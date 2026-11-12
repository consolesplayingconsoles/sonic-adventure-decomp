/* @unit 8C05BC40-8C05CFE0 @data 8C154A7C-8C154B6C +r04 +egflags +pool32 */
/* the iron balls. O IRON BALL, or O IRONB, is a joint that rides up and
 * down. one or two arms of chain turn round it, each with an iron ball at
 * its end. O IRON BALL JG, or O FeBJG, is a lone ball that rises off the
 * ground and drops back with a thud. this file calls it a jg */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "collision/ground.h"
#include "collision/mesh.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "effect/dust.h"
#include "object/common.h"
#include "object/iron_ball.h"
#include "object/models.h"
#include "object/placement.h"
#include "object/ring.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "stg03/mirror.h"
#include "system/task.h"
#include "system/texture.h"
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
void *syMalloc_default_malloc(size_t size);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void FreeTask(struct task *task);
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
void CharacterShadow(struct task_work *work, struct shadow *shadow);
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke2(struct dust_params *params);
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
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
void FUN_8c05c7f2(struct task *task);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
struct task *createMirrorTask(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
void OnConstantAttr(Uint32 and_attr, Uint32 or_attr);
void SaveControl3D(void);
void LoadControl3D(void);
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* each turning ball plays SE_IRON_BALL, and a jg plays SE_THUD as it lands */
#define SE_IRON_BALL 700
#define SE_THUD 701

/* the world flags of the joint's copy: solid, and of the size
 * model_start_world gives a model of radius 3 to 10 */
#define JOINT_FLAGS (WORLD_MEDIUM | WORLD_SOLID)

/* world_collect_near_players takes the joint's copy only while a player is
 * within the radius of its model plus JOINT_NEAR */
#define JOINT_NEAR 20.0F

/* the joint's submode, which iron_ball_setup takes from the last three
 * digits of the whole part of scl.z, as the set editor labels them. a ones
 * digit other than 0 sets IRON_BALL_ONE. a tens digit of 1 to 8 sets
 * IRON_BALL_NO_SHADOW, and one of 9 sets IRON_BALL_HEAVY_SHADOW, which
 * only the set editor reads. a hundreds digit other than 0 sets
 * IRON_BALL_NO_CHAIN */
#define IRON_BALL_ONE 0x1 /* one arm, not two */
#define IRON_BALL_NO_SHADOW 0x2 /* the balls draw no shadow */
#define IRON_BALL_NO_CHAIN 0x4 /* the arms step and draw no links */
#define IRON_BALL_HEAVY_SHADOW 0x10

/* the phase of the joint's ride advances RIDE_STEP a step, and
 * RIDE_SPEED_STEP more for each thousand in its scl.z */
#define RIDE_STEP 0x100
#define RIDE_SPEED_STEP 0x200

/* iron_ball_setup holds the arms' length, scl.x, from ARM_LENGTH_LEAST to
 * ARM_LENGTH_MOST, and their turn a step to ARM_TURN_MOST either way */
#define ARM_LENGTH_LEAST (-5.0F)
#define ARM_LENGTH_MOST 50.0F
#define ARM_TURN_MOST NJM_DEG_ANG(22.5)

/* an arm's first link hangs FIRST_LINK out from the joint, and the rest
 * LINK_SPACING apart */
#define FIRST_LINK 6.0F
#define LINK_SPACING 4.0F

/* how far out from the joint an arm's ball hangs */
#define BALL_REACH(joint) ((((joint)->scl.x + 6.0F) * LINK_SPACING) + 16.0F)
/* the set editor draws marker_cylinder_object, 20 across, at this scale
 * across: a radius 10 short of BALL_REACH */
#define EDIT_SCALE(joint) ((((joint)->scl.x + 6.0F) * 0.4F) + 0.6F)

/* a ball's submode: how it looks for the ground under it */
#define BALL_NO_PROBE 0x2 /* it never looks */
#define BALL_GROUNDED 0x8 /* it has found the ground, and looks no more */
#define BALL_PROBE_NOW 0x10 /* it looks every step */

/* outside the set editor, a ball looks for the ground every
 * BALL_PROBE_STEPS steps until it finds some. in the set editor, it looks
 * every step */
#define BALL_PROBE_STEPS 40

/* a jg on moving ground counts down in its submode from JG_PROBE_COUNT.
 * the step that takes the count past 0 looks for the ground, and starts
 * the count again. so the jg looks every JG_PROBE_COUNT + 1 steps, and
 * only while the camera is within JG_PROBE_RANGE */
#define JG_PROBE_COUNT 8
#define JG_PROBE_RANGE 400.0F

/* a jg on moving ground follows a change in the ground's height of less
 * than JG_GROUND_SHIFT between two looks. a change of JG_GROUND_SHIFT or
 * more sends it flying, for JG_FLY_STEPS steps */
#define JG_GROUND_SHIFT 8.0F
#define JG_FLY_STEPS 120

/* a jg waits at the top and on the ground until its count passes JG_WAIT.
 * dropping, its speed gains JG_FALL a step, up to JG_FALL_MOST */
#define JG_WAIT 30
#define JG_FALL 0.1F
#define JG_FALL_MOST 4.0F

/* the joint's vars. its work's submode holds IRON_BALL_* flags, its
 * unsigned timer the ride's phase, and its ang.y the arms' turn a step.
 * scl.x sets the arms' length, and scl.y the ride's height. scl.z holds the
 * IRON_BALL_* digits, and in its thousands the ride's speed */
#define VARS(work) ((struct iron_ball_vars *)&(work)->vars)
#define PART(work) ((struct iron_ball_part_vars *)&(work)->vars)
#define JG(work) ((struct iron_ball_jg_vars *)&(work)->vars)
#define GROUND(work) ((work)->scl.z)
#define REACH(work) ((work)->scl.x)
#define TWISTED(work) ((work)->scl.y)
#define RANGE(work) ((work)->scl.x)
#define RISE(work) ((work)->scl.y)
#define LIFT(work) ((work)->scl.z)
#define ON_MOVING_GROUND(work) ((work)->ang.z == 1)
#define FLIGHT(work) ((work)->scl)
struct iron_ball_vars {
    /* what the joint draws: its copy in the world, or while the set editor
     * holds it, iron_ball_joint_object */
    NJS_OBJECT *object;
    union {
        NJS_OBJECT *joint; /* iron_ball_joint_object, until iron_ball_setup */
        Float y; /* from iron_ball_setup on: pos.y as placed, the ride's foot */
    } base;
};

/* an arm's or a link's vars. an arm's task is its ball, and the links of
 * its chain are its children */
struct iron_ball_part_vars {
    NJS_OBJECT *object;
};

/* a jg's vars. its submode counts the steps to its next look for the
 * ground, -1 for never */
struct iron_ball_jg_vars {
    NJS_OBJECT *object;
    Float ground; /* the height of the ground under it */
};

/* the height of the ground under a ball, in its scl.z. the ball's unsigned
 * timer counts the steps since it last looked. its ang.x and ang.z take the
 * ground's slope, which tilts its shadow, and its ang.y is the arm's turn
 * round the joint */
/* how far out from the joint a link hangs, in its scl.x */
/* nonzero on every other link, which draws turned a quarter turn about z */

/* a jg rises RANGE above the ground at RISE a step, and stands LIFT above
 * it now: its scl.x, scl.y and scl.z */
/* a jg placed with ang.z 1 stands on ground that moves */
/* a flying jg's speed. iron_ball_jg_fly sets its x and z from the jg's
 * heading in ang.x */

/* a jg's work->mode */
enum jg_mode {
    JG_RISE, /* rises to RANGE */
    JG_UP, /* waits at the top */
    JG_DROP, /* drops, faster each step, and lands */
    JG_DOWN /* waits on the ground */
};

/* a jg's work->mode once iron_ball_jg_fly is its step */
enum jg_fly_mode { JG_FLY_START = 0, JG_FLY = 1, JG_FLY_END = 4 };
void iron_ball_setup(struct task_work *work);
void ObjectIronBallDisplay(struct task *task);
static void iron_ball_step(struct task *task);
void ObjectIronBallExit(struct task *task);
void ChildIronBall(struct task *task);
void ChildIronBallDisplayer(struct task *task);

static void iron_ball_arm_step(struct task *task);
static void iron_ball_part_destroy(struct task *task);
void iron_ball_link_init(struct task *task);
void iron_ball_link_draw(struct task *task);
void iron_ball_link_step(struct task *task);
void iron_ball_jg_step(struct task *task);
void iron_ball_jg_draw(struct task *task);
static void iron_ball_jg_destroy(struct task *task);
static void iron_ball_jg_fly(struct task *task);
void SpreadSmoke(NJS_POINT3 *pos, Float radius, Uint8 count, Float scale);
extern struct collision_shape iron_ball_shape;
extern struct collision_shape iron_ball_link_shape;
/* clang-format on */

void ObjectIronBall(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    VARS(work)->base.joint = &iron_ball_joint_object;
    if (!OnEdit(task)) {
        object = GetMobileLandObject();
        VARS(work)->object = object;
        object->evalflags = NJD_EVAL_BREAK;
        object->scl[0] = 1.0F;
        object->scl[1] = 1.0F;
        object->scl[2] = 1.0F;
        object->ang[0] = work->ang.x;
        object->ang[1] = work->ang.y;
        object->ang[2] = work->ang.z;
        object->pos[0] = work->pos.x;
        object->pos[1] = work->pos.y;
        object->pos[2] = work->pos.z;
        object->model = VARS(work)->base.joint->model;
        object->child = VARS(work)->base.joint->child;
        object->sibling = VARS(work)->base.joint->sibling;
        RegisterCollisionEntry(JOINT_FLAGS, task, object);
    } else {
        VARS(work)->object = VARS(work)->base.joint;
    }
    iron_ball_setup(work);
    CreateChildTask(0x2, ChildIronBall, task);
    if (!(work->submode & 0x1)) {
        CreateChildTask(0x2, ChildIronBall, task);
        if (task->child != ((void *)0) && task->child->next != ((void *)0)) {
            task->child->work->ang.y =
                task->child->next->work->ang.y + NJM_DEG_ANG(180);
        }
    }
    task->destructor = ObjectIronBallExit;
    task->step = iron_ball_step;
    task->draw = ObjectIronBallDisplay;
}

/* keep pos.y as the ride's foot, hold the arms' length and turn to their
 * limits, and set the submode from scl.z */
void iron_ball_setup(struct task_work *work)
{
    int digits;

    work->submode = 0;
    VARS(work)->base.y = work->pos.y;
    if (work->scl.x > ARM_LENGTH_MOST) {
        work->scl.x = ARM_LENGTH_MOST;
    }
    if (work->scl.x < ARM_LENGTH_LEAST) {
        work->scl.x = ARM_LENGTH_LEAST;
    }
    work->ang.y &= 0xffff;
    if (work->ang.y <= 0x7fff && work->ang.y > ARM_TURN_MOST) {
        work->ang.y = ARM_TURN_MOST;
    }
    if (work->ang.y >= 0x8000 && work->ang.y < 0x10000 - ARM_TURN_MOST) {
        work->ang.y = 0x10000 - ARM_TURN_MOST;
    }
    digits = work->scl.z;
    digits = njAbs(digits % 1000);
    if (digits >= 100) {
        work->submode |= IRON_BALL_NO_CHAIN;
    }
    digits = digits % 100;
    if (digits >= 10) {
        if (digits >= 90) {
            work->submode |= IRON_BALL_HEAVY_SHADOW;
        } else {
            work->submode |= IRON_BALL_NO_SHADOW;
        }
    }
    digits = digits % 10;
    if (digits >= 1) {
        work->submode |= IRON_BALL_ONE;
    }
}

void ObjectIronBallDisplay(struct task *task)
{
    struct task_work *work = task->work;

    SaveConstantAttr();
    OffConstantAttr(0, NJD_FLAG_IGNORE_SPECULAR);
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    ds_DrawModelClip(VARS(work)->object->model);
    late_DrawObjectClipEx(1);
    LoadConstantAttr();
}

/* ride up and down, and keep the joint's copy in the world with it. in the
 * set editor, show the settings and the ride instead, and follow the
 * settings as they change */
static void iron_ball_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;
    Float y;
    Float size;

    if (CheckRangeOut(task)) {
        return;
    }
    ObjectIronBallDisplay(task);
    if (!OnEdit(task)) {
        work->pos.y = VARS(work)->base.y + (work->scl.y * 0.5F) +
                      (work->scl.y * njSin(TASK_TIMER(work)) * 0.5F);
        TASK_TIMER(work) +=
            ((int)(work->scl.z * 0.001F) * RIDE_SPEED_STEP) + RIDE_STEP;
        object = VARS(work)->object;
        object->pos[0] = work->pos.x;
        object->pos[1] = work->pos.y;
        object->pos[2] = work->pos.z;
        object->ang[0] = work->ang.x;
        object->ang[1] = work->ang.y;
        object->ang[2] = work->ang.z;
        if (player_in_range(&work->pos, object->model->r + JOINT_NEAR)) {
            work->flags |= WORLD_TESTED;
        } else {
            work->flags &= ~WORLD_TESTED;
        }
    } else {
        y = VARS(work)->base.y + (work->scl.y * 0.5F) +
            (work->scl.y * njSin(TASK_TIMER(work)) * 0.5F);
        TASK_TIMER(work) +=
            ((int)(work->scl.z * 0.001F) * RIDE_SPEED_STEP) + RIDE_STEP;
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "-> ROTATION Y SPEED");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "-> ARM LENGTH");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "-> Y TRANS RANGE");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "-> 1000 Y TRANS SPEED");
        njPrintC(NJM_LOCATION(21, 22), "100 CHANE");
        njPrintC(NJM_LOCATION(22, 23), "10 SHADOW");
        njPrintC(NJM_LOCATION(23, 24), "1 IRONBALL");
        if (work->submode & IRON_BALL_NO_CHAIN) {
            njPrintC(NJM_LOCATION(34, 22), "OFF");
        } else {
            njPrintC(NJM_LOCATION(34, 22), "ON");
        }
        if (work->submode & IRON_BALL_NO_SHADOW) {
            njPrintC(NJM_LOCATION(34, 23), "OFF");
        } else if (work->submode & IRON_BALL_HEAVY_SHADOW) {
            njPrintC(NJM_LOCATION(34, 23), "HEAVY");
        } else {
            njPrintC(NJM_LOCATION(34, 23), "LITE");
        }
        if (work->submode & IRON_BALL_ONE) {
            njPrintC(NJM_LOCATION(34, 24), "ONE");
        } else {
            njPrintC(NJM_LOCATION(34, 24), "TWO");
        }
        iron_ball_setup(work);
        if (!(work->submode & 0x1)) {
            if (task->child != ((void *)0) &&
                task->child->next == ((void *)0)) {
                CreateChildTask(0x2, ChildIronBall, task);
                task->child->work->ang.y =
                    task->child->next->work->ang.y + NJM_DEG_ANG(180);
            }
        } else if (task->child != NULL && task->child->next != NULL) {
            DestroyTask(task->child->next);
        }
        /* draw a cylinder as tall as the ride, then a flat one at the
         * joint's height */
        size = EDIT_SCALE(work);
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x,
                    VARS(work)->base.y + (work->scl.y * 0.5F), work->pos.z);
        njScale(NULL, size, work->scl.y * 0.05F, size);
        SetMaterial(0.1F, 0.4F, 1.0F, 0.2F);
        late_DrawObject(&object_cylinder01);
        late_DrawObjectClipEx(1);
        size = EDIT_SCALE(work);
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, y, work->pos.z);
        njScale(NULL, size, 0.1F, size);
        SetMaterial(0.1F, 1.0F, 0.4F, 0.8F);
        late_DrawObject(&object_cylinder01);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
    LoopTaskC(task);
}

