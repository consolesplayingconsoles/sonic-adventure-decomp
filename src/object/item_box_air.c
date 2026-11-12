/* @unit 8C05D900-8C05E5C0 @data 8C154B90-8C154BA0 +r04 +egflags +pool32 */
/* the floating item box, O ITEMBOXAIR or O ITEMBOX AIR in the object lists,
 * which a player's or an attack's touch bursts. this file also keeps two
 * things both kinds of box share. one is the row of items just collected,
 * at the foot of the screen. the other is the blast an explosion item sends
 * out */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/helpers.h"
#include "draw/model.h"
#include "effect/snow.h"
#include "main.h"
#include "object/item_box.h"
#include "object/item_box_air.h"
#include "object/models.h"
#include "object/placement.h"
#include "player/lockon.h"
#include "player/player.h"
#include "stage/stage.h"
#include "system/task.h"
#include "system/texlists.h"
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
void njGetkmPointer_jp(void);
void njSetkmPointer_jp(void);
void njSetEORflag_jp();
void *njStartVertexNonTexOpaque_jp(void);
void *njStartVertexTexOpaque_jp(void);
void *njStartVertexNonTexTransIntens_jp(Uint32 *color);
void *njStartVertexTexOpaqueIntens_jp(Uint32 *color);
void njEndVertex_jp(Uint32 *vertex);
Sint32 njSetkmTextureNum_jp(Uint32 n);
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
void FUN_8c05e038(enum item_kind kind);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void FUN_8c091a9e(struct task *task);
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
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
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
void *syMalloc_default_malloc(size_t size);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
void OffConstantAttr(Uint32 and_attr, Uint32 or_attr);
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* the box's work->mode */
#define GROW_STEP 0.05F
#define BURST_STEP 0.2F
#define BURST_SCALE 5.0F
#define SHOWN_COUNT 20
#define SHOWN_STEPS 60
#define SHOWN_SPACING 80.0F
#define SHOWN_START_X (-60.0F)
#define SHOWN_SLIDE 30.0F
#define SHOWN_SCALE 2.0F
#define SHOWN_GROW 0.2F
#define BLAST_START 10.0F
#define BLAST_GROWTH 10.0F
#define BLAST_MOST 500.0F
#define NO_BLAST (-1.0F)
#define EXTRA(task) ((struct item_box_air_extra *)(task)->extra)
enum box_mode {
    BOX_INIT, /* starts the box */
    BOX_WAIT, /* grows in, then waits for a player's or an attack's touch */
    BOX_BURST, /* bursts, swelling to BURST_SCALE */
    BOX_DRAW, /* draws, and nothing more */
    BOX_KILL /* kills the task */
};

/* a waiting box's scale grows GROW_STEP a step, to 1. a bursting box's
 * scale swells BURST_STEP a step, and the box goes once it reaches
 * BURST_SCALE */

/* the state of the row of collected items on show */
enum shown_state {
    SHOWN_NONE, /* none on show */
    SHOWN_ENTER, /* they slide in from the left to their places */
    SHOWN_HOLD, /* they hold */
    SHOWN_LEAVE /* they shrink away */
};

/* the items the row has room for */
/* a holding row counts its steps in shown.timer. the step that takes the
 * count past SHOWN_STEPS starts the row shrinking away, over SHOWN_STEPS
 * steps */
/* the row's items stand SHOWN_SPACING apart */
/* an item comes on show at SHOWN_START_X, off the screen's left, and
 * slides SHOWN_SLIDE a step to its place. it comes at scale SHOWN_SCALE,
 * and an item that has shrunk grows back SHOWN_GROW a step to it */

/* a blast's radius starts at BLAST_START and grows BLAST_GROWTH a step.
 * past BLAST_MOST, the blast ends, and the radius is NO_BLAST */

/* the box's record. its task's extra points to it */
struct item_box_air {
    Uint8 unk_00[4];
    enum item_kind kind; /* the item, which the step copies from scl.x */
    Uint8 unk_08[12];
    Angle panel_ang; /* the turn of the item's panel about y */
    Float burst; /* the box's scale as it bursts, from 1 to BURST_SCALE */
    Float grow; /* its scale as it grows in, from 0 to 1 */
};

/* the box's task's extra: its record, or NULL */
struct item_box_air_extra {
    struct item_box_air *box;
};

/* a collected item on show */
struct shown_item {
    enum item_kind kind;
    Float x; /* its x on the screen */
    Float scale;
    Sint32 rings; /* item_rings_given as the item was collected */
};

