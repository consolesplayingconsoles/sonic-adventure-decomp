/* @unit 8C034CE0-8C034DE0 +egflags +onepool +pool32 */
/* the debug flag, debug axes and lines, and the names of frame files and
 * stages */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/debug.h"
#include "draw/light.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

#define ORANGE 0xffff8000

/* an entry of a menu list, which ends with an entry of zeros and an empty
 * name */
struct menu_entry {
    Sint32 unk_00;
    const char *name;
    void (*func)(void);
    Sint32 unk_0c;
};

struct edit_item {
    const char *name;
    Float *value;
    Sint32 unk_08;
    Float unk_0c[5];
};

struct edit_menu {
    Sint32 count;
    Sint32 unk_04;
    Sint16 unk_08[4];
    struct edit_item *items;
};

void light_choose(void);
extern Sint16 debug_flag;
extern NJS_POINT3 debug_axis_points[6];
extern NJS_BGRA debug_axis_colors[6];
extern NJS_POINT3COL debug_axes;
extern char frame_file_name[];
extern char hex_digits[];
extern Uint16 frame_file_count;
extern struct menu_entry light_entries[];
extern struct edit_item light_items[];
extern struct edit_menu light_menu;
extern const char *stage_names[43][8];

Bool debug_set_flag(Sint16 on)
{
    if (on) {
        if (debug_flag == 0) {
            debug_flag = -1;
            return TRUE;
        }
    } else if (debug_flag != 0) {
        debug_flag = 0;
        return TRUE;
    }
    return FALSE;
}

void debug_draw_axes(struct task_work *work)
{
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    njDrawLine3D(&debug_axes, 3, NJD_DRAW_NORMAL);
    late_DrawObjectClipEx(1);
    /* @hack redundant: a return where the function ends anyway. with it, SHC
     * opens the frame with ADD #-4,R15 and stores work in it (0x8c035e0c,
     * 0x8c035e10); without it, one push does both, the function runs 2 bytes
     * short and 20 of 21 words differ */
    return; /* NOLINT(readability-redundant-control-flow) */
}

void debug_draw_line(NJS_POINT3 *pos, NJS_VECTOR *dir, Float length)
{
    NJS_POINT3 points[2];
    NJS_COLOR color;
    NJS_POINT3COL line;

    points[0].x = 0.0F;
    points[0].y = 0.0F;
    points[0].z = 0.0F;
    points[1].x = dir->x * length;
    points[1].y = dir->y * length;
    points[1].z = dir->z * length;
    color.color = ORANGE;
    line.p = points;
    line.col = &color;
    line.tex = NULL;
    line.num = 2;
    njPushMatrix(NULL);
    njTranslate(NULL, pos->x, pos->y, pos->z);
    njDrawLine3D(&line, 1, NJD_DRAW_NORMAL);
    late_DrawObjectClipEx(1);
}

void fun_8c035f18(void)
{
}

void light_choose(void)
{
}

void debug_print_stage_name(Int loc, Sint16 stage_act)
{
}
