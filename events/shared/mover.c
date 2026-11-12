/* @unit 0CB821C0-0CB82984 +r04 +egflags +asmfunc=execMoveObjTask:0cb82962 */
/* an event's mover: the task that carries out a move. once its steps run
 * out, it frees its slot and kills itself */
#include <ninja.h>

#include "player/player.h"
#include "shared/move.h"
#include "shared/mover.h"
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
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
extern struct task_work *playertwp[];
extern struct task_motion *playermwp[];
extern struct task *playerpwp[8];
extern Uint8 playerframe[8];
void PInitialize(int player, struct task *task);
void PDestruct(int player);
void PAdjustHoldingPosition(struct task_work *work, struct task_motion *motion);
Bool PCheckPower(struct task_work *work, Angle *ang, Float *stroke);
void PGetAccelerationFly(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void PSetSnowEffect(struct task_work *work, struct task_motion *motion,
                    struct player *record);
void PResetPositionForBuilding(struct task_work *work,
                               struct task_motion *motion,
                               struct player *record);
void PResetPosition(struct task_work *work, struct task_motion *motion,
                    struct player *record);
void PSetCrashEffect(struct task_work *work);
void KillPlayerFallingDownStageP(struct task *task);
void PSetRippleEffect(Uint8 player, NJS_POINT3 *pos, Angle *ang);
int CheckCollisionCylinderP(NJS_POINT3 *pos, Float radius, Float height);
int GetPlayerCharacterName(Uint8 player);
int GetTheNearestPlayerNumber(NJS_POINT3 *pos);
Bool CheckPlayerRideOnMobileLandObjectP(Uint8 player, struct task *task);
void SetLookingTaskP(Uint8 player, struct task *task, NJS_POINT3 *offset);
void SetLookingPointP(Uint8 player, NJS_POINT3 *pos);
void CancelLookingAtP(Uint8 player);
void HoldOnPillarP(Uint8 player, NJS_POINT3 *pos, Uint32 steps);
void KeepPlayersEyesOnThePointP(Uint8 player, struct angles *ang, Uint32 steps);
void SetInputP(Uint8 player, Uint8 mode);
void SetVelocityAndRotationAndNoconTimeWithSpinDashP(Uint8 player,
                                                     NJS_VECTOR *speed,
                                                     const Angle *ang,
                                                     Sint16 steps);
void SetPositionP(Uint8 player, Float x, Float y, Float z);
Bool GetPlayerPosition(Uint8 player, int steps, NJS_POINT3 *pos,
                       struct angles *ang);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
extern struct task *p_MoveObjTask[10];
void moveObject(struct task *target, Float from_x, Float from_y, Float from_z,
                Float to_x, Float to_y, Float to_z, int steps);
void moveObjectAngle(struct task *target, Float from_x, Float from_y,
                     Float from_z, Float to_x, Float to_y, Float to_z,
                     Float ang_x, Float ang_y, Float ang_z, Float to_ang_x,
                     Float to_ang_y, Float to_ang_z, int steps);
void moveObjectAngle2(struct task *target, Float from_x, Float from_y,
                      Float from_z, Float to_x, Float to_y, Float to_z,
                      Angle ang_x, Angle ang_y, Angle ang_z, Angle to_ang_x,
                      Angle to_ang_y, Angle to_ang_z, int steps);
void moveObjectOn(struct task *target, Float x, Float y, Float z, int steps,
                  struct task *base);
void moveObjectOnRotate(struct task *target, Float x, Float y, Float z,
                        int steps, struct task *base);
void moveObjectRightHand(struct task *target, int player, Float x, Float y,
                         Float z, int steps);
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

/* free the mover's slot, and kill the mover */
/* @hack redundant: the test of task, which a step is never passed null.
 * without it in the eight cases that end a move, the step runs 132 bytes
 * short and 777 of 872 words differ */
#define END_MOVE(task, move)                                                   \
    do {                                                                       \
        if ((task) != NULL) {                                                  \
            p_MoveObjTask[(move)->slot] = NULL;                                \
            FreeTask(task);                                                    \
        }                                                                      \
    } while (0)

#ifdef NON_MATCHING
void execMoveObjTask(struct task *task)
{
    struct task_work *work = task->work;
    struct moveObject *move = MOVER(work)->move;
    struct task *player;
    struct player *record;
    Angle ang;
    NJS_VECTOR point;
    NJS_VECTOR moved;
    struct angles turned;

    switch (work->mode) {
    case MOVER_IDLE:
        break;
    case MOVER_LINE_START:
        work->mode = MOVER_LINE;
        break;
    case MOVER_LINE:
        work->pos.x += move->speed.x;
        work->pos.y += move->speed.y;
        work->pos.z += move->speed.z;
        move->target->work->pos.x = work->pos.x;
        move->target->work->pos.y = work->pos.y;
        move->target->work->pos.z = work->pos.z;
        move->target->work->ang.x = move->ang.x;
        move->target->work->ang.y = move->ang.y;
        move->target->work->ang.z = move->ang.z;
        if (++move->step >= move->steps) {
            work->mode = MOVER_LINE_END;
        }
        break;
    case MOVER_LINE_END:
        END_MOVE(task, move);
        break;
    case MOVER_TURN_START:
        work->mode = MOVER_TURN;
        break;
    case MOVER_TURN:
        work->pos.x += move->speed.x;
        work->pos.y += move->speed.y;
        work->pos.z += move->speed.z;
        work->ang.x += move->turn.x;
        work->ang.y += move->turn.y;
        work->ang.z += move->turn.z;
        move->target->work->ang.x = work->ang.x;
        move->target->work->ang.y = work->ang.y;
        move->target->work->ang.z = work->ang.z;
        move->target->work->pos.x = work->pos.x;
        move->target->work->pos.y = work->pos.y;
        move->target->work->pos.z = work->pos.z;
        if (++move->step >= move->steps) {
            work->mode = MOVER_TURN_END;
        }
        break;
    case MOVER_TURN_END:
        END_MOVE(task, move);
        break;
    case MOVER_FOLLOW_START:
        work->mode = MOVER_FOLLOW;
        break;
    case MOVER_FOLLOW:
        work->pos.x = move->base->work->pos.x + move->offset.x;
        work->pos.y = move->base->work->pos.y + move->offset.y;
        work->pos.z = move->base->work->pos.z + move->offset.z;
        move->target->work->pos.x = work->pos.x;
        move->target->work->pos.y = work->pos.y;
        move->target->work->pos.z = work->pos.z;
        move->target->work->ang.x = move->ang.x;
        move->target->work->ang.y = move->ang.y;
        move->target->work->ang.z = move->ang.z;
        if (++move->step >= move->steps) {
            work->mode = MOVER_FOLLOW_END;
        }
        break;
    case MOVER_FOLLOW_END:
        END_MOVE(task, move);
        break;
    /* @hack spelling: MOVER_FOLLOW_ANGLES's cases ahead of MOVER_FOLLOW_TURN's,
     * where the image has their code (MOVER_FOLLOW_ANGLES_START's at
     * 0x0cb84c92 in EV0007), since SHC lays the cases out in the source's
     * order. in enum order, 123 of 872 words differ */
    case MOVER_FOLLOW_ANGLES_START:
        work->mode = MOVER_FOLLOW_ANGLES;
        break;
    case MOVER_FOLLOW_ANGLES:
        work->pos.x = move->base->work->pos.x + move->offset.x;
        work->pos.y = move->base->work->pos.y + move->offset.y;
        work->pos.z = move->base->work->pos.z + move->offset.z;
        work->ang.x = move->base->work->ang.x + move->turn.x;
        work->ang.y = move->base->work->ang.y + move->turn.y;
        work->ang.z = move->base->work->ang.z + move->turn.z;
        move->target->work->pos.x = work->pos.x;
        move->target->work->pos.y = work->pos.y;
        move->target->work->pos.z = work->pos.z;
        move->target->work->ang.x = work->ang.x;
        move->target->work->ang.y = work->ang.y;
        move->target->work->ang.z = work->ang.z;
        if (++move->step >= move->steps) {
            work->mode = MOVER_FOLLOW_ANGLES_END;
        }
        break;
    case MOVER_FOLLOW_ANGLES_END:
        END_MOVE(task, move);
        break;
    case MOVER_FOLLOW_TURN_START:
        work->mode = MOVER_FOLLOW_TURN;
        break;
    case MOVER_FOLLOW_TURN:
        work->pos.x = move->base->work->pos.x + move->offset.x;
        work->pos.y = move->base->work->pos.y + move->offset.y;
        work->pos.z = move->base->work->pos.z + move->offset.z;
        work->ang.x += move->turn.x;
        work->ang.y += move->turn.y;
        work->ang.z += move->turn.z;
        move->target->work->pos.x = work->pos.x;
        move->target->work->pos.y = work->pos.y;
        move->target->work->pos.z = work->pos.z;
        move->target->work->ang.x = work->ang.x;
        move->target->work->ang.y = work->ang.y;
        move->target->work->ang.z = work->ang.z;
        if (++move->step >= move->steps) {
            work->mode = MOVER_FOLLOW_TURN_END;
        }
        break;
    case MOVER_FOLLOW_TURN_END:
        END_MOVE(task, move);
        break;
    case MOVER_FACING_START:
        work->mode = MOVER_FACING;
        break;
    case MOVER_FACING:
        turned.x = move->base->work->ang.x + move->turn.x;
        turned.y = move->base->work->ang.y + move->turn.y;
        turned.z = move->base->work->ang.z + move->turn.z;
        /* @bug uninitialized: njUnitVector reads point, which no path
         * through MOVER_FACING writes first (JSR at 0x0cb84e44 in EV0007).
         * no call starts MOVER_FACING, so the read never runs */
#ifdef GCC
        /* repairs the unset point the tag names: GCC's is the x axis, which
         * event_follow_facing's turns about y and z measure from */
        point.x = 1.0F;
        point.y = 0.0F;
        point.z = 0.0F;
#endif
        njUnitVector(&point);
        njPushMatrix(&nj_unit_matrix_);
        TURN_VIA(njRotateZ, turned.z, ang);
        TURN_VIA(njRotateX, turned.x, ang);
        TURN_VIA(njRotateY, turned.y, ang);
        njCalcVector(NULL, &point, &moved);
        late_DrawObjectClipEx(1);
        work->pos.x = moved.x * MOVER(work)->distance;
        work->pos.y = moved.y * MOVER(work)->distance;
        work->pos.z = moved.z * MOVER(work)->distance;
        move->target->work->pos.x = work->pos.x;
        move->target->work->pos.y = work->pos.y;
        move->target->work->pos.z = work->pos.z;
        /* MOVER_FACING ends through MOVER_FOLLOW_TURN_END, whose case does
         * what MOVER_FACING_END's does */
        if (++move->step >= move->steps) {
            work->mode = MOVER_FOLLOW_TURN_END;
        }
        break;
    case MOVER_FACING_END:
        END_MOVE(task, move);
        break;
    case MOVER_WELD0_START:
        work->mode = MOVER_WELD0;
        break;
    case MOVER_WELD0:
        player = GetPlayerTaskPointer(move->player);
        record = GetPlayerWorkPointer(move->player);
        point.x = -record->weld_point0.x + move->offset.x;
        point.y = record->weld_point0.y + move->offset.y;
        point.z = record->weld_point0.z + move->offset.z;
        njPushMatrix(&nj_unit_matrix_);
        TURN_VIA(njRotateZ, player->work->ang.z, ang);
        TURN_VIA(njRotateX, player->work->ang.x, ang);
        TURN_VIA(njRotateY, 0x8000 - player->work->ang.y, ang);
        njCalcVector(NULL, &point, &moved);
        late_DrawObjectClipEx(1);
        work->pos.x = moved.x + player->work->pos.x;
        work->pos.y = moved.y + player->work->pos.y + record->consts.center_y;
        work->pos.z = moved.z + player->work->pos.z;
        move->target->work->pos.x = work->pos.x;
        move->target->work->pos.y = work->pos.y;
        move->target->work->pos.z = work->pos.z;
        if (++move->step >= move->steps) {
            work->mode = MOVER_WELD0_END;
        }
        break;
    case MOVER_WELD0_END:
        END_MOVE(task, move);
        break;
    case MOVER_WELD1_START:
        work->mode = MOVER_WELD1;
        break;
    case MOVER_WELD1:
        player = GetPlayerTaskPointer(move->player);
        record = GetPlayerWorkPointer(move->player);
        point.x = -record->weld_point1.x + move->offset.x;
        point.y = record->weld_point1.y + move->offset.y;
        point.z = record->weld_point1.z + move->offset.z;
        njPushMatrix(&nj_unit_matrix_);
        TURN_VIA(njRotateZ, player->work->ang.z, ang);
        TURN_VIA(njRotateX, player->work->ang.x, ang);
        TURN_VIA(njRotateY, 0x8000 - player->work->ang.y, ang);
        njCalcVector(NULL, &point, &moved);
        late_DrawObjectClipEx(1);
        work->pos.x = moved.x + player->work->pos.x;
        work->pos.y = moved.y + player->work->pos.y + record->consts.center_y;
        work->pos.z = moved.z + player->work->pos.z;
        move->target->work->pos.x = work->pos.x;
        move->target->work->pos.y = work->pos.y;
        move->target->work->pos.z = work->pos.z;
        if (++move->step >= move->steps) {
            work->mode = MOVER_WELD1_END;
        }
        break;
    case MOVER_WELD1_END:
        END_MOVE(task, move);
        break;
    }
}
#else
void execMoveObjTask(struct task *task)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
}
#endif

void dispMoveObjTask(struct task *task)
{
}

void destMoveObjTask(struct task *task)
{
    struct task_work *work = task->work;

    if (MOVER(work)->move != NULL) {
        Free(MOVER(work)->move);
    }
}
