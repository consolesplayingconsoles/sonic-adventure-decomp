/* @unit 8C0D6220-8C0D6700 +egflags +pool32 */
/* the sphere one of E-102's shots leaves where it ends, once his laser has
 * pierced its target. it swells and fades */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "draw/model.h"
#include "player/e102_sphere.h"
#include "player/textures.h" /* NOLINT(misc-include-cleaner) */
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void FUN_8c0d64fa(struct task *task);
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

/* its timer counts down from SPHERE_STEPS. with SPHERE_FADE steps left,
 * its shape turns off, and it fades after that */
#define SPHERE_STEPS 60
#define SPHERE_FADE 30

/* the mesh: BANDS bands from pole to pole. each is a strip of PAIRS pairs
 * of points round the sphere, and its first pair again to close it */
#define BANDS 8
#define PAIRS 8
/* the turn from one band's top edge to the next band's, and from one pair to
 * the next */
#define BAND_ANGLE (0x8000 / BANDS)
#define PAIR_ANGLE (0x10000 / PAIRS)
#define STRIP_POINTS (2 + (2 * PAIRS))

#define VARS(work) ((struct sphere_vars *)&(work)->vars)
enum sphere_mode { SPHERE_INIT, SPHERE_GROW, SPHERE_KILL };

/* in work->vars. work->scl.x is the sphere's size, and work->scl.z its
 * opacity, which sets how open its bands are too */
struct sphere_vars {
    Uint8 unk_00[4];
    Sint32 scroll; /* how far the texture has scrolled in v */
    Float growth; /* added to its size each step */
};

static void e102_sphere_build(void);
static void e102_sphere_scroll(int scroll);
static void e102_sphere_close(Float open);
static void e102_sphere_draw(struct task *task);
extern Float e102_sphere_ring[8 * 2];
extern NJS_POINT3 e102_sphere_points[8 * 8 * 2];
extern NJS_VECTOR e102_sphere_normals[8 * 8 * 2];
extern Sint16 e102_sphere_strips[8 * (1 + (2 + (2 * 8)))];
extern Sint16 e102_sphere_uvs[8 * (2 + (2 * 8)) * 2];
extern Float e102_sphere_size_max;
extern NJS_MESHSET e102_sphere_meshset;
extern NJS_MATERIAL e102_sphere_material;
extern NJS_MODEL e102_sphere_model;
extern NJS_TEXLIST e102_sphere_texlist;
extern Bool e102_sphere_built;
extern struct collision_shape e102_sphere_shape;
/* clang-format on */

/* make the ring, the points and the strips, and lay the texture
 * unscrolled, on the first call only */
static void e102_sphere_build(void)
{
    Float *ring;
    Float *point;
    Sint16 *strip;
    int i;
    int j;
    int index;
    int first;
    Float sin0;
    Float cos0;
    Float sin1;
    Float cos1;
    Float x;
    Float z;

    if (e102_sphere_built) {
        return;
    }
    e102_sphere_built = TRUE;
    ring = e102_sphere_ring;
    for (i = 0; i < PAIRS * PAIR_ANGLE; i += PAIR_ANGLE) {
        *ring++ = njCos(i);
        *ring++ = njSin(i);
    }
    point = (Float *)e102_sphere_points;
    for (i = 0; i < BANDS * BAND_ANGLE; i += BAND_ANGLE) {
        ring = e102_sphere_ring;
        sin0 = njSin(i);
        cos0 = njCos(i);
        sin1 = njSin(i + BAND_ANGLE);
        cos1 = njCos(i + BAND_ANGLE);
        for (j = 0; j < PAIRS * PAIR_ANGLE; j += PAIR_ANGLE) {
            x = *ring++;
            z = *ring++;
            *point++ = sin0 * x;
            *point++ = cos0;
            *point++ = sin0 * z;
            *point++ = sin1 * x;
            *point++ = cos1;
            *point++ = sin1 * z;
        }
    }
    strip = e102_sphere_strips;
    index = 0;
    for (i = 0; i < BANDS; i++) {
        first = index;
        *strip++ = STRIP_POINTS;
        for (j = 0; j < PAIRS; j++) {
            *strip++ = index++;
            *strip++ = index++;
        }
        *strip++ = first++;
        *strip++ = first;
    }
    e102_sphere_scroll(0);
}

