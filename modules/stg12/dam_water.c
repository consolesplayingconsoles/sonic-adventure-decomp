/* @unit 0C90FA00-0C90FB80 +jpflags +pool32 */
/* the surface of the water act 0's dam holds back */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "draw/tree.h"
#include "stg12/dam.h"
#include "stg12/dam_water.h"
#include "stg12/texlists.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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

#define TEXTURES 14
#define TEXTURE_LAST_TICK 2
#define FADE_SPEED 0.02F
#define VARS(work) ((struct shelter_dam_water_vars *)&(work)->vars)
extern NJS_OBJECT shelter_dam_water_object;

/* the textures the surface cycles through. each shows while work->tick
 * counts from 0 to TEXTURE_LAST_TICK, for three steps */

/* the alpha the surface loses each step it fades */

/* the surface stays still until the dam's water starts to fall. it falls
 * with that water until the water stops, then fades and is gone */
enum shelter_dam_water_mode { WATER_STILL, WATER_FALL, WATER_FADE, WATER_GONE };

/* work->tick counts the steps the texture has shown, and TASK_TIMER(work)
 * holds the texture's index */
struct shelter_dam_water_vars {
    Uint8 unk_00[8];
    Float alpha; /* constant material alpha, from 0 down to -1 as it fades */
};

void shelter_dam_water_step(struct task *task);
void shelter_dam_water_draw(struct task *task);

void shelter_dam_water_start(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 *point;
    Sint32 count;
    int i;

    work->mode = WATER_STILL;
    work->tick = 0;
    TASK_TIMER(work) = 0;
    VARS(work)->alpha = 0.0F;
    work->pos.y = shelter_dam_level;
    count = shelter_dam_water_object.model->nbPoint;
    point = shelter_dam_water_object.model->points;
    for (i = 0; i < count; i++, point++) {
        point->y = 0.0F;
    }
    task->step = shelter_dam_water_step;
    task->draw = shelter_dam_water_draw;
}

void shelter_dam_water_step(struct task *task)
{
    struct task_work *work = task->work;
    Float level = shelter_dam_level;

    switch (work->mode) {
    case WATER_STILL:
        if (work->pos.y != level) {
            work->pos.y = level;
            work->mode = WATER_FALL;
        }
        break;
    case WATER_FALL:
        if (work->pos.y == level) {
            work->mode = WATER_FADE;
        } else {
            work->pos.y = level;
        }
        break;
    case WATER_FADE:
        VARS(work)->alpha -= FADE_SPEED;
        if (VARS(work)->alpha <= -1.0F) {
            VARS(work)->alpha = -1.0F;
            work->mode = WATER_GONE;
        }
        break;
    case WATER_GONE:
        return;
    }
    work->tick++;
    if (work->tick > TEXTURE_LAST_TICK) {
        work->tick = 0;
        TASK_TIMER(work)++;
        TASK_TIMER(work) %= TEXTURES;
    }
    shelter_dam_water_object.model->mats[0].attr_texId = TASK_TIMER(work);
    shelter_dam_water_draw(task);
}

void shelter_dam_water_draw(struct task *task)
{
    struct task_work *work = task->work;

    njSetTexture_jp(&shelter_suimen_texlist);
    njPushMatrix(NULL);
    SetMaterial(VARS(work)->alpha, 0.0F, 0.0F, 0.0F);
    njTranslateV(NULL, &work->pos);
    late_DrawObject(&shelter_dam_water_object);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    late_DrawObjectClipEx(1);
}
