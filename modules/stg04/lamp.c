/* @unit 0C907060-0C907340 +egflags +pool32 */
/* O LAMP street lamp with two glows that face the camera, and O LAMP01 and
 * O LAMP02 lamps on arms */
#include <ninja.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/common.h"
#include "object/placement.h"
#include "stg04/lamp.h"
#include "system/cache.h"
#include "system/frame.h"
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
Bool FUN_8c0591fc(struct task *task);
Bool ObjectGCollision(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void FUN_0c907276(struct task *task);
void FUN_0c9072a8(struct task *task);
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

extern NJS_MODEL highway_lamp_model;
extern NJS_OBJECT highway_lamp_object;
extern NJS_MODEL highway_lamp_glow_1_model;
extern NJS_OBJECT highway_lamp_glow_1_object;
extern NJS_MODEL highway_lamp_glow_2_model;
extern NJS_OBJECT highway_lamp_glow_2_object;
extern NJS_OBJECT highway_lamp_1_object;
extern NJS_OBJECT highway_lamp_2_object;

/* the lamp's modes, in its work->mode. no code sets HIGHWAY_LAMP_GONE */
enum highway_lamp_mode {
    HIGHWAY_LAMP_INIT,
    HIGHWAY_LAMP_STAND,
    HIGHWAY_LAMP_GONE
};

void highway_lamp_clear_hit(struct task *task);
void highway_lamp_draw(struct task *task);
void highway_lamp_destroy(struct task *task);
extern struct collision_shape highway_lamp_shape;

void highway_lamp_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case HIGHWAY_LAMP_INIT:
        MODEL(work)->object = &highway_lamp_object;
        if (!OnEdit(task)) {
            CCL_Init(task, &highway_lamp_shape, COLLISION_OBJECT, 1, 1);
        }
        task->destructor = highway_lamp_destroy;
        task->draw = highway_lamp_draw;
        work->mode = HIGHWAY_LAMP_STAND;
        break;
    case HIGHWAY_LAMP_STAND:
        if (!OnEdit(task)) {
            highway_lamp_clear_hit(task);
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
        }
        highway_lamp_draw(task);
        break;
    case HIGHWAY_LAMP_GONE:
        break;
    }
}

void highway_lamp_clear_hit(struct task *task)
{
    struct task_work *work = task->work;

    if (work->collision->flags & COLLISION_HIT) {
        work->collision->flags &= ~COLLISION_HIT;
    }
}

/* on a frame's first step, draw the post, then a glow at each glow node.
 * each glow turns to face the camera and draws without fog. at each node, the
 * glow is the other node's model, but the two models are the same square */
void highway_lamp_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *glow_2;
    NJS_OBJECT *glow_1;

    if (loop_count) {
        return;
    }
    glow_2 = &highway_lamp_glow_2_object;
    glow_1 = &highway_lamp_glow_1_object;
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN(njRotateY, work->ang.y);
    ds_DrawModelClip(&highway_lamp_model);
    njPushMatrix(NULL);
    njTranslate(NULL, glow_2->pos[0], glow_2->pos[1], glow_2->pos[2]);
    TURN(njRotateY, -work->ang.y);
    TURN(njRotateY, camera_twp->ang.y);
    TURN(njRotateX, camera_twp->ang.x);
    njFogDisable();
    ds_DrawModelClip(&highway_lamp_glow_1_model);
    matrix_load_parent();
    njTranslate(NULL, glow_1->pos[0], glow_1->pos[1], glow_1->pos[2]);
    TURN(njRotateY, -work->ang.y);
    TURN(njRotateY, camera_twp->ang.y);
    TURN(njRotateX, camera_twp->ang.x);
    ds_DrawModelClip(&highway_lamp_glow_2_model);
    njFogEnable();
    late_DrawObjectClipEx(2);
}

void highway_lamp_destroy(struct task *task)
{
}

void FUN_0c907276(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &highway_lamp_1_object;
    if (!OnEdit(task)) {
        CCL_Init(task, &highway_lamp_shape, COLLISION_OBJECT, 1, 1);
    }
    FUN_8c0591fc(task);
}

void FUN_0c9072a8(struct task *task)
{
    struct task_work *work = task->work;

    MODEL(work)->object = &highway_lamp_2_object;
    if (!OnEdit(task)) {
        CCL_Init(task, &highway_lamp_shape, COLLISION_OBJECT, 1, 1);
    }
    FUN_8c0591fc(task);
}
