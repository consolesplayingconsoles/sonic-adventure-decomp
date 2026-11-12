/* @unit 0CB91C40-0CB91E00 @data 0CB99644-0CB9965C +egflags +pool32 */
/* the deal, which collects the race's items and shuffles them out to the
 * lanes */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_race/deal.h"
#include "al_race/racer.h"
#include "al_race/scenery.h"
#include "debug/editor.h"
#include "system/shuffle.h"
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
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void FUN_0cb91dc4(struct task *task);
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);
Bool OnEdit(struct task *task);
extern struct deal_item deal_items[20];

static const struct task_desc deal_desc = {sizeof(struct deal_work),
                                           0,
                                           deal_start,
                                           deal_step,
                                           ((void *)0),
                                           FUN_0cb91dc4};
extern Sint8 deal_state;
extern Sint8 deal_count;
extern Sint8 deal_open;

struct task *deal_create(Sint8 open)
{
    struct task *task;

    if (deal_state) {
        task = NULL;
    } else {
        deal_open = open;
        task = scenery_add(&deal_desc, NULL);
    }
    return task;
}

Bool deal_add(struct task *task, void (*set)(struct task *, int), Sint8 kind)
{
    /* deal_count holds 0 to DEAL_ITEMS, so widening it as signed, as the
     * image does, loses nothing */
    /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
    int count = deal_count;
    int result = 0;
    struct deal_item *entry;

    if (!deal_open || count >= DEAL_ITEMS) {
        FreeTask(task);
    } else {
        switch (deal_state) {
        case DEAL_IDLE:
            break;
        case DEAL_OPEN:
            entry = &deal_items[count];
            entry->task = task;
            entry->set = set;
            entry->kind = kind;
            deal_count++;
            result = 1;
            break;
        case DEAL_DEALT:
            FreeTask(task);
            break;
        }
    }
    return result;
}

int deal_take(NJS_POINT3 *pos, int lane)
{
    int result = 0;
    struct deal_item *entry;
    struct task *task;
    void (*set)(struct task *, int);

    if (deal_state == DEAL_DEALT && pos && lane >= 0 && lane < RACE_LANES) {
        entry = &deal_items[lane];
        task = entry->task;
        if (task) {
            *pos = task->work->pos;
            set = entry->set;
            result = 1;
            if (set) {
                set(task, lane);
            }
        }
    }
    return result;
}

void deal_start(struct task *task, void *arg)
{
    struct deal_work *work;

    deal_count = 0;
    deal_state = DEAL_OPEN;
    work = (struct deal_work *)task->motion;
    work->mode = 0;
}

void deal_step(struct task *task)
{
    /* deal_count holds 0 to DEAL_ITEMS, so widening it as signed, as the
     * image does, loses nothing */
    /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
    int count = deal_count;
    struct deal_work *work = (struct deal_work *)task->motion;
    struct deal_item *entries;
    struct deal_item *entry;

    switch (work->mode) {
    case 0:
        if (count > 0 && !edit_mode) {
            entries = deal_items;
            for (entry = &entries[count]; count < RACE_LANES;
                 count++, entry++) {
                entry->task = NULL;
            }
            deal_count = count;
            deal_state = DEAL_DEALT;
            array_shuffle(entries, count, sizeof(struct deal_item));
            work->mode = 1;
        }
        break;
    case 1:
        break;
    }
}

void FUN_0cb91dc4(struct task *task)
{
    deal_state = DEAL_IDLE;
}
