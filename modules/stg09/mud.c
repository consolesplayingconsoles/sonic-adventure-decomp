/* @unit 0C91DB80-0C91DE80 @data 0CB236C0-0CB236D4 +egflags +pool32 */
/* O MUD tints the players' palette by player 0's mud level, and O MUDOUT
 * lowers the level */
#include <ninja.h>
#include <sg_xpt.h>
#include <string.h>

#include "debug/editor.h"
#include "draw/model.h"
#include "object/placement.h"
#include "player/player.h"
#include "sound/sound.h"
#include "stg09/casino.h"
#include "stg09/helpers.h"
#include "stg09/mud.h"
#include "system/task.h"
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
extern NJS_MATRIX nj_unit_matrix_;
void *memmove(void *s1, const void *s2, size_t n);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
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
void SetVelocityAndRotationAndNoconTimeWithSpinDashP(Uint8 player,
                                                     NJS_VECTOR *speed,
                                                     const Angle *ang,
                                                     Sint16 steps);
void SetPositionP(Uint8 player, Float x, Float y, Float z);
Bool GetPlayerPosition(Uint8 player, int steps, NJS_POINT3 *pos,
                       struct angles *ang);
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
int thunk_FUN_8c09cbc0(char *name, void *dest);
void ObjCasino_InitTexUvInfo(struct uv_shift *rows, int count);
void ObjCasino_SetTexUvInfo(struct uv_shift *rows, int count);
void ObjCasino_ResetTexUvInfo(struct uv_shift *rows, int count);
void ObjCasino_EndTexUvInfo(struct uv_shift *rows, int count);
Float FUN_0c91dca8(void);

/* destroyed beyond about 600 units of the camera and player 0 */
#define RANGE ((600.0F * 600.0F) + 10.0F)

/* O MUDOUT lowers the level by MUD_OUT_DROP each step for MUD_OUT_STEPS
 * steps. SE_MUD_OUT plays MUD_OUT_SOUND_DELAY steps after player 0 enters,
 * if player 0's mode is still PLAYER_MODE_MUD_OUT */
#define MUD_OUT_STEPS 150
#define MUD_OUT_DROP 0.003F
#define MUD_OUT_SOUND_DELAY 68

/* while a change of level is pending, O MUD counts its steps. it tints the
 * palette by the level on the step after it has counted TINT_DELAY */
#define TINT_DELAY 5

#define SE_MUD_OUT 262

#define OUT_VARS(work) ((struct mud_out_vars *)&(work)->vars)
#define VARS(work) ((struct mud_vars *)&(work)->vars)
struct mud_out_vars {
    /* 0 while no sound is pending. player 0's entry sets it to 1, and it
     * rises by 1 each step until it passes MUD_OUT_SOUND_DELAY */
    Uint32 sound;
};

struct mud_vars {
    Uint8 unk_08[4];
    Uint32 *muddy; /* a copy of MUDDY_PALETTE */
    Uint32 *clean; /* a copy of the players' palette as it was */
};
extern Float mud_level;
extern int mud_changed;

void ExecMudout(struct task *task);
void mud_destroy(struct task *task);
void ExecMud(struct task *task);

void ObjectCasinoMudout(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, RANGE)) {
        task->step = ExecMudout;
        work->timer = 0;
        OUT_VARS(work)->sound = 0;
    }
}

/* set player 0's mode to PLAYER_MODE_MUD_OUT the first time it is on land
 * within scl.x of O MUDOUT. then lower the level for MUD_OUT_STEPS steps */
