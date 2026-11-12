/* @unit 8C063040-8C0648C0 @data 8C154FB8-8C154FD8 +r04 +egflags +pool32 +poolafter=FUN_8c063040,FUN_8c063160,FUN_8c0632a0,FUN_8c0633c0,rocket_launcher_init_v,rocket_fly_v,rocket_take_off,rocket_get_grip +poolbra=rocket_launcher_open_v:j1 +poolbra=rocket_step:1 +poolbra=rocket_vanish_h_step:1 +poolbra=rocket_rise:1 +poolbra=rocket_pull:1 +poolbra=rocket_jet_draw:1 +onepool */
/* rockets: one rises out of its launcher, and a player who takes its grip
 * rides it toward a target, along or up, until the player lets go */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>
#include <stdlib.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "draw/pose.h"
#include "effect/dust.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "object/helpers.h"
#include "object/models.h"
#include "object/placement.h"
#include "object/rocket.h"
#include "object/switch.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "system/frame.h"
#include "system/pad.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
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
void pdExecPeripheralServerUser(void);
void *syMalloc_default_malloc(size_t size);
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
extern struct task_work *camera_twp;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void SetMleriRangeRad(Float radius);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool GetMMMatrix(Uint32 node, NJS_MATRIX *out);
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
Float vector_reflect(NJS_VECTOR *vector, NJS_VECTOR *normal_jp,
                     NJS_VECTOR *out);
Bool polygon_contains(NJS_POINT3 *point, NJS_POINT3 *corners,
                      NJS_VECTOR *normal_jp, int count);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void FUN_8c063040(struct task *task);
void FUN_8c063160(struct task *task);
void FUN_8c0632a0(struct task *task);
void FUN_8c0633c0(struct task *task);
void ObjectSwitch(struct task *task);
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
struct player *GetPlayerWorkPointer(Uint8 player);
int GetTheNearestPlayerNumber(NJS_POINT3 *pos);
Bool CheckPlayerRideOnMobileLandObjectP(Uint8 player, struct task *task);
void SetLookingTaskP(Uint8 player, struct task *task, NJS_POINT3 *offset);
void SetLookingPointP(Uint8 player, NJS_POINT3 *pos);
void CancelLookingAtP(Uint8 player);
void HoldOnPillarP(Uint8 player, NJS_POINT3 *pos, Uint32 steps);
void KeepPlayersEyesOnThePointP(Uint8 player, struct angles *ang, Uint32 steps);
void SetVelocityAndRotationAndNoconTimeWithSpinDashP(Uint8 player,
                                                     NJS_VECTOR *speed,
                                                     const Angle *ang,
                                                     Sint16 steps);
void FUN_8c07c93a(Uint8 player, Float x, Float y, Float z);
Bool GetPlayerPosition(Uint8 player, int steps, NJS_POINT3 *pos,
                       struct angles *ang);
void kmiLogFileOpen(void *data);
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
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
Uint16 GetStageNumber(void);
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

#define SE_LAUNCHER_OPEN 705
#define SE_ROCKET_FIRE 706

/* the frames of its action a launcher plays each step */
#define LAUNCHER_PACE 0.05F

/* a new rocket rises for RISE_STEPS steps for each frame of its launcher's
 * action, to lift its grip GRIP_HEIGHT above where the rocket started. the
 * grip is node GRIP_NODE of the rocket's action */
#define RISE_STEPS 20.0F
#define GRIP_HEIGHT 8.0F
#define GRIP_NODE 3

/* how far along its launcher's x a rocket that flies up starts */
#define UP_OFFSET 4.0F

/* a player takes hold once its hands are within TAKE_RANGE of the grip,
 * and within TAKE_HEIGHT of its height. the pull onto the grip then takes
 * PULL_STEPS steps */
#define TAKE_RANGE 5.5F
#define TAKE_HEIGHT 2.0F
#define PULL_STEPS 6.0F

/* a flying rocket's speed grows by FLY_ACCEL each step until it passes
 * FLY_SPEED */
#define FLY_SPEED 12.0F
#define FLY_ACCEL 0.9F

/* the step of the flight from which the rider may let go, along and up */
#define ALONG_LET_GO 10
#define UP_LET_GO 15
/* how far above the target the rider of a rocket that flies up lets go */
#define UP_REACH 300.0F

/* once the rider has let go, a rocket that flies along blinks after
 * ALONG_BLINK steps and ends at ALONG_VANISH. one that flies up waits for
 * the rider to land after UP_VANISH steps */
#define ALONG_BLINK 30
#define ALONG_VANISH 60
#define UP_VANISH 30

/* bits of a launcher's state */
#define LAUNCHER_FIRED 0x4 /* its rocket has taken off */
#define LAUNCHER_GONE 0x8 /* it has left range, which ends its rocket */

/* a launcher's own layout of task_work. target is the placed scl */
struct launcher_work {
    Sint8 mode;
    /* the switch that opens ROCKET HS and VS: the placed ang.x's low four
     * bits */
    Uint8 id;
    Uint8 unk_02;
    Uint8 state;
    Sint16 flags;
    Sint16 timer;
    NJS_ACTION *action;
    NJS_OBJECT *world; /* its model, in the collision world */
    Float frame;
    struct angles ang;
    NJS_POINT3 pos;
    NJS_POINT3 target; /* where its rockets fly to */
    struct collision_work *collision;
    struct event_work *event;
};

/* what a launcher keeps in its task's extra */
struct launcher_extra {
    Float reach; /* how far across its rockets fly, squared */
    Angle climb; /* the turn about z that, with ang.y, aims at the target */
};

enum launcher_mode {
    LAUNCHER_INIT,
    LAUNCHER_READY, /* closed, and waits to open */
    LAUNCHER_OPEN, /* its action plays on, to its last frame */
    LAUNCHER_WAIT, /* open, and waits for its rocket to take off */
    LAUNCHER_CLOSE /* its action plays back */
};