/* take the joint's copy out of the world and back to the pool. in the set
 * editor, object is iron_ball_joint_object, which the task never put in
 * the world and the pool doesn't hold, so neither call changes anything */
void ObjectIronBallExit(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->object != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->object);
        ReleaseMobileLandObject(VARS(work)->object);
    }
    FreeTaskC(task);
}

/* start an arm and its chain's links, which number the joint's scl.x + 7,
 * rounded up */
void ChildIronBall(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *joint;
    struct task *child;
    Float reach;
    int i;

    PART(work)->object = &iron_ball_object;
    /* @hack spelling: a select in place of an if, which loads the 1 that
     * unused and count both take into R2 at the call (MOV #1,R2 at
     * 0x8c05f47c). as an if, SHC hoists the 1 into R12 ahead of the call,
     * and 71 of 88 words differ */
    OnEdit(task) ? (void)0
                 : CCL_Init(task, &iron_ball_shape, COLLISION_OBJECT, 1, 1);
    joint = task->parent->work;
    reach = FIRST_LINK;
    for (i = 0; i < joint->scl.x + 7.0F; i++) {
        child = CreateChildTask(TASK_WORK, iron_ball_link_init, task);
        if (child != NULL) {
            REACH(child->work) = reach;
            if (i & 1) {
                TWISTED(child->work) = 1.0F;
            }
        }
        reach += LINK_SPACING;
    }
    task->destructor = iron_ball_part_destroy;
    task->step = iron_ball_arm_step;
    task->draw = ChildIronBallDisplayer;
}

