/* @unit 8C0957A0-8C097F20 +r04 +egflags +pool32 -aggressive=2 */
/* curves: records sampled round a closed curve through keys, and runs along
 * one axis */
#include <ninja.h>
#include <sg_xpt.h>

#include "path/curve.h"
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

#define FIELDS_MAX 19

/* lay out format's fields: offsets gets each field's offset, then the
 * record's size. returns the count of fields */
#define KEY_FIELD(type, n)                                                     \
    (*(type *)((char *)curve->keys + ((n) * size) + offsets[field]))
#define BLEND(type, a, b, c, d)                                                \
    (*(type *)(out + offsets[field]) =                                         \
         (weight[0] * KEY_FIELD(type, a)) + (weight[1] * KEY_FIELD(type, b)) + \
         (weight[2] * KEY_FIELD(type, c)) + (weight[3] * KEY_FIELD(type, d)))
#define SAMPLE(type)                                                           \
    do {                                                                       \
        if (key == 0) {                                                        \
            BLEND(type, curve->count - 1, 0, 1, 2);                            \
        } else if (key == curve->count - 2) {                                  \
            BLEND(type, key - 1, key, key + 1, 0);                             \
        } else if (key == curve->count - 1) {                                  \
            BLEND(type, key - 1, key, 0, 1);                                   \
        } else {                                                               \
            BLEND(type, key - 1, key, key + 1, key + 2);                       \
        }                                                                      \
    } while (0)
int layout_fields(const char *format, int *offsets)
{
    int offset = 0;
    int i = 0;
    int align = 1;
    int pad;

    for (; *format != '\0'; format++, i++) {
        switch (*format) {
        case 'c':
        case 'C':
            offsets[i] = offset;
            offset++;
            break;
        case 's':
        case 'S':
            offset += offset % 2;
            offsets[i] = offset;
            offset += 2;
            if (align < 2) {
                align = 2;
            }
            break;
        case 'l':
        case 'L':
        case 'I':
        case 'i':
        case 'F':
        case 'f':
        case 'A':
        case 'a':
            pad = offset % 4;
            if (pad != 0) {
                offset += 4 - pad;
            }
            offsets[i] = offset;
            offset += 4;
            if (align < 4) {
                align = 4;
            }
            break;
        default:
#ifdef GCC
            /* stops on a letter with no case, as the shipped store's fault
             * does. GCC splits a store to address 1 into byte stores, which
             * don't fault */
            for (;;) {
            }
#else
            *(int *)1 = 0;
#endif
            break;
        }
    }
    if (offset % align != 0) {
        offset = ((offset / align) + 1) * align;
    }
    offsets[i] = offset;
    return i;
}

/* the field at offsets[field] of key n */

/* set out's field to the sum of keys a to d's, each times its weight */

/* set out's field from the four keys round key, key - 1 to key + 2, which
 * wrap round the loop */

