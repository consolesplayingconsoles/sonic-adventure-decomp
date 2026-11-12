/* @unit 8C04BF00-8C04C5E0 +egflags +r04 +pool32 +asmfunc=FUN_8c04bf00 */
/* a player's model posed by a motion the caller gives, with the player's
 * welds closing its seams. events pose players so, in place of their own
 * actions */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/pose.h"
#include "player/player.h"
#include "player/weld.h"
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
void FUN_8c04bf00(int player, NJS_OBJECT *object, NJS_MOTION *motion,
                  Float frame);
extern NJS_MATRIX weld_matrix_a;
extern NJS_MATRIX weld_matrix_b;
extern NJS_MATRIX weld_inverse_a;
extern NJS_MATRIX weld_inverse_b;

#ifdef NON_MATCHING

void FUN_8c04bf00(int player, NJS_OBJECT *object, NJS_MOTION *motion,
                  Float frame)
{
    struct player *record;
    struct player_anim *anim;
    struct weld *weld;
    NJS_POINT3 *vertex_a;
    NJS_POINT3 *vertex_b;
    NJS_ACTION action;
    NJS_POINT3 *points_a;
    NJS_POINT3 *points_b;
    NJS_VECTOR *normals_a;
    NJS_VECTOR *normals_b;
    NJS_POINT3 point;
    NJS_POINT3 other;
    /* @hack type: i as a Uint16, which SHC zero-extends (EXTU.W) for each
     * index and each loop test (0x8c04f1ae, 0x8c04f2ca); as an int, 125 of
     * 682 words differ */
    Uint16 i;
    int index_a;
    int index_b;

    record = GetPlayerWorkPointer(player);
    anim = &record->anim;
    weld = anim->welds;
    action.object = object;
    action.motion = motion;
#ifdef GCC
    /* GCC can't see that a weld whose kind reads the points and normals has
     * the object_b that sets them, as in player_update_welds */
    points_a = points_b = normals_a = normals_b = NULL;
#endif
    switch (anim->weld_mode) {
    case PLAYER_WELDING:
        CalcMMMatrix(&nj_unit_matrix_, &action, frame, anim->actions->nodes,
                     NULL);
        for (; weld->base != NULL; weld++) {
            if (weld->base == object) {
                GetMMMatrix(weld->node_a, &weld_matrix_a);
                if (weld->object_b != NULL) {
                    points_a = weld->object_a->model->points;
                    normals_a = weld->object_a->model->normals;
                    njSetMatrix(&weld_inverse_a, &weld_matrix_a);
                    njInvertMatrix(&weld_inverse_a);
                    GetMMMatrix(weld->node_b, &weld_matrix_b);
                    points_b = weld->object_b->model->points;
                    normals_b = weld->object_b->model->normals;
                    njSetMatrix(&weld_inverse_b, &weld_matrix_b);
                    njInvertMatrix(&weld_inverse_b);
                } else {
                    /* @hack spelling: point's and other's zeros in two chains,
                     * which put 0.0F in FR13 (FLDI0 FR13 at 0x8c04f026) and
                     * lay the frame out as the image does (MOV #92,R0 at
                     * 0x8c04efbe); as six single stores, 0.0F takes FR15,
                     * the frame's slots move, and 44 of 682 words differ */
                    point.x = point.y = point.z = 0.0F;
                    other.x = other.y = other.z = 0.0F;
                    if (weld->count == 0) {
                        other.x = 1.0F;
                    } else if (weld->count == 1) {
                        other.y = 1.0F;
                    } else {
                        other.z = 1.0F;
                    }
                    njPushMatrix(&weld_matrix_a);
                }
                switch (weld->kind) {
                case WELD_BOTH:
                    for (i = 0; i < weld->count; i++) {
                        index_a = weld->indices[i * 2];
                        index_b = weld->indices[(i * 2) + 1];
                        /* @hack spelling: a's and b's points through vertex_a
                         * and vertex_b, which has SHC form vertex_b before the
                         * first call and keep it in the frame (MOV.L
                         * R2,@(R0,R15) at 0x8c04f1e4, R0 68). passed directly,
                         * the frame is 192 bytes, not 196, and 196 of 682
                         * words differ */
                        vertex_a = &weld->vertices[i * 4];
                        vertex_b = &weld->vertices[(i * 4) + 2];
                        njCalcPoint(&weld_matrix_a, vertex_a, &point);
                        njCalcPoint(&weld_matrix_b, vertex_b, &other);
                        point.x = (point.x + other.x) * 0.5F;
                        point.y = (point.y + other.y) * 0.5F;
                        point.z = (point.z + other.z) * 0.5F;
                        njCalcPoint(&weld_inverse_a, &point,
                                    &points_a[index_a]);
                        njCalcPoint(&weld_inverse_b, &point,
                                    &points_b[index_b]);
                        njCalcVector(&weld_matrix_a,
                                     &weld->vertices[(i * 4) + 1], &point);
                        njCalcVector(&weld_matrix_b,
                                     &weld->vertices[(i * 4) + 3], &other);
                        point.x += other.x;
                        point.y += other.y;
                        point.z += other.z;
                        njUnitVector(&point);
                        njCalcVector(&weld_inverse_a, &point,
                                     &normals_a[index_a]);
                        njCalcVector(&weld_inverse_b, &point,
                                     &normals_b[index_b]);
                    }
                    break;
                case WELD_TO_A:
                    njPushMatrix(&weld_inverse_b);
                    njMultiMatrix(NULL, &weld_matrix_a);
                    for (i = 0; i < weld->count; i++) {
                        index_a = weld->indices[i * 2];
                        index_b = weld->indices[(i * 2) + 1];
                        points_a[index_a] = weld->vertices[i * 4];
                        njCalcPoint(NULL, &weld->vertices[i * 4],
                                    &points_b[index_b]);
                        normals_a[index_a] = weld->vertices[(i * 4) + 1];
                        njCalcVector(NULL, &weld->vertices[(i * 4) + 1],
                                     &normals_b[index_b]);
                    }
                    late_DrawObjectClipEx(1);
                    break;
                case WELD_TO_B:
                    njPushMatrix(&weld_inverse_a);
                    njMultiMatrix(NULL, &weld_matrix_b);
                    for (i = 0; i < weld->count; i++) {
                        index_a = weld->indices[i * 2];
                        index_b = weld->indices[(i * 2) + 1];
                        points_b[index_b] = weld->vertices[(i * 4) + 2];
                        njCalcPoint(NULL, &weld->vertices[(i * 4) + 2],
                                    &points_a[index_a]);
                        normals_b[index_b] = weld->vertices[(i * 4) + 3];
                        njCalcVector(NULL, &weld->vertices[(i * 4) + 3],
                                     &normals_a[index_a]);
                    }
                    late_DrawObjectClipEx(1);
                    break;
                case WELD_MARK:
                    njCalcPoint(NULL, &point, &record->weld_point0);
                    njCalcVector(NULL, &other, &record->weld_axis0);
                    late_DrawObjectClipEx(1);
                    break;
                case WELD_MARK + 1:
                    njCalcPoint(NULL, &point, &record->weld_point1);
                    njCalcVector(NULL, &other, &record->weld_axis1);
                    late_DrawObjectClipEx(1);
                    break;
                case WELD_MARK + 2:
                    njCalcPoint(NULL, &point, &record->weld_point2);
                    njCalcVector(NULL, &other, &record->weld_axis2);
                    late_DrawObjectClipEx(1);
                    break;
                case WELD_MARK + 3:
                    njCalcPoint(NULL, &point, &record->weld_point3);
                    njCalcVector(NULL, &other, &record->weld_axis3);
                    late_DrawObjectClipEx(1);
                    break;
                case WELD_MARK + 4:
                    njCalcPoint(NULL, &point, &record->weld_point4);
                    njCalcVector(NULL, &other, &record->weld_axis4);
                    late_DrawObjectClipEx(1);
                    break;
                case WELD_MARK + 5:
                    njCalcPoint(NULL, &point, &record->weld_point5);
                    njCalcVector(NULL, &other, &record->weld_axis5);
                    late_DrawObjectClipEx(1);
                    break;
                }
            }
        }
        break;
    /* @hack redundant: case labels for PLAYER_WELD_MAKE and PLAYER_WELD_FREE,
     * which the default takes too, keep the image's CMP/EQ #0 and CMP/EQ #2
     * (0x8c04ef60, 0x8c04ef6c); without them, 639 of 682 words differ */
    case PLAYER_WELD_MAKE:
    case PLAYER_WELD_FREE:
    default:
        while (1) {
        }
    }
}
#else
void FUN_8c04bf00(int player, NJS_OBJECT *object, NJS_MOTION *motion,
                  Float frame)
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
}
#endif
