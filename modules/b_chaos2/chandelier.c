/* @unit 0C906940-0C906E00 +r04 +egflags +pool32 +asmfunc=FUN_0c906944:0c906c40 */
/* CHAND__, Chaos 2's chandelier: six lit lamps, a shadow on the floor and
 * a lens flare at its middle. struck, it swings away from what struck it,
 * and the swing dies away */
#include <mathf.h>
#include <ninja.h>
#include <sg_xpt.h>

#include "b_chaos2/chandelier.h"
#include "b_chaos2/textures.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "effect/lens.h"
#include "object/common.h"
#include "sound/sound.h"
#include "system/task.h"
#include "system/util.h"
#include "vmu/vibration.h"
float njFloor(float x);
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void nj_constant_attr_or_(Uint32 and_attr, Uint32 or_attr);
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
void *CAlloc(int count, int size);
void Free(void *mem);
void FUN_0c906d28(struct task *task);
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
void late_DrawObject(NJS_OBJECT *object);
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
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
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

#define SE_CHANDELIER 0x160

/* a strike swings it SWING_REACH from hanging straight. the swing's phase
 * goes round once in SWING_STEPS steps, and each step the swing keeps
 * SWING_DAMP of its reach */
#define SWING_REACH NJM_DEG_ANG(40)
#define SWING_STEPS 60
#define SWING_PACE (NJM_DEG_ANG(360) / SWING_STEPS)
#define SWING_DAMP 0.985F
/* a strike rings it and shakes the pad while its pitch and roll sum to
 * less than SWING_STILL either way */
#define SWING_STILL 0.1F

/* it has LAMPS lamps, and its shadow lies flat at a y of SHADOW_Y */
#define LAMPS 6
#define SHADOW_Y 1.0F

/* its record, at its task's extra. chaos2_chandelier_step allocates its
 * 0x164 bytes (MOV.W at 0x0c907342), and the module uses only the last three
 * fields */
struct chandelier {
    Uint8 unk_00[0x158];
    /* the swing's phase. the swing's angle is cos(phase) times its reach */
    Angle phase;
    Float pitch; /* the swing's reach about x */
    Float roll; /* the swing's reach about z */
};

void chandelier_destroy(struct task *task);
void chandelier_draw(struct task *task);
void chandelier_run(struct task *task);
extern Float lamp_alpha;
extern Float lamp_red;
extern Float lamp_green;
extern Float lamp_blue;
extern Float shadow_alpha;
extern Float shadow_red;
extern Float shadow_green;
extern Float shadow_blue;
extern const Sint8 chandelier_shape_count;
extern NJS_MATERIAL chaos2_chandelier_materials[8];
extern Sint16 chaos2_chandelier_meshes0[168];
extern Sint16 chaos2_chandelier_meshes1[60];
extern Sint16 chaos2_chandelier_meshes2[24];
extern Sint16 chaos2_chandelier_meshes3[72];
extern Sint16 chaos2_chandelier_meshes4[12];
extern Sint16 chaos2_chandelier_meshes5[24];
extern Sint16 chaos2_chandelier_meshes6[12];
extern Sint16 chaos2_chandelier_meshes7[24];
extern Sint16 chaos2_chandelier_meshes8[72];
extern NJS_COLOR chaos2_chandelier_uvs0[168];
extern NJS_COLOR chaos2_chandelier_uvs1[52];
extern NJS_COLOR chaos2_chandelier_uvs2[18];
extern NJS_COLOR chaos2_chandelier_uvs3[72];
extern NJS_COLOR chaos2_chandelier_uvs4[12];
extern NJS_COLOR chaos2_chandelier_uvs5[18];
extern NJS_COLOR chaos2_chandelier_uvs6[10];
extern NJS_COLOR chaos2_chandelier_uvs7[24];
extern NJS_COLOR chaos2_chandelier_uvs8[60];
extern NJS_MESHSET chaos2_chandelier_meshsets[9];
extern NJS_POINT3 chaos2_chandelier_points[202];
extern NJS_VECTOR chaos2_chandelier_normals[202];
extern NJS_MODEL chaos2_chandelier_model;
extern NJS_OBJECT chaos2_chandelier_object;
extern NJS_MATERIAL chaos2_chandelier_shadow_materials[1];
extern Sint16 chaos2_chandelier_shadow_meshes0[27];
extern NJS_COLOR chaos2_chandelier_shadow_uvs0[24];
extern NJS_MESHSET chaos2_chandelier_shadow_meshsets[1];
extern NJS_POINT3 chaos2_chandelier_shadow_points[16];
extern NJS_VECTOR chaos2_chandelier_shadow_normals[16];
extern NJS_MODEL chaos2_chandelier_shadow_model;
extern NJS_OBJECT chandelier_shadow_object;
extern struct collision_shape chandelier_shape[1];
extern NJS_TEXANIM chandelier_texanims[2];
extern NJS_SPRITE lamp_sprite;
extern NJS_POINT3 lamps[6];
extern NJS_VECTOR shadow_reach;
extern NJS_POINT3 flare_pos;

void chandelier_destroy(struct task *task)
{
}
#ifdef NON_MATCHING

