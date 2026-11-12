/* @unit 8C0573A0-8C057A20 +egflags +pool32 +poolafter=angle_turn_toward,hud_draw_time +poolkeep=FUN_8c0574c6 */
/* drawing helpers: a model tree with its own draws for some nodes, the
 * hud's big digits and a line, and measures of points, spheres and angles */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "draw/helpers.h"
#include "draw/model.h"
#include "hud/hud.h"
#include "system/task.h"
#include "system/util.h"
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
void ModelTurnWhite(struct task_work *work, Sint16 characters);
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
void FUN_8c0574c6(NJS_POINT3 *start, NJS_POINT3 *target, Float distance,
                  NJS_POINT3 *out);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void WakeTimer(void);
void SleepTimer(void);
int GetGlobalTime(void);
void DrawSNumbers(struct hud_number *number);
void *syMalloc_default_malloc(size_t size);
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle DiffAngle(Angle from, Angle to);
Angle CreateNinjaAngle(Angle from, Angle to);
int VectorAngle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal_jp);
Bool FrameIn(struct task_work *work);
void SaveConstantAttr(void);
void LoadConstantAttr(void);
void OnConstantAttr(Uint32 and_attr, Uint32 or_attr);
void OffConstantAttr(Uint32 and_attr, Uint32 or_attr);
void SaveControl3D(void);
void LoadControl3D(void);
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);
extern NJS_TEXANIM time_digit_texanims[10 + 1];

/* the colon's sprite in time_digit_texanims, after the ten digits' */
#define COLON 10

void draw_object(NJS_OBJECT *object, const struct draw_override *overrides)
{
    Angle ang;

    njPushMatrix(NULL);
    if (object->model != NULL) {
        int i;

        for (i = 0; overrides[i].object != NULL; i++) {
            if (overrides[i].object == object) {
                break;
            }
        }
        if (overrides[i].object == NULL) {
            njTranslateV(NULL, (NJS_VECTOR *)object->pos);
            TURN_VIA(njRotateZ, object->ang[2], ang);
            TURN_VIA(njRotateX, object->ang[0], ang);
            TURN_VIA(njRotateY, object->ang[1], ang);
            njScaleV(NULL, (NJS_VECTOR *)object->scl);
            ds_DrawModelClip(object->model);
        } else if (overrides[i].draw != NULL) {
            overrides[i].draw(object);
        }
    } else {
        njTranslateV(NULL, (NJS_VECTOR *)object->pos);
        TURN_VIA(njRotateZ, object->ang[2], ang);
        TURN_VIA(njRotateX, object->ang[0], ang);
        TURN_VIA(njRotateY, object->ang[1], ang);
        njScaleV(NULL, (NJS_VECTOR *)object->scl);
    }
    if (object->child != NULL) {
        njPushMatrix(NULL);
        draw_object(object->child, overrides);
        late_DrawObjectClipEx(1);
    }
    late_DrawObjectClipEx(1);
    if (object->sibling != NULL) {
        draw_object(object->sibling, overrides);
    }
}

void FUN_8c0574c6(NJS_POINT3 *start, NJS_POINT3 *target, Float distance,
                  NJS_POINT3 *out)
{
    NJS_VECTOR way;

    way.x = target->x - start->x;
    way.y = target->y - start->y;
    way.z = target->z - start->z;
    if (njUnitVector(&way) == 0.0F) {
        *out = *start;
    } else {
        way.x *= distance;
        way.y *= distance;
        way.z *= distance;
        way.x += start->x;
        way.y += start->y;
        way.z += start->z;
        *out = way;
    }
}

Bool spheres_overlap(NJS_POINT3 *center1, NJS_POINT3 *center2, Float radius1,
                     Float radius2)
{
    NJS_SPHERE spheres[2];

    spheres[0].c.x = center1->x;
    spheres[0].c.y = center1->y;
    spheres[0].c.z = center1->z;
    spheres[0].r = radius1;
    spheres[1].c.x = center2->x;
    spheres[1].c.y = center2->y;
    spheres[1].c.z = center2->z;
    spheres[1].r = radius2;
    return njCollisionCheckSS(&spheres[0], &spheres[1]);
}

Angle angle_forward_distance(Angle angle, Angle target)
{
    angle &= 0xffff;
    target &= 0xffff;
    target |= 0x10000;
    target -= angle;
    return target & 0xffff;
}

Angle angle_shortest_distance(Angle angle, Angle target)
{
    Angle distance = angle_forward_distance(angle, target);

    if (distance > 0x8000) {
        distance = 0x10000 - distance;
    }
    return distance;
}

