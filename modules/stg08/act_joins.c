/* @unit 0C90D6E0-0C90DA00 +egflags +pool32 */
/* ACT23JOIN joins act 1 to act 2 with solid ground, and ACT12JOIN act 0 to
 * act 1. their names count acts from 1 */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "stage/stage.h"
#include "stg08/act_joins.h"
#include "system/task.h"
#include "system/texture.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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
struct task *GetPlayerTaskPointer(Uint8 player);
struct player *GetPlayerWorkPointer(Uint8 player);
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
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Bool ChkPause(void);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);

#define JOIN_NEAR 16.0F
#define VARS(work) ((struct act_join_vars *)&(work)->vars)
extern NJS_OBJECT icecap_act23_join_object;
extern NJS_OBJECT icecap_act12_join_object;

/* the collision world tests a join only while a player is near it. near
 * means within the model's radius plus JOIN_NEAR of the join's center. the
 * join's center is the model's center offset by the join's position */

/* which join the task is, in work->mode */
enum act_join_kind { JOIN_ACT12, JOIN_ACT23 };

struct act_join_vars {
    NJS_OBJECT *object; /* its copy of source in the world, or null */
    NJS_OBJECT *source; /* the join's model, which it draws */
};

void IcecapJointExecute(struct task *task);
void IcecapJointDisplay(struct task *task);
void IcecapJointExit(struct task *task);

/* a join stands where its model's position puts it, not where its task was
 * created. a join the set file placed holds its placement, so its task lives
 * on as the act changes. a join the set editor holds has no copy in the
 * world */
void ObjectIcecapJoint(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    if (task->placement != NULL) {
        placement_hold(task);
    }
    work->mode = JOIN_ACT23;
    VARS(work)->source = &icecap_act23_join_object;
    if (!OnEdit(task)) {
        VARS(work)->object = object = GetMobileLandObject();
        object->evalflags = VARS(work)->source->evalflags &
                            ~(NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG);
        object->scl[0] = 1.0F;
        object->scl[1] = 1.0F;
        object->scl[2] = 1.0F;
        object->ang[0] = 0;
        object->ang[1] = 0;
        object->ang[2] = 0;
        object->pos[0] = work->pos.x = VARS(work)->source->pos[0];
        object->pos[1] = work->pos.y = VARS(work)->source->pos[1];
        object->pos[2] = work->pos.z = VARS(work)->source->pos[2];
        object->model = VARS(work)->source->model;
        object->child = VARS(work)->source->child;
        object->sibling = VARS(work)->source->sibling;
        RegisterCollisionEntry(WORLD_SOLID, task, object);
    }
    task->destructor = IcecapJointExit;
    task->step = IcecapJointExecute;
    task->draw = IcecapJointDisplay;
}

/* kill the join in any act but its two. in them, the step does nothing
 * while the camera is beyond the far clip from the model's center */
void IcecapJointExecute(struct task *task)
{
    struct task_work *work = task->work;
    Uint16 act = GetStageNumber();
    NJS_OBJECT *source;
    NJS_OBJECT *object;
    Float distance;

    if (work->mode == JOIN_ACT12) {
        if (act != STAGE_ACT(STAGE_ICECAP, 0) &&
            act != STAGE_ACT(STAGE_ICECAP, 1)) {
            FreeTask(task);
            return;
        }
    } else if (act != STAGE_ACT(STAGE_ICECAP, 1) &&
               act != STAGE_ACT(STAGE_ICECAP, 2)) {
        FreeTask(task);
        return;
    }
    source = VARS(work)->source;
    /* @hack spelling: the distance through a local, which copies it to FR4
     * for the compare (0x0c90e3cc); compared in place, 56 of 112 words
     * differ */
    /* @bug logic: the distance is to the model's center, near the
     * origin, not to the join's center (0x0c90e3c4, 0x0c90e3c6). with the
     * camera within the far clip of the join but beyond it from the origin,
     * the join neither draws nor updates WORLD_TESTED */
    distance = CalcDistance(&camera_twp->pos, &source->model->center);
    if (distance >= _nj_far_clip_) {
        return;
    }
    object = VARS(work)->object;
    if (object != NULL) {
        NJS_POINT3 center;

        center = object->model->center;
        njAddVector(&center, &work->pos);
        object->pos[0] = work->pos.x;
        object->pos[1] = work->pos.y;
        object->pos[2] = work->pos.z;
        object->ang[0] = work->ang.x;
        object->ang[1] = work->ang.y;
        object->ang[2] = work->ang.z;
        if (player_in_range(&center, object->model->r + JOIN_NEAR)) {
            work->flags |= WORLD_TESTED;
        } else {
            work->flags &= ~WORLD_TESTED;
        }
    }
    IcecapJointDisplay(task);
}

/* draw source by its own position and angles. the task's don't move it */
void IcecapJointDisplay(struct task *task)
{
    struct task_work *work = task->work;

    SetObjectTexture();
    late_DrawObject(VARS(work)->source);
}

void IcecapJointExit(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->object != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->object);
        ReleaseMobileLandObject(VARS(work)->object);
    }
}

void ObjectIcecapJoint12(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    if (task->placement != NULL) {
        placement_hold(task);
    }
    work->mode = JOIN_ACT12;
    VARS(work)->source = &icecap_act12_join_object;
    if (!OnEdit(task)) {
        VARS(work)->object = object = GetMobileLandObject();
        object->evalflags = VARS(work)->source->evalflags &
                            ~(NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_SCL);
        object->scl[0] = 1.0F;
        object->scl[1] = 1.0F;
        object->scl[2] = 1.0F;
        object->ang[0] = 0;
        object->ang[1] = 0;
        object->ang[2] = 0;
        object->pos[0] = work->pos.x = VARS(work)->source->pos[0];
        object->pos[1] = work->pos.y = VARS(work)->source->pos[1];
        object->pos[2] = work->pos.z = VARS(work)->source->pos[2];
        object->model = VARS(work)->source->model;
        object->child = VARS(work)->source->child;
        object->sibling = VARS(work)->source->sibling;
        RegisterCollisionEntry(WORLD_SOLID, task, object);
    }
    task->destructor = IcecapJointExit;
    task->step = IcecapJointExecute;
    task->draw = IcecapJointDisplay;
}
