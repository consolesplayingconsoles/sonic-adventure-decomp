/* @unit 0C9027C0-0C9028E0 @data 0CB32728-0CB3273C +egflags +pool32 */
/* O KARTKANBAN Twinkle Circuit sign, whose lights cycle through three
 * textures */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv00/kart_sign.h"
#include "adv00/station_square.h"
#include "adv00/texlists.h"
#include "draw/tree.h"
#include "object/placement.h"
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define LIGHTS_MATERIAL 2 /* the model's material that shows the lights */
#define TEXTURE(work) ((work)->submode) /* the texture the lights show */
#define LIGHTS_FIRST 4
#define LIGHTS_LAST 6
#define LIGHTS_DELAY 2
extern NJS_OBJECT kart_sign_object;

/* the lights show ss_twins_texlist's textures from LIGHTS_FIRST to
 * LIGHTS_LAST, in turn */
/* the texture changes once tick passes this, every third step */

void kart_sign_step(struct task *task);
void kart_sign_draw(struct task *task);
void kart_sign_destroy(struct task *task);

void kart_sign_init(struct task *task)
{
    struct task_work *work = task->work;
    Uint16 stage_act = GetStageNumber();

    if ((Uint8)stage_act != STATION_SQUARE_TWINKLE) {
        njPrintC(NJM_LOCATION(10, 8), "ACT TWINKLE ONLY !");
        return;
    }
    work->ang.x = 0;
    work->ang.y = 0;
    work->ang.z = 0;
    work->mode = 0;
    work->tick = 0;
    TEXTURE(work) = LIGHTS_FIRST;
    task->step = kart_sign_step;
    task->draw = kart_sign_draw;
    task->destructor = kart_sign_destroy;
}

void kart_sign_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    work->tick++;
    if (work->tick > LIGHTS_DELAY) {
        work->tick = 0;
        TEXTURE(work)++;
        if (TEXTURE(work) > LIGHTS_LAST) {
            TEXTURE(work) = LIGHTS_FIRST;
        }
    }
    /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
    kart_sign_object.model->mats[LIGHTS_MATERIAL].attr_texId = TEXTURE(work);
    kart_sign_draw(task);
}

void kart_sign_draw(struct task *task)
{
    struct task_work *work = task->work;

    njSetTexture_jp(&ss_twins_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    late_DrawObject(&kart_sign_object);
    late_DrawObjectClipEx(1);
}

void kart_sign_destroy(struct task *task)
{
}
