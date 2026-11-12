/* @unit 8C059D60-8C05A2A0 +egflags +pool32 */
/* the balloon, O BALOON in the object lists, and the sign it carries. it
 * bobs and sways until Amy grabs it. then it clears the stage and carries
 * her off */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "collision/ground.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "event/play.h"
#include "hud/hud.h"
#include "object/balloon.h"
#include "object/models.h"
#include "object/placement.h"
#include "player/player.h"
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
void *syMalloc_default_malloc(size_t size);
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
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
Bool OnEdit(struct task *task);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void EV_Load2(int number);
void EV_Exec2(void);
Bool EV_CheckExec(int number);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z, Angle ang_x,
                     Angle ang_y, Angle ang_z);
void WakeTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
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
struct player *GetPlayerWorkPointer(Uint8 player);
int GetTheNearestPlayerNumber(NJS_POINT3 *pos);
Bool CheckPlayerRideOnMobileLandObjectP(Uint8 player, struct task *task);
void SetLookingTaskP(Uint8 player, struct task *task, NJS_POINT3 *offset);
void SetLookingPointP(Uint8 player, NJS_POINT3 *pos);
void CancelLookingAtP(Uint8 player);
void HoldOnPillarP(Uint8 player, NJS_POINT3 *pos, Uint32 steps);
void KeepPlayersEyesOnThePointP(Uint8 player, struct angles *ang, Uint32 steps);
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
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
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

/* Amy grabs the balloon from within GRAB_RANGE of the point GRAB_DEPTH
 * below it. she hangs HANG_DEPTH below it while it dips and rises */
#define GRAB_RANGE 8.0F
#define GRAB_DEPTH 22.0F
#define HANG_DEPTH 24.0F

/* the dip's speed, upward, starts at DIP_SPEED and gains DIP_ACCEL each
 * step. the rise starts once the speed passes 0 */
#define DIP_SPEED (-1.5F)
#define DIP_ACCEL 0.15F

/* the shadow's size with the balloon at work->pos's height. as the bob
 * lifts the balloon, the shadow shrinks by the height */
#define SHADOW_SIZE 4.8F

#define VARS(work) ((struct balloon_vars *)&(work)->vars)
struct balloon_vars {
    /* while the balloon waits and rises, steps paces its bob, sway and
     * squash. while it dips, the union holds its speed instead. the rise's
     * count then starts from the last speed's bits, read as a Uint32 */
    union {
        Uint32 steps; /* while it waits and rises */
        Float speed; /* while it dips: upward, per step */
    } move;
    Uint8 unk_04[4];
    Float height; /* above work->pos */
};

enum balloon_mode {
    BALLOON_INIT,
    BALLOON_WAIT, /* bobs and sways until Amy grabs it */
    BALLOON_DIP, /* sinks with Amy, slowing to a stop */
    BALLOON_RISE, /* carries Amy up until an event takes control */
    BALLOON_DONE
};
extern struct collision_shape balloon_shapes[];
/* clang-format on */

static void balloon_start(struct task_work *work);
static void Normal(struct task_work *work);
static void Down(struct task_work *work);
static void Hold(struct task_work *work);
static void Draw(struct task *task);
static void balloon_destroy(struct task *task);
static void balloon_bob(struct task_work *work);
static void balloon_sway(struct task_work *work);
static void balloon_squash(struct task_work *work);

void ObjectBaloon(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BALLOON_INIT:
        task->destructor = balloon_destroy;
        task->draw = Draw;
        CCL_Init(task, balloon_shapes, COLLISION_OBJECT, 1, 2);
        balloon_start(work);
        break;
    case BALLOON_WAIT:
        Normal(work);
        break;
    case BALLOON_DIP:
        Down(work);
        break;
    case BALLOON_RISE:
        Hold(work);
        break;
        /* @hack redundant: a second break, which loads placement_kill's address
         * into R2 and BALLOON_INIT into R3 (0x8c05cfa6, 0x8c05cfac); without
         * it, the two trade, and 4 of 65 words differ */
        break;
    case BALLOON_DONE:
        DeadOut(task);
        /* fall through */
    default:
        work->mode = BALLOON_INIT;
    }
    Draw(task);
}

/* set the balloon waiting at work->pos, level and unscaled, with its step
 * count at random below 100 */
static void balloon_start(struct task_work *work)
{
    /* @hack spelling: the count through a local, which SHC holds in FR15,
     * saved on entry (0x8c05cfc6, 0x8c05cfde); stored straight from rand's
     * product, 41 of 43 words differ */
    Float count;

    work->mode = BALLOON_WAIT;
    count = rand() * (100.0F * RAND_SCALE);
    VARS(work)->move.steps = count;
    VARS(work)->height = 0.0F;
    work->ang.z = 0;
    work->scl.x = 1.0F;
    work->scl.y = 1.0F;
    work->scl.z = 1.0F;
}

