/* @unit 0C90D5E0-0C90D9C0 @data 0C911810-0C911834 +r04 +egflags +pool32 */
/* O BZ, Tails beside a smoking wreck. player 0 clears the stage by touching
 * Tails */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "effect/dust.h"
#include "object/capsule.h"
#include "object/placement.h"
#include "player/player.h"
#include "player/textures.h"
#include "progress/progress.h"
#include "stage/stage.h"
#include "stg01/crash.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
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
Bool SetObjectTexture(void);
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

/* @hack type: declared an array, not the one NJS_ACTION it is, so SHC pools
 * its address and reads motion through it, MOV.L @(4,R2),R3 at 0x0c90de16;
 * declared as one, 19 of beach_crash_draw's 210 words differ */
#define VARS(work) ((struct beach_crash_vars *)&(work)->vars)
#define REACH 14.0F
#define TAILS_RISE 5.0F
#define TAILS_TURN NJM_DEG_ANG(270)
#define TAILS_RATE 0.5F
#define WRECK_AHEAD 50.0F
#define SMOKE_WAIT 10
extern NJS_ACTION beach_crash_tails_action;
extern NJS_OBJECT beach_crash_wreck_object;

enum beach_crash_mode {
    CRASH_INIT = 0,
    CRASH_WAIT = 2, /* until player 0 touches Tails */
    CRASH_CAPSULE = 3, /* one step, which starts the capsule */
    CRASH_GONE = 4,
    CRASH_CLEARED = 5
};

struct beach_crash_vars {
    Float frame; /* Tails' frame in his motion */
};
extern struct dust_params beach_crash_smoke;

void DrawZangai(struct task *task);
void beach_crash_draw_reach(struct task *task);
void beach_crash_touch(struct task *task);

void ObjectBeachZangai(struct task *task)
{
    struct task_work *work = task->work;
    struct task *made;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case CRASH_INIT:
        work->mode = CRASH_WAIT;
        break;
    case CRASH_WAIT:
        if (SeqCheckFlag(FLAG_SONIC_CLEAR_BEACH)) {
            work->mode = CRASH_CAPSULE;
            break;
        }
        task->draw = DrawZangai;
        if (!OnEdit(task)) {
            beach_crash_touch(task);
        }
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- SCALE");
            beach_crash_draw_reach(task);
        }
        VARS(work)->frame += TAILS_RATE;
        DrawZangai(task);
        break;
    case CRASH_CAPSULE:
        made = CreateElementalTask(TASK_WORK, 2, ObjectReleaseBox);
        made->work->pos.x = work->pos.x;
        made->work->pos.y = work->pos.y;
        made->work->pos.z = work->pos.z;
        work->mode = CRASH_GONE;
        break;
    case CRASH_CLEARED:
        DrawZangai(task);
        break;
    case CRASH_GONE:
        break;
    }
}

/* Tails, then the wreck and its smoke */
void DrawZangai(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: a vector nothing reads, which SHC still copies from
     * the constants to the frame (0x0c90ddec to 0x0c90de02); without it, 201
     * of 210 words differ */
    NJS_VECTOR unused = {0.3F, 0.5F, 0.0F};
    /* @hack redundant: ahead's initializer, which the draw replaces before
     * it reads ahead, copied from the constants (0x0c90de04 to 0x0c90de12);
     * without it, 199 of 210 words differ */
    NJS_POINT3 ahead = {3.0F, 0.0F, 0.0F};
    Angle ang;
    if (((struct beach_crash_vars *)&(work)->vars)->frame >=
        beach_crash_tails_action.motion->nbFrame - 1) {
        ((struct beach_crash_vars *)&(work)->vars)->frame = 0.0F;
    }
    TASK_TIMER(work)++;
    njSetTexture_jp(&tails_texlist);
    njPushMatrix(((void *)0));
    njTranslate(((void *)0), work->pos.x, work->pos.y + 5.0F, work->pos.z);
    (((ang) = (work->ang.z)) ? (njRotateZ)(((void *)0), (ang)) : (void)0);
    (((ang) = (work->ang.x)) ? (njRotateX)(((void *)0), (ang)) : (void)0);
    (((ang) = (work->ang.y + ((Angle)(((270) * 65536.0) / 360.0))))
         ? (njRotateY)(((void *)0), (ang))
         : (void)0);
    ds_ActionClip(&beach_crash_tails_action,
                  ((struct beach_crash_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
    ahead.x = WRECK_AHEAD;
    ahead.y = 0.0F;
    ahead.z = 0.0F;
    njPushMatrix(&nj_unit_matrix_);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njCalcPoint(NULL, &ahead, &ahead);
    late_DrawObjectClipEx(1);
    if (TASK_TIMER(work) > SMOKE_WAIT) {
        beach_crash_smoke.pos.x = work->pos.x + ahead.x;
        beach_crash_smoke.pos.y = work->pos.y;
        beach_crash_smoke.pos.z = work->pos.z + ahead.z;
        TASK_TIMER(work) = 0;
        CreateSmoke2(&beach_crash_smoke);
    }
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x + ahead.x, work->pos.y,
                work->pos.z + ahead.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObject(&beach_crash_wreck_object);
    late_DrawObjectClipEx(1);
}

/* in the set editor, draw marker_object scaled by one more than scale x, as
 * the touch's reach scales */
void beach_crash_draw_reach(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack type: the scale in a vector's x, which SHC keeps on the frame
     * across the calls, FMOV.S FR2,@R15 at 0x0c90df98 and FMOV.S @R15,FR15 at
     * 0x0c90dfb0; as a Float, 40 of 41 words differ */
    NJS_VECTOR scale;

    scale.x = work->scl.x + 1.0F;
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    njScale(NULL, scale.x, scale.x, scale.x);
    late_DrawObject(&object_sphere01);
    late_DrawObjectClipEx(1);
}

void beach_crash_touch(struct task *task)
{
    struct task_work *work = task->work;

    if (player_in_range(&work->pos, (work->scl.x + 1.0F) * REACH) == 1) {
        SetFinishAction();
        work->mode = CRASH_CLEARED;
    }
}
