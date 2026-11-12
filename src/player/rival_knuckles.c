/* @unit 8C0841A0-8C084A20 +egflags +pool32 */
/* the rival Knuckles: Knuckles as player 1, on the pad its task writes */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "camera/battle.h"
#include "collision/collision.h"
#include "event/play.h"
#include "object/common.h"
#include "player/knuckles.h"
#include "player/npc.h"
#include "player/player.h"
#include "player/rival.h"
#include "player/rival_knuckles.h"
#include "sound/stream.h"
#include "system/math.h"
#include "system/pad.h"
#include "system/task.h"
#include "vmu/vibration.h"
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
void pdExecPeripheralServerUser(void);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void *MAlloc(int size);
void Free(void *mem);
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void EV_Load2(int number);
void EV_Exec2(void);
Bool EV_CheckExec(int number);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z, Angle ang_x,
                     Angle ang_y, Angle ang_z);
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
extern struct AdvertiseWork AdvertiseWork;
Bool thunk_FUN_8c081ba6(void);
struct task *thunk_FUN_8c081bec(void);
struct task *thunk_FUN_8c08395e(struct battle *battle);
struct task *thunk_FUN_8c083ebc(struct battle *battle);
void thunk_FUN_8c083f7e(struct battle *battle);
Sint16 thunk_FUN_8c0829cc(int frames);
Sint16 thunk_FUN_8c082b9a(int unused);
void ObjectMovableSRegularExecute(struct task *task);
void ObjectMovableMRegularExecute(struct task *task);
void ObjectSetupInput(struct task_work *work, struct task_motion *motion);
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
Bool Knuckles_KakeraGame_GetNearEmePos(NJS_POINT3 *from, NJS_POINT3 *pos,
                                       Float *distance);
Bool Knuckles_KakeraGame_Set_PutEme(int id, NJS_POINT3 *pos);
struct task *NpcMilesSet(struct task *leader);
void FUN_8c08267c(NJS_VECTOR *speed, Float *stroke, Angle *ang);
Sint16 StageNameModeInit(int frames);
Sint16 StageNameMode(void);
void ADX_Close(void);
Bool CameraFishingCatch(void);
void Serif_Play(int voice);
Float ghUnitVector(NJS_VECTOR *vector, NJS_VECTOR *out);
Float CalcDistance2(NJS_POINT3 *from, NJS_POINT3 *to);
Uint32 ghBlendColors(Uint32 color, Uint32 by);
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void VibShot(int pad, int power, int freq, int time);

/* the rival Knuckles' modes. the stick is released unless a mode moves
 * it */
#define PUNCH_GAP 8
#define SLOW_STEPS 120
#define VOICE_LAST_SONIC 0xa8
#define VOICE_LAST_TAILS 0xaa
#define VOICE_HIT 0xa6 /* as it takes a hit */
#define STICK_UP (-127)
enum rival_mode {
    RIVAL_START,
    RIVAL_MUSIC,
    RIVAL_WAIT, /* until timer passes wait */
    RIVAL_READY, /* setting player 1's mode to PLAYER_MODE_READY, then facing */
    /* facing player 0, until timer passes face_steps with the rival on the
     * ground. while the rival stands, the stick turns it toward player 0 at
     * RIVAL_NUDGE. here the battle is lost once rival_player_fights is
     * FALSE. a rival that has taken RIVAL_HITS hits goes to RIVAL_BEATEN */
    RIVAL_FACE,
    RIVAL_RECOIL, /* recoiling, running from player 0 unless beaten */
    RIVAL_BEATEN,
    RIVAL_IDLE,
    RIVAL_PUNCH_AT, /* running at player 0, to punch within range[0] */
    RIVAL_PUNCH, /* punching at player 0, by phase */
    RIVAL_ROLL_AT, /* running at player 0, to press action within range[1] */
    /* rolling at player 0, the stick released while timer & blink is 0 and
     * pushed otherwise. it ends once timer passes chase, or once player 1's
     * flags lose PLAYER_ATTACKING */
    RIVAL_ROLL,
    /* turning toward player 0 at RIVAL_NUDGE, to jump from the ground */
    RIVAL_TAKE_OFF,
    /* in the air at player 0, jump held as it rises, then pressed again to
     * glide */
    RIVAL_JUMP,
    RIVAL_GLIDE, /* gliding at player 0, until it lands or climbs a wall */
    RIVAL_CLIMB /* the stick pushed up, until it has climbed over the top */
};

