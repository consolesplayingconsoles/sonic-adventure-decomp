/* @unit 0C904980-0C904E80 +r04 +egflags +pool32 */
/* Emerald Coast's texture cycles. each steps the materials of an act's
 * sand, waves or water through a run of textures */
#include <ninja.h>
#include <sg_xpt.h>

#include "stage/stage.h"
#include "stg01/cycle.h"
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
void FUN_0c904a8c(struct task *task);
void FUN_0c904c9a(struct task *task);
void FUN_0c904d06(struct task *task);

#define ACT0_SAND 67
#define ACT0_WAVE 82
#define ACT1_SAND 42
#define ACT1_WATER 57
#define ACT1_WAVE 71
#define ACT2_WAVE 50
#define ACT2_SAND 65
#define ACT2_WATER 80
#define SAND_TEXTURES 15
#define WAVE_TEXTURES 15
#define WATER_TEXTURES 12
#define VARS(work) ((struct cycle_vars *)&(work)->vars)
#define ENTRIES(cycles) (sizeof(cycles) / sizeof((cycles)[0]))
extern NJS_OBJECT beach_act0_sand_object_0;
extern NJS_OBJECT beach_act0_sand_object_1;
extern NJS_OBJECT beach_act0_sand_object_2;
extern NJS_OBJECT beach_act0_sand_object_3;
extern NJS_OBJECT beach_act0_sand_object_4;
extern NJS_OBJECT beach_act0_sand_object_5;
extern NJS_OBJECT beach_act0_sand_object_6;
extern NJS_OBJECT beach_act0_sand_object_7;
extern NJS_OBJECT beach_act0_sand_object_8;
extern NJS_OBJECT beach_act0_sand_object_9;
extern NJS_OBJECT beach_act0_sand_object_10;
extern NJS_OBJECT beach_act0_sand_object_11;
extern NJS_OBJECT beach_act0_wave_object_0;
extern NJS_OBJECT beach_act0_wave_object_1;
extern NJS_OBJECT beach_act0_wave_object_2;
extern NJS_OBJECT beach_act0_wave_object_3;
extern NJS_OBJECT beach_act0_wave_object_4;
extern NJS_OBJECT beach_act0_wave_object_5;
extern NJS_OBJECT beach_act0_wave_object_6;
extern NJS_OBJECT beach_act0_wave_object_7;
extern NJS_OBJECT beach_act0_wave_object_8;
extern NJS_OBJECT beach_act0_wave_object_9;
extern NJS_OBJECT beach_act0_wave_object_10;
extern NJS_OBJECT beach_act0_wave_object_11;
extern NJS_OBJECT beach_act0_wave_object_12;
extern NJS_OBJECT beach_act0_wave_object_13;
extern NJS_OBJECT beach_act0_wave_object_14;
extern NJS_OBJECT beach_act0_wave_object_15;
extern NJS_OBJECT beach_act0_wave_object_16;
extern NJS_OBJECT beach_act1_sand_object_0;
extern NJS_OBJECT beach_act1_sand_object_1;
extern NJS_OBJECT beach_act1_sand_object_2;
extern NJS_OBJECT beach_act1_sand_object_3;
extern NJS_OBJECT beach_act1_sand_object_4;
extern NJS_OBJECT beach_act1_sand_object_5;
extern NJS_OBJECT beach_act1_sand_object_6;
extern NJS_OBJECT beach_act1_sand_object_7;
extern NJS_OBJECT beach_act1_sand_object_8;
extern NJS_OBJECT beach_act1_sand_object_9;
extern NJS_OBJECT beach_act1_sand_object_10;
extern NJS_OBJECT beach_act1_sand_object_11;
extern NJS_OBJECT beach_act1_wave_object_0;
extern NJS_OBJECT beach_act1_wave_object_1;
extern NJS_OBJECT beach_act1_wave_object_2;
extern NJS_OBJECT beach_act1_wave_object_3;
extern NJS_OBJECT beach_act1_wave_object_4;
extern NJS_OBJECT beach_act1_wave_object_5;
extern NJS_OBJECT beach_act1_wave_object_6;
extern NJS_OBJECT beach_act1_wave_object_7;
extern NJS_OBJECT beach_act1_wave_object_8;
extern NJS_OBJECT beach_act1_wave_object_9;
extern NJS_OBJECT beach_act1_wave_object_10;
extern NJS_OBJECT beach_act1_wave_object_11;
extern NJS_OBJECT beach_act1_wave_object_12;
extern NJS_OBJECT beach_act1_wave_object_13;
extern NJS_OBJECT beach_act1_water_object_0;
extern NJS_OBJECT beach_act2_sand_object_0;
extern NJS_OBJECT beach_act2_sand_object_1;
extern NJS_OBJECT beach_act2_sand_object_2;
extern NJS_OBJECT beach_act2_sand_object_3;
extern NJS_OBJECT beach_act2_sand_object_4;
extern NJS_OBJECT beach_act2_sand_object_5;
extern NJS_OBJECT beach_act2_sand_object_6;
extern NJS_OBJECT beach_act2_sand_object_7;
extern NJS_OBJECT beach_act2_sand_object_8;
extern NJS_OBJECT beach_act2_sand_object_9;
extern NJS_OBJECT beach_act2_sand_object_10;
extern NJS_OBJECT beach_act2_sand_object_11;
extern NJS_OBJECT beach_act2_sand_object_12;
extern NJS_OBJECT beach_act2_sand_object_13;
extern NJS_OBJECT beach_act2_sand_object_14;
extern NJS_OBJECT beach_act2_sand_object_15;
extern NJS_OBJECT beach_act2_sand_object_16;
extern NJS_OBJECT beach_act2_sand_object_17;
extern NJS_OBJECT beach_act2_sand_object_18;
extern NJS_OBJECT beach_act2_sand_object_19;
extern NJS_OBJECT beach_act2_sand_object_20;
extern NJS_OBJECT beach_act2_sand_object_21;
extern NJS_OBJECT beach_act2_sand_object_22;
extern NJS_OBJECT beach_act2_sand_object_23;
extern NJS_OBJECT beach_act2_sand_object_24;
extern NJS_OBJECT beach_act2_sand_object_25;
extern NJS_OBJECT beach_act2_sand_object_26;
extern NJS_OBJECT beach_act2_sand_object_27;
extern NJS_OBJECT beach_act2_sand_object_28;
extern NJS_OBJECT beach_act2_wave_object_0;
extern NJS_OBJECT beach_act2_wave_object_1;
extern NJS_OBJECT beach_act2_wave_object_2;
extern NJS_OBJECT beach_act2_wave_object_3;
extern NJS_OBJECT beach_act2_wave_object_4;
extern NJS_OBJECT beach_act2_wave_object_5;
extern NJS_OBJECT beach_act2_wave_object_6;
extern NJS_OBJECT beach_act2_wave_object_7;
extern NJS_OBJECT beach_act2_wave_object_8;
extern NJS_OBJECT beach_act2_water_object_0;

