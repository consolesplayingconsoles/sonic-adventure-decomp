/* @unit 0C908620-0C9087E0 +r04 +egflags +pool32 */
/* the controller of act 0's orcas, its sea and its floating bridge */
#include <ninja.h>
#include <sg_xpt.h>

#include "stg01/bridge.h"
#include "stg01/orca.h"
#include "stg01/orca_control.h"
#include "stg01/path_orca.h"
#include "stg01/sea.h"
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
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
Bool FUN_0c90867c(void);
Bool FUN_0c908710(void);
void FUN_0c90878c(Float x, Float z, Float radius, Float width, Float height);
void ObjectBeachPathoruka(struct task *task);
extern struct task *OrukaTask;
extern Bool orca_leaving;
extern struct task *sea_task;
extern NJS_POINT3 orca_head;
extern NJS_VECTOR orca_speed;
extern Sint32 orca_crash_wait;

void orInitOrukaSequence(void)
{
    OrukaTask = NULL;
    orca_head.x = 0.0F;
    orca_head.y = 0.0F;
    orca_head.z = 0.0F;
    CreateYurehasi();
    sea_task = CreateElementalTask(TASK_WORK | TASK_FORCE, 3, beach_sea_init);
    orca_crash_wait = 0;
}

void orca_control_end(void)
{
    beach_bridge_remove();
    if (OrukaTask != NULL) {
        FreeTask(OrukaTask);
    }
    if (sea_task != NULL) {
        FreeTask(sea_task);
    }
}

Bool FUN_0c90867c(void)
{
    return FALSE;
}

Bool orCreateAttackOruka(Float x, Float y, Float z, Angle ang)
{
    struct task_work *work;

    if (OrukaTask != NULL) {
        FreeTask(OrukaTask);
    }
    orca_leaving = FALSE;
    OrukaTask =
        CreateElementalTask(TASK_MOTION | TASK_WORK, 3, ObjectBeachAttackoruka);
    work = OrukaTask->work;
    work->pos.x = x;
    work->pos.y = y;
    work->pos.z = z;
    work->ang.y = ang;
    return TRUE;
}

Bool orca_send_away(void)
{
    /* @hack redundant: the else after the return, which has SHC load
     * orca_leaving's address into R1 at 0x0c908b26. without it, R3 takes
     * the address, and 2 of 12 words differ */
    if (OrukaTask == NULL) {
        return FALSE;
    } else {
        orca_leaving = TRUE;
        return TRUE;
    }
}

void orca_clear_task(struct task *task)
{
    if (OrukaTask == task) {
        OrukaTask = NULL;
        orca_head.x = 0.0F;
        orca_head.y = 0.0F;
        orca_head.z = 0.0F;
    }
}

Bool FUN_0c908710(void)
{
    /* @hack redundant: the else after the return, which has SHC hold
     * orca_leaving's address in R3 and the 0 it stores in R1 at 0x0c908ba0.
     * without it, the two trade, and 7 of 22 words differ */
    if (OrukaTask != NULL) {
        return FALSE;
    } else {
        orca_leaving = FALSE;
        OrukaTask = CreateElementalTask(TASK_MOTION | TASK_WORK, 3,
                                        ObjectBeachPathoruka);
        return TRUE;
    }
}

void orFreePathOruka(struct task *task)
{
    if (OrukaTask == task) {
        OrukaTask = NULL;
    }
}

void FUN_0c90878c(Float x, Float z, Float radius, Float width, Float height)
{
    beach_sea_add_ripple(sea_task, x, z, radius, width, height);
}

Float beach_sea_height(Float x, Float z)
{
    Float height = 0.0F;

    if (sea_task != NULL) {
        height = beach_sea_get_height(sea_task, x, z);
    }
    return height;
}
