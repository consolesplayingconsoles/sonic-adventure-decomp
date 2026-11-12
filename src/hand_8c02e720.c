/* @unit 8C02E720-8C02E820 +res00 */
/* Hand-written from the European disassembly: the game's cache.src (cache_ram_init, cache_ram_restore, cache_ram_end, cache_empty,
   matrix_load_parent; JP refs src/system/cache.src). The original is assembly (LDC SR, FSCHG and the XD loads have no C form), kept
   here as SHC #pragma asm text; each literal pool and its zero gap are spelled out where the assembler put them. */
extern float *_nj_current_matrix_ptr_;  /* Ninja's current matrix */

#pragma asm
          .IMPORT     __nj_current_matrix_ptr_
          .EXPORT     _FUN_8c02e720
          .EXPORT     _cache_ram_restore
          .EXPORT     _matrix_load_parent
_FUN_8c02e720:
          RTS
          NOP
          MOV.L       cache_ccr1,R1
          MOV.L       @R1,R0
          OR          #32,R0
          MOV.L       R0,@R1
          RTS
          NOP
cache_ccr1:
          .DATA.L     H'FF00001C
_cache_ram_restore:
          RTS
          NOP
          MOV.L       cache_ccr2,R1
          MOV.L       @R1,R0
          OR          #32,R0
          MOV.L       R0,@R1
          MOV.W       cache_w2_0,R2
          MOV.W       cache_w2_1,R3
          MOV.W       cache_w2_2,R7
          BRA         cache_empty_lines
          NOP
cache_w2_0:
          .DATA.W     H'0000
cache_w2_1:
          .DATA.W     H'2000
cache_w2_2:
          .DATA.W     H'0100
cache_ccr2:
          .DATA.L     H'FF00001C
cache_empty_lines:
          MOV         #15,R1
          SHLL2       R1
          SHLL2       R1
          NOT         R1,R1
          STC         SR,R0
          AND         R1,R0
          OR          #240,R0
          LDC         R0,SR
          MOV.L       cache_oc,R1
          ADD         R1,R2
          ADD         R1,R3
          MOV         #0,R0
cache_line:
          MOV.L       R0,@R2
          MOV.L       @R3,R4
          MOV.L       R0,@R3
          ADD         #32,R2
          ADD         #32,R3
          DT          R7
          BF          cache_line
          NOP
          NOP
          NOP
          NOP
          MOV         #15,R1
          SHLL2       R1
          SHLL2       R1
          NOT         R1,R1
          STC         SR,R0
          AND         R1,R0
          LDC         R0,SR
          RTS
          NOP
cache_oc:
          .DATA.L     H'F4000000
cache_ram_end:
          RTS
          NOP
          MOV.L       cache_ccr3,R1
          MOV.L       @R1,R0
          MOV.L       cache_notora,R2
          AND         R2,R0
          MOV.L       R0,@R1
          MOV.W       cache_w3_0,R2
          MOV.W       cache_w3_1,R3
          MOV.W       cache_w3_2,R7
          BRA         cache_empty_lines
          NOP
cache_w3_0:
          .DATA.W     H'0000
cache_w3_1:
          .DATA.W     H'2000
cache_w3_2:
          .DATA.W     H'0100
          .DATA.W     H'0000
cache_ccr3:
          .DATA.L     H'FF00001C
cache_notora:
          .DATA.L     H'FFFFFFDF
cache_empty:
          MOV.L       cache_p_all,R0
          MOV.L       cache_p2,R1
          OR          R1,R0
          JMP         @R0
          NOP
          .DATA.W     H'0000
cache_p_all:
          .DATA.L     cache_empty_all
cache_p2:
          .DATA.L     H'A0000000
cache_empty_all:
          MOV.W       cache_w4_0,R2
          MOV.W       cache_w4_1,R3
          MOV.W       cache_w4_2,R7
          BRA         cache_empty_lines
          NOP
cache_w4_0:
          .DATA.W     H'0000
cache_w4_1:
          .DATA.W     H'2000
cache_w4_2:
          .DATA.W     H'0100
_matrix_load_parent:
          MOV         #1,R4
          SHLL2       R4
          SHLL2       R4
          MOV.L       cache_cur,R5
          SHLL2       R4
          MOV.L       @R5,R1
          SUB         R4,R1
          FSCHG
          .DATA.W     H'F119
          .DATA.W     H'F319
          .DATA.W     H'F519
          .DATA.W     H'F719
          .DATA.W     H'F919
          .DATA.W     H'FB19
          .DATA.W     H'FD19
          .DATA.W     H'FF19
          FSCHG
          RTS
          MOV         #1,R0
          .DATA.W     H'0000
cache_cur:
          .DATA.L     __nj_current_matrix_ptr_
#pragma endasm
