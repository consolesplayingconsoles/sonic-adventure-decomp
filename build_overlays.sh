#!/usr/bin/env bash
# Rebuild every code overlay with build.sh --overlay and check each against the disc's decompressed image.
#   bash build_overlays.sh [name ...]     (setup.sh prepares them; SDK_PATH, DC_LOCAL as for build.sh)
# JOBS=<n> (opt-in) builds n overlays at a time; the default is one at a time.
set -uo pipefail
cd "$(dirname "$0")"
if [ $# -gt 0 ]; then names=("$@")
else mapfile -t names < <(for d in overlays/*/; do [ -f "$d/objects.txt" ] && basename "$d"; done); fi
mkdir -p build
printf '%s\n' "${names[@]}" | xargs -P "${JOBS:-1}" -I{} sh -c 'mkdir -p "overlays/$1/build"; bash build.sh --overlay "$1" > "overlays/$1/build/build.log" 2>&1; echo "$1 $(tail -1 "overlays/$1/build/build.log")"' _ {} > build/overlays.txt
bad=$(grep -vc ' MATCH: ' build/overlays.txt)
grep -v ' MATCH: ' build/overlays.txt
echo "${#names[@]} overlays, $(( ${#names[@]} - bad )) MATCH, $bad not"
[ "$bad" = 0 ]
