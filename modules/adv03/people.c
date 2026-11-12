/* @unit 0C9049A0-0C904F20 +r04 +egflags +pool32 +poolafter=pastpc_init,pastpc_exec */
/* the past's people: Tikal, Pachacamac, Chao and echidnas. past_people_place
 * places those whose rows' scripts pass, and each plays its action round and
 * round */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv03/people.h"
#include "adv03/shadow.h"
#include "camera/camera.h"
#include "collision/collision.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "event/play.h"
#include "event/script.h"
#include "object/common.h"
#include "player/player.h"
#include "player/talk.h"
#include "progress/progress.h"
#include "stage/stage.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
#include "tikal_prog/tikal.h"
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
void FUN_8c60d138(void (*func)(NJS_OBJECT *obj));
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
void HintRegistStatusPointer(Uint8 *manager_data);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
void EV_Load2(int number);
void EV_Exec2(void);
Bool EV_CheckExec(int number);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z, Angle ang_x,
                     Angle ang_y, Angle ang_z);
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
void ObjectSetupInput(struct task_work *work, struct task_motion *motion);
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
struct task *InputHookInit(void);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
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

/* Pachacamac's, the Chao's and the echidnas' texture lists, which past_pvms
 * loads with the stage */
#define PEOPLE_MAX 12
#define NO_CHARACTER (-1)
#define NO_CHARACTER_CHAO (-2)
#define TALK_REACH 20.0F
#define VIEW_RADIUS 15.0F
#define PERSON(task) ((struct person_work *)(task)->work)
#define PERSON_SHAPE                                                           \
    {SHAPE_CAPSULE | SHAPE_NO_PUSH | SHAPE_UNTURNED,                           \
     0,                                                                        \
     PUSH_PLAYERS | PUSH_OBJECTS | PUSH_FIRM(PUSH_PLAYERS),                    \
     {0.0F, 7.0F, 0.0F},                                                       \
     4.0F,                                                                     \
     5.0F,                                                                     \
     0.0F,                                                                     \
     {0},                                                                      \
     0,                                                                        \
     NULL}
#define CHAO_SHAPE                                                             \
    {SHAPE_SPHERE | SHAPE_NO_PUSH | SHAPE_UNTURNED,                            \
     0,                                                                        \
     PUSH_PLAYERS | PUSH_OBJECTS | PUSH_FIRM(PUSH_PLAYERS),                    \
     {0.0F, 1.6F, 0.0F},                                                       \
     2.0F,                                                                     \
     0.0F,                                                                     \
     0.0F,                                                                     \
     {0},                                                                      \
     0,                                                                        \
     NULL}
extern NJS_TEXLIST k_patya_texlist;
extern NJS_TEXLIST ev_alife_texlist;
extern NJS_TEXLIST past_kn_fam_texlist;
/* the kinds' actions. dat_0cb2d478 lies in TIKAL_PROG.PRS, as does
 * tikal_texlist, which both Tikal kinds draw with. TIKAL_PROG.PRS must stay
 * loaded while a person of either kind draws */
extern NJS_ACTION patya_action;
extern NJS_ACTION dat_0c9e9ab8;
extern NJS_ACTION dat_0c9eaabc;
extern NJS_ACTION dat_0c9eb8a0;
extern NJS_ACTION dat_0cb2d478;
extern NJS_ACTION dat_0ca00ab8;
extern NJS_ACTION past_kn_fam_actions[3];
/* the node of a Chao's model that person_face_camera turns to the camera */
extern NJS_OBJECT dat_0c9ddb2c;

/* the most people past_people_place places at once */

/* a kind's character, whose textures person_start loads and person_destroy
 * releases. a kind whose texture list past_pvms loads with the stage has
 * NO_CHARACTER instead, or NO_CHARACTER_CHAO for a Chao. person_draw turns a
 * node of a Chao's model to the camera */

/* the indexes of people_kinds. each Chao, Tikal and echidna kind plays an
 * action of its own */
enum person_kind_index {
    PERSON_PACHACAMAC,
    PERSON_CHAO_A,
    PERSON_CHAO_B,
    PERSON_CHAO_C,
    PERSON_TIKAL_A,
    PERSON_TIKAL_B,
    PERSON_ECHIDNA_A,
    PERSON_ECHIDNA_B,
    PERSON_ECHIDNA_C,
    PERSON_KINDS
};

/* a person's talk reaches TALK_REACH past its shape's radius, and talk_add
 * adds player 0's radius to that */

/* the radius draw_in_view tests a person's position by */

/* a kind of person: how it looks, its shape, and where player 0 looks during
 * a talk */
struct person_kind {
    int character;
    NJS_TEXLIST *texlist;
    NJS_ACTION *action;
    Float lift; /* how far above pos the model is drawn */
    Float eye; /* how far above pos player 0 looks during a talk */
    struct collision_shape shape;
};

