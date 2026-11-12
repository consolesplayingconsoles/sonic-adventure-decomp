/* @unit 8C0A15A0-8C0A1700 @data 8C15B1B4-8C15B1FC +spflags +pool32 */
/* the debug info menu: one item, which turns the debug info on and off */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/info.h"
#include "debug/menu.h"
#include "system/frame.h"
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
void nwEditWinPrintf(Int loc, const char *fmt, ...);
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
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);

#define INFO_MENU(task) ((struct debug_info_menu *)(task)->motion)
struct debug_info_menu {
    Sint8 count;
    Sint8 selection;
    Sint16 column;
    Sint16 row;
};

static void debug_info_menu_init(struct task *task, void *arg);
static void debug_info_menu_step(struct task *task);
static void debug_info_menu_draw(struct task *task);
static enum debug_menu_result debug_info_menu_choose(struct task *task);

/* the info menu's task, which nothing creates. init takes the menu's
 * column and row from a debug_menu_page as its arg. the step draws the
 * menu, so the task has no draw */
/* NOLINTNEXTLINE(clang-diagnostic-unused-const-variable) */
static const struct task_desc debug_info_menu_desc = {
    sizeof(struct debug_info_menu), 0, debug_info_menu_init,
    debug_info_menu_step,           0, 0};
extern Sint8 debug_info;

Bool debug_info_on(void)
{
    return debug_info;
}

static void debug_info_menu_init(struct task *task, void *arg)
{
    struct debug_info_menu *menu = INFO_MENU(task);
    struct debug_menu_page *page = arg;

    menu->count = 1;
    menu->selection = 0;
    menu->column = page->column;
    menu->row = page->row;
}

static void debug_info_menu_step(struct task *task)
{
    struct debug_info_menu *menu = INFO_MENU(task);
    /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
    int selection = menu->selection;
    Sint8 result;

    result = debug_menu_select(task, &selection, menu->count,
                               debug_info_menu_choose);
    menu->selection = selection;
    switch (result) {
    case DEBUG_MENU_IDLE:
    case DEBUG_MENU_NOTHING:
    case DEBUG_MENU_DONE:
    case DEBUG_MENU_START:
    case DEBUG_MENU_MOVE:
        break;
    case DEBUG_MENU_CLOSE:
        FreeTask(task);
        break;
    }
    debug_info_menu_draw(task);
}

/* draw the menu, on a frame's first step only */
static void debug_info_menu_draw(struct task *task)
{
    struct debug_info_menu *menu;
    int column;
    int row;

    if (loop_count != 0) {
        return;
    }
    menu = INFO_MENU(task);
    column = menu->column;
    row = menu->row;
    njPrintColor(0xff00ff00);
    njPrintC(NJM_LOCATION(column, row), "<Debug info menu>");
    row++;
    njPrintColor(0xffff0000);
    njPrintC(NJM_LOCATION(column, row + menu->selection), ">");
    column++;
    njPrintColor(0xffffffff);
    nwEditWinPrintf(((column) << 16 | (row)), "DEBUG INFO: %s",
                    debug_info ? "ON" : "OFF");
}

static enum debug_menu_result debug_info_menu_choose(struct task *task)
{
    struct debug_info_menu *menu = INFO_MENU(task);
    enum debug_menu_result result = DEBUG_MENU_NOTHING;

    /* @hack spelling: a switch of one case, which SHC tests with CMP/EQ
     * #0,R0 (0x8c0a77d2); as an if, it tests with TST R0,R0 and 1 of 13 words
     * differs */
    switch (menu->selection) {
    case 0:
        debug_info = !debug_info;
        result = DEBUG_MENU_DONE;
        break;
    }
    return result;
}
