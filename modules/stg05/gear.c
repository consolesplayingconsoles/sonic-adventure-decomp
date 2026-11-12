/* @unit 0C904580-0C9047E0 @data 0CADB8E8-0CADB8F4 +egflags +pool32 */
/* O GEAR, a great turning wheel that puffs dust along its top */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "effect/dust.h"
#include "object/placement.h"
#include "stg05/gear.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke2(struct dust_params *params);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
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

#define VARS(work) ((struct gear_vars *)&(work)->vars)
#define GEAR_LEAVE_RANGE (1000.0F * 1000.0F)
#define GEAR_FRAMES 49.0F
#define GEAR_SPEED 0.5F
extern NJS_TEXLIST texlist_obj_mountain;
extern NJS_ACTION gear_action;

struct gear_vars {
    Float frame;
};

/* the step does nothing in GEAR_IDLE, which nothing in this file sets */
enum gear_mode { GEAR_INIT, GEAR_RUN, GEAR_IDLE };
extern NJS_POINT3 gear_puff_points[8];
extern struct collision_shape gear_shape;

void Norm(struct task *task);
void Draw(struct task *task);
void gear_destroy(struct task *task);

void ObjectMountainGear(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, GEAR_LEAVE_RANGE)) {
        switch (work->mode) {
        case GEAR_INIT:
            VARS(work)->frame = 0.0F;
            task->destructor = gear_destroy;
            task->draw = Draw;
            work->mode = GEAR_RUN;
            break;
        case GEAR_RUN:
            Norm(task);
            Draw(task);
            break;
        case GEAR_IDLE:
            break;
        }
    }
}

/* a puff of dust from each of gear_puff_points, blowing along -x and up in
 * the gear's own space */
void Norm(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 point;
    NJS_POINT3 pos;
    NJS_VECTOR blow = {-1.0F, 0.5F, 0.0F};
    NJS_VECTOR speed;
    Angle ang;
    int i;

    njPushMatrix(&nj_unit_matrix_);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateY, work->ang.y, ang);
    for (i = 0; i < 8; i++) {
        point = gear_puff_points[i];
        njCalcPoint(NULL, &point, &pos);
        njCalcVector(NULL, &blow, &speed);
        CreateSmoke(&pos, &speed, 1.2F);
    }
    late_DrawObjectClipEx(1);
}

/* draw the gear while it is in view, and only then advance its action */
void Draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 1500.0F)) {
        njSetTexture_jp(&texlist_obj_mountain);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
        ds_ActionClip(&gear_action, ((struct gear_vars *)&(work)->vars)->frame);
        late_DrawObjectClipEx(1);
        VARS(work)->frame += GEAR_SPEED;
        if (VARS(work)->frame >= GEAR_FRAMES) {
            VARS(work)->frame -= GEAR_FRAMES;
        }
    }
}

void gear_destroy(struct task *task)
{
}
