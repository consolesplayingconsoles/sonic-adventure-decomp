/* @unit 0C9055E0-0C905980 +r04 +egflags +pool32 +poolafter=FUN_0c9056ae,back_door_locked */
/* O URADOOR back door that swings open when a player touches it in the sewer
 * act */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "adv00/back_door.h"
#include "adv00/station_square.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "object/placement.h"
#include "stage/stage.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
float njArcTan2(float y, float x);
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
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

/* @hack type: the door's action declared as an array. SHC then pools its
 * address and reads its motion through it, MOV.L @(4,R3),R2 at 0x0c905890.
 * declared as one NJS_ACTION, SHC pools the motion field's address, and 11 of
 * back_door_turn's 57 words, 8 of back_door_close's 49 and 3 of
 * back_door_open's 54 differ */
#define DOOR_SPEED 0.2F /* motion frames a step */
#define DOOR_TURN 16384.0F
#define DOOR_WAIT 90 /* steps the door stays fully open */
#define DOOR_HALF 5.0F /* half the door's width */
#define VARS(work) ((struct back_door_vars *)&(work)->vars)
extern NJS_ACTION back_door_action[];

/* the door's turn over its whole motion, a quarter turn */

struct back_door_vars {
    Float frame; /* the door's frame in its motion, 0 shut */
};

void back_door_close(struct task *task);
void back_door_wait(struct task *task);
void back_door_open(struct task *task);
void back_door_locked(struct task *task);
void back_door_idle(struct task *task);
extern struct collision_shape back_door_shape;
/* clang-format on */

Bool back_door_touched(struct task_work *work)
{
    return (work->flags & COLLISION_TOUCHING) &&
           work->collision->hit->kind == COLLISION_PLAYER;
}

void back_door_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    (((ang) = (work->ang.y)) ? (njRotateY)(((void *)0), (ang)) : (void)0);
    ds_ActionClip(back_door_action,
                  ((struct back_door_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

/* turn the door's shape about its hinge as far as frame has swung the door,
 * and register the record for this step's checks */
void back_door_turn(struct task_work *work)
{
    struct collision_shape *shape = work->collision->shapes;
    Angle ang;

    ang = njFloor(VARS(work)->frame * DOOR_TURN /
                  (back_door_action->motion->nbFrame - 1));
    shape->center.x = -(njSin(ang) * DOOR_HALF);
    shape->center.z = -(njCos(ang) * DOOR_HALF) + DOOR_HALF;
    shape->ang.y = ang;
    EntryColliList(work);
}

/* swing shut, reopening if a player touches the door on the way */
void back_door_close(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: last set and never read, which loads the motion's
     * frame count and converts it ahead of the range check (FLOAT at
     * 0x0c905906); without it, 48 of 49 words differ */
    Float last = back_door_action->motion->nbFrame - 1;

    if (CheckRangeOut(task)) {
        return;
    }
    back_door_draw(task);
    if (!back_door_touched(work)) {
        /* @hack spelling: the frame decremented in the test, which SHC tests in
         * FR2 and stores in the slot of the BT/S at 0x0c90592e. as a statement
         * of its own, SHC reads the frame back to test it, and 29 of 49 words
         * differ */
        if ((VARS(work)->frame -= DOOR_SPEED) <= 0.0F) {
            VARS(work)->frame = 0.0F;
            task->step = back_door_idle;
        }
    } else {
        task->step = back_door_open;
    }
    back_door_turn(work);
}

void back_door_wait(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    back_door_draw(task);
    if (--work->tick == 0) {
        task->step = back_door_close;
    }
    back_door_turn(work);
}

void back_door_open(struct task *task)
{
    struct task_work *work = task->work;
    Float last = back_door_action->motion->nbFrame - 1;

    if (CheckRangeOut(task)) {
        return;
    }
    back_door_draw(task);
    VARS(work)->frame += DOOR_SPEED;
    if (VARS(work)->frame >= last) {
        VARS(work)->frame = last;
        work->tick = DOOR_WAIT;
        task->step = back_door_wait;
    }
    back_door_turn(work);
}

/* outside the sewer act, keep the door shut */
void back_door_locked(struct task *task)
{
    struct task_work *work = task->work;

    if (OnEdit(task)) {
        back_door_draw(task);
    } else {
        if (CheckRangeOut(task)) {
            return;
        }
        back_door_draw(task);
        back_door_turn(work);
    }
}

/* wait shut until a player touches the door */
void back_door_idle(struct task *task)
{
    struct task_work *work = task->work;

    if (OnEdit(task)) {
        back_door_draw(task);
    } else {
        if (CheckRangeOut(task)) {
            return;
        }
        back_door_draw(task);
        if (back_door_touched(work)) {
            task->step = back_door_open;
        }
        back_door_turn(work);
    }
}

static Bool back_door_opens(void)
{
    return (Uint8)GetStageNumber() == STATION_SQUARE_GESUI;
}

void back_door_init(struct task *task)
{
    if (CheckRangeOut(task)) {
        return;
    }
    CCL_Init(task, &back_door_shape, COLLISION_OBJECT, 1, 1);
    if (back_door_opens()) {
        task->step = back_door_idle;
    } else {
        task->step = back_door_locked;
    }
    task->draw = back_door_draw;
}
