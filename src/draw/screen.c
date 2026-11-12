/* @unit 8C07DE00-8C07F4A0 @data 8C155780-8C1557CC +r04 +egflags +pool32 +poolafter=ghDefaultBlendingMode,ghDrawPvrTexture,screen_quad_draw_matrix,screen_blend,screen_cover_set_color,FUN_8c07f15c +poolbra=ghDrawPvrTexture:11 +poolbra=ghDrawPvrTexture:19 +poolbra=ghDrawPvrTextureWH:8 +poolbra=ghDrawPvrTextureS:11 +poolbra=ghDrawPvrTextureS:17 +poolbra=screen_viewer_step:3 */
/* textures drawn flat on the screen through one quad, and the pictures,
 * boxes and bands built on it. also a cover over the whole screen and a
 * texture viewer */
#define TEXT_1 ""
#define TEXT_2 ""
#include <ninja.h>
#include <sg_xpt.h>
#include <shinobi.h>

#include "draw/model.h"
#include "draw/screen.h"
#include "main.h"
#include "system/bitmap.h"
#include "system/math.h"
#include "system/pad.h"
#include "system/task.h"
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal_jp, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal_jp, Int reverse);
void text_set_size(Uint16 size);
void nwEditWinPrintf(Int loc, const char *fmt, ...);
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
void pdExecPeripheralServerUser(void);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void FUN_8c07eaa0(const struct screen_parts *picture, Float x, Float y,
                  Float z);
void FUN_8c07f020(Bool manager_data);
void FUN_8c07f15c(void);
void main_jp(void);
void SetPlayerNumberForGame(void);
void Draw_Reset(void);
Float ghUnitVector(NJS_VECTOR *vector, NJS_VECTOR *out);
Float CalcDistance2(NJS_POINT3 *from, NJS_POINT3 *to);
extern PDS_PERIPHERAL perG[8];
extern struct pad_stick input_dataG[8];
void ufExitSystem(void);
void PadReadOff(void);
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);

#define TEXT_1_LENGTH 9
#define TEXT_2_LENGTH 9

/* a texture surface's pixel format, in bits 27 to 29 of its PixelFormat,
 * numbered in screen_format_names' order. PIXEL_ARGB1555 and PIXEL_ARGB4444,
 * the two with alpha, draw translucent */
#define PIXEL_FORMAT(surface) ((surface)->PixelFormat & 0x38000000)
#define PIXEL_FORMAT_SHIFT 27
#define PIXEL_ARGB1555 0x00000000
#define PIXEL_ARGB4444 0x10000000

/* an ARGB color's alpha byte, and opaque white */
#define COLOR_ALPHA 0xff000000
#define COLOR_WHITE 0xffffffff

/* screen_bitmap_draw draws at this share of a texture's width and height */
#define BITMAP_SCALE 0.66666F

/* screen_band_draw's green, opaque at the band's left edge and clear at its
 * right */
#define BAND_GREEN 0x00007014

/* screen_box_texlist's textures: a corner, and the fill for the rest. the
 * box's layout takes the corner texture to be BOX_CORNER_SIZE pixels a
 * side */
#define BOX_CORNER 0
#define BOX_FILL 1
#define BOX_CORNER_SIZE 16.0F

/* the texture viewer's state, in its work's vars. it draws at work->pos */
#define VARS(work) ((struct viewer_vars *)&(work)->vars)
struct viewer_vars {
    Uint8 player;
    Uint8 unk_01;
    Uint16 texture;
    Uint8 unk_04[4];
    NJS_TEXLIST *texlist;
};

static void screen_quad_flip(Uint32 flip);
static Uint32 ghGetColor2Color(int mode, Uint32 from, Uint32 to, Float share);
static void screen_viewer_step(struct task *task);
extern NJS_TEXTURE_VTX screen_corners[4];
extern Bool screen_translucent;
extern Uint32 PvrBaseColor;
extern Uint32 screen_cover_color;
extern Bool screen_cover_shown;
extern Float dat_8c7a13c8;
extern Bool dat_8c1d4df8;
extern const char *screen_format_names[7];
extern NJS_TEXNAME screen_box_textures[2];
extern NJS_TEXLIST screen_box_texlist;

