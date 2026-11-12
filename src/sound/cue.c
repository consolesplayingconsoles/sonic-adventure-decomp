/* @unit 8C0A0B80-8C0A0EC0 @data 8C15B0B0-8C15B0D4 +jpflags +pool32 +synth16 */
/* sound cues: music now or after a wait, and effects that fade with distance */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "sound/cue.h"
#include "sound/sound.h"
#include "sound/stream.h"
#include "system/task.h"
#include "system/task_desc.h"
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
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
void kmiLogFileOpen(void *data);
int dsPlay_iloop(int se, int id, int priority, int volume);
void dsStop_num(int se);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
void BGM_Play(int music);
Bool CameraFishingCatch(void);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);

#define KEEP_UPDATES 2
#define LATER(task) ((struct music_later *)(task)->motion)
struct music_later {
    int music;
    int wait; /* the steps and draws to count before the music starts */
};

/* the updates sound_play_for and sound_play_at_for give a kept effect */

static void music_later_init(struct task *task, void *arg);
static void music_later_step(struct task *task);
static void music_later_destroy(struct task *task);

/* the task counts down as it steps, and again as it draws */
static const struct task_desc music_later_desc = {
    sizeof(struct music_later), 0,
    music_later_init,           music_later_step,
    music_later_step,           music_later_destroy};

static const struct sound_falloff sound_falloff_default = {0, -127, 20.0F,
                                                           600.0F};
extern struct task *music_later_task;

struct task *music_start_later(int music, int wait)
{
    struct task *task;
    struct music_later later;

    if (music_later_task == NULL) {
        later.music = music;
        later.wait = wait;
        task = MirenSetTask(0, &music_later_desc, &later);
        music_later_task = task;
    } else {
        task = NULL;
    }
    return task;
}

void music_start(int music)
{
    ADXTaskInit();
    stream_request_and_save_music(music);
    if (music_later_task != NULL) {
        DestroyTask(music_later_task);
    }
}

void music_end(void)
{
    ADX_Close();
    if (music_later_task != NULL) {
        DestroyTask(music_later_task);
    }
}

void music_play(int music)
{
    stream_request_and_save_music(music);
}

void music_stop(void)
{
    stream_stop_music();
}

void sound_play_near(int se, NJS_POINT3 *pos,
                     const struct sound_falloff *falloff)
{
    struct task_work *camera;
    NJS_POINT3 *at;
    int volume;

    camera = camera_twp;
    if (camera == NULL) {
        dsPlay_oneshot(se, 0, 0, 0);
    } else {
        at = &camera->pos;
        volume = sound_falloff_volume(pos, falloff);
        dsPlay_oneshot_v(se, 0, 0, volume, at->x, at->y, at->z);
    }
}

void sound_keep_near(int se, void *owner, NJS_POINT3 *pos,
                     const struct sound_falloff *falloff)
{
    struct task_work *camera;
    NJS_POINT3 *at;
    int volume;

    if (owner == NULL) {
        return;
    }
    volume = sound_falloff_volume(pos, falloff);
    camera = camera_twp;
    if (camera == NULL) {
        dsPlay_timer(se, (int)owner, 1, 0, KEEP_UPDATES);
        if (volume != 0) {
            dsVolume_id((int)owner, volume);
        }
    } else {
        at = &camera->pos;
        dsPlay_Dolby_time(se, (int)owner, 1, volume, at->x, at->y, at->z,
                          KEEP_UPDATES);
    }
}

void sound_stop_near(void *owner)
{
    if (owner != NULL) {
        dsStop_id((int)owner);
    }
}

int sound_falloff_volume(NJS_POINT3 *pos, const struct sound_falloff *falloff)
{
    int near_volume;
    int far_volume;
    int near;
    int far;
    int volume;
    Float distance;

    if (falloff == NULL) {
        falloff = &sound_falloff_default;
    }
    near_volume = falloff->near_volume;
    if (near_volume < -128) {
        near_volume = -128;
    } else if (near_volume > 127) {
        near_volume = 127;
    }
    far_volume = falloff->far_volume;
    if (far_volume < -128) {
        far_volume = -128;
    } else if (far_volume > 127) {
        far_volume = 127;
    }
    near = (int)falloff->near;
    if ((Float)near < 0.0F) {
        near = 0;
    }
    far = (int)falloff->far;
    if ((Float)far < 0.0F) {
        far = 0;
    }
    if (near > far) {
        /* @hack type: swap as a Float, which converts near to a float and back
         * (FLOAT FPUL,FR3 at 0x8c0a6e5c, FTRC FR4,FPUL at 0x8c0a6e60). near
         * holds 0 or a Float truncated to an int, which a Float holds exactly,
         * so the trip changes nothing. as an int, 25 of 115 words differ */
        Float swap = (Float)near;

        near = far;
        far = (int)swap;
    }
    if (pos == NULL || camera_twp == NULL) {
        volume = near_volume;
    } else {
        distance = CalcDistance(pos, &camera_twp->pos);
        if (distance <= (Float)near) {
            volume = near_volume;
        } else if (distance >= (Float)far) {
            volume = far_volume;
        } else {
            volume = (int)(near_volume +
                           ((far_volume - near_volume) *
                            (distance - (Float)near) / (Float)(far - near)));
        }
    }
    if (volume < -128) {
        volume = -128;
    } else if (volume > 127) {
        volume = 127;
    }
    return volume;
}

static void music_later_init(struct task *task, void *arg)
{
    struct music_later *later = LATER(task);
    struct music_later *from = arg;

    later->music = from->music;
    later->wait = from->wait;
}

static void music_later_step(struct task *task)
{
    struct music_later *later = LATER(task);

    if (later->wait > 0) {
        later->wait--;
    } else {
        music_later_task = NULL;
        music_start(later->music);
        DestroyTask(task);
    }
}

static void music_later_destroy(struct task *task)
{
    music_later_task = NULL;
}
