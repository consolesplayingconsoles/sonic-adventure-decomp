/* @unit 8C0E6560-8C0EBEE0 +r04 +egflags +pool32 +poolafter=fishing_target_draw,chkCursorLimit,fishing_create_lure,fishing_banner_blink,fishing_measure_line,fishing_lure_show,fishing_lure_at_rod,setLureSpd_D,fishing_reel_fast,fishing_lure_dangle,fishing_lure_yaw,fishing_hook_point,fishing_set_draw,fishing_look_at_lure,fishing_get_water,fishing_reset,fishing_sweep,fishing_save +poolbra=fishing_steep:1,fishing_hud_draw:4,fishing_draw_tension:2,DisplayScoreAction:1,fishing_rod_tip:1,fishing_reel_fast:2,setLureSpd_Swing:8,CL_ColPolCheckZxNShadow:5,CL_ColPolCheckZxNShadow:11,CL_ColPolCheckZxNShadow:18,fishing_lure_swim:1,fishing_lure_swim:6,fishing_lure_swim:14,fishing_lure_swim:16,setLureReturn:j3,fishing_lure_step:8,fishing_lure_step:17,fishing_lure_step:21,fishing_lure_step:26,fishing_lure_step:34,fishing_lure_sway:6,fishing_lure_pitch:10,fishing_lure_camera:2,fishing_banner_step:j2,fishing_splash_step:2,fishing_pen_sweep:1,fishing_sweep:3,fishing_catch_step:1,fishing_save_stage:1,fishing_lure_return:1 +asmfunc=fishing_target_draw,calcFishingCursorY:+8c0e9f80,fishing_find_surfaces_at:+8c0ea230,fishing_save_score */
/* the fishing game: Big's target and lure, their camera, the hud and score */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "collision/ground.h"
#include "collision/mesh.h"
#include "collision/polygon.h"
#include "collision/world.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "hud/board.h"
#include "hud/hud.h"
#include "main.h"
#include "object/item_box.h"
#include "object/item_box_air.h"
#include "object/level_item.h"
#include "player/big.h"
#include "player/big_models.h"
#include "player/fish.h"
#include "player/fishing.h"
#include "player/fishing_line.h"
#include "player/player.h"
#include "progress/progress.h"
#include "save/card.h"
#include "save/save.h"
#include "sound/sound.h"
#include "sound/stream.h"
#include "stage/stage.h"
#include "system/frame.h"
#include "system/pad.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
#include "system/util.h"
float njFloor(float x);
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
void *syMalloc_default_malloc(size_t size);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
void InitCartGoalCamFunc(struct camera_view *view);
void AmyBalanceGameStartChecker(struct camera_view *view);
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void MirenScoreDisplayScore(int score);
void FUN_8c08a060(Sint16 count);
Sint16 FUN_8c08a4b2(void);
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
void PutItem_ItemBoxAir(NJS_POINT3 *pos, enum item_kind kind);
void ObjectItemboxAir(struct task *task);
void InitItemBoxManager(void);
void FUN_8c05e038(enum item_kind kind);
Bool chkAngLimit(struct task *task, NJS_POINT3 *point);
Bool chkLureKaeru(struct task *task);
void BigSakana(struct task *task);
int FUN_8c0e6dc0(void);
Float FUN_8c0eb4f0(void);
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
Bool SeqCheckStage(int stage, int act);
void SeqChangeStage(int stage, int act);
Bool SeqCheckNextStage(Uint8 stage, Uint8 act);
Bool SeqCheckClearAction(int stage);
void pdExecPeripheralServerUser(void);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
void ADX_Close(void);
void BGM_Play(int music);
void Serif_Play(int voice);
void ADXTaskInit(void);
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
Angle AdjustAngle(Angle from, Angle to, Angle step);
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
struct task *GetPlayerTaskPointer(Uint8 player);

#define TEXT_1_LENGTH 8
#define TEXT_2_LENGTH 10
#define TEXT_3_LENGTH 10
#define TEXT_4_LENGTH 10
#define TEXT_5_LENGTH 11

#define SE_CAST 797
#define SE_LURE_WATER 798
#define SE_LURE_GROUND 799
#define SE_REEL 800
#define SE_LURE_BOTTOM 809
#define SE_STRAIN 810
#define SE_CAST_SWING 1208

/* Big's voice line once the frog's catch has shown, at Twinkle Park and
 * Ice Cap */
#define VOICE_FROG 0x727

/* Big's act of Ice Cap, where he fishes in pens */
#define ICECAP_POND STAGE_ACT(STAGE_ICECAP, 3)

/* the depth the fishing game's hud draws at, each sprite a little apart */
#define HUD_DEPTH (-1.8F)

/* how far the lure flies a step, in x and z */
#define CAST_SPEED 3.0F

/* the reel's buttons held this step, as bits. an action button reels in
 * slowly, and a jump button fast, with an action button or without */
#define HELD_ACTION 0x1
#define HELD_JUMP 0x2

/* a trigger's pull, 0 to 255, on a stick's signed scale: -0x8000 at rest */
#define TRIGGER_AXIS(pull) (((pull) << 8) - 0x8000)

#define TARGET(task) ((struct target_extra *)(task)->extra)
#define LURE(task) ((struct lure_extra *)(task)->extra)
#define LURE_VARS(work) ((struct lure_vars *)&(work)->vars)
#define SKIP_WATER_BELOW 0x1
#define SKIP_WATER_ABOVE 0x2
#define SKIP_NOTHING 0x4
#define BANNER_VARS(work) ((struct banner_vars *)&(work)->vars)
#define SPLASH_VARS(work) ((struct splash_vars *)&(work)->vars)
#define CATCH_VARS(work) ((struct catch_vars *)&(work)->vars)
#define CATCH_SNAPPED 999
#define PRIZE_NONE (-1)
#define RANDOM_RING_COUNTS 6
#define PENS 3
#define EASY_PULL 0.0F
enum lure_mode {
    LURE_INIT,
    LURE_DANGLE, /* hanging from the rod's tip while Big aims */
    LURE_WAIT, /* dangling 10 steps after the cast, then thrown */
    LURE_FLY,
    LURE_LANDED, /* just down in the water, for the one step that moves it on */
    LURE_IN_WATER,
    LURE_FISH, /* with a fish on */
    LURE_BACK, /* back to the rod with no fish, 10 a step */
    LURE_CATCH /* back to the rod with a fish on, 2 a step */
};

enum target_mode { TARGET_INIT, TARGET_AIM };

enum hud_mode { HUD_INIT, HUD_SHOW };

enum banner_mode {
    BANNER_INIT,
    BANNER_IN,
    BANNER_WAIT,
    BANNER_OUT,
    BANNER_DONE
};

enum splash_mode { SPLASH_INIT, SPLASH_PLAY, SPLASH_FADE };

enum catch_mode { CATCH_INIT, CATCH_SHOW, CATCH_LEAVE };

/* the target task's extra */
struct target_extra {
    Float distance; /* how far out from player 0 it is */
    Float ground; /* the ground's height under it */
    Sint16 heading; /* Big's heading as it was put out */
    Uint8 unk_0a[2];
    /* the ground's slope under it, which its mark tilts by */
    Sint16 slope_x;
    Sint16 slope_z;
};

/* the lure model's turns that lure_extra's sway keeps. SWAY_PHASE is the
 * phase of the model's rock about x. SWAY_ROLL is its turn about z, which
 * it takes on the bottom as its turn about x. SWAY_BOTTOM_Z is its turn
 * about z on the bottom, which nothing sets */
enum { SWAY_BOTTOM_Z, SWAY_PHASE, SWAY_ROLL };

/* the lure task's extra */
struct lure_extra {
    Uint8 unk_00[2];
    Sint16 sway[3];
    /* the line, from the heap */
    struct fishing_line *line;
    NJS_POINT3 *goal; /* where it flies to; freed with the lure */
};

/* the lure task's work->vars */
struct lure_vars {
    Uint8 unk_00[4];
    /* the steps left to dangle after the cast. in flight, the steps flown,
     * which nothing reads */
    Sint32 steps;
};

/* a surface fishing_find_surfaces found */
struct near_surface {
    Sint32 flags; /* its object's WORLD_ flags */
    Angle ang_x; /* how it slopes */
    Angle ang_z;
    Float height;
};

/* the surfaces nearest a point, which fishing_find_surfaces' skip may leave
 * water out of. with none found, above's height is GROUND_FAR, below's
 * -GROUND_FAR and water's GROUND_FAR */
struct near_surfaces {
    struct near_surface above; /* the lowest above the point */
    struct near_surface below; /* the highest at or below it */
    struct near_surface water; /* the nearest water, above or below */
};

/* fishing_find_surfaces' skip, as bits: water left out of below, or out of
 * above. SKIP_NOTHING is a bit neither test reads, so water counts on both
 * sides */

/* the hit banner's work->vars. its pos.x is each half's distance from the
 * screen's middle */
struct banner_vars {
    Sint32 blinks; /* the steps fishing_banner_blink has run */
    Sint32 steps; /* the steps left to wait at the middle */
};

/* a splash task's work->vars. its TASK_TIMER counts the steps to its next
 * sprite, or to its next fade */
struct splash_vars {
    Sint32 frame; /* the sprite it shows */
    Uint8 unk_04[4];
    Float alpha; /* 1, less a tenth for each fade */
};

/* a catch task's work->vars. its pos.x and pos.z hold where the weight
 * shows on the screen, and its scl.x the weight's size */
struct catch_vars {
    /* the fish's kind, or CATCH_SNAPPED for a fish the snapped line lost */
    Sint32 kind;
    Sint32 steps; /* the steps left to show the weight */
    Sint32 weight;
};

/* a field's prize */
struct fishing_prize {
    Float chance; /* that fishing_give_prize gives it, from 0 to 1 */
    Sint32 kind; /* an item_kind, or PRIZE_NONE */
    void (*give)(void); /* or null */
};

/* how many ring counts a random-rings prize picks from: the same six as
 * item_box.c's random rings */

extern NJS_OBJECT fishing_target_mark;
extern NJS_OBJECT fishing_target_object;
extern NJS_OBJECT big_lure_0;
extern NJS_OBJECT big_lure_1;
extern NJS_OBJECT big_lure_2;
extern NJS_OBJECT big_lure_3;
extern NJS_OBJECT big_lure_4;
extern const Sint16 fishing_random_ring_counts[6];
extern Float fishing_water;
extern Float fishing_distance;
extern Float fishing_line_out;
extern Float fishing_tension;
extern Float fishing_tension_aim;
extern Angle fishing_reel_ang;
extern int fishing_warn_steps;
extern NJS_TEXNAME fishing_prize_textures[];
extern NJS_OBJECT *fishing_lures[];
extern NJS_POINT3 fishing_pens[];
extern NJS_TEXLIST fishing_prize_texlist;
extern struct collision_shape fishing_lure_shapes[];
/* clang-format on */
/* fishing_hud_texanims' sprites, which fishing_texlist holds */
enum hud_sprite {
    SPRITE_GAUGE, /* the tension gauge */
    SPRITE_REEL,
    /* castgauge2, the gauge's bar as a sprite, which nothing draws. a
     * polygon draws the bar */
    SPRITE_BAR,
    SPRITE_LIVES, /* zanki_r, which nothing draws */
    SPRITE_SCORE_LABEL,
    SPRITE_UNIT, /* the weight's unit */
    SPRITE_HIT_LEFT, /* the hit banner's halves */
    SPRITE_HIT_RIGHT,
    /* a field's label, in place of the score's: the lower part of its
     * texture */
    SPRITE_FIELD_LABEL,
    HUD_SPRITES
};
extern NJS_TEXANIM fishing_hud_texanims[HUD_SPRITES];
extern NJS_TEXLIST fishing_regular_texlist;
extern NJS_TEXANIM fishing_head_texanims[1];
extern NJS_TEXANIM fishing_splash_texanims[8];

void fishing_prize_5_rings(void);
void fishing_prize_10_rings(void);
void fishing_prize_random_rings(void);
void fishing_prize_1up(void);
extern struct fishing_prize fishing_prizes[7];
extern int fishing_score;
extern Sint16 biggest_fish;
extern int biggest_fish_kind;
extern int fishing_record_weight;
extern Uint16 fishing_flags;
extern Float fishing_strain;
extern NJS_POINT3 fishing_cast_pos;
extern int fishing_fight_steps;
extern Angle fishing_ring_blink;
extern struct save fishing_save_copy;
void fishing_target_draw(struct task *task);

static void fishing_target_destroy(struct task *task);
void MoveFishingCursor(struct task *task);
Bool fishing_steep(struct task *task, struct angles *ang);
Bool fishing_upright(struct task *task, struct angles *ang);
Bool chkCursorLimit(struct task *task, struct near_surfaces *info, Float x,
                    Float y, Float z);
void fishingCursorCtrl(struct task *task);
void fishing_lure_destroy(struct task *task);
void fishing_banner_draw(struct task *task);
void fishing_banner_blink(struct task *task);
void fishing_hud_show(struct task *task);
void fishing_hud_draw(struct task *task);
void fishing_draw_reel(void);
void fishing_draw_tension(void);
void fishing_draw_line_out(Float distance);
void DisplayScoreAction(int score);
void fishing_measure_line(NJS_POINT3 *from, NJS_POINT3 *to);
void fishing_lure_show(struct task *task);
void fishing_lure_draw(struct task *task);
void fishing_rod_tip(struct task *task, NJS_POINT3 *pos);
Bool fishing_lure_fly(struct task *task);
Bool fishing_lure_return(struct task *task);
Bool fishing_lure_at_rod(NJS_POINT3 *tip, NJS_POINT3 *pos);
void setLureSpd_D(struct task *task);
void setLureSpd_S(struct task *task, NJS_POINT3 *tip);
void fishing_reel_fast(struct task *task, NJS_POINT3 *tip);
void setLureSpd_Swing(struct task *task, NJS_POINT3 *tip);
void CL_ColPolCheckZxNShadow(struct task *task, NJS_VECTOR *move);
Bool fishing_fish_pulls(struct task *task);
Bool fishing_in_pen(void);
void fishing_lure_swim(struct task *task);
void fishing_lure_dangle(struct task *task, NJS_POINT3 *tip);
void fishing_lure_reset(struct task *task);
void setLureReturn(struct task *task);
Bool fishing_lure_in_water(struct task *task, struct near_surfaces *info);
Bool fishing_mark_shelter_plug(void);
void fishing_lure_step(struct task *task);
void fishing_lure_home(struct task *task);
Float calcFishingCursorY(Float x, Float y, Float z, int skip,
                         struct near_surfaces *info);
Float fishing_find_surfaces_at(struct task_work *work, int skip,
                               struct near_surfaces *info);
void fishing_lure_sway(struct task *task);
void fishing_lure_pitch(struct task *task);
void fishing_lure_yaw(struct task *task);
void moveFishingRotZ(struct task *task);
void fishing_line_end(NJS_POINT3 *pos);
void fishing_set_draw(void);
void fishing_camera_step_point(struct camera_view *view);
void fishing_target_camera(struct task *task);
void fishing_lure_camera(struct task *task);
void fishing_look_at_lure(struct task *task);
void fishing_camera_clear(NJS_POINT3 *from, NJS_POINT3 *to);
void fishing_camera_step_lure(struct camera_view *view);
void fishing_banner_step(struct task *task);
struct task *fishing_splash_create(struct task *parent);
void fishing_splash_draw(struct task *task);
void fishing_splash_destroy(struct task *task);
void fishing_splash_step(struct task *task);
int fishing_give_prize(void);
Bool fishing_pen_sweep(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                       Float radius);
Bool fishing_sweep(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                   Float radius);
void fishing_score_catch(Float weight, int kind);
void fishing_catch_draw(struct task *task);
void fishing_catch_destroy(struct task *task);
void fishing_catch_step(struct task *task);
int fishing_save_stage(void);
void fishing_save_score(struct save *save, int stage, Sint16 score);
void fishing_save_fish(struct save *save, int stage, Sint16 weight, int kind);
void fishing_save(void);
Float fishing_load_record(void);

struct task *SetFishingCursorTask(struct task *big)
{
    struct task *task;

    task = CreateElementalTask(TASK_MOTION | TASK_WORK | TASK_EXTRA, 2,
                               fishingCursorCtrl);
    if (task != NULL) {
        task->work->pos = big->work->pos;
        task->work->ang = big->work->ang;
        TARGET(task)->heading = big->work->ang.y;
        TARGET(task)->distance = 20.0F;
        task->work->pos.x += njCos(task->work->ang.y) * TARGET(task)->distance;
        task->work->pos.y += 20.0F;
        task->work->pos.z += njSin(task->work->ang.y) * TARGET(task)->distance;
    }
    return task;
}
#ifdef NON_MATCHING

/* draw the target's mark on the ground, tilted to its slope, and the
 * target. the quad it fills is never drawn */