/* what a rocket keeps in its task's motion */
struct rocket_motion {
    struct launcher_work *launcher; /* the work of the launcher that made it */
    NJS_VECTOR speed; /* as it rises, and as it pulls its rider on */
    /* where its grip is in the world, once it has risen. once it flies, x
     * is its speed */
    NJS_POINT3 grip;
    Uint8 unk_1c[24];
    Float reach; /* how far it flies across, squared */
    Float steps; /* the steps left to pull the rider on */
    Float count; /* steps left to rise, then its action's last frame */
};

/* where a rocket starts, in its task's force */
struct rocket_origin {
    Uint8 unk_00[16];
    NJS_POINT3 pos;
};

/* a rocket's jet, in its task's extra: lit once it flies, and its frame */
struct rocket_jet {
    Uint8 lit;
    Float frame;
};

/* a rocket's work mode, which changes along with its task's step */
enum rocket_mode {
    ROCKET_START,
    ROCKET_RISE,
    ROCKET_WAIT, /* waits for a player to take hold */
    ROCKET_PULL, /* pulls the player onto its grip */
    ROCKET_TAKE_OFF, /* its action plays as it takes off */
    ROCKET_FLY,
    ROCKET_VANISH, /* blinks out once the rider has let go */
    ROCKET_END,
    ROCKET_DROPPED
};
extern const struct collision_shape rocket_shape;
extern const NJS_POINT3 rocket_grip_hands[8];
extern const NJS_POINT3 rocket_along_hands[8];
extern const NJS_POINT3 rocket_up_hands[8];
extern NJS_TEXLIST rocket_jet_texlist;
extern NJS_TEXANIM rocket_jet_frames[3];
extern NJS_SPRITE rocket_jet_sprite;
extern NJS_TEXLIST rocket_thrust_texlist;
extern NJS_TEXANIM rocket_thrust_frames[8];
extern struct particle_anim rocket_thrust_anim;
extern struct particle_pool_spec rocket_thrust_pool;
extern struct dust_params rocket_thrust_params;
extern struct rocket_work *rockets[10];

static void rocket_launcher_init_h(struct task *task);
static void rocket_launcher_init_v(struct task *task);
static void rocket_launcher_open_h(struct task *task);
static void rocket_launcher_open_v(struct task *task);
static void rocket_launcher_opened(struct task *task);
static void rocket_launcher_close(struct task *task);
static void rocket_launcher_draw(struct task *task);
static void rocket_launcher_destroy(struct task *task);
static void rocket_step(struct task *task);
static void rocket_end_step(struct task *task);
static void rocket_land_step(struct task *task);
static void rocket_drop_step(struct task *task);
static void rocket_start(struct task *task);
static void rocket_rise(struct rocket_work *work, struct rocket_motion *motion);
static void rocket_fly_h(struct task *task);
static void rocket_fly_v(struct task *task);
static Bool ChkPlayerCanHold(struct task *task, Uint8 player);
static Bool rocket_pull(struct task *task);
static Bool rocket_take_off(struct task *task);
static void rocket_move(struct task *task);
static void rocket_get_grip(struct rocket_work *work, NJS_ACTION *action,
                            Float frame, NJS_POINT3 *out);
static void rocket_draw(struct task *task);
static void rocket_destroy(struct task *task);
static void rocket_thrust_create(NJS_POINT3 *pos, NJS_VECTOR *speed,
                                 Float scale);
static void rocket_jet_draw(struct task *task);
static void rocket_thrust_emit(struct task *task);

/* leave the launcher closed, at frame 0, to wait for its switch */
static void rocket_launcher_rest(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    work->mode = LAUNCHER_READY;
    work->frame = 0.0F;
}

/* ROCKET H's step. the launcher opens with a rocket in it, closes once the
 * rocket takes off, and opens again with the next. its rockets fly along,
 * toward its target */
void FUN_8c063040(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    if (OnEdit(task)) {
        njPrintC(NJM_LOCATION(17, 19), "Target Position");
    }
    if (CheckRangeOut(task)) {
        work->state |= LAUNCHER_GONE;
        return;
    }
    switch (work->mode) {
    case LAUNCHER_INIT:
        rocket_launcher_init_h(task);
        rocket_launcher_open_h(task);
        break;
    case LAUNCHER_READY:
        if (work->state & LAUNCHER_FIRED) {
            rocket_launcher_open_h(task);
        }
        break;
    case LAUNCHER_OPEN:
        /* @hack spelling: the frame stepped in the test, which compares the
         * FR3 it stores (FCMP/GT FR3,FR2 at 0x8c06680c); stepped apart, SHC
         * loads the frame back, task and work trade R14 and R13, and 63 of
         * 107 words differ */
        if ((work->frame += LAUNCHER_PACE) >=
            (Float)work->action->motion->nbFrame - 1.0F) {
            rocket_launcher_opened(task);
        }
        break;
    case LAUNCHER_WAIT:
        if (work->state & LAUNCHER_FIRED) {
            rocket_launcher_close(task);
        }
        break;
    case LAUNCHER_CLOSE:
        /* @hack spelling: the frame stepped in the test, which stores it in the
         * branch's delay slot (FMOV.S FR3,@(R0,R13) at 0x8c066834); stepped
         * apart, task and work trade R14 and R13 and 24 of 107 words
         * differ */
        if ((work->frame -= LAUNCHER_PACE) < 0.0F) {
            rocket_launcher_open_h(task);
        }
        break;
    }
    object_world_test((struct task_work *)work, work->world);
    object_step_draw(task);
}

/* ROCKET HS's step: as ROCKET H's, but the launcher opens only while its
 * switch is on, and turns the switch off once it has closed */
