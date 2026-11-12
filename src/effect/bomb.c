/* @unit 8C0445A0-8C044680 +spflags +onepool +pool32 */
/* bombs: a puff that plays bomb01 to 16 once */
#include <ninja.h>
#include <sg_xpt.h>

#include "effect/bomb.h"
#include "effect/dust.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
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
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);

/* a puff's size at a scale of 1 */
#define BOMB_SIZE 0.5F
/* bomb01 to bomb16, a frame each */
#define BOMB_FRAMES 16

#define BOMB(particle) ((struct bomb_vars *)&(particle)->vars)
struct bomb_vars {
    struct dust_params *params;
};
extern NJS_TEXLIST bomb_texlist;
extern NJS_TEXANIM bomb_frames[16];
extern struct particle_anim bomb_anim;
extern struct particle_pool_spec bomb_pool;
extern struct dust_params bomb_defaults;

/* a puff's step. it plays its frames at the params' rate, but its last at
 * twice the rate, and ends after it */
static void bomb_step(struct particle *particle, struct particle_pool *pool)
{
    struct dust_params *params = BOMB(particle)->params;

    particle->frame = particle->time;
    if (particle->frame >= (Sint16)pool->anim->frames) {
        particle->frame = pool->anim->frames - 1;
        SpFreeTask(particle);
        return;
    }
    if (particle->time < BOMB_FRAMES - 1) {
        particle->time += params->rate;
    } else {
        particle->time += params->rate * 2.0F;
    }
}

void CreateBomb(NJS_POINT3 *pos, Float scale)
{
    struct particle_pool *pool = bomb_pool.pool;
    struct particle *particle = SpCreateTask(pool, bomb_step);

    if (particle != NULL) {
        particle->pos = *pos;
        particle->scale = scale * BOMB_SIZE;
        particle->time = 0.0F;
        particle->ang = 0;
        particle->color = bomb_defaults.color;
        BOMB(particle)->params = &bomb_defaults;
    }
}
