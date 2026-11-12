/* @unit 8C05A880-8C05AE40 +egflags +pool32 */
/* the kusa, CMN KUSA: a plant that Tails' tail attack or Amy's hammer spin
 * cuts down. once cut, it may drop an item, and its seven leaves fly off
 * and fade */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/helpers.h"
#include "object/kusa.h"
#include "object/models.h"
#include "object/placement.h"
#include "player/amy.h"
#include "player/tails.h"
#include "player/player.h"
#include "sound/sound.h"
#include "system/task.h"
#include "system/texlists.h"
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
void *syMalloc_default_malloc(size_t size);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Float vector_reflect(NJS_VECTOR *vector, NJS_VECTOR *normal_jp,
                     NJS_VECTOR *out);
Bool polygon_contains(NJS_POINT3 *point, NJS_POINT3 *corners,
                      NJS_VECTOR *normal_jp, int count);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void MilesSnowBoard(struct task *task);
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
Angle AdjustAngle(Angle from, Angle to, Angle step);
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

/* a leaf's motion each step. an x or z speed of more than LEAF_SLOW either
 * way scales by LEAF_DRAG, and the leaf rises LEAF_RISE */
#define LEAF_DRAG 0.7F
#define LEAF_SLOW 0.15F
#define LEAF_RISE 0.06F

/* the alpha a leaf loses a step once its flight's steps run out */
#define LEAF_FADE 0.05F

/* the vars of the plant and of each leaf. a leaf counts its flight's steps
 * down in work->timer */
#define VARS(work) ((struct kusa_vars *)&(work)->vars)
struct kusa_vars {
    NJS_OBJECT *object;
    /* a leaf's constant material alpha, an offset. it falls from 0, which
     * draws the leaf as it is, to -1, which clears it */
    Float alpha;
    NJS_TEXLIST *texlist;
};

enum kusa_mode { KUSA_INIT, KUSA_WAIT, KUSA_BROKEN };
enum leaf_mode { LEAF_INIT, LEAF_FLY, LEAF_FADE_OUT };

void kusa_leaf_step(struct task *task);
static void kusa_leaf_start(struct task *task, struct task_work *work,
                            struct task_force *force);
static void FlyCmnKusa(struct task_work *work, struct task_force *force);
static void kusa_drop_item(struct task_work *work);
static void kusa_draw(struct task *task);
static void kusa_leaf_draw(struct task *task);
extern struct collision_shape kusa_shapes[];
extern struct task_spec kusa_leaves[];
extern Float kusa_drops[];

void kusa_step(struct task *task)
{
    struct task_work *work = task->work;
    struct touch *touch = task->extra;
    struct task_work *by;
    int touched;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case KUSA_INIT:
        VARS(work)->texlist = &obj_regular_texlist;
        task->draw = kusa_draw;
        /* a plant cut down before comes back cut down, and only draws until
         * it leaves */
        if (placement_used(task)) {
            VARS(work)->object = &kusa_cut_object;
            task->step = object_step_draw_range;
            break;
        } else {
            work->mode = KUSA_WAIT;
            VARS(work)->object = &kusa_object;
            CCL_Init(task, kusa_shapes, COLLISION_OBJECT, 1, 1);
        }
        /* falls through, so it starts waiting this step */
    case KUSA_WAIT:
        /* @hack spelling: touched assigned in the test, which tests
         * object_touch_moved's R0 and copies it to R12 in the BT/S's slot
         * (0x8c05dae6, 0x8c05daea); assigned apart, SHC tests R12,
         * kusa.c's code runs 32 bytes short and 23 of 115 words differ */
        if ((touched = object_touch_moved(work, touch)) != 0) {
            by = touch->by.owner->work;
            if (by != NULL && (((touched & (1 << CHARACTER_TAILS)) &&
                                (TAILS_STATE(by) & TAILS_ATTACKING)) ||
                               ((touched & (1 << CHARACTER_AMY)) &&
                                amy_get_action(0) == AMY_SPINNING))) {
                work->mode = KUSA_BROKEN;
                placement_set_used(task);
                VARS(work)->object = &kusa_cut_object;
                dsPlay_oneshot(SE_LAND, 0, 0, 0);
                kusa_drop_item(work);
                task_create_children(kusa_leaves, task);
                LoopTaskC(task);
                break;
            }
        }
        EntryColliList(work);
        break;
    case KUSA_BROKEN:
        LoopTaskC(task);
        break;
    }
    object_step_draw(task);
}

