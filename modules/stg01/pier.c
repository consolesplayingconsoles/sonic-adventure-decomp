/* @unit 0C903240-0C903AC0 @data 0C910B10-0C910B20 +r04 +egflags +pool32 */
/* the O PIER boardwalk sections, which break apart as the chasing orca
 * reaches them */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stg01/orca_control.h"
#include "stg01/pier.h"
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
extern struct task_work *playertwp[];
extern struct task_motion *playermwp[];
extern struct task *playerpwp[8];
extern Uint8 playerframe[8];
void PInitialize(int player, struct task *task);
void PDestruct(int player);
void PAdjustHoldingPosition(struct task_work *work, struct task_motion *motion);
Bool PCheckPower(struct task_work *work, Angle *ang, Float *stroke);
void PGetAccelerationFly(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void PSetSnowEffect(struct task_work *work, struct task_motion *motion,
                    struct player *record);
void PResetPositionForBuilding(struct task_work *work,
                               struct task_motion *motion,
                               struct player *record);
void PResetPosition(struct task_work *work, struct task_motion *motion,
                    struct player *record);
void PSetCrashEffect(struct task_work *work);
void KillPlayerFallingDownStageP(struct task *task);
void PSetRippleEffect(Uint8 player, NJS_POINT3 *pos, Angle *ang);
int CheckCollisionCylinderP(NJS_POINT3 *pos, Float radius, Float height);
int GetPlayerCharacterName(Uint8 player);
struct task *GetPlayerTaskPointer(Uint8 player);
struct player *GetPlayerWorkPointer(Uint8 player);
int GetTheNearestPlayerNumber(NJS_POINT3 *pos);
void SetLookingTaskP(Uint8 player, struct task *task, NJS_POINT3 *offset);
void SetLookingPointP(Uint8 player, NJS_POINT3 *pos);
void CancelLookingAtP(Uint8 player);
void HoldOnPillarP(Uint8 player, NJS_POINT3 *pos, Uint32 steps);
void KeepPlayersEyesOnThePointP(Uint8 player, struct angles *ang, Uint32 steps);
void SetInputP(Uint8 player, Uint8 mode);
void SetVelocityAndRotationAndNoconTimeWithSpinDashP(Uint8 player,
                                                     NJS_VECTOR *speed,
                                                     const Angle *ang,
                                                     Sint16 steps);
void SetPositionP(Uint8 player, Float x, Float y, Float z);
Bool GetPlayerPosition(Uint8 player, int steps, NJS_POINT3 *pos,
                       struct angles *ang);
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
void FUN_0c903240(struct task *task);
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

#define PIER_KINDS 2
#define PIECE_STEPS 300
#define PIER_RANGE_SQUARED (500.0F * 500.0F)
#define DECK_RANGE 50.0F
#define BREAK_RANGE_SQUARED (75.0F * 75.0F)
#define SE_CRASH 42
#define CRASH_WAIT 2
#define PIECE_GRAVITY 0.1F
#define SINK_SPEED (-0.7F)
#define PIECE_DRAG 0.93F
#define SINK_STEPS 120
#define SIDE_PUSH 2.9F
#define AWAY_PUSH 1.2F
#define PIECE_PUSH 1.8F
#define RISE_MIN 2.5F
#define RISE_MAX 4.0F
#define SPIN_X 3000.0F
#define SPIN_Y 1800.0F
#define FLY_CHANCE 0.6F
#define WAIT_STEPS 5
#define THROW_SPEED 8.0F
#define THROW_RISE 2.0F
#define KIND(work) ((work)->submode)
#define VARS(work) ((struct pier_vars *)&(work)->vars)
#define PIECE(work) ((struct piece_vars *)&(work)->vars)
#define PIECE_MOTION(task) ((struct piece_motion *)(task)->motion)
extern NJS_OBJECT beach_pier_deck_object;
extern NJS_OBJECT beach_pier_straight_object;
extern NJS_OBJECT beach_pier_straight_piece_1_object;
extern NJS_OBJECT beach_pier_straight_piece_2_object;
extern NJS_OBJECT beach_pier_straight_piece_3_object;
extern NJS_OBJECT beach_pier_straight_piece_4_object;
extern NJS_OBJECT beach_pier_straight_piece_5_object;
extern NJS_OBJECT beach_pier_straight_piece_6_object;
extern NJS_OBJECT beach_pier_straight_piece_7_object;
extern NJS_OBJECT beach_pier_straight_piece_8_object;
extern NJS_OBJECT beach_pier_straight_piece_9_object;
extern NJS_OBJECT beach_pier_straight_piece_10_object;
extern NJS_OBJECT beach_pier_straight_piece_11_object;
extern NJS_OBJECT beach_pier_straight_piece_12_object;
extern NJS_OBJECT beach_pier_straight_piece_13_object;
extern NJS_OBJECT beach_pier_straight_piece_14_object;
extern NJS_OBJECT beach_pier_straight_piece_15_object;
extern NJS_OBJECT beach_pier_straight_piece_16_object;
extern NJS_OBJECT beach_pier_straight_piece_17_object;
extern NJS_OBJECT beach_pier_straight_piece_18_object;
extern NJS_OBJECT beach_pier_straight_piece_19_object;
extern NJS_OBJECT beach_pier_straight_piece_20_object;
extern NJS_OBJECT beach_pier_straight_piece_21_object;
extern NJS_OBJECT beach_pier_straight_piece_22_object;
extern NJS_OBJECT beach_pier_straight_piece_23_object;
extern NJS_OBJECT beach_pier_straight_piece_24_object;
extern NJS_OBJECT beach_pier_straight_piece_25_object;
extern NJS_OBJECT beach_pier_corner_object;
extern NJS_OBJECT beach_pier_corner_piece_1_object;
extern NJS_OBJECT beach_pier_corner_piece_2_object;
extern NJS_OBJECT beach_pier_corner_piece_3_object;
extern NJS_OBJECT beach_pier_corner_piece_4_object;
extern NJS_OBJECT beach_pier_corner_piece_5_object;
extern NJS_OBJECT beach_pier_corner_piece_6_object;
extern NJS_OBJECT beach_pier_corner_piece_7_object;
extern NJS_OBJECT beach_pier_corner_piece_8_object;
extern NJS_OBJECT beach_pier_corner_piece_9_object;
extern NJS_OBJECT beach_pier_corner_piece_10_object;
extern NJS_OBJECT beach_pier_corner_piece_11_object;
extern NJS_OBJECT beach_pier_corner_piece_12_object;
extern NJS_OBJECT beach_pier_corner_piece_13_object;
extern NJS_OBJECT beach_pier_corner_piece_14_object;
extern NJS_OBJECT beach_pier_corner_piece_15_object;
extern NJS_OBJECT beach_pier_corner_piece_16_object;
extern NJS_OBJECT beach_pier_corner_piece_17_object;
extern NJS_OBJECT beach_pier_corner_piece_18_object;
extern NJS_OBJECT beach_pier_corner_piece_19_object;
extern NJS_OBJECT beach_pier_corner_piece_20_object;
extern NJS_OBJECT beach_pier_corner_piece_21_object;
extern NJS_OBJECT beach_pier_corner_piece_22_object;
extern NJS_OBJECT beach_pier_corner_piece_23_object;
extern NJS_OBJECT beach_pier_corner_piece_24_object;

/* the kinds of section: straight and corner */
/* a broken section keeps its pieces until its timer passes PIECE_STEPS */

/* the section stays while the camera or player 0 is within 500 of it */
/* the world tests the deck only while player 0 or 1 is within DECK_RANGE */
/* a section breaks once the orca's head is within 75 of it */

/* sound of a breaking section; after it plays, the next CRASH_WAIT sections
 * break silently */

/* a piece's fall acceleration, its sink speed in the sea, and the share of
 * its x and z speed it keeps each step there */

/* a piece stops being drawn once it has sunk for more than SINK_STEPS */

/* a breaking section pushes its pieces SIDE_PUSH out to its side of the
 * orca's path. it pushes them AWAY_PUSH away from the orca's head */
/* a piece flies out at up to PIECE_PUSH times the push. it flies up at
 * RISE_MIN to RISE_MAX a step */
/* a piece spins up to half SPIN_X about x and half SPIN_Y about y a step,
 * either way */
/* a piece flies at once at a chance above FLY_CHANCE, two in five. the rest
 * wait WAIT_STEPS */

/* player 0, thrown off a breaking section, takes THROW_SPEED along it and
 * THROW_RISE up */

/* the section's kind, scl.y modulo PIER_KINDS, kept in submode */

/* the section's deck object in the collision world */
struct pier_vars {
    NJS_OBJECT *world;
};

struct piece_vars {
    Uint8 unk_00[4];
    NJS_OBJECT *part; /* the piece's model */
    Float unk_08; /* the start clears it, and nothing reads it */
};

/* a piece's speed and spins, laid over its task's motion. a spin is the turn
 * the piece adds each step */
struct piece_motion {
    Uint8 unk_00[4];
    NJS_VECTOR speed;
    Uint8 unk_10[24];
    Angle spin_x;
    Angle spin_y;
};

enum pier_mode { PIER_STAND = 0, PIER_BROKEN = 1, PIER_GONE = 6 };

enum piece_mode {
    PIECE_WAIT = 2,
    PIECE_FLY = 3,
    PIECE_FALL = 4,
    PIECE_SINK = 5,
    PIECE_GONE = 6
};

void o_beach_pier_Exec(struct task *task);
void beach_pier_draw(struct task *task);
void beach_pier_destroy(struct task *task);
void beach_pier_piece_start(struct task *task);
void beach_pier_piece_step(struct task *task);
void beach_pier_piece_draw(struct task *task);
void beach_pier_piece_destroy(struct task *task);
extern NJS_OBJECT *beach_pier_straight_parts[26];
extern NJS_OBJECT *beach_pier_corner_parts[25];
extern int beach_pier_part_counts[2];
extern NJS_OBJECT **beach_pier_parts[2];
extern struct collision_shape beach_pier_straight_shapes[2];
extern struct collision_shape beach_pier_corner_shapes[2];
extern struct collision_shape *beach_pier_shapes[2];

/* outside the set editor, put the deck in the collision world, at the
 * section's position and y turn. the deck goes in small and solid, its mesh
 * made again each step. the rails get a collision record */
void FUN_0c903240(struct task *task)
{
    struct task_work *work = task->work;
    struct task_force *force = task->force;
    NJS_OBJECT *object;

    KIND(work) = (Uint8)work->scl.y % PIER_KINDS;
    work->mode = PIER_STAND;
    work->timer = 0;
    force->turn.x = 0;
    force->turn.y = 0;
    force->turn.z = 0;
    force->speed.x = 0.0F;
    force->speed.y = 0.0F;
    force->speed.z = 0.0F;
    if (!OnEdit(task)) {
        object = GetMobileLandObject();
        VARS(work)->world = object;
        object->evalflags = NJD_EVAL_BREAK;
        object->scl[0] = 1.0F;
        object->scl[1] = 1.0F;
        object->scl[2] = 1.0F;
        object->ang[0] = 0;
        object->ang[1] = work->ang.y;
        object->ang[2] = 0;
        object->pos[0] = work->pos.x;
        object->pos[1] = work->pos.y;
        object->pos[2] = work->pos.z;
        object->model = beach_pier_deck_object.model;
        object->child = NULL;
        object->sibling = NULL;
        RegisterCollisionEntry(WORLD_SIZE | WORLD_MOVES | WORLD_SOLID, task,
                               object);
        work->flags |= WORLD_TESTED;
        CCL_Init(task, beach_pier_shapes[KIND(work)], COLLISION_OBJECT, 1, 2);
    }
    task->step = o_beach_pier_Exec;
    task->draw = beach_pier_draw;
    task->destructor = beach_pier_destroy;
}

/* once the orca's head comes within 75 of it, the section breaks. it stops
 * drawing and testing its deck, and creates its pieces */
void o_beach_pier_Exec(struct task *task)
{
    struct task_work *work = task->work;
    Float *at;
    char *bytes;
    Float head_x;
    Float head_y;
    Float head_z;
    Float x;
    Float y;
    Float z;
    Float origin_x;
    Float origin_y;
    Float origin_z;
    /* @hack redundant: a vector declared and never used, which keeps the frame
     * at 40 bytes (ADD #-40,R15 at 0x0c9034f6). without it, 2 of 331 words
     * differ */
    NJS_VECTOR unused;
    /* @hack spelling: way, the orca's direction of motion, reused for the
     * direction from the head to the section. both take the frame's slot at
     * sp+16 (stores at 0x0c903618 and 0x0c903692). with a vector for each,
     * 192 of 331 words differ */
    NJS_VECTOR way;
    /* the way out from the orca's path to the side the section lies on */
    NJS_VECTOR side;
    Float dx;
    Float dy;
    Float dz;
    Float squared;
    Float cross;
    Float facing;
    Float off_x;
    NJS_OBJECT **parts;
    int count;
    int i;
    Float cos;
    Float sin;
    Angle ang;
    struct task *child;
    struct task_work *piece;
    NJS_OBJECT *part;

    if (CheckRangeOutWithR(task, PIER_RANGE_SQUARED)) {
        return;
    }
    if (OnEdit(task)) {
        KIND(work) = (Uint8)work->scl.y % PIER_KINDS;
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "-> KIND OF PIER");
        beach_pier_draw(task);
        return;
    }
    switch (work->mode) {
    case PIER_STAND:
        if (player_in_range(&work->pos, DECK_RANGE)) {
            work->flags |= WORLD_TESTED;
        } else {
            work->flags &= ~WORLD_TESTED;
        }
        /* @hack spelling: the head read a Float at a time through a byte
         * cursor, as the image reads it. through the members, 78 of 331 words
         * differ */
        bytes = (char *)&orca_head;
        head_x = *(Float *)bytes;
        bytes += sizeof(Float);
        head_y = *(Float *)bytes;
        bytes += sizeof(Float);
        head_z = *(Float *)bytes;
        /* @hack spelling: the section's pos walked as Floats through
         * VECTOR_FLOATS, which keeps the image's registers. as a byte cursor,
         * 10 of 331 words differ, and through the members, 81 */
        at = VECTOR_FLOATS(&work->pos);
        x = *at;
        at++;
        y = *at++;
        z = *at;
        dx = head_x - x;
        dy = head_y - y;
        dz = head_z - z;
        squared = (dx * dx) + (dy * dy) + (dz * dz);
        if (squared < BREAK_RANGE_SQUARED) {
            count = beach_pier_part_counts[KIND(work)];
            parts = beach_pier_parts[KIND(work)];
            way.x = orca_speed.x;
            way.y = 0.0F;
            way.z = orca_speed.z;
            off_x = x - head_x;
            /* @hack spelling: head_z, reused for the section's z offset from
             * the head, which keeps the offset in head_z's FR4 (0x0c903628 to
             * 0x0c90362c). with a local of its own, 59 of 331 words differ */
            head_z = z - head_z;
            cross = (way.z * off_x) - (way.x * head_z);
            if (cross < 0.0F) {
                side.x = -way.z;
                side.z = way.x;
            } else {
                side.x = way.z;
                side.z = -way.x;
            }
            way.x = off_x;
            way.y = 0.0F;
            way.z = head_z;
            side.y = 0.0F;
            njUnitVector(&side);
            njUnitVector(&way);
            /* the pieces read their push from scl.x and scl.z */
            work->scl.x = (side.x * SIDE_PUSH) + (way.x * AWAY_PUSH);
            work->scl.z = (side.z * SIDE_PUSH) + (way.z * AWAY_PUSH);
            work->mode = PIER_BROKEN;
            work->timer = 0;
            work->flags &= ~WORLD_TESTED;
            task->draw = NULL;
            /* player 0, if on the deck, is thrown along the section's
             * heading the way the orca moves */
            if (CheckPlayerRideOnMobileLandObjectP(0, task)) {
                cos = njCos(work->ang.y);
                sin = njSin(work->ang.y);
                facing = (sin * orca_speed.x) + (cos * orca_speed.z);
                if (facing < 0.0F) {
                    cos *= -1.0F;
                    sin *= -1.0F;
                }
                player_set_speed(0, sin * THROW_SPEED, THROW_RISE,
                                 cos * THROW_SPEED);
            }
            origin_x = work->pos.x;
            origin_y = work->pos.y;
            origin_z = work->pos.z;
            ang = work->ang.y;
            /* @hack redundant: a store of origin_x that never runs. it gives
             * origin_x its register first, as the image's allocation does
             * (0x0c903740 to 0x0c903786); without it, 6 of 331 words differ */
            if (0) {
                side.x = origin_x;
            }
            for (i = 1; i < count; i++) {
                child = CreateChildTask(TASK_WORK | TASK_MOTION,
                                        beach_pier_piece_start, task);
                piece = child->work;
                part = parts[i];
                PIECE(piece)->part = part;
                piece->ang.y = ang;
                piece->pos.x = origin_x + part->pos[0];
                piece->pos.y = origin_y + part->pos[1];
                piece->pos.z = origin_z + part->pos[2];
            }
            if (orca_crash_wait == 0) {
                dsPlay_oneshot(SE_CRASH, 0, 0, 0);
                orca_crash_wait = CRASH_WAIT;
            } else {
                orca_crash_wait--;
            }
        }
        EntryColliList(work);
        beach_pier_draw(task);
        break;
    case PIER_BROKEN:
        TASK_TIMER(work)++;
        if (TASK_TIMER(work) > PIECE_STEPS) {
            work->mode = PIER_GONE;
            FreeTaskC(task);
        } else {
            LoopTaskC(task);
        }
        break;
    case PIER_GONE:
        break;
    }
}

