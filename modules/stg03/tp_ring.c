/* @unit 0C906900-0C906D60 +egflags +pool32 */
/* O TP RING ring that is also drawn in the mirrors */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "collision/ground.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "hud/hud.h"
#include "object/models.h"
#include "object/placement.h"
#include "object/ring.h"
#include "sound/sound.h"
#include "stg03/mirror.h"
#include "stg03/tp_ring.h"
#include "system/frame.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
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
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
Bool OnEdit(struct task *task);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
extern NJS_OBJECT object_shadow[];
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
void *syMalloc_default_malloc(size_t size);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
void OnConstantAttr(Uint32 and_attr, Uint32 or_attr);
void SaveControl3D(void);
void LoadControl3D(void);
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* the ring's turn a step */
#define RING_SPIN NJM_DEG_ANG(2)

/* a sparkle draws while its sprite frame is at least 0 and below SPARKLE_END.
 * a taken ring ends once sparkle 2's frame passes SPARKLE_END. each step adds
 * SPARKLE_SPEED to each sparkle's frame. at frame f, a sparkle's scale is f
 * times SPARKLE_SIZE. it draws SPARKLE_DROP times its scale below the ring's
 * position. each sparkle draws SPARKLE_SPACING further back in x and z than
 * the one before */
#define SPARKLE_END 7.0F
#define SPARKLE_SPEED 0.8F
#define SPARKLE_SIZE 0.05F
#define SPARKLE_DROP 3.0F
#define SPARKLE_SPACING 2.0F

/* the ring draws its shadow while work->tick is below SHADOW_TICKS */
#define SHADOW_TICKS 50

/* the steps until the ring looks for the ground again, or -1 for a ring that
 * doesn't look. init sets -1, which skips the countdown and its reset to
 * RING_PROBE_COUNT, so the ring never looks */
#define RING_PROBE_WAIT(work) ((work)->submode)
/* sparkles 1 and 2's frames. RING(work)->spin holds sparkle 0's */
#define SPARKLE_1_FRAME(work) ((work)->scl.x)
#define SPARKLE_2_FRAME(work) ((work)->scl.z)
/* the height of the ground below the ring, or -GROUND_FAR for none */
#define RING_GROUND(work) ((work)->scl.y)

void dispTPRing(struct task *task);
void tp_ring_draw_sparkle(struct task_work *work);
void tp_ring_sprite_init(struct task_work *work, NJS_SPRITE *sprite);
void tp_ring_destroy(struct task *task);
extern NJS_TEXANIM tp_ring_texanims[8];
extern struct collision_shape tp_ring_shape;
extern NJS_SPRITE tp_ring_sprite;

/* outside the set editor the ring spins, and a hit takes it. a taken ring adds
 * one to the rings, plays SE_RING and starts its sparkles. until then, the ring
 * steps its reflection child, which draws it in the mirrors */
void ObjectTPRing(struct task *task)
{
    struct task_work *work = task->work;
    Float height;
    Float rise;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case RING_INIT:
        CCL_Init(task, &tp_ring_shape, COLLISION_RING, 1, 1);
        RING_PROBE_WAIT(work) = -1;
        RING_GROUND(work) =
            GetShadowPos(work->pos.x, work->pos.y, work->pos.z, &work->ang);
        work->mode = RING_WAIT;
        RING(work)->spin = 0.0F;
        SPARKLE_1_FRAME(work) = -2.0F;
        SPARKLE_2_FRAME(work) = -4.0F;
        work->id = RING_ID;
        task->destructor = tp_ring_destroy;
        task->draw = dispTPRing;
        tp_ring_sprite_init(work, &tp_ring_sprite);
        createMirrorTask(task);
        break;
    case RING_WAIT:
        if (edit_mode == 0) {
            if (work->collision->flags & COLLISION_HIT) {
                work->mode = RING_SPARKLE;
                ring_add(1);
                dsPlay_oneshot(SE_RING, 0, 0, 0);
            }
            EntryColliList(work);
            work->ang.y += RING_SPIN;
        }
        if (RING_PROBE_WAIT(work) >= 0) {
            RING_PROBE_WAIT(work)--;
            if (RING_PROBE_WAIT(work) == -1) {
                RING_PROBE_WAIT(work) = RING_PROBE_COUNT;
                height = GetShadowPos(work->pos.x, work->pos.y, work->pos.z,
                                      &work->ang);
                rise = height - RING_GROUND(work);
                RING_GROUND(work) = height;
                work->pos.y += rise;
            }
        }
        dispTPRing(task);
        LoopTaskC(task);
        break;
    case RING_SPARKLE:
        tp_ring_draw_sparkle(work);
        break;
    case RING_DONE:
        DeadOut(task);
        break;
    }
}