void screen_quad_init(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        screen_corners[i].col = COLOR_WHITE;
    }
    screen_corners[0].u = 0.0F;
    screen_corners[0].v = 0.0F;
    screen_corners[1].u = 0.0F;
    screen_corners[1].v = 1.0F;
    screen_corners[2].u = 1.0F;
    screen_corners[2].v = 0.0F;
    screen_corners[3].u = 1.0F;
    screen_corners[3].v = 1.0F;
    PvrBaseColor = COLOR_WHITE;
    screen_translucent = FALSE;
    dat_8c1d4df8 = TRUE;
    screen_cover_color = 0;
    dat_8c7a13c8 = 1.0F;
    screen_cover_shown = FALSE;
}

Uint32 screen_quad_get_tint(void)
{
    return PvrBaseColor;
}

void ghSetPvrTexMaterial(Uint32 color)
{
    int i;
    Uint32 tinted = ghBlendColors(color, PvrBaseColor);

    for (i = 0; i < 4; i++) {
        screen_corners[i].col = tinted;
    }
    if ((tinted & COLOR_ALPHA) == COLOR_ALPHA) {
        screen_translucent = FALSE;
    } else {
        screen_translucent = TRUE;
    }
}

void ghSetPvrTexVertexColor(Uint32 corner0, Uint32 corner1, Uint32 corner2,
                            Uint32 corner3)
{
    corner0 = ghBlendColors(corner0, PvrBaseColor);
    corner1 = ghBlendColors(corner1, PvrBaseColor);
    corner2 = ghBlendColors(corner2, PvrBaseColor);
    corner3 = ghBlendColors(corner3, PvrBaseColor);
    screen_corners[0].col = corner0;
    screen_corners[1].col = corner1;
    screen_corners[2].col = corner2;
    screen_corners[3].col = corner3;
    if ((corner0 & corner1 & corner2 & corner3 & COLOR_ALPHA) == COLOR_ALPHA) {
        screen_translucent = FALSE;
    } else {
        screen_translucent = TRUE;
    }
}

Uint32 ghDefaultBlendingMode(Uint32 *colors)
{
    Uint32 first;

    if (colors != NULL) {
        colors[0] = first = screen_corners[0].col;
        colors[1] = screen_corners[1].col;
        colors[2] = screen_corners[2].col;
        colors[3] = screen_corners[3].col;
    } else {
        first = screen_corners[0].col;
    }
    return first;
}

void ghSetPvrTexBaseColor(Uint32 tint)
{
    int i;
    Uint32 alpha;

    PvrBaseColor = tint;
    alpha = COLOR_ALPHA;
    for (i = 0; i < 4; i++) {
        screen_corners[i].col = ghBlendColors(screen_corners[i].col, tint);
        alpha &= screen_corners[i].col;
    }
    if ((alpha & COLOR_ALPHA) == COLOR_ALPHA) {
        screen_translucent = FALSE;
    } else {
        screen_translucent = TRUE;
    }
}

void screen_quad_set_translucent(Bool translucent)
{
    screen_translucent = translucent;
}