void beach_pier_draw(struct task *task)
{
    struct task_work *work = task->work;
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObject(beach_pier_parts[KIND(work)][0]);
    late_DrawObjectClipEx(1);
}

void beach_pier_destroy(struct task *task)
{
    struct task_work *work = task->work;

    FreeTaskC(task);
    if (VARS(work)->world != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->world);
        ReleaseMobileLandObject(VARS(work)->world);
    }
}

/* start a piece flying at a random speed and spin */
void beach_pier_piece_start(struct task *task)
{
    struct task_work *work = task->work;
    struct piece_motion *motion = PIECE_MOTION(task);
    struct task_work *parent;
    Float chance;
    Float push_x;
    Float push_z;

    work->timer = 0;
    PIECE(work)->unk_08 = 0.0F;
    chance = rand() * RAND_SCALE;
    work->mode = PIECE_WAIT;
    /* @bug logic: the waits of 2 and 3 steps test for a chance above 0.75
     * and above 0.95 (FCMP/GT at 0x0c903960 and 0x0c90396e). a chance above
     * FLY_CHANCE has already flown at once, so neither test holds */
    if (chance > FLY_CHANCE) {
        work->timer = 0;
        work->mode = PIECE_FLY;
    } else if (chance > 0.75F) {
        work->timer = 2;
    } else if (chance > 0.95F) {
        work->timer = 3;
    } else {
        work->timer = WAIT_STEPS;
    }
    parent = task->parent->work;
    push_x = parent->scl.x;
    push_z = parent->scl.z;
    motion->speed.x = (rand() * push_x) * (PIECE_PUSH * RAND_SCALE);
    motion->speed.y = RANDOM(RISE_MIN, RISE_MAX);
    motion->speed.z = (rand() * push_z) * (PIECE_PUSH * RAND_SCALE);
    motion->spin_y = RANDOM(-0.5F, 0.5F) * SPIN_Y;
    motion->spin_x = RANDOM(-0.5F, 0.5F) * SPIN_X;
    task->step = beach_pier_piece_step;
    task->draw = beach_pier_piece_draw;
    task->destructor = beach_pier_piece_destroy;
    beach_pier_piece_draw(task);
}