/* draw the ball, turned with the joint, and its shadow on the ground under
 * it, unless the joint has IRON_BALL_NO_SHADOW */
void ChildIronBallDisplayer(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *joint = task->parent->work;
    NJS_POINT3 shadow;

    SaveConstantAttr();
    OffConstantAttr(0, NJD_FLAG_IGNORE_SPECULAR);
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, joint->ang.z);
    TURN(njRotateX, joint->ang.x);
    TURN(njRotateY, work->ang.y + NJM_DEG_ANG(45));
    late_DrawObject(PART(work)->object);
    late_DrawObjectClipEx(1);
    LoadConstantAttr();
    if (!(joint->submode & IRON_BALL_NO_SHADOW)) {
        shadow.x = work->pos.x;
        shadow.y = GROUND(work);
        shadow.z = work->pos.z;
        shadow_draw_at(&work->ang, &shadow, 1.2F);
    }
}

/* put the ball at the arm's end, turned with the joint, and look for the
 * ground under it. then turn the arm a step further round */
static void iron_ball_arm_step(struct task *task)
{
    struct task_work *joint = task->parent->work;
    struct task_work *work = task->work;
    NJS_VECTOR offset;

    offset.x = offset.y = 0.0F;
    offset.z = BALL_REACH(joint);
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, joint->ang.z);
    TURN(njRotateX, joint->ang.x);
    TURN(njRotateY, work->ang.y);
    njCalcVector(NULL, &offset, &work->pos);
    njAddVector(&work->pos, &joint->pos);
    late_DrawObjectClipEx(1);
    if (!(work->submode & BALL_NO_PROBE)) {
        if (work->submode & BALL_PROBE_NOW) {
            TASK_TIMER(work) = BALL_PROBE_STEPS;
        } else if (!(work->submode & BALL_GROUNDED)) {
            TASK_TIMER(work)++;
        }
        if (TASK_TIMER(work) >= BALL_PROBE_STEPS) {
            GROUND(work) =
                GetShadowPos(work->pos.x, work->pos.y, work->pos.z, &work->ang);
            if (GROUND(work) != -GROUND_FAR) {
                work->submode |= BALL_GROUNDED;
            }
            TASK_TIMER(work) = 0;
        }
    }
    if (OnEdit(task)) {
        GROUND(work) =
            GetShadowPos(work->pos.x, work->pos.y, work->pos.z, &work->ang);
    } else {
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
        /* the work's address is the sound's id, so each ball keeps a slot
         * of its own */
        dsPlay_Dolby_time(SE_IRON_BALL, (int)work, 1, 0, work->pos.x,
                          work->pos.y, work->pos.z, 2);
    }
    ChildIronBallDisplayer(task);
    if (!(joint->submode & IRON_BALL_NO_CHAIN)) {
        LoopTaskC(task);
    }
    work->ang.y += joint->ang.y;
}

