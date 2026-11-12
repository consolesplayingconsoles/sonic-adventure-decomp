/* @unit 8C065740-8C066260 @data 8C154FD8-8C154FFC +egflags +pool32 */
/* springs: a touch launches a player along the spring's y axis, and the
 * spring bobs after. spring b also takes the player's control away for the
 * steps its scl.x gives */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/models.h"
#include "object/placement.h"
#include "object/spring.h"
#include "player/player.h"
#include "sound/sound.h"
#include "system/cache.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
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
struct player *GetPlayerWorkPointer(Uint8 player);
int GetTheNearestPlayerNumber(NJS_POINT3 *pos);
Bool CheckPlayerRideOnMobileLandObjectP(Uint8 player, struct task *task);
void SetLookingTaskP(Uint8 player, struct task *task, NJS_POINT3 *offset);
void SetLookingPointP(Uint8 player, NJS_POINT3 *pos);
void CancelLookingAtP(Uint8 player);
void HoldOnPillarP(Uint8 player, NJS_POINT3 *pos, Uint32 steps);
void KeepPlayersEyesOnThePointP(Uint8 player, struct angles *ang, Uint32 steps);
void FUN_8c07c6a8(Uint8 player, const Angle *ang, Float speed, Sint16 steps);
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
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
void *syMalloc_default_malloc(size_t size);
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
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);
void VibShot(int pad, int power, int freq, int time);

/* the coil's stretch at a launch, as its scale less 1 */
#define LAUNCH_STRETCH 0.1F
/* a launch's speed, before ADD_YSPD adds to it */
#define LAUNCH_SPEED 5.0F

/* a player on the ground running ahead at RUN_SPEED or more is set on the
 * spring's top before its launch. a slower one between PULL and PULL_RANGE
 * across from the top is pulled PULL toward it */
#define RUN_SPEED 1.0F
#define PULL 2.0F
#define PULL_RANGE 14.0F

/* a spring takes a touch once work->tick passes TOUCH_WAIT. a launch sets
 * the plain spring's tick to 0, and spring b's to B_LAUNCH_TICK. so the
 * plain spring takes another touch 11 steps after a launch, and spring b 6
 * steps after one */
#define TOUCH_WAIT 10
#define B_LAUNCH_TICK 5
/* work->tick counts up to TICK_LIMIT and stays there */
#define TICK_LIMIT 50

/* a spring's bytes in work->vars. work->submode holds the player it
 * launches, and work->tick counts the steps since its last launch */
#define VARS(work) ((struct spring_vars *)&(work)->vars)
#define PHASE(work) ((work)->scl.x)
#define NO_TIMER(work) ((work)->scl.x)
#define ADD_YSPD(work) ((work)->scl.y)
#define PHASE_SPEED(work) ((work)->scl.z) /* the bob's degrees a step */
struct spring_vars {
    /* the coil's scale less 1: LAUNCH_STRETCH at a launch, then between
     * -0.6 and 0 as it bobs */
    Float stretch;
    Float phase_b; /* spring b's bob phase, in degrees */
    Float bob; /* the bob's size, which shrinks as the phase runs on */
};

/* the plain spring's bob phase, in degrees. spring b keeps its own in
 * phase_b, since its scl.x is NO_TIMER */
/* spring b's steps out of the player's control after a launch, labeled NO
 * TIMER in the set editor */
/* the speed a launch adds to LAUNCH_SPEED, labeled ADD YSPD in the set
 * editor */

/* a spring's modes, in work->mode */
enum spring_mode { SPRING_INIT, SPRING_WAIT, SPRING_LAUNCH, SPRING_KILL };

static void VacumePlayer(struct task *task, Uint8 along_angles);
static void spring_destroy(struct task *task);
static void spring_draw(struct task *task);
static void spring_b_draw(struct task *task);
static void spring_b_destroy(struct task *task);
extern struct collision_shape spring_shape[1];
extern struct collision_shape spring_b_shape[1];
/* clang-format on */

/* while the set editor is open, a spring draws but neither bobs nor takes
 * a touch */
