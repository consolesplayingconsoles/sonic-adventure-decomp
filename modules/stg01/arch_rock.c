/* @unit 0C90AC60-0C90B1A0 +r04 +egflags +pool32 +asmfunc=arch_rock_step */
/* O ARCHROCK, a rock arch standing on two big rocks. its top falls in
 * pieces once either rock starts to topple */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "stg01/arch_rock.h"
#include "stg01/big_rock.h"
#include "stg01/sea.h"
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
void *syMalloc_default_malloc(size_t size);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
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
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
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

#define LEAVE_RANGE (1000.0F * 1000.0F)
#define ARCH_REACH 150.0F
#define LEG_A_Z 73.0F
#define LEG_B_Z 57.0F
#define TOP_Y 110.0F
#define FALL_WAIT 8
#define TOP_PIECES 7
#define PIECE_SPREAD 3.4F
#define PIECE_LIFT 3.0F
#define PIECE_GRAVITY 0.1F
#define FALL_KEEP 0.995F
#define SINK_KEEP 0.97F
#define TUMBLE_X 500
#define TUMBLE_Z 800
#define VARS(work) ((struct arch_rock_vars *)&(work)->vars)
#define PIECE(work) ((struct piece_vars *)&(work)->vars)
extern NJS_OBJECT arch_rock_object;
extern NJS_OBJECT arch_rock_piece_1_object;
extern NJS_OBJECT arch_rock_piece_2_object;
extern NJS_OBJECT arch_rock_piece_3_object;
extern NJS_OBJECT arch_rock_piece_4_object;
extern NJS_OBJECT arch_rock_piece_5_object;
extern NJS_OBJECT arch_rock_piece_6_object;
extern NJS_OBJECT arch_rock_piece_7_object;

/* the arch destroys itself once the camera and player 0 are both beyond
 * 1000 of it. it stays while player 1 is Sonic within 40 of it. the range is
 * squared, as placement_try_leave_by takes it */
/* the radius of the arch's collision record, which holds the top's capsule */

/* where the parts stand in the arch's frame. big rock a stands LEG_A_Z ahead
 * along z, big rock b LEG_B_Z behind, and the top TOP_Y up */

/* the top breaks into TOP_PIECES pieces FALL_WAIT + 2 steps after a big rock
 * starts to topple. the arch tests its rocks before it steps them, so it sees
 * the topple a step late. its timer then counts up from 0, and the top breaks
 * once the timer passes FALL_WAIT */

/* a piece flies off at a random speed. in x and in z, that speed is within
 * PIECE_SPREAD / 2 of 0. its speed up is below PIECE_LIFT */
/* what a falling piece's upward speed loses each step, and how far a sinking
 * piece sinks each step */
/* the share of its speed in x and z a piece keeps each step. FALL_KEEP
 * holds while it falls, and SINK_KEEP once it sinks */
/* how far a falling piece turns about x and about z each step, 65536 a
 * turn */

struct arch_rock_vars {
    Float unk_00;
};

/* what a piece keeps in work->vars. its speed is in work->scl */
struct piece_vars {
    Uint8 unk_00[4];
    NJS_OBJECT *part; /* its part of the top */
};

enum arch_rock_mode {
    ARCH_ROCK_STAND = 0,
    ARCH_ROCK_BREAK = 1,
    ARCH_ROCK_FALLEN = 3
};

/* the arch's parts, which index arch_rock_parts and arch_rock_part_counts */
enum arch_rock_part { PART_LEG_A, PART_TOP, PART_LEG_B, ARCH_ROCK_PARTS };

enum piece_mode { PIECE_FALL = 0, PIECE_SINK = 2 };

void arch_rock_step(struct task *task);
void o_beach_archrock_Disp(struct task *task);
void arch_rock_destroy(struct task *task);
void arch_rock_piece_start(struct task *task);
void arch_rock_piece_step(struct task *task);
void arch_rock_piece_draw(struct task *task);
void arch_rock_piece_destroy(struct task *task);
extern NJS_OBJECT *arch_rock_leg_a_parts[10];
extern NJS_OBJECT *arch_rock_top_parts[7 + 1];
extern NJS_OBJECT *arch_rock_leg_b_parts[11];
extern int arch_rock_part_counts[ARCH_ROCK_PARTS];
extern NJS_OBJECT **arch_rock_parts[ARCH_ROCK_PARTS];
extern struct collision_shape arch_rock_shape;
/* clang-format on */