void iron_ball_part_destroy(struct task *task)
{
}

/* start a link of an arm's chain. the arm steps it, unless the joint has
 * IRON_BALL_NO_CHAIN */
void iron_ball_link_init(struct task *task)
{
    struct task_work *work = task->work;

    PART(work)->object = &iron_ball_link_object;
    if (!OnEdit(task)) {
        CCL_Init(task, &iron_ball_link_shape, COLLISION_OBJECT, 1, 1);
    }
    task->destructor = iron_ball_part_destroy;
    task->step = iron_ball_link_step;
    task->draw = iron_ball_link_draw;
}

void iron_ball_link_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *arm = task->parent->work;
    struct task_work *joint = task->parent->parent->work;

    if (joint->submode & IRON_BALL_NO_CHAIN) {
        return;
    }
    SaveConstantAttr();
    OffConstantAttr(0, NJD_FLAG_IGNORE_SPECULAR);
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, joint->ang.z);
    TURN(njRotateX, joint->ang.x);
    TURN(njRotateY, arm->ang.y);
    if (TWISTED(work) != 0.0F) {
        njRotateZ(NULL, NJM_DEG_ANG(90));
    }
    ds_DrawModelClip(PART(work)->object->model);
    late_DrawObjectClipEx(1);
    LoadConstantAttr();
}

