/* @unit 0C915B40-0C915E00 +egflags +pool32 */
/* Casinopolis water smoke particles, with a pool of their own */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/dust.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "stg09/water_smoke.h"
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
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void FUN_0c915c54(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale);
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

/* watersmoke01 to watersmoke08 */
#define WATER_SMOKE_FRAMES 8
#define WATER_SMOKE_TURN 48
#define SMOKE(particle) ((struct water_smoke_vars *)&(particle)->vars)
extern NJS_TEXLIST water_smoke_texlist;

/* the turn each step. a puff with an odd angle turns one way, and one with
 * an even angle the other. the turn is even, so each puff keeps its way */

struct water_smoke_vars {
    struct dust_params *params; /* what the puff moves by, read each step */
    /* the alpha added each step as it fades in, and taken as it fades out */
    Float fade;
};
extern NJS_TEXANIM water_smoke_frames[8];
extern struct particle_anim water_smoke_anim;
extern struct dust_params water_smoke_defaults;
extern struct particle_pool_spec water_smoke_pool;

void water_smoke_step(struct particle *particle, struct particle_pool *pool)
{
    struct dust_params *params = SMOKE(particle)->params;
    Float drag;

    particle->frame = particle->time;
    if (particle->frame >= WATER_SMOKE_FRAMES) {
        particle->color.a -= SMOKE(particle)->fade;
        if (particle->color.a < 0.0F) {
            particle->color.a = 0.0F;
        }
        particle->frame = WATER_SMOKE_FRAMES - 1;
        if (particle->color.a < 0.05F) {
            particle->frame = WATER_SMOKE_FRAMES - 1;
            SpFreeTask(particle);
            return;
        }
    } else if (particle->color.a < params->color.a) {
        particle->color.a += SMOKE(particle)->fade;
        if (particle->color.a > params->color.a) {
            particle->color.a = params->color.a;
        }
    } else {
        particle->scale += params->growth;
        particle->time += params->rate;
    }
    drag = params->drag;
    particle->speed.x += -particle->speed.x * drag;
    particle->speed.y += (-particle->speed.y * drag) + params->lift;
    particle->speed.z += -particle->speed.z * drag;
    particle->pos.x += particle->speed.x;
    particle->pos.y += particle->speed.y;
    particle->pos.z += particle->speed.z;
    if (particle->ang & 1) {
        particle->ang += WATER_SMOKE_TURN;
    } else {
        particle->ang -= WATER_SMOKE_TURN;
    }
}

void FUN_0c915c54(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale)
{
    struct particle_pool *pool = water_smoke_pool.pool;
    struct particle *particle = SpCreateTask(pool, water_smoke_step);

    if (particle) {
        particle->pos = *pos;
        particle->speed = *speed;
        particle->scale = scale;
        particle->time = rand() * (2.0F * RAND_SCALE);
        particle->ang = NJM_DEG_ANG(45) - (int)(rand() * 0.125F);
        particle->color.a = 1.0F;
        particle->color.r = 1.0F;
        particle->color.g = 1.0F;
        particle->color.b = 1.0F;
        SMOKE(particle)->params = &water_smoke_defaults;
        SMOKE(particle)->fade = 0.02F;
    }
}

void water_smoke_create_from(struct dust_params *params)
{
    struct particle_pool *pool = water_smoke_pool.pool;
    struct particle *particle = SpCreateTask(pool, water_smoke_step);

    if (particle) {
        particle->pos = params->pos;
        particle->speed = params->speed;
        particle->scale = params->scale;
        particle->time = rand() * (2.0F * RAND_SCALE);
        particle->ang = NJM_DEG_ANG(45) - (int)(rand() * 0.125F);
        particle->color = params->color;
        particle->color.a = 0.05F;
        SMOKE(particle)->params = params;
        SMOKE(particle)->fade = 0.05F;
    }
}
