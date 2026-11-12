/* @unit 0C9087E0-0C9091C0 +r04 +egflags +pool32 */
/* act 0's floating bridge, whose planks ride the sea */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stg01/bridge.h"
#include "stg01/orca_control.h"
#include "stg01/sea.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
float njArcTan2(float y, float x);
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
void DestroyTask(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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
void SetMleriRangeRad(Float radius);
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
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
extern struct task *OrukaTask;
void orInitOrukaSequence(void);
Bool orCreateAttackOruka(Float x, Float y, Float z, Angle ang);
void orFreePathOruka(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
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

#define SE_BRIDGE 41
#define PLANKS 25
#define PLANK_LENGTH 40.0F
#define END_EDGE 75.0F
#define LENGTH (END_EDGE + (PLANKS * PLANK_LENGTH) + END_EDGE)
#define PLANK_RISE 9.5F
#define END_REACH 80.0F
#define STEP_RANGE (1500.0F * 1500.0F)
#define TEST_RANGE (95.0F * 95.0F)
#define DRAW_RANGE (600.0F * 600.0F)
#define BRIDGE_VARS(work) ((struct bridge_vars *)&(work)->vars)
#define END_VARS(work) ((struct bridge_end_vars *)&(work)->vars)
#define PLANK_VARS(work) ((struct bridge_plank_vars *)&(work)->vars)
extern NJS_OBJECT beach_bridge_end_0_object;
extern NJS_OBJECT beach_bridge_end_1_object;
extern NJS_OBJECT beach_bridge_plank_object;
/* drawn between each two planks while the set editor holds the bridge */
extern NJS_OBJECT beach_bridge_joint_object;
extern NJS_OBJECT beach_bridge_end_world_object;
extern NJS_OBJECT beach_bridge_plank_world_object;

/* the bridge's held sound. the step holds it while the sea is off
 * SEA_LEVEL at any plank's far edge */

/* the bridge runs along x: an end, PLANKS planks of PLANK_LENGTH, and an
 * end. END_EDGE is the length from an end's middle to its edge, where the
 * planks meet it */
/* from the first end's middle to the last's */
/* a plank rides PLANK_RISE above the bridge's y, plus the sea's height */
/* the radius of an end's collision record */
/* the step runs the pieces only while the camera is within 1500 of the
 * bridge's middle. the world tests a piece only while player 0 or 1 is
 * within 95 of it. a piece beyond 600 of the camera hides. each range is
 * squared */

/* a piece's submode, which the bridge's step sets. a hidden piece isn't
 * drawn */
enum bridge_piece_mode { PIECE_SHOWN, PIECE_HIDDEN };

struct bridge_vars {
    Float unk_00;
    Bool sounding; /* SE_BRIDGE is held for the bridge */
};

struct bridge_end_vars {
    NJS_OBJECT *world; /* the end's object in the collision world */
    Uint8 unk_04[4];
    NJS_OBJECT *object; /* what the end draws */
};

struct bridge_plank_vars {
    NJS_OBJECT *world; /* the plank's object in the collision world */
    Uint8 unk_04[4];
    Float unk_08;
};

void ObjectBeachYurehasi(struct task *task);
void beach_bridge_step(struct task *task);
void Disp(struct task *task);
void beach_bridge_destroy(struct task *task);
void A_Init(struct task *task);
void beach_bridge_end_step(struct task *task);
void beach_bridge_end_draw(struct task *task);
void beach_bridge_end_destroy(struct task *task);
void B_Init(struct task *task);
void B_Exec(struct task *task);
void B_Disp(struct task *task);
void B_Destructor(struct task *task);
extern struct collision_shape beach_bridge_end_0_shapes[4];
extern struct collision_shape beach_bridge_end_1_shapes[4];
extern struct collision_shape beach_bridge_plank_shapes[2];
extern struct task *beach_bridge_task;
extern Angle beach_bridge_plank_angles[25];
extern Float beach_bridge_plank_heights[25];
extern Float beach_bridge_end_heights[2];

void CreateYurehasi(void)
{
    struct task_work *work;

    beach_bridge_task = CreateElementalTask(TASK_WORK, 3, ObjectBeachYurehasi);
    work = beach_bridge_task->work;
    work->pos.x = 2803.0F;
    work->pos.y = -1.0F;
    work->pos.z = 365.0F;
}

void beach_bridge_remove(void)
{
    if (beach_bridge_task != NULL) {
        FreeTask(beach_bridge_task);
    }
}

/* create the bridge's two ends, then its planks from the first end out.
 * while the set editor holds the bridge, create none. each piece's tick
 * numbers it */
void ObjectBeachYurehasi(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *child_work;
    struct task *child;
    Float x;
    Float unk;
    int i;

    work->ang.y = 0;
    BRIDGE_VARS(work)->unk_00 = 0.0F;
    BRIDGE_VARS(work)->sounding = FALSE;
    if (!OnEdit(task)) {
        child = CreateChildTask(TASK_WORK | TASK_FORCE, A_Init, task);
        child_work = child->work;
        child_work->pos.x = work->pos.x;
        child_work->pos.y = work->pos.y;
        child_work->pos.z = work->pos.z;
        child_work->tick = 0;
        END_VARS(child_work)->object = &beach_bridge_end_0_object;

        child = CreateChildTask(TASK_WORK | TASK_FORCE, A_Init, task);
        child_work = child->work;
        child_work->pos.x = work->pos.x + LENGTH;
        child_work->pos.y = work->pos.y;
        child_work->pos.z = work->pos.z;
        child_work->tick = 1;
        END_VARS(child_work)->object = &beach_bridge_end_1_object;

        x = work->pos.x + (END_EDGE + (PLANK_LENGTH / 2));
        unk = 0.0F;
        for (i = 0; i < PLANKS; i++) {
            child = CreateChildTask(TASK_WORK | TASK_FORCE, B_Init, task);
            child_work = child->work;
            child_work->pos.x = x;
            child_work->pos.y = work->pos.y;
            child_work->pos.z = work->pos.z;
            child_work->tick = i;
            PLANK_VARS(child_work)->unk_08 = unk;
            x += PLANK_LENGTH;
            /* 5242.8794F spells the float the pool holds at 0x0c908e3c,
             * 0x45a3d709. the shorter 5242.88F rounds to 0x45a3d70a */
            unk += 5242.8794F;
        }
    }
    task->step = beach_bridge_step;
    task->destructor = beach_bridge_destroy;
}

/* run the bridge only while the camera's squared distance from its middle
 * is within STEP_RANGE. while the set editor holds it, draw it whole.
 * otherwise mark which pieces the world tests and which hide. then sample
 * the sea for the pieces and run them */
void beach_bridge_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task *child;
    struct task_work *child_work;
    NJS_POINT3 position;
    Float *at;
    Float camera_x;
    Float camera_y;
    Float camera_z;
    Float player0_x;
    Float player0_y;
    Float player0_z;
    Float player1_x;
    Float player1_y;
    Float player1_z;
    Float x;
    Float y;
    Float z;
    Float distance;
    Float dx;
    Float dy;
    Float dz;
    Float player0_distance;
    Float player1_distance;
    Float previous;
    Float height;
    Float base_y;
    Bool calm; /* the sea is at SEA_LEVEL at every far edge sampled */
    int i;
    Angle *angles;
    Float *heights;

    /* @hack spelling: the camera's pos and the bridge's read through a cursor,
     * which loads them with FMOV.S @R4+ from 0x0c908e86; without it, 264 of
     * 287 words differ */
    at = VECTOR_FLOATS(&camera_twp->pos);
    /* @hack spelling: the camera's cursor stepped in statements of its own,
     * which leaves ~WORLD_TESTED in R7 and WORLD_TESTED in R6 for 0x0c908fae
     * and 0x0c908fb2; stepped as *at++, 125 of 287 words differ */
    camera_x = *at;
    at++;
    camera_y = *at;
    at++;
    camera_z = *at;
    at = VECTOR_FLOATS(&work->pos);
    dx = camera_x - *at++ - (LENGTH / 2);
    /* @hack spelling: dy assigned apart from its subtraction, which keeps
     * camera x in FR14 and z in FR15, loaded at 0x0c908e86 and 0x0c908e8c; as
     * one statement, 6 of 287 words differ */
    dy = camera_y;
    dy -= *at++;
    dz = camera_z - *at;
    distance = (dx * dx) + (dy * dy) + (dz * dz);
    if (distance > STEP_RANGE) {
        BRIDGE_VARS(work)->unk_00 += 300.0F;
        return;
    }
    if (OnEdit(task)) {
        Disp(task);
    } else {
        child = task->child;
        /* @bug uninitialized: with no player 0, player_get_history returns
         * FALSE without writing position (JSR at 0x0c908f0c), and the step
         * reads it all the same (0x0c908f14 to 0x0c908f28). with no player
         * 1, the second call writes nothing, and 0x0c908f34 to 0x0c908f4a
         * read what the first left */
        GetPlayerPosition(0, 0, &position, NULL);
        /* @hack spelling: player 0's position read through the cursor, which
         * loads it with FMOV.S @R4+ from 0x0c908f14; without it, 99 of 287
         * words differ */
        at = VECTOR_FLOATS(&position);
        player0_x = *at++;
        player0_y = *at++;
        player0_z = *at;
        GetPlayerPosition(1, 0, &position, NULL);
        /* @hack spelling: player 1's position read the same way, from
         * 0x0c908f34; without it, 81 of 287 words differ */
        at = VECTOR_FLOATS(&position);
        player1_x = *at++;
        player1_y = *at++;
        player1_z = *at;
        while (child != NULL) {
            child_work = child->work;
            /* @hack redundant: a never-run test of child, whose reads keep
             * child in R13 and 0 in R12, at 0x0c908f04 and 0x0c908f58; without
             * it, 55 of 287 words differ */
            if (0) {
                /* NOLINTNEXTLINE(misc-redundant-expression) */
                if (child && child && child) {
                }
            }
            x = child_work->pos.x;
            y = child_work->pos.y;
            z = child_work->pos.z;
            /* @hack redundant: a never-run test of x, which keeps the piece's x
             * in FR7, loaded at 0x0c908f60; without it, 55 of 287 words
             * differ */
            if (0) {
                if (x) {
                }
            }
            /* @hack spelling: dy ahead of dx, which keeps player 0's y in FR12,
             * loaded at 0x0c908f20; with dx first, 15 of 287 words differ */
            dy = player0_y - y;
            dx = player0_x - x;
            player0_distance = dx * dx;
            player0_distance += dy * dy;
            dz = player0_z - z;
            player0_distance += dz * dz;
            dx = player1_x - x;
            player1_distance = dx * dx;
            dy = player1_y - y;
            player1_distance += dy * dy;
            dz = player1_z - z;
            player1_distance += dz * dz;
            /* @hack redundant: a never-run test of player0_distance, whose
             * reads keep player 0's distance in FR4, from 0x0c908f6c; without
             * it, 72 of 287 words differ */
            if (0) {
                /* NOLINTNEXTLINE(misc-redundant-expression) */
                if (player0_distance && player0_distance) {
                }
            }
            /* @hack redundant: a never-run test against TEST_RANGE, which
             * keeps TEST_RANGE in FR6, loaded at 0x0c908f54; without it, 67 of
             * 287 words differ */
            if (0) {
                if (player0_distance > TEST_RANGE) {
                }
            }
            if (player0_distance > TEST_RANGE &&
                player1_distance > TEST_RANGE) {
                child_work->flags &= ~WORLD_TESTED;
            } else {
                child_work->flags |= WORLD_TESTED;
            }
            dx = camera_x - x;
            distance = dx * dx;
            /* @hack spelling: y, reused for its own delta, which keeps the
             * piece's y in FR5, loaded at 0x0c908f64; as dy, 70 of 287 words
             * differ */
            y = camera_y - y;
            distance += y * y;
            dz = camera_z - z;
            distance += dz * dz;
            if (distance > DRAW_RANGE) {
                child_work->submode = PIECE_HIDDEN;
            } else {
                child_work->submode = PIECE_SHOWN;
            }
            child = child->next;
        }
        /* @hack redundant: never-run stores of sounding, which keep work in
         * R14, from 0x0c908e7e; without it, 122 of 287 words differ */
        if (0) {
            BRIDGE_VARS(work)->sounding = FALSE;
            BRIDGE_VARS(work)->sounding = FALSE;
            BRIDGE_VARS(work)->sounding = FALSE;
            BRIDGE_VARS(work)->sounding = FALSE;
        }
        /* @hack redundant: a never-run test of work and task, whose reads keep
         * camera x in FR14 and y in FR13, loaded at 0x0c908e86 and 0x0c908e88;
         * without it, 60 of 287 words differ */
        if (0) {
            /* NOLINTNEXTLINE(misc-redundant-expression) */
            if (work && work && task) {
            }
        }
        x = work->pos.x + END_EDGE;
        z = work->pos.z;
        calm = TRUE;
        previous = beach_sea_height(x, z);
        beach_bridge_end_heights[0] = previous;
        base_y = work->pos.y + PLANK_RISE;
        angles = beach_bridge_plank_angles;
        heights = beach_bridge_plank_heights;
        for (i = 0; i < PLANKS; i++) {
            x += PLANK_LENGTH;
            height = beach_sea_height(x, z);
            if (height != SEA_LEVEL) {
                calm = FALSE;
            }
            /* @hack redundant: a never-run test of calm, which keeps the locals
             * in 44 bytes, ADD #-44,R15 at 0x0c908e78; without it, 123 of 287
             * words differ */
            if (0) {
                if (calm) {
                }
            }
            *heights++ = base_y + ((previous + height) * 0.5F);
            *angles++ = (Angle)(njArcTan2(height - previous, PLANK_LENGTH) *
                                ANGLE_PER_RADIAN);
            previous = height;
        }
        beach_bridge_end_heights[1] = height;
        if (BRIDGE_VARS(work)->sounding == TRUE && calm == TRUE) {
            dsStop_id((int)work);
            BRIDGE_VARS(work)->sounding = FALSE;
        } else if (BRIDGE_VARS(work)->sounding == FALSE && calm == FALSE) {
            dsPlay_iloop(SE_BRIDGE, (int)work, 1, 2000);
            BRIDGE_VARS(work)->sounding = TRUE;
        }
        LoopTaskC(task);
    }
}

/* the whole bridge, at rest: the first end, the planks with a joint between
 * each two, and the last end */
void Disp(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    int i;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObject(&beach_bridge_end_0_object);
    njTranslate(NULL, END_EDGE, PLANK_RISE, 0.0F);
    for (i = 0; i < PLANKS - 1; i++) {
        njTranslate(NULL, PLANK_LENGTH / 2, 0.0F, 0.0F);
        late_DrawObject(&beach_bridge_plank_object);
        njTranslate(NULL, PLANK_LENGTH / 2, 0.0F, 0.0F);
        late_DrawObject(&beach_bridge_joint_object);
    }
    njTranslate(NULL, PLANK_LENGTH / 2, 0.0F, 0.0F);
    late_DrawObject(&beach_bridge_plank_object);
    njTranslate(NULL, (PLANK_LENGTH / 2) + END_EDGE, 0.0F, 0.0F);
    late_DrawObject(&beach_bridge_end_1_object);
    late_DrawObjectClipEx(1);
}

void beach_bridge_destroy(struct task *task)
{
    FreeTaskC(task);
}

void A_Init(struct task *task)
{
    struct task_work *work = task->work;
    struct task_force *force = task->force;
    NJS_OBJECT *object;

    work->submode = PIECE_SHOWN;
    force->turn.x = 0;
    force->turn.y = 0;
    force->turn.z = 0;
    force->speed.x = 0.0F;
    force->speed.y = 0.0F;
    force->speed.z = 0.0F;
    END_VARS(work)->world = object = GetMobileLandObject();
    object->evalflags = NJD_EVAL_BREAK;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    object->ang[0] = 0;
    object->ang[1] = work->ang.y;
    object->ang[2] = 0;
    object->pos[0] = work->pos.x;
    object->pos[1] = work->pos.y;
    object->pos[2] = work->pos.z;
    object->model = beach_bridge_end_world_object.model;
    object->child = NULL;
    object->sibling = NULL;
    RegisterCollisionEntry(WORLD_SMALL | WORLD_MOVES | WORLD_SOLID, task,
                           object);
    work->flags |= WORLD_TESTED;
    if (work->tick == 0) {
        CCL_Init(task, beach_bridge_end_0_shapes, COLLISION_OBJECT, 1, 4);
    } else {
        CCL_Init(task, beach_bridge_end_1_shapes, COLLISION_OBJECT, 1, 4);
    }
    work->collision->radius = END_REACH;
    task->step = beach_bridge_end_step;
    task->draw = beach_bridge_end_draw;
    task->destructor = beach_bridge_end_destroy;
}

/* draw, then ride the sea at the end's edge */
void beach_bridge_end_step(struct task *task)
{
    struct task_work *work = task->work;
    Float height;

    beach_bridge_end_draw(task);
    height = beach_bridge_end_heights[work->tick];
    work->pos.y = height;
    END_VARS(work)->world->pos[1] = height;
    EntryColliList(work);
}

void beach_bridge_end_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    if (work->submode == PIECE_SHOWN) {
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        late_DrawObject(END_VARS(work)->object);
        late_DrawObjectClipEx(1);
    }
}

