/* @unit 0C911CC0-0C911F20 +r04 +egflags +asmfunc=FUN_0c911dc0:0c911f20 */
/* the cargo ride's tunnel walls, drawn scrolling past the train */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/tree.h"
#include "player/player.h"
#include "stage/stage.h"
#include "stg12/cargo_ride.h"
#include "stg12/cargo_tunnel.h"
#include "stg12/texlists.h"
#include "system/frame.h"
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
void late_DrawObject(NJS_OBJECT *object);
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

#define TUNNEL_Y 10000.0F
#define PIECE_LENGTH 260.0F
#define PAIRS 10
#define AHEAD (PIECE_LENGTH * 9)
#define PAIR_LENGTH (PIECE_LENGTH * 2)
#define SCROLL_SPEED 20.0F
#define END_SPEED 2.0F
#define SLOW_DOWN 0.1F
#define RUN_STEPS 600
#define VARS(work) ((struct cargo_tunnel_vars *)&(work)->vars)
extern NJS_OBJECT cargo_tunnel_a_object;
extern NJS_OBJECT cargo_tunnel_b_object;

/* the walls are PAIRS pairs of pieces, A then B, each PIECE_LENGTH long. the
 * first piece stands AHEAD plus the scroll along z from the tunnel's pos. each
 * later piece stands PIECE_LENGTH further along -z */

/* the walls scroll back SCROLL_SPEED a step, while the train runs at most 5
 * a step. so the train seems faster than it is */
/* once the ride is ending, the scroll slows by SLOW_DOWN a step to
 * END_SPEED */

/* the tunnel counts its steps in TUNNEL_RUN until the count passes RUN_STEPS,
 * then stays in TUNNEL_COUNTED. nothing else reads the mode */
enum cargo_tunnel_mode { TUNNEL_RUN = 2, TUNNEL_COUNTED = 3 };

/* TASK_TIMER(work) holds the stage and act the tunnel started in, which
 * nothing reads */
struct cargo_tunnel_vars {
    Float scroll;
    Float speed;
    int steps; /* counted in TUNNEL_RUN */
};

void cargo_tunnel_step(struct task *task);
void cargo_tunnel_draw(struct task *task);

void cargo_tunnel_start(struct task *task)
{
    struct task_work *work = task->work;

    work->ang.x = 0;
    work->ang.z = 0;
    work->pos.x = 0.0F;
    work->pos.y = TUNNEL_Y;
    TASK_TIMER(work) = GetStageNumber();
    VARS(work)->scroll = 0.0F;
    VARS(work)->speed = SCROLL_SPEED;
    work->mode = TUNNEL_RUN;
    task->step = cargo_tunnel_step;
    task->draw = cargo_tunnel_draw;
}

/* the tunnel moves along z by whole pairs, so that it stays within a pair of
 * player 0. a whole pair leaves each piece where one of its kind was */
void cargo_tunnel_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 pos;
    Float pairs;

    if (!cargo_ride_on) {
        FreeTask(task);
        return;
    }
    GetPlayerPosition(0, 0, &pos, NULL);
    /* @hack spelling: the difference, its scale and its round-off in three
     * statements, which keeps the difference in FR4, njRoundOff's argument,
     * FSUB FR3,FR4 at 0x0c9124fc. as one statement, SHC subtracts into FR2 and
     * copies it to FR4, and 31 of 92 words differ */
    pairs = pos.z - work->pos.z;
    pairs *= 1.0F / PAIR_LENGTH;
    pairs = njRoundOff(pairs);
    work->pos.z += pairs * PAIR_LENGTH;
    if (cargo_ride_ending) {
        VARS(work)->speed -= SLOW_DOWN;
        if (VARS(work)->speed <= END_SPEED) {
            VARS(work)->speed = END_SPEED;
        }
    } else if (work->mode == TUNNEL_RUN) {
        ++VARS(work)->steps;
        if (VARS(work)->steps > RUN_STEPS) {
            VARS(work)->steps = 0;
            work->mode = TUNNEL_COUNTED;
        }
    }
    VARS(work)->scroll -= VARS(work)->speed;
    if (VARS(work)->scroll <= PAIR_LENGTH) {
        VARS(work)->scroll += PAIR_LENGTH;
    }
    cargo_tunnel_draw(task);
}
#ifdef NON_MATCHING

void cargo_tunnel_draw(struct task *task)
{
    struct task_work *work = task->work;
    Float ahead;
    Angle ang;
    int i;

    if (loop_count == 0) {
        /* @hack spelling: ahead assigned before the texture is set, which
         * stores it on the stack in the slot of njSetTexture's call, at
         * 0x0c912622. assigned at its use, 91 of 102 words differ */
        ahead = AHEAD;
        njSetTexture_jp(&hotshelter4_texlist);
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        /* @hack redundant: the scroll times 1, which SHC adds to ahead in one
         * FMAC, at 0x0c91264c. as a plain sum, 67 of 102 words differ */
        njTranslate(NULL, 0.0F, 0.0F, (VARS(work)->scroll * 1.0F) + ahead);
        for (i = 0; i < PAIRS; ++i) {
            late_DrawObject(&cargo_tunnel_a_object);
            njTranslate(NULL, 0.0F, 0.0F, -PIECE_LENGTH);
            late_DrawObject(&cargo_tunnel_b_object);
            njTranslate(NULL, 0.0F, 0.0F, -PIECE_LENGTH);
        }
        late_DrawObjectClipEx(1);
    }
}
#else
void cargo_tunnel_draw(struct task *task)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
}
#endif
