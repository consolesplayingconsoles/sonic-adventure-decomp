/* @unit 0CB80F20-0CB81180 +r04 +egflags +pool32 +poolafter=ev00b7_dim_create +asmfunc=FUN_0cb80f20:0cb80fb0,FUN_0cb80fb8:0cb810c4 */
/* EV00B7.PRS's dimming: a task that darkens the models' palettes and puts
 * them back */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/model.h"
#include "ev00b7/dim.h"
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern Sint32 dim_diffuse;
extern Sint32 dim_ambient;
extern struct task *dim_task;
extern NJS_LIGHT dim_light;
extern Uint32 dim_saved[2][256 * 2];

/* how many of draw_palettes the dimming darkens, from the first */
#define DIM_PALETTES 2

/* the light's diffuse and ambient intensities, each ten times the value
 * njSetLightIntensity takes */
#ifdef NON_MATCHING

void ev00b7_dim_destroy(struct task *task)
{
    int palette;
    int entry;

    njDeleteLight(&dim_light);
    for (palette = 0; palette < DIM_PALETTES; palette++) {
        for (entry = 0; entry < DRAW_PALETTE_ENTRIES; entry++) {
            draw_palettes[palette][entry * 2] = dim_saved[palette][entry * 2];
            draw_palettes[palette][(entry * 2) + 1] =
                dim_saved[palette][(entry * 2) + 1];
        }
    }
}
#else
void ev00b7_dim_destroy(struct task *task)
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
}
#endif

void ev00b7_dim_draw(struct task *task)
{
}

void ev00b7_dim_step(struct task *task)
{
}
#ifdef NON_MATCHING

void ev00b7_dim_init(struct task *task)
{
    int palette;
    int entry;
    /* @hack type: color signed, which SHC shifts with SHAR (0x0cb80fae,
     * 0x0cb80fd4), though the mask clears the bit SHAR copies; as a Uint32,
     * it shifts with SHLR and 2 of 123 words differ */
    Sint32 color;

    njCreateLight(&dim_light, NJD_SIMPLE_LIGHT | NJD_AMBIENT | NJD_DIR_LIGHT);
    njSetLightIntensity(&dim_light, 0.0F, dim_diffuse * 0.1F,
                        dim_ambient * 0.1F);
    njSetLightColor(&dim_light, 1.0F, 1.0F, 1.0F);
    njSetLightDirection(&dim_light, 0.0F, 0.0F, 1.0F);
    task->step = ev00b7_dim_step;
    task->draw = ev00b7_dim_draw;
    task->destructor = ev00b7_dim_destroy;
    for (palette = 0; palette < DIM_PALETTES; palette++) {
        for (entry = 0; entry < DRAW_PALETTE_ENTRIES; entry++) {
            /* each base color drops to half its brightness and becomes
             * opaque. each offset color becomes black, which adds
             * nothing */
            color = draw_palettes[palette][entry * 2];
            dim_saved[palette][entry * 2] = color;
            draw_palettes[palette][entry * 2] =
                ((color >> 1) & 0x007f7f7f) | 0xff000000;
            color = draw_palettes[palette][(entry * 2) + 1];
            dim_saved[palette][(entry * 2) + 1] = color;
            draw_palettes[palette][(entry * 2) + 1] = 0xff000000;
        }
    }
}
#else
void ev00b7_dim_init(struct task *task)
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
}
#endif

void ev00b7_dim_create(void)
{
    dim_task = CreateElementalTask(0, 1, ev00b7_dim_init);
}

void ev00b7_dim_kill(void)
{
    if (dim_task != NULL) {
        FreeTask(dim_task);
        dim_task = NULL;
    }
}