void FUN_8c063160(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    if (OnEdit(task)) {
        njPrintC(NJM_LOCATION(17, 16), "<- ID Number");
        njPrintC(NJM_LOCATION(17, 19), "Target Position");
    }
    if (CheckRangeOut(task)) {
        work->state |= LAUNCHER_GONE;
        return;
    }
    switch (work->mode) {
    case LAUNCHER_INIT:
        rocket_launcher_init_h(task);
        break;
    case LAUNCHER_READY:
        if (switch_is_on(work->id)) {
            rocket_launcher_open_h(task);
        }
        break;
    case LAUNCHER_OPEN:
        /* @hack spelling: the frame stepped in the test, as in rocket_h_step
         * (FCMP/GT FR3,FR2 at 0x8c066934); stepped apart, SHC loads the
         * frame back, the function runs 4 bytes long and 59 of 121 words
         * differ */
        if ((work->frame += LAUNCHER_PACE) >=
            (Float)work->action->motion->nbFrame - 1.0F) {
            rocket_launcher_opened(task);
        }
        break;
    case LAUNCHER_WAIT:
        if (work->state & LAUNCHER_FIRED) {
            rocket_launcher_close(task);
        }
        break;
    case LAUNCHER_CLOSE:
        work->frame -= LAUNCHER_PACE;
        if (work->frame < 0.0F) {
            switch_set(work->id, FALSE);
            rocket_launcher_rest(task);
        }
        break;
    }
    object_world_test((struct task_work *)work, work->world);
    object_step_draw(task);
}

/* ROCKET V's step: as ROCKET H's, but its rockets fly up */
void FUN_8c0632a0(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    if (OnEdit(task)) {
        njPrintC(NJM_LOCATION(17, 19), "Target Position");
    }
    if (CheckRangeOut(task)) {
        work->state |= LAUNCHER_GONE;
        return;
    }
    switch (work->mode) {
    case LAUNCHER_INIT:
        rocket_launcher_init_v(task);
        rocket_launcher_open_v(task);
        break;
    case LAUNCHER_READY:
        if (work->state & LAUNCHER_FIRED) {
            rocket_launcher_open_v(task);
        }
        break;
    case LAUNCHER_OPEN:
        /* @hack spelling: the frame stepped in the test, as in rocket_h_step
         * (FCMP/GT FR3,FR2 at 0x8c066a6c); stepped apart, 63 of 107 words
         * differ */
        if ((work->frame += LAUNCHER_PACE) >=
            (Float)work->action->motion->nbFrame - 1.0F) {
            rocket_launcher_opened(task);
        }
        break;
    case LAUNCHER_WAIT:
        if (work->state & LAUNCHER_FIRED) {
            rocket_launcher_close(task);
        }
        break;
    case LAUNCHER_CLOSE:
        /* @hack spelling: the frame stepped in the test, as in rocket_h_step
         * (FMOV.S FR3,@(R0,R13) at 0x8c066a94); stepped apart, 24 of 107
         * words differ */
        if ((work->frame -= LAUNCHER_PACE) < 0.0F) {
            rocket_launcher_open_v(task);
        }
        break;
    }
    object_world_test((struct task_work *)work, work->world);
    object_step_draw(task);
}

/* ROCKET VS's step: as ROCKET HS's, but its rockets fly up */
void FUN_8c0633c0(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    if (OnEdit(task)) {
        njPrintC(NJM_LOCATION(17, 16), "<- ID Number");
        njPrintC(NJM_LOCATION(17, 19), "Target Position");
    }
    if (CheckRangeOut(task)) {
        work->state |= LAUNCHER_GONE;
        return;
    }
    switch (work->mode) {
    case LAUNCHER_INIT:
        rocket_launcher_init_v(task);
        break;
    case LAUNCHER_READY:
        if (switch_is_on(work->id)) {
            rocket_launcher_open_v(task);
        }
        break;
    case LAUNCHER_OPEN:
        /* @hack spelling: the frame stepped in the test, as in rocket_hs_step
         * (FCMP/GT FR3,FR2 at 0x8c066b94); stepped apart, 59 of 121 words
         * differ */
        if ((work->frame += LAUNCHER_PACE) >=
            (Float)work->action->motion->nbFrame - 1.0F) {
            rocket_launcher_opened(task);
        }
        break;
    case LAUNCHER_WAIT:
        if (work->state & LAUNCHER_FIRED) {
            rocket_launcher_close(task);
        }
        break;
    case LAUNCHER_CLOSE:
        work->frame -= LAUNCHER_PACE;
        if (work->frame < 0.0F) {
            switch_set(work->id, FALSE);
            rocket_launcher_rest(task);
        }
        break;
    }
    object_world_test((struct task_work *)work, work->world);
    object_step_draw(task);
}

void rocket_reset(void)
{
    struct rocket_work **slot = rockets;
    int i;

    for (i = 0; i < ROCKET_COUNT; i++) {
        *slot++ = NULL;
    }
}

/* put the rocket in the first free slot of rockets. TRUE when there is
 * one, else FALSE, and the rocket's slot stays as it was */
static Bool rocket_enter(struct rocket_work *work)
{
    struct rocket_work **slot = rockets;
    int i;

    for (i = 0; i < ROCKET_COUNT; i++) {
        if (*slot == NULL) {
            *slot = work;
            work->slot = i;
            return TRUE;
        }
        slot++;
    }
    return FALSE;
}

/* set up a launcher of ROCKET H or HS, facing its target. extra keeps how
 * far across the target is, squared */
static void rocket_launcher_init_h(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;
    struct launcher_extra *extra = (struct launcher_extra *)task->extra;
    NJS_OBJECT *world;

    work->action = &rocket_launcher_action;
    task->draw = rocket_launcher_draw;
    task->destructor = rocket_launcher_destroy;
    work->mode = LAUNCHER_READY;
    work->id = work->ang.x & 0xf;
    work->ang.x = 0;
    VecTemp0.x = work->target.x - work->pos.x;
    VecTemp0.y = work->target.y - work->pos.y;
    VecTemp0.z = work->target.z - work->pos.z;
    vector_aim_x(&VecTemp0, &work->ang.y, &extra->climb);
    extra->reach = (VecTemp0.x * VecTemp0.x) + (VecTemp0.z * VecTemp0.z);
    /* @hack spelling: world set in the test, which tests R0 and copies it in
     * the branch's delay slot (TST R0,R0 at 0x8c066cf8); set apart, SHC
     * tests the copy and 3 of 80 words differ */
    if ((world = object_add_world_model(task, rocket_launcher_object->model)) !=
        NULL) {
        work->world = world;
        object_world_follow((struct task_work *)work, world);
    }
}

