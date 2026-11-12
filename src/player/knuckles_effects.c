/* @unit 8C0C9F80-8C0CBD40 +r04 +egflags +pool32 +poolafter=FUN_8c0ca5c0,KnuEffectDisplayRadar,FUN_8c0cacd8,knuckles_scatter_rocks,KnuEffectPutRingSpring,KnuEffectChargeUp,KnuEffectComboFire,FUN_8c0cb7b0,knuckles_trail_clear +poolbra=FUN_8c0ca05c:2,FUN_8c0ca1ec:3,FUN_8c0ca45e:1,FUN_8c0ca8f0:j1,dispKnuEffectClod:2 +asmfunc=knuckles_trail_draw */
/* Knuckles' effects: his punches, digging and radar, and his maximum heat,
 * the attack his fighting gloves charge */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "object/ring.h"
#include "player/knuckles_effects.h"
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void dispKnuEffectChargeUpStay(struct task *task);
void FUN_8c0c9fd4(struct task *task);
void FUN_8c0ca172(struct task *task);
void FUN_8c0ca8f0(struct task *task);
void FUN_8c0cb8a0(void);
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
extern NJS_TEXLIST texlist_knu_eff;
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

/* the maximum heat's trail keeps up to TRAIL_RINGS rings of TRAIL_POINTS
 * points round him. the strip between two rings takes their points in pairs,
 * then the first pair again to close the loop */
#define TRAIL_RINGS 16
#define TRAIL_POINTS 8
#define STRIP_POINTS ((TRAIL_POINTS * 2) + 2)
#define STRIP_TRIANGLES (STRIP_POINTS - 2)

/* the flash's sprite frames. it steps through them half a frame a step,
 * then ends */
#define FLASH_FRAMES 6
/* the wave's radius at its start, before it shrinks */
#define WAVE_RADIUS 8.0F
/* the steps a glow of the burst lasts */
#define BURST_STEPS 30
/* the rings a fountain scatters, a few at a time, FOUNTAIN_DELAY steps
 * apart */
#define FOUNTAIN_RINGS 32
#define FOUNTAIN_DELAY 17

/* an effect's work mode. EFFECT_START sets it up on its first step, and
 * dirt sinks once it falls below its floor */
#define EFFECT(task) ((struct effect_work *)(task)->work)
#define FOUNTAIN(task) ((struct fountain_work *)(task)->work)
#define MOTE(task) ((struct mote_work *)(task)->work)
#define PULSE(task) ((struct pulse_work *)(task)->work)

void FUN_8c0ca394(struct task *task);
void FUN_8c0ca5c0(struct task *task);
void dispKnuEffectClod(struct task *task);
void FUN_8c0cacd8(struct task *task);
void FUN_8c0cb7b0(struct task *task);
void FUN_8c0c9f80(struct task *task);
void FUN_8c0ca05c(struct task *task);
void FUN_8c0ca1ec(struct task *task);
enum effect_mode { EFFECT_START, EFFECT_PLAY, EFFECT_SINK };

/* the work of each effect but the fountain, the motes and the pulses, in
 * place of task_work. pos and speed are task_work's pos and scl */
struct effect_work {
    Sint8 mode;
    Uint8 unk_01[5];
    Uint16 timer; /* steps since it was made */
    /* the flash's frame and the dirt's size. for the wave and a puff, the
     * part of it left, from 1 down to 0 */
    Float scale;
    Float flip; /* 1, or -1 to mirror the dirt */
    Float floor; /* the height below which the dirt sinks */
    Angle ang_x;
    Angle spin; /* added to a rock's ang_x and ang_z each step */
    Angle ang_z;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    struct collision_work *collision;
};

/* the fountain's work, in place of task_work */
struct fountain_work {
    Sint8 mode;
    Uint8 unk_01[19];
    Sint32 rings; /* the rings it has yet to scatter */
    Sint32 delay; /* steps until it scatters more */
    Sint32 steps; /* steps it has run */
    NJS_POINT3 pos;
};

/* the work of a mote and of the copy it leaves each step, in place of
 * task_work. a mote circles player 0 */
struct mote_work {
    Sint8 mode;
    Uint8 unk_01[11];
    Float age; /* the part of its life gone, from 0 to 1 */
    Float alpha; /* its alpha before it fades */
    Angle ang; /* its angle round player 0 */
    Angle turn; /* added to ang each step */
    Uint8 unk_1c[4];
    NJS_POINT3 pos;
    Float height; /* its height above player 0 */
    Float radius; /* the radius of its circle round player 0 */
};

/* a pulse's work, in place of task_work. as age goes from 0 to 1, its scale
 * goes from scale_from to scale_to and its alpha from alpha_from to
 * alpha_to */
struct pulse_work {
    Uint8 unk_00[8];
    Float alpha_to;
    Float age;
    Float alpha_from;
    Uint8 unk_14[24];
    Float speed; /* added to age each step */
    Float scale_from;
    Float scale_to;
};

/* the points round him at one step of the trail */
struct trail_ring {
    NJS_POINT3 points[TRAIL_POINTS];
};

