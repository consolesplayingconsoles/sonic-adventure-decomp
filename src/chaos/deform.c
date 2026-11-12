/* @unit 8C0F16C0-8C0F1B80 +egflags +r04 +onepool +pool32 +asmfunc=deform_step */
/* a Chaos's model melted down and out, and put back */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <string.h>

#include "chaos/deform.h"
#include "chaos/steer.h"
#include "draw/motion.h"
#include "draw/pose.h"
#include "system/task.h"
#include "system/util.h"
float njFloor(float x);
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
void *memmove(void *s1, const void *s2, size_t n);
extern Sint8 chaos_reqmode;
Bool CalcMMMatrix(NJS_MATRIX *base, NJS_ACTION *action, Float frame,
                  Uint32 node, NJS_MATRIX *out);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
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

/* the nodes a deformer has room for, and the deepest it walks */
#define DEFORM_NODES 120
#define DEFORM_DEPTH 12

/* a point of a node's model where the pose put it as the deformer was made.
 * ang_y and ang_z are its angles about the pose's y and z axes. DEFORM_MELT
 * reads ang_y, and nothing reads ang_z */
struct deform_point {
    Angle ang_y;
    Angle ang_z;
    NJS_POINT3 pos;
};
extern NJS_MATRIX deform_matrix;
#ifdef NON_MATCHING