void ObjectBeachArchrock(struct task *task)
{
    struct task_work *work = task->work;
    struct task *child;
    struct task_work *rock;
    Float *at;
    Float x;
    Float y;
    Float z;
    Float sin;
    Float cos;

    work->mode = ARCH_ROCK_STAND;
    VARS(work)->unk_00 = 0.0F;
    if (!OnEdit(task)) {
        CCL_Init(task, &arch_rock_shape, COLLISION_OBJECT, 1, 1);
        work->collision->radius = ARCH_REACH;
        /* @hack spelling: the position read a float at a time through a
         * pointer, which loads it with FMOV.S @R4+ from 0x0c90b248; without it,
         * 87 of 109 words differ */
        at = VECTOR_FLOATS(&work->pos);
        x = *at++;
        y = *at++;
        z = *at;
        sin = njSin(work->ang.y);
        cos = njCos(work->ang.y);
        child =
            CreateChildTask(TASK_WORK | TASK_MOTION, ObjectBeachBigrockC, task);
        rock = child->work;
        rock->scl.y = 0.0F; /* its kind: big rock a */
        rock->pos.x = x + (sin * LEG_A_Z);
        rock->pos.y = y;
        rock->pos.z = z + (cos * LEG_A_Z);
        child =
            CreateChildTask(TASK_WORK | TASK_MOTION, ObjectBeachBigrockC, task);
        rock = child->work;
        rock->scl.y = 1.0F; /* its kind: big rock b */
        rock->pos.x = x - (sin * LEG_B_Z);
        rock->pos.y = y;
        rock->pos.z = z - (cos * LEG_B_Z);
    }
    task->step = arch_rock_step;
    task->draw = o_beach_archrock_Disp;
    task->destructor = arch_rock_destroy;
}

/* once either big rock's work mode leaves 0, as it starts to topple, wait
 * out FALL_WAIT. then stop drawing the top, and start its pieces as children.
 * each piece starts at its part's pos from the top, not turned by the arch's
 * heading */
void arch_rock_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task *child;
    struct task_work *piece;
    struct task_work *rock;
    NJS_OBJECT **next;
    NJS_OBJECT *part;
    Float x;
    Float y;
    Float z;
    Float *at;
    Angle ang;
    int i;

    if (CheckRangeOutWithR(task, LEAVE_RANGE)) {
        return;
    }
    switch (work->mode) {
    case ARCH_ROCK_STAND:
        for (child = task->child; child != ((void *)0); child = child->next) {
            work = work;
            rock = child->work;
            if (rock->mode) {
                work->timer = 0;
                work->mode = ARCH_ROCK_BREAK;
            }
        }
        o_beach_archrock_Disp(task);
        break;
    case ARCH_ROCK_BREAK:
        ++TASK_TIMER(work);
        if (TASK_TIMER(work) > FALL_WAIT) {
            x = work->pos.x;
            y = work->pos.y;
            z = work->pos.z;
            ang = work->ang.y;
            next = &arch_rock_top_parts[1];
            for (i = 0; i < TOP_PIECES; ++i) {
                child = CreateChildTask(TASK_WORK, arch_rock_piece_start, task);
                piece = child->work;
                part = *next++;
                PIECE(piece)->part = part;
                piece->ang.x = 0;
                piece->ang.y = ang;
                piece->ang.z = 0;
                /* @hack spelling: the part's pos read through a pointer, which
                 * loads it with FMOV.S @R4+ from 0x0c90b404; without it, 94
                 * of 191 words differ */
                at = part->pos;
                piece->pos.x = x + *at++;
                piece->pos.y = y + *at++ + TOP_Y;
                piece->pos.z = z + *at;
                piece->scl.x = RANDOM(-0.5F, 0.5F) * PIECE_SPREAD;
                piece->scl.y = rand() * (PIECE_LIFT * RAND_SCALE);
                piece->scl.z = RANDOM(-0.5F, 0.5F) * PIECE_SPREAD;
            }
            work->mode = ARCH_ROCK_FALLEN;
            task->draw = NULL;
        }
        o_beach_archrock_Disp(task);
        break;
    case ARCH_ROCK_FALLEN:
        break;
    }
    if (!OnEdit(task)) {
        EntryColliList(work);
    }
    LoopTaskC(task);
}

