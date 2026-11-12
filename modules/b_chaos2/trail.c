/* @unit 0C906580-0C9066A0 +jpflags +pool32 */
/* the trail a thrown drop of Chaos 2's leaves. the drop makes a sprite
 * each step it flies, and each sprite shrinks away */
#include <ninja.h>
#include <sg_xpt.h>

#include "b_chaos2/textures.h" /* NOLINT(misc-include-cleaner) */
#include "b_chaos2/trail.h"
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
void FreeTask(struct task *task);
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
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* the sprite's scale starts at 1 and falls by TRAIL_SHRINK a step. the
 * sprite ends once its scale falls to 0 or below */
#define TRAIL_SHRINK (1.0F / 15.0F)

/* the sprite's work->mode */
#define VARS(work) ((struct trail_vars *)&(work)->vars)
enum trail_mode { TRAIL_START, TRAIL_RUN };

struct trail_vars {
    Float scale;
};
extern NJS_TEXANIM trail_frame;
extern NJS_SPRITE trail_sprite;

/* draw the sprite at the work's pos and scale, added to what lies behind
 * it. the offset color the draw sets doesn't reach the sprite:
 * njDrawSprite3D colors a sprite white unless NJD_SPRITE_COLOR is set (TST
 * at 0x8c6237d4 in 1ST_READ.BIN) */
void trail_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_ARGB color;

    SaveControl3D();
    njControl3D(NJD_CONTROL_3D_OFFSET_MATERIAL);
    color.r = color.g = color.b = VARS(work)->scale - 1.0F;
    /* @bug uninitialized: color.a has no store before njSetConstantMaterial
     * copies all four of color's members. color lies at R15, which R4 passes
     * at 0x0c906b2c, and njSetConstantMaterial reads color.a through R4 at
     * 0x8c629894 in 1ST_READ.BIN */
    njSetConstantMaterial(&color);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njPushMatrix(NULL);
    trail_sprite.sx = trail_sprite.sy = VARS(work)->scale;
    njTranslateV(NULL, &work->pos);
    njDrawSprite3D(&trail_sprite, 0, NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE);
    late_DrawObjectClipEx(1);
    color.a = 1.0F;
    njSetConstantMaterial(&color);
    LoadControl3D();
}

void chaos2_trail_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case TRAIL_START:
        VARS(work)->scale = 1.0F;
        task->draw = trail_draw;
        work->mode = TRAIL_RUN;
        /* fall through */
    case TRAIL_RUN:
        VARS(work)->scale -= TRAIL_SHRINK;
        if (VARS(work)->scale <= 0.0F) {
            DestroyTask(task);
            return;
        }
        break;
    }
    trail_draw(task);
}
