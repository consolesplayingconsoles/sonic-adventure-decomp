/* @unit 8C019360-8C01C480 +r04 +egflags +pool32 +poolafter=camera_disable_collisions,FUN_8c01957e,camera_run_mode,sphere_holds_player,plane_crossed_by_player,camera_place_at_angles,CameraSetEventCameraFunc,CameraSetCollisionCameraFunc,camera_restore_high,camera_reset_steps,camera_settle_adjust,FUN_8c01b554,push_out_of_sphere,FUN_8c01b900 +poolbra=camera_task_step:2,camera_start_or_end_survey:j3,test_at_area:4,test_at_area:13,test_at_event:j2,camera_enter_collision:1,camera_leave_collision:2,camera_override_mode:2,camera_push_out:3,push_out_of_block:7,FUN_8c01c2d8:1 +brafpool=FUN_8c01b5e0 +asmfunc=FUN_8c01995e,camera_apply_view,FUN_8c01b900,FUN_8c01bd9e,camera_task_step,FUN_8c01c2d8 */
/* the camera task: its modes and their levels, the act's collisions that
 * pick them, the overrides, and the tint under water */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "camera/camera.h"
#include "camera/editor.h"
#include "camera/layouts.h"
#include "collision/polygon.h"
#include "collision/world.h"
#include "draw/draw.h"
#include "draw/light.h"
#include "main.h"
#include "player/player.h"
#include "stage/stage.h"
#include "system/pad.h"
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
void FUN_8c6094be(NJS_CACTION *caction, Float frame);
void FUN_8c63e114(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
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
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
void FUN_8c01937c(Angle ang);
void FUN_8c01957e(void);
void FUN_8c01a680(struct task_work *work);
void FUN_8c01a7a4(NJS_VECTOR *offset);
void FUN_8c01aae0(Sint16 mode, Uint8 adjust);
int FUN_8c01b406(void);
Bool FUN_8c01b5e0(void);
void AmyBalanceGameStartChecker(struct camera_view *view);
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
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void FUN_8c0130f8(void);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
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
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
void *syMalloc_default_malloc(size_t size);
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

/* the field of view the camera starts at */
#define PERSPECTIVE NJM_DEG_ANG(70)
/* the most the FIXED modes move the field of view toward PERSPECTIVE in a
 * call */
#define PERSPECTIVE_STEP 18

/* the d-pad starts the look round; a face button ends it, as a stick does */
#define SURVEY_START (PDD_DGT_KU | PDD_DGT_KD | PDD_DGT_KL | PDD_DGT_KR)
#define SURVEY_END (PDD_DGT_TA | PDD_DGT_TB | PDD_DGT_TX | PDD_DGT_TY)
/* the pad starts the survey only once camera_restored_steps passes this */
#define SURVEY_DELAY 10

/* the adjust modes run only once camera_steps passes this */
#define ADJUST_DELAY 60

/* a change between two collisions of at least this priority takes adjust
 * mode NONE */
#define PRIORITY_HIGH 10

/* the steps player 0 loses control for when the view cuts */
#define CUT_STEPS 30

/* the collisions test player 0 at this height above his feet */
#define TEST_HEIGHT 4.0F

/* player 0 is still while he is on land and moves less than STILL_MOVE in
 * a step. the camera is still while it moves less than STILL_MOVE in a
 * step, and turns less than STILL_TURN about each axis */
#define STILL_MOVE 0.1F
#define STILL_TURN NJM_DEG_ANG(0.5)

/* the steps camera_ease takes */
#define EASE_STEPS 30

/* a height past any water, above the camera or below it */
#define NO_WATER 1000000.0F

/* the camera task's work mode */
#define SAVE_SLOT(slot)                                                        \
    do {                                                                       \
        /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */                      \
        camera_control->saved_level[slot] = camera_control->level;             \
        camera_control->saved_collision[slot] = camera_control->collision;     \
        camera_control->saved_flags[slot] = camera_control->flags;             \
        camera_control->saved_mode[slot] = camera_control->mode;               \
        camera_control->saved_step[slot] = camera_control->step;               \
        /* @bug memory: with collision -1, as camera_set_mode and the          \
         * overrides leave it, the adjust mode is read from                    \
         * camera_collisions[-1] (MOV.B @(2,R0),R0 at 0x8c01b9f2 and           \
         * 0x8c01ba0c in camera_set_mode). in an act's layout that is the      \
         * entry holding the count, whose byte 2 is 0 for any count up to      \
         * CAMERA_COLLISIONS_MAX, so the slot keeps adjust mode NONE */        \
        camera_control->saved_adjust[slot] =                                   \
            camera_collisions[camera_control->collision].adjust;               \
        camera_control->saved_adjust_step[slot] =                              \
            camera_adjusts[camera_collisions[camera_control->collision]        \
                               .adjust]                                        \
                .step;                                                         \
    } while (0)
#define RESTORE_SLOT(slot)                                                     \
    do {                                                                       \
        camera_control->collision = camera_control->saved_collision[slot];     \
        camera_control->flags = camera_control->saved_flags[slot];             \
        camera_control->mode = camera_control->saved_mode[slot];               \
        camera_control->step = camera_control->saved_step[slot];               \
        camera_control->adjust = camera_control->saved_adjust[slot];           \
        camera_control->adjust_step = camera_control->saved_adjust_step[slot]; \
        camera_control->level = camera_control->saved_level[slot];             \
    } while (0)
#define PLAYER_INSIDE(inside, collision)                                       \
    do {                                                                       \
        switch ((collision)->type) {                                           \
        case CAMCOL_SPHERE:                                                    \
            (inside) = sphere_holds_player(collision);                         \
            break;                                                             \
        case CAMCOL_BLOCK:                                                     \
            (inside) = block_holds_player(collision);                          \
            break;                                                             \
        default:                                                               \
            (inside) = FALSE;                                                  \
        }                                                                      \
    } while (0)
void FUN_8c01c29a(void);
void FUN_8c01c2d8(void);
enum camera_task_mode { CAMERA_TASK_INIT, CAMERA_TASK_START, CAMERA_TASK_RUN };

/* camera_action_state's values */
enum action_state {
    ACTION_NONE,
    ACTION_ASKED, /* camera_play_action gave one since the camera's last step */
    /* the camera's last step played one, which its next ends unless
     * camera_play_action gives one again */
    ACTION_PLAYED
};
extern struct camera_place camera_place;
extern Uint8 dat_8c6c0a30[4];
extern Bool camera_player_still;
extern NJS_VECTOR camera_moved;
extern struct task_work camera_last_record;
extern struct cameraControlWork camera_state_record;
extern Uint8 dat_8c6c0ad8[12];
extern struct camera_control camera_control_record;
extern struct camera_view camera_step_view;
extern struct camera_view camera_override_view;
extern struct camera_adjust_work camera_adjust_record;
extern Sint16 camera_stage;
extern Sint16 camera_act;
extern Sint16 camera_mode_count;
extern struct camera_mode *camera_modes;
extern Sint16 camera_adjust_count;
extern struct camera_adjust_mode *camera_adjusts;
extern Sint32 *camera_collision_count;
extern struct camera_collision *camera_collisions;
extern Angle camera_perspective;
extern Sint32 camera_action_state;
extern NJS_CACTION *camera_action;
extern Float camera_action_frame;
extern Uint32 camera_steps;
extern Uint32 camera_restored_steps;
extern Sint32 camera_start_mode;
extern Sint32 camera_restore_mode;
extern Sint32 camera_restore_adjust;
extern Bool camera_cut;
extern Sint32 camera_step_count;
extern struct task_work *camera_take_work;
extern Uint8 dat_8c6c0c30[4];
extern NJS_POINT3 camera_player_last;
extern NJS_POINT3 camera_last_pos;
extern Bool camera_in_dry_box;
extern struct task_work *const camera_last;
extern struct cameraControlWork *const cameraControlWork;
extern struct camera_control *const camera_control;
extern struct camera_adjust_work *const camera_adjust;
extern const NJS_VECTOR start_above;
extern const char user_function_name[];
extern struct task_work *camera_twp;
extern Bool camera_collisions_on;
extern NJS_PLANE collision_plane;
extern char camera_level_labels[CAMERA_LEVELS][16];
extern Sint32 camera_ease_left;
extern NJS_COLOR tint_colors[4];

void camera_start_at_player(void);
void camera_set_default_mode(void);
void camera_task_destroy(struct task *task);
void camera_task_draw(struct task *task);
void camera_task_step(struct task *task);
void FUN_8c01995e(void);
void camera_start_or_end_survey(void);
void test_at_normal(Sint16 index, struct camera_collision *collision);
void test_at_area(Sint16 index, struct camera_collision *collision);
void test_at_event(Sint16 index, struct camera_collision *collision);
void camera_run_mode(struct task_work *work);
void camera_apply_view(struct task_work *work);
Bool sphere_holds_player(struct camera_collision *collision);
Bool plane_crossed_by_player(struct camera_collision *collision);
Bool block_holds_player(struct camera_collision *collision);
void camera_pick_next_mode(void);
void camera_enter_collision(Sint8 mode, Sint16 index);
void camera_leave_collision(void);
void camera_override_mode_high(Sint16 mode, Uint8 adjust);
void camera_view_from_collision(struct camera_collision *collision);
void camera_mode_change_step(struct task *task);
void camera_settle_adjust(struct task_work *work, struct task_work *last);
void camera_note_player_still(void);
void FUN_8c01b554(void);
Bool sphere_holds(const struct camera_collision *collision,
                  const NJS_POINT3 *point);
Bool push_out_of_sphere(struct camera_collision *collision, NJS_POINT3 *pos);
Bool push_out_of_block(struct camera_collision *collision, NJS_POINT3 *pos);
void FUN_8c01bd9e(void);
void camera_task_draw_tint(struct task *task);
void FUN_8c01c29a(void);
void FUN_8c01c2d8(void);

void camera_set_start_mode(Sint8 mode)
{
    /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
    camera_start_mode = mode;
}

void camera_set_restore_mode(Sint8 mode, Sint8 adjust)
{
    /* NOLINTBEGIN(bugprone-signed-char-misuse) */
    camera_restore_mode = mode;
    camera_restore_adjust = adjust;
    /* NOLINTEND(bugprone-signed-char-misuse) */
}

Angle camera_get_perspective(void)
{
    return camera_perspective;
}

void FUN_8c01937c(Angle ang)
{
    int adjust;

    switch (camera_control->mode) {
    case CAMERA_MODE_FIXED:
    case CAMERA_MODE_A_FIXED:
    case CAMERA_MODE_C_FIXED:
        /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
        adjust = camera_control->adjust;
        /* @hack redundant: the label ease, which starts a block that keeps
         * angle_approach's address in R2 (0x8c01a208, 0x8c01a20e); without it
         * and its jump, R1, and 2 of 34 words differ */
        goto ease;
    ease:
        if (adjust != CAMERA_ADJUST_NONE) {
            camera_perspective =
                AdjustAngle(camera_perspective, PERSPECTIVE, PERSPECTIVE_STEP);
        } else {
            camera_perspective = PERSPECTIVE;
        }
        break;
    default:
        camera_perspective = ang;
        break;
    }
    njSetPerspective(camera_perspective);
}

Bool camera_collisions_enabled(void)
{
    return camera_collisions_on;
}

void camera_enable_collisions(void)
{
    camera_collisions_on = TRUE;
}

void camera_disable_collisions(void)
{
    camera_collisions_on = FALSE;
}

/* start the camera at player 0. it looks at a point 7.5 above his feet,
 * from 20 above that point along his up, moved 3 in x and in z */
void camera_start_at_player(void)
{
    NJS_VECTOR up;

    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y = playertwp[0]->pos.y + 7.5F;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    cameraControlWork->ang_x = 0;
    cameraControlWork->ang_y = 0;
    cameraControlWork->ang_z = 0;
    cameraControlWork->distance = 50.0F;
    up = start_above;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, playertwp[0]->ang.z);
    TURN(njRotateX, playertwp[0]->ang.x);
    TURN(njRotateY, 0x4000 - playertwp[0]->ang.y);
    njCalcVector(NULL, &up, &up);
    late_DrawObjectClipEx(1);
    cameraControlWork->pos.x = cameraControlWork->target.x + up.x + 3.0F;
    cameraControlWork->pos.y = cameraControlWork->target.y + up.y;
    cameraControlWork->pos.z = cameraControlWork->target.z + up.z + 3.0F;
    FUN_8c01a680(camera_twp);
    camera_steps = 0;
    camera_restored_steps = 0;
}

