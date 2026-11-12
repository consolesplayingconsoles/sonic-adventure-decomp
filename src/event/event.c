/* @unit 8C04B440-8C04BF00 @data 8C112A34-8C112A4C +jpflags +pool32 */
/* event records and actors */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "collision/collision.h"
#include "collision/ground.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "event/event.h"
#include "player/player.h"
#include "player/weld.h"
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
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
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
void CharacterShadow(struct task_work *work, struct shadow *shadow);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
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
Bool CheckPlayerRideOnMobileLandObjectP(Uint8 player, struct task *task);
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
void FUN_8c04bf00(int player, NJS_OBJECT *object, NJS_MOTION *motion,
                  Float frame);
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
extern struct collision_shape actor_shape;

/* an angle part of the way from one path point to the next, the short way
 * round. the points keep angles in 256ths of a turn */
#define PATH_ANG(from, to, part)                                               \
    ((Angle)((((from) + ((Sint8)((to) - (from)) * (part))) * 256.0F) + 0.5F))

/* each actor's collision sphere, of radius 0. an actor touches nothing until
 * event_set_radius gives it a radius */
/* clang-format off */
/* clang-format on */

void SetEventWork(struct task_work *work)
{
    struct event_work *event;

    if (work->event == NULL) {
        event = CAlloc(1, sizeof(struct event_work));
        work->event = event;
        event->flags = EVENT_GROUND | EVENT_SLOPE;
    }
}

void event_free(struct task_work *work)
{
    if (work->event != NULL) {
        event_motions_clear(work);
        event_paths_clear(work);
        Free(work->event);
        work->event = NULL;
    }
}

void event_motions_clear(struct task_work *work)
{
    struct event_work *event = work->event;
    struct event_motion *entry;
    struct event_motion *next;

    for (entry = event->motions; entry != NULL; entry = next) {
        next = entry->next;
        Free(entry);
    }
    event->motions = NULL;
    if (event->previous != NULL) {
        Free(event->previous);
        event->previous = NULL;
    }
    event->motion_frame = 0.0F;
}

void event_motions_add_action(struct task_work *work, NJS_ACTION *action,
                              NJS_TEXLIST *texlist, Float speed, int flags,
                              int blend)
{
    struct event_work *event = work->event;
    struct event_motion **link = &event->motions;
    struct event_motion *entry;

    while (*link != NULL) {
        link = &(*link)->next;
    }
    entry = CAlloc(1, sizeof(struct event_motion));
    *link = entry;
    entry->flags = flags;
    entry->blend = blend;
    entry->action = *action;
    entry->texlist = texlist;
    entry->speed = speed;
}

void event_motions_add(struct task_work *work, NJS_OBJECT *object,
                       NJS_MOTION *motion, NJS_TEXLIST *texlist, Float speed,
                       int flags, int blend)
{
    struct event_work *event = work->event;
    struct event_motion **link = &event->motions;
    struct event_motion *entry;

    while (*link != NULL) {
        link = &(*link)->next;
    }
    entry = CAlloc(1, sizeof(struct event_motion));
    *link = entry;
    entry->flags = flags;
    entry->blend = blend;
    entry->action.object = object;
    entry->action.motion = motion;
    entry->texlist = texlist;
    entry->speed = speed;
}