void deform_step(struct deform *deform)
{
    switch (deform->mode) {
    case DEFORM_MAKE: {
        struct deform_node *node;
        struct deform_point *point;
        NJS_OBJECT *object;
        NJS_POINT3 *points;
        int size;
        int count;
        /* @hack redundant: register on i and j, which keeps i in R14 and j
         * in R13 (MOV #0,R14 at 0x8c0fca08, MOV #0,R13 at 0x8c0fca7c); as
         * plain ints, they take R8 and R10, the frame shrinks by 4 bytes,
         * and 224 of 382 words differ */
        register int i;
        register int j;

        node = deform->nodes;
        for (i = 0; i < deform->count; i++, node++) {
            node->points = NULL;
            object = node->object;
            if (object->model == NULL) {
                continue;
            }
            count = object->model->nbPoint;
            size = count * sizeof(NJS_POINT3);
            points = MAlloc(size);
            if (points == NULL) {
                for (;;) {
                }
            }
            node->points = points;
            memmove(points, object->model->points, size);
            /* @hack type: (Uint16)i, which narrows the node's number by
             * EXTU.W for the call (0x8c0fca54); as i, a plain MOV, and 1 of
             * 382 words differ */
            GetMMMatrix((Uint16)i, &deform_matrix);
            njPushMatrix(&deform_matrix);
            points = node->points;
            point = MAlloc(count * sizeof(struct deform_point));
            if (point == NULL) {
                for (;;) {
                }
            }
            node->posed = point;
            for (j = 0; j < count; j++) {
                njCalcPoint(NULL, points, &point->pos);
                point->ang_y = (Angle)(njArcTan2(point->pos.z, point->pos.x) *
                                       ANGLE_PER_RADIAN);
                point->ang_z = (Angle)(njArcTan2(point->pos.y, point->pos.x) *
                                       ANGLE_PER_RADIAN);
                points++;
                point++;
            }
            late_DrawObjectClipEx(1);
        }
    }
        /* fall through */
    case DEFORM_RESTORE: {
        struct deform_node *node;
        NJS_OBJECT *object;
        NJS_POINT3 *from;
        NJS_POINT3 *to;
        int count;
        /* @hack redundant: register on i and j, which keeps i in R4
         * (MOV #0,R4 at 0x8c0fcad0); as plain ints, i takes R13, the frame
         * shrinks by 4 bytes, and 133 of 382 words differ */
        register int i;
        register int j;

        for (i = 0, node = deform->nodes; i < deform->count; i++, node++) {
            object = node->object;
            if (object->model == NULL) {
                continue;
            }
            from = node->points;
            to = object->model->points;
            count = object->model->nbPoint;
            for (j = 0; j < count; j++) {
                *to++ = *from++;
            }
        }
        deform->mode = DEFORM_IDLE;
        break;
    }
    case DEFORM_IDLE:
        break;
    case DEFORM_MELT: {
        struct deform_node *node;
        struct deform_point *point;
        NJS_OBJECT *object;
        NJS_MODEL *model;
        NJS_POINT3 *from;
        NJS_POINT3 *to;
        Float share;
        Float reach;
        Float limit;
        Angle ang;
        int count;
        /* @hack redundant: register on i and j, which keeps i in R14
         * (MOV #0,R14 at 0x8c0fcba2); as plain ints, i takes a frame slot,
         * the frame shrinks by 8 bytes, deform.c's code runs 32 bytes short
         * and 190 of 382 words differ */
        register int i;
        register int j;

        njPushMatrix(&nj_unit_matrix_);
        share = 1.0F / chaos_params->melt_grain * chaos_params->height;
        reach = deform->scale * deform->scale * chaos_params->melt_spread;
        njTranslate(NULL, 0.0F, chaos_params->model_y, 0.0F);
        node = deform->nodes;
        for (i = 0; i < deform->count; i++, node++) {
            NJS_VECTOR offset = {0.0F, 0.0F, 0.0F};
            NJS_POINT3 pos;

            object = node->object;
            if (object->model == NULL) {
                continue;
            }
            /* @hack type: (Uint16)i, which narrows the node's number by
             * EXTU.W for the call (0x8c0fcbd8); as i, a plain MOV, and 1 of
             * 382 words differ */
            GetMMMatrix((Uint16)i, &deform_matrix);
            from = node->points;
            model = object->model;
            to = model->points;
            count = model->nbPoint;
            point = node->posed;
            njPushMatrix(NULL);
            njMultiMatrix(NULL, &deform_matrix);
            njInvertMatrix(&deform_matrix);
            for (j = 0; j < count; j++) {
                ang = point->ang_y;
                njCalcPoint(NULL, from, &pos);
                limit = deform->scale * (chaos_params->melt_grain + (j & 7)) *
                        share;
                offset.x = reach * njSin(ang);
                offset.y = -(pos.y > limit ? limit : pos.y);
                offset.z = reach * njCos(ang);
                njPushMatrix(&deform_matrix);
                njCalcVector(NULL, &offset, to);
                late_DrawObjectClipEx(1);
                njAddVector(to++, from++);
                point++;
            }
            late_DrawObjectClipEx(1);
        }
        late_DrawObjectClipEx(1);
        break;
    }
    case DEFORM_FREE: {
        struct deform_node *node;
        NJS_OBJECT *object;
        int i;

        for (i = 0, node = deform->nodes; i < deform->count; i++, node++) {
            object = node->object;
            if (object->model == NULL || node->points == NULL) {
                continue;
            }
            Free(node->points);
            Free(node->posed);
        }
        Free(deform->nodes);
        Free(deform);
        break;
    }
    }
}
#else
void deform_step(struct deform *deform)
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
    asm_stub[0] = 32;
    asm_stub[1] = 33;
    asm_stub[2] = 34;
    asm_stub[3] = 35;
    asm_stub[4] = 36;
    asm_stub[5] = 37;
    asm_stub[6] = 38;
    asm_stub[7] = 39;
    asm_stub[0] = 40;
    asm_stub[1] = 41;
    asm_stub[2] = 42;
    asm_stub[3] = 43;
    asm_stub[4] = 44;
    asm_stub[5] = 45;
    asm_stub[6] = 46;
    asm_stub[7] = 47;
    asm_stub[0] = 48;
    asm_stub[1] = 49;
    asm_stub[2] = 50;
    asm_stub[3] = 51;
    asm_stub[4] = 52;
    asm_stub[5] = 53;
    asm_stub[6] = 54;
    asm_stub[7] = 55;
    asm_stub[0] = 56;
    asm_stub[1] = 57;
    asm_stub[2] = 58;
    asm_stub[3] = 59;
    asm_stub[4] = 60;
    asm_stub[5] = 61;
    asm_stub[6] = 62;
    asm_stub[7] = 63;
    asm_stub[0] = 64;
    asm_stub[1] = 65;
    asm_stub[2] = 66;
    asm_stub[3] = 67;
    asm_stub[4] = 68;
    asm_stub[5] = 69;
    asm_stub[6] = 70;
    asm_stub[7] = 71;
    asm_stub[0] = 72;
    asm_stub[1] = 73;
    asm_stub[2] = 74;
    asm_stub[3] = 75;
    asm_stub[4] = 76;
    asm_stub[5] = 77;
    asm_stub[6] = 78;
    asm_stub[7] = 79;
    asm_stub[0] = 80;
    asm_stub[1] = 81;
    asm_stub[2] = 82;
    asm_stub[3] = 83;
    asm_stub[4] = 84;
    asm_stub[5] = 85;
    asm_stub[6] = 86;
    asm_stub[7] = 87;
    asm_stub[0] = 88;
    asm_stub[1] = 89;
    asm_stub[2] = 90;
    asm_stub[3] = 91;
    asm_stub[4] = 92;
    asm_stub[5] = 93;
    asm_stub[6] = 94;
    asm_stub[7] = 95;
    asm_stub[0] = 96;
    asm_stub[1] = 97;
    asm_stub[2] = 98;
    asm_stub[3] = 99;
    asm_stub[4] = 100;
    asm_stub[5] = 101;
    asm_stub[6] = 102;
    asm_stub[7] = 103;
    asm_stub[0] = 104;
    asm_stub[1] = 105;
    asm_stub[2] = 106;
    asm_stub[3] = 107;
    asm_stub[4] = 108;
    asm_stub[5] = 109;
    asm_stub[6] = 110;
    asm_stub[7] = 111;
    asm_stub[0] = 112;
    asm_stub[1] = 113;
    asm_stub[2] = 114;
    asm_stub[3] = 115;
    asm_stub[4] = 116;
    asm_stub[5] = 117;
    asm_stub[6] = 118;
    asm_stub[7] = 119;
    asm_stub[0] = 120;
    asm_stub[1] = 121;
    asm_stub[2] = 122;
    asm_stub[3] = 123;
    asm_stub[4] = 124;
    asm_stub[5] = 125;
    asm_stub[6] = 126;
    asm_stub[7] = 127;
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
    asm_stub[0] = 32;
    asm_stub[1] = 33;
    asm_stub[2] = 34;
    asm_stub[3] = 35;
    asm_stub[4] = 36;
    asm_stub[5] = 37;
    asm_stub[6] = 38;
    asm_stub[7] = 39;
    asm_stub[0] = 40;
    asm_stub[1] = 41;
    asm_stub[2] = 42;
    asm_stub[3] = 43;
    asm_stub[4] = 44;
    asm_stub[5] = 45;
    asm_stub[6] = 46;
    asm_stub[7] = 47;
    asm_stub[0] = 48;
    asm_stub[1] = 49;
    asm_stub[2] = 50;
    asm_stub[3] = 51;
    asm_stub[4] = 52;
    asm_stub[5] = 53;
    asm_stub[6] = 54;
    asm_stub[7] = 55;
    asm_stub[0] = 56;
    asm_stub[1] = 57;
    asm_stub[2] = 58;
    asm_stub[3] = 59;
    asm_stub[4] = 60;
    asm_stub[5] = 61;
    asm_stub[6] = 62;
}
#endif

