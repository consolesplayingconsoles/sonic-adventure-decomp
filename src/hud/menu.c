/* @unit 8C0A5580-8C0A6800 @data 8C15B5FC-8C15B738 +r04 +egflags +pool32 +asmfunc=menu_blend_color:+8c0a59a4,DrawDialogs:+8c0a60b8,FUN_8c0a65e8:+8c0a662a,dialog_exec:+8c0a64f2,menu_popup:+8c0a6670,menu_popup_default:+8c0a66d2,menu_popup_eu:+8c0a676a,menu_popup_default_eu:+8c0a6770,DrawShadowWinCenter:+8c0a5bda,is_disable_csrs:+8c0a5cb2,menu_close:+8c0a67b4 +poolafter=program_select_step,DrawDlgCsrSqr,set_disable_csrs,DrawDialogBg,dialog_disp +align0=menu_set_cursor */
/* menus: the debug menu titled <SELECT PROGRAM>, and the menu task that
 * grows a menu open, moves its cursor and shrinks it closed */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "debug/editor.h"
#include "debug/fog_editor.h"
#include "debug/seq_editor.h"
#include "draw/screen.h"
#include "hud/menu.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "system/pad.h"
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
void pdExecPeripheralServerUser(void);
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
Bool OnEdit(struct task *task);
void ghSetPvrTexMaterial(Uint32 color);
void ghSetPvrTexVertexColor(Uint32 corner0, Uint32 corner1, Uint32 corner2,
                            Uint32 corner3);
Uint32 ghDefaultBlendingMode(Uint32 *colors);
void ghSetPvrTexBaseColor(Uint32 tint);
void ghDrawPvrTexture(int texture, Float x, Float y, Float z);
void ghDrawPvrTextureWH(int texture, Float x, Float y, Float z, Float width,
                        Float height);
void ghDrawPvrTextureS(int texture, Float x, Float y, Float z, Float scale_x,
                       Float scale_y);
void screen_cover_show(Bool manager_data);
void DrawShadowWindow(Float x, Float y, Float z, Float width, Float height);
void DrawTitleBack(Float x, Float y, Float z, Float width, Float height);
void FUN_8c0a5aa0(Uint32 color, Float x, Float y, Float z, Float scale_x,
                  Float scale_y);
void FUN_8c0a65e8(const struct menu *menu, Sint8 cursor, Sint8 *disabled);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Uint16 GetStageNumber(void);
Bool ChkPause(void);
extern PDS_PERIPHERAL perG[8];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);

/* program_select_step's modes. 1 is skipped: nothing sets program_mode to
 * it */
#define SCALE_STEPS 16 /* to grow a menu open, or to shrink it closed */
#define CHOSEN_STEPS 4 /* between a choice and the close */
#define CURSOR_SCALE 1.2F
#define BLINK_STEP 0x2d8
#define PULSE_MOVED 1.5F
#define PULSE_FALL 0.05F
#define DISABLED_SIZE 16
#define ROW_ITEM_COLOR 0xff0000ff
#define COLUMN_ITEM_COLOR 0xff12b4ff
#define CURSOR_ITEM_COLOR 0xffff0000
#define CURSOR_YELLOW 0xffeb00
#define CURSOR_ORANGE 0xec9800
enum program_mode {
    PROGRAM_SELECT = 0, /* the menu shows while X is held */
    PROGRAM_RUN = 2 /* the chosen program steps */
};

/* a program on the debug menu. init readies it once, and exec steps it
 * until it returns -1. a NULL init ends the table */
struct program {
    char name[16];
    void (*init)(void);
    int (*exec)(void);
};

/* the item under the cursor, and the cursor, are a fifth larger */

/* the cursor's blink turns this far a step: a whole blink in 90 steps,
 * near enough */
/* the cursor's pulse after a move, and its fall in a step */

/* room for 15 disabled items and the negative that ends them */

/* the items' colors, 0xAARRGGBB. the item under the cursor is
 * CURSOR_ITEM_COLOR, but while the menu waits for a choice it blinks
 * between that and its kind's color */

/* the cursor's colors, 0xRRGGBB under its alpha. a row's cursor runs from
 * yellow at its top to orange at its bottom, and a column's is orange */

enum menu_mode {
    MENU_IDLE, /* no menu yet */
    MENU_OPEN, /* growing open */
    MENU_CHOOSE, /* waiting while the pad moves the cursor */
    MENU_CHOSEN, /* chosen, and waiting CHOSEN_STEPS to close */
    MENU_CLOSE, /* shrinking closed */
    MENU_DONE /* closed, with the cursor on the choice */
};

/* the menu task's extra */
struct menu_work {
    const struct menu *menu;
    enum menu_mode mode;
    Uint32 tint; /* the whole menu's color, or 0 to hide it */
    Float scale_x, scale_y; /* the whole menu's, as it grows and shrinks */
    Float pulse; /* the cursor's scale: 1.5 after a move, settling to 1 */
    Uint32 cursor_color; /* the item under the cursor's */
    Uint32 item_color; /* the other items' */
    Angle blink; /* cursor_color follows its cosine */
    Sint16 idle; /* as menu_get_idle gives it */
    Sint16 step; /* steps into the mode */
    Sint8 cursor;
    Uint8 alpha; /* the cursor's, from its pulse */
    Sint8 disabled[DISABLED_SIZE]; /* items to skip, ending in a negative */
};

struct menu_scale {
    Float x, y;
};

struct menu_keys {
    Uint32 prev, next;
};

void program_select_draw(void);
Bool is_disable_csrs(Sint8 *list, Sint8 value);
void set_disable_csrs(Sint8 *disabled);
void dialog_exec(struct task *task);
void dialog_disp(struct task *task);
void menu_set_cursor(Sint8 cursor);
extern struct program program_table[];
extern enum program_mode program_mode;
extern int program_count;
extern int program_cursor;
extern int program_selected;