/* put the link REACH out along its arm, turned with the joint */
void iron_ball_link_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *arm = task->parent->work;
    struct task_work *joint = task->parent->parent->work;
    NJS_VECTOR offset;

    offset.x = offset.y = 0.0F;
    offset.z = REACH(work);
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, joint->ang.z);
    TURN(njRotateX, joint->ang.x);
    TURN(njRotateY, arm->ang.y);
    njCalcVector(NULL, &offset, &work->pos);
    njAddVector(&work->pos, &joint->pos);
    late_DrawObjectClipEx(1);
    if (!OnEdit(task)) {
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
    }
    iron_ball_link_draw(task);
}

void FUN_8c05c7f2(struct task *task)
{
    struct task_work *work = task->work;

    JG(work)->object = &iron_ball_object;
    if (!OnEdit(task)) {
        CCL_Init(task, &iron_ball_shape, COLLISION_OBJECT, 1, 1);
    }
    JG(work)->ground = work->pos.y;
    RANGE(work) = njAbs(RANGE(work));
    RISE(work) = njAbs(RISE(work));
    task->destructor = iron_ball_jg_destroy;
    task->step = iron_ball_jg_step;
    task->draw = iron_ball_jg_draw;
    /* on moving ground, the jg looks for the ground, its count started at
     * ring_stagger, so that rings and jgs look on different steps. elsewhere,
     * it never looks */
    if (ON_MOVING_GROUND(work)) {
        work->submode = ring_stagger;
        ring_stagger++;
        if (ring_stagger > RING_PROBE_COUNT) {
            ring_stagger = 0;
        }
    } else {
        work->submode = -1;
    }
    if (GetStageNumber() == STAGE_TWINKLE_MIRRORS) {
        createMirrorTask(task);
    }
}

