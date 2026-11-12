/* @unit 0C9051E0-0C905360 +egflags +pool32 */
/* Chaos 4 surfaces. he comes up facing player 0, and a column of water
 * bursts up round him. until he is back under, his shapes hurt nothing and
 * their guard stops no attack, and players can aim at him. back under, his
 * shapes hurt again, and their guard stops every attack */
#include <ninja.h>

#include "b_chaos4/boss.h"
#include "b_chaos4/column.h"
#include "b_chaos4/surface.h"
#include "b_chaos4/swamp.h"
#include "chaos/chaos.h"
#include "collision/collision.h"
#include "draw/motion.h"
#include "sound/sound.h"
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
void FUN_0c9051e0(struct task_work *work, struct task_motion *motion,
                  void *extra);
void FUN_0c906ca0(NJS_POINT3 *pos);
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
void EntryColliList(struct task_work *work);
void shape_get_center(struct task_work *work, struct collision_shape *shape,
                      NJS_POINT3 *pos);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal_jp);
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

#define DEPTH_Y 0.0F /* the depth he sinks back to */
#define RISE_TIME 60
#define UP_TIME 377
#define SINK_TIME 60
#define SE_SURFACE 0x178
#define UNDER_ATTACK 1
#define UNDER_GUARD GUARD(3)
enum surface_mode { SURFACE_RISE, SURFACE_BURST, SURFACE_UP, SURFACE_SINK };

/* the phases' countdowns: his rise before the column, his stay up after
 * it, and his sink. each phase ends on the step its count passes below 0 */

/* his sound as he starts up, and again as he starts down */

/* the attack level his shapes take once he is back under, and their guard
 * level, which no attack exceeds */

void FUN_0c9051e0(struct task_work *work, struct task_motion *motion,
                  void *extra)
{
    struct chaos *chaos = extra;
    struct chaos4 *record = CHAOS4_VARS(work)->record;
    int i;

    switch (work->submode) {
    case SURFACE_RISE:
        chaos4_set_shapes(work, SHAPES_ON);
        chaos->target.y = SWAMP_Y;
        /* @hack spelling: the action set through extra, cast, not chaos, which
         * keeps a second copy of extra on the stack (MOV.L R6,@R15 at
         * 0x0c905c32) and stores the action through it (0x0c905c72). through
         * chaos, chaos4_surface runs 32 bytes short, and 169 of 172 words
         * differ */
        ((struct chaos *)extra)->motion.wanted = ACTION_RISE;
        CHAOS4_VARS(work)->timer = RISE_TIME;
        record->turn = TURN_PLAYER;
        dsPlay_oneshot(SE_SURFACE, 0, 0, 0);
        work->collision->flags |= COLLISION_TARGET;
        /* his shapes hurt nothing, and their guard stops no attack */
        for (i = 0; i < CHAOS4_SHAPES; i++) {
            work->collision->shapes[i].levels =
                work->collision->shapes[i].levels & ~SHAPE_ATTACK;
            work->collision->shapes[i].levels =
                work->collision->shapes[i].levels & ~SHAPE_GUARD;
        }
        work->submode = SURFACE_BURST;
    case SURFACE_BURST:
        if (--((struct chaos4_vars *)&(work)->vars)->timer < 0) {
            FUN_0c906ca0(&work->pos);
            column_create(&work->pos, NULL);
            record->turn = TURN_NONE;
            CHAOS4_VARS(work)->timer = UP_TIME;
            work->submode = SURFACE_UP;
        }
        break;
    case SURFACE_UP:
        if (--CHAOS4_VARS(work)->timer < 0) {
            chaos->target.y = DEPTH_Y;
            CHAOS4_VARS(work)->timer = SINK_TIME;
            dsPlay_oneshot(SE_SURFACE, 0, 0, 0);
            work->submode = SURFACE_SINK;
        }
        break;
    case SURFACE_SINK:
        if (--CHAOS4_VARS(work)->timer < 0) {
            work->collision->flags &= ~COLLISION_TARGET;
            for (i = 0; i < CHAOS4_SHAPES; i++) {
                work->collision->shapes[i].levels =
                    (work->collision->shapes[i].levels & ~SHAPE_ATTACK) |
                    UNDER_ATTACK;
                work->collision->shapes[i].levels =
                    (work->collision->shapes[i].levels & ~SHAPE_GUARD) |
                    UNDER_GUARD;
            }
            work->submode = MODE_DONE;
        }
        break;
    }
    if (work->submode == MODE_DONE) {
        if (work->mode != BOSS_SWIM) {
            chaos_reqmode = BOSS_SWIM;
            boss_last_mode = work->mode;
        }
        work->submode = SURFACE_RISE;
    }
}
