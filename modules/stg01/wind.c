/* @unit 0C90CDA0-0C90D200 @data 0C9117B4-0C911804 +r04 +egflags +pool32 */
/* O BEWIND box of rising wind that lifts player 0 */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "object/placement.h"
#include "player/player.h"
#include "stg01/wind.h"
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
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
extern NJS_POINT3 beach_wind_cube[24];
extern NJS_COLOR beach_wind_white[24];
extern NJS_POINT3COL beach_wind_box[1];
extern NJS_COLOR beach_wind_yellow[24];
extern NJS_POINT3COL beach_wind_origin[1];

/* a unit cube about the origin: its twelve edges, each a pair of points */
#define BOX_MIN 10.0F
#define BOX_MAX 200.0F
#define POWER(work) ((Uint8)(work)->ang.x)
#define POWER_MIN 1
#define POWER_MAX 8
#define VARS(work) ((struct beach_wind_vars *)&(work)->vars)
#define DWELL_MAX 32
#define DWELL_WAIT 2
#define SLICE_GAP 128

/* the mode is WIND_EDIT while the set editor holds the task */
enum beach_wind_mode { WIND_INIT = 0, WIND_BLOW = 2, WIND_EDIT = 9 };

/* the step holds scl's sizes within BOX_MIN to BOX_MAX, and the power within
 * POWER_MIN to POWER_MAX. it does so as the task starts and in the set
 * editor */
/* the wind's power, ang.x's low byte. the set editor's label says 1 to 10 */
struct beach_wind_vars {
    /* dwell[i] counts the steps in a row the loop's pass i has found its
     * player in the box. it stops at DWELL_MAX */
    Uint8 dwell[4];
    Uint8 unk_04[2];
    /* in the set editor, its low 7 bits are the lowest slice's height above
     * the box's bottom. it rises by the power each step, so the slices climb.
     * the low bits wrap at SLICE_GAP */
    Sint8 slice;
    Uint8 unk_07;
    Uint8 unk_08[4];
};

/* the wind lifts a player only after more than this many steps in a row in
 * the box */

/* the set editor draws level slices of the box this far apart */

/* each step player 0 is in the box, put it in the updraft. after more than
 * DWELL_WAIT steps there, the updraft pushes it. the push is (power - its
 * upward speed) / 10 */
