/* @unit 0C901800-0C902240 @data 0C910A70-0C910AD8 +r04 +egflags +pool32 */
/* O DOLPHIN, a dolphin that leaps from the sea, and O DOLSW, a switch that
 * calls dolphins */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "hud/hud.h"
#include "object/placement.h"
#include "sound/sound.h"
#include "stg01/dolphin.h"
#include "stg01/spray.h"
#include "stg01/water_column.h"
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
void *syMalloc_default_malloc(size_t size);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
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
void FUN_0c901a28(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

#define LEAVE_RANGE (1800.0F * 1800.0F)
#define SWITCH_REACH 14.0F
#define SE_DOLPHIN_SWITCH 48
#define LEAP_SPEED 2.7F
#define ARC_STEP (64.0F / 360.0F)
#define ARC_GRAVITY 0.035F
#define ARC_TOP 17.0F
#define SPRAY_STEPS 80
#define SPRAY_GAP 3.0F
#define SPRAY_DROPS 4
#define MIST_DROP 1
#define MIST_AFTER 10
#define MIST_BEFORE 30
#define VARS(work) ((struct dolphin_vars *)&(work)->vars)
extern NJS_OBJECT dolphin_object;
/* @hack type: declared an array, not the one NJS_MOTION it is, so SHC pools
 * its address and reads nbFrame through it, MOV.L @(4,R3),R2 at 0x0c901a4a;
 * declared as one, 5 of dolphin_draw's 84 words differ */
extern NJS_MOTION dolphin_motion;
extern NJS_MOTION dolphin_leap_a_motion;
extern NJS_MOTION dolphin_leap_a_shape;
extern NJS_MOTION dolphin_leap_b_motion;
extern NJS_MOTION dolphin_leap_b_shape;

/* the dolphin destroys itself once the camera and player 0 are both beyond
 * 1800 of it. it stays while player 1 is Sonic within 40 of it. the range is
 * squared, as placement_try_leave_by takes it */

/* a switch's sphere has a radius of SWITCH_REACH times one more than its
 * scale x */

/* each step of a leap, the dolphin runs LEAP_SPEED along its heading. the
 * arc's time, VARS(work)->frame, gains ARC_STEP. the dolphin then rises
 * ARC_GRAVITY * time * (ARC_TOP - time). it climbs until the time passes
 * ARC_TOP, and falls after */
/* while its timer is below SPRAY_STEPS, a leaping dolphin throws spray from
 * around its head. a burst of SPRAY_DROPS drops comes once extra->spray
 * passes SPRAY_GAP. drop MIST_DROP of a burst after step MIST_AFTER and
 * before step MIST_BEFORE trails mist */

/* the dolphin's work->vars */
struct dolphin_vars {
    Float frame; /* the arc's time, and the leap's frame */
    Uint16 unk_04; /* the init clears it, and nothing reads it */
};

struct dolphin_extra {
    NJS_POINT3 home; /* where the dolphin waits, and returns to */
    Float spray; /* the leap's steps since its last spray */
};

enum dolphin_mode { DOLPHIN_INIT, DOLPHIN_WAIT, DOLPHIN_LEAP, DOLPHIN_END };

/* SWITCH_END's case kills the switch, but no code sets the mode to it */
enum switch_mode { SWITCH_INIT = 0, SWITCH_RUN = 2, SWITCH_END = 3 };
extern Uint8 dolphin_switch_id;
extern Float dolphin_switch_count;
extern struct collision_shape dolphin_switch_shape;

void dolphin_destroy(struct task *task);
void dolphin_draw(struct task *task);
void Jump2(struct task *task);
void dolphin_switch_destroy(struct task *task);

/* the dolphin's step. it waits at home until its switch calls it, then
 * leaps once. at the leap's end, the dolphin destroys itself, and its
 * placement makes no more until placement_reset */
void ObjectBeachDolphin(struct task *task)
{
    struct task_work *work = task->work;
    struct dolphin_extra *extra = task->extra;

    if (CheckRangeOutWithR(task, LEAVE_RANGE)) {
        return;
    }
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<-ID_NUMBER");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "<-ID");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "<-MOTION -A +B");
    }
    if (OnEdit(task) || edit_mode == 1) {
        dolphin_draw(task);
    }
    switch (work->mode) {
    case DOLPHIN_INIT:
        task->destructor = dolphin_destroy;
        task->draw = dolphin_draw;
        VARS(work)->unk_04 = 0;
        extra->home.y = work->pos.y;
        extra->home.x = work->pos.x;
        extra->home.z = work->pos.z;
        work->mode = DOLPHIN_WAIT;
        break;
    case DOLPHIN_WAIT:
        if ((Uint8)work->scl.y == dolphin_switch_id &&
            (Uint8)work->scl.x < dolphin_switch_count) {
            work->mode = DOLPHIN_LEAP;
        }
        work->timer = 0;
        VARS(work)->frame = 8.0F;
        break;
    case DOLPHIN_LEAP:
        if (!OnEdit(task)) {
            Jump2(task);
        }
        dolphin_draw(task);
        break;
    case DOLPHIN_END:
        DeadOut(task);
        break;
    }
}

