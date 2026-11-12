/* @unit 8C09DCE0-8C09E1E0 @data 8C15AFDC-8C15B008 +r04 +egflags +pool32 */
/* particles: sprites from a free list, stepped and drawn in pools */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/sprite.h"
#include "effect/particle.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/timer.h"
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c6409c0(Int loc, Int val, Int digit);
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
void FUN_8c09dff8(void);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
extern Bool pause_flg;
extern struct particle *particle_buffer;
extern Uint32 particle_capacity;
extern struct particle *particle_free_list;
extern Uint32 particle_free_count;
extern struct particle_pool *particle_pools;
extern int particle_pool_count;
extern int particle_drawn;
extern NJS_SPRITE particle_sprite;
extern Float particle_depth;
extern NJS_ARGB clear_material;

#define POOL_PAUSED 0x1
#define POOL_DEAD 0x2

static void particle_free_list_init(struct particle *buffer, Uint32 count)
{
    Uint32 i;

    particle_free_list = buffer;
    particle_free_count = count;
    for (i = 0; i < count - 1; i++) {
        buffer[i].next = &buffer[i + 1];
    }
    buffer[count - 1].next = NULL;
}

void particle_init(struct particle *buffer, Uint32 count)
{
    particle_buffer = buffer;
    particle_capacity = count;
    particle_free_list_init(particle_buffer, count);
    particle_pools = NULL;
    particle_pool_count = 0;
    particle_depth = 0.0F;
}

struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool))
{
    struct particle *particle;

#ifdef GCC
    /* the split frame's second picture makes no particle */
    if (frame_redrawing) {
        return NULL;
    }
#endif
    if (pool == NULL) {
        return NULL;
    }
    if (particle_free_list == NULL) {
        return NULL;
    }
    particle = particle_free_list;
    particle_free_list = particle->next;
    particle_free_count--;
    particle->next = pool->particles;
    pool->particles = particle;
    pool->count++;
    particle->step = step;
    particle->depth = particle_depth;
    return particle;
}

void SpFreeTask(struct particle *particle)
{
    particle->step = NULL;
}

struct particle_pool *particle_pool_create(struct particle_anim *anim,
                                           Uint32 size)
{
    struct particle_pool *pool;

    if (anim == NULL) {
        return NULL;
    }
    pool = CAlloc(1, size + sizeof(*pool));
    if (pool == NULL) {
        return NULL;
    }
    pool->next = particle_pools;
    particle_pools = pool;
    particle_pool_count++;
    if (size > 0) {
        pool->work = pool + 1;
    }
    pool->anim = anim;
    return pool;
}

Bool particle_pool_step(struct particle_pool *pool)
{
    if (pool->flags & POOL_DEAD) {
        return FALSE;
    }
    if (pool->flags & POOL_PAUSED) {
        return FALSE;
    }
    if (pool->step != NULL) {
        pool->step(pool);
    }
    return TRUE;
}

void SpFreeLink(struct particle_pool *pool)
{
    if (!(pool->flags & POOL_DEAD)) {
        pool->flags |= POOL_DEAD;
    }
}

/* the pool's last particle keeps its step until particle_alloc reuses it */
void particle_pool_release(struct particle_pool *pool)
{
    struct particle *particle;

    if (!(pool->flags & POOL_DEAD)) {
        pool->flags |= POOL_DEAD;
        if (pool->particles != NULL) {
            for (particle = pool->particles; particle->next != NULL;
                 particle = particle->next) {
                particle->step = NULL;
            }
            particle->next = particle_free_list;
            particle_free_list = pool->particles;
            particle_free_count += pool->count;
            pool->particles = NULL;
            pool->count = 0;
        }
    }
}

void particle_pool_pause(struct particle_pool *pool)
{
    pool->flags |= POOL_PAUSED;
}

void particle_pool_resume(struct particle_pool *pool)
{
    if (!(pool->flags & POOL_DEAD)) {
        pool->flags &= ~POOL_PAUSED;
    }
}

