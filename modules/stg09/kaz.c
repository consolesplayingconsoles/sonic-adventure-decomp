/* @unit 0C9114E0-0C911DE0 @data 0CB233F8-0CB23424 +egflags +pool32 */
/* O KAZB to O KAZG models that turn about z, and O KAZA, whose two parts move
 * apart and back on its action */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "draw/pose.h"
#include "object/placement.h"
#include "stg09/casino.h"
#include "stg09/helpers.h"
#include "stg09/kaz.h"
#include "system/frame.h"
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
Bool GetMMMatrix(Uint32 node, NJS_MATRIX *out);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
int thunk_FUN_8c09cbc0(char *name, void *dest);
void ObjCasino_DrawSphere(NJS_POINT3 *pos, Float radius);
void ObjCasino_InitTexUvInfo(struct uv_shift *rows, int count);
void ObjCasino_SetTexUvInfo(struct uv_shift *rows, int count);
void ObjCasino_ResetTexUvInfo(struct uv_shift *rows, int count);
void ObjCasino_EndTexUvInfo(struct uv_shift *rows, int count);
void FUN_0c9114e0(struct task *task);
void FUN_0c9114ea(struct task *task);
void FUN_0c9114f4(struct task *task);
void FUN_0c9114fe(struct task *task);
void FUN_0c911508(struct task *task);
void FUN_0c911512(struct task *task);
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

#define RANGE ((250.0F * 250.0F) + 10.0F)
#define KAZ_A_VIEW_RADIUS 98.0F
#define VARS(work) ((struct kaz_vars *)&(work)->vars)
extern NJS_OBJECT kaz_b_object;
extern NJS_OBJECT kaz_c_object;
extern NJS_OBJECT kaz_d_object;
extern NJS_OBJECT kaz_e_object;
extern NJS_OBJECT kaz_f_object;
extern NJS_OBJECT kaz_g_object;
/* O KAZA's model: the lower part, whose child is the upper */
extern NJS_OBJECT kaz_a_object;
extern NJS_ACTION kaz_a_action;

/* destroyed beyond about 250 units of the camera and player 0 */
/* the radius of the sphere about O KAZA that draw_in_view tests before O KAZA
 * draws */

struct kaz_vars {
    Uint16 angle; /* a turning model's, about its axis */
    Uint8 unk_02[2];
    NJS_MODEL *model; /* the turning model */
    Float frame; /* O KAZA's action's */
};
extern Angle kaz_turn;
extern Float kaz_scale;
extern Float kaz_a_frame_rate;
extern struct collision_shape kaz_b_shape;
extern struct collision_shape kaz_c_shape;
extern struct collision_shape kaz_d_shape;
extern struct collision_shape kaz_e_shape;
extern struct collision_shape kaz_f_shapes[3];
extern struct collision_shape kaz_g_shape;
extern struct collision_shape coll_0[4];

void kaz_start(struct task *task, NJS_MODEL *model,
               const struct collision_shape *shape, Sint8 axis);
void kaz_f_start(struct task *task, NJS_MODEL *model,
                 const struct collision_shape *shapes, Sint8 axis);

void FUN_0c9114e0(struct task *task)
{
    kaz_start(task, kaz_b_object.model, &kaz_b_shape, 0);
}

void FUN_0c9114ea(struct task *task)
{
    kaz_start(task, kaz_c_object.model, &kaz_c_shape, 0);
}

void FUN_0c9114f4(struct task *task)
{
    kaz_start(task, kaz_d_object.model, &kaz_d_shape, 0);
}

void FUN_0c9114fe(struct task *task)
{
    kaz_start(task, kaz_e_object.model, &kaz_e_shape, 0);
}

void FUN_0c911508(struct task *task)
{
    kaz_f_start(task, kaz_f_object.model, kaz_f_shapes, 0);
}

void FUN_0c911512(struct task *task)
{
    kaz_start(task, kaz_g_object.model, &kaz_g_shape, 0);
}

void kaz_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (CheckRangeOutWithR(task, RANGE) || loop_count) {
        return;
    }
    casino_set_texture(CASINO_TEXTURES_ACTS_12);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    if (work->submode) {
        TURN_VIA(njRotateX, VARS(work)->angle, ang);
    } else {
        TURN_VIA(njRotateZ, VARS(work)->angle, ang);
    }
    ds_DrawModelClip(VARS(work)->model);
    late_DrawObjectClipEx(1);
}