/* keep what the camera runs, to go back to as a level's mode ends. slot is
 * that level. the slot keeps the collision's adjust mode, not the one
 * running */

/* go back to what slot keeps */

/* run the mode of the act's first collision at CAMERA_LEVEL_NORMAL, with
 * adjust mode NONE. it sets CAMERA_VIEW_GIVEN, so the mode's step reads
 * camera_override_view, not the collision's view */
void camera_set_default_mode(void)
{
    camera_control->level = CAMERA_LEVEL_NORMAL;
    camera_control->collision = 0;
    camera_control->mode = camera_collisions->mode;
    camera_control->step = camera_modes[camera_control->mode].step;
    camera_control->adjust = CAMERA_ADJUST_NONE;
    camera_control->adjust_step = camera_adjusts[CAMERA_ADJUST_NONE].step;
    camera_adjust->steps = 0;
    camera_control->type = camera_modes[camera_control->mode].type;
    camera_control->changed = TRUE;
    camera_control->flags = CAMERA_VIEW_GIVEN;
}

void FUN_8c01957e(void)
{
    struct task *task = CreateElementalTask(TASK_WORK, 0, camera_task_step);

    camera_stage = GetStageNumber();
    camera_act = (Uint8)camera_stage;
    camera_stage >>= 8;
    camera_mode_count = camera_mode_table.mode_count;
    camera_modes = camera_mode_table.modes;
    camera_adjust_count = camera_mode_table.adjust_count;
    camera_adjusts = camera_mode_table.adjusts;
    camera_collision_count = (Sint32 *)camera_layouts[camera_stage][camera_act];
    camera_collisions = camera_layouts[camera_stage][camera_act] + 1;
    camera_set_default_mode();
    task->destructor = camera_task_destroy;
    task->draw = camera_task_draw;
    camera_action_state = ACTION_NONE;
    camera_start_mode = -1;
    camera_restore_mode = -1;
    /* @hack spelling: one statement, which keeps njSetPerspective a JSR ahead
     * of the return (0x8c01a526); as two, the call becomes a tail jump and
     * 12 of 73 words differ */
    camera_perspective = PERSPECTIVE, njSetPerspective(PERSPECTIVE);
}

void camera_create_advertise(void)
{
    struct task *task = CreateElementalTask(TASK_WORK, 0, camera_task_step);

    camera_mode_count = camera_mode_table.mode_count;
    camera_modes = camera_mode_table.modes;
    camera_adjust_count = camera_mode_table.adjust_count;
    camera_adjusts = camera_mode_table.adjusts;
    camera_collision_count = &camera_advertise_layout.count;
    camera_collisions = camera_advertise_layout.collisions;
    camera_control->level = CAMERA_LEVEL_NORMAL;
    camera_control->collision = 0;
    camera_control->mode = CAMERA_MODE_ADVERTISE;
    camera_control->step = camera_modes[CAMERA_MODE_ADVERTISE].step;
    camera_control->adjust = CAMERA_ADJUST_NONE;
    camera_control->adjust_step = camera_adjusts[CAMERA_ADJUST_NONE].step;
    camera_adjust->steps = 0;
    camera_control->type = CAMERA_FROM_TARGET;
    camera_control->changed = TRUE;
    camera_control->flags = 0;
    task->destructor = camera_task_destroy;
    task->draw = camera_task_draw;
    /* @hack spelling: one statement, which keeps njSetPerspective a JSR ahead
     * of the return (0x8c01a62e); as two, the call becomes a tail jump, 23
     * of 76 words differ and camera.c's code runs 32 bytes short */
    camera_perspective = PERSPECTIVE, njSetPerspective(PERSPECTIVE);
}

void camera_task_destroy(struct task *task)
{
    camera_twp = NULL;
}

void camera_task_draw(struct task *task)
{
    struct task_work *work = task->work;

    camera_apply_view(work);
}

void camera_change_act(Sint16 by)
{
    if (stage_playing()) {
        camera_act += by;
        camera_collision_count =
            (Sint32 *)camera_layouts[camera_stage][camera_act];
        camera_collisions = camera_layouts[camera_stage][camera_act] + 1;
        camera_set_default_mode();
        camera_steps = 0;
        camera_restored_steps = 0;
    }
}

/* the first step takes the work, the next starts the camera at player 0,
 * and each step after runs the collisions, the mode and the view */
void camera_task_step(struct task *task)
{
    struct task_work *work = task->work;
    int adjust;

    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    switch (work->mode) {
    case CAMERA_TASK_INIT:
        camera_twp = work;
        work->mode = CAMERA_TASK_START;
        camera_collisions_on = TRUE;
        break;
    case CAMERA_TASK_START:
        if (camera_start_mode != -1) {
            FUN_8c01aae0(camera_start_mode, 0);
        }
        camera_start_at_player();
        camera_run_mode(work);
        camera_apply_view(work);
        work->mode = CAMERA_TASK_RUN;
        task->draw = camera_task_draw_tint;
        FUN_8c01c29a();
        break;
    case CAMERA_TASK_RUN:
        camera_step_count++;
        if (camera_action_state == ACTION_PLAYED) {
            camera_action_state = ACTION_NONE;
            CameraReleaseEventCamera();
        }
        camera_note_player_still();
        FUN_8c01b554();
        FUN_8c01995e();
        if (!camera_control->changed) {
            camera_control->steps++;
        } else {
            camera_control->steps = 0;
            camera_control->changed = FALSE;
            /* @hack spelling: the adjust mode held in adjust, where the test
             * could read camera_control->adjust. the local keeps
             * camera_action_state's address in R12 and 0 in R13 (0x8c01a76a,
             * 0x8c01a778), and has the test take a copy in R4 (MOV R0,R4 at
             * 0x8c01a7ac); read in the test, 61 of 137 words differ */
            /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
            adjust = camera_control->adjust;
            /* @hack redundant: the jump to cut, where control goes anyway,
             * which puts camera_cut's address in R2 and player_get's in R3
             * (0x8c01a7b2, 0x8c01a7ba); without it, the two trade and 5 of
             * 137 words differ */
            goto cut;
        cut:
            if (adjust == CAMERA_ADJUST_NONE && camera_cut) {
                struct player *player = GetPlayerWorkPointer(0);

                player->launch_steps = CUT_STEPS;
            }
        }
        camera_cut = FALSE;
        camera_run_mode(work);
        camera_apply_view(work);
        FUN_8c01bd9e();
        camera_settle_adjust(work, camera_last);
        FUN_8c01c2d8();
        camera_pick_next_mode();
        if (camera_action_state == ACTION_ASKED) {
            camera_action_state = ACTION_PLAYED;
        }
        break;
    }
    ++camera_steps;
    ++camera_restored_steps;
}

