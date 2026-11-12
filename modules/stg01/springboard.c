/* @unit 0C904F50-0C905CA0 +r04 +egflags +pool32 +poolafter=FUN_0c9050ca,Object_beach_gomubane_End +asmfunc=CalcBaneTopPoint:+0c9050ca,springboard_init:+0c905224,Object_beach_gomubane_Exec:+0c905af4,Object_beach_gomubane_Draw:+0c905ca0 */
/* O GOMBAN springboard, a board that bends under a player and springs
 * back */
#include "stg01/springboard.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/sound.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
#include "vmu/vibration.h"
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <string.h>
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c6409c0(Int loc, Int val, Int digit);
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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
void VibShot(int pad, int power, int freq, int time);
float njArcTan2(float y, float x);
float njFloor(float x);

/* the board's state, in work->vars. work->submode holds the number of the
 * player it pushes, and work->tick its chain id. scl.z holds the speed of its
 * deflection. work->timer counts the steps since a player last touched it, up
 * to 0x7fff */
#define SPRING_REFLECT 0x8 /* the board throws a player */
#define SPRING_REFLECT_45 0x10
#define SPRING_RUBBER 0x4
#define STRETCH_RUBBER 0x1
#define STRETCH_CORD 0x2 /* the push grows as the stretch squared */
#define SPRING_FEEDBACK 0x40 /* the push has played its sound and vibration */
#define SPRING_BOUNCED 0x80 /* the push has thrown its player */
#define FEEDBACK_DEFLECTION 0.8F
#define THROW_DEFLECTION 1.0F
#define THROW_SPEED 0.2F
#define SE_SPRINGBOARD 46
#define POWER_MOST 6
#define AIM_45_MASK 0x6000
#define NEXT_REACH NJM_DEG_ANG(67.5)
#define LAUNCH_STEPS 30
#define HALF_SPAN 34.0F
#define BOARD_POINTS 15
#define BENT_DEFLECTION 4.95F
#define APEX_REACH 3.5F
#define CHAIN_BOARDS 20
#define SHAPES_REACH 39.0F
#define SPRING(work) ((struct springboard_vars *)&(work)->vars)
struct springboard_vars {
    /* the heading the player came in at, in the board's frame, mirrored
     * across its x axis. a throw sends the player the opposite way, which
     * reflects it off the board */
    Uint16 aim;
    Uint16 flags;
    /* how far the board's middle is pushed along its x axis, to meet the
     * player's ball */
    Float deflection;
    /* where along its z axis, its span, the board's bend peaks */
    Float apex;
};
extern const char reflect_bane45[20];
extern const char reflect_bane[20];
extern const char reflect_gomu[20];
extern const char stretch_himo[20];
extern const char stretch_gomu[20];
extern const char chain_label[4];
extern const NJS_POINT3 board_middle;
extern struct task *active_springboard[2];
extern int nusobaneref;
extern struct collision_shape springboard_shapes[3];
extern struct task_work *usobanetwp[20];

void springboard_init(struct task *task);
void Object_beach_gomubane_End(struct task *task);
void Object_beach_gomubane_Exec(struct task *task);
void Object_beach_gomubane_Draw(struct task *task);

/* whether a player's ball, at position with radius and moving at velocity,
 * touches the board. a board untouched on the previous step picks the side
 * from the ball's x against its x speed. it also sets *aim from the ball's
 * heading. a board touched then keeps the side of that touch. a touch sets
 * *deflection to put the board's face against the ball. it sets *apex to the
 * ball's z in the board's frame */
