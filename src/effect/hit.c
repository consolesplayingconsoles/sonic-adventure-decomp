/* @unit 8C09E460-8C09E6A0 +spflags +pool32 +synth16 +hoist=1,0 */
/* hits: flashes that drift and grow, and lightning that plays its frames
 * once, from two pools */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/dust.h"
#include "effect/hit.h"
#include "effect/particle.h"
#include "effect/pools.h"
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
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void FUN_8c09e552(struct dust_params *params);
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
extern NJS_TEXLIST hit_texlist;
extern NJS_TEXANIM hit_frames[8];
extern struct particle_anim hit_anim;
extern struct dust_params hit_defaults;
extern struct particle_pool_spec hit_pool;
extern NJS_TEXLIST lightning_texlist;
extern NJS_TEXANIM lightning_frames[8];
extern struct particle_anim lightning_anim;
extern struct particle_pool_spec lightning_pool;

/* the frames each plays, and lightning's size at a size of 1 */
#define HIT_FRAMES 8
#define LIGHTNING_FRAMES 8
#define LIGHTNING_SIZE 0.15F

/* EFF_REGULAR's hit_l01 to 08 */

static void hit_step(struct particle *particle, struct particle_pool *pool)
{
    struct dust_params *params = DUST(particle)->params;
    Float *walk;
    char *position;
    Float x;
    Float y;
    Float z;
    Float px;
    Float py;
    Float pz;

    particle->frame = particle->time;
    if (particle->frame >= HIT_FRAMES) {
        particle->frame = HIT_FRAMES - 1;
        SpFreeTask(particle);
        return;
    }
    particle->time += params->rate;
    /* @hack spelling: speed out and back through a Float cursor stepped
     * across its members, which loads with @R5+ and stores with @-R5
     * (0x8c0a405e, 0x8c0a406e); as particle->speed.x, .y and .z, the function
     * runs 8 bytes long and 41 of 61 words differ */
    walk = &particle->speed.x;
    x = *walk++;
    y = *walk++;
    z = *walk++;
    x *= 1.0F - params->drag;
    y *= 1.0F - params->drag;
    z *= 1.0F - params->drag;
    y += params->lift;
    *--walk = z;
    *--walk = y;
    *--walk = x;
    /* @hack spelling: pos out and back through a byte cursor, the same way;
     * through the members, SHC indexes them through R0 and 28 of 61 words
     * differ */
    position = (char *)&particle->pos;
    px = *(Float *)position;
    position += sizeof(Float);
    py = *(Float *)position;
    position += sizeof(Float);
    pz = *(Float *)position;
    position += sizeof(Float);
    px += x;
    py += y;
    pz += z;
    position -= sizeof(Float);
    *(Float *)position = pz;
    position -= sizeof(Float);
    *(Float *)position = py;
    position -= sizeof(Float);
    *(Float *)position = px;
    particle->scale += params->growth;
}

void hit_create(NJS_POINT3 *pos, Float scale)
{
    char *walk;
    Float x;
    Float y;
    Float z;
    struct particle_pool *pool = hit_pool.pool;
    struct particle *particle = SpCreateTask(pool, hit_step);
    if (particle != ((void *)0)) {
        x = y = z = 0.0F;
        walk = (char *)&particle->pos + sizeof(NJS_POINT3);
        walk -= sizeof(Float);
        *(Float *)walk = z;
        walk -= sizeof(Float);
        *(Float *)walk = y;
        walk -= sizeof(Float);
        *(Float *)walk = x;
        particle->scale = scale;
        particle->time = rand() * RAND_SCALE * 4.0F;
        particle->ang =
            NJM_DEG_ANG(45) - (Angle)(rand() * RAND_SCALE * NJM_DEG_ANG(22.5));
        particle->color.a = 1.0F;
        particle->color.r = 1.0F;
        particle->color.g = 1.0F;
        particle->color.b = 1.0F;
        DUST(particle)->params = &hit_defaults;
    }
}

void FUN_8c09e552(struct dust_params *params)
{
    struct particle_pool *pool = hit_pool.pool;
    struct particle *particle = SpCreateTask(pool, hit_step);

    if (particle != NULL) {
        particle->pos = params->pos;
        particle->speed = params->speed;
        particle->scale = params->scale;
        particle->time = 0.0F;
        particle->ang =
            NJM_DEG_ANG(45) - (Angle)(rand() * RAND_SCALE * NJM_DEG_ANG(22.5));
        particle->color = params->color;
        DUST(particle)->params = params;
    }
}

static void lightning_step(struct particle *particle,
                           struct particle_pool *pool)
{
    particle->frame = particle->time;
    if (particle->frame >= LIGHTNING_FRAMES) {
        particle->frame = LIGHTNING_FRAMES - 1;
        SpFreeTask(particle);
        return;
    }
    particle->time += 1.0F;
}

void lightning_create(NJS_POINT3 *pos, Float size)
{
    struct particle_pool *pool = lightning_pool.pool;
    struct particle *particle = SpCreateTask(pool, lightning_step);

    if (particle != NULL) {
        particle->pos = *pos;
        particle->scale = size * LIGHTNING_SIZE;
        particle->time = 0.0F;
        particle->ang = 0;
        particle->color.a = 1.0F;
        particle->color.r = 1.0F;
        particle->color.g = 1.0F;
        particle->color.b = 1.0F;
    }
}