/* the trail's rings, newest first, of which the first count hold points */
struct trail {
    Sint32 count;
    struct trail_ring rings[TRAIL_RINGS];
};

extern NJS_OBJECT knuckles_swing_object;
/* @hack type: the aura as an array, whose address SHC loads before it reads
 * model at @(4,R3) (0x8c0d40fc). as an object, SHC folds model's offset into
 * the pool word, and 20 of the 185 words of knuckles_draw_aura and
 * pulse_step differ */
extern NJS_OBJECT knuckles_aura_object[];
void FUN_8c0ca45e(struct task *task);
void FUN_8c0cac60(struct task *task);
void KnuEffectRingSpring(struct task *task);
void FUN_8c0cb354(struct task *task);
void KnuEffectChargeUp(struct task *task);
void KnuEffectChargeScl(struct task *task);
extern NJS_TEXANIM flash_texanims[6];
extern NJS_SPRITE flash_sprite;
extern NJS_TEXANIM glow_texanim;
extern NJS_SPRITE puff_sprite;
extern NJS_SPRITE wave_sprite;
extern NJS_SPRITE mote_sprite;
extern NJS_TEXANIM fleck_texanim;
extern NJS_SPRITE dirt_sprite;
extern NJS_SPRITE rock_sprite;
extern NJS_TEXANIM radar_texanims[10];
extern NJS_SPRITE radar_sprite;
extern struct collision_shape wave_shapes[];
extern struct trail trail;
extern NJS_POINT3 trail_points[((8 * 2) + 2)];
extern NJS_COLOR trail_colors[((8 * 2) + 2)];
extern NJS_POINT3COL trail_strip;
void FUN_8c0c9f80(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    switch (work->mode) {
    case EFFECT_START:
        work->scale = 0.0F;
        work->mode = EFFECT_PLAY;
        task->draw = FUN_8c0c9fd4;
        break;
    case EFFECT_PLAY:
        if ((work->scale += 0.5F) >= 6) {
            FreeTask(task);
            return;
        }
        break;
    }
    FUN_8c0c9fd4(task);
    CheckRangeOut(task);
}