void fishing_target_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct target_extra *extra = task->extra;
    NJS_POINT3COL quad;
    NJS_POINT3 points[4];
    NJS_COLOR colors[4];
    /* @hack redundant: 12 bytes of frame that no code reads, of a type unknown,
     * declared as a point. the image's ADD #-100,R15 reserves them in its
     * 124-byte frame (0x8c0f0cf2); without them, 5 of 168 words differ */
    NJS_POINT3 unused;
    Float ground;
    Angle ang;
    NJS_COLOR *color;
    int i;

    quad.p = points;
    quad.col = colors;
    quad.num = 4;
    quad.p[0].x = -5.0F;
    quad.p[0].z = -5.0F;
    quad.p[1].x = 5.0F;
    quad.p[1].z = -5.0F;
    quad.p[2].x = 5.0F;
    quad.p[2].z = 5.0F;
    quad.p[3].x = -5.0F;
    quad.p[3].z = 5.0F;
    ground = extra->ground;
    quad.p[0].y = quad.p[1].y = quad.p[2].y = quad.p[3].y = 0.0F;
    color = quad.col;
    for (i = 0; i < 4; i++) {
        color[i].color = 0x80ffffff;
    }
    quad.tex = NULL;
    njSetTexture_jp(&fishing_texlist);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, ground + 3.0F, work->pos.z);
    TURN_VIA(njRotateZ, extra->slope_z, ang);
    TURN_VIA(njRotateX, extra->slope_x, ang);
    TURN(njRotateY, -work->ang.y);
    late_DrawObject(&fishing_target_mark);
    late_DrawObjectClipEx(1);
    color = quad.col;
    for (i = 0; i < 4; i++) {
        color[i].color = 0x80ff0000;
    }
    /* @hack redundant: color set to colors after both loops, though nothing
     * reads it, which has each loop load color from quad.col (MOV.L
     * @(4,R14),R4 at 0x8c0f0d66 and 0x8c0f0de0); without it, 127 of 168 words
     * differ */
    color = colors;
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(&fishing_target_object);
    late_DrawObjectClipEx(1);
}
#else
void fishing_target_draw(struct task *task)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
    asm_stub[0] = 32;
    asm_stub[1] = 33;
    asm_stub[2] = 34;
    asm_stub[3] = 35;
    asm_stub[4] = 36;
    asm_stub[5] = 37;
    asm_stub[6] = 38;
    asm_stub[7] = 39;
    asm_stub[0] = 40;
    asm_stub[1] = 41;
    asm_stub[2] = 42;
    asm_stub[3] = 43;
    asm_stub[4] = 44;
    asm_stub[5] = 45;
    asm_stub[6] = 46;
    asm_stub[7] = 47;
    asm_stub[0] = 48;
    asm_stub[1] = 49;
    asm_stub[2] = 50;
    asm_stub[3] = 51;
    asm_stub[4] = 52;
    asm_stub[5] = 53;
    asm_stub[6] = 54;
    asm_stub[7] = 55;
    asm_stub[0] = 56;
    asm_stub[1] = 57;
    asm_stub[2] = 58;
    asm_stub[3] = 59;
    asm_stub[4] = 60;
    asm_stub[5] = 61;
    asm_stub[6] = 62;
    asm_stub[7] = 63;
    asm_stub[0] = 64;
    asm_stub[1] = 65;
    asm_stub[2] = 66;
    asm_stub[3] = 67;
    asm_stub[4] = 68;
    asm_stub[5] = 69;
    asm_stub[6] = 70;
    asm_stub[7] = 71;
    asm_stub[0] = 72;
    asm_stub[1] = 73;
    asm_stub[2] = 74;
    asm_stub[3] = 75;
    asm_stub[4] = 76;
    asm_stub[5] = 77;
    asm_stub[6] = 78;
    asm_stub[7] = 79;
    asm_stub[0] = 80;
    asm_stub[1] = 81;
    asm_stub[2] = 82;
    asm_stub[3] = 83;
    asm_stub[4] = 84;
    asm_stub[5] = 85;
    asm_stub[6] = 86;
    asm_stub[7] = 87;
    asm_stub[0] = 88;
    asm_stub[1] = 89;
    asm_stub[2] = 90;
    asm_stub[3] = 91;
    asm_stub[4] = 92;
    asm_stub[5] = 93;
    asm_stub[6] = 94;
    asm_stub[7] = 95;
    asm_stub[0] = 96;
    asm_stub[1] = 97;
    asm_stub[2] = 98;
    asm_stub[3] = 99;
    asm_stub[4] = 100;
    asm_stub[5] = 101;
    asm_stub[6] = 102;
    asm_stub[7] = 103;
    asm_stub[0] = 104;
    asm_stub[1] = 105;
    asm_stub[2] = 106;
    asm_stub[3] = 107;
    asm_stub[4] = 108;
    asm_stub[5] = 109;
    asm_stub[6] = 110;
}
#endif

void fishing_target_destroy(struct task *task)
{
}

/* move the target the way the stick points, 3 a step, onto the ground there. it
 * stays where it is when the place is out of reach, or the move met a wall. the
 * stick is that of the player its vars name, which nothing sets: player 0. the
 * target stands 20 above the ground, but at most 49.9 above player 0 */
void MoveFishingCursor(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    struct target_extra *extra = task->extra;
    Angle ang = input_dataG[PLAYER_VARS(work)->player].ang;
    Float stroke = input_dataG[PLAYER_VARS(work)->player].stroke;
    struct angles slope;
    NJS_POINT3 pos;
    NJS_VECTOR move;
    struct near_surfaces info;
    Float x;
    Float y;
    Float z;

    slope.x = slope.y = slope.z = 0;
    pos = work->pos;
    if (stroke == 0.0F) {
        move.x = 0.0F;
        move.y = 0.0F;
        move.z = 0.0F;
    } else {
        move.x = njCos(ang) * 3.0F;
        move.y = 0.0F;
        move.z = njSin(ang) * 3.0F;
        MSetPosition(&pos, &move, &slope, 1.0F);
    }
    x = work->pos.x + move.x;
    y = work->pos.y + move.y;
    z = work->pos.z + move.z;
    calcFishingCursorY(x, y, z, SKIP_NOTHING, &info);
    y = info.below.height;
    if (chkCursorLimit(task, &info, x, y, z) == FALSE &&
        fishing_steep(NULL, &slope) == FALSE) {
        work->pos.x = x;
        work->pos.z = z;
        extra->ground = y;
        extra->slope_x = info.below.ang_x;
        extra->slope_z = info.below.ang_z;
        y += 20.0F;
        if (y >= player->pos.y + 49.9F) {
            work->pos.y = player->pos.y + 49.9F;
        } else {
            work->pos.y = y;
        }
    }
    move.x = work->pos.x - player->pos.x;
    move.z = work->pos.z - player->pos.z;
    extra->distance = njScalor(&move);
}

/* TRUE when a surface sloped by ang is a wall or hangs over: its normal's
 * y is at most 0.01. with a task, TRUE only if the normal's dot with the
 * way from player 0 to the task also passes 0.7. fishing_target_move, the
 * one caller, passes no task */
Bool fishing_steep(struct task *task, struct angles *ang)
{
    NJS_VECTOR up;
    NJS_VECTOR axis;
    NJS_MATRIX matrix;
    Float dot;

    up.x = up.z = axis.x = axis.z = 0.0F;
    up.y = axis.y = 1.0F;
    njUnitMatrix(&matrix);
    njRotateXYZ(&matrix, ang->x, ang->y, ang->z);
    njCalcVector(&matrix, &up, &up);
    dot = njInnerProduct(&up, &axis);
    if (dot <= 0.01F) {
        if (task == NULL) {
            return TRUE;
        }
        axis.x = task->work->pos.x - playertwp[0]->pos.x;
        axis.y = 0.0F;
        axis.z = task->work->pos.z - playertwp[0]->pos.z;
        njUnitVector(&axis);
        dot = njInnerProduct(&up, &axis);
        if (dot > 0.7F) {
            return TRUE;
        }
    }
    return FALSE;
}

/* TRUE when a surface sloped by ang stands straight up: its normal's y
 * lies within 0.01 of 0. task goes unused */
Bool fishing_upright(struct task *task, struct angles *ang)
{
    NJS_VECTOR up;
    NJS_VECTOR axis;
    NJS_MATRIX matrix;
    Float dot;

    up.x = up.z = axis.x = axis.z = 0.0F;
    up.y = axis.y = 1.0F;
    njUnitMatrix(&matrix);
    njRotateXYZ(&matrix, ang->x, ang->y, ang->z);
    njCalcVector(&matrix, &up, &up);
    dot = njInnerProduct(&up, &axis);
    if (dot > 0.01F || dot < -0.01F) {
        return FALSE;
    }
    return TRUE;
}

/* TRUE when the target can't go to (x, y, z), on the ground info found
 * there. the point must lie 18 to 250 from player 0 in x and z, or 18 to
 * 350 with the power rod. its bearing from him must lie within 0x2b00,
 * about 60 degrees, of the target's heading. for some headings the test
 * passes more, as its tag says. the ground must slope at most a quarter
 * turn each way, and lie within 50 of his height */
Bool chkCursorLimit(struct task *task, struct near_surfaces *info, Float x,
                    Float y, Float z)
{
    struct task_work *player = playertwp[0];
    struct player *record = playermwp[0]->record;
    NJS_VECTOR away;
    Float distance;
    Float reach;
    Float height;
    int ang;

    away.x = x - player->pos.x;
    away.y = 0.0F;
    away.z = z - player->pos.z;
    distance = njScalor(&away);
    reach = (record->upgrades & PLAYER_BIG_POWER_ROD) ? 350.0F : 250.0F;
    if (distance > reach || distance < 18.0F) {
        return TRUE;
    }
    ang = ((0x4000 - (Angle)(njArcTan2(away.x, away.z) * ANGLE_PER_RADIAN)) &
           0xffff) -
          TARGET(task)->heading;
    /* @bug logic: the heading is read sign-extended (MOV.W @(8,R1),R0 at
     * 0x8c0f126a), and the bearing runs 0 to 0xffff, so ang runs from
     * -0x7fff to 0x17fff. neither window (CMP/GT at 0x8c0f127c, CMP/GE at
     * 0x8c0f1288) refuses ang past 0x12b00. so for a heading from 0x8000
     * to 0xd4fe, some bearings more than 0x2b00 off it pass, up to half a
     * turn off for 0x8000. a heading of 0xc000 and a bearing of 0xf000 give
     * ang 0x13000, which passes */
    if (ang > 0x2b00 && ang < 0xd500) {
        return TRUE;
    }
    if (ang < -0x2b00 && ang > -0xd500) {
        return TRUE;
    }
    ang = info->below.ang_x;
    if (ang > 0x4000 || ang < -0x4000 || info->below.ang_z > 0x4000 ||
        info->below.ang_z < -0x4000) {
        return TRUE;
    }
    height = y - player->pos.y;
    if (height <= -50.0F || height >= 50.0F) {
        return TRUE;
    }
    return FALSE;
}

/* the target's step. as Big aims, it spins, the camera looks at it, the
 * stick moves it and player 0 turns to face it. it ends once
 * big_not_fishing gives TRUE */
void fishingCursorCtrl(struct task *task)
{
    struct task_work *work = task->work;
    struct target_extra *extra = task->extra;
    struct task_work *player = playertwp[0];
    NJS_OBJECT *lure = fishing_lures[FUN_8c0e6dc0()]->child;

    switch (work->mode) {
    case TARGET_INIT:
        work->mode = TARGET_AIM;
        task->destructor = fishing_target_destroy;
        task->draw = fishing_target_draw;
        extra->ground = work->pos.y;
        extra->slope_z = 0;
        extra->slope_x = 0;
        lure->ang[0] = 0x1000;
        lure->evalflags &= ~NJD_EVAL_UNIT_ANG;
        break;
    case TARGET_AIM:
        fishing_water = extra->ground;
        work->ang.y += 0x200;
        fishing_target_camera(task);
        MoveFishingCursor(task);
        fishing_target_draw(task);
        playermwp[0]->aim.y = playertwp[0]->ang.y =
            0x4000 - (Angle)(njArcTan2(work->pos.x - player->pos.x,
                                       work->pos.z - player->pos.z) *
                             ANGLE_PER_RADIAN);
        if (ChkFishingThrowNow(task)) {
            FreeTask(task);
        }
        break;
    }
}

struct task *fishing_create_lure(struct task *big)
{
    struct task *task;
    struct fishing_line *line;
    NJS_POINT3 *goal;

    task = CreateElementalTask(TASK_MOTION | TASK_WORK | TASK_EXTRA, 2,
                               fishing_lure_step);
    /* @bug memory: each lure leaks its line. fishing_lure_destroy frees goal
     * (JSR to heap_free at 0x8c0f157a), but nothing frees the line heap_calloc
     * gives here (JSR at 0x8c0f1478) */
    line = CAlloc(1, sizeof(struct fishing_line));
    /* @bug memory: the line goes into task's extra before the test for a
     * null task (MOV.L @(44,R14),R3 at 0x8c0f147c, TST R14,R14 at
     * 0x8c0f148a) */
    LURE(task)->line = line;
    goal = CAlloc(5, sizeof(Float));
    /* @bug memory: a lure whose goal fails to allocate comes back all the
     * same, with a null goal its cast stores through (FMOV.S FR3,@R1 at
     * 0x8c0f3de6) */
    if (task != NULL && goal != NULL) {
        task->work->pos = big->work->pos;
        task->work->ang = big->work->ang;
        LURE(task)->goal = goal;
        if (big_lure != NULL) {
            fishing_flags = 0;
        }
        fishing_reel_ang = 0;
    }
    return task;
}

int FUN_8c0e6dc0(void)
{
    int count = 0;

    if (SeqCheckFlag(FLAG_BIG_LURE_EGG_CARRIER)) {
        count++;
    }
    if (SeqCheckFlag(FLAG_BIG_LURE_ICECAP)) {
        count++;
    }
    if (SeqCheckFlag(FLAG_BIG_LURE_STATION_SQUARE)) {
        count++;
    }
    if (SeqCheckFlag(FLAG_BIG_LURE_MYSTIC_RUINS)) {
        count++;
    }
    big_lure_count = count;
    return count;
}

void fishing_lure_destroy(struct task *task)
{
    struct lure_extra *extra = task->extra;
    NJS_POINT3 *goal;

    dsStop_num(SE_REEL);
    goal = extra->goal;
    if (goal != NULL) {
        Free(goal);
    }
    big_lure = NULL;
}

/* draw the hit banner's halves, each pos.x from the screen's middle */
void fishing_banner_draw(struct task *task)
{
    NJS_SPRITE sprite;

    sprite.tlist = &fishing_texlist;
    sprite.tanim = fishing_hud_texanims;
    sprite.sx = 1.0F;
    sprite.sy = 1.0F;
    sprite.p.x = SCREEN_MIDDLE_X - task->work->pos.x;
    sprite.p.y = 200.0F;
    late_DrawSprite2D(&sprite, SPRITE_HIT_LEFT, HUD_DEPTH - 0.016F,
                      NJD_SPRITE_ALPHA);
    sprite.p.x = SCREEN_MIDDLE_X + 8.0F + task->work->pos.x;
    sprite.p.y = 208.0F;
    late_DrawSprite2D(&sprite, SPRITE_HIT_RIGHT, HUD_DEPTH - 0.017F,
                      NJD_SPRITE_ALPHA);
}

/* count a step, and draw the banner on the even counts */
void fishing_banner_blink(struct task *task)
{
    if (!(++BANNER_VARS(task->work)->blinks & 1)) {
        fishing_banner_draw(task);
    }
}

/* the hud task's step. on each frame's first step, it draws the score's
 * label, the weight's unit, the head beside the lives and the numbers.
 * rings_shown and lives_shown choose among them. it draws nothing on the
 * cart, in a field, or while hud_hidden is below 0 */
void fishing_hud_show(struct task *task)
{
    NJS_SPRITE sprite;

    sprite.tlist = &fishing_texlist;
    sprite.tanim = fishing_hud_texanims;
    sprite.sx = 1.0F;
    sprite.sy = 1.0F;
    if (cart_active()) {
        return;
    }
    if (loop_count != 0) {
        return;
    }
    if (stage_group() == STAGE_GROUP_FIELD) {
        return;
    }
    if (hud_hidden < 0) {
        return;
    }
#ifdef GCC
    /* 16:9 squeezes the score, the lives and the rings about the screen's
     * left edge */
    port_wide_anchor = WIDE_LEFT;
#endif
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njTextureFilterMode_jp(NJD_TEXTUREFILTER_POINT_SAMPLE);
    SetMaterial(1.0F, 1.0F, 1.0F, 1.0F);
    if (rings_shown <= 0) {
        sprite.p.x = 48.0F;
        sprite.p.y = 64.0F;
        late_DrawSprite2D(&sprite, SPRITE_SCORE_LABEL, HUD_DEPTH - 0.02F,
                          NJD_SPRITE_ALPHA);
        sprite.p.x = 184.0F;
        sprite.p.y = 47.0F;
        late_DrawSprite2D(&sprite, SPRITE_UNIT, HUD_DEPTH - 0.02F,
                          NJD_SPRITE_ALPHA);
    }
    if (lives_shown >= 0) {
        sprite.tlist = &fishing_regular_texlist;
        sprite.tanim = fishing_head_texanims;
        sprite.p.x = 16.0F;
        sprite.p.y = 416.0F;
        late_DrawSprite2D(&sprite, 0, -2.0F, NJD_SPRITE_ALPHA);
    }
    DisplayScoreAction(fishing_score);
    njTextureFilterMode_jp(NJD_TEXTUREFILTER_BILINEAR);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
#ifdef GCC
    port_wide_anchor = WIDE_MIDDLE;
#endif
    if (stage_group() == STAGE_GROUP_FIELD) {
        rings_shown = -1;
        lives_shown = -1;
    } else {
        rings_shown = lives_shown = hud_hidden;
    }
}

/* the hud task's draw: as fishing_hud_show, but in a field too, where
 * SPRITE_FIELD_LABEL takes the place of the score's label and unit */
