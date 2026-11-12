/* @unit 8C08F6C0-8C08FCC0 @data 8C1595D0-8c159668 @ddata 8C1BFDCC-8C1BFF58 +egflags +r04 +pool32 */
/* select: the stage select, which picks a character, a stage and an act
 * outside the story */
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "debug/debug.h"
#include "draw/fade.h"
#include "player/player.h"
#include "progress/select.h"
#include "stage/stage.h"
#include "system/pad.h"
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
void FUN_8c042f0e(void);
Sint16 GameOver(int choice);
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
extern PDS_PERIPHERAL perG[8];
extern struct pad_stick input_dataG[8];
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

#define TEXT_1_LENGTH 5
#define TEXT_2_LENGTH 5
#define TEXT_3_LENGTH 5
#define TEXT_4_LENGTH 5
#define TEXT_5_LENGTH 5
#define TEXT_6_LENGTH 5

#define SELECT_ROWS 79 /* the entries of select_rows */
#define COLUMNS 3 /* the menu's columns, the last of them short */
#define COLUMN_ROWS 28 /* the entries in a full column */
#define COLUMN_WIDTH 12 /* the text cells from one column to the next */
#define SELECT_CHARACTERS 6 /* the characters the menu offers */

#define COLOR_ARROWS 0xffd0b072
#define COLOR_TEXT 0xffc0c0c0
#define COLOR_CURSOR 0xffe04054

#define VARS(work) ((struct select_vars *)&(work)->vars)
enum select_mode {
    SELECT_INIT = 0,
    SELECT_WAIT = 1, /* while the fade from black holds the black */
    SELECT_FADE_IN = 2,
    SELECT_PICK = 3,
    SELECT_FADE_OUT = 6,
    SELECT_DONE = 7
};

/* a stage and act the menu lists */
struct select_row {
    Uint8 stage;
    Uint8 act;
};

/* select_step's vars. work->submode holds the chosen character's index in
 * select_characters */
struct select_vars {
    Uint8 unk_00[4];
    Sint8 row; /* the chosen entry of select_rows */
};

void select_draw_character(struct task *task);
void FUN_8c08f786(struct task *task);

static struct select_row select_rows[SELECT_ROWS] = {
    {STAGE_PRACTICE, 0},
    {STAGE_BEACH, 0},
    {STAGE_BEACH, 1},
    {STAGE_BEACH, 2},
    {STAGE_WINDY, 0},
    {STAGE_WINDY, 1},
    {STAGE_WINDY, 2},
    {STAGE_TWINKLE, 0},
    {STAGE_TWINKLE, 1},
    {STAGE_TWINKLE, 2},
    {STAGE_HIGHWAY, 0},
    {STAGE_HIGHWAY, 1},
    {STAGE_HIGHWAY, 2},
    {STAGE_MOUNTAIN, 0},
    {STAGE_MOUNTAIN, 1},
    {STAGE_MOUNTAIN, 2},
    {STAGE_SKY_DECK, 0},
    {STAGE_SKY_DECK, 1},
    {STAGE_SKY_DECK, 2},
    {STAGE_RUIN, 0},
    {STAGE_RUIN, 1},
    {STAGE_RUIN, 2},
    {STAGE_ICECAP, 0},
    {STAGE_ICECAP, 1},
    {STAGE_ICECAP, 2},
    {STAGE_ICECAP, 3},
    {STAGE_CASINO, 0},
    {STAGE_CASINO, 1},
    {STAGE_CASINO, 2},
    {STAGE_CASINO, 3},
    {STAGE_FINAL, 0},
    {STAGE_FINAL, 1},
    {STAGE_FINAL, 2},
    {STAGE_SHELTER, 0},
    {STAGE_SHELTER, 1},
    {STAGE_SHELTER, 2},
    {STAGE_SHELTER, 3},
    {STAGE_CHAOS0, 0},
    {STAGE_CHAOS2, 0},
    {STAGE_CHAOS4, 0},
    {STAGE_CHAOS6, 0},
    {STAGE_CHAOS6, 1},
    {STAGE_CHAOS7, 0},
    {STAGE_EGGMOBILE1, 0},
    {STAGE_EGGMOBILE2, 0},
    {STAGE_EGGMOBILE3, 0},
    {STAGE_EGGMANROBO, 0},
    {STAGE_E101, 0},
    {STAGE_E101_R, 0},
    {STAGE_STATION_SQUARE, 0},
    {STAGE_STATION_SQUARE, 1},
    {STAGE_STATION_SQUARE, 2},
    {STAGE_STATION_SQUARE, 3},
    {STAGE_STATION_SQUARE, 4},
    {STAGE_STATION_SQUARE, 5},
    {STAGE_EGG_CARRIER, 0},
    {STAGE_EGG_CARRIER, 1},
    {STAGE_EGG_CARRIER, 2},
    {STAGE_EGG_CARRIER, 3},
    {STAGE_EGG_CARRIER, 4},
    {STAGE_EGG_CARRIER, 5},
    {STAGE_EGG_CARRIER_INSIDE, 0},
    {STAGE_EGG_CARRIER_INSIDE, 1},
    {STAGE_EGG_CARRIER_INSIDE, 2},
    {STAGE_EGG_CARRIER_INSIDE, 3},
    {STAGE_EGG_CARRIER_INSIDE, 4},
    {STAGE_EGG_CARRIER_INSIDE, 5},
    {STAGE_MYSTIC_RUINS, 0},
    {STAGE_MYSTIC_RUINS, 1},
    {STAGE_MYSTIC_RUINS, 2},
    {STAGE_MYSTIC_RUINS, 3},
    {STAGE_CART, 0},
    {STAGE_SHOOTING1, 0},
    {STAGE_SHOOTING2, 0},
    {STAGE_SUNABOARD, 0},
    {STAGE_ALIFE_SS, 0},
    {STAGE_ALIFE_EG, 0},
    {STAGE_ALIFE_MR, 0},
    {STAGE_ALIFE_RACE, 0},
};

