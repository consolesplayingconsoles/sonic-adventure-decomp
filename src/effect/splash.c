/* @unit 8C046960-8C046D80 +r04 +egflags +pool32 */
/* splashes: drops that fly up out of the water, and the ripple that spreads
 * where something meets it */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "draw/draw.h"
#include "effect/dust.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "effect/splash.h"
#include "object/models.h"
#ifdef GCC
#include "system/frame.h"
#endif
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
#include "system/texture.h"
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
void FUN_8c638d8e(NJS_OBJECT *obj);
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void FUN_8c046a08(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale);
void FUN_8c046a9c(struct dust_params *params);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
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

/* a drop's frames, and its size at a scale of 1 */
#define SPLASH_FRAMES 8
#define SPLASH_SIZE 0.17F

/* a ripple's scl.x is its size */
#define RIPPLE(work) ((struct ripple_vars *)&(work)->vars)
struct ripple_vars {
    /* the r, g and b of its constant material, from -0.5 down past -1 */
    Float fade;
    Float fade_size; /* it starts to fade past this */
    Float growth; /* added to its size each step */
};

enum ripple_mode { RIPPLE_GROW, RIPPLE_FADE, RIPPLE_END };

void ripple_init(struct task *task);
void ripple_step(struct task *task);
void ripple_draw(struct task *task);
void ripple_destroy(struct task *task);
extern NJS_TEXLIST splash_texlist;
extern NJS_TEXANIM splash_frames[8];
extern struct particle_anim splash_anim;
extern struct particle_pool_spec splash_pool;
extern struct dust_params splash_defaults;

void splash_step(struct particle *particle, struct particle_pool *pool)
{
    struct dust_params *params = DUST(particle)->params;
    Float keep;

    particle->frame = particle->time;
    if (particle->frame > SPLASH_FRAMES - 1) {
        particle->frame = SPLASH_FRAMES - 1;
        SpFreeTask(particle);
        return;
    }
    if (particle->time < 6.0F) {
        particle->time += params->rate * 1.4F;
    } else {
        particle->time += params->rate * 2.8F;
    }
    keep = 1.0F - params->drag;
    /* @hack spelling: the products and sums spelled out, which SHC works in
     * registers (FMAC at 0x8c049720); with *= and +=, it forms each speed's
     * address in R1 to read it for the sums, the function runs 6 bytes long
     * and 53 of 84 words differ */
    particle->speed.x = particle->speed.x * keep;
    particle->speed.y = (particle->speed.y * keep) + params->lift;
    particle->speed.z = particle->speed.z * keep;
    particle->pos.x = particle->pos.x + particle->speed.x;
    particle->pos.y = particle->pos.y + particle->speed.y;
    particle->pos.z = particle->pos.z + particle->speed.z;
    particle->scale += params->growth * (1.5F * SPLASH_SIZE);
}

void FUN_8c046a08(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale)
{
    struct particle_pool *pool = splash_pool.pool;
    struct particle *particle = SpCreateTask(pool, splash_step);

    if (particle != NULL) {
        particle->pos = *pos;
        particle->speed = *speed;
        particle->scale = scale * SPLASH_SIZE;
        particle->time = rand() * RAND_SCALE * 5.0F;
        particle->ang = RANDOM(100.0F, 260.0F) * ANGLE_PER_DEGREE;
        particle->color = splash_defaults.color;
        DUST(particle)->params = &splash_defaults;
    }
}

void FUN_8c046a9c(struct dust_params *params)
{
    struct particle_pool *pool = splash_pool.pool;
    struct particle *particle = SpCreateTask(pool, splash_step);

    if (particle != NULL) {
        particle->pos = params->pos;
        particle->speed = params->speed;
        particle->scale = params->scale;
        particle->time = rand() * RAND_SCALE * 5.0F;
        particle->ang = RANDOM(100.0F, 260.0F) * ANGLE_PER_DEGREE;
        particle->color = params->color;
        DUST(particle)->params = params;
    }
}

void ripple_create(NJS_POINT3 *pos, NJS_VECTOR *growth, Float size)
{
    struct task *task = CreateElementalTask(TASK_WORK, 6, ripple_init);
    struct task_work *work = task->work;

    work->pos = *pos;
    RIPPLE(work)->growth = growth->x;
    RIPPLE(work)->fade_size = growth->z;
    work->scl.x = size;
    work->scl.y = 1.0F;
    RIPPLE(work)->fade = -0.5F;
}

void ripple_init(struct task *task)
{
    struct task_work *work = task->work;

    work->mode = RIPPLE_GROW;
    task->step = ripple_step;
    task->draw = ripple_draw;
    task->destructor = ripple_destroy;
}

void ripple_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case RIPPLE_GROW: {
        Float size = work->scl.x + RIPPLE(work)->growth;

        if (size > RIPPLE(work)->fade_size) {
            work->mode = RIPPLE_FADE;
            RIPPLE(work)->fade = -0.5F;
        }
        work->scl.x = size;
        break;
    }
    case RIPPLE_FADE: {
        Float fade = RIPPLE(work)->fade;

        work->scl.x += RIPPLE(work)->growth;
        fade -= 0.02F;
        if (fade < -1.0F) {
            work->mode = RIPPLE_END;
        }
        RIPPLE(work)->fade = fade;
        break;
    }
    case RIPPLE_END:
        FreeTask(task);
        break;
    }
#ifdef GCC
    /* the second picture's pass draws the ripple by ripple_draw. step 1 of
     * a split frame draws none, so that the picture adds the ripple once */
    if (frame_split && loop_count == 1) {
        return;
    }
#endif
    ripple_draw(task);
}

void ripple_draw(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack type: the fade in a color on the stack, its alpha unset, which
     * gives the function a 20-byte frame (ADD #-20,R15 at 0x8c0499c6); as a
     * Float, it takes FR14, the frame is 4 bytes and 81 of 85 words differ */
    NJS_ARGB color;

    {
        extern int loop_count;
        if (loop_count != 0) {
            return;
        }
    }
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    color.r = color.g = color.b = RIPPLE(work)->fade;
    SaveConstantAttr();
    OnConstantAttr(0, NJD_FLAG_USE_ALPHA);
    SetMaterial(0.0F, color.r, color.g, color.b);
    njColorBlendingMode_jp(0, 8);
    njColorBlendingMode_jp(1, 10);
    njScale(((void *)0), work->scl.x, 1.0F, work->scl.x);
    FUN_8c638d8e(&ripple_object);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_BOTHSRCALPHA);
    LoadConstantAttr();
    late_DrawObjectClipEx(1);
}

void ripple_destroy(struct task *task)
{
}
