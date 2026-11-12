/* @unit 0C900000-0C900840 @data 0C90F3E0-0C90F404 +r04 +egflags +pool32 */
/* Emerald Coast's stage task and sky task. the stage task starts each act,
 * and the sky task draws each act's sky and lens flares */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "collision/world.h"
#include "draw/tree.h"
#include "effect/lens.h"
#include "object/placement.h"
#include "player/player.h"
#include "progress/progress.h"
#include "sound/sound.h"
#include "sound/stream.h"
#include "stage/stage.h"
#include "stg01/beach.h"
#include "stg01/cycle.h"
#include "stg01/footprints.h"
#include "stg01/orca_control.h"
#include "stg01/sea_surface.h"
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
void thunk_FUN_8c652d78(Uint32 density);
void ReleaseModule(NJS_FOG_TABLE fog, Float n, Float f);
void kmSetFogTable(NJS_FOG_TABLE fog);
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
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
void FUN_8c04f84e(Sint16 by);
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
Bool SeqCheckStage(int stage, int act);
void SeqChangeStage(int stage, int act);
Bool SeqCheckNextStage(Uint8 stage, Uint8 act);
Bool SeqCheckClearAction(int stage);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
Bool CameraFishingCatch(void);
void FUN_0c900000(struct task *task);
void FUN_0c90023e(struct task *task);
void FUN_0c904a8c(struct task *task);
void FUN_0c904c9a(struct task *task);
void FUN_0c904d06(struct task *task);
void FUN_0c906082(struct task *task);
extern struct task *OrukaTask;
Bool orCreateAttackOruka(Float x, Float y, Float z, Angle ang);
void orFreePathOruka(struct task *task);
void DestructBeachWaveBG(void);
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
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

#define MUSIC_DELAY 10
#define SE_WAVES 926
#define SE_SURF 928
#define EXIT_NEAR 22.0F
#define SUN_NEAR 1000.0F
#define FOG_NEAR 880.0F
#define FOG_Y (-70.0F)
#define SKY_MODES 3
#define SKY_MODE(act, mode) (((act) * SKY_MODES) + (mode))
#define BACK_COLOR 0x3946
#define BACK_COLOR_ACT2 0x444cff
extern NJS_TEXLIST beach_sky_texlist;
extern NJS_OBJECT beach_sky_object_0;
extern NJS_OBJECT beach_sky_object_1;

/* the music task waits MUSIC_DELAY steps. it asks for the act's music on
 * the step after */

/* the sounds of the waves and the surf. each act's start plays both, held */

/* player 0 leaves act 0 for act 1 within EXIT_NEAR of act0_exit */
/* act 1 draws its lens flare only while player 0 is within SUN_NEAR of
 * sun_point */
/* act 2 fogs the view in place of its sky while player 0 is below FOG_Y. a
 * player must also be within FOG_NEAR of water_point */

/* sky modes, three for each act: start the act's sky, draw it, and reset it */
enum sky_mode { SKY_START, SKY_DRAW, SKY_RESET };
extern NJS_FOG_TABLE beach_fog_table;

void beach_music_wait_step(struct task *task);
void FUN_0c900064(struct task *task);
void FUN_0c900210(struct task *task);
void beach_sky_run(struct task *task);
void DisplayBg(struct task *task);
void DestructBg(struct task *task);
void Rd_Beach(struct task *task);

void FUN_0c900000(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case BEACH_INIT:
        FUN_0c900064(task);
        break;
    case BEACH_ACT0:
        Rd_Beach(task);
        break;
    case BEACH_ACT1:
    case BEACH_ACT2:
        break;
    case BEACH_END:
        FUN_0c900210(task);
        break;
    }
}

/* the music task. once work->timer counts down below 0, it resets the
 * streams and asks for the music in work->mode. then the task ends */
void beach_music_wait_step(struct task *task)
{
    struct task_work *work = task->work;

    work->timer--;
    if (work->timer < 0) {
        ADXTaskInit();
        BGM_Play(work->mode);
        DestroyTask(task);
    }
}

/* start the act the stage is in: the held sounds, the act's tasks and its
 * music. as Tails, starting act 1 also ends it as a clear. an act past 2
 * starts only the sounds, and takes the mode BEACH_ACT0 */
