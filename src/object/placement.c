/* @unit 8C090EE0-8C091B60 +r04 +egflags +pool32 +asmfunc=clear_placements,add_placements,compact_placements */
/* placement: the objects an act's set file lists, and the tasks that run
 * them */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv00/object_list.h"
#include "adv0100/object_list.h"
#include "adv0130/object_list.h"
#include "adv02/object_list.h"
#include "adv03/object_list.h"
#include "al_garden00/object_list.h"
#include "al_garden01/object_list.h"
#include "al_garden02/object_list.h"
#include "al_race/object_list.h"
#include "b_chaos0/object_list.h"
#include "b_chaos2/object_list.h"
#include "b_chaos4/object_list.h"
#include "b_chaos6/object_list.h"
#include "b_chaos7/object_list.h"
#include "b_e101/object_list.h"
#include "b_e101_r/object_list.h"
#include "b_egm1/object_list.h"
#include "b_egm2/object_list.h"
#include "b_egm3/object_list.h"
#include "b_robo/object_list.h"
#include "camera/camera.h"
#include "debug/editor.h"
#include "minicart/object_list.h"
#include "object/placement.h"
#include "player/fishing.h"
#include "player/player.h"
#include "sboard/object_list.h"
#include "shooting/object_list.h"
#include "stage/stage.h"
#include "stg00/object_list.h"
#include "stg01/object_list.h"
#include "stg02/object_list.h"
#include "stg03/object_list.h"
#include "stg04/object_list.h"
#include "stg05/object_list.h"
#include "stg06/object_list.h"
#include "stg07/object_list.h"
#include "stg08/object_list.h"
#include "stg09/object_list.h"
#include "stg10/object_list.h"
#include "stg12/act0_object_list.h"
#include "stg12/act1_object_list.h"
#include "stg12/act2_object_list.h"
#include "stg12/act3_object_list.h"
#include "system/loader.h"
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
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
void SetObject(struct task *task);
Bool FUN_8c091852(struct task *task);
Bool FUN_8c0919d2(struct task *task);
void FUN_8c091a9e(struct task *task);
void FUN_8c091aca(struct task *task);
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
Bool OnEdit(struct task *task);
struct task *SetFishingCursorTask(struct task *big);
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
Bool ChkPause(void);
int thunk_FUN_8c09cbc0(char *name, void *dest);

/* the leave range, squared, of a task without a placement */
#define LEAVE_RANGE (410.0F * 410.0F)
/* the reach of player 1, squared. the manager places an object within it,
 * and a range check keeps a task within it while player 1 is Sonic */
#define NEAR_RANGE (40.0F * 40.0F)

/* each act's set file, where the loader puts it */
#define SET_FILE_0 ((struct set_file *)SET_AREA_0)
#define SET_FILE_1 ((struct set_file *)SET_AREA_1)
#define SET_FILE_2 ((struct set_file *)SET_AREA_2)
#define SET_FILE_3 ((struct set_file *)SET_AREA_3)
#define SET_FILE_4 ((struct set_file *)SET_AREA_4)
#define SET_FILE_5 ((struct set_file *)SET_AREA_5)

/* the practice stage's list, which acts that don't exist point at too */
#define PRACTICE (&practice_object_list)

enum manager_mode {
    MANAGER_INIT,
    MANAGER_PLACE, /* place the act's objects */
    MANAGER_CHANGE /* change to the act placement_change_act asks for */
};

/* the change's stages, one a step, in the manager's submode */
enum change_step { CHANGE_TAKE, CHANGE_WAIT, CHANGE_COMPACT, CHANGE_PLACE };

/* player_work, as a pair */
struct players {
    struct task_work *work[2];
};

void start_asked_change(struct task_work *work);
void InitStatusTable(void);
void ProcessStatusTable(void);
void SwitchStatusTable(struct task_work *work);
void clear_placements(void);
void add_placements(void);
void release_placements(void);
void compact_placements(void);
extern Bool act_ready;
extern Bool change_asked;
extern Bool boolOneShot;
extern int dat_8c1d722c;
extern struct set_file *set_files[43][8];
extern struct object_list *object_lists[43][8];
extern struct object_list *placement_list;
extern struct set_file *pObjEditTable;
extern Uint32 *placement_file_count;
extern struct set_entry *placement_entries;
extern Sint16 placement_count;
extern struct placement placements[1023];
extern Sint8 placed_stage;
extern Sint8 placed_act;

