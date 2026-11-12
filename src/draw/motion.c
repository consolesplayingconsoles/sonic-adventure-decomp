/* @unit 8C018120-8C019360 +r04 +egflags +pool32 */
/* motions: a model playing a table of actions, blending each into the next */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/motion.h"
#include "draw/pose.h"
#include "player/player.h"
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
extern Sint8 chaos_reqmode;
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *syMalloc_default_malloc(size_t size);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
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

/* the room, in nodes, for a tree as tree_list_nodes lists it, and in the
 * blend's motion data */
#define TREE_NODES 128
#define BLEND_NODES 118

/* the factors in each node's motion data: positions and angles, and scales
 * too in a motion with NJD_MTYPE_SCL_2 */
#define FACTORS 2
#define SCALED_FACTORS 3

/* the blend's motion: two frames, from the old action's pose at the frame
 * to the new action's first key. it has scales when either action does.
 * each factor has a key at frame 0 and one at frame 1 */
#define BLEND_FRAMES 2
#define BLEND_KEYS 2
#define BLEND_TYPE (NJD_MTYPE_POS_0 | NJD_MTYPE_ANG_1)
#define BLEND_SCALED_TYPE (BLEND_TYPE | NJD_MTYPE_SCL_2)

/* narrow an angle to 16 bits, a half turn either way, in place */
/* @hack spelling: a bare scope with a local of its own. SHC then loads each
 * angle's address and value into R4 and R5 by turns (0x8c0198a2 to
 * 0x8c0198dc). a plain assignment keeps the address in R4 and puts the
 * value in R3 or R2, and 47 of 827 words differ */
#define SHORT_ANGLE(angle)                                                     \
    {                                                                          \
        Angle wide = (angle);                                                  \
        (angle) = (Sint16)wide;                                                \
    }

static void motion_follow(struct motion *motion, int index);
static void motion_enter(struct motion *motion);
void motion_blend_start(struct task_work *work, struct motion *motion);
static void motion_blend_make(struct task_work *work, struct motion *motion);
static void motion_blend_free(struct task_work *work, struct motion *motion);
extern Sint8 motion_flags;
extern struct task_work *boss_work;
extern Sint8 boss_last_mode;
extern Sint8 chaos_reqmode;
extern Sint8 boss_return_mode;
extern Sint32 boss_attack_checks;
extern Sint8 boss_repeats;
extern Sint8 boss_waiting;
extern Sint8 chaos_handed_over;
extern Uint8 dat_8c6c042b;
extern Sint8 chaos_current_form;
extern struct chaos *chaos_record;
extern struct chaos_form *chaos_params;
extern Float chaos_travel;
extern struct boss_point boss_points[32];
extern Uint32 dat_8c6c08bc;
extern NJS_MATRIX motion_weld_matrix_a;
extern NJS_MATRIX motion_weld_matrix_b;
extern NJS_MATRIX motion_weld_inverse_a;
extern NJS_MATRIX motion_weld_inverse_b;
extern NJS_MATRIX motion_pose_matrix;

struct motion *motion_create(struct task_work *work, int size)
{
    struct motion *motion = CAlloc(1, size);

    if (motion != NULL) {
        motion->state = MOTION_START;
        motion->weld_mode = PLAYER_WELD_MAKE;
    }
    work->flags |= 1;
    motion_flags = 0;
    return motion;
}

/* a change of entry blends from the playing action's pose into the new
 * action's first key, by the new entry's blend each step. a new entry whose
 * blend is 1, or whose action's object isn't the playing action's, is cut
 * to at once. once the blend ends, the new entry's mode plays its action */
