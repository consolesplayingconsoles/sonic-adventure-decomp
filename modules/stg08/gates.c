/* @unit 0C90DA00-0C90DD40 +r04 +egflags +pool32 */
/* O Kuguri: snowboard gates, and the combo they score. they stand only in a
 * mini game's trial */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/model.h"
#include "hud/hud.h"
#include "main.h"
#include "object/common.h"
#include "object/placement.h"
#include "player/e102_bonus.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "stg08/gates.h"
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
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
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
Bool thunk_FUN_8c081ba6(void);
struct task *thunk_FUN_8c081bec(void);
struct task *thunk_FUN_8c08395e(struct battle *battle);
struct task *thunk_FUN_8c083ebc(struct battle *battle);
void thunk_FUN_8c083f7e(struct battle *battle);
Sint16 thunk_FUN_8c0829cc(int frames);
Sint16 thunk_FUN_8c082b9a(int unused);
void ObjectMovableSRegularExecute(struct task *task);
void ObjectMovableMRegularExecute(struct task *task);
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
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
void FUN_0c90daee(struct task *task);
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

#define COMBO_MAX 50
#define COMBO_STEPS 180
#define COMBO_POINTS 10
#define COMBO_X 528.0F
#define COMBO_SPACING 32.0F
#define COMBO_PRI (-3.0F)
#define COMBO_TIMES 10
#define SE_GATE 21
#define GATE_PASSED 0x200
extern NJS_MODEL icecap_gate_model;
extern Uint8 icecap_gate_combo_count;
extern Uint8 KuguriTimer;
extern struct collision_shape icecap_gate_shape;
extern NJS_TEXANIM icecap_gate_combo_texanims[11];
extern NJS_SPRITE icecap_gate_combo_sprite;
extern const NJS_ARGB icecap_gate_combo_white;
extern const NJS_ARGB icecap_gate_combo_none;

void icecap_gate_destroy(struct task *task)
{
}

/* the gate's step and draw */
void icecap_gate_run(struct task *task)
{
    struct task_work *work = task->work;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateZ, work->ang.z);
    TURN(njRotateX, work->ang.x);
    TURN(njRotateY, work->ang.y);
    ds_DrawModelClip(&icecap_gate_model);
    late_DrawObjectClipEx(1);
    if ((work->collision->flags & COLLISION_HIT) &&
        !(work->flags & GATE_PASSED)) {
        work->flags |= GATE_PASSED;
        if (KuguriTimer == 0) {
            icecap_gate_combo_count = 1;
        } else if (++icecap_gate_combo_count > COMBO_MAX) {
            icecap_gate_combo_count = COMBO_MAX;
        }
        KuguriTimer = COMBO_STEPS;
        score_add(icecap_gate_combo_count * COMBO_POINTS);
        dsPlay_oneshot(SE_GATE, 0, 0, 0);
    }
    if (!OnEdit(task)) {
        EntryColliList(work);
        ObjectSetupInput(work, NULL);
    }
}

void FUN_0c90daee(struct task *task)
{
    struct task_work *work = task->work;

    if (game_mode != GAME_MODE_TRIAL ||
        AdvertiseWork.trial[0] != MENU_TRIAL_MINI_GAME) {
        DeadOut(task);
        return;
    }
    work->flags &= ~GATE_PASSED;
    CCL_Init(task, &icecap_gate_shape, COLLISION_OBJECT, 1, 1);
    task->destructor = icecap_gate_destroy;
    task->step = icecap_gate_run;
    task->draw = icecap_gate_run;
}

void icecap_gate_combo_draw(struct task *task)
{
    if (KuguriTimer == 0) {
        return;
    }
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njTextureFilterMode_jp(NJD_TEXTUREFILTER_POINT_SAMPLE);
    njSetConstantMaterial((NJS_ARGB *)&icecap_gate_combo_white);
#ifdef GCC
    /* the port's 16:9 squeezes the count about the screen's right edge */
    port_wide_anchor = WIDE_RIGHT;
#endif
    icecap_gate_combo_sprite.p.x = COMBO_X;
    late_DrawSprite2D(&icecap_gate_combo_sprite, COMBO_TIMES, COMBO_PRI,
                      NJD_SPRITE_ALPHA);
    icecap_gate_combo_sprite.p.x += COMBO_SPACING;
    if (icecap_gate_combo_count >= 10) {
        late_DrawSprite2D(&icecap_gate_combo_sprite,
                          icecap_gate_combo_count / 10, COMBO_PRI,
                          NJD_SPRITE_ALPHA);
        icecap_gate_combo_sprite.p.x += COMBO_SPACING;
        late_DrawSprite2D(&icecap_gate_combo_sprite,
                          icecap_gate_combo_count % 10, COMBO_PRI,
                          NJD_SPRITE_ALPHA);
    } else {
        late_DrawSprite2D(&icecap_gate_combo_sprite, icecap_gate_combo_count,
                          COMBO_PRI, NJD_SPRITE_ALPHA);
    }
#ifdef GCC
    port_wide_anchor = WIDE_MIDDLE;
#endif
    njSetConstantMaterial((NJS_ARGB *)&icecap_gate_combo_none);
    njTextureFilterMode_jp(NJD_TEXTUREFILTER_BILINEAR);
}

/* the combo's step ends its task outside act 2, the board run. in act 2, it
 * counts down the combo's steps */
void NormalKuguri(struct task *task)
{
    if (GetStageNumber() != STAGE_ACT(STAGE_ICECAP, 2)) {
        FreeTask(task);
        return;
    }
    if (KuguriTimer != 0) {
        KuguriTimer--;
    }
    icecap_gate_combo_draw(task);
}

void ObjectKuguriControl(struct task *task)
{
    icecap_gate_combo_count = 1;
    KuguriTimer = 0;
    task->step = NormalKuguri;
    task->draw = icecap_gate_combo_draw;
}
