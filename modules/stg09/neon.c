/* @unit 0C923700-0C923980 +egflags +pool32 */
/* StarNeon, YajiNeon and Densyoku: a star, arrows and strings of lights in
 * neon, each flashing through its frames */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/model.h"
#include "stg09/neon.h"
#include "stg09/obj_casino_textures.h"
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
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void FUN_0c9238dc(struct task *task);
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

#define NEON_STAR 0
#define NEON_ARROW 1
#define NEON_ARROW_LAST 3
#define NEON_LIGHTS 4
#define LIGHTS_FRAMES 3
#define LIGHTS_TEXTURES 8
#define KIND(work) ((work)->mode)
#define FRAME(work) ((work)->tick)
#define CLOCK(work) ((work)->vars.f[0]) /* steps since its frame changed */
#define PERIOD(work) ((work)->scl.z)
#define VARIANT(work) ((work)->scl.y)
extern NJS_MATERIAL neon_star_materials[];
extern NJS_MODEL neon_star_model;
extern NJS_MATERIAL neon_arrow_materials[];
extern NJS_MODEL neon_arrow_model;
extern NJS_MATERIAL neon_lights_materials[];
extern NJS_MODEL neon_lights_model;

/* kinds of neon: the star, three arrows, then three strings of lights */

/* neon_texlist holds the star's 2 frames as textures 0 and 1, and each
 * arrow's 2 after them. each string's LIGHTS_FRAMES frames follow from
 * texture LIGHTS_TEXTURES on. a string's frame takes 2 textures, one for each
 * of its model's materials */

/* the texture frame it shows: 0 or 1, or 0 to 2 for a string */
/* a frame shows for PERIOD + 2 steps, with PERIOD rounded down */
/* which arrow or string: 0, 1, or any other value for the third */

void neon_destroy(struct task *task)
{
}

void neon_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    Float scale;

    if (loop_count) {
        return;
    }
    if (KIND(work) == NEON_STAR) {
        neon_star_materials[0].attr_texId = FRAME(work);
    } else if (KIND(work) <= NEON_ARROW_LAST) {
        neon_arrow_materials[0].attr_texId = (KIND(work) * 2) + FRAME(work);
    } else {
        neon_lights_materials[0].attr_texId =
            ((((KIND(work) - NEON_LIGHTS) * LIGHTS_FRAMES) + FRAME(work)) * 2) +
            (LIGHTS_TEXTURES + 1);
        neon_lights_materials[1].attr_texId =
            ((((KIND(work) - NEON_LIGHTS) * LIGHTS_FRAMES) + FRAME(work)) * 2) +
            LIGHTS_TEXTURES;
    }
    njSetTexture_jp(&neon_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    scale = work->scl.x;
    njScale(NULL, scale, scale, scale);
    if (KIND(work) == NEON_STAR) {
        ds_DrawModelClip(&neon_star_model);
    } else if (KIND(work) <= NEON_ARROW_LAST) {
        ds_DrawModelClip(&neon_arrow_model);
    } else {
        ds_DrawModelClip(&neon_lights_model);
    }
    late_DrawObjectClipEx(1);
}

void neon_run(struct task *task)
{
    struct task_work *work = task->work;

    if (CLOCK(work) > PERIOD(work)) {
        CLOCK(work) = 0.0F;
        if (KIND(work) <= NEON_ARROW_LAST) {
            FRAME(work) = (FRAME(work) + 1) & 1;
        } else {
            FRAME(work) = (FRAME(work) + 1) % LIGHTS_FRAMES;
        }
    } else {
        CLOCK(work) += 1.0F;
    }
    neon_draw(task);
}

void neon_init(struct task *task)
{
    /* @hack spelling: each store through task->work, which SHC loads again for
     * each (MOV.L @(32,R4),R3 at 0x0c925440 and 0x0c92544a). through a
     * local work, 12 of neon_init's 14 words differ */
    CLOCK(task->work) = 0.0F;
    FRAME(task->work) = 0;
    task->step = neon_run;
    task->draw = neon_draw;
    task->destructor = neon_destroy;
}

void FUN_0c9238dc(struct task *task)
{
    struct task_work *work = task->work;

    KIND(work) = NEON_STAR;
    neon_init(task);
}

void neon_arrow_step(struct task *task)
{
    struct task_work *work = task->work;

    if (VARIANT(work) == 0.0F) {
        KIND(work) = NEON_ARROW;
    } else if (VARIANT(work) == 1.0F) {
        KIND(work) = NEON_ARROW + 1;
    } else {
        KIND(work) = NEON_ARROW + 2;
    }
    neon_init(task);
}

void neon_lights_step(struct task *task)
{
    struct task_work *work = task->work;

    if (VARIANT(work) == 0.0F) {
        KIND(work) = NEON_LIGHTS;
    } else if (VARIANT(work) == 1.0F) {
        KIND(work) = NEON_LIGHTS + 1;
    } else {
        KIND(work) = NEON_LIGHTS + 2;
    }
    neon_init(task);
}