Angle angle_turn_toward(Angle angle, Angle target, Uint32 delta)
{
    Angle distance;

    angle &= 0xffff;
    target &= 0xffff;
    if (angle == target) {
        return angle;
    }
    distance = angle_forward_distance(angle, target);
    if (distance > 0x8000) {
        angle = (angle - delta) & 0xffff;
        if (angle_forward_distance(angle, target) < 0x8000) {
            angle = target;
        }
    } else {
        angle = (angle + delta) & 0xffff;
        if (angle_forward_distance(angle, target) > 0x8000) {
            angle = target;
        }
    }
    return angle & 0xffff;
}

/* draw value's last digits, as many as digits says and five at most, each
 * sprite at its own depth. value is clamped to 0 through 99999, and then to
 * one digit more than it draws. with two digits, 150 draws as 50, and 1500
 * as 99 */
static void hud_draw_digits(struct hud_layout *layout, int value, int digits)
{
    NJS_SPRITE sprite;
    int limit;
    int i;
    int digit;
    /* @hack spelling: at, places and number, copies of the parameters, which
     * put digits' MOV R6,R12 ahead of value's MOV R5,R13 (0x8c05a7b4,
     * 0x8c05a7b8); without them the two trade and 2 of 212 words differ */
    struct hud_layout *at = layout;
    int places = digits;
    int number = value;

    njSetTexture_jp(&hud_digit_texlist);
    sprite.tlist = &hud_digit_texlist;
    sprite.tanim = time_digit_texanims;
    sprite.sx = at->scale.x;
    sprite.sy = at->scale.y;
    sprite.ang = 0;
    sprite.p.x = at->pos.x;
    sprite.p.y = at->pos.y;
    if (number >= 100000) {
        number = 99999;
    }
    if (number <= 0) {
        number = 0;
    }
    limit = 10;
    for (i = 0; i < places; i++) {
        limit *= 10;
    }
    limit--;
    if (number > limit) {
        number = limit;
    }
    if (places >= 5) {
        /* @hack spelling: a comma after each digit's assignment, which stores
         * the digit at @R15 and loads it back into R5 for the call, as at
         * 0x8c05a866 and 0x8c05a86a; with semicolons it goes straight to R5,
         * 184 of 212 words differ and the code runs 32 bytes short */
        digit = number / 10000,
        late_DrawSprite2D(&sprite, digit, -10.0F, NJD_SPRITE_ALPHA);
        sprite.p.x += at->spacing.x;
        sprite.p.y += at->spacing.y;
    }
    if (places >= 4) {
        digit = number % 10000 / 1000,
        late_DrawSprite2D(&sprite, digit, -10.001F, NJD_SPRITE_ALPHA);
        sprite.p.x += at->spacing.x;
        sprite.p.y += at->spacing.y;
    }
    if (places >= 3) {
        digit = number % 1000 / 100,
        late_DrawSprite2D(&sprite, digit, -10.002F, NJD_SPRITE_ALPHA);
        sprite.p.x += at->spacing.x;
        sprite.p.y += at->spacing.y;
    }
    if (places >= 2) {
        digit = number % 100 / 10,
        late_DrawSprite2D(&sprite, digit, -10.003F, NJD_SPRITE_ALPHA);
        sprite.p.x += at->spacing.x;
        sprite.p.y += at->spacing.y;
    }
    if (places >= 1) {
        digit = number % 10,
        late_DrawSprite2D(&sprite, digit, -10.004F, NJD_SPRITE_ALPHA);
    }
}

void hud_draw_time(struct hud_layout *layout, int minutes, int seconds)
{
    struct hud_layout next;
    NJS_SPRITE sprite;

    next = *layout;
    hud_draw_digits(&next, minutes, 2);
    next.pos.x += layout->spacing.x * 2.0F;
    njSetTexture_jp(&hud_digit_texlist);
    sprite.tlist = &hud_digit_texlist;
    sprite.tanim = time_digit_texanims;
    sprite.sx = next.scale.x;
    sprite.sy = next.scale.y;
    sprite.ang = 0;
    sprite.p.x = next.pos.x;
    sprite.p.y = next.pos.y;
    late_DrawSprite2D(&sprite, COLON, -10.0F, NJD_SPRITE_ALPHA);
    next.pos.x += layout->spacing.x;
    hud_draw_digits(&next, seconds, 2);
}

void draw_line_facing(struct angles *ang, NJS_POINT3 *pos, Float length)
{
    NJS_VECTOR way;
    NJS_POINT3 end;

    way.x = 0.0F;
    way.y = 0.0F;
    way.z = length;
    njPushMatrix(NULL);
    njUnitMatrix(NULL);
    njRotateXYZ(NULL, ang->x, ang->y, ang->z);
    njCalcVector(NULL, &way, &end);
    end.x += pos->x;
    end.y += pos->y;
    end.z += pos->z;
    late_DrawObjectClipEx(1);
    DrawLine(pos->x, pos->y, pos->z, end.x, end.y, end.z);
}
