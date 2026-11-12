/* @unit 0C9012A0-0C901600 +r04 +egflags +asmfunc=FUN_0c901582:0c901600 */
/* O EGGSTAND stand for the shop's egg, which sinks under an egg's weight */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv00/egg_stand.h"
#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "progress/progress.h"
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
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

#define STAND_SINK 2.8F /* how far the stand sinks under an egg */
#define STAND_SPEED 0.2F /* how far the stand sinks or rises each step */
#define STAND_TOP 3.5F
#define SOLID_WORLD_FLAGS (WORLD_SMALL | WORLD_MOVES | WORLD_SOLID)
#define VARS(work) ((struct egg_stand_vars *)&(work)->vars)
extern NJS_OBJECT egg_stand_object;
extern NJS_OBJECT fake_egg_object;
extern NJS_OBJECT egg_stand_solid_object;

/* the top's height above the stand's position, where the solid and an egg
 * sit */

/* the world flags of the stand's solid, which players stand on */

/* the stand's work->mode, which skips 2: no code sets it */
enum egg_stand_mode {
    STAND_UP = 0,
    STAND_SINKING = 1,
    STAND_DOWN = 3,
    STAND_RISING = 4
};

struct egg_stand_vars {
    /* the solid the stand adds to the world, or NULL in the set editor and
     * once the real egg is taken into a garden */
    NJS_OBJECT *solid;
    Float up_y; /* the stand's height with no egg on it */
};

void egg_stand_draw(struct task *task);
void egg_stand_swapped_draw(struct task *task);
void egg_stand_step(struct task *task);
void egg_stand_swapped_step(struct task *task);
void egg_stand_destroy(struct task *task);
extern struct collision_shape egg_stand_swapped_shape;
/* clang-format on */

void station_square_egg_stand_init(struct task *task)
{
    struct task_work *work = task->work;
    struct task_force *force = task->force;
    NJS_OBJECT *solid;
    Bool swapped;

    work->mode = STAND_UP;
    VARS(work)->up_y = work->pos.y;
    work->timer = 0;
    force->turn.x = 0;
    force->turn.y = 0;
    force->turn.z = 0;
    force->speed.x = 0.0F;
    force->speed.y = 0.0F;
    force->speed.z = 0.0F;
    if (OnEdit(task)) {
        VARS(work)->solid = NULL;
        task->step = egg_stand_step;
        return;
    }
    /* @hack spelling: the flag read into swapped, which the image tests in
     * R5 (MOV.B @(R0,R4),R5 at 0x0c9013a8); tested in place, it takes R2, and
     * 3 of 114 words differ */
    swapped = seqVars[FLAG_GOLD_EGG_IN];
    if (swapped) {
        seqVars[FLAG_EGG_ON_STAND] = TRUE;
        VARS(work)->solid = NULL;
        CCL_Init(task, &egg_stand_swapped_shape, COLLISION_OBJECT, 1, 1);
        task->step = egg_stand_swapped_step;
        task->draw = egg_stand_swapped_draw;
    } else {
        seqVars[FLAG_EGG_ON_STAND] = FALSE;
        VARS(work)->solid = solid = GetMobileLandObject();
        solid->evalflags =
            NJD_EVAL_UNIT_SCL | NJD_EVAL_BREAK | NJD_EVAL_ZXY_ANG;
        solid->scl[0] = 1.0F;
        solid->scl[1] = 1.0F;
        solid->scl[2] = 1.0F;
        solid->ang[0] = 0;
        solid->ang[1] = work->ang.y;
        solid->ang[2] = 0;
        solid->pos[0] = work->pos.x;
        solid->pos[1] = work->pos.y + STAND_TOP;
        solid->pos[2] = work->pos.z;
        solid->model = egg_stand_solid_object.model;
        solid->child = NULL;
        solid->sibling = NULL;
        RegisterCollisionEntry(SOLID_WORLD_FLAGS, task, solid);
        work->flags |= WORLD_TESTED;
        task->step = egg_stand_step;
        task->draw = egg_stand_draw;
    }
    task->destructor = egg_stand_destroy;
}

void egg_stand_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObject(&egg_stand_object);
    late_DrawObjectClipEx(1);
}

/* draw the stand sunk, with the fake egg on it */
void egg_stand_swapped_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y - STAND_SINK, work->pos.z);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObject(&egg_stand_object);
    njTranslate(NULL, 0.0F, STAND_TOP, 0.0F);
    late_DrawObject(&fake_egg_object);
    late_DrawObjectClipEx(1);
}

/* sink the stand and its solid once an egg is on it, and raise them once the
 * egg is off */
void egg_stand_step(struct task *task)
{
    struct task_work *work = task->work;
    Float *pos_y;
    Float y;
    Float up_y;
    Float sunk;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        switch (work->mode) {
        case STAND_UP:
            if (seqVars[FLAG_EGG_ON_STAND]) {
                work->mode = STAND_SINKING;
            }
            break;
        case STAND_SINKING:
            /* @hack spelling: the height read and written through pos_y, which
             * SHC forms in R4 (ADD #36,R4 at 0x0c9015ae), with y, up_y and
             * sunk in locals; as arithmetic on work->pos.y, 70 of 94 words
             * differ */
            pos_y = &work->pos.y;
            y = *pos_y;
            up_y = VARS(work)->up_y;
            y -= STAND_SPEED;
            sunk = up_y - y;
            if (sunk > STAND_SINK) {
                y = up_y - STAND_SINK;
                work->mode = STAND_DOWN;
            }
            VARS(work)->solid->pos[1] = y + STAND_TOP;
            *pos_y = y;
            break;
        case STAND_DOWN:
            if (!seqVars[FLAG_EGG_ON_STAND]) {
                work->mode = STAND_RISING;
            }
            break;
        case STAND_RISING:
            /* @hack spelling: the height read and written through pos_y, which
             * SHC forms in R4 (ADD #36,R4 at 0x0c9015ea), with y, up_y and
             * sunk in locals; as arithmetic on work->pos.y, 54 of 94 words
             * differ */
            pos_y = &work->pos.y;
            y = *pos_y;
            up_y = VARS(work)->up_y;
            y += STAND_SPEED;
            sunk = up_y - y;
            if (sunk < 0.0F) {
                work->mode = STAND_UP;
                y = up_y;
            }
            VARS(work)->solid->pos[1] = y + STAND_TOP;
            *pos_y = y;
            break;
        }
    }
    egg_stand_draw(task);
}

void egg_stand_swapped_step(struct task *task)
{
    struct task_work *work = task->work;

    if (!OnEdit(task)) {
        EntryColliList(work);
    }
    egg_stand_swapped_draw(task);
}
#ifdef NON_MATCHING

void egg_stand_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->solid) {
        WithdrawCollisionEntry(task, VARS(work)->solid);
        ReleaseMobileLandObject(VARS(work)->solid);
    }
}
#else
void egg_stand_destroy(struct task *task)
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
