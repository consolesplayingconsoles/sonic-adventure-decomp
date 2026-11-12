/* @unit 0CB98020-0CB98110 +r04 +egflags */
/* the Chao race's stage task, which creates the game, steps it in the hall
 * and on the course, and changes act when the game asks */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_race/game.h"
#include "al_race/race.h"
#include "chao/chao.h"
#include "player/player.h"
#include "sound/cue.h"
#include "sound/stream.h"
#include "stage/act.h"
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
void AddExtraDisplay(Sint8 kind);
void ExtraDisplayInit(void);
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

/* the stage task's vars: the game alife_race_start creates */
#define VARS(work) ((struct race_vars *)&(work)->vars)
#define HALL_FLOOR (-600.0F)
#define MUSIC_WAIT 10
struct race_vars {
    Uint8 unk_00[8];
    struct race_game *game;
};

/* the stage task's modes. RACE_INIT creates the game, and RACE_RUN steps
 * it. RACE_END changes act, and RACE_WAIT then waits a step before RACE_RUN */
enum race_mode { RACE_INIT, RACE_WAIT, RACE_RUN, RACE_END };

/* in the hall, player 0 falls out of the stage below this height */

/* music_start_later's wait before the hall's music starts, counted down by
 * each step and each draw */

void alife_race_start(struct task *task);
void alife_race_run(struct task *task);
void alife_race_end(struct task *task);
void alife_race_destroy(struct task *task);
void alife_race_step(struct task *task);
void alife_race_start(struct task *task)
{
    struct task_work *work = task->work;
    chao_gardens_init();
    ((struct race_vars *)&(work)->vars)->game = race_game_create();
    if (((struct race_vars *)&(work)->vars)->game == ((void *)0)) {
    }
    work->mode = RACE_RUN;
    task->destructor = alife_race_destroy;
    music_start_later(MUSIC_CHAOHALL, 10);
}

void alife_race_run(struct task *task)
{
    struct task_work *work = task->work;
    Uint32 stage_act;
    struct task_work *player;

    if (race_game_step(VARS(work)->game)) {
        work->mode = RACE_END;
    }
    stage_act = GetStageNumber();
    if ((Uint8)stage_act == ACT_HALL) {
        player = playertwp[0];
        if (player != NULL && player->pos.y < HALL_FLOOR) {
            music_end();
            player_fall(0);
        }
    }
}

void alife_race_end(struct task *task)
{
    struct task_work *work = task->work;
    Uint32 stage_act;

    work->mode = RACE_WAIT;
    stage_act = GetStageNumber();
    switch ((Uint8)stage_act) {
    case ACT_HALL:
        act_change(1, MUSIC_CHAORACE);
        break;
    case ACT_COURSE:
        act_change(-1, -1);
        break;
    }
}

void alife_race_destroy(struct task *task)
{
    struct task_work *work = task->work;

    race_game_free(VARS(work)->game);
}
