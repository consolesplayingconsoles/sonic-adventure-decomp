/* @unit 8C0A1220-8C0A15A0 @data 8C15B174-8C15B1B4 +egflags +pool32 +poolkeep=debug_menu_step */
/* the debug menu: a page of items, each starting a task as the menu's
 * child */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "debug/editor.h"
#include "debug/menu.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "system/frame.h"
#include "system/pad.h"
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
void pdExecPeripheralServerUser(void);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
Bool OnEdit(struct task *task);
void kmiLogFileOpen(void *data);
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
Uint16 GetStageNumber(void);
Bool ChkPause(void);
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);

#define MENU(task) ((struct debug_menu *)(task)->motion)
enum debug_menu_mode {
    DEBUG_MENU_CLOSED,
    DEBUG_MENU_OPEN,
    DEBUG_MENU_RUNNING /* the chosen item's task, until it ends */
};

struct debug_menu {
    Sint8 mode;
    Sint8 count;
    Sint8 selection;
    Sint16 column;
    Sint16 row;
    struct debug_menu_item *items;
};

void debug_menu_sound(Sint8 result);
void debug_menu_init(struct task *task, struct debug_menu_page *page);
void debug_menu_step(struct task *task);
void debug_menu_draw(struct task *task);
void debug_menu_destroy(struct task *task);
enum debug_menu_result debug_menu_choose(struct task *task);

/* the menu's task. the step draws the menu, so the task has no draw */
static const struct task_desc debug_menu_desc = {
    sizeof(struct debug_menu),
    0,
    (void (*)(struct task *, void *))debug_menu_init,
    debug_menu_step,
    NULL,
    debug_menu_destroy};

/* each result's sound, or -1 for none */
static const int debug_menu_sounds[6] = {
    -1, SE_ICE_BREAK, SE_CHOOSE, SE_MENU_CLOSE, SE_MOVE, SE_MENU_OPEN};

struct task *debug_menu_create(struct debug_menu_page *page)
{
    struct task *task;

    task = MirenSetTask(0, &debug_menu_desc, page);
    return task;
}

Sint8 debug_menu_select(struct task *task, int *selection, int count,
                        enum debug_menu_result (*choose)(struct task *task))
{
    Uint32 press = debug_pad_press();
    Uint32 repeat = debug_pad_repeat();
    int at = *selection;
    int last = count - 1;
    enum debug_menu_result result = DEBUG_MENU_IDLE;

    if (press & PDD_DGT_TB) {
        result = DEBUG_MENU_CLOSE;
    } else if (press & PDD_DGT_TA) {
        result = choose(task);
    } else if (repeat & PDD_DGT_KD) {
        if (at < last) {
            at++;
        } else {
            at = 0;
        }
    } else if (repeat & PDD_DGT_KU) {
        if (at > 0) {
            at--;
        } else {
            at = last;
        }
    }
    if (at != *selection) {
        result = DEBUG_MENU_MOVE;
        *selection = at;
    }
    debug_menu_sound(result);
    return result;
}

Uint32 debug_pad_on(void)
{
    return per[3]->on;
}

Uint32 debug_pad_press(void)
{
    return per[3]->press;
}

Uint32 debug_pad_repeat(void)
{
    return pad_press_repeat[0];
}

void debug_menu_sound(Sint8 result)
{
    int se;

    if (result >= 0 && result < DEBUG_MENU_RESULTS) {
        se = debug_menu_sounds[result];
        if (se >= 0) {
            dsPlay_oneshot(se, 0, 0, 0);
        }
    }
}

/* @hack type: the page taken as its own type, which debug_menu_desc casts
 * to init's; taking a void pointer, SHC copies the page to R6 before the
 * null test (TST R5,R5 at 0x8c0a740a) and 32 of 34 words differ */
void debug_menu_init(struct task *task, struct debug_menu_page *page)
{
    int count = 0;
    struct debug_menu_item *items = NULL;
    struct debug_menu_item *item;
    struct debug_menu *menu;

    if (page != NULL) {
        items = page->items;
        for (item = items; item->desc != NULL; item++) {
            count++;
        }
    }
    if (count <= 0) {
        FreeTask(task);
        return;
    }
    menu = MENU(task);
    menu->mode = DEBUG_MENU_CLOSED;
    menu->count = count;
    menu->selection = 0;
    menu->column = page->column;
    menu->row = page->row;
    menu->items = items;
}

void debug_menu_step(struct task *task)
{
    Uint32 on = debug_pad_on();
    Uint32 press = debug_pad_press();
    struct debug_menu *menu;
    int selection;
    Sint8 result;

    if (edit_mode) {
        return;
    }
    if (on & PDD_DGT_TX) {
        return;
    }
    menu = MENU(task);
    switch (menu->mode) {
    case DEBUG_MENU_CLOSED:
        if ((on & PDD_DGT_TY) && (press & PDD_DGT_ST)) {
            debug_menu_sound(DEBUG_MENU_START);
            PadReadOff();
            pause_disable();
            menu->mode = DEBUG_MENU_OPEN;
        }
        break;
    case DEBUG_MENU_OPEN:
        /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
        selection = menu->selection;
        result =
            debug_menu_select(task, &selection, menu->count, debug_menu_choose);
        menu->selection = selection;
        switch (result) {
        case DEBUG_MENU_DONE:
        case DEBUG_MENU_START:
            menu->mode = DEBUG_MENU_RUNNING;
            /* fall through */
        case DEBUG_MENU_IDLE:
        case DEBUG_MENU_NOTHING:
        case DEBUG_MENU_MOVE:
            pause_disable();
            break;
        case DEBUG_MENU_CLOSE:
            ufExitSystem();
            pause_enable();
            menu->mode = DEBUG_MENU_CLOSED;
            break;
        }
        break;
    case DEBUG_MENU_RUNNING:
        LoopTaskC(task);
        if (task->child == NULL) {
            menu->mode = DEBUG_MENU_OPEN;
        }
        pause_disable();
        break;
    }
    debug_menu_draw(task);
}

/* draw the open menu, on a frame's first step only */
void debug_menu_draw(struct task *task)
{
    struct debug_menu *menu;
    struct debug_menu_item *item;
    const char *label;
    int column;
    int row;

    if (loop_count != 0) {
        return;
    }
    menu = MENU(task);
    switch (menu->mode) {
    case DEBUG_MENU_CLOSED:
        break;
    case DEBUG_MENU_RUNNING:
        break;
    case DEBUG_MENU_OPEN:
        column = menu->column;
        row = menu->row;
        njPrintColor(0xff00ff00);
        njPrintC(NJM_LOCATION(column, row), "<Main menu>");
        row++;
        njPrintColor(0xffff0000);
        njPrintC(NJM_LOCATION(column, row + menu->selection), ">");
        column++;
        njPrintColor(0xffffffff);
        for (item = menu->items; item->desc != NULL; item++, row++) {
            label = item->label;
            if (label != NULL) {
                njPrintC(NJM_LOCATION(column, row), label);
            }
        }
        break;
    }
}

void debug_menu_destroy(struct task *task)
{
    ufExitSystem();
    pause_enable();
}

enum debug_menu_result debug_menu_choose(struct task *task)
{
    struct debug_menu *menu = MENU(task);
    struct debug_menu_item *item = &menu->items[menu->selection];
    const struct task_desc *desc = item->desc;
    struct task *child;
    enum debug_menu_result result = DEBUG_MENU_NOTHING;

    if (desc != NULL) {
        child = MirenSetChildTask(task, desc, item->arg);
        if (child != NULL) {
            result = DEBUG_MENU_START;
        }
    }
    return result;
}
