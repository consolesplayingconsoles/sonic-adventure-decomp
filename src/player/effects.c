/* @unit 8C0B32E0-8C0B6060 @data 8C15BBEC-8C15BBF4 +r04 +egflags +pool32 +poolbra=bubble_origin:2,FUN_8c0b396e:1,bubbles_step:5,bubbles_step:9,ball_shrink_place:1,dash_alloc:2,FUN_8c0b4a60:6,trail_extend:2,trail_extend:8 +poolafter=FUN_8c0b3f1a,ball_jitter_place,ball_jitter_step,ball_shrink_draw,dash_draw,dash_destroy,trail_step,trail_create,charge_spark_create,EffectSpinRibbon,CreateEffectSpinRibbon,ice_piece_start +asmfunc=bubbles_step,FUN_8c0b4a60,FUN_8c0b5460 */
/* player effects: bubbles and ice, and Sonic's spin balls, dash, aura and
 * light charge */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#define TEXT_6 ""
#define TEXT_7 ""
#define TEXT_8 ""
#define TEXT_9 ""
#define TEXT_10 ""
#define TEXT_11 ""
#define TEXT_12 ""
#define TEXT_13 ""
#define TEXT_14 ""
#define TEXT_15 ""
#define TEXT_16 ""
#define TEXT_17 ""
#define TEXT_18 ""
#define TEXT_19 ""
#define TEXT_20 ""
#define TEXT_21 ""
#define TEXT_22 ""
#define TEXT_23 ""
#define TEXT_24 ""
#define TEXT_25 ""
#define TEXT_26 ""
#define TEXT_27 ""
#define TEXT_28 ""
#define TEXT_29 ""
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/sprite.h"
#include "draw/tree.h"
#include "hud/hud.h"
#include "object/placement.h"
#include "player/effects.h"
#include "player/player.h"
#include "player/s_mot.h"
#include "player/sonic_effect_models.h"
#include "player/sonic_ice_piece.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/texlists.h"
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
void FUN_8c60e3da(NJS_ACTION *action, Float frame);
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
void *CAlloc(int count, int size);
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void FUN_8c0b396e(struct task *task);
void FUN_8c0b3ee6(struct task *task);
void FUN_8c0b3f00(struct task *task);
void FUN_8c0b3f1a(struct task *task);
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
struct task *GetPlayerTaskPointer(Uint8 player);
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
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
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

#define TEXT_1_LENGTH 8
#define TEXT_2_LENGTH 8
#define TEXT_3_LENGTH 8
#define TEXT_4_LENGTH 8
#define TEXT_5_LENGTH 8
#define TEXT_6_LENGTH 8
#define TEXT_7_LENGTH 8
#define TEXT_8_LENGTH 8
#define TEXT_9_LENGTH 8
#define TEXT_10_LENGTH 8
#define TEXT_11_LENGTH 8
#define TEXT_12_LENGTH 8
#define TEXT_13_LENGTH 8
#define TEXT_14_LENGTH 8
#define TEXT_15_LENGTH 8
#define TEXT_16_LENGTH 8
#define TEXT_17_LENGTH 8
#define TEXT_18_LENGTH 8
#define TEXT_19_LENGTH 8
#define TEXT_20_LENGTH 8
#define TEXT_21_LENGTH 8
#define TEXT_22_LENGTH 8
#define TEXT_23_LENGTH 8
#define TEXT_24_LENGTH 8
#define TEXT_25_LENGTH 8
#define TEXT_26_LENGTH 9
#define TEXT_27_LENGTH 9
#define TEXT_28_LENGTH 9
#define TEXT_29_LENGTH 9

/* how many textures SON_EFF's texlist has */
#define SON_EFF_TEXTURES 29

/* bubble_sources holds CHARACTER_SOURCES rows for each of five characters */
#define BUBBLE_SOURCES 15
#define CHARACTER_SOURCES 3

/* a bubbles task's work->tick: which of its character's sources it uses.
 * a drowning player has a source for its bursts and one for between them */
#define BURST_TIME 40
#define BUBBLE_DEPTH 500.0F
#define BALL_HEIGHT 5.0F
#define BALL_STEPS 5
#define SHRINK_STEPS 10
#define DASH_SECOND_SET 0x8
#define DASH_STEPS 20
#define SECOND_SET_END 19
#define STREAK_LENGTH 8.0F
#define TRAIL_STOP 0.05F
#define SPARK_SPREAD 1.0F
#define CHARGE_SPEED 3.0F
#define ICE_PIECES 16
#define BUBBLES(work) ((struct bubbles_vars *)&(work)->vars)
#define BALL(work) ((struct ball_vars *)&(work)->vars)
#define DASH(work) ((struct dash_vars *)&(work)->vars)
#define TRAIL(work) ((struct trail_vars *)&(work)->vars)
#define SPARK(work) ((struct spark_vars *)&(work)->vars)
#define CHARGE(work) ((struct charge_vars *)&(work)->vars)
#define ICE(work) ((struct ice_vars *)&(work)->vars)
#define SOURCE(work) (&BUBBLES(work)->sources[(work)->tick])
#define OWNER(work) ((Sint8)(work)->scl.z)
#define STRIP(task) ((NJS_POINT3COL *)(task)->motion)
enum bubble_use {
    BUBBLES_UNDER_WATER,
    BUBBLES_DROWN_BURST,
    BUBBLES_DROWN_STEADY
};

/* where a source's bubbles start and the way they head. BUBBLES_AT_WELD4
 * starts them out from weld_point4 along weld_axis4, the point and axis
 * the player's WELD_MARK + 4 weld keeps; BUBBLES_AT_WELD5 takes weld 5's.
 * any other kind starts them eye_height above the player's middle, heading
 * along x */
enum bubble_kind { BUBBLES_AT_WELD4, BUBBLES_AT_WELD5 };

/* a bubbles task's work->submode */
enum bubble_burst { BUBBLES_STEADY, BUBBLES_BURSTING };
/* the timer a burst starts with. bubbles_step takes 1 off it on each step of a
 * burst, and adds 1 back on a frame's first step. it falls only on a frame's
 * later steps, so a burst ends only while frames take two steps or more */

/* a bubble starts less than this far below the water's surface, or not at
 * all */

/* how far up from the player a spin ball starts, turned as the player
 * faces */
/* the steps a ball draws after its first: BALL_STEPS for a jitter or
 * follow ball, and SHRINK_STEPS for a shrink ball. each fades out over
 * them */

/* in a dash's work->flags: it draws dash_textures_b, the second set */
/* the steps a dash draws with the first set. with the second, it ends on
 * step SECOND_SET_END, before that step draws */
/* the streak model's length along x */

/* a trail stops growing at a step this short or shorter */

/* a charge spark's speed on each axis lies within half this of 0 */

/* the farthest a light of the light charge flies in a step */

struct bubble {
    Float surface; /* the height of the water's surface, where it bursts */
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    Sint16 ang;
    Sint16 spin; /* added to ang each frame */
    Float aspect; /* its height over its width */
    Float size;
    Float max_size;
    struct bubble *prev;
    struct bubble *next;
};

struct bubble_start {
    Sint32 character;
    NJS_POINT3 offset; /* from where the weld puts them */
    Float reach; /* how far along the weld's axis they start */
    Float speed; /* how fast they start along the weld's axis */
    Sint32 kind; /* a bubble_kind */
};

struct bubble_motion {
    Float size_max; /* each grows to a random size between this and size_min */
    Float size_min;
    Float squash; /* a bubble's aspect is 1 less up to this, at random */
    Float drag; /* the share of its speed a bubble keeps each frame */
    Float lift; /* the upward speed a bubble gains each frame */
    /* a new bubble's speed gains up to this either way on each axis */
    Float spread;
    Float rate; /* the chance of a bubble on a step that leaves it to chance */
    /* a bubble spins up to half this either way, in degrees a frame */
    Float spin;
    Float growth; /* the size it gains each frame */
    Float wobble_rate; /* the chance each frame it wobbles */
    /* a wobble adds up to half this either way to the speed on x and z */
    Float wobble;
};

struct bubble_source {
    struct bubble_start start;
    struct bubble_motion motion;
};

struct bubbles_vars {
    struct bubble_source *sources; /* its character's rows, or null */
    Uint8 unk_04[4];
    struct bubble *list;
};

struct ball_vars {
    Uint8 player; /* the player's number, which the player's task sets */
    Uint8 unk_01[7];
    NJS_TEXLIST *texlist; /* s_ball_a or b */
};

