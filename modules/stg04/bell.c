/* @unit 0C903DC0-0C9041E0 +egflags +pool32 */
/* O HW BELL hanging bell that rings and scatters rings when struck */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "object/common.h"
#include "object/placement.h"
#include "object/ring.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stg04/bell.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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
void DeadOut(struct task *task);
void kmiLogFileOpen(void *data);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
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

#define BELL_RINGS 5
#define BELL_RINGS_DROP 70.0F
#define SWING_SPEED_LEAST 1.0F
#define SWING_SPEED_MOST 3.0F
#define SWING_STEP 0x400
#define SWING_FARTHEST 3094.0F
#define QUARTER_TURN NJM_DEG_ANG(90)
#define THREE_QUARTER_TURN NJM_DEG_ANG(270)
#define SE_BELL 93
#define BELL_STRUCK 0x100
#define BELL_SWINGING 0x200
#define RINGS_LEFT(work) ((work)->mode)
#define SWING_PHASE(work) ((work)->vars.l[0])
#define CLAPPER(work) ((struct clapper_vars *)&(work)->vars)
extern NJS_MODEL bell_model;
extern NJS_MODEL bell_clapper_model;

/* the bell's first strike scatters BELL_RINGS rings, and each later strike one
 * fewer. the rings scatter from BELL_RINGS_DROP below the bell's position */

/* player 0 swings the clapper only at a ground speed of SWING_SPEED_LEAST or
 * more. a speed past SWING_SPEED_MOST counts as that. a hit on the clapper
 * sets the swing's phase to a turn for each whole unit of speed */
/* the swing's phase falls by SWING_STEP a step, a turn in 64 steps. the
 * clapper tilts at most SWING_FARTHEST angle units, about 17 degrees */
/* a swing's ends lie where the phase within its turn is QUARTER_TURN or
 * THREE_QUARTER_TURN */

/* BELL_STRUCK and BELL_SWINGING are flags in the bell's work->flags.
 * BELL_STRUCK blocks another strike until the bell and the clapper are
 * untouched and still. BELL_SWINGING is set while the clapper swings */

/* the bell's work->mode counts the rings its next strike scatters. its
 * vars.l[0] holds the swing's phase, which falls to 0 */

/* the shares of the clapper's swing that tilt it about x and about z. a hit
 * that swings the clapper sets them to the sine and negated cosine of player
 * 0's heading. it reads player 0's heading whatever made the hit */
struct clapper_vars {
    Uint8 unk_00[4];
    Float x;
    Float z;
};
extern struct collision_shape bell_shapes[2];
extern struct collision_shape bell_clapper_shape[1];

void bell_destroy(struct task *task)
{
    FreeTaskC(task);
}

/* the clapper's step, which draws it in the bell's frame. a hit while the bell
 * isn't struck swings the clapper along player 0's heading. the bell rings at
 * each end of the swing. the clapper collides only while it doesn't swing and
 * the set editor doesn't hold it */
