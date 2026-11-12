/* @unit 0C902A60-0C902CA0 +jpflags +pool32 */
/* O BURNING, flames that fly out and up from a ring round the object */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "adv03/burning.h"
#include "effect/flame.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "object/placement.h"
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
void *syMalloc_default_malloc(size_t size);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void SpFreeLink(struct particle_pool *pool);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

/* the steps from one flame to the next, a power of 2 to mask the timer by */
#define FLAME_STEPS 8
/* a flame starts at a random sprite frame below START_FRAMES and plays
 * FRAME_RATE frames a step. it ends once its frame reaches END_FRAME, so it
 * never shows the last two of flame_pool's ten frames */
#define START_FRAMES 3.0F
#define FRAME_RATE 0.15F
#define END_FRAME 8
/* a flame's scale starts at random from START_SCALE up to START_SCALE + 1.
 * its sprite's angle is random, within TILT / 2 either side of 0 */
#define START_SCALE 1.8F
#define TILT 4096.0F
/* each step, a flame keeps SPEED_KEPT of its speed, then gains LIFT of upward
 * speed. its scale loses SHRINK a step */
#define SPEED_KEPT 0.94F
#define LIFT 0.05F
#define SHRINK 0.02F

#define FLAME_DEPTH (-20.0F)

#define VARS(work) ((struct burning_vars *)&(work)->vars)
enum burning_mode { BURNING_INIT, BURNING_RUN };

struct burning_vars {
    Uint8 unk_00[4];
    Sint16 around; /* the next flame's angle round the ring */
    Sint16 rise_phase; /* its sine sets the next flame's upward speed */
};
extern NJS_ARGB flame_color;

void spexec_fire(struct particle *particle, struct particle_pool *pool);

void ObjectPastBurning(struct task *task)
{
    struct task_work *work = task->work;
    struct particle *flame;
    Float x;
    Float y;
    Float z;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BURNING_INIT:
        work->mode = BURNING_RUN;
        break;
    case BURNING_RUN:
        if ((TASK_TIMER(work)++ & (FLAME_STEPS - 1)) == 0) {
            flame = SpCreateTask(flame_pool.pool, spexec_fire);
            if (flame != NULL) {
                /* the flame's offset on the ring is also its outward speed */
                x = njSin(VARS(work)->around) * work->scl.x;
                z = njCos(VARS(work)->around) * work->scl.x;
                VARS(work)->around += work->ang.x;
                y = (njSin(VARS(work)->rise_phase) + 1.0F) * work->scl.y;
                VARS(work)->rise_phase += work->ang.y;
                flame->time = rand() * (START_FRAMES * RAND_SCALE);
                flame->pos.x = work->pos.x + x;
                flame->pos.y = work->pos.y;
                flame->pos.z = work->pos.z + z;
                flame->scale = (rand() * RAND_SCALE) + START_SCALE;
                flame->ang = ((rand() * RAND_SCALE) - 0.5F) * TILT;
                flame->speed.x = x + (((rand() * RAND_SCALE) - 0.5F) * 2.0F);
                flame->speed.y = y;
                flame->speed.z = z + (((rand() * RAND_SCALE) - 0.5F) * 2.0F);
                flame->depth = FLAME_DEPTH;
                flame->color = flame_color;
            }
        }
        break;
    }
}

void spexec_fire(struct particle *particle, struct particle_pool *pool)
{
    char *cursor;
    Float x;
    Float y;
    Float z;
    Float px;
    Float py;
    Float pz;

    particle->frame = particle->time;
    if (particle->frame >= END_FRAME) {
        particle->frame = END_FRAME - 1;
        SpFreeTask(particle);
        return;
    }
    particle->time += FRAME_RATE;
    /* @hack spelling: speed read whole through a byte cursor before it is
     * written back; through the members, SHC orders the loads and stores
     * otherwise and 33 of 55 words differ */
    cursor = (char *)&particle->speed;
    x = *(Float *)cursor;
    cursor += sizeof(Float);
    y = *(Float *)cursor;
    cursor += sizeof(Float);
    z = *(Float *)cursor;
    cursor += sizeof(Float);
    y *= SPEED_KEPT;
    x *= SPEED_KEPT;
    z *= SPEED_KEPT;
    y += LIFT;
    cursor -= sizeof(Float);
    *(Float *)cursor = z;
    cursor -= sizeof(Float);
    *(Float *)cursor = y;
    cursor -= sizeof(Float);
    *(Float *)cursor = x;
    /* @hack spelling: pos the same way; through the members, 27 of 55
     * words differ */
    cursor = (char *)&particle->pos;
    px = *(Float *)cursor;
    cursor += sizeof(Float);
    py = *(Float *)cursor;
    cursor += sizeof(Float);
    pz = *(Float *)cursor;
    cursor += sizeof(Float);
    px += x;
    py += y;
    pz += z;
    cursor -= sizeof(Float);
    *(Float *)cursor = pz;
    cursor -= sizeof(Float);
    *(Float *)cursor = py;
    cursor -= sizeof(Float);
    *(Float *)cursor = px;
    particle->scale -= SHRINK;
}
