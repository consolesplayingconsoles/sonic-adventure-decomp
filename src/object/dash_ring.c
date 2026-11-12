/* @unit 8C05A2A0-8C05A880 @data 8C154A1C-8C154A2C +egflags +pool32 */
/* the dash ring, CMN_DRING or O DUSH RING in the object lists. a player
 * who passes through it is carried on toward its target */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/dash_ring.h"
#include "object/helpers.h"
#include "object/models.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stage/stage.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ds_DrawModelClip(NJS_MODEL *model);
Float vector_reflect(NJS_VECTOR *vector, NJS_VECTOR *normal_jp,
                     NJS_VECTOR *out);
Bool polygon_contains(NJS_POINT3 *point, NJS_POINT3 *corners,
                      NJS_VECTOR *normal_jp, int count);
int FUN_8c0670ee(NJS_POINT3 *pos, Float range);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
extern struct task_work *playertwp[];
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
void SetVelocityAndRotationAndNoconTimeWithSpinDashP(Uint8 player,
                                                     NJS_VECTOR *speed,
                                                     const Angle *ang,
                                                     Sint16 steps);
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
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
Uint16 GetStageNumber(void);
Bool ChkPause(void);
void ReleasePlayersTexture(int character);
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

/* squared ranges: the ring's, for placement_try_leave_by, and the one
 * within which a carrier takes its player */
#define RING_RANGE (1500.0F * 1500.0F)
#define TAKE_RANGE (30.0F * 30.0F)

/* how far a carrier carries its player: NO_TARGET_DISTANCE without a
 * target, else the target's distance, up to MAX_DISTANCE */
#define NO_TARGET_DISTANCE 400.0F
#define MAX_DISTANCE 1500.0F

/* a carry's phase runs to a quarter turn by PHASE_STEP a step. the
 * player's distance along the carry is its length times the phase's sine,
 * so each step moves the player less. the carry ends early once a step
 * would move it less than LEAST_MOVE */
#define PHASE_STEP 0x200
#define LEAST_MOVE 3.0F

#define SE_DASH_RING 732

/* the ring's work->scl is its target, or all zero for none */
#define VARS(work) ((struct dash_ring_vars *)&(work)->vars)
#define CARRIER(work) ((struct carrier_vars *)&(work)->vars)
struct dash_ring_vars {
    NJS_OBJECT *object;
};

/* the ring makes a carrier for each of players 0 and 1: a child task that
 * keeps the angles the ring had then. a carrier's work->scl.x is how far it
 * carries its player. scl.y is the z, in the carrier's frame, that the
 * carry last moved the player to, and 0 between carries */
struct carrier_vars {
    struct task *player_task; /* the player's task, set as a carry starts */
    Angle phase; /* how far along the carry, up to a quarter turn */
    Sint32 player; /* the player it waits for and carries */
};

enum dash_ring_mode { DASH_RING_INIT, DASH_RING_RUN };
enum carrier_mode { CARRIER_WAIT, CARRIER_CARRY };

static Bool InitCmnDushRing(struct task *task);
static Float GetTargetDist(struct task *task);
static Bool CreateChkDashPlayer(struct task *task, int player, Float distance);
static void dash_ring_carrier_step(struct task *task);
static Bool dash_ring_carry(struct task *task);
static void DrawCmnDushRing(struct task *task);
static void dash_ring_destroy(struct task *task);

void ObjectCmnDushRing(struct task *task)
{
    struct task_work *work = task->work;
    Float distance;

    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "Target Position");
    }
    if (CheckRangeOutWithR(task, RING_RANGE)) {
        return;
    }
    switch (work->mode) {
    case DASH_RING_INIT:
        if (!InitCmnDushRing(task)) {
            FreeTask(task);
            return;
        }
        break;
    case DASH_RING_RUN:
        LoopTaskC(task);
        break;
    }
    object_step_draw(task);
    if (edit_mode != 1) {
        return;
    }
    /* while the set editor is open, an arrow from the ring shows the carry */
    distance = GetTargetDist(task);
    VecTemp0.x = 0.0F;
    VecTemp0.y = 0.0F;
    VecTemp0.z = -distance;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateZ, work->ang.z);
    njCalcVector(NULL, &VecTemp0, &scratch_vector2);
    late_DrawObjectClipEx(1);
    arrow_draw(&work->pos, &scratch_vector2);
}

/* aim the ring, and make its two carriers. returns FALSE when a carrier
 * can't be made, else TRUE */
static Bool InitCmnDushRing(struct task *task)
{
    struct task_work *work = task->work;
    Float distance;

    work->mode = DASH_RING_RUN;
    VARS(work)->object = &dash_ring_object;
    task->draw = DrawCmnDushRing;
    task->destructor = dash_ring_destroy;
    distance = GetTargetDist(task);
    if (!CreateChkDashPlayer(task, 0, distance) ||
        !CreateChkDashPlayer(task, 1, distance)) {
        return FALSE;
    }
    return TRUE;
}