int CalcBaneTopPoint(NJS_POINT3 *position, Float radius, NJS_VECTOR *velocity,
                     NJS_POINT3 *unused, Float *deflection, Float *apex,
                     struct task_work *work, int *aim)
{
    int hit = 0;
    NJS_POINT3 local_position;
    NJS_VECTOR local_velocity;
    Angle angle;
    njPushMatrix(&nj_unit_matrix_);
    njTranslate(0, -4.12F, -8.4F, -0.0F);
    TURN_VIA(njRotateY, -work->ang.y, angle);
    njTranslate(0, -work->pos.x, -work->pos.y, -work->pos.z);
    njCalcVector(0, velocity, &local_velocity);
    njCalcPoint(0, position, &local_position);
    late_DrawObjectClipEx(1);
    if (TASK_TIMER(work) > 1) {
        if (local_position.x <= radius && local_position.x > local_velocity.x) {
            *deflection = local_position.x - radius;
            hit = 1;
            *aim = (int)(njArcTan2(local_velocity.z, local_velocity.x) *
                         ANGLE_PER_RADIAN);
        } else if (local_position.x >= -radius &&
                   local_position.x < local_velocity.x) {
            *deflection = local_position.x + radius;
            hit = 1;
            *aim = (int)(njArcTan2(local_velocity.z, local_velocity.x) *
                         ANGLE_PER_RADIAN);
        }
    } else if (SPRING(work)->deflection < 0.0F) {
        if (local_position.x <= radius) {
            *deflection = local_position.x - radius;
            hit = 1;
        }
    } else {
        if (local_position.x >= -radius) {
            *deflection = local_position.x + radius;
            hit = 1;
        }
    }
    if (!hit) {
        return 0;
    }
    *apex = local_position.z;
    return 1;
}

void read_settings(Float reflect, Float stretch, struct task_work *work)
{
    SPRING(work)->flags = 0;
    switch ((Sint8)reflect % 3) {
    case 0:
        SPRING(work)->flags |= SPRING_REFLECT;
        break;
    case 1:
        SPRING(work)->flags |= SPRING_REFLECT;
        SPRING(work)->flags |= SPRING_REFLECT_45;
        break;
    case 2:
        SPRING(work)->flags |= SPRING_RUBBER;
        break;
    }
    switch ((Sint8)stretch % 3) {
    case 0:
        SPRING(work)->flags |= STRETCH_RUBBER;
        break;
    case 1:
        SPRING(work)->flags |= STRETCH_CORD;
        break;
    }
}

void Object_beach_gomubane_Init(struct task *task)
{
    /* @hack spelling: current, a copy of task, which keeps task in R14
     * across the range check (MOV R4,R14 at 0x0c90536a). without it, 10 of 14
     * words differ and springboard_init moves */
    struct task *current = task;
    if (!CheckRangeOut(current)) {
        springboard_init(current);
    }
}

void springboard_init(struct task *task)
{
    struct task_work *work = task->work;
    int i;
    if (!OnEdit(task)) {
        CCL_Init(task, springboard_shapes, COLLISION_OBJECT, 1, 3);
    }
    task->draw = Object_beach_gomubane_Draw;
    task->step = Object_beach_gomubane_Exec;
    task->destructor = Object_beach_gomubane_End;
    read_settings(work->scl.x, work->scl.y, work);
    work->tick = (Sint8)work->scl.z;
    work->timer = 2;
    SPRING(work)->deflection = 0.0F;
    SPRING(work)->apex = 0.0F;
    work->scl.z = 0.0F;
    if (nusobaneref++ == 0) {
        memset((void *)usobanetwp, 0, sizeof(usobanetwp));
    }
    if (work->tick) {
        /* @hack redundant: a goto to the next statement, which loads each slot
         * into R2 rather than R3 (MOV.L @R5,R2 at 0x0c9053fc). without it, 2 of
         * 77 words differ */
        goto entries;
    entries:
        for (i = 0; i < CHAIN_BOARDS; ++i) {
            if (usobanetwp[i] == 0) {
                usobanetwp[i] = work;
                return;
            }
        }
    }
}

void Object_beach_gomubane_End(struct task *task)
{
    struct task_work *work = task->work;
    int i;
    --nusobaneref;
    for (i = 0; i < CHAIN_BOARDS; ++i) {
        if (usobanetwp[i] == work) {
            usobanetwp[i] = 0;
        }
    }
    for (i = 0; i < 2; ++i) {
        if (active_springboard[i] == task) {
            active_springboard[i] = 0;
        }
    }
}

/* push a player that touches the board. the board bends to meet the player's
 * ball. it pushes the player toward its middle, harder as it stretches more.
 * untouched, the board springs back to rest */
