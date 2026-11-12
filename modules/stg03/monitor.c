/* @unit 0C905A40-0C905DC0 @data 0C9F78CC-0C9F7918 +egflags +pool32 */
/* O MONITOR screen with a scrolling picture, under a rocking speaker */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "object/common.h"
#include "object/placement.h"
#include "stg03/monitor.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
float njArcTan2(float y, float x);
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
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
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
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Uint16 GetStageNumber(void);
Bool ChkPause(void);
extern Uint8 seqVars[512];
extern Sint8 evExecFlag[512];
extern int evfade;
void SeqCtrl(void);
void story_save_wait(void);
void main(void);
void SeqEndSection(void);
void SeqEvent(int event);
void SeqSetFlag(int flag);
Bool SeqCheckFlag(int flag);
Bool SeqCheckStage(int stage, int act);
void SeqChangeStage(int stage, int act);
Bool SeqCheckNextStage(Uint8 stage, Uint8 act);
Bool SeqCheckClearAction(int stage);
extern struct save SaveData[3];
extern struct AdvertiseWork AdvertiseWork;
Bool thunk_FUN_8c081ba6(void);
struct task *thunk_FUN_8c081bec(void);
struct task *thunk_FUN_8c08395e(struct battle *battle);
struct task *thunk_FUN_8c083ebc(struct battle *battle);
void thunk_FUN_8c083f7e(struct battle *battle);
Sint16 thunk_FUN_8c0829cc(int frames);
Sint16 thunk_FUN_8c082b9a(int unused);
void ObjectMovableSRegularExecute(struct task *task);
void ObjectMovableMRegularExecute(struct task *task);
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
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

/* the monitor, whose child is the speaker */
#define MONITOR_RANGE (1010.0F * 1010.0F)
#define MONITOR_REACH 20.0F
#define SPEAKER_SWING NJM_DEG_ANG(10)
#define SCROLL_END 512
#define SCREEN_MESHSET 5
#define SCREEN_CORNERS 4
#define VARS(work) ((struct monitor_vars *)&(work)->vars)
#define SCROLL_SPEED(work) ((work)->tick)
#define SCROLL(work) TASK_TIMER(work)
extern NJS_OBJECT monitor_object;

/* the monitor's range for placement_try_leave_by, squared */
/* how far the monitor's collision record reaches from its position */

/* the speaker reverses once its turn passes SPEAKER_SWING either way */
/* the picture's scroll returns to 0 once it passes SCROLL_END */
/* the screen's meshset in the monitor's model, and its count of uvs */

struct monitor_vars {
    NJS_OBJECT *object;
    Angle rate; /* the speaker's turn a step */
    Angle turn; /* the speaker's turn about x */
};

/* the picture's scroll a step, and its scroll so far */

enum monitor_mode { MONITOR_INIT, MONITOR_RUN };
/* the speaker's rocking direction, in work->submode */
enum speaker_way { SPEAKER_UP, SPEAKER_DOWN };
extern struct collision_shape monitor_shape;

void dispTPMonitor(struct task *task)
{
    FreeTask(task);
}

/* on a frame's first step, draw the monitor, then the speaker turned about x */
void monitor_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object = VARS(work)->object;
    Angle ang;

    if (loop_count == 0) {
        SetObjectTexture();
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateY, work->ang.y, ang);
        njTranslateV(NULL, (NJS_VECTOR *)object->pos);
        ds_DrawModelClip(object->model);
        njPushMatrix(NULL);
        object = object->child;
        njTranslateV(NULL, (NJS_VECTOR *)object->pos);
        TURN_VIA(njRotateX, VARS(work)->turn, ang);
        ds_DrawModelClip(object->model);
        late_DrawObjectClipEx(1);
        late_DrawObjectClipEx(1);
    }
}

/* rock the speaker, scroll the picture, and draw the monitor. every monitor
 * draws monitor_object, so the screen's uvs take the scroll only for the
 * draw */
void execTPMonitor(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack type: i a Uint16, which zero-extends it for each loop's test
     * (EXTU.W at 0x0c905db6 and 0x0c905df6); as an int, the tests move into
     * the bodies, the function runs 4 bytes shorter and 44 of 113 words
     * differ */
    Uint16 i;

    switch (work->submode) {
    case SPEAKER_UP:
        VARS(work)->turn += VARS(work)->rate;
        if (VARS(work)->turn > SPEAKER_SWING) {
            work->submode = SPEAKER_DOWN;
        }
        break;
    case SPEAKER_DOWN:
        VARS(work)->turn -= VARS(work)->rate;
        if (VARS(work)->turn < -SPEAKER_SWING) {
            work->submode = SPEAKER_UP;
        }
        break;
    }
    /* @hack spelling: the add inside the test, which tests the sum still in R0
     * (EXTU.W R0,R0 at 0x0c905d76); as a statement of its own, the test reads
     * the scroll again, the function runs 2 bytes longer and 73 of 113 words
     * differ */
    if ((SCROLL(work) += SCROLL_SPEED(work)) > SCROLL_END) {
        SCROLL(work) = 0;
    }
    for (i = 0; i < SCREEN_CORNERS; i++) {
        VARS(work)->object->model->meshsets[SCREEN_MESHSET].vertuv[i].tex.v -=
            SCROLL(work);
    }
    monitor_draw(task);
    for (i = 0; i < SCREEN_CORNERS; i++) {
        VARS(work)->object->model->meshsets[SCREEN_MESHSET].vertuv[i].tex.v +=
            SCROLL(work);
    }
}

/* in the set editor, the monitor animates but takes no collision record.
 * while the editor holds it, the step labels the set entry's fields */
void ObjectTPMonitor(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOutWithR(task, MONITOR_RANGE)) {
        return;
    }
    if (edit_mode) {
        VARS(work)->object = &monitor_object;
        SCROLL_SPEED(work) = (Uint8)njFloor(work->scl.x);
        VARS(work)->rate = (Angle)(work->scl.y * ANGLE_PER_DEGREE);
        execTPMonitor(task);
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_X), ">");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "> ROTATION");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Z), ">");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "> TEX SCROLL SPEED");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "> SPEAKER ROT RATE");
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "> INIT SPEAKER ROT");
        }
    } else {
        switch (work->mode) {
        case MONITOR_INIT:
            work->mode = MONITOR_RUN;
            SCROLL_SPEED(work) = (Uint8)njFloor(work->scl.x);
            VARS(work)->rate = (Angle)(work->scl.y * ANGLE_PER_DEGREE);
            VARS(work)->turn = (Angle)(work->scl.z * ANGLE_PER_DEGREE);
            VARS(work)->object = &monitor_object;
            task->destructor = dispTPMonitor;
            task->draw = monitor_draw;
            CCL_Init(task, &monitor_shape, COLLISION_OBJECT, 1, 1);
            work->collision->radius = MONITOR_REACH;
            break;
        case MONITOR_RUN:
            execTPMonitor(task);
            EntryColliList(work);
            ObjectSetupInput(work, NULL);
            break;
        }
    }
}
