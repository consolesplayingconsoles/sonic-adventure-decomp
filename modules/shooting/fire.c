/* @unit 0C903760-0C903C80 +r04 +egflags +pool32 */
/* the sky chase's fire. FIRE_L is one flame, which shows a frame a step
 * for FIRE_FRAMES steps. pom is six such flames at points on the tornado,
 * which starts them on request. pom takes its name from its textures, pom01
 * to pom08. pom_burn's sprite takes pom_texlist, though it sets
 * fire_l_texlist as the current texlist */
#define TEXT_1 ""
#define TEXT_9 ""
#define TEXT_2 ""
#define TEXT_10 ""
#define TEXT_3 ""
#define TEXT_11 ""
#define TEXT_4 ""
#define TEXT_12 ""
#define TEXT_5 ""
#define TEXT_13 ""
#define TEXT_6 ""
#define TEXT_14 ""
#define TEXT_7 ""
#define TEXT_15 ""
#define TEXT_8 ""
#define TEXT_16 ""
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "shooting/fire.h"
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
extern NJS_MATRIX nj_unit_matrix_;
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void FUN_0c903760(struct task *task);
void *syMalloc_default_malloc(size_t size);
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

#define TEXT_1_LENGTH 8
#define TEXT_2_LENGTH 8
#define TEXT_3_LENGTH 8
#define TEXT_4_LENGTH 8
#define TEXT_5_LENGTH 8
#define TEXT_6_LENGTH 8
#define TEXT_7_LENGTH 8
#define TEXT_8_LENGTH 8
#define TEXT_9_LENGTH 5
#define TEXT_10_LENGTH 5
#define TEXT_11_LENGTH 5
#define TEXT_12_LENGTH 5
#define TEXT_13_LENGTH 5
#define TEXT_14_LENGTH 5
#define TEXT_15_LENGTH 5
#define TEXT_16_LENGTH 5
#define FIRE_FRAMES 8
#define FIRE_SIZE 0.4F
#define POM_POINTS 6
#define FIRE_FRAME(work) (((struct fire_vars *)&(work)->vars)->frame)
enum fire_mode { FIRE_INIT, FIRE_BURN, FIRE_GONE };

struct fire_vars {
    Uint8 unk_00[8];
    Sint32 frame; /* the frame fire_l_loop draws next */
};

void fire_l_init(struct task *task);
void fire_l_burn(struct task *task);
void pom_init(struct task *task);
void KumoAnimation(struct task *task);
extern NJS_TEXNAME fire_l_textures[8];
extern NJS_TEXNAME pom_textures[8];
extern NJS_TEXLIST fire_l_texlist;
extern NJS_TEXLIST pom_texlist;
extern NJS_TEXANIM fire_l_frames[8];
extern Float pom_points[6][3];

void EffectKumo(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case FIRE_INIT:
        fire_l_init(task);
        break;
    case FIRE_BURN:
        fire_l_burn(task);
        break;
    case FIRE_GONE:
        /* @hack redundant: the call in a loop of one pass, which keeps it a JSR
         * (0x0c903980) and fire_l_step's push of PR; alone, it becomes a
         * tail jump, fire_l_step runs 4 bytes short and 21 of 21 words
         * differ */
        do {
            DestroyTask(task);
        } while (0);
        break;
    }
}

/* start the flame at its parent's pos. it also turns a point 8 above the
 * parent by the parent's angles, and never reads it */
void fire_l_init(struct task *task)
{
    struct task_work *parent = task->parent->work;
    struct task_work *work = task->work;
    NJS_MATRIX matrix;
    NJS_VECTOR over;
    NJS_VECTOR turned;

    work->mode = FIRE_BURN;
    if (parent != NULL) {
        over.x = over.z = 0.0F;
        over.y = 8.0F;
        njUnitMatrix(&matrix);
        TURN_MATRIX(njRotateZ, &matrix, parent->ang.z);
        TURN_MATRIX(njRotateX, &matrix, parent->ang.x);
        TURN_MATRIX(njRotateY, &matrix, -parent->ang.y);
        njCalcVector(&matrix, &over, &turned);
        work->pos.x = parent->pos.x;
        work->pos.y = parent->pos.y;
        work->pos.z = parent->pos.z;
    }
}

/* draw the next frame each step, added to what's behind it. after
 * FIRE_FRAMES steps the flame goes */
