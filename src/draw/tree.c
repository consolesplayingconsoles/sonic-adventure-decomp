/* @unit 8C036BC0-8C036F60 +jpflags +pool32 */
/* model trees: drawn node by node, as each node's evalflags say */
#include <ninja.h>

#include "draw/model.h"
#include "draw/tree.h"
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
void FUN_8c037098(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);

/* the evalflags bits that each spare a node one move: its translation,
 * its rotation or its scale */
#define UNIT_ALL (NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL)

/* draw a node and each sibling after it, with the nodes under each */
static void draw_nodes(NJS_OBJECT *node)
{
    do {
        switch (node->evalflags & (0x01 | 0x02 | 0x04)) {
        case (0x01 | 0x02 | 0x04):
            if (!(node->evalflags & 0x08)) {
                FUN_8c037098(node->model);
            }
            if (!(node->evalflags & NJD_EVAL_BREAK)) {
                draw_nodes(node->child);
            }
            break;
        case 0:
            njPushMatrix(NULL);
            njTranslate(NULL, node->pos[0], node->pos[1], node->pos[2]);
            if (node->evalflags & NJD_EVAL_ZXY_ANG) {
                njRotateZXY(NULL, node->ang[0], node->ang[1], node->ang[2]);
            } else {
                njRotateXYZ(NULL, node->ang[0], node->ang[1], node->ang[2]);
            }
            njScale(((void *)0), node->scl[0], node->scl[1], node->scl[2]);
            if (!(node->evalflags & 0x08)) {
                FUN_8c037098(node->model);
            }
            if (!(node->evalflags & NJD_EVAL_BREAK)) {
                draw_nodes(node->child);
            }
            late_DrawObjectClipEx(1);
            break;
        case NJD_EVAL_UNIT_POS:
            njPushMatrix(NULL);
            if (node->evalflags & NJD_EVAL_ZXY_ANG) {
                njRotateZXY(NULL, node->ang[0], node->ang[1], node->ang[2]);
            } else {
                njRotateXYZ(NULL, node->ang[0], node->ang[1], node->ang[2]);
            }
            njScale(((void *)0), node->scl[0], node->scl[1], node->scl[2]);
            if (!(node->evalflags & 0x08)) {
                FUN_8c037098(node->model);
            }
            if (!(node->evalflags & NJD_EVAL_BREAK)) {
                draw_nodes(node->child);
            }
            late_DrawObjectClipEx(1);
            break;
        case 0x02:
            njPushMatrix(((void *)0));
            njTranslate(((void *)0), node->pos[0], node->pos[1], node->pos[2]);
            njScale(((void *)0), node->scl[0], node->scl[1], node->scl[2]);
            if (!(node->evalflags & 0x08)) {
                FUN_8c037098(node->model);
            }
            if (!(node->evalflags & NJD_EVAL_BREAK)) {
                draw_nodes(node->child);
            }
            late_DrawObjectClipEx(1);
            break;
        case 0x01 | 0x02:
            njPushMatrix(((void *)0));
            njScale(((void *)0), node->scl[0], node->scl[1], node->scl[2]);
            if (!(node->evalflags & 0x08)) {
                FUN_8c037098(node->model);
            }
            if (!(node->evalflags & NJD_EVAL_BREAK)) {
                draw_nodes(node->child);
            }
            late_DrawObjectClipEx(1);
            break;
        case NJD_EVAL_UNIT_SCL:
            njPushMatrix(NULL);
            njTranslate(NULL, node->pos[0], node->pos[1], node->pos[2]);
            if (node->evalflags & NJD_EVAL_ZXY_ANG) {
                njRotateZXY(NULL, node->ang[0], node->ang[1], node->ang[2]);
            } else {
                njRotateXYZ(NULL, node->ang[0], node->ang[1], node->ang[2]);
            }
            if (!(node->evalflags & 0x08)) {
                FUN_8c037098(node->model);
            }
            if (!(node->evalflags & NJD_EVAL_BREAK)) {
                draw_nodes(node->child);
            }
            late_DrawObjectClipEx(1);
            break;
        case NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_SCL:
            njPushMatrix(NULL);
            if (node->evalflags & NJD_EVAL_ZXY_ANG) {
                njRotateZXY(NULL, node->ang[0], node->ang[1], node->ang[2]);
            } else {
                njRotateXYZ(NULL, node->ang[0], node->ang[1], node->ang[2]);
            }
            if (!(node->evalflags & 0x08)) {
                FUN_8c037098(node->model);
            }
            if (!(node->evalflags & NJD_EVAL_BREAK)) {
                draw_nodes(node->child);
            }
            late_DrawObjectClipEx(1);
            break;
        case 0x02 | 0x04:
            njPushMatrix(((void *)0));
            njTranslate(((void *)0), node->pos[0], node->pos[1], node->pos[2]);
            if (!(node->evalflags & 0x08)) {
                FUN_8c037098(node->model);
            }
            if (!(node->evalflags & NJD_EVAL_BREAK)) {
                draw_nodes(node->child);
            }
            late_DrawObjectClipEx(1);
            break;
        }
        node = node->sibling;
    } while (node != NULL);
}

void late_DrawObject(NJS_OBJECT *object)
{
    njGetkmPointer_jp();
    draw_nodes(object);
    njSetkmPointer_jp();
}
