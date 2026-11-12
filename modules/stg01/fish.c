/* @unit 0C90D9C0-0C90F3E0 +r04 +egflags +pool32 */
/* the fish of Big's stages. Emerald Coast, Twinkle Park, Ice Cap and Hot
 * Shelter each link this source. S GENE and S BASS run generators, each of
 * which keeps a fish swimming where it stands. a fish takes the lure, fights
 * and is landed */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "player/big.h"
#include "player/fish.h"
#include "player/fishing.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "stg01/fish.h"
#include "stg01/fish_models.h"
#include "system/task.h"
#include "system/util.h"
#include "vmu/vibration.h"
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
void *syMalloc_default_malloc(size_t size);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
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
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
void FUN_8c0ec920(struct task *task);
void BigSakana(struct task *task);
struct task *SetFishingCursorTask(struct task *big);
int FUN_8c0e6dc0(void);
Float FUN_8c0eb4f0(void);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
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
void kmiLogFileOpen(void *data);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
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
void FUN_0c90d9c0(struct task *task);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
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

#define FISH_KINDS 16
/* the one kind drawn with a second model, fish_an_ke's */
#define KIND_AN 8
/* the kind whose scale_max Twinkle Park raises to 2 */
#define KIND_MS 12

/* the lures Big can find */
#define LURES 4

/* the distance within which fish_step keeps a fish and fish_generator_step
 * makes one */
#define FISH_NEAR 400.0F

/* the weight at or above which fish_weigh may draw a fish's weight at
 * random */
#define HEAVY 2350

/* the steps a generator rests once Big lands its fish */
#define REST_STEPS 18000

#define SE_KICK 801
#define SE_HOOKED 1312

/* a fighting fish takes a new aim every TURN_MIN to TURN_MAX steps, at
 * random. the aim lies AIM_OFF to one side or the other of the lure's
 * heading. each new aim may start a kick, which lasts at most KICK_STEPS. a
 * kick's chance is KICK_CHANCE while fishing_fight_steps is under KICK_LATE,
 * and 0 after. the chance gains KICK_PER_WEIGHT for each unit of weight above
 * KICK_WEIGHT, and loses as much for each below */
#define TURN_MIN 60.0F
#define TURN_MAX 120.0F
#define AIM_OFF NJM_DEG_ANG(67.5)
#define KICK_STEPS 120
#define KICK_CHANCE 0.2F
#define KICK_LATE 900
#define KICK_WEIGHT 600.0F
#define KICK_PER_WEIGHT 0.000125F
/* how far a fish turns toward its aim each step, 65536 a turn. FIGHT_TURN
 * holds in a fight, BACK_TURN once turned back, and HOME_TURN on its way home
 * and once there */
#define FIGHT_TURN 0x100
#define BACK_TURN 0x200
#define HOME_TURN 0x80
/* a fish arriving home takes its aim as its heading once the heading lies less
 * than ARRIVE_ABOVE above the aim, or less than ARRIVE_BELOW below it */
#define ARRIVE_ABOVE 80
#define ARRIVE_BELOW 0x80

/* a fish's task->extra: a copy of its kind's action, and the generator that
 * made it. the copy draws the kind's own model */
#define GENERATOR_VARS(work) ((struct generator_vars *)&(work)->vars)
#define FISH_SIZE(length, shortest, longest)                                   \
    {(length), (shortest) / (length), (longest) / (length), (length) * 100.0F}
struct fish_extra {
    NJS_ACTION action;
    struct task *generator;
};

/* a generator's work->vars: its fish while it lives, and the steps left of
 * its rest */
struct generator_vars {
    Uint8 unk_00[4];
    Sint32 rest_steps;
    struct task *fish;
};

enum generator_mode {
    GENERATOR_INIT,
    GENERATOR_WAIT,
    GENERATOR_SWIMMING,
    GENERATOR_REST
};

/* a fish wanders by its generator until the lure draws it, then chases the
 * lure and bites. Big's pull starts the fight, or for a fish of size class 0
 * the bite alone. the fight lasts until he lands the fish or it gets away. a
 * fish that lets go swims home */
enum fish_mode {
    FISH_INIT,
    FISH_WANDER,
    FISH_RETURN, /* swimming home to its generator */
    FISH_ARRIVE, /* home, turning to face as its generator does */
    FISH_CHASE,
    FISH_BITE, /* biting, until a pull starts the fight, or at once for size
                * class 0 */
    FISH_FIGHT,
    FISH_FIGHT_BACK, /* turned about where the world pushed it up */
    FISH_CLOSE, /* fighting with the lure within 100 of player 0 */
    FISH_LANDED
};

/* the action a fish plays, which work->tick holds */
enum fish_anim { ANIM_SWIM, ANIM_BITE, ANIM_HOOKED };

/* a kind's size. FISH_SIZE makes one from three lengths: the kind's at scale
 * 1, and its shortest and longest. fish_choose_scale draws a scale between
 * theirs */
struct fish_size {
    Float length; /* at scale 1 */
    Float scale_min;
    Float scale_max;
    Float weight; /* at scale 1: 100 for each unit of length */
};
extern int fish_kind_counts[4];
extern int beach_fish_kinds[8];
extern int twinkle_fish_kinds[3];
extern int icecap_fish_kinds[6];
extern int shelter_fish_kinds[6];
extern NJS_TEXLIST *fish_texlists[16];
extern NJS_OBJECT *fish_objects[16];
extern NJS_ACTION *fish_swim_actions[16];
extern NJS_ACTION *fish_hooked_actions[16];
extern NJS_ACTION *fish_bite_actions[16];
extern NJS_VECTOR fish_model_offsets[16];
extern NJS_VECTOR fish_held_small[16];
extern NJS_VECTOR fish_held_medium[16];
extern NJS_VECTOR fish_held_large[16];
extern struct fish_size fish_sizes[16];
extern struct collision_shape fish_shapes[];
/* clang-format on */