/* the phases of RIVAL_PUNCH. each of the first three presses action */
enum punch_phase {
    PUNCH_FIRST,
    /* once timer passes PUNCH_GAP, ten steps after the first */
    PUNCH_SECOND,
    PUNCH_THIRD, /* once timer passes PUNCH_GAP again */
    /* until the punching ends. the rival then halves its speed and steers
     * off */
    PUNCH_FINISH,
    /* the stick released, until its speed falls to 0.02 or timer passes
     * SLOW_STEPS */
    PUNCH_SLOW
};

/* the rival Knuckles' voices. as it recovers from a hit with one hit left,
 * it says the VOICE_LAST for the character it fights */

/* the y1 RIVAL_CLIMB writes to player 1's pad: its stick pushed up */

static void rival_knuckles_step(struct task *task);
extern Sint8 rival_knuckles_attacks[3];

struct task *rival_knuckles_start(struct battle *battle)
{
    struct task *rival_task = battle->rival;
    struct task *task;
    struct rival *rival;

    task = CreateElementalTask(TASK_WORK, 0, rival_knuckles_step);
    if (task == NULL) {
        return NULL;
    }
    rival = CAlloc(1, sizeof(struct rival));
    task->extra = rival;
    rival->rival_task = rival_task;
    rival->rival_work = rival_task->work;
    rival->rival_motion = rival_task->motion;
    rival->rival_record = rival->rival_motion->record;
    rival->player_task = battle->player;
    rival->playertwp = rival->player_task->work;
    rival->playermwp = rival->player_task->motion;
    rival->player_record = rival->playermwp->record;
    rival->kind = battle->kind;
    rival->unk_10 = battle->unk_0c;
    rival->finish = battle->finish;
    rival->attacks = rival_knuckles_attacks;
    rival->range[0] = 50.0F;
    rival->range[1] = 50.0F;
    rival->range[2] = 50.0F;
    rival->wait = 120;
    rival->face_steps = 60;
    rival->chase = 120;
    rival->blink = 1;
    rival_place(task);
    task->draw = rival_draw;
    task->destructor = rival_end;
    battle_set_outcome(BATTLE_RUNNING);
    camera_start_battle(task);
    return task;
}

