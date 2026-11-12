/* @unit 8C09FA40-8C09FF80 +r04 +egflags +pool32 -noinline */
/* helpers for the modules' simple objects: collision records, trees drawn
 * at a work's place, their copies in the collision world, and bounces on
 * the ground */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "collision/ground.h"
#include "collision/world.h"
#include "draw/tree.h"
#include "object/simple.h"
#include "player/player.h"
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
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
void MirenObjDrawCharColliObjectNoScale(NJS_OBJECT *object,
                                        struct task_work *work,
                                        NJS_TEXLIST *texlist);
void FUN_8c09fac8(NJS_OBJECT *object, struct task_work *work, Float scale,
                  NJS_TEXLIST *texlist);
void FUN_8c09fd40(NJS_OBJECT *object, struct task_work *work, Float scale,
                  NJS_TEXLIST *texlist);
void FUN_8c09fc4c(struct task_motion *motion);
int FUN_8c09ff5a(NJS_MESHSET *meshset);
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
extern const NJS_VECTOR object_no_speed;
extern const NJS_VECTOR object_no_accel;

/* object_bounce looks for the ground from this far above a thing's foot,
 * pos less offset */
#define GROUND_ABOVE 4.0F
/* the speed a falling thing gains each step. a thing no more than
 * FALL_STEP above the ground comes to rest on it, once it rises or falls no
 * faster than FALL_STEP */
#define FALL_STEP 0.027222218F
/* a speed no faster than FALL_STEP, squared, counts as none */
#define REST_SPEED2 (FALL_STEP * FALL_STEP)

void object_turn_x(struct angles *ang)
{
    TURN(njRotateX, ang->x);
}

void object_turn_y(struct angles *ang)
{
    TURN(njRotateY, ang->y);
}

void object_turn_z(struct angles *ang)
{
    TURN(njRotateZ, ang->z);
}

void object_collision_init(struct task *task, const struct collision_list *list,
                           const struct collision_kind *kind)
{
    CCL_Init(task, list->shapes, kind->kind, kind->unused, list->count);
}
#pragma inline(set_texlist)
#pragma inline(scale_by)
static void set_texlist(NJS_TEXLIST *texlist)
{
    if (texlist == ((void *)0)) {
        SetObjectTexture();
    } else {
        njSetTexture_jp(texlist);
    }
}

static void scale_by(Float scale)
{
    njScale(NULL, scale, scale, scale);
}

void FUN_8c09fac8(NJS_OBJECT *object, struct task_work *work, Float scale,
                  NJS_TEXLIST *texlist)
{
    struct angles *ang;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    ang = &work->ang;
    object_turn_z(ang);
    object_turn_x(ang);
    object_turn_y(ang);
    scale_by(scale);
    set_texlist(texlist);
    late_DrawObject(object);
    late_DrawObjectClipEx(1);
}

void MirenObjDrawCharColliObjectNoScale(NJS_OBJECT *object,
                                        struct task_work *work,
                                        NJS_TEXLIST *texlist)
{
    struct angles *ang;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    ang = &work->ang;
    object_turn_z(ang);
    object_turn_x(ang);
    object_turn_y(ang);
    set_texlist(texlist);
    late_DrawObject(object);
    late_DrawObjectClipEx(1);
}

NJS_OBJECT *object_world_copy(NJS_OBJECT *source)
{
    NJS_OBJECT *object;
    /* @hack spelling: the scale stored through scl, object->scl's address in R5
     * (ADD #32,R5 at 0x8c0a5b6e); stored through object, 21 of 30 words
     * differ */
    Float *scl;

    object = GetMobileLandObject();
    if (object != NULL) {
        object->evalflags =
            source->evalflags & ~(NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG);
        object->model = source->model;
        object->child = source->child;
        /* @hack spelling: scl set before sibling is copied, which forms its
         * address ahead of the copies (ADD #32,R5 at 0x8c0a5b6e); set after
         * the copy, 5 of 30 words differ */
        scl = object->scl;
        object->sibling = source->sibling;
        scl[0] = 1.0F;
        scl[1] = 1.0F;
        scl[2] = 1.0F;
    }
    return object;
}

void object_world_place(NJS_OBJECT *object, struct task_work *work, Float scale)
{
    /* @hack spelling: the copies through pointers, which take pos's and ang's
     * addresses (ADD #32 at 0x8c0a5b98, ADD #20 at 0x8c0a5ba0) and read at
     * offsets from them; through object and work, 27 of 28 words differ */
    Float *to;
    NJS_POINT3 *from;
    Angle *ang_to;
    struct angles *ang_from;

    from = &work->pos;
    to = object->pos;
    to[0] = from->x;
    to[1] = from->y;
    to[2] = from->z;
    ang_to = object->ang;
    ang_from = &work->ang;
    ang_to[0] = ang_from->x;
    ang_to[1] = ang_from->y;
    ang_to[2] = ang_from->z;
    to = object->scl;
    to[0] = scale;
    to[1] = scale;
    to[2] = scale;
}

