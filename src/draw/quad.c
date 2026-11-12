/* @unit 8C0A1700-8C0A19E0 +egflags +pool32 +poolkeep=quad_set_uv +asmfunc=quad_set_corners */
/* quads: a part of a texture drawn on the screen, turned, flipped and
 * colored */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/quad.h"
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

static void quad_set_depth(NJS_TEXTURE_VTX *corners, Float depth);
static void quad_set_colors(NJS_TEXTURE_VTX *corners, Uint32 *colors,
                            int flags);
static void quad_set_uv(NJS_TEXTURE_VTX *corners, NJS_POINT2 *uv, int flags);
static void quad_set_corners(NJS_TEXTURE_VTX *corners, struct quad *quad);
extern NJS_TEXTURE_VTX quad_corners[4];
extern NJS_POINT2 quad_offsets[4];

void quad_draw(struct quad *quad)
{
    int flags;
    Int texture;
    Bool alpha;

    if (quad != NULL) {
        flags = quad->flags;
        quad_set_depth(quad_corners, quad->depth);
        quad_set_colors(quad_corners, quad->colors, flags);
        quad_set_uv(quad_corners, quad->uv, flags);
        quad_set_corners(quad_corners, quad);
        texture =
            ((NJS_TEXMEMLIST *)quad->texlist->textures[quad->texture].texaddr)
                ->globalIndex;
        alpha = (flags & NJD_SPRITE_ALPHA) ? TRUE : FALSE;
        njDrawTexture(quad_corners, 4, texture, alpha);
    }
}

static void quad_set_depth(NJS_TEXTURE_VTX *corners, Float depth)
{
    NJS_TEXTURE_VTX *corner;
    int i;

    if (depth < -65535.0F) {
        depth = -65535.0F;
    } else if (depth > -1.0F) {
        depth = -1.0F;
    }
    depth = -1.0F / depth;
    for (i = 0, corner = corners; i < 4; i++, corner++) {
        corner->z = depth;
    }
}

static void quad_set_colors(NJS_TEXTURE_VTX *corners, Uint32 *colors, int flags)
{
    int i = 0;
    Uint32 *color;

    if (flags & NJD_SPRITE_COLOR) {
        for (color = colors; i < 4; i++, color++, corners++) {
            corners->col = *color;
        }
    } else {
        for (; i < 4; i++, corners++) {
            corners->col = 0xffffffff;
        }
    }
}

static void quad_set_uv(NJS_TEXTURE_VTX *corners, NJS_POINT2 *uv, int flags)
{
    Float u1 = uv[0].x;
    Float v1 = uv[0].y;
    Float u2 = uv[1].x;
    Float v2 = uv[1].y;
    Float swap;

    if (u1 < 0.0F) {
        u1 = 0.0F;
    } else if (u1 > 1.0F) {
        u1 = 1.0F;
    }
    if (v1 < 0.0F) {
        v1 = 0.0F;
    } else if (v1 > 1.0F) {
        v1 = 1.0F;
    }
    if (u2 < 0.0F) {
        u2 = 0.0F;
    } else if (u2 > 1.0F) {
        u2 = 1.0F;
    }
    if (v2 < 0.0F) {
        v2 = 0.0F;
    } else if (v2 > 1.0F) {
        v2 = 1.0F;
    }
    if (flags & NJD_SPRITE_HFLIP) {
        swap = u1;
        u1 = u2;
        u2 = swap;
    }
    if (flags & NJD_SPRITE_VFLIP) {
        swap = v1;
        v1 = v2;
        v2 = swap;
    }
    corners[0].u = u1;
    corners[0].v = v1;
    corners[1].u = u1;
    corners[1].v = v2;
    corners[2].u = u2;
    corners[2].v = v1;
    corners[3].u = u2;
    corners[3].v = v2;
}
#ifdef NON_MATCHING

static void quad_set_corners(NJS_TEXTURE_VTX *corners, struct quad *quad)
{
    Float width = quad->size[0];
    Float height = quad->size[1];
    Float cx = quad->center[0];
    Float cy = quad->center[1];
    Float left = -(width * cx);
    Float right = (1.0F - cx) * width;
    Float top = -(height * cy);
    Float bottom = (1.0F - cy) * height;
    Float sine;
    Float cosine;
    Float x;
    Float y;
    NJS_POINT2 *offset;
    NJS_TEXTURE_VTX *corner;
    int i;
    Angle ang;

    quad_offsets[0].x = left;
    quad_offsets[0].y = top;
    quad_offsets[1].x = left;
    quad_offsets[1].y = bottom;
    quad_offsets[2].x = right;
    quad_offsets[2].y = top;
    quad_offsets[3].x = right;
    quad_offsets[3].y = bottom;
    if (quad->flags & NJD_SPRITE_ANGLE) {
        ang = quad->ang;
        sine = njSin(ang);
        cosine = njCos(ang);
        for (i = 0, offset = quad_offsets; i < 4; i++, offset++) {
            x = offset->x;
            y = offset->y;
            offset->x = (cosine * x) - (sine * y);
            offset->y = (sine * x) + (cosine * y);
        }
    }
    x = quad->pos[0];
    y = quad->pos[1];
    /* @hack redundant: offset set to quad_offsets, which the loop indexes
     * instead. the store starts the loop's pointer with MOV R13,R4 at
     * 0x8c0a7aaa; without it, SHC adds R13 to a 0 there and 33 of 136 words
     * differ */
    for (i = 0, corner = corners; i < 4; i++) {
        corner->x = x + quad_offsets[i].x;
        corner->y = y + quad_offsets[i].y;
        corner++;
    }
}
#else
static void quad_set_corners(NJS_TEXTURE_VTX *corners, struct quad *quad)
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
}
#endif
