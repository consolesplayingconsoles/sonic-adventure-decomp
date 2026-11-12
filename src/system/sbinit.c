/* @unit 8C010180-8C010320 @data 8C11112C-8C111134 +egflags +pool32 */
/* hardware, memory and SDK subsystem initialization */
#include <machine.h>
#include <ninja.h>
#include <sg_syhw.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "system/cache.h"
#include "system/sbinit.h"
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c604642(Int mode, Int frame, Int count);
void FUN_8c605220(void);
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
void FUN_8c602068(void *heap, Uint32 size);
void pdExecPeripheralServerUser(void);
void FUN_8c02e720(void);

/* the heap is main memory's last megabyte. MEMORY_END is main memory's
 * end, in the address region _BSG_END lies in */
#define HEAP_SIZE 0x100000
#define MEMORY_END ((((Uint32)_BSG_END) & 0xe0000000) | 0x0d000000)

#define PAD_BUFFER_SIZE (1024 * 24 * 2)

/* GD filesystem limits: open files, directory entries and init attempts */
#define GD_FILES 8
#define GD_ENTRIES 1920
#define GD_TRIES 8

/* advance to the next 32-byte boundary, even if already aligned.
 * callers reserve 32 extra bytes for this adjustment */
#define ALIGN_32(buffer) ((void *)(((Uint32)(buffer) & ~31) + 32))

/* the end of the last bss section, as the linker puts it */
extern Uint8 *_BSG_END;
extern Uint8 pad_recv_buffer[];
extern Uint8 pad_send_buffer[];
extern Uint8 gd_work[];
extern Uint8 gd_directory[];

void sbInitSystem(Int mode, Int frame, Int count)
{
    void *work;
    void *directory;
    Sint32 err;
    int tries;

    set_imask(IMASK_ALL);
    syHwInit();
    FUN_8c02e720();
    FUN_8c602068(
        (void *)(((((Uint32)_BSG_END) & 0xe0000000) | 0x0d000000) - 0x100000),
        0x100000);
    FUN_8c604642(mode, frame, count);
    syHwInit2();
    pdInitPeripheral(PDD_PLOGIC_ACTIVE, pad_recv_buffer, pad_send_buffer);
    syRtcInit();
    _builtin_set_imask(0);
    work = ((void *)(((Uint32)(gd_work) & ~31) + 32));
    directory = ((void *)(((Uint32)(gd_directory) & ~31) + 32));
    for (tries = 8; tries > 0; tries--) {
        err = gdFsInit(8, work, 2100, directory);
        if (err == (-23) || err == (-33)) {
            sbExitSystem();
            syBtExit();
        } else if (err == GDD_ERR_OK) {
            break;
        }
    }
    if (tries == 0) {
        sbExitSystem();
        syBtExit();
    }
    gdFsChangeDir("SONICAD");
}

void sbExitSystem(void)
{
    gdFsFinish();
    syRtcFinish();
    pdExitPeripheral();
    FUN_8c605220();
    syMallocFinish();
    syHwFinish();
    set_imask(IMASK_ALL);
}
