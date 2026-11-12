/* @unit 0CB859A0-0CB85DC0 +r04 +egflags +pool32 */
/* an event's claw, drawn from the five nodes each event defines */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/model.h"
#include "shared/claw.h"
#include "shared/claw_textures.h"
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void FUN_0cb85d74(struct task *task, enum claw_mode mode);
void FUN_0cb85d88(struct task *task, int open_rate, int close_rate);
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

/* how far each arm turns from shut to open */
#define CLAW_OPEN_MAX 0x3000

#define VARS(work) ((struct claw_vars *)&(work)->vars)
#define CLAW(task) ((struct claw_motion *)(task)->motion)
struct claw_vars {
    Uint32 open; /* how far each arm has turned from shut */
};

/* the claw's TASK_MOTION record, which task_create zeroes */
struct claw_motion {
    Float steps; /* the steps a move lasts */
    NJS_VECTOR speed; /* added to its place each step of a move */
    Uint8 unk_10[24];
    Uint32 open_rate; /* how far its arms turn each step as it opens */
    Uint32 close_rate; /* how far its arms turn each step as it closes */
    Uint8 unk_30[4];
    Float timer; /* the steps its moves have run, which nothing resets */
    Uint8 unk_38[8];
};

/* the claw's nodes, by their place in event_claw_nodes */
enum claw_node {
    CLAW_SPRING,
    CLAW_BALL, /* under the spring */
    CLAW_HUB,
    CLAW_ARM_PLUS, /* the arm the draw turns on the hub by open about z */
    CLAW_ARM_MINUS, /* the arm it turns by -open */
    CLAW_NODES
};

/* each event that links claw.c defines these */
extern NJS_OBJECT *event_claw_nodes[CLAW_NODES];

void event_claw_destroy(struct task *task)
{
}

