/* @unit 8C0F1B80-8C0F1FE0 +egflags +r04 +pool32 +asmfunc=DisplayBossName */
/* the boss's name, typed a letter at a time as a fight starts */
#include <ninja.h>
#include <sg_xpt.h>
#include <string.h>

#include "draw/draw.h"
#include "hud/boss_name.h"
#include "main.h"
#include "sound/sound.h"
#include "stage/stage.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
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
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);

#define TEXT_1_LENGTH 12

/* b32ascii's letters are 32-pixel squares, numbered across rows of eight */
#define LETTER_SIZE 32
#define ROW_SHIFT 3
#define LETTERS_PER_ROW (1 << ROW_SHIFT)
/* the square of anything b32ascii has no letter for */
#define LETTER_NONE 63

/* the steps from one letter to the next, the steps the whole name holds,
 * and the steps its fade takes */
#define LETTER_STEPS 20
#define HOLD_STEPS 120
#define FADE_STEPS 30

/* the click of a letter, in each boss stage's own sounds */
#define SE_LETTER_CHAOS0 331
#define SE_LETTER_CHAOS4 355
#define SE_LETTER_CHAOS6 378
#define SE_LETTER_CHAOS7 409
#define SE_LETTER_CHAOS7_2 428 /* Chaos 7's second act */
#define SE_LETTER_MOUNTAIN 151
#define SE_LETTER_EGGMOBILE1 454
#define SE_LETTER_EGGMOBILE2 468
#define SE_LETTER_EGGMOBILE3 487

#define VARS(work) ((struct boss_name_vars *)&(work)->vars)
enum boss_name_mode {
    BOSS_NAME_INIT,
    BOSS_NAME_TYPE, /* a letter every LETTER_STEPS */
    BOSS_NAME_WHOLE,
    BOSS_NAME_HOLD,
    BOSS_NAME_FADE
};

struct boss_name_vars {
    Uint8 unk_00[4];
    Sint32 steps; /* to the next letter, or the end of the hold */
};

/* the name task's extra. the fade's end frees text and letters. the task
 * has no destructor, so they leak if it is destroyed sooner */
struct boss_name {
    char *text;
    Sint8 length;
    Sint8 manager_data; /* letters typed so far */
    NJS_TEXANIM *letters; /* each one's square in b32ascii */
};
extern NJS_TEXLIST b32ascii_texlist;
extern NJS_SPRITE boss_name_sprite;
extern NJS_ARGB boss_name_color;
extern Uint16 boss_name_stage;
extern Uint16 boss_name_act;
#ifdef NON_MATCHING

/* type the name, hold it whole, then fade it out and kill the task. each
 * step but the last draws the letters typed so far */
