/* @unit 0CB82420-0CB82500 +r04 +egflags +asmfunc=event_highway_create:0cb8248c,FUN_0cb8244e:0cb82474 */
/* the stretch of highway where the last story's last events play. its task
 * draws its one model each step */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#define TEXT_6 ""
#define TEXT_7 ""
#define TEXT_8 ""
#define TEXT_9 ""
#define TEXT_10 ""
#define TEXT_11 ""
#define TEXT_12 ""
#include <ninja.h>

#include "draw/tree.h"
#include "shared/highway.h"
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
void FUN_0cb8248c(void);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

#define TEXT_1_LENGTH 11
#define TEXT_2_LENGTH 11
#define TEXT_3_LENGTH 11
#define TEXT_4_LENGTH 12
#define TEXT_5_LENGTH 12
#define TEXT_6_LENGTH 12
#define TEXT_7_LENGTH 12
#define TEXT_8_LENGTH 12
#define TEXT_9_LENGTH 12
#define TEXT_10_LENGTH 10
#define TEXT_11_LENGTH 10
#define TEXT_12_LENGTH 11

/* the first of the highway's seven parts, which EV00FD, EV00FE and EV00FF
 * each define. each part's sibling is the next */
extern NJS_OBJECT event_highway_parts;
extern NJS_OBJECT event_highway_object;
extern NJS_TEXNAME event_highway_texnames[12];
extern NJS_TEXLIST event_highway_texlist;
extern struct task *event_highway;

void event_highway_destroy(struct task *task)
{
}

void event_highway_draw(struct task *task)
{
    njSetTexture_jp(&event_highway_texlist);
    late_DrawObject(&event_highway_object);
}

void event_highway_step(struct task *task)
{
    event_highway_draw(task);
}

struct task *event_highway_spawn(void)
{
    struct task *task;

    task = CreateElementalTask(0, 5, NULL);
    if (task != NULL) {
        task->step = event_highway_step;
        task->draw = event_highway_draw;
        task->destructor = event_highway_destroy;
    }
    /* @hack implicit: no return, so R0 still holds task_create's result
     * (MOV R0,R4 at 0x0cb860be in EV00FE), which event_highway_create stores
     * (0x0cb860e6); returned explicitly, the function runs 2 bytes long and 10
     * of 18 words differ */
#ifdef GCC
    /* keeps the value the tag names: task_create's result */
    return task;
#endif
} /* NOLINT(clang-diagnostic-return-type) */

void event_highway_create(void)
{
    if (event_highway == NULL) {
        event_highway = event_highway_spawn();
    }
}

void FUN_0cb8248c(void)
{
    if (event_highway != NULL) {
        FreeTask(event_highway);
        event_highway = NULL;
    }
}
