/* @unit 8C064DC0-8C065740 @ddata 8C1BA77C-8C1BA794 +egflags +pool32 */
/* the savepoint: a gate with two lamps. player 0's touch saves player 0's
 * place as the restart point */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/helpers.h"
#include "draw/model.h"
#include "effect/sparkle.h"
#include "hud/hud.h"
#include "object/models.h"
#include "object/placement.h"
#include "object/savepoint.h"
#include "player/player.h"
#include "player/target.h"
#include "sound/sound.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
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
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void FUN_8c091a9e(struct task *task);
void FUN_8c064df2(NJS_POINT3 *pos, struct angles *ang);
void FUN_8c064e36(NJS_POINT3 *pos, struct angles *ang);
void FUN_8c064e80(struct task *task);
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

/* the steps the saved time shows for after a touch */
#define SHOW_TIME 300
/* the saved time blinks for its first 120 steps: it hides through every
 * other run of BLINK_STEPS steps */
#define BLINK_STEPS 10

#define SE_TOUCH 10

/* the lamps' textures in the regular texture list, unlit and lit */
#define LAMP_UNLIT 59
#define LAMP_LIT 60

/* the lamps keep SPIN_KEPT of their spin about y each step. once the spin
 * falls below SWING_SPIN a step, they swing about x toward 0 */
#define SPIN_KEPT 0.995F
#define SWING_SPIN NJM_DEG_ANG(20)

/* where a player starts again, and the clock's time when it was saved */
#define VARS(work) ((struct savepoint_vars *)&(work)->vars)
#define EXTRA(task) ((struct savepoint_extra *)(task)->extra)
struct restart_point {
    Uint16 stage_act; /* the stage and act it was saved in */
    Uint8 minutes;
    Uint8 seconds;
    Uint8 frames;
    Bool saved;
    NJS_POINT3 pos;
    struct angles ang;
};

/* a savepoint's own record, reached through task->extra */
struct savepoint {
    Uint8 unk_00[4];
    struct angles ang; /* the lamps' turn: x tilts them and y spins them */
    struct angles speed; /* added to ang.x and ang.y each step */
    struct task *lamps[2]; /* child tasks whose works follow the lamps */
    /* the constant material's red, green and blue as a lamp draws. this
     * file leaves them at 0 */
    Float color[3];
    Sint32 timer; /* the steps left to show the saved time */
    Sint16 sparkles; /* the sparkles made above player 0 so far */
};

struct savepoint_extra {
    struct savepoint *savepoint;
};

/* a savepoint's bytes in work->vars */
struct savepoint_vars {
    NJS_OBJECT *object; /* the tree it draws, set by savepoint_draw */
};

/* @hack spelling: the record reached through task->extra at every use, which
 * the image reads again each time (MOV.L @(44,R14) at 0x8c06867a,
 * 0x8c06869a and 0x8c0686a6); held in a local in each function, 258 of 297
 * words differ */

/* a savepoint's modes, in work->mode */
enum savepoint_mode {
    SAVEPOINT_INIT,
    SAVEPOINT_WAIT, /* for player 0's touch */
    SAVEPOINT_SPIN, /* touched: the lamps spin, then turn to rest */
    SAVEPOINT_DONE, /* touched, with the lamps at rest */
    SAVEPOINT_DRAW, /* it only draws */
    SAVEPOINT_KILL
};

void savepoint_destroy(struct task *task);
void savepoint_draw(struct task *task);
struct savepoint *savepoint_alloc(void);
void FUN_8c0651aa(NJS_OBJECT *object);
void lamp_step(struct task *task);
void lamps_place(struct task_work *work);
void savepoint_touch(struct task *task, struct task_work *work);
void lamps_swing(struct task *task, struct task_work *work);
void savepoint_show_time(struct task *task, struct task_work *work);
Float savepoint_pass_speed(struct task *task, struct task_work *work);
extern struct collision_shape savepoint_shape;
/* clang-format on */

/* draw_object leaves the lamps to lamp_draw */
static struct draw_override lamp_overrides[] = {
    {savepoint_lamp_plus_x, FUN_8c0651aa},
    {savepoint_lamp_minus_x, FUN_8c0651aa},
    {NULL, NULL},
};
extern NJS_VECTOR lamp_pos[2];
extern struct hud_layout time_layout;
extern struct savepoint *savepoint_current;
extern struct restart_point restart_point;

