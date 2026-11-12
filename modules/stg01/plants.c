/* @unit 0C906820-0C9070C0 @data 0C910BC8-0C910BE0 +r04 +egflags +pool32 +asmfunc=beach_butterfly_step */
/* O MKUSA and O BKUSA plants, and O K2, a plant that sends up butterflies as
 * player 0 runs past */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "debug/editor.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg01/plants.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
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
extern NJS_MATRIX nj_unit_matrix_;
void *syMalloc_default_malloc(size_t size);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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
void FUN_0c906e6e(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

#define PHASE(work) (((struct beach_kusa_vars *)&(work)->vars)->phase)
#define SWAY_AMPLITUDE 10.0F
#define SWAY_SPEED 3.5F
#define SWAY_DECAY 0.045F
#define TOUCH_RANGE 20.0F
#define TOUCH_SPEED 0.2F
#define OTHER_MODEL 5.0F
#define BUTTERFLY(work) ((struct beach_butterfly_vars *)&(work)->vars)
#define BUTTERFLY_STEPS 600
#define SPIN (65536.0F / 20.0F)
#define PUSH 0.1F
#define FALL_MOST 0.67F
#define MOVE_XZ (1.0F / 24.0F)
#define MOVE_Y 0.1F
#define SCATTER_RANGE 30.0F
#define SCATTER_SPEED 0.7F
#define SCATTER_WAIT 10
#define BUTTERFLIES 2
#define FLUTTER_HEIGHT 10.0F
#define SCATTER_REACH 3.0F
extern NJS_MODEL beach_mkusa_model;
extern NJS_OBJECT beach_mkusa_leaf_1_object;
extern NJS_OBJECT beach_mkusa_leaf_2_object;
extern NJS_OBJECT beach_mkusa_leaf_3_object;
extern NJS_OBJECT beach_mkusa_leaf_4_object;
extern NJS_OBJECT beach_mkusa_leaf_5_object;
extern NJS_OBJECT beach_mkusa_leaf_6_object;
extern NJS_OBJECT beach_mkusa_leaf_7_object;
extern NJS_OBJECT beach_mkusa_leaf_8_object;
extern NJS_OBJECT beach_bkusa_a_object;
extern NJS_OBJECT beach_bkusa_b_object;
extern NJS_OBJECT beach_bkusa_other_object;
extern NJS_OBJECT beach_k2_object;
/* one quad folded along a diagonal, whose two halves are a butterfly's
 * wings */
extern NJS_OBJECT beach_butterfly_object;

/* the plants' modes. only beach_kusa_touch, which O BKUSA's step calls,
 * enters KUSA_SWAY. nothing here enters KUSA_STOP */
enum beach_kusa_mode { KUSA_INIT, KUSA_STILL, KUSA_SWAY, KUSA_STOP };

/* a butterfly flutters until it rises above its height, then falls until it
 * drops below it */
enum beach_butterfly_mode {
    BUTTERFLY_INIT = 0,
    BUTTERFLY_FLUTTER = 3,
    BUTTERFLY_FALL = 6
};

/* a plant's sway: scl.y holds its amplitude, and scl.x its offset this step.
 * neither draw reads them, so a swaying plant draws as a still one does */
struct beach_kusa_vars {
    Float phase; /* the sway's phase, in degrees */
};

/* a touch starts the sway at SWAY_AMPLITUDE. each step, the phase moves on
 * SWAY_SPEED degrees and the amplitude loses SWAY_DECAY. the sway ends once
 * the amplitude falls below 0, 223 steps on */

/* player 0 touches O BKUSA by running on the ground within TOUCH_RANGE of it
 * at TOUCH_SPEED or faster */

/* O BKUSA's scl.z picks its model: beach_bkusa_a_object at 0,
 * beach_bkusa_other_object above OTHER_MODEL, and beach_bkusa_b_object
 * otherwise */

/* scl holds a butterfly's speed, tick its scale in 32nds, and
 * TASK_TIMER(work) the steps it has left */
struct beach_butterfly_vars {
    Uint16 spin_x; /* the turn added to ang.x each step */
    Uint16 spin_y; /* the turn added to ang.y each step */
    Uint8 unk_04[4];
    Float height; /* the height the butterfly flutters about */
};

/* each spin is random, from -SPIN / 2 up to SPIN / 2 */

/* while a butterfly flutters, its x and z speeds gain PUSH a step along
 * ang.y. its y speed gains PUSH times sin(2 * ang.x). while it falls, its y
 * speed loses PUSH a step, down to -FALL_MOST */

/* a step moves a butterfly by its x and z speeds times MOVE_XZ. it moves by
 * its y speed times MOVE_Y */

/* O K2 sends up butterflies while player 0 runs on the ground near it. he
 * must be within SCATTER_RANGE, at SCATTER_SPEED or faster.
 * TASK_TIMER(work) counts those steps from 0 up to SCATTER_WAIT and round
 * again. BUTTERFLIES go up on each step it is 0, each to flutter about
 * FLUTTER_HEIGHT above the plant */
/* a butterfly starts off the plant by a random offset, from 0 up to
 * SCATTER_REACH. the same offset applies in x and z, and is its first y
 * speed */

void beach_bkusa_draw(struct task *task);
void beach_mkusa_draw(struct task *task);
void beach_kusa_sway(struct task *task);
void beach_butterfly_step(struct task *task);
void beach_kusa_touch(struct task *task);
void beach_k2_draw(struct task *task);
static void beach_k2_scatter(struct task *task);

/* O MKUSA never tests for a touch, so it never enters KUSA_SWAY */
void beach_mkusa_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case KUSA_INIT:
        task->draw = beach_mkusa_draw;
        work->mode = KUSA_STILL;
        break;
    case KUSA_STILL:
        beach_mkusa_draw(task);
        /* @hack redundant: a test of placement_editing's result that does
         * nothing, which keeps the image's TST R0,R0 at 0x0c906b7e. as a
         * bare call, 31 of 54 words differ and the functions after it
         * move */
        if (!OnEdit(task)) {
        }
        break;
    case KUSA_SWAY:
        beach_kusa_sway(task);
        if (work->scl.y < 0.0F) {
            work->scl.y = 0.0F;
            work->mode = KUSA_STILL;
            PHASE(work) = 0.0F;
        }
        beach_mkusa_draw(task);
        break;
    case KUSA_STOP:
        break;
    }
}

