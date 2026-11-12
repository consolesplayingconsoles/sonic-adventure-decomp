/* @unit 0C905480-0C905600 @data 0C90A5B8-0C90A5D0 +r04 +egflags +pool32 */
/* Sand Hill's act tasks, the children of a parent that lives as long as the
 * act */
#include <ninja.h>
#include <sg_xpt.h>

#include "effect/flare.h"
#include "sboard/act.h"
#include "sboard/gate_combo.h"
#include "sboard/rolling_rock.h"
#include "sboard/sand_worm.h"
#include "stage/stage.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);
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

/* the parent's record, in task->motion: the stage and act it was made in */
struct act_record {
    Uint8 stage;
    Uint8 act;
};

void act_parent_init(struct task *task, void *arg);
void act_parent_step(struct task *task);

static const struct task_desc act_parent_desc = {
    sizeof(struct act_record), 0, act_parent_init, act_parent_step, NULL, NULL};
extern const NJS_POINT3 sun_pos;
extern struct task *act_parent;

struct task *act_parent_create(void)
{
    /* @hack spelling: the result through task, which keeps the call a JSR
     * (0x0c905548); returned directly, it becomes a tail jump to
     * task_create_desc, and 9 of 9 words differ */
    struct task *task = MirenSetTask(3, &act_parent_desc, NULL);

    return task;
}

void act_parent_kill(void)
{
    if (act_parent != NULL) {
        FreeTask(act_parent);
        act_parent = NULL;
    }
}

void act_parent_destroy(void)
{
    if (act_parent != NULL) {
        DestroyTask(act_parent);
        act_parent = NULL;
    }
}

struct task *act_task_create(const struct task_desc *desc, void *arg)
{
    struct task *parent = act_parent;
    struct task *task;

    task = parent == NULL ? NULL : MirenSetChildTask(parent, desc, arg);
    return task;
}

void act_parent_init(struct task *task, void *arg)
{
    struct act_record *record;
    Uint32 stage_act;

    act_parent = task;
    record = (struct act_record *)task->motion;
    stage_act = GetStageNumber();
    record->stage = STAGE_OF(stage_act);
    record->act = stage_act & 0xff;
    sand_worm_a_create();
    sand_worm_b_create();
    sand_worm_c_create();
    sand_worm_d_create();
    rolling_rock_a_create();
    rolling_rock_b_create();
    rolling_rock_c_create();
    gate_combo_create();
    act_task_create(&flare_desc, (void *)&sun_pos);
}

void act_parent_step(struct task *task)
{
    Uint32 stage_act = GetStageNumber();
    struct act_record *record = (struct act_record *)task->motion;

    if (STAGE_OF(stage_act) != record->stage ||
        (stage_act & 0xff) != record->act) {
        DestroyTask(task);
    } else {
        LoopTaskC(task);
    }
}
