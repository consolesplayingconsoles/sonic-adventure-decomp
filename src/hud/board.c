/* @unit 8C0A1060-8C0A1220 +egflags +onepool +pool32 */
/* the board stages' hud: a score under its own label, where the time
 * would be */
#define TEXT_1 ""
#include <ninja.h>
#include <sg_xpt.h>

#include "hud/board.h"
#include "main.h"
#include "stage/stage.h"
#include "system/texlists.h" /* NOLINT(misc-include-cleaner) */
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
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
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

#define TEXT_1_LENGTH 13

/* the most the score shows, in its five digits */
#define SCORE_MAX 99999
/* the step in x from one digit to the next */
#define DIGIT_WIDTH 16.0F

static Float draw_score_digit(Float x, Float y, Float depth, Sint16 digit);
extern NJS_TEXANIM score_digit_texanim;
extern NJS_SPRITE score_digit_sprite;
extern int dat_8c1da8d4;
extern NJS_TEXNAME score_texnames[];
extern NJS_TEXLIST board_score_texlist;
extern const Float score_digit_depths[2];
extern const NJS_ARGB score_color;
extern const NJS_ARGB score_no_color;
extern const NJS_TEXANIM score_label_texanims[1];
extern const NJS_SPRITE score_label_sprite;
extern const NJS_TEXANIM rings_label_texanims[1];
extern const NJS_SPRITE rings_label_sprite;

void MirenScoreDisplayScore(int score)
{
    Float x;
    Float y;
    int value;
    int place;
    int depth;

    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_BOTHSRCALPHA);
    njTextureFilterMode_jp(NJD_TEXTUREFILTER_POINT_SAMPLE);
    njSetConstantMaterial((NJS_ARGB *)&score_color);
    x = 92.0F;
    y = 33.0F;
    value = score;
    if (value > SCORE_MAX) {
        value = SCORE_MAX;
    }
    place = 10000;
    depth = 0;
    do {
        x += draw_score_digit(x, y, score_digit_depths[depth], value / place);
        value %= place;
        place /= 10;
        depth ^= 1;
    } while (place > 0);
    njSetConstantMaterial((NJS_ARGB *)&score_no_color);
    njTextureFilterMode_jp(NJD_TEXTUREFILTER_BILINEAR);
}

void hud_draw_board_labels(void)
{
    late_DrawSprite2D((NJS_SPRITE *)&score_label_sprite, 0, -2.001F,
                      NJD_SPRITE_ALPHA);
    late_DrawSprite2D((NJS_SPRITE *)&rings_label_sprite, 0, -2.0F,
                      NJD_SPRITE_ALPHA);
}

Bool board_active(void)
{
    Bool active = FALSE;
    int stage_act = GetStageNumber();
    Uint8 stage = STAGE_OF(stage_act);

    if (stage == STAGE_SUNABOARD ||
        (stage == STAGE_ICECAP && (Uint8)stage_act == 2 &&
         game_mode == GAME_MODE_TRIAL)) {
        active = TRUE;
    }
    return active;
}

Bool cart_active(void)
{
    Bool active = FALSE;
    int stage_act = GetStageNumber();
    Uint8 stage = STAGE_OF(stage_act);

    if (stage == STAGE_CART) {
        active = TRUE;
    }
    return active;
}

/* draw digit at x, y and depth. returns the step in x to the next digit */
static Float draw_score_digit(Float x, Float y, Float depth, Sint16 digit)
{
    score_digit_texanim.texid = digit;
    score_digit_sprite.p.x = x;
    score_digit_sprite.p.y = y;
    late_DrawSprite2D(&score_digit_sprite, 0, depth, NJD_SPRITE_ALPHA);
    return DIGIT_WIDTH;
}
