/* @unit 0C906360-0C906460 +r04 +egflags +pool32 */
/* KuroKabe: the tables' black walls, whose alpha pulses. one wall is left out
 * while ShoogaiL is down, and another while ShoogaiR is */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "draw/model.h"
#include "stg09/black_wall.h"
#include "stg09/casino.h"
#include "stg09/pinball.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void FUN_0c906400(struct task *task);
int thunk_FUN_8c09cbc0(char *name, void *dest);
void SetGetRing(Uint8 count);

#define VARS(work) ((struct black_wall_vars *)&(work)->vars)
#define BLACK_WALL_PULSING 0x100
#define BLACK_WALL_PULSE 0x400 /* the phase's turn each step */
extern NJS_MODEL black_wall_model;
extern NJS_MODEL black_wall_a_model;
extern NJS_MODEL black_wall_b_model;

struct black_wall_vars {
    Uint8 unk_00[8];
    Angle phase; /* the alpha pulse's angle */
};

/* in work->flags. the step sets it, and the paused draw clears it. the
 * pulse moves on only while it is set */

void black_wall_destroy(struct task *task)
{
    FreeTaskC(task);
}

void black_wall_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (work->flags & BLACK_WALL_PULSING) {
        VARS(work)->phase += BLACK_WALL_PULSE;
    }
    SetMaterial((njSin(VARS(work)->phase) * (1.0F / 3.0F)) - 0.3F, 1.0F, 1.0F,
                1.0F);
    casino_set_texture(CASINO_TEXTURES_ACTS_34);
    if (!(PinballFlag & CASINO_SHOOGAI_L_DOWN)) {
        ds_DrawModelClip(&black_wall_a_model);
    }
    ds_DrawModelClip(&black_wall_model);
    if (!(PinballFlag & CASINO_SHOOGAI_R_DOWN)) {
        ds_DrawModelClip(&black_wall_b_model);
    }
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

void black_wall_draw_held(struct task *task)
{
    task->work->flags &= ~BLACK_WALL_PULSING;
    black_wall_draw(task);
}

void black_wall_run(struct task *task)
{
    task->work->flags |= BLACK_WALL_PULSING;
    black_wall_draw(task);
}

void FUN_0c906400(struct task *task)
{
    PinballFlag &= ~(CASINO_SHOOGAI_L_DOWN | CASINO_SHOOGAI_R_DOWN);
    task->step = black_wall_run;
    task->draw = black_wall_draw_held;
    task->destructor = black_wall_destroy;
}
