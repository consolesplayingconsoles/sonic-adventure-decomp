/* @unit 0CB80000-0CB802A0 @data 0CB8087C-0CB8088C +r04 +egflags +pool32 */
/* the Egg Carrier's garden: the stage's task */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_garden01/garden.h"
#include "al_garden01/sky_textures.h"
#include "al_main/alife.h"
#include "al_main/camera.h"
#include "al_main/chao.h"
#include "camera/camera.h"
#include "chao/chao.h"
#include "progress/progress.h"
#include "sound/sound.h"
#include "sound/stream.h"
#include "system/frame.h"
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
Bool HintMessageInit(int row, struct script_pages *pick);
void HintMessageStart(struct script_pages *pick);
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
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void FUN_8c01937c(Angle ang);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void AmyBalanceGameStartChecker(struct camera_view *view);
void AddExtraDisplay(Sint8 kind);
void ExtraDisplayInit(void);
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
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
void ADX_Close(void);
Bool CameraFishingCatch(void);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
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

#define SEA_FIRST 54
#define SEA_LAST 63
#define WAVE_FIRST 64
#define WAVE_LAST 78
#define SEA_SPEED 0.3F
#define WAVE_SPEED 0.2F
#define GARDEN_PERSPECTIVE NJM_DEG_ANG(80)
#define PERSPECTIVE NJM_DEG_ANG(70) /* the one GARDEN_END would put back */
#define VARS(work) ((struct garden_vars *)&(work)->vars)
extern NJS_OBJECT egg_carrier_garden_sky_object;
extern NJS_MATERIAL sea_materials[];
extern NJS_MATERIAL sea_materials_2[];
extern NJS_MATERIAL sea_materials_3[];
extern NJS_MATERIAL wave_materials[];

/* the textures sea_materials and wave_materials cycle through.
 * sea_materials_2 and sea_materials_3 don't cycle: each takes SEA_FIRST as
 * sea_materials wraps */
/* how far the sea and the waves move toward their next texture a step */

/* the field of view the start gives camera_set_perspective, which
 * garden_camera_step soon replaces with the zoom's: 30, 49 or 68 degrees */

/* no code sets GARDEN_END, so egg_carrier_garden_end never runs */
enum garden_mode { GARDEN_INIT, GARDEN_WAIT, GARDEN_RUN, GARDEN_END };

/* how far the sea and the waves are toward their next texture. each takes
 * its next texture once it passes 1 */
struct garden_vars {
    Float sea;
    Float wave;
};

void egg_carrier_garden_start(struct task *task);
void egg_carrier_garden_end(struct task *task);
void egg_carrier_garden_sky_draw(struct task *task);

static void egg_carrier_garden_sky_load(struct task *task)
{
    /* @hack redundant: work, which nothing reads. inlined into
     * egg_carrier_garden_step, it keeps the image's MOV R13,R4 at 0x0cb8002c,
     * a copy of task that the call's own arguments replace; without it, 100
     * of 118 words differ */
    struct task_work *work = task->work;

    texLoadTexturePvmFile("garden01_sky", &egg_carrier_garden_sky_texlist);
}

void egg_carrier_garden_step(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case GARDEN_INIT:
        alife_create();
        egg_carrier_garden_start(task);
        egg_carrier_garden_sky_load(task);
        task->draw = egg_carrier_garden_sky_draw;
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
        egg_carrier_garden_sky_draw(task);
        if (VARS(work)->sea > 1.0F) {
            sea_materials->attr_texId++;
            if (sea_materials->attr_texId > SEA_LAST) {
                sea_materials->attr_texId = SEA_FIRST;
                sea_materials_2->attr_texId = sea_materials->attr_texId;
                sea_materials_3->attr_texId = sea_materials->attr_texId;
            }
            VARS(work)->sea = 0.0F;
        }
        if (VARS(work)->wave > 1.0F) {
            wave_materials->attr_texId++;
            if (wave_materials->attr_texId > WAVE_LAST) {
                wave_materials->attr_texId = WAVE_FIRST;
            }
            VARS(work)->wave = 0.0F;
        }
        VARS(work)->sea += SEA_SPEED;
        VARS(work)->wave += WAVE_SPEED;
        break;
    case GARDEN_END:
        egg_carrier_garden_end(task);
        break;
    }
}

void egg_carrier_garden_start(struct task *task)
{
    chao_gardens_init();
    njSetBackColor_jp(0x5555ff, 0x5555ff, 0xffffff);
    alife_chao_create_garden(GARDEN_EGG_CARRIER);
    FUN_8c01937c(((Angle)(((80) * 65536.0) / 360.0)));
    ADXTaskInit();
    BGM_Play(MUSIC_CHAO);
}

void egg_carrier_garden_end(struct task *task)
{
    dsStop_id((int)task);
    FUN_8c01937c(((Angle)(((70) * 65536.0) / 360.0)));
    njReleaseTexture_jp(&egg_carrier_garden_sky_texlist);
}

/* set the work's submode to the time of day, and on a frame's first step draw
 * the sky round the camera, without fog */
void egg_carrier_garden_sky_draw(struct task *task)
{
    struct task_work *work = task->work;

    work->submode = story_get_time();
    if (loop_count == 0) {
        njSetTexture_jp(&egg_carrier_garden_sky_texlist);
        SaveControl3D();
        draw_control_set(NJD_CONTROL_3D_NO_CLIP_CHECK);
        draw_control_clear(NJD_CONTROL_3D_DEPTH_QUEUE);
        njFogDisable();
        njPushMatrix(NULL);
        njTranslate(NULL, camera_twp->pos.x, -62.5F, camera_twp->pos.z);
        njScale(NULL, 0.15F, 0.15F, 0.15F);
        late_DrawObjectClip(&egg_carrier_garden_sky_object);
        njFogEnable();
        late_DrawObjectClipEx(1);
        LoadControl3D();
    }
}