/* where an act places a person, with the person's row and kind */
struct person_spot {
    NJS_POINT3 pos;
    Sint16 ang_x;
    Sint16 ang_y;
    Sint16 ang_z;
    Sint8 row; /* the person's row of past_script_table */
    Sint8 kind; /* a person_kind_index */
};

struct person_list {
    const struct person_spot *spots;
    int count;
};

/* a person's task work, which the task holds in place of a task_work. each
 * member the two share lies at the same offset in both */
struct person_work {
    Sint8 mode;
    Sint8 submode;
    Uint8 id;
    Uint8
        manager_data; /* 1 while the next message started after a talk shows */
    Sint16 flags;
    Sint16 timer;
    Float frame; /* the action's frame */
    /* TRUE from the start of player 0's talk with the person until
     * person_step answers it */
    Bool talking;
    int kind; /* a person_kind_index */
    struct angles ang;
    NJS_POINT3 pos;
    Uint8 unk_2c[4];
    struct script_pages *pick; /* what the person's row last picked */
    int row; /* in past_script_table */
    struct collision_work *collision;
    struct event_work *event;
};

/* a person's shape, a capsule whose center lies 7 above the person's
 * position, and a Chao's, a ball. the person's angles turn neither. each
 * pushes players and objects, and players can't push it. a player it pushes
 * back doesn't start to push against it */
/* clang-format off */
/* clang-format on */

void pastpc_init(struct task *task);
void pastpc_set_pcindex(struct task *task);
void pastpc_exec_always(struct task *task);
void pastpc_talk(struct task *task);
void pastpc_exec(struct task *task);
void person_face_camera(NJS_OBJECT *object);
void pastpc_draw(struct task *task);
void pastpc_end(struct task *task);
extern const struct person_kind pastpc_data_tbl[PERSON_KINDS];
extern const struct person_spot people_act0[3];
extern const struct person_spot people_act1[8];
extern const struct person_spot people_act2[13];
extern const Sint16 people_script_0[];
extern const Sint16 people_script_1[];
extern const Sint16 people_script_2[];
extern const Sint16 people_script_3[];
extern const Sint16 people_script_4[];
extern const Sint16 people_script_5[];
extern const Sint16 people_script_6[];
extern const Sint16 people_script_7[];
extern const Sint16 people_script_8[];
extern const Sint16 people_script_9[];
extern const struct person_list people_lists[3];
extern const struct script_row past_script_table[];
extern int people_count;
extern struct task *people[12];

void PASTPcInit(void)
{
    const struct person_list *list;
    const struct person_spot *spot;
    struct script_pages *pick;
    struct task *task;
    struct person_work *work;
    int left;
    int row;

    people_count = 0;
    list = &people_lists[(Uint8)GetStageNumber()];
    spot = list->spots;
    left = list->count;
    if (spot == NULL) {
        return;
    }
    pick = MAlloc(sizeof(struct script_pages));
    do {
        if (pick != NULL) {
            /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
            row = spot->row;
            if (HintMessageInit(row, pick)) {
                task = CreateElementalTask(TASK_WORK, 3, pastpc_init);
                work = PERSON(task);
                work->pick = pick;
                pick = MAlloc(sizeof(struct script_pages));
                work->row = row;
                work->pos = spot->pos;
                work->ang.x = spot->ang_x;
                work->ang.y = spot->ang_y;
                work->ang.z = spot->ang_z;
                /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
                work->kind = spot->kind;
                people[people_count] = task;
                people_count++;
            }
        }
        spot++;
    } while (--left != 0 && people_count < PEOPLE_MAX);
    Free(pick);
}

void past_people_remove(void)
{
    while (people_count != 0) {
        people_count--;
        if (people[people_count] != NULL) {
            DestroyTask(people[people_count]);
            people[people_count] = NULL;
        }
    }
}

/* start the person, and give it its step, draw and destructor. the
 * WORK_SAME_PLACE tests always pass */
void pastpc_init(struct task *task)
{
    /* @hack redundant: pos tested a second time (ADD #32,R2 at 0x0c904d26 and
     * 0x0c904d56); tested once, 24 of 51 words differ */
    /* NOLINTBEGIN(misc-redundant-expression) */
    if (WORK_SAME_PLACE(struct person_work, pos) &&
        WORK_SAME_PLACE(struct person_work, id) &&
        WORK_SAME_PLACE(struct person_work, collision) &&
        WORK_SAME_PLACE(struct person_work, event) &&
        WORK_SAME_PLACE(struct person_work, pos) &&
        WORK_SAME_PLACE(struct person_work, flags)) {
        pastpc_set_pcindex(task);
        task->step = pastpc_exec;
        task->draw = pastpc_draw;
        task->destructor = pastpc_end;
    }
    /* NOLINTEND(misc-redundant-expression) */
}