void program_select_init(void)
{
    struct program *program = program_table;

    program_count = 0;
    for (; program->init != NULL; program_count++, program++) {
        program->init();
    }
    light_editor_init();
    fog_editor_init();
    program_cursor = 0;
    program_mode = PROGRAM_SELECT;
}

void program_select_step(void)
{
    struct program *program;
    int result;

    switch (program_mode) {
    case PROGRAM_SELECT:
        if (per_info[0]->on & PDD_DGT_TX) {
            if (per_info[0]->press & PDD_DGT_KU) {
                program_cursor--;
            } else if (per_info[0]->press & PDD_DGT_KD) {
                program_cursor++;
            }
            if (program_cursor < 0) {
                program_cursor = program_count - 1;
            } else if (program_cursor >= program_count) {
                program_cursor = 0;
            }
            if (per_info[0]->press & PDD_DGT_ST) {
                program_selected = program_cursor;
                program_mode = PROGRAM_RUN;
            } else {
                program_select_draw();
                pause_disable();
            }
        } else {
            pause_enable();
        }
        break;
    case PROGRAM_RUN:
        program = &program_table[program_selected];
        result = program->exec();
        if (result == -1) {
            program_mode = PROGRAM_SELECT;
        }
        break;
    }
}

void program_select_draw(void)
{
    int i;

    njPrintColor(0xff00ff00);
    njPrintC(NJM_LOCATION(10, 6), "<SELECT PROGRAM>");
    njPrintColor(0xffc0c0c0);
    for (i = 0; i < program_count; i++) {
        njPrintC(NJM_LOCATION(10, i + 8), program_table[i].name);
    }
    njPrintColor(0xffff0000);
    njPrintC(NJM_LOCATION(9, program_cursor + 8), ">");
    njPrintColor(0xffffffff);
}

const struct menu_sounds menu_default_sounds = {SE_MENU_OPEN, SE_MENU_CLOSE,
                                                SE_MOVE, SE_CHOOSE, SE_CANCEL};
const Uint32 menu_open_scales_bits[32] = {
    0x3e4ccccc, 0x3e4ccccc, 0x3ecccccc, 0x3ecccccc, 0x3f199999, 0x3f199999,
    0x3f4ccccc, 0x3f4ccccc, 0x3f75c28f, 0x3f75c28f, 0x3f8f5c28, 0x3f8f5c28,
    0x3f999999, 0x3f999999, 0x3f947ae1, 0x3f947ae1, 0x3f8e147a, 0x3f8e147a,
    0x3f866666, 0x3f866666, 0x3f7d70a3, 0x3f7d70a3, 0x3f70a3d7, 0x3f70a3d7,
    0x3f666666, 0x3f666666, 0x3f733333, 0x3f733333, 0x3f7ae147, 0x3f7ae147,
    0x3f800000, 0x3f800000};
const Uint32 menu_close_scales_bits[32] = {
    0x3f8a3d70, 0x3f70a3d7, 0x3f9851eb, 0x3f599999, 0x3fa3d70a, 0x3f333333,
    0x3faccccc, 0x3f000000, 0x3fb33333, 0x3e999999, 0x3f999999, 0x3f000000,
    0x3f800000, 0x3f400000, 0x3f4ccccc, 0x3f800000, 0x3f199999, 0x3fb33333,
    0x3f000000, 0x3feccccc, 0x3ecccccc, 0x3fb33333, 0x3e800000, 0x3f800000,
    0x3e0f5c28, 0x3f000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000};
const struct menu_keys menu_keys_data[2] = {{0x40, 0x80}, {0x10, 0x20}};
extern NJS_TEXNAME row_texnames[4];
extern NJS_TEXLIST menu_row_texlist;
extern NJS_TEXNAME column_texnames[3];
extern NJS_TEXLIST menu_column_texlist;
extern struct task *menu_task;

/* set the cursor on the first item from cursor on that isn't disabled,
 * wrapping past the last */
void menu_set_cursor(Sint8 cursor)
{
    struct menu_work *work = menu_task->extra;
    Sint8 i;

    for (i = 0; i < work->menu->count; i++) {
        if (is_disable_csrs(work->disabled, cursor)) {
            cursor++;
            if (cursor >= work->menu->count) {
                cursor = 0;
            }
        }
    }
    work->cursor = cursor;
}

void SetDlgCsrStat(Uint8 *alpha, Angle *blink, Float *pulse)
{
    *blink += BLINK_STEP;
    *pulse = *pulse > 1.0F ? *pulse - PULSE_FALL : 1.0F;
    *alpha = (1.0F - njSqrt((*pulse - 1.0F) * 2.0F)) * 255.0F;
}
#ifdef NON_MATCHING

