/* @unit 8C010400-8C010B00 +jpflags +pool32 */
/* requests between the game and the development host, which reads and
 * writes the game's memory while it runs */
#include <kamui.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "debug/editor.h"
#include "debug/host.h"
#include "player/player.h"
#include "system/loader.h"
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
Bool OnEdit(struct task *task);
void FUN_8c010a3e(Sint32 word0, Sint32 word1, Sint32 word2);
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
int thunk_FUN_8c09cbc0(char *name, void *dest);

/* what the development host asks of the game, in host_request.code */
#define CAPTURE_BMP ((char *)WORK_AREA)
#define CAPTURE_BUFFER ((char *)0x0ce00000)
#define REQUEST_ARGS 8
enum host_code {
    HOST_NONE,
    HOST_CAPTURE_SCREEN,
    HOST_RESTORE_SNAPSHOT,
    HOST_SAVE_EDITOR,
    HOST_RESTORE_EDITOR
};

/* what the game asks of the host, in game_request.code */
enum game_code {
    GAME_NONE,
    GAME_LOAD_FILE,
    GAME_SAVE_FILE,
    GAME_REQUEST_3,
    GAME_REQUEST_4
};

/* host_capture_screen has njFrameBufferBmp read the shown frame into
 * CAPTURE_BUFFER and write it as a 24-bit BMP at CAPTURE_BMP. both lie in
 * WORK_AREA */

/* a request: its maker sets code and args, then pending, and whoever
 * serves it clears pending when it is done */
struct host_request {
    Sint32 code;
    Sint32 args[REQUEST_ARGS]; /* the result comes back in args[0] */
    Bool pending;
};

struct snapshot_place {
    Float pos[3];
    Sint32 ang[3];
};

struct snapshot {
    struct snapshot_place camera;
    struct snapshot_place players[PLAYER_COUNT];
    Sint32 unk_d8;
    Sint32 unk_dc;
    Sint32 unk_e0;
};

/* the set editor's kind and cursor, which HOST_SAVE_EDITOR copies out for
 * the host and HOST_RESTORE_EDITOR copies back while the editor is open */
struct editor_snapshot {
    Uint16 kind;
    Sint16 ang_x, ang_y, ang_z;
    NJS_POINT3 pos;
    NJS_POINT3 scl;
};

static void host_take_snapshot(void);
static void host_restore_snapshot(void);
static void host_save_editor(void);
static void host_restore_editor(void);
static void host_capture_screen(void);
extern volatile struct host_request host_request;
extern volatile struct host_request game_request;
extern volatile struct snapshot snapshot_out;
extern volatile struct snapshot snapshot_in;
extern volatile struct editor_snapshot editor_snapshot;

static void host_take_snapshot(void)
{
    struct task *task;
    struct task_work *work;
    int i;

    snapshot_out.camera.pos[0] = camera_twp->pos.x;
    snapshot_out.camera.pos[1] = camera_twp->pos.y;
    snapshot_out.camera.pos[2] = camera_twp->pos.z;
    snapshot_out.camera.ang[0] = camera_twp->ang.x;
    snapshot_out.camera.ang[1] = camera_twp->ang.y;
    snapshot_out.camera.ang[2] = camera_twp->ang.z;
    for (i = 0; i < PLAYER_COUNT; i++) {
        task = GetPlayerTaskPointer(i);
        if (task != NULL) {
            work = task->work;
            snapshot_out.players[i].pos[0] = work->pos.x;
            snapshot_out.players[i].pos[1] = work->pos.y;
            snapshot_out.players[i].pos[2] = work->pos.z;
            snapshot_out.players[i].ang[0] = work->ang.x;
            snapshot_out.players[i].ang[1] = work->ang.y;
            snapshot_out.players[i].ang[2] = work->ang.z;
        } else {
            snapshot_out.players[i].pos[0] = 0.0F;
            snapshot_out.players[i].pos[1] = 0.0F;
            snapshot_out.players[i].pos[2] = 0.0F;
            snapshot_out.players[i].ang[0] = 0;
            snapshot_out.players[i].ang[1] = 0;
            snapshot_out.players[i].ang[2] = 0;
        }
    }
}

static void host_restore_snapshot(void)
{
    struct task *task;
    struct task_work *work;
    int i;

    camera_twp->pos.x = snapshot_in.camera.pos[0];
    camera_twp->pos.y = snapshot_in.camera.pos[1];
    camera_twp->pos.z = snapshot_in.camera.pos[2];
    camera_twp->ang.x = snapshot_in.camera.ang[0];
    camera_twp->ang.y = snapshot_in.camera.ang[1];
    camera_twp->ang.z = snapshot_in.camera.ang[2];
    for (i = 0; i < PLAYER_COUNT; i++) {
        task = GetPlayerTaskPointer(i);
        if (task != NULL) {
            work = task->work;
            work->pos.x = snapshot_in.players[i].pos[0];
            work->pos.y = snapshot_in.players[i].pos[1];
            work->pos.z = snapshot_in.players[i].pos[2];
            work->ang.x = snapshot_in.players[i].ang[0];
            work->ang.y = snapshot_in.players[i].ang[1];
            work->ang.z = snapshot_in.players[i].ang[2];
        }
    }
}

