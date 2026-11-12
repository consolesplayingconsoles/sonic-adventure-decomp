# Sonic Adventure decomp

![decomp progress](badges/progress.svg?p=44.4&b=8.9&a=0&s=0)

**Explore this decomp project with [Shuriken Explorer](https://consolesplayingconsoles.github.io/dc-shuriken-explorer/) and see the game's models, skeletons, animations, textures, images, sounds, text and side-by-side C and assembly code directly in your browser.**

A decompilation of the Dreamcast **Sonic Adventure**, in progress. It rebuilds the game's executable byte for byte.
A function is **done** when its C rebuilds byte for byte (Matching): the build compiles it with the SDK's own compiler,
links it in place, and the result has to `MATCH` the original.

_**This is not a traditional, human-idiomatic decompilation.** It is structured and documented for AI consumption,
and its tooling is built for the automation and scale of that paradigm.
If needed, a human-idiomatic rewrite can start from it, as a fork or a new project.
This project constitutes a solid stepping stone for such a target: it contains matching C, the asset maps,
the Shuriken Explorer code and asset views, the build pipeline and the author's notes in [docs/engine.md](docs/engine.md)._

**This repository contains no game code or data.** You supply your own disc; `setup.sh` generates
everything game-derived on your machine, and `.gitignore` keeps it out of git.

## Progress

<!-- progress -->
```
FUNCTIONS                              
FUNCTIONS LEFT  (44.4% complete) 3351  of the 6022 functions
BYTES LEFT    (8.9% complete) 5773988  of 6336294 bytes of code
  unnamed                        1605  functions still called FUN_... (1605 of 6022)
  documented                     0.0%  3 named functions in docs/*.md
OVERLAYS                          200 of 232 disc files with code, 21074 functions, 4166844 bytes of code (separate total)
  matching C                20.3%  6663 functions, 845062 bytes, 1045 units: rebuilt byte for byte (build_overlays.sh)
  named                     59.2%  12483 functions
  not in scope                     32 files (overlays.tsv says why)
```
<!-- /progress -->

Updated on every commit by `tools/hooks/pre-commit` (enable once per clone:
`git config core.hooksPath tools/hooks`).

## The steps

This decomp follows the first steps of the dc-decomp-kickoff skill, then matches the C: the goal is a byte-identical rebuild from C. `AGENTS.md` has the detail.

| # | Step                                    | Decomp completion                              | You provide                        | What it does                                                                                                                                                                                                                                                                                                               |
|---|-----------------------------------------|------------------------------------------------|------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1 | **Decomp project setup**                | -                                              | The disc as a `.gdi`, a Katana SDK | Installs the tools (Docker, Python 3) and checks your game disc and SDK.                                                                                                                                                                                                                                                   |
| 2 | **Signature-driven baseline**           | -                                              |                                    | Reads the disc, splits the executable into one assembly file per function, rebuilds it **byte for byte** with the SDK's own assembler and linker, and names every function it can match by signature.                                                                                                                      |
| 3 | **Asset mapping**                       | -                                              |                                    | Writes the text map (every string with its pointers, text per disc file), the model map, the texture list and the audio map.                                                                                                                                                                                               |
| 4 | **Opportunity-driven optional boosts**  | Varies greatly by project                      | The materials                      | Uses what you hand over to save work in every step after it, the earlier the better: a later port (Android is the strongest), a prototype or debug build, cheat codes, other regions, existing notes, the same game on another console, a sibling decomp. It never looks for these itself and never reads your other code. |
| 5 | **Matching C**                          | up to 100%                                     | SDK library sources (optional)     | Rewrites the game one original source file at a time as C that compiles to the original's exact bytes: `src/<name>.c` with an `@unit` header, laid out like the original (`tools/1-2-baseline/fill.py`) and linked in place; `build.sh` must still print `MATCH`. The SDK's own library source, where you have it, reproduces library functions byte for byte too (`tools/5-generated/sdk_source.py`). |

## Build

You need: your own copy of the disc as a `.gdi` with its track files, Python 3, Docker, and a Katana SDK (its Hitachi
assembler and linker do the build; any folder layout works).

```
make setup GDI="path/to/your disc.gdi"
echo 'SDK_PATH="/path/to/katana-sdk"' > .env      # once: where your SDK is (not committed)
echo 'SDK_R04_PATH="/path/to/shc-5.1r04/bin"' >> .env   # the older compiler most of the game's C needs (docs/matching.md)
make
```

`make` (which runs `build.sh`) should end with `MATCH`. `bash build_overlays.sh` does the same for the code overlays: see [docs/overlays.md](docs/overlays.md).

It builds its own small tools image the first time (Docker must be running). The first build assembles every file
(a few minutes); after that only changed files. (Running the scripts with `bash` means file permissions never matter;
`./build.sh` works too once `setup.sh` has run.) Docker is required; on Linux x86_64 without
Docker, `DC_LOCAL=1` runs the tools through `wibo` instead.

## Supported version

| | |
|---|---|
| Release | MK-5100050, V1.003, 1999-09-09, region E (Europe) |
| `1ST_READ.BIN` | 6735296 bytes, SHA-1 `7ca46c7d78f9bd869fdf5d8b6fa93da516dffded` |
| Linked at | `0x8C010000` |
| SDK era | Shinobi 1.41, Kamui 1.06, Ninja 01000081 (Feb-Mar 1999), ntUtl 2.00 (Aug 1999); CRI ADX 5.5x / Sofdec middleware; closest preserved release R9 (26 of 31 library builds) |

Other releases are different builds: `setup.sh` refuses them rather than produce a broken split.

## What is here

**Instructions for agents and people working on the decomp**

| path           | what                                                                                                                                               |
|----------------|----------------------------------------------------------------------------------------------------------------------------------------------------|
| [AGENTS.md](AGENTS.md)    | The steps this decomp follows and the per-function loop |
| [KICKOFF](KICKOFF)      | The version of dc-decomp-kickoff this repo follows                                                                                                 |
| [.recomp.json](.recomp.json) | The project's metadata (game, version, status, approach) in the recomp.fyi format                                                                  |

**Documentation**

| path                             | what                                                                                                                                                   |
|----------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------|
| [README.md](README.md)                      | This file                                                                                                                                              |
| [docs/engine.md](docs/engine.md) | The author's notes: the particularities of this game's code and data, and what was learned                                                             |
| text-map/                      | (generated) The executable's strings, how much text each disc file holds, and every image file (`images.tsv`): counts and lists to read, not a verdict |

**The functions and their names**

| path                       | what                                                                                                                                    |
|----------------------------|-----------------------------------------------------------------------------------------------------------------------------------------|
| [functions.txt](functions.txt)            | Every function: address, size, name (`FUN_<addr>` = not named yet). The source of truth for boundaries; [asm/](asm/) is generated from it     |
| [globals.txt](globals.txt)              | Named globals: address and the original name                                                                                            |
| [symbols.txt](symbols.txt)              | Addresses the C units use that no file defines yet (RAM, data inside asm)                                                               |
| [sdk.txt](sdk.txt)                  | The bundled Sega SDK's code (for [tools/progress.py](tools/progress.py))                                                                                   |
| [models.txt](models.txt), [model-map/](model-map/) | What is known about the game's 3D models: tables whose layout is understood (read by [tools/3-assets/model_map.py](tools/3-assets/model_map.py)), and the map built from them |
| [BASE](BASE)                     | Link address                                                                                                                            |

**The C**

| path | what |
|---|---|
| [src/](src/) | The matching C units (`@unit` files, built by `build.sh`, see below) |
| [partial/](partial/) | C that was written but does not match yet: drafts, counted apart from done |
| [sdk-verified.txt](sdk-verified.txt) | Library functions whose bytes the SDK source you supplied reproduces (written by [tools/5-generated/sdk_source.py](tools/5-generated/sdk_source.py)) |
| [sdk-headers/](sdk-headers/), [sdk-patches.txt](sdk-patches.txt) | The SDK headers and the changes to the supplied sources that [tools/5-generated/sdk_source.py](tools/5-generated/sdk_source.py) needs |

**Progress**

| path | what |
|---|---|
| [badges/](badges) | The progress badge, written by [tools/progress.py](tools/progress.py): `progress.svg`. It also lists the statuses in [status.txt](status.txt) (BUILDS FROM C, BOOTS TO MENU, PLAYABLE, STABLE), ticked, crossed, or a question mark where not tested yet (`[?]`); each needs the ones above it |

**Scripts and tools**

| path | what |
|---|---|
| [setup.sh](setup.sh) | Extract and verify your executable and code overlays, generate [asm/](asm/), `overlays/<name>/asm/`, [text-map/](text-map/) and [model-map/](model-map/) |
| [Makefile](Makefile) | The build commands: `make setup`, `make`, `make progress` |
| [build.sh](build.sh) | Assemble, link, convert, compare with your original (`--overlay <name>`: one code overlay) |
| [build_overlays.sh](build_overlays.sh), [overlays.tsv](overlays.tsv), [overlays/](overlays/) | The code overlays: their list and load addresses, function lists, C units, and the build of them all ([docs/overlays.md](docs/overlays.md)) |
| [disc.sh](disc.sh) | Build a playable disc image of your version (files you put under `disc/`) |
| [textures.sh](textures.sh) | Optional: every standard texture on one page, to look through |
| [tools/](tools/README.md) | The tools several steps use: the SH-4 disassembler and simulator, progress and status reports, renaming |
| [tools/1-2-baseline/](tools/1-2-baseline/README.md) | Steps 1-2: splitting the executable, the C-unit layout, SDK naming |
| [tools/3-assets/](tools/3-assets/README.md) | Step 3: text map, model map, textures |
| [tools/4-boosts/](tools/4-boosts/README.md) | Step 4: names and C from a sibling decomp, checks against the running game |
| [tools/5-generated/](tools/5-generated/README.md) | SDK source (`sdk_source.py`) and the other checks |
| [tools/8-build/](tools/8-build/README.md) | The build from C and the disc image |

**Local only (git-ignored)**

| path | what | written by |
|---|---|---|
| 1ST_READ.BIN, asm/, objects.txt | Your executable and the assembly generated from it | [setup.sh](setup.sh) (with `tools/gdi_read.py` and `tools/1-2-baseline/split_asm.py`) |
| sdk-source/ | The C of the library functions, from the SDK source you supplied | `tools/5-generated/sdk_source.py` |
| build/ | Build output (`build/obj/`, `build/out.bin`) | `make` (`build.sh`) |

## Model map

`setup.sh` also builds `model-map/game.dcgs` (with `tools/3-assets/model_map.py`): every model it recognises in the disc files, the
table in the executable that holds it, the texture lists, every sound it recognises (CRI ADX and AHX streams, and the sound
banks), and, where a skeleton is known, characters assembled from their parts. It is plain tab-separated text in sections (`[models]`, `[assemblies]`, `[rigs]`, `[bones]`, `[audio]`, `[textures]`) and it is
**committed**: it holds addresses, offsets, sizes and names only, no game bytes or text (the text map is the one
that stays local). Regenerate it with `python3 tools/3-assets/model_map.py 1ST_READ.BIN "$(cat BASE)" functions.txt "<your disc>.gdi" model-map`.

- **No setup needed to start.** With no rules the map still lists every model it recognises, grouped by the table that holds it.
- **`models.txt` is what is known about the game's models**, one rule per line: `chars` and `structs` (tables whose
  layout is understood), `rig` / `bone` / `assemble` (a skeleton posed from a motion record), `nodes` / `nodelayout` (linked node structs in
  the executable, each character placed in its bind pose), `textures` (pairs a
  model file with a texture file of another name; matching names are found by themselves), `note`, and the two a
  person adds by naming things: `name <file> <offset> <text>` (one model), `sound <file> <entry> <text>` (one sound), `image <file> <offset> <text>` (one picture) and `table <address> <group> <label>`
  (a whole table). The syntax is in the header of `tools/3-assets/model_map.py`.
