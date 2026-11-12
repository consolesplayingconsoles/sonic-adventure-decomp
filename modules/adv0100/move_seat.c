/* @unit 0C926920-0C926BA0 +egflags +pool32 */
/* O MOVESEAT seat on a spring that bounces three times when its cushion is
 * touched */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv0100/move_seat.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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

/* the base. its child is the spring, and the spring's sibling the cushion */
#define CUSHION 1
#define BOUNCE_STEP 0x400
#define BOUNCE_END 0x30000
#define LEVEL_STEP 0.1F /* the change in LEVEL each step */
#define CUSHION_REST 1.0F
#define CUSHION_SAG 1.5F /* half the depth the bounce lowers the cushion by */
#define CUSHION_ROCK 4096.0F
#define SEAT_BOUNCING 0x2
#define LEVEL(work) ((work)->scl.x)
#define VARS(work) ((struct move_seat_vars *)&(work)->vars)
extern NJS_OBJECT move_seat_object;

/* the index in move_seat_shapes of the cushion, whose touch starts a bounce */
/* the bounce's phase gain each step, and the phase at which it ends, three
 * whole turns on */
/* the cushion's height above its node's place at rest */
/* the farthest the bounce rocks the cushion, a sixteenth of a turn */

/* in work->flags while the seat bounces */
/* rises to 1 while the seat bounces, and falls back to 0 after. nothing in this
 * image reads it */

struct move_seat_vars {
    Uint8 unk_00[8];
    Angle bounce;
};

enum move_seat_mode {
    SEAT_INIT,
    SEAT_WAIT,
    SEAT_BOUNCE,
    SEAT_STILL /* no code switches to it */
};

void SeatDestructor(struct task *task);
void SeatDisplayer(struct task *task);
void DisplaySeat(struct task *task, struct task_work *work);
extern struct collision_shape move_seat_shapes[];
extern NJS_TEXANIM move_seat_texanim;

void ObjectECMovingSeat(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case SEAT_INIT:
        if (!OnEdit(task)) {
            CCL_Init(task, move_seat_shapes, COLLISION_OBJECT, 1, 2);
        }
        task->destructor = SeatDestructor;
        task->draw = SeatDisplayer;
        work->mode = SEAT_WAIT;
        break;
    case SEAT_WAIT:
        if (work->collision->flags & COLLISION_HIT) {
            if (work->collision->own_shape == CUSHION) {
                work->mode = SEAT_BOUNCE;
                work->flags |= SEAT_BOUNCING;
                VARS(work)->bounce = 0;
            }
        }
        break;
    case SEAT_BOUNCE:
        VARS(work)->bounce += BOUNCE_STEP;
        if (VARS(work)->bounce == BOUNCE_END) {
            work->mode = SEAT_WAIT;
            VARS(work)->bounce = 0;
            work->flags &= ~SEAT_BOUNCING;
        }
        break;
    case SEAT_STILL:
        break;
    }
    if (work->flags & SEAT_BOUNCING) {
        LEVEL(work) += LEVEL_STEP;
        if (LEVEL(work) >= 1.0F) {
            LEVEL(work) = 1.0F;
        }
    } else {
        /* @hack spelling: -LEVEL_STEP added, a constant of its own, which SHC
         * loads through R1 and FPUL (MOV.L at 0x0c926bfc), as the rise loads
         * 0.1 (0x0c926be4); with -=, SHC loads 0.1 once into FR4 for both, the
         * function runs 8 bytes short and 46 of 123 words differ */
        LEVEL(work) += -LEVEL_STEP;
        if (LEVEL(work) <= 0.0F) {
            LEVEL(work) = 0.0F;
        }
    }
    DisplaySeat(task, work);
    if (!OnEdit(task)) {
        EntryColliList(work);
    }
}

void SeatDestructor(struct task *task)
{
}

void SeatDisplayer(struct task *task)
{
    struct task_work *work = task->work;

    DisplaySeat(task, work);
}

/* draw the base, then the spring and the cushion, its children. the bounce
 * lowers the cushion and rocks it about z either way, as CUSHION_SAG and
 * CUSHION_ROCK say */
void DisplaySeat(struct task *task, struct task_work *work)
{
    Float height = ((njSin(VARS(work)->bounce + 0x4000) - 1.0F) * CUSHION_SAG) +
                   CUSHION_REST;
    Angle rock = (Angle)(njSin(VARS(work)->bounce) * CUSHION_ROCK);
    NJS_OBJECT *object = &move_seat_object;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njTranslateV(NULL, (NJS_VECTOR *)object->pos);
    ds_DrawModelClip(object->model);
    object = object->child;
    njPushMatrix(NULL);
    njTranslateV(NULL, (NJS_VECTOR *)object->pos);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    object = object->sibling;
    njPushMatrix(NULL);
    njTranslateV(NULL, (NJS_VECTOR *)object->pos);
    njTranslate(NULL, 0.0F, height, 0.0F);
    TURN(njRotateZ, rock);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    late_DrawObjectClipEx(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
