/* @unit 8C066260-8C0673C0 +r04 +egflags +pool32 +poolafter=object_draw_model,vector_dot,FUN_8c06673e,mirror_count,FUN_8c066c20,vector_cos +poolbra=item_pick:1 +poolbra=FUN_8c066a3e:1 +poolbra=object_world_follow:1 +poolbra=FUN_8c0670ee:1 +onepool +asmfunc=FUN_8c066a3e */
/* helpers: small routines the objects and the race share, from vector sums
 * to mirrors and jumps */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "collision/world.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "object/common.h"
#include "object/helpers.h"
#include "object/item_box.h"
#include "object/placement.h"
#include "object/ring.h"
#include "player/player.h"
#include "stage/stage.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/util.h"
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
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Bool ChkPause(void);
extern Uint8 seqVars[512];
extern Sint8 evExecFlag[512];
extern int evfade;
void SeqCtrl(void);
void story_save_wait(void);
void main(void);
void SeqEndSection(void);
void SeqEvent(int event);
void SeqSetFlag(int flag);
Bool SeqCheckFlag(int flag);
Bool SeqCheckStage(int stage, int act);
void SeqChangeStage(int stage, int act);
Bool SeqCheckNextStage(Uint8 stage, Uint8 act);
Bool SeqCheckClearAction(int stage);
extern struct save SaveData[3];
extern struct AdvertiseWork AdvertiseWork;
Bool thunk_FUN_8c081ba6(void);
struct task *thunk_FUN_8c081bec(void);
struct task *thunk_FUN_8c08395e(struct battle *battle);
struct task *thunk_FUN_8c083ebc(struct battle *battle);
void thunk_FUN_8c083f7e(struct battle *battle);
Sint16 thunk_FUN_8c0829cc(int frames);
Sint16 thunk_FUN_8c082b9a(int unused);
void ObjectMovableSRegularExecute(struct task *task);
void ObjectMovableMRegularExecute(struct task *task);
void ObjectSetupInput(struct task_work *work, struct task_motion *motion);
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
Float FUN_8c06673e(NJS_VECTOR *vector, NJS_VECTOR *normal_jp, NJS_VECTOR *out);
Bool FUN_8c066a3e(NJS_POINT3 *point, NJS_POINT3 *corners, NJS_VECTOR *normal_jp,
                  int count);
Bool FUN_8c066c20(struct task_work *work, NJS_MODEL *model);
void FUN_8c066da0(struct task *task, void (*draw)(struct task *task));
int FUN_8c0670ee(NJS_POINT3 *pos, Float range);
Bool FUN_8c067320(void);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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
extern NJS_MATERIAL arrow_materials[1];
extern Sint16 arrow_meshes[102];
extern NJS_MESHSET arrow_meshsets[1];
extern NJS_POINT3 arrow_points[19];
extern NJS_VECTOR arrow_normals[19];
extern NJS_MODEL arrow_model;
extern NJS_OBJECT arrow_y;
extern NJS_OBJECT arrow_z;
extern Sint32 quad_order[4];

/* bits of work->tick, for a task that keeps no count there */
#define TICK_TOUCHED 0x1 /* object_touch_moved holds a touch */
#define TICK_NO_WORLD 0x2 /* object_add_world_model found the pool empty */

/* a player within a world model's radius plus this of its task has the
 * world test the model */
#define WORLD_REACH 20.0F

/* a jump that ends within this of its target lands on it */
#define LANDED_RANGE 2.0F

/* an arrow one unit long along y, which arrow_draw_y stretches */

void vector_copy(const Float *from, Float *to)
{
    /* @hack spelling: from and to walked, for the image's @Rn+ loads and ADD #4
     * stores (0x8c069aa0, 0x8c069aa4); without it, through subscripts, 8 of
     * 9 words differ */
    *to++ = *from++;
    *to++ = *from++;
    *to = *from;
}

