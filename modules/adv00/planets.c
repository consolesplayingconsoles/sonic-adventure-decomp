/* @unit 0C90A380-0C90A600 +egflags +pool32 */
/* O WAKUSEI planet model on a stand, whose four parts turn */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv00/planets.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
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

/* the stand, whose children are the four turning parts */
#define PLANETS_SPEED 0.005F
#define WHOLE_TURN 65536.0F
#define VARS(work) ((struct planets_vars *)&(work)->vars)
extern NJS_OBJECT planets_object;

/* the share of a whole turn the parts turn each step */

/* a whole turn, in Angle's units */

struct planets_vars {
    Float turn; /* the parts' angle, as a share of a whole turn */
};

void planets_step(struct task *task);
void planets_draw(struct task *task);
extern struct collision_shape planets_shape;
/* clang-format on */

void planets_init(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    work->ang.x = 0;
    work->ang.y = 0;
    work->ang.z = 0;
    work->mode = 0;
    VARS(work)->turn = 0.0F;
    motion->aim.x = 0;
    motion->aim.y = 0;
    motion->aim.z = 0;
    if (!OnEdit(task)) {
        CCL_Init(task, &planets_shape, COLLISION_OBJECT, 1, 1);
    }
    task->step = planets_step;
    task->draw = planets_draw;
}

void planets_step(struct task *task)
{
    struct task_work *work = task->work;
    Float turn;

    if (!CheckRangeOut(task)) {
        if (!OnEdit(task)) {
            EntryColliList(work);
        }
        turn = VARS(work)->turn + PLANETS_SPEED;
        if (turn >= 1.0F) {
            turn -= 1.0F;
        }
        VARS(work)->turn = turn;
        planets_draw(task);
    }
}

/* draw the stand, then its four parts, each turned by spin. spin replaces the
 * second part's node's y angle and the last two parts' z angles. the first
 * part turns by spin about y alone, without its node's angles */
void planets_draw(struct task *task)
{
    NJS_OBJECT *object;
    NJS_OBJECT *root;
    Angle spin;
    Angle ang;
    struct task_work *work = task->work;

    spin = (Angle)(VARS(work)->turn * WHOLE_TURN);
    root = &planets_object;
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(root->model);
    object = root->child;
    njPushMatrix(NULL);
    njTranslate(NULL, object->pos[0], object->pos[1], object->pos[2]);
    TURN(njRotateY, spin);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    object = object->sibling;
    /* @hack redundant: a never-run test of object, which keeps object in R13
     * and draw_model's address in R10 (0x0c90a98e, 0x0c90a988), as the image
     * has them; without it, the registers rotate and 36 of 189 words differ */
    if (0) {
        if (object) {
        }
    }
    njPushMatrix(NULL);
    njTranslate(NULL, object->pos[0], object->pos[1], object->pos[2]);
    TURN_VIA(njRotateZ, object->ang[2], ang);
    TURN(njRotateY, spin);
    TURN_VIA(njRotateX, object->ang[0], ang);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    object = object->sibling;
    njPushMatrix(NULL);
    njTranslate(NULL, object->pos[0], object->pos[1], object->pos[2]);
    TURN_VIA(njRotateX, object->ang[0], ang);
    TURN_VIA(njRotateY, object->ang[1], ang);
    TURN(njRotateZ, spin);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    object = object->sibling;
    njPushMatrix(NULL);
    njTranslate(NULL, object->pos[0], object->pos[1], object->pos[2]);
    TURN_VIA(njRotateX, object->ang[0], ang);
    TURN_VIA(njRotateY, object->ang[1], ang);
    TURN(njRotateZ, spin);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}
