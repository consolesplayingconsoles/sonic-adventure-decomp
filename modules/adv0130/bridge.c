/* @unit 0C922780-0C922A60 +egflags +pool32 */
/* O BRIDGE, a bridge that rises out of the way while FLAG_BRIDGE_UP is set */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv0130/bridge.h"
#include "collision/world.h"
#include "draw/draw.h"
#include "object/placement.h"
#include "player/player.h"
#include "progress/progress.h"
#include "sound/sound.h"
#include "system/task.h"
#include "system/texture.h"
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);

#define BRIDGE_TOP 99.99F
#define BRIDGE_SPEED 0.5F
#define BRIDGE_SHOW_DOWN 0x400
#define BRIDGE_SHOW_UP 0x800
#define TESTED_LOW 60.0F
#define TESTED_HIGH 90.0F
#define SE_BRIDGE 706
#define VARS(work) ((struct bridge_vars *)&(work)->vars)
extern NJS_ACTION bridge_down_action;
extern NJS_ACTION bridge_down2_action;
extern NJS_ACTION bridge_up_action;
extern NJS_ACTION bridge_up2_action;
extern NJS_ACTION bridge_up3_action;
extern NJS_ACTION bridge_up4_action;
extern NJS_OBJECT bridge_solid_object;

/* the actions' frame at which the bridge stands up, and the frames a step
 * it rises and falls by */

/* in work->flags, beside WORLD_TESTED. BRIDGE_SHOW_DOWN draws the down
 * actions, and BRIDGE_SHOW_UP the up actions. both are set while the bridge
 * moves */

/* the collision world tests the surface while the down actions draw and
 * player 0's y lies between TESTED_LOW and TESTED_HIGH */

struct bridge_vars {
    NJS_OBJECT *solid; /* in the collision world */
    NJS_OBJECT *object; /* the object whose place and model solid takes */
    Float frame; /* the actions' frame: 0 down, BRIDGE_TOP up */
};

enum bridge_mode {
    BRIDGE_INIT,
    BRIDGE_DOWN,
    BRIDGE_UP,
    BRIDGE_RISE,
    BRIDGE_FALL
};

void egg_carrier_bridge_destroy(struct task *task);
void egg_carrier_bridge_draw(struct task *task);
void bridge_solid_init(struct task *task, struct task_work *work);

/* raise the bridge once FLAG_BRIDGE_UP is set, and lower it once the flag is
 * clear, each with SE_BRIDGE. the step tests the flag only while the bridge
 * stands up or down, so a bridge that starts to move goes all the way */
void ObjectECHallBridge(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BRIDGE_INIT:
        bridge_solid_init(task, work);
        work->flags |= BRIDGE_SHOW_DOWN;
        work->flags &= ~BRIDGE_SHOW_UP;
        task->destructor = egg_carrier_bridge_destroy;
        task->draw = egg_carrier_bridge_draw;
        work->mode = BRIDGE_DOWN;
        break;
    case BRIDGE_DOWN:
        if (seqVars[FLAG_BRIDGE_UP] == 1) {
            dsPlay_oneshot(SE_BRIDGE, 0, 0, 0);
            work->mode = BRIDGE_RISE;
            work->flags |= BRIDGE_SHOW_UP;
        }
        break;
    case BRIDGE_UP:
        if (seqVars[FLAG_BRIDGE_UP] == 0) {
            dsPlay_oneshot(SE_BRIDGE, 0, 0, 0);
            work->flags |= BRIDGE_SHOW_DOWN;
            work->mode = BRIDGE_FALL;
        }
        break;
    case BRIDGE_RISE:
        VARS(work)->frame += BRIDGE_SPEED;
        if (VARS(work)->frame > BRIDGE_TOP) {
            VARS(work)->frame = BRIDGE_TOP;
            work->mode = BRIDGE_UP;
            work->flags &= ~BRIDGE_SHOW_DOWN;
            work->timer = 0;
        }
        break;
    case BRIDGE_FALL:
        /* @hack spelling: the speed negated and added, -0.5 in the pool at
         * 0x0c9229e8 and an FADD at 0x0c92294a; subtracted, 134 of 161 words
         * differ */
        VARS(work)->frame += -BRIDGE_SPEED;
        if (VARS(work)->frame < 0.0F) {
            VARS(work)->frame = 0.0F;
            work->mode = BRIDGE_DOWN;
            work->flags &= ~BRIDGE_SHOW_UP;
            work->timer = 0;
        }
        break;
    }
    work->flags &= ~WORLD_TESTED;
    if ((work->flags & BRIDGE_SHOW_DOWN) && playertwp[0]->pos.y < TESTED_HIGH &&
        playertwp[0]->pos.y > TESTED_LOW) {
        work->flags |= WORLD_TESTED;
    }
    egg_carrier_bridge_draw(task);
}

void egg_carrier_bridge_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->solid != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->solid);
        ReleaseMobileLandObject(VARS(work)->solid);
    }
}

void egg_carrier_bridge_draw(struct task *task)
{
    struct task_work *work = task->work;

    SetObjectTexture();
    if (work->flags & 0x400) {
        ds_ActionClip(&bridge_down_action,
                      ((struct bridge_vars *)&(work)->vars)->frame);
        ds_ActionClip(&bridge_down2_action,
                      ((struct bridge_vars *)&(work)->vars)->frame);
    }
    if (work->flags & 0x800) {
        ds_ActionClip(&bridge_up_action,
                      ((struct bridge_vars *)&(work)->vars)->frame);
        ds_ActionClip(&bridge_up2_action,
                      ((struct bridge_vars *)&(work)->vars)->frame);
        ds_ActionClip(&bridge_up3_action,
                      ((struct bridge_vars *)&(work)->vars)->frame);
        ds_ActionClip(&bridge_up4_action,
                      ((struct bridge_vars *)&(work)->vars)->frame);
    }
}

void bridge_solid_init(struct task *task, struct task_work *work)
{
    NJS_OBJECT *solid;

    VARS(work)->object = &bridge_solid_object;
    solid = GetMobileLandObject();
    VARS(work)->solid = solid;
    solid->evalflags = NJD_EVAL_BREAK;
    solid->scl[0] = 1.0F;
    solid->scl[1] = 1.0F;
    solid->scl[2] = 1.0F;
    solid->ang[0] = 0;
    /* the surface turns about y by the object's x angle, not its y angle.
     * both are 0 in bridge_solid_object */
    solid->ang[1] = VARS(work)->object->ang[0];
    solid->ang[2] = 0;
    solid->pos[0] = VARS(work)->object->pos[0];
    solid->pos[1] = VARS(work)->object->pos[1];
    solid->pos[2] = VARS(work)->object->pos[2];
    solid->model = VARS(work)->object->model;
    solid->child = NULL;
    solid->sibling = NULL;
    RegisterCollisionEntry(WORLD_SOLID, task, solid);
    work->pos = VARS(work)->object->model->center;
}
