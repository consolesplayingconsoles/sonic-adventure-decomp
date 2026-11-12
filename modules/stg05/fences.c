/* @unit 0C905DA0-0C905F40 +r04 +egflags +pool32 */
/* the O SAKU, O SAKU2, MT_TSAKU and MT_SOTO fences, the O ROUYA prison door
 * and the MT_TBOX crate. each draws at one more than its set entry's
 * scale */
#include <ninja.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "object/common.h"
#include "stg05/fences.h"
#include "system/task.h"
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
void EntryColliList(struct task_work *work);
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
void ObjectSetupInput(struct task_work *work, struct task_motion *motion);
void InitObjects(void);
Bool FUN_8c059108(struct task *task);
Bool ObjectGCollision(struct task *task);
void FUN_8c059854(struct task_work *work);
void FUN_0c905da0(struct task *task);
void FUN_0c905e20(struct task *task);
void FUN_0c905e6e(struct task *task);
void FUN_0c905eae(struct task *task);

extern NJS_TEXLIST texlist_obj_mountain;
extern NJS_OBJECT mountain_fence_object;
extern NJS_OBJECT mountain_fence_2_object;
extern NJS_OBJECT prison_door_object;
extern NJS_OBJECT mountain_crate_object;
extern NJS_OBJECT iron_fence_object;
extern struct collision_shape mountain_fence_2_shapes[3];
extern struct collision_shape mountain_crate_shape;
extern struct collision_shape prison_door_shape;
extern struct collision_shape iron_fence_shape;
extern struct collision_shape mountain_fence_shape;

void FUN_0c905da0(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &mountain_fence_object;
    MODEL(work)->texlist = &texlist_obj_mountain;
    if (!OnEdit(task)) {
        CCL_Init(task, &mountain_fence_shape, 4, 1, 1);
        FUN_8c059854(work);
    }
    model_start_solid_scaled(task);
}

void mountain_fence_2_step(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &mountain_fence_2_object;
    MODEL(work)->texlist = &texlist_obj_mountain;
    if (!OnEdit(task)) {
        CCL_Init(task, mountain_fence_2_shapes, 4, 1, 3);
        FUN_8c059854(work);
    }
    model_start_solid_scaled(task);
}

void FUN_0c905e20(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &prison_door_object;
    MODEL(work)->texlist = &texlist_obj_mountain;
    if (!OnEdit(task)) {
        CCL_Init(task, &prison_door_shape, 4, 1, 1);
        FUN_8c059854(work);
    }
    model_start_solid_scaled(task);
}

/* MT_SOTO: O SAKU's fence, with no collision */
void mountain_fence_outside_step(struct task *task)
{
    struct task_work *work = task->work;
    ((struct model_vars *)&(work)->vars)->object = &mountain_fence_object;
    ((struct model_vars *)&(work)->vars)->texlist = &texlist_obj_mountain;
    FUN_8c059108(task);
}

void FUN_0c905e6e(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &mountain_crate_object;
    MODEL(work)->texlist = &texlist_obj_mountain;
    if (!OnEdit(task)) {
        CCL_Init(task, &mountain_crate_shape, 4, 1, 1);
        FUN_8c059854(work);
    }
    model_start_solid_scaled(task);
}

void FUN_0c905eae(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &iron_fence_object;
    MODEL(work)->texlist = &texlist_obj_mountain;
    if (!OnEdit(task)) {
        CCL_Init(task, &iron_fence_shape, 4, 1, 1);
        FUN_8c059854(work);
    }
    model_start_solid_scaled(task);
}