void beach_bridge_end_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (END_VARS(work)->world != NULL) {
        WithdrawCollisionEntry(task, END_VARS(work)->world);
        ReleaseMobileLandObject(END_VARS(work)->world);
    }
}

void B_Init(struct task *task)
{
    struct task_work *work = task->work;
    struct task_force *force = task->force;
    NJS_OBJECT *object;

    work->submode = PIECE_SHOWN;
    force->turn.x = 0;
    force->turn.y = 0;
    force->turn.z = 0;
    force->speed.x = 0.0F;
    force->speed.y = 0.0F;
    force->speed.z = 0.0F;
    PLANK_VARS(work)->world = object = GetMobileLandObject();
    object->evalflags = NJD_EVAL_BREAK;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    object->ang[0] = 0;
    object->ang[1] = work->ang.y;
    object->ang[2] = 0;
    object->pos[0] = work->pos.x;
    object->pos[1] = work->pos.y;
    object->pos[2] = work->pos.z;
    object->model = beach_bridge_plank_world_object.model;
    object->child = NULL;
    object->sibling = NULL;
    RegisterCollisionEntry(WORLD_SMALL | WORLD_MOVES | WORLD_SOLID, task,
                           object);
    work->flags |= WORLD_TESTED;
    CCL_Init(task, beach_bridge_plank_shapes, COLLISION_OBJECT, 1, 2);
    task->step = B_Exec;
    task->draw = B_Disp;
    task->destructor = B_Destructor;
}

