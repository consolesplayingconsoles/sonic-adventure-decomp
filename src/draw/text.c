/* @unit 8C041E60-8C042DC0 @data 8C11298C-8C112994 +egflags +pool32 +poolbra=text_draw_char:1,text_draw_char_front:1,FUN_8c042298:2,FUN_8c0425a0:11,FUN_8c042b22:2 +poolafter=FUN_8c042416,FUN_8c0425a0 +r04 +asmfunc=FUN_8c04298e */
/* debug text: a copy of ninja's print with a color and size of its own,
 * drawn with the font and polygon header njInitPrint sets up */
#include <kamui.h>
#include <machine.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "draw/text.h"
#include "system/frame.h"
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
void FUN_8c041e94(void);
void FUN_8c041e98(Uint16 size);
void FUN_8c042298(Int loc, const char *string);
void FUN_8c042416(Int loc, const char *string);
void FUN_8c0425a0(Int loc, Int value, Int digits);
void FUN_8c042880(Int loc, Uint32 value, Int digits);
void FUN_8c04298e(Int loc, Uint32 value, Int digits);
void FUN_8c042b22(Int loc, Float value, Int digits);
void FUN_8c042d3a(Int loc, const char *format, ...);
extern int loop_count;

/* a store queue writes to the 64 MB area its QACR register selects, at the
 * offset its own address carries. SQ_AREA(ptr) is ptr's area as QACR takes
 * it: ptr's bits 28 to 26, in bits 4 to 2 */
#define SQ_AREA(ptr) (((ptr) >> 24) & 0x1c)
/* the bits of a pointer that a store queue's address carries: its offset */
#define SQ_ADDRESS 0x03ffffff
/* the store queues' own addresses start here */
#define SQ_BASE 0xe0000000
/* the bits of a list's write pointer above its offset */
#define LIST_TOP 0xfc000000

/* the SH-4's store queue address control registers, one for each queue */
#define QACR0 (*(Uint32 *)0xff000038)
#define QACR1 (*(Uint32 *)0xff00003c)

/* a list takes ENTRY_SIZE bytes at a time, as a store queue holds them: a
 * vertex, or a polygon header. the text writes a vertex's first
 * VERTEX_WRITTEN bytes, all but its offset color, and a polygon header's
 * first HEADER_WRITTEN, its four parameter words */
#define ENTRY_SIZE 32
#define VERTEX_WRITTEN 28
#define HEADER_WRITTEN 16

/* the index in _nj_context_ of the vertex context njInitPrint sets up */
#define DEBUG_CONTEXT 4

/* a global index no texture has. with _nj_current_texture at it, ninja's
 * next textured draw sets its texture again */
#define NO_TEXTURE (-2)

/* the color text_style_init sets, an opaque light gray, and the side of a
 * character's cell, in pixels */
#define TEXT_COLOR 0xffbfbfbf
#define TEXT_SIZE 16.0F

/* ninja's vertex contexts. njInitPrint has kamui compute the font's polygon
 * header into DEBUG_CONTEXT's */
/* NOLINTBEGIN(bugprone-reserved-identifier,readability-identifier-naming) */
#define SQ_PUT(type, value) (*(type *)(text_sq -= 4) = (value))
#define FONT_COLUMNS 16
#define FONT_CELL (1.0F / FONT_COLUMNS)
#define FONT_INSET (1.0F / 1024)
#define FONT_SPAN (FONT_CELL - FONT_INSET)
#define TEXT_INV_W 0.90909094F
#define FRONT_INV_W 2.0F
#define TEXT_OPEN()                                                            \
    _nj_current_texture = NO_TEXTURE;                                          \
    text_list_ptr =                                                            \
        (Uint32)(&_nj_vertex_buffer_)->pCurrentPtr[KM_TRANS_POLYGON];          \
    text_list_top = text_list_ptr & LIST_TOP;                                  \
    text_sq_area = SQ_AREA(text_list_ptr);                                     \
    QACR0 = text_sq_area;                                                      \
    QACR1 = text_sq_area;                                                      \
    text_sq = (Uint8 *)(SQ_BASE | (text_list_ptr & SQ_ADDRESS));               \
    text_sq += HEADER_WRITTEN;                                                 \
    SQ_PUT(Uint32, text_tex_param);                                            \
    SQ_PUT(Uint32, text_tsp_param);                                            \
    SQ_PUT(Uint32, text_isp_param);                                            \
    SQ_PUT(Uint32, text_global_param);                                         \
    prefetch(text_sq);                                                         \
    text_sq += ENTRY_SIZE;
