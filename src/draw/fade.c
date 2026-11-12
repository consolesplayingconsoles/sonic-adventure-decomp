/* @unit 8C042E20-8C043A20 @data 8C112994-8C1129AC +egflags +pool32 +poolkeep=fade_in_step,DisplayGameOver,GameOver,FUN_8c0437c6,fade_task_to_black */
/* fades: the screen to and from black, the game over and coming soon
 * screens, and the color that covers the screen */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/fade.h"
#include "main.h"
#include "sound/stream.h"
#include "system/task.h"
#include "system/texlists.h"
#include "system/texture.h"
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
void FUN_8c042f0e(void);
void FUN_8c0430e0(void);
void FUN_8c0437c6(struct task *task);
void FUN_8c0438ac(struct task *task);
void FUN_8c0439ae(void);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
void BGM_Play(int music);
Bool CameraFishingCatch(void);
void ADXTaskInit(void);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);

/* njDrawPolygon2D's attributes for the quads: see-through, see-through with
 * a texture, and textured but solid, as the game over's banner draws */
#define SEE_THROUGH (NJD_DRAW_CONNECTED | NJD_FILL | NJD_TRANSPARENT)
#define SEE_THROUGH_TEXTURED (NJD_USE_TEXTURE | SEE_THROUGH)
#define SOLID_TEXTURED (NJD_USE_TEXTURE | NJD_DRAW_CONNECTED | NJD_FILL)

/* how far fade_level moves each step, out of 255 */
#define FADE_RATE 6
/* the steps fade_in_step holds the black before the fade moves. the fade
 * then starts FADE_IN_BLACK_STEPS moves past 255, so the screen stays black
 * that many steps longer */
#define FADE_IN_HOLD 5
#define FADE_IN_BLACK_STEPS 6
#define FADE_IN_LEVEL (255 + (FADE_IN_BLACK_STEPS * FADE_RATE))

/* how far a fade task's alpha moves each step, out of 255. the black and
 * back task holds its alpha at 255, and its steps draw nothing, until its
 * held count passes FADE_TASK_HOLD, which takes 62 steps */
#define FADE_TASK_RATE 4.0F
#define FADE_TASK_HOLD 60

#define COMING_SOON_CALLS 120
#define COMING_SOON_SPRITES 6

/* what a fade task keeps in work->vars */
#define VARS(work) ((struct fade_vars *)&(work)->vars)
struct fade_vars {
    Uint8 unk_00[4];
    Sint32 held; /* the steps it has held its alpha at 255 */
    Float alpha;
};

/* a fade task's modes, one way: to black or from it */
enum fade_mode { FADE_START, FADE_RUN, FADE_END };

/* a fade task's modes to black and back */
enum fade_back_mode {
    FADE_BACK_START,
    FADE_BACK_DARKEN,
    FADE_BACK_HOLD,
    FADE_BACK_LIGHTEN,
    FADE_BACK_END
};

void fade_task_to_black(struct task *task);
extern Uint8 fading;
extern NJS_TEXANIM game_over_piece_texanims[8];
extern NJS_TEXANIM game_over_texanims[6];
extern NJS_POINT2 cover_points[4];
extern NJS_COLOR cover_colors[4];
extern NJS_POINT2COL cover_quad;
extern Uint8 fade_hold;
extern Uint16 fade_level;
extern Sint8 game_over_phase;
extern NJS_COLOR fade_cover;

void fade_set_cover_black(int alpha)
{
    NJS_COLOR color;

    color.argb.a = alpha;
    color.argb.r = 0;
    color.argb.g = 0;
    color.argb.b = 0;
    fade_set_cover(&color);
}

static void fade_start(void)
{
    fading = 1;
    /* @hack redundant: a return where the function ends. SHC expands fade_start
     * at its calls in this file, and with the return, fade_in_start stores
     * fade_level before it calls stream_destroy, not in the call's slot
     * (0x8c045a6c); without it, 26 of 60 words differ */
    return; /* NOLINT(readability-redundant-control-flow) */
}

static void fade_stop(void)
{
    fading = 0;
}