/* set up a launcher of ROCKET V or VS */
static void rocket_launcher_init_v(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;
    NJS_OBJECT *world;

    work->action = &rocket_launcher_action;
    task->draw = rocket_launcher_draw;
    task->destructor = rocket_launcher_destroy;
    work->mode = LAUNCHER_READY;
    work->id = work->ang.x & 0xf;
    work->ang.x = 0;
    /* @hack spelling: world set in the test, which keeps it in R13 (MOV R0,R13
     * at 0x8c066d4a); set apart, it stays in R5, the function runs short
     * and 33 of 36 words differ */
    if ((world = object_add_world_model(task, rocket_launcher_object->model)) !=
        NULL) {
        work->world = world;
        object_world_follow((struct task_work *)work, world);
    }
}

/* open the launcher and put a new rocket in it, facing the target. in the
 * set editor the launcher opens empty. the rocket rises for RISE_STEPS steps
 * for each frame of the launcher's action. its speed would lift its grip
 * GRIP_HEIGHT above its start in that time, but it moves on all but the
 * last step */
static void rocket_launcher_open_h(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;
    struct launcher_extra *extra = (struct launcher_extra *)task->extra;
    struct task *rocket;
    struct rocket_work *rocket_work;
    struct rocket_motion *motion;
    Float rise;

    work->mode = LAUNCHER_OPEN;
    work->frame = 0.0F;
    work->state &= ~LAUNCHER_FIRED;
    if (OnEdit(task)) {
        return;
    }
    /* @hack spelling: rocket set in the test, which tests R0 and copies it in
     * the branch's delay slot (TST R0,R0 at 0x8c066df6); set apart, SHC
     * tests the copy and 3 of 123 words differ */
    if ((rocket = CreateElementalTask(TASK_MOTION | TASK_WORK | TASK_FORCE |
                                          TASK_EXTRA,
                                      3, rocket_step)) == NULL) {
        return;
    }
    rocket_work = (struct rocket_work *)rocket->work;
    motion = (struct rocket_motion *)rocket->motion;
    /* @hack redundant: mode stored again, as the image stores it twice
     * (MOV.B at 0x8c066dd8 and 0x8c066e06); stored once, 93 of 123 words
     * differ */
    work->mode = LAUNCHER_OPEN;
    rocket->parent = task;
    rocket_work->action = &rocket_h_action;
    rocket_work->pos.x = work->pos.x;
    rocket_work->pos.y = work->pos.y;
    rocket_work->pos.z = work->pos.z;
    rocket_work->target.x = work->target.x;
    rocket_work->target.y = work->target.y;
    rocket_work->target.z = work->target.z;
    rocket_work->ang.y = work->ang.y;
    rocket_work->ang.z = extra->climb;
    motion->launcher = work;
    motion->count = (Float)work->action->motion->nbFrame * RISE_STEPS;
    motion->reach = extra->reach;
    rocket_get_grip(rocket_work, rocket_work->action, rocket_work->frame,
                    &VecTemp0);
    /* @hack spelling: the rise through a local, which works it out in FR4
     * and loads the count into FR3 (FDIV FR3,FR4 at 0x8c066e7c); as one
     * expression, 36 of 123 words differ */
    rise = GRIP_HEIGHT - VecTemp0.y;
    motion->speed.y = rise / motion->count;
    rocket_enter(rocket_work);
    dsPlay_oneshot_v(SE_LAUNCHER_OPEN, 0, 0, 0, work->pos.x, work->pos.y,
                     work->pos.z);
}

/* as rocket_launcher_open_h, for a rocket that flies up. it starts
 * UP_OFFSET along the launcher's x, faces back along the launcher, stands
 * on its tail, and takes no slot in rockets */
static void rocket_launcher_open_v(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;
    struct task *rocket;
    struct rocket_work *rocket_work;
    struct rocket_motion *motion;
    Float rise;

    work->mode = LAUNCHER_OPEN;
    work->frame = 0.0F;
    work->state &= ~LAUNCHER_FIRED;
    if (OnEdit(task)) {
        return;
    }
    /* @hack spelling: rocket set in the test, as in rocket_launcher_open_h
     * (TST R0,R0 at 0x8c066f3a); set apart, 3 of 167 words differ */
    if ((rocket = CreateElementalTask(TASK_MOTION | TASK_WORK | TASK_FORCE |
                                          TASK_EXTRA,
                                      3, rocket_step)) == NULL) {
        return;
    }
    rocket_work = (struct rocket_work *)rocket->work;
    motion = (struct rocket_motion *)rocket->motion;
    /* @hack redundant: mode stored again, as in rocket_launcher_open_h
     * (MOV.B at 0x8c066f18 and 0x8c066f4a); stored once, 123 of 167 words
     * differ */
    work->mode = LAUNCHER_OPEN;
    rocket->parent = task;
    rocket_work->state |= ROCKET_UP;
    rocket_work->action = &rocket_v_action;
    rocket_work->frame = 2.0F;
    VecTemp0.x = UP_OFFSET;
    VecTemp0.y = 0.0F;
    VecTemp0.z = 0.0F;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateY, work->ang.y);
    njCalcVector(NULL, &VecTemp0, &scratch_vector2);
    late_DrawObjectClipEx(1);
    rocket_work->pos.x = work->pos.x + scratch_vector2.x;
    rocket_work->pos.y = work->pos.y;
    rocket_work->pos.z = work->pos.z + scratch_vector2.z;
    rocket_work->target.x = work->target.x;
    rocket_work->target.y = work->target.y;
    rocket_work->target.z = work->target.z;
    rocket_work->ang.y = work->ang.y + NJM_DEG_ANG(180);
    rocket_work->ang.z = NJM_DEG_ANG(90);
    motion->launcher = work;
    motion->count = (Float)work->action->motion->nbFrame * RISE_STEPS;
    rocket_get_grip(rocket_work, rocket_work->action, rocket_work->frame,
                    &VecTemp0);
    /* @hack spelling: the rise through a local, as in
     * rocket_launcher_open_h (FDIV FR3,FR4 at 0x8c06701c); as one
     * expression, 23 of 167 words differ */
    rise = GRIP_HEIGHT - VecTemp0.y;
    motion->speed.y = rise / motion->count;
    dsPlay_oneshot_v(SE_LAUNCHER_OPEN, 0, 0, 0, work->pos.x, work->pos.y,
                     work->pos.z);
}

