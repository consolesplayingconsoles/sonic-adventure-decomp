/* @unit 0C900000-0C9006C0 @data 0C909400-0C909424 +r04 +egflags +pool32 */
/* the sky chase's camera steps. they look along the course's path, trail
 * the tornado, or swing round a target */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "player/player.h"
#include "shooting/camera.h"
#include "shooting/shooting.h"
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
extern struct task_work *camera_twp;
void InitCartGoalCamFunc(struct camera_view *view);
void FUN_8c01aae0(Sint16 mode, Uint8 adjust);
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
void FUN_0c90009a(struct camera_view *view);
Bool StageEventCheck(void);
void pdExecPeripheralServerUser(void);
extern PDS_PERIPHERAL perG[8];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
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
extern Float shooting_camera_distance;
extern Angle shooting_camera_ang_x;
extern Angle shooting_camera_ang_y;
extern Angle shooting_camera_ang_z;
extern Float shooting_camera_offset_x;
extern Float shooting_camera_offset_y;
extern Float shooting_camera_offset_z;
extern int shooting_camera_behind;
extern int shooting_camera_ahead;
extern int watch_point;
extern Angle swing_turned;
extern Angle swing_turn;
extern struct task_work *swing_work;
extern Float swing_height;
extern Float swing_distance;
extern Float swing_near;
extern Float swing_close_step;
extern Sint8 swing_done;
extern Sint8 swing_phase;
extern NJS_POINT3 swing_target;
extern Angle swing_heading;

/* shooting_camera_start puts the watch point WATCH_BEHIND path points
 * behind the tornado's */
#define WATCH_BEHIND 10
/* shooting_camera_look_back sits LOOK_BACK_AHEAD path points ahead of the
 * tornado's, and looks at the point LOOK_BACK_BEHIND behind it */
#define LOOK_BACK_AHEAD 7
#define LOOK_BACK_BEHIND 15
/* a swing starts SWING_FAR times its distance away and closes in over
 * SWING_CLOSE_STEPS */
#define SWING_FAR 4.0F
#define SWING_CLOSE_STEPS 120.0F

/* the trailing camera's distance and angles, and its offset from its point
 * on the path */

/* swing_phase's values: the swing closes in, then turns, then holds its
 * distance and heading once round */
enum swing_phase { SWING_CLOSING, SWING_TURNING, SWING_ROUND };

void shooting_camera_watch(struct camera_view *view)
{
    /* @hack redundant: offset, set and never read. its initializer keeps
     * the image's copy of {0, 0, 80} into the stack at R15+12 (0x0c900002 to
     * 0x0c900014); without it, the constants run 12 bytes short, and 75 of
     * 77 words differ */
    NJS_VECTOR offset = {0.0F, 0.0F, 80.0F};
    /* @hack redundant: turned, 12 bytes of stack no instruction reads or
     * writes, of the 24 that ADD #-24,R15 at 0x0c900000 makes; without it,
     * 75 of 77 words differ */
    NJS_POINT3 turned;
    int behind;

    /* @hack redundant: behind, set and clamped but never read (ADD #-10,R4
     * at 0x0c90001c, CMP/GE at 0x0c90001e, CMP/PZ at 0x0c900026); without
     * it, 72 of 77 words differ */
    behind = shooting_path_index - WATCH_BEHIND;
    if (behind >= shooting_path_count) {
        behind = 0;
    }
    if (behind < 0) {
        behind = 0;
    }
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y = playertwp[0]->pos.y;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    cameraControlWork->pos.x = shooting_path[watch_point].x;
    cameraControlWork->pos.y = shooting_path[watch_point].y;
    cameraControlWork->pos.z = shooting_path[watch_point].z;
}

