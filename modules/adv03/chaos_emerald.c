/* @unit 0C9026C0-0C9027C0 +egflags +pool32 */
/* O C EMERALD, a Chaos Emerald that turns and bobs */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv03/chaos_emerald.h"
#include "draw/tree.h"
#include "system/task.h"
#include "system/texture.h"
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

#define EMERALDS 7
#define TURN_SPEED 0x80
#define BOB_SPEED 0x100
#define EMERALD(work) ((work)->submode)
#define VARS(work) ((struct emerald_vars *)&(work)->vars)
extern NJS_OBJECT chaos_emerald_red_object;
extern NJS_OBJECT chaos_emerald_yellow_object;
extern NJS_OBJECT chaos_emerald_green_object;
extern NJS_OBJECT chaos_emerald_sky_object;
extern NJS_OBJECT chaos_emerald_blue_object;
extern NJS_OBJECT chaos_emerald_purple_object;
extern NJS_OBJECT chaos_emerald_white_object;

/* each step but the first turns the emerald TURN_SPEED about y and advances
 * its bob's phase BOB_SPEED */

enum emerald_mode { EMERALD_INIT, EMERALD_RUN };

/* the emerald's index in chaos_emeralds */

struct emerald_vars {
    Uint8 unk_00[4];
    Sint16 phase; /* the bob's phase, whose sine is bob */
    Uint8 unk_06[2];
    Float bob; /* the emerald's height above pos.y, from -1 to 1 */
};
extern NJS_OBJECT *chaos_emeralds[7];

void past_chaos_emerald_draw(struct task *task);

void past_chaos_emerald_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case EMERALD_INIT:
        EMERALD(work) = work->ang.x;
        if (EMERALD(work) < 0 || EMERALD(work) >= EMERALDS) {
            EMERALD(work) = 0;
        }
        task->draw = past_chaos_emerald_draw;
        work->mode = EMERALD_RUN;
        break;
    case EMERALD_RUN:
        work->ang.y += TURN_SPEED;
        VARS(work)->phase += BOB_SPEED;
        VARS(work)->bob = njSin(VARS(work)->phase);
        break;
    }
    past_chaos_emerald_draw(task);
}

void past_chaos_emerald_draw(struct task *task)
{
    struct task_work *work = task->work;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y + VARS(work)->bob, work->pos.z);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(chaos_emeralds[EMERALD(work)]);
    late_DrawObjectClipEx(1);
}