struct dash_vars {
    Uint8 player; /* the player's number, which the player's task sets */
    Uint8 unk_01[7];
    NJS_OBJECT *object; /* its own copy of the streak */
};

struct trail_vars {
    Uint32 count; /* the points the strip has room for */
    union {
        Uint32 color;
        struct {
            Uint8 b, g, r;
            /* @hack type: a signed, so charge_spark_create's -1 is MOV #-1
             * (0x8c0bc8ea). as a Uint8 set to 255, SHC loads it from a pool:
             * charge_spark_create runs 70 bytes long and 135 of its 151
             * words differ */
            Sint8 a;
        } argb; /* as NJS_BGRA has them */
    } color;
    NJS_POINT3 *follow; /* the point it grows toward */
};

struct spark_vars {
    Uint32 count; /* the steps it has left */
};

/* the vars of one of the light charge's lights */
struct charge_vars {
    Uint8 player; /* the number of the player it flies to */
    Uint8 unk_01[3];
    Sint32 timer; /* the steps it has left */
};

/* the vars of a block of ice, and of each piece it breaks into */
struct ice_vars {
    NJS_OBJECT *object;
    Uint8 unk_04[4];
    NJS_TEXLIST *texlist;
};

/* a bubbles task's source, which work->tick picks, and the number of the
 * player whose bubbles they are, which player_init stores in work->scl.z */

/* a trail's strip of triangles, which trail_start allocates and keeps in
 * task->motion */

void bubbles_destroy(struct task *task);
void bubbles_step(struct task *task);
void bubbles_draw(struct task *task);
void ball_jitter_place(struct task_work *work);
void ball_follow_place(struct task_work *work);
void ball_shrink_place(struct task_work *work);
void ball_jitter_draw(struct task *task);
void ball_jitter_step(struct task *task);
void ball_follow_draw(struct task *task);
void ball_follow_step(struct task *task);
void ball_shrink_draw(struct task *task);
void ball_shrink_step(struct task *task);
Bool dash_alloc(struct task_work *work);
void dash_draw(struct task *task);
void FUN_8c0b4a60(struct task *task);
void dash_destroy(struct task *task);
extern struct bubble_source bubble_sources[15];
extern NJS_TEXANIM bubble_texanim;
extern NJS_TEXNAME son_eff_textures[29];
extern NJS_TEXLIST ball_textures[2];
extern NJS_TEXLIST dash_textures[20];
extern NJS_TEXLIST dash_textures_b[19];
extern NJS_TEXLIST trail_textures[2];
extern NJS_TEXLIST charge_textures[2];
extern NJS_TEXLIST son_eff_texlist;
extern NJS_TEXANIM charge_texanim;
extern NJS_SPRITE charge_sprites[2];
extern struct collision_shape charge_shape;
extern NJS_MATRIX dash_matrix;

/* a new bubble at the head of work's list, or null when the heap is full */
struct bubble *bubble_alloc(struct task_work *work)
{
    struct bubble *bubble = MAlloc(sizeof(struct bubble));

    if (bubble != NULL) {
        bubble->prev = NULL;
        bubble->next = BUBBLES(work)->list;
        if (BUBBLES(work)->list != NULL) {
            BUBBLES(work)->list->prev = bubble;
        }
        BUBBLES(work)->list = bubble;
    }
    return bubble;
}

void bubble_free(struct task_work *work, struct bubble *bubble)
{
    struct bubble *prev = bubble->prev;
    struct bubble *next = bubble->next;

    if (prev != NULL) {
        prev->next = next;
    } else {
        BUBBLES(work)->list = next;
    }
    if (next != NULL) {
        next->prev = prev;
    }
    Free(bubble);
}

/* carry pos, speed and, unless it is null, point from the player's own
 * frame into the world's. the player's frame is centered on its middle and
 * turned as it faces */
void bubble_to_world(int player, NJS_POINT3 *pos, NJS_VECTOR *speed,
                     NJS_POINT3 *point)
{
    struct task_work *work = playertwp[player];
    struct collision_shape *shape = work->collision->shapes;

    njPushMatrix(&nj_unit_matrix_);
    njTranslateV(NULL, &shape->center);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, NJM_DEG_ANG(180) - work->ang.y);
    njCalcPoint(NULL, pos, pos);
    njCalcVector(NULL, speed, speed);
    if (point != NULL) {
        njCalcPoint(NULL, point, point);
    }
    late_DrawObjectClipEx(1);
}

/* a new bubble's start and speed in the world, by work's source, and
 * unless point is null, the point it starts out from */
void bubble_origin(struct task_work *work, NJS_POINT3 *pos, NJS_VECTOR *speed,
                   NJS_POINT3 *point)
{
    struct player *record = GetPlayerWorkPointer(OWNER(work));
    Float *axis;

    switch (SOURCE(work)->start.kind) {
    case BUBBLES_AT_WELD4:
        *speed = record->weld_axis4;
        /* @hack spelling: the speed scaled through a Float walk, for the
         * image's @Rn+ loads; through the members, 124 of 379 words
         * differ */
        axis = &speed->x;
        *axis++ *= SOURCE(work)->start.speed;
        *axis++ *= SOURCE(work)->start.speed;
        *axis *= SOURCE(work)->start.speed;
        pos->x = SOURCE(work)->start.offset.x +
                 (SOURCE(work)->start.reach * record->weld_axis4.x) +
                 record->weld_point4.x;
        pos->y = SOURCE(work)->start.offset.y +
                 (SOURCE(work)->start.reach * record->weld_axis4.y) +
                 record->weld_point4.y;
        pos->z = SOURCE(work)->start.offset.z +
                 (SOURCE(work)->start.reach * record->weld_axis4.z) +
                 record->weld_point4.z;
        if (point != NULL) {
            *point = record->weld_point4;
        }
        break;
    case BUBBLES_AT_WELD5:
        *speed = record->weld_axis5;
        /* @hack spelling: the same walk; through the members, 126 of 379 words
         * differ */
        axis = &speed->x;
        *axis++ *= SOURCE(work)->start.speed;
        *axis++ *= SOURCE(work)->start.speed;
        *axis *= SOURCE(work)->start.speed;
        pos->x = SOURCE(work)->start.offset.x +
                 (SOURCE(work)->start.reach * record->weld_axis5.x) +
                 record->weld_point5.x;
        pos->y = SOURCE(work)->start.offset.y +
                 (SOURCE(work)->start.reach * record->weld_axis5.y) +
                 record->weld_point5.y;
        pos->z = SOURCE(work)->start.offset.z +
                 (SOURCE(work)->start.reach * record->weld_axis5.z) +
                 record->weld_point5.z;
        if (point != NULL) {
            *point = record->weld_point5;
        }
        break;
    default:
        *pos = SOURCE(work)->start.offset;
        pos->x += SOURCE(work)->start.reach;
        pos->y += record->consts.eye_height;
        speed->x = SOURCE(work)->start.speed;
        speed->y = 0.0F;
        speed->z = 0.0F;
        if (point != NULL) {
            point->x = 0.0F;
            point->y = pos->y;
            point->z = 0.0F;
        }
        break;
    }
    bubble_to_world(OWNER(work), pos, speed, point);
}

/* a new bubble from work's source, or null. it needs water above the
 * player as of the step before, and room on the heap. its start must lie
 * less than BUBBLE_DEPTH below the water's surface */
struct bubble *bubble_create(struct task_work *work)
{
    Sint8 number = OWNER(work);
    struct player *record = GetPlayerWorkPointer(number);
    struct bubble *bubble = NULL;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    Float size;

    if (!(record->shadow.last_above_flags & WORLD_WATER)) {
        return NULL;
    }
    bubble_origin(work, &pos, &speed, NULL);
    /* @hack spelling: bubble assigned in the test, which keeps pos.y, the
     * surface and bubble in the frame (0x8c0ba7f4, 0x8c0ba800, 0x8c0ba824).
     * in an if of its own, they take registers: the function runs 22 bytes
     * short and 274 of 292 words differ */
    if (pos.y < record->shadow.above &&
        pos.y + BUBBLE_DEPTH > record->shadow.above &&
        (bubble = bubble_alloc(work)) != NULL) {
        size =
            ((SOURCE(work)->motion.size_max - SOURCE(work)->motion.size_min) *
             rand() * RAND_SCALE) +
            SOURCE(work)->motion.size_min;
        speed.x +=
            ((rand() * RAND_SCALE) - 0.5F) * SOURCE(work)->motion.spread * 2.0F;
        speed.y +=
            ((rand() * RAND_SCALE) - 0.5F) * SOURCE(work)->motion.spread * 2.0F;
        speed.z +=
            ((rand() * RAND_SCALE) - 0.5F) * SOURCE(work)->motion.spread * 2.0F;
        bubble->pos = pos;
        bubble->speed = speed;
        /* any angle: up to three turns, which an Angle wraps */
        bubble->ang =
            (Angle)(rand() * (RAND_SCALE * 1080.0F * ANGLE_PER_DEGREE));
        bubble->spin = (Angle)(((rand() * RAND_SCALE) - 0.5F) *
                               SOURCE(work)->motion.spin * ANGLE_PER_DEGREE);
        bubble->surface = record->shadow.above;
        bubble->aspect =
            1.0F - (rand() * SOURCE(work)->motion.squash * RAND_SCALE);
        bubble->size = size * 0.1F;
        bubble->max_size = size;
    }
    return bubble;
}

