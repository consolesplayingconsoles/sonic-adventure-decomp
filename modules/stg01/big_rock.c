/* @unit 0C903AC0-0C904220 @data 0C910B20-0C910B30 +r04 +egflags +pool32 */
/* O BIGROCK, a big rock that topples once the orca's head comes near it. it
 * breaks into pieces as it falls */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "sound/sound.h"
#include "stg01/big_rock.h"
#include "stg01/orca_control.h"
#include "stg01/sea.h"
#include "system/task.h"
#include "system/texture.h"
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
extern NJS_MATRIX nj_unit_matrix_;
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
void kmiLogFileOpen(void *data);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
extern struct task *OrukaTask;
void orInitOrukaSequence(void);
Bool orCreateAttackOruka(Float x, Float y, Float z, Angle ang);
void orFreePathOruka(struct task *task);
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

/* the rock's kinds, a and b, which index the tables below. a rock keeps its
 * kind in its work's submode */
#define BIG_ROCK_KINDS 2
#define KIND(work) ((work)->submode)

/* the rock destroys itself once the camera and player 0 are both beyond
 * 1000 of it. it stays while player 1 is Sonic within 40 of it. the range is
 * squared, as placement_try_leave_by takes it */
#define LEAVE_RANGE (1000.0F * 1000.0F)
/* the radius of the rock's collision record */
#define ROCK_REACH 150.0F

/* a standing rock topples once the orca's head is within 70 of it in x and
 * z. the range is squared */
#define TOPPLE_RANGE (70.0F * 70.0F)

#define SE_TOPPLE 43

/* a rock falls along its push, which has two parts. SIDE_PUSH points to the
 * side of the orca's path the rock stands on. AWAY_PUSH points away from the
 * orca's head */
#define SIDE_PUSH 5.0F
#define AWAY_PUSH 2.0F
/* each step, a toppling rock slides SLIDE_SHARE of its push */
#define SLIDE_SHARE 0.01F
/* the rock tips TIP_START a step at first, 65536 a turn. each step it tips
 * faster by TIP_GAIN times the sine of its tip */
#define TIP_START 70.0F
#define TIP_GAIN 30.0F
/* the rock breaks once its tip brings the point BREAK_POINT up its axis below
 * a height of BREAK_HEIGHT */
#define BREAK_POINT 80.0F
#define BREAK_HEIGHT 15.0F

/* a piece starts out falling PIECE_DROP a step. in x and z, it starts out
 * flying SCATTER_SHARE of its offset from the rock a step */
#define PIECE_DROP 0.5F
#define SCATTER_SHARE 0.01F
/* what a falling piece's upward speed loses each step, and how far a sinking
 * piece sinks each step */
#define PIECE_GRAVITY 0.1F
/* the share of its speed in x and z a piece keeps each step. FALL_KEEP
 * holds while it falls, and SINK_KEEP once it sinks */
#define FALL_KEEP 0.995F
#define SINK_KEEP 0.97F
/* how far a falling piece turns about x each step, 65536 a turn */
#define TUMBLE_X 500

/* a broken rock destroys its pieces after more than PIECE_STEPS steps */
#define PIECE_STEPS 400

#define VARS(work) ((struct big_rock_vars *)&(work)->vars)
#define PIECE(work) ((struct piece_vars *)&(work)->vars)
struct big_rock_vars {
    Float tip_speed; /* the angle added to the tip each step */
};

/* what a piece keeps in work->vars. its speed is in work->scl. ang.z starts
 * as the rock's heading, ang.x as its tip, and ang.y as its turn. the
 * piece's draw turns it about y by ang.z, about x by ang.x, then about y by
 * ang.y */
struct piece_vars {
    Uint8 unk_00[4];
    NJS_OBJECT *part; /* its part of the rock */
};

enum big_rock_mode {
    BIG_ROCK_STAND = 0,
    BIG_ROCK_TOPPLE = 1,
    BIG_ROCK_BROKEN = 2,
    BIG_ROCK_GONE = 4
};

