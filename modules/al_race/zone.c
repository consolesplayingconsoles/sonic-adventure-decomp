/* @unit 0CB97F60-0CB98020 +r04 +egflags +pool32 */
/* ZONE, a sphere a racing Chao can touch, drawn only in edit mode. the
 * collision checks ignore its shape for players and attacks, objects, pickups
 * and rings */
#include <ninja.h>

#include "al_race/zone.h"
#include "collision/collision.h"
#include "collision/draw.h"
#include "debug/editor.h"
#include "object/simple.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/task_desc.h"
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
void FUN_0cb97f60(struct task *task);
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void MirenObjDrawCharColliObjectNoScale(NJS_OBJECT *object,
                                        struct task_work *work,
                                        NJS_TEXLIST *texlist);
void MirenObjEntryMobileLandObject(struct task *task, NJS_OBJECT *object,
                                   Sint32 flags, Float scale);
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);

/* a zone's radius is its scale's x. zone_get_size tells a small zone from a
 * large one by its scale's z */
#define ZONE_RADIUS(work) ((work)->scl.x)

void zone_start(struct task *task, void *arg);
void zone_step(struct task *task);
void zone_draw(struct task *task);
extern struct collision_shape zone_shapes[1];
extern const struct task_desc zone_desc;
extern const struct collision_list zone_list;
extern const struct collision_kind zone_collision;
extern struct collision_shape zone_shapes[1];

void FUN_0cb97f60(struct task *task)
{
    MirenInitTask(task, &zone_desc, NULL);
}

void zone_destroy(struct task *task)
{
}

void zone_start(struct task *task, void *arg)
{
    struct task_work *work = task->work;

    zone_shapes[0].radius = ZONE_RADIUS(work);
    object_collision_init(task, (struct collision_list *)&zone_list,
                          (struct collision_kind *)&zone_collision);
}

void zone_step(struct task *task)
{
    struct task_work *work = task->work;

    if (OnEdit(task)) {
        work->collision->shapes[0].radius = ZONE_RADIUS(work);
    } else {
        EntryColliList(work);
    }
    zone_draw(task);
}

void zone_draw(struct task *task)
{
    if (edit_mode && loop_count == 0) {
        collision_draw(task->work->collision);
    }
}