/* find the sources for player 0's character, unless the set editor holds
 * the task */
void FUN_8c0b396e(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack type: i unsigned, which SHC tests with CMP/HS (0x8c0baac2); as
     * an int, 1 of 63 words differ */
    int i;

    task->draw = bubbles_draw;
    task->step = bubbles_step;
    task->destructor = bubbles_destroy;
    BUBBLES(work)->list = NULL;
    work->submode = BUBBLES_STEADY;
    work->timer = 0;
    if (!OnEdit(task)) {
        work->tick = BUBBLES_UNDER_WATER;
        ((struct bubbles_vars *)&(work)->vars)->sources = ((void *)0);
        for (i = 0; i < 15U; i += 3) {
            if (GetPlayerCharacterName(0) ==
                bubble_sources[i].start.character) {
                BUBBLES(work)->sources = &bubble_sources[i];
                return;
            }
        }
    }
}

void bubbles_destroy(struct task *task)
{
    struct task_work *work = task->work;

    while (BUBBLES(work)->list != NULL) {
        bubble_free(work, BUBBLES(work)->list);
    }
}

/* make the player's bubbles each step, and move them once a frame. a burst
 * starts once the player's action is at frame 1 or less. under water, the
 * player tries for a bubble by chance on each step of a burst. drowning, it
 * tries on every step of a burst, and by chance between bursts. bubble_create
 * decides each try */
void bubbles_step(struct task *task)
{
    struct task_work *work = task->work;
    struct bubble_source *source;
    struct bubble *bubble;
    struct bubble *next;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    NJS_POINT3 point;
    NJS_POINT3 center;
    Float *center_axis;
    Float *pos_axis;
    Float *speed_axis;
    char *center_byte;
    char *point_byte;
    char *pos_byte;
    Float ball_radius;
    Float cx;
    Float cy;
    Float cz;
    Float drag;
    Float lift;
    Float growth;
    Float wobble_rate;
    Float wobble;
    Float dx;
    Float dy;
    Float dz;
    Float px;
    Float py;
    Float pz;
    Float vx;
    Float vy;
    Float vz;
    Float distance2;
    Float radius;
    Float radius2;
    Float size;
    Float push;
    Float grown;
    Float room;
    Float y;
    Float limit;
    Float surface;

    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Z), "player");
        return;
    }
    if (playertwp[OWNER(work)] == NULL || SOURCE(work) == NULL) {
        FreeTask(task);
        return;
    }
    if (playertwp[OWNER(work)]->submode == PLAYER_MODE_DROWN) {
        if (work->submode != BUBBLES_STEADY) {
            work->tick = BUBBLES_DROWN_BURST;
        } else {
            work->tick = BUBBLES_DROWN_STEADY;
        }
    } else {
        work->tick = BUBBLES_UNDER_WATER;
    }
    if (work->submode != BUBBLES_STEADY) {
        if (work->tick != BUBBLES_UNDER_WATER ||
            rand() * RAND_SCALE < SOURCE(work)->motion.rate) {
            bubble_create(work);
        }
        if (TASK_TIMER(work)-- <= 0) {
            work->submode = BUBBLES_STEADY;
        }
    } else {
        if (work->tick != BUBBLES_UNDER_WATER &&
            rand() * RAND_SCALE < SOURCE(work)->motion.rate) {
            bubble_create(work);
        }
        if (!(GetPlayerWorkPointer(OWNER(work))->anim.frame > 1.0F)) {
            work->submode = BUBBLES_BURSTING;
            work->timer = BURST_TIME;
        }
    }
    bubbles_draw(task);
    if (loop_count != 0) {
        return;
    }

    /* the ball the bubbles keep out of. its center mirrors their start, pos,
     * through point, so pos lies on its surface */
    bubble_origin(work, &pos, &speed, &point);
    /* @hack spelling: center as point less pos through byte cursors, for the
     * image's @Rn+ loads; through the members, the function runs 2 bytes
     * long and 300 of 482 words differ */
    center_byte = (char *)&center;
    point_byte = (char *)&point;
    pos_byte = (char *)&pos;
    *(Float *)center_byte = *(Float *)point_byte - *(Float *)pos_byte;
    center_byte += sizeof(Float);
    point_byte += sizeof(Float);
    pos_byte += sizeof(Float);
    *(Float *)center_byte = *(Float *)point_byte - *(Float *)pos_byte;
    center_byte += sizeof(Float);
    point_byte += sizeof(Float);
    pos_byte += sizeof(Float);
    *(Float *)center_byte = *(Float *)point_byte - *(Float *)pos_byte;
    /* @hack spelling: center doubled through a Float walk; through the members,
     * 300 of 482 words differ */
    center_axis = &center.x;
    *center_axis++ *= 2.0F;
    *center_axis++ *= 2.0F;
    *center_axis *= 2.0F;
    ball_radius = njScalor(&center);
    /* @hack spelling: pos added to center through byte cursors; through the
     * members, the function runs 6 bytes long and 267 of 482 words
     * differ */
    center_byte = (char *)&center;
    pos_byte = (char *)&pos;
    *(Float *)center_byte += *(Float *)pos_byte;
    center_byte += sizeof(Float);
    pos_byte += sizeof(Float);
    *(Float *)center_byte += *(Float *)pos_byte;
    center_byte += sizeof(Float);
    pos_byte += sizeof(Float);
    *(Float *)center_byte += *(Float *)pos_byte;
    cx = center.x;
    cy = center.y;
    cz = center.z;
    source = SOURCE(work);
    drag = source->motion.drag;
    lift = source->motion.lift;
    growth = source->motion.growth;
    wobble_rate = source->motion.wobble_rate;
    wobble = source->motion.wobble;

    for (bubble = BUBBLES(work)->list; bubble != NULL; bubble = next) {
        next = bubble->next;
        /* @hack spelling: the bubble's pos and speed walked as Floats, out and
         * back, for the image's @Rn+ loads and @-Rn stores; through the
         * members, 197 of 482 words differ */
        pos_axis = &bubble->pos.x;
        px = *pos_axis++;
        py = *pos_axis++;
        pz = *pos_axis;
        speed_axis = &bubble->speed.x;
        vx = *speed_axis++;
        vy = *speed_axis++;
        vz = *speed_axis;
        /* @hack spelling: py stepped first, then pz, then px, which keeps px,
         * py and pz in FR9, FR7 and FR8 (0x8c0bad66 to 0x8c0bad6e); in x, y
         * and z order, px and pz trade registers and 6 of 482 words
         * differ */
        py += vy;
        vy += lift;
        pz += vz;
        px += vx;
        vx *= drag;
        vz *= drag;
        vy *= drag;
        *speed_axis = vz;
        *--speed_axis = vy;
        *--speed_axis = vx;
        *pos_axis = pz;
        *--pos_axis = py;
        *--pos_axis = px;

        /* @hack spelling: size read ahead of the distance, which loads it into
         * FR5 at 0x8c0badce; read where radius takes it, 35 of 482 words
         * differ */
        size = bubble->size;
        /* @hack spelling: pos walked as Floats for the distance; through the
         * members, the function runs 2 bytes long and 174 of 482 words
         * differ */
        pos_axis = &bubble->pos.x;
        /* @hack spelling: cx and cy negated and added, which SHC negates once
         * ahead of the loop and keeps in the frame (FNEG at 0x8c0bad44 and
         * 0x8c0bad52); subtracted, the function runs 20 bytes short and 257
         * of 482 words differ */
        dx = -cx + *pos_axis++;
        dy = -cy + *pos_axis++;
        dz = *pos_axis - cz;
        distance2 = (dx * dx) + (dy * dy) + (dz * dz);
        radius = ball_radius + size;
        /* @hack spelling: radius squared through a local, which SHC computes
         * in FR5 (FMUL FR1,FR5 at 0x8c0badfe); in the test, the function
         * runs 2 bytes short and 159 of 482 words differ */
        radius2 = radius * radius;
        /* the ball pushes a bubble inside it out to its surface, but never
         * down */
        if (radius2 > distance2 && distance2 > 0.01F) {
            push = (radius + 0.1F) / njSqrt(distance2);
            dx *= push;
            dy *= push;
            dz *= push;
            /* @hack spelling: pos written through a Float walk, z through
             * pos_axis[1] past y; through the members, 142 of 482 words
             * differ */
            pos_axis = &bubble->pos.x;
            *pos_axis++ = cx + dx;
            if (dy >= 0.0F) {
                *pos_axis++ = cy + dy;
                *pos_axis = cz + dz;
            } else {
                pos_axis[1] = cz + dz;
            }
        }

        y = bubble->pos.y;
        limit = bubble->max_size;
        grown = bubble->size + growth;
        if (grown > limit) {
            grown = limit;
        }
        /* @hack spelling: the surface through a local, read once
         * (0x8c0bae6a), which keeps px in FR9, py in FR7, and cx and cy in
         * their frame slots. read twice, px and py trade registers, two
         * frame slots trade places, and 12 of 482 words differ */
        surface = bubble->surface;
        room = surface - grown - y;
        if (y >= surface) {
            bubble_free(work, bubble);
        } else {
            if (room < 0.0F) {
                grown += room;
            }
            bubble->size = grown;
        }

        /* @bug memory: a bubble that bursts is freed above (BSR to
         * bubble_free at 0x8c0bae7c), and its angle is still written here
         * (0x8c0baee4). its speed is too when the wobble's roll passes
         * (0x8c0baec2, 0x8c0baeda) */
        if (rand() * RAND_SCALE < wobble_rate) {
            /* @hack spelling: speed stepped to y and indexed on to z through a
             * Float walk; through the members, 203 of 482 words differ */
            speed_axis = &bubble->speed.x;
#ifdef GCC
            /* the step follows the +=, which tools/floats.py then writes as
             * an addition, so that GCC fuses the product as SHC does */
            *speed_axis += ((rand() * RAND_SCALE) - 0.5F) * wobble;
            speed_axis++;
#else
            *speed_axis++ += ((rand() * RAND_SCALE) - 0.5F) * wobble;
#endif
            speed_axis[1] += ((rand() * RAND_SCALE) - 0.5F) * wobble;
        }
        bubble->ang += bubble->spin;
    }
    work->timer++;
}

