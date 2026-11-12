/* @unit 8C05AE40-8C05B1A0 @data 8C154A30-8C154A38 +r04 +egflags +pool32 */
/* targets: things E-102 shoots down, which the stages count by id */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "effect/bomb.h"
#include "object/models.h"
#include "object/piece.h"
#include "object/target.h"
#include "player/lockon.h"
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
void *MAlloc(int size);
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
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
void ObjectEmeraldP(struct task *task);
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
void ReleasePlayersTexture(int character);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

/* the most targets a stage can start: the size of target_tasks */
#define TARGET_COUNT 64

#define TARGET_DOWN 0x100 /* in work->flags: shot down */

#define BURST_TIME 30 /* steps a target bursts for once it's down */
#define PUFF_TIME 8 /* steps between its puffs */

/* a target's bytes in work->vars. its id is in work->scl.x */
#define VARS(work) ((struct target_vars *)&(work)->vars)
struct target_vars {
    void *param; /* its kind's param in the object list, as placed */
    Sint16 burst; /* steps left to burst */
    Sint16 puff; /* steps to the next puff */
};

enum target_mode { TARGET_STAND, TARGET_BURST, TARGET_GONE };
extern const Uint8 target_shape_count;
extern struct collision_shape target_shapes[];
extern Sint16 target_count;
extern struct task *target_tasks[64];

void target_draw(struct task *task)
{
    struct task_work *work;

    work = task->work;
    if (work->mode != TARGET_STAND) {
        return;
    }
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 10.0F)) {
        return;
    }
    draw_set_palette(DRAW_PLAYER_PALETTE);
    SetRegularTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(&target_object);
    late_DrawObjectClipEx(1);
    draw_set_palette(0);
}

/* shot down, the target lets the shot fly on through it. it then bursts
 * into puffs for BURST_TIME steps, and is gone */
static void target_step(struct task *task)
{
    struct task_work *work;
    struct lockon_target *record;
    NJS_POINT3 pos;

    work = task->work;
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- ID");
        target_draw(task);
        return;
    }
    switch (work->mode) {
    case TARGET_STAND:
        LoopTaskC(task);
        if (work->flags & COLLISION_DAMAGED) {
            record = LOCKON_TARGET(task);
            record->flags |= LOCKON_HIT;
            E102KillCursor(task);
            work->flags |= TARGET_DOWN;
            VARS(work)->burst = BURST_TIME;
            VARS(work)->puff = PUFF_TIME;
            work->mode = TARGET_BURST;
            FreeTaskC(task);
        }
        break;
    case TARGET_BURST:
        VARS(work)->puff--;
        if (VARS(work)->puff == 0) {
            VARS(work)->puff = PUFF_TIME;
            pos = work->pos;
            pos.x += (0.5F - (rand() * RAND_SCALE)) * 12.0F;
            pos.y += (0.5F - (rand() * RAND_SCALE)) * 12.0F;
            pos.z += (0.5F - (rand() * RAND_SCALE)) * 12.0F;
            CreateBomb(&pos, 0.35F);
        }
        VARS(work)->burst--;
        /* @hack spelling: the test and its store as an expression, which
         * puts collision_register's address in R2 (MOV.L at 0x8c05e284);
         * as an if, it takes R3, and 2 of 148 words differ */
        !VARS(work)->burst ? (void)(work->mode = TARGET_GONE) : (void)0;
        return;
    case TARGET_GONE:
        return;
    }
    target_draw(task);
    EntryColliList(work);
}

void target_start(struct task *task)
{
    struct task *child;

    CCL_Init(task, target_shapes, COLLISION_ITEM, 1, target_shape_count);
    task->motion = CAlloc(1, sizeof(struct lockon_target));
    task->step = target_step;
    task->draw = target_draw;
    child = CreateChildTask(TASK_WORK, target_blink_start, task);
    if (child != NULL) {
        child->work->pos = task->work->pos;
    }
    target_tasks[target_count++] = task;
}

Bool target_cleared(int id)
{
    struct task_work *work;
    int count;
    int its_id;
    int i;

    count = 0;
    for (i = 0; i < target_count; i++) {
        work = target_tasks[i]->work;
        /* @hack spelling: the placed id through a local, which takes a
         * third saved register, R14, for TARGET_DOWN (MOV.W at 0x8c05e30a);
         * compared in place, 21 of 37 words differ */
        its_id = (int)work->scl.x;
        /* @hack spelling: the continue, which makes the loop read target_count
         * again on every pass (MOV.W @R11,R3 at 0x8c05e37c); as an if round
         * the test of TARGET_DOWN, 37 of 37 words differ */
        if (id != its_id) {
            continue;
        }
        if (work->flags & TARGET_DOWN) {
            count++;
        } else {
            return FALSE;
        }
    }
    if (count == 0) {
        return FALSE;
    }
    return TRUE;
}

void target_reset(void)
{
    target_count = 0;
}