static void DisplayBossName(struct task *task)
{
    struct task_work *work = task->work;
    struct boss_name *name = task->extra;
    NJS_TEXANIM *letter;
    int attr;
    int i;

    switch (work->mode) {
    case BOSS_NAME_INIT:
        boss_name_stage = GetStageNumber();
        boss_name_act = (Uint8)boss_name_stage;
        boss_name_stage >>= 8;
        work->mode = BOSS_NAME_TYPE;
        /* fall through */
    case BOSS_NAME_TYPE:
        VARS(work)->steps--;
        if (VARS(work)->steps == 0) {
            name->manager_data++;
            /* @hack spelling: the letter just shown, through a pointer sum,
             * which the image adds before its MOV.B (0x8c0fcf34,
             * 0x8c0fcf38); as name->text[name->shown - 1], SHC indexes with
             * @(R0,R3), an instruction shorter, and 38 of 270 words
             * differ */
            if (*(name->text + name->manager_data - 1) != ' ') {
                switch (boss_name_stage) {
                case STAGE_CHAOS0:
                case STAGE_CHAOS2:
                    dsPlay_oneshot(SE_LETTER_CHAOS0, 0, 0, 0);
                    break;
                case STAGE_CHAOS4:
                    dsPlay_oneshot(SE_LETTER_CHAOS4, 0, 0, 0);
                    break;
                case STAGE_CHAOS6:
                    dsPlay_oneshot(SE_LETTER_CHAOS6, 0, 0, 0);
                    break;
                case STAGE_CHAOS7:
                    if (boss_name_act == 0) {
                        dsPlay_oneshot(SE_LETTER_CHAOS7, 0, 0, 0);
                    } else {
                        dsPlay_oneshot(SE_LETTER_CHAOS7_2, 0, 0, 0);
                    }
                    break;
                case STAGE_MOUNTAIN:
                    dsPlay_oneshot(SE_LETTER_MOUNTAIN, 0, 0, 0);
                    break;
                case STAGE_EGGMOBILE1:
                    dsPlay_oneshot(SE_LETTER_EGGMOBILE1, 0, 0, 0);
                    break;
                case STAGE_EGGMOBILE2:
                    dsPlay_oneshot(SE_LETTER_EGGMOBILE2, 0, 0, 0);
                    break;
                case STAGE_EGGMOBILE3:
                    dsPlay_oneshot(SE_LETTER_EGGMOBILE3, 0, 0, 0);
                    break;
                }
            }
            if (name->manager_data < name->length) {
                VARS(work)->steps = LETTER_STEPS;
            } else {
                boss_name_color.a = 1.0F;
                work->mode = BOSS_NAME_WHOLE;
            }
        }
        break;
    case BOSS_NAME_WHOLE:
        VARS(work)->steps = HOLD_STEPS;
        work->mode = BOSS_NAME_HOLD;
        break;
    case BOSS_NAME_HOLD:
        VARS(work)->steps--;
        if (VARS(work)->steps == 0) {
            work->mode = BOSS_NAME_FADE;
        }
        break;
    case BOSS_NAME_FADE:
        /* @hack spelling: the fade through boss_name_color's address, which it
         * loads into R1 at 0x8c0fd09c; as boss_name_color.a, SHC keeps the
         * address in R10 from the start, the function runs 28 bytes long and
         * 258 of 270 words differ */
        (&boss_name_color)->a -= 1.0F / FADE_STEPS;
        if (boss_name_color.a <= 0.0F) {
            Free(name->text);
            Free(name->letters);
            FreeTask(task);
            return;
        }
        break;
    }
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
    njSetTexture_jp(&b32ascii_texlist);
    njSetConstantMaterial(&boss_name_color);
    boss_name_sprite.p.x = work->pos.x;
    boss_name_sprite.p.y = work->pos.y;
    attr = NJD_SPRITE_ALPHA;
    if (work->mode >= BOSS_NAME_FADE) {
        attr = NJD_SPRITE_ALPHA | NJD_SPRITE_COLOR;
    }
    letter = name->letters;
    for (i = 0; i < name->manager_data; i++, letter++) {
        boss_name_sprite.tanim = letter;
        if (name->text[i] != ' ') {
            late_DrawSprite2D(&boss_name_sprite, 0, 0.0F, attr);
        }
        boss_name_sprite.p.x += letter->sx;
    }
}
#else
static void DisplayBossName(struct task *task)
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
}
#endif

void SetDisplayBossName(const char *text, int x, int y, int delay)
{
    struct task *task;
    struct boss_name *name;
    NJS_TEXANIM *letter;
    int i;
    Sint8 square;
    int left;
    int top;

    task = CreateElementalTask(TASK_WORK, 1, DisplayBossName);
    task->extra = CAlloc(1, sizeof(struct boss_name));
    VARS(task->work)->steps = delay + 1;
    name = task->extra;
    name->length = strlen(text);
    name->text = MAlloc(name->length + 1);
    strcpy(name->text, text);
    name->letters = CAlloc(name->length, sizeof(NJS_TEXANIM));
    letter = name->letters;
    for (i = 0; i < name->length; i++, letter++, text++) {
        letter->sx = LETTER_SIZE;
        letter->sy = LETTER_SIZE;
        letter->cx = 0;
        letter->cy = 0;
        if (*text >= '0' && *text <= '9') {
            square = *text - '0';
        } else if (*text >= 'A' && *text <= 'Z') {
            square = *text - 'A' + 10;
        } else if (*text >= 'a' && *text <= '|') {
            square = *text - 'a' + 36;
        } else {
            square = LETTER_NONE;
        }
        left = (square & (LETTERS_PER_ROW - 1)) * LETTER_SIZE;
        letter->u1 = left;
        top = (square >> ROW_SHIFT) * LETTER_SIZE;
        letter->v1 = top;
        letter->u2 = left + LETTER_SIZE - 1;
        letter->v2 = top + LETTER_SIZE - 1;
    }
    if (x >= 0) {
        task->work->pos.x = x;
    } else {
        /* a negative x centers the name. its width is a multiple of 32, so
         * the integer division loses nothing */
        /* NOLINTNEXTLINE(bugprone-integer-division) */
        task->work->pos.x = SCREEN_MIDDLE_X - (name->length * LETTER_SIZE / 2);
    }
    task->work->pos.y = y;
}