enum piece_mode { PIECE_FALL = 0, PIECE_SINK = 3 };

void o_beach_bigrock_Exec(struct task *task);
void ExecChild(struct task *task);
void beach_big_rock_draw(struct task *task);
void beach_big_rock_destroy(struct task *task);
void beach_big_rock_piece_start(struct task *task);
void beach_big_rock_piece_step(struct task *task);
void beach_big_rock_piece_draw(struct task *task);
void beach_big_rock_piece_destroy(struct task *task);
extern NJS_OBJECT *beach_big_rock_a_parts[10];
extern NJS_OBJECT *beach_big_rock_b_parts[11];
extern int beach_big_rock_part_counts[2];
extern NJS_OBJECT **beach_big_rock_parts[2];
extern struct collision_shape beach_big_rock_shapes[2];
/* clang-format on */

void beach_big_rock_init(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    work->mode = BIG_ROCK_STAND;
    KIND(work) = (Uint8)(int)work->scl.y % BIG_ROCK_KINDS;
    work->ang.x = 0;
    work->ang.z = 0;
    VARS(work)->tip_speed = 0.0F;
    motion->aim.x = 0;
    motion->aim.y = 0;
    if (!OnEdit(task)) {
        CCL_Init(task, &beach_big_rock_shapes[KIND(work)], COLLISION_OBJECT, 1,
                 1);
        work->collision->radius = ROCK_REACH;
    }
    task->step = o_beach_bigrock_Exec;
    task->draw = beach_big_rock_draw;
    task->destructor = beach_big_rock_destroy;
}

void ObjectBeachBigrockC(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    work->mode = BIG_ROCK_STAND;
    KIND(work) = (Uint8)(int)work->scl.y % BIG_ROCK_KINDS;
    VARS(work)->tip_speed = 0.0F;
    motion->aim.x = 0;
    motion->aim.y = 0;
    CCL_Init(task, &beach_big_rock_shapes[KIND(work)], COLLISION_OBJECT, 1, 1);
    work->collision->radius = ROCK_REACH;
    task->step = ExecChild;
    task->draw = beach_big_rock_draw;
    task->destructor = beach_big_rock_destroy;
}

/* in the set editor, take the kind from scale y again, label its row and draw
 * the rock without running it */
void o_beach_bigrock_Exec(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, LEAVE_RANGE)) {
        return;
    }
    if (OnEdit(task)) {
        KIND(work) = (Uint8)(int)work->scl.y % BIG_ROCK_KINDS;
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "-> KIND OF ROCK");
        beach_big_rock_draw(task);
        return;
    }
    ExecChild(task);
}

/* the rock registers its collision only while it stands. it topples along
 * its push once the orca's head's squared distance falls below TOPPLE_RANGE.
 * a toppling rock's motion holds its fall. aim.y is the heading it falls
 * along, and aim.x how far it has tipped. the motion's speed is how far it
 * slides each step. once its tip brings BREAK_POINT below BREAK_HEIGHT, it
 * draws a last time and breaks. its pieces fall as its children */
