/* @unit 8C05CFE0-8C05D900 @ddata 8C1B9AE0-8C1B9B28 +r04 +egflags +pool32 */
/* the item box, O ITEMBOX in the object lists. a player or an attack opens
 * it, and the item its face shows is given */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "effect/snow.h"
#include "hud/hud.h"
#include "object/item_box.h"
#include "object/item_box_air.h"
#include "object/models.h"
#include "object/placement.h"
#ifdef GCC
#include "player/e102_shot.h"
#endif
#include "player/lockon.h"
#include "player/player.h"
#include "player/target.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "stg03/mirror.h"
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
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void *MAlloc(int size);
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
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void FUN_8c08a060(Sint16 count);
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
void PutItem_ItemBoxAir(NJS_POINT3 *pos, enum item_kind kind);
void ObjectItemboxAir(struct task *task);
void InitItemBoxManager(void);
void FUN_8c05e038(enum item_kind kind);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void FUN_8c091a9e(struct task *task);
void DeadOut(struct task *task);
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
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
struct player *GetPlayerWorkPointer(Uint8 player);
int GetTheNearestPlayerNumber(NJS_POINT3 *pos);
Bool CheckPlayerRideOnMobileLandObjectP(Uint8 player, struct task *task);
void FUN_8c07d2e0(Uint8 player);
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
struct task *createMirrorTask(struct task *task);
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

/* every item plays SE_ITEM. in E-102's game, the speed up also plays
 * SE_E102_SPEED_UP, and every other item SE_E102_ITEM */
#define SE_E102_ITEM 1196
#define SE_E102_SPEED_UP 1197

/* the box's work->mode */
#define KIND(work) ((work)->scl.x)
#define SPIN(work) ((work)->scl.y)
#define GROWTH(work) ((work)->scl.z)
#define GROW_STEP 0.11F
#define GROWN 5.0F
#define SPIN_STEP 3.0F
enum item_box_mode {
    ITEM_BOX_INIT, /* starts the box the object lists place */
    ITEM_BOX_GROW, /* grows in */
    ITEM_BOX_WAIT, /* waits to be opened */
    ITEM_BOX_OPEN, /* opens, in one step */
    ITEM_BOX_OPENED, /* only its base stays */
    ITEM_BOX_STILL, /* it collides, and nothing more */
    ITEM_BOX_RESET /* starts over at ITEM_BOX_INIT */
};

/* a box's kind is its scl.x, its icon's turn in degrees its scl.y, and its
 * growth its scl.z */

/* a growing box's GROWTH rises GROW_STEP a step, to GROWN. until then the
 * box draws at scale GROWTH / GROWN */

/* a waiting box's icon turns SPIN_STEP degrees a step */

static void item_box_grow(struct task_work *work);
static void item_box_wait(struct task *task);
static void item_box_open(struct task *task);
static void item_box_draw(struct task *task);
static void item_box_draw_open(struct task *task);
static void item_box_burst(struct task_work *work);
static void item_box_destroy(struct task *task);
static void item_give_speed_up(struct task_work *work);
static void item_give_5_rings(struct task_work *work);
static void item_give_10_rings(struct task_work *work);
static void item_give_random_rings(struct task_work *work);
static void item_give_1up(struct task_work *work);
static void item_give_invincibility(struct task_work *work);
static void item_give_barrier(struct task_work *work);
static void item_give_bomb(struct task_work *work);
static void item_give_magnetic_barrier(struct task_work *work);
extern const NJS_VECTOR item_box_up;
extern const Sint16 random_ring_counts[6];
extern struct collision_shape item_box_shapes[2];
extern struct collision_shape item_box_open_shapes[2];
extern NJS_TEXNAME dat_8c794ec8[1];
extern NJS_TEXNAME dat_8c794ed4[1];
extern NJS_TEXLIST dat_8c1d0510[2];

