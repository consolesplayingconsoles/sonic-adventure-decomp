/* @unit 0C90A620-0C90A800 +r04 +egflags +pool32 +poolafter=InitStartDushCheck */
/* the race's splits and lap times, the save's best, and the start boost */
#include <sg_xpt.h>
#include <shinobi.h>

#include "hud/hud.h"
#include "minicart/cart_time.h"
#include "minicart/e_cart.h"
#include "minicart/race.h"
#include "minicart/times.h"
#include "save/minigame.h"
#include "save/save.h"
#include "system/pad.h"
#include "system/task.h"
void pdExecPeripheralServerUser(void);
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
void WakeTimer(void);
void SleepTimer(void);
void DrawSNumbers(struct hud_number *number);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void InitSnatchPlayerInfo(void);
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);
struct task *CartRaceSetManageTask(void);
void CartRaceDestroyManageTask(void);
Bool CartRacePrepareRace(void);
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
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);

#define CART_LAPS 3

#define BOOST_STEPS 60

void setDashParam(struct task *task);
void startDushCheck(struct task *task);
extern int cart_splits[3];
extern int cart_laps[3];
extern int boost_press;
extern Float boost;

/* give the cart the boost each step until the timer passes BOOST_STEPS, then
 * destroy the task */
void setDashParam(struct task *task)
{
    SetCartBonusAdd(boost);
    if (TASK_TIMER(task->work)++ > BOOST_STEPS) {
        FreeTask(task);
    }
}

/* note each press of A by player 0. once the race goes, the last press
 * earns a boost if it came at most 2 steps before. the later the press, the
 * bigger the boost and the cart's afterimages. then the task holds the
 * boost */
void startDushCheck(struct task *task)
{
    if (per[0]->press & (1 << 2)) {
        boost_press = GetGlobalTime();
    }
    if (CartRaceGetMode() == RACE_GO) {
        boost_press = GetGlobalTime() - boost_press;
        switch (boost_press) {
        case 0:
            boost = 0.1F;
            MakeEgo(0.3F);
            break;
        case 1:
            boost = 0.06F;
            MakeEgo(0.2F);
            break;
        case 2:
            boost = 0.03F;
            MakeEgo(0.1F);
            break;
        default:
            boost = 0.0F;
            break;
        }
        task->step = setDashParam;
    }
}

void InitStartDushCheck(void)
{
    CreateElementalTask(TASK_WORK, 3, startDushCheck);
    boost_press = 0;
}
struct cart_time cart_get_time(void);
struct cart_time cart_get_split(Sint8 lap);
struct cart_time cart_get_lap(Sint8 lap);
int cart_best_time(void)
{
    return cart_best_split(3 - 1);
}

/* the save keeps the best time, the best run's last split, in time[0]. that
 * run's first two splits follow the save's best times. each field is clamped
 * to its range */
int cart_best_split(Sint8 lap)
{
    struct save_cart_times times;
    struct save_time *time;
    int minutes;
    int seconds;
    int hundredths;
    int value;

    cart_copy_times(&times);
    if (lap == CART_LAPS - 1) {
        time = &times.time[0];
    } else {
        /* @hack type: the splits reached as an array of their own at
         * &times.time[SAVE_BEST], which adds lap's offset to that address
         * (ADD #13,R3 at 0x0c90a788); as &times.time[SAVE_BEST + lap], SHC
         * adds the 9 bytes after, cart_best_split is 2 bytes longer and 43
         * of 62 words differ */
        time = &(*(struct save_time(*)[SAVE_CART_SPLITS]) &
                 times.time[SAVE_BEST])[lap];
    }
    minutes = (int)time->minutes;
    if (minutes < 0) {
        minutes = 0;
    } else if (minutes >= 100) {
        minutes = 99;
    }
    seconds = (int)time->seconds;
    if (seconds < 0) {
        seconds = 0;
    } else if (seconds >= 60) {
        seconds = 59;
    }
    hundredths = (int)time->frames;
    if (hundredths < 0) {
        hundredths = 0;
    } else if (hundredths >= 100) {
        hundredths = 99;
    }
    value = (((minutes * 60) + seconds) * 100) + hundredths;
    return value;
}

void CartStateIntrptToCentiSec(Sint8 lap, int time)
{
    cart_splits[lap] = time;
}

void CartDataSetSubTotalTime(Sint8 lap, int time)
{
    cart_laps[lap] = time;
}
