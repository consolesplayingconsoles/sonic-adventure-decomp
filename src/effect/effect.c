/* @unit 8C043C00-8C0445A0 +r04 +egflags +pool32 */
/* the barriers and the invincibility a player wears */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "draw/draw.h"
#include "effect/effect.h"
#include "player/player.h"
#include "sound/sound.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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

/* the barriers' sound as they start */
#define SE_BARRIER 6

/* the count on the last of the 1261 steps invincibility lasts. the step
 * that finds its count past this ends it. at the main loop's 60 steps a
 * second, it lasts about 21 seconds */
#define INVINCIBLE_LAST 1260

/* the last of the eleven steps a magnetic spark takes a new bolt and flash
 * on */
#define BOLT_LAST 10

/* a player effect's vars. the effect follows player, but reads the effects
 * worn and the height from player 0's record */
#define EFFECT(work) ((struct effect_vars *)&(work)->vars)
#define SPARK(work) ((struct spark_vars *)&(work)->vars)
struct effect_vars {
    /* the player's slot, which player_give_barrier and the like set */
    Uint8 player;
    Uint8 unk_01[3];
    Sint32 timer; /* invincibility's steps so far */
};

/* a magnetic barrier's spark */
struct spark_vars {
    Uint8 bolt; /* which half of which lightning texture */
    Uint8 flash; /* which texture the shell flashes */
    Uint8 unk_02[6];
    Float fade; /* how bright it still is, from 1 */
};

extern NJS_MODEL magnetic_spark_model;
extern NJS_MODEL barrier_spark_model;
extern NJS_MODEL invincibility_spark_model;
extern NJS_MODEL invincibility_ball_model;

void magnetic_barrier_step(struct task *task);
void magnetic_spark_step(struct task *task);
void magnetic_spark_draw(struct task *task);
void magnetic_barrier_destroy(struct task *task);
void ObjectJammer(struct task *task);
void barrier_spark_step(struct task *task);
void barrier_spark_draw(struct task *task);
void invincibility_destroy(struct task *task);
void invincibility_draw(struct task *task);
void invincibility_step(struct task *task);
void invincibility_spark_step(struct task *task);
void invincibility_spark_draw(struct task *task);
extern NJS_TEXLIST bolt_textures[9];
extern NJS_TEXLIST flash_textures[4];
extern NJS_TEXLIST barrier_spark_textures[15];
extern NJS_TEXLIST invincibility_spark_textures[8];
extern NJS_TEXLIST invincibility_ball_texture;
extern NJS_POINT3 bolt_points[4];
extern NJS_COLOR bolt_colors[4];

/* place the effect on player, at the player's x scale. it sits up the
 * player's tilted axis, at 0.6 of player 0's height times that scale. scl.y
 * keeps that offset */
void follow_player(struct task_work *work, struct task_work *player)
{
    NJS_POINT3 origin;

    origin.x = origin.y = origin.z = 0.0F;
    work->scl.x = player->scl.x;
    work->scl.y = GetPlayerWorkPointer(0)->consts.height * work->scl.x * 0.6F;
    njPushMatrix(&nj_unit_matrix_);
    njTranslateV(NULL, &player->pos);
    TURN(njRotateZ, player->ang.z);
    TURN(njRotateX, player->ang.x);
    njTranslate(NULL, 0.0F, work->scl.y, 0.0F);
    njCalcPoint(NULL, &origin, &work->pos);
    late_DrawObjectClipEx(1);
}

void magnetic_barrier_start(struct task *task)
{
    dsPlay_oneshot(SE_BARRIER, 0, 0, 0);
    task->destructor = magnetic_barrier_destroy;
    task->step = magnetic_barrier_step;
    magnetic_barrier_step(task);
}

void magnetic_barrier_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[EFFECT(work)->player];
    struct task *child;
    struct task_work *spark;

    if (player == NULL ||
        !(GetPlayerWorkPointer(0)->effects & PLAYER_MAGNETIC_BARRIER)) {
        FreeTask(task);
        return;
    }
    follow_player(work, player);
    if (rand() * RAND_SCALE > 0.7F) {
        if ((child = CreateChildTask(TASK_WORK, magnetic_spark_step, task)) !=
            NULL) {
            spark = child->work;
            spark->ang.x = RANDOM_ANGLE();
            spark->ang.y = RANDOM_ANGLE();
            SPARK(spark)->fade = 1.0F;
            child->draw = magnetic_spark_draw;
        }
    }
    LoopTaskC(task);
}

