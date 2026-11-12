/* @unit 8C045E00-8C046480 +egflags +pool32 */
/* lens flares: a light's glare, and the ghosts strung from the light through
 * the middle of the screen */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "draw/draw.h"
#include "effect/lens.h"
#include "main.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void FUN_8c046120(NJS_POINT3 *pos);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
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

#define LENS_ATTR (NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR)

/* the frames the light itself draws as, lens01, and its glare, panlight */
#define LENS_LIGHT 0
#define LENS_GLARE 7

#define GHOST_END (-1)

/* the glare draws while facing passes GLARE_FACING. in lens_draw, facing is
 * the cosine of the light's angle off the view, so the glare draws within
 * about 8 degrees. the glare's glow is ((facing - 0.98) * 50) squared, 1
 * head on. the glare draws at an alpha of 0.9 times its glow, and a scale
 * of GLARE_SCALE times it */
#define GLARE_FACING 0.99F
#define GLARE_SCALE 20.0F

/* the ghosts' glow is ((facing - GHOST_FACING) * 3) to the fourth power,
 * and 0 while facing is GHOST_FACING or less. in lens_draw, it rises from 0
 * at about 53 degrees off the view, through 1 at about 21, to about 2.07
 * head on */
#define GHOST_FACING 0.6F

/* a ghost of the flare. it draws at an alpha of alpha * the ghosts' glow.
 * its scale is size * (1 - (1 - glow) * shrink), not below 0 */
struct lens_ghost {
    Sint32 texture; /* in lens_texlist, or GHOST_END */
    Float along; /* from the light, 0, through the screen's middle, 1 */
    Float size;
    Float shrink;
    Float alpha;
    Float depth; /* njDrawSprite2D's pri */
};

static void lens_step(struct task *task);
static void lens_destroy(struct task *task);
extern NJS_TEXLIST lens_texlist;
extern NJS_TEXANIM lens_frames[8];
extern NJS_SPRITE lens_sprite;
extern struct lens_ghost lens_ghosts[11];

static void lens_start(struct task *task)
{
    task->step = lens_step;
    task->destructor = lens_destroy;
}
extern int loop_count;

void lens_draw(NJS_POINT3 *pos)
{
    NJS_POINT2 screen;
    NJS_VECTOR view; /* the way the camera looks */
    NJS_VECTOR to_light;
    struct task_work *camera;
    struct lens_ghost *ghost;
    Float facing;
    Float glow;
    Float size;

    camera = camera_twp;
    if (loop_count != 0) {
        return;
    }
    to_light.x = pos->x - camera->pos.x;
    to_light.y = pos->y - camera->pos.y;
    to_light.z = pos->z - camera->pos.z;
    njUnitVector(&to_light);
    /* @hack spelling: the matrix and forward in a scope of their own, whose
     * stack space across takes once it ends: the frame is 116 bytes
     * (ADD #-116,R15 at 0x8c048bc0); declared with the function's locals, it
     * is 124 and 27 of 305 words differ */
    {
        NJS_MATRIX matrix;
        NJS_VECTOR forward;

        forward.x = 0.0F;
        forward.y = 0.0F;
        forward.z = -1.0F;
        njUnitMatrix(&matrix);
        TURN_MATRIX(njRotateY, &matrix, camera->ang.y);
        TURN_MATRIX(njRotateX, &matrix, camera->ang.x);
        njCalcVector(&matrix, &forward, &view);
    }
    facing = njInnerProduct(&view, &to_light);
    if (facing > 0.0F) {
        NJS_POINT2 across;

        njSetTexture_jp(&lens_texlist);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        njFogDisable();
        njProjectScreen(NULL, pos, &screen);
        if (facing > GLARE_FACING) {
            glow = (facing - 0.98F) * 50.0F;
            glow = glow * glow;
            SetMaterial(0.9F * glow, 1.0F, 1.0F, 1.0F);
            lens_sprite.p.x = screen.x;
            lens_sprite.p.y = screen.y;
            lens_sprite.sx = glow * GLARE_SCALE;
            lens_sprite.sy = glow * GLARE_SCALE;
            late_DrawSprite2D(&lens_sprite, LENS_GLARE, -2.0F, LENS_ATTR);
        }
        if (facing > GHOST_FACING) {
            glow = (facing - GHOST_FACING) * 3.0F;
        } else {
            glow = 0.0F;
        }
        glow = glow * glow * glow * glow;
        across.x = -screen.x + SCREEN_MIDDLE_X;
        across.y = -screen.y + SCREEN_MIDDLE_Y;
        SetMaterial(1.0F, 1.0F, 1.0F, 1.0F);
        lens_sprite.p.x = screen.x;
        lens_sprite.p.y = screen.y;
        lens_sprite.sx = 1.0F;
        lens_sprite.sy = 1.0F;
        late_DrawSprite2D(&lens_sprite, LENS_LIGHT, -3.0F, LENS_ATTR);
        for (ghost = lens_ghosts; ghost->texture != GHOST_END; ghost++) {
            size = ghost->size * (1.0F - ((1.0F - glow) * ghost->shrink));
            if (size < 0.0F) {
                size = 0.0F;
            }
            SetMaterial(glow * ghost->alpha, 1.0F, 1.0F, 1.0F);
            lens_sprite.p.x = screen.x + (across.x * ghost->along);
            lens_sprite.p.y = screen.y + (across.y * ghost->along);
            lens_sprite.sx = size;
            lens_sprite.sy = size;
            late_DrawSprite2D(&lens_sprite, ghost->texture, ghost->depth,
                              LENS_ATTR);
        }
    }
    njFogEnable();
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    lens_sprite.p.x = 0.0F;
    lens_sprite.p.y = 0.0F;
    lens_sprite.sx = 1.0F;
    lens_sprite.sy = 1.0F;
}