void motion_step(struct task_work *work, struct motion *motion)
{
    NJS_ACTION *action;
    int index = motion->wanted;

    motion->previous = motion->current;
    if (motion->state != MOTION_FREE) {
        if (motion->current != motion->wanted &&
            motion->state != MOTION_BLENDING) {
            motion->state = MOTION_CHANGE;
            motion->steps = 0;
        } else {
            motion->steps++;
        }
    }
    switch (motion->state) {
    case MOTION_START:
        motion->frame = 0.0F;
        motion->current = index;
        motion->state = MOTION_CHANGE;
        motion->blend = MAlloc(sizeof(NJS_ACTION));
        motion->blend->object = motion->actions[index].action->object;
        motion->blend->motion = MAlloc(sizeof(NJS_MOTION));
        motion->blend->motion->nbFrame = BLEND_FRAMES;
        motion->blend->motion->type = BLEND_TYPE;
        motion->blend->motion->inp_fn = FACTORS;
        motion->blend->motion->mdata = CAlloc(BLEND_NODES, sizeof(NJS_MDATA3));
        motion_flags = 0;
        break;
    case MOTION_CHANGE:
        if (motion->actions[index].blend != 1.0F &&
            motion->actions[index].action->object ==
                motion->actions[motion->current].action->object) {
            motion_blend_start(work, motion);
            motion->frame = 0.0F;
        } else {
            motion->frame = 1.0F;
        }
        motion->current = index;
        motion->state = MOTION_BLENDING;
        /* fall through */
    case MOTION_BLENDING:
        motion->frame += motion->actions[index].blend;
        if (motion->frame < 1.0F) {
            break;
        }
        /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
        motion->state = motion->actions[index].mode;
        motion_blend_free(work, motion);
        motion_enter(motion);
        break;
    case MOTION_LOOP:
        action = motion->actions[index].action;
        motion->frame += motion->actions[index].speed;
        if (motion->frame >= (Float)action->motion->nbFrame) {
            motion->frame -= (Float)action->motion->nbFrame;
            motion_flags |= MOTION_ENDED;
        }
        break;
    case MOTION_PACED:
        action = motion->actions[index].action;
        motion->frame += motion->speed * motion->actions[index].speed;
        /* @hack spelling: the second test's 0 on the left, which loads the
         * frame into FR3 and the 0 into FR2 (0x8c0191da, 0x8c0191dc); written
         * motion->frame < 0.0F, the two trade and 6 of 445 words differ */
        if (motion->frame >= (Float)action->motion->nbFrame) {
            motion->frame -= (Float)action->motion->nbFrame;
        } else if (0.0F > motion->frame) {
            motion->frame += (Float)action->motion->nbFrame;
        }
        break;
    case MOTION_AT:
        action = motion->actions[index].action;
        motion->frame = motion->pace * (Float)action->motion->nbFrame;
        break;
    case MOTION_STEP:
        action = motion->actions[index].action;
        motion->frame += motion->pace;
        if (motion->frame >= (Float)action->motion->nbFrame - 1.0F) {
            motion_follow(motion, index);
        }
        break;
    case MOTION_ONCE:
        action = motion->actions[index].action;
        motion->frame += motion->actions[index].speed;
        if (motion->frame >= (Float)action->motion->nbFrame - 1.0F) {
            motion_follow(motion, index);
            motion_flags |= MOTION_ENDED;
        }
        break;
    case MOTION_HOLD:
        action = motion->actions[index].action;
        motion->frame += motion->actions[index].speed;
        if (motion->frame >= (Float)action->motion->nbFrame - 1.0F) {
            motion->frame = (Float)action->motion->nbFrame - 1.0F;
            if (motion_flags & MOTION_HOLDING) {
                motion_flags &= ~MOTION_HOLDING;
            } else {
                motion_flags |= MOTION_HOLDING;
            }
        }
        break;
    case MOTION_STILL:
        break;
    case MOTION_BACKWARD:
        motion->frame -= motion->actions[index].speed;
        if (motion->frame < 0.0F) {
            motion_follow(motion, index);
            motion_flags |= MOTION_ENDED;
        }
        break;
    case MOTION_FREE:
        motion_blend_free(work, motion);
        Free(motion->blend->motion->mdata);
        Free(motion->blend->motion);
        Free(motion->blend);
        motion->blend = NULL;
        break;
    }
}

