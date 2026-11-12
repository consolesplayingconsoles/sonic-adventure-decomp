/* @unit 0CB85F40-0CB861C0 +r04 +egflags +pool32 */
/* EV0030.PRS's plane: Tails' new plane, with Tails in it */
#define TEXT_1 ""
#define TEXT_5 ""
#define TEXT_2 ""
#define TEXT_6 ""
#define TEXT_3 ""
#define TEXT_34 ""
#define TEXT_4 ""
#define TEXT_35 ""
#define TEXT_7 ""
#define TEXT_36 ""
#define TEXT_8 ""
#define TEXT_9 ""
#define TEXT_10 ""
#define TEXT_11 ""
#define TEXT_12 ""
#define TEXT_13 ""
#define TEXT_14 ""
#define TEXT_15 ""
#define TEXT_16 ""
#define TEXT_17 ""
#define TEXT_18 ""
#define TEXT_19 ""
#define TEXT_20 ""
#define TEXT_21 ""
#define TEXT_22 ""
#define TEXT_23 ""
#define TEXT_24 ""
#define TEXT_25 ""
#define TEXT_26 ""
#define TEXT_27 ""
#define TEXT_28 ""
#define TEXT_29 ""
#define TEXT_30 ""
#define TEXT_31 ""
#define TEXT_32 ""
#define TEXT_33 ""
#include <ninja.h>
#include <sg_xpt.h>

#include "draw/draw.h"
#include "draw/model.h"
#include "draw/pose.h"
#include "ev0030/plane.h"
#include "event/event.h"
#include "event/play.h"
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
void ds_ActionClip(NJS_ACTION *action, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void DrawLine(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void ModelTurnWhite(struct task_work *work, Sint16 characters);
void ds_DrawModelClip(NJS_MODEL *model);
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
Bool GetMMMatrix(Uint32 node, NJS_MATRIX *out);
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                             struct task *parent);
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void ExecEventFace(struct task_work *work);
struct task *CreateEventObject(void);
void EventObject(struct task *task);
void EV_Load2(int number);
void EV_Exec2(void);
Bool EV_CheckCansel(void);
Bool EV_CheckExec(int number);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z, Angle ang_x,
                     Angle ang_y, Angle ang_z);
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

#define TEXT_1_LENGTH 11
#define TEXT_2_LENGTH 8
#define TEXT_3_LENGTH 8
#define TEXT_4_LENGTH 13
#define TEXT_5_LENGTH 9
#define TEXT_6_LENGTH 11
#define TEXT_7_LENGTH 9
#define TEXT_8_LENGTH 8
#define TEXT_9_LENGTH 11
#define TEXT_10_LENGTH 11
#define TEXT_11_LENGTH 11
#define TEXT_12_LENGTH 11
#define TEXT_13_LENGTH 11
#define TEXT_14_LENGTH 11
#define TEXT_15_LENGTH 11
#define TEXT_16_LENGTH 10
#define TEXT_17_LENGTH 11
#define TEXT_18_LENGTH 10
#define TEXT_19_LENGTH 10
#define TEXT_20_LENGTH 12
#define TEXT_21_LENGTH 11
#define TEXT_22_LENGTH 11
#define TEXT_23_LENGTH 11
#define TEXT_24_LENGTH 11
#define TEXT_25_LENGTH 12
#define TEXT_26_LENGTH 11
#define TEXT_27_LENGTH 9
#define TEXT_28_LENGTH 10
#define TEXT_29_LENGTH 11
#define TEXT_30_LENGTH 12
#define TEXT_31_LENGTH 11
#define TEXT_32_LENGTH 11
#define TEXT_33_LENGTH 10
#define TEXT_34_LENGTH 14
#define TEXT_35_LENGTH 14
#define TEXT_36_LENGTH 12

/* the node of ev0030_plane_object that Tails' head is drawn at */
#define PLANE_HEAD 12

/* an animation: the plane's action, and the motion and shape motion of Tails'
 * head. the head is a model of its own, drawn at PLANE_HEAD. all three play
 * at the plane's frame */
#define VARS(work) ((struct plane_vars *)&(work)->vars)
struct plane_anim {
    NJS_ACTION *action;
    NJS_MOTION *head_motion;
    NJS_MOTION *head_shape;
    Sint32 next; /* the animation that takes over at this one's last frame */
};