void ghDrawPvrTexture(int texture, Float x, Float y, Float z)
{
    Uint32 flip = texture & QUAD_FLIP;
    Uint32 place = texture & QUAD_PLACE;
    NJS_TEXLIST *texlist;
    NJS_TEXMEMLIST *memory;
    NJS_TEXINFO *info;
    NJS_TEXSURFACE *surface;
    Float left;
    Float top;
    Float right;
    Float bottom;
    Float half_width;
    Float half_height;
    Float depth;
    Bool translucent;
    Uint32 format;

    texture &= QUAD_TEXTURE;
    texlist = _nj_current_texlist;
    memory = (NJS_TEXMEMLIST *)texlist->textures[texture].texaddr;
    /* @hack spelling: surface through info, which puts info, memory + 20, in R4
     * and surface, R4 + 4, in R14 (0x8c082aea to 0x8c082af0); as
     * &memory->texinfo.texsurface, SHC adds 24 at once, lays out the frame
     * otherwise, and 363 of 384 words differ */
    info = &memory->texinfo;
    surface = &info->texsurface;
    screen_quad_flip(flip);
    /* nWidth and nHeight are integers, so each half rounds down, and an odd
     * size loses a pixel */
    /* NOLINTBEGIN(bugprone-integer-division) */
    switch (place) {
    case QUAD_TOP_LEFT:
        left = x;
        top = y;
        right = x + surface->nWidth;
        bottom = y + surface->nHeight;
        break;
    case QUAD_TOP:
        half_width = surface->nWidth / 2;
        left = x - half_width;
        top = y;
        right = x + half_width;
        bottom = y + surface->nHeight;
        break;
    case QUAD_TOP_RIGHT:
        left = x - surface->nWidth;
        top = y;
        right = x;
        bottom = y + surface->nHeight;
        break;
    case QUAD_LEFT:
        half_height = surface->nHeight / 2;
        left = x;
        top = y - half_height;
        right = x + surface->nWidth;
        bottom = y + half_height;
        break;
    case QUAD_CENTERED:
        half_width = surface->nWidth / 2;
        half_height = surface->nHeight / 2;
        left = x - half_width;
        top = y - half_height;
        right = x + half_width;
        bottom = y + half_height;
        break;
    case QUAD_RIGHT:
        half_height = surface->nHeight / 2;
        left = x - surface->nWidth;
        top = y - half_height;
        right = x;
        bottom = y + half_height;
        break;
    case QUAD_BOTTOM_LEFT:
        left = x;
        top = y - surface->nHeight;
        right = x + surface->nWidth;
        bottom = y;
        break;
    case QUAD_BOTTOM:
        half_width = surface->nWidth / 2;
        left = x - half_width;
        top = y - surface->nHeight;
        right = x + half_width;
        bottom = y;
        break;
    case QUAD_BOTTOM_RIGHT:
        left = x - surface->nWidth;
        top = y - surface->nHeight;
        right = x;
        bottom = y;
        break;
#ifdef GCC
    default:
        /* repairs a place past QUAD_BOTTOM_RIGHT, where the image leaves the
         * corners unset: GCC's draws nothing */
        return;
#endif
    }
    /* NOLINTEND(bugprone-integer-division) */
    depth = 1.0F / z;
    screen_corners[0].x = left;
    screen_corners[0].y = top;
    screen_corners[0].z = depth;
    screen_corners[1].x = left;
    screen_corners[1].y = bottom;
    screen_corners[1].z = depth;
    screen_corners[2].x = right;
    screen_corners[2].y = top;
    screen_corners[2].z = depth;
    screen_corners[3].x = right;
    screen_corners[3].y = bottom;
    screen_corners[3].z = depth;
    translucent = screen_translucent;
    format = PIXEL_FORMAT(surface);
    if (format == PIXEL_ARGB1555 || format == PIXEL_ARGB4444) {
        translucent = TRUE;
    }
    njDrawTexture(screen_corners, 4, memory->globalIndex, translucent);
}

void ghDrawPvrTextureWH(int texture, Float x, Float y, Float z, Float width,
                        Float height)
{
    Uint32 flip = texture & QUAD_FLIP;
    Uint32 place = texture & QUAD_PLACE;
    NJS_TEXLIST *texlist;
    NJS_TEXMEMLIST *memory;
    NJS_TEXSURFACE *surface;
    Float left;
    Float top;
    Float right;
    Float bottom;
    Float half_width;
    Float half_height;
    Float depth;
    Bool translucent;
    Uint32 format;

    texture &= QUAD_TEXTURE;
    texlist = _nj_current_texlist;
    memory = (NJS_TEXMEMLIST *)texlist->textures[texture].texaddr;
    surface = &memory->texinfo.texsurface;
    screen_quad_flip(flip);
    switch (place) {
    case QUAD_TOP_LEFT:
        left = x;
        top = y;
        right = x + width;
        bottom = y + height;
        break;
    case QUAD_TOP:
        half_width = width * 0.5F;
        left = x - half_width;
        top = y;
        right = x + half_width;
        bottom = y + height;
        break;
    case QUAD_TOP_RIGHT:
        left = x - width;
        top = y;
        right = x;
        bottom = y + height;
        break;
    case QUAD_LEFT:
        half_height = height * 0.5F;
        left = x;
        top = y - half_height;
        right = x + width;
        bottom = y + half_height;
        break;
    case QUAD_CENTERED:
        half_width = width * 0.5F;
        half_height = height * 0.5F;
        left = x - half_width;
        top = y - half_height;
        right = x + half_width;
        bottom = y + half_height;
        break;
    case QUAD_RIGHT:
        half_height = height * 0.5F;
        left = x - width;
        top = y - half_height;
        right = x;
        bottom = y + half_height;
        break;
    case QUAD_BOTTOM_LEFT:
        left = x;
        top = y - height;
        right = x + width;
        bottom = y;
        break;
    case QUAD_BOTTOM:
        half_width = width * 0.5F;
        left = x - half_width;
        top = y - height;
        right = x + half_width;
        bottom = y;
        break;
    case QUAD_BOTTOM_RIGHT:
        left = x - width;
        top = y - height;
        right = x;
        bottom = y;
        break;
#ifdef GCC
    default:
        /* repairs a place past QUAD_BOTTOM_RIGHT, as screen_quad_draw's
         * default does */
        return;
#endif
    }
    depth = 1.0F / z;
    screen_corners[0].x = left;
    screen_corners[0].y = top;
    screen_corners[0].z = depth;
    screen_corners[1].x = left;
    screen_corners[1].y = bottom;
    screen_corners[1].z = depth;
    screen_corners[2].x = right;
    screen_corners[2].y = top;
    screen_corners[2].z = depth;
    screen_corners[3].x = right;
    screen_corners[3].y = bottom;
    screen_corners[3].z = depth;
    translucent = screen_translucent;
    format = PIXEL_FORMAT(surface);
    if (format == PIXEL_ARGB1555 || format == PIXEL_ARGB4444) {
        translucent = TRUE;
    }
    njDrawTexture(screen_corners, 4, memory->globalIndex, translucent);
}

