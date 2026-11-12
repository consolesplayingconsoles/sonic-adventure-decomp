/* @unit 0CB88180-0CB88C00 +egflags +pool32 +tail0900 */
/* an event's moves: the calls that make a mover and its move. mover.c
 * holds the mover's step */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "shared/move.h"
#include "shared/mover.h"
#include "system/task.h"
#include "system/util.h"
float njFloor(float x);
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
void Free(void *mem);
void moveObject(struct task *target, Float from_x, Float from_y, Float from_z,
                Float to_x, Float to_y, Float to_z, int steps);
void moveObjectOnAngle(struct task *target, Float x, Float y, Float z,
                       Angle ang_x, Angle ang_y, Angle ang_z, int steps,
                       struct task *base);
void moveObjectRightHand(struct task *target, int player, Float x, Float y,
                         Float z, int steps);
void FUN_0cb88b20(struct task *target);
void FUN_0cb88b7e(void);
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

/* d degrees in angle units, plus a half and truncated toward 0 */
#define DEGREES_TO_ANGLE(d) ((Angle)(((d) * ANGLE_PER_DEGREE) + 0.5F))

void initMoveObjTask(struct task *task);
extern struct task *p_MoveObjTask[10];

/* the first free slot, or -1 */
int getTaskIndex(void)
{
    int i;

    for (i = 0; i < EVENT_MOVERS; i++) {
        if (p_MoveObjTask[i] == NULL) {
            return i;
        }
    }
    return -1;
}

void moveObject(struct task *target, Float from_x, Float from_y, Float from_z,
                Float to_x, Float to_y, Float to_z, int steps)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = from_x;
    work->pos.y = from_y;
    work->pos.z = from_z;
    move->target = target;
    move->from.x = from_x;
    move->from.y = from_y;
    move->from.z = from_z;
    move->to.x = to_x;
    move->to.y = to_y;
    move->to.z = to_z;
    move->ang.x = target->work->ang.x;
    move->ang.y = target->work->ang.y;
    move->ang.z = target->work->ang.z;
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    move->speed.x = (to_x - from_x) / steps;
    move->speed.y = (to_y - from_y) / steps;
    move->speed.z = (to_z - from_z) / steps;
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_LINE_START;
    }
}

void moveObjectAngle(struct task *target, Float from_x, Float from_y,
                     Float from_z, Float to_x, Float to_y, Float to_z,
                     Float ang_x, Float ang_y, Float ang_z, Float to_ang_x,
                     Float to_ang_y, Float to_ang_z, int steps)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = from_x;
    work->pos.y = from_y;
    work->pos.z = from_z;
    work->ang.x = DEGREES_TO_ANGLE(ang_x);
    work->ang.y = DEGREES_TO_ANGLE(ang_y);
    work->ang.z = DEGREES_TO_ANGLE(ang_z);
    move->target = target;
    move->from.x = from_x;
    move->from.y = from_y;
    move->from.z = from_z;
    move->to.x = to_x;
    move->to.y = to_y;
    move->to.z = to_z;
    move->ang.x = DEGREES_TO_ANGLE(ang_x);
    move->ang.y = DEGREES_TO_ANGLE(ang_y);
    move->ang.z = DEGREES_TO_ANGLE(ang_z);
    move->ang_to.x = DEGREES_TO_ANGLE(to_ang_x);
    move->ang_to.y = DEGREES_TO_ANGLE(to_ang_y);
    move->ang_to.z = DEGREES_TO_ANGLE(to_ang_z);
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    move->speed.x = (to_x - from_x) / steps;
    move->speed.y = (to_y - from_y) / steps;
    move->speed.z = (to_z - from_z) / steps;
    move->turn.x = DEGREES_TO_ANGLE((to_ang_x - ang_x) / steps);
    move->turn.y = DEGREES_TO_ANGLE((to_ang_y - ang_y) / steps);
    move->turn.z = DEGREES_TO_ANGLE((to_ang_z - ang_z) / steps);
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_TURN_START;
    }
}

