/* @unit 8C0BFD40-8C0C0580 +egflags +r04 +pool32 */
/* Tails' trails: the quads his tails leave as he attacks with them */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "object/placement.h"
#include "player/tails_trail.h"
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
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
extern NJS_POINT3 tails_trail_points[4];
extern NJS_COLOR tails_trail_colors[4];
extern NJS_POINT3 tails_inner_points[4];
extern NJS_COLOR tails_inner_colors[4];
extern NJS_BGRA tails_trail_shades[4];
extern NJS_POINT3COL tails_trail_quad;
extern NJS_BGRA tails_inner_shades[4];
extern NJS_POINT3COL tails_inner_quad;
extern struct collision_shape tails_trail_shape;

#define TEXT_1_LENGTH 8
#define TEXT_2_LENGTH 8
#define TEXT_3_LENGTH 8
#define TEXT_4_LENGTH 8
#define TEXT_5_LENGTH 8

/* each trail's life, in steps: the outer one's, then the inner one's */
#define TRAIL_STEPS (0.6F * 30.0F)
#define INNER_STEPS (0.4F * 30.0F)
/* the age in steps from which an outer trail strikes, and the age at which
 * it stops */
#define STRIKE_START (0.3F * 30.0F)
#define STRIKE_END ((0.3F * 30.0F) + (0.1F * 30.0F))

/* @hack spelling: the middle of his body in the task's extra, by index, which
 * adds each part's offset to the extra's address (ADD #4,R4 at 0x8c0c7d70);
 * by member through TAILS_TRAIL_CENTER, SHC loads each at an offset in R0,
 * and 243 of the 950 words of the two functions that use it differ */
#define CENTER(task, i) (((Float *)(task)->extra)[i])

/* set out to the shades from and to blended by t, then faded by u. the
 * trails' steps pass u as 1 - t */
#define FADE_COLOR(out, from, to, t, u)                                        \
    {                                                                          \
        (out).argb.r = (u) * (((u) * (from).r) + ((t) * (to).r));              \
        (out).argb.g = (u) * (((u) * (from).g) + ((t) * (to).g));              \
        (out).argb.b = (u) * (((u) * (from).b) + ((t) * (to).b));              \
    }

/* the corners and colors of the quad each outer trail draws, and of the
 * one each inner trail draws. a step fills them just before it draws them.
 * corner 0 is where the tail's end was, and corner 1 where it is. corner 2
 * is the middle of his body now, and corner 3 where it was */
/* clang-format on */

/* step an outer trail: draw its quad, fading, until it is TRAIL_STEPS
 * steps old. on its first step, the quad's body edge closes in on its tail
 * edge. on each later one, the tail edge moves out from the body edge. from
 * STRIKE_START steps old until STRIKE_END, it strikes past the tail's end */
void EffectMilesZanzoPolygon(struct task *task)
{
    struct tails_trail_work *work = TAILS_TRAIL_WORK(task);
    NJS_POINT3 tip;
    Float t0;
    Float t1;
    Float u0;
    Float u1;

    if (work->timer == 0) {
        /* @hack spelling: the moves toward the tail's end written out, which
         * load each part once and copy it (FMOV FR5,FR2 at 0x8c0c7d64); as
         * +=, SHC loads it twice, the function runs 32 bytes long and 448 of
         * 510 words differ */
        CENTER(task, 0) =
            CENTER(task, 0) + ((work->to.x - CENTER(task, 0)) * 0.4F);
        CENTER(task, 1) =
            CENTER(task, 1) + ((work->to.y - CENTER(task, 1)) * 0.4F);
        CENTER(task, 2) =
            CENTER(task, 2) + ((work->to.z - CENTER(task, 2)) * 0.4F);
        work->center.x =
            work->center.x + ((work->from.x - work->center.x) * 0.4F);
        work->center.y =
            work->center.y + ((work->from.y - work->center.y) * 0.4F);
        work->center.z =
            work->center.z + ((work->from.z - work->center.z) * 0.4F);
        CCL_Init(task, &tails_trail_shape, COLLISION_OBJECT, 1, 1);
    } else {
        work->to.x += (work->to.x - CENTER(task, 0)) * 0.01F;
        work->to.y += (work->to.y - CENTER(task, 1)) * 0.01F;
        work->to.z += (work->to.z - CENTER(task, 2)) * 0.01F;
        work->from.x += (work->from.x - work->center.x) * 0.01F;
        work->from.y += (work->from.y - work->center.y) * 0.01F;
        work->from.z += (work->from.z - work->center.z) * 0.01F;
        if (work->timer >= STRIKE_START && work->timer < STRIKE_END) {
            tip.x = ((work->to.x - CENTER(task, 0)) * 0.6F) + work->to.x;
            tip.y = ((work->to.y - CENTER(task, 1)) * 0.6F) + work->to.y;
            tip.z = ((work->to.z - CENTER(task, 2)) * 0.6F) + work->to.z;
            work->collision->shapes->center = tip;
            EntryColliList((struct task_work *)work);
        }
    }
    if (++work->timer >= TRAIL_STEPS) {
        FreeTask(task);
        return;
    }
    t0 = work->timer * (1.0F / TRAIL_STEPS);
    t1 = (work->timer + 1) * (1.0F / TRAIL_STEPS);
    u0 = 1.0F - t0;
    u1 = 1.0F - t1;
    FADE_COLOR(tails_trail_colors[0], tails_trail_shades[0],
               tails_trail_shades[1], t1, u1);
    FADE_COLOR(tails_trail_colors[1], tails_trail_shades[0],
               tails_trail_shades[1], t0, u0);
    FADE_COLOR(tails_trail_colors[3], tails_trail_shades[2],
               tails_trail_shades[3], t1, u1);
    FADE_COLOR(tails_trail_colors[2], tails_trail_shades[2],
               tails_trail_shades[3], t0, u0);
    tails_trail_points[0] = work->from;
    tails_trail_points[1] = work->to;
    tails_trail_points[2].x = CENTER(task, 0);
    tails_trail_points[2].y = CENTER(task, 1);
    tails_trail_points[2].z = CENTER(task, 2);
    /* @hack spelling: the middle of his body before copied float by float, for
     * the image's FMOV.S copies (0x8c0c8134 on); as a struct, SHC copies it
     * in MOV.L words, the function runs 12 bytes short and 88 of 510 words
     * differ */
    tails_trail_points[3].x = work->center.x;
    tails_trail_points[3].y = work->center.y;
    tails_trail_points[3].z = work->center.z;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njDrawPolygon3D(&tails_trail_quad, 4, NJD_FILL | NJD_TRANSPARENT);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_BOTHSRCALPHA);
    CheckRangeOut(task);
}