void spring_step(struct task *task)
{
    struct task_work *work = task->work;
    Uint8 i;
    struct task *player;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case SPRING_INIT:
        task->destructor = spring_destroy;
        task->draw = spring_draw;
        CCL_Init(task, spring_shape, COLLISION_OBJECT, 1, 1);
        work->collision->flags |= COLLISION_TARGET;
        PHASE(work) = 180.0F;
        PHASE_SPEED(work) = 0.0F;
        VARS(work)->bob = 0.5F;
        work->mode = SPRING_WAIT;
        break;
    case SPRING_WAIT:
        VARS(work)->stretch = -_builtin_fabsf(
            VARS(work)->bob * njSin(PHASE(work) * ANGLE_PER_DEGREE));
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "<- ADD YSPD");
        }
        if (edit_mode == 0) {
            PHASE(work) += PHASE_SPEED(work);
            if (PHASE(work) >= 290.0F &&
                PHASE(work) < 290.0F + PHASE_SPEED(work)) {
                PHASE_SPEED(work) = 18.0F;
            }
            VARS(work)->bob =
                njCos((PHASE(work) - 180.0F) * (0.1F * ANGLE_PER_DEGREE)) *
                0.6F;
            if (VARS(work)->bob < 0.0F) {
                PHASE(work) = 180.0F;
                PHASE_SPEED(work) = 0.0F;
            }
            work->tick++;
            if (work->tick > TOUCH_WAIT) {
                if (work->collision->flags & COLLISION_HIT) {
                    work->collision->flags &= ~COLLISION_HIT;
                    for (i = 0; i < 2; i++) {
                        player = GetPlayerTaskPointer(i);
                        if (work->collision->hit->owner == player) {
                            VARS(work)->stretch = LAUNCH_STRETCH;
                            work->submode = i;
                            PHASE_SPEED(work) = 20.0F;
                            PHASE(work) = 270.0F;
                            work->mode = SPRING_LAUNCH;
                            break;
                        }
                    }
                }
                if (work->mode != SPRING_LAUNCH) {
                    EntryColliList(work);
                }
            }
            if (work->tick > TICK_LIMIT) {
                work->tick = TICK_LIMIT;
            }
        }
        spring_draw(task);
        break;
    case SPRING_LAUNCH:
        dsPlay_oneshot(SE_SPRING, 0, 0, 0);
        work->tick = 0;
        VacumePlayer(task, 0);
        spring_draw(task);
        break;
    case SPRING_KILL:
        DeadOut(task);
        break;
    }
}

/* launch the player that touched the spring from the spring's top. without
 * along_angles, player_bounce sends it along the spring's y axis. with it,
 * player_launch sends it through the spring's angles, out of its control
 * for NO_TIMER steps */
