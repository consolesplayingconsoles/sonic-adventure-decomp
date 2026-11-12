/* @unit 0CB83360-0CB83620 +r04 +egflags +pool32 */
/* EV00B7.PRS's spotlights: a lamp whose beam sways from a random phase
 * until the script aims it at a point */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "draw/tree.h"
#include "ev00b7/spotlight.h"
#include "system/task.h"
#include "system/util.h"
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
void *syMalloc_default_malloc(size_t size);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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
#define TEXT_3_LENGTH 11
#define TEXT_4_LENGTH 10
#define TEXT_5_LENGTH 9

/* in order: SPOTLIGHT_AIM moves on to SPOTLIGHT_HOLD by mode++ */
#define VARS(work) ((struct spotlight_vars *)&(work)->vars)
enum spotlight_mode { SPOTLIGHT_SWAY, SPOTLIGHT_AIM, SPOTLIGHT_HOLD };

struct spotlight_vars {
    Uint8 unk_00[4];
    Sint32 phase; /* the sway's count of steps, from a random 0 to 999 */
};
extern NJS_TEXNAME ev00b7_spotlight_textures[5];
extern NJS_TEXLIST ev00b7_spotlight_texlist;
extern NJS_MATERIAL ev00b7_spotlight_lens_materials[1];
extern Sint16 ev00b7_spotlight_lens_meshes0[12];
extern NJS_COLOR ev00b7_spotlight_lens_uvs0[10];
extern NJS_MESHSET ev00b7_spotlight_lens_meshsets[1];
extern NJS_POINT3 ev00b7_spotlight_lens_points[7];
extern NJS_VECTOR ev00b7_spotlight_lens_normals[7];
extern NJS_MODEL ev00b7_spotlight_lens_model;
extern NJS_OBJECT ev00b7_spotlight_lens_object;
extern NJS_MATERIAL ev00b7_spotlight_beam_materials[1];
extern Sint16 ev00b7_spotlight_beam_meshes0[17];
extern NJS_COLOR ev00b7_spotlight_beam_uvs0[14];
extern NJS_MESHSET ev00b7_spotlight_beam_meshsets[1];
extern NJS_POINT3 ev00b7_spotlight_beam_points[9];
extern NJS_VECTOR ev00b7_spotlight_beam_normals[9];
extern NJS_MODEL ev00b7_spotlight_beam_model;
extern NJS_OBJECT ev00b7_spotlight_beam_object;
extern NJS_MATERIAL ev00b7_spotlight_materials[3];
extern Sint16 ev00b7_spotlight_meshes0[12];
extern Sint16 ev00b7_spotlight_meshes1[24];
extern Sint16 ev00b7_spotlight_meshes2[16];
extern Sint16 ev00b7_spotlight_meshes3[24];
extern NJS_COLOR ev00b7_spotlight_uvs0[10];
extern NJS_COLOR ev00b7_spotlight_uvs1[24];
extern NJS_COLOR ev00b7_spotlight_uvs2[12];
extern NJS_COLOR ev00b7_spotlight_uvs3[24];
extern NJS_MESHSET ev00b7_spotlight_meshsets[4];
extern NJS_POINT3 ev00b7_spotlight_points[19];
extern NJS_VECTOR ev00b7_spotlight_normals[19];
extern NJS_MODEL ev00b7_spotlight_model;
extern NJS_OBJECT ev00b7_spotlight_object;

void CTikalLight_Dest(struct task *task)
{
}

void ev00b7_spotlight_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    njSetTexture_jp(&ev00b7_spotlight_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y + 0x8000, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    njScale(NULL, 0.5F, 1.0F, 0.5F);
    late_DrawObject(&ev00b7_spotlight_object);
    late_DrawObjectClipEx(1);
}

void light_exec(struct task *task)
{
    struct task_work *work = task->work;
    Float x;
    Float y;
    Float z;

    switch (work->mode) {
    case SPOTLIGHT_SWAY:
        /* the beam tilts round an ellipse, up to 4608 about x and 4096
         * about z. each step moves it on by njSqrt(1088888.9), about 1043.5
         * of the 65536 a lap takes, so a lap lasts about 63 steps. its
         * heading turns by 1 a step */
        work->ang.x =
            (Angle)(njCos((Angle)(njSqrt(1088888.9F) * VARS(work)->phase)) *
                    4608.0F);
        work->ang.y = VARS(work)->phase;
        work->ang.z =
            (Angle)(njSin((Angle)(njSqrt(1088888.9F) * VARS(work)->phase)) *
                    4096.0F);
        VARS(work)->phase++;
        break;
    case SPOTLIGHT_AIM:
        x = work->scl.x - work->pos.x;
        y = work->scl.y - work->pos.y;
        z = work->scl.z - work->pos.z;
        work->ang.x = 0;
        work->ang.y = -(Angle)(njArcTan2(z, x) * ANGLE_PER_RADIAN);
        work->ang.z =
            (Angle)(njArcTan2(y, njSqrt((z * z) + (x * x))) * ANGLE_PER_RADIAN);
        work->mode++;
        break;
    case SPOTLIGHT_HOLD:
        break;
    }
    ev00b7_spotlight_draw(task);
}

void light_init(struct task *task)
{
    struct task_work *work = task->work;

    work->mode = SPOTLIGHT_SWAY;
    work->pos = work->scl;
    work->ang.x = 0;
    work->ang.y = 0;
    work->ang.z = 0;
    VARS(work)->phase = rand() * (1000 * RAND_SCALE);
    task->step = light_exec;
    task->draw = ev00b7_spotlight_draw;
    task->destructor = CTikalLight_Dest;
}

struct task *ev00b7_spotlight_create(Float x, Float y, Float z)
{
    struct task *task = CreateElementalTask(TASK_WORK, 5, light_init);
    struct task_work *work;

    if (task != NULL) {
        work = task->work;
        work->scl.x = x;
        work->scl.y = y;
        work->scl.z = z;
    }
    return task;
}

void ev00b7_spotlight_aim(struct task *task, Float x, Float y, Float z)
{
    struct task_work *work = task->work;

    work->scl.x = x;
    work->scl.y = y;
    work->scl.z = z;
    work->mode = SPOTLIGHT_AIM;
}

void ev00b7_spotlight_kill(struct task *task)
{
    if (task != NULL) {
        FreeTask(task);
        /* @hack redundant: the parameter cleared, which nothing reads, and
         * which keeps task_kill a call that saves PR (STS.L PR,@-R15 at
         * 0x0cb832fe); without it, task_kill becomes a tail jump, the code
         * runs 4 bytes short and 9 of the function's 9 words differ */
        task = NULL;
    }
}
