/* @unit 8C900DA0-8C900F00 +r04 +egflags +pool32 */
/* the console's sound mode, stereo or mono, which the options screen reads and
 * sets */
#include <sg_xpt.h>
#include <shinobi.h>

#include "advertise/sound_config.h"
#include "sound/sound.h"
#include "system/task.h"
void pdExecPeripheralServerUser(void);
void FUN_8c092f28(void);
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
extern struct {
    Bool open;
    void *work;
} sound_config;
extern int sound_config_tries;

#define CONFIG_WORK_SIZE 0x4000 /* the bytes of syCfg's work area */

void sound_config_open(void)
{
    sound_config.open = FALSE;
    /* @hack spelling: the work area assigned in the test. SHC then tests it in
     * R0 (TST R0,R0 at 0x8c900d5a). assigned first, it is copied to R2 and
     * tested there, the function runs 2 bytes longer, and 31 of 44 words
     * differ */
    if ((sound_config.work = CAlloc(1, CONFIG_WORK_SIZE)) != NULL) {
        sound_config_tries = 0;
        sound_config.open = TRUE;
        while (syCfgInit(sound_config.work) != SYD_CFG_OK) {
            if (sound_config_tries++ > CFG_TRIES) {
                sound_config.open = FALSE;
                break;
            }
        }
    }
}

void sound_config_close(void)
{
    if (sound_config.open) {
        syCfgExit();
    }
    if (sound_config.work != NULL) {
        Free(sound_config.work);
        sound_config.work = NULL;
    }
    FUN_8c092f28();
}

int sound_config_set(Sint32 mode)
{
    sound_config_tries = 0;
    while (syCfgSetSoundMode(mode) != SYD_CFG_OK) {
        if (sound_config_tries++ > CFG_TRIES) {
            break;
        }
    }
    return 0;
}

Sint32 sound_config_get(void)
{
    Sint32 mode;

    sound_config_tries = 0;
    while (syCfgGetSoundMode(&mode) != SYD_CFG_OK) {
        if (sound_config_tries++ > CFG_TRIES) {
            mode = SYD_CFG_STEREO;
            break;
        }
    }
    return mode;
}
