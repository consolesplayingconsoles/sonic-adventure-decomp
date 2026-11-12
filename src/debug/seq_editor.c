/* @unit 8C0A3EE0-8C0A5580 @data 8C15B54C-8C15B5B8 +r04 +egflags +pool32 */
/* the SEQ EDITOR, a program of the <SELECT PROGRAM> menu. its pages set the
 * event flags, the events played and the stages cleared. they go to a stage
 * or a section of the story, and show where player 0 is */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "debug/debug.h"
#include "debug/editor.h"
#include "debug/seq_editor.h"
#include "draw/draw.h"
#include "player/player.h"
#include "progress/progress.h"
#include "progress/story.h"
#include "sound/sound.h"
#include "stage/stage.h"
#include "system/pad.h"
#include "system/task.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void FUN_8c6409c0(Int loc, Int val, Int digit);
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
Bool OnEdit(struct task *task);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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
int FUN_8c090e56(int character);
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
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);

/* the text's colors. TEXT_LIT colors most text, and each box's rim.
 * TEXT_DIM marks a value that is off, and each row of a stage list the
 * cursor isn't on. while a page runs, it also marks each menu row but that
 * page's. TEXT_CURSOR colors the cursor and each list's heading */
#define TEXT_LIT 0xffa0a0a0
#define TEXT_DIM 0xff606060
#define TEXT_CURSOR 0xffff0000
/* the section the story is in, on the SEQ page */
#define TEXT_CURRENT 0xff00ff00
/* each box's fill: black, half transparent */
#define BOX_FILL 0x7f000000

/* the menu's pages, the last of them EXIT */
#define SEQ_PAGES 7
#define SEQ_EXIT (SEQ_PAGES - 1)
/* the rows the FLAG, EVENT and SEQ lists show at once. each list scrolls
 * to keep the cursor from its window's row LIST_CURSOR_TOP to row
 * LIST_CURSOR_BOTTOM, counting from 0, where the list's ends allow */
#define LIST_ROWS 14
#define LIST_CURSOR_TOP 5
#define LIST_CURSOR_BOTTOM 8
/* the rows of the SCENE list, seq_scenes */
#define SEQ_SCENES 76
/* the rows COMPLT lists: STAGE_PRACTICE to STAGE_E101_R, then
 * STAGE_SHOOTING1's two acts */
#define SEQ_STAGES 28
/* the rows the SCENE and COMPLT lists show, and the middle one, which the
 * cursor is on */
#define STAGE_ROWS_SHOWN 11
#define STAGE_CURSOR_ROW (STAGE_ROWS_SHOWN / 2)

#define SCENE_MODES 2
enum seq_mode {
    SEQ_OPEN = 2, /* opens the menu, with no page running */
    SEQ_RUN, /* runs seq_menu until it returns -1 */
    SEQ_CLOSE
};

/* what the SCENE page's pad chooses: L and R switch between the two */
enum seq_scene_mode { SCENE_STAGE, SCENE_ENTRANCE };

/* a translucent box behind a page's text, with a rim */
struct seq_box {
    Float x, y;
    Float width, height;
    Uint32 color;
};

struct seq_page {
    char *name;
    int (*exec)(void); /* -1 goes back to the menu */
};

int seq_menu(void);
int seq_flag_page(void);
int seq_event_page(void);
int seq_scene_page(void);
int seq_section_page(void);
int seq_complete_page(void);
int seq_debug_page(void);
void seq_draw_box(struct seq_box *box);
extern Sint16 seq_characters[6];
extern struct seq_box seq_menu_box;
extern struct seq_box seq_scene_box;
extern struct seq_box seq_stage_box;
extern struct seq_box seq_flag_box;
extern struct seq_box seq_section_box;
extern struct seq_box seq_debug_box;
extern NJS_TEXLIST seq_texlist;
extern NJS_TEXANIM seq_texanims[6];
extern struct seq_page seq_pages[7];
extern char *seq_off_on[2];
extern char *seq_no_yes[2];
extern Uint8 seq_scenes[76][2];
extern enum seq_mode seq_mode;
extern int seq_page;
extern int seq_menu_cursor;
extern Uint32 dat_8c7aabac;
extern int seq_scene_cursor;
extern int seq_scene_entrance;
extern int seq_flag_cursor;
extern int seq_flag_top;
extern int seq_event_cursor;
extern int seq_event_top;
extern int seq_complete_cursor;
extern Uint32 dat_8c7aabcc;
extern int seq_section_cursor;
extern int seq_section_top;
extern enum seq_scene_mode seq_scene_mode;

