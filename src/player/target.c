/* @unit 8C07D4A0-8C07DC20 +egflags +pool32 */
/* the targets a falling player steers onto, what players hold, and the
 * invincibility a player is granted */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "object/common.h"
#include "player/player.h"
#include "player/target.h"
#include "system/task.h"
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
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
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
void *syMalloc_default_malloc(size_t size);
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
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

#define INVINCIBLE_STEPS 120

/* player_add_target offers a target to players 0 and 1. a player takes it
 * only within TARGET_REACH of the target's surface */
#define TARGET_PLAYERS 2
#define TARGET_REACH 120.0F
/* steering needs its target within TARGET_ARC of the player's facing, and
 * a pushed stick within TARGET_ARC of the target */
#define TARGET_ARC 0x1800
/* a steered player facing within TURN_ARC of its target turns toward it by
 * TURN_STEP a step */
#define TURN_ARC 0x1000
#define TURN_STEP 0x100
/* steering follows the fall for up to FALL_STEPS steps, and gives up on a
 * fall its end test doesn't end within them */
#define FALL_STEPS 120
/* where steering aims a landing, in radii short of the target's center. a
 * landing past the center moves back to LONG_AIM short of it, and one more
 * than LONG_AIM short moves up to SHORT_AIM short */
#define LONG_AIM 0.75F
#define SHORT_AIM 0.5F

static void player_invincible_step(struct task *task)
{
    struct task_work *work = task->work;
    struct player *record = player_records[PLAYER_VARS(work)->player];

    TASK_TIMER(work)++;
    if (TASK_TIMER(work) > INVINCIBLE_STEPS) {
        if (record != NULL) {
            record->effects &= ~PLAYER_INVINCIBLE;
        }
        FreeTask(task);
    } else if (record != NULL) {
        /* @hack spelling: player_records[] read again, though record holds the
         * same pointer (MOV.L @(R0,R7),R2 at 0x8c08211a); through record, 26
         * of 35 words differ */
        player_records[PLAYER_VARS(work)->player]->effects |= PLAYER_INVINCIBLE;
    }
}

void player_grant_invincibility(Uint8 player)
{
    struct task *task;

    /* @bug memory: for a player above 7, the test reads player_work[player]
     * past the table's end (MOV.L at 0x8c082140). it holds only for such a
     * player (CMP/GT at 0x8c082136), so a player of 1 to 7 with no work keeps
     * its number */
    /* @hack redundant: player >= 1, the CMP/GE at 0x8c082130, adds nothing to
     * player > 7; without it, 28 of 31 words differ */
#ifdef GCC
    /* repairs the read the tag names, as player.c's
     * player_give_invincibility does */
    if (player > PLAYER_COUNT - 1) {
        player = 0;
    }
#else
    /* NOLINTNEXTLINE(misc-redundant-expression) */
    if (player >= 1 && player > 7 && playertwp[player] == NULL) {
        player = 0;
    }
#endif
    task = CreateElementalTask(TASK_WORK, 0, player_invincible_step);
    if (task != NULL) {
        PLAYER_VARS(task->work)->player = player;
    }
}

void player_set_held_kind(Uint8 player, Sint8 kind)
{
    struct task_work *work = playertwp[player];

    player_held_kinds[PLAYER_VARS(work)->character] = kind;
}

int player_get_held_kind(Uint8 player)
{
    struct task_work *work = playertwp[player];

    return player_held_kinds[PLAYER_VARS(work)->character];
}

void player_hand_task(Uint8 player, struct task *task)
{
    struct task_work *work = playertwp[player];

    work->flags |= PLAYER_REQUEST;
    work->submode = PLAYER_MODE_HOLD;
    PLAYER_VARS(work)->arg.carry = task;
}

void player_drop_held(Uint8 player)
{
    struct task_work *work = playertwp[player];
    struct player *record = player_records[player];

    if (work != NULL && (work->flags & PLAYER_HOLDING) &&
        record->held != NULL) {
        work->flags &= ~PLAYER_HOLDING;
        if (record->held->work != NULL) {
            record->held->work->flags &= ~CARRY_HELD;
        }
        record->held = NULL;
    }
}