void dolphin_destroy(struct task *task)
{
}

/* draw the dolphin at its leap's frame. the frame wraps to 0 at
 * dolphin_motion's last frame, for either leap */
void dolphin_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    if (((struct dolphin_vars *)&(work)->vars)->frame >=
        dolphin_motion.nbFrame - 1) {
        ((struct dolphin_vars *)&(work)->vars)->frame = 0.0F;
    }
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    if (work->scl.z < 0.0F) {
        draw_shape_motion(&dolphin_object, &dolphin_leap_a_motion,
                          &dolphin_leap_a_shape, VARS(work)->frame);
    } else {
        draw_shape_motion(&dolphin_object, &dolphin_leap_b_motion,
                          &dolphin_leap_b_shape, VARS(work)->frame);
    }
    late_DrawObjectClipEx(1);
}

/* the switch's step. a hit makes it the switch hit last, in
 * dolphin_switch_id and dolphin_switch_count. a hit reads the time too, and
 * drops it */
void FUN_0c901a28(struct task *task)
{
    /* no code reads it, though the image's constants hold it */
    static const NJS_VECTOR dolphin_switch_up = {0.0F, 1.0F, 0.0F};
    struct task_work *work = task->work;
    Uint8 minutes;
    Uint8 seconds;
    /* @hack type: a vector for the marker's scale, of which only x is used,
     * which gives the frame 20 bytes (ADD #-20,R15 at 0x0c901af0); as one
     * Float, 88 of 158 words differ */
    NJS_VECTOR scale;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case SWITCH_INIT:
        task->destructor = dolphin_switch_destroy;
        CCL_Init(task, &dolphin_switch_shape, COLLISION_OBJECT, 1, 1);
        work->mode = SWITCH_RUN;
        break;
    case SWITCH_RUN:
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "<- ID");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- SCALE");
        }
        work->collision->shapes->radius = (work->scl.x + 1.0F) * SWITCH_REACH;
        if (OnEdit(task) || edit_mode == 1) {
            scale.x = work->scl.x + 1.0F;
            njPushMatrix(NULL);
            njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
            njScale(NULL, scale.x, scale.x, scale.x);
            late_DrawObject(&object_sphere01);
            late_DrawObjectClipEx(1);
        }
        if (work->collision->flags & COLLISION_HIT) {
            work->collision->flags &= ~COLLISION_HIT;
            dolphin_switch_id = (Uint8)work->scl.y;
            time_get_whole(&minutes, &seconds);
            dolphin_switch_count = (Uint8)work->scl.z;
            dsPlay_oneshot(SE_DOLPHIN_SWITCH, 0, 0, 0);
            /* @hack spelling: a break in each arm, which gives each arm its own
             * BRA to the exit (0x0c901c70, 0x0c901c7a); with one break after
             * the if, 4 of 158 words differ */
            break;
        } else {
            EntryColliList(work);
            break;
        }
    case SWITCH_END:
        FreeTask(task);
        break;
    }
}

/* a step of the leap. its first step raises a water column. once the
 * dolphin falls below home, another column rises, and the dolphin goes home
 * and ends its leap */
