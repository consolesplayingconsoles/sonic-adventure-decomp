/* @unit 0CB83660-0CB83980 +egflags +pool32 */
/* an event's props. each is a task in its slot of event_props, with its
 * record, struct prop, from the heap */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "event/event.h"
#include "shared/prop.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
void ExecEventFace(struct task_work *work);
struct task *CreateEventObject(void);
void EventObject(struct task *task);
void ev000c_egg_carrier_object(Float x, Float y, Float z, Angle ang_x,
                               Angle ang_y, Angle ang_z, Float scl_x,
                               Float scl_y, Float scl_z, NJS_OBJECT *object,
                               NJS_TEXLIST *texlist, int slot);
struct task *FUN_0cb8376e(int slot);
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

/* a prop's work mode: still, or playing its action */
#define PROP_STILL 0
#define PROP_PLAYING 1

/* a prop's record, which its destructor frees */
#define VARS(work) ((struct prop_vars *)&(work)->vars)
struct prop {
    NJS_OBJECT *object; /* drawn while action is -1 */
    NJS_ACTION *actions[EVENT_PROP_ACTIONS];
    Sint32 unk_2c; /* the create clears it, and nothing reads it */
    NJS_TEXLIST *texlist;
    Float speed; /* the action's frames advanced each step */
    Sint32 slot; /* the create sets it, and nothing reads it */
    Sint32 action; /* the index in actions of the one drawn, or -1 */
    Uint8 unk_40[4];
};

struct prop_vars {
    Float frame;
    /* the plays left, the one under way included. at 0 or below, the action
     * plays without end */
    Sint32 count;
    struct prop *prop;
};
extern struct task *event_props[10];

void event_prop_init(struct task *task);
void event_prop_step(struct task *task);
void event_prop_draw(struct task *task);
void event_prop_destroy(struct task *task);

void ev000c_egg_carrier_object(Float x, Float y, Float z, Angle ang_x,
                               Angle ang_y, Angle ang_z, Float scl_x,
                               Float scl_y, Float scl_z, NJS_OBJECT *object,
                               NJS_TEXLIST *texlist, int slot)
{
    struct task_work *work;
    struct prop *prop;
    int i;

    event_props[slot] = CreateElementalTask(TASK_WORK, 5, event_prop_init);
    prop = MAlloc(sizeof(struct prop));
    work = event_props[slot]->work;
    VARS(work)->prop = prop;
    work->mode = PROP_STILL;
    work->pos.x = x;
    work->pos.y = y;
    work->pos.z = z;
    work->ang.x = ang_x;
    work->ang.y = ang_y;
    work->ang.z = ang_z;
    work->scl.x = scl_x;
    work->scl.y = scl_y;
    work->scl.z = scl_z;
    VARS(work)->frame = 0.0F;
    prop->object = object;
    prop->texlist = texlist;
    prop->slot = slot;
    prop->action = -1;
    prop->unk_2c = 0;
    for (i = 0; i < EVENT_PROP_ACTIONS; i++) {
        prop->actions[i] = NULL;
    }
    SetEventWork(work);
}

void event_prop_set_action(int slot, NJS_ACTION *action, int number)
{
    struct task_work *work = event_props[slot]->work;
    struct prop *prop = VARS(work)->prop;

    prop->actions[number] = action;
}

void event_prop_play(int slot, int number, Float speed, int count)
{
    struct task_work *work = event_props[slot]->work;
    struct prop *prop = VARS(work)->prop;

    prop->action = number;
    prop->speed = speed;
    VARS(work)->count = count;
    VARS(work)->frame = 0.0F;
    work->mode = PROP_PLAYING;
}

void event_prop_stop(int slot)
{
    struct task_work *work = event_props[slot]->work;
    struct prop *prop = VARS(work)->prop;

    work->mode = PROP_STILL;
    prop->action = -1;
}

struct task *FUN_0cb8376e(int slot)
{
    return event_props[slot];
}

void event_prop_kill(int slot)
{
    if (event_props[slot] != NULL) {
        FreeTask(event_props[slot]);
        event_props[slot] = NULL;
    }
}

void event_prop_init(struct task *task)
{
    task->step = event_prop_step;
    task->draw = event_prop_draw;
    task->destructor = event_prop_destroy;
}

/* advance a playing action by speed. at the action's end, its frame goes
 * back to 0. the prop stands still there once its plays are done. then run
 * the prop's paths, and draw it */
void event_prop_step(struct task *task)
{
    struct task_work *work = task->work;
    struct prop *prop = VARS(work)->prop;

    switch (work->mode) {
    case PROP_STILL:
        break;
    case PROP_PLAYING:
        VARS(work)->frame += prop->speed;
        if (VARS(work)->frame >=
            (Float)prop->actions[prop->action]->motion->nbFrame) {
            VARS(work)->frame = 0.0F;
            if (VARS(work)->count >= 0) {
                VARS(work)->count--;
                if (VARS(work)->count == 0) {
                    work->mode = PROP_STILL;
                }
            }
        }
    }
    if (work->event->paths != NULL) {
        ExecEventPath(work);
    }
    event_prop_draw(task);
}

void event_prop_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct prop *prop = VARS(work)->prop;
    Angle ang;

    njSetTexture_jp(prop->texlist);
    draw_set_palette(DRAW_PLAYER_PALETTE);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njScaleV(NULL, &work->scl);
    if (prop->action >= 0) {
        ds_ActionClip(prop->actions[prop->action],
                      ((struct prop_vars *)&(work)->vars)->frame);
    } else {
        late_DrawObject(prop->object);
    }
    late_DrawObjectClipEx(1);
    draw_set_palette(0);
}

void event_prop_destroy(struct task *task)
{
    struct task_work *work = task->work;
    struct prop *prop = VARS(work)->prop;

    if (prop != NULL) {
        Free(prop);
    }
}
