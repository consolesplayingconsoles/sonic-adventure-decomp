/* @unit 0C922FC0-0C9231E0 +egflags +pool32 */
/* the water of act 4's reservoir, which the object list names O RESERVOIR */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv0130/egg_carrier_inside.h"
#include "adv0130/reservoir.h"
#include "collision/world.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "object/common.h"
#include "player/player.h"
#include "progress/progress.h"
#include "stage/stage.h"
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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

#define RESERVOIR_ACT 4
#define WATER_TEXTURES 14
#define WATER_TEXTURE_STEPS 2
#define TEST_HEIGHT 20.0F
#define RESERVOIR_HIDDEN 0x200
#define WATER_TEXTURE(work) ((work)->tick)
extern NJS_OBJECT reservoir_object;
extern NJS_OBJECT reservoir_solid_object;

/* the surface cycles through WATER_TEXTURES of ec_water_texlist's textures,
 * each shown for WATER_TEXTURE_STEPS steps */

/* a shown surface's collision is tested while player 0 is within TEST_HEIGHT
 * of the solid model's height */

/* in work->flags, beside WORLD_TESTED: the surface isn't drawn. nothing sets
 * it */

/* the surface's texture in ec_water_texlist */

enum reservoir_mode {
    RESERVOIR_INIT,
    RESERVOIR_SHOWN,
    /* the step returns at once. the step that sets it still runs the height
     * test and draws the surface, once. from then on WORLD_TESTED keeps that
     * test's result, and nothing draws the surface */
    RESERVOIR_IDLE
};

void WaterDestructor(struct task *task);
void WaterDisplayer(struct task *task);

/* outside act 4, the step returns at once. the first step in it puts the
 * solid model in the world, solid and water. it then shows the surface if
 * FLAG_E102_EC_TRANSFORM is set, E-102's flag whoever plays, and otherwise
 * idles from then on */
void ObjectECReservoirWater(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *solid;

    if ((Uint8)GetStageNumber() != RESERVOIR_ACT) {
        return;
    }
    switch (work->mode) {
    case RESERVOIR_INIT:
        WORLD_MODEL(work)->model = &reservoir_solid_object;
        solid = GetMobileLandObject();
        WORLD_MODEL(work)->world = solid;
        solid->evalflags = NJD_EVAL_BREAK;
        solid->scl[0] = 1.0F;
        solid->scl[1] = 1.0F;
        solid->scl[2] = 1.0F;
        solid->ang[0] = 0;
        solid->ang[1] = 0;
        solid->ang[2] = 0;
        solid->pos[0] = work->pos.x = WORLD_MODEL(work)->model->pos[0];
        solid->pos[1] = WORLD_MODEL(work)->model->pos[1];
        solid->pos[2] = work->pos.z = WORLD_MODEL(work)->model->pos[2];
        solid->model = WORLD_MODEL(work)->model->model;
        solid->child = NULL;
        solid->sibling = NULL;
        RegisterCollisionEntry(WORLD_SOLID | WORLD_WATER, task, solid);
        task->destructor = WaterDestructor;
        if (!SeqCheckFlag(FLAG_E102_EC_TRANSFORM)) {
            work->mode = RESERVOIR_IDLE;
            task->draw = NULL;
        } else {
            work->mode = RESERVOIR_SHOWN;
            task->draw = WaterDisplayer;
        }
        break;
    case RESERVOIR_SHOWN:
        TASK_TIMER(work)++;
        if (TASK_TIMER(work) == WATER_TEXTURE_STEPS) {
            TASK_TIMER(work) = 0;
            WATER_TEXTURE(work)++;
            if (WATER_TEXTURE(work) == WATER_TEXTURES) {
                WATER_TEXTURE(work) = 0;
            }
        }
        break;
    case RESERVOIR_IDLE:
        return;
    }
    work->flags &= ~WORLD_TESTED;
    if (_builtin_fabsf(playertwp[0]->pos.y - WORLD_MODEL(work)->model->pos[1]) <
        TEST_HEIGHT) {
        work->flags |= WORLD_TESTED;
    }
    WaterDisplayer(task);
}

void WaterDestructor(struct task *task)
{
    struct task_work *work = task->work;

    if (WORLD_MODEL(work)->world != NULL) {
        WithdrawCollisionEntry(task, WORLD_MODEL(work)->world);
        ReleaseMobileLandObject(WORLD_MODEL(work)->world);
    }
}

/* draw the surface with its texture, unless RESERVOIR_HIDDEN is set. it
 * translates the current matrix by pos without pushing it, and leaves it
 * there */
void WaterDisplayer(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = &reservoir_object;

    object->model->mats->attr_texId = WATER_TEXTURE(work);
    if (!(work->flags & RESERVOIR_HIDDEN)) {
        njSetTexture_jp(&ec_water_texlist);
        SetMaterial(-0.3F, 0.0F, 0.0F, 0.0F);
        njTranslateV(NULL, &work->pos);
        late_DrawObject(object);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
