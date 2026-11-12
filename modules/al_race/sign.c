/* @unit 0CB960C0-0CB961E0 @data 0CB9A698-0CB9A6B0 +r04 +egflags +pool32 */
/* the Chao race hall's sign, whose face shows each of two textures in
 * turn */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_race/scenery.h"
#include "al_race/sign.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/task_desc.h"
#include "system/texture.h"
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
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);
extern struct set_file *pObjEditTable;
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);

/* the sign's object and its face's material */
#define SIGN(task) ((struct sign *)(task)->motion)
#define SIDE_STEPS 36
extern NJS_OBJECT dat_0cbc8994;
extern NJS_MATERIAL dat_0cbc8570;

/* a face of the sign: its material, and its texture for each side */
struct sign_face {
    NJS_MATERIAL *material;
    Uint16 textures[2];
};

/* what sign_start takes: the sign's object, and its count faces */
struct sign_kind {
    NJS_OBJECT *object;
    const struct sign_face *faces;
    Sint16 count;
};

/* the sign's state, in its task's motion. object, faces and count are the
 * sign_kind's */
struct sign {
    Sint16 side; /* the side shown, 0 or 1, which picks each face's texture */
    Sint16 timer; /* steps until the other side shows */
    NJS_OBJECT *object;
    const struct sign_face *faces;
    Sint16 count;
};

/* the steps each side of the sign shows */

void sign_start(struct task *task, void *arg);
void sign_step(struct task *task);
void sign_draw(struct task *task);
void sign_show(struct sign *sign);

static const struct task_desc sign_desc = {
    sizeof(struct sign), TASK_WORK, sign_start, sign_step, sign_draw, NULL};
extern const struct sign_face sign_faces[1];
extern const struct sign_kind sign_kind;

void sign_create(void)
{
    scenery_add(&sign_desc, (void *)&sign_kind);
}

void sign_start(struct task *task, void *arg)
{
    struct task_work *work = task->work;
    struct sign *sign = SIGN(task);
    const struct sign_kind *kind = arg;
    NJS_OBJECT *object = kind->object;

    scenery_place(work, object);
    sign->side = 0;
    sign->timer = SIDE_STEPS;
    sign->object = object;
    sign->faces = kind->faces;
    sign->count = kind->count;
    sign_show(sign);
}

void sign_step(struct task *task)
{
    struct sign *sign;

    sign_draw(task);
    sign = SIGN(task);
    sign->timer--;
    if (sign->timer <= 0) {
        sign->timer = SIDE_STEPS;
        sign->side++;
        if (sign->side >= 2) {
            sign->side = 0;
        }
        sign_show(sign);
    }
}

void sign_draw(struct task *task)
{
    struct sign *sign;

    if (loop_count == 0 && !CheckRange(task)) {
        sign = SIGN(task);
        SetObjectTexture();
        late_DrawObject(sign->object);
    }
}

void sign_show(struct sign *sign)
{
    int count = sign->count;
    const struct sign_face *face;
    int i;

    for (i = 0, face = sign->faces; i < count; i++, face++) {
        face->material->attr_texId = face->textures[sign->side];
    }
}
