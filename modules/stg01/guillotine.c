/* @unit 0C9009A0-0C901120 @data 0C910690-0C9106A8 +r04 +egflags +pool32 */
/* O BGIRO: a guillotine blade that drops between two posts, then rises half
 * as fast */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "effect/dust.h"
#include "object/common.h"
#include "object/placement.h"
#include "sound/sound.h"
#include "stg01/guillotine.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
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
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void ds_DrawModelClip(NJS_MODEL *model);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke2(struct dust_params *params);
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
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define DROP 38.0F
#define HOLD 30
#define VIEW_RADIUS 20.0F
#define SHADOW_DEPTH 46.0F
#define DUST_PAIRS 9
#define DUST_GAP 3
#define SE_GUILLOTINE 45
#define VARS(work) ((struct guillotine_vars *)&(work)->vars)
extern NJS_OBJECT guillotine_frame_object;
extern NJS_MODEL guillotine_blade_model;
extern NJS_MODEL guillotine_shadow_model;

/* how far the blade drops. at the bottom it holds HOLD + 1 steps */

/* the draw shows nothing unless a sphere of radius VIEW_RADIUS about the
 * blade is in view */

/* the shadow lies SHADOW_DEPTH below top */

/* the dust comes in DUST_PAIRS pairs of puffs, along the blade's width. the
 * first pair is at its center, and each next pair DUST_GAP farther out
 * either side */

/* the blade's vars. TASK_TIMER(work) holds the cycle's angle in degrees, and
 * work->tick is 1 once a hold is over. work->scl.y holds how far the blade
 * has dropped, and work->scl.z is 1 until the first drop */
struct guillotine_vars {
    Uint8 held; /* the steps of the current hold so far */
    Float top; /* the blade's y at rest, where it starts */
};

/* in GUILLOTINE_END, the step only checks its range. no code sets it */
enum guillotine_mode { GUILLOTINE_INIT, GUILLOTINE_RUN, GUILLOTINE_END };
enum guillotine_posts_mode { POSTS_INIT, POSTS_RUN };

void guillotine_move(struct task *task);
void Draw(struct task *task);
void guillotine_destroy(struct task *task);
void guillotine_posts_step(struct task *task);
void SmokeEff(struct task *task);
extern struct collision_shape guillotine_post_shapes[2];
extern struct collision_shape guillotine_blade_shape;
extern struct dust_params guillotine_dust_params;
/* clang-format on */

void ObjectBeachGiro(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case GUILLOTINE_INIT:
        CreateChildTask(TASK_WORK, guillotine_posts_step, task);
        if (!OnEdit(task)) {
            CCL_Init(task, &guillotine_blade_shape, COLLISION_OBJECT, 1, 1);
        }
        task->destructor = guillotine_destroy;
        task->draw = Draw;
        work->mode = GUILLOTINE_RUN;
        VARS(work)->top = work->pos.y;
        work->timer = 0;
        work->scl.z = 1.0F;
        break;
    case GUILLOTINE_RUN:
        if (!OnEdit(task)) {
            guillotine_move(task);
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
        }
        Draw(task);
        LoopTaskC(task);
        break;
    case GUILLOTINE_END:
        break;
    }
}

/* advance the cycle a step. the blade drops through the cycle's first
 * quarter, 2 degrees a step, and holds at the bottom. then it rises through
 * the second quarter and rests through the second half, 1 degree a step. a
 * hold at the bottom starts with dust and SE_GUILLOTINE. before the first
 * drop, the blade holds as long at the top, without them */
