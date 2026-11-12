/* @unit 0C905660-0C905880 @data 0C90A5DC-0C90A5F4 +r04 +egflags +pool32 +poolafter=gate_combo_destroy */
/* the gate combo: more points for each sand gate passed soon after the last.
 * its count shows at the screen's top right */
#include <ninja.h>
#include <sg_xpt.h>

#include "hud/hud.h"
#include "player/e102_bonus.h"
#include "sboard/act.h"
#include "sboard/gate_combo.h"
#include "stage/stage.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/task_desc.h"
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
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
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
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);
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

/* the combo's record, in task->motion */
#define COMBO_MAX 50
#define COMBO_STEPS 180
#define COMBO_POINTS 10
#define COMBO_X 528.0F
#define COMBO_Y 32.0F
#define COMBO_SPACING 32.0F
#define COMBO_X_ONE_DIGIT (COMBO_X + COMBO_SPACING)
#define COMBO_TIMES E102TIME_LOCKON0
struct gate_combo_record {
    Sint16 steps; /* left before the combo runs out */
    Sint16 count;
};

/* a gate passed adds one to the combo's count, up to COMBO_MAX, and scores
 * COMBO_POINTS times the count. each gate leaves the combo COMBO_STEPS steps
 * to run. the count goes back to 0 once they run out */

/* the combo's screen position, and the spacing of its glyphs. a count of
 * one digit starts one glyph further right. its digit then lands where a
 * count of two digits puts its last */
/* the times sign drawn before the count */

void gate_combo_init(struct task *task, void *arg);
void gate_combo_step(struct task *task);
void dispScore(struct task *task);
void gate_combo_destroy(struct task *task);
void dispLink(int count);
Float drawLetter(Float x, Float y, Float pri, int glyph);

static const struct task_desc gate_combo_desc = {
    sizeof(struct gate_combo_record),
    0,
    gate_combo_init,
    gate_combo_step,
    dispScore,
    gate_combo_destroy};
extern const NJS_ARGB gate_combo_white;
extern const NJS_ARGB gate_combo_none;
extern const Float gate_combo_pri[2];
extern struct gate_combo_record *gate_combo;
extern NJS_TEXANIM gate_combo_frame;
extern NJS_SPRITE gate_combo_sprite;

struct task *gate_combo_create(void)
{
    /* @hack spelling: the result through task, which keeps the call a JSR
     * (0x0c905726); returned directly, it becomes a tail jump to
     * act_task_create, and 8 of 8 words differ */
    struct task *task = act_task_create(&gate_combo_desc, NULL);

    return task;
}

void gate_combo_add(void)
{
    struct gate_combo_record *record = gate_combo;

    if (record == NULL) {
        score_add(COMBO_POINTS);
        return;
    }
    record->count++;
    if (record->count > COMBO_MAX) {
        record->count = COMBO_MAX;
    }
    score_add(record->count * COMBO_POINTS);
    record->steps = COMBO_STEPS;
}

void gate_combo_init(struct task *task, void *arg)
{
    struct gate_combo_record *record = (struct gate_combo_record *)task->motion;

    record->steps = 0;
    record->count = 0;
    gate_combo = record;
}

/* count the combo's steps down, and set its count back to 0 once they have
 * run out. then draw the combo */
void gate_combo_step(struct task *task)
{
    struct gate_combo_record *record = (struct gate_combo_record *)task->motion;

    if (record->steps > 0) {
        record->steps--;
    } else {
        record->count = 0;
    }
    dispScore(task);
}

/* on a frame's first step, draw a count above 0. nothing draws while
 * hud_hidden is below 0 */
void dispScore(struct task *task)
{
    struct gate_combo_record *record = (struct gate_combo_record *)task->motion;

    if (loop_count == 0 && hud_hidden >= 0 && record->count > 0) {
        njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                               NJD_COLOR_BLENDING_BOTHSRCALPHA);
        njTextureFilterMode_jp(NJD_TEXTUREFILTER_POINT_SAMPLE);
        njSetConstantMaterial((NJS_ARGB *)&gate_combo_white);
#ifdef GCC
        /* the port's 16:9 squeezes the count about the screen's right edge */
        port_wide_anchor = WIDE_RIGHT;
#endif
        dispLink(record->count);
#ifdef GCC
        port_wide_anchor = WIDE_MIDDLE;
#endif
        njSetConstantMaterial((NJS_ARGB *)&gate_combo_none);
        njTextureFilterMode_jp(NJD_TEXTUREFILTER_BILINEAR);
    }
}

/* forget the record only while gate_combo holds it, so that a newer combo's
 * stays */
void gate_combo_destroy(struct task *task)
{
    struct gate_combo_record *record = (struct gate_combo_record *)task->motion;

    if (gate_combo == record) {
        gate_combo = NULL;
    }
}

/* draw the times sign, then the count's one or two digits. the last digit
 * always lands at the same x */
void dispLink(int count)
{
    Float x = COMBO_X;
    Float y = COMBO_Y;
    int last;

    if (count < 10) {
        x = COMBO_X_ONE_DIGIT;
        x += drawLetter(x, y, gate_combo_pri[0], COMBO_TIMES);
        last = 1;
    } else {
        x += drawLetter(x, y, gate_combo_pri[0], COMBO_TIMES);
        x += drawLetter(x, y, gate_combo_pri[1], count / 10);
        last = 0;
    }
    drawLetter(x, y, gate_combo_pri[last], count % 10);
}

/* draw e102time_texlist's texture glyph at x and y, and return the spacing
 * to the next glyph's x */
Float drawLetter(Float x, Float y, Float pri, int glyph)
{
    gate_combo_frame.texid = glyph;
    gate_combo_sprite.p.x = x;
    gate_combo_sprite.p.y = y;
    late_DrawSprite2D(&gate_combo_sprite, 0, pri, NJD_SPRITE_ALPHA);
    return COMBO_SPACING;
}
