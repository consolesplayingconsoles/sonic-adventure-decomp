/* @unit 8C090E00-8C090EE0 +r04 +egflags +pool32 */
/* story: each character's sections, and the scripts in the field modules
 * they run */
#include "progress/story.h"
#include "adv00/script_amy_birds.h"
#include "adv00/script_amy_opening.h"
#include "adv00/script_amy_sonic.h"
#include "adv00/script_big_beach.h"
#include "adv00/script_big_twinkle.h"
#include "adv00/script_e102_beach.h"
#include "adv00/script_knuckles_chaos2.h"
#include "adv00/script_knuckles_highway.h"
#include "adv00/script_tails_casino.h"
#include "adv00/script_tails_highway.h"
#include "adv00/script_tails_opening.h"
#include "adv00/script_tails_wake.h"
#include "adv00/script_sonic_amy.h"
#include "adv00/script_sonic_beach.h"
#include "adv00/script_sonic_highway.h"
#include "adv00/script_sonic_opening.h"
#include "adv00/script_sonic_sewer.h"
#include "adv00/script_sonic_twinkle.h"
#include "adv00/script_sonic_wake.h"
#include "adv01obj/script_amy_mogura.h"
#include "adv01obj/script_amy_sink.h"
#include "adv01obj/script_amy_zero.h"
#include "adv01obj/script_big_chaos6.h"
#include "adv01obj/script_big_hot_shelter.h"
#include "adv01obj/script_e102_amy.h"
#include "adv01obj/script_e102_e101r.h"
#include "adv01obj/script_e102_mission.h"
#include "adv01obj/script_knuckles_chaos6.h"
#include "adv01obj/script_knuckles_skydeck.h"
#include "adv01obj/script_tails_escape.h"
#include "adv01obj/script_tails_skydeck.h"
#include "adv01obj/script_sonic_chaos6.h"
#include "adv01obj/script_sonic_skydeck.h"
#include "adv02/script_amy_go_egg_carrier.h"
#include "adv02/script_amy_mr_final_egg.h"
#include "adv02/script_big_ending.h"
#include "adv02/script_big_icecap.h"
#include "adv02/script_big_opening.h"
#include "adv02/script_e102_birth_e101.h"
#include "adv02/script_e102_go_egg_carrier.h"
#include "adv02/script_e102_mountain.h"
#include "adv02/script_e102_windy.h"
#include "adv02/script_knuckles_ending1.h"
#include "adv02/script_knuckles_ending2.h"
#include "adv02/script_knuckles_m_emerald.h"
#include "adv02/script_knuckles_mountain_chaos4.h"
#include "adv02/script_knuckles_opening.h"
#include "adv02/script_last_chaos_emerald.h"
#include "adv02/script_last_opening_1.h"
#include "adv02/script_last_opening_2.h"
#include "adv02/script_tails_ending.h"
#include "adv02/script_tails_icecap_shooting.h"
#include "adv02/script_tails_lose_sand_board.h"
#include "adv02/script_tails_mobile1_windy.h"
#include "adv02/script_tails_shooting2.h"
#include "adv02/script_sonic_ending.h"
#include "adv02/script_sonic_final_egg.h"
#include "adv02/script_sonic_icecap_shooting.h"
#include "adv02/script_sonic_lost_world.h"
#include "adv02/script_sonic_mobile1_windy.h"
#include "adv02/script_sonic_mountain_shooting2.h"
#include "adv03/script_amy_tikal.h"
#include "adv03/script_last_angry.h"
#include "adv03/scripts.h"
#include "player/player.h"
#include "progress/progress.h"
#include "stage/stage.h"
int FUN_8c090e56(int character);
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

#define LENGTH(story) ((int)(sizeof(story) / sizeof((story)[0])))

void script_idle_init(void);
void script_idle_step(int seq);
extern struct story_script script_idle;
extern struct story_section sonic_story[16];
extern struct story_section sonic_story[];
extern struct story_section tails_story[12];
extern struct story_section tails_story[];
extern struct story_section knuckles_story[12];
extern struct story_section knuckles_story[];
extern struct story_section amy_story[9];
extern struct story_section amy_story[];
extern struct story_section e102_story[9];
extern struct story_section e102_story[];
extern struct story_section big_story[8];
extern struct story_section big_story[];
extern struct story_section last_story_sections[4];
extern struct story_section last_story_sections[];

struct story_section *story_get_table(int character)
{
    if (last_story) {
        return last_story_sections;
    }
    switch (character) {
    case CHARACTER_SONIC:
        return sonic_story;
    case CHARACTER_TAILS:
        return tails_story;
    case CHARACTER_KNUCKLES:
        return knuckles_story;
    case CHARACTER_AMY:
        return amy_story;
    case CHARACTER_E102:
        return e102_story;
    case CHARACTER_BIG:
        return big_story;
    }
    return NULL;
}

int FUN_8c090e56(int character)
{
    if (last_story) {
        return LENGTH(last_story_sections);
    }
    switch (character) {
    case CHARACTER_SONIC:
        return LENGTH(sonic_story);
    case CHARACTER_TAILS:
        return LENGTH(tails_story);
    case CHARACTER_KNUCKLES:
        return LENGTH(knuckles_story);
    case CHARACTER_AMY:
        return LENGTH(amy_story);
    case CHARACTER_E102:
        return LENGTH(e102_story);
    case CHARACTER_BIG:
        return LENGTH(big_story);
    }
    return 0;
}

void script_idle_init(void)
{
}

void script_idle_step(int seq)
{
}
