/* @unit 8C0502A0-8C0509A0 +r04 +egflags +pool32 +poolafter=sprite_play_init,sprite_step +poolbra=sprite_render:4,sprite_task_step:j1 +asmfunc=sprite_play_step */
/* sprites: textured rectangles that face the screen and play through a list
 * of frames as they move. sprite_create runs one on a task of its own */
#include <ninja.h>
#include <sg_xpt.h>

#include "effect/sprite.h"
#include "effect/sprite_pool.h"
#include "main.h"
#include "system/frame.h"
#include "system/math.h"
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *CAlloc(int count, int size);
void Free(void *mem);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
Float ghUnitVector(NJS_VECTOR *vector, NJS_VECTOR *out);
Float CalcDistance2(NJS_POINT3 *from, NJS_POINT3 *to);
Uint32 ghBlendColors(Uint32 color, Uint32 by);

/* a channel from 0 to 1 as a byte of a packed ARGB color */
/* @hack type: the channel converted through int, which SHC does with FTRC
 * and STS alone (0x8c053866, 0x8c05386c); cast straight to Uint32,
 * sprite_render runs 160 bytes long, count unmeasured */
#define COLOR_BYTE(part) ((Uint32)(int)((part) * 255.0F))

#define TEXTURE(texlist, frame)                                                \
    ((NJS_TEXMEMLIST *)(texlist)->textures[(frame)->texture].texaddr)
void sprite_play_seek(struct sprite_play *play,
                      const struct sprite_frame *frames, Float age)
{
    const struct sprite_frame *frame;
    const struct sprite_frame *last;
    int index;

    last = frames;
    frame = frames + 1;
    index = 0;
    play->age = age;
    for (;;) {
        if (frame->texture < 0) {
            index = 0;
            age -= last->age;
            last = frames;
            frame = frames;
        } else {
            if (frame->age > age) {
                break;
            }
            index++;
            last = frame;
        }
        frame++;
    }
    play->frame = index;
}

/* the texture of frame, as texlist has it loaded */

void sprite_bind(NJS_TEXLIST *texlist, const struct sprite_frame *frames,
                 int flags)
{
    struct sprite_frame *frame;

    frame = (struct sprite_frame *)frames;
    if (flags & SPRITE_LOAD) {
        NeonuLoadTexture(texlist);
    }
    while (frame->texture >= 0) {
        if (texlist->textures[frame->texture].texaddr != 0) {
            frame->index = TEXTURE(texlist, frame)->globalIndex;
            if (frame->flags & SPRITE_TEXTURE_SIZE) {
                frame->width =
                    (Float)TEXTURE(texlist, frame)->texinfo.texsurface.nWidth;
                frame->height =
                    (Float)TEXTURE(texlist, frame)->texinfo.texsurface.nHeight;
            }
            if (frame->flags & SPRITE_CENTERED) {
                frame->center_x = frame->width * 0.5F;
                frame->center_y = frame->height * 0.5F;
            }
        }
        frame++;
    }
}

void sprite_play_init(struct sprite_play *play)
{
    play->age = 0.0F;
    play->rate = 1.0F;
    play->frame = 0;
    play->loops = 0;
}

void sprite_set(struct sprite *sprite, NJS_POINT3 *pos,
                struct sprite_desc *desc, int flags)
{
    sprite->step = desc->step;
    sprite_body_init(&sprite->body, pos, &desc->speed);
    if (flags & SPRITE_MOVES) {
        sprite->pos = &sprite->body.pos;
    } else {
        sprite->pos = pos;
    }
    sprite->body.scale = desc->scale;
    sprite->body.depth = desc->depth;
    sprite->motion.drag = desc->drag;
    sprite->motion.gravity = desc->gravity;
    sprite->frames = desc->frames;
    sprite_play_init(&sprite->play);
    sprite->play.rate = desc->rate;
}

int sprite_play_step(struct sprite_play *play,
                     const struct sprite_frame *frames)
{
    const struct sprite_frame *frame;
    const struct sprite_frame *next;

    next = &frames[play->frame + 1];
    if (next->texture >= 0) {
        play->age += play->rate;
        if (play->age >= next->age) {
            frame = next++;
            switch (next->texture) {
            case (-1):
                play->age = frame->age;
                return (-1);
            case (-2):
                play->loops++;
                if (play->loops < next->index) {
                    play->age -= frame->age;
                    play->frame = 0;
                    return SPRITE_LOOP;
                }
                play->age = frame->age;
                return SPRITE_END;
            default:
                break;
            }
            play->frame++;
        }
        return 0;
    }
    return SPRITE_END;
}

int sprite_step(struct sprite *sprite)
{
    int result;

    if (sprite->step != NULL) {
        result = sprite->step(sprite);
    } else {
        sprite_body_move(&sprite->body, &sprite->motion);
        result = sprite_play_step(&sprite->play, sprite->frames);
    }
    return result;
}

void sprite_render(NJS_POINT3 *pos, struct sprite_body *body,
                   struct sprite_play *play, const struct sprite_frame *frames)
{
    const struct sprite_frame *frame;
    const struct sprite_frame *next;
    NJS_POINT3 view;
    NJS_POINT3 screen;
    NJS_POINT3 size;
    NJS_POINT3 center;
    NJS_TEXTURE_VTX quad[4];
    NJS_POINT3 screen_size;
    NJS_POINT3 screen_center;
    Uint32 color;
    Float scale;
    Float blend;
    Float alpha;
    Float red;
    Float green;
    Float blue;