/* hold the launcher open, at its action's last frame */
static void rocket_launcher_opened(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    work->mode = LAUNCHER_WAIT;
    work->frame = (Float)work->action->motion->nbFrame - 1.0F;
}

/* close the launcher, playing its action back from the last frame, once
 * its rocket has taken off */
static void rocket_launcher_close(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    work->mode = LAUNCHER_CLOSE;
    work->frame = (Float)work->action->motion->nbFrame - 1.0F;
    work->state &= ~LAUNCHER_FIRED;
}

static void rocket_launcher_draw(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 30.0F)) {
        SetRegularTexture();
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        ds_ActionClip(work->action, work->frame);
        late_DrawObjectClipEx(1);
    }
}

static void rocket_launcher_destroy(struct task *task)
{
    struct launcher_work *work = (struct launcher_work *)task->work;

    WithdrawCollisionEntry(task, work->world);
    ReleaseMobileLandObject(work->world);
}

/* a rocket's step until a rider takes hold: it starts, rises, then waits
 * for player 0 or 1 to take hold. it ends once its launcher has left range,
 * or once its parent task's work is no longer its launcher's */
static void rocket_step(struct task *task)
{
    struct rocket_motion *motion = (struct rocket_motion *)task->motion;
    struct launcher_work *launcher = (struct launcher_work *)task->parent->work;
    struct rocket_work *work = (struct rocket_work *)task->work;

    if (launcher != motion->launcher || (launcher->state & LAUNCHER_GONE)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case ROCKET_START:
        rocket_start(task);
        break;
    case ROCKET_RISE:
        rocket_rise(work, motion);
        break;
    case ROCKET_WAIT:
        if (!ChkPlayerCanHold(task, 0)) {
            ChkPlayerCanHold(task, 1);
        }
        break;
    /* @hack redundant: the default's break, which loads collision_register's
     * address into R2 and object_step_draw's into R3 (0x8c067220 and
     * 0x8c067228); without it, the two trade and 4 of 55 words differ */
    default:
        break;
    }
    EntryColliList((struct task_work *)work);
    object_step_draw(task);
}

static void rocket_pull_step(struct task *task)
{
    rocket_pull(task);
    object_step_draw(task);
}

static void rocket_take_off_step(struct task *task)
{
    rocket_take_off(task);
    object_step_draw(task);
}

/* fly, with smoke behind, until the rider lets go, or is made to */
static void rocket_fly_step(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct task_work *rider;

    if (work->state & ROCKET_RELEASE) {
        rider = work->rider->work;
        task->step = rocket_drop_step;
        work->mode = ROCKET_DROPPED;
        SetInputP(PLAYER_VARS(rider)->player, PLAYER_MODE_RESET);
        collision_shapes_on(rider);
        return;
    }
    if (!(work->state & ROCKET_UP)) {
        rocket_fly_h(task);
    } else {
        rocket_fly_v(task);
    }
    object_step_draw(task);
    rocket_thrust_emit(task);
    rocket_move(task);
}

/* fly on once the rider of a rocket that flies along has let go. after
 * ALONG_BLINK steps the rocket blinks, and at ALONG_VANISH it ends */
static void rocket_vanish_h_step(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;

    work->timer++;
    if (work->timer == ALONG_VANISH) {
        task->step = rocket_end_step;
        work->mode = ROCKET_END;
    }
    /* @hack redundant: the else after the return, which loads
     * object_step_draw's address into R2 (MOV.L at 0x8c0672d8); without it, R3,
     * and 2 of 33 words differ */
    if (work->timer > ALONG_BLINK && !(work->timer & 3)) {
        return;
    } else {
        object_step_draw(task);
        rocket_move(task);
    }
}

/* fly on, blinking, once the rider of a rocket that flies up has let go.
 * after UP_VANISH steps, wait for the rider to land */
static void rocket_vanish_v_step(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;

    work->timer++;
    if (work->timer == UP_VANISH) {
        task->step = rocket_land_step;
        work->mode = ROCKET_END;
    }
    /* @hack redundant: the else after the return, which loads
     * object_step_draw's address into R3 (MOV.L at 0x8c06734c); without it, R2,
     * and 2 of 29 words differ */
    if (!(work->timer & 3)) {
        return;
    } else {
        object_step_draw(task);
        rocket_move(task);
    }
}

static void rocket_end_step(struct task *task)
{
    FreeTask(task);
}

/* the step of a rocket that flew up, once it has vanished. when the rider
 * lands, or falls below the target, the rocket ends, and gives the camera
 * back if the rider is player 0 */
static void rocket_land_step(struct task *task)
{
    /* @hack redundant: register on work, which puts work in R4, task's
     * register, and rider in R5 (MOV.L @(32,R4),R4 at 0x8c06736c); without
     * it, SHC copies task to R5 for work, the function runs 2 bytes long
     * and 32 of 34 words differ */
    register struct rocket_work *work = (struct rocket_work *)task->work;
    struct task_work *rider = work->rider->work;

    if (work->state & ROCKET_UP) {
        if ((rider->flags & PLAYER_ON_GROUND) ||
            rider->pos.y < work->target.y) {
            if (PLAYER_VARS(rider)->player == 0) {
                CameraReleaseEventCamera();
            }
            FreeTask(task);
        }
    }
}

static void rocket_drop_step(struct task *task)
{
    FreeTask(task);
}

/* note where the rocket starts, give it its shape, and rise */
static void rocket_start(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct rocket_origin *origin = (struct rocket_origin *)task->force;

    work->mode = ROCKET_RISE;
    task->draw = rocket_draw;
    task->destructor = rocket_destroy;
    origin->pos.x = work->pos.x;
    origin->pos.y = work->pos.y;
    origin->pos.z = work->pos.z;
    CCL_Init(task, &rocket_shape, COLLISION_OBJECT, 1, 1);
}