void seq_editor_init(void)
{
    seq_mode = SEQ_OPEN;
}

int seq_editor_exec(void)
{
    switch (seq_mode) {
    case SEQ_OPEN:
        seq_page = -1;
        seq_mode = SEQ_RUN;
        break;
    case SEQ_RUN:
        if (seq_menu() == -1) {
            seq_mode = SEQ_CLOSE;
        }
        njPrintColor(0xffffffff);
        break;
    case SEQ_CLOSE:
        seq_mode = SEQ_OPEN;
        return -1;
    }
    editor_take_buttons(0, PDD_DGT_TL | PDD_DGT_TR | PDD_DGT_TX | PDD_DGT_TY |
                               PDD_DGT_ST | PDD_DGT_TA | PDD_DGT_TB);
    return 0;
}

/* up and down move the menu's cursor, which stops at the ends. a choice
 * runs the page at the cursor, beside the dimmed menu, until the page
 * returns -1. cancel moves the cursor to EXIT. return -1 when EXIT is
 * chosen, otherwise 0 */
int seq_menu(void)
{
    int i;

    seq_draw_box(&seq_menu_box);
    if (seq_page == -1) {
        if (pad_press_live[0] & PDD_DGT_KU) {
            seq_menu_cursor--;
        } else if (pad_press_live[0] & PDD_DGT_KD) {
            seq_menu_cursor++;
        }
        if (seq_menu_cursor < 0) {
            seq_menu_cursor = 0;
        } else if (seq_menu_cursor >= SEQ_PAGES) {
            seq_menu_cursor = SEQ_PAGES - 1;
        }
        if (PAD_BUTTONS(pad_press_live[0], pad_choose_buttons)) {
            if (seq_menu_cursor == SEQ_EXIT) {
                return -1;
            } else {
                seq_page = seq_menu_cursor;
            }
        } else if (PAD_BUTTONS(pad_press_live[0], pad_cancel_buttons)) {
            seq_menu_cursor = SEQ_EXIT;
        }
        njPrintColor(TEXT_LIT);
        for (i = 0; i < SEQ_PAGES; i++) {
            njPrintC(NJM_LOCATION(4, i + 8), seq_pages[i].name);
        }
        njPrintColor(TEXT_CURSOR);
        njPrintC(NJM_LOCATION(3, seq_menu_cursor + 8), ">");
    } else {
        if (seq_pages[seq_menu_cursor].exec() == -1) {
            seq_page = -1;
        }
        njPrintColor(TEXT_DIM);
        for (i = 0; i < SEQ_PAGES; i++) {
            if (i == seq_menu_cursor) {
                njPrintColor(TEXT_LIT);
            } else {
                njPrintColor(TEXT_DIM);
            }
            njPrintC(NJM_LOCATION(4, i + 8), seq_pages[i].name);
        }
    }
    return 0;
}

/* FLAG: the event flags, by number. up and down move the cursor a flag a
 * press, and left and right a flag each step while held. a choice turns the
 * cursor's flag on or off */
