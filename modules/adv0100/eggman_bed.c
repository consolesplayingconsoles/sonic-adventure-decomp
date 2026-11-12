/* @unit 0C924380-0C9244C0 +egflags +pool32 */
/* O EGGMANBED Eggman's bed, which stands on end until switch 1 turns on, then
 * swings down flat */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv0100/eggman_bed.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "object/switch.h"
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
void ObjectSwitch(struct task *task);
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

/* @hack type: the bed's object as an array, which has SHC pool its address
 * and read its model 4 bytes past it (MOV.L @(4,R4),R4 at 0x0c9244d2); as a
 * plain object, SHC pools the model's address, and 6 of 31 words differ */
#define BED_SWITCH 1
#define BED_ON_END 0x4000 /* the bed's angle about z standing on end */
#define SWING_STEP 16 /* the speed the swing gains each step */
#define SWING_MOST 0x200 /* the swing's top speed, in angle each step */
#define VARS(work) ((struct eggman_bed_vars *)&(work)->vars)
extern NJS_OBJECT eggman_bed_object[];

struct eggman_bed_vars {
    Uint8 unk_00[8];
    Angle speed; /* the swing's speed */
};

enum eggman_bed_mode { BED_INIT, BED_WAIT, BED_DOWN, BED_SWING };

void eggman_bed_draw(struct task *task);
void eggman_bed_destroy(struct task *task);
void eggman_bed_draw_work(struct task_work *work);
extern struct collision_shape eggman_bed_shapes[1];

void egg_carrier_eggman_bed_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case BED_INIT:
        VARS(work)->speed = 0;
        work->ang.x = 0;
        work->ang.z = BED_ON_END;
        if (!OnEdit(task)) {
            CCL_Init(task, eggman_bed_shapes, COLLISION_OBJECT, 1, 1);
        }
        task->destructor = eggman_bed_destroy;
        task->draw = eggman_bed_draw;
        work->mode = BED_WAIT;
        break;
    case BED_WAIT:
        /* @hack spelling: an early break, not an if around the store, which
         * lets this case's store of its mode share the swing's (BRA at
         * 0x0c9243ea to 0x0c924442); as an if, 2 of 90 words differ */
        if (!switch_is_on(BED_SWITCH)) {
            break;
        }
        work->mode = BED_SWING;
        break;
    case BED_SWING:
        VARS(work)->speed += SWING_STEP;
        if (VARS(work)->speed > SWING_MOST) {
            VARS(work)->speed = SWING_MOST;
        }
        work->ang.z -= VARS(work)->speed;
        /* @hack spelling: an early break, not an if around the stores, whose
         * store of the mode BED_WAIT's shares (0x0c924442); as an if, 4 of 90
         * words differ */
        if (work->ang.z > 0) {
            break;
        }
        work->ang.z = 0;
        work->mode = BED_DOWN;
        break;
    case BED_DOWN:
        break;
    }
    eggman_bed_draw_work(work);
    if (!OnEdit(task)) {
        EntryColliList(work);
    }
}

void eggman_bed_draw(struct task *task)
{
    eggman_bed_draw_work(task->work);
}

void eggman_bed_destroy(struct task *task)
{
}

void eggman_bed_draw_work(struct task_work *work)
{
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    ds_DrawModelClip(eggman_bed_object->model);
    late_DrawObjectClipEx(1);
}
