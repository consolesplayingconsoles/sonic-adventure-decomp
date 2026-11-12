/* @unit 0CB96740-0CB96820 @data 0CB9A864-0CB9A87C +r04 +egflags +pool32 */
/* START MARK, SMALL SCREEN and ISLET, props that are only drawn */
#include <ninja.h>

#include "al_race/props.h"
#include "draw/model.h"
#include "object/placement.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/task_desc.h"
#include "system/texture.h"
#include "system/util.h"
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
void FUN_0cb96740(struct task *task);
void FUN_0cb9674a(struct task *task);
void FUN_0cb96754(struct task *task);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
void *syMalloc_default_malloc(size_t size);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
void SaveConstantAttr(void);
void LoadConstantAttr(void);
void OnConstantAttr(Uint32 and_attr, Uint32 or_attr);
void OffConstantAttr(Uint32 and_attr, Uint32 or_attr);
void SaveControl3D(void);
void LoadControl3D(void);
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* the start mark, small screen and islet */
#define PROP(task) ((NJS_MODEL **)(task)->motion)
extern NJS_OBJECT dat_0cbc517c;
extern NJS_OBJECT dat_0cbc7cdc;
extern NJS_OBJECT dat_0cbc7904;

/* a prop's state, in its task's motion: its model */

void prop_start(struct task *task, void *arg);
void prop_draw(struct task *task);

static const struct task_desc prop_desc = {
    sizeof(NJS_MODEL *), TASK_WORK, prop_start, prop_draw, prop_draw, NULL};
extern NJS_OBJECT *const start_mark_object;
extern NJS_OBJECT *const small_screen_object;
extern NJS_OBJECT *const islet_object;

void FUN_0cb96740(struct task *task)
{
    MirenInitTask(task, &prop_desc, (void *)&start_mark_object);
}

void FUN_0cb9674a(struct task *task)
{
    MirenInitTask(task, &prop_desc, (void *)&small_screen_object);
}

void FUN_0cb96754(struct task *task)
{
    MirenInitTask(task, &prop_desc, (void *)&islet_object);
}

void prop_start(struct task *task, void *arg)
{
    NJS_MODEL **model = PROP(task);

    *model = (*(NJS_OBJECT **)arg)->model;
}

void prop_draw(struct task *task)
{
    struct task_work *work;
    NJS_MODEL **model;
    struct angles *ang;
    Angle turn;

    if (loop_count == 0) {
        if (!CheckRange(task)) {
            work = task->work;
            model = PROP(task);
            /* @hack redundant: turn takes ang.x and then ang.z, unread,
             * which leaves the model's stack slot at @(4,R15) and ang's at
             * @R15 (0x0cb97ea8, 0x0cb97eb0); without them, the slots trade
             * places, and 6 of 56 words differ */
            turn = work->ang.x; /* NOLINT(clang-analyzer-deadcode.DeadStores) */
            turn = work->ang.z; /* NOLINT(clang-analyzer-deadcode.DeadStores) */
            ang = &work->ang;
            njPushMatrix(NULL);
            njTranslateV(NULL, &work->pos);
            TURN_VIA(njRotateY, ang->y, turn);
            SetObjectTexture();
            ds_DrawModelClip(*model);
            late_DrawObjectClipEx(1);
        }
    }
}
