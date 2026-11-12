/* @unit 0C908060-0C908600 @data 0CAC18D8-0CAC18E4 +r04 +egflags +pool32 +poolafter=DoaDraw,DoaExec +asmfunc=DoaDraw:0c9083a0 */
/* O SNOW DOA, a drawbridge that falls open on its chains once the first big
 * icicle has landed */
#include <ninja.h>
#include <sg_xpt.h>

#include "collision/collision.h"
#include "debug/editor.h"
#include "draw/tree.h"
#include "effect/snow.h"
#include "object/placement.h"
#include "sound/sound.h"
#include "stg08/big_icicle.h"
#include "stg08/snow_door.h"
#include "system/task.h"
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
void late_DrawObject(NJS_OBJECT *object);
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
extern struct set_file *pObjEditTable;
Bool CheckRange(struct task *task);
Bool CheckRangeOut(struct task *task);
void DeadOut(struct task *task);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                     Float z);
int dsPlay_iloop(int se, int id, int priority, int volume);
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

#define DOOR_RANGE (1300.0F * 1300.0F)
#define DOOR_OPEN 0x4000
#define DOOR_FALL_GAIN 2 /* the opening speed the door gains each step */
#define SE_DOOR_FALL 220
#define SE_DOOR_LAND 221
#define DOOR_FALL_UPDATES 90
#define LINK_SPAN 7.6F
#define LINK_EXTRA 5.0F
#define PUFFS 5
#define PUFF_SIZE 2.0F
#define VARS(work) ((struct snow_door_vars *)&(work)->vars)
#define CHAIN_WAY(work) (&(work)->scl)
extern NJS_OBJECT snow_door_object;
extern NJS_OBJECT snow_door_link_object;

/* destroyed beyond 1300 units of the camera and player 0 */

/* the door's opening as it lies flat: a quarter turn */

/* links lie 7.6 units apart, and a chain has five more links than its span
 * needs */

struct snow_door_vars {
    Uint32 opening;
    Sint16 links; /* each chain's link count, as the last draw measured it */
    Sint16 landed; /* DOOR_IN_AIR, DOOR_LANDED or DOOR_PUFFED */
    Uint32 fall_speed;
};

/* the unit vector along the chains, from the door to the hook */

enum snow_door_mode { DOOR_SHUT, DOOR_FALLING, DOOR_LANDING, DOOR_DOWN };
/* how far the landing has gone. the first draw at DOOR_LANDED raises the
 * puffs */
enum snow_door_landed { DOOR_IN_AIR, DOOR_LANDED, DOOR_PUFFED };

NJS_POINT3 GetTomeganePos(struct task_work *work, Angle tilt, NJS_POINT3 point);
extern NJS_POINT3 snow_door_chain_1;
extern NJS_POINT3 snow_door_chain_2;
extern NJS_POINT3 snow_door_hook;
extern NJS_POINT3 snow_door_top;
extern NJS_POINT3 snow_door_puffs[5];
extern struct collision_shape snow_door_shapes[3];

void snow_door_destroy(struct task *task)
{
}

/* draw the door, and each chain with the link count the last draw measured.
 * the first draw after the door lands raises the puffs */
void DoaDraw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 hook;
    NJS_POINT3 end;
    int links;
    int i;
    Float span;

    if (CheckRangeOutWithR(task, DOOR_RANGE)) {
        return;
    }
    links = VARS(work)->links;
    hook = GetTomeganePos(work, DOOR_OPEN, snow_door_hook);
    end = GetTomeganePos(work, -VARS(work)->opening + DOOR_OPEN, snow_door_top);
    CHAIN_WAY(work)->x = hook.x - end.x;
    CHAIN_WAY(work)->y = hook.y - end.y;
    CHAIN_WAY(work)->z = hook.z - end.z;
    njUnitVector(CHAIN_WAY(work));
    span = CalcDistance(&hook, &end);
    /* a multiplication by 1/LINK_SPAN, 0x3e06bca1, as SHC's code under
     * -aggressive=2 does */
    VARS(work)->links = (span * (1.0F / LINK_SPAN)) + LINK_EXTRA;
    SetObjectTexture();
    /* @hack type: njPushMatrix's argument as a bare 0, which makes the stack
     * frame 56 bytes (ADD #-56,R15 at 0x0c9085d8); as NULL, it is 52 bytes
     * and 222 of 364 words differ */
    njPushMatrix(0);
    njTranslateV(NULL, &work->pos);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateZ, -VARS(work)->opening);
    late_DrawObject(&snow_door_object);
    late_DrawObjectClipEx(1);
    SetObjectTexture();
    end = GetTomeganePos(work, -VARS(work)->opening + DOOR_OPEN,
                         snow_door_chain_1);
    for (i = 0; i < links; i++) {
        njPushMatrix(NULL);
        njTranslate(NULL, end.x + (CHAIN_WAY(work)->x * i * LINK_SPAN),
                    end.y + (CHAIN_WAY(work)->y * i * LINK_SPAN),
                    end.z + (CHAIN_WAY(work)->z * i * LINK_SPAN));
        TURN(njRotateY, work->ang.y);
        TURN(njRotateZ, (-VARS(work)->opening >> 1) + 0x7fff);
        late_DrawObject(&snow_door_link_object);
        late_DrawObjectClipEx(1);
    }
    end = GetTomeganePos(work, -VARS(work)->opening + DOOR_OPEN,
                         snow_door_chain_2);
    for (i = 0; i < links; i++) {
        njPushMatrix(NULL);
        njTranslate(NULL, end.x + (CHAIN_WAY(work)->x * i * LINK_SPAN),
                    end.y + (CHAIN_WAY(work)->y * i * LINK_SPAN),
                    end.z + (CHAIN_WAY(work)->z * i * LINK_SPAN));
        TURN(njRotateY, work->ang.y);
        TURN(njRotateZ, (-VARS(work)->opening >> 1) + 0x7fff);
        late_DrawObject(&snow_door_link_object);
        late_DrawObjectClipEx(1);
    }
    if (VARS(work)->landed == DOOR_LANDED) {
        NJS_POINT3 puff;
        NJS_VECTOR rise = {0.0F, 1.0F, 0.0F};

        /* @hack spelling: the increment written out, which keeps links in R11,
         * njPushMatrix's address in R12, draw_tree's in R9 and njPopMatrix's
         * in R10 (0x0c908602, 0x0c908688, 0x0c9086bc, 0x0c9086c2); as i++,
         * each pair trades and 19 of 364 words differ */
        for (i = 0; i < PUFFS; i = i + 1) {
            puff = GetTomeganePos(work, 0, snow_door_puffs[i]);
            snow_create(&puff, &rise, PUFF_SIZE);
        }
        VARS(work)->landed = DOOR_PUFFED;
    }
}