void ghDrawPvrTextureS(int texture, Float x, Float y, Float z, Float scale_x,
                       Float scale_y)
{
    Uint32 flip = texture & QUAD_FLIP;
    Uint32 place = texture & QUAD_PLACE;
    NJS_TEXLIST *texlist;
    NJS_TEXMEMLIST *memory;
    NJS_TEXSURFACE *surface;
    Float left;
    Float top;
    Float right;
    Float bottom;
    Float half_width;
    Float half_height;
    Float depth;
    Bool translucent;
    Uint32 format;

    texture &= QUAD_TEXTURE;
    texlist = _nj_current_texlist;
    memory = (NJS_TEXMEMLIST *)texlist->textures[texture].texaddr;
    surface = &memory->texinfo.texsurface;
    screen_quad_flip(flip);
    /* nWidth and nHeight are integers, so each half rounds down, and an odd
     * size loses a pixel */
    /* NOLINTBEGIN(bugprone-integer-division) */
    switch (place) {
    case QUAD_TOP_LEFT:
        left = x;
        top = y;
        right = x + (surface->nWidth * scale_x);
        bottom = y + (surface->nHeight * scale_y);
        break;
    case QUAD_TOP:
        half_width = surface->nWidth / 2 * scale_x;
        left = x - half_width;
        top = y;
        right = x + half_width;
        bottom = y + (surface->nHeight * scale_y);
        break;
    case QUAD_TOP_RIGHT:
        left = x - (surface->nWidth * scale_x);
        top = y;
        right = x;
        bottom = y + (surface->nHeight * scale_y);
        break;
    case QUAD_LEFT:
        half_height = surface->nHeight / 2 * scale_y;
        left = x;
        top = y - half_height;
        right = x + (surface->nWidth * scale_x);
        bottom = y + half_height;
        break;
    case QUAD_CENTERED:
        half_width = surface->nWidth / 2 * scale_x;
        half_height = surface->nHeight / 2 * scale_y;
        left = x - half_width;
        top = y - half_height;
        right = x + half_width;
        bottom = y + half_height;
        break;
    case QUAD_RIGHT:
        half_height = surface->nHeight / 2 * scale_y;
        left = x - (surface->nWidth * scale_x);
        top = y - half_height;
        right = x;
        bottom = y + half_height;
        break;
    case QUAD_BOTTOM_LEFT:
        left = x;
        top = y - (surface->nHeight * scale_y);
        right = x + (surface->nWidth * scale_x);
        bottom = y;
        break;
    case QUAD_BOTTOM:
        half_width = surface->nWidth / 2 * scale_x;
        left = x - half_width;
        top = y - (surface->nHeight * scale_y);
        right = x + half_width;
        bottom = y;
        break;
    case QUAD_BOTTOM_RIGHT:
        left = x - (surface->nWidth * scale_x);
        top = y - (surface->nHeight * scale_y);
        right = x;
        bottom = y;
        break;
#ifdef GCC
    default:
        /* repairs a place past QUAD_BOTTOM_RIGHT, as screen_quad_draw's
         * default does */
        return;
#endif
    }
    /* NOLINTEND(bugprone-integer-division) */
    depth = 1.0F / z;
    screen_corners[0].x = left;
    screen_corners[0].y = top;
    screen_corners[0].z = depth;
    screen_corners[1].x = left;
    screen_corners[1].y = bottom;
    screen_corners[1].z = depth;
    screen_corners[2].x = right;
    screen_corners[2].y = top;
    screen_corners[2].z = depth;
    screen_corners[3].x = right;
    screen_corners[3].y = bottom;
    screen_corners[3].z = depth;
    translucent = screen_translucent;
    format = PIXEL_FORMAT(surface);
    if (format == PIXEL_ARGB1555 || format == PIXEL_ARGB4444) {
        translucent = TRUE;
    }
    njDrawTexture(screen_corners, 4, memory->globalIndex, translucent);
}

