/* @unit 0C905180-0C9055C0 +r04 +egflags +pool32 */
/* RollUpR, RollUpL and RollDownL, the platforms on the tables that turn
 * about y */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/world.h"
#include "draw/model.h"
#include "object/common.h"
#include "player/player.h"
#include "stg09/casino.h"
#include "stg09/roll_up.h"
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void SetMleriRangeRad(Float radius);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
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
Uint16 GetStageNumber(void);
Bool ChkPause(void);
extern Uint8 seqVars[512];
extern Sint8 evExecFlag[512];
extern int evfade;
void SeqCtrl(void);
void story_save_wait(void);
void main(void);
void SeqEndSection(void);
void SeqEvent(int event);
void SeqSetFlag(int flag);
Bool SeqCheckFlag(int flag);
Bool SeqCheckStage(int stage, int act);
void SeqChangeStage(int stage, int act);
Bool SeqCheckNextStage(Uint8 stage, Uint8 act);
Bool SeqCheckClearAction(int stage);
extern struct save SaveData[3];
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
extern struct AdvertiseWork AdvertiseWork;
Bool thunk_FUN_8c081ba6(void);
struct task *thunk_FUN_8c081bec(void);
struct task *thunk_FUN_8c08395e(struct battle *battle);
struct task *thunk_FUN_8c083ebc(struct battle *battle);
void thunk_FUN_8c083f7e(struct battle *battle);
Sint16 thunk_FUN_8c0829cc(int frames);
Sint16 thunk_FUN_8c082b9a(int unused);
void ObjectMovableSRegularExecute(struct task *task);
void ObjectMovableMRegularExecute(struct task *task);
void ObjectSetupInput(struct task_work *work, struct task_motion *motion);
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
int thunk_FUN_8c09cbc0(char *name, void *dest);
void FUN_0c90547a(struct task *task);
void FUN_0c90553e(struct task *task);
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

#define VARS(work) ((struct roll_up_vars *)&(work)->vars)
#define ROLL_UP_WORLD (WORLD_MEDIUM | WORLD_SOLID)
#define ROLL_DOWN_WORLD (WORLD_MEDIUM | WORLD_DEFLECT | WORLD_SOLID)
#define ROLL_UP_RIGHT_TURN 0x80
#define ROLL_UP_LEFT_TURN 0x200
#define ROLL_DOWN_LEFT_SWING 0x200
#define ROLL_UP_LEFT_WAIT 60
#define ROLL_DOWN_LEFT_WAIT 30
#define STOP_ANGLE(ang) ((ang) & 0xff00)
extern NJS_MODEL roll_up_right_model_0;
extern NJS_MODEL roll_up_right_model_1;
extern NJS_MODEL roll_up_right_model_2;
extern NJS_MODEL roll_up_right_model_3;
extern NJS_MODEL roll_up_right_model_4;
extern NJS_MODEL roll_up_right_model_5;
extern NJS_MODEL roll_up_left_model_0;
extern NJS_MODEL roll_up_left_model_1;
extern NJS_MODEL roll_down_left_model_0;
extern NJS_MODEL roll_down_left_model_1;
extern NJS_MODEL roll_down_left_model_2;
extern NJS_OBJECT roll_up_right_object;
extern NJS_OBJECT roll_up_left_object;
extern NJS_OBJECT roll_down_left_object;

struct roll_up_vars {
    NJS_OBJECT *object; /* the platform's copy in the collision world */
    Angle swing; /* RollDownL's phase, whose sine sets its y angle */
    Sint32 wait; /* steps left to stay stopped */
};

/* each platform's turn or swing phase a step, and the steps RollUpL and
 * RollDownL stay stopped */

/* ang within its turn, rounded down to a multiple of 0x100. RollUpL and
 * RollDownL stop where it is a quarter turn */

void roll_up_destroy(struct task *task)
{
    NJS_OBJECT *object = VARS(task->work)->object;

    WithdrawCollisionEntry(task, object);
    ReleaseMobileLandObject(object);
}

void roll_up_right_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    casino_set_texture(CASINO_TEXTURES_ACTS_34);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&roll_up_right_model_0);
    ds_DrawModelClip(&roll_up_right_model_1);
    ds_DrawModelClip(&roll_up_right_model_2);
    ds_DrawModelClip(&roll_up_right_model_3);
    ds_DrawModelClip(&roll_up_right_model_4);
    ds_DrawModelClip(&roll_up_right_model_5);
    late_DrawObjectClipEx(1);
}

