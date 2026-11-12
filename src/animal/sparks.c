/* @unit 8C017B20-8C018120 +egflags +pool32 */
/* the sparks of an animal a player frees, and the flash as its barrier goes */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "animal/sparks.h"
#include "effect/hit.h" /* NOLINT(misc-include-cleaner) */
#include "effect/lens.h" /* NOLINT(misc-include-cleaner) */
#include "object/tikal_light.h" /* NOLINT(misc-include-cleaner) */
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
void *syMalloc_default_malloc(size_t size);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
struct task *TikalMake(struct task *parent, struct task **holder,
                       NJS_POINT3 *origin);
void TikalSetParameter(struct task *light, Float scale, Float alpha);
void TikalSetIllusion(struct task *light);
void TikalGotoTarget(NJS_POINT3 *pos, NJS_POINT3 *to, Float distance);
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

/* a burst's sparks. the first SPARK_SLOW_COUNT are slow, and the rest fast */
#define SPARK_COUNT 14
#define SPARK_SLOW_COUNT 7

/* the slow and the fast sparks' speeds, and the steps a fast spark waits
 * before it moves and shows */
#define SLOW_SPEED 1.5F
#define FAST_SPEED 3.0F
#define FAST_DELAY 10

/* what a spark's fade gains each step after its delay. the fade reaches 1,
 * which ends the spark, on the 34th step after the delay */
#define SPARK_FADE_STEP (1.8F / 60.0F)

/* the flash sprite's last frame */
#define FLASH_LAST 3

#define SPARK(work) ((struct spark_vars *)&(work)->vars)
#define FLASH(work) ((struct flash_vars *)&(work)->vars)
enum spark_sprite { SPARK_SLOW, SPARK_FAST };

/* the flash's work->mode. FLASH_FIRST shows frame 0 until the flash's fade
 * passes 0.5. FLASH_PLAY shows the next frame each step up to FLASH_LAST,
 * holds that frame, and ends the flash when the fade reaches 1 */
enum flash_mode { FLASH_FIRST, FLASH_PLAY };

/* a spark's work->vars. its spark_color is work->mode, and its velocity
 * work->scl */
struct spark_vars {
    Float fade; /* from 0, and gone at 1 */
    Sint16 sprite; /* a spark_sprite */
    Sint16 delay; /* steps before it moves and shows */
};

/* the flash's work->vars. its spark_color is work->submode */
struct flash_vars {
    Float fade; /* from 0, and gone at 1 */
    Sint16 frame;
    Sint16 timer; /* steps it has run, which nothing reads */
};

void animal_spark_step(struct task *task);
void dispParticle_new(struct task *task);
void dispWa_new(struct task *task);
extern int loop_count;
void FUN_8c017ea2(struct task *task);
NJS_ARGB getARGB(int color, Float alpha, Float level);
extern const NJS_TEXANIM animal_slow_texanims[1];
extern const NJS_SPRITE animal_slow_sprite;
extern const NJS_TEXANIM animal_fast_texanims[1];
extern const NJS_SPRITE animal_fast_sprite;
extern const NJS_TEXANIM animal_flash_texanims[4];
extern const NJS_SPRITE animal_flash_sprite;

/* the slow sparks fly off in any direction, each after a random 0 to 4
 * steps. the fast ones fly off after FAST_DELAY steps, each at a random
 * heading. they share one random pitch, up to 30 degrees above or below
 * level */