void fishing_hud_draw(struct task *task)
{
    NJS_SPRITE sprite;

    sprite.tlist = &fishing_texlist;
    sprite.tanim = fishing_hud_texanims;
    sprite.sx = 1.0F;
    sprite.sy = 1.0F;
    if (cart_active()) {
        return;
    }
#ifdef GCC
    /* the split frame's second picture replays the hud step 0 drew. this
     * draw is the pause's: in a field it shows the rings, which play hides,
     * and it moves the pulse of a ring count of 0, which step 0 reads */
    if (frame_redrawing) {
        return;
    }
#endif
    if (loop_count != 0) {
        return;
    }
    if (hud_hidden < 0) {
        return;
    }
#ifdef GCC
    port_wide_anchor = WIDE_LEFT;
#endif
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njTextureFilterMode_jp(NJD_TEXTUREFILTER_POINT_SAMPLE);
    SetMaterial(1.0F, 1.0F, 1.0F, 1.0F);
    if (rings_shown <= 0) {
        if (stage_group() == STAGE_GROUP_FIELD) {
            sprite.p.x = 48.0F;
            sprite.p.y = 54.0F;
            late_DrawSprite2D(&sprite, SPRITE_FIELD_LABEL, HUD_DEPTH - 0.02F,
                              NJD_SPRITE_ALPHA);
        } else {
            sprite.p.x = 48.0F;
            sprite.p.y = 64.0F;
            late_DrawSprite2D(&sprite, SPRITE_SCORE_LABEL, HUD_DEPTH - 0.02F,
                              NJD_SPRITE_ALPHA);
            sprite.p.x = 184.0F;
            sprite.p.y = 47.0F;
            late_DrawSprite2D(&sprite, SPRITE_UNIT, HUD_DEPTH - 0.02F,
                              NJD_SPRITE_ALPHA);
        }
    }
    if (lives_shown >= 0) {
        sprite.tlist = &fishing_regular_texlist;
        sprite.tanim = fishing_head_texanims;
        sprite.p.x = 16.0F;
        sprite.p.y = 416.0F;
        late_DrawSprite2D(&sprite, 0, -2.0F, NJD_SPRITE_ALPHA);
    }
    DisplayScoreAction(fishing_score);
    njTextureFilterMode_jp(NJD_TEXTUREFILTER_BILINEAR);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
#ifdef GCC
    port_wide_anchor = WIDE_MIDDLE;
#endif
    if (stage_group() == STAGE_GROUP_FIELD) {
        rings_shown = -1;
        lives_shown = -1;
    } else {
        rings_shown = lives_shown = hud_hidden;
    }
}

/* draw the reel, turned by fishing_reel_ang while the lure is in the water
 * and upright otherwise. nothing while big_lure is null */
void fishing_draw_reel(void)
{
    NJS_SPRITE sprite;

    if (big_lure != NULL) {
        sprite.tlist = &fishing_texlist;
        sprite.tanim = fishing_hud_texanims;
        if (big_lure->work->mode < LURE_LANDED ||
            big_lure->work->mode > LURE_FISH) {
            sprite.ang = 0;
        } else {
            sprite.ang = fishing_reel_ang;
        }
        sprite.sx = 1.0F;
        sprite.sy = 1.0F;
        sprite.p.x = 592.0F;
        sprite.p.y = 394.0F;
        late_DrawSprite2D(&sprite, SPRITE_REEL, HUD_DEPTH - 0.018F,
                          NJD_SPRITE_ALPHA | NJD_SPRITE_ANGLE);
    }
}

/* draw the tension gauge, and its bar as a polygon, 135 tall at a tension
 * of 1. as the tension rises, the bar's top shades from blue to red, and
 * its base from cyan to yellow */
void fishing_draw_tension(void)
{
    NJS_SPRITE sprite;
    NJS_POINT2COL bar;
    NJS_POINT2COL *poly;
    NJS_POINT2 points[4];
    NJS_COLOR colors[4];
    int red;

    sprite.tlist = &fishing_texlist;
    sprite.tanim = fishing_hud_texanims;
    sprite.ang = 0;
    sprite.sx = 1.0F;
    sprite.sy = 1.0F;
    sprite.p.x = 576.0F;
    sprite.p.y = 328.0F;
    late_DrawSprite2D(&sprite, SPRITE_GAUGE, HUD_DEPTH - 0.019F,
                      NJD_SPRITE_ALPHA);
    /* a scale and SPRITE_BAR's top for the tension, which nothing draws:
     * the polygon below is the bar */
    sprite.sx = 1.0F;
    if (fishing_tension < 0.0F) {
        sprite.sy = 0.0F;
    } else if (fishing_tension >= 1.0F) {
        sprite.sy = 4.3F;
    } else {
        sprite.sy = fishing_tension * 4.3F;
        fishing_hud_texanims[SPRITE_BAR].v1 = (1.0F - fishing_tension) * 256.0F;
    }
    poly = &bar;
    poly->p = points;
    poly->col = colors;
    poly->num = 4;
    poly->p[0].x = poly->p[3].x = 574.0F;
    poly->p[0].y = poly->p[1].y = 368.0F;
    poly->p[1].x = poly->p[2].x = 606.0F;
    poly->p[2].y = poly->p[3].y = 368.0F - (fishing_tension * 135.0F);
    red = (int)(fishing_tension * 255.0F) & 0xff;
    poly->col[0].color = poly->col[1].color = 0xff00ffff + (red << 16) - red;
    poly->col[2].color = poly->col[3].color = 0xff0000ff + (red << 16) - red;
    poly->tex = NULL;
    njDrawPolygon2D(poly, 4, HUD_DEPTH - 0.02F, NJD_FILL);
}

/* draw distance, in tens, to 99 */
void fishing_draw_line_out(Float distance)
{
    struct hud_number number;

    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    SetMaterial(1.0F, 1.0F, 1.0F, 1.0F);
    number.flags = NUMBER_CLAMPED | NUMBER_ZEROS;
    number.place = NUMBER_LEFT | NUMBER_TOP | NUMBER_DEPTH;
    number.unk_02 = 0;
    number.max = 99;
    number.value = (int)(distance * 0.1F);
    number.pos.x = 555.0F;
    number.pos.y = 418.0F;
    number.pos.z = 0.0F;
    number.scale = 1.0F;
    number.color = 0xffc0c0c0;
    DrawSNumbers(&number);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_BOTHSRCALPHA);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

/* draw score, except in a field, then the lives and the rings. the ring count
 * pulses toward red while it is 0 */
void DisplayScoreAction(int score)
{
    struct hud_number number;
    /* @hack spelling: hud_draw_number called through draw, which keeps its
     * address in R14 (MOV.L at 0x8c0f1c1a, JSR @R14 at 0x8c0f1c50); called
     * by name, 16 of 131 words differ */
    /* @hack redundant: register, which puts the wave in FR4 (FMOV FR0,FR4
     * at 0x8c0f1d1e); without it, the wave takes FR5 and 6 of 131 words
     * differ */
    register void (*draw)(struct hud_number *number);
    int lives;
    int rings;
    Float wave;
    Float glow;
    int green;
    Float top;

    number.flags = NUMBER_CLAMPED;
    number.place = NUMBER_LEFT | NUMBER_TOP | NUMBER_DEPTH;
    number.unk_02 = 0;
    number.max = 99999;
    number.value = score;
    number.pos.x = 96.0F;
    top = 32.0F;
    number.pos.y = top;
    number.pos.z = 0.0F;
    number.scale = 1.0F;
    number.color = 0xffc0c0c0;
    draw = DrawSNumbers;
    if (stage_group() != STAGE_GROUP_FIELD && rings_shown <= 0) {
        draw(&number);
    }
    lives = FUN_8c08a4b2();
    number.flags = NUMBER_CLAMPED | NUMBER_ZEROS;
    number.max = 99;
    number.value = lives;
    number.pos.x = 49.0F;
    number.pos.y = 432.0F;
    if (lives_shown >= 0) {
        draw(&number);
    }
    rings = (Sint16)ring_count();
    number.flags = NUMBER_CLAMPED | NUMBER_ZEROS;
    number.max = 999;
    number.value = rings;
    number.pos.x = 46.0F;
    if (stage_group() == STAGE_GROUP_FIELD) {
        number.pos.y = top;
    } else {
        number.pos.y = 57.0F;
    }
    if (rings == 0) {
        fishing_ring_blink += 0x400;
        wave = njSin(fishing_ring_blink);
        glow = 1.0F - (wave * wave);
    } else {
        glow = 1.0F;
    }
    number.color = 0xffc00000;
    green = (int)(glow * 192.0F);
    number.color += (green << 8) + green;
    if (rings_shown <= 0) {
        draw(&number);
    }
}

/* set fishing_distance to the distance from from to to, keep
 * fishing_line_out between it and 5 past it, and draw the line out */
void fishing_measure_line(NJS_POINT3 *from, NJS_POINT3 *to)
{
    Float distance = CalcDistance(from, to);

    fishing_distance = distance;
    if (distance > fishing_line_out) {
        fishing_line_out = distance;
    }
    if (fishing_distance + 5.0F <= fishing_line_out) {
        fishing_line_out = fishing_distance + 5.0F;
    }
    fishing_draw_line_out(fishing_line_out);
}

/* the lure task's draw as it steps: the lure, unless the line snapped.
 * from LURE_FLY on, it draws the line and the hud's reel, gauge and line
 * out too, on each frame's first step. nothing while big_lure is null */
void fishing_lure_show(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    NJS_POINT3 tip;
    NJS_POINT3 end;
    if (big_lure == ((void *)0)) {
        return;
    }
    if (GetPlayerTaskPointer(0)->step != big_step) {
        return;
    }
    fishing_line_end(&end);
    fishing_rod_tip(task, &tip);
    njSetTexture_jp(&fishing_texlist);
    fishing_set_draw();
    if (!(fishing_flags & FISHING_SNAPPED)) {
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
        TURN(njRotateY, -work->ang.y);
        TURN(njRotateX, work->ang.x);
        TURN(njRotateZ, work->ang.z);
        if (work->mode < LURE_FLY) {
            njTranslate(NULL, 0.6F, -0.3F, 0.0F);
        }
        njScale(NULL, 0.3F, 0.3F, 0.3F);
        late_DrawObject(fishing_lures[FUN_8c0e6dc0()]);
        late_DrawObjectClipEx(1);
    }
    if (loop_count == 0) {
        if (work->mode >= LURE_FLY) {
            fishing_line_draw(LURE(task)->line);
        }
        /* @hack spelling: the mode read again through task->work, which the
         * image reloads from task (MOV.L @(32,R13),R2 at 0x8c0f1ec8);
         * through work, 17 of 142 words differ */
        if (task->work->mode >= LURE_FLY) {
            njSetTexture_jp(&fishing_texlist);
#ifdef GCC
            /* 16:9 squeezes the reel, the gauge and the line-out count about
             * the screen's right edge */
            port_wide_anchor = WIDE_RIGHT;
#endif
            fishing_draw_reel();
            fishing_draw_tension();
            fishing_measure_line(&player->pos, &end);
#ifdef GCC
            port_wide_anchor = WIDE_MIDDLE;
#endif
        }
    }
}

/* the lure task's draw: as fishing_lure_show, but it draws while big_lure is
 * null too. it draws the line and the hud on every step of a frame */
void fishing_lure_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    NJS_POINT3 tip;
    NJS_POINT3 end;

    if (GetPlayerTaskPointer(0)->step != big_step) {
        return;
    }
    fishing_line_end(&end);
    fishing_rod_tip(task, &tip);
    njSetTexture_jp(&fishing_texlist);
    fishing_set_draw();
    if (!(fishing_flags & FISHING_SNAPPED)) {
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
        TURN(njRotateY, -work->ang.y);
        TURN(njRotateX, work->ang.x);
        TURN(njRotateZ, work->ang.z);
        if (work->mode < LURE_FLY) {
            njTranslate(NULL, 0.6F, -0.3F, 0.0F);
        }
        njScale(NULL, 0.3F, 0.3F, 0.3F);
        late_DrawObject(fishing_lures[FUN_8c0e6dc0()]);
        late_DrawObjectClipEx(1);
    }
    if (work->mode >= LURE_FLY) {
        fishing_line_draw(LURE(task)->line);
    }
    /* @hack spelling: the mode read again through task->work, which the image
     * reloads from task (MOV.L @(32,R13),R2 at 0x8c0f2046); through work,
     * 24 of 130 words differ */
    if (task->work->mode >= LURE_FLY) {
        njSetTexture_jp(&fishing_texlist);
#ifdef GCC
        port_wide_anchor = WIDE_RIGHT;
#endif
        fishing_draw_reel();
        fishing_draw_tension();
        fishing_measure_line(&player->pos, &end);
#ifdef GCC
        port_wide_anchor = WIDE_MIDDLE;
#endif
    }
}

/* set pos to the rod's tip, from player 0's weld_point4 in his model, turned
 * as he is about his center. the tip lies 16 back along weld_axis4 and 0.6
 * down. with the power rod, it lies 17 back, 1.8 down and 0.6 along z. task
 * goes unused */
void fishing_rod_tip(struct task *task, NJS_POINT3 *pos)
{
    struct player *record = playermwp[0]->record;
    struct task_work *player = playertwp[0];
    NJS_VECTOR point;
    NJS_VECTOR offset;
    Float back;

    njPushMatrix(&nj_unit_matrix_);
    point.x = point.z = 0.0F;
    point.y = record->consts.center_y;
    TURN(njRotateZ, player->ang.z);
    TURN(njRotateX, player->ang.x);
    TURN(njRotateY, 0x8000 - player->ang.y);
    njCalcVector(NULL, &point, pos);
    back = (record->upgrades & PLAYER_BIG_POWER_ROD) ? 17.0F : 16.0F;
    point.x = record->weld_point4.x - (back * record->weld_axis4.x);
    point.y = record->weld_point4.y - (back * record->weld_axis4.y);
    point.z = record->weld_point4.z - (back * record->weld_axis4.z);
    if (record->upgrades & PLAYER_BIG_POWER_ROD) {
        point.y -= 0.6F * 3.0F;
        point.z += 0.6F;
    } else {
        point.y -= 0.6F;
    }
    njCalcVector(NULL, &point, &offset);
    pos->x += player->pos.x + offset.x;
    pos->y += player->pos.y + offset.y;
    pos->z += player->pos.z + offset.z;
    late_DrawObjectClipEx(1);
}

/* fly the lure along its speed, whose y falls 0.02 a step. TRUE, with the lure
 * where it was, when its sweep meets the world. otherwise it moves, and TRUE
 * when its collision hit something */
Bool fishing_lure_fly(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    NJS_POINT3 pos;
    struct angles slope;

    slope.x = slope.y = slope.z = 0;
    motion->speed.y -= 0.02F;
    pos = work->pos;
    if (MSetPosition(&pos, &motion->speed, &slope, 0.5F)) {
        return TRUE;
    }
    VECTOR_ADD(&work->pos, &motion->speed);
    if (work->collision->flags & COLLISION_HIT) {
        return TRUE;
    }
    return FALSE;
}

/* move the lure toward the rod's tip, 10 a step as LURE_BACK, else 2.
 * TRUE once it lies within 5 of the tip on each axis */
Bool fishing_lure_return(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    NJS_POINT3 tip;
    Float speed;

    fishing_rod_tip(task, &tip);
    motion->speed.x = tip.x - work->pos.x;
    motion->speed.y = tip.y - work->pos.y;
    motion->speed.z = tip.z - work->pos.z;
    njUnitVector(&motion->speed);
    speed = (work->mode == LURE_BACK) ? 10.0F : 2.0F;
    work->pos.x += motion->speed.x * speed;
    work->pos.y += motion->speed.y * speed;
    work->pos.z += motion->speed.z * speed;
    if (work->pos.x + 5.0F > tip.x && tip.x > work->pos.x - 5.0F &&
        work->pos.y + 5.0F > tip.y && tip.y > work->pos.y - 5.0F &&
        work->pos.z + 5.0F > tip.z && tip.z > work->pos.z - 5.0F) {
        return TRUE;
    }
    return FALSE;
}

/* TRUE when pos lies within 20 of tip in x and z, and at Ice Cap's pond,
 * less than 10 under the water */
Bool fishing_lure_at_rod(NJS_POINT3 *tip, NJS_POINT3 *pos)
{
    NJS_VECTOR away;

    away.x = tip->x - pos->x;
    away.z = tip->z - pos->z;
    away.y = 0.0F;
    if (GetStageNumber() == ICECAP_POND) {
        if (njScalor(&away) < 20.0F && pos->y > fishing_water - 10.0F) {
            return TRUE;
        }
    } else {
        if (njScalor(&away) < 20.0F) {
            return TRUE;
        }
    }
    return FALSE;
}

/* slow the lure in x and z, by 0.05 a step to a stop. with a fish on, it
 * sinks 0.05 a step, and at random one step in five rises 0.05. with none,
 * it sinks 0.005 a step faster, to 0.05 a step, or 0.1 at Ice Cap's pond.
 * on the bottom, it neither sinks nor rises. the reel's sound stops */
void setLureSpd_D(struct task *task)
{
    struct task_motion *motion = task->motion;

    if (motion->speed.x > 0.0F) {
        motion->speed.x -= 0.05F;
    }
    if (motion->speed.x < 0.0F) {
        motion->speed.x += 0.05F;
    }
    if (motion->speed.x < 0.1F && motion->speed.x > -0.1F) {
        motion->speed.x = 0.0F;
    }
    if (motion->speed.z > 0.0F) {
        motion->speed.z -= 0.05F;
    }
    if (motion->speed.z < 0.0F) {
        motion->speed.z += 0.05F;
    }
    if (motion->speed.z < 0.1F && motion->speed.z > -0.1F) {
        motion->speed.z = 0.0F;
    }
    if (fishing_flags & FISHING_HOOKED) {
        if (fishing_flags & FISHING_BOTTOM) {
            motion->speed.y = 0.1F;
        } else if (rand() * RAND_SCALE < 0.8F) {
            motion->speed.y = -0.05F;
        } else {
            motion->speed.y = 0.05F;
        }
    } else {
        motion->speed.y -= 0.005F;
        if (GetStageNumber() == ICECAP_POND) {
            if (motion->speed.y < -0.1F) {
                motion->speed.y = -0.1F;
            }
        } else {
            if (motion->speed.y < -0.05F) {
                motion->speed.y = -0.05F;
            }
        }
    }
    if (fishing_flags & FISHING_BOTTOM) {
        motion->speed.y = 0.0F;
    }
    dsStop_num(SE_REEL);
}