/* each kind's face, by its texture's name in OBJ_REGULAR */
struct item item_kinds[ITEM_COUNT] = {
    {35, item_give_speed_up}, /* item_speed */
    {72, item_give_invincibility}, /* item_muteki */
    {33, item_give_5_rings}, /* item_ring5 */
    {32, item_give_10_rings}, /* item_ring10 */
    {34, item_give_random_rings}, /* item_ringq */
    {71, item_give_barrier}, /* item_nbarria */
    {31, item_give_1up}, /* item_1up, until a draw sets the character's */
    {73, item_give_bomb}, /* item_explosion */
    {70, item_give_magnetic_barrier}, /* item_tbarria */
};
extern Uint32 item_1up_textures[8];
extern Uint32 item_box_kind;
extern Sint32 dat_8c794ee4;

void item_box_create(NJS_POINT3 *pos, enum item_kind kind)
{
    struct task *task = CreateElementalTask(TASK_WORK, 3, item_box_step);
    struct task_work *work = task->work;

    work->pos = *pos;
    KIND(work) = kind;
    task->destructor = item_box_destroy;
    task->draw = item_box_draw;
    CCL_Init(task, item_box_shapes, COLLISION_ITEM, 1, 2);
    work->mode = ITEM_BOX_GROW;
    GROWTH(work) = 0.0F;
    task->motion = CAlloc(1, sizeof(struct lockon_target));
}

void item_box_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (work->mode == ITEM_BOX_INIT || work->mode == ITEM_BOX_WAIT ||
        work->mode == ITEM_BOX_GROW) {
        task->draw = item_box_draw;
    } else if (work->mode == ITEM_BOX_OPEN || work->mode == ITEM_BOX_OPENED) {
        task->draw = item_box_draw_open;
    }
    if ((int)KIND(work) < 0) {
        KIND(work) = ITEM_COUNT - 1;
    } else if ((int)KIND(work) >= ITEM_COUNT) {
        KIND(work) = 0.0F;
    }
    item_box_kind = KIND(work);
    switch (work->mode) {
    case ITEM_BOX_INIT:
        if (task->placement != ((void *)0)) {
            FUN_8c091a9e(task);
        }
        task->destructor = item_box_destroy;
        task->draw = item_box_draw;
        CCL_Init(task, item_box_shapes, COLLISION_ITEM, 1, 2);
        work->mode = ITEM_BOX_GROW;
        GROWTH(work) = 0.0F;
        task->motion = CAlloc(1, sizeof(struct lockon_target));
        if (GetStageNumber() == STAGE_TWINKLE_MIRRORS) {
            createMirrorTask(task);
        }
        if (placement_used(task)) {
            work->mode = ITEM_BOX_OPEN;
        }
        break;
    case ITEM_BOX_GROW:
        item_box_grow(work);
        break;
    case ITEM_BOX_WAIT:
        item_box_wait(task);
        break;
    case ITEM_BOX_OPEN:
        item_box_open(task);
        break;
    case ITEM_BOX_OPENED:
    case ITEM_BOX_STILL:
        EntryColliList(work);
        break;
    case ITEM_BOX_RESET:
    default:
        work->mode = ITEM_BOX_INIT;
        break;
    }
    if (work->mode == ITEM_BOX_INIT || work->mode == ITEM_BOX_WAIT ||
        work->mode == ITEM_BOX_GROW) {
        item_box_draw(task);
    } else if (work->mode == ITEM_BOX_OPEN || work->mode == ITEM_BOX_OPENED) {
        item_box_draw_open(task);
    }
    /* @hack redundant: the range checked again, its result tested to no
     * effect, which keeps the image's TST R0,R0 at 0x8c060548. without it,
     * the step runs 2 bytes short and 27 of its 185 words differ */
    if (CheckRangeOut(task)) {
    }
    if (work->mode == ITEM_BOX_WAIT) {
        player_add_target(work->pos.x, work->pos.y, work->pos.z, 3.0F);
    }
    LoopTaskC(task);
}

