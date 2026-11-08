# Matching notes

What it took to rebuild source files of Sonic Adventure DC byte for byte, and what is still open. The binary is the authority throughout:
a unit counts only when `build.sh` (1ST_READ.BIN) or `build_overlays.sh` (an overlay) prints `MATCH` from a clean build.

## Overlays

Stage, boss, event and Chao code lives in PRS overlays (`overlays.tsv`). Bases: `0c900000` stages and bosses, `0c920000` Egg Carrier,
`0cb80000` events and Chao, `8c900000` ADVERTISE. `2_DP.BIN` (the Dream Passport browser, a separate program) is out of scope, and files with too
little code or an undecided base are listed with their `status` and stay out.

- Function lists come from `tools/overlay/analyze.py`, a reachability pass (about 90% of the known starts on 1ST_READ.BIN). Boundaries never change
  the rebuilt bytes, but a wrong one blocks a C unit: check them before writing C. A typical fault is a boundary on the delay slot of the
  previous function's `rts`.
- A byte match compares decompressed images; recompressing to the disc's exact PRS bytes is not done.
- Much code is linked into several images (6,116 overlay functions fall in 812 identical-code groups). A unit written once is carried to every
  copy with `tools/overlay/carry_unit.py`; most copies are unnamed in their overlay's list, so `<overlay>@<address>` places them by address.
  Units of only a few words match everywhere by chance: such hits are not copies.
- `build_overlays.sh` builds an overlay's units as `build.sh` does (`tools/overlay/build.py`). The compiler needs a short temp folder: under a long
  path it cannot open its temp files ("Cannot open internal file"). The build stops when `units.py` refuses a unit (a range not on function
  boundaries) and deletes the previous image before linking, so a failed link can never compare a stale image.

## The game's layout (`fill.py` options, in the `@unit` header)

- `+pool32`: the game's own code puts a source file's literal pool on a 32-byte boundary; the gap before it is the word 0x0900, and zero bytes run
  from the pool to the next file (342 of 469 game source files of 1ST_READ.BIN). The instructions are the compiler's own; only the layout differs.
- `+tail0900`: code that resumes after a pool in the middle of a file starts at the next 32-byte boundary, the gap 0x0900 words, and the unit's
  tail is 0x0900 too. The Kamui register functions (`src/kamui_regs.c`) match so: what looked like hand-written assembly was this layout.
- `+poolafter=f1,f2`: the original link has a literal pool after these functions as well as at the end; each group of functions gets its own pool
  right after it, entries in the compiler's order.
- A gap the compiler reserves inside a literal pool (`.RES` after `.DATA`) is zero in the original (153 of 157 cases); other reserved gaps are 0xEE.
- `-speed` (a compiler option): some game files were built for speed. Signs: struct copies inlined, plain `for` loops kept as such.
- Library code padded with `nop`s between functions was built with `-align16`.

## The game's compiler is not any available SHC

The code of the game itself (not the SDK libraries) was built by a compiler that differs from every available SHC (5.0r10, r26, r28, r31, r32;
5.1r01, r03, r04, r08, r11, r13; any option or `-cpu`) in how it puts constants in registers:

| constant | game's code | available SHC | 1ST_READ.BIN game code | SDK libraries |
|---|---|---|---|---|
| 16-bit (0x100, ~0x100) | `mov #hi; shll8 [; add #lo]` | `mov.w` from the pool | 1,806 against 14 pool loads | 5 against 113 |
| 128 to 255 | `mov #v-256; extu.b` | `mov.w` from the pool | 1,968 against 174 pool loads | 1 against 1,222 |

`+synth16` emulates it: `fill.py` writes the game's form for each such `mov.w` (not one in a branch's delay slot), drops the constant from the pool
and moves the pool's other loads to their new offsets. It changes instructions, so a unit asks for it by name and says why in its header.
`tools/fcmp.py` applies it too when the header asks. First use: `skywalk.c` (EV0001 and 12 other event overlays), where `twp->flag |= 0x100` was
the one difference left.

