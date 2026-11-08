#!/usr/bin/env bash
# Rebuild every overlay image from overlays/<name>/asm and check each against the disc's decompressed bytes.
#   bash build_overlays.sh [name ...]     (setup.sh prepares them; SDK_PATH as for build.sh)
set -euo pipefail
cd "$(dirname "$0")"
[ -z "${SDK_PATH:-}" ] && [ -f .env ] && . ./.env
[ -n "${SDK_PATH:-}" ] || { echo "[ERROR] no SDK_PATH"; exit 1; }
SDK_PATH="$(cd "$SDK_PATH" && pwd)"
ASMSH="$(find "$SDK_PATH" -iname asmsh.exe -print -quit)"
REL="${ASMSH#"$SDK_PATH"/}"; REL="${REL%/*}"
if [ "${DC_LOCAL:-0}" = 1 ]; then
  T="$SDK_PATH/$REL" python3 tools/overlay/build.py "$@"
else
  . tools/docker_check.sh
  docker_ready tools/tools-image || exit 1
  docker run --rm -v "$SDK_PATH":/sdk:ro -v "$PWD":/app -w /app -e T="/sdk/$REL" -e JOBS "${DC_TOOLS_IMAGE:-dc-tools}" python3 tools/overlay/build.py "$@"
fi
