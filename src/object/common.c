/* @unit 8C0583E0-8C0599C0 @data 8C154928-8C1549C0 @ddata 8C1B9598-8C1B95B4 +r04 +egflags +pool32 +align0=carry_set_kind +poolafter=thunk_FUN_8c0829cc,FUN_8c0585a4,ObjectMovableMRegularExecute,InitObjects,model_start_solid_scaled,world_model_draw,action_destroy +poolbra=FUN_8c058438:7,ObjectMovableSRegularExecute:3,ObjectMovableSRegularExecute:8,ObjectMovableMRegularExecute:4,object_tree_remove:1,FUN_8c0591fc:1,ObjectGCollision:5 +poolkeep=model_draw */
/* common: what the menus chose, the game's calls on the npc, battles and
 * title cards, and the starts and steps the objects share */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "collision/collision.h"
#include "collision/world.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/tree.h"
#include "object/capsule.h"
#include "object/common.h"
#include "object/item_box_air.h"
#include "object/panel.h"
#include "object/placement.h"
#include "object/rocket.h"
#include "object/switch.h"
#include "object/target.h"
#include "player/npc.h"
#include "player/player.h"
#include "player/rival.h"
#include "save/save.h"
#include "system/frame.h"
#include "system/math.h"
#include "system/pad.h"
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
void nwEditWinPrintf(Int loc, const char *fmt, ...);
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
void pdExecPeripheralServerUser(void);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
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
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void SetMleriRangeRad(Float radius);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ObjectReleaseBox(struct task *task);
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
void FUN_8c058438(int unused, struct task *player);
int FUN_8c0584e6(int character);
void FUN_8c0584fa(void);
void FUN_8c058502(void);
int FUN_8c05859c(void);
struct save *FUN_8c0585a4(void);
Bool FUN_8c058fba(struct task *task);
Bool FUN_8c059108(struct task *task);
Bool FUN_8c0591fc(struct task *task);
Bool FUN_8c0596ee(struct task *task);
void FUN_8c059854(struct task_work *work);
void PutItem_ItemBoxAir(NJS_POINT3 *pos, enum item_kind kind);
void ObjectItemboxAir(struct task *task);
void ObjectJumpPanel(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void ObjectSwitch(struct task *task);
struct task *FUN_8c083ebc(struct battle *battle);
Float ghUnitVector(NJS_VECTOR *vector, NJS_VECTOR *out);
Float CalcDistance2(NJS_POINT3 *from, NJS_POINT3 *to);
Uint32 ghBlendColors(Uint32 color, Uint32 by);
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
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

#define SMALL_RADIUS 2.5F
#define SMALL_CENTER 2.48F
#define LARGE_RADIUS 5.0F
#define LARGE_CENTER 4.9F
#define WORLD_MODEL_REACH 16.0F
static void object_tree_destroy(struct task *task);
void object_tree_draw(struct task *task);
void model_destroy(struct task *task);
void model_draw(struct task *task);
void model_draw_scaled(struct task *task);
void FUN_8c0592a4(struct task *task);
static void model_step_solid_scaled(struct task *task);
void world_model_step(struct task *task);
void world_model_draw(struct task *task);
void world_model_destroy(struct task *task);
void world_model_destroy_tree(struct task *task);
void action_destroy(struct task *task);
void action_step(struct task *task);
void action_draw(struct task *task);
extern int npc_choice;
static char *npc_names[7] = {
    "1.5P",
    "BOSS SONIC vs KNUCKLES",
    "BOSS SONIC vs E102",
    "BOSS KNUCKLES vs SONIC",
    "BOSS KNUCKLES vs MILES",
    "BOSS E102 vs SONIC",
    "BOSS E102 vs MILES",
};
extern struct AdvertiseWork AdvertiseWork;
extern Sint32 dat_8c793fc4;
extern struct save menu_saves[3];
extern struct task *npc_task;
extern Bool npc_disabled;
extern enum battle_outcome battle_result;
extern Sint32 dat_8c794db4;
extern NJS_OBJECT *object_tree;
extern NJS_OBJECT *object_tree_last;

void npc_choose(Uint32 loc)
{
    int count = sizeof(npc_names) / sizeof(npc_names[0]);
    if (per[1]->press & (1 << 7)) {
        npc_choice++;
        if (npc_choice >= count) {
            npc_choice = 0;
        }
    } else if (per[1]->press & (1 << 6)) {
        npc_choice--;
        if (npc_choice < 0) {
            npc_choice = count - 1;
        }
    }
    nwEditWinPrintf(loc, "NPC [%s]", npc_names[npc_choice]);
}

void FUN_8c058438(int unused, struct task *player)
{
    struct battle battle;

    if (npc_choice == 0) {
        NpcMilesSet(player);
        return;
    }
    switch (npc_choice) {
    case 1:
        battle.kind = BATTLE_SONIC_KNUCKLES;
        break;
    case 2:
        battle.kind = BATTLE_SONIC_E102;
        break;
    case 3:
        battle.kind = BATTLE_KNUCKLES_SONIC;
        break;
    case 4:
        battle.kind = BATTLE_KNUCKLES_TAILS;
        break;
    case 5:
        battle.kind = BATTLE_E102_SONIC;
        break;
    case 6:
        battle.kind = BATTLE_E102_TAILS;
        break;
    default:
        /* npc_choose keeps npc_choice within npc_names. any other value
         * spins here forever (BRA to itself at 0x8c05b5e0) */
        while (1) {
        }
    }
    battle.player = player;
    battle.rival = NULL;
    battle.unk_0c = 0;
    battle.finish = ((void *)0);
    FUN_8c083ebc(&battle);
    rival_begin(&battle);
}

int FUN_8c0584e6(int character)
{
    /* @hack spelling: the story through a local, which SHC loads into R4
     * (MOV.B @R3,R4 at 0x8c05b608); returned directly, it loads into R0 and
     * 2 of 4 words differ */
    Uint8 story = AdvertiseWork.story;

    return story;
}

Bool thunk_FUN_8c081ba6(void)
{
    return npc_remove_tails();
}

struct task *thunk_FUN_8c081bec(void)
{
    return npc_create_tails();
}

void FUN_8c0584fa(void)
{
    npc_disabled = TRUE;
}

void FUN_8c058502(void)
{
    npc_disabled = FALSE;
}

struct task *thunk_FUN_8c08395e(struct battle *battle)
{
    return rival_begin(battle);
}

struct task *thunk_FUN_8c083ebc(struct battle *battle)
{
    return FUN_8c083ebc(battle);
}

void thunk_FUN_8c083f7e(struct battle *battle)
{
    rival_remove(battle);
}

void battle_set_outcome(enum battle_outcome outcome)
{
    battle_result = outcome;
}

enum battle_outcome battle_outcome(void)
{
    return battle_result;
}

Sint16 thunk_FUN_8c0829cc(int frames)
{
    return StageNameModeInit(frames);
}

Sint16 thunk_FUN_8c082b9a(int unused)
{
    return StageNameMode();
}

void boot_finish(void)
{
    fill_bytes(&AdvertiseWork, 0, sizeof(AdvertiseWork));
    npc_task = NULL;
}

int FUN_8c05859c(void)
{
    return AdvertiseWork.mode;
}

struct save *FUN_8c0585a4(void)
{
    return &menu_saves[AdvertiseWork.save];
}

Bool carry_set_kind(struct task_work *work, struct task_motion *motion,
                    enum carry_kind kind)
{
    if (motion == NULL) {
        return FALSE;
    }
    switch (kind) {
    case CARRY_KIND_SMALL:
        CARRY_REACH(motion) = 5.0F;
        motion->gravity = 0.02F;
        work->flags |= CARRY_HOLDABLE | PLAYER_CAN_CARRY;
        break;
    case CARRY_KIND_MEDIUM:
        CARRY_REACH(motion) = 20.0F;
        motion->gravity = 0.1F;
        work->flags |= CARRY_HOLDABLE | PLAYER_CAN_CARRY | PLAYER_CAN_PUSH;
        break;
    case CARRY_KIND_LARGE:
        CARRY_REACH(motion) = 30.0F;
        motion->gravity = 0.2F;
        work->flags |= CARRY_HOLDABLE | PLAYER_CAN_CARRY | PLAYER_CAN_PUSH;
        break;
    case CARRY_KIND_SHAKE:
        CARRY_REACH(motion) = 5.0F;
        motion->gravity = 1.0F;
        work->flags |= CARRY_HOLDABLE | PLAYER_CAN_SHAKE;
        break;
    default:
        return FALSE;
    }
    work->id = kind;
    return TRUE;
}

void ObjectMovableSRegularExecute(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    NJS_VECTOR speed;
    NJS_VECTOR offset;
    NJS_POINT3 pos;
    struct angles ang;
    int hit;

    if (!(work->flags & CARRY_HELD)) {
        if (work->flags & CARRY_GROUND) {
            motion->accel.y = 0.0F;
            motion->speed.y = 0.0F;
        } else {
            motion->accel.y = -motion->gravity;
        }
        if (!(work->flags & CARRY_GROUND)) {
            motion->speed.x *= 0.996F;
            motion->speed.z *= 0.996F;
        } else {
            motion->speed.x *= 0.1F;
            motion->speed.z *= 0.1F;
            if (njAbs(motion->speed.x) <= 1.0F) {
                motion->speed.x = 0.0F;
            }
            if (njAbs(motion->speed.z) <= 1.0F) {
                motion->speed.z = 0.0F;
            }
        }
        motion->speed.y += motion->accel.y;
        if (motion->speed.y > 6.0F) {
            motion->speed.y = 6.0F;
        } else if (motion->speed.y < -6.0F) {
            motion->speed.y = -6.0F;
        }
        pos = work->pos;
        speed.x = motion->speed.x + motion->accel.x;
        speed.y = motion->speed.y + motion->accel.y;
        speed.z = motion->speed.z + motion->accel.z;
        ang = work->ang;
        offset.x = 0.0F;
        offset.y = SMALL_CENTER;
        offset.z = 0.0F;
        object_turn(work, &offset);
        njAddVector(&pos, &offset);
        if (!OnEdit(task)) {
            hit =
                world_sweep_ball(&pos, &speed, &ang, WORLD_WATER, SMALL_RADIUS);
            if (((work->flags & CARRY_WALLS) && (hit & HIT_GROUND)) ||
                (!(work->flags & CARRY_WALLS) && hit)) {
                work->pos.x = pos.x + speed.x;
                work->pos.y = pos.y + speed.y;
                work->pos.z = pos.z + speed.z;
                work->ang = ang;
                offset.x = 0.0F;
                offset.y = SMALL_RADIUS;
                offset.z = 0.0F;
                object_turn(work, &offset);
                njSubVector(&work->pos, &offset);
                work->flags |= CARRY_GROUND;
            } else {
                if ((work->flags & CARRY_WALLS) && (hit & HIT_WALL)) {
                    work->pos.x = pos.x + speed.x;
                    work->pos.y = pos.y + speed.y;
                    work->pos.z = pos.z + speed.z;
                    offset.x = 0.0F;
                    offset.y = SMALL_RADIUS;
                    offset.z = 0.0F;
                    object_turn(work, &offset);
                    njSubVector(&work->pos, &offset);
                    motion->speed.x *= 0.1F;
                    motion->speed.z *= 0.1F;
                } else {
                    work->pos.x += motion->speed.x;
                    work->pos.y += motion->speed.y;
                    work->pos.z += motion->speed.z;
                }
                work->ang.x = 0;
                work->ang.z = 0;
                work->flags &= ~CARRY_GROUND;
            }
        }
    } else {
        work->flags &= ~CARRY_GROUND;
    }
    if (!(work->flags & CARRY_HELD) && !OnEdit(task)) {
        EntryColliList(work);
        ObjectSetupInput(work, motion);
    }
}

void ObjectMovableMRegularExecute(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;
    NJS_VECTOR speed;
    NJS_VECTOR offset;
    NJS_POINT3 pos;
    struct angles ang;
    Float fall;
    int hit;

    if (!(work->flags & CARRY_HELD)) {
        if (work->flags & CARRY_GROUND) {
            fall = 0.0F;
            motion->speed.y = 0.0F;
        } else {
            fall = -motion->gravity;
        }
        if (!(work->flags & CARRY_GROUND)) {
            motion->speed.x *= 0.98F;
            motion->speed.z *= 0.98F;
        } else {
            motion->speed.x *= 0.1F;
            motion->speed.z *= 0.1F;
            if (njAbs(motion->speed.x) <= 1.0F) {
                motion->speed.x = 0.0F;
            }
            if (njAbs(motion->speed.z) <= 1.0F) {
                motion->speed.z = 0.0F;
            }
        }
        motion->speed.y += fall;
        if (motion->speed.y > 6.0F) {
            motion->speed.y = 6.0F;
        } else if (motion->speed.y < -6.0F) {
            motion->speed.y = -6.0F;
        }
        if (!(work->flags & CARRY_GROUND) || !loop_count) {
            pos = work->pos;
            speed.x = motion->speed.x + motion->accel.x;
            speed.y = motion->speed.y + motion->accel.y;
            speed.z = motion->speed.z + motion->accel.z;
            ang = work->ang;
            offset.x = 0.0F;
            offset.y = LARGE_CENTER;
            offset.z = 0.0F;
            object_turn(work, &offset);
            njAddVector(&pos, &offset);
            if (!OnEdit(task)) {
                hit = world_sweep_ball(&pos, &speed, &ang, WORLD_WATER,
                                       LARGE_RADIUS);
                if (((work->flags & CARRY_WALLS) && (hit & HIT_GROUND)) ||
                    (!(work->flags & CARRY_WALLS) && hit)) {
                    work->pos.x = pos.x + speed.x;
                    work->pos.y = pos.y + speed.y;
                    work->pos.z = pos.z + speed.z;
                    work->ang = ang;
                    offset.x = 0.0F;
                    offset.y = LARGE_RADIUS;
                    offset.z = 0.0F;
                    object_turn(work, &offset);
                    njSubVector(&work->pos, &offset);
                    work->flags |= CARRY_GROUND;
                } else {
                    if ((work->flags & CARRY_WALLS) && (hit & HIT_WALL)) {
                        work->pos.x = pos.x + speed.x;
                        work->pos.y = pos.y + speed.y;
                        work->pos.z = pos.z + speed.z;
                        offset.x = 0.0F;
                        offset.y = LARGE_RADIUS;
                        offset.z = 0.0F;
                        object_turn(work, &offset);
                        njSubVector(&work->pos, &offset);
                    } else {
                        work->pos.x += motion->speed.x;
                        work->pos.y += motion->speed.y;
                        work->pos.z += motion->speed.z;
                    }
                    work->ang.x = 0;
                    work->ang.z = 0;
                    work->flags &= ~CARRY_GROUND;
                }
            }
        }
    } else {
        work->flags &= ~CARRY_GROUND;
    }
    if (!(work->flags & CARRY_HELD) && !OnEdit(task)) {
        EntryColliList(work);
    }
    ObjectSetupInput(work, motion);
}

void carry_step_still(struct task *task)
{
    struct task_work *work = task->work;
    struct task_motion *motion = task->motion;

    EntryColliList(work);
    ObjectSetupInput(work, motion);
}

void ObjectSetupInput(struct task_work *work, struct task_motion *motion)
{
#ifdef GCC
    /* the split frame's second picture clears no touch */
    if (frame_redrawing) {
        return;
    }
#endif
    work->flags &= ~COLLISION_TOUCHED;
    if (motion != NULL) {
        motion->accel.x = motion->accel.y = motion->accel.z = 0.0F;
    }
}

void object_turn_back(struct task_work *work, NJS_VECTOR *vector)
{
    NJS_VECTOR from;

    from.x = vector->x;
    from.y = vector->y;
    from.z = vector->z;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateY, -work->ang.y);
    TURN(njRotateX, -work->ang.x);
    TURN(njRotateZ, -work->ang.z);
    njCalcVector(NULL, &from, vector);
    late_DrawObjectClipEx(1);
}