void roll_up_left_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    casino_set_texture(CASINO_TEXTURES_ACTS_34);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&roll_up_left_model_0);
    ds_DrawModelClip(&roll_up_left_model_1);
    late_DrawObjectClipEx(1);
}

void roll_down_left_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    casino_set_texture(CASINO_TEXTURES_ACTS_34);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&roll_down_left_model_0);
    ds_DrawModelClip(&roll_down_left_model_1);
    ds_DrawModelClip(&roll_down_left_model_2);
    late_DrawObjectClipEx(1);
}

void roll_up_right_run(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = VARS(work)->object;

    if (player_in_range(&work->pos, object->model->r + 20.0F)) {
        work->flags |= WORLD_TESTED;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
    work->ang.y = object->ang[1] = work->ang.y + ROLL_UP_RIGHT_TURN;
    roll_up_right_draw(task);
    /* @hack redundant: a return where the function ends, which makes the frame
     * with ADD #-4,R15 and stores task in it across player_in_range
     * (0x0c905926, 0x0c90592c). without it, a push does both, and 38 of 39
     * words differ */
    /* NOLINTNEXTLINE(readability-redundant-control-flow) */
    return;
}

void roll_up_left_run(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = VARS(work)->object;
    Angle quarter;

    if (player_in_range(&work->pos, object->model->r + 20.0F)) {
        work->flags |= WORLD_TESTED;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
    if (VARS(work)->wait) {
        VARS(work)->wait--;
    } else {
        work->ang.y = object->ang[1] = work->ang.y - ROLL_UP_LEFT_TURN;
        /* the turn keeps the angle's remainder by ROLL_UP_LEFT_TURN. the
         * platform stops only if that remainder is under 0x100 */
        quarter = STOP_ANGLE(work->ang.y);
        if (quarter == 0 || quarter == NJM_DEG_ANG(90) ||
            quarter == NJM_DEG_ANG(180) || quarter == NJM_DEG_ANG(270)) {
            VARS(work)->wait = ROLL_UP_LEFT_WAIT;
        }
    }
    roll_up_left_draw(task);
    /* @hack redundant: a return where the function ends, which makes the frame
     * with ADD #-4,R15 and stores task in it across player_in_range
     * (0x0c905974, 0x0c90597a). without it, a push does both, and 23 of 62
     * words differ */
    /* NOLINTNEXTLINE(readability-redundant-control-flow) */
    return;
}

/* the swing sets RollDownL's y angle, from 0 to -360 degrees, in place of
 * its set entry's */
void roll_down_left_run(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = VARS(work)->object;
    Angle quarter;

    if (player_in_range(&work->pos, object->model->r + 20.0F)) {
        work->flags |= WORLD_TESTED;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
    if (VARS(work)->wait) {
        VARS(work)->wait--;
    } else {
        VARS(work)->swing += ROLL_DOWN_LEFT_SWING;
        quarter = STOP_ANGLE(VARS(work)->swing);
        if (quarter == NJM_DEG_ANG(90) || quarter == NJM_DEG_ANG(270)) {
            VARS(work)->wait = ROLL_DOWN_LEFT_WAIT;
        }
    }
    work->ang.y = object->ang[1] =
        (Angle)(njSin(VARS(work)->swing) * (180.0F * ANGLE_PER_DEGREE)) -
        NJM_DEG_ANG(180);
    roll_down_left_draw(task);
    /* @hack redundant: a return where the function ends, which makes the frame
     * with ADD #-4,R15 and stores task in it across player_in_range
     * (0x0c905a12, 0x0c905a18). without it, a push does both, and 23 of 68
     * words differ */
    /* NOLINTNEXTLINE(readability-redundant-control-flow) */
    return;
}

void FUN_0c90547a(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    VARS(work)->object =
        object_add_world(&roll_up_right_object, task, ROLL_UP_WORLD);
    object = VARS(work)->object;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    task->step = roll_up_right_run;
    task->draw = roll_up_right_draw;
    task->destructor = roll_up_destroy;
}

void roll_up_left_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    VARS(work)->object =
        object_add_world(&roll_up_left_object, task, ROLL_UP_WORLD);
    object = VARS(work)->object;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    VARS(work)->wait = 0;
    task->step = roll_up_left_run;
    task->draw = roll_up_left_draw;
    task->destructor = roll_up_destroy;
}

void FUN_0c90553e(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    VARS(work)->object =
        object_add_world(&roll_down_left_object, task, ROLL_DOWN_WORLD);
    object = VARS(work)->object;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    task->step = roll_down_left_run;
    task->draw = roll_down_left_draw;
    task->destructor = roll_up_destroy;
}
