/* @unit 8C045B20-8C045E00 @data 8C1129CC-8C1129E8 +jpflags +pool32 */
/* sparkles: glints that drift and spin, and a glint that comes and goes */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/particle.h"
#include "effect/pools.h"
#include "effect/sparkle.h"
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

/* a glint's frames, and its scale at a size of 1 */
#define GLINT_FRAMES 7
#define GLINT_SIZE 0.1F

/* a sparkle's frames, and its size at a scale of 1 */
#define SPARKLE_FRAMES 4
#define SPARKLE_SIZE 1.0F

#define SPARKLE(particle) ((struct sparkle_vars *)&(particle)->vars)
#define GLINT(work) ((struct glint_vars *)&(work)->vars)
struct sparkle_vars {
    Angle spin; /* the turn each step */
};

/* a glint's scl.x is its scale, and scl.z the frame it's at */
struct glint_vars {
    Uint8 unk_00[8];
    Float rate; /* frames a step */
};

static void glint_step(struct task *task);
static void glint_draw(struct task *task);
static void glint_destroy(struct task *task);

/* the glint's textures, by frame: kiran01 up to 04 and back */
static const Sint32 glint_textures[7] = {0, 1, 2, 3, 2, 1, 0};
extern NJS_TEXLIST sparkle_texlist;
extern NJS_TEXANIM sparkle_frames[4];
extern struct particle_anim sparkle_anim;
extern struct particle_pool_spec sparkle_pool;

static void sparkle_step(struct particle *particle, struct particle_pool *pool)
{
    particle->frame = particle->time;
    if (particle->frame >= (Sint16)pool->anim->frames) {
        particle->frame = pool->anim->frames - 1;
        SpFreeTask(particle);
        return;
    }
    particle->time += 0.01F;
    particle->speed.x *= 1.02F;
    particle->speed.y *= 0.98F;
    particle->speed.z *= 1.02F;
    particle->pos.x += particle->speed.x;
    particle->pos.y += particle->speed.y;
    particle->pos.z += particle->speed.z;
    particle->ang += SPARKLE(particle)->spin;
    particle->scale *= 59.0F / 60.0F;
}

void sparkle_create(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale, Angle spin)
{
    struct particle_pool *pool = sparkle_pool.pool;
    struct particle *particle = SpCreateTask(pool, sparkle_step);

    if (particle != NULL) {
        particle->pos = *pos;
        particle->speed = *speed;
        particle->scale = scale * SPARKLE_SIZE;
        particle->time = 0.0F;
        particle->ang = rand() * RAND_SCALE * 360.0F * ANGLE_PER_DEGREE;
        particle->color.a = 1.0F;
        particle->color.r = 1.0F;
        particle->color.g = 1.0F;
        particle->color.b = 1.0F;
        SPARKLE(particle)->spin =
            (spin * (Float)rand() * RAND_SCALE) - (Angle)(spin / 2);
    }
}

void sparkle_create_glint(NJS_POINT3 *pos, Float size, Float rate)
{
    struct task *task;
    struct task_work *work;

    task = CreateElementalTask(TASK_WORK, 3, glint_step);
    work = task->work;
    task->destructor = glint_destroy;
    task->draw = glint_draw;
    work->scl.x = size * GLINT_SIZE;
    work->scl.z = 0.0F;
    GLINT(work)->rate = rate;
    work->pos = *pos;
}

static void glint_step(struct task *task)
{
    struct task_work *work = task->work;

    work->scl.z += GLINT(work)->rate;
    if ((Uint32)work->scl.z >= GLINT_FRAMES) {
        FreeTask(task);
        return;
    }
    glint_draw(task);
}

static void glint_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_SPRITE sprite;

    sprite.p = work->pos;
    sprite.sx = work->scl.x;
    sprite.sy = work->scl.x;
    sprite.ang = 0;
    sprite.tlist = &sparkle_texlist;
    sprite.tanim = sparkle_frames;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njDrawSprite3D(&sprite, glint_textures[(Uint32)work->scl.z],
                   NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
}

static void glint_destroy(struct task *task)
{
}
