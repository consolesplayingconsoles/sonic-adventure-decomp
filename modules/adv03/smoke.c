/* @unit 0C901F40-0C902440 +jpflags +pool32 */
/* O SMOKE, a fire that puffs smoke and throws flames */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "adv03/smoke.h"
#include "camera/camera.h"
#include "collision/collision.h"
#include "effect/flame.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "object/placement.h"
#include "system/task.h"
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
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
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

/* the steps between puffs, which the task's timer counts */
#define PUFF_STEPS 16

/* a puff's age counts its steps of growth from 0. the step that finds it at
 * PUFF_GROWN still grows the puff, then turns it to fading */
#define PUFF_GROWN 100

/* within FLAME_NEAR of the camera the fire throws a flame on every step.
 * within FLAME_FAR, it throws one on the steps its timer is odd */
#define FLAME_NEAR 100.0F
#define FLAME_FAR 500.0F

/* the fire's own pool of puffs, which smoke_destroy kills */
#define POOL(work) ((work)->vars.p[0])

#define PUFF(particle) ((struct puff_vars *)&(particle)->vars)
enum smoke_mode { SMOKE_INIT, SMOKE_BURN };

/* a puff's life: it grows, then fades */
enum puff_mode { PUFF_GROW, PUFF_FADE };

struct puff_vars {
    /* @hack type: age as an array of one, which has SHC form its address in
     * a register for each access (ADD #68,R3 at 0x0c902236, ADD #68,R0 at
     * 0x0c902348); as one Sint16, SHC reaches it through @(R0,Rn), and,
     * summed over the two functions that use it, 152 of 291 words differ */
    Sint16 age[1];
};
extern NJS_TEXLIST smoke_puff_texlist;
extern NJS_TEXANIM smoke_puff_frames[8];
extern struct particle_anim smoke_puff_anim;
extern struct collision_shape smoke_shape[1];

void SmokeDestructor(struct task *task);
void spexec_smoke(struct particle *particle, struct particle_pool *pool);
void create_firedust(struct task_work *work);
void spexec_firedust(struct particle *particle, struct particle_pool *pool);

void ObjectPastSmoke(struct task *task)
{
    struct task_work *work = task->work;
    struct particle *puff;
    struct particle_pool *pool;
    Float x;
    Float z;
    Float distance;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case SMOKE_INIT:
        CCL_Init(task, smoke_shape, COLLISION_OBJECT, 1, 1);
        /* @hack spelling: the pool through a local, which SHC copies to R4
         * (MOV R0,R4 at 0x0c90216e); stored directly, the function runs 2
         * bytes short and 168 of 204 words differ */
        pool = particle_pool_create(&smoke_puff_anim, 0);
        POOL(work) = pool;
        task->destructor = SmokeDestructor;
        work->mode = SMOKE_BURN;
        break;
    case SMOKE_BURN:
        TASK_TIMER(work)++;
        if (TASK_TIMER(work) == PUFF_STEPS) {
            puff = SpCreateTask(POOL(work), spexec_smoke);
            if (puff != NULL) {
                puff->life = PUFF_GROW;
                x = ((rand() * RAND_SCALE) - 0.5F) * 10.0F;
                z = ((rand() * RAND_SCALE) - 0.5F) * 10.0F;
                puff->pos.x = work->pos.x + x;
                puff->pos.y = work->pos.y;
                puff->pos.z = work->pos.z + z;
                puff->speed.x = x * 0.1F;
                puff->speed.y = 0.0F;
                puff->speed.z = z * 0.1F;
                puff->frame = (int)(rand() * (1.0F / 8192.0F));
                puff->ang = (int)(((rand() * RAND_SCALE) - 0.5F) * 65536.0F);
                puff->scale = 1.0F + (rand() * (0.5F * RAND_SCALE));
                PUFF(puff)->age[0] = 0;
                puff->color.a = 0.8F;
                puff->color.r = 1.0F;
                puff->color.g = 0.3F;
                puff->color.b = 0.3F;
            }
            TASK_TIMER(work) = 0;
        }
        distance = CalcDistance(&camera_twp->pos, &work->pos);
        if (distance < FLAME_NEAR) {
            create_firedust(work);
        } else if (distance < FLAME_FAR && (TASK_TIMER(work) & 1)) {
            create_firedust(work);
        }
        break;
    }
    EntryColliList(work);
}