/* reel in 0.1 of line a step, turning the reel 10 degrees, with SE_REEL
 * each half turn. while the line out reaches the lure, the line is slack,
 * and the lure drifts. once the line is taut, the lure comes toward the
 * rod's tip 0.08 a step in x and z. it rises 0.02 a step, or 0.06 at Ice
 * Cap's pond. a hooked fish of weight w scales the 0.08 by 5000 / (w +
 * 5000). where fishing_lure_at_rod holds, the lure leaves the water. on a
 * taut line, a press of an action button twitches the lure */
void setLureSpd_S(struct task *task, NJS_POINT3 *tip)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    Float pace;
    Angle was;

    if (big_lure == NULL) {
        return;
    }
    if (big_catch != NULL && (fishing_flags & FISHING_HOOKED)) {
        pace = 5000.0F / (FISH_MOTION(big_catch)->weight + 5000.0F);
    } else {
        pace = 1.0F;
    }
    fishing_line_out -= 0.1F;
    was = fishing_reel_ang;
    fishing_reel_ang += NJM_DEG_ANG(10);
    if ((was ^ fishing_reel_ang) & 0x8000) {
        dsStop_num(SE_REEL);
        dsPlay_oneshot(SE_REEL, 0, 0, 0);
    }
    if (fishing_distance <= fishing_line_out) {
        setLureSpd_D(task);
        return;
    }
    motion->speed.x = tip->x - work->pos.x;
    motion->speed.z = tip->z - work->pos.z;
    if (fishing_lure_at_rod(tip, &work->pos)) {
        setLureReturn(task);
    }
    njUnitVector(&motion->speed);
    motion->speed.x *= pace * 0.08F;
    motion->speed.z *= pace * 0.08F;
    if (GetStageNumber() == ICECAP_POND) {
        motion->speed.y = 0.06F;
    } else {
        motion->speed.y = 0.02F;
    }
    /* @hack spelling: the aim read through task->motion, which the image
     * reloads from task (MOV.L @(36,R13),R3 at 0x8c0f27aa); through motion,
     * task and work trade R12 and R13, and 33 of 153 words differ */
    work->ang.z = task->motion->aim.z + 0x2000;
    if (PAD_BUTTONS(perG[0].press, pad_action_buttons)) {
        fishing_flags |= FISHING_TWITCH;
    }
}

/* fishing_reel_slow, faster. it reels in 0.2 of line a step and turns the
 * reel 25 degrees. the lure comes 0.2 a step in x and z, and rises 0.06,
 * or 0.18 at Ice Cap's pond. a press of a jump button twitches it */
void fishing_reel_fast(struct task *task, NJS_POINT3 *tip)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    Float pace;
    Angle was;

    if (big_lure == NULL) {
        return;
    }
    if (big_catch != NULL && (fishing_flags & FISHING_HOOKED)) {
        pace = 5000.0F / (FISH_MOTION(big_catch)->weight + 5000.0F);
    } else {
        pace = 1.0F;
    }
    fishing_line_out -= 0.2F;
    was = fishing_reel_ang;
    fishing_reel_ang += NJM_DEG_ANG(25);
    if ((was ^ fishing_reel_ang) & 0x8000) {
        dsStop_num(SE_REEL);
        dsPlay_oneshot(SE_REEL, 0, 0, 0);
    }
    if (fishing_distance <= fishing_line_out) {
        setLureSpd_D(task);
        return;
    }
    motion->speed.x = tip->x - work->pos.x;
    motion->speed.z = tip->z - work->pos.z;
    if (fishing_lure_at_rod(tip, &work->pos)) {
        setLureReturn(task);
    }
    njUnitVector(&motion->speed);
    motion->speed.x *= pace * 0.2F;
    motion->speed.z *= pace * 0.2F;
    if (GetStageNumber() == ICECAP_POND) {
        motion->speed.y = 0.18F;
    } else {
        motion->speed.y = 0.06F;
    }
    /* @hack spelling: the aim read through task->motion, which the image
     * reloads from task (MOV.L @(36,R13),R3 at 0x8c0f294a); through motion,
     * 43 of 153 words differ */
    work->ang.z = task->motion->aim.z + 0x2000;
    if (PAD_BUTTONS(perG[0].press, pad_jump_buttons)) {
        fishing_flags |= FISHING_TWITCH;
    }
}

/* move the lure aside as Big turns the reel with the stick to one side.
 * off is the lure's bearing from him less his heading. a turn to the left
 * moves the lure only while off lies outside 30 to 180 degrees. a turn to
 * the right needs off outside 180 to 330. the line must also be within 5
 * of taut. the lure then moves toward the rod's tip and that side, about
 * 0.5 a step in x and z, and rises 0.04 a step. it turns 0x100 a step, to
 * at most 45 degrees off its aim. frame 15 of his turn twitches it.
 * otherwise the lure drifts, rising at most 0.015 a step with no fish on */
void setLureSpd_Swing(struct task *task, NJS_POINT3 *tip)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    struct player *record = playermwp[0]->record;
    struct task_work *player = playertwp[0];
    NJS_VECTOR side;
    NJS_MATRIX matrix;
    int off;

    if (fishing_line_out <= fishing_distance + 5.0F) {
        VECTOR_DIFF(&motion->speed, tip, &work->pos);
        njUnitVector(&motion->speed);
        motion->speed.x *= 0.5F;
        motion->speed.y *= 0.5F;
        motion->speed.z *= 0.5F;
        /* @hack spelling: the aim here, and the lure's heading in both turns
         * below, read through task, which the image reloads (MOV.L
         * @(36,R13),R4 at 0x8c0f2a30, MOV.L @(32,R13),R2 at 0x8c0f2a7c and
         * 0x8c0f2ba2); through motion and work, 126 of 305 words differ */
        off = (Uint16)(task->motion->aim.y - player->ang.y);
        if (record->anim.action == ACTION_REEL_DOWN_LEFT ||
            record->anim.action == ACTION_REEL_LEFT ||
            record->anim.action == ACTION_FLOAT_REEL_DOWN_LEFT ||
            record->anim.action == ACTION_FLOAT_REEL_LEFT) {
            if (off < NJM_DEG_ANG(30) || off > NJM_DEG_ANG(180)) {
                side.x = 0.0F;
                side.y = 0.0F;
                side.z = 1.0F;
                njUnitMatrix(&matrix);
                TURN_MATRIX(njRotateY, &matrix, -task->work->ang.y);
                njCalcVector(&matrix, &side, &side);
                njAddVector(&motion->speed, &side);
                njUnitVector(&motion->speed);
            } else {
                motion->speed.x = 0.0F;
                motion->speed.z = 0.0F;
                if (motion->speed.y >= 0.02F) {
                    motion->speed.y = 0.02F;
                }
                setLureSpd_D(task);
                return;
            }
            if (work->ang.y - motion->aim.y > -NJM_DEG_ANG(45)) {
                work->ang.y -= 0x100;
            }
        } else if (record->anim.action == ACTION_REEL_DOWN_RIGHT ||
                   record->anim.action == ACTION_REEL_RIGHT ||
                   record->anim.action == ACTION_FLOAT_REEL_DOWN_RIGHT ||
                   record->anim.action == ACTION_FLOAT_REEL_RIGHT) {
            if (off > NJM_DEG_ANG(330) || off < NJM_DEG_ANG(180)) {
                side.x = 0.0F;
                side.y = 0.0F;
                side.z = -1.0F;
                njUnitMatrix(&matrix);
                TURN_MATRIX(njRotateY, &matrix, -task->work->ang.y);
                njCalcVector(&matrix, &side, &side);
                njAddVector(&motion->speed, &side);
                njUnitVector(&motion->speed);
            } else {
                motion->speed.x = 0.0F;
                motion->speed.z = 0.0F;
                if (motion->speed.y >= 0.02F) {
                    motion->speed.y = 0.02F;
                }
                setLureSpd_D(task);
                return;
            }
            if (work->ang.y - motion->aim.y < NJM_DEG_ANG(45)) {
                work->ang.y += 0x100;
            }
        } else {
            motion->speed.x = 0.0F;
            motion->speed.z = 0.0F;
            if (motion->speed.y >= 0.02F) {
                motion->speed.y = 0.02F;
            }
            setLureSpd_D(task);
            return;
        }
    } else {
        if (motion->speed.y >= 0.02F) {
            motion->speed.y = 0.02F;
        }
        setLureSpd_D(task);
        return;
    }
    motion->speed.x *= 0.5F;
    motion->speed.y = 0.04F;
    motion->speed.z *= 0.5F;
    /* @hack spelling: the aim read through task->motion, which the image
     * reloads from task (MOV.L @(36,R13),R3 at 0x8c0f2c78); through motion,
     * 24 of 305 words differ */
    work->ang.z = task->motion->aim.z + 0x1000;
    if (record->anim.frame == 15.0F) {
        fishing_flags |= FISHING_TWITCH;
    }
}

/* what a fish's pull of 0 or more adds to the tension */
/* @hack redundant: EASY_PULL is 0, which the image adds all the same (FLDI0
 * FR12 at 0x8c0f2d0e, FMAC at 0x8c0f2e0e, FADD at 0x8c0f2f1e); with neither
 * addition, 195 of fishing_tension_step's 415 words differ */

/* set fishing_tension_aim from the hooked fish's weight and pull, the
 * buttons held and fishing_strain, and ease fishing_tension toward it. the
 * fish's pull is its speed times the cosine of its heading less the lure's
 * aim, and a negative pull raises the aim. the tension eases on a frame's
 * first step, by 0.02, or by 0.002 once within 0.02 of the aim. at a
 * tension of 1, the line snaps, the music changes, and the hooked fish's
 * weight shows as lost. from 0.8, SE_STRAIN plays every 120 steps. move is
 * the lure's move this step, to which a kick adds the fish's speed */
void CL_ColPolCheckZxNShadow(struct task *task, NJS_VECTOR *move)
{
    struct task_motion *motion = task->motion;
    Float weight;
    Float pull;
    Float speed;
    Float gap;

    if (big_lure != NULL && big_catch != NULL) {
        /* @hack spelling: the weight tested bare, which loads the 0 into
         * FR2 and the weight into FR3 (0x8c0f2d2a, 0x8c0f2d2c); tested as
         * != 0.0F, the two trade and 3 of 415 words differ */
        if (big_catch->motion != NULL && FISH_MOTION(big_catch)->weight) {
            weight = FISH_MOTION(big_catch)->weight;
        } else {
            weight = 1000.0F;
        }
        /* @hack spelling: the product spelled out, which loads 0.001 into
         * FR5 and fishing_strain into FR4 (0x8c0f2d44, 0x8c0f2d52); with *=,
         * the two trade and 19 of 415 words differ */
        weight = weight * 0.0001F;
        if (fishing_flags & FISHING_HOOKED) {
            if (PAD_BUTTONS(pad_action_buttons | pad_jump_buttons,
                            perG[0].on)) {
                fishing_strain += 0.0005F;
            } else if (fishing_strain > 0.0F) {
                fishing_strain -= 0.001F;
            }
            if (fishing_flags & FISHING_PULL) {
                if (fishing_strain > 0.0F) {
                    fishing_strain -= 0.001F;
                }
            }
            /* each arm calls njScalor on move and drops its result (JSR at
             * 0x8c0f2daa and 0x8c0f2ee8) */
            if (fishing_flags & FISHING_KICK) {
                njScalor(move);
                speed = njScalor(&FISH_MOTION(big_catch)->speed);
                pull = speed * njCos(big_catch->work->ang.y - motion->aim.y);
                if (pull < 0.0F) {
                    fishing_tension_aim = (weight * 1.1F) - (pull * 2.1F);
                    fishing_tension_aim +=
                        (0.24F - weight) * rand() * (1.2F * RAND_SCALE);
                } else {
                    fishing_tension_aim = EASY_PULL + (weight * 2.0F);
                }
                if (fishing_tension_aim < 0.5F) {
                    if (perG[0].on & pad_jump_buttons) {
                        fishing_tension_aim += 0.5F;
                    } else if (perG[0].on & pad_action_buttons) {
                        fishing_tension_aim += 0.3F;
                    }
                }
                fishing_tension_aim += fishing_strain;
                if (fishing_fight_steps > 1800 && fishing_tension_aim > 0.8F) {
                    fishing_tension_aim -= 0.1F;
                }
                njAddVector(move, &FISH_MOTION(big_catch)->speed);
            } else {
                njScalor(move);
                speed = njScalor(&FISH_MOTION(big_catch)->speed);
                pull = speed * njCos(big_catch->work->ang.y - motion->aim.y);
                if (pull < 0.0F) {
                    weight -= pull * 2.0F;
                } else {
                    weight += EASY_PULL;
                }
                fishing_tension_aim = weight;
                if (fishing_tension_aim < 0.5F) {
                    if (perG[0].on & pad_jump_buttons) {
                        fishing_tension_aim += 0.5F;
                    } else if (perG[0].on & pad_action_buttons) {
                        fishing_tension_aim += 0.3F;
                    }
                }
                fishing_tension_aim += fishing_strain;
            }
        } else {
            if (fishing_strain > 0.0F) {
                fishing_strain -= 0.001F;
            }
            if (fishing_flags & FISHING_PULL) {
                fishing_tension_aim = 0.1F;
            } else {
                fishing_tension_aim = 0.2F;
            }
        }
    } else {
        fishing_tension_aim = 0.1F;
    }
    fishing_tension_aim += rand() * (0.1F * RAND_SCALE);
    if (loop_count == 0) {
        if (fishing_tension_aim != fishing_tension) {
            gap = fishing_tension_aim - fishing_tension;
            if (gap > 0.02F) {
                fishing_tension += 0.02F;
            } else if (gap < -0.02F) {
                fishing_tension -= 0.02F;
            } else if (gap > 0.002F) {
                fishing_tension += 0.002F;
            } else if (gap < -0.002F) {
                fishing_tension -= 0.002F;
            } else {
                fishing_tension = fishing_tension_aim;
            }
        }
        if (fishing_tension < 0.0F) {
            fishing_tension = 0.0F;
        } else if (fishing_tension >= 1.0F) {
            fishing_tension = 1.0F;
            if (big_lure != NULL) {
                fishing_flags |= FISHING_SNAPPED;
                stream_request_interlude(MUSIC_FISHMISS);
                if (big_catch != NULL) {
                    fishing_show_catch(FISH_MOTION(big_catch)->weight,
                                       CATCH_SNAPPED);
                }
            }
        }
    }
    if (fishing_warn_steps) {
        fishing_warn_steps--;
    }
    if (fishing_tension >= 0.8F) {
        if (!fishing_warn_steps) {
            dsPlay_oneshot(SE_STRAIN, 0, 0, 0);
            fishing_warn_steps = 120;
        }
    } else {
        dsStop_num(SE_STRAIN);
    }
}

/* TRUE while the fish pulls the lure: whenever it kicks, and while it's
 * hooked with no reel button held, unless Big pulls the rod aside. FALSE
 * while big_lure is null */
Bool fishing_fish_pulls(struct task *task)
{
    if (big_lure == NULL) {
        return FALSE;
    }
    if (fishing_flags & FISHING_KICK) {
        return TRUE;
    }
    if (fishing_flags & FISHING_PULL) {
        return FALSE;
    }
    if ((fishing_flags & FISHING_HOOKED) &&
        PAD_BUTTONS(perG[0].off, pad_action_buttons) ==
            (Sint32)pad_action_buttons &&
        (perG[0].off & pad_jump_buttons) == pad_jump_buttons) {
        return TRUE;
    }
    return FALSE;
}

/* TRUE at Ice Cap's pond while fishing_cast_pos lies within 70 of one of
 * the first PENS of fishing_pens */
Bool fishing_in_pen(void)
{
    int i;

    if (GetStageNumber() != ICECAP_POND) {
        return FALSE;
    }
    for (i = 0; i < PENS; i++) {
        if (CalcDistance(&fishing_pens[i], &fishing_cast_pos) < 70.0F) {
            break;
        }
    }
    if (i == PENS) {
        return FALSE;
    }
    return TRUE;
}

/* move the lure in the water for a step: by the pulling fish's speed, or
 * else by the reels or the rod's pull. it stays between the bottom and the
 * water's top, and the line's tension follows. a pulling fish gets away 300
 * from Big, or 400 with the power rod. the lure leaves the water under a
 * surface within 2 of the water's top, outside a pen. with no fish pulling,
 * it also leaves at the top against an upright surface. it stays at Emerald
 * Coast, or while Big pulls the rod aside */
