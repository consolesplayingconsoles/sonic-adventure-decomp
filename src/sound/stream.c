/* @unit 8C1077A0-8C107D80 @data 8C15D4A0-8C15DB20 +jpflags +pool32 +poolafter=stream_step,CameraFishingCatch,stream_unmute,stream_reset_voice +synth16 +hoist=1,1,0,-1,1,1 */
/* streams: the music and the voices, played from the disc */
#include <sg_xpt.h>
#include <sofdec.h>

#include "sound/stream.h"
#include "system/task.h"
void ADXT_SetReloadSct(ADXT adxt, Sint32 freq);
Sint32 FUN_8c10c108(Sint32 ptid, char *fname, void *ptinfo, Sint32 nmax);
void FUN_8c1077a4(struct task *task);
void Serif_Play(int voice);
void FUN_8c107b32(void);
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
void FreeTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

/* the voices' archive, the partition adx loads it as, and the most files
 * ADXF_LoadPartition reads from it */
#define VOICE_ARCHIVE "event_adx.afs"
#define VOICE_PARTITION 0
#define VOICE_FILES 2148

#define MUSIC_CHANNELS 2
#define VOICE_CHANNELS 1

/* each stream's work, music first, at a fixed place in main memory.
 * ADXT_Create lays a work out as an output buffer for each channel, then
 * whole 2048-byte sectors of input. the music's holds 74 of them, and the
 * voices' 19 */
#define STREAM_WORK 0x0cca8000
#define MUSIC_WORK_SIZE 0x2d0c4
#define VOICE_WORK_SIZE 0xd884

/* each stream's volume, in tenths of a decibel, and the one that silences
 * it */
#define MUSIC_VOLUME (-10)
#define VOICE_VOLUME 0
#define MUTED (-960)

/* each stream's server is told to expect this many calls a second */
#define SERVER_FREQ 20

#define VARS(work) ((struct interlude_vars *)&(work)->vars)
enum interlude_mode {
    INTERLUDE_INIT,
    INTERLUDE_WAIT /* for the interlude to end */
};

struct interlude_vars {
    Sint32 music; /* the music to go back to */
    Uint8 unk_04[4];
    Sint32 interlude; /* the interlude's music */
};

