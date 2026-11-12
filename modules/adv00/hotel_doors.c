/* @unit 0C90BC00-0C90C340 +r04 +egflags +pool32 +poolafter=FUN_0c90bd30,FUN_0c90bf0e,FUN_0c90c074,ObjectSSHotelfront +asmfunc=station_door_unlocked:0c90bcf4 */
/* O HOTEL FRONT, O HOTEL BACK and O HOTEL POOL folding doors, locked until the
 * story of player 0's character opens them */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "adv00/hotel_doors.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "object/placement.h"
#include "player/player.h"
#include "progress/progress.h"
#include "sound/sound.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
float njArcTan2(float y, float x);
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
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

/* @hack type: the folding door's action declared as an array. SHC then pools
 * its address and reads its motion through it, MOV.L @(4,R2),R1 at 0x0c90c66e.
 * declared as one NJS_ACTION, SHC pools the motion field's address, and 10 of
 * hotel_door_collide_open's 125 words, 5 of hotel_door_close's 54 and 3 of
 * hotel_door_open's 54 differ */
#define DOOR_REACH 20.0F /* within which a player opens the door */
#define DOOR_SPEED 0.2F /* motion frames a step */
#define DOOR_WAIT 90 /* steps the door stays fully open */
#define DOOR_TURN 12743.0F /* each panel's turn when fully open, 70 degrees */
#define PANEL_HALF 6.25F /* half a panel's width */
#define DOOR_HALF 25.0F
#define SE_DOOR 530
#define VARS(work) ((struct hotel_door_vars *)&(work)->vars)
extern NJS_ACTION folding_door_action[];

/* half the four panels' width, where each pair hinges */

/* sound of the door folding open or shut */

enum hotel_door_shape {
    DOOR_PANEL = 0, /* the first of four, from the left */
    DOOR_SIDE_LEFT = 4,
    DOOR_SIDE_RIGHT = 5,
    DOOR_WALL = 6, /* a wall across the shut doorway */
    DOOR_POST_LEFT = 7,
    DOOR_POST_RIGHT = 8,
    DOOR_SHAPES = 9
};

struct hotel_door_vars {
    Float frame; /* the door's frame in its motion, 0 shut */
    Bool (*open_test)(void); /* the test that unlocks it */
};

void hotel_door_wait(struct task *task);
void hotel_door_open(struct task *task);
void hotel_door_idle(struct task *task);
extern struct collision_shape ccinfo[DOOR_SHAPES];
/* clang-format on */

Bool hotel_front_open(void)
{
    switch (GetPlayerCharacterName(0)) {
    case CHARACTER_SONIC:
        return seqVars[FLAG_SONIC_SS_HOTEL_FRONT];
    case CHARACTER_TAILS:
        return seqVars[FLAG_TAILS_SS_HOTEL_FRONT];
    case CHARACTER_KNUCKLES:
        return seqVars[FLAG_KNUCKLES_SS_HOTEL_FRONT];
    case CHARACTER_AMY:
        return seqVars[FLAG_AMY_SS_HOTEL_FRONT];
    case CHARACTER_E102:
        return seqVars[FLAG_E102_SS_HOTEL_FRONT];
    case CHARACTER_BIG:
        return seqVars[FLAG_BIG_SS_HOTEL_FRONT];
    }
    return FALSE;
}

Bool station_door_unlocked(void)
{
    switch (GetPlayerCharacterName(0)) {
    case CHARACTER_SONIC:
        return seqVars[FLAG_SONIC_SS_HOTEL_BACK];
    case CHARACTER_TAILS:
        return seqVars[FLAG_TAILS_SS_HOTEL_BACK];
    case CHARACTER_KNUCKLES:
        return seqVars[FLAG_KNUCKLES_SS_HOTEL_BACK];
    case CHARACTER_AMY:
        return seqVars[FLAG_AMY_SS_HOTEL_BACK];
    case CHARACTER_E102:
        return FALSE;
    case CHARACTER_BIG:
        return seqVars[FLAG_BIG_SS_HOTEL_BACK];
    }
    return FALSE;
}

