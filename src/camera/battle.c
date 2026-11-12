/* @unit 8C048B00-8C0491C0 +r04 +egflags +pool32 +asmfunc=battle_camera_step */
/* the camera in a battle with a rival */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "camera/battle.h"
#include "camera/camera.h"
#include "player/player.h"
#include "player/rival.h"
#include "system/math.h"
#include "system/pad.h"
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
void pdExecPeripheralServerUser(void);
void FUN_8c049160(NJS_POINT3 *pos);
void FUN_8c049172(Angle turn);
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
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
void InitCartGoalCamFunc(struct camera_view *view);
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
Float ghUnitVector(NJS_VECTOR *vector, NJS_VECTOR *out);
Float CalcDistance2(NJS_POINT3 *from, NJS_POINT3 *to);
Uint32 ghBlendColors(Uint32 color, Uint32 by);
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
void *syMalloc_default_malloc(size_t size);
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

/* how far ORBIT moves the camera out or in, and turns it round player 0, in
 * a step. ORBIT_PITCH tilts the orbit about x, a 32nd of a turn */
#define ORBIT_STEP 2.0F
#define ORBIT_TURN 0x200
#define ORBIT_PITCH (-0x800)
/* how far the camera rises above player 0's eyes for each unit of
 * camera_state's distance */
#define RISE 0.06F
/* what camera_start_battle sets turn.x and turn.y to: a 256th of a turn */
#define AIM_TURN 0x100

/* how battle_camera_step places the camera. FACE and BETWEEN aim it from
 * battle_distance beyond player 0, on the side away from the rival, at the
 * point battle_distance past the rival. both distances are in x and z.
 * battle_camera_aim swings the camera toward that aim round player 0, no
 * faster than turn allows */
enum battle_camera_mode {
    BATTLE_CAMERA_ORBIT, /* circling player 0, steered by pad 0 */
    BATTLE_CAMERA_FACE, /* looking at the height of player 0's feet */
    BATTLE_CAMERA_BETWEEN /* looking at the mean height of both players' feet */
};

struct battle_camera {
    Sint8 mode; /* a battle_camera_mode */
    NJS_POINT3 pos;
    NJS_POINT3 target;
    /* y is the camera's height above player 0, and z its distance away */
    NJS_POINT3 offset;
    /* y is the heading from player 0 to pos. x follows the pitch from pos to
     * target, as battle_camera_aim turns it */
    struct angles ang;
    Uint8 unk_34[12];
    /* the most battle_camera_aim turns ang.x and ang.y in a step */
    struct angles turn;
    /* pos and ang as they were before battle_camera_aim's last call */
    NJS_POINT3 last_pos;
    struct angles last_ang;
    struct task *task; /* the task that drives the rival */
    struct task_work *player;
    struct task_work *rival;
};

static void battle_camera_step(struct camera_view *view);
static void battle_camera_aim(struct battle_camera *camera,
                              struct task_work *player,
                              struct task_work *rival);
extern Float battle_distance;
extern struct battle_camera battle_camera;

void camera_start_battle(struct task *task)
{
    struct battle_camera *camera = &battle_camera;
    struct rival *rival = task->extra;
    struct player *record;

    CameraSetEventCameraFunc(battle_camera_step, 0, CAMERA_LOOK_AT);
    fill_bytes(camera, 0, sizeof(*camera));
    camera->mode = BATTLE_CAMERA_BETWEEN;
    camera->task = task;
    camera->turn.x = AIM_TURN;
    camera->turn.y = AIM_TURN;
    /* @hack spelling: record assigned inside the test, which tests R0 and
     * copies it to R4 in the BT/S's slot (0x8c04ba04, 0x8c04ba08); assigned
     * ahead of the test, 78 of 85 words differ */
    if ((record = GetPlayerWorkPointer(0)) != NULL) {
        camera->offset.x = 0.0F;
        camera->offset.y =
            record->consts.eye_height + (cameraControlWork->distance * RISE);
        camera->offset.z = 0.0F;
    } else {
        camera->offset.y = 50.0F;
        camera->offset.z = 50.0F;
    }
    switch (rival->kind) {
    case BATTLE_SONIC_KNUCKLES:
    case BATTLE_KNUCKLES_SONIC:
    case BATTLE_KNUCKLES_TAILS:
        battle_distance = 50.0F;
        break;
    case BATTLE_SONIC_E102:
    case BATTLE_E102_SONIC:
    case BATTLE_E102_TAILS:
        battle_distance = 70.0F;
        break;
    }
}

