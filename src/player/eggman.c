/* @unit 8C0ED7C0-8C0EE9E0 +r04 +egflags +pool32 +poolafter=eggman_choose_mode,eggman_try_fall +brafpool=eggman_step +poolbra=eggman_step:9,eggman_step:20,eggman_choose_mode:1,eggman_choose_mode:21,eggman_choose_mode:33,eggman_choose_mode:53,eggman_draw:4,eggman_edit:3,eggman_follow_event:3 */
/* Eggman: his player task, on foot, and the edit mode that flies him */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "collision/ground.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "event/event.h"
#include "player/eggman.h"
#include "player/player.h"
#include "player/target.h"
#include "player/textures.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "system/pad.h"
#include "system/task.h"
#include "system/texture.h"
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
void pdExecPeripheralServerUser(void);
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
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void SetEventWork(struct task_work *work);
void ExecEventFace(struct task_work *work);
struct task *CreateEventObject(void);
void EventObject(struct task *task);
extern struct task_work *playertwp[];
extern struct task_motion *playermwp[];
extern struct task *playerpwp[8];
extern Uint8 playerframe[8];
void PAdjustHoldingPosition(struct task_work *work, struct task_motion *motion);
Bool FUN_8c06cd80(struct task_work *work, struct task_motion *motion);
void FUN_8c06d194(struct task_work *work, struct task_motion *motion,
                  struct player *record);
void FUN_8c06f19c(struct task_work *work, struct task_motion *motion,
                  struct player *record);
