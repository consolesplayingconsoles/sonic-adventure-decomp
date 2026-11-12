/* @unit 0C90F500-0C90F840 +egflags +pool32 */
/* O ASIBA1, a solid scaffold footing that its set entry scales */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/world.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg05/scaffold.h"
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
void ds_DrawModelClip(NJS_MODEL *model);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define VARS(work) ((struct scaffold_vars *)&(work)->vars)
#define SCAFFOLD_REACH 36.0F
#define DRAW_RADIUS 46.0F
#define NEAR_MARGIN 16.0F
extern NJS_TEXLIST texlist_obj_mountain;
extern NJS_OBJECT scaffold_object;

struct scaffold_vars {
    NJS_OBJECT *world;
    Uint8 unk_04[4];
    /* world's model: a heap copy of scaffold_object's, its radius scaled */
    NJS_MODEL *model;
};

/* the scaffold draws at the set entry's scales plus 1, and its size is the
 * largest of those. its reach and draw radius are at a size of 1. its
 * model's radius is less, about 26 */
/* the world tests the copy only while a player is within its reach plus
 * this margin */

void Die(struct task *task);
void scaffold_run(struct task *task);
void scaffold_draw(struct task *task);

/* unless the set editor holds the scaffold, put a scaled copy of the model in
 * the world. the copy's radius scales by the size, so it bounds the scaled
 * model. the size times SCAFFOLD_REACH picks its world size */
void ObjectMountainAsiba1(struct task *task)
{
    struct task_work *work = task->work;
    NJS_MODEL *model;
    NJS_OBJECT *world;
    Float size;
    Uint32 flags;

    if (CheckRangeOut(task)) {
        return;
    }
    task->destructor = Die;
    task->step = scaffold_run;
    task->draw = scaffold_draw;
    work->ang.x = 0;
    work->ang.z = 0;
    if (OnEdit(task)) {
        return;
    }
    size = work->scl.x;
    if (work->scl.y > size) {
        size = work->scl.y;
    }
    if (work->scl.z > size) {
        size = work->scl.z;
    }
    size += 1.0F;
    model = MAlloc(sizeof(NJS_MODEL));
    *model = *scaffold_object.model;
    VARS(work)->model = model;
    model->r *= size;
    VARS(work)->world = world = GetMobileLandObject();
    world->scl[0] = work->scl.x + 1.0F;
    world->scl[1] = work->scl.y + 1.0F;
    world->scl[2] = work->scl.z + 1.0F;
    world->ang[0] = 0;
    world->ang[1] = work->ang.y;
    world->ang[2] = 0;
    world->pos[0] = work->pos.x;
    world->pos[1] = work->pos.y;
    world->pos[2] = work->pos.z;
    world->model = model;
    work->flags &= ~WORLD_TESTED;
    size *= SCAFFOLD_REACH;
    flags = WORLD_SOLID | WORLD_HUGE;
    if (size <= WORLD_SMALL_REACH) {
        flags = WORLD_SOLID | WORLD_SMALL;
    } else if (size <= WORLD_MEDIUM_REACH) {
        flags = WORLD_SOLID | WORLD_MEDIUM;
    } else if (size <= WORLD_LARGE_REACH) {
        flags = WORLD_SOLID | WORLD_LARGE;
    }
    RegisterCollisionEntry(flags, task, world);
}

void Die(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->world) {
        WithdrawCollisionEntry(task, VARS(work)->world);
        ReleaseMobileLandObject(VARS(work)->world);
    }
    Free(VARS(work)->model);
}

void scaffold_run(struct task *task)
{
    struct task_work *work = task->work;
    Float size;
    NJS_OBJECT *world;

    if (CheckRangeOut(task)) {
        return;
    }
    world = VARS(work)->world;
    if (world) {
        size = work->scl.x;
        if (size < work->scl.y) {
            size = work->scl.y;
        }
        if (size < work->scl.z) {
            size = work->scl.z;
        }
        if (player_in_range(&work->pos,
                            ((size + 1.0F) * SCAFFOLD_REACH) + NEAR_MARGIN)) {
            work->flags |= WORLD_TESTED;
        } else {
            work->flags &= ~WORLD_TESTED;
        }
    }
    scaffold_draw(task);
}

void scaffold_draw(struct task *task)
{
    struct task_work *work = task->work;
    Float size;
    Float reach;
    Angle ang;

    if (CheckRangeOut(task)) {
        return;
    }
    size = work->scl.x;
    if (size < work->scl.y) {
        size = work->scl.y;
    }
    if (size < work->scl.z) {
        size = work->scl.z;
    }
    size += 1.0F;
    reach = size * DRAW_RADIUS;
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, reach)) {
        return;
    }
    njSetTexture_jp(&texlist_obj_mountain);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njScale(NULL, work->scl.x + 1.0F, work->scl.y + 1.0F, work->scl.z + 1.0F);
    ds_DrawModelClip(scaffold_object.model);
    late_DrawObjectClipEx(1);
}
