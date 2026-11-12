/* @unit 8C0599C0-8C059D60 @data 8C1549C0-8C154A1C +egflags +pool32 */
/* the dash panel, O AXPNL or O DUSH PANEL in the object lists. a player
 * who touches it on the ground is sent off along its angles */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "object/dash_panel.h"
#include "object/models.h"
#include "object/placement.h"
#include "player/e102_effects.h"
#include "player/player.h"
#include "sound/sound.h"
#include "system/task.h"
#include "system/texture.h"
#include "system/util.h"
#include "vmu/vibration.h"
float njArcTan2(float y, float x);
float njFloor(float x);
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
extern NJS_OBJECT object_shadow[];
extern NJS_MODEL model_obj_ring_ring;
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
void kmiLogFileOpen(void *data);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
void ReleasePlayersTexture(int character);
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
void VibShot(int pad, int power, int freq, int time);

/* work->scl.x is the speed the panel sends a player off at, and scl.y the
 * steps that player's stick is then ignored for. for as many steps, the
 * panel won't send the same player again. at 0 or below, each takes its
 * default */
#define DASH_SPEED 14.0F
#define DASH_STEPS 60.0F

/* work->submode is the player the panel last sent off, or NO_PLAYER, which
 * is no player's number, before the first */
#define NO_PLAYER 13

#define VARS(work) ((struct dash_panel_vars *)&(work)->vars)
struct dash_panel_vars {
    NJS_ACTION *action;
    Float frame;
    Sint32 steps; /* the steps left before it may send that player again */
};

enum dash_panel_mode { DASH_PANEL_INIT, DASH_PANEL_RUN, DASH_PANEL_IDLE };
extern struct collision_shape dash_panel_shape[];
/* clang-format on */

static void dispAxelPanel(struct task *task)
{
    extern Bool ChkPause(void);
    struct task_work *work = task->work;

    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 30.0F)) {
        return;
    }
    SetRegularTexture();
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
    ((work->ang.y + ((Angle)(((180) * 65536.0) / 360.0)))
         ? (njRotateY)(((void *)0),
                       (work->ang.y + ((Angle)(((180) * 65536.0) / 360.0))))
         : (void)0);
    ds_ActionClip(((struct dash_panel_vars *)&(work)->vars)->action,
                  ((struct dash_panel_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
    if (!OnEdit(task) && !ChkPause()) {
        /* @hack spelling: the frame advanced inside the test, which compares
         * the sum in FR2 as it stores it (FCMP/GT FR2,FR1 at 0x8c05cc06);
         * advanced before it, SHC reloads the frame, the function runs 2
         * bytes long and 14 of 92 words differ */
        if ((VARS(work)->frame += 1.0F) >=
            VARS(work)->action->motion->nbFrame) {
            VARS(work)->frame = 0.0F;
        }
    }
}

static void dash_panel_destroy(struct task *task)
{
    FreeTask(task);
}

void ObjectAxelPanel(struct task *task)
{
    struct task_work *work = task->work;
    Sint8 player;
    Angle ang[3];

    if (CheckRangeOut(task)) {
        return;
    }
    if (OnEdit(task)) {
        njPrintC(NJM_LOCATION(20, 5), "SCL_X IS FOR SPEED.");
        njPrintC(NJM_LOCATION(20, 6), "IF 0.0F OR LOWER,");
        njPrintC(NJM_LOCATION(20, 7), "IT'S ");
        njPrintF(NJM_LOCATION(25, 7), DASH_SPEED, 2);
        njPrintC(NJM_LOCATION(33, 7), ".");
        njPrintC(NJM_LOCATION(20, 8), "SCL_Y IS FOR DISABLE TIME.");
        njPrintC(NJM_LOCATION(20, 9), "IF 0.0F OR LOWER,");
        njPrintC(NJM_LOCATION(20, 10), "IT'S ");
        njPrintF(NJM_LOCATION(25, 10), DASH_STEPS, 2);
        njPrintC(NJM_LOCATION(33, 10), ".");
        VARS(work)->action = &dash_panel_action;
        dispAxelPanel(task);
    } else {
        switch (work->mode) {
        case DASH_PANEL_INIT:
            work->mode = DASH_PANEL_RUN;
            work->submode = NO_PLAYER;
            VARS(work)->action = &dash_panel_action;
            task->destructor = dash_panel_destroy;
            task->draw = dispAxelPanel;
            CCL_Init(task, dash_panel_shape, COLLISION_OBJECT, 1, 1);
            if (work->scl.x <= 0.0F) {
                work->scl.x = DASH_SPEED;
            }
            if (work->scl.y <= 0.0F) {
                work->scl.y = DASH_STEPS;
            }
            break;
        case DASH_PANEL_RUN:
            dispAxelPanel(task);
            if (VARS(work)->steps > 0) {
                VARS(work)->steps--;
            }
            if (OnEdit(task)) {
                break;
            }
            if ((work->collision->flags & COLLISION_HIT) &&
                work->collision->hit->kind == COLLISION_PLAYER) {
                player = PLAYER_VARS(work->collision->hit->owner->work)->player;
                if ((playertwp[player]->flags & PLAYER_ON_LAND) &&
                    (VARS(work)->steps == 0 || work->submode != player)) {
                    NJS_VECTOR speed = {0.0F, 0.0F, 0.0F};

                    speed.x = work->scl.x;
                    ang[0] = work->ang.x;
                    ang[1] = work->ang.y;
                    ang[2] = work->ang.z;
                    VARS(work)->steps = ceilf(work->scl.y);
                    player_send_flying(player, &speed, ang, VARS(work)->steps);
                    dsPlay_oneshot(SE_DASH, 0, 0, 0);
                    VibShot(player, 4, 15, 0);
                    work->submode = player;
                    if (PLAYER_VARS(playertwp[player])->character ==
                        CHARACTER_E102) {
                        e102_set_skating(player);
                    }
                }
            }
            EntryColliList(work);
            break;
        case DASH_PANEL_IDLE:
            break;
        }
    }
}