/* outside the set editor, an O BKUSA whose scl.z is below OTHER_MODEL tests
 * for player 0's touch */
void ObjectBeachKusa(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case KUSA_INIT:
        task->draw = beach_bkusa_draw;
        work->mode = KUSA_STILL;
        break;
    case KUSA_STILL:
        beach_bkusa_draw(task);
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "<- OTHER MODEL 5 over");
        }
        if (!OnEdit(task) && work->scl.z < OTHER_MODEL) {
            beach_kusa_touch(task);
        }
        break;
    case KUSA_SWAY:
        beach_kusa_sway(task);
        if (work->scl.y < 0.0F) {
            work->mode = KUSA_STILL;
            PHASE(work) = 0.0F;
        }
        beach_bkusa_draw(task);
        break;
    case KUSA_STOP:
        break;
    }
}

void beach_bkusa_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    if (work->scl.z == 0.0F) {
        late_DrawObject(&beach_bkusa_a_object);
    } else if (work->scl.z > OTHER_MODEL) {
        late_DrawObject(&beach_bkusa_other_object);
    } else {
        late_DrawObject(&beach_bkusa_b_object);
    }
    late_DrawObjectClipEx(1);
}

/* draw_tree draws each sibling after the node it is given. the leaves are
 * one sibling chain, from leaf 1 to leaf 8, so leaf n draws n times */