void FUN_8c09fc4c(struct task_motion *motion)
{
    motion->speed = object_no_speed;
    motion->accel = object_no_accel;
}

/* the cutoffs on the scaled radius are ten times model_start_world's */
void MirenObjEntryMobileLandObject(struct task *task, NJS_OBJECT *object,
                                   Sint32 flags, Float scale)
{
    Float radius;

    flags |= WORLD_SOLID;
    radius = object->model->r * scale;
    if (radius <= WORLD_LARGE_REACH) {
        if (radius > WORLD_MEDIUM_REACH) {
            flags |= WORLD_LARGE;
        } else if (radius > WORLD_SMALL_REACH) {
            flags |= WORLD_MEDIUM;
        } else {
            flags |= WORLD_SMALL;
        }
    }
    RegisterCollisionEntry(flags, task, object);
}

Bool object_world_test_radius(struct task_work *work, Float radius)
{
    Bool in_range;

    in_range = player_in_range(&work->pos, radius) != 0;
    if (in_range) {
        work->flags |= WORLD_TESTED;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
    return in_range;
}

void FUN_8c09fd40(NJS_OBJECT *object, struct task_work *work, Float scale,
                  NJS_TEXLIST *texlist)
{
    struct angles *ang;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    ang = &work->ang;
    object_turn_z(ang);
    object_turn_y(ang);
    object_turn_x(ang);
    scale_by(scale);
    set_texlist(texlist);
    late_DrawObject(object);
    late_DrawObjectClipEx(1);
}

void object_world_free(struct task *task, NJS_OBJECT *object)
{
    if (object != NULL) {
        WithdrawCollisionEntry(task, object);
        ReleaseMobileLandObject(object);
    }
}

Bool object_bounce(NJS_POINT3 *pos, NJS_VECTOR *speed, NJS_VECTOR *bounce,
                   Float offset)
{
    struct angles slope;
    Float x;
    Float y;
    Float z;
    Float speed_x;
    Float speed_y;
    Float speed_z;
    Float ground;
    /* the part of the step after the landing: 0 in the air, and 1 on the
     * ground. pos moves across at the old speed through the part before
     * and at the scaled speed through after */
    Float after;
    Float below;
    Float before;
    Bool moving;
    Bool result;

    x = pos->x;
    y = pos->y;
    z = pos->z;
    speed_x = speed->x;
    speed_y = speed->y;
    speed_z = speed->z;
    ground = GetShadowPos(x, y - offset + GROUND_ABOVE, z, &slope) + offset;
    result = TRUE;
    moving = SQUARE(speed_x) + SQUARE(speed_z) > REST_SPEED2;
    if (y - ground <= FALL_STEP && SQUARE(speed_y) <= REST_SPEED2) {
        speed_y = 0.0F;
        y = ground;
        after = 1.0F;
        if (!moving) {
            result = FALSE;
        }
    } else {
        speed_y += -FALL_STEP;
        y += speed_y;
        below = y - ground;
        if (below > 0.0F) {
            after = 0.0F;
        } else {
            y = ground - (below * bounce->y);
            after = SQUARE(speed_y) <= REST_SPEED2 ? 1.0F : below / speed_y;
            speed_y *= -bounce->y;
        }
    }
    pos->y = y;
    speed->y = speed_y;
    if (moving) {
        before = 1.0F - after;
        x += before * speed_x;
        z += before * speed_z;
        if (after > 0.0F) {
            speed_x *= bounce->x;
            speed_z *= bounce->z;
            x += after * speed_x;
            z += after * speed_z;
            speed->x = speed_x;
            speed->z = speed_z;
        }
        pos->x = x;
        pos->z = z;
    } else {
        speed->x = 0.0F;
        speed->z = 0.0F;
    }
    return result;
}

int FUN_8c09ff5a(NJS_MESHSET *meshset)
{
    int total = 0;
    /* @hack spelling: i zeroed where it's declared, which zeroes total from it
     * ahead of the loads (MOV #0,R5 and MOV R5,R7 at 0x8c0a5efe); zeroed in
     * the for, 3 of 18 words differ */
    int i = 0;
    int count = meshset->nbMesh;
    Sint16 *meshes = meshset->meshes;
    int points;

    for (; i < count; i++) {
        points = (Uint8)*meshes;
        total += points;
        meshes += points + 1;
    }
    return total;
}
