/* @unit 8C015820-8C017B20 +r04 +egflags +pool32 */
/* the small animals, in a stage and in the Chao gardens. a frame runs
 * frame_step_count steps of the task. in a stage an animal moves only on a
 * frame's first step, so its moves' speeds, pulls and turns are per frame.
 * its age, its motion's frame and its barrier's wobble advance every
 * step */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "animal/animal.h"
#include "animal/barrier.h"
#include "animal/sparks.h"
#include "animal/textures.h"
#include "chao/chao.h"
#include "collision/collision.h"
#include "collision/ground.h"
#include "collision/polygon.h"
#include "collision/world.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "effect/dust.h"
#include "object/common.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "system/frame.h"
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
void *syMalloc_default_malloc(size_t size);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void ExtraDisplayInit(void);
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
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
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void kmiLogFileOpen(void *data);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
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
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* an animal's ages, in steps */
#define APPEAR_AGE 15 /* SE_APPEAR plays */
#define HIT_AGE 30 /* once older, the animal takes hits */
#define BARRIER_AGE 180 /* its barrier breaks, unless ANIMAL_KEEP_BARRIER */
#define WANDER_AGE 600 /* once older, a follower that doesn't flee wanders */
#define AGE_MAX 0x3fff /* where the count stops */

/* an animal's flags in a stage, in work->timer. in a garden that word is
 * COUNT instead */
#define ANIMAL_LEAP 0x4 /* it strode or leapt the last time it stood */
#define ANIMAL_GROUND 0x8 /* it stands on a floor */
#define ANIMAL_FLOOR 0x10 /* a floor lies under it: a flag nothing reads */
#define ANIMAL_REVERSE 0x20 /* it circles the other way */
#define ANIMAL_BARRIER 0x40 /* it's in its barrier */
#define ANIMAL_BREAKING 0x80 /* its barrier breaks this step */
#define ANIMAL_FLEES 0x100 /* it runs from E-102 */
#define ANIMAL_STOP 0x200 /* it doesn't move across this frame */
#define ANIMAL_AIMED 0x400 /* it has chosen where to wander */
#define ANIMAL_BLOCKED 0x800 /* it has stepped back from an edge */
#define ANIMAL_STAY 0x1000 /* in its barrier, it circles where it was made */
#define ANIMAL_OWN_SPEC 0x2000 /* its spec is its own, on the heap */
#define ANIMAL_KEEP_BARRIER 0x4000 /* its barrier outlasts BARRIER_AGE */
#define ANIMAL_GONE 0x8000 /* animal_step destroys it */

/* what work->mode makes an animal do in a stage */
#define PRESS_X 0x1
#define PRESS_Y 0x2
#define PRESS_Z 0x4
#define VARS(work) ((struct animal_vars *)&(work)->vars)
#define FLAGS(work) TASK_TIMER(work)
#define COUNT(work) FLAGS(work)
#define SE_APPEAR 24
#define SE_FREED 28
#define GRAVITY (-0.28095F)
#define STEEP NJM_DEG_ANG(25)
#define TOO_STEEP NJM_DEG_ANG(50)
#define NO_FLOOR (-10000.0F)
#define STAND_HEIGHT 2.0F
#define WANDER_RADIUS 10.0F
#define CIRCLE_RADIUS 18.0F
#define FLY_RADIUS 22.0F
#define RADIUS_SWING 5.0F
#define FLEE_AHEAD 8.0F
#define FLEE_NEAR 5.0F
#define FLY_HEIGHT 8.0F
#define FLY_BOB 4.0F
#define FLEE_RISE 0.08F
#define PULL 0.01F
#define SWALLOW_PULL 0.05F
#define COLLIDE_RANGE 10.0F
#define BARRIER_REACH 8.0F
#define BODY_REACH 2.0F
#define EDGE_DROP 15.0F
#define REVERSE_BUMPS 5.0F
#define BARRIER_LEAST 0.5F
#define BARRIER_MOST 1.5F
#define STRIDE_SPEED 0.9F
#define STRIDE_SQUARED 0.81F
#define HELD_TURN NJM_DEG_ANG(11.25)
#define HELD_STEPS 30
#define THROWN_STEPS 200
enum animal_mode {
    MODE_FOLLOW, /* circle player 0 */
    MODE_WANDER, /* circle a place it picks as it starts to wander */
    MODE_FLEE, /* run straight away from player 0 */
    MODE_FLEE_90, /* run away from player 0, turned 90 degrees */
    MODE_FLEE_270 /* run away from player 0, turned 270 degrees */
};

/* what work->mode makes an animal do in a garden */
enum garden_mode { GARDEN_LOOSE, GARDEN_THROWN, GARDEN_HELD };

/* the axes something presses the barrier along, for squash_barrier */

/* the motion frames after from, up to and including to */
struct frames {
    Float from;
    Float to;
};

/* how each kind of animal looks and moves */
struct animal_spec {
    Uint16 color; /* the color of its sparks and its flash, 0 to 7 */
    /* degrees each move turns the animal round its target, out of its
     * barrier. its seed adds 0 to 5 more */
    Uint16 turn;
    Angle ang; /* added to work->ang.y as it's drawn */
    Float scale;
    Float speed; /* motion frames a step */
    NJS_TEXLIST *texlist;
};

/* an animal's own record, beside its task */
struct animal {
    Uint8 kind;
    Uint8 seed; /* random bits: which way this one circles, and how fast */
    Uint8 bumps; /* walls and edges met since it last reversed its circling */
    Uint8 unk_03;
    Float frame; /* how far into its motion */
    NJS_VECTOR speed;
    NJS_VECTOR accel; /* the frame's pushes and pulls, added to speed */
    NJS_VECTOR barrier_scale;
    NJS_VECTOR barrier_speed; /* how fast barrier_scale changes on each axis */
    Angle orbit; /* its angle round the target */
    Float radius; /* how far from the target it circles */
    /* the slope of the floor under it, which nothing reads */
    Angle floor_ang_x;
    Angle floor_ang_z;
    NJS_POINT3 target; /* the point it circles */
    NJS_POINT3 last_pos; /* where it was the frame before */
    /* its kind's move: animal_walk, animal_chase, animal_gallop, animal_hop
     * or animal_fly */
    void (*move)(struct animal *animal, struct task_work *work);
    /* the destructor animal_create_custom was given, or null */
    void (*destructor)(struct task *task);
    const struct animal_spec *spec; /* its kind's, or its own */
};

/* an animal's bytes in work->vars */
struct animal_vars {
    NJS_ACTION *action; /* the body's model and motion, or null for none */
    Sint16 age; /* steps since it started, up to AGE_MAX */
    Uint8 unk_06[2];
    struct animal *animal;
};

/* in a garden, the flags word counts the steps the animal has been held or
 * thrown instead. animal_draw still reads its ANIMAL_BARRIER bit, 0x40, so
 * the barrier shows at counts 64 to 127, 192 to 255 and so on.
 * animal_destroy still reads its ANIMAL_OWN_SPEC bit, 0x2000. at a count
 * with that bit set, it passes heap_free the kind's row of the static
 * animal_specs */

/* the y speed gravity adds each frame to an animal out of its barrier that
 * walks, chases, gallops or hops */

