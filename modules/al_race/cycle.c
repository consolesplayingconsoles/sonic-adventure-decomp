/* @unit 0CB89B40-0CB89C00 @data 0CB989E0-0CB989F8 +r04 +egflags +pool32 */
/* the course's texture cycles, each a material that shows textures in turn */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_race/cycle.h"
#include "al_race/scenery.h"
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

/* the course's materials that cycle */
#define CYCLE(task) ((struct cycle *)(task)->motion)
#define CYCLE_COUNT 3
extern NJS_MATERIAL dat_0cbbfb88;
extern NJS_MATERIAL dat_0cbbfeb4;
extern NJS_MATERIAL dat_0cbab120;

/* cycle_start's arg: a material, and the textures it shows in turn */
struct cycle_kind {
    NJS_MATERIAL *material;
    const Sint16 *textures;
    Sint16 count;
    Sint16 steps; /* the steps each texture shows */
};

/* a cycle's state, in its task's motion */
struct cycle {
    Sint16 texture; /* an index into textures */
    Sint16 count;
    Sint16 timer; /* the steps since the last change */
    Sint16 steps;
    NJS_MATERIAL *material;
    const Sint16 *textures;
};

void cycle_start(struct task *task, void *arg);
void cycle_step(struct task *task);
static void cycle_show(struct cycle *cycle);

static const struct task_desc cycle_desc = {
    sizeof(struct cycle), 0, cycle_start, cycle_step, NULL, NULL};
extern const Sint16 cycle_textures[14];
extern const struct cycle_kind cycle_kinds[3];

void cycles_create(void)
{
    const struct cycle_kind *kind;
    /* @hack spelling: count, CYCLE_COUNT in a local, which keeps the loop
     * rolled, as the image does. as CYCLE_COUNT, SHC writes the body three
     * times a pass, the function runs 16 bytes long, and 15 of 22 words
     * differ */
    int count = CYCLE_COUNT;
    int i;

    for (i = 0, kind = cycle_kinds; i < count; i++, kind++) {
        scenery_add(&cycle_desc, (void *)kind);
    }
}

void cycle_start(struct task *task, void *arg)
{
    struct cycle *cycle = CYCLE(task);

    /* @hack spelling: the kind read through a cast of arg at each use, which
     * SHC reads from R5, where arg arrives (0x0cb8a9b4 to 0x0cb8a9c6), as the
     * image does. through a local of the kind's type, SHC copies arg into
     * R4, the function runs 2 bytes long, and 13 of 17 words differ */
    cycle->texture = 0;
    cycle->count = ((struct cycle_kind *)arg)->count;
    cycle->timer = 0;
    cycle->steps = ((struct cycle_kind *)arg)->steps;
    cycle->material = ((struct cycle_kind *)arg)->material;
    cycle->textures = ((struct cycle_kind *)arg)->textures;
    cycle_show(cycle);
}

void cycle_step(struct task *task)
{
    struct cycle *cycle = CYCLE(task);

    cycle->timer++;
    if (cycle->timer >= cycle->steps) {
        cycle->timer = 0;
        cycle->texture++;
        if (cycle->texture >= cycle->count) {
            cycle->texture = 0;
        }
        cycle_show(cycle);
    }
}

static void cycle_show(struct cycle *cycle)
{
    cycle->material->attr_texId = (Uint16)cycle->textures[cycle->texture];
}
