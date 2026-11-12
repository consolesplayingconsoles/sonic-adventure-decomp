/* @unit 0C92AE00-0C92AF60 +r04 +egflags +pool32 */
/* the hall's light glows: a sprite at each of the hall's 34 lamps, all
 * pulsing together */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv0130/egg_carrier_inside.h" /* NOLINT(misc-include-cleaner) */
#include "adv0130/hall_lights.h"
#include "draw/sprite.h"
#include "system/task.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);

/* work->scl.x holds the glows' scale, and work->ang.x the phase of their
 * pulse */
#define VARS(work) ((struct hall_lights_vars *)&(work)->vars)
struct hall_lights_vars {
    NJS_POINT3 *places;
    Sint16 count;
    Float alpha; /* from 0.2 to 1, with the pulse's sine */
};

enum hall_lights_mode { LIGHTS_INIT, LIGHTS_RUN };
extern NJS_POINT3 hall_lights_places[34];
extern int hall_lights_count;
extern NJS_TEXANIM hall_lights_frames[2];
extern NJS_SPRITE hall_lights_sprite;
extern NJS_ARGB hall_lights_no_color;
extern NJS_ARGB hall_lights_color;

void GreenBlinkDisplayer(struct task *task);

void ObjectECCGreenBlink(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case LIGHTS_INIT:
        work->scl.x = 0.5F;
        VARS(work)->places = hall_lights_places;
        VARS(work)->count = hall_lights_count;
        task->draw = GreenBlinkDisplayer;
        work->mode = LIGHTS_RUN;
        break;
    case LIGHTS_RUN:
        work->ang.x += 0x400;
        work->ang.x &= 0xffff;
        VARS(work)->alpha = (njSin(work->ang.x) * 0.4F) + 0.6F;
        break;
    }
    GreenBlinkDisplayer(task);
}

void GreenBlinkDisplayer(struct task *task)
{
    struct task_work *work = task->work;
    NJS_SPRITE *sprite = &hall_lights_sprite;
    NJS_POINT3 *place;
    int i;

    sprite->sx = sprite->sy = work->scl.x;
    place = VARS(work)->places;
    hall_lights_color.a = VARS(work)->alpha;
    hall_lights_color.r = 1.0F;
    hall_lights_color.g = 1.0F;
    hall_lights_color.b = 1.0F;
    njFogDisable();
    sprite_set_depth(-20.0F);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njSetConstantMaterial(&hall_lights_color);
    for (i = 0; i < VARS(work)->count; i++) {
        sprite->p = *place++;
        sprite_draw_3d(sprite, 0,
                       NJD_SPRITE_COLOR | NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
    }
    njSetConstantMaterial(&hall_lights_no_color);
    njFogEnable();
}