/* rise to RANGE and wait, then drop and wait on the ground. the jg lands
 * with a thud and a ring of dust. on moving ground, it follows the ground's
 * height, and flies off once the ground shifts JG_GROUND_SHIFT or more. in
 * the set editor, it follows no ground, and shows the settings and its
 * rise */
void iron_ball_jg_step(struct task *task)
{
    struct task_work *work = task->work;
    Float speed;
    Float dx;
    Float dy;
    Float dz;
    Float height;
    Float rise;
    struct angles slope;
    Float top;
    Float scale;

    if (CheckRangeOut(task)) {
        return;
    }
    RANGE(work) = njAbs(RANGE(work));
    RISE(work) = njAbs(RISE(work));
    switch (work->mode) {
    case JG_RISE:
        LIFT(work) += RISE(work);
        if (LIFT(work) >= RANGE(work)) {
            LIFT(work) = RANGE(work);
            work->mode = JG_UP;
            TASK_TIMER(work) = 0;
        }
        break;
    case JG_UP:
        if (TASK_TIMER(work)++ > JG_WAIT) {
            work->mode = JG_DROP;
            TASK_TIMER(work) = 0;
        }
        break;
    case JG_DROP:
        speed = TASK_TIMER(work) * JG_FALL;
        if (speed > JG_FALL_MOST) {
            speed = JG_FALL_MOST;
        }
        LIFT(work) -= speed;
        if (LIFT(work) <= 0.0F) {
            LIFT(work) = 0.0F;
            work->mode = JG_DOWN;
            TASK_TIMER(work) = 0;
            SpreadSmoke(&work->pos, 12.0F, 16, 1.0F);
            dsPlay_oneshot_v(SE_THUD, 0, 0, 0, work->pos.x, work->pos.y,
                             work->pos.z);
        } else {
            TASK_TIMER(work)++;
        }
        break;
    case JG_DOWN:
    default:
        if (TASK_TIMER(work)++ > JG_WAIT) {
            work->mode = JG_RISE;
            TASK_TIMER(work) = 0;
        }
        break;
    }
    if (!OnEdit(task)) {
        if (work->submode >= 0) {
            work->submode--;
            if (work->submode == -1) {
                work->submode = JG_PROBE_COUNT;
                dx = camera_twp->pos.x - work->pos.x;
                dy = camera_twp->pos.y - work->pos.y;
                dz = camera_twp->pos.z - work->pos.z;
                if (vector_length_squared(dx, dy, dz) <
                    JG_PROBE_RANGE * JG_PROBE_RANGE) {
                    height = GetShadowPos(work->pos.x, work->pos.y + 10.0F,
                                          work->pos.z, &slope);
                    rise = height - JG(work)->ground;
                    if (njAbs(rise) < JG_GROUND_SHIFT) {
                        JG(work)->ground = height;
                    } else {
                        task->step = iron_ball_jg_fly;
                        work->mode = JG_FLY_START;
                    }
                }
            }
        }
        work->pos.y = LIFT(work) + JG(work)->ground;
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
    } else {
        JG(work)->ground = work->pos.y;
        /* @hack spelling: top worked out ahead of the prints, which SHC keeps
         * at
         * @(4,R15) across them (FMOV.S FR2,@(R0,R15) at 0x8c05fd96).
         * worked out at the translate, the stack frame is 44 bytes, not 48,
         * and 120 of 334 words differ */
        top = LIFT(work) + JG(work)->ground;
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "-> ROTATION Y");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Z), "=1:Ground Move");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "-> Y TRANS RANGE");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "-> Y TRANS SPEED");
        njPrintC(NJM_LOCATION(17, 22), "Be Sure To Land");
        /* a cylinder spans the jg's rise, and a sphere marks its height */
        scale = RANGE(work) * 0.05F;
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, JG(work)->ground + (RANGE(work) * 0.5F),
                    work->pos.z);
        njScale(NULL, 1.0F, scale, 1.0F);
        SetMaterial(0.1F, 0.4F, 1.0F, 0.2F);
        late_DrawObject(&object_cylinder01);
        late_DrawObjectClipEx(1);
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, top, work->pos.z);
        SetMaterial(0.1F, 1.0F, 0.4F, 0.8F);
        late_DrawObject(&object_sphere01);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
    iron_ball_jg_draw(task);
    LoopTaskC(task);
}

