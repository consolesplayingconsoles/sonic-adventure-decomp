/* @unit 0C9018A0-0C9019C0 +r04 +egflags +pool32 */
/* O KAITENMETER: a gauge of the whole turns each way under a handle's key */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "debug/print.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "stg12/handle.h"
#include "stg12/handle_meter.h"
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
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
Bool OnEdit(struct task *task);
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
#define VARS(work) ((struct handle_meter_vars *)&(work)->vars)
extern NJS_OBJECT handle_meter_object;
extern NJS_OBJECT handle_meter_right_object;
extern NJS_OBJECT handle_meter_left_object;

/* destroyed beyond 500 units of the camera and player 0 */

enum handle_meter_mode { METER_INIT, METER_RUN };

/* left and right are the counts the bars show */
struct handle_meter_vars {
    Uint8 left;
    Uint8 right;
    Uint8 unk_02[6];
    /* @hack type: key in an array of one, so SHC adds 16 to the work's
     * address to reach it, as ADD #16,R3 at 0x0c9018b6 does; as a Sint8,
     * summed over handle_meter_init and handle_meter_read, 18 of 50 words
     * differ */
    Sint8 key[1];
};

static void handle_meter_init(struct task *task);
void handle_meter_draw(struct task *task);
void handle_meter_destroy(struct task *task);
void handle_meter_read(struct task_work *work);
extern struct collision_shape handle_meter_shape;
extern Float handle_meter_lengths[];

/* @hack spelling: the registration in a helper, which SHC expands at both of
 * handle_meter_step's calls. the step then saves only R14 and R13 (0x0c901800,
 * 0x0c901804). with collision_register(work) written in the step, it saves R12
 * too, the object's code runs 32 bytes long, and 70 of the step's 74 words
 * differ */
static void handle_meter_register(struct task *task)
{
    struct task_work *work = task->work;

    EntryColliList(work);
}
void handle_meter_step(struct task *task);

static void handle_meter_init(struct task *task)
{
    struct task_work *work = task->work;

    task->draw = handle_meter_draw;
    task->destructor = handle_meter_destroy;
    CCL_Init(task, &handle_meter_shape, COLLISION_OBJECT, 1, 1);
    VARS(work)->left = 0;
    VARS(work)->right = 0;
    VARS(work)->key[0] = (int)work->scl.x & (HANDLE_KEYS - 1);
    work->mode = METER_RUN;
}

void handle_meter_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count == 0) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        late_DrawObject(&handle_meter_object);
        njPushMatrix(NULL);
        njScale(NULL, handle_meter_lengths[VARS(work)->left], 1.0F, 1.0F);
        late_DrawObject(&handle_meter_left_object);
        late_DrawObjectClipEx(1);
        njPushMatrix(NULL);
        njScale(NULL, handle_meter_lengths[VARS(work)->right], 1.0F, 1.0F);
        late_DrawObject(&handle_meter_right_object);
        late_DrawObjectClipEx(1);
        late_DrawObjectClipEx(1);
    }
}

void handle_meter_destroy(struct task *task)
{
}

void handle_meter_read(struct task_work *work)
{
    int right;
    int left;

    handle_get_turns(VARS(work)->key[0], &right, &left);
    VARS(work)->right = right;
    VARS(work)->left = left;
}
