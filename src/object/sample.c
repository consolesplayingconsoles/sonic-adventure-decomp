/* @unit 8C0648C0-8C064DC0 +spflags +pool32 +poolafter=ObjectSampleM,ObjectSampleLRegular +synth16 */
/* samples: stand-ins, drawn as the marker cylinder, for things a player
 * carries, in three sizes, and for one the player shakes */
#include <ninja.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "object/common.h"
#include "object/placement.h"
#include "object/sample.h"
#include "player/player.h"
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
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
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
void ObjectSetupInput(struct task_work *work, struct task_motion *motion);
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

/* draw_highlight_near's mask for Big alone */
#define BIG_ONLY (1 << CHARACTER_BIG)

static void ObjectSampleSRegular(struct task *task);
static void sample_small_destroy(struct task *task);
static void ObjectSampleMRegular(struct task *task);
static void sample_medium_destroy(struct task *task);
static void ObjectSampleLRegular(struct task *task);
static void sample_large_destroy(struct task *task);
static void ObjectSampleSWRegular(struct task *task);
static void sample_shake_destroy(struct task *task);
extern struct collision_shape sample_small_shapes[2];
extern struct collision_shape sample_medium_shapes[2];
extern struct collision_shape sample_large_shapes[2];
extern struct collision_shape sample_shake_shapes[2];
/* clang-format on */

void ObjectSampleS(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    MODEL(work)->object = &object_cylinder01;
    if (!OnEdit(task)) {
        CCL_Init(task, sample_small_shapes, COLLISION_OBJECT, 1, 2);
    }
    carry_set_kind(work, motion, CARRY_KIND_SMALL);
    task->destructor = sample_small_destroy;
    task->step = ObjectSampleSRegular;
}

static void ObjectSampleSRegular(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    ObjectMovableSRegularExecute(task);
    ModelTurnWhite(work, ALL_CHARACTERS);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y + 2.5F, work->pos.z);
    TURN(njRotateY, work->ang.y);
    njScale(NULL, 0.25F, 0.25F, 0.25F);
    late_DrawObject(MODEL(work)->object);
    late_DrawObjectClipEx(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

static void sample_small_destroy(struct task *task)
{
}

void ObjectSampleM(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    MODEL(work)->object = &object_cylinder01;
    if (!OnEdit(task)) {
        CCL_Init(task, sample_medium_shapes, COLLISION_OBJECT, 1, 2);
    }
    carry_set_kind(work, motion, CARRY_KIND_MEDIUM);
    task->destructor = sample_medium_destroy;
    task->step = ObjectSampleMRegular;
}

static void ObjectSampleMRegular(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    ObjectMovableMRegularExecute(task);
    ModelTurnWhite(work, ALL_CHARACTERS);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y + 5.0F, work->pos.z);
    TURN(njRotateY, work->ang.y);
    njScale(NULL, 0.5F, 0.5F, 0.5F);
    late_DrawObject(MODEL(work)->object);
    late_DrawObjectClipEx(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

static void sample_medium_destroy(struct task *task)
{
}

void ObjectSampleL(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    MODEL(work)->object = &object_cylinder01;
    if (!OnEdit(task)) {
        CCL_Init(task, sample_large_shapes, COLLISION_OBJECT, 1, 2);
    }
    carry_set_kind(work, motion, CARRY_KIND_LARGE);
    task->destructor = sample_large_destroy;
    task->step = ObjectSampleLRegular;
}

static void ObjectSampleLRegular(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    ObjectMovableMRegularExecute(task);
    ModelTurnWhite(work, BIG_ONLY);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y + 15.0F, work->pos.z);
    TURN(njRotateY, work->ang.y);
    njScale(NULL, 1.5F, 1.5F, 1.5F);
    late_DrawObject(MODEL(work)->object);
    late_DrawObjectClipEx(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

static void sample_large_destroy(struct task *task)
{
}

void ObjectSampleSW(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    MODEL(work)->object = &object_cylinder01;
    if (!OnEdit(task)) {
        CCL_Init(task, sample_shake_shapes, COLLISION_OBJECT, 1, 2);
    }
    carry_set_kind(work, motion, CARRY_KIND_SHAKE);
    task->destructor = sample_shake_destroy;
    task->step = ObjectSampleSWRegular;
}

/* draw the sample moved by motion's accel, the push a shake gave it this
 * step. then step it as a carried thing that doesn't move by itself */
static void ObjectSampleSWRegular(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    if (CheckRangeOut(task)) {
        return;
    }
    ModelTurnWhite(work, ALL_CHARACTERS);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x + motion->accel.x,
                work->pos.y + motion->accel.y + 20.0F,
                work->pos.z + motion->accel.z);
    TURN(njRotateY, work->ang.y);
    njScale(NULL, 0.25F, 2.0F, 0.25F);
    late_DrawObject(MODEL(work)->object);
    late_DrawObjectClipEx(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    carry_step_still(task);
}

static void sample_shake_destroy(struct task *task)
{
}
