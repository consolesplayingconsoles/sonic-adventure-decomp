/* @unit 0C90C6A0-0C90C900 +egflags +pool32 */
/* the ladder the object list names O LADDER, which players climb along a
 * ledge path */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv02/ladder.h"
#include "adv02/texlists.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "path/path.h"
#include "path/steps.h"
#include "stage/stage.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
void FreeTaskC(struct task *task);
void *CAlloc(int count, int size);
void FUN_0c90c6a0(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
Bool GetStatusOnPath(struct path *path, struct GetStatusOnPath *sample);
Bool path_spline_sample(struct path_spline *spline,
                        struct GetStatusOnPath *sample);
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Bool ChkPause(void);
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

#define RUNGS 33 /* the path's points */
#define RUNG_SPACING 3.0F /* the distance between points, up the ladder's y */
/* the first point's height above the ladder's position */
#define FIRST_RUNG 6.0F

/* the path the ladder's path_ledge_step child follows, and the path's points.
 * ladder_start allocates both from the heap, and ladder_destroy frees them */
#define VARS(work) ((struct ladder_vars *)&(work)->vars)
struct ladder_vars {
    Uint8 unk_00[4];
    struct path_point *points;
    struct path *path;
};

void ladder_step(struct task *task);
void ladder_draw(struct task *task);
void ladder_destroy(struct task *task);
extern Float ladder_reach;

/* a ladder the set editor holds as it starts never gets its path */
void FUN_0c90c6a0(struct task *task)
{
    struct task_work *work = task->work;
    struct task *child;
    struct path_point *points;
    struct path *path;
    NJS_POINT3 rung;
    NJS_POINT3 offset;
    Angle ang;
    int rungs;
    int i;

    if (OnEdit(task)) {
        ladder_draw(task);
        task->step = ladder_step;
        return;
    }
    child = CreateChildTask(TASK_WORK, path_ledge_step, task);
    PATH_VARS(child->work)->stage_act = GetStageNumber();
    child->work->ang.x = 0;
    child->work->ang.y = work->ang.y;
    child->work->ang.z = 0;
    offset.x = 0.0F;
    offset.y = FIRST_RUNG;
    offset.z = ladder_reach;
    /* @hack spelling: the count through a local, which SHC keeps in the frame,
     * MOV.L R2,@R15 at 0x0c90cce6; as RUNGS in the loop's test, the function
     * grows, the functions after it move, and 122 of its 159 words differ */
    rungs = RUNGS;
    njPushMatrix(&nj_unit_matrix_);
    TURN_VIA(njRotateY, work->ang.y, ang);
    points = MAlloc(sizeof(struct path_point) * RUNGS);
    VARS(work)->points = points;
    for (i = 0; i < rungs; i++) {
        points[i].ang_x = 0;
        points[i].ang_z = 0;
        points[i].length = RUNG_SPACING;
        njCalcPoint(NULL, &offset, &rung);
        points[i].pos.x = work->pos.x + rung.x;
        points[i].pos.y = work->pos.y + rung.y;
        points[i].pos.z = work->pos.z + rung.z;
        offset.y += RUNG_SPACING;
    }
    late_DrawObjectClipEx(1);
    path = MAlloc(sizeof(struct path));
    VARS(work)->path = path;
    path->ends = PATH_STOP;
    path->count = RUNGS;
    path->length = (RUNGS - 1) * RUNG_SPACING;
    path->points = points;
    path->step = path_ledge_step;
    PATH_VARS(child->work)->path = path;
    task->step = ladder_step;
    task->draw = ladder_draw;
    task->destructor = ladder_destroy;
}

void ladder_step(struct task *task)
{
    if (!CheckRangeOut(task)) {
        ladder_draw(task);
        LoopTaskC(task);
    }
}

void ladder_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njSetTexture_jp(&mrobj_texlist);
    ds_DrawModelClip(ladder_object->model);
    late_DrawObjectClipEx(1);
}

void ladder_destroy(struct task *task)
{
    struct task_work *work = task->work;

    Free(VARS(work)->path);
    Free(VARS(work)->points);
}
