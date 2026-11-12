/* @unit 0C90B3E0-0C90B7A0 +egflags +pool32 */
/* sea surface of acts 1 and 2, which follows player 0 */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/world.h"
#include "draw/tree.h"
#include "player/player.h"
#include "stg01/beach.h"
#include "stg01/sea_surface.h"
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
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
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
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

#define SURFACE_Y (-1.5F)
/* the surface follows player 0 in whole strides of this many units in x
 * and z */
#define STRIDE 25.0F
/* the texture changes once TASK_TIMER(work) passes TEXTURE_WAIT, every 5
 * steps, through TEXTURES in turn */
#define TEXTURE_WAIT 4
#define TEXTURES 10

#define VARS(work) ((struct beach_sea_surface_vars *)&(work)->vars)
#define TEXTURE(work) ((work)->tick)
#define HIDE_RANGE 300.0F
struct beach_sea_surface_vars {
    NJS_OBJECT *plane; /* act 1's plane in the collision world, or NULL */
};
extern NJS_POINT3 beach_sea_surface_hide_point;

/* the surface's submodes. only act 2's step hides it */
enum { SURFACE_SHOWN, SURFACE_HIDDEN };
extern struct task *WaveTask;

void beach_sea_surface_act1_init(struct task *task);
void Exec2(struct task *task);
void ObjectBeachWaveBG3(struct task *task);
void Exec3(struct task *task);
void beach_sea_surface_draw(struct task *task);
void beach_sea_surface_destroy(struct task *task);

void CreateBeachWaveBG(int mode)
{
    struct task_work *work;

    if (mode == BEACH_ACT1) {
        WaveTask = CreateElementalTask(TASK_WORK | TASK_FORCE, 3,
                                       beach_sea_surface_act1_init);
        work = WaveTask->work;
        work->mode = BEACH_ACT1;
    } else if (mode == BEACH_ACT2) {
        WaveTask = CreateElementalTask(TASK_WORK, 3, ObjectBeachWaveBG3);
        work = WaveTask->work;
        work->mode = BEACH_ACT2;
    }
}

void DestructBeachWaveBG(void)
{
    FreeTask(WaveTask);
}

/* put the plane in the collision world as moving water, where the surface
 * is */
void beach_sea_surface_act1_init(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *plane;

    work->pos.y = SURFACE_Y;
    work->ang.x = 0;
    work->ang.y = 0;
    work->ang.z = 0;
    work->submode = SURFACE_SHOWN;
    TASK_TIMER(work) = 0;
    TEXTURE(work) = 0;
    VARS(work)->plane = plane = GetMobileLandObject();
    plane->evalflags = NJD_EVAL_BREAK;
    plane->scl[0] = 1.0F;
    plane->scl[1] = 1.0F;
    plane->scl[2] = 1.0F;
    plane->ang[0] = 0;
    plane->ang[1] = work->ang.y;
    plane->ang[2] = 0;
    plane->pos[0] = work->pos.x;
    plane->pos[1] = work->pos.y;
    plane->pos[2] = work->pos.z;
    plane->model = beach_sea_surface_plane_object.model;
    plane->child = NULL;
    plane->sibling = NULL;
    RegisterCollisionEntry(WORLD_MOVES | WORLD_WATER, task, plane);
    work->flags |= WORLD_TESTED;
    task->step = Exec2;
    task->draw = beach_sea_surface_draw;
    task->destructor = beach_sea_surface_destroy;
}

/* step the surface's texture, and move the surface and its plane to
 * follow player 0 */
void Exec2(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 player;
    Float x;
    Float z;
    Float player_x;
    Float player_z;
    Float strides_x;
    Float strides_z;

    TASK_TIMER(work)++;
    if (TASK_TIMER(work) > TEXTURE_WAIT) {
        TASK_TIMER(work) = 0;
        beach_sea_surface_object.model->mats->attr_texId = TEXTURE(work);
        TEXTURE(work)++;
        TEXTURE(work) %= TEXTURES;
    }
    GetPlayerPosition(0, 0, &player, NULL);
    x = work->pos.x;
    z = work->pos.z;
    player_x = player.x;
    player_z = player.z;
    strides_x = njRoundOff((player_x - x) * (1.0F / STRIDE));
    strides_z = njRoundOff((player_z - z) * (1.0F / STRIDE));
    x += strides_x * STRIDE;
    z += strides_z * STRIDE;
    work->pos.x = x;
    work->pos.z = z;
    VARS(work)->plane->pos[0] = x;
    VARS(work)->plane->pos[2] = z;
    beach_sea_surface_draw(task);
}

void ObjectBeachWaveBG3(struct task *task)
{
    struct task_work *work = task->work;

    work->pos.y = SURFACE_Y;
    work->ang.x = 0;
    work->ang.y = 0;
    work->ang.z = 0;
    work->submode = SURFACE_SHOWN;
    TASK_TIMER(work) = 0;
    TEXTURE(work) = 0;
    VARS(work)->plane = NULL;
    task->step = Exec3;
    task->draw = beach_sea_surface_draw;
    task->destructor = beach_sea_surface_destroy;
}

/* as act 1's step, without a plane. it also hides the surface near the hide
 * point */
void Exec3(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 player;
    Float x;
    Float z;
    Float player_x;
    Float player_z;
    Float strides_x;
    Float strides_z;

    TASK_TIMER(work)++;
    if (TASK_TIMER(work) > TEXTURE_WAIT) {
        TASK_TIMER(work) = 0;
        beach_sea_surface_object.model->mats->attr_texId = TEXTURE(work);
        TEXTURE(work)++;
        TEXTURE(work) %= TEXTURES;
    }
    if (player_in_range(&beach_sea_surface_hide_point, HIDE_RANGE)) {
        work->submode = SURFACE_HIDDEN;
    } else {
        work->submode = SURFACE_SHOWN;
    }
    GetPlayerPosition(0, 0, &player, NULL);
    x = work->pos.x;
    z = work->pos.z;
    player_x = player.x;
    player_z = player.z;
    strides_x = njRoundOff((player_x - x) * (1.0F / STRIDE));
    strides_z = njRoundOff((player_z - z) * (1.0F / STRIDE));
    x += strides_x * STRIDE;
    z += strides_z * STRIDE;
    work->pos.x = x;
    work->pos.z = z;
    beach_sea_surface_draw(task);
}

void beach_sea_surface_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (work->submode == SURFACE_SHOWN) {
        njSetTexture_jp(&beach_sea_surface_texlist);
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        late_DrawObject(&beach_sea_surface_object);
        late_DrawObjectClipEx(1);
    }
}

void beach_sea_surface_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (VARS(work)->plane != NULL) {
        WithdrawCollisionEntry(task, VARS(work)->plane);
        ReleaseMobileLandObject(VARS(work)->plane);
    }
}
