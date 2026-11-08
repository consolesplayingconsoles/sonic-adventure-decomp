#!/usr/bin/env python3
"""Rebuild every overlay image from its asm and compare it with the disc's decompressed bytes.

    python3 tools/overlay/build.py [name ...]     (from build_overlays.sh; T = the SDK tools folder, in the environment)

Assemble what changed, compile the overlay's C units (src/*.c with an @unit header, as build.sh does: shc, tools/fill.py, in place of the asm
they replace, tools/units.py), link at the overlay's BASE, elf2bin, compare. Exits 1 if any differs. A unit's outside names come from the overlay's
functions.txt, globals.txt and symbols.local.txt and from 1ST_READ.BIN's functions.txt, globals.txt and symbols.txt.
The disc holds these PRS-compressed; a byte match here is on the decompressed image, not the compressed file.
"""
import concurrent.futures as CF, os, shutil, subprocess, sys, tempfile
T = os.environ['T']
tool = {x.lower(): os.path.join(T, x) for x in os.listdir(T)}
ENV = dict(os.environ, SHC_LIB='Z:' + T.replace('/', '\\'), SHC_INC='Z:' + T.replace('/', '\\'))
names = sys.argv[1:] or sorted(n for n in os.listdir('overlays') if os.path.isfile('overlays/%s/objects.txt' % n))
abspath = os.getcwd()


def wibo(cwd, *a):
    return subprocess.run(['wibo', *a], cwd=cwd, env=ENV, capture_output=True, text=True, errors='replace', stdin=subprocess.DEVNULL)


FLAGS = ('-cpu=sh4 -endian=little -fpu=single -division=cpu -round=nearest -pic=0 -macsave=0 -optimize=1 -size -string=const '
         '-section=p=P,c=C,d=D,b=B -include=src').split()
PY = sys.executable
import re


def table(path, a_col, n_col, fn=False):
    out = {}
    if os.path.exists(path):
        for l in open(path, errors='replace'):
            q = l.split()
            if l.startswith('#') or len(q) <= n_col or (fn and q[0] != 'F'):
                continue
            try:
                out.setdefault(q[n_col], int(q[a_col], 16))
            except ValueError:
                pass
    return out


MAIN_NAMES = {}
for args in (('functions.txt', 1, 3, True), ('globals.txt', 0, 1), ('symbols.txt', 0, 1)):
    for k, v in table(*args).items():
        MAIN_NAMES.setdefault(k, v)


def units(o, n):
    """Compile the overlay's units; their objects, link order and the defines their names need. (None, why) when one fails."""
    r = subprocess.run([PY, os.path.join(abspath, 'tools/units.py'), '--units'], cwd=o, capture_output=True, text=True)
    us = [l.split() for l in r.stdout.splitlines() if l.strip()]
    if not us:
        return [], ''
    os.makedirs(o + '/build/tmp', exist_ok=True)
    for u in us:
        name, start, end, dstart, dend, opts = u[0], u[1], u[2], u[3], u[4], [x for x in u[5:] if not x.startswith('+')]
        fillopts = ['--' + x[1:] for x in u[5:] if x.startswith('+')]       # +pool32 and the like: layout options for fill.py
        obj = '%s/build/obj/c_%s.obj' % (o, name)
        src = '%s/src/%s.c' % (o, name)
        if os.path.exists(obj) and os.path.getmtime(obj) > os.path.getmtime(src):
            continue
        tmp = tempfile.mkdtemp(prefix='shc', dir='/tmp')       # the compiler cannot open its temp files under a long path (an overlay's folder)
        try:
            r = subprocess.run(['wibo', tool['shc.exe'], 'src\\%s.c' % name, '-code=asm', '-object=build\\obj\\c_%s.s' % name] + FLAGS + opts,
                               cwd=o, env=dict(ENV, SHC_TMP='Z:' + tmp.replace('/', '\\')), capture_output=True, text=True, errors='replace')
        finally:
            shutil.rmtree(tmp, ignore_errors=True)
        if r.returncode:
            return None, 'unit %s: %s' % (name, (r.stdout + r.stderr)[-200:])
        fargs = ['build/obj/c_%s.s' % name, 'build/obj/c_%s_f.s' % name, start, end]
        if dstart != '-':
            fargs += ['build/obj/c_%s_data.s' % name, dstart, dend, name]
        r = subprocess.run([PY, os.path.join(abspath, 'tools/fill.py')] + fargs + fillopts, cwd=o, capture_output=True, text=True)
        if r.returncode:
            return None, 'unit %s: %s' % (name, (r.stdout + r.stderr)[-200:])
        for s_ in (['c_%s_data' % name] if dstart != '-' else []) + ['c_%s_f' % name]:
            target = 'c_%s' % name if s_.endswith('_f') else s_
            r = wibo(o, tool['asmsh.exe'], 'build\\obj\\%s.s' % s_, '-object=build\\obj\\%s.obj' % target, '-cpu=sh4', '-endian=little')
            if r.returncode:
                return None, 'unit %s asm: %s' % (name, r.stdout[-200:])
    idents = set()
    for u in us:
        idents |= set(re.findall(r'[A-Za-z_]\w*', open('%s/src/%s.c' % (o, u[0]), errors='replace').read()))
    names = {}
    for args in (('%s/functions.txt' % o, 1, 3, True), ('%s/globals.txt' % o, 0, 1), ('%s/symbols.local.txt' % o, 0, 1)):
        for k, v in table(*args).items():
            names.setdefault(k, v)
    for k, v in MAIN_NAMES.items():
        names.setdefault(k, v)
    exported = set()
    for f in os.listdir(o + '/asm'):
        exported.add(f.split('_', 1)[1][:-4] if '_' in f else '')
    # the compiler's helpers (_divls, _quick_mvn...) are called by code whose text never names them; they live in 1ST_READ.BIN
    helpers = {k for k in MAIN_NAMES if re.match(r'_(quick|slow|div|mod)\w*$', k)}
    return ['define _%s(%08X)' % (k, names[k]) for k in sorted(idents | helpers) if k in names and k not in exported], ''


