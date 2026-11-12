/* @unit 0C90F060-0C90F2E0 +egflags +pool32 */
/* C APP ZERO and C KILL ZERO invisible boxes that cue and remove Zero */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "enemy/zero_handle.h"
#include "object/placement.h"
#include "stg10/zero_appear.h"
#include "stg10/zero_box.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
Bool OnEdit(struct task *task);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ERobCtrlInit(void);
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

#define CUE(work) ((work)->tick)
enum zero_box_mode { BOX_INIT, BOX_RUN };
extern struct collision_shape zero_box_shape;

/* draw a cube where the box's shape lies, for the set editor */
void zero_box_draw(struct task_work *work)
{
    Float x = work->scl.x * CUBE_FIT;
    Float y = work->scl.y * CUBE_FIT;
    Float z = work->scl.z * CUBE_FIT;

    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y + work->scl.y, work->pos.z);
    TURN(njRotateY, work->ang.y);
    njScale(NULL, x, y, z);
    SetMaterial(0.05F, 0.05F, 0.0F, 0.0F);
    late_DrawObject(marker_cube_object);
    late_DrawObjectClipEx(1);
}

void zero_appear_box_step(struct task *task)
{
    struct task_work *work = task->work;
    struct collision_shape *shape;

    if (edit_mode) {
        zero_box_draw(work);
        return;
    }
    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BOX_INIT:
        CUE(work) = work->ang.x;
        work->ang.x = 0;
        work->ang.z = 0;
        CCL_Init(task, &zero_box_shape, COLLISION_OBJECT, 1, 1);
        shape = work->collision->shapes;
        shape->center.y = work->scl.y;
        shape->radius = work->scl.x;
        shape->size_y = work->scl.y;
        shape->size_z = work->scl.z;
        work->mode = BOX_RUN;
        break;
    case BOX_RUN:
        if (work->collision->flags & COLLISION_HIT) {
            zero_appear_set(CUE(work));
            FreeTask(task);
            return;
        }
        break;
    }
    EntryColliList(work);
}

void zero_kill_box_step(struct task *task)
{
    struct task_work *work = task->work;
    struct collision_shape *shape;

    if (edit_mode) {
        zero_box_draw(work);
        return;
    }
    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BOX_INIT:
        CUE(work) = work->ang.x;
        work->ang.x = 0;
        work->ang.z = 0;
        CCL_Init(task, &zero_box_shape, COLLISION_OBJECT, 1, 1);
        shape = work->collision->shapes;
        shape->center.y = work->scl.y;
        shape->radius = work->scl.x;
        shape->size_y = work->scl.y;
        shape->size_z = work->scl.z;
        work->mode = BOX_RUN;
        break;
    case BOX_RUN:
        if (work->collision->flags & COLLISION_HIT) {
            zero_kill();
            FreeTask(task);
            return;
        }
        break;
    }
    EntryColliList(work);
}
