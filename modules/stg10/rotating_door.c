/* @unit 0C906E60-0C9071C0 +r04 +egflags +pool32 +poolafter=rotating_door_reset,rotating_door_swing +asmfunc=FUN_0c906e60:0c906efa */
/* O ROTDOOR door that swings open as the nearest player comes near */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "debug/print.h"
#include "draw/model.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg10/rotating_door.h"
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
Bool OnEdit(struct task *task);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
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
#define REACH 10000.0F
#define NEAR 50.0F
#define SWING_MAX 16384.0F /* a quarter turn, from shut to open */
#define SWING_SPEED 768.0F /* the top speed, in angle units a step */
#define SWING_MIN_SPEED 112.0F /* the speed braking leaves the door */
#define SWING_ACCEL 40.0F /* the speed gained each step until braking */
#define SWING_BRAKE 30.0F /* the speed lost each step braking */
#define BRAKE_OPENING (SWING_MAX * 0.65F) /* where opening starts braking */
#define BRAKE_SHUTTING (SWING_MAX * 0.35F) /* where shutting starts braking */
#define VARS(work) ((struct door_vars *)&(work)->vars)
extern NJS_MODEL rotating_door_model;

/* destroyed beyond 500 units of the camera and player 0 */
/* how far the collision record reaches from the hinge, far past the 43
 * units the door's box reaches */

/* the door opens while the nearest player is this near the hinge, along the
 * shut door's z axis */

struct door_vars {
    Float speed; /* the swing's speed, below 0 while it shuts */
    Sint16 shut_y; /* the door's angle y while shut */
    Uint8 unk_06[2];
    Float swing; /* the door's turn from shut */
};

enum door_mode { DOOR_INIT, DOOR_RUN };

void rotating_door_init(struct task *task);
void rotating_door_reset(struct task *task);
void rotating_door_swing(struct task *task);
void rotating_door_draw(struct task *task);
void rotating_door_destroy(struct task *task);
extern struct collision_shape rotating_door_shape;
void rotating_door_step(struct task *task);
#ifdef NON_MATCHING

void rotating_door_init(struct task *task)
{
    struct task_work *work = task->work;

    task->draw = rotating_door_draw;
    task->destructor = rotating_door_destroy;
    rotating_door_reset(task);
    work->mode = DOOR_RUN;
}
#else
void rotating_door_init(struct task *task)
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

void rotating_door_reset(struct task *task)
{
    struct task_work *work = task->work;

    CCL_Init(task, &rotating_door_shape, COLLISION_OBJECT, 1, 1);
    work->collision->radius = REACH;
    VARS(work)->shut_y = work->ang.y;
    VARS(work)->swing = 0.0F;
    VARS(work)->speed = 0.0F;
}

/* swing the door open while the nearest player is within NEAR, and shut
 * otherwise. each way, it speeds up until it passes BRAKE_OPENING or
 * BRAKE_SHUTTING, and then brakes */
void rotating_door_swing(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 pos;
    NJS_POINT3 local;
    Angle ang;

    pos = playertwp[GetTheNearestPlayerNumber(&work->pos)]->pos;
    njPushMatrix(&nj_unit_matrix_);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, VARS(work)->shut_y, ang);
    njInvertMatrix(NULL);
    njCalcPoint(NULL, &pos, &local);
    late_DrawObjectClipEx(1);
    work->submode = local.z >= -NEAR && local.z <= NEAR;
    if (work->submode) {
        if (VARS(work)->swing < BRAKE_OPENING) {
            VARS(work)->speed += SWING_ACCEL;
            if (VARS(work)->speed > SWING_SPEED) {
                VARS(work)->speed = SWING_SPEED;
            }
        } else {
            VARS(work)->speed -= SWING_BRAKE;
            if (VARS(work)->speed < SWING_MIN_SPEED) {
                VARS(work)->speed = SWING_MIN_SPEED;
            }
        }
    } else {
        if (VARS(work)->swing > BRAKE_SHUTTING) {
            VARS(work)->speed -= SWING_ACCEL;
            if (VARS(work)->speed < -SWING_SPEED) {
                VARS(work)->speed = -SWING_SPEED;
            }
        } else {
            VARS(work)->speed += SWING_BRAKE;
            if (VARS(work)->speed > -SWING_MIN_SPEED) {
                VARS(work)->speed = -SWING_MIN_SPEED;
            }
        }
    }
    VARS(work)->swing += VARS(work)->speed;
    if (VARS(work)->swing < 0.0F) {
        VARS(work)->swing = 0.0F;
    } else if (VARS(work)->swing > SWING_MAX) {
        VARS(work)->swing = SWING_MAX;
    }
    work->ang.y = (Angle)(VARS(work)->shut_y + VARS(work)->swing);
    EntryColliList(work);
}

void rotating_door_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count == 0) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        ds_DrawModelClip(&rotating_door_model);
        late_DrawObjectClipEx(1);
    }
}

void rotating_door_destroy(struct task *task)
{
}