void FUN_8c0c9fd4(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    if (loop_count == 0) {
        SetMaterial(0.5F, 1.0F, 1.0F, 1.0F);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        njSetTexture_jp(&texlist_knu_eff);
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        njDrawSprite3D(&flash_sprite, (Uint32)work->scale,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE | NJD_SPRITE_COLOR);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
void FUN_8c0ca05c(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    switch (work->mode) {
    case EFFECT_START:
        work->scale = 1.0F;
        CCL_Init(task, wave_shapes, 4, 1, 1);
        work->mode = EFFECT_PLAY;
        task->draw = FUN_8c0ca172;
        break;
    case EFFECT_PLAY:
        if ((work->scale += -1.0F / (0.2F * 60.0F)) <= 0.0F) {
            FreeTask(task);
            return;
        }
        work->pos.x += work->speed.x;
        work->pos.y += work->speed.y;
        work->pos.z += work->speed.z;
        work->collision->shapes->radius = work->scale * 8.0F;
        EntryColliList((struct task_work *)work);
        break;
    }
    FUN_8c0ca172(task);
    CheckRangeOut(task);
}
void FUN_8c0ca172(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    Float alpha;
    if (loop_count == 0) {
        alpha = work->scale * 0.8F;
        SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
        njColorBlendingMode_jp(0, 8);
        njColorBlendingMode_jp(1, 10);
        njSetTexture_jp(&texlist_knu_eff);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        njDrawSprite3D(&wave_sprite, 0, 0x20 | 0x10 | 0x02);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
void FUN_8c0ca1ec(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    switch (work->mode) {
    case EFFECT_START:
        work->scale = 1.0F;
        work->speed.x = (rand() * (1.0F / (32767 + 1))) - 0.5F;
        work->speed.y = (rand() * (1.0F / (32767 + 1))) - 0.5F;
        work->speed.z = (rand() * (1.0F / (32767 + 1))) - 0.5F;
        if (njScalor(&work->speed) == 0.0F) {
            work->speed.x = 1.0F;
            work->speed.y = work->speed.z = 0.0F;
        } else {
            njUnitVector(&work->speed);
        }
        work->speed.x *= 0.5F;
        work->speed.y *= 0.5F;
        work->speed.z *= 0.5F;
        work->mode = EFFECT_PLAY;
        task->draw = FUN_8c0ca394;
        break;
    case EFFECT_PLAY:
        if ((work->scale += -1.0F / (2.5F * 60.0F)) <= 0.0F) {
            FreeTask(task);
            return;
        }
        work->pos.x += work->speed.x;
        work->pos.y += work->speed.y;
        work->pos.z += work->speed.z;
        work->speed.x *= 0.975F;
        work->speed.y *= 0.975F;
        work->speed.z *= 0.975F;
        break;
    }
    FUN_8c0ca394(task);
    CheckRangeOut(task);
}
void FUN_8c0ca394(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    Float alpha;
    Float size;
    if (loop_count == 0) {
        alpha = 0.005F + (work->scale * 0.015F);
        size = 4.0F - (work->scale * 1.0F);
        SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
        njColorBlendingMode_jp(0, 8);
        njColorBlendingMode_jp(1, 10);
        njSetTexture_jp(&texlist_knu_eff);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((camera_twp->ang.y) ? (njRotateY)(((void *)0), (camera_twp->ang.y))
                             : (void)0);
        ((camera_twp->ang.x) ? (njRotateX)(((void *)0), (camera_twp->ang.x))
                             : (void)0);
        njScale(((void *)0), size, size, size);
        njDrawSprite3D(&puff_sprite, 0, 0x20 | 0x08 | 0x02);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}

/* a glow of the burst, which slows and fades out over BURST_STEPS */
void FUN_8c0ca45e(struct task *task)
{
    struct effect_work *work = EFFECT(task);
    NJS_POINT3 pos; /* NOLINT(clang-diagnostic-unused-but-set-variable) */
    NJS_VECTOR drag;

    if (work->mode == EFFECT_START) {
        work->mode = EFFECT_PLAY;
    }
    /* @hack spelling: the timer stepped inside the test, which compares the
     * new count in R0 as it stores it (CMP/GT R3,R0 at 0x8c0d2fc2).
     * stepped apart, 157 of 177 words differ */
    if (++work->timer > BURST_STEPS) {
        FreeTask(task);
        return;
    }
    /* @hack redundant: a copy of the work's pos that nothing reads, which
     * SHC stores at @(12,R15) in a 24-byte frame (0x8c0d2fd8, ADD #-24,R15
     * at 0x8c0d2fa8). without it, the frame is 12 bytes, and 41 of 177 words
     * differ */
    pos = work->pos;
    drag.x = work->speed.x;
    drag.y = work->speed.y + 0.1F;
    drag.z = work->speed.z;
    /* @hack spelling: the stores through &drag, whose address SHC copies from
     * R15 for each (MOV R15,R2 at 0x8c0d300c and 0x8c0d3012, MOV R15,R3 at
     * 0x8c0d3018). as drag.x, drag.y and drag.z, SHC stores off R15, and 10
     * of 177 words differ */
    if (njScalor(&drag) == 0.0F) {
        (&drag)->x = 1.0F;
        (&drag)->y = (&drag)->z = 0.0F;
    } else {
        njUnitVector(&drag);
    }
    /* @hack spelling: each part scaled inside its test, which scales, stores
     * and tests it in FR2 (0x8c0d3090 to 0x8c0d3096). scaled in a statement
     * before each test, 104 of 177 words differ */
    if (njAbs(drag.x *= -0.05F) < 0.001F) {
        drag.x = 0.0F;
    }
    if (njAbs(drag.y *= -0.05F) < 0.001F) {
        drag.y = 0.0F;
    }
    if (njAbs(drag.z *= -0.05F) < 0.001F) {
        drag.z = 0.0F;
    }
    njAddVector(&work->speed, &drag);
    njAddVector(&work->pos, &work->speed);
    FUN_8c0ca5c0(task);
    CheckRangeOut(task);
}
void FUN_8c0ca5c0(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    Float alpha;
    if (loop_count == 0) {
        alpha = (30 - work->timer) * (1.0F / 30);
        SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
        njColorBlendingMode_jp(0, 8);
        njColorBlendingMode_jp(1, 10);
        njSetTexture_jp(&texlist_knu_eff);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        njDrawSprite3D(&puff_sprite, 0, 0x20 | 0x10 | 0x02);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}

void SetEffectSpray(NJS_POINT3 *pos, int unused)
{
    /* @hack type: i as a byte, which SHC counts with ADD #1 and EXTU.B
     * (0x8c0d3330, 0x8c0d3332) over four copies of the body. as an int, SHC
     * counts down with DT over one copy, and 269 of 270 words differ */
    Uint8 i;
    struct task *task;

    for (i = 0; i < 10; i++) {
        if ((task = CreateElementalTask(0x2, 6, FUN_8c0ca45e)) != ((void *)0)) {
            ((struct effect_work *)(task)->work)->pos = *pos;
            ((struct effect_work *)(task)->work)->speed.x =
                (1.0F - (rand() * (1.0F / 16384.0F))) * 2.0F;
            EFFECT(task)->speed.y =
                (1.0F - (rand() * (1.0F / 16384.0F))) * 2.0F;
            EFFECT(task)->speed.z =
                (1.0F - (rand() * (1.0F / 16384.0F))) * 2.0F;
            task->draw = FUN_8c0ca5c0;
        }
    }
}
void FUN_8c0ca8f0(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    if (++work->timer > 0.8F * 60.0F) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case EFFECT_START:
        work->floor = work->pos.y - (rand() * (1.0F / (32767 + 1)));
        work->scale = (rand() * (1.0F / (32767 + 1))) + 1.0F;
        if (rand() * (1.0F / (32767 + 1)) < 0.5F) {
            work->flip = 1.0F;
        } else {
            work->flip = -1.0F;
        }
        work->mode = EFFECT_PLAY;
        task->draw = dispKnuEffectClod;
        return;
    case EFFECT_PLAY:
        work->speed.y += -0.2F;
        work->pos.x += work->speed.x;
        work->pos.y += work->speed.y;
        work->pos.z += work->speed.z;
        if (work->pos.y < work->floor) {
            work->mode = EFFECT_SINK;
        }
        break;
    case EFFECT_SINK:
        work->pos.y += -0.2F;
        break;
    }
    dispKnuEffectClod(task);
    CheckRangeOut(task);
}
void dispKnuEffectClod(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    Float stretch;
    Float width;
    Float height;
    if (loop_count == 0) {
        njColorBlendingMode_jp(0, 8);
        njColorBlendingMode_jp(1, 6);
        njSetTexture_jp(&texlist_knu_eff);
        njPushMatrix(((void *)0));
        stretch = work->speed.y * 0.25F;
        if (stretch < -0.25F) {
            stretch = -0.25F;
        } else if (stretch > 0.25F) {
            stretch = 0.25F;
        }
        width = (1.0F - stretch) * work->scale * work->flip;
        height = (stretch + 1.0F) * work->scale;
        njTranslateV(((void *)0), &work->pos);
        ((camera_twp->ang.y) ? (njRotateY)(((void *)0), (camera_twp->ang.y))
                             : (void)0);
        ((camera_twp->ang.x + ((Angle)(((180) * 65536.0) / 360.0)))
             ? (njRotateX)(((void *)0), (camera_twp->ang.x +
                                         ((Angle)(((180) * 65536.0) / 360.0))))
             : (void)0);
        njScale(((void *)0), width, height, width);
        njDrawSprite3D(&dirt_sprite, 0, 0x20);
        late_DrawObjectClipEx(1);
    }
}

void KnuEffectDisplayRadar(NJS_POINT3 *pos, int sprite, Float scale,
                           Float alpha)
{
    if (loop_count == 0) {
        SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                               NJD_COLOR_BLENDING_BOTHSRCALPHA);
        radar_sprite.p.x = pos->x;
        radar_sprite.p.y = pos->y;
        radar_sprite.sx = scale;
        radar_sprite.sy = scale;
        njSetTexture_jp(&texlist_knu_eff);
        late_DrawSprite2D(&radar_sprite, sprite, (scale * 0.01F) - 2.0F,
                          NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
void FUN_8c0cac60(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    if (++work->timer >= 60) {
        FreeTask(task);
    }
    if ((work->speed.y += -0.1F) < -2.0F) {
        work->speed.y = -2.0F;
    }
    work->pos.x += work->speed.x;
    work->pos.y += work->speed.y;
    work->pos.z += work->speed.z;
    work->ang_x += work->spin;
    work->ang_z += work->spin;
    FUN_8c0cacd8(task);
}
void FUN_8c0cacd8(struct task *task)
{
    struct effect_work *work = ((struct effect_work *)(task)->work);
    if (loop_count == 0) {
        njColorBlendingMode_jp(0, 8);
        njColorBlendingMode_jp(1, 6);
        njSetTexture_jp(&texlist_knu_eff);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang_x) ? (njRotateX)(((void *)0), (work->ang_x)) : (void)0);
        ((work->ang_z) ? (njRotateZ)(((void *)0), (work->ang_z)) : (void)0);
        njDrawSprite3D(&rock_sprite, 0, 0x20);
        late_DrawObjectClipEx(1);
    }
}

void knuckles_scatter_rocks(NJS_POINT3 *pos, NJS_VECTOR *speed)
{
    int i;
    struct task *task;

    for (i = 0; i < 4; i++) {
        if ((task = CreateElementalTask(0x2, 6, FUN_8c0cac60)) != ((void *)0)) {
            ((struct effect_work *)(task)->work)->pos = *pos;
            ((struct effect_work *)(task)->work)->speed.x =
                speed->x + ((0.5F - (rand() * (1.0F / (32767 + 1)))) * 1.0F);
            ((struct effect_work *)(task)->work)->speed.y =
                speed->y + ((0.5F - (rand() * (1.0F / (32767 + 1)))) * 1.0F);
            ((struct effect_work *)(task)->work)->speed.z =
                speed->z + ((0.5F - (rand() * (1.0F / (32767 + 1)))) * 1.0F);
            ((struct effect_work *)(task)->work)->ang_x =
                (Angle)(rand() * (1.0F / (32767 + 1)) * 65536.0F);
            ((struct effect_work *)(task)->work)->spin =
                (Angle)((0.5F - (rand() * (1.0F / (32767 + 1)))) * 4096.0F);
            ((struct effect_work *)(task)->work)->ang_z =
                (Angle)(rand() * (1.0F / (32767 + 1)) * 65536.0F);
            task->draw = FUN_8c0cacd8;
        }
    }
}

/* a fountain of what his digging turns up: FOUNTAIN_RINGS rings, up to 5
 * at a time, and dirt and rock every eighth step. it ends once it has
 * scattered the rings */
void KnuEffectRingSpring(struct task *task)
{
    struct fountain_work *work = FOUNTAIN(task);
    NJS_VECTOR up;
    struct task *child;
    int count;
    Angle ang;

    switch (work->mode) {
    case EFFECT_START:
        work->rings = FOUNTAIN_RINGS;
        work->delay = FOUNTAIN_DELAY;
        work->mode = EFFECT_PLAY;
        break;
    case EFFECT_PLAY:
        /* @hack spelling: delay counted down inside the test, which tests R1
         * as it stores it (CMP/PL R1 at 0x8c0d3b62). counted down apart, SHC
         * tests a copy, and 38 of 182 words differ */
        if (--work->delay <= 0) {
            work->delay = FOUNTAIN_DELAY;
            count = (int)(rand() * RAND_SCALE * 5.1F);
            if (work->rings < count) {
                count = work->rings;
            }
            ring_scatter(work->pos.x, work->pos.y - 8.0F, work->pos.z, count);
            /* @hack spelling: rings counted down inside the test, which tests
             * R2 as it stores it (CMP/PL R2 at 0x8c0d3b9e). counted down
             * apart, SHC tests a copy, and 7 of 182 words differ */
            if ((work->rings -= count) <= 0) {
                FreeTask(task);
                return;
            }
        }
        break;
    }
    /* @hack spelling: steps counted inside the test, which tests R0 and stores
     * it in the BF/S's slot (TST #7,R0 at 0x8c0d3be4). counted apart, SHC
     * counts in R3 and copies it to R0, and 112 of 182 words differ */
    if (!(++work->steps & 7)) {
        for (ang = (Angle)(rand() * RAND_SCALE * 2048.0F); ang < 0x10000;
             ang += 0x800) {
            if ((child = CreateElementalTask(0x2, 6, FUN_8c0ca8f0)) !=
                ((void *)0)) {
                ((struct effect_work *)(child)->work)->pos = work->pos;
                ((struct effect_work *)(child)->work)->speed.x =
                    rand() * njSin(ang) * (1.0F / (32767 + 1));
                ((struct effect_work *)(child)->work)->speed.y =
                    (rand() * (1.0F / (32767 + 1)) * 1.75F) + 0.25F;
                ((struct effect_work *)(child)->work)->speed.z =
                    rand() * njCos(ang) * (1.0F / (32767 + 1));
            }
        }
        up.x = up.z = 0.0F;
        up.y = 1.0F;
        knuckles_scatter_rocks(&work->pos, &up);
    }
}

void KnuEffectPutRingSpring(NJS_POINT3 *pos)
{
    struct task *task;
    if ((task = CreateElementalTask(0x2, 6, KnuEffectRingSpring)) !=
        ((void *)0)) {
        ((struct fountain_work *)(task)->work)->pos = *pos;
    }
}

void KnuEffectDrawTsubu(NJS_POINT3 *pos, Float alpha)
{
    if (loop_count == 0) {
        njSetTexture_jp(&texlist_knu_eff);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
        njPushMatrix(NULL);
        njTranslateV(NULL, pos);
        njDrawSprite3D(&mote_sprite, 0,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE | NJD_SPRITE_COLOR);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
static void dispKnuEffectChargeUpStay(struct task *task)
{
    struct mote_work *work = ((struct mote_work *)(task)->work);
    KnuEffectDrawTsubu(&work->pos, (1.0F - work->age) * work->alpha);
}

/* the copy a mote leaves, which fades out over about 6 steps */
void FUN_8c0cb354(struct task *task)
{
    struct mote_work *work = MOTE(task);

    /* @hack spelling: age added to inside the test, which compares the sum in
     * FR2 and stores it in the BT/S's slot (0x8c0d3db6, 0x8c0d3dba). added
     * apart, SHC loads age back, and 22 of 27 words differ */
    if ((work->age += 1.0F / (0.1F * 60.0F)) >= 1.0F) {
        FreeTask(task);
        return;
    }
    KnuEffectDrawTsubu(&work->pos, (1.0F - work->age) * work->alpha);
}

/* a mote, which circles player 0 for about 18 steps as it fades, and
 * leaves a copy each step. it ends once player 0 is gone */
void KnuEffectChargeUp(struct task *task)
{
    struct mote_work *work = MOTE(task);
    struct task_work *player;
    struct task *child;
    Float alpha;

    /* @hack spelling: age added to inside the test, which compares the sum in
     * FR2 and stores it in the BF/S's slot (0x8c0d3df2, 0x8c0d3df6). added
     * apart, SHC loads age back, and 19 of 91 words differ */
    if ((work->age += 1.0F / (0.3F * 60.0F)) >= 1.0F) {
        FreeTask(task);
        return;
    }
    player = playertwp[0];
    if (player == NULL) {
        FreeTask(task);
        return;
    }
    work->ang += work->turn;
    work->pos.x = (work->radius * njCos(work->ang)) + player->pos.x;
    work->pos.y = work->height + player->pos.y;
    work->pos.z = (work->radius * njSin(work->ang)) + player->pos.z;
    alpha = work->alpha * (1.0F - work->age);
    KnuEffectDrawTsubu(&work->pos, alpha);
    if ((child = CreateElementalTask(0x2, 6, FUN_8c0cb354)) != ((void *)0)) {
        ((struct mote_work *)(child)->work)->pos = work->pos;
        ((struct mote_work *)(child)->work)->alpha = alpha;
        child->draw = dispKnuEffectChargeUpStay;
    }
}

void KnuEffectPutChargeUp(Float charge)
{
    struct task *task;
    struct task_work *player;
    Angle turn;

    player = playertwp[0];
    if (player == NULL) {
        return;
    }
    if ((task = CreateElementalTask(0x2, 6, KnuEffectChargeUp)) ==
        ((void *)0)) {
        return;
    }
    turn = (Angle)(charge * 4096.0F) + 16;
    if (rand() * RAND_SCALE < 0.5F) {
        turn = -turn;
    }
    ((struct mote_work *)(task)->work)->height =
        (rand() * (1.0F / (32767 + 1)) * 8.0F) + 1.0F;
    ((struct mote_work *)(task)->work)->radius =
        (rand() * (1.0F / (32767 + 1)) * 2.5F) + 2.5F;
    ((struct mote_work *)(task)->work)->ang =
        (Angle)(rand() * (1.0F / (32767 + 1)) * 65536.0F);
    ((struct mote_work *)(task)->work)->turn = turn;
    ((struct mote_work *)(task)->work)->alpha = charge;
    task->draw = dispKnuEffectChargeUpStay;
}

void KnuEffectComboFire(NJS_POINT3 *pos, struct angles *ang, Float frame)
{
    Float alpha;

    if (frame < 25.0F) {
        alpha = (frame - 20.0F) * 0.15F;
    } else {
        alpha = (30.0F - frame) * 0.15F;
    }
    if (loop_count == 0) {
        SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
        njPushMatrix(NULL);
        njTranslateV(NULL, pos);
        TURN(njRotateZ, ang->z);
        TURN(njRotateX, ang->x);
        TURN(njRotateY, NJM_DEG_ANG(180) - ang->y);
        TURN(njRotateX, (Angle)(frame * 6553.6F));
        njScale(NULL, 1.0F, 2.0F, 2.0F);
        njSetTexture_jp(&texlist_knu_eff);
        late_DrawObject(&knuckles_swing_object);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}

void KnuEffectPutChargeComp(NJS_POINT3 *pos, Float pulse)
{
    Float size;
    Float alpha;

    if (loop_count != 0) {
        return;
    }
    knuckles_aura_object->model->mats->attr_texId = 1;
    alpha = -(pulse * 0.6F);
    SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
    njPushMatrix(NULL);
    njTranslateV(NULL, pos);
    /* @hack redundant: the square times 1.0F, which SHC multiplies by the
     * 1.0F in FR14 (FMUL FR14,FR3 at 0x8c0d412e). without it, 48 of 85 words
     * differ */
    size = 2.0F - (pulse * pulse * 1.0F);
    njScale(NULL, size, size, size);
    TURN(njRotateY, (Angle)(pulse * 262144.0F));
    njSetTexture_jp(&texlist_knu_eff);
    late_DrawObject(knuckles_aura_object);
    late_DrawObjectClipEx(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
void KnuEffectChargeScl(struct task *task)
{
    struct pulse_work *work = ((struct pulse_work *)(task)->work);
    struct task_work *player;
    if ((player = playertwp[0]) == ((void *)0) ||
        (work->age += work->speed) >= 1.0F) {
        FreeTask(task);
        return;
    }
    FUN_8c0cb7b0(task);
}

/* a pulse of the aura round player 0. it ends once age reaches 1, or once
 * player 0 is gone */
void FUN_8c0cb7b0(struct task *task)
{
    struct pulse_work *work = PULSE(task);
    struct task_work *player;
    Float scale;
    Float alpha;
    if ((player = playertwp[0]) == ((void *)0)) {

        return;
    }
    if (loop_count == 0) {
        knuckles_aura_object->model->mats->attr_texId = 2;
        scale = work->scale_from +
                ((work->scale_to - work->scale_from) * work->age);
        alpha = work->alpha_from +
                ((work->alpha_to - work->alpha_from) * work->age);
        SetMaterial(alpha, 1.0F, 1.0F, 1.0F);
        njPushMatrix(NULL);
        njTranslateV(NULL, &player->collision->shapes->center);
        njScale(NULL, scale, scale, scale);
        njSetTexture_jp(&texlist_knu_eff);
        late_DrawObject(knuckles_aura_object);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}

void FUN_8c0cb8a0(void)
{
    struct task *task;
    struct pulse_work *work;
    if ((task = CreateElementalTask(0x2, 6, KnuEffectChargeScl)) !=
        ((void *)0)) {
        work = ((struct pulse_work *)(task)->work);
        work->speed = 1.0F / (0.3F * 60.0F);
        work->scale_from = 6.0F;
        work->scale_to = 1.2F;
        work->alpha_from = 0.0F;
        work->alpha_to = -1.0F;
        task->draw = FUN_8c0cb7b0;
    }
}

void KnuEffectPutCharge1(void)
{
    struct task *task;
    struct pulse_work *work;
    if ((task = CreateElementalTask(0x2, 6, KnuEffectChargeScl)) !=
        ((void *)0)) {
        work = ((struct pulse_work *)(task)->work);
        work->speed = 1.0F / (0.4F * 60.0F);
        work->scale_from = 0.6F;
        work->scale_to = 4.5F;
        work->alpha_from = 0.0F;
        work->alpha_to = -1.0F;
        task->draw = FUN_8c0cb7b0;
    }
}

void knuckles_trail_clear(void)
{
    trail.count = 0;
}
#ifdef NON_MATCHING

/* add a ring of radius 5 round a point 7.5 behind work and 7.5 above it,
 * turned by work's angles. then draw a red strip from each ring to the next.
 * the trail is faint at both ends and brightest a fifth of the way back */
void knuckles_trail_draw(struct task_work *work)
{
    int i;
    Angle turn;
    NJS_POINT3 *point;
    NJS_COLOR *color;
    Float fade;

    i = trail.count;
    if (i > TRAIL_RINGS - 1) {
        i = TRAIL_RINGS - 1;
    }
    for (; i > 0; i--) {
        trail.rings[i] = trail.rings[i - 1];
    }
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, NJM_DEG_ANG(180) - work->ang.y);
    /* @hack spelling: a bare scope for spoke and out, whose frame bytes
     * col's block below reuses (ADD #-28,R15 at 0x8c0d43b8). declared at the
     * top, they keep their own bytes, the frame takes 32, and 21 of 418
     * words differ */
    {
        NJS_VECTOR spoke;
        NJS_VECTOR out;

        for (i = 0, turn = 0; i < TRAIL_POINTS; i++, turn += NJM_DEG_ANG(45)) {
            spoke.x = -7.5F;
            spoke.y = njSin(turn) * 5.0F;
            spoke.z = njCos(turn) * 5.0F;
            njCalcVector(NULL, &spoke, &out);
            njAddVector(&out, &work->pos);
            out.y += 7.5F;
            trail.rings[0].points[i] = out;
        }
    }
    late_DrawObjectClipEx(1);
    /* @hack spelling: count stepped inside the test, which tests R3 and stores
     * it in the BF/S's slot (CMP/GT R4,R3 at 0x8c0d458a). stepped apart, SHC
     * tests a copy, and 86 of 418 words differ */
    if (++trail.count > TRAIL_RINGS) {
        trail.count = TRAIL_RINGS;
    }
#ifdef GCC
    /* no callback draws the trail for the second picture's pass, so step 1
     * draws it for that picture where port.h's FRAME_DRAWS says. where it
     * says not, the trail shows in the first picture alone */
    if (FRAME_DRAWS()) {
#else
    if (loop_count == 0) {
#endif
        NJS_COLOR col;
        int j;

#ifdef GCC
        present_untimed(TRUE);
#endif
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        for (i = 0; i < trail.count - 1; i++) {
            fade = (Float)i / (Float)trail.count;
            if (fade < 0.2F) {
                fade *= 0.5F / 0.2F;
            } else {
                fade = (1.0F - fade) * (0.5F / (1.0F - 0.2F));
            }
            col.argb.a = (Uint8)(fade * 256.0F);
            col.argb.r = 0xff;
            col.argb.b = col.argb.g = 0;
            point = trail_points;
            color = trail_colors;
            /* @hack type: the next ring's index cast to a short, which SHC
             * works out from i + 1 in a register of its own (ADD #1,R9 at
             * 0x8c0d4634, EXTS.W R9,R9 at 0x8c0d465c). uncast, 217 of 418
             * words differ */
            for (j = 0; j < TRAIL_POINTS; j++) {
                *point++ = trail.rings[i].points[j];
                *point++ = trail.rings[(Sint16)(i + 1)].points[j];
                *color++ = col;
                *color++ = col;
            }
            *point++ = trail.rings[i].points[0];
            *point = trail.rings[(Sint16)(i + 1)].points[0];
            *color++ = col;
            *color = col;
            njDrawTriangle3D(&trail_strip, STRIP_TRIANGLES,
                             NJD_TRANSPARENT | NJD_FILL | NJD_DRAW_CONNECTED);
        }
        njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                               NJD_COLOR_BLENDING_BOTHSRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_BOTHSRCALPHA);
#ifdef GCC
        present_untimed(FALSE);
#endif
    }
}
#else
void knuckles_trail_draw(struct task_work *work)
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
    asm_stub[0] = 32;
    asm_stub[1] = 33;
    asm_stub[2] = 34;
    asm_stub[3] = 35;
    asm_stub[4] = 36;
    asm_stub[5] = 37;
    asm_stub[6] = 38;
    asm_stub[7] = 39;
    asm_stub[0] = 40;
    asm_stub[1] = 41;
    asm_stub[2] = 42;
    asm_stub[3] = 43;
    asm_stub[4] = 44;
    asm_stub[5] = 45;
    asm_stub[6] = 46;
    asm_stub[7] = 47;
    asm_stub[0] = 48;
    asm_stub[1] = 49;
    asm_stub[2] = 50;
    asm_stub[3] = 51;
    asm_stub[4] = 52;
    asm_stub[5] = 53;
    asm_stub[6] = 54;
    asm_stub[7] = 55;
    asm_stub[0] = 56;
    asm_stub[1] = 57;
    asm_stub[2] = 58;
    asm_stub[3] = 59;
    asm_stub[4] = 60;
    asm_stub[5] = 61;
    asm_stub[6] = 62;
    asm_stub[7] = 63;
    asm_stub[0] = 64;
    asm_stub[1] = 65;
    asm_stub[2] = 66;
    asm_stub[3] = 67;
    asm_stub[4] = 68;
    asm_stub[5] = 69;
    asm_stub[6] = 70;
    asm_stub[7] = 71;
    asm_stub[0] = 72;
    asm_stub[1] = 73;
    asm_stub[2] = 74;
    asm_stub[3] = 75;
    asm_stub[4] = 76;
    asm_stub[5] = 77;
    asm_stub[6] = 78;
    asm_stub[7] = 79;
    asm_stub[0] = 80;
    asm_stub[1] = 81;
    asm_stub[2] = 82;
    asm_stub[3] = 83;
    asm_stub[4] = 84;
    asm_stub[5] = 85;
    asm_stub[6] = 86;
    asm_stub[7] = 87;
    asm_stub[0] = 88;
    asm_stub[1] = 89;
    asm_stub[2] = 90;
    asm_stub[3] = 91;
    asm_stub[4] = 92;
    asm_stub[5] = 93;
    asm_stub[6] = 94;
    asm_stub[7] = 95;
    asm_stub[0] = 96;
    asm_stub[1] = 97;
    asm_stub[2] = 98;
    asm_stub[3] = 99;
    asm_stub[4] = 100;
    asm_stub[5] = 101;
    asm_stub[6] = 102;
    asm_stub[7] = 103;
    asm_stub[0] = 104;
    asm_stub[1] = 105;
    asm_stub[2] = 106;
    asm_stub[3] = 107;
    asm_stub[4] = 108;
    asm_stub[5] = 109;
    asm_stub[6] = 110;
    asm_stub[7] = 111;
    asm_stub[0] = 112;
    asm_stub[1] = 113;
    asm_stub[2] = 114;
    asm_stub[3] = 115;
    asm_stub[4] = 116;
    asm_stub[5] = 117;
    asm_stub[6] = 118;
    asm_stub[7] = 119;
    asm_stub[0] = 120;
    asm_stub[1] = 121;
    asm_stub[2] = 122;
    asm_stub[3] = 123;
    asm_stub[4] = 124;
    asm_stub[5] = 125;
    asm_stub[6] = 126;
    asm_stub[7] = 127;
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
    asm_stub[0] = 32;
    asm_stub[1] = 33;
    asm_stub[2] = 34;
    asm_stub[3] = 35;
    asm_stub[4] = 36;
    asm_stub[5] = 37;
    asm_stub[6] = 38;
    asm_stub[7] = 39;
    asm_stub[0] = 40;
    asm_stub[1] = 41;
    asm_stub[2] = 42;
    asm_stub[3] = 43;
    asm_stub[4] = 44;
    asm_stub[5] = 45;
    asm_stub[6] = 46;
    asm_stub[7] = 47;
    asm_stub[0] = 48;
    asm_stub[1] = 49;
    asm_stub[2] = 50;
    asm_stub[3] = 51;
    asm_stub[4] = 52;
    asm_stub[5] = 53;
    asm_stub[6] = 54;
    asm_stub[7] = 55;
    asm_stub[0] = 56;
    asm_stub[1] = 57;
    asm_stub[2] = 58;
    asm_stub[3] = 59;
    asm_stub[4] = 60;
    asm_stub[5] = 61;
    asm_stub[6] = 62;
    asm_stub[7] = 63;
    asm_stub[0] = 64;
    asm_stub[1] = 65;
    asm_stub[2] = 66;
    asm_stub[3] = 67;
    asm_stub[4] = 68;
    asm_stub[5] = 69;
    asm_stub[6] = 70;
    asm_stub[7] = 71;
    asm_stub[0] = 72;
    asm_stub[1] = 73;
    asm_stub[2] = 74;
    asm_stub[3] = 75;
    asm_stub[4] = 76;
    asm_stub[5] = 77;
    asm_stub[6] = 78;
    asm_stub[7] = 79;
    asm_stub[0] = 80;
    asm_stub[1] = 81;
    asm_stub[2] = 82;
    asm_stub[3] = 83;
    asm_stub[4] = 84;
    asm_stub[5] = 85;
    asm_stub[6] = 86;
    asm_stub[7] = 87;
    asm_stub[0] = 88;
    asm_stub[1] = 89;
    asm_stub[2] = 90;
    asm_stub[3] = 91;
    asm_stub[4] = 92;
    asm_stub[5] = 93;
    asm_stub[6] = 94;
    asm_stub[7] = 95;
    asm_stub[0] = 96;
    asm_stub[1] = 97;
    asm_stub[2] = 98;
    asm_stub[3] = 99;
    asm_stub[4] = 100;
    asm_stub[5] = 101;
    asm_stub[6] = 102;
    asm_stub[7] = 103;
    asm_stub[0] = 104;
    asm_stub[1] = 105;
    asm_stub[2] = 106;
    asm_stub[3] = 107;
    asm_stub[4] = 108;
    asm_stub[5] = 109;
    asm_stub[6] = 110;
    asm_stub[7] = 111;
}
#endif
