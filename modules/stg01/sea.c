/* @unit 0C909F20-0C90A820 +r04 +egflags +pool32 +asmfunc=beach_sea_get_height */
/* act 0's sea: a surface that follows player 0, and a grid of points that
 * ripples raise */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/world.h"
#include "draw/tree.h"
#include "player/player.h"
#include "stg01/sea.h"
#include "stg01/sea_surface.h"
#include "system/task.h"
float njArcTan2(float y, float x);
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
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
void CreateBeachWaveBG(int mode);
void DestructBeachWaveBG(void);

/* the grid of points the ripples raise, GRID by GRID, CELL apart, from
 * -GRID_EDGE to GRID_EDGE in x and z about the sea */
#define PLANE_FLAGS (LAND_DRAWN | WORLD_MOVES | WORLD_WATER)
#define STRIDE 25.0F
#define TEXTURE_WAIT 2
#define TEXTURES 10
#define RIPPLES 30
#define PHASE_PER_UNIT 150.0F
#define LIFE 200.0F
#define SPREAD 8.0F
#define FADE 0.985F
#define GRID 26
#define GRID_POINTS (GRID * GRID)
#define CELL 40.0F
#define GRID_EDGE 500.0F
#define SURFACE_SHIFT 2476.0F
#define VARS(work) ((struct beach_sea_vars *)&(work)->vars)
#define TEXTURE(work) ((work)->tick)
#define RIPPLE_FLOATS(r) (((union beach_sea_ripple_floats *)(r))->elements)
extern NJS_OBJECT beach_sea_grid_object;

/* the land draws its own entries that have LAND_DRAWN. it never tests the flag
 * on an object a task adds. sea_surface.c adds the same plane for act 1 without
 * it */

/* the sea follows player 0 in whole strides of this many units in x and z */
/* the texture changes once TASK_TIMER(work) passes TEXTURE_WAIT, every 3
 * steps, through TEXTURES in turn */

/* the most ripples the sea holds at once */
/* a wave's phase moves on PHASE_PER_UNIT angle units for each unit out from
 * its ripple's center. a wave is then 65536 / PHASE_PER_UNIT units long,
 * about 437 */
/* the steps a ripple lasts, the units its ring spreads each step, and what
 * its height keeps of itself each step */

/* with ripples, the surface moves this far along x. its -x edge, 1975.5
 * from its center, then lies just past the grid's +x edge */

struct beach_sea_vars {
    Uint32 ripples; /* the ripples in use, from beach_sea_ripples[0] on */
    NJS_OBJECT *plane; /* the surface's plane, in the collision world */
    Float unk_08; /* init clears it, and nothing reads it */
};

/* tick holds the next texture */

struct beach_sea_ripple {
    Float x; /* x and z: the ripple's center */
    Float z;
    Float height; /* half its waves' amplitude */
    Float radius; /* its ring's outer radius */
    Float width; /* its ring's width, in from radius */
    Float life; /* the steps it has left */
};

/* a ripple, and its floats as an array, so a walk through them stays inside
 * one object */
union beach_sea_ripple_floats {
    struct beach_sea_ripple ripple;
    Float elements[6];
};
extern Float beach_sea_grid_x;
extern Float beach_sea_grid_z;
extern Sint32 dat_0cab1ee0;
extern Sint32 beach_sea_visits;
extern struct beach_sea_ripple beach_sea_ripples[30];

void beach_sea_step(struct task *task);
void beach_sea_draw(struct task *task);
void beach_sea_destroy(struct task *task);
void RippleExec(struct beach_sea_ripple *ripple);
void RippleWave(Float radius, Float width, Float height, Float x, Float z,
                Float min_x, Float min_z, Float max_x, Float max_z);

void beach_sea_init(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 *point;
    NJS_OBJECT *plane;
    int i;

    work->pos.y = SEA_LEVEL;
    work->ang.x = 0;
    work->ang.y = 0;
    work->ang.z = 0;
    TASK_TIMER(work) = 0;
    TEXTURE(work) = 0;
    VARS(work)->ripples = 0;
    work->scl.x = 0.0F;
    VARS(work)->unk_08 = 0.0F;
    point = beach_sea_grid_object.model->points;
    for (i = 0; i < GRID_POINTS; i++) {
        point->y = 0.0F;
        point++;
    }
    dat_0cab1ee0 = 0;
    VARS(work)->plane = plane = GetMobileLandObject();
    plane->evalflags = NJD_EVAL_BREAK;
    plane->scl[0] = 1.0F;
    plane->scl[1] = 1.0F;
    plane->scl[2] = 1.0F;
    plane->ang[0] = 0;
    plane->ang[1] = work->ang.y;
    plane->ang[2] = 0;
    plane->pos[0] = work->pos.x;
    plane->pos[1] = work->pos.y;
    plane->pos[2] = work->pos.z;
    plane->model = beach_sea_surface_plane_object.model;
    plane->child = NULL;
    plane->sibling = NULL;
    RegisterCollisionEntry(PLANE_FLAGS, task, plane);
    work->flags |= WORLD_TESTED;
    task->step = beach_sea_step;
    task->draw = beach_sea_draw;
    task->destructor = beach_sea_destroy;
}

