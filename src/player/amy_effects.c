/* @unit 8C0DF040-8C0DFDA0 +r04 +egflags +pool32 +poolafter=FUN_8c0df0e0,AmyEffectPutFallHeart,FUN_8c0df570 +poolbra=amy_chicks_step:j1,FUN_8c0dfa38:j1,FUN_8c0dfc7e:j1 */
/* Amy's effects: hearts, the chicks round her head as she's dizzy, and her
 * hammer's shock */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "camera/camera.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/amy.h"
#include "player/amy_effects.h"
#include "player/player.h"
#include "player/textures.h"
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
void *syMalloc_default_malloc(size_t size);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void FUN_8c0df570(NJS_POINT3 *pos);
void FUN_8c0dfa38(struct task *task);
void FUN_8c0dfc7e(struct task *task);
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

#define FALL_STEPS 30
#define DRIFT_STEPS 15
#define SHOCK_STEPS 30

/* the circle the chicks fly round player 0's head: its radius, and its
 * height above her position */
#define CHICK_RADIUS 3.0F
#define CHICK_HEIGHT 12.0F

/* a shock's radius as it starts, how far it spreads each step, and how far
 * it swells along y halfway through its life */
#define SHOCK_RADIUS 3.0F
#define SHOCK_GROWTH 0.5F
#define SHOCK_SWELL 3.0F

#define RING_QUADS 12
#define RING_TURN (0x10000 / RING_QUADS)
/* each corner of the ring is drawn in its shock_ring_colors times the
 * ring's life times this */
#define RING_COLOR_SCALE 0.031F

#define VARS(work) ((struct effect_vars *)&(work)->vars)
enum shock_mode { SHOCK_START, SHOCK_SPREAD };

/* each effect also puts work->scl to its own use. a heart moves by it each
 * step, and a shock is drawn scaled by it. chicks_shrink_step grows the
 * chicks by its x each step */
struct effect_vars {
    /* the part of its life a heart has lived, from 0 to 1. for a shock, the
     * part it has left, from 1 to 0 */
    Float life;
};

extern NJS_OBJECT amy_shock_object;