/* the plane's view of work->vars */
struct plane_vars {
    Float speed; /* the frames added to frame each step */
    Float frame;
    Sint32 anim; /* its animation, an index into ev0030_plane_anims */
};
extern NJS_TEXNAME ev0030_plane_textures[33];
extern NJS_TEXLIST ev0030_plane_texlist;
extern NJS_TEXNAME ev0030_head_textures[5];
extern NJS_TEXLIST ev0030_head_texlist;
extern NJS_OBJECT ev0030_plane_44;
extern NJS_MATERIAL ev0030_plane_43_materials[4];
extern Sint16 ev0030_plane_43_meshes0[28];
extern Sint16 ev0030_plane_43_meshes1[80];
extern Sint16 ev0030_plane_43_meshes2[5];
extern Sint16 ev0030_plane_43_meshes3[26];
extern NJS_COLOR ev0030_plane_43_uvs0[22];
extern NJS_COLOR ev0030_plane_43_uvs1[70];
extern NJS_COLOR ev0030_plane_43_uvs2[4];
extern NJS_COLOR ev0030_plane_43_uvs3[22];
extern NJS_MESHSET ev0030_plane_43_meshsets[4];
extern NJS_POINT3 ev0030_plane_43_points[57];
extern NJS_VECTOR ev0030_plane_43_normals[57];
extern NJS_MODEL ev0030_plane_43_model;
extern NJS_OBJECT ev0030_plane_43;
extern NJS_OBJECT ev0030_plane_42;
extern NJS_OBJECT ev0030_plane_41;
extern NJS_OBJECT ev0030_plane_40;
extern NJS_OBJECT ev0030_plane_39;
extern NJS_OBJECT ev0030_plane_38;
extern NJS_OBJECT ev0030_plane_37;
extern NJS_MATERIAL ev0030_plane_36_materials[1];
extern Sint16 ev0030_plane_36_meshes0[16];
extern NJS_COLOR ev0030_plane_36_uvs0[14];
extern NJS_MESHSET ev0030_plane_36_meshsets[1];
extern NJS_POINT3 ev0030_plane_36_points[8];
extern NJS_VECTOR ev0030_plane_36_normals[8];
extern NJS_MODEL ev0030_plane_36_model;
extern NJS_OBJECT ev0030_plane_36;
extern NJS_MATERIAL ev0030_plane_35_materials[1];
extern Sint16 ev0030_plane_35_meshes0[11];
extern NJS_COLOR ev0030_plane_35_uvs0[10];
extern NJS_MESHSET ev0030_plane_35_meshsets[1];
extern NJS_POINT3 ev0030_plane_35_points[8];
extern NJS_VECTOR ev0030_plane_35_normals[8];
extern NJS_MODEL ev0030_plane_35_model;
extern NJS_OBJECT ev0030_plane_35;
extern NJS_MATERIAL ev0030_plane_34_materials[1];
extern Sint16 ev0030_plane_34_meshes0[35];
extern NJS_COLOR ev0030_plane_34_uvs0[30];
extern NJS_MESHSET ev0030_plane_34_meshsets[1];
extern NJS_POINT3 ev0030_plane_34_points[12];
extern NJS_VECTOR ev0030_plane_34_normals[12];
extern NJS_MODEL ev0030_plane_34_model;
extern NJS_OBJECT ev0030_plane_34;
extern NJS_MATERIAL ev0030_plane_33_materials[3];
extern Sint16 ev0030_plane_33_meshes0[20];
extern Sint16 ev0030_plane_33_meshes1[16];
extern Sint16 ev0030_plane_33_meshes2[11];
extern NJS_COLOR ev0030_plane_33_uvs0[16];
extern NJS_COLOR ev0030_plane_33_uvs1[14];
extern NJS_COLOR ev0030_plane_33_uvs2[10];
extern NJS_MESHSET ev0030_plane_33_meshsets[3];
extern NJS_POINT3 ev0030_plane_33_points[16];
extern NJS_VECTOR ev0030_plane_33_normals[16];
extern NJS_MODEL ev0030_plane_33_model;
extern NJS_OBJECT ev0030_plane_33;
extern NJS_MATERIAL ev0030_plane_32_materials[2];
extern Sint16 ev0030_plane_32_meshes0[19];
extern Sint16 ev0030_plane_32_meshes1[5];
extern NJS_COLOR ev0030_plane_32_uvs0[16];
extern NJS_COLOR ev0030_plane_32_uvs1[4];
extern NJS_MESHSET ev0030_plane_32_meshsets[2];
extern NJS_POINT3 ev0030_plane_32_points[9];
extern NJS_VECTOR ev0030_plane_32_normals[9];
extern NJS_MODEL ev0030_plane_32_model;
extern NJS_OBJECT ev0030_plane_32;
extern NJS_MATERIAL ev0030_plane_31_materials[3];
extern Sint16 ev0030_plane_31_meshes0[28];
extern Sint16 ev0030_plane_31_meshes1[6];
extern Sint16 ev0030_plane_31_meshes2[11];
extern NJS_COLOR ev0030_plane_31_uvs0[23];
extern NJS_COLOR ev0030_plane_31_uvs1[5];
extern NJS_COLOR ev0030_plane_31_uvs2[10];
extern NJS_MESHSET ev0030_plane_31_meshsets[3];
extern NJS_POINT3 ev0030_plane_31_points[18];
extern NJS_VECTOR ev0030_plane_31_normals[18];
extern NJS_MODEL ev0030_plane_31_model;
extern NJS_OBJECT ev0030_plane_31;
extern NJS_OBJECT ev0030_plane_30;
extern NJS_OBJECT ev0030_plane_29;
extern NJS_OBJECT ev0030_plane_28;
extern NJS_OBJECT ev0030_plane_27;
extern NJS_OBJECT ev0030_plane_26;
extern NJS_MATERIAL ev0030_plane_25_materials[1];
extern Sint16 ev0030_plane_25_meshes0[19];
extern NJS_COLOR ev0030_plane_25_uvs0[16];
extern NJS_MESHSET ev0030_plane_25_meshsets[1];
extern NJS_POINT3 ev0030_plane_25_points[8];
extern NJS_VECTOR ev0030_plane_25_normals[8];
extern NJS_MODEL ev0030_plane_25_model;
extern NJS_OBJECT ev0030_plane_25;
extern NJS_MATERIAL ev0030_plane_24_materials[1];
extern Sint16 ev0030_plane_24_meshes0[11];
extern NJS_COLOR ev0030_plane_24_uvs0[10];
extern NJS_MESHSET ev0030_plane_24_meshsets[1];
extern NJS_POINT3 ev0030_plane_24_points[8];
extern NJS_VECTOR ev0030_plane_24_normals[8];
extern NJS_MODEL ev0030_plane_24_model;
extern NJS_OBJECT ev0030_plane_24;
extern NJS_MATERIAL ev0030_plane_23_materials[1];
extern Sint16 ev0030_plane_23_meshes0[35];
extern NJS_COLOR ev0030_plane_23_uvs0[30];
extern NJS_MESHSET ev0030_plane_23_meshsets[1];
extern NJS_POINT3 ev0030_plane_23_points[12];
extern NJS_VECTOR ev0030_plane_23_normals[12];
extern NJS_MODEL ev0030_plane_23_model;
extern NJS_OBJECT ev0030_plane_23;
extern NJS_MATERIAL ev0030_plane_22_materials[3];
extern Sint16 ev0030_plane_22_meshes0[20];
extern Sint16 ev0030_plane_22_meshes1[16];
extern Sint16 ev0030_plane_22_meshes2[11];
extern NJS_COLOR ev0030_plane_22_uvs0[16];
extern NJS_COLOR ev0030_plane_22_uvs1[14];
extern NJS_COLOR ev0030_plane_22_uvs2[10];
extern NJS_MESHSET ev0030_plane_22_meshsets[3];
extern NJS_POINT3 ev0030_plane_22_points[16];
extern NJS_VECTOR ev0030_plane_22_normals[16];
extern NJS_MODEL ev0030_plane_22_model;
extern NJS_OBJECT ev0030_plane_22;
extern NJS_MATERIAL ev0030_plane_21_materials[2];
extern Sint16 ev0030_plane_21_meshes0[19];
extern Sint16 ev0030_plane_21_meshes1[5];
extern NJS_COLOR ev0030_plane_21_uvs0[16];
extern NJS_COLOR ev0030_plane_21_uvs1[4];
extern NJS_MESHSET ev0030_plane_21_meshsets[2];
extern NJS_POINT3 ev0030_plane_21_points[9];
extern NJS_VECTOR ev0030_plane_21_normals[9];
extern NJS_MODEL ev0030_plane_21_model;
extern NJS_OBJECT ev0030_plane_21;
extern NJS_MATERIAL ev0030_plane_20_materials[3];
extern Sint16 ev0030_plane_20_meshes0[28];
extern Sint16 ev0030_plane_20_meshes1[6];
extern Sint16 ev0030_plane_20_meshes2[11];
extern NJS_COLOR ev0030_plane_20_uvs0[23];
extern NJS_COLOR ev0030_plane_20_uvs1[5];
extern NJS_COLOR ev0030_plane_20_uvs2[10];
extern NJS_MESHSET ev0030_plane_20_meshsets[3];
extern NJS_POINT3 ev0030_plane_20_points[18];
extern NJS_VECTOR ev0030_plane_20_normals[18];
extern NJS_MODEL ev0030_plane_20_model;
extern NJS_OBJECT ev0030_plane_20;
extern NJS_OBJECT ev0030_plane_19;
extern NJS_OBJECT ev0030_plane_18;
extern NJS_OBJECT ev0030_plane_17;
extern NJS_OBJECT ev0030_plane_16;
extern NJS_OBJECT ev0030_plane_15;
extern NJS_MATERIAL ev0030_plane_14_materials[1];
extern Sint16 ev0030_plane_14_meshes0[9];
extern NJS_COLOR ev0030_plane_14_uvs0[8];
extern NJS_MESHSET ev0030_plane_14_meshsets[1];
extern NJS_POINT3 ev0030_plane_14_points[8];
extern NJS_VECTOR ev0030_plane_14_normals[8];
extern NJS_MODEL ev0030_plane_14_model;
extern NJS_OBJECT ev0030_plane_14;
extern NJS_MATERIAL ev0030_plane_13_materials[1];
extern Sint16 ev0030_plane_13_meshes0[9];
extern NJS_COLOR ev0030_plane_13_uvs0[8];
extern NJS_MESHSET ev0030_plane_13_meshsets[1];
extern NJS_POINT3 ev0030_plane_13_points[8];
extern NJS_VECTOR ev0030_plane_13_normals[8];
extern NJS_MODEL ev0030_plane_13_model;
extern NJS_OBJECT ev0030_plane_13;
extern NJS_OBJECT ev0030_plane_12;
extern NJS_OBJECT ev0030_plane_11;
extern NJS_OBJECT ev0030_plane_10;
extern NJS_OBJECT ev0030_plane_9;
extern NJS_OBJECT ev0030_plane_8;
extern NJS_OBJECT ev0030_plane_7;
extern NJS_OBJECT ev0030_plane_6;
extern NJS_OBJECT ev0030_plane_5;
extern NJS_MATERIAL ev0030_plane_4_materials[4];
extern Sint16 ev0030_plane_4_meshes0[40];
extern Sint16 ev0030_plane_4_meshes1[32];
extern Sint16 ev0030_plane_4_meshes2[39];
extern Sint16 ev0030_plane_4_meshes3[12];
extern NJS_COLOR ev0030_plane_4_uvs0[31];
extern NJS_COLOR ev0030_plane_4_uvs1[25];
extern NJS_COLOR ev0030_plane_4_uvs2[34];
extern NJS_COLOR ev0030_plane_4_uvs3[9];
extern NJS_MESHSET ev0030_plane_4_meshsets[4];
extern NJS_POINT3 ev0030_plane_4_points[41];
extern NJS_VECTOR ev0030_plane_4_normals[41];
extern NJS_MODEL ev0030_plane_4_model;
extern NJS_OBJECT ev0030_plane_4;
extern NJS_MATERIAL ev0030_plane_3_materials[2];
extern Sint16 ev0030_plane_3_meshes0[93];
extern Sint16 ev0030_plane_3_meshes1[36];
extern NJS_COLOR ev0030_plane_3_uvs0[78];
extern NJS_COLOR ev0030_plane_3_uvs1[32];
extern NJS_MESHSET ev0030_plane_3_meshsets[2];
extern NJS_POINT3 ev0030_plane_3_points[44];
extern NJS_VECTOR ev0030_plane_3_normals[44];
extern NJS_MODEL ev0030_plane_3_model;
extern NJS_OBJECT ev0030_plane_3;
extern NJS_MATERIAL ev0030_plane_2_materials[18];
extern Sint16 ev0030_plane_2_meshes0[9];
extern Sint16 ev0030_plane_2_meshes1[201];
extern Sint16 ev0030_plane_2_meshes2[15];
extern Sint16 ev0030_plane_2_meshes3[6];
extern Sint16 ev0030_plane_2_meshes4[83];
extern Sint16 ev0030_plane_2_meshes5[16];
extern Sint16 ev0030_plane_2_meshes6[12];
extern Sint16 ev0030_plane_2_meshes7[15];
extern Sint16 ev0030_plane_2_meshes8[28];
extern Sint16 ev0030_plane_2_meshes9[11];
extern Sint16 ev0030_plane_2_meshes10[32];
extern Sint16 ev0030_plane_2_meshes11[28];
extern Sint16 ev0030_plane_2_meshes12[92];
extern Sint16 ev0030_plane_2_meshes13[30];
extern Sint16 ev0030_plane_2_meshes14[10];
extern Sint16 ev0030_plane_2_meshes15[10];
extern Sint16 ev0030_plane_2_meshes16[5];
extern Sint16 ev0030_plane_2_meshes17[87];
extern NJS_COLOR ev0030_plane_2_uvs0[8];
extern NJS_COLOR ev0030_plane_2_uvs1[178];
extern NJS_COLOR ev0030_plane_2_uvs2[13];
extern NJS_COLOR ev0030_plane_2_uvs3[5];
extern NJS_COLOR ev0030_plane_2_uvs4[68];
extern NJS_COLOR ev0030_plane_2_uvs5[14];
extern NJS_COLOR ev0030_plane_2_uvs6[10];
extern NJS_COLOR ev0030_plane_2_uvs7[12];
extern NJS_COLOR ev0030_plane_2_uvs8[22];
extern NJS_COLOR ev0030_plane_2_uvs9[10];
extern NJS_COLOR ev0030_plane_2_uvs10[25];
extern NJS_COLOR ev0030_plane_2_uvs11[22];
extern NJS_COLOR ev0030_plane_2_uvs12[80];
extern NJS_COLOR ev0030_plane_2_uvs13[25];
extern NJS_COLOR ev0030_plane_2_uvs14[8];
extern NJS_COLOR ev0030_plane_2_uvs15[8];
extern NJS_COLOR ev0030_plane_2_uvs16[4];
extern NJS_COLOR ev0030_plane_2_uvs17[74];
extern NJS_MESHSET ev0030_plane_2_meshsets[18];
extern NJS_POINT3 ev0030_plane_2_points[211];
extern NJS_VECTOR ev0030_plane_2_normals[211];
extern NJS_MODEL ev0030_plane_2_model;
extern NJS_OBJECT ev0030_plane_2;
extern NJS_OBJECT ev0030_plane_1;
extern NJS_OBJECT ev0030_plane_object;
extern NJS_MATERIAL ev0030_head_materials[8];
extern Sint16 ev0030_head_meshes0[68];
extern Sint16 ev0030_head_meshes1[40];
extern Sint16 ev0030_head_meshes2[18];
extern Sint16 ev0030_head_meshes3[465];
extern Sint16 ev0030_head_meshes4[119];
extern Sint16 ev0030_head_meshes5[40];
extern Sint16 ev0030_head_meshes6[168];
extern Sint16 ev0030_head_meshes7[12];
extern NJS_COLOR ev0030_head_uvs0[60];
extern NJS_COLOR ev0030_head_uvs1[36];
extern NJS_COLOR ev0030_head_uvs2[16];
extern NJS_COLOR ev0030_head_uvs3[407];
extern NJS_COLOR ev0030_head_uvs4[110];
extern NJS_COLOR ev0030_head_uvs5[32];
extern NJS_COLOR ev0030_head_uvs6[144];
extern NJS_COLOR ev0030_head_uvs7[10];
extern NJS_MESHSET ev0030_head_meshsets[8];
extern NJS_POINT3 ev0030_head_points[366];
extern NJS_VECTOR ev0030_head_normals[366];
extern NJS_MODEL ev0030_head_model;
extern NJS_OBJECT ev0030_head_object;
extern NJS_MKEY_F ev0030_plane_motion_0_pos1[44];
extern NJS_MKEY_A ev0030_plane_motion_0_ang4[44];
extern NJS_MKEY_A ev0030_plane_motion_0_ang6[44];
extern NJS_MKEY_A ev0030_plane_motion_0_ang10[44];
extern NJS_MKEY_A ev0030_plane_motion_0_ang15[44];
extern NJS_MKEY_A ev0030_plane_motion_0_ang16[43];
extern NJS_MKEY_A ev0030_plane_motion_0_ang17[41];
extern NJS_MKEY_A ev0030_plane_motion_0_ang18[31];
extern NJS_MKEY_A ev0030_plane_motion_0_ang26[44];
extern NJS_MKEY_A ev0030_plane_motion_0_ang27[43];
extern NJS_MKEY_A ev0030_plane_motion_0_ang28[41];
extern NJS_MKEY_A ev0030_plane_motion_0_ang29[29];
extern NJS_MKEY_F ev0030_plane_motion_0_pos37[44];
extern NJS_MKEY_F ev0030_plane_motion_0_pos38[43];
extern NJS_MKEY_F ev0030_plane_motion_0_pos39[21];
extern NJS_MKEY_F ev0030_plane_motion_0_pos40[44];
extern NJS_MKEY_F ev0030_plane_motion_0_pos41[43];
extern NJS_MKEY_F ev0030_plane_motion_0_pos42[25];
extern NJS_MDATA2 ev0030_plane_motion_0_mdata[45];
extern NJS_MOTION ev0030_plane_motion_0;
extern NJS_ACTION ev0030_plane_action_0;
extern NJS_MKEY_F ev0030_plane_motion_1_pos1[44];
extern NJS_MKEY_A ev0030_plane_motion_1_ang4[44];
extern NJS_MKEY_F ev0030_plane_motion_1_pos5[44];
extern NJS_MKEY_A ev0030_plane_motion_1_ang6[44];
extern NJS_MKEY_A ev0030_plane_motion_1_ang10[32];
extern NJS_MKEY_A ev0030_plane_motion_1_ang15[44];
extern NJS_MKEY_A ev0030_plane_motion_1_ang16[44];
extern NJS_MKEY_A ev0030_plane_motion_1_ang17[38];
extern NJS_MKEY_A ev0030_plane_motion_1_ang18[34];
extern NJS_MKEY_A ev0030_plane_motion_1_ang26[43];
extern NJS_MKEY_A ev0030_plane_motion_1_ang27[44];
extern NJS_MKEY_A ev0030_plane_motion_1_ang28[42];
extern NJS_MKEY_A ev0030_plane_motion_1_ang29[24];
extern NJS_MKEY_F ev0030_plane_motion_1_pos37[44];
extern NJS_MKEY_F ev0030_plane_motion_1_pos38[40];
extern NJS_MKEY_F ev0030_plane_motion_1_pos39[2];
extern NJS_MKEY_F ev0030_plane_motion_1_pos40[44];
extern NJS_MKEY_F ev0030_plane_motion_1_pos41[40];
extern NJS_MKEY_F ev0030_plane_motion_1_pos42[2];
extern NJS_MDATA2 ev0030_plane_motion_1_mdata[45];
extern NJS_MOTION ev0030_plane_motion_1;
extern NJS_ACTION ev0030_plane_action_1;
extern NJS_MKEY_F ev0030_plane_motion_2_pos1[44];
extern NJS_MKEY_A ev0030_plane_motion_2_ang4[44];
extern NJS_MKEY_F ev0030_plane_motion_2_pos5[43];
extern NJS_MKEY_A ev0030_plane_motion_2_ang6[43];
extern NJS_MKEY_A ev0030_plane_motion_2_ang10[43];
extern NJS_MKEY_A ev0030_plane_motion_2_ang16[43];
extern NJS_MKEY_A ev0030_plane_motion_2_ang17[39];
extern NJS_MKEY_A ev0030_plane_motion_2_ang18[35];
extern NJS_MKEY_A ev0030_plane_motion_2_ang27[43];
extern NJS_MKEY_A ev0030_plane_motion_2_ang28[43];
extern NJS_MKEY_A ev0030_plane_motion_2_ang29[29];
extern NJS_MKEY_F ev0030_plane_motion_2_pos37[44];
extern NJS_MKEY_F ev0030_plane_motion_2_pos38[31];
extern NJS_MKEY_F ev0030_plane_motion_2_pos39[2];
extern NJS_MKEY_F ev0030_plane_motion_2_pos40[43];
extern NJS_MKEY_F ev0030_plane_motion_2_pos41[31];
extern NJS_MKEY_F ev0030_plane_motion_2_pos42[2];
extern NJS_MDATA2 ev0030_plane_motion_2_mdata[45];
extern NJS_MOTION ev0030_plane_motion_2;
extern NJS_ACTION ev0030_plane_action_2;
extern NJS_MKEY_F ev0030_plane_motion_3_pos1[44];
extern NJS_MKEY_A ev0030_plane_motion_3_ang4[44];
extern NJS_MKEY_A ev0030_plane_motion_3_ang6[44];
extern NJS_MKEY_A ev0030_plane_motion_3_ang10[44];
extern NJS_MKEY_A ev0030_plane_motion_3_ang15[44];
extern NJS_MKEY_A ev0030_plane_motion_3_ang16[44];
extern NJS_MKEY_A ev0030_plane_motion_3_ang17[41];
extern NJS_MKEY_A ev0030_plane_motion_3_ang18[23];
extern NJS_MKEY_A ev0030_plane_motion_3_ang26[44];
extern NJS_MKEY_A ev0030_plane_motion_3_ang27[44];
extern NJS_MKEY_A ev0030_plane_motion_3_ang28[41];
extern NJS_MKEY_A ev0030_plane_motion_3_ang29[29];
extern NJS_MKEY_F ev0030_plane_motion_3_pos37[44];
extern NJS_MKEY_F ev0030_plane_motion_3_pos38[44];
extern NJS_MKEY_F ev0030_plane_motion_3_pos39[44];
extern NJS_MKEY_F ev0030_plane_motion_3_pos40[44];
extern NJS_MKEY_F ev0030_plane_motion_3_pos41[44];
extern NJS_MKEY_F ev0030_plane_motion_3_pos42[44];
extern NJS_MDATA2 ev0030_plane_motion_3_mdata[45];
extern NJS_MOTION ev0030_plane_motion_3;
extern NJS_ACTION ev0030_plane_action_3;
extern NJS_MDATA2 ev0030_head_motion_0_mdata[1];
extern NJS_MOTION ev0030_head_motion_0;
extern NJS_ACTION ev0030_head_action_0;
extern NJS_MDATA2 ev0030_head_motion_1_mdata[1];
extern NJS_MOTION ev0030_head_motion_1;
extern NJS_ACTION ev0030_head_action_1;
extern NJS_MDATA2 ev0030_head_motion_2_mdata[1];
extern NJS_MOTION ev0030_head_motion_2;
extern NJS_ACTION ev0030_head_action_2;
extern NJS_POINT3 ev0030_head_shape_0_points0[366];
extern NJS_POINT3 ev0030_head_shape_0_normals0[366];
extern NJS_POINT3 ev0030_head_shape_0_points1[366];
extern NJS_POINT3 ev0030_head_shape_0_normals1[366];
extern NJS_POINT3 ev0030_head_shape_0_points2[366];
extern NJS_POINT3 ev0030_head_shape_0_normals2[366];
extern NJS_MKEY_P ev0030_head_shape_0_points[3];
extern NJS_MKEY_P ev0030_head_shape_0_normals[3];
extern NJS_MDATA2 ev0030_head_shape_0_mdata[1];
extern NJS_MOTION ev0030_head_shape_0;
extern NJS_POINT3 ev0030_head_shape_1_points0[366];
extern NJS_POINT3 ev0030_head_shape_1_normals0[366];
extern NJS_POINT3 ev0030_head_shape_1_points1[366];
extern NJS_POINT3 ev0030_head_shape_1_normals1[366];
extern NJS_POINT3 ev0030_head_shape_1_points2[366];
extern NJS_POINT3 ev0030_head_shape_1_normals2[366];
extern NJS_POINT3 ev0030_head_shape_1_points3[366];
extern NJS_POINT3 ev0030_head_shape_1_normals3[366];
extern NJS_MKEY_P ev0030_head_shape_1_points[4];
extern NJS_MKEY_P ev0030_head_shape_1_normals[4];
extern NJS_MDATA2 ev0030_head_shape_1_mdata[1];
extern NJS_MOTION ev0030_head_shape_1;
extern NJS_POINT3 ev0030_head_shape_2_points0[366];
extern NJS_POINT3 ev0030_head_shape_2_normals0[366];
extern NJS_POINT3 ev0030_head_shape_2_points1[366];
extern NJS_POINT3 ev0030_head_shape_2_normals1[366];
extern NJS_POINT3 ev0030_head_shape_2_points2[366];
extern NJS_POINT3 ev0030_head_shape_2_normals2[366];
extern NJS_POINT3 ev0030_head_shape_2_points3[366];
extern NJS_POINT3 ev0030_head_shape_2_normals3[366];
extern NJS_POINT3 ev0030_head_shape_2_points4[366];
extern NJS_POINT3 ev0030_head_shape_2_normals4[366];
extern NJS_MKEY_P ev0030_head_shape_2_points[5];
extern NJS_MKEY_P ev0030_head_shape_2_normals[5];
extern NJS_MDATA2 ev0030_head_shape_2_mdata[1];
extern NJS_MOTION ev0030_head_shape_2;
extern struct plane_anim ev0030_plane_anims[4];
extern struct task *ev0030_plane_task;