static void host_save_editor(void)
{
    if (edit_mode == 1) {
        editor_snapshot.kind = editor_kind;
        editor_snapshot.ang_x = editor_work->ang.x;
        editor_snapshot.ang_y = editor_work->ang.y;
        editor_snapshot.ang_z = editor_work->ang.z;
        editor_snapshot.pos.x = editor_work->pos.x;
        editor_snapshot.pos.y = editor_work->pos.y;
        editor_snapshot.pos.z = editor_work->pos.z;
        editor_snapshot.scl.x = editor_work->scl.x;
        editor_snapshot.scl.y = editor_work->scl.y;
        editor_snapshot.scl.z = editor_work->scl.z;
    }
}

static void host_restore_editor(void)
{
    if (edit_mode == 1) {
        editor_kind = editor_snapshot.kind;
        editor_work->ang.x = editor_snapshot.ang_x;
        editor_work->ang.y = editor_snapshot.ang_y;
        editor_work->ang.z = editor_snapshot.ang_z;
        editor_work->pos.x = editor_snapshot.pos.x;
        editor_work->pos.y = editor_snapshot.pos.y;
        editor_work->pos.z = editor_snapshot.pos.z;
        editor_work->scl.x = editor_snapshot.scl.x;
        editor_work->scl.y = editor_snapshot.scl.y;
        editor_work->scl.z = editor_snapshot.scl.z;
    }
}

static void host_snapshot_step(struct task *task)
{
    host_take_snapshot();
}

void host_snapshot_each_step(struct task *task)
{
    task->step = host_snapshot_step;
}

void host_serve_request(void)
{
    if (host_request.pending) {
        switch (host_request.code) {
        case HOST_NONE:
            break;
        case HOST_CAPTURE_SCREEN:
            host_capture_screen();
            break;
        case HOST_RESTORE_SNAPSHOT:
            host_restore_snapshot();
            break;
        case HOST_SAVE_EDITOR:
            host_save_editor();
            break;
        case HOST_RESTORE_EDITOR:
            host_restore_editor();
            break;
        }
        host_request.pending = FALSE;
    }
}

void host_init(void)
{
    int i;

    host_request.code = HOST_NONE;
    game_request.code = GAME_NONE;
    for (i = 0; i < REQUEST_ARGS; i++) {
        host_request.args[i] = 0;
        game_request.args[i] = 0;
    }
    host_request.pending = FALSE;
    game_request.pending = FALSE;
    snapshot_out.unk_d8 = 0xc3a000;
    snapshot_out.unk_dc = 0;
    snapshot_out.unk_e0 = 0;
    snapshot_in.unk_d8 = 0xc3a000;
    snapshot_in.unk_dc = 0;
    snapshot_in.unk_e0 = 0;
}

Sint32 host_load_file(const char *name, void *dest)
{
    Sint32 result;

    game_request.code = GAME_LOAD_FILE;
    game_request.args[0] = (Sint32)name;
    game_request.args[1] = (Sint32)dest;
    game_request.pending = TRUE;
    do {
        njWaitVSync_jp();
    } while (game_request.pending);
    /* @hack spelling: the answer through a local, which loads its address
     * into R4, not R0 (0x8c010a64); returned directly, 3 of 23 words differ */
    result = game_request.args[0];
    return result;
}

void host_save_file(const char *name, void *src, int size)
{
    game_request.code = GAME_SAVE_FILE;
    game_request.args[0] = (Sint32)name;
    game_request.args[1] = (Sint32)src;
    game_request.args[2] = size;
    game_request.pending = TRUE;
    do {
        njWaitVSync_jp();
    } while (game_request.pending);
}

void FUN_8c010a3e(Sint32 word0, Sint32 word1, Sint32 word2)
{
    game_request.code = GAME_REQUEST_3;
    game_request.args[0] = word0;
    game_request.args[1] = word1;
    game_request.args[2] = word2;
    game_request.pending = TRUE;
    do {
        njWaitVSync_jp();
    } while (game_request.pending);
}

static void host_capture_screen(void)
{
    /* @hack spelling: the bmp's address through a local, which loads
     * CAPTURE_BUFFER into R5 ahead of it into R4 (0x8c010ad2, 0x8c010ad4) and
     * keeps host_serve_request from inlining the function; passed directly,
     * it is inlined and 11 of 11 words differ */
    char *bmp = CAPTURE_BMP;

    njFrameBufferBmp_jp(bmp, CAPTURE_BUFFER);
    kmfSetTimeOutCount(1, 1);
}

Sint32 fun_8c010ae4(Sint32 word)
{
    Sint32 result;

    game_request.code = GAME_REQUEST_4;
    game_request.args[0] = word;
    game_request.pending = TRUE;
    do {
        njWaitVSync_jp();
    } while (game_request.pending);
    /* @hack spelling: the answer through a local, as in host_load_file
     * (0x8c010b06); returned directly, 3 of 22 words differ */
    result = game_request.args[0];
    return result;
}
