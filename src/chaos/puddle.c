/* @unit 8C0EF4C0-8C0EF940 +egflags +pool32 */
/* an event's Chaos puddle, and the blobs of water round a Chaos */
#define TEXT_1 ""
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "chaos/chaos.h"
#include "chaos/puddle.h"
#include "collision/ground.h"
#include "draw/motion.h"
#include "draw/tree.h"
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
void *syMalloc_default_malloc(size_t size);
extern Sint8 chaos_reqmode;
void FUN_8c0ef5b8(void *unused, struct chaos *chaos);
void FUN_8c0ef6c0(void *unused, struct chaos *chaos, Float spread);
void FUN_8c0ef840(NJS_POINT3 *pos, NJS_VECTOR *scale);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void Free(void *mem);
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
extern NJS_TEXNAME puddle_textures[];
extern NJS_TEXLIST puddle_texlist;
extern Sint8 blob_count;
extern NJS_POINT3 blob_pos[16];
extern Float blob_size[16];
extern struct task *puddle_task;

#define TEXT_1_LENGTH 14

/* the most blobs blob_place puts round a Chaos */
#define BLOB_MAX 16

/* the event puddle's water texture, whose image chaos_animate_surface
 * flows through CHAOS_SURFACE's frames */

void blob_place(struct task_work *work, int unused, int count)
{
    int i;
    Angle ang;
    Float radius;
    Float x;
    Float y;
    Float z;
    struct angles slope;

    blob_count = count < BLOB_MAX ? count : BLOB_MAX;
    for (i = 0; i < blob_count; i++) {
        radius = RANDOM(10.0F, 15.0F);
        ang = (Angle)(360.0F / blob_count * i * ANGLE_PER_DEGREE);
        x = radius * njCos(ang);
        z = radius * njSin(ang);
        blob_pos[i].x = x;
        blob_pos[i].z = z;
        y = GetShadowPos(work->pos.x + x, work->pos.y + 3.0F, work->pos.z + z,
                         &slope);
        blob_pos[i].y = y - work->pos.y;
        blob_size[i] = RANDOM(0.5F, 0.9F);
    }
}

void FUN_8c0ef5b8(void *unused, struct chaos *chaos)
{

    Float scale_y;
    Float width;
    register Float size;
    int i;
    register Float fade;
    Float scale_x;

    for (i = 0; i < blob_count; i++) {
        width = chaos->scale.x;
        size = blob_size[i];
        scale_y = chaos->scale.y * size;
        scale_x = width * size;
        fade = width - 0.75F;
        fade = fade > 0.0F ? fade : 0.0F;
        njPushMatrix(NULL);
        njTranslate(NULL, blob_pos[i].x * fade, blob_pos[i].y,
                    blob_pos[i].z * fade);
        njScale(NULL, scale_x, scale_y, scale_x);
        late_DrawObject(&chaos_blob);
        late_DrawObjectClipEx(1);
    }
}

void FUN_8c0ef6c0(void *unused, struct chaos *chaos, Float spread)
{
    int i;
    Float scale_x;
    Float scale_y;
    Float reach;
    Float width;
    Float size;

    for (i = 0; i < blob_count; i++) {
        width = chaos->scale.x;
        size = blob_size[i];
        scale_x = width * size;
        scale_y = chaos->scale.y * size;

        reach = width * spread * 0.5F;
        njPushMatrix(NULL);
        njTranslate(NULL, blob_pos[i].x * reach, blob_pos[i].y,
                    blob_pos[i].z * reach);
        njScale(NULL, scale_x, scale_y, scale_x);
        late_DrawObject(&chaos_blob);
        late_DrawObjectClipEx(1);
    }
}

/* draw the puddle, its water flowing and its points trailing over the
 * ground */
static void puddle_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct chaos *puddle = task->extra;

    chaos_animate_surface(puddle);
    njSetTexture_jp(puddle->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    chaos_puddle_deform(work, puddle, &chaos_puddle);
    njScaleV(NULL, &puddle->scale);
    late_DrawObject(&chaos_puddle);
    late_DrawObjectClipEx(1);
}

/* give the puddle's model its own points back, and free the kept ones */
static void puddle_destroy(struct task *task)
{
    struct task_work *work = task->work;
    struct chaos *puddle = task->extra;

    puddle->puddle_mode = PUDDLE_FREE;
    chaos_puddle_deform(work, puddle, &chaos_puddle);
}

struct task *puddle_create(Angle ang)
{
    struct task_work *work;
    struct chaos *puddle;
    NJS_OBJECT *object;

    puddle_task = CreateElementalTask(TASK_WORK, 1, puddle_draw);
    puddle_task->extra = CAlloc(1, sizeof(struct chaos));
    puddle_task->destructor = puddle_destroy;
    puddle = puddle_task->extra;
    work = puddle_task->work;
    work->ang.y = ang;
    puddle->texlist = &puddle_texlist;
    puddle->puddle_mode = PUDDLE_MAKE;
    object = &chaos_puddle;
    chaos_puddle_deform(work, puddle, object);
    object->model->mats->attrflags |= NJD_FLAG_USE_ALPHA;
    object->model->mats->diffuse.argb.a = 0x99;
    return puddle_task;
}

void FUN_8c0ef840(NJS_POINT3 *pos, NJS_VECTOR *scale)
{
    struct task_work *work = puddle_task->work;
    struct chaos *puddle = puddle_task->extra;
    Angle ang = (Angle)(njArcTan2(pos->z - work->pos.z, pos->x - work->pos.x) *
                        ANGLE_PER_RADIAN);

    work->ang.y = AdjustAngle(work->ang.y, ang, NJM_DEG_ANG(5));
    work->pos = *pos;
    puddle->scale = *scale;
}
