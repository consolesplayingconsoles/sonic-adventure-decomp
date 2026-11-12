/* @unit 0CB82540-0CB826A0 +egflags +pool32 */
/* an event's rays: a task that starts count beams at one point each step */
#include <ninja.h>
#include <sg_xpt.h>

#include "effect/beam.h"
#include "shared/rays.h"
#include "system/task.h"
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
void FUN_0cb825d8(void);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);

/* the rays' modes, in work->mode */
#define RAYS_IDLE 0
#define RAYS_RUNNING 1

/* the rays' record, from the heap, which the destructor frees */
#define VARS(work) ((struct rays_vars *)&(work)->vars)
struct rays {
    struct beam_params beam; /* the parameters each beam starts with */
    int count; /* beams started each step */
};

struct rays_vars {
    Sint32 steps; /* the steps run in RAYS_RUNNING, counted and never read */
    Uint8 unk_04[4];
    struct rays *rays;
};
extern struct task *event_rays;

void initCrushLightTask(struct task *task);
void execCrushLightTask(struct task *task);
void destCrushLightTask(struct task *task);

void crushLightOn(Float x, Float y, Float z, int count, int time,
                  Float width_foot, Float width_tip, Uint32 color_foot,
                  Uint32 color_tip)
{
    struct rays *rays;
    struct task_work *work;

    event_rays = CreateElementalTask(TASK_WORK, 5, initCrushLightTask);
    rays = MAlloc(sizeof(struct rays));
    work = event_rays->work;
    VARS(work)->rays = rays;
    work->mode = RAYS_IDLE;
    VARS(work)->steps = 0;
    work->pos.x = x;
    work->pos.y = y;
    work->pos.z = z;
    rays->beam.time = time;
    rays->beam.width[0] = width_foot;
    rays->beam.width[1] = width_tip;
    rays->beam.color[0] = color_foot;
    rays->beam.color[1] = color_tip;
    rays->beam.max_speed = 91;
    rays->beam.length = 100.0F;
    rays->beam.growth = 1.3F;
    rays->count = count;
    work->mode = RAYS_RUNNING;
}

void FUN_0cb825d8(void)
{
    if (event_rays != NULL) {
        FreeTask(event_rays);
        event_rays = NULL;
    }
}

void initCrushLightTask(struct task *task)
{
    task->step = execCrushLightTask;
    task->draw = NULL;
    task->destructor = destCrushLightTask;
}

void execCrushLightTask(struct task *task)
{
    struct task_work *work = task->work;
    struct rays *rays = VARS(work)->rays;
    int i;

    switch (work->mode) {
    case RAYS_IDLE:
        break;
    case RAYS_RUNNING:
        VARS(work)->steps++;
        for (i = 0; i < rays->count; i++) {
            /* @bug memory: a beam that outlives this task reads its foot from
             * freed memory. each beam keeps &work->pos and reads it each step
             * (JSR at 0x0cb80d7a in EV009D, MOV.L @(24,R14),R4 at 0x8c047a00
             * in beam_draw). event_rays_kill has the task destroy itself on
             * its next step, which frees work, and a beam runs on for about
             * time + min(time, 10) steps from its start */
            beam_create(&work->pos, &rays->beam);
        }
        break;
    }
}

void destCrushLightTask(struct task *task)
{
    struct task_work *work = task->work;
    struct rays *rays = VARS(work)->rays;

    if (rays != NULL) {
        Free(rays);
    }
}
