/* @unit 0C929FA0-0C92A1D8 +r04 +egflags +onepool +asmfunc=FUN_0c92a0d8:0c92a146 */
/* O POOLWATER, the pool's water, whose textures ripple. the pool is drained
 * while FLAG_KNUCKLES_EC_POOL is set */
#include <ninja.h>

#include "adv0100/pool_water.h"
#include "adv0100/texlists.h"
#include "collision/world.h"
#include "draw/tree.h"
#include "player/player.h"
#include "progress/progress.h"
#include "system/task.h"
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
void FUN_0c929fa0(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
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
Bool SeqCheckStage(int stage, int act);
void SeqChangeStage(int stage, int act);
Bool SeqCheckNextStage(Uint8 stage, Uint8 act);
Bool SeqCheckClearAction(int stage);

#define FLAG_KNUCKLES_EC_POOL 269
#define RIPPLE_FRAMES 14
#define RIPPLE_STEPS 4
#define RIPPLE_MATERIALS 3
#define VARS(work) ((struct pool_water_vars *)&(work)->vars)
#define RIPPLE(work) ((work)->tick) /* the ripple's frame */
#define WATER_FULL 0x400
extern NJS_OBJECT pool_water_object;
/* the water's collision model, in which a player swims */
extern NJS_OBJECT pool_water_solid_object;

/* the flag Knuckles' story sets as it plays event 289 in act 2. it drains
 * the pool, and opens the pool door for Knuckles */

/* the ripple's frames, which are the first textures of ec_water_texlist, and
 * the steps each lasts. the model's first RIPPLE_MATERIALS materials show
 * it */

struct pool_water_vars {
    NJS_OBJECT *solid; /* in the collision world */
    NJS_OBJECT *from; /* the object whose model, evalflags and pos it takes */
};

/* in work->flags, set while the pool is full */

enum pool_water_mode { WATER_INIT, WATER_RUN, WATER_DRAINED };

void pool_water_destroy(struct task *task);
void pool_water_draw(struct task *task);

/* add the water to the collision world as solid water, where its model
 * stands. while the pool is full, advance the ripple every RIPPLE_STEPS
 * steps. the world tests the water while player 0 is within 100 of it. while
 * the pool is drained, the step returns before that test, so WORLD_TESTED
 * keeps the value it had as the pool drained */
void FUN_0c929fa0(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *solid;

    switch (work->mode) {
    case WATER_INIT:
        VARS(work)->from = &pool_water_solid_object;
        VARS(work)->solid = solid = GetMobileLandObject();
        solid->evalflags = VARS(work)->from->evalflags | NJD_EVAL_BREAK;
        solid->scl[0] = 1.0F;
        solid->scl[1] = 1.0F;
        solid->scl[2] = 1.0F;
        solid->ang[0] = 0;
        solid->ang[1] = 0;
        solid->ang[2] = 0;
        solid->pos[0] = VARS(work)->from->pos[0];
        solid->pos[1] = VARS(work)->from->pos[1];
        solid->pos[2] = VARS(work)->from->pos[2];
        solid->model = VARS(work)->from->model;
        solid->child = NULL;
        solid->sibling = NULL;
        RegisterCollisionEntry(WORLD_SOLID | WORLD_WATER, task, solid);
        work->flags |= WATER_FULL;
        RIPPLE(work) = 0;
        work->timer = RIPPLE_STEPS;
        task->destructor = pool_water_destroy;
        task->draw = pool_water_draw;
        work->mode = WATER_RUN;
        break;
    case WATER_RUN:
        if (!--TASK_TIMER(work)) {
            work->timer = RIPPLE_STEPS;
            RIPPLE(work)++;
            if (RIPPLE(work) == RIPPLE_FRAMES) {
                RIPPLE(work) = 0;
            }
        }
        if (SeqCheckFlag(FLAG_KNUCKLES_EC_POOL)) {
            work->flags &= ~WATER_FULL;
            work->mode = WATER_DRAINED;
        }
        break;
    case WATER_DRAINED:
        if (!SeqCheckFlag(FLAG_KNUCKLES_EC_POOL)) {
            work->flags |= WATER_FULL;
            work->mode = WATER_RUN;
        }
        return;
    }
    work->flags &= ~WORLD_TESTED;
    if (CalcDistance(&playertwp[0]->pos, (NJS_POINT3 *)VARS(work)->solid->pos) <
        100.0F) {
        work->flags |= WORLD_TESTED;
    }
    pool_water_draw(task);
}
#ifdef NON_MATCHING

void pool_water_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->solid != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->solid);
        ReleaseMobileLandObject(VARS(work)->solid);
    }
}
#else
void pool_water_destroy(struct task *task)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
}
#endif

/* draw the water at the ripple's frame while the pool is full */
void pool_water_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;
    NJS_MATERIAL *material;
    int i;

    if (!(work->flags & WATER_FULL)) {
        return;
    }
    object = &pool_water_object;
    material = object->model->mats;
    for (i = 0; i < RIPPLE_MATERIALS; i++, material++) {
        material->attr_texId = RIPPLE(work);
    }
    njSetTexture_jp(&ec_water_texlist);
    njPushMatrix(NULL);
    late_DrawObject(object);
    late_DrawObjectClipEx(1);
}
