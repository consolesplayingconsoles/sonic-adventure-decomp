/* @unit 0C902FE0-0C903180 +egflags +pool32 */
/* the camera's sweep around an E-100 series robot as it goes down */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "stg05/camera_sweep.h"
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
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct task_work *camera_twp;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
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
extern NJS_POINT3 sweep_unit;
extern NJS_POINT3 sweep_target;
extern Angle sweep_ang;
extern Angle sweep_turn;
extern Float sweep_reach;
extern int sweep_step;
extern int sweep_steps;

#define SWEEP_DISTANCE 50.0F /* the camera's distance, less the reach */
#define SWEEP_ELEVATION NJM_DEG_ANG(30) /* the angle it looks down from */
#define SWEEP_ARC NJM_DEG_ANG(100) /* the turn of its whole sweep */

void CameraWindyTgtDeath(struct camera_view *view);

void StartCameraWindy_TgtDeath(NJS_POINT3 *target, Angle ang, int steps)
{
    VECTOR_COPY(&sweep_target, target);
    sweep_ang = ang - (SWEEP_ARC / 2);
    sweep_turn = SWEEP_ARC / steps;
    sweep_step = 0;
    sweep_steps = steps;
    sweep_reach = 0.0F;
    CameraSetEventCameraFunc(CameraWindyTgtDeath, 0, CAMERA_LOOK_AT);
}

void SetCameraWindy_TgtDeathExpSize(Float reach)
{
    sweep_reach = reach;
}

void CameraWindyTgtDeath(struct camera_view *view)
{
    NJS_POINT3 pos;
    Float distance;

    if (++sweep_step > sweep_steps) {
        return;
    }
    sweep_ang += sweep_turn;
    cameraControlWork->target.x = sweep_target.x;
    cameraControlWork->target.y = sweep_target.y;
    cameraControlWork->target.z = sweep_target.z;
    distance = sweep_reach + SWEEP_DISTANCE;
    njPushMatrix(&nj_unit_matrix_);
    njScale(NULL, distance, distance, distance);
    TURN(njRotateY, sweep_ang);
    njRotateZ(NULL, SWEEP_ELEVATION);
    njCalcPoint(NULL, &sweep_unit, &pos);
    late_DrawObjectClipEx(1);
    VECTOR_SUM(&pos, &pos, &sweep_target);
    cameraControlWork->pos.x = pos.x;
    cameraControlWork->pos.y = pos.y;
    cameraControlWork->pos.z = pos.z;
}