/* a surface that leans more than STEEP from level is a wall. a floor that
 * leans more than TOO_STEEP is too steep to walk onto */
/* lower than any floor: none was found */

/* an animal's position lies STAND_HEIGHT above the floor it stands on */

/* the radius at which a walking animal circles the place it wanders round */
/* out of its barrier, an animal that chases, gallops or hops circles its
 * target at CIRCLE_RADIUS, and a flier at FLY_RADIUS. in its barrier every
 * animal flies at FLY_RADIUS. each radius swings RADIUS_SWING in and out,
 * once in four turns round the target */
/* a fleeing animal aims FLEE_AHEAD from itself. within FLEE_NEAR of player
 * 0, it aims by the world's axes instead */
/* how high above its target a flying animal circles, and how far it bobs
 * up and down */
/* animal_fly raises the target of an animal that flees E-102 by FLEE_RISE
 * each move, out of its barrier. no move reads the rise: for such an
 * animal, animal_aim sets the whole target before each move's animal_fly
 * reads it */
/* each frame, a chasing or flying animal adds PULL of the way to its point
 * to its speed. SWALLOW_PULL is the swallow's, out of its barrier */
/* the radius in which world_list_near finds the objects an animal collides
 * with */
/* animal_collide meets walls with a box round the animal. its half-width
 * across x and z is BARRIER_REACH times the barrier's scale in its barrier,
 * and BODY_REACH out of it */
/* the drop below its last position past which an animal is at an edge */
/* an animal reverses its circling once its bumps pass a random number below
 * REVERSE_BUMPS */
/* wobble_barrier holds each axis of the barrier's scale within
 * BARRIER_LEAST and BARRIER_MOST. animal_collide's squash comes later in a
 * step, so the scale drawn can pass them */
/* a stride or a leap cuts the animal's whole speed to STRIDE_SPEED once its
 * speed across reaches it. the test compares the square of its speed across
 * with STRIDE_SQUARED, which is 0.81F, one float above 0.9F * 0.9F */
/* a held animal turns by up to HELD_TURN a step for HELD_STEPS steps */
/* once its count passes THROWN_STEPS, a thrown animal runs loose again */

void animal_start(struct task *task, enum animal_kind kind);
void Flicky_executor(struct task *task);
void animal_garden_step(struct task *task);
void FUN_8c015ad0(struct task *task);
void animal_destroy(struct task *task);
Bool animal_init(struct animal *animal, struct task_work *work,
                 enum animal_kind kind);
void animal_update(struct animal *animal, struct task_work *work,
                   struct task *task);
void animal_choose_mode(struct animal *animal, struct task_work *work);
void Flicky_checkGet(struct animal *animal, struct task_work *work,
                     struct task *task);
void animal_barrier_step(struct animal *animal, struct task_work *work);
void animal_move(struct animal *animal, struct task_work *work);
void animal_aim(struct animal *animal, struct task_work *work);
void animal_walk(struct animal *animal, struct task_work *work);
Bool Flicky_moveCmnOnTheFloor(struct animal *animal, struct task_work *work,
                              NJS_POINT3 *point);
void Flicky_moveHop(struct animal *animal, struct task_work *work);
void Flicky_moveStep(struct animal *animal, struct task_work *work);
void Flicky_moveJump(struct animal *animal, struct task_work *work);
void animal_fly(struct animal *animal, struct task_work *work);
void Flicky_checkColli(struct animal *animal, struct task_work *work);
void animal_garden_update(struct animal *animal, struct task_work *work,
                          struct task *task);
void animal_garden_loose(struct animal *animal, struct task_work *work,
                         struct task *task);
static void animal_garden_thrown(struct animal *animal, struct task_work *work,
                                 struct task *task);
void animal_garden_held(struct animal *animal, struct task_work *work);
void Flicky_dsp(struct animal *animal, struct task_work *work);
void animal_draw_body(struct animal *animal, struct task_work *work, Angle ang);
void animal_draw_barrier(struct animal *animal, struct task_work *work,
                         Angle ang);
void animal_kick_dust(struct animal *animal, struct task_work *work);
void Flicky_transformBaloon(struct animal *animal, struct task_work *work);
void squash_barrier(NJS_VECTOR *scale, int axes);
static void animal_start_custom(struct task *task);
extern const struct collision_shape animal_shapes[2];
extern const struct collision_shape garden_shapes[2];
extern const struct animal_spec animal_specs[ANIMAL_KINDS];

struct task_work *animal_create(Float x, Float y, Float z,
                                void (*start)(struct task *task))
{
    struct task *task;
    struct task_work *work;
    struct animal *animal;

    if (start == NULL) {
        return NULL;
    }
    task = CreateElementalTask(TASK_MOTION | TASK_WORK, 4, start);
    animal = CAlloc(1, sizeof(struct animal));
    /* @bug memory: a task that can't be allocated leaks the animal's record.
     * BT/S at 0x8c0162f4 returns null with it unfreed */
    if (task == NULL) {
        return NULL;
    }
    if (animal != NULL) {
        work = task->work;
        work->pos.x = x;
        work->pos.y = y;
        work->pos.z = z;
        work->ang.y = RANDOM_ANGLE();
        player_look_at_task(0, task, 300);
        VARS(work)->animal = animal;
        animal->destructor = NULL;
        return work;
    } else {
        DestroyTask(task);
        return NULL;
    }
}

struct task_work *animal_create_staying(Float x, Float y, Float z,
                                        void (*start)(struct task *task))
{
    struct task_work *work;

    work = animal_create(x, y, z, start);
    if (work != NULL) {
        FLAGS(work) |= ANIMAL_STAY | ANIMAL_KEEP_BARRIER;
    }
    return work;
}

void animal_start_goma(struct task *task)
{
    animal_start(task, ANIMAL_GOMA);
}

void animal_start_pen(struct task *task)
{
    animal_start(task, ANIMAL_PEN);
}

void animal_start_tuba(struct task *task)
{
    animal_start(task, ANIMAL_TUBA);
}

void animal_start_kuja(struct task *task)
{
    animal_start(task, ANIMAL_KUJA);
}

void animal_start_oum(struct task *task)
{
    animal_start(task, ANIMAL_OUM);
}

void animal_start_koar(struct task *task)
{
    animal_start(task, ANIMAL_KOAR);
}

void animal_start_wara(struct task *task)
{
    animal_start(task, ANIMAL_WARA);
}

void animal_start_banb(struct task *task)
{
    animal_start(task, ANIMAL_BANB);
}

void animal_start_usa(struct task *task)
{
    animal_start(task, ANIMAL_USA);
}

void animal_start_mogu(struct task *task)
{
    animal_start(task, ANIMAL_MOGU);
}

void animal_start_zou(struct task *task)
{
    animal_start(task, ANIMAL_ZOU);
}

void animal_start_lion(struct task *task)
{
    animal_start(task, ANIMAL_LION);
}

void animal_start_gori(struct task *task)
{
    animal_start(task, ANIMAL_GORI);
}

void animal_start_suka(struct task *task)
{
    animal_start(task, ANIMAL_SUKA);
}

void animal_start_rako(struct task *task)
{
    animal_start(task, ANIMAL_RAKO);
}