int seq_flag_page(void)
{
    int move = 0;
    int i;
    int flag;
    int on;

    if (PAD_BUTTONS(pad_press_live[0], pad_cancel_buttons)) {
        return -1;
    } else if (PAD_BUTTONS(pad_press_live[0], pad_choose_buttons)) {
        dsPlay_oneshot(SE_CHOOSE, 0, 0, 0);
        seqVars[seq_flag_cursor] = !seqVars[seq_flag_cursor];
    }
    if ((pad_press_live[0] & PDD_DGT_KU) || (pad_held_live[0] & PDD_DGT_KL)) {
        move--;
    }
    if ((pad_press_live[0] & PDD_DGT_KD) || (pad_held_live[0] & PDD_DGT_KR)) {
        move++;
    }
    if (move < 0) {
        seq_flag_cursor += move;
        if (seq_flag_cursor < 0) {
            seq_flag_cursor = 0;
        }
        if (seq_flag_cursor < seq_flag_top + LIST_CURSOR_TOP) {
            seq_flag_top += move;
        }
    } else if (move > 0) {
        seq_flag_cursor += move;
        if (seq_flag_cursor > FLAG_COUNT - 1) {
            seq_flag_cursor = FLAG_COUNT - 1;
        }
        if (seq_flag_cursor > seq_flag_top + LIST_CURSOR_BOTTOM) {
            seq_flag_top += move;
        }
    }
    if (seq_flag_top < 0) {
        seq_flag_top = 0;
    } else if (seq_flag_top > FLAG_COUNT - LIST_ROWS) {
        seq_flag_top = FLAG_COUNT - LIST_ROWS;
    }
    for (i = 0, flag = seq_flag_top; i < LIST_ROWS; i++, flag++) {
        on = seqVars[flag] == 0 ? 0 : 1;
        if (seq_flag_cursor == flag) {
            njPrintColor(TEXT_CURSOR);
            njPrintC(NJM_LOCATION(13, i + 10), ">");
        }
        njPrintColor(TEXT_LIT);
        njPrintH(NJM_LOCATION(14, i + 10), flag, 4);
        if (on == 1) {
            njPrintColor(TEXT_LIT);
        } else {
            njPrintColor(TEXT_DIM);
        }
        njPrintC(NJM_LOCATION(19, i + 10), seq_off_on[on]);
    }
    seq_draw_box(&seq_flag_box);
    return 0;
}

/* EVENT: as FLAG, for whether each event has played */
int seq_event_page(void)
{
    int move = 0;
    int i;
    int event;
    int on;

    if (PAD_BUTTONS(pad_press_live[0], pad_cancel_buttons)) {
        return -1;
    } else if (PAD_BUTTONS(pad_press_live[0], pad_choose_buttons)) {
        dsPlay_oneshot(SE_CHOOSE, 0, 0, 0);
        evExecFlag[seq_event_cursor] = !evExecFlag[seq_event_cursor];
    }
    if ((pad_press_live[0] & PDD_DGT_KU) || (pad_held_live[0] & PDD_DGT_KL)) {
        move--;
    }
    if ((pad_press_live[0] & PDD_DGT_KD) || (pad_held_live[0] & PDD_DGT_KR)) {
        move++;
    }
    if (move < 0) {
        seq_event_cursor += move;
        if (seq_event_cursor < 0) {
            seq_event_cursor = 0;
        }
        if (seq_event_cursor < seq_event_top + LIST_CURSOR_TOP) {
            seq_event_top += move;
        }
    } else if (move > 0) {
        seq_event_cursor += move;
        if (seq_event_cursor > EVENT_COUNT - 1) {
            seq_event_cursor = EVENT_COUNT - 1;
        }
        if (seq_event_cursor > seq_event_top + LIST_CURSOR_BOTTOM) {
            seq_event_top += move;
        }
    }
    if (seq_event_top < 0) {
        seq_event_top = 0;
    } else if (seq_event_top > EVENT_COUNT - LIST_ROWS) {
        seq_event_top = EVENT_COUNT - LIST_ROWS;
    }
    for (i = 0, event = seq_event_top; i < LIST_ROWS; i++, event++) {
        on = evExecFlag[event] == 0 ? 0 : 1;
        if (seq_event_cursor == event) {
            njPrintColor(TEXT_CURSOR);
            njPrintC(NJM_LOCATION(13, i + 10), ">");
        }
        njPrintColor(TEXT_LIT);
        njPrintH(NJM_LOCATION(14, i + 10), event, 4);
        if (on == 1) {
            njPrintColor(TEXT_LIT);
        } else {
            njPrintColor(TEXT_DIM);
        }
        njPrintC(NJM_LOCATION(19, i + 10), seq_off_on[on]);
    }
    seq_draw_box(&seq_flag_box);
    return 0;
}

/* SCENE: a stage and act from the list, which wraps, and an entrance by
 * number. a choice fades out to the stage and act at the cursor, and sets
 * the entrance it starts at */
