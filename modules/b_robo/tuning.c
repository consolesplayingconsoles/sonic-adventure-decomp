/* @unit 0C904F00-0C905040 +r04 +egflags +pool32 */
/* a debug menu that changes Float values from the second pad */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "b_robo/tuning.h"
#include "system/frame.h"
#include "system/pad.h"
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void text_set_size(Uint16 size);
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
void pdExecPeripheralServerUser(void);
void FUN_0c904f00(void);
void FUN_0c904f26(struct erobo_tuning *entry);
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
extern Sint8 tuning_picked;
extern Sint8 tuning_last;
extern struct erobo_tuning *tuning_entries[20];

#define ENTRIES 20

/* the index of the entry the menu shows and changes */

void FUN_0c904f00(void)
{
    int i;

    for (i = 0; i < ENTRIES; i++) {
        tuning_entries[i] = NULL;
    }
    tuning_picked = 0;
    tuning_last = -1;
}

void FUN_0c904f26(struct erobo_tuning *entry)
{
    int i;

    if (entry != NULL) {
        for (i = 0; i < ENTRIES; i++) {
            if (tuning_entries[i] == NULL) {
                tuning_entries[i] = entry;
                tuning_last = i;
                break;
            }
        }
    }
}

void erobo_tuning_step(void)
{
    struct erobo_tuning *entry;

    if (tuning_last >= 0) {
        if (per[1]->press & (1 << 6)) {
            if (--tuning_picked < 0) {
                tuning_picked = tuning_last;
            }
        }
        if (per[1]->press & (1 << 7)) {
            if (++tuning_picked > tuning_last) {
                tuning_picked = 0;
            }
        }
        entry = tuning_entries[tuning_picked];
        if (pad_held_live[1] & PDD_DGT_KU) {
            *entry->value += entry->step;
        }
        if (pad_held_live[1] & PDD_DGT_KD) {
            *entry->value -= entry->step;
        }
        if (loop_count == 0) {
            text_set_size(8);
            njPrintC(((0) << 16 | (11)), entry->label);
            njPrintF(((0) << 16 | (12)), *entry->value, 5);
            text_set_size(16);
        }
    }
}
