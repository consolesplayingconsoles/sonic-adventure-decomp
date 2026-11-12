/* @unit 0C9085A0-0C908860 +r04 +egflags +pool32 */
/* O JAMER road barrier whose lamps blink */
#include <ninja.h>

#include "collision/world.h"
#include "debug/editor.h"
#include "object/common.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg04/barrier.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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
int texlist_jammer(const NJS_POINT3 *pos, Float radius);
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
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Uint16 GetStageNumber(void);
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define BARRIER_WORLD_FLAGS WORLD_SMALL
#define BARRIER_NEAR 33.0F
#define BLINK_TIMER_MOST 25
extern NJS_OBJECT barrier_object;
/* OBJ_HIGHWAY2's texture names, among them the barrier's with its lamps lit
 * one way, then the other */
extern NJS_TEXNAME obj_highway2_textures[54];

/* the collision world tests the barrier while a player is within BARRIER_NEAR
 * units */

/* the lamps switch each time the timer passes BLINK_TIMER_MOST, so every
 * BLINK_TIMER_MOST + 1 steps */

enum barrier_mode {
    BARRIER_INIT,
    BARRIER_STAND,
    BARRIER_GONE /* this file never sets it */
};

void barrier_add_world(struct task *task);
void changeTexture(struct task_work *work);
void barrier_blink(struct task_work *work);
void barrier_draw(struct task *task);
void exitJammer(struct task *task);
extern NJS_TEXLIST barrier_texlists[2];

void barrier_add_world(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = GetMobileLandObject();

    WORLD_MODEL(work)->model = &barrier_object;
    WORLD_MODEL(work)->world = object;
    object->evalflags = WORLD_MODEL(work)->model->evalflags &
                        ~(NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG);
    object->scl[0] = object->scl[1] = object->scl[2] = 1.0F;
    object->ang[0] = work->ang.x;
    object->ang[1] = work->ang.y;
    object->ang[2] = work->ang.z;
    object->pos[0] = work->pos.x;
    object->pos[1] = work->pos.y;
    object->pos[2] = work->pos.z;
    object->model = WORLD_MODEL(work)->model->model;
    object->child = WORLD_MODEL(work)->model->child;
    object->sibling = WORLD_MODEL(work)->model->sibling;
    RegisterCollisionEntry(BARRIER_WORLD_FLAGS, task, object);
}

void changeTexture(struct task_work *work)
{
    NJS_OBJECT *object = WORLD_MODEL(work)->world;

    object->pos[0] = work->pos.x;
    object->pos[1] = work->pos.y;
    object->pos[2] = work->pos.z;
    object->ang[0] = work->ang.x;
    object->ang[1] = work->ang.y;
    object->ang[2] = work->ang.z;
    if (texlist_jammer(&work->pos, 33.0F)) {
        work->flags |= 0x100;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
}

void barrier_blink(struct task_work *work)
{
    if (++TASK_TIMER(work) > BLINK_TIMER_MOST) {
        work->timer = 0;
        switch (work->submode) {
        case 0:
            work->submode++;
            WORLD_MODEL(work)->texlist = &barrier_texlists[1];
            break;
        case 1:
        default:
            work->submode--;
            WORLD_MODEL(work)->texlist = &barrier_texlists[0];
            break;
        }
    }
}

void barrier_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    njSetTexture_jp(WORLD_MODEL(work)->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njSimpleDrawModel(WORLD_MODEL(work)->world->model);
    late_DrawObjectClipEx(1);
}

/* unless the set editor holds the barrier, remove its copy from the world and
 * free it. task_kill changes nothing here: task_destroy clears the step once a
 * destructor returns */
void exitJammer(struct task *task)
{
    struct task_work *work = task->work;

    if (!OnEdit(task) && WORLD_MODEL(work)->world) {
        WithdrawCollisionEntry(task, WORLD_MODEL(work)->world);
        ReleaseMobileLandObject(WORLD_MODEL(work)->world);
    }
    FreeTask(task);
}

/* barrier_draw draws the model of WORLD_MODEL(work)->world. that is
 * barrier_object for a barrier that first steps with the set editor open, else
 * barrier_add_world's copy */
void ObjectJammer(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *model;
    NJS_TEXLIST *texlists;

    if (CheckRangeOut(task)) {
        return;
    }
    /* @hack spelling: both addresses taken into locals ahead of the editor
     * test, which loads them before it (0x0c908c20, 0x0c908c24); without it,
     * the editor's branch loads barrier_object only where it stores it, 10 of
     * the pool's words differ too, and 54 of 64 words differ */
    texlists = barrier_texlists;
    model = &barrier_object;
    if (edit_mode) {
        if (!WORLD_MODEL(work)->world) {
            WORLD_MODEL(work)->world = model;
        }
        if (!WORLD_MODEL(work)->texlist) {
            WORLD_MODEL(work)->texlist = texlists;
        }
        barrier_blink(work);
        barrier_draw(task);
    } else {
        switch (work->mode) {
        case BARRIER_INIT:
            work->mode = BARRIER_STAND;
            WORLD_MODEL(work)->world = model;
            WORLD_MODEL(work)->texlist = texlists;
            barrier_add_world(task);
            task->destructor = exitJammer;
            task->draw = barrier_draw;
            break;
        case BARRIER_STAND:
            changeTexture(work);
            barrier_blink(work);
            barrier_draw(task);
            break;
        case BARRIER_GONE:
            break;
        }
    }
}