void chandelier_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct chandelier *chandelier = task->extra;
    Float swing = njCos(chandelier->phase);
    Angle pitch = (Angle)(swing * chandelier->pitch);
    Angle roll = (Angle)(swing * chandelier->roll);
    Angle ang;
    int i;
    NJS_ARGB color;

    njSetTexture_jp(MODEL(work)->texlist);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z + roll, ang);
    TURN_VIA(njRotateX, work->ang.x + pitch, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    late_DrawObject(MODEL(work)->object);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_ONE);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, NJD_COLOR_BLENDING_ONE);
    color.a = lamp_alpha;
    color.r = lamp_red;
    color.g = lamp_green;
    color.b = lamp_blue;
    njSetConstantMaterial(&color);
    for (i = 0; i < LAMPS; i++) {
        lamp_sprite.p = lamps[i];
        njDrawSprite3D(&lamp_sprite, 0,
                       NJD_SPRITE_ALPHA | NJD_SPRITE_SCALE | NJD_SPRITE_COLOR);
    }
    late_DrawObjectClipEx(1);
    {
        NJS_ARGB shadow;
        NJS_VECTOR offset;

        njPushMatrix(NULL);
        njPushMatrix(&nj_unit_matrix_);
        TURN_VIA(njRotateZ, work->ang.z + roll, ang);
        TURN_VIA(njRotateX, work->ang.x + pitch, ang);
        njCalcVector(NULL, &shadow_reach, &offset);
        late_DrawObjectClipEx(1);
        njTranslate(NULL, work->pos.x + offset.x, SHADOW_Y,
                    work->pos.z + offset.z);
        SaveControl3D();
        SaveConstantAttr();
        draw_control_set(NJD_CONTROL_3D_CONSTANT_ATTR |
                         NJD_CONTROL_3D_CONSTANT_MATERIAL);
        shadow.a = shadow_alpha;
        shadow.r = shadow_red;
        shadow.g = shadow_green;
        shadow.b = shadow_blue;
        njSetConstantMaterial(&shadow);
        nj_constant_attr_or_(~(0xe0000000 | 0x1c000000),
                             0x20000000 | 0x04000000 | 0x00100000);
        late_DrawObjectClip(&chandelier_shadow_object);
        LoadControl3D();
        LoadConstantAttr();
        late_DrawObjectClipEx(1);
    }
    {
        NJS_POINT3 flare;

        njPushMatrix(&nj_unit_matrix_);
        njTranslateV(NULL, &work->pos);
        TURN_VIA(njRotateZ, work->ang.z + roll, ang);
        TURN_VIA(njRotateX, work->ang.x + pitch, ang);
        TURN_VIA(njRotateY, work->ang.y, ang);
        njCalcPoint(NULL, &flare_pos, &flare);
        late_DrawObjectClipEx(1);
        lens_draw(&flare);
    }
}
#else
void chandelier_draw(struct task *task)
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

/* its step after the first. struck, it swings away from the task that
 * struck it, and the swing then dies away. it draws itself each step */
void chandelier_run(struct task *task)
{
    struct task_work *work = task->work;
    struct chandelier *chandelier = task->extra;
    struct task_work *other;
    Angle heading;

    if (!OnEdit(task)) {
        if (work->collision->flags & COLLISION_HIT) {
            other = work->collision->hit->owner->work;
            /* @bug logic: pitch and roll are summed before the size is
             * taken (FADD and FABS at 0x0c907230 and 0x0c907236). the two
             * cancel when the striker's heading from it was 135 or 315
             * degrees, so that swing tests as still however wide it is, and
             * each strike rings it and shakes the pad again */
            if (_builtin_fabsf(chandelier->pitch + chandelier->roll) <
                SWING_STILL) {
                dsPlay_oneshot_v(SE_CHANDELIER, 0, 0, 0, work->pos.x,
                                 work->pos.y, work->pos.z);
                VibShot(0, 4, 15, 0);
            }
            heading = (Angle)(njArcTan2(other->pos.z - work->pos.z,
                                        other->pos.x - work->pos.x) *
                              ANGLE_PER_RADIAN);
            chandelier->pitch = njCos(heading) * SWING_REACH;
            chandelier->roll = njSin(heading) * SWING_REACH;
            chandelier->phase = 0;
        }
        EntryColliList(work);
    }
    chandelier->phase += SWING_PACE;
    chandelier->pitch *= SWING_DAMP;
    chandelier->roll *= SWING_DAMP;
    chandelier_draw(task);
}

void FUN_0c906d28(struct task *task)
{
    struct task_work *work = task->work;
    struct chandelier *chandelier;

    CCL_Init(task, chandelier_shape, COLLISION_OBJECT_MUTUAL, 1,
             chandelier_shape_count);
    MODEL(work)->object = &chaos2_chandelier_object;
    MODEL(work)->texlist = &chaos2_object_texlist;
    task->destructor = chandelier_destroy;
    task->step = chandelier_run;
    task->draw = chandelier_draw;
    chandelier = task->extra = MAlloc(sizeof(struct chandelier));
    chandelier->phase = 0;
    chandelier->pitch = chandelier->roll = 0.0F;
}
