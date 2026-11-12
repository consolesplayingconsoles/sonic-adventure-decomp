/* @unit 0C90701A-0C907158 @data 0C9078CC-0C9078D4 +r04 +egflags +poolafter=bottom_destroy +asmfunc=bottom_destroy:0c907080 */
/* Chaos 4's stage. its task starts the fight, and its sky's task sets the
 * colors behind the land */
#include <ninja.h>

#include "b_chaos4/boss.h"
#include "b_chaos4/chaos4.h"
#include "b_chaos4/column.h"
#include "b_chaos4/util.h"
#include "chaos/effect.h"
#include "hud/boss_name.h"
#include "hud/hud.h"
#include "sound/stream.h"
#include "stage/stage.h"
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
void WakeTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
Bool CameraFishingCatch(void);
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
Bool ChkPause(void);

#define TEXT_1_LENGTH 7

/* the stage task's modes. nothing in the module sets CHAOS4_END, which
 * stops the stream */
#define MUSIC_DELAY 5
#define SKY_BACK_1 0x1040
#define SKY_BACK_2 0x401074
#define SKY_BACK_3 0x807474
enum chaos4_mode { CHAOS4_WAIT, CHAOS4_START, CHAOS4_FIGHT, CHAOS4_END };

enum sky_mode { SKY_START, SKY_RUN, SKY_RESET };

/* the steps the music's task counts down before the music starts */

/* the three colors njSetBackColor puts behind the land: dark blue, violet
 * and a dull pink */

void ReleaseMobileLandObject(struct task *task);
void chaos4_end(struct task *task);
void bottom_destroy(struct task *task)
{
    struct task_work *work = task->work;
    switch (work->mode) {
    case CHAOS4_WAIT:
        work->mode = CHAOS4_START;
        break;
    case CHAOS4_START:
        ReleaseMobileLandObject(task);
        break;
    case CHAOS4_FIGHT:
        break;
    case CHAOS4_END:
        chaos4_end(task);
        break;
    }
}
void dsEventBGMRestart(struct task *task)
{
    struct task_work *work = task->work;
    --work->timer;
    if (work->timer < 0) {
        ADXTaskInit();
        BGM_Play(work->mode);
        DestroyTask(task);
    }
}

/* start the fight, a step after the stage's task starts: the boss, his
 * effects, his name and the music */
void ReleaseMobileLandObject(struct task *task)
{
    struct task_work *work = task->work;
    struct task *music;

    GetStageNumber();
    SleepTimer();
    effect_counts_clear();
    chaos4_create();
    chaos_effect_init();
    chaos4_sprites_init();
    SetDisplayBossName("Chaos 4", -1, 240, 120);
    work->mode = CHAOS4_FIGHT;
    music = CreateElementalTask(TASK_WORK, 0, dsEventBGMRestart);
    music->work->mode = MUSIC_CHAOS;
    music->work->timer = MUSIC_DELAY;
}

void chaos4_end(struct task *task)
{
    ADX_Close();
}
void chaos4_sky_step(struct task *task);