void Object_beach_gomubane_Exec(struct task *task)
{
    struct task_work *work = task->work;
    Float deflection = SPRING(work)->deflection;
    Float apex = SPRING(work)->apex;
    Float velocity = work->scl.z;
    Sint8 number = work->submode;
    Sint16 timer = work->timer;
    struct task_work *rider = playertwp[number];
    struct player *player = GetPlayerWorkPointer(number);
    NJS_POINT3 point;
    NJS_POINT3 difference;
    Angle angle;
    int untouched;
    int aim;
    Angle launch_aim;
    Float x;
    Float z;
    Float length;
    Float factor;
    Float radius;
    Sint16 power;
    int i;
    struct task_work *next;

    /* @hack redundant: a never-run test of timer, which gives timer R12, as in
     * the image; without it, 48 of 836 words differ */
    if (0) {
        if (timer) {
        }
    }
    /* @hack redundant: the same for player, which gives player R11; without it,
     * 39 of 836 words differ */
    if (0) {
        if (player) {
        }
    }
    if (CheckRangeOut(task)) {
        return;
    }
    if (OnEdit(task)) {
        read_settings(work->scl.x, work->scl.y, work);
        work->tick = (Sint8)work->scl.z;
        work->timer = 0;
        SPRING(work)->deflection = 0.0F;
        SPRING(work)->apex = 0.0F;
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_X),
                 (SPRING(work)->flags & SPRING_REFLECT)
                     ? (SPRING(work)->flags & SPRING_REFLECT_45 ? reflect_bane45
                                                                : reflect_bane)
                     : reflect_gomu);
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Y),
                 SPRING(work)->flags & STRETCH_CORD ? stretch_himo
                                                    : stretch_gomu);
        njPrintC(((18) << 16 | ((21))), chain_label);
        FUN_8c6409c0(((22) << 16 | (21)), work->tick, 2);
        Object_beach_gomubane_Draw(task);
        return;
    }
    Object_beach_gomubane_Draw(task);
    if ((work->collision->flags & COLLISION_HIT) &&
        work->collision->own_shape == 2 &&
        (timer > 1 || work->collision->hit->owner->work == rider)) {
        aim = SPRING(work)->aim;
        if (timer > 1) {
            number = GetTheNearestPlayerNumber(&work->pos);
            rider = playertwp[number];
            player = GetPlayerWorkPointer(number);
        }
        if (CalcBaneTopPoint(&rider->pos, player->consts.radius * 0.9F,
                             &playermwp[number]->speed, &point, &deflection,
                             &apex, work, &aim)) {
            timer = 0;
        }
        SPRING(work)->aim = aim;
    }
    /* @hack spelling: timer copied to untouched, an int, which the image
     * keeps at sp+8 for the second test (MOV.L R3,@(8,R15) at 0x0c9056b0);
     * tested as timer, 147 of 836 words differ */
    untouched = timer;
    if (!untouched || deflection > 0.1F || apex > 0.1F) {
        work->collision->shapes[2].center.x =
            springboard_shapes[2].center.x + deflection;
        work->collision->shapes[2].center.z =
            springboard_shapes[2].center.z + apex;
    }
    x = work->collision->shapes[2].center.x;
    z = work->collision->shapes[2].center.z;
    radius = njSqrt((x * x) + (z * z));
    radius += SHAPES_REACH;
    work->collision->radius = radius;
    EntryColliList(work);
    if (untouched > 0 || (active_springboard[number] != 0 &&
                          active_springboard[number] != task)) {
        if (active_springboard[number] == task) {
            active_springboard[number] = 0;
        }
        if (njAbs(apex) < 0.1F) {
            apex = 0.0F;
        }
        if (njAbs(velocity) < 0.1F) {
            velocity = 0.0F;
        }
        if (apex == 0.0F && velocity == 0.0F && njAbs(deflection) < 0.1F) {
            deflection = 0.0F;
        } else {
            apex *= 0.92F;
            velocity += -deflection * 0.5F;
            velocity *= 0.95F;
            deflection += velocity;
        }
        SPRING(work)->flags &= ~SPRING_BOUNCED;
        SPRING(work)->flags &= ~SPRING_FEEDBACK;
    } else {
        /* @hack redundant: the second test of deflection, which repeats the
         * first and so never decides; the image tests it twice (0x0c905840,
         * 0x0c905848). without it, the function shrinks, springboard_draw
         * moves, and 514 of 836 words differ */
        /* NOLINTNEXTLINE(misc-redundant-expression) */
        if (njAbs(deflection) > 0.1F || njAbs(deflection) > 0.1F) {
            /* the point the player is pushed toward. it lies 0.9 of the
             * player's radius out from the board's middle, on the player's
             * side. along z it lies 0.8 of the way to the apex. board_middle's
             * z is 0, so both arms below set the same z */
            point = board_middle;
            if (deflection < 0.0F) {
                point.x += player->consts.radius * 0.9F;
            } else {
                point.x -= player->consts.radius * 0.9F;
            }
            if (velocity < 0.0F) {
                point.z += apex * 0.8F;
            } else {
                point.z = apex * 0.8F;
            }
            /* the stretch: the two halves' lengths, from the apex to either
             * end, less the board's length at rest */
            x = HALF_SPAN - apex;
            z = -HALF_SPAN - apex;
            length = njSqrt((deflection * deflection) + (x * x)) +
                     njSqrt((deflection * deflection) + (z * z)) -
                     (2.0F * HALF_SPAN);

            /* @hack redundant: a never-run test of x, which puts x in FR15
             * ahead of z in FR13; without it, 13 of 836 words differ */
            if (0) {
                if (x) {
                }
            }
            /* velocity, the deflection's speed, takes the push's speed here.
             * the step sets it back to the deflection's speed before it
             * stores it in scl.z */
            if (SPRING(work)->flags & STRETCH_CORD) {
                velocity = length * length * 0.02F;
            } else {
                velocity = length * 0.02F;
            }
            njPushMatrix(&nj_unit_matrix_);
            njTranslateV(0, &work->pos);
            TURN_VIA(njRotateY, work->ang.y, angle);
            njCalcPoint(0, &point, &point);
            late_DrawObjectClipEx(1);
            {
                /* @hack spelling: out, from and other, byte cursors over
                 * difference, point and the rider's pos, which keep task in R10
                 * (MOV R4,R10 at 0x0c9054e0). without them, 371 of 836 words
                 * differ */
                unsigned char *out = (unsigned char *)&difference;
                unsigned char *from = (unsigned char *)&point;
                unsigned char *other = (unsigned char *)&rider->pos;

                /* @hack redundant: a never-run test of other, which puts other
                 * in R4, from in R5 and out in R6; without it, 11 of 836 words
                 * differ */
                if (0) {
                    if (other) {
                    }
                }
                *(Float *)out = *(Float *)from - *(Float *)other;
                from += sizeof(Float);
                other += sizeof(Float);
                *(Float *)(out += sizeof(Float)) =
                    *(Float *)from - *(Float *)other;
                out += sizeof(Float);
                from += sizeof(Float);
                other += sizeof(Float);
                *(Float *)out = *(Float *)from - *(Float *)other;
            }
            difference.y = 0.0F;
            length = njScalor(&difference);
            factor = velocity / length;
            {
                /* @hack spelling: out, a byte cursor over difference, which SHC
                 * forms on the stack (ADD #20,R4 at 0x0c9059d4). without it,
                 * 193 of 836 words differ */
                unsigned char *out = (unsigned char *)&difference;

                /* @hack redundant: an empty never-run branch, which puts the
                 * first product in FR3; without it, 3 of 836 words differ */
                if (0) {
                }
                *(Float *)out *= factor;
                out += sizeof(Float);
                /* @hack redundant: the same, which orders the next two
                 * products' scratch registers; without it, 6 of 836 words
                 * differ */
                if (0) {
                }
                *(Float *)out *= factor;
                out += sizeof(Float);
                *(Float *)out *= factor;
            }
            active_springboard[number] = task;
            player_push(number, difference.x, difference.y, difference.z);
            if (velocity > player->consts.gravity) {
                playermwp[number]->accel.y += player->consts.gravity;
            }
        }
        if (njAbs(deflection) > FEEDBACK_DEFLECTION &&
            !(SPRING(work)->flags & SPRING_FEEDBACK) &&
            ((work->scl.z < 0.0F && SPRING(work)->deflection <= deflection) ||
             (work->scl.z > 0.0F && SPRING(work)->deflection >= deflection))) {
            power = (Sint16)(njAbs(deflection) * 0.25F) + 1;
            if (power > POWER_MOST) {
                power = POWER_MOST;
            }
            dsPlay_oneshot(SE_SPRINGBOARD, 0, 0, 0);
            VibShot(0, power, (power * 2) + 10, 0);
            SPRING(work)->flags |= SPRING_FEEDBACK;
        }
        if (njAbs(deflection) > THROW_DEFLECTION &&
            !(SPRING(work)->flags & SPRING_BOUNCED) &&
            (SPRING(work)->flags & SPRING_REFLECT) &&
            ((work->scl.z < 0.0F && SPRING(work)->deflection <= deflection) ||
             (work->scl.z > 0.0F && SPRING(work)->deflection >= deflection))) {
            point = playermwp[number]->speed;
            length = njScalor(&point);
            if (length > THROW_SPEED) {
                factor = -3.5F - (length * 1.2F);
                if (factor < -7.0F) {
                    factor = -7.0F;
                }
                if (SPRING(work)->flags & SPRING_REFLECT_45) {
                    /* @hack spelling: aim through a pointer, which forms its
                     * address in R4 (ADD #8,R4 at 0x0c905b84). without it, 17
                     * of 836 words differ */
                    Uint16 *turn = &SPRING(work)->aim;
                    *turn &= AIM_45_MASK;
                    launch_aim = (Sint16)*turn;
                } else {
                    launch_aim = SPRING(work)->aim;
                }
                if (work->tick) {
                    struct task_work **entry;
                    struct task_work **entries;
                    for (entries = usobanetwp, entry = usobanetwp, i = 0;
                         i < CHAIN_BOARDS; ++i, ++entry) {
                        if ((next = *entries++) &&
                            next->tick == work->tick + 1) {
                            {
                                /* @hack spelling: out, from and other, byte
                                 * cursors over point, the listed board's pos
                                 * and the rider's, which keep task in R10 (MOV
                                 * R4,R10 at 0x0c9054e0). without them, 304 of
                                 * 836 words differ */
                                unsigned char *out = (unsigned char *)&point;
                                unsigned char *from =
                                    (unsigned char *)&(*entry)->pos;
                                unsigned char *other =
                                    (unsigned char *)&rider->pos;

                                /* @hack redundant: a never-run test of from,
                                 * which puts from in R4, out in R5 and other in
                                 * R6; without it, 125 of 836 words differ */
                                if (0) {
                                    if (from) {
                                    }
                                }
                                *(Float *)out =
                                    *(Float *)from - *(Float *)other;
                                out += sizeof(Float);
                                from += sizeof(Float);
                                *(Float *)out =
                                    *(Float *)from -
                                    *(Float *)(other += sizeof(Float));
                                out += sizeof(Float);
                                from += sizeof(Float);
                                other += sizeof(Float);
                                *(Float *)out =
                                    *(Float *)from - *(Float *)other;
                            }
                            angle = -(int)(njArcTan2(point.z, point.x) *
                                           ANGLE_PER_RADIAN) -
                                    work->ang.y + NJM_DEG_ANG(180);
                            {
                                Sint16 delta = angle - launch_aim;
                                if (delta < NEXT_REACH && delta > -NEXT_REACH) {
                                    launch_aim = angle;
                                }
                            }
                            break;
                        }
                    }
                }
                point.x = factor;
                point.y = 0.0F;
                point.z = 0.0F;
                njPushMatrix(&nj_unit_matrix_);
                TURN_VIA(njRotateY, work->ang.y + launch_aim, angle);
                njCalcVector(0, &point, &point);
                late_DrawObjectClipEx(1);
                angle = -(int)(njArcTan2(point.z, point.x) * ANGLE_PER_RADIAN);
                player_set_angles(number, 0, angle + NJM_DEG_ANG(90), 0);
                player_bounce(number, point.x, point.y, point.z);

                player->launch_steps = LAUNCH_STEPS;
                SPRING(work)->flags |= SPRING_BOUNCED;
            }
        }
        velocity = deflection - SPRING(work)->deflection;
    }
    if (++timer <= 0) {
        --timer;
    }
    SPRING(work)->deflection = deflection;
    work->scl.z = velocity;
    SPRING(work)->apex = apex;
    work->submode = number;
    work->timer = timer;
}