void ExecMudout(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player;

    if (CheckRangeOutWithR(task, RANGE)) {
        return;
    }
    if (OnEdit(task)) {
        njPrintC(EDITOR_LABEL_RIGHT(EDITOR_ROW_SCL_X), "-> scl ");
        ObjCasino_DrawSphere(&work->pos,
                             work->scl.x > 0.0F ? work->scl.x : 0.0F);
        return;
    }
    if (OUT_VARS(work)->sound > 0) {
        /* @hack spelling: the test for the wrap to 0, written <= 0 for the
         * image's CMP/HI (0x0c91f4cc). sound is a Uint32, so <= 0 holds only
         * at 0. the decrement undoes the wrap. as == 0, 2 of mud_out_run's 127
         * words differ */
        if (++OUT_VARS(work)->sound <= 0) {
            --OUT_VARS(work)->sound;
        }
        if (OUT_VARS(work)->sound > MUD_OUT_SOUND_DELAY) {
            if (playertwp[0]->submode == PLAYER_MODE_MUD_OUT) {
                dsPlay_oneshot(SE_MUD_OUT, 0, 0, 0);
            }
            OUT_VARS(work)->sound = 0;
        }
    }
    /* @hack spelling: player assigned in the test, which keeps it on the stack
     * (MOV.L R3,@(8,R15) at 0x0c91f500). assigned apart, 91 of
     * mud_out_run's 127 words differ */
    if ((player = playertwp[0])->flags & PLAYER_ON_LAND) {
        if (CalcDistance(&work->pos, &player->pos) < work->scl.x) {
            SetInputP(0, PLAYER_MODE_MUD_OUT);
            work->scl.x = -1.0F;
            work->timer = 1;
            OUT_VARS(work)->sound = 1;
        }
    }
    if ((*(Uint16 *)&(work)->timer) > 0) {
        mud_set_level(FUN_0c91dca8() - 0.003F);
        work->timer++;
        if (TASK_TIMER(work) > MUD_OUT_STEPS) {
            work->timer = 0;
        }
    }
}

Float FUN_0c91dca8(void)
{
    return mud_level;
}

void mud_set_level(Float level)
{
    if (level > 1.0F) {
        level = 1.0F;
    }
    if (level < 0.0F) {
        level = 0.0F;
    }
    if (mud_level != level) {
        mud_changed = 1;
        mud_level = level;
    }
}

void mud_step(struct task *task)
{
    struct task_work *work = task->work;

    task->destructor = mud_destroy;
    task->step = ExecMud;
    if (OnEdit(task)) {
        VARS(work)->clean = NULL;
        VARS(work)->muddy = NULL;
        return;
    }
    ((struct mud_vars *)&(work)->vars)->clean =
        MAlloc(sizeof(draw_palettes[2]));
    ((struct mud_vars *)&(work)->vars)->muddy =
        MAlloc(sizeof(draw_palettes[2]));
    memmove(((struct mud_vars *)&(work)->vars)->clean, draw_palettes[2],
            sizeof(draw_palettes[2]));
    memmove(((struct mud_vars *)&(work)->vars)->muddy, ((Uint8 *)0x0cb74000),
            sizeof(draw_palettes[2]));
    (*(Uint16 *)&(work)->timer) = 0xffff;
}

void mud_destroy(struct task *task)
{
    struct task_work *work = task->work;

    if (!OnEdit(task)) {
        if (VARS(work)->clean && VARS(work)->muddy) {
            casino_blend_palette(VARS(work)->clean, VARS(work)->muddy,
                                 draw_palettes[DRAW_PLAYER_PALETTE], 0.0F);
        }
        Free(VARS(work)->clean);
        Free(VARS(work)->muddy);
    }
}

void ExecMud(struct task *task)
{
    struct task_work *work = task->work;

    if (OnEdit(task)) {
        njPrintC(NJM_LOCATION(20, EDITOR_ROW_SCL_X), "Only 1 Obj!");
        return;
    }
    /* @bug logic: TASK_TIMER reads the timer unsigned, so the test never
     * holds (EXTU.W and CMP/PZ at 0x0c91f6c2 and 0x0c91f6c4). the 0xffff
     * mud_step leaves in the timer reads as 65535, not -1, and the first
     * step tints no palette */
    if (TASK_TIMER(work) < 0) {
        /* @hack spelling: the palette through a local of its own, which SHC
         * loads into R6 ahead of the level (0x0c91f6d0, 0x0c91f6d2). passed
         * directly, the two trade, and 2 of mud_run's 59 words differ */
        Uint32 *palette = draw_palettes[DRAW_PLAYER_PALETTE];

        casino_blend_palette(VARS(work)->clean, VARS(work)->muddy, palette,
                             mud_level);
        work->timer = 0;
        mud_changed = 0;
    }
    if (mud_changed) {
        work->timer++;
        if (TASK_TIMER(work) > TINT_DELAY) {
            /* @hack spelling: the palette through a local of its own, which SHC
             * loads into R6 ahead of the level (0x0c91f6fa, 0x0c91f6fc).
             * passed directly, the two trade, and 2 of mud_run's 59 words
             * differ */
            Uint32 *palette = draw_palettes[DRAW_PLAYER_PALETTE];

            casino_blend_palette(VARS(work)->clean, VARS(work)->muddy, palette,
                                 mud_level);
            mud_changed = 0;
            work->timer = 0;
        }
    }
}
