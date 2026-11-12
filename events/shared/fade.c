/* @unit 0CB829A0-0CB82B60 +egflags +pool32 */
/* an event's fade: a polygon of one color over the whole screen. its alpha
 * moves by its speed each step, and holds at 0 and 1 */
#include <ninja.h>
#include <sg_xpt.h>

#include "shared/fade.h"
#include "system/task.h"
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
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void COverlaySetSpeed(struct task *task, Float speed);
void COverlaySetAlpha(struct task *task, Float alpha);
void COverlaySetColor(struct task *task, Float red, Float green, Float blue);
void COverlaySetPriority(struct task *task, Float depth);

/* the fade's view of its task_work, whose first 32 bytes it never reads. the
 * color is in pos, and the alpha, its speed and the depth in scl */
struct fade_work {
    Uint8 unk_00[32];
    Float r, g, b;
    Float alpha;
    Float speed; /* added to alpha each step */
    Float depth; /* the draw priority it passes njDrawPolygon2D as pri */
};
extern NJS_POINT2 event_fade_corners[4];

void COverlayDisp(struct task *task)
{
    struct fade_work *work = (struct fade_work *)task->work;
    Uint8 alpha;
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    NJS_POINT2COL polygon;
    NJS_COLOR colors[4];

    extern int loop_count;
    alpha = work->alpha * 255.0F;
    red = work->r * 255.0F;
    green = work->g * 255.0F;
    blue = work->b * 255.0F;
    if (loop_count != 0) {
        return;
    }
    if (alpha > 0) {
        polygon.p = event_fade_corners;
        polygon.col = colors;
        polygon.tex = NULL;
        polygon.num = 4;
        colors[3].argb.a = alpha;
        colors[3].argb.r = red;
        colors[3].argb.g = green;
        colors[3].argb.b = blue;
        colors[0] = colors[1] = colors[2] = colors[3];
        if (alpha < 255) {
            njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                                   NJD_COLOR_BLENDING_BOTHSRCALPHA);
            njDrawPolygon2D(&polygon, 4, work->depth,
                            NJD_FILL | NJD_TRANSPARENT);
        } else {
            njDrawPolygon2D(&polygon, 4, work->depth, NJD_FILL);
        }
    }
}

void COverlayExec(struct task *task)
{
    struct fade_work *work = (struct fade_work *)task->work;
    Float alpha = work->alpha + work->speed;

    if (alpha > 1.0F) {
        alpha = 1.0F;
    } else if (alpha < 0.0F) {
        alpha = 0.0F;
    }
    work->alpha = alpha;
    COverlayDisp(task);
}

void COverlayDest(struct task *task)
{
}

void COverlayCons(struct task *task)
{
    task->step = COverlayExec;
    task->draw = COverlayDisp;
    task->destructor = COverlayDest;
    COverlayExec(task);
}

struct task *COverlayCreate(Float speed, Float alpha, Float red, Float green,
                            Float blue)
{
    struct task *task = CreateElementalTask(TASK_WORK, 1, COverlayCons);
    struct fade_work *work = (struct fade_work *)task->work;

    work->speed = speed;
    work->alpha = alpha;
    work->r = red;
    work->g = green;
    work->b = blue;
    work->depth = -1.0F;
    return task;
}

void COverlaySetSpeed(struct task *task, Float speed)
{
    struct fade_work *work = (struct fade_work *)task->work;

    work->speed = speed;
}

void COverlaySetAlpha(struct task *task, Float alpha)
{
    struct fade_work *work = (struct fade_work *)task->work;

    work->alpha = alpha;
}

void COverlaySetColor(struct task *task, Float red, Float green, Float blue)
{
    struct fade_work *work = (struct fade_work *)task->work;

    work->r = red;
    work->g = green;
    work->b = blue;
}

void COverlaySetPriority(struct task *task, Float depth)
{
    struct fade_work *work = (struct fade_work *)task->work;

    work->depth = depth;
}