Uint32 menu_blend_color(Uint32 from, Uint32 to, Float part)
{
    Uint32 alpha;
    Uint32 red;
    Uint32 green;
    Uint32 blue;

    alpha = ((from >> 24) * (1.0F - part)) + ((to >> 24) * part);
    red =
        (((from >> 16) & 0xff) * (1.0F - part)) + (((to >> 16) & 0xff) * part);
    green =
        (((from >> 8) & 0xff) * (1.0F - part)) + (((to >> 8) & 0xff) * part);
    blue = ((from & 0xff) * (1.0F - part)) + ((to & 0xff) * part);
    return (alpha << 24) | (red << 16) | (green << 8) | blue;
}
#else
Uint32 menu_blend_color(Uint32 from, Uint32 to, Float part)
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
    asm_stub[0] = 32;
    asm_stub[1] = 33;
    asm_stub[2] = 34;
    asm_stub[3] = 35;
    asm_stub[4] = 36;
    asm_stub[5] = 37;
    asm_stub[6] = 38;
    asm_stub[7] = 39;
    asm_stub[0] = 40;
    asm_stub[1] = 41;
    asm_stub[2] = 42;
    asm_stub[3] = 43;
    asm_stub[4] = 44;
    asm_stub[5] = 45;
    asm_stub[6] = 46;
    asm_stub[7] = 47;
    asm_stub[0] = 48;
    asm_stub[1] = 49;
    asm_stub[2] = 50;
    asm_stub[3] = 51;
    asm_stub[4] = 52;
    asm_stub[5] = 53;
    asm_stub[6] = 54;
    asm_stub[7] = 55;
    asm_stub[0] = 56;
    asm_stub[1] = 57;
    asm_stub[2] = 58;
    asm_stub[3] = 59;
    asm_stub[4] = 60;
    asm_stub[5] = 61;
    asm_stub[6] = 62;
    asm_stub[7] = 63;
    asm_stub[0] = 64;
    asm_stub[1] = 65;
    asm_stub[2] = 66;
    asm_stub[3] = 67;
    asm_stub[4] = 68;
    asm_stub[5] = 69;
    asm_stub[6] = 70;
    asm_stub[7] = 71;
    asm_stub[0] = 72;
    asm_stub[1] = 73;
    asm_stub[2] = 74;
    asm_stub[3] = 75;
    asm_stub[4] = 76;
    asm_stub[5] = 77;
    return asm_stub[0];
}
#endif

void DrawDlgCsr(int alpha, Float x, Float y, Float z, Float scale_x,
                Float scale_y)
{
    /* @hack type: the cast to Uint32 on top's alpha alone, which has SHC
     * extend alpha once for each color (EXTU.B at 0x8c0abd6c and
     * 0x8c0abd74); with the same cast on both, 37 of 48 words differ */
    Uint32 top = ((Uint32)(Uint8)alpha << 24) | CURSOR_YELLOW;
    Uint32 bottom = ((Uint8)alpha << 24) | CURSOR_ORANGE;

    njSetTexture_jp(&menu_row_texlist);
    ghSetPvrTexVertexColor(top, bottom, top, bottom);
    ghDrawPvrTextureS(QUAD_CENTERED | 3, x, y, z, scale_x, scale_y);
}

/* @hack type: an old-style definition, so that a caller passes alpha as an
 * int and this function reads it as a Uint8; with a prototype taking int
 * alpha, cast as menu_draw_row_cursor casts it, 37 of 39 words differ */
