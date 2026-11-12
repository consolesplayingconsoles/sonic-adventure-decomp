/* @unit 8C0F2860-8C0F2AE0 +jpflags +pool32 */
/* Chaos's brain: CHAOS_BRAINFRAME's sixteen frames, played once at a
 * task's place, or looped at a point the brain follows */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#define TEXT_6 ""
#define TEXT_7 ""
#define TEXT_8 ""
#define TEXT_9 ""
#define TEXT_10 ""
#define TEXT_11 ""
#define TEXT_12 ""
#define TEXT_13 ""
#define TEXT_14 ""
#define TEXT_15 ""
#define TEXT_16 ""
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "draw/draw.h"
#include "effect/brain.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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

#define TEXT_1_LENGTH 10
#define TEXT_2_LENGTH 10
#define TEXT_3_LENGTH 10
#define TEXT_4_LENGTH 10
#define TEXT_5_LENGTH 10
#define TEXT_6_LENGTH 10
#define TEXT_7_LENGTH 10
#define TEXT_8_LENGTH 10
#define TEXT_9_LENGTH 10
#define TEXT_10_LENGTH 10
#define TEXT_11_LENGTH 10
#define TEXT_12_LENGTH 10
#define TEXT_13_LENGTH 10
#define TEXT_14_LENGTH 10
#define TEXT_15_LENGTH 10
#define TEXT_16_LENGTH 10

/* CHAOS_BRAINFRAME's frames, and the steps each one shows */
#define BRAIN_FRAMES 16
#define BRAIN_WAIT 2

#define VARS(work) ((struct brain_vars *)&(work)->vars)
#define WAIT(work) (VARS(work)->time.count[0])
#define FRAME(work) (VARS(work)->time.count[1])
enum brain_mode { BRAIN_INIT, BRAIN_PLAY };

struct brain_vars {
    NJS_POINT3 *follow;
    /* @hack type: the two cleared together through a Sint32, MOV #0 and one
     * MOV.L store (0x8c0fdc82, 0x8c0fdc84 in brain_once_step); cleared one by
     * one, 79 of the two steps' 95 words differ */
    /* @hack type: the two as an array, which SHC reaches through an address
     * it forms (MOV R5,R2 and ADD #12,R2 at 0x8c0fdca8, 0x8c0fdcaa); as
     * fields, they take displacement loads, and 64 of the 201 words of the
     * four functions that use them differ */
    union {
        Sint32 both;
        /* the steps the current frame has shown, then that frame, which
         * WAIT and FRAME read */
        Sint16 count[2];
    } time;
};
extern const Sint32 brain_texanim_count;
extern NJS_TEXNAME chaos_brainframe_textures[16];
extern NJS_TEXLIST chaos_brainframe_texlist;
extern NJS_TEXANIM brain_frames[2];
extern NJS_SPRITE brain_once_sprite;
extern NJS_SPRITE brain_sprite;
extern Sint8 brain_shown;
extern const NJS_POINT3 *brain_offset;

static void brain_once_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (loop_count == 0) {
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        brain_frames[0].texid = FRAME(work);
        njDrawSprite3D(&brain_once_sprite, 0,
                       NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
        late_DrawObjectClipEx(1);
    }
}

void brain_once_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case BRAIN_INIT:
        VARS(work)->time.both = 0;
        work->mode = BRAIN_PLAY;
        brain_once_sprite.sx = brain_once_sprite.sy = 1.0F;
        task->draw = brain_once_draw;
        break;
    case BRAIN_PLAY:
        WAIT(work)++;
        if (WAIT(work) >= BRAIN_WAIT) {
            WAIT(work) -= BRAIN_WAIT;
            FRAME(work)++;
            if (FRAME(work) >= BRAIN_FRAMES) {
                DestroyTask(task);
                return;
            }
        }
        break;
    }
    brain_once_draw(task);
}

static void brain_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (brain_shown) {
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN(njRotateY, camera_twp->ang.y);
        TURN(njRotateX, camera_twp->ang.x);
        /* njTranslateV takes a mutable vector but only reads it */
        njTranslateV(NULL, (NJS_VECTOR *)brain_offset);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        brain_frames[1].texid = FRAME(work);
        njDrawSprite3D(&brain_sprite, 1, NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
        late_DrawObjectClipEx(1);
    }
}

static void brain_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case BRAIN_INIT:
        VARS(work)->time.both = 0;
        work->mode = BRAIN_PLAY;
        task->draw = brain_draw;
        break;
    case BRAIN_PLAY:
        WAIT(work)++;
        if (WAIT(work) >= BRAIN_WAIT) {
            WAIT(work) -= BRAIN_WAIT;
            FRAME(work)++;
            if (FRAME(work) >= BRAIN_FRAMES) {
                FRAME(work) = 0;
            }
        }
        if (VARS(work)->follow != NULL) {
            work->pos = *VARS(work)->follow;
        }
        break;
    }
    brain_draw(task);
}

struct task *brain_create(struct task *boss, Float scale, NJS_POINT3 *follow,
                          const NJS_POINT3 *offset)
{
    struct task *task;
    struct task_work *work;

    task = CreateElementalTask(TASK_WORK, 2, brain_step);
    if (task != NULL) {
        work = task->work;
        brain_sprite.sx = brain_sprite.sy = scale;
        VARS(work)->follow = follow;
        brain_offset = offset;
    }
    brain_shown = 1;
    return task;
}