void FUN_0c900064(struct task *task)
{
    struct task_work *work = task->work;
    struct task *made;
    Uint16 stage;

    dsPlay_iloop(SE_WAVES, -1, 8, 0);
    dsPlay_iloop(SE_SURF, -1, 8, 0);
    stage = GetStageNumber();
    if ((Uint8)stage == 0) {
        orInitOrukaSequence();
        if ((made = CreateElementalTask(0x2, 3, FUN_0c906082)) != ((void *)0)) {
            made->work->scl.x = 0.0F;
        }
        CreateElementalTask(TASK_WORK | TASK_EXTRA, 3, beach_act0_sand_step);
        CreateElementalTask(TASK_WORK | TASK_EXTRA, 3, beach_act0_wave_step);
        made = CreateElementalTask(TASK_WORK, 0, beach_music_wait_step);
        made->work->mode = MUSIC_ECOAST1;
        made->work->timer = MUSIC_DELAY;
        work->mode = BEACH_ACT0;
    } else if ((Uint8)stage == 1) {
        if ((made = CreateElementalTask(0x2, 3, FUN_0c906082)) != ((void *)0)) {
            made->work->scl.x = 0.0F;
        }
        CreateBeachWaveBG(BEACH_ACT1);
        CreateElementalTask(0x2 | 0x8, 1, beach_act1_sand_step);
        CreateElementalTask(0x2 | 0x8, 1, FUN_0c904a8c);
        CreateElementalTask(0x2 | 0x8, 1, beach_act1_water_step);
        made = CreateElementalTask(0x2, 0, beach_music_wait_step);
        made->work->mode = MUSIC_ECOAST2;
        made->work->timer = MUSIC_DELAY;
        work->mode = BEACH_ACT1;
        if (GetPlayerNumber() == CHARACTER_TAILS) {
            stage_end(STAGE_END_CLEAR);
        }
    } else if ((Uint8)stage == 2) {
        if ((made = CreateElementalTask(0x2, 3, FUN_0c906082)) != ((void *)0)) {
            made->work->scl.x = 0.0F;
        }
        CreateBeachWaveBG(BEACH_ACT2);
        CreateElementalTask(0x2 | 0x8, 1, FUN_0c904c9a);
        CreateElementalTask(0x2 | 0x8, 1, beach_act2_wave_step);
        CreateElementalTask(0x2 | 0x8, 1, FUN_0c904d06);
        made = CreateElementalTask(0x2, 0, beach_music_wait_step);
        made->work->mode = MUSIC_ECOAST3;
        made->work->timer = MUSIC_DELAY;
        work->mode = BEACH_ACT2;
    } else {
        /* @hack redundant: the jump to the next statement, which puts
         * BEACH_ACT0 in R2 for its store (MOV #1,R2 at 0x0c90021e); without it,
         * 2 of 168 words differ */
        goto other_act;
    other_act:
        work->mode = BEACH_ACT0;
    }
}

void FUN_0c900210(struct task *task)
{
    Uint16 act = (Uint8)GetStageNumber();

    if (act == 0) {
        orca_control_end();
    }
    if (act == 2) {
        stage_end(STAGE_END_CLEAR);
    }
}

void FUN_0c90023e(struct task *task)
{
    task->step = beach_sky_run;
    task->draw = DisplayBg;
    task->destructor = DestructBg;
}

/* end the sky task and its children off Emerald Coast. once the act
 * changes, a drawing sky goes to its reset. the reset returns it to
 * SKY_MODE(0, SKY_START), act 0's start. a sky at any act's start goes to
 * the new act's start */
void beach_sky_run(struct task *task)
{
    struct task_work *work = task->work;
    Uint16 stage = GetStageNumber();
    Uint16 act = (Uint8)stage;
    stage &= 0xff00;
    if (stage != ((1) << 8 | (0))) {
        FreeTask(task);
        return;
    }
    if (work->mode / SKY_MODES != act) {
        if (work->mode % SKY_MODES == SKY_DRAW) {
            ++work->mode;
        } else if (work->mode % SKY_MODES == SKY_START) {
            work->mode = SKY_MODE(act, SKY_START);
        }
    }
    DisplayBg(task);
}

/* each act's sky, about the camera's x and z, and its lens flares. act 2's
 * draw also steps the task's children. FOG_NEAR and FOG_Y say where it fogs
 * the view in place of the sky */
