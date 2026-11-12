/* @unit 0C915040-0C915200 @data 0C919D44-0C919D58 +egflags +pool32 */
/* C HANE fan that spins about y by its set entry's angle x each step */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "sound/sound.h"
#include "stg10/fan.h"
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
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
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

#define SE_FAN 985

/* the fan's turn each step when its angle x is 0 */
#define SPEED NJM_DEG_ANG(1)
/* a scale below SCALE_MIN is taken as 1 */
#define SCALE_MIN 0.01F

#define VARS(work) ((struct final_fan_vars *)&(work)->vars)
struct final_fan_vars {
    Uint8 unk_00[8];
    Angle speed; /* the turn about y each step */
};

void hane_exec(struct task *task);
void final_fan_draw(struct task *task);
void final_fan_destroy(struct task *task);
extern NJS_MATERIAL final_fan_node6_materials[5];
extern Sint16 final_fan_node6_meshes0[11];
extern Sint16 final_fan_node6_meshes1[20];
extern Sint16 final_fan_node6_meshes2[5];
extern Sint16 final_fan_node6_meshes3[22];
extern NJS_COLOR final_fan_node6_uvs0[10];
extern NJS_COLOR final_fan_node6_uvs1[16];
extern NJS_COLOR final_fan_node6_uvs2[4];
extern NJS_COLOR final_fan_node6_uvs3[18];
extern NJS_MESHSET final_fan_node6_meshsets[4];
extern NJS_POINT3 final_fan_node6_points[16];
extern NJS_VECTOR final_fan_node6_normals[16];
extern NJS_MODEL final_fan_node6_model;
extern NJS_OBJECT final_fan_node6_object;
extern NJS_MATERIAL final_fan_node5_materials[5];
extern Sint16 final_fan_node5_meshes0[11];
extern Sint16 final_fan_node5_meshes1[20];
extern Sint16 final_fan_node5_meshes2[5];
extern Sint16 final_fan_node5_meshes3[22];
extern NJS_COLOR final_fan_node5_uvs0[10];
extern NJS_COLOR final_fan_node5_uvs1[16];
extern NJS_COLOR final_fan_node5_uvs2[4];
extern NJS_COLOR final_fan_node5_uvs3[18];
extern NJS_MESHSET final_fan_node5_meshsets[4];
extern NJS_POINT3 final_fan_node5_points[16];
extern NJS_VECTOR final_fan_node5_normals[16];
extern NJS_MODEL final_fan_node5_model;
extern NJS_OBJECT final_fan_node5_object;
extern NJS_MATERIAL final_fan_node4_materials[5];
extern Sint16 final_fan_node4_meshes0[11];
extern Sint16 final_fan_node4_meshes1[20];
extern Sint16 final_fan_node4_meshes2[5];
extern Sint16 final_fan_node4_meshes3[22];
extern NJS_COLOR final_fan_node4_uvs0[10];
extern NJS_COLOR final_fan_node4_uvs1[16];
extern NJS_COLOR final_fan_node4_uvs2[4];
extern NJS_COLOR final_fan_node4_uvs3[18];
extern NJS_MESHSET final_fan_node4_meshsets[4];
extern NJS_POINT3 final_fan_node4_points[16];
extern NJS_VECTOR final_fan_node4_normals[16];
extern NJS_MODEL final_fan_node4_model;
extern NJS_OBJECT final_fan_node4_object;
extern NJS_MATERIAL final_fan_node3_materials[5];
extern Sint16 final_fan_node3_meshes0[11];
extern Sint16 final_fan_node3_meshes1[20];
extern Sint16 final_fan_node3_meshes2[5];
extern Sint16 final_fan_node3_meshes3[22];
extern NJS_COLOR final_fan_node3_uvs0[10];
extern NJS_COLOR final_fan_node3_uvs1[16];
extern NJS_COLOR final_fan_node3_uvs2[4];
extern NJS_COLOR final_fan_node3_uvs3[18];
extern NJS_MESHSET final_fan_node3_meshsets[4];
extern NJS_POINT3 final_fan_node3_points[16];
extern NJS_VECTOR final_fan_node3_normals[16];
extern NJS_MODEL final_fan_node3_model;
extern NJS_OBJECT final_fan_node3_object;
extern NJS_MATERIAL final_fan_node2_materials[5];
extern Sint16 final_fan_node2_meshes0[11];
extern Sint16 final_fan_node2_meshes1[20];
extern Sint16 final_fan_node2_meshes2[5];
extern Sint16 final_fan_node2_meshes3[22];
extern NJS_COLOR final_fan_node2_uvs0[10];
extern NJS_COLOR final_fan_node2_uvs1[16];
extern NJS_COLOR final_fan_node2_uvs2[4];
extern NJS_COLOR final_fan_node2_uvs3[18];
extern NJS_MESHSET final_fan_node2_meshsets[4];
extern NJS_POINT3 final_fan_node2_points[16];
extern NJS_VECTOR final_fan_node2_normals[16];
extern NJS_MODEL final_fan_node2_model;
extern NJS_OBJECT final_fan_node2_object;
extern NJS_MATERIAL final_fan_node1_materials[5];
extern Sint16 final_fan_node1_meshes0[39];
extern Sint16 final_fan_node1_meshes1[19];
extern Sint16 final_fan_node1_meshes2[19];
extern Sint16 final_fan_node1_meshes3[19];
extern NJS_COLOR final_fan_node1_uvs0[34];
extern NJS_COLOR final_fan_node1_uvs1[18];
extern NJS_COLOR final_fan_node1_uvs2[18];
extern NJS_COLOR final_fan_node1_uvs3[18];
extern NJS_MESHSET final_fan_node1_meshsets[4];
extern NJS_POINT3 final_fan_node1_points[41];
extern NJS_VECTOR final_fan_node1_normals[41];
extern NJS_MODEL final_fan_node1_model;
extern NJS_OBJECT final_fan_node1_object;
extern NJS_OBJECT final_fan_object[1];