void fade_draw(void)
{
    NJS_POINT2COL quad;
    NJS_POINT2 points[4];
    NJS_COLOR colors[4];
    NJS_COLOR color;
    Uint8 alpha;

    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    if (fade_level > 255) {
        alpha = 255;
    } else {
        alpha = fade_level;
    }
    quad.p = points;
    quad.col = colors;
    quad.tex = NULL;
    quad.num = 4;
    color.argb.b = color.argb.g = color.argb.r = 0;
    color.argb.a = alpha;
    quad.p[0].x = 0.0F;
    quad.p[0].y = 0.0F;
    quad.col[0].color = color.color;
    quad.p[1].x = SCREEN_WIDTH;
    quad.p[1].y = 0.0F;
    quad.col[1].color = color.color;
    quad.p[2].x = SCREEN_WIDTH;
    quad.p[2].y = SCREEN_HEIGHT;
    quad.col[2].color = color.color;
    quad.p[3].x = 0.0F;
    quad.p[3].y = SCREEN_HEIGHT;
    quad.col[3].color = color.color;
    njDrawPolygon2D(&quad, 4, -0.1F, SEE_THROUGH);
}

void FUN_8c042f0e(void)
{
    fade_start();
    fade_hold = FADE_IN_HOLD;
    fade_level = FADE_IN_LEVEL;
    ADX_Close();
    fade_draw();
}

Sint16 fade_in_step(void)
{
    if (fade_hold != 0) {
        fade_draw();
        fade_hold--;
        return -1;
    } else if (fading == 0) {
        return -1;
    } else if (fade_level > FADE_RATE) {
        fade_set_cover_black(0);
        fade_draw();
        fade_level -= FADE_RATE;
    } else {
        fade_set_cover_black(0);
        fading = 0;
    }
    return 0;
}

void fade_out_start(void)
{
    NJS_COLOR color;

    fade_start();
    fade_hold = 1;
    fade_get_cover(&color);
    fade_level = color.argb.a;
    ADX_Close();
    fade_draw();
}

Sint16 fade_out_step(void)
{
    if (fade_hold != 0) {
        fade_hold--;
    } else {
        fade_draw();
        if (fading == 0) {
            fade_set_cover_black(255);
            njSetBackColor_jp(0xff000000, 0xff000000, 0xff000000);
            return -1;
        } else if (fade_level != 255) {
            if (fade_level < 255 - 6) {
                fade_level += 6;
            } else {
                fade_level = 255;
            }
        } else {
            fading = 0;
        }
    }
    return 0;
}

void game_over_start(void)
{
    CreateElementalTask(TASK_WORK, 0, fade_task_to_black);
    fade_start();
    fade_level = 0;
    fade_hold = 1;
}

void FUN_8c0430e0(void)
{
    njReleaseTexture_jp(&game_over_texlist);
    fade_level = 255;
    fade_hold = 0;
}

/* draw the black, the banner and both choices, with a glow behind the
 * chosen one and its frame pulsing between red and blue */