void PGetAccelerationFly(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void PSetSnowEffect(struct task_work *work, struct task_motion *motion,
                    struct player *record);
void FUN_8c071c80(struct task_work *work, struct task_motion *motion,
                  struct player *record);
void FUN_8c0725ae(struct task_work *work, struct task_motion *motion,
                  struct player *record);
int FUN_8c072a84(struct task_work *work, struct task_motion *motion,
                 struct player *record);
void PResetPositionForBuilding(struct task_work *work,
                               struct task_motion *motion,
                               struct player *record);
void FUN_8c0793b6(struct player_anim *anim);
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
void kmiLogFileOpen(void *data);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
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
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

/* his modes, in work->mode. eggman_mode_names holds the image's name for
 * each */
#define EDIT_X 100.0F
#define EDIT_Y 0.0F
#define EDIT_Z (-600.0F)
enum eggman_mode {
    EGGMAN_INIT,
    EGGMAN_STAND,
    EGGMAN_WALK,
    EGGMAN_PATH,
    EGGMAN_PATH_SPIN,
    EGGMAN_JUMP,
    EGGMAN_SPRING,
    EGGMAN_LAUNCH,
    EGGMAN_FALL,
    EGGMAN_STOP, /* skidding to a stop, with the stick pulled back */
    EGGMAN_PUSH,
    EGGMAN_HURT,
    EGGMAN_BACK,
    EGGMAN_POSE,
    EGGMAN_CRASH, /* thrown back from a wall he ran into */
    EGGMAN_EVENT, /* moved along an event's paths */
    EGGMAN_DOWN,
    EGGMAN_EDIT, /* flown with the pad: X enters it, and A leaves */
    EGGMAN_MODES
};

/* his actions, as indexes into eggman_actions */
enum eggman_action {
    ACTION_STAND = 0,
    ACTION_LAND = 1, /* a landing at a standstill */
    ACTION_WALK = 4,
    ACTION_TROT = 5,
    ACTION_RUN = 6,
    ACTION_SPRINT = 7,
    ACTION_FULL_SPEED = 8,
    ACTION_JUMP = 9,
    ACTION_FALL_START = 12, /* as a rise turns to a fall */
    ACTION_FALL = 13,
    ACTION_SKID = 15,
    ACTION_TURN = 16,
    ACTION_PUSH = 17,
    ACTION_CRASH = 22,
    ACTION_CRASH_LAND = 23,
    ACTION_COUNT = 25 /* eggman_actions' entries, an empty one last */
};

/* where eggman_step's second test for a press of X would put him. the
 * first test sets EGGMAN_EDIT whenever the second's condition holds, so the
 * second never passes */

extern NJS_OBJECT eggman_object;
extern NJS_OBJECT eggman_upper_arm_plus_z;
extern NJS_OBJECT eggman_forearm_plus_z;
extern NJS_OBJECT eggman_hand_plus_z;
extern NJS_OBJECT eggman_fingers_plus_z;
extern NJS_OBJECT eggman_upper_arm_minus_z;
extern NJS_OBJECT eggman_forearm_minus_z;
extern NJS_OBJECT eggman_hand_minus_z;
extern NJS_OBJECT eggman_fingers_minus_z;
extern NJS_OBJECT eggman_thigh_plus_z;
extern NJS_OBJECT eggman_shin_plus_z;
extern NJS_OBJECT eggman_foot_plus_z;
extern NJS_OBJECT eggman_toes_plus_z;
extern NJS_OBJECT eggman_thigh_minus_z;
extern NJS_OBJECT eggman_shin_minus_z;
extern NJS_OBJECT eggman_foot_minus_z;
extern NJS_OBJECT eggman_toes_minus_z;
extern NJS_ACTION eggman_stand_action;
extern NJS_ACTION eggman_walk_action;
extern NJS_ACTION eggman_run_action;
extern NJS_ACTION eggman_skid_action;
extern NJS_ACTION eggman_turn_action;

void eggman_choose_mode(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void eggman_destroy(struct task *task);
void eggman_draw(struct task_work *work, struct task_motion *motion,
                 struct player *record);
void eggman_set_walk_action(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void eggman_edit(struct task_work *work, struct task_motion *motion,
                 struct player *record);
Bool eggman_try_jump(struct task_work *work, struct task_motion *motion,
                     struct player *record);
Bool eggman_follow_event(struct task_work *work, struct task_motion *motion,
                         struct player *record);
Bool eggman_try_request(struct task_work *work, struct task_motion *motion,
                        struct player *record);
Bool eggman_try_fall(struct task_work *work, struct task_motion *motion,
                     struct player *record);
Bool eggman_try_stop(struct task_work *work, struct task_motion *motion,
                     struct player *record);
extern char eggman_mode_names[EGGMAN_MODES][8];
extern struct player_action eggman_actions[ACTION_COUNT];
extern struct collision_shape eggman_shapes[];
extern Uint16 elbow_vertices[10];
extern Uint16 finger_vertices[8];
extern Uint16 knee_vertices[10];
extern Uint16 ankle_vertices[10];
extern Uint16 toe_vertices[16];
extern struct weld eggman_welds[];

/* his step: the mode he's in moves him, then he's posed and drawn. outside
 * EGGMAN_DOWN, eggman_choose_mode first picks the mode. X pressed on pad 0
 * puts him in the edit mode */
void eggman_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    struct player *record = motion->record;

    /* on top of another task's shape, and not rising, he stands on it. his
     * collision record's owner is his own task, so the angles copied from it
     * don't change */
    if ((work->flags & COLLISION_ON_TOP) && motion->speed.y <= 0.0F) {
        work->flags |= PLAYER_ON_TASK;
        work->ang.x = work->collision->owner->work->ang.x;
        work->ang.z = work->collision->owner->work->ang.z;
    }
    if (work->mode != EGGMAN_DOWN) {
        eggman_choose_mode(work, motion, record);
    }
    switch (work->mode) {
    case EGGMAN_INIT:
        PLAYER_VARS(work)->character = CHARACTER_EGGMAN;
        PInitialize(PLAYER_VARS(work)->player, task);
        record = motion->record;
        record->anim.actions = eggman_actions;
        record->anim.action = ACTION_STAND;
        CCL_Init(task, eggman_shapes, COLLISION_PLAYER, 1, 1);
        work->collision->shapes->radius = record->consts.radius;
        work->mode = EGGMAN_STAND;
        texture_load_character(CHARACTER_EGGMAN);
        record->anim.welds = eggman_welds;
        task->destructor = eggman_destroy;
        break;
    case EGGMAN_STAND:
        player_turn_to_stick(work, motion, record);
        FUN_8c06d194(work, motion, record);
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_WALK:
        if (record->anim.previous == ACTION_TURN &&
            record->anim.current != ACTION_TURN) {
            record->speed.x += record->consts.trot_speed;
        }
        FUN_8c06d194(work, motion, record);
        player_apply_accel(work, motion, record);
        if (FUN_8c072a84(work, motion, record) == 2) {
            work->mode = EGGMAN_CRASH;
            record->anim.action = ACTION_CRASH;
            PSetCrashEffect(work);
            record->speed.x = -record->speed.x;
            record->speed.z = -record->speed.z;
            break;
        }
        PResetPosition(work, motion, record);
        eggman_set_walk_action(work, motion, record);
        break;
    case EGGMAN_PATH:
        FUN_8c06f19c(work, motion, record);
        player_apply_path_accel(work, motion, record);
        player_move_on_path(work, motion, record);
        eggman_set_walk_action(work, motion, record);
        break;
    case EGGMAN_PATH_SPIN:
        player_accel_roll(work, motion, record);
        player_apply_path_accel(work, motion, record);
        player_move_on_path(work, motion, record);
        break;
    case EGGMAN_JUMP:
        FUN_8c071c80(work, motion, record);
        if (!player_steer_to_target(work, motion, record)) {
            player_accel_air(work, motion, record);
        }
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_SPRING:
        player_accel_air(work, motion, record);
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_LAUNCH:
        if (record->speed.y >= record->consts.launch_speed) {
            player_accel_launched(work, motion, record);
        } else {
            player_accel_air(work, motion, record);
        }
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_FALL:
        FUN_8c071c80(work, motion, record);
        if (!player_steer_to_target(work, motion, record)) {
            player_accel_air(work, motion, record);
        }
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_STOP:
        player_accel_brake(work, motion, record);
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        /* stopped, with the stick still pointing back, he turns round */
        if (record->speed.x <= 0.0F && FUN_8c06cd80(work, motion)) {
            work->mode = EGGMAN_WALK;
            record->anim.action = ACTION_TURN;
            player_turn_to_stick(work, motion, record);
            work->ang.y = motion->aim.y;
            /* @hack redundant: a redundant break ahead of the case's own, whose
             * jump (BRA at 0x8c0f89aa) has the cases after it call through R3,
             * then R2 (0x8c0f89e0, 0x8c0f89ea); without it, the two trade
             * and 24 of 469 words differ */
            break;
        }
        break;
    case EGGMAN_PUSH:
        FUN_8c06d194(work, motion, record);
        FUN_8c0725ae(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_HURT:
        FUN_8c071c80(work, motion, record);
        FUN_8c06d194(work, motion, record);
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_BACK:
        player_accel_brake(work, motion, record);
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_POSE:
        break;
    case EGGMAN_CRASH:
        player_accel_brake(work, motion, record);
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_EVENT:
        ExecEventPath(work);
        break;
    case EGGMAN_DOWN:
        FUN_8c071c80(work, motion, record);
        player_accel_roll(work, motion, record);
        player_apply_accel(work, motion, record);
        FUN_8c072a84(work, motion, record);
        PResetPosition(work, motion, record);
        break;
    case EGGMAN_EDIT:
        eggman_edit(work, motion, record);
        break;
    }
    FUN_8c0793b6(&record->anim);
    player_update_welds(work, motion, record);
    eggman_draw(work, motion, record);
    if ((perG[0].press & PDD_DGT_TX) && work->mode != EGGMAN_EDIT) {
        work->mode = EGGMAN_EDIT;
        work->flags &= ~(PLAYER_ON_PATH | PLAYER_REQUEST | PLAYER_BALL);
    }
    /* the same test as the one above, which sets EGGMAN_EDIT whenever it
     * passes, so this one never passes */
    if ((perG[0].press & PDD_DGT_TX) && work->mode != EGGMAN_EDIT) {
        work->mode = EGGMAN_EDIT;
        work->pos.x = EDIT_X;
        work->pos.y = EDIT_Y;
        work->pos.z = EDIT_Z;
    }
    CharacterShadow(work, &record->shadow);
    EntryColliList(work);
    player_finish_step(work, motion, record);
}

/* choose his next mode from the one he's in. first his timer counts down.
 * PLAYER_HURT clears while it runs, and PLAYER_RECOILING once it's out. an
 * eggman_try_ call that returns TRUE has settled the mode, and ends the
 * case */
void eggman_choose_mode(struct task_work *work, struct task_motion *motion,
                        struct player *record)
{
    if (work->timer == 0) {
        work->flags &= ~PLAYER_RECOILING;
    } else {
        work->timer--;
        work->flags &= ~PLAYER_HURT;
    }
    switch (work->mode) {
    case EGGMAN_STAND:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        if (eggman_try_fall(work, motion, record)) {
            break;
        }
        if (eggman_try_jump(work, motion, record)) {
            break;
        }
        if (PCheckPower(work, NULL, NULL) || record->speed.x != 0.0F) {
            work->mode = EGGMAN_WALK;
            record->anim.action = ACTION_WALK;
            /* @hack redundant: a redundant break ahead of the case's own, whose
             * jump (BRA at 0x8c0f8c66) takes the action store four arms share
             * at 0x8c0f919c, with ACTION_WALK set in its slot; without it, the
             * arm stores its own and 8 of 687 words differ */
            break;
        }
        break;
    case EGGMAN_WALK:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        if (eggman_try_fall(work, motion, record)) {
            break;
        }
        if (eggman_try_jump(work, motion, record)) {
            break;
        }
        if (eggman_try_stop(work, motion, record)) {
            break;
        }
        /* another task's shape has pushed him at his side. if that shape
         * pushes any group, and he is unhurt and faces it head on, he pushes
         * against it */
        {
            struct collision_work *collision = work->collision;
            int flags = collision->flags;

            if ((flags & COLLISION_PUSHED) && !(work->flags & PLAYER_HURT) &&
                (flags & COLLISION_HIT_SIDE) &&
                (collision->hit->shapes[collision->hit_shape].push &
                 PUSH_ALL)) {
                /* @hack spelling: the wall test as a switch of one case (CMP/EQ
                 * #4,R0 at 0x8c0f8d16), whose stores take ACTION_PUSH in R3
                 * and EGGMAN_PUSH in R2 (0x8c0f8d1c, 0x8c0f8d1e); as an if,
                 * the two trade and 4 of 687 words differ */
                switch (player_face_wall(work, motion)) {
                case PLAYER_WALL_HEAD_ON:
                    work->mode = EGGMAN_PUSH;
                    record->anim.action = ACTION_PUSH;
                    break;
                }
            }
        }
        if (FUN_8c06cd80(work, motion) &&
            record->speed.x >= record->consts.trot_speed) {
            work->mode = EGGMAN_STOP;
            record->anim.action = ACTION_SKID;
            /* @hack redundant: a redundant break ahead of the case's own, whose
             * jump (BRA at 0x8c0f8d46) takes the shared action store at
             * 0x8c0f919c, with ACTION_SKID set in its slot; without it, the
             * arm stores its own and 3 of 687 words differ */
            break;
        }
        break;
    case EGGMAN_PATH:
        work->flags &= ~PLAYER_ATTACKING;
        if (eggman_try_request(work, motion, record)) {
            work->flags &= ~PLAYER_ON_PATH;
            break;
        }
        if (eggman_try_fall(work, motion, record)) {
            work->flags &= ~PLAYER_ON_PATH;
            break;
        }
        if (eggman_try_jump(work, motion, record)) {
            work->flags &= ~PLAYER_ON_PATH;
            break;
        }
        if (record->speed.x < record->consts.trot_speed) {
            work->mode = EGGMAN_WALK;
            record->anim.action = ACTION_WALK;
            work->flags &= ~PLAYER_ON_PATH;
            break;
        }
        if (eggman_try_stop(work, motion, record)) {
            work->flags &= ~PLAYER_ON_PATH;
            /* @hack redundant: a redundant break ahead of the case's own, whose
             * jump (BRA at 0x8c0f8dda) takes the PLAYER_ON_PATH store that ends
             * EGGMAN_PATH_SPIN's arms (0x8c0f8e6a); without it, the arm
             * clears the flag itself and 13 of 687 words differ */
            break;
        }
        break;
    case EGGMAN_PATH_SPIN:
        if (eggman_try_request(work, motion, record)) {
            work->flags &= ~PLAYER_ATTACKING;
            work->flags &= ~PLAYER_ON_PATH;
            break;
        }
        if (eggman_try_fall(work, motion, record)) {
            record->anim.action = ACTION_JUMP;
            record->action_speed = 2.0F;
            work->ang.z = 0;
            work->ang.x = 0;
            work->flags |= PLAYER_ATTACKING;
            work->flags &= ~PLAYER_ON_PATH;
            break;
        }
        if (record->speed.x < PLAYER_SPIN_SPEED) {
            record->anim.action = ACTION_JUMP;
            record->action_speed = 2.0F;
            work->ang.z = 0;
            work->ang.x = 0;
            work->flags |= PLAYER_ATTACKING;
            work->flags &= ~PLAYER_ON_PATH;
            /* @hack redundant: a redundant break ahead of the case's own, which
             * ends this arm with the PLAYER_ON_PATH store that EGGMAN_PATH's
             * arms and this case's first two jump to (0x8c0f8e6a); without
             * it, the store ends the fall's arm instead and 99 of 687 words
             * differ */
            break;
        }
        break;
    case EGGMAN_JUMP:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        if (work->flags & PLAYER_ON_GROUND) {
            if (FUN_8c06cd80(work, motion) && record->speed.x > 0.0F) {
                work->mode = EGGMAN_STOP;
                record->anim.action = ACTION_SKID;
            } else if (eggman_try_stop(work, motion, record)) {
                work->ang.x = motion->aim.x;
                work->ang.z = motion->aim.z;
                record->anim.action = ACTION_LAND;
            } else {
                work->ang.x = motion->aim.x;
                work->ang.z = motion->aim.z;
                work->mode = EGGMAN_WALK;
                eggman_set_walk_action(work, motion, record);
            }
            work->flags &= ~PLAYER_ATTACKING;
            break;
        }
        if (player_count_jump_hold(work, record)) {
            record->speed.y += record->consts.jump_hold_speed * 0.8F;
        }
        if (record->anim.action == ACTION_JUMP && motion->speed.y <= 0.0F) {
            record->anim.action = ACTION_FALL_START;
        }
        break;
    /* @hack spelling: EGGMAN_SPRING's and EGGMAN_LAUNCH's tests kept in
     * cases of their own, as the image holds the test twice (0x8c0f8f80,
     * 0x8c0f8f98). as one case, 153 of eggman_choose_mode's 687 words
     * differ */
    case EGGMAN_SPRING:
        if (motion->speed.y <= 0.0F) {
            work->mode = EGGMAN_FALL;
            record->anim.action = ACTION_FALL_START;
        }
        break;
    case EGGMAN_LAUNCH:
        if (motion->speed.y <= 0.0F) {
            work->mode = EGGMAN_FALL;
            record->anim.action = ACTION_FALL_START;
        }
        break;
    case EGGMAN_FALL:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        if (work->flags & PLAYER_ON_GROUND) {
            if (FUN_8c06cd80(work, motion) && record->speed.x > 0.0F) {
                work->mode = EGGMAN_STOP;
                record->anim.action = ACTION_SKID;
            } else if (eggman_try_stop(work, motion, record)) {
                work->ang.x = motion->aim.x;
                work->ang.z = motion->aim.z;
                record->anim.action = ACTION_LAND;
            } else {
                work->ang.x = motion->aim.x;
                work->ang.z = motion->aim.z;
                work->mode = EGGMAN_WALK;
                eggman_set_walk_action(work, motion, record);
            }
        }
        break;
    case EGGMAN_STOP:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        if (eggman_try_fall(work, motion, record)) {
            break;
        }
        if (eggman_try_jump(work, motion, record)) {
            break;
        }
        if (record->anim.action != ACTION_SKID) {
            work->mode = EGGMAN_STAND;
            record->anim.action = ACTION_STAND;
        }
        break;
    case EGGMAN_PUSH:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        if (eggman_try_jump(work, motion, record)) {
            break;
        }
        if (eggman_try_fall(work, motion, record)) {
            break;
        }
        if (eggman_try_stop(work, motion, record)) {
            break;
        }
        switch (player_stick_into_wall(work, motion)) {
        case PLAYER_WALL_HEAD_ON:
            break;
        case PLAYER_WALL_ASKEW:
            if (!(work->flags & PLAYER_HOLDING)) {
                work->mode = EGGMAN_WALK;
                record->anim.action = ACTION_WALK;
            }
            break;
        default:
            work->mode = EGGMAN_WALK;
            record->anim.action = ACTION_WALK;
            break;
        }
        break;
    case EGGMAN_HURT:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        /* @hack type: the timer read as a Uint16, through TASK_TIMER, which
         * the image widens with EXTU.W ahead of its CMP/EQ #120 (0x8c0f9172).
         * an equality test reads either sign alike. as work->timer, the
         * Sint16 field, 45 of 687 words differ */
        if (TASK_TIMER(work) == PLAYER_HURT_STEPS) {
            break;
        }
        if (work->flags & PLAYER_ON_GROUND) {
            if (eggman_try_stop(work, motion, record)) {
                work->ang.x = motion->aim.x;
                work->ang.z = motion->aim.z;
                record->anim.action = ACTION_LAND;
            } else {
                work->ang.x = motion->aim.x;
                work->ang.z = motion->aim.z;
                work->mode = EGGMAN_WALK;
                eggman_set_walk_action(work, motion, record);
            }
        }
        break;
    case EGGMAN_BACK:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        if (eggman_try_fall(work, motion, record)) {
            break;
        }
        if (eggman_try_jump(work, motion, record)) {
            break;
        }
        if (eggman_try_stop(work, motion, record)) {
            break;
        }
        if (record->speed.x >= 0.0F) {
            work->mode = EGGMAN_WALK;
            eggman_set_walk_action(work, motion, record);
        }
        break;
    case EGGMAN_POSE:
        if (eggman_try_request(work, motion, record)) {
            break;
        }
        break;
    case EGGMAN_CRASH:
        if (eggman_try_fall(work, motion, record)) {
            break;
        }
        /* @hack spelling: the crash's own test and break ahead of the
         * landing's, which have the function keep EGGMAN_WALK's 2 in R10 and
         * ~PLAYER_ON_PATH in R11 (MOV #2,R10 at 0x8c0f8bc8, MOV.W at
         * 0x8c0f8bca); as one test with &&, R8 takes the 2, R10 the mask,
         * and 32 of 687 words differ */
        if (record->anim.action == ACTION_CRASH) {
            break;
        }
        if (record->anim.action != ACTION_CRASH_LAND) {
            work->mode = EGGMAN_STAND;
            record->anim.action = ACTION_STAND;
        }
        break;
    case EGGMAN_EVENT:
        if (work->event->paths == NULL) {
            work->ang.x = motion->aim.x;
            work->ang.z = motion->aim.z;
            work->mode = EGGMAN_STAND;
            record->anim.action = ACTION_STAND;
        }
        break;
    case EGGMAN_EDIT:
        if (perG[0].press & PDD_DGT_TA) {
            work->mode = EGGMAN_WALK;
            record->anim.action = ACTION_WALK;
        }
        break;
    }
}

void eggman_destroy(struct task *task)
{
    /* @hack spelling: task->work read into a local, which the image stores in a
     * frame of its own (ADD #-4,R15 and MOV.L R3,@R15 at 0x8c0f9300,
     * 0x8c0f9306); read in place, 13 of 14 words differ */
    struct task_work *work = task->work;

    PDestruct(PLAYER_VARS(work)->player);
    ReleasePlayersTexture(CHARACTER_EGGMAN);
}

/* draw him from his middle, and center his shape there. neither happens
 * while his timer is odd, so he blinks as it runs. in the edit mode,
 * holding X draws his model unposed */
void eggman_draw(struct task_work *work, struct task_motion *motion,
                 struct player *record)
{
    NJS_VECTOR offset;
    NJS_POINT3 pos;
    struct collision_shape *shape;
    int action;

    action = record->anim.action;
    if (record->anim.state == PLAYER_ANIM_BLENDING) {
        action = record->anim.current;
    }
    /* @hack type: the timer read as a Uint16, through TASK_TIMER, which the
     * image widens with EXTU.W ahead of its TST #1 (0x8c0f9364). a bit test
     * reads either sign alike. as work->timer, the Sint16 field, 139 of 217
     * words differ */
    if (TASK_TIMER(work) & 1) {
        return;
    }
    draw_set_palette(DRAW_PLAYER_PALETTE);
    njSetTexture_jp(&eggman_texlist);
    njPushMatrix(NULL);
    offset.x = offset.z = 0.0F;
    offset.y = record->consts.height * 0.5F;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, -work->ang.y);
    njCalcVector(NULL, &offset, &pos);
    late_DrawObjectClipEx(1);
    pos.x += work->pos.x;
    pos.y += work->pos.y;
    pos.z += work->pos.z;
    njTranslateV(NULL, &pos);
    shape = work->collision->shapes;
    shape->center.x = pos.x;
    shape->center.y = pos.y;
    shape->center.z = pos.z;
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, NJM_DEG_ANG(180) - work->ang.y);
    if (work->event->motions != NULL) {
        event_motions_draw(work);
    } else if ((perG[0].on & PDD_DGT_TX) && work->mode == EGGMAN_EDIT) {
        late_DrawObject(
            record->anim.actions[record->anim.action].action->object);
    } else if (record->anim.state != 2) {
        ds_ActionClip(record->anim.actions[action].action, record->anim.frame);
    } else {
        ds_ActionClip(record->anim.blend, record->anim.frame);
    }
    late_DrawObjectClipEx(1);
    draw_set_palette(0);
}

/* the walk or the run his speed calls for, and how fast it plays */
void eggman_set_walk_action(struct task_work *work, struct task_motion *motion,
                            struct player *record)
{
    Float speed = record->speed.x + (motion->slip * 5.0F);

    if (speed > record->consts.full_speed) {
        record->anim.action = ACTION_FULL_SPEED;
    } else if (speed > record->consts.sprint_speed) {
        record->anim.action = ACTION_SPRINT;
    } else if (speed > record->consts.running_speed) {
        record->anim.action = ACTION_RUN;
    } else if (speed > record->consts.trot_speed) {
        record->anim.action = ACTION_TROT;
    } else {
        record->anim.action = ACTION_WALK;
    }
    record->action_speed = record->speed.x + (motion->slip * 20.0F);
}

/* fly him PLAYER_EDIT_SPEED a step the way the stick points, turned by the
 * camera's heading. while X is held, the stick moves him up and down
 * instead. B puts him back where the stage places him */
void eggman_edit(struct task_work *work, struct task_motion *motion,
                 struct player *record)
{
    Float x;
    Float y;
    Float sign;
    Angle ang;

    if (perG[0].press & PDD_DGT_TB) {
        stage_place_player(work);
    }
    if (perG[0].on & PDD_DGT_TX) {
        x = (Float)(perG[PLAYER_VARS(work)->player].x1 << 8);
        y = (Float)(perG[PLAYER_VARS(work)->player].y1 << 8);
        if (x > PAD_DEAD_ZONE || x < -PAD_DEAD_ZONE || y > PAD_DEAD_ZONE ||
            y < -PAD_DEAD_ZONE) {
            sign = y != 0.0F ? y / njSqrt(y * y) : 0.0F;
            work->pos.y -= sign * PLAYER_EDIT_SPEED;
        }
        return;
    }
    x = (Float)(perG[PLAYER_VARS(work)->player].x1 << 8);
    y = (Float)(perG[PLAYER_VARS(work)->player].y1 << 8);
    if (x > PAD_DEAD_ZONE || x < -PAD_DEAD_ZONE || y > PAD_DEAD_ZONE ||
        y < -PAD_DEAD_ZONE) {
        ang = (Angle)(njArcTan2(y, x) * ANGLE_PER_RADIAN) - camera_twp->ang.y;
        work->pos.x += njCos(ang) * PLAYER_EDIT_SPEED;
        work->pos.z += njSin(ang) * PLAYER_EDIT_SPEED;
    }
}

/* jump as player_jump_pressed says to: up at his jump speed, plus the
 * speed of the task he stands on. TRUE when he jumps */
Bool eggman_try_jump(struct task_work *work, struct task_motion *motion,
                     struct player *record)
{
    if (player_jump_pressed(work, record)) {
        work->mode = EGGMAN_JUMP;
        if (record->ground_task != NULL) {
            struct task_force *force = record->ground_task->force;

            if (force != NULL) {
                player_set_accel(PLAYER_VARS(work)->player, force->speed.x,
                                 force->speed.y, force->speed.z);
            }
        }
        record->speed.y = record->consts.jump_speed;
        record->anim.action = ACTION_JUMP;
        record->action_speed = 2.0F;
        work->flags &= ~PLAYER_ON_TASK;
        work->flags |= PLAYER_ATTACKING;
        record->jump_steps = 0;
        dsPlay_oneshot(SE_JUMP, 0, 0, 0);
        return TRUE;
    }
    return FALSE;
}

/* follow the event's action: let it move him, or turn as it says. TRUE
 * for an action he takes. for any other, PLAYER_EVENT_DRIVEN clears, and
 * the result is FALSE */
Bool eggman_follow_event(struct task_work *work, struct task_motion *motion,
                         struct player *record)
{
    struct event_work *event = work->event;

    switch (event->action) {
    case EVENT_ACTION_RUN:
    case EVENT_ACTION_MOVE:
    case EVENT_ACTION_PUSH:
    case EVENT_ACTION_DONE:
        work->flags |= PLAYER_EVENT_DRIVEN;
        break;
    case EVENT_ACTION_TURN_TO:
        player_set_heading(PLAYER_VARS(work)->player, event->move.ang.y);
        break;
    case EVENT_ACTION_TURN_BY:
        player_set_heading(PLAYER_VARS(work)->player,
                           event->move.ang.y + work->ang.y);
        break;
    default:
        work->flags &= ~PLAYER_EVENT_DRIVEN;
        return FALSE;
    }
    return TRUE;
}

/* TRUE while something outside holds his mode: an event's paths, which put
 * him in EGGMAN_EVENT, or PLAYER_REQUEST. while the event's record holds an
 * action, he follows it, and the result is FALSE */
Bool eggman_try_request(struct task_work *work, struct task_motion *motion,
                        struct player *record)
{
    if (work->event->action) {
        eggman_follow_event(work, motion, record);
        return FALSE;
    }
    if (work->event->paths != NULL) {
        work->mode = EGGMAN_EVENT;
        work->flags &= ~PLAYER_ATTACKING;
        work->flags &= ~PLAYER_ON_PATH;
        return TRUE;
    }
    if (!(work->flags & PLAYER_REQUEST)) {
        return FALSE;
    }
    return TRUE;
}

/* TRUE once he is off the ground, with his mode set to EGGMAN_FALL, or to
 * EGGMAN_JUMP while he's curled up */
Bool eggman_try_fall(struct task_work *work, struct task_motion *motion,
                     struct player *record)
{
    if (!(work->flags & PLAYER_ON_GROUND)) {
        /* @hack redundant: an empty else, whose jump has the fall's stores take
         * ACTION_FALL in R3 and EGGMAN_FALL in R2 (0x8c0f9940, 0x8c0f9942);
         * without it, the two trade and 4 of 21 words differ */
        if (work->flags & PLAYER_BALL) {
            work->mode = EGGMAN_JUMP;
            return TRUE;
        } else {
        }
        work->mode = EGGMAN_FALL;
        record->anim.action = ACTION_FALL;
        return TRUE;
    }
    return FALSE;
}

/* TRUE once he is still with the stick let go, with his mode set to
 * EGGMAN_STAND */
Bool eggman_try_stop(struct task_work *work, struct task_motion *motion,
                     struct player *record)
{
    if (!PCheckPower(work, NULL, NULL) && record->speed.x == 0.0F) {
        work->mode = EGGMAN_STAND;
        record->anim.action = ACTION_STAND;
        return TRUE;
    }
    return FALSE;
}
