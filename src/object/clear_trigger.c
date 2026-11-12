/* @unit 8C0A28E0-8C0A2AE0 @data 8C15B4AC-8C15B4B8 +egflags +r04 +pool32 */
/* the clear trigger, O CLROBJ in the object lists. player 0's touch clears
 * the stage. in STAGE_MOUNTAIN, STAGE_RUIN and STAGE_FINAL, once Sonic has
 * cleared the stage, a capsule stands in the trigger's place instead */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "object/capsule.h"
#include "object/clear_trigger.h"
#include "object/placement.h"
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
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
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

/* the trigger's reach is REACH * (work->scl.x + 1) */
#define REACH 14.0F

/* the trigger's work->mode. it has no 1, and clear_trigger_step no case
 * for one */
#define VARS(work) ((struct clear_trigger_vars *)&(work)->vars)
enum clear_trigger_mode {
    CLEAR_INIT = 0,
    CLEAR_WAIT = 2, /* waits for player 0's touch, or for the flag */
    CLEAR_CAPSULE = 3, /* makes the capsule */
    CLEAR_PLACED = 4, /* the capsule stands in the trigger's place */
    CLEAR_DONE = 5 /* touched */
};

struct clear_trigger_vars {
    /* the event flag that puts a capsule in the trigger's place: Sonic's
     * clear of STAGE_MOUNTAIN, STAGE_RUIN or STAGE_FINAL. in any other
     * stage it stays 0, as task_create zeroes the work */
    Sint32 flag;
};

static void clear_trigger_draw(struct task *task);
static void clear_trigger_touch(struct task *task);

void ObjectClearObj(struct task *task)
{
    struct task_work *work = task->work;
    struct task *capsule;
    Uint16 stage;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case CLEAR_INIT:
        work->mode = CLEAR_WAIT;
        stage = (Uint8)(GetStageNumber() >> 8);
        switch (stage) {
        case STAGE_MOUNTAIN:
            VARS(work)->flag = FLAG_SONIC_CLEAR_MOUNTAIN;
            break;
        case STAGE_RUIN:
            VARS(work)->flag = FLAG_SONIC_CLEAR_RUIN;
            break;
        case STAGE_FINAL:
            VARS(work)->flag = FLAG_SONIC_CLEAR_FINAL_EGG;
            break;
        }
        break;
    case CLEAR_WAIT:
        if (SeqCheckFlag(VARS(work)->flag)) {
            work->mode = CLEAR_CAPSULE;
        } else {
            if (!OnEdit(task)) {
                clear_trigger_touch(task);
            }
            if (OnEdit(task)) {
                njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- SCALE");
            }
            if (OnEdit(task) || edit_mode == 1) {
                clear_trigger_draw(task);
            }
        }
        break;
    case CLEAR_CAPSULE:
        capsule = CreateElementalTask(TASK_WORK, 2, ObjectReleaseBox);
        capsule->work->pos.x = work->pos.x;
        capsule->work->pos.y = work->pos.y;
        capsule->work->pos.z = work->pos.z;
        work->mode = CLEAR_PLACED;
        break;
    case CLEAR_DONE:
    case CLEAR_PLACED:
        break;
    }
}

/* draw marker_object at the trigger for the set editor: a ball of radius
 * 10 * (work->scl.x + 1) */
static void clear_trigger_draw(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack type: the scale as the x of a vector, which SHC stores at @R15
     * and loads back into FR15 after njTranslate (0x8c0a8c44, 0x8c0a8c5c).
     * as a Float, SHC holds it in FR15 across both calls, and 40 of 41
     * words differ */
    NJS_VECTOR scale;

    scale.x = work->scl.x + 1.0F;
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    njScale(NULL, scale.x, scale.x, scale.x);
    late_DrawObject(&object_sphere01);
    late_DrawObjectClipEx(1);
}

/* clear the stage once player 0 is within the trigger's reach.
 * player_in_range gives 1 for player 0 */
static void clear_trigger_touch(struct task *task)
{
    struct task_work *work = task->work;

    if (player_in_range(&work->pos, (work->scl.x + 1.0F) * REACH) == 1) {
        SetFinishAction();
        work->mode = CLEAR_DONE;
    }
}
