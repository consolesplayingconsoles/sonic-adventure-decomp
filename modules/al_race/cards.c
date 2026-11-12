/* @unit 0CB91E00-0CB92020 +r04 +egflags +pool32 */
/* the Chao the race loads from the memory cards, and writes back to them */
#include <sg_xpt.h>
#include <shinobi.h>

#include "al_main/card.h"
#include "al_race/cards.h"
#include "chao/chao.h"
#include "save/card.h"
void pdExecPeripheralServerUser(void);
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void njUserClipping_jp(Int mode, NJS_POINT2 *p);
Bool late_DrawObjectClipEx(Uint32 n);
Float CalcDistance(NJS_POINT3 *p1, NJS_POINT3 *p2);
void late_DrawObjectClip(NJS_OBJECT *obj);
void njGetkmPointer_jp(void);
void njSetkmPointer_jp(void);
void njSetEORflag_jp();
void *njStartVertexNonTexOpaque_jp(void);
void *njStartVertexTexOpaque_jp(void);
void *njStartVertexNonTexTransIntens_jp(Uint32 *color);
void *njStartVertexTexOpaqueIntens_jp(Uint32 *color);
void njEndVertex_jp(Uint32 *vertex);
Sint32 njSetkmTextureNum_jp(Uint32 n);
void late_DrawSprite2D(NJS_SPRITE *sp, Int n, Float pri, Uint32 attr);
void CHAOS_SetChaosNo(Uint32 c);
void thunk_FUN_8c652d78(Uint32 density);
void ReleaseModule(NJS_FOG_TABLE fog, Float n, Float f);
void njSetVSyncFunction_jp(void (*func)(void));
void njWaitVSync_jp(void);
Uint32 njCalcTexture_jp(Uint32 flag);
Sint32 njSetTexture_jp(NJS_TEXLIST *texlist);
Sint32 njSetTextureNum_jp(Uint32 n);
Sint32 NeonuLoadTexture(NJS_TEXLIST *texlist);
Sint32 njReleaseTexture_jp(NJS_TEXLIST *texlist);
Sint32 njLoadTexturePvmFile_jp(const char *filename, NJS_TEXLIST *texlist);
Sint32 njLoadTexturePvmMemory_jp(Uint8 *addr, NJS_TEXLIST *texlist);
void njSetBackColor_jp(Uint32 col1, Uint32 col2, Uint32 col3);
void njSetBorderColor_jp(Uint32 color);
void njFrameBufferBmp_jp(char *bmp, char *buffer);
void njTextureFilterMode_jp(Int mode);
void njTextureClampMode_jp(Int mode);
void njTextureFlipMode_jp(Int mode);
void njColorBlendingMode_jp(Int target, Int mode);
void thunk_FUN_8c652c7a(Float size);
void njMemCopy_jp(void *dst, const void *src, Sint32 num);
void njMemCopy4_jp(void *dst, const void *src, Sint32 num);
extern NJS_MATRIX nj_unit_matrix_;
void AddExtraDisplay(Sint8 kind);
void ExtraDisplayInit(void);
int FUN_0cb91e9c(struct race_cards *cards);
int FUN_0cb91eec(struct race_cards *cards, int drive);
int FUN_0cb91f60(struct race_cards *cards);
int FUN_0cb91fbc(struct race_cards *cards);
extern const Sint32 race_drives[8];

int race_load_cards(struct race_cards *cards, struct chao *chao)
{
    /* @hack spelling: to, a cursor apart from chao, which the loop steps in
     * chao's place. it keeps cards in R13, i in R14, 8 in R9 and 1 in R8
     * (0x0cb93166 to 0x0cb9317a), as the image does. stepping chao itself,
     * each pair swaps and 20 of 76 words differ */
    struct chao *to = chao;
    int i;
    const Sint32 *drive = race_drives;

    cards->count = cards->remaining = cards->loaded = 0;
    for (i = 0; i < CARD_DRIVES; i++) {
        if (card_menu_drives[i].exec_marked == 1 &&
            card_menu_drives[i].chao.type != CHAO_NOTHING) {
            if (card_read_chao(*drive, to) == 1) {
                while (buStat(*drive) != BUD_STAT_READY) {
                }
                cards->loaded |= 1 << i;
                ++cards->count;
            }
        }
        ++drive;
        ++to;
    }
    cards->remaining = cards->loaded;
    return 1;
}

int FUN_0cb91e9c(struct race_cards *cards)
{
    int i;
    const Sint32 *drive = race_drives;

    for (i = 0; i < CARD_DRIVES; i++, drive++) {
        if (cards->loaded & (1 << i)) {
            if (buStat(*drive) == (Sint32)BUD_STAT_BUSY) {
                return 1;
            }
        }
    }
    return 0;
}

int FUN_0cb91eec(struct race_cards *cards, int drive)
{
    if (card_menu_drives[drive].chao.type != CHAO_NOTHING) {
        if (cards->loaded & (1 << drive)) {
            return 1;
        }
    }
    return 0;
}

int race_card_loaded(struct race_cards *cards, int drive)
{
    if (cards->loaded & (1 << drive)) {
        return 1;
    }
    return 0;
}

int FUN_0cb91f60(struct race_cards *cards)
{
    int i = 0;
    int bit;

    /* @hack spelling: the loop as a do-while, which SHC keeps rolled, as the
     * image does. as a for loop, SHC writes the body four times a pass, the
     * function runs 128 bytes long, and 18 of 31 words differ */
    do {
        bit = 1 << i;
        if (cards->remaining & bit) {
            if (card_menu_drives[i].present != 1) {
                cards->remaining &= ~bit;
            }
        }
    } while (++i < CARD_DRIVES);
    return 1;
}

int race_card_remains(struct race_cards *cards, int drive)
{
    if (cards->remaining & (1 << drive)) {
        return 1;
    }
    return 0;
}

int FUN_0cb91fbc(struct race_cards *cards)
{
    int i;

    for (i = 0; i < CARD_DRIVES; i++) {
        if (card_menu_drives[i].present != card_menu_drives[i].was_present) {
            return 1;
        }
    }
    return 0;
}

void race_card_save(struct race_cards *cards, int drive,
                    const struct chao *chao)
{
    card_write_chao(drive, chao);
}
