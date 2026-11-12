/* @unit 8C0100A0-8C010180 +res00 */
/* Hand-written from the European disassembly: Shinobi's strt2.c (stack fill, section setup, library table). */
typedef unsigned char Uint8;
typedef unsigned long Uint32;

extern const char *__0ShinobiVersion;
extern void *DAT_8c66c200;              /* _DSGLH_BGN */
extern Uint8 *DAT_8c1110ec, *DAT_8c1110f8;   /* _B_BGN, _B_END */
extern Uint8 *DAT_8c1110dc, *DAT_8c1110e8, *DAT_8c1110d4;   /* _D_BGN, _D_END, _D_ROM */
extern Uint8 *DAT_8c66c22c, *DAT_8c66c238;   /* _BSG_BGN, _BSG_END */
extern Uint8 *DAT_8c66c218, *DAT_8c66c224, *DAT_8c66c210;   /* _DSG_BGN, _DSG_END, _DSG_ROM */
extern void FUN_8c053940(void);         /* main */
extern int ovMdlEntryTbl(void *ovmdl);
extern int ovMdlDeleteTbl(void *ovmdl);

void FUN_8c0100c8(void);
void FUN_8c0100d0(void);
void FUN_8c0100d8(void);

void FUN_8c0100a0(void)
{
    Uint32 *stack_word;

    (void)*(volatile const char *)__0ShinobiVersion;
    for (stack_word = (Uint32 *)0x8c00c000; stack_word < (Uint32 *)0x8c00f400; ++stack_word) {
        *stack_word = 0x41474553;
    }
    FUN_8c0100d8();
    FUN_8c0100c8();
    FUN_8c053940();
    FUN_8c0100d0();
}

void FUN_8c0100c8(void)
{
    ovMdlEntryTbl(DAT_8c66c200);
}

void FUN_8c0100d0(void)
{
    ovMdlDeleteTbl(DAT_8c66c200);
}

void FUN_8c0100d8(void)
{
    Uint8 *destination;
    Uint8 *initial;

    for (destination = DAT_8c1110ec; destination < DAT_8c1110f8; ++destination) {
        *destination = 0;
    }
    for (destination = DAT_8c1110dc, initial = DAT_8c1110d4; destination < DAT_8c1110e8; ++destination, ++initial) {
        *destination = *initial;
    }
    for (destination = DAT_8c66c22c; destination < DAT_8c66c238; ++destination) {
        *destination = 0;
    }
    for (destination = DAT_8c66c218, initial = DAT_8c66c210; destination < DAT_8c66c224; ++destination, ++initial) {
        *destination = *initial;
    }
}
