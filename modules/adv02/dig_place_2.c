/* @unit 0C904E80-0C9051A0 +r04 +egflags +pool32 */
/* the dig place the object list names O DIG PLACE2: a mound Knuckles digs a
 * kill switch out of */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv02/dig_place_2.h"
#include "adv02/kill_switch.h"
#include "adv02/texlists.h"
#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "debug/print.h"
#include "draw/draw.h"
#include "object/placement.h"
#include "player/knuckles.h"
#include "player/player.h"
#include "sound/sound.h"
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
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
Bool OnEdit(struct task *task);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
Bool Knuckles_KakeraGame_GetNearEmePos(NJS_POINT3 *from, NJS_POINT3 *pos,
                                       Float *distance);
Bool Knuckles_KakeraGame_Set_PutEme(int id, NJS_POINT3 *pos);
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
int Serif_Play(const NJS_POINT3 *pos, Float radius);
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
#define NEAR 500.0F
#define DRAW_RANGE 500.0F /* drawn only while a player is this near */
#define RADIUS 20.0F /* the collision record's radius */
#define GROUND_FLAGS WORLD_MEDIUM
#define SPOT_FLAGS (WORLD_MEDIUM | WORLD_DIGGABLE)
#define FRAME_SPEED 0.3F /* the motion frames the place advances each step */
#define VARS(work) ((struct dig_place_2_vars *)&(work)->vars)
extern NJS_OBJECT dig_place_2_ground_object;
extern NJS_OBJECT dig_place_2_spot_object;
/* the action the place's draw loops. its object's child is
 * dig_place_2_spot_object */
/* @hack type: declared an array, not the one NJS_ACTION it is, so SHC pools
 * its address at 0x0c905294 and reads motion through it, MOV.L @(4,R4),R3 at
 * 0x0c9051e8; declared as one, the code runs 32 bytes longer, and 21 of
 * dig_place_2_update's 124 words differ */
extern NJS_ACTION dig_place_2_action[];

/* placement_try_leave_by ends the task once the camera and player 0 are
 * both beyond 500 */
/* the collision world tests the place only while a player is this near */

enum dig_place_mode { DIG_PLACE_INIT, DIG_PLACE_RUN };

struct dig_place_2_vars {
    /* the ground's and the spot's copies in the collision world */
    NJS_OBJECT *ground;
    NJS_OBJECT *spot;
    Float frame;
};

static void dig_place_2_init(struct task *task);
void dig_place_2_add_to_world(struct task *task);
void dig_place_2_update(struct task *task);
void dig_place_2_draw(struct task *task);
void dig_place_2_destroy(struct task *task);
extern struct collision_shape dig_place_2_shape[1];

static void dig_place_2_reset(struct task *task)
{
    struct task_work *work = task->work;

    dig_place_2_add_to_world(task);
    work->submode = 0;
}
void dig_place_2_step(struct task *task);

static void dig_place_2_init(struct task *task)
{
    struct task_work *work = task->work;

    task->draw = dig_place_2_draw;
    task->destructor = dig_place_2_destroy;
    VARS(work)->frame = 0.0F;
    CCL_Init(task, dig_place_2_shape, COLLISION_OBJECT, 1, 1);
    work->collision->radius = RADIUS;
    dig_place_2_reset(task);
    work->mode = DIG_PLACE_RUN;
}

void dig_place_2_add_to_world(struct task *task)
{
    struct task_work *work = task->work;
    struct task_force *force = task->force;
    NJS_OBJECT *object;
    NJS_OBJECT *from;

    force->turn.x = 0;
    force->turn.y = 0;
    force->turn.z = 0;
    force->speed.x = 0.0F;
    force->speed.y = 0.0F;
    force->speed.z = 0.0F;
    from = &dig_place_2_ground_object;
    VARS(work)->ground = object = GetMobileLandObject();
    object->evalflags = from->evalflags;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    object->ang[0] = 0;
    object->ang[1] = work->ang.y;
    object->ang[2] = 0;
    object->pos[0] = from->pos[0] + work->pos.x;
    object->pos[1] = from->pos[1] + work->pos.y;
    object->pos[2] = from->pos[2] + work->pos.z;
    object->model = from->model;
    object->child = NULL;
    object->sibling = NULL;
    RegisterCollisionEntry(GROUND_FLAGS, task, object);
    from = &dig_place_2_spot_object;
    VARS(work)->spot = object = GetMobileLandObject();
    object->evalflags = from->evalflags;
    object->scl[0] = 1.0F;
    object->scl[1] = 1.0F;
    object->scl[2] = 1.0F;
    object->ang[0] = 0;
    object->ang[1] = work->ang.y;
    object->ang[2] = 0;
    object->pos[0] = from->pos[0] + work->pos.x;
    object->pos[1] = from->pos[1] + work->pos.y;
    object->pos[2] = from->pos[2] + work->pos.z;
    object->model = from->model;
    object->child = NULL;
    object->sibling = NULL;
    RegisterCollisionEntry(SPOT_FLAGS, task, object);
}

/* while no kill switch lives, raise one when Knuckles touches the place and
 * player 0's action is KNUCKLES_DIGGING_OUT. the toucher and player 0 can be
 * different players */
void dig_place_2_update(struct task *task)
{
    struct task_work *work = task->work;
    struct task *button;
    struct task_work *button_work;
    struct task_motion *motion;

    if (kill_switch_work == NULL && (work->collision->flags & COLLISION_HIT) &&
        player_task_character(work->collision->hit->owner) ==
            CHARACTER_KNUCKLES &&
        knuckles_get_activity(0) == KNUCKLES_DIGGING_OUT) {
        button =
            CreateElementalTask(TASK_MOTION | TASK_WORK, 3, kill_switch_step);
        button_work = button->work;
        motion = button->motion;
        button_work->pos.x = work->pos.x;
        button_work->pos.y = work->pos.y + 11.0F;
        button_work->pos.z = work->pos.z;
        motion->speed.x = 0.0F;
        motion->speed.y = 0.5F;
        motion->speed.z = 0.0F;
        dsPlay_oneshot(SE_NOTICE, 0, 0, 0);
    }
    if (Serif_Play(&work->pos, 500.0F)) {
        work->flags |= 0x100;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
    if (kill_switch_work == NULL) {
        EntryColliList(work);
    }
    VARS(work)->frame += FRAME_SPEED;
    if (VARS(work)->frame >= dig_place_2_action->motion->nbFrame - 1.0F) {
        VARS(work)->frame -= dig_place_2_action->motion->nbFrame - 1.0F;
    }
}

void dig_place_2_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    if (Serif_Play(&work->pos, 500.0F) == 0) {
        return;
    }
    njSetTexture_jp(&mrobj_texlist);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
    ds_ActionClip(dig_place_2_action,
                  ((struct dig_place_2_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

void dig_place_2_destroy(struct task *task)
{
    struct task_work *work = task->work;

    WithdrawCollisionEntry(task, VARS(work)->ground);
    ReleaseMobileLandObject(VARS(work)->ground);
    WithdrawCollisionEntry(task, VARS(work)->spot);
    ReleaseMobileLandObject(VARS(work)->spot);
}
