/* @unit 0C906D80-0C906F00 +r04 +egflags +pool32 +asmfunc=FUN_0c906d84:0c906e3e */
/* Idea, which shows the second table's idea pieces in place. it shows the
 * next piece too, from when the cards deal it until player 0 carries it */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "stg09/casino.h"
#include "stg09/idea.h"
#include "stg09/pinball.h"
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
int thunk_FUN_8c09cbc0(char *name, void *dest);
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
void FUN_0c906e62(struct task *task);
void SetGetRing(Uint8 count);

#define LAST_FRAME 15.0F
#define FRAME_RATE 0.1F
#define VARS(work) ((struct idea_vars *)&(work)->vars)
extern NJS_OBJECT idea_object_0;
extern NJS_OBJECT idea_object_1;
extern NJS_OBJECT idea_object_2;
extern NJS_OBJECT idea_object_3;
extern NJS_OBJECT idea_object_4;
extern NJS_MOTION idea_motion;
extern NJS_OBJECT *idea_objects[5];
extern NJS_POINT3 idea_places[5];

struct idea_vars {
    /* idea_motion's frame, in the task's first var, which first holds the
     * object kind's param */
    Float frame;
};

void idea_destroy(struct task *task)
{
}
#ifdef NON_MATCHING

void idea_draw(struct task *task)
{
    struct task_work *work = task->work;
    int i;

    casino_set_texture(CASINO_TEXTURES_ACTS_34);
    if (pinball_idea_draws >= PINBALL_IDEA_DRAWS) {
        pinball_idea_draws = PINBALL_IDEA_DRAWS;
#ifdef GCC
        /* repairs the read the tag names: GCC draws no next piece once all
         * PINBALL_IDEAS are in place */
        if (!(PinballFlag & CASINO_IDEA_CARRIED) &&
            pinball_ideas < PINBALL_IDEAS) {
#else
        if (!(PinballFlag & CASINO_IDEA_CARRIED)) {
#endif
            njPushMatrix(NULL);
            njTranslateV(NULL, &work->pos);
            /* @bug memory: with every piece in place, this reads the
             * word past idea_objects, idea_places[0]'s x, as the next
             * piece's model, at 0x0c9075f8 */
            draw_motion(idea_objects[pinball_ideas], &idea_motion,
                        VARS(work)->frame);
            late_DrawObjectClipEx(1);
        }
    }
    for (i = 0; i < pinball_ideas; i++) {
        njPushMatrix(NULL);
        njTranslate(NULL, idea_places[i].x, idea_places[i].y, idea_places[i].z);
        draw_motion(idea_objects[i], &idea_motion, VARS(work)->frame);
        late_DrawObjectClipEx(1);
    }
}
#else
void idea_draw(struct task *task)
{
    volatile int asm_stub[8];
    asm_stub[0] = 0;
    asm_stub[1] = 1;
    asm_stub[2] = 2;
    asm_stub[3] = 3;
    asm_stub[4] = 4;
    asm_stub[5] = 5;
    asm_stub[6] = 6;
    asm_stub[7] = 7;
    asm_stub[0] = 8;
    asm_stub[1] = 9;
    asm_stub[2] = 10;
    asm_stub[3] = 11;
    asm_stub[4] = 12;
    asm_stub[5] = 13;
    asm_stub[6] = 14;
    asm_stub[7] = 15;
    asm_stub[0] = 16;
    asm_stub[1] = 17;
    asm_stub[2] = 18;
    asm_stub[3] = 19;
    asm_stub[4] = 20;
    asm_stub[5] = 21;
    asm_stub[6] = 22;
    asm_stub[7] = 23;
    asm_stub[0] = 24;
    asm_stub[1] = 25;
    asm_stub[2] = 26;
    asm_stub[3] = 27;
    asm_stub[4] = 28;
    asm_stub[5] = 29;
    asm_stub[6] = 30;
    asm_stub[7] = 31;
}
#endif

void idea_run(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->frame += FRAME_RATE;
    if (VARS(work)->frame >= LAST_FRAME) {
        VARS(work)->frame = 0.0F;
    }
    idea_draw(task);
}

void FUN_0c906e62(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->frame = 0.0F;
    PinballFlag &= ~CASINO_IDEA_CARRIED;
    pinball_ideas = 1;
    task->step = idea_run;
    task->draw = idea_draw;
    task->destructor = idea_destroy;
}
