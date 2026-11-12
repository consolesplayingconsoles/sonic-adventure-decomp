/* @unit 0C901E20-0C9024E0 +r04 +egflags +pool32 +asmfunc=FUN_0c902068:0c902402 */
/* the burning boulder that rolls down ruin_boulder_path after player 0. once
 * player 0 has got ahead, the boulder speeds up while it stays ahead */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "effect/dust.h"
#include "effect/flame.h"
#include "object/common.h"
#include "path/path.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "stg07/boulder.h"
#include "stg07/paths.h"
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
void *syMalloc_default_malloc(size_t size);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
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
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
Bool OnEdit(struct task *task);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke2(struct dust_params *params);
void FUN_8c04536e(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale);
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
Bool GetStatusOnPath(struct path *path, struct GetStatusOnPath *sample);
Bool path_spline_sample(struct path_spline *spline,
                        struct GetStatusOnPath *sample);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
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

#define VARS(work) ((struct boulder_vars *)&(work)->vars)
#define BOULDER_SPEED(work) ((work)->scl.x)
#define BOULDER_ALONG(work) ((work)->scl.y)
#define BOULDER_FLAME(work) ((work)->scl.z)
#define BOULDER_FLAMES(work) ((work)->tick)
#define BOULDER_CHASING 0x100
#define BOULDER_DUSTED 0x200
#define FLAME(work) ((struct flame_vars *)&(work)->vars)
#define DUST_ACROSS(work) ((work)->scl.x)
#define BOULDER_END 5755.0F
#define BOULDER_AHEAD 200.0F
#define BOULDER_DUST 150.0F
#define BOULDER_RIM 52.0F
#define SE_RUMBLE 199
extern NJS_MODEL boulder_model;

/* a path task's vars, laid out as path/path.h's struct path_vars. the spin
 * takes the bytes of its two wait counts */
struct boulder_vars {
    Angle spin; /* taken off ang.z each step */
    Sint16 stage_act;
    struct path *path;
};

/* the boulder's speed along the path, a step, and its distance along it */
/* its flames' scale, which each new flame grows by 1 */
/* the flames it has taken on */

/* the boulder's flags. BOULDER_CHASING is set once player 0 has got more
 * than BOULDER_AHEAD ahead. BOULDER_DUSTED is set once it has thrown up its
 * dust */

/* a flame child's vars */
struct flame_vars {
    Uint8 unk_00[4];
    Float across; /* its offset in z from the boulder */
};
extern int boulder_flame_distances[8];
extern struct collision_shape boulder_shape;
/* clang-format on */

void boulder_destroy(struct task *task)
{
    FreeTaskC(task);
}

/* every 8 steps, the child lights a flame on the boulder's rim. the flame
 * lies at the boulder's turn plus the child's, and moves along x at the
 * boulder's speed */
void C_Fire(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *boulder = task->parent->work;
    NJS_POINT3 pos;

    if (!(++work->tick & 7)) {
        pos.x = boulder->pos.x +
                (njCos(boulder->ang.z + work->ang.z) * BOULDER_RIM);
        pos.y = boulder->pos.y + (njSin(boulder->ang.z + work->ang.z) * 52.0F);
        pos.z = boulder->pos.z + ((struct flame_vars *)&(work)->vars)->across;
        work->scl.x = ((boulder)->scl.x);
        FUN_8c04536e(&pos, &work->scl, ((boulder)->scl.z));
    }
}

void boulder_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    SetObjectTexture();
    ds_DrawModelClip(&boulder_model);
    late_DrawObjectClipEx(1);
}

/* every 9 steps, the child puffs dust forward from the boulder's front, at
 * its foot */
void C_Smoke(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *boulder = task->parent->work;
    NJS_POINT3 pos;
    NJS_VECTOR speed;

    if (work->tick == 8) {
        work->tick = 0;
        pos.x = boulder->pos.x + 45.0F;
        pos.y = boulder->pos.y - 40.0F;
        pos.z = boulder->pos.z + DUST_ACROSS(work);
        speed.x = 3.0F;
        speed.y = work->scl.y;
        speed.z = work->scl.z;
        CreateSmoke(&pos, &speed, 2.0F);
    } else {
        work->tick++;
    }
}