void DisplayBg(struct task *task)
{
    static const NJS_POINT3 sun_point = {6235.0F, 0.0F, -2275.0F};
    static const NJS_POINT3 water_point = {6152.0F, -85.0F, 2383.0F};
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    NJS_POINT3 sun;
    NJS_POINT3 point;

    sun = sun_point;
    SaveControl3D();
    draw_control_set(NJD_CONTROL_3D_NO_CLIP_CHECK);
    draw_control_clear(NJD_CONTROL_3D_DEPTH_QUEUE);
    switch (work->mode) {
    case SKY_MODE(0, SKY_START):
        njSetBackColor_jp(BACK_COLOR, BACK_COLOR, BACK_COLOR);
        CHAOS_SetChaosNo(0);
        njFogDisable();
        work->mode = SKY_MODE(0, SKY_DRAW);
        /* falls through, so the sky draws on the step it starts */
    case SKY_MODE(0, SKY_DRAW):
        point.x = 10000.0F;
        point.y = 4000.0F;
        point.z = -590.0F;
        lens_draw(&point);
        point.x = -1500.0F;
        point.y = 3000.0F;
        point.z = 4000.0F;
        lens_draw(&point);
        njFogDisable();
        njPushMatrix(NULL);
        njTranslate(NULL, camera_twp->pos.x, 0.0F, camera_twp->pos.z);
        njSetTexture_jp(&beach_sky_texlist);
        late_DrawObject(&beach_sky_object_0);
        late_DrawObject(&beach_sky_object_1);
        late_DrawObjectClipEx(1);
        njFogEnable();
        break;
    case SKY_MODE(0, SKY_RESET):
        DestructBg(task);
        work->mode = 0;
        break;
    case SKY_MODE(1, SKY_START):
        njSetBackColor_jp(BACK_COLOR, BACK_COLOR, BACK_COLOR);
        if (!SeqCheckFlag(FLAG_SONIC_CLEAR_BEACH)) {
            texture_load_character(CHARACTER_TAILS);
        }
        njFogDisable();
        work->mode = SKY_MODE(1, SKY_DRAW);
        /* falls through, so the sky draws on the step it starts */
    case SKY_MODE(1, SKY_DRAW):
        if (CalcDistance(&player->pos, &sun) < SUN_NEAR) {
            point.x = 17000.0F;
            point.y = 3500.0F;
            point.z = -2000.0F;
            lens_draw(&point);
        }
        njPushMatrix(NULL);
        njTranslate(NULL, camera_twp->pos.x, 0.0F, camera_twp->pos.z);
        njSetTexture_jp(&beach_sky_texlist);
        late_DrawObject(&beach_sky_object_0);
        late_DrawObject(&beach_sky_object_1);
        late_DrawObjectClipEx(1);
        break;
    case SKY_MODE(1, SKY_RESET):
        DestructBg(task);
        work->mode = 0;
        break;
    case SKY_MODE(2, SKY_START):
        CHAOS_SetChaosNo(0xffffffff);
        ReleaseModule(beach_fog_table, -10.0F, -1600.0F);
        kmSetFogTable(beach_fog_table);
        njSetBackColor_jp(BACK_COLOR_ACT2, BACK_COLOR_ACT2, BACK_COLOR_ACT2);
        njSetDepthQueue(-1700.0F, -1900.0F);
        njClipZ(-3.0F, -2000.0F);
        work->mode = SKY_MODE(2, SKY_DRAW);
        njFogDisable();
        break;
    case SKY_MODE(2, SKY_DRAW):
        point.x = 6158.0F;
        point.y = 3500.0F;
        point.z = 2385.0F;
        lens_draw(&point);

        njFogDisable();
        point = water_point;
        if (player_in_range(&point, 880.0F) && playertwp[0]->pos.y < (-70.0F)) {
            ReleaseModule(beach_fog_table, -10.0F, -1600.0F);
            kmSetFogTable(beach_fog_table);
        } else {
            ReleaseModule(beach_fog_table, -1600.0F, -2000.0F);
            kmSetFogTable(beach_fog_table);
            njPushMatrix(((void *)0));
            njTranslate(((void *)0), camera_twp->pos.x, 0.0F,
                        camera_twp->pos.z);
            njSetTexture_jp(&beach_sky_texlist);
            late_DrawObject(&beach_sky_object_0);
            late_DrawObject(&beach_sky_object_1);
            late_DrawObjectClipEx(1);
        }
        njFogEnable();
        break;
    case SKY_MODE(2, SKY_RESET):
        DestructBg(task);
        work->mode = 0;
        break;
    default:
        /* @bug memory: a mode past 8 hands heap_free the task itself (JSR at
         * 0x0c9006f2), though tasks come from task_init's pool, not from
         * heap_alloc. SKY_MODE gives acts 0 to 2 the modes 0 to 8.
         * beach_sky_run sets a mode past them only for an act of 3 or more */
        Free(task);
        break;
    }
    LoadControl3D();
}
void DestructBg(struct task *task)
{
    switch (task->work->mode) {
    case (((0) * 3) + (SKY_DRAW)):
    case (((0) * 3) + (SKY_RESET)):
        break;
    case (((1) * 3) + (SKY_DRAW)):
    case (((1) * 3) + (SKY_RESET)):
        DestructBeachWaveBG();
        if (!SeqCheckFlag(166)) {
            ReleasePlayersTexture(2);
        }
        break;
    case (((2) * 3) + (SKY_DRAW)):
    case (((2) * 3) + (SKY_RESET)):
        DestructBeachWaveBG();
        njFogDisable();
        break;
    case (((0) * 3) + (SKY_START)):
    case (((1) * 3) + (SKY_START)):
    case (((2) * 3) + (SKY_START)):
        break;
    default:
        return;
    }
}

void Rd_Beach(struct task *task)
{
    static const NJS_POINT3 act0_exit = {5746.0F, 406.0F, 655.0F};
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    NJS_POINT3 exit;

    exit = act0_exit;
    if (player == NULL) {
        return;
    }
    if (CalcDistance(&exit, &player->pos) < EXIT_NEAR) {
        work->mode = BEACH_INIT;
        ADX_Close();
        world_change_act(1);
        placement_change_act(1);
        camera_change_act(1);
        FUN_8c04f84e(1);
        stage_place_player(player);
    }
}
