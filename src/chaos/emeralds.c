/* @unit 8C0F23C0-8C0F2860 +egflags +r04 +pool32 */
/* the Chaos Emeralds that circle a Chaos and fly home */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "chaos/emeralds.h"
#include "chaos/models.h" /* NOLINT(misc-include-cleaner) */
#include "chaos/steer.h"
#include "draw/motion.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/util.h"
float njFloor(float x);
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
void FUN_8c0f270a(void);
struct task *FUN_8c0f2780(NJS_POINT3 *home, int slot);
extern NJS_TEXLIST texlist_chaos_effect;
extern Sint8 chaos_reqmode;
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
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

#define EMERALD_SLOTS 7
/* each emerald's sprites: three glints, one after another */
#define EMERALD_GLINTS 3
/* the steps each glint shows for */
#define GLINT_STEPS 3
/* an emerald grows, and shrinks, by 1 / SCALE_PARTS of its full scale a
 * step. SHC folds 1.0F / SCALE_PARTS to 0x3d888888 (0x8c0fd8c8), the float
 * just below 1/15, so the grow takes 16 steps, to about 16/15 of the full
 * scale, and the shrink from there 16 */
#define SCALE_PARTS 15.0F
/* how far an emerald flies each step. SHC folds 0.3F * 3.0F to the float
 * just below 0.9F, which 0.9F would not give */
#define EMERALD_SPEED (0.3F * 3.0F)

#define VARS(work) ((struct emerald_vars *)&(work)->vars)
enum emerald_mode {
    EMERALD_INIT,
    EMERALD_GROW, /* where it starts */
    EMERALD_CIRCLE, /* round the boss, until chaos_emerald_return_all */
    EMERALD_RETURN, /* to where it started */
    EMERALD_SHRINK /* there, then end */
};

struct emerald_vars {
    Float scale;
    Sint16 tick; /* the steps its glint has shown for */
    Sint16 glint; /* which of its glints shows */
    /* its first sprite's index: its slot times EMERALD_GLINTS */
    /* @hack type: an array of one, which SHC reads through the member's
     * address (MOV R14,R5 and ADD #16,R5 at 0x8c0fd74c in
     * chaos_emerald_draw); as a plain Sint8, chaos_emerald_step runs 2 bytes
     * short and, summed over the three functions that use it, 152 of 442
     * words differ */
    Sint8 sprite[1];
};

/* an emerald task's extra */
struct emerald {
    Angle ang; /* its angle round the boss */
    Float radius;
    Float height;
    Float bob; /* how far it rises and falls */
    Angle bob_ang;
    NJS_POINT3 *home;
};
extern NJS_SPRITE chaos_emerald_sprite;
extern NJS_ARGB chaos_emerald_color;
extern struct task *chaos_emerald_slots[7];

/* on a frame's first step, draw the emerald's glint, added over what's
 * behind it */
static void chaos_emerald_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (loop_count) {
        return;
    }
    chaos_emerald_color.a = 0.5F;
    njSetConstantMaterial(&chaos_emerald_color);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    chaos_emerald_sprite.sx = chaos_emerald_sprite.sy = VARS(work)->scale;
    njDrawSprite3D(&chaos_emerald_sprite,
                   VARS(work)->glint + VARS(work)->sprite[0],
                   NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE);
    late_DrawObjectClipEx(1);
}

/* each step, the emerald flies EMERALD_SPEED toward where its mode takes
 * it, or all the way when that is nearer. then it draws itself */