void restart_clear(void)
{
    Uint8 *byte;
    int i;

    byte = (Uint8 *)&restart_point;
    for (i = sizeof(restart_point); i != 0; i--) {
        *byte++ = 0;
    }
}

Bool restart_keep_this_act(void)
{
    if (GetStageNumber() != restart_point.stage_act) {
        restart_clear();
    }
    return restart_point.saved;
}

void FUN_8c064df2(NJS_POINT3 *pos, struct angles *ang)
{
    *pos = restart_point.pos;
    *ang = restart_point.ang;
    time_set(restart_point.minutes, restart_point.seconds,
             restart_point.frames);
    ring_add(-ring_count());
    player_grant_invincibility(0);
}

void FUN_8c064e36(NJS_POINT3 *pos, struct angles *ang)
{
    time_get(&restart_point.minutes, &restart_point.seconds,
             &restart_point.frames);
    restart_point.pos = *pos;
    restart_point.ang = *ang;
    restart_point.saved = TRUE;
    restart_point.stage_act = GetStageNumber();
}

void FUN_8c064e80(struct task *task)
{
    struct task_work *work;

    work = task->work;
    if (CheckRangeOut(task)) {
        return;
    }
    savepoint_current = EXTRA(task)->savepoint;
    /* in the set editor's hands it only draws */
    if (OnEdit(task)) {
        if (work->mode == SAVEPOINT_INIT) {
            work->mode++;
            EXTRA(task)->savepoint = savepoint_alloc();
            task->destructor = savepoint_destroy;
            task->draw = savepoint_draw;
        }
        savepoint_current = EXTRA(task)->savepoint;
        savepoint_draw(task);
    } else {
        switch (work->mode) {
        case SAVEPOINT_INIT:
            work->mode = SAVEPOINT_WAIT;
            EXTRA(task)->savepoint = savepoint_alloc();
            savepoint_current = EXTRA(task)->savepoint;
            task->destructor = savepoint_destroy;
            task->draw = savepoint_draw;
            savepoint_current->lamps[0] =
                CreateChildTask(TASK_WORK, lamp_step, task);
            savepoint_current->lamps[1] =
                CreateChildTask(TASK_WORK, lamp_step, task);
            CCL_Init(task, &savepoint_shape, COLLISION_OBJECT, 1, 1);
            lamps_place(work);
            savepoint_current->ang.x = ((Angle)(((90) * 65536.0) / 360.0));
            savepoint_current->ang.y = ((Angle)(((-90) * 65536.0) / 360.0));
            if (task->placement != ((void *)0)) {
                FUN_8c091a9e(task);
            }
            /* an earlier task of this placement was touched, so this one
             * starts lit with its lamps at rest */
            if (placement_used(task)) {
                savepoint_current->ang.x = 0;
                work->mode = SAVEPOINT_DONE;
            }
            break;
        case SAVEPOINT_WAIT:
            savepoint_draw(task);
            savepoint_touch(task, work);
            break;
        case SAVEPOINT_SPIN:
            savepoint_draw(task);
            savepoint_touch(task, work);
            lamps_swing(task, work);
            savepoint_show_time(task, work);
            break;
        case SAVEPOINT_DONE:
            savepoint_draw(task);
            savepoint_touch(task, work);
            savepoint_show_time(task, work);
            break;
        case SAVEPOINT_DRAW:
            savepoint_draw(task);
            break;
        /* @hack redundant: case SAVEPOINT_KILL, which shares the default's
         * code, keeps the image's CMP/EQ #5 at 0x8c0686e0; without it, 6 of 186
         * words differ */
        case SAVEPOINT_KILL:
        default:
            DeadOut(task);
            break;
        }
    }
}

void savepoint_destroy(struct task *task)
{
    if (EXTRA(task)->savepoint != NULL) {
        Free(EXTRA(task)->savepoint);
        EXTRA(task)->savepoint = NULL;
    }
}

