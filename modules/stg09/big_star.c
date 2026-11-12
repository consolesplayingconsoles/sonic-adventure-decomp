/* @unit 0C908800-0C908940 +r04 +egflags +pool32 */
/* BigStar: a sprite that turns to face the camera and shows its eight images
 * in turn */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "stg09/big_star.h"
#include "stg09/obj_casino_textures.h"
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

#define BIG_STAR_FRAMES 8

#define VARS(work) ((struct big_star_vars *)&(work)->vars)
struct big_star_vars {
    Float manager_data; /* the steps the image has shown, less 1 */
};
extern NJS_TEXANIM big_star_frames[8];
extern NJS_SPRITE big_star_sprite;

void big_star_destroy(struct task *task)
{
}

/* the stars share big_star_sprite, which each draws at its own position */
void big_star_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    Float scale;

    if (loop_count) {
        return;
    }
    njSetTexture_jp(&big_star_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, camera_twp->ang.y, ang);
    scale = work->scl.x;
    njScale(NULL, scale, scale, scale);
    njDrawSprite3D(&big_star_sprite, work->tick, NJD_SPRITE_ALPHA);
    late_DrawObjectClipEx(1);
}

void big_star_run(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->manager_data >= work->scl.z) {
        work->tick = (work->tick + 1) % BIG_STAR_FRAMES;
        VARS(work)->manager_data = 0.0F;
    } else {
        VARS(work)->manager_data += 1.0F;
    }
    big_star_draw(task);
}

void big_star_step(struct task *task)
{
    struct task_work *work = task->work;

    work->tick = 0;
    big_star_sprite.tlist = &big_star_texlist;
    big_star_sprite.tanim = big_star_frames;
    big_star_sprite.sx = 1.0F;
    big_star_sprite.sy = 1.0F;
    big_star_sprite.p.x = 0.0F;
    big_star_sprite.p.y = 0.0F;
    big_star_sprite.p.z = 0.0F;
    task->step = big_star_run;
    task->draw = big_star_draw;
    task->destructor = big_star_destroy;
}