void player_targets_alloc(struct player *record)
{
    record->targets = CAlloc(PLAYER_TARGETS, sizeof(struct player_target));
    record->target_count = 0;
}

void player_targets_free(struct player *record)
{
    if (record->targets != NULL) {
        Free(record->targets);
        record->targets = NULL;
    }
}

void player_add_target(Float x, Float y, Float z, Float radius)
{
    int i;
    struct task_work *work;
    struct player *record;
    Float distance;
    int index;

    for (i = 0; i < TARGET_PLAYERS; i++) {
        work = playertwp[i];
        if (work == NULL) {
            continue;
        }
        if (work->pos.y < y) {
            continue;
        }
        record = player_records[i];
        distance = (x - work->pos.x) * (x - work->pos.x);
        distance += (y - work->pos.y) * (y - work->pos.y);
        distance += (z - work->pos.z) * (z - work->pos.z);
        distance = njSqrt(distance) - radius;
        if (distance > TARGET_REACH) {
            continue;
        }
        if (record->target_count >= PLAYER_TARGETS) {
            continue;
        }
        index = record->target_count;
        record->targets[index].pos.x = x;
        record->targets[index].pos.y = y;
        record->targets[index].pos.z = z;
        record->targets[index].radius = radius;
        record->targets[index].distance = distance;
        record->target_count++;
        return;
    }
}

