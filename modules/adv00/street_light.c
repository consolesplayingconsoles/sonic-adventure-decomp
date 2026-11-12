/* @unit 0C9088E0-0C908B80 +egflags +pool32 */
/* O GAITOU street light, whose lamp glows at night */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv00/street_light.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "draw/sprite.h"
#include "object/placement.h"
#include "progress/progress.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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

/* the post, whose children are a quad and then the lamp */
#define QUAD_ATTR (NJD_SA_SRC | NJD_DA_ONE | NJD_FLAG_USE_ALPHA)
#define GLOW_HEIGHT 39.0F
#define LIT(work) ((work)->submode)
extern NJS_OBJECT street_light_object;

/* the quad's blend, under which its color adds to what lies behind it. init
 * sets it in the quad's material, but neither draw draws the quad */

/* 1 for a light started at night, which draws its glow, else 0 */

void street_light_step(struct task *task);
void street_light_draw(struct task *task);
void LampDisp(struct task *task);
extern struct collision_shape street_light_shape;
extern NJS_TEXANIM street_light_glow_texanim;
extern NJS_SPRITE street_light_glow;

void ObjectSSGaitou(struct task *task)
{
    struct task_work *work = task->work;

    work->ang.x = 0;
    work->ang.z = 0;
    work->mode = 0;
    work->vars.f[0] = 0.0F;
    if (!OnEdit(task)) {
        CCL_Init(task, &street_light_shape, COLLISION_OBJECT, 1, 1);
    }
    street_light_object.child->model->mats[0].attrflags |= QUAD_ATTR;
    task->step = street_light_step;
    if (story_get_time() == TIME_NIGHT) {
        LIT(work) = 1;
        task->draw = LampDisp;
    } else {
        LIT(work) = 0;
        task->draw = street_light_draw;
    }
}

void street_light_step(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOut(task)) {
        if (!OnEdit(task)) {
            EntryColliList(work);
        }
        if (LIT(work) == 1) {
            LampDisp(task);
        } else {
            street_light_draw(task);
        }
    }
}

void street_light_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_OBJECT *object;
    Angle ang;
    Float x;
    Float y;
    Float z;
    Float scale_x;
    Float scale_y;
    Float scale_z;
    Float *walk;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    object = &street_light_object;
    njTranslateV(NULL, (NJS_VECTOR *)object->pos);
    njPushMatrix(NULL);
    TURN_VIA(njRotateY, work->ang.y, ang);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
    /* @hack spelling: the walk to the lamp in two steps, which keeps work in
     * R13 and object in R14 (0x0c908e5c, 0x0c908e6e). in one, the two trade
     * and 13 of 86 words differ */
    object = object->child;
    object = object->sibling;
    /* @hack spelling: the lamp's position and scale read through walk, which
     * loads them with FMOV.S @R4+ (0x0c908ea8 to 0x0c908ebe). indexed, 51 of
     * 86 words differ */
    walk = object->pos;
    x = *walk++;
    y = *walk++;
    z = *walk;
    walk = object->scl;
    scale_x = *walk++;
    scale_y = *walk++;
    scale_z = *walk;
    njTranslate(NULL, x, y, z);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njScale(NULL, scale_x, scale_y, scale_z);
    ds_DrawModelClip(object->model);
    late_DrawObjectClipEx(1);
}

/* draw the glow and then the light, on a frame's first step only */
void LampDisp(struct task *task)
{
    struct task_work *work = task->work;

    if (!loop_count) {
        njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
        njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
        SetMaterial(0.7F, 0.8F, 0.8F, 0.8F);
        street_light_glow.p.x = work->pos.x;
        street_light_glow.p.y = work->pos.y + GLOW_HEIGHT;
        street_light_glow.p.z = work->pos.z;
        sprite_set_depth(-3.0F);
        sprite_draw_3d(&street_light_glow, 0,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE | NJD_SPRITE_COLOR);
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
        street_light_draw(task);
    }
}
