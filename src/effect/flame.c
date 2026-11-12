/* @unit 8C0452C0-8C0454E0 +spflags +onepool +pool32 */
/* flames: sprites that play flame01 to 10 once as they rise */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/dust.h"
#include "effect/flame.h"
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
void FUN_8c04536e(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale);
void FUN_8c045402(struct dust_params *params);
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

/* a flame's frames, and its size at a scale of 1 */
#define FLAME_FRAMES 10
#define FLAME_SIZE 0.15F

#define FLAME(particle) ((struct flame_vars *)&(particle)->vars)
struct flame_vars {
    struct dust_params *params;
};
extern NJS_TEXLIST flame_texlist;
extern NJS_TEXANIM flame_frames[10];
extern struct particle_anim flame_anim;
extern struct particle_pool_spec flame_pool;
extern struct dust_params flame_defaults;

static void flame_step(struct particle *particle, struct particle_pool *pool)
{
    struct dust_params *params = FLAME(particle)->params;
    Float drag;

    particle->frame = particle->time;
    if (particle->frame > FLAME_FRAMES - 1) {
        particle->frame = FLAME_FRAMES - 1;
        SpFreeTask(particle);
        return;
    }
    particle->time += params->rate;
    drag = params->drag;
    /* @hack spelling: the drag's product negated and added, FNEG and FADD at
     * 0x8c04807c and 0x8c04807e; with -=, SHC subtracts, the function runs 6
     * bytes short and 65 of 87 words differ */
    particle->speed.x += -particle->speed.x * drag;
    particle->speed.y += (-particle->speed.y * drag) + params->lift;
    particle->speed.z += -particle->speed.z * drag;
    particle->pos.x += particle->speed.x;
    particle->pos.y += particle->speed.y;
    particle->pos.z += particle->speed.z;
    particle->scale += params->growth * FLAME_SIZE;
}

void FUN_8c04536e(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale)
{
    struct particle_pool *pool = flame_pool.pool;
    struct particle *particle = SpCreateTask(pool, flame_step);

    if (particle != NULL) {
        particle->pos = *pos;
        particle->speed = *speed;
        particle->scale = scale * FLAME_SIZE;
        particle->time = rand() * RAND_SCALE * 5.0F;
        particle->ang = RANDOM(100.0F, 260.0F) * ANGLE_PER_DEGREE;
        particle->color = flame_defaults.color;
        FLAME(particle)->params = &flame_defaults;
    }
}

void FUN_8c045402(struct dust_params *params)
{
    struct particle_pool *pool = flame_pool.pool;
    struct particle *particle = SpCreateTask(pool, flame_step);

    if (particle != NULL) {
        particle->pos = params->pos;
        particle->speed = params->speed;
        particle->scale = params->scale * FLAME_SIZE;
        particle->time = rand() * RAND_SCALE * 5.0F;
        particle->ang = RANDOM(100.0F, 260.0F) * ANGLE_PER_DEGREE;
        particle->color = params->color;
        FLAME(particle)->params = params;
    }
}