/* give the camera the mode of a collision player 0 is in, by the rules of
 * the level the camera runs at. the collisions are tested from the last
 * down to the second, and again from the last whenever the level drops */
void FUN_8c01995e(void)
{
    struct camera_collision *collision;
    Uint16 stage;
    Sint16 i;
    Sint8 level;

    if (!camera_collisions_on) {
        return;
    }
    camera_start_or_end_survey();
    if (camera_control->mode == CAMERA_MODE_SURVEY) {
        return;
    }
    stage = GetStageNumber();
    if (!camera_layouts[stage >> 8][stage & 0xff]) {
        return;
    }
restart:
    collision = &camera_collisions[*camera_collision_count - 1];
    level = camera_control->level;
    for (i = *camera_collision_count - 1; i > 0; i--, collision--) {
        if (camera_modes[collision->mode].level >= camera_control->level) {
            switch (camera_control->level) {
            case CAMERA_LEVEL_NORMAL:
                if (camera_modes[collision->mode].level != CAMERA_LEVEL_COLI) {
                    test_at_normal(i, collision);
                }
                break;
            case CAMERA_LEVEL_AREA:
            case CAMERA_LEVEL_COMP:
                if (camera_modes[collision->mode].level != CAMERA_LEVEL_COLI) {
                    test_at_area(i, collision);
                }
                break;
            case CAMERA_LEVEL_EVENT:
                test_at_event(i, collision);
                break;
            }
            if (camera_control->level < level) {
                goto restart;
            }
        }
    }
}

/* start or end the survey, the pad's look round. the d-pad starts it at
 * NORMAL, AREA or COMP while camera_player_still is set, once
 * camera_restored_steps passes SURVEY_DELAY. it doesn't in the three
 * ASHLAND_I modes or the three FIXED modes. a face button, the stick, or
 * camera_player_still clear ends it, with adjust mode TIME. each call counts
 * camera_restored_steps once more */
void camera_start_or_end_survey(void)
{
    ++camera_restored_steps;
    /* @hack spelling: the end tested in two arms of one chain, which SHC builds
     * twice (0x8c01a9c4, 0x8c01aa60); tested in one, 103 of 108 words differ
     * and the code runs 64 bytes short */
    if (!(perG[0].on & SURVEY_START)) {
        if (camera_control->mode == CAMERA_MODE_SURVEY) {
            if ((perG[0].on & SURVEY_END) || ((perG[0].x1 << 8) != 0) ||
                ((perG[0].y1 << 8) != 0) || !camera_player_still) {
                camera_restore_high();
                camera_set_adjust(CAMERA_ADJUST_TIME);
            }
        }
    } else if (camera_control->mode != CAMERA_MODE_SURVEY &&
               camera_control->level != CAMERA_LEVEL_EVENT &&
               camera_player_still) {
        switch (camera_control->mode) {
        case CAMERA_MODE_ASHLAND_I:
        case CAMERA_MODE_A_ASHLAND_I:
        case CAMERA_MODE_C_ASHLAND_I:
        case CAMERA_MODE_FIXED:
        case CAMERA_MODE_A_FIXED:
        case CAMERA_MODE_C_FIXED:
            break;
        default:
            if (camera_restored_steps > 30 &&
                camera_control->level != CAMERA_LEVEL_COLI) {
                camera_override_mode_high(CAMERA_MODE_SURVEY,
                                          CAMERA_ADJUST_TIME);
            }
            break;
        }
    } else if (camera_control->mode == CAMERA_MODE_SURVEY) {
        if ((perG[0].on & SURVEY_END) || ((perG[0].x1 << 8) != 0) ||
            ((perG[0].y1 << 8) != 0) || !camera_player_still) {
            camera_restore_high();
            camera_set_adjust(CAMERA_ADJUST_TIME);
        }
    }
}

/* at CAMERA_LEVEL_NORMAL: take the collision's mode once player 0 is in it,
 * or crosses its plane */
void test_at_normal(Sint16 index, struct camera_collision *collision)
{
    Bool inside = FALSE;

    if (camera_control->collision == index || !playertwp[0]) {
        return;
    }
    switch (collision->type) {
    case CAMCOL_SPHERE:
        inside = sphere_holds_player(collision);
        break;
    case CAMCOL_PLANE:
        inside = plane_crossed_by_player(collision);
        break;
    case CAMCOL_BLOCK:
        inside = block_holds_player(collision);
        break;
    }
    if (!inside) {
        return;
    }
    camera_enter_collision(collision->mode, index);
    CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
}

/* set inside to whether player 0 is in the collision's sphere or block. a
 * plane never holds him */
/* @hack redundant: the switch in a loop of one pass, which keeps
 * test_at_area's 0 in R13, with R11 among the registers its prologue saves
 * (0x8c01ab22, 0x8c01ab0e); as the switch alone, summed over test_at_area
 * and test_at_event, 182 of 312 words differ */

/* at CAMERA_LEVEL_AREA or COMP: leave the camera's collision once player 0
 * is out of it. take a collision player 0 is in whose mode runs at a higher
 * level, or at the same level with a higher priority */
void test_at_area(Sint16 index, struct camera_collision *collision)
{
    Bool inside;

    if (camera_control->collision == index) {
        if (!playertwp[0]) {
            return;
        }
        PLAYER_INSIDE(inside, collision);
        if (!inside) {
            camera_leave_collision();
            CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
        }
    } else if (camera_modes[collision->mode].level > camera_control->level) {
        PLAYER_INSIDE(inside, collision);
        if (inside) {
            camera_enter_collision(collision->mode, index);
            CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
        }
    } else if (camera_modes[collision->mode].level == camera_control->level &&
               playertwp[0] &&
               camera_collisions[camera_control->collision].priority <
                   collision->priority) {
        PLAYER_INSIDE(inside, collision);
        if (inside) {
            camera_leave_collision();
            camera_enter_collision(collision->mode, index);
            CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
        }
    }
}

/* at CAMERA_LEVEL_EVENT: player 0 crossing a plane whose mode runs at COLI
 * sets the mode and adjust mode the camera goes back to at NORMAL. a
 * collision of higher priority that player 0 is in ends the override and
 * takes its own mode */
void test_at_event(Sint16 index, struct camera_collision *collision)
{
    Bool inside = FALSE;
    int level;

    if (camera_modes[collision->mode].level == CAMERA_LEVEL_COLI) {
        if (collision->type == CAMCOL_PLANE) {
            inside = plane_crossed_by_player(collision);
        }
        if (inside) {
            level = CAMERA_LEVEL_EVENT;
            while (camera_control->saved_level[level] != CAMERA_LEVEL_NORMAL) {
                level = camera_control->saved_level[level];
            }
            if (camera_collisions[index].mode != CAMERA_MODE_COLLI) {
                camera_control->saved_mode[level] =
                    camera_collisions[index].mode;
            }
            camera_control->saved_adjust[level] =
                camera_collisions[index].adjust;
            if (camera_collisions[index].mode != CAMERA_MODE_COLLI) {
                camera_control->saved_step[level] =
                    camera_modes[collision->mode].step;
            }
            camera_control->saved_adjust_step[level] =
                camera_adjusts[camera_collisions[index].adjust].step;
            CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
        }
    } else if (playertwp[0] &&
               /* @bug memory: after an override, collision is -1,
                * and the priority is read from camera_collisions[-1], as in
                * SAVE_SLOT (MOV.B @(1,R0),R0 at 0x8c01ad66): byte 1 of an
                * act's count, 0 below 256 collisions, so player 0 inside a
                * collision of any priority above 0 ends the override */
               camera_collisions[camera_control->collision].priority <
                   collision->priority) {
        PLAYER_INSIDE(inside, collision);
        if (inside) {
            CameraReleaseEventCamera();
            camera_enter_collision(collision->mode, index);
            CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
        }
    }
}

/* run the mode's step, and place work as camera_control's type says. the
 * adjust mode's step follows once camera_steps passes ADJUST_DELAY, but
 * under CAMERA_ADJUST_WAITS not in the mode's first step */