void DisplayGameOver(int choice)
{
    NJS_POINT2COL quad;
    NJS_POINT2 points[4];
    NJS_COLOR colors[4];
    NJS_COLOR shade;
    NJS_COLOR uv[4];
    /* @hack redundant: register on glow, edge and spacing, which keeps the
     * constant 0.0F in FR12 throughout (FLDI0 FR12 at 0x8c045ce0); as plain
     * Floats, 49 of 557 words differ */
    register Float glow;
    register Float edge;
    register Float spacing;
    Float left;
    Float right;
    int offset;
    /* @hack type: volatile on blue, which keeps it in the frame: stored
     * at 0x8c046058, and read back at 0x8c046060 and 0x8c04606e; as a plain
     * Float, fade.c's code runs 32 bytes short and 152 of 557 words differ */
    volatile Float blue;
    /* @hack type: volatile on chosen, which keeps it in the frame at
     * R15 + 4 (0x8c045c9a, 0x8c04605a); as a plain int, 288 of 557 words
     * differ */
    volatile int chosen = choice;
    /* @hack redundant: register on color, which keeps edge in FR14 and
     * spacing in FR13 (0x8c045da0, 0x8c045da6); as a plain pointer, 14 of
     * 557 words differ */
    register NJS_COLOR *color;

    glow = game_over_phase;
    game_over_phase = (game_over_phase + 4) & 0xfc;
    if (glow < 0.0F) {
        glow = -glow;
    }
    glow *= 1.0F / 128.0F;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    quad.p = points;
    quad.col = colors;
    quad.tex = NULL;
    quad.num = 4;
    color = &shade;
    color->argb.b = color->argb.g = color->argb.r = 0;
    color->argb.a = fade_level;
    quad.p[0].x = 0.0F;
    quad.p[0].y = 0.0F;
    quad.col[0].color = color->color;
    quad.p[1].x = SCREEN_WIDTH;
    quad.p[1].y = 0.0F;
    quad.col[1].color = color->color;
    quad.p[2].x = SCREEN_WIDTH;
    quad.p[2].y = SCREEN_HEIGHT;
    quad.col[2].color = color->color;
    quad.p[3].x = 0.0F;
    quad.p[3].y = SCREEN_HEIGHT;
    quad.col[3].color = color->color;
    njDrawPolygon2D(&quad, 4, -1.05F, SEE_THROUGH);

    color->argb.b = color->argb.g = color->argb.r = 255;
    /* @hack type: &uv, cast, where uv would do, which stores the address
     * through R3 (0x8c045d7e to 0x8c045d8e); as uv, fade.c's code runs 32
     * bytes long and 407 of 557 words differ */
    quad.tex = (NJS_COLOR *)&uv;
    njSetTexture_jp(&game_over_texlist);
    njSetTextureNum_jp(GAME_OVER_BANNER);
    /* the banner's left side reuses spacing, 192, the step from the first
     * choice to the second. its top reuses edge, 160, the first choice's left
     * side */
    spacing = 192.0F;
    points[0].x = spacing;
    edge = 160.0F;
    points[0].y = edge;
    colors[0].color = color->color;
    points[1].x = 448.0F;
    points[1].y = edge;
    colors[1].color = color->color;
    points[2].x = 448.0F;
    points[2].y = 208.0F;
    colors[2].color = color->color;
    points[3].x = spacing;
    points[3].y = 208.0F;
    colors[3].color = color->color;
    uv[0].tex.u = 0;
    uv[0].tex.v = 0;
    uv[1].tex.u = 255;
    uv[1].tex.v = 0;
    uv[2].tex.u = 255;
    uv[2].tex.v = 255;
    uv[3].tex.u = 0;
    uv[3].tex.v = 255;
    njDrawPolygon2D(&quad, 4, -1.04F, SOLID_TEXTURED);

    /* each choice's words, over their back */
    quad.p[0].x = edge;
    quad.p[0].y = 368.0F;
    quad.p[1].x = 288.0F;
    quad.p[1].y = 368.0F;
    quad.p[2].x = 288.0F;
    quad.p[2].y = 400.0F;
    quad.p[3].x = edge;
    quad.p[3].y = 400.0F;
    njSetTextureNum_jp(GAME_OVER_CONTINUE);
    njDrawPolygon2D(&quad, 4, -1.0F, SEE_THROUGH_TEXTURED);
    njSetTextureNum_jp(GAME_OVER_BACK);
    njDrawPolygon2D(&quad, 4, -1.02F, SEE_THROUGH_TEXTURED);
    quad.p[0].x = 352.0F;
    quad.p[1].x = 480.0F;
    quad.p[2].x = 480.0F;
    quad.p[3].x = 352.0F;
    njSetTextureNum_jp(GAME_OVER_QUIT);
    njDrawPolygon2D(&quad, 4, -1.0F, SEE_THROUGH_TEXTURED);
    njSetTextureNum_jp(GAME_OVER_BACK);
    njDrawPolygon2D(&quad, 4, -1.02F, SEE_THROUGH_TEXTURED);

    /* the glow, from orange to yellow, behind the one chosen */
    njSetTextureNum_jp(GAME_OVER_CURSOR);
    color->argb.b = 0;
    color->argb.g = 152.0F + (glow * 83.0F);
    color->argb.r = 236.0F + (glow * 19.0F);
    /* @hack spelling: offset assigned inside the sum that first reads it, which
     * loads 160 at 0x8c045f3a, ahead of the multiply; assigned apart, 26 of
     * 557 words differ */
    quad.p[0].x = left = 160 + (offset = 192 * chosen);
    quad.p[0].y = 352.0F;
    quad.col[0].color = color->color;
    quad.p[1].x = right = 288 + offset;
    quad.p[1].y = 352.0F;
    quad.col[1].color = color->color;
    quad.p[2].x = right;
    quad.p[2].y = 416.0F;
    quad.col[2].color = color->color;
    quad.p[3].x = left;
    quad.p[3].y = 416.0F;
    quad.col[3].color = color->color;
    njDrawPolygon2D(&quad, 4, -1.01F, SEE_THROUGH_TEXTURED);

    /* each choice's frame: blue, or pulsing if it's the one chosen */
    blue = glow * 255.0F;
    if (chosen == 0) {
        color->argb.b = 0.0F + blue;
        color->argb.g = 0;
        color->argb.r = 255.0F - blue;
    } else {
        color->argb.b = 255;
        color->argb.g = 0;
        color->argb.r = 0;
    }
    njSetTextureNum_jp(GAME_OVER_FRAME);
    quad.p[0].x = edge;
    quad.col[0].color = color->color;
    quad.p[1].x = 288.0F;
    quad.col[1].color = color->color;
    quad.p[2].x = 288.0F;
    quad.col[2].color = color->color;
    quad.p[3].x = edge;
    quad.col[3].color = color->color;
    njDrawPolygon2D(&quad, 4, -1.02F, SEE_THROUGH_TEXTURED);
    if (chosen == 1) {
        color->argb.b = 0.0F + blue;
        color->argb.g = 0;
        color->argb.r = 255.0F - blue;
    } else {
        color->argb.b = 255;
        color->argb.g = 0;
        color->argb.r = 0;
    }
    quad.p[0].x += spacing;
    quad.col[0].color = color->color;
    quad.p[1].x += spacing;
    quad.col[1].color = color->color;
    quad.p[2].x += spacing;
    quad.col[2].color = color->color;
    quad.p[3].x += spacing;
    quad.col[3].color = color->color;
    njDrawPolygon2D(&quad, 4, -1.02F, SEE_THROUGH_TEXTURED);
}

