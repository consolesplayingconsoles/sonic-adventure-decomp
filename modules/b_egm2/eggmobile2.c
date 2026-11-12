/* @unit 0C9072E0-0C9073E0 +r04 +egflags +pool32 */
/* the Egg Walker's stage: the steps of its stage task and its sky task */
#include <ninja.h>

#include "adv00/station_square.h"
#include "b_egm2/egg_walker.h"
#include "b_egm2/eggmobile2.h"
#include "draw/light.h"
#include "hud/boss_name.h"
#include "hud/hud.h"
#include "player/player.h"
#include "sound/stream.h"
#include "stage/stage.h"
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
extern Sint8 chaos_reqmode;
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
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
void ADX_Close(void);
void BGM_Play(int music);
Bool CameraFishingCatch(void);
void ADXTaskInit(void);
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
Bool ChkPause(void);

#define BOUND_X_MIN (-515.0F)
#define BOUND_X_MAX (-375.0F)
#define BOUND_Y_MIN (-3.0F)
#define BOUND_Y_MAX 45.0F
#define BOUND_Z_MIN 930.0F
#define BOUND_Z_MAX 1480.0F
#define BACK_COLOR 0x1e
enum eggmobile2_mode {
    EGGMOBILE2_START,
    EGGMOBILE2_LOAD,
    EGGMOBILE2_FIGHT,
    EGGMOBILE2_IDLE
};

/* the sky task's work->mode. SKY_RESET starts the sky over. a mode past it
 * passes the task to heap_free */
enum sky_mode { SKY_START, SKY_RUN, SKY_RESET };
extern const char eggmobile2_boss_name[11];

void eggmobile2_fight_start(struct task *task);
void Rd_Bossegm2(void);
void eggmobile2_step(struct task *task);
void eggmobile2_fight_start(struct task *task)
{
    struct task_work *work = task->work;
    GetStageNumber();
    egg_walker_create();
    SetDisplayBossName(eggmobile2_boss_name, -1, 240, 120);
    work->mode = EGGMOBILE2_FIGHT;
}

void Rd_Bossegm2(void)
{
    if (playertwp[0]->pos.z < BOUND_Z_MIN) {
        playertwp[0]->pos.z = BOUND_Z_MIN;
    } else if (playertwp[0]->pos.z > BOUND_Z_MAX) {
        playertwp[0]->pos.z = BOUND_Z_MAX;
    }
    if (playertwp[0]->pos.x < BOUND_X_MIN) {
        playertwp[0]->pos.x = BOUND_X_MIN;
    } else if (playertwp[0]->pos.x > BOUND_X_MAX) {
        playertwp[0]->pos.x = BOUND_X_MAX;
    }
    if (playertwp[0]->pos.y < BOUND_Y_MIN) {
        playertwp[0]->pos.y = BOUND_Y_MIN;
    } else if (playertwp[0]->pos.y > BOUND_Y_MAX) {
        playertwp[0]->pos.y = BOUND_Y_MAX;
    }
}
void eggmobile2_sky_step(struct task *task);
