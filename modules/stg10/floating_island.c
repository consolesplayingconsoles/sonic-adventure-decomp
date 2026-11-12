/* @unit 0C910640-0C910A60 @data 0C9199C8-0C919A0C +egflags +pool32 */
/* O Ukishima floating island that sways along its z and rises and falls,
 * carrying what stands on it */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/world.h"
#include "debug/editor.h"
#include "debug/print.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg10/floating_island.h"
#include "system/frame.h"
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
extern struct set_file *pObjEditTable;
Bool FUN_8c091852(struct task *task);
Bool CheckRangeOut(struct task *task);
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

#define NEAR 48.0F
#define VARS(work) ((struct island_vars *)&(work)->vars)
#define FORCE(task) ((struct task_force *)(task)->force)
#define PHASE(work) ((work)->ang.x)
#define PHASE_STEP(work) ((work)->ang.z)
#define RISE(work) ((work)->scl.y)
#define SWAY(work) ((work)->scl.z)
#define OBJECT(work) (*(NJS_OBJECT **)&(work)->collision)
extern NJS_OBJECT floating_island_object;
/* the model the collision world tests for the island. its pos is the
 * model's offset from the island */
extern NJS_OBJECT floating_island_world_object;

/* the collision world tests the island while a player is this near */

struct island_vars {
    NJS_POINT3 home; /* the set entry's position: the middle of the ride */
};

/* the ride, from the set entry. the island sways SWAY(work) either way along
 * its own z, and rises and falls RISE(work). both go as the sine of
 * PHASE(work), which gains PHASE_STEP(work) each step */

/* the island's object in the collision world, kept in work->collision.
 * task_free_work frees a non-null collision record there, so the destructor
 * clears it first */

enum island_mode { ISLAND_INIT, ISLAND_RUN };

void floating_island_init(struct task *task);
void floating_island_ride(struct task *task);
void floating_island_draw(struct task *task);
void floating_island_add(struct task *task);
void floating_island_destroy(struct task *task);

void ObjectFinalEggUkishima(struct task *task)
{
    struct task_work *work = task->work;

    if (FUN_8c091852(task)) {
        return;
    }
    if (!OnEdit(task)) {
        switch (work->mode) {
        case ISLAND_INIT:
            floating_island_init(task);
            break;
        case ISLAND_RUN:
            floating_island_draw(task);
            PHASE(work) += PHASE_STEP(work);
            work->pos.y =
                VARS(work)->home.y + (njSin(PHASE(work)) * RISE(work));
            floating_island_ride(task);
            break;
        }
    } else {
        switch (work->mode) {
        case ISLAND_INIT:
            floating_island_init(task);
            break;
        case ISLAND_RUN:
            debug_print(EDITOR_LABEL(EDITOR_ROW_ANG_X), "OFFSET");
            debug_print(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "-> ROTATE Y");
            debug_print(EDITOR_LABEL(EDITOR_ROW_ANG_Z), "MOVE SPEED");
            debug_print(EDITOR_LABEL(EDITOR_ROW_SCL_X), "NO USE");
            debug_print(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "MOVE Y");
            debug_print(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "MOVE Z");
            floating_island_draw(task);
            floating_island_ride(task);
            break;
        }
    }
}

void floating_island_init(struct task *task)
{
    struct task_work *work = task->work;

    task->draw = floating_island_draw;
    task->destructor = floating_island_destroy;
    floating_island_add(task);
    work->mode = ISLAND_RUN;
}

/* sway the island along its own z by its phase. both of the task's struct
 * task_force records take the island's move this step as their speed. that
 * speed carries the players standing on the island. the island's object in
 * the collision world follows the island */
void floating_island_ride(struct task *task)
{
    struct task_work *work;
    NJS_VECTOR offset = {0.0F, 0.0F, 0.0F};
    Float old_x;
    Float old_y;
    Float old_z;
    NJS_OBJECT *from;
    NJS_OBJECT *object;
    Angle ang;

    work = task->work;
    old_x = work->pos.x;
    /* @bug logic: the island carries its riders along x and z only, not as
     * it rises and falls. floating_island_step has already moved pos.y when
     * the ride reads it as the old height (0x0c910fec), so both records' y
     * speed is pos.y less itself (FSUB at 0x0c91106c), always 0 */
    old_y = work->pos.y;
    old_z = work->pos.z;
    njPushMatrix(&nj_unit_matrix_);
    offset.z = njSin(PHASE(work)) * SWAY(work);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njCalcVector(NULL, &offset, &offset);
    work->pos.x = VARS(work)->home.x + offset.x;
    work->pos.z = VARS(work)->home.z + offset.z;
    late_DrawObjectClipEx(1);
    FORCE(task)[1].speed.x = FORCE(task)[0].speed.x = work->pos.x - old_x;
    FORCE(task)[1].speed.y = FORCE(task)[0].speed.y = work->pos.y - old_y;
    FORCE(task)[1].speed.z = FORCE(task)[0].speed.z = work->pos.z - old_z;
    if (player_in_range(&work->pos, NEAR)) {
        work->flags |= WORLD_TESTED;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
    from = &floating_island_world_object;
    object = OBJECT(work);
    object->ang[0] = 0;
    object->ang[1] = work->ang.y;
    object->ang[2] = 0;
    object->pos[0] = work->pos.x + from->pos[0];
    object->pos[1] = work->pos.y + from->pos[1];
    object->pos[2] = work->pos.z + from->pos[2];
    /* the timer counts 0 to 20, round and round, and nothing else reads it */
    work->timer++;
    if (TASK_TIMER(work) >= 21) {
        work->timer = 0;
    }
}

void floating_island_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count == 0) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        late_DrawObject(&floating_island_object);
        late_DrawObjectClipEx(1);
    }
}

void floating_island_add(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *from;
    NJS_OBJECT *object;

    VARS(work)->home.x = work->pos.x;
    VARS(work)->home.y = work->pos.y;
    VARS(work)->home.z = work->pos.z;
    from = &floating_island_world_object;
    OBJECT(work) = object = GetMobileLandObject();
    object->evalflags = from->evalflags;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    object->ang[0] = 0;
    object->ang[1] = work->ang.y;
    object->ang[2] = 0;
    object->pos[0] = work->pos.x + from->pos[0];
    object->pos[1] = work->pos.y + from->pos[1];
    object->pos[2] = work->pos.z + from->pos[2];
    object->model = from->model;
    object->child = NULL;
    object->sibling = NULL;
    RegisterCollisionEntry(WORLD_MOVES, task, object);
    work->timer = 0;
}

void floating_island_destroy(struct task *task)
{
    struct task_work *work = task->work;

    WithdrawCollisionEntry(task, OBJECT(work));
    ReleaseMobileLandObject(OBJECT(work));
    OBJECT(work) = NULL;
}