void kaz_run(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    Angle turn;
    Float factor;
    Float steps;
    Float scaled;
    Sint16 *low;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    casino_set_texture(CASINO_TEXTURES_ACTS_12);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    if (work->submode) {
        TURN_VIA(njRotateX, VARS(work)->angle, ang);
    } else {
        TURN_VIA(njRotateZ, VARS(work)->angle, ang);
    }
    ds_DrawModelClip(VARS(work)->model);
    late_DrawObjectClipEx(1);
    if (OnEdit(task)) {
        njPrintC(((18) << 16 | ((19))), ((Sint8)(int)(work)->scl.x & 1)
                                            ? "RotDir:Migi"
                                            : "RotDir:Hidari");
        njPrintC(((18) << 16 | ((20))), "RotSpd:");
        FUN_8c6409c0(((26) << 16 | ((20))), (int)njRoundOff(work->scl.y), 4);
        return;
    }
    EntryColliList(work);
    steps = TASK_TIMER(work);
    turn = kaz_turn;
    if (TURNS_RIGHT(work)) {
        factor = kaz_scale * njRoundOff(work->scl.y) * steps;
    } else {
        factor = -(kaz_scale * njRoundOff(work->scl.y) * steps);
    }
    /* scaled, kaz_turn times factor, can pass a Sint16's range. FTRC converts
     * it to an Angle, and only that Angle's low half is kept (0x0c91267a) */
    /* @hack type: turn scaled through a Sint16 pointer to its low half on
     * the stack, which the image loads at 0x0c912672 and stores at
     * 0x0c91267e; as union angle_halves, 56 of 157 words differ */
    low = (Sint16 *)&turn;
    scaled = *low;
    scaled *= factor;
    *low = (Angle)scaled;
    VARS(work)->angle = turn;
    work->timer++;
}

/* the model turns about x for a nonzero axis, and about z for 0 */
void kaz_start(struct task *task, NJS_MODEL *model,
               const struct collision_shape *shape, Sint8 axis)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        if (!OnEdit(task)) {
            CCL_Init(task, shape, COLLISION_OBJECT, 1, 1);
        }
        task->draw = kaz_draw;
        task->step = kaz_run;
        VARS(work)->model = model;
        work->submode = axis;
        VARS(work)->angle = 0;
        work->timer = 0;
    }
}

void kaz_f_run(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: a point nothing reads, which gives the image's 20-byte
     * stack frame (ADD #-20 at 0x0c91276a). without it, 2 of its 154 words
     * differ */
    NJS_POINT3 unused;
    Angle ang;
    Angle turn;
    Float factor;
    Float steps;
    Float scaled;
    Sint16 *low;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    kaz_draw(task);
    if (OnEdit(task)) {
        njPrintC(((18) << 16 | ((19))), ((Sint8)(int)(work)->scl.x & 1)
                                            ? "RotDir:Migi"
                                            : "RotDir:Hidari");
        njPrintC(((18) << 16 | ((20))), "RotSpd:");
        FUN_8c6409c0(((26) << 16 | ((20))), (int)njRoundOff(work->scl.y), 4);
        return;
    }
    EntryColliList(work);
    steps = TASK_TIMER(work);
    turn = kaz_turn;
    if (TURNS_RIGHT(work)) {
        factor = kaz_scale * njRoundOff(work->scl.y) * steps;
    } else {
        factor = -(kaz_scale * njRoundOff(work->scl.y) * steps);
    }
    /* @hack type: as in kaz_run, with the load at 0x0c912814, FTRC at
     * 0x0c91281c and the store at 0x0c912820; as union angle_halves, 95 of
     * 154 words differ */
    low = (Sint16 *)&turn;
    scaled = *low;
    scaled *= factor;
    *low = (Angle)scaled;
    VARS(work)->angle = turn;
    work->collision->shapes[1].ang.z = VARS(work)->angle;
    work->collision->shapes[2].ang.z = VARS(work)->angle;
    njPushMatrix(&nj_unit_matrix_);
    TURN_VIA(njRotateZ, VARS(work)->angle, ang);
    njCalcPoint(NULL, &kaz_f_shapes[1].center,
                &work->collision->shapes[1].center);
    njCalcPoint(NULL, &kaz_f_shapes[2].center,
                &work->collision->shapes[2].center);
    late_DrawObjectClipEx(1);
    work->timer++;
}

void kaz_f_start(struct task *task, NJS_MODEL *model,
                 const struct collision_shape *shapes, Sint8 axis)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        if (!OnEdit(task)) {
            CCL_Init(task, shapes, COLLISION_OBJECT, 1, 3);
        }
        task->draw = kaz_draw;
        task->step = kaz_f_run;
        VARS(work)->model = model;
        work->submode = axis;
        VARS(work)->angle = 0;
        work->timer = 0;
    }
}

/* pose the action at frame. set first to node 0's origin, and second to node
 * 1's, both in the model's space. node 0 is the lower part, and node 1 the
 * upper. returns TRUE, as pose_action always does */