int seq_scene_page(void)
{
    int i;
    int scene;
    int stage;
    int act;

    if (PAD_BUTTONS(pad_press_live[0], pad_cancel_buttons)) {
        return -1;
    } else if (PAD_BUTTONS(pad_press_live[0], pad_choose_buttons)) {
        Sint16 next_stage = seq_scenes[seq_scene_cursor][0];
        Sint16 next_act = seq_scenes[seq_scene_cursor][1];

        stage_fade_to(next_stage, next_act);
        stage_set_entrance(seq_scene_entrance);
        dsPlay_oneshot(SE_CHOOSE, 0, 0, 0);
    }
    if (pad_press_live[0] & PDD_DGT_TL) {
        seq_scene_mode--;
    } else if (pad_press_live[0] & PDD_DGT_TR) {
        seq_scene_mode++;
    }
    if (seq_scene_mode < 0) {
        seq_scene_mode = SCENE_MODES - 1;
    } else if (seq_scene_mode >= SCENE_MODES) {
        seq_scene_mode = 0;
    }
    switch (seq_scene_mode) {
    case SCENE_STAGE:
        njPrintColor(TEXT_CURSOR);
        njPrintC(NJM_LOCATION(14, 10), "SELECT STAGE");
        if ((pad_press_live[0] & PDD_DGT_KU) ||
            (pad_held_live[0] & PDD_DGT_KL)) {
            seq_scene_cursor--;
        } else if ((pad_press_live[0] & PDD_DGT_KD) ||
                   (pad_held_live[0] & PDD_DGT_KR)) {
            seq_scene_cursor++;
        }
        if (seq_scene_cursor < 0) {
            seq_scene_cursor = SEQ_SCENES - 1;
        } else if (seq_scene_cursor >= SEQ_SCENES) {
            seq_scene_cursor = 0;
        }
        for (scene = seq_scene_cursor + SEQ_SCENES - STAGE_CURSOR_ROW, i = 0;
             i < STAGE_ROWS_SHOWN; i++, scene++) {
            scene %= SEQ_SCENES;
            if (scene == seq_scene_cursor) {
                njPrintColor(TEXT_LIT);
            } else {
                njPrintColor(TEXT_DIM);
            }
            stage = seq_scenes[scene][0];
            act = seq_scenes[scene][1];
            debug_print_stage_name(NJM_LOCATION(14, i + 12),
                                   STAGE_ACT(stage, act));
        }
        break;
    case SCENE_ENTRANCE:
        njPrintColor(TEXT_CURSOR);
        njPrintC(NJM_LOCATION(14, 10), "SELECT ENTRANCE");
        if (pad_press_live[0] & PDD_DGT_KU) {
            seq_scene_entrance--;
        } else if (pad_press_live[0] & PDD_DGT_KD) {
            seq_scene_entrance++;
        }
        break;
    }
    seq_draw_box(&seq_scene_box);
    seq_draw_box(&seq_stage_box);
    njPrintColor(0xffa0a0a0);
    njPrintC(((14) << 16 | (4)), "STAGE:");
    debug_print_stage_name(((20) << 16 | (4)),
                           ((seq_scenes[seq_scene_cursor][0]) << 8 |
                            (seq_scenes[seq_scene_cursor][1])));
    njPrintC(((14) << 16 | (5)), "ENTER:");
    FUN_8c6409c0(((20) << 16 | (5)), seq_scene_entrance, 2);
    return 0;
}

/* SEQ: the sections of the character's story, by name, with the story's
 * own section in TEXT_CURRENT. a choice puts the story before the section's
 * first step, and makes the section's stage, act and entrance the next. it
 * then ends the act as a clear. without player_record, the page shows only
 * its box */