void fishing_lure_swim(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    struct player *record = playermwp[0]->record;
    NJS_POINT3 tip;
    NJS_POINT3 pos;
    NJS_VECTOR move;
    struct near_surfaces info;
    struct angles wall_slope;
    struct angles floor_slope;
    Float radius;
    Float depth;
    Float length;
    Bool wall;
    Bool floor;
    int buttons;

    if (fishing_flags & FISHING_HOOKED) {
        radius = 5.5F;
    } else {
        radius = 0.5F;
    }
    fishing_find_surfaces_at(work, SKIP_WATER_BELOW | SKIP_WATER_ABOVE, &info);
    if (info.water.height == GROUND_FAR) {
        info.water.height = fishing_water;
    } else {
        fishing_water = info.water.height;
    }
    /* @hack spelling: depth set inside the test, which keeps it in the frame
     * (FMOV.S FR2,@(R0,R15) at 0x8c0f3314); set ahead of the test, the
     * frame shrinks by 4 bytes and 244 of 631 words differ */
    if ((depth = info.above.height - info.water.height) < 2.0F &&
        depth > -2.0F && !fishing_in_pen()) {
        work->pos.y = info.above.height;
        setLureReturn(task);
        return;
    }
    if (fishing_fish_pulls(task)) {
        if (big_catch == NULL) {
            return;
        }
        move = FISH_MOTION(big_catch)->speed;
        wall_slope.x = wall_slope.y = wall_slope.z = 0;
        pos = work->pos;
        wall = MSetPosition(&pos, &move, &wall_slope, radius);
        floor_slope.x = floor_slope.y = floor_slope.z = 0;
        pos = work->pos;
        floor = fishing_sweep(&pos, &move, &floor_slope, radius);
        /* @hack spelling: the four tests joined by &, which calls
         * fishing_upright for both slopes whatever the sweeps found (JSR at
         * 0x8c0f33d4 and 0x8c0f33e0). each test gives TRUE or FALSE, and
         * fishing_upright changes nothing but its own locals, so & gives what
         * && does. with &&, fishing.c's code runs 32 bytes longer and 522 of
         * 631 words differ */
        if (wall & floor & fishing_upright(NULL, &floor_slope) &
            fishing_upright(NULL, &wall_slope)) {
            move.x = move.z = 0.0F;
            move.y *= 3.0F;
        }
        if (work->pos.y + move.y > info.water.height - radius - 0.1F &&
            !fishing_upright(task, &wall_slope)) {
            move.y = 0.0F;
            work->pos.y = info.water.height - radius - 0.1F;
        }
        if (work->pos.y + move.y <= info.below.height + radius) {
            length = njScalor(&move);
            if (work->pos.y != info.water.height - radius - 0.1F) {
                work->pos.y = info.below.height + radius;
                if (length <= 0.03F) {
                    move.x = move.y = move.z = 0.0F;
                }
            } else {
                move.x = move.y = move.z = 0.0F;
            }
        }
        motion->speed = move;
        work->pos.x += move.x;
        work->pos.y += move.y;
        work->pos.z += move.z;
        CL_ColPolCheckZxNShadow(task, &move);
        if (record->upgrades & PLAYER_BIG_POWER_ROD) {
            if (fishing_distance > 400.0F) {
                fishing_flags |= FISHING_LOST;
            }
        } else {
            if (fishing_distance > 300.0F) {
                fishing_flags |= FISHING_LOST;
            }
        }
    } else {
        fishing_rod_tip(task, &tip);
        if (big_lure != NULL && (fishing_flags & FISHING_PULL)) {
            setLureSpd_Swing(task, &tip);
        } else {
            buttons = 0;
            if (perG[0].on & pad_action_buttons) {
                buttons = HELD_ACTION;
            }
            if (PAD_BUTTONS(perG[0].on, pad_jump_buttons)) {
                buttons |= HELD_JUMP;
            }
            switch (buttons) {
            case HELD_ACTION:
                setLureSpd_S(task, &tip);
                break;
            case HELD_JUMP:
            case HELD_ACTION | HELD_JUMP:
                fishing_reel_fast(task, &tip);
                break;
            default:
                dsStop_num(SE_REEL);
                setLureSpd_D(task);
                break;
            }
        }
        move = motion->speed;
        wall_slope.x = wall_slope.y = wall_slope.z = 0;
        pos = work->pos;
        wall = MSetPosition(&pos, &move, &wall_slope, radius);
        if (GetStageNumber() == ICECAP_POND && wall_slope.x == 0 &&
            wall_slope.z == 0x8000) {
            wall = FALSE;
            move.y = motion->speed.y;
        }
        floor_slope.x = floor_slope.y = floor_slope.z = 0;
        pos = work->pos;
        floor = fishing_sweep(&pos, &move, &floor_slope, radius);
        /* @hack spelling: the four tests joined by &, as in the arm above (JSR
         * at 0x8c0f36be and 0x8c0f36ca). as there, & gives what && does. with
         * &&, 201 of 631 words differ */
        if (wall & floor & fishing_upright(NULL, &floor_slope) &
            fishing_upright(NULL, &wall_slope)) {
            move.x = move.z = 0.0F;
            move.y *= 3.0F;
        }
        if (work->pos.y + move.y > info.water.height - radius - 0.1F) {
            if (!(fishing_upright(task, &wall_slope) ||
                  fishing_upright(task, &floor_slope)) ||
                IN_STAGE(STAGE_BEACH) || (fishing_flags & FISHING_PULL)) {
                move.y = 0.0F;
                work->pos.y = info.water.height - radius - 0.1F;
                motion->speed.y = 0.0F;
            } else {
                setLureReturn(task);
                return;
            }
        }
        if (work->pos.y + move.y <= info.below.height + radius) {
            length = njScalor(&move);
            work->pos.y = info.below.height + radius;
            if (big_lure != NULL) {
                fishing_flags |= FISHING_BOTTOM;
                if (!(fishing_flags & FISHING_SPLASH) && length >= 0.15F) {
                    fishing_splash_create(task);
                    dsPlay_oneshot(SE_LURE_BOTTOM, 0, 0, 0);
                    fishing_flags |= FISHING_SPLASH;
                }
                if (length <= 0.03F) {
                    move.x = move.y = move.z = 0.0F;
                }
            }
        }
        work->pos.x += move.x;
        work->pos.y += move.y;
        work->pos.z += move.z;
        CL_ColPolCheckZxNShadow(task, &move);
        fishing_tension_aim += rand() * (0.1F * RAND_SCALE);
        if (work->pos.y > info.water.height - radius) {
            setLureReturn(task);
        }
    }
}

/* hang the lure from the rod's tip, facing as player 0 does, and rock it.
 * about x, it turns 0x200 a step, and back each time it passes 0x6000 or
 * 0xa000. about z, it turns 0x80 a step, and back past 0x3000 or 0x5000 */
void fishing_lure_dangle(struct task *task, NJS_POINT3 *tip)
{
    Angle ang;
    Angle aim;
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];

    work->pos = *tip;
    work->ang.y = task->motion->aim.y = player->ang.y;
    /* @hack spelling: the turns read and stored through task->work, which the
     * image reloads from task (MOV.L @(32,R4),R5 at 0x8c0f38fc); through work,
     * which it holds in R6 from 0x8c0f38e2, 82 of 90 words differ */
    ang = task->work->ang.x;
    aim = task->motion->aim.x;
    if (ang < 0x5800 || ang > 0xa800) {
        ang = 0x5800;
    }
    if (ang < 0x6000 && ang > 0x5000) {
        aim = 0xa000;
    }
    if (ang > 0xa000 && ang < 0xb000) {
        aim = 0x6000;
    }
    if (aim < 0x8000) {
        ang = (Uint16)(ang - 0x200);
    } else {
        ang = (Uint16)(ang + 0x200);
    }
    task->motion->aim.x = aim;
    task->work->ang.x = ang;
    ang = task->work->ang.z;
    aim = task->motion->aim.z;
    if (ang < 0x2800 || ang > 0x5800) {
        ang = 0x5800;
    }
    if (ang < 0x3000 && ang > 0x2000) {
        aim = 0x5000;
    }
    if (ang > 0x5000 && ang < 0x6000) {
        aim = 0x3000;
    }
    if (aim < 0x4000) {
        ang = (Uint16)(ang - 0x80);
    } else {
        ang = (Uint16)(ang + 0x80);
    }
    task->motion->aim.z = aim;
    task->work->ang.z = ang;
}

/* put the lure back on the rod as LURE_DANGLE, with no line out and no tension,
 * and the reel at rest. the music comes back if a fish was hooked */
void fishing_lure_reset(struct task *task)
{
    struct task_work *work = task->work;
    struct lure_extra *extra = task->extra;

    work->mode = LURE_DANGLE;
    extra->sway[SWAY_PHASE] = 0;
    extra->sway[SWAY_ROLL] = 0;
    fishing_tension_aim = fishing_tension = 0.0F;
    fishing_reel_ang = 0;
    fishing_line_out = 0.0F;
    fishing_distance = 0.0F;
    if (fishing_flags & FISHING_HOOKED) {
        CameraFishingCatch();
    }
    dsStop_num(SE_REEL);
}

/* take the lure out of the water. a hooked fish within 150 of player 0
 * comes with it, as LURE_CATCH, and the camera looks at Big. a fish
 * further off is killed, and the lure comes back empty as LURE_BACK, as
 * with no fish, with the camera on it. at Hot Shelter, the camera looks at
 * Big either way. nothing in a field */
void setLureReturn(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];

    if (stage_group() == STAGE_GROUP_FIELD) {
        return;
    }
    dsStop_num(SE_REEL);
    if (big_lure != NULL) {
        fishing_flags &= ~FISHING_CAMERA;
        if (work->mode <= LURE_LANDED) {
            CameraReleaseEventCamera();
        } else {
            camera_restore_high();
        }
        if (fishing_flags & FISHING_HOOKED) {
            CameraFishingCatch();
            if (CalcDistance(&work->pos, &player->pos) < 50.0F) {
                work->mode = LURE_CATCH;
                CameraSetEventCameraFunc(fishing_camera_step_point, 0,
                                         CAMERA_LOOK_AT);
                fishing_look_at_big(task);
            } else {
                work->mode = LURE_BACK;
                if (big_catch != NULL) {
                    FreeTask(big_catch);
                }
                big_catch = NULL;
                fishing_flags &=
                    ~(FISHING_HOOKED | FISHING_LOST | FISHING_KICK);
                if (IN_STAGE(STAGE_SHELTER)) {
                    CameraSetEventCameraFunc(fishing_camera_step_point, 0,
                                             CAMERA_LOOK_AT);
                    fishing_look_at_big(task);
                } else {
                    CameraSetEventCameraFunc(camera_step_fishing_point, 0,
                                             CAMERA_LOOK_AT);
                    fishing_look_at_lure(task);
                }
            }
        } else {
            work->mode = LURE_BACK;
            if (IN_STAGE(STAGE_SHELTER)) {
                CameraSetEventCameraFunc(fishing_camera_step_point, 0,
                                         CAMERA_LOOK_AT);
                fishing_look_at_big(task);
            } else {
                CameraSetEventCameraFunc(camera_step_fishing_point, 0,
                                         CAMERA_LOOK_AT);
                fishing_look_at_lure(task);
            }
        }
    }
}

/* TRUE when the surface below or above the lure, as info gives them, is
 * water, and the lure's collision hit nothing */
Bool fishing_lure_in_water(struct task *task, struct near_surfaces *info)
{
    if ((!(info->below.flags & WORLD_WATER) &&
         !(info->above.flags & WORLD_WATER)) ||
        (task->work->collision->flags & COLLISION_HIT)) {
        return FALSE;
    }
    return TRUE;
}

/* TRUE when big_catch is the plug of Hot Shelter, which stands at (750,
 * 75.5, -650). it then sets FISHING_SHELTER_PLUG. FALSE otherwise */
Bool fishing_mark_shelter_plug(void)
{
    if (big_catch != NULL && IN_STAGE(STAGE_SHELTER) &&
        big_catch->work->pos.x == 750.0F && big_catch->work->pos.y == 75.5F &&
        big_catch->work->pos.z == -650.0F) {
        fishing_flags |= FISHING_SHELTER_PLUG;
        return TRUE;
    }
    return FALSE;
}

/* the lure task's step, by its lure_mode. each step, the lure rocks, and
 * FISHING_TWITCH and FISHING_BOTTOM clear */
void fishing_lure_step(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack spelling: the goal read through extra in the cast and the flight,
     * which the image keeps in R9 (MOV.L @(44,R14),R9 at 0x8c0f3cda), and
     * the rest through LURE(task), which it reloads from task (MOV.L
     * @(44,R14),R2 at 0x8c0f3dd6); through extra alone, 741 of 814 words
     * differ */
    struct lure_extra *extra = task->extra;
    struct task_motion *motion = task->motion;
    struct player *record = playermwp[0]->record;
    NJS_VECTOR away;
    struct near_surfaces info;
    NJS_POINT3 tip;
    NJS_POINT3 end;
    Float distance;
    Float steps;
    int kind;

    fishing_rod_tip(task, &tip);
    if (work->mode != LURE_INIT) {
        fishing_lure_sway(task);
    }
    if (big_lure != NULL) {
        fishing_flags &= ~(FISHING_TWITCH | FISHING_BOTTOM);
    }
    switch (work->mode) {
    case LURE_INIT:
        fishing_lure_reset(task);
        task->destructor = fishing_lure_destroy;
        task->draw = fishing_lure_draw;
        break;
    case LURE_DANGLE:
        fishing_lure_dangle(task, &tip);
        fishing_lure_show(task);
        if (big_lure != NULL && (fishing_flags & FISHING_CAST)) {
            fishing_flags &= ~FISHING_CAST;
            work->mode = LURE_WAIT;
            LURE(task)->goal->x = BIG_TARGET(record)->work->pos.x;
            LURE(task)->goal->y = TARGET(BIG_TARGET(record))->ground;
            LURE(task)->goal->z = BIG_TARGET(record)->work->pos.z;
            FreeTask(BIG_TARGET(record));
            LURE_VARS(work)->steps = 10;
            fishing_flags = 0;
        }
        break;
    case LURE_WAIT:
        fishing_lure_dangle(task, &tip);
        fishing_lure_show(task);
        if (--LURE_VARS(work)->steps) {
            break;
        }
        away.x = extra->goal->x - work->pos.x;
        away.y = 0.0F;
        away.z = extra->goal->z - work->pos.z;
        distance = njScalor(&away);
        steps = distance * (1.0F / CAST_SPEED);
        CCL_Init(task, fishing_lure_shapes, COLLISION_ATTACK, 1, 1);
        work->mode = LURE_FLY;
        motion->speed.x = away.x / steps;
        motion->speed.z = away.z / steps;
        motion->speed.y =
            ((extra->goal->y - work->pos.y) / steps) + (steps * 0.01F);
        motion->aim.x = 0;
        work->ang.z = 0;
        fishing_line_end(&end);
        if (LURE(task)->line != NULL) {
            fishing_line_reset(LURE(task)->line, &tip, &end);
        }
        dsPlay_oneshot(SE_CAST, 0, 0, 0);
        dsPlay_oneshot(SE_CAST_SWING, 0, 0, 0);
        break;
    case LURE_FLY:
        LURE_VARS(work)->steps++;
        if (fishing_lure_fly(task)) {
            fishing_find_surfaces_at(work, 0, &info);
            if (!fishing_lure_in_water(task, &info)) {
                if (big_lure != NULL) {
                    fishing_flags &= ~FISHING_CAMERA;
                }
                work->mode = LURE_BACK;
                dsPlay_oneshot(SE_LURE_GROUND, 0, 0, 0);
            } else {
                work->mode = LURE_LANDED;
                work->pos.x = extra->goal->x;
                work->pos.y = info.water.height - 0.6F;
                work->pos.z = extra->goal->z;
                /* @hack redundant: a goto where the else ends anyway, which
                 * loads njDistanceP2P's address into R3 for the else-if's call
                 * (MOV.L at 0x8c0f3fe0); without it, R2 takes it and 2 of
                 * 814 words differ */
                goto flown;
            }
        } else if (CalcDistance(extra->goal, &work->pos) < 3.0F) {
            work->mode = LURE_LANDED;
            VECTOR_COPY(&work->pos, extra->goal);
            fishing_find_surfaces_at(work, 0, &info);
            if (!fishing_lure_in_water(task, &info)) {
                if (big_lure != NULL) {
                    fishing_flags &= ~FISHING_CAMERA;
                }
                work->mode = LURE_BACK;
                dsPlay_oneshot(SE_LURE_GROUND, 0, 0, 0);
            } else {
                work->pos.y = info.water.height - 0.6F;
            }
        }
    flown:
        fishing_line_end(&end);
        if (LURE(task)->line != NULL) {
            String_Exe(LURE(task)->line, &tip, &end, FISHING_LINE_SLACK);
        }
        fishing_lure_show(task);
        EntryColliList(work);
        break;
    case LURE_BACK:
    case LURE_CATCH:
        if (fishing_lure_return(task)) {
            fishing_lure_home(task);
        } else {
            fishing_line_end(&end);
            if (LURE(task)->line != NULL) {
                String_Exe(LURE(task)->line, &tip, &end, FISHING_LINE_TAUT);
            }
            fishing_lure_show(task);
        }
        break;
    case LURE_LANDED:
        if (stage_group() != STAGE_GROUP_FIELD) {
            fishing_cast_pos = work->pos;
        }
        work->pos.y -= 0.5001F;
        work->mode = LURE_IN_WATER;
        fishing_lure_camera(task);
        fishing_lure_swim(task);
        fishing_line_end(&end);
        if (LURE(task)->line != NULL) {
            String_Exe(LURE(task)->line, &tip, &end, FISHING_LINE_SLACK);
        }
        fishing_lure_show(task);
        if (stage_group() == STAGE_GROUP_FIELD) {
            if (CalcDistance(&playertwp[0]->pos, &fishing_cast_pos) > 20.0F &&
                (kind = fishing_give_prize()) > 0) {
                FUN_8c05e038(kind);
                fishing_cast_pos = playertwp[0]->pos;
            }
            fishing_flags &= ~FISHING_CAMERA;
            work->mode = LURE_BACK;
            CameraReleaseEventCamera();
        } else if (ChkFishingThrowNow(task)) {
            fishing_lure_reset(task);
        } else if (fishing_lure_at_rod(&tip, &work->pos)) {
            fishing_flags &= ~FISHING_CAMERA;
            work->mode = LURE_BACK;
        } else if (work->mode == LURE_IN_WATER) {
            if (big_lure != NULL) {
                fishing_flags |= FISHING_CAMERA;
            }
            fishing_cast_pos = work->pos;
            fishing_line_out = fishing_distance;
            VECTOR_SCALE(&motion->speed, &motion->speed, 0.25F);
            /* @hack spelling: the turn cleared through task->work, which has
             * the store share R0's 0 with sound_play's arguments (MOV #0,R0 at
             * 0x8c0f42a8, MOV.L @(32,R14),R3 at 0x8c0f42aa); through work,
             * the 0 takes R3, and 24 of 814 words differ */
            task->work->ang.x = 0;
            dsPlay_oneshot(SE_LURE_WATER, 0, 0, 0);
            CameraReleaseEventCamera();
            CameraSetCollisionCameraFunc(fishing_camera_step_lure, 0,
                                         CAMERA_LOOK_AT);
        }
        break;
    case LURE_IN_WATER:
        fishing_lure_camera(task);
        fishing_lure_swim(task);
        fishing_lure_pitch(task);
        fishing_lure_yaw(task);
        moveFishingRotZ(task);
        fishing_line_end(&end);
        if (LURE(task)->line != NULL) {
            String_Exe(LURE(task)->line, &tip, &end, FISHING_LINE_TAUT);
        }
        fishing_lure_show(task);
        if (TRIGGER_AXIS(perG[0].l) > PAD_DEAD_ZONE - 0x8000 &&
            TRIGGER_AXIS(perG[0].r) > PAD_DEAD_ZONE - 0x8000 &&
            !(fishing_flags & FISHING_HOOKED)) {
            fishing_flags |= FISHING_GIVE_UP;
            camera_restore_high();
            if (IN_STAGE(STAGE_SHELTER)) {
                CameraSetEventCameraFunc(fishing_camera_step_point, 0,
                                         CAMERA_LOOK_AT);
                fishing_look_at_big(task);
            } else {
                CameraSetEventCameraFunc(camera_step_fishing_point, 0,
                                         CAMERA_LOOK_AT);
                fishing_look_at_lure(task);
            }
        }
        if ((fishing_flags & FISHING_SHELTER_PLUG) && IN_STAGE(STAGE_SHELTER) &&
            !(fishing_flags & FISHING_HOOKED)) {
            fishing_flags |= FISHING_GIVE_UP;
            camera_restore_high();
            if (IN_STAGE(STAGE_SHELTER)) {
                CameraSetEventCameraFunc(fishing_camera_step_point, 0,
                                         CAMERA_LOOK_AT);
                fishing_look_at_big(task);
            } else {
                CameraSetEventCameraFunc(camera_step_fishing_point, 0,
                                         CAMERA_LOOK_AT);
                fishing_look_at_lure(task);
            }
            fishing_flags &= ~FISHING_SHELTER_PLUG;
        }
        if (fishing_flags & FISHING_GIVE_UP) {
            if (big_lure != NULL) {
                fishing_flags &= ~FISHING_CAMERA;
                work->mode = LURE_BACK;
                dsStop_num(SE_REEL);
            }
        } else if (ChkFishingThrowNow(task)) {
            fishing_lure_reset(task);
        } else if (big_lure != NULL && (fishing_flags & FISHING_HOOKED)) {
            work->mode = LURE_FISH;
            fishing_mark_shelter_plug();
        }
        break;
    case LURE_FISH:
        fishing_lure_camera(task);
        fishing_lure_swim(task);
        fishing_lure_pitch(task);
        fishing_lure_yaw(task);
        moveFishingRotZ(task);
        fishing_line_end(&end);
        if (LURE(task)->line != NULL) {
            String_Exe(LURE(task)->line, &tip, &end, FISHING_LINE_TAUT);
        }
        fishing_lure_show(task);
        if (big_lure != ((void *)0) && !(fishing_flags & 0x1)) {
            if (work->mode == LURE_FISH) {
                work->mode = LURE_IN_WATER;
            }
            CameraFishingCatch();
        } else if (ChkFishingThrowNow(task)) {
            fishing_lure_reset(task);
        }
        break;
    }
}

