/* @unit 0C904220-0C904980 @data 0C910B30-0C910B48 +r04 +egflags +pool32 */
/* O KAMOME and O KAMOMEL seagulls that fly between random points above a
 * circle about where they were placed */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/helpers.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/helpers.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg01/seagull.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void FUN_8c0574c6(NJS_POINT3 *start, NJS_POINT3 *target, Float distance,
                  NJS_POINT3 *out);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
Float vector_reflect(NJS_VECTOR *vector, NJS_VECTOR *normal_jp,
                     NJS_VECTOR *out);
Bool polygon_contains(NJS_POINT3 *point, NJS_POINT3 *corners,
                      NJS_VECTOR *normal_jp, int count);
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

#define VARS(work) ((struct seagull_vars *)&(work)->vars)
#define SEAGULL_MOTION(task) ((struct seagull_motion *)(task)->motion)
#define EXTRA(task) ((struct seagull_extra *)(task)->extra)
#define TARGET_REACH 80.0F
#define PACE_START 2.0F
#define PACE_DRAG 0.01F
#define PACE_LEAST 0.5F
#define SPEED_MOST 0.3F
#define SPEED_LEAST 0.09F
#define PLAYER_NEAR 30.0F
#define PLAYER_BOOST 2.2F
#define STEER_SPEED 0.7F
#define WING_SWING 10.0F
#define SEAGULL_SCALE 1.5F
extern NJS_ACTION beach_seagull_action;
extern NJS_MODEL beach_seagull_l_body_model;
extern NJS_OBJECT beach_seagull_l_wing_minus_x_object;
extern NJS_OBJECT beach_seagull_l_wing_plus_x_object;

/* the steer point. the seagull flies toward it, and it moves on toward the
 * target */
struct seagull_vars {
    Float steer_y;
    Float steer_z;
    Float steer_x;
};

struct seagull_motion {
    Uint8 unk_00[4];
    Float unk_04;
    Uint8 unk_08[4];
    Float pace; /* the action's frames a step, and the speed before its clamp */
    NJS_POINT3 home; /* where the seagull was placed */
    Uint8 unk_1c[24];
    NJS_POINT3 target; /* the point the steer point moves toward */
};

/* where the current leg toward the target starts */
struct seagull_extra {
    NJS_POINT3 from;
};

/* in SEAGULL_IDLE, the step neither flies nor draws. nothing here enters
 * it */
enum seagull_mode { SEAGULL_START = 0, SEAGULL_FLY = 3, SEAGULL_IDLE = 5 };

/* the targets lie this far plus scl.y out from home, and up to this far
 * above it */

/* each new target sets the pace to PACE_START. the pace then falls by
 * PACE_DRAG a step, down to PACE_LEAST */
/* the seagull always flies SPEED_MOST a step, or PLAYER_BOOST times that
 * within PLAYER_NEAR of player 0. its speed is its pace held from
 * SPEED_LEAST to SPEED_MOST. the pace never falls below PACE_LEAST, which is
 * above SPEED_MOST */

/* the steer point moves this far toward the target each step */

/* O KAMOMEL's wings swing this many degrees times the pace each way */

/* both seagulls draw at this scale */

void o_beach_kamome_Draw(struct task *task);
void DrawLow(struct task *task);
void Norm(struct task *task, Float unused);
void seagull_choose(struct task *task);
void seagull_steer(struct task *task);

/* the object list's step for O KAMOME */
void ObjectBeachKamome(struct task *task)
{
    struct task_work *work = task->work;
    struct seagull_motion *motion = SEAGULL_MOTION(task);
    struct seagull_extra *extra = EXTRA(task);

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case SEAGULL_START:
        work->mode = SEAGULL_FLY;
        motion->home = work->pos;
        extra->from.x = work->pos.x;
        extra->from.y = work->pos.y;
        extra->from.z = work->pos.z;
        seagull_choose(task);
        ((struct seagull_vars *)&(work)->vars)->steer_x =
            (motion->target.x - extra->from.x) * 0.5F;
        ((struct seagull_vars *)&(work)->vars)->steer_y =
            (motion->target.y - extra->from.y) * 0.5F;
        ((struct seagull_vars *)&(work)->vars)->steer_z =
            (motion->target.z - extra->from.z) * 0.5F;
        task->draw = o_beach_kamome_Draw;
        break;
    case SEAGULL_FLY:
        if (!OnEdit(task)) {
            Norm(task, motion->unk_04);
            seagull_steer(task);
        }
        o_beach_kamome_Draw(task);
        break;
    case SEAGULL_IDLE:
        break;
    }
}

/* draw the action at frame scl.x, which the step advances. a frame at the
 * motion's last or past it goes back to 0 */