/* draw the ball, and its shadow on the ground, smaller the higher the ball
 * is */
void iron_ball_jg_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 shadow;

    SaveConstantAttr();
    OffConstantAttr(0, NJD_FLAG_IGNORE_SPECULAR);
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(JG(work)->object);
    late_DrawObjectClipEx(1);
    LoadConstantAttr();
    shadow.x = work->pos.x;
    shadow.y = JG(work)->ground + SHADOW_LIFT;
    shadow.z = work->pos.z;
    shadow_draw_at(
        &work->ang, &shadow,
        2.0F / ((njAbs(work->pos.y - JG(work)->ground) * 0.03F) + 1.0F));
}

static void iron_ball_jg_destroy(struct task *task)
{
}

/* fly off a random way, spinning and bouncing on the ground below, for
 * JG_FLY_STEPS steps, then kill the task */
static void iron_ball_jg_fly(struct task *task)
{
    struct task_work *work = task->work;
    struct angles slope;

    switch (work->mode) {
    case JG_FLY_START:
        work->mode = JG_FLY;
        /* a random heading, from 0 to just short of a whole turn */
        work->ang.x = rand() * 1.9999999F;
        FLIGHT(work).y = 2.4F;
        TASK_TIMER(work) = JG_FLY_STEPS;
        iron_ball_jg_draw(task);
        break;
    case JG_FLY:
        work->submode--;
        if (work->submode == -1) {
            work->submode = JG_PROBE_COUNT;
            JG(work)->ground =
                GetShadowPos(work->pos.x, work->pos.y, work->pos.z, &slope);
        }
        work->ang.y += 0x444;
        TASK_TIMER(work)--;
        /* @hack spelling: the timer <= 0, which for the unsigned timer is
         * == 0, keeps the image's EXTU.W and CMP/PL (0x8c0600b6,
         * 0x8c0600b8). as == 0, SHC tests with a TST, and 79 of 137 words
         * differ */
        if (TASK_TIMER(work) <= 0) {
            work->mode = JG_FLY_END;
        }
        FLIGHT(work).x = njSin(work->ang.x) * 2.0F;
        FLIGHT(work).z = njCos(work->ang.x) * 2.0F;
        FLIGHT(work).y -= 0.12F;
        work->pos.x += FLIGHT(work).x;
        work->pos.y += FLIGHT(work).y;
        work->pos.z += FLIGHT(work).z;
        if (JG(work)->ground >= work->pos.y) {
            FLIGHT(work).y *= -0.8F;
        }
        iron_ball_jg_draw(task);
        break;
    case JG_FLY_END:
        DeadOut(task);
        break;
    }
}