Sint16 GameOver(int choice)
{
    if (fade_hold == 0) {
        DisplayGameOver(choice);
    } else if (fading == 0) {
        ADX_Close();
        {
            extern int region_export;
            if (region_export == 0) {
                texLoadTexturePvmFile("GAMEOVER", &game_over_texlist);
            } else {
                texLoadTexturePvmFile("GAMEOVER_E", &game_over_texlist);
            }
        }
        njSetBackColor_jp(0xff000000, 0xff000000, 0xff000000);
        fade_hold = 0;
        DisplayGameOver(choice);
    } else if (fade_level < 255 - FADE_RATE) {
        fade_level += FADE_RATE;
    } else {
        fade_level = 255;
        fading = 0;
        return -1;
    }
    return 0;
}
#if 0

static void coming_soon_draw(void)
{
    NJS_SPRITE sprite;
    /* @hack redundant: 16 bytes of the frame that the function never reads.
     * their type is unknown. the image's ADD #-48,R15 at 0x8c04628a reserves
     * them; without them, 42 of 61 words differ */
    char unused[16];
    int i;

    njSetTexture_jp(&coming_soon_texlist);
    sprite.tlist = &coming_soon_texlist;
    sprite.tanim = coming_soon_texanims;
    sprite.sx = 1.0F;
    sprite.sy = 1.0F;
    sprite.p.x = SCREEN_MIDDLE_X;
    sprite.p.y = 0.0F;
    for (i = 0; i < COMING_SOON_SPRITES; i++) {
        late_DrawSprite2D(&sprite, i, -10.0F, 0);
    }
}

void coming_soon_start(void)
{
    fade_hold = COMING_SOON_CALLS;
    ADX_Close();
    texLoadTexturePvmFile("COMESOON", &coming_soon_texlist);
    coming_soon_draw();
}

Sint16 coming_soon_step(void)
{
    fade_hold--;
    if (fade_hold == 0) {
        njSetBackColor_jp(0xff000000, 0xff000000, 0xff000000);
        njReleaseTexture_jp(&coming_soon_texlist);
        return -1;
    }
    coming_soon_draw();
    return 0;
}
#endif

