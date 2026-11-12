/* @unit 0C906140-0C9064A0 @data 0C9196F8-0C919718 +egflags +pool32 */
/* O HAMMER hammer that swings on its mount and flings the players it hits */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "debug/print.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg10/hammer.h"
#include "system/frame.h"
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
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
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

#define RANGE (500.0F * 500.0F)
#define REACH (100.0F * 100.0F)
#define SWING 14848.0F
#define FLING 0.014466831F
#define HIT_WAIT 30
#define VARS(work) ((struct hammer_vars *)&(work)->vars)
#define PHASE(work) TASK_TIMER(work)
extern NJS_OBJECT hammer_mount_object;
extern NJS_MODEL hammer_model;

/* destroyed beyond 500 units of the camera and player 0 */
/* the collision record's radius: 100 squared, though the checks take it as
 * a plain distance */

/* how far the hammer swings each way from hanging straight down, as angle x:
 * about 81.6 degrees */
/* a fling's speed is scale x times FLING times the cosine of the swing's
 * phase. the cosine peaks at the bottom of the swing, where the head moves
 * fastest */
/* the steps after a fling before the hammer can fling again */

struct hammer_vars {
    Uint8 unk_00[4];
    Sint16 wait; /* steps left of HIT_WAIT */
};

/* the swing's phase, which gains scale x each step. angle x is SWING times
 * its sine */

enum hammer_mode { HAMMER_INIT, HAMMER_RUN };

void hammer_init(struct task *task);
void hammer_reset(struct task *task);
void hammer_swing(struct task *task);
void hammer_draw(struct task *task);
void hammer_destroy(struct task *task);
extern struct collision_shape hammer_shapes[2];
extern NJS_VECTOR hammer_fling;

void ObjectFinalEggHammer(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (!OnEdit(task)) {
        switch (work->mode) {
        case HAMMER_INIT:
            hammer_init(task);
            break;
        case HAMMER_RUN:
            hammer_draw(task);
            hammer_swing(task);
            break;
        }
    } else {
        switch (work->mode) {
        case HAMMER_INIT:
            hammer_init(task);
            break;
        case HAMMER_RUN:
            debug_print(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "-> ROTATE Y");
            debug_print(EDITOR_LABEL(EDITOR_ROW_SCL_X), "-> ROTATION SPEED");
            hammer_draw(task);
            hammer_swing(task);
            break;
        }
    }
}

void hammer_init(struct task *task)
{
    struct task_work *work = task->work;

    task->draw = hammer_draw;
    task->destructor = hammer_destroy;
    hammer_reset(task);
    work->mode = HAMMER_RUN;
}

void hammer_reset(struct task *task)
{
    struct task_work *work = task->work;

    CCL_Init(task, hammer_shapes, COLLISION_OBJECT, 1, 2);
    work->collision->radius = REACH;
    PHASE(work) = 0;
    work->ang.x = 0;
    VARS(work)->wait = 0;
}

void hammer_swing(struct task *task)
{
    struct task_work *work = task->work;
    struct collision_work *collision = work->collision;
    struct task_work *player;
    NJS_VECTOR speed;
    Angle ang;
    int i;

    if ((collision->flags & COLLISION_HIT) &&
        collision->hit->kind == COLLISION_PLAYER && VARS(work)->wait == 0) {
        VARS(work)->wait = HIT_WAIT;
        hammer_fling.z = -(work->scl.x * njCos(PHASE(work)) * FLING);
        njPushMatrix(&nj_unit_matrix_);
        TURN_VIA(njRotateY, work->ang.y, ang);
        TURN_VIA(njRotateX, work->ang.x, ang);
        njCalcVector(NULL, &hammer_fling, &speed);
        player = collision->hit->owner->work;
        for (i = 0; i < PLAYER_COUNT; i++) {
            if (playertwp[i] == player) {
                player_set_speed(i, speed.x, speed.y, speed.z);
            }
        }
        late_DrawObjectClipEx(1);
    } else if (VARS(work)->wait) {
        VARS(work)->wait--;
    }
    PHASE(work) += work->scl.x;
    work->ang.x = njSin(PHASE(work)) * SWING;
    EntryColliList(work);
}

void hammer_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count == 0) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        late_DrawObject(&hammer_mount_object);
        TURN_VIA(njRotateX, work->ang.x, ang);
        ds_DrawModelClip(&hammer_model);
        late_DrawObjectClipEx(1);
    }
}

void hammer_destroy(struct task *task)
{
}
