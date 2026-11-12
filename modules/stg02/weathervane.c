/* @unit 0C90B5A0-0C90B880 @data 0CA14F48-0CA14F58 +jpflags +pool32 */
/* O KAZAMI: a solid weathervane that turns to random headings as its propeller
 * spins */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "stg02/weathervane.h"
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
void *syMalloc_default_malloc(size_t size);
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

#define VARS(work) ((struct weathervane_vars *)&(work)->vars)
#define HOLD_STEPS 100
extern NJS_OBJECT windy_weathervane_object;
extern NJS_OBJECT windy_weathervane_head_object;
extern NJS_OBJECT windy_weathervane_propeller_object;

/* the weathervane's work->vars, in degrees. TASK_TIMER(work) counts the steps
 * the head holds its heading */
struct weathervane_vars {
    Float spin; /* the propeller's angle */
    Float heading; /* the head's angle about y */
    Float target; /* the heading the head turns to */
};

/* in VANE_END each step does nothing, and no step here sets it */
enum weathervane_mode { VANE_START, VANE_HOLD, VANE_TURN, VANE_END };
extern Float dat_0ca13f30;
extern struct collision_shape windy_weathervane_shape;

void windy_weathervane_draw(struct task *task);

void ObjectWindyKazami(struct task *task)
{
    struct task_work *work = task->work;
    Float speed;
    Float heading;
    Angle ang;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case VANE_START:
        work->mode = VANE_HOLD;
        task->draw = windy_weathervane_draw;
        VARS(work)->heading = 0.0F;
        CCL_Init(task, &windy_weathervane_shape, COLLISION_OBJECT, 1, 1);
        break;
    case VANE_HOLD:
        VARS(work)->spin += work->scl.x;
        if (TASK_TIMER(work)++ > HOLD_STEPS) {
            work->timer = 0;
            VARS(work)->target = rand() * (360.0F * RAND_SCALE);
            work->mode = VANE_TURN;
        }
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- ROTATE_SPEED");
        }
        windy_weathervane_draw(task);
        EntryColliList(work);
        break;
    case VANE_TURN:
        VARS(work)->spin += work->scl.x;
        if (VARS(work)->target > VARS(work)->heading) {
            speed = VARS(work)->target / (VARS(work)->heading + 0.1F) *
                    work->scl.x * 0.1F;
        } else {
            speed = VARS(work)->heading / (VARS(work)->target + 0.1F) *
                    work->scl.x * 0.1F;
        }
        ang = AdjustAngle(VARS(work)->heading * ANGLE_PER_DEGREE,
                          VARS(work)->target * ANGLE_PER_DEGREE,
                          speed * ANGLE_PER_DEGREE);
        heading = ang * (360.0F / 65536.0F);
        /* @hack spelling: a select in place of an if, for the hold once the
         * head stops turning. it loads the mode's 1 at its store (MOV #1,R2 at
         * 0x0c90be5e). as an if, SHC keeps the 1 in R12, a saved register, and
         * 149 of 162 words differ */
        VARS(work)->heading == heading ? work->mode = VANE_HOLD : 0;
        VARS(work)->heading = heading;
        windy_weathervane_draw(task);
        EntryColliList(work);
        break;
    case VANE_END:
        break;
    }
}

void windy_weathervane_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *post = &windy_weathervane_object;
    NJS_OBJECT *head = &windy_weathervane_head_object;
    NJS_OBJECT *propeller = &windy_weathervane_propeller_object;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    ds_DrawModelClip(post->model);
    njPushMatrix(NULL);
    njTranslate(NULL, head->pos[0], head->pos[1], head->pos[2]);
    TURN(njRotateY, (Angle)(VARS(work)->heading * ANGLE_PER_DEGREE));
    ds_DrawModelClip(head->model);
    njPushMatrix(NULL);
    njTranslate(NULL, propeller->pos[0], propeller->pos[1], propeller->pos[2]);
    TURN(njRotateX, (Angle)(VARS(work)->spin * ANGLE_PER_DEGREE));
    ds_DrawModelClip(propeller->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
}