void bubbles_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct bubble *bubble;
    NJS_SPRITE sprite;

    if (loop_count > 0) {
        return;
    }
    sprite.tlist = &eff_regular_texlist;
    sprite.tanim = &bubble_texanim;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    for (bubble = BUBBLES(work)->list; bubble != NULL; bubble = bubble->next) {
        sprite.ang = bubble->ang;
        sprite.p = bubble->pos;
        sprite.sx = bubble->size;
        sprite.sy = bubble->size * bubble->aspect;
        sprite_draw_3d(&sprite, 0,
                       NJD_SPRITE_ANGLE | NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
    }
}

void FUN_8c0b3ee6(struct task *task)
{
    ball_jitter_place(task->work);
    task->step = ball_jitter_step;
    task->draw = ball_jitter_draw;
    ball_jitter_draw(task);
}

void FUN_8c0b3f00(struct task *task)
{
    ball_follow_place(task->work);
    task->step = ball_follow_step;
    task->draw = ball_follow_draw;
    ball_follow_draw(task);
}

void FUN_8c0b3f1a(struct task *task)
{
    ball_shrink_place(task->work);
    task->step = ball_shrink_step;
    task->draw = ball_shrink_draw;
    ball_shrink_draw(task);
}

/* place a jitter ball as an offset from the player. it starts BALL_HEIGHT
 * up, turned as the player faces, then 0.2 to 1.2 further in a random
 * direction. TURN reads its angle twice, so each random turn draws one
 * rand for its test and another for its angle */
void ball_jitter_place(struct task_work *work)
{
    struct task_work *player = playertwp[BALL(work)->player];
    NJS_VECTOR vec;
    NJS_VECTOR offset;

    if (player != NULL) {
        vec.x = vec.z = 0.0F;
        vec.y = BALL_HEIGHT;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, player->ang.z);
        TURN(njRotateX, player->ang.x);
        TURN(njRotateY, -player->ang.y);
        njCalcVector(NULL, &vec, &work->pos);
        vec.x = vec.z = 0.0F;
        vec.y = (rand() * RAND_SCALE) + 0.2F;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, (Angle)RANDOM_ANGLE());
        TURN(njRotateX, (Angle)RANDOM_ANGLE());
        TURN(njRotateY, (Angle)RANDOM_ANGLE());
        njCalcVector(NULL, &vec, &offset);
        late_DrawObjectClipEx(2);
        njAddVector(&work->pos, &offset);
    }
    if (rand() * RAND_SCALE > 0.5F) {
        BALL(work)->texlist = &ball_textures[0];
    } else {
        BALL(work)->texlist = &ball_textures[1];
    }
}

/* place a follow ball as an offset from the player's position, which scl
 * keeps. it starts BALL_HEIGHT up, turned as the player faces, then 1 to 3
 * further in a random direction */
void ball_follow_place(struct task_work *work)
{
    struct task_work *player = playertwp[BALL(work)->player];
    NJS_VECTOR vec;
    NJS_VECTOR offset;

    if (player != NULL) {
        vec.x = vec.z = 0.0F;
        vec.y = BALL_HEIGHT;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, player->ang.z);
        TURN(njRotateX, player->ang.x);
        TURN(njRotateY, -player->ang.y);
        njCalcVector(NULL, &vec, &work->pos);
        vec.x = vec.z = 0.0F;
        vec.y = RANDOM(1.0F, 3.0F);
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, (Angle)RANDOM_ANGLE());
        TURN(njRotateX, (Angle)RANDOM_ANGLE());
        TURN(njRotateY, player->ang.y);
        njCalcVector(NULL, &vec, &offset);
        late_DrawObjectClipEx(2);
        njAddVector(&work->pos, &offset);
        work->scl = player->pos;
    }
    if (rand() * RAND_SCALE > 0.5F) {
        BALL(work)->texlist = &ball_textures[0];
    } else {
        BALL(work)->texlist = &ball_textures[1];
    }
}

/* place a shrink ball in the world, BALL_HEIGHT up from the player and
 * turned as the player faces, at three times its size */
void ball_shrink_place(struct task_work *work)
{
    struct task_work *player = playertwp[BALL(work)->player];
    NJS_VECTOR vec;

    if (player != NULL) {
        vec.x = vec.z = 0.0F;
        vec.y = BALL_HEIGHT;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, player->ang.z);
        TURN(njRotateX, player->ang.x);
        TURN(njRotateY, -player->ang.y);
        njCalcVector(NULL, &vec, &work->pos);
        njAddVector(&work->pos, &player->pos);
        late_DrawObjectClipEx(1);
    }
    if (rand() * RAND_SCALE > 0.5F) {
        BALL(work)->texlist = &ball_textures[0];
    } else {
        BALL(work)->texlist = &ball_textures[1];
    }
    work->scl.x = 3.0F;
}

/* the ball with the player, turned as it faces, tipped and squashed, and
 * fading */
void ball_jitter_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[BALL(work)->player];
    NJS_ARGB color;
    NJS_VECTOR vec;

    SaveConstantAttr();
    OnConstantAttr(0, NJD_FLAG_IGNORE_LIGHT | NJD_FLAG_USE_ALPHA);
    color.r = color.g = color.b = 0.0F;
    color.a = -(TASK_TIMER(work) * (1.0F / BALL_STEPS));
    njSetConstantMaterial(&color);
    njSetTexture_jp(BALL(work)->texlist);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x + player->pos.x, work->pos.y + player->pos.y,
                work->pos.z + player->pos.z);
    TURN(njRotateZ, player->ang.z);
    TURN(njRotateX, player->ang.x);
    TURN(njRotateY, -player->ang.y);
    vec.x = 0.0F;
    vec.y = -1.0F;
    vec.z = 0.0F;
    njTranslateV(NULL, &vec);
    njRotateZ(NULL, NJM_DEG_ANG(-45));
    vec.x = 0.7F;
    vec.y = 1.1F;
    vec.z = 0.8F;
    njScaleV(NULL, &vec);
    late_DrawObject(&sonic_ball_object);
    late_DrawObjectClipEx(1);
    color.a = 0.0F;
    njSetConstantMaterial(&color);
    LoadConstantAttr();
}

