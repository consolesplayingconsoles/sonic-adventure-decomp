/* @unit 8C097F20-8C098380 +jpflags +pool32 +poolafter=inset_clip,FUN_8c0981c6 +synth16 +hoist=10001,20401 */
/* the inset: a box on the screen that draws the stage again, looking down
 * on player 1 */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/inset.h"
#include "main.h"
#include "player/player.h"
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
void FUN_8c0981c6(enum inset_clipping clip, Float width, Float height);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
void CharacterShadow(struct task_work *work, struct shadow *shadow);
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
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
extern Uint32 inset_flags;
extern NJS_SCREEN inset_full_screen;
extern NJS_SCREEN inset_screen;
extern struct task *inset_task;
extern NJS_VIEW inset_view;

/* the size of the tiles njUserClipping clips by, in pixels */
#define TILE 32

/* how far above player 1 the inset's view stands */
#define EYE_HEIGHT 100.0F

/* inset_flags' bits. inset_show, inset_hide and inset_toggle change
 * INSET_ASKED, and inset_update copies it to INSET_UP, which inset_clip and
 * inset_draw read */
#define INSET_ASKED 0x1
#define INSET_UP 0x2

/* the color inset_clip fills the inset's tiles with, as ARGB */
#define WHITE 0xffffffff

static void look_down(struct task_work *work, struct task_motion *motion);

void inset_clip(enum inset_clipping clip)
{
    NJS_POINT2 tiles[2];
    NJS_POINT2COL quad;
    NJS_POINT2 points[4];
    NJS_COLOR colors[4];
    NJS_SCREEN *full = &inset_full_screen;
    NJS_SCREEN *inset = &inset_screen;
    Float left;
    Float right;
    Float top;
    Float bottom;
    Float full_left;
    Float full_right;
    Float full_top;
    Float full_bottom;
    int i;

    /* full and inset point at this file's screens, so the test never holds.
     * the image tests both all the same (0x8c09da12, 0x8c09da16) */
    if (full == NULL && inset == NULL) {
        return;
    }
    if (!(inset_flags & INSET_UP)) {
        clip = INSET_CLIP_NONE;
    }
    /* the inset's edges, held within the full screen's */
    left = inset->cx - (inset->w * 0.5F);
    top = inset->cy - (inset->h * 0.5F);
    right = inset->cx + (inset->w * 0.5F);
    bottom = inset->cy + (inset->h * 0.5F);
    full_left = full->cx - (full->w * 0.5F);
    full_top = full->cy - (full->h * 0.5F);
    full_right = full->cx + (full->w * 0.5F);
    full_bottom = full->cy + (full->h * 0.5F);
    if (left < full_left) {
        left = full_left;
    }
    if (right > full_right) {
        right = full_right;
    }
    if (top < full_top) {
        top = full_top;
    }
    if (bottom > full_bottom) {
        bottom = full_bottom;
    }
    /* NOLINTBEGIN(bugprone-integer-division) */
    tiles[0].x = (int)left / TILE;
    tiles[0].y = (int)top / TILE;
    tiles[1].x = (int)right / TILE;
    tiles[1].y = (int)bottom / TILE;
    /* NOLINTEND(bugprone-integer-division) */
    switch (clip) {
    case INSET_CLIP_NONE:
        njUserClipping_jp(NJD_CLIP_DISABLE, NULL);
        _nj_screen_.cx = full->cx;
        _nj_screen_.cy = full->cy;
        _nj_screen_.w = full->w;
        _nj_screen_.h = full->h;
        break;
    case INSET_CLIP_AROUND:
        njUserClipping_jp(NJD_CLIP_OUTSIDE, tiles);
        _nj_screen_.cx = full->cx;
        _nj_screen_.cy = full->cy;
        _nj_screen_.w = full->w;
        _nj_screen_.h = full->h;
        break;
    case INSET_CLIP_INSIDE:
        njUserClipping_jp(NJD_CLIP_INSIDE, tiles);
        _nj_screen_.cx = inset->cx;
        _nj_screen_.cy = inset->cy;
        _nj_screen_.w = inset->w;
        _nj_screen_.h = inset->h;
        quad.p = points;
        quad.col = colors;
        quad.num = 4;
        points[0].x = points[1].x = tiles[0].x * TILE;
        points[2].x = points[3].x = ((tiles[1].x + 1.0F) * TILE) - 1.0F;
        points[0].y = points[3].y = tiles[0].y * TILE;
        points[1].y = points[2].y = ((tiles[1].y + 1.0F) * TILE) - 1.0F;
        for (i = 0; i < 4; i++) {
            colors[i].color = WHITE;
        }
        njDrawPolygon2D(&quad, 4, 0.1F, NJD_DRAW_NORMAL);
        break;
    }
}