void fire_l_burn(struct task *task)
{
    struct task_work *work = task->work;
    /* ang stays unset: no draw passes NJD_SPRITE_ANGLE */
    NJS_SPRITE sprite;

    sprite.tlist = &fire_l_texlist;
    sprite.tanim = fire_l_frames;
    sprite.sx = FIRE_SIZE;
    sprite.sy = FIRE_SIZE;
    sprite.p.x = 0.0F;
    sprite.p.y = 0.0F;
    sprite.p.z = 0.0F;
    if (TASK_TIMER(work) < FIRE_FRAMES) {
        TASK_TIMER(work)++;
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        njSetTexture_jp(&fire_l_texlist);
        njFogDisable();
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
        njDrawSprite3D(&sprite, TASK_TIMER(work) & (FIRE_FRAMES - 1),
                       NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
        late_DrawObjectClipEx(1);
    } else {
        work->timer = 15;
        work->mode = FIRE_GONE;
    }
}

void fire_l_loop(struct task_work *work)
{
    /* ang stays unset: no draw passes NJD_SPRITE_ANGLE */
    NJS_SPRITE sprite;

    sprite.tlist = &fire_l_texlist;
    sprite.tanim = fire_l_frames;
    sprite.sx = FIRE_SIZE;
    sprite.sy = FIRE_SIZE;
    sprite.p.x = 0.0F;
    sprite.p.y = 0.0F;
    sprite.p.z = 0.0F;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njSetTexture_jp(&fire_l_texlist);
    njFogDisable();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    njDrawSprite3D(&sprite, FIRE_FRAME(work),
                   NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
    late_DrawObjectClipEx(1);
    FIRE_FRAME(work)++;
    if (FIRE_FRAME(work) >= FIRE_FRAMES) {
        FIRE_FRAME(work) = 0;
    }
}

void FUN_0c903760(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case FIRE_INIT:
        pom_init(task);
        break;
    case FIRE_BURN:
        KumoAnimation(task);
        break;
    case FIRE_GONE:
        /* @hack redundant: the call in a loop of one pass, as in fire_l_step,
         * which keeps it a JSR (0x0c903bc8); alone, it becomes a tail jump
         * and 21 of 21 words differ */
        do {
            DestroyTask(task);
        } while (0);
        break;
    }
}

/* as fire_l_init does, pom_init turns a point over the parent and never
 * reads it. nothing reads the pos it sets either: pom_burn draws at the
 * parent's */
void pom_init(struct task *task)
{
    struct task_work *parent = task->parent->work;
    struct task_work *work = task->work;
    NJS_MATRIX matrix;
    NJS_VECTOR over;
    NJS_VECTOR turned;

    work->mode = FIRE_BURN;
    if (parent != NULL) {
        over.x = over.z = 0.0F;
        over.y = 8.0F;
        njUnitMatrix(&matrix);
        TURN_MATRIX(njRotateZ, &matrix, parent->ang.z);
        TURN_MATRIX(njRotateX, &matrix, parent->ang.x);
        TURN_MATRIX(njRotateY, &matrix, -parent->ang.y);
        njCalcVector(&matrix, &over, &turned);
        work->pos.x = 10.0F;
        work->pos.y = 0.0F;
        work->pos.z = 0.0F;
        work->timer = 0;
    }
}

/* draw the next frame each step at each of the POM_POINTS, which turn as
 * the parent turns. after FIRE_FRAMES steps the flames go */
void KumoAnimation(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *parent = task->parent->work;
    /* ang stays unset: no draw passes NJD_SPRITE_ANGLE */
    NJS_SPRITE sprite;
    int i;

    sprite.tlist = &pom_texlist;
    sprite.tanim = fire_l_frames;
    sprite.sx = FIRE_SIZE;
    sprite.sy = FIRE_SIZE;
    sprite.p.x = 0.0F;
    sprite.p.y = 0.0F;
    sprite.p.z = 0.0F;
    if (TASK_TIMER(work) < FIRE_FRAMES) {
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_INVSRCALPHA);
        njSetTexture_jp(&fire_l_texlist);
        SetMaterial(-0.5F, 0.0F, 0.0F, 0.0F);
        njFogDisable();
        njPushMatrix(NULL);
        njTranslate(NULL, parent->pos.x, parent->pos.y, parent->pos.z);
        njRotateXYZ(NULL, parent->ang.x, parent->ang.y, parent->ang.z);
        for (i = 0; i < POM_POINTS; i++) {
            njPushMatrix(NULL);
            njTranslate(NULL, pom_points[i][0], pom_points[i][1],
                        pom_points[i][2]);
            njDrawSprite3D(&sprite, TASK_TIMER(work),
                           NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
            late_DrawObjectClipEx(1);
        }
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
        work->timer++;
    } else {
        work->mode = FIRE_GONE;
    }
}
