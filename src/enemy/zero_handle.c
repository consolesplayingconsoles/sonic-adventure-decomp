/* @unit 8C107640-8C1077A0 @data 8C15D498-8C15D4A0 +spflags +pool32 +poolafter=zero_exists +synth16 +hoist=0,1 */
/* the handle on Zero's task: the task zero_appear made, until zero_kill or
 * zero_init empties it */
#include <ninja.h>
#include <sg_xpt.h>

#include "enemy/zero.h"
#include "enemy/zero_handle.h"
#include "event/play.h"
#include "stage/stage.h"
#include "system/task.h"
#include "system/texture.h"
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
void EggrobForEvent0(struct task *task);
Bool FUN_8c107740(NJS_POINT3 *pos);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void EV_Load2(int number);
void EV_Exec2(void);
Bool EV_CheckExec(int number);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z, Angle ang_x,
                     Angle ang_y, Angle ang_z);
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
extern struct task *zero_task;

void ERobCtrlInit(void)
{
    zero_task = NULL;
    if (GetStageNumber() == STAGE_ACT(STAGE_FINAL, 0) ||
        (!IN_STAGE(STAGE_EGGMANROBO) && !EV_CheckCansel())) {
        texLoadTexturePvmFile("EGGROB", &zero_texlist);
    }
}

Bool zero_appear(struct zero_start *start)
{
    if (zero_task != NULL) {
        return FALSE;
    }
    /* @hack spelling: the task stored as it's tested, which loads zero_task's
     * address again after the call and tests R0 (0x8c1164f0, 0x8c1164f2); as
     * two statements, SHC keeps the address in R14 across the call and 18 of
     * 19 words differ */
    if ((zero_task = zero_create(start)) == NULL) {
        return FALSE;
    }
    return TRUE;
}

Bool zero_kill(void)
{
    /* @hack redundant: the else after the return, which loads task_kill's
     * address into R2 (0x8c116570), then zero_task's into R2 after the call
     * and the null into R3 (0x8c116576, 0x8c116578); without it, R2 and R3
     * trade and 5 of 18 words differ */
    if (zero_task == NULL) {
        return FALSE;
    } else {
        FreeTask(zero_task);
        zero_task = NULL;
        return TRUE;
    }
}

Bool zero_leave(void)
{
    if (zero_task == NULL) {
        return FALSE;
    }
    zero_task->work->tick |= ZERO_LEAVING;
    return TRUE;
}

Bool zero_exists(void)
{
    if (zero_task == NULL) {
        return FALSE;
    }
    return TRUE;
}

Bool FUN_8c107740(NJS_POINT3 *pos)
{
    if (zero_task == NULL || pos == NULL) {
        return FALSE;
    }
    *pos = zero_task->work->pos;
    return TRUE;
}
