/* @unit 0C902720-0C902AA0 @data 0C910AD8-0C910AE4 +r04 +egflags +pool32 */
/* water column splash that rises from the sea and sinks back */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "draw/tree.h"
#include "effect/snow.h"
#include "stg01/water_column.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
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

#define VARS(work) ((struct water_column_vars *)&(work)->vars)
extern NJS_TEXLIST beach_water_column_texlist;
extern NJS_OBJECT beach_water_column_object_0;
extern NJS_OBJECT beach_water_column_object_1;
extern NJS_OBJECT *beach_water_column_inner;
extern NJS_OBJECT *beach_water_column_outer;

/* the column's state, in work->vars. scl.x is the column's width and scl.y
 * its height. scl.z counts steps toward its next spray puff. a column of size
 * above 0.2 throws a puff each step of its rise. a smaller one throws none */
struct water_column_vars {
    Float shade; /* twice this is added to the sheets' material color */
    Float rise; /* the height grows by rise squared times size a step */
    Float size; /* the scale the column was made at */
};

enum water_column_mode { COLUMN_RISE, COLUMN_SINK, COLUMN_END };

void ObjectBeachWatertube(struct task *task);
void beach_water_column_run(struct task *task);
void beach_water_column_draw(struct task *task);
void beach_water_column_destroy(struct task *task);

void CreateBeachWatertube(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale)
{
    struct task *task =
        CreateElementalTask(TASK_MOTION | TASK_WORK, 3, ObjectBeachWatertube);
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    work->pos.x = pos->x;
    work->pos.y = pos->y;
    work->pos.z = pos->z;
    motion->speed.x = speed->x;
    motion->speed.y = 0.0F;
    motion->speed.z = speed->z;
    work->scl.x = work->scl.z = scale * 2.0F;
    work->scl.y = 0.0F;
    work->scl.z = 0.0F;
    VARS(work)->shade = scale * 0.1F;
    VARS(work)->size = scale;
    VARS(work)->rise = 0.1F;
}

void ObjectBeachWatertube(struct task *task)
{
    struct task_work *work = task->work;

    work->mode = COLUMN_RISE;
    task->step = beach_water_column_run;
    task->draw = beach_water_column_draw;
    task->destructor = beach_water_column_destroy;
}

/* rise until the height passes size times 0.04. then sink and darken until
 * shade falls below -1, and end */
void beach_water_column_run(struct task *task)
{
    struct task_work *work = task->work;
    Float most;
    Float shade;
    Float rise;
    Float size;
    Float time;

    ++work->timer;
    switch (work->mode) {
    case COLUMN_RISE:
        work->scl.x += VARS(work)->size * 0.03F;
        time = TASK_TIMER(work);
        work->scl.y =
            (time * VARS(work)->rise * VARS(work)->rise * VARS(work)->size) +
            0.001F;
        if (work->scl.y > VARS(work)->size * (0.2F * 0.2F)) {
            work->mode = COLUMN_SINK;
            VARS(work)->shade = 1.0F;
            work->timer = 0;
        }
        work->scl.z += 1.0F;
        most = VARS(work)->size * 5.0F;
        if (most > 5.0F) {
            most = 5.0F;
        }
        if (work->scl.z++ < most) {
            NJS_VECTOR speed = {0.0F, 1.5F, 0.0F};

            speed.y *= VARS(work)->rise * 1.5F;
            snow_create(&work->pos, &speed,
                        ((VARS(work)->size * 2.0F) + 1.0F) * 0.5F);
            work->scl.z = 0.0F;
        }
        break;
    case COLUMN_SINK:
        shade = VARS(work)->shade;
        /* @hack redundant: size and rise, loaded and stored back unchanged
         * (FMOV.S at 0x0c902a0a and 0x0c902a0e, and at 0x0c902a40 and
         * 0x0c902a46). without them, 64 of 172 words differ and the functions
         * after it move */
        size = VARS(work)->size;
        rise = VARS(work)->rise;
        work->scl.y -= 0.001F;
        shade -= 0.01F;
        if (shade < -1.0F) {
            work->mode = COLUMN_END;
        }
        work->scl.x += VARS(work)->size * 0.03F;
        VARS(work)->shade = shade;
        VARS(work)->size = size;
        VARS(work)->rise = rise;
        break;
    case COLUMN_END:
        FreeTask(task);
        break;
    }
    if (work->scl.y < 0.1F) {
        work->scl.y = 0.1F;
    }
    beach_water_column_draw(task);
}

/* draw the two sheets with alpha, scaled to the column. twice shade is added
 * to their material's color */
void beach_water_column_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_ARGB color;

    njSetTexture_jp(&beach_water_column_texlist);
    njPushMatrix(NULL);
    SaveConstantAttr();
    OnConstantAttr(0, NJD_FLAG_USE_ALPHA);
    color.r = color.g = color.b = VARS(work)->shade * 0.8F;
    SetMaterial(0.0F, color.r, color.g, color.b);
    njTranslateV(NULL, &work->pos);
    njScale(NULL, work->scl.x, work->scl.y, work->scl.x);
    color.r = color.g = color.b = VARS(work)->shade * 2.0F;
    SetMaterial(0.0F, color.r, color.g, color.b);
    /* @hack spelling: each sheet through its pointer's address, which takes
     * draw_tree's address into R3 and then R2 (0x0c902b80 and 0x0c902b88).
     * without it, 12 of 103 words differ */
    {
        NJS_OBJECT **slot = &beach_water_column_inner;
        NJS_OBJECT *sheet = *slot;

        late_DrawObject(sheet);
    }
    {
        NJS_OBJECT **slot = &beach_water_column_outer;
        NJS_OBJECT *sheet = *slot;

        late_DrawObject(sheet);
    }
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    LoadConstantAttr();
    late_DrawObjectClipEx(1);
}

void beach_water_column_destroy(struct task *task)
{
}
