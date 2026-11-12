/* @unit 0C906A00-0C906AA0 @data 0C907858-0C907874 +jpflags +pool32 */
/* SMOKE__, Chaos 6's smoke: a puff of dust at the object's pos once every
 * SMOKE_WAIT + 1 steps. the object's scl.x sets each puff's scale, and its
 * scl.y the gray of its color, from 0 to 1. the set editor labels both
 * fields */
#include <ninja.h>
#include <sg_xpt.h>

#include "b_chaos6/smoke.h"
#include "debug/editor.h"
#include "effect/dust.h"
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
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);

/* the steps with no puff between two puffs */
#define SMOKE_WAIT 6

#define VARS(work) ((struct smoke_vars *)&(work)->vars)
struct smoke_vars {
    Uint8 unk_00[4];
    Sint16 steps; /* the steps since its last puff */
};

enum smoke_mode { SMOKE_START, SMOKE_RUN };
extern struct dust_params chaos6_smoke_params;

void chaos6_smoke_step(struct task *task)
{
    struct task_work *work = task->work;

    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- SIZE");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "<- COLOR(0.0 - 1.0)");
    }
    switch (work->mode) {
    case SMOKE_START:
        work->mode = SMOKE_RUN;
        /* fall through */
    case SMOKE_RUN:
        if (++VARS(work)->steps > SMOKE_WAIT) {
            VARS(work)->steps = 0;
            chaos6_smoke_params.scale = work->scl.x;
            chaos6_smoke_params.pos = work->pos;
            chaos6_smoke_params.color.r = chaos6_smoke_params.color.g =
                chaos6_smoke_params.color.b = work->scl.y;
            CreateSmoke2(&chaos6_smoke_params);
        }
        break;
    }
}