static void VacumePlayer(struct task *task, Uint8 along_angles)
{
    struct task_work *work = task->work;
    struct task_work *player;
    NJS_POINT3 offset = {0.0F, LAUNCH_SPEED, 0.0F};
    NJS_POINT3 top;
    NJS_POINT3 up;
    Float speed;
    Float distance;
    Float dx;
    Float dy;
    Float dz;
    Uint8 number;

    player = playertwp[work->submode];
    offset.y = ADD_YSPD(work) + LAUNCH_SPEED;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njCalcPoint(NULL, &offset, &up);
    late_DrawObjectClipEx(1);
    top.x = work->pos.x + up.x;
    top.y = work->pos.y + up.y;
    top.z = work->pos.z + up.z;
    if (player == NULL) {
        return;
    }
    number = work->submode;
    dx = top.x - player->pos.x;
    /* @hack redundant: dy, which nothing reads, worked out in FR4 (FSUB
     * and FABS at 0x8c0692de and 0x8c0692ea); without it, 262 of 358 words
     * differ */
    /* @hack spelling: dy's fabs a statement of its own, which keeps dy in FR4;
     * as one statement, 23 of 358 words differ */
    dy = top.y - player->pos.y;
    dy = _builtin_fabsf(dy);
    dz = top.z - player->pos.z;
    distance = njSqrt((dx * dx) + (dz * dz));
    /* @bug uninitialized: player_ground_speed leaves speed unset for a
     * player off the ground, and its FALSE goes unread. the test below then
     * reads speed's frame slot unwritten (FMOV.S @(R0,R15),FR3 at
     * 0x8c069306, R0 4) */
#ifdef GCC
    /* repairs the unset speed the tag names: GCC starts it at 0, a still
     * player's speed, so the test below takes a player off the ground as
     * slow */
    speed = 0.0F;
#endif
    player_ground_speed(number, &speed);
    /* @hack spelling: RUN_SPEED > speed, which loads RUN_SPEED into FR2 and
     * speed into FR3 (FLDI1 FR2 at 0x8c069304); as speed < RUN_SPEED, the
     * two trade and 5 of 358 words differ */
    /* @hack spelling: each arm stores the mode itself, which the image does
     * twice (MOV.B R9,@R14 at 0x8c0694b2 and 0x8c069518); with one store
     * after the arms, SHC holds player_launch's address in R8 and 208 of
     * 358 words differ */
    if (RUN_SPEED > speed || VARS(work)->stretch != LAUNCH_STRETCH) {
        if (distance < PULL_RANGE && distance >= PULL) {
            SetInputP(number, PLAYER_MODE_STILL);
            player->pos.x += (dx / distance) * PULL;
            player->pos.z += (dz / distance) * PULL;
            SetInputP(number, PLAYER_MODE_RESET);
            if (!along_angles) {
                player_bounce(number, up.x, up.y, up.z);
            } else {
                /* @hack spelling: angles declared in each arm, which forms
                 * the array's address there (MOV R15,R10 and ADD #8,R10 at
                 * 0x8c069376); declared once, 254 of 358 words differ */
                Angle angles[3];

                angles[0] = work->ang.x;
                angles[1] = work->ang.y;
                angles[2] = work->ang.z;
                player->pos.x = top.x;
                player->pos.y = work->pos.y + (up.y * 0.8F);
                player->pos.z = top.z;
                if (NO_TIMER(work) <= 0.0F) {
                    NO_TIMER(work) = 0.0F;
                }
                FUN_8c07c6a8(number, angles, ((work)->scl.y) + 5.0F,
                             ((work)->scl.x));
            }
            work->mode = SPRING_WAIT;
        } else {
            if (!along_angles) {
                player_bounce(number, up.x, up.y, up.z);
            } else {
                Angle angles[3];

                angles[0] = work->ang.x;
                angles[1] = work->ang.y;
                angles[2] = work->ang.z;
                player->pos.x = top.x;
                player->pos.y = work->pos.y + (up.y * 0.8F);
                player->pos.z = top.z;
                if (NO_TIMER(work) <= 0.0F) {
                    NO_TIMER(work) = 0.0F;
                }
                FUN_8c07c6a8(number, angles, ((work)->scl.y) + 5.0F,
                             ((work)->scl.x));
            }
            work->mode = SPRING_WAIT;
        }
    } else {
        SetInputP(number, PLAYER_MODE_STILL);
        player->pos = top;
        SetInputP(number, PLAYER_MODE_RESET);
        if (!along_angles) {
            player_bounce(number, up.x, up.y, up.z);
        } else {
            Angle angles[3];

            angles[0] = work->ang.x;
            angles[1] = work->ang.y;
            angles[2] = work->ang.z;
            if (NO_TIMER(work) <= 0.0F) {
                NO_TIMER(work) = 0.0F;
            }
            FUN_8c07c6a8(number, angles, ((work)->scl.y) + 5.0F,
                         ((work)->scl.x));
        }
        work->mode = SPRING_WAIT;
    }
    VARS(work)->stretch = LAUNCH_STRETCH;
    VibShot(number, 4, 15, 0);
}

static void spring_destroy(struct task *task)
{
}

/* draw the base, the coil at its stretch, and the top on the coil */
static void spring_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;
    NJS_MODEL *model;

    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    /* @hack spelling: the base's model through a local, which loads
     * draw_model's address ahead of the model's (0x8c0695ac, 0x8c0695ae);
     * passed in place, 2 of 113 words differ */
    model = &spring_base_model;
    ds_DrawModelClip(model);
    njPushMatrix(NULL);
    object = &spring_coil_object;
    njTranslate(NULL, object->pos[0], object->pos[1], object->pos[2]);
    njScale(NULL, 1.0F, VARS(work)->stretch + 1.0F, 1.0F);
    ds_DrawModelClip(object->model);
    matrix_load_parent();
    object = &spring_top_object;
    njTranslate(NULL, object->pos[0], object->pos[1], object->pos[2]);
    njTranslate(NULL, 0.0F, VARS(work)->stretch * 4.0F, 0.0F);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

