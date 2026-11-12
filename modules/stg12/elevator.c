/* @unit 0C901EE0-0C902400 +r04 +egflags +pool32 +poolafter=shelter_elevator_update,FUN_0c902288 +asmfunc=FUN_0c901ee0:0c9020f8 */
/* O ELEVATOR: a car that carries the players down its shaft, then opens its
 * doors */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "debug/print.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "stg12/elevator.h"
#include "system/frame.h"
#include "system/pad.h"
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
Bool OnEdit(struct task *task);
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
Bool ChkPause(void);
void pdExecPeripheralServerUser(void);
extern PDS_PERIPHERAL perG[8];
extern struct pad_stick input_dataG[8];
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
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

#define RANGE (500.0F * 500.0F)
#define DOWN_SPEED 0.6F
#define OPEN_SPEED 0.02F
#define CAR_FLAGS (WORLD_LARGE | WORLD_MOVES)
#define SE_ELEVATOR_RIDE 306
#define SE_CLANK 307
#define ACT_STILL 1
#define ACT_PADS_OFF 2
#define SHUT_SHARE(work) ((work)->scl.z)
#define DOOR_A_X(work) ((work)->scl.y)
#define DOOR_B_X(work) ((work)->scl.x)
#define VARS(work) ((struct shelter_elevator_vars *)&(work)->vars)
#define FORCE(task) ((struct task_force *)(task)->force)
extern NJS_OBJECT shelter_elevator_object;
extern NJS_OBJECT shelter_elevator_door_a_object;
extern NJS_OBJECT shelter_elevator_door_b_object;
extern NJS_OBJECT shelter_elevator_world_object;

/* destroyed beyond 500 units of the camera and player 0 */

/* each step, the car sinks DOWN_SPEED and the doors open OPEN_SPEED of the
 * way */

/* in act ACT_STILL the car stands still, its doors shut. in act ACT_PADS_OFF
 * the pads are off until the doors open */

enum shelter_elevator_mode {
    ELEVATOR_INIT,
    ELEVATOR_OPEN,
    ELEVATOR_WAIT,
    ELEVATOR_DOWN,
    ELEVATOR_OPENING,
    ELEVATOR_STILL
};

struct shelter_elevator_vars {
    Uint8 act;
    Uint8 unk_01[7];
    NJS_OBJECT *car; /* the car's object in the collision world */
};

/* the doors' state, in work->scl. SHUT_SHARE is the share of the way the
 * doors are from open: 1 shut, 0 open. DOOR_A_X and DOOR_B_X are their
 * offsets along x */

/* each act's shaft: where the car starts and where it stops */
struct shelter_elevator_shaft {
    NJS_POINT3 top;
    NJS_POINT3 bottom;
};

void shelter_elevator_init(struct task *task);
void shelter_elevator_update(struct task *task);
void shelter_elevator_draw(struct task *task);
void shelter_elevator_destroy(struct task *task);
void shelter_elevator_wait(struct task *task);
void shelter_elevator_down(struct task *task);
void shelter_elevator_open(struct task *task);
void OpenDoor(struct task_work *work);
extern struct collision_shape shelter_elevator_shape;
extern struct shelter_elevator_shaft shelter_elevator_shafts[3];
void shelter_elevator_step(struct task *task);

