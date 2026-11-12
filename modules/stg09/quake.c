/* @unit 0C9147E0-0C914940 +r04 +egflags +asmfunc=quake_start:0c914940 */
/* a quake: the camera bobs like a settling spring, and pad 0 vibrates */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "player/player.h"
#include "stg09/quake.h"
#include "system/task.h"
#include "vmu/vibration.h"
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
void DestroyTask(struct task *task);
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
extern struct task_work *camera_twp;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void FUN_8c01a7a4(NJS_VECTOR *offset);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
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
void VibShot(int pad, int power, int freq, int time);
extern Float quake_keep;
extern Float quake_pull_above;
extern Float quake_pull_below;

/* the spring, in work->scl. the camera's offset in y is the stretch times
 * the strength */
#define STRETCH(work) ((work)->scl.x)
#define SPEED(work) ((work)->scl.y)
#define STRENGTH(work) ((work)->scl.z)

/* the share of its speed the spring keeps each step */

void quake_run(struct task *task);

void quake_step(struct task *task)
{
    task->step = quake_run;
}

/* the quake's step after the first. it ends the quake once the camera's
 * offset and the strength are both less than 0.5 in size. the strength never
 * changes, so a quake whose strength is 0.5 or more never ends */
void quake_run(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VECTOR offset;

    STRETCH(work) += SPEED(work);
    SPEED(work) -= STRETCH(work) >= 0.0F ? STRETCH(work) * quake_pull_above
                                         : STRETCH(work) * quake_pull_below;
    SPEED(work) *= quake_keep;
    offset.x = 0.0F;
    offset.y = STRETCH(work) * STRENGTH(work);
    offset.z = 0.0F;
    FUN_8c01a7a4(&offset);
    if (_builtin_fabsf(offset.y) < 0.5F &&
        _builtin_fabsf(STRENGTH(work)) < 0.5F) {
        FreeTask(task);
    }
}

struct task *quake_start(NJS_POINT3 *pos, Float radius, Float speed)
{
    struct task_work *player = playertwp[0];
    struct task *task;
    struct task_work *work;
    Float power;
    Float distance = CalcDistance(pos, &player->pos);

    if (distance < radius) {
        task = CreateElementalTask(TASK_WORK, 3, quake_step);
        if (task) {
            work = task->work;
            STRETCH(work) = 0.0F;
            SPEED(work) = speed;
            /* @bug uninitialized: no path sets power before the strength
             * divides it by radius. SHC reads it from FR15 as the caller left
             * it (FMOV FR15,FR2 at 0x0c915a38). lion_slam, the one caller,
             * calls this at 0x0c910804 before it writes FR15. FR15 then holds
             * the 0.0F that lion_run loads (FLDI0 at 0x0c910d0e) before both
             * its calls of lion_slam. every quake's strength is 1.0F, and no
             * quake ends */
#ifdef GCC
            /* keeps the shipped strength the tag names: power is lion_run's
             * 0.0F */
            power = 0.0F;
#endif
            /* NOLINTNEXTLINE(clang-diagnostic-uninitialized) */
            STRENGTH(work) = 1.0F - (power / radius);
            power = 1.0F + (SPEED(work) * STRENGTH(work) * 2.0F);
            if (power > 6.0F) {
                power = 6.0F;
            }
            VibShot(0, (int)power, 15, 0);
            return task;
        }
    }
    return NULL;
}