void fade_task_draw(struct task *task)
{
    NJS_POINT2COL quad;
    NJS_POINT2 points[4];
    NJS_COLOR colors[4];
    NJS_COLOR color;
    struct task_work *work = task->work;

    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    quad.p = points;
    quad.col = colors;
    quad.tex = NULL;
    quad.num = 4;
    color.argb.b = color.argb.g = color.argb.r = 0;
    color.argb.a = ((struct fade_vars *)&(work)->vars)->alpha * 0.0039215684F;
    quad.p[0].x = 0.0F;
    quad.p[0].y = 0.0F;
    quad.col[0].color = color.color;
    quad.p[1].x = SCREEN_WIDTH;
    quad.p[1].y = 0.0F;
    quad.col[1].color = color.color;
    quad.p[2].x = SCREEN_WIDTH;
    quad.p[2].y = SCREEN_HEIGHT;
    quad.col[2].color = color.color;
    quad.p[3].x = 0.0F;
    quad.p[3].y = SCREEN_HEIGHT;
    quad.col[3].color = color.color;
    njDrawPolygon2D(&quad, 4, -0.1F, SEE_THROUGH);
}

void fade_task_destroy(struct task *task)
{
}

void FUN_8c0437c6(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case FADE_BACK_START:
        task->draw = fade_task_draw;
        task->destructor = fade_task_destroy;
        work->mode = FADE_BACK_DARKEN;
        /* fall through */
    case FADE_BACK_DARKEN:
        fade_task_draw(task);
        ((struct fade_vars *)&(work)->vars)->alpha += 6.0F;
        if (((struct fade_vars *)&(work)->vars)->alpha > 255.0F) {
            ((struct fade_vars *)&(work)->vars)->alpha = 255.0F;
            work->mode = FADE_BACK_HOLD;
        }
        break;
    case FADE_BACK_HOLD:
        fade_task_draw(task);
        if (((struct fade_vars *)&(work)->vars)->held++ > 60) {
            work->mode = FADE_BACK_LIGHTEN;
        }
        break;
    case FADE_BACK_LIGHTEN:
        fade_task_draw(task);
        ((struct fade_vars *)&(work)->vars)->alpha -= 6.0F;
        if (((struct fade_vars *)&(work)->vars)->alpha < 0.0F) {
            ((struct fade_vars *)&(work)->vars)->alpha = 0.0F;
            work->mode = FADE_BACK_END;
        }
        break;
    case FADE_BACK_END:
        FreeTask(task);
        break;
    }
}

void FUN_8c0438ac(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case FADE_START:
        task->draw = fade_task_draw;
        task->destructor = fade_task_destroy;
        work->mode = FADE_RUN;
        VARS(work)->alpha = 255.0F;
        /* fall through */
    case FADE_RUN:
        fade_task_draw(task);
        ((struct fade_vars *)&(work)->vars)->alpha -= 6.0F;
        if (((struct fade_vars *)&(work)->vars)->alpha < 0.0F) {
            ((struct fade_vars *)&(work)->vars)->alpha = 0.0F;
            work->mode = FADE_END;
        }
        break;
    case FADE_END:
        FreeTask(task);
        break;
    }
}

void fade_task_to_black(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case FADE_START:
        task->draw = fade_task_draw;
        task->destructor = fade_task_destroy;
        work->mode = FADE_RUN;
        /* fall through */
    case FADE_RUN:
        fade_task_draw(task);
        ((struct fade_vars *)&(work)->vars)->alpha += 6.0F;
        if (((struct fade_vars *)&(work)->vars)->alpha > 255.0F) {
            ((struct fade_vars *)&(work)->vars)->alpha = 255.0F;
            work->mode = FADE_END;
        }
        break;
    case FADE_END:
        fade_task_draw(task);
        FreeTask(task);
        break;
    }
}

void fade_set_cover(NJS_COLOR *color)
{
    fade_cover = *color;
}

void fade_get_cover(NJS_COLOR *color)
{
    if (color != NULL) {
        *color = fade_cover;
    }
}

void FUN_8c0439ae(void)
{
    int i;

    if (fade_cover.argb.a != 0) {
        for (i = 0; i < 4; i++) {
            cover_colors[i] = fade_cover;
        }
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                               NJD_COLOR_BLENDING_INVSRCALPHA);
        njDrawPolygon2D(&cover_quad, 4, -1.01F, NJD_FILL | NJD_TRANSPARENT);
    }
}
