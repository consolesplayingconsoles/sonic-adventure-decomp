/* @unit 8C057B00-8C0583E0 +egflags +pool32 */
/* poses: a model tree at one frame of a motion, and the matrix of each node */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
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

#define POSE_NODES 128

/* the factors of a node's motion data, in order, and the most it can have,
 * as in NJS_MDATA5 */
#define FACTOR_POS 0
#define FACTOR_ANG 1
#define FACTOR_SCL 2
#define FACTORS_MAX 5

/* a walk of a model tree through a motion */
struct pose_walk {
    void *mdata; /* the next node's motion data */
    NJS_MATRIX *matrix; /* where the next node's matrix goes */
    Uint32 type;
    Uint32 frames; /* the motion's nbFrame */
    Float frame;
};
extern NJS_POINT3 axis_points[6];
extern NJS_BGRA axis_colors[6];
extern NJS_POINT3COL axes[1];
extern NJS_MATRIX pose_matrices[128];
extern Uint32 pose_count;
extern Uint32 pose_limit;

/* pose object at the walk's frame, keep its matrix, and pose the nodes
 * under it, then return its sibling. when the walk has kept pose_limit
 * nodes already, it poses nothing and returns null. a node's motion data
 * holds a factor for each bit of the type up to its highest. a factor
 * without keys takes the node's own value */
