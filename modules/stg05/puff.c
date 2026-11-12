/* @unit 0C900120-0C9004A0 +r04 +egflags +pool32 */
/* Red Mountain's puffs: smoke and flame sprites in four groups. each group
 * is a task that steps its puffs and draws them */
#include <ninja.h>

#include "camera/camera.h"
#include "draw/draw.h"
#include "effect/dust.h"
#include "effect/flame.h"
#include "stg05/puff.h"
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
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
void *CAlloc(int count, int size);
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
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
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
extern NJS_TEXANIM puff_smoke_frames[10];
extern NJS_TEXANIM puff_flame_frames[8];
extern struct task *puff_groups[4];
extern NJS_SPRITE puff_smoke_sprite;
extern NJS_SPRITE puff_flame_sprite;
extern int puff_frames;

#define SMOKE_FRAMES 10
#define FLAME_FRAMES 6

void puff_draw_group(struct task *task, NJS_SPRITE *sprite);

void puff_smoke_step(struct task *task)
{
    puff_frames = SMOKE_FRAMES;
    LoopTaskC(task);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    SetMaterial(1.0F, 0.8F, 0.8F, 0.7F);
    njSetTexture_jp(&dust_texlist);
    puff_draw_group(task, &puff_smoke_sprite);
}

void puff_smoke_destroy(struct task *task)
{
    FreeTaskC(task);
}

void puff_dark_smoke_step(struct task *task)
{
    puff_frames = SMOKE_FRAMES;
    LoopTaskC(task);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    SetMaterial(1.0F, 0.3F, 0.3F, 0.2F);
    njSetTexture_jp(&dust_texlist);
    puff_draw_group(task, &puff_smoke_sprite);
}

void puff_dark_smoke_destroy(struct task *task)
{
    FreeTaskC(task);
}

void puff_flame_step(struct task *task)
{
    puff_frames = FLAME_FRAMES;
    LoopTaskC(task);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    SetMaterial(1.0F, 0.8F, 0.8F, 0.8F);
    njSetTexture_jp(&flame_texlist);
    puff_draw_group(task, &puff_flame_sprite);
}

void puff_flame_destroy(struct task *task)
{
    FreeTaskC(task);
}

void puff_violet_smoke_step(struct task *task)
{
    puff_frames = SMOKE_FRAMES;
    LoopTaskC(task);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    SetMaterial(1.0F, 0.7F, 0.6F, 1.0F);
    njSetTexture_jp(&dust_texlist);
    puff_draw_group(task, &puff_smoke_sprite);
}

void puff_violet_smoke_destroy(struct task *task)
{
    FreeTaskC(task);
}

void mountain_puff_init(void)
{
    struct task *task;

    puff_smoke_sprite.p.x = 0.0F;
    puff_smoke_sprite.p.y = 0.0F;
    puff_smoke_sprite.p.z = 0.0F;
    puff_smoke_sprite.tlist = &dust_texlist;
    puff_smoke_sprite.tanim = puff_smoke_frames;
    puff_flame_sprite.p.x = 0.0F;
    puff_flame_sprite.p.y = 0.0F;
    puff_flame_sprite.p.z = 0.0F;
    puff_flame_sprite.tlist = &flame_texlist;
    puff_flame_sprite.tanim = puff_flame_frames;
    task = CreateElementalTask(0, 2, puff_smoke_step);
    task->destructor = puff_smoke_destroy;
    puff_groups[PUFF_SMOKE] = task;
    task = CreateElementalTask(0, 2, puff_dark_smoke_step);
    task->destructor = puff_dark_smoke_destroy;
    puff_groups[PUFF_DARK_SMOKE] = task;
    task = CreateElementalTask(0, 2, puff_flame_step);
    task->destructor = puff_flame_destroy;
    puff_groups[PUFF_FLAME] = task;
    task = CreateElementalTask(0, 2, puff_violet_smoke_step);
    task->destructor = puff_violet_smoke_destroy;
    puff_groups[PUFF_VIOLET_SMOKE] = task;
}

void puff_destroy(struct task *task)
{
    if (task->work != NULL) {
        Free(task->work);
        task->work = NULL;
    }
}

struct task *mountain_puff_create(int group, void (*step)(struct task *task))
{
    struct task *task = CreateChildTask(0, step, puff_groups[group]);
    void *work;

    if (task != NULL) {
        task->destructor = puff_destroy;
        /* @hack spelling: the work through a local, which copies it to R4 as
         * well, unused; stored directly, the function is 2 bytes shorter and 7
         * of 26 words differ */
        work = MAlloc(sizeof(struct mountain_puff));
        task->work = work;
    }
    return task;
}

int mountain_puff_frames(void)
{
    return puff_frames;
}

/* draw each of the group's puffs as sprite at its pos, scale and ang. the
 * sprite turns to face the camera */
void puff_draw_group(struct task *task, NJS_SPRITE *sprite)
{
    struct task *child = task->child;
    struct task *next;
    struct mountain_puff *puff;
    Angle ang;

    while (child != NULL) {
        next = child->next;
        /* @bug logic: the test reads the group's step, which is never null
         * while the group runs, so the test always holds. MOV.L @(16,R9),R2 at
         * 0x0c900390 reads it */
        if (task->step != NULL) {
            puff = (struct mountain_puff *)child->work;
            sprite->sx = puff->scale;
            sprite->sy = puff->scale;
            sprite->ang = puff->ang;
            njPushMatrix(NULL);
            njTranslateV(NULL, &puff->pos);
            TURN_VIA(njRotateY, camera_twp->ang.y, ang);
            TURN_VIA(njRotateX, camera_twp->ang.x, ang);
            njDrawSprite3D(sprite, (int)puff->frame,
                           NJD_SPRITE_ANGLE | NJD_SPRITE_COLOR |
                               NJD_SPRITE_ALPHA);
            late_DrawObjectClipEx(1);
        }
        child = next;
    }
}
