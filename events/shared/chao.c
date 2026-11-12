/* @unit 0CB84BE0-0CB84F18 +r04 +egflags +pool32 +asmfunc=event_chao_show_eyes:0cb84f18 */
/* an event's Chao, which draws the model each event defines */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/ground.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "event/event.h"
#include "event/play.h"
#include "shared/chao.h"
#include "shared/chao_textures.h"
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
void FUN_8c60d138(void (*func)(NJS_OBJECT *obj));
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
void EV_Load2(int number);
void EV_Exec2(void);
Bool EV_CheckCansel(void);
Bool EV_CheckExec(int number);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z, Angle ang_x,
                     Angle ang_y, Angle ang_z);
void FUN_0cb84e16(struct task *task, int texture);
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

#define CHAO_LIFT 1.4F /* how far above the ground EVENT_GROUND stands it */

#define VARS(work) ((struct chao_vars *)&(work)->vars)
struct chao_vars {
    Sint32 eyes; /* the texture its eyes show, as event_chao_set_eyes takes */
};

/* each event that links chao.c defines these. the draw draws
 * event_chao_object while no motion is queued. every Chao of the event
 * shares the two eyes */
extern NJS_OBJECT event_chao_object;
extern NJS_OBJECT event_chao_body;
extern NJS_OBJECT event_chao_eye_minus_x;
extern NJS_OBJECT event_chao_eye_plus_x;

void event_chao_show_eyes(struct task_work *work, int texture);
void event_chao_turn_body(NJS_OBJECT *object);

void EV_Alife_dest(struct task *task)
{
    event_chao_show_eyes(task->work, CHAO_EYES_PLAIN);
}

void EV_Alife_draw(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: 24 bytes of frame that no code reads, of a type unknown,
     * declared as under and slope. the image's ADD #-28,R15 reserves them
     * (0x0cb80d06 in EV0022); without them, 2 of 108 words differ */
    NJS_POINT3 under;
    struct angles slope;
    Angle ang;

    FUN_8c60d138(event_chao_turn_body);
    if (work->event->motions != NULL) {
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
        njSetTexture_jp(&event_chao_texlist);
        draw_set_palette(DRAW_PLAYER_PALETTE);
        late_DrawObject(&event_chao_object);
        draw_set_palette(0);
        late_DrawObjectClipEx(1);
    }
    FUN_8c60d138(((void *)0));
}

void EV_Alife_exec(struct task *task)
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
        work->pos.y = under.y + CHAO_LIFT;
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
         * @(60,R14),R3 at 0x0cb80e66 in EV0022), though R13 holds it as event;
         * without it, the step runs 2 bytes short and 29 of 87 words differ */
        shadow_draw_at(&slope, &under, work->event->shadow);
    }
    event_chao_show_eyes(work, VARS(work)->eyes);
    EV_Alife_draw(task);
}

void EV_Alife_cons(struct task *task)
{
    VARS(task->work)->eyes = CHAO_EYES_PLAIN;
    task->step = EV_Alife_exec;
    task->draw = EV_Alife_draw;
    task->destructor = EV_Alife_dest;
}

struct task *EV_Alife(void)
{
    struct task *task;

    task = CreateElementalTask(TASK_WORK, 3, EV_Alife_cons);
    if (task != NULL) {
        SetEventWork(task->work);
    }
    return task;
}

void FUN_0cb84e16(struct task *task, int texture)
{
    if (task != NULL) {
        VARS(task->work)->eyes = texture;
    }
}

/* the motion callback the draw sets. as a motion draws each node, it turns
 * event_chao_body by the camera's y angle, then its x angle */
void event_chao_turn_body(NJS_OBJECT *object)
{
    Angle ang;

    if (object == &event_chao_body) {
        TURN_VIA(njRotateY, event_camera.ang.y, ang);
        TURN_VIA(njRotateX, event_camera.ang.x, ang);
    }
}
#ifdef NON_MATCHING

/* set texture on both eyes' material. every Chao of the event shares the eyes,
 * so each Chao's step sets its own before its draw */
void event_chao_show_eyes(struct task_work *work, int texture)
{
    /* @hack spelling: each eye's model read through the eye's address, which
     * the image pools and reads 4 bytes past (MOV.L @(4,R3),R2 at 0x0cb80f02 in
     * EV0022); without it, 7 of 9 words differ */
    (&event_chao_eye_minus_x)->model->mats[0].attr_texId = texture;
    (&event_chao_eye_plus_x)->model->mats[0].attr_texId = texture;
}
#else
void event_chao_show_eyes(struct task_work *work, int texture)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
}
#endif
