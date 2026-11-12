/* @unit 0CB81640-0CB81840 +r04 +egflags +pool32 */
/* an event's scan lines: lines of one color across the screen, with
 * spacing rows between them. they scroll down */
#include <ninja.h>
#include <sg_xpt.h>

#include "shared/scanlines.h"
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
void FUN_8c63e114(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
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
void FUN_0cb81692(void);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);

/* the lines' only mode, in work->mode */
#define SCANLINES_RUNNING 0

/* the lines' record, from the heap, which the destructor frees */
#define VARS(work) ((struct scanlines_vars *)&(work)->vars)
#define SCANLINES_DEPTH (-1.05F)
struct scanlines {
    NJS_COLOR color;
    int spacing; /* the rows between two lines */
};

struct scanlines_vars {
    Sint32 unk_00; /* cleared by the create, and never read */
    Uint8 unk_04[4];
    struct scanlines *lines;
};
extern const int event_scanlines_width;
extern const int event_scanlines_height;
extern struct task *event_scanlines;
extern int event_scanlines_row;

void event_scanlines_init(struct task *task);
void event_scanlines_step(struct task *task);
void event_scanlines_draw(struct task *task);
void event_scanlines_destroy(struct task *task);
void event_scanlines_draw_lines(struct task *task);

void event_scanlines_create(Uint8 alpha, Uint8 red, Uint8 green, Uint8 blue,
                            int spacing)
{
    struct task_work *work;
    struct scanlines *lines;

    event_scanlines = CreateElementalTask(TASK_WORK, 5, event_scanlines_init);
    lines = MAlloc(sizeof(*lines));
    work = event_scanlines->work;
    VARS(work)->lines = lines;
    work->mode = SCANLINES_RUNNING;
    VARS(work)->unk_00 = 0;
    lines->color.argb.a = alpha;
    lines->color.argb.r = red;
    lines->color.argb.g = green;
    lines->color.argb.b = blue;
    lines->spacing = spacing;
}

void FUN_0cb81692(void)
{
    if (event_scanlines != NULL) {
        FreeTask(event_scanlines);
        event_scanlines = NULL;
    }
}

void event_scanlines_init(struct task *task)
{
    task->step = event_scanlines_step;
    task->draw = event_scanlines_draw;
    task->destructor = event_scanlines_destroy;
}

void event_scanlines_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case SCANLINES_RUNNING:
        break;
    }
    event_scanlines_draw(task);
}

void event_scanlines_draw_lines(struct task *task)
{
    struct task_work *work = task->work;
    struct scanlines *lines = VARS(work)->lines;
    NJS_POINT2COL line;
    NJS_POINT2 points[2];
    NJS_COLOR colors[2];
    int y;

    line.p = points;
    line.col = colors;
    line.tex = NULL;
    line.num = 2;
    if (++event_scanlines_row == lines->spacing) {
        event_scanlines_row = 0;
    }
    for (y = event_scanlines_row; y < event_scanlines_height;
         y += lines->spacing + 1) {
        line.p[0].x = 0.0F;
        line.p[0].y = (Float)y;
        line.col[0].argb.a = lines->color.argb.a;
        line.col[0].argb.r = lines->color.argb.r;
        line.col[0].argb.g = lines->color.argb.g;
        line.col[0].argb.b = lines->color.argb.b;
        line.p[1].x = (Float)event_scanlines_width;
        line.p[1].y = (Float)y;
        line.col[1].argb.a = lines->color.argb.a;
        line.col[1].argb.r = lines->color.argb.r;
        line.col[1].argb.g = lines->color.argb.g;
        line.col[1].argb.b = lines->color.argb.b;
        FUN_8c63e114(&line, 1, (-1.05F), 0x00000040);
    }
}

void event_scanlines_draw(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case SCANLINES_RUNNING:
        event_scanlines_draw_lines(task);
        break;
    }
}

void event_scanlines_destroy(struct task *task)
{
    struct task_work *work = task->work;
    struct scanlines *lines = VARS(work)->lines;

    if (lines != NULL) {
        Free(lines);
    }
}
