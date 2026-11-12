/* @unit 0C902AA0-0C902CA0 @data 0C910AE4-0C910AFC @ddata 0CAAFB84-0CAAFBE8 +r04 +egflags +pool32 */
/* the spray O DOLPHIN throws up: drops that fall and shrink as they fly */
#define TEXT_1 "am_sea124_8"
#include <ninja.h>
#include <sg_xpt.h>

#include "effect/dust.h"
#include "effect/snow.h"
#include "stg01/spray.h"
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
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
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

#define TEXT_1_LENGTH 11
#define SPRAY_STEPS 60
#define SPRAY_FALL 0.04F
#define MIST_WAIT 5
enum spray_mode { SPRAY_INIT, SPRAY_FLY, SPRAY_END };

/* a drop flies SPRAY_STEPS + 1 steps. each step it rises SPRAY_FALL less than
 * the step before, and loses SPRAY_FALL more of its size */

/* a drop with scl.z below 0 leaves a mist puff each time work->tick passes
 * MIST_WAIT: every sixth step */

/* the drops' texture, and their sprite's one frame, which spans all of it */
static NJS_TEXNAME beach_spray_texnames[1] = {{TEXT_1, 0, 0}};
NJS_TEXLIST beach_spray_texlist = {beach_spray_texnames, 1};
static NJS_TEXANIM beach_spray_frame[1] = {{8, 8, 4, 4, 0, 0, 255, 255, 0, 0}};

/* the params of the mist puffs the drops leave. beach_spray_draw sets pos and
 * scale before each puff */
static struct dust_params beach_spray_mist = {0.78F,
                                              0.01F,
                                              1.0F,
                                              0.06F,
                                              -0.02F,
                                              {0.0F, 0.0F, 0.0F},
                                              {0.0F, 0.0F, 0.0F},
                                              {0.7F, 1.0F, 1.0F, 1.0F}};
extern NJS_SPRITE beach_spray_sprite;

void DrawDropSprite(struct task_work *work);
void FUN_0c902b6e(struct task *task);

void EffectBeachDrop(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case SPRAY_INIT:
        beach_spray_sprite.tlist = &beach_spray_texlist;
        beach_spray_sprite.tanim = beach_spray_frame;
        beach_spray_sprite.sx = 0.07F;
        beach_spray_sprite.sy = 0.07F;
        beach_spray_sprite.p.x = 0.0F;
        beach_spray_sprite.p.y = 0.0F;
        beach_spray_sprite.p.z = 0.0F;
        work->mode = SPRAY_FLY;
        task->draw = FUN_0c902b6e;
        break;
    case SPRAY_FLY:
        work->tick++;
        work->pos.x += SPRAY_VARS(work)->speed_x;
        work->pos.y +=
            SPRAY_VARS(work)->speed_y - (TASK_TIMER(work) * SPRAY_FALL);
        work->pos.z += SPRAY_VARS(work)->speed_z;
        work->scl.x -= TASK_TIMER(work) * SPRAY_FALL;
        if (work->scl.x < 0.0F) {
            work->scl.x = 0.0F;
        }
        DrawDropSprite(work);
        TASK_TIMER(work)++;
        if (TASK_TIMER(work) > SPRAY_STEPS) {
            work->mode = SPRAY_END;
        }
        break;
    case SPRAY_END:
        FreeTask(task);
        break;
    }
}
void FUN_0c902b6e(struct task *task)
{
    struct task_work *work = task->work;
    DrawDropSprite(work);
}

/* draw the drop at its size, and leave its mist */
void DrawDropSprite(struct task_work *work)
{
    extern int loop_count;
    Float size;

    if (loop_count != 0) {
        return;
    }
    njSetTexture_jp(&beach_spray_texlist);
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    size = work->scl.x + 1.7F;
    njScale(NULL, size, size, size);
    njDrawSprite3D(&beach_spray_sprite, 0,
                   NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE | NJD_SPRITE_ANGLE);
    late_DrawObjectClipEx(1);
    if (work->scl.z < 0.0F) {
        if (work->tick > MIST_WAIT) {
            /* @hack redundant: down, which the image copies from its constants
             * (0x0c902d4e to 0x0c902d5e) and never reads. without it, 85 of 87
             * words differ and the constants are 12 bytes fewer */
            NJS_VECTOR down = {0.0F, -1.0F, 0.0F};

            beach_spray_mist.pos.x = work->pos.x;
            beach_spray_mist.pos.y = work->pos.y;
            beach_spray_mist.pos.z = work->pos.z;
            beach_spray_mist.scale = -work->scl.z * 0.02F;
            snow_create_from(&beach_spray_mist);
            work->tick = 0;
        }
    }
}
