/* @unit 8C034DE0-8C035000 @data 8C1126AC-8C1126F8 +egflags +pool32 */
/* recorder: record pad 0 into memory, or play a recording back over it, for
 * the demos */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "debug/host.h"
#include "player/player.h"
#include "progress/demo.h"
#include "progress/recorder.h"
#include "stage/stage.h"
#include "system/pad.h"
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
void GM_WaitEventDemo(struct task *task);
void FUN_8c034de0(void);
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
Uint16 GetStageNumber(void);
Bool ChkPause(void);
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
extern Bool recording_on;
extern enum recorder_mode recording_mode;
extern enum recording_kind recording_kind;
extern int demo_next;
extern struct pad_sample *recording_next;
extern Uint32 recording_buttons;
extern void *dat_8c751454;

/* the last sample a recording fills from pad 0. PAD_SAMPLE_END fits in the
 * 128 KB after it */
#define RECORD_LAST ((struct pad_sample *)0x0cbfffe8)
/* the last sample a playback reads, past the recording's 128 KB */
#define PLAY_LAST ((struct pad_sample *)0x0cd60000)

void FUN_8c034de0(void)
{
    struct pad_sample *sample;
    Uint32 old;
    Uint32 on;
    Uint32 changed;
    int size;

    if (!recording_on) {
        return;
    }
    /* a demo of an event plays no recording */
    if (demo_event >= 0) {
        return;
    }
    sample = recording_next;
    switch (recording_mode) {
    case RECORDER_RECORD:
        if (recording_next > RECORD_LAST || (perG[0].on & PDD_DGT_TX)) {
            recording_mode = RECORDER_DONE;
            sample->on = PAD_SAMPLE_END;
            sample++;
            size = (Uint8 *)sample - (Uint8 *)DEMO_RECORDING;
            switch (GetPlayerNumber()) {
            case CHARACTER_SONIC:
                host_save_file("K_SONIC.BIN", DEMO_RECORDING, size);
                break;
            case CHARACTER_TAILS:
                host_save_file("K_MILES.BIN", DEMO_RECORDING, size);
                break;
            case CHARACTER_KNUCKLES:
                host_save_file("K_KNUCKLES.BIN", DEMO_RECORDING, size);
                break;
            case CHARACTER_AMY:
                host_save_file("K_AMY.BIN", DEMO_RECORDING, size);
                break;
            case CHARACTER_E102:
                host_save_file("K_E102.BIN", DEMO_RECORDING, size);
                break;
            case CHARACTER_BIG:
                host_save_file("K_BIG.BIN", DEMO_RECORDING, size);
                break;
            /* @hack redundant: the empty default keeps per_info[0] in R3 and
             * its on in R2 for the copy below (0x8c0360d6, 0x8c0360d8); without
             * it, the two trade and 3 of 187 words differ */
            default:
                break;
            }
        } else {
            sample->on = per[0]->on;
            sample->l = per[0]->l;
            sample->r = per[0]->r;
            sample->x1 = per[0]->x1;
            sample->y1 = per[0]->y1;
        }
        sample++;
        recording_next = sample;
        break;
    case RECORDER_PLAY:
        if (recording_next > PLAY_LAST || sample->on == PAD_SAMPLE_END) {
            recording_on = FALSE;
            stage_end(STAGE_END_QUIT);
        } else {
            on = sample->on;
            old = recording_buttons;
            per[0]->on = (per[0]->on & (1 << 3)) | on;
            per[0]->l = sample->l;
            per[0]->r = sample->r;
            per[0]->x1 = sample->x1;
            per[0]->y1 = sample->y1;
            changed = old ^ on;
            per[0]->press = (per[0]->press & (1 << 3)) | (on & changed);
            per[0]->off = ~on;
            per[0]->release = old & changed;
            recording_buttons = on;
        }
        sample++;
        recording_next = sample;
        break;
    case RECORDER_DONE:
        /* print recording_next in hex. the call that ended the recording
         * left it a sample past the end of the file it saved */
        njPrintH(NJM_LOCATION(28, 12), (Uint32)sample, 8);
        break;
    }
}
