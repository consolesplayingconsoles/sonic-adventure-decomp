/* @unit 0C908B40-0C908D00 +egflags +pool32 */
/* O FUUSYA1, a windmill whose blades turn at a speed that swells and fades */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/model.h"
#include "object/placement.h"
#include "stg08/windmill.h"
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
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
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

/* the mill, with its blades as its child */
#define WINDMILL_RANGE 1000100.0F
#define BLADE_DEGREES 2.2F
#define BLADE_SWELL_DEGREES 0.5F
#define SWELL_STEPS 260.0F
#define SWELL(step)                                                            \
    njAbs(njSin((Angle)((step) * ((360.0F / SWELL_STEPS) * ANGLE_PER_DEGREE))))
#define BLADE_TURN(work) ((work)->ang.z)
extern NJS_OBJECT windmill_object;

/* squared: destroyed beyond about 1000 units of the camera and player 0 */

/* each step, the blades turn BLADE_DEGREES plus BLADE_SWELL_DEGREES times
 * SWELL of work->timer. SWELL(step) rises from 0 to 1 and falls back every
 * SWELL_STEPS / 2 steps */

void Object_IcecapFuusya1End(struct task *task);
void Object_IcecapFuusya1Exec(struct task *task);
void Object_IcecapFuusya1Draw(struct task *task);

void ObjectIcecapFuusya1(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, WINDMILL_RANGE)) {
        BLADE_TURN(work) = 0;
        work->timer = 0;
        task->draw = Object_IcecapFuusya1Draw;
        task->step = Object_IcecapFuusya1Exec;
        task->destructor = Object_IcecapFuusya1End;
    }
}

void Object_IcecapFuusya1End(struct task *task)
{
}

void Object_IcecapFuusya1Exec(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, WINDMILL_RANGE)) {
        Object_IcecapFuusya1Draw(task);
        BLADE_TURN(work) +=
            (Angle)((BLADE_DEGREES +
                     (BLADE_SWELL_DEGREES * SWELL(TASK_TIMER(work)++))) *
                    ANGLE_PER_DEGREE);
    }
}

/* the blades turn about their model's center */
void Object_IcecapFuusya1Draw(struct task *task)
{
    NJS_OBJECT *mill = &windmill_object;
    struct task_work *work = task->work;
    NJS_OBJECT *child;
    NJS_MODEL *blades;
    Float *walk;
    Float x;
    Float y;
    Float z;
    Angle ang;

    if (!CheckRangeOutWithR(task, WINDMILL_RANGE)) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateX, work->ang.x, ang);
        TURN_VIA(njRotateY, work->ang.y, ang);
        ds_DrawModelClip(mill->model);
        /* @hack spelling: the child read into a local of its own, which
         * loads it into R4 (0x0c9092ac); read in the model's load, it takes
         * R2 and 2 of 96 words differ */
        child = mill->child;
        blades = child->model;
        /* @hack spelling: the center read through a Float walk, which steps one
         * pointer through it (FMOV.S @R4+,FR14 at 0x0c9092b6); through the
         * members, work and the mill trade R14 and R13, the function runs 2
         * bytes long and 58 of 96 words differ */
        walk = (Float *)&blades->center;
        x = *walk++;
        y = *walk++;
        z = *walk;
        njTranslate(NULL, x, y, z);
        TURN_VIA(njRotateZ, BLADE_TURN(work), ang);
        njTranslate(NULL, -x, -y, -z);
        ds_DrawModelClip(blades);
        late_DrawObjectClipEx(1);
    }
}