static void battle_camera_step(struct camera_view *view)
{
    extern Uint16 GetStageNumber(void);
    NJS_VECTOR away;
    struct battle_camera *camera = &battle_camera;
    struct task_work *player;
    struct task_work *rival;
    struct player *record;

    if (camera_twp == NULL || cameraControlWork == NULL) {
        return;
    }
    camera->player = player = playertwp[0];
    camera->rival = rival = playertwp[1];
    record = GetPlayerWorkPointer(0);
    if (player == NULL || rival == NULL || record == NULL) {
        return;
    }
    switch (camera->mode) {
    case BATTLE_CAMERA_ORBIT:
        camera->offset.x = 0.0F;
        camera->offset.y =
            record->consts.eye_height + (cameraControlWork->distance * RISE);
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateY, camera->ang.y);
        njRotateX(NULL, ORBIT_PITCH);
        camera->offset.z = battle_distance;
        njCalcPoint(NULL, &camera->offset, &camera->pos);
        camera->pos.x = player->pos.x + camera->pos.x;
        camera->pos.y = player->pos.y + camera->pos.y;
        camera->pos.z = player->pos.z + camera->pos.z;
        camera->offset.z = -battle_distance;
        njCalcPoint(NULL, &camera->offset, &camera->target);
        camera->target.x = player->pos.x + camera->target.x;
        camera->target.y = player->pos.y + camera->target.y;
        camera->target.z = player->pos.z + camera->target.z;
        late_DrawObjectClipEx(1);
        if (per[0]->on & (1 << 9)) {
            if (per[0]->on & (1 << 17)) {
                battle_distance += 2.0F;
            } else if (per[0]->on & (1 << 16)) {
                battle_distance -= 2.0F;
            }
        } else {
            if (per[0]->on & (1 << 17)) {
                camera->ang.y -= 0x200;
            } else if (per[0]->on & (1 << 16)) {
                camera->ang.y += 0x200;
            }
        }
        break;
    case BATTLE_CAMERA_FACE:
        if (record != NULL) {
            camera->offset.y = record->consts.eye_height +
                               (cameraControlWork->distance * RISE);
            camera->offset.z = battle_distance;
        }
        VECTOR_DIFF(&away, &player->pos, &rival->pos);
        if (vector_magnitude(&away) != 0.0F) {
            vector_unit_across(&away, &away);
            camera->pos.x = player->pos.x + (away.x * camera->offset.z);
            camera->pos.y = player->pos.y + camera->offset.y;
            camera->pos.z = player->pos.z + (away.z * camera->offset.z);
            camera->target.x = rival->pos.x - (away.x * camera->offset.z);
            camera->target.y = camera->pos.y - camera->offset.y;
            camera->target.z = rival->pos.z - (away.z * camera->offset.z);
            /* @hack spelling: the aim called in each arm, which SHC joins
             * into one call of FACE's own (BSR at 0x8c04bd92); as one call
             * after the if, SHC merges it with BETWEEN's, 223 of 463 words
             * differ and the code runs 32 bytes short */
            battle_camera_aim(camera, player, rival);
        } else {
            battle_camera_aim(camera, player, rival);
        }
        break;
    case BATTLE_CAMERA_BETWEEN:
        if (record != NULL) {
            if (PLAYER_VARS(camera->player)->character == CHARACTER_E102) {
                camera->offset.y = record->consts.eye_height +
                                   (cameraControlWork->distance * RISE) + 10.0F;
            } else {
                camera->offset.y = record->consts.eye_height * 3.0F;
            }
            camera->offset.z = battle_distance;
        }
        VECTOR_DIFF(&away, &player->pos, &rival->pos);
        vector_unit_across(&away, &away);
        camera->pos.x = player->pos.x + (away.x * camera->offset.z);
        camera->pos.y = player->pos.y + camera->offset.y;
        camera->pos.z = player->pos.z + (away.z * camera->offset.z);
        camera->target.x = (player->pos.x + rival->pos.x) * 0.5F;
        camera->target.y = (player->pos.y + rival->pos.y) * 0.5F;
        camera->target.z = (player->pos.z + rival->pos.z) * 0.5F;
        battle_camera_aim(camera, player, rival);
        break;
    }
    if (((Uint16)GetStageNumber() & 0xff00) == 0x1d00) {
        if (camera->pos.z > 3560.0F) {
            camera->pos.z = 3560.0F;
        }
        if (camera->pos.z < 3180.0F) {
            camera->pos.z = 3180.0F;
        }
    }
    cameraControlWork->target.x = camera->target.x;
    cameraControlWork->target.y = camera->target.y;
    cameraControlWork->target.z = camera->target.z;
    cameraControlWork->pos.x = camera->pos.x;
    cameraControlWork->pos.y = camera->pos.y;
    cameraControlWork->pos.z = camera->pos.z;
    cameraControlWork->ang_x = cameraControlWork->ang_y =
        cameraControlWork->ang_z = 0;
}

