/* @unit 0C90B880-0C90BBA0 @data 0CA14F58-0CA14F74 +r04 +egflags +pool32 */
/* O BALL ball that bounces away once a player comes near */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg02/ball.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define VARS(work) ((struct ball_vars *)&(work)->vars)
#define EXTRA(task) ((struct ball_extra *)(task)->extra)
#define BALL_REACH 70.0F
#define FALL_STEPS 100
#define BOUNCE_SPEED 0.21F
#define BOUNCE_GRAVITY 0.01F
extern NJS_MODEL windy_ball_model;

/* the ball's move a step, in work->vars */
struct ball_vars {
    Float speed_y;
    Float speed_x;
    Float speed_z;
};

struct ball_extra {
    /* the speed across is BOUNCE_SPEED plus this times the timer. it grows by
     * 0.0002 a landing */
    Float accel;
    Float bounces; /* the landings so far, plus 1 */
    Float roll; /* added to the timer to give the ball's turn, in degrees */
    Float growth; /* grows by 0.22 a landing, and nothing reads it */
};

enum ball_mode {
    BALL_START = 0,
    BALL_WAIT = 1,
    BALL_BOUNCE = 3, /* the ball bounces until it lands after scl.x rebounds */
    BALL_FALL = 4, /* the ball falls until its tick passes FALL_STEPS */
    BALL_GONE = 5
};

/* the ball starts to bounce once player 0 or 1 is this near */

/* each bounce starts up at BOUNCE_SPEED times the sine of 45 degrees. its
 * upward speed then falls by BOUNCE_GRAVITY a step. the speed across starts at
 * BOUNCE_SPEED too */

void windy_ball_draw(struct task *task);
void Norm(struct task *task);

/* the ball moves along its heading only on the first step of its first
 * bounce. after that, windy_ball_bounce sets its x and z speeds alike, whatever
 * its heading */
void ObjectWindyBall(struct task *task)
{
    struct task_work *work = task->work;
    struct ball_extra *extra = EXTRA(task);
    NJS_VECTOR speed = {0.0F, 0.0F, 1.0F};

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BALL_START:
        work->mode = BALL_WAIT;
        task->draw = windy_ball_draw;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateY, work->ang.y);
        njCalcPoint(NULL, &speed, &speed);
        late_DrawObjectClipEx(1);
        VARS(work)->speed_x = speed.x;
        VARS(work)->speed_y = speed.y;
        VARS(work)->speed_z = speed.z;
        work->scl.y = work->pos.y;
        extra->accel = 0.0012F;
        extra->bounces = 1.0F;
        extra->roll = 1.0F;
        break;
    case BALL_WAIT:
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- NUM_CAISUU");
        }
        if (player_in_range(&work->pos, BALL_REACH)) {
            work->mode = BALL_BOUNCE;
        }
        windy_ball_draw(task);
        break;
    case BALL_BOUNCE:
        work->pos.x += VARS(work)->speed_x;
        work->pos.y += VARS(work)->speed_y;
        work->pos.z += VARS(work)->speed_z;
        Norm(task);
        windy_ball_draw(task);
        break;
    case BALL_FALL:
        work->pos.x += VARS(work)->speed_x;
        work->pos.y += VARS(work)->speed_y;
        work->pos.z += VARS(work)->speed_z;
        work->tick++;
        work->timer++;
        windy_ball_draw(task);
        if (work->tick > FALL_STEPS) {
            work->mode = BALL_GONE;
        }
        break;
    case BALL_GONE:
        FreeTask(task);
        break;
    }
}

/* draw the ball turned about x by its timer plus the roll, in degrees */
void windy_ball_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct ball_extra *extra = EXTRA(task);

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN(njRotateX,
         (Angle)((TASK_TIMER(work) + extra->roll) * ANGLE_PER_DEGREE));
    ds_DrawModelClip(&windy_ball_model);
    late_DrawObjectClipEx(1);
}

/* set the ball's speed for its next step. the ball rebounds each time it
 * falls below scl.y, the height it started at. at the landing after scl.x
 * rebounds, the ball falls away instead. work->tick counts the steps of this
 * bounce, and the timer those of every bounce */
void Norm(struct task *task)
{
    struct task_work *work = task->work;
    struct ball_extra *extra = EXTRA(task);
    Float speed;

    TASK_TIMER(work)++;
    work->tick++;
    speed = (extra->accel * TASK_TIMER(work)) + BOUNCE_SPEED;
    VARS(work)->speed_y =
        (njSin(NJM_DEG_ANG(45)) * BOUNCE_SPEED) - (work->tick * BOUNCE_GRAVITY);
    VARS(work)->speed_x = speed;
    VARS(work)->speed_z = speed;
    if (work->scl.y > work->pos.y) {
        extra->accel += 0.0002F;
        /* @hack spelling: the sum spelled out, which loads 0.22F with MOVA
         * (0x0c90c2e2). with +=, SHC loads it through R1 and FPUL, the
         * function runs 2 bytes longer and 36 of 85 words differ */
        extra->growth = extra->growth + 0.22F;
        work->tick = 0;
        if (extra->bounces++ > work->scl.x) {
            work->mode = BALL_FALL;
            VARS(work)->speed_y = -(njSin(NJM_DEG_ANG(45)) * BOUNCE_SPEED);
            work->timer = 0;
        }
    }
}