void ExecChild(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    /* way is the orca's direction of motion, then the way from its head to
     * the rock. side points to the side of the orca's path the rock stands
     * on. the break uses side for each piece's offset, and way for that
     * offset turned */
    NJS_VECTOR way;
    NJS_VECTOR side;
    Float dx;
    Float dz;
    Float cross;
    Float vx;
    Float vz;
    Float value;
    Float distance;
    NJS_OBJECT **parts;
    Float *at;
    NJS_OBJECT *part;
    struct task *child;
    struct task_work *piece;
    int count;
    int i;
    Float x;
    Float y;
    Float z;
    Angle tip;
    Angle heading;
    Angle turn;

    switch (work->mode) {
    case BIG_ROCK_STAND:
        /* @hack spelling: the head's x and z, then the rock's, read through a
         * pointer that steps over y, which loads them with FMOV.S @R4+ and
         * ADD #4 (0x0c903e86, 0x0c903e92); without it, 155 of 391 words
         * differ */
        at = VECTOR_FLOATS(&orca_head);
        x = *at;
        at++;
        at++;
        z = *at;
        at = VECTOR_FLOATS(&work->pos);
        dx = x - (vx = *at);
        at++;
        at++;
        dz = z - (vz = *at);
        /* @hack redundant: never-run tests and a store, which put the head's x
         * in FR4 and the rock's in FR5 at 0x0c903e86 and 0x0c903e92, and the
         * rock's x and z in FR14 and FR13 at 0x0c904056 and 0x0c904064; without
         * it, 38 of 391 words differ */
        if (0) {
            if (x) {
            }
            if (vx) {
            }
            if (vx) {
            }
            if (vx) {
            }
            if (vx) {
            }
            if (vx) {
            }
            work->mode = BIG_ROCK_STAND;
        }
        distance = (dx * dx) + (dz * dz);
        if (distance < TOPPLE_RANGE) {
            way.x = orca_speed.x;
            way.y = 0.0F;
            way.z = orca_speed.z;
            /* @hack spelling: x and z, reused for the rock's offset from the
             * head, which keeps the offset in the head's own FR4 and FR6
             * (0x0c903ec4 to 0x0c903ece); in locals of its own, 141 of 391
             * words differ */
            x = vx - x;
            z = vz - z;
            cross = (way.z * x) - (way.x * z);
            if (cross < 0.0F) {
                side.x = -way.z;
                side.z = way.x;
            } else {
                side.x = way.z;
                side.z = -way.x;
            }
            side.y = 0.0F;
            way.x = x;
            way.y = 0.0F;
            way.z = z;
            njUnitVector(&side);
            njUnitVector(&way);
            vx = (side.x * SIDE_PUSH) + (way.x * AWAY_PUSH);
            vz = (side.z * SIDE_PUSH) + (way.z * AWAY_PUSH);
            motion->speed.x = vx * SLIDE_SHARE;
            motion->speed.z = vz * SLIDE_SHARE;
            motion->aim.y = (Angle)(njArcTan2(vx, vz) * ANGLE_PER_RADIAN);
            work->ang.y -= motion->aim.y;
            motion->aim.x = 0;
            work->mode = BIG_ROCK_TOPPLE;
            VARS(work)->tip_speed = TIP_START;
            dsPlay_oneshot(SE_TOPPLE, 0, 0, 0);
        }
        EntryColliList(work);
        beach_big_rock_draw(task);
        break;
    case BIG_ROCK_TOPPLE:
        tip = motion->aim.x += (int)VARS(work)->tip_speed;
        VARS(work)->tip_speed += njSin(tip) * TIP_GAIN;
        value = njCos(tip);
        work->pos.x += motion->speed.x;
        work->pos.z += motion->speed.z;
        if (value * BREAK_POINT < BREAK_HEIGHT - work->pos.y) {
            parts = beach_big_rock_parts[KIND(work)];
            x = work->pos.x;
            y = work->pos.y;
            z = work->pos.z;
            turn = work->ang.y;
            tip = motion->aim.x;
            heading = motion->aim.y;
            count = beach_big_rock_part_counts[KIND(work)];
            njPushMatrix(NULL);
            njUnitMatrix(NULL);
            /* @hack redundant: never-run tests of work, which put dx in FR7 and
             * dz in FR9 at 0x0c903e8a to 0x0c903ea4; without it, 8 of 391 words
             * differ */
            if (0) {
                if (work) {
                }
                if (work) {
                }
                if (work) {
                }
            }
            if (heading) {
                njRotateY(NULL, heading);
            }
            /* @hack redundant: an empty never-run branch, which reloads tip
             * into R3, not R2, at 0x0c904088; without it, 2 of 391 words
             * differ */
            if (0) {
            }
            if (tip) {
                njRotateX(NULL, tip);
            }
            /* @hack spelling: the empty arm for a turn of 0, which loads
             * njRotateY into R2, not R3, at 0x0c90409a; as if (turn) and the
             * call alone, 7 of 391 words differ */
            if (!turn) {
            } else {
                njRotateY(NULL, turn);
            }
            /* @hack redundant: the jump to the next statement, which puts
             * parts' cursor in R2 and count in R3 (0x0c9040a2, 0x0c9040ac);
             * without it, 5 of 391 words differ */
            goto pieces;
        pieces:
            /* @hack spelling: i stepped as i = i + 1; as i++, tip moves from
             * the frame at sp+0 to R9 and turn from R8 to the frame (0x0c904062
             * to 0x0c90406e), and 32 of 391 words differ */
            for (i = 1; i < count; i = i + 1) {
                child = CreateChildTask(TASK_WORK, beach_big_rock_piece_start,
                                        task);
                piece = child->work;
                part = parts[i];
                PIECE(piece)->part = part;
                piece->ang.x = tip;
                piece->ang.y = turn;
                piece->ang.z = heading;
                /* @hack spelling: the part's pos read through a pointer, which
                 * loads it into side with FMOV.S @R4+ from 0x0c9040e4; without
                 * it, 77 of 391 words differ */
                at = part->pos;
                side.x = *at++;
                side.y = *at++;
                side.z = *at;
                njCalcVector(NULL, &side, &way);
                /* @hack spelling: the turned x read into value first, which
                 * loads way.x before way.z at 0x0c9040f8, and puts AWAY_PUSH
                 * ahead of SIDE_PUSH in the pool at 0x0c903fb0; without it, 9
                 * of 391 words and 2 pool words differ */
                value = way.x;
                dz = way.z + z;
                dx = value + x;
                piece->pos.x = dx;
                piece->pos.y = way.y + y;
                piece->pos.z = dz;
                piece->scl.x = (dx - x) * SCATTER_SHARE;
                piece->scl.y = -PIECE_DROP;
                piece->scl.z = (dz - z) * SCATTER_SHARE;
            }
            late_DrawObjectClipEx(1);
            LoopTaskC(task);
            work->mode = BIG_ROCK_BROKEN;
            work->timer = 0;
            task->draw = NULL;
        }
        beach_big_rock_draw(task);
        break;
    case BIG_ROCK_BROKEN:
        TASK_TIMER(work)++;
        if (TASK_TIMER(work) > PIECE_STEPS) {
            work->mode = BIG_ROCK_GONE;
            FreeTaskC(task);
        } else {
            LoopTaskC(task);
        }
        break;
    case BIG_ROCK_GONE:
        break;
    }
}

