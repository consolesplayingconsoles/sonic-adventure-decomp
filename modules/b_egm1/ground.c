/* @unit 0C9042C0-0C904920 +r04 +egflags +pool32 */
/* the Egg Hornet near the ground: its nodes' places, its shadow, and dust
 * and clods where it lands */
#include <ninja.h>
#include <sg_xpt.h>

#include "b_egm1/effect_textures.h"
#include "b_egm1/egg_hornet.h"
#include "b_egm1/ground.h"
#include "b_egm1/texlists.h"
#include "b_egm1/util.h"
#include "collision/ground.h"
#include "draw/pose.h"
#include "draw/tree.h"
#include "effect/dust.h"
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
extern Sint8 chaos_reqmode;
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke2(struct dust_params *params);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void Free(void *mem);
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

/* the node whose place the shadow falls under */
#define SHADOW_NODE 0
/* shadow_draw's scale: the shadow's size on a floor right under the node */
#define SHADOW_SCALE 16.0F

#define WHOLE_TURN NJM_DEG_ANG(360)

#define RING_RADIUS 44.0F
#define RING_RISE 0.6F
#define RING_SCALE 3.0F
#define PUFFS 4
#define PUFF_RADIUS 12.0F
#define PUFF_RISE 0.8F
#define PUFF_SCALE 20.0F
#define CLOD_GRAVITY (-0.1F)
#define CLOD_SPIN NJM_DEG_ANG(8)
#define CLOD_SIZES 3
#define CLOD_KINDS 2
struct dust_ring {
    NJS_POINT3 center;
    Uint8 mode; /* an enum ground_mode */
};

struct clod {
    NJS_OBJECT *object;
    NJS_TEXLIST *texlist;
    NJS_VECTOR speed;
    struct angles spin;
    Float scale;
};

struct clod_config {
    NJS_OBJECT *object;
    NJS_TEXLIST *texlist;
    NJS_POINT3 *pos;
    NJS_VECTOR *speed;
    Float scale;
    /* random_spin's range for the clod's spin about each axis, in a step */
    Angle spin;
};

struct clods {
    NJS_POINT3 origin;
    Sint32 steps; /* the steps the clods' task has run */
    Uint8 mode; /* an enum ground_mode */
};
extern const Float clod_scales[3];
extern const Float clod_rises[3];
extern const Float clod_radii[3];
extern Float clod_speed;
extern NJS_OBJECT *clod_objects[2];
extern NJS_TEXLIST *clod_texlists[2];
extern struct task *dust_ring_task;
extern struct task *clods_task;

Bool egg_hornet_node_matrix(struct task *task, Uint16 node, NJS_MATRIX *matrix)
{
    struct egg_hornet *record = task->extra;
    NJS_ACTION *action = record->motion.actions[record->motion.current].action;

    CalcMMMatrix(NULL, action, record->motion.frame, POSE_LAST_NODE, NULL);
    return GetMMMatrix(node, matrix);
}

void egg_hornet_shadow(struct task *task)
{
    struct task_work *work = task->work;
    NJS_MATRIX matrix;
    NJS_POINT3 pos;

    VECTOR_COPY(&pos, &work->pos);
    njPushMatrix(NULL);
    njUnitMatrix(NULL);
    egg_hornet_place(task);
    egg_hornet_node_matrix(task, SHADOW_NODE, &matrix);
    njGetTranslation(&matrix, &work->pos);
    late_DrawObjectClipEx(1);
    shadow_draw(work, SHADOW_SCALE);
    VECTOR_COPY(&work->pos, &pos);
}

void dust_ring_step(struct task *task)
{
    struct dust_ring *ring = task->extra;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    Angle ang;

    switch (ring->mode) {
    case GROUND_ON:
        ang = random_spin(WHOLE_TURN);
        pos.x = ring->center.x + (njCos(ang) * RING_RADIUS);
        pos.y = ring->center.y;
        pos.z = ring->center.z + (njSin(ang) * RING_RADIUS);
        speed.x = 0.0F;
        speed.y = RING_RISE;
        speed.z = 0.0F;
        CreateSmoke(&pos, &speed, RING_SCALE);
        break;
    default:
        FreeTask(task);
        break;
    }
}

void dust_ring_create(NJS_POINT3 *center)
{
    struct task *task;
    struct dust_ring *ring;

    if ((dust_ring_task = task = CreateElementalTask(0, 3, dust_ring_step)) !=
        NULL) {
        ring = CAlloc(1, sizeof(struct dust_ring));
        task->extra = ring;
        ring->center = *center;
        ring->mode = GROUND_ON;
        task->step = dust_ring_step;
    }
}