void object_turn(struct task_work *work, NJS_VECTOR *vector)
{
    NJS_VECTOR from;

    from.x = vector->x;
    from.y = vector->y;
    from.z = vector->z;
    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njCalcVector(NULL, &from, vector);
    late_DrawObjectClipEx(1);
}

void InitObjects(void)
{
    NJS_OBJECT *root;
    struct task *task;

    object_tree = NULL;
    object_tree_last = NULL;
    root = CAlloc(1, sizeof(NJS_OBJECT));
    if (root == NULL) {
        return;
    }
    object_tree = root;
    object_tree_last = root;
    root->evalflags = NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG |
                      NJD_EVAL_UNIT_SCL | NJD_EVAL_HIDE | NJD_EVAL_BREAK;
    root->child = NULL;
    root->sibling = NULL;
    root->model = NULL;
    /* @hack spelling: task assigned in the test, which tests task_create's R0
     * with the copy to R4 in the BT/S's slot (0x8c05bf46, 0x8c05bf4a);
     * assigned apart, SHC tests R4 and 3 of 60 words differ */
    if ((task = CreateElementalTask(0, 3, object_tree_draw)) != NULL) {
        task->destructor = object_tree_destroy;
        task->draw = object_tree_draw;
    }
    placement_reset();
    panel_reset();
    rocket_reset();
    capsule_reset();
    target_reset();
    switch_reset();
    InitItemBoxManager();
}

