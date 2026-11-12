/* @unit 8C109D60-8C10A060 +egflags +onepool +pool32 +asmfunc=VibShot,vibration_start_fading */
/* vibration: shaking a pad through the pack in one of its sockets */
#include <sg_pdvib.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "progress/demo.h"
#include "system/task.h"
#include "vmu/vibration.h"
Sint32 pdVibIsReady(Uint32 port);
void pdExecPeripheralServerUser(void);
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
void GM_WaitEventDemo(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
void Free(void *mem);
void VibShot(int pad, int power, int freq, int time);

/* for a pad with no pack ready */
#define NO_PORT 0xffffffff

/* the expansion sockets in a pad */
#define SOCKETS 2

/* the bounds vibration.h gives power, freq and time */
#define POWER_MAX 4
#define FREQ_MIN 7
#define FREQ_MAX 59
#define TIME_MAX 255

/* the fade's whole inc, which vibration_start_fading divides by its span */
#define FADE_INC 255

/* the task that starts a vibration keeps these in its extra */
#define EXTRA(task) ((struct vibration_extra *)(task)->extra)
struct vibration_extra {
    Uint32 port;
    Sint32 steps; /* taken so far */
};
extern const Uint32 vibration_ports[];

/* on the task's second step, start the vibration and destroy the task.
 * task_destroy frees the parameters in its force */
static void vibration_step(struct task *task)
{
    PDS_VIBPARAM *param;

    param = task->force;
    /* @hack spelling: the extra read through EXTRA at each use, which loads
     * task->extra again for the port (MOV.L @(44,R14),R4 at 0x8c118eba);
     * through a local, read once, 20 of 24 words differ */
    if (EXTRA(task)->steps++ == 1) {
        pdVibMxStart(EXTRA(task)->port, param);
        DestroyTask(task);
    }
}

/* start a vibration of the pack at port, through a task that waits a step.
 * nothing starts when an allocation fails */
void vibration_queue(Uint32 port, int flag, int power, int freq, int inc)
{
    struct task *task;
    PDS_VIBPARAM *param;

    /* @hack spelling: task assigned inside the test, which tests task_create's
     * R0 and copies it to R14 in the BT/S's slot (0x8c118ee8, 0x8c118eec);
     * assigned apart, SHC tests R14 and 3 of 46 words differ */
    if ((task = CreateElementalTask(TASK_EXTRA, 0, vibration_step)) != NULL) {
        /* @hack spelling: param assigned inside the test, as task is
         * (0x8c118ef4, 0x8c118ef8); assigned apart, 3 of 46 words differ */
        if ((param = MAlloc(sizeof(*param))) != NULL) {
            task->force = param;
            EXTRA(task)->port = port;
            param->unit = 1;
            param->flag = flag;
            param->power = power;
            param->freq = freq;
            param->inc = inc;
        } else {
            DestroyTask(task);
        }
    }
}
#ifdef NON_MATCHING

void VibShot(int pad, int power, int freq, int time)
{
    extern int pad_ports[];
    Uint32 port;
    int socket;
    int i;
    int flag;

#ifdef GCC
    /* behind a skip's curtain a request starts no rumble, but a request of
     * power 0 still stops the pack */
    if (event_skipping && power != 0) {
        return;
    }
#endif
    if (demo_playing) {
        return;
    }
    port = 0xffffffff;
    i = pad_ports[pad];
    if (i != -1) {
        for (socket = 0, i += i; socket < 2; socket++, i++) {
            if (pdVibIsReady(vibration_ports[i])) {
                port = vibration_ports[i];
                break;
            }
        }
    }
    if (port == NO_PORT) {
        return;
    }
    if (power > POWER_MAX) {
        power = POWER_MAX;
    } else if (power < -POWER_MAX) {
        power = -POWER_MAX;
    }
    if (power == 1) {
        power = 2;
    } else if (power == -1) {
        power = -2;
    }
    if (freq > FREQ_MAX) {
        freq = FREQ_MAX;
    } else if (freq < FREQ_MIN) {
        freq = FREQ_MIN;
    }
    if (time > TIME_MAX) {
        time = TIME_MAX;
    }
    if (time < 0) {
        time = 0;
    }
    if (time == 0) {
        flag = 0;
    } else {
        flag = PDD_VIB_FLAG_CONTINUOUS;
        pdVibMxSetStopTime(port, time);
    }
    vibration_queue(port, flag, power, freq, 0);
}
#else
void VibShot(int pad, int power, int freq, int time)
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
}
#endif
#ifdef NON_MATCHING

void vibration_start_fading(int pad, int power, int freq, int length)
{
    extern int pad_ports[];
    Uint32 port;
    int socket;
    int i;
    int span;
    int flag;
    /* @hack redundant: eight bytes nothing reads or writes, which make the
     * frame 12 bytes (ADD #-12,R15 at 0x8c119050); without them, it is 4 and
     * 2 of 98 words differ */
    Uint8 unused[8];

    if (demo_playing) {
        return;
    }
    port = 0xffffffff;
    i = pad_ports[pad];
    if (i != -1) {
        for (socket = 0, i += i; socket < 2; socket++, i++) {
            if (pdVibIsReady(vibration_ports[i])) {
                port = vibration_ports[i];
                break;
            }
        }
    }
    if (port == NO_PORT) {
        return;
    }
    if (power > POWER_MAX) {
        power = POWER_MAX;
    } else if (power < -POWER_MAX) {
        power = -POWER_MAX;
    }
    if (power == 1) {
        power = 2;
    } else if (power == -1) {
        power = -2;
    }
    if (freq > FREQ_MAX) {
        freq = FREQ_MAX;
    } else if (freq < FREQ_MIN) {
        freq = FREQ_MIN;
    }
    flag = PDD_VIB_FLAG_CONVERGENCE;
    span = freq * length / (power * 4);
    if (span <= 0) {
        span = 1;
    }
    vibration_queue(port, flag, power, freq, FADE_INC / span);
}
#else
void vibration_start_fading(int pad, int power, int freq, int length)
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
