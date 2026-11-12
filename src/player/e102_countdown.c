/* @unit 8C0D6000-8C0D6220 +egflags +r04 +pool32 +asmfunc=countdown_draw */
/* E-102's last seconds: his time in a big digit, pulsing */
#include <ninja.h>
#include <sg_xpt.h>

#include "hud/hud.h"
#include "main.h"
#include "player/e102_bonus.h"
#include "player/e102_countdown.h"
#include "sound/sound.h"
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
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
void FUN_8c0d60d8(struct task *task);
void kmiLogFileOpen(void *data);
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

#define SE_LAST_SECONDS 1195

/* the time, in seconds, at which the countdown opens, and the scale of its
 * digit and its sign */
#define LAST_SECONDS 5
#define DIGIT_SCALE 2.2F

#define COUNTDOWN(work) ((struct countdown_vars *)&(work)->vars)
enum countdown_mode {
    COUNTDOWN_INIT,
    COUNTDOWN_WAIT,
    COUNTDOWN_OPEN,
    COUNTDOWN_SHOW,
    COUNTDOWN_CLOSE
};

struct countdown_vars {
    Float open; /* how wide, from 0 to 1 */
};
#ifdef NON_MATCHING

/* the time left, as one digit under the sign, pulsing twice a second. the time
 * in seconds is the digit's texanim index in e102time_sprite. so as the
 * countdown closes, a time above 9 draws a texanim past the digits */
static void countdown_draw(struct task *task)
{
    struct task_work *work = task->work;
    Uint8 minutes;
    Uint8 seconds;
    Uint8 frames;
    int time;
    Float size;
    Angle ang;

    if (loop_count != 0) {
        return;
    }
    time_get(&minutes, &seconds, &frames);
    time = (minutes * 60) + seconds;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    e102time_sprite.p.x = SCREEN_MIDDLE_X;
    e102time_sprite.p.y = 415.2F;
    ang = frames * 0x8000 / 30;
    size = (0.9F + (0.4F * _builtin_fabsf(njSin(ang)))) * DIGIT_SCALE;
    e102time_sprite.sx = size * COUNTDOWN(work)->open;
    e102time_sprite.sy = size;
    late_DrawSprite2D(&e102time_sprite, time, -2.0F, NJD_SPRITE_ALPHA);
    e102time_sprite.p.x = SCREEN_MIDDLE_X;
    e102time_sprite.p.y = 380.0F;
    e102time_sprite.sx = COUNTDOWN(work)->open * DIGIT_SCALE;
    e102time_sprite.sy = DIGIT_SCALE;
    late_DrawSprite2D(&e102time_sprite, E102TIME_LASTSEC, -3.0F,
                      NJD_SPRITE_ALPHA);
}
#else
static void countdown_draw(struct task *task)
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
}
#endif

/* at LAST_SECONDS or less, the countdown sounds a warning and opens over 8
 * steps. once the time is above LAST_SECONDS again, it closes */
void FUN_8c0d60d8(struct task *task)
{
    struct task_work *work = task->work;
    Uint8 minutes;
    Uint8 seconds;
    Uint8 frames;
    int time;

    time_get(&minutes, &seconds, &frames);
    time = (minutes * 60) + seconds;
    switch (work->mode) {
    case COUNTDOWN_INIT:
        COUNTDOWN(work)->open = 0.0F;
        work->mode = COUNTDOWN_WAIT;
        /* fall through */
    case COUNTDOWN_WAIT:
        if (time <= LAST_SECONDS) {
            work->mode = COUNTDOWN_OPEN;
            dsPlay_oneshot(SE_LAST_SECONDS, 0, 0, 0);
        }
        return;
        /* @hack redundant: a break after the return, whose deleted jump has
         * the next two cases store their modes from R2 and R1 (0x8c0df632,
         * 0x8c0df63e). without it, R3 and R2 take them and 4 of 92 words
         * differ */
        break;
    case COUNTDOWN_OPEN:
        COUNTDOWN(work)->open += 0.125F;
        if (COUNTDOWN(work)->open >= 1.0F) {
            COUNTDOWN(work)->open = 1.0F;
            work->mode = COUNTDOWN_SHOW;
        }
        break;
    case COUNTDOWN_SHOW:
        if (time > LAST_SECONDS) {
            work->mode = COUNTDOWN_CLOSE;
        }
        break;
    case COUNTDOWN_CLOSE:
        COUNTDOWN(work)->open -= 0.125F;
        if (COUNTDOWN(work)->open <= 0.0F) {
            COUNTDOWN(work)->open = 0.0F;
            work->mode = COUNTDOWN_WAIT;
            return;
        }
        break;
    }
    countdown_draw(task);
}
