/* @unit 0C90B3C0-0C90B620 +egflags +pool32 */
/* the statue the object list names O KNUCKLES STUTUE, as the disc spells it.
 * it stands in the jungle, and moves aside once FLAG_SONIC_MR_ENTRANCE_RUIN is
 * set */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv02/knuckles_statue.h"
#include "collision/world.h"
#include "draw/draw.h"
#include "object/placement.h"
#include "player/player.h"
#include "progress/progress.h"
#include "stage/stage.h"
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
int Serif_Play(const NJS_POINT3 *pos, Float radius);
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

/* the action that moves the statue aside, and the statue's collision models,
 * standing and aside */
#define FRAME_SPEED 0.2F /* the action frames the statue advances each step */
#define ASIDE_FRAME 53.99F
#define NEAR 100.0F
#define STATUE_FLAGS (WORLD_MEDIUM | WORLD_SOLID)
#define VARS(work) ((struct knuckles_statue_vars *)&(work)->vars)
extern NJS_ACTION knuckles_statue_action;
extern NJS_OBJECT knuckles_statue_object;
/* @hack type: declared an array, not the one NJS_OBJECT it is, so SHC pools
 * its address at 0x0c90b9d0 and reads model through it, MOV.L @(4,R3),R1 at
 * 0x0c90b96e; declared as one, 7 of knuckles_statue_step's 110 words and a
 * pool word differ */
extern NJS_OBJECT knuckles_statue_aside_object[];

/* the action's last frame, with the statue aside */

/* the collision world tests the statue only while a player is this near */

enum knuckles_statue_mode {
    STATUE_INIT,
    STATUE_STANDING,
    STATUE_MOVING,
    STATUE_ASIDE
};

struct knuckles_statue_vars {
    NJS_OBJECT *object; /* the statue's copy in the collision world */
    NJS_OBJECT *from; /* what knuckles_statue_add_to_world copies */
    Float frame;
};

void KnucklesStutueDisplayer(struct task *task);
void KnucklesStutueDestructor(struct task *task);
void KnucklesStutueInit(struct task *task);

/* the statue tests FLAG_SONIC_MR_ENTRANCE_RUIN, Sonic's flag, whoever plays.
 * it moves aside for any character once Sonic has set the flag, and it starts
 * aside only for Sonic */
void ObjectMysticRuinKnucklesStutue(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOut(task)) {
        switch (work->mode) {
        case STATUE_INIT:
            if (GetPlayerNumber() == CHARACTER_SONIC &&
                SeqCheckFlag(FLAG_SONIC_MR_ENTRANCE_RUIN)) {
                VARS(work)->from = knuckles_statue_aside_object;
                VARS(work)->frame = ASIDE_FRAME;
                work->mode = STATUE_ASIDE;
            } else {
                VARS(work)->from = &knuckles_statue_object;
                VARS(work)->frame = 0.0F;
                work->mode = STATUE_STANDING;
            }
            KnucklesStutueInit(task);
            task->draw = KnucklesStutueDisplayer;
            task->destructor = KnucklesStutueDestructor;
            /* every statue starts in STATUE_STANDING: this replaces the mode
             * either branch set. a statue that starts aside already holds
             * ASIDE_FRAME, and its next two steps take it through
             * STATUE_MOVING back to STATUE_ASIDE */
            work->mode = STATUE_STANDING;
            break;
        case STATUE_STANDING:
            if (SeqCheckFlag(FLAG_SONIC_MR_ENTRANCE_RUIN)) {
                work->mode = STATUE_MOVING;
            }
            break;
        case STATUE_MOVING:
            VARS(work)->frame += FRAME_SPEED;
            if (VARS(work)->frame >= ASIDE_FRAME) {
                VARS(work)->frame = ASIDE_FRAME;
                work->mode = STATUE_ASIDE;
                VARS(work)->object->model = knuckles_statue_aside_object->model;
            }
            break;
        case STATUE_ASIDE:
        default:
            break;
        }
        work->flags &= ~0x100;
        if (Serif_Play(&work->pos, 100.0F) > 0) {
            work->flags |= 0x100;
        }
        KnucklesStutueDisplayer(task);
    }
}

void KnucklesStutueDisplayer(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
    ds_ActionClip(&knuckles_statue_action,
                  ((struct knuckles_statue_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

void KnucklesStutueDestructor(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->object != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->object);
        ReleaseMobileLandObject(VARS(work)->object);
    }
}

void KnucklesStutueInit(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *from = VARS(work)->from;
    NJS_OBJECT *object;

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
    object->model = from->model;
    object->child = NULL;
    object->sibling = NULL;
    RegisterCollisionEntry(STATUE_FLAGS, task, object);
}
