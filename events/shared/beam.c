/* @unit 0CB810E0-0CB81460 +r04 +egflags +pool32 +poolafter=capturebeam_exec */
/* an event's capture beam: a cone of light that spins about its y while it
 * opens or closes */
#define TEXT_1 ""
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/tree.h"
#include "shared/beam.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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

#define TEXT_1_LENGTH 11
#define VARS(work) ((struct beam_vars *)&(work)->vars)
#define BEAM(task) ((struct beam_motion *)(task)->motion)
struct beam_vars {
    Uint32 spin; /* the angle it has turned about its y, below a turn */
};

/* the beam's shape and the speeds of its widths. the beam keeps them in
 * task->motion, the record TASK_MOTION allocates, in place of a struct
 * task_motion */
struct beam_motion {
    Uint8 unk_00[4];
    Float speed_x; /* how far scl.x moves each step it opens or closes */
    Uint8 unk_08[4];
    Float speed_z; /* how far scl.z moves each step it opens or closes */
    Float open_accel; /* added to both speeds each step it opens */
    Float close_accel; /* added to both speeds each step it closes */
    Float spin_speed; /* added to its spin each step it opens or closes */
    Uint8 unk_1c[24];
    Float width_x; /* the scl.x it opens to */
    Float width_z; /* the scl.z it opens to */
    Uint8 unk_3c[4];
};
extern NJS_TEXNAME event_beam_texnames[1];
extern NJS_TEXLIST event_beam_texlist;
extern NJS_MATERIAL event_beam_materials[1];
extern Sint16 event_beam_meshes[88];
extern NJS_COLOR event_beam_uvs[80];
extern NJS_MESHSET event_beam_meshsets[1];
extern NJS_POINT3 event_beam_points[40];
extern NJS_VECTOR event_beam_normals[40];
extern NJS_MODEL event_beam_cone_model;
extern NJS_OBJECT event_beam_cone;
extern NJS_OBJECT event_beam_object;
extern NJS_MDATA2 event_beam_mdata[2];
extern NJS_MOTION event_beam_motion;
extern NJS_ACTION event_beam_action;

void capturebeam_dest(struct task *task)
{
}

void capturebeam_disp(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    njSetTexture_jp(&event_beam_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    if (VARS(work)->spin != 0) {
        njRotateY(NULL, VARS(work)->spin);
    }
    /* @hack redundant: the height plus 0, which keeps the image's FLDI0 and
     * FADD (0x0cb81074 and 0x0cb81080 in EV0009); without it, the draw runs
     * 4 bytes short and 24 of 68 words differ */
    njScale(NULL, work->scl.x, work->scl.y + 0.0F, work->scl.z);
    late_DrawObject(&event_beam_object);
    late_DrawObjectClipEx(1);
}

void capturebeam_exec(struct task *task)
{
    switch (task->work->mode) {
    case BEAM_STILL:
        break;
    case BEAM_OPEN:
        VARS(task->work)->spin += BEAM(task)->spin_speed;
        VARS(task->work)->spin &= 0xffff;
        BEAM(task)->speed_x += BEAM(task)->open_accel;
        BEAM(task)->speed_z += BEAM(task)->open_accel;
        task->work->scl.x += BEAM(task)->speed_x;
        task->work->scl.z += BEAM(task)->speed_z;
        if (task->work->scl.x > BEAM(task)->width_x) {
            task->work->scl.x = BEAM(task)->width_x;
        }
        if (task->work->scl.z > BEAM(task)->width_z) {
            task->work->scl.z = BEAM(task)->width_z;
        }
        break;
    case BEAM_CLOSE:
        VARS(task->work)->spin += BEAM(task)->spin_speed;
        VARS(task->work)->spin &= 0xffff;
        BEAM(task)->speed_x += BEAM(task)->close_accel;
        BEAM(task)->speed_z += BEAM(task)->close_accel;
        task->work->scl.x -= BEAM(task)->speed_x;
        task->work->scl.z -= BEAM(task)->speed_z;
        if (task->work->scl.x < 0.0F) {
            task->work->scl.x = 0.0F;
        }
        if (task->work->scl.z < 0.0F) {
            task->work->scl.z = 0.0F;
        }
        break;
    }
    capturebeam_disp(task);
}

void capturebeam_init(struct task *task)
{
    task->work->scl.x = 0.0F;
    task->work->scl.y = 1.0F;
    task->work->scl.z = 0.0F;
    task->work->tick = 0;
    VARS(task->work)->spin = 0;
    BEAM(task)->speed_x = 0.0F;
    BEAM(task)->speed_z = 0.0F;
    BEAM(task)->open_accel = 0.01F;
    BEAM(task)->close_accel = 0.01F;
    BEAM(task)->spin_speed = 768.0F;
    BEAM(task)->width_x = 1.0F;
    BEAM(task)->width_z = 1.0F;
    task->work->mode = BEAM_STILL;
    task->step = capturebeam_exec;
    task->draw = capturebeam_disp;
    task->destructor = capturebeam_dest;
}

struct task *event_beam_create(Float x, Float y, Float z, Angle ang_x,
                               Angle ang_y, Angle ang_z)
{
    struct task *task =
        CreateElementalTask(TASK_MOTION | TASK_WORK, 5, capturebeam_init);

    if (task != NULL) {
        task->work->pos.x = x;
        task->work->pos.y = y;
        task->work->pos.z = z;
        task->work->ang.x = ang_x;
        task->work->ang.y = ang_y;
        task->work->ang.z = ang_z;
        return task;
    }
    return NULL;
}

void event_beam_kill(struct task *task)
{
    if (task != NULL) {
        FreeTask(task);
    }
}

void event_beam_set_mode(struct task *task, enum beam_mode mode)
{
    task->work->mode = mode;
    BEAM(task)->speed_x = 0.0F;
    BEAM(task)->speed_z = 0.0F;
}

void event_beam_set_shape(struct task *task, Float width_x, Float height,
                          Float width_z, Float open_accel, Float close_accel,
                          int spin_speed)
{
    if (width_x > 0.0F) {
        BEAM(task)->width_x = width_x;
    }
    if (height > 0.0F) {
        task->work->scl.y = height;
    }
    if (width_z > 0.0F) {
        BEAM(task)->width_z = width_z;
    }
    if (open_accel > 0.0F) {
        BEAM(task)->open_accel = open_accel;
    }
    if (close_accel > 0.0F) {
        BEAM(task)->close_accel = close_accel;
    }
    if (spin_speed > 0) {
        BEAM(task)->spin_speed = (Float)spin_speed;
    }
}