void fish_init(struct task *task);
void fish_set_action(struct task *task, Uint8 anim);
void fish_weigh(struct task *task);
void fish_choose_kind(struct task *task, int number);
void fish_choose_scale(struct task *task);
int fish_classify(struct task *task);
Bool fish_chase(struct task *task, struct task *target);
void fish_step(struct task *task);
void fish_draw(struct task *task);
void fish_destroy(struct task *task);
void fish_generator_destroy(struct task *task);

void FUN_0c90d9c0(struct task *task)
{
    fish_generator_step(task);
}

/* the fish's first step. unless fish_spawn chose its kind, it chooses one at
 * random. then it sets the fish's scale, size class and weight */
void fish_init(struct task *task)
{
    struct task_work *work = task->work;
    struct fish_extra *extra;

    task->step = fish_step;
    task->draw = fish_draw;
    task->destructor = fish_destroy;
    if (FISH_VARS(work)->kind <= 0 || FISH_VARS(work)->kind >= FISH_KINDS) {
        fish_choose_kind(task, 0);
    }
    fish_choose_scale(task);
    fish_classify(task);
    fish_weigh(task);
    /* @hack redundant: task->extra read and stored back, MOV.L @(44,R14),R4 and
     * MOV.L R4,@(44,R14) at 0x0c90e0fa and 0x0c90e0fe; without it, 6 of 32
     * words differ */
    extra = task->extra;
    task->extra = extra;
    fish_set_action(task, ANIM_SWIM);
}

/* set work->tick to anim, and the fish's action to its own copy of its
 * kind's action for anim. the copy draws the kind's own model */
void fish_set_action(struct task *task, Uint8 anim)
{
    struct task_work *work = task->work;
    struct fish_extra *extra = task->extra;

    work->tick = anim;
    if (anim == ANIM_SWIM) {
        extra->action = *fish_swim_actions[FISH_VARS(work)->kind];
    } else if (anim == ANIM_BITE) {
        extra->action = *fish_bite_actions[FISH_VARS(work)->kind];
    } else {
        extra->action = *fish_hooked_actions[FISH_VARS(work)->kind];
    }
    extra->action.object = fish_objects[FISH_VARS(work)->kind];
    FISH_VARS(work)->action = &extra->action;
}

/* set the fish's weight: its kind's weight times its scale, rounded up to a
 * multiple of 10. once fishing_record_weight is HEAVY or more, a fish that
 * heavy weighs a random amount instead. that amount runs from the kind's
 * weight at 1.2 times scale_max up to 20 past fishing_record_weight. the
 * random amount rounds up to a multiple of 10 too */
void fish_weigh(struct task *task)
{
    struct task_work *work = task->work;
    Float weight;
    Float most;
    Float scaled;
    Float scaled_most;
    Float record;
    Float chosen;
    Float scale_max;
    struct fish_size *size;

    scaled = fish_sizes[FISH_VARS(work)->kind].weight * work->scl.x;
    weight = ceilf(scaled * 0.1F) * 10.0F;
    /* @hack spelling: the row's address taken inside the read, which gives
     * scaled_most its slot at R15+8 (MOV #8,R0 at 0x0c90e1d8); as a statement
     * of its own, 2 of 99 words differ */
    scale_max = (size = &fish_sizes[FISH_VARS(work)->kind])->scale_max;
    scaled_most = size->weight * scale_max * 1.2F;
    most = ceilf(scaled_most * 0.1F) * 10.0F;
    if (fishing_record_weight >= HEAVY && weight >= HEAVY) {
        record = fishing_record_weight + 20;
        chosen = ((record - most) * rand() * (1.0F / (32767 + 1))) + most;
        weight = ceilf(chosen * 0.1F) * 10.0F;
    }
    FISH_MOTION(task)->weight = weight;
}

/* set the fish's kind from the stage's list. a number from 1 up to the
 * list's count picks that entry, and any other a random one. until Big has
 * every lure, a random entry leaves out the list's last */
void fish_choose_kind(struct task *task, int number)
{
    struct task_work *work = task->work;
    int count;
    int entry;

    if (IN_STAGE(STAGE_BEACH)) {
        count = fish_kind_counts[0];
        if (number > 0 && number <= count) {
            entry = number - 1;
        } else {
            if (FUN_8c0e6dc0() != 4) {
                --count;
            }
            entry = rand() * (Float)count * RAND_SCALE;
        }
        FISH_VARS(work)->kind = beach_fish_kinds[entry];
    } else if (IN_STAGE(STAGE_TWINKLE)) {
        count = fish_kind_counts[1];
        if (number > 0 && number <= count) {
            entry = number - 1;
        } else {
            if (FUN_8c0e6dc0() != 4) {
                --count;
            }
            entry = rand() * (Float)count * RAND_SCALE;
        }
        FISH_VARS(work)->kind = twinkle_fish_kinds[entry];
    } else if (IN_STAGE(STAGE_ICECAP)) {
        count = fish_kind_counts[2];
        if (number > 0 && number <= count) {
            entry = number - 1;
        } else {
            if (FUN_8c0e6dc0() != 4) {
                --count;
            }
            entry = rand() * (Float)count * RAND_SCALE;
        }
        FISH_VARS(work)->kind = icecap_fish_kinds[entry];
    } else {
        count = fish_kind_counts[3];
        if (number > 0 && number <= count) {
            entry = number - 1;
        } else {
            if (FUN_8c0e6dc0() != 4) {
                --count;
            }
            entry = rand() * (Float)count * RAND_SCALE;
        }
        FISH_VARS(work)->kind = shelter_fish_kinds[entry];
    }
}

/* set work->scl.x, the fish's scale, at random. it runs from the kind's
 * scale_min up to 1, or from 1 up to its scale_max. either range is as
 * likely. with work->scl.z set, as its generator's was, it runs from twice
 * scale_min up to scale_max instead. then the lures Big has make it
 * larger */
