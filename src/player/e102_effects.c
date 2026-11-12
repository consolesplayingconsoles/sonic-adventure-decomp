/* @unit 8C0D2620-8C0D31E0 +r04 +egflags +pool32 */
/* E-102's booster, sparks and dust, and helpers his step and other files
 * call */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "collision/mesh.h"
#include "collision/polygon.h"
#include "collision/world.h"
#include "effect/dust.h"
#include "player/e102.h"
#include "player/e102_effects.h"
#include "player/player.h"
#include "system/pad.h"
#include "system/task.h"
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
void *syMalloc_default_malloc(size_t size);
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
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void pdExecPeripheralServerUser(void);
extern PDS_PERIPHERAL perG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
void FUN_8c0d2b40(struct task_work *work, struct task_motion *motion,
                  struct player *record);
void FUN_8c0d3160(struct e102 *e102, int player);
Bool FUN_8c0d317e(struct task *task);
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

/* how far his booster bobs above and below its place */
#define BOOSTER_BOB 1.0F

#define SPARK_STEPS 60 /* the steps a spark flies */

/* the puffs in his landing's ring, and their speed for each unit of the
 * speed he fell at */
#define LANDING_PUFFS 12
#define LANDING_SPEED 1.0F

#define SPARK(work) ((struct spark_vars *)&(work)->vars)
#define SPARK_YAW(work)                                                        \
    (0x8000 - (work)->ang.y +                                                  \
     (Angle)((20.0F - (rand() * RAND_SCALE * 40.0F)) * ANGLE_PER_DEGREE))
#define SPARK_PITCH(work)                                                      \
    ((Angle)((30.0F + (rand() * RAND_SCALE * 30.0F)) * ANGLE_PER_DEGREE) -     \
     (work)->ang.z)
enum spark_mode { SPARK_START, SPARK_FLY };

struct spark_vars {
    Uint8 unk_00[4];
    Sint32 steps; /* steps left to fly */
};
extern struct dust_params e102_dust;
extern NJS_POINT3 e102_spark_points[2];
extern NJS_COLOR e102_spark_colors[2];
extern NJS_POINT3COL e102_spark_line;
extern NJS_VECTOR e102_spark_speed;

void e102_bob_booster(struct task_work *work, struct player *record,
                      struct e102 *e102)
{
    Float speed;
    int tilt;

    speed = CLAMP(_builtin_fabsf(record->speed.x + record->speed.z) - 1.0F,
                  0.0F, 1.0F);
    e102->booster_phase +=
        (Angle)(speed * (12.5F * ANGLE_PER_DEGREE)) + NJM_DEG_ANG(11.25);
    e102->booster_lift = njSin(e102->booster_phase) * BOOSTER_BOB;
    tilt = record->speed.x * (10.0F * ANGLE_PER_DEGREE);
    e102->booster_ang_z = CLAMP(tilt, -NJM_DEG_ANG(25), NJM_DEG_ANG(25));
}

Uint32 e102_floor_flags(struct task_work *work)
{
    struct floor_query query;
    NJS_VECTOR away;
    struct world_object *objects;
    NJS_OBJECT *object;
    Uint32 flags;
    /* @hack type: i a Uint16, which the image zero-extends to index with it and
     * to test it (EXTU.W at 0x8c0db820 and 0x8c0db8d6). as an int, the two
     * EXTU.W go, the function runs 2 bytes short and 22 of 141 words differ */
    Uint16 i;
    Float best;
    Float was;
    Float now;

    flags = 0;
    query.pos = work->pos;
    objects = numLandCollList;
    best = -100000.0F;
    for (i = 0; i < LandCollList; i++) {
        object = objects[i].object;
        /* an object with no owner, the land, is always tested. a task's reach
         * is its model's radius at its largest scale */
        if (objects[i].owner != NULL) {
            Float distance;
            Float size;
            Float reach;

            away.x = object->pos[0] - work->pos.x;
            away.y = 0.0F;
            away.z = object->pos[2] - work->pos.z;
            distance = njScalor(&away);
            size = object->scl[0];
            if (size < object->scl[1]) {
                size = object->scl[1];
            }
            if (size < object->scl[2]) {
                size = object->scl[2];
            }
            reach = size * object->model->r;
            if (distance > reach) {
                continue;
            }
        }
        if (polygon_find_floor(&query, objects[i].object, objects[i].flags)) {
            was = njAbs(work->pos.y - best);
            now = njAbs(work->pos.y - query.floor.level);
            if (was > now) {
                best = query.floor.level;
                /* a task's floor counts where its force moves it this step */
                if (objects[i].owner != NULL) {
                    best +=
                        ((struct task_force *)objects[i].owner->force)->speed.y;
                }
                flags = objects[i].flags;
            }
        }
    }
    return flags;
}