/* draw, then ride the sea. the slope's angle turns the plank about z. it
 * turns the plank about x by the same angle too, as drawn and in the
 * collision world */
void B_Exec(struct task *task)
{
    struct task_work *work = task->work;
    int plank;
    Float height;
    Angle angle;

    B_Disp(task);
    plank = work->tick;
    height = beach_bridge_plank_heights[plank];
    angle = beach_bridge_plank_angles[plank];
    work->pos.y = height;
    work->ang.z = angle;
    PLANK_VARS(work)->world->pos[1] = height;
    PLANK_VARS(work)->world->ang[2] = angle;
    PLANK_VARS(work)->world->ang[0] = angle;
    EntryColliList(work);
}

void B_Disp(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (work->submode == PIECE_SHOWN) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateZ, work->ang.z, ang);
        TURN_VIA(njRotateX, work->ang.z, ang);
        late_DrawObject(&beach_bridge_plank_object);
        late_DrawObjectClipEx(1);
    }
}

void B_Destructor(struct task *task)
{
    struct task_work *work = task->work;

    if (PLANK_VARS(work)->world != NULL) {
        WithdrawCollisionEntry(task, PLANK_VARS(work)->world);
        ReleaseMobileLandObject(PLANK_VARS(work)->world);
    }
}