/* move the sea after player 0, flatten the grid, and raise each ripple's
 * ring on it. drop the ripples that run out, then step the texture and
 * draw */
void beach_sea_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 player;
    NJS_POINT3 *point;
    NJS_VECTOR *normal_jp;
    struct beach_sea_ripple *ripple;
    struct beach_sea_ripple *last;
    struct beach_sea_ripple *each;
    NJS_OBJECT *plane;
    int i;
    int count;
    Float x;
    Float z;
    Float player_x;
    Float player_z;
    Float strides_x;
    Float strides_z;
    if ((Uint8)GetStageNumber()) {
        FreeTask(task);
    }
    GetPlayerPosition(0, 0, &player, ((void *)0));
    x = work->pos.x;
    z = work->pos.z;
    /* @hack spelling: player 0's x and z through locals, which SHC copies
     * to frame slots of their own, sp+4 and sp+8 (0x0c90a5b4 to
     * 0x0c90a5c0); read from player where they are used, the frame is 8
     * bytes smaller, x and z trade FR14 and FR15, and 146 of 259 words
     * differ */
    player_x = player.x;
    player_z = player.z;
    strides_x = njRoundOff((player_x - x) * (1.0F / STRIDE));
    strides_z = njRoundOff((player_z - z) * (1.0F / STRIDE));
    x += strides_x * STRIDE;
    z += strides_z * STRIDE;
    work->pos.x = x;
    work->pos.z = z;
    beach_sea_grid_x = x;
    beach_sea_grid_z = z;
    plane = VARS(work)->plane;
    plane->pos[0] = x;
    plane->pos[2] = z;
    point = beach_sea_grid_object.model->points;
    for (i = 0; i < GRID_POINTS; i++) {
        point->y = 0.0F;
        point++;
    }
    beach_sea_visits = 0;
    count = (int)VARS(work)->ripples;
    each = beach_sea_ripples;
    for (i = 0; i < count; i++) {
        RippleExec(each);
        each++;
    }
    point = beach_sea_grid_object.model->points;
    normal_jp = beach_sea_grid_object.model->normals;
    for (i = 0; i < GRID_POINTS; i++) {
        normal_jp->y = 1.0F + (point->y * 0.2F);
        point++;
        normal_jp++;
    }
    /* the last ripple takes the place of each one that runs out */
    count = (int)VARS(work)->ripples;
    /* @hack spelling: with none left, last points one record before
     * beach_sea_ripples: undefined in ISO C, and never read through. the
     * image forms it so (0x0c90a67e to 0x0c90a690, 0x0c90a6cc); kept one
     * past the end and read at last - 1, 20 of 259 words differ */
    last = &beach_sea_ripples[count - 1];
    ripple = beach_sea_ripples;
    for (i = 0; i < count; i++) {
        if (!(ripple->life > 0.0F)) {
            /* @hack redundant: i < count, so this always holds; the image
             * tests it all the same, at 0x0c90a6a0. without it, 40 of 259
             * words differ */
            if (i != count) {
                /* @hack spelling: through pointers, for the image's
                 * post-increment loads (0x0c90a6a6 to 0x0c90a6c0); through
                 * the fields, 66 of 259 words differ */
                Float *from = RIPPLE_FLOATS(last);
                Float *to = RIPPLE_FLOATS(ripple);

                *to++ = *from++;
                *to++ = *from++;
                *to++ = *from++;
                *to++ = *from++;
                *to++ = *from++;
                *to++ = *from++;
            }
            last--;
            i--;
            count--;
        } else {
            ripple++;
        }
    }
    VARS(work)->ripples = count;
    TASK_TIMER(work)++;
    if (TASK_TIMER(work) > TEXTURE_WAIT) {
        TASK_TIMER(work) = 0;
        beach_sea_grid_object.model->mats->attr_texId = TEXTURE(work);
        beach_sea_surface_object.model->mats->attr_texId = TEXTURE(work);
        TEXTURE(work)++;
        TEXTURE(work) %= TEXTURES;
    }
    beach_sea_draw(task);
}

