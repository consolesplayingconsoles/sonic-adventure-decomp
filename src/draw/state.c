/* @unit 8C09FF80-8C0A0160 +egflags -noinline +poolafter=sprite_anim_step +pool32 */
/* Ninja's draw state: its 3D control flags and constant attributes, saved
 * around a draw and set for a translucent one. also a task that plays a
 * sprite's texture animation */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/state.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/task_desc.h"
#include "system/util.h"
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c60ed26(Uint32 and_attr, Uint32 or_attr);
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
void FUN_8c09ffe0(void);
void FUN_8c0a000a(Uint32 clear_attr, Uint32 set_attr);
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
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);
void *syMalloc_default_malloc(size_t size);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
void OnConstantAttr(Uint32 and_attr, Uint32 or_attr);
void OffConstantAttr(Uint32 and_attr, Uint32 or_attr);
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

/* the record sprite_anim_desc gives its task, in task->motion. the task
 * draws sprite->tanim[frame], and frame runs from 0 to count - 1 */
#define SPRITE_ANIM(task) ((struct sprite_anim *)(task)->motion)
struct sprite_anim {
    Sint16 frame;
    Sint16 count;
    NJS_SPRITE *sprite;
    Uint32 attr; /* njDrawSprite3D's flags */
};

/* the arg sprite_anim_desc's creator passes, which sprite_anim_init copies */
struct sprite_anim_arg {
    Sint16 count;
    NJS_SPRITE *sprite;
    Uint32 attr;
};

void sprite_anim_init(struct task *task, void *arg);
void sprite_anim_step(struct task *task);
void sprite_anim_draw(struct task *task);
extern const struct task_desc sprite_anim_desc;
extern const NJS_ARGB draw_state_no_material;
extern NJS_ARGB translucent_material;

void sprite_turn_x(struct angles *ang)
{
    TURN(njRotateX, ang->x);
}

void sprite_turn_y(struct angles *ang)
{
    TURN(njRotateY, ang->y);
}

void sprite_turn_z(struct angles *ang)
{
    TURN(njRotateZ, ang->z);
}

void FUN_8c09ffe0(void)
{
    SaveControl3D();
    SaveConstantAttr();
}

void draw_state_restore(void)
{
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    LoadControl3D();
    LoadConstantAttr();
    njSetConstantMaterial((NJS_ARGB *)&draw_state_no_material);
}
#pragma inline(FUN_8c0a000a)
void FUN_8c0a000a(Uint32 clear_attr, Uint32 set_attr)
{
    draw_control_set(0x00000004);
    FUN_8c60ed26(~clear_attr, set_attr);
}

void draw_translucent(Float alpha)
{
    njColorBlendingMode_jp(0, 1);
    draw_control_clear(0x00000020);
    draw_control_set(0x00000010);
    FUN_8c0a000a(0, 0x00100000);
    translucent_material.a = alpha;
    njSetConstantMaterial(&translucent_material);
}

void sprite_anim_init(struct task *task, void *arg)
{
    struct sprite_anim *anim = SPRITE_ANIM(task);
    struct sprite_anim_arg *from = arg;

    anim->frame = 0;
    anim->count = from->count;
    anim->sprite = from->sprite;
    anim->attr = from->attr;
}

void sprite_anim_step(struct task *task)
{
    struct sprite_anim *anim = SPRITE_ANIM(task);

    sprite_anim_draw(task);
    anim->frame++;
    if (anim->frame >= anim->count) {
        anim->frame = 0;
    }
}

/* draw only on a frame's first step, while frame_step is 0 */
void sprite_anim_draw(struct task *task)
{
    struct sprite_anim *anim;
    struct task_work *work;
    struct angles *ang;

    if (!loop_count) {
        work = task->work;
        anim = SPRITE_ANIM(task);
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        ang = &work->ang;
        sprite_turn_z(ang);
        sprite_turn_y(ang);
        sprite_turn_x(ang);
        njDrawSprite3D(anim->sprite, anim->frame, anim->attr);
        late_DrawObjectClipEx(1);
    }
}
