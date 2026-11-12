/* @unit 0C9119E0-0C911CA0 +egflags +pool32 */
/* the ladder the object list names O LONG LADDER: three ladders tall, and
 * players climb it along a ledge path */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv02/ladder.h"
#include "adv02/long_ladder.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "path/path.h"
#include "path/steps.h"
#include "stage/stage.h"
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
void *CAlloc(int count, int size);
void FUN_0c9119e0(struct task *task);
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

#define RUNGS 79 /* the path's points */
#define RUNG_SPACING 3.0F /* the distance between points, up the ladder's y */
/* the first point's height above the ladder's position */
#define FIRST_RUNG 6.0F
/* the path's offset along the ladder's z, in front of the ladder */
#define PATH_Z (-2.55F)

/* the ladder draws as LADDERS ladder models, each LADDER_HEIGHT above the last,
 * from LADDER_FOOT below its position */
#define LADDERS 3
#define LADDER_HEIGHT 99.0F
#define LADDER_FOOT 60.0F

#define VARS(work) ((struct long_ladder_vars *)&(work)->vars)
enum long_ladder_mode { LONG_LADDER_INIT, LONG_LADDER_RUN };

/* the path the ladder's path_ledge_step child follows, and the path's points.
 * the ladder's first step allocates both from the heap, and
 * long_ladder_destroy frees them */
struct long_ladder_vars {
    Uint8 unk_00[4];
    struct path_point *points;
    struct path *path;
};

void long_ladder_destroy(struct task *task);
void LadderDisplayer(struct task *task);

/* the ladder's first step builds a ledge path of RUNGS points up it, for a
 * child task that runs path_ledge_step. while the set editor holds the
 * ladder, each step only draws it */
void FUN_0c9119e0(struct task *task)
{
    struct task_work *work = task->work;
    struct task *child;
    struct task_work *child_work;
    struct path_point *points;
    struct path_point *point;
    struct path *path;
    NJS_POINT3 rung;
    NJS_POINT3 offset;
    Angle ang;
    int i;

    if (CheckRangeOut(task)) {
        return;
    }
    if (OnEdit(task)) {
        LadderDisplayer(task);
        return;
    }
    switch (work->mode) {
    case LONG_LADDER_INIT:
        task->destructor = long_ladder_destroy;
        task->draw = LadderDisplayer;
        child = CreateChildTask(TASK_WORK, path_ledge_step, task);
        if (child != NULL) {
            child_work = child->work;
            PATH_VARS(child_work)->stage_act = GetStageNumber();
            child_work->ang.y = work->ang.y;
        }
        offset.x = 0.0F;
        offset.y = FIRST_RUNG;
        offset.z = PATH_Z;
        njPushMatrix(&nj_unit_matrix_);
        TURN_VIA(njRotateY, work->ang.y, ang);
        points = MAlloc(sizeof(struct path_point) * RUNGS);
        VARS(work)->points = points;
        point = points;
        for (i = 0; i < RUNGS; i++, point++) {
            point->ang_x = 0;
            point->ang_z = 0;
            point->length = RUNG_SPACING;
            njCalcPoint(NULL, &offset, &rung);
            point->pos.x = work->pos.x + rung.x;
            point->pos.y = work->pos.y + rung.y;
            point->pos.z = work->pos.z + rung.z;
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
        /* @bug memory: the path's store reads child->work, MOV.L @(32,R8),R3 at
         * 0x0c912186, without the test of child that guards the stores above
         * (TST R8,R8 at 0x0c9120b4). when task_create_child returns null, it
         * reads address 32 */
        PATH_VARS(child->work)->path = path;
        work->mode = LONG_LADDER_RUN;
        break;
    case LONG_LADDER_RUN:
        break;
    }
    LoopTaskC(task);
    LadderDisplayer(task);
}

void long_ladder_destroy(struct task *task)
{
    struct task_work *work = task->work;

    Free(VARS(work)->path);
    Free(VARS(work)->points);
    FreeTaskC(task);
}

void LadderDisplayer(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;
    int i;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y - LADDER_FOOT, work->pos.z);
    TURN_VIA(njRotateY, work->ang.y, ang);
    for (i = 0; i < LADDERS; i++) {
        ds_DrawModelClip(ladder_object->model);
        njTranslate(NULL, 0.0F, LADDER_HEIGHT, 0.0F);
    }
    late_DrawObjectClipEx(1);
}