/* throw count puffs of dust of scale out and up from a ring of radius round
 * pos. scale scales their speed too */
void SpreadSmoke(NJS_POINT3 *pos, Float radius, Uint8 count, Float scale)
{
    NJS_VECTOR thrown = {0.0F, 0.25F, 2.0F};
    NJS_POINT3 offset = {0.0F, 0.0F, 0.0F};
    NJS_POINT3 point;
    NJS_VECTOR speed;
    Angle step;
    Angle ang;
    Uint8 i;

    step = 0x10000 / count;
    offset.z = radius;
    ang = 0;
    njPushMatrix(NULL);
    njUnitMatrix(NULL);
    thrown.y *= scale;
    thrown.z *= scale;
    /* each pass turns the matrix by ang on top of the passes before, so puff
     * i stands step * i * (i + 1) / 2 round the ring, not step * i. for the
     * count of 16 the one caller passes, those are the same 16 places in
     * another order */
    for (i = 0; i < count; i++, ang += step) {
        TURN(njRotateY, ang);
        njCalcPoint(NULL, &offset, &point);
        njCalcVector(NULL, &thrown, &speed);
        point.x += pos->x;
        point.y += pos->y;
        point.z += pos->z;
        CreateSmoke(&point, &speed, scale);
    }
    late_DrawObjectClipEx(1);
}