void ev0030_plane_destroy(struct task *task)
{
}

void ev0030_plane_draw(struct task *task)
{
    struct task_work *work = task->work;
    NJS_MATRIX head;
    Angle ang;

    draw_set_palette(DRAW_PLAYER_PALETTE);
    njPushMatrix(NULL);
    njTranslateV(NULL, &work->pos);
    TURN_VIA(njRotateZ, work->ang.z, ang);
    TURN_VIA(njRotateX, work->ang.x, ang);
    TURN_VIA(njRotateY, work->ang.y, ang);
    njSetTexture_jp(&ev0030_plane_texlist);
    ds_ActionClip(
        ev0030_plane_anims[((struct plane_vars *)&(work)->vars)->anim].action,
        ((struct plane_vars *)&(work)->vars)->frame);
    CalcMMMatrix(
        &nj_unit_matrix_,
        ev0030_plane_anims[((struct plane_vars *)&(work)->vars)->anim].action,
        ((struct plane_vars *)&(work)->vars)->frame, 12, &head);
    njMultiMatrix(((void *)0), &head);
    njSetTexture_jp(&ev0030_head_texlist);
    draw_shape_motion(
        &ev0030_head_object, ev0030_plane_anims[VARS(work)->anim].head_motion,
        ev0030_plane_anims[VARS(work)->anim].head_shape, VARS(work)->frame);
    late_DrawObjectClipEx(1);
    draw_set_palette(0);
}