void moveObjectAngle2(struct task *target, Float from_x, Float from_y,
                      Float from_z, Float to_x, Float to_y, Float to_z,
                      Angle ang_x, Angle ang_y, Angle ang_z, Angle to_ang_x,
                      Angle to_ang_y, Angle to_ang_z, int steps)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = from_x;
    work->pos.y = from_y;
    work->pos.z = from_z;
    work->ang.x = ang_x;
    work->ang.y = ang_y;
    work->ang.z = ang_z;
    move->target = target;
    move->from.x = from_x;
    move->from.y = from_y;
    move->from.z = from_z;
    move->to.x = to_x;
    move->to.y = to_y;
    move->to.z = to_z;
    move->ang.x = ang_x;
    move->ang.y = ang_y;
    move->ang.z = ang_z;
    move->ang_to.x = to_ang_x;
    move->ang_to.y = to_ang_y;
    move->ang_to.z = to_ang_z;
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    move->speed.x = (to_x - from_x) / steps;
    move->speed.y = (to_y - from_y) / steps;
    move->speed.z = (to_z - from_z) / steps;
    move->turn.x = (Float)(to_ang_x - ang_x) / steps;
    move->turn.y = (Float)(to_ang_y - ang_y) / steps;
    move->turn.z = (Float)(to_ang_z - ang_z) / steps;
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_TURN_START;
    }
}

void moveObjectOn(struct task *target, Float x, Float y, Float z, int steps,
                  struct task *base)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = target->work->pos.x;
    work->pos.y = target->work->pos.y;
    work->pos.z = target->work->pos.z;
    move->ang.x = target->work->ang.x;
    move->ang.y = target->work->ang.y;
    move->ang.z = target->work->ang.z;
    move->target = target;
    move->base = base;
    move->offset.x = x;
    move->offset.y = y;
    move->offset.z = z;
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_FOLLOW_START;
    }
}

void event_follow_turn(struct task *target, Float x, Float y, Float z,
                       Angle ang_x, Angle ang_y, Angle ang_z, int steps,
                       struct task *base)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = target->work->pos.x;
    work->pos.y = target->work->pos.y;
    work->pos.z = target->work->pos.z;
    work->ang.x = target->work->ang.x;
    work->ang.y = target->work->ang.y;
    work->ang.z = target->work->ang.z;
    move->target = target;
    move->base = base;
    move->offset.x = x;
    move->offset.y = y;
    move->offset.z = z;
    move->turn.x = (Float)(ang_x - target->work->ang.x) / steps;
    move->turn.y = (Float)(ang_y - target->work->ang.y) / steps;
    move->turn.z = (Float)(ang_z - target->work->ang.z) / steps;
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_FOLLOW_TURN_START;
    }
}

void moveObjectOnAngle(struct task *target, Float x, Float y, Float z,
                       Angle ang_x, Angle ang_y, Angle ang_z, int steps,
                       struct task *base)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = target->work->pos.x;
    work->pos.y = target->work->pos.y;
    work->pos.z = target->work->pos.z;
    work->ang.x = target->work->ang.x;
    work->ang.y = target->work->ang.y;
    work->ang.z = target->work->ang.z;
    move->target = target;
    move->base = base;
    move->offset.x = x;
    move->offset.y = y;
    move->offset.z = z;
    move->turn.x = ang_x;
    move->turn.y = ang_y;
    move->turn.z = ang_z;
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_FOLLOW_ANGLES_START;
    }
}

void moveObjectOnRotate(struct task *target, Float x, Float y, Float z,
                        int steps, struct task *base)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = target->work->pos.x;
    work->pos.y = target->work->pos.y;
    work->pos.z = target->work->pos.z;
    work->ang.x = target->work->ang.x;
    work->ang.y = target->work->ang.y;
    work->ang.z = target->work->ang.z;
    move->target = target;
    move->base = base;
    move->offset.x = x;
    move->offset.y = y;
    move->offset.z = z;
    MOVER(work)->distance = njSqrt((x * x) + (y * y) + (z * z));
    move->turn.x =
        (Angle)(njArcTan2(y, z) * ANGLE_PER_RADIAN) - move->base->work->ang.x;
    move->turn.y =
        (Angle)(njArcTan2(z, x) * ANGLE_PER_RADIAN) - move->base->work->ang.y;
    move->turn.z =
        (Angle)(njArcTan2(y, x) * ANGLE_PER_RADIAN) - move->base->work->ang.z;
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_FOLLOW_ANGLES_START;
    }
}