void fish_choose_scale(struct task *task)
{
    struct task_work *work = task->work;
    Float scale;
    Float least = fish_sizes[FISH_VARS(work)->kind].scale_min;
    Float most = fish_sizes[FISH_VARS(work)->kind].scale_max;

    if (IN_STAGE(STAGE_TWINKLE) && FISH_VARS(work)->kind == KIND_MS) {
        most = 2.0F;
    }
    if (work->scl.z) {
        least = least * 2.0F;
        scale = ((most - least) * rand() * RAND_SCALE) + least;
    } else if (rand() * RAND_SCALE < 0.5F) {
        scale = ((1.0F - least) * rand() * RAND_SCALE) + least;
    } else {
        scale = ((most - 1.0F) * rand() * RAND_SCALE) + 1.0F;
    }
    /* two lures scale the fish less than one does */
    switch (FUN_8c0e6dc0()) {
    case 0:
        break;
    case 2:
        scale *= 1.05F;
        break;
    case 1:
        scale *= 1.1F;
        break;
    case 3:
        scale *= 1.15F;
        break;
    case 4:
        scale *= 1.2F;
        break;
    }
    work->scl.x = scale;
}

/* set work->scl.y to the fish's size class, by its length. the class is 0
 * under 10, 1 under 14, and 2 for the rest. the result is the class too */
int fish_classify(struct task *task)
{
    struct task_work *work = task->work;
    Float size = fish_sizes[FISH_VARS(work)->kind].length * work->scl.x;

    if (size < 10.0F) {
        size = 0.0F;
    } else if (size < 14.0F) {
        size = 1.0F;
    } else {
        size = 2.0F;
    }
    work->scl.y = size;
    return (int)size;
}

/* a step of the fish's fight. once turn_steps runs out, the fish sets it
 * again, takes a new aim and may kick. between, the fish turns toward its
 * aim, which fish_keep_ahead_of_player may set while it kicks */
void fish_fight(struct task *task)
{
    struct task_work *work = task->work;
    struct fish_motion *motion = FISH_MOTION(task);
    Float chance;
    int steps;
    int limit;

    if (--FISH_VARS(work)->turn_steps <= 0) {
        if (work->mode == FISH_FIGHT_BACK) {
            work->mode = FISH_FIGHT;
        }
        FISH_VARS(work)->turn_steps = RANDOM(TURN_MIN, TURN_MAX);
        motion->aim.y = big_lure->motion->aim.y;
        if (rand() * RAND_SCALE < 0.5F) {
            motion->aim.y += AIM_OFF;
        } else {
            motion->aim.y -= AIM_OFF;
        }
        motion->aim.y &= 0xffff;
        /* @hack spelling: the limit and fishing_fight_steps through locals,
         * which has SHC load both ahead of the mask's AND (0x0c90e67a,
         * 0x0c90e680); compared in place, 7 of 155 words differ */
        limit = KICK_LATE;
        steps = fishing_fight_steps;
        chance = steps < limit ? KICK_CHANCE : 0.0F;
        chance += (motion->weight - KICK_WEIGHT) * KICK_PER_WEIGHT;
        if (rand() * RAND_SCALE < chance) {
            work->timer = KICK_STEPS;
            fishing_flags |= FISHING_KICK;
            fish_set_action(task, ANIM_HOOKED);
            dsPlay_oneshot(SE_KICK, 0, 0, 0);
            VibShot(0, 5, 15, 4);
        } else {
            VibShot(0, 1, 15, 5);
        }
        return;
    }
    if (fishing_flags & FISHING_KICK) {
        chkAngLimit(task, &work->pos);
    }
    if (work->ang.y - motion->aim.y < 0) {
        work->ang.y += FIGHT_TURN;
    } else {
        work->ang.y -= FIGHT_TURN;
    }
    work->ang.y &= 0xffff;
}

/* a step of the fight of a fish the world turned back. it stays at the hook
 * and turns toward its aim until turn_steps runs out. then it fights on as
 * FISH_FIGHT, and may kick as fish_fight says. it aims AIM_OFF off the
 * reverse of the lure's heading, to one side or the other */
void fish_fight_back(struct task *task)
{
    struct task_work *work = task->work;
    struct fish_motion *motion = FISH_MOTION(task);
    Float chance;
    int steps;
    int limit;

    if (--FISH_VARS(work)->turn_steps <= 0) {
        work->mode = FISH_FIGHT;
        FISH_VARS(work)->turn_steps = RANDOM(TURN_MIN, TURN_MAX);
        motion->aim.y = big_lure->motion->aim.y + NJM_DEG_ANG(180);
        if (rand() * RAND_SCALE < 0.5F) {
            motion->aim.y += AIM_OFF;
        } else {
            motion->aim.y -= AIM_OFF;
        }
        motion->aim.y &= 0xffff;
        /* @hack spelling: the limit and fishing_fight_steps through locals,
         * which has SHC load both ahead of the mask's AND (0x0c90e832,
         * 0x0c90e838); compared in place, 18 of 159 words differ */
        limit = KICK_LATE;
        steps = fishing_fight_steps;
        if (steps < limit) {
            chance = 0.2F;
        } else {
            chance = 0.0F;
        }
        chance += (motion->weight - 600.0F) * 0.000125F;
        if (0) {
            fishing_flags = 0;
        }
        if (rand() * RAND_SCALE < chance) {
            work->timer = KICK_STEPS;
            fishing_flags |= FISHING_KICK;
            fish_set_action(task, ANIM_HOOKED);
            dsPlay_oneshot(SE_KICK, 0, 0, 0);
            VibShot(0, 5, 15, 4);
        } else {
            fishing_flags &= ~FISHING_KICK;
            VibShot(0, 1, 15, 5);
            fish_set_action(task, ANIM_HOOKED);
        }
    }
    if (work->ang.y - motion->aim.y < 0) {
        work->ang.y += BACK_TURN;
    } else {
        work->ang.y -= BACK_TURN;
    }
    work->ang.y &= 0xffff;
    fishing_hook_point(&work->pos);
    motion->speed.x = motion->speed.y = motion->speed.z = 0.0F;
}

