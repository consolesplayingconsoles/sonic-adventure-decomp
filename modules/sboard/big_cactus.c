/* @unit 0C903300-0C903500 @data 0C905E20-0C905E38 +r04 +egflags +pool32 */
/* BIG CACTUS A, B and C, solid cacti that sway when touched. they sway the
 * more the faster player 0 goes */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "object/placement.h"
#include "object/simple.h"
#include "player/player.h"
#include "sboard/big_cactus.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/task_desc.h"
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
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void MirenObjEntryMobileLandObject(struct task *task, NJS_OBJECT *object,
                                   Sint32 flags, Float scale);
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
void FUN_0c903300(struct task *task);
void FUN_0c90330a(struct task *task);
void FUN_0c903314(struct task *task);
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
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

/* a kind of big cactus, which init takes as arg */
#define KIND(arg) ((struct big_cactus_kind *)(arg))
#define SWAY_SPEED NJM_DEG_ANG(5)
#define SWAY_DECAY NJM_DEG_ANG(0.1)
#define SWAY_SPEED_FULL (4.6F * 0.4F)
#define SWAY_MOST NJM_DEG_ANG(30)
struct big_cactus_kind {
    NJS_OBJECT *object;
    struct collision_list list;
};

/* @hack spelling: arg read through KIND at each use, which keeps arg on the
 * stack (MOV.L R5,@R15 at 0x0c9032ee); through a local, SHC keeps it in
 * R13, big_cactus_init runs 4 bytes short and 35 of its 36 words differ */

/* a big cactus's record, in task->motion */
struct big_cactus_record {
    Sint8 mode;
    NJS_OBJECT *object;
    struct collision_list *list;
    Angle rest; /* ang.x at rest */
    Angle phase; /* the sway's phase */
    Angle swing; /* the most the sway turns it from rest */
};

enum big_cactus_mode { BIG_CACTUS_STAND };

/* the sway's phase turns SWAY_SPEED a step, and its swing shrinks SWAY_DECAY
 * a step */

/* a touch at player 0's speed of SWAY_SPEED_FULL or more swings a cactus
 * SWAY_MOST. a slower one swings it less, in proportion */

extern NJS_OBJECT big_cactus_a_object;
extern NJS_OBJECT big_cactus_b_object;
extern NJS_OBJECT big_cactus_c_object;

void big_cactus_init(struct task *task, void *arg);
void big_cactus_step(struct task *task);
void big_cactus_draw(struct task *task);
Angle big_cactus_push(Angle swing);
extern const struct collision_kind big_cactus_collision;
static const struct task_desc big_cactus_desc = {
    sizeof(struct big_cactus_record),
    TASK_WORK,
    big_cactus_init,
    big_cactus_step,
    big_cactus_draw,
    NULL};
extern struct collision_shape big_cactus_a_shapes[1];
extern struct big_cactus_kind big_cactus_a;
extern struct collision_shape big_cactus_b_shapes[1];
extern struct big_cactus_kind big_cactus_b;
extern struct collision_shape big_cactus_c_shapes[1];
extern struct big_cactus_kind big_cactus_c;

void FUN_0c903300(struct task *task)
{
    MirenInitTask(task, &big_cactus_desc, &big_cactus_a);
}

void FUN_0c90330a(struct task *task)
{
    MirenInitTask(task, &big_cactus_desc, &big_cactus_b);
}

void FUN_0c903314(struct task *task)
{
    MirenInitTask(task, &big_cactus_desc, &big_cactus_c);
}

/* give the cactus its shapes, unless the set editor holds it, and start it
 * at rest */
void big_cactus_init(struct task *task, void *arg)
{
    struct collision_list *list = &KIND(arg)->list;
    struct task_work *work;
    struct big_cactus_record *record;
    /* @hack spelling: the test through in_play, which SHC computes with MOVT
     * R4 in the branch's delay slot (0x0c9032f8); tested directly, the MOVT
     * goes, big_cactus_init runs 2 bytes short and 24 of its 36 words
     * differ */
    int in_play = !OnEdit(task);

    if (in_play) {
        object_collision_init(task, list, &big_cactus_collision);
    }
    work = task->work;
    record = (struct big_cactus_record *)task->motion;
    record->mode = BIG_CACTUS_STAND;
    record->object = KIND(arg)->object;
    record->list = list;
    record->rest = work->ang.x;
    record->phase = 0;
    record->swing = 0;
}

/* draw the cactus and sway it. a touch sets its swing as big_cactus_push
 * says, and the swing then shrinks to 0. while the set editor holds the
 * cactus, it doesn't sway */
void big_cactus_step(struct task *task)
{
    struct big_cactus_record *record;
    struct task_work *work;
    struct collision_work *collision;

    if (CheckRangeOut(task)) {
        return;
    }
    big_cactus_draw(task);
    work = task->work;
    record = (struct big_cactus_record *)task->motion;
    if (OnEdit(task)) {
        return;
    }
    switch (record->mode) {
    case BIG_CACTUS_STAND:
        collision = work->collision;
        /* @bug memory: a cactus the set editor held as it started has no
         * collision record. once the editor lets it go, this reads the
         * record's flags through null (MOV.W @(2,R4),R0 at 0x0c903354) */
        if (!(collision->flags & COLLISION_HIT)) {
            EntryColliList(work);
        } else {
            collision->flags &= ~COLLISION_HIT;
            record->swing = big_cactus_push(record->swing);
        }
        work->ang.x =
            record->rest +
            (Angle)(asinf(njSin(record->swing) * njSin(record->phase)) *
                    ANGLE_PER_RADIAN);
        record->phase += SWAY_SPEED;
        record->swing -= SWAY_DECAY;
        if (record->swing <= 0) {
            record->swing = 0;
        }
        break;
    }
}

/* draw the cactus on a frame's first step */
void big_cactus_draw(struct task *task)
{
    struct task_work *work;
    struct big_cactus_record *record;

    if (loop_count != 0) {
        return;
    }
    work = task->work;
    record = (struct big_cactus_record *)task->motion;
    MirenObjDrawCharColliObjectNoScale(record->object, work, NULL);
}

/* the swing after a touch, from player 0's speed.x, its speed along its
 * own x. the result is SWAY_MOST times |speed.x| / SWAY_SPEED_FULL, at most
 * SWAY_MOST, or swing itself when swing is larger */
Angle big_cactus_push(Angle swing)
{
    struct player *record = GetPlayerWorkPointer(0);
    Float speed = record->speed.x;
    Angle push;

    if (speed < 0.0F) {
        speed = -speed;
    }
    speed *= 1.0F / SWAY_SPEED_FULL;
    if (speed > 1.0F) {
        speed = 1.0F;
    }
    push = (Angle)(speed * SWAY_MOST);
    if (push < swing) {
        push = swing;
    }
    return push;
}
