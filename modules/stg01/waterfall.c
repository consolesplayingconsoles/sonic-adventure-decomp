/* @unit 0C9070C0-0C907300 @data 0C910BE0-0C910BEC +r04 +egflags +pool32 */
/* O TAKI waterfall whose texture slides down it */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "stg01/waterfall.h"
#include "system/task.h"
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
void FUN_8c6409c0(Int loc, Int val, Int digit);
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
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

#define FALL_MESHSETS 3
#define FALL_UVS 50
#define RANGE (1200.0F * 1200.0F)
extern NJS_OBJECT beach_waterfall_object;
extern Sint8 beach_waterfall_speed;

void beach_waterfall_start(struct task *task);
void Object_beach_taki_End(struct task *task);
void Object_beach_taki_Exec(struct task *task);
void Object_beach_taki_Draw(struct task *task);

void Object_beach_taki(struct task *task)
{
    /* @hack redundant: work, set and never read, which keeps task in R14
     * across the range check (MOV R4,R14 at 0x0c907428). without it, 12 of 16
     * words differ and the three functions after it move */
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        beach_waterfall_start(task);
    }
}

void beach_waterfall_start(struct task *task)
{
    struct task_work *work = task->work;

    task->draw = Object_beach_taki_Draw;
    task->step = Object_beach_taki_Exec;
    task->destructor = Object_beach_taki_End;
    work->timer = 0;
}

void Object_beach_taki_End(struct task *task)
{
}

void Object_beach_taki_Exec(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        if (OnEdit(task)) {
            njPrintC(((18) << 16 | ((16))), "TakiSpeed:");
            FUN_8c6409c0(((32) << 16 | (16)),
                         (Uint8)(work->ang.x + beach_waterfall_speed), 3);
        }
        Object_beach_taki_Draw(task);
        work->timer++;
    }
}

/* draw the model with a copy of each meshset's uvs, slid along v. then give
 * each meshset its own uvs back */
void Object_beach_taki_Draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = &beach_waterfall_object;
    Uint32 slide = (Uint8)(work->timer * (work->ang.x + beach_waterfall_speed));
    NJS_MESHSET *meshset;
    NJS_COLOR uvs[FALL_MESHSETS * FALL_UVS];
    NJS_COLOR *own[FALL_MESHSETS];
    NJS_COLOR *from;
    NJS_COLOR *to;
    int i;
    int j;
    Angle ang;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njScale(NULL, work->scl.x + 1.0F, work->scl.y + 1.0F, work->scl.z + 1.0F);
    meshset = object->model->meshsets;
    for (i = 0; i < FALL_MESHSETS; ++i, ++meshset) {
        /* @hack spelling: down, slide copied into an int, which keeps slide in
         * R8 (EXTU.B R8,R8 at 0x0c90752c). the store keeps the same low 16
         * bits either way: as from->tex.v - slide, 30 of 136 words differ */
        int down = slide;

        j = FALL_UVS;
        from = meshset->vertuv;
        to = &uvs[i * FALL_UVS];
        own[i] = from;
        meshset->vertuv = to;
        while (j--) {
            to->tex.u = from->tex.u;
            to->tex.v = from->tex.v - down;
            ++from;
            ++to;
        }
    }
    ds_DrawModelClip(object->model);
    meshset = object->model->meshsets;
    for (i = 0; i < FALL_MESHSETS; ++i, ++meshset) {
        meshset->vertuv = own[i];
    }
    late_DrawObjectClipEx(1);
}