void fish_turn_to_aim(struct task *task)
{
    struct task_work *work = task->work;
    struct fish_motion *motion = FISH_MOTION(task);

    if ((Uint16)(work->ang.y - motion->aim.y) > NJM_DEG_ANG(180)) {
        work->ang.y += FIGHT_TURN;
    } else {
        work->ang.y -= FIGHT_TURN;
    }
    work->ang.y &= 0xffff;
}

/* @hack spelling: the size class, work->scl.y as an int, read through an
 * inline function, which reads task->work again at each call (MOV.L
 * @(32,R4),R5 at 0x0c90ea7a and 0x0c90eeea). read in place, summed over
 * fish_fight_close and fish_carry, 338 of 353 words differ */
static int fish_size_class(struct task *task)
{
    return (int)task->work->scl.y;
}

/* a step of a fish fighting close to Big. it stays at the hook and sweeps a
 * short way ahead. TRUE once that sweep hits the world. TRUE too once the
 * lure is out past 130 from player 0, plus 30 for each size class. FALSE
 * otherwise */
Bool fish_fight_close(struct task *task)
{
    struct task_work *work = task->work;
    struct fish_motion *motion = FISH_MOTION(task);
    NJS_MATRIX matrix;
    NJS_VECTOR ahead;
    NJS_POINT3 pos;
    /* @hack redundant: a point and a vector never used, which give the frame
     * 120 bytes (ADD #-120,R15 at 0x0c90ea08); without them, 11 of 88 words
     * differ */
    NJS_POINT3 unused_pos;
    NJS_VECTOR unused_ahead;
    Angle ang;
    Bool hit;
    Float limit;
    Float size;

    ahead.y = 0.0F;
    ahead.z = 0.0F;
    ahead.x = -0.3F;
    njUnitMatrix(&matrix);
    TURN_MATRIX_VIA(njRotateY, &matrix, work->ang.y, ang);
    njCalcVector(&matrix, &ahead, &motion->speed);
    pos = work->pos;
    hit = MSetPosition(&pos, &motion->speed, NULL, FISH_RADIUS);
    fishing_hook_point(&work->pos);
    size = fish_size_class(task);
    limit = 130.0F + (30.0F * size);
    if (FUN_8c0eb4f0() > limit) {
        hit = TRUE;
    }
    return hit;
}

/* swim the fish at target, the lure or its generator, at least 0.1 under the
 * water's surface. TRUE while the chase goes on. the fish holds still while
 * its aim is more than 22.5 degrees off its heading. FALSE ends the chase:
 * with no target, or where the world blocks the swim. for a target that is
 * big_catch, it ends while FISHING_CAMERA is clear or FISHING_BOTTOM set. it
 * ends too while the fish is within 50 of player 0. no caller passes
 * big_catch, so those tests never run */
Bool fish_chase(struct task *task, struct task *target)
{
    struct fish_motion *motion = FISH_MOTION(task);
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    struct task_work *at;
    NJS_VECTOR away;
    NJS_POINT3 pos;
    /* @hack redundant: a point never used, which gives the frame 44 bytes (ADD
     * #-44,R15 at 0x0c90eb0a); without it, 11 of 174 words differ */
    NJS_POINT3 unused_pos;
    Angle off;
    Float step;

    njScalor(&motion->speed);
    if (!target) {
        return FALSE;
    } else {
        at = target->work;
    }
    /* @hack spelling: the jumps to test and back to steer, which load target's
     * work (MOV.L @(32,R11),R12 at 0x0c90eb26) ahead of the test against
     * big_catch, not in its branch's slot; as one test, 20 of 174 words
     * differ */
    goto test;
untested:
    goto steer;
test:
    if (target != big_catch) {
        goto untested;
    }
    if (!(fishing_flags & FISHING_CAMERA) || (fishing_flags & FISHING_BOTTOM) ||
        CalcDistance(&work->pos, &player->pos) < 50.0F) {
        return FALSE;
    }
steer:
    away.x = at->pos.x - work->pos.x;
    away.y = at->pos.y - work->pos.y;
    away.z = at->pos.z - work->pos.z;
    off = work->ang.y - motion->aim.y;
    if (off < 0) {
        off += 0x10000;
    }
    if (off > NJM_DEG_ANG(22.5) && off < NJM_DEG_ANG(337.5)) {
        return TRUE;
    }
    njUnitVector(&away);
    step = -0.4F;
    motion->speed.x = -(away.x * step);
    motion->speed.y = -(away.y * step);
    motion->speed.z = -(away.z * step);
    pos = work->pos;
    if (MSetPosition(&pos, &motion->speed, NULL, FISH_RADIUS)) {
        return FALSE;
    }
    motion->speed.x *= 0.5F;
    motion->speed.y *= 0.5F;
    motion->speed.z *= 0.5F;
    work->pos.x += motion->speed.x;
    work->pos.y += motion->speed.y;
    if (work->pos.y > motion->surface - 0.1F) {
        work->pos.y = motion->surface - 0.1F;
    }
    work->pos.z += motion->speed.z;
    return TRUE;
}

/* the fish on the hook pulls the lure along its heading, and itself moves to
 * the hook. a kicking fish pulls twice as fast on half its steps. where its
 * sweep turns it up, it stops and turns about. a fighting fish then fights
 * back for 64 steps. once its timer runs out, FISHING_KICK clears */
