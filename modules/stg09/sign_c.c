/* @unit 0C921AA0-0C921D20 @data 0CB2379C-0CB237B8 +egflags +pool32 */
/* O KBC, a sign of card suits that runs its motion while its lamps step
 * through their faces */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "object/placement.h"
#include "stg09/casino.h"
#include "stg09/helpers.h"
#include "stg09/sign.h"
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

#define RANGE 360010.0F
#define FACES 3
#define LAMP_MESHSETS 2
#define VARS(work) ((struct sign_c_vars *)&(work)->vars)
#define FACE(work) ((work)->submode)
#define FRAME_SPEED(work) ((work)->scl.y)
#define FACE_WAIT(work) ((Sint16)(work)->scl.z)
extern NJS_ACTION sign_c_action;
extern NJS_MESHSET sign_c_meshsets[4];

/* placement_try_leave_by's squared range: about 600 from the camera or
 * player 0 */

/* the lamps' faces besides their own. each face shifts the UVs of
 * LAMP_MESHSETS meshsets */

struct sign_c_vars {
    Uint8 unk_00[8];
    Float frame; /* the frame of sign_c_action's motion */
};
extern struct uv_shift sign_c_lamps[3 * 2];
extern struct collision_shape sign_c_posts[2];

void sign_c_destroy(struct task *task);
void sign_c_draw(struct task *task);
void sign_c_run(struct task *task);

void sign_c_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    task->draw = sign_c_draw;
    task->step = sign_c_run;
    task->destructor = sign_c_destroy;
    work->timer = 0;
    VARS(work)->frame = 0.0F;
    FACE(work) = 0;
    ObjCasino_InitTexUvInfo(sign_c_lamps, FACES * LAMP_MESHSETS);
    if (!OnEdit(task)) {
        work->ang.x = 0;
        work->ang.z = 0;
        CCL_Init(task, sign_c_posts, COLLISION_OBJECT, 1, 2);
    }
}

void sign_c_destroy(struct task *task)
{
    ObjCasino_EndTexUvInfo(sign_c_lamps, FACES * LAMP_MESHSETS);
}

void sign_c_draw(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: room for 150 UVs nothing uses, which makes the frame 604
     * bytes (MOV.W and ADD R0,R15 at 0x0c923524). without it, the code is 64
     * bytes short and 80 of 82 words differ */
    NJS_TEX room[150];
    Angle ang;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 40.0F)) {
        return;
    }
    if (FACE(work) != 0) {
        ObjCasino_SetTexUvInfo(&sign_c_lamps[(FACE(work) - 1) * LAMP_MESHSETS],
                               LAMP_MESHSETS);
    }
    casino_set_texture(12);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
    ds_ActionClip(&sign_c_action, ((struct sign_c_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
    if (FACE(work) != 0) {
        ObjCasino_ResetTexUvInfo(sign_c_lamps, FACES * LAMP_MESHSETS);
    }
}

void sign_c_run(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    sign_c_draw(task);
    VARS(work)->frame += _builtin_fabsf(FRAME_SPEED(work));
    if (VARS(work)->frame >= sign_c_action.motion->nbFrame) {
        VARS(work)->frame = 0.0F;
    }
    if (TASK_TIMER(work)++ > FACE_WAIT(work)) {
        FACE(work)++;
        if (FACE(work) > FACES) {
            FACE(work) = 0;
        }
        work->timer = 0;
    }
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Y), "-> Frame Pitch");
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_Z), "-> UV Pitch");
        return;
    }
    EntryColliList(work);
}
