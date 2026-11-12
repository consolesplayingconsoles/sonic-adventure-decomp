/* @unit 8C044680-8C044A20 +r04 +egflags +pool32 */
/* crash stars: the stars that burst from a player as it crashes into a
 * wall */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "camera/camera.h"
#include "effect/crash_stars.h"
#include "object/models.h"
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
void *syMalloc_default_malloc(size_t size);
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
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
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

/* how many stars burst, the steps each flies, and how far it flies a step */
#define STAR_COUNT 6
#define STAR_STEPS 10
#define STAR_SPEED 2.0F
/* the headings a star can take, evenly round, and the bound of its tilt
 * about x, 67.5 degrees */
#define STAR_HEADINGS 32.0F
#define STAR_TILT 12288.0F

enum crash_stars_mode { CRASH_STARS_START, CRASH_STARS_PLACED };
enum star_mode { STAR_START, STAR_FLY, STAR_END };

void CrashInit(struct task_work *work);
void CrashStarGenerate(struct task_work *from);
void CrashStar(struct task *task);
void crash_star_fly(struct task_work *work);

void EffectCrash(struct task *task)
{
    struct task_work *work = task->work;

    CrashInit(work);
    CrashStarGenerate(work);
    /* @hack redundant: the call in a loop of one pass, which keeps it a JSR
     * from a frame of its own (ADD #-4,R15 at 0x8c0473c4); alone, it becomes
     * a tail jump, the function runs 4 bytes short and 16 of 17 words differ */
    do {
        FreeTask(task);
    } while (0);
}

void CrashInit(struct task_work *work)
{
    struct task_work *player;
    NJS_POINT3 offset;
    NJS_POINT3 point;

    work->mode = CRASH_STARS_PLACED;
    player = playertwp[CRASH_STARS_VARS(work)->player];
    if (player != NULL) {
        offset.x = offset.z = 0.0F;
        offset.y = 5.0F;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, player->ang.z);
        TURN(njRotateX, player->ang.x);
        TURN(njRotateY, -player->ang.y);
        njCalcVector(NULL, &offset, &point);
        late_DrawObjectClipEx(1);
        work->pos.x = player->pos.x + point.x;
        work->pos.y = player->pos.y + point.y;
        work->pos.z = player->pos.z + point.z;
    }
}

/* start STAR_COUNT stars at from's place. one random draw picks a star's
 * heading, its tilt and its color, yellow or orange */
void CrashStarGenerate(struct task_work *from)
{
    int i;
    struct task *task;
    struct task_work *work;
    Float roll;

    for (i = 0; i < STAR_COUNT; i++) {
        task = CreateElementalTask(TASK_WORK, 5, CrashStar);
        if (task == NULL) {
            break;
        }
        roll = rand() * RAND_SCALE;
        work = task->work;
        work->ang.y = (Uint32)(roll * STAR_HEADINGS) << 11;
        /* @hack spelling: ang.x taken from the field as it stands, in two
         * statements, which loads the loop's 0 into R13 ahead of its 6 in R10
         * (0x8c047500, 0x8c047504); in one expression, 15 of 102 words
         * differ */
        work->ang.x = (Uint32)(roll * STAR_TILT) & 0x3fff;
        work->ang.x = 0x10000 - work->ang.x;
        work->tick = (Uint8)(roll * 64.0F) & 1;
        work->pos = from->pos;
    }
}
void crash_star_draw(struct task *task);
extern int ChkPause(void);

void CrashStar(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case STAR_START:
        work->mode = STAR_FLY;
        task->draw = crash_star_draw;
        break;
    case STAR_FLY:
        crash_star_fly(work);
        break;
    case STAR_END:
        /* @hack redundant: the call in a loop of one pass, as in
         * crash_stars_step, which keeps it a JSR (STS.L PR,@-R15 at
         * 0x8c047602); alone, it becomes a tail jump, the function runs 6
         * bytes short and 24 of 25 words differ */
        do {
            FreeTask(task);
        } while (0);
        break;
    }
}
void crash_star_draw(struct task *task)
{
    crash_star_fly(task->work);
}

void crash_star_fly(struct task_work *work)
{
    NJS_VECTOR ahead;
    NJS_VECTOR move;
    if (!ChkPause()) {
        if ((*(Uint16 *)&(work)->timer)++ >= 10) {
            work->mode = STAR_END;
            return;
        }
    }
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, camera_twp->ang.y);
    TURN(njRotateZ, work->ang.z);
    if (work->tick & 1) {
        late_DrawObjectClip(&star_yellow_object);
    } else {
        late_DrawObjectClip(&star_orange_object);
    }
    late_DrawObjectClipEx(1);
    ahead.x = STAR_SPEED;
    ahead.z = 0.0F;
    ahead.y = 0.0F;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njCalcVector(NULL, &ahead, &move);
    late_DrawObjectClipEx(1);
    /* @hack spelling: the sums spelled out, which read move.y from the frame
     * with FMOV.S @(R0,R15),FR3 (0x8c04771a to 0x8c04771e); with +=, SHC
     * forms the address first, the function runs 6 bytes long and 25 of 122
     * words differ */
    if (!ChkPause()) {
        work->pos.x = work->pos.x + move.x;
        work->pos.y = work->pos.y + move.y;
        work->pos.z = work->pos.z + move.z;
        work->ang.z += NJM_DEG_ANG(22.5);
    }
}
