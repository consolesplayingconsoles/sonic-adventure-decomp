/* @unit 0C909460-0C9095E0 +r04 +egflags +pool32 */
/* SitaAlEgg and UeAlEgg, eggs that loop along the table's lower and upper
 * routes */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "draw/draw.h"
#include "path/path.h"
#include "stg09/casino.h"
#include "stg09/paths.h"
#include "stg09/route_egg.h"
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
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
int thunk_FUN_8c09cbc0(char *name, void *dest);
void FUN_0c909568(struct task *task);
void FUN_0c90956c(struct task *task);
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

#define VARS(work) ((struct route_egg_vars *)&(work)->vars)
#define ROUTE(work) ((work)->tick)
#define ROUTE_LOWER 0
#define ROUTE_UPPER 1
#define FRAME_SPEED 0.1F
#define LAST_FRAME 19.0F
#define LOWER_END 1114.0F
#define UPPER_END 1844.0F
extern NJS_ACTION route_egg_action;

struct route_egg_vars {
    Float frame; /* route_egg_action's frame */
    Float distance; /* along the route's path */
};

/* the routes, as ROUTE holds them */

/* route_egg_action's frames a step, and the frame at which the egg goes
 * back to frame 0. the action has 20 frames */

/* the distances at which an egg goes back to its route's start. the lower
 * path is 1115.8 long, and the upper 1845.4 */

void route_egg_destroy(struct task *task)
{
}

void route_egg_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    casino_set_texture(34);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    (((ang) = (camera_twp->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
    ds_ActionClip(&route_egg_action,
                  ((struct route_egg_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

void route_egg_run(struct task *task)
{
    struct task_work *work = task->work;
    struct GetStatusOnPath sample;

    VARS(work)->frame += FRAME_SPEED;
    if (VARS(work)->frame >= LAST_FRAME) {
        VARS(work)->frame = 0.0F;
    }
    sample.distance = VARS(work)->distance;
    if (ROUTE(work) == ROUTE_LOWER) {
        GetStatusOnPath(&route_egg_lower_path, &sample);
    } else {
        GetStatusOnPath(&route_egg_upper_path, &sample);
    }
    work->pos.x = sample.pos.x;
    work->pos.y = sample.pos.y;
    work->pos.z = sample.pos.z;
    VARS(work)->distance += 1.0F;
    if (ROUTE(work) == ROUTE_LOWER) {
        if (VARS(work)->distance >= LOWER_END) {
            VARS(work)->distance = 0.0F;
        }
    } else {
        if (VARS(work)->distance >= UPPER_END) {
            VARS(work)->distance = 0.0F;
        }
    }
    route_egg_draw(task);
}

void route_egg_start(struct task *task, Uint8 route)
{
    struct task_work *work = task->work;

    ROUTE(work) = route;
    VARS(work)->frame = 0.0F;
    task->step = route_egg_run;
    task->draw = route_egg_draw;
    task->destructor = route_egg_destroy;
}

void FUN_0c909568(struct task *task)
{
    route_egg_start(task, ROUTE_LOWER);
}

void FUN_0c90956c(struct task *task)
{
    route_egg_start(task, ROUTE_UPPER);
}
