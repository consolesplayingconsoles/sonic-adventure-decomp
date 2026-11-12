/* @unit 0C916B40-0C916D00 +egflags +pool32 */
/* a Chao's sleep */
#include <ninja.h>
#include <stdlib.h>

#include "al_main/behavior.h"
#include "al_main/chao.h"
#include "al_main/face.h"
#include "al_main/sleep.h"
#include "sound/sound.h"
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
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void AddExtraDisplay(Sint8 kind);
void ExtraDisplayInit(void);
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
extern struct polygon_contact colihitdat[];
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object,
                           Uint32 flags);
Bool CL_ColPolBeamHit(struct ray_query *query);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal_jp);
void FUN_0c908480(struct alife_chao *chao, int eyes, int steps);
void FUN_0c916b40(struct task_work *work, struct alife_chao *chao);
void kmiLogFileOpen(void *data);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
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

/* the motions. a Chao whose curio and agres are both 0 or below lies down
 * shy */
#define MOTION_LIE_DOWN 78
#define MOTION_LIE_DOWN_SHY 7
#define MOTION_GET_UP 81

#define SE_SNORE 0x359
#define SE_GET_UP 0x36c

/* the Chao snores as it lies down. each later snore comes once the work's
 * timer passes the Chao's limit. it restarts the timer, and sets the limit
 * to SNORE_WAIT steps and a random count below SNORE_SPREAD more. the first
 * of them waits for the limit the last behavior left */
#define SNORE_WAIT 100
#define SNORE_SPREAD 40.0F

/* a point of sleep runs out each time the work's tick passes SLEEP_TICKS,
 * which restarts it from 0. alife_sleep and the Chao's task step each count
 * the tick up, so each point after the first lasts 51 steps */
#define SLEEP_TICKS 100

/* the work's submode */
enum sleep_mode { SLEEP_LIE_DOWN, SLEEP_SLEEP, SLEEP_GET_UP };

void FUN_0c916b40(struct task_work *work, struct alife_chao *chao)
{
    struct chao_motion *motion = &chao->motion;

    switch (work->submode) {
    case SLEEP_LIE_DOWN:
        work->submode++;
        if (chao->record->curio > 0 || chao->record->agres > 0) {
            chao->motion.flags |= MOTION_NEW;
            chao->motion.id = MOTION_LIE_DOWN;
        } else {
            chao->motion.flags |= MOTION_NEW;
            chao->motion.id = MOTION_LIE_DOWN_SHY;
        }
        dsPlay_oneshot_v(SE_SNORE, 0, 0, -20, work->pos.x, work->pos.y,
                         work->pos.z);
        /* fall through */
    case SLEEP_SLEEP:
        if (chao->record->sleep == 0) {
            work->submode++;
            chao->motion.flags |= MOTION_NEW;
            chao->motion.id = MOTION_GET_UP;
            dsPlay_oneshot_v(SE_GET_UP, 0, 0, -20, work->pos.x, work->pos.y,
                             work->pos.z);
        } else if (work->tick++ > SLEEP_TICKS) {
            work->tick = 0;
            chao->record->sleep--;
        }
        if (TASK_TIMER(work) > chao->limit) {
            dsPlay_oneshot_v(SE_SNORE, 0, 0, -20, work->pos.x, work->pos.y,
                             work->pos.z);
            work->timer = 0;
            chao->limit =
                (int)(rand() * (SNORE_SPREAD * RAND_SCALE)) + SNORE_WAIT;
        }
        break;
    case SLEEP_GET_UP:
        if (motion->flags & MOTION_DONE) {
            /* NOLINTNEXTLINE(bugprone-signed-char-misuse) */
            chao->last_mode = work->mode;
            work->mode = MODE_IDLE;
            work->submode = 0;
            work->timer = 0;
            chao->mode_timer = 0;
        }
        break;
    }
    FUN_0c908480(chao, 4, 2);
    chao->accel.x = -chao->speed.x * 0.2F;
    chao->accel.z = -chao->speed.z * 0.2F;
}