SHC 5.0 runs under wibo only with short paths ("Illegal environment variable" otherwise); 5.0r10 refuses `-fpu=single` and `-round=nearest`.
The game's code was built without `-round=nearest`: 0.025f is 0x3CCCCCCC, one bit under the nearest float.

## What made files match

- One unit is one original source file: the compiler shares one literal pool across a file's functions, so a function cannot match alone when its
  pool is shared. A run of neighbours that ends with its own pool is enough; the rest stays asm.
- Event files (`se.c`, `tikallight.c`, `objsmoke.c`, `skywalk.c`): reading `tp->twp` after setting the task's functions; `if (--x == 0)`;
  clamps as `if (x < 0) ... else if (x > 1)`; `timer.f = 0.0f` written as a float; `x = y = 0` in the original's store order; float constants
  written out to the bit; a local copy of a global object pointer.
- `se.c`: the sound state lives in the task's work (+16) rather than an allocated block; task creation and the volume, pan and pitch setters are
  static helpers the public functions call or tail-call; explicit temporaries in CEventSe_Exec; `gOneshotId++; gOneshotId &= 0x1F;`.
- A difference that no rewording moves is worth checking against another compiler version first; when all versions agree, it is the C.
- `tools/permute.py` (one function, rewrites that keep the meaning, kept when `fcmp.py --score` gets no worse): local copies of globals, flattening
  blocks, commutative operands, comparison direction, `!x` and `x == 0`, if/else order, neighbouring statements, declarations, `register`, `x op= y`.

## Matched so far

- 1ST_READ.BIN: `src/*.c` (30 units), among them the CRI ADX bitstream decoder's accessors and pool (`adxb_get.c`, `adxb_obj.c`), the VMS file
  system's command slots (`vmsfs_cmd.c`) and the Kamui register functions (`kamui_regs.c`).
- Overlays: `event_se.c` (14 functions, 132 overlays), `tikallight.c` (4 functions, 26), `objsmoke.c` (4, 17), `skywalk.c` (4, 13), `capturebeam.c`
  (10 events), and the game's object files `o_carrier_sidelift.c`, `o_eggcarrier_eggcap.c`, `o_eggcarrier_itembox.c`, `o_eggcarrier_palmbase.c`,
  `o_mysticruin_eggmandoor.c`, `o_twinkle_catapult.c`, `o_twinkle_rocket.c`, `egm3.c`, `sht_score.c`, `sht_target.c`, `sht_tenkyu.c`.

## Open

- `overlay.c` (COverlay, the screen tint; EV0001 0CB829A0-0CB82B60, about 20 overlays): 8 of 9 functions match. COverlayDisp has the original's
  instructions in a different order: the original stores `p2c.p` before `p2c.col` and calls `njColorBlendingMode` through r1 (ours: r2). Every SHC
  version agrees with ours, so it is the C. A nested `if (!loop_count) if (a > 0)` and `col[0] = col[1] = col[2] = col[3]` got it this close.
  Its screen corners (0CB93DB8, {0,0} {0,480} {640,480} {640,0}) are the file's initialised data, which `fill.py` cannot lay out yet.
- `moveobj.c` (EV0001 0CB81740-0CB829A0, in most event overlays): 17 functions (getTaskIndex, nine movers for modes 1, 4, 4, 7, 10, 13, 13, 19
  and 22, stopObject, stopObjectAll, init, exec, disp, dest). getTaskIndex matches; each mover differs only where the original keeps
  `task_index * 4` on the stack and reloads the array's address for the final `p_MoveObjTask[i]->twp->mode = n` (ours shifts again). No SHC
  version, option or rewording tried does that; 1ST_READ.BIN has 42 such spills, none in code matched so far.
- `fill.py` cannot lay out initialised (D) or zeroed (B) variables yet: a file's own data stays in asm and its C declares it `extern`.
- `njDrawPolygon2D` (8c63eb08) takes `(NJS_POINT2COL *, Int, Float, Uint32)`; an earlier name for it was wrong.