/* rise until the count runs out, then note where the grip is, and wait
 * for a rider */
static void rocket_rise(struct rocket_work *work, struct rocket_motion *motion)
{
    motion->count -= 1.0F;
    if (motion->count > 0.0F) {
        work->pos.y += motion->speed.y;
    } else {
        work->mode = ROCKET_WAIT;
        rocket_get_grip(work, work->action, work->frame, &VecTemp0);
        motion->grip.x = work->pos.x + VecTemp0.x;
        motion->grip.y = work->pos.y + VecTemp0.y;
        motion->grip.z = work->pos.z + VecTemp0.z;
    }
}

/* from the flight's ALONG_LET_GO step, jump or action on pad 0 makes the
 * rider let go. once the rocket is farther across from its start than its
 * reach, the rider lets go anyway */
static void rocket_fly_h(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct rocket_motion *motion = (struct rocket_motion *)task->motion;
    struct rocket_origin *origin = (struct rocket_origin *)task->force;
    struct task_work *rider = work->rider->work;
    Float dx;
    Float dz;

    work->timer++;
    if (work->timer == ALONG_LET_GO) {
        work->state |= ROCKET_LET_GO;
    }
    dx = work->pos.x - origin->pos.x;
    dz = work->pos.z - origin->pos.z;
    if (((per[0]->press & (pad_jump_buttons | pad_action_buttons)) &&
         (work->state & ROCKET_LET_GO)) ||
        (dx * dx) + (dz * dz) > motion->reach) {
        task->step = rocket_vanish_h_step;
        work->mode = ROCKET_VANISH;
        work->timer = 0;
        SetInputP(PLAYER_VARS(rider)->player, PLAYER_MODE_RESET);
        collision_shapes_on(rider);
    }
}

/* from the flight's UP_LET_GO step, jump or action on pad 0 makes the
 * rider let go. at that step, a rider that is player 0 has its camera look
 * at the target. UP_REACH above the target, the rider lets go anyway. a
 * rider that is player 0 gets its camera back as it lets go. playing Sonic,
 * a rider at or above the target gets it back from rocket_land_step
 * instead */
static void rocket_fly_v(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct task_work *rider = work->rider->work;

    work->timer++;
    if (work->timer == UP_LET_GO) {
        work->state |= ROCKET_LET_GO;
        if (PLAYER_VARS(rider)->player == 0) {
            camera_override_view.target.x = work->target.x;
            camera_override_view.target.y = work->target.y;
            camera_override_view.target.z = work->target.z;
            CameraSetEventCameraFunc(camera_step_view_target, 0,
                                     CAMERA_LOOK_AT);
        }
    }
    if (((per[0]->press & (pad_jump_buttons | pad_action_buttons)) &&
         (work->state & ROCKET_LET_GO)) ||
        work->pos.y > work->target.y + UP_REACH) {
        task->step = rocket_vanish_v_step;
        work->mode = ROCKET_VANISH;
        work->timer = 0;
        SetInputP(PLAYER_VARS(rider)->player, PLAYER_MODE_RESET);
        if ((GetPlayerNumber() || rider->pos.y < work->target.y) &&
            PLAYER_VARS(rider)->player == 0) {
            CameraReleaseEventCamera();
        }
        collision_shapes_on(rider);
    }
}

/* take player as the rider, if it stands on the ground with its hands
 * within TAKE_RANGE of the grip and within TAKE_HEIGHT of its height. the
 * rider turns to face along the rocket, and is pulled onto the grip in
 * PULL_STEPS steps. TRUE when it takes hold, else FALSE */
static Bool ChkPlayerCanHold(struct task *task, Uint8 player)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct rocket_motion *motion = (struct rocket_motion *)task->motion;
    struct task *rider_task;
    struct task_work *rider;
    const NJS_POINT3 *hands;
    NJS_VECTOR offset;
    NJS_POINT3 grip;
    Float distance;
    Float divisor;
    rider_task = GetPlayerTaskPointer(player);
    if (rider_task == ((void *)0)) {
        return (0);
    }
    if (work->state & 0x8) {
        return (0);
    }
    rider = rider_task->work;
    if (!(rider->flags & PLAYER_ON_GROUND)) {
        return FALSE;
    }
    hands = &rocket_grip_hands[PLAYER_VARS(rider)->character];
    VecTemp0.x = hands->x;
    VecTemp0.y = hands->y;
    VecTemp0.z = hands->z;
    player_turn_to_world(rider, &VecTemp0);
    grip.x = rider->pos.x + VecTemp0.x;
    grip.y = rider->pos.y + VecTemp0.y;
    grip.z = rider->pos.z + VecTemp0.z;
    offset.x = grip.x - motion->grip.x;
    offset.y = grip.y - motion->grip.y;
    offset.z = grip.z - motion->grip.z;
    if (_builtin_fabsf(offset.y) > TAKE_HEIGHT) {
        return FALSE;
    }
    distance =
        (offset.x * offset.x) + (offset.y * offset.y) + (offset.z * offset.z);
    if (distance > TAKE_RANGE * TAKE_RANGE) {
        return FALSE;
    }
    work->mode = ROCKET_PULL;
    task->step = rocket_pull_step;
    work->rider = rider_task;
    SetInputP(player, PLAYER_MODE_ROCKET);
    /* @hack spelling: z stored in each arm, which keeps scratch_vector's
     * address in R14 and motion in R13 (MOV.L @(36,R9),R13 at 0x8c067638);
     * stored once after the if, the two trade and 28 of 209 words differ */
    if (!(work->state & ROCKET_UP)) {
        VecTemp0.x = 1.0F;
        VecTemp0.y = 0.0F;
        VecTemp0.z = 0.0F;
    } else {
        VecTemp0.x = 0.0F;
        VecTemp0.y = 1.0F;
        VecTemp0.z = 0.0F;
    }
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateZ, work->ang.z);
    njCalcVector(NULL, &VecTemp0, &scratch_vector2);
    late_DrawObjectClipEx(1);
    FUN_8c07c93a(((struct player_vars *)&(rider)->vars)->player,
                 scratch_vector2.x, scratch_vector2.y, scratch_vector2.z);
    /* each step of the pull, the rider closes an eighth of the gap across,
     * and the rocket an eighth of the gap up or down */
    /* @hack spelling: 8.0F through divisor, a local, which loads it ahead of
     * PULL_STEPS (FMOV.S @R0,FR4 at 0x8c067776); written in place,
     * PULL_STEPS comes first and 5 of 209 words differ */
    divisor = 8.0F;
    motion->steps = PULL_STEPS;
    motion->speed.x = (motion->grip.x - grip.x) / divisor;
    motion->speed.y = (grip.y - motion->grip.y) / divisor;
    motion->speed.z = (motion->grip.z - grip.z) / divisor;
    return TRUE;
}