void event_motions_draw(struct task_work *work)
{
    struct event_work *event = work->event;
    struct event_motion *entry;
    struct event_motion *previous;
    NJS_MOTION_LINK link;
    NJS_ACTION_LINK action;
    Float frames;
    Float frame;
    int i;

    if (event == NULL) {
        return;
    }
    entry = event->motions;
    previous = event->previous;
    if (entry == NULL) {
        return;
    }
    frames = entry->action.motion->nbFrame;
    frame = event->motion_frame;
    if (entry->texlist != NULL) {
        njSetTexture_jp(entry->texlist);
    }
    draw_set_palette(DRAW_PLAYER_PALETTE);
    if (previous != NULL && entry->blend) {
        action.motionlink = &link;
        action.object = entry->action.object;
        link.motion[0] = previous->action.motion;
        link.motion[1] = entry->action.motion;
        if (previous->flags & EVENT_REPEAT) {
            link.frame[0] = 0.0F;
        } else {
            link.frame[0] = previous->action.motion->nbFrame - 1;
        }
        link.frame[1] = 0.0F;
        for (i = 0; i < PLAYER_COUNT; i++) {
            if (work == playertwp[i]) {
                if (njFloor(frame) * 2.0F < entry->blend) {
                    FUN_8c04bf00(i, entry->action.object, link.motion[0],
                                 link.frame[0]);
                } else {
                    FUN_8c04bf00(i, entry->action.object, link.motion[1],
                                 link.frame[1]);
                }
                break;
            }
        }
        ___dsActionLink(&action, (frame + 1.0F) / (entry->blend + 1));
        frame += 1.0F;
        if (njFloor(frame) >= entry->blend) {
            Free(previous);
            event->previous = NULL;
            frame = 0.0F;
        }
    } else {
        for (i = 0; i < PLAYER_COUNT; i++) {
            if (work == playertwp[i]) {
                FUN_8c04bf00(i, entry->action.object, entry->action.motion,
                             event->motion_frame);
                break;
            }
        }
        ds_ActionClip(&entry->action, event->motion_frame);
        frame += entry->speed;
        if (entry->flags & EVENT_REPEAT) {
            if (frame >= frames) {
                if (entry->next != NULL) {
                    goto ended;
                }
                frame -= frames;
            }
        } else if (frame >= frames - 1.0F) {
        ended:
            event->previous = entry;
            frame = 0.0F;
            event->motions = entry->next;
        }
    }
    draw_set_palette(0);
    event->motion_frame = frame;
}

void event_paths_add(struct task_work *work, struct event_path *path,
                     Float speed, int flags)
{
    struct event_work *event = work->event;
    struct event_path_entry **link = &event->paths;
    struct event_path_entry *entry;

    if (*link != NULL) {
        do {
            link = &(*link)->next;
        } while (*link != NULL);
    } else if (flags & EVENT_FROM_HERE) {
        event->origin = work->pos;
    } else {
        event->origin.x = event->origin.y = event->origin.z = 0.0F;
    }
    entry = CAlloc(1, sizeof(struct event_path_entry));
    *link = entry;
    entry->flags = flags;
    entry->path = path;
    entry->speed = speed;
}

void event_paths_clear(struct task_work *work)
{
    struct event_path_entry *entry;
    struct event_path_entry *next;

    for (entry = work->event->paths; entry != NULL; entry = next) {
        next = entry->next;
        Free(entry);
    }
    work->event->paths = NULL;
    work->event->path_frame = 0.0F;
}

/* replace ang, the angles njRotateXYZ turns by, with angles that make the
 * same turn in the order an actor draws in. that order is z, x and y */
static void angles_to_zxy(struct angles *ang)
{
    NJS_MATRIX matrix;
    NJS_VECTOR y_axis = {0.0F, 1.0F, 0.0F};
    NJS_VECTOR x_axis = {1.0F, 0.0F, 0.0F};
    NJS_VECTOR turned;

    njUnitMatrix(&matrix);
    njRotateXYZ(&matrix, ang->x, ang->y, ang->z);
    njCalcVector(&matrix, &y_axis, &turned);
    ang->z = (Angle)(njArcTan2(-turned.x, turned.y) * ANGLE_PER_RADIAN);
    ang->x = (Angle)(njArcTan2(turned.z, njSqrt((turned.y * turned.y) +
                                                (turned.x * turned.x))) *
                     ANGLE_PER_RADIAN);
    njInvertMatrix(&matrix);
    TURN_MATRIX(njRotateZ, &matrix, ang->z);
    TURN_MATRIX(njRotateX, &matrix, ang->x);
    njCalcVector(&matrix, &x_axis, &turned);
    ang->y = (Angle)(njArcTan2(turned.z, turned.x) * ANGLE_PER_RADIAN);
}