/* the lure is home: Big's fishing ends, and the lure goes back on the rod.
 * with a fish hooked, FISHING_LANDED sets, and the camera looks at Big */
void fishing_lure_home(struct task *task)
{
    struct player *record = playermwp[0]->record;

    BIG_FLAGS(record) |= BIG_FISHING_OVER;
    if (big_lure != NULL) {
        fishing_flags &= ~FISHING_CAMERA;
        if (big_catch != NULL && (fishing_flags & FISHING_HOOKED)) {
            CameraReleaseEventCamera();
            CameraSetEventCameraFunc(fishing_camera_step_point, 0,
                                     CAMERA_LOOK_AT);
            fishing_flags |= FISHING_LANDED;
            fishing_look_at_big(task);
        }
    }
    fishing_lure_reset(task);
}

/* fill info with the surfaces nearest (x, y, z) among the world's objects
 * within 25 of it, and return below's height. skip leaves water out of above
 * or below. an object a task owns counts only while the point lies within its
 * model's radius, times its largest scale, in x and z. the speed.y of that
 * task's force raises the object's surfaces. world_objects keeps the objects
 * it listed */
Float calcFishingCursorY(Float x, Float y, Float z, int skip,
                         struct near_surfaces *info)
{
    struct height_query query;
    NJS_VECTOR away;
    Angle above_ang_x;
    Angle above_ang_z;
    Sint32 above_flags;
    Angle below_ang_x;
    Angle below_ang_z;
    Sint32 below_flags;
    struct world_object *objects;
    NJS_OBJECT *object;
    Uint16 i;
    Float above;
    Float below;
    /* NOLINTNEXTLINE(clang-diagnostic-unused-but-set-variable) */
    Float height;

    query.pos.x = x;
    query.pos.y = y;
    query.pos.z = z;
    below = -GROUND_FAR;
    below_flags = 0;
    below_ang_z = 0;
    below_ang_x = 0;
    above_flags = 0;
    above_ang_z = 0;
    above_ang_x = 0;
    above = info->water.height = GROUND_FAR;
    info->water.flags = info->water.ang_z = info->water.ang_x = 0;
    objects = numLandCollList;
    ListGroundForCollision(x, y, z, 25.0F);
    for (i = 0; i < LandCollList; i++) {
        object = objects[i].object;
        if (objects[i].owner != NULL) {
            Float size;
            Float distance;
            Float reach;

            away.x = object->pos[0] - x;
            away.y = 0.0F;
            away.z = object->pos[2] - z;
            distance = njScalor(&away);
            size = object->scl[0];
            if (object->scl[1] > size) {
                size = object->scl[1];
            }
            if (object->scl[2] > size) {
                size = object->scl[2];
            }
            reach = size * object->model->r;
            if (distance > reach) {
                continue;
            }
        }
        if (polygon_find_heights(&query, objects[i].object, objects[i].flags)) {
            if (objects[i].owner != NULL && objects[i].owner->force != NULL) {
                query.above.level +=
                    ((struct task_force *)objects[i].owner->force)->speed.y;
                query.below.level +=
                    ((struct task_force *)objects[i].owner->force)->speed.y;
            }
            /* @hack redundant: a store to height, which nothing reads, that
             * keeps above_flags at @(20,R15) and below_flags at @(24,R15), as
             * their reads at 0x8c0f4898 and 0x8c0f48a2 show; without it, the
             * two trade and 8 of 311 words differ */
            /* @hack redundant: the select on the constant 1.0F, which picks
             * below; without it, 8 of 311 words differ */
            height = 1.0F ? below : query.below.level;
            if (query.above.found == TRUE && query.pos.y < query.above.level &&
                above > query.above.level) {
                if (objects[i].flags & WORLD_WATER) {
                    if (_builtin_fabsf(query.above.level - query.pos.y) <
                        _builtin_fabsf(info->water.height - query.pos.y)) {
                        info->water.height = query.above.level;
                        info->water.ang_x = query.above.ang_x;
                        info->water.ang_z = query.above.ang_z;
                        info->water.flags = objects[i].flags;
                    }
                    if (!(skip & SKIP_WATER_ABOVE)) {
                        above = query.above.level;
                        above_ang_x = query.above.ang_x;
                        above_ang_z = query.above.ang_z;
                        above_flags = objects[i].flags;
                    }
                } else {
                    above = query.above.level;
                    above_ang_x = query.above.ang_x;
                    above_ang_z = query.above.ang_z;
                    above_flags = objects[i].flags;
                }
            }
            if (query.below.found == TRUE && query.pos.y >= query.below.level &&
                query.below.level > below) {
                if (objects[i].flags & WORLD_WATER) {
                    if (_builtin_fabsf(query.below.level - query.pos.y) <
                        _builtin_fabsf(info->water.height - query.pos.y)) {
                        info->water.height = query.below.level;
                        info->water.ang_x = query.below.ang_x;
                        info->water.ang_z = query.below.ang_z;
                        info->water.flags = objects[i].flags;
                    }
                    if (!(skip & SKIP_WATER_BELOW)) {
                        below = query.below.level;
                        below_ang_x = query.below.ang_x;
                        below_ang_z = query.below.ang_z;
                        below_flags = objects[i].flags;
                    }
                } else {
                    below = query.below.level;
                    below_ang_x = query.below.ang_x;
                    below_ang_z = query.below.ang_z;
                    below_flags = objects[i].flags;
                }
            }
        }
    }
    info->above.height = above;
    info->above.ang_x = above_ang_x;
    info->above.ang_z = above_ang_z;
    info->above.flags = above_flags;
    info->below.height = below;
    info->below.ang_x = below_ang_x;
    info->below.ang_z = below_ang_z;
    info->below.flags = below_flags;
    return below;
}

/* fishing_find_surfaces, at the work's pos */
Float fishing_find_surfaces_at(struct task_work *work, int skip,
                               struct near_surfaces *info)
{
    struct height_query query;
    NJS_VECTOR away;
    Angle above_ang_x;
    Angle above_ang_z;
    Sint32 above_flags;
    Angle below_ang_x;
    Angle below_ang_z;
    Sint32 below_flags;
    struct world_object *objects;
    NJS_OBJECT *object;
    Uint16 i;
    Float above;
    Float below;
    Float x;
    Float y;
    Float z;
    /* NOLINTNEXTLINE(clang-diagnostic-unused-but-set-variable) */
    Float height;

    x = work->pos.x;
    y = work->pos.y;
    z = work->pos.z;
    query.pos.x = x;
    query.pos.y = y;
    query.pos.z = z;
    below = -GROUND_FAR;
    below_flags = 0;
    below_ang_z = 0;
    below_ang_x = 0;
    above_flags = 0;
    above_ang_z = 0;
    above_ang_x = 0;
    above = GROUND_FAR;
    info->water.height = above;
    info->water.flags = info->water.ang_z = info->water.ang_x = 0;
    objects = numLandCollList;
    /* @hack redundant: height, which nothing reads, takes a select on z,
     * which keeps x in FR12 and z in FR13 (0x8c0f48ec, 0x8c0f48f8); without
     * it, the two trade and 8 of 323 words differ */
    height = z ? query.pos.x : query.pos.z;
    ListGroundForCollision(x, y, z, 25.0F);
    for (i = 0; i < LandCollList; i++) {
        object = objects[i].object;
        if (objects[i].owner != NULL) {
            Float size;
            Float distance;
            Float reach;

            away.x = object->pos[0] - x;
            away.y = 0.0F;
            away.z = object->pos[2] - z;
            distance = njScalor(&away);
            size = object->scl[0];
            if (object->scl[1] > size) {
                size = object->scl[1];
            }
            if (object->scl[2] > size) {
                size = object->scl[2];
            }
            reach = size * object->model->r;
            if (distance > reach) {
                continue;
            }
        }
        if (polygon_find_heights(&query, objects[i].object, objects[i].flags)) {
            if (objects[i].owner != NULL && objects[i].owner->force != NULL) {
                query.above.level +=
                    ((struct task_force *)objects[i].owner->force)->speed.y;
                query.below.level +=
                    ((struct task_force *)objects[i].owner->force)->speed.y;
            }
            /* @hack redundant: a store to height, which nothing reads, that
             * keeps above_flags at @(20,R15) and below_flags at @(24,R15), as
             * their reads at 0x8c0f4b60 and 0x8c0f4b6e show; without it, the
             * two trade and 8 of 323 words differ */
            /* @hack redundant: the select on the constant 1.0F, which picks
             * below; without it, 8 of 323 words differ */
            height = 1.0F ? below : query.below.level;
            if (query.above.found == TRUE && query.pos.y < query.above.level &&
                above > query.above.level) {
                if (objects[i].flags & WORLD_WATER) {
                    if (_builtin_fabsf(query.above.level - query.pos.y) <
                        _builtin_fabsf(info->water.height - query.pos.y)) {
                        info->water.height = query.above.level;
                        info->water.ang_x = query.above.ang_x;
                        info->water.ang_z = query.above.ang_z;
                        info->water.flags = objects[i].flags;
                    }
                    if (!(skip & SKIP_WATER_ABOVE)) {
                        above = query.above.level;
                        above_ang_x = query.above.ang_x;
                        above_ang_z = query.above.ang_z;
                        above_flags = objects[i].flags;
                    }
                } else {
                    above = query.above.level;
                    above_ang_x = query.above.ang_x;
                    above_ang_z = query.above.ang_z;
                    above_flags = objects[i].flags;
                }
            }
            if (query.below.found == TRUE && query.pos.y >= query.below.level &&
                query.below.level > below) {
                if (objects[i].flags & WORLD_WATER) {
                    if (_builtin_fabsf(query.below.level - query.pos.y) <
                        _builtin_fabsf(info->water.height - query.pos.y)) {
                        info->water.height = query.below.level;
                        info->water.ang_x = query.below.ang_x;
                        info->water.ang_z = query.below.ang_z;
                        info->water.flags = objects[i].flags;
                    }
                    if (!(skip & SKIP_WATER_BELOW)) {
                        below = query.below.level;
                        below_ang_x = query.below.ang_x;
                        below_ang_z = query.below.ang_z;
                        below_flags = objects[i].flags;
                    }
                } else {
                    below = query.below.level;
                    below_ang_x = query.below.ang_x;
                    below_ang_z = query.below.ang_z;
                    below_flags = objects[i].flags;
                }
            }
        }
    }
    info->above.height = above;
    info->above.ang_x = above_ang_x;
    info->above.ang_z = above_ang_z;
    info->above.flags = above_flags;
    info->below.height = below;
    info->below.ang_x = below_ang_x;
    info->below.ang_z = below_ang_z;
    info->below.flags = below_flags;
    return below;
}

/* turn the lure's model within the lure. with a fish on, the model tips 80
 * degrees about x, and turns about y with the fish. on the bottom, its last
 * turn about z becomes its turn about x. otherwise it rocks 0x1000 either way
 * about x. about z, it turns 5 degrees a step to undo the lure's own turn
 * about z while the lure sits still. while the lure moves or dangles, or a
 * reel button is pressed, the model's turn about z goes back to 80 degrees */
void fishing_lure_sway(struct task *task)
{
    NJS_OBJECT *lure = fishing_lures[FUN_8c0e6dc0()]->child;
    NJS_VECTOR flat;
    int ang;
    int off;
    Float speed;
    int phase;

    lure->evalflags &= ~NJD_EVAL_UNIT_ANG;
    if (big_lure == NULL) {
        return;
    }
    if (fishing_flags & FISHING_HOOKED) {
        lure->ang[0] = NJM_DEG_ANG(80);
        lure->ang[2] = 0;
        if (big_catch != NULL) {
            lure->ang[1] =
                big_catch->work->ang.y + big_lure->work->ang.y + 0xc000;
        } else {
            lure->ang[1] = -0x4000;
        }
    } else if (fishing_flags & FISHING_BOTTOM) {
        lure->ang[0] = LURE(task)->sway[SWAY_ROLL];
        lure->ang[1] = 0;
        lure->ang[2] = LURE(task)->sway[SWAY_BOTTOM_Z];
    } else {
        /* @hack spelling: the phase read, then advanced, in two statements,
         * which adds the read into 0x800's register (ADD R4,R1 at
         * 0x8c0f4c6a); as one statement, the add's operands swap and 2 of
         * 152 words differ */
        phase = LURE(task)->sway[SWAY_PHASE];
        phase = (Uint16)(phase + 0x800);
        LURE(task)->sway[SWAY_PHASE] = phase;
        lure->ang[0] = njSin(phase) * 4096.0F;
        ang = LURE(task)->sway[SWAY_ROLL];
        flat.x = task->motion->speed.x;
        flat.y = 0.0F;
        flat.z = task->motion->speed.z;
        speed = njScalor(&flat);
        if (speed > 0.1F || (fishing_flags & FISHING_BOTTOM) ||
            PAD_BUTTONS(perG[0].press, pad_action_buttons | pad_jump_buttons) ||
            task->work->mode < LURE_FLY) {
            ang = NJM_DEG_ANG(80);
        } else {
            off = (Uint16)(task->work->ang.z + ang);
            if (off < 0x8000) {
                ang -= NJM_DEG_ANG(5);
            } else if (off > 0x8000) {
                ang += NJM_DEG_ANG(5);
            }
            if (off < NJM_DEG_ANG(5) || off > NJM_DEG_ANG(355)) {
                ang = -task->work->ang.z;
            }
        }
        LURE(task)->sway[SWAY_ROLL] = ang;
        lure->ang[2] = ang;
    }
}

/* set the lure's aim about y to its bearing from player 0, and tip the lure
 * about x. hooked, or with no speed in x and z, it levels 0x80 a step. on
 * the bottom, it tips 0x80 a step toward 0x1800. there a tilt past 0x1800,
 * even one below level, goes to 0x1800 at once, as the tag on its test
 * says. moving, it rocks 0x200 a step, to 0x800 either side of level. with
 * a jump button held, it rocks 0xc00 a step, to 0x1400. nothing while
 * big_lure is null */
