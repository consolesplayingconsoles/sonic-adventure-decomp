#!/usr/bin/env bash
# Run one of the repo's tools on an overlay: the tools read 1ST_READ.BIN, BASE, functions.txt from the current folder.
#   bash tools/overlay/in.sh <overlay> shdis.py --func <name>
#   bash tools/overlay/in.sh <overlay> equiv.py src/<file>.c
# The compiler's runtime helpers of 1ST_READ.BIN are in memory on every run (tools/overlay/runtime_helpers.py).
# Every 1ST_READ.BIN function and global the overlay can reach is given as a name (symbols.txt, generated).
set -euo pipefail
R="$(cd "$(dirname "$0")/../.." && pwd)"
n="$1"; t="$2"; shift 2
export SH4SIM_ALSO="$R/build/runtime_helpers.json"
[ -f "$SH4SIM_ALSO" ] || (cd "$R" && python3 tools/overlay/runtime_helpers.py)
cd "$R/overlays/$n"
ln -sf "$n.bin" 1ST_READ.BIN
[ -f .env ] || cp "$R/.env" .env
{ [ -f symbols.local.txt ] && cat symbols.local.txt
  awk '$1=="F"{print toupper($2), $4}' "$R/functions.txt"
  grep -v '^#' "$R/globals.txt" | awk 'NF==2{print toupper($1), $2}'; } > symbols.txt
# equiv.py, sh4sim.py and shdis.py: the overlays' checker (tools/overlay/check), newer than the one 1ST_READ.BIN's proofs use
[ -f "$R/tools/overlay/check/$t" ] && exec python3 "$R/tools/overlay/check/$t" "$@"
exec python3 "$R/tools/$t" "$@"