/* write the rival Knuckles' pad and stick for the step, by its mode */
static void rival_knuckles_step(struct task *task)
{
    struct rival *rival;
    Uint32 on;
    Uint32 press;
    Angle ang;
    Float stroke;
    Float across;
    int caught;
    int flags;

    rival = task->extra;
    if (EV_CheckCansel() == TRUE) {
        return;
    }
    camera_keep_battle();
    rival->rival_record = rival->rival_motion->record;
    rival->player_record = rival->playermwp->record;
    if (rival->rival_record == NULL) {
        return;
    }
    if (rival->player_record == NULL) {
        return;
    }
    if (PLAYER_VARS(rival->playertwp)->character == CHARACTER_SONIC) {
        rival->rival_work->collision->flags |= COLLISION_TARGET;
    }
    PadReadOffP(1);
    ang = 0;
    stroke = 0.0F;
    on = perG[1].on;
    press = perG[1].press;
    caught = rival_catch_falls(rival);
    if (caught & RIVAL_FELL) {
        rival->mode = RIVAL_BEATEN;
        rival->rival_work->pos = rival->start;
    } else if (caught & RIVAL_PLAYER_FELL) {
        /* @hack redundant: an empty arm, whose test keeps the image's TST R0,R4
         * at 0x8c089222. the switch's CMP/HS at 0x8c089232 sets T again
         * before any branch. without it, rival_knuckles.c's code runs 32
         * bytes short and 711 of 774 words differ */
    }
    switch (rival->mode) {
    case RIVAL_START:
        rival->rival_work->id = RIVAL_ID;
        rival->timer = 0;
        rival->mode = RIVAL_MUSIC;
        ADXTaskInit();
        break;
    case RIVAL_MUSIC:
        BGM_Play(MUSIC_BOSSEVNT);
        rival->mode = RIVAL_WAIT;
        break;
    case RIVAL_WAIT:
        rival->timer++;
        if (rival->timer > rival->wait) {
            rival->timer = 0;
            rival->mode = RIVAL_READY;
        }
        break;
    case RIVAL_READY:
        SetInputP(1, PLAYER_MODE_READY);
        rival->mode = RIVAL_FACE;
        break;
    case RIVAL_FACE:
        if (!rival_player_fights(task)) {
            battle_set_outcome(BATTLE_LOST);
            FreeTask(task);
            return;
        }
        if (rival->hits >= RIVAL_HITS) {
            rival->mode = RIVAL_BEATEN;
            break;
        }
        rival->flags &= ~RIVAL_ATTACKING;
        if (rival->rival_record->speed.x == 0.0F) {
            ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                               NULL, NULL);
            stroke = RIVAL_NUDGE;
        }
        rival->timer++;
        if (rival->timer > rival->face_steps &&
            (rival->rival_work->flags & PLAYER_ON_GROUND)) {
            rival->timer = 0;
            if (rival->hits == 1) {
                if (rival->turn & 1) {
                    rival->mode = RIVAL_PUNCH_AT;
                } else {
                    rival->mode = RIVAL_ROLL_AT;
                }
                rival->turn++;
            } else {
                rival->mode = rival->attacks[rival->hits];
                rival->flags |= RIVAL_ATTACKING;
            }
        }
        break;
    case RIVAL_RECOIL:
        if (rival->hits < RIVAL_HITS) {
            ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                               NULL, &across);
            stroke = 1.0F;
            ang += NJM_DEG_ANG(180);
        }
        if (!(rival->rival_work->flags & PLAYER_RECOILING)) {
            rival->mode = RIVAL_READY;
            if (rival->hits == 3 - 1) {
                extern int dat_8c754b40;
                if (rival->kind == BATTLE_KNUCKLES_SONIC) {
                    Serif_Play(0xa6);
                } else if (rival->kind == BATTLE_KNUCKLES_TAILS) {
                    if (dat_8c754b40 == 0) {
                        Serif_Play(0xa8);
                    } else {
                        Serif_Play(0xa6);
                    }
                }
            }
        }
        break;
    case RIVAL_BEATEN:
        battle_set_outcome(BATTLE_WON);
        FreeTask(task);
        return;
    case RIVAL_IDLE:
        break;
    case RIVAL_PUNCH_AT:
        ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                           NULL, &across);
        stroke = 1.0F;
        if (across < rival->range[0]) {
            rival->phase = PUNCH_FIRST;
            rival->mode = RIVAL_PUNCH;
        }
        break;
    case RIVAL_PUNCH:
        ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                           NULL, &across);
        stroke = 1.0F;
        if (rival->rival_record->speed.x > 2.0F) {
            rival->rival_record->speed.x = 1.9F;
        }
        switch (rival->phase) {
        case PUNCH_FIRST:
            if (rival->rival_record->speed.x < 0.5F) {
                rival->rival_record->speed.x = 0.5F;
            }
            press |= pad_action_buttons;
            rival->phase = PUNCH_SECOND;
            break;
        case PUNCH_SECOND:
            if (rival->timer++ > PUNCH_GAP) {
                press |= pad_action_buttons;
                rival->timer = 0;
                rival->phase = PUNCH_THIRD;
            }
            break;
        case PUNCH_THIRD:
            if (rival->timer++ > PUNCH_GAP) {
                /* @hack redundant: an empty test of player 0's
                 * PLAYER_ON_GROUND, which keeps the image's TST R12,R0 at
                 * 0x8c08955e; without it, 12 of 774 words differ */
                if (rival->playertwp->flags & PLAYER_ON_GROUND) {
                }
                press |= pad_action_buttons;
                rival->timer = 0;
                rival->phase = PUNCH_FINISH;
            }
            break;
        case PUNCH_FINISH:
            stroke = 1.0F;
            if (knuckles_get_activity(1) != KNUCKLES_PUNCHING) {
                rival->timer = 0;
                rival->rival_record->speed.x *= 0.5F;
                ang = angle_arc_tan2(rival->rival_motion->speed.z,
                                     rival->rival_motion->speed.x) +
                      NJM_DEG_ANG(11.25);
                stroke = 1.0F;
                rival->phase = PUNCH_SLOW;
            }
            break;
        case PUNCH_SLOW:
            stroke = 0.0F;
            if (rival->rival_record->speed.x <= 0.02F ||
                rival->timer++ > SLOW_STEPS) {
                rival->timer = 0;
                rival->phase = PUNCH_FIRST;
                rival->mode = RIVAL_READY;
            }
            break;
        }
        break;
    case RIVAL_ROLL_AT:
        ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                           NULL, &across);
        stroke = 1.0F;
        if (across < rival->range[1]) {
            press = pad_action_buttons;
            if (rival->rival_record->speed.x <= 2.0F) {
                rival->rival_record->speed.x = 2.01F;
            }
            rival->phase = 0;
            rival->mode = RIVAL_ROLL;
        }
        break;
    case RIVAL_ROLL:
        ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                           NULL, &across);
        if ((rival->timer & rival->blink) == 0) {
            stroke = 0.0F;
        } else {
            stroke = 1.0F;
        }
        rival->timer++;
        if (rival->timer > rival->chase) {
            press |= pad_action_buttons;
            FUN_8c08267c(&rival->rival_motion->speed, &stroke, &ang);
            stroke = 1.0F;
            rival->timer = 0;
            rival->mode = RIVAL_READY;
        } else if ((rival->rival_work->flags & PLAYER_ATTACKING) !=
                   PLAYER_ATTACKING) {
            rival->timer = 0;
            rival->mode = RIVAL_READY;
        }
        break;
    case RIVAL_TAKE_OFF:
        ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                           NULL, NULL);
        stroke = RIVAL_NUDGE;
        if (rival->rival_work->flags & PLAYER_ON_GROUND) {
            press |= pad_jump_buttons;
            rival->mode = RIVAL_JUMP;
        }
        break;
    case RIVAL_JUMP:
        ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                           NULL, NULL);
        stroke = 1.0F;
        if (rival->rival_motion->speed.y > 0.0F) {
            on |= pad_jump_buttons;
        } else {
            press |= pad_jump_buttons;
            rival->timer = 0;
            rival->mode = RIVAL_GLIDE;
        }
        break;
    case RIVAL_GLIDE:
        ang = npc_angle_to(&rival->rival_work->pos, &rival->playertwp->pos,
                           NULL, NULL);
        rival->timer++;
        stroke = 0.5F;
        if (rival->rival_work->flags & PLAYER_ON_GROUND) {
            rival->timer = 0;
            if (knuckles_get_activity(1) == KNUCKLES_CLIMBING) {
                rival->mode = RIVAL_CLIMB;
            } else {
                rival->mode = RIVAL_READY;
            }
        } else {
            on |= pad_jump_buttons;
        }
        break;
    case RIVAL_CLIMB:
        stroke = 1.0F;
        perG[1].y1 = STICK_UP;
        if (knuckles_get_activity(1) != KNUCKLES_CLIMBING &&
            knuckles_get_activity(1) != KNUCKLES_CLIMBING_OUT) {
            rival->mode = RIVAL_READY;
        }
        break;
    }
    if (npc_players_clash(rival->rival_task, rival->player_task)) {
        rival->mode = RIVAL_WAIT;
        rival->phase = 0;
        rival->timer = 0;
        rival->rival_task->work->flags &= ~PLAYER_HURT;
        rival->player_task->work->flags &= ~PLAYER_HURT;
        rival_push_apart(0, 1, 1.0F);
        VibShot(0, 3, 50, 2);
    } else {
        flags = rival->rival_work->flags;
        if (!(flags & PLAYER_RECOILING) && (flags & PLAYER_HURT)) {
            rival->hits++;
            rival->timer = 0;
            rival->phase = 0;
            rival->mode = RIVAL_RECOIL;
            Serif_Play(0xa4);
        }
    }
    perG[1].on = on;
    perG[1].press = press;
    input_dataG[1].ang = ang;
    input_dataG[1].stroke = stroke;
    rival->ang = ang;
    rival->heading = ang;
    rival->stroke = stroke;
    rival->on = on;
    rival->press = press;
    rival_draw(task);
    LoopTaskC(task);
}
