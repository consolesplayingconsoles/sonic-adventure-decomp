/* @unit 0C9029C0-0C902C40 @data 0C908D80-0C908D98 +jpflags +pool32 */
/* Zero's banks, read into the memory past the module's end: EROBO.PB's
 * textures, and EROBO.NB's models and motions. each arm and action here
 * holds offsets into the model bank, which erobo_load turns into
 * pointers */
#include <ninja.h>
#include <sg_xpt.h>

#include "b_robo/banks.h"
#include "system/binary.h"
#include "system/loader.h"
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
Bool FUN_8c09f320(void *file);
struct pvb_texlist *FUN_8c09f45a(void *file);
void FUN_8c09f426(struct pvb_texlist *textures);

/* the end of the module's bss, from the table bounds.src makes */
#define BANK_ALIGN 32
extern Uint8 *eggmanrobo_bss_end;
extern struct njb_action beam_offsets;
extern struct njb_action wind_up_offsets;
extern struct njb_action throw_offsets;
extern struct njb_action throw_end_offsets;
extern struct njb_action hand_out_offsets;
extern struct njb_action hand_home_offsets;
extern struct njb_action hit_front_offsets;
extern struct njb_action hit_front_land_offsets;
extern struct njb_action hit_behind_offsets;
extern struct njb_action hit_behind_land_offsets;
extern struct njb_action turn_around_offsets;
extern struct njb_action leap_offsets;
extern struct njb_action leap_fall_offsets;
extern struct njb_action walk_offsets;
extern struct njb_action stand_offsets;
extern struct njb_action shocked_offsets;
extern struct njb_action knocked_down_offsets;
extern struct njb_action hurt_offsets;
extern struct njb_action get_up_offsets;
extern struct njb_action spin_offsets;
extern NJS_OBJECT arm0_template;
extern NJS_OBJECT arm1_template;
extern Uint8 *erobo_models;
extern NJS_TEXLIST *erobo_textures;
extern NJS_OBJECT erobo_arm0_object;
extern NJS_OBJECT erobo_arm1_object;
extern NJS_ACTION erobo_beam_action;
extern NJS_ACTION erobo_wind_up_action;
extern NJS_ACTION erobo_throw_action;
extern NJS_ACTION erobo_throw_end_action;
extern NJS_ACTION erobo_hand_out_action;
extern NJS_ACTION erobo_hand_home_action;
extern NJS_ACTION erobo_hit_front_action;
extern NJS_ACTION erobo_hit_front_land_action;
extern NJS_ACTION erobo_hit_behind_action;
extern NJS_ACTION erobo_hit_behind_land_action;
extern NJS_ACTION erobo_turn_around_action;
extern NJS_ACTION erobo_leap_action;
extern NJS_ACTION erobo_leap_fall_action;
extern NJS_ACTION erobo_walk_action;
extern NJS_ACTION erobo_stand_action;
extern NJS_ACTION erobo_shocked_action;
extern NJS_ACTION erobo_knocked_down_action;
extern NJS_ACTION erobo_hurt_action;
extern NJS_ACTION erobo_get_up_action;
extern NJS_ACTION erobo_spin_action;

/* point action at the object and the motion that offsets gives in the
 * model bank */
void rebase_action(struct njb_action *offsets, NJS_ACTION *action)
{
    action->object = (NJS_OBJECT *)(erobo_models + offsets->object);
    action->motion = (NJS_MOTION *)(erobo_models + offsets->motion);
}

void erobo_load(void)
{
    Uint8 *memory = (Uint8 *)(((Uint32)eggmanrobo_bss_end + BANK_ALIGN - 1) &
                              ~(BANK_ALIGN - 1));

    /* pvb_load loads the textures out of the texture bank, and the model
     * bank is then read over it */
    thunk_FUN_8c09cbc0("EROBO.PB", memory);
    erobo_textures = (NJS_TEXLIST *)FUN_8c09f45a(memory);
    erobo_models = memory;
    thunk_FUN_8c09cbc0("EROBO.NB", memory);
    FUN_8c09f320(erobo_models);
    rebase_action(&beam_offsets, &erobo_beam_action);
    rebase_action(&wind_up_offsets, &erobo_wind_up_action);
    rebase_action(&throw_offsets, &erobo_throw_action);
    rebase_action(&throw_end_offsets, &erobo_throw_end_action);
    rebase_action(&hand_out_offsets, &erobo_hand_out_action);
    rebase_action(&hand_home_offsets, &erobo_hand_home_action);
    rebase_action(&hit_front_offsets, &erobo_hit_front_action);
    rebase_action(&hit_front_land_offsets, &erobo_hit_front_land_action);
    rebase_action(&hit_behind_offsets, &erobo_hit_behind_action);
    rebase_action(&hit_behind_land_offsets, &erobo_hit_behind_land_action);
    rebase_action(&turn_around_offsets, &erobo_turn_around_action);
    rebase_action(&leap_offsets, &erobo_leap_action);
    rebase_action(&leap_fall_offsets, &erobo_leap_fall_action);
    rebase_action(&walk_offsets, &erobo_walk_action);
    rebase_action(&stand_offsets, &erobo_stand_action);
    rebase_action(&shocked_offsets, &erobo_shocked_action);
    rebase_action(&knocked_down_offsets, &erobo_knocked_down_action);
    rebase_action(&hurt_offsets, &erobo_hurt_action);
    rebase_action(&get_up_offsets, &erobo_get_up_action);
    rebase_action(&spin_offsets, &erobo_spin_action);
    erobo_arm0_object = arm0_template;
    erobo_arm0_object.model =
        (NJS_MODEL *)(erobo_models + (Uint32)arm0_template.model);
    erobo_arm0_object.child =
        (NJS_OBJECT *)(erobo_models + (Uint32)arm0_template.child);
    erobo_arm1_object = arm1_template;
    erobo_arm1_object.model =
        (NJS_MODEL *)(erobo_models + (Uint32)arm1_template.model);
    erobo_arm1_object.child =
        (NJS_OBJECT *)(erobo_models + (Uint32)arm1_template.child);
}

void erobo_release(void)
{
    FUN_8c09f426((struct pvb_texlist *)erobo_textures);
    erobo_textures = NULL;
}