/* the row of collected items on show */
struct shown_items {
    enum shown_state state;
    Sint32 count;
    /* while the row holds, the steps it has held. while it shrinks, the
     * steps left */
    Uint32 timer;
    struct shown_item items[SHOWN_COUNT];
};
void FUN_8c05db4c(struct task *task);
void itembox_airDisplay(struct task *task);
struct item_box_air *item_box_air_alloc(void);
void itembox_airCollisitonBefore(struct task *task);
void item_box_air_burst(struct task *task);
void itemBoxManager(struct task *task);
void manager_Move(void);
void shown_hold(void);
void shown_leave(void);
void manager_Disp(struct task *task);
void DrawItemBoxSprite(enum item_kind kind, Float x, int rings, Float scale);

static void shown_destroy(struct task *task);
void item_explosion_step(struct task *task);
void itemDisp_itembox(struct task *task);
void sphereDraw(NJS_OBJECT *object);
void item_box_air_panel_draw(NJS_OBJECT *object);
extern const NJS_VECTOR item_box_air_puff_speed;
extern struct collision_shape item_box_air_shape;
extern struct draw_override item_box_air_overrides[];
extern struct draw_override item_box_air_burst_overrides[];
extern NJS_TEXANIM shown_face;
extern NJS_TEXANIM shown_rings;
extern char *item_names[ITEM_COUNT];
extern Sint32 item_rings_given;
extern struct item_box_air *itembox_air_data;
extern NJS_POINT3 item_explosion_pos;
extern Float item_explosion_radius;
extern struct shown_items manager_data;

void PutItem_ItemBoxAir(NJS_POINT3 *pos, enum item_kind kind)
{
    struct task *task = CreateElementalTask(
        TASK_MOTION | TASK_WORK | TASK_FORCE | TASK_EXTRA, 3, ObjectItemboxAir);
    struct task_work *work = task->work;

    work->pos = *pos;
    work->scl.x = (Float)kind;
}

void ObjectItemboxAir(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    itembox_air_data = EXTRA(task)->box;
    if (itembox_air_data != NULL) {
        if ((int)work->scl.x < 0) {
            work->scl.x = ITEM_COUNT - 1;
        } else if ((int)work->scl.x >= ITEM_COUNT) {
            work->scl.x = 0.0F;
        }
        if (work->mode != BOX_INIT) {
            /* @hack type: the kind converted through a Uint32, which keeps
             * the image's test against 2147483648.0F ahead of the FTRC
             * (FCMP/GT at 0x8c060cb4, FTRC at 0x8c060cbe). as an enum
             * item_kind, the test goes, the object's code runs 64 bytes
             * short, and 174 of the step's 211 words differ */
            itembox_air_data->kind = (Uint32)work->scl.x;
        }
    }
    if (OnEdit(task)) {
        if (work->mode == BOX_INIT) {
            work->mode++;
            EXTRA(task)->box = item_box_air_alloc();
            task->destructor = FUN_8c05db4c;
            task->draw = itembox_airDisplay;
        }
        itembox_air_data = ((struct item_box_air_extra *)(task)->extra)->box;
        itembox_airDisplay(task);
        itemDisp_itembox(task);
    } else {
        switch (work->mode) {
        case BOX_INIT:
            work->mode = BOX_WAIT;
            EXTRA(task)->box = item_box_air_alloc();
            /* a lockon_target for E-102 to lock on to, in place of the
             * task's motion record */
            if (task->motion != NULL) {
                Free(task->motion);
            }
            task->motion = CAlloc(1, sizeof(struct lockon_target));
            itembox_air_data = EXTRA(task)->box;
            task->destructor = FUN_8c05db4c;
            task->draw = itembox_airDisplay;
            CCL_Init(task, &item_box_air_shape, COLLISION_ITEM, 1, 1);
            itembox_air_data->burst = 1.0F;
            if (!((GetStageNumber() & 0xff00) == (((35)) << 8 | (0)))) {
                if (task->placement != ((void *)0)) {
                    FUN_8c091a9e(task);
                } else {
                }
            }
            return;
        case BOX_WAIT:
            itembox_airDisplay(task);
            itembox_airCollisitonBefore(task);
            itembox_air_data->panel_ang += NJM_DEG_ANG(3);
            return;
        case BOX_BURST:
            itembox_airDisplay(task);
            item_box_air_burst(task);
            return;
        case BOX_DRAW:
            itembox_airDisplay(task);
            return;
        /* @hack redundant: a case label nothing needs, which keeps the image's
         * CMP/EQ #4,R0 and its branch (0x8c060d1a). left to the default,
         * the compare goes, the object's code runs 32 bytes short, and 126
         * of 211 words differ */
        case BOX_KILL:
            break;
        default:
            break;
        }
        if (task->placement != NULL) {
            DeadOut(task);
        } else {
            FreeTask(task);
        }
    }
}

