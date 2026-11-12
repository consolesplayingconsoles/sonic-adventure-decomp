/* @unit 0C924220-0C924380 +r04 +egflags +pool32 */
/* O BCHAIR beach chair by the pool, solid for a player to stand on */
#include <ninja.h>

#include "adv0100/beach_chair.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "object/placement.h"
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
void FUN_0c924220(struct task *task);
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define SOLID_FLAGS (WORLD_MEDIUM | WORLD_SOLID)
#define VARS(work) ((struct beach_chair_vars *)&(work)->vars)
extern NJS_OBJECT beach_chair_object;
extern NJS_OBJECT beach_chair_solid_object;

struct beach_chair_vars {
    NJS_OBJECT *solid; /* the surface's copy in the collision world */
    NJS_OBJECT *from; /* the node whose model solid takes */
};

enum beach_chair_mode { CHAIR_INIT, CHAIR_RUN };

void beach_chair_draw(struct task *task);
void beach_chair_destroy(struct task *task);
void beach_chair_draw_work(struct task_work *work);

void FUN_0c924220(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *solid;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case CHAIR_INIT:
        if (!OnEdit(task)) {
            VARS(work)->from = &beach_chair_solid_object;
            VARS(work)->solid = solid = GetMobileLandObject();
            solid->evalflags = NJD_EVAL_BREAK;
            solid->scl[0] = 1.0F;
            solid->scl[1] = 1.0F;
            solid->scl[2] = 1.0F;
            solid->ang[0] = 0;
            solid->ang[1] = work->ang.y;
            solid->ang[2] = 0;
            solid->pos[0] = work->pos.x;
            solid->pos[1] = work->pos.y;
            solid->pos[2] = work->pos.z;
            solid->model = VARS(work)->from->model;
            solid->child = NULL;
            solid->sibling = NULL;
            RegisterCollisionEntry(SOLID_FLAGS, task, solid);
        }
        task->destructor = beach_chair_destroy;
        task->draw = beach_chair_draw;
        work->mode = CHAIR_RUN;
        break;
    case CHAIR_RUN:
        beach_chair_draw_work(work);
        break;
    }
}

void beach_chair_draw(struct task *task)
{
    struct task_work *work = task->work;

    beach_chair_draw_work(work);
}

void beach_chair_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->solid != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->solid);
        ReleaseMobileLandObject(VARS(work)->solid);
    }
}

void beach_chair_draw_work(struct task_work *work)
{
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObject(&beach_chair_object);
    late_DrawObjectClipEx(1);
}
