/* @unit 0C925340-0C925560 +r04 +egflags +pool32 +poolafter=ObjectECEggmanCap */
/* O EGGCAP hinged lid, which player 0 comes up through at entrance 1 */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv0100/egg_cap.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/player.h"
#include "stage/stage.h"
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
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
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

#define HINGE_X 18.883199F
#define HINGE_TURN 0x800 /* the lid's turn about its hinge each step */
#define HINGE_OPEN 0xa000 /* the hinge's angle with the lid open */
#define OPEN_STEPS 10
#define CAP_ENTRANCE 1
#define RISE_SPEED 5.0F
#define VARS(work) ((struct egg_cap_vars *)&(work)->vars)
extern NJS_OBJECT egg_cap_object;

/* the hinge's offset along world x from the lid's position */

/* the steps the lid stays open after the one it opens on */

/* the entrance under the lid, and player 0's speed up through it there */

struct egg_cap_vars {
    Uint8 unk_00[8];
    Angle hinge; /* from 0, shut, to HINGE_OPEN */
};

enum egg_cap_mode {
    CAP_INIT,
    CAP_OPENING, /* no code switches to it */
    CAP_SHUTTING,
    CAP_SHUT,
    CAP_OPEN, /* counts OPEN_STEPS, then shuts, whatever the hinge's angle */
    CAP_EDITING /* while the set editor runs, the lid is only drawn */
};

void EggmanCapDisplayer(struct task *task);
void EggmanCapDestructor(struct task *task);
void DisplayEggmanCap(struct task_work *work);
extern struct collision_shape egg_cap_shapes[];

void ObjectECEggmanCap(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case CAP_INIT:
        task->destructor = EggmanCapDestructor;
        task->draw = EggmanCapDisplayer;
        /* @hack redundant: the else after the return, which builds
         * collision_init's two 1s in R1 (0x0c925418 to 0x0c925420); without
         * it, in R2, and 3 of 140 words differ */
        if (OnEdit(task)) {
            work->mode = CAP_EDITING;
            return;
        } else {
            CCL_Init(task, egg_cap_shapes, COLLISION_OBJECT, 1, 1);
            if (stage_get_entrance() == CAP_ENTRANCE) {
                player_set_speed(0, 0.0F, RISE_SPEED, 0.0F);
                work->mode = CAP_OPEN;
                work->collision->shapes->flags |= SHAPE_OFF;
            } else {
                work->mode = CAP_SHUT;
                work->collision->shapes->flags &= ~SHAPE_OFF;
            }
        }
        break;
    case CAP_SHUT:
        break;
    case CAP_OPEN:
        if (TASK_TIMER(work)++ < OPEN_STEPS) {
            break;
        }
        work->mode = CAP_SHUTTING;
        break;
    case CAP_OPENING:
        VARS(work)->hinge += HINGE_TURN;
        if (VARS(work)->hinge < HINGE_OPEN) {
            break;
        }
        VARS(work)->hinge = HINGE_OPEN;
        work->mode = CAP_OPEN;
        work->timer = 0;
        break;
    case CAP_SHUTTING:
        /* @hack spelling: -HINGE_TURN added, a constant of its own, which SHC
         * loads from the pool for the add (MOV.W at 0x0c9254de) as
         * CAP_OPENING loads 0x800 (0x0c9254c2); with -=, SHC loads 0x800 once
         * into R5 ahead of the switch, the function runs 56 bytes short and
         * 130 of 140 words differ */
        VARS(work)->hinge += -HINGE_TURN;
        if (VARS(work)->hinge > 0) {
            break;
        }
        VARS(work)->hinge = 0;
        work->mode = CAP_SHUT;
        work->collision->shapes->flags &= ~SHAPE_OFF;
        break;
    }
    DisplayEggmanCap(work);
    if (!OnEdit(task)) {
        EntryColliList(work);
    }
}

void EggmanCapDisplayer(struct task *task)
{
    struct task_work *work = task->work;

    DisplayEggmanCap(work);
}

void EggmanCapDestructor(struct task *task)
{
}

void DisplayEggmanCap(struct task_work *work)
{
    Angle ang;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    njTranslate(NULL, HINGE_X, 0.0F, 0.0F);
    TURN_VIA(njRotateY, work->ang.y, ang);
    TURN_VIA(njRotateZ, VARS(work)->hinge, ang);
    late_DrawObject(&egg_cap_object);
    late_DrawObjectClipEx(1);
}