void inset_show(void)
{
    inset_flags |= INSET_ASKED;
}

void inset_hide(void)
{
    inset_flags &= ~INSET_ASKED;
}

void inset_toggle(void)
{
    inset_flags ^= INSET_ASKED;
}

Bool inset_update(void)
{
    if (inset_flags & INSET_ASKED) {
        inset_flags |= INSET_UP;
        return TRUE;
    }
    inset_flags &= ~INSET_UP;
    return FALSE;
}

void inset_set_size(enum inset_clipping clip, Float width, Float height)
{
    switch (clip) {
    case INSET_CLIP_NONE:
    case INSET_CLIP_AROUND:
        inset_full_screen.w = width;
        inset_full_screen.h = height;
        break;
    case INSET_CLIP_INSIDE:
        inset_screen.w = width;
        inset_screen.h = height;
        break;
    }
}

void FUN_8c0981c6(enum inset_clipping clip, Float width, Float height)
{
    switch (clip) {
    case INSET_CLIP_NONE:
    case INSET_CLIP_AROUND:
        inset_full_screen.w = width;
        inset_full_screen.h = height;
        break;
    case INSET_CLIP_INSIDE:
        inset_screen.w = width;
        inset_screen.h = height;
        break;
    }
}

void inset_create_task(void (*step)(struct task *task))
{
    inset_task = CreateElementalTask(TASK_WORK, 0, step);
}

void inset_step_task(void)
{
    struct task *task = inset_task;

    if (task != NULL && task->step != NULL) {
        task->step(task);
    }
}

void inset_draw(void)
{
    Float dist;
    int level;

    if (!(inset_flags & INSET_UP)) {
        return;
    }
    dist = _nj_screen_.dist;
    njSetPerspective(NJM_DEG_ANG(30));
    njPushMatrix(NULL);
    look_down(playertwp[1], playermwp[1]);
    for (level = 1; level <= TASK_LEVELS - 1; level++) {
        task_draw_level(level);
    }
    late_DrawObjectClipEx(1);
    _nj_screen_.dist = dist;
}

/* set ninja's view to inset_view, looking straight down on work from
 * EYE_HEIGHT above it. motion goes unread */
static void look_down(struct task_work *work, struct task_motion *motion)
{
    Float x;
    Float y;
    Float z;
    Angle ang_x;
    Angle ang_y;
    Angle ang_z;
    /* @hack redundant: 24 bytes of the frame that the function never reads.
     * their type is unknown. the image's ADD #-40,R15 at 0x8c09ddd8 reserves
     * them; without them, 2 of 47 words differ */
    Uint8 unused[24];

    x = work->pos.x;
    y = work->pos.y + EYE_HEIGHT;
    z = work->pos.z;
    ang_x = NJM_DEG_ANG(-90);
    ang_y = 0;
    ang_z = 0;
    njInitView(&inset_view);
    njRotateViewZRelative(&inset_view, ang_z);
    njRotateViewXRelative(&inset_view, ang_x);
    njRotateViewYRelative(&inset_view, ang_y);
    njTranslateViewRelative(&inset_view, x, y, z);
    njSetView(&inset_view);
}