void savepoint_draw(struct task *task)
{
    struct task_work *work;

    work = task->work;
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    savepoint_current = EXTRA(task)->savepoint;
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    SetRegularTexture();
    if (work->mode != SAVEPOINT_WAIT) {
        savepoint_lamp_plus_x->model->mats->attr_texId = LAMP_LIT;
        savepoint_lamp_minus_x->model->mats->attr_texId = LAMP_LIT;
    } else {
        savepoint_lamp_plus_x->model->mats->attr_texId = LAMP_UNLIT;
        savepoint_lamp_minus_x->model->mats->attr_texId = LAMP_UNLIT;
    }
    VARS(work)->object = &savepoint_gate;
    draw_object(&savepoint_gate, lamp_overrides);
    late_DrawObjectClipEx(1);
}
struct savepoint *savepoint_alloc(void)
{
    struct savepoint *savepoint;
    Uint8 *p;
    Uint8 *end;
    struct savepoint *r;
    if ((savepoint = MAlloc(sizeof(*savepoint))) != ((void *)0)) {
    }
    r = savepoint;
    p = (Uint8 *)r;
    end = p + sizeof(*r);
    while (p < end) {
        *p++ = 0;
        *p++ = 0;
    }
    return savepoint;
}

/* draw a lamp turned by the record's angles, the two lamps spinning
 * opposite ways about y. the record's color is its constant material */