static void stream_step(struct task *task);
static void stream_close(struct task *task);
static void interlude_step(struct task *task);
extern char *music_files[MUSIC_COUNT];
extern Bool music_enabled;
extern Bool voice_enabled;
extern void *music_work;
extern void *voice_work;
extern ADXT music_stream;
extern ADXT voice_stream;
extern char *stream_state_names[];
static const char stream_str_ev0[16] = "event_adx.afs";
static const char stream_str_ev1[20] = "event_adx_us.afs";
static const char stream_str_0[12] = "ADVAMY.ADX";
static const char stream_str_1[12] = "ADVBIG.ADX";
static const char stream_str_2[12] = "ADVE102.ADX";
static const char stream_str_3[16] = "ADVKNKLS.ADX";
static const char stream_str_4[16] = "ADVMILES.ADX";
static const char stream_str_5[16] = "ADVSONIC.ADX";
static const char stream_str_6[8] = "AMY.ADX";
static const char stream_str_7[8] = "BIG.ADX";
static const char stream_str_8[12] = "BOSSALL.ADX";
static const char stream_str_9[16] = "BOSSE101.ADX";
static const char stream_str_10[16] = "BOSSEVNT.ADX";
static const char stream_str_11[16] = "BOSSTRGT.ADX";
static const char stream_str_12[12] = "CASINO1.ADX";
static const char stream_str_13[12] = "CASINO2.ADX";
static const char stream_str_14[12] = "CASINO3.ADX";
static const char stream_str_15[12] = "CASINO4.ADX";
static const char stream_str_16[12] = "CHAO.ADX";
static const char stream_str_17[16] = "CHAOGOAL.ADX";
static const char stream_str_18[16] = "CHAOHALL.ADX";
static const char stream_str_19[16] = "CHAORACE.ADX";
static const char stream_str_20[12] = "CHAOS.ADX";
static const char stream_str_21[12] = "CHAOS_6.ADX";
static const char stream_str_22[16] = "CHAOS_P1.ADX";
static const char stream_str_23[16] = "CHAOS_P2.ADX";
static const char stream_str_24[16] = "CHARACTR.ADX";
static const char stream_str_25[12] = "CIRCUIT.ADX";
static const char stream_str_26[16] = "CONTINUE.ADX";
static const char stream_str_27[12] = "E102.ADX";
static const char stream_str_28[12] = "ECOAST1.ADX";
static const char stream_str_29[12] = "ECOAST2.ADX";
static const char stream_str_30[12] = "ECOAST3.ADX";
static const char stream_str_31[16] = "EGCARER1.ADX";
static const char stream_str_32[16] = "EGCARER2.ADX";
static const char stream_str_33[12] = "EGGMAN.ADX";
static const char stream_str_34[16] = "EGGMBL23.ADX";
static const char stream_str_35[12] = "EGGROBO.ADX";
static const char stream_str_36[16] = "EVTBGM00.ADX";
static const char stream_str_37[16] = "EVTBGM01.ADX";
static const char stream_str_38[16] = "EVTBGM02.ADX";
static const char stream_str_39[16] = "EVTBGM03.ADX";
static const char stream_str_40[16] = "EVTBGM04.ADX";
static const char stream_str_41[16] = "EVTBGM05.ADX";
static const char stream_str_42[16] = "FINALEG1.ADX";
static const char stream_str_43[16] = "FINALEG2.ADX";
static const char stream_str_44[12] = "FISHGET.ADX";
static const char stream_str_45[12] = "FISHING.ADX";
static const char stream_str_46[16] = "FISHMISS.ADX";
static const char stream_str_47[12] = "HAMMER.ADX";
static const char stream_str_48[16] = "HIGHWAY1.ADX";
static const char stream_str_49[16] = "HIGHWAY2.ADX";
static const char stream_str_50[16] = "HIGHWAY3.ADX";
static const char stream_str_51[12] = "HURRYUP.ADX";
static const char stream_str_52[12] = "ICECAP1.ADX";
static const char stream_str_53[12] = "ICECAP2.ADX";
static const char stream_str_54[12] = "ICECAP3.ADX";
static const char stream_str_55[16] = "INVNCIBL.ADX";
static const char stream_str_56[12] = "ITEM1.ADX";
static const char stream_str_57[16] = "JINGLE_1.ADX";
static const char stream_str_58[16] = "JINGLE_2.ADX";
static const char stream_str_59[16] = "JINGLE_3.ADX";
static const char stream_str_60[16] = "JINGLE_4.ADX";
static const char stream_str_61[16] = "JINGLE_5.ADX";
static const char stream_str_62[16] = "KNUCKLES.ADX";
static const char stream_str_63[16] = "LSTWRLD1.ADX";
static const char stream_str_64[16] = "LSTWRLD2.ADX";
static const char stream_str_65[16] = "LSTWRLD3.ADX";
static const char stream_str_66[16] = "MAINTHEM.ADX";
static const char stream_str_67[12] = "MSTCLN.ADX";
static const char stream_str_68[16] = "NIGHTS_A.ADX";
static const char stream_str_69[16] = "NIGHTS_K.ADX";
static const char stream_str_70[16] = "NIGHTS_S.ADX";
static const char stream_str_71[12] = "ONE_UP.ADX";
static const char stream_str_72[12] = "OPTION.ADX";
static const char stream_str_73[16] = "REDMNTN1.ADX";
static const char stream_str_74[16] = "REDMNTN2.ADX";
static const char stream_str_75[16] = "RNDCLEAR.ADX";
static const char stream_str_76[16] = "S_SQUARE.ADX";
static const char stream_str_77[16] = "SANDHILL.ADX";
static const char stream_str_78[16] = "SCRAMBLE.ADX";
static const char stream_str_79[16] = "SHELTER1.ADX";
static const char stream_str_80[16] = "SHELTER2.ADX";
static const char stream_str_81[16] = "SKYDECK1.ADX";
static const char stream_str_82[16] = "SKYDECK2.ADX";
static const char stream_str_83[12] = "SONIC.ADX";
static const char stream_str_84[16] = "SONIC_CD.ADX";
static const char stream_str_85[12] = "SPEEDUP.ADX";
static const char stream_str_86[16] = "SPRSONIC.ADX";
static const char stream_str_87[16] = "SSRACING.ADX";
static const char stream_str_88[12] = "TAILS.ADX";
static const char stream_str_89[12] = "THEAMY.ADX";
static const char stream_str_90[12] = "THEBIG.ADX";
static const char stream_str_91[12] = "THEE102.ADX";
static const char stream_str_92[16] = "THEKNKLS.ADX";
static const char stream_str_93[16] = "THEMILES.ADX";
static const char stream_str_94[16] = "THESONIC.ADX";
static const char stream_str_95[12] = "TICAL.ADX";
static const char stream_str_96[12] = "TIMER.ADX";
static const char stream_str_97[16] = "TITL_EGG.ADX";
static const char stream_str_98[16] = "TITL_MR1.ADX";
static const char stream_str_99[16] = "TITL_MR2.ADX";
static const char stream_str_100[12] = "TITL_SS.ADX";
static const char stream_str_101[12] = "TITLE.ADX";
static const char stream_str_102[12] = "TITLE2.ADX";
static const char stream_str_103[12] = "TRIAL.ADX";
static const char stream_str_104[16] = "TWNKLPK1.ADX";
static const char stream_str_105[16] = "TWNKLPK2.ADX";
static const char stream_str_106[16] = "TWNKLPK3.ADX";
static const char stream_str_107[16] = "WNDYVLY1.ADX";
static const char stream_str_108[16] = "WNDYVLY2.ADX";
static const char stream_str_109[16] = "WNDYVLY3.ADX";
static const char stream_str_110[8] = "STOP   ";
static const char stream_str_111[8] = "DECINFO";
static const char stream_str_112[8] = "PREP   ";
static const char stream_str_113[8] = "PLAYING";
static const char stream_str_114[8] = "DECEND ";
static const char stream_str_115[8] = "PLAYEND";
extern int dat_8c612510[4];
extern int voice_request;
extern Sint32 voice_state;
extern int music_request;
extern Sint32 music_state;
extern int music_current;
extern int dat_8c612534;
extern int music_saved;
extern struct task *stream_task;
extern Uint8 voice_ptinfo[0x1138];
extern Sint32 stream_work_size;