/* the tree's task's destructor: free the root's children, then the root,
 * leaving object_tree and object_tree_last null */
static void object_tree_destroy(struct task *task)
{
    NJS_OBJECT *object;

    object_tree_last = NULL;
    while (object_tree != NULL) {
        object = object_tree->child;
        if (object != NULL) {
            object_tree->child = object->sibling;
        } else {
            object = object_tree;
            object_tree = NULL;
        }
        Free(object);
    }
}

void object_tree_draw(struct task *task)
{
    SetObjectTexture();
    late_DrawObject(object_tree);
}

/* append object to the root's children, and point work's world model at
 * it. the root's first child clears its NJD_EVAL_BREAK */
void object_tree_add(struct task_work *work, NJS_OBJECT *object)
{
    if (object_tree->child == NULL) {
        object_tree->child = object;
        object_tree->evalflags &= ~NJD_EVAL_BREAK;
    } else {
        object_tree_last->sibling = object;
    }
    WORLD_MODEL(work)->model = object;
    object_tree_last = object;
}

/* add a copy of work's world object to the tree, from the heap. returns
 * FALSE when there's no tree or no heap room, else TRUE */
Bool object_tree_add_copy(struct task_work *work)
{
    NJS_OBJECT *object;

    if (object_tree == NULL) {
        return FALSE;
    }
    /* @hack spelling: object assigned in the test, which tests heap_alloc's R0
     * with the copy to R5 in the BF/S's slot (0x8c05c084, 0x8c05c088);
     * assigned apart, SHC tests R5 and 3 of 52 words differ */
    if ((object = MAlloc(sizeof(NJS_OBJECT))) == NULL) {
        return FALSE;
    }
    *object = *WORLD_MODEL(work)->world;
    object_tree_add(work, object);
    return TRUE;
}