void screen_quad_draw_matrix(int texture, NJS_MATRIX *matrix)
{
    NJS_TEXLIST *texlist;
    NJS_TEXMEMLIST *memory;
    NJS_TEXSURFACE *surface;
    NJS_POINT3 point;
    Float width;
    Float height;
    Float depth;
    Bool translucent;
    Uint32 format;
    Uint32 index;

    texlist = _nj_current_texlist;
    memory = (NJS_TEXMEMLIST *)texlist->textures[texture].texaddr;
    index = memory->globalIndex;
    surface = &memory->texinfo.texsurface;
    width = surface->nWidth;
    height = surface->nHeight;
    njGetTranslation(matrix, &point);
    depth = 1.0F / point.z;
    point.x = point.y = point.z = 0.0F;
    point_calc_xy(NULL, &point, &screen_corners[0].x);
    screen_corners[0].z = depth;
    point.x = 0.0F;
    point.y = height;
    point_calc_xy(NULL, &point, &screen_corners[1].x);
    screen_corners[1].z = depth;
    point.x = width;
    point.y = 0.0F;
    point_calc_xy(NULL, &point, &screen_corners[2].x);
    screen_corners[2].z = depth;
    point.x = width;
    point.y = height;
    point_calc_xy(NULL, &point, &screen_corners[3].x);
    screen_corners[3].z = depth;
    translucent = screen_translucent;
    format = PIXEL_FORMAT(surface);
    if (format == PIXEL_ARGB1555 || format == PIXEL_ARGB4444) {
        translucent = TRUE;
    }
    njDrawTexture(screen_corners, 4, index, translucent);
}

void FUN_8c07eaa0(const struct screen_parts *picture, Float x, Float y, Float z)
{
    int i;
    const struct screen_part *part = picture->parts;

    for (i = 0; i < picture->count; i++) {
        ghDrawPvrTexture(part->texture, part->x + x, part->y + y, z);
        part++;
    }
}

static void screen_quad_flip(Uint32 flip)
{
    switch (flip) {
    case 0:
    default:
        screen_corners[0].u = 0.0F;
        screen_corners[0].v = 0.0F;
        screen_corners[1].u = 0.0F;
        screen_corners[1].v = 1.0F;
        screen_corners[2].u = 1.0F;
        screen_corners[2].v = 0.0F;
        screen_corners[3].u = 1.0F;
        screen_corners[3].v = 1.0F;
        break;
    case QUAD_FLIP_V:
        screen_corners[0].u = 0.0F;
        screen_corners[0].v = 1.0F;
        screen_corners[1].u = 0.0F;
        screen_corners[1].v = 0.0F;
        screen_corners[2].u = 1.0F;
        screen_corners[2].v = 1.0F;
        screen_corners[3].u = 1.0F;
        screen_corners[3].v = 0.0F;
        break;
    case QUAD_FLIP_U:
        screen_corners[0].u = 1.0F;
        screen_corners[0].v = 0.0F;
        screen_corners[1].u = 1.0F;
        screen_corners[1].v = 1.0F;
        screen_corners[2].u = 0.0F;
        screen_corners[2].v = 0.0F;
        screen_corners[3].u = 0.0F;
        screen_corners[3].v = 1.0F;
        break;
    case QUAD_FLIP_U | QUAD_FLIP_V:
        screen_corners[0].u = 1.0F;
        screen_corners[0].v = 1.0F;
        screen_corners[1].u = 1.0F;
        screen_corners[1].v = 0.0F;
        screen_corners[2].u = 0.0F;
        screen_corners[2].v = 1.0F;
        screen_corners[3].u = 0.0F;
        screen_corners[3].v = 0.0F;
        break;
    }
}

