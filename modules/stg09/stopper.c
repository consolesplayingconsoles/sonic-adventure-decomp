/* @unit 0C903260-0C9038C0 +egflags +pool32 */
/* StoperC, StoperL and StoperR stoppers on the pinball tables */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "collision/world.h"
#include "draw/model.h"
#include "object/common.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stg09/casino.h"
#include "stg09/pinball.h"
#include "stg09/stopper.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
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
int thunk_FUN_8c09cbc0(char *name, void *dest);
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

/* StoperC's base and top, then the two drawn while CASINO_STOPPER_C_UP is
 * set */
#define VARS(work) ((struct stopper_vars *)&(work)->vars)
#define SWITCH_TOUCHING 0x8000
#define SWITCH_GAP 40.0F
#define C_DOWN (-4.5F)
#define C_RISE 0.5F
#define ARM_DOWN NJM_DEG_ANG(-25.5)
#define ARM_SWING 0x100
#define ARM_RINGS 8 /* given for a touch of a raised arm */
extern NJS_MODEL stopper_c_base_model;
extern NJS_MODEL stopper_c_top_model;
extern NJS_MODEL stopper_c_base_up_model;
extern NJS_MODEL stopper_c_top_up_model;
/* StoperL's and StoperR's base and arm, then the two drawn while the
 * stopper's bit is set */
extern NJS_MODEL stopper_base_model;
extern NJS_MODEL stopper_arm_model;
extern NJS_MODEL stopper_base_up_model;
extern NJS_MODEL stopper_arm_up_model;

enum stopper_mode { STOPPER_C, STOPPER_L, STOPPER_R };

struct stopper_vars {
    /* the object kind's param, which the destructor passes to world_remove
     * and world_object_free. StoperC's param is null, and StoperC puts
     * nothing in the world, so both calls do nothing */
    NJS_OBJECT *object;
    Float height; /* the height StoperC's top is drawn at, C_DOWN up to 0 */
};
extern struct collision_shape stopper_shapes[3];

void Exit(struct task *task)
{
    struct task_work *work = task->work;

    if (work->mode == STOPPER_C) {
        NJS_OBJECT *object = VARS(work)->object;

        WithdrawCollisionEntry(task, object);
        ReleaseMobileLandObject(object);
    } else {
        FreeTaskC(task);
    }
}

void DispC(struct task *task)
{
    struct task_work *work = task->work;

    casino_set_texture(CASINO_TEXTURES_ACTS_34);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    if (!(PinballFlag & CASINO_STOPPER_C_UP)) {
        ds_DrawModelClip(&stopper_c_base_model);
        njTranslate(NULL, 0.0F, VARS(work)->height, 0.0F);
        ds_DrawModelClip(&stopper_c_top_model);
    } else {
        ds_DrawModelClip(&stopper_c_base_up_model);
        njTranslate(NULL, 0.0F, VARS(work)->height, 0.0F);
        ds_DrawModelClip(&stopper_c_top_up_model);
    }
    late_DrawObjectClipEx(1);
}

void DispLR(struct task *task)
{
    struct task_work *work = task->work;

    casino_set_texture(CASINO_TEXTURES_ACTS_34);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    if ((work->mode == STOPPER_L && !(PinballFlag & CASINO_STOPPER_L_UP)) ||
        (work->mode == STOPPER_R && !(PinballFlag & CASINO_STOPPER_R_UP))) {
        ds_DrawModelClip(&stopper_base_model);
        TURN(njRotateX, work->ang.x);
        ds_DrawModelClip(&stopper_arm_model);
    } else {
        ds_DrawModelClip(&stopper_base_up_model);
        TURN(njRotateX, work->ang.x);
        ds_DrawModelClip(&stopper_arm_up_model);
    }
    late_DrawObjectClipEx(1);
}

void cNormalLR(struct task *task)
{
    struct task_work *work = task->work;

    if (work->collision->flags & COLLISION_HIT) {
        if (!(work->flags & SWITCH_TOUCHING)) {
            if (PinballFlag & CASINO_UNK_100) {
                pinball_view = PINBALL_VIEW_MOVING | PINBALL_VIEW_TABLE;
                PinballFlag &= ~CASINO_UNK_100;
            } else {
                PinballFlag |= CASINO_UNK_100;
            }
            work->flags |= SWITCH_TOUCHING;
        }
    } else {
        work->flags &= ~SWITCH_TOUCHING;
    }
    EntryColliList(work);
    ObjectSetupInput(work, NULL);
}

void NormalC(struct task *task)
{
    struct task_work *work = task->work;

    if (PinballFlag & CASINO_STOPPER_C_UP) {
        if (VARS(work)->height != 0.0F) {
            VARS(work)->height += C_RISE;
            if (VARS(work)->height > 0.0F) {
                VARS(work)->height = 0.0F;
            }
        }
        work->collision->shapes->flags &= ~SHAPE_OFF;
    } else {
        if (VARS(work)->height != C_DOWN) {
            VARS(work)->height -= C_RISE;
            if (VARS(work)->height < C_DOWN) {
                VARS(work)->height = C_DOWN;
            }
        } else {
            work->collision->shapes->flags |= SHAPE_OFF;
        }
    }
    EntryColliList(work);
    ObjectSetupInput(work, NULL);
    DispC(task);
    /* @hack redundant: the return, which makes SHC open the frame in the
     * prologue with ADD #-4,R15 and store task with MOV.L R4,@R15 (0x0c903804,
     * 0x0c90380c). without it, SHC pushes task with MOV.L R4,@-R15, the
     * function runs 2 bytes short and 64 of 64 words differ */
    /* NOLINTNEXTLINE(readability-redundant-control-flow) */
    return;
}