void beach_mkusa_draw(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: a vector declared and never used, which keeps the frame
     * at 16 bytes (ADD #-16,R15 at 0x0c906cfe). without it, 2 of 83 words
     * differ */
    NJS_VECTOR unused;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&beach_mkusa_model);
    njPushMatrix(NULL);
    late_DrawObject(&beach_mkusa_leaf_1_object);
    late_DrawObject(&beach_mkusa_leaf_2_object);
    late_DrawObject(&beach_mkusa_leaf_3_object);
    late_DrawObject(&beach_mkusa_leaf_4_object);
    late_DrawObject(&beach_mkusa_leaf_5_object);
    late_DrawObject(&beach_mkusa_leaf_6_object);
    late_DrawObject(&beach_mkusa_leaf_7_object);
    late_DrawObject(&beach_mkusa_leaf_8_object);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

void beach_kusa_sway(struct task *task)
{
    struct task_work *work = task->work;

    PHASE(work) += SWAY_SPEED;
    work->scl.y -= SWAY_DECAY;
    work->scl.x = work->scl.y * njSin((Angle)(PHASE(work) * ANGLE_PER_DEGREE));
}

/* a butterfly starts with random x and z speeds from -0.5 up to 0.5. its
 * angles and spins start random too, and its scale from 0.5 up to 1.5, in
 * 16ths. it flies and draws for BUTTERFLY_STEPS steps */
void beach_butterfly_step(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    Float scale;

    switch (work->mode) {
    case BUTTERFLY_INIT:
        TASK_TIMER(work) = BUTTERFLY_STEPS;
        work->scl.x = RANDOM(-0.5F, 0.5F);
        work->scl.z = RANDOM(-0.5F, 0.5F);
        work->ang.y = RANDOM_ANGLE();
        work->ang.x = RANDOM_ANGLE();
        BUTTERFLY(work)->spin_x = RANDOM(-0.5F, 0.5F) * SPIN;
        BUTTERFLY(work)->spin_y = RANDOM(-0.5F, 0.5F) * SPIN;
        work->tick = RANDOM(1.0F, 3.0F) * 16.0F;
        work->mode = BUTTERFLY_FLUTTER;
        break;
    case BUTTERFLY_FLUTTER:
        work->scl.x += PUSH * njSin(work->ang.y);
        work->scl.z += PUSH * njCos(work->ang.y);
        work->scl.y += PUSH * njSin(work->ang.x * 2);
        if (work->pos.y > BUTTERFLY(work)->height) {
            work->mode = BUTTERFLY_FALL;
        }
        break;
    case BUTTERFLY_FALL:
        if ((work->scl.y -= PUSH) < -FALL_MOST) {
            work->scl.y = -FALL_MOST;
        }
        if (work->pos.y < BUTTERFLY(work)->height) {
            work->mode = BUTTERFLY_FLUTTER;
        }
        break;
    }
    work->ang.x += BUTTERFLY(work)->spin_x;
    work->ang.y += BUTTERFLY(work)->spin_y;
    work->pos.x += work->scl.x * MOVE_XZ;
    work->pos.y += work->scl.y * MOVE_Y;
    work->pos.z += work->scl.z * MOVE_XZ;
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    /* halved as an integer, an odd tick loses its last 32nd */
    /* NOLINTNEXTLINE(bugprone-integer-division) */
    scale = (work->tick / 2) * (1.0F / 16.0F);
    njScale(NULL, scale, scale, scale);
    njEasyDrawObject(&beach_butterfly_object);
    late_DrawObjectClipEx(1);
    /* a butterfly has no placement, so its range is 410 units. out of range,
     * it still counts down this step, and destroys itself on its next */
    CheckRangeOut(task);
    if (--TASK_TIMER(work) == 0) {
        FreeTask(task);
    }
}

/* at player 0's touch, start the sway. keep a unit vector in the task's
 * extra, where nothing reads it */
void beach_kusa_touch(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VECTOR *way = task->extra;
    Float speed;
    NJS_VECTOR unit;

    if (CalcDistance(&playertwp[0]->pos, &work->pos) < TOUCH_RANGE) {
        if (player_ground_speed(0, &speed) && speed >= TOUCH_SPEED) {
            /* @bug logic: the vector's y and z take player 0's y and z
             * from the plant's x, not from its y and z (FMOV.S @(R0,R13),FR2
             * with R0 32, pos.x, at 0x0c907168 and 0x0c907178) */
            way->x = work->pos.x - playertwp[0]->pos.x;
            way->y = work->pos.x - playertwp[0]->pos.y;
            way->z = work->pos.x - playertwp[0]->pos.z;
            unit.x = way->x;
            unit.y = way->y;
            unit.z = way->z;
            njUnitVector(&unit);
            way->x = unit.x;
            way->y = unit.y;
            way->z = unit.z;
            work->scl.y = SWAY_AMPLITUDE;
            work->mode = KUSA_SWAY;
        }
    }
}

void FUN_0c906e6e(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case KUSA_INIT:
        task->draw = beach_k2_draw;
        work->mode = KUSA_STILL;
        break;
    case KUSA_STILL:
        beach_k2_draw(task);
        if (!OnEdit(task)) {
            beach_k2_scatter(task);
        }
        break;
    case KUSA_STOP:
        break;
    }
}

void beach_k2_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObject(&beach_k2_object);
    late_DrawObjectClipEx(1);
}

static void beach_k2_scatter(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: a vector declared and never used, which keeps the frame
     * at 16 bytes (ADD #-16,R15 at 0x0c907304). without it, 2 of 103 words
     * differ */
    NJS_VECTOR unused;
    Float speed;

    if (CalcDistance(&playertwp[0]->pos, &work->pos) < SCATTER_RANGE) {
        if (player_ground_speed(0, &speed) && speed >= SCATTER_SPEED) {
            if (TASK_TIMER(work) == 0) {
                int i;

                for (i = BUTTERFLIES; i > 0; --i) {
                    struct task *made;

                    if ((made = CreateElementalTask(
                             TASK_WORK, 5, beach_butterfly_step)) != NULL) {
                        struct task_work *butterfly = made->work;
                        Float offset = rand() * RAND_SCALE;

                        butterfly->pos.x =
                            work->pos.x + (offset * SCATTER_REACH);
                        butterfly->pos.y = work->pos.y;
                        butterfly->pos.z =
                            work->pos.z + (offset * SCATTER_REACH);
                        BUTTERFLY(butterfly)->height =
                            work->pos.y + FLUTTER_HEIGHT;
                        butterfly->scl.y = njAbs(offset) * SCATTER_REACH;
                    }
                }
            }
            TASK_TIMER(work)++;
            if (TASK_TIMER(work) > SCATTER_WAIT) {
                TASK_TIMER(work) = 0;
            }
        }
    }
}