Bool hotel_pool_open(void)
{
    switch (GetPlayerCharacterName(0)) {
    case CHARACTER_SONIC:
    case CHARACTER_TAILS:
    case CHARACTER_KNUCKLES:
    case CHARACTER_AMY:
    case CHARACTER_E102:
        return TRUE;
    case CHARACTER_BIG:
        return seqVars[FLAG_BIG_SS_HOTEL_POOL];
    }
    return FALSE;
}

void hotel_door_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    SetObjectTexture();
    ds_ActionClip(folding_door_action,
                  ((struct hotel_door_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

/* the number, from 1, of a player within DOOR_REACH of the door, or 0 for
 * none */
static int hotel_door_near(struct task_work *work)
{
    return player_in_range(&work->pos, DOOR_REACH);
}

/* make the open door's panels, sides and posts solid, and register the record
 * for this step's checks. each panel's shape turns as far as frame has folded
 * the door, each pair folding toward its own side. x is a panel's half width
 * along the doorway, so an outer panel's center lies x in from its hinge, and
 * an inner one's 3x */
void ObjectColliSet_1(struct task_work *work)
{
    struct collision_shape *shapes = work->collision->shapes;
    Angle ang;
    Float x;
    Float z;

    shapes[DOOR_PANEL].flags &= ~SHAPE_OFF;
    shapes[DOOR_PANEL + 1].flags &= ~SHAPE_OFF;
    shapes[DOOR_PANEL + 2].flags &= ~SHAPE_OFF;
    shapes[DOOR_PANEL + 3].flags &= ~SHAPE_OFF;
    shapes[DOOR_SIDE_LEFT].flags &= ~SHAPE_OFF;
    shapes[DOOR_SIDE_RIGHT].flags &= ~SHAPE_OFF;
    shapes[DOOR_WALL].flags |= SHAPE_OFF;
    shapes[DOOR_POST_LEFT].flags &= ~SHAPE_OFF;
    shapes[DOOR_POST_RIGHT].flags &= ~SHAPE_OFF;
    ang = njFloor(VARS(work)->frame * DOOR_TURN /
                  (folding_door_action->motion->nbFrame - 1));
    x = njCos(ang) * PANEL_HALF;
    z = njSin(ang) * PANEL_HALF;
    shapes[3].center.x = -(shapes[0].center.x = x - DOOR_HALF);
    shapes[2].center.x = -(shapes[1].center.x = (x * 3.0F) - DOOR_HALF);
    shapes[0].center.z = shapes[1].center.z = shapes[2].center.z =
        shapes[3].center.z = z;
    shapes[2].ang.y = shapes[0].ang.y = -ang;
    shapes[3].ang.y = shapes[1].ang.y = ang;
    EntryColliList(work);
}

/* make the shut door's wall and posts solid, and register the record for this
 * step's checks */
void hotel_door_collide_shut(struct task_work *work)
{
    struct collision_shape *shapes = work->collision->shapes;

    shapes[DOOR_PANEL].flags |= SHAPE_OFF;
    shapes[DOOR_PANEL + 1].flags |= SHAPE_OFF;
    shapes[DOOR_PANEL + 2].flags |= SHAPE_OFF;
    shapes[DOOR_PANEL + 3].flags |= SHAPE_OFF;
    shapes[DOOR_SIDE_LEFT].flags |= SHAPE_OFF;
    shapes[DOOR_SIDE_RIGHT].flags |= SHAPE_OFF;
    shapes[DOOR_WALL].flags &= ~SHAPE_OFF;
    shapes[DOOR_POST_LEFT].flags &= ~SHAPE_OFF;
    shapes[DOOR_POST_RIGHT].flags &= ~SHAPE_OFF;
    EntryColliList(work);
}

/* fold the door shut, and open it again while a player is near */
void hotel_door_close(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: last set and never read, which loads the motion's frame
     * count and converts it ahead of the range check (FLOAT at 0x0c90c7a8);
     * without it, 53 of 54 words differ */
    Float last = folding_door_action->motion->nbFrame - 1;

    if (CheckRangeOut(task)) {
        return;
    }
    hotel_door_draw(task);
    if (!hotel_door_near(work)) {
        /* @hack spelling: the frame decremented in the test, which SHC tests in
         * FR2 and stores in the slot of the BT/S at 0x0c90c7da. as a statement
         * of its own, SHC reads the frame back to test it, and 29 of 54 words
         * differ */
        if ((VARS(work)->frame -= DOOR_SPEED) <= 0.0F) {
            VARS(work)->frame = 0.0F;
            task->step = hotel_door_idle;
        }
    } else {
        task->step = hotel_door_open;
    }
    ObjectColliSet_1(work);
}

void hotel_door_wait(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    hotel_door_draw(task);
    if (!--work->tick) {
        task->step = hotel_door_close;
        dsPlay_oneshot(SE_DOOR, 0, 0, 0);
    }
    ObjectColliSet_1(work);
}

void hotel_door_open(struct task *task)
{
    struct task_work *work = task->work;
    Float last = folding_door_action->motion->nbFrame - 1;

    if (CheckRangeOut(task)) {
        return;
    }
    hotel_door_draw(task);
    VARS(work)->frame += DOOR_SPEED;
    if (VARS(work)->frame >= last) {
        VARS(work)->frame = last;
        work->tick = DOOR_WAIT;
        task->step = hotel_door_wait;
    }
    ObjectColliSet_1(work);
}

/* wait shut until a player comes near */
void hotel_door_idle(struct task *task)
{
    struct task_work *work = task->work;

    if (OnEdit(task)) {
        hotel_door_draw(task);
    } else {
        if (CheckRangeOut(task)) {
            return;
        }
        hotel_door_draw(task);
        if (hotel_door_near(work)) {
            task->step = hotel_door_open;
            dsPlay_oneshot(SE_DOOR, 0, 0, 0);
        }
        hotel_door_collide_shut(work);
    }
}

/* stay locked until the door's open test passes */
void hotel_door_locked(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        if (VARS(work)->open_test) {
            Bool (*open_test)(void) = VARS(work)->open_test;

            if (open_test()) {
                task->step = hotel_door_idle;
            }
        }
        hotel_door_collide_shut(work);
    }
    hotel_door_draw(task);
}

/* stay locked until hotel_pool_open passes. unlike hotel_door_locked, this
 * step doesn't call placement_try_leave first */
void hotel_pool_locked(struct task *task)
{
    struct task_work *work = task->work;

    if (!OnEdit(task)) {
        if (hotel_pool_open()) {
            task->step = hotel_door_idle;
        }
        hotel_door_collide_shut(work);
    }
    hotel_door_draw(task);
}

void hotel_door_destroy(struct task *task)
{
    FreeTaskC(task);
}

void ObjectSSHotelfront(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        CCL_Init(task, ccinfo, COLLISION_OBJECT, 1, DOOR_SHAPES);
    }
    VARS(work)->frame = 0.0F;
    work->tick = 0;
    VARS(work)->open_test = hotel_front_open;
    if (hotel_front_open()) {
        task->step = hotel_door_idle;
    } else {
        task->step = hotel_door_locked;
    }
    task->draw = hotel_door_draw;
    task->destructor = hotel_door_destroy;
}

void ObjectSSHotelback(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        CCL_Init(task, ccinfo, COLLISION_OBJECT, 1, DOOR_SHAPES);
    }
    VARS(work)->frame = 0.0F;
    work->tick = 0;
    VARS(work)->open_test = station_door_unlocked;
    if (station_door_unlocked()) {
        task->step = hotel_door_idle;
    } else {
        task->step = hotel_door_locked;
    }
    task->draw = hotel_door_draw;
    task->destructor = hotel_door_destroy;
}

void ObjectSSHotelpool(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        CCL_Init(task, ccinfo, COLLISION_OBJECT, 1, DOOR_SHAPES);
    }
    VARS(work)->frame = 0.0F;
    work->tick = 0;
    VARS(work)->open_test = hotel_pool_open;
    if (hotel_pool_open()) {
        task->step = hotel_door_idle;
    } else {
        task->step = hotel_pool_locked;
    }
    task->draw = hotel_door_draw;
    task->destructor = hotel_door_destroy;
}
