#!/usr/bin/env python3
"""fill.py <in.s> <out.s> <start hex> <end hex> [<out_data.s> <dstart hex> <dend hex> <unit name>]:
shc's asm output laid out exactly like the game.

The unit is linked in place among the asm files (all ALIGN=2), so its sections are declared ALIGN=2
and every alignment is spelled out from the known start address instead:
  .ALIGN n  -> nops (0x0009) in code, the padding the original has there; zero bytes in data;
  .RES.x n  -> 0xEE bytes, what the original link filled reserved gaps with;
  and 0xEE after the end of the code, up to <end>, so the next piece starts where it did.
SH-4 instructions are all 2 bytes, so offsets are counted here, not by the assembler.

Constant data (shc's C section: initialised tables, string literals) goes to <out_data.s>, laid out
from <dstart> to <dend> (the unit's @data range): the original link put each file's C section in
the data area, far from its code. Labels one piece defines and the other uses get unit-unique names
with .EXPORT/.IMPORT, so the two pieces link as one. --pool32 (a unit's header option +pool32): the game's own code puts each literal pool at a 32-byte boundary and fills the gap before it with the word 0x0900, and
the rest up to the next file with zero bytes; no compiler option of SHC 5.0 or 5.1 lays it out so (342 of 469 source files of 1ST_READ.BIN's game code).
--pool00 (+pool00): the gap a literal pool reserves between its 16-bit and 32-bit entries is zero bytes, not 0xEE (implied by --pool32).
A unit with constant data and no @data range,
or with initialised variables (D/B sections), is refused with the reason.
"""
import os as _tp_os, sys as _tp_sys  # noqa: E401  every tools folder on the import path (tools/toolpath.py)
_tp_sys.path.insert(0, _tp_os.path.normpath(_tp_os.path.join(_tp_os.path.dirname(_tp_os.path.abspath(__file__)), '..')))
import toolpath  # noqa: E402,F401
import re
import sys

SIZES = {'B': 1, 'W': 2, 'L': 4}
LABEL = re.compile(r'^([A-Za-z_$.][\w$.]*):')
IDENT = re.compile(r'[A-Za-z_$.][\w$.]*')


def sdata_len(args):
    """Bytes in a .SDATA operand list: "text" pieces (a doubled quote is one quote) and <h'xx> codes."""
    n, i = 0, 0
    while i < len(args):
        c = args[i]
        if c == '"':
            i += 1
            while i < len(args):
                if args[i] == '"':
                    if i + 1 < len(args) and args[i + 1] == '"':
                        n += 1; i += 2; continue
                    break
                n += 1; i += 1
        elif c == '<':
            n += 1; i = args.index('>', i)
        i += 1
    return n


