/* @unit 0CB82740-0CB82840 +egflags +pool32 */
/* an event's black over the screen, which clears at a rate */
#include <ninja.h>
#include <sg_xpt.h>

#include "shared/black.h"
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

#define VARS(work) ((struct black_vars *)&(work)->vars)
struct black_vars {
    Uint8 unk_00[4];
    /* the black's transparency, 0 when opaque. the draw's alpha is
     * (1 - transparency) * 255, and it draws nothing while that is below 1 */
    Float transparency;
    Float rate; /* added to transparency each step */
};
extern NJS_POINT2 event_black_corners[4];
extern NJS_COLOR event_black_colors[4];
extern NJS_POINT2COL event_black_polygon;
extern NJS_ARGB event_black_unused;
extern struct task *event_black;

void event_black_destroy(struct task *task)
{
}

void event_black_draw(struct task *task)
{
    struct task_work *work = task->work;
    int alpha = (1.0F - VARS(work)->transparency) * 255.0F;

    if (alpha > 0) {
        event_black_colors[0].argb.a = event_black_colors[1].argb.a =
            event_black_colors[2].argb.a = event_black_colors[3].argb.a = alpha;
        njDrawPolygon2D(&event_black_polygon, 4, -1.0F,
                        NJD_FILL | NJD_TRANSPARENT);
    }
}

void event_black_step(struct task *task)
{
    struct task_work *work = task->work;
    Float transparency;
    Float rate;

    /* @hack spelling: the rate read before the transparency it adds to, as the
     * image reads them (0x0cb8256c and 0x0cb82570 in EV0060). as
     * VARS(work)->transparency += VARS(work)->rate, which reads the
     * transparency first, the step runs 2 bytes long and 7 of its 8 words
     * differ */
    rate = VARS(work)->rate;
    transparency = VARS(work)->transparency;
    VARS(work)->transparency = transparency + rate;
    event_black_draw(task);
}

void event_black_init(struct task *task)
{
    task->step = event_black_step;
    task->draw = event_black_draw;
    task->destructor = event_black_destroy;
    VARS(task->work)->transparency = 0.0F;
    event_black_step(task);
}

void event_black_set_rate(Float rate)
{
    if (event_black == NULL) {
        event_black = CreateElementalTask(TASK_WORK, 5, event_black_init);
    }
    VARS(event_black->work)->rate = rate;
}

void event_black_kill(void)
{
    if (event_black != NULL) {
        FreeTask(event_black);
        event_black = NULL;
    }
}