/* on a frame's first step, draw the ring, with NJD_FLAG_IGNORE_SPECULAR
 * cleared from the attributes Ninja forces on. its shadow draws first, at
 * RING_GROUND unless that is -GROUND_FAR. this file never sets work->tick, so
 * the shadow's SHADOW_TICKS test always holds */
void dispTPRing(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    if (loop_count != 0) {
        return;
    }
    if (work->tick < SHADOW_TICKS) {
        if (RING_GROUND(work) != -GROUND_FAR) {
            shadow_draw_at_height(work, RING_GROUND(work));
        }
    }
    SaveConstantAttr();
    OffConstantAttr(0, NJD_FLAG_IGNORE_SPECULAR);
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(&model_obj_ring_ring);
    late_DrawObjectClipEx(1);
    LoadConstantAttr();
}

/* advance and draw a taken ring's sparkles 0 to 2. each runs two sprite
 * frames behind the one before. once sparkle 2's frame passes SPARKLE_END, set
 * the mode to RING_DONE */
void tp_ring_draw_sparkle(struct task_work *work)
{
    Float size;
    Float scale;
    int frame[3];

    int i;
    Angle ang;

    RING(work)->spin += SPARKLE_SPEED;
    SPARKLE_1_FRAME(work) += SPARKLE_SPEED;
    SPARKLE_2_FRAME(work) += SPARKLE_SPEED;
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    njSetTexture_jp(&ring_texlist);
    frame[0] = RING(work)->spin;
    frame[1] = SPARKLE_1_FRAME(work);
    frame[2] = SPARKLE_2_FRAME(work);
    for (i = 0; i < 3; i++) {
        if (frame[i] < SPARKLE_END && frame[i] >= 0) {
            size = frame[i] * SPARKLE_SIZE;
            scale = _builtin_fabsf(frame[i] * SPARKLE_SIZE);
            njPushMatrix(NULL);
            njTranslate(NULL, work->pos.x - (i * SPARKLE_SPACING),
                        work->pos.y - (size * SPARKLE_DROP),
                        work->pos.z - (i * SPARKLE_SPACING));
            TURN_VIA(njRotateY, camera_twp->ang.y, ang);
            TURN_VIA(njRotateX, camera_twp->ang.x, ang);
            njScale(NULL, scale, scale, scale);
            njDrawSprite3D(&tp_ring_sprite, frame[i],
                           NJD_SPRITE_ALPHA | NJD_SPRITE_VFLIP |
                               NJD_SPRITE_ANGLE);
            late_DrawObjectClipEx(1);
        }
    }
    if (frame[2] > SPARKLE_END) {
        work->mode = RING_DONE;
    }
}

/* set sprite up to draw the sparkle's frames at a scale of 1 */
void tp_ring_sprite_init(struct task_work *work, NJS_SPRITE *sprite)
{
    sprite->tlist = &ring_texlist;
    sprite->tanim = tp_ring_texanims;
    sprite->sx = 1.0F;
    sprite->sy = 1.0F;
    sprite->p.x = sprite->p.y = sprite->p.z = 0.0F;
}

void tp_ring_destroy(struct task *task)
{
}