/* take object out of the tree and free it. object must be one of the
 * root's children: the walk for it doesn't test for the end of the list.
 * with the last child gone, the root carries NJD_EVAL_BREAK again */
void object_tree_remove(NJS_OBJECT *object)
{
    NJS_OBJECT *prev = object_tree;

    if (prev == NULL) {
        return;
    }
    if (object == prev->child) {
        prev->child = object->sibling;
    } else {
        prev = prev->child;
        while (prev->sibling != object) {
            prev = prev->sibling;
        }
        prev->sibling = object->sibling;
    }
    if (object_tree_last == object) {
        object_tree_last = prev;
    }
    Free(object);
    if (object_tree->child == NULL) {
        object_tree->evalflags |= NJD_EVAL_BREAK;
    }
}

Bool FUN_8c058fba(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return TRUE;
    }
    if (CheckObjectTexture()) {
        MODEL(work)->texlist = NULL;
    } else {
        NeonuLoadTexture(MODEL(work)->texlist);
    }
    if (CheckObjectTexture() && !OnEdit(task)) {
        task->step = model_draw;
        task->draw = model_draw;
        task->destructor = model_destroy;
    }
    model_draw(task);
    return FALSE;
}

void model_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (MODEL(work)->texlist != NULL) {
        njReleaseTexture_jp(MODEL(work)->texlist);
    }
}