#define TEXT_CLOSE()                                                           \
    ((&_nj_vertex_buffer_)->pCurrentPtr[KM_TRANS_POLYGON] =                    \
         (Uint32 *)(((Uint32)text_sq & SQ_ADDRESS) | text_list_top))
extern KMVERTEXCONTEXT _nj_context_[];
/* NOLINTEND(bugprone-reserved-identifier,readability-identifier-naming) */
/* ninja's vertex buffer, whose pCurrentPtr holds each list's write pointer */
extern KMVERTEXBUFFDESC _nj_vertex_buffer_;
extern char text_hex_digits[16];
extern Uint32 text_color;
extern Float text_size;
extern Uint32 text_tex_param;
extern Uint32 text_tsp_param;
extern Uint32 text_global_param;
extern Uint32 text_isp_param;
extern Uint8 *text_sq;
extern Uint32 text_list_ptr;
extern Uint32 text_sq_area;
extern Uint32 text_list_top;

void text_style_init(Uint32 *texture, Uint32 size, Uint32 attr)
{
    text_color = TEXT_COLOR;
    text_size = TEXT_SIZE;
    text_global_param = _nj_context_[DEBUG_CONTEXT].GLOBALPARAMBUFFER;
    text_isp_param = _nj_context_[DEBUG_CONTEXT].ISPPARAMBUFFER;
    text_tsp_param = _nj_context_[DEBUG_CONTEXT].TSPPARAMBUFFER;
    text_tex_param = _nj_context_[DEBUG_CONTEXT].TexturePARAMBUFFER;
}

void FUN_8c041e94(void)
{
}

void FUN_8c041e98(Uint16 size)
{
    text_size = size;
}

void text_set_color(Uint32 color)
{
    text_color = color;
}

/* step text_sq back 4 bytes and store value there */

/* the font's texture holds 16 rows of 16 characters. a character takes its
 * cell less FONT_INSET at the cell's top and left */

/* a vertex's 1/w, which kamui takes as its depth: a larger 1/w draws
 * nearer. text_draw_char's vertices take 1 / 1.1, and text_draw_char_front's
 * 2 */

/* send ch at x, y in pixels, the top left corner of its place on the
 * screen, as a strip of four vertices. each is written from its color back
 * to its control word, then sent by a prefetch of its start. the character
 * leans: its top runs from x + 1 to x + text_size + 4. its bottom runs from
 * x - 4 to x + text_size - 1. a '0' draws as the font's 'O' */
void text_draw_char(Sint16 x, Sint16 y, char ch)
{
    Sint16 col;
    Sint16 row;
    Float left;
    Float top;
    Float right;
    Float bottom;

    if (ch == '0') {
        ch = 'O';
    }
    col = ch % FONT_COLUMNS;
    row = ch / FONT_COLUMNS;
    left = (col * FONT_CELL) + FONT_INSET;
    top = (row * FONT_CELL) + FONT_INSET;
    right = left + FONT_SPAN;
    bottom = top + FONT_SPAN;
    text_sq += VERTEX_WRITTEN;
    SQ_PUT(Uint32, text_color);
    SQ_PUT(Float, top);
    SQ_PUT(Float, left);
    SQ_PUT(Float, TEXT_INV_W);
    SQ_PUT(Float, y);
    SQ_PUT(Float, x + 1.0F);
    SQ_PUT(Uint32, KM_VERTEXPARAM_NORMAL);
    prefetch(text_sq);
    text_sq += ENTRY_SIZE + VERTEX_WRITTEN;
    SQ_PUT(Uint32, text_color);
    SQ_PUT(Float, bottom);
    SQ_PUT(Float, left);
    SQ_PUT(Float, TEXT_INV_W);
    SQ_PUT(Float, y + text_size);
    SQ_PUT(Float, x - 4.0F);
    SQ_PUT(Uint32, KM_VERTEXPARAM_NORMAL);
    prefetch(text_sq);
    text_sq += ENTRY_SIZE + VERTEX_WRITTEN;
    SQ_PUT(Uint32, text_color);
    SQ_PUT(Float, top);
    SQ_PUT(Float, right);
    SQ_PUT(Float, TEXT_INV_W);
    SQ_PUT(Float, y);
    SQ_PUT(Float, x + text_size + 4.0F);
    SQ_PUT(Uint32, KM_VERTEXPARAM_NORMAL);
    prefetch(text_sq);
    text_sq += ENTRY_SIZE + VERTEX_WRITTEN;
    SQ_PUT(Uint32, text_color);
    SQ_PUT(Float, bottom);
    SQ_PUT(Float, right);
    SQ_PUT(Float, TEXT_INV_W);
    SQ_PUT(Float, y + text_size);
    SQ_PUT(Float, x + text_size - 1.0F);
    SQ_PUT(Uint32, KM_VERTEXPARAM_ENDOFSTRIP);
    prefetch(text_sq);
    text_sq += ENTRY_SIZE;
}

