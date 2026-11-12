/* @unit 0C916940-0C916B20 @data 0CB23470-0CB2347C +egflags +pool32 */
/* O MB mirror ball that spins and turns the act's light with it */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "stage/stage.h"
#include "stg09/casino.h"
#include "stg09/mirror_ball.h"
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
void ds_DrawObjectClip(NJS_OBJECT *object);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
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
int thunk_FUN_8c09cbc0(char *name, void *dest);
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

#define RANGE ((700.0F * 700.0F) + 10.0F)
#define VIEW_RADIUS 40.0F
#define TURN_DEGREES(work) ((work)->scl.x + 2.0F)
#define VARS(work) ((struct mirror_ball_vars *)&(work)->vars)
#define LIGHT_KEPT(work) ((work)->submode)
extern NJS_OBJECT mirror_ball_object;

/* the act light's turn about y. save/card.c defines it static. this image
 * links to it through 1ST_READ.BIN's symbols, which name its address */
extern Angle light_ry;

/* destroyed beyond about 700 units of the camera and player 0 */
/* the radius of the sphere about the ball that draw_in_view tests */
/* the ball's turn each step, in degrees */

struct mirror_ball_vars {
    Uint8 unk_00[8];
    Sint16 stage_act; /* the stage and act the ball started in */
};
extern struct collision_shape mirror_ball_shape;

void mirror_ball_destroy(struct task *task);
void mirror_ball_draw(struct task *task);
void Exec(struct task *task);

void mirror_ball_step(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        task->draw = mirror_ball_draw;
        task->step = Exec;
        task->destructor = mirror_ball_destroy;
        if (!OnEdit(task)) {
            CCL_Init(task, &mirror_ball_shape, COLLISION_OBJECT, 1, 1);
        }
        VARS(work)->stage_act = GetStageNumber();
        /* @bug arithmetic: submode, a Sint8, keeps only light_ry's low byte
         * (MOV.B @R3,R0 at 0x0c917bc8). mirror_ball_destroy gives that byte
         * back sign-extended (MOV.B @(1,R14),R0 at 0x0c917bf4), so a turn
         * outside -128 to 127 comes back as another */
        LIGHT_KEPT(work) = light_ry;
    }
}

/* outside the set editor, in the act the ball started in, give light_ry
 * back LIGHT_KEPT */
void mirror_ball_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (!OnEdit(task)) {
        if (VARS(work)->stage_act == GetStageNumber()) {
            /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
            light_ry = LIGHT_KEPT(work);
        }
    }
}

void mirror_ball_draw(struct task *task)
{
    struct task_work *work = task->work;
    if (!CheckRangeOutWithR(task, ((700.0F * 700.0F) + 10.0F))) {
        if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 40.0F)) {
            casino_set_texture(12);
            njPushMatrix(((void *)0));
            njTranslateV(((void *)0), &work->pos);
            ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
            ds_DrawObjectClip(&mirror_ball_object);
            late_DrawObjectClipEx(1);
        }
    }
}

void Exec(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        mirror_ball_draw(task);
        work->ang.y += (Angle)(TURN_DEGREES(work) * ANGLE_PER_DEGREE);
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_X), "-> RotSpd ");
            return;
        }
        EntryColliList(work);
        if (VARS(work)->stage_act == GetStageNumber()) {
            light_ry = work->ang.y;
        }
    }
}