def layout(lines, start, end, data, what):
    pos, out = start, []
    last_data = False                   # the previous item was literal-pool data
    pending_res = 0                     # under POOL32: a .RES right after a pool's label, already filled
    for k, line in enumerate(lines):
        code = line.split(';', 1)[0].strip()
        m = re.match(r'(\S+:)?\s*(.*)', code)
        rest = m.group(2).strip()
        if POOL32 and not data and last_data and (m.group(1) or (rest and not rest.split()[0].upper().startswith('.'))):
            # code again after a pool in the middle of the file: it starts at the next 32-byte boundary, the gap the same 0x0900 words
            pad = (-pos) % 32
            out.extend('          .DATA.W     H\'0900\n' for _ in range(pad // 2))
            pos += pad
            last_data = False
        if POOL32 and not data and m.group(1) and not last_data:
            # a label the pool starts at (the compiler addresses the pool as label+gap): everything before it is padded so that the pool's data
            # lands on a 32-byte boundary, the gap included, all with the word 0x0900
            nxt = [l.split(';', 1)[0].strip() for l in lines[k + 1:k + 4]]
            ops = [re.match(r'(\S+:)?\s*(.*)', x).group(2).split()[0].upper() if re.match(r'(\S+:)?\s*(.*)', x).group(2).strip() else '' for x in nxt]
            ops = [x for x in ops if x]
            first = ops[0] if ops else ''
            if rest:
                first = rest.split()[0].upper()
            if first.startswith('.DATA') or first.startswith('.RES'):
                gap = 0
                if first.startswith('.RES'):
                    src = rest if rest else next(x for x in nxt if x and not x.endswith(':'))
                    mr_ = re.match(r'(?:\S+:)?\s*\.RES\.([BWL])\s+(\S+)', src, re.I)
                    gap = int(mr_.group(2), 0) * SIZES[mr_.group(1).upper()] if mr_ else 0
                pad = (-(pos + gap)) % 32
                out.extend('          .DATA.W     H\'0900\n' for _ in range(pad // 2))
                pos += pad
                pending_res = gap
        if not rest:
            out.append(line); continue
        op = rest.split()[0].upper()
        args = rest[len(op):].strip()
        if not op.startswith('.'):
            last_data = False
        if op == '.SECTION':
            out.append('          .SECTION    P,CODE,ALIGN=2\n'); continue
        if op == '.ALIGN':
            pad = (-pos) % int(args, 0)
            if data:
                if pad: out.append('          .DATAB.B    %d,H\'00\n' % pad)
            else:
                if pad % 2:
                    sys.exit('[ERROR] fill.py: odd alignment pad at %08X' % pos)
                out.extend('          .DATA.W     H\'%s\n' % ('0900' if POOL32 else '0009') for _ in range(pad // 2))
            pos += pad; continue
        mr = re.match(r'\.RES\.([BWL])$', op)
        if mr and pending_res:
            n = int(args, 0) * SIZES[mr.group(1)]
            out.extend('          .DATA.W     H\'0900\n' for _ in range(n // 2))
            pending_res = 0
            pos += n; continue
        if mr:
            n = int(args, 0) * SIZES[mr.group(1)]
            # --pool00 (and --pool32): inside a literal pool (right after its .DATA words: the gap before the longs) the original has zero
            # bytes, in the game and the library alike (153 of 157 such gaps in 1ST_READ.BIN); other reserved gaps were filled with 0xEE
            fillb = '00' if last_data and (POOL00 or POOL32) else 'EE'
            if n: out.append('          .DATAB.B    %d,H\'%s\n' % (n, fillb))
            pos += n; continue
        md = re.match(r'\.DATA\.([BWL])$', op)
        if md:
            last_data = True
            pos += SIZES[md.group(1)] * len(args.split(',')); out.append(line); continue
        mb = re.match(r'\.DATAB\.([BWL])$', op)
        if mb:
            pos += SIZES[mb.group(1)] * int(args.split(',')[0], 0); out.append(line); continue
        if op in ('.SDATA', '.SDATAZ'):
            pos += sdata_len(args) + (op == '.SDATAZ'); out.append(line); continue
        if op.startswith('.'):
            out.append(line); continue      # .EXPORT, .IMPORT, .LINE, ... take no space
        if data:
            sys.exit('[ERROR] fill.py: instruction in the constant data: ' + rest)
        pos += 2                            # an SH-4 instruction
        out.append(line)
    if pos > end:
        sys.exit('[ERROR] fill.py: unit %s is %d bytes, %d over its end %08X'
                 % (what, pos - start, pos - end, end))
    if end > pos and POOL32 and not data and (end - pos) % 2 == 0:
        if TAIL0900:
            out.extend('          .DATA.W     H\'0900\n' for _ in range((end - pos) // 2))
        else:
            out.append('          .DATAB.B    %d,H\'00\n' % (end - pos))                 # after the pool, to the next file: zero bytes
    elif end > pos:
        out.append('          .DATAB.B    %d,H\'%s\n' % (end - pos, '00' if data else 'EE'))
        if data:
            print('[note] fill.py: constant data is %d bytes, %d short of its @data end %08X'
                  % (pos - start, end - pos, end), file=sys.stderr)
    return out


POOL32 = False        # --pool32: the game's layout of a literal pool (see the module notes)
POOL_AFTER = []       # --poolafter=f1,f2: a literal pool of its own right after these functions (see split_pools)
SYNTH16 = False       # --synth16: 16-bit constants built with mov #hi / shll8 [/ add #lo], as the game's own compiler does (see synth16)
POOL00 = False        # --pool00: zero bytes, not 0xEE, in the gap a literal pool reserves between its 16-bit and 32-bit entries
TAIL0900 = False      # --tail0900: after the pool the same 0x0900 words to the unit's end (code of the same file follows), not zero bytes


def split_pools(lines, names):
    """The original link has a literal pool after each of `names` and one at the end of the file; the compiler places its own elsewhere. Each group
    of functions (after the previous name, up to this one; the last group to the end) gets one pool right after it, holding what the group's code
    loads, in the compiler's own order of entries. The compiler's pools go. No instruction changes; only .DATA.L pools."""
    fn_at = []
    for i, l in enumerate(lines):
        m = re.search(r';\s*function:\s*(\w+)', l)
        if m:
            fn_at.append((i, m.group(1)))
    pools = {}
    for i, l in enumerate(lines):
        m = re.match(r'^(L\d+):\s*$', l.split(';')[0].strip())
        if m:
            nxt = lines[i + 1].split(';')[0].strip().upper() if i + 1 < len(lines) else ''
            if nxt.startswith('.RES.W') or nxt.startswith('.DATA.L'):
                gap = 2 if nxt.startswith('.RES.W') else 0
                ents, j = [], i + 1 + (1 if gap else 0)
                while j < len(lines) and lines[j].split(';')[0].strip().upper().startswith('.DATA.L'):
                    ents.append(lines[j].split(';')[0].strip().split(None, 1)[1].strip())
                    j += 1
                if j < len(lines) and lines[j].split(';')[0].strip().upper().startswith('.DATA.W'):
                    sys.exit('[ERROR] fill.py: --poolafter: a pool with 16-bit entries is not supported')
                pools[m.group(1)] = (i, j, gap, ents)
    if not pools:
        return lines
    names_at = {n: i for i, n in fn_at}
    for n in names:
        if n not in names_at:
            sys.exit('[ERROR] fill.py: --poolafter: no function %s' % n)
    order = [n for i, n in fn_at]
    ends = []                                   # the line before which each group's pool goes
    for n in names:
        k = order.index(n)
        ends.append(fn_at[k + 1][0] if k + 1 < len(fn_at) else len(lines))
    # the end of the file's code: after the last line that is not a pool
    in_pool = set()
    for lab, (i, j, gap, ents) in pools.items():
        in_pool.update(range(i, j))
    last_code = max(i for i in range(len(lines)) if i not in in_pool and lines[i].split(';')[0].strip()
                    and not lines[i].split(';')[0].strip().upper().startswith(('.END', '.EXPORT', '.IMPORT', '.SECTION')))
    bounds = ends + [last_code + 1]
    ref = re.compile(r'\b(%s)(?:\+(\d+))?\b(?!:)' % '|'.join(map(re.escape, pools)))      # a load at offset 0 names the bare label
    groups, prev = [], 0
    for b in bounds:
        groups.append((prev, b))
        prev = b
    rank = {}
    for lab, (i, j, gap, ents_) in sorted(pools.items(), key=lambda kv: kv[1][0]):
        for s_ in ents_:
            rank.setdefault(s_, len(rank))
    newlab = {}
    newents = []
    out = list(lines)
    for g, (a, b) in enumerate(groups):
        ents, key = [], {}
        ppos = {lab: k for k, (lab, v) in enumerate(sorted(pools.items(), key=lambda kv: kv[1][0]))}
        for i in range(a, b):
            if i in in_pool:
                continue
            for mm in ref.finditer(out[i]):
                lab, off = mm.group(1), int(mm.group(2) or 0)
                e = (off - pools[lab][2]) // 4
                sym = pools[lab][3][e]
                if sym not in ents:
                    ents.append(sym)
                key[sym] = min(key.get(sym, (1 << 30, 0)), (ppos[lab], e))
        ents.sort(key=lambda s_: key[s_])        # the compiler's own order, in the pools this group loads from
        newents.append(ents)
        lb = 'LPOOL%d' % g
        for i in range(a, b):
            if i in in_pool:
                continue
            out[i] = ref.sub(lambda mm: '%s+%d' % (lb, 4 * ents.index(pools[mm.group(1)][3][(int(mm.group(2) or 0) - pools[mm.group(1)][2]) // 4])), out[i])
    result = []
    for i, l in enumerate(out):
        for g, (a, b) in enumerate(groups):
            if i == b and newents[g]:
                result.append('LPOOL%d:\n' % g)
                result.extend('          .DATA.L     %s\n' % s_ for s_ in newents[g])
        if i in in_pool:
            continue
        result.append(l)
    g = len(groups) - 1
    if groups[g][1] >= len(out) and newents[g]:
        result.append('LPOOL%d:\n' % g)
        result.extend('          .DATA.L     %s\n' % s_ for s_ in newents[g])
    return result


DELAYED = re.compile(r'^\s*(BT/S|BF/S|BRA|BSR|BRAF|BSRF|JMP|JSR|RTS|RTE)\b', re.I)


def synth16(lines, align=False):
    """The compiler that built Sonic Adventure DC's game code puts a 16-bit constant such as 0x100 or ~0x100 in a register with mov #hi, shll8 and,
    when needed, add #lo (and one of 128 to 255 with mov #v-256, extu.b: 1,968 times in the game's code against 174 pool loads, the libraries 1 against 1,222), where every available SHC (5.0r10 to 5.1r13, any option) loads it from the literal pool: 1,806 such constants in
    1ST_READ.BIN's game code against 14 pool loads (the SDK's libraries: 5 against 113). This writes that form instead of each mov.w load of a constant
    that fits it, drops the constant from the pool and moves the pool's other loads to their new offsets. A load in a branch's delay slot stays.
    It changes instructions (an emulation of a compiler that is not available), so a unit asks for it by name: +synth16."""
    out = list(lines)
    blocks = []
    for i, l in enumerate(out):
        m = re.match(r'^(L\d+):\s*$', l.split(';')[0].strip())
        if not m:
            continue
        j, w = i + 1, []
        while j < len(out) and out[j].split(';')[0].strip().upper().startswith('.DATA.W'):
            w.append(out[j].split(';')[0].strip().split(None, 1)[1].strip())
            j += 1
        if not w:
            continue
        pad = 0
        if j < len(out) and out[j].split(';')[0].strip().upper().startswith('.RES.W'):
            pad = int(out[j].split(';')[0].strip().split()[1], 0) * 2
            j += 1
        k, lw = j, []
        while k < len(out) and out[k].split(';')[0].strip().upper().startswith('.DATA.L'):
            lw.append(out[k].split(';')[0].strip().split(None, 1)[1].strip())
            k += 1
        blocks.append((m.group(1), i, w, pad, lw, k))
    for lab, i, w, pad, lw, k in sorted(blocks, key=lambda b: -b[1]):
        def val(s):
            s = s.strip()
            v = int(s[2:].rstrip("'"), 16) if s.upper().startswith("H'") else int(s, 0)
            return v - 0x10000 if v & 0x8000 else v
        form = {}
        for e, s in enumerate(w):
            try:
                v = val(s)
            except ValueError:
                continue
            if -128 <= v <= 127:
                continue
            if 128 <= v <= 255:
                form[e] = ('extu', v - 256)        # mov #v-256 / extu.b: 1,968 times in the game's code, 1 in the libraries
                continue
            hi = (v + 128) >> 8
            lo = v - hi * 256
            if -128 <= hi <= 127 and -128 <= lo <= 127:
                form[e] = (hi, lo)
        ref = re.compile(r'^(\s*)MOV\.W(\s+)%s(?:\+(\d+))?\s*,\s*(R\d+)(.*)$' % re.escape(lab), re.I)
        used_pool = set()
        new = []
        for n, l in enumerate(out):
            m = ref.match(l.rstrip('\n'))
            if m:
                e = int(m.group(3) or 0) // 2
                prev = next((out[q] for q in range(n - 1, -1, -1) if out[q].split(';')[0].strip() and not re.match(r'^\S+:\s*$', out[q].split(';')[0].strip())), '')
                if e in form and not DELAYED.match(prev.split(';')[0]):
                    hi, lo = form[e]
                    ind, rn = m.group(1), m.group(4)
                    if hi == 'extu':
                        new.append('%sMOV         #%d,%s\n' % (ind, lo, rn))
                        new.append('%sEXTU.B      %s,%s\n' % (ind, rn, rn))
                        continue
                    new.append('%sMOV         #%d,%s\n' % (ind, hi, rn))
                    new.append('%sSHLL8       %s\n' % (ind, rn))
                    if lo:
                        new.append('%sADD         #%d,%s\n' % (ind, lo, rn))
                    continue
                used_pool.add(e)
            new.append(l)
        out = new
        keep = [e for e in range(len(w)) if e in used_pool or e not in form]
        if len(keep) == len(w):
            continue
        # the label's place mod 4 follows from the compiler's block (its .DATA.L entries are 4-aligned); keep them so with fewer words
        at = (-(2 * len(w) + pad)) % 4
        newpad = (-(at + 2 * len(keep))) % 4
        wmap = {e: 2 * q for q, e in enumerate(keep)}
        lbase_old, lbase_new = 2 * len(w) + pad, 2 * len(keep) + newpad
        refall = re.compile(r'\b%s(?:\+(\d+))?\b(?!:)' % re.escape(lab))
        def fix(mm):
            off = int(mm.group(1) or 0)
            if off < 2 * len(w):
                no = wmap[off // 2]
            elif align:
                return '%s_L+%d' % (lab, off - lbase_old)
            else:
                no = off - lbase_old + lbase_new
            return '%s+%d' % (lab, no) if no else lab
        # the block's position moved by the inserted instructions: find it again
        bi = next(q for q, l in enumerate(out) if l.split(';')[0].strip() == lab + ':')
        bend = bi + 1 + len(w) + (1 if pad else 0) + len(lw)
        block = ['%s:\n' % lab] + ['          .DATA.W     %s\n' % w[e] for e in keep]
        if align:
            # the caller does not lay the pools out (tools/fcmp.py) and the inserted instructions moved the label: the longs get a
            # label of their own, aligned by the assembler
            block += ['          .ALIGN      4\n', '%s_L:\n' % lab]
        elif newpad:
            block += ['          .RES.W      1\n']
        block += ['          .DATA.L     %s\n' % s for s in lw]
        out = [refall.sub(fix, l) if not (bi <= q < bend) else l for q, l in enumerate(out)]
        out[bi:bend] = block
    return out


def main():
    global POOL32
    a = sys.argv[1:]
    global TAIL0900, POOL00
    if '--pool00' in a:
        a.remove('--pool00'); POOL00 = True
    if '--pool32' in a:
        a.remove('--pool32'); POOL32 = True
    if '--tail0900' in a:
        a.remove('--tail0900'); TAIL0900 = True
    global POOL_AFTER, SYNTH16
    if '--synth16' in a:
        a.remove('--synth16'); SYNTH16 = True
    for x in list(a):
        if x.startswith('--poolafter='):
            POOL_AFTER = x.split('=', 1)[1].split(',')
            a.remove(x)
    if len(a) not in (4, 8):
        sys.exit(__doc__)
    lines = open(a[0], encoding='latin-1').readlines()
    if SYNTH16:
        lines = synth16(lines)
    if POOL_AFTER:
        lines = split_pools(lines, POOL_AFTER)
    head, parts, cur = [], {'P': [], 'C': []}, None
    for line in lines:
        code = line.split(';', 1)[0].strip()
        op = code.split()[0].upper() if code and not LABEL.match(code) else ''
        if op == '.SECTION':
            name = code.split()[1].split(',')[0].upper()
            if name not in parts:
                sys.exit('[ERROR] fill.py: a %s section (initialised or zeroed variables) is not '
                         'supported yet: keep such variables in asm for now' % name)
            cur = name
        if op == '.END':
            continue
        (head if cur is None else parts[cur]).append(line)
    if parts['C'] and len(a) == 4:
        sys.exit('[ERROR] fill.py: this unit has constant data (tables, strings): give it a range with '
                 '@data <dstart>-<dend> in its @unit line')
    if len(a) == 4:
        open(a[1], 'w', encoding='latin-1').writelines(head + layout(parts['P'], int(a[2], 16), int(a[3], 16), False, 'code') + ['          .END\n'])
        return
    if not parts['C']:
        sys.exit('[ERROR] fill.py: @data given but the unit has no constant data')

    def defined(ls):
        return {m.group(1) for m in (LABEL.match(l) for l in ls) if m}

    def used(ls):
        return {t for l in ls for t in IDENT.findall(l.split(';', 1)[0].split(':')[-1])}

    exported = {l.split()[1] for l in head if l.strip().upper().startswith('.EXPORT')}
    dc, dd = defined(parts['P']), defined(parts['C'])
    cross = {(x, 'P') for x in dc & used(parts['C'])} | {(x, 'C') for x in dd & used(parts['P'])}
    rename = {x: '_U_%s_%s' % (a[7], x.lstrip('_')) for x, _ in cross if x not in exported}

    def sub(ls):
        if not rename:
            return ls
        r = re.compile(r'(?<![\w$.])(%s)(?![\w$.])' % '|'.join(map(re.escape, rename)))
        return [r.sub(lambda m: rename[m.group(1)], l) for l in ls]

    code, data = sub(parts['P']), sub(parts['C'])
    ext = {}
    for x, side in cross:
        n = rename.get(x, x)
        ext.setdefault(side, []).append(n)
    imports = [l for l in head if l.strip().upper().startswith('.IMPORT')]
    code_head = sub(head) + ['          .EXPORT     %s\n' % n for n in ext.get('P', []) if n not in exported] \
        + ['          .IMPORT     %s\n' % n for n in ext.get('C', [])]
    data_head = imports + ['          .EXPORT     %s\n' % n for n in ext.get('C', [])] \
        + ['          .IMPORT     %s\n' % n for n in ext.get('P', [])]
    open(a[1], 'w', encoding='latin-1').writelines(
        code_head + layout(code, int(a[2], 16), int(a[3], 16), False, 'code') + ['          .END\n'])
    open(a[4], 'w', encoding='latin-1').writelines(
        data_head + layout(data, int(a[5], 16), int(a[6], 16), True, 'data') + ['          .END\n'])


if __name__ == '__main__':
    main()