- **Naming convention.** A row shows the name first and the id beside it, and only the id when there is no name.
  Names are tidied the same way everywhere: words separated by single spaces (underscores and camelCase become
  spaces), each word starting with a capital, no parentheses. Ids (hex offsets, table addresses, the game's own
  identifiers) are never changed.
- **Naming things.** Edit `models.txt` and rerun the tool, or use a model viewer that opens this folder and writes
  the `name` and `table` lines for you, into two sorted blocks at the end of the file, so a naming session is a small
  `git diff`. Commit the diff.

## Matching C units

A file `src/<name>.c` whose first line is `/* @unit <start>-<end> [shc options] */` replaces every
asm file in that address range. `build.sh` compiles it with the SDK's `shc` to assembly, lays it
out exactly like the original (`tools/1-2-baseline/fill.py`: alignment as nops, reserved gaps as `0xEE`, padded
to `<end>`), assembles it and links it in place; the result still has to `MATCH`. A unit with
constant data (initialised local arrays, const tables, string literals) also names where the
original link put that data: `/* @unit <start>-<end> @data <dstart>-<dend> [shc options] */`. The
data becomes its own piece at that range, in source order; both ranges must start and end on asm
file boundaries (add them to `functions.txt`: `F <addr> 0 FUN_<addr>` for a function start,
`D <addr> 0 data_<addr>` for a data boundary, which is not counted as a function). A unit is one
original source file: all its functions share literal pools, so it goes in only when all of it
matches. A unit can also sit in a folder of `src/` (`src/player/sonic.c`), beside the headers it includes: the C ported from the
Japanese release's decomp ([docs/matching.md](docs/matching.md#the-source-tree-of-the-japanese-release)) keeps that tree, with
`modules/` and `events/` for the overlays' sources and `sdk/` for the library headers. The layout options (`+pool32` and others), the other
compiler some units need (`+r04`: SHC 5.1 Release 4, `SDK_R04_PATH` in `.env`) and what made the units match: [docs/matching.md](docs/matching.md). `python3 tools/progress.py` reports the state,
each function in one bucket: done (matching C, and library functions the SDK's own source reproduces), named only (a name is
not done work), unnamed; plus documented functions and named globals.

## Names

Names come from signature matching: 1046 matches from the Katana SDK's own libraries (only
unique matches are applied). 1088
functions carry a name in all, because small wrappers inherit the name of the function they call.

## How this was started

This repo was autogenerated using
[dc-decomp-kickoff](https://github.com/consolesplayingconsoles/dc-decomp-kickoff) unstable. It follows the steps above; `AGENTS.md` says how.

## Related work

- [reshaped/sonic-adventure](https://github.com/reshaped/sonic-adventure): the matching decompilation of the Japanese release.
  Its C, ported to this release, is most of this repo's matching C (`src/<dir>/`, `modules/`, `events/`, `sdk/`).
- [FraGag/sadx_decomp](https://github.com/FraGag/sadx_decomp): a decompilation of the GameCube release. A reference for structures, class names and logic; no bytes match the Dreamcast build.

## Third-party sources

The build needs a Katana SDK. Repositories that hold such material (for example
`Kochise/dreamcast-docs`)
are named solely as examples of the type of material required. We have no affiliation with, and
make no representation regarding, those repositories, their contents, or their licensing. You are
solely responsible for determining whether you are entitled to obtain and use any such material.

Sonic Adventure and its publisher's trademarks belong to their owners. This project is not affiliated with
or endorsed by them.