void animal_start(struct task *task, enum animal_kind kind)
{
    struct task_work *work;
    struct animal *animal;
    Uint16 stage;

    work = task->work;
    animal = VARS(work)->animal;
    if (playertwp[0] == NULL || !animal_init(animal, work, kind)) {
        DestroyTask(task);
        return;
    }
    stage = (Uint8)(GetStageNumber() >> 8);
    if (stage == STAGE_ALIFE_SS || stage == STAGE_ALIFE_EG ||
        stage == STAGE_ALIFE_MR) {
        if (animal->kind >= ANIMAL_KINDS) {
            DestroyTask(task);
            return;
        }
        CCL_Init(task, garden_shapes, COLLISION_ENEMY, 1, 2);
        task->step = animal_garden_step;
        carry_set_kind(work, task->motion, CARRY_KIND_SMALL);
        /* @hack spelling: x = x & ~ANIMAL_BARRIER, which loads
         * collision_init's 2 into R3 (0x8c016482); as &=, R1, and 12 of 105
         * words differ */
        FLAGS(work) = FLAGS(work) & ~ANIMAL_BARRIER;
    } else {
        CCL_Init(task, animal_shapes, COLLISION_PICKUP, 1, 2);
        task->step = Flicky_executor;
    }
    /* MODE_FOLLOW in a stage, and GARDEN_LOOSE in a garden */
    work->mode = 0;
    task->draw = FUN_8c015ad0;
    task->destructor = animal_destroy;
    work->collision->flags &= ~COLLISION_TARGET;
}

/* once placement_try_leave finds the animal out of range, it has made
 * task_destroy the task's next step, and the animal returns undrawn. the
 * test below reads the flags word as a number. above 1500, the animal is
 * destroyed in this step instead. ANIMAL_BLOCKED, 0x800, or any higher
 * flag passes 1500 alone */
void Flicky_executor(struct task *task)
{
    struct task_work *work;
    struct animal *animal;

    work = task->work;
    animal = VARS(work)->animal;
    if (CheckRangeOut(task)) {
        if (FLAGS(work) > 1500) {
            FLAGS(work) |= ANIMAL_GONE;
        } else {
            return;
        }
    }
    if (FLAGS(work) & ANIMAL_GONE) {
        DestroyTask(task);
        return;
    }
    animal_update(animal, work, task);
    Flicky_dsp(animal, work);
}

void animal_garden_step(struct task *task)
{
    struct task_work *work;
    struct animal *animal;

    work = task->work;
    animal = VARS(work)->animal;
    animal_garden_update(animal, work, task);
    Flicky_dsp(animal, work);
}
void FUN_8c015ad0(struct task *task)
{
    struct task_work *work;
    struct animal *animal;
    work = task->work;
    animal = ((struct animal_vars *)&(work)->vars)->animal;
    Flicky_dsp(animal, work);
}

void animal_destroy(struct task *task)
{
    struct task_work *work;
    struct animal *animal;

    work = task->work;
    animal = VARS(work)->animal;
    if (animal != NULL) {
        if (FLAGS(work) & ANIMAL_OWN_SPEC) {
            Free((void *)animal->spec);
        }
        if (animal->destructor != NULL) {
            animal->destructor(task);
        }
        Free(animal);
    }
    FreeTask(task);
}

Bool animal_init(struct animal *animal, struct task_work *work,
                 enum animal_kind kind)
{
    animal->kind = kind;
    if (!(FLAGS(work) & ANIMAL_OWN_SPEC)) {
        animal->spec = &animal_specs[kind];
    }
    switch (kind) {
    case ANIMAL_GOMA:
        VARS(work)->action = &goma_action;
        animal->move = animal_walk;
        break;
    case ANIMAL_PEN:
        VARS(work)->action = &pen_action;
        animal->move = Flicky_moveHop;
        break;
    case ANIMAL_TUBA:
        VARS(work)->action = &tuba_action;
        animal->move = animal_fly;
        break;
    case ANIMAL_KUJA:
        VARS(work)->action = &kuja_action;
        animal->move = animal_fly;
        break;
    case ANIMAL_OUM:
        VARS(work)->action = &oum_action;
        animal->move = animal_fly;
        break;
    case ANIMAL_KOAR:
        VARS(work)->action = &koar_action;
        animal->move = animal_walk;
        break;
    case ANIMAL_WARA:
        VARS(work)->action = &wara_action;
        animal->move = Flicky_moveJump;
        break;
    case ANIMAL_BANB:
        VARS(work)->action = &banb_action;
        animal->move = Flicky_moveStep;
        break;
    case ANIMAL_USA:
        VARS(work)->action = &usa_action;
        animal->move = Flicky_moveJump;
        break;
    case ANIMAL_MOGU:
        VARS(work)->action = &mogu_action;
        animal->move = animal_walk;
        break;
    case ANIMAL_ZOU:
        VARS(work)->action = &zou_action;
        animal->move = animal_walk;
        break;
    case ANIMAL_LION:
        VARS(work)->action = &lion_action;
        animal->move = Flicky_moveStep;
        break;
    case ANIMAL_GORI:
        VARS(work)->action = &gori_action;
        animal->move = animal_walk;
        break;
    case ANIMAL_SUKA:
        VARS(work)->action = &suka_action;
        animal->move = Flicky_moveHop;
        break;
    case ANIMAL_RAKO:
        VARS(work)->action = &rako_action;
        animal->move = animal_walk;
        break;
    case ANIMAL_CUSTOM:
    default:
        animal->move = animal_fly;
        break;
    }
    animal->bumps = 0;
    if (VARS(work)->action != NULL) {
        animal->frame =
            rand() * (Float)VARS(work)->action->motion->nbFrame * RAND_SCALE;
    }
    animal->seed = RANDOM(0.0F, 255.0F);
    animal->radius = WANDER_RADIUS;
    animal->orbit = RANDOM_ANGLE();
    VECTOR_COPY(&animal->last_pos, &work->pos);
    VARS(work)->age = 0;
    animal->barrier_scale.x = 0.85F;
    animal->barrier_scale.y = 1.3F;
    animal->barrier_scale.z = 0.85F;
    FLAGS(work) |= ANIMAL_BARRIER;
    if (FLAGS(work) & ANIMAL_STAY) {
        VECTOR_COPY(&animal->target, &work->pos);
    }
    if (GetPlayerCharacterName(0) == CHARACTER_E102) {
        FLAGS(work) |= ANIMAL_FLEES;
    }
    VECTOR_CLEAR(&animal->accel);
    VECTOR_CLEAR(&animal->speed);
    return TRUE;
}

/* age and animate the animal every step, and move it on a frame's first
 * step alone */
void animal_update(struct animal *animal, struct task_work *work,
                   struct task *task)
{
    VARS(work)->age++;
    if (VARS(work)->age > AGE_MAX) {
        VARS(work)->age = AGE_MAX;
    } else if (VARS(work)->age == APPEAR_AGE) {
        dsPlay_oneshot_v(SE_APPEAR, 0, 0, 0, work->pos.x, work->pos.y,
                         work->pos.z);
    }
    if (VARS(work)->action != NULL) {
        animal->frame += animal->spec->speed;
        if (animal->frame > VARS(work)->action->motion->nbFrame) {
            animal->frame -= VARS(work)->action->motion->nbFrame;
        }
    }
    animal_choose_mode(animal, work);
    Flicky_checkGet(animal, work, task);
    animal_barrier_step(animal, work);
    if (loop_count == 0) {
        animal_move(animal, work);
    }
    EntryColliList(work);
}

