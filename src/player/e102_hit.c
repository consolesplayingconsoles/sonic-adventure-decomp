/* @unit 8C0D68A0-8C0D6A80 +jpflags +pool32 */
/* E-102's hit: a flash, and a burst of sparks, on E102HIT's textures */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "effect/sprite.h"
#include "effect/sprite_pool.h"
#include "player/e102_hit.h"
#include "system/task.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void FUN_8c0d69c4(void);
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
extern const NJS_TEXNAME e102hit_textures[17];
extern const struct sprite_frame hit_flash_frames[17];
extern const struct sprite_frame hit_spark_frames[5];
extern NJS_TEXLIST e102hit_texlist;
extern struct task *hit_sparks;

#define POOL_SPARKS 40 /* the sparks the pool has room for */
#define BURST_SPARKS 20 /* the sparks a burst adds */

/* E102HIT's textures, with empty names: only its PVM names them */

void hit_sparks_create(void)
{
    struct sprite_motion motion;

    if (hit_sparks == NULL) {
        sprite_bind(&e102hit_texlist, hit_spark_frames, 0);
        motion.drag = 0.03F;
        motion.gravity = 0.0F;
        hit_sparks =
            sprite_pool_create(POOL_SPARKS, &motion, hit_spark_frames, NULL);
    }
}

/* each spark flies off at -2 to 2 on each axis, from a random age of 0 to
 * 15 */
void hit_burst(NJS_POINT3 *pos, Float depth)
{
    NJS_VECTOR speed;
    int i;

    if (hit_sparks != NULL) {
        for (i = 0; i < BURST_SPARKS; i++) {
            speed.x = (rand() * RAND_SCALE * 4.0F) - 2.0F;
            speed.y = (rand() * RAND_SCALE * 4.0F) - 2.0F;
            speed.z = (rand() * RAND_SCALE * 4.0F) - 2.0F;
            sprite_pool_add(hit_sparks, pos, &speed,
                            rand() * RAND_SCALE * 15.0F, depth);
        }
    }
}

void e102_hit_init(void)
{
    sprite_bind(&e102hit_texlist, hit_flash_frames, 0);
    hit_sparks_create();
}

void FUN_8c0d69c4(void)
{
    if (hit_sparks != NULL) {
        FreeTask(hit_sparks);
        hit_sparks = NULL;
    }
}

void e102_hit_create(NJS_POINT3 *pos, Float depth)
{
    struct sprite_desc desc;

    desc.step = NULL;
    desc.speed.x = desc.speed.y = desc.speed.z = 0.0F;
    desc.scale = 1.0F;
    desc.depth = depth;
    desc.drag = 0.0F;
    desc.gravity = 0.0F;
    desc.frames = hit_flash_frames;
    desc.rate = 1.0F;
    sprite_create(pos, &desc, SPRITE_MOVES);
    hit_burst(pos, depth);
}
