/* @unit 8C0DE800-8C0DEDE0 @data 8C15C740-8C15C74C +r04 +egflags +pool32 +poolafter=AmyBirdInit +asmfunc=AmyBirdExe */
/* the bird that circles over Amy */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "event/play.h"
#include "main.h"
#include "player/amy.h"
#include "player/amy_bird.h"
#include "player/player.h"
#include "player/textures.h"
#include "stage/stage.h"
#include "stg03/mirror.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/util.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void EV_Load2(int number);
void EV_Exec2(void);
Bool EV_CheckExec(int number);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z, Angle ang_x,
                     Angle ang_y, Angle ang_z);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
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
struct task *createMirrorTask(struct task *task);
void *syMalloc_default_malloc(size_t size);
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

/* the stage_act that ends amy_bird_create's list of stages, which no act
 * has */
#define BIRD_STAGES_END 0x7fff

/* the circle the bird flies round player 0: its radius, and its height over
 * her */
#define BIRD_RADIUS 3.0F
#define BIRD_HEIGHT 12.0F
/* the bird jumps to its place on the circle from this far away or more,
 * and eases there from nearer */
#define BIRD_JUMP_DISTANCE 200.0F
/* as she takes a drum, the bird flies to the point this far up her own y
 * axis */
#define PERCH_HEIGHT 7.0F

/* the bird keeps its angle round player 0 in work->ang.x, and its bob's
 * phase in work->ang.z */
