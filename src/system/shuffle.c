/* @unit 8C0A0F40-8C0A1000 +jpflags +pool32 */
/* shuffles: an array's records in a random order */
#include <sg_xpt.h>
#include <stdlib.h>

#include "system/shuffle.h"
#include "system/util.h"
void syMalloc_default_free(void *ptr);
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c6214fa(NJS_MODEL *volatile model);
void FUN_8c610c7e(Float r, Float g, Float b);
void FUN_8c605220(void);
void FUN_8c60ed4a(Float dnear, Float dfar);
void FUN_8c640468(NJS_SCREEN *s);
void njUserClipping_jp(Int mode, NJS_POINT2 *p);
Bool late_DrawObjectClipEx(Uint32 n);
Float CalcDistance(NJS_POINT3 *p1, NJS_POINT3 *p2);
Sint32 FUN_8c6214da(NJS_MODEL *model);
void FUN_8c62153a(NJS_OBJECT *obj);
void njGetkmPointer_jp(void);
void njSetkmPointer_jp(void);
void njSetEORflag_jp();
void FUN_8c606948(Uint32 mode);
void *njStartVertexNonTexOpaque_jp(void);
void *FUN_8c605e7c(void);
void *njStartVertexTexOpaque_jp(void);
void *FUN_8c605fba(void);
void *FUN_8c6061ec(Uint32 *color);
void *njStartVertexNonTexTransIntens_jp(Uint32 *color);
void *njStartVertexTexOpaqueIntens_jp(Uint32 *color);
void *kmRenderTexture(Uint32 *color);
void njEndVertex_jp(Uint32 *vertex);
Sint32 njSetkmTextureNum_jp(Uint32 n);
void njSimpleDrawModel(NJS_MODEL *model);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void late_DrawSprite2D(NJS_SPRITE *sp, Int n, Float pri, Uint32 attr);
void CHAOS_SetChaosNo(Uint32 c);
void thunk_FUN_8c652d78(Uint32 density);
void ReleaseModule(NJS_FOG_TABLE fog, Float n, Float f);
void FUN_8c63fd44(Uint32 c);
void njSetVSyncFunction_jp(void (*func)(void));
void njWaitVSync_jp(void);
void FUN_8c608d14(NJS_TEXMEMLIST *addr, Uint32 n);
Uint32 njCalcTexture_jp(Uint32 flag);
Sint32 njSetTexture_jp(NJS_TEXLIST *texlist);
Sint32 njSetTextureNum_jp(Uint32 n);
Sint32 njReleaseTexture_jp(NJS_TEXLIST *texlist);
Sint32 FUN_8c64ddf8(Uint32 n);
void FUN_8c6071a4(NJS_TEXLIST *texlist, NJS_TEXNAME *texname, char *filename,
                  Sint32 size);
Sint32 njLoadTexturePvmFile_jp(const char *filename, NJS_TEXLIST *texlist);
Sint32 njLoadTexturePvmMemory_jp(Uint8 *addr, NJS_TEXLIST *texlist);
Sint32 FUN_8c64e6e2(NJS_TEXMEMLIST *list, Uint32 n, Uint32 globalIndex);
Sint32 FUN_8c64f146(Uint32 type);
void FUN_8c608d64(void);
void FUN_8c64e4ce(Sint32 offset, Sint32 type);
Sint32 FUN_8c64ed3c(NJS_TEXNAME *texname, NJS_TEXINFO *info);
void njSetBackColor_jp(Uint32 col1, Uint32 col2, Uint32 col3);
void njSetBorderColor_jp(Uint32 color);
void njFrameBufferBmp_jp(char *bmp, char *buffer);
void njTextureFilterMode_jp(Int mode);
void njTextureClampMode_jp(Int mode);
void njTextureFlipMode_jp(Int mode);
void njColorBlendingMode_jp(Int target, Int mode);
void FUN_8c605514(Int mode);
void thunk_FUN_8c652c7a(Float size);
void njMemCopy_jp(void *dst, const void *src, Sint32 num);
void njMemCopy4_jp(void *dst, const void *src, Sint32 num);
extern NJS_MATRIX nj_unit_matrix_;
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
void SaveControl3D(void);
void LoadControl3D(void);

void memory_swap(void *one, void *other, int size)
{
    int i = 0;
    Uint8 *left = one;
    Uint8 *right = other;
    Uint8 byte;

    while (i < size) {
        byte = *left;
        *left = *right;
        *right = byte;
        left++;
        right++;
        i++;
    }
}

void array_shuffle(void *array, int count, int size)
{
    Uint8 *base = array;
    Uint8 *last = base + (count * size);
    int left = count;
    int pick;

    while (left > 1) {
        pick = (int)((Float)rand() * (Float)left * RAND_SCALE);
        left--;
        last -= size;
        if (pick != left) {
            memory_swap(base + (pick * size), last, size);
        }
    }
}