void model_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!SetObjectTexture()) {
        njSetTexture_jp(MODEL(work)->texlist);
    }
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    late_DrawObject(MODEL(work)->object);
    late_DrawObjectClipEx(1);
}

Bool FUN_8c059108(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return TRUE;
    }
    if (CheckObjectTexture()) {
        MODEL(work)->texlist = NULL;
    } else {
        NeonuLoadTexture(MODEL(work)->texlist);
    }
    if (CheckObjectTexture() && !OnEdit(task)) {
        task->step = model_draw_scaled;
        task->draw = model_draw_scaled;
        task->destructor = model_destroy;
    }
    model_draw_scaled(task);
    return FALSE;
}

void model_draw_scaled(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!SetObjectTexture()) {
        njSetTexture_jp(MODEL(work)->texlist);
    }
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    njScale(NULL, work->scl.x + 1.0F, work->scl.y + 1.0F, work->scl.z + 1.0F);
    late_DrawObject(MODEL(work)->object);
    late_DrawObjectClipEx(1);
}

Bool FUN_8c0591fc(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return TRUE;
    }
    if (CheckObjectTexture()) {
        MODEL(work)->texlist = NULL;
    } else {
        NeonuLoadTexture(MODEL(work)->texlist);
    }
    if (CheckObjectTexture() && !OnEdit(task)) {
        task->destructor = model_destroy;
        task->step = FUN_8c0592a4;
        task->draw = model_draw;
    }
    model_draw(task);
    return FALSE;
}

