/* @unit 8C10A060-8C10A420 +spflags +pool32 +synth16 */
/* talks: what player 0 starts talking to by pressing grab near it */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "player/player.h"
#include "player/talk.h"
#include "system/math.h"
#include "system/pad.h"
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
void pdExecPeripheralServerUser(void);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
extern struct task_work *playertwp[];
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
Float ghUnitVector(NJS_VECTOR *vector, NJS_VECTOR *out);
Float CalcDistance2(NJS_POINT3 *from, NJS_POINT3 *to);
Uint32 ghBlendColors(Uint32 color, Uint32 by);
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
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

/* a talk starts only while player 0 is nearer to it in x and z than
 * TALK_FARTHEST */
#define TALK_FARTHEST 100.0F
/* a TALK_LEVEL talk starts only while player 0 is less than LEVEL_HEIGHT
 * above or below it */
#define LEVEL_HEIGHT 10.0F
/* a bearing is how far one thing faces off the way to another. a
 * TALK_FACING talk starts only while player 0's bearing to it is less than
 * PLAYER_ARC. a talk with an ang starts only while its bearing to player 0
 * is less than TALK_ARC */
#define PLAYER_ARC NJM_DEG_ANG(40)
#define TALK_ARC NJM_DEG_ANG(80)

/* a talk on talk_list, as talk_add gave it */
struct talk {
    struct talk *prev;
    struct talk *next;
    void *id; /* what talk_add and talk_remove find it by */
    NJS_POINT3 *pos; /* where it stands, or null for a fallback talk */
    Angle *ang; /* the way it faces, or null for every way */
    Bool *active; /* TRUE while the talk goes on */
    Float radius; /* its reach, added to player 0's radius */
    Sint32 flags; /* TALK_LEVEL and TALK_FACING */
};

static void inputhook_exec(struct task *task);
static void talk_manager_destroy(struct task *task);
static Bool talk_find(void *id, struct talk **found);
static void talk_free_all(void);
extern struct talk *talk_list;
extern struct talk *talk_current;

struct task *InputHookInit(void)
{
    struct task *task = CreateElementalTask(0, 0, inputhook_exec);

    talk_list = NULL;
    talk_current = NULL;
    if (task != NULL) {
        task->destructor = talk_manager_destroy;
    }
    return task;
}

Bool InputHookSet(void *id, NJS_POINT3 *pos, Angle *ang, Bool *active,
                  Float radius, Sint32 flags)
{
    struct talk *talk;
    struct talk *last;

    if (!talk_find(id, &talk)) {
        last = talk;
        talk = MAlloc(sizeof(*talk));
        if (talk == NULL) {
            return FALSE;
        }
        talk->prev = last;
        if (last != NULL) {
            last->next = talk;
        } else {
            talk_list = talk;
        }
        talk->next = NULL;
    }
    talk->flags = flags;
    talk->pos = pos;
    talk->ang = ang;
    talk->active = active;
    talk->radius = radius;
    talk->id = id;
    return TRUE;
}

void InputHookRelease(void)
{
    struct talk *talk = talk_current;

    if (talk != NULL) {
        *talk->active = FALSE;
        talk_current = NULL;
    }
    PadReadOnP(PAD_BOTH_PLAYERS);
}

void InputHookDelete(void *id)
{
    struct talk *talk;
    struct talk *prev;
    struct talk *next;

    if (talk_find(id, &talk)) {
        prev = talk->prev;
        next = talk->next;
        if (talk == talk_current) {
            InputHookRelease();
        }
        if (prev != NULL) {
            prev->next = next;
        } else {
            talk_list = next;
        }
        if (next != NULL) {
            next->prev = prev;
        }
        Free(talk);
    }
}

/* set the talk's active TRUE and take the pads from the players. pad_scan
 * then clears their buttons, the press of grab included. player 0 stops */
static void talk_start(struct talk *talk)
{
    *talk->active = TRUE;
    talk_current = talk;
    PadReadOffP(PAD_BOTH_PLAYERS);
    pad_scan();
    player_clear_speed(playermwp[0], GetPlayerWorkPointer(0));
}

/* when player 0 presses grab and no talk goes on, start a talk. it is the
 * nearest in reach whose flags and ang allow it. the first talk with no pos
 * starts when no talk with a pos qualifies */