void FlickyEff_Particle_New(NJS_POINT3 *pos, int color, int grounded)
{
    struct task *task;
    struct task_work *work;
    Angle fast_pitch;
    Angle pitch;
    Angle yaw;
    Float across;
    int i;

    fast_pitch = RANDOM(-NJM_DEG_ANG(30), NJM_DEG_ANG(30));
    for (i = 0; i < SPARK_COUNT; i++) {
        /* @hack spelling: task assigned in the test, which keeps pos on the
         * stack (MOV.L R4,@R15 at 0x8c01899c); as a statement of its own,
         * pos takes R8, the function runs 6 bytes short and 123 of 175
         * words differ */
        if ((task = CreateElementalTask(TASK_WORK, 6, animal_spark_step)) !=
            NULL) {
            work = task->work;
            pitch = RANDOM_ANGLE();
            yaw = RANDOM_ANGLE();
            SPARK(work)->fade = 0.0F;
            /* @hack redundant: the copy in a loop of one pass, which keeps
             * the loop round it rolled, with one call of task_create
             * (0x8c0189ce); as the copy alone, SHC unrolls that loop and
             * sparks.c's code runs 1024 bytes long, count unmeasured */
            do {
                VECTOR_COPY(&work->pos, pos);
            } while (0);
            work->mode = color;
            if (i < SPARK_SLOW_COUNT) {
                SPARK(work)->delay = RANDOM(0.0F, 5.0F);
                SPARK(work)->sprite = SPARK_SLOW;
                work->scl.y = njSin(pitch) * SLOW_SPEED;
                across = njCos(pitch) * SLOW_SPEED;
                work->scl.x = across * njCos(yaw);
                work->scl.z = -(across * njSin(yaw));
            } else {
                SPARK(work)->delay = FAST_DELAY;
                SPARK(work)->sprite = SPARK_FAST;
                work->scl.y = njSin(fast_pitch) * FAST_SPEED;
                across = njCos(fast_pitch) * FAST_SPEED;
                work->scl.x = across * njCos(yaw);
                work->scl.z = -(across * njSin(yaw));
            }
            if (grounded) {
                if (work->scl.y < 0.0F) {
                    work->scl.y = -work->scl.y;
                }
            }
            task->draw = dispParticle_new;
        }
    }
}