void fish_pull(struct task *task)
{
    struct task_work *work = task->work;
    struct fish_motion *motion = FISH_MOTION(task);
    NJS_MATRIX matrix;
    NJS_VECTOR move;
    NJS_POINT3 pos;
    Angle ang;
    Bool hit;

    if (!big_lure) {
        return;
    }
    move.y = -0.002F;
    move.z = 0.0F;
    move.x = -0.4F;
    if ((fishing_flags & FISHING_KICK) && rand() * RAND_SCALE < 0.5F) {
        move.x = -0.8F;
    }
    njUnitMatrix(&matrix);
    TURN_MATRIX_VIA(njRotateY, &matrix, work->ang.y, ang);
    njCalcVector(&matrix, &move, &motion->speed);
    pos = work->pos;
    hit = MSetPosition(&pos, &motion->speed, NULL, FISH_RADIUS);
    if (hit && motion->speed.y > 0.0F) {
        FISH_VARS(work)->turn_steps = 64;
        motion->aim.y = (Uint16)(motion->aim.y + NJM_DEG_ANG(180));
        if (work->mode == FISH_FIGHT) {
            work->mode = FISH_FIGHT_BACK;
        }
        fishing_flags &= ~FISHING_KICK;
        motion->speed.x = motion->speed.y = motion->speed.z = 0.0F;
    }
    motion->speed.x *= 0.5F;
    motion->speed.y *= 0.5F;
    motion->speed.z *= 0.5F;
    fishing_hook_point(&work->pos);
    if (work->timer) {
        --work->timer;
    } else {
        fishing_flags &= ~FISHING_KICK;
        fish_set_action(task, ANIM_HOOKED);
    }
}

/* lay the landed fish on its side, swimming */
void fish_land(struct task *task)
{
    struct task_work *work = task->work;

    work->ang.x = work->ang.y = 0;
    work->ang.z = NJM_DEG_ANG(90);
    fish_set_action(task, ANIM_SWIM);
}

/* hold the fish in player 0's hand. it sits at his weld_point0, raised by
 * his center_y, plus its held offset, turned as he is. a fish of size class
 * 0 lies on its side. a larger one is held level */
void fish_carry(struct task *task)
{
    struct player *record = playermwp[0]->record;
    struct task_work *player = playertwp[0];
    struct task_work *work = task->work;
    NJS_VECTOR hand;
    NJS_VECTOR offset;
    Angle ang;

    njPushMatrix(&nj_unit_matrix_);
    TURN_VIA(njRotateZ, player->ang.z, ang);
    TURN_VIA(njRotateX, player->ang.x, ang);
    TURN_VIA(njRotateY, NJM_DEG_ANG(180) - player->ang.y, ang);
    hand.x = record->weld_point0.x;
    hand.y = record->weld_point0.y + record->consts.center_y;
    hand.z = record->weld_point0.z;
    switch (fish_size_class(task)) {
    case 0:
    default:
        hand.x += fish_held_small[FISH_VARS(work)->kind].x;
        hand.y += fish_held_small[FISH_VARS(work)->kind].y;
        hand.z += fish_held_small[FISH_VARS(work)->kind].z;
        break;
    case 1:
        hand.x += fish_held_medium[FISH_VARS(work)->kind].x;
        hand.y += fish_held_medium[FISH_VARS(work)->kind].y;
        hand.z += fish_held_medium[FISH_VARS(work)->kind].z;
        break;
    case 2:
        hand.x += fish_held_large[FISH_VARS(work)->kind].x;
        hand.y += fish_held_large[FISH_VARS(work)->kind].y;
        hand.z += fish_held_large[FISH_VARS(work)->kind].z;
        break;
    }
    njCalcVector(NULL, &hand, &offset);
    late_DrawObjectClipEx(1);
    work->pos.x = player->pos.x + offset.x;
    work->pos.y = player->pos.y + offset.y;
    work->pos.z = player->pos.z + offset.z;
    switch (fish_size_class(task)) {
    case 0:
        work->ang.z = NJM_DEG_ANG(90);
        work->ang.x = NJM_DEG_ANG(90) - player->ang.y;
        break;
    case 1:
    case 2:
    default:
        work->ang.z = 0;
        work->ang.y = NJM_DEG_ANG(90) - player->ang.y;
        work->ang.x = work->ang.z = 0;
        break;
    }
}

/* swim the fish home to its generator, turning toward it. TRUE once it is
 * within 3 of the generator. it then takes the generator's position, and aims
 * as the generator faces. FALSE until then, and with no extra */
Bool fish_return(struct task *task)
{
    struct task_work *work = task->work;
    struct fish_motion *motion = FISH_MOTION(task);
    struct fish_extra *extra;
    struct task *generator;
    NJS_VECTOR away;

    if (task->extra == NULL) {
        return FALSE;
    }
    extra = task->extra;
    /* @bug uninitialized: with extra->generator null, generator and away stay
     * unset. the BT at 0x0c90f142 skips their reads, and the aim then reads
     * generator->work through R13, which holds whatever the caller left
     * (0x0c90f170). STG03, STG08 and STG12 link the same code, with the BT at
     * 0x0c90b7a2, 0x0c9144c2 and 0x0c918342 and the read at 0x0c90b7d0,
     * 0x0c9144f0 and 0x0c918370. fish_spawn, the only creator of a fish,
     * always stores its generator (0x0c90fb18), so the path never runs */
#ifdef GCC
    /* repairs the reads the tag names: a fish with no generator has no home
     * to reach, so it returns FALSE, as one with no extra does */
    if (extra->generator == NULL) {
        return FALSE;
    }
#endif
    /* NOLINTNEXTLINE(clang-diagnostic-sometimes-uninitialized) */
    if (extra->generator != NULL) {
        generator = extra->generator;
        away.x = generator->work->pos.x - work->pos.x;
        away.y = generator->work->pos.y - work->pos.y;
        away.z = generator->work->pos.z - work->pos.z;
    }
    motion->aim.y = ((Angle)(njArcTan2(work->pos.x - generator->work->pos.x,
                                       work->pos.z - generator->work->pos.z) *
                             ANGLE_PER_RADIAN) +
                     NJM_DEG_ANG(270)) &
                    0xffff;
    if ((Uint16)(work->ang.y - motion->aim.y) > NJM_DEG_ANG(180)) {
        work->ang.y += HOME_TURN;
    } else {
        work->ang.y -= HOME_TURN;
    }
    work->ang.y &= 0xffff;
    motion->speed.x = motion->speed.y = motion->speed.z = 0.0F;
    fish_chase(task, generator);
    if (njScalor(&away) < 3.0F) {
        work->pos = generator->work->pos;
        motion->aim.y = generator->work->ang.y;
        return TRUE;
    }
    return FALSE;
}