void camera_run_mode(struct task_work *work)
{
    if (!camera_control->step) {
        return;
    }
    camera_last_record = *work;
    cameraControlWork->pos.x = work->pos.x;
    cameraControlWork->pos.y = work->pos.y;
    cameraControlWork->pos.z = work->pos.z;
    if (camera_control->level == CAMERA_LEVEL_DEBUG) {
        camera_step_editor(&camera_step_view);
        camera_control->step(&camera_step_view);
    } else if (camera_control->flags & CAMERA_VIEW_GIVEN) {
        camera_step_view = camera_override_view;
        camera_step_view.steps = camera_control->steps;
        camera_control->step(&camera_step_view);
    } else {
        struct camera_collision *collision =
            &camera_collisions[camera_control->collision];

        camera_view_from_collision(collision);
        camera_control->step(&camera_step_view);
    }
    switch (camera_control->type) {
    case CAMERA_AT_ANGLES:
        camera_place_at_angles(work);
        break;
    case CAMERA_LOOK_AT:
        FUN_8c01a680(work);
        break;
    case CAMERA_FROM_TARGET:
        camera_place_from_target(work);
        break;
    }
    if (camera_control->steps ||
        !(camera_control->flags & CAMERA_ADJUST_WAITS)) {
        if (camera_steps > ADJUST_DELAY) {
            camera_control->adjust_step(work, camera_last, camera_adjust);
            camera_adjust->steps++;
        }
    }
}

/* set Ninja's view, then the light in it. while a camera action plays, the
 * action gives the view. otherwise the view is work's, moved by the offsets
 * camera_add_offset gave, which this zeroes */
void camera_apply_view(struct task_work *work)
{
    if (camera_action_state != ACTION_NONE) {
        FUN_8c6094be(camera_action, camera_action_frame);
        if (((int)GetStageNumber() >> 8) == 32) {
            struct task_work *w;
            w = camera_twp;
            w->ang.y = 0;
        }
    } else {
        njRotateViewZAbsolute(&view, work->ang.z);
        njRotateViewXAbsolute(&view, work->ang.x);
        njRotateViewYRelative(&view, work->ang.y);
        njTranslateViewAbsolute(&view, work->pos.x + camera_control->offset.x,
                                work->pos.y + camera_control->offset.y,
                                work->pos.z + camera_control->offset.z);
        njSetView(&view);
        camera_control->offset.x = 0.0F;
        camera_control->offset.y = 0.0F;
        camera_control->offset.z = 0.0F;
    }
    FUN_8c0130f8();
}

/* whether player 0, at TEST_HEIGHT, is in the sphere */
Bool sphere_holds_player(struct camera_collision *collision)
{
    Float dx = playertwp[0]->pos.x - collision->col_pos.x;
    Float dy = playertwp[0]->pos.y - collision->col_pos.y + TEST_HEIGHT;
    Float dz = playertwp[0]->pos.z - collision->col_pos.z;
    Float distance = (dx * dx) + (dy * dy) + (dz * dz);

    if (collision->col_scl.z > distance) {
        return TRUE;
    }
    return FALSE;
}

/* whether player 0, at TEST_HEIGHT, crossed the plane between the last two
 * steps, within its width and height */
Bool plane_crossed_by_player(struct camera_collision *collision)
{
    NJS_MATRIX matrix;
    NJS_POINT3 point;
    NJS_POINT3 before;
    NJS_POINT3 after;
    NJS_POINT3 hit;
    NJS_LINE line;
    Float x = collision->col_pos.x;
    Float y = collision->col_pos.y;
    Float z = collision->col_pos.z;
    Float sx = collision->col_scl.x;
    Float sy = collision->col_scl.y;
    Float dx = x - playertwp[0]->pos.x;
    /* @bug logic: dy adds 4 to the plane's height less player 0's, so
     * the range test measures from 4 below his feet, not above (FSUB at
     * 0x8c01b122, FADD at 0x8c01b12a) */
    Float dy = y - playertwp[0]->pos.y + TEST_HEIGHT;
    Float dz = z - playertwp[0]->pos.z;
    Float distance = (dx * dx) + (dy * dy) + (dz * dz);
    Float range = (sx * sx) + (sy * sy);
    Angle ang;

    if (distance > range) {
        return FALSE;
    }
    GetPlayerPosition(0, 1, &after, NULL);
    GetPlayerPosition(0, 2, &before, NULL);
    after.y += TEST_HEIGHT;
    before.y += TEST_HEIGHT;
    njUnitMatrix(&matrix);
    njTranslate(&matrix, x, y, z);
    TURN_MATRIX_VIA(njRotateX, &matrix, collision->col_ang_x, ang);
    TURN_MATRIX_VIA(njRotateY, &matrix, collision->col_ang_y, ang);
    njInvertMatrix(&matrix);
    njCalcPoint(&matrix, &before, &point);
    before = point;
    njCalcPoint(&matrix, &after, &point);
    after = point;
    if (before.z < 0.0F && after.z < 0.0F) {
        return FALSE;
    }
    if (before.z > 0.0F && after.z > 0.0F) {
        return FALSE;
    }
    line.px = before.x;
    line.py = before.y;
    line.pz = before.z;
    line.vx = after.x - before.x;
    line.vy = after.y - before.y;
    line.vz = after.z - before.z;
    njDistanceL2PL(&line, &collision_plane, &hit);
    if (hit.x > sx) {
        return FALSE;
    }
    if (hit.x < -sx) {
        return FALSE;
    }
    if (hit.y > sy) {
        return FALSE;
    }
    if (hit.y < -sy) {
        return FALSE;
    }
    return TRUE;
}

/* whether player 0, at TEST_HEIGHT, is in the block */
Bool block_holds_player(struct camera_collision *collision)
{
    NJS_MATRIX matrix;
    NJS_POINT3 local;
    NJS_POINT3 point;
    Float x = collision->col_pos.x;
    Float y = collision->col_pos.y;
    Float z = collision->col_pos.z;
    Float sx = collision->col_scl.x;
    Float sy = collision->col_scl.y;
    Float sz = collision->col_scl.z;
    Float dx = x - playertwp[0]->pos.x;
    /* @bug logic: dy adds 4 to the block's height less player 0's, so
     * the range test measures from 4 below his feet, not above (FSUB at
     * 0x8c01b386, FADD at 0x8c01b38c) */
    Float dy = y - playertwp[0]->pos.y + TEST_HEIGHT;
    Float dz = z - playertwp[0]->pos.z;
    Float distance = (dx * dx) + (dy * dy) + (dz * dz);
    Float range = (sx * sx) + (sy * sy) + (sz * sz);
    Angle ang;

    if (distance > range) {
        return FALSE;
    }
    GetPlayerPosition(0, 1, &point, NULL);
    point.y += TEST_HEIGHT;
    njUnitMatrix(&matrix);
    njTranslate(&matrix, x, y, z);
    TURN_MATRIX_VIA(njRotateX, &matrix, collision->col_ang_x, ang);
    TURN_MATRIX_VIA(njRotateY, &matrix, collision->col_ang_y, ang);
    njInvertMatrix(&matrix);
    njCalcPoint(&matrix, &point, &local);
    if (local.x > sx) {
        return FALSE;
    }
    if (local.x < -sx) {
        return FALSE;
    }
    if (local.y > sy) {
        return FALSE;
    }
    if (local.y < -sy) {
        return FALSE;
    }
    if (local.z > sz) {
        return FALSE;
    }
    if (local.z < -sz) {
        return FALSE;
    }
    return TRUE;
}

/* at CAMERA_LEVEL_NORMAL, a press of one of pad_camera_buttons moves the
 * camera on to the next pickable mode, round to mode 0 after the last */
void camera_pick_next_mode(void)
{
    if (camera_control->level != CAMERA_LEVEL_NORMAL) {
        return;
    }
    if (!(perG[0].press & pad_camera_buttons)) {
        return;
    }
    /* @hack redundant: the jump to next, which loads camera_control into R2 at
     * the loop's head (MOV.L @R4,R2 at 0x8c01b48e); without it and its
     * label, R3, and 3 of 47 words differ */
    goto next;
next:
    for (;;) {
        camera_control->mode++;
        if (camera_control->mode >= camera_mode_count) {
            camera_control->mode = 0;
        }
        if (camera_modes[camera_control->mode].pickable == TRUE &&
            camera_control->level == CAMERA_LEVEL_NORMAL) {
            FUN_8c01aae0(camera_control->mode, 0);
            break;
        }
    }
}

void camera_place_at_angles(struct task_work *work)
{
    work->pos.x = cameraControlWork->pos.x;
    work->pos.y = cameraControlWork->pos.y;
    work->pos.z = cameraControlWork->pos.z;
    work->ang.x = cameraControlWork->ang_x;
    work->ang.y = cameraControlWork->ang_y;
    work->ang.z = cameraControlWork->ang_z;
}

void FUN_8c01a680(struct task_work *work)
{
    Float dx;
    Float dz;

    work->pos.x = cameraControlWork->pos.x;
    work->pos.y = cameraControlWork->pos.y;
    work->pos.z = cameraControlWork->pos.z;
    dx = cameraControlWork->pos.x - cameraControlWork->target.x;
    dz = cameraControlWork->pos.z - cameraControlWork->target.z;
    work->ang.y = (Angle)(njArcTan2(dx, dz) * ANGLE_PER_RADIAN);
    work->ang.x = (Angle)(njArcTan2(cameraControlWork->target.y -
                                        cameraControlWork->pos.y,
                                    njSqrt((dx * dx) + (dz * dz))) *
                          ANGLE_PER_RADIAN);
    work->ang.z = cameraControlWork->ang_z;
}