/* load the textures of the kind's character, if it has one, add the person's
 * talk and start its collision */
void pastpc_set_pcindex(struct task *task)
{
    struct person_work *work = PERSON(task);
    const struct person_kind *kind = &pastpc_data_tbl[work->kind];

    if (kind->character >= 0) {
        texture_load_character(kind->character);
    }
    InputHookSet(task, &work->pos, &work->ang.y, &work->talking,
                 kind->shape.radius + TALK_REACH, TALK_LEVEL);
    work->frame = 0.0F;
    CCL_Init(task, &kind->shape, COLLISION_OBJECT, 1, 1);
}

/* advance the action a frame, back to 0 once it passes the last, and draw
 * the person */
void pastpc_exec_always(struct task *task)
{
    struct person_work *work = PERSON(task);
    const struct person_kind *kind = &pastpc_data_tbl[work->kind];

    /* @hack spelling: the frame advanced inside the test, which compares the
     * sum in FR2 as it stores it (FCMP/GT FR1,FR2 at 0x0c904e6c); advanced
     * before it, SHC loads the frame again, the function runs 2 bytes longer
     * and 12 of 37 words differ */
    if ((work->frame += 1.0F) > kind->action->motion->nbFrame - 1.0F) {
        work->frame = 0.0F;
    }
    pastpc_draw(task);
}

/* animate the person. once shown is clear, end the talk, clear player 0's
 * look and go back to person_step */
void pastpc_talk(struct task *task)
{
    struct person_work *work = PERSON(task);

    if (!work->manager_data) {
        InputHookRelease();
        CancelLookingAtP(0);
        task->step = pastpc_exec;
    }
    pastpc_exec_always(task);
}

/* while no event has control, register the person's collision and animate
 * it. once player 0 starts talking to it, run its row again and hand the
 * pick to script_show. when the heap has no room or the script fails, hand
 * it the last pick instead. past_script_table's rows pick no pages, so the
 * talk shows no message. player 0 then looks at the person's eye height
 * until person_listen ends the talk */
void pastpc_exec(struct task *task)
{
    struct person_work *work = PERSON(task);
    const struct person_kind *kind = &pastpc_data_tbl[work->kind];
    struct script_pages *pick;
    NJS_POINT3 eye;

    if (EV_CheckCansel()) {
        return;
    }
    EntryColliList((struct task_work *)work);
    if (work->talking) {
        pick = MAlloc(sizeof(struct script_pages));
        if (pick != NULL && HintMessageInit(work->row, pick)) {
            Free(work->pick);
            work->pick = pick;
        } else {
            Free(pick);
        }
        HintRegistStatusPointer(&work->manager_data);
        HintMessageStart(work->pick);
        eye.x = work->pos.x;
        eye.y = work->pos.y + kind->eye;
        eye.z = work->pos.z;
        SetLookingPointP(0, &eye);
        work->talking = FALSE;
        task->step = pastpc_talk;
    }
    pastpc_exec_always(task);
}

void person_face_camera(NJS_OBJECT *object)
{
    if (object == &dat_0c9ddb2c) {
        TURN(njRotateY, camera_twp->ang.y);
        TURN(njRotateX, camera_twp->ang.x + 0x8000);
    }
}

/* on a frame's first step, while no event has control and the sphere of
 * VIEW_RADIUS about the person is in view, draw the person and its shadow */
void pastpc_draw(struct task *task)
{
    struct person_work *work = PERSON(task);
    const struct person_kind *kind;
    Float lift;
    NJS_TEXLIST *texlist;
    NJS_ACTION *action;

    if (!loop_count &&
        dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, VIEW_RADIUS) &&
        !EV_CheckCansel()) {
        njPushMatrix(NULL);
        kind = &pastpc_data_tbl[work->kind];
        lift = kind->lift;
        texlist = kind->texlist;
        action = kind->action;
        njTranslateV(NULL, &work->pos);
        PASTDrawShadow(kind->shape.radius);
        njTranslate(NULL, 0.0F, lift, 0.0F);
        njRotateXYZ(NULL, work->ang.x, work->ang.y, work->ang.z);
        draw_set_palette(DRAW_PLAYER_PALETTE);
        njSetTexture_jp(texlist);
        if (kind->character == (-2)) {
            FUN_8c60d138(person_face_camera);
        }
        ds_ActionClip(action, work->frame);
        if (kind->character == (-2)) {
            FUN_8c60d138(((void *)0));
        }
        draw_set_palette(0);
        late_DrawObjectClipEx(1);
    }
}

/* give back the kind's character's textures, the pick and the talk */
void pastpc_end(struct task *task)
{
    struct person_work *work = PERSON(task);
    const struct person_kind *kind = &pastpc_data_tbl[work->kind];

    if (kind->character >= 0) {
        ReleasePlayersTexture(kind->character);
    }
    Free(work->pick);
    InputHookDelete(task);
}
