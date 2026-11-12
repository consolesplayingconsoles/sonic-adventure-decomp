/* @unit 0C90C720-0C90C860 +r04 +egflags +pool32 */
/* GOAL ZONE, PREVIOUS ZONE and NEXT ZONE, boxes that tell the race when a
 * player is in one. they draw only while the set editor is open */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "collision/draw.h"
#include "debug/editor.h"
#include "minicart/race.h"
#include "minicart/zone.h"
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
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *CartRaceSetManageTask(void);
void CartRaceDestroyManageTask(void);
Bool CartRacePrepareRace(void);
Sint8 CartRaceGetMode(void);
void FUN_0c90c720(struct task *task);
void FUN_0c90c72a(struct task *task);
void FUN_0c90c734(struct task *task);
void MirenObjDrawCharColliObjectNoScale(NJS_OBJECT *object,
                                        struct task_work *work,
                                        NJS_TEXLIST *texlist);
void MirenObjEntryMobileLandObject(struct task *task, NJS_OBJECT *object,
                                   Sint32 flags, Float scale);

void cart_zone_init(struct task *task, void *arg);
void cart_zone_step(struct task *task);
void cart_zone_draw(struct task *task);
extern const struct task_desc cart_zone_desc;
extern const Sint8 cart_zones[3];
extern struct collision_shape cart_zone_shape;
extern const struct collision_list cart_zone_shapes;
extern const struct collision_kind cart_zone_kind;

void FUN_0c90c720(struct task *task)
{
    MirenInitTask(task, &cart_zone_desc, (void *)&cart_zones[ZONE_GOAL]);
}

void FUN_0c90c72a(struct task *task)
{
    MirenInitTask(task, &cart_zone_desc, (void *)&cart_zones[ZONE_PREVIOUS]);
}

void FUN_0c90c734(struct task *task)
{
    MirenInitTask(task, &cart_zone_desc, (void *)&cart_zones[ZONE_NEXT]);
}

void cart_zone_init(struct task *task, void *arg)
{
    struct task_work *work;
    NJS_POINT3 *scl;
    struct collision_shape *shape;
    Sint8 *zone;

    work = task->work;
    scl = &work->scl;
    shape = &cart_zone_shape;
    zone = (Sint8 *)task->motion;
    shape->radius = scl->x;
    shape->size_y = scl->y;
    shape->size_z = scl->z;
    object_collision_init(task, &cart_zone_shapes, &cart_zone_kind);
    *zone = *(Sint8 *)arg;
}

/* draw the box. then report a player's touch to the race, and register the
 * box for this step's checks. while the set editor holds the zone, size the
 * box to its scale instead */
void cart_zone_step(struct task *task)
{
    struct task_work *work;
    Sint8 *zone;
    struct collision_work *collision;
    struct collision_work *hit;
    NJS_POINT3 *scl;
    struct collision_shape *shape;

    cart_zone_draw(task);
    work = task->work;
    zone = (Sint8 *)task->motion;
    if (OnEdit(task)) {
        shape = work->collision->shapes;
        scl = &work->scl;
        shape->radius = scl->x;
        shape->size_y = scl->y;
        shape->size_z = scl->z;
    } else {
        collision = work->collision;
        if (collision->flags & COLLISION_HIT) {
            hit = collision->hit;
            if (hit != NULL) {
                /* @hack spelling: the kind tested by a switch of one case,
                 * which tests it with CMP/EQ #0,R0 (0x0c90c42e); as an if, SHC
                 * tests it with TST R3,R3, cart_zone_step runs 2 bytes short
                 * and 24 of its 58 words differ */
                switch (hit->kind) {
                case COLLISION_PLAYER:
                    race_enter_zone(*zone);
                }
            }
        }
        EntryColliList(work);
    }
}

/* while the set editor is open, draw the box on a frame's first step */
void cart_zone_draw(struct task *task)
{
    if (edit_mode) {
        if (loop_count == 0) {
            collision_draw(task->work->collision);
        }
    }
}
