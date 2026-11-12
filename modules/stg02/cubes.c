/* @unit 0C908940-0C908AE0 +egflags +pool32 */
/* O_CUBES, O_CUBEM, O_CUBEL, O_UKISIM, O TATES and O TATEL: models that
 * stand solid. O BIGFLA: a model in the collision world */
#include <ninja.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "object/common.h"
#include "stg02/cubes.h"
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
Bool FUN_8c0591fc(struct task *task);
void FUN_0c908940(struct task *task);
void FUN_0c908972(struct task *task);
void FUN_0c9089a4(struct task *task);
void FUN_0c908a08(struct task *task);
void FUN_0c908a44(struct task *task);

#define BOX(x, y, z, half_x, half_y, half_z)                                   \
    {SHAPE_RECTANGLE,                                                          \
     0,                                                                        \
     PUSH_ALL | PUSH_FIRM(PUSH_ALL),                                           \
     {(x), (y), (z)},                                                          \
     (half_x),                                                                 \
     (half_y),                                                                 \
     (half_z),                                                                 \
     {0, 0, 0},                                                                \
     0,                                                                        \
     NULL}
extern NJS_OBJECT windy_small_cube_object;
extern NJS_OBJECT windy_medium_cube_object;
extern NJS_OBJECT windy_large_cube_object;
extern NJS_OBJECT windy_floating_island_object;
extern NJS_OBJECT windy_bigfla_object;
extern NJS_OBJECT windy_tate_large_object;
extern NJS_OBJECT windy_tate_small_object;
extern struct collision_shape windy_small_cube_shape;
extern struct collision_shape windy_medium_cube_shape;
extern struct collision_shape windy_large_cube_shape;
extern struct collision_shape windy_tate_small_shape;
extern struct collision_shape windy_tate_large_shapes[3];
extern struct collision_shape windy_floating_island_shapes[2];

void FUN_0c908940(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &windy_small_cube_object;
    if (!OnEdit(task)) {
        CCL_Init(task, &windy_small_cube_shape, COLLISION_OBJECT, 1, 1);
    }
    FUN_8c0591fc(task);
}

void FUN_0c908972(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &windy_medium_cube_object;
    if (!OnEdit(task)) {
        CCL_Init(task, &windy_medium_cube_shape, COLLISION_OBJECT, 1, 1);
    }
    FUN_8c0591fc(task);
}

void FUN_0c9089a4(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &windy_large_cube_object;
    if (!OnEdit(task)) {
        CCL_Init(task, &windy_large_cube_shape, COLLISION_OBJECT, 1, 1);
    }
    FUN_8c0591fc(task);
}

void windy_floating_island_step(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &windy_floating_island_object;
    if (!OnEdit(task)) {
        CCL_Init(task, windy_floating_island_shapes, COLLISION_OBJECT, 1, 2);
    }
    FUN_8c0591fc(task);
}

void FUN_0c908a08(struct task *task)
{
    struct task_work *work = task->work;

    WORLD_MODEL(work)->model = &windy_bigfla_object;
    ObjectGCollision(task);
}

void windy_tate_large_step(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &windy_tate_large_object;
    if (!OnEdit(task)) {
        CCL_Init(task, windy_tate_large_shapes, COLLISION_OBJECT, 1, 3);
    }
    FUN_8c0591fc(task);
}

void FUN_0c908a44(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &windy_tate_small_object;
    if (!OnEdit(task)) {
        CCL_Init(task, &windy_tate_small_shape, COLLISION_OBJECT, 1, 1);
    }
    FUN_8c0591fc(task);
}
