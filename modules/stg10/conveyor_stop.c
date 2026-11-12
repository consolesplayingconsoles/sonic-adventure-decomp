/* @unit 0C902AA0-0C902D00 +r04 +egflags +pool32 +poolafter=conveyor_stop_reset +asmfunc=FUN_0c902aa0:0c902b4a */
/* O CONV_STOP swinging bar over the conveyor belts that hurts players */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "debug/print.h"
#include "draw/draw.h"
#include "draw/pose.h"
#include "object/placement.h"
#include "stg10/conveyor_stop.h"
#include "system/frame.h"
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
Bool OnEdit(struct task *task);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
Bool GetMMMatrix(Uint32 node, NJS_MATRIX *out);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
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

#define RANGE (500.0F * 500.0F)
#define REACH 150.0F /* the collision record's radius */
#define FRAME_SPEED 0.4F /* the action's frames a step */
#define BAR_NODE 2 /* the bar's node in the action, counted from 0 */
#define VARS(work) ((struct stop_vars *)&(work)->vars)
extern NJS_ACTION conveyor_stop_action;

/* the stopper is destroyed beyond 500 units of the camera and player 0 */

struct stop_vars {
    Float frame;
};

enum stop_mode { STOP_INIT, STOP_RUN };

void conveyor_stop_init(struct task *task);
void conveyor_stop_reset(struct task *task);
void conveyor_stop_swing(struct task *task);
void conveyor_stop_draw(struct task *task);
void conveyor_stop_destroy(struct task *task);
extern struct collision_shape conveyor_stop_shape;
extern NJS_POINT3 conveyor_stop_bar_center;
extern NJS_MATRIX conveyor_stop_matrix;
void conveyor_stop_step(struct task *task);
#ifdef NON_MATCHING

void conveyor_stop_init(struct task *task)
{
    struct task_work *work = task->work;

    task->draw = conveyor_stop_draw;
    task->destructor = conveyor_stop_destroy;
    conveyor_stop_reset(task);
    work->mode = STOP_RUN;
}
#else
void conveyor_stop_init(struct task *task)
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

void conveyor_stop_reset(struct task *task)
{
    struct task_work *work = task->work;

    CCL_Init(task, &conveyor_stop_shape, COLLISION_OBJECT, 1, 1);
    work->collision->radius = REACH;
    VARS(work)->frame = 0.0F;
    work->collision->shapes->ang.y = work->ang.y;
}

/* advance the action, wrapping at its end, and put the bar's box where the
 * pose puts the bar */
void conveyor_stop_swing(struct task *task)
{
    struct task_work *work = task->work;
    NJS_ACTION *action;
    Angle ang;

    VARS(work)->frame += FRAME_SPEED;
    action = &conveyor_stop_action;
    if (VARS(work)->frame >= action->motion->nbFrame) {
        VARS(work)->frame -= action->motion->nbFrame;
    }
    njPushMatrix(&nj_unit_matrix_);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    CalcMMMatrix(NULL, &conveyor_stop_action, VARS(work)->frame, BAR_NODE,
                 &conveyor_stop_matrix);
    njCalcPoint(&conveyor_stop_matrix, &conveyor_stop_bar_center,
                &work->collision->shapes->center);
    late_DrawObjectClipEx(1);
    EntryColliList(work);
}

void conveyor_stop_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count == 0) {
        SetObjectTexture();
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
        ds_ActionClip(&conveyor_stop_action,
                      ((struct stop_vars *)&(work)->vars)->frame);
        late_DrawObjectClipEx(1);
    }
}

void conveyor_stop_destroy(struct task *task)
{
}
