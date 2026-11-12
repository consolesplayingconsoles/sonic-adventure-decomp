/* @unit 0C906400-0C906580 @ddata 0C964D64-0C964D74 +egflags +pool32 */
/* the ripple where Chaos 2's ball lands. it is ripple_object, which its
 * action spreads while its texture cycles, and it darkens away */
#include <ninja.h>
#include <sg_xpt.h>

#include "b_chaos2/ripple.h"
#include "b_chaos2/textures.h"
#include "draw/draw.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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

/* the ripple plays its action's RIPPLE_FRAMES frames over RIPPLE_STEPS
 * steps, and ends once its frame reaches RIPPLE_FRAMES */
#define RIPPLE_FRAMES 7.0F
#define RIPPLE_STEPS 60.0F
#define RIPPLE_PACE (RIPPLE_FRAMES / RIPPLE_STEPS)
/* how far above its maker's pos the ripple lies */
#define RIPPLE_HEIGHT 1.0F
/* the ripple shows TEXTURES textures in turn, moving on every
 * TEXTURE_STEPS steps, and then starts again. the first is
 * chaos2_effect_texlist's FIRST_TEXTURE, c2_bb01 */
#define TEXTURE_STEPS 2
#define TEXTURES 8
#define FIRST_TEXTURE 41
/* past DARKEN_AT of its frames, the ripple darkens, as its offset color
 * falls from 0 to -1 over the DARKEN_SPAN left. DARKEN_SPAN is written
 * 0.3F: as 1.0F - DARKEN_AT, its reciprocal folds to 0x40555554, where the
 * image has 0x40555556 (0x0c906acc) */
#define DARKEN_AT 0.7F
#define DARKEN_SPAN 0.3F

/* the ripple's work->mode */
#define VARS(work) ((struct ripple_vars *)&(work)->vars)
enum ripple_mode { RIPPLE_START, RIPPLE_RUN };

struct ripple_vars {
    Float frame; /* the action's frame */
    /* @hack type: the steps on the texture and the texture shown, as an array
     * that SHC indexes from its base (ADD R2,R3 at 0x0c906a56). a union clears
     * both in one store (MOV.L R6,@(12,R5) at 0x0c906a32). as two Sint16 fields
     * cleared one by one, summed over ripple_draw and chaos2_ripple_step, 54 of
     * 137 words differ */
    union {
        Sint16 count[2];
        Sint32 all;
    } texture;
};
extern NJS_MATERIAL ripple_materials[1];
extern Sint16 ripple_meshes0[37];
extern NJS_COLOR ripple_uvs0[30];
extern NJS_MESHSET ripple_meshsets[1];
extern NJS_POINT3 ripple_points[17];
extern NJS_VECTOR ripple_normals[17];
extern NJS_MODEL ripple_model;
extern NJS_OBJECT ripple_object;
extern NJS_MKEY_F ripple_scl[8];
extern NJS_MDATA3 ripple_mdata[1];
extern NJS_MOTION ripple_motion;
extern NJS_ACTION ripple_action;

/* draw ripple_object at the work's pos, posed by its action at the step's
 * frame, with the texture the step shows. it draws through the offset
 * material, so a color below 0 darkens it */
void ripple_draw(struct task *task)
{
    static NJS_ARGB ripple_color = {1.0F, 0.0F, 0.0F, 0.0F};
    struct task_work *work = task->work;
    Float done;

    ripple_materials[0].attr_texId =
        VARS(work)->texture.count[1] + FIRST_TEXTURE;
    njSetTexture_jp(&chaos2_effect_texlist);
    njPushMatrix(NULL);
    done = VARS(work)->frame * (1.0F / RIPPLE_FRAMES);
    SaveControl3D();
    njControl3D(NJD_CONTROL_3D_OFFSET_MATERIAL);
    if (done < DARKEN_AT) {
        ripple_color.r = ripple_color.g = ripple_color.b = 0.0F;
    } else {
        Float dark = (DARKEN_AT - done) * (1.0F / DARKEN_SPAN);

        ripple_color.r = ripple_color.g = ripple_color.b = dark;
    }
    njSetConstantMaterial(&ripple_color);
    njTranslateV(((void *)0), &work->pos);
    njScale(((void *)0), 1.0F, 1.0F, 1.0F);
    ds_ActionClip(&ripple_action, ((struct ripple_vars *)&(work)->vars)->frame);
    LoadControl3D();
    late_DrawObjectClipEx(1);
}

void chaos2_ripple_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case RIPPLE_START:
        VARS(work)->texture.all = 0;
        VARS(work)->frame = 0.0F;
        work->pos.y += RIPPLE_HEIGHT;
        task->draw = ripple_draw;
        work->mode = RIPPLE_RUN;
        /* fall through */
    case RIPPLE_RUN:
        VARS(work)->texture.count[0]++;
        if (VARS(work)->texture.count[0] >= TEXTURE_STEPS) {
            VARS(work)->texture.count[0] = 0;
            VARS(work)->texture.count[1]++;
            if (VARS(work)->texture.count[1] >= TEXTURES) {
                VARS(work)->texture.count[1] = 0;
            }
        }
        VARS(work)->frame += RIPPLE_PACE;
        if (VARS(work)->frame >= RIPPLE_FRAMES) {
            DestroyTask(task);
            return;
        }
        break;
    }
    ripple_draw(task);
}