void SmokeDestructor(struct task *task)
{
    struct task_work *work = task->work;

    if (POOL(work) != NULL) {
        SpFreeLink(POOL(work));
    }
}

void spexec_smoke(struct particle *particle, struct particle_pool *pool)
{
    switch (particle->life) {
    case PUFF_GROW:
        if (PUFF(particle)->age[0]++ == PUFF_GROWN) {
            particle->life = PUFF_FADE;
        }
        if (particle->color.r > 0.3F) {
            particle->color.r -= 0.01F;
        }
        particle->scale += 0.02F;
        break;
    case PUFF_FADE:
        particle->color.a -= 0.005F;
        if (particle->color.a < 0.0F) {
            SpFreeTask(particle);
            return;
        }
        particle->scale += 0.04F;
        break;
    }
    if (particle->ang > 0) {
        particle->ang += 64;
    } else {
        particle->ang -= 64;
    }
    particle->speed.y += 0.05F;
    particle->speed.y *= 0.97F;
    particle->pos.y += particle->speed.y;
}

void create_firedust(struct task_work *work)
{
    struct particle *flame = SpCreateTask(flame_pool.pool, spexec_firedust);

    if (flame != NULL) {
        flame->life = 30 + (int)(rand() * (30.0F * RAND_SCALE));
        flame->frame = (int)(rand() * (8.0F * RAND_SCALE));
        flame->ang = 0;
        flame->scale = 0.05F + (rand() * (0.05F * RAND_SCALE));
        flame->depth = -10.0F;
        flame->pos.x = work->pos.x + (((rand() * RAND_SCALE) - 0.5F) * 20.0F);
        flame->pos.y = work->pos.y + (rand() * (40.0F * RAND_SCALE)) + 10.0F;
        flame->pos.z = work->pos.z + (((rand() * RAND_SCALE) - 0.5F) * 20.0F);
        flame->speed.x = ((rand() * RAND_SCALE) - 0.5F) * 3.0F;
        flame->speed.y = 0.5F + (rand() * (2.0F * RAND_SCALE));
        flame->speed.z = ((rand() * RAND_SCALE) - 0.5F) * 3.0F;
        flame->color.a = 0.8F;
        flame->color.r = 1.0F;
        flame->color.g = 0.5F;
        flame->color.b = 0.5F;
    }
}

void spexec_firedust(struct particle *particle, struct particle_pool *pool)
{
    char *speed;
    char *pos;
    Float x;
    Float y;
    Float z;
    Float drag;
    Float px;
    Float py;
    Float pz;

    if (particle->life == 0) {
        SpFreeTask(particle);
        return;
    }
    /* @hack spelling: speed read whole through a byte cursor before it is
     * written back; through the members, SHC orders the loads and stores
     * otherwise and 31 of 37 words differ */
    speed = (char *)&particle->speed;
    drag = 0.96F;
    x = *(Float *)speed * drag;
    speed += sizeof(Float);
    y = *(Float *)speed;
    speed += sizeof(Float);
    z = *(Float *)speed * drag;
    speed += sizeof(Float);
    y *= drag;
    y += 0.05F;
    *(Float *)(speed -= sizeof(Float)) = z;
    *(Float *)(speed -= sizeof(Float)) = y;
    *(Float *)(speed -= sizeof(Float)) = x;
    /* @hack spelling: pos the same way; through the members, 23 of 37 words
     * differ */
    pos = (char *)&particle->pos;
    px = *(Float *)pos;
    pos += sizeof(Float);
    py = *(Float *)pos;
    pos += sizeof(Float);
    pz = *(Float *)pos;
    pos += sizeof(Float);
    px += x;
    py += y;
    pz += z;
    pos -= sizeof(Float);
    *(Float *)pos = pz;
    pos -= sizeof(Float);
    *(Float *)pos = py;
    pos -= sizeof(Float);
    *(Float *)pos = px;
    particle->life--;
}