void moveObjectRightHand(struct task *target, int player, Float x, Float y,
                         Float z, int steps)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = target->work->pos.x;
    work->pos.y = target->work->pos.y;
    work->pos.z = target->work->pos.z;
    move->target = target;
    move->player = player;
    move->offset.x = x;
    move->offset.y = y;
    move->offset.z = z;
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_WELD0_START;
    }
}

void event_follow_weld1(struct task *target, int player, Float x, Float y,
                        Float z, int steps)
{
    int slot = getTaskIndex();
    struct moveObject *move;
    struct task_work *work;

    if (slot < 0) {
        return;
    }
    p_MoveObjTask[slot] = CreateElementalTask(TASK_WORK, 5, initMoveObjTask);
    move = MAlloc(sizeof(*move));
    work = p_MoveObjTask[slot]->work;
    MOVER(work)->move = move;
    work->pos.x = target->work->pos.x;
    work->pos.y = target->work->pos.y;
    work->pos.z = target->work->pos.z;
    move->target = target;
    move->player = player;
    move->offset.x = x;
    move->offset.y = y;
    move->offset.z = z;
    move->steps = steps;
    move->step = 0;
    move->slot = slot;
    if (p_MoveObjTask[slot] != NULL) {
        work = p_MoveObjTask[slot]->work;
        work->mode = MOVER_WELD1_START;
    }
}

void FUN_0cb88b20(struct task *target)
{
    struct moveObject *move;
    int i;

    for (i = 0; i < EVENT_MOVERS; i++) {
        if (p_MoveObjTask[i] != NULL) {
            move = MOVER(p_MoveObjTask[i]->work)->move;
            if (move->target == target) {
                DestroyTask(p_MoveObjTask[i]);
                p_MoveObjTask[i] = NULL;
            }
        }
    }
}

void FUN_0cb88b7e(void)
{
    int i;

    for (i = 0; i < EVENT_MOVERS; i++) {
        if (p_MoveObjTask[i] != NULL) {
            /* @hack redundant: a read of the move that nothing uses, which
             * loads it in task_destroy's delay slot (MOV.L @R2,R2 at 0x0cb8496a
             * in EV0007); without it, 80 of 94 words differ and the function
             * ends 40 bytes short */
            (void)MOVER(p_MoveObjTask[i]->work)->move;
            DestroyTask(p_MoveObjTask[i]);
            p_MoveObjTask[i] = NULL;
        }
    }
}

#ifdef GCC
/* run up to skip_owed passes, the steps the mover owes for a skip's collapsed
 * wait. the passes stop at MOVER_IDLE or an _END mode, the modes that are
 * multiples of 3. an idle pass does nothing. an _END pass kills the mover, so
 * the mover's own step runs it */
static void event_mover_pay(struct task *task)
{
    int i;

    for (i = skip_owed; i > 0 && task->work->mode % 3 != 0; i--) {
        execMoveObjTask(task);
    }
}

/* a mover's step under GCC: the passes owed, then its own */
static void event_mover_skip_step(struct task *task)
{
    event_mover_pay(task);
    execMoveObjTask(task);
}
#endif

void initMoveObjTask(struct task *task)
{
#ifdef GCC
    /* a mover pays from its first step, so one made under a skip pays the
     * wait after it at once */
    event_mover_pay(task);
    task->step = event_mover_skip_step;
#else
    task->step = execMoveObjTask;
#endif
    task->draw = dispMoveObjTask;
    task->destructor = destMoveObjTask;
}