#define VARS(work) ((struct bird_vars *)&(work)->vars)
struct bird_vars {
    Float frame; /* the frame of bird_flap_action it shows */
};
extern NJS_MATERIAL bird_wing_tip_minus_z_materials[1];
extern Sint16 bird_wing_tip_minus_z_meshes0[11];
extern NJS_COLOR bird_wing_tip_minus_z_uvs0[9];
extern NJS_MESHSET bird_wing_tip_minus_z_meshsets[1];
extern NJS_POINT3 bird_wing_tip_minus_z_points[7];
extern NJS_VECTOR bird_wing_tip_minus_z_normals[7];
extern NJS_MODEL bird_wing_tip_minus_z_model;
extern NJS_OBJECT bird_wing_tip_minus_z;
extern NJS_MATERIAL bird_wing_minus_z_materials[1];
extern Sint16 bird_wing_minus_z_meshes0[5];
extern NJS_COLOR bird_wing_minus_z_uvs0[4];
extern NJS_MESHSET bird_wing_minus_z_meshsets[1];
extern NJS_POINT3 bird_wing_minus_z_points[4];
extern NJS_VECTOR bird_wing_minus_z_normals[4];
extern NJS_MODEL bird_wing_minus_z_model;
extern NJS_OBJECT bird_wing_minus_z;
extern NJS_MATERIAL bird_wing_tip_plus_z_materials[1];
extern Sint16 bird_wing_tip_plus_z_meshes0[11];
extern NJS_COLOR bird_wing_tip_plus_z_uvs0[9];
extern NJS_MESHSET bird_wing_tip_plus_z_meshsets[1];
extern NJS_POINT3 bird_wing_tip_plus_z_points[7];
extern NJS_VECTOR bird_wing_tip_plus_z_normals[7];
extern NJS_MODEL bird_wing_tip_plus_z_model;
extern NJS_OBJECT bird_wing_tip_plus_z;
extern NJS_MATERIAL bird_wing_plus_z_materials[1];
extern Sint16 bird_wing_plus_z_meshes0[5];
extern NJS_COLOR bird_wing_plus_z_uvs0[4];
extern NJS_MESHSET bird_wing_plus_z_meshsets[1];
extern NJS_POINT3 bird_wing_plus_z_points[4];
extern NJS_VECTOR bird_wing_plus_z_normals[4];
extern NJS_MODEL bird_wing_plus_z_model;
extern NJS_OBJECT bird_wing_plus_z;
extern NJS_MATERIAL bird_tail_materials[1];
extern Sint16 bird_tail_meshes0[18];
extern NJS_COLOR bird_tail_uvs0[15];
extern NJS_MESHSET bird_tail_meshsets[1];
extern NJS_POINT3 bird_tail_points[7];
extern NJS_VECTOR bird_tail_normals[7];
extern NJS_MODEL bird_tail_model;
extern NJS_OBJECT bird_tail;
extern NJS_MATERIAL bird_head_materials[5];
extern Sint16 bird_head_meshes0[236];
extern Sint16 bird_head_meshes1[22];
extern Sint16 bird_head_meshes2[21];
extern Sint16 bird_head_meshes3[21];
extern Sint16 bird_head_meshes4[18];
extern NJS_COLOR bird_head_uvs0[207];
extern NJS_COLOR bird_head_uvs1[20];
extern NJS_COLOR bird_head_uvs2[16];
extern NJS_COLOR bird_head_uvs3[18];
extern NJS_COLOR bird_head_uvs4[16];
extern NJS_MESHSET bird_head_meshsets[5];
extern NJS_POINT3 bird_head_points[143];
extern NJS_VECTOR bird_head_normals[143];
extern NJS_MODEL bird_head_model;
extern NJS_OBJECT bird_head;
extern NJS_MATERIAL bird_foot_minus_z_materials[1];
extern Sint16 bird_foot_minus_z_meshes0[47];
extern NJS_COLOR bird_foot_minus_z_uvs0[38];
extern NJS_MESHSET bird_foot_minus_z_meshsets[1];
extern NJS_POINT3 bird_foot_minus_z_points[12];
extern NJS_VECTOR bird_foot_minus_z_normals[12];
extern NJS_MODEL bird_foot_minus_z_model;
extern NJS_OBJECT bird_foot_minus_z;
extern NJS_MATERIAL bird_foot_plus_z_materials[1];
extern Sint16 bird_foot_plus_z_meshes0[47];
extern NJS_COLOR bird_foot_plus_z_uvs0[38];
extern NJS_MESHSET bird_foot_plus_z_meshsets[1];
extern NJS_POINT3 bird_foot_plus_z_points[12];
extern NJS_VECTOR bird_foot_plus_z_normals[12];
extern NJS_MODEL bird_foot_plus_z_model;
extern NJS_OBJECT bird_foot_plus_z;
extern NJS_MATERIAL bird_body_materials[5];
extern Sint16 bird_body_meshes0[54];
extern Sint16 bird_body_meshes1[21];
extern Sint16 bird_body_meshes2[35];
extern Sint16 bird_body_meshes3[23];
extern Sint16 bird_body_meshes4[20];
extern NJS_COLOR bird_body_uvs0[48];
extern NJS_COLOR bird_body_uvs1[18];
extern NJS_COLOR bird_body_uvs2[30];
extern NJS_COLOR bird_body_uvs3[20];
extern NJS_COLOR bird_body_uvs4[16];
extern NJS_MESHSET bird_body_meshsets[5];
extern NJS_POINT3 bird_body_points[62];
extern NJS_VECTOR bird_body_normals[62];
extern NJS_MODEL bird_body_model;
extern NJS_OBJECT bird_body;
extern NJS_OBJECT bird_object;
extern NJS_MKEY_F bird_flap_pos0[15];
extern NJS_MKEY_A bird_flap_ang2[16];
extern NJS_MKEY_A bird_flap_ang3[16];
extern NJS_MKEY_A bird_flap_ang4[15];
extern NJS_MKEY_A bird_flap_ang5[16];
extern NJS_MKEY_A bird_flap_ang6[16];
extern NJS_MKEY_A bird_flap_ang7[16];
extern NJS_MKEY_A bird_flap_ang8[16];
extern NJS_MKEY_A bird_flap_ang9[16];
extern NJS_MDATA2 bird_flap_mdata[10];
extern NJS_MOTION bird_flap_motion;
extern NJS_ACTION bird_flap_action[1];

void bird_draw(struct task *task)
{
    extern struct model_weld bird_welds[1];
    struct task_work *work;

    struct task_work shadow;
    NJS_ACTION *action;
    if (loop_count != 0) {
        return;
    }
    work = task->work;
    action = bird_flap_action;
    model_weld(action->object, action->motion,
               ((struct bird_vars *)&(work)->vars)->frame, bird_welds);
    njSetTexture_jp(&amy_texlist);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    ds_ActionClip(action, ((struct bird_vars *)&(work)->vars)->frame);
    late_DrawObjectClipEx(1);
    if (ChkPause()) {
        shadow.pos = work->pos;
        shadow.ang = work->ang;
        shadow.ang.y *= -1;
        shadow_draw(&shadow, 0.4F);
    }
}
#ifdef NON_MATCHING

