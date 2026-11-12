/* @unit 0C90BA60-0C90BD00 +r04 +egflags +pool32 */
/* the workshop's runway, its six trees and its four panels, which event flags
 * move out */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv02/runway.h"
#include "adv02/texlists.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
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
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
Bool OnEdit(struct task *task);
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

/* the trees' action's object, whose children are the trees */
/* @hack type: declared an array, not the one NJS_OBJECT it is, so SHC pools
 * its address at 0x0c90bf60 and reads child through it, MOV.L @(44,R6),R6 at
 * 0x0c90bed6; declared as one, it pools child's address, and 22 of
 * runway_init's 85 words and 1 pool word differ */
#define TREES 6
#define RUNWAY_X 1487.23F
#define RUNWAY_Y 172.26F
#define RUNWAY_Z 802.42F
#define RUNWAY_ANG 0x1ae8
#define TREES_ANG 0x1a7b
#define PANELS_X 1421.98F
#define PANELS_Y 191.8F
#define PANELS_Z 734.89F
#define PANELS_ANG 0x5b43
#define FRAME_SPEED 0.3F
#define RADIUS 1000.0F /* the collision record's radius */
#define RUNWAY_OUT(work) ((work)->submode)
#define PANELS_OUT(work) ((work)->tick)
#define VARS(work) ((struct runway_vars *)&(work)->vars)
extern NJS_OBJECT runway_trees_object[];
/* @hack type: each action declared an array, not the one NJS_ACTION it is, so
 * SHC pools its address and reads motion through it twice. declared as one, it
 * pools motion's address and reads motion once, and runway_update runs 2 bytes
 * shorter. for the panels' action, pooled at 0x0c90c0f8 and read through by
 * MOV.L @(4,R5),R3 at 0x0c90c082 and MOV.L @(4,R5),R2 at 0x0c90c09e, 33 of
 * runway_update's 161 words differ */
extern NJS_ACTION runway_panels_action[];
/* @hack type: as runway_panels_action: pooled at 0x0c90c0f4 and read through by
 * MOV.L @(4,R5),R3 at 0x0c90c034 and MOV.L @(4,R5),R2 at 0x0c90c050. declared
 * as one, 69 of runway_update's 161 words differ */
extern NJS_ACTION runway_trees_action[];
/* @hack type: as runway_panels_action: pooled at 0x0c90c0ec and read through by
 * MOV.L @(4,R5),R3 at 0x0c90bff6 and MOV.L @(4,R5),R2 at 0x0c90c012. declared
 * as one, 97 of runway_update's 161 words differ */
extern NJS_ACTION runway_action[];

/* the fixed positions and y angles. the trees share the runway's position */

/* the action frames each action plays each step */

enum runway_mode { RUNWAY_INIT, RUNWAY_RUN };

/* work->submode is TRUE while the runway is out, and work->tick while the
 * panels are out */

/* the frame each of the three actions is at */
struct runway_vars {
    Float panels;
    Float runway;
    Float trees;
};

static void runway_init(struct task *task);
void runway_reset(struct task *task);
void runway_update(struct task *task);
void runway_draw(struct task *task);
void runway_destroy(struct task *task);
extern struct collision_shape runway_shapes[1 + 6];
void runway_step(struct task *task);

static void runway_init(struct task *task)
{
    struct task_work *work = task->work;
    struct collision_shape *shape;
    NJS_OBJECT *tree;
    int i;

    work->pos.x = RUNWAY_X;
    work->pos.y = RUNWAY_Y;
    work->pos.z = RUNWAY_Z;
    work->ang.y = RUNWAY_ANG;
    task->draw = runway_draw;
    task->destructor = runway_destroy;
    VARS(work)->panels = 0.0F;
    VARS(work)->runway = 0.0F;
    VARS(work)->trees = 0.0F;
    CCL_Init(task, runway_shapes, COLLISION_OBJECT, 1, 1 + TREES);
    shape = work->collision->shapes + 1;
    tree = runway_trees_object->child;
    for (i = 0; i < TREES; i++) {
        /* @hack type: tree->pos, a Float[3], read whole as an NJS_POINT3;
         * without it, as three element reads, the function runs 18 bytes long
         * and 51 of 85 words differ */
        shape->center = *(NJS_POINT3 *)tree->pos;
        shape++;
        tree = tree->sibling;
    }
    work->collision->radius = RADIUS;
    runway_reset(task);
    work->mode = RUNWAY_RUN;
}

