/* @unit 8C087AC0-8C088060 @data 8C15936C-8C1593D4 +r04 +egflags +pool32 +poolafter=ring_group_draw_marker,ring_group_line_pos +poolbra=ObjectGroupRing:10 +onepool +asmfunc=ring_group_line_pos */
/* the ring group, "O GRING": rings on a line or round a circle, each a
 * child task. a taken ring's bit in the placement's state keeps the group
 * from making it again */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "object/ring.h"
#include "object/ring_group.h"
#include "system/task.h"
#include "system/util.h"
float njArcTan2(float y, float x);
float njFloor(float x);
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

/* a group's scl. scl.x is the last ring's number: a line's rings are 0 to
 * scl.x, and a circle's 1 to scl.x. scl.y is the space between a line's
 * rings, or a circle's radius, and scl.z a ring_group_pattern */
#define RING_GROUP_LAST(work) ((int)(work)->scl.x)
#define RING_GROUP_SPACING(work) ((work)->scl.y)
#define RING_GROUP_PATTERN(work) ((int)(work)->scl.z)

/* how a group's rings lie: on a line along the group's z, or round a
 * circle */
enum ring_group_pattern { RING_GROUP_LINE, RING_GROUP_CIRCLE };

enum ring_group_mode {
    RING_GROUP_PLACE = 0,
    RING_GROUP_RUN = 1,
    RING_GROUP_GONE = 3, /* a ring has left range, and the group goes */
    RING_GROUP_KILL = 4
};

static void ring_group_draw_marker(NJS_POINT3 *pos, struct angles *ang);
static void ring_group_destroy(struct task *task);
static Uint8 ring_group_in_range(struct task *task);
static Uint8 ring_group_keep_taken(struct task *task);
static void ring_group_line_pos(NJS_POINT3 *pos, struct task_work *work,
                                int ring);
static void ring_group_circle_pos(NJS_POINT3 *pos, struct task_work *work,
                                  int ring);

void ObjectGroupRing(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack redundant: 12 bytes of frame that no code reads, of a type unknown,
     * declared as a point. the image's ADD #-72,R15 reserves them (0x8c08cb70);
     * without them, 2 of 251 words differ */
    NJS_POINT3 unused;
    NJS_POINT3 pos;
    struct angles ang = {0, 0, 0};
    int i;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case RING_GROUP_PLACE:
        task->destructor = ring_group_destroy;
        for (i = 0; i < RING_GROUP_LAST(work) + 1; i++) {
            switch (RING_GROUP_PATTERN(work)) {
            case RING_GROUP_LINE:
                ring_group_line_pos(&pos, work, i);
                break;
            case RING_GROUP_CIRCLE:
                if (i == 0) {
                    continue;
                }
                ring_group_circle_pos(&pos, work, i);
            }
            if (OnEdit(task)) {
                ring_group_draw_marker(&pos, &ang);
            }
            if (!OnEdit(task)) {
                Sint8 taken = placement_get_state(task);
                struct task *ring;

                if (!(taken & (1 << i))) {
                    /* @hack spelling: ring set in the test, which tests R0
                     * and copies it in the branch's delay slot (TST R0,R0
                     * at 0x8c08cc2a); set apart, SHC tests the copy and 3
                     * of 251 words differ */
                    if ((ring = CreateChildTask(TASK_WORK, ring_step, task)) !=
                        NULL) {
                        RING(ring->work)->bit = 1 << i;
                        ring->work->pos.x = pos.x;
                        ring->work->pos.y = pos.y;
                        ring->work->pos.z = pos.z;
                        ring->work->ang.x = ang.x;
                        ring->work->ang.y = ang.y;
                        ring->work->ang.z = ang.z;
                    }
                }
            }
        }
        if (!OnEdit(task)) {
            work->mode = RING_GROUP_RUN;
        }
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- NUM MAX 7");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "<- DISTANCE");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z),
                     "<-PATTERN 0:RETU 1:CIRCLE");
        }
        break;
    case RING_GROUP_RUN:
        if (!OnEdit(task)) {
            LoopTaskC(task);
            /* @hack redundant: ring_group_keep_taken's result, tested and
             * left unused, which keeps the image's TST R0,R0 at
             * 0x8c08cd14; as a bare call, the function runs 4 bytes short
             * and 84 of 251 words differ */
            if (ring_group_keep_taken(task)) {
            }
            if (!ring_group_in_range(task)) {
                work->mode = RING_GROUP_GONE;
            }
        }
        /* in the set editor, draw a marker where each ring goes */
        if (OnEdit(task)) {
            /* @hack redundant: 12 bytes of frame that no code reads, of a type
             * unknown, declared as a point. they put pos 48 bytes into the
             * image's 72-byte frame (ADD #48,R4 at 0x8c08cbe2); without them,
             * 13 of 251 words differ */
            NJS_POINT3 unused_preview;
            struct angles preview_ang = {0, 0, 0};
            NJS_POINT3 preview;

            for (i = 0; i < RING_GROUP_LAST(work) + 1; i++) {
                switch (RING_GROUP_PATTERN(work)) {
                case RING_GROUP_LINE:
                    ring_group_line_pos(&preview, work, i);
                    break;
                case RING_GROUP_CIRCLE:
                    if (i == 0) {
                        continue;
                    }
                    ring_group_circle_pos(&preview, work, i);
                }
                ring_group_draw_marker(&preview, &preview_ang);
            }
        }
        break;
    case RING_GROUP_GONE:
        work->mode = RING_GROUP_KILL;
        break;
    case RING_GROUP_KILL:
        FreeTask(task);
        break;
    }
}

