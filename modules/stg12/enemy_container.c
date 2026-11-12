/* @unit 0C912A80-0C912DE0 +egflags +pool32 */
/* O ENEMYCONTAINER: a container whose door opens as a player comes near */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/world.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stg12/container_door.h"
#include "stg12/enemy_container.h"
#include "stg12/texlists.h"
#include "system/frame.h"
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
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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

/* the container, drawn by its action, whose motion opens the door */
/* @hack type: declared an array, not the one NJS_ACTION it is, so SHC
 * pools its address and reads motion through it, MOV.L @(4,R3),R2 at
 * 0x0c913536; declared as one, 3 of enemy_container_run's 114 words and a
 * pool word differ */
#define CONTAINER_FLAGS (WORLD_LARGE | WORLD_MOVES)
#define OPEN_X 110.0F
#define OPEN_Z 30.0F
#define OPEN_RANGE 55.0F
#define SE_OPEN 327
#define VARS(work) ((struct enemy_container_vars *)&(work)->vars)
extern NJS_ACTION enemy_container_action[];
/* the body's model, for the collision world */
extern NJS_OBJECT enemy_container_body_object;

/* a player within OPEN_RANGE of the container's position, moved OPEN_X along
 * x and -OPEN_Z along z, opens it. the offset ignores the container's turn */

enum enemy_container_mode { CONTAINER_SHUT, CONTAINER_OPENING, CONTAINER_OPEN };

struct enemy_container_vars {
    NJS_OBJECT *object; /* in the collision world */
    Float frame;
};

void enemy_container_run(struct task *task);
void enemy_container_draw(struct task *task);
void enemy_container_destroy(struct task *task);
void enemy_container_door_start(struct task *task);
void enemy_container_door_step(struct task *task);
void enemy_container_door_destroy(struct task *task);

void enemy_container_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    work->ang.x = 0;
    work->ang.z = 0;
    work->mode = CONTAINER_SHUT;
    work->timer = 300;
    if (!OnEdit(task)) {
        VARS(work)->object = object = GetMobileLandObject();
        object->evalflags = NJD_EVAL_BREAK;
        object->scl[0] = 1.0F;
        object->scl[1] = 1.0F;
        object->scl[2] = 1.0F;
        object->ang[0] = 0;
        object->ang[1] = work->ang.y;
        object->ang[2] = 0;
        object->pos[0] = work->pos.x;
        object->pos[1] = work->pos.y;
        object->pos[2] = work->pos.z;
        object->model = enemy_container_body_object.model;
        object->child = NULL;
        object->sibling = NULL;
        RegisterCollisionEntry(CONTAINER_FLAGS, task, object);
        work->flags |= WORLD_TESTED;
        CreateChildTask(TASK_WORK | TASK_FORCE, enemy_container_door_start,
                        task);
    }
    task->step = enemy_container_run;
    task->draw = enemy_container_draw;
    task->destructor = enemy_container_destroy;
}

void enemy_container_run(struct task *task)
{
    struct task_work *work = task->work;
    Float x;
    Float z;
    Float last;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case CONTAINER_SHUT:
        x = work->pos.x;
        z = work->pos.z;
        work->pos.x += OPEN_X;
        work->pos.z -= OPEN_Z;
        if (player_in_range(&work->pos, OPEN_RANGE)) {
            work->mode = CONTAINER_OPENING;
            VARS(work)->frame = 0.0F;
            dsPlay_oneshot(SE_OPEN, 0, 0, 0);
        }
        work->pos.x = x;
        work->pos.z = z;
        LoopTaskC(task);
        break;
    case CONTAINER_OPENING:
        VARS(work)->frame += 1.0F;
        last = (Float)(enemy_container_action->motion->nbFrame - 1);
        if (VARS(work)->frame >= last) {
            VARS(work)->frame = last;
            work->mode = CONTAINER_OPEN;
            FreeTaskC(task);
        }
        break;
    case CONTAINER_OPEN:
        break;
    }
    enemy_container_draw(task);
}

void enemy_container_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count == 0) {
        njSetTexture_jp(&hotshelter4_texlist);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
        ds_ActionClip(enemy_container_action,
                      ((struct enemy_container_vars *)&(work)->vars)->frame);
        late_DrawObjectClipEx(1);
    }
}

void enemy_container_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->object) {
        WithdrawCollisionEntry(task, VARS(work)->object);
        ReleaseMobileLandObject(VARS(work)->object);
    }
    FreeTaskC(task);
}

/* a child that holds the shut door in the collision world. the container
 * destroys it once open */
void enemy_container_door_start(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    work->ang.x = 0;
    work->ang.z = 0;
    VARS(work)->object = object = GetMobileLandObject();
    object->evalflags = NJD_EVAL_BREAK;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    object->ang[0] = 0;
    object->ang[1] = work->ang.y;
    object->ang[2] = 0;
    object->pos[0] = work->pos.x;
    object->pos[1] = work->pos.y;
    object->pos[2] = work->pos.z;
    object->model = enemy_container_door_object.model;
    object->child = NULL;
    object->sibling = NULL;
    RegisterCollisionEntry(CONTAINER_FLAGS, task, object);
    work->flags |= WORLD_TESTED;
    task->step = enemy_container_door_step;
    task->destructor = enemy_container_door_destroy;
}

void enemy_container_door_step(struct task *task)
{
}

void enemy_container_door_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->object) {
        WithdrawCollisionEntry(task, VARS(work)->object);
        ReleaseMobileLandObject(VARS(work)->object);
    }
}
