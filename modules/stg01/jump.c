/* @unit 0C9012E0-0C901800 @data 0C910A38-0C910A70 +r04 +egflags +pool32 */
/* O JUMP: a solid ramp with a turning wheel, which launches a player who
 * touches it */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/common.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stg01/jump.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
#include "vmu/vibration.h"
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
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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
void SetMleriRangeRad(Float radius);
void ds_DrawModelClip(NJS_MODEL *model);
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
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

#define WAIT_STEPS 10
#define LAUNCH_RISE 4.0F
#define TEST_MARGIN 16.0F
#define WHEEL_TURN 5
#define VARS(work) ((struct jump_vars *)&(work)->vars)
extern NJS_OBJECT beach_jump_object;
extern NJS_OBJECT beach_jump_wheel_object;
extern NJS_OBJECT beach_jump_top_object;

/* after a launch, the ramp waits WAIT_STEPS + 1 steps before it can launch
 * again. the world doesn't test the ramp's copy while it waits */

/* a launch sends the player off LAUNCH_RISE a step up */

/* the world tests the ramp's copy only while a player is within its radius
 * plus TEST_MARGIN */

/* the wheel's turn each draw, in degrees */

/* the ramp's vars. work->submode holds the number of the player to launch.
 * work->tick counts the wait down from WAIT_STEPS to 0, a step at each.
 * TASK_TIMER(work) holds the wheel's turn in degrees */
struct jump_vars {
    NJS_OBJECT *world; /* the ramp's copy in the collision world */
    Uint8 unk_04[4];
    NJS_OBJECT *object; /* the ramp model drawn */
};

/* in JUMP_IDLE, the step only checks its range. no code sets it */
enum jump_mode { JUMP_INIT, JUMP_RUN, JUMP_LAUNCH, JUMP_WAITING, JUMP_IDLE };
extern struct collision_shape beach_jump_shape;

void GetColli(struct task *task, NJS_OBJECT *object);
void o_beach_jumpraft_Norm(struct task *task);
void beach_jump_draw(struct task *task);
void beach_jump_destroy(struct task *task);

/* launch a player who touches the ramp, then wait. the launch sends the
 * player off at scale x a step forward and LAUNCH_RISE up. the speed is in
 * the frame of the ramp's angles, turned a half turn about y. the player's
 * stick is ignored for scale y steps, rounded up */
void ObjectBeachJump(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case JUMP_INIT:
        task->destructor = beach_jump_destroy;
        task->draw = beach_jump_draw;
        GetColli(task, &beach_jump_object);
        CCL_Init(task, &beach_jump_shape, COLLISION_OBJECT, 1, 1);
        VARS(work)->object = &beach_jump_object;
        work->mode = JUMP_RUN;
        break;
    case JUMP_RUN:
        if (!OnEdit(task)) {
            o_beach_jumpraft_Norm(task);
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
        }
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Z), "<- -EXPRESS");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<-V SPEED");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "<-NO_CONTROL TIME");
        }
        beach_jump_draw(task);
        break;
    case JUMP_LAUNCH: {
        Angle ang[3];
        NJS_VECTOR speed = {0.0F, LAUNCH_RISE, 0.0F};
        int steps;

        dsPlay_oneshot(SE_DASH, 0, 0, 0);
        speed.x = work->scl.x;
        ang[0] = work->ang.x;
        ang[1] = work->ang.y + NJM_DEG_ANG(180);
        ang[2] = work->ang.z;
        steps = ceilf(work->scl.y);
        player_send_flying(work->submode, &speed, ang, steps);
        VibShot(work->submode, 4, 15, 0);
        work->flags &= ~WORLD_TESTED;
        work->mode = JUMP_WAITING;
        work->tick = WAIT_STEPS;
        beach_jump_draw(task);
        break;
    }
    case JUMP_WAITING:
        /* @hack spelling: the test and the store as one conditional expression,
         * as at 0x0c901518. as an if statement, SHC holds 1 in R12 through
         * the step, its code runs 32 bytes short, and 97 of its 170 words
         * differ */
        (work->tick-- <= 0) ? (void)(work->mode = JUMP_RUN) : (void)0;
        work->flags &= ~WORLD_TESTED;
        beach_jump_draw(task);
        break;
    case JUMP_IDLE:
    default:
        break;
    }
}

