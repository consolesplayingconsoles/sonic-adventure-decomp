/* @unit 0C914980-0C914D20 @data 0C919D18-0C919D3C +r04 +egflags +pool32 +asmfunc=FUN_0c914c0a:0c914d20 */
/* O Pin Lamp and O Side Lamp lamps with a turning glare */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/tree.h"
#include "effect/glare.h"
#include "object/common.h"
#include "object/placement.h"
#include "stg10/lamp.h"
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
extern struct AdvertiseWork AdvertiseWork;
Bool thunk_FUN_8c081ba6(void);
struct task *thunk_FUN_8c081bec(void);
struct task *thunk_FUN_8c08395e(struct battle *battle);
struct task *thunk_FUN_8c083ebc(struct battle *battle);
void thunk_FUN_8c083f7e(struct battle *battle);
Sint16 thunk_FUN_8c0829cc(int frames);
Sint16 thunk_FUN_8c082b9a(int unused);
void ObjectMovableSRegularExecute(struct task *task);
void ObjectMovableMRegularExecute(struct task *task);
void ObjectSetupInput(struct task_work *work, struct task_motion *motion);
void InitObjects(void);
Bool ObjectGCollision(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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

#define SCALE_MIN 0.1F
#define SPIN 0x400 /* the glare's turn each step */
#define GLARE_SIZE 0.75F
enum final_lamp_kind { LAMP_PIN, LAMP_SIDE };

/* the least scale a lamp draws at. a smaller scale becomes 1 */

/* the lamp's view of its task_work. fields that share task_work's names
 * must stay at task_work's offsets. pin_lamp_step and side_lamp_step test
 * five of them, pos twice, and start no lamp if one has moved */
struct final_lamp_work {
    Sint8 kind; /* LAMP_PIN or LAMP_SIDE, kept in task_work's mode */
    Uint8 unk_01;
    Uint8 id;
    Uint8 unk_03;
    Sint16 flags;
    Uint8 unk_06[2];
    NJS_POINT3 light; /* the light's position in the world */
    struct angles ang;
    NJS_POINT3 pos;
    Float scale; /* scale x, applied on all three axes */
    Angle spin; /* the glare's turn, kept in scale y */
    Uint8 unk_34[4];
    struct collision_work *collision;
    struct event_work *event;
};

void pin_side_lamp_init(struct task *task);
void pin_side_lamp_exec(struct task *task);
void pin_side_lamp_draw(struct task *task);
void final_lamp_destroy(struct task *task);
void final_lamp_find_node(NJS_OBJECT *object, NJS_OBJECT *node,
                          NJS_POINT3 *pos);
extern NJS_MATERIAL side_lamp_light_materials[1];
extern Sint16 side_lamp_light_meshes[66];
extern NJS_COLOR side_lamp_light_uvs[58];
extern NJS_MESHSET side_lamp_light_meshsets[1];
extern NJS_POINT3 side_lamp_light_points[28];
extern NJS_VECTOR side_lamp_light_normals[28];
extern NJS_MODEL side_lamp_light_model;
extern NJS_OBJECT side_lamp_light_object;
extern NJS_MATERIAL side_lamp_materials[3];
extern Sint16 side_lamp_meshes0[84];
extern Sint16 side_lamp_meshes1[20];
extern Sint16 side_lamp_meshes2[10];
extern NJS_COLOR side_lamp_uvs0[76];
extern NJS_COLOR side_lamp_uvs1[16];
extern NJS_COLOR side_lamp_uvs2[8];
extern NJS_MESHSET side_lamp_meshsets[3];
extern NJS_POINT3 side_lamp_points[44];
extern NJS_VECTOR side_lamp_normals[44];
extern NJS_MODEL side_lamp_model;
extern NJS_OBJECT side_lamp_object;
extern NJS_MATERIAL pin_lamp_light_materials[1];
extern Sint16 pin_lamp_light_meshes[63];
extern NJS_COLOR pin_lamp_light_uvs[56];
extern NJS_MESHSET pin_lamp_light_meshsets[1];
extern NJS_POINT3 pin_lamp_light_points[28];
extern NJS_VECTOR pin_lamp_light_normals[28];
extern NJS_MODEL pin_lamp_light_model;
extern NJS_OBJECT pin_lamp_light_object;
extern NJS_MATERIAL pin_lamp_materials[4];
extern Sint16 pin_lamp_meshes0[20];
extern Sint16 pin_lamp_meshes1[81];
extern Sint16 pin_lamp_meshes2[20];
extern Sint16 pin_lamp_meshes3[5];
extern NJS_COLOR pin_lamp_uvs0[16];
extern NJS_COLOR pin_lamp_uvs1[72];
extern NJS_COLOR pin_lamp_uvs2[16];
extern NJS_COLOR pin_lamp_uvs3[4];
extern NJS_MESHSET pin_lamp_meshsets[4];
extern NJS_POINT3 pin_lamp_points[47];
extern NJS_VECTOR pin_lamp_normals[47];
extern NJS_MODEL pin_lamp_model;
extern NJS_OBJECT pin_lamp_object;
extern NJS_OBJECT *const final_lamp_objects[2];
extern NJS_OBJECT *const final_lamp_lights[2];
extern NJS_ARGB final_lamp_glare_color;

void pin_lamp_step(struct task *task)
{
    struct final_lamp_work *work = (struct final_lamp_work *)task->work;

    /* @hack redundant: pos tested twice, as the image tests it (ADD #32,R2 at
     * 0x0c9154a6 and 0x0c9154d8); tested once, 84 of 109 words differ */
    /* NOLINTBEGIN(misc-redundant-expression) */
    if (!WORK_SAME_PLACE(struct final_lamp_work, pos) ||
        !WORK_SAME_PLACE(struct final_lamp_work, id) ||
        !WORK_SAME_PLACE(struct final_lamp_work, collision) ||
        !WORK_SAME_PLACE(struct final_lamp_work, event) ||
        !WORK_SAME_PLACE(struct final_lamp_work, pos) ||
        !WORK_SAME_PLACE(struct final_lamp_work, flags)) {
        return;
    }
    /* NOLINTEND(misc-redundant-expression) */
    work->kind = LAMP_PIN;
    pin_side_lamp_init(task);
}

void side_lamp_step(struct task *task)
{
    struct final_lamp_work *work = (struct final_lamp_work *)task->work;

    /* @hack redundant: pos tested twice, as the image tests it (ADD #32,R2 at
     * 0x0c9154fa and 0x0c91552c); tested once, 85 of 110 words differ */
    /* NOLINTBEGIN(misc-redundant-expression) */
    if (!WORK_SAME_PLACE(struct final_lamp_work, pos) ||
        !WORK_SAME_PLACE(struct final_lamp_work, id) ||
        !WORK_SAME_PLACE(struct final_lamp_work, collision) ||
        !WORK_SAME_PLACE(struct final_lamp_work, event) ||
        !WORK_SAME_PLACE(struct final_lamp_work, pos) ||
        !WORK_SAME_PLACE(struct final_lamp_work, flags)) {
        return;
    }
    /* NOLINTEND(misc-redundant-expression) */
    work->kind = LAMP_SIDE;
    pin_side_lamp_init(task);
}

/* set work->light by the set entry's scale, then raise a scale below
 * SCALE_MIN to 1. such a lamp draws at 1, but its light stays where a lamp
 * that small has it */
void pin_side_lamp_init(struct task *task)
{
    struct final_lamp_work *work = (struct final_lamp_work *)task->work;
    int kind = work->kind; /* NOLINT(bugprone-signed-char-misuse) */
    Float scale;

    njPushMatrix(&nj_unit_matrix_);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    scale = work->scale;
    njScale(NULL, scale, scale, scale);
    final_lamp_find_node(final_lamp_objects[kind], final_lamp_lights[kind],
                         &work->light);
    late_DrawObjectClipEx(1);
    if (work->scale < SCALE_MIN) {
        work->scale = 1.0F;
    }
    task->step = pin_side_lamp_exec;
    task->draw = pin_side_lamp_draw;
    task->destructor = final_lamp_destroy;
}

void pin_side_lamp_exec(struct task *task)
{
    struct final_lamp_work *work = (struct final_lamp_work *)task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "<- scale");
        njPrintColor(0xffff0000);
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "Don't EDIT!");
        njPrintColor(0xffc0c0c0);
    }
    work->spin = (work->spin + SPIN) & 0xffff;
    pin_side_lamp_draw(task);
}