void animal_choose_mode(struct animal *animal, struct task_work *work)
{
    switch (work->mode) {
    case MODE_FOLLOW:
        if (FLAGS(work) & ANIMAL_FLEES) {
            if (!(FLAGS(work) & ANIMAL_BARRIER)) {
                work->mode = MODE_FLEE;
            }
        } else if (VARS(work)->age > WANDER_AGE) {
            work->mode = MODE_WANDER;
        }
        break;
    case MODE_WANDER:
        break;
    }
}

/* the animal ignores hits until it is older than HIT_AGE. then a player's
 * hit frees it: it sparks, and animal_step destroys it. animal_icon_add
 * puts its kind, unless ANIMAL_CUSTOM, in the row of animals the player
 * carries. a hit by anything else squashes its barrier */
void Flicky_checkGet(struct animal *animal, struct task_work *work,
                     struct task *task)
{
    if (VARS(work)->age > HIT_AGE) {
        if (!(work->collision->flags & COLLISION_HIT)) {
            return;
        }
        if (work->collision->hit->kind == COLLISION_PLAYER) {
            dsPlay_oneshot(SE_FREED, 0, 0, 0);
            if (FLAGS(work) & ANIMAL_BARRIER) {
                FlickyEff_Wa_New(&work->pos, animal->spec->color);
            }
            FlickyEff_Particle_New(&work->pos, animal->spec->color,
                                   FLAGS(work) & ANIMAL_GROUND);
            if (animal->kind < ANIMAL_KINDS) {
                AddExtraDisplay(animal->kind);
            }
            FLAGS(work) |= ANIMAL_GONE;
        } else {
            if (work->collision->flags & COLLISION_HIT_SIDE) {
                squash_barrier(&animal->barrier_scale, PRESS_X);
            } else {
                squash_barrier(&animal->barrier_scale, PRESS_Y | PRESS_Z);
            }
        }
    }
}

void animal_barrier_step(struct animal *animal, struct task_work *work)
{
    if (!(FLAGS(work) & ANIMAL_KEEP_BARRIER)) {
        if (VARS(work)->age == BARRIER_AGE) {
            FLAGS(work) &= ~ANIMAL_BARRIER;
            FLAGS(work) |= ANIMAL_BREAKING;
            FlickyEff_Wa_New(&work->pos, animal->spec->color);
        }
        if (VARS(work)->age == BARRIER_AGE + 1) {
            FLAGS(work) &= ~ANIMAL_BREAKING;
        }
    }
    if (FLAGS(work) & ANIMAL_BARRIER) {
        Flicky_transformBaloon(animal, work);
    }
}

void animal_move(struct animal *animal, struct task_work *work)
{
    NJS_VECTOR drag;
    Float squared;

    animal_aim(animal, work);
    squared = ACROSS_SQUARED(&animal->speed);
    if (squared > 0.02F * 0.02F) {
        int heading;
        int turn;

        heading =
            njArcTan2(animal->speed.x, animal->speed.z) * ANGLE_PER_RADIAN;
        /* turn a quarter of the way to the heading, the shorter way round */
        /* @hack spelling: the difference taken inside the test, which copies
         * the heading in R5 to R4 to subtract (0x8c016c20, 0x8c016c22); as a
         * statement of its own, the function runs 2 bytes short and 17 of
         * 177 words differ */
        work->ang.y +=
            ((turn = heading - work->ang.y) & 0x8000 ? turn | ~0xffff
                                                     : turn & 0xffff) >>
            2;
    }
    animal->move(animal, work);
    Flicky_checkColli(animal, work);
    if (FLAGS(work) & ANIMAL_STOP) {
        animal->accel.x = 0.0F;
        animal->accel.z = 0.0F;
        animal->speed.x = 0.0F;
        animal->speed.z = 0.0F;
    }
    FLAGS(work) &= ~ANIMAL_STOP;
    VECTOR_COPY(&animal->last_pos, &work->pos);
    VECTOR_ADD(&work->pos, &animal->speed);
    VECTOR_ADD(&animal->speed, &animal->accel);
    VECTOR_SCALE(&drag, &animal->speed, 0.33587F);
    VECTOR_SUB(&animal->speed, &drag);
    VECTOR_CLEAR(&animal->accel);
}

void animal_aim(struct animal *animal, struct task_work *work)
{
    NJS_VECTOR away;
    NJS_MATRIX matrix;
    int turn;
    Float flat;

    if ((FLAGS(work) & ANIMAL_STAY) && (FLAGS(work) & ANIMAL_BARRIER)) {
        return;
    }
    switch (work->mode) {
    case MODE_FOLLOW:
        animal->target.x = playertwp[0]->pos.x;
        animal->target.y = playertwp[0]->pos.y;
        animal->target.z = playertwp[0]->pos.z;
        break;
    case MODE_WANDER:
        if (!(FLAGS(work) & ANIMAL_AIMED)) {
            if (animal->move == animal_walk) {
                VECTOR_COPY(&animal->target, &work->pos);
            } else {
                animal->target.x = playertwp[0]->pos.x;
                animal->target.y = playertwp[0]->pos.y;
                animal->target.z = playertwp[0]->pos.z;
            }
            animal->radius = WANDER_RADIUS;
            FLAGS(work) |= ANIMAL_AIMED;
        }
        if (FLAGS(work) & ANIMAL_BLOCKED) {
            if (animal->speed.x > 0.0F) {
                animal->target.x += RANDOM(-4.0F, -1.0F);
            } else {
                animal->target.x += RANDOM(1.0F, 4.0F);
            }
            if (animal->speed.z > 0.0F) {
                animal->target.z += RANDOM(-4.0F, -1.0F);
            } else {
                animal->target.z += RANDOM(1.0F, 4.0F);
            }
            FLAGS(work) &= ~ANIMAL_BLOCKED;
        }
        break;
    case MODE_FLEE:
    case MODE_FLEE_90:
    case MODE_FLEE_270:
        switch (work->mode) {
        case MODE_FLEE:
            turn = 0;
            break;
        case MODE_FLEE_90:
            turn = NJM_DEG_ANG(90);
            break;
        case MODE_FLEE_270:
        default:
            turn = NJM_DEG_ANG(270);
            break;
        }
        if (FLAGS(work) & ANIMAL_BLOCKED) {
            work->mode = RANDOM(0.0F, 3.0F);
            work->mode += MODE_FLEE;
            FLAGS(work) &= ~ANIMAL_BLOCKED;
        }
        /* aim FLEE_AHEAD from the animal, along the way from player 0 to
         * it, turned by turn. within FLEE_NEAR of player 0, aim along the
         * world's x axis turned by turn instead */
        VECTOR_DIFF(&away, &work->pos, &playertwp[0]->pos);
        if (VECTOR_SQUARED(&away) > FLEE_NEAR * FLEE_NEAR) {
            njUnitVector(&away);
            njUnitMatrix(&matrix);
            TURN_MATRIX(njRotateY, &matrix, turn);
            njCalcVector(&matrix, &away, &away);
            VECTOR_SCALE(&away, &away, FLEE_AHEAD);
        } else {
            /* @hack spelling: away's members written through &away, which
             * stores each through its address in R8 (0x8c017082,
             * 0x8c01708e); as away.x, away.y and away.z, SHC stores at
             * @(R0,R15), animal.c's code runs 32 bytes short and 85 of 375
             * words differ */
            (&away)->y = njSin(0) * FLEE_AHEAD;
            flat = njCos(0) * FLEE_AHEAD;
            (&away)->x = flat * njCos(turn);
            (&away)->z = -(flat * njSin(turn));
        }
        VECTOR_SUM(&animal->target, &away, &work->pos);
        break;
    }
}