/* a spark takes a new bolt and flash each step up to BOLT_LAST. then it
 * fades from half bright by 0.025 a step, and goes once dark */
void magnetic_spark_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *parent = task->parent->work;

    if (work->tick++ > BOLT_LAST) {
        /* @hack redundant: the else after the return, which loads the fade into
         * FR2 (0x8c046aa4, 0x8c046aa6); as two ifs, FR3, and 2 of 82 words
         * differ */
        if (SPARK(work)->fade <= 0.0F) {
            FreeTask(task);
            return;
        } else if (SPARK(work)->fade > 0.5F) {
            SPARK(work)->fade = 0.5F;
        }
        SPARK(work)->fade -= 0.025F;
    } else {
        SPARK(work)->bolt = rand() * (16.0F * RAND_SCALE);
        SPARK(work)->flash = rand() * (3.0F * RAND_SCALE);
    }
    work->pos = parent->pos;
    work->scl.x = parent->scl.y * 0.2F;
    magnetic_spark_draw(task);
}

/* a patch of the shell flashes, darker as it fades, and a bolt reaches up
 * to it */
void magnetic_spark_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3COL card;
    NJS_COLOR uv[4];
    Float shade;
    int texture;
    int left;
    Uint8 bright;

    if (loop_count != 0) {
        return;
    }
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njPushMatrix(NULL);
    shade = SPARK(work)->fade - 1.0F;
    SetMaterial(0.0F, shade, shade, shade);
    texture = SPARK(work)->flash;
    njSetTexture_jp(&flash_textures[texture]);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateX, work->ang.x);
    njScale(NULL, work->scl.x, work->scl.x, work->scl.x);
    njSimpleDrawModel(&magnetic_spark_model);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    card.p = bolt_points;
    card.col = bolt_colors;
    card.tex = uv;
    card.num = 4;
    if (SPARK(work)->bolt & 1) {
        left = 128;
    } else {
        left = 0;
    }
    uv[0].tex.u = left;
    uv[0].tex.v = 0;
    uv[1].tex.u = left + 127;
    uv[1].tex.v = 0;
    uv[2].tex.u = left;
    uv[2].tex.v = 255;
    uv[3].tex.u = left + 127;
    uv[3].tex.v = 255;
    bright = SPARK(work)->fade * 255.0F;
    bolt_colors[0].argb.b = bolt_colors[0].argb.g = bolt_colors[0].argb.r =
        bright;
    bolt_colors[1].argb.b = bolt_colors[1].argb.g = bolt_colors[1].argb.r =
        bright;
    bolt_colors[2].argb.b = bolt_colors[2].argb.g = bolt_colors[2].argb.r =
        bright;
    bolt_colors[3].argb.b = bolt_colors[3].argb.g = bolt_colors[3].argb.r =
        bright;
    texture = SPARK(work)->bolt / 2;
    njSetTexture_jp(&bolt_textures[texture]);
    njSetTextureNum_jp(0);
    njDrawTriangle3D(&card, 2,
                     NJD_USE_TEXTURE | NJD_TRANSPARENT | NJD_FILL |
                         NJD_DRAW_CONNECTED);
    late_DrawObjectClipEx(1);
}

void magnetic_barrier_destroy(struct task *task)
{
}

void barrier_start(struct task *task)
{
    dsPlay_oneshot(SE_BARRIER, 0, 0, 0);
    task->destructor = invincibility_destroy;
    task->step = ObjectJammer;
    ObjectJammer(task);
}

void ObjectJammer(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[EFFECT(work)->player];
    struct task *child;
    struct task_work *spark;

    if (player == NULL ||
        !(GetPlayerWorkPointer(0)->effects & PLAYER_BARRIER)) {
        FreeTask(task);
        return;
    }
    follow_player(work, player);
    if (rand() * RAND_SCALE > 0.7F) {
        if ((child = CreateChildTask(TASK_WORK, barrier_spark_step, task)) !=
            NULL) {
            spark = child->work;
            spark->ang.x = RANDOM_ANGLE();
            spark->ang.y = RANDOM_ANGLE();
            child->draw = barrier_spark_draw;
        }
    }
    LoopTaskC(task);
}