/* the pull: the rider slides toward the grip, and the rocket up or down
 * toward the rider's hands. on the last step the rider is set at the grip
 * and left out of the collision checks, and the rocket takes off. TRUE on
 * that step, else FALSE */
static Bool rocket_pull(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct rocket_motion *motion = (struct rocket_motion *)task->motion;
    struct task_work *rider = work->rider->work;
    const NJS_POINT3 *hands;
    Float y;

    motion->steps -= 1.0F;
    if (motion->steps > 0.0F) {
        rider->pos.x += motion->speed.x;
        work->pos.y += motion->speed.y;
        rider->pos.z += motion->speed.z;
    } else {
        task->step = rocket_take_off_step;
        work->mode = ROCKET_TAKE_OFF;
        motion->count = (Float)work->action->motion->nbFrame - 1.0F;
        hands = &rocket_grip_hands[PLAYER_VARS(rider)->character];
        VecTemp0.x = hands->x;
        VecTemp0.y = hands->y;
        VecTemp0.z = hands->z;
        player_turn_to_world(rider, &VecTemp0);
        y = rider->pos.y + VecTemp0.y;
        work->pos.y += y - motion->grip.y;
        motion->grip.y = y;
        SetPositionP(PLAYER_VARS(rider)->player, motion->grip.x - VecTemp0.x,
                     motion->grip.y - VecTemp0.y, motion->grip.z - VecTemp0.z);
        collision_shapes_off(rider);
        return TRUE;
    }
    return FALSE;
}

/* play the rocket's action as it takes off, the grip held where the
 * rider's hands are. at the action's last frame the rocket flies, its
 * launcher closes and its jet lights. TRUE then, else FALSE */
static Bool rocket_take_off(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct rocket_motion *motion = (struct rocket_motion *)task->motion;
    struct rocket_jet *jet = (struct rocket_jet *)task->extra;
    struct task *rider_task;
    struct task_work *rider;
    struct launcher_work *launcher;
    struct task *parent;

    /* @hack spelling: the rider's task through rider_task, which loads it
     * into R5 before its work into R11 (MOV.L @(16,R14),R5 at 0x8c067948);
     * read in one expression, R11 takes both and 2 of 106 words differ */
    rider_task = work->rider;
    rider = rider_task->work;
    work->frame += 0.2F;
    if (work->frame < motion->count) {
        rocket_get_grip(work, work->action, work->frame, &VecTemp0);
        work->pos.x = motion->grip.x - VecTemp0.x;
        work->pos.y = motion->grip.y - VecTemp0.y;
        work->pos.z = motion->grip.z - VecTemp0.z;
    } else {
        /* @hack spelling: the launcher's task through parent, which loads
         * it into R5 ahead of the mode's store (MOV.L @(8,R4),R5 at
         * 0x8c067992); read in one expression, it goes to R12 and 6 of 106
         * words differ */
        parent = task->parent;
        launcher = (struct launcher_work *)parent->work;
        work->mode = ROCKET_FLY;
        task->step = rocket_fly_step;
        if (!(work->state & ROCKET_UP)) {
            SetInputP(PLAYER_VARS(rider)->player, PLAYER_MODE_ROCKET_ALONG);
        } else {
            SetInputP(PLAYER_VARS(rider)->player, PLAYER_MODE_ROCKET_UP);
        }
        if (launcher == motion->launcher) {
            launcher->state |= LAUNCHER_FIRED;
        }
        work->state |= ROCKET_FLYING;
        work->frame = motion->count;
        work->timer = 0;
        motion->grip.x = 0.0F;
        jet->lit = 1;
        dsPlay_oneshot(SE_ROCKET_FIRE, 0, 0, 0);
        return TRUE;
    }
    return FALSE;
}

/* move along the rocket's heading, with the speed growing by FLY_ACCEL
 * each step until it passes FLY_SPEED. while the rocket flies, bring the
 * rider along by its hands */
static void rocket_move(struct task *task)
{
    struct rocket_motion *motion = (struct rocket_motion *)task->motion;
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct task *rider_task;
    struct task_work *rider;
    const NJS_POINT3 *hands;

    if (motion->grip.x < FLY_SPEED) {
        motion->grip.x += FLY_ACCEL;
    }
    njPushMatrix(&nj_unit_matrix_);
    VecTemp0.x = motion->grip.x;
    VecTemp0.y = 0.0F;
    VecTemp0.z = 0.0F;
    TURN(njRotateY, work->ang.y);
    TURN(njRotateZ, work->ang.z);
    njCalcVector(NULL, &VecTemp0, &scratch_vector2);
    work->pos.x += scratch_vector2.x;
    work->pos.y += scratch_vector2.y;
    work->pos.z += scratch_vector2.z;
    if (work->mode == ROCKET_FLY) {
        /* @hack spelling: the rider's task through rider_task, which keeps
         * motion in R13 (MOV.L @(36,R4),R13 at 0x8c067a8e); read in one
         * expression, motion takes R12 and 30 of 165 words differ */
        rider_task = work->rider;
        rider = rider_task->work;
        if (rider->submode != PLAYER_MODE_RESET) {
            rocket_get_grip(work, work->action, work->frame, &VecTemp0);
            VecTemp0.x += work->pos.x;
            VecTemp0.y += work->pos.y;
            VecTemp0.z += work->pos.z;
            /* @hack spelling: the hands copied in each arm, which keeps
             * motion in R13 as well; copied once after the if, motion takes
             * R12 and 28 of 165 words differ */
            if (!(work->state & ROCKET_UP)) {
                hands = &rocket_along_hands[PLAYER_VARS(rider)->character];
                scratch_vector2.x = hands->x;
                scratch_vector2.y = hands->y;
                scratch_vector2.z = hands->z;
            } else {
                hands = &rocket_up_hands[PLAYER_VARS(rider)->character];
                scratch_vector2.x = hands->x;
                scratch_vector2.y = hands->y;
                scratch_vector2.z = hands->z;
            }
            player_turn_to_world(rider, &scratch_vector2);
            rider->pos.x = VecTemp0.x - scratch_vector2.x;
            rider->pos.y = VecTemp0.y - scratch_vector2.y;
            rider->pos.z = VecTemp0.z - scratch_vector2.z;
        }
    }
    late_DrawObjectClipEx(1);
}

