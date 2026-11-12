/* @unit 0C9047E0-0C904940 +egflags +pool32 */
/* o_komokosu, a cobweb in Red Mountain's caves, scaled by its set entry */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "stg05/cobweb.h"
#include "system/task.h"
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
void ds_DrawModelClip(NJS_MODEL *model);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define VARS(work) ((struct cobweb_vars *)&(work)->vars)
extern NJS_TEXLIST texlist_obj_mountain;
extern NJS_OBJECT cobweb_object;

/* the step sets object and texlist, but the draw takes cobweb_object and
 * obj_mountain_texlist itself */
struct cobweb_vars {
    Uint8 unk_00[4];
    NJS_OBJECT *object;
    NJS_TEXLIST *texlist;
};

enum cobweb_mode { COBWEB_INIT, COBWEB_SHOWN };

void cobweb_draw(struct task *task);
void cobweb_destroy(struct task *task);

void cobweb_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (OnEdit(task)) {
        VARS(work)->object = &cobweb_object;
        VARS(work)->texlist = &texlist_obj_mountain;
    } else {
        switch (work->mode) {
        case COBWEB_INIT:
            work->mode = COBWEB_SHOWN;
            VARS(work)->object = &cobweb_object;
            VARS(work)->texlist = &texlist_obj_mountain;
            task->draw = cobweb_draw;
            task->destructor = cobweb_destroy;
            break;
        case COBWEB_SHOWN:
            cobweb_draw(task);
            break;
        }
    }
}

void cobweb_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = &cobweb_object;
    Angle ang;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 100.0F)) {
        njSetTexture_jp(&texlist_obj_mountain);
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateZ, work->ang.z, ang);
        TURN_VIA(njRotateX, work->ang.x, ang);
        TURN_VIA(njRotateY, work->ang.y, ang);
        njScale(NULL, work->scl.x, work->scl.y, work->scl.z);
        ds_DrawModelClip(object->model);
        late_DrawObjectClipEx(1);
    }
}

void cobweb_destroy(struct task *task)
{
}