/* text_draw_char at FRONT_INV_W, in front of text_draw_char's */
void text_draw_char_front(Sint16 x, Sint16 y, char ch)
{
    Sint16 col;
    Sint16 row;
    Float left;
    Float top;
    Float right;
    Float bottom;

    if (ch == '0') {
        ch = 'O';
    }
    col = ch % FONT_COLUMNS;
    row = ch / FONT_COLUMNS;
    left = (col * FONT_CELL) + FONT_INSET;
    top = (row * FONT_CELL) + FONT_INSET;
    right = left + FONT_SPAN;
    bottom = top + FONT_SPAN;
    text_sq += VERTEX_WRITTEN;
    SQ_PUT(Uint32, text_color);
    SQ_PUT(Float, top);
    SQ_PUT(Float, left);
    SQ_PUT(Float, FRONT_INV_W);
    SQ_PUT(Float, y);
    SQ_PUT(Float, x + 1.0F);
    SQ_PUT(Uint32, KM_VERTEXPARAM_NORMAL);
    prefetch(text_sq);
    text_sq += ENTRY_SIZE + VERTEX_WRITTEN;
    SQ_PUT(Uint32, text_color);
    SQ_PUT(Float, bottom);
    SQ_PUT(Float, left);
    SQ_PUT(Float, FRONT_INV_W);
    SQ_PUT(Float, y + text_size);
    SQ_PUT(Float, x - 4.0F);
    SQ_PUT(Uint32, KM_VERTEXPARAM_NORMAL);
    prefetch(text_sq);
    text_sq += ENTRY_SIZE + VERTEX_WRITTEN;
    SQ_PUT(Uint32, text_color);
    SQ_PUT(Float, top);
    SQ_PUT(Float, right);
    SQ_PUT(Float, FRONT_INV_W);
    SQ_PUT(Float, y);
    SQ_PUT(Float, x + text_size + 4.0F);
    SQ_PUT(Uint32, KM_VERTEXPARAM_NORMAL);
    prefetch(text_sq);
    text_sq += ENTRY_SIZE + VERTEX_WRITTEN;
    SQ_PUT(Uint32, text_color);
    SQ_PUT(Float, bottom);
    SQ_PUT(Float, right);
    SQ_PUT(Float, FRONT_INV_W);
    SQ_PUT(Float, y + text_size);
    SQ_PUT(Float, x + text_size - 1.0F);
    SQ_PUT(Uint32, KM_VERTEXPARAM_ENDOFSTRIP);
    prefetch(text_sq);
    text_sq += ENTRY_SIZE;
}

/* point the store queues at the translucent list and send the font's
 * polygon header. _nj_current_texture becomes NO_TEXTURE. the statements
 * stand bare: wrapped in a do-while (0), text_print_number and
 * text_print_hex compile to other code */
/* @hack spelling: _nj_vertex_buffer_ through its address, here and in
 * TEXT_CLOSE, which loads the address after the store to _nj_current_texture
 * (0x8c04348a in text_print_number); as _nj_vertex_buffer_ itself, 511 of
 * 1,013 words differ */

/* set the translucent list's write pointer to the end of what the text
 * sent: text_sq's offset, with the pointer's own bits above it */

void FUN_8c042298(Int loc, const char *string)
{
    Sint16 x;
    Sint16 y;
    Sint16 length;
    Sint16 i;

    if (loop_count != 0) {
        return;
    }
    TEXT_OPEN();
    x = (Sint16)(loc >> 16) * text_size;
    y = (Sint16)loc * text_size;
    length = strlen(string);
    for (i = 0; i < length; i++) {
        text_draw_char(x, y, string[i]);
        x += text_size;
    }
    TEXT_CLOSE();
}

void FUN_8c042416(Int loc, const char *string)
{
    Sint16 x;
    Sint16 y;
    Sint16 length;
    Sint16 i;

    if (loop_count != 0) {
        return;
    }
    TEXT_OPEN();
    x = (Sint16)(loc >> 16) * text_size;
    y = (Sint16)loc * text_size;
    length = strlen(string);
    for (i = 0; i < length; i++) {
        text_draw_char_front(x, y, string[i]);
        x += text_size;
    }
    TEXT_CLOSE();
}