static void FUN_8c0df040(struct task *task);
void FUN_8c0df480(struct task *task);
void FUN_8c0df938(struct task *task);
void FUN_8c0dfbfc(struct task *task);
void FUN_8c0df0e0(struct task *task);
void FUN_8c0df50c(struct task *task);
void chicks_draw(struct task *task);
void chicks_shrink_step(struct task *task);
extern NJS_TEXANIM heart_texanim;
extern NJS_SPRITE heart_sprite;
extern NJS_TEXANIM chick_texanims[2];
extern NJS_SPRITE chick_sprite;
extern NJS_POINT3 shock_ring_points[4];
extern NJS_COLOR shock_ring_colors[4];
extern NJS_COLOR shock_ring_fade_colors[4];
extern NJS_POINT3COL shock_ring_quad[1];
static void FUN_8c0df040(struct task *task)
{
    struct task_work *work = task->work;
    if (loop_count == 0) {
        njSetTexture_jp(&amy_eff_texlist);
        SetMaterial(1.0F - ((struct effect_vars *)&(work)->vars)->life, 1.0F,
                    1.0F, 1.0F);
        njColorBlendingMode_jp(0, 8);
        njColorBlendingMode_jp(1, 10);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
        njDrawSprite3D(&heart_sprite, 0, 0x20 | 0x02);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
void FUN_8c0df0e0(struct task *task)
{
    struct task_work *work = task->work;
    if ((((struct effect_vars *)&(work)->vars)->life += 1.0F / 30) >= 1.0F) {
        FreeTask(task);
        return;
    }
    work->scl.y += -0.05F;
    ((&work->pos)->x += (&work->scl)->x, (&work->pos)->y += (&work->scl)->y,
     (&work->pos)->z += (&work->scl)->z);
    work->ang.y += 0x400;
    if ((Uint16)work->ang.z > ((Angle)(((180) * 65536.0) / 360.0))) {
        work->ang.x -= 0x100;
    } else {
        work->ang.x += 0x200;
    }
    work->ang.z += work->ang.x;
    task->draw = FUN_8c0df040;
}

void AmyEffectPutFallHeart(NJS_POINT3 *pos, Angle ang_x, Angle ang_z)
{
    NJS_POINT3 ring;
    NJS_VECTOR out;
    Angle ang;
    struct task *task;
    struct task_work *work;

    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, ang_z);
    TURN(njRotateX, ang_x);
    ring.x = 0.4358F;
    ring.y = 0.9F;
    ring.z = 0.0F;
    for (ang = 0; ang < 0x10000; ang += ((Angle)(((45) * 65536.0) / 360.0))) {
        njRotateY(((void *)0), ((Angle)(((45) * 65536.0) / 360.0)));
        njCalcPoint(((void *)0), &ring, &out);
        if ((task = CreateElementalTask(0x2, 6, FUN_8c0df0e0)) != ((void *)0)) {
            work = task->work;
            work->pos = *pos;
            work->pos.x += out.x * 5.0F;
            work->pos.y += out.y * 5.0F;
            work->pos.z += out.z * 5.0F;
            work->scl = out;
            work->ang.y = ang;
            work->ang.z = 0x7000;
            task->draw = FUN_8c0df040;
        }
    }
    late_DrawObjectClipEx(1);
}
static void FUN_8c0df480(struct task *task)
{
    struct task_work *work = task->work;
    Float alpha;
    if (loop_count == 0) {
        njSetTexture_jp(&amy_eff_texlist);
        alpha = ((struct effect_vars *)&(work)->vars)->life - 0.5F;
        alpha = (0.25F - (alpha * alpha)) * 2.0F;
        SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
        njColorBlendingMode_jp(0, 8);
        njColorBlendingMode_jp(1, 10);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        njDrawSprite3D(&heart_sprite, 0, 0x20 | 0x10 | 0x02);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
void FUN_8c0df50c(struct task *task)
{
    struct task_work *work = task->work;
    if ((((struct effect_vars *)&(work)->vars)->life += 1.0F / 15) >= 1.0F) {
        FreeTask(task);
        return;
    }
    work->scl.x *= 0.9F;
    work->scl.y *= 0.9F;
    work->scl.z *= 0.9F;
    ((&work->pos)->x += (&work->scl)->x, (&work->pos)->y += (&work->scl)->y,
     (&work->pos)->z += (&work->scl)->z);
    FUN_8c0df480(task);
}

void FUN_8c0df570(NJS_POINT3 *pos)
{
    struct task *task;
    NJS_VECTOR way;
    if ((task = CreateElementalTask(0x2, 6, FUN_8c0df50c)) != ((void *)0)) {
        way.x =
            ((rand() * (((0.5F) - (-0.5F)) * (1.0F / (32767 + 1)))) + (-0.5F));
        way.y =
            ((rand() * (((0.5F) - (-0.5F)) * (1.0F / (32767 + 1)))) + (-0.5F));
        way.z =
            ((rand() * (((0.5F) - (-0.5F)) * (1.0F / (32767 + 1)))) + (-0.5F));
        if (njScalor(&way) == 0.0F) {
            /* @hack spelling: way stored through &way, whose address SHC forms
             * again for each store (MOV R15,R2 and ADD #4,R2 at 0x8c0e9584
             * and again at 0x8c0e958e); stored as way.x, 48 of 103 words
             * differ */
            (&way)->x = 1.0F;
            (&way)->y = (&way)->z = 0.0F;
        } else {
            njUnitVector(&way);
        }
        task->work->scl.x = way.x * 0.25F;
        task->work->scl.y = way.y * 0.25F;
        task->work->scl.z = way.z * 0.25F;
        task->draw = FUN_8c0df480;
        task->work->pos = *pos;
    }
}

/* draw the chicks round player 0's head, a third of a turn apart from
 * work->ang.y, on a frame's first step. each faces the camera and spins.
 * a_piyo02 flashes over each chick, its alpha the chick's distance from her
 * along x divided by CHICK_RADIUS */
void chicks_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    NJS_POINT3 pos;
    Angle ang;
    Float alpha;

    if (loop_count == 0) {
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_INVSRCALPHA);
        njSetTexture_jp(&amy_eff_texlist);
        /* @bug arithmetic: a third of 0x10000 truncates to 0x5555 (MOV.W at
         * 0x8c0e9758). three steps make 0xffff, one angle unit short of a
         * turn, so the loop draws a fourth chick, over the first */
        for (ang = work->ang.y; ang < work->ang.y + 0x10000;
             ang += 0x10000 / 3) {
            njPushMatrix(NULL);
            pos = player->pos;
            pos.x += njSin(ang) * CHICK_RADIUS;
            pos.z += njCos(ang) * CHICK_RADIUS;
            pos.y += CHICK_HEIGHT;
            njTranslateV(NULL, &pos);
            njPushMatrix(NULL);
            TURN(njRotateY, camera_twp->ang.y);
            TURN(njRotateX, camera_twp->ang.x);
            /* @hack spelling: -ang shifted left by 2, which SHC negates into
             * R3 and then shifts (NEG R14,R3 at 0x8c0e9706); as -ang * 4, it
             * copies, shifts and then negates, and 61 of 175 words differ */
            TURN(njRotateZ, (Angle)(-ang << 2));
            njDrawSprite3D(&chick_sprite, 0,
                           NJD_SPRITE_ALPHA | NJD_SPRITE_VFLIP);
            late_DrawObjectClipEx(1);
            /* @hack spelling: the alpha in a statement of its own, which keeps
             * draw_set_material's address in R8 and njSin's in R11
             * (0x8c0e9680, 0x8c0e9682); as the call's argument, the two trade
             * and 6 of 175 words differ */
            alpha = _builtin_fabsf(njSin(ang));
            SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
            njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                                   NJD_COLOR_BLENDING_BOTHSRCALPHA);
            njDrawSprite3D(&chick_sprite, 1,
                           NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE |
                               NJD_SPRITE_COLOR);
            SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
            late_DrawObjectClipEx(1);
        }
    }
}

