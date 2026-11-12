/* @unit 0CB94620-0CB947E0 @data 0CB9A4CC-0CB9A4E4 +r04 +egflags +pool32 */
/* CHEER CHAO, a Chao on the race course that cheers over and over */
#include <ninja.h>
#include <sg_xpt.h>
#include <stdlib.h>

#include "al_race/cheer_chao.h"
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
void *syMalloc_default_malloc(size_t size);
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void FUN_0cb94620(struct task *task);
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
Bool CheckRangeOut(struct task *task);
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

/* the Chao's model and its cheer */
#define CHEER_CHAO(task) ((struct cheer_chao *)(task)->motion)
#define CHEER_CHAO_SCALE 1.3F
extern NJS_ACTION dat_0cbd2780;

/* the Chao's state, in its task's motion */
struct cheer_chao {
    Float frame;
    Float last; /* the action's last frame */
    Float speed; /* the frames the cheer plays a step */
    NJS_ACTION *action;
};

/* cheer_chao_start's arg */
struct cheer_chao_start {
    Float speed;
    NJS_ACTION *action;
};

void cheer_chao_start(struct task *task, void *arg);
void execObject(struct task *task);
void dispObject(struct task *task);
extern struct collision_shape cheer_chao_shapes[1];

static const struct task_desc cheer_chao_desc = {sizeof(struct cheer_chao),
                                                 TASK_WORK,
                                                 cheer_chao_start,
                                                 execObject,
                                                 dispObject,
                                                 NULL};
extern const struct cheer_chao_start cheer_chao_kind;
extern const struct collision_list cheer_chao_list;
extern const struct collision_kind cheer_chao_collision;
extern struct collision_shape cheer_chao_shapes[1];

void FUN_0cb94620(struct task *task)
{
    MirenInitTask(task, &cheer_chao_desc, (void *)&cheer_chao_kind);
}

void cheer_chao_start(struct task *task, void *arg)
{
    NJS_ACTION *action;
    Float last;
    struct cheer_chao *chao;

    if (!OnEdit(task)) {
        object_collision_init(task, (struct collision_list *)&cheer_chao_list,
                              (struct collision_kind *)&cheer_chao_collision);
    }
    action = ((struct cheer_chao_start *)arg)->action;
    last = action->motion->nbFrame - 1.0F;
    chao = CHEER_CHAO(task);
    chao->frame = rand() * last * RAND_SCALE;
    chao->last = last;
    chao->speed = ((struct cheer_chao_start *)arg)->speed;
    chao->action = action;
}

void execObject(struct task *task)
{
    struct task_work *work;
    struct cheer_chao *chao;

    if (CheckRange(task)) {
        FreeTask(task);
        return;
    }
    work = task->work;
    chao = CHEER_CHAO(task);
    chao->frame += chao->speed;
    if (chao->frame >= chao->last) {
        chao->frame -= chao->last;
    }
    if (!OnEdit(task)) {
        EntryColliList(work);
    }
    dispObject(task);
}

void dispObject(struct task *task)
{
    if (loop_count == 0) {
        struct task_work *work = task->work;
        struct cheer_chao *chao = CHEER_CHAO(task);

        njPushMatrix(NULL);
        njTranslateV(NULL, &work->pos);
        {
            struct angles *ang = &work->ang;
            Angle turn;

            TURN_VIA(njRotateY, ang->y, turn);
        }
        {
            /* @hack spelling: scale, CHEER_CHAO_SCALE in a local, which puts
             * ang at @(4,R15) and turn at @R15 (0x0cb95c9a, 0x0cb95ca2), as
             * the image does. with CHEER_CHAO_SCALE passed to njScale, the
             * two swap and 3 of 59 words differ */
            Float scale = CHEER_CHAO_SCALE;

            njScale(NULL, scale, scale, scale);
        }
        SetObjectTexture();
        ds_ActionClip(chao->action, chao->frame);
        late_DrawObjectClipEx(1);
    }
}
