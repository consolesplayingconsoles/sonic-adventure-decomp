/* @unit 0C9224A0-0C9226A0 @data 0CB237EC-0CB237F8 +r04 +egflags +pool32 */
/* O SLB, O SLG, O SLR and O SLY lamps, which play their actions in a loop.
 * the four are blue, green, red and yellow */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "object/placement.h"
#include "stg09/casino.h"
#include "stg09/lamp.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
int thunk_FUN_8c09cbc0(char *name, void *dest);
void FUN_0c9225f8(struct task *task);
void FUN_0c922660(struct task *task);
void FUN_0c922666(struct task *task);
void FUN_0c92266c(struct task *task);
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

#define RANGE ((800.0F * 800.0F) + 10.0F)
#define VIEW_RADIUS 220.0F
#define VARS(work) ((struct lamp_vars *)&(work)->vars)
#define FRAME_RATE(work) ((work)->scl.y) /* added to frame each step */
extern NJS_ACTION lamp_blue_action;
extern NJS_ACTION lamp_green_action;
extern NJS_ACTION lamp_red_action;
extern NJS_ACTION lamp_yellow_action;

/* destroyed beyond about 800 units of the camera and player 0 */
/* the radius of the sphere about a lamp that draw_in_view tests */

struct lamp_vars {
    Float frame; /* the action's, back to 0 at its motion's last */
    NJS_ACTION *action;
};
extern struct collision_shape lamp_shape;

void DispMot3(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, VIEW_RADIUS)) {
        return;
    }
    casino_set_texture(12);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    (((ang) = (work->ang.z)) ? (njRotateZ)(((void *)0), (ang)) : (void)0);
    (((ang) = (work->ang.x)) ? (njRotateX)(((void *)0), (ang)) : (void)0);
    (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
    ds_ActionClip(((struct lamp_vars *)&(work)->vars)->action,
                  ((struct lamp_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

void ExecCM(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (VARS(work)->frame >= VARS(work)->action->motion->nbFrame - 1) {
        VARS(work)->frame = 0.0F;
    }
    DispMot3(task);
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Y), "Mot Pitch");
        return;
    }
    EntryColliList(work);
    VARS(work)->frame += FRAME_RATE(work);
}

void lamp_init(struct task *task, NJS_ACTION *action)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (!OnEdit(task)) {
        CCL_Init(task, &lamp_shape, COLLISION_OBJECT, 1, 1);
    }
    task->draw = DispMot3;
    task->step = ExecCM;
    VARS(work)->frame = 0.0F;
    VARS(work)->action = action;
}

void FUN_0c9225f8(struct task *task)
{
    lamp_init(task, &lamp_blue_action);
}

void FUN_0c922660(struct task *task)
{
    lamp_init(task, &lamp_green_action);
}

void FUN_0c922666(struct task *task)
{
    lamp_init(task, &lamp_red_action);
}

void FUN_0c92266c(struct task *task)
{
    lamp_init(task, &lamp_yellow_action);
}
