/* @unit 0C90F4A0-0C90F620 +egflags +pool32 */
/* act 0's upper pool, above the dam. it pours into the act's water once
 * Big has pulled its plug and that water is SHELTER_WATER_RISEN */
#include <sg_xpt.h>

#include "stage/stage.h"
#include "stg12/lid.h"
#include "stg12/plug.h"
#include "stg12/upper_pool.h"
#include "stg12/upper_water.h"
#include "stg12/water.h"
#include "stg12/waterfall.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

#define POOL_X 750.0F
#define POOL_Y 65.0F
#define POOL_Z (-650.0F)

/* the pool's surface starts at FULL_LEVEL. as the pool pours, its surface
 * falls POUR_SPEED each step down to LOW_LEVEL */
#define FULL_LEVEL 155.0F
#define POUR_SPEED 0.15F
#define LOW_LEVEL 82.5F

/* the act's water rises FILL_SPEED each step the pool pours, about 62.1
 * units in all */
#define FILL_SPEED (62.1F / (FULL_LEVEL - LOW_LEVEL) * POUR_SPEED)

enum shelter_upper_pool_mode { POOL_FULL, POOL_POUR, POOL_LOW };
extern int shelter_big_flags;
extern Float shelter_upper_pool_level;

void shelter_upper_pool_step(struct task *task);
void shelter_upper_pool_destroy(struct task *task);

void shelter_upper_pool_start(struct task *task)
{
    struct task_work *work = task->work;

    work->mode = POOL_FULL;
    /* the stage and the act the pool starts in. the step kills the pool
     * once either changes */
    TASK_TIMER(work) = GetStageNumber();
    work->pos.x = POOL_X;
    work->pos.y = POOL_Y;
    work->pos.z = POOL_Z;
    shelter_big_flags = 0;
    CreateChildTask(TASK_WORK | TASK_MOTION, shelter_plug_start, task);
    CreateChildTask(TASK_WORK, shelter_lid_start, task);
    shelter_upper_pool_level = FULL_LEVEL;
    CreateChildTask(TASK_WORK | TASK_FORCE, shelter_upper_water_start, task);
    task->step = shelter_upper_pool_step;
    task->destructor = shelter_upper_pool_destroy;
}

void shelter_upper_pool_step(struct task *task)
{
    struct task_work *work = task->work;

    if (TASK_TIMER(work) != GetStageNumber()) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case POOL_FULL:
        if ((shelter_big_flags & BIG_PULLED) &&
            shelter_water_state == SHELTER_WATER_RISEN) {
            work->mode = POOL_POUR;
            CreateChildTask(TASK_WORK, shelter_waterfall_start, task);
        }
        LoopTaskC(task);
        break;
    case POOL_POUR:
        shelter_upper_pool_level -= POUR_SPEED;
        if (shelter_upper_pool_level <= LOW_LEVEL) {
            shelter_upper_pool_level = LOW_LEVEL;
            shelter_water_state = SHELTER_WATER_FULL;
            work->mode = POOL_LOW;
        } else {
            shelter_water_level += FILL_SPEED;
        }
        LoopTaskC(task);
        break;
    case POOL_LOW:
        LoopTaskC(task);
        break;
    }
}

void shelter_upper_pool_destroy(struct task *task)
{
    FreeTaskC(task);
}