    frame = frames + play->frame;
    next = frame + 1;
    if (!loop_count) {
        njCalcPoint(NULL, pos, &view);
        if (_nj_near_clip_ > view.z + body->depth) {
            return;
        }
        point_project_centered(&view, &screen);
        if (frame->flags & SPRITE_ADDITIVE) {
            njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                                   NJD_COLOR_BLENDING_SRCALPHA);
            njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                                   NJD_COLOR_BLENDING_ONE);
        } else {
            njColorBlendingMode_jp(NJD_SOURCE_COLOR,
                                   NJD_COLOR_BLENDING_BOTHSRCALPHA);
        }
        /* the frame draws unblended at its own age, or when the next frame
         * has another texture */
        if (play->age == frame->age || frame->texture != next->texture) {
            scale = body->scale;
            size.x = frame->width * scale;
            size.y = frame->height * scale;
            center.x = frame->center_x * scale;
            center.y = frame->center_y * scale;
            color = COLOR_BYTE(frame->color.a) << 24 |
                    COLOR_BYTE(frame->color.r) << 16 |
                    COLOR_BYTE(frame->color.g) << 8 |
                    COLOR_BYTE(frame->color.b);
        } else {
            scale = body->scale;
            blend = (play->age - frame->age) / (next->age - frame->age);
            size.x = frame->width + (blend * (next->width - frame->width));
            size.y = frame->height + (blend * (next->height - frame->height));
            center.x =
                frame->center_x + (blend * (next->center_x - frame->center_x));
            center.y =
                frame->center_y + (blend * (next->center_y - frame->center_y));
            size.x *= scale;
            size.y *= scale;
            center.x *= scale;
            center.y *= scale;
            alpha = frame->color.a + (blend * (next->color.a - frame->color.a));
            red = frame->color.r + (blend * (next->color.r - frame->color.r));
            green = frame->color.g + (blend * (next->color.g - frame->color.g));
            blue = frame->color.b + (blend * (next->color.b - frame->color.b));
            color = COLOR_BYTE(alpha) << 24 | COLOR_BYTE(red) << 16 |
                    COLOR_BYTE(green) << 8 | COLOR_BYTE(blue);
        }
        /* the size and the center project as lengths at pos's view z,
         * without the body's depth */
        size.z = screen.z;
        center.z = screen.z;
        point_project_centered(&size, &screen_size);
        point_project_centered(&center, &screen_center);
        quad[0].u = quad[1].u = 0.0F;
        quad[2].u = quad[3].u = 1.0F;
        quad[0].v = quad[2].v = 0.0F;
        quad[1].v = quad[3].v = 1.0F;
        quad[0].col = quad[1].col = quad[2].col = quad[3].col = color;
        quad[0].z = quad[1].z = quad[2].z = quad[3].z =
            1.0F / (screen.z + body->depth);
        quad[0].x = quad[1].x = screen.x - screen_center.x + SCREEN_MIDDLE_X;
        quad[2].x = quad[3].x =
            screen.x - screen_center.x + screen_size.x + SCREEN_MIDDLE_X;
        quad[0].y = quad[2].y = screen.y - screen_center.y + SCREEN_MIDDLE_Y;
        quad[1].y = quad[3].y =
            screen.y - screen_center.y + screen_size.y + SCREEN_MIDDLE_Y;
        njDrawTexture(quad, 4, frame->index, TRUE);
    }
}

static void sprite_draw(struct sprite *sprite)
{
    sprite_render(sprite->pos, &sprite->body, &sprite->play, sprite->frames);
}

void sprite_draw_at(struct sprite *sprite, NJS_POINT3 *pos)
{
    sprite_render(pos, &sprite->body, &sprite->play, sprite->frames);
}

static void sprite_task_draw(struct task *task)
{
    struct sprite *sprite;

    sprite = task->extra;
    sprite_draw(sprite);
}

static void sprite_task_step(struct task *task)
{
    struct sprite *sprite;

    sprite = task->extra;
    sprite_task_draw(task);
    if (sprite_step(sprite) == SPRITE_END) {
        FreeTask(task);
    }
}

static void sprite_task_step_own(struct task *task)
{
    struct sprite *sprite;

    sprite = task->extra;
    sprite_task_draw(task);
    if (sprite->step(sprite) == SPRITE_END) {
        FreeTask(task);
    }
}

struct task *sprite_create(NJS_POINT3 *pos, struct sprite_desc *desc, int flags)
{
    struct task *task;
    struct sprite *sprite;

    if ((task = CreateElementalTask(TASK_WORK, 4, sprite_task_step)) != NULL) {
        sprite = MAlloc(sizeof(*sprite));
        if (sprite != NULL) {
            task->extra = sprite;
            sprite_set(sprite, pos, desc, flags);
            if (sprite->step != NULL) {
                task->step = sprite_task_step_own;
            }
            task->draw = sprite_task_draw;
        } else {
            DestroyTask(task);
            task = NULL;
        }
    }
    return task;
}