void SetObject(struct task *task)
{
    struct task_work *work = task->work;

    switch (work->mode) {
    case MANAGER_INIT:
        pObjEditTable = NULL;
        placed_stage = 0;
        placed_act = 0;
        act_ready = TRUE;
        change_asked = FALSE;
        InitStatusTable();
        work->mode = MANAGER_PLACE;
        boolOneShot = FALSE;
        break;
    case MANAGER_PLACE:
        ProcessStatusTable();
        start_asked_change(work);
        break;
    case MANAGER_CHANGE:
        SwitchStatusTable(work);
        break;
    }
}

/* start the act change placement_change_act asked for, if it asked */
void start_asked_change(struct task_work *work)
{
    if (change_asked) {
        work->mode = MANAGER_CHANGE;
        work->submode = CHANGE_TAKE;
        change_asked = FALSE;
    }
}

/* clear the placements, and take the object list and set file of the stage
 * and act the game is in. then add a placement for each entry */
void InitStatusTable(void)
{
    Uint16 stage_act = GetStageNumber();

    placed_stage = STAGE_OF(stage_act);
    placed_act = stage_act & 0xff;
    clear_placements();
    placement_list = object_lists[placed_stage][placed_act];
    pObjEditTable = set_files[placed_stage][placed_act];
    if (pObjEditTable == NULL) {
        placement_file_count = NULL;
        placement_entries = NULL;
    } else {
        placement_file_count = &pObjEditTable->count;
        placement_entries = (struct set_entry *)(pObjEditTable + 1);
    }
    add_placements();
}

/* TRUE when the point at pos is within range of x, y and z. TRUE too when
 * other isn't null and the point at it is within NEAR_RANGE of pos. FALSE
 * otherwise. range is squared */