static void chaos_emerald_step(struct task *task)
{
    struct task_work *work = task->work;
    struct emerald *emerald = task->extra;
    NJS_POINT3 to;
    NJS_POINT3 way;
    Float distance;
    Float scale;

    switch (work->mode) {
    case EMERALD_INIT:
        /* @hack type: the tick and the glint cleared in one store,
         * MOV.L R11,@(12,R14) at 0x8c0fd7c0; as two, the function runs 4
         * bytes long and 92 of 326 words differ */
        work->vars.l[1] = 0;
        VARS(work)->scale = 0.0F;
        way = *emerald->home;
        njSubVector(&way, &boss_work->pos);
        emerald->ang = (Angle)(njArcTan2(way.z, way.x) * ANGLE_PER_RADIAN);
        emerald->radius = njSqrt((way.x * way.x) + (way.z * way.z));
        emerald->height = work->pos.y + chaos_params->orbit_height;
        emerald->bob = way.y * 0.2F;
        emerald->bob_ang = 0;
        task->draw = chaos_emerald_draw;
        work->mode = EMERALD_GROW;
        /* fall through */
    case EMERALD_GROW:
        to = *emerald->home;
        VARS(work)->scale += 1.0F / SCALE_PARTS;
        if (VARS(work)->scale >= 1.0F) {
            work->mode = EMERALD_CIRCLE;
        }
        break;
    case EMERALD_CIRCLE:
        VARS(work)->tick++;
        if (VARS(work)->tick >= GLINT_STEPS) {
            VARS(work)->tick = 0;
            VARS(work)->glint++;
            if (VARS(work)->glint >= EMERALD_GLINTS) {
                VARS(work)->glint = 0;
            }
        }
        emerald->ang += NJM_DEG_ANG(1);
        to.x = boss_work->pos.x + (njCos(emerald->ang) * emerald->radius);
        to.z = boss_work->pos.z + (njSin(emerald->ang) * emerald->radius);
        emerald->radius = emerald->radius + 1.0F < chaos_params->orbit_radius
                              ? emerald->radius + 1.0F
                              : chaos_params->orbit_radius;
        to.y = emerald->height + (emerald->bob * njSin(emerald->bob_ang));
        emerald->bob_ang += 0xc00;
        break;
    case EMERALD_RETURN:
        to = *emerald->home;
        /* @hack spelling: the distance through a local, which copies
         * njDistanceP2P's result to FR4 (FMOV.S FR0,FR4 at 0x8c0fd994); in
         * the test, it is compared in FR0, emeralds.c's code runs 32 bytes
         * short and 127 of 326 words differ */
        distance = CalcDistance(&to, &work->pos);
        if (distance < 2.0F * EMERALD_SPEED) {
            work->mode = EMERALD_SHRINK;
        }
        break;
    case EMERALD_SHRINK:
        to = *emerald->home;
        VARS(work)->scale -= 1.0F / SCALE_PARTS;
        if (VARS(work)->scale <= 0.0F) {
            chaos_emerald_slots[VARS(work)->sprite[0] / EMERALD_GLINTS] = NULL;
            FreeTask(task);
            return;
        }
        break;
    }
    way = to;
    njSubVector(&way, &work->pos);
    scale = EMERALD_SPEED /
            (njScalor(&way) < EMERALD_SPEED ? EMERALD_SPEED : njScalor(&way));
    way.x *= scale;
    way.y *= scale;
    way.z *= scale;
    njAddVector(&work->pos, &way);
    chaos_emerald_draw(task);
}

void FUN_8c0f270a(void)
{
    int i;

    for (i = 0; i < EMERALD_SLOTS; i++) {
        chaos_emerald_slots[i] = NULL;
    }
}

struct task *FUN_8c0f2780(NJS_POINT3 *home, int slot)
{
    struct task *task;
    struct task_work *work;
    struct emerald *emerald;

    if (chaos_emerald_slots[slot] != NULL) {
        DestroyTask(chaos_emerald_slots[slot]);
    }
    task = CreateElementalTask(TASK_WORK | TASK_MOTION, 2, chaos_emerald_step);
    if (task != NULL) {
        work = task->work;
        task->extra = MAlloc(sizeof(struct emerald));
        work->pos = *home;
        VARS(work)->sprite[0] = slot * EMERALD_GLINTS;
        emerald = task->extra;
        emerald->home = home;
        chaos_emerald_slots[slot] = task;
    }
    return task;
}

void chaos_emerald_return_all(void)
{
    struct task *task;
    int i;

    for (i = 0; i < EMERALD_SLOTS; i++) {
        task = chaos_emerald_slots[i];
        if (task != ((void *)0) && task->work != ((void *)0) &&
            task->work->mode != EMERALD_SHRINK) {
            task->work->mode = EMERALD_RETURN;
        }
    }
}