/* go on to entry index's next entry, and start its action in its mode */
static void motion_follow(struct motion *motion, int index)
{
    motion->wanted = motion->actions[index].next;
    motion->current = motion->wanted;
    /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
    motion->state = motion->actions[motion->current].mode;
    motion_enter(motion);
}

/* an action starts at its first frame, or its last when it plays
 * backward */
static void motion_enter(struct motion *motion)
{
    int index = motion->wanted;
    NJS_ACTION *action;

    switch (motion->state) {
    case MOTION_BACKWARD:
        action = motion->actions[index].action;
        motion->frame = (Float)action->motion->nbFrame - 1.0F;
        break;
    default:
        motion->frame = 0.0F;
        break;
    }
}

/* make the blend from the playing entry into the entry asked for */
void motion_blend_start(struct task_work *work, struct motion *motion)
{
    NJS_MOTION *next;
    NJS_MOTION *prev;
    Uint16 next_factors;
    Uint16 prev_factors;
    Uint16 index = motion->wanted;
    Uint16 current = motion->current;

    next = motion->actions[index].action->motion;
    prev = motion->actions[current].action->motion;
    if (next->type & NJD_MTYPE_SCL_2) {
        next_factors = SCALED_FACTORS;
    } else {
        next_factors = FACTORS;
    }
    if (prev->type & NJD_MTYPE_SCL_2) {
        prev_factors = SCALED_FACTORS;
    } else {
        prev_factors = FACTORS;
    }
    /* @hack redundant: both branches of the test for scales call
     * motion_blend_make alike, but the image makes the test (CMP/EQ #3 at
     * 0x8c019470 and 0x8c019478); as one call, 41 of 41 words differ */
    if (next_factors == SCALED_FACTORS || prev_factors == SCALED_FACTORS) {
        motion_blend_make(work, motion);
    } else {
        motion_blend_make(work, motion);
    }
}

/* allocate two keys for each factor of each node in the blend. the first
 * key is the old action's value at the frame, between the keys either side
 * of it. past the old action's last key, it lies between the last and the
 * first. the second key is the new action's first. where one action has no
 * keys for a factor, its key takes the node's own value. the new action's
 * angles are the exception: with none, the node's angles overwrite the
 * first key instead. where neither action has keys for a factor, the blend
 * has none either */