Bool in_range_or_near(Float *pos, Float x, Float y, Float z, Float range,
                      Float *other)
{
    Float px;
    Float py;
    Float pz;
    Float distance;

    /* @hack spelling: pos and other each address a point's x, and the reads
     * walk on to its y and z, as the image's @R4+ and @R5+ loads do
     * (0x8c096240, 0x8c096268). ISO C leaves the walk undefined, since each
     * member is an object of its own. through NJS_POINT3 members, 45 of 45
     * words differ */
    px = *pos++;
    py = *pos++;
    pz = *pos;
    x -= px;
    distance = x * x;
    if (distance <= range) {
        y -= py;
        distance += y * y;
        if (distance <= range) {
            z -= pz;
            distance += z * z;
            if (distance <= range) {
                return TRUE;
            }
        }
    }
    if (other != NULL) {
        /* @hack spelling: range, reused for NEAR_RANGE, which keeps it in FR7
         * (FMOV.S @R0,FR7 at 0x8c09626c); with NEAR_RANGE in each test, SHC
         * loads it into FR5 and 4 of 45 words differ */
        range = NEAR_RANGE;
        px -= *other++;
        distance = px * px;
        if (distance <= range) {
            py -= *other++;
            distance += py * py;
            if (distance <= range) {
                pz -= *other;
                distance += pz * pz;
                if (distance <= range) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

/* TRUE when the point at pos is within range of x, y and z, else FALSE.
 * range is squared */
Bool in_range(NJS_POINT3 *pos, Float x, Float y, Float z, Float range)
{
    Float px;
    Float py;
    Float pz;
    Float distance;
    const char *rest;

    px = pos->x;
    /* @hack spelling: y and z read through a byte cursor past x, for the
     * image's @R4+ loads (FMOV.S @R4+ at 0x8c09629a, 0x8c09629e); through
     * the members, the function runs 4 bytes long and 23 of 23 words
     * differ */
    rest = (const char *)pos + sizeof(Float);
    py = *(const Float *)rest;
    rest += sizeof(Float);
    pz = *(const Float *)rest;
    x -= px;
    distance = x * x;
    if (distance <= range) {
        y -= py;
        distance += y * y;
        if (distance <= range) {
            z -= pz;
            distance += z * z;
            if (distance <= range) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

/* give a task to each active placement without a live one that is in
 * range of player 0, or within NEAR_RANGE of player 1. the camera stands in
 * for player 0 while there is none or the set editor is open */
void ProcessStatusTable2P(void)
{
    struct players *players;
    /* @hack redundant: register on other, x, y, z and the rest below, which
     * puts x, y and z in FR14, FR13 and FR15, range in FR12, other in R12
     * and placement in R11, in a 52-byte frame (0x8c0962e0 to 0x8c096320);
     * without them, 142 of 227 words differ */
    register Float *other;
    register Float x;
    register Float y;
    register Float z;
    Float range;
    register struct placement *placement;
    register struct set_entry *entry;
    register struct object_kind *kind;
    register struct task *task;
    register struct task_work *work;
    register int flags;
    int saved;
    register Bool near;
    int attr;
    register int i;

    /* @hack type: player_work read as a pair, so player 1 loads at @(4,R4)
     * from its base (0x8c096306); through player_work itself, 21 of 227
     * words differ */
    players = (struct players *)playertwp;
    if (players->work[0] == NULL || edit_mode == 1) {
        if (camera_twp == NULL) {
            return;
        }
        x = camera_twp->pos.x;
        y = camera_twp->pos.y;
        z = camera_twp->pos.z;
    } else {
        x = players->work[0]->pos.x;
        y = players->work[0]->pos.y;
        z = players->work[0]->pos.z;
    }
    /* @hack spelling: a loop around the test, which keeps z's load ahead of it
     * (FMOV.S @(R0,R5),FR15 at 0x8c096310); as an if, SHC loads z in the
     * test's delay slot and 4 of 227 words differ */
    while (players->work[1] == NULL) {
        goto no_other;
    }
    other = &players->work[1]->pos.x;
    goto have_other;
no_other:
    other = NULL;
have_other:
    placement = placements;
    for (i = placement_count - 1; i >= 0; placement++, i--) {
        flags = placement->flags;
        /* @hack spelling: PLACEMENT_ACTIVE tested as flags' sign bit, which SHC
         * tests with CMP/PZ (0x8c096364); as flags & PLACEMENT_ACTIVE, SHC
         * loads 0x8000 from the pool and 51 of 227 words differ */
        if (flags >= 0 || (flags & PLACEMENT_LIVE)) {
            continue;
        }
        entry = placement->entry;
        kind = &placement_list->kinds[entry->id & SET_KIND];
        saved = flags & PLACEMENT_SAVED;
        /* @hack spelling: the kind's tests as a loop of one pass, which the
         * kinds placed at any distance break out of. it keeps other in R12
         * and placement in R11 (0x8c096316, 0x8c096320); with a goto past
         * the tests, they take R14 and R13 and 124 of 227 words differ */
        do {
            attr = kind->attr;
            if (attr & KIND_RANGE) {
                range = kind->range;
            } else if (attr & KIND_ALWAYS) {
                /* -LEAVE_MARGIN gives the placement a leave.range of 0,
                 * which the range checks read as always in range */
                range = -LEAVE_MARGIN;
                near = TRUE;
                break;
            } else {
                range = PLACE_RANGE;
            }
            if ((attr & KIND_FIRST) && !boolOneShot) {
                near = TRUE;
                break;
            } else if (!saved) {
                near = in_range_or_near(&entry->pos.x, x, y, z, range, other);
            } else {
                near = in_range_or_near(&placement->leave.pose->pos.x, x, y, z,
                                        range, other);
            }
        } while (0);
        if (!near) {
            continue;
        }
        task = CreateElementalTask(kind->create, kind->level, kind->step);
        if (task != NULL) {
            placement->tasks++;
            placement->flags |= PLACEMENT_LIVE;
            task->placement = placement;
            work = task->work;
            if (work != NULL) {
                if (saved) {
                    work->pos = placement->leave.pose->pos;
                    work->ang = placement->leave.pose->ang;
                    work->scl = placement->leave.pose->scl;
                    Free(placement->leave.pose);
                    placement->flags &= ~PLACEMENT_SAVED;
                } else {
                    /* @hack type: the copies through &pos.x and &scl.x,
                     * which form each base in a register first (ADD #8,R1 at
                     * 0x8c096498, ADD #20,R3 at 0x8c0964a8); as entry->pos
                     * and entry->scl, SHC copies at offsets from entry and
                     * 61 of 227 words differ */
                    work->pos = *(NJS_POINT3 *)&entry->pos.x;
                    work->ang.x = entry->ang_x;
                    work->ang.y = entry->ang_y;
                    work->ang.z = entry->ang_z;
                    work->scl = *(NJS_POINT3 *)&entry->scl.x;
                }
                work->vars.p[0] = kind->param;
            }
            placement->leave.range = range + LEAVE_MARGIN;
            placement->task = task;
        }
    }
    boolOneShot = TRUE;
}

/* give a task to each active placement without a live one that is in
 * range of player 0. the camera stands in for player 0 while there is none
 * or the set editor is open. the camera also stands in during the alife
 * race, and for Big while the fishing game has the camera */
#ifdef GCC
/* inlined into placement_manager_step, its registers spill: 21k cycles a
 * frame more in Emerald Coast */
static void ProcessStatusTable1P(void) __attribute__((noinline));
#endif
void ProcessStatusTable1P(void)
{
    /* @hack redundant: register on center, x, y, z and the rest below, which
     * puts x, y and z in FR14, FR13 and FR15, the count in R9 and placement
     * in R12, in a 52-byte frame (0x8c096538 to 0x8c096596); without them,
     * 133 of 237 words differ */
    register struct task_work *center;
    register Float x;
    register Float y;
    register Float z;
    Float range;
    register struct placement *placement;
    register struct set_entry *entry;
    register struct object_kind *kind;
    register struct task *task;
    register struct task_work *work;
    register int flags;
    int saved;
    register Bool near;
    int attr;
    register int i;

    if (playertwp[0] == NULL || edit_mode == 1 || IN_STAGE(STAGE_ALIFE_RACE) ||
        (GetPlayerNumber() == CHARACTER_BIG &&
         (fishing_flags & FISHING_CAMERA))) {
        center = camera_twp;
        if (center == NULL) {
            return;
        }
    } else {
        center = playertwp[0];
    }
    x = center->pos.x;
    y = center->pos.y;
    z = center->pos.z;
    placement = placements;
    for (i = placement_count - 1; i >= 0; placement++, i--) {
        flags = placement->flags;
        /* @hack spelling: PLACEMENT_ACTIVE tested as the sign bit, as in
         * place_near_two (CMP/PZ at 0x8c0965e4); as flags & PLACEMENT_ACTIVE,
         * 51 of 237 words differ */
        if (flags >= 0 || (flags & PLACEMENT_LIVE)) {
            continue;
        }
        entry = placement->entry;
        kind = &placement_list->kinds[entry->id & SET_KIND];
        saved = flags & PLACEMENT_SAVED;
        /* @hack spelling: the kind's tests as a loop of one pass, as in
         * place_near_two. it keeps the 1 that both breaks store in near in
         * R8, set ahead of the loop (MOV #1,R8 at 0x8c09659a); with a goto
         * past the tests, 203 of 237 words differ */
        do {
            attr = kind->attr;
            if (attr & KIND_RANGE) {
                range = kind->range;
            } else if (attr & KIND_ALWAYS) {
                range = -LEAVE_MARGIN;
                near = TRUE;
                break;
            } else {
                range = PLACE_RANGE;
            }
            if ((attr & KIND_FIRST) && !boolOneShot) {
                near = TRUE;
                break;
            } else if (!saved) {
                near = in_range(&entry->pos, x, y, z, range);
            } else {
                near = in_range(&placement->leave.pose->pos, x, y, z, range);
            }
        } while (0);
        if (!near) {
            continue;
        }
        task = CreateElementalTask(kind->create, kind->level, kind->step);
        if (task != NULL) {
            placement->tasks++;
            placement->flags |= PLACEMENT_LIVE;
            task->placement = placement;
            work = task->work;
            if (work != NULL) {
                if (saved) {
                    work->pos = placement->leave.pose->pos;
                    work->ang = placement->leave.pose->ang;
                    work->scl = placement->leave.pose->scl;
                    Free(placement->leave.pose);
                    placement->flags &= ~PLACEMENT_SAVED;
                } else {
                    /* @hack type: the copies through &pos.x and &scl.x, as
                     * in place_near_two (ADD #8,R1 at 0x8c096714, ADD #20,R3
                     * at 0x8c096724); as entry->pos and entry->scl, 58 of
                     * 237 words differ */
                    work->pos = *(NJS_POINT3 *)&entry->pos.x;
                    work->ang.x = entry->ang_x;
                    work->ang.y = entry->ang_y;
                    work->ang.z = entry->ang_z;
                    work->scl = *(NJS_POINT3 *)&entry->scl.x;
                }
                work->vars.p[0] = kind->param;
            }
            placement->leave.range = range + LEAVE_MARGIN;
            placement->task = task;
        }
    }
}

/* place around player 0 alone while there is no player 1, the set editor
 * is open or player 1 is Tails, and around both otherwise */
void ProcessStatusTable(void)
{
    if (playertwp[1] == NULL || edit_mode == 1 ||
        PLAYER_VARS(playertwp[1])->character == CHARACTER_TAILS) {
        ProcessStatusTable1P();
    } else {
        ProcessStatusTable2P();
    }
    boolOneShot = TRUE;
}

/* the act change, a stage a step in submode. CHANGE_TAKE takes the new
 * act's object list and set file, and releases the old placements.
 * CHANGE_COMPACT compacts the placements, and CHANGE_PLACE adds the new
 * act's */
void SwitchStatusTable(struct task_work *work)
{
    switch (work->submode) {
    case CHANGE_TAKE:
        placement_list = object_lists[placed_stage][placed_act];
        pObjEditTable = set_files[placed_stage][placed_act];
        if (pObjEditTable == NULL) {
            placement_file_count = NULL;
            placement_entries = NULL;
        } else {
            placement_file_count = &pObjEditTable->count;
            placement_entries = (struct set_entry *)(pObjEditTable + 1);
        }
        release_placements();
        break;
    case CHANGE_COMPACT:
        compact_placements();
        break;
    case CHANGE_PLACE:
        act_ready = TRUE;
        work->mode = MANAGER_PLACE;
        add_placements();
        break;
    }
    work->submode++;
}

void clear_placements(void)
{
    Sint16 i;
    placement_count = 0;
    i = 1023 - 1;
    while (i >= 0) {
        placements[i].tasks = 0;
        placements[i].state = 0;
        placements[i].flags = 0;
        placements[i].entry = NULL;
        placements[i].leave.pose = NULL;
        i--;
    }
}

/* give each entry of the set file an active placement, and set
 * placement_count to their count, up to PLACEMENT_COUNT. i counts from
 * placement_count, but placement from placements[0]. the two agree only
 * because placement_count is 0 whenever add_placements runs */
void add_placements(void)
{
    struct set_entry *entry;
    struct placement *placement;
    Uint32 count;
    Sint16 first;
    int last;
    int i;
    if (placement_entries == ((void *)0)) {
        return;
    }
    entry = placement_entries;
    count = *placement_file_count;
    first = placement_count;
    last = first + count > 1023 ? 1023 : first + (int)count;
    /* @bug memory: the loop runs through last, one placement past the
     * entries (CMP/GT R2,R6 at 0x8c096950). at the cap, last is
     * PLACEMENT_COUNT, and the stores land past placements, on placed_stage,
     * placed_act and the bytes after them */
    for (placement = &placements[first], i = first; i <= last;
         i++, entry++, placement++) {
        placement->flags |= PLACEMENT_ACTIVE;
        placement->tasks = 0;
        placement->state = 0;
        placement->entry = entry;
    }
    placement_count = last;
}

/* stop placing every placement but the held ones, and destroy their live
 * tasks. it clears PLACEMENT_SAVED without freeing the saved pose */
void release_placements(void)
{
    int i;

    /* @bug logic: the held placements are lost. kept, their count, never
     * counts up, so placement_count ends at 0. compact_placements then has
     * nothing to compact, and add_placements writes the new act's
     * placements from placements[0] on, over any held one there. the image
     * keeps kept's 0 in the frame (MOV.L R7,@R15 at 0x8c096988) and stores
     * it as the count from there (MOV.L @R15,R3 at 0x8c0969b6, then
     * MOV.W R3,@R14 at 0x8c0969b8) */
    for (i = 0; i < placement_count; i++) {
        if (!(placements[i].flags & PLACEMENT_HELD)) {
            placements[i].flags &= ~(PLACEMENT_ACTIVE | PLACEMENT_KEEP |
                                     PLACEMENT_USED | PLACEMENT_SAVED);
            if (placements[i].flags & PLACEMENT_LIVE) {
                placements[i].task->step = DestroyTask;
            }
        }
    }
}

/* move the held placements to the front, and clear the rest */
void compact_placements(void)
{
    int kept;
    int i;

    for (kept = i = 0; i < placement_count; i++) {
        if (placements[i].flags & PLACEMENT_HELD) {
            placements[i].flags &= ~PLACEMENT_HELD;
            placements[kept] = placements[i];
            placements[kept].task->placement = &placements[kept];
            kept++;
        }
        if (!(placements[i].flags & 0x2)) {
            placements[i].flags = 0;
            placements[i].entry = NULL;
        } else {
            placements[i].flags = 0;
            placements[i].entry = NULL;
            Free(placements[i].leave.pose);
            placements[i].leave.pose = NULL;
        }
    }
    placement_count = kept;
}

void placement_reset(void)
{
    struct placement *placement;
    Uint32 count;
    int last;
    Sint16 flags;
    int i;

    if (placement_entries == NULL) {
        return;
    }
    count = *placement_file_count;
    last = placement_count + count > PLACEMENT_COUNT ? PLACEMENT_COUNT
                                                     : placement_count + count;
    placement = placements;
    for (i = 0; i < last; i++) {
        flags = placement->flags;
        if (!(flags & PLACEMENT_KEEP)) {
            placement->flags = PLACEMENT_ACTIVE;
            placement->state = 0;
        }
        placement++;
    }
}

void placement_change_act(Sint16 change)
{
    if (stage_playing()) {
        act_ready = FALSE;
        change_asked = TRUE;
        placed_act += change;
    }
}

Bool FUN_8c091852(struct task *task)
{
    if (task->placement != NULL) {
        return placement_far_from_camera_by(task, task->placement->leave.range);
    }
    return placement_far_from_camera_by(task, LEAVE_RANGE);
}

Bool placement_far_from_camera_by(struct task *task, Float range)
{
    struct placement *placement = task->placement;
    struct task_work *work;
    Float dx;
    Float dy;
    Float dz;
    Float distance;

    if (placement != NULL && (placement->flags & PLACEMENT_IN_RANGE)) {
        return FALSE;
    }
    if (range == 0.0F) {
        return FALSE;
    }
    work = task->work;
    dx = work->pos.x - camera_twp->pos.x;
    dy = work->pos.y - camera_twp->pos.y;
    dz = work->pos.z - camera_twp->pos.z;
    distance = (dx * dx) + (dy * dy) + (dz * dz);
    if (distance > range) {
        return TRUE;
    }
    return FALSE;
}

Bool CheckRangeOut(struct task *task)
{
    if (task->placement != NULL) {
        return CheckRangeOutWithR(task, task->placement->leave.range);
    }
    return CheckRangeOutWithR(task, LEAVE_RANGE);
}

Bool CheckRangeOutWithR(struct task *task, Float range)
{
    struct placement *placement = task->placement;
    struct task_work *viewer;
    Float x;
    Float y;
    Float z;

#ifdef GCC
    /* the split frame's second picture lets no task leave */
    if (frame_redrawing) {
        return FALSE;
    }
#endif
    if (placement != NULL && (placement->flags & PLACEMENT_IN_RANGE)) {
        return FALSE;
    }
    if (range == 0.0F) {
        return FALSE;
    }
    x = task->work->pos.x;
    y = task->work->pos.y;
    z = task->work->pos.z;
    /* @hack spelling: each viewer set in its test, which stores it to the frame
     * and loads it back (MOV.L R3,@R15 at 0x8c096c40, MOV.L @R15,R4 at
     * 0x8c096c42); set apart, it stays in R13 and 79 of 85 words differ */
    if ((viewer = camera_twp) != NULL &&
        in_range(&viewer->pos, x, y, z, range)) {
        return FALSE;
    }
    if ((viewer = playertwp[0]) != NULL &&
        in_range(&viewer->pos, x, y, z, range)) {
        return FALSE;
    }
    if (playertwp[1] != NULL &&
        PLAYER_VARS(playertwp[1])->character == CHARACTER_SONIC &&
        in_range(&playertwp[1]->pos, x, y, z, NEAR_RANGE)) {
        return FALSE;
    }
    task->step = DestroyTask;
    return TRUE;
}

Bool FUN_8c0919d2(struct task *task)
{
    if (task->placement != NULL) {
        return placement_try_leave_saving_by(task,
                                             task->placement->leave.range);
    }
    return placement_try_leave_saving_by(task, LEAVE_RANGE);
}

Bool placement_try_leave_saving_by(struct task *task, Float range)
{
    struct placement *placement = task->placement;
    struct placement_pose *pose;
    struct task_work *work;

    if (placement == NULL || !(placement->flags & PLACEMENT_IN_RANGE)) {
        if (CheckRangeOutWithR(task, range)) {
            /* @hack spelling: pose assigned in the test, which tests
             * heap_alloc's R0 and copies it to R4 in the BT/S's slot
             * (0x8c096d14, 0x8c096d18); assigned apart, SHC tests R4 and 3 of
             * 54 words differ */
            if ((pose = MAlloc(sizeof(*pose))) != NULL) {
                work = task->work;
                pose->pos = work->pos;
                pose->ang = work->ang;
                pose->scl = work->scl;
                /* @bug memory: a task without a placement gets here too, and
                 * the pose and PLACEMENT_SAVED are stored through its null
                 * placement (0x8c096d42, 0x8c096d4a) */
                task->placement->leave.pose = pose;
                task->placement->flags |= PLACEMENT_SAVED;
            }
            task->step = DestroyTask;
            return TRUE;
        }
    }
    return FALSE;
}

void placement_set_used(struct task *task)
{
    task->placement->flags |= PLACEMENT_USED;
}

void FUN_8c091a9e(struct task *task)
{
    task->placement->flags |= PLACEMENT_KEEP;
}

int placement_used(struct task *task)
{
    return task->placement->flags & PLACEMENT_USED;
}

void placement_hold(struct task *task)
{
    task->placement->flags |= PLACEMENT_HELD;
}

int placement_held(struct task *task)
{
    return task->placement->flags & PLACEMENT_HELD;
}

void FUN_8c091aca(struct task *task)
{
    task->placement->flags &= ~PLACEMENT_ACTIVE;
    task->placement->flags &= ~PLACEMENT_LIVE;
}

void DeadOut(struct task *task)
{
    task->placement->flags &= ~PLACEMENT_ACTIVE;
    task->placement->flags &= ~PLACEMENT_LIVE;
    task->step = DestroyTask;
}

Uint16 placement_get_kind(struct task *task)
{
    return task->placement->entry->id & SET_KIND;
}

void placement_set_state(struct task *task, Sint8 state)
{
    if (task->placement != NULL) {
        task->placement->state = state;
    }
}

Sint8 placement_get_state(struct task *task)
{
    if (task->placement != NULL) {
        return task->placement->state;
    }
    /* @bug uninitialized: without a placement, the function returns the R0
     * its caller left, as the BT at 0x8c096e34 skips to the RTS */
#ifdef GCC
    /* repairs the missing return the tag names: with no placement, GCC
     * returns 0 */
    return 0;
#endif
    /* NOLINTNEXTLINE(clang-diagnostic-return-type) */
}
