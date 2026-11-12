# Overlays

Stage, boss, event and Chao code is in PRS overlays on the disc, each linked at a fixed address. `overlays.tsv` lists every disc file with code:
its load address (`base`), hash and `status`. Bases: `0c900000` stages and bosses, `0c920000` Egg Carrier, `0cb80000` events and Chao, `8c900000`
ADVERTISE. `2_DP.BIN` (the Dream Passport browser, a separate program) is out of scope, and files with too little code or an undecided base stay out
with their `status` saying why. `overlays.tsv` is the one place for an overlay's address: the tools read it from there
(`python3 tools/overlay/ovtsv.py base <name>`).

## Layout

- `overlays/<name>/`: `functions.txt`, `globals.txt` and `symbols.local.txt` of one overlay (committed). `setup.sh` adds the decompressed image
  (`<name>.bin`), `asm/` and `objects.txt` (`tools/overlay/setup_overlays.py`; never committed).
- `overlays/src/<unit>.c`: the C units of the overlays, each stored once. `overlays/units.tsv` says which overlays have each unit and at what
  range: the same code sits at a different address in each. The `@unit` range in the stored file is that of one of its overlays; the build
  writes `overlays/<name>/src/<unit>.c` with the range of that overlay's row (`tools/overlay/place_units.py`, generated, `.gitignore`).

## Building

`bash build.sh --overlay <name>` is the same build as `bash build.sh`, run in the overlay's folder: its asm, its C units (shc, `fill.py`,
`units.py`), linked at its base and compared with its decompressed image. A unit's outside names come from the overlay's `functions.txt`,
`globals.txt` and `symbols.local.txt`, then from 1ST_READ.BIN's (`tools/overlay/link_defs.py`). `bash build_overlays.sh [name ...]` runs it for
every overlay (`JOBS=<n>`: n at a time) and must end with `200 overlays, 200 MATCH`. A byte match compares decompressed images; recompressing to
the disc's exact PRS bytes is not done. The compiler cannot open its temp files under a long path ("Cannot open internal file"), so an overlay's
build gives it a short one of its own (`/tmp/shc_<name>`).

## Tools on an overlay

`bash tools/overlay/in.sh <name> <tool> <args>` runs a shared tool in the overlay's folder (`shdis.py --func X`, `equiv.py src/x.c`): it writes
the image as `1ST_READ.BIN`, `BASE`, the units and a `symbols.txt` with 1ST_READ.BIN's names there, and puts the compiler's runtime helpers of
1ST_READ.BIN in the simulator's memory (`SH4SIM_ALSO`, `tools/overlay/runtime_helpers.py`). Rename in the overlay's `functions.txt`, then re-run
`tools/1-2-baseline/split_asm.py`. Many names are very likely rather than proven: correct them when reading the code shows otherwise.

## Function lists and shared code

- Function lists come from `tools/overlay/analyze.py`, a reachability pass (about 90% of the known starts on 1ST_READ.BIN). Boundaries never change
  the rebuilt bytes, but a wrong one blocks a C unit: check them before writing C. A typical fault is a boundary on the delay slot of the
  previous function's `rts`.
- Much code is linked into several images (6,116 overlay functions fall in 812 identical-code groups). A unit matched once is carried to every
  copy: `python3 tools/overlay/carry_unit.py <overlay> <unit> [overlay[@address] ...]` finds each copy (masked words equal), moves the unit's
  boundaries, reads that overlay's globals from its own pools, adds the row to `overlays/units.tsv` and keeps it only if `build.sh --overlay`
  matches with the unit linked (`@address` for a copy whose `functions.txt` lacks the first function's name). Units of only a few words match
  everywhere by chance: such hits are not copies.
- `python3 tools/progress.py` ends with the overlays' own total (`tools/overlay/progress.py`); the main metric stays 1ST_READ.BIN's.
