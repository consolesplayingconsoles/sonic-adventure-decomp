/* @unit 0C905F40-0C906460 @data 0CADB900-0CADB92C +r04 +egflags +pool32 +asmfunc=FUN_0c9063be:0c906460 */
/* O BONEHEAD, a burning skull, and O BONESTICK, a stick topped by one in
 * either of two poses
 *
 * each draws at one more than its set entry's scale x, and its flame at
 * one more than its scale y. the stick's pose is 0 when scale z's whole part
 * is even, and 1 when it's odd. the set editor labels the stick's scale y
 * FIRE SCL and its scale z TYPE CHANGE */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "effect/dust.h"
#include "effect/flame.h"
#include "object/common.h"
#include "object/placement.h"
#include "stg05/bones.h"
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
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void FUN_8c045402(struct dust_params *params);
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
void FUN_8c059854(struct task_work *work);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define POSE(work) ((work)->tick)
#define FLAME_SCALE 0.12F
#define SKULL_SCALE 1.18F
extern NJS_TEXLIST texlist_obj_mountain;
extern NJS_MODEL bone_skull_model;
extern NJS_MODEL bone_stick_model;

/* the step does nothing in BONE_IDLE, which nothing in this file sets */
enum bone_mode { BONE_INIT = 0, BONE_LIT = 1, BONE_IDLE = 3 };
extern struct collision_shape bone_head_shape;
extern struct collision_shape bone_stick_shape;
extern struct dust_params bone_flame;
extern NJS_POINT3 bone_skull_pos_0;
extern struct angles bone_skull_ang_0;
extern NJS_POINT3 bone_skull_pos_1;
extern struct angles bone_skull_ang_1;
extern const NJS_POINT3 bone_origin;

void bone_head_destroy(struct task *task);
void bone_head_draw(struct task *task);
void bone_stick_destroy(struct task *task);
void bone_stick_draw(struct task *task);
void bone_stick_labels(struct task_work *work);
void bone_stick_pick(struct task_work *work);

/* each step, a flame starts at the skull's center */
void bone_head_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BONE_INIT:
        CCL_Init(task, &bone_head_shape, 4, 1, 1);
        FUN_8c059854(work);
        task->destructor = bone_head_destroy;
        task->draw = bone_head_draw;
        work->mode = BONE_LIT;
        break;
    case BONE_LIT:
        /* @hack redundant: placement_editing's result tested for nothing, which
         * keeps task in R14 and work in R13 (0x0c906482, 0x0c90648c); without
         * it, the two trade, the function is 8 bytes shorter and 41 of 70
         * words differ */
        if (OnEdit(task)) {
        }
        EntryColliList(work);
        bone_flame.pos = work->pos;
        bone_flame.scale = (work->scl.y + 1.0F) * 0.12F;
        FUN_8c045402(&bone_flame);
        bone_head_draw(task);
        break;
    case BONE_IDLE:
        break;
    }
}

void bone_head_destroy(struct task *task)
{
}

void bone_head_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    Float scale;

    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    njSetTexture_jp(&texlist_obj_mountain);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    scale = work->scl.x + 1.0F;
    njScale(NULL, scale, scale, scale);
    ds_DrawModelClip(&bone_skull_model);
    late_DrawObjectClipEx(1);
}

/* each step, a flame starts above the stick's foot, at the skull's height in
 * its pose. the flame ignores the stick's turn and the skull's place along x
 * and z */
void bone_stick_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 pos;
    /* NOLINTNEXTLINE(clang-diagnostic-unused-but-set-variable) */
    NJS_POINT3 origin;
    /* @hack redundant: top_1 and top_0, a point for each pose, each copied to
     * pos. the two give the stack frame 48 bytes (ADD #-48,R15 at
     * 0x0c906626); with one point for both, the frame takes 36, the function
     * is 10 bytes shorter and 129 of 138 words differ */
    NJS_POINT3 top_1;
    NJS_POINT3 top_0;
    Float height;
    Float one;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BONE_INIT:
        CCL_Init(task, &bone_stick_shape, 4, 1, 1);
        FUN_8c059854(work);
        task->destructor = bone_stick_destroy;
        task->draw = bone_stick_draw;
        work->mode = BONE_LIT;
        break;
    case BONE_LIT:
        if (OnEdit(task)) {
            bone_stick_labels(work);
        }
        EntryColliList(work);
        bone_stick_pick(work);
        /* count the stick's steps, which nothing reads */
        work->timer++;
        /* @hack redundant: bone_origin copied to origin and never read;
         * without it, the function is 44 bytes shorter and 129 of 138 words
         * differ */
        origin = bone_origin;
        /* @hack spelling: 1 through a local, which loads it once, into FR5 at
         * 0x0c9066b6, before the copy of bone_origin; as the literal, it is
         * loaded later, into FR4, and 9 of 138 words differ */
        one = 1.0F;
        if (POSE(work) == 1) {
            height = bone_skull_pos_1.y * (work->scl.x + one);
            top_1 = work->pos;
            top_1.y += height;
            pos = top_1;
        } else {
            height = bone_skull_pos_0.y * (work->scl.x + one);
            top_0 = work->pos;
            top_0.y += height;
            pos = top_0;
        }
        bone_flame.pos = pos;
        bone_flame.scale = (work->scl.y + one) * 0.12F;
        FUN_8c045402(&bone_flame);
        bone_stick_draw(task);
        break;
    case BONE_IDLE:
        break;
    }
}

void bone_stick_destroy(struct task *task)
{
}

/* draw the stick, then the skull at its pose's place on it, scaled by scale
 * x plus SKULL_SCALE */
void bone_stick_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    Float scale;

    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    njSetTexture_jp(&texlist_obj_mountain);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    scale = work->scl.x + 1.0F;
    njScale(NULL, scale, scale, scale);
    ds_DrawModelClip(&bone_stick_model);
    njSetTexture_jp(&texlist_obj_mountain);
    if (POSE(work) == 0) {
        njTranslateV(NULL, &bone_skull_pos_0);
        TURN_VIA(njRotateZ, bone_skull_ang_0.z, ang);
        TURN_VIA(njRotateX, bone_skull_ang_0.x, ang);
        TURN_VIA(njRotateY, bone_skull_ang_0.y, ang);
    } else {
        njTranslateV(NULL, &bone_skull_pos_1);
        TURN_VIA(njRotateZ, bone_skull_ang_1.z, ang);
        TURN_VIA(njRotateX, bone_skull_ang_1.x, ang);
        TURN_VIA(njRotateY, bone_skull_ang_1.y, ang);
    }
    scale = work->scl.x + SKULL_SCALE;
    njScale(NULL, scale, scale, scale);
    ds_DrawModelClip(&bone_skull_model);
    late_DrawObjectClipEx(1);
}

void bone_stick_labels(struct task_work *work)
{
    njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "SCL Y -> FIRE SCL");
    njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "SCL Z -> TYPE CHANGE");
}
#ifdef NON_MATCHING

void bone_stick_pick(struct task_work *work)
{
    if ((int)work->scl.z % 2 == 0) {
        POSE(work) = 0;
    } else {
        POSE(work) = 1;
    }
}
#else
void bone_stick_pick(struct task_work *work)
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