void barrier_spark_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *parent = task->parent->work;

    if (work->tick >= 30) {
        FreeTask(task);
        return;
    }
    work->pos = parent->pos;
    work->scl.x = parent->scl.y * 0.2F;
    barrier_spark_draw(task);
    work->tick++;
}

void barrier_spark_draw(struct task *task)
{
    struct task_work *work = task->work;
    int frame;

    if (loop_count != 0) {
        return;
    }
    njPushMatrix(NULL);
    frame = work->tick >> 1;
    njSetTexture_jp(&barrier_spark_textures[frame]);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateX, work->ang.x);
    njScale(NULL, work->scl.x, work->scl.x, work->scl.x);
    njSimpleDrawModel(&barrier_spark_model);
    late_DrawObjectClipEx(1);
}

void invincibility_destroy(struct task *task)
{
}

void invincibility_start(struct task *task)
{
    task->destructor = invincibility_destroy;
    /* @hack redundant: a store of the draw that the next store overwrites,
     * which SHC deletes but whose load it keeps (MOV.L at 0x8c046faa);
     * without it, the function runs 2 bytes short and 3 of 6 words differ */
    task->step = invincibility_draw;
    task->step = invincibility_step;
    invincibility_step(task);
}

void invincibility_draw(struct task *task)
{
    struct task_work *work = task->work;

#ifdef GCC
    /* the task has no callback for the second picture's pass, so step 1
     * draws the ball for that picture where port.h's FRAME_DRAWS says.
     * where it says not, the ball shows in the first picture alone */
    if (!FRAME_DRAWS()) {
        return;
    }
    present_untimed(TRUE);
#else
    if (loop_count != 0) {
        return;
    }
#endif
    njPushMatrix(NULL);
    njSetTexture_jp(&invincibility_ball_texture);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateX, work->ang.x);
    njScale(NULL, work->scl.x, work->scl.x, work->scl.x);
    njSimpleDrawModel(&invincibility_ball_model);
    late_DrawObjectClipEx(1);
#ifdef GCC
    present_untimed(FALSE);
#endif
}

void invincibility_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[EFFECT(work)->player];
    struct player *record = GetPlayerWorkPointer(0);
    struct task *child;
    struct task_work *spark;
    int i;

    if (player == NULL || EFFECT(work)->timer++ > INVINCIBLE_LAST) {
        record->effects &= ~PLAYER_INVINCIBLE;
        FreeTask(task);
        return;
    }
    record->effects |= PLAYER_INVINCIBLE;
    follow_player(work, player);
    for (i = 0; i < 3; i++) {
        if (rand() * RAND_SCALE > 0.7F) {
            if ((child = CreateChildTask(TASK_WORK, invincibility_spark_step,
                                         task)) != NULL) {
                spark = child->work;
                spark->ang.x = RANDOM_ANGLE();
                spark->ang.y = RANDOM_ANGLE();
                child->draw = invincibility_spark_draw;
            }
        }
    }
    invincibility_draw(task);
    LoopTaskC(task);
}

void invincibility_spark_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *parent = task->parent->work;

    if (work->tick >= 32) {
        FreeTask(task);
        return;
    }
    work->pos = parent->pos;
    work->scl.x = parent->scl.y * 0.2F;
    invincibility_spark_draw(task);
    work->tick++;
}

void invincibility_spark_draw(struct task *task)
{
    struct task_work *work = task->work;
    int frame;

    if (loop_count != 0) {
        return;
    }
    njPushMatrix(NULL);
    frame = (work->tick >> 1) & 7;
    njSetTexture_jp(&invincibility_spark_textures[frame]);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateX, work->ang.x);
    njScale(NULL, work->scl.x, work->scl.x, work->scl.x);
    njSimpleDrawModel(&invincibility_spark_model);
    late_DrawObjectClipEx(1);
}
