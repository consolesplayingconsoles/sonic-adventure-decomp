/* @unit 0CB83500-0CB836A0 +egflags +pool32 */
/* an event's fade in: a polygon of one color over the whole screen. its
 * alpha rises to full and holds. the work keeps the color in pos, and the
 * alpha and its step in scl.x and scl.y */
#include <ninja.h>
#include <sg_xpt.h>

#include "shared/fade_in.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern NJS_POINT2 event_fade_in_corners[4];
extern struct task *event_fade_in;

#define FADE_IN_STEP 0.01F /* the alpha it gains each step */

void event_fade_in_destroy(struct task *task)
{
}

void COverlayDisp(struct task *task)
{
    struct task_work *work = task->work;
    Uint8 alpha;
    Uint8 red;
    Uint8 green;
    Uint8 blue;
    NJS_POINT2COL polygon;
    NJS_COLOR colors[4];

    alpha = work->scl.x * 255.0F;
    red = work->pos.x;
    green = work->pos.y;
    blue = work->pos.z;
    /* @hack type: alpha, a Uint8, tested against 0.0F, so SHC converts it and
     * compares floats (FLOAT and FCMP/GT at 0x0cb81e90 in EV001B). tested
     * against 0, the draw runs 4 bytes short and 70 of 76 words differ */
    if (alpha > 0.0F) {
        polygon.p = event_fade_in_corners;
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
            njDrawPolygon2D(&polygon, 4, -1.0F, NJD_FILL | NJD_TRANSPARENT);
        } else {
            njDrawPolygon2D(&polygon, 4, -1.0F, NJD_FILL);
        }
    }
}

void event_fade_in_step(struct task *task)
{
    struct task_work *work = task->work;
    Float alpha = work->scl.x + work->scl.y;

    if (alpha > 1.0F) {
        alpha = 1.0F;
    } else if (alpha < 0.0F) {
        alpha = 0.0F;
    }
    work->scl.x = alpha;
    COverlayDisp(task);
}

void event_fade_in_init(struct task *task)
{
    struct task_work *work = task->work;

    work->scl.x = 0.0F;
    work->scl.y = FADE_IN_STEP;
    task->step = event_fade_in_step;
    task->draw = COverlayDisp;
    task->destructor = event_fade_in_destroy;
    event_fade_in_step(task);
}

void event_fade_in_create(Float red, Float green, Float blue)
{
    struct task *task = CreateElementalTask(TASK_WORK, 1, event_fade_in_init);

    if (task != NULL) {
        struct task_work *work = task->work;

        work->pos.x = red;
        work->pos.y = green;
        work->pos.z = blue;
        event_fade_in = task;
    }
}

void event_fade_in_kill(void)
{
    if (event_fade_in != NULL) {
        FreeTask(event_fade_in);
        event_fade_in = NULL;
    }
}