void ev0030_plane_step(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->frame += VARS(work)->speed;
    if (VARS(work)->frame >=
        (Float)(ev0030_plane_anims[VARS(work)->anim].action->motion->nbFrame -
                1)) {
        VARS(work)->anim = ev0030_plane_anims[VARS(work)->anim].next;
        VARS(work)->frame = 0.0F;
    }
    if (work->event->paths != NULL) {
        ExecEventPath(work);
    }
    ev0030_plane_draw(task);
}

void ev0030_plane_init(struct task *task)
{
    struct task_work *work = task->work;

    VARS(work)->speed = 0.5F;
    VARS(work)->frame = 0.0F;
    VARS(work)->anim = 0;
    work->scl.x = 0.0F;
    work->scl.y = 0.0F;
    work->scl.z = 0.0F;
    event_set_flags(task, EVENT_IGNORE_GROUND);
    task->step = ev0030_plane_step;
    task->draw = ev0030_plane_draw;
    task->destructor = ev0030_plane_destroy;
}

struct task *ev0030_plane_create(void)
{
    struct task *task;

    task = CreateElementalTask(TASK_WORK, 5, ev0030_plane_init);
    if (task != NULL) {
        ev0030_plane_task = task;
        SetEventWork(task->work);
    }
    return task;
}

void ev0030_plane_play(int anim, Float speed)
{
    if (ev0030_plane_task != NULL) {
        VARS(ev0030_plane_task->work)->anim = anim;
        VARS(ev0030_plane_task->work)->frame = 0.0F;
        VARS(ev0030_plane_task->work)->speed = speed;
    }
}