/* each cycle's first texture, by its index in its act's land texlist:
 * m128_sand001, m128_wave001 or los_wt00 */

/* the textures in each cycle: m128_sand001 to m128_sand015, m128_wave001 to
 * m128_wave015, and los_wt00 to los_wt11 */

/* a model whose materials take the cycle's texture. beach_cycle_advance
 * reads first and delay from the first entry alone */
struct cycle_entry {
    NJS_OBJECT *object;
    Uint8 count; /* how many of materials are in use */
    Uint8 materials[3]; /* indices into the model's mats */
    Uint8 first; /* the cycle's first texture */
    Uint8 unk_09;
    Sint16 delay; /* the calls of beach_cycle_advance each texture lasts */
};

/* the cycle's work->vars. work->tick holds the texture shown, and
 * work->timer the calls of beach_cycle_advance since it changed. the wave
 * tasks also set work->scl.z to 1, which no code here reads */
struct cycle_vars {
    struct cycle_entry *entries;
    Sint8 count;
    Sint8 textures; /* the cycle's length */
};

/* the count of a cycle table's entries */

enum cycle_mode { CYCLE_INIT, CYCLE_RUN, CYCLE_STILL };

void beach_cycle_advance(struct task *task);
void beach_cycle_destroy(struct task *task);
extern struct cycle_entry beach_act0_sand_cycles[12];
extern struct cycle_entry beach_act0_wave_cycles[17];
extern struct cycle_entry beach_act1_sand_cycles[12];
extern struct cycle_entry beach_act1_wave_cycles[14];
extern struct cycle_entry beach_act1_water_cycles[1];
extern struct cycle_entry beach_act2_sand_cycles[30];
extern struct cycle_entry beach_act2_wave_cycles[9];
extern struct cycle_entry beach_act2_water_cycles[1];

void beach_act0_sand_step(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_BEACH, 0)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = beach_cycle_destroy;
        task->draw = beach_cycle_advance;
        work->mode = CYCLE_RUN;
        work->tick = ACT0_SAND;
        VARS(work)->entries = beach_act0_sand_cycles;
        VARS(work)->count = ENTRIES(beach_act0_sand_cycles);
        VARS(work)->textures = SAND_TEXTURES;
        break;
    case CYCLE_RUN:
        beach_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}

void beach_act0_wave_step(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_BEACH, 0)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = beach_cycle_destroy;
        task->draw = beach_cycle_advance;
        work->mode = CYCLE_RUN;
        work->tick = ACT0_WAVE;
        VARS(work)->entries = beach_act0_wave_cycles;
        VARS(work)->count = ENTRIES(beach_act0_wave_cycles);
        VARS(work)->textures = WAVE_TEXTURES;
        work->scl.z = 1.0F;
        break;
    case CYCLE_RUN:
        beach_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}