static void stream_ignore_error(void *obj, char *msg)
{
}
extern Sint32 VoiceLanguage;

void FUN_8c1077a4(struct task *task)
{
    if (stream_task == NULL) {
        stream_task = task;
        stream_work_size = 0x2d0c4 + 0xd884;
        ADXT_EntryErrFunc(stream_ignore_error, ((void *)0));
        if (VoiceLanguage == 0) {
            FUN_8c10c108(0, stream_str_ev0, voice_ptinfo, 2148);
        } else {
            FUN_8c10c108(0, stream_str_ev1, voice_ptinfo, 2148);
        }
        music_stream = ADXT_Create(2, music_work, 0x2d0c4);
        voice_stream = ADXT_Create(1, voice_work, 0xd884);
        if (music_stream != ((void *)0)) {
            ADXT_SetAutoRcvr(music_stream, 2);
            ADXT_SetOutVol(music_stream, (-10));
            ADXT_SetReloadSct(music_stream, 20);
        }
        if (voice_stream != ((void *)0)) {
            ADXT_SetAutoRcvr(voice_stream, 1);
            ADXT_SetOutVol(voice_stream, 0);
            ADXT_SetReloadSct(voice_stream, 20);
        }
        task->destructor = stream_close;
        task->step = stream_step;
    } else {
        DestroyTask(task);
    }
}

static void stream_step(struct task *task)
{
    /* @hack redundant: 256 bytes of frame that no code reads, of a type
     * unknown, declared as a char[256]. the image's 260-byte frame holds them
     * (ADD R0,R15 at 0x8c11671e, ADD R1,R15 at 0x8c116788); without them, 59 of
     * 61 words differ */
    char unused[256];

#ifdef GCC
    /* a skip starts no stream behind its curtain, so no voice takes time */
    if (event_skipping) {
        music_request = voice_request = -1;
    }
#endif
    if (music_stream != NULL) {
        if (music_request >= 0) {
            ADXT_StartFname(music_stream, music_files[music_request]);
        }
        music_request = -1;
        music_state = ADXT_GetStat(music_stream);
    }
    if (voice_stream != NULL) {
        if (voice_request >= 0) {
            ADXT_StartAfs(voice_stream, VOICE_PARTITION, voice_request);
        }
        voice_request = -1;
        voice_state = ADXT_GetStat(voice_stream);
    }
    if (gAdxPcmDecodeErrorFlag) {
        gAdxPcmDecodeErrorFlag = 0;
    }
    LoopTaskC(task);
}