void FUN_8c0425a0(Int loc, Int value, Int digits)
{
    int digit;
    Sint16 x;
    Sint16 y;

    if (loop_count != 0) {
        return;
    }
    TEXT_OPEN();
    x = (Sint16)(loc >> 16) * text_size;
    y = (Sint16)loc * text_size;
    if (value < 0) {
        text_draw_char(x, y, '-');
        value = -value;
        x += text_size;
    }
    for (; digits > 0; digits--) {
        switch (digits) {
        case 1:
            digit = value % 10;
            break;
        case 2:
            digit = value / 10;
            value -= digit * 10;
            break;
        case 3:
            digit = value / 100;
            value -= digit * 100;
            break;
        case 4:
            digit = value / 1000;
            value -= digit * 1000;
            break;
        case 5:
            digit = value / 10000;
            value -= digit * 10000;
            break;
        case 6:
            digit = value / 100000;
            value -= digit * 100000;
            break;
        case 7:
            digit = value / 1000000;
            value -= digit * 1000000;
            break;
        case 8:
            digit = value / 10000000;
            value -= digit * 10000000;
            break;
        case 9:
            digit = value / 100000000;
            value -= digit * 100000000;
            break;
        default:
            digit = value / 1000000000;
            value -= digit * 1000000000;
            break;
        }
        if (digit > 9) {
            digit = 0;
        }
        text_draw_char(x, y, '0' + digit);
        x += text_size;
    }
    TEXT_CLOSE();
}

void FUN_8c042880(Int loc, Uint32 value, Int digits)
{
    Sint16 x;
    Sint16 y;
    int bit;

    if (loop_count != 0) {
        return;
    }
    TEXT_OPEN();
    x = (Sint16)(loc >> 16) * text_size;
    y = (Sint16)loc * text_size;
    for (bit = digits - 1; bit >= 0; bit--) {
        text_draw_char(x, y, '0' + ((value >> bit) & 1));
        x += text_size;
    }
    TEXT_CLOSE();
}
#ifdef NON_MATCHING

void FUN_8c04298e(Int loc, Uint32 value, Int digits)
{
    Sint16 x;
    Sint16 y[1];
    int digit;
    int i;

    if (loop_count != 0) {
        return;
    }
    TEXT_OPEN();
    x = (Sint16)(loc >> 16) * text_size;
    y[0] = (Sint16)loc * text_size;
    for (i = digits - 1; i >= 0; i--) {
        digit = (value >> (i * 4)) & 0xf;
        text_draw_char(x, y[0], text_hex_digits[digit]);
        x += text_size;
    }
    TEXT_CLOSE();
}
#else
void FUN_8c04298e(Int loc, Uint32 value, Int digits)
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
}
#endif

void FUN_8c042b22(Int loc, Float value, Int digits)
{
    char buffer[20];
    Sint16 x;
    Sint16 y;
    int length;
    int point;
    int pad;
    int padded;
    int i;

    if (loop_count != 0) {
        return;
    }
    TEXT_OPEN();
    x = (Sint16)(loc >> 16) * text_size;
    y = (Sint16)loc * text_size;
    if (value < 0.0F) {
        text_draw_char(x, y, '-');
        value *= -1.0F;
        x += text_size;
    }
    sprintf(buffer, "%0.*f", 5, value);
    length = strlen(buffer);
    for (point = 0; point < length; point++) {
        if (buffer[point] == '.') {
            break;
        }
    }
    pad = digits - point;
    padded = length + pad;
    /* @bug memory: a value with more than digits places before its
     * point makes pad negative, and the shift writes -pad bytes before buffer
     * (MOV.B R3,@-R7 at 0x8c043b34). each byte the shift copies then comes
     * from -pad bytes above it, so buffer fills with repeats of its last -pad
     * bytes, the NUL among them, and the print draws those */
    for (i = padded; i >= pad; i--) {
        buffer[i] = buffer[length--];
    }
    for (i = 0; i < pad; i++) {
        buffer[i] = '0';
    }
    for (i = 0; i < padded; i++) {
        text_draw_char(x, y, buffer[i]);
        x += text_size;
    }
    TEXT_CLOSE();
}

void FUN_8c042d3a(Int loc, const char *format, ...)
{
    char buffer[128];
    va_list args;

    if (loop_count != 0) {
        return;
    }
    va_start(args, format);
    vsprintf(buffer, format, args);
    ;
    FUN_8c042298(loc, buffer);
}
