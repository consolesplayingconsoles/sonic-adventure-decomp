/* @unit 0C903D40-0C9042C0 +r04 +egflags +pool32 */
/* the Egg Hornet's shots: volleys of missiles that curve toward a target.
 * the launchers at the boss's two sides fire by turns. each missile sets out
 * its own way and curves round to the target. it blows up where its curve
 * ends */
#include <ninja.h>
#include <sg_xpt.h>

#include "b_egm1/hornet_textures.h"
#include "b_egm1/rumble.h"
#include "b_egm1/shots.h"
#include "b_egm1/texlists.h"
#include "b_egm1/util.h"
#include "collision/collision.h"
#include "draw/tree.h"
#include "effect/bomb.h"
#include "effect/dust.h"
#include "sound/sound.h"
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
extern NJS_MATRIX nj_unit_matrix_;
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
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke2(struct dust_params *params);
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

#define SE_SHOT 455
#define SE_SHOT_BLAST 456
#define SHOT_PITCH NJM_DEG_ANG(25)
#define LAUNCHER_X 28.36F
#define LAUNCHER_Y 3.9F
#define LAUNCHER_Z 3.0F
#define TRAIL_EVERY 2
#define TRAIL_SCALE 0.5F
struct missile {
    struct curve path;
    NJS_POINT3 *target;
    Float time; /* along path, from 0 to 1 */
    Float time_step; /* what each step adds to time */
    Uint16 trail_timer; /* the steps since the last puff of its trail */
    Uint16 follow_steps; /* the steps left in which path's end follows target */
};

struct volley_record {
    struct volley volley;
    Uint16 timer; /* the steps since the volley began */
    Uint16 fired; /* the shots fired so far */
};
extern const struct angles egg_hornet_volley_angles[6];
extern Float egg_hornet_missile_speed;
extern Sint32 egg_hornet_missile_volume;
extern struct collision_shape egg_hornet_missile_shape;
/* clang-format on */

void egg_hornet_missile_draw(struct task *task);

/* *pos gets the launcher on side 0 or side 1. its offset from the boss is
 * turned by work->ang.y and moved to work->pos */
void Flicky_detectAim(struct task_work *work, NJS_POINT3 *pos, int side)
{
    NJS_MATRIX matrix;
    NJS_VECTOR offset;

    njUnitMatrix(&matrix);
    TURN_MATRIX(njRotateY, &matrix, work->ang.y);
    offset.x = side ? LAUNCHER_X : -LAUNCHER_X;
    offset.y = LAUNCHER_Y;
    offset.z = LAUNCHER_Z;
    njCalcVector(&matrix, &offset, pos);
    pos->x += work->pos.x;
    pos->y += work->pos.y;
    pos->z += work->pos.z;
}

void egg_hornet_missile_step(struct task *task)
{
    struct missile *missile = task->extra;
    struct task_work *work = task->work;
    NJS_VECTOR moved;

    missile->time += missile->time_step;
    if (missile->time >= 1.0F) {
        dsPlay_oneshot_v(SE_SHOT_BLAST, 0, 0, egg_hornet_missile_volume,
                         work->pos.x, work->pos.y, work->pos.z);
        CreateBomb(&work->pos, 1.0F);
        rumble_weak();
        FreeTask(task);
    } else {
        if (missile->follow_steps > 0) {
            --missile->follow_steps;
            missile->path.end.x = missile->target->x;
            missile->path.end.y = missile->target->y;
            missile->path.end.z = missile->target->z;
        }
        VECTOR_COPY(&moved, &work->pos);
        curve_point(&work->pos, &missile->path, missile->time);
        VECTOR_DIFF(&moved, &work->pos, &moved);
        work->ang.y = vector_yaw(&moved);
        work->ang.x = vector_pitch(&moved);
        if (work->ang.x < -SHOT_PITCH) {
            work->ang.x = -SHOT_PITCH;
        }
        if (work->ang.x > SHOT_PITCH) {
            work->ang.x = SHOT_PITCH;
        }
        if (++missile->trail_timer >= TRAIL_EVERY) {
            moved.x = -moved.x;
            moved.y = -moved.y;
            moved.z = -moved.z;
            CreateSmoke(&work->pos, &moved, TRAIL_SCALE);
            missile->trail_timer = 0;
        }
        EntryColliList(work);
        egg_hornet_missile_draw(task);
    }
}