void Jump2(struct task *task)
{
    /* where the spray starts, before the turn to the dolphin's heading */
    static const NJS_VECTOR dolphin_ahead = {0.0F, 7.0F, 13.0F};
    static const NJS_VECTOR dolphin_splash_speed = {0.0F, 1.0F, 0.0F};
    static const NJS_VECTOR dolphin_fall_speed = {0.0F, 1.0F, 0.0F};
    struct task_work *work = task->work;
    struct dolphin_extra *extra = task->extra;
    NJS_VECTOR ahead;
    NJS_VECTOR offset;
    NJS_VECTOR speed;
    NJS_POINT3 pos;
    Angle ang;
    int i;
    struct task *child;
    struct task_work *spray;
    Float random;
    Float frame;
    Float gravity;
    Float rise;

    ahead = dolphin_ahead;
    njPushMatrix(&nj_unit_matrix_);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njCalcVector(NULL, &ahead, &offset);
    late_DrawObjectClipEx(1);
    /* @hack redundant: a never-run store of the step to frame, which makes the
     * step load before the frame, as in the image, and keeps the function 2
     * bytes shorter; without it, 631 of 681 words differ */
    if (0) {
        VARS(work)->frame = ARC_STEP;
    }
    VARS(work)->frame += ARC_STEP;
    gravity = ARC_GRAVITY;
    frame = VARS(work)->frame;
    rise = frame * gravity;
    /* @hack redundant: a never-run store of frame to rise, which gives rise its
     * register before gravity, as in the image; without it, 7 of 681 words
     * differ */
    if (0) {
        rise = frame;
    }
    work->pos.y += (rise * ARC_TOP) - (frame * frame * gravity);
    work->pos.x += njSin(work->ang.y) * LEAP_SPEED;
    work->pos.z += njCos(work->ang.y) * LEAP_SPEED;
    TASK_TIMER(work)++;
    /* a column on the first step alone */
    /* @hack redundant: the test against 5 (CMP/GE at 0x0c901dd8) always holds
     * once the test against 2 has; without it, 571 of 681 words differ */
    /* NOLINTNEXTLINE(misc-redundant-expression) */
    if (TASK_TIMER(work) < 2 && TASK_TIMER(work) < 5) {
        speed = dolphin_splash_speed;
        pos = work->pos;
        pos.x +=
            njSin((Angle)(TASK_TIMER(work) * 30 * ANGLE_PER_DEGREE)) * 4.0F;
        pos.y += 3.0F;
        pos.z +=
            njCos((Angle)(TASK_TIMER(work) * 30 * ANGLE_PER_DEGREE)) * 4.0F;
        CreateBeachWatertube(&pos, &speed, 0.25F);
    }
    if (TASK_TIMER(work) < SPRAY_STEPS) {
        extra->spray += 1.0F;
        if (extra->spray > SPRAY_GAP) {
            for (i = 0; i < SPRAY_DROPS; i++) {
                if ((child = CreateElementalTask(TASK_WORK, 2,
                                                 EffectBeachDrop)) != NULL) {
                    spray = child->work;
                    random = rand() * RAND_SCALE;
                    spray->pos.x =
                        work->pos.x + offset.x -
                        (njSin(ang = (Angle)(random *
                                             (360.0F * ANGLE_PER_DEGREE))) *
                         10.0F);
                    spray->pos.y = work->pos.y + offset.y;
                    spray->pos.z =
                        work->pos.z + offset.z + (njCos(ang) * 10.0F);
                    spray->scl.x = random + 1.0F;
                    SPRAY_VARS(spray)->speed_x =
                        njSin(work->ang.y + ang) * 0.8F;
                    SPRAY_VARS(spray)->speed_y = random;
                    SPRAY_VARS(spray)->speed_z =
                        -njCos(work->ang.y + ang) * 0.8F;
                    if (i == MIST_DROP && TASK_TIMER(work) > MIST_AFTER &&
                        TASK_TIMER(work) < MIST_BEFORE) {
                        spray->scl.z = -1.0F;
                    }
                }
            }
            extra->spray = 0.0F;
        }
    }
    if (extra->home.y > work->pos.y) {
        speed = dolphin_fall_speed;
        pos = work->pos;
        pos.y += 12.0F;
        CreateBeachWatertube(&pos, &speed, 0.25F);
        work->pos.x = extra->home.x;
        work->pos.y = extra->home.y;
        work->pos.z = extra->home.z;
        work->mode = DOLPHIN_END;
    }
}

void dolphin_switch_destroy(struct task *task)
{
}