/* shake the pad, harder for a larger size class */
void fish_vibrate(struct task *task)
{
    Float size = task->work->scl.y;

    if (size == 0.0F) {
        VibShot(0, 3, 10, 2);
    } else if (size == 1.0F) {
        VibShot(0, 5, 15, 4);
    } else {
        VibShot(0, 7, 15, 6);
    }
}

void fish_animate(struct task *task);
void fish_rest(struct task *task);
void fish_let_go(struct task *task);

/* the fish's step after its first. a fish in a mode before FISH_CHASE is
 * destroyed beyond FISH_NEAR of the lure. it is destroyed as well while
 * another fish is hooked. with no lure out, a fish past FISH_WANDER is
 * destroyed. so is a wandering one beyond FISH_NEAR of player 0. a landed fish
 * is destroyed once Big stops fishing */
void fish_step(struct task *task)
{
    struct task_work *work = task->work;
    struct fish_motion *motion = FISH_MOTION(task);
    struct task_work *player = playertwp[0];
    Angle off;

    if (big_lure) {
        player = big_lure->work;
        if (CalcDistance(&player->pos, &work->pos) > FISH_NEAR &&
            work->mode < FISH_CHASE) {
            /* @hack redundant: a never-run call of task_kill, which, as the
             * three after it, keeps big_lure's address in R8 and task_kill's in
             * R9 (0x0c90f282, 0x0c90f28e in STG01), which otherwise trade;
             * without it, 8 of 512 words differ */
            if (0) {
                FreeTask(task);
            }
            /* @hack redundant: a second never-run call of task_kill, which also
             * keeps big_lure's address in R8 and task_kill's in R9 (0x0c90f282,
             * 0x0c90f28e in STG01); without it, 8 of 512 words differ */
            if (0) {
                FreeTask(task);
            }
            goto destroy;
        }
        /* @hack spelling: the comparison's 0 or 1 ANDed with the flags, which
         * the image computes (MOVT and AND at 0x0c90f2c6 and 0x0c90f2ce).
         * FISHING_HOOKED is 0x1, so the &s act as &&; with &&, 17 of 512
         * words differ */
        if ((fishing_flags & (work->mode < FISH_CHASE) & FISHING_HOOKED) &&
            big_catch != task) {
            /* @hack redundant: a never-run call of task_kill for a hooked
             * fish, which also keeps big_lure's address in R8 and task_kill's
             * in R9. it spares the code before the first pool a jump around it
             * and 32 bytes of alignment (0x0c90f2e0 in STG01), and fish_vibrate
             * a word; without it, 454 of 512 words differ */
            if (0) {
                FreeTask(task);
            }
            goto destroy;
        }
    } else {
        if ((CalcDistance(&player->pos, &work->pos) > FISH_NEAR &&
             work->mode == FISH_WANDER) ||
            work->mode > FISH_WANDER) {
            /* @hack redundant: a never-run call of task_kill for a fish far off
             * or past wandering, which also keeps big_lure's address in R8 and
             * task_kill's in R9. it puts collision_init's 1 in R3 and its
             * address in R2 (0x0c90f366, 0x0c90f368 in STG01); without it, 16
             * of 512 words differ */
            if (0) {
                FreeTask(task);
            }
            goto destroy;
        }
    }
    switch (work->mode) {
    case FISH_INIT:
        /* @hack redundant: a jump to the next line, which puts collision_init's
         * count in R3 (MOV #1,R3 at 0x0c90f366); without it, 9 of 512 words
         * differ */
        goto init;
    init:
        CCL_Init(task, fish_shapes, COLLISION_OBJECT, 1, 1);
        work->mode = FISH_WANDER;
        fish_animate(task);
        fish_draw(task);
        break;
    case FISH_WANDER:
        fish_animate(task);
        fish_draw(task);
        if (big_lure && fish_claim_lure(task) && chkLureKaeru(task)) {
            work->mode = FISH_CHASE;
            motion->surface = fishing_get_water();
        }
        fish_wander(task);
        fish_swim(task);
        break;
    case FISH_CHASE:
        fish_animate(task);
        fish_draw(task);
        if (fish_try_bite(task)) {
            fishing_flags |= FISHING_HOOKED;
            work->mode = FISH_BITE;
            motion->aim.y =
                (Uint16)(big_lure->motion->aim.y + NJM_DEG_ANG(180));
            fish_vibrate(task);
            fish_set_action(task, ANIM_BITE);
            work->timer = 45;
            motion->speed.x = motion->speed.y = motion->speed.z = 0.0F;
        } else {
            FUN_8c0ec920(task);
            /* @hack spelling: two tests, the first jumping to release, which
             * read big_lure through the address in R8 (MOV.L @R8,R5 at
             * 0x0c90f436); as one test with ||, 31 of 512 words differ */
            if (!fish_claim_lure(task)) {
                goto release;
            }
            if (!fish_chase(task, big_lure)) {
            release:
                fish_let_go(task);
            }
        }
        break;
    case FISH_BITE:
        fish_animate(task);
        fish_draw(task);
        if (fishing_flags & FISHING_LANDED) {
            work->mode = FISH_LANDED;
            fish_land(task);
        } else {
            /* @hack redundant: a jump to the next line, which puts the flags in
             * R2 and the mask in R3 (0x0c90f4c0, 0x0c90f4c2); without it, the
             * two trade and 4 of 512 words differ */
            goto bite_test;
        bite_test:
            if ((fishing_flags & (FISHING_LOST | FISHING_SNAPPED)) ||
                !work->timer) {
                goto escape;
            } else {
                /* Big's pull starts the fight, as does the bite of a fish of
                 * size class 0. outside Ice Cap, a fish whose lure is within
                 * 100 of player 0 fights close, as FISH_CLOSE */
                if ((fishing_flags & FISHING_PULL) || work->scl.y == 0.0F) {
                    fishing_fight_steps = 0;
                    if (FUN_8c0eb4f0() > 100.0F || IN_STAGE(STAGE_ICECAP)) {
                        work->mode = FISH_FIGHT;
                    } else {
                        work->mode = FISH_CLOSE;
                        fishing_flags |= FISHING_KICK;
                    }
                    dsPlay_oneshot(1304, 0, 0, 0);
                    fish_vibrate(task);
                    fishing_start_fight();
                    fish_set_action(task, ANIM_HOOKED);
                }
                goto pull;
            }
        }
        break;
    case FISH_FIGHT:
        ++fishing_fight_steps;
        if (fishing_flags & FISHING_PULL) {
            ++fishing_fight_steps;
        }
        fish_animate(task);
        fish_draw(task);
        if (fishing_flags & FISHING_LANDED) {
            work->mode = FISH_LANDED;
            fish_land(task);
        } else {
            /* @hack redundant: a jump to the next line, which puts the flags in
             * R2 and the mask in R3 (0x0c90f5ae, 0x0c90f5b0); without it, the
             * two trade and 7 of 512 words differ */
            goto fight_test;
        fight_test:
            if (fishing_flags & (FISHING_LOST | FISHING_SNAPPED)) {
                goto escape;
            } else {
                fish_fight(task);
            pull:
                fish_pull(task);
            }
        }
        break;
    case FISH_FIGHT_BACK:
        ++fishing_fight_steps;
        if (fishing_flags & FISHING_PULL) {
            ++fishing_fight_steps;
        }
        fish_animate(task);
        fish_draw(task);
        if (fishing_flags & FISHING_LANDED) {
            work->mode = FISH_LANDED;
            fish_land(task);
        } else {
            /* @hack redundant: a jump to the next line, which puts the flags in
             * R2 and the mask in R3 (0x0c90f640, 0x0c90f642); without it, the
             * two trade and 7 of 512 words differ */
            goto back_test;
        back_test:
            if (fishing_flags & (FISHING_LOST | FISHING_SNAPPED)) {
                goto escape;
            } else {
                fish_fight_back(task);
            }
        }
        break;
    case FISH_CLOSE:
        ++fishing_fight_steps;
        if (fishing_flags & FISHING_PULL) {
            ++fishing_fight_steps;
        }
        fish_animate(task);
        fish_draw(task);
        if (fishing_flags & FISHING_LANDED) {
            work->mode = FISH_LANDED;
            fish_land(task);
        } else {
            /* @hack redundant: a jump to the next line, which puts the flags in
             * R2 and the mask in R3 (0x0c90f6a0, 0x0c90f6a2); without it, the
             * two trade and 10 of 512 words differ */
            goto close_test;
        close_test:
            if (fishing_flags & (FISHING_LOST | FISHING_SNAPPED)) {
            escape:
                fish_let_go(task);
            } else {
                fish_turn_to_aim(task);
                if (fish_fight_close(task)) {
                    work->mode = FISH_FIGHT;
                }
            }
        }
        break;
    case FISH_LANDED:
        fish_carry(task);
        fish_animate(task);
        fish_draw(task);
        if (ChkFishingThrowNow(task)) {
        destroy:
            FreeTask(task);
        }
        break;
    case FISH_RETURN:
        fish_animate(task);
        fish_draw(task);
        /* @hack spelling: an empty then-arm, which stores FISH_ARRIVE through
         * R2 (MOV #3,R2 at 0x0c90f720); as if (fish_return(task)), it takes R3
         * and 2 of 512 words differ */
        if (!fish_return(task)) {
        } else {
            work->mode = FISH_ARRIVE;
        }
        break;
    case FISH_ARRIVE:
        fish_animate(task);
        fish_draw(task);
        off = (Uint16)(work->ang.y - motion->aim.y);
        if (off > NJM_DEG_ANG(180)) {
            work->ang.y += HOME_TURN;
        } else {
            work->ang.y -= HOME_TURN;
        }
        work->ang.y &= 0xffff;
        motion->speed.x = motion->speed.y = motion->speed.z = 0.0F;
        if (off < ARRIVE_ABOVE || off > 0x10000 - ARRIVE_BELOW) {
            work->ang.y = motion->aim.y;
            fish_rest(task);
        }
        break;
    }
}

