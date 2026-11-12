/* @unit 0C904480-0C904840 @data 0CAA3440-0CAA3468 +egflags +pool32 */
/* O HAGURUMA5: O HAGURUMA4 half as big again across its face. it turns
 * about z, the other way while its switch is on. it carries player 0 round
 * with it */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/world.h"
#include "debug/editor.h"
#include "debug/print.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "object/switch.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stg12/gear_5.h"
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
void ObjectSwitch(struct task *task);
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
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
void FUN_0c904480(struct task *task);
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

#define RANGE (1000.0F * 1000.0F)
#define GEAR_FLAGS (WORLD_LARGE | WORLD_MOVES | WORLD_GRIP_HIGH)
#define SCALE 1.5F
#define NEAR 148.0F
#define SE_GEAR 321
#define VARS(work) ((struct gear_5_vars *)&(work)->vars)
#define FORCE(task) ((struct task_force *)(task)->force)
#define TURN_STEP(work) ((work)->scl.x)
extern NJS_OBJECT gear_4_object;
extern NJS_OBJECT gear_4_world_object;

/* destroyed beyond 1000 units of the camera and player 0 */

/* the gear draws and collides with gear_4's models, SCALE times their
 * size across the face */

/* the collision world tests the gear only while player 0 or 1 is within
 * NEAR of it */

enum gear_5_mode { GEAR_INIT, GEAR_RUN };

struct gear_5_vars {
    Uint8 switch_id;
    Uint8 unk_01[7];
    NJS_OBJECT *world;
};

/* the angle the gear turns each step */

void gear_5_init(struct task *task);
void gear_5_turn(struct task *task);
void gear_5_draw(struct task *task);
void gear_5_destroy(struct task *task);

void FUN_0c904480(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (!OnEdit(task)) {
        switch (work->mode) {
        case GEAR_INIT:
            gear_5_init(task);
            break;
        case GEAR_RUN:
            gear_5_draw(task);
            gear_5_turn(task);
            dsPlay_Dolby_time(SE_GEAR, (int)task, 1, 0, work->pos.x,
                              work->pos.y, work->pos.z, 2);
            break;
        /* @hack redundant: an empty default, which leaves the pop of
         * sound_play_at_for's stack argument, ADD #4,R15 at 0x0c9045f8,
         * ahead of the BRA rather than in its delay slot; without it, 3 of 93
         * words differ */
        default:;
        }
    } else {
        switch (work->mode) {
        case GEAR_INIT:
            gear_5_init(task);
            break;
        case GEAR_RUN:
            debug_print(EDITOR_LABEL(EDITOR_ROW_ANG_X), "-> No Use");
            debug_print(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "-> No Use");
            debug_print(EDITOR_LABEL(EDITOR_ROW_ANG_Z), "-> No Use");
            debug_print(EDITOR_LABEL(EDITOR_ROW_SCL_X), "-> ROTSPEED");
            debug_print(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "-> SWITCH ID");
            gear_5_draw(task);
            gear_5_turn(task);
            break;
        }
    }
}

void gear_5_init(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *world;

    task->draw = gear_5_draw;
    task->destructor = gear_5_destroy;
    VARS(work)->world = world = GetMobileLandObject();
    world->evalflags = gear_4_world_object.evalflags;
    world->scl[0] = SCALE;
    world->scl[1] = SCALE;
    world->scl[2] = 1.0F;
    world->ang[0] = 0;
    world->ang[1] = 0;
    world->ang[2] = 0;
    world->pos[0] = work->pos.x + gear_4_world_object.pos[0];
    world->pos[1] = work->pos.y + gear_4_world_object.pos[1];
    world->pos[2] = work->pos.z + gear_4_world_object.pos[2];
    world->model = gear_4_world_object.model;
    world->child = NULL;
    world->sibling = NULL;
    RegisterCollisionEntry(GEAR_FLAGS, task, world);
    work->ang.x = 0;
    work->ang.y = 0;
    work->ang.z = 0;
    VARS(work)->switch_id = work->scl.y;
    work->mode = GEAR_RUN;
}

/* turn the gear a step, the other way while its switch is on. the gear's
 * force carries player 0 through the same turn about the gear's axis */
void gear_5_turn(struct task *task)
{
    struct task_work *work = task->work;
    int turn;
    NJS_OBJECT *world;
    NJS_POINT3 offset;
    NJS_POINT3 moved;

    if (player_in_range(&work->pos, NEAR)) {
        work->flags |= WORLD_TESTED;
    } else {
        work->flags &= ~WORLD_TESTED;
    }
    if (!switch_is_on(VARS(work)->switch_id)) {
        turn = (int)TURN_STEP(work);
    } else {
        turn = -(int)TURN_STEP(work);
    }
    work->ang.z += turn;
    world = VARS(work)->world;
    world->ang[0] = 0;
    world->ang[1] = 0;
    world->ang[2] = work->ang.z;
    world->pos[0] = work->pos.x + gear_4_world_object.pos[0];
    world->pos[1] = work->pos.y + gear_4_world_object.pos[1];
    world->pos[2] = work->pos.z + gear_4_world_object.pos[2];
    offset.x = playertwp[0]->pos.x - work->pos.x;
    offset.y = playertwp[0]->pos.y - work->pos.y;
    offset.z = 0.0F;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, turn);
    njCalcVector(NULL, &offset, &moved);
    late_DrawObjectClipEx(1);
    njSubVector(&moved, &offset);
    FORCE(task)->speed = moved;
}

void gear_5_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count == 0) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        njScale(NULL, SCALE, SCALE, 1.0F);
        TURN_VIA(njRotateZ, work->ang.z, ang);
        late_DrawObject(&gear_4_object);
        late_DrawObjectClipEx(1);
    }
}

void gear_5_destroy(struct task *task)
{
    struct task_work *work = task->work;

    WithdrawCollisionEntry(task, VARS(work)->world);
    ReleaseMobileLandObject(VARS(work)->world);
}
