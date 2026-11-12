/* @unit 0C900360-0C900400 +r04 +egflags +pool32 */
/* Chaos 6's stage, the fight on the Egg Carrier's deck: its task, and the
 * task that starts its music */
#include "b_chaos6/chaos6.h"
#include "b_chaos6/boss.h"
#include "b_chaos6/sky.h"
#include "chaos/effect.h"
#include "chaos/start.h"
#include "sound/stream.h"
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
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void SetEffectPunchTame(NJS_POINT3 *target);
void FUN_8c0f0ac0(void);
void ADX_Close(void);
void BGM_Play(int music);
Bool CameraFishingCatch(void);

enum chaos6_mode { CHAOS6_START, CHAOS6_FIGHT };

void chaos6_start(struct task *task);
void chaos6_step(struct task *task);
void chaos6_music_wait_step(struct task *task)
{
    struct task_work *work = task->work;
    --work->timer;
    if (work->timer < 0) {
        ADXTaskInit();
        stream_request_and_save_music(work->mode);
        DestroyTask(task);
    }
}

/* the stage's first step: start the boss and the clouds, and set up the
 * Chaos effects. it also sets boss_waiting and clears chaos_handed_over,
 * through chaos_start */
void chaos6_start(struct task *task)
{
    struct task_work *work = task->work;

    FUN_8c0f0ac0();
    chaos6_create();
    chaos_effect_init();
    CreateElementalTask(TASK_WORK, 3, chaos6_clouds_step);
    work->mode = CHAOS6_FIGHT;
}
