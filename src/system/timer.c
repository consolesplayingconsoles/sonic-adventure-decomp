/* @unit 8C06C000-8C06C240 +spflags +pool32 +poolafter=timer_end_of_render +synth16 */
/* the frame timer, on the SH-4's timer 1 */
#include <kamui.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/host.h"
#include "draw/model.h"
#include "system/timer.h"
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c6409c0(Int loc, Int val, Int digit);
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern Bool pause_flg;
void FUN_8c06c000(void);
extern int dat_8c1d4878;
extern int debug_page;
extern Bool pause_flg;
extern int dat_8c1d4884;
extern int dat_8c795150;
extern int timer_counts[8];
extern Uint32 timer_marked;
extern Uint32 timer_rendered;

/* the timer unit's registers, by their SH-4 names: the start register, and
 * timer 1's constant, count and control registers */
/* @hack type: the registers not volatile, which lets SHC schedule other
 * instructions among their reads and writes: timer_start puts pool loads
 * and the saves of R14 and PR between TSTR's address and its read
 * (0x8c06fae0 to 0x8c06faf0). as volatile, 40 of the 126 words of the six
 * functions that use them differ */
#ifdef GCC
#define TSTR (*(volatile Uint8 *)0xffd80004)
#define TCOR1 (*(volatile Uint32 *)0xffd80014)
#define TCNT1 (*(volatile Uint32 *)0xffd80018)
#define TCR1 (*(volatile Uint16 *)0xffd8001c)
#else
#define TSTR (*(Uint8 *)0xffd80004)
#define TCOR1 (*(Uint32 *)0xffd80014)
#define TCNT1 (*(Uint32 *)0xffd80018)
#define TCR1 (*(Uint16 *)0xffd8001c)
#endif
/* TSTR's bit that runs timer 1 */
#define STR1 0x02
/* TCR's setting for a count at a quarter of the 50 MHz peripheral clock,
 * with no underflow interrupt */
#define TCR_PCLK_4 0

/* a second's ticks at 12.5 MHz, TCR_PCLK_4's rate. timer_start has timer 1
 * count down from this and reload it after 0, so the timer starts over each
 * second */
#define TICKS_PER_SECOND 12500000
/* a tick, 0.08 microseconds, in thousandths of a vsync. a microsecond is
 * 0.001 milliseconds, and a millisecond 60 thousandths of a vsync */
#define TICK (0.08F * 0.001F * 60.0F)

#define TIMER_COUNTS 8

static void timer_end_of_render(void *arg);

void FUN_8c06c000(void)
{
    int i;
    Uint8 tstr = TSTR;

    TSTR = tstr & ~STR1;
    timer_marked = TICKS_PER_SECOND;
    TCR1 = TCR_PCLK_4;
    TCOR1 = timer_marked;
    TCNT1 = timer_marked;
    tstr |= STR1;
    TSTR = tstr;
    /* @hack type: a plain 0 as the callback's argument, which puts TSTR's
     * address in R5 and timer_marked's in R6 (0x8c06fae0, 0x8c06fae4); as
     * NULL, the two trade and 8 of 50 words differ */
    kmSetEORCallback(timer_end_of_render, 0);
    for (i = 0; i < TIMER_COUNTS; i++) {
        timer_counts[i] = -1;
    }
    for (i = 0; i < DRAW_DEBUG_COUNTS; i++) {
        draw_debug_counts[i] = 0;
    }
}

Float timer_elapsed_and_mark(void)
{
    /* @hack spelling: TCNT1's count through a local, which SHC reads into
     * R4 (0x8c06fb48); without it, the count takes R3, and 21 of 22 words
     * differ */
    Uint32 count = TCNT1;
    /* @hack spelling: the time through a local, which SHC computes in FR4
     * and copies to FR0 in the RTS's slot (0x8c06fb68 to 0x8c06fb6e);
     * without it, the time takes FR0, and 6 of 22 words differ */
    Float time;

    timer_marked = count;
    time = ((Float)TICKS_PER_SECOND - timer_marked) * TICK;
    return time;
}

Float timer_lap(void)
{
    Uint32 count = TCNT1;
    Uint32 ticks = timer_marked - count;
    /* @hack spelling: the time through a local, which SHC computes in FR4
     * and copies to FR0 in the RTS's slot (0x8c06fbde to 0x8c06fbe6);
     * without it, the time takes FR0, and 4 of 20 words differ */
    Float time;

    timer_marked = count;
    time = ticks * TICK;
    return time;
}

void timer_mark(void)
{
    /* @hack spelling: TCNT1's count through a local, which SHC reads into
     * R4 (0x8c06fbec); without it, the count takes R3, and 4 of 5 words
     * differ */
    Uint32 count = TCNT1;

    timer_marked = count;
}

Float timer_render_time(void)
{
    /* @hack spelling: the time through a local, which SHC computes in FR4
     * and copies to FR0 in the RTS's slot (0x8c06fc10 to 0x8c06fc16);
     * without it, the time takes FR0, and 6 of 19 words differ */
    Float time = ((Float)TICKS_PER_SECOND - timer_rendered) * TICK;

    return time;
}

Float timer_elapsed(void)
{
    /* @hack spelling: TCNT1's count through a local, which SHC reads into
     * R4 (0x8c06fc1a); without it, the count takes R3, and 7 of 19 words
     * differ */
    Uint32 count = TCNT1;
    /* @hack spelling: the time through a local, which SHC computes in FR4
     * and copies to FR0 in the RTS's slot (0x8c06fc36 to 0x8c06fc3c);
     * without it, the time takes FR0, and 6 of 19 words differ */
    Float time = ((Float)TICKS_PER_SECOND - count) * TICK;

    return time;
}

/* the callback Kamui calls as each render ends. it takes the place of
 * Ninja's callback, njSetEORflag, and calls it in turn */
static void timer_end_of_render(void *arg)
{
    /* @hack spelling: TCNT1's count through a local, which SHC reads into
     * R4 and stores in the JSR's slot (0x8c06fc46, 0x8c06fc4a); without it,
     * the count takes R3, the store moves ahead of the call, and 10 of 10
     * words differ */
    Uint32 count = TCNT1;

    timer_rendered = count;
    /* @bug mismatched-call: njSetEORflag takes Kamui's callback argument, and
     * gets none: as the JSR at 0x8c06fc48 calls it, R4 holds TCNT1's count,
     * read at 0x8c06fc46, which njSetEORflag ignores */
    njSetEORflag_jp();
    host_serve_request();
}

void timer_show_counts(void)
{
    int i;
    int row;

    if (debug_page) {
        row = 16;
        for (i = 0; i < TIMER_COUNTS; i++) {
            if (timer_counts[i] > 0) {
                FUN_8c6409c0(((35) << 16 | (row)), timer_counts[i] + 1, 4);
            }
            row++;
        }
    }
}