void camera_place_from_target(struct task_work *work)
{
    Float across =
        cameraControlWork->distance * njCos(cameraControlWork->ang_x);

    work->pos.y =
        cameraControlWork->target.y -
        (cameraControlWork->distance * njSin(cameraControlWork->ang_x));
    work->pos.x = cameraControlWork->target.x +
                  (across * njSin(cameraControlWork->ang_y));
    work->pos.z = cameraControlWork->target.z +
                  (across * njCos(cameraControlWork->ang_y));
    work->ang.x = cameraControlWork->ang_x;
    work->ang.y = cameraControlWork->ang_y;
    work->ang.z = cameraControlWork->ang_z;
}

void FUN_8c01a7a4(NJS_VECTOR *offset)
{
    camera_control->offset.x += offset->x;
    camera_control->offset.y += offset->y;
    camera_control->offset.z += offset->z;
}

/* give the camera mode, the mode of collision index, at the mode's level.
 * that level's slot keeps what the camera ran */
void camera_enter_collision(Sint8 mode, Sint16 index)
{
    Sint8 level = camera_modes[mode].level;
    /* NOLINTBEGIN(bugprone-signed-char-misuse) */
    /* @bug memory: with collision -1, old_priority is read from
     * camera_collisions[-1], as in SAVE_SLOT (MOV.B @(1,R11),R0 at
     * 0x8c01b742): byte 1 of an act's count, 0 below 256 collisions */
    int old_priority = camera_collisions[camera_control->collision].priority;
    int new_priority = camera_collisions[index].priority;
    do {
        camera_control->saved_level[level] = camera_control->level;
        camera_control->saved_collision[level] = camera_control->collision;
        camera_control->saved_flags[level] = camera_control->flags;
        camera_control->saved_mode[level] = camera_control->mode;
        camera_control->saved_step[level] = camera_control->step;
        if (camera_control->collision != -1) {
            camera_control->saved_adjust[level] =
                camera_collisions[camera_control->collision].adjust;
        } else {
            camera_control->saved_adjust[level] = 21;
        }
        camera_control->saved_adjust_step[level] =
            camera_adjusts[camera_control->saved_adjust[level]].step;
    } while (0);
    camera_control->level = level;
    camera_control->collision = index;
    camera_control->mode = mode;
    camera_control->step = camera_modes[mode].step;
    if (old_priority < new_priority) {
        camera_cut = TRUE;
    }
    if (old_priority >= PRIORITY_HIGH && new_priority >= PRIORITY_HIGH) {
        camera_control->adjust = CAMERA_ADJUST_NONE;
    } else {
        camera_control->adjust = camera_collisions[index].adjust;
    }
    camera_control->adjust_step = camera_adjusts[camera_control->adjust].step;
    camera_adjust->steps = 0;
    /* a waiting adjust mode adds CAMERA_ADJUST_WAITS to the flags the
     * camera had. a CAMERA_VIEW_GIVEN from before then stays, and the step
     * reads camera_override_view, not this collision's view. any other
     * adjust mode clears the flags */
    if (camera_adjusts[camera_control->adjust].waits) {
        camera_control->flags |= CAMERA_ADJUST_WAITS;
    } else {
        camera_control->flags = 0;
    }
    camera_control->type = camera_modes[camera_control->mode].type;
    camera_control->changed = TRUE;
    CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
}

/* go back to what the slot of the camera's level keeps */
void camera_leave_collision(void)
{
    Sint8 level = camera_control->level;
    /* NOLINTBEGIN(bugprone-signed-char-misuse) */
    int old_priority = camera_collisions[camera_control->collision].priority;
    /* @bug memory: with the slot's collision -1, new_priority is read
     * from camera_collisions[-1], as in SAVE_SLOT (MOV.B @(1,R1),R0 at
     * 0x8c01b8ba): byte 1 of an act's count, 0 below 256 collisions */
    int new_priority =
        camera_collisions[camera_control->saved_collision[level]].priority;
    /* NOLINTEND(bugprone-signed-char-misuse) */

    camera_control->collision = camera_control->saved_collision[level];
    camera_control->flags = camera_control->saved_flags[level];
    camera_control->mode = camera_control->saved_mode[level];
    camera_control->step = camera_control->saved_step[level];
    camera_control->level = camera_control->saved_level[level];
    if (old_priority >= PRIORITY_HIGH && new_priority >= PRIORITY_HIGH) {
        camera_control->adjust = CAMERA_ADJUST_NONE;
    } else {
        camera_control->adjust = camera_control->saved_adjust[level];
    }
    if (old_priority < new_priority) {
        camera_cut = TRUE;
    }
    if (old_priority >= PRIORITY_HIGH && new_priority >= PRIORITY_HIGH) {
        camera_control->adjust_step = camera_adjusts[CAMERA_ADJUST_NONE].step;
    } else {
        camera_control->adjust_step = camera_control->saved_adjust_step[level];
    }
    camera_control->type = camera_modes[camera_control->mode].type;
    camera_control->changed = TRUE;
    camera_control->steps = 0;
    camera_adjust->steps = 0;
    CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
}

void FUN_8c01aae0(Sint16 mode, Uint8 adjust)
{
    if (camera_control->level != CAMERA_LEVEL_NORMAL) {
        return;
    }
    do {
        camera_control->saved_level[CAMERA_LEVEL_NORMAL] =
            camera_control->level;
        camera_control->saved_collision[CAMERA_LEVEL_NORMAL] =
            camera_control->collision;
        camera_control->saved_flags[CAMERA_LEVEL_NORMAL] =
            camera_control->flags;
        camera_control->saved_mode[CAMERA_LEVEL_NORMAL] = camera_control->mode;
        camera_control->saved_step[CAMERA_LEVEL_NORMAL] = camera_control->step;
        if (camera_control->collision != -1) {
            camera_control->saved_adjust[CAMERA_LEVEL_NORMAL] =
                camera_collisions[camera_control->collision].adjust;
        } else {
            camera_control->saved_adjust[CAMERA_LEVEL_NORMAL] = 21;
        }
        camera_control->saved_adjust_step[CAMERA_LEVEL_NORMAL] =
            camera_adjusts[camera_control->saved_adjust[CAMERA_LEVEL_NORMAL]]
                .step;
    } while (0);
    camera_control->collision = -1;
    camera_control->level = CAMERA_LEVEL_NORMAL;
    camera_control->mode = mode;
    camera_control->step = camera_modes[mode].step;
    camera_control->adjust = adjust;
    camera_control->adjust_step = camera_adjusts[adjust].step;
    camera_adjust->steps = 0;
    if (camera_adjusts[camera_control->adjust].waits) {
        camera_control->flags |= CAMERA_ADJUST_WAITS;
    }
    camera_control->type = camera_modes[camera_control->mode].type;
    camera_control->changed = TRUE;
    CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
}

void camera_override_mode(Sint16 mode, Uint8 adjust)
{
    if (camera_control->level <= CAMERA_LEVEL_EVENT) {
        if (camera_control->level != CAMERA_LEVEL_EVENT) {
            do {
                camera_control->saved_level[CAMERA_LEVEL_EVENT] =
                    camera_control->level;
                camera_control->saved_collision[CAMERA_LEVEL_EVENT] =
                    camera_control->collision;
                camera_control->saved_flags[CAMERA_LEVEL_EVENT] =
                    camera_control->flags;
                camera_control->saved_mode[CAMERA_LEVEL_EVENT] =
                    camera_control->mode;
                camera_control->saved_step[CAMERA_LEVEL_EVENT] =
                    camera_control->step;
                if (camera_control->collision != -1) {
                    camera_control->saved_adjust[CAMERA_LEVEL_EVENT] =
                        camera_collisions[camera_control->collision].adjust;
                } else {
                    camera_control->saved_adjust[CAMERA_LEVEL_EVENT] = 21;
                }
                camera_control->saved_adjust_step[CAMERA_LEVEL_EVENT] =
                    camera_adjusts[camera_control
                                       ->saved_adjust[CAMERA_LEVEL_EVENT]]
                        .step;
            } while (0);
            camera_control->level = CAMERA_LEVEL_EVENT;
        }
        camera_control->collision = -1;
        camera_control->mode = mode;
        camera_control->step = camera_modes[mode].step;
        camera_control->adjust = adjust;
        camera_control->adjust_step = camera_adjusts[adjust].step;
        camera_adjust->steps = 0;
        camera_control->flags = CAMERA_VIEW_GIVEN;
        if (camera_adjusts[camera_control->adjust].waits) {
            camera_control->flags |= CAMERA_ADJUST_WAITS;
        }
        camera_control->type = camera_modes[camera_control->mode].type;
        camera_control->changed = TRUE;
        CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
    }
}