/* swing the camera round player 0 toward the view the caller set. ang.y
 * turns toward the heading from the target to pos, by at most turn.y in a
 * step. ang.x turns toward the pitch from pos to the target, by at most
 * turn.x. pos then moves round player 0 to heading ang.y, keeping its
 * distance in x and z. the target moves in x and z to the opposite heading,
 * as far from player 0 as pos was from the rival */
static void battle_camera_aim(struct battle_camera *camera,
                              struct task_work *player, struct task_work *rival)
{
    /* @hack redundant: 12 bytes of frame that no code reads, of a type unknown,
     * declared as a vector. the image's ADD #-32,R15 reserves them
     * (0x8c04bf4a); without them, 2 of 125 words differ */
    NJS_VECTOR unused;
    Float sine;
    Float cosine;
    Angle pitch;
    Angle heading;
    Float across;
    Float near;
    Float far;

    camera->last_pos = camera->pos;
    camera->last_ang = camera->ang;
    heading = angle_arc_tan2(camera->pos.x - camera->target.x,
                             camera->pos.z - camera->target.z);
    across = point_distance_across(&camera->pos, &camera->target);
    pitch = angle_arc_tan2(camera->target.y - camera->pos.y, across);
    camera->ang.y = AdjustAngle(camera->last_ang.y, heading, camera->turn.y);
    camera->ang.x = AdjustAngle(camera->last_ang.x, pitch, camera->turn.x);
    far = point_distance_across(&camera->pos, &rival->pos);
    near = point_distance_across(&camera->pos, &player->pos);
    _builtin_fsca(camera->ang.y, &sine, &cosine);
    camera->pos.x = player->pos.x + (near * sine);
    camera->pos.z = player->pos.z + (near * cosine);
    camera->target.x = player->pos.x - (sine * far);
    camera->target.z = player->pos.z - (cosine * far);
}

void FUN_8c049160(NJS_POINT3 *pos)
{
    *pos = camera_twp->pos;
}

void FUN_8c049172(Angle turn)
{
    struct battle_camera *camera = &battle_camera;

    camera->turn.y = turn;
}

void camera_keep_battle(void)
{
    CameraSetEventCameraFunc(battle_camera_step, 0, CAMERA_LOOK_AT);
}
