/* @unit 0C90F2E0-0C90F420 +egflags +pool32 */
/* smoke puff particles shared by Final Egg and Hot Shelter objects */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/dust.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "effect/snow.h"
#include "stg10/puff.h"
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
void FUN_0c90f360(struct dust_params *params);
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

/* the frames of a puff's animation. the puff ends once its time passes the
 * last */
#define PUFF_FRAMES 8

void final_puff_step(struct particle *particle, struct particle_pool *pool);
extern NJS_TEXANIM final_puff_frames[8];
extern struct particle_anim final_puff_anim;
extern struct dust_params final_puff_params;
extern struct particle_pool_spec final_puff_pool;

void final_puff_step(struct particle *particle, struct particle_pool *pool)
{
    struct dust_params *params = DUST(particle)->params;
    Float kept;
    Float *walk;
    Float x;
    Float y;
    Float z;
    Float px;
    Float py;
    Float pz;

    particle->frame = particle->time;
    if (particle->frame >= PUFF_FRAMES) {
        particle->frame = PUFF_FRAMES - 1;
        SpFreeTask(particle);
        return;
    }
    particle->time += params->rate;
    /* @hack spelling: the speed out and back through a Float cursor, which
     * loads with @R5+ and stores with @-R5 (0x0c90fa5e, 0x0c90fa6e). through
     * the fields, SHC indexes them through R0, the function is 8 bytes longer,
     * and 44 of 64 words differ */
    walk = &particle->speed.x;
    kept = 1.0F - params->drag;
    x = *walk++;
    y = *walk++;
    x *= kept;
    y *= kept;
    z = *walk++;
    z *= kept;
    y += params->lift;
    *--walk = z;
    *--walk = y;
    *--walk = x;
    /* @hack spelling: the position out and back through the same cursor, which
     * loads with @R5+ and stores with @-R5 (0x0c90fa78, 0x0c90fa90). through
     * the fields, the function is 8 bytes longer and 32 of 64 words differ */
    /* @hack spelling: each step of walk a statement of its own, which loads the
     * x into FR7 (FMOV.S @R5+,FR7 at 0x0c90fa78). with *walk++ and *--walk,
     * FR5 and FR7 trade, and 10 of 64 words differ */
    walk = &particle->pos.x;
    px = *walk;
    walk++;
    py = *walk;
    walk++;
    pz = *walk;
    walk++;
    px += x;
    py += y;
    pz += z;
    walk--;
    *walk = pz;
    walk--;
    *walk = py;
    walk--;
    *walk = px;
    particle->scale += params->growth * DUST_SIZE;
}

/* a puff starts at a random time in its first four frames, turned by 22.5
 * to 45 degrees */
void FUN_0c90f360(struct dust_params *params)
{
    struct particle_pool *pool = final_puff_pool.pool;
    struct particle *particle = SpCreateTask(pool, final_puff_step);

    if (particle != NULL) {
        particle->pos = params->pos;
        particle->speed = params->speed;
        particle->scale = params->scale * DUST_SIZE;
        particle->time = rand() * RAND_SCALE * 4.0F;
        particle->ang =
            NJM_DEG_ANG(45) - (int)(rand() * RAND_SCALE * NJM_DEG_ANG(22.5));
        particle->color = params->color;
        DUST(particle)->params = params;
    }
}
