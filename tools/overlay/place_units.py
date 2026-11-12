#!/usr/bin/env python3
"""Write an overlay's C units from the one copy of each: python3 tools/overlay/place_units.py <overlay> [...]   (run in the repo; build.sh --overlay runs it)

A unit's C is stored once, in overlays/src/<unit>.c; overlays/units.tsv says which overlays have it and at what range (the same code sits at a
different address in each). For each row of the overlay this writes overlays/<overlay>/src/<unit>.c: the stored file with the @unit range of that
row. Those folders are generated (.gitignore): a file is rewritten only when its text changes, so a build recompiles only what changed, and a
generated unit with no row any more is removed.
"""
import os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
HEAD = re.compile(r'^(\s*/\*\s*@unit\s+)[0-9A-Fa-f]{8}-[0-9A-Fa-f]{8}')


def rows():
    out = []
    for l in open(os.path.join(ROOT, 'overlays', 'units.tsv')):
        q = l.split()
        if q and not l.startswith('#'):
            out.append(q[:4])
    return out


def place(ov):
    d = os.path.join(ROOT, 'overlays', ov, 'src')
    want = {}
    for o, unit, start, end in rows():
        if o == ov:
            text = open(os.path.join(ROOT, 'overlays', 'src', unit + '.c'), encoding='latin1').read()
            want[unit + '.c'] = HEAD.sub(r'\g<1>%s-%s' % (start, end), text, count=1)
    if want:
        os.makedirs(d, exist_ok=True)
    for f in os.listdir(d) if os.path.isdir(d) else []:
        if f.endswith('.c') and f not in want:
            os.remove(os.path.join(d, f))
    for f, text in want.items():
        p = os.path.join(d, f)
        if not os.path.exists(p) or open(p, encoding='latin1').read() != text:
            open(p, 'w', encoding='latin1').write(text)


if __name__ == '__main__':
    for ov in sys.argv[1:]:
        place(ov)
