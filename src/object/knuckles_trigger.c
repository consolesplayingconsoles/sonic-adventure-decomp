/* @unit 8C0A2600-8C0A28E0 @data 8C15B408-8C15B470 +egflags +pool32 */
/* Knuckles' item trigger boxes, KN ITEM COLLI. the set editor draws and
 * labels each box. in the game a box does nothing: it ends for good once
 * player 0 is gone, and leaves once it is out of range */
#include <ninja.h>
#include <sg_xpt.h>

#include "debug/editor.h"
#include "draw/draw.h"
#include "object/knuckles_trigger.h"
#include "object/placement.h"
#include "player/player.h"
#include "system/frame.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void FUN_8c0a2898(struct task *task);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
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

/* a box's type, from the low byte of its ang.x. any value past
 * TRIGGER_RINGSPR is TRIGGER_BAD */
#define TYPE(work) TASK_TIMER(work)
#define VARS(work) ((struct knuckles_trigger_vars *)&(work)->vars)
#define SCALE_MAX 40.0F
#define NAME_BLINK 0x10
#define COLOR_BLINK 0x18
enum knuckles_trigger_type { TRIGGER_NOITEM, TRIGGER_RINGSPR, TRIGGER_BAD };

/* a box keeps its type in its work's timer */

struct knuckles_trigger_vars {
    /* whether the box works once: 1 when bits 8 to 11 of ang.x aren't all 0,
     * else 0. only the set editor's label reads it */
    Uint8 one_shot;
};
extern const Float knuckles_trigger_colors[];
extern const char *knuckles_trigger_names[];
extern const char *knuckles_trigger_shots[];

static void knuckles_trigger_draw(struct task *task)
{
    struct task_work *work = task->work;
    int index;
    const Float *color;

    if (loop_count != 0) {
        return;
    }
    index = TYPE(work) * 6;
    if (++work->tick & COLOR_BLINK) {
        index += 3;
    }
    color = knuckles_trigger_colors + index;
    SetMaterial(0.01F, color[0], color[1], color[2]);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    njScaleV(NULL, &work->scl);
    late_DrawObjectClip(&marker_box_object);
    late_DrawObjectClipEx(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}

static void ERSC_DisplayEditInfo(struct task *task)
{
    struct task_work *work = task->work;

    if (loop_count != 0) {
        return;
    }
    work->tick++;
    if (OnEdit(task)) {
        if (work->tick & NAME_BLINK) {
            njPrintC(NJM_LOCATION(8, 8), "<KN ITEM COLLI>");
        } else {
            njPrintC(NJM_LOCATION(8, 8), "<             >");
        }
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_X), "-> TYPE ");
        njPrintC(NJM_LOCATION(25, EDITOR_ROW_ANG_X),
                 knuckles_trigger_names[TYPE(work)]);
        njPrintC(NJM_LOCATION(37, EDITOR_ROW_ANG_X),
                 knuckles_trigger_shots[VARS(work)->one_shot]);
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Y), "-> ROT Y");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_ANG_Z), "->      ");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_X), "-> SCL X");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Y), "-> SCL Y");
        njPrintC(EDITOR_LABEL(EDITOR_ROW_SCL_Z), "-> SCL Z");
    }
}

/* hold each axis of the box's scale from 1 to SCALE_MAX, and take its type
 * and one_shot from ang.x */
static void knuckles_trigger_take_settings(struct task_work *work)
{
    if (work->scl.x < 1.0F) {
        work->scl.x = 1.0F;
    } else if (work->scl.x > SCALE_MAX) {
        work->scl.x = SCALE_MAX;
    }
    if (work->scl.y < 1.0F) {
        work->scl.y = 1.0F;
    } else if (work->scl.y > SCALE_MAX) {
        work->scl.y = SCALE_MAX;
    }
    if (work->scl.z < 1.0F) {
        work->scl.z = 1.0F;
    } else if (work->scl.z > SCALE_MAX) {
        work->scl.z = SCALE_MAX;
    }
    /* @hack spelling: the type assigned in the test, which compares the R0 it
     * stores (MOV.W R0,@(6,R4) at 0x8c0a89fe, EXTU.W R0,R0 at 0x8c0a8a00);
     * assigned apart, SHC loads it back first and 19 of 53 words differ */
    if ((TYPE(work) = (Uint8)work->ang.x) >= TRIGGER_BAD) {
        TYPE(work) = TRIGGER_BAD;
    }
    /* @hack spelling: one_shot assigned in the test, as the type is
     * (0x8c0a8a16, 0x8c0a8a18); assigned apart, 7 of 53 words differ */
    if ((VARS(work)->one_shot = (work->ang.x & 0xf00) >> 8) > 1) {
        VARS(work)->one_shot = 1;
    }
}

/* take the box's settings. in edit mode, draw and label the box and do no
 * more. with no player 0 the box ends for good, and out of range it
 * leaves */
static void knuckles_trigger_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    /* @hack redundant: two points whose address is stored and never read,
     * which give the image's 36-byte frame (ADD #-28,R15 at 0x8c0a8a2a);
     * without them, the frame is 12 bytes and 23 of 40 words differ */
    NJS_POINT3 unused[2];
    void *taken = unused;

    knuckles_trigger_take_settings(work);
    if (edit_mode) {
        knuckles_trigger_draw(task);
        ERSC_DisplayEditInfo(task);
        return;
    }
    if (player == NULL) {
        DeadOut(task);
        return;
    }
    /* @hack redundant: a return where the function ends, which keeps the
     * image's TST R0,R0 of the result (0x8c0a8a9a); without it, 5 of 40 words
     * differ */
    if (CheckRangeOut(task)) {
        return;
    }
}

void FUN_8c0a2898(struct task *task)
{
    knuckles_trigger_take_settings(task->work);
    knuckles_trigger_step(task);
    task->step = knuckles_trigger_step;
}
