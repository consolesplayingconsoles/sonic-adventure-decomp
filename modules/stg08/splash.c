/* @unit 0C900000-0C900360 +egflags +pool32 */
/* the water splashes that O ICEBAR1 and O ICEBAR2 raise as they rise */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "camera/camera.h"
#include "stg08/splash.h"
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
void DestroyTask(struct task *task);
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
void FUN_0c9002e0(NJS_POINT3 *pos, Angle ang, Float size);
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

/* alpha_water01 to alpha_water08, the splash's eight images */
#define SPLASH_IMAGES 8
#define SPLASH_LAST (SPLASH_IMAGES - 1.0F)
#define SPLASH_RATE 0.5F
#define SPLASH_LAST_RATE 1.0F
#define SPLASH_SINK 0.0F
#define SPLASH_FADE 0.5F
#define SPLASH_FADE_STEPS 20
#define SPLASH_FLICKER 0.01F
#define SPLASH_FLICKER_MAX 0.6F
#define SPLASH_FLICKER_MIN 0.1F
#define VARS(work) ((struct splash_vars *)&(work)->vars)
#define SPLASH_SIZE(work) ((work)->scl.x)
#define SPLASH_IMAGE(work) ((work)->scl.y)
#define SPLASH_DROP(work) ((work)->scl.z)
extern NJS_TEXLIST alpha_water_texlist;

/* a splash plays its images at SPLASH_RATE a step. the play ends as it
 * reaches the last, so the rate past it, SPLASH_LAST_RATE, never applies */
/* how far the splash sinks for each image played: not at all */
/* the fade lasts SPLASH_FADE_STEPS steps. its alpha falls from 1 by
 * SPLASH_FADE a step, so it reaches 0 on the fade's third step. it stays
 * below 0 for the fade's other 17 */
/* a flickering splash's alpha rises by up to SPLASH_FLICKER a step. it stays
 * within SPLASH_FLICKER_MIN and SPLASH_FLICKER_MAX */

struct splash_vars {
    Float alpha;
    Uint8 unk_04[4];
    Float y; /* pos.y, kept while the draw lowers pos by the drop */
};

/* how far the splash has played, in images */
/* how far the draw lowers it: SPLASH_SINK for each image played */

/* nothing sets SPLASH_FLICKERING or SPLASH_HOLD */
enum splash_mode {
    SPLASH_INIT,
    SPLASH_PLAY,
    SPLASH_FLICKERING,
    SPLASH_HOLD,
    SPLASH_FADING,
    SPLASH_GONE
};

void icecap_splash_init(struct task *task);
void icecap_splash_play(struct task *task);
void icecap_splash_flicker(struct task *task);
void icecap_splash_draw(struct task *task);
void icecap_splash_fade(struct task *task);
void icecap_splash_destroy(struct task *task);
extern NJS_TEXANIM icecap_splash_texanims[8];
extern NJS_SPRITE icecap_splash_sprite;

void icecap_splash_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case SPLASH_INIT:
        icecap_splash_init(task);
        break;
    case SPLASH_PLAY:
        icecap_splash_play(task);
        icecap_splash_draw(task);
        break;
    case SPLASH_FADING:
        icecap_splash_fade(task);
        icecap_splash_draw(task);
        break;
    case SPLASH_FLICKERING:
        icecap_splash_flicker(task);
        /* SPLASH_FLICKERING falls through to SPLASH_HOLD's draw */
    case SPLASH_HOLD:
        icecap_splash_draw(task);
        break;
    case SPLASH_GONE:
        /* @hack redundant: task_kill in a loop of one pass, which keeps the
         * call a JSR followed by a return (0x0c900052, 0x0c900058); as a
         * plain call, SHC jumps to it, the function runs 4 bytes long and 7
         * of 46 words differ */
        do {
            FreeTask(task);
        } while (0);
        break;
    /* @hack redundant: the default's return, which returns from the switch's
     * test itself (RTS at 0x0c900024); without it, SHC branches to the
     * end, the function runs 2 bytes short and 35 of 46 words differ */
    default:
        return;
    }
}

