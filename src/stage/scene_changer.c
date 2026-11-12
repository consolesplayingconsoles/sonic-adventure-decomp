/* @unit 8C034940-8C034C80 @data 8C1125FC-8c11264c +egflags +r04 +pool32 */
/* C SCENECHANGER: a box that changes the stage or act once touched */
#include <ninja.h>
#include <sg_xpt.h>

#include "camera/camera.h"
#include "collision/collision.h"
#include "collision/world.h"
#include "debug/debug.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/stream.h"
#include "stage/scene_changer.h"
#include "stage/stage.h"
#include "system/pad.h"
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
extern struct task_work *camera_twp;
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void RegisterCollisionEntry(Sint32 flags, struct task *task,
                            NJS_OBJECT *object);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void SetMleriRangeRad(Float radius);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
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
void BGM_Play(int music);
Bool CameraFishingCatch(void);
void ADXTaskInit(void);
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
void FUN_8c04f84e(Sint16 by);
Bool ChkPause(void);
void pdExecPeripheralServerUser(void);
extern PDS_PERIPHERAL perG[8];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
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
extern struct collision_shape scene_changer_shape;

/* half the box's size along each axis at scale 0. a placement's scale s
 * makes it (s + 1) * BOX_HALF_SIZE */
#define BOX_HALF_SIZE 5.0F

/* the box at scale 0. collision_init copies it for each task, which scales
 * its copy */

static void scene_changer_step(struct task *task);
static void scene_changer_destroy(struct task *task);

void scene_changer_go(int destination)
{
    Sint16 stage;
    int act;
    Sint16 current_stage;
    int current_act;
    int by;

    stage_set_entrance((destination >> 4) & 0xf);
    stage = (destination >> 8) & 0xff;
    act = destination & 0xf;
    current_stage = GetStageNumber() >> 8;
    current_act = GetStageNumber() & 0xff;
    if (stage == current_stage) {
        by = act - current_act;
        ADX_Close();
        world_change_act(by);
        placement_change_act(by);
        camera_change_act(by);
        FUN_8c04f84e(by);
        stage_place_player(playertwp[0]);
    } else {
        stage_end(STAGE_END_CLEAR);
        stage_set_next_stage_act(stage, act);
    }
}

void scene_changer_init(struct task *task)
{
    struct task_work *work = task->work;
    Float x;
    Float y;
    Float z;

    if (!OnEdit(task)) {
        CCL_Init(task, &scene_changer_shape, COLLISION_PICKUP, 1, 1);
        /* @hack spelling: each scale's sum inside its product, which SHC
         * multiplies from the register that holds the sum (FMOV FR3,FR4 at
         * 0x8c035af8). as statements, SHC loads the x and z scales again
         * after their stores, and 51 of 74 words differ */
        x = (work->scl.x += 1.0F) * BOX_HALF_SIZE;
        y = (work->scl.y += 1.0F) * BOX_HALF_SIZE;
        z = (work->scl.z += 1.0F) * BOX_HALF_SIZE;
        work->collision->shapes->radius = x;
        /* @hack spelling: the height's store inside the sum, which keeps x's
         * product in FR4 and y's in FR5 (0x8c035afa, 0x8c035b06). as two
         * statements, the two trade, and 52 of 74 words differ */
        work->pos.y += (work->collision->shapes->size_y = y);
        work->collision->shapes->size_z = z;
        /* radius takes the sum of the half sizes' squares, where
         * collision_set_radius would take its square root. the radius then
         * reaches past the box's corners while they lie more than 1 from its
         * center */
        work->collision->radius = (x * x) + (y * y) + (z * z);
    }
    task->destructor = scene_changer_destroy;
    task->step = scene_changer_step;
}

static void scene_changer_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        /* @hack spelling: pad_is_enabled compared with TRUE, CMP/EQ #1
         * (0x8c035b88). it returns pads_on, which only ever holds 1 or 0. as a
         * plain test, SHC writes TST and 2 of 144 words differ */
        if ((work->collision->flags & COLLISION_HIT) &&
            CheckPadReadMode() == TRUE) {
            scene_changer_go(work->ang.z);
            FreeTask(task);
        } else {
            EntryColliList(work);
        }
    } else {
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "-> ROTATION Y");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Z), "-> STAGE & ENTRANCE & ACT");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "-> SCALE X");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "-> SCALE Y");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "-> SCALE Z");
        debug_print_stage_name(NJM_LOCATION(17, 22), work->ang.z);
        njPushMatrix(NULL);
        njTranslate(NULL, work->pos.x,
                    work->pos.y + ((work->scl.y + 1.0F) * BOX_HALF_SIZE),
                    work->pos.z);
        TURN(njRotateY, work->ang.y);
        njScale(NULL, work->scl.x + 1.0F, work->scl.y + 1.0F,
                work->scl.z + 1.0F);
        SetMaterial(0.1F, 1.0F, 0.8F, 0.2F);
        late_DrawObject(&marker_box_object);
        late_DrawObjectClipEx(1);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}

static void scene_changer_destroy(struct task *task)
{
}
