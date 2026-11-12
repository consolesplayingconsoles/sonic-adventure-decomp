/* @unit 0CB80768-0CB80940 @data 0CB81168-0CB81174 +egflags +pool32 */
/* the fountain: O AR_FUN, four jets of water whose texture runs down them */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_garden00/fountain.h"
#include "al_garden00/fountain_object.h"
#include "al_garden00/textures.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
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
void FUN_8c6409c0(Int loc, Int val, Int digit);
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
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
extern Sint8 fountain_uv_speed;

#define RANGE (1200.0F * 1200.0F)

/* the draw takes the jets as JETS meshsets of JET_UVS UVs each */
#define JETS 4
#define JET_UVS 40

/* the jets' v runs down by this plus 8 a step, wrapping at 256. the set
 * editor prints UVSPEED as this plus the placement's x angle, which the draw
 * doesn't add */

void fountain_draw(struct task *task);
void fountain_init(struct task *task);
void fun_0cb80744(struct task *task);

void fountain_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (OnEdit(task)) {
        njPrintC(((18) << 16 | ((16))), "UVSPEED:");
        FUN_8c6409c0(((32) << 16 | (16)),
                     (Uint8)(work->ang.x + fountain_uv_speed), 3);
    }
    fountain_draw(task);
    work->timer++;
}

/* draw the jets with their v run down by work->timer. for the draw, the
 * meshsets point at a copy of their UVs on the stack, then at their own
 * again */
void fountain_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = &fountain_object;
    Uint32 scroll = (Uint8)(work->timer * (fountain_uv_speed + 8));
    NJS_MESHSET *meshset;
    NJS_COLOR uvs[JETS * JET_UVS];
    NJS_COLOR *saved[JETS];
    NJS_COLOR *from;
    NJS_COLOR *to;
    int i;
    int j;
    Angle ang;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    njSetTexture_jp(&garden_objects_texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    meshset = object->model->meshsets;
    /* @bug memory: fountain_object's model has one meshset, whose four
     * strips take all JET_UVS of the model's UVs. so this loop and the one
     * after the draw take the model's points as three more meshsets: they
     * read UVs through them and store into them (CMP/GE R13,R6 at
     * 0x0cb808f6, R13 set to JETS at 0x0cb80866, ADD #24,R7 at 0x0cb808fa).
     * nothing runs fountain_step, so neither loop runs */
    for (i = 0; i < JETS; ++i, ++meshset) {
        /* @hack spelling: offset, an int copy of scroll for each jet, which
         * keeps the image's MOV R9,R12 at 0x0cb8087e; without it, 41 of 135
         * words differ */
        int offset = scroll;

        j = JET_UVS;
        from = meshset->vertuv;
        to = &uvs[i * JET_UVS];
        saved[i] = from;
        meshset->vertuv = to;
        while (j--) {
            to->tex.u = from->tex.u;
            to->tex.v = from->tex.v - offset;
            ++from;
            ++to;
        }
    }
    ds_DrawModelClip(object->model);
    meshset = object->model->meshsets;
    for (i = 0; i < JETS; ++i, ++meshset) {
        meshset->vertuv = saved[i];
    }
    late_DrawObjectClipEx(1);
}