/* draw the top. in the set editor, where arch_rock_init starts no big
 * rocks, draw both of them whole too */
void o_beach_archrock_Disp(struct task *task)
{
    /* @hack spelling: arch, a copy of task, which SHC keeps in R13 across the
     * calls before placement_editing (MOV R4,R13 at 0x0c90b4c8); without it,
     * 34 of 86 words differ */
    struct task *arch = task;
    struct task_work *work = arch->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateY, work->ang.y, ang);
    if (OnEdit(arch)) {
        njPushMatrix(NULL);
        njTranslate(NULL, 0.0F, 0.0F, LEG_A_Z);
        late_DrawObject(*arch_rock_parts[PART_LEG_A]);
        late_DrawObjectClipEx(1);
        njPushMatrix(NULL);
        njTranslate(NULL, 0.0F, 0.0F, -LEG_B_Z);
        late_DrawObject(*arch_rock_parts[PART_LEG_B]);
        late_DrawObjectClipEx(1);
    }
    njTranslate(NULL, 0.0F, TOP_Y, 0.0F);
    late_DrawObject(*arch_rock_parts[PART_TOP]);
    late_DrawObjectClipEx(1);
}

void arch_rock_destroy(struct task *task)
{
    FreeTaskC(task);
}

void arch_rock_piece_start(struct task *task)
{
    struct task_work *work = task->work;

    work->timer = 0;
    work->mode = PIECE_FALL;
    task->step = arch_rock_piece_step;
    task->draw = arch_rock_piece_draw;
    task->destructor = arch_rock_piece_destroy;
}

/* move a piece. it falls, tumbling, until it drops below SEA_LEVEL. then it
 * sinks PIECE_GRAVITY a step until the arch's destructor destroys it */
void arch_rock_piece_step(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack spelling: the position and speed read and written a float at a time
     * through pointers, which load them with FMOV.S @R6+ and @R5+ from
     * 0x0c90b60e; without it, 33 of 62 words differ */
    Float *pos = VECTOR_FLOATS(&work->pos);
    Float *speed = VECTOR_FLOATS(&work->scl);
    Float x = *pos++;
    Float speed_x = *speed++;
    Float y = *pos++;
    Float speed_y = *speed++;
    Float z = *pos++;
    Float speed_z = *speed++;

    pos -= 3;
    speed -= 3;
    switch (work->mode) {
    case PIECE_FALL:
        x += speed_x;
        y += speed_y;
        z += speed_z;
        speed_x *= FALL_KEEP;
        speed_y -= PIECE_GRAVITY;
        work->ang.x += TUMBLE_X;
        work->ang.z += TUMBLE_Z;
        speed_z *= FALL_KEEP;
        if (y < SEA_LEVEL) {
            work->mode = PIECE_SINK;
        }
        break;
    case PIECE_SINK:
        y -= PIECE_GRAVITY;
        x += speed_x;
        z += speed_z;
        speed_x *= SINK_KEEP;
        speed_z *= SINK_KEEP;
        break;
    }
    *pos++ = x;
    *pos++ = y;
    *pos = z;
    *speed++ = speed_x;
    *speed++ = speed_y;
    *speed = speed_z;
    arch_rock_piece_draw(task);
}

/* draw the piece's model at its position, turned about x and then y. a
 * falling piece's ang.z turns each step too, but the draw leaves it out */
void arch_rock_piece_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(PIECE(work)->part->model);
    late_DrawObjectClipEx(1);
}

void arch_rock_piece_destroy(struct task *task)
{
}
