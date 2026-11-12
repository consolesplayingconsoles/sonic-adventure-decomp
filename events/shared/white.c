/* @unit 0CB802E0-0CB805A0 +r04 +egflags +pool32 */
/* an event's white screen: a white polygon over the whole screen. its
 * alpha climbs to 255, holds and falls back. the task kills itself once the
 * alpha has fallen to a step's change or less */
#include <ninja.h>
#include <sg_xpt.h>

#include "event/play.h"
#include "shared/white.h"
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
void *CAlloc(int count, int size);
void EV_Load2(int number);
void EV_Exec2(void);
Bool EV_CheckCansel(void);
Bool EV_CheckExec(int number);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z, Angle ang_x,
                     Angle ang_y, Angle ang_z);

/* the white's modes, in work->mode, in the order it runs them */
#define WHITE_IDLE 0
#define WHITE_IN 1
#define WHITE_HOLD 2
#define WHITE_OUT 3
#define WHITE_DONE 4

/* the depth the white draws at */
#define WHITE_DEPTH (-1.0F)

/* the white's record, which its task's first step takes from the heap */
#define VARS(work) ((struct white_vars *)&(work)->vars)
struct white {
    Uint8 in_step; /* added to the alpha each step as it climbs */
    Uint8 out_step; /* taken from it each step as it falls */
    Uint8 unk_02[2];
    Sint32 hold; /* WHITE_HOLD runs hold + 1 steps */
    Sint32 timer; /* the steps it has held */
    NJS_COLOR color;
};

struct white_vars {
    Uint8 unk_00[8];
    struct white *white;
};
extern struct task *p_EfWhiteTask;

void initEfWhiteTask(struct task *task);
void execEfWhiteTask(struct task *task);
void dispEfWhiteTask(struct task *task);
void destEfWhiteTask(struct task *task);

/* the wait lets the task's first step allocate its record */
void event_white_start(int in_steps, int out_steps)
{
    struct task_work *work;
    struct white *white;

    p_EfWhiteTask = CreateElementalTask(TASK_WORK, 5, initEfWhiteTask);
    event_wait(1);
    white = VARS(p_EfWhiteTask->work)->white;
    /* 255.0F / 0 is infinite, which the SH-4's conversion to int turns into
     * 0x7fffffff. its low byte makes the change 255 */
    white->in_step = 255.0F / in_steps;
    white->out_step = 255.0F / out_steps;
    white->hold = 0;
    white->timer = 0;
    if (p_EfWhiteTask != NULL) {
        work = p_EfWhiteTask->work;
        work->mode = WHITE_IN;
    }
}

void efWhiteOn2(int in_steps, int hold, int out_steps)
{
    struct task_work *work;
    struct white *white;

    p_EfWhiteTask = CreateElementalTask(TASK_WORK, 5, initEfWhiteTask);
    event_wait(1);
    white = VARS(p_EfWhiteTask->work)->white;
    white->in_step = 255.0F / in_steps;
    white->out_step = 255.0F / out_steps;
    white->hold = hold;
    white->timer = 0;
    if (p_EfWhiteTask != NULL) {
        work = p_EfWhiteTask->work;
        work->mode = WHITE_IN;
    }
}

void efWhiteOff(void)
{
    if (p_EfWhiteTask != NULL) {
        FreeTask(p_EfWhiteTask);
        p_EfWhiteTask = NULL;
    }
}

void initEfWhiteTask(struct task *task)
{
    struct task_work *work = task->work;
    struct white *white = MAlloc(sizeof(*white));

    work->mode = WHITE_IDLE;
    white->color.argb.a = 0;
    white->color.argb.r = 255;
    white->color.argb.g = 255;
    white->color.argb.b = 255;
    VARS(work)->white = white;
    task->step = execEfWhiteTask;
    task->draw = dispEfWhiteTask;
    task->destructor = destEfWhiteTask;
}

void execEfWhiteTask(struct task *task)
{
    struct task_work *work = task->work;
    struct white *white = VARS(work)->white;

    switch (work->mode) {
    case WHITE_IDLE:
        break;
    case WHITE_IN:
        white->color.argb.a += white->in_step;
        if (white->color.argb.a >= 255 - white->in_step) {
            white->color.argb.a = 255;
            work->mode = WHITE_HOLD;
        }
        break;
    case WHITE_HOLD:
        if (++white->timer > white->hold) {
            work->mode = WHITE_OUT;
        }
        break;
    case WHITE_OUT:
        white->color.argb.a -= white->out_step;
        if (white->color.argb.a <= white->out_step) {
            work->mode = WHITE_DONE;
        }
        break;
    case WHITE_DONE:
        FreeTask(task);
        p_EfWhiteTask = NULL;
        break;
    }
    dispEfWhiteTask(task);
}

void dispEfWhiteTask(struct task *task)
{
    struct task_work *work = task->work;
    struct white *white = VARS(work)->white;
    NJS_POINT2COL polygon;
    NJS_POINT2 points[4];
    NJS_COLOR colors[4];

    extern int loop_count;
    if (loop_count != 0) {
        return;
    }
    polygon.p = points;
    polygon.col = colors;
    polygon.tex = NULL;
    polygon.num = 4;
    polygon.p[0].x = 0.0F;
    polygon.p[0].y = 0.0F;
    polygon.col[0] = white->color;
    polygon.p[1].x = 0.0F;
    polygon.p[1].y = 480.0F;
    polygon.col[1] = white->color;
    polygon.p[2].x = 640.0F;
    polygon.p[2].y = 480.0F;
    polygon.col[2] = white->color;
    polygon.p[3].x = 640.0F;
    polygon.p[3].y = 0.0F;
    polygon.col[3] = white->color;
    njDrawPolygon2D(&polygon, 4, WHITE_DEPTH, NJD_FILL | NJD_TRANSPARENT);
}

void destEfWhiteTask(struct task *task)
{
    Free(VARS(task->work)->white);
}