void FUN_8c0651aa(NJS_OBJECT *object)
{
    SetMaterial(1.0F, savepoint_current->color[0], savepoint_current->color[1],
                savepoint_current->color[2]);
    njTranslateV(NULL, (NJS_VECTOR *)object->pos);
    if (object == savepoint_lamp_plus_x) {
        TURN(njRotateY, savepoint_current->ang.y);
        TURN(njRotateX, savepoint_current->ang.x);
    } else {
        TURN(njRotateY, -savepoint_current->ang.y);
        TURN(njRotateX, savepoint_current->ang.x);
    }
    ds_DrawModelClip(object->model);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

/* a lamp's task does nothing itself: savepoint_touch turns its work */
void lamp_step(struct task *task)
{
}

/* move each lamp's task, which starts at the gate's pos, to its lamp's
 * place on the turned gate */
void lamps_place(struct task_work *work)
{
    NJS_VECTOR offset[2];
    NJS_MATRIX matrix;

    njUnitMatrix(&matrix);
    TURN_MATRIX(njRotateZ, &matrix, work->ang.z);
    TURN_MATRIX(njRotateX, &matrix, work->ang.x);
    TURN_MATRIX(njRotateY, &matrix, work->ang.y);
    njCalcVector(&matrix, &lamp_pos[0], &offset[0]);
    njCalcVector(&matrix, &lamp_pos[1], &offset[1]);
    savepoint_current->lamps[0]->work->pos.x += offset[0].x;
    savepoint_current->lamps[0]->work->pos.y += offset[0].y;
    savepoint_current->lamps[0]->work->pos.z += offset[0].z;
    savepoint_current->lamps[1]->work->pos.x += offset[1].x;
    savepoint_current->lamps[1]->work->pos.y += offset[1].y;
    savepoint_current->lamps[1]->work->pos.z += offset[1].z;
}

/* turn the lamps' tasks as the lamps turn. in SAVEPOINT_WAIT, a touch by
 * player 0 saves player 0's place as the restart point and starts the
 * spin */
void savepoint_touch(struct task *task, struct task_work *work)
{
    savepoint_current->lamps[0]->work->ang.x =
        savepoint_current->ang.x + work->ang.x;
    savepoint_current->lamps[0]->work->ang.y =
        -savepoint_current->ang.y + work->ang.y;
    savepoint_current->lamps[0]->work->ang.z =
        savepoint_current->ang.z + work->ang.z;
    savepoint_current->lamps[1]->work->ang.x =
        savepoint_current->ang.x + work->ang.x;
    savepoint_current->lamps[1]->work->ang.y =
        savepoint_current->ang.y + work->ang.y;
    savepoint_current->lamps[1]->work->ang.z =
        savepoint_current->ang.z + work->ang.z;
    if (work->mode == SAVEPOINT_WAIT) {
        if ((work->collision->flags & COLLISION_HIT) &&
            work->collision->hit->owner == GetPlayerTaskPointer(0)) {
            work->mode = SAVEPOINT_SPIN;
            /* ten degrees a step for each unit of player 0's speed */
            savepoint_current->speed.y = savepoint_pass_speed(task, work) *
                                         (10.0F * (65536.0F / 360.0F));
            savepoint_current->timer = 300;
            FUN_8c064e36(&playertwp[0]->pos, &playertwp[0]->ang);
            placement_set_used(task);
            dsPlay_oneshot(SE_TOUCH, 0, 0, 0);
        }
    }
    EntryColliList(work);
}

/* the lamps spin about y, slowing, then swing about x toward 0, faster as
 * the spin dies. SAVEPOINT_DONE follows once both speeds reach 0. each of
 * the first three steps leaves a sparkle above player 0 */
void lamps_swing(struct task *task, struct task_work *work)
{
    /* Sint16 copies of the record's ang and speed, x and y */
    /* @hack type: each array's z, which nothing reads, gives the image's
     * 44 bytes of locals (ADD #-44,R15 at 0x8c068cea); as arrays of two, 3
     * of 155 words differ */
    Sint16 speed[3];
    Sint16 ang[3];
    NJS_VECTOR velocity;
    NJS_POINT3 pos;
    Sint16 from;
    Sint16 spin;
    Sint16 push;

    ang[0] = savepoint_current->ang.x;
    ang[1] = savepoint_current->ang.y;
    speed[0] = savepoint_current->speed.x;
    speed[1] = savepoint_current->speed.y;
    ang[0] += speed[0];
    ang[1] += speed[1];
    speed[1] = speed[1] * SPIN_KEPT;
    spin = njAbs(speed[1]);
    if (spin < SWING_SPIN) {
        if (ang[0] > NJM_DEG_ANG(45)) {
            from = NJM_DEG_ANG(101) - ang[0];
        } else {
            from = ang[0];
        }
        /* @hack spelling: the push through a local, which puts its NEG in R4
         * (NEG R3,R4 at 0x8c068d7e); stored straight to speed[0], the NEG
         * stays in R3 and 2 of 155 words differ */
        push = -(int)((SWING_SPIN - spin) * (Float)from * (1.0F / 81920.0F));
        speed[0] = push;
    }
    savepoint_current->ang.x = ang[0];
    savepoint_current->ang.y = ang[1];
    savepoint_current->speed.x = speed[0];
    savepoint_current->speed.y = speed[1];
    if (speed[0] == 0 && speed[1] == 0) {
        work->mode = SAVEPOINT_DONE;
    } else if (savepoint_current->sparkles < 3) {
        velocity.x = 0.0F;
        velocity.y = -0.3F;
        velocity.z = 0.0F;
        pos = playertwp[0]->pos;
        pos.y += 4.0F;
        sparkle_create(&pos, &velocity, 0.1F, NJM_DEG_ANG(5));
        savepoint_current->sparkles++;
    }
}

/* count the timer down, drawing the saved time while it runs */
void savepoint_show_time(struct task *task, struct task_work *work)
{
    if (savepoint_current->timer > 0) {
        savepoint_current->timer--;
        switch ((SHOW_TIME - savepoint_current->timer) / BLINK_STEPS) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
        case 11:
            break;
        default:
#ifdef GCC
            /* the port's 16:9 squeezes the time about the screen's right
             * edge */
            port_wide_anchor = WIDE_RIGHT;
#endif
            hud_draw_time(&time_layout, restart_point.minutes,
                          restart_point.seconds);
#ifdef GCC
            port_wide_anchor = WIDE_MIDDLE;
#endif
            break;
        }
    }
}

/* player 0's speed, negative when player 0 passes through the gate
 * backward */
Float savepoint_pass_speed(struct task *task, struct task_work *work)
{
    Float speed;
    Angle difference;

    speed = njScalor(&GetPlayerWorkPointer(0)->speed);
    difference =
        angle_difference(NJM_DEG_ANG(90) - playertwp[0]->ang.y, work->ang.y);
    if ((int)njAbs(difference) > NJM_DEG_ANG(90)) {
        return -speed;
    }
    return speed;
}
