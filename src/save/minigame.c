/* @unit 8C0A19E0-8C0A1E80 @data 8C15B1FC-8C15B224 +egflags +pool32 */
/* minigames: the boards' best scores and the cart's best times */
#include <sg_xpt.h>

#include "minicart/times.h"
#include "player/player.h"
#include "save/card.h"
#include "save/minigame.h"
#include "save/save.h"
#include "stage/stage.h"
int FUN_8c0a1b14(void);
void InitStartDushCheck(void);
void CartStateIntrptToCentiSec(Sint8 lap, int time);
void CartDataSetSubTotalTime(Sint8 lap, int time);
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
void pdExecPeripheralServerUser(void);
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
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

/* the save keeps the boards' scores for Sonic and for Tails */
#define BOARD_PLAYERS 2

/* the cart's acts. the save keeps the first's times, and cart_act_times
 * the others' */
#define CART_ACTS 6

/* a character's default times in an act of the cart: the best three, then
 * the best run's splits. CART_ACT_DEFAULTS holds a set for each character */
#define CART_DEFAULTS                                                          \
    {                                                                          \
        {                                                                      \
            {10, 0, 0}, {15, 0, 0}, {20, 0, 0}, {4, 0, 0}, {7, 0, 0}           \
        }                                                                      \
    }
#define CART_ACT_DEFAULTS                                                      \
    {CART_DEFAULTS, CART_DEFAULTS, CART_DEFAULTS,                              \
     CART_DEFAULTS, CART_DEFAULTS, CART_DEFAULTS}

static struct save_cart_times *cart_find_times(void);
static int minigame_character(void);
static int cart_get_act(void);
extern struct save_cart_times cart_act_times[6 - 1][6];

void board_reset_icecap_scores(struct save *save)
{
    static const struct save_scores defaults = {{9000, 6000, 3000}};
    struct save_scores *scores;
    int i;

    for (i = 0, scores = save->icecap_scores; i < BOARD_PLAYERS;
         i++, scores++) {
        *scores = defaults;
    }
}

void board_reset_sunaboard_scores(struct save *save)
{
    static const struct save_scores defaults = {{10000, 6000, 3000}};
    struct save_scores *scores;
    int i;

    for (i = 0, scores = save->sunaboard_scores; i < BOARD_PLAYERS;
         i++, scores++) {
        *scores = defaults;
    }
}

void cart_reset_times(struct save *save)
{
    static const struct save_cart_times defaults = CART_DEFAULTS;
    struct save_cart_times *times;
    int i;

    for (i = 0, times = save->cart_times; i < SAVE_CHARACTERS; i++, times++) {
        *times = defaults;
    }
}

int FUN_8c0a1b14(void)
{
    /* @hack redundant: register on count, which keeps SAVE_BEST in R13 (MOV
     * #3,R13 at 0x8c0a7ca4); as a plain local, 11 of 59 words differ, and
     * with SAVE_BEST in its place, 11 of 59 too */
    register int count = SAVE_BEST;
    /* @hack redundant: register on rank, which keeps it in R14 (MOV R13,R14
     * at 0x8c0a7cac); without it, 15 of 59 words differ */
    register int rank = count;
    int character = minigame_character();
    int points;
    Sint32 *scores;
    Sint32 *cursor;
    int i;

    if (character < BOARD_PLAYERS) {
        points = score;
        scores = SaveData[save_slot].icecap_scores[character].score;
        for (i = 0, cursor = scores; i < count; i++, cursor++) {
            if (points >= *cursor) {
                break;
            }
        }
        rank = i;
        if (rank < count) {
            for (i = count - 1, cursor = scores + count - 1; i > rank;
                 i--, cursor--) {
                *cursor = cursor[-1];
            }
            *cursor = points;
        }
    }
    return rank;
}