/* the turns that send a spark off. its yaw is back from the way it faces,
 * up to 20 degrees to either side. its pitch is 30 to 60 degrees up, less
 * its ang.z. each read draws a rand() of its own: e102_spark_step reads the
 * yaw up to three times and the pitch twice */

/* a spark. it leaves with 1 to 3 added to its starting speed, back from
 * the way it faces and upward, then falls and spins for SPARK_STEPS */
void e102_spark_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    NJS_VECTOR speed;
    int i;

    switch (work->mode) {
    case SPARK_START:
        njPushMatrix(&nj_unit_matrix_);
        e102_spark_speed.x = 1.0F + (rand() * RAND_SCALE * 2.0F);
        SPARK_YAW(work) ? TURN(njRotateY, SPARK_YAW(work)) : (void)0;
        TURN(njRotateZ, SPARK_PITCH(work));
        njCalcVector(NULL, &e102_spark_speed, &speed);
        njAddVector(&motion->speed, &speed);
        late_DrawObjectClipEx(1);
        work->ang.x = (Angle)(rand() * RAND_SCALE * 360.0F * ANGLE_PER_DEGREE);
        work->ang.y = (Angle)(rand() * RAND_SCALE * 360.0F * ANGLE_PER_DEGREE);
        SPARK(work)->steps = SPARK_STEPS;
        work->mode = SPARK_FLY;
        break;
    case SPARK_FLY:
        SPARK(work)->steps--;
        if (SPARK(work)->steps <= 0) {
            DestroyTask(task);
            return;
        }
        work->ang.x += 0x2000;
        work->ang.y += 0x2000;
        motion->speed.y -= 9.8F / 60.0F;
        njAddVector(&work->pos, &motion->speed);
        break;
    }
    njPushMatrix(NULL);
    for (i = 0; i < 2; i++) {
        e102_spark_colors[i].argb.r = 96.0F + (rand() * RAND_SCALE * 160.0F);
        e102_spark_colors[i].argb.g = 96.0F + (rand() * RAND_SCALE * 160.0F);
        e102_spark_colors[i].argb.b = rand() * RAND_SCALE * 128.0F;
    }
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njDrawLine3D(&e102_spark_line, 1, NJD_TRANSPARENT);
    late_DrawObjectClipEx(1);
}

/* each spark starts by a foot's weld point, with his speed and angles */
void FUN_8c0d2b40(struct task_work *work, struct task_motion *motion,
                  struct player *record)
{
    NJS_POINT3 skates[2];
    struct collision_shape *shape;
    struct task *task;
    int i;
    int j;

    if (work->flags & PLAYER_ON_GROUND) {
        njPushMatrix(&nj_unit_matrix_);
        shape = work->collision->shapes;
        TURN(njRotateZ, work->ang.z);
        TURN(njRotateX, work->ang.x);
        TURN(njRotateY, 0x8000 - work->ang.y);
        njTranslate(NULL, -4.0F, -3.0F, 0.0F);
        njCalcPoint(NULL, &record->weld_point3, &skates[0]);
        njAddVector(&skates[0], &shape->center);
        njCalcPoint(NULL, &record->weld_point2, &skates[1]);
        njAddVector(&skates[1], &shape->center);
        late_DrawObjectClipEx(1);
        /* @hack redundant: a loop of one pass round the pair, which counts j
         * down in R9 (MOV #1,R9 and DT R9 at 0x8c0dbd14, 0x8c0dbd66). without
         * it, 138 of 143 words differ */
        for (j = 1; j != 0; j--) {
            for (i = 0; i < 2; i++) {
                task = CreateElementalTask(TASK_MOTION | TASK_WORK, 5,
                                           e102_spark_step);
                if (task != NULL) {
                    task->work->pos = skates[i];
                    task->motion->speed = motion->speed;
                    task->work->ang = work->ang;
                }
            }
        }
    }
}