/* the characters in the menu's order, with their names and pictures */
static Sint16 select_characters[SELECT_CHARACTERS] = {
    CHARACTER_SONIC, CHARACTER_TAILS, CHARACTER_KNUCKLES,
    CHARACTER_BIG,   CHARACTER_AMY,   CHARACTER_E102,
};
static char *select_character_names[SELECT_CHARACTERS] = {
    " SONIC  ", " MILES  ", "KNUCKLES", "  BIG   ", "  AMY   ", " E_102  ",
};
static NJS_TEXNAME select_character_texnames[SELECT_CHARACTERS] = {
    {"sel_s", 0, 0}, {"sel_t", 0, 0}, {"sel_k", 0, 0},
    {"sel_b", 0, 0}, {"sel_a", 0, 0}, {"sel_e", 0, 0},
};
static NJS_TEXLIST select_character_texlist = {select_character_texnames, 6};
static NJS_TEXANIM select_character_texanims[6] = {
    {0x100, 0x100, 0x80, 0x80, 0, 0, 0xff, 0xff, 0, 0},
    {0x100, 0x100, 0x80, 0x80, 0, 0, 0xff, 0xff, 1, 0},
    {0x100, 0x100, 0x80, 0x80, 0, 0, 0xff, 0xff, 2, 0},
    {0x100, 0x100, 0x80, 0x80, 0, 0, 0xff, 0xff, 3, 0},
    {0x100, 0x100, 0x80, 0x80, 0, 0, 0xff, 0xff, 4, 0},
    {0x100, 0x100, 0x80, 0x80, 0, 0, 0xff, 0xff, 5, 0}};
extern Sint16 select_result;
extern Sint16 select_character_count;
extern Sint8 select_stage;
extern Sint8 select_act;

Sint16 stage_select_step(void)
{
    pad_scan();
    task_step_all();
    if (pad_quit_pressed(0)) {
        task_destroy_all();
        return SELECT_STEP_RESET;
    }
    return select_result;
}

void stage_select_start(void)
{
    heap_init();
    task_init();
    CreateElementalTask(0x2, 1, FUN_8c08f786);
    PadReadOff();
    select_result = 0;
    select_character_count = SELECT_CHARACTERS;
}

/* print the chosen character's name between the arrows. the sprite is set
 * up, but nothing draws it */
void select_draw_character(struct task *task)
{
    NJS_SPRITE sprite;
    int character;

    sprite.tlist = &select_character_texlist;
    sprite.tanim = select_character_texanims;
    njSetTexture_jp(sprite.tlist);
    character = task->work->submode; /* NOLINT(bugprone-signed-char-misuse) */
    sprite.sx = 0.5F;
    sprite.sy = 0.5F;
    sprite.p.x = 540.0F;
    sprite.p.y = 360.0F;
    njPrintColor(COLOR_ARROWS);
    njPrintC(NJM_LOCATION(25, 27), "<-X        B->");
    njPrintColor(COLOR_TEXT);
    njPrintC(NJM_LOCATION(28, 27), select_character_names[character]);
}

/* the selector's task: fade in, pick, fade out. a pick sets the character,
 * stage and act as the fade out starts, and select_result as it ends. each
 * call that doesn't return early lists the rows, with the cursor on the
 * chosen one */