void event_claw_draw(struct task *task)
{
    njSetTexture_jp(&event_claw_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &task->work->pos);
    njTranslate(NULL, event_claw_nodes[CLAW_SPRING]->pos[0],
                event_claw_nodes[CLAW_SPRING]->pos[1],
                event_claw_nodes[CLAW_SPRING]->pos[2]);
    TURN(njRotateZ, task->work->ang.z + event_claw_nodes[CLAW_SPRING]->ang[2]);
    TURN(njRotateX, task->work->ang.x + event_claw_nodes[CLAW_SPRING]->ang[0]);
    TURN(njRotateY, task->work->ang.y + event_claw_nodes[CLAW_SPRING]->ang[1]);
    njPushMatrix(NULL);
    njScale(NULL, 0.5F, 2.0F, 0.5F);
    ds_DrawModelClip(event_claw_nodes[CLAW_SPRING]->model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, event_claw_nodes[CLAW_BALL]->pos[0],
                event_claw_nodes[CLAW_BALL]->pos[1],
                event_claw_nodes[CLAW_BALL]->pos[2]);
    TURN(njRotateZ, event_claw_nodes[CLAW_BALL]->ang[2]);
    TURN(njRotateX, event_claw_nodes[CLAW_BALL]->ang[0]);
    TURN(njRotateY, event_claw_nodes[CLAW_BALL]->ang[1]);
    njScale(NULL, 0.5F, 0.5F, 0.5F);
    ds_DrawModelClip(event_claw_nodes[CLAW_BALL]->model);
    late_DrawObjectClipEx(1);
    /* the hub's model isn't drawn: its arms turn on it */
    njPushMatrix(NULL);
    njTranslate(NULL, event_claw_nodes[CLAW_HUB]->pos[0],
                event_claw_nodes[CLAW_HUB]->pos[1],
                event_claw_nodes[CLAW_HUB]->pos[2]);
    TURN(njRotateZ, event_claw_nodes[CLAW_HUB]->ang[2]);
    TURN(njRotateX, event_claw_nodes[CLAW_HUB]->ang[0]);
    TURN(njRotateY, event_claw_nodes[CLAW_HUB]->ang[1]);
    njScale(NULL, 0.5F, 0.5F, 0.5F);
    njPushMatrix(NULL);
    njTranslate(NULL, event_claw_nodes[CLAW_ARM_PLUS]->pos[0],
                event_claw_nodes[CLAW_ARM_PLUS]->pos[1],
                event_claw_nodes[CLAW_ARM_PLUS]->pos[2]);
    TURN(njRotateZ,
         event_claw_nodes[CLAW_ARM_PLUS]->ang[2] + VARS(task->work)->open);
    TURN(njRotateX, event_claw_nodes[CLAW_ARM_PLUS]->ang[0]);
    TURN(njRotateY, event_claw_nodes[CLAW_ARM_PLUS]->ang[1]);
    ds_DrawModelClip(event_claw_nodes[CLAW_ARM_PLUS]->model);
    late_DrawObjectClipEx(1);
    njTranslate(NULL, event_claw_nodes[CLAW_ARM_MINUS]->pos[0],
                event_claw_nodes[CLAW_ARM_MINUS]->pos[1],
                event_claw_nodes[CLAW_ARM_MINUS]->pos[2]);
    TURN(njRotateZ,
         event_claw_nodes[CLAW_ARM_MINUS]->ang[2] - VARS(task->work)->open);
    TURN(njRotateX, event_claw_nodes[CLAW_ARM_MINUS]->ang[0]);
    TURN(njRotateY, event_claw_nodes[CLAW_ARM_MINUS]->ang[1]);
    ds_DrawModelClip(event_claw_nodes[CLAW_ARM_MINUS]->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

void event_claw_step(struct task *task)
{
    struct task_work *work = task->work;
    struct claw_motion *motion = CLAW(task);

    switch (work->mode) {
    case CLAW_STILL:
        break;
    case CLAW_OPEN:
        VARS(work)->open += motion->open_rate;
        if (VARS(work)->open >= CLAW_OPEN_MAX) {
            VARS(work)->open = CLAW_OPEN_MAX;
            work->mode = CLAW_STILL;
        }
        break;
    case CLAW_CLOSE:
        VARS(work)->open -= motion->close_rate;
        VARS(work)->open &= 0xffff;
        /* @hack spelling: open <= 0, which for an unsigned open is open == 0,
         * keeps the image's MOV #0,R2 and CMP/HI R2,R0 (0x0cb8776c and
         * 0x0cb87772 in EV0008); without it, 47 of 73 words differ */
        if (VARS(work)->open <= 0) {
            VARS(work)->open = 0;
            work->mode = CLAW_STILL;
        }
        break;
    case CLAW_MOVE:
        work->pos.x += motion->speed.x;
        work->pos.y += motion->speed.y;
        work->pos.z += motion->speed.z;
        if (++motion->timer >= motion->steps) {
            work->mode = CLAW_STILL;
        }
        break;
    case CLAW_LOCKED:
        break;
    }
    event_claw_draw(task);
}

struct task *event_claw_create(Float x, Float y, Float z, Angle ang_x,
                               Angle ang_y, Angle ang_z)
{
    struct task *task =
        CreateElementalTask(TASK_MOTION | TASK_WORK, 3, event_claw_step);

    if (task != NULL) {
        task->work->pos.x = x;
        task->work->pos.y = y;
        task->work->pos.z = z;
        task->work->ang.x = ang_x;
        task->work->ang.y = ang_y;
        task->work->ang.z = ang_z;
        task->work->timer = 0;
        VARS(task->work)->open = 0;
        CLAW(task)->open_rate = 0x20;
        CLAW(task)->close_rate = 0x200;
        task->draw = event_claw_draw;
        task->destructor = event_claw_destroy;
    }
    return task;
}

void FUN_0cb85d74(struct task *task, enum claw_mode mode)
{
    if (task != NULL && task->work->mode == CLAW_STILL) {
        task->work->mode = mode;
    }
}

void FUN_0cb85d88(struct task *task, int open_rate, int close_rate)
{
    if (task != NULL) {
        CLAW(task)->open_rate = open_rate;
        CLAW(task)->close_rate = close_rate;
    }
}