int CalcSpline(struct path_curve *curve)
{
    int offsets[FIELDS_MAX + 1]; /* one per field, then the record's size */
    int size;
    int key;
    int field;
    Float weight[4];
    Float part;
    /* @hack redundant: records zeroed here and again before the loop, the
     * image's two stores (0x8c09b002, 0x8c09b01e); without it, the function
     * runs 32 bytes short and 4,293 of 4,417 words differ */
    int records = 0;
    int fields;
    const char *format;
    char *out;
    Float part_to[4]; /* part to the power of the index, 2 or 3 */
    Float rest_to[4]; /* 1 - part to the power of the index, 1 to 3 */

    fields = layout_fields(curve->format, offsets);
    size = offsets[fields];
    records = 0;
    for (key = 0; key < curve->count; key++) {
        /* NOLINTNEXTLINE(bugprone-float-loop-counter) */
        for (part = 0.0F; part <= 1.0F - curve->step; part += curve->step) {
            switch (curve->kind) {
            case PATH_CURVE_LAGRANGE:
#ifdef GCC
                /* weight[0] negates the product, then multiplies by 1/6,
                 * 0x3e2aaaaa, as SHC's code under -aggressive=2 does
                 * (0x8c09b0a2, 0x8c09b0a4). GCC would divide by 6 where SHC's
                 * side divides */
                weight[0] =
                    -((part - 1.0F) * (part - 2.0F) * part) * (1.0F / 6.0F);
#else
                weight[0] = -((part - 1.0F) * (part - 2.0F) * part) / 6.0F;
#endif
                weight[1] =
                    (part + 1.0F) * (part - 1.0F) * (part - 2.0F) * 0.5F;
                weight[2] = (-1.0F - part) * (part - 2.0F) * part * 0.5F;
                /* weight[3] multiplies by 1/6, 0x3e2aaaaa, as SHC's code
                 * under -aggressive=2 does */
                weight[3] =
                    (part + 1.0F) * (part - 1.0F) * part * (1.0F / 6.0F);
                break;
            case PATH_CURVE_BSPLINE:
            default:
                part_to[2] = part * part;
                part_to[3] = part_to[2] * part;
                rest_to[1] = 1.0F - part;
                rest_to[2] = (1.0F - part) * (1.0F - part);
                rest_to[3] = rest_to[1] * rest_to[2];
                /* weight[0] and weight[3] multiply by 1/6, 0x3e2aaaaa, as SHC's
                 * code under -aggressive=2 does */
                weight[0] = rest_to[3] * (1.0F / 6.0F);
                weight[1] = (part_to[3] * 0.5F) - part_to[2] + (2.0F / 3.0F);
                weight[2] = (-part_to[3] / 2.0F) + (part_to[2] * 0.5F) +
                            (part * 0.5F) + (1.0F / 6.0F);
                weight[3] = part_to[3] * (1.0F / 6.0F);
                break;
            }
            format = curve->format;
            out = (char *)curve->out + (size * records);
            for (field = 0; field < fields; format++, field++) {
                switch (*format) {
                case 'c':
                    SAMPLE(Uint8);
                    break;
                case 'C':
                    SAMPLE(Sint8);
                    break;
                case 's':
                    SAMPLE(Uint16);
                    break;
                case 'S':
                    SAMPLE(Sint16);
                    break;
                case 'l':
                    SAMPLE(Uint32);
                    break;
                case 'L':
                case 'A':
                case 'a':
                    SAMPLE(Sint32);
                    break;
                case 'I':
                case 'i':
                    SAMPLE(int);
                    break;
                case 'F':
                case 'f':
                    SAMPLE(Float);
                    break;
                }
            }
            records++;
        }
    }
    return records;
}

Float path_axis_position(const Float *stops, Float distance)
{
    /* @hack type: i a long, not an int, which has SHC add 1 to i before it
     * scales it to index stops[i + 1] (ADD #1,R0 at 0x8c09d94c); as an int,
     * 38 of 52 words differ */
    Sint32 i;
    Float length = 0.0F;
    Float before;

#ifdef GCC
    /* repairs a distance below 0, or NaN, where the image reads stops[-1]
     * and an unset local: GCC's run is still at its first stop */
    if (!(distance >= 0.0F)) {
        return stops[0];
    }
#endif
    for (i = 0; length <= distance; i++) {
        if (stops[i + 1] < 0.0F) {
            return stops[i];
        }
        before = length;
        length += njAbs(stops[i + 1] - stops[i]);
    }
    i--;
    if (stops[i + 1] - stops[i] > 0.0F) {
        return stops[i] + distance - before;
    }
    return stops[i] - distance + before;
}

Float path_axis_length(const Float *stops)
{
    /* @hack type: i a long, not an int, as in path_axis_position (ADD #1,R0
     * at 0x8c09d9ca); as an int, the function runs 2 bytes long and 25 of 29
     * words differ */
    Sint32 i;
    Float length = 0.0F;

    for (i = 0; stops[i + 1] >= 0.0F; i++) {
        length += njAbs(stops[i + 1] - stops[i]);
    }
    return length;
}