void FUN_8c05db4c(struct task *task)
{
    if (EXTRA(task)->box != NULL) {
        Free(EXTRA(task)->box);
        EXTRA(task)->box = NULL;
    }
}

/* draw the box in view: at its grow scale while it starts and waits, and
 * otherwise at its burst scale, fading */
void itembox_airDisplay(struct task *task)
{
    struct task_work *work = task->work;

    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    itembox_air_data = EXTRA(task)->box;
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    SetRegularTexture();
    if (work->mode == BOX_WAIT || work->mode == BOX_INIT) {
        njScale(NULL, itembox_air_data->grow, itembox_air_data->grow,
                itembox_air_data->grow);
        draw_object(&item_box_air_object, item_box_air_overrides);
    } else {
        njScale(NULL, itembox_air_data->burst, itembox_air_data->burst,
                itembox_air_data->burst);
        SaveConstantAttr();
        OnConstantAttr(0, NJD_FLAG_USE_ALPHA);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_INVSRCALPHA);
        SetMaterial((1.0F - itembox_air_data->burst) * 0.25F, 0.0F, 0.0F, 0.0F);
        draw_object(&item_box_air_object, item_box_air_burst_overrides);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
        LoadConstantAttr();
    }
    late_DrawObjectClipEx(1);
}

/* a record from the heap, zeroed, or NULL when the heap has no room */
struct item_box_air *item_box_air_alloc(void)
{
    struct item_box_air *box;
    Uint8 *p;
    Uint8 *end;
    struct item_box_air *r;

    /* @hack redundant: the new record tested to no effect, which keeps the
     * image's TST R0,R0 at 0x8c061060. without it, the function runs 2
     * bytes short and 17 of its 23 words differ */
    if ((box = MAlloc(sizeof(*box))) != NULL) {
    }
    /* NOLINTNEXTLINE(clang-diagnostic-sign-compare) */
    r = box;
    p = (Uint8 *)r;
    end = p + sizeof(*r);
    while (p < end) {
        *p++ = 0;
        *p++ = 0;
    }
    return box;
}

/* draw the box's lower part, darkened as the box bursts */
void sphereDraw(NJS_OBJECT *object)
{
    NJS_ARGB color;

    SaveControl3D();
    njControl3D(NJD_CONTROL_3D_OFFSET_MATERIAL);
    color.r = color.g = color.b = (1.0F - itembox_air_data->burst) * 0.25F;
    njSetConstantMaterial(&color);
    late_DrawObjectClip(object);
    LoadControl3D();
}

/* draw the panel with the face of the box's item, turned panel_ang about
 * y */
void item_box_air_panel_draw(NJS_OBJECT *object)
{
    item_kinds[ITEM_1UP].texture = item_1up_textures[GetPlayerNumber()];
    object->model->mats->attr_texId =
        item_kinds[itembox_air_data->kind].texture;
    njTranslateV(NULL, (NJS_VECTOR *)object->pos);
    TURN(njRotateZ, object->ang[2]);
    TURN(njRotateX, object->ang[0]);
    TURN(njRotateY, itembox_air_data->panel_ang);
    ds_DrawModelClip(object->model);
}

/* grow the box in. once it has grown, a player's or an attack's touch
 * bursts it. the item is given when player 0 burst the box. in E-102's
 * game, or with Tails as player 0 and player 1 not Sonic, it is given
 * whatever burst the box */
void itembox_airCollisitonBefore(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 pos;

    itembox_air_data->grow += GROW_STEP;
    if (itembox_air_data->grow > 1.0F) {
        itembox_air_data->grow = 1.0F;
        if ((work->collision->flags & COLLISION_HIT) &&
            (work->collision->hit->kind == COLLISION_PLAYER ||
             work->collision->hit->kind == COLLISION_ATTACK)) {
            work->mode = BOX_BURST;
            pos = work->pos;
            pos.y += 15.0F;
            snow_create(&pos, &item_box_air_puff_speed, 1.2F);
            if (item_kinds[itembox_air_data->kind].give != NULL &&
                (work->collision->hit->owner == GetPlayerTaskPointer(0) ||
                 GetPlayerNumber() == 6 || GetPlayerNumber() == 7 ||
                 GetPlayerNumber() == 0 ||
                 (GetPlayerCharacterName(1) == 2 &&
                  GetPlayerCharacterName(0) == 0) ||
                 (GetPlayerCharacterName(0) == 2 &&
                  GetPlayerCharacterName(1) != 0))) {
                item_kinds[itembox_air_data->kind].give(work);
                FUN_8c05e038(itembox_air_data->kind);
            }
            E102KillCursor(task);
            collision_free(work);
            /* @bug memory: the burst's shape reads 36 bytes past
             * item_box_air_overrides' end. collision_init takes that table of
             * draw overrides as the burst's one shape (MOV.L at 0x8c061298),
             * and the shape's 52 bytes are the table's 16 and the 36 after
             * it */
#ifdef GCC
            /* repairs the read the tag names: GCC's burst takes a shape that
             * touches nothing. the image's touches nothing either: its kind
             * is the low four bits of item_box_air_panel's address, 0xc,
             * which no check takes */
            CCL_Init(task, &item_box_air_burst_shape, COLLISION_OBJECT, 1, 1);
#else
            CCL_Init(task, (struct collision_shape *)item_box_air_overrides,
                     COLLISION_OBJECT, 1, 1);
#endif
        } else {
            EntryColliList(work);
        }
    }
}

