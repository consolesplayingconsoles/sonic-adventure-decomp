/* @unit 0C9058A0-0C905C20 +r04 +egflags +pool32 */
/* Chaos 6's debris: pieces thrown out and up from round the boss. each
 * tumbles as it falls, and its task ends once it drops below the deck */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "b_chaos6/boss.h"
#include "b_chaos6/debris.h"
#include "b_chaos6/textures.h"
#include "draw/motion.h"
#include "draw/tree.h"
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
void *syMalloc_default_malloc(size_t size);
extern Sint8 chaos_reqmode;
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

/* debris_pieces holds two sets of pieces. chaos6_debris_scatter's kind 0
 * throws the last four, and every other kind the first three */
#define FIRST_PIECES 3
#define LAST_PIECES 4
#define PIECES (FIRST_PIECES + LAST_PIECES)

/* how far a piece turns about x and about z a step */
#define DEBRIS_SPIN 512
/* how much a piece's upward speed drops a step: 9.8 / 360, written as a
 * decimal. SHC folds 9.8F / 360.0F to 0x3cdf0122, one below the image's
 * 0x3cdf0123 */
#define DEBRIS_FALL 0.027222222F
/* the deck's height. a piece's task kills itself once the piece is below
 * it */
#define DEBRIS_BOTTOM 744.0F

#define VARS(work) ((struct debris_vars *)&(work)->vars)
struct debris_vars {
    Uint8 unk_00[4];
    Sint8 piece; /* its index in debris_pieces */
};
extern Float debris_speed;
extern Angle debris_tilt;
extern Sint32 dat_0c900338;
extern Float debris_reach;
extern Float debris_height;
extern NJS_MATERIAL chaos6_debris_0_materials[1];
extern Sint16 chaos6_debris_0_meshes0[64];
extern NJS_COLOR chaos6_debris_0_uvs0[48];
extern NJS_MESHSET chaos6_debris_0_meshsets[1];
extern NJS_POINT3 chaos6_debris_0_points[10];
extern NJS_VECTOR chaos6_debris_0_normals[10];
extern NJS_MODEL chaos6_debris_0_model;
extern NJS_OBJECT chaos6_debris_0_object;
extern NJS_MATERIAL chaos6_debris_1_materials[1];
extern Sint16 chaos6_debris_1_meshes0[96];
extern NJS_COLOR chaos6_debris_1_uvs0[72];
extern NJS_MESHSET chaos6_debris_1_meshsets[1];
extern NJS_POINT3 chaos6_debris_1_points[14];
extern NJS_VECTOR chaos6_debris_1_normals[14];
extern NJS_MODEL chaos6_debris_1_model;
extern NJS_OBJECT chaos6_debris_1_object;
extern NJS_MATERIAL chaos6_debris_2_materials[1];
extern Sint16 chaos6_debris_2_meshes0[96];
extern NJS_COLOR chaos6_debris_2_uvs0[72];
extern NJS_MESHSET chaos6_debris_2_meshsets[1];
extern NJS_POINT3 chaos6_debris_2_points[14];
extern NJS_VECTOR chaos6_debris_2_normals[14];
extern NJS_MODEL chaos6_debris_2_model;
extern NJS_OBJECT chaos6_debris_2_object;
extern NJS_MATERIAL chaos6_debris_3_materials[1];
extern Sint16 chaos6_debris_3_meshes0[76];
extern NJS_COLOR chaos6_debris_3_uvs0[57];
extern NJS_MESHSET chaos6_debris_3_meshsets[1];
extern NJS_POINT3 chaos6_debris_3_points[16];
extern NJS_VECTOR chaos6_debris_3_normals[16];
extern NJS_MODEL chaos6_debris_3_model;
extern NJS_OBJECT chaos6_debris_3_object;
extern NJS_MATERIAL chaos6_debris_4_materials[1];
extern Sint16 chaos6_debris_4_meshes0[60];
extern NJS_COLOR chaos6_debris_4_uvs0[45];
extern NJS_MESHSET chaos6_debris_4_meshsets[1];
extern NJS_POINT3 chaos6_debris_4_points[13];
extern NJS_VECTOR chaos6_debris_4_normals[13];
extern NJS_MODEL chaos6_debris_4_model;
extern NJS_OBJECT chaos6_debris_4_object;
extern NJS_MATERIAL chaos6_debris_5_materials[1];
extern Sint16 chaos6_debris_5_meshes0[37];
extern NJS_COLOR chaos6_debris_5_uvs0[28];
extern NJS_MESHSET chaos6_debris_5_meshsets[1];
extern NJS_POINT3 chaos6_debris_5_points[10];
extern NJS_VECTOR chaos6_debris_5_normals[10];
extern NJS_MODEL chaos6_debris_5_model;
extern NJS_OBJECT chaos6_debris_5_object;
extern NJS_MATERIAL chaos6_debris_6_materials[1];
extern Sint16 chaos6_debris_6_meshes0[12];
extern NJS_COLOR chaos6_debris_6_uvs0[9];
extern NJS_MESHSET chaos6_debris_6_meshsets[1];
extern NJS_POINT3 chaos6_debris_6_points[5];
extern NJS_VECTOR chaos6_debris_6_normals[5];
extern NJS_MODEL chaos6_debris_6_model;
extern NJS_OBJECT chaos6_debris_6_object;
extern NJS_OBJECT *debris_pieces[(3 + 4)];

