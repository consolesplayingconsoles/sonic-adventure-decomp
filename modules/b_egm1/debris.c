/* @unit 0C901C00-0C9020E0 +jpflags +pool32 */
/* debris: a piece for each node of a model. each is flung out from the
 * model's position, and falls leaving a trail */
#include <ninja.h>
#include <sg_xpt.h>

#include "b_egm1/debris.h"
#include "b_egm1/util.h"
#include "draw/model.h"
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
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

/* the piece of one node */
#define DEBRIS_GRAVITY (-0.04F)
struct debris_piece {
    NJS_MATRIX matrix; /* its node's matrix, without the translation */
    /* its node's model, or null for a piece that never draws */
    NJS_MODEL *model;
    NJS_VECTOR speed;
    NJS_VECTOR accel;
    struct angles spin; /* its angles' change each step */
    Uint16 delay; /* nothing reads it */
    NJS_POINT3 pos;
    struct angles ang; /* the draw doesn't read it */
};

/* the debris's record, its task's extra */
struct debris {
    NJS_TEXLIST *texlist;
    struct debris_piece *pieces;
    void (*trail)(NJS_POINT3 *pos, int steps);
    Sint32 steps; /* the steps it has flown */
    Uint16 count; /* its pieces, one for each node */
};
extern Float egg_hornet_debris_rise;
/* added to each piece's y speed each step */

/* add a piece for object's node. then add one for each node of its
 * children's and its later siblings' trees, in order. parent places
 * object's node, and each piece takes its node's place and turn from there.
 * *index counts the pieces. the first piece never draws, even where its node
 * has a model */
void egg_hornet_debris_add_node(struct debris *debris, Uint16 *index,
                                NJS_OBJECT *object, NJS_MATRIX *parent)
{
    NJS_MATRIX matrix;
    struct debris_piece *piece = &debris->pieces[*index];

    njSetMatrix(&matrix, parent);
    njTranslate(&matrix, object->pos[0], object->pos[1], object->pos[2]);
    njRotateXYZ(&matrix, object->ang[0], object->ang[1], object->ang[2]);
    /* a node without a model takes a piece that never draws */
    if ((piece->model = object->model) != NULL) {
        njGetTranslation(&matrix, &piece->pos);
        njSetMatrix(&piece->matrix, &matrix);
        matrix_clear_translation(&piece->matrix);
    }
    if (*index == 0) {
        piece->model = NULL;
    }
    ++*index;
    if (object->child != NULL) {
        egg_hornet_debris_add_node(debris, index, object->child, &matrix);
    }
    if (object->sibling != NULL) {
        egg_hornet_debris_add_node(debris, index, object->sibling, parent);
    }
}

/* add a piece for each node of config's object, at config's position and
 * angles, at twice its size */
void egg_hornet_debris_add_tree(struct debris *debris, Uint16 *index,
                                struct debris_config *config)
{
    NJS_MATRIX matrix;

    njUnitMatrix(&matrix);
    njTranslateV(&matrix, config->pos);
    matrix_turn_zxy(&matrix, config->ang);
    njScale(&matrix, 2.0F, 2.0F, 2.0F);
    egg_hornet_debris_add_node(debris, index, config->object, &matrix);
}

/* fling each piece out from config's position in x and z, and up, with a
 * random spin. a piece right above or below the position goes out along
 * x */
void egg_hornet_debris_launch(struct debris *debris,
                              struct debris_config *config)
{
    Uint16 i;
    NJS_VECTOR dir;
    struct debris_piece *piece;

    for (i = 0; i < debris->count; ++i) {
        piece = &debris->pieces[i];
        piece->accel.x = piece->accel.z = 0.0F;
        piece->accel.y = DEBRIS_GRAVITY;
        piece->spin.x = random_spin(config->spin);
        piece->spin.y = random_spin(config->spin);
        piece->spin.z = random_spin(config->spin);
        dir.x = piece->pos.x - config->pos->x;
        dir.y = 0.0F;
        dir.z = piece->pos.z - config->pos->z;
        if (njScalor(&dir) == 0.0F) {
            dir.x = 0.01F;
        }
        njUnitVector(&dir);
        piece->speed.x = dir.x * config->speed;
        piece->speed.y = egg_hornet_debris_rise;
        piece->speed.z = dir.z * config->speed;
        piece->delay = config->delay * i;
    }
}

void egg_hornet_debris_init(struct task *task, struct debris_config *config)
{
    struct debris *debris = task->extra;
    /* @hack redundant: a matrix no code uses, which SHC still makes room for in
     * the frame (ADD #-64,R15 at 0x0c901fe6); without it, 35 of 39 words
     * differ */
    NJS_MATRIX matrix;

    debris->pieces = MAlloc((Uint16)tree_count_nodes(config->object) *
                            sizeof(struct debris_piece));
    debris->texlist = config->texlist;
    debris->count = 0;
    debris->trail = config->trail;
    debris->steps = 0;
    egg_hornet_debris_add_tree(debris, &debris->count, config);
    egg_hornet_debris_launch(debris, config);
}

void egg_hornet_debris_draw(struct task *task);

void egg_hornet_debris_step(struct task *task)
{
    struct debris *debris = task->extra;
    Uint16 i;
    struct debris_piece *piece;
    NJS_POINT3 pos;
    Float top = 0.0F;

    ++debris->steps;
    for (i = 0; i < debris->count; ++i) {
        piece = &debris->pieces[i];
        if (piece->model != NULL) {
            piece->pos.x = piece->pos.x + piece->speed.x;
            piece->pos.y = piece->pos.y + piece->speed.y;
            piece->pos.z = piece->pos.z + piece->speed.z;
            piece->speed.x = piece->speed.x + piece->accel.x;
            piece->speed.y = piece->speed.y + piece->accel.y;
            piece->speed.z = piece->speed.z + piece->accel.z;
            piece->ang.x = piece->ang.x + piece->spin.x;
            piece->ang.y = piece->ang.y + piece->spin.y;
            piece->ang.z = piece->ang.z + piece->spin.z;
            VECTOR_COPY(&pos, &piece->pos);
            if (debris->trail != NULL) {
                debris->trail(&pos, debris->steps);
            }
            if (pos.y > top) {
                top = pos.y;
            }
        }
    }
    if (top <= 0.0F) {
        Free(debris->pieces);
        FreeTask(task);
    } else {
        egg_hornet_debris_draw(task);
    }
}

void egg_hornet_debris_draw(struct task *task)
{
    struct debris *debris = task->extra;
    Uint16 i;
    struct debris_piece *piece;

    njSetTexture_jp(debris->texlist);
    for (i = 0; i < debris->count; ++i) {
        piece = &debris->pieces[i];
        if (piece->model != NULL) {
            njPushMatrix(NULL);
            njTranslateV(NULL, &piece->pos);
            njMultiMatrix(NULL, &piece->matrix);
            ds_DrawModelClip(piece->model);
            late_DrawObjectClipEx(1);
        }
    }
}

void egg_hornet_debris_create(struct debris_config *config)
{
    struct task *task;
    struct debris *debris;

    if ((task = CreateElementalTask(0, 3, egg_hornet_debris_step)) != NULL) {
        debris = CAlloc(1, sizeof(struct debris));
        task->extra = debris;
        egg_hornet_debris_init(task, config);
        task->step = egg_hornet_debris_step;
        task->draw = egg_hornet_debris_draw;
    }
}