/* advance the fish's motion half a frame a step, and loop it at its end */
void fish_animate(struct task *task)
{
    struct task_work *work = task->work;

    if ((FISH_VARS(work)->frame += 0.5F) >=
        FISH_VARS(work)->action->motion->nbFrame) {
        FISH_VARS(work)->frame = 0.0F;
        /* @bug logic: action points at the fish's own copy in its extra,
         * never at fish_swim_actions' entry, so the test never holds (CMP/EQ
         * at 0x0c90f838 in STG01). the loop never sets the swim action again */
        if (FISH_VARS(work)->action ==
            fish_swim_actions[FISH_VARS(work)->kind]) {
            fish_set_action(task, ANIM_SWIM);
        }
    }
}

/* the fish is home: it wanders again, a little less drawn to the lure. if
 * it is big_catch, big_catch is cleared. a fish above the water's surface
 * is destroyed */
void fish_rest(struct task *task)
{
    struct task_work *work = task->work;

    work->mode = FISH_WANDER;
    if (big_catch == task) {
        big_catch = NULL;
        fishing_flags &= ~(FISHING_HOOKED | FISHING_LOST | FISHING_KICK);
    }
    if (FISH_MOTION(task)->interest > 1.0F) {
        FISH_MOTION(task)->interest -= 1.0F;
    }
    fish_set_action(task, ANIM_SWIM);
    if (work->pos.y > FISH_MOTION(task)->surface) {
        FreeTask(task);
    }
}