/* draw the set editor's box at pos, turned by ang, where a ring goes */
static void ring_group_draw_marker(NJS_POINT3 *pos, struct angles *ang)
{
    njPushMatrix(NULL);
    njTranslate(NULL, pos->x, pos->y, pos->z);
    TURN(njRotateZ, ang->z);
    TURN(njRotateX, ang->x);
    TURN(njRotateY, ang->y);
    late_DrawObject(&marker_box_object);
    late_DrawObjectClipEx(1);
}

static void ring_group_destroy(struct task *task)
{
    FreeTaskC(task);
}

/* 1 while every ring is in range, and 0 once one has left it */
/* @hack type: a Uint8 result, which ring_group_step zero-extends before it
 * tests it (EXTU.B R0,R0 at 0x8c08cd1a); as a Bool, ring_group_step runs 2
 * bytes short and 80 of its 251 words differ */
static Uint8 ring_group_in_range(struct task *task)
{
    struct task *ring;

    for (ring = task->child; ring != NULL; ring = ring->next) {
        if (ring->step == DestroyTask && RING(ring->work)->gone == 1) {
            return 0;
        }
    }
    return 1;
}

/* set each taken ring's bit in the placement's state, so the group doesn't
 * make it again. returns 1 */
/* @hack type: a Uint8 result, which ring_group_step zero-extends before it
 * tests it (EXTU.B R0,R0 at 0x8c08cd12); as a Bool, ring_group_step runs 2
 * bytes short and 84 of its 251 words differ */
static Uint8 ring_group_keep_taken(struct task *task)
{
    struct task *ring;
    Sint8 taken;

    for (ring = task->child; ring != NULL; ring = ring->next) {
        if (ring->work->mode == RING_DONE) {
            taken = placement_get_state(task) | RING(ring->work)->bit;
            placement_set_state(task, taken);
        }
    }
    return 1;
}

/* set pos to where ring goes on a line. ring 0 is at the group. odd rings
 * lie out along the group's z, and even ones back, RING_GROUP_SPACING
 * apart */
static void ring_group_line_pos(NJS_POINT3 *pos, struct task_work *work,
                                int ring)
{
    NJS_VECTOR offset = {0.0F, 0.0F, 0.0F};
    Float number = ring;

    if (ring % 2) {
        offset.z = RING_GROUP_SPACING(work) * ceilf(number * 0.5F);
    } else {
        offset.z = -(RING_GROUP_SPACING(work) * number * 0.5F);
    }
    njPushMatrix(&nj_unit_matrix_);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njCalcVector(NULL, &offset, pos);
    njAddVector(pos, &work->pos);
    late_DrawObjectClipEx(1);
}

/* set pos to where ring goes on a circle. the circle holds RING_GROUP_LAST
 * rings, numbered from 1, RING_GROUP_SPACING from the group and evenly
 * round it in its x and z */
static void ring_group_circle_pos(NJS_POINT3 *pos, struct task_work *work,
                                  int ring)
{
    NJS_VECTOR offset = {0.0F, 0.0F, 0.0F};

    offset.z = RING_GROUP_SPACING(work) *
               njCos((Angle)(ring * 360.0F / work->scl.x * ANGLE_PER_DEGREE));
    offset.x = RING_GROUP_SPACING(work) *
               njSin((Angle)(ring * 360.0F / work->scl.x * ANGLE_PER_DEGREE));
    njPushMatrix(&nj_unit_matrix_);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njCalcVector(NULL, &offset, pos);
    njAddVector(pos, &work->pos);
    late_DrawObjectClipEx(1);
}