/* set out to the grip's offset from the rocket, turned with the rocket, as
 * its action stands at frame */
static void rocket_get_grip(struct rocket_work *work, NJS_ACTION *action,
                            Float frame, NJS_POINT3 *out)
{
    /* @hack spelling: scratch_matrix through matrix, a local, which keeps
     * its address in R14 across the calls (MOV.L at 0x8c067bd8); named at
     * each use, 55 of 57 words differ */
    NJS_MATRIX *matrix = &scratch_matrix;

    VecTemp0.x = 0.0F;
    VecTemp0.y = 0.0F;
    VecTemp0.z = 0.0F;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateZ, work->ang.z);
    CalcMMMatrix(NULL, action, frame, GRIP_NODE, matrix);
    njCalcPoint(matrix, &VecTemp0, out);
    late_DrawObjectClipEx(1);
}

static void rocket_draw(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 30.0F)) {
        SetRegularTexture();
        njPushMatrix(((void *)0));
        njTranslate(((void *)0), work->pos.x, work->pos.y, work->pos.z);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
        ds_ActionClip(work->action, work->frame);
        late_DrawObjectClipEx(1);
        rocket_jet_draw(task);
    }
}

static void rocket_destroy(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;

    task->parent = NULL;
    /* @bug logic: a rocket that flies up, or found rockets full, has
     * slot 0, and clears rockets[0] though another rocket may hold it
     * (MOV.L R6,@R3 at 0x8c067d14) */
    rockets[work->slot] = NULL;
}

/* make a puff of smoke from rocket_thrust_pool at pos, moving at speed,
 * its size scale times DUST_SIZE */
static void rocket_thrust_create(NJS_POINT3 *pos, NJS_VECTOR *speed,
                                 Float scale)
{
    struct particle_pool *pool = rocket_thrust_pool.pool;
    struct particle *particle = SpCreateTask(pool, dust_step);

    if (particle != NULL) {
        particle->pos = *pos;
        particle->speed = *speed;
        particle->scale = scale * DUST_SIZE;
        particle->time = rand() * RAND_SCALE * 6.0F;
        particle->ang = rand() * RAND_SCALE * 360.0F * ANGLE_PER_DEGREE;
        particle->color.a = 1.0F;
        particle->color.r = 1.0F;
        particle->color.g = 1.0F;
        particle->color.b = 1.0F;
        DUST(particle)->params = &rocket_thrust_params;
    }
}

/* draw the lit jet as four sprites at the rocket's tail, on a frame's
 * first step only. each call steps the jet's frame through 0, 1 and 2 */
static void rocket_jet_draw(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct rocket_jet *jet = (struct rocket_jet *)task->extra;
    Float frame;

    if (!ChkPause()) {
        frame = jet->frame + 1.0F;
        if (frame >= 3.0F) {
            frame = 0.0F;
        }
        jet->frame = frame;
    } else {
        frame = jet->frame;
    }
    if (jet->lit && !loop_count) {
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN(njRotateY, work->ang.y);
        TURN(njRotateZ, work->ang.z);
        njTranslate(NULL, -8.0F, 2.4F, -2.4F);
        njDrawSprite3D(&rocket_jet_sprite, (Int)frame,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE);
        njTranslate(NULL, 0.0F, 0.0F, 4.8F);
        njDrawSprite3D(&rocket_jet_sprite, (Int)frame,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE);
        njTranslate(NULL, 0.0F, -4.8F, 0.0F);
        njDrawSprite3D(&rocket_jet_sprite, (Int)frame,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE);
        njTranslate(NULL, 0.0F, 0.0F, -4.8F);
        njDrawSprite3D(&rocket_jet_sprite, (Int)frame,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE);
        late_DrawObjectClipEx(1);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_INVSRCALPHA);
    }
}

/* while the jet is lit, on a frame's first step, make a puff of smoke
 * behind the rocket's tail, moving with the rocket */
static void rocket_thrust_emit(struct task *task)
{
    struct rocket_work *work = (struct rocket_work *)task->work;
    struct rocket_motion *motion = (struct rocket_motion *)task->motion;
    struct rocket_jet *jet = (struct rocket_jet *)task->extra;

    if (jet->lit && !loop_count) {
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateY, work->ang.y);
        TURN(njRotateZ, work->ang.z);
        scratch_point.x = -motion->grip.x - 3.0F;
        scratch_point.y = 0.0F;
        scratch_point.z = 0.0F;
        njCalcPoint(NULL, &scratch_point, &scratch_point2);
        vector_add(&work->pos, &scratch_point2, &scratch_point);
        VecTemp0.x = motion->grip.x;
        VecTemp0.y = 0.0F;
        VecTemp0.z = 0.0F;
        njCalcVector(NULL, &VecTemp0, &scratch_vector2);
        late_DrawObjectClipEx(1);
        rocket_thrust_create(&scratch_point, &scratch_vector2, 0.8F);
    }
}
