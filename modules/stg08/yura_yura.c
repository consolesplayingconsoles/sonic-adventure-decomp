/* @unit 0C90F680-0C90F840 +jpflags +pool32 */
/* YuraYura, the land's moving snow: it steps the texture of the snow's
 * materials through 15 images */
#include <ninja.h>
#include <sg_xpt.h>

#include "stg08/icecap02_textures.h"
#include "stg08/yura_yura.h"
#include "system/task.h"
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

/* the land's materials that show the moving snow */
#define YURA_YURA_IMAGES 15
#define YURA_YURA_DELAY 4 /* the steps each image shows for */
#define VARS(work) ((struct yura_yura_vars *)&(work)->vars)
extern NJS_MATERIAL dat_0c977dac[1];
extern NJS_MATERIAL dat_0c978228[1];
extern NJS_MATERIAL dat_0c9830c8[2];
extern NJS_MATERIAL dat_0c98f8c4[1];
extern NJS_MATERIAL dat_0c98f9c8[1];
extern NJS_MATERIAL dat_0c9a5eec[1];
extern NJS_MATERIAL dat_0c9a8720[2];
extern NJS_MATERIAL dat_0c9aa3fc[1];
extern NJS_MATERIAL dat_0c9aaabc[3];
extern NJS_MATERIAL dat_0c9ac498[1];
extern NJS_MATERIAL dat_0c9ad698[1];
extern NJS_MATERIAL dat_0c9b7230[2];
extern NJS_MATERIAL dat_0c9b94ac[1];
extern NJS_MATERIAL dat_0c9bda40[2];
extern NJS_MATERIAL dat_0c9be30c[2];
extern NJS_MATERIAL dat_0c9c57e4[1];
extern NJS_MATERIAL dat_0c9c5924[1];
extern NJS_MATERIAL dat_0c9c5a28[1];
extern NJS_MATERIAL dat_0c9c5b68[1];
extern NJS_MATERIAL dat_0c9c5c6c[1];

struct yura_yura_vars {
    Uint32 image;
};
extern Uint32 yura_yura_textures[15];

void yura_yura_run(struct task *task)
{
    if (++task->work->tick == YURA_YURA_DELAY) {
        task->work->tick = 0;
        VARS(task->work)->image =
            (VARS(task->work)->image + 1) % YURA_YURA_IMAGES;
        /* clang-format off */
        /* @hack spelling: the materials' textures set in one chain, which has SHC
         * take their addresses first, twelve of them onto the stack
         * (0x0c9103a2 to 0x0c910412), and read the texture once, at
         * 0x0c91041c; as a statement for each, SHC reads the texture again
         * for each store, the function runs 64 bytes long and 144 of 144
         * words differ */
        dat_0c98f8c4[0].attr_texId =
        dat_0c98f9c8[0].attr_texId =
        dat_0c977dac[0].attr_texId =
        dat_0c978228[0].attr_texId =
        dat_0c9830c8[0].attr_texId =
        dat_0c9830c8[1].attr_texId =
        dat_0c9c57e4[0].attr_texId =
        dat_0c9c5924[0].attr_texId =
        dat_0c9c5a28[0].attr_texId =
        dat_0c9c5b68[0].attr_texId =
        dat_0c9c5c6c[0].attr_texId =
        dat_0c9a5eec[0].attr_texId =
        dat_0c9a8720[0].attr_texId =
        dat_0c9a8720[1].attr_texId =
        dat_0c9aa3fc[0].attr_texId =
        dat_0c9aaabc[0].attr_texId =
        dat_0c9aaabc[1].attr_texId =
        dat_0c9aaabc[2].attr_texId =
        dat_0c9ac498[0].attr_texId =
        dat_0c9ad698[0].attr_texId =
        dat_0c95cb4c[0].attr_texId =
        dat_0c9b7230[0].attr_texId =
        dat_0c9b7230[1].attr_texId =
        dat_0c9b94ac[0].attr_texId =
        dat_0c9bda40[0].attr_texId =
        dat_0c9bda40[1].attr_texId =
        dat_0c9be30c[0].attr_texId =
        dat_0c9be30c[1].attr_texId =
            yura_yura_textures[VARS(task->work)->image];
        /* clang-format on */
    }
}

void yura_yura_step(struct task *task)
{
    VARS(task->work)->image = 0;
    task->work->tick = 0;
    task->step = yura_yura_run;
}