void DoaExec(struct task *task)
{
    struct task_work *work = task->work;
    struct collision_work *collision = work->collision;

    if (CheckRangeOutWithR(task, DOOR_RANGE)) {
        return;
    }
    if (!OnEdit(task)) {
        switch (work->mode) {
        case DOOR_SHUT:
            if (GetBigturaraStatus()) {
                dsPlay_timer(SE_DOOR_FALL, (int)work, 1, 0, DOOR_FALL_UPDATES);
                work->mode = DOOR_FALLING;
            } else {
                collision->shapes->ang.z = VARS(work)->opening;
            }
            break;
        case DOOR_FALLING:
            /* @bug logic: the opening is unsigned, so the test against 0
             * always holds. SHC folds it to the 1 it keeps in R11 (MOV #1 at
             * 0x0c90897e), and tests that (TST R11,R11 at 0x0c9089ea) */
            if (VARS(work)->opening >= 0 && VARS(work)->opening < DOOR_OPEN) {
                VARS(work)->fall_speed += DOOR_FALL_GAIN;
                VARS(work)->opening += VARS(work)->fall_speed;
                collision->shapes->ang.z = VARS(work)->opening;
            }
            if (VARS(work)->opening >= DOOR_OPEN &&
                VARS(work)->landed == DOOR_IN_AIR) {
                VARS(work)->opening = DOOR_OPEN;
                VARS(work)->landed = DOOR_LANDED;
                work->mode = DOOR_LANDING;
                collision->shapes->ang.z = VARS(work)->opening;
            }
            work->ang.z = -VARS(work)->opening;
            break;
        case DOOR_LANDING:
            dsPlay_oneshot(SE_DOOR_LAND, 0, 0, 0);
            work->mode = DOOR_DOWN;
            break;
        case DOOR_DOWN:
            break;
        }
    }
    DoaDraw(task);
    if (!OnEdit(task)) {
        EntryColliList(work);
    }
}

void obj_snow_doa(struct task *task)
{
    struct task_work *work = task->work;

    if (!CheckRangeOutWithR(task, DOOR_RANGE)) {
        VARS(work)->opening = 0;
        VARS(work)->fall_speed = 0;
        VARS(work)->links = 0;
        VARS(work)->landed = DOOR_IN_AIR;
        if (!OnEdit(task)) {
            CCL_Init(task, snow_door_shapes, COLLISION_OBJECT, 1, 3);
            work->collision->radius = 150.0F;
        }
        task->step = DoaExec;
        task->draw = DoaDraw;
        task->destructor = snow_door_destroy;
    }
}

/* where point, in the door's frame, lies in the world with that frame
 * turned tilt about z */
NJS_POINT3 GetTomeganePos(struct task_work *work, Angle tilt, NJS_POINT3 point)
{
    NJS_POINT3 out;

    njPushMatrix(&nj_unit_matrix_);
    TURN(njRotateY, work->ang.y);
    TURN(njRotateZ, tilt);
    njCalcPoint(NULL, &point, &out);
    late_DrawObjectClipEx(1);
    out.x += work->pos.x;
    out.y += work->pos.y;
    out.z += work->pos.z;
    return out;
}
