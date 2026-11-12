/* @unit 8C043A20-8C043C00 +egflags +onepool +pool32 */
/* the constant material, lines, and the highlight on what draws near the
 * players */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
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

void SetMaterial(Float alpha, Float red, Float green, Float blue)
{
    NJS_ARGB color;

    color.a = alpha;
    color.r = red;
    color.g = green;
    color.b = blue;
    njSetConstantMaterial(&color);
}

void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2)
{
    NJS_POINT3COL line;
    NJS_POINT3 points[2];
    NJS_COLOR colors[2];

    points[0].x = x1;
    points[0].y = y1;
    points[0].z = z1;
    points[1].x = x2;
    points[1].y = y2;
    points[1].z = z2;
    colors[0].argb.a = 255;
    colors[0].argb.r = 255;
    colors[0].argb.g = 255;
    colors[0].argb.b = 255;
    colors[1].argb.a = 255;
    colors[1].argb.r = 136;
    colors[1].argb.g = 136;
    colors[1].argb.b = 187;
    line.p = points;
    line.col = colors;
    line.tex = NULL;
    line.num = 2;
    njDrawLine3D(&line, 1, NJD_DRAW_NORMAL);
}

void draw_line_colored(Float x1, Float y1, Float z1, const NJS_COLOR *color1,
                       Float x2, Float y2, Float z2, const NJS_COLOR *color2)
{
    NJS_POINT3COL line;
    NJS_POINT3 points[2];
    NJS_COLOR colors[2];

    points[0].x = x1;
    points[0].y = y1;
    points[0].z = z1;
    points[1].x = x2;
    points[1].y = y2;
    points[1].z = z2;
    colors[0] = *color1;
    colors[1] = *color2;
    line.p = points;
    line.col = colors;
    line.tex = NULL;
    line.num = 2;
    njDrawLine3D(&line, 1, NJD_DRAW_NORMAL);
}

void draw_line_v(NJS_POINT3 *from, NJS_POINT3 *to)
{
    NJS_POINT3COL line;
    NJS_POINT3 points[2];
    NJS_COLOR colors[2];

    points[0].x = from->x;
    points[0].y = from->y;
    points[0].z = from->z;
    points[1].x = to->x;
    points[1].y = to->y;
    points[1].z = to->z;
    colors[0].argb.a = 255;
    colors[0].argb.r = 255;
    colors[0].argb.g = 255;
    colors[0].argb.b = 255;
    colors[1].argb.a = 255;
    colors[1].argb.r = 136;
    colors[1].argb.g = 136;
    colors[1].argb.b = 187;
    line.p = points;
    line.col = colors;
    line.tex = NULL;
    line.num = 2;
    njDrawLine3D(&line, 1, NJD_DRAW_NORMAL);
}

void ModelTurnWhite(struct task_work *work, Sint16 characters)
{
    NJS_ARGB color;
    Sint16 bit = 1 << GetPlayerCharacterName(0);

    if (characters & bit) {
        if (player_in_range(&work->pos, 20.0F)) {
            color.a = 0.0F;
            color.r = 0.5F;
            color.g = 0.5F;
            color.b = 0.5F;
        } else {
            color.a = 0.0F;
            color.r = 0.0F;
            color.g = 0.0F;
            color.b = 0.0F;
        }
        njSetConstantMaterial(&color);
    }
}