void ObjectFinalEggHane(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->speed = work->ang.x ? work->ang.x : SPEED;
    work->ang.x = 0;
    /* @hack spelling: the three clamps as one expression, which loads each
     * scale into a register of its own, FR5 to FR7 (0x0c915b9a, 0x0c915baa,
     * 0x0c915bba). as three statements, each takes FR5, and 6 of 43 words
     * differ */
    work->scl.x = work->scl.x < SCALE_MIN ? 1.0F : work->scl.x,
    work->scl.y = work->scl.y < SCALE_MIN ? 1.0F : work->scl.y,
    work->scl.z = work->scl.z < SCALE_MIN ? 1.0F : work->scl.z;
    task->step = hane_exec;
    task->draw = final_fan_draw;
    task->destructor = final_fan_destroy;
}

void hane_exec(struct task *task)
{
    struct task_work *work = task->work;

    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_X), "<- FAN SPEED(ANGLE)");
        if (work->ang.x) {
            VARS(work)->speed = work->ang.x;
        }
    }
    work->ang.y += VARS(work)->speed;
    final_fan_draw(task);
    dsPlay_Dolby_time(SE_FAN, (int)task, 1, 0, work->pos.x, work->pos.y,
                      work->pos.z, 2);
}

void final_fan_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (loop_count == 0) {
        if (!CheckRangeOut(task)) {
            SetObjectTexture();
            njPushMatrix(NULL);
            njTranslateV(NULL, &work->pos);
            TURN(njRotateY, work->ang.y);
            njScale(NULL, work->scl.x, work->scl.y, work->scl.z);
            late_DrawObject(final_fan_object->child);
            late_DrawObjectClipEx(1);
        }
    }
}

void final_fan_destroy(struct task *task)
{
}