Bool kaz_a_pose(Float frame, NJS_POINT3 *first, NJS_POINT3 *second)
{
    /* Ninja needs a matrix on an 8-byte boundary, and the stack is aligned
     * only to 4. matrix points at the boundary at or below shifted.matrix's
     * start. storage keeps that boundary, and a whole matrix after it, inside
     * the struct */
    struct {
        NJS_MATRIX *matrix;
        union {
            NJS_MATRIX matrix;
            struct {
                Float alignment;
                NJS_MATRIX matrix;
            } shifted;
        } storage;
    } aligned;
    union point_floats origin;
    Float *at;

    aligned.matrix =
        (NJS_MATRIX *)((Uint32)&aligned.storage.shifted.matrix & ~7);
    njPushMatrix(&nj_unit_matrix_);
    if (CalcMMMatrix(NULL, &kaz_a_action, frame, 0, aligned.matrix)) {
        /* @hack spelling: the array walked as (&origin)->elements, whose
         * address SHC forms from the stack pointer at each use (MOV R15,R4 at
         * 0x0c9129b0). as origin.elements, the address takes R13, and 73 of
         * kaz_a_pose's 79 words differ */
        at = (&origin)->elements;
        *at++ = 0.0F;
        *at++ = 0.0F;
        *at = 0.0F;
        njCalcPoint(aligned.matrix, &origin.point, first);
        njUnitMatrix(NULL);
        if (CalcMMMatrix(NULL, &kaz_a_action, frame, 1, aligned.matrix)) {
            /* the translation below moves the current matrix, which
             * njCalcPoint doesn't read. second is node 1's origin as posed */
            njTranslateV(NULL, (NJS_VECTOR *)kaz_a_object.child->pos);
            njCalcPoint(aligned.matrix, &origin.point, second);
        }
        late_DrawObjectClipEx(1);
        return TRUE;
    }
    late_DrawObjectClipEx(1);
    return FALSE;
}

void KazariADisp(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z,
                      KAZ_A_VIEW_RADIUS)) {
        return;
    }
    casino_set_texture(12);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    ds_ActionClip(&kaz_a_action, ((struct kaz_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

void kazariAExec(struct task *task)
{
    struct task_work *work = task->work;
    Float frames;
    /* @hack spelling: a copy of kaz_a_shapes' address, which SHC loads into
     * R4 (0x0c912bfa). read through kaz_a_shapes, the address takes R5, and 44
     * of kaz_a_run's 177 words differ */
    const struct collision_shape *shapes;
    NJS_POINT3 first;
    NJS_POINT3 second;
    /* @hack spelling: Float cursors over the three points of each center's sum,
     * which SHC loads with FMOV.S @Rm+ (0x0c912c06). as member sums, the
     * function runs 96 bytes longer, and 108 of its 177 words differ */
    Float *destination;
    const Float *source;
    const Float *offset;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    frames = kaz_a_action.motion->nbFrame;
    if (VARS(work)->frame < 0.0F) {
        VARS(work)->frame += frames;
    }
    if (VARS(work)->frame >= frames) {
        VARS(work)->frame -= frames;
    }
    KazariADisp(task);
    if (OnEdit(task)) {
        njPrintC(((18) << 16 | ((19))), "Frame:");
        FUN_8c6409c0(((26) << 16 | ((19))), (int)njRoundOff(work->scl.x), 10);
        return;
    }
    EntryColliList(work);
    if (!loop_count) {
        return;
    }
#ifdef GCC
    /* GCC can't see that kaz_a_pose sets both points: pose_action always
     * returns TRUE */
    first = second = (NJS_POINT3){0.0F, 0.0F, 0.0F};
#endif
    kaz_a_pose(VARS(work)->frame, &first, &second);
    shapes = coll_0;
    destination = VECTOR_FLOATS(&work->collision->shapes[0].center);
    source = VECTOR_FLOATS(&first);
    offset = VECTOR_FLOATS(&shapes[0].center);
    *destination++ = *source++ + *offset++;
    *destination++ = *source++ + *offset++;
    *destination = *source + *offset;
    destination = VECTOR_FLOATS(&work->collision->shapes[1].center);
    source = VECTOR_FLOATS(&second);
    offset = VECTOR_FLOATS(&shapes[1].center);
    *destination++ = *source++ + *offset++;
    *destination++ = *source++ + *offset++;
    *destination = *source + *offset;
    destination = VECTOR_FLOATS(&work->collision->shapes[2].center);
    source = VECTOR_FLOATS(&first);
    offset = VECTOR_FLOATS(&shapes[2].center);
    *destination++ = *source++ + *offset++;
    *destination++ = *source++ + *offset++;
    *destination = *source + *offset;
    destination = VECTOR_FLOATS(&work->collision->shapes[3].center);
    source = VECTOR_FLOATS(&second);
    offset = VECTOR_FLOATS(&shapes[3].center);
    /* @hack spelling: the fourth center's advances as statements of their own,
     * offset's as offset = offset + 1. SHC then gives the first center's
     * source, offset and destination R5, R6 and R7 (0x0c912bfc to
     * 0x0c912c0a). advanced in the sums, or with offset++, they take R6, R7
     * and R5, and 36 of its 177 words differ */
    *destination = *source + *offset;
    offset = offset + 1;
    source++;
    destination++;
    *destination = *source + *offset;
    offset = offset + 1;
    source++;
    destination++;
    *destination = *source + *offset;
    VARS(work)->frame += 2.0F * kaz_a_frame_rate;
}

void ObjectCasinoKazariA(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        if (!OnEdit(task)) {
            CCL_Init(task, coll_0, COLLISION_OBJECT, 1, 4);
        }
        task->draw = KazariADisp;
        task->step = kazariAExec;
        VARS(work)->frame = work->scl.x;
    }
}