void FUN_0c90009a(struct camera_view *view)
{
    /* @hack redundant: offset, set and never read. its initializer keeps
     * the image's copy of {0, 0, 10} into the stack at R15+12 (0x0c9000a2 to
     * 0x0c9000b4); without it, the constants run 12 bytes short, and 105 of
     * 109 words differ */
    NJS_VECTOR offset = {0.0F, 0.0F, 10.0F};
    /* @hack redundant: turned, 12 bytes of stack no instruction reads or
     * writes, of the 24 that ADD #-24,R15 at 0x0c9000a0 makes; without it,
     * 104 of 109 words differ */
    NJS_POINT3 turned;
    int behind;
    int ahead;
    struct task *player;
    /* work is the dead store tagged below */
    /* NOLINTNEXTLINE(clang-diagnostic-unused-but-set-variable) */
    struct task_work *work;

    behind = shooting_path_index - LOOK_BACK_BEHIND;
    if (behind >= shooting_path_count) {
        behind = 0;
    }
    ahead = shooting_path_index + LOOK_BACK_AHEAD;
    if (ahead >= shooting_path_count) {
        ahead = 0;
    }
    if (ahead < 0) {
        ahead = 0;
    }
    player = GetPlayerTaskPointer(0);
    /* @hack redundant: work, set and never read, for which SHC copies
     * player into R4 (MOV R0,R4 at 0x0c9000ec); without it, 65 of 109 words
     * differ */
    work = player->work;
    cameraControlWork->target.x = shooting_path[behind].x;
    cameraControlWork->target.y = shooting_path[behind].y;
    cameraControlWork->target.z = shooting_path[behind].z;
    cameraControlWork->pos.x = shooting_path[ahead].x;
    cameraControlWork->pos.y = shooting_path[ahead].y;
    cameraControlWork->pos.z = shooting_path[ahead].z;
    cameraControlWork->distance = shooting_camera_distance;
    cameraControlWork->ang_x = shooting_camera_ang_x;
    cameraControlWork->ang_y = shooting_camera_ang_y;
    cameraControlWork->ang_z = shooting_camera_ang_z;
}

/* the camera sits shooting_camera_behind path points behind the tornado's
 * point, moved by its offset. its target is the point shooting_camera_ahead
 * past the tornado's. half the tornado's offset from the path moves the
 * target, turned as the tornado turns */
void CameraBack2(struct camera_view *view)
{
    NJS_VECTOR offset = {0.0F, 0.0F, 10.0F};
    NJS_POINT3 turned;
    int ahead;
    int behind;
    struct task *player;
    struct task_work *work;

    ahead = shooting_path_index + shooting_camera_ahead;
    if (ahead >= shooting_path_count) {
        ahead = 0;
    }
    behind = shooting_path_index - shooting_camera_behind;
    if (behind >= shooting_path_count) {
        behind = 0;
    }
    if (behind < 0) {
        behind = 0;
    }
    player = GetPlayerTaskPointer(0);
    work = player->work;
    offset.x = shooting_flight.offset.x * 0.5F;
    offset.y = shooting_flight.offset.y * 0.5F;
    offset.z = shooting_flight.offset.z * 0.5F;
    njPushMatrix(&nj_unit_matrix_);
    njRotateXYZ(NULL, work->ang.x, work->ang.y, work->ang.z);
    njRotateXYZ(NULL, shooting_flight.ang.x, shooting_flight.ang.y,
                shooting_flight.ang.z);
    njCalcPoint(NULL, &offset, &turned);
    late_DrawObjectClipEx(1);
    cameraControlWork->target.x = shooting_path[ahead].x + turned.x;
    cameraControlWork->target.y = shooting_path[ahead].y + turned.y;
    cameraControlWork->target.z = shooting_path[ahead].z + turned.z;
    cameraControlWork->pos.x =
        shooting_path[behind].x + shooting_camera_offset_x;
    cameraControlWork->pos.y =
        shooting_path[behind].y + shooting_camera_offset_y;
    cameraControlWork->pos.z =
        shooting_path[behind].z + shooting_camera_offset_z;
    cameraControlWork->distance = shooting_camera_distance;
    cameraControlWork->ang_x = shooting_camera_ang_x;
    cameraControlWork->ang_y = shooting_camera_ang_y;
    cameraControlWork->ang_z = shooting_camera_ang_z;
}

