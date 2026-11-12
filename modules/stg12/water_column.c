/* @unit 0C90CB60-0C90CDA0 +r04 +egflags +pool32 */
/* the column of water that falls from a burst water tank, and splashes */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "stg12/texlists.h"
#include "stg12/water_column.h"
#include "system/frame.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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

/* @hack type: an array, not the single NJS_ACTION it is. SHC pools only the
 * action's address, and reads the motion through it at 0x0c90d068. as a
 * single object, SHC pools the motion field's address too, and 75 of the 200
 * words of water_column_step and water_column_draw differ */
#define START_HEIGHT 40.0F
#define START_SPEED 1.0F
#define DROP_ACCEL 0.8F
#define SPREAD_FRAME 10.0F
#define SPREAD_SPEED 0.04F
#define FADE_FRAME 20.0F
#define FADE_SPEED 0.1F
#define SHEETS 4
#define TEXTURES 5
#define TEXTURE_LAST_TICK 2
#define VARS(work) ((struct water_column_vars *)&(work)->vars)
extern NJS_ACTION water_column_action[];

/* the column starts START_HEIGHT above its position. it falls START_SPEED
 * the first step, and DROP_ACCEL faster each step after */

/* once the action's frame passes SPREAD_FRAME, the column widens by
 * SPREAD_SPEED each step. once it passes FADE_FRAME, its alpha falls by
 * FADE_SPEED each step */

/* the action's sheets, which all show the same texture */
/* the sheets show TEXTURES textures in turn. work->tick counts a texture's
 * steps up to TEXTURE_LAST_TICK, so each shows for three steps. only the
 * first texture's first showing lasts two */

enum water_column_mode { COLUMN_DROP, COLUMN_SPLASH };

/* work->scl.x scales the column's width. work->scl.z holds the change in
 * its height each step as it falls. work->tick counts its texture's steps,
 * and TASK_TIMER(work) holds the texture */
struct water_column_vars {
    Float frame; /* of water_column_action, which the draw shows */
    Float alpha; /* for draw_set_material, from 0 down */
    Float height; /* above work->pos */
};

void water_column_step(struct task *task);
void water_column_draw(struct task *task);

void water_column_start(struct task *task)
{
    struct task_work *work = task->work;

    work->tick = 0;
    TASK_TIMER(work) = 0;
    work->mode = COLUMN_DROP;
    work->scl.x = 1.0F;
    VARS(work)->frame = 0.0F;
    VARS(work)->alpha = 0.0F;
    VARS(work)->height = START_HEIGHT;
    work->scl.z = -START_SPEED;
    task->step = water_column_step;
    task->draw = water_column_draw;
}

void water_column_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *sheet;
    Float last;
    int i;

    switch (work->mode) {
    case COLUMN_DROP:
        VARS(work)->height += work->scl.z;
        work->scl.z -= DROP_ACCEL;
        if (VARS(work)->height <= 0.0F) {
            VARS(work)->height = 0.0F;
            work->mode = COLUMN_SPLASH;
        }
        break;
    case COLUMN_SPLASH:
        VARS(work)->frame += 1.0F;
        last = water_column_action->motion->nbFrame - 1;
        if (VARS(work)->frame >= last) {
            VARS(work)->frame -= last;
            FreeTask(task);
        }
        if (VARS(work)->frame > SPREAD_FRAME) {
            work->scl.x += SPREAD_SPEED;
        }
        if (VARS(work)->frame > FADE_FRAME) {
            VARS(work)->alpha -= FADE_SPEED;
        }
        break;
    }
    work->tick++;
    if (work->tick > TEXTURE_LAST_TICK) {
        work->tick = 0;
        TASK_TIMER(work)++;
        if (TASK_TIMER(work) >= TEXTURES) {
            TASK_TIMER(work) = 0;
        }
    }
    sheet = water_column_action->object;
    sheet = sheet->child;
    for (i = 0; i < SHEETS; i++) {
        sheet->model->mats[0].attr_texId = TASK_TIMER(work);
        sheet = sheet->sibling;
    }
    water_column_draw(task);
}

void water_column_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (loop_count == 0) {
        njSetTexture_jp(&shelter_column_texlist);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        njTranslate(((void *)0), 0.0F,
                    ((struct water_column_vars *)&(work)->vars)->height, 0.0F);
        njScale(((void *)0), work->scl.x, 1.0F, work->scl.x);
        SetMaterial(((struct water_column_vars *)&(work)->vars)->alpha, 0.0F,
                    0.0F, 0.0F);
        ds_ActionClip(water_column_action,
                      ((struct water_column_vars *)&(work)->vars)->frame);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
        late_DrawObjectClipEx(1);
    }
}
