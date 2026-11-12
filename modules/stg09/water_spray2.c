/* @unit 0C91CD60-0C91D080 @data 0CB23644-0CB23688 +jpflags +pool32 */
/* O WSR2 water spray, which puffs water smoke as O WSR does, in spells
 * between rests */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "debug/editor.h"
#include "draw/draw.h"
#include "effect/dust.h"
#include "object/placement.h"
#include "stg09/water_smoke.h"
#include "stg09/water_spray.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/util.h"
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
void *syMalloc_default_malloc(size_t size);
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
void SaveConstantAttr(void);
void LoadConstantAttr(void);
void OnConstantAttr(Uint32 and_attr, Uint32 or_attr);
void OffConstantAttr(Uint32 and_attr, Uint32 or_attr);
void SaveControl3D(void);
void LoadControl3D(void);
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* O WSR2 is destroyed beyond about 250 units of the camera and player 0.
 * RANGE is that distance squared */
#define RANGE 62510.0F

#define VARS(work) ((struct water_spray2_vars *)&(work)->vars)
#define SPRAYING(work) ((work)->submode)
#define INTERVAL(work) ((Uint8)(work)->ang.x)
#define SPEED(work) ((work)->scl.x)
#define SPREAD(work) ((work)->scl.y)
#define SIZE(work) ((work)->scl.z)
struct water_spray2_vars {
    Uint16 countdown; /* frames left in the spell or rest, after this one */
};
extern Sint32 water_spray2_spell_frames;
extern Sint32 water_spray2_rest_frames;
extern struct dust_params water_spray2_puff;

void water_spray2_run(struct task *task)
{
    struct task_work *work = task->work;
    union point_floats speed;
    Angle ang;
    Float spread;
    Float *at;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (loop_count) {
        return;
    }
    /* @hack spelling: the test for 0, written <= 0 for the image's CMP/PL
     * (0x0c91e5c2). countdown is a Uint16, so <= 0 holds only at 0. as == 0,
     * the test is TST, and 2 of 265 words differ */
    if (VARS(work)->countdown-- <= 0) {
        if (SPRAYING(work)) {
            VARS(work)->countdown =
                rand() * (Float)water_spray2_rest_frames * RAND_SCALE;
            SPRAYING(work) = FALSE;
        } else {
            VARS(work)->countdown =
                rand() * (Float)water_spray2_spell_frames * RAND_SCALE;
            SPRAYING(work) = TRUE;
        }
    }
    if (SPRAYING(work)) {
        if (TASK_TIMER(work)++ > INTERVAL(work)) {
            /* @hack spelling: the cursor taken as (&speed)->elements, whose
             * address SHC forms from R15 in R4 (0x0c91e626 to 0x0c91e62a); as
             * speed.elements, 247 of 265 words differ, and as member stores,
             * 152 */
            at = (&speed)->elements;
            *at++ = 0.0F;
            *at++ = SPEED(work);
            *at = 0.0F;
            njPushMatrix(&nj_unit_matrix_);
            TURN_VIA(njRotateY, work->ang.y, ang);
            TURN_VIA(njRotateZ, work->ang.z, ang);
            njCalcVector(NULL, &speed.vector, &speed.vector);
            late_DrawObjectClipEx(1);
            spread = SPREAD(work) * 2.0F;
            speed.vector.x += spread * ((rand() * RAND_SCALE) - 0.5F);
            speed.vector.y += spread * ((rand() * RAND_SCALE) - 0.5F);
            speed.vector.z += spread * ((rand() * RAND_SCALE) - 0.5F);
            water_spray2_puff.scale = SIZE(work) + 0.1F;
            water_spray2_puff.pos = work->pos;
            water_spray2_puff.speed = speed.vector;
            water_smoke_create_from(&water_spray2_puff);
            work->timer = 0;
        }
    }
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_ANG_X), "-> create pitch");
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_ANG_Y), "-> angy");
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_ANG_Z), "-> angz");
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_X), "-> Spd");
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Y), "-> Spread Spd");
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Z), "-> scale");
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        TURN_VIA(njRotateZ, work->ang.z, ang);
        DrawLine(0.0F, 0.0F, 0.0F, 0.0F, 20.0F, 0.0F);
        late_DrawObjectClipEx(1);
    }
}

void water_spray2_step(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        work->timer = 0;
        VARS(work)->countdown = 0;
        SPRAYING(work) = TRUE;
        task->step = water_spray2_run;
    }
}