void angles_copy(const Angle *from, Angle *to)
{
    /* @hack spelling: from and to walked, as in vector_copy (0x8c069ab2,
     * 0x8c069ab6); without it, through subscripts, 9 of 9 words differ */
    *to++ = *from++;
    *to++ = *from++;
    *to = *from;
}

void vector_clear(Float *vector)
{
    /* @hack spelling: vector walked, for the image's ADD #4 stores
     * (0x8c069ac8); without it, through subscripts, 6 of 7 words differ */
    *vector++ = 0.0F;
    *vector++ = 0.0F;
    *vector = 0.0F;
}

void vector_add(const NJS_VECTOR *first, const NJS_VECTOR *second,
                NJS_VECTOR *sum)
{
    /* @hack spelling: byte cursors over the whole vectors, for the image's
     * @Rn+ loads and ADD #4 stores; without them, through the members,
     * 12 of 15 words differ */
    const char *at_first = (const char *)first;
    const char *at_second = (const char *)second;
    char *out = (char *)sum;

    *(Float *)out = *(const Float *)at_first + *(const Float *)at_second;
    out += sizeof(Float);
    at_first += sizeof(Float);
    at_second += sizeof(Float);
    *(Float *)out = *(const Float *)at_first + *(const Float *)at_second;
    out += sizeof(Float);
    at_first += sizeof(Float);
    at_second += sizeof(Float);
    *(Float *)out = *(const Float *)at_first + *(const Float *)at_second;
}

void vector_sub(const Float *first, const Float *second, Float *difference)
{
    /* @hack spelling: the three pointers walked, as in vector_copy; without it,
     * through subscripts, 12 of 15 words differ */
    *difference++ = *first++ - *second++;
    *difference++ = *first++ - *second++;
    *difference = *first - *second;
}

void vector_between(const NJS_VECTOR *from, const NJS_VECTOR *to,
                    NJS_VECTOR *out)
{
    /* @hack spelling: byte cursors over the whole vectors, as in vector_add;
     * without them, through the members, 12 of 15 words differ */
    const char *at_from = (const char *)from;
    const char *at_to = (const char *)to;
    char *at_out = (char *)out;

    *(Float *)at_out = *(const Float *)at_to - *(const Float *)at_from;
    at_out += sizeof(Float);
    at_to += sizeof(Float);
    at_from += sizeof(Float);
    *(Float *)at_out = *(const Float *)at_to - *(const Float *)at_from;
    at_out += sizeof(Float);
    at_to += sizeof(Float);
    at_from += sizeof(Float);
    *(Float *)at_out = *(const Float *)at_to - *(const Float *)at_from;
}

void object_step_draw_range(struct task *task)
{
    /* @hack spelling: the draw called through a local, which SHC stores to the
     * stack (MOV.L R3,@R15 at 0x8c069b38); called as task->draw, 13 of 15
     * words differ */
    void (*draw)(struct task *task);

    draw = task->draw;
    draw(task);
    CheckRangeOut(task);
}

void object_step_draw(struct task *task)
{
    /* @hack spelling: the draw called through a local, as above (MOV.L R3,@R15
     * at 0x8c069b50); called as task->draw, 6 of 6 words differ */
    void (*draw)(struct task *task);

    draw = task->draw;
    draw(task);
}