static NJS_OBJECT *pose_node(NJS_OBJECT *object, struct pose_walk *walk)
{
    Uint32 type;
    Uint32 bit;
    int factors;
    Uint32 frame;
    Float rate;
    NJS_MKEY_F *key;
    NJS_MKEY_F *next;
    Float *kpos;
    Float *npos;
    Angle *kang;
    Angle *nang;
    Float px;
    Float py;
    Float pz;
    Angle x;
    Angle y;
    Angle z;
    Angle dx;
    Angle dy;
    Angle dz;
    Angle ax;
    Angle ay;
    Angle az;
    NJS_OBJECT *child;

    if (++pose_count > pose_limit) {
        pose_count = pose_limit;
        return NULL;
    }
    type = walk->type;
    factors = 0;
    bit = 1;
    while (factors < FACTORS_MAX && type != 0) {
        factors++;
        type &= ~bit;
        bit <<= 1;
    }
    njPushMatrix(NULL);
    /* @hack spelling: a counter declared in each case, which SHC keeps in R9
     * with njRotateXYZ in R11 (MOV #0,R9 at 0x8c05ac54, MOV.L at 0x8c05ac3c);
     * declared once for the function, 389 of 582 words differ */
    switch (factors) {
    case 2: {
        NJS_MDATA2 *mdata;
        int i;

        mdata = walk->mdata;
        for (i = 0; i < 2; i++) {
            if (mdata->p[i] == NULL) {
                switch (i) {
                case FACTOR_POS:
                    njTranslateV(NULL, (NJS_VECTOR *)object->pos);
                    break;
                case FACTOR_ANG:
                    if (!(object->evalflags & NJD_EVAL_UNIT_ANG)) {
                        njRotateXYZ(NULL, object->ang[0], object->ang[1],
                                    object->ang[2]);
                    }
                    break;
                }
                continue;
            }
            /* find the keys either side of the frame. a key on the motion's
             * last frame, nbFrame - 1, runs on to its first key over one
             * frame */
            frame = walk->frame;
            key = mdata->p[i];
            next = key + 1;
            while (frame > key->keyframe && frame >= next->keyframe) {
                key++;
                next++;
            }
            if (key->keyframe == walk->frames - 1) {
                next = mdata->p[i];
                rate = walk->frame - key->keyframe;
            } else {
                rate = (walk->frame - key->keyframe) /
                       (Float)(next->keyframe - key->keyframe);
            }
            switch (i) {
            case FACTOR_POS:
                kpos = key->key;
                npos = next->key;
                px = *kpos + ((*npos - *kpos) * rate);
                kpos++;
                npos++;
                py = *kpos + ((*npos - *kpos) * rate);
                kpos++;
                npos++;
                pz = *kpos + ((*npos - *kpos) * rate);
                njTranslate(NULL, px, py, pz);
                break;
            case FACTOR_ANG:
                kang = ((NJS_MKEY_A *)key)->key;
                nang = ((NJS_MKEY_A *)next)->key;
                x = *kang++;
                y = *kang++;
                z = *kang;
                dx = angle_difference(x, *nang++);
                dy = angle_difference(y, *nang++);
                dz = angle_difference(z, *nang);
                /* @hack redundant: a read through y as a pointer, which SHC
                 * drops, but which keeps x, y and z at sp+8, sp+4 and sp+12
                 * (0x8c05adb6 to 0x8c05adbe); without it, 6 of 582 words
                 * differ */
                (void)((NJS_MKEY_A *)y)->keyframe;
                ax = x + (Angle)(dx * rate);
                ay = y + (Angle)(dy * rate);
                az = z + (Angle)(dz * rate);
                njRotateXYZ(NULL, ax, ay, az);
                break;
            }
        }
        if (!(object->evalflags & NJD_EVAL_UNIT_SCL)) {
            njScaleV(NULL, (NJS_VECTOR *)object->scl);
        }
        walk->mdata = mdata + 1;
        break;
    }
    case 3: {
        NJS_MDATA3 *mdata;
        int i;

        mdata = walk->mdata;
        for (i = 0; i < 3; i++) {
            if (mdata->p[i] == NULL) {
                switch (i) {
                case FACTOR_POS:
                    if (!(object->evalflags & NJD_EVAL_UNIT_POS)) {
                        njTranslateV(NULL, (NJS_VECTOR *)object->pos);
                    }
                    break;
                case FACTOR_ANG:
                    if (!(object->evalflags & NJD_EVAL_UNIT_ANG)) {
                        njRotateXYZ(NULL, object->ang[0], object->ang[1],
                                    object->ang[2]);
                    }
                    break;
                case FACTOR_SCL:
                    if (!(object->evalflags & NJD_EVAL_UNIT_SCL)) {
                        njScaleV(NULL, (NJS_VECTOR *)object->scl);
                    }
                    break;
                }
                continue;
            }
            frame = walk->frame;
            key = mdata->p[i];
            next = key + 1;
            while (frame > key->keyframe && frame >= next->keyframe) {
                key++;
                next++;
            }
            if (key->keyframe == walk->frames - 1) {
                next = mdata->p[i];
                rate = walk->frame - key->keyframe;
            } else {
                rate = (walk->frame - key->keyframe) /
                       (Float)(next->keyframe - key->keyframe);
            }
            switch (i) {
            case FACTOR_POS:
                kpos = key->key;
                npos = next->key;
                px = *kpos + ((*npos - *kpos) * rate);
                kpos++;
                npos++;
                py = *kpos + ((*npos - *kpos) * rate);
                kpos++;
                npos++;
                pz = *kpos + ((*npos - *kpos) * rate);
                njTranslate(NULL, px, py, pz);
                break;
            case FACTOR_ANG:
                kang = ((NJS_MKEY_A *)key)->key;
                nang = ((NJS_MKEY_A *)next)->key;
                x = *kang++;
                y = *kang++;
                z = *kang;
                dx = angle_difference(x, *nang++);
                dy = angle_difference(y, *nang++);
                dz = angle_difference(z, *nang);
                /* @hack redundant: the same read, which keeps x, y and z at
                 * sp+8, sp+4 and sp+12 in this case too (0x8c05b00a to
                 * 0x8c05b012); without it, 15 of 582 words differ */
                (void)((NJS_MKEY_A *)y)->keyframe;
                ax = x + (Angle)(dx * rate);
                ay = y + (Angle)(dy * rate);
                az = z + (Angle)(dz * rate);
                njRotateXYZ(NULL, ax, ay, az);
                break;
            case FACTOR_SCL:
                kpos = key->key;
                npos = next->key;
                px = *kpos + ((*npos - *kpos) * rate);
                kpos++;
                npos++;
                py = *kpos + ((*npos - *kpos) * rate);
                kpos++;
                npos++;
                pz = *kpos + ((*npos - *kpos) * rate);
                njScale(NULL, px, py, pz);
                break;
            }
        }
        mdata++;
        walk->mdata = mdata;
        break;
    }
    default:
        /* a motion with other than two or three factors hangs the game */
        for (;;) {
        }
    }
    njGetMatrix(walk->matrix);
    walk->matrix++;
    child = object->child;
    while (child != NULL) {
        child = pose_node(child, walk);
    }
    late_DrawObjectClipEx(1);
    return object->sibling;
}