void dust_ring_set_mode(enum ground_mode mode)
{
    struct dust_ring *ring = dust_ring_task->extra;

    ring->mode = mode;
}

void landing_puffs(NJS_POINT3 *origin)
{
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    Angle ang;
    int i;

    for (i = 0; i < PUFFS; i++) {
        ang = random_spin(WHOLE_TURN);
        pos.x = origin->x + (njCos(ang) * PUFF_RADIUS);
        pos.y = origin->y;
        pos.z = origin->z + (njSin(ang) * PUFF_RADIUS);
        speed.x = 0.0F;
        speed.y = PUFF_RISE;
        speed.z = 0.0F;
        CreateSmoke(&pos, &speed, PUFF_SCALE);
    }
}

void clod_draw(struct task *task);

void clod_step(struct task *task)
{
    struct task_work *work = task->work;
    struct clod *clod = task->extra;

    work->pos.x = work->pos.x + clod->speed.x;
    work->pos.y = work->pos.y + clod->speed.y;
    work->pos.z = work->pos.z + clod->speed.z;
    clod->speed.y += CLOD_GRAVITY;
    work->ang.x = work->ang.x + clod->spin.x;
    work->ang.y = work->ang.y + clod->spin.y;
    work->ang.z = work->ang.z + clod->spin.z;
    if (work->pos.y < 0.0F) {
        FreeTask(task);
        return;
    }
    clod_draw(task);
}

void clod_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct clod *clod = task->extra;
    Float scale;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    njRotateZXY(NULL, work->ang.x, work->ang.y, work->ang.z);
    scale = clod->scale;
    njScale(NULL, scale, scale, scale);
    njSetTexture_jp(clod->texlist);
    late_DrawObject(clod->object);
    late_DrawObjectClipEx(1);
}

void clod_create(struct clod_config *config)
{
    struct task *task;
    struct task_work *work;
    struct clod *clod;

    if ((task = CreateElementalTask(TASK_WORK, 3, clod_step)) != NULL) {
        work = task->work;
        task->extra = clod = CAlloc(1, sizeof(struct clod));
        clod->object = config->object;
        clod->texlist = config->texlist;
        work->pos.x = config->pos->x;
        work->pos.y = config->pos->y;
        work->pos.z = config->pos->z;
        clod->speed.x = config->speed->x;
        clod->speed.y = config->speed->y;
        clod->speed.z = config->speed->z;
        clod->scale = config->scale;
        clod->spin.x = random_spin(config->spin);
        clod->spin.y = random_spin(config->spin);
        clod->spin.z = random_spin(config->spin);
        work->ang.x = random_spin(WHOLE_TURN);
        work->ang.y = random_spin(WHOLE_TURN);
        work->ang.z = random_spin(WHOLE_TURN);
        task->step = clod_step;
        task->draw = clod_draw;
    }
}

/* make a clod every second step. steps is even then, so size runs 2, 1 and
 * 0 in turn. kind is always 0 */
void clods_step(struct task *task)
{
    struct clods *clods = task->extra;
    struct clod_config config;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    Angle ang;
    int size;
    int kind;

    switch (clods->mode) {
    case GROUND_ON:
        if ((++clods->steps & 1) == 0) {
            ang = random_spin(WHOLE_TURN);
            size = clods->steps % CLOD_SIZES;
            pos.x = clods->origin.x + (njCos(ang) * clod_radii[size]);
            pos.y = clods->origin.y;
            pos.z = clods->origin.z + (njSin(ang) * clod_radii[size]);
            speed.x = njCos(ang) * clod_speed;
            speed.y = clod_rises[size];
            speed.z = njSin(ang) * clod_speed;
            config.pos = &pos;
            config.speed = &speed;
            config.scale = clod_scales[size];
            config.spin = CLOD_SPIN;
            kind = clods->steps % CLOD_KINDS;
            config.object = clod_objects[kind];
            config.texlist = clod_texlists[kind];
            clod_create(&config);
        }
        break;
    default:
        FreeTask(task);
        break;
    }
}

void clods_create(NJS_POINT3 *pos)
{
    struct task *task;
    struct clods *clods;

    if ((clods_task = task = CreateElementalTask(0, 3, clods_step)) != NULL) {
        clods = CAlloc(1, sizeof(struct clods));
        task->extra = clods;
        clods->origin = *pos;
        clods->mode = GROUND_ON;
        clods->steps = 0;
        task->step = clods_step;
    }
}

void clods_set_mode(enum ground_mode mode)
{
    struct clods *clods = clods_task->extra;

    clods->mode = mode;
}
