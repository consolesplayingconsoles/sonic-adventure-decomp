#!/usr/bin/env python3
"""The overlays' state, printed after tools/progress.py's report. Run in the repo. A separate total: the main metric stays 1ST_READ.BIN's."""
import csv, glob, os, re
rows = list(csv.DictReader(open('overlays.tsv'), delimiter='\t'))
ok = [r for r in rows if r['status'] == 'ok']
fn = by = named = mt = mt_b = mt_u = 0
for r in ok:
    o = 'overlays/' + r['name']
    p = o + '/functions.txt'
    if not os.path.exists(p):
        continue
    unit_ranges = []
    for g in glob.glob(o + '/src/*.c'):
        m_ = re.match(r'\s*/\*\s*@unit\s+([0-9A-Fa-f]{8})-([0-9A-Fa-f]{8})', open(g, errors='replace').readline())
        if m_:
            unit_ranges.append((int(m_.group(1), 16), int(m_.group(2), 16)))
    mt_u += len(unit_ranges)
    for l in open(p):
        q = l.split()
        if q and q[0] == 'F':
            s = int(q[2]); fn += 1; by += s
            for a_, b_ in unit_ranges:
                if a_ <= int(q[1], 16) < b_:
                    mt += 1; mt_b += min(s, b_ - int(q[1], 16))      # only what the unit covers (a listed size can run past it)
                    break
            named += not q[3].startswith('FUN_')
print('OVERLAYS                          %d of %d disc files with code, %d functions, %d bytes of code (separate total)' % (len(ok), len(rows), fn, by))
print('  matching C               %5.1f%%  %d functions, %d bytes, %d units: rebuilt byte for byte (build_overlays.sh)'
      % (100 * mt_b / max(by, 1), mt, mt_b, mt_u))
print('  named                    %5.1f%%  %d functions' % (100 * named / max(fn, 1), named))
print('  not in scope                     %d files (overlays.tsv says why)' % (len(rows) - len(ok)))
