/* @unit 8C0A0EC0-8C0A0F40 +jpflags +pool32 */
/* act changes in place, without ending the stage */
#include <sg_xpt.h>

#include "camera/camera.h"
#include "collision/world.h"
#include "object/placement.h"
#include "player/reset.h"
#include "sound/cue.h"
#include "stage/act.h"
#include "stage/stage.h"
void FUN_8c63aed8(NJS_LIGHT *l);
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c6214fa(NJS_MODEL *volatile model);
void FUN_8c610c70(Float inten, Float ambient);
void FUN_8c610c7e(Float r, Float g, Float b);
void FUN_8c604642(Int mode, Int frame, Int count);
void FUN_8c605220(void);
void FUN_8c60ed26(Uint32 and_attr, Uint32 or_attr);
void FUN_8c60ed4a(Float dnear, Float dfar);
void text_set_size(Uint16 size);
void FUN_8c6409c0(Int loc, Int val, Int digit);
void nwEditWinPrintf(Int loc, const char *fmt, ...);
void FUN_8c640468(NJS_SCREEN *s);
void njUserClipping_jp(Int mode, NJS_POINT2 *p);
Bool late_DrawObjectClipEx(Uint32 n);
Float FUN_8c63fec4(NJS_POINT3 *p, NJS_LINE *l, NJS_POINT3 *cp);
Sint32 FUN_8c6214da(NJS_MODEL *model);
void FUN_8c62153a(NJS_OBJECT *obj);
void njGetkmPointer_jp(void);
void njSetkmPointer_jp(void);
void njSetEORflag_jp();
void FUN_8c606948(Uint32 mode);
void *njStartVertexNonTexOpaque_jp(void);
void *FUN_8c605e7c(void);
void *njStartVertexTexOpaque_jp(void);
void *FUN_8c605fba(void);
void *FUN_8c6061ec(Uint32 *color);
void *njStartVertexNonTexTransIntens_jp(Uint32 *color);
void *njStartVertexTexOpaqueIntens_jp(Uint32 *color);
void *kmRenderTexture(Uint32 *color);
void njEndVertex_jp(Uint32 *vertex);
Sint32 njSetkmTextureNum_jp(Uint32 n);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void FUN_8c6094be(NJS_CACTION *caction, Float frame);
void FUN_8c63e114(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
void kmSetFogTable(NJS_FOG_TABLE fog);
void FUN_8c63fd44(Uint32 c);
void njSetVSyncFunction_jp(void (*func)(void));
void njWaitVSync_jp(void);
void FUN_8c608b6a(NJS_TEXMEMLIST *addr, Uint32 n);
void demo_next_mode(void);
void FUN_8c608d14(NJS_TEXMEMLIST *addr, Uint32 n);
Uint32 njCalcTexture_jp(Uint32 flag);
Sint32 njSetTexture_jp(NJS_TEXLIST *texlist);
Sint32 njSetTextureNum_jp(Uint32 n);
Sint32 njReleaseTexture_jp(NJS_TEXLIST *texlist);
Sint32 FUN_8c64ddf8(Uint32 n);
void FUN_8c6071a4(NJS_TEXLIST *texlist, NJS_TEXNAME *texname, char *filename,
                  Sint32 size);
Sint32 njLoadTexturePvmFile_jp(const char *filename, NJS_TEXLIST *texlist);
Sint32 njLoadTexturePvmMemory_jp(Uint8 *addr, NJS_TEXLIST *texlist);
void FUN_8c608854(NJS_TEXINFO *info, Uint16 *tex, Sint32 type, Sint32 width,
                  Sint32 height);
void FUN_8c608862(NJS_TEXNAME *texname, void *addr, Uint32 globalIndex,
                  Uint32 attr);
Sint32 FUN_8c64e6e2(NJS_TEXMEMLIST *list, Uint32 n, Uint32 globalIndex);
Sint32 FUN_8c64f146(Uint32 type);
void FUN_8c608d64(void);
void FUN_8c64e4ce(Sint32 offset, Sint32 type);
Sint32 FUN_8c64ed3c(NJS_TEXNAME *texname, NJS_TEXINFO *info);
void njSetBackColor_jp(Uint32 col1, Uint32 col2, Uint32 col3);
void njSetBorderColor_jp(Uint32 color);
void njFrameBufferBmp_jp(char *bmp, char *buffer);
void njTextureFilterMode_jp(Int mode);
void njTextureClampMode_jp(Int mode);
void njTextureFlipMode_jp(Int mode);
void njColorBlendingMode_jp(Int target, Int mode);
void FUN_8c605406(Int mode);
void FUN_8c605514(Int mode);
void njMemCopy_jp(void *dst, const void *src, Sint32 num);
void njMemCopy4_jp(void *dst, const void *src, Sint32 num);
extern NJS_MATRIX nj_unit_matrix_;
void FUN_8c01957e(void);
void FUN_8c01a7a4(NJS_VECTOR *offset);
void fishing_give_prize(void (*step)(struct camera_view *view), Uint8 adjust,
                        Sint8 type);
Bool FUN_8c021b60(void);
int FUN_8c01b406(void);
Bool FUN_8c01b5e0(void);
void FUN_8c021700(struct camera_view *view);
void AmyBalanceGameStartChecker(struct camera_view *view);
void FUN_8c052518(void);
void FUN_8c052ba0(void);
void SetMleriRangeRad(Float radius);
Bool CheckRangeOut(struct task *task);
void FUN_8c091aca(struct task *task);
extern Sint16 stage_retry_count;
extern Sint16 fishing_reset;
extern Sint16 SetObject;
Uint16 GetStageNumber(void);
void FUN_8c04f84e(Sint16 by);
Bool nj_constant_attr_and_(void);

void act_change(Sint16 by, int music)
{
    music_end();
    world_change_act(by);
    placement_change_act(by);
    camera_change_act(by);
    FUN_8c04f84e(by);
    player_place_start(0);
    if (music >= 0) {
        music_start(music);
    }
}