void FUN_8c08f786(struct task *task)
{
    /* @hack redundant: the six halfwords at 0x8c16cd50, which the image
     * copies into the frame (0x8c094ad8 to 0x8c094aee) and never reads;
     * without them, 467 of 481 words differ */
    Sint16 unused[SELECT_CHARACTERS] = {26, 22, 30, 10, 22, 0};
    struct task_work *work = task->work;
    Sint16 fade;
    Uint16 current;
    Sint16 count;
    int i;
    int row;
    int column;

    switch (work->mode) {
    case SELECT_INIT:
        FUN_8c042f0e();
        work->mode = SELECT_WAIT;
        /* fall through */
    case SELECT_WAIT:
        /* @hack spelling: the return in an else keeps fade_in_step's address
         * in R1 for SELECT_FADE_IN's call (0x8c094c20); with an early return,
         * R2 takes it and 2 of 481 words differ */
        if (fade_in_step() == 0) {
            NeonuLoadTexture(&select_character_texlist);
            work->mode = SELECT_FADE_IN;
            current = GetStageNumber();
            select_stage = current >> 8;
            select_act = current;
            njSetBackColor_jp(0xff000040, 0xff100060, 0xff002078);
        } else {
            return;
        }
        break;
    case SELECT_FADE_IN:
        fade = fade_in_step();
        LoopTaskC(task);
        select_draw_character(task);
        if (fade != 0) {
            work->mode = SELECT_PICK;
            ufExitSystem();
        }
        break;
    case SELECT_PICK:
        if (PAD_BUTTONS(pad_press_live[0], pad_choose_buttons)) {
            work->mode = SELECT_FADE_OUT;
            set_character(select_characters[work->submode]);
            stage_set_stage_act(select_stage, select_act);
            fade_out_start();
        } else if (pad_press_live[0] & PDD_DGT_TX) {
            work->submode--;
        } else if (pad_press_live[0] & PDD_DGT_TB) {
            work->submode++;
        }
        count = select_character_count;
        if (work->submode >= count) {
            work->submode = 0;
        } else if (work->submode < 0) {
            work->submode = count - 1;
        }
        select_draw_character(task);
        /* up and down move a row, and left and right a column, wrapping
         * past either end. a column move onto the short last column's empty
         * rows skips that column */
        if (pad_press_live[0] & PDD_DGT_KD) {
            VARS(work)->row++;
        } else if (pad_press_live[0] & PDD_DGT_KU) {
            VARS(work)->row--;
        } else if (pad_press_live[0] & PDD_DGT_KL) {
            VARS(work)->row -= COLUMN_ROWS;
            if (VARS(work)->row < 0) {
                VARS(work)->row += COLUMNS * COLUMN_ROWS;
                if (VARS(work)->row >= SELECT_ROWS) {
                    VARS(work)->row -= COLUMN_ROWS;
                }
            }
        } else if (pad_press_live[0] & PDD_DGT_KR) {
            VARS(work)->row += COLUMN_ROWS;
            if (VARS(work)->row >= SELECT_ROWS) {
                VARS(work)->row -= COLUMNS * COLUMN_ROWS;
                if (VARS(work)->row < 0) {
                    VARS(work)->row += COLUMN_ROWS;
                }
            }
        }
        if (VARS(work)->row >= SELECT_ROWS) {
            VARS(work)->row = 0;
        } else if (VARS(work)->row < 0) {
            VARS(work)->row = SELECT_ROWS - 1;
        }
        select_stage = select_rows[VARS(work)->row].stage;
        select_act = select_rows[VARS(work)->row].act;
        break;
    case SELECT_FADE_OUT:
        fade = fade_out_step();
        PadReadOff();
        if (fade != 0) {
            work->mode = SELECT_DONE;
            select_result = SELECT_STEP_PICKED;
            njReleaseTexture_jp(&select_character_texlist);
            task_destroy_all();
            return;
        }
        select_draw_character(task);
        break;
    case SELECT_DONE:
        select_result = SELECT_STEP_PICKED;
        njReleaseTexture_jp(&select_character_texlist);
        task_destroy_all();
        return;
    }
    /* @hack spelling: the positions as locals keep pad_press_live's address in
     * R9 and the zero in R10 (0x8c094c48, 0x8c094af8), and keep the cursor's
     * position at @R15 across njPrintColor (0x8c094e32, 0x8c094e3a); inline,
     * 215 of 481 words differ */
    row = 1;
    column = 1;
    for (i = 0; i < SELECT_ROWS; i++) {
        struct select_row *entry;

        if (i == VARS(work)->row) {
            int loc = NJM_LOCATION(column, row);

            njPrintColor(COLOR_CURSOR);
            njPrintC(loc, "@");
            njPrintColor(COLOR_TEXT);
        }
        {
            int loc = NJM_LOCATION(column + 1, row);
            Sint16 stage_act;

            entry = &select_rows[i];
            /* @hack spelling: the stage and act in two statements, which load
             * the row's address into R6 (0x8c094e42 to 0x8c094e4a); as one
             * statement, R5 takes it and 204 of 481 words differ */
            stage_act = entry->stage << 8;
            stage_act |= entry->act;
            debug_print_stage_name(loc, stage_act);
        }
        row++;
        if (row > COLUMN_ROWS) {
            row = 1;
            column += COLUMN_WIDTH;
        }
    }
}
