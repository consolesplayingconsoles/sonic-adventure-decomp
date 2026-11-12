/* @unit 8C0D5DC0-8C0D6000 +jpflags +pool32 */
/* the seconds E-102 gets, as a count rising in the world, facing the camera */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "player/e102_bonus.h"
#include "player/e102_getsec.h"
#include "player/lockon.h"
#include "system/frame.h"
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
void FUN_8c0d5f94(struct task_work *from, int seconds);
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
void E102KillCursor(struct task *target);
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

#define VARS(work) ((struct getsec_vars *)&(work)->vars)
enum getsec_mode { GETSEC_START, GETSEC_RISE };

struct getsec_vars {
    Float age; /* the share of its life gone, from 0 to 1 */
    Uint8 unk_04[4];
    Sint16 seconds;
};
extern NJS_ARGB getsec_material;

/* the count rises 0.3 a step for 120 steps, facing the camera. it draws
 * its backdrop, then its digits from the last leftward */
static void e102_getsec_step(struct task *task)
{
    struct task_work *work = task->work;
    int digits;
    int seconds;

    switch (work->mode) {
    case GETSEC_START:
        VARS(work)->age = 0.0F;
        work->mode = GETSEC_RISE;
        break;
    case GETSEC_RISE:
        work->pos.y += 0.3F;
        VARS(work)->age += 1.0F / 120.0F;
        if (VARS(work)->age >= 1.0F) {
            DestroyTask(task);
            return;
        }
        break;
    }
    if (loop_count != 0) {
        return;
    }
    seconds = VARS(work)->seconds;
    if (seconds > 99) {
        digits = 3;
    } else if (seconds > 9) {
        digits = 2;
    } else {
        digits = 1;
    }
    njSetConstantMaterial(&getsec_material);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    njSetTexture_jp(&e102time_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, camera_twp->ang.y);
    TURN(njRotateX, camera_twp->ang.x + NJM_DEG_ANG(180));
    njTranslate(NULL, 0.0F, 0.0F, -10.0F);
    njDrawSprite3D(&lockon_sprite, E102TIME_GETSECBG,
                   NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
    while (digits > 0) {
        njTranslate(NULL, -8.0F, 0.0F, 0.0F);
        njDrawSprite3D(&lockon_sprite, seconds % 10,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR);
        digits--;
        seconds /= 10;
    }
    late_DrawObjectClipEx(1);
}

void FUN_8c0d5f94(struct task_work *from, int seconds)
{
    struct task *task;

    task = CreateElementalTask(TASK_WORK, 2, e102_getsec_step);
    if (task != NULL) {
        task->work->pos = from->pos;
        VARS(task->work)->seconds = seconds;
    }
}