void fishing_lure_pitch(struct task *task)
{
    struct task_work *player = playertwp[0];
    int ang;
    int aim;
    int limit;
    int step;
    int buttons;

    if (big_lure == NULL) {
        return;
    }
    task->motion->aim.y =
        0x4000 - (Angle)(njArcTan2(task->work->pos.x - player->pos.x,
                                   task->work->pos.z - player->pos.z) *
                         ANGLE_PER_RADIAN);
    /* @hack spelling: the hooked arm stores its turn and returns, with an else
     * after the return, which keeps 0x8000 in R13 (MOV.L at 0x8c0f4db2);
     * with one store after the chain, R7 takes it and 21 of 182 words
     * differ */
    if (fishing_flags & FISHING_HOOKED) {
        ang = task->work->ang.x;
        if (ang > 0x8000) {
            ang += 0x80;
            if (ang >= 0x10000) {
                ang = 0;
            }
        } else {
            ang -= 0x80;
            if (ang <= 0) {
                ang = 0;
            }
        }
        task->work->ang.x = ang;
        return;
    } else {
        if (fishing_flags & FISHING_BOTTOM) {
            ang = task->work->ang.x;
            /* @bug logic: every store to the lure's ang.x before it
             * reaches the bottom leaves 0 to 0xffff, so this test (CMP/PZ at
             * 0x8c0f4e38) always holds. a tilt below level, 0xe800 to
             * 0xffff, goes to 0x1800, and the arm meant for it (0x8c0f4e4c)
             * never runs */
            if (ang >= 0) {
                ang += 0x80;
                if (ang > 0x1800) {
                    ang = 0x1800;
                }
            } else {
                ang -= 0x80;
                ang = (Uint16)ang;
                if (ang < 0xe800) {
                    ang = 0xe800;
                }
            }
        } else {
            ang = task->work->ang.x;
            if (task->motion->speed.x == 0.0F &&
                task->motion->speed.z == 0.0F) {
                if (ang > 0x8000) {
                    ang += 0x80;
                    if (ang >= 0x10000) {
                        ang = 0;
                    }
                } else {
                    ang -= 0x80;
                    if (ang <= 0) {
                        ang = 0;
                    }
                }
            } else {
                buttons = 0;
                if (perG[0].on & pad_action_buttons) {
                    buttons = HELD_ACTION;
                }
                if (PAD_BUTTONS(perG[0].on, pad_jump_buttons)) {
                    buttons |= HELD_JUMP;
                }
                switch (buttons) {
                case HELD_ACTION:
                default:
                    step = 0x200;
                    limit = 0x800;
                    break;
                case HELD_JUMP:
                case HELD_ACTION | HELD_JUMP:
                    step = 0xc00;
                    limit = 0x1400;
                    break;
                }
                aim = task->motion->aim.x;
                if (ang > limit && ang < limit + 0x3000) {
                    aim = 0x10000 - limit;
                }
                if (ang > 0xd000 - limit && ang < 0x10000 - limit) {
                    aim = limit;
                }
                if (aim < 0x8000) {
                    ang = (Uint16)(ang + step);
                } else {
                    ang = (Uint16)(ang - step);
                }
                task->motion->aim.x = aim;
            }
        }
        task->work->ang.x = ang;
    }
}

/* turn the lure 0x40 a step about y toward its aim, and onto it once
 * within 0x80 */
void fishing_lure_yaw(struct task *task)
{
    Angle ang = task->work->ang.y;
    Angle aim = task->motion->aim.y;
    int off = (Uint16)(ang - aim);

    if (off < 0x8000) {
        ang -= 0x40;
    } else if (off > 0x8000) {
        ang += 0x40;
    }
    if (off < 0x80 || off > 0xff80) {
        ang = aim;
    }
    task->work->ang.y = ang;
}

/* turn the lure 0x80 a step about z toward its aim, and onto it once
 * within 0x80. the aim is level, but at Ice Cap's pond, off the bottom, it
 * is the slope of the way to the rod's tip. nothing while big_lure is
 * null */
void moveFishingRotZ(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang = work->ang.z;
    NJS_VECTOR tip;
    Angle aim;
    int off;

    if (big_lure == NULL) {
        return;
    }
    if (!(fishing_flags & FISHING_BOTTOM) && GetStageNumber() == ICECAP_POND) {
        fishing_rod_tip(task, &tip);
        tip.x -= work->pos.x;
        tip.y -= work->pos.y;
        tip.z -= work->pos.z;
        njUnitVector(&tip);
        aim = task->motion->aim.z =
            -(Angle)(asinf(tip.y) * ANGLE_PER_RADIAN) & 0xffff;
    } else {
        aim = task->motion->aim.z = 0;
    }
    off = (Uint16)(ang - aim);
    if (off < 0x8000) {
        ang -= 0x80;
    } else if (off > 0x8000) {
        ang += 0x80;
    }
    if (off < 0x80 || off > 0xff80) {
        ang = aim;
    }
    /* @hack spelling: the turn stored through task->work, which the image
     * reloads from task (MOV.L @(32,R13),R3 at 0x8c0f510c); through work,
     * task and work trade R12 and R13, and 20 of 101 words differ */
    task->work->ang.z = (Uint16)ang;
}

void fishing_hook_point(NJS_POINT3 *pos)
{
    NJS_MATRIX matrix;
    NJS_VECTOR hook;
    struct task_work *work;

    if (big_lure == NULL) {
        pos->x = pos->y = pos->z = 0.0F;
        return;
    }
    work = big_lure->work;
    hook.x = 0.6F;
    hook.y = -(0.3F * 1.5F);
    hook.z = 0.0F;
    njUnitMatrix(&matrix);
    TURN_MATRIX(njRotateZ, &matrix, work->ang.z);
    TURN_MATRIX(njRotateX, &matrix, work->ang.x);
    TURN_MATRIX(njRotateY, &matrix, -work->ang.y);
    njCalcVector(&matrix, &hook, pos);
    VECTOR_ADD(pos, &work->pos);
}

void fishing_catch_point(NJS_POINT3 *pos)
{
    NJS_MATRIX matrix;
    NJS_VECTOR offset;
    NJS_POINT3 base;
    struct task_work *work;

    if (big_lure == NULL) {
        pos->x = pos->y = pos->z = 0.0F;
        return;
    }
    work = big_lure->work;
    base = big_catch->work->pos;
    offset.x = -2.0F;
    offset.y = 1.5F;
    offset.z = 0.0F;
    njUnitMatrix(&matrix);
    njRotateXYZ(&matrix, work->ang.x, -work->ang.y, work->ang.z);
    njCalcVector(&matrix, &offset, pos);
    pos->x += base.x;
    pos->y += base.y;
    pos->z += base.z;
}

/* set pos to where the line meets the lure: its position plus (-0.6, 0.3,
 * 0), turned as the lure is. the origin while big_lure is null */
void fishing_line_end(NJS_POINT3 *pos)
{
    NJS_MATRIX matrix;
    NJS_VECTOR end;
    struct task_work *work;

    if (big_lure == NULL) {
        pos->x = pos->y = pos->z = 0.0F;
        return;
    }
    work = big_lure->work;
    end.x = -0.6F;
    end.y = 0.3F;
    end.z = 0.0F;
    njUnitMatrix(&matrix);
    TURN_MATRIX(njRotateY, &matrix, -work->ang.y);
    TURN_MATRIX(njRotateX, &matrix, work->ang.x);
    TURN_MATRIX(njRotateZ, &matrix, work->ang.z);
    njCalcVector(&matrix, &end, pos);
    VECTOR_ADD(pos, &work->pos);
}

/* set the draw state for the lure: its model's own materials, not the
 * constant one, blended by their alpha */
void fishing_set_draw(void)
{
    draw_control_clear(NJD_CONTROL_3D_CONSTANT_MATERIAL);
    draw_control_set(NJD_CONTROL_3D_OFFSET_MATERIAL);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_BOTHSRCALPHA);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

/* the camera's step that looks at camera_place's target from 50 beyond a
 * point 20 above player 0. camera_step_fishing_point does the same, then
 * pushes the camera out of walls, eases it and sweeps it, which this step
 * leaves out */
void fishing_camera_step_point(struct camera_view *view)
{
    /* @hack redundant: a copy of camera_work's pos into 12 bytes of the
     * frame, which nothing reads (0x8c0f53e6 to 0x8c0f53f2); without it, 107
     * of 116 words differ */
    /* NOLINTNEXTLINE(clang-diagnostic-unused-but-set-variable) */
    NJS_POINT3 unused;
    NJS_POINT3 away;

    unused = camera_twp->pos;
    VECTOR_COPY(&cameraControlWork->target, &camera_place.target);
    away.x = playertwp[0]->pos.x - cameraControlWork->target.x;
    away.y = playertwp[0]->pos.y - cameraControlWork->target.y + 20.0F;
    away.z = playertwp[0]->pos.z - cameraControlWork->target.z;
    njUnitVector(&away);
    away.x *= 50.0F;
    away.y *= 50.0F;
    away.z *= 50.0F;
    cameraControlWork->pos.x = playertwp[0]->pos.x + away.x;
    cameraControlWork->pos.y = playertwp[0]->pos.y + away.y + 20.0F;
    cameraControlWork->pos.z = playertwp[0]->pos.z + away.z;
    cameraControlWork->ang_z = 0;
}

/* set camera_place's target to the target's place on the ground, but at
 * least 30 out from player 0 in x and z */
void fishing_target_camera(struct task *task)
{
    NJS_POINT3 away;
    struct task_work *player = playertwp[0];

    away.x = task->work->pos.x - player->pos.x;
    away.y = 0.0F;
    away.z = task->work->pos.z - player->pos.z;
    if (njScalor(&away) < 30.0F) {
        njUnitVector(&away);
        away.x *= 30.0F;
        away.z *= 30.0F;
    }
    camera_place.target.x = player->pos.x + away.x;
    camera_place.target.y = TARGET(task)->ground;
    camera_place.target.z = player->pos.z + away.z;
}

/* set camera_place's pos to the lure, and move its target toward a point 10
 * from the lure. while a fish holds the lure unhooked, the point lies toward
 * that fish. otherwise it lies along a vector whose x and z run from player 0
 * to the lure, and whose y is minus the lure's height. the target moves 10 a
 * step, and onto the point once within 5. nothing while big_lure is null */
void fishing_lure_camera(struct task *task)
{
    NJS_POINT3 point;
    Float follow;
    Float distance;
    struct camera_place *place;
    /* @hack spelling: njSubVector called through subtract, set before follow,
     * which puts its pool word ahead of 10.0F's (0x8c0f55d8, 0x8c0f55dc);
     * called by name, the two trade and 2 of 149 words differ */
    void (*subtract)(NJS_POINT3 *from, NJS_POINT3 *by);

    if (big_lure == NULL) {
        return;
    }
    place = &camera_place;
    place->pos = task->work->pos;
    subtract = njSubVector;
    follow = 10.0F;
    if (big_catch != NULL && !(fishing_flags & FISHING_HOOKED)) {
        point = big_catch->work->pos;
        subtract(&point, &task->work->pos);
        distance = follow;
    } else {
        point = playertwp[0]->pos;
        subtract(&point, &task->work->pos);
        distance = -10.0F;
        point.y = task->work->pos.y;
    }
    njUnitVector(&point);
    point.x = task->work->pos.x + (point.x * distance);
    point.y = task->work->pos.y + (point.y * distance);
    point.z = task->work->pos.z + (point.z * distance);
    if (CalcDistance(&point, &place->target) < 5.0F) {
        place->target.x = point.x;
        place->target.y = point.y;
        place->target.z = point.z;
    } else {
        subtract(&point, &place->target);
        njUnitVector(&point);
        place->target.x += point.x * follow;
        place->target.y += point.y * follow;
        place->target.z += point.z * follow;
    }
}

void fishing_look_at_big(struct task *task)
{
    NJS_POINT3 ahead;
    NJS_POINT3 offset;
    struct task_work *player = playertwp[0];

    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, player->ang.z);
    TURN(njRotateX, player->ang.x);
    TURN(njRotateY, 0x8000 - player->ang.y);
    ahead.x = 100.0F;
    ahead.y = 0.0F;
    ahead.z = 0.0F;
    njCalcVector(NULL, &ahead, &offset);
    late_DrawObjectClipEx(1);
    camera_place.target.x = offset.x + player->pos.x;
    camera_place.target.y = offset.y + player->pos.y;
    camera_place.target.z = offset.z + player->pos.z;
}

/* set camera_place's target 30 out from player 0 toward the lure in x and
 * z, at his height */
void fishing_look_at_lure(struct task *task)
{
    NJS_POINT3 away;
    struct task_work *player = playertwp[0];

    away.x = task->work->pos.x - player->pos.x;
    away.y = 0.0F;
    away.z = task->work->pos.z - player->pos.z;
    njUnitVector(&away);
    away.x *= 30.0F;
    away.z *= 30.0F;
    camera_place.target.x = player->pos.x + away.x;
    camera_place.target.y = player->pos.y;
    camera_place.target.z = player->pos.z + away.z;
}

/* sweep a ball of radius 4 from *from toward *to. at a hit, *to moves back
 * to the nearest contact, *from plus the move as world_sweep_all_hit leaves
 * them. the sweep changes *from too */
void fishing_camera_clear(NJS_POINT3 *from, NJS_POINT3 *to)
{
    NJS_POINT3 move;

    move.x = to->x - from->x;
    move.y = to->y - from->y;
    move.z = to->z - from->z;
    if (MSetPosition(from, &move, NULL, 4.0F)) {
        to->x = from->x + move.x;
        to->y = from->y + move.y;
        to->z = from->z + move.z;
    }
}

/* the camera's step while the lure is in the water. it looks at the middle
 * of camera_place's pos and target, from twice their distance apart, and
 * moves at most 20 a step. it stays no lower than the point it looks at.
 * more than 5 under the water, a sweep from where it was keeps it clear of
 * walls */
void fishing_camera_step_lure(struct camera_view *view)
{
    NJS_POINT3 lure;
    NJS_POINT3 point;
    NJS_POINT3 from;
    NJS_POINT3 move;
    NJS_POINT3 apart;
    Float distance;

    lure = camera_place.pos;
    point = camera_place.target;
    from = camera_twp->pos;
    cameraControlWork->target.x = (lure.x + point.x) * 0.5F;
    cameraControlWork->target.y = (lure.y + point.y) * 0.5F;
    cameraControlWork->target.z = (lure.z + point.z) * 0.5F;
    move.x = cameraControlWork->pos.x - cameraControlWork->target.x;
    move.y = cameraControlWork->pos.y - cameraControlWork->target.y;
    move.z = cameraControlWork->pos.z - cameraControlWork->target.z;
    apart.x = lure.x - point.x;
    apart.y = lure.y - point.y;
    apart.z = lure.z - point.z;
    distance = njScalor(&apart) * 2.0F;
    njUnitVector(&move);
    move.x = cameraControlWork->target.x + (move.x * distance) -
             cameraControlWork->pos.x;
    move.y = cameraControlWork->target.y + (move.y * distance) -
             cameraControlWork->pos.y;
    move.z = cameraControlWork->target.z + (move.z * distance) -
             cameraControlWork->pos.z;
    if (njScalor(&move) < 20.0F) {
        cameraControlWork->pos.x += move.x;
        cameraControlWork->pos.y += move.y;
        cameraControlWork->pos.z += move.z;
    } else {
        njUnitVector(&move);
        cameraControlWork->pos.x += move.x * 20.0F;
        cameraControlWork->pos.y += move.y * 20.0F;
        cameraControlWork->pos.z += move.z * 20.0F;
    }
    if (cameraControlWork->pos.y < cameraControlWork->target.y) {
        cameraControlWork->pos.y = cameraControlWork->target.y;
    }
    if (fishing_water - 5.0F > cameraControlWork->pos.y) {
        fishing_camera_clear(&from, &cameraControlWork->pos);
    }
}

Float fishing_get_water(void)
{
    return fishing_water;
}

void fishing_hud_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case HUD_INIT:
        task->draw = fishing_hud_draw;
        work->mode = HUD_SHOW;
        break;
    case HUD_SHOW:
        fishing_hud_show(task);
        break;
    }
}

/* the hit banner's step: its halves slide together 16 a step, wait 60
 * steps, slide on past each other, and the banner ends. it shows on every
 * other step */
void fishing_banner_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case BANNER_INIT:
        task->draw = fishing_banner_draw;
        work->mode = BANNER_IN;
        work->pos.x = 420.0F;
        break;
    case BANNER_IN:
        work->pos.x -= 16.0F;
        if (work->pos.x < 0.0F) {
            work->pos.x = 0.0F;
            work->mode = BANNER_WAIT;
            BANNER_VARS(work)->steps = 60;
        }
        fishing_banner_blink(task);
        break;
    case BANNER_WAIT:
        if (--BANNER_VARS(work)->steps == 0) {
            work->mode = BANNER_OUT;
        }
        fishing_banner_blink(task);
        break;
    case BANNER_OUT:
        work->pos.x -= 16.0F;
        if (work->pos.x < -420.0F) {
            work->mode = BANNER_DONE;
        }
        fishing_banner_blink(task);
        break;
    case BANNER_DONE:
        FreeTask(task);
        break;
    }
}

void fishing_start_fight(void)
{
    CreateElementalTask(TASK_WORK, 3, fishing_banner_step);
    fishing_strain = 0.0F;
    stream_request_interlude(MUSIC_FISHING);
}

/* create a splash at parent's place, facing as it does. the task, or
 * null */
struct task *fishing_splash_create(struct task *parent)
{
    struct task *task = CreateElementalTask(TASK_WORK, 2, fishing_splash_step);

    if (task != NULL) {
        task->work->pos = parent->work->pos;
        task->work->ang.y = parent->work->ang.y;
        SPLASH_VARS(task->work)->frame = 0;
        TASK_TIMER(task->work) = 5;
        SPLASH_VARS(task->work)->alpha = 1.0F;
    }
    return task;
}