/* walk toward the animal's place on its circle round the target, weaving
 * from side to side. in its barrier the animal flies instead, as animal_fly
 * moves it */
void animal_walk(struct animal *animal, struct task_work *work)
{
    NJS_VECTOR to;
    int ang;

    if (FLAGS(work) & ANIMAL_BARRIER) {
        animal_fly(animal, work);
        return;
    }
    /* @bug logic: ANIMAL_BREAKING lasts the one step the barrier breaks
     * in, and an animal moves only on a frame's first step (TST R3,R3 on
     * frame_step at 0x8c0169aa). so this test (TST #0x80,R0 at 0x8c017180)
     * misses a break on a frame's second step, and the walker keeps the
     * radius animal_fly gave it, FLY_RADIUS give or take RADIUS_SWING, in
     * place of 0 */
    if (FLAGS(work) & ANIMAL_BREAKING) {
        animal->radius = 0.0F;
    }
    VECTOR_DIFF(&to, &animal->target, &work->pos);
    to.x += animal->radius * njCos(animal->orbit);
    to.z += animal->radius * njSin(animal->orbit);
    animal->orbit +=
        (int)(((animal->seed & 5) + animal->spec->turn) * ANGLE_PER_DEGREE);
    if (VECTOR_SQUARED(&to) > 25.0F) {
        ang = (int)(njArcTan2(to.z, to.x) * ANGLE_PER_RADIAN) +
              (njSin(animal->orbit) * 8192.0F);
        animal->speed.x = njCos(ang) * 0.25F;
        animal->speed.z = njSin(ang) * 0.25F;
    }
    animal->accel.y += GRAVITY;
}

/* in its barrier, fly as animal_fly does and return TRUE. out of it, turn
 * the animal round its target and set its radius. then set point to its
 * place on the circle, and return FALSE */
Bool Flicky_moveCmnOnTheFloor(struct animal *animal, struct task_work *work,
                              NJS_POINT3 *point)
{
    int turn;
    int step;

    if (FLAGS(work) & ANIMAL_BARRIER) {
        animal_fly(animal, work);
        return TRUE;
    }
    turn = (animal->seed & 3) + animal->spec->turn;
    step = turn * ANGLE_PER_DEGREE;
    if (animal->seed & 4) {
        step = -step;
    }
    if (FLAGS(work) & ANIMAL_REVERSE) {
        step = -step;
    }
    animal->orbit += step;
    VECTOR_COPY(point, &animal->target);
    animal->radius = CIRCLE_RADIUS + (njCos(animal->orbit >> 2) * RADIUS_SWING);
    point->x += animal->radius * njCos(animal->orbit);
    point->z += animal->radius * njSin(animal->orbit);
    return FALSE;
}

void Flicky_moveHop(struct animal *animal, struct task_work *work)
{
    NJS_POINT3 point;

    if (!Flicky_moveCmnOnTheFloor(animal, work, &point)) {
        Float dx;
        Float dz;

        dx = point.x - work->pos.x;
        dx *= PULL;
        animal->accel.x += dx;
        dz = point.z - work->pos.z;
        dz *= PULL;
        animal->accel.z += dz;
        animal->accel.y += GRAVITY;
    }
}

void Flicky_moveStep(struct animal *animal, struct task_work *work)
{
    struct frames pause;

    Flicky_moveHop(animal, work);
    switch (animal->kind) {
    case ANIMAL_BANB:
        pause.from = 13.0F;
        pause.to = 15.0F;
        break;
    case ANIMAL_LION:
    default:
        pause.from = 13.0F;
        pause.to = 15.0F;
        break;
    }
    if (FLAGS(work) & ANIMAL_GROUND) {
        FLAGS(work) &= ~ANIMAL_LEAP;
        if (animal->frame <= pause.to && animal->frame > pause.from) {
            FLAGS(work) |= ANIMAL_STOP;
        } else {
            if (ACROSS_SQUARED(&animal->speed) >= STRIDE_SQUARED) {
                njUnitVector(&animal->speed);
                VECTOR_SCALE(&animal->speed, &animal->speed, STRIDE_SPEED);
                animal_kick_dust(animal, work);
            }
            FLAGS(work) |= ANIMAL_LEAP;
        }
    }
}

/* on the ground, the animal stands still until its motion reaches the
 * leap's frames, and there it leaps toward its place on the circle. the
 * animal must be ANIMAL_USA or ANIMAL_WARA, the kinds animal_init gives
 * this move: for any other kind, up, across and leap stay unset */
void Flicky_moveJump(struct animal *animal, struct task_work *work)
{
    struct frames leap;
    NJS_POINT3 point;
    Float up;
    Float across;
    int heading;

    if (Flicky_moveCmnOnTheFloor(animal, work, &point)) {
        return;
    }
    animal->accel.y += GRAVITY;
#ifdef GCC
    /* GCC can't see that animal_init gives this move only to ANIMAL_USA and
     * ANIMAL_WARA, whose cases set the leap */
    up = across = leap.from = leap.to = 0.0F;
#endif
    switch (animal->kind) {
    case ANIMAL_USA:
        up = 2.25F;
        across = 2.8F;
        leap.from = 2.0F;
        leap.to = 4.0F;
        break;
    case ANIMAL_WARA:
        up = 3.6F;
        across = 3.6F;
        leap.from = 3.0F;
        leap.to = 4.0F;
        break;
    }
    if (!(FLAGS(work) & ANIMAL_GROUND)) {
        return;
    }
    FLAGS(work) &= ~ANIMAL_LEAP;
    FLAGS(work) |= ANIMAL_STOP;
    if (animal->frame <= leap.to && animal->frame > leap.from) {
        FLAGS(work) &= ~ANIMAL_STOP;
        FLAGS(work) |= ANIMAL_LEAP;
        work->pos.y += 0.01F;
        animal->speed.y = 0.0F;
        VECTOR_SUB(&point, &work->pos);
        heading = njArcTan2(point.z, point.x) * ANGLE_PER_RADIAN;
        point.x = across * njCos(heading);
        point.z = across * njSin(heading);
        point.y = up;
        VECTOR_ADD(&animal->accel, &point);
        if (ACROSS_SQUARED(&animal->speed) >= STRIDE_SQUARED) {
            njUnitVector(&animal->speed);
            VECTOR_SCALE(&animal->speed, &animal->speed, STRIDE_SPEED);
            animal_kick_dust(animal, work);
        }
    }
}

/* pull the animal toward a point that circles FLY_HEIGHT above the target,
 * bobbing FLY_BOB up and down. the birds and custom animals always fly, and
 * every animal flies in its barrier */
