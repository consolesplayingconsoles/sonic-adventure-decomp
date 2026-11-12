/* @unit 0C909B40-0C909F20 @data 0C910C3C-0C910C54 +r04 +egflags +pool32 */
/* O PO SUMMON's path orca, which leaps in and out of the sea along
 * path_orca_path */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/draw.h"
#include "path/path.h"
#include "sound/sound.h"
#include "stg01/orca_control.h"
#include "stg01/path_orca.h"
#include "stg01/sea.h"
#include "stg01/water_column.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
#include "vmu/vibration.h"
float njArcTan2(float y, float x);
float njFloor(float x);
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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
extern struct task *OrukaTask;
void orInitOrukaSequence(void);
Bool orCreateAttackOruka(Float x, Float y, Float z, Angle ang);
void FUN_0c90878c(Float x, Float z, Float radius, Float width, Float height);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

#define VARS(work) ((struct path_orca_vars *)&(work)->vars)
#define SPEED_MAX 4.0F
#define SPEED_GAIN 0.1F
#define FRAME_SPEED 0.1F
#define FRAMES 30.0F
#define START_DISTANCE 330.0F
#define HEADING_BACK 200.0F
#define TILT_BACK 100.0F
#define MODEL_BACK 160.0F
#define SE_ORCA_SPLASH 47
extern NJS_OBJECT orca_object;
extern NJS_MOTION orca_swim_motion;
extern NJS_MOTION orca_swim_shape;
extern NJS_MOTION path_orca_leap_motion;
extern NJS_MOTION path_orca_leap_shape;
extern struct path path_orca_path;

struct path_orca_vars {
    Float frame; /* both motions' frame, from 0 up to FRAMES */
    Float distance; /* the orca's distance along the path */
    Float speed; /* how far the orca moves along the path each step */
};

enum path_orca_mode {
    PATH_ORCA_UNDER = 0,
    PATH_ORCA_RISE = 1,
    PATH_ORCA_FALL = 2,
    PATH_ORCA_END = 6 /* past the path's end, where the step kills the task */
};

/* the orca always moves SPEED_MAX along the path: it starts there, and
 * nothing lowers its speed. the step's regain of SPEED_GAIN a step under the
 * sea, for a speed below SPEED_MAX, never applies */
/* both motions advance FRAME_SPEED frames a step, and wrap at FRAMES */

/* the orca starts START_DISTANCE along the path */
/* the orca heads away from the path's point HEADING_BACK behind it. it tilts
 * as the path does TILT_BACK behind it */
/* the orca's model is drawn MODEL_BACK behind its position, along its
 * heading */

/* sound of the orca leaving and entering the sea */

/* speeds for the water columns the orca throws up leaving the sea and falling
 * back in. no column moves by them */
static const NJS_VECTOR path_orca_rise_splash_speed = {1.0F, 1.0F, 1.0F};
static const NJS_VECTOR path_orca_fall_splash_speed = {1.0F, 1.0F, 1.0F};

void o_beach_pathoruka_Exec(struct task *task);
void path_orca_draw(struct task *task);
void Destructor(struct task *task);

/* start the orca rising, at full speed. it sets submode 4, which nothing
 * reads */
void ObjectBeachPathoruka(struct task *task)
{
    struct task_work *work = task->work;

    work->ang.y = 0;
    work->ang.x = 0;
    work->ang.z = 0;
    VARS(work)->frame = 0.0F;
    VARS(work)->distance = START_DISTANCE;
    VARS(work)->speed = SPEED_MAX;
    work->mode = PATH_ORCA_RISE;
    work->submode = 4;
    /* @hack redundant: a test of placement_editing's result that does nothing,
     * which keeps the image's TST R0,R0 at 0x0c90a076. as a bare call, the
     * function runs 2 bytes short and 13 of 36 words differ */
    if (!OnEdit(task)) {
    }
    task->step = o_beach_pathoruka_Exec;
    task->draw = path_orca_draw;
    task->destructor = Destructor;
}

/* move the orca along the path by its speed. kill the task once the orca
 * passes the path's end. a rising orca falls once it is no higher than the
 * point HEADING_BACK behind it. crossing the sea's surface either way throws up
 * a water column, ripples the sea and plays SE_ORCA_SPLASH. leaving the sea
 * also shakes pad 0 */
