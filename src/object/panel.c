/* @unit 8C05E5C0-8C05EF40 @data 8C154BF8-8C154C38 +r04 +egflags +pool32 */
/* jump panels, O JPanel: numbered panels that player 0 jumps along */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "object/common.h"
#include "object/models.h"
#include "object/panel.h"
#include "object/placement.h"
#include "player/player.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
#include "system/texture.h"
#include "system/util.h"
float njArcTan2(float y, float x);
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
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
void FUN_8c05e6c8(struct task_work *work);
int FUN_8c05e714(struct task_work *work, struct task_motion *motion,
                 struct player *player);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
void *syMalloc_default_malloc(size_t size);
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

/* panels 0 to 9, each kept in panel_tasks at its number */
#define PANEL_COUNT 10

/* the id in a panel's work, by which panel_touched knows a panel */
#define PANEL_ID 8

/* player 0 can jump from a panel numbered 2 or more only in its first
 * PANEL_WAIT steps touching the panel. the count of those steps stops at
 * PANEL_WAIT_MAX */
#define PANEL_WAIT 30
#define PANEL_WAIT_MAX 3600

/* the index in panel_shapes of a numbered panel's top, from which player 0
 * jumps, and of panel 0's one shape */
#define TOP_SHAPE 1
#define END_SHAPE 3

/* a flight's speed a step: at least FLY_SPEED, and gaining FLY_GAIN a step
 * while under FLY_TOP */
#define FLY_SPEED 9.0F
#define FLY_GAIN 0.5F
#define FLY_TOP 15.0F

/* a flight aims the center of the player's first shape at a point above the
 * panel, along the panel's up: the player's consts.center_y plus AIM_ABOVE.
 * it lands the player LAND_ABOVE above the panel */
#define AIM_ABOVE 3.8F
#define LAND_ABOVE 3.3F

/* a panel draws while the camera is within DRAW_RANGE of it */
#define DRAW_RANGE 500.0F

/* the spark's frames, each held for two steps */
#define SPARK_FRAMES 5

/* a panel's mode: whether a jump leaves it or flies to it */
#define VARS(work) ((struct panel_vars *)&(work)->vars)
#define NUMBER(work) TASK_TIMER(work)
enum panel_mode {
    PANEL_IDLE,
    PANEL_LEFT, /* the panel the player jumped from */
    PANEL_NEXT /* the panel the player flies to */
};

struct panel_vars {
    void *param; /* the object kind's param, which no panel reads */
    /* the steps player 0 has touched a panel numbered 2 or more without a
     * break */
    Sint32 touched;
};

/* a panel's number, from the set file's scale x, kept in the work's timer
 * and read unsigned */

void panel_idle_all(void);
void ObjectJumpPanelSetNumber(struct task *task);
void FUN_8c05ebb2(struct task *task);
static void panel_step(struct task *task);
static void panel_draw(struct task *task);
void panel_destroy(struct task *task);
static void panel_spark_draw(struct task *task);
static void panel_spark_step(struct task *task);
void panel_spark_start(struct task *task);
extern struct collision_shape panel_shapes[4];
extern NJS_TEXLIST panel_number_textures[10];
extern NJS_TEXLIST panel_spark_textures[5];
extern NJS_TEXANIM panel_spark_texanims[5];
extern NJS_SPRITE panel_spark_sprite;
extern struct task *panel_tasks[10];

void panel_reset(void)
{
    int i;

    for (i = 0; i < PANEL_COUNT; i++) {
        panel_tasks[i] = NULL;
    }
}

void panel_idle_all(void)
{
    int i;

    for (i = 0; i < PANEL_COUNT; i++) {
        /* @hack spelling: the continue past an empty slot, which keeps the loop
         * rolled (BT/S at 0x8c06196e); as an if around the store, SHC
         * unrolls it and 19 of 21 words differ */
        if (panel_tasks[i] == NULL) {
            continue;
        }
        panel_tasks[i]->work->mode = PANEL_IDLE;
    }
}

Bool panel_touched(struct task_work *work)
{
    struct collision_work *hit = work->collision->hit;
    struct task_work *panel;

    if (hit == NULL) {
        return FALSE;
    }
    if (PLAYER_VARS(work)->player != 0) {
        return FALSE;
    }
    panel = hit->owner->work;
    if (panel->id != PANEL_ID) {
        return FALSE;
    }
    return TRUE;
}

int panel_jump_ready_or_idle(struct task_work *work)
{
    struct collision_work *hit;
    struct task_work *panel;

    if (!panel_touched(work)) {
        if (PLAYER_VARS(work)->player == 0) {
            panel_idle_all();
        }
        return 0;
    }
    hit = work->collision->hit;
    panel = hit->owner->work;
    if (NUMBER(panel) == 0) {
        panel_idle_all();
        return -1;
    }
    if (work->collision->hit_shape != TOP_SHAPE) {
        panel_idle_all();
        return 0;
    }
    /* @hack type: touched compared as a Float, which the image converts with
     * FLOAT and tests with FCMP/GT (0x8c0619f4, 0x8c0619f6); compared as an
     * int, 20 of 51 words differ */
    if (VARS(panel)->touched >= (Float)PANEL_WAIT) {
        panel_idle_all();
        return 0;
    }
    return 1;
}

