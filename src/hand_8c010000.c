/* @unit 8C010000-8C0100A0 +res00 */
/* Hand-written from the European disassembly: Shinobi's strt1.src start record (the boot entry: cache setup, jump to _INIT) and the
   library-handle records between "Lib Handle Start" and "Lib Handle End" (gdfs and ov_main entries). The original is assembly and
   data, kept here as SHC #pragma asm text. */
extern void FUN_8c0100a0(void);     /* _INIT, src/hand_8c0100a0.c */
extern char DAT_8c66c3f4[];         /* the overlay library's record */

#pragma asm
          .IMPORT     _FUN_8c0100a0
          .IMPORT     _DAT_8c66c3f4
          .EXPORT     _blob_8c010000
_blob_8c010000:
          NOP
          NOP
          NOP
          NOP
          NOP
          NOP
          MOV.L       strt_ccr,R0
          MOV.L       @R0,R1
          MOV.L       strt_ccr_bits,R2
          AND         R2,R1
          MOV.W       strt_ccr_ici,R2
          OR          R2,R1
          MOV.L       R1,@R0
          MOV.L       strt_init,R0
          JMP         @R0
          NOP
strt_ccr_ici:
          .DATA.W     H'0800
          .DATA.W     H'0000
strt_ccr:
          .DATA.L     H'FF00001C
strt_ccr_bits:
          .DATA.L     H'000089AF
strt_init:
          .DATA.L     _FUN_8c0100a0
          .SDATA      "Lib Handle Start"
          .DATA.L     H'00000000,H'00004100,H'00000000,H'00000000
          .DATA.L     H'BA7E0A00,H'11D1BDA9,H'6000EB8A,H'5F629508
          .DATA.L     _DAT_8c66c3f4,H'00000601,H'00000000,H'00000000
          .DATA.L     H'AC19E50A,H'11D20797,H'1000D3AC,H'D5E82A4B
          .DATA.L     H'00000000,H'00000000,H'00000000,H'00000000
          .SDATA      "Lib Handle End  "
#pragma endasm