void animal_fly(struct animal *animal, struct task_work *work)
{
    NJS_POINT3 point;
    NJS_VECTOR pull;
    Float scale;
    Float px;
    int step;

    if (FLAGS(work) & ANIMAL_BARRIER) {
        step = ((animal->seed & 3) + 1) * ANGLE_PER_DEGREE;
    } else {
        step = ((animal->seed & 3) + animal->spec->turn) * ANGLE_PER_DEGREE;
    }
    if (animal->seed & 8) {
        step = -step;
    }
    if (FLAGS(work) & ANIMAL_REVERSE) {
        step = -step;
    }
    animal->orbit += step;
    VECTOR_COPY(&point, &animal->target);
    animal->radius = FLY_RADIUS + (njCos(animal->orbit >> 2) * RADIUS_SWING);
    point.x += animal->radius * njCos(animal->orbit);
    point.z += animal->radius * njSin(animal->orbit);
    point.y += FLY_HEIGHT + (njSin(animal->orbit * 2) * FLY_BOB);
    if (!(FLAGS(work) & ANIMAL_BARRIER)) {
        if (FLAGS(work) & ANIMAL_FLEES) {
            animal->target.y += FLEE_RISE;
        }
    }
    px = point.x;
    if (animal->kind == ANIMAL_TUBA && !((*(Uint16 *)&(work)->timer) & 0x40)) {
        ((&pull)->x = px - (&work->pos)->x,
         (&pull)->y = (&point)->y - (&work->pos)->y,
         (&pull)->z = (&point)->z - (&work->pos)->z);
        scale = 0.05F;
    } else {
        ((&pull)->x = px - (&work->pos)->x,
         (&pull)->y = (&point)->y - (&work->pos)->y,
         (&pull)->z = (&point)->z - (&work->pos)->z);
        scale = 0.01F;
    }
    ((&pull)->x = (&pull)->x * (scale), (&pull)->y = (&pull)->y * (scale),
     (&pull)->z = (&pull)->z * (scale));
    ((&animal->accel)->x += (&pull)->x, (&animal->accel)->y += (&pull)->y,
     (&animal->accel)->z += (&pull)->z);
}

/* push the animal off the walls of the world objects within COLLIDE_RANGE,
 * water aside, and stand it on their floors. each wall it runs into counts
 * a bump. after each object, bumps past a random number below
 * REVERSE_BUMPS reverse its circling. in its barrier, the walls and floors
 * it meets squash the barrier.
 *
 * out of its barrier, an animal that doesn't fly then looks for an edge, if
 * it stood after its last move or has ANIMAL_LEAP set. it is at an edge
 * when no floor was found. it is at one too when the floor found lies more
 * than EDGE_DROP below its last position, or leans more than TOO_STEEP.
 * that floor is the highest below it, unless a floor within STAND_HEIGHT
 * above its position replaces it. at an edge the animal steps back to its
 * last x and z, stops, and counts a bump. it also sets ANIMAL_BLOCKED, on
 * which animal_aim moves a wandering animal's target, or has a fleeing one
 * pick its way again */
