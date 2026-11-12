/* @unit 0C90B800-0C90B900 +r04 +egflags +pool32 */
/* door below the station, whose two panels slide apart and back together as
 * FLAG_STATION_DOOR says */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv02/station_door.h"
#include "adv02/texlists.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "progress/progress.h"
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
Bool OnEdit(struct task *task);
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

/* @hack type: the four objects declared as arrays, and read through ->. SHC
 * then loads each object's address and reads its fields past it, as the door's
 * model at 0x0c90bd0e (MOV.L @(4,R4),R4). as NJS_OBJECTs read through ., 63 of
 * station_door_draw's 90 words differ */
#define DOOR_X 441.776F
#define DOOR_Y (-319.1976F)
#define DOOR_Z 896.727F
#define OPEN_TRAVEL 40.0F
#define SPEED_UP 0.03F
#define TOP_SPEED 0.5F
#define SLOW_DOWN 0.06F
#define LOW_SPEED 0.05F
#define OPENING_BRAKE 0.6F
#define SHUTTING_BRAKE 0.4F
#define VARS(work) ((struct station_door_vars *)&(work)->vars)
extern NJS_OBJECT station_door_object[];
extern NJS_OBJECT station_door_middle_object[];
extern NJS_OBJECT station_door_left_object[];
extern NJS_OBJECT station_door_right_object[];

/* how far each panel slides out from shut */
/* a moving panel speeds up by SPEED_UP a step, up to TOP_SPEED. once it
 * brakes, it slows down by SLOW_DOWN a step, to no less than LOW_SPEED */
/* an opening panel brakes once it is OPENING_BRAKE of OPEN_TRAVEL out from
 * shut, and a shutting one once it is SHUTTING_BRAKE out */

enum station_door_mode { DOOR_INIT, DOOR_RUN };

struct station_door_vars {
    Float speed; /* the panels' speed a step, below 0 while they shut */
    Float travel; /* how far each panel has slid out from shut */
};

static void station_door_init(struct task *task);
static void station_door_update(struct task *task);
void station_door_draw(struct task *task);
void station_door_destroy(struct task *task);
void station_door_step(struct task *task);

static void station_door_init(struct task *task)
{
    struct task_work *work = task->work;

    work->pos.x = DOOR_X;
    work->pos.y = DOOR_Y;
    work->pos.z = DOOR_Z;
    task->draw = station_door_draw;
    task->destructor = station_door_destroy;
    VARS(work)->travel = 0.0F;
    VARS(work)->speed = 0.0F;
    work->mode = DOOR_RUN;
}

static void station_door_update(struct task *task)
{
    struct task_work *work = task->work;

    switch (seqVars[FLAG_STATION_DOOR]) {
    case STATION_DOOR_SHUT:
        VARS(work)->travel = 0.0F;
        VARS(work)->speed = 0.0F;
        break;
    case STATION_DOOR_SHUTTING:
        if (VARS(work)->travel > OPEN_TRAVEL * SHUTTING_BRAKE) {
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
        break;
    case STATION_DOOR_OPEN:
        VARS(work)->travel = OPEN_TRAVEL;
        VARS(work)->speed = 0.0F;
        break;
    case STATION_DOOR_OPENING:
        if (VARS(work)->travel < OPEN_TRAVEL * OPENING_BRAKE) {
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
        break;
    }
    VARS(work)->travel += VARS(work)->speed;
    if (VARS(work)->travel < 0.0F) {
        VARS(work)->travel = 0.0F;
    } else if (VARS(work)->travel > OPEN_TRAVEL) {
        VARS(work)->travel = OPEN_TRAVEL;
    }
}

void station_door_draw(struct task *task)
{
    struct task_work *work = task->work;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    njSetTexture_jp(&mrobj_texlist);
    ds_DrawModelClip(station_door_object->model);
    njPushMatrix(NULL);
    njTranslate(NULL, station_door_middle_object->pos[0],
                station_door_middle_object->pos[1],
                station_door_middle_object->pos[2]);
    ds_DrawModelClip(station_door_middle_object->model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, station_door_left_object->pos[0] - VARS(work)->travel,
                station_door_left_object->pos[1],
                station_door_left_object->pos[2]);
    ds_DrawModelClip(station_door_left_object->model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, station_door_right_object->pos[0] + VARS(work)->travel,
                station_door_right_object->pos[1],
                station_door_right_object->pos[2]);
    ds_DrawModelClip(station_door_right_object->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

void station_door_destroy(struct task *task)
{
}
