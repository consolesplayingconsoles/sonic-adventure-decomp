/* @unit 0CB83160-0CB83460 +egflags +pool32 */
/* an event's sparkles: particles in the sparkle pool that drift, spin and
 * shrink, then end */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/particle.h"
#include "effect/pools.h"
#include "effect/sparkle.h"
#include "shared/sparkle.h"
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

/* a sparkle's turn each step is random, up to half of this either way */
#define SPARKLE_SPIN NJM_DEG_ANG(5)

/* the frames of the pool's animation a sparkle plays each step */
#define SPARKLE_RATE 0.01F

/* the factors of a sparkle's speed each step: sideways, then up and down */
#define SPARKLE_SPREAD 1.02F
#define SPARKLE_SETTLE 0.98F

/* the share of its scale event_sparkle_create's sparkle keeps each step */
#define SPARKLE_SHRINK (59.0F / 60.0F)

/* a sparkle's size at a scale of 1 */
#define SPARKLE_SIZE 1.0F

#define SPARKLE(particle) ((struct sparkle_vars *)&(particle)->vars)
struct sparkle_vars {
    Angle spin; /* the turn each step */
    Float shrink; /* the share of its scale it keeps each step */
};
extern NJS_TEXLIST event_sparkle_texlist;
extern NJS_TEXANIM event_sparkle_frames[4];
extern struct particle_anim event_sparkle_anim;

void event_sparkle_step(struct particle *particle, struct particle_pool *pool)
{
    particle->frame = particle->time;
    if (particle->frame >= (Sint16)pool->anim->frames) {
        particle->frame = pool->anim->frames - 1;
        SpFreeTask(particle);
        return;
    }
    particle->time += SPARKLE_RATE;
    particle->speed.x *= SPARKLE_SPREAD;
    particle->speed.y *= SPARKLE_SETTLE;
    particle->speed.z *= SPARKLE_SPREAD;
    particle->pos.x += particle->speed.x;
    particle->pos.y += particle->speed.y;
    particle->pos.z += particle->speed.z;
    particle->ang += SPARKLE(particle)->spin;
    particle->scale *= SPARKLE_SHRINK;
}

void event_sparkle_create(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale)
{
    struct particle_pool *pool = sparkle_pool.pool;
    struct particle *particle = SpCreateTask(pool, event_sparkle_step);

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
        SPARKLE(particle)->spin = (SPARKLE_SPIN * (Float)rand() * RAND_SCALE) -
                                  (Angle)(SPARKLE_SPIN / 2);
    }
}

void event_sparkle_step_shrinking(struct particle *particle,
                                  struct particle_pool *pool)
{
    particle->frame = particle->time;
    if (particle->frame >= (Sint16)pool->anim->frames) {
        particle->frame = pool->anim->frames - 1;
        SpFreeTask(particle);
        return;
    }
    particle->time += SPARKLE_RATE;
    particle->speed.x *= SPARKLE_SPREAD;
    particle->speed.y *= SPARKLE_SETTLE;
    particle->speed.z *= SPARKLE_SPREAD;
    particle->pos.x += particle->speed.x;
    particle->pos.y += particle->speed.y;
    particle->pos.z += particle->speed.z;
    particle->ang += SPARKLE(particle)->spin;
    particle->scale *= SPARKLE(particle)->shrink;
}

void event_sparkle_create_shrinking(NJS_POINT3 *pos, NJS_VECTOR *speed,
                                    Float scale, Float shrink)
{
    struct particle_pool *pool = sparkle_pool.pool;
    struct particle *particle =
        SpCreateTask(pool, event_sparkle_step_shrinking);

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
        SPARKLE(particle)->spin = (SPARKLE_SPIN * (Float)rand() * RAND_SCALE) -
                                  (Angle)(SPARKLE_SPIN / 2);
        SPARKLE(particle)->shrink = shrink;
    }
}