void FUN_8c0592a4(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
    }
    if (task->destructor == model_destroy) {
        model_draw(task);
    }
}

Bool model_start_solid_scaled(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return TRUE;
    }
    if (CheckObjectTexture()) {
        MODEL(work)->texlist = NULL;
    } else {
        NeonuLoadTexture(MODEL(work)->texlist);
    }
    if (CheckObjectTexture() && !OnEdit(task)) {
        task->destructor = model_destroy;
        task->step = model_step_solid_scaled;
        task->draw = model_draw_scaled;
    }
    model_draw_scaled(task);
    return FALSE;
}

static void model_step_solid_scaled(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (!OnEdit(task)) {
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
    }
    if (task->destructor == model_destroy) {
        model_draw_scaled(task);
    }
}

Bool ObjectGCollision(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;
    Sint32 flags;

    if (CheckRangeOut(task)) {
        return TRUE;
    }
    if (CheckObjectTexture()) {
        WORLD_MODEL(work)->texlist = NULL;
    } else {
        NeonuLoadTexture(WORLD_MODEL(work)->texlist);
    }
    if (!OnEdit(task)) {
        object = GetMobileLandObject();
        WORLD_MODEL(work)->world = object;
        object->evalflags = WORLD_MODEL(work)->model->evalflags &
                            ~(NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG);
        object->scl[0] = 1.0F;
        object->scl[1] = 1.0F;
        object->scl[2] = 1.0F;
        object->ang[0] = work->ang.x;
        object->ang[1] = work->ang.y;
        object->ang[2] = work->ang.z;
        object->pos[0] = work->pos.x;
        object->pos[1] = work->pos.y;
        object->pos[2] = work->pos.z;
        object->model = WORLD_MODEL(work)->model->model;
        object->child = WORLD_MODEL(work)->model->child;
        object->sibling = WORLD_MODEL(work)->model->sibling;
        flags = WORLD_HUGE | WORLD_SOLID;
        /* @hack spelling: an empty arm for a radius over 20, where flags keeps
         * the value set above, which SHC sets in the BT/S's slot (MOV #1,R12
         * at 0x8c05c606); with the store in that arm, SHC branches round it,
         * the function runs 2 bytes long and 58 of 134 words differ */
        if (object->model->r > 20.0F) {
        } else if (object->model->r > 10.0F) {
            flags = WORLD_LARGE | WORLD_SOLID;
        } else if (object->model->r > 3.0F) {
            flags = WORLD_MEDIUM | WORLD_SOLID;
        } else {
            flags = WORLD_SMALL | WORLD_SOLID;
        }
        RegisterCollisionEntry(flags, task, object);
    }
    if (CheckObjectTexture() && WORLD_MODEL(work)->world != NULL &&
        object_tree_add_copy(work)) {
        task->destructor = world_model_destroy_tree;
        task->step = world_model_step;
    } else {
        task->destructor = world_model_destroy;
        task->step = world_model_step;
        task->draw = world_model_draw;
    }
    /* @hack redundant: a return of flags that never runs, which keeps flags in
     * R12, a saved register (0x8c05c606); without it, flags lives in R4 and 130
     * of 134 words differ */
    if (0) {
        return flags;
    }
    return FALSE;
}

