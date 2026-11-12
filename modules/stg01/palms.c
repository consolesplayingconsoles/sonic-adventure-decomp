/* @unit 0C907E00-0C908620 +r04 +egflags +pool32 */
/* YASI0 to YASI3: palms with solid trunks. the leaves of YASI0 to YASI2
 * turn to face the camera */
#include <ninja.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/common.h"
#include "object/placement.h"
#include "stg01/palms.h"
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
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void FUN_0c907e00(struct task *task);
void FUN_0c90801a(struct task *task);
void FUN_0c908244(struct task *task);
void FUN_0c9084c0(struct task *task);
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

extern NJS_MODEL beach_palm_0_trunk_model;
extern NJS_OBJECT beach_palm_0_leaves_a_object;
extern NJS_OBJECT beach_palm_0_leaves_b_object;
extern NJS_MODEL beach_palm_1_trunk_model;
extern NJS_OBJECT beach_palm_1_leaves_a_object;
extern NJS_OBJECT beach_palm_1_leaves_b_object;
extern NJS_MODEL beach_palm_2_trunk_model;
extern NJS_OBJECT beach_palm_2_leaves_a_object;
extern NJS_OBJECT beach_palm_2_leaves_b_object;
extern NJS_MODEL beach_palm_3_model;

/* PALM_KILL's step kills the placement. no code sets it */
enum beach_palm_mode { PALM_INIT, PALM_RUN, PALM_KILL };
extern struct collision_shape beach_palm_0_shape;
extern struct collision_shape beach_palm_1_shape;
extern struct collision_shape beach_palm_2_shape;
extern struct collision_shape beach_palm_3_shape;

void beach_palm_0_draw(struct task *task);
void beach_palm_1_draw(struct task *task);
void beach_palm_2_draw(struct task *task);
void beach_palm_destroy(struct task *task);
void beach_palm_3_draw(struct task *task);

void FUN_0c907e00(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case PALM_INIT:
        if (!OnEdit(task)) {
            CCL_Init(task, &beach_palm_0_shape, COLLISION_OBJECT, 1, 1);
        }
        task->destructor = beach_palm_destroy;
        task->draw = beach_palm_0_draw;
        work->mode = PALM_RUN;
        break;
    case PALM_RUN:
        if (!OnEdit(task)) {
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
        }
        beach_palm_0_draw(task);
        break;
    case PALM_KILL:
        DeadOut(task);
        break;
    }
}

/* each cluster of leaves takes back the palm's turn about y. it then turns
 * by the camera's y and x angles to face the camera. on this palm alone,
 * the second cluster turns a further quarter turn about y */
void beach_palm_0_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *leaves_a = &beach_palm_0_leaves_a_object;
    NJS_OBJECT *leaves_b = &beach_palm_0_leaves_b_object;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&beach_palm_0_trunk_model);
    njPushMatrix(NULL);
    njTranslate(NULL, leaves_a->pos[0], leaves_a->pos[1], leaves_a->pos[2]);
    TURN_VIA(njRotateY, -work->ang.y, ang);
    TURN_VIA(njRotateY, camera_twp->ang.y, ang);
    TURN_VIA(njRotateX, camera_twp->ang.x, ang);
    ds_DrawModelClip(leaves_a->model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, leaves_b->pos[0], leaves_b->pos[1], leaves_b->pos[2]);
    TURN_VIA(njRotateY, -work->ang.y, ang);
    TURN_VIA(njRotateY, camera_twp->ang.y, ang);
    TURN_VIA(njRotateX, camera_twp->ang.x, ang);
    njRotateY(NULL, NJM_DEG_ANG(90));
    ds_DrawModelClip(leaves_b->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

void FUN_0c90801a(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case PALM_INIT:
        if (!OnEdit(task)) {
            CCL_Init(task, &beach_palm_1_shape, COLLISION_OBJECT, 1, 1);
        }
        task->destructor = beach_palm_destroy;
        task->draw = beach_palm_1_draw;
        work->mode = PALM_RUN;
        break;
    case PALM_RUN:
        if (!OnEdit(task)) {
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
        }
        beach_palm_1_draw(task);
        break;
    case PALM_KILL:
        DeadOut(task);
        break;
    }
}

void beach_palm_1_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *leaves_a = &beach_palm_1_leaves_a_object;
    NJS_OBJECT *leaves_b = &beach_palm_1_leaves_b_object;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&beach_palm_1_trunk_model);
    njPushMatrix(NULL);
    njTranslate(NULL, leaves_a->pos[0], leaves_a->pos[1], leaves_a->pos[2]);
    TURN_VIA(njRotateY, -work->ang.y, ang);
    TURN_VIA(njRotateY, camera_twp->ang.y, ang);
    TURN_VIA(njRotateX, camera_twp->ang.x, ang);
    ds_DrawModelClip(leaves_a->model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, leaves_b->pos[0], leaves_b->pos[1], leaves_b->pos[2]);
    TURN_VIA(njRotateY, -work->ang.y, ang);
    TURN_VIA(njRotateY, camera_twp->ang.y, ang);
    TURN_VIA(njRotateX, camera_twp->ang.x, ang);
    ds_DrawModelClip(leaves_b->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

void FUN_0c908244(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case PALM_INIT:
        if (!OnEdit(task)) {
            CCL_Init(task, &beach_palm_2_shape, COLLISION_OBJECT, 1, 1);
        }
        task->destructor = beach_palm_destroy;
        task->draw = beach_palm_2_draw;
        work->mode = PALM_RUN;
        break;
    case PALM_RUN:
        if (!OnEdit(task)) {
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
        }
        beach_palm_2_draw(task);
        break;
    case PALM_KILL:
        DeadOut(task);
        break;
    }
}

void beach_palm_2_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *leaves_a = &beach_palm_2_leaves_a_object;
    NJS_OBJECT *leaves_b = &beach_palm_2_leaves_b_object;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&beach_palm_2_trunk_model);
    njPushMatrix(NULL);
    njTranslate(NULL, leaves_a->pos[0], leaves_a->pos[1], leaves_a->pos[2]);
    TURN_VIA(njRotateY, -work->ang.y, ang);
    TURN_VIA(njRotateY, camera_twp->ang.y, ang);
    TURN_VIA(njRotateX, camera_twp->ang.x, ang);
    ds_DrawModelClip(leaves_a->model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, leaves_b->pos[0], leaves_b->pos[1], leaves_b->pos[2]);
    TURN_VIA(njRotateY, -work->ang.y, ang);
    TURN_VIA(njRotateY, camera_twp->ang.y, ang);
    TURN_VIA(njRotateX, camera_twp->ang.x, ang);
    ds_DrawModelClip(leaves_b->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

void beach_palm_destroy(struct task *task)
{
}

void FUN_0c9084c0(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case PALM_INIT:
        if (!OnEdit(task)) {
            CCL_Init(task, &beach_palm_3_shape, COLLISION_OBJECT, 1, 1);
        }
        task->destructor = beach_palm_destroy;
        task->draw = beach_palm_3_draw;
        work->mode = PALM_RUN;
        break;
    case PALM_RUN:
        if (!OnEdit(task)) {
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
        }
        beach_palm_3_draw(task);
        break;
    case PALM_KILL:
        DeadOut(task);
        break;
    }
}

void beach_palm_3_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&beach_palm_3_model);
    late_DrawObjectClipEx(1);
}