void cNormal(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *bell = task->parent->work;
    struct task_work *player = playertwp[0];
    Float speed;

    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    ds_DrawModelClip(&bell_clapper_model);
    if ((work->collision->flags & COLLISION_HIT) &&
        !(bell->flags & BELL_STRUCK)) {
        Angle heading;

        /* @bug uninitialized: player_ground_speed leaves speed unset for
         * player 0 off the ground, and its FALSE goes unread. the test below
         * then reads speed's frame slot unwritten (FMOV.S @R15,FR2 at
         * 0x0c9040d4) */
#ifdef GCC
        /* repairs the unset speed the tag names: 0, a still player's ground
         * speed, leaves the bell still */
        speed = 0.0F;
#endif
        player_ground_speed(0, &speed);
        if (speed < SWING_SPEED_LEAST) {
            return;
        }
        heading = (Uint16)player->ang.y;
        CLAPPER(work)->x = njSin(heading);
        CLAPPER(work)->z = -njCos(heading);
        if (speed > SWING_SPEED_MOST) {
            speed = SWING_SPEED_MOST;
        }
        SWING_PHASE(bell) = (int)speed << 16;
        bell->flags |= BELL_STRUCK | BELL_SWINGING;
    } else if (bell->flags & BELL_SWINGING) {
        Angle phase = SWING_PHASE(bell) & 0x3ff00;

        if (phase) {
            phase &= 0xff00;
            if (phase == THREE_QUARTER_TURN || phase == QUARTER_TURN) {
                dsPlay_oneshot_v(SE_BELL, 0, 0, 64, bell->pos.x, bell->pos.y,
                                 bell->pos.z);
            }
            SWING_PHASE(bell) -= SWING_STEP;
            work->ang.x = (Angle)(CLAPPER(work)->x * njSin(SWING_PHASE(bell)) *
                                  SWING_FARTHEST);
            work->ang.z = (Angle)(CLAPPER(work)->z * njSin(SWING_PHASE(bell)) *
                                  SWING_FARTHEST);
        } else {
            bell->flags &= ~BELL_SWINGING;
        }
    } else if (!OnEdit(task)) {
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
    }
}

/* the bell's step and draw, which steps the clapper in the bell's frame */
void bell_run(struct task *task)
{
    struct task_work *work = task->work;
    /* @bug memory: a bell whose first step ran while the set editor held it has
     * no clapper, and the clapper's work is read through the null child,
     * MOV.L @(32,R3),R2 at 0x0c904250 */
    struct task_work *clapper = task->child->work;

    if (CheckRangeOut(task)) {
        return;
    }
    SetMaterial(0.0F, work->scl.x, work->scl.y, work->scl.z);
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    njPushMatrix(NULL);
    TURN(njRotateY, work->ang.y);
    ds_DrawModelClip(&bell_model);
    late_DrawObjectClipEx(1);
    LoopTaskC(task);
    late_DrawObjectClipEx(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    /* a hit while the bell isn't struck rings it, and scatters RINGS_LEFT
     * rings while it has any. otherwise BELL_STRUCK clears once neither the
     * bell nor the clapper is hit and the swing is over */
    if ((work->collision->flags & COLLISION_HIT) &&
        !(work->flags & BELL_STRUCK)) {
        if (RINGS_LEFT(work)) {
            ring_scatter(work->pos.x, work->pos.y - BELL_RINGS_DROP,
                         work->pos.z, RINGS_LEFT(work)--);
        }
        dsPlay_oneshot(SE_BELL, 0, 0, 0);
        work->flags |= BELL_STRUCK;
    } else if ((work->flags & (BELL_STRUCK | BELL_SWINGING)) == BELL_STRUCK &&
               !(work->collision->flags & COLLISION_HIT) &&
               !(clapper->collision->flags & COLLISION_HIT) &&
               !SWING_PHASE(work)) {
        work->flags &= ~BELL_STRUCK;
    }
    if (!OnEdit(task)) {
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
    }
}

/* the bell hangs upright, and its clapper takes its heading. a bell that
 * starts while the set editor holds it has no clapper */
void ObjHighWayBell(struct task *task)
{
    struct task_work *work = task->work;
    struct task *clapper;
    struct task_work *clapper_work;

    work->ang.x = work->ang.z = 0;
    CCL_Init(task, bell_shapes, COLLISION_OBJECT, 1, 2);
    if (!OnEdit(task)) {
        clapper = CreateChildTask(TASK_MOTION | TASK_WORK | TASK_FORCE, cNormal,
                                  task);
        clapper_work = clapper->work;
        clapper_work->pos = work->pos;
        clapper_work->ang.x = clapper_work->ang.z = 0;
        clapper_work->ang.y = work->ang.y;
        CCL_Init(clapper, bell_clapper_shape, COLLISION_OBJECT, 1, 1);
    }
    work->flags &= ~(BELL_STRUCK | BELL_SWINGING);
    RINGS_LEFT(work) = BELL_RINGS;
    task->step = bell_run;
    task->draw = bell_run;
    task->destructor = bell_destroy;
}