void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type)
{
    if (camera_control->level <= CAMERA_LEVEL_EVENT) {
        if (camera_control->level != CAMERA_LEVEL_EVENT) {
            do {
                camera_control->saved_level[CAMERA_LEVEL_EVENT] =
                    camera_control->level;
                camera_control->saved_collision[CAMERA_LEVEL_EVENT] =
                    camera_control->collision;
                camera_control->saved_flags[CAMERA_LEVEL_EVENT] =
                    camera_control->flags;
                camera_control->saved_mode[CAMERA_LEVEL_EVENT] =
                    camera_control->mode;
                camera_control->saved_step[CAMERA_LEVEL_EVENT] =
                    camera_control->step;
                if (camera_control->collision != -1) {
                    camera_control->saved_adjust[CAMERA_LEVEL_EVENT] =
                        camera_collisions[camera_control->collision].adjust;
                } else {
                    camera_control->saved_adjust[CAMERA_LEVEL_EVENT] = 21;
                }
                camera_control->saved_adjust_step[CAMERA_LEVEL_EVENT] =
                    camera_adjusts[camera_control
                                       ->saved_adjust[CAMERA_LEVEL_EVENT]]
                        .step;
            } while (0);
            camera_control->level = CAMERA_LEVEL_EVENT;
        }
        camera_control->collision = -1;
        camera_control->mode = -1;
        camera_control->step = step;
        camera_control->adjust = adjust;
        camera_control->adjust_step =
            camera_adjusts[camera_control->adjust].step;
        camera_adjust->steps = 0;
        camera_control->flags = CAMERA_VIEW_GIVEN;
        if (camera_adjusts[camera_control->adjust].waits) {
            camera_control->flags |= CAMERA_ADJUST_WAITS;
        }
        camera_control->type = type;
        camera_control->changed = TRUE;
        CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
    }
}

void CameraReleaseEventCamera(void)
{
    if (camera_control->level == CAMERA_LEVEL_EVENT) {
        RESTORE_SLOT(CAMERA_LEVEL_EVENT);
        camera_control->type = camera_modes[camera_control->mode].type;
        camera_control->changed = TRUE;
        camera_control->steps = 0;
        camera_adjust->steps = 0;
        CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
        if (camera_control->level == CAMERA_LEVEL_NORMAL &&
            camera_restore_mode != -1) {
            FUN_8c01aae0(camera_restore_mode, camera_restore_adjust);
        }
    }
    camera_restored_steps = 0;
}

void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type)
{
    if (camera_control->level <= CAMERA_LEVEL_COLI) {
        if (camera_control->level != CAMERA_LEVEL_COLI) {
            do {
                camera_control->saved_level[CAMERA_LEVEL_COLI] =
                    camera_control->level;
                camera_control->saved_collision[CAMERA_LEVEL_COLI] =
                    camera_control->collision;
                camera_control->saved_flags[CAMERA_LEVEL_COLI] =
                    camera_control->flags;
                camera_control->saved_mode[CAMERA_LEVEL_COLI] =
                    camera_control->mode;
                camera_control->saved_step[CAMERA_LEVEL_COLI] =
                    camera_control->step;
                if (camera_control->collision != -1) {
                    camera_control->saved_adjust[CAMERA_LEVEL_COLI] =
                        camera_collisions[camera_control->collision].adjust;
                } else {
                    camera_control->saved_adjust[CAMERA_LEVEL_COLI] = 21;
                }
                camera_control->saved_adjust_step[CAMERA_LEVEL_COLI] =
                    camera_adjusts[camera_control
                                       ->saved_adjust[CAMERA_LEVEL_COLI]]
                        .step;
            } while (0);
            camera_control->level = CAMERA_LEVEL_COLI;
        }
        camera_control->collision = -1;
        camera_control->mode = -1;
        camera_control->step = step;
        camera_control->adjust = adjust;
        camera_control->adjust_step =
            camera_adjusts[camera_control->adjust].step;
        camera_adjust->steps = 0;
        camera_control->flags = CAMERA_VIEW_GIVEN;
        if (camera_adjusts[camera_control->adjust].waits) {
            camera_control->flags |= CAMERA_ADJUST_WAITS;
        }
        camera_control->type = type;
        camera_control->changed = TRUE;
        CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
    }
}

void camera_override_mode_high(Sint16 mode, Uint8 adjust)
{
    if (camera_control->level <= CAMERA_LEVEL_COLI) {
        if (camera_control->level != CAMERA_LEVEL_COLI) {
            do {
                camera_control->saved_level[CAMERA_LEVEL_COLI] =
                    camera_control->level;
                camera_control->saved_collision[CAMERA_LEVEL_COLI] =
                    camera_control->collision;
                camera_control->saved_flags[CAMERA_LEVEL_COLI] =
                    camera_control->flags;
                camera_control->saved_mode[CAMERA_LEVEL_COLI] =
                    camera_control->mode;
                camera_control->saved_step[CAMERA_LEVEL_COLI] =
                    camera_control->step;
                if (camera_control->collision != -1) {
                    camera_control->saved_adjust[CAMERA_LEVEL_COLI] =
                        camera_collisions[camera_control->collision].adjust;
                } else {
                    camera_control->saved_adjust[CAMERA_LEVEL_COLI] = 21;
                }
                camera_control->saved_adjust_step[CAMERA_LEVEL_COLI] =
                    camera_adjusts[camera_control
                                       ->saved_adjust[CAMERA_LEVEL_COLI]]
                        .step;
            } while (0);
            camera_control->level = CAMERA_LEVEL_COLI;
        }
        camera_control->collision = -1;
        camera_control->mode = mode;
        camera_control->step = camera_modes[mode].step;
        camera_control->adjust = adjust;
        camera_control->adjust_step = camera_adjusts[adjust].step;
        camera_adjust->steps = 0;
        camera_control->flags = CAMERA_VIEW_GIVEN;
        if (camera_adjusts[camera_control->adjust].waits) {
            camera_control->flags |= CAMERA_ADJUST_WAITS;
        }
        camera_control->type = camera_modes[camera_control->mode].type;
        camera_control->changed = TRUE;
        CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
    }
}

void camera_restore_high(void)
{
    if (camera_control->level != CAMERA_LEVEL_COLI) {
        return;
    }
    RESTORE_SLOT(CAMERA_LEVEL_COLI);
    camera_control->type = camera_modes[camera_control->mode].type;
    camera_control->changed = TRUE;
    camera_control->steps = 0;
    camera_adjust->steps = 0;
    CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
    if (camera_control->level == CAMERA_LEVEL_NORMAL &&
        camera_restore_mode != -1) {
        FUN_8c01aae0(camera_restore_mode, camera_restore_adjust);
    }
}

void camera_take(struct task_work *work, void (*step)(struct camera_view *view))
{
    if (camera_control->level != CAMERA_LEVEL_DEBUG) {
        /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
        camera_control->saved_level[CAMERA_LEVEL_DEBUG] = camera_control->level;
        camera_control->saved_collision[CAMERA_LEVEL_DEBUG] =
            camera_control->collision;
        camera_control->saved_flags[CAMERA_LEVEL_DEBUG] = camera_control->flags;
        camera_control->saved_mode[CAMERA_LEVEL_DEBUG] = camera_control->mode;
        camera_control->saved_step[CAMERA_LEVEL_DEBUG] = camera_control->step;
        camera_control->saved_adjust[CAMERA_LEVEL_DEBUG] =
            camera_control->adjust;
        camera_control->saved_adjust_step[CAMERA_LEVEL_DEBUG] =
            camera_control->adjust_step;
        camera_control->saved_type[CAMERA_LEVEL_DEBUG] = camera_control->type;
        /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
        camera_control->unk_86[CAMERA_LEVEL_DEBUG] = camera_control->level;
        camera_control->level = CAMERA_LEVEL_DEBUG;
    }
    camera_take_work = work;
    camera_control->collision = -1;
    camera_control->mode = -1;
    camera_control->step = step;
    camera_control->adjust = CAMERA_ADJUST_NONE;
    camera_control->adjust_step = camera_adjusts[CAMERA_ADJUST_NONE].step;
    camera_control->flags = CAMERA_ADJUST_WAITS | CAMERA_VIEW_GIVEN;
    camera_control->type = CAMERA_BY_STEP;
    camera_control->changed = TRUE;
    CreateElementalTask(TASK_EXTRA, 6, camera_mode_change_step);
}

void camera_release(void)
{
    if (camera_control->level == CAMERA_LEVEL_DEBUG) {
        camera_set_default_mode();
    }
}

/* set camera_step_view to the view the collision gives its mode's step */
void camera_view_from_collision(struct camera_collision *collision)
{
    camera_step_view.pos.x = collision->cam_pos.x;
    camera_step_view.pos.y = collision->cam_pos.y;
    camera_step_view.pos.z = collision->cam_pos.z;
    camera_step_view.target.x = collision->dir_pos.x;
    camera_step_view.target.y = collision->dir_pos.y;
    camera_step_view.target.z = collision->dir_pos.z;
    camera_step_view.ang_x = collision->cam_ang_x;
    camera_step_view.ang_y = collision->cam_ang_y;
    camera_step_view.distance = collision->distance;
    camera_step_view.steps = camera_control->steps;
}

/* the task made at each change of mode, which only ends itself */
void camera_mode_change_step(struct task *task)
{
    FreeTask(task);
}

Bool camera_at_event_level(void)
{
    if (camera_control->level == CAMERA_LEVEL_EVENT) {
        return TRUE;
    }
    return FALSE;
}

Bool camera_at_comp_level(void)
{
    if (camera_control->level == CAMERA_LEVEL_COMP) {
        return TRUE;
    }
    return FALSE;
}