/* put the runway in, with its box not solid, and the panels in */
void runway_reset(struct task *task)
{
    struct task_work *work = task->work;

    work->collision->shapes->flags |= SHAPE_OFF;
    RUNWAY_OUT(work) = FALSE;
    PANELS_OUT(work) = FALSE;
}

/* while FLAG_RUNWAY is set, the runway's and the trees' actions play to their
 * last frames, and the runway's box is solid. while FLAG_RUNWAY_PANELS is set,
 * the panels' action plays the same way. each action goes back to its first
 * frame once its flag clears */
void runway_update(struct task *task)
{
    struct task_work *work = task->work;

    if (seqVars[FLAG_RUNWAY]) {
        if (!RUNWAY_OUT(work)) {
            work->collision->shapes->flags &= ~SHAPE_OFF;
            RUNWAY_OUT(work) = TRUE;
        }
    } else {
        if (RUNWAY_OUT(work)) {
            work->collision->shapes->flags |= SHAPE_OFF;
            RUNWAY_OUT(work) = FALSE;
        }
    }
    if (seqVars[FLAG_RUNWAY_PANELS]) {
        if (!PANELS_OUT(work)) {
            PANELS_OUT(work) = TRUE;
        }
    } else {
        if (PANELS_OUT(work)) {
            PANELS_OUT(work) = FALSE;
        }
    }
    if (RUNWAY_OUT(work)) {
        VARS(work)->runway += FRAME_SPEED;
        if (VARS(work)->runway >= runway_action->motion->nbFrame - 1.0F) {
            VARS(work)->runway = runway_action->motion->nbFrame - 1.0F;
        }
        VARS(work)->trees += FRAME_SPEED;
        if (VARS(work)->trees >= runway_trees_action->motion->nbFrame - 1.0F) {
            VARS(work)->trees = runway_trees_action->motion->nbFrame - 1.0F;
        }
    } else {
        VARS(work)->runway = 0.0F;
        VARS(work)->trees = 0.0F;
    }
    if (PANELS_OUT(work)) {
        VARS(work)->panels += FRAME_SPEED;
        if (VARS(work)->panels >=
            runway_panels_action->motion->nbFrame - 1.0F) {
            VARS(work)->panels = runway_panels_action->motion->nbFrame - 1.0F;
        }
    } else {
        VARS(work)->panels = 0.0F;
    }
    EntryColliList(work);
}

void runway_draw(struct task *task)
{
    struct task_work *work = task->work;

    njPushMatrix(NULL);
    njTranslate(NULL, PANELS_X, PANELS_Y, PANELS_Z);
    njRotateY(NULL, PANELS_ANG);
    njSetTexture_jp(&mrobj_texlist);
    ds_ActionClip(runway_panels_action,
                  ((struct runway_vars *)&(work)->vars)->panels);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, RUNWAY_X, RUNWAY_Y, RUNWAY_Z);
    njRotateY(NULL, RUNWAY_ANG);
    njSetTexture_jp(&mrobj_texlist);
    ds_ActionClip(runway_action, ((struct runway_vars *)&(work)->vars)->runway);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, RUNWAY_X, RUNWAY_Y, RUNWAY_Z);
    njRotateY(NULL, TREES_ANG);
    njSetTexture_jp(&mrobj_texlist);
    ds_ActionClip(runway_trees_action,
                  ((struct runway_vars *)&(work)->vars)->trees);
    late_DrawObjectClipEx(1);
}

void runway_destroy(struct task *task)
{
}
