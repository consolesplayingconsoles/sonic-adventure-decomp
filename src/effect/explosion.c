/* @unit 8C0454E0-8C0457C0 +jpflags +pool32 */
/* explosions: a blast's sprite, and the sparks that fly from it */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/explosion.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "effect/spark.h"
#include "sound/sound.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
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
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSpark(NJS_POINT3 *pos, NJS_VECTOR *speed, Float unused);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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

/* the blast's sound */
#define SE_EXPLOSION 25

#define VARS(work) ((struct explosion_vars *)&(work)->vars)
struct explosion_vars {
    Uint8 unk_00[8];
    /* the sparks' clock, up by 0.4 a step. the step that takes it past 7
     * throws none, and ends the explosion */
    Float time;
};

enum explosion_mode { EXPLOSION_BLAST, EXPLOSION_SPARK, EXPLOSION_END };

static void blast_step(struct particle *particle, struct particle_pool *pool);
extern NJS_TEXLIST explosion_texlist;
extern NJS_TEXANIM explosion_frames[8];
extern struct particle_anim explosion_anim;
extern struct particle_pool_spec explosion_pool;

static void FlashManagerInit(struct task_work *work)
{
    struct particle_pool *pool = explosion_pool.pool;
    struct particle *particle = SpCreateTask(pool, blast_step);

    if (particle != NULL) {
        particle->pos = work->pos;
        particle->scale = work->scl.x;
        particle->time = 0.0F;
        particle->ang = rand() * RAND_SCALE * 360.0F * ANGLE_PER_DEGREE;
        particle->color.a = 1.0F;
        particle->color.r = 1.0F;
        particle->color.g = 1.0F;
        particle->color.b = 1.0F;
    }
    work->mode = EXPLOSION_SPARK;
}

static void FlashManagerNormal(struct task_work *work)
{
    NJS_VECTOR speed;
    int i;

    VARS(work)->time += 0.4F;
    if (VARS(work)->time > 7.0F) {
        work->mode = EXPLOSION_END;
        return;
    }
    for (i = 0; i < 3; i++) {
        speed.x = -2.75F + (rand() * (1.0F / (32767 + 1)) * 5.5F);
        speed.y = -2.0F + (rand() * (1.0F / (32767 + 1)) * 5.5F);
        speed.z = -2.75F + (rand() * (1.0F / (32767 + 1)) * 5.5F);
        CreateSpark(&work->pos, &speed, 1.0F);
    }
}

static void FlashManager(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case EXPLOSION_BLAST:
        FlashManagerInit(work);
        break;
    case EXPLOSION_SPARK:
        FlashManagerNormal(work);
        break;
    case EXPLOSION_END:
        FreeTask(task);
        break;
    }
}

static void blast_step(struct particle *particle, struct particle_pool *pool)
{
    particle->frame = particle->time;
    if (particle->frame > 7) {
        particle->frame = 7;
        SpFreeTask(particle);
    } else {
        particle->time += 0.4F;
    }
}

void CreateFlash(struct task_work *work, Float scale)
{
    struct task *task;
    struct task_work *explosion;

    dsPlay_oneshot(SE_EXPLOSION, 0, 0, 0);
    task = CreateElementalTask(TASK_WORK, 6, FlashManager);
    if (task != NULL) {
        explosion = task->work;
        explosion->pos = work->pos;
        explosion->scl.x = scale;
    }
}

void CreateFlash2(Float x, Float y, Float z, Float scale)
{
    struct task *task;
    struct task_work *explosion;

    dsPlay_oneshot(SE_EXPLOSION, 0, 0, 0);
    task = CreateElementalTask(TASK_WORK, 6, FlashManager);
    if (task != NULL) {
        explosion = task->work;
        explosion->pos.x = x;
        explosion->pos.y = y;
        explosion->pos.z = z;
        explosion->scl.x = scale;
    }
}