void kusa_leaf_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_force *force = task->force;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case LEAF_INIT:
        work->mode = LEAF_FLY;
        VARS(work)->object = &kusa_leaf_object;
        VARS(work)->texlist = &obj_regular_texlist;
        task->draw = kusa_leaf_draw;
        kusa_leaf_start(task, work, force);
        break;
    case LEAF_FLY:
        FlyCmnKusa(work, force);
        if (work->timer-- < 0) {
            work->mode = LEAF_FADE_OUT;
            VARS(work)->alpha = 0.0F;
        }
        break;
    case LEAF_FADE_OUT:
        /* @hack spelling: alpha stepped in the test, which compares the FR2 it
         * stores (0x8c05dc48, 0x8c05dc4e); stepped apart, SHC loads it back,
         * the function runs 4 bytes long and 32 of 87 words differ */
        if ((VARS(work)->alpha -= LEAF_FADE) < -1.0F) {
            FreeTask(task);
            return;
        }
        FlyCmnKusa(work, force);
        /* a fading leaf draws here and again in object_step_draw */
        kusa_leaf_draw(task);
        break;
    }
    object_step_draw(task);
}

/* start a leaf. its speed is the hitter's last move, plus a random push of
 * -2.25 to 2.5 in x and in z. it takes random angles. each step, it turns
 * about each axis by a 64th of its starting angle there. it flies until its
 * timer, set from 30 to 59, runs out */
static void kusa_leaf_start(struct task *task, struct task_work *work,
                            struct task_force *force)
{
    NJS_VECTOR *speed = &((struct touch *)task->parent->extra)->moved;
    Float roll[3];
    int i;

    for (i = 0; i < 3; i++) {
        /* @hack spelling: roll[i] assigned in the test, which stores the roll
         * in the BF/S's slot (FMOV.S FR3,@R12 at 0x8c05dcc2); assigned apart,
         * 91 of 117 words differ */
        if ((roll[i] = rand() * RAND_SCALE) < 0.05F) {
            roll[i] = 0.05F;
        }
    }
    force->speed.x = speed->x + (roll[0] * 5.0F) - 2.5F;
    force->speed.y = speed->y;
    force->speed.z = speed->z + (roll[2] * 5.0F) - 2.5F;
    work->ang.x = (Angle)(roll[0] * (360.0F * ANGLE_PER_DEGREE));
    work->ang.y = (Angle)(roll[1] * (360.0F * ANGLE_PER_DEGREE));
    work->ang.z = (Angle)(roll[2] * (360.0F * ANGLE_PER_DEGREE));
    force->turn.x = work->ang.x >> 6;
    force->turn.y = work->ang.y >> 6;
    force->turn.z = work->ang.z >> 6;
    work->timer = RANDOM(30.0F, 60.0F);
}

static void FlyCmnKusa(struct task_work *work, struct task_force *force)
{
    /* @hack spelling: the x and z speeds through pointers, formed with ADD #16
     * and ADD #24 (0x8c05ddc2, 0x8c05ddd2); through the fields, 63 of 64
     * words differ */
    Float *x = &force->speed.x;
    Float *z = &force->speed.z;

    if ((*x < 0.0F ? -*x : *x) > LEAF_SLOW) {
        *x *= LEAF_DRAG;
    }
    work->pos.x += *x;
    /* @hack spelling: LEAF_RISE subtracted as its negative, which keeps the
     * image's FSUB and its -0.06F (FSUB FR3,FR2 at 0x8c05de00); added, SHC
     * writes an FADD and 1 of 64 words differ */
    work->pos.y -= -LEAF_RISE;
    if ((*z < 0.0F ? -*z : *z) > LEAF_SLOW) {
        *z *= LEAF_DRAG;
    }
    work->pos.z += *z;
    work->ang.x += force->turn.x;
    work->ang.y += force->turn.y;
    work->ang.z += force->turn.z;
}

static void kusa_drop_item(struct task_work *work)
{
    enum drop_kind kind;

    /* @hack spelling: kind assigned in the test, which tests item_pick's R0 and
     * copies it to R5 in the BT/S's slot (0x8c05de4e, 0x8c05de52); assigned
     * apart, SHC tests R5 and 3 of 19 words differ */
    if ((kind = item_pick(kusa_drops)) != 0) {
        item_drop(work, kind);
    }
}

static void kusa_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 10.0F)) {
        return;
    }
    njSetTexture_jp(VARS(work)->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(VARS(work)->object);
    late_DrawObjectClipEx(1);
}

static void kusa_leaf_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 10.0F)) {
        return;
    }
    njSetTexture_jp(VARS(work)->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    SaveConstantAttr();
    OnConstantAttr(0, NJD_FLAG_USE_ALPHA);
    SetMaterial(VARS(work)->alpha, 0.0F, 0.0F, 0.0F);
    ds_DrawModelClip(VARS(work)->object->model);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    LoadConstantAttr();
    late_DrawObjectClipEx(1);
}