/* draw the ball for BALL_STEPS steps, then end */
void ball_jitter_step(struct task *task)
{
    struct task_work *work = task->work;

    if (TASK_TIMER(work)++ >= BALL_STEPS) {
        FreeTask(task);
        task->draw = ((void *)0);
        return;
    }
    ball_jitter_draw(task);
}

/* the ball where the player was, turned as it faced, and fading */
void ball_follow_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_ARGB color;

    SaveConstantAttr();
    OnConstantAttr(0, NJD_FLAG_IGNORE_LIGHT | NJD_FLAG_USE_ALPHA);
    color.r = color.g = color.b = 0.0F;
    color.a = -(TASK_TIMER(work) * (1.0F / BALL_STEPS));
    njSetConstantMaterial(&color);
    njSetTexture_jp(BALL(work)->texlist);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x + work->scl.x, work->pos.y + work->scl.y,
                work->pos.z + work->scl.z);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, -work->ang.y);
    late_DrawObject(&sonic_ball_object);
    late_DrawObjectClipEx(1);
    color.a = 0.0F;
    njSetConstantMaterial(&color);
    LoadConstantAttr();
}

/* draw the ball where the player was a step before, for BALL_STEPS steps,
 * then end */
void ball_follow_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[BALL(work)->player];

    if (TASK_TIMER(work)++ >= BALL_STEPS) {
        FreeTask(task);
        task->draw = ((void *)0);
        return;
    }
    ball_follow_draw(task);
    work->scl = player->pos;
    work->ang = player->ang;
}

/* the ball where it was left, at its size, and fading */
void ball_shrink_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_ARGB color;

    SaveConstantAttr();
    OnConstantAttr(0, NJD_FLAG_IGNORE_LIGHT | NJD_FLAG_USE_ALPHA);
    color.r = color.g = color.b = 0.0F;
    color.a = -(TASK_TIMER(work) * (1.0F / SHRINK_STEPS));
    njSetConstantMaterial(&color);
    njSetTexture_jp(BALL(work)->texlist);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    njScale(NULL, work->scl.x, work->scl.x, work->scl.x);
    late_DrawObject(&sonic_ball_object);
    late_DrawObjectClipEx(1);
    color.a = 0.0F;
    njSetConstantMaterial(&color);
    LoadConstantAttr();
}

/* draw the ball for SHRINK_STEPS steps, shrinking it after each, then end */
void ball_shrink_step(struct task *task)
{
    struct task_work *work = task->work;

    if (TASK_TIMER(work)++ >= SHRINK_STEPS) {
        FreeTask(task);
        task->draw = ((void *)0);
        return;
    }
    ball_shrink_draw(task);
    work->scl.x -= 0.4F;
}

/* set ang[1] and ang[2] to the angles about y and z that turn the x axis
 * toward vector, and clear ang[0]. a vector of no length leaves them */
/* @hack type: ang an Angle *, which callers point at a struct angles' x and
 * which reaches its other members by index, as ISO C leaves undefined.
 * dash_step then keeps &aim.x in R12 and reads aim through it (0x8c0bbdde,
 * 0x8c0bbdf2). as a struct angles *, SHC builds the address in R5, and 61
 * of 412 words differ, all of them dash_step's */
void dash_angles(NJS_VECTOR *vector, Angle *ang)
{
    Float length = njScalor(vector);

    if (length != 0.0F) {
        ang[1] = (Angle)(njArcTan2(-vector->z, vector->x) * ANGLE_PER_RADIAN);
        ang[2] = (Angle)(asinf(vector->y / length) * ANGLE_PER_RADIAN);
        ang[0] = 0;
    }
}

void EffectDash(struct task *task)
{
    if (dash_alloc(task->work) == TRUE) {
        task->step = FUN_8c0b4a60;
        task->draw = dash_draw;
        task->destructor = dash_destroy;
    } else {
        FreeTask(task);
    }
}

/* copy the streak, its model and its points onto the heap, with the copy's
 * object in the dash's vars. start the dash at the player's middle. FALSE if
 * the heap has no room, with none of the copy left allocated */
Bool dash_alloc(struct task_work *work)
{
    NJS_OBJECT *object = &sonic_dash_object;
    Uint32 count = object->model->nbPoint;
    NJS_OBJECT *copy;
    NJS_POINT3 *to;
    NJS_POINT3 *from;
    Uint32 i;
    struct task_work *player;
    struct collision_shape *shape;

    copy = MAlloc(sizeof(NJS_OBJECT));
    /* @hack spelling: an else that returns FALSE, not an early return, which
     * puts the model copy's source in R2 and its destination in R3
     * (0x8c0bb960, 0x8c0bb962); with an early return, the two trade and 22
     * of 144 words differ */
    if (copy != NULL) {
        *copy = *object;
        DASH(work)->object = copy;
    } else {
        return FALSE;
    }
    if ((copy->model = MAlloc(sizeof(NJS_MODEL))) != NULL) {
        *copy->model = *object->model;
    } else {
        Free(copy);
        return FALSE;
    }
    if ((copy->model->points = MAlloc(count * sizeof(NJS_POINT3))) != NULL) {
        to = copy->model->points;
        from = object->model->points;
        for (i = 0; i < count; i++) {
            VECTOR_COPY(to, from);
            to++;
            from++;
        }
    } else {
        Free(copy->model);
        Free(copy);
        return FALSE;
    }
    player = playertwp[DASH(work)->player];
    if (player != NULL) {
        shape = player->collision->shapes;
        work->pos = shape->center;
    }
    return TRUE;
}

/* the streak, its first step as the model has it, and its copy after */
void dash_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = DASH(work)->object;

    if (work->flags & DASH_SECOND_SET) {
        njSetTexture_jp(&dash_textures_b[TASK_TIMER(work) - 1]);
    } else {
        njSetTexture_jp(&dash_textures[TASK_TIMER(work) - 1]);
    }
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateZ, work->ang.z);
    njScaleV(NULL, &work->scl);
    if (TASK_TIMER(work) == 1) {
        late_DrawObject(&sonic_dash_object);
    } else {
        late_DrawObject(object);
    }
    late_DrawObjectClipEx(1);
}

/* draw the dash for DASH_STEPS steps, or with the second set until step
 * SECOND_SET_END. the first step stretches the streak from the player's
 * middle back to where the dash started. it takes the second set if the
 * record's own.sonic.dashes shows a dash two steps back but none one step
 * back. the second step turns the copy's end at x 0, its odd points, to
 * dash_matrix */
