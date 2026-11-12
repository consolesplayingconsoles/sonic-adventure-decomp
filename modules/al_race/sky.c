/* @unit 0CB92020-0CB92200 @data 0CB99694-0CB996A4 +r04 +egflags +pool32 */
/* the Chao race's sky, a dome around the camera, drawn only on the course */
#define TEXT_1 ""
#include <ninja.h>
#include <sg_xpt.h>

#include "al_race/game.h"
#include "al_race/sky.h"
#include "camera/camera.h"
#include "draw/tree.h"
#include "stage/stage.h"
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
void AddExtraDisplay(Sint8 kind);
void ExtraDisplayInit(void);
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
extern struct cameraControlWork camera_state_record;
extern Bool CamPathCam2Core_AliveFlag;
extern struct angles CamPathCam2Core_Angle;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view),
                              Uint8 adjust, Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view),
                                  Uint8 adjust, Sint8 type);
void AmyBalanceGameStartChecker(struct camera_view *view);
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
struct task *MirenSetTask(int level, const struct task_desc *desc, void *arg);
struct task *MirenSetChildTask(struct task *parent,
                               const struct task_desc *desc, void *arg);
struct task *MirenInitTask(struct task *task, const struct task_desc *desc,
                           void *arg);
void ReleasePlayersTexture(int character);
Bool SetRegularTexture(void);
Bool SetObjectTexture(void);
Bool CheckObjectTexture(void);
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
void InterpolateModel(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out,
                      Float blend);
void InterpolatePointAsSin(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                           Float blend, int count);
void CalculatePointNormals(NJS_MODEL *model);
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                  Float radius);

#define TEXT_1_LENGTH 7

/* the sky's state, in its task's motion. texlist and object stay null until
 * SKY_LOAD loads the textures */
#define SKY(task) ((struct sky *)(task)->motion)
#define SKY_DROP 140.0F
#define SKY_SCALE 2.0F
struct sky {
    Uint8 stage; /* the stage the sky was created in */
    Uint8 act; /* the act sky_step last saw */
    Sint8 mode; /* an enum sky_mode */
    Uint8 unk_03; /* sky.c never reads or writes it */
    NJS_TEXLIST *texlist;
    NJS_OBJECT *object;
};

enum sky_mode { SKY_LOAD, SKY_SHOW };

/* the depth of the dome's center below the camera, and its scale */

void sky_init(struct task *task, void *arg);
void sky_step(struct task *task);
void sky_draw(struct task *task);
void sky_destroy(struct task *task);
extern const struct task_desc sky_desc;
extern NJS_MATERIAL sky_materials[1];
extern Sint16 sky_meshes0[96];
extern NJS_COLOR sky_uvs0[88];
extern NJS_MESHSET sky_meshsets[1];
extern NJS_POINT3 sky_points[41];
extern NJS_VECTOR sky_normals[41];
extern NJS_MODEL sky_model;
extern NJS_OBJECT sky_object;
extern NJS_TEXNAME sky_textures[1];
extern NJS_TEXLIST sky_texlist;
void race_sky_step(struct task *task);
void sky_init(struct task *task, void *arg)
{
    struct sky *sky = ((struct sky *)(task)->motion);
    Uint32 stage_act = GetStageNumber();
    sky->stage = (((stage_act) & 0xff00) >> 8);
    sky->act = stage_act;
    sky->mode = SKY_LOAD;
    sky->texlist = ((void *)0);
    sky->object = ((void *)0);
    sky_step(task);
}

/* end the task once the stage changes. the textures load at the first step,
 * and a change of act sends the sky back to SKY_LOAD, which leaves them
 * loaded */
void sky_step(struct task *task)
{
    struct sky *sky = SKY(task);
    Uint32 stage_act = GetStageNumber();
    Uint8 act;

    if (STAGE_OF(stage_act) != sky->stage) {
        FreeTask(task);
        return;
    }
    act = stage_act;
    switch (sky->mode) {
    case SKY_LOAD:
        if (act != sky->act) {
            sky->act = act;
        }
        if (sky->texlist == NULL) {
            NJS_TEXLIST *texlist = &sky_texlist;

            sky->texlist = texlist;
            texLoadTexturePvmFile("BG_AL_RACE02", texlist);
        }
        sky->object = &sky_object;
        sky->mode = SKY_SHOW;
        /* fallthrough */
    case SKY_SHOW:
        if (act != sky->act) {
            sky->act = act;
            sky->mode = SKY_LOAD;
        }
        break;
    default:
        FreeTask(task);
        break;
    }
    sky_draw(task);
}

/* draw the dome, on the course once it is loaded. every call turns fog off,
 * whether it draws or not */
void sky_draw(struct task *task)
{
    struct sky *sky = SKY(task);
    NJS_TEXLIST *texlist = sky->texlist;
    NJS_OBJECT *object = sky->object;
    NJS_POINT3 pos;
    NJS_POINT3 *camera = &camera_twp->pos;

    pos.x = camera->x;
    pos.y = camera->y - SKY_DROP;
    pos.z = camera->z;
    njFogDisable();
    if (loop_count == 0 && texlist != NULL && object != NULL &&
        sky->act == ACT_COURSE) {
        SaveControl3D();
        draw_control_clear(NJD_CONTROL_3D_DEPTH_QUEUE);
        njPushMatrix(NULL);
        njTranslateV(NULL, &pos);
        njScale(NULL, SKY_SCALE, SKY_SCALE, SKY_SCALE);
        njSetTexture_jp(texlist);
        late_DrawObject(object);
        late_DrawObjectClipEx(1);
        LoadControl3D();
    }
}

void sky_destroy(struct task *task)
{
    struct sky *sky = SKY(task);
    NJS_TEXLIST *texlist = sky->texlist;

    if (texlist != NULL) {
        njReleaseTexture_jp(texlist);
        sky->texlist = NULL;
    }
}