void o_beach_kamome_Draw(struct task *task)
{
    struct task_work *work = task->work;

    SetObjectTexture();
    njPushMatrix(((void *)0));
    njTranslate(((void *)0), work->pos.x, work->pos.y, work->pos.z);
    ((work->ang.y - ((Angle)(((90) * 65536.0) / 360.0)))
         ? (njRotateY)(((void *)0),
                       (work->ang.y - ((Angle)(((90) * 65536.0) / 360.0))))
         : (void)0);
    njScale(((void *)0), 1.5F, 1.5F, 1.5F);
    ds_ActionClip(&beach_seagull_action, work->scl.x);
    late_DrawObjectClipEx(1);
    /* @hack spelling: the motion reached through the action's address, so the
     * load at 0x0c90455a takes the action's own pool entry, which
     * draw_action's argument uses too. through the member, 5 of 68 words and
     * 4 pool words differ */
    if (work->scl.x >= (Float)((&beach_seagull_action)->motion->nbFrame - 1)) {
        work->scl.x = 0.0F;
    }
}

/* TASK_TIMER(work) counts these draws, and the wings beat once every 360 of
 * them */
void DrawLow(struct task *task)
{
    struct task_work *work = task->work;
    struct seagull_motion *motion = SEAGULL_MOTION(task);
    Float swing;
    Angle ang;
    swing = motion->pace *
            njSin((Angle)((*(Uint16 *)&(work)->timer) * (65536.0F / 360.0F))) *
            10.0F;
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN(njRotateY, work->ang.y - NJM_DEG_ANG(90));
    njScale(NULL, SEAGULL_SCALE, SEAGULL_SCALE, SEAGULL_SCALE);
    ds_DrawModelClip(&beach_seagull_l_body_model);
    njPushMatrix(NULL);
    TURN_VIA(njRotateZ, (Angle)(swing * ANGLE_PER_DEGREE), ang);
    /* the plus-x wing is the minus-x wing's sibling, so it draws twice:
     * here, turned with the minus-x wing, and below, turned the other way */
    late_DrawObject(&beach_seagull_l_wing_minus_x_object);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    TURN(njRotateZ, -ang);
    late_DrawObject(&beach_seagull_l_wing_plus_x_object);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}

/* advance the action by the pace, slow the pace, and fly toward the steer
 * point. the seagull turns its x axis away from the point. ang.z turns at
 * once, and ang.y by at most a degree a step. work->tick counts the steps at
 * PACE_LEAST from 0 to 10 and round again. nothing reads it */
void Norm(struct task *task, Float unused)
{
    struct task_work *work = task->work;
    struct seagull_motion *motion = SEAGULL_MOTION(task);
    NJS_POINT3 steer;
    /* @hack redundant: an initializer, which the image copies from
     * 0x0c911428 (0x0c904748 to 0x0c90475e) before it sets each field again.
     * without it, 129 of 134 words differ, the functions after it move, and
     * the constants are 12 bytes fewer */
    NJS_VECTOR away = {0.0F, 0.0F, 0.0F};
    Angle heading;
    Float speed;

    work->scl.x += motion->pace;
    /* @hack redundant: + 0.0F, which keeps the image's FADD at 0x0c904776.
     * without it, 113 of 134 words differ */
    speed = motion->pace + 0.0F;
    if (speed > SPEED_MOST) {
        speed = SPEED_MOST;
    }
    if (speed < SPEED_LEAST) {
        speed = SPEED_LEAST;
    }
    motion->pace -= PACE_DRAG;
    if (motion->pace < PACE_LEAST) {
        motion->pace = PACE_LEAST;
        work->tick++;
        if (work->tick > 10) {
            work->tick = 0;
        }
    }
    steer.x = VARS(work)->steer_x;
    steer.y = VARS(work)->steer_y;
    steer.z = VARS(work)->steer_z;
    if (CalcDistance(&work->pos, &playertwp[0]->pos) < PLAYER_NEAR) {
        speed *= PLAYER_BOOST;
    }
    FUN_8c0574c6(&work->pos, &steer, speed, &work->pos);
    away.x = work->pos.x - steer.x;
    away.y = work->pos.y - steer.y;
    away.z = work->pos.z - steer.z;
    vector_aim_x(&away, &heading, &work->ang.z);
    work->ang.y = AdjustAngle(work->ang.y, heading, NJM_DEG_ANG(1));
}