static void lens_step(struct task *task)
{
    lens_draw(&task->work->pos);
    /* @hack redundant: a return where the function ends, which makes the frame
     * with ADD #-4,R15 and stores task in it across the call (0x8c048e90,
     * 0x8c048e92); without it, a push does both, the call becomes a tail
     * branch, the function runs 2 bytes short and 6 of 6 words differ */
    /* NOLINTNEXTLINE(readability-redundant-control-flow) */
    return;
}

static void lens_destroy(struct task *task)
{
}

void FUN_8c046120(NJS_POINT3 *pos)
{
    struct task *task = CreateElementalTask(TASK_WORK, 4, lens_start);

    if (task != NULL) {
        struct task_work *work = task->work;

        work->pos = *pos;
    }
}
extern int loop_count;

void lens_draw_facing(NJS_POINT3 *pos, NJS_VECTOR *dir)
{
    NJS_POINT2 screen;
    NJS_VECTOR view; /* the way the camera looks */
    NJS_VECTOR to_light;
    struct task_work *camera;
    struct lens_ghost *ghost;
    Float facing;
    Float glow;
    Float size;

    camera = camera_twp;
    if (loop_count != 0) {
        return;
    }
    to_light.x = pos->x - camera->pos.x;
    to_light.y = pos->y - camera->pos.y;
    to_light.z = pos->z - camera->pos.z;
    njUnitVector(&to_light);
    /* @hack spelling: the matrix and forward in a scope of their own, as in
     * lens_draw: the frame is 120 bytes (ADD #-120,R15 at 0x8c048f16);
     * declared with the function's locals, it is 128, the function runs 2
     * bytes long and 175 of 303 words differ */
    {
        NJS_MATRIX matrix;
        NJS_VECTOR forward;

        forward.x = 0.0F;
        forward.y = 0.0F;
        forward.z = -1.0F;
        njUnitMatrix(&matrix);
        TURN_MATRIX(njRotateY, &matrix, camera->ang.y);
        TURN_MATRIX(njRotateX, &matrix, camera->ang.x);
        njCalcVector(&matrix, &forward, &view);
    }
    facing = -njInnerProduct(&view, &to_light) * njInnerProduct(dir, &to_light);
    if (facing > 0.0F) {
        NJS_POINT2 across;

        njSetTexture_jp(&lens_texlist);
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        njProjectScreen(NULL, pos, &screen);
        if (facing > GLARE_FACING) {
            glow = (facing - 0.98F) * 50.0F;
            glow = glow * glow;
            SetMaterial(0.9F * glow, 1.0F, 1.0F, 1.0F);
            lens_sprite.p.x = screen.x;
            lens_sprite.p.y = screen.y;
            lens_sprite.sx = glow * GLARE_SCALE;
            lens_sprite.sy = glow * GLARE_SCALE;
            late_DrawSprite2D(&lens_sprite, LENS_GLARE, -2.0F, LENS_ATTR);
        }
        if (facing > GHOST_FACING) {
            glow = (facing - GHOST_FACING) * 3.0F;
        } else {
            glow = 0.0F;
        }
        glow = glow * glow * glow * glow;
        across.x = -screen.x + SCREEN_MIDDLE_X;
        across.y = -screen.y + SCREEN_MIDDLE_Y;
        SetMaterial(glow, 1.0F, 1.0F, 1.0F);
        lens_sprite.p.x = screen.x;
        lens_sprite.p.y = screen.y;
        lens_sprite.sx = 1.0F;
        lens_sprite.sy = 1.0F;
        for (ghost = lens_ghosts; ghost->texture != GHOST_END; ghost++) {
            size = ghost->size * (1.0F - ((1.0F - glow) * ghost->shrink));
            if (size < 0.0F) {
                size = 0.0F;
            }
            SetMaterial(glow * ghost->alpha, 1.0F, 1.0F, 1.0F);
            lens_sprite.p.x = screen.x + (across.x * ghost->along);
            lens_sprite.p.y = screen.y + (across.y * ghost->along);
            lens_sprite.sx = size;
            lens_sprite.sy = size;
            late_DrawSprite2D(&lens_sprite, ghost->texture, ghost->depth,
                              LENS_ATTR);
        }
    }
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    lens_sprite.p.x = 0.0F;
    lens_sprite.p.y = 0.0F;
    lens_sprite.sx = 1.0F;
    lens_sprite.sy = 1.0F;
}