static void motion_blend_make(struct task_work *work, struct motion *motion)
{
    NJS_OBJECT *nodes[TREE_NODES];
    NJS_OBJECT *object;
    NJS_OBJECT *node;
    NJS_MOTION *next;
    NJS_MOTION *prev;
    Uint16 next_factors;
    Uint16 prev_factors;
    NJS_MDATA2 *next_data;
    NJS_MDATA2 *prev_data;
    NJS_MDATA2 *blend_data;
    Uint32 i;
    Uint16 index = motion->wanted;
    Uint16 current = motion->current;

    object = motion->blend->object = motion->actions[index].action->object;
    tree_list_nodes(object, nodes);
    next = motion->actions[index].action->motion;
    prev = motion->actions[current].action->motion;
    if (next->type & NJD_MTYPE_SCL_2) {
        next_factors = SCALED_FACTORS;
    } else {
        next_factors = FACTORS;
    }
    if (prev->type & NJD_MTYPE_SCL_2) {
        prev_factors = SCALED_FACTORS;
    } else {
        prev_factors = FACTORS;
    }
    next_data = next->mdata;
    prev_data = prev->mdata;
    blend_data = motion->blend->motion->mdata;
    for (i = 0; i < motion->actions[index].nodes; i++) {
        node = nodes[i];
        if (next_data->p[0] != NULL || prev_data->p[0] != NULL) {
            NJS_MKEY_F *key = MAlloc(BLEND_KEYS * sizeof(NJS_MKEY_F));

            blend_data->p[0] = key;
            key->keyframe = 0;
            if (prev_data->p[0] != NULL) {
                NJS_MKEY_F *keys = prev_data->p[0];
                Uint32 nb = prev_data->nb[0];
                Uint32 start = 0;
                Uint32 end = 0;
                Uint32 span;
                Float along;

                while (motion->frame > (Float)keys[end].keyframe) {
                    if (end >= nb - 1) {
                        end = 0;
                        start = nb - 1;
                        break;
                    }
                    start = end;
                    end++;
                }
                key->key[0] = keys[start].key[0];
                key->key[1] = keys[start].key[1];
                key->key[2] = keys[start].key[2];
                if (end != start) {
                    span = keys[end].keyframe - keys[start].keyframe;
                    if (end < start) {
                        span += prev->nbFrame;
                    }
                    along = (motion->frame - (Float)keys[start].keyframe) /
                            (Float)span;
                    key->key[0] +=
                        (keys[end].key[0] - keys[start].key[0]) * along;
                    key->key[1] +=
                        (keys[end].key[1] - keys[start].key[1]) * along;
                    key->key[2] +=
                        (keys[end].key[2] - keys[start].key[2]) * along;
                }
            } else {
                key->key[0] = node->pos[0];
                key->key[1] = node->pos[1];
                key->key[2] = node->pos[2];
            }
            key[1].keyframe = 1;
            if (next_data->p[0] != NULL) {
                NJS_MKEY_F *keys = next_data->p[0];

                key[1].key[0] = keys->key[0];
                key[1].key[1] = keys->key[1];
                key[1].key[2] = keys->key[2];
            } else {
                key[1].key[0] = node->pos[0];
                key[1].key[1] = node->pos[1];
                key[1].key[2] = node->pos[2];
            }
            blend_data->nb[0] = BLEND_KEYS;
        } else {
            blend_data->p[0] = NULL;
            blend_data->nb[0] = 0;
        }
        if (next_data->p[1] != NULL || prev_data->p[1] != NULL) {
            NJS_MKEY_A *key = MAlloc(BLEND_KEYS * sizeof(NJS_MKEY_A));

            blend_data->p[1] = key;
            key->keyframe = 0;
            if (prev_data->p[1] != NULL) {
                NJS_MKEY_A *keys = prev_data->p[1];
                Uint32 nb = prev_data->nb[1];
                Uint32 start = 0;
                Uint32 end = 0;
                Uint32 span;
                Float along;

                while (motion->frame > (Float)keys[end].keyframe) {
                    if (end >= nb - 1) {
                        end = 0;
                        start = nb - 1;
                        break;
                    }
                    start = end;
                    end++;
                }
                key->key[0] = keys[start].key[0];
                key->key[1] = keys[start].key[1];
                key->key[2] = keys[start].key[2];
                if (end != start) {
                    span = keys[end].keyframe - keys[start].keyframe;
                    if (end < start) {
                        span += prev->nbFrame;
                    }
                    along = (motion->frame - (Float)keys[start].keyframe) /
                            (Float)span;
                    key->key[0] +=
                        (Angle)((Float)angle_difference(keys[start].key[0],
                                                        keys[end].key[0]) *
                                along);
                    key->key[1] +=
                        (Angle)((Float)angle_difference(keys[start].key[1],
                                                        keys[end].key[1]) *
                                along);
                    key->key[2] +=
                        (Angle)((Float)angle_difference(keys[start].key[2],
                                                        keys[end].key[2]) *
                                along);
                }
            } else {
                key->key[0] = node->ang[0];
                key->key[1] = node->ang[1];
                key->key[2] = node->ang[2];
            }
            key[1].keyframe = 1;
            if (next_data->p[1] != NULL) {
                NJS_MKEY_A *keys = next_data->p[1];

                key[1].key[0] = keys->key[0];
                key[1].key[1] = keys->key[1];
                key[1].key[2] = keys->key[2];
            } else {
                /* @bug logic: with no angle keys in the new action, the
                 * node's angles are stored through key, at R13, where they
                 * belong in key[1], at R13 + 16 (0x8c019898 to 0x8c0198a0).
                 * they overwrite the old action's angles in the first key,
                 * and the second key's angles keep what heap_alloc left
                 * there, which SHORT_ANGLE and angle_unwrap then read */
                key->key[0] = node->ang[0];
                key->key[1] = node->ang[1];
                key->key[2] = node->ang[2];
            }
            /* narrow both keys' angles to a half turn either way. angle_unwrap
             * then moves each of the second key's by whole turns, so the
             * blend turns the short way round from the first */
            SHORT_ANGLE(key->key[0]);
            SHORT_ANGLE(key->key[1]);
            SHORT_ANGLE(key->key[2]);
            SHORT_ANGLE(key[1].key[0]);
            SHORT_ANGLE(key[1].key[1]);
            SHORT_ANGLE(key[1].key[2]);
            key[1].key[0] = CreateNinjaAngle(key->key[0], key[1].key[0]);
            key[1].key[1] = CreateNinjaAngle(key->key[1], key[1].key[1]);
            key[1].key[2] = CreateNinjaAngle(key->key[2], key[1].key[2]);
            blend_data->nb[1] = BLEND_KEYS;
        } else {
            blend_data->p[1] = NULL;
            blend_data->nb[1] = 0;
        }
        if (prev_factors == SCALED_FACTORS || next_factors == SCALED_FACTORS) {
            NJS_MDATA3 *blend3;
            NJS_MDATA3 *next3;
            NJS_MDATA3 *prev3;

            next3 = (NJS_MDATA3 *)next_data;
            blend3 = (NJS_MDATA3 *)blend_data;
            prev3 = (NJS_MDATA3 *)prev_data;
            blend3->nb[1] = blend_data->nb[1];
            blend3->nb[0] = blend_data->nb[0];
            if ((next_factors == SCALED_FACTORS && next3->p[2] != NULL) ||
                (prev_factors == SCALED_FACTORS && prev3->p[2] != NULL)) {
                NJS_MKEY_F *key = MAlloc(BLEND_KEYS * sizeof(NJS_MKEY_F));

                blend3->p[2] = key;
                key->keyframe = 0;
                if (prev_factors == SCALED_FACTORS && prev3->p[2] != NULL) {
                    /* @hack spelling: start declared before nb, which has end
                     * copy its 0 from start's R6 (MOV R6,R5 at 0x8c0199b0);
                     * declared after nb, end copies it from R14 and 1 of 827
                     * words differs */
                    NJS_MKEY_F *keys = prev3->p[2];
                    Uint32 start = 0;
                    Uint32 nb = prev3->nb[2];
                    Uint32 end = 0;
                    Uint32 span;
                    Float along;

                    while (motion->frame > (Float)keys[end].keyframe) {
                        if (end >= nb - 1) {
                            end = 0;
                            start = nb - 1;
                            break;
                        }
                        start = end;
                        end++;
                    }
                    key->key[0] = keys[start].key[0];
                    key->key[1] = keys[start].key[1];
                    key->key[2] = keys[start].key[2];
                    if (end != start) {
                        span = keys[end].keyframe - keys[start].keyframe;
                        if (end < start) {
                            span += prev->nbFrame;
                        }
                        along = (motion->frame - (Float)keys[start].keyframe) /
                                (Float)span;
                        key->key[0] +=
                            (keys[end].key[0] - keys[start].key[0]) * along;
                        key->key[1] +=
                            (keys[end].key[1] - keys[start].key[1]) * along;
                        key->key[2] +=
                            (keys[end].key[2] - keys[start].key[2]) * along;
                    }
                } else {
                    key->key[0] = node->scl[0];
                    key->key[1] = node->scl[1];
                    key->key[2] = node->scl[2];
                }
                key[1].keyframe = 1;
                if (next_factors == SCALED_FACTORS && next3->p[2] != NULL) {
                    NJS_MKEY_F *keys = next3->p[2];

                    key[1].key[0] = keys->key[0];
                    key[1].key[1] = keys->key[1];
                    key[1].key[2] = keys->key[2];
                } else {
                    key[1].key[0] = node->scl[0];
                    key[1].key[1] = node->scl[1];
                    key[1].key[2] = node->scl[2];
                }
                blend3->nb[2] = BLEND_KEYS;
            } else {
                blend3->p[2] = NULL;
                blend3->nb[2] = 0;
            }
        }
        if (next_factors == SCALED_FACTORS || prev_factors == SCALED_FACTORS) {
            blend_data = (NJS_MDATA2 *)((NJS_MDATA3 *)blend_data + 1);
        } else {
            blend_data++;
        }
        if (next_factors == SCALED_FACTORS) {
            next_data = (NJS_MDATA2 *)((NJS_MDATA3 *)next_data + 1);
        } else {
            next_data++;
        }
        if (prev_factors == SCALED_FACTORS) {
            prev_data = (NJS_MDATA2 *)((NJS_MDATA3 *)prev_data + 1);
        } else {
            prev_data++;
        }
    }
    if (next_factors == SCALED_FACTORS || prev_factors == SCALED_FACTORS) {
        motion->blend->motion->type = BLEND_SCALED_TYPE;
        motion->blend->motion->inp_fn = SCALED_FACTORS;
    } else {
        motion->blend->motion->type = BLEND_TYPE;
        motion->blend->motion->inp_fn = FACTORS;
    }
}