/* step an inner trail as an outer one, until it is INNER_STEPS steps old.
 * its edges close in further and move apart faster, and it strikes
 * nothing */
void EffectMilesZanzo2Polygon(struct task *task)
{
    struct tails_trail_work *work = TAILS_TRAIL_WORK(task);
    Float t0;
    Float t1;
    Float u0;
    Float u1;

    if (work->timer == 0) {
        /* @hack spelling: the moves toward the tail's end written out, as in
         * tails_trail_step (FMOV FR5,FR2 at 0x8c0c81a0); as +=, the function
         * runs 32 bytes long and 393 of 440 words differ */
        CENTER(task, 0) =
            CENTER(task, 0) + ((work->to.x - CENTER(task, 0)) * 0.7F);
        CENTER(task, 1) =
            CENTER(task, 1) + ((work->to.y - CENTER(task, 1)) * 0.7F);
        CENTER(task, 2) =
            CENTER(task, 2) + ((work->to.z - CENTER(task, 2)) * 0.7F);
        work->center.x =
            work->center.x + ((work->from.x - work->center.x) * 0.7F);
        work->center.y =
            work->center.y + ((work->from.y - work->center.y) * 0.7F);
        work->center.z =
            work->center.z + ((work->from.z - work->center.z) * 0.7F);
    } else {
        work->to.x += (work->to.x - CENTER(task, 0)) * 0.2F;
        work->to.y += (work->to.y - CENTER(task, 1)) * 0.2F;
        work->to.z += (work->to.z - CENTER(task, 2)) * 0.2F;
        work->from.x += (work->from.x - work->center.x) * 0.2F;
        work->from.y += (work->from.y - work->center.y) * 0.2F;
        work->from.z += (work->from.z - work->center.z) * 0.2F;
    }
    if (++work->timer >= INNER_STEPS) {
        FreeTask(task);
        return;
    }
    t0 = work->timer * (1.0F / INNER_STEPS);
    t1 = (work->timer + 1) * (1.0F / INNER_STEPS);
    u0 = 1.0F - t0;
    u1 = 1.0F - t1;
    FADE_COLOR(tails_inner_colors[0], tails_inner_shades[0],
               tails_inner_shades[1], t1, u1);
    FADE_COLOR(tails_inner_colors[1], tails_inner_shades[0],
               tails_inner_shades[1], t0, u0);
    FADE_COLOR(tails_inner_colors[3], tails_inner_shades[2],
               tails_inner_shades[3], t1, u1);
    FADE_COLOR(tails_inner_colors[2], tails_inner_shades[2],
               tails_inner_shades[3], t0, u0);
    tails_inner_points[0] = work->from;
    tails_inner_points[1] = work->to;
    tails_inner_points[2].x = CENTER(task, 0);
    tails_inner_points[2].y = CENTER(task, 1);
    tails_inner_points[2].z = CENTER(task, 2);
    /* @hack spelling: the middle of his body before copied float by float, as
     * in tails_trail_step (0x8c0c84ea on); as a struct, 137 of 440 words
     * differ */
    tails_inner_points[3].x = work->center.x;
    tails_inner_points[3].y = work->center.y;
    tails_inner_points[3].z = work->center.z;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    njDrawPolygon3D(&tails_inner_quad, 4, NJD_FILL | NJD_TRANSPARENT);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_BOTHSRCALPHA);
    CheckRangeOut(task);
}