int seq_section_page(void)
{
    struct story_section *table;
    int length;
    int move;
    int i;
    int section;

    if (PAD_BUTTONS(pad_press_live[0], pad_cancel_buttons)) {
        return -1;
    }
    if (player_record != NULL) {
        move = 0;
        table = story_get_table(GetPlayerNumber());
        length = FUN_8c090e56(GetPlayerNumber());
        if (PAD_BUTTONS(pad_press_live[0], pad_choose_buttons)) {
            table += seq_section_cursor;
            player_record->seq = -1;
            player_record->section = seq_section_cursor;
            stage_set_entrance(table->entrance);
            stage_fade_to(table->stage, table->act);
            stage_end(STAGE_END_CLEAR);
            return -1;
        }
        if ((pad_press_live[0] & PDD_DGT_KU) ||
            (pad_held_live[0] & PDD_DGT_KL)) {
            move--;
        }
        if ((pad_press_live[0] & PDD_DGT_KD) ||
            (pad_held_live[0] & PDD_DGT_KR)) {
            move++;
        }
        if (move < 0) {
            seq_section_cursor += move;
            if (seq_section_cursor < 0) {
                seq_section_cursor = 0;
            }
            if (seq_section_cursor < seq_section_top + LIST_CURSOR_TOP) {
                seq_section_top += move;
            }
        } else if (move > 0) {
            seq_section_cursor += move;
            if (seq_section_cursor > length - 1) {
                seq_section_cursor = length - 1;
            }
            if (seq_section_cursor > seq_section_top + LIST_CURSOR_BOTTOM) {
                seq_section_top += move;
            }
        }
        if (length > LIST_ROWS) {
            if (seq_section_top < 0) {
                seq_section_top = 0;
            } else if (seq_section_top > length - LIST_ROWS) {
                seq_section_top = length - LIST_ROWS;
            }
            length = LIST_ROWS;
        } else {
            seq_section_top = 0;
        }
        njPrintColor(TEXT_CURSOR);
        njPrintC(NJM_LOCATION(18, 8), "SELECT SECTION");
        section = seq_section_top;
        for (i = 0; i < length; i++, section++) {
            if (seq_section_cursor == section) {
                njPrintColor(TEXT_CURSOR);
                njPrintC(NJM_LOCATION(13, i + 10), ">");
            }
            if (player_record->section == section) {
                njPrintColor(TEXT_CURRENT);
            } else {
                njPrintColor(TEXT_LIT);
            }
            njPrintC(NJM_LOCATION(14, i + 10), table[section].name);
        }
        njPrintC(((14) << 16 | (24)), "SEQNO:");
        FUN_8c6409c0(((20) << 16 | (24)), player_record->seq, 3);
    }
    seq_draw_box(&seq_section_box);
    return 0;
}

/* COMPLT: whether the character has cleared each stage. a choice sets the
 * stage's count of clears to 1 if it is 0, and otherwise to 0. with X held,
 * a choice fades out to the stage's act 0 instead. the page takes each
 * row's number as its stage, even on rows 26 and 27, which name
 * STAGE_SHOOTING1's acts */
