/* @unit 0C90F840-0C90FF40 +egflags +pool32 */
/* bursts of short pale streaks that fly out, slow and fall */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "stg08/streaks.h"
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
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
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

#define STREAK_LIFE 70

/* each step sets a streak's head STREAK_LENGTH ahead of its tail, along its
 * velocity. at a speed of STREAK_SLOW or less, the head lies the speed
 * squared ahead instead */
#define STREAK_LENGTH 0.15F
#define STREAK_SLOW 0.01F

/* the bytes a burst's arrays allot each streak. a streak uses 24 of
 * POINTS_ROOM, 12 of SPEEDS_ROOM and 8 of COLORS_ROOM */
#define POINTS_ROOM 32
#define SPEEDS_ROOM 16
#define COLORS_ROOM 16

/* a burst, in the list streak_bursts heads. the burst and its three arrays
 * are heap blocks, which streak_burst_free gives back */
struct streak_burst {
    NJS_POINT3 *points; /* each streak's tail, then its head */
    NJS_COLOR *colors; /* a color for each point */
    NJS_VECTOR *speeds; /* each streak's velocity, in units a step */
    int count; /* how many streaks */
    /* the steps left. the step that finds it 0 frees the burst */
    int life;
    struct streak_burst *prev;
    struct streak_burst *next;
};
extern Float streak_gravity;
extern Float streak_drag;
extern struct task *streaks_task;
extern struct streak_burst *streak_bursts;

void streaks_destroy(struct task *task);
void streaks_run(struct task *task);

void streaks_step(struct task *task)
{
    task->step = streaks_run;
    task->destructor = streaks_destroy;
}

void streak_burst_free(struct streak_burst *burst)
{
    if (burst->prev == NULL) {
        streak_bursts = burst->next;
    } else {
        burst->prev->next = burst->next;
    }
    if (burst->next != NULL) {
        burst->next->prev = burst->prev;
    }
    Free(burst->colors);
    Free(burst->points);
    Free(burst->speeds);
    Free(burst);
}

void streaks_destroy(struct task *task)
{
    struct streak_burst *burst = streak_bursts;
    struct streak_burst *next;

    while (burst != NULL) {
        next = burst->next;
        streak_burst_free(burst);
        burst = next;
    }
    if (streaks_task == task) {
        streaks_task = NULL;
    }
}

/* draw each burst, then move its streaks a step. the task kills itself on a
 * step that finds no burst */
