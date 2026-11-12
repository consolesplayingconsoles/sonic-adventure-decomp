/* @unit 0C90F840-0C90FB40 @data 0CADBBC8-0CADBBCC +egflags +pool32 */
/* O HAGO, a base with two rails. an arm on it rocks about x, 15 degrees each
 * way */
#include <ninja.h>

#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/common.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg05/rocker.h"
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

#define TILT(work) ((work)->scl.x)
#define ROCKER_STEP 80.0F /* the tilt's change each step */
#define ROCKER_BOUND 2730.5F /* the tilt's bound each way: 15 degrees */
#define ROCKER_REACH 68.0F
#define DRAW_RADIUS 500.0F
extern NJS_TEXLIST texlist_obj_mountain;
extern NJS_MODEL rocker_arm_model;
extern NJS_OBJECT rocker_arm_object;
extern NJS_MODEL rocker_base_model;
extern NJS_OBJECT rocker_world_object;

/* the arm's tilt about x, in angle units, as a float. it takes the place of
 * the set entry's scale x, which the rocker never reads */

enum rocker_mode { ROCKER_UP, ROCKER_DOWN };
extern struct collision_shape rocker_shapes[2];

void Exec(struct task *task);
void rocker_draw(struct task *task);
void rocker_destroy(struct task *task);

/* start the arm level. unless the set editor holds the rocker, put a copy of
 * rocker_world_object in the world. the rails then get their boxes. the copy
 * stands at the rocker's place plus that object's position */
void rocker_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_force *force = task->force;
    NJS_OBJECT *world;

    work->ang.x = 0;
    work->ang.z = 0;
    TILT(work) = 0.0F;
    work->mode = ROCKER_UP;
    force->turn.x = 0;
    force->turn.y = 0;
    force->turn.z = 0;
    force->speed.x = 0.0F;
    force->speed.y = 0.0F;
    force->speed.z = 0.0F;
    if (!OnEdit(task)) {
        WORLD_MODEL(work)->model = &rocker_world_object;
        world = GetMobileLandObject();
        WORLD_MODEL(work)->world = world;
        world->evalflags =
            NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK | NJD_EVAL_ZXY_ANG;
        world->scl[0] = WORLD_MODEL(work)->model->scl[0];
        world->scl[1] = WORLD_MODEL(work)->model->scl[1];
        world->scl[2] = WORLD_MODEL(work)->model->scl[2];
        world->ang[0] = 0;
        world->ang[1] = work->ang.y;
        world->ang[2] = 0;
        world->pos[0] = work->pos.x + WORLD_MODEL(work)->model->pos[0];
        world->pos[1] = work->pos.y + WORLD_MODEL(work)->model->pos[1];
        world->pos[2] = work->pos.z + WORLD_MODEL(work)->model->pos[2];
        world->model = WORLD_MODEL(work)->model->model;
        world->child = NULL;
        world->sibling = NULL;
        RegisterCollisionEntry(WORLD_MOVES, task, world);
        CCL_Init(task, rocker_shapes, COLLISION_OBJECT, 1, 2);
    }
    task->step = Exec;
    task->draw = rocker_draw;
    task->destructor = rocker_destroy;
}

/* rock the arm between -ROCKER_BOUND and ROCKER_BOUND, ROCKER_STEP a step.
 * unless the set editor holds the rocker, its copy in the world tilts with
 * it */
void Exec(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case ROCKER_UP:
        TILT(work) += ROCKER_STEP;
        if (TILT(work) >= ROCKER_BOUND) {
            TILT(work) = ROCKER_BOUND;
            work->mode = ROCKER_DOWN;
        }
        break;
    case ROCKER_DOWN:
        TILT(work) -= ROCKER_STEP;
        if (TILT(work) <= -ROCKER_BOUND) {
            TILT(work) = -ROCKER_BOUND;
            work->mode = ROCKER_UP;
        }
        break;
    }
    if (!OnEdit(task)) {
        if (player_in_range(&work->pos, ROCKER_REACH)) {
            work->flags |= WORLD_TESTED;
        } else {
            work->flags &= ~WORLD_TESTED;
        }
        WORLD_MODEL(work)->world->ang[0] = (Angle)TILT(work);
        WORLD_MODEL(work)->world->ang[1] = work->ang.y;
        EntryColliList(work);
    }
    rocker_draw(task);
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "->");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "->");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "->");
    }
}

void rocker_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, DRAW_RADIUS)) {
        njSetTexture_jp(&texlist_obj_mountain);
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        ds_DrawModelClip(&rocker_base_model);
        njTranslate(NULL, rocker_arm_object.pos[0], rocker_arm_object.pos[1],
                    rocker_arm_object.pos[2]);
        TURN_VIA(njRotateX, (Angle)TILT(work), ang);
        ds_DrawModelClip(&rocker_arm_model);
        late_DrawObjectClipEx(1);
    }
}

void rocker_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (WORLD_MODEL(work)->world != NULL) {
        WithdrawCollisionEntry(task, WORLD_MODEL(work)->world);
        ReleaseMobileLandObject(WORLD_MODEL(work)->world);
    }
}