static void Normal(struct task_work *work)
{
    int character;
    struct task *task;
    struct task_work *player;
    Float dx;
    Float dy;
    Float dz;
    Float distance;

    if (edit_mode) {
        return;
    }
    balloon_bob(work);
    balloon_sway(work);
    balloon_squash(work);
    ((struct balloon_vars *)&(work)->vars)->move.steps++;
    character = GetPlayerCharacterName(0);
    if (character == CHARACTER_AMY) {
        task = GetPlayerTaskPointer(0);
        player = task->work;
        dx = player->pos.x - work->pos.x;
        dy = player->pos.y - work->pos.y - VARS(work)->height + GRAB_DEPTH;
        dz = player->pos.z - work->pos.z;
        /* @hack spelling: each square stored back in its difference, which
         * SHC multiplies with FMUL and sums with FADD (0x8c05d0da to
         * 0x8c05d0ea); squared in njSqrt's argument, it fuses them with
         * FMAC, and 54 of 104 words differ */
        dx = dx * dx;
        dy = dy * dy;
        dz = dz * dz;
        distance = njSqrt(dx + dy + dz);
        if (distance < GRAB_RANGE) {
            work->mode = BALLOON_DIP;
            SetInputP(0, PLAYER_MODE_STILL);
            VARS(work)->move.speed = DIP_SPEED;
            SleepTimer();
            SetFinishAction();
        }
    }
    EntryColliList(work);
}

static void Down(struct task_work *work)
{
    /* @hack spelling: DIP_ACCEL through a local, which SHC loads first and
     * keeps at @R15 for the end (0x8c05d142, 0x8c05d17a); added as
     * DIP_ACCEL, 49 of 50 words differ */
    Float accel = DIP_ACCEL;
    struct task *task;
    struct task_work *player;

    VARS(work)->height += VARS(work)->move.speed;
    task = GetPlayerTaskPointer(0);
    player = task->work;
    player->pos = work->pos;
    player->pos.y += VARS(work)->height - HANG_DEPTH;
    VARS(work)->move.speed += accel;
    if (VARS(work)->move.speed > 0.0F) {
        work->mode = BALLOON_RISE;
    }
}

static void Hold(struct task_work *work)
{
    struct task *task;
    struct task_work *player;

    balloon_sway(work);
    balloon_squash(work);
    VARS(work)->height +=
        ((njSin(VARS(work)->move.steps * 200) * 0.5F) + 0.3F) * 0.5F;
    VARS(work)->move.steps++;
    task = GetPlayerTaskPointer(0);
    player = task->work;
    player->pos = work->pos;
    player->pos.y += VARS(work)->height - HANG_DEPTH;
    if (EV_CheckCansel()) {
        work->mode = BALLOON_DONE;
    }
}

static void Draw(struct task *task)
{
    struct task_work *work = task->work;

    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y + VARS(work)->height,
                work->pos.z);
    TURN(njRotateZ, work->ang.z);
    njScaleV(NULL, &work->scl);
    ds_DrawModelClip(&balloon_model);
    njPushMatrix(NULL);
    njTranslate(NULL, 0.0F, 0.0F, 0.0F);
    TURN(njRotateZ, -work->ang.z);
    njScale(NULL, 1.0F / work->scl.x, 1.0F / work->scl.y, 1.0F / work->scl.z);
    ds_DrawModelClip(&balloon_knot_model);
    njPushMatrix(NULL);
    njTranslate(NULL, 0.0F, 0.0F, 0.0F);
    njScale(NULL, 1.0F, 0.5F, 1.0F);
    ds_DrawModelClip(&balloon_sign_model);
    njScale(NULL, 1.0F, 2.0F, 1.0F);
    njPushMatrix(NULL);
    njTranslate(NULL, 0.0F, -9.0F, 0.0F);
    ds_DrawModelClip(&balloon_sign_frame_model);
    late_DrawObjectClipEx(4);
    shadow_draw(work, 4.8F - ((struct balloon_vars *)&(work)->vars)->height);
}

static void balloon_destroy(struct task *task)
{
}

static void balloon_bob(struct task_work *work)
{
    VARS(work)->height = njSin((VARS(work)->move.steps + 800) * 256) * 4.0F;
}

static void balloon_sway(struct task_work *work)
{
    work->ang.z = njCos((VARS(work)->move.steps + 2000) * 200) * 4096.0F;
}

static void balloon_squash(struct task_work *work)
{
    work->scl.x = 1.0F - (njCos(VARS(work)->move.steps * 2048) * 0.05F);
    work->scl.y = 1.0F - (njSin(VARS(work)->move.steps * 2048) * 0.05F);
}
