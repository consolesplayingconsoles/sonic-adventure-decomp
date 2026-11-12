/* @unit 0C901B40-0C901F40 +r04 +egflags +pool32 +poolafter=ShidaDestructor +asmfunc=ObjectPastSotetsu:0c901e2a */
/* O SHIDA, a fern, and O SOTETSU, a cycad. a plant that stands still sways
 * through its action once whenever another collision record starts or stops
 * touching it */
#include <ninja.h>
#include <sg_xpt.h>

#include "adv03/plants.h"
#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/draw.h"
#include "draw/model.h"
#include "draw/tree.h"
#include "object/placement.h"
#include "sound/sound.h"
#include "system/task.h"
#include "system/texture.h"
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
extern struct near_task around_enemy_list_p0[1160 + 1];
extern struct near_task around_enemy_list_p1[1160 + 1];
extern struct collision_work *enemy_entry_num[128];
extern struct collision_work *enemy_colli_list2[256];
extern NJS_OBJECT object_sphere01;
extern NJS_OBJECT object_cylinder01;
extern NJS_OBJECT collision_dome_object;
void CCL_CalcRange(struct collision_work *collision);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
void DeadOut(struct task *task);
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
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);

#define PLANT_SWAYING 0x200
#define PLANT_TOUCHED 0x400
#define PLANT_CHANGED 0x800
#define SE_SWAY 0x255
#define VIEW_RADIUS 30.0F
#define SHIDA_FRAMES 60.0F
#define SOTETSU_FRAMES 15.0F
#define VARS(work) ((struct plant_vars *)&(work)->vars)
extern NJS_ACTION shida_action;
extern NJS_ACTION sotetsu_action;
extern NJS_OBJECT ___ADV03_OBJECTS;

/* flags of work->flags. PLANT_SWAYING lasts from a sway's step through the
 * draw after it, which then plays the action. PLANT_TOUCHED is set while
 * another record touches the plant, and PLANT_CHANGED for the step a touch
 * starts or ends */

/* the sound a sway starts with */
/* the radius draw_in_view tests a plant's position by */

/* a sway plays its action one frame each step, from frame 0 until the frame
 * reaches SHIDA_FRAMES or SOTETSU_FRAMES */

enum plant_mode { PLANT_INIT, PLANT_WAIT, PLANT_SWAY };

struct plant_vars {
    Uint8 unk_00[8];
    Float frame;
};
extern struct collision_shape cinfo_bush[1];

void ShidaDestructor(struct task *task);
void ShidaDisplayer(struct task *task);
void SotetsuDestructor(struct task *task);
void SotetsuDisplayer(struct task *task);
void chk_hitedge(struct task_work *work);

void ObjectPastShida(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (OnEdit(task)) {
        ShidaDisplayer(task);
        return;
    }
    chk_hitedge(work);
    switch (work->mode) {
    case PLANT_INIT:
        CCL_Init(task, cinfo_bush, COLLISION_OBJECT, 1, 1);
        task->destructor = ShidaDestructor;
        task->draw = ShidaDisplayer;
        work->mode = PLANT_WAIT;
        break;
    case PLANT_WAIT:
        if (work->flags & PLANT_CHANGED) {
            work->mode = PLANT_SWAY;
            VARS(work)->frame = 0.0F;
            dsPlay_oneshot(SE_SWAY, 0, 0, 0);
        }
        break;
    case PLANT_SWAY:
        work->flags |= PLANT_SWAYING;
        VARS(work)->frame += 1.0F;
        if (VARS(work)->frame >= SHIDA_FRAMES) {
            VARS(work)->frame = 0.0F;
            work->mode = PLANT_WAIT;
        }
        break;
    }
    ShidaDisplayer(task);
    work->flags &= ~PLANT_SWAYING;
    EntryColliList(work);
}

void ShidaDestructor(struct task *task)
{
}

void ShidaDisplayer(struct task *task)
{
    struct task_work *work = task->work;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, VIEW_RADIUS)) {
        NJS_ACTION *action = &shida_action;

        SetObjectTexture();
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        njRotateZXY(((void *)0), work->ang.x, work->ang.y, work->ang.z);
        if (work->flags & 0x200) {
            ds_ActionClip(action, ((struct plant_vars *)&(work)->vars)->frame);
        } else {
            late_DrawObject(action->object);
        }
        late_DrawObject(&___ADV03_OBJECTS);
        late_DrawObjectClipEx(1);
    }
}

void ObjectPastSotetsu(struct task *task)
{
    struct task_work *work = task->work;

    if (CheckRangeOut(task)) {
        return;
    }
    if (OnEdit(task)) {
        SotetsuDisplayer(task);
        return;
    }
    chk_hitedge(work);
    switch (work->mode) {
    case PLANT_INIT:
        CCL_Init(task, cinfo_bush, COLLISION_OBJECT, 1, 1);
        task->destructor = SotetsuDestructor;
        task->draw = SotetsuDisplayer;
        work->mode = PLANT_WAIT;
        break;
    case PLANT_WAIT:
        if (work->flags & PLANT_CHANGED) {
            work->mode = PLANT_SWAY;
            VARS(work)->frame = 0.0F;
            dsPlay_oneshot(SE_SWAY, 0, 0, 0);
        }
        break;
    case PLANT_SWAY:
        work->flags |= PLANT_SWAYING;
        VARS(work)->frame += 1.0F;
        if (VARS(work)->frame >= SOTETSU_FRAMES) {
            VARS(work)->frame = 0.0F;
            work->mode = PLANT_WAIT;
        }
        break;
    }
    SotetsuDisplayer(task);
    work->flags &= ~PLANT_SWAYING;
    EntryColliList(work);
}

void SotetsuDestructor(struct task *task)
{
}

void SotetsuDisplayer(struct task *task)
{
    struct task_work *work = task->work;

    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, VIEW_RADIUS)) {
        NJS_ACTION *action = &sotetsu_action;

        SetObjectTexture();
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        njRotateZXY(((void *)0), work->ang.x, work->ang.y, work->ang.z);
        if (work->flags & 0x200) {
            ds_ActionClip(action, ((struct plant_vars *)&(work)->vars)->frame);
        } else {
            late_DrawObject(action->object);
        }
        late_DrawObject(&___ADV03_OBJECTS);
        late_DrawObjectClipEx(1);
    }
}

/* clear PLANT_CHANGED, then set it for the step another record starts or
 * stops touching the plant. without a collision record, PLANT_TOUCHED stays
 * as it was */
void chk_hitedge(struct task_work *work)
{
    work->flags &= ~PLANT_CHANGED;
    if (work->collision != NULL) {
        if (work->collision->flags & COLLISION_HIT) {
            if (!(work->flags & PLANT_TOUCHED)) {
                work->flags |= PLANT_CHANGED;
            }
            work->flags |= PLANT_TOUCHED;
        } else {
            if (work->flags & PLANT_TOUCHED) {
                work->flags |= PLANT_CHANGED;
            }
            work->flags &= ~PLANT_TOUCHED;
        }
    }
}
