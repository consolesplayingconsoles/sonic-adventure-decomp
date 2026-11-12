/* @unit 0C909BA0-0C90A000 +egflags +pool32 */
/* the containers the object list names O CON and O D CON. O CON slides along
 * z as gravity tilts, and carries whoever stands on it. O D CON stands still
 * until the collapse reaches it, then drifts away */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/world.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "stage/stage.h"
#include "stg06/collapse.h"
#include "stg06/container.h"
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
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
Bool OnEdit(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
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
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Uint16 GetStageNumber(void);
Bool ChkPause(void);
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

#define CONTAINER_RANGE (2010.0F * 2010.0F)
#define CONTAINER_NEAR 70.0F
#define SLIDING_FLAGS (WORLD_MEDIUM | WORLD_MOVES)
#define STILL_FLAGS (WORLD_MEDIUM | WORLD_SOLID)
#define DRIFT_X 1.8F
#define DRIFT_Y 0.4F
#define DRIFT_TURN 32
#define VARS(work) ((struct container_vars *)&(work)->vars)
#define HOME(work) ((work)->scl.z)
extern NJS_OBJECT sky_deck_container_object;
extern NJS_OBJECT container_d_object;
extern NJS_OBJECT container_world_object;

/* the square of the distance from the camera or player 0 within which a
 * container stays */
/* the world tests a container while a player is within CONTAINER_NEAR of
 * its position */

/* once the collapse reaches O D CON, it moves DRIFT_X along x and DRIFT_Y up
 * each step. it also turns DRIFT_TURN about z each step */

struct container_vars {
    NJS_OBJECT *world;
    NJS_OBJECT *object; /* the model it draws, O CON's or O D CON's */
};

/* O CON's z as it started, which its travel is measured from */

enum container_mode { CONTAINER_INIT, CONTAINER_RUN };

/* one of O CON's travels along z. it runs from HOME + low to HOME + high, at
 * speed times gravity's z each step. the first step picks a travel by scl.x,
 * and work->submode holds its index in container_travels */
struct container_travel {
    Float low;
    Float high;
    Float speed;
};
extern struct container_travel container_travels[3];

void sky_deck_container_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    SetObjectTexture();
    late_DrawObject(VARS(work)->object);
    late_DrawObjectClipEx(1);
}

void sky_deck_container_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->world != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->world);
        ReleaseMobileLandObject(VARS(work)->world);
    }
}

/* put O CON's shape in the world where it stands, as one that moves */
void container_add_world(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *shape = &container_world_object;
    NJS_OBJECT *world;

    VARS(work)->world = world = GetMobileLandObject();
    world->evalflags =
        shape->evalflags & ~(NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG);
    world->scl[0] = world->scl[1] = world->scl[2] = 1.0F;
    world->ang[0] = work->ang.x;
    world->ang[1] = work->ang.y;
    world->ang[2] = work->ang.z;
    world->pos[0] = work->pos.x;
    world->pos[1] = work->pos.y;
    world->pos[2] = work->pos.z;
    world->model = shape->model;
    world->child = shape->child;
    world->sibling = shape->sibling;
    RegisterCollisionEntry(SLIDING_FLAGS, task, world);
}

/* put O D CON's shape, the same as O CON's, in the world as a solid one */
void container_d_add_world(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *shape = &container_world_object;
    NJS_OBJECT *world;

    VARS(work)->world = world = GetMobileLandObject();
    world->evalflags =
        shape->evalflags & ~(NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG);
    world->scl[0] = world->scl[1] = world->scl[2] = 1.0F;
    world->ang[0] = work->ang.x;
    world->ang[1] = work->ang.y;
    world->ang[2] = work->ang.z;
    world->pos[0] = work->pos.x;
    world->pos[1] = work->pos.y;
    world->pos[2] = work->pos.z;
    world->model = shape->model;
    world->child = shape->child;
    world->sibling = shape->sibling;
    RegisterCollisionEntry(STILL_FLAGS, task, world);
}