void FUN_8c05e6c8(struct task_work *work)
{
    struct collision_work *hit;
    struct task_work *panel;
    Sint16 number;

    panel_idle_all();
    hit = work->collision->hit;
    panel = hit->owner->work;
    number = NUMBER(panel);
    panel->mode = PANEL_LEFT;
    {
        int n = number;
        if (n == 10 - 1) {
            number = 0;
        } else if (panel_tasks[++n] == ((void *)0)) {
            number = 0;
        } else {
            number++;
        }
    }
    panel_tasks[number]->work->mode = PANEL_NEXT;
}

int FUN_8c05e714(struct task_work *work, struct task_motion *motion,
                 struct player *player)
{
    struct task_work *next;
    Sint16 i;
    struct task *spark;
    NJS_VECTOR way;
    NJS_VECTOR up;
    NJS_VECTOR offset;
    Angle ang_x;
    Angle ang_y;
    Angle ang_z;
    Float distance;
    Float speed;

    /* @hack spelling: the search as a do-while, which indexes panel_tasks by i
     * on each pass (MOV.L @(R0,R6),R3 at 0x8c061ab8); as a for loop, SHC
     * walks three pointers instead and 52 of 383 words differ */
    i = 0;
    next = NULL;
    do {
        if (panel_tasks[i] == NULL) {
            return 0;
        }
        if (panel_tasks[i]->work->mode == PANEL_NEXT) {
            next = panel_tasks[i]->work;
            break;
        }
    } while (++i < PANEL_COUNT);
    if (next == NULL) {
        return 0;
    }
    up.x = up.z = 0.0F;
    up.y = player->consts.center_y + AIM_ABOVE;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, next->ang.z);
    TURN(njRotateX, next->ang.x);
    TURN(njRotateY, next->ang.y);
    njCalcVector(NULL, &up, &way);
    late_DrawObjectClipEx(1);
    /* @hack spelling: the offset added last, which sums into FR2 (FADD FR3,FR2
     * at 0x8c061b96, 0x8c061bae and 0x8c061bca); with +=, SHC sums into FR3
     * and 6 of 383 words differ */
    way.x = next->pos.x - work->collision->shapes->center.x + way.x;
    way.y = next->pos.y - work->collision->shapes->center.y + way.y;
    way.z = next->pos.z - work->collision->shapes->center.z + way.z;
    distance = njScalor(&way);
    speed = njScalor(&motion->speed);
    njUnitVector(&way);
    ang_x = next->ang.x;
    ang_z = next->ang.z;
    if (distance <= speed) {
        up.x = up.z = 0.0F;
        up.y = LAND_ABOVE;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, next->ang.z);
        TURN(njRotateX, next->ang.x);
        njCalcVector(NULL, &up, &offset);
        late_DrawObjectClipEx(1);
        work->pos.x = next->pos.x + offset.x;
        work->pos.y = next->pos.y + offset.y;
        work->pos.z = next->pos.z + offset.z;
        work->ang.x = ang_x;
        work->ang.y = -next->ang.y;
        work->ang.z = ang_z;
        player_clear_speed(motion, player);
        work->flags |= PLAYER_ON_TASK;
        panel_idle_all();
        distance = 0.0F;
        if ((spark = CreateElementalTask(TASK_WORK, 6, panel_spark_start)) !=
            NULL) {
            spark->work->pos = work->pos;
            spark->work->ang = next->ang;
        }
    } else {
        if (speed < FLY_SPEED) {
            speed = FLY_SPEED;
        } else if (speed < FLY_TOP) {
            speed += FLY_GAIN;
        }
        way.x *= speed;
        way.y *= speed;
        way.z *= speed;
        motion->speed = way;
        work->pos.x += way.x;
        work->pos.y += way.y;
        work->pos.z += way.z;
        ang_z = -(Angle)(njArcTan2(way.x, way.y) * ANGLE_PER_RADIAN);
        ang_x = (Angle)(asinf(way.z) * ANGLE_PER_RADIAN);
        ang_y = (Angle)(njArcTan2(way.x, -way.z) * ANGLE_PER_RADIAN);
        work->ang.x = AdjustAngle(work->ang.x, ang_x, NJM_DEG_ANG(22.5));
        work->ang.y = AdjustAngle(work->ang.y, ang_y, NJM_DEG_ANG(22.5));
        work->ang.z = AdjustAngle(work->ang.z, ang_z, NJM_DEG_ANG(22.5));
        player_turn_back(work, &way);
        player->speed = way;
    }
    return (int)(distance * (1.0F / FLY_SPEED));
}

int panel_get_left(void)
{
    int i;
    int left = 0;

    for (i = 0; i < PANEL_COUNT; i++) {
        /* @hack spelling: the continue past an empty slot, as in panel_idle_all
         * (BT at 0x8c061eca); as an if around the test, 23 of 23 words
         * differ */
        if (panel_tasks[i] == NULL) {
            continue;
        }
        if (panel_tasks[i]->work->mode == PANEL_LEFT) {
            left = i;
        }
    }
    return left;
}

