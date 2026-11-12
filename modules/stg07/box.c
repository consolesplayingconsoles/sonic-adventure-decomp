/* @unit 0C901A20-0C901E20 +r04 +egflags +pool32 */
/* HakoAF, a box that breaks into its six pieces once something hits it. the
 * pieces fly apart and away from player 0, shrinking as they spread. they
 * rise, then fall. once they fall faster than BOX_GONE_SPEED, the box is
 * gone for good */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/common.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg07/box.h"
#include "system/task.h"
#include "system/texture.h"
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
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
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
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
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

#define VARS(work) ((struct box_vars *)&(work)->vars)
#define BOX_SPREAD(work) ((work)->scl.x)
#define BOX_RISE(work) ((work)->scl.y)
#define BOX_SPREAD_STEP 1.0F
#define BOX_GRAVITY 0.2F
#define BOX_GONE_SPEED (-10.0F)
#define BOX_AWAY 2.5F
#define BOX_SHRINK 0.05F
extern NJS_MODEL box_piece0_model;
extern NJS_MODEL box_piece1_model;
extern NJS_MODEL box_piece2_model;
extern NJS_MODEL box_piece3_model;
extern NJS_MODEL box_piece4_model;
extern NJS_MODEL box_piece5_model;

struct box_vars {
    Uint8 unk_00[4];
    Angle away; /* the way the pieces fly, away from player 0 */
};
extern struct collision_shape box_shape;
/* clang-format on */

void box_destroy(struct task *task)
{
}

/* draw a piece at x, y and z in the box, with ang its own angle */
void box_draw_piece(struct task_work *work, Angle ang, Float x, Float y,
                    Float z, NJS_MODEL *model)
{
    Float dx;
    Float dz;
    Float scale;

    if (BOX_SPREAD(work) == 0.0F) {
        njPushMatrix(NULL);
        njTranslate(NULL, x, y, z);
        ds_DrawModelClip(model);
        late_DrawObjectClipEx(1);
    } else {
        dx = (njSin(VARS(work)->away) * BOX_SPREAD(work) * BOX_AWAY) +
             (njSin(ang) * BOX_SPREAD(work));
        dz = (-njCos(VARS(work)->away) * BOX_SPREAD(work) * BOX_AWAY) +
             (njCos(ang) * BOX_SPREAD(work));
        scale = 1.0F - (BOX_SPREAD(work) * BOX_SHRINK);
        njPushMatrix(NULL);
        njTranslate(NULL, x + dx, y + BOX_RISE(work), z + dz);
        njScale(NULL, scale, scale, scale);
        ds_DrawModelClip(model);
        late_DrawObjectClipEx(1);
    }
}

void DispExp(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    box_draw_piece(work, 0xe000, -5.699998F, 7.499999F, 3.799999F,
                   &box_piece0_model);
    box_draw_piece(work, 0xa000, -3.8F, 7.499996F, -3.899999F,
                   &box_piece1_model);
    box_draw_piece(work, 0x5000, 3.7F, 7.499999F, -2.799999F,
                   &box_piece2_model);
    box_draw_piece(work, 0x1000, 1.8F, 5.5F, 3.7F, &box_piece3_model);
    box_draw_piece(work, 0x6000, 4.0F, 7.3F, -6.5F, &box_piece4_model);
    box_draw_piece(work, 0x3000, 2.0F, 13.200004F, 3.7F, &box_piece5_model);
    late_DrawObjectClipEx(1);
}

/* the step of a broken box */
void Exp(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (BOX_RISE(work) < BOX_GONE_SPEED) {
        DeadOut(task);
        return;
    }
    BOX_SPREAD(work) += BOX_SPREAD_STEP;
    BOX_RISE(work) -= BOX_GRAVITY;
    work->pos.y += BOX_RISE(work);
    DispExp(task);
}

/* the step of a whole box. it is the box's draw too, so it tests for a hit
 * even while the game is paused. a hit sends the pieces away from player 0,
 * and breaks the box */
void box_wait(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 *player = &playertwp[0]->pos;

    if (CheckRangeOut(task)) {
        return;
    }
    DispExp(task);
    if (work->collision->flags & COLLISION_HIT) {
        VARS(work)->away = ((Angle)(njArcTan2(work->pos.z - player->z,
                                              work->pos.x - player->x) *
                                    ANGLE_PER_RADIAN) +
                            work->ang.y + 0x4000) &
                           0xffff;
        task->step = Exp;
        task->draw = DispExp;
    }
    if (!OnEdit(task)) {
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
    }
}

void box_step(struct task *task)
{
    struct task_work *work = task->work;

    BOX_SPREAD(work) = 0.0F;
    BOX_RISE(work) = 0.5F;
    VARS(work)->away = 0;
    CCL_Init(task, &box_shape, COLLISION_OBJECT, 1, 1);
    task->destructor = box_destroy;
    task->step = box_wait;
    task->draw = box_wait;
}
