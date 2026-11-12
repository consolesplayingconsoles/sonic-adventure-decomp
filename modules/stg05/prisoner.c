/* @unit 0C90ECA0-0C90EF9C +r04 +egflags +asmfunc=FUN_0c90edd8:0c90ee66 */
/* Syuujin b, Syuujin r and Syuujin g: prisoners who stir where they sit.
 * Syuujin b also swells along x, and Syuujin r along y */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_10 ""
#define TEXT_11 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#define TEXT_6 ""
#define TEXT_7 ""
#define TEXT_8 ""
#define TEXT_9 ""
#include <ninja.h>

#include "debug/editor.h"
#include "draw/draw.h"
#include "object/common.h"
#include "object/placement.h"
#include "stg05/prisoner.h"
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
void FUN_0c90ee66(struct task *task);
void FUN_0c90eeba(struct task *task);
void FUN_0c90ef0e(struct task *task);
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

#define TEXT_1_LENGTH 11
#define TEXT_2_LENGTH 11
#define TEXT_3_LENGTH 10
#define TEXT_4_LENGTH 10
#define TEXT_5_LENGTH 9
#define TEXT_6_LENGTH 11
#define TEXT_7_LENGTH 11
#define TEXT_8_LENGTH 12
#define TEXT_9_LENGTH 12
#define TEXT_10_LENGTH 11
#define TEXT_11_LENGTH 11
#define PRISONER_LAST_FRAME 29.0F
#define PRISONER_PACE 0.1F
#define SWELL_PHASE(work) TASK_TIMER(work)
#define SWELL_STEP 1392
#define SWELL_SIZE 0.1F
extern NJS_TEXLIST texlist_obj_mountain;
extern NJS_ACTION prisoner_action;
extern NJS_TEXNAME prisoner_b_textures[9];
extern NJS_TEXNAME prisoner_r_textures[9];
extern NJS_TEXNAME prisoner_g_textures[9];

void prisoner_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    njSetTexture_jp(&texlist_obj_mountain);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    (((ang) = (work->ang.x)) ? (njRotateX)(((void *)0), (ang)) : (void)0);
    (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
    njScaleV(((void *)0), &work->scl);
    ds_ActionClip(((struct action_vars *)&(work)->vars)->action,
                  ((struct action_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

void prisoner_swell_x(struct task *task)
{
    struct task_work *work;

    if (!CheckRangeOut(task)) {
        work = task->work;
        /* @hack spelling: the frame tested in the addition, which compares
         * the sum in FR2 (FCMP/GT at 0x0c90f9ca); as two statements, the test
         * reads the frame back, the function is 2 bytes longer and 25 of 50
         * words differ */
        if ((ACTION(work)->frame += work->ang.z * PRISONER_PACE) >
            PRISONER_LAST_FRAME) {
            ACTION(work)->frame = 0.0F;
        }
        SWELL_PHASE(work) += SWELL_STEP;
        work->scl.x = 1.0F + (njSin(SWELL_PHASE(work)) * SWELL_SIZE);
        prisoner_draw(task);
    }
}

void prisoner_swell_y(struct task *task)
{
    struct task_work *work;

    if (!CheckRangeOut(task)) {
        work = task->work;
        /* @hack spelling: the frame tested in the addition, which compares
         * the sum in FR2 (FCMP/GT at 0x0c90fa72); as two statements, the test
         * reads the frame back, the function is 2 bytes longer and 30 of 50
         * words differ */
        if ((ACTION(work)->frame += work->ang.z * PRISONER_PACE) >
            PRISONER_LAST_FRAME) {
            ACTION(work)->frame = 0.0F;
        }
        SWELL_PHASE(work) += SWELL_STEP;
        work->scl.y = 1.0F + (njSin(SWELL_PHASE(work)) * SWELL_SIZE);
        prisoner_draw(task);
    }
}

void prisoner_play(struct task *task)
{
    struct task_work *work;

    if (!CheckRangeOut(task)) {
        work = task->work;
        /* @hack spelling: the frame tested in the addition, which compares
         * the sum in FR2 (FCMP/GT at 0x0c90fb08); as two statements, the test
         * reads the frame back, the function is 2 bytes longer and 13 of 32
         * words differ */
        if ((ACTION(work)->frame += work->ang.z * PRISONER_PACE) >
            PRISONER_LAST_FRAME) {
            ACTION(work)->frame = 0.0F;
        }
        prisoner_draw(task);
    }
}

void FUN_0c90ee66(struct task *task)
{
    struct task_work *work = task->work;

    if (work->scl.x == 0.0F) {
        work->scl.x = 1.0F;
    }
    if (work->scl.y == 0.0F) {
        work->scl.y = 1.0F;
    }
    if (work->scl.z == 0.0F) {
        work->scl.z = 1.0F;
    }
    ACTION(work)->texlist = &texlist_obj_mountain;
    ACTION(work)->action = &prisoner_action;
    if (OnEdit(task)) {
        task->step = prisoner_draw;
        return;
    }
    task->draw = prisoner_draw;
    task->step = prisoner_swell_x;
}

void FUN_0c90eeba(struct task *task)
{
    struct task_work *work = task->work;

    if (work->scl.x == 0.0F) {
        work->scl.x = 1.0F;
    }
    if (work->scl.y == 0.0F) {
        work->scl.y = 1.0F;
    }
    if (work->scl.z == 0.0F) {
        work->scl.z = 1.0F;
    }
    ACTION(work)->texlist = &texlist_obj_mountain;
    ACTION(work)->action = &prisoner_action;
    if (OnEdit(task)) {
        task->step = prisoner_draw;
        return;
    }
    task->draw = prisoner_draw;
    task->step = prisoner_swell_y;
}

void FUN_0c90ef0e(struct task *task)
{
    struct task_work *work = task->work;

    if (work->scl.x == 0.0F) {
        work->scl.x = 1.0F;
    }
    if (work->scl.y == 0.0F) {
        work->scl.y = 1.0F;
    }
    if (work->scl.z == 0.0F) {
        work->scl.z = 1.0F;
    }
    ACTION(work)->texlist = &texlist_obj_mountain;
    ACTION(work)->action = &prisoner_action;
    if (OnEdit(task)) {
        task->step = prisoner_draw;
        return;
    }
    task->draw = prisoner_draw;
    task->step = prisoner_play;
}