def one(n):
    o = os.path.join(abspath, 'overlays', n)
    os.makedirs(o + '/build/obj', exist_ok=True)
    base = open(o + '/BASE').read().strip()
    objs = open(o + '/objects.txt').read().split()
    for f in objs:
        out = '%s/build/obj/%s.obj' % (o, f[:-4])
        if not os.path.exists(out) or os.path.getmtime('%s/asm/%s' % (o, f)) > os.path.getmtime(out):
            r = wibo(o, tool['asmsh.exe'], 'asm\\' + f, '-object=build\\obj\\%s.obj' % f[:-4], '-cpu=sh4', '-endian=little')
            if r.returncode:
                return n, 'asm failed: ' + f + ' ' + r.stdout[-200:]
    defines, why = units(o, n)
    if defines is None:
        return n, why
    if os.path.exists(o + '/src') and any(open(os.path.join(o, 'src', c), errors='replace').readline().lstrip().startswith('/* @unit') for c in os.listdir(o + '/src') if c.endswith('.c')):
        ro = subprocess.run([PY, os.path.join(abspath, 'tools/units.py'), 'objects.txt'], cwd=o, capture_output=True, text=True)
        order = ro.stdout.split()
        if ro.returncode or not order or any(x.startswith('[ERROR]') for x in order):
            return n, 'link order: ' + (ro.stdout + ro.stderr).strip()[-200:]
        inputs = ['input %s' % x for x in order]
    else:
        inputs = ['input build\\obj\\%s.obj' % f[:-4] for f in objs]
    sub = ['elf', 'start P(%s)' % base.upper(), 'output build\\out.elf'] + inputs + defines + ['exit']
    open(o + '/build/link.sub', 'w').write('\n'.join(sub) + '\n')
    for old in ('build/out.elf', 'build/out.bin'):           # a link that fails must not leave the last good image to compare
        if os.path.exists(os.path.join(o, old)):
            os.remove(os.path.join(o, old))
    r = wibo(o, tool['lnk.exe'], '-subcommand=build\\link.sub')
    if 'UNDEFINED' in r.stdout.upper():
        return n, 'undefined symbol: ' + ' | '.join(l.strip() for l in r.stdout.splitlines() if 'UNDEFINED' in l.upper() or l.strip().startswith('NAME'))[:300]
    if os.path.exists(o + '/build/out.bin'):
        os.remove(o + '/build/out.bin')
    wibo(o, tool['elf2bin.exe'], '-s', base, 'build\\out.elf')
    if not os.path.exists(o + '/build/out.bin'):
        return n, 'no output: ' + r.stdout[-200:]
    a, b = open(o + '/build/out.bin', 'rb').read(), open('%s/%s.bin' % (o, n), 'rb').read()
    if a == b:
        return n, 'MATCH'
    k = next((i for i, (x, y) in enumerate(zip(a, b)) if x != y), min(len(a), len(b)))
    return n, 'DIFFERS at %x (%d vs %d bytes)' % (k, len(a), len(b))


bad = 0
with CF.ThreadPoolExecutor(int(os.environ.get('JOBS', os.cpu_count() or 4))) as ex:
    for n, r in ex.map(one, names):
        if r != 'MATCH':
            bad += 1
            print(n, r, flush=True)
print('%d overlays, %d MATCH, %d not' % (len(names), len(names) - bad, bad))
sys.exit(1 if bad else 0)
