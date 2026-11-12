/* @unit 8C0DEDE0-8C0DF040 +r04 +egflags +pool32 */
/* the drums Amy takes up and sets down */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "draw/model.h"
#include "player/amy_drum.h"
#include "player/player.h"
#include "player/textures.h"
#include "stage/stage.h"
#include "system/frame.h"
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
Bool FUN_8c0deef6(NJS_POINT3 *pos);
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
Bool ChkPause(void);
void *syMalloc_default_malloc(size_t size);
Angle AdjustAngle(Angle from, Angle to, Angle step);
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

/* a drum further than this from player 0 neither draws nor collides */
#define DRUM_RANGE 400.0F

/* a player touching a drum marks it touched only within this height of it,
 * and facing it within this angle */
#define TOUCH_HEIGHT 2.0F
#define TOUCH_FACING NJM_DEG_ANG(45)

/* the stage_act of drum_places's last row, which no act has */
#define DRUM_PLACES_END 0x7fff

/* the act stage_act sets out count drums, at pos[0] to pos[count - 1] */
struct drum_place {
    Uint16 stage_act;
    Uint16 count;
    NJS_POINT3 *pos;
};

extern NJS_MODEL amy_drum_model;

static void FUN_8c0dee22(struct task *task);
static void drum_init(struct task *task);
extern struct collision_shape drum_shapes[];
extern NJS_POINT3 drum_twinkle_pos[];
extern NJS_POINT3 drum_final_pos[];
extern struct drum_place drum_places[];
extern struct task *drum_touched;
static void FUN_8c0dede0(struct task *task)
{
    if (loop_count == 0) {
        njSetTexture_jp(&amy_texlist);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &task->work->pos);
        ds_DrawModelClip(&amy_drum_model);
        late_DrawObjectClipEx(1);
    }
}

/* the step of a drum. within DRUM_RANGE of player 0, it draws the drum and
 * registers its collision, and a player's touch marks it touched as
 * TOUCH_HEIGHT and TOUCH_FACING allow. the drum ends once player 0 has no
 * task */
void FUN_8c0dee22(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    struct collision_work *hit;
    struct task_work *toucher;
    NJS_VECTOR away;
    Angle ang;

    if (player == NULL) {
        FreeTask(task);
        return;
    }
    if (CalcDistance(&work->pos, &player->pos) > DRUM_RANGE) {
        return;
    }
    if (work->flags & COLLISION_TOUCHING) {
        hit = work->collision->hit;
        if (hit != NULL && hit->kind == COLLISION_PLAYER) {
            toucher = hit->owner->work;
            away = work->pos;
            njSubVector(&away, &toucher->pos);
            ang = (Angle)(njArcTan2(away.z, away.x) * ANGLE_PER_RADIAN);
            if (_builtin_fabsf(away.y) < TOUCH_HEIGHT &&
                DiffAngle(toucher->ang.y, ang) < TOUCH_FACING) {
                drum_touched = task;
            }
        }
    }
    FUN_8c0dede0(task);
    EntryColliList(work);
}

static void drum_init(struct task *task)
{
    CCL_Init(task, drum_shapes, COLLISION_OBJECT, 1, 2);
    task->step = FUN_8c0dee22;
    task->draw = FUN_8c0dede0;
}

Bool FUN_8c0deef6(NJS_POINT3 *pos)
{
    struct task *task;

    /* @hack spelling: the task assigned in the test, which tests R0 and copies
     * it to R4 in the BT/S's slot (MOV R0,R4 at 0x8c0e8e58); assigned in a
     * statement of its own, SHC copies it first and tests R4, and 3 of 28
     * words differ */
    if ((task = CreateElementalTask(TASK_WORK, 6, drum_init)) != NULL) {
        task->work->pos = *pos;
        return TRUE;
    }
    return FALSE;
}

Bool amy_drum_create_all(void)
{
    struct drum_place *place;
    Uint16 stage_act;
    int count;
    NJS_POINT3 *pos;

    if (GetPlayerNumber() != CHARACTER_AMY) {
        return FALSE;
    }
    stage_act = GetStageNumber();
    place = drum_places;
    while (place->stage_act != stage_act) {
        if (place->stage_act == DRUM_PLACES_END) {
            return FALSE;
        }
        place++;
    }
    count = place->count;
    pos = place->pos;
    for (; count > 0; count--, pos++) {
        if (!FUN_8c0deef6(pos)) {
            return FALSE;
        }
    }
    drum_touched = NULL;
    return TRUE;
}

struct task *amy_drum_get_touched(void)
{
    return drum_touched;
}

void amy_drum_clear_touched(void)
{
    drum_touched = NULL;
}