/* pick a target at random, and set the pace to PACE_START */
void seagull_choose(struct task *task)
{
    struct task_work *work = task->work;
    struct seagull_motion *motion = SEAGULL_MOTION(task);
    struct seagull_extra *extra = EXTRA(task);
    /* @hack redundant: the leg, which the image stores (0x0c904920 to
     * 0x0c90493a) and never reads. without it, 86 of 90 words differ and the
     * functions after it move */
    NJS_VECTOR leg;
    /* @hack redundant: twelve bytes declared and never used, which keep the
     * frame at 24 bytes (ADD #-24,R15 at 0x0c9048ac). without them, 35 of 90
     * words differ and the functions after it move */
    Uint8 unused[12];
    /* rand() times just under 2: an angle from 0 up to a turn. 1.9999999F
     * spells the image's factor, the float 0x3fffffff */
    Angle ang = (Angle)(rand() * 1.9999999F);

    motion->target.x =
        motion->home.x + ((work->scl.y + TARGET_REACH) * njSin(ang));
    motion->target.y =
        motion->home.y + _builtin_fabsf(njSin(ang) * TARGET_REACH);
    motion->target.z =
        motion->home.z + ((work->scl.y + TARGET_REACH) * njCos(ang));
    leg.x = motion->target.x - extra->from.x;
    leg.y = motion->target.y - extra->from.y;
    leg.z = motion->target.z - extra->from.z;
    motion->pace = PACE_START;
}

/* move the steer point STEER_SPEED toward the target. the leg ends once the
 * seagull's distance from the leg's start passes half the steer point's.
 * the next leg starts at the steer point, toward a new target */
void seagull_steer(struct task *task)
{
    struct task_work *work = task->work;
    struct seagull_motion *motion = SEAGULL_MOTION(task);
    struct seagull_extra *extra = EXTRA(task);
    NJS_POINT3 target;
    NJS_POINT3 steer;
    /* @hack redundant: the leg, which the image stores (0x0c904988 to
     * 0x0c9049a4) and never reads. without it, 147 of 158 words differ and
     * the functions after it move */
    NJS_VECTOR leg;
    NJS_POINT3 next;
    /* @hack redundant: up, whose initializer the image copies (0x0c904976
     * to 0x0c90497e) and never reads. without it, 147 of 158 words differ
     * and the constants are 12 bytes fewer */
    NJS_VECTOR up = {0.0F, 1.0F, 0.0F};
    NJS_VECTOR back;
    NJS_VECTOR flown;

    leg.x = motion->target.x - extra->from.x;
    leg.y = motion->target.y - extra->from.y;
    leg.z = motion->target.z - extra->from.z;
    steer.x = VARS(work)->steer_x;
    steer.y = VARS(work)->steer_y;
    steer.z = VARS(work)->steer_z;
    target.x = motion->target.x;
    target.y = motion->target.y;
    target.z = motion->target.z;
    FUN_8c0574c6(&steer, &target, 0.7F, &next);
    ((struct seagull_vars *)&(work)->vars)->steer_x = next.x;
    ((struct seagull_vars *)&(work)->vars)->steer_y = next.y;
    ((struct seagull_vars *)&(work)->vars)->steer_z = next.z;
    back.x = extra->from.x - ((struct seagull_vars *)&(work)->vars)->steer_x;
    back.y = extra->from.y - ((struct seagull_vars *)&(work)->vars)->steer_y;
    back.z = extra->from.z - ((struct seagull_vars *)&(work)->vars)->steer_z;
    flown.x = work->pos.x - extra->from.x;
    flown.y = work->pos.y - extra->from.y;
    flown.z = work->pos.z - extra->from.z;
    if (njScalor(&back) * 0.5F < njScalor(&flown)) {
        extra->from.x = VARS(work)->steer_x;
        extra->from.y = VARS(work)->steer_y;
        extra->from.z = VARS(work)->steer_z;
        seagull_choose(task);
    }
}

/* the object list's step for O KAMOMEL. it runs as beach_seagull_step does,
 * but draws with seagull_l_draw */
void beach_seagull_l_step(struct task *task)
{
    struct task_work *work = task->work;
    struct seagull_motion *motion = SEAGULL_MOTION(task);
    struct seagull_extra *extra = EXTRA(task);

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case SEAGULL_START:
        work->mode = SEAGULL_FLY;
        motion->home = work->pos;
        extra->from.x = work->pos.x;
        extra->from.y = work->pos.y;
        extra->from.z = work->pos.z;
        seagull_choose(task);
        ((struct seagull_vars *)&(work)->vars)->steer_x =
            (motion->target.x - extra->from.x) * 0.5F;
        ((struct seagull_vars *)&(work)->vars)->steer_y =
            (motion->target.y - extra->from.y) * 0.5F;
        ((struct seagull_vars *)&(work)->vars)->steer_z =
            (motion->target.z - extra->from.z) * 0.5F;
        task->draw = DrawLow;
        break;
    case SEAGULL_FLY:
        if (!OnEdit(task)) {
            Norm(task, motion->unk_04);
            seagull_steer(task);
        }
        (*(Uint16 *)&(work)->timer)++;
        DrawLow(task);
        break;
    case SEAGULL_IDLE:
        break;
    }
}
