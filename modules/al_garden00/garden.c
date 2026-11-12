/* @unit 0CB80000-0CB80240 @data 0CB8115C-0CB81168 +egflags +pool32 */
/* the Station Square garden: the stage's task */
#include <ninja.h>

#include "al_garden00/door.h"
#include "al_garden00/garden.h"
#include "al_main/alife.h"
#include "al_main/camera.h"
#include "al_main/card.h"
#include "al_main/chao.h"
#include "camera/camera.h"
#include "chao/chao.h"
#include "debug/editor.h"
#include "draw/light.h"
#include "player/player.h"
#include "progress/progress.h"
#include "sound/stream.h"
#include "stage/stage.h"
#include "system/task.h"
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
void FUN_0cb80dc4(void);
void HintRegistStatusPointer(Uint8 *manager_data);
Bool HintMessageInit(int row, struct script_pages *pick);
void HintMessageStart(struct script_pages *pick);
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct task_work *camera_twp;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void FUN_8c01937c(Angle ang);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
void AddExtraDisplay(Sint8 kind);
void ExtraDisplayInit(void);
void pdExecPeripheralServerUser(void);
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
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
Bool OnEdit(struct task *task);
Bool light_read_disc_palettes(Uint16 stage, int act);
Bool FUN_8c014308(Uint16 stage, int act);
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
Bool CameraFishingCatch(void);

#define WATER_LAST 9
#define GARDEN_PERSPECTIVE NJM_DEG_ANG(80)
#define PERSPECTIVE NJM_DEG_ANG(70) /* the one the destructor puts back */
#define EXIT_RANGE 80.0F
#define CEILING 62.0F /* the step holds player 0's y at or below this */
extern NJS_MATERIAL water_material;

/* water_material's texture cycles from 0 to WATER_LAST, a texture every
 * third step */

/* the field of view the start gives camera_set_perspective, which
 * garden_camera_step soon replaces with the zoom's: 30, 49 or 68 degrees */

/* player 0 leaves for the race once within EXIT_RANGE of (0, 0, -250) */

enum garden_mode { GARDEN_INIT, GARDEN_WAIT, GARDEN_RUN };

void station_square_garden_start(struct task *task);
void station_square_garden_destroy(struct task *task);
void station_square_garden_light_load(struct task *task);

void station_square_garden_step(struct task *task)
{
    struct task_work *work = task->work;

    if (edit_mode != 0) {
        CameraReleaseEventCamera();
    }
    switch (work->mode) {
    case GARDEN_INIT:
        alife_create();
        station_square_garden_start(task);
        task->destructor = station_square_garden_destroy;
        station_square_garden_light_load(task);
        work->mode++;
        work->timer = 0;
        break;
    case GARDEN_WAIT:
        if (TASK_TIMER(work)++ > 3) {
            CameraSetCollisionCameraFunc(garden_camera_step, 1, CAMERA_LOOK_AT);
            work->mode++;
        }
        break;
    case GARDEN_RUN:
        if (work->tick++ > 1) {
            water_material.attr_texId++;
            if (water_material.attr_texId > WATER_LAST) {
                water_material.attr_texId = 0;
            }
            work->tick = 0;
        }
        {
            NJS_POINT3 exit = {0.0F, 0.0F, -250.0F};
            if (CalcDistance(&playertwp[0]->pos, &exit) < 80.0F) {
                FUN_0cb80dc4();
                alife_save();
                stage_fade_to(STAGE_ALIFE_RACE, 0);
                FreeTask(task);
            }
        }
        if (playertwp[0]->pos.y > CEILING) {
            playertwp[0]->pos.y = CEILING;
        }
        break;
    }
}

void station_square_garden_start(struct task *task)
{
    chao_gardens_init();
    alife_chao_create_garden(GARDEN_STATION_SQUARE);
    garden_flags_load();
    FUN_8c01937c(((Angle)(((80) * 65536.0) / 360.0)));
    ADXTaskInit();
    BGM_Play(MUSIC_CHAO);
}

void station_square_garden_destroy(struct task *task)
{
    FUN_8c01937c(((Angle)(((70) * 65536.0) / 360.0)));
    CameraReleaseEventCamera();
    njFogDisable();
    ADX_Close();
}

/* set the work's submode to the time of day, and read that time's light
 * sources and palettes, which are act 0's for every time. a time other than
 * TIME_DAY, TIME_EVENING and TIME_NIGHT sets a red, green and blue
 * background instead */
void station_square_garden_light_load(struct task *task)
{
    struct task_work *work = task->work;

    work->submode = story_get_time();
    /* @hack spelling: the same reads in a case of each time's own, which SHC
     * keeps as one arm behind a CMP/EQ for each time (0x0cb8019c to
     * 0x0cb801a4); with the three labels on one case, 35 of 39 words differ */
    switch (work->submode) {
    case 0:
        light_read_disc_palettes(39, 0);
        FUN_8c014308(39, 0);
        break;
    case 1:
        light_read_disc_palettes(39, 0);
        FUN_8c014308(39, 0);
        break;
    case 2:
        light_read_disc_palettes(39, 0);
        FUN_8c014308(39, 0);
        break;
    default:
        njSetBackColor_jp(0xff0000, 0xff00, 0xff);
        break;
    }
}