void chaos6_debris_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    Float scale;

    njSetTexture_jp(&chaos6_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    scale = work->scl.x;
    njScale(NULL, scale, scale, scale);
    late_DrawObject(debris_pieces[VARS(work)->piece]);
    late_DrawObjectClipEx(1);
}

void chaos6_debris_run(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    work->ang.x += DEBRIS_SPIN;
    work->ang.z += DEBRIS_SPIN;
    motion->speed.y -= DEBRIS_FALL;
    njAddVector(&work->pos, &motion->speed);
    if (work->pos.y < DEBRIS_BOTTOM) {
        FreeTask(task);
    } else {
        chaos6_debris_draw(task);
    }
}

/* the piece's first step: place it out from the boss along work->ang.y,
 * tilted up, and set its speed along the same heading. it tumbles from
 * random angles about x and z, and its size is from 1 to 1.5 at random */
void chaos6_debris_start(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    NJS_VECTOR out;
    Angle ang;

    task->step = chaos6_debris_run;
    task->draw = chaos6_debris_draw;
    njPushMatrix(&nj_unit_matrix_);
    TURN_VIA(njRotateY, work->ang.y, ang);
    /* TURN reads its angle twice, so rand runs twice: TURN's test of the
     * angle calls it at 0x0c905f42, and the turn at 0x0c905f5e */
    TURN(njRotateZ, debris_tilt + (Angle)(rand() * (1.0F / 6.0F)));
    out.y = out.z = 0.0F;
    out.x = RANDOM(1.0F, 1.5F) * debris_reach;
    njCalcVector(NULL, &out, &work->pos);
    njAddVector(&work->pos, &boss_work->pos);
    work->pos.y += RANDOM(1.0F, 1.5F) * debris_height;
    out.x = RANDOM(1.0F, 1.5F) * debris_speed;
    njCalcVector(NULL, &out, &motion->speed);
    late_DrawObjectClipEx(1);
    work->ang.x = RANDOM_ANGLE();
    work->ang.z = RANDOM_ANGLE();
    work->scl.x = RANDOM(1.0F, 1.5F);
}

void Flicky_ini(int kind, int count)
{
    struct task *task;
    struct task_work *work;
    Float spacing = 360.0F / count;
    Float heading;
    int i;

    for (i = 0, heading = 0.0F; i < count; i++, heading += spacing) {
        task = CreateElementalTask(TASK_WORK | TASK_MOTION, 2,
                                   chaos6_debris_start);
        if (task != NULL) {
            work = task->work;
            if (kind == 0) {
                VARS(work)->piece = (Sint8)RANDOM(FIRST_PIECES, PIECES);
            } else {
                VARS(work)->piece =
                    (Sint8)(rand() * (FIRST_PIECES * RAND_SCALE));
            }
            work->ang.y = (Angle)(heading * ANGLE_PER_DEGREE);
        }
    }
}