/* set up a dust child across in z from the boulder. its puffs rise at ang
 * from up toward z */
void cSmokeInit(struct task_work *work, Float across, Angle ang)
{
    DUST_ACROSS(work) = across;
    work->scl.y = njCos(ang) * 1.5F;
    work->scl.z = njSin(ang) * 1.5F;
}

/* puff dust across in z from the boulder, at its front and foot. the puff
 * moves forward, and rises at ang from up toward z */
void SmokeInit(struct task_work *work, Float across, Angle ang)
{
    NJS_POINT3 pos;
    NJS_VECTOR speed;

    pos.x = work->pos.x + 30.0F;
    pos.y = work->pos.y - 40.0F;
    pos.z = work->pos.z + across;
    speed.x = 5.0F;
    speed.y = njCos(ang) * 4.0F;
    speed.z = njSin(ang) * 4.0F;
    CreateSmoke(&pos, &speed, 4.0F);
}
#ifdef NON_MATCHING

/* roll along the path. a touch sends player 0 flying. the boulder stops past
 * BOULDER_END, or once the stage or act changes from the path task's. then
 * each step only destroys the flames and the dust */
void boulder_roll(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    struct task *child;
    struct GetStatusOnPath sample;
    NJS_VECTOR speed;
    Angle ang[3];

    /* @hack type: stage_get_stage_act called through a cast as returning
     * int, so the compare takes R0 as it is (MOV R0,R3 at 0x0c9022aa). as
     * the Uint16 stage.h declares, SHC extends it with EXTU.W, and 1 of 368
     * words differ */
    /* @hack redundant: an else after the return, which loads the collision
     * record into R3 for the hit's test (MOV.L @(56,R14),R3 at 0x0c902300);
     * without it, R2 takes it and 2 of 368 words differ */
#ifdef GCC
    /* keeps the shipped play: stage << 8 | act fits a Uint16, so stage.h's
     * return compares the same */
    if (GetStageNumber() != VARS(work)->stage_act) {
#else
    /* NOLINTNEXTLINE(clang-diagnostic-cast-function-type-mismatch) */
    if (((int (*)(void))GetStageNumber)() != VARS(work)->stage_act) {
#endif
        FreeTaskC(task);
        return;
    } else {
        /* @hack spelling: the hit's two tests nested, which give player R11
         * (the loads at 0x0c9022a2 and 0x0c9022a8); as one test with &&, R9
         * takes it and 112 of 368 words differ */
        if (work->collision->flags & COLLISION_HIT) {
            if (work->collision->hit == playertwp[0]->collision) {
                ang[0] = 0;
                ang[1] = 0x4000;
                ang[2] = 0;
                speed.x = 5.0F;
                speed.y = 1.0F;
                speed.z = 0.0F;
                player_send_flying(0, &speed, ang, 60);
            }
        }
        BOULDER_ALONG(work) += BOULDER_SPEED(work);
        if (BOULDER_ALONG(work) >= BOULDER_END) {
            FreeTaskC(task);
            return;
        }
        work->ang.z -= VARS(work)->spin;
        sample.distance = BOULDER_ALONG(work);
        GetStatusOnPath(&ruin_boulder_path, &sample);
        work->pos.x = sample.pos.x;
        work->pos.y = sample.pos.y;
        work->pos.z = sample.pos.z;
        boulder_draw(task);
        if (!(work->flags & BOULDER_CHASING)) {
            if (player->pos.x > work->pos.x + BOULDER_AHEAD) {
                /* @hack spelling: the clear bit added, ADD at 0x0c9023be;
                 * or'd, it takes an OR, and 1 of 368 words differ */
                work->flags += BOULDER_CHASING;
            }
        } else {
            dsPlay_Dolby_time(SE_RUMBLE, (int)work, 1, 96, work->pos.x,
                              work->pos.y, work->pos.z, 2);
            if (player->pos.x > work->pos.x + BOULDER_AHEAD) {
                BOULDER_SPEED(work) += 0.15F;
                VARS(work)->spin += 24;
            } else if (BOULDER_SPEED(work) > 1.5F) {
                BOULDER_SPEED(work) -= 0.3F;
                VARS(work)->spin -= 48;
            }
        }
        LoopTaskC(task);
        if (!(work->flags & BOULDER_DUSTED) &&
            BOULDER_ALONG(work) >= BOULDER_DUST) {
            /* @hack spelling: the clear bit added, ADD at 0x0c9024e2; or'd,
             * it takes an OR, and 1 of 368 words differ */
            work->flags += BOULDER_DUSTED;
            SmokeInit(work, -35.0F, NJM_DEG_ANG(-50));
            SmokeInit(work, -30.0F, NJM_DEG_ANG(-40));
            SmokeInit(work, -25.0F, NJM_DEG_ANG(-30));
            SmokeInit(work, -20.0F, NJM_DEG_ANG(-20));
            SmokeInit(work, -15.0F, NJM_DEG_ANG(-10));
            SmokeInit(work, 0.0F, NJM_DEG_ANG(0));
            SmokeInit(work, 15.0F, NJM_DEG_ANG(10));
            SmokeInit(work, 20.0F, NJM_DEG_ANG(20));
            SmokeInit(work, 25.0F, NJM_DEG_ANG(30));
            SmokeInit(work, 30.0F, NJM_DEG_ANG(40));
            SmokeInit(work, 35.0F, NJM_DEG_ANG(50));
            child = CreateChildTask(TASK_WORK, C_Smoke, task);
            cSmokeInit(child->work, -25.0F, NJM_DEG_ANG(-50));
            child->work->tick = 0;
            child = CreateChildTask(TASK_WORK, C_Smoke, task);
            cSmokeInit(child->work, 5.0F, NJM_DEG_ANG(-85));
            child->work->tick = 4;
            child = CreateChildTask(TASK_WORK, C_Smoke, task);
            cSmokeInit(child->work, -5.0F, NJM_DEG_ANG(85));
            child->work->tick = 2;
            child = CreateChildTask(TASK_WORK, C_Smoke, task);
            cSmokeInit(child->work, 25.0F, NJM_DEG_ANG(50));
            child->work->tick = 6;
        }
        if (BOULDER_ALONG(work) >
            boulder_flame_distances[BOULDER_FLAMES(work)]) {
            BOULDER_FLAMES(work)++;
            BOULDER_FLAME(work) += 1.0F;
            child = CreateChildTask(TASK_WORK, C_Fire, task);
            child->work->ang.z = work->ang.z;
            child->work->tick = 0;
            child->work->scl.y = 0.0F;
            child->work->scl.z = 0.0F;
            FLAME(child->work)->across =
                (rand() * (50.0F * RAND_SCALE)) - 25.0F;
        }
        if (!OnEdit(task)) {
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
        }
    }
}
#else
void boulder_roll(struct task *task)
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

void ObjectRockRoll(struct task *task)
{
    struct task_work *work = task->work;

    CCL_Init(task, &boulder_shape, COLLISION_ENEMY, 1, 1);
    /* @hack redundant: the flame count's 0 written as a select on 1.0F, which
     * SHC folds too late to share. the count takes MOV #0,R0, and the spin
     * its own MOV #0,R3 (0x0c9026f8, 0x0c902704). as a plain 0, both take R4
     * and 11 of 39 words differ */
    BOULDER_FLAMES(work) = 1.0F ? 0 : 0; /* NOLINT(misc-redundant-expression) */
    BOULDER_SPEED(work) = 0.0F;
    VARS(work)->spin = 0;
    BOULDER_ALONG(work) = 0.0F;
    BOULDER_FLAME(work) = 0.5F;
    work->flags = ~(BOULDER_CHASING | BOULDER_DUSTED);
    task->step = boulder_roll;
    task->draw = boulder_draw;
    task->destructor = boulder_destroy;
}