void shooting_camera_start(void)
{
    int point;

    /* @hack spelling: the store and the copy joined by a comma, which keeps
     * watch_point's address in R5 while point takes R4 (0x0c900320,
     * 0x0c90032a). as two statements, the address takes R4, and 9 of 14
     * words differ */
    watch_point = shooting_path_index - WATCH_BEHIND, point = watch_point;
    /* @hack redundant: two tests of point with empty bodies, the image's CMP/GE
     * and CMP/PZ at 0x0c900332 and 0x0c900334; without them, 13 of 14 words
     * differ */
    if (point >= shooting_path_count) {
    }
    if (point < 0) {
    }
    FUN_8c01aae0(68, 3);
}

void CameraBackInit(int spacing)
{
    switch (spacing) {
    case 0:
        shooting_camera_behind = 10;
        shooting_camera_ahead = 10;
        break;
    case 1:
        shooting_camera_behind = 10;
        shooting_camera_ahead = 5;
        break;
    }
}

/* set out to the point distance from camera_state's target, in the
 * direction of camera_state's y angle */
void sht_CalcTargetPos(Float distance, NJS_POINT3 *out)
{
    NJS_POINT3 point;
    Angle ang;

    point.x = 0.0F;
    point.y = 0.0F;
    point.z = distance;
    njPushMatrix(&nj_unit_matrix_);
    TURN_VIA(njRotateY, cameraControlWork->ang_y, ang);
    njCalcPoint(NULL, &point, out);
    late_DrawObjectClipEx(1);
    njAddVector(out, &cameraControlWork->target);
}

void shooting_camera_swing(struct camera_view *view)
{
    switch (swing_phase) {
    case SWING_CLOSING:
        swing_target.x = cameraControlWork->target.x = swing_work->pos.x;
        swing_target.y = cameraControlWork->target.y =
            swing_work->pos.y + swing_height;
        swing_target.z = cameraControlWork->target.z = swing_work->pos.z;
        swing_distance += swing_close_step;
        if (swing_distance <= swing_near) {
            swing_phase = SWING_TURNING;
        }
        break;
    case SWING_TURNING:
        swing_target.x = cameraControlWork->target.x = swing_work->pos.x;
        swing_target.y = cameraControlWork->target.y =
            swing_work->pos.y + swing_height;
        swing_target.z = cameraControlWork->target.z = swing_work->pos.z;
        swing_heading += swing_turn;
        swing_turned += swing_turn;
        if (swing_turned >= 0x8000) {
            swing_phase = SWING_ROUND;
            swing_done = TRUE;
        }
        break;
    case SWING_ROUND:
        swing_target.x = cameraControlWork->target.x = swing_work->pos.x;
        swing_target.y = cameraControlWork->target.y =
            swing_work->pos.y + swing_height;
        swing_target.z = cameraControlWork->target.z = swing_work->pos.z;
        break;
    }
    cameraControlWork->ang_y = swing_heading;
    cameraControlWork->target.x = swing_target.x;
    cameraControlWork->target.y = swing_target.y;
    cameraControlWork->target.z = swing_target.z;
    sht_CalcTargetPos(swing_distance, &cameraControlWork->pos);
}

void CameraShtEventInit(struct task_work *work, Float height, Float distance,
                        int swing_steps)
{
    swing_done = FALSE;
    swing_work = work;
    swing_height = height;
    swing_near = distance;
    swing_distance = distance * SWING_FAR;
    swing_close_step =
        (swing_near - swing_distance) * (1.0F / SWING_CLOSE_STEPS);
    swing_target.x = cameraControlWork->target.x = swing_work->pos.x;
    swing_target.y = cameraControlWork->target.y = swing_work->pos.y + height;
    swing_target.z = cameraControlWork->target.z = swing_work->pos.z;
    swing_turn = (Angle)(180.0F / swing_steps * ANGLE_PER_DEGREE);
    cameraControlWork->ang_x = cameraControlWork->ang_z = 0;
    swing_heading = cameraControlWork->ang_y = work->ang.y + 0x8000;
    swing_turned = 0;
    sht_CalcTargetPos(swing_distance, &cameraControlWork->pos);
    swing_phase = SWING_CLOSING;
    PadReadOff();
}