void egg_hornet_missile_draw(struct task *task)
{
    struct task_work *work = task->work;

    njSetTexture_jp(&egm1mis_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateX, work->ang.x);
    late_DrawObject(&egg_hornet_missile_object);
    late_DrawObjectClipEx(1);
}

/* fire a missile from pos along a curve to *target. the curve's control
 * point is pos plus half the line to the target, turned by ang. the curve's
 * end follows *target for the missile's first follow_steps steps */
void egg_hornet_missile_create(NJS_POINT3 *pos, NJS_POINT3 *target,
                               const struct angles *ang, Uint16 follow_steps)
{
    struct task *task;
    struct task_work *work;
    struct missile *missile;
    NJS_MATRIX matrix;
    NJS_VECTOR half;
    NJS_VECTOR out;
    Float length;

    if ((task = CreateElementalTask(TASK_WORK, 3, egg_hornet_missile_step)) ==
        NULL) {
        return;
    }
    work = task->work;
    CCL_Init(task, &egg_hornet_missile_shape, COLLISION_ITEM, 1, 1);
    work->collision->flags &= ~COLLISION_TARGET;
    task->extra = missile = CAlloc(1, sizeof(struct missile));
    missile->target = target;
    missile->path.start.x = pos->x;
    missile->path.start.y = pos->y;
    missile->path.start.z = pos->z;
    missile->path.end.x = missile->target->x;
    missile->path.end.y = missile->target->y;
    missile->path.end.z = missile->target->z;
    missile->time = 0.0F;
    half.x = (target->x - pos->x) * 0.5F;
    half.y = (target->y - pos->y) * 0.5F;
    half.z = (target->z - pos->z) * 0.5F;
    if ((length = njScalor(&half)) > 0.0F) {
        missile->time_step = egg_hornet_missile_speed / length;
    } else {
        missile->time_step = 1.0F;
    }
    njUnitMatrix(&matrix);
    TURN_MATRIX(njRotateY, &matrix, ang->y);
    TURN_MATRIX(njRotateX, &matrix, ang->x);
    njCalcVector(&matrix, &half, &out);
    VECTOR_SUM(&missile->path.control, &out, pos);
    missile->follow_steps = follow_steps;
    work->pos.x = pos->x;
    work->pos.y = pos->y;
    work->pos.z = pos->z;
    work->ang.y = vector_yaw(&half);
    work->ang.x = work->ang.z = 0;
    task->step = egg_hornet_missile_step;
    task->draw = egg_hornet_missile_draw;
}

/* fire shot n once the volley has run more than n * interval steps. side
 * n & 1 fires it, and the volley ends after its last shot */
void egg_hornet_volley_step(struct task *task)
{
    struct volley_record *record = task->extra;
    Uint16 delay = record->fired * record->volley.interval;
    NJS_POINT3 pos;
    struct task_work *owner;

    if (++record->timer > delay) {
        owner = record->volley.owner;
        Flicky_detectAim(owner, &pos, record->fired & 1);
        egg_hornet_missile_create(
            &pos, record->volley.target,
            &egg_hornet_volley_angles[record->fired],
            (record->fired * record->volley.follow_interval) - delay);
        dsPlay_oneshot(SE_SHOT, 0, 0, 0);
        if (++record->fired >= record->volley.count) {
            FreeTask(task);
        }
    }
}

void egg_hornet_volley_create(struct volley *volley)
{
    struct task *task;
    struct volley_record *record;

    if ((task = CreateElementalTask(0, 3, egg_hornet_volley_step)) != NULL) {
        task->extra = record = CAlloc(1, sizeof(struct volley_record));
        record->volley = *volley;
        record->timer = 0;
        record->fired = 0;
        task->step = egg_hornet_volley_step;
    }
}
