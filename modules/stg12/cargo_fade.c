/* @unit 0C913BE0-0C913D40 +r04 +egflags +asmfunc=FUN_0c913c76:0c913d40 */
/* screen fade to black and back as the cargo ride starts and ends */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "stg12/cargo_fade.h"
/* the sprite's generated data names hotshelter4_texlist */
#include "stg12/texlists.h" /* NOLINT(misc-include-cleaner) */
#include "system/frame.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

#define FADE_SPEED 0.01F /* the alpha the fade gains or loses each step */
/* the screen holds black until its count of steps passes HOLD_STEPS, so for
 * 31 steps */
#define HOLD_STEPS 30

/* the scales that stretch the 64-pixel sprite over the 640 by 480 screen,
 * and the screen's center */
#define COVER_X 10.0F
#define COVER_Y 7.5F
#define MIDDLE_X 320.0F
#define MIDDLE_Y 240.0F

#define VARS(work) ((struct cargo_fade_vars *)&(work)->vars)
enum cargo_fade_mode { FADE_TO_BLACK, FADE_HOLD, FADE_BACK };

/* TASK_TIMER(work) counts the steps the screen is held black */
struct cargo_fade_vars {
    Float alpha; /* the sprite's: it rises from -0.5 to 1, then falls to 0 */
};

void egoManager(struct task *task);
void cargo_fade_draw(struct task *task);
extern NJS_TEXANIM cargo_fade_frame;
extern NJS_SPRITE cargo_fade_sprite;

void cargo_fade_start(struct task *task)
{
    struct task_work *work = task->work;

    work->mode = FADE_TO_BLACK;
    VARS(work)->alpha = -0.5F;
    task->step = egoManager;
    task->draw = cargo_fade_draw;
}

void egoManager(struct task *task)
{
    struct task_work *work = task->work;

    cargo_fade_draw(task);
    switch (work->mode) {
    case FADE_TO_BLACK:
        VARS(work)->alpha += FADE_SPEED;
        if (VARS(work)->alpha >= 1.0F) {
            VARS(work)->alpha = 1.0F;
            work->timer = 0;
            work->mode = FADE_HOLD;
        }
        break;
    case FADE_HOLD:
        TASK_TIMER(work)++;
        if (TASK_TIMER(work) > HOLD_STEPS) {
            work->timer = 0;
            work->mode = FADE_BACK;
        }
        break;
    case FADE_BACK:
        VARS(work)->alpha -= FADE_SPEED;
        if (VARS(work)->alpha <= 0.0F) {
            VARS(work)->alpha = 0.0F;
            FreeTask(task);
        }
        break;
    }
}
#ifdef NON_MATCHING

/* a frame runs frame_step_count steps, and the stage's objects draw in the
 * first. the fade draws in each of the others */
void cargo_fade_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (loop_count != 0) {
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_INVSRCALPHA);
        SetMaterial(VARS(work)->alpha, 0.0F, 0.0F, 0.0F);
        cargo_fade_sprite.sx = COVER_X;
        cargo_fade_sprite.sy = COVER_Y;
        cargo_fade_sprite.p.x = MIDDLE_X;
        cargo_fade_sprite.p.y = MIDDLE_Y;
#ifdef GCC
        /* the port's 16:9 stretches the fade across the screen */
        port_wide_cover = TRUE;
#endif
        late_DrawSprite2D(&cargo_fade_sprite, 0, -0.9F,
                          NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
#ifdef GCC
        port_wide_cover = FALSE;
#endif
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
#else
void cargo_fade_draw(struct task *task)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
}
#endif
