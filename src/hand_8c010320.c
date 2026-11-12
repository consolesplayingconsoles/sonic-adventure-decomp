/* @unit 8C010320-8C010400 +res00 */
/* Hand-written from the European disassembly: the game's crt0.src helpers (_SetSR, _SetSP, _GetSP, _CashOn, point_calc, matrix_load,
   point_calc_loaded). The original is assembly (LDC SR, FRCHG, FTRV have no C form), kept here as SHC #pragma asm text; each literal
   pool and its zero gap are spelled out where the assembler put them. */
extern float *_nj_current_matrix_ptr_;  /* Ninja's current matrix */

#pragma asm
          .IMPORT     __nj_current_matrix_ptr_
          .EXPORT     _FUN_8c010320
_FUN_8c010320:
          LDC         R4,SR
          RTS
          NOP
crt0_SetSP:
          RTS
          MOV         R4,R15
crt0_GetSP:
          RTS
          MOV         R15,R0
crt0_CashOn:
          MOV.L       crt0_ccr_on,R0
          MOV.L       crt0_ccr,R1
          RTS
          MOV.L       R0,@R1
          .DATA.W     H'0000
crt0_ccr_on:
          .DATA.L     H'00000105
crt0_ccr:
          .DATA.L     H'FF00001C
crt0_point_calc:
          FMOV.S      @R5+,FR0
          MOV.L       crt0_p_one1,R0
          FMOV.S      @R5+,FR1
          FMOV.S      @R0,FR3
          TST         R4,R4
          BF/S        crt0_load1
          FMOV.S      @R5+,FR2
          MOV.L       crt0_p_cur1,R4
          MOV.L       @R4,R4
crt0_load1:
          FRCHG
          FMOV.S      @R4+,FR0
          FMOV.S      @R4+,FR4
          FMOV.S      @R4+,FR8
          FMOV.S      @R4+,FR12
          FMOV.S      @R4+,FR1
          FMOV.S      @R4+,FR5
          FMOV.S      @R4+,FR9
          FMOV.S      @R4+,FR13
          FMOV.S      @R4+,FR2
          FMOV.S      @R4+,FR6
          FMOV.S      @R4+,FR10
          FMOV.S      @R4+,FR14
          FMOV.S      @R4+,FR3
          FMOV.S      @R4+,FR7
          FMOV.S      @R4+,FR11
          FMOV.S      @R4+,FR15
          FRCHG
          FTRV        XMTRX,FV0
          ADD         #12,R6
          FMOV.S      FR2,@-R6
          FMOV.S      FR1,@-R6
          RTS
          FMOV.S      FR0,@-R6
          .DATA.W     H'0000
crt0_p_one1:
          .DATA.L     crt0_one1
crt0_p_cur1:
          .DATA.L     __nj_current_matrix_ptr_
crt0_one1:
          .DATA.L     H'3F800000
crt0_matrix_load:
          TST         R4,R4
          BF          crt0_load2
          MOV.L       crt0_p_cur2,R4
          MOV.L       @R4,R4
crt0_load2:
          FRCHG
          FMOV.S      @R4+,FR0
          FMOV.S      @R4+,FR4
          FMOV.S      @R4+,FR8
          FMOV.S      @R4+,FR12
          FMOV.S      @R4+,FR1
          FMOV.S      @R4+,FR5
          FMOV.S      @R4+,FR9
          FMOV.S      @R4+,FR13
          FMOV.S      @R4+,FR2
          FMOV.S      @R4+,FR6
          FMOV.S      @R4+,FR10
          FMOV.S      @R4+,FR14
          FMOV.S      @R4+,FR3
          FMOV.S      @R4+,FR7
          FMOV.S      @R4+,FR11
          FMOV.S      @R4+,FR15
          RTS
          FRCHG
          .DATA.W     H'0000
crt0_p_cur2:
          .DATA.L     __nj_current_matrix_ptr_
crt0_point_calc_loaded:
          FMOV.S      @R4+,FR0
          MOV.L       crt0_p_one2,R0
          FMOV.S      @R4+,FR1
          FMOV.S      @R0,FR3
          FMOV.S      @R4+,FR2
          FTRV        XMTRX,FV0
          ADD         #12,R5
          FMOV.S      FR2,@-R5
          FMOV.S      FR1,@-R5
          RTS
          FMOV.S      FR0,@-R5
          .DATA.W     H'0000
crt0_p_one2:
          .DATA.L     crt0_one2
crt0_one2:
          .DATA.L     H'3F800000
#pragma endasm