void pin_side_lamp_draw(struct task *task)
{
    struct final_lamp_work *work = (struct final_lamp_work *)task->work;
    int kind = work->kind; /* NOLINT(bugprone-signed-char-misuse) */
    NJS_VECTOR dir = {1.0F, 0.0F, 0.0F};
    Float scale;

    SetObjectTexture();
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    scale = work->scale;
    njScale(NULL, scale, scale, scale);
    late_DrawObject(final_lamp_objects[kind]);
    njUnitMatrix(NULL);
    TURN(njRotateY, work->spin);
    njCalcVector(NULL, &dir, &dir);
    late_DrawObjectClipEx(1);
    DrawHeadLight(&work->light, &dir, GLARE_SIZE, &final_lamp_glare_color);
}

void final_lamp_destroy(struct task *task)
{
}
#ifdef NON_MATCHING

/* set *pos to where node lies in the tree from object, under the current
 * matrix. each node's pos and ang apply, but not its scl */
void final_lamp_find_node(NJS_OBJECT *object, NJS_OBJECT *node, NJS_POINT3 *pos)
{
    njPushMatrix(NULL);
    njTranslate(NULL, object->pos[0], object->pos[1], object->pos[2]);
    njRotateXYZ(NULL, object->ang[0], object->ang[1], object->ang[2]);
    if (object == node) {
        njGetTranslation(NULL, pos);
    } else if (object->child != NULL) {
        final_lamp_find_node(object->child, node, pos);
    }
    late_DrawObjectClipEx(1);
    if (object->sibling != NULL) {
        final_lamp_find_node(object->sibling, node, pos);
    }
}
#else
void final_lamp_find_node(NJS_OBJECT *object, NJS_OBJECT *node, NJS_POINT3 *pos)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
}
#endif