/* pose the task's world object, if it has one, as the task. WORLD_TESTED
 * is then set while a player is within the model's radius plus
 * WORLD_MODEL_REACH of the task, else clear. a task the tree doesn't draw
 * draws itself here */
void world_model_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;

    if (CheckRangeOut(task)) {
        return;
    }
    object = WORLD_MODEL(work)->world;
    if (object != NULL) {
        object->pos[0] = work->pos.x;
        object->pos[1] = work->pos.y;
        object->pos[2] = work->pos.z;
        object->ang[0] = work->ang.x;
        object->ang[1] = work->ang.y;
        object->ang[2] = work->ang.z;
        if (player_in_range(&work->pos, object->model->r + WORLD_MODEL_REACH)) {
            work->flags |= WORLD_TESTED;
        } else {
            work->flags &= ~WORLD_TESTED;
        }
    }
    if (task->destructor == world_model_destroy) {
        world_model_draw(task);
    }
}

void world_model_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (!SetObjectTexture()) {
        njSetTexture_jp(WORLD_MODEL(work)->texlist);
    }
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateX, work->ang.x);
    late_DrawObject(WORLD_MODEL(work)->model);
    late_DrawObjectClipEx(1);
}

void world_model_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (WORLD_MODEL(work)->texlist != NULL) {
        njReleaseTexture_jp(WORLD_MODEL(work)->texlist);
    }
    if (WORLD_MODEL(work)->world != NULL) {
        WithdrawCollisionEntry(task, WORLD_MODEL(work)->world);
        ReleaseMobileLandObject(WORLD_MODEL(work)->world);
    }
}