void FUN_8c0b4a60(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = DASH(work)->object;
    NJS_VECTOR vec;
    NJS_VECTOR offset;
    struct angles aim;

    /* @hack redundant: the second test an else after the first's return, which
     * loads its SECOND_SET_END into R2 (0x8c0bbb88); without the else, R3,
     * and 2 of 370 words differ */
    if (TASK_TIMER(work)++ >= DASH_STEPS) {
        FreeTask(task);
        task->draw = ((void *)0);
        return;
    } else if ((work->flags & DASH_SECOND_SET) &&
               TASK_TIMER(work) >= SECOND_SET_END) {
        FreeTask(task);
        task->draw = ((void *)0);
        return;
    }
    if (TASK_TIMER(work) == 1) {
        struct task_work *player = playertwp[DASH(work)->player];
        struct player *record;

        if (player != NULL) {
            vec.x = vec.z = 0.0F;
            vec.y = GetPlayerWorkPointer(DASH(work)->player)->consts.center_y;
            njPushMatrix(&nj_unit_matrix_);
            TURN(njRotateZ, player->ang.z);
            TURN(njRotateX, player->ang.x);
            TURN(njRotateY, -player->ang.y);
            njCalcVector(NULL, &vec, &offset);
            late_DrawObjectClipEx(1);
            njAddVector(&offset, &player->pos);
            vec = work->pos;
            work->pos = offset;
            njSubVector(&vec, &offset);
            dash_angles(&vec, &work->ang.x);
            work->scl.x = njScalor(&vec) * (1.0F / STREAK_LENGTH);
            work->scl.y = 1.0F;
            work->scl.z = 1.0F;
            record = playermwp[DASH(work)->player]->record;
            if ((record->own.sonic.dashes[0] & 4) &&
                !(record->own.sonic.dashes[0] & 2)) {
                work->flags |= DASH_SECOND_SET;
            }
        }
    } else if (TASK_TIMER(work) == 2) {
        struct task_work *player = playertwp[DASH(work)->player];
        /* @hack spelling: the streak read through original, which loads its
         * address into R4 and its model through it (0x8c0bbd3c, 0x8c0bbd40).
         * read as sonic_dash_object, the pool holds its model field's address,
         * and 6 of 370 words differ */
        NJS_OBJECT *original;
        NJS_POINT3 *point;
        Uint32 count;
        Uint32 i;

        if (player != NULL) {
            original = &sonic_dash_object;
            point = object->model->points;
            count = original->model->nbPoint;
            vec.x = vec.z = 0.0F;
            vec.y = GetPlayerWorkPointer(DASH(work)->player)->consts.center_y;
            njPushMatrix(&nj_unit_matrix_);
            TURN(njRotateZ, player->ang.z);
            TURN(njRotateX, player->ang.x);
            TURN(njRotateY, -player->ang.y);
            njCalcVector(NULL, &vec, &offset);
            late_DrawObjectClipEx(1);
            njAddVector(&offset, &player->pos);
            vec = work->pos;
            njSubVector(&vec, &offset);
            if (njScalor(&vec) != 0.0F) {
                dash_angles(&vec, &aim.x);
                njUnitMatrix(&dash_matrix);
                TURN_MATRIX(njRotateY, &dash_matrix, aim.y);
                TURN_MATRIX(njRotateZ, &dash_matrix, aim.z);
                njScaleV(&dash_matrix, &work->scl);
                njPushMatrix(&nj_unit_matrix_);
                TURN(njRotateY, work->ang.y);
                TURN(njRotateZ, work->ang.z);
                njScaleV(NULL, &work->scl);
                njInvertMatrix(NULL);
                njMultiMatrix(NULL, &dash_matrix);
                for (i = 0, point++; i < count; i += 2, point += 2) {
                    vec = *point;
                    njCalcPoint(NULL, &vec, point);
                }
                late_DrawObjectClipEx(1);
            }
        }
    }
    dash_draw(task);
}

/* free the dash's copy: its points, its model and its object. the model and the
 * object are each read through before their NULL tests. no test can fail:
 * dash_start sets this destructor only once dash_alloc has the whole copy */
void dash_destroy(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = DASH(work)->object;

    if (object->model->points != NULL) {
        Free(object->model->points);
    }
    if (object->model != NULL) {
        Free(object->model);
    }
    if (object != NULL) {
        Free(object);
    }
}

/* while the record blends, the aura draws the blend in place of the action. its
 * first color's green falls from 0.28 to 0.1 and rises back over each 128 steps
 * of play time */
void SonicChargeBodyDisplay(struct task_work *work, struct task_motion *motion,
                            struct player *record)
{
    NJS_ACTION action;
    NJS_ARGB color;
    int index;
    extern int time_steps;
    Float phase;
    /* @hack spelling: the scale through three locals, which SHC copies
     * from FR15 to FR6 first (0x8c0bc05c, 0x8c0bc08c); passed as constants,
     * FR4 comes first and 4 of 157 words differ */
    Float sx;
    Float sy;
    Float sz;

    if (loop_count != 0) {
        return;
    }
    action.object = &sonic_aura_object;
    index = record->anim.action;
    /* @hack redundant: index picked while the record blends, where nothing
     * reads it (0x8c0bbf8e, 0x8c0bbf90); without it, 135 of 157 words differ */
    if (record->anim.state == PLAYER_ANIM_BLENDING) {
        index = record->anim.current;
    }
    njPushMatrix(NULL);
    if (record->anim.state != PLAYER_ANIM_BLENDING) {
        action.motion = record->anim.actions[index].action->motion;
    } else {
        action.motion = record->anim.blend->motion;
    }
    phase = (Float)(time_steps & 0x7f);
    if (phase >= 64.0F) {
        phase = 128.0F - phase;
    }
    phase *= 1.0F / 64.0F;
    color.r = 0.0F;
    color.g = 0.28F - (phase * 0.18F);
    color.b = 1.0F;
    color.a = 0.0F;
    njSetConstantMaterial(&color);
    FUN_8c60e3da(&action, record->anim.frame);
    color.r = 0.05F;
    /* @hack spelling: green less 0.15 as -0.15 added, FADD at 0x8c0bc04e; with
     * -=, SHC subtracts, and 1 of 157 words differ */
    color.g += -0.15F;
    njSetConstantMaterial(&color);
    sx = 1.05F;
    sy = 1.05F;
    sz = 1.05F;
    njScale(((void *)0), sx, sy, sz);
    FUN_8c60e3da(&action, record->anim.frame);
    color.g -= 0.05F;
    color.b = 0.3F;
    njSetConstantMaterial(&color);
    sx = 1.05F;
    sy = 1.05F;
    sz = 1.05F;
    njScale(((void *)0), sx, sy, sz);
    FUN_8c60e3da(&action, record->anim.frame);
    color.b = color.g = color.r = 0.0F;
    njSetConstantMaterial(&color);
    late_DrawObjectClipEx(1);
}

/* draw the strip, once it has a triangle, in the look work->tick picks.
 * it draws only on a frame's first step */
void trail_draw(struct task *task)
{
    /* @hack redundant: work set and never read, which keeps task in R12 for
     * the texture's lookup (0x8c0bc128, 0x8c0bc14a); without it, task waits
     * at @R15, the function runs 4 bytes long and 49 of 50 words differ */
    struct task_work *work = task->work;
    NJS_POINT3COL *strip = STRIP(task);

    if (strip->num >= 3 && loop_count == 0) {
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        njSetTexture_jp(&trail_textures[task->work->tick]);
        njSetTextureNum_jp(0);
        njDrawTriangle3D(strip, strip->num - 2,
                         NJD_USE_TEXTURE | NJD_TRANSPARENT | NJD_FILL |
                             NJD_DRAW_CONNECTED);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                               NJD_COLOR_BLENDING_BOTHSRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_BOTHSRCALPHA);
    }
}

/* add up to steps points toward the target in scl, each a share of the
 * way left. it stops when the strip is full or a step falls to TRAIL_STOP.
 * the points fall on alternate sides of the trail's line, which rolls as
 * it goes */
void trail_extend(struct task_work *work, NJS_POINT3COL *strip, int steps)
{
    NJS_POINT3 *points;
    NJS_COLOR *colors;
    NJS_COLOR *uvs;
    int i;
    int j;
    int count;
    Float side;
    Float step;
    Angle pitch;
    Angle yaw;
    NJS_VECTOR vec;
    NJS_POINT3 point;

    points = strip->p;
    colors = strip->col;
    uvs = strip->tex;
    i = strip->num;
    count = TRAIL(work)->count;
    if (i == count) {
        return;
    }
    side = (i & 1) ? 0.4F : -0.4F;
    for (j = 0; j < steps; j++) {
        vec.x = work->scl.x - work->pos.x;
        vec.y = work->scl.y - work->pos.y;
        vec.z = work->scl.z - work->pos.z;
        step = njScalor(&vec) / (steps - j);
        if (step <= TRAIL_STOP) {
            return;
        }
        pitch = -(Angle)(asinf(vec.y / step) * ANGLE_PER_RADIAN);
        yaw = (Angle)(njArcTan2(vec.x, vec.z) * ANGLE_PER_RADIAN);
        work->ang.x = pitch;
        work->ang.y = yaw;
        work->ang.z += 0x180;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateY, work->ang.y);
        TURN(njRotateX, work->ang.x);
        TURN(njRotateZ, work->ang.z);
        vec.x = 0.0F;
        vec.y = 0.0F;
        vec.z = step;
        njCalcPoint(NULL, &vec, &point);
        work->pos.x += point.x;
        work->pos.y += point.y;
        work->pos.z += point.z;
        vec.x = side;
        vec.y = 0.0F;
        vec.z = step;
        njCalcPoint(NULL, &vec, &point);
        point.x += work->pos.x;
        point.y += work->pos.y;
        point.z += work->pos.z;
        points[i].x = point.x;
        points[i].y = point.y;
        points[i].z = point.z;
        side = -side;
        late_DrawObjectClipEx(1);
        colors[i].color = TRAIL(work)->color.color;
        /* u runs along the trail: 0 at its first two points and 255 at its last
         * two. between them, u is 112 for a pair of points, then 144 for a
         * pair, in turn. v crosses the trail: 0 at an even point and 255 at an
         * odd one, but the last two take 0 then 255 */
        if (i == 1) {
            uvs[i].tex.u = 0;
            uvs[i].tex.v = 255;
        } else if (i == count - 1) {
            uvs[i].tex.u = 255;
            uvs[i].tex.v = 255;
        } else if (i == count - 2) {
            uvs[i].tex.u = 255;
            uvs[i].tex.v = 0;
        } else if (i % 4 == 2) {
            uvs[i].tex.u = 112;
            uvs[i].tex.v = 0;
        } else if (i % 4 == 3) {
            uvs[i].tex.u = 112;
            uvs[i].tex.v = 255;
        } else if (i % 4 == 0) {
            uvs[i].tex.u = 144;
            uvs[i].tex.v = 0;
        } else {
            uvs[i].tex.u = 144;
            uvs[i].tex.v = 255;
        }
        strip->num = ++i;
        if (i >= count) {
            break;
        }
    }
}