/* lay the texture across each band, scrolled by scroll in v */
static void e102_sphere_scroll(int scroll)
{
    Sint16 *uv;
    int i;
    int j;
    int tu;
    int tv;

    uv = e102_sphere_uvs;
    tv = scroll;
    for (i = 0; i < BANDS; i++) {
        tu = 0;
        for (j = 0; j < PAIRS + 1; j++) {
            *uv++ = tu;
            *uv++ = tv;
            *uv++ = tu;
            *uv++ = tv + 63;
            tu += 64;
            tv += 64;
        }
    }
}

/* move each band's top edge to open of its height above its bottom edge.
 * at 1 the sphere is whole, and at 0 each band closes up */
static void e102_sphere_close(Float open)
{
    Float *ring;
    Float *point;
    int i;
    int j;
    Float sin0;
    Float cos0;
    Float sin1;
    Float cos1;
    Float x;
    Float z;

    point = (Float *)e102_sphere_points;
    for (i = 0; i < BANDS * BAND_ANGLE; i += BAND_ANGLE) {
        ring = e102_sphere_ring;
        sin0 = njSin(i);
        cos0 = njCos(i);
        sin1 = njSin(i + BAND_ANGLE);
        cos1 = njCos(i + BAND_ANGLE);
        sin0 = sin1 + ((sin0 - sin1) * open);
        cos0 = cos1 + ((cos0 - cos1) * open);
        for (j = 0; j < PAIRS * PAIR_ANGLE; j += PAIR_ANGLE) {
            x = *ring++;
            z = *ring++;
            *point++ = sin0 * x;
            *point++ = cos0;
            *point++ = sin0 * z;
            point += 3;
        }
    }
}

/* the sphere swells from 2 to e102_sphere_size_max, slowing as it grows.
 * its shape turns off with SPHERE_FADE steps left on its timer, and it
 * fades after that */
void FUN_8c0d64fa(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case SPHERE_INIT:
        TASK_TIMER(work) = SPHERE_STEPS;
        VARS(work)->scroll = 0;
        VARS(work)->growth = 5.0F;
        work->scl.x = 2.0F;
        work->scl.z = 1.0F;
        e102_sphere_build();
        CCL_Init(task, &e102_sphere_shape, COLLISION_ATTACK, 1, 1);
        task->draw = e102_sphere_draw;
        work->mode = SPHERE_GROW;
        break;
    case SPHERE_GROW:
        TASK_TIMER(work)--;
        if (TASK_TIMER(work) == 0) {
            work->mode = SPHERE_KILL;
            break;
        }
        if (TASK_TIMER(work) == SPHERE_FADE) {
            work->collision->shapes->flags |= SHAPE_OFF;
        } else if (TASK_TIMER(work) < SPHERE_FADE) {
            work->scl.z -= 0.033F;
        }
        VARS(work)->growth += 0.1F;
        VARS(work)->growth *= 0.8F;
        work->scl.x = work->scl.x + VARS(work)->growth < e102_sphere_size_max
                          ? work->scl.x + VARS(work)->growth
                          : e102_sphere_size_max;
        work->collision->shapes->radius = work->scl.x * 0.8F;
        VARS(work)->scroll += 10;
        break;
    case SPHERE_KILL:
        FreeTask(task);
        return;
    }
    e102_sphere_draw(task);
    EntryColliList(work);
}

static void e102_sphere_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_MODEL *model;
    Float size;
    Float alpha;

    njSetTexture_jp(&e102_sphere_texlist);
    e102_sphere_close(work->scl.z);
    e102_sphere_scroll(VARS(work)->scroll);
    njPushMatrix(NULL);
    model = &e102_sphere_model;
    size = work->scl.x;
    alpha = work->scl.z;
    model->mats->diffuse.argb.a = alpha * 255.0F;
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    njScale(NULL, size, size, size);
    ds_DrawModelClip(model);
    late_DrawObjectClipEx(1);
}