void FUN_0c904a8c(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_BEACH, 1)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = beach_cycle_destroy;
        task->draw = beach_cycle_advance;
        work->mode = CYCLE_RUN;
        /* los_wt04, the water's fifth texture. past the water cycle's twelve,
         * act 1's texlist holds los_wt12 and los_wt13, at 69 and 70. the tick
         * counts up through them into the waves' own textures, and cycles
         * there */
        work->tick = ACT1_WATER + 4;
        VARS(work)->entries = beach_act1_wave_cycles;
        VARS(work)->count = ENTRIES(beach_act1_wave_cycles);
        VARS(work)->textures = WAVE_TEXTURES;
        work->scl.z = 1.0F;
        break;
    case CYCLE_RUN:
        beach_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}

void beach_act1_sand_step(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_BEACH, 1)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = beach_cycle_destroy;
        task->draw = beach_cycle_advance;
        work->mode = CYCLE_RUN;
        /* the waves' first texture, past the sand's last. the first advance
         * wraps the tick to the sand's first */
        work->tick = ACT1_WAVE;
        VARS(work)->entries = beach_act1_sand_cycles;
        VARS(work)->count = ENTRIES(beach_act1_sand_cycles);
        VARS(work)->textures = SAND_TEXTURES;
        break;
    case CYCLE_RUN:
        beach_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}

void beach_act1_water_step(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_BEACH, 1)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = beach_cycle_destroy;
        task->draw = beach_cycle_advance;
        work->mode = CYCLE_RUN;
        /* the sand's first texture. the tick counts up through the sand's
         * textures into the water's own, and cycles there */
        work->tick = ACT1_SAND;
        VARS(work)->entries = beach_act1_water_cycles;
        VARS(work)->count = ENTRIES(beach_act1_water_cycles);
        VARS(work)->textures = WATER_TEXTURES;
        break;
    case CYCLE_RUN:
        beach_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}

void beach_act2_wave_step(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_BEACH, 2)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = beach_cycle_destroy;
        task->draw = beach_cycle_advance;
        work->mode = CYCLE_RUN;
        work->tick = ACT2_WAVE + WAVE_TEXTURES - 1;
        VARS(work)->entries = beach_act2_wave_cycles;
        VARS(work)->count = ENTRIES(beach_act2_wave_cycles);
        VARS(work)->textures = WAVE_TEXTURES;
        work->scl.z = 1.0F;
        break;
    case CYCLE_RUN:
        beach_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}

void FUN_0c904c9a(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_BEACH, 2)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = beach_cycle_destroy;
        task->draw = beach_cycle_advance;
        work->mode = CYCLE_RUN;
        work->tick = ACT2_SAND + SAND_TEXTURES - 1;
        VARS(work)->entries = beach_act2_sand_cycles;
        VARS(work)->count = ENTRIES(beach_act2_sand_cycles);
        VARS(work)->textures = SAND_TEXTURES;
        break;
    case CYCLE_RUN:
        beach_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}

void FUN_0c904d06(struct task *task)
{
    struct task_work *work = task->work;
    int stage_act = GetStageNumber();

    if (stage_act != STAGE_ACT(STAGE_BEACH, 2)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case CYCLE_INIT:
        task->destructor = beach_cycle_destroy;
        task->draw = beach_cycle_advance;
        work->mode = CYCLE_RUN;
        work->tick = ACT2_WATER;
        VARS(work)->entries = beach_act2_water_cycles;
        VARS(work)->count = ENTRIES(beach_act2_water_cycles);
        VARS(work)->textures = WATER_TEXTURES;
        break;
    case CYCLE_RUN:
        beach_cycle_advance(task);
        return;
    case CYCLE_STILL:
        break;
    default:
        work->mode = CYCLE_INIT;
    }
}

/* the task's draw, which its step calls too. once every entries[0].delay
 * calls, work->tick moves to the cycle's next texture. each call sets every
 * entry's materials to work->tick. as the draw, it runs while the game is
 * paused */
void beach_cycle_advance(struct task *task)
{
    struct task_work *work;
    /* @hack spelling: work assigned inside the entries' initializer, which
     * loads the entries (MOV.L @(8,R5),R13 at 0x0c9050d0) ahead of the timer's
     * increment; initialized in its own declaration, 23 of 74 words differ */
    struct cycle_entry *entries = VARS(work = task->work)->entries;
    struct cycle_entry *entry;
    NJS_OBJECT *object;
    int i;
    int j;

    if (ChkPause()) {
        return;
    }
    work->timer++;
    if (work->timer == entries->delay) {
        work->tick++;
        if (work->tick >= VARS(work)->textures + entries->first) {
            work->tick = entries->first;
        }
        work->timer = 0;
    }
    for (i = 0; i < VARS(work)->count; i++) {
        entry = &entries[i];
        object = entry->object;
        for (j = 0; j < entry->count; j++) {
            object->model->mats[entry->materials[j]].attr_texId = work->tick;
        }
    }
}

void beach_cycle_destroy(struct task *task)
{
}