/* one puff, at a random point 7 from a spot 10 behind him. it's bigger the
 * lower he is */
void e102_hover_dust(struct task_work *work, Float ground)
{
    Float height = work->pos.y - ground;
    Angle heading = work->ang.y;
    Float back_x = -njCos(heading) * 10.0F;
    Float back_z = -njSin(heading) * 10.0F;

    if (height > 0.0F && height < 30.0F) {
        Angle ang =
            (Angle)(rand() * (RAND_SCALE * (2 * NJD_PI) * ANGLE_PER_RADIAN));
        Float speed = (21.0F - height) * 0.25F;

        e102_dust.scale = 0.5F + (speed * 0.1F);
        e102_dust.pos.x = work->pos.x + back_x + (njCos(ang) * 7.0F);
        e102_dust.pos.y = ground + 1.5F;
        e102_dust.pos.z = work->pos.z + back_z + (njSin(ang) * 7.0F);
        e102_dust.speed.x = speed * ((rand() * RAND_SCALE) - 0.5F);
        e102_dust.speed.y = 0.0F;
        e102_dust.speed.z = speed * ((rand() * RAND_SCALE) - 0.5F);
        dust_create_glow(&e102_dust);
    }
}

/* LANDING_PUFFS puffs, evenly round him 7 out */
void e102_landing_dust(struct task_work *work, struct task_motion *motion)
{
    int i;
    Float speed;

    for (i = 0; i < LANDING_PUFFS; i++) {
        Angle ang =
            (Angle)(i * ((2 * NJD_PI / LANDING_PUFFS) * ANGLE_PER_RADIAN));

        speed = _builtin_fabsf(motion->speed.y) * LANDING_SPEED;
        e102_dust.scale = 0.5F + (speed * 0.1F);
        e102_dust.pos.x = work->pos.x + (njCos(ang) * 7.0F);
        e102_dust.pos.y = work->pos.y + 1.5F;
        e102_dust.pos.z = work->pos.z + (njSin(ang) * 7.0F);
        e102_dust.speed.x = speed * ((rand() * RAND_SCALE) - 0.5F);
        e102_dust.speed.y = 0.0F;
        e102_dust.speed.z = speed * ((rand() * RAND_SCALE) - 0.5F);
        dust_create_glow(&e102_dust);
    }
}

void e102_record_stick(struct e102 *e102, int player, Bool lag)
{
    struct pad_stick *stick = e102->sticks;
    int i;

    for (i = 0; i < E102_STICK_STEPS - 1; i++) {
        *stick = stick[1];
        stick++;
    }
    *stick = input_dataG[player];
    if (lag) {
        input_dataG[player].ang = e102->sticks[0].ang;
        input_dataG[player].stroke = e102->sticks[0].stroke;
    }
}

void FUN_8c0d3160(struct e102 *e102, int player)
{
    input_dataG[player].ang = e102->sticks[E102_STICK_STEPS - 1].ang;
    input_dataG[player].stroke = e102->sticks[E102_STICK_STEPS - 1].stroke;
}

Bool FUN_8c0d317e(struct task *task)
{
    struct task_motion *motion = task->motion;
    struct player *record = motion->record;
    struct e102 *e102 = record->own.e102.record[0];

    return e102->aim_mode == E102_AIM_START ||
           e102->aim_mode == E102_AIM_LOCKING;
}

void e102_set_skating(int player)
{
    struct task_work *work = playertwp[player];

    work->mode = E102_SKATE_START;
}