void screen_blend_alpha(void)
{
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
}

void screen_blend(int source, int destination)
{
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, source);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR, destination);
}

/* from mixed with to, channel by channel. share is to's weight, so a share
 * of 0 gives from and 1 gives to */
static Uint32 ghGetColor2Color(int mode, Uint32 from, Uint32 to, Float share)
{
    NJS_ARGB argb[3];
    Float rest;

    color_to_argb(from, &argb[0]);
    color_to_argb(to, &argb[1]);
    rest = 1.0F - share;
    /* @hack redundant: a switch on mode with only a default, which saves mode
     * to the frame and loads it into R0 (0x8c083736, 0x8c08375e), where MOV
     * #4,R0 overwrites it; without it, 57 of 63 words differ */
    switch (mode) {
    default:
        argb[2].a = (argb[0].a * rest) + (argb[1].a * share);
        argb[2].r = (argb[0].r * rest) + (argb[1].r * share);
        argb[2].g = (argb[0].g * rest) + (argb[1].g * share);
        argb[2].b = (argb[0].b * rest) + (argb[1].b * share);
        break;
    }
    return color_from_argb(&argb[2]);
}

struct task *screen_viewer_create(NJS_TEXLIST *texlist,
                                  struct screen_viewer_place *place)
{
    struct task *task = CreateElementalTask(TASK_WORK, 0, screen_viewer_step);
    struct task_work *work;

    if (task != NULL) {
        work = task->work;
        VARS(work)->texlist = texlist;
        if (place != NULL) {
            work->pos.x = place->x;
            work->pos.y = place->y;
            VARS(work)->player = place->player;
        } else {
            work->pos.x = 0.0F;
            work->pos.y = 0.0F;
            VARS(work)->player = 0;
        }
    }
    return task;
}

static void screen_viewer_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_TEXLIST *texlist;
    NJS_TEXMEMLIST *memory;
    NJS_TEXSURFACE *surface;
    int player;
    int texture;
    Uint32 index;
    Float width;
    Float height;
    Uint32 format;
    Uint32 flags;
    int location;

    player = VARS(work)->player;
    texture = VARS(work)->texture;
    texlist = VARS(work)->texlist;
    if (pad_press_repeat[player] & PDD_DGT_KL) {
        texture--;
        if (texture < 0) {
            texture = texlist->nbTexture - 1;
        }
    } else if (pad_press_repeat[player] & PDD_DGT_KR) {
        texture++;
        if ((Uint32)texture >= texlist->nbTexture) {
            texture = 0;
        }
    }
    VARS(work)->texture = texture;
    /* NOLINTNEXTLINE(clang-diagnostic-sometimes-uninitialized) */
    if (texlist != NULL) {
        screen_blend_alpha();
        njSetTexture_jp(texlist);
        ghSetPvrTexMaterial(COLOR_WHITE);
        ghDrawPvrTexture(texture, work->pos.x, work->pos.y, 1.0F);
        memory = (NJS_TEXMEMLIST *)texlist->textures[texture].texaddr;
    }
    /* @bug memory: with no texlist (BT/S at 0x8c083834), nothing sets
     * memory. its register, R4, still holds &pad_press_repeat[player] from
     * 0x8c08380a, and the reads from here on load through it (0x8c083870) */
#ifdef GCC
    /* repairs the unset memory the tag names: with no texlist the viewer
     * draws no texture, so GCC prints no texture's fields either */
    if (texlist == NULL) {
        return;
    }
#endif
    index = memory->globalIndex;
    surface = &memory->texinfo.texsurface;
    width = surface->nWidth;
    height = surface->nHeight;
    format = PIXEL_FORMAT(surface) >> PIXEL_FORMAT_SHIFT;
    flags = surface->fSurfaceFlags;
    location = (((int)(work->pos.x * 0.125F)) << 16 |
                ((int)((work->pos.y + height) * 0.125F)));
    text_set_size(8);
    nwEditWinPrintf(location++, "NO. %d",
                    ((struct viewer_vars *)&(work)->vars)->texture);
    nwEditWinPrintf(location++, "GINDEX : %08X(%d)", index, index);
    nwEditWinPrintf(location++, "SIZE   : %d x %d", (int)width, (int)height);
    nwEditWinPrintf(location++, "FORMAT : %s", screen_format_names[format]);
    nwEditWinPrintf(location, "SURFACE: %08X", flags);
    text_set_size(16);
}