/* the fish gives up the lure: it swims home, a little less drawn to it. if
 * it is big_catch, big_catch is cleared */
void fish_let_go(struct task *task)
{
    struct task_work *work = task->work;

    work->mode = FISH_RETURN;
    if (big_catch == task) {
        big_catch = NULL;
        fishing_flags &= ~(FISHING_HOOKED | FISHING_LOST | FISHING_KICK);
    }
    if (FISH_MOTION(task)->interest > 1.0F) {
        FISH_MOTION(task)->interest -= 1.0F;
    }
    fish_set_action(task, ANIM_SWIM);
}

void fish_draw(struct task *task)
{
    struct task_work *work = task->work;
    Float scale;
    Angle ang;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 5.0F) != 0) {
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        scale = work->scl.x;
        njScale(((void *)0), scale, scale, scale);
        (((ang) = (work->ang.y + ((Angle)(((180) * 65536.0) / 360.0))))
             ? (njRotateY)(((void *)0), (ang))
             : (void)0);
        (((ang) = (work->ang.z)) ? (njRotateZ)(((void *)0), (ang)) : (void)0);
        (((ang) = (work->ang.x)) ? (njRotateX)(((void *)0), (ang)) : (void)0);
        njTranslateV(
            ((void *)0),
            &fish_model_offsets[((struct fish_vars *)&(work)->vars)->kind]);
        njSetTexture_jp(
            fish_texlists[((struct fish_vars *)&(work)->vars)->kind]);
        ds_ActionClip(((struct fish_vars *)&(work)->vars)->action,
                      ((struct fish_vars *)&(work)->vars)->frame);
        if (((struct fish_vars *)&(work)->vars)->kind == 8) {
            njSetTexture_jp(&fish_an_ke_texlist);
            if (work->tick == ANIM_SWIM) {
                ds_ActionClip(&fish_an_ke_swim_action,
                              ((struct fish_vars *)&(work)->vars)->frame);
            } else if (work->tick == ANIM_BITE) {
                ds_ActionClip(&fish_an_ke_bite_action,
                              ((struct fish_vars *)&(work)->vars)->frame);
            } else {
                ds_ActionClip(&fish_an_ke_hooked_action,
                              ((struct fish_vars *)&(work)->vars)->frame);
            }
        }
        late_DrawObjectClipEx(1);
    }
}

/* the fish's destructor. a fish with an extra clears its generator's fish,
 * so the generator can make another. it also drops fishing_fish_count by
 * one */
void fish_destroy(struct task *task)
{
    struct fish_extra *extra;

    if (task->extra != NULL) {
        extra = task->extra;
        if (extra->generator != NULL) {
            struct task *generator = extra->generator;

            GENERATOR_VARS(generator->work)->fish = NULL;
        }
        --fishing_fish_count;
    }
}

void fish_generator_destroy(struct task *task)
{
}

/* create a fish at the generator, facing as it does. the generator's scales
 * give its kind and size. NULL where the task pool or the heap runs out */
struct task *fish_spawn(struct task *generator)
{
    struct task *fish;
    struct fish_extra *extra;

    fish = CreateElementalTask(TASK_MOTION | TASK_WORK, 3, fish_init);
    if (fish != NULL) {
        fish->work->pos = generator->work->pos;
        fish->work->ang = generator->work->ang;
        extra = CAlloc(1, sizeof(struct fish_extra));
        if (generator->work->scl.x) {
            fish_choose_kind(fish, (int)generator->work->scl.x);
        }
        fish->work->scl.z = generator->work->scl.z;
        if (extra == NULL) {
            FreeTask(fish);
            return NULL;
        }
        fish->extra = extra;
        extra->generator = generator;
    }
    return fish;
}

/* a generator makes its fish with a chance of 0.3 a step. it makes none
 * while five fish swim, while a fish is hooked, or beyond FISH_NEAR of
 * player 0. once Big lands its fish, it rests REST_STEPS before it makes
 * another */
void fish_generator_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];

    switch (work->mode) {
    case GENERATOR_INIT:
        task->destructor = fish_generator_destroy;
        work->mode = GENERATOR_WAIT;
        GENERATOR_VARS(work)->fish = NULL;
        break;
    case GENERATOR_WAIT:
        /* @hack type: the count compared unsigned, CMP/HS at 0x0c90fba6. the
         * compare is the int's while the count isn't negative, as it stays
         * while a generator adds one for each fish it makes and the fish's
         * destructor takes that one off. as the int it is, 1 of 133 words
         * differ */
        if ((unsigned int)fishing_fish_count >= 5) {
            break;
        }
        if (CalcDistance(&player->pos, &work->pos) > FISH_NEAR) {
            break;
        }
        if (fishing_flags & FISHING_HOOKED) {
            break;
        }
        if (rand() * RAND_SCALE > 0.3F) {
            break;
        }
        if (IN_STAGE(STAGE_SHELTER) && work->scl.y && !fishing_shelter_ready) {
            break;
        }
        GENERATOR_VARS(work)->fish = fish_spawn(task);
        if (GENERATOR_VARS(work)->fish == NULL) {
            break;
        }
        work->mode = GENERATOR_SWIMMING;
        ++fishing_fish_count;
        break;
    case GENERATOR_SWIMMING:
        if (GENERATOR_VARS(work)->fish == NULL) {
            work->mode = GENERATOR_WAIT;
            return;
        }
        if (GENERATOR_VARS(work)->fish == big_catch &&
            (fishing_flags & (FISHING_HOOKED | FISHING_LANDED)) ==
                (FISHING_HOOKED | FISHING_LANDED)) {
            work->mode = GENERATOR_REST;
            GENERATOR_VARS(work)->rest_steps = REST_STEPS;
        }
        break;
    case GENERATOR_REST:
        if (--GENERATOR_VARS(work)->rest_steps > 0) {
            return;
        }
        work->mode = GENERATOR_WAIT;
        return;
    }
}
