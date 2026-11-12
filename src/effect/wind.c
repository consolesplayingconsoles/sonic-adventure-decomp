/* @unit 8C046D80-8C047040 +egflags +pool32 */
/* the wind: one task that blows across the ground in gusts */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/wind.h"
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
void *syMalloc_default_malloc(size_t size);
Bool FUN_8c046f48(NJS_POINT3 *pos, NJS_VECTOR *force);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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

/* a gust is never more than this share of the wind's strength */
#define GUST_MAX 0.7F
/* the phase's pace, how far it moves a step, is PACE_MAX less a random
 * whole number below PACE_SPREAD: 73 to 364 */
#define PACE_MAX 364
#define PACE_SPREAD 292.0F

static void wind_destroy(struct task *task);
static void BlowingWind(struct task *task);
extern struct task *wind_task;

void wind_set(Sint8 level, const Angle *heading)
{
    struct task *task;

    if (wind_task == NULL) {
        task = CreateElementalTask(TASK_WORK, 0, BlowingWind);
        if (task == NULL) {
            return;
        }
        task->destructor = wind_destroy;
        wind_task = task;
        task->work->ang.y = rand() * RAND_SCALE * 65535.0F;
        task->work->pos.x = -100000.0F;
        task->work->pos.y = 0.0F;
        task->work->pos.z = -100000.0F;
    }
    wind_task->work->submode = level;
    if (heading != NULL) {
        wind_task->work->ang.y = *heading;
    }
}

void wind_stop(void)
{
    if (wind_task != NULL) {
        DestroyTask(wind_task);
        wind_task = NULL;
    }
}

static void wind_destroy(struct task *task)
{
    wind_task = NULL;
}

/* while the phase is 0 or has made a turn, pick a strength for the level
 * and a pace for the phase. then move the phase by the pace */
static void BlowingWind(struct task *task)
{
    struct task_work *work = task->work;

    /* @bug logic: only its overflow, at least 5.8 million steps on,
     * takes ang.x back below 0x10000. from the phase's first turn until
     * then, the test (CMP/GE at 0x8c049bb6) holds on every step, and the
     * wind picks a new strength and pace each step */
    if (work->ang.x == 0 || work->ang.x >= 0x10000) {
        switch (work->submode) {
        case 0:
            work->scl.x = 0.0F;
            break;
        case 1:
            work->scl.x = RANDOM(0.5F, 1.0F);
            break;
        case 2:
            work->scl.x = RANDOM(1.0F, 2.0F);
            break;
        case 3:
            work->scl.x = RANDOM(2.0F, 3.0F);
            break;
        case 4:
        default:
            work->scl.x = RANDOM(3.0F, 5.0F);
            break;
        }
        work->ang.z = PACE_MAX - (Angle)(rand() * RAND_SCALE * PACE_SPREAD);
    }
    work->ang.x += work->ang.z;
    work->scl.z = work->scl.x / ((Float)work->ang.z * (1.0F / 65536.0F));
}

Bool FUN_8c046f48(NJS_POINT3 *pos, NJS_VECTOR *force)
{
    struct task_work *work;
    Angle phase;
    Float gust;

    if (wind_task == NULL) {
        return FALSE;
    }
    if (force != NULL) {
        work = wind_task->work;
        VECTOR_DIFF(force, pos, &work->pos);
        /* each unit of pos's distance from the far point, mod scl.z, adds
         * a turn to the phase. the gusts are bands a unit apart */
        phase = float_wrap(njScalor(force), work->scl.z) * 65536.0F;
        gust = (njSin(phase + work->ang.x) + 1.0F) * 0.5F;
        if (gust > GUST_MAX) {
            gust = GUST_MAX;
        }
        gust *= work->scl.x;
        force->x = njSin(work->ang.y) * gust;
        force->y = 0.0F;
        force->z = njCos(work->ang.y) * gust;
    }
    return TRUE;
}