void Flicky_checkColli(struct animal *animal, struct task_work *work)
{
    struct sides_query query;
    NJS_VECTOR push;
    struct world_object *objects = numLandCollList;
    /* @hack redundant: i's initializer, which the loop's start sets again,
     * and which loads its 0 into R2 (MOV #0,R2 at 0x8c0179dc); without it,
     * the function runs 2 bytes long and 564 of 801 words differ */
    int i = 0;
    Bool on_x_wall = FALSE;
    Bool on_floor = FALSE;
    Float floor = NO_FLOOR;
    Float floor_up = 1.0F;
    int was_grounded = FLAGS(work) & ANIMAL_GROUND;
    Float x_min;
    Float x_max;
    Float z_min;
    Float z_max;
    Float up_mx;
    Float out_mx;
    Float up_px;
    Float out_px;
    Float up_mz;
    Float out_mz;
    Float up_pz;
    Float out_pz;

    FLAGS(work) &= ~ANIMAL_GROUND;
    FLAGS(work) &= ~ANIMAL_FLOOR;
    VECTOR_COPY(&query.pos, &work->pos);
    ListGroundForCollision(work->pos.x, work->pos.y, work->pos.z,
                           COLLIDE_RANGE);
    if (FLAGS(work) & ANIMAL_BARRIER) {
        x_min = work->pos.x - (animal->barrier_scale.x * BARRIER_REACH);
        x_max = work->pos.x + (animal->barrier_scale.x * BARRIER_REACH);
        z_min = work->pos.z - (animal->barrier_scale.z * BARRIER_REACH);
        z_max = work->pos.z + (animal->barrier_scale.z * BARRIER_REACH);
    } else {
        x_min = work->pos.x - BODY_REACH;
        x_max = work->pos.x + BODY_REACH;
        z_min = work->pos.z - BODY_REACH;
        z_max = work->pos.z + BODY_REACH;
    }
    for (i = 0; i < LandCollList; i++) {
        if (polygon_find_sides(&query, objects[i].object, objects[i].flags)) {
            VECTOR_CLEAR(&push);
            if (objects[i].flags & WORLD_WATER) {
                continue;
            }
            up_mx = query.sides[SIDE_MINUS_X].normal_jp.y;
            out_mx = query.sides[SIDE_MINUS_X].normal_jp.x;
            if (query.sides[SIDE_MINUS_X].found && njCos(STEEP) > up_mx) {
                if ((out_mx >= 0.0F && query.sides[SIDE_MINUS_X].level >
                                           x_min + animal->speed.x) ||
                    (out_mx < 0.0F && x_max + animal->speed.x >
                                          query.sides[SIDE_MINUS_X].level)) {
                    if (animal->speed.x < 0.0F) {
                        animal->speed.x = -(animal->speed.x * 0.1F);
                    }
                    VECTOR_ADD(&push, &query.sides[SIDE_MINUS_X].normal_jp);
                    on_x_wall = TRUE;
                    animal->bumps++;
                }
            }
            up_px = query.sides[SIDE_PLUS_X].normal_jp.y;
            out_px = query.sides[SIDE_PLUS_X].normal_jp.x;
            if (query.sides[SIDE_PLUS_X].found && njCos(STEEP) > up_px) {
                if ((out_px <= 0.0F && x_max + animal->speed.x >
                                           query.sides[SIDE_PLUS_X].level) ||
                    (out_px > 0.0F && query.sides[SIDE_PLUS_X].level >
                                          x_min + animal->speed.x)) {
                    if (animal->speed.x > 0.0F) {
                        animal->speed.x = -(animal->speed.x * 0.1F);
                    }
                    VECTOR_ADD(&push, &query.sides[SIDE_PLUS_X].normal_jp);
                    on_x_wall = TRUE;
                    animal->bumps++;
                }
            }
            if (query.sides[SIDE_BELOW].found &&
                query.sides[SIDE_BELOW].normal_jp.y > 0.0F) {
                if (query.sides[SIDE_BELOW].level > floor) {
                    floor = query.sides[SIDE_BELOW].level;
                    floor_up = query.sides[SIDE_BELOW].normal_jp.y;
                }
                /* scl.z keeps the floor's level, which nothing reads */
                work->scl.z = query.sides[SIDE_BELOW].level;
                animal->floor_ang_x = query.sides[SIDE_BELOW].ang_x;
                animal->floor_ang_z = query.sides[SIDE_BELOW].ang_z;
                FLAGS(work) |= ANIMAL_FLOOR;
                if (query.sides[SIDE_BELOW].level >
                    work->pos.y + animal->speed.y - STAND_HEIGHT) {
                    animal->speed.y = 0.0F;
                    work->pos.y = query.sides[SIDE_BELOW].level + STAND_HEIGHT;
                    FLAGS(work) |= ANIMAL_GROUND;
                    on_floor = TRUE;
                }
            } else {
                if (query.sides[SIDE_ABOVE].found &&
                    query.sides[SIDE_ABOVE].normal_jp.y > 0.0F &&
                    work->pos.y + STAND_HEIGHT >
                        query.sides[SIDE_ABOVE].level) {
                    work->scl.z = query.sides[SIDE_ABOVE].level;
                    floor = query.sides[SIDE_ABOVE].level;
                    floor_up = query.sides[SIDE_ABOVE].normal_jp.y;
                    animal->floor_ang_x = query.sides[SIDE_ABOVE].ang_x;
                    animal->floor_ang_z = query.sides[SIDE_ABOVE].ang_z;
                    FLAGS(work) |= ANIMAL_FLOOR;
                    FLAGS(work) |= ANIMAL_GROUND;
                    animal->speed.y = 0.0F;
                    work->pos.y = query.sides[SIDE_ABOVE].level + STAND_HEIGHT;
                    on_floor = TRUE;
                }
            }
            up_mz = query.sides[SIDE_MINUS_Z].normal_jp.y;
            out_mz = query.sides[SIDE_MINUS_Z].normal_jp.z;
            if (query.sides[SIDE_MINUS_Z].found && njCos(STEEP) > up_mz) {
                if ((out_mz >= 0.0F && query.sides[SIDE_MINUS_Z].level >
                                           z_min + animal->speed.z) ||
                    (out_mz < 0.0F && z_max + animal->speed.z >
                                          query.sides[SIDE_MINUS_Z].level)) {
                    if (animal->speed.z < 0.0F) {
                        animal->speed.z = -(animal->speed.z * 0.5F);
                    }
                    VECTOR_ADD(&push, &query.sides[SIDE_MINUS_Z].normal_jp);
                    animal->bumps++;
                }
            }
            up_pz = query.sides[SIDE_PLUS_Z].normal_jp.y;
            out_pz = query.sides[SIDE_PLUS_Z].normal_jp.z;
            if (query.sides[SIDE_PLUS_Z].found && njCos(STEEP) > up_pz) {
                if ((out_pz <= 0.0F && z_max + animal->speed.z >
                                           query.sides[SIDE_PLUS_Z].level) ||
                    (out_pz > 0.0F && query.sides[SIDE_PLUS_Z].level >
                                          z_min + animal->speed.z)) {
                    if (animal->speed.z > 0.0F) {
                        animal->speed.z = -(animal->speed.z * 0.5F);
                    }
                    VECTOR_ADD(&push, &query.sides[SIDE_PLUS_Z].normal_jp);
                    animal->bumps++;
                }
            }
            if (FLAGS(work) & ANIMAL_BARRIER) {
                /* on_floor presses PRESS_Y and PRESS_Z, and on_x_wall
                 * PRESS_X */
                /* @hack redundant: each flag masked to its bit, which keeps
                 * the animal in R14 (MOV R4,R14 at 0x8c0179ea). the flags are
                 * set only to FALSE or TRUE, so the masks change no value;
                 * unmasked, the function runs 8 bytes long and 769 of 801
                 * words differ */
                squash_barrier(&animal->barrier_scale,
                               ((on_floor & 1) << 1) | ((on_floor & 1) << 2) |
                                   (on_x_wall & 1));
            }
            VECTOR_ADD(&animal->accel, &push);
            if (animal->bumps > RANDOM(0.0F, REVERSE_BUMPS)) {
                animal->bumps = 0;
                if (FLAGS(work) & ANIMAL_REVERSE) {
                    FLAGS(work) &= ~ANIMAL_REVERSE;
                } else {
                    FLAGS(work) |= ANIMAL_REVERSE;
                }
            }
        }
    }
    if (animal->move != animal_fly && !(FLAGS(work) & ANIMAL_BARRIER)) {
        if ((was_grounded || (FLAGS(work) & ANIMAL_LEAP)) &&
            ((floor > NO_FLOOR && animal->last_pos.y - floor > EDGE_DROP) ||
             floor == NO_FLOOR || njCos(TOO_STEEP) > floor_up)) {
            animal->bumps++;
            work->pos.x = animal->last_pos.x;
            work->pos.z = animal->last_pos.z;
            FLAGS(work) |= ANIMAL_STOP;
            FLAGS(work) |= ANIMAL_BLOCKED;
        }
    }
}

void animal_garden_update(struct animal *animal, struct task_work *work,
                          struct task *task)
{
    VARS(work)->age++;
    if (VARS(work)->age > AGE_MAX) {
        VARS(work)->age = AGE_MAX;
    }
    if (VARS(work)->action != NULL) {
        animal->frame += animal->spec->speed;
        if (animal->frame > VARS(work)->action->motion->nbFrame) {
            animal->frame -= VARS(work)->action->motion->nbFrame;
        }
    }
    switch (work->mode) {
    case GARDEN_LOOSE:
        animal_garden_loose(animal, work, task);
        break;
    case GARDEN_THROWN:
        animal_garden_thrown(animal, work, task);
        break;
    case GARDEN_HELD:
        animal_garden_held(animal, work);
        break;
    }
}

void animal_garden_loose(struct animal *animal, struct task_work *work,
                         struct task *task)
{
    struct task_motion *motion;
    Float floor;

    motion = task->motion;
    motion->speed.y -= 0.05F;
    VECTOR_ADD(&work->pos, &motion->speed);
    work->ang.x = 0;
    work->ang.z = 0;
    floor = shadow_draw(work, 0.35F);
    work->pos.y -= 1.0F;
    if (floor > work->pos.y - STAND_HEIGHT) {
        work->pos.y = floor + STAND_HEIGHT;
        if (motion->speed.y < 0.0F) {
            motion->speed.y *= -0.6F;
        }
        motion->speed.x *= 0.7F;
        motion->speed.z *= 0.7F;
    }
    if (work->flags & CARRY_HELD) {
        work->mode = GARDEN_HELD;
        COUNT(work) = 0;
    } else {
        EntryColliList(work);
    }
}

static void animal_garden_thrown(struct animal *animal, struct task_work *work,
                                 struct task *task)
{
    struct task_motion *motion;
    Float floor;

    motion = task->motion;
    motion->speed.y -= 0.05F;
    VECTOR_ADD(&work->pos, &motion->speed);
    work->ang.x = 0;
    work->ang.z = 0;
    floor = shadow_draw(work, 0.35F);
    if (floor > work->pos.y - STAND_HEIGHT) {
        work->pos.y = floor + STAND_HEIGHT;
        if (motion->speed.y < 0.0F) {
            motion->speed.y *= -0.6F;
        }
        motion->speed.x *= 0.7F;
        motion->speed.z *= 0.7F;
    }
    if (COUNT(work)++ > THROWN_STEPS) {
        work->mode = GARDEN_LOOSE;
        COUNT(work) = 0;
    }
    EntryColliList(work);
}

