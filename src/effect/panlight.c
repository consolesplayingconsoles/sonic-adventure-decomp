/* @unit 8C0459E0-8C045B20 +spflags +onepool +pool32 */
/* panlights: glows that move as dust does, fading and shrinking as they go */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/dust.h"
#include "effect/panlight.h"
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
extern NJS_TEXLIST panlight_texlist;
extern NJS_TEXANIM panlight_frame;
extern struct particle_anim panlight_anim;
extern struct particle_pool_spec panlight_pool;

/* a glow's size at a scale of 1 */
#define PANLIGHT_SIZE 0.15F

/* EFF_REGULAR's panlight */

static void panlight_step(struct particle *particle, struct particle_pool *pool)
{
    struct dust_params *params = DUST(particle)->params;
    Float keep;

    particle->color.a -= params->rate * 0.1F;
    if (particle->color.a < 0.0F) {
        SpFreeTask(particle);
        return;
    }
    keep = 1.0F - params->drag;
    /* @hack spelling: the products and sums spelled out, which SHC works in
     * registers (FNEG at 0x8c04878e); with *= and +=, it takes each field's
     * address into a register first, the function runs 6 bytes long and 47
     * of 72 words differ */
    particle->speed.x = particle->speed.x * keep;
    particle->speed.y = (particle->speed.y * keep) + params->lift;
    particle->speed.z = particle->speed.z * keep;
    particle->pos.x = particle->pos.x + particle->speed.x;
    particle->pos.y = particle->pos.y + particle->speed.y;
    particle->pos.z = particle->pos.z + particle->speed.z;
    particle->scale = particle->scale - (particle->scale * params->growth *
                                         (0.1F * PANLIGHT_SIZE));
}

void panlight_create(struct dust_params *params)
{
    struct particle_pool *pool = panlight_pool.pool;
    struct particle *particle = SpCreateTask(pool, panlight_step);

    if (particle != NULL) {
        particle->pos = params->pos;
        particle->speed = params->speed;
        particle->scale = params->scale * PANLIGHT_SIZE;
        particle->frame = 0;
        particle->time = 0.0F;
        particle->ang = RANDOM_ANGLE();
        particle->color = params->color;
        DUST(particle)->params = params;
    }
}