void guillotine_move(struct task *task)
{
    struct task_work *work = task->work;
    int angle = TASK_TIMER(work);

    if (angle > 0 && angle < 90) {
        TASK_TIMER(work) += 2;
        work->tick = 0;
        VARS(work)->held = 0;
    } else if (!work->tick) {
        VARS(work)->held++;
        if (VARS(work)->held == 1 && work->scl.z == 0.0F) {
            SmokeEff(task);
            dsPlay_oneshot(SE_GUILLOTINE, 0, 0, 0);
        }
        if (VARS(work)->held > HOLD) {
            work->tick = 1;
        }
    } else {
        work->scl.z = 0.0F;
        TASK_TIMER(work)++;
    }
    work->scl.y = njSin((Angle)(TASK_TIMER(work) * ANGLE_PER_DEGREE)) * DROP;
    if (work->scl.y < 0.0F) {
        work->scl.y = 0.0F;
    }
    if (TASK_TIMER(work) > 360) {
        TASK_TIMER(work) = 0;
    }
    work->pos.y = VARS(work)->top - work->scl.y;
}

/* draw the blade where it has dropped to, and the frame at top. the shadow
 * widens along z as the blade drops */
void Draw(struct task *task)
{
    static const NJS_VECTOR guillotine_frame_offset = {0.0F, 0.0F, 0.0F};
    struct task_work *work = task->work;
    NJS_OBJECT *frame = &guillotine_frame_object;
    NJS_VECTOR offset;
    Angle ang;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, VIEW_RADIUS)) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
        TURN_VIA(njRotateY, work->ang.y, ang);
        ds_DrawModelClip(&guillotine_blade_model);
        njPushMatrix(NULL);
        njTranslate(NULL, frame->pos[0], frame->pos[1], frame->pos[2]);
        offset = guillotine_frame_offset;
        offset.y = work->scl.y;
        njTranslateV(NULL, &offset);
        ds_DrawModelClip(frame->model);
        late_DrawObjectClipEx(1);
        late_DrawObjectClipEx(1);
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x, work->pos.y + work->scl.y - SHADOW_DEPTH,
                    work->pos.z);
        TURN_VIA(njRotateY, work->ang.y, ang);
        njScale(NULL, 1.0F, 1.0F, (0.0325F * work->scl.y) + 0.82F);
        ds_DrawModelClip(&guillotine_shadow_model);
        late_DrawObjectClipEx(1);
    }
}

void guillotine_destroy(struct task *task)
{
    FreeTaskC(task);
}

/* the step of the posts' task, a child of the blade's. the posts stay where
 * the blade starts, facing the same way */
void guillotine_posts_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *blade = task->parent->work;

    switch (work->mode) {
    case POSTS_INIT:
        CCL_Init(task, guillotine_post_shapes, COLLISION_OBJECT, 1, 2);
        work->mode = POSTS_RUN;
        work->pos.x = blade->pos.x;
        work->pos.y = blade->pos.y;
        work->pos.z = blade->pos.z;
        work->ang.x = blade->ang.x;
        work->ang.y = blade->ang.y;
        work->ang.z = blade->ang.z;
        break;
    case POSTS_RUN:
        EntryColliList(work);
        break;
    }
}

/* puffs of dust at the bottom of the drop */
void SmokeEff(struct task *task)
{
    static const NJS_VECTOR guillotine_dust_speed = {0.0F, 0.0F, 0.0F};
    struct task_work *work = task->work;
    NJS_POINT3 turned;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    Angle ang;
    int i;

    speed = guillotine_dust_speed;
    for (i = 0; i < DUST_PAIRS * DUST_GAP; i += DUST_GAP) {
        pos.x = (Float)i;
        pos.y = 0.0F;
        pos.z = 0.0F;
        njPushMatrix(&nj_unit_matrix_);
        TURN_VIA(njRotateY, work->ang.y, ang);
        njCalcPoint(NULL, &pos, &turned);
        late_DrawObjectClipEx(1);
        pos.y = VARS(work)->top - DROP;
        pos.x = turned.x + work->pos.x;
        pos.z = turned.z + work->pos.z;
        CreateSmoke(&pos, &speed, 2.4F);
        pos.x = -turned.x + work->pos.x;
        pos.z = -turned.z + work->pos.z;
        CreateSmoke(&pos, &speed, 2.4F);
    }
}