static void item_box_grow(struct task_work *work)
{
    GROWTH(work) += GROW_STEP;
    if (GROWTH(work) >= GROWN) {
        work->mode = ITEM_BOX_WAIT;
        GROWTH(work) = 1.0F;
    }
}

/* a player's or an attack's touch opens the box when it is on the box's
 * top, or when it damages the box. a player that touched the top bounces
 * up, while off the ground. the item is given when player 0 opened the box.
 * in E-102's game, or with Tails as player 0 and player 1 not Sonic, it is
 * given whoever opened it */
static void item_box_wait(struct task *task)
{
    struct task_work *work = task->work;
    struct collision_work *hit = work->collision->hit;

    if (edit_mode) {
        return;
    }
    if (work->collision->flags & COLLISION_HIT) {
        if (hit->kind == COLLISION_PLAYER || hit->kind == COLLISION_ATTACK) {
            /* @hack spelling: player_get_task called through a local, whose
             * address SHC loads once, into R13 (MOV.L at 0x8c0605de). called
             * by name, each call loads it again, and 140 of 144 words
             * differ */
            struct task *(*get_task)(Uint8 player) = GetPlayerTaskPointer;

            if (work->collision->own_shape == 1) {
                work->mode = ITEM_BOX_OPEN;
                if (work->collision->hit->owner == get_task(0) &&
                    !(playertwp[0]->flags & PLAYER_ON_LAND)) {
                    player_set_speed(0, 0.0F, 2.0F, 0.0F);
                } else if (work->collision->hit->owner == get_task(1) &&
                           /* @bug logic: player 1's bounce tests player
                            * 0's PLAYER_ON_LAND, as player 0's does (MOV.L
                            * @R0,R0 at 0x8c060670 reads player_work[0]).
                            * player 1 bounces only while player 0 is off
                            * the ground */
                           !(playertwp[0]->flags & PLAYER_ON_LAND)) {
                    player_set_speed(1, 0.0F, 2.0F, 0.0F);
                }
            }
            if (work->flags & COLLISION_DAMAGED) {
                work->mode = ITEM_BOX_OPEN;
            }
            if (work->mode == ITEM_BOX_OPEN) {
                if (item_kinds[item_box_kind].give != NULL &&
                    (work->collision->hit->owner == get_task(0) ||
                     GetPlayerNumber() == 6 || GetPlayerNumber() == 7 ||
                     GetPlayerNumber() == 0 ||
                     (GetPlayerCharacterName(1) == 2 &&
                      GetPlayerCharacterName(0) == 0) ||
                     (GetPlayerCharacterName(0) == 2 &&
                      GetPlayerCharacterName(1) != 0))) {
                    item_kinds[item_box_kind].give(work);
                    FUN_8c05e038(item_box_kind);
                }
            }
        }
    }
    EntryColliList(work);
    SPIN(work) += SPIN_STEP;
}

/* open the box. it bursts, unless its placement was used before, and marks
 * the placement used. then its lock-on goes, and its shapes become the
 * base's */
static void item_box_open(struct task *task)
{
    struct task_work *work = task->work;

    if (task->placement != NULL) {
        /* @hack spelling: an empty then-arm, which loads placement_set_used's
         * and lockon_release's addresses into R2 (MOV.L at 0x8c060722 and
         * 0x8c060734). as if (!placement_used(task)), they take R3 and 12 of
         * 43 words differ */
        if (placement_used(task)) {
        } else {
            placement_set_used(task);
            item_box_burst(work);
        }
    } else {
        item_box_burst(work);
    }
    E102KillCursor(task);
    collision_free(work);
    CCL_Init(task, item_box_open_shapes, COLLISION_OBJECT, 1, 2);
    work->mode = ITEM_BOX_OPENED;
}