static void inputhook_exec(struct task *task)
{
    /* @hack redundant: work, set and never read, which puts heading in R10
     * and angle_arc_tan2's address in R9 (0x8c1193b4, 0x8c1193ba); without
     * it, the two trade registers and 7 of 197 words differ */
    struct task_work *work = task->work;
    struct talk *head;
    struct talk *talk;
    struct talk *best;
    struct player *record;
    NJS_POINT3 pos;
    struct angles ang;
    NJS_VECTOR delta;
    /* @hack redundant: 4 bytes of frame that no code reads, of a type unknown,
     * declared as a Float[1]. the image's ADD #-40,R15 reserves them in its
     * 80-byte frame (0x8c119300); without them, 121 of 197 words differ */
    Float unused[1];
    /* the square of TALK_FARTHEST, then of the nearest talk's distance */
    Float nearest;
    Float player_radius;
    Angle direction;
    Angle player_bearing;
    Angle talk_bearing;
    /* @hack spelling: ang.y through heading, which SHC keeps in R10 (MOV
     * R15,R10 and ADD #20,R10 at 0x8c1193b4 and 0x8c1193be). read as ang.y,
     * angle_arc_tan2's address takes R10 in place of R9, the frame is 76
     * bytes, not 80, and 124 of 197 words differ */
    Angle *heading;
    Float reach; /* the square of the talk's reach */
    Float distance; /* the square of the talk's distance in x and z */

    /* @hack redundant: a loop that never runs, which SHC deletes. it puts
     * talk_list's address in R2 and pad_grab_buttons in R3 (0x8c119302,
     * 0x8c119312); without it, the two trade registers and 4 of 197 words
     * differ */
    while (0) {
    }
    head = talk_list;
    if (head == NULL || !PAD_BUTTONS(perG[0].press, pad_grab_buttons) ||
        talk_current != NULL) {
        return;
    }
    talk = head;
    best = NULL;
    nearest = TALK_FARTHEST * TALK_FARTHEST;
    record = GetPlayerWorkPointer(0);
    player_radius = record != NULL ? record->consts.radius : 0.0F;
    GetPlayerPosition(0, 0, &pos, &ang);
    heading = &ang.y;
    do {
        if (talk->pos == NULL) {
            if (best == NULL) {
                best = talk;
            }
        } else {
            delta = pos;
            VECTOR_DIFF(&delta, &delta, talk->pos);
            direction = angle_arc_tan2(delta.x, delta.z);
            /* each bearing is 0 where the talk doesn't ask for it */
            player_bearing =
                (talk->flags & TALK_FACING)
                    ? (Sint16)(*heading + direction + NJM_DEG_ANG(90))
                    : 0;
            talk_bearing =
                talk->ang != NULL
                    ? (Sint16)(direction - *talk->ang + NJM_DEG_ANG(90))
                    : 0;
            if (njAbs(player_bearing) < PLAYER_ARC &&
                njAbs(talk_bearing) < TALK_ARC) {
                reach = (talk->radius + player_radius) *
                        (talk->radius + player_radius);
                distance = (delta.x * delta.x) + (delta.z * delta.z);
                if (!(talk->flags & TALK_LEVEL) ||
                    njAbs(delta.y) < LEVEL_HEIGHT) {
                    if (distance < reach && distance < nearest) {
                        nearest = distance;
                        best = talk;
                    }
                }
            }
        }
        talk = talk->next;
    } while (talk != NULL);
    if (best != NULL) {
        talk_start(best);
    }
}

static void talk_manager_destroy(struct task *task)
{
    talk_free_all();
}

/* TRUE when id has a talk, which goes to *found. FALSE when it hasn't, and
 * *found gets the last talk on the list, or null */
static Bool talk_find(void *id, struct talk **found)
{
    struct talk *talk;

    *found = NULL;
    for (talk = talk_list; talk != NULL; talk = talk->next) {
        *found = talk;
        if (talk->id == id) {
            return TRUE;
        }
    }
    return FALSE;
}

static void talk_free_all(void)
{
    struct talk *talk = talk_list;
    struct talk *gone;

    while ((gone = talk) != NULL) {
        talk = talk->next;
        Free(gone);
    }
    talk_list = NULL;
}