void fishing_splash_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_SPRITE sprite;
    NJS_ARGB color;

    sprite.tlist = &fishing_texlist;
    sprite.tanim = fishing_splash_texanims;
    sprite.ang = 0;
    sprite.sx = 0.1F;
    sprite.sy = 0.1F;
    VECTOR_CLEAR(&sprite.p);
    njSetTexture_jp(&fishing_texlist);
    color.b = 1.0F;
    color.g = 1.0F;
    color.r = 1.0F;
    if (work->mode == SPLASH_FADE) {
        color.a = SPLASH_VARS(work)->alpha;
    } else {
        color.a = 1.0F;
    }
    njSetConstantMaterial(&color);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    /* @hack spelling: the sprite read through task->work, which keeps task in
     * the frame (MOV.L R4,@R15 at 0x8c0f5c16); through work, the frame
     * shrinks by 4 bytes and 67 of 76 words differ */
    njDrawSprite3D(&sprite, SPLASH_VARS(task->work)->frame,
                   NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE | NJD_SPRITE_COLOR);
    late_DrawObjectClipEx(1);
}

void fishing_splash_destroy(struct task *task)
{
}

/* the splash's step: its first seven sprites show five steps each, then
 * the last fades a tenth every ten steps, and the splash ends. its fade
 * clears FISHING_SPLASH */
void fishing_splash_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case SPLASH_INIT:
        task->destructor = fishing_splash_destroy;
        task->draw = fishing_splash_draw;
        work->mode = SPLASH_PLAY;
        TASK_TIMER(work) = 5;
        break;
    case SPLASH_PLAY:
        if (SPLASH_VARS(work)->frame == 7) {
            work->mode = SPLASH_FADE;
            TASK_TIMER(work) = 10;
            if (big_lure != NULL) {
                fishing_flags &= ~FISHING_SPLASH;
            }
            break;
        }
        if (--TASK_TIMER(work) == 0) {
            TASK_TIMER(work) = 5;
            SPLASH_VARS(work)->frame++;
        }
        fishing_splash_draw(task);
        break;
    case SPLASH_FADE:
        if (SPLASH_VARS(work)->alpha <= 0.0F) {
            FreeTask(task);
        } else {
            if (--TASK_TIMER(work) == 0) {
                TASK_TIMER(work) = 10;
                SPLASH_VARS(work)->alpha -= 0.1F;
            }
            fishing_splash_draw(task);
        }
        break;
    }
}

Bool fishing_task_in_reach(struct task_work *work)
{
    struct near_task *near;
    Float distance;

    if (PLAYER_VARS(work)->player == 0) {
        near = around_enemy_list_p0;
    } else {
        near = around_enemy_list_p1;
    }
    if (near->work == NULL) {
        return FALSE;
    }
    for (distance = near->distance; near->work != NULL; near++) {
        if (distance > near->distance) {
            distance = near->distance;
        }
    }
    if (distance > 50.0F * 50.0F) {
        return FALSE;
    }
    return TRUE;
}

void fishing_reset(void)
{
    fishing_score = 0;
    biggest_fish = 0;
    biggest_fish_kind = 0;
    fishing_record_weight = fishing_load_record();
    fishing_cast_pos.x = fishing_cast_pos.y = fishing_cast_pos.z = 0.0F;
}

/* give a prize at random, by fishing_prizes' chances, and return its
 * kind */
int fishing_give_prize(void)
{
    int i = 0;
    Float sum = 0.0F;
    Float chance = rand() * RAND_SCALE;

    do {
        i++;
        sum += fishing_prizes[i].chance;
    } while (chance > sum);
    if (fishing_prizes[i].give != NULL) {
        fishing_prizes[i].give();
    }
    return fishing_prizes[i].kind;
}

void fishing_prize_5_rings(void)
{
    ring_add(5);
    dsPlay_oneshot(SE_RING, 0, 0, 0);
}

void fishing_prize_10_rings(void)
{
    ring_add(10);
    dsPlay_oneshot(SE_RING, 0, 0, 0);
}

void fishing_prize_random_rings(void)
{
    int rings;

    ring_add(rings = fishing_random_ring_counts[(
                 int)(rand() * (RANDOM_RING_COUNTS * RAND_SCALE))]);
    /* @hack redundant: a call of ring_add that never runs. its use of rings
     * keeps rings in the frame (ADD #-4,R15 at 0x8c0f5edc, MOV.L R2,@R15 at
     * 0x8c0f5efa); without it, the frame goes, the function runs 6 bytes short,
     * and 25 of 27 words differ */
    if (0) {
        ring_add(rings);
    }
    dsPlay_oneshot(SE_RING, 0, 0, 0);
}

void fishing_prize_1up(void)
{
    FUN_8c08a060(1);
}

Float FUN_8c0eb4f0(void)
{
    return fishing_distance;
}

/* stop a ball of radius at the walls of the pen fishing_in_pen finds, 40 out
 * from its middle each way. TRUE when it meets one, with speed cut to the wall
 * and ang set to the wall's slope. away from the pens of Ice Cap's pond, there
 * is none to meet */
Bool fishing_pen_sweep(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                       Float radius)
{
    int i;
    Bool hit;
    Float min_x;
    Float max_x;
    Float min_z;
    Float max_z;

    if (GetStageNumber() != ICECAP_POND) {
        return FALSE;
    }
    for (i = 0; i < PENS; i++) {
        if (CalcDistance(&fishing_pens[i], &fishing_cast_pos) < 70.0F) {
            break;
        }
    }
    if (i == PENS) {
        return FALSE;
    }
    min_x = fishing_pens[i].x - 40.0F;
    max_x = fishing_pens[i].x + 40.0F;
    min_z = fishing_pens[i].z - 40.0F;
    max_z = fishing_pens[i].z + 40.0F;
    hit = FALSE;
    if (pos->x + speed->x - radius <= min_x) {
        hit = TRUE;
        speed->x = min_x - pos->x + radius;
        ang->z = 0xc000;
    }
    if (pos->x + speed->x + radius >= max_x) {
        hit = TRUE;
        speed->x = max_x - pos->x - radius;
        ang->z = 0x4000;
    }
    if (pos->z + speed->z - radius <= min_z) {
        hit = TRUE;
        speed->z = min_z - pos->z + radius;
        ang->x = 0x4000;
    }
    if (pos->z + speed->z + radius >= max_z) {
        hit = TRUE;
        speed->z = max_z - pos->z - radius;
        ang->x = 0xc000;
    }
    return hit;
}

/* sweep a ball of radius from pos along speed, as world_sweep_ball does, but
 * skipping WORLD_WATER objects. TRUE at once where fishing_pen_sweep meets a
 * pen's wall. otherwise the ball sweeps through the world's objects as last
 * listed. TRUE at a hit, with pos, speed and ang the nearest contact's */
Bool fishing_sweep(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                   Float radius)
{
    struct polygon_ball ball;
    struct polygon_ball best;
    struct angles offset;
    struct polygon_ball *CalcBaneTopPoint;
    struct world_object *objects;
    struct task_force *force;
    struct task *owner;
    Angle slope_x;
    Angle slope_z;
    Angle flipped_x;
    Angle flipped_z;
    Angle gap_x;
    Angle gap_z;
    Uint16 i;
    Bool hit;
    Float nearest;
    Float distance;

    hit = FALSE;
    if (fishing_pen_sweep(pos, speed, ang, radius)) {
        return TRUE;
    }
    objects = numLandCollList;
    CalcBaneTopPoint = &ball;
    offset.x = 0;
    offset.y = 0;
    offset.z = 0;
    if (ang == NULL) {
        CalcBaneTopPoint->normal_jp.x = 0.0F;
        CalcBaneTopPoint->normal_jp.y = 1.0F;
        CalcBaneTopPoint->normal_jp.z = 0.0F;
    } else {
        NJS_VECTOR normal_jp;
        NJS_VECTOR up;

        up.x = 0.0F;
        up.y = 1.0F;
        up.z = 0.0F;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, ang->z);
        TURN(njRotateX, ang->x);
        TURN(njRotateY, ang->y);
        njCalcVector(NULL, &up, &normal_jp);
        late_DrawObjectClipEx(1);
        CalcBaneTopPoint->normal_jp = normal_jp;
    }
    CalcBaneTopPoint->pos = *pos;
    CalcBaneTopPoint->radius = radius;
    CalcBaneTopPoint->speed = *speed;
    for (i = 0; i < LandCollList; i++) {
        struct angles turn;
        NJS_VECTOR moved;

        if (objects[i].flags & WORLD_WATER) {
            continue;
        }
        if (CL_ColPolCheckTouchRe(CalcBaneTopPoint, objects[i].object,
                                  objects[i].flags)) {
            if (ang != NULL && CalcBaneTopPoint->hit.normal_jp.y < 0.0F) {
                slope_x = (Angle)(asinf(CalcBaneTopPoint->hit.normal_jp.z) *
                                  ANGLE_PER_RADIAN);
                slope_z = -(Angle)(asinf(CalcBaneTopPoint->hit.normal_jp.x) *
                                   ANGLE_PER_RADIAN);
                flipped_x = (Uint16)(0x8000 - slope_x);
                flipped_z = (Uint16)(0x8000 - slope_z);
                gap_x = DiffAngle(ang->x, flipped_x);
                gap_z = DiffAngle(ang->z, flipped_z);
                if (gap_x < gap_z) {
                    CalcBaneTopPoint->hit.ang_x = flipped_x;
                    CalcBaneTopPoint->hit.ang_z = slope_z;
                } else {
                    CalcBaneTopPoint->hit.ang_x = slope_x;
                    CalcBaneTopPoint->hit.ang_z = flipped_z;
                }
            }
            owner = objects[i].owner;
            if (owner != NULL && owner->force != NULL) {
                force = owner->force;
                VECTOR_ADD(&CalcBaneTopPoint->hit.pos, &force->speed);
                turn = force->turn;
            } else {
                turn.x = 0;
                turn.y = 0;
                turn.z = 0;
            }
            moved.x = CalcBaneTopPoint->hit.pos.x - pos->x;
            moved.y = CalcBaneTopPoint->hit.pos.y - pos->y;
            moved.z = CalcBaneTopPoint->hit.pos.z - pos->z;
            if (!hit) {
                best = ball;
                nearest = njScalor(&moved);
                offset = turn;
            } else {
                distance = njScalor(&moved);
                if (nearest > distance) {
                    best = ball;
                    nearest = distance;
                    offset = turn;
                }
            }
            hit = TRUE;
        }
    }
    if (hit == TRUE) {
        CalcBaneTopPoint = &best;
        *pos = CalcBaneTopPoint->hit.pos;
        *speed = CalcBaneTopPoint->hit.speed;
        if (ang != NULL) {
            ang->x = CalcBaneTopPoint->hit.ang_x + offset.x;
            ang->y += offset.y;
            ang->z = CalcBaneTopPoint->hit.ang_z + offset.z;
        }
    }
    return hit;
}

/* add a catch's weight to fishing_score, to 99990 at most. biggest_fish and
 * biggest_fish_kind take the catch if it's the heaviest */
void fishing_score_catch(Float weight, int kind)
{
    fishing_score += weight;
    if (fishing_score > 99990) {
        fishing_score = 99990;
    }
    if (weight > biggest_fish) {
        biggest_fish = weight;
        biggest_fish_kind = kind;
    }
}

/* draw the catch's weight and its unit, on each frame's first step */
void fishing_catch_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_SPRITE sprite;
    struct hud_number number;

    if (loop_count == 0) {
#ifdef GCC
        /* 16:9 squeezes the weight about a pivot that travels with it from
         * the screen's right edge to the left edge, the score's pivot. its
         * scale falls from 2 to 1 on the way, and a lost fish's stays 2 as
         * it leaves on the right */
        port_wide_anchor =
            WIDE_RIGHT + ((2.0F - work->scl.x) * (WIDE_LEFT - WIDE_RIGHT));
#endif
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_INVSRCALPHA);
        SetMaterial(1.0F, 1.0F, 1.0F, 1.0F);
        sprite.tlist = &fishing_texlist;
        sprite.tanim = fishing_hud_texanims;
        sprite.sx = work->scl.x;
        sprite.sy = work->scl.x;
        sprite.p.x = work->pos.x;
        sprite.p.y = work->pos.z;
        late_DrawSprite2D(&sprite, SPRITE_UNIT, HUD_DEPTH - 0.018F,
                          NJD_SPRITE_ALPHA);
        number.flags = NUMBER_SCALED | NUMBER_CLAMPED;
        number.place = NUMBER_LEFT | NUMBER_TOP | NUMBER_DEPTH;
        number.unk_02 = 0;
        number.max = 9999;
        /* @hack spelling: the weight read through task->work, which keeps task
         * in the frame (MOV.L R4,@R15 at 0x8c0f64ee); through work, the
         * frame shrinks by 4 bytes and 110 of 116 words differ */
        number.value = CATCH_VARS(task->work)->weight;
        number.pos.x = work->pos.x - (work->scl.x * 64.0F) - 16.0F;
        number.pos.y = work->pos.z - 16.0F;
        number.pos.z = 0.0F;
        number.scale = work->scl.x;
        number.color = 0xffc0c0c0;
        DrawSNumbers(&number);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                               NJD_COLOR_BLENDING_BOTHSRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_BOTHSRCALPHA);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
#ifdef GCC
        port_wide_anchor = WIDE_MIDDLE;
#endif
    }
}

/* score the catch as its task ends, with SE_RING, but not a fish the line
 * lost. the frog's catch saves the score too */
void fishing_catch_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (CATCH_VARS(work)->kind != CATCH_SNAPPED) {
        fishing_score_catch(CATCH_VARS(work)->weight, CATCH_VARS(work)->kind);
        if (CATCH_VARS(work)->kind == FISH_FROG) {
            fishing_save();
        }
        dsPlay_oneshot(SE_RING, 0, 0, 0);
    }
}

/* the catch task's step. the weight shows at twice its size for 60 steps.
 * over 60 more, it shrinks as it slides left, or for a fish the line lost,
 * slides right. at the end, the frog's catch at Twinkle Park and Ice Cap
 * plays VOICE_FROG */
void fishing_catch_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case CATCH_INIT:
        task->draw = fishing_catch_draw;
        task->destructor = fishing_catch_destroy;
        work->mode = CATCH_SHOW;
        CATCH_VARS(work)->steps = 120;
        work->pos.x = 604.0F;
        work->pos.z = 40.0F;
        work->scl.x = 2.0F;
        break;
    case CATCH_SHOW:
        if (--CATCH_VARS(work)->steps == 60) {
            work->mode = CATCH_LEAVE;
        }
        fishing_catch_draw(task);
        break;
    case CATCH_LEAVE:
        if (--((struct catch_vars *)&(work)->vars)->steps <= 0) {
            if (((struct catch_vars *)&(work)->vars)->kind == 0) {
                if (((GetStageNumber() & 0xff00) == (((3)) << 8 | (0))) ||
                    ((GetStageNumber() & 0xff00) == (((8)) << 8 | (0)))) {
                    Serif_Play(0x536);
                }
            }
            FreeTask(task);
        }
        if (CATCH_VARS(work)->kind != CATCH_SNAPPED) {
            work->pos.x += -7.0F;
            work->pos.z += 7.0F / 60.0F;
            work->scl.x = 1.0F + (CATCH_VARS(work)->steps * (1.0F / 60.0F));
        } else {
            work->pos.x += 5.0F;
        }
        fishing_catch_draw(task);
        break;
    }
}

void fishing_show_catch(int weight, int kind)
{
    struct task *task = CreateElementalTask(TASK_WORK, 3, fishing_catch_step);

    if (task != NULL) {
        CATCH_VARS(task->work)->weight = weight;
        CATCH_VARS(task->work)->kind = kind;
    }
}

/* Big's stage as the save numbers it: 0 at Emerald Coast, 1 at Twinkle Park and
 * 2 at Ice Cap. any other stage, as Hot Shelter, is 3 */
int fishing_save_stage(void)
{
    if (IN_STAGE(STAGE_BEACH)) {
        return 0;
    } else if (IN_STAGE(STAGE_TWINKLE)) {
        return 1;
    } else if (IN_STAGE(STAGE_ICECAP)) {
        return 2;
    } else {
        return 3;
    }
    /* @hack redundant: a return no path reaches, whose MOV #0,R0 the
     * beach's test branches to for its own 0 (BT at 0x8c0f6822 to
     * 0x8c0f6880); without it, that test returns in place and 21 of 37
     * words differ */
    return 0;
}

/* put score among the stage's three best in the save, in order, if it
 * beats the third */
void fishing_save_score(struct save *save, int stage, Sint16 score)
{
    if (save->fishing_scores[stage][0] < score) {
        save->fishing_scores[stage][2] = save->fishing_scores[stage][1];
        save->fishing_scores[stage][1] = save->fishing_scores[stage][0];
        save->fishing_scores[stage][0] = score;
    } else if (save->fishing_scores[stage][1] < score) {
        save->fishing_scores[stage][2] = save->fishing_scores[stage][1];
        save->fishing_scores[stage][1] = score;
    } else if (save->fishing_scores[stage][2] < score) {
        save->fishing_scores[stage][2] = score;
    }
}

/* keep a fish's weight and kind as the stage's biggest in the save, if it
 * is heavier */
void fishing_save_fish(struct save *save, int stage, Sint16 weight, int kind)
{
    if (save->biggest_fish[stage].weight < weight) {
        save->biggest_fish[stage].weight = weight;
        save->biggest_fish[stage].kind = kind;
    }
}

/* put the score, in tens, and the heaviest catch into the save slot's
 * records for the stage */
void fishing_save(void)
{
    struct save *save;
    int stage;

    fishing_save_copy = SaveData[save_slot];
    save = &fishing_save_copy;
    stage = fishing_save_stage();
    if (stage < 0) {
        return;
    }
    fishing_save_score(save, stage, fishing_score / 10);
    fishing_save_fish(save, stage, biggest_fish, biggest_fish_kind);
    SaveData[save_slot] = fishing_save_copy;
}

/* the weight of the stage's biggest fish in the save slot, which it stores
 * in fishing_record_weight too */
Float fishing_load_record(void)
{
    struct save *save = &SaveData[save_slot];
    int stage = fishing_save_stage();

    return fishing_record_weight = save->biggest_fish[stage].weight;
}