/* the step of the chicks once she's no longer dizzy. they grow a little
 * and then shrink away, and the task ends once their y scale is under
 * 0.1 or player 0 has no task */
void chicks_shrink_step(struct task *task)
{
    struct task_work *work = task->work;

    if (playertwp[0] == NULL) {
        FreeTask(task);
        return;
    }
    work->scl.x -= 0.025F;
    chick_sprite.sx += work->scl.x;
    /* @hack spelling: the size tested where it's stored, which tests the sum
     * still in FR1 (FCMP/GT FR1,FR2 at 0x8c0e981c); stored in a statement of
     * its own, SHC loads it again, the function runs 4 bytes longer and 9 of
     * 38 words differ */
    if ((chick_sprite.sy += work->scl.x) < 0.1F) {
        FreeTask(task);
    } else {
        chicks_draw(task);
    }
}

void amy_chicks_step(struct task *task)
{
    struct task_work *work = task->work;
    Float scale;

    if (playertwp[0] == NULL) {
        FreeTask(task);
        return;
    }
    task->draw = chicks_draw;
    if (amy_get_action(0) != AMY_DIZZY) {
        work->scl.x = 0.2F;
        chicks_shrink_step(task);
        task->step = chicks_shrink_step;
    } else {
        work->ang.y += 0x200;
        scale = (njSin(work->ang.y * 4) * 0.3F) + 1.0F;
        chick_sprite.sx = scale;
        chick_sprite.sy = scale;
        chicks_draw(task);
    }
}
void FUN_8c0df938(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    if (loop_count == 0) {
        njColorBlendingMode_jp(0, 10);
        njColorBlendingMode_jp(1, 10);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
        ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
        for (ang = 0; ang < 12 * (0x10000 / 12); ang += (0x10000 / 12)) {
            njPushMatrix(((void *)0));
            ((ang) ? (njRotateY)(((void *)0), (ang)) : (void)0);
            njScaleV(((void *)0), &work->scl);
            njDrawPolygon3D(shock_ring_quad, 4, 0x00000020 | 0x00000040);
            late_DrawObjectClipEx(1);
        }
        late_DrawObjectClipEx(1);
    }
}
void FUN_8c0dfa38(struct task *task)
{
    struct task_work *work = task->work;
    Uint16 i;
    if (work->mode == SHOCK_START) {
        work->scl.x = 3.0F;
        ((struct effect_vars *)&(work)->vars)->life = 1.0F;
        work->mode = SHOCK_SPREAD;
        task->draw = FUN_8c0df938;
    }
    if ((((struct effect_vars *)&(work)->vars)->life += -1.0F / 30) < 0.0F) {
        FreeTask(task);
        return;
    }
    work->scl.x += 0.5F;
    work->scl.y =
        njSin((Angle)(((struct effect_vars *)&(work)->vars)->life * 32768.0F)) *
        3.0F;
    work->scl.z = work->scl.x;
    for (i = 0; i < 4; i++) {
        shock_ring_fade_colors[i].argb.r =
            ((struct effect_vars *)&(work)->vars)->life *
            shock_ring_colors[i].argb.r * 0.031F;
        shock_ring_fade_colors[i].argb.g =
            ((struct effect_vars *)&(work)->vars)->life *
            shock_ring_colors[i].argb.g * 0.031F;
        shock_ring_fade_colors[i].argb.b =
            ((struct effect_vars *)&(work)->vars)->life *
            shock_ring_colors[i].argb.b * 0.031F;
    }
    FUN_8c0df938(task);
    CheckRangeOut(task);
}
void FUN_8c0dfbfc(struct task *task)
{
    struct task_work *work = task->work;
    if (loop_count == 0) {
        njSetTexture_jp(&amy_eff_texlist);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
        ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
        njScaleV(((void *)0), &work->scl);
        late_DrawObject(&amy_shock_object);
        late_DrawObjectClipEx(1);
    }
}
void FUN_8c0dfc7e(struct task *task)
{
    struct task_work *work = task->work;
    if (work->mode == SHOCK_START) {
        work->scl.x = 3.0F;
        ((struct effect_vars *)&(work)->vars)->life = 1.0F;
        work->mode = SHOCK_SPREAD;
        task->draw = FUN_8c0dfbfc;
    }
    if ((((struct effect_vars *)&(work)->vars)->life += -1.0F / 30) < 0.0F) {
        FreeTask(task);
        return;
    }
    work->scl.x += 0.5F;
    work->scl.y =
        njSin((Angle)(((struct effect_vars *)&(work)->vars)->life * 32768.0F)) *
        3.0F;
    work->scl.z = work->scl.x;
    FUN_8c0dfbfc(task);
    CheckRangeOut(task);
}