void stopper_l_run(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VECTOR speed;
    Angle ang[3];

    if (PinballFlag & CASINO_STOPPER_L_UP) {
        if (work->collision->flags & COLLISION_HIT) {
            ang[0] = 0;
            ang[1] = NJM_DEG_ANG(180);
            ang[2] = 0;
            speed.x = 5.0F;
            speed.y = 0.0F;
            speed.z = 0.0F;
            player_send_flying(0, &speed, ang, 0);
            dsPlay_oneshot(SE_SPRING, 0, 0, 0);
            SetGetRing(ARM_RINGS);
            PinballFlag &= ~CASINO_STOPPER_L_UP;
        }
        if (work->ang.x != 0) {
            work->ang.x += ARM_SWING;
            if (work->ang.x > 0) {
                work->ang.x = 0;
            }
        }
    } else {
        if (work->ang.x != ARM_DOWN) {
            work->ang.x -= ARM_SWING;
            if (work->ang.x < ARM_DOWN) {
                work->ang.x = ARM_DOWN;
            }
        }
    }
    EntryColliList(work);
    ObjectSetupInput(work, NULL);
    DispLR(task);
    LoopTaskC(task);
}

void stopper_r_run(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VECTOR speed;
    Angle ang[3];

    if (PinballFlag & CASINO_STOPPER_R_UP) {
        if (work->collision->flags & COLLISION_HIT) {
            ang[0] = 0;
            ang[1] = NJM_DEG_ANG(180);
            ang[2] = 0;
            speed.x = 5.0F;
            speed.y = 0.0F;
            speed.z = 0.0F;
            player_send_flying(0, &speed, ang, 0);
            dsPlay_oneshot(SE_SPRING, 0, 0, 0);
            SetGetRing(ARM_RINGS);
            PinballFlag &= ~CASINO_STOPPER_R_UP;
        }
        if (work->ang.x != 0) {
            work->ang.x += ARM_SWING;
            if (work->ang.x > 0) {
                work->ang.x = 0;
            }
        }
    } else {
        if (work->ang.x != ARM_DOWN) {
            work->ang.x -= ARM_SWING;
            if (work->ang.x < ARM_DOWN) {
                work->ang.x = ARM_DOWN;
            }
        }
    }
    EntryColliList(work);
    ObjectSetupInput(work, NULL);
    DispLR(task);
    LoopTaskC(task);
}

void ObjectStoperC(struct task *task)
{
    struct task_work *work = task->work;

    CCL_Init(task, &stopper_shapes[2], COLLISION_OBJECT, 1, 1);
    work->mode = STOPPER_C;
    VARS(work)->height = C_DOWN;
    work->collision->shapes->flags |= SHAPE_OFF;
    PinballFlag &= ~CASINO_STOPPER_C_UP;
    task->step = NormalC;
    task->draw = DispC;
    task->destructor = Exit;
}

void stopper_l_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task *child;
    struct task_work *switch_work;
    NJS_POINT3 *from;
    struct angles *from_ang;
    NJS_POINT3 *to;
    struct angles *to_ang;

    work->mode = STOPPER_L;
    CCL_Init(task, &stopper_shapes[0], COLLISION_OBJECT, 1, 1);
    child = CreateChildTask(TASK_WORK, cNormalLR, task);
    /* @hack spelling: the switch's place and angles copied through pointers,
     * which SHC forms with ADD #32 and ADD #20 (0x0c903b5e, 0x0c903b68).
     * through the members, the step runs 12 bytes short and 58 of 68 words
     * differ */
    /* @hack spelling: from and from_ang set before switch_work, so that SHC
     * loads child->work (0x0c903b58) ahead of MOV R13,R1. set after it, the
     * two trade places and 10 of 68 words differ */
    from = &work->pos;
    from_ang = &work->ang;
    switch_work = child->work;
    to = &switch_work->pos;
    to_ang = &switch_work->ang;
    to->x = from->x;
    to->y = from->y;
    to->z = from->z - SWITCH_GAP;
    to_ang->x = from_ang->x;
    to_ang->y = from_ang->y;
    to_ang->z = from_ang->z;
    CCL_Init(child, &stopper_shapes[1], COLLISION_OBJECT, 1, 1);
    PinballFlag &= ~CASINO_STOPPER_L_UP;
    task->step = stopper_l_run;
    task->draw = DispLR;
    task->destructor = Exit;
}

void stopper_r_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task *child;
    struct task_work *switch_work;
    NJS_POINT3 *from;
    struct angles *from_ang;
    NJS_POINT3 *to;
    struct angles *to_ang;

    work->mode = STOPPER_R;
    CCL_Init(task, &stopper_shapes[0], COLLISION_OBJECT, 1, 1);
    child = CreateChildTask(TASK_WORK, cNormalLR, task);
    /* @hack spelling: the switch's place and angles copied through pointers, as
     * in stopper_l_step (0x0c903be8, 0x0c903bf2). through the members, the
     * step runs 12 bytes short and 58 of 69 words differ */
    /* @hack spelling: from and from_ang set before switch_work, as in
     * stopper_l_step (0x0c903be2). set after it, 10 of 69 words differ */
    from = &work->pos;
    from_ang = &work->ang;
    switch_work = child->work;
    to = &switch_work->pos;
    to_ang = &switch_work->ang;
    to->x = from->x;
    to->y = from->y;
    to->z = from->z - SWITCH_GAP;
    to_ang->x = from_ang->x;
    to_ang->y = from_ang->y;
    to_ang->z = from_ang->z;
    CCL_Init(child, &stopper_shapes[1], COLLISION_OBJECT, 1, 1);
    PinballFlag &= ~CASINO_STOPPER_R_UP;
    task->step = stopper_r_run;
    task->draw = DispLR;
    task->destructor = Exit;
}