struct deform *deform_create(NJS_OBJECT *root, struct task_work *work)
{
    NJS_OBJECT *stack[DEFORM_DEPTH];
    NJS_OBJECT *object;
    struct deform *deform;
    struct deform_node *node;
    int depth;
    Bool more;
    Bool climb;

    depth = 0;
    more = TRUE;
    deform = CAlloc(1, sizeof(struct deform));
    if (deform == NULL) {
        for (;;) {
        }
    }
    deform->nodes = node = CAlloc(DEFORM_NODES, sizeof(struct deform_node));
    if (node == NULL) {
        for (;;) {
        }
    }
    object = root;
    deform->count = 0;
    do {
        node->object = object;
        node->depth = depth;
        deform->count++;
        node++;
        if (object->child != NULL) {
            stack[depth] = object;
            object = object->child;
            depth++;
        } else {
            climb = TRUE;
            do {
                if (object->sibling != NULL) {
                    object = object->sibling;
                    climb = FALSE;
                } else if (depth > 0) {
                    depth--;
                    object = stack[depth];
                } else {
                    more = climb = FALSE;
                }
            } while (climb);
        }
    } while (more);
    deform_step(deform);
    return deform;
}

void deform_free(struct deform *deform)
{
    deform->mode = DEFORM_FREE;
    deform_step(deform);
}

void fun_8c0fce40(struct deform *deform)
{
    deform->unk_0c = 1.0F;
    deform->unk_10 = 0.98F;
    deform->unk_18 = 0;
    deform->unk_24 = 0x400;
    deform->unk_1c = 0;
    deform->unk_24 = 0x200;
    deform->mode = DEFORM_HOLD;
}

void deform_use_moved(struct deform *deform)
{
    struct deform_node *node;
    NJS_OBJECT *object;
    int i;

    for (i = 0, node = deform->nodes; i < deform->count; i++, node++) {
        object = node->object;
        if (object->model == NULL) {
            continue;
        }
        object->model->points = node->moved;
    }
}