static void stream_close(struct task *task)
{
    if (music_stream != NULL) {
        ADXT_Destroy(music_stream);
        music_stream = NULL;
    }
    if (voice_stream != NULL) {
        ADXT_Destroy(voice_stream);
        voice_stream = NULL;
    }
    stream_reset_music();
    stream_reset_voice();
    stream_task = NULL;
}

void ADX_Close(void)
{
    if (stream_task != NULL) {
        DestroyTask(stream_task);
        stream_task = NULL;
    }
}

void BGM_Play(int music)
{
    if (music_enabled) {
        music_request = music;
        music_current = music;
    }
}

void stream_stop_music(void)
{
    if (music_stream != NULL) {
        ADXT_Stop(music_stream);
        music_current = -1;
    }
}

Sint32 stream_music_state(void)
{
    return music_state;
}

int stream_music_time(void)
{
    if (music_stream != NULL) {
        Sint32 count;
        Sint32 scale;

        ADXT_GetTime(music_stream, &count, &scale);
        return count;
    }
    return 0;
}

Bool CameraFishingCatch(void)
{
    if (music_current != -1) {
        BGM_Play(music_current);
        return TRUE;
    }
    return FALSE;
}

void Serif_Play(int voice)
{
    if (voice_enabled) {
        voice_request = voice;
    }
}

void stream_stop_voice(void)
{
    if (voice_stream != NULL) {
        ADXT_Stop(voice_stream);
    }
}

Sint32 stream_voice_state(void)
{
    return voice_state;
}

int stream_voice_time(void)
{
    if (voice_stream != NULL) {
        Sint32 count;
        Sint32 scale;

        ADXT_GetTime(voice_stream, &count, &scale);
        return count;
    }
    return 0;
}

void FUN_8c107b32(void)
{
    if (music_stream != NULL) {
        ADXT_SetOutVol(music_stream, MUTED);
    }
    if (voice_stream != NULL) {
        ADXT_SetOutVol(voice_stream, MUTED);
    }
}

void stream_unmute(void)
{
    if (music_stream != NULL) {
        ADXT_SetOutVol(music_stream, MUSIC_VOLUME);
    }
    if (voice_stream != NULL) {
        ADXT_SetOutVol(voice_stream, VOICE_VOLUME);
    }
}

void stream_request_interlude(int music)
{
    struct task *task;

    if (music_enabled) {
        music_request = music;
        if (stream_task != NULL) {
            task = CreateChildTask(TASK_WORK, interlude_step, stream_task);
            VARS(task->work)->interlude = music;
            VARS(task->work)->music = music_current;
        }
    }
}

static void interlude_destroy(struct task *task)
{
}

static void interlude_step(struct task *task)
{
    struct task_work *work;

    work = task->work;
    switch (work->mode) {
    case INTERLUDE_INIT:
        task->destructor = interlude_destroy;
        work->mode = INTERLUDE_WAIT;
        break;
    case INTERLUDE_WAIT:
        if (music_current != VARS(work)->music) {
            FreeTask(task);
        } else {
            switch (stream_music_state()) {
            case ADXT_STAT_STOP:
            case ADXT_STAT_PLAYEND:
                BGM_Play(music_current);
                FreeTask(task);
                break;
            }
        }
        break;
    }
}

void stream_reset_music(void)
{
    music_request = -1;
    music_state = ADXT_STAT_STOP;
    music_current = -1;
}

void stream_reset_voice(void)
{
    voice_request = -1;
    voice_state = ADXT_STAT_STOP;
}

void ADXTaskInit(void)
{
    /* @hack redundant: task, set to task_create's result and never read,
     * which keeps the call a JSR that returns here (0x8c116b40). with the
     * result dropped, SHC makes the call a jump, and 16 of 21 words differ */
    /* NOLINTNEXTLINE(clang-diagnostic-unused-but-set-variable) */
    struct task *task;

    stream_reset_music();
    stream_reset_voice();
    task = CreateElementalTask(0, 1, FUN_8c1077a4);
}

void stream_request_and_save_music(int music)
{
    if (music_enabled) {
        music_request = music;
        music_saved = music;
        music_current = music;
    }
}

Bool stream_restore_music(void)
{
    if (music_saved != -1) {
        stream_request_and_save_music(music_saved);
        return TRUE;
    }
    return FALSE;
}