/* free the strip's points, colors and uvs. the arm that frees tex sets col to
 * NULL, not tex, so tex keeps its freed address */
void trail_destroy(struct task *task)
{
    NJS_POINT3COL *strip;

    strip = STRIP(task);
    if (strip->p != NULL) {
        Free(strip->p);
        strip->p = NULL;
    }
    if (strip->col != NULL) {
        Free(strip->col);
        strip->col = NULL;
    }
    if (strip->tex != NULL) {
        Free(strip->tex);
        strip->col = NULL;
    }
}

/* fade each point until none is left to fade, then end */
void trail_fade(struct task *task)
{
    /* NOLINTNEXTLINE(clang-diagnostic-unused-but-set-variable) */
    struct task_work *work;
    NJS_POINT3COL *strip;
    NJS_COLOR *color;
    int i;
    Bool fading;

    /* @hack redundant: work set and never read, which leaves fading in R5
     * and the constant 1 in R7 (0x8c0bc512, 0x8c0bc534); without it, the
     * two trade registers and 5 of 40 words differ */
    work = task->work;
    strip = STRIP(task);
    color = strip->col;
    trail_draw(task);
    fading = FALSE;
    for (i = strip->num; i > 0; i--) {
        if (color->argb.a > 8) {
            color->argb.a -= 5;
            fading = TRUE;
        }
        color++;
    }
    if (!fading) {
        FreeTask(task);
        task->draw = ((void *)0);
    }
}

/* add a point toward what the trail follows, and fade once a step adds
 * none or the strip is full */
void trail_step(struct task *task)
{
    struct task_work *work;
    NJS_POINT3COL *strip;
    Uint32 last;
    /* @hack spelling: the target through a local, which SHC copies through
     * R4 (0x8c0bc562 to 0x8c0bc570); read in place, through R3 and R2, and 9
     * of 38 words differ */
    NJS_POINT3 *follow;

    work = task->work;
    strip = STRIP(task);
    follow = TRAIL(work)->follow;
    work->scl = *follow;
    last = strip->num;
    trail_extend(work, strip, 1);
    trail_draw(task);
    if (strip->num == last || strip->num >= TRAIL(work)->count) {
        task->step = trail_fade;
    }
}

/* make the strip with room for count points: the first at work->pos, and
 * two more toward what the trail follows. the task ends if the heap has no
 * room, or if the strip has fewer than three points or no room for more */
void FUN_8c0b5460(struct task *task)
{
    struct task_work *work;
    NJS_POINT3COL *strip;
    NJS_POINT3 *points;
    NJS_COLOR *colors;
    NJS_COLOR *uvs;
    int count;
    int size;
    NJS_POINT3 *follow;
    NJS_VECTOR vec;

    /* @hack redundant: count's and size's addresses taken and dropped, which
     * keeps each in a frame slot of its own, count at @R15 and size at
     * @(4,R15) (0x8c0bc5ce, 0x8c0bc5e4); without them, count takes R8, the
     * frame shrinks from 28 bytes to 24 and 45 of 185 words differ */
    (void)&size;
    (void)&count;
    work = task->work;
    if ((task->motion = MAlloc(sizeof(NJS_POINT3COL))) != NULL) {
        strip = STRIP(task);
        count = TRAIL(work)->count;
        if ((points = MAlloc(count * sizeof(NJS_POINT3))) == NULL) {
            FreeTask(task);
            return;
        }
        size = count * sizeof(NJS_COLOR);
        if ((colors = MAlloc(size)) == NULL) {
            Free(points);
            FreeTask(task);
            return;
        }
        if ((uvs = MAlloc(size)) == NULL) {
            Free(colors);
            Free(points);
            FreeTask(task);
            return;
        }
        strip->p = points;
        strip->col = colors;
        strip->tex = uvs;
        strip->num = 1;
        VECTOR_COPY(&points[0], &work->pos);
        colors[0].color = TRAIL(work)->color.color;
        uvs[0].tex.u = 0;
        uvs[0].tex.v = 0;
        follow = TRAIL(work)->follow;
        work->scl = *follow;
        vec.x = work->scl.x - work->pos.x;
        vec.y = work->scl.y - work->pos.y;
        vec.z = work->scl.z - work->pos.z;
        work->ang.x = (Angle)(njArcTan2(vec.y, njSqrt((vec.x * vec.x) +
                                                      (vec.z * vec.z))) *
                              ANGLE_PER_RADIAN);
        work->ang.y = (Angle)(njArcTan2(vec.x, vec.z) * ANGLE_PER_RADIAN);
        trail_extend(work, strip, 2);
        task->step = trail_step;
        task->draw = trail_draw;
        task->destructor = trail_destroy;
        if (strip->num < 3 || strip->num >= TRAIL(work)->count) {
            FreeTask(task);
            return;
        }
        trail_draw(task);
    } else {
        FreeTask(task);
    }
}

void trail_create(NJS_POINT3 *follow, int count)
{
    struct task *task;
    if ((task = CreateElementalTask(0x2, 3, FUN_8c0b5460)) != ((void *)0)) {
        ((struct trail_vars *)&(task->work)->vars)->follow = follow;
        ((struct trail_vars *)&(task->work)->vars)->count = count;
        ((struct trail_vars *)&(task->work)->vars)->color.color = 0xffffffff;
        task->work->pos = *follow;
    }
}

/* fly on at its speed, which it keeps in scl, until its count runs out */
void charge_spark_step(struct task *task)
{
    struct task_work *work;

    work = task->work;
    if (SPARK(work)->count-- <= 0) {
        FreeTask(task);
        return;
    }
    VECTOR_ADD(&work->pos, &work->scl);
}

void charge_spark_create(struct task_work *work, int count)
{
    struct task *spark;
    struct task *trail;

    if ((spark = CreateElementalTask(TASK_WORK, 2, charge_spark_step)) !=
        NULL) {
        spark->work->pos = work->pos;
        SPARK(spark->work)->count = count;
        spark->work->scl.x = ((rand() * RAND_SCALE) - 0.5F) * SPARK_SPREAD;
        spark->work->scl.y = ((rand() * RAND_SCALE) - 0.5F) * SPARK_SPREAD;
        spark->work->scl.z = ((rand() * RAND_SCALE) - 0.5F) * SPARK_SPREAD;
    } else {
        /* @hack spelling: an else that returns, not an early return, which
         * loads task_create's address below into R2 (0x8c0bc87c); with an early
         * return, R3, the function runs 2 bytes long and 80 of 151 words
         * differ */
        return;
    }
    if ((trail = CreateElementalTask(0x2, 3, FUN_8c0b5460)) != ((void *)0)) {
        ((struct trail_vars *)&(trail->work)->vars)->follow = &spark->work->pos;
        ((struct trail_vars *)&(trail->work)->vars)->count = count;
        ((struct trail_vars *)&(trail->work)->vars)->color.argb.b =
            ((rand() * (((254.0F) - (127.0F)) * (1.0F / (32767 + 1)))) +
             (127.0F));
        ((struct trail_vars *)&(trail->work)->vars)->color.argb.g =
            ((rand() * (((254.0F) - (127.0F)) * (1.0F / (32767 + 1)))) +
             (127.0F));
        ((struct trail_vars *)&(trail->work)->vars)->color.argb.r =
            ((rand() * (((254.0F) - (127.0F)) * (1.0F / (32767 + 1)))) +
             (127.0F));
        ((struct trail_vars *)&(trail->work)->vars)->color.argb.a = -1;
        trail->work->pos = spark->work->pos;
    } else {
        FreeTask(spark);
    }
}

