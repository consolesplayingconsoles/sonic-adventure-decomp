/* @unit 0C909E80-0C90A0E0 +egflags +pool32 */
/* the roll: the step of one of act 1's paths. a touch of the sphere at the
 * path's start curls player 0 up. the task then carries player 0 along the
 * path. near its end, the task sends player 0 off, standing again, and
 * ends */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "path/path.h"
#include "player/player.h"
#include "stage/stage.h"
#include "stg07/roll_path.h"
#include "system/task.h"
#include "system/util.h"
float njFloor(float x);
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
Bool ChkPause(void);
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

/* the carry's distance along the path, and the distance at which it ends,
 * in the work's scale */
#define ROLL_ALONG(work) ((work)->scl.x)
#define ROLL_END(work) ((work)->scl.y)

#define ROLL_SPEED 15.0F
#define ROLL_SHORT 10.0F
#define LEAVE_SPEED 3.0F
#define LEAVE_RISE 1.0F
#define ROLL_START_X 6950.0F
#define ROLL_START_Y (-2440.0F)
#define ROLL_START_Z 993.0F
enum roll_mode { ROLL_START, ROLL_WAIT, ROLL_CARRY };
extern struct collision_shape roll_path_shape;
/* clang-format on */

void SetPath2Taskwk(struct path *path, struct task_work *work, Float along);
void roll_path_carry(struct task_work *work);

/* the task ends once the stage or act changes, and once the carry ends */
void ReverseRuinLoop(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (GetStageNumber() != PATH_VARS(work)->stage_act) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case ROLL_START:
        work->mode = ROLL_WAIT;
        work->timer = 0;
        ROLL_ALONG(work) = 0.0F;
        work->pos.x = ROLL_START_X;
        work->pos.y = ROLL_START_Y;
        work->pos.z = ROLL_START_Z;
        CCL_Init(task, &roll_path_shape, COLLISION_OBJECT, 1, 1);
        SetPath2Taskwk(PATH_VARS(work)->path, work, ROLL_ALONG(work));
        ROLL_END(work) = PATH_VARS(work)->path->length - ROLL_SHORT;
        break;
    case ROLL_WAIT:
        if (work->collision->flags & COLLISION_HIT) {
            SetInputP(0, PLAYER_MODE_BALL);
            work->mode = ROLL_CARRY;
        }
        EntryColliList(work);
        break;
    case ROLL_CARRY:
        ROLL_ALONG(work) += ROLL_SPEED;
        SetPath2Taskwk(PATH_VARS(work)->path, work, ROLL_ALONG(work));
        roll_path_carry(work);
        if (ROLL_ALONG(work) > ROLL_END(work)) {
            ang = -work->ang.y + NJM_DEG_ANG(90);
            player_set_speed(0, njCos(ang) * LEAVE_SPEED, LEAVE_RISE,
                             -(njSin(ang) * LEAVE_SPEED));
            SetInputP(0, PLAYER_MODE_RESET);
            FreeTask(task);
            return;
        }
        break;
    }
}

/* put the work along that far on the path, tilted as the path is there.
 * its y angle comes from the way the path runs there */
void SetPath2Taskwk(struct path *path, struct task_work *work, Float along)
{
    struct GetStatusOnPath sample;
    NJS_VECTOR ahead;
    Angle ang;

    sample.distance = along;
    if (GetStatusOnPath(path, &sample)) {
        work->pos = sample.pos_copy;
        work->ang.x = sample.smooth_x;
        work->ang.z = sample.smooth_z;
        njPushMatrix(&nj_unit_matrix_);
        TURN_VIA(njRotateX, -work->ang.x, ang);
        TURN_VIA(njRotateZ, -work->ang.z, ang);
        njCalcVector(NULL, &sample.ahead, &ahead);
        late_DrawObjectClipEx(1);
        work->ang.y = (Angle)(njArcTan2(ahead.x, ahead.z) * ANGLE_PER_RADIAN);
    }
}

/* put player 0 where the work is, turned as the work is */
void roll_path_carry(struct task_work *work)
{
    struct task_work *player = playertwp[0];

    player->pos = work->pos;
    player->ang.x = work->ang.x;
    player->ang.y = -work->ang.y + NJM_DEG_ANG(90);
    player->ang.z = work->ang.z;
}
