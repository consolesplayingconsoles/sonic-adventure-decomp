/* @unit 8C052FA0-8C053320 +r04 +egflags +pool32 */
/* the stage's directional light, and the lights tasks bring */
#include <ninja.h>

#include "draw/light.h"
#include "stage/stage.h"
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
void FUN_8c610c70(Float inten, Float ambient);
void FUN_8c610c7e(Float r, Float g, Float b);
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
void FUN_8c052fa0(struct task *task);
struct task *FUN_8c0531d6(struct task *parent, NJS_LIGHT *light,
                          struct light_spec *spec);
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
struct task *CreateElementalTask(Uint16 flags, int level,
                                 void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
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

/* the modes of light_stage_step's task and of light_create's. LIGHT_END
 * kills the task, and light_create's reaches it once the stage or act
 * changes */
#define VARS(work) ((struct light_vars *)&(work)->vars)
enum light_mode { LIGHT_INIT, LIGHT_KEEP, LIGHT_END };

/* what light_create's task keeps in work->vars */
struct light_vars {
    NJS_LIGHT *light;
    struct light_spec *spec;
};

void light_stage_destroy(struct task *task);
void light_destroy(struct task *task);
void light_step(struct task *task);
extern NJS_LIGHT dir_light;

/* make dir_light in the first step. each step after copies it to ninja's
 * easy light, with its direction turned by the current matrix and its
 * ambient doubled */
void FUN_8c052fa0(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VECTOR direction;

    switch (work->mode) {
    case LIGHT_INIT:
        njCreateLight(&dir_light, NJD_PHONG_DIR);
        njSetLightIntensity(&dir_light, 0.8F, 1.0F, 0.25F);
        njSetLightColor(&dir_light, 1.0F, 1.0F, 1.0F);
        njSetLightAngle(&dir_light, NJM_DEG_ANG(15), NJM_DEG_ANG(70));
        njSetLightDirection(&dir_light, 0.866025F, -0.6F, 0.0F);
        task->destructor = light_stage_destroy;
        work->mode++;
        break;
    case LIGHT_KEEP:
        njPushMatrix(NULL);
        njCalcVector(NULL, &dir_light.vctr, &direction);
        late_DrawObjectClipEx(1);
        njSetEasyLight(direction.x, direction.y, direction.z);
        FUN_8c610c70(dir_light.attr.idif, dir_light.attr.iamb * 2.0F);
        FUN_8c610c7e(dir_light.attr.argb.r, dir_light.attr.argb.g,
                     dir_light.attr.argb.b);
        break;
    case LIGHT_END:
        FreeTask(task);
        break;
    }
}

void light_stage_destroy(struct task *task)
{
    njDeleteLight(&dir_light);
}

void light_destroy(struct task *task)
{
    struct task_work *work = task->work;
    NJS_LIGHT *light = VARS(work)->light;

    njDeleteLight(light);
}

/* make the light from its spec in the first step, and end the task once
 * the stage or act differs from the first step's. the work's timer holds
 * that stage and act */
void light_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_LIGHT *light;
    struct light_spec *spec;

    switch (work->mode) {
    case LIGHT_INIT:
        light = VARS(work)->light;
        spec = VARS(work)->spec;
        TASK_TIMER(work) = GetStageNumber();
        njCreateLight(light, spec->type);
        njSetLightIntensity(light, spec->specular, spec->diffuse,
                            spec->ambient);
        njSetLightColor(light, spec->color.r, spec->color.g, spec->color.b);
        if (spec->type & (NJD_DIR_LIGHT | NJD_SPOT_LIGHT)) {
            njSetLightDirection(light, spec->direction.x, spec->direction.y,
                                spec->direction.z);
        }
        if (spec->type & (NJD_POINT_LIGHT | NJD_SPOT_LIGHT)) {
            njSetLightRange(light, spec->near, spec->far);
        }
        if (spec->type & NJD_SPOT_LIGHT) {
            njSetLightAngle(light, spec->inner, spec->outer);
        }
        task->destructor = light_destroy;
        work->mode++;
        break;
    case LIGHT_KEEP:
        if (TASK_TIMER(work) != GetStageNumber()) {
            work->mode = LIGHT_END;
        }
        break;
    case LIGHT_END:
        FreeTask(task);
        break;
    }
}

struct task *FUN_8c0531d6(struct task *parent, NJS_LIGHT *light,
                          struct light_spec *spec)
{
    struct task_work *from = parent->work;
    struct task *task;
    struct task_work *work;
    NJS_POINT3 offset;
    NJS_VECTOR turned;

    /* @hack spelling: task assigned in the test, which tests
     * task_create_child's R0 with the copy to R12 in the BT/S's slot
     * (0x8c05659e, 0x8c0565a2); assigned apart, SHC copies it first and
     * tests R12, and 3 of 106 words differ */
    if ((task = CreateChildTask(TASK_WORK, light_step, parent)) != NULL) {
        work = task->work;
        if (work != NULL) {
            if (from != NULL) {
                offset = spec->pos;
                njPushMatrix(&nj_unit_matrix_);
                njTranslateV(NULL, &from->pos);
                TURN(njRotateZ, from->ang.z);
                TURN(njRotateX, from->ang.x);
                TURN(njRotateY, from->ang.y);
                /* @bug logic: the task stands at the parent's position plus
                 * offset unturned, and the turned offset goes unread.
                 * njCalcVector's JSR at 0x8c05660a writes turned at R15+12,
                 * and the sums read offset from R15+24 (0x8c056614 to
                 * 0x8c056636) */
                njCalcVector(NULL, &offset, &turned);
                late_DrawObjectClipEx(1);
                work->pos.x = from->pos.x + offset.x;
                work->pos.y = from->pos.y + offset.y;
                work->pos.z = from->pos.z + offset.z;
            }
            VARS(work)->light = light;
            VARS(work)->spec = spec;
        }
    } else {
        /* @hack redundant: a return of NULL where return task returns the same,
         * which gives the null path its own MOV #0,R0 (0x8c056642,
         * 0x8c056644); without it, 13 of 106 words differ */
        return NULL;
    }
    return task;
}