void pose_draw_player(struct task_work *work, struct player *player,
                      struct player_action *actions)
{
    struct pose_walk walk;
    Uint32 i;
    NJS_MATRIX *matrix;

    pose_count = 0;
    pose_limit = POSE_NODES;
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->collision->shapes->center);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, NJM_DEG_ANG(180) - work->ang.y);
    walk.mdata = actions[player->anim.action].action->motion->mdata;
    walk.matrix = pose_matrices;
    walk.type = actions[player->anim.action].action->motion->type;
    walk.frames = actions[player->anim.action].action->motion->nbFrame;
    walk.frame = player->anim.frame;
    pose_node(actions[player->anim.action].action->object, &walk);
    late_DrawObjectClipEx(1);
    for (i = 0, matrix = pose_matrices; i < pose_count && i < POSE_NODES;
         i++, matrix++) {
        njPushMatrix(NULL);
        njSetMatrix(NULL, matrix);
        njDrawLine3D(axes, 3, NJD_DRAW_NORMAL);
        late_DrawObjectClipEx(1);
    }
}

Bool pose_draw_player_node(struct task_work *work, struct player *player,
                           struct player_action *actions, Uint32 node)
{
    struct pose_walk walk;

    pose_count = 0;
    /* @hack spelling: pose_limit assigned in the test, which loads POSE_NODES
     * into R4 and pose_limit's address into R5 (0x8c05b292, 0x8c05b294);
     * assigned first, the two trade and 14 of 134 words differ */
    if ((pose_limit = node + 1) > POSE_NODES) {
        pose_limit = POSE_NODES;
    }
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->collision->shapes->center);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, NJM_DEG_ANG(180) - work->ang.y);
    walk.mdata = actions[player->anim.action].action->motion->mdata;
    walk.matrix = pose_matrices;
    walk.type = actions[player->anim.action].action->motion->type;
    walk.frames = actions[player->anim.action].action->motion->nbFrame;
    walk.frame = player->anim.frame;
    pose_node(actions[player->anim.action].action->object, &walk);
    late_DrawObjectClipEx(1);
    njPushMatrix(NULL);
    njSetMatrix(NULL, &pose_matrices[node]);
    njDrawLine3D(axes, 3, NJD_DRAW_NORMAL);
    late_DrawObjectClipEx(1);
    return TRUE;
}

Bool CalcMMMatrix(NJS_MATRIX *base, NJS_ACTION *action, Float frame,
                  Uint32 node, NJS_MATRIX *out)
{
    struct pose_walk walk;

    pose_count = 0;
    /* @hack spelling: pose_limit assigned in the test, which loads POSE_NODES
     * into R4 and pose_limit's address into R5 (0x8c05b3f2, 0x8c05b3ee);
     * assigned first, the two trade and 16 of 70 words differ */
    if ((pose_limit = node + 1) > POSE_NODES) {
        pose_limit = POSE_NODES;
    }
    njPushMatrix(NULL);
    if (base != NULL) {
        njSetMatrix(NULL, base);
    }
    walk.mdata = action->motion->mdata;
    walk.matrix = pose_matrices;
    walk.type = action->motion->type;
    walk.frames = action->motion->nbFrame;
    walk.frame = frame;
    pose_node(action->object, &walk);
    if (out != NULL) {
        njSetMatrix(out, &pose_matrices[node]);
    }
    late_DrawObjectClipEx(1);
    return TRUE;
}

Uint32 pose_get_count(void)
{
    return pose_count;
}

Bool GetMMMatrix(Uint32 node, NJS_MATRIX *out)
{
    if (node >= pose_count) {
        return FALSE;
    }
    njSetMatrix(out, &pose_matrices[node]);
    return TRUE;
}