void spring_b_step(struct task *task)
{
    struct task_work *work = task->work;
    Uint8 i;
    struct task *player;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case SPRING_INIT:
        task->destructor = spring_b_destroy;
        task->draw = spring_b_draw;
        CCL_Init(task, spring_b_shape, COLLISION_OBJECT, 1, 1);
        work->collision->flags |= COLLISION_TARGET;
        VARS(work)->phase_b = 180.0F;
        PHASE_SPEED(work) = 0.0F;
        VARS(work)->bob = 0.5F;
        work->tick = TOUCH_WAIT;
        work->mode = SPRING_WAIT;
        break;
    case SPRING_WAIT:
        VARS(work)->stretch = -_builtin_fabsf(
            VARS(work)->bob * njSin(VARS(work)->phase_b * ANGLE_PER_DEGREE));
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- NO TIMER");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "<- ADD YSPD");
        }
        if (edit_mode == 0) {
            VARS(work)->phase_b += PHASE_SPEED(work);
            if (VARS(work)->phase_b >= 290.0F &&
                VARS(work)->phase_b < 290.0F + PHASE_SPEED(work)) {
                PHASE_SPEED(work) = 15.0F;
            }
            VARS(work)->bob = njCos((VARS(work)->phase_b - 180.0F) *
                                    (0.1F * ANGLE_PER_DEGREE)) *
                              0.6F;
            if (VARS(work)->bob < 0.0F) {
                VARS(work)->phase_b = 180.0F;
                PHASE_SPEED(work) = 0.0F;
            }
            work->tick++;
            if (work->tick > TOUCH_WAIT) {
                if (work->collision->flags & COLLISION_HIT) {
                    work->collision->flags &= ~COLLISION_HIT;
                    for (i = 0; i < 2; i++) {
                        player = GetPlayerTaskPointer(i);
                        if (work->collision->hit->owner == player) {
                            VARS(work)->stretch = LAUNCH_STRETCH;
                            work->submode = i;
                            PHASE_SPEED(work) = 20.0F;
                            VARS(work)->phase_b = 270.0F;
                            work->mode = SPRING_LAUNCH;
                            break;
                        }
                    }
                }
                if (work->mode != SPRING_LAUNCH) {
                    EntryColliList(work);
                }
            }
            if (work->tick > TICK_LIMIT) {
                work->tick = TICK_LIMIT;
            }
        }
        spring_b_draw(task);
        break;
    case SPRING_LAUNCH:
        work->tick = B_LAUNCH_TICK;
        VacumePlayer(task, 1);
        spring_b_draw(task);
        dsPlay_oneshot(SE_SPRING, 0, 0, 0);
        break;
    case SPRING_KILL:
        DeadOut(task);
        break;
    }
}

/* draw the base, the top on the coil, and the coil at its stretch */
static void spring_b_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *coil;
    NJS_OBJECT *object;
    /* @hack redundant: 12 bytes of frame that no code reads, of a type unknown,
     * declared as a point. the image's ADD #-16,R15 reserves them in its
     * 44-byte frame (0x8c06996e); without them, the frame is 32 bytes and 2 of
     * 117 words differ */
    NJS_POINT3 unused;
    /* @hack spelling: draw_model called through draw, which keeps its address
     * in R12 and njPushMatrix's in R11 (0x8c0699c0, 0x8c069976); called by
     * name, the two trade and 11 of 117 words differ */
    void (*draw)(NJS_MODEL *model);

    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    draw = ds_DrawModelClip;
    draw(&spring_b_base_model);
    njPushMatrix(NULL);
    coil = &spring_b_coil_object;
    njTranslate(NULL, coil->pos[0], coil->pos[1], coil->pos[2]);
    njPushMatrix(NULL);
    object = &spring_b_top_object;
    njTranslate(NULL, object->pos[0], object->pos[1], object->pos[2]);
    njTranslate(NULL, 0.0F, VARS(work)->stretch * 4.0F, 0.0F);
    draw(object->model);
    late_DrawObjectClipEx(1);
    /* @hack redundant: coil set again, which loads its address from the pool
     * again and keeps it at @R15 (MOV.L R3,@R15 at 0x8c069a1a); held from
     * above, coil stays in R10, R9 is saved too, and 86 of 117 words
     * differ */
    coil = &spring_b_coil_object;
    njScale(NULL, 1.0F, VARS(work)->stretch + 1.0F, 1.0F);
    draw(coil->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

static void spring_b_destroy(struct task *task)
{
}