void shelter_elevator_init(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *car;

    task->draw = shelter_elevator_draw;
    task->destructor = shelter_elevator_destroy;
    VARS(work)->act = GetStageNumber();
    work->pos = shelter_elevator_shafts[VARS(work)->act].top;
    if (VARS(work)->act == ACT_PADS_OFF) {
        PadReadOff();
    }
    VARS(work)->car = car = GetMobileLandObject();
    car->evalflags = shelter_elevator_world_object.evalflags;
    car->scl[0] = 1.0F;
    car->scl[1] = 1.0F;
    car->scl[2] = 1.0F;
    car->ang[0] = 0;
    car->ang[1] = 0;
    car->ang[2] = 0;
    car->pos[0] = work->pos.x + shelter_elevator_world_object.pos[0];
    car->pos[1] = work->pos.y + shelter_elevator_world_object.pos[1];
    car->pos[2] = work->pos.z + shelter_elevator_world_object.pos[2];
    car->model = shelter_elevator_world_object.model;
    car->child = NULL;
    car->sibling = NULL;
    RegisterCollisionEntry(CAR_FLAGS, task, car);
    FORCE(task)->speed.x = 0.0F;
    FORCE(task)->speed.y = 0.0F;
    FORCE(task)->speed.z = 0.0F;
    FORCE(task)->turn.x = 0;
    FORCE(task)->turn.y = 0;
    FORCE(task)->turn.z = 0;
    CCL_Init(task, &shelter_elevator_shape, COLLISION_OBJECT, 1, 1);
    work->ang.x = 0;
    work->ang.y = 0;
    work->ang.z = 0;
    SHUT_SHARE(work) = 1.0F;
    OpenDoor(work);
    if (VARS(work)->act == ACT_STILL) {
        work->mode = ELEVATOR_STILL;
    } else {
        work->mode = ELEVATOR_WAIT;
    }
}

void shelter_elevator_update(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *car = VARS(work)->car;
    NJS_OBJECT *from = &shelter_elevator_world_object;
    /* @hack redundant: 24 bytes of frame that no code reads, of a type unknown,
     * declared as two points. the image's ADD #-24,R15 reserves them
     * (0x0c902158); without them, 32 of 33 words differ */
    NJS_POINT3 unused[2];

    car->ang[0] = 0;
    car->ang[1] = work->ang.y;
    car->ang[2] = 0;
    car->pos[0] = work->pos.x + from->pos[0];
    car->pos[1] = work->pos.y + from->pos[1];
    car->pos[2] = work->pos.z + from->pos[2];
    EntryColliList(work);
}

void shelter_elevator_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count == 0) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        late_DrawObject(&shelter_elevator_object);
        njPushMatrix(NULL);
        njTranslate(NULL, DOOR_A_X(work), 15.0F, -45.0F);
        late_DrawObject(&shelter_elevator_door_a_object);
        late_DrawObjectClipEx(1);
        njPushMatrix(NULL);
        njTranslate(NULL, DOOR_B_X(work), 15.0F, -45.0F);
        late_DrawObject(&shelter_elevator_door_b_object);
        late_DrawObjectClipEx(1);
        late_DrawObjectClipEx(1);
    }
}

void shelter_elevator_destroy(struct task *task)
{
    struct task_work *work = task->work;

    WithdrawCollisionEntry(task, VARS(work)->car);
    ReleaseMobileLandObject(VARS(work)->car);
}

void shelter_elevator_wait(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckPlayerRideOnMobileLandObjectP(0, task) ||
        CheckPlayerRideOnMobileLandObjectP(1, task)) {
        work->mode = ELEVATOR_DOWN;
    }
}

/* the car's force carries player 0 down with it */
void shelter_elevator_down(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 bottom;

    bottom = shelter_elevator_shafts[VARS(work)->act].bottom;
    if (work->pos.y <= bottom.y) {
        FORCE(task)->speed.y = 0.0F;
        work->mode = ELEVATOR_OPENING;
        dsPlay_oneshot(SE_CLANK, 0, 0, 0);
    } else {
        work->pos.y -= DOWN_SPEED;
        FORCE(task)->speed.y = -DOWN_SPEED;
        dsPlay_timer(SE_ELEVATOR_RIDE, (int)task, 1, 0, 2);
    }
}

void shelter_elevator_open(struct task *task)
{
    struct task_work *work = task->work;

    SHUT_SHARE(work) -= OPEN_SPEED;
    if (SHUT_SHARE(work) <= 0.0F) {
        SHUT_SHARE(work) = 0.0F;
        work->mode = ELEVATOR_OPEN;
        ufExitSystem();
    }
    OpenDoor(work);
}

void OpenDoor(struct task_work *work)
{
    DOOR_B_X(work) = (SHUT_SHARE(work) * 12.0F) - 25.0F;
    DOOR_A_X(work) = (SHUT_SHARE(work) * 24.0F) - 24.0F;
}