int seq_complete_page(void)
{
    int character;
    int i;
    int row;
    int stage;
    int act;
    Sint8 *clears;

    character = GetPlayerNumber();
    if (PAD_BUTTONS(pad_press_live[0], pad_cancel_buttons)) {
        return -1;
    } else if (((Sint32)(pad_press_live[0]) & (Sint32)(pad_choose_buttons))) {
        if (per[0]->on & (1 << 10)) {
            dsPlay_oneshot(2, 0, 0, 0);
            SeqChangeStage(seq_complete_cursor, 0);
            return -1;
        } else {
            stage_clears[character][seq_complete_cursor] =
                !stage_clears[character][seq_complete_cursor];
        }
    }
    njPrintColor(TEXT_CURSOR);
    njPrintC(NJM_LOCATION(14, 10), "SELECT STAGE");
    if ((pad_press_live[0] & PDD_DGT_KU) || (pad_held_live[0] & PDD_DGT_KL)) {
        seq_complete_cursor--;
    } else if ((pad_press_live[0] & PDD_DGT_KD) ||
               (pad_held_live[0] & PDD_DGT_KR)) {
        seq_complete_cursor++;
    }
    if (seq_complete_cursor < 0) {
        seq_complete_cursor = SEQ_STAGES - 1;
    } else if (seq_complete_cursor >= SEQ_STAGES) {
        seq_complete_cursor = 0;
    }
    /* @hack spelling: row and i set before clears. this gives i R10
     * (0x8c0ab412), keeps stage at @(4,R15) and act at @(8,R15) in the
     * loop's second unrolled copy and its remainder (0x8c0ab4b0 to
     * 0x8c0ab528, 0x8c0ab68c to 0x8c0ab6a6), and stores clears before the
     * MOV of STAGE_SHOOTING1 to R12 (0x8c0ab41c, 0x8c0ab41e); with both set
     * after clears, 52 of 415 words differ */
    row = seq_complete_cursor + SEQ_STAGES - STAGE_CURSOR_ROW;
    i = 0;
    clears = stage_clears[character];
    for (; i < STAGE_ROWS_SHOWN; i++, row++) {
        row %= SEQ_STAGES;
        if (row == seq_complete_cursor) {
            njPrintColor(TEXT_LIT);
        } else {
            njPrintColor(TEXT_DIM);
        }
        if (row == SEQ_STAGES - 2) {
            stage = STAGE_SHOOTING1;
            act = 0;
        } else if (row == SEQ_STAGES - 1) {
            stage = STAGE_SHOOTING1;
            act = 1;
        } else {
            stage = row;
            act = 0;
        }
        debug_print_stage_name(NJM_LOCATION(14, i + 12), STAGE_ACT(stage, act));
        njPrintC(NJM_LOCATION(28, i + 12), seq_no_yes[clears[row] != 0]);
    }
    seq_draw_box(&seq_stage_box);
    /* @bug uninitialized: seq_menu tests this page's result against -1
     * (0x8c0aa37c), and the page returns none. the image branches to
     * seq_draw_box last (0x8c0ab6f0), and draw_set_material and seq_draw_box
     * return without writing R0 again. the R0 seq_menu tests is 12, from
     * njSetConstantMaterial's MOV #12,R0 (0x8c6298a2). a return of 0 would
     * make the branch a call */
#ifdef GCC
    /* repairs the missing return the tag names: GCC returns 0, and seq_menu
     * stays on the page, as it does on the 12 the image returns */
    return 0;
#endif
    /* NOLINTNEXTLINE(clang-diagnostic-return-type) */
}

/* DEBUG: where player 0 is, and how it's turned */
int seq_debug_page(void)
{
    if (PAD_BUTTONS(pad_press_live[0], pad_cancel_buttons)) {
        return -1;
    }
    njPrintC(NJM_LOCATION(15, 6), "PLPOS X:");
    njPrintC(NJM_LOCATION(21, 7), "Y:");
    njPrintC(NJM_LOCATION(21, 8), "Z:");
    njPrintF(NJM_LOCATION(24, 6), playertwp[0]->pos.x, 4);
    njPrintF(NJM_LOCATION(24, 7), playertwp[0]->pos.y, 4);
    njPrintF(NJM_LOCATION(24, 8), playertwp[0]->pos.z, 4);
    njPrintC(NJM_LOCATION(15, 9), "PLANG X:");
    njPrintC(NJM_LOCATION(21, 10), "Y:");
    njPrintC(NJM_LOCATION(21, 11), "Z:");
    njPrintH(NJM_LOCATION(24, 9), playertwp[0]->ang.x, 4);
    njPrintH(NJM_LOCATION(24, 10), playertwp[0]->ang.y, 4);
    njPrintH(NJM_LOCATION(24, 11), playertwp[0]->ang.z, 4);
    seq_draw_box(&seq_debug_box);
    return 0;
}

void seq_draw_box(struct seq_box *box)
{
    NJS_COLOR colors[4];
    NJS_POINT2 points[4];
    NJS_POINT2COL polygon;

    polygon.p = points;
    polygon.col = colors;
    polygon.tex = NULL;
    polygon.num = 4;
    points[0].x = points[1].x = box->x;
    points[2].x = points[3].x = box->x + box->width;
    points[0].y = points[3].y = box->y;
    points[1].y = points[2].y = box->y + box->height;
    colors[0].color = colors[1].color = colors[2].color = colors[3].color =
        box->color;
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    njDrawPolygon2D(&polygon, 4, -1.0F, NJD_FILL | NJD_TRANSPARENT);
    colors[0].color = colors[1].color = colors[2].color = colors[3].color =
        TEXT_LIT;
    njDrawPolygon2D(&polygon, 4, -0.9F, NJD_DRAW_NORMAL);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