void ExecEventPath(struct task_work *work)
{
    struct event_work *event = work->event;
    struct event_path_entry *entry;
    struct event_path *path;
    struct event_path_point *point;
    struct event_path_point *next;
    Float frame;
    Float count;
    Float part;
    Float ground;
    int index;
    struct angles slope;

    if (event == NULL) {
        return;
    }
    entry = event->paths;
    if (entry == NULL) {
        return;
    }
    path = entry->path;
    count = path->count;
    frame = event->path_frame;
    index = (int)njFloor(frame);
    part = njFraction(frame);
    /* from the last point, a repeating path runs back to the first */
    next = path->points;
    point = &next[index];
    if (index + 1 < path->count) {
        next = point + 1;
    }
    work->pos.x =
        event->origin.x + point->pos.x + ((next->pos.x - point->pos.x) * part);
    work->pos.y =
        event->origin.y + point->pos.y + ((next->pos.y - point->pos.y) * part);
    work->pos.z =
        event->origin.z + point->pos.z + ((next->pos.z - point->pos.z) * part);
    work->ang.x = PATH_ANG(point->ang_x, next->ang_x, part);
    work->ang.y = PATH_ANG(point->ang_y, next->ang_y, part);
    work->ang.z = PATH_ANG(point->ang_z, next->ang_z, part);
    angles_to_zxy(&work->ang);
    work->ang.y = NJM_DEG_ANG(180) - work->ang.y;
    if (work->id == PLAYER_ID) {
        playermwp[PLAYER_VARS(work)->player]->aim.y = work->ang.y;
    }
    if ((event->flags & EVENT_GROUND) || (event->flags & EVENT_SLOPE)) {
        ground = GetShadowPos(work->pos.x, work->pos.y, work->pos.z, &slope);
        if (event->flags & EVENT_GROUND) {
            work->pos.y = ground;
        }
        if (event->flags & EVENT_SLOPE) {
            work->ang.x = slope.x;
            work->ang.z = slope.z;
        }
    }
    frame += entry->speed;
    if (entry->flags & EVENT_REPEAT) {
        if (frame >= count) {
            if (entry->next != NULL) {
                goto ended;
            }
            frame -= count;
        }
    } else if (frame >= count - 1.0F) {
    ended:
        event->paths = entry->next;
        Free(entry);
        frame = 0.0F;
        /* this reads entry after heap_free. heap_free writes only the heap's
         * block headers, so entry's flags are as they were */
        if (entry->flags & EVENT_FROM_HERE) {
            event->origin = work->pos;
        } else {
            event->origin.x = event->origin.y = event->origin.z = 0.0F;
        }
    }
    event->path_frame = frame;
}

void event_mouth_start(struct task_work *work, const char *text)
{
    struct event_mouth *mouth = &work->event->mouth;

    mouth->text = text;
    if (mouth->steps == 0) {
        mouth->timer = 0;
        mouth->steps = 1;
        mouth->shape = 0;
        mouth->next_shape = 0;
    }
}

/* take the next byte of the mouth's text, and return its script's number.
 * A to Z return 0 to 25, and a to z 26 to 51. '0' returns -1, and any other
 * byte its own code, negative from 0x80 on. the end of the text lets go of
 * it, and the end or no text returns 0 */
static int SetEventFace(struct task_work *work)
{
    struct event_mouth *mouth = &work->event->mouth;
    int code;

    if (mouth->text != NULL) {
        /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
        code = *mouth->text++;
        if (code != 0) {
            if (code >= 'A' && code <= 'Z') {
                return code - 'A';
            } else if (code >= 'a' && code <= 'z') {
                return code - 'a' + 26;
            } else if (code != '0') {
                /* @hack spelling: return code stands after return 0, so the
                 * BF at 0x8c04ec80, from the compare with '0', reaches the
                 * last RTS with code still in R0; return code here gets an
                 * RTS of its own, the function runs 4 bytes long and 9 of 40
                 * words differ */
                goto other;
            }
            return -1;
        }
        mouth->text = NULL;
    }
    return 0;
other:
    return code;
}