void beach_big_rock_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, motion->aim.y);
    TURN(njRotateX, motion->aim.x);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(*beach_big_rock_parts[KIND(work)]);
    late_DrawObjectClipEx(1);
}

void beach_big_rock_destroy(struct task *task)
{
    FreeTaskC(task);
}

void beach_big_rock_piece_start(struct task *task)
{
    struct task_work *work = task->work;

    work->timer = 0;
    work->mode = PIECE_FALL;
    task->step = beach_big_rock_piece_step;
    task->draw = beach_big_rock_piece_draw;
    task->destructor = beach_big_rock_piece_destroy;
}

/* a piece falls, tumbling about x, until it goes below SEA_LEVEL. then it
 * sinks while its speed in x and z fades, until the rock destroys it */
void beach_big_rock_piece_step(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack spelling: the pos and the speed read and written a float at a time
     * through pointers, which load them with FMOV.S @R5+ and @R6+ from
     * 0x0c9042ea; without it, 31 of 58 words differ */
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
        y += speed_y;
        x += speed_x;
        z += speed_z;
        speed_x *= FALL_KEEP;
        speed_y -= PIECE_GRAVITY;
        speed_z *= FALL_KEEP;
        work->ang.x += TUMBLE_X;
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
    beach_big_rock_piece_draw(task);
}

void beach_big_rock_piece_draw(struct task *task)
{
    struct task_work *work = task->work;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    ds_DrawModelClip(PIECE(work)->part->model);
    late_DrawObjectClipEx(1);
}

void beach_big_rock_piece_destroy(struct task *task)
{
}