void screen_texture_size(NJS_TEXLIST *texlist, int texture, Uint32 *width,
                         Uint32 *height)
{
    NJS_TEXMEMLIST *memory;
    NJS_TEXSURFACE *surface;

    if (texlist == NULL) {
        texlist = _nj_current_texlist;
    }
    memory = (NJS_TEXMEMLIST *)texlist->textures[texture].texaddr;
    surface = &memory->texinfo.texsurface;
    if (width != NULL) {
        *width = surface->nWidth;
    }
    if (height != NULL) {
        *height = surface->nHeight;
    }
}

Uint32 screen_texture_index(NJS_TEXLIST *texlist, int texture)
{
    NJS_TEXMEMLIST *memory;

    if (texlist == NULL) {
        texlist = _nj_current_texlist;
    }
    memory = (NJS_TEXMEMLIST *)texlist->textures[texture].texaddr;
    return memory->globalIndex;
}

void screen_bitmap_draw(struct bitmap *bitmap, Float z)
{
    NJS_TEXTURE_VTX corners[4];
    Float width;
    Float height;
    Float depth;

    if (bitmap != NULL && bitmap->texlist.textures != NULL &&
        bitmap->texlist.nbTexture != 0) {
        depth = 1.0F / z;
        width = bitmap->texture_width;
        height = bitmap->texture_height;
        width *= BITMAP_SCALE;
        height *= BITMAP_SCALE;
        corners[0].x = bitmap->x;
        corners[0].y = bitmap->y;
        corners[0].z = depth;
        corners[0].u = 0.0F;
        corners[0].v = 0.0F;
        corners[0].col = bitmap->text_color.color;
        corners[1].x = bitmap->x;
        corners[1].y = bitmap->y + height;
        corners[1].z = depth;
        corners[1].u = 0.0F;
        corners[1].v = 1.0F;
        corners[1].col = bitmap->text_color.color;
        corners[2].x = bitmap->x + width;
        corners[2].y = bitmap->y;
        corners[2].z = depth;
        corners[2].u = 1.0F;
        corners[2].v = 0.0F;
        corners[2].col = bitmap->text_color.color;
        corners[3].x = bitmap->x + width;
        corners[3].y = bitmap->y + height;
        corners[3].z = depth;
        corners[3].u = 1.0F;
        corners[3].v = 1.0F;
        corners[3].col = bitmap->text_color.color;
        njSetTexture_jp(&bitmap->texlist);
        njDrawTexture(corners, 4, bitmap->index, TRUE);
    }
}

void screen_cover_set_color(Uint32 color)
{
    screen_cover_color = color | COLOR_ALPHA;
}

void FUN_8c07f020(Bool manager_data)
{
    screen_cover_shown = manager_data;
}

void screen_cover_draw(Float alpha)
{
    NJS_POLYGON_VTX corners[4];
    Uint32 color;
    Float depth;

    if (!screen_cover_shown) {
        return;
    }
    color = (Uint32)(alpha * 255.0F);
    if (color > 0xff) {
        color = 0xff;
    }
    color = (color << 24) | 0xffffff;
    color = ghBlendColors(color, screen_cover_color);
    depth = 1.0F;
    corners[0].x = 0.0F;
    corners[0].y = 0.0F;
    corners[0].z = depth;
    corners[0].col = color;
    corners[1].x = 0.0F;
    corners[1].y = SCREEN_HEIGHT;
    corners[1].z = depth;
    corners[1].col = color;
    corners[2].x = SCREEN_WIDTH;
    corners[2].y = 0.0F;
    corners[2].z = depth;
    corners[2].col = color;
    corners[3].x = SCREEN_WIDTH;
    corners[3].y = SCREEN_HEIGHT;
    corners[3].z = depth;
    corners[3].col = color;
    njDrawPolygon(corners, 4, TRUE);
}

void screen_view_from_task(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VIEW view;

    njInitView(&view);
    njRotateViewZRelative(&view, work->ang.z);
    njRotateViewXRelative(&view, work->ang.x);
    njRotateViewYRelative(&view, work->ang.y);
    njTranslateViewRelative(&view, work->pos.x, work->pos.y, work->pos.z);
    njSetView(&view);
}