/* free each key array in the blend, and set its pointer and its count to
 * 0. an NJS_MDATA2 or NJS_MDATA3 entry holds a key pointer for each factor,
 * p[], then a count for each, nb[]. data walks the entries a word at a time,
 * and finds a factor's count factors words past its keys */
static void motion_blend_free(struct task_work *work, struct motion *motion)
{
    NJS_ACTION *blend_action[1];
    NJS_MOTION *blend = (blend_action[0] = motion->blend)->motion;
    void **data = (void **)blend->mdata;
    Uint16 factors = blend->inp_fn;
    int i;

    for (i = motion->actions[motion->wanted].nodes; i > 0; i--) {
        if (*data != NULL) {
            Free(*data);
            *data = NULL;
            data[factors] = NULL;
        }
        data++;
        if (*data != NULL) {
            Free(*data);
            *data = NULL;
            data[factors] = NULL;
        }
        data++;
        if (factors == SCALED_FACTORS) {
            if (*data != NULL) {
                Free(*data);
                *data = NULL;
                data[factors] = NULL;
            }
        }
        if (factors == SCALED_FACTORS) {
            data += 4;
        } else {
            data += 2;
        }
    }
}

/* PLAYER_WELDING puts one side of each weld on the posed object back to
 * its copies. it then carries those through the two nodes' matrices onto
 * the other side's vertices */
