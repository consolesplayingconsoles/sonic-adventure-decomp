/* @unit 8C09E1E0-8C09E280 +jpflags +pool32 */
/* particle pools: those every stage makes, and those each stage adds */
#include <sg_xpt.h>

#include "adv01obj/pools.h"
#include "al_race/pools.h"
#include "b_chaos6/snow.h"
#include "effect/bomb.h"
#include "effect/dust.h"
#include "effect/explosion.h"
#include "effect/flame.h"
#include "effect/hit.h"
#include "effect/panlight.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "effect/snow.h"
#include "effect/sparkle.h"
#include "effect/splash.h"
#include "object/rocket.h"
#include "sboard/pools.h"
#include "stage/stage.h"
#include "stg03/coaster.h"
#include "stg05/rock_burst.h"
#include "stg08/snowman.h"
#include "stg09/water_smoke.h"
#include "stg10/pom.h"
#include "stg10/puff.h"
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
struct particle *SpCreateTask(struct particle_pool *pool,
                              void (*step)(struct particle *particle,
                                           struct particle_pool *pool));
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void CreateBomb(NJS_POINT3 *pos, Float scale);
void CreateFlash(struct task_work *work, Float scale);
void CreateFlash2(Float x, Float y, Float z, Float scale);
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
extern Sint16 stage_retry_count;
extern Uint16 enemy_colli_list;
extern Uint16 enemy2_entry_num;
extern Sint8 ucMinutes;
extern Sint8 ucSeconds;
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR vG;
enum stage_group LoadTextureForEachGameMode(void);
void SetFinishAction(void);
int GetPlayerNumber(void);
Bool ChkPause(void);
extern struct particle_pool_spec *common_pools[];
extern struct particle_pool_spec *beach_pools[];
extern struct particle_pool_spec *twinkle_pools[];
extern struct particle_pool_spec *highway_pools[];
extern struct particle_pool_spec *mountain_pools[];
extern struct particle_pool_spec *icecap_pools[];
extern struct particle_pool_spec *casino_pools[];
extern struct particle_pool_spec *shelter_pools[];
extern struct particle_pool_spec *alife_ss_pools[];
extern struct particle_pool_spec *chaos6_pools[];
extern struct particle_pool_spec *chaos7_pools[];
extern struct particle_pool_spec **stage_pools[43];

void create_pools(struct particle_pool_spec **list)
{
    struct particle_pool_spec *spec;

    for (; *list != NULL; list++) {
        spec = *list;
        spec->pool = particle_pool_create(spec->anim, spec->size);
        if (spec->init != NULL) {
            spec->init(spec->pool);
        }
    }
}

void particle_create_pools(void)
{
    Uint16 stage;
    struct particle_pool_spec **list;

    create_pools(common_pools);
    stage = STAGE_OF(GetStageNumber());
    /* @hack spelling: list assigned in the test, which keeps the stage in R5
     * (MOV R0,R5 at 0x8c0a3d92); assigned before the test, 10 of 24 words
     * differ */
    if ((list = stage_pools[stage])) {
        create_pools(list);
    }
}
