/* @unit 0C9027C0-0C902960 +jpflags +pool32 */
/* O KNULAMP, a lamp under a flickering red glow, EFF_REGULAR's panlight. the
 * step keeps the glow's red, green and blue in work->scl's x, y and z */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "adv03/knuckles_lamp.h"
#include "draw/sprite.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
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
void *syMalloc_default_malloc(size_t size);
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

#define GLOW_HEIGHT 12.5F
#define GLOW_RED 0.8F
#define GLOW_GREEN 0.1F
#define GLOW_BLUE 0.1F
#define FLICKER 0.2F
extern NJS_OBJECT knuckles_lamp_object;

/* the glow's height above the lamp's position */

/* each step, the glow's red, green and blue are these plus one random
 * flicker, from 0 up to FLICKER */

enum knuckles_lamp_mode { LAMP_INIT, LAMP_LIT };
extern NJS_TEXLIST glow_texlist;
extern NJS_TEXANIM glow_frames[1];
extern NJS_ARGB glow_color;
extern NJS_SPRITE glow_sprite;
extern NJS_ARGB glow_no_color;

void LampDisplayer(struct task *task);

void ObjectPastKnucklesLamp(struct task *task)
{
    struct task_work *work = task->work;
    Float flicker;

    if (!CheckRangeOut(task)) {
        switch (work->mode) {
        case LAMP_INIT:
            task->draw = LampDisplayer;
            work->mode = LAMP_LIT;
            break;
        case LAMP_LIT:
            flicker = rand() * (FLICKER * RAND_SCALE);
            work->scl.x = flicker + GLOW_RED;
            work->scl.y = flicker + GLOW_GREEN;
            work->scl.z = flicker + GLOW_BLUE;
            break;
        }
        LampDisplayer(task);
    }
}

void LampDisplayer(struct task *task)
{
    struct task_work *work = task->work;
    NJS_SPRITE *sprite = &glow_sprite;

    sprite->p.x = work->pos.x;
    sprite->p.y = work->pos.y + GLOW_HEIGHT;
    sprite->p.z = work->pos.z;
    glow_color.r = work->scl.x;
    glow_color.g = work->scl.y;
    glow_color.b = work->scl.z;
    njFogDisable();
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njSetConstantMaterial(&glow_color);
    sprite_set_depth(-10.0F);
    sprite_draw_3d(sprite, 0,
                   NJD_SPRITE_COLOR | NJD_SPRITE_SCALE | NJD_SPRITE_ALPHA);
    njSetConstantMaterial(&glow_no_color);
    njFogEnable();
    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(&knuckles_lamp_object);
    late_DrawObjectClipEx(1);
}
