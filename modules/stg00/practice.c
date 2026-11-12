/* @unit 0C900D00-0C900E00 +r04 +egflags +pool32 */
/* the stage task of the Hedgehog Hammer, STAGE_PRACTICE. it sets up the act
 * the stage starts in, and each act it changes to */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/light.h"
#include "hud/hud.h"
#include "player/player.h"
#include "sound/stream.h"
#include "stage/stage.h"
#include "stg00/practice.h"
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
Bool light_read_disc_palettes(Uint16 stage, int act);
Bool FUN_8c014308(Uint16 stage, int act);
void FUN_8c089fbc(void);
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
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
void SetVelocityAndRotationAndNoconTimeWithSpinDashP(Uint8 player,
                                                     NJS_VECTOR *speed,
                                                     const Angle *ang,
                                                     Sint16 steps);
void SetPositionP(Uint8 player, Float x, Float y, Float z);
Bool GetPlayerPosition(Uint8 player, int steps, NJS_POINT3 *pos,
                       struct angles *ang);
void FUN_8c1077a4(struct task *task);
void ADX_Close(void);
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
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

/* the act the task last set up, kept in the work's timer */
#define PRACTICE_ACT(work) TASK_TIMER(work)

/* the stage task's modes, in work->mode */
#define LIGHT_STAGE STAGE_EGG_CARRIER_INSIDE
#define LIGHT_ACT 2
#define MUSIC_DELAY 10
enum practice_mode {
    PRACTICE_INIT,
    PRACTICE_START,
    PRACTICE_RUN,
    PRACTICE_END
};

/* the stage and act whose light sources and palettes each act reads from
 * the disc */

/* the steps the music task waits. it asks for MUSIC_HAMMER on the step after
 * them */

void RdActInit(struct task *task);
void practice_destroy(struct task *task);
void ec_bgmcontrol(struct task *task);

/* the step of the act in progress, which does nothing */
static void practice_act_step(struct task *task)
{
    /* @hack redundant: a read of the work, which keeps the task passed in, MOV
     * R13,R4 at 0x0c900054, where SHC expands the step in practice_step;
     * without it, 34 of 49 words differ */
    (void)task->work;
}
void practice_step(struct task *task);
void RdActInit(struct task *task)
{
    struct task_work *work = task->work;
    struct task *music;
    (*(Uint16 *)&(work)->timer) = (Uint8)GetStageNumber();
    SetInputP(0, 24);
    player_set_speed(0, 0.0F, 0.0F, 0.0F);
    njSetBackColor_jp(0, 0, 0);
    music = CreateElementalTask(0x2, 0, ec_bgmcontrol);
    music->work->mode = MUSIC_HAMMER;
    music->work->timer = 10;
    light_read_disc_palettes(32, 2);
    FUN_8c014308(32, 2);
    FUN_8c089fbc();
    pause_enable();
}

void practice_destroy(struct task *task)
{
}

/* count down work->timer. once it falls below 0, start the streams' task
 * and ask for the music work->mode names. the task then destroys itself */
void ec_bgmcontrol(struct task *task)
{
    struct task_work *work = task->work;

    work->timer--;
    if (work->timer < 0) {
        CreateElementalTask(0, 1, FUN_8c1077a4);
        BGM_Play(work->mode);
        DestroyTask(task);
    }
}
