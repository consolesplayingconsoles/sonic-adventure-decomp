/* @unit 8C04FEA0-8C0502A0 +jpflags +pool32 */
/* sprite pools: many sprites that move and play alike, on one task */
#include <ninja.h>
#include <sg_xpt.h>

#include "effect/sprite.h"
#include "effect/sprite_pool.h"
#include "system/task.h"
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
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
void *syMalloc_default_malloc(size_t size);
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

void sprite_body_init(struct sprite_body *body, NJS_POINT3 *pos,
                      NJS_VECTOR *speed)
{
    if (pos != NULL) {
        VECTOR_COPY(&body->pos, pos);
    } else {
        body->pos.x = body->pos.y = body->pos.z = 0.0F;
    }
    if (speed != NULL) {
        VECTOR_COPY(&body->speed, speed);
    } else {
        body->speed.x = body->speed.y = body->speed.z = 0.0F;
    }
    body->scale = 1.0F;
    body->depth = 0.0F;
}

void sprite_body_move(struct sprite_body *body, struct sprite_motion *motion)
{
    VECTOR_SUM(&body->pos, &body->pos, &body->speed);
    body->speed.x -= body->speed.x * motion->drag;
    body->speed.y -= (body->speed.y * motion->drag) - motion->gravity;
    body->speed.z -= body->speed.z * motion->drag;
}

void sprite_pool_add(struct task *task, NJS_POINT3 *pos, NJS_VECTOR *speed,
                     Float age, Float depth)
{
    struct sprite_pool *pool;
    struct sprite_slot *slot;

    pool = task->extra;
    if (pool->count >= pool->capacity) {
        return;
    }
    pool->live[pool->count] = pool->free[pool->count];
    slot = &pool->slots[pool->live[pool->count]];
    VECTOR_COPY(&slot->body.pos, pos);
    VECTOR_COPY(&slot->body.speed, speed);
    slot->body.scale = 1.0F;
    slot->body.depth = depth;
    sprite_play_init(&slot->play);
    sprite_play_seek(&slot->play, pool->frames, age);
    pool->count++;
}

/* free the live sprite at index, and move the last live one into its place */
static void sprite_pool_remove(struct task *task, int index)
{
    struct sprite_pool *pool;

    pool = task->extra;
    if (pool->count > 0) {
        pool->count--;
        pool->free[pool->count] = pool->live[index];
        pool->live[index] = pool->live[pool->count];
    }
}

static void sprite_pool_draw(struct task *task)
{
    struct sprite_pool *pool;
    struct sprite_slot *slot;
    int i;

    pool = task->extra;
    for (i = 0; i < pool->count; i++) {
        slot = &pool->slots[pool->live[i]];
        sprite_render(&slot->body.pos, &slot->body, &slot->play, pool->frames);
    }
}

static Bool sprite_slot_step(struct sprite_slot *slot,
                             struct sprite_motion *motion,
                             const struct sprite_frame *frames)
{
    sprite_body_move(&slot->body, motion);
    if (sprite_play_step(&slot->play, frames) == SPRITE_END) {
        return FALSE;
    }
    return TRUE;
}

static void sprite_pool_step(struct task *task)
{
    struct sprite_pool *pool;
    struct sprite_slot *slot;
    int i;

    pool = task->extra;
    for (i = 0; i < pool->count; i++) {
        slot = &pool->slots[pool->live[i]];
        if (!sprite_slot_step(slot, &pool->motion, pool->frames)) {
            sprite_pool_remove(task, i--);
        }
    }
    sprite_pool_draw(task);
}

static void sprite_pool_step_own(struct task *task)
{
    struct sprite_pool *pool;
    struct sprite_slot *slot;
    int i;

    pool = task->extra;
    for (i = 0; i < pool->count; i++) {
        slot = &pool->slots[pool->live[i]];
        if (!pool->step(slot, &pool->motion, pool->frames)) {
            sprite_pool_remove(task, i--);
        }
    }
    sprite_pool_draw(task);
}

static void sprite_pool_destroy(struct task *task)
{
    struct sprite_pool *pool;

    pool = task->extra;
    Free(pool->free);
    Free(pool->live);
    Free(pool->slots);
}

struct task *sprite_pool_create(int count, struct sprite_motion *motion,
                                const struct sprite_frame *frames,
                                Bool (*step)(struct sprite_slot *slot,
                                             struct sprite_motion *motion,
                                             const struct sprite_frame *frames))
{
    struct task *task;
    struct sprite_pool *pool;
    int i;

    if ((task = CreateElementalTask(TASK_WORK, 4, sprite_pool_step)) != NULL) {
        pool = MAlloc(sizeof(*pool));
        if (pool != NULL) {
            task->extra = pool;
            pool->count = 0;
            pool->capacity = count;
            /* @hack type: signed products, which the image keeps in the frame
             * at 12 (ADD #-16,R15 at 0x8c0533fc); unsigned, the frame is 4
             * bytes smaller and 13 of 88 words differ */
            pool->free = MAlloc(count * (int)sizeof(*pool->free));
            pool->live = MAlloc(count * (int)sizeof(*pool->live));
            pool->slots = MAlloc(count * (int)sizeof(*pool->slots));
            pool->motion = *motion;
            pool->frames = frames;
            pool->step = step;
            if (step != NULL) {
                task->step = sprite_pool_step_own;
            }
            for (i = 0; i < count; i++) {
                pool->free[i] = i;
            }
            task->draw = sprite_pool_draw;
            task->destructor = sprite_pool_destroy;
        } else {
            DestroyTask(task);
            task = NULL;
        }
    }
    return task;
}