Bool player_steer_to_target(struct task_work *work, struct task_motion *motion,
                            struct player *record)
{
    NJS_POINT3 pos;
    NJS_VECTOR gravity;
    NJS_VECTOR speed;
    struct player_target *target;
    struct player_target *best;
    int i;
    Angle ang;
    Angle off;
    Angle facing;
    Angle aim;
    Float distance;
    Float steps;
    best = ((void *)0);
    pos = work->pos;
    for (i = 0; i < record->target_count; i++) {
        target = &record->targets[i];
        if (pos.y < target->pos.y) {
            continue;
        }
        ang = (Angle)(njArcTan2(target->pos.z - pos.z, target->pos.x - pos.x) *
                      ANGLE_PER_RADIAN);
        off = angle_difference(work->ang.y, ang);
        /* past TARGET_ARC, a target still competes while the player lies
         * within its radius in x and z */
        if (off > TARGET_ARC || off < -TARGET_ARC) {
            distance = (target->pos.z - pos.z) * (target->pos.z - pos.z);
            distance += (target->pos.x - pos.x) * (target->pos.x - pos.x);
            distance = njSqrt(distance);
            if (distance > target->radius) {
                continue;
            }
        }
        if (best != NULL && best->distance < target->distance) {
            continue;
        }
        target->off = off;
        target->ang = ang;
        best = target;
    }
    if (best == NULL) {
        return FALSE;
    }
    /* the nearest must lie within TARGET_ARC of the player's facing, and
     * the player must have been outside its sphere as player_add_target
     * listed it */
    off = best->off;
    if (off > TARGET_ARC || off < -TARGET_ARC || best->distance < 0.0F) {
        return FALSE;
    }
    /* player_turn_to_stick for the stick's aim alone: the player's facing
     * and aim go back as they were */
    facing = work->ang.y;
    aim = motion->aim.y;
    player_turn_to_stick(work, motion, record);
    work->ang.y = facing;
    ang = motion->aim.y;
    motion->aim.y = aim;
    off = DiffAngle(ang, best->ang);
    if (off > TARGET_ARC) {
        return FALSE;
    }
    ang = best->ang;
    pos.x -= best->pos.x;
    pos.y -= best->pos.y;
    pos.z -= best->pos.z;
    best->across = njSqrt((pos.x * pos.x) + (pos.z * pos.z));
    speed = motion->speed;
    gravity.x = 0.0F;
    gravity.y = -record->consts.gravity;
    gravity.z = 0.0F;
    /* follow the fall step by step, by the player's constants, to the end
     * the test below takes. the speed in x and z that corrects the landing
     * is spread over the steps the fall takes. each axis of it is held
     * within ground_accel */
    i = 0;
    do {
        speed.x += (record->consts.air_resist * speed.x) + gravity.x;
        speed.y += (record->consts.resist.y * speed.y) + gravity.y;
        speed.z += (record->consts.resist.z * speed.z) + gravity.z;
        if (speed.y < -record->consts.fall_limit) {
            speed.y = -record->consts.fall_limit;
        }
        pos.x += speed.x;
        pos.y += speed.y;
        pos.z += speed.z;
        /* @bug logic: pos.y is the height above the target's center
         * (FSUB at 0x8c0824e0), but the test takes the center's own height,
         * best->pos.y, for the center (FCMP/GT at 0x8c0825f2). the fall ends
         * once the height above the center drops to the center's height,
         * not to 0 */
        if (pos.y > best->pos.y) {
            continue;
        }
        pos.x += best->pos.x - work->pos.x;
        pos.z += best->pos.z - work->pos.z;
        distance = njSqrt((pos.x * pos.x) + (pos.z * pos.z));
        if (distance > best->across) {
            distance = best->across - (best->radius * LONG_AIM) - distance;
            speed.x = distance * njCos(ang);
            speed.y = 0.0F;
            speed.z = distance * njSin(ang);
        } else if (distance > best->across - (best->radius * LONG_AIM)) {
            /* a landing less than LONG_AIM radii short of the center
             * stands. but where the square of the fall's speed in x and z
             * passes running_speed, steering aims it at the target's near
             * edge */
            if ((speed.x * speed.x) + (speed.z * speed.z) >
                record->consts.running_speed) {
                distance = best->across - best->radius - distance;
                speed.x = distance * njCos(ang);
                speed.y = 0.0F;
                speed.z = distance * njSin(ang);
            } else {
                speed.x = speed.y = speed.z = 0.0F;
            }
        } else {
            distance = best->across - (best->radius * SHORT_AIM) - distance;
            speed.x = distance * njCos(ang);
            speed.y = 0.0F;
            speed.z = distance * njSin(ang);
        }
        steps = (Float)i + 1.0F;
        speed.x /= steps;
        speed.z /= steps;
        if (speed.x > record->consts.ground_accel) {
            speed.x = record->consts.ground_accel;
        }
        if (speed.x < -record->consts.ground_accel) {
            speed.x = -record->consts.ground_accel;
        }
        if (speed.z > record->consts.ground_accel) {
            speed.z = record->consts.ground_accel;
        }
        if (speed.z < -record->consts.ground_accel) {
            speed.z = -record->consts.ground_accel;
        }
        motion->accel.x += speed.x;
        motion->accel.z += speed.z;
        off = best->off;
        if (off < TURN_ARC && off > -TURN_ARC) {
            work->ang.y = AdjustAngle(work->ang.y, best->ang, TURN_STEP);
        }
        player_accel_roll(work, motion, record);
        return TRUE;
    } while (++i < FALL_STEPS);
    return FALSE;
}
Float CalcDistance(NJS_POINT3 *a, NJS_POINT3 *b);
struct lure_a {
    char pad[20];
    Float f;
};
struct lure_c {
    Uint8 pad0[12];
    char *q;
};
void setLureCameraPos(struct task_work *a, struct task_work *b, char *c)
{
    struct lure_c *p = (struct lure_c *)b->collision;
    NJS_POINT3 v;
    Float r;
    if (p != 0) {
        r = *(Float *)(c + 268) + ((struct lure_a *)(p->q + 52))->f;
        if (CalcDistance(&a->pos, &b->pos) < r) {
            v = b->pos;
            njSubVector(&v, &a->pos);
            v.y = 0;
            njUnitVector(&v);
            b->pos.x = a->pos.x + v.x * r;
            b->pos.z = a->pos.z + v.z * r;
        }
    }
}
