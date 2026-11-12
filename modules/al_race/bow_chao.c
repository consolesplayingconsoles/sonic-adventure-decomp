/* @unit 0CB93820-0CB93A00 @data 0CB9A378-0CB9A390 +r04 +egflags +pool32 */
/* BOW CHAO, a Chao in the race hall that bows as the hall's door starts to
 * open from shut, and as something touches it */
#include <ninja.h>
#include <sg_xpt.h>

#include "al_race/bow_chao.h"
#include "al_race/door.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "object/placement.h"
#include "object/simple.h"
#include "system/frame.h"
#include "system/task.h"
#include "system/task_desc.h"
#include "system/texture.h"
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
void FUN_0cb93820(struct task *task);
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void CCL_Init(struct task *task, const struct collision_shape *shapes,
              Uint8 kind, int unused, Uint8 count);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
void MirenObjDrawCharColliObjectNoScale(NJS_OBJECT *object,
                                        struct task_work *work,
                                        NJS_TEXLIST *texlist);
void MirenObjEntryMobileLandObject(struct task *task, NJS_OBJECT *object,
                                   Sint32 flags, Float scale);
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
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

/* the Chao's model and its bow */
#define BOW_CHAO(task) ((struct bow_chao *)(task)->motion)
#define BOW_CHAO_SCALE 2.0F
extern NJS_ACTION dat_0cbd2ee4;

/* the Chao's state, in its task's motion */
struct bow_chao {
    int mode;
    Float frame;
    Float last; /* the action's last frame */
    Float speed; /* the frames the bow plays a step */
    NJS_ACTION *action;
};

/* bow_chao_start's arg */
struct bow_chao_start {
    Float speed;
    NJS_ACTION *action;
};

/* the Chao's modes. BOW_WAIT waits for the door or a touch. BOW_BOWING
 * plays the bow once, from frame 0 to its last, then waits again */
enum bow_chao_mode { BOW_WAIT, BOW_BOWING };

void bow_chao_start(struct task *task, void *arg);
void bow_chao_step(struct task *task);
void bow_chao_draw(struct task *task);
extern struct collision_shape bow_chao_shapes[1];

static const struct task_desc bow_chao_desc = {
    sizeof(struct bow_chao), TASK_WORK,     bow_chao_start,
    bow_chao_step,           bow_chao_draw, NULL};
extern const struct bow_chao_start bow_chao_kind;
extern const struct collision_list bow_chao_list;
extern const struct collision_kind bow_chao_collision;
extern struct collision_shape bow_chao_shapes[1];

void FUN_0cb93820(struct task *task)
{
    MirenInitTask(task, &bow_chao_desc, (void *)&bow_chao_kind);
}

void bow_chao_start(struct task *task, void *arg)
{
    struct bow_chao *chao;
    NJS_ACTION *action;

    if (!OnEdit(task)) {
        object_collision_init(task, (struct collision_list *)&bow_chao_list,
                              (struct collision_kind *)&bow_chao_collision);
    }
    chao = BOW_CHAO(task);
    action = ((struct bow_chao_start *)arg)->action;
    chao->mode = BOW_WAIT;
    chao->frame = 0.0F;
    chao->last = action->motion->nbFrame - 1.0F;
    chao->speed = ((struct bow_chao_start *)arg)->speed;
    chao->action = action;
}

void bow_chao_step(struct task *task)
{
    struct bow_chao *chao;
    struct task_work *work;

    if (!CheckRangeOut(task)) {
        work = task->work;
        chao = BOW_CHAO(task);
        if (!OnEdit(task)) {
            switch (chao->mode) {
            case BOW_WAIT:
                if (door_opening() ||
                    (work->collision->flags & COLLISION_HIT)) {
                    chao->mode = BOW_BOWING;
                }
                break;
            case BOW_BOWING:
                chao->frame += chao->speed;
                if (chao->frame >= chao->last) {
                    chao->frame = 0.0F;
                    chao->mode = BOW_WAIT;
                }
                break;
            }
            EntryColliList(work);
        }
        bow_chao_draw(task);
    }
}

void bow_chao_draw(struct task *task)
{
    if (loop_count == 0) {
        struct task_work *work = task->work;
        struct bow_chao *chao = BOW_CHAO(task);

        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        {
            struct angles *ang = &work->ang;
            Angle turn;

            TURN_VIA(njRotateY, ang->y, turn);
        }
        {
            /* @hack spelling: scale, BOW_CHAO_SCALE in a local, which puts
             * ang at @(4,R15) and turn at @R15 (0x0cb94e4a, 0x0cb94e52), as
             * the image does. with BOW_CHAO_SCALE passed to njScale, the two
             * swap and 3 of 60 words differ */
            Float scale = BOW_CHAO_SCALE;

            njScale(NULL, scale, scale, scale);
        }
        SetObjectTexture();
        ds_ActionClip(chao->action, chao->frame);
        late_DrawObjectClipEx(1);
    }
}