/* draw the frame, and the board blended between its rest shape and its bent
 * one by its deflection. the board's points near its middle move along z by
 * the apex */
void Object_beach_gomubane_Draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = &beach_springboard_object;
    NJS_POINT3 points[BOARD_POINTS];
    /* @hack spelling: from, to and out, byte cursors over the rest shape, the
     * bent one and points, which read each Float with a post-increment (FMOV.S
     * @R6+,FR8 at 0x0c905e90). as NJS_POINT3 pointers, 67 of 136 words
     * differ */
    const unsigned char *from;
    const unsigned char *to;
    unsigned char *out;
    NJS_POINT3 *original;
    NJS_POINT3 *mesh;
    NJS_MODEL *model;
    Angle angle;
    Float ratio;
    Float apex;
    NJS_OBJECT *sibling;
    Float x;
    Float y;
    Float z;
    Float from_x;
    Float from_y;
    Float from_z;
    Float to_x;
    Float to_y;
    Float to_z;
    int i;
    if (CheckRangeOut(task)) {
        return;
    }
    SetObjectTexture();
    njPushMatrix(0);
    njTranslateV(0, &work->pos);

    TURN_VIA(njRotateY, work->ang.y, angle);
    ds_DrawModelClip(object->model);
    object = object->child;
    if (SPRING(work)->deflection == 0.0F && SPRING(work)->apex == 0.0F) {
        njTranslate(0, 4.12F, 8.4F, 0.0F);
        ds_DrawModelClip(object->model);
    } else {
        sibling = object->sibling;
        mesh = points;
        out = (unsigned char *)mesh;
        from = (const unsigned char *)(model = object->model)->points;
        original = model->points;
        to = (const unsigned char *)sibling->model->points;
        /* the model points at the local copy only until draw_model below has
         * drawn it */
        model->points = mesh;
        ratio = -SPRING(work)->deflection * (1.0F / BENT_DEFLECTION);
        apex = SPRING(work)->apex;
        for (i = BOARD_POINTS; i != 0; --i) {
            from_x = *(const Float *)from;
            from += sizeof(Float);
            from_y = *(const Float *)from;
            from += sizeof(Float);
            from_z = *(const Float *)from;
            from += sizeof(Float);
            to_x = *(const Float *)to;
            to += sizeof(Float);
            to_y = *(const Float *)to;
            to += sizeof(Float);
            to_z = *(const Float *)to;
            to += sizeof(Float);
            x = from_x + ((to_x - from_x) * ratio);
            y = from_y + ((to_y - from_y) * ratio);
            z = from_z + ((to_z - from_z) * ratio);
            if (njAbs(z) < APEX_REACH) {
                z += apex;
            }
            *(Float *)out = x;
            out += sizeof(Float);
            *(Float *)out = y;
            out += sizeof(Float);
            *(Float *)out = z;
            out += sizeof(Float);
        }

        /* @hack redundant: three never-run reads of y, which keep the cursors
         * from, to and out in R6, R5 and R4 (0x0c905e90, 0x0c905e92,
         * 0x0c905ebe) and APEX_REACH in FR11 (0x0c905e8a); without them, the
         * cursors take R5, R4 and R6, APEX_REACH takes FR10 and 25 of 136
         * words differ */
        if (0) {
            if (y) {
            }
            if (y) {
            }
            if (y) {
            }
        }
        njTranslate(0, 4.12F, 8.4F, 0.0F);
        ds_DrawModelClip(object->model);
        object->model->points = original;
    }
    late_DrawObjectClipEx(1);
}