/* start the mouth on script number, or stop it for a number below 0. number
 * 0, or one whose script is null or empty, starts script 0 three times in
 * four and script 1 otherwise */
static void sub_ExecEventFace(struct task_work *work, int number)
{
    struct event_mouth *mouth;
    struct event_mouth_key *script;

    if (number < 0) {
        event_mouth_stop(work);
    } else {
        mouth = &work->event->mouth;
        /* @bug memory: nothing checks number against the table's 31
         * scripts, so f to z, 31 to 51, and any other byte from 31 to 127
         * read past its end (MOV.L @(R0,R14),R4 at 0x8c04ecb2), and a word
         * there that isn't null is read as a key (MOV.B @R4,R3 at
         * 0x8c04ecb8). the 736 texts the events pass event_talk_start hold
         * only capitals, a to c and '0', so no path reaches a number past
         * 28 */
#ifdef GCC
        /* repairs the read the tag names: GCC takes a number past the table
         * as a null script */
        script =
            number < EVENT_MOUTH_SCRIPTS ? event_mouth_scripts[number] : NULL;
#else
        script = event_mouth_scripts[number];
#endif
        if (number == 0 || script == NULL || script->steps == 0) {
            if (rand() * RAND_SCALE < 0.75F) {
                script = event_mouth_scripts[0];
            } else {
                script = event_mouth_scripts[1];
            }
        }
        mouth->script = script;
    }
}

void ExecEventFace(struct task_work *work)
{
    struct event_mouth *mouth = &work->event->mouth;
    struct event_mouth_key *key;

    if (mouth->steps == 0) {
        return;
    }
    if (++mouth->timer < mouth->steps) {
        return;
    }
    mouth->shape = mouth->next_shape;
    mouth->timer = 0;
    key = mouth->script;
    if (key == NULL || key->steps == 0) {
        sub_ExecEventFace(work, SetEventFace(work));
        if (mouth->steps == 0) {
            return;
        }
    }
    key = mouth->script++;
    /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
    mouth->steps = key->steps;
    mouth->next_shape = key->shape;
}

void event_mouth_stop(struct task_work *work)
{
    struct event_mouth *mouth = &work->event->mouth;

    mouth->text = NULL;
    mouth->script = NULL;
    mouth->steps = 0;
}

struct task *CreateEventObject(void)
{
    struct task *task = CreateElementalTask(TASK_WORK, 5, EventObject);

    SetEventWork(task->work);
    CCL_Init(task, &actor_shape, COLLISION_OBJECT, 1, 1);
    return task;
}

void EventObject(struct task *task)
{
    struct task_work *work = task->work;
    struct event_work *event = work->event;
    NJS_POINT3 under;
    struct angles slope;
    Float x;
    Float y;
    Float z;
    int flags;

    ExecEventFace(work);
    /* @hack spelling: both tests read work->event again, not event; through
     * event, 128 of 140 words differ */
    if (work->event->paths != NULL) {
        ExecEventPath(work);
    }
    if (work->event->motions == NULL) {
        return;
    }
    flags = event->flags;
    x = work->pos.x;
    y = work->pos.y;
    z = work->pos.z;
    under.y = GetShadowPos(x, y, z, &slope);
    if (flags & EVENT_GROUND) {
        work->pos.y = under.y;
    }
    if (flags & EVENT_SLOPE) {
        work->ang.x = slope.x;
        work->ang.z = slope.z;
    }
    if (event->shadow > 0.0F) {
        under.x = x;
        under.y += SHADOW_LIFT;
        under.z = z;
        shadow_draw_at(&slope, &under, event->shadow);
    }
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, NJM_DEG_ANG(180) - work->ang.y);
    njTranslateV(NULL, &event->offset);
    event_motions_draw(work);
    late_DrawObjectClipEx(1);
    if (work->collision->shapes->radius > 0.0F) {
        EntryColliList(work);
    }
}