void object_draw_model(struct task *task)
{
    struct task_work *work = task->work;

    njSetTexture_jp(MODEL(work)->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(MODEL(work)->object);
    late_DrawObjectClipEx(1);
}

void object_draw_model_scaled(struct task *task)
{
    struct task_work *work = task->work;

    njSetTexture_jp(MODEL(work)->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njScaleV(NULL, &work->scl);
    late_DrawObject(MODEL(work)->object);
    late_DrawObjectClipEx(1);
}

void object_draw_action(struct task *task)
{
    struct task_work *work = task->work;

    njSetTexture_jp(ACTION(work)->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    /* @hack spelling: the frame added in the test, which compares the sum in
     * FR2 (FCMP/GT FR2,FR1 at 0x8c069cd6); added apart, SHC loads the frame
     * back from the work and 9 of 70 words differ */
    if ((ACTION(work)->frame += 1.0F) >=
        (Float)ACTION(work)->action->motion->nbFrame) {
        ACTION(work)->frame = 0.0F;
    }
    ds_ActionClip(((struct action_vars *)&(work)->vars)->action,
                  ((struct action_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

int object_touch_moved(struct task_work *work, struct touch *touch)
{
    struct collision_work *collision;
    struct collision_work *hit;
    struct collision_shape *shape;
    Float *moved;

    if (work->flags & COLLISION_DAMAGED) {
        collision = work->collision;
        hit = collision->hit;
        shape = &hit->shapes[collision->hit_shape];
        if (!(work->tick & TICK_TOUCHED)) {
            work->tick |= TICK_TOUCHED;
            touch->moved.x = shape->center.x;
            touch->moved.y = shape->center.y;
            touch->moved.z = shape->center.z;
            touch->by.shape = shape;
            return 0;
        } else if (shape == touch->by.shape) {
            goto moved;
        }
    }
    work->tick &= ~TICK_TOUCHED;
    return 0;
    /* @hack spelling: the report's arm placed last, past the shared return of
     * 0 (0x8c069d44); in the else-if's arm, 36 of 69 words differ */
moved:
    /* @hack spelling: each of touch->moved's members through a pointer, whose
     * address SHC forms in R4 (MOV R5,R4 at 0x8c069d46); through
     * touch->moved, SHC reaches y and z through R0 and 14 of 69 words
     * differ */
    moved = &touch->moved.x;
    *moved = shape->center.x - *moved;
    moved = &touch->moved.y;
    *moved = shape->center.y - *moved;
    moved = &touch->moved.z;
    *moved = shape->center.z - *moved;
    touch->by.owner = hit->owner;
    return 1 << PLAYER_VARS(hit->owner->work)->character;
}

Float vector_dot(NJS_VECTOR *first, NJS_VECTOR *second)
{
    return (first->x * second->x) + (first->y * second->y) +
           (first->z * second->z);
}

void vector_cross(NJS_VECTOR *first, NJS_VECTOR *second, NJS_VECTOR *out)
{
    out->x = (first->y * second->z) - (first->z * second->y);
    out->y = (first->z * second->x) - (first->x * second->z);
    out->z = (first->x * second->y) - (first->y * second->x);
}

Float vector_length(NJS_VECTOR *vector)
{
    return njSqrt((vector->x * vector->x) + (vector->y * vector->y) +
                  (vector->z * vector->z));
}

void vector_aim_z(NJS_VECTOR *vector, Angle *ang_x, Angle *ang_y)
{
    *ang_x = -(Angle)(njArcTan2(vector->y, vector->z) * ANGLE_PER_RADIAN);
    *ang_y = (Angle)(njArcTan2(vector->x, njSqrt((vector->y * vector->y) +
                                                 (vector->z * vector->z))) *
                     ANGLE_PER_RADIAN);
}

void vector_aim_y(NJS_VECTOR *vector, Angle *ang_x, Angle *ang_z)
{
    *ang_z = -(Angle)(njArcTan2(vector->x, vector->y) * ANGLE_PER_RADIAN);
    *ang_x = (Angle)(njArcTan2(vector->z, njSqrt((vector->x * vector->x) +
                                                 (vector->y * vector->y))) *
                     ANGLE_PER_RADIAN);
}

void vector_aim_x(NJS_VECTOR *vector, Angle *ang_y, Angle *ang_z)
{
    *ang_y = -(Angle)(njArcTan2(vector->z, vector->x) * ANGLE_PER_RADIAN);
    *ang_z = (Angle)(njArcTan2(vector->y, njSqrt((vector->z * vector->z) +
                                                 (vector->x * vector->x))) *
                     ANGLE_PER_RADIAN);
}

Float FUN_8c06673e(NJS_VECTOR *vector, NJS_VECTOR *normal_jp, NJS_VECTOR *out)
{
    Float dot = vector_dot(vector, normal_jp);
    Float push = -(dot * 2.0F);
    Float squareness = dot / vector_length(vector);

    out->x = vector->x + (push * normal_jp->x);
    out->y = vector->y + (push * normal_jp->y);
    out->z = vector->z + (push * normal_jp->z);
    return njAbs(squareness);
}

void arrow_draw(NJS_POINT3 *pos, NJS_VECTOR *vector)
{
    /* @hack type: the angles in an array, whose elements' addresses SHC
     * keeps on the stack (MOV.L R6,@(12,R15) at 0x8c06a06a); as two Angle
     * locals, 52 of 84 words differ */
    Angle aim[3];
    Float length;

    if (loop_count != 0) {
        length = njSqrt((vector->x * vector->x) + (vector->y * vector->y) +
                        (vector->z * vector->z));
        vector_aim_z(vector, &aim[0], &aim[1]);
        njPushMatrix(NULL);
        njTranslateV(NULL, pos);
        TURN(njRotateX, aim[0]);
        TURN(njRotateY, aim[1]);
        njScale(NULL, 1.0F, 1.0F, length);
        late_DrawObjectClip(&arrow_z);
        late_DrawObjectClipEx(1);
    }
}

void arrow_draw_y(NJS_POINT3 *pos, NJS_VECTOR *vector)
{
    /* @hack type: the angles in an array, as in arrow_draw; as two Angle
     * locals, 52 of 84 words differ */
    Angle aim[3];
    Float length;

    if (loop_count != 0) {
        length = njSqrt((vector->x * vector->x) + (vector->y * vector->y) +
                        (vector->z * vector->z));
        vector_aim_y(vector, &aim[0], &aim[2]);
        njPushMatrix(NULL);
        njTranslateV(NULL, pos);
        TURN(njRotateZ, aim[2]);
        TURN(njRotateX, aim[0]);
        njScale(NULL, 1.0F, length, 1.0F);
        late_DrawObjectClip(&arrow_y);
        late_DrawObjectClipEx(1);
    }
}

void marker_draw(NJS_POINT3 *pos, Float size)
{
    if (loop_count != 0) {
        size *= 0.1F;
        njPushMatrix(NULL);
        njTranslateV(NULL, pos);
        njScale(NULL, size, size, size);
        late_DrawObjectClip(&object_sphere01);
        late_DrawObjectClipEx(1);
    }
}

int item_pick(Float *table)
{
    Float pick = (Float)rand() * RAND_SCALE;
    Float weight;

    while ((weight = *table++) != 0.0F) {
        if ((pick -= weight) < 0.0F) {
        /* @hack redundant: a label no goto uses, which has SHC load the kind
         * into FR3 (FMOV.S @R14,FR3 at 0x8c06a228); without it, FR2, and 2 of
         * 31 words differ */
        found: /* NOLINT(clang-diagnostic-unused-label) */
            return (int)*table;
        }
        table++;
    }
    return 0;
}

Bool item_drop(struct task_work *work, enum drop_kind kind)
{
    switch (kind) {
    case DROP_RING:
        ring_scatter(work->pos.x, work->pos.y, work->pos.z, 1);
        break;
    case DROP_5_RINGS:
        ring_scatter(work->pos.x, work->pos.y, work->pos.z, 5);
        break;
    case DROP_10_RINGS:
        ring_scatter(work->pos.x, work->pos.y, work->pos.z, 10);
        break;
    case DROP_RANDOM_RINGS:
        item_box_create(&work->pos, ITEM_RANDOMRING);
        break;
    case DROP_1UP:
        item_box_create(&work->pos, ITEM_1UP);
        break;
    }
    return TRUE;
}

/* point lies inside while, seen from it, each corner turns anticlockwise
 * about normal to the next. offsets[n] is corner n less point */
Bool FUN_8c066a3e(NJS_POINT3 *point, NJS_POINT3 *corners, NJS_VECTOR *normal_jp,
                  int count)
{
    NJS_VECTOR offsets[8];
    NJS_VECTOR cross;
    int i;

    for (i = 0; i < count; i++) {
        offsets[i].x = corners->x - point->x;
        offsets[i].y = corners->y - point->y;
        offsets[i].z = corners->z - point->z;
        corners++;
    }
    /* the first offset again after the last, for the last turn */
    /* @hack type: the offset's Floats moved as three Sint32 words through
     * words_copy, which SHC expands to MOV.L moves; without it, member by
     * member, 54 of 96 words differ */
    words_copy((Sint32 *)offsets, (Sint32 *)&offsets[i], 3);
    for (i = 0; i < count; i++) {
        /* @hack type: the next offset's index narrowed to a Sint16, which SHC
         * scales apart from i's (ADD #1,R5 at 0x8c06a338); as i + 1, SHC
         * adds 12 to &offsets[i] in a fourth saved register, R11, and 85 of
         * 96 words differ */
        vector_cross(&offsets[i], &offsets[(Sint16)(i + 1)], &cross);
        if (vector_dot(&cross, normal_jp) <= 0.000001F) {
            return FALSE;
        }
    }
    return TRUE;
}

/* polygon_contains, the only code that calls words_copy, expands it in place
 * (0x8c06a320). words_copy, being external, keeps its own body too, at
 * 0x8c06a380. SHC writes no copy of a static it expands at every call */
void words_copy(Sint32 *from, Sint32 *to, int count)
{
    while (count--) {
        *to++ = *from++;
    }
}

Bool player_get_middle(Uint8 player, int steps, NJS_POINT3 *pos,
                       struct angles *ang)
{
    struct player *record;
    NJS_VECTOR up;

    if (!GetPlayerPosition(player, steps, pos, ang)) {
        return FALSE;
    }
    record = GetPlayerWorkPointer(player);
    up.x = 0.0F;
    up.y = record->consts.height * 0.5F;
    up.z = 0.0F;
    njPushMatrix(NULL);
    njUnitMatrix(NULL);
    njTranslateV(NULL, pos);
    TURN(njRotateZ, ang->z);
    TURN(njRotateX, ang->x);
    TURN(njRotateY, ang->y);
    njCalcPoint(NULL, &up, pos);
    late_DrawObjectClipEx(1);
    return TRUE;
}

void mirror_clear(void)
{
    mirrors.count = 0;
}

int mirror_count(void)
{
    return mirrors.count;
}

Bool FUN_8c066c20(struct task_work *work, NJS_MODEL *model)
{
    NJS_MESHSET *meshset = model->meshsets;
    int slot;
    struct mirror *mirror;
    struct mirror_quad *quad;
    Sint16 *meshes;
    NJS_POINT3 *points;
    NJS_VECTOR *normal_jp;
    Sint32 *order;
    Sint32 *corner;
    int count;
    int i;
    int j;
    NJS_POINT3 *point;

    if ((slot = mirrors.count++) >= MIRRORS) {
        return FALSE;
    }
    /* @hack spelling: an empty arm for a meshset of other polygons, which puts
     * the mirror's size in R3 and njPushMatrix's address in R1 (0x8c06a4fc,
     * 0x8c06a506); as the quads' test alone, 12 of 153 words differ */
    if ((meshset->type_matId & NJD_MESHSET_MASK) != NJD_MESHSET_4) {
    } else {
        meshes = meshset->meshes;
        /* @hack type: mirror set to the list's first ahead of points, then
         * moved on by an offset narrowed to a Sint16, the image's MULS.W and
         * EXTS.W (0x8c06a502, 0x8c06a510). the test above keeps slot below
         * MIRRORS, where the offset fits a Sint16 and the narrowing changes
         * nothing; as &mirrors.mirrors[slot] after points, 9 of 153 words
         * differ */
        mirror = mirrors.mirrors;
        points = model->points;
        mirror = (struct mirror *)((char *)mirror + (slot * sizeof(*mirror)));
        quad = mirror->quads;
        mirror->count = count = meshset->nbMesh;
        njPushMatrix(&nj_unit_matrix_);
        njTranslateV(NULL, &work->pos);
        TURN(njRotateZ, work->ang.z);
        TURN(njRotateX, work->ang.x);
        TURN(njRotateY, work->ang.y);
        /* @hack spelling: i zeroed ahead of normal and order, which puts its 0
         * in R3 (MOV #0,R3 at 0x8c06a558); zeroed in the for, 6 of 153 words
         * differ */
        i = 0;
        normal_jp = meshset->normals;
        order = quad_order;
        for (; i < count; i++) {
            /* @hack spelling: the vectors through from and to, which put MOV
             * R13,R6 ahead of MOV R8,R5 (0x8c06a56c); passed directly, 2 of
             * 153 words differ */
            NJS_VECTOR *from = normal_jp;
            NJS_VECTOR *to = &quad->normal_jp;

            njCalcVector(NULL, from, to);
            corner = order;
            for (j = 0; j < 4; j++) {
                /* @hack spelling: the point through a local, which keeps
                 * meshes in R9 and njCalcPoint's address in R10 (0x8c06a578,
                 * 0x8c06a596); passed directly, 33 of 153 words differ */
                point = &points[*meshes++];
                njCalcPoint(NULL, point, &quad->corners[*corner]);
                corner++;
            }
            quad++;
            /* @hack spelling: normal = normal + 1, which keeps the stack frame
             * at 44 bytes (ADD #-12,R15 at 0x8c06a4d0); as normal++, 48 bytes,
             * and 99 of 153 words differ */
            normal_jp = normal_jp + 1;
        }
        late_DrawObjectClipEx(1);
        return TRUE;
    }
    return FALSE;
}

void FUN_8c066da0(struct task *task, void (*draw)(struct task *task))
{
    int count;
    struct task_work *work = task->work;
    struct mirror *mirror;
    struct mirror_quad *quad;
    NJS_POINT3 nearest; /* the point of the quad's plane nearest the task */
    NJS_VECTOR delta;
    NJS_PLANE plane;
    int quads;
    int i;
    int j;

    /* @hack redundant: count tested ahead of the loop's own test, the image's
     * TST R3,R3 ahead of its CMP/PL R3 (0x8c06a656, 0x8c06a664); without
     * it, 124 of 135 words differ */
    if ((count = mirrors.count) != 0) {
        /* @bug memory: count is mirror_add's calls since mirror_clear,
         * which can pass MIRRORS, and the loop then reads past
         * mirrors.mirrors (CMP/PL R3 at 0x8c06a664 bounds it by count
         * alone) */
        for (i = 0; i < count; i++) {
            mirror = &mirrors.mirrors[i];
            quads = mirror->count;
            quad = mirror->quads;
            for (j = 0; j < quads; j++) {
                vector_copy(&quad->corners[0].x, &plane.px);
                vector_copy(&quad->normal_jp.x, &plane.vx);
                njDistanceP2PL(&work->pos, &plane, &nearest);
                delta.x = nearest.x - work->pos.x;
                delta.y = nearest.y - work->pos.y;
                delta.z = nearest.z - work->pos.z;
                if (vector_dot(&delta, &quad->normal_jp) < 0.0F &&
                    FUN_8c066a3e(&nearest, quad->corners, &quad->normal_jp,
                                 4)) {
                    marker_draw(&nearest, 0.5F);
                    njPushMatrix(NULL);
                    njMirror(NULL, &plane);
                    draw(task);
                    marker_draw(&work->pos, 1.0F);
                    late_DrawObjectClipEx(1);
                }
                quad++;
            }
        }
    }
}

NJS_OBJECT *object_add_world_model(struct task *task, NJS_MODEL *model)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    if ((object = GetMobileLandObject()) != NULL) {
        object->evalflags = NJD_EVAL_BREAK;
        object->scl[0] = 1.0F;
        object->scl[1] = 1.0F;
        object->scl[2] = 1.0F;
        object->pos[0] = work->pos.x;
        object->pos[1] = work->pos.y;
        object->pos[2] = work->pos.z;
        object->ang[0] = work->ang.x;
        object->ang[1] = work->ang.y;
        object->ang[2] = work->ang.z;
        object->model = model;
        object->child = NULL;
        object->sibling = NULL;
        RegisterCollisionEntry(0, task, object);
        return object;
    }
    work->tick |= TICK_NO_WORLD;
    return NULL;
}

void object_world_follow(struct task_work *work, NJS_OBJECT *object)
{
    if (!(work->tick & TICK_NO_WORLD)) {
        if (player_in_range(&work->pos, object->model->r + WORLD_REACH)) {
            work->flags |= WORLD_TESTED;
            object->pos[0] = work->pos.x;
            object->pos[1] = work->pos.y;
            object->pos[2] = work->pos.z;
            object->ang[0] = work->ang.x;
            object->ang[1] = work->ang.y;
            object->ang[2] = work->ang.z;
        } else {
            work->flags &= ~WORLD_TESTED;
        }
    }
}

void object_world_test(struct task_work *work, NJS_OBJECT *object)
{
    if (!(work->tick & TICK_NO_WORLD)) {
        if (player_in_range(&work->pos, object->model->r + WORLD_REACH)) {
            work->flags |= WORLD_TESTED;
        } else {
            work->flags &= ~WORLD_TESTED;
        }
    }
}

void collision_shapes_on(struct task_work *work)
{
    /* @hack spelling: the count through a local, which SHC stores to the
     * stack and loads back (MOV.W R0,@R15 and MOV.W @R15,R6 at 0x8c06a8dc);
     * read in the test, 20 of 20 words differ */
    Uint16 count = work->collision->count;
    struct collision_shape *shape = work->collision->shapes;
    int i;

    for (i = 0; i < count; i++) {
        shape->flags &= ~SHAPE_OFF;
        shape++;
    }
}

void collision_shapes_off(struct task_work *work)
{
    /* @hack spelling: the count through a local, as above (0x8c06a928); read
     * in the test, 20 of 20 words differ */
    Uint16 count = work->collision->count;
    struct collision_shape *shape = work->collision->shapes;
    int i;

    for (i = 0; i < count; i++) {
        shape->flags |= SHAPE_OFF;
        shape++;
    }
}

void action_advance(NJS_ACTION *action, Float *frame, Float step)
{
    *frame += step;
    if (*frame < 0.0F) {
        *frame += action->motion->nbFrame;
        return;
    }
    if (*frame >= action->motion->nbFrame) {
        *frame -= action->motion->nbFrame;
    }
}

int FUN_8c0670ee(NJS_POINT3 *pos, Float range)
{
    int near = 0;
    int i;
    struct task *task;
    const char *center;
    Float distance;

    for (i = 0; i < 2; i++) {
        /* @hack spelling: task assigned in the test, which tests R0 with the
         * copy to R4 in the BT/S's slot (0x8c06a9d4, 0x8c06a9d8); assigned
         * apart, 3 of 66 words differ */
        if ((task = GetPlayerTaskPointer(i)) == NULL) {
            continue;
        }
        /* @hack spelling: a byte cursor over the shape's center, for the
         * image's
         * @Rn+ loads; without it, through a pointer to the center, 3 of 66
         * words differ */
        center = (const char *)&task->work->collision->shapes->center;
        VecTemp0.x = *(const Float *)center - pos->x;
        center += sizeof(Float);
        VecTemp0.y = *(const Float *)center - pos->y;
        center += sizeof(Float);
        VecTemp0.z = *(const Float *)center - pos->z;
        /* @hack spelling: the distance through a local, which SHC copies
         * from FR0 to FR4 for the compare (FMOV FR0,FR4 at 0x8c06aa04);
         * compared directly, 22 of 66 words differ */
        distance = njScalor2(&VecTemp0);
        if (distance < range) {
            near |= 1 << i;
        }
    }
    return near;
}

Float vector_distance2(NJS_POINT3 *from, NJS_POINT3 *to)
{
    NJS_VECTOR delta;

    delta.x = from->x - to->x;
    delta.y = from->y - to->y;
    delta.z = from->z - to->z;
    return njScalor2(&delta);
}

void jump_aim(struct jump *jump)
{
    Float time = (Float)jump->steps;
    /* @hack spelling: pos through a pointer to the point, which puts dx in FR14
     * and dz in FR13; as &jump->pos.x, they trade and 10 of 80 words
     * differ */
    NJS_POINT3 *from = &jump->pos;
    /* @hack spelling: a Float cursor stepped across pos's members, for the
     * image's @Rn+ loads; as from->x, ->y and ->z, the function runs 4 bytes
     * long and 66 of 80 words differ */
    Float *pos = &from->x;
    /* @hack spelling: a Float cursor stepped across target's members the same
     * way; as jump->target.x, .y and .z, the function runs 2 bytes long and 70
     * of 80 words differ */
    Float *target = &jump->target.x;
    Float dx;
    Float dy;
    Float dz;
    Float level;
    Float speed;
    Angle ang;

    dx = *target++ - *pos++;
    dy = *target++ - *pos++;
    dz = *target - *pos;
    speed = njSqrt((dx * dx) + (dz * dz)) / time;
    ang = (Angle)(njArcTan2(dz, dx) * ANGLE_PER_RADIAN);
    jump->speed.x = speed * njCos(ang);
    jump->speed.z = speed * njSin(ang);
    jump->speed.y =
        ((dy * 2.0F) + (jump->gravity * time * time)) / (time * 2.0F);
}

enum jump_state jump_landed(struct jump *jump)
{
    /* @hack spelling: byte cursors over pos and target, for the image's @Rn+
     * loads; without them, through pointers to the points, 6 of 42 words
     * differ */
    const char *pos = (const char *)&jump->pos;
    const char *target = (const char *)&jump->target;
    Float distance;

    if (jump->steps-- > 0) {
        return JUMP_FLYING;
    }
    VecTemp0.x = *(const Float *)target - *(const Float *)pos;
    target += sizeof(Float);
    pos += sizeof(Float);
    VecTemp0.y = *(const Float *)target - *(const Float *)pos;
    target += sizeof(Float);
    pos += sizeof(Float);
    VecTemp0.z = *(const Float *)target - *(const Float *)pos;
    distance = njAbs(njScalor(&VecTemp0));
    if (distance < LANDED_RANGE) {
        return JUMP_ON_TARGET;
    }
    return JUMP_OFF_TARGET;
}

Float vector_cos(NJS_VECTOR *first, NJS_VECTOR *second)
{
    vector_normalize(first);
    vector_normalize(second);
    return njInnerProduct(first, second);
}

Bool FUN_8c067320(void)
{
    Uint16 stage = (Uint8)(GetStageNumber() >> 8);

    if (stage >= STAGE_PRACTICE && stage < STAGE_CHAOS0) {
        return TRUE;
    }
    return FALSE;
}

Float vector_normalize(NJS_VECTOR *vector)
{
    NJS_VECTOR copy;
    Float length;

    vector_copy(&vector->x, &copy.x);
    length = njScalor(&copy);
    if (length < 0.000001F) {
        vector->x = 0.0F;
        vector->y = 1.0F;
        vector->z = 0.0F;
    }
    njUnitVector(vector);
    return length;
}

void object_idle(struct task *task)
{
}