int board_record_sunaboard_score(void)
{
    /* @hack redundant: register on count, which keeps SAVE_BEST in R13 (MOV
     * #3,R13 at 0x8c0a7d44); as a plain local, 11 of 59 words differ */
    register int count = SAVE_BEST;
    /* @hack redundant: register on rank, which keeps it in R14 (MOV R13,R14
     * at 0x8c0a7d4c); without it, 15 of 59 words differ */
    register int rank = count;
    int character = minigame_character();
    int points;
    Sint32 *scores;
    Sint32 *cursor;
    int i;

    if (character < BOARD_PLAYERS) {
        points = score;
        scores = SaveData[save_slot].sunaboard_scores[character].score;
        for (i = 0, cursor = scores; i < count; i++, cursor++) {
            if (points > *cursor) {
                break;
            }
        }
        rank = i;
        if (rank < count) {
            for (i = count - 1, cursor = scores + count - 1; i > rank;
                 i--, cursor--) {
                *cursor = cursor[-1];
            }
            *cursor = points;
        }
    }
    return rank;
}

int cart_record_time(void)
{
    struct cart_time run;
    int run_value;
    struct save_cart_times *times;
    struct save_time *records;
    int rank;
    int i;
    struct save_time *cursor;
    Sint8 lap;
    struct cart_time split;

    run = cart_get_time();
    run_value = (((run.minutes * 60) + run.seconds) * 100) + run.hundredths;
    times = cart_find_times();
    records = times->time;
    for (i = 0, cursor = records; i < SAVE_BEST; i++, cursor++) {
        int value =
            (((cursor->minutes * 60) + cursor->seconds) * 100) + cursor->frames;
        if (run_value <= value) {
            break;
        }
    }
    rank = i;
    if (rank < SAVE_BEST) {
        for (i = SAVE_BEST - 1, cursor = records + SAVE_BEST - 1; i > rank;
             i--, cursor--) {
            *cursor = cursor[-1];
        }
        cursor->minutes = run.minutes;
        cursor->seconds = run.seconds;
        cursor->frames = run.hundredths;
        if (rank == 0) {
            for (lap = 0, cursor = times->time + SAVE_BEST;
                 lap < SAVE_CART_SPLITS; lap++, cursor++) {
                split = cart_get_split(lap);
                cursor->minutes = split.minutes;
                cursor->seconds = split.seconds;
                cursor->frames = split.hundredths;
            }
        }
    }
    return rank;
}

void cart_copy_times(struct save_cart_times *out)
{
    if (out != NULL) {
        struct save_cart_times *times = cart_find_times();

        *out = *times;
    }
}

/* the times of the character playing in the current act: the save's for
 * the cart's first act, else cart_act_times'. a character the save keeps
 * no times for takes Sonic's */
static struct save_cart_times *cart_find_times(void)
{
    int character = minigame_character();
    int act;
    struct save_cart_times *times;

    if (character >= SAVE_CHARACTERS) {
        character = 0;
    }
    act = cart_get_act();
    switch ((Uint8)act) {
    case 0:
        times = &SaveData[save_slot].cart_times[character];
        break;
    default:
        times = &cart_act_times[(Uint8)act - 1][character];
        break;
    }
    return times;
}

/* the index of the character playing among a save's records, or
 * SAVE_CHARACTERS for a character it keeps none for */
static int minigame_character(void)
{
    int character = GetPlayerNumber();

    switch (character) {
    case CHARACTER_SONIC:
        character = 0;
        break;
    case CHARACTER_TAILS:
        character = 1;
        break;
    case CHARACTER_KNUCKLES:
        character = 2;
        break;
    case CHARACTER_AMY:
        character = 3;
        break;
    case CHARACTER_E102:
        character = 4;
        break;
    case CHARACTER_BIG:
        character = 5;
        break;
    default:
        character = SAVE_CHARACTERS;
        break;
    }
    return character;
}

/* stage_get_stage_act() if its act is one of the cart's after the first,
 * else 0 */
static int cart_get_act(void)
{
    int stage_act = GetStageNumber();

    if (!((Uint8)stage_act > 0 && (Uint8)stage_act < CART_ACTS)) {
        stage_act = 0;
    }
    return stage_act;
}