void screen_palette_grays(int palette)
{
    int i;
    Uint32 level = 0xff;
    Uint32 color;

    for (i = 0; i < DRAW_PALETTE_ENTRIES; i++) {
        color = (level << 16) | (level << 8) | level | COLOR_ALPHA;
        draw_palettes[palette][i * 2] = color;
        level--;
    }
}

void FUN_8c07f15c(void)
{
    int i;

    for (i = 0; i < DRAW_PALETTES; i++) {
        screen_palette_grays(i);
    }
}

void DrawShadowWindow(Float x, Float y, Float z, Float width, Float height)
{
    Uint32 colors[4];
    /* the colors at the top, a corner's size down, a corner's size up from
     * the bottom, and at the bottom */
    Uint32 shades[4];

    ghDefaultBlendingMode(colors);
    njTextureClampMode_jp(NJD_TEXTURECLAMP_CLAMP_UV);
    njSetTexture_jp(&screen_box_texlist);
    /* this gray never shows: screen_quad_colors below sets every corner's
     * color and the translucency again */
    ghSetPvrTexMaterial(0xc0808080);
    shades[0] = colors[0];
    shades[1] =
        ghGetColor2Color(0, colors[0], colors[1], BOX_CORNER_SIZE / height);
    shades[2] = ghGetColor2Color(0, colors[0], colors[1],
                                 (height - BOX_CORNER_SIZE) / height);
    shades[3] = colors[1];
    ghSetPvrTexVertexColor(shades[0], shades[1], shades[0], shades[1]);
    ghDrawPvrTexture(BOX_CORNER | QUAD_TOP_LEFT, x, y, z);
    ghDrawPvrTexture(BOX_CORNER | QUAD_TOP_RIGHT | QUAD_FLIP_U, x + width, y,
                     z);
    ghSetPvrTexVertexColor(shades[2], shades[3], shades[2], shades[3]);
    ghDrawPvrTexture(BOX_CORNER | QUAD_BOTTOM_LEFT | QUAD_FLIP_V, x, y + height,
                     z);
    ghDrawPvrTexture(BOX_CORNER | QUAD_BOTTOM_RIGHT | QUAD_FLIP_U | QUAD_FLIP_V,
                     x + width, y + height, z);
    ghSetPvrTexVertexColor(shades[1], shades[2], shades[1], shades[2]);
    ghDrawPvrTextureWH(BOX_FILL, x, y + BOX_CORNER_SIZE, z, BOX_CORNER_SIZE,
                       height - (2 * BOX_CORNER_SIZE));
    ghDrawPvrTextureWH(BOX_FILL, (x + width) - BOX_CORNER_SIZE,
                       y + BOX_CORNER_SIZE, z, BOX_CORNER_SIZE,
                       height - (2 * BOX_CORNER_SIZE));
    ghSetPvrTexVertexColor(shades[0], shades[3], shades[0], shades[3]);
    ghDrawPvrTextureWH(BOX_FILL, x + BOX_CORNER_SIZE, y, z,
                       width - (2 * BOX_CORNER_SIZE), height);
}

void DrawTitleBack(Float x, Float y, Float z, Float width, Float height)
{
    NJS_POLYGON_VTX corners[4];
    Uint32 colors[2];
    Float depth;

    colors[0] = ghBlendColors(BAND_GREEN | COLOR_ALPHA, screen_quad_get_tint());
    colors[1] = ghBlendColors(BAND_GREEN, screen_quad_get_tint());
    depth = 1.0F / z;
    corners[0].x = x;
    corners[0].y = y;
    corners[0].z = depth;
    corners[0].col = colors[0];
    corners[1].x = x;
    corners[1].y = y + height;
    corners[1].z = depth;
    corners[1].col = colors[0];
    corners[2].x = x + width;
    corners[2].y = y;
    corners[2].z = depth;
    corners[2].col = colors[1];
    corners[3].x = x + width;
    corners[3].y = y + height;
    corners[3].z = depth;
    corners[3].col = colors[1];
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCCOLOR);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVDESTCOLOR);
    njDrawPolygon(corners, 4, TRUE);
    njColorBlendingMode_jp(NJD_SOURCE_COLOR, NJD_COLOR_BLENDING_SRCALPHA);
    njColorBlendingMode_jp(NJD_DESTINATION_COLOR,
                           NJD_COLOR_BLENDING_INVSRCALPHA);
}
