/* @unit 0CB89C00-0CB89D60 +r04 +egflags +onepool +asmfunc=zone_get_size:0cb89d60 */
/* Chao race item messages and zones */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_race/ball.h"
#include "al_race/bugle.h"
#include "al_race/coconut_palm.h"
#include "al_race/item.h"
#include "al_race/palm_coconut.h"
#include "al_race/racer.h"
#include "al_race/scoop.h"
#include "al_race/watering_can.h"
#include "al_race/zone.h"
#include "collision/collision.h"
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
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void MirenObjDrawCharColliObjectNoScale(NJS_OBJECT *object,
                                        struct task_work *work,
                                        NJS_TEXLIST *texlist);
void MirenObjEntryMobileLandObject(struct task *task, NJS_OBJECT *object,
                                   Sint32 flags, Float scale);
Float FUN_0cb89c9a(struct task *task, struct task *other);
extern int (*const item_tells[6])(struct task *task, struct task *other,
                                  Sint8 command);

/* a zone with a scale z up to this is small, and one above it large */
#define ZONE_SMALL_SCALE 10.0F

struct task *item_hit_chao(struct collision_work *collision)
{
    struct task *task = NULL;
    struct collision_work *hit;

    if (collision->flags & COLLISION_HIT) {
        hit = collision->hit;
        if (hit != NULL && hit->kind == COLLISION_ENEMY) {
            task = hit->owner;
        }
    }
    return task;
}

int item_tell_chao(struct task *chao_task, struct task *other, Sint8 command,
                   Sint8 kind)
{
    struct racer *racer;
    int heard;

    if (chao_task == NULL || chao_task->work == NULL || other == NULL) {
        heard = 0;
    } else {
        racer = RACER_VARS(chao_task->work)->racer;
        if (racer == NULL || !racer_has_chao(racer)) {
            heard = 0;
        } else {
            heard = racer_tell(racer, command, other, kind);
        }
    }
    return heard;
}

int item_tell(struct task *task, struct task *other, Sint8 command, Sint8 kind)
{
    int (*tell)(struct task *task, struct task *other, Sint8 command);
    int heard;

    if (task == NULL || other == NULL) {
        heard = 0;
    } else {
        tell = item_tells[kind];
        if (tell == NULL) {
            heard = 0;
        } else {
            heard = tell(task, other, command);
        }
    }
    return heard;
}

Float FUN_0cb89c9a(struct task *task, struct task *other)
{
    Float distance = -1.0F;

    if (task != NULL && other != NULL) {
        NJS_POINT3 *from = &task->work->pos;
        NJS_POINT3 *to = &other->work->pos;
        Float dx = from->x - to->x;
        Float dy = from->y - to->y;
        Float dz = from->z - to->z;

        distance = (dx * dx) + (dy * dy) + (dz * dz);
    }
    return distance;
}

struct task_work *zone_get_work(struct collision_work *collision)
{
    struct task_work *work = NULL;
    struct task *owner;

    if (collision != NULL) {
        owner = collision->owner;
        if (owner != NULL && owner->destructor == zone_destroy) {
            work = owner->work;
        }
    }
    return work;
}
#ifdef NON_MATCHING

enum zone_size zone_get_size(struct collision_work *collision)
{
    struct task_work *work = zone_get_work(collision);
    enum zone_size size;

    if (work == NULL) {
        size = ZONE_NONE;
    } else if (work->scl.z <= ZONE_SMALL_SCALE) {
        size = ZONE_SMALL;
    } else {
        size = ZONE_LARGE;
    }
    return size;
}
#else
enum zone_size zone_get_size(struct collision_work *collision)
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
    return asm_stub[0];
}
#endif