Uint32 camera_get_steps(void)
{
    return camera_steps;
}

void camera_reset_steps(void)
{
    camera_steps = 0;
}

void camera_set_adjust(int adjust)
{
    camera_control->adjust = adjust;
    camera_control->adjust_step = camera_adjusts[camera_control->adjust].step;
    camera_adjust->steps = 0;
}

int FUN_8c01b406(void)
{
    return camera_control->adjust;
}

int camera_get_mode(void)
{
    return camera_control->mode;
}
void FUN_8c01b416(int mode)
{
    camera_control->collision = -1;
    camera_control->mode = mode;
    camera_control->step = camera_modes[mode].step;
}

/* if the camera is still from last to work, adjust mode NORMAL becomes
 * SLOW. NONE, NORMAL_S, SLOW and SLOW_S become NONE. camera_set_adjust
 * zeroes the adjust mode's steps, so a still camera at NONE zeroes them
 * each step */
void camera_settle_adjust(struct task_work *work, struct task_work *last)
{
    Float dx = work->pos.x - last->pos.x;
    Float dy = work->pos.y - last->pos.y;
    Float dz = work->pos.z - last->pos.z;
    Float distance = (dx * dx) + (dy * dy) + (dz * dz);

    if (distance < STILL_MOVE * STILL_MOVE &&
        DiffAngle(work->ang.x, last->ang.x) < STILL_TURN &&
        DiffAngle(work->ang.y, last->ang.y) < STILL_TURN &&
        DiffAngle(work->ang.z, last->ang.z) < STILL_TURN) {
        switch (camera_control->adjust) {
        case CAMERA_ADJUST_NORMAL:
            camera_set_adjust(CAMERA_ADJUST_SLOW);
            break;
        case CAMERA_ADJUST_NONE:
        case CAMERA_ADJUST_NORMAL_S:
        case CAMERA_ADJUST_SLOW:
        case CAMERA_ADJUST_SLOW_S:
            camera_set_adjust(CAMERA_ADJUST_NONE);
            break;
        }
    }
}

void camera_note_player_still(void)
{
    njSubVector(&camera_player_last, &playertwp[0]->pos);
    if (njScalor(&camera_player_last) < STILL_MOVE &&
        (playertwp[0]->flags & PLAYER_ON_LAND)) {
        camera_player_still = TRUE;
    } else {
        camera_player_still = FALSE;
    }
    camera_player_last = playertwp[0]->pos;
}

void FUN_8c01b554(void)
{
    camera_moved.x = camera_twp->pos.x - camera_last_pos.x;
    camera_moved.y = camera_twp->pos.y - camera_last_pos.y;
    camera_moved.z = camera_twp->pos.z - camera_last_pos.z;
    camera_last_pos = camera_twp->pos;
}

Bool FUN_8c01b5e0(void)
{
    /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
    int adjust = camera_control->adjust;

    switch (adjust) {
    case CAMERA_ADJUST_TIME:
    case CAMERA_ADJUST_THREE1C:
    case CAMERA_ADJUST_THREE2C:
    case CAMERA_ADJUST_THREE3C:
    case CAMERA_ADJUST_THREE4C:
    case CAMERA_ADJUST_THREE5C:
    case CAMERA_ADJUST_RELATIVE1C:
    case CAMERA_ADJUST_RELATIVE2C:
    case CAMERA_ADJUST_RELATIVE3C:
    case CAMERA_ADJUST_RELATIVE4C:
    case CAMERA_ADJUST_RELATIVE5C:
    case CAMERA_ADJUST_RELATIVE6C:
        return TRUE;
    default:
        return FALSE;
    }
}

void camera_set_type(int type)
{
    camera_control->type = type;
}

Bool camera_play_action(NJS_CACTION *action, Float frame)
{
    switch (camera_action_state) {
    case ACTION_NONE:
        CameraSetEventCameraFunc(InitCartGoalCamFunc, CAMERA_ADJUST_NONE,
                                 CAMERA_BY_STEP);
        /* fall through */
    case ACTION_PLAYED:
        camera_action_state = ACTION_ASKED;
        camera_action = action;
        camera_action_frame = frame;
        return FALSE;
    }
    return TRUE;
}

int camera_push_out(NJS_POINT3 *pos)
{
    struct camera_collision *collision;
    Uint16 stage;
    int count = 0;
    Sint16 i;

    stage = GetStageNumber();
    if (!camera_layouts[stage >> 8][stage & 0xff]) {
        return 0;
    }
    collision = &camera_collisions[*camera_collision_count - 1];
    for (i = *camera_collision_count - 1; i > 0; i--, collision--) {
        if (camera_modes[collision->mode].level == CAMERA_LEVEL_COLI) {
            switch (collision->type) {
            case CAMCOL_SPHERE:
                count += push_out_of_sphere(collision, pos);
                break;
            case CAMCOL_BLOCK:
                count += push_out_of_block(collision, pos);
                break;
            }
        }
    }
    return count;
}
int FUN_8c01b900(struct camera_collision *collision, NJS_POINT3 *a,
                 NJS_POINT3 *b);
int FUN_8c01b782(NJS_POINT3 *a, NJS_POINT3 *b)
{
    struct camera_collision *collision;
    Uint16 stage;
    int count = 0;
    Sint16 i;
    stage = GetStageNumber();
    if (!camera_layouts[stage >> 8][stage & 0xff]) {
        return 0;
    }
    collision = &camera_collisions[*camera_collision_count - 1];
    for (i = *camera_collision_count - 1; i > 0; i--, collision--) {
        if (camera_modes[collision->mode].level == CAMERA_LEVEL_COLI) {
            switch (collision->type) {
            case CAMCOL_PLANE:
                count += FUN_8c01b900(collision, a, b);
                break;
            }
        }
    }
    return count;
}

Bool sphere_holds(const struct camera_collision *collision,
                  const NJS_POINT3 *point)
{
    Float dx = point->x - collision->col_pos.x;
    Float dy = point->y - collision->col_pos.y;
    Float dz = point->z - collision->col_pos.z;
    Float distance = (dx * dx) + (dy * dy) + (dz * dz);

    if (collision->col_scl.z > distance) {
        return TRUE;
    }
    return FALSE;
}

/* push pos out to the sphere's surface, away from its middle, if the
 * sphere holds it. TRUE if it did */
Bool push_out_of_sphere(struct camera_collision *collision, NJS_POINT3 *pos)
{
    NJS_VECTOR away;

    if (sphere_holds(collision, pos) == TRUE) {
        away.x = pos->x - collision->col_pos.x;
        away.y = pos->y - collision->col_pos.y;
        away.z = pos->z - collision->col_pos.z;
        njUnitVector(&away);
        pos->x = collision->col_pos.x + (away.x * collision->col_scl.x);
        pos->y = collision->col_pos.y + (away.y * collision->col_scl.x);
        pos->z = collision->col_pos.z + (away.z * collision->col_scl.x);
        return TRUE;
    }
    return FALSE;
}
int FUN_8c01b900(struct camera_collision *collision, NJS_POINT3 *a,
                 NJS_POINT3 *b)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    return asm_stub[0];
}

/* push pos out through the block's nearest face, if the block holds it.
 * TRUE if it did */
Bool push_out_of_block(struct camera_collision *collision, NJS_POINT3 *pos)
{
    NJS_MATRIX matrix;
    NJS_POINT3 local;
    Float depth[3];
    Angle ang;
    int axis;

    njUnitMatrix(&matrix);
    njTranslate(&matrix, collision->col_pos.x, collision->col_pos.y,
                collision->col_pos.z);
    TURN_MATRIX_VIA(njRotateX, &matrix, collision->col_ang_x, ang);
    TURN_MATRIX_VIA(njRotateY, &matrix, collision->col_ang_y, ang);
    njInvertMatrix(&matrix);
    njCalcPoint(&matrix, pos, &local);
    /* @hack spelling: each depth set inside its test, which stores it through
     * R4 (FMOV.S FR3,@R4 at 0x8c01c70a); set ahead of the tests, depth's
     * address takes R13 and 63 of 186 words differ */
    if ((depth[0] = njAbs(local.x)) > collision->col_scl.x) {
        return FALSE;
    }
    if ((depth[1] = njAbs(local.y)) > collision->col_scl.y) {
        return FALSE;
    }
    if ((depth[2] = njAbs(local.z)) > collision->col_scl.z) {
        return FALSE;
    }
    depth[0] = collision->col_scl.x - depth[0];
    depth[1] = collision->col_scl.y - depth[1];
    depth[2] = collision->col_scl.z - depth[2];
    axis = 0;
    if (depth[1] < depth[0]) {
        axis = 1;
        if (depth[2] < depth[1]) {
            axis = 2;
        }
    } else if (depth[2] < depth[0]) {
        axis = 2;
    }
    switch (axis) {
    case 0:
        if (local.x > 0.0F) {
            local.x = collision->col_scl.x;
        } else {
            local.x = -collision->col_scl.x;
        }
        break;
    case 1:
        if (local.y > 0.0F) {
            local.y = collision->col_scl.y;
        } else {
            local.y = -collision->col_scl.y;
        }
        break;
    case 2:
        if (local.z > 0.0F) {
            local.z = collision->col_scl.z;
        } else {
            local.z = -collision->col_scl.z;
        }
        break;
    }
    njInvertMatrix(&matrix);
    njCalcPoint(&matrix, &local, pos);
    return TRUE;
}