void streaks_run(struct task *task)
{
    struct streak_burst *burst;
    struct streak_burst *next;
    NJS_POINT3COL lines;
    NJS_POINT3 *point;
    Float *cursor;
    char *source;
    NJS_VECTOR *speed;
    NJS_VECTOR *out_speed;
    int bursts = 0;
    int i;
    int count;
    /* NOLINTNEXTLINE(clang-diagnostic-unused-but-set-variable) */
    int unused;
    Float x;
    Float y;
    Float z;
    Float dx;
    Float dy;
    Float dz;
    Float length;
    Float end_x;
    Float end_y;
    Float end_z;

    burst = streak_bursts;
    lines.tex = NULL;
    for (; burst != NULL; burst = next) {
        count = burst->count;
        bursts++;
        next = burst->next;
        lines.p = burst->points;
        lines.col = burst->colors;
        /* @hack spelling: the points counted as count + count, which keeps
         * count in R13 (ADD R13,R2 at 0x0c9105e2); as count * 2, count takes
         * R9 and 39 of 166 words differ */
        lines.num = count + count;
        njDrawLine3D(&lines, count, 0);
        point = burst->points;
        out_speed = burst->speeds;
        i = 0;
        speed = burst->speeds;
        while (i < count) {
            /* @hack spelling: the point and its speed read through a byte
             * cursor; through the members, the function runs 20 bytes short and
             * 142 of 166 words differ */
            source = (char *)&burst->points[i * 2];
            x = *(Float *)source;
            source += sizeof(Float);
            y = *(Float *)source;
            source += sizeof(Float);
            z = *(Float *)source;
            source = (char *)speed;
            dx = *(Float *)source;
            source += sizeof(Float);
            dy = *(Float *)source;
            source += sizeof(Float);
            dz = *(Float *)source;
            dx *= streak_drag;
            dy *= streak_drag;
            dz *= streak_drag;
            dy += streak_gravity;
            /* @hack redundant: unused set from a test of y, which keeps y in
             * FR12 and x and z in the frame (FMOV.S @R4+,FR12 at
             * 0x0c910614); without it, z takes FR12 and 35 of 166 words
             * differ */
            unused = y ? burst->count : 0;
            x = x + dx;
            y = y + dy;
            z = z + dz;
            length = njSqrt((dx * dx) + (dy * dy) + (dz * dz));
            if (length > STREAK_SLOW) {
                length = STREAK_LENGTH / length;
            }
            /* @hack spelling: end_x summed in two statements, which keeps i
             * in R9 and point in R10 (0x0c9105f2, 0x0c9105f4); as one sum,
             * the two trade and 7 of 166 words differ */
            end_x = x;
            end_x += dx * length;
            end_y = y + (dy * length);
            /* @hack redundant: unused set from i, which has SHC find the
             * streak's points from i on each pass (SHLL R4 at 0x0c9105fe)
             * in a 36-byte frame; without it, SHC steps a pointer instead,
             * the frame takes 40 bytes and 133 of 166 words differ */
            unused = i;
            /* @hack spelling: i stepped between end_y and end_z, which puts its
             * ADD #1,R9 among the sums, at 0x0c910676; stepped at the end of
             * the pass, 3 of 166 words differ */
            i++;
            end_z = z + (dz * length);
            /* @hack redundant: unused set from a test of end_x, which keeps
             * i in R9 and point in R10 (0x0c9105f2, 0x0c9105f4); without it,
             * the two trade and 7 of 166 words differ */
            unused = end_x ? burst->count : 0;
            /* @hack spelling: both points written through one Float walk across
             * point[0] and point[1]; as stores to their members, 33 of 166
             * words differ */
            cursor = &point->x;
            *cursor++ = x;
            *cursor++ = y;
            *cursor++ = z;
            *cursor++ = end_x;
            *cursor++ = end_y;
            *cursor = end_z;
            /* @hack spelling: out_speed written through a Float walk; as stores
             * to its members, 70 of 166 words differ */
            cursor = &out_speed->x;
            *cursor++ = dx;
            *cursor++ = dy;
            *cursor = dz;
            out_speed++;
            point = point + 2;
            speed = speed + 1;
        }
        if (burst->life-- == 0) {
            streak_burst_free(burst);
        }
    }
    if (bursts == 0) {
        FreeTask(task);
    }
}

Bool streaks_burst(NJS_POINT3 *pos, NJS_VECTOR *speed, int count, Float spread)
{
    struct streak_burst *burst;
    NJS_VECTOR velocity;
    int i;
    int first;
    int second;

    if (streaks_task == NULL) {
        streaks_task = CreateElementalTask(0, 3, streaks_step);
        if (streaks_task == NULL) {
            return FALSE;
        }
    }
    burst = MAlloc(sizeof(struct streak_burst));
    if (burst != NULL) {
        burst->points = MAlloc(count * POINTS_ROOM);
        burst->speeds = MAlloc(count * SPEEDS_ROOM);
        burst->colors = MAlloc(count * COLORS_ROOM);
        burst->count = count;
        burst->life = STREAK_LIFE;
        for (i = 0; i < count; i++) {
            /* @hack spelling: first, the tail's index, written i + i, which
             * keeps the 24-byte frame (ADD #-24,R15 at 0x0c910758); as i * 2,
             * the frame takes 36 bytes, the function runs 14 bytes long and
             * 198 of 260 words differ */
            first = i + i;
            second = first + 1;
            velocity.x =
                speed->x + (spread * ((rand() * RAND_SCALE) - 0.5F) * 2.0F);
            velocity.y = speed->y + (spread * rand() * RAND_SCALE);
            velocity.z =
                speed->z + (spread * ((rand() * RAND_SCALE) - 0.5F) * 2.0F);
            burst->points[first].x = pos->x;
            burst->points[first].y = pos->y;
            burst->points[first].z = pos->z;
            burst->points[second].x = pos->x + velocity.x;
            burst->points[second].y = pos->y + velocity.y;
            burst->points[second].z = pos->z + velocity.z;
            burst->speeds[i] = velocity;
            burst->colors[first].argb.a = 255;
            burst->colors[first].argb.r = 239;
            burst->colors[first].argb.g = 223;
            burst->colors[first].argb.b = 223;
            burst->colors[second].argb.a = 255;
            burst->colors[second].argb.r = 223;
            burst->colors[second].argb.g = 223;
            burst->colors[second].argb.b = 223;
        }
        if (streak_bursts == NULL) {
            streak_bursts = burst;
            burst->prev = NULL;
            burst->next = NULL;
        } else {
            burst->prev = NULL;
            burst->next = streak_bursts;
            streak_bursts->prev = burst;
            streak_bursts = burst;
        }
        return TRUE;
    }
    return FALSE;
}