void item_box_air_burst(struct task *task)
{
    itembox_air_data->burst += BURST_STEP;
    if (itembox_air_data->burst >= BURST_SCALE) {
        itembox_air_data->burst = BURST_SCALE;
        task->work->mode = BOX_KILL;
    }
}

void InitItemBoxManager(void)
{
    struct task *task = CreateElementalTask(0x2, 3, itemBoxManager);
    task->draw = manager_Disp;
    task->destructor = shown_destroy;
    manager_data.count = 0;
    manager_data.state = SHOWN_NONE;
    item_explosion_radius = NO_BLAST;
}

void FUN_8c05e038(enum item_kind kind)
{
    /* @bug memory: shown.count goes untested against SHOWN_COUNT
     * (MOV.L R4,@R3 at 0x8c06132a). a 21st item on show writes past
     * shown.items, into the bss after it */
#ifdef GCC
    /* repairs the stores the tag names, which in a stage with panels
     * overwrite their live tasks. GCC's row takes no item past its last, but
     * enters again, as the image's does on each item */
    if (manager_data.count >= SHOWN_COUNT) {
        manager_data.state = SHOWN_ENTER;
        return;
    }
#endif
    manager_data.items[manager_data.count].kind = kind;
    manager_data.items[manager_data.count].x = SHOWN_START_X;
    manager_data.items[manager_data.count].scale = SHOWN_SCALE;
    manager_data.items[manager_data.count].rings = item_rings_given;
    manager_data.count++;
    manager_data.state = SHOWN_ENTER;
}

/* the step of item_reset's task: move the row on show and draw it, and grow
 * the blast. the row also draws as the task's draw */
void itemBoxManager(struct task *task)
{
    switch (manager_data.state) {
    case SHOWN_NONE:
        break;
    case SHOWN_ENTER:
        manager_Move();
        manager_Disp(task);
        break;
    case SHOWN_HOLD:
        shown_hold();
        manager_Disp(task);
        break;
    case SHOWN_LEAVE:
        shown_leave();
        manager_Disp(task);
        break;
    }
    item_explosion_step(task);
}

/* slide each item in from the left to its place in the row, which is
 * centered on the screen. the row holds once every item is in place */
void manager_Move(void)
{
    int i;
    int done = 0;
    Float place;

    for (i = 0; i < manager_data.count; i++) {
        manager_data.items[i].x += SHOWN_SLIDE;
        place = ((manager_data.count - 1) * (SHOWN_SPACING / 2)) -
                (i * SHOWN_SPACING) + SCREEN_MIDDLE_X;
        if (manager_data.items[i].x >= place) {
            manager_data.items[i].x = place;
            done++;
        }
        manager_data.items[i].scale += SHOWN_GROW;
        if (manager_data.items[i].scale > SHOWN_SCALE) {
            manager_data.items[i].scale = SHOWN_SCALE;
        }
    }
    if (done == manager_data.count) {
        manager_data.state = SHOWN_HOLD;
        manager_data.timer = 0;
    }
}

void shown_hold(void)
{
    int i;

    for (i = 0; i < manager_data.count; i++) {
        manager_data.items[i].scale += SHOWN_GROW;
        if (manager_data.items[i].scale > SHOWN_SCALE) {
            manager_data.items[i].scale = SHOWN_SCALE;
        }
    }
    manager_data.timer++;
    if (manager_data.timer > SHOWN_STEPS) {
        manager_data.timer = SHOWN_STEPS;
        manager_data.state = SHOWN_LEAVE;
    }
}