void world_model_destroy_tree(struct task *task)
{
    struct task_work *work = task->work;

    if (WORLD_MODEL(work)->texlist != NULL) {
        njReleaseTexture_jp(WORLD_MODEL(work)->texlist);
    }
    if (WORLD_MODEL(work)->world != NULL) {
        WithdrawCollisionEntry(task, WORLD_MODEL(work)->world);
        ReleaseMobileLandObject(WORLD_MODEL(work)->world);
    }
    object_tree_remove(WORLD_MODEL(work)->model);
}

Bool FUN_8c0596ee(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return TRUE;
    }
    if (CheckObjectTexture()) {
        ACTION(work)->texlist = NULL;
    } else {
        NeonuLoadTexture(ACTION(work)->texlist);
    }
    task->destructor = action_destroy;
    task->step = action_step;
    task->draw = action_draw;
    return FALSE;
}

void action_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (ACTION(work)->texlist != NULL) {
        njReleaseTexture_jp(ACTION(work)->texlist);
    }
}

void action_step(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOut(task)) {
        action_draw(task);
        ACTION(work)->frame += 1.0F;
        if (ACTION(work)->frame >=
            (Float)ACTION(work)->action->motion->nbFrame) {
            ACTION(work)->frame = 0.0F;
        }
    }
}

void action_draw(struct task *task)
{
    struct task_work *work = task->work;

    if (!SetObjectTexture()) {
        njSetTexture_jp(ACTION(work)->texlist);
    }
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    ds_ActionClip(((struct action_vars *)&(work)->vars)->action,
                  ((struct action_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
}

void FUN_8c059854(struct task_work *work)
{
    Uint16 count = work->collision->count;
    Uint16 i;
    struct collision_shape *shape;

    for (i = 0; i < count; i++) {
        if (work->scl.x <= -1.0F) {
            work->scl.x = -1.0F;
        }
        if (work->scl.y <= -1.0F) {
            work->scl.y = -1.0F;
        }
        if (work->scl.z <= -1.0F) {
            work->scl.z = -1.0F;
        }
        /* @hack spelling: the shapes read, then offset by i, which reads
         * work->collision->shapes on each pass (MOV.L @(56,R4),R5 and
         * MOV.L @(12,R5),R5 at 0x8c05ca06 and 0x8c05ca0c); as &shapes[i],
         * SHC reads it once before the loop, the function runs 6 bytes short
         * and 79 of 81 words differ */
        shape = work->collision->shapes;
        shape += i;
        shape->radius = shape->radius * (work->scl.x + 1.0F);
        shape->size_y = shape->size_y * (work->scl.y + 1.0F);
        shape->size_z = shape->size_z * (work->scl.z + 1.0F);
        shape->center.x = shape->center.x * (work->scl.x + 1.0F);
        shape->center.y = shape->center.y * (work->scl.y + 1.0F);
        shape->center.z = shape->center.z * (work->scl.z + 1.0F);
    }
}

NJS_OBJECT *object_add_world(NJS_OBJECT *model, struct task *task, Sint32 flags)
{
    struct task_work *work = task->work;
    NJS_POINT3 *pos = &work->pos;
    struct angles *ang = &work->ang;
    NJS_OBJECT *object = GetMobileLandObject();

    object->evalflags =
        model->evalflags & ~(NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG);
    object->model = model->model;
    object->child = model->child;
    object->sibling = model->sibling;
    object->pos[0] = pos->x;
    object->pos[1] = pos->y;
    object->pos[2] = pos->z;
    object->ang[0] = ang->x;
    object->ang[1] = ang->y;
    object->ang[2] = ang->z;
    RegisterCollisionEntry(flags, task, object);
    return object;
}