void ObjectJumpPanel(struct task *task)
{
    struct task_work *work = task->work;

    work->id = PANEL_ID;
    if (!OnEdit(task)) {
        ObjectJumpPanelSetNumber(task);
        /* @hack spelling: the radius stored in each arm, which puts
         * collision_init's address in R3 and the count of 2 in R2
         * (0x8c061f1e, 0x8c061f20); stored once after the arms, the two
         * trade and 8 of 61 words differ */
        if (NUMBER(work) == 0) {
            CCL_Init(task, &panel_shapes[END_SHAPE], COLLISION_OBJECT, 1, 1);
            work->collision->radius = 10.3F;
        } else {
            CCL_Init(task, panel_shapes, COLLISION_OBJECT, 1, 2);
            work->collision->radius = 10.3F;
        }
        panel_tasks[NUMBER(work)] = task;
    }
    task->destructor = panel_destroy;
    task->draw = panel_draw;
    task->step = panel_step;
}

/* the number is scale x, truncated. a scale x below 0, or of 10 or more, is
 * set to 0 first */
void ObjectJumpPanelSetNumber(struct task *task)
{
    struct task_work *work = task->work;

    if (work->scl.x >= PANEL_COUNT || work->scl.x < 0.0F) {
        work->scl.x = 0.0F;
    }
    work->timer = njRoundOff(work->scl.x);
}

/* count the steps player 0 touches a panel numbered 2 or more, up to
 * PANEL_WAIT_MAX. any other step sets the count to 0 */
void FUN_8c05ebb2(struct task *task)
{
    struct task_work *work = task->work;
    struct collision_work *hit;

    if (work->collision != NULL) {
        /* @hack spelling: the hit read through task->work again (MOV.L
         * @(32,R4),R3 at 0x8c061fda); through work, 35 of 36 words differ */
        hit = task->work->collision->hit;
        if (hit != NULL && hit->kind == COLLISION_PLAYER &&
            PLAYER_VARS(hit->owner->work)->player == 0 && NUMBER(work) != 0 &&
            NUMBER(work) != 1) {
            if (VARS(work)->touched++ >= PANEL_WAIT_MAX) {
                VARS(work)->touched = PANEL_WAIT_MAX;
            }
        } else {
            VARS(work)->touched = 0;
        }
    }
}

/* the panel marked left registers no collision, so the player flying off
 * it doesn't touch it */
static void panel_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        FUN_8c05ebb2(task);
        if (work->mode != PANEL_LEFT) {
            EntryColliList(work);
        }
        ObjectSetupInput(work, NULL);
    } else {
        ObjectJumpPanelSetNumber(task);
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_X), "-> ROTATION X");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "-> ROTATION Y");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Z), "-> ROTATION Z");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "-> PANEL NUMBER");
    }
    panel_draw(task);
}

/* draw the panel while the camera is within DRAW_RANGE. panel 0 draws only
 * while the set editor is open */
static void panel_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (CalcDistance(&camera_twp->pos, &work->pos) < DRAW_RANGE &&
        (NUMBER(work) != 0 || edit_mode != 0)) {
        SaveConstantAttr();
        OffConstantAttr(0, NJD_FLAG_IGNORE_SPECULAR);
        njPushMatrix(NULL);
        SetRegularTexture();
        njTranslateV(NULL, &work->pos);
        TURN(njRotateZ, work->ang.z);
        TURN(njRotateX, work->ang.x);
        TURN(njRotateY, work->ang.y);
        if (NUMBER(work) == 0) {
            late_DrawObject(&panel_end_object);
        } else {
            late_DrawObject(&panel_object);
            njSetTexture_jp(&panel_number_textures[NUMBER(work)]);
            late_DrawObject(&panel_number_object);
        }
        late_DrawObjectClipEx(1);
        LoadConstantAttr();
    }
}

/* empty the panel's slot, unless a later panel of its number holds it */
void panel_destroy(struct task *task)
{
    Sint16 number = NUMBER(task->work);

    if (panel_tasks[number] == task) {
        panel_tasks[number] = NULL;
    }
}

/* draw only on a display frame's first step, frame_step 0 */
static void panel_spark_draw(struct task *task)
{
    struct task_work *work = task->work;
    int frame = work->tick >> 1;

    if (loop_count != 0) {
        return;
    }
    panel_spark_sprite.tlist = &panel_spark_textures[frame];
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njRotateX(NULL, NJM_DEG_ANG(90));
    njDrawSprite3D(&panel_spark_sprite, frame, NJD_SPRITE_ALPHA);
    late_DrawObjectClipEx(1);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_BOTHSRCALPHA);
}

static void panel_spark_step(struct task *task)
{
    struct task_work *work = task->work;
    if (++work->tick >= 9) {
        FreeTask(task);
    } else {
        panel_spark_draw(task);
    }
}

void panel_spark_start(struct task *task)
{
    task->step = panel_spark_step;
    task->draw = panel_spark_draw;
    panel_spark_draw(task);
}