void camera_ease(NJS_POINT3 *from, NJS_POINT3 *pos)
{
    if (!camera_ease_left) {
        return;
    }
    pos->x =
        from->x + ((pos->x - from->x) * (Float)(EASE_STEPS - camera_ease_left) *
                   (1.0F / EASE_STEPS));
    pos->y =
        from->y + ((pos->y - from->y) * (Float)(EASE_STEPS - camera_ease_left) *
                   (1.0F / EASE_STEPS));
    pos->z =
        from->z + ((pos->z - from->z) * (Float)(EASE_STEPS - camera_ease_left) *
                   (1.0F / EASE_STEPS));
    camera_ease_left--;
}

/* tint the screen while the eye point, 2 in front of the camera, is under
 * water. a step that finds camera_in_dry_box set draws no tint, and clears
 * the flag. the facing plane runs through the eye point, square to the
 * camera's view. the water line is where it meets the nearest water surface
 * above the eye point. the tint covers the screen from the row that line
 * projects to, or all of it where that row is off the screen */
void FUN_8c01bd9e(void)
{
    /* @hack spelling: the locals in this order, which puts facing 100 to 120
     * bytes above R15, in reach of MOV #imm,R0 (0x8c01c948 to 0x8c01c96c);
     * declared as first used, 251 of 486 words differ and the code runs 32
     * bytes short */
    struct height_query query;
    NJS_POINT3 above;
    NJS_POINT3 below;
    NJS_POINT3 eye;
    NJS_POINT2 screen;
    union plane_view facing;
    NJS_PLANE above_plane;
    NJS_PLANE below_plane;
    struct task_work *work = camera_twp;
    struct world_object *objects;
    NJS_OBJECT *object;
    Uint16 i;
    Sint16 y;
    Bool dry;

    dry = camera_in_dry_box;
    camera_in_dry_box = FALSE;
    if (dry == TRUE) {
        return;
    }
    eye.x = 0.0F;
    eye.y = 0.0F;
    eye.z = -2.0F;
    njPushMatrix(&nj_unit_matrix_);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateX, work->ang.x);
    njCalcPoint(NULL, &eye, &eye);
    facing.plane.px = eye.x;
    facing.plane.py = eye.y;
    facing.plane.pz = eye.z;
    facing.plane.vx = 0.0F;
    facing.plane.vy = 0.0F;
    facing.plane.vz = -1.0F;
    njCalcVector(NULL, &facing.split.normal_jp, &facing.split.normal_jp);
    late_DrawObjectClipEx(1);

    query.pos = eye;
    objects = numLandCollList;
    ListGroundForCollision(eye.x, eye.y, eye.z, 200.0F);
    above.y = NO_WATER;
    below.y = -NO_WATER;
    for (i = 0; i < LandCollList; i++) {
        object = objects[i].object;
        if (objects[i].owner) {
            NJS_VECTOR away;
            Float scale;
            Float distance;

            away.x = object->pos[0] - eye.x;
            away.y = 0.0F;
            away.z = object->pos[2] - eye.z;
            distance = njScalor(&away);
            scale = object->scl[0];
            if (object->scl[1] > scale) {
                scale = object->scl[1];
            }
            if (object->scl[2] > scale) {
                scale = object->scl[2];
            }
            if (distance > scale * object->model->r) {
                continue;
            }
        }
        if (objects[i].flags & WORLD_LIQUID) {
            if (polygon_find_model_heights(&query, objects[i].object)) {
                if (query.above.found == TRUE &&
                    query.pos.y < query.above.level &&
                    query.above.level < above.y) {
                    above.y = query.above.level;
                } else if (query.below.found == TRUE &&
                           query.pos.y > query.below.level &&
                           query.below.level < below.y) {
                    /* @bug logic: below.y starts at -NO_WATER, so FCMP/GT
                     * at 0x8c01cb1c passes only a level under -NO_WATER, and
                     * no water below the point is kept */
                    below.y = query.below.level;
                }
            }
        }
    }
    if (above.y == NO_WATER && below.y == -NO_WATER) {
        return;
    }

    /* below_plane lies at above.y, as above_plane does, so below takes the
     * point above takes. where above projects off the screen, the code below
     * projects that same point again. where the planes don't meet, each else
     * sets above.y to -NO_WATER */
    above_plane.px = eye.x;
    above_plane.py = above.y;
    above_plane.pz = eye.z;
    above_plane.vx = 0.0F;
    above_plane.vy = 1.0F;
    above_plane.vz = 0.0F;
    below_plane.px = eye.x;
    below_plane.py = above.y;
    below_plane.pz = eye.z;
    below_plane.vx = 0.0F;
    below_plane.vy = 1.0F;
    below_plane.vz = 0.0F;
    {
        NJS_LINE line;

        /* @hack type: the union's own address as the NJS_PLANE, which SHC
         * forms from R15 at each use; as &facing.plane here too, it keeps
         * the address in a saved register, the function runs 4 bytes long
         * and 274 of 486 words differ */
        if (njDistancePL2PL((NJS_PLANE *)&facing, &above_plane, &line) ==
            0.0F) {
            above.x = line.px;
            above.y = line.py;
            above.z = line.pz;
        } else {
            above.y = -NO_WATER;
        }
        if (njDistancePL2PL(&facing.plane, &below_plane, &line) == 0.0F) {
            below.x = line.px;
            below.y = line.py;
            below.z = line.pz;
        } else {
            above.y = -NO_WATER;
        }
    }
    njPushMatrix(NULL);
    njProjectScreen(NULL, &above, &screen);
    late_DrawObjectClipEx(1);
    if (screen.y < 0.0F || screen.y > SCREEN_HEIGHT) {
        njPushMatrix(NULL);
        njProjectScreen(NULL, &below, &screen);
        late_DrawObjectClipEx(1);
    }

    {
        NJS_POINT2COL polygon;

        {
            NJS_POINT2 line[2];
            NJS_COLOR colors[2];

            /* draw a line along row 490, below the screen's 480 rows and
             * out of sight */
            polygon.p = line;
            polygon.col = colors;
            polygon.tex = NULL;
            polygon.num = 2;
            polygon.p[0].x = 0.0F;
            polygon.p[1].x = SCREEN_WIDTH;
            polygon.p[0].y = 490.0F;
            polygon.p[1].y = 490.0F;
            polygon.col[0].color = 0xff88;
            polygon.col[1].color = 0xff88;
            FUN_8c63e114(&polygon, 2, -2.0F, 0x00000040);
        }
        {
            NJS_POINT2 quad[4];

            y = (Sint16)screen.y;
            if (y < 0 || y > 480) {
                y = 0;
            }
            polygon.p = quad;
            polygon.col = tint_colors;
            polygon.tex = NULL;
            polygon.num = 4;
            quad[0].x = 0.0F;
            quad[0].y = (Float)y;
            quad[1].x = 0.0F;
            quad[1].y = SCREEN_HEIGHT;
            quad[2].x = SCREEN_WIDTH;
            quad[2].y = SCREEN_HEIGHT;
            quad[3].x = SCREEN_WIDTH;
            quad[3].y = (Float)y;
            njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                                   NJD_COLOR_BLENDING_SRCALPHA);
            njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                                   NJD_COLOR_BLENDING_ONE);
            SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
            njDrawPolygon2D(&polygon, 4, 0.0F, NJD_FILL | NJD_TRANSPARENT);
        }
    }
}

Bool camera_sweep_hits(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                       Float radius)
{
    return world_sweep_ball_hit(pos, speed, ang, WORLD_LIQUID, radius);
}

void camera_task_draw_tint(struct task *task)
{
    FUN_8c01bd9e();
}
extern NJS_POINT3 camera_trail[50];
extern int camera_trail_index;
void FUN_8c01c29a(void)
{
    int i;
    for (i = 0; i < 50; i++) {
        camera_trail[i] = playertwp[0]->pos;
    }
    camera_trail_index = 0;
}
void FUN_8c01c2d8(void)
{
    NJS_VECTOR d;
    NJS_POINT3 *last;
    int i;
    int n;
    if (camera_trail_index == 0) {
        i = 49;
    } else {
        i = camera_trail_index - 1;
    }
    last = &camera_trail[i];
    d.x = playertwp[0]->pos.x - last->x;
    d.y = (playertwp[0]->pos.y - last->y) +
          GetPlayerWorkPointer(0)->consts.eye_height;
    d.z = playertwp[0]->pos.z - last->z;
    if (njScalor(&d) > 1.0F) {
        camera_trail[camera_trail_index].x = playertwp[0]->pos.x;
        camera_trail[camera_trail_index].y =
            playertwp[0]->pos.y + GetPlayerWorkPointer(0)->consts.eye_height;
        camera_trail[camera_trail_index].z = playertwp[0]->pos.z;
        camera_trail_index = camera_trail_index + 1;
        if (camera_trail_index >= 50) {
            camera_trail_index = 0;
        }
    }
}
NJS_POINT3 *FUN_8c01c432(int back)
{
    int i = camera_trail_index - back;
    if (i < 0) {
        i += 50;
    }
    return &camera_trail[i];
}