Bool streaks_ring(NJS_POINT3 *center, NJS_VECTOR *speed, Float spread,
                  int count, Float radius)
{
    struct streak_burst *burst;
    NJS_VECTOR velocity;
    NJS_POINT3 pos;
    Angle ang;
    int i;
    int first;
    int second;

    if (streaks_task == NULL) {
        streaks_task = CreateElementalTask(0, 3, streaks_step);
        if (streaks_task == NULL) {
            return FALSE;
        }
    }
    burst = MAlloc(sizeof(struct streak_burst));
    if (burst != NULL) {
        burst->points = MAlloc(count * POINTS_ROOM);
        burst->speeds = MAlloc(count * SPEEDS_ROOM);
        burst->colors = MAlloc(count * COLORS_ROOM);
        burst->count = count;
        burst->life = STREAK_LIFE;
        for (i = 0; i < count; i++) {
            ang = (Angle)(rand() * (720.0F * ANGLE_PER_DEGREE * RAND_SCALE));
            pos.x = (radius * njCos(ang)) + center->x;
            pos.y = center->y;
            pos.z = (radius * njSin(ang)) + center->z;
            /* @hack spelling: first, the tail's index, written i + i, which
             * keeps the 48-byte frame (ADD #-48,R15 at 0x0c9109d8); as i * 2,
             * the frame takes 56 bytes, the function runs 6 bytes long and
             * 229 of 303 words differ */
            first = i + i;
            second = first + 1;
            velocity.x =
                speed->x + (spread * ((rand() * RAND_SCALE) - 0.5F) * 2.0F);
            velocity.y = speed->y + (spread * rand() * RAND_SCALE);
            velocity.z =
                speed->z + (spread * ((rand() * RAND_SCALE) - 0.5F) * 2.0F);
            burst->points[first].x = pos.x;
            burst->points[first].y = pos.y;
            burst->points[first].z = pos.z;
            burst->points[second].x = pos.x + velocity.x;
            burst->points[second].y = pos.y + velocity.y;
            burst->points[second].z = pos.z + velocity.z;
            burst->speeds[i] = velocity;
            burst->colors[first].argb.a = 255;
            burst->colors[first].argb.r = 239;
            burst->colors[first].argb.g = 223;
            burst->colors[first].argb.b = 223;
            burst->colors[second].argb.a = 255;
            burst->colors[second].argb.r = 223;
            burst->colors[second].argb.g = 223;
            burst->colors[second].argb.b = 223;
        }
        if (streak_bursts == NULL) {
            streak_bursts = burst;
            burst->prev = NULL;
            burst->next = NULL;
        } else {
            burst->prev = NULL;
            burst->next = streak_bursts;
            streak_bursts->prev = burst;
            streak_bursts = burst;
        }
        return TRUE;
    }
    return FALSE;
}