void motion_weld(struct task_work *work, struct motion *motion)
{
    struct weld *weld = motion->welds;
    NJS_MODEL *model_a;
    NJS_MODEL *model_b;
    NJS_POINT3 *vertex;
    NJS_POINT3 *points_a;
    NJS_POINT3 *points_b;
    NJS_VECTOR *normals_a;
    NJS_VECTOR *normals_b;
    Sint32 i;
    int index_a;
    int index_b;
    /* @hack redundant: 24 bytes of frame that no code reads, of a type unknown,
     * declared as a Uint32[6]. the image's ADD #-96,R15 reserves them
     * (0x8c019cb0); without them, 2 of 543 words differ */
    Uint32 unused[6];

    switch (motion->weld_mode) {
    case PLAYER_WELD_MAKE:
        motion->weld_mode = PLAYER_WELDING;
        if (weld == NULL) {
            return;
        }
        for (; weld->base != NULL; weld++) {
            weld->vertices = MAlloc(weld->count * (4 * sizeof(NJS_POINT3)));
            vertex = weld->vertices;
            model_a = weld->object_a->model;
            model_b = weld->object_b->model;
            for (i = 0; i < weld->count; i++) {
                *vertex++ = model_a->points[weld->indices[i * 2]];
                *vertex++ = model_a->normals[weld->indices[i * 2]];
                *vertex++ = model_b->points[weld->indices[(i * 2) + 1]];
                *vertex++ = model_b->normals[weld->indices[(i * 2) + 1]];
            }
            weld->node_a = tree_node_index(weld->base, weld->object_a);
            weld->node_b = tree_node_index(weld->base, weld->object_b);
        }
        break;
    case PLAYER_WELDING:
        if (motion->state == MOTION_BLENDING) {
            CalcMMMatrix(&nj_unit_matrix_, motion->blend, motion->frame,
                         motion->actions[motion->wanted].nodes,
                         &motion_pose_matrix);
        } else {
            CalcMMMatrix(&nj_unit_matrix_,
                         motion->actions[motion->wanted].action, motion->frame,
                         motion->actions[motion->wanted].nodes,
                         &motion_pose_matrix);
        }
        if (weld == NULL) {
            return;
        }
        for (; weld->base != NULL; weld++) {
            if (weld->base == motion->actions[motion->wanted].action->object) {
                GetMMMatrix(weld->node_a, &motion_weld_matrix_a);
                GetMMMatrix(weld->node_b, &motion_weld_matrix_b);
                points_a = weld->object_a->model->points;
                normals_a = weld->object_a->model->normals;
                points_b = weld->object_b->model->points;
                normals_b = weld->object_b->model->normals;
                njSetMatrix(&motion_weld_inverse_a, &motion_weld_matrix_a);
                njSetMatrix(&motion_weld_inverse_b, &motion_weld_matrix_b);
                njInvertMatrix(&motion_weld_inverse_a);
                njInvertMatrix(&motion_weld_inverse_b);
                /* WELD_BOTH takes WELD_TO_A's code: b's vertices follow a's */
                switch (weld->kind) {
                case WELD_BOTH:
                case WELD_TO_A:
                    njPushMatrix(&motion_weld_inverse_b);
                    njMultiMatrix(NULL, &motion_weld_matrix_a);
                    for (i = 0; i < weld->count; i++) {
                        index_a = weld->indices[i * 2];
                        index_b = weld->indices[(i * 2) + 1];
                        points_a[index_a] = weld->vertices[i * 4];
                        njCalcPoint(NULL, &points_a[index_a],
                                    &points_b[index_b]);
                        normals_a[index_a] = weld->vertices[(i * 4) + 1];
                        njCalcVector(NULL, &normals_a[index_a],
                                     &normals_b[index_b]);
                    }
                    late_DrawObjectClipEx(1);
                    break;
                case WELD_TO_B:
                    njPushMatrix(&motion_weld_inverse_a);
                    njMultiMatrix(NULL, &motion_weld_matrix_b);
                    for (i = 0; i < weld->count; i++) {
                        index_a = weld->indices[i * 2];
                        index_b = weld->indices[(i * 2) + 1];
                        points_b[index_b] = weld->vertices[(i * 4) + 2];
                        njCalcPoint(NULL, &points_b[index_b],
                                    &points_a[index_a]);
                        normals_b[index_b] = weld->vertices[(i * 4) + 3];
                        njCalcVector(NULL, &normals_b[index_b],
                                     &normals_a[index_a]);
                    }
                    late_DrawObjectClipEx(1);
                    break;
                }
            }
        }
        break;
    case PLAYER_WELD_FREE:
    default:
        for (; weld->base != NULL; weld++) {
            vertex = weld->vertices;
            model_a = weld->object_a->model;
            model_b = weld->object_b->model;
            for (i = 0; i < weld->count; i++) {
                model_a->points[weld->indices[i * 2]] = *vertex++;
                model_a->normals[weld->indices[i * 2]] = *vertex++;
                model_b->points[weld->indices[(i * 2) + 1]] = *vertex++;
                model_b->normals[weld->indices[(i * 2) + 1]] = *vertex++;
            }
            Free(weld->vertices);
        }
        break;
    }
}