/* move the bird and draw it, unless an event has control. while player 0
 * takes a drum, the bird eases toward its perch over her. while she carries
 * the drum, it keeps to her position, and its step doesn't draw it.
 * otherwise it circles her, bobbing and facing her way. it flaps half a
 * frame a step, and half a frame more for each unit it moves */
void AmyBirdExe(struct task *task)
{
    Float dx;
    NJS_POINT3 last;
    Float dz;
    struct task_work *player;
    NJS_POINT3 to;
    Float moved;
    struct task_work *work;
    player = playertwp[0];
    work = task->work;
    if (player == ((void *)0) || GetPlayerTaskPointer(0)->step == ((void *)0)) {
        FreeTask(task);
    }
    if (EV_CheckCansel() == TRUE) {
        return;
    }
    last = work->pos;
    if (amy_get_action(0) == AMY_TAKING_DRUM) {
        /* @hack spelling: up.x and up.z in one chained store, which loads 0.0F
         * into FR3 for both (FLDI0 FR3 at 0x8c0e87ee); as two stores, SHC
         * keeps 0.0F in FR15 and saves it, the stack frame grows from 72
         * bytes to 76, and 178 of 340 words differ */
        NJS_VECTOR up;
        up.x = up.z = 0.0F;
        up.y = PERCH_HEIGHT;
        njPushMatrix(&nj_unit_matrix_);
        TURN(njRotateZ, player->ang.z);
        TURN(njRotateX, player->ang.x);
        TURN(njRotateY, -player->ang.y);
        njCalcVector(NULL, &up, &to);
        late_DrawObjectClipEx(1);
        to.x += player->pos.x;
        to.y += player->pos.y;
        to.z += player->pos.z;
        dx = to.x - work->pos.x;
        dz = to.z - work->pos.z;
        work->ang.y = AdjustAngle(
            work->ang.y, (Angle)(njArcTan2(dz, -dx) * ANGLE_PER_RADIAN), 0x400);
        work->pos.x += (to.x - work->pos.x) * 0.1F;
        work->pos.y += (to.y - work->pos.y) * 0.1F;
        work->pos.z += (to.z - work->pos.z) * 0.1F;
    } else {
        if (amy_carries_drum(0) == TRUE) {
            work->pos = player->pos;
            return;
        }
        work->ang.y =
            AdjustAngle(work->ang.y, NJM_DEG_ANG(180) - player->ang.y, 0x400);
        work->ang.x = work->ang.x + 16;
        to.x = player->pos.x + (njCos(work->ang.x) * BIRD_RADIUS);
        to.z = player->pos.z + (njSin(work->ang.x) * BIRD_RADIUS);
        to.y = player->pos.y + njSin(work->ang.z += 0x400) + BIRD_HEIGHT;
        if (CalcDistance(&work->pos, &to) < BIRD_JUMP_DISTANCE) {
            work->pos.x += (to.x - work->pos.x) * 0.25F;
            work->pos.y += (to.y - work->pos.y) * 0.25F;
            work->pos.z += (to.z - work->pos.z) * 0.25F;
        } else {
            work->pos = to;
        }
    }
    moved = CalcDistance(&last, &work->pos);
    /* @hack spelling: the frame tested where it's stored, which tests the sum
     * still in FR2 (FCMP/GT FR2,FR3 at 0x8c0e8a8e); stored in a statement of
     * its own, SHC loads it again for the test, and 26 of 340 words differ */
    if ((VARS(work)->frame += (moved * 0.5F) + 0.5F) >=
        (Float)bird_flap_action[0].motion->nbFrame) {
        VARS(work)->frame = 0.0F;
    }
    bird_draw(task);
    {
        struct {
            Sint8 mode;
            Sint8 submode;
            Uint8 id;
            Uint8 tick;
            Sint16 flags;
            Sint16 timer;
            union task_vars vars;
            struct angles ang;
            NJS_POINT3 pos;
        } shadow;
        shadow.pos = work->pos;
        shadow.ang = work->ang;
        shadow.ang.y *= -1;
        shadow_draw((struct task_work *)&shadow, 0.4F);
    }
    LoopTaskC(task);
}
#else
void AmyBirdExe(struct task *task)
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
    asm_stub[0] = 32;
    asm_stub[1] = 33;
    asm_stub[2] = 34;
    asm_stub[3] = 35;
    asm_stub[4] = 36;
    asm_stub[5] = 37;
    asm_stub[6] = 38;
    asm_stub[7] = 39;
    asm_stub[0] = 40;
    asm_stub[1] = 41;
    asm_stub[2] = 42;
    asm_stub[3] = 43;
    asm_stub[4] = 44;
    asm_stub[5] = 45;
    asm_stub[6] = 46;
    asm_stub[7] = 47;
    asm_stub[0] = 48;
    asm_stub[1] = 49;
    asm_stub[2] = 50;
    asm_stub[3] = 51;
    asm_stub[4] = 52;
    asm_stub[5] = 53;
    asm_stub[6] = 54;
    asm_stub[7] = 55;
    asm_stub[0] = 56;
    asm_stub[1] = 57;
    asm_stub[2] = 58;
    asm_stub[3] = 59;
    asm_stub[4] = 60;
    asm_stub[5] = 61;
    asm_stub[6] = 62;
    asm_stub[7] = 63;
    asm_stub[0] = 64;
    asm_stub[1] = 65;
    asm_stub[2] = 66;
    asm_stub[3] = 67;
    asm_stub[4] = 68;
    asm_stub[5] = 69;
    asm_stub[6] = 70;
    asm_stub[7] = 71;
    asm_stub[0] = 72;
    asm_stub[1] = 73;
    asm_stub[2] = 74;
    asm_stub[3] = 75;
    asm_stub[4] = 76;
    asm_stub[5] = 77;
    asm_stub[6] = 78;
    asm_stub[7] = 79;
    asm_stub[0] = 80;
    asm_stub[1] = 81;
    asm_stub[2] = 82;
    asm_stub[3] = 83;
    asm_stub[4] = 84;
    asm_stub[5] = 85;
    asm_stub[6] = 86;
    asm_stub[7] = 87;
    asm_stub[0] = 88;
    asm_stub[1] = 89;
    asm_stub[2] = 90;
    asm_stub[3] = 91;
    asm_stub[4] = 92;
    asm_stub[5] = 93;
    asm_stub[6] = 94;
    asm_stub[7] = 95;
    asm_stub[0] = 96;
    asm_stub[1] = 97;
    asm_stub[2] = 98;
    asm_stub[3] = 99;
    asm_stub[4] = 100;
    asm_stub[5] = 101;
    asm_stub[6] = 102;
    asm_stub[7] = 103;
    asm_stub[0] = 104;
    asm_stub[1] = 105;
    asm_stub[2] = 106;
    asm_stub[3] = 107;
    asm_stub[4] = 108;
    asm_stub[5] = 109;
    asm_stub[6] = 110;
    asm_stub[7] = 111;
    asm_stub[0] = 112;
    asm_stub[1] = 113;
    asm_stub[2] = 114;
    asm_stub[3] = 115;
    asm_stub[4] = 116;
    asm_stub[5] = 117;
    asm_stub[6] = 118;
    asm_stub[7] = 119;
    asm_stub[0] = 120;
    asm_stub[1] = 121;
    asm_stub[2] = 122;
    asm_stub[3] = 123;
    asm_stub[4] = 124;
    asm_stub[5] = 125;
    asm_stub[6] = 126;
    asm_stub[7] = 127;
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
    asm_stub[0] = 32;
    asm_stub[1] = 33;
    asm_stub[2] = 34;
    asm_stub[3] = 35;
    asm_stub[4] = 36;
    asm_stub[5] = 37;
    asm_stub[6] = 38;
    asm_stub[7] = 39;
    asm_stub[0] = 40;
    asm_stub[1] = 41;
    asm_stub[2] = 42;
    asm_stub[3] = 43;
    asm_stub[4] = 44;
    asm_stub[5] = 45;
    asm_stub[6] = 46;
    asm_stub[7] = 47;
    asm_stub[0] = 48;
    asm_stub[1] = 49;
    asm_stub[2] = 50;
    asm_stub[3] = 51;
    asm_stub[4] = 52;
    asm_stub[5] = 53;
    asm_stub[6] = 54;
    asm_stub[7] = 55;
    asm_stub[0] = 56;
    asm_stub[1] = 57;
    asm_stub[2] = 58;
    asm_stub[3] = 59;
    asm_stub[4] = 60;
    asm_stub[5] = 61;
    asm_stub[6] = 62;
    asm_stub[7] = 63;
    asm_stub[0] = 64;
    asm_stub[1] = 65;
    asm_stub[2] = 66;
    asm_stub[3] = 67;
    asm_stub[4] = 68;
    asm_stub[5] = 69;
    asm_stub[6] = 70;
    asm_stub[7] = 71;
    asm_stub[0] = 72;
    asm_stub[1] = 73;
    asm_stub[2] = 74;
    asm_stub[3] = 75;
    asm_stub[4] = 76;
    asm_stub[5] = 77;
    asm_stub[6] = 78;
    asm_stub[7] = 79;
    asm_stub[0] = 80;
    asm_stub[1] = 81;
    asm_stub[2] = 82;
    asm_stub[3] = 83;
    asm_stub[4] = 84;
    asm_stub[5] = 85;
    asm_stub[6] = 86;
    asm_stub[7] = 87;
    asm_stub[0] = 88;
    asm_stub[1] = 89;
    asm_stub[2] = 90;
    asm_stub[3] = 91;
    asm_stub[4] = 92;
}
#endif