void icecap_splash_init(struct task *task)
{
    struct task_work *work = task->work;

    work->mode = SPLASH_PLAY;
    work->timer = 0;
    VARS(work)->alpha = 1.0F;
    task->draw = icecap_splash_draw;
    task->destructor = icecap_splash_destroy;
}

void icecap_splash_play(struct task *task)
{
    struct task_work *work = task->work;

    if (SPLASH_IMAGE(work) < SPLASH_LAST) {
        SPLASH_IMAGE(work) += SPLASH_RATE;
    } else {
        SPLASH_IMAGE(work) += SPLASH_LAST_RATE;
    }
    SPLASH_DROP(work) = SPLASH_IMAGE(work) * SPLASH_SINK;
    if (SPLASH_IMAGE(work) >= SPLASH_LAST) {
        work->mode = SPLASH_FADING;
        SPLASH_IMAGE(work) = SPLASH_LAST;
    }
    work->timer++;
}

void icecap_splash_flicker(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->alpha += rand() * (SPLASH_FLICKER * RAND_SCALE);
    if (VARS(work)->alpha > SPLASH_FLICKER_MAX) {
        VARS(work)->alpha = SPLASH_FLICKER_MAX;
    } else if (VARS(work)->alpha < SPLASH_FLICKER_MIN) {
        VARS(work)->alpha = SPLASH_FLICKER_MIN;
    }
}

void icecap_splash_draw(struct task *task)
{
    struct task_work *work = task->work;
    Uint32 image = (Uint32)SPLASH_IMAGE(work);
    NJS_ARGB color;

    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    VARS(work)->y = work->pos.y;
    /* @hack spelling: the subtraction written out, which reads the drop at
     * @(R0,R14) (0x0c90016e); with -=, SHC reaches it through its address in
     * R1, the function runs 2 bytes long and 97 of 130 words differ */
    work->pos.y = work->pos.y - SPLASH_DROP(work);
    njSetTexture_jp(&alpha_water_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, camera_twp->ang.y);
    TURN(njRotateX, camera_twp->ang.x);
    TURN(njRotateZ, work->ang.z);
    njScale(NULL, SPLASH_SIZE(work), SPLASH_SIZE(work), SPLASH_SIZE(work));
    color.a = VARS(work)->alpha;
    color.r = 1.0F;
    color.g = 1.0F;
    color.b = 1.0F;
    njSetConstantMaterial(&color);
    njDrawSprite3D(&icecap_splash_sprite, image,
                   NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR | NJD_SPRITE_ALPHA);
    late_DrawObjectClipEx(1);
    color.a = 0.0F;
    color.r = 0.0F;
    color.g = 0.0F;
    color.b = 0.0F;
    njSetConstantMaterial(&color);
    work->pos.y = VARS(work)->y;
}

void icecap_splash_fade(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->alpha = 1.0F - (work->tick * SPLASH_FADE);
    work->tick++;
    if (work->tick == SPLASH_FADE_STEPS) {
        work->mode = SPLASH_GONE;
    }
}

/* the destructor. its task_kill changes nothing: task_destroy clears the
 * step as the destructor returns */
void icecap_splash_destroy(struct task *task)
{
    FreeTask(task);
}

void FUN_0c9002e0(NJS_POINT3 *pos, Angle ang, Float size)
{
    struct task *task = CreateElementalTask(TASK_WORK, 6, icecap_splash_step);
    struct task_work *work;

    if (task != NULL) {
        work = task->work;
        work->pos = *pos;
        SPLASH_SIZE(work) = size;
        SPLASH_IMAGE(work) = 0.0F;
        work->ang.x = 0;
        work->ang.y = 0;
        work->ang.z = ang;
    }
}