/* a waiting piece counts its timer down to 0, then flies. it falls once its
 * y speed turns down, and sinks once it reaches SEA_LEVEL. it sinks at
 * SINK_SPEED while PIECE_DRAG slows its x and z speeds. it stops being drawn
 * after SINK_STEPS */
void beach_pier_piece_step(struct task *task)
{
    struct task_work *work = task->work;
    struct piece_motion *motion = PIECE_MOTION(task);
    /* @hack spelling: pos and speed read and written back a Float at a time
     * through byte cursors over the whole records. read through the members,
     * 138 of 176 words differ. written through them, the function runs 28
     * bytes short and 165 differ */
    char *pos = (char *)&work->pos;
    Float x;
    Float y;
    Float z;
    char *speed = (char *)&motion->speed;
    Float vx;
    Float vy;
    Float vz;
    /* @hack redundant: splash, set as the piece lands and never read
     * (0x0c903b74 to 0x0c903b80). without it, the function runs 32 bytes
     * short and 79 of 176 words differ */
    NJS_VECTOR splash;

    x = *(Float *)pos;
    pos += sizeof(Float);
    y = *(Float *)pos;
    pos += sizeof(Float);
    z = *(Float *)pos;
    pos += sizeof(Float);
    pos -= 3 * sizeof(Float);
    vx = *(Float *)speed;
    speed += sizeof(Float);
    vy = *(Float *)speed;
    speed += sizeof(Float);
    vz = *(Float *)speed;
    speed += sizeof(Float);
    speed -= 3 * sizeof(Float);
    switch (work->mode) {
    case PIECE_WAIT:
        TASK_TIMER(work)--;
        if (TASK_TIMER(work) <= 0) {
            work->timer = 0;
            work->mode = PIECE_FLY;
        }
        beach_pier_piece_draw(task);
        break;
    case PIECE_FLY:
        x += vx;
        y += vy;
        z += vz;
        vy -= PIECE_GRAVITY;
        work->ang.y += motion->spin_y;
        work->ang.x += motion->spin_x;
        if (vy < 0.0F) {
            work->mode = PIECE_FALL;
        }
        beach_pier_piece_draw(task);
        break;
    case PIECE_FALL:
        x += vx;
        y += vy;
        z += vz;
        work->ang.y += motion->spin_y;
        work->ang.x += motion->spin_x;
        vy -= PIECE_GRAVITY;
        if (y <= SEA_LEVEL) {
            work->mode = PIECE_SINK;
            work->timer = 0;
            vy = SINK_SPEED;
            splash.x = vx * 0.1F;
            splash.y = 0.0F;
            splash.z = vz * 0.1F;
        }
        beach_pier_piece_draw(task);
        break;
    case PIECE_SINK:
        TASK_TIMER(work)++;
        if (TASK_TIMER(work) > SINK_STEPS) {
            work->mode = PIECE_GONE;
        }
        x += vx;
        y += vy;
        z += vz;
        vx *= PIECE_DRAG;
        vz *= PIECE_DRAG;
        beach_pier_piece_draw(task);
        break;
    case PIECE_GONE:
        task->draw = NULL;
        break;
    }
    *(Float *)pos = x;
    pos += sizeof(Float);
    *(Float *)pos = y;
    pos += sizeof(Float);
    *(Float *)pos = z;
    *(Float *)speed = vx;
    speed += sizeof(Float);
    *(Float *)speed = vy;
    speed += sizeof(Float);
    *(Float *)speed = vz;
}

void beach_pier_piece_draw(struct task *task)
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

void beach_pier_piece_destroy(struct task *task)
{
}
