/* @unit 0CB81180-0CB813E0 +egflags +pool32 */
/* an event's E-103, which draws the model each event defines */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/ground.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "event/event.h"
#include "shared/e103.h"
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
void CharacterShadow(struct task_work *work, struct shadow *shadow);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ExecEventFace(struct task_work *work);
struct task *CreateEventObject(void);
void EventObject(struct task *task);
struct task *event_e104_create(void);
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

/* his first step clears unk_00 and unk_08. nothing reads them */
#define VARS(work) ((struct e103_vars *)&(work)->vars)
struct e103_vars {
    Float unk_00;
    Uint8 unk_04[4];
    Uint32 unk_08;
};

/* each event that links e103.c defines these. the draw draws
 * event_e103_object while no motion is queued */
extern NJS_TEXLIST event_e103_texlist;
extern NJS_OBJECT event_e103_object;

void event_e103_destroy(struct task *task)
{
}

void event_e103_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct event_work *event = work->event;
    Angle ang;
    /* @hack redundant: 24 bytes of frame that no code reads, of a type unknown,
     * declared as under and slope. the image's ADD #-28,R15 reserves them
     * (0x0cb81098 in EV00B7); without them, 3 of 102 words differ */
    NJS_POINT3 under;
    struct angles slope;

    if (event->motions != NULL) {
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateZ, work->ang.z, ang);
        TURN_VIA(njRotateX, work->ang.x, ang);
        TURN_VIA(njRotateY, work->ang.y, ang);
        event_motions_draw(work);
        late_DrawObjectClipEx(1);
    } else {
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateZ, work->ang.z, ang);
        TURN_VIA(njRotateX, work->ang.x, ang);
        TURN_VIA(njRotateY, work->ang.y, ang);
        njSetTexture_jp(&event_e103_texlist);
        draw_set_palette(DRAW_PLAYER_PALETTE);
        late_DrawObject(&event_e103_object);
        draw_set_palette(0);
        late_DrawObjectClipEx(1);
    }
}

void event_e103_step(struct task *task)
{
    struct task_work *work = task->work;
    struct event_work *event = work->event;
    NJS_POINT3 under;
    struct angles slope;
    Float x;
    Float y;
    Float z;

    if (event->paths != NULL) {
        ExecEventPath(work);
    }
    x = work->pos.x;
    y = work->pos.y;
    z = work->pos.z;
    under.y = GetShadowPos(x, y, z, &slope);
    if (event->flags & EVENT_GROUND) {
        work->pos.y = under.y;
    }
    if (event->flags & EVENT_SLOPE) {
        work->ang.x = slope.x;
        work->ang.z = slope.z;
    }
    if (event->shadow > 0.0F) {
        under.x = x;
        under.y += SHADOW_LIFT;
        under.z = z;
        /* @hack spelling: work->event read again for the shadow's size (MOV.L
         * @(60,R14),R3 at 0x0cb811e6 in EV00B7), though R13 holds it as event;
         * without it, the step runs 4 bytes short and 22 of 81 words differ */
        shadow_draw_at(&slope, &under, work->event->shadow);
    }
    event_e103_draw(task);
}

void event_e103_init(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->unk_00 = 0.0F;
    VARS(work)->unk_08 = 0;
    task->step = event_e103_step;
    task->draw = event_e103_draw;
    task->destructor = event_e103_destroy;
}

struct task *event_e104_create(void)
{
    struct task *task;

    task = CreateElementalTask(TASK_WORK, 3, event_e103_init);
    if (task != NULL) {
        SetEventWork(task->work);
    }
    return task;
}