/* the light, facing the camera and shrinking as its time runs out */
void charge_draw(struct task *task)
{
    struct task_work *work;
    Float scale;

    work = task->work;
    if (loop_count == 0) {
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        scale = CHARGE(work)->timer * (1.0F / 32.0F);
        TURN(njRotateY, camera_twp->ang.y);
        TURN(njRotateX, camera_twp->ang.x);
        njScale(NULL, scale, scale, scale);
        njFogDisable();
        njDrawSprite3D(&charge_sprites[work->tick], 0, NJD_SPRITE_ALPHA);
        njFogEnable();
        late_DrawObjectClipEx(1);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_INVSRCALPHA);
    }
}

/* turn toward the player's middle, which scl keeps, and fly at it until
 * the time runs out. a step flies at most CHARGE_SPEED */
void EffectSpinRibbon(struct task *task)
{
    struct task_work *work;
    struct task_work *player;
    Angle pitch;
    Angle yaw;
    NJS_VECTOR delta;
    NJS_POINT3 step;
    Float distance;

    work = task->work;
    if (CHARGE(work)->timer-- > 0) {
        player = playertwp[CHARGE(work)->player];
        if (player != NULL) {
            work->scl = player->collision->shapes->center;
        }
        delta.x = work->scl.x - work->pos.x;
        delta.y = work->scl.y - work->pos.y;
        delta.z = work->scl.z - work->pos.z;
        distance = njScalor(&delta);
        if (distance == 0.0F) {
            return;
        }
        pitch = -(Angle)(asinf(delta.y / distance) * ANGLE_PER_RADIAN);
        yaw = (Angle)(njArcTan2(delta.x, delta.z) * ANGLE_PER_RADIAN);
        work->ang.x = AdjustAngle(work->ang.x, pitch, 0x400);
        work->ang.y = AdjustAngle(work->ang.y, yaw, 0x700);
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateY, work->ang.y);
        TURN(njRotateX, work->ang.x);
        if (distance > CHARGE_SPEED) {
            distance = CHARGE_SPEED;
        }
        delta.x = 0.0F;
        delta.y = 0.0F;
        delta.z = distance;
        njCalcPoint(NULL, &delta, &step);
        work->pos.x += step.x;
        work->pos.y += step.y;
        work->pos.z += step.z;
        late_DrawObjectClipEx(1);
        charge_draw(task);
        EntryColliList(work);
    } else {
        FreeTask(task);
    }
}

/* the light starts at a random heading, pitched between 11.25 degrees below
 * level and about 56 above. the crystal ring picks its look and its trail's */
void CreateEffectSpinRibbon(struct task_work *work, int count)
{
    struct player *record;
    int look;
    struct task *charge;
    struct task *trail;
    struct task_work *light;
    struct task_work *trail_work;
    NJS_POINT3 *center;
    Float distance;
    /* @hack type: pitch and yaw Floats, though each holds an Angle, which
     * SHC converts to a float and back for njSin and njCos (0x8c0bccd8,
     * 0x8c0bccf4, 0x8c0bcd08); as Angles, the function runs 32 bytes short
     * and 132 of 185 words differ */
    Float pitch;
    Float yaw;

    record = GetPlayerWorkPointer(PLAYER_VARS(work)->player);
    if (record != NULL && (record->upgrades & PLAYER_SONIC_CRYSTAL_RING)) {
        look = 1;
    } else {
        look = 0;
    }
    if ((charge = CreateElementalTask(TASK_WORK, 2, EffectSpinRibbon)) !=
        NULL) {
        center = &work->collision->shapes->center;
        light = charge->work;
        CHARGE(light)->player = PLAYER_VARS(work)->player;
        light->scl = *center;
        distance = RANDOM(25.0F, 40.0F);
        pitch = (Angle)(rand() * 0.375F) - NJM_DEG_ANG(11.25);
        yaw = (Angle)RANDOM_ANGLE();
        light->pos.x = center->x + (distance * njSin(yaw) * njCos(pitch));
        light->pos.z = center->z + (distance * njCos(yaw) * njCos(pitch));
        light->pos.y = center->y + (distance * njSin(pitch));
        light->ang.y = NJM_DEG_ANG(180) - work->ang.y;
        CHARGE(light)->timer = count + 1;
        light->tick = look;
    } else {
        /* @hack spelling: an else that returns, not an early return, which
         * loads task_create's address below into R2 (0x8c0bcd50); with an early
         * return, R3, and 19 of 185 words differ */
        return;
    }
    if ((trail = CreateElementalTask(0x2, 3, FUN_8c0b5460)) != ((void *)0)) {
        trail_work = trail->work;
        TRAIL(trail_work)->follow = &charge->work->pos;
        TRAIL(trail_work)->count = count;
        TRAIL(trail_work)->color.color = 0xffffffff;
        trail_work->pos = charge->work->pos;
        trail_work->tick = look;
    } else {
        FreeTask(charge);
        return;
    }
    CCL_Init(charge, &charge_shape, COLLISION_ATTACK, 1, 1);
    charge->draw = charge_draw;
}

void ice_draw(struct task *task)
{
    struct task_work *work;

    work = task->work;
    njSetTexture_jp(ICE(work)->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njScaleV(NULL, &work->scl);
    late_DrawObject(ICE(work)->object);
    late_DrawObjectClipEx(1);
}

void ice_destroy(struct task *task)
{
}

/* fly out along its heading and fall, tumbling. scl.y holds the piece's
 * upward speed, so ice_draw scales the piece by it too */
void ice_piece_step(struct task *task)
{
    struct task_work *work;

    work = task->work;
    if (CheckRangeOut(task)) {
        return;
    }
    work->pos.x += njSin(work->ang.y) * 2.0F;
    work->pos.z += njCos(work->ang.y) * 2.0F;
    work->pos.y += work->scl.y;
    work->scl.y -= 0.1F;
    if (work->scl.y < -6.0F) {
        work->scl.y = -6.0F;
    }
    work->ang.x += 0x100;
    ice_draw(task);
}

/* a piece at a random size and turn */
void ice_piece_start(struct task *task)
{
    struct task_work *work;
    Float random;

    work = task->work;
    GetPlayerWorkPointer(work->tick);
    random = rand() * RAND_SCALE;
    work->scl.x = random + 0.5F;
    work->ang.x = (Angle)(random * 65536.0F);
    random = rand() * RAND_SCALE;
    work->scl.z = random + 0.5F;
    work->ang.z = (Angle)(random * 65536.0F);
    task->draw = ice_draw;
    task->step = ice_piece_step;
    task->destructor = ice_destroy;
    ICE(work)->object = &sonic_ice_piece_object;
    ICE(work)->texlist = &sonic_ice_texlist;
}

/* the pieces fly off at random headings, rising up to 2 a step */
void ice_break(struct task_work *work)
{
    struct task *piece;
    int i;

    for (i = 0; i < ICE_PIECES; i++) {
        piece = CreateElementalTask(TASK_WORK, 6, ice_piece_start);
        piece->work->pos = work->pos;
        piece->work->ang.y = (Angle)RANDOM_ANGLE();
        piece->work->scl.y = rand() * (2.0F * RAND_SCALE);
        piece->work->tick = work->tick;
    }
}

/* stay at the player's middle until its action changes, then break */
void ice_step(struct task *task)
{
    struct task_work *work;
    Uint8 player;
    struct player *record;

    work = task->work;
    player = work->tick;
    record = GetPlayerWorkPointer(player);
    if (record->anim.action != TASK_TIMER(work)) {
        ice_break(work);
        FreeTask(task);
        return;
    }
    work->pos = playertwp[player]->collision->shapes->center;
    ice_draw(task);
}

/* the ice's first step. it keeps the player's action in work->timer, and
 * ice_step breaks the ice once the action changes */
void ice_start(struct task *task)
{
    struct task_work *work;
    struct player *record;

    work = task->work;
    record = GetPlayerWorkPointer(work->tick);
    work->timer = record->anim.action;
    work->scl.x = work->scl.y = work->scl.z = 1.0F;
    task->draw = ice_draw;
    task->step = ice_step;
    task->destructor = ice_destroy;
    ICE(work)->object = &sonic_ice_object;
    ICE(work)->texlist = &sonic_ice_texlist;
}

void ice_create(int player)
{
    struct task *task;

    if ((task = CreateElementalTask(TASK_WORK, 3, ice_start)) != NULL) {
        task->work->tick = player;
    }
}
