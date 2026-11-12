/* @unit 0C90D200-0C90D5E0 @data 0C911804-0C911810 +r04 +egflags +pool32 */
/* O FROG: a frog in a bubble, which clears the stage when player 0 touches
 * it */
#include <ninja.h>

#include "animal/barrier.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "player/big_kaeru_textures.h"
#include "player/player.h"
#include "progress/progress.h"
#include "stage/stage.h"
#include "stg01/frog.h"
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
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
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
Bool SeqCheckStage(int stage, int act);
void SeqChangeStage(int stage, int act);
Bool SeqCheckNextStage(Uint8 stage, Uint8 act);
Bool SeqCheckClearAction(int stage);
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

/* the frog Big fishes for: its whole tree, and the nodes beach_frog_nodes
 * lists */
#define FROG_NODES 12
#define REACH 14.0F
#define BOB_HEIGHT 2.5F
extern NJS_OBJECT frog_object;
extern NJS_OBJECT frog_node_1_object;
extern NJS_OBJECT frog_node_2_object;
extern NJS_OBJECT frog_node_3_object;
extern NJS_OBJECT frog_node_4_object;
extern NJS_OBJECT frog_node_5_object;
extern NJS_OBJECT frog_node_6_object;
extern NJS_OBJECT frog_node_7_object;
extern NJS_OBJECT frog_node_8_object;
extern NJS_OBJECT frog_node_9_object;
extern NJS_OBJECT frog_node_10_object;
extern NJS_OBJECT frog_node_11_object;
extern NJS_OBJECT frog_node_12_object;
extern NJS_OBJECT *beach_frog_nodes[12];

enum beach_frog_mode { FROG_INIT = 0, FROG_WAIT = 2, FROG_CAUGHT = 3 };

/* player 0 catches the frog within (scale x + 1) * REACH of it */

/* how far the frog bobs above and below its place */

void beach_frog_draw_nodes(struct task *task);
void beach_frog_draw_whole(struct task *task);
void beach_frog_bob(struct task *task);
void beach_frog_draw_reach(struct task *task);
void beach_frog_touch(struct task *task);
void beach_frog_draw(struct task *task);

void beach_frog_step(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    switch (work->mode) {
    case FROG_INIT:
        work->mode = FROG_WAIT;
        task->draw = beach_frog_draw;
        break;
    case FROG_WAIT:
        if (!OnEdit(task)) {
            beach_frog_touch(task);
        }
        if (OnEdit(task)) {
            njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- SCALE");
            beach_frog_draw_reach(task);
        }
        beach_frog_bob(task);
        beach_frog_draw(task);
        break;
    case FROG_CAUGHT:
        break;
    }
}

/* draw each node of beach_frog_nodes moved by its own pos and turned with
 * the frog. the node's own angles and its parents' moves don't apply. then
 * draw the bubble, turned TASK_TIMER(work) degrees about y. work->scl.y
 * raises both by the bob */
void beach_frog_draw_nodes(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT **nodes;
    NJS_OBJECT *node;
    Angle ang;
    int i;

    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y + work->scl.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njSetTexture_jp(&big_kaeru_texlist);
    for (i = 0; i < 12; i++) {
        node = beach_frog_nodes[i];
        njPushMatrix(NULL);
        njTranslate(NULL, node->pos[0], node->pos[1], node->pos[2]);
        ds_DrawModelClip(node->model);
        late_DrawObjectClipEx(1);
    }
    njSetTexture_jp(&al_barria_texlist);
    TURN_VIA(njRotateY, (Angle)(TASK_TIMER(work) * ANGLE_PER_DEGREE), ang);
    late_DrawObject(&al_barria_object);
    late_DrawObjectClipEx(1);
}

void beach_frog_draw_whole(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;
    Angle ang;

    njSetTexture_jp(&big_kaeru_texlist);
    njPushMatrix(NULL);
    object = &frog_object;
    njTranslate(NULL, work->pos.x, work->pos.y + work->scl.y, work->pos.z);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObjectClip(object);
    njSetTexture_jp(&al_barria_texlist);
    TURN_VIA(njRotateY, (Angle)(TASK_TIMER(work) * ANGLE_PER_DEGREE), ang);
    late_DrawObject(&al_barria_object);
    late_DrawObjectClipEx(1);
}

/* advance TASK_TIMER(work) a degree, which turns the bubble too. then set
 * work->scl.y to the bob, which goes round once each 360 steps */
void beach_frog_bob(struct task *task)
{
    struct task_work *work = task->work;

    TASK_TIMER(work)++;
    work->scl.y =
        njSin((Angle)(TASK_TIMER(work) * ANGLE_PER_DEGREE)) * BOB_HEIGHT;
}

/* in the set editor, draw marker_object scaled by scale x + 1. it shows a
 * sphere of radius (scale x + 1) * 10. the touch reaches farther, to (scale
 * x + 1) * REACH */
void beach_frog_draw_reach(struct task *task)
{
    struct task_work *work = task->work;
    /* @hack type: a vector, of which only x is used, whose 12 bytes give the
     * image's ADD #-12,R15 (0x0c90db9c). as one Float, 40 of 41 words
     * differ */
    NJS_VECTOR scale;

    scale.x = work->scl.x + 1.0F;
    njPushMatrix(NULL);
    njTranslate(NULL, work->pos.x, work->pos.y, work->pos.z);
    njScale(NULL, scale.x, scale.x, scale.x);
    late_DrawObject(&object_sphere01);
    late_DrawObjectClipEx(1);
}

void beach_frog_touch(struct task *task)
{
    struct task_work *work = task->work;

    if (player_in_range(&work->pos, (work->scl.x + 1.0F) * REACH) == 1) {
        SetFinishAction();
        work->mode = FROG_CAUGHT;
    }
}

/* draw the frog node by node once E-102 has cleared Emerald Coast, and its
 * whole tree before */
void beach_frog_draw(struct task *task)
{
    if (SeqCheckFlag(FLAG_E102_CLEAR_BEACH)) {
        beach_frog_draw_nodes(task);
    } else {
        beach_frog_draw_whole(task);
    }
}