void FlickyEff_Wa_New(NJS_POINT3 *pos, int color)
{
    struct task *task;
    struct task_work *work;
    if ((task = CreateElementalTask(0x2, 6, FUN_8c017ea2)) != ((void *)0)) {
        work = task->work;
        VECTOR_COPY(&work->pos, pos);
        FLASH(work)->frame = 0;
        work->mode = FLASH_FIRST;
        work->submode = color;
        ((struct flash_vars *)&(work)->vars)->fade = 0.0F;
        ((struct flash_vars *)&(work)->vars)->timer = 0;
        task->draw = dispWa_new;
    }
}
void animal_spark_step(struct task *task)
{
    struct task_work *work;
    NJS_VECTOR drag;
    work = task->work;
    if (((struct spark_vars *)&(work)->vars)->delay-- > 0) {
        return;
    }
    if ((((struct spark_vars *)&(work)->vars)->fade += (1.8F / 60.0F)) >=
        1.0F) {
        FreeTask(task);
        return;
    }
    work->scl.y -= 0.02F;
    ((&drag)->x = (&work->scl)->x * (0.2F),
     (&drag)->y = (&work->scl)->y * (0.2F),
     (&drag)->z = (&work->scl)->z * (0.2F));
    ((&work->scl)->x -= (&drag)->x, (&work->scl)->y -= (&drag)->y,
     (&work->scl)->z -= (&drag)->z);
    ((&work->pos)->x += (&work->scl)->x, (&work->pos)->y += (&work->scl)->y,
     (&work->pos)->z += (&work->scl)->z);
    dispParticle_new(task);
}
void dispParticle_new(struct task *task)
{
    struct task_work *work;
    NJS_ARGB color;
    Float level;
    NJS_SPRITE *sprite;
    work = task->work;
    if (loop_count != 0) {
        return;
    }
    level = 1.0F - (((struct spark_vars *)&(work)->vars)->fade * 1.5F);
    if (level < 0.0F) {
        level = 0.0F;
    }
    color = getARGB(work->mode,
                    1.0F - ((struct spark_vars *)&(work)->vars)->fade, level);
    switch (((struct spark_vars *)&(work)->vars)->sprite) {
    case SPARK_SLOW:
        sprite = (NJS_SPRITE *)&animal_slow_sprite;
        break;
    case SPARK_FAST:
    default:
        sprite = (NJS_SPRITE *)&animal_fast_sprite;
        break;
    }
    njSetConstantMaterial(&color);
    njColorBlendingMode_jp(0, 1);
    njColorBlendingMode_jp(1, 10);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    njDrawSprite3D(sprite, 0, 0x20 | 0x10 | 0x02);
    late_DrawObjectClipEx(1);
    color.a = color.r = color.g = color.b = 1.0F;
    njSetConstantMaterial(&color);
    njColorBlendingMode_jp(0, 1);
    njColorBlendingMode_jp(1, 1);
}
void FUN_8c017ea2(struct task *task)
{
    struct task_work *work;
    work = task->work;
    ((struct flash_vars *)&(work)->vars)->timer++;
    switch (work->mode) {
    case FLASH_FIRST:
        ((struct flash_vars *)&(work)->vars)->fade += 0.02F;
        if (((struct flash_vars *)&(work)->vars)->fade > 0.5F) {
            work->mode = FLASH_PLAY;
        }
        break;
    case FLASH_PLAY:
        ((struct flash_vars *)&(work)->vars)->frame++;
        if (((struct flash_vars *)&(work)->vars)->frame > 3) {
            ((struct flash_vars *)&(work)->vars)->frame = 3;
        }
        ((struct flash_vars *)&(work)->vars)->fade += 0.015F;
        if (((struct flash_vars *)&(work)->vars)->fade >= 1.0F) {
            FreeTask(task);
            return;
        }
        break;
    }
    dispWa_new(task);
}
void dispWa_new(struct task *task)
{
    struct task_work *work;
    NJS_ARGB color;
    Float level;
    work = task->work;
    if (loop_count != 0) {
        return;
    }
    level = 1.0F - (((struct flash_vars *)&(work)->vars)->fade * 1.8F);
    if (level < -0.8F) {
        level = -0.8F;
    }
    color = getARGB(work->submode,
                    1.0F - ((struct flash_vars *)&(work)->vars)->fade, level);
    njSetConstantMaterial(&color);
    njColorBlendingMode_jp(0, 1);
    njColorBlendingMode_jp(1, 10);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    njDrawSprite3D((NJS_SPRITE *)&animal_flash_sprite,
                   ((struct flash_vars *)&(work)->vars)->frame,
                   0x20 | 0x10 | 0x02);
    late_DrawObjectClipEx(1);
    color.a = color.r = color.g = color.b = 1.0F;
    njSetConstantMaterial(&color);
    njColorBlendingMode_jp(0, 1);
    njColorBlendingMode_jp(1, 1);
}

/* the ARGB of color, a spark_color, at alpha, with level in the channels
 * the color doesn't fill. any other color gives SPARK_MINT's, which takes no
 * level */
NJS_ARGB getARGB(int color, Float alpha, Float level)
{
    NJS_ARGB argb;

    argb.a = alpha;
    switch (color) {
    case SPARK_RED:
        argb.r = 1.0F;
        argb.b = level;
        argb.g = level;
        break;
    case SPARK_GREEN:
        argb.r = level;
        argb.b = level;
        argb.g = 1.0F;
        break;
    case SPARK_BLUE:
        argb.r = level;
        argb.b = 1.0F;
        argb.g = level;
        break;
    case SPARK_WHITE:
        argb.r = 1.0F;
        argb.b = 1.0F;
        argb.g = 1.0F;
        break;
    case SPARK_YELLOW:
        argb.r = 1.0F;
        argb.b = level;
        argb.g = 1.0F;
        break;
    case SPARK_MAGENTA:
        argb.r = 1.0F;
        argb.b = 1.0F;
        argb.g = level;
        break;
    case SPARK_CYAN:
        argb.r = level;
        argb.b = 1.0F;
        argb.g = 1.0F;
        break;
    case SPARK_MINT:
    default:
        argb.r = 0.5F;
        argb.b = 0.7F;
        argb.g = 1.0F;
        break;
    }
    return argb;
}