/* turn the ring so its -z points at its target, and return the carry's
 * length. without a target, the ring keeps its angles */
static Float GetTargetDist(struct task *task)
{
    struct task_work *work = task->work;
    Float distance;

    if (work->scl.x == 0.0F && work->scl.y == 0.0F && work->scl.z == 0.0F) {
        return NO_TARGET_DISTANCE;
    } else {
        vector_between(&work->scl, &work->pos, &VecTemp0);
        vector_aim_z(&VecTemp0, &work->ang.x, &work->ang.y);
        distance = njScalor(&VecTemp0);
        if (distance > MAX_DISTANCE) {
            distance = MAX_DISTANCE;
        }
        return distance;
    }
}

static Bool CreateChkDashPlayer(struct task *task, int player, Float distance)
{
    struct task_work *ring = task->work;
    struct task *child;
    struct task_work *work;

    child = CreateChildTask(TASK_WORK, dash_ring_carrier_step, task);
    if (child == NULL) {
        return FALSE;
    }
    work = child->work;
    work->pos = ring->pos;
    CARRIER(work)->player = player;
    work->scl.x = distance;
    return TRUE;
}

static void dash_ring_carrier_step(struct task *task)
{
    struct task_work *work = task->work;
    int player;
    struct task_motion *motion;
    struct player *record;
    int near;

    switch (work->mode) {
    case CARRIER_WAIT:
        near = FUN_8c0670ee(&work->pos, (30.0F * 30.0F));
        switch (near) {
        case 0:
            return;
        case 1:
            player = 0;
            break;
        case 2:
            player = 1;
            break;
        case 3:
            player = CARRIER(work)->player;
            break;
        }
        if (player != CARRIER(work)->player) {
            return;
        }
        motion = playermwp[player];
        record = GetPlayerWorkPointer(player);
        work->mode = CARRIER_CARRY;
        CARRIER(work)->player_task = GetPlayerTaskPointer(player);
        player_clear_speed(motion, record);
        dsPlay_oneshot(SE_DASH_RING, 0, 0, 0);
        switch (GetPlayerNumber()) {
        case CHARACTER_TAILS:
            SetInputP(player, PLAYER_MODE_HOVER);
            break;
        case CHARACTER_KNUCKLES:
            SetInputP(player, PLAYER_MODE_STILL);
            break;
        }
        break;
    case CARRIER_CARRY:
        if (!dash_ring_carry(task)) {
            return;
        }
        work->mode = CARRIER_WAIT;
        SetInputP(CARRIER(work)->player, PLAYER_MODE_RESET);
        work->scl.y = 0.0F;
        CARRIER(work)->phase = 0;
        if (GetPlayerNumber() == CHARACTER_TAILS) {
            SetInputP(0, PLAYER_MODE_FLY);
        }
        break;
    }
}

/* move the player one step along the carry, and set its speed to its move
 * from its history's previous entry. returns TRUE, with the player left
 * where it is, once the step would move it less than LEAST_MOVE or the
 * phase passes a quarter turn. else FALSE */
static Bool dash_ring_carry(struct task *task)
{
    struct task_work *work = task->work;
    struct task *player_task =
        ((struct carrier_vars *)&(work)->vars)->player_task;
    Angle phase;
    struct task_work *carried = player_task->work;
    int player = ((struct carrier_vars *)&(work)->vars)->player;
    NJS_POINT3 pos;
    Float z;
    phase = ((struct carrier_vars *)&(work)->vars)->phase;
    phase = phase + 0x200;
    z = -(work->scl.x * njSin(phase));
    CARRIER(work)->phase = phase;
    VecTemp0.x = 0.0F;
    VecTemp0.y = 0.0F;
    VecTemp0.z = z;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njCalcVector(NULL, &VecTemp0, &scratch_vector2);
    late_DrawObjectClipEx(1);
    if (z - work->scl.y > -LEAST_MOVE || (Uint16)phase > NJM_DEG_ANG(90)) {
        return TRUE;
    }
    work->scl.y = z;
    SetPositionP(player, work->pos.x + scratch_vector2.x,
                 work->pos.y + scratch_vector2.y,
                 work->pos.z + scratch_vector2.z);
    GetPlayerPosition(player, 1, &pos, NULL);
    playermwp[player]->speed.x = carried->pos.x - pos.x;
    playermwp[player]->speed.y = carried->pos.y - pos.y;
    playermwp[player]->speed.z = carried->pos.z - pos.z;
    return FALSE;
}

static void DrawCmnDushRing(struct task *task)
{
    struct task_work *work = task->work;

    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 100.0F)) {
        return;
    }
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateZ, work->ang.z);
    late_DrawObject(&dash_ring_object);
    late_DrawObjectClipEx(1);
}

static void dash_ring_destroy(struct task *task)
{
}