void beach_wind_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player;
    struct task_motion *motion;
    struct player *record;
    Uint8 i;
    Float top;
    Float bottom;
    Float y;
    Float lift;
    Float ax;
    Float az;
    Float bx;
    Float bz;
    Float half_ax;
    Float half_az;
    Float half_bx;
    Float half_bz;
    Float edge_x;
    Float edge_z;
    Float dx;
    Float dz;
    Angle ang;

    work->tick = 1;
    if (CheckRangeOut(task)) {
        return;
    }
    top = work->pos.y + (work->scl.y * 0.5F);
    bottom = work->pos.y - (work->scl.y * 0.5F);
    if (work->mode == WIND_INIT || work->mode == WIND_EDIT) {
        if (work->scl.x < BOX_MIN) {
            work->scl.x = BOX_MIN;
        } else if (work->scl.x > BOX_MAX) {
            work->scl.x = BOX_MAX;
        }
        if (work->scl.y < BOX_MIN) {
            work->scl.y = BOX_MIN;
        } else if (work->scl.y > BOX_MAX) {
            work->scl.y = BOX_MAX;
        }
        if (work->scl.z < BOX_MIN) {
            work->scl.z = BOX_MIN;
        } else if (work->scl.z > BOX_MAX) {
            work->scl.z = BOX_MAX;
        }
        if (POWER(work) < POWER_MIN) {
            work->ang.x = POWER_MIN;
        } else if (POWER(work) > POWER_MAX) {
            work->ang.x = POWER_MAX;
        }
    }
    switch (work->mode) {
    case WIND_INIT:
        work->vars.l[0] = 0;
        work->mode = WIND_BLOW;
        VARS(work)->unk_08[0] = 0;
        break;
    case WIND_BLOW:
        /* @bug memory: the loop steps player and motion by their own
         * sizes, so its second pass reads the 64 bytes after player 0's work
         * and motion, not player 1's. the image loads player_motion[0] and
         * player_work[0] at 0x0c90d520 and 0x0c90d522, and steps them with
         * ADD #64 at 0x0c90d6ea and 0x0c90d6ee. with player_work[0] null, the
         * second pass reads a position at address 96 (0x0c90d56a) */
        player = playertwp[0];
        motion = playermwp[0];
        for (i = 0; i < 2; i++, player++, motion++) {
            if (player == NULL) {
                continue;
            }
            if (player->pos.y > top || player->pos.y < bottom) {
                VARS(work)->dwell[i] = 0;
                continue;
            }
            /* a is the box's x edge and b its z edge, each turned by
             * -ang.y */
            ax = njCos(work->ang.y) * work->scl.x;
            az = njSin(work->ang.y) * work->scl.x;
            bx = -(njSin(work->ang.y) * work->scl.z);
            bz = njCos(work->ang.y) * work->scl.z;
            half_ax = ax * 0.5F;
            half_az = az * 0.5F;
            half_bx = bx * 0.5F;
            half_bz = bz * 0.5F;
            /* a player outside any of the four sides is out of the box */
            edge_x = -bx;
            edge_z = -bz;
            dx = player->pos.x - work->pos.x - half_ax - half_bx;
            dz = player->pos.z - work->pos.z - half_az - half_bz;
            if ((edge_z * dx) - (edge_x * dz) < 0.0F) {
                VARS(work)->dwell[i] = 0;
                continue;
            }
            edge_x = -ax;
            edge_z = -az;
            dx = player->pos.x - work->pos.x - half_ax + half_bx;
            dz = player->pos.z - work->pos.z - half_az + half_bz;
            if ((edge_z * dx) - (edge_x * dz) < 0.0F) {
                VARS(work)->dwell[i] = 0;
                continue;
            }
            edge_x = bx;
            edge_z = bz;
            dx = player->pos.x - work->pos.x + half_ax + half_bx;
            dz = player->pos.z - work->pos.z + half_az + half_bz;
            if ((edge_z * dx) - (edge_x * dz) < 0.0F) {
                VARS(work)->dwell[i] = 0;
                continue;
            }
            edge_x = ax;
            edge_z = az;
            dx = player->pos.x - work->pos.x + half_ax - half_bx;
            dz = player->pos.z - work->pos.z + half_az - half_bz;
            if ((edge_z * dx) - (edge_x * dz) < 0.0F) {
                VARS(work)->dwell[i] = 0;
                continue;
            }
            if (++VARS(work)->dwell[i] > DWELL_MAX) {
                VARS(work)->dwell[i] = DWELL_MAX;
            }
            record = motion->record;
            if (VARS(work)->dwell[i] > DWELL_WAIT) {
                lift = (POWER(work) - record->speed.y) * 0.1F;
            } else {
                lift = 0.0F;
            }
            player_updraft(i, 0.0F, lift, 0.0F);
        }
        break;
    case WIND_EDIT:
        /* in the set editor, draw a unit cube at the position, the box, and
         * the box's slices. the slices rise by the power each step. then label
         * the fields. once the editor lets the task go, it starts again */
        if (!OnEdit(task)) {
            work->mode = WIND_INIT;
        }
        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        njDrawLine3D(beach_wind_origin, 12, 0);
        TURN_VIA(njRotateY, -work->ang.y, ang);
        njScale(NULL, work->scl.x, work->scl.y, work->scl.z);
        njDrawLine3D(beach_wind_box, 12, 0);
        late_DrawObjectClipEx(1);
        VARS(work)->slice += work->ang.x;
        y = bottom + (VARS(work)->slice & (SLICE_GAP - 1));
        while (y < top) {
            njPushMatrix(NULL);
            njTranslate(NULL, work->pos.x, y, work->pos.z);
            TURN_VIA(njRotateY, -work->ang.y, ang);
            njScale(NULL, work->scl.x, 0.0F, work->scl.z);
            njDrawLine3D(beach_wind_box, 12, 0);
            late_DrawObjectClipEx(1);
            y += SLICE_GAP;
        }
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_X), "<- POWER{ 1-10}");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "<- COLLIRotateY");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- COLLISIZE X");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "<- COLLISIZE Y");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "<- COLLISIZE Z");
        return;
    }
    if (OnEdit(task)) {
        work->mode = WIND_EDIT;
    }
}