/* draw the box, with its kind's icon turned SPIN degrees in the glass.
 * growing, it draws at scale GROWTH / GROWN. it first sets the character's
 * extra-life face in item_kinds */
static void item_box_draw(struct task *task)
{
    struct task_work *work = task->work;
    Float scale;

    item_kinds[ITEM_1UP].texture = item_1up_textures[GetPlayerNumber()];
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    if (work->mode != ITEM_BOX_WAIT) {
        scale = GROWTH(work) * (1.0F / GROWN);
        njScale(NULL, scale, scale, scale);
    }
    ds_DrawModelClip(&item_box_base_model);
    njPushMatrix(NULL);
    ds_DrawModelClip(&item_box_glass_model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    ds_DrawModelClip(&item_box_top_model);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njTranslate(NULL, 0.0F, 7.5F, 0.0F);
    TURN(njRotateY, (Angle)(SPIN(work) * ANGLE_PER_DEGREE));
    item_box_kind = KIND(task->work);
    item_box_icon_model.mats->attr_texId = item_kinds[item_box_kind].texture;
    ds_DrawModelClip(&item_box_icon_model);
    late_DrawObjectClipEx(2);
}

static void item_box_draw_open(struct task *task)
{
    struct task_work *work = task->work;

    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    ds_DrawModelClip(&item_box_base_model);
    late_DrawObjectClipEx(1);
}

static void item_box_burst(struct task_work *work)
{
    NJS_POINT3 pos;

    pos = work->pos;
    pos.y += 5.0F;
    snow_create(&pos, &item_box_up, 1.0F);
}

static void item_box_destroy(struct task *task)
{
}

/* speed up the player that owns the touch that opened the box */
static void item_give_speed_up(struct task_work *work)
{
    struct collision_work *hit = work->collision->hit;
    FUN_8c07d2e0(((struct player_vars *)&(hit->owner->work)->vars)->player);
    if (GetPlayerNumber() == 6) {
        dsPlay_oneshot(1197, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
}

static void item_give_5_rings(struct task_work *work)
{
    ring_add(5);
    if (GetPlayerNumber() == CHARACTER_E102) {
        dsPlay_oneshot(SE_E102_ITEM, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
}

static void item_give_10_rings(struct task_work *work)
{
    ring_add(10);
    if (GetPlayerNumber() == CHARACTER_E102) {
        dsPlay_oneshot(SE_E102_ITEM, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
}

static void item_give_random_rings(struct task_work *work)
{
    item_rings_given = random_ring_counts[(int)(rand() * (6 * RAND_SCALE))];
    ring_add(item_rings_given);
    if (GetPlayerNumber() == CHARACTER_E102) {
        dsPlay_oneshot(SE_E102_ITEM, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
}

static void item_give_1up(struct task_work *work)
{
    FUN_8c08a060(1);
    if (GetPlayerNumber() == CHARACTER_E102) {
        dsPlay_oneshot(SE_E102_ITEM, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
}

static void item_give_invincibility(struct task_work *work)
{
    player_give_invincibility(0);
    if (GetPlayerNumber() == CHARACTER_E102) {
        dsPlay_oneshot(SE_E102_ITEM, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
}

static void item_give_barrier(struct task_work *work)
{
    player_give_barrier(0);
    if (GetPlayerNumber() == CHARACTER_E102) {
        dsPlay_oneshot(SE_E102_ITEM, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
}

static void item_give_bomb(struct task_work *work)
{
    if (GetPlayerNumber() == CHARACTER_E102) {
        dsPlay_oneshot(SE_E102_ITEM, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
    item_explosion_start(&work->pos);
}

static void item_give_magnetic_barrier(struct task_work *work)
{
    player_give_magnetic_barrier(0);
    if (GetPlayerNumber() == CHARACTER_E102) {
        dsPlay_oneshot(SE_E102_ITEM, 0, 0, 0);
    }
    dsPlay_oneshot(SE_ITEM, 0, 0, 0);
}