void particle_run(void)
{
    struct particle_pool *pool;
    struct particle_pool *next;
    struct particle_pool *prev;
    struct particle *particle;
    struct particle *after;
    struct particle *before;
    Float step_time;
    Float draw_time;

    timer_mark();
    prev = NULL;
    for (pool = particle_pools; pool != NULL; pool = next) {
        next = pool->next;
        if (pool->flags & POOL_DEAD) {
            if (pool->particles == NULL) {
                if (prev == NULL) {
                    particle_pools = next;
                } else {
                    prev->next = next;
                }
                particle_pool_count--;
                Free(pool);
                continue;
            } else {
                prev = pool;
            }
        } else {
            prev = pool;
        }
        before = NULL;
        for (particle = pool->particles; particle != NULL; particle = after) {
            after = particle->next;
            if (particle->step != NULL) {
                particle->step(particle, pool);
                before = particle;
            } else {
                if (before == NULL) {
                    pool->particles = after;
                } else {
                    before->next = after;
                }
                pool->count--;
                particle->next = particle_free_list;
                particle_free_list = particle;
                particle_free_count++;
            }
        }
    }
    step_time = timer_lap();
    timer_mark();
    if (loop_count == 0) {
        FUN_8c09dff8();
    }
    draw_time = timer_lap();
    if (debug_page) {
        njPrintC(((30) << 16 | (10)), "SPR TASK");
        njPrintC(((30) << 16 | (11)), "MAX:");
        FUN_8c6409c0(((35) << 16 | (11)), particle_capacity, 4);
        njPrintC(((30) << 16 | (12)), "NUM:");
        FUN_8c6409c0(((35) << 16 | (12)), particle_drawn, 4);
        njPrintC(((30) << 16 | (13)), "EXEC:");
        FUN_8c6409c0(((35) << 16 | (13)), (int)step_time, 4);
        njPrintC(((30) << 16 | (14)), "DRAW:");
        FUN_8c6409c0(((35) << 16 | (14)), (int)draw_time, 4);
    }
}

void FUN_8c09dff8(void)
{
    struct particle_pool *pool;
    struct particle *particle;
    struct particle_anim *anim;
    NJS_SPRITE *sprite;
    int count;

    count = 0;
    njFogDisable();
    for (pool = particle_pools; pool != NULL; pool = pool->next) {
        anim = pool->anim;
        /* @hack spelling: the particles read before the blend (MOV.L
         * @(4,R12),R14 at 0x8c0a3b86), which keeps the count's 0 in R9 and
         * njColorBlendingMode's address in R10 (0x8c0a3b72, 0x8c0a3b76); read
         * after it, SHC also hoists sprite_set_depth's address and 44 of 86
         * words differ */
        particle = pool->particles;
        /* @hack spelling: the sprite through a pointer, whose address loads
         * into R13 after the loop's test (0x8c0a3b82); by name, it loads
         * before, and 12 of 86 words differ */
        sprite = &particle_sprite;
        sprite->tlist = anim->tlist;
        sprite->tanim = anim->tanim;
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, anim->src_blend);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, anim->dst_blend);
        for (; particle != NULL; particle = particle->next) {
            if (particle->step != NULL) {
                njSetConstantMaterial(&particle->color);
                sprite->p = particle->pos;
                sprite->sx = sprite->sy = particle->scale;
                sprite->ang = particle->ang;
                sprite_set_depth(particle->depth);
                sprite_draw_3d(sprite, particle->frame,
                               NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR |
                                   NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
                count++;
            }
        }
    }
    njSetConstantMaterial(&clear_material);
    njFogEnable();
    particle_drawn = count;
}

void particle_free_all(void)
{
    struct particle_pool *pool;
    struct particle_pool *next;

    particle_free_list_init(particle_buffer, particle_capacity);
    for (pool = particle_pools; pool != NULL; pool = next) {
        next = pool->next;
        Free(pool);
    }
    particle_pools = NULL;
    particle_pool_count = 0;
}

void particle_release_all(void)
{
    struct particle_pool *pool;
    struct particle *particle;

    for (pool = particle_pools; pool != NULL; pool = pool->next) {
        if (pool->particles != NULL) {
            for (particle = pool->particles; particle->next != NULL;
                 particle = particle->next) {
                particle->step = NULL;
            }
            particle->next = particle_free_list;
            particle_free_list = pool->particles;
            particle_free_count += pool->count;
            pool->particles = NULL;
            pool->count = 0;
        }
    }
}

void particle_set_depth(Float depth)
{
    particle_depth = depth;
}