/* move the container's shape to its position and angles. the world tests
 * the shape while a player is within CONTAINER_NEAR of the container */
void container_update_world(struct task_work *work)
{
    NJS_OBJECT *world = VARS(work)->world;

    world->pos[0] = work->pos.x;
    world->pos[1] = work->pos.y;
    world->pos[2] = work->pos.z;
    world->ang[0] = work->ang.x;
    world->ang[1] = work->ang.y;
    world->ang[2] = work->ang.z;
    if (player_in_range(&work->pos, CONTAINER_NEAR)) {
        work->flags |= WORLD_TESTED;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
}

/* O CON's step. each step the container slides along z by its travel's
 * speed times gravity's z. it stops at either end of the travel. its force's
 * speed is the slide, which carries whoever stands on it */
void sky_deck_container_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_force *force = task->force;
    NJS_OBJECT *object;
    Float pos;
    Float home;
    Float speed;
    Sint8 travel;

    if (CheckRangeOutWithR(task, CONTAINER_RANGE)) {
        return;
    }
    object = &sky_deck_container_object;
    if (edit_mode) {
        if (VARS(work)->object == NULL) {
            VARS(work)->object = object;
        }
        sky_deck_container_draw(task);
    } else {
        switch (work->mode) {
        case CONTAINER_INIT:
            work->mode = CONTAINER_RUN;
            task->destructor = sky_deck_container_destroy;
            task->draw = sky_deck_container_draw;
            VARS(work)->object = object;
            container_add_world(task);
            if (work->scl.x < 10.0F) {
                work->submode = 0;
            } else if (work->scl.x < 20.0F) {
                work->submode = 1;
            } else {
                work->submode = 2;
            }
            HOME(work) = work->pos.z;
            break;
        case CONTAINER_RUN:
            pos = work->pos.z;
            home = HOME(work);
            travel = work->submode;
            /* @hack spelling: speed set to the travel's and then multiplied by
             * the tilt in a statement of its own, which keeps it in FR5 for
             * the FMUL at 0x0c90a6d6; as one product, 11 of 135 words
             * differ */
            speed = container_travels[travel].speed;
            speed *= vG.z;
            pos += speed;
            if (pos < home + container_travels[travel].low) {
                pos = home + container_travels[travel].low;
                speed = 0.0F;
            } else if (pos > home + container_travels[travel].high) {
                pos = home + container_travels[travel].high;
                speed = 0.0F;
            }
            work->pos.z = pos;
            force->speed.z = speed;
            container_update_world(work);
            sky_deck_container_draw(task);
            break;
        }
    }
}

/* O D CON's step. once the collapse reaches the container, it drifts away
 * each step. a container that leaves range after that is gone for good: its
 * placement makes no more */
void ObjectSkyDecorativeContainer(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    if (CheckRangeOutWithR(task, CONTAINER_RANGE)) {
        if (work->mode == CONTAINER_RUN) {
            if (SkydeckCheck_break(work->pos.x, work->pos.y, work->pos.z)) {
                DeadOut(task);
            }
        }
        return;
    }
    object = &container_d_object;
    if (edit_mode) {
        if (VARS(work)->object == NULL) {
            VARS(work)->object = object;
        }
        sky_deck_container_draw(task);
    } else {
        switch (work->mode) {
        case CONTAINER_INIT:
            work->mode = CONTAINER_RUN;
            task->destructor = sky_deck_container_destroy;
            task->draw = sky_deck_container_draw;
            VARS(work)->object = object;
            container_d_add_world(task);
            break;
        case CONTAINER_RUN:
            container_update_world(work);
            if (SkydeckCheck_break(work->pos.x, work->pos.y, work->pos.z)) {
                work->ang.z += DRIFT_TURN;
                work->pos.y += DRIFT_Y;
                work->pos.x += DRIFT_X;
            }
            sky_deck_container_draw(task);
            break;
        }
    }
}