void shown_leave(void)
{
    int i;

    for (i = 0; i < manager_data.count; i++) {
        manager_data.items[i].scale =
            manager_data.timer * (SHOWN_SCALE / SHOWN_STEPS);
    }
    manager_data.timer--;
    if (manager_data.timer == 0) {
        manager_data.count = 0;
        manager_data.state = SHOWN_NONE;
    }
}

void manager_Disp(struct task *task)
{
    int i;

    for (i = 0; i < manager_data.count; i++) {
        struct shown_item *item = &manager_data.items[i];

        DrawItemBoxSprite(item->kind, item->x, item->rings, item->scale);
    }
}
#pragma inline(set_rings_uv)
static void set_rings_uv(int u1, int v1, int u2, int v2)
{
    *(Sint16 *)((char *)&shown_rings + (4 * sizeof(Sint16))) = u1;
    *(Sint16 *)((char *)&shown_rings + (5 * sizeof(Sint16))) = v1;
    *(Sint16 *)((char *)&shown_rings + (6 * sizeof(Sint16))) = u2;
    *(Sint16 *)((char *)&shown_rings + (7 * sizeof(Sint16))) = v2;
}

/* draw the item's face at x, at scale, and on a random ring item the count
 * it gave. a count of 5 or 10 shows as ITEM_5RING's or ITEM_10RING's face,
 * with no count over it. a count other than 40, 20 or 15 shows as 1 */
void DrawItemBoxSprite(enum item_kind kind, Float x, int rings, Float scale)
{
    NJS_SPRITE sprite;
    NJS_SPRITE number;

    if (kind == ITEM_RANDOMRING) {
        switch (rings) {
        case 5:
            kind = ITEM_5RING;
            break;
        case 10:
            kind = ITEM_10RING;
            break;
        }
    }
    item_kinds[ITEM_1UP].texture = item_1up_textures[GetPlayerNumber()];
    shown_face.texid = item_kinds[kind].texture;
    sprite.tlist = &obj_regular_texlist;
    sprite.tanim = &shown_face;
    sprite.sx = scale;
    sprite.sy = scale;
    sprite.ang = 0;
    sprite.p.x = x;
    sprite.p.y = 370.0F;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    SetMaterial(1.0F, 1.0F, 1.0F, 1.0F);
    late_DrawSprite2D(&sprite, 0, -10.0F, NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
    if (kind == ITEM_RANDOMRING) {
        number.p.x = x - 1.0F;
        number.p.y = 372.0F;
        number.sx = scale;
        number.sy = scale;
        number.ang = 0;
        number.tlist = &obj_regular_texlist;
        number.tanim = &shown_rings;
        /* @hack spelling: a draw at the end of each case, which keeps
         * njDrawSprite2D's address in R12 (MOV.L at 0x8c0616c6) and the
         * stack frame at 100 bytes. with one draw after the switch, the
         * stack frame is 96 bytes and 111 of 175 words differ. the cases
         * stand in the order the image lays out their code */
        switch (rings) {
        case 40:
            set_rings_uv(0, 0, 127, 127);
            late_DrawSprite2D(&number, 0, -9.0F,
                              NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
            break;
        case 20:
            set_rings_uv(0, 128, 127, 255);
            late_DrawSprite2D(&number, 0, -9.0F,
                              NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
            break;
        case 15:
            set_rings_uv(128, 0, 255, 127);
            late_DrawSprite2D(&number, 0, -9.0F,
                              NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
            break;
        default:
            set_rings_uv(128, 128, 255, 255);
            late_DrawSprite2D(&number, 0, -9.0F,
                              NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
            break;
        }
    }
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

static void shown_destroy(struct task *task)
{
}

void item_explosion_start(NJS_POINT3 *pos)
{
    item_explosion_pos = *pos;
    item_explosion_radius = BLAST_START;
}

void item_explosion_step(struct task *task)
{
    if (item_explosion_radius >= 0.0F) {
        item_explosion_radius += BLAST_GROWTH;
        if (item_explosion_radius > BLAST_MOST) {
            item_explosion_radius = NO_BLAST;
        }
    }
}

Bool item_explosion_reaches(NJS_POINT3 *pos)
{
    NJS_VECTOR away;

    if (item_explosion_radius >= 0.0F) {
        away.x = pos->x - item_explosion_pos.x;
        away.y = pos->y - item_explosion_pos.y;
        away.z = pos->z - item_explosion_pos.z;
        if (item_explosion_radius > njScalor(&away)) {
            return TRUE;
        }
    }
    return FALSE;
}

void itemDisp_itembox(struct task *task)
{
    njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "-> ITEM NUMBER ");
    njPrintC(NJM_LOCATION(20, 20), item_names[(int)task->work->scl.x]);
}