/* face the way player 0 faces: turn by up to HELD_TURN a step for
 * HELD_STEPS steps, and outright after. once no player holds the animal,
 * it is thrown */
void animal_garden_held(struct animal *animal, struct task_work *work)
{
    if (COUNT(work)++ < HELD_STEPS) {
        work->ang.y = AdjustAngle(
            work->ang.y, NJM_DEG_ANG(90) - playertwp[0]->ang.y, HELD_TURN);
    } else {
        work->ang.y = NJM_DEG_ANG(90) - playertwp[0]->ang.y;
    }
    if (!(work->flags & CARRY_HELD)) {
        work->mode = GARDEN_THROWN;
        COUNT(work) = 0;
    }
}

void Flicky_dsp(struct animal *animal, struct task_work *work)
{
    Angle ang;

    ang = work->ang.y + animal->spec->ang;
    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        animal_draw_body(animal, work, ang);
        animal_draw_barrier(animal, work, ang);
    }
}

void animal_draw_body(struct animal *animal, struct task_work *work, Angle ang)
{
    Float scale;

    if (VARS(work)->action != NULL) {
        njSetTexture_jp(animal->spec->texlist);
        njPushMatrix(NULL);
        scale = animal->spec->scale;
        njTranslate(((void *)0), work->pos.x, work->pos.y - 2.0F, work->pos.z);
        ((ang) ? (njRotateY)(((void *)0), (ang)) : (void)0);
        njScale(((void *)0), scale, scale, scale);
        ds_ActionClip(((struct animal_vars *)&(work)->vars)->action,
                      animal->frame);
        late_DrawObjectClipEx(1);
    }
}

void animal_draw_barrier(struct animal *animal, struct task_work *work,
                         Angle ang)
{
    if (FLAGS(work) & ANIMAL_BARRIER) {
        njSetTexture_jp(&al_barria_texlist);
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, work->pos.y + 1.2F, work->pos.z);
        njScale(NULL, animal->barrier_scale.x, animal->barrier_scale.y,
                animal->barrier_scale.z);
        njRotateXYZ(NULL, animal->orbit, animal->orbit + ang, ang);
        late_DrawObject(&al_barria_object);
        late_DrawObjectClipEx(1);
    }
}

void animal_kick_dust(struct animal *animal, struct task_work *work)
{
    NJS_POINT3 pos;
    NJS_VECTOR speed;

    pos.x = work->pos.x;
    pos.y = work->pos.y - 0.2F;
    pos.z = work->pos.z;
    speed.x = -(animal->speed.z * 0.8F);
    speed.z = -(animal->speed.x * 0.8F);
    speed.y = 0.0001F;
    ;
}

/* pull each axis of the barrier's scale toward the mean of the other two,
 * as a damped spring does. hold each within BARRIER_LEAST and BARRIER_MOST */
void Flicky_transformBaloon(struct animal *animal, struct task_work *work)
{
    /* @hack redundant: 12 bytes of frame that no code reads, of a type unknown,
     * declared as a Uint32[3]. the image's ADD #-36,R15 reserves them
     * (0x8c018680); without them, 2 of 204 words differ */
    Uint32 unused[3];
    NJS_VECTOR step;
    NJS_VECTOR mean;

    mean.x = (animal->barrier_scale.y + animal->barrier_scale.z) * 0.5F;
    mean.y = (animal->barrier_scale.z + animal->barrier_scale.x) * 0.5F;
    mean.z = (animal->barrier_scale.x + animal->barrier_scale.y) * 0.5F;
    VECTOR_DIFF(&step, &mean, &animal->barrier_scale);
    VECTOR_SCALE(&step, &step, 0.05F);
    VECTOR_ADD(&animal->barrier_speed, &step);
    VECTOR_SCALE(&step, &animal->barrier_speed, 0.167935F);
    VECTOR_SUB(&animal->barrier_speed, &step);
    VECTOR_ADD(&animal->barrier_scale, &animal->barrier_speed);
    if (animal->barrier_scale.x > BARRIER_MOST) {
        animal->barrier_scale.x = BARRIER_MOST;
    }
    if (animal->barrier_scale.y > BARRIER_MOST) {
        animal->barrier_scale.y = BARRIER_MOST;
    }
    if (animal->barrier_scale.z > BARRIER_MOST) {
        animal->barrier_scale.z = BARRIER_MOST;
    }
    if (animal->barrier_scale.x < BARRIER_LEAST) {
        animal->barrier_scale.x = BARRIER_LEAST;
    }
    if (animal->barrier_scale.y < BARRIER_LEAST) {
        animal->barrier_scale.y = BARRIER_LEAST;
    }
    if (animal->barrier_scale.z < BARRIER_LEAST) {
        animal->barrier_scale.z = BARRIER_LEAST;
    }
}

/* flatten the barrier along the axes pressed, and widen it along the rest */
void squash_barrier(NJS_VECTOR *scale, int axes)
{
    if ((axes & PRESS_X) && (axes & PRESS_Z)) {
        scale->x -= 0.15F;
        scale->y += 0.3F;
        scale->z -= 0.15F;
    } else if (axes & PRESS_X) {
        scale->x -= 0.3F;
        scale->y += 0.15F;
        scale->z += 0.15F;
    } else if (axes & PRESS_Z) {
        scale->x += 0.15F;
        scale->y += 0.15F;
        scale->z -= 0.3F;
    }
    if (axes & PRESS_Y) {
        scale->x += 0.15F;
        scale->y -= 0.3F;
        scale->z += 0.15F;
    }
}

struct task_work *animal_create_custom(struct animal_model *model,
                                       void (*destructor)(struct task *task))
{
    struct task_work *work;
    struct animal *animal;
    struct animal_spec *spec;

    if (model == NULL) {
        return NULL;
    }
    work = animal_create(model->pos.x, model->pos.y, model->pos.z,
                         animal_start_custom);
    if (work != NULL) {
        animal = VARS(work)->animal;
        spec = CAlloc(1, sizeof(struct animal_spec));
        VARS(work)->action = model->action;
        /* @bug memory: a spec that can't be allocated leaves the task running
         * with ANIMAL_OWN_SPEC set and the record's spec null, which
         * animal_init keeps. animal_draw reads the spec's ang through it
         * (MOV.L @(4,R12),R3 at 0x8c01845a), and with an action
         * animal_update reads its speed (FMOV.S @R1,FR3 at 0x8c016954) */
        FLAGS(work) |= ANIMAL_STAY | ANIMAL_OWN_SPEC | ANIMAL_KEEP_BARRIER;
        if (spec != NULL) {
            animal->spec = spec;
            animal->destructor = destructor;
            spec->color = RANDOM(0.0F, 8.0F);
            spec->turn = 1;
            spec->ang = 0;
            spec->scale = 1.0F;
            spec->speed = model->speed;
            spec->texlist = model->texlist;
            return work;
        }
    }
    return NULL;
}

void animal_start_custom(struct task *task)
{
    animal_start(task, ANIMAL_CUSTOM);
}
