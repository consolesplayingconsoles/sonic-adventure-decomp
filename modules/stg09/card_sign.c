/* @unit 0C917320-0C9175E0 @data 0CB2349C-0CB234C8 +egflags +pool32 */
/* O CARDKAN: a card sign whose middle and upper parts turn, and whose faces
 * change in phases */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "stg09/card_sign.h"
#include "stg09/casino.h"
#include "stg09/helpers.h"
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
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
int thunk_FUN_8c09cbc0(char *name, void *dest);
void ObjCasino_DrawSphere(NJS_POINT3 *pos, Float radius);
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

/* the sign's base, whose child is the middle part. the middle part's sibling
 * is the upper part */
#define RANGE ((600.0F * 600.0F) + 10.0F)
#define CARD_SIGN_FACES 3 /* the meshsets whose UVs a phase shifts */
#define CARD_SIGN_PHASES 3
#define UPPER_START NJM_DEG_ANG(-17.5)
#define VARS(work) ((struct card_sign_vars *)&(work)->vars)
#define PHASE(work) ((work)->submode)
extern NJS_OBJECT card_sign_object;
extern NJS_MESHSET card_sign_base_meshsets[6];
extern NJS_MESHSET card_sign_middle_meshset;
extern NJS_MESHSET card_sign_upper_meshset;

/* the task destroys itself beyond about 600 of the camera and player 0.
 * placement_try_leave_by takes the range squared */

/* the phases after phase 0, which shows the meshsets' own UVs */

/* the upper part's turn about y as the sign starts */

struct card_sign_vars {
    Uint16 middle; /* the middle part's turn about y */
    Uint16 upper; /* the upper part's turn about y */
};
extern struct uv_shift card_sign_faces[3 * 3];
extern struct collision_shape card_sign_shapes[2];

void card_sign_destroy(struct task *task);
void card_sign_draw(struct task *task);
void card_sign_run(struct task *task);

void card_sign_step(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        task->draw = card_sign_draw;
        task->step = card_sign_run;
        task->destructor = card_sign_destroy;
        if (!OnEdit(task)) {
            CCL_Init(task, card_sign_shapes, COLLISION_OBJECT, 1, 2);
        }
        VARS(work)->middle = 0;
        VARS(work)->upper = UPPER_START;
        work->timer = 0;
        PHASE(work) = 0;
        ObjCasino_InitTexUvInfo(card_sign_faces,
                                CARD_SIGN_PHASES * CARD_SIGN_FACES);
    }
}

void card_sign_destroy(struct task *task)
{
    ObjCasino_EndTexUvInfo(card_sign_faces, CARD_SIGN_PHASES * CARD_SIGN_FACES);
}

void card_sign_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;
    Angle ang;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (PHASE(work) != 0) {
        ObjCasino_SetTexUvInfo(
            &card_sign_faces[(PHASE(work) - 1) * CARD_SIGN_FACES],
            CARD_SIGN_FACES);
    }
    casino_set_texture(CASINO_TEXTURES_ACTS_12);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    object = &card_sign_object;
    ds_DrawModelClip(object->model);
    object = object->child;
    njPushMatrix(NULL);
    TURN_VIA(njRotateY, VARS(work)->middle, ang);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    object = object->sibling;
    njPushMatrix(NULL);
    TURN_VIA(njRotateY, VARS(work)->upper, ang);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
    if (PHASE(work) != 0) {
        ObjCasino_ResetTexUvInfo(card_sign_faces,
                                 CARD_SIGN_PHASES * CARD_SIGN_FACES);
    }
}

void card_sign_run(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    card_sign_draw(task);
    VARS(work)->upper += (Angle)(work->scl.x * ANGLE_PER_DEGREE);
    VARS(work)->middle += (Angle)(work->scl.y * ANGLE_PER_DEGREE);
    if (TASK_TIMER(work)++ > (Sint16)work->scl.z) {
        ++PHASE(work);
        if (PHASE(work) > CARD_SIGN_PHASES) {
            PHASE(work) = 0;
        }
        work->timer = 0;
    }
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_X), "-> RotHiSpd ");
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Y), "-> RotMidSpd ");
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Z), "-> UV Pitch");
        return;
    }
    work->collision->shapes[1].ang.x = VARS(work)->upper + NJM_DEG_ANG(90);
    EntryColliList(work);
}
