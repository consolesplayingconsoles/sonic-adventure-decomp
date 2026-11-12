/* @unit 0CB854C0-0CB856E0 +egflags +pool32 */
/* EV0034.PRS's scorched Egg Mobile: Eggman in his craft, with a scorched
 * face. the craft loops its one action and bobs where it stands. its welds
 * close Eggman's elbows and fingers, as shared/eggmobile.c's do */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "draw/model.h"
#include "draw/motion.h"
#include "ev0034/scorched.h"
#include "ev0034/scorched_textures.h"
#include "event/event.h"
#include "player/player.h"
#include "shared/motion.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern Sint8 chaos_reqmode;
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ExecEventPath(struct task_work *work);
void ExecEventFace(struct task_work *work);
struct task *CreateEventObject(void);
void EventObject(struct task *task);
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

#define BOB_SPEED 0x200 /* the angle the bob's phase turns a step */
#define BOB_HEIGHT 1.5F /* the most the bob lifts or lowers the craft */
#define VARS(work) ((struct scorched_vars *)&(work)->vars)
extern NJS_ACTION ev0034_scorched_action;
extern NJS_OBJECT ev0034_scorched_object;
extern NJS_OBJECT ev0034_scorched_upper_arm_plus_z;
extern NJS_OBJECT ev0034_scorched_forearm_plus_z;
extern NJS_OBJECT ev0034_scorched_hand_plus_z;
extern NJS_OBJECT ev0034_scorched_fingers_plus_z;
extern NJS_OBJECT ev0034_scorched_upper_arm_minus_z;
extern NJS_OBJECT ev0034_scorched_forearm_minus_z;
extern NJS_OBJECT ev0034_scorched_hand_minus_z;
extern NJS_OBJECT ev0034_scorched_fingers_minus_z;

/* the craft's view of work->vars. its event motion takes the last var, as
 * EVENT_MOTION reads it */
struct scorched_vars {
    Float bob; /* how far above work->pos the craft is drawn */
    Angle bob_phase;
};
extern struct motion_entry scorched_actions[2];
extern Uint16 scorched_elbow_vertices[10];
extern Uint16 scorched_finger_vertices[8];
extern struct weld scorched_welds[5];

void scorched_destroy(struct task *task)
{
    event_motion_free(task->work);
}

void scorched_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct event_motion_control *motion;
    int index;
    Angle ang;

    /* @hack spelling: the motion through task, a struct task *. SHC loads it
     * into task's R4 and copies it to R13 (MOV.L @(16,R14),R4 and MOV R4,R13
     * at 0x0cb84ef2). read straight into motion, scorched_draw runs 4 bytes
     * short, and 97 of its 103 words differ */
    task = EVENT_MOTION(work);
    motion = (struct event_motion_control *)task;
    index = motion->action;
    if (motion->state == EVENT_MOTION_BLENDING) {
        index = motion->current;
    }
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y + VARS(work)->bob, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    if (work->event->motions != NULL) {
        event_actor_draw(work);
    } else {
        draw_set_palette(DRAW_PLAYER_PALETTE);
        njSetTexture_jp(&ev0034_scorched_texlist);
        if (motion->state != EVENT_MOTION_BLENDING) {
            ds_ActionClip(motion->actions[index].action, motion->frame);
        } else {
            ds_ActionClip(motion->blend, motion->frame);
        }
        draw_set_palette(0);
    }
    late_DrawObjectClipEx(1);
}

void scorched_step(struct task *task)
{
    struct task_work *work = task->work;
    struct event_motion_control *motion = EVENT_MOTION(work);

    event_motion_step(motion);
    event_motion_weld(work, motion);
    VARS(work)->bob_phase += BOB_SPEED;
    VARS(work)->bob = njSin(VARS(work)->bob_phase) * BOB_HEIGHT;
    scorched_draw(task);
}

void scorched_init(struct task *task)
{
    struct task_work *work = task->work;
    struct event_motion_control *motion;

    VARS(work)->bob = 0.0F;
    VARS(work)->bob_phase = 0;
    event_motion_alloc(work);
    motion = EVENT_MOTION(work);
    motion->actions = scorched_actions;
    motion->welds = scorched_welds;
    motion->action = 0;
    task->step = scorched_step;
    task->draw = scorched_draw;
    task->destructor = scorched_destroy;
}

struct task *ev0034_scorched_create(void)
{
    struct task *task = CreateElementalTask(TASK_WORK, 3, scorched_init);

    if (task != NULL) {
        SetEventWork(task->work);
    }
    return task;
}