/* start the bird BIRD_HEIGHT over player 0, facing her way. in any act of
 * STAGE_TWINKLE, a child of its task also draws it in the mirrors */
void AmyBirdInit(struct task *task)
{
    struct task_work *player = playertwp[0];
    struct task_work *work = task->work;

    /* @bug memory: with no task for player 0, bird_init kills the bird's task
     * but goes on, and reads player->pos through the null pointer
     * (MOV.L @(32,R13),R3 at 0x8c0e8b1a) */
    if (player == NULL) {
        FreeTask(task);
    }
    work->pos = player->pos;
    work->pos.y += BIRD_HEIGHT;
    work->ang.y = NJM_DEG_ANG(180) - player->ang.y;
    task->draw = bird_draw;
    if (IN_STAGE(STAGE_TWINKLE)) {
        createMirrorTask(task);
    }
    task->step = AmyBirdExe;
}

struct task *AmyBirdStart(void)
{
    Uint16 stage_act;
    struct task *task;

    if (GetPlayerNumber() != CHARACTER_AMY) {
        return NULL;
    }
    if (game_mode != GAME_MODE_ACTION && game_mode != GAME_MODE_FIELD &&
        game_mode != GAME_MODE_TRIAL) {
        return NULL;
    }
    stage_act = GetStageNumber();
    if (stage_act < STAGE_ACT(STAGE_CHAOS0, 0)) {
        Uint16 stages[] = {
            STAGE_ACT(STAGE_TWINKLE, 1), STAGE_ACT(STAGE_TWINKLE, 2),
            STAGE_ACT(STAGE_FINAL, 0),   STAGE_ACT(STAGE_SHELTER, 0),
            STAGE_ACT(STAGE_SHELTER, 1), BIRD_STAGES_END,
        };
        Uint16 *stage;

        for (stage = stages; *stage != stage_act; stage++) {
            if (*stage == BIRD_STAGES_END) {
                return NULL;
            }
        }
    } else if (stage_act >= STAGE_ACT(STAGE_STATION_SQUARE, 0) &&
               stage_act < STAGE_ACT(STAGE_CART, 0)) {
        /* a field, where no bird flies while an event has control */
        if (EV_CheckCansel()) {
            return NULL;
        }
    } else {
        return NULL;
    }
    /* @hack redundant: the task tested against NULL, though both arms return
     * it. the test reads R0 at 0x8c0e8c4a; with task_create's result
     * returned directly, the call moves to the end and 26 of 82 words
     * differ */
    /* @hack spelling: the task assigned in the test, which copies it to R4 in
     * the BF/S's slot (MOV R0,R4 at 0x8c0e8c4e); assigned in a statement of
     * its own, SHC copies it first and tests R4, and 3 of 82 words differ */
    if ((task = CreateElementalTask(TASK_WORK, 3, AmyBirdInit)) == NULL) {
        return NULL;
    }
    return task;
}