/* put a copy of object in the world, posed as the task. the copy is
 * WORLD_SOLID, with the WORLD_SIZE its model's radius picks */
void GetColli(struct task *task, NJS_OBJECT *object)
{
    struct task_work *work = task->work;
    NJS_OBJECT *copy;
    Uint32 flags;

    VARS(work)->world = copy = GetMobileLandObject();
    copy->scl[0] = 1.0F;
    copy->scl[1] = 1.0F;
    copy->scl[2] = 1.0F;
    copy->ang[0] = work->ang.x;
    copy->ang[1] = work->ang.y;
    copy->ang[2] = work->ang.z;
    copy->pos[0] = work->pos.x;
    copy->pos[1] = work->pos.y;
    copy->pos[2] = work->pos.z;
    copy->model = object->model;
    copy->child = object->child;
    copy->sibling = object->sibling;
    flags = WORLD_HUGE | WORLD_SOLID;
    /* @hack spelling: the empty branch for a radius over 20, which keeps flags
     * as set, by the BT/S at 0x0c9015e2. as if (r <= 20.0F) around the other
     * sizes, 2 of 80 words differ */
    if (copy->model->r > 20.0F) {
    } else if (copy->model->r > 10.0F) {
        flags = WORLD_LARGE | WORLD_SOLID;
    } else if (copy->model->r > 3.0F) {
        flags = WORLD_MEDIUM | WORLD_SOLID;
    } else {
        flags = WORLD_SMALL | WORLD_SOLID;
    }
    RegisterCollisionEntry(flags, task, copy);
    /* @hack redundant: a return where the function ends, which has SHC keep
     * task in a stack slot: ADD #-4,R15 at 0x0c901586 makes it, and MOV.L
     * R4,@R15 at 0x0c90158c fills it. without it, SHC pushes task, and 79 of 80
     * words differ */
    /* NOLINTNEXTLINE(readability-redundant-control-flow) */
    return;
}

/* keep the ramp's copy in the world posed as the task, and tested while a
 * player is near. a player whose task hit the box is launched on the next
 * step */
void o_beach_jumpraft_Norm(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *copy = VARS(work)->world;
    struct task *player;
    int i;

    copy->pos[0] = work->pos.x;
    copy->pos[1] = work->pos.y;
    copy->pos[2] = work->pos.z;
    copy->ang[0] = work->ang.x;
    copy->ang[1] = work->ang.y;
    copy->ang[2] = work->ang.z;
    if (player_in_range(&work->pos, copy->model->r + TEST_MARGIN)) {
        work->flags |= WORLD_TESTED;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
    if (work->collision->flags & COLLISION_HIT) {
        work->collision->flags &= ~COLLISION_HIT;
        for (i = 0; i < 2; ++i) {
            player = GetPlayerTaskPointer(i);
            if (work->collision->hit->owner == player) {
                work->submode = i;
                work->mode = JUMP_LAUNCH;
            }
        }
    }
}

/* draw the ramp, its top and its wheel. the wheel turns backward about x by
 * WHEEL_TURN degrees each draw */
void beach_jump_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = VARS(work)->object;
    NJS_OBJECT *top = &beach_jump_top_object;
    NJS_OBJECT *wheel = &beach_jump_wheel_object;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    ds_DrawModelClip(object->model);
    njPushMatrix(NULL);
    njTranslate(NULL, top->pos[0], top->pos[1], top->pos[2]);
    TURN_VIA(njRotateZ, top->ang[2], ang);
    TURN_VIA(njRotateY, top->ang[1], ang);
    TURN_VIA(njRotateX, top->ang[0], ang);
    ds_DrawModelClip(top->model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, wheel->pos[0], wheel->pos[1], wheel->pos[2]);
    TURN_VIA(njRotateZ, wheel->ang[2], ang);
    TURN_VIA(njRotateY, wheel->ang[1], ang);
    TURN_VIA(njRotateX, wheel->ang[0], ang);
    TURN_VIA(njRotateX, -(Angle)(TASK_TIMER(work) * ANGLE_PER_DEGREE), ang);
    ds_DrawModelClip(wheel->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
    if (!ChkPause()) {
        (*(Uint16 *)&(work)->timer) += 5;
    }
}

void beach_jump_destroy(struct task *task)
{
    struct task_work *work = task->work;

    WithdrawCollisionEntry(task, VARS(work)->world);
    ReleaseMobileLandObject(VARS(work)->world);
}
