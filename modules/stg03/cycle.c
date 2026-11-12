/* @unit 0C908480-0C9085B8 +r04 +egflags +asmfunc=FUN_0c9084ec:0c908590 */
/* act 1's texture cycle, which steps four models' materials through a run
 * of textures */
#include <ninja.h>
#include <sg_xpt.h>

#include "stage/stage.h"
#include "stg03/cycle.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

#define CYCLE_FIRST 74
#define CYCLE_TEXTURES 14
#define CYCLE_MODELS 4
#define VARS(work) ((struct cycle_vars *)&(work)->vars)
extern NJS_OBJECT cycle_object_0;
extern NJS_OBJECT cycle_object_1;
extern NJS_OBJECT cycle_object_2;
extern NJS_OBJECT cycle_object_3;

/* the cycle steps through CYCLE_TEXTURES texture numbers from CYCLE_FIRST */

/* a model whose materials take the cycle's texture. twinkle_cycle_advance
 * reads first and delay from the first entry alone */
struct cycle_entry {
    NJS_OBJECT *object;
    Uint8 count; /* the entries of materials in use */
    Uint8 materials[3]; /* indices into the model's mats */
    Uint8 first; /* the cycle's first texture */
    Uint8 unk_09;
    Sint16 delay; /* the calls of twinkle_cycle_advance each texture lasts */
};

/* the cycle's work->vars. work->tick holds the texture shown, and
 * work->timer the calls of twinkle_cycle_advance since it changed */
struct cycle_vars {
    struct cycle_entry *entries;
    Sint8 count;
    Sint8 textures; /* the cycle's length */
};

enum cycle_mode { CYCLE_INIT, CYCLE_RUN, CYCLE_STILL };

void twinkle_cycle_advance(struct task *task);
void twinkle_cycle_destroy(struct task *task);
extern struct cycle_entry twinkle_cycles[4];

void twinkle_cycle_step(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_TWINKLE, 1)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = twinkle_cycle_destroy;
        task->draw = twinkle_cycle_advance;
        work->mode = CYCLE_RUN;
        work->tick = CYCLE_FIRST;
        VARS(work)->entries = twinkle_cycles;
        VARS(work)->count = CYCLE_MODELS;
        VARS(work)->textures = CYCLE_TEXTURES;
        break;
    case CYCLE_RUN:
        twinkle_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}
#ifdef NON_MATCHING

/* the task's draw, which its step calls too. once every entries[0].delay
 * calls, work->tick moves to the cycle's next texture. each call sets every
 * entry's materials to work->tick. as the draw, it runs while the game is
 * paused */
void twinkle_cycle_advance(struct task *task)
{
    struct task_work *work = task->work;
    struct cycle_entry *entries = VARS(work)->entries;
    struct cycle_entry *entry;
    NJS_OBJECT *object;
    Uint32 i;
    Uint32 j;

    work->timer++;
    if (work->timer == entries->delay) {
        work->tick++;
        if (work->tick >= VARS(work)->textures + entries->first) {
            work->tick = entries->first;
        }
        work->timer = 0;
    }
    for (i = 0; i < (Uint32)VARS(work)->count; i++) {
        entry = &entries[i];
        object = entry->object;
        for (j = 0; j < entry->count; j++) {
            object->model->mats[entry->materials[j]].attr_texId = work->tick;
        }
    }
}
#else
void twinkle_cycle_advance(struct task *task)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
}
#endif

void twinkle_cycle_destroy(struct task *task)
{
}