/* draw the surface. with ripples, draw the grid in its place, and the
 * surface SURFACE_SHIFT along x */
void beach_sea_draw(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack spelling: draw_tree through a local, which keeps its address in R14
     * for both calls (0x0c90a7b0, 0x0c90a7c4); without it, each call loads
     * it from the pool, 35 of 39 words differ and the function ends 2 bytes
     * early */
    void (*draw)(NJS_OBJECT *object);

    njSetTexture_jp(&beach_sea_surface_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    draw = late_DrawObject;
    if (VARS(work)->ripples != 0) {
        draw(&beach_sea_grid_object);
        njTranslate(NULL, SURFACE_SHIFT, 0.0F, 0.0F);
    }
    draw(&beach_sea_surface_object);
    late_DrawObjectClipEx(1);
}

void beach_sea_destroy(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *plane = VARS(work)->plane;

    if (plane != NULL) {
        WithdrawCollisionEntry(task, plane);
        ReleaseMobileLandObject(plane);
    }
}

void beach_sea_add_ripple(struct task *sea, Float x, Float z, Float radius,
                          Float width, Float height)
{
    struct task_work *work = sea->work;
    struct beach_sea_ripple *ripple;
    Float length = 65536.0F / PHASE_PER_UNIT;
    Uint32 index;

    if (VARS(work)->ripples < RIPPLES) {
        index = VARS(work)->ripples++;
        ripple = &beach_sea_ripples[index];
        ripple->x = x;
        ripple->z = z;
        ripple->height = height;
        ripple->radius = radius * length;
        ripple->width = width * length;
        ripple->life = LIFE;
    }
}

Float beach_sea_get_height(struct task *sea, Float x, Float z)
{
    struct task_work *work = sea->work;
    struct beach_sea_ripple *ripple;
    int count;
    int i;
    Float height = SEA_LEVEL;
    Float radius;
    Float width;
    Float inner;
    Float distance;
    Float dx;
    Float dz;

    count = (int)VARS(work)->ripples;
    for (i = 0; i < count; i++) {
        ripple = &beach_sea_ripples[i];
        /* @hack spelling: the center copied into dx and dz, which loads it
         * with radius and width, ahead of the subtractions (0x0c90a890 to
         * 0x0c90a89a); subtracted from x and z as it loads, 130 of 166 words
         * differ and the function ends 32 bytes early */
        dx = ripple->x;
        dz = ripple->z;
        radius = ripple->radius;
        width = ripple->width;
        dx = x - dx;
        dz = z - dz;
        /* @hack spelling: the sum in distance, which keeps dx and dz in FR4
         * and FR5 (0x0c90a8a4, 0x0c90a8aa) and 2.0F in FR12 (0x0c90a878);
         * passed to njSqrt as it is, dx and dz take FR15 and FR13, 147 of 166
         * words differ and the function ends 30 bytes early */
        distance = (dx * dx) + (dz * dz);
        distance = njSqrt(distance);
        inner = (radius < width) ? 0.0F : radius - width;
        if (distance > inner && distance < radius) {
            distance -= radius;
            distance *= PHASE_PER_UNIT;
            height += njSin((Angle)distance) * ripple->height * 2.0F;
        }
    }
    return height;
}

/* spread the ripple's ring and raise it on the grid. a ring with no hole
 * takes one box around it. any other takes four boxes, around the square
 * inscribed in its inner circle. then the ripple's height fades, and its
 * life runs down a step */
void RippleExec(struct beach_sea_ripple *ripple)
{
    /* @hack spelling: through a pointer, for the image's post-increment loads
     * (0x0c90a99c to 0x0c90a9aa); through the fields, the function is 10
     * bytes longer and 181 of 191 words differ */
    Float *at = RIPPLE_FLOATS(ripple);
    Float x = *at++;
    Float z = *at++;
    Float height = *at++;
    Float radius = *at++;
    Float width = *at++;
    Float life = *at;
    Float min_x;
    Float min_z;
    Float max_x;
    Float max_z;
    Float inner;
    Float inner_min_x;
    Float inner_min_z;
    Float inner_max_x;
    Float inner_max_z;

    x -= beach_sea_grid_x;
    z -= beach_sea_grid_z;
    radius += SPREAD;
    inner = radius - width;
    /* @hack spelling: the bounds set in each branch, which SHC computes once
     * ahead of the test (0x0c90a9c8 to 0x0c90a9ec) and stores min_z again in
     * each (0x0c90a9f2, 0x0c90aa1e); set once before the test, 175 of 191
     * words differ and the function ends 26 bytes early */
    if (inner <= 0.0F) {
        min_x = x - radius;
        min_z = z - radius;
        max_x = x + radius;
        max_z = z + radius;
        RippleWave(radius, width, height, x, z, min_x, min_z, max_x, max_z);
    } else {
        /* half the side of the square inscribed in the inner circle */
        inner *= 0.707106F;
        min_x = x - radius;
        min_z = z - radius;
        max_x = x + radius;
        max_z = z + radius;
        inner_min_x = x - inner;
        inner_min_z = z - inner;
        inner_max_x = x + inner;
        inner_max_z = z + inner;
        RippleWave(radius, width, height, x, z, min_x, min_z, max_x,
                   inner_min_z);
        RippleWave(radius, width, height, x, z, min_x, inner_min_z + CELL,
                   inner_min_x, inner_max_z - CELL);
        RippleWave(radius, width, height, x, z, inner_max_x, inner_min_z + CELL,
                   max_x, inner_max_z - CELL);
        RippleWave(radius, width, height, x, z, min_x, inner_max_z, max_x,
                   max_z);
    }
    life -= 1.0F;
    height *= FADE;
    ripple->height = height;
    ripple->radius = radius;
    ripple->life = life;
}

/* add the ripple's waves to the grid points in the box from min_x, min_z to
 * max_x, max_z. the box and the ripple's x and z are measured from the
 * grid's center. the box widens to whole cells and stops at the grid's
 * edges. a box wholly past an edge raises nothing */
void RippleWave(Float radius, Float width, Float height, Float x, Float z,
                Float min_x, Float min_z, Float max_x, Float max_z)
{
    Float ix;
    Float iz;
    Float row;
    Float inner;
    Float dx;
    Float dz;
    Float distance;
    NJS_POINT3 *points;
    NJS_POINT3 *point;
    int index;

    if (min_x > GRID_EDGE) {
        return;
    } else if (min_x < -GRID_EDGE) {
        min_x = 0.0F;
    } else {
        min_x *= 1.0F / CELL;
        min_x = njFloor(min_x) + (GRID / 2.0F);
    }
    if (max_x < -GRID_EDGE) {
        return;
    } else if (max_x > GRID_EDGE) {
        max_x = GRID;
    } else {
        max_x *= 1.0F / CELL;
        max_x = ceilf(max_x) + (GRID / 2.0F);
    }
    if (min_z > GRID_EDGE) {
        return;
    } else if (min_z < -GRID_EDGE) {
        min_z = 0.0F;
    } else {
        min_z *= 1.0F / CELL;
        min_z = njFloor(min_z) + (GRID / 2.0F);
    }
    if (max_z < -GRID_EDGE) {
        return;
    } else if (max_z > GRID_EDGE) {
        max_z = GRID;
    } else {
        max_z *= 1.0F / CELL;
        max_z = ceilf(max_z) + (GRID / 2.0F);
    }
    points = beach_sea_grid_object.model->points;
    row = min_x * GRID;
    inner = (radius < width) ? 0.0F : radius - width;
    /* the counters are whole numbers no larger than GRID, exact in a float */
    /* NOLINTNEXTLINE(bugprone-float-loop-counter) */
    for (ix = min_x; ix < max_x; ix += 1.0F) {
        /* NOLINTNEXTLINE(bugprone-float-loop-counter) */
        for (iz = min_z; iz < max_z; iz += 1.0F) {
            index = (int)(iz + row);
            if (index >= 0 && index < GRID_POINTS) {
                point = &points[index];
                dx = point->x - x;
                dz = point->z - z;
                /* @hack spelling: the sum in distance, which keeps dx and dz
                 * in FR5 and FR4 (0x0c90acf6, 0x0c90acfe); passed to njSqrt
                 * as it is, dx takes a frame slot and dz FR15, and 151 of 345
                 * words differ */
                distance = (dx * dx) + (dz * dz);
                distance = njSqrt(distance);
                /* @hack spelling: !! and &, which make both tests, the inner
                 * one first, as the image does: MOVT at 0x0c90ad14 and
                 * 0x0c90ad18. without the !!, the outer test runs first and
                 * 10 of 345 words differ; with &&, 69 */
                if (!!(distance > inner) & !(distance > radius)) {
                    distance -= radius;
                    distance *= PHASE_PER_UNIT;
                    point->y += njSin((Angle)distance) * height * 2.0F;
                }
                beach_sea_visits++;
            }
        }
        row += GRID;
    }
}