/* clang-format off */
/* NOLINTNEXTLINE(clang-diagnostic-deprecated-non-prototype) */
void DrawDlgCsrSqr(alpha, x, y, z, scale_x, scale_y)
    Uint8 alpha;
    Float x, y, z, scale_x, scale_y;
{ njSetTexture_jp ( & menu_column_texlist ) ; ghSetPvrTexMaterial ( ( ( Uint32 ) alpha << 24 ) | 0xec9800 ) ; ghDrawPvrTextureS ( 0x04000000 | 2 , x , y , z , scale_x , scale_y ) ; } void FUN_8c0a5aa0 ( Uint32 color , Float x , Float y , Float z , Float scale_x , Float scale_y ) { njSetTexture_jp ( & menu_row_texlist ) ; ghSetPvrTexMaterial ( color ) ; ghDrawPvrTextureS ( 0x04000000 | 2 , x , y , z - 0.3F , scale_x , scale_y ) ; ghSetPvrTexMaterial ( ( color & 0xff000000 ) | 0xffffff ) ; ghDrawPvrTextureS ( 0x04000000 | 1 , x , y , z - 0.6F , scale_x , scale_y ) ; } void DrawSquareC ( Uint32 color , Float x , Float y , Float z , Float scale_x , Float scale_y ) { njSetTexture_jp ( & menu_column_texlist ) ; ghSetPvrTexMaterial ( color ) ; ghDrawPvrTextureS ( 0x04000000 | 0 , x , y , z - 0.3F , scale_x , scale_y ) ; ghSetPvrTexMaterial ( ( color & 0xff000000 ) | 0xffffff ) ; ghDrawPvrTextureS ( 0x04000000 | 1 , x , y , z , scale_x * 1.0460432F , scale_y * 1.1770245F ) ; } void menu_draw_box_eu ( Float x , Float y , Float z , Float width , Float height ) { DrawShadowWindow ( x - ( width * 0.5F ) , y - ( height * 0.5F ) , z , width , height ) ; }
#ifdef NON_MATCHING
void DrawShadowWinCenter ( struct menu_work * work ) { work -> tint = 0 ; work -> scale_x = 0.0F ; work -> scale_y = 0.0F ; work -> pulse = 1.0F ; work -> idle = 0 ; work -> step = 0 ; set_disable_csrs ( ( ( void * ) 0 ) ) ; }
#else
void DrawShadowWinCenter ( struct menu_work * work ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; }
#endif
void set_disable_csrs ( Sint8 * disabled ) { struct menu_work * work = menu_task -> extra ; int i ; int j = 0 ; if ( disabled != ( ( void * ) 0 ) ) { do { work -> disabled [ j ++ ] = * disabled ; } while ( * disabled ++ >= 0 ) ; } else { for ( i = 0 ; i < 16 ; i ++ ) { work -> disabled [ i ] = - 1 ; } } }
#ifdef NON_MATCHING
Bool is_disable_csrs ( Sint8 * list , Sint8 value ) { Bool found = ( 0 ) ; while ( * list >= 0 ) { if ( value == * list ) { found = ( 1 ) ; } list ++ ; } return found ; }
#else
Bool is_disable_csrs ( Sint8 * list , Sint8 value ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; return asm_stub [ 0 ] ; }
#endif
Sint8 csrs_next ( Sint8 * disabled , Sint8 cursor , Sint8 count ) { Sint8 start ; if ( cursor == count - 1 ) { return cursor ; } start = cursor ; do { cursor ++ ; if ( ! is_disable_csrs ( disabled , cursor ) ) { return cursor ; } } while ( cursor < count - 1 ) ; return start ; }
Sint8 csrs_prev ( Sint8 * disabled , Sint8 cursor ) { Sint8 start ; if ( cursor <= 0 ) { return cursor ; } start = cursor ; do { cursor -- ; if ( ! is_disable_csrs ( disabled , cursor ) ) { return cursor ; } } while ( cursor > 0 ) ; return start ; }
void DrawDialogBg ( struct menu_work * work ) { const struct menu * menu = work -> menu ; screen_blend_alpha ( ) ; ghSetPvrTexVertexColor ( menu -> frame_top , menu -> frame_bottom , menu -> frame_top , menu -> frame_bottom ) ; menu_draw_box_eu ( menu -> x , menu -> y , menu -> z - 4.0F , menu -> frame_w * work -> scale_x , menu -> frame_h * work -> scale_y ) ; }
#ifdef NON_MATCHING
void DrawDialogs ( struct menu_work * work ) { const struct menu * menu = work -> menu ; Float x ; Float y ; Float scale_x ; Float scale_y ; Uint32 color ; Uint32 tint ; int alpha ; Sint8 i ; for ( i = 0 ; i < menu -> count ; i ++ ) { x = menu -> x + ( menu -> items [ i ] . x * work -> scale_x ) ; y = menu -> y + ( menu -> items [ i ] . y * work -> scale_y ) ; if ( work -> cursor == i ) { scale_x = work -> scale_x * 1.2F ; scale_y = work -> scale_y * 1.2F ; } else { scale_x = work -> scale_x * 1.0F ; scale_y = work -> scale_y * 1.0F ; } if ( is_disable_csrs ( work -> disabled , i ) ) { color = ( work -> item_color & 0xffffff ) | 0x30000000 ; tint = 0xb0ffffff ; } else { color = work -> cursor == i ? work -> cursor_color : work -> item_color ; tint = 0xffffffff ; } switch ( menu -> kind ) { case MENU_ROW : FUN_8c0a5aa0 ( color , x , y , menu -> z - 6.0F , menu -> item_scale_x * scale_x , menu -> item_scale_y * scale_y ) ; break ; case MENU_COLUMN : DrawSquareC ( color , x , y , menu -> z - 6.0F , menu -> item_scale_x * scale_x , menu -> item_scale_y * scale_y ) ; break ; } njSetTexture_jp ( menu -> texlist ) ; ghSetPvrTexMaterial ( tint ) ; ghDrawPvrTextureS ( menu -> items [ i ] . texture | 0x04000000 , x , y , menu -> z - 8.0F , scale_x , scale_y ) ; } if ( work -> cursor < menu -> count ) { alpha = is_disable_csrs ( work -> disabled , work -> cursor ) ? work -> alpha / 2 : work -> alpha ; scale_x = menu -> item_scale_x * work -> scale_x * work -> pulse * 1.2F ; scale_y = menu -> item_scale_y * work -> scale_y * work -> pulse * 1.2F ; switch ( menu -> kind ) { case MENU_ROW : DrawDlgCsr ( alpha , menu -> x + ( menu -> items [ work -> cursor ] . x * work -> scale_x ) , menu -> y + ( menu -> items [ work -> cursor ] . y * work -> scale_y ) , menu -> z - 10.0F , scale_x , scale_y ) ; break ; case MENU_COLUMN : DrawDlgCsrSqr ( alpha , menu -> x + ( menu -> items [ work -> cursor ] . x * work -> scale_x ) , menu -> y + ( menu -> items [ work -> cursor ] . y * work -> scale_y ) , menu -> z - 10.0F , scale_x , scale_y ) ; break ; } } }
#else
void DrawDialogs ( struct menu_work * work ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; asm_stub [ 0 ] = 24 ; asm_stub [ 1 ] = 25 ; asm_stub [ 2 ] = 26 ; asm_stub [ 3 ] = 27 ; asm_stub [ 4 ] = 28 ; asm_stub [ 5 ] = 29 ; asm_stub [ 6 ] = 30 ; asm_stub [ 7 ] = 31 ; asm_stub [ 0 ] = 32 ; asm_stub [ 1 ] = 33 ; asm_stub [ 2 ] = 34 ; asm_stub [ 3 ] = 35 ; asm_stub [ 4 ] = 36 ; asm_stub [ 5 ] = 37 ; asm_stub [ 6 ] = 38 ; asm_stub [ 7 ] = 39 ; asm_stub [ 0 ] = 40 ; asm_stub [ 1 ] = 41 ; asm_stub [ 2 ] = 42 ; asm_stub [ 3 ] = 43 ; asm_stub [ 4 ] = 44 ; asm_stub [ 5 ] = 45 ; asm_stub [ 6 ] = 46 ; asm_stub [ 7 ] = 47 ; asm_stub [ 0 ] = 48 ; asm_stub [ 1 ] = 49 ; asm_stub [ 2 ] = 50 ; asm_stub [ 3 ] = 51 ; asm_stub [ 4 ] = 52 ; asm_stub [ 5 ] = 53 ; asm_stub [ 6 ] = 54 ; asm_stub [ 7 ] = 55 ; asm_stub [ 0 ] = 56 ; asm_stub [ 1 ] = 57 ; asm_stub [ 2 ] = 58 ; asm_stub [ 3 ] = 59 ; asm_stub [ 4 ] = 60 ; asm_stub [ 5 ] = 61 ; asm_stub [ 6 ] = 62 ; asm_stub [ 7 ] = 63 ; asm_stub [ 0 ] = 64 ; asm_stub [ 1 ] = 65 ; asm_stub [ 2 ] = 66 ; asm_stub [ 3 ] = 67 ; asm_stub [ 4 ] = 68 ; asm_stub [ 5 ] = 69 ; asm_stub [ 6 ] = 70 ; asm_stub [ 7 ] = 71 ; asm_stub [ 0 ] = 72 ; asm_stub [ 1 ] = 73 ; asm_stub [ 2 ] = 74 ; asm_stub [ 3 ] = 75 ; asm_stub [ 4 ] = 76 ; asm_stub [ 5 ] = 77 ; asm_stub [ 6 ] = 78 ; asm_stub [ 7 ] = 79 ; asm_stub [ 0 ] = 80 ; asm_stub [ 1 ] = 81 ; asm_stub [ 2 ] = 82 ; asm_stub [ 3 ] = 83 ; asm_stub [ 4 ] = 84 ; asm_stub [ 5 ] = 85 ; asm_stub [ 6 ] = 86 ; asm_stub [ 7 ] = 87 ; asm_stub [ 0 ] = 88 ; asm_stub [ 1 ] = 89 ; asm_stub [ 2 ] = 90 ; asm_stub [ 3 ] = 91 ; asm_stub [ 4 ] = 92 ; asm_stub [ 5 ] = 93 ; asm_stub [ 6 ] = 94 ; asm_stub [ 7 ] = 95 ; asm_stub [ 0 ] = 96 ; asm_stub [ 1 ] = 97 ; asm_stub [ 2 ] = 98 ; asm_stub [ 3 ] = 99 ; asm_stub [ 4 ] = 100 ; asm_stub [ 5 ] = 101 ; asm_stub [ 6 ] = 102 ; asm_stub [ 7 ] = 103 ; asm_stub [ 0 ] = 104 ; asm_stub [ 1 ] = 105 ; asm_stub [ 2 ] = 106 ; asm_stub [ 3 ] = 107 ; asm_stub [ 4 ] = 108 ; asm_stub [ 5 ] = 109 ; asm_stub [ 6 ] = 110 ; asm_stub [ 7 ] = 111 ; asm_stub [ 0 ] = 112 ; asm_stub [ 1 ] = 113 ; asm_stub [ 2 ] = 114 ; asm_stub [ 3 ] = 115 ; asm_stub [ 4 ] = 116 ; asm_stub [ 5 ] = 117 ; asm_stub [ 6 ] = 118 ; asm_stub [ 7 ] = 119 ; asm_stub [ 0 ] = 120 ; asm_stub [ 1 ] = 121 ; asm_stub [ 2 ] = 122 ; asm_stub [ 3 ] = 123 ; asm_stub [ 4 ] = 124 ; asm_stub [ 5 ] = 125 ; asm_stub [ 6 ] = 126 ; asm_stub [ 7 ] = 127 ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; asm_stub [ 0 ] = 24 ; asm_stub [ 1 ] = 25 ; asm_stub [ 2 ] = 26 ; asm_stub [ 3 ] = 27 ; asm_stub [ 4 ] = 28 ; asm_stub [ 5 ] = 29 ; }
#endif
void menu_init ( struct task * task ) { struct menu_work * work = task -> extra ; work -> menu = ( ( void * ) 0 ) ; work -> mode = MENU_IDLE ; DrawShadowWinCenter ( work ) ; }
#ifdef NON_MATCHING
void dialog_exec ( struct task * task ) { struct menu_work * work = task -> extra ; const struct menu * menu = work -> menu ; Sint8 cursor ; Uint32 buttons ; SetDlgCsrStat ( & work -> alpha , & work -> blink , & work -> pulse ) ; work -> cursor_color = 0xffff0000 ; if ( menu != ( ( void * ) 0 ) ) { switch ( menu -> kind ) { case MENU_ROW : work -> item_color = 0xff0000ff ; break ; case MENU_COLUMN : work -> item_color = 0xff12b4ff ; break ; } } else { work -> item_color = 0xff12b4ff ; } switch ( work -> mode ) { case MENU_IDLE : DrawShadowWinCenter ( work ) ; break ; case MENU_OPEN : work -> tint = 0xffffffff ; work -> scale_x = menu_open_scales [ work -> step ] . x ; work -> scale_y = menu_open_scales [ work -> step ] . y ; work -> step ++ ; if ( work -> step >= 16 ) { work -> blink = 0 ; work -> mode = MENU_CHOOSE ; } break ; case MENU_CHOOSE : work -> tint = 0xffffffff ; work -> scale_x = work -> scale_y = 1.0F ; switch ( menu -> kind ) { case MENU_ROW : work -> cursor_color = menu_blend_color ( 0xff0000ff , 0xffff0000 , ( njCos ( work -> blink ) + 1.0F ) * 0.5F ) ; break ; case MENU_COLUMN : work -> cursor_color = menu_blend_color ( 0xff12b4ff , 0xffff0000 , ( njCos ( work -> blink ) + 1.0F ) * 0.5F ) ; break ; } cursor = work -> cursor ; if ( ( pad_press_repeat [ 0 ] & menu_keys [ menu -> kind ] . prev ) && work -> cursor > 0 ) { work -> cursor = csrs_prev ( work -> disabled , work -> cursor ) ; } else if ( ( pad_press_repeat [ 0 ] & menu_keys [ menu -> kind ] . next ) && work -> cursor < menu -> count - 1 ) { work -> cursor = csrs_next ( work -> disabled , work -> cursor , menu -> count ) ; } else if ( ( buttons = pad_press_repeat [ 0 ] , ( buttons & ( 1 << 2 ) ) | ( buttons & ( 1 << 3 ) ) ) ) { if ( ! is_disable_csrs ( work -> disabled , work -> cursor ) ) { work -> step = 0 ; work -> mode = MENU_CHOSEN ; if ( menu -> sounds != ( ( void * ) 0 ) ) { dsPlay_oneshot ( work -> cursor == menu -> cancel ? menu -> sounds -> cancel : menu -> sounds -> select , 0 , 0 , 0 ) ; } } } else if ( ( buttons & ( 1 << 1 ) ) | ( buttons & ( 1 << 10 ) ) ) { work -> cursor = menu -> cancel ; work -> step = 0 ; work -> mode = MENU_CHOSEN ; if ( menu -> sounds != ( ( void * ) 0 ) ) { dsPlay_oneshot ( menu -> sounds -> cancel , 0 , 0 , 0 ) ; } } if ( cursor != work -> cursor ) { work -> idle = 0 ; work -> pulse = 1.5F ; if ( menu -> sounds != ( ( void * ) 0 ) ) { dsPlay_oneshot ( menu -> sounds -> move , 0 , 0 , 0 ) ; } } else if ( work -> idle < 0x7fff ) { work -> idle ++ ; } break ; case MENU_CHOSEN : work -> step ++ ; if ( work -> step >= 4 ) { work -> step = 0 ; work -> mode = MENU_CLOSE ; if ( menu -> sounds != ( ( void * ) 0 ) ) { dsPlay_oneshot ( menu -> sounds -> close , 0 , 0 , 0 ) ; } } break ; case MENU_CLOSE : work -> tint = 0xffffffff ; work -> scale_x = menu_close_scales [ work -> step ] . x ; work -> scale_y = menu_close_scales [ work -> step ] . y ; work -> step ++ ; if ( work -> step >= 16 ) { DrawShadowWinCenter ( work ) ; work -> mode = MENU_DONE ; } break ; case MENU_DONE : break ; } }
#else
void dialog_exec ( struct task * task ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; asm_stub [ 0 ] = 24 ; asm_stub [ 1 ] = 25 ; asm_stub [ 2 ] = 26 ; asm_stub [ 3 ] = 27 ; asm_stub [ 4 ] = 28 ; asm_stub [ 5 ] = 29 ; asm_stub [ 6 ] = 30 ; asm_stub [ 7 ] = 31 ; asm_stub [ 0 ] = 32 ; asm_stub [ 1 ] = 33 ; asm_stub [ 2 ] = 34 ; asm_stub [ 3 ] = 35 ; asm_stub [ 4 ] = 36 ; asm_stub [ 5 ] = 37 ; asm_stub [ 6 ] = 38 ; asm_stub [ 7 ] = 39 ; asm_stub [ 0 ] = 40 ; asm_stub [ 1 ] = 41 ; asm_stub [ 2 ] = 42 ; asm_stub [ 3 ] = 43 ; asm_stub [ 4 ] = 44 ; asm_stub [ 5 ] = 45 ; asm_stub [ 6 ] = 46 ; asm_stub [ 7 ] = 47 ; asm_stub [ 0 ] = 48 ; asm_stub [ 1 ] = 49 ; asm_stub [ 2 ] = 50 ; asm_stub [ 3 ] = 51 ; asm_stub [ 4 ] = 52 ; asm_stub [ 5 ] = 53 ; asm_stub [ 6 ] = 54 ; asm_stub [ 7 ] = 55 ; asm_stub [ 0 ] = 56 ; asm_stub [ 1 ] = 57 ; asm_stub [ 2 ] = 58 ; asm_stub [ 3 ] = 59 ; asm_stub [ 4 ] = 60 ; asm_stub [ 5 ] = 61 ; asm_stub [ 6 ] = 62 ; asm_stub [ 7 ] = 63 ; asm_stub [ 0 ] = 64 ; asm_stub [ 1 ] = 65 ; asm_stub [ 2 ] = 66 ; asm_stub [ 3 ] = 67 ; asm_stub [ 4 ] = 68 ; asm_stub [ 5 ] = 69 ; asm_stub [ 6 ] = 70 ; asm_stub [ 7 ] = 71 ; asm_stub [ 0 ] = 72 ; asm_stub [ 1 ] = 73 ; asm_stub [ 2 ] = 74 ; asm_stub [ 3 ] = 75 ; asm_stub [ 4 ] = 76 ; asm_stub [ 5 ] = 77 ; asm_stub [ 6 ] = 78 ; asm_stub [ 7 ] = 79 ; asm_stub [ 0 ] = 80 ; asm_stub [ 1 ] = 81 ; asm_stub [ 2 ] = 82 ; asm_stub [ 3 ] = 83 ; asm_stub [ 4 ] = 84 ; asm_stub [ 5 ] = 85 ; asm_stub [ 6 ] = 86 ; asm_stub [ 7 ] = 87 ; asm_stub [ 0 ] = 88 ; asm_stub [ 1 ] = 89 ; asm_stub [ 2 ] = 90 ; asm_stub [ 3 ] = 91 ; asm_stub [ 4 ] = 92 ; asm_stub [ 5 ] = 93 ; asm_stub [ 6 ] = 94 ; asm_stub [ 7 ] = 95 ; asm_stub [ 0 ] = 96 ; asm_stub [ 1 ] = 97 ; asm_stub [ 2 ] = 98 ; asm_stub [ 3 ] = 99 ; asm_stub [ 4 ] = 100 ; asm_stub [ 5 ] = 101 ; asm_stub [ 6 ] = 102 ; asm_stub [ 7 ] = 103 ; asm_stub [ 0 ] = 104 ; asm_stub [ 1 ] = 105 ; asm_stub [ 2 ] = 106 ; asm_stub [ 3 ] = 107 ; asm_stub [ 4 ] = 108 ; asm_stub [ 5 ] = 109 ; asm_stub [ 6 ] = 110 ; asm_stub [ 7 ] = 111 ; asm_stub [ 0 ] = 112 ; asm_stub [ 1 ] = 113 ; asm_stub [ 2 ] = 114 ; asm_stub [ 3 ] = 115 ; asm_stub [ 4 ] = 116 ; asm_stub [ 5 ] = 117 ; asm_stub [ 6 ] = 118 ; asm_stub [ 7 ] = 119 ; asm_stub [ 0 ] = 120 ; asm_stub [ 1 ] = 121 ; asm_stub [ 2 ] = 122 ; asm_stub [ 3 ] = 123 ; asm_stub [ 4 ] = 124 ; asm_stub [ 5 ] = 125 ; asm_stub [ 6 ] = 126 ; asm_stub [ 7 ] = 127 ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; asm_stub [ 0 ] = 24 ; asm_stub [ 1 ] = 25 ; asm_stub [ 2 ] = 26 ; asm_stub [ 3 ] = 27 ; asm_stub [ 4 ] = 28 ; asm_stub [ 5 ] = 29 ; asm_stub [ 6 ] = 30 ; asm_stub [ 7 ] = 31 ; asm_stub [ 0 ] = 32 ; asm_stub [ 1 ] = 33 ; asm_stub [ 2 ] = 34 ; asm_stub [ 3 ] = 35 ; asm_stub [ 4 ] = 36 ; asm_stub [ 5 ] = 37 ; asm_stub [ 6 ] = 38 ; asm_stub [ 7 ] = 39 ; asm_stub [ 0 ] = 40 ; asm_stub [ 1 ] = 41 ; asm_stub [ 2 ] = 42 ; asm_stub [ 3 ] = 43 ; asm_stub [ 4 ] = 44 ; asm_stub [ 5 ] = 45 ; asm_stub [ 6 ] = 46 ; asm_stub [ 7 ] = 47 ; asm_stub [ 0 ] = 48 ; asm_stub [ 1 ] = 49 ; asm_stub [ 2 ] = 50 ; asm_stub [ 3 ] = 51 ; asm_stub [ 4 ] = 52 ; asm_stub [ 5 ] = 53 ; asm_stub [ 6 ] = 54 ; asm_stub [ 7 ] = 55 ; asm_stub [ 0 ] = 56 ; asm_stub [ 1 ] = 57 ; asm_stub [ 2 ] = 58 ; asm_stub [ 3 ] = 59 ; asm_stub [ 4 ] = 60 ; asm_stub [ 5 ] = 61 ; asm_stub [ 6 ] = 62 ; asm_stub [ 7 ] = 63 ; asm_stub [ 0 ] = 64 ; asm_stub [ 1 ] = 65 ; asm_stub [ 2 ] = 66 ; asm_stub [ 3 ] = 67 ; asm_stub [ 4 ] = 68 ; asm_stub [ 5 ] = 69 ; asm_stub [ 6 ] = 70 ; asm_stub [ 7 ] = 71 ; asm_stub [ 0 ] = 72 ; asm_stub [ 1 ] = 73 ; asm_stub [ 2 ] = 74 ; asm_stub [ 3 ] = 75 ; asm_stub [ 4 ] = 76 ; asm_stub [ 5 ] = 77 ; asm_stub [ 6 ] = 78 ; asm_stub [ 7 ] = 79 ; asm_stub [ 0 ] = 80 ; asm_stub [ 1 ] = 81 ; asm_stub [ 2 ] = 82 ; asm_stub [ 3 ] = 83 ; asm_stub [ 4 ] = 84 ; asm_stub [ 5 ] = 85 ; asm_stub [ 6 ] = 86 ; asm_stub [ 7 ] = 87 ; asm_stub [ 0 ] = 88 ; asm_stub [ 1 ] = 89 ; asm_stub [ 2 ] = 90 ; asm_stub [ 3 ] = 91 ; asm_stub [ 4 ] = 92 ; asm_stub [ 5 ] = 93 ; asm_stub [ 6 ] = 94 ; asm_stub [ 7 ] = 95 ; asm_stub [ 0 ] = 96 ; asm_stub [ 1 ] = 97 ; asm_stub [ 2 ] = 98 ; asm_stub [ 3 ] = 99 ; asm_stub [ 4 ] = 100 ; asm_stub [ 5 ] = 101 ; asm_stub [ 6 ] = 102 ; asm_stub [ 7 ] = 103 ; asm_stub [ 0 ] = 104 ; asm_stub [ 1 ] = 105 ; asm_stub [ 2 ] = 106 ; asm_stub [ 3 ] = 107 ; asm_stub [ 4 ] = 108 ; asm_stub [ 5 ] = 109 ; asm_stub [ 6 ] = 110 ; asm_stub [ 7 ] = 111 ; asm_stub [ 0 ] = 112 ; asm_stub [ 1 ] = 113 ; asm_stub [ 2 ] = 114 ; asm_stub [ 3 ] = 115 ; asm_stub [ 4 ] = 116 ; asm_stub [ 5 ] = 117 ; asm_stub [ 6 ] = 118 ; asm_stub [ 7 ] = 119 ; asm_stub [ 0 ] = 120 ; asm_stub [ 1 ] = 121 ; asm_stub [ 2 ] = 122 ; asm_stub [ 3 ] = 123 ; asm_stub [ 4 ] = 124 ; asm_stub [ 5 ] = 125 ; asm_stub [ 6 ] = 126 ; asm_stub [ 7 ] = 127 ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; }
#endif
void dialog_disp ( struct task * task ) { struct menu_work * work = task -> extra ; struct menu_view view ; if ( work -> tint == 0 ) { return ; } if ( work -> scale_x == 0.0F && work -> scale_y == 0.0F ) { return ; } ghSetPvrTexBaseColor ( work -> tint ) ; DrawDialogBg ( work ) ; DrawDialogs ( work ) ; if ( work -> menu -> draw != ( ( void * ) 0 ) ) { view . x = work -> menu -> x ; view . y = work -> menu -> y ; view . z = work -> menu -> z ; view . scale_x = work -> scale_x ; view . scale_y = work -> scale_y ; view . cursor = work -> cursor ; work -> menu -> draw ( & view ) ; } }
struct task * SetDialogTask ( void ) { struct task * task ; struct menu_work * work ; if ( ( menu_task = task = CreateElementalTask ( 0x8 , 3 , dialog_exec ) ) != ( ( void * ) 0 ) ) { work = MAlloc ( 64 ) ; task -> extra = work ; menu_init ( task ) ; task -> step = dialog_exec ; task -> draw = dialog_disp ; } return task ; }
void menu_kill ( void ) { if ( menu_task != ( ( void * ) 0 ) ) { FreeTask ( menu_task ) ; } }
#ifdef NON_MATCHING
void FUN_8c0a65e8 ( const struct menu * menu , Sint8 cursor , Sint8 * disabled ) { struct menu_work * work ; ( ( struct menu_work * ) menu_task -> extra ) -> menu = menu ; set_disable_csrs ( disabled ) ; menu_set_cursor ( cursor ) ; menu_set_idle ( 0 ) ; work = menu_task -> extra ; work -> blink = 0 ; work -> mode = MENU_CHOOSE ; }
#else
void FUN_8c0a65e8 ( const struct menu * menu , Sint8 cursor , Sint8 * disabled ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; }
#endif
#ifdef NON_MATCHING
void menu_popup ( const struct menu * menu , Sint8 cursor , Sint8 * disabled ) { ( ( struct menu_work * ) menu_task -> extra ) -> menu = menu ; ( ( struct menu_work * ) menu_task -> extra ) -> mode = MENU_OPEN ; set_disable_csrs ( disabled ) ; menu_set_cursor ( cursor ) ; menu_set_idle ( 0 ) ; if ( menu -> sounds != ( ( void * ) 0 ) ) { dsPlay_oneshot ( menu -> sounds -> open , 0 , 0 , 0 ) ; } }
#else
void menu_popup ( const struct menu * menu , Sint8 cursor , Sint8 * disabled ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; }
#endif
#ifdef NON_MATCHING
void menu_popup_default ( const struct menu * menu ) { menu_popup ( menu , 0 , ( ( void * ) 0 ) ) ; }
#else
void menu_popup_default ( const struct menu * menu ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; }
#endif
#ifdef NON_MATCHING
void menu_popup_eu ( const struct menu * menu , Sint8 cursor , Sint8 * disabled ) { }
#else
void menu_popup_eu ( const struct menu * menu , Sint8 cursor , Sint8 * disabled ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; asm_stub [ 0 ] = 24 ; asm_stub [ 1 ] = 25 ; asm_stub [ 2 ] = 26 ; asm_stub [ 3 ] = 27 ; asm_stub [ 4 ] = 28 ; asm_stub [ 5 ] = 29 ; asm_stub [ 6 ] = 30 ; asm_stub [ 7 ] = 31 ; asm_stub [ 0 ] = 32 ; asm_stub [ 1 ] = 33 ; asm_stub [ 2 ] = 34 ; asm_stub [ 3 ] = 35 ; asm_stub [ 4 ] = 36 ; asm_stub [ 5 ] = 37 ; }
#endif
#ifdef NON_MATCHING
void menu_popup_default_eu ( const struct menu * menu ) { }
#else
void menu_popup_default_eu ( const struct menu * menu ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; }
#endif
int menu_result ( void ) { struct menu_work * work = menu_task -> extra ; if ( work -> mode >= MENU_DONE ) { return work -> cursor ; } return - 1 ; }
#ifdef NON_MATCHING
Bool menu_close ( void ) { struct menu_work * work = menu_task -> extra ; if ( work -> mode < MENU_CHOOSE ) { return ( 0 ) ; } else if ( work -> mode == MENU_CHOOSE ) { work -> step = 4 ; work -> mode = MENU_CHOSEN ; } return ( 1 ) ; }
#else
Bool menu_close ( void ) { volatile int asm_stub [ 8 ] ; asm_stub [ 0 ] = 0 ; asm_stub [ 1 ] = 1 ; asm_stub [ 2 ] = 2 ; asm_stub [ 3 ] = 3 ; asm_stub [ 4 ] = 4 ; asm_stub [ 5 ] = 5 ; asm_stub [ 6 ] = 6 ; asm_stub [ 7 ] = 7 ; asm_stub [ 0 ] = 8 ; asm_stub [ 1 ] = 9 ; asm_stub [ 2 ] = 10 ; asm_stub [ 3 ] = 11 ; asm_stub [ 4 ] = 12 ; asm_stub [ 5 ] = 13 ; asm_stub [ 6 ] = 14 ; asm_stub [ 7 ] = 15 ; asm_stub [ 0 ] = 16 ; asm_stub [ 1 ] = 17 ; asm_stub [ 2 ] = 18 ; asm_stub [ 3 ] = 19 ; asm_stub [ 4 ] = 20 ; asm_stub [ 5 ] = 21 ; asm_stub [ 6 ] = 22 ; asm_stub [ 7 ] = 23 ; return asm_stub [ 0 ] ; }
#endif
Sint16 menu_get_idle ( void ) { struct menu_work * work = menu_task -> extra ; return work -> idle ; }
void menu_set_idle ( Sint16 idle ) { struct menu_work * work = menu_task -> extra ; work -> idle = idle ; }
