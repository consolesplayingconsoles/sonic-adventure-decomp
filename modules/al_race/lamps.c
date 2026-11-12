/* @unit 0CB961E0-0CB96380 +r04 +egflags +pool32 */
/* Chao race lamp rows that run through a pattern together */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_race/lamps.h"
#include "al_race/scenery.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/task_desc.h"
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
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);
extern struct set_file *pObjEditTable;
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);

/* the rows' objects, and each row's model's materials, one for each lamp */
#define LAMPS 8
#define LAMP_ROWS(task) ((struct lamps *)(task)->motion)
extern NJS_OBJECT dat_0cbc8e00;
extern NJS_OBJECT dat_0cbc926c;
extern NJS_OBJECT dat_0cbc96d8;
extern NJS_OBJECT dat_0cbcaf20;
extern NJS_MATERIAL dat_0cbc89c8[];
extern NJS_MATERIAL dat_0cbc8e34[];
extern NJS_MATERIAL dat_0cbc92a0[];
extern NJS_MATERIAL dat_0cbca838[];

/* lamps in a row */

struct lamp_row {
    NJS_OBJECT *object;
    NJS_MATERIAL *lamps[LAMPS];
};

/* a set of rows' starting values */
struct lamps_kind {
    const struct lamp_row *rows;
    Sint16 count;
    /* a lit lamp's texture is textures[1][lamp], and an unlit one's
     * textures[0][lamp] */
    const Uint16 (*textures)[LAMPS];
    const Uint8 *patterns; /* a byte for each pattern, a bit for each lamp */
    Sint16 pattern_count;
    Sint16 steps; /* how long each pattern shows */
};

/* the rows' state, in their task's motion */
struct lamps {
    Sint16 pattern;
    Sint16 timer; /* the steps until the next pattern */
    /* the rows' count. it and the fields after it copy the lamps_kind's */
    Sint16 count;
    Sint16 pattern_count;
    Sint16 steps;
    const struct lamp_row *rows;
    const Uint16 (*textures)[LAMPS];
    const Uint8 *patterns;
};

void lamps_start(struct task *task, void *arg);
void lamps_step(struct task *task);
void lamps_draw(struct task *task);
void lamps_show(struct lamps *lamps);
extern const struct task_desc lamps_desc;
extern const Uint16 lamp_textures[2][8];
extern const Uint8 lamp_patterns[71];
extern const struct lamp_row hall_rows[3];
extern const struct lamps_kind hall_lamps;
extern const struct lamp_row course_rows[1];
extern const struct lamps_kind course_lamps;

void hall_lamps_create(void)
{
    scenery_add(&lamps_desc, (void *)&hall_lamps);
}

void course_lamps_create(void)
{
    scenery_add(&lamps_desc, (void *)&course_lamps);
}

void lamps_start(struct task *task, void *arg)
{
    const struct lamp_row *rows = ((struct lamps_kind *)arg)->rows;
    int steps = ((struct lamps_kind *)arg)->steps;
    struct task_work *work = task->work;
    struct lamps *lamps = LAMP_ROWS(task);

    scenery_place(work, rows->object);
    lamps->pattern = 0;
    lamps->timer = steps;
    lamps->count = ((struct lamps_kind *)arg)->count;
    lamps->pattern_count = ((struct lamps_kind *)arg)->pattern_count;
    lamps->steps = steps;
    lamps->rows = rows;
    lamps->textures = ((struct lamps_kind *)arg)->textures;
    lamps->patterns = ((struct lamps_kind *)arg)->patterns;
}

void lamps_step(struct task *task)
{
    struct lamps *lamps;

    lamps_draw(task);
    lamps = LAMP_ROWS(task);
    lamps->timer--;
    if (lamps->timer <= 0) {
        lamps->timer = lamps->steps;
        lamps->pattern++;
        if (lamps->pattern >= lamps->pattern_count) {
            lamps->pattern = 0;
        }
    }
}

void lamps_draw(struct task *task)
{
    struct lamps *lamps;
    const struct lamp_row *row;
    int count;
    int i;

    if (loop_count == 0 && !CheckRange(task)) {
        lamps = LAMP_ROWS(task);
        count = lamps->count;
        lamps_show(lamps);
        SetObjectTexture();
        for (i = 0, row = lamps->rows; i < count; i++, row++) {
            late_DrawObject(row->object);
        }
    }
}

/* give each row's lamps the current pattern's textures. the pattern's
 * lowest bit picks the last lamp's, and its highest bit the first's */
void lamps_show(struct lamps *lamps)
{
    int count = lamps->count;
    const Uint16(*textures)[LAMPS] = lamps->textures;
    Uint8 pattern = lamps->patterns[lamps->pattern];
    const struct lamp_row *row;
    int i;
    int j;
    Uint8 bits;

    for (i = 0, row = lamps->rows; i < count; i++, row++) {
        NJS_MATERIAL *const *lamp;

        bits = pattern;
        j = LAMPS;
        lamp = &row->lamps[LAMPS];
        while (j > 0) {
            j--;
            --lamp;
            (*lamp)->attr_texId = textures[bits & 1][j];
            bits >>= 1;
        }
    }
}
