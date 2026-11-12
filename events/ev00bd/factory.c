/* @unit 0CB80C60-0CB80E20 +jpflags +pool32 */
/* EV00BD.PRS's factory, drawn in three groups: eight parts, two pieces at
 * positions of their own and four machines that loop their actions. its
 * texture file, PVME101FACTORY, names it E-101's */
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "draw/tree.h"
#include "ev00bd/factory.h"
#include "ev00bd/factory_part_7_object.h"
#include "ev00bd/factory_textures.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);

#define FACTORY_PARTS 8
#define FACTORY_PIECES 2
#define FACTORY_MACHINES 4
extern NJS_OBJECT ev00bd_factory_part_0_object;
extern NJS_OBJECT ev00bd_factory_part_1_object;
extern NJS_OBJECT ev00bd_factory_part_2_object;
extern NJS_OBJECT ev00bd_factory_part_3_object;
extern NJS_OBJECT ev00bd_factory_part_4_object;
extern NJS_OBJECT ev00bd_factory_part_5_object;
extern NJS_OBJECT ev00bd_factory_part_6_object;
extern NJS_OBJECT ev00bd_factory_piece_0_object;
extern NJS_OBJECT ev00bd_factory_piece_1_object;
extern NJS_ACTION ev00bd_factory_machine_0_action;
extern NJS_ACTION ev00bd_factory_machine_1_action;
extern NJS_ACTION ev00bd_factory_machine_2_action;
extern NJS_ACTION ev00bd_factory_machine_3_action;

struct factory_piece {
    NJS_OBJECT *object;
    NJS_POINT3 pos;
};

struct factory_machine {
    NJS_ACTION *action;
    Float frame;
    Float speed; /* motion frames per step */
};
extern NJS_OBJECT *ev00bd_factory_parts[8];
extern struct factory_piece ev00bd_factory_pieces[2];
extern struct factory_machine ev00bd_factory_machines[4];

void draw_e101factory(void)
{
    /* @hack type: i unsigned, which SHC tests with CMP/HS (0x0cb80ba8,
     * 0x0cb80bf4, 0x0cb80cdc); as an int, it tests with CMP/GE and 3 of 189
     * words differ */
    Uint32 i;
    NJS_OBJECT **part;
    struct factory_piece *piece;
    struct factory_machine *machine;

    njSetTexture_jp(&ev00bd_factory_texlist);
    for (part = ev00bd_factory_parts, i = 0; i < FACTORY_PARTS; i++, part++) {
        late_DrawObject(*part);
    }
    for (piece = ev00bd_factory_pieces, i = 0; i < FACTORY_PIECES;
         i++, piece++) {
        njPushMatrix(NULL);
        njTranslate(NULL, piece->pos.x, piece->pos.y, piece->pos.z);
        late_DrawObject(piece->object);
        late_DrawObjectClipEx(1);
    }
    for (machine = ev00bd_factory_machines, i = 0; i < FACTORY_MACHINES;
         i++, machine++) {
        ds_ActionClip(machine->action, machine->frame);
        machine->frame += machine->speed;
        if (machine->frame >= machine->action->motion->nbFrame) {
            machine->frame = 0.0F;
        }
    }
}