void o_beach_pathoruka_Exec(struct task *task)
{
    struct task_work *work = task->work;
    struct path *path = &path_orca_path;
    Float distance;
    Float length;
    Float y;
    Float back_y;

    distance = VARS(work)->distance;
    distance += VARS(work)->speed;
    length = path->length;
    if (distance >= length) {
        work->mode = PATH_ORCA_END;
    } else {
        struct GetStatusOnPath samples[3];
        Float *at;
        Float x;
        Float z;
        Float back_x;
        Float back_z;

        samples[0].distance = distance;
        samples[1].distance = distance - HEADING_BACK;
        samples[2].distance = distance - TILT_BACK;
        GetStatusOnPath(path, &samples[0]);
        GetStatusOnPath(path, &samples[1]);
        GetStatusOnPath(path, &samples[2]);
        /* @hack spelling: the positions read through a Float cursor, for the
         * image's post-increment loads (0x0c90a142 to 0x0c90a156). through
         * the members, 73 of 262 words differ */
        at = &samples[0].pos_copy.x;
        x = *at++;
        y = *at++;
        z = *at++;
        at = &samples[1].pos_copy.x;
        back_x = *at++;
        back_y = *at++;
        back_z = *at++;
        work->pos.x = x;
        work->pos.y = y;
        work->pos.z = z;
        work->ang.x = samples[2].smooth_x;
        work->ang.z = samples[2].smooth_z;
        work->ang.y =
            (Angle)(njArcTan2(x - back_x, z - back_z) * ANGLE_PER_RADIAN);
        VARS(work)->distance = distance;
    }
    switch (work->mode) {
    case PATH_ORCA_UNDER:
        if (work->pos.y > SEA_LEVEL) {
            NJS_VECTOR speed;

            work->mode = PATH_ORCA_RISE;
            speed = path_orca_rise_splash_speed;
            CreateBeachWatertube(&work->pos, &speed, 1.0F);
            vibration_start_fading(0, 7, 59, 6);
            FUN_0c90878c(work->pos.x, work->pos.z, 0.0F, 8.0F, 20.0F);
            dsPlay_oneshot(SE_ORCA_SPLASH, 0, 0, 0);
        } else if (VARS(work)->speed < SPEED_MAX) {
            VARS(work)->speed += SPEED_GAIN;
        }
        break;
    case PATH_ORCA_RISE:
        if (y > back_y) {
            break;
        }
        work->mode = PATH_ORCA_FALL;
        break;
    case PATH_ORCA_FALL:
        if (work->pos.y < SEA_LEVEL) {
            NJS_VECTOR speed;

            work->mode = PATH_ORCA_UNDER;
            speed = path_orca_fall_splash_speed;
            CreateBeachWatertube(&work->pos, &speed, 1.0F);
            FUN_0c90878c(work->pos.x, work->pos.z, 0.0F, 8.0F, 20.0F);
            dsPlay_oneshot(SE_ORCA_SPLASH, 0, 0, 0);
        } else if (VARS(work)->speed < SPEED_MAX) {
            /* @hack redundant: a test of the speed that does nothing, which
             * keeps the image's FCMP/GT at 0x0c90a2d8. without it, the
             * function runs 32 bytes long and 139 of 262 words differ */
        }
        break;
    case PATH_ORCA_END:
        FreeTask(task);
        break;
    }
    VARS(work)->frame += FRAME_SPEED;
    if (VARS(work)->frame >= FRAMES) {
        VARS(work)->frame -= FRAMES;
    }
    path_orca_draw(task);
}

/* draw the orca swimming under the sea, and leaping above it */
void path_orca_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njTranslate(NULL, 0.0F, 0.0F, -MODEL_BACK);
    if (work->mode == PATH_ORCA_UNDER) {
        draw_shape_motion(&orca_object, &orca_swim_motion, &orca_swim_shape,
                          VARS(work)->frame);
    } else {
        draw_shape_motion(&orca_object, &path_orca_leap_motion,
                          &path_orca_leap_shape, VARS(work)->frame);
    }
    late_DrawObjectClipEx(1);
}

/* make the controller forget the orca, and stop pad 0's vibration */
void Destructor(struct task *task)
{
    orFreePathOruka(task);
    VibShot(0, 0, 0, 0);
}
