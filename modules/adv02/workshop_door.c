/* @unit 0C90D4C0-0C90D7E0 +r04 +egflags +pool32 +poolafter=workshop_door_reset,workshop_door_draw +asmfunc=ObjectMysticRuinTailsDoor:0c90d576 */
/* workshop door that swings open a quarter turn as the nearest player comes
 * near */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv02/texlists.h"
#include "adv02/workshop_door.h"
#include "camera/camera.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "player/player.h"
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
Bool OnEdit(struct task *task);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
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

#define DOOR_X 1432.5F
#define DOOR_Y 201.0F
#define DOOR_Z 809.5F
#define SHUT_ANG (-6990)
#define RUN_RANGE 400.0F
#define OPEN_REACH (30.0F * 30.0F)
#define OPEN_SWING 16384.0F
#define SPEED_UP 40.0F
#define TOP_SPEED 768.0F
#define SLOW_DOWN 30.0F
#define LOW_SPEED 112.0F
#define OPENING_BRAKE 0.65F
#define SHUTTING_BRAKE 0.35F
#define VARS(work) ((struct workshop_door_vars *)&(work)->vars)
#define OPENING(work) ((work)->submode)
extern NJS_MODEL workshop_door_model;

/* where the door stands, and its y angle shut */
/* outside the set editor, the step draws and runs the door only while the
 * camera is within RUN_RANGE of it */

/* the nearest player opens the door from within 30 units of it. OPEN_REACH is
 * 30 squared */

/* how far the door turns out from shut: a quarter turn, in Ninja's angle
 * units */
/* the moving door speeds up by SPEED_UP a step, up to TOP_SPEED. once it
 * brakes, it slows down by SLOW_DOWN a step, to no less than LOW_SPEED */
/* the opening door brakes once it is OPENING_BRAKE of OPEN_SWING out from shut,
 * and the shutting door once it is SHUTTING_BRAKE out */

enum workshop_door_mode { DOOR_INIT, DOOR_RUN };

struct workshop_door_vars {
    Float speed; /* the door's speed a step, below 0 while it shuts */
    Sint16 shut_ang; /* the door's y angle shut */
    Float swing; /* how far the door has turned out from shut */
};

/* TRUE while the nearest player is within OPEN_REACH, so the door opens, else
 * FALSE */

void ObjectMysticRuinTailsDoor(struct task *task);
void workshop_door_reset(struct task *task);
void workshop_door_update(struct task *task);
void workshop_door_draw(struct task *task);
void workshop_door_destroy(struct task *task);
extern struct collision_shape workshop_door_shape[1];
void workshop_door_step(struct task *task);

void ObjectMysticRuinTailsDoor(struct task *task)
{
    struct task_work *work = task->work;

    work->pos.x = DOOR_X;
    work->pos.y = DOOR_Y;
    work->pos.z = DOOR_Z;
    work->ang.y = SHUT_ANG;
    task->draw = workshop_door_draw;
    task->destructor = workshop_door_destroy;
    workshop_door_reset(task);
    work->mode = DOOR_RUN;
}

void workshop_door_reset(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->shut_ang = work->ang.y;
    VARS(work)->swing = 0.0F;
    VARS(work)->speed = 0.0F;
}

void workshop_door_update(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 player;
    Float x;
    Float y;
    Float z;

    player = playertwp[GetTheNearestPlayerNumber(&work->pos)]->pos;
    x = player.x - work->pos.x;
    y = player.y - work->pos.y;
    z = player.z - work->pos.z;
    if ((x * x) + (y * y) + (z * z) < OPEN_REACH) {
        OPENING(work) = TRUE;
    } else {
        OPENING(work) = FALSE;
    }
    if (OPENING(work)) {
        if (VARS(work)->swing < OPEN_SWING * OPENING_BRAKE) {
            VARS(work)->speed += SPEED_UP;
            if (VARS(work)->speed > TOP_SPEED) {
                VARS(work)->speed = TOP_SPEED;
            }
        } else {
            VARS(work)->speed -= SLOW_DOWN;
            if (VARS(work)->speed < LOW_SPEED) {
                VARS(work)->speed = LOW_SPEED;
            }
        }
    } else {
        if (VARS(work)->swing > OPEN_SWING * SHUTTING_BRAKE) {
            VARS(work)->speed -= SPEED_UP;
            if (VARS(work)->speed < -TOP_SPEED) {
                VARS(work)->speed = -TOP_SPEED;
            }
        } else {
            VARS(work)->speed += SLOW_DOWN;
            if (VARS(work)->speed > -LOW_SPEED) {
                VARS(work)->speed = -LOW_SPEED;
            }
        }
    }
    VARS(work)->swing += VARS(work)->speed;
    if (VARS(work)->swing < 0.0F) {
        VARS(work)->swing = 0.0F;
    } else if (VARS(work)->swing > OPEN_SWING) {
        VARS(work)->swing = OPEN_SWING;
    }
    work->ang.y = VARS(work)->shut_ang + VARS(work)->swing;
}

void workshop_door_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njSetTexture_jp(&mrobj_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&workshop_door_model);
    late_DrawObjectClipEx(1);
}

void workshop_door_destroy(struct task *task)
{
}
