/* @unit 0C914580-0C914640 +r04 +egflags +pool32 */
/* poms, the bursts of textures pom01 to pom08 that play once where they're
 * made; the targets' box and boards; and the list of the particle pools Final
 * Egg adds */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#define TEXT_6 ""
#define TEXT_7 ""
#define TEXT_8 ""
#include <ninja.h>
#include <sg_xpt.h>

#include "effect/dust.h"
#include "effect/particle.h"
#include "effect/pools.h"
#include "stg10/drum.h"
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
void SpFreeTask(struct particle *particle);
void SpFreeLink(struct particle_pool *pool);
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
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

#define TEXT_1_LENGTH 5
#define TEXT_2_LENGTH 5
#define TEXT_3_LENGTH 5
#define TEXT_4_LENGTH 5
#define TEXT_5_LENGTH 5
#define TEXT_6_LENGTH 5
#define TEXT_7_LENGTH 5
#define TEXT_8_LENGTH 5

#define POM_FRAMES 8

void final_pom_step(struct particle *particle, struct particle_pool *pool);
extern NJS_TEXNAME final_pom_textures[8];
extern NJS_TEXANIM final_pom_frames[8];
extern struct particle_anim final_pom_anim;
extern struct dust_params final_pom_params;
extern NJS_TEXLIST final_pom_texlist;
extern struct particle_pool_spec final_pom_pool;
extern NJS_OBJECT target_box_node5_object;
extern NJS_MATERIAL target_box_node4_materials[1];
extern Sint16 target_box_node4_meshes[63];
extern NJS_COLOR target_box_node4_uvs[56];
extern NJS_MESHSET target_box_node4_meshsets[1];
extern NJS_POINT3 target_box_node4_points[28];
extern NJS_VECTOR target_box_node4_normals[28];
extern NJS_MODEL target_box_node4_model;
extern NJS_OBJECT target_box_node4_object;
extern NJS_MATERIAL target_box_node3_materials[19];
extern Sint16 target_box_node3_meshes0[25];
extern Sint16 target_box_node3_meshes1[7];
extern Sint16 target_box_node3_meshes2[20];
extern Sint16 target_box_node3_meshes3[21];
extern Sint16 target_box_node3_meshes4[30];
extern Sint16 target_box_node3_meshes5[40];
extern Sint16 target_box_node3_meshes6[25];
extern Sint16 target_box_node3_meshes7[30];
extern Sint16 target_box_node3_meshes8[45];
extern Sint16 target_box_node3_meshes9[6];
extern Sint16 target_box_node3_meshes10[6];
extern Sint16 target_box_node3_meshes11[50];
extern Sint16 target_box_node3_meshes12[36];
extern Sint16 target_box_node3_meshes13[9];
extern Sint16 target_box_node3_meshes14[18];
extern Sint16 target_box_node3_meshes15[30];
extern Sint16 target_box_node3_meshes16[15];
extern Sint16 target_box_node3_meshes17[20];
extern Sint16 target_box_node3_meshes18[10];
extern NJS_COLOR target_box_node3_uvs0[20];
extern NJS_COLOR target_box_node3_uvs1[6];
extern NJS_COLOR target_box_node3_uvs2[16];
extern NJS_COLOR target_box_node3_uvs3[18];
extern NJS_COLOR target_box_node3_uvs4[24];
extern NJS_COLOR target_box_node3_uvs5[32];
extern NJS_COLOR target_box_node3_uvs6[20];
extern NJS_COLOR target_box_node3_uvs7[24];
extern NJS_COLOR target_box_node3_uvs8[36];
extern NJS_COLOR target_box_node3_uvs9[5];
extern NJS_COLOR target_box_node3_uvs11[40];
extern NJS_COLOR target_box_node3_uvs12[32];
extern NJS_COLOR target_box_node3_uvs13[8];
extern NJS_COLOR target_box_node3_uvs14[16];
extern NJS_COLOR target_box_node3_uvs15[24];
extern NJS_COLOR target_box_node3_uvs16[12];
extern NJS_COLOR target_box_node3_uvs17[16];
extern NJS_COLOR target_box_node3_uvs18[8];
extern NJS_MESHSET target_box_node3_meshsets[19];
extern NJS_POINT3 target_box_node3_points[143];
extern NJS_VECTOR target_box_node3_normals[143];
extern NJS_MODEL target_box_node3_model;
extern NJS_OBJECT target_box_node3_object;
extern NJS_MATERIAL target_box_node2_materials[2];
extern Sint16 target_box_node2_meshes0[5];
extern Sint16 target_box_node2_meshes1[5];
extern NJS_COLOR target_box_node2_uvs0[4];
extern NJS_COLOR target_box_node2_uvs1[4];
extern NJS_MESHSET target_box_node2_meshsets[2];
extern NJS_POINT3 target_box_node2_points[6];
extern NJS_VECTOR target_box_node2_normals[6];
extern NJS_MODEL target_box_node2_model;
extern NJS_OBJECT target_box_node2_object;
extern NJS_MATERIAL target_box_node1_materials[2];
extern Sint16 target_box_node1_meshes0[5];
extern Sint16 target_box_node1_meshes1[5];
extern NJS_COLOR target_box_node1_uvs0[4];
extern NJS_COLOR target_box_node1_uvs1[4];
extern NJS_MESHSET target_box_node1_meshsets[2];
extern NJS_POINT3 target_box_node1_points[6];
extern NJS_VECTOR target_box_node1_normals[6];
extern NJS_MODEL target_box_node1_model;
extern NJS_OBJECT target_box_node1_object;
extern NJS_MATERIAL target_box_materials[5];
extern Sint16 target_box_meshes0[14];
extern Sint16 target_box_meshes1[17];
extern Sint16 target_box_meshes2[5];
extern Sint16 target_box_meshes3[11];
extern Sint16 target_box_meshes4[20];
extern NJS_COLOR target_box_uvs0[12];
extern NJS_COLOR target_box_uvs1[14];
extern NJS_COLOR target_box_uvs2[4];
extern NJS_COLOR target_box_uvs3[10];
extern NJS_COLOR target_box_uvs4[16];
extern NJS_MESHSET target_box_meshsets[5];
extern NJS_POINT3 target_box_points[20];
extern NJS_VECTOR target_box_normals[20];
extern NJS_MODEL target_box_model;
extern NJS_OBJECT target_box_object;
extern NJS_MATERIAL target_sonic_node8_materials[5];
extern Sint16 target_sonic_node8_meshes0[22];
extern Sint16 target_sonic_node8_meshes1[25];
extern Sint16 target_sonic_node8_meshes2[30];
extern Sint16 target_sonic_node8_meshes3[7];
extern Sint16 target_sonic_node8_meshes4[10];
extern NJS_COLOR target_sonic_node8_uvs0[20];
extern NJS_COLOR target_sonic_node8_uvs1[21];
extern NJS_COLOR target_sonic_node8_uvs2[24];
extern NJS_COLOR target_sonic_node8_uvs3[6];
extern NJS_COLOR target_sonic_node8_uvs4[8];
extern NJS_MESHSET target_sonic_node8_meshsets[5];
extern NJS_POINT3 target_sonic_node8_points[34];
extern NJS_VECTOR target_sonic_node8_normals[34];
extern NJS_MODEL target_sonic_node8_model;
extern NJS_OBJECT target_sonic_node8_object;
extern NJS_MATERIAL target_sonic_node7_materials[2];
extern Sint16 target_sonic_node7_meshes0[100];
extern Sint16 target_sonic_node7_meshes1[22];
extern NJS_COLOR target_sonic_node7_uvs0[88];
extern NJS_COLOR target_sonic_node7_uvs1[20];
extern NJS_MESHSET target_sonic_node7_meshsets[2];
extern NJS_POINT3 target_sonic_node7_points[50];
extern NJS_VECTOR target_sonic_node7_normals[50];
extern NJS_MODEL target_sonic_node7_model;
extern NJS_OBJECT target_sonic_node7_object;
extern NJS_MATERIAL target_sonic_node6_materials[5];
extern Sint16 target_sonic_node6_meshes0[22];
extern Sint16 target_sonic_node6_meshes1[22];
extern Sint16 target_sonic_node6_meshes2[27];
extern Sint16 target_sonic_node6_meshes3[10];
extern Sint16 target_sonic_node6_meshes4[10];
extern NJS_COLOR target_sonic_node6_uvs0[20];
extern NJS_COLOR target_sonic_node6_uvs1[19];
extern NJS_COLOR target_sonic_node6_uvs2[22];
extern NJS_COLOR target_sonic_node6_uvs3[8];
extern NJS_COLOR target_sonic_node6_uvs4[8];
extern NJS_MESHSET target_sonic_node6_meshsets[5];
extern NJS_POINT3 target_sonic_node6_points[34];
extern NJS_VECTOR target_sonic_node6_normals[34];
extern NJS_MODEL target_sonic_node6_model;
extern NJS_OBJECT target_sonic_node6_object;
extern NJS_MATERIAL target_sonic_node5_materials[2];
extern Sint16 target_sonic_node5_meshes0[100];
extern Sint16 target_sonic_node5_meshes1[22];
extern NJS_COLOR target_sonic_node5_uvs0[88];
extern NJS_COLOR target_sonic_node5_uvs1[20];
extern NJS_MESHSET target_sonic_node5_meshsets[2];
extern NJS_POINT3 target_sonic_node5_points[50];
extern NJS_VECTOR target_sonic_node5_normals[50];
extern NJS_MODEL target_sonic_node5_model;
extern NJS_OBJECT target_sonic_node5_object;
extern NJS_MATERIAL target_sonic_node4_materials[1];
extern Sint16 target_sonic_node4_meshes[16];
extern NJS_COLOR target_sonic_node4_uvs[14];
extern NJS_MESHSET target_sonic_node4_meshsets[1];
extern NJS_POINT3 target_sonic_node4_points[8];
extern NJS_VECTOR target_sonic_node4_normals[8];
extern NJS_MODEL target_sonic_node4_model;
extern NJS_OBJECT target_sonic_node4_object;
extern NJS_MATERIAL target_sonic_node3_materials[1];
extern Sint16 target_sonic_node3_meshes[16];
extern NJS_COLOR target_sonic_node3_uvs[14];
extern NJS_MESHSET target_sonic_node3_meshsets[1];
extern NJS_POINT3 target_sonic_node3_points[8];
extern NJS_VECTOR target_sonic_node3_normals[8];
extern NJS_MODEL target_sonic_node3_model;
extern NJS_OBJECT target_sonic_node3_object;
extern NJS_MATERIAL target_sonic_node2_materials[1];
extern Sint16 target_sonic_node2_meshes[16];
extern NJS_COLOR target_sonic_node2_uvs[14];
extern NJS_MESHSET target_sonic_node2_meshsets[1];
extern NJS_POINT3 target_sonic_node2_points[8];
extern NJS_VECTOR target_sonic_node2_normals[8];
extern NJS_MODEL target_sonic_node2_model;
extern NJS_OBJECT target_sonic_node2_object;
extern NJS_MATERIAL target_sonic_node1_materials[5];
extern Sint16 target_sonic_node1_meshes0[113];
extern Sint16 target_sonic_node1_meshes1[61];
extern Sint16 target_sonic_node1_meshes2[32];
extern Sint16 target_sonic_node1_meshes3[21];
extern Sint16 target_sonic_node1_meshes4[8];
extern NJS_COLOR target_sonic_node1_uvs0[100];
extern NJS_COLOR target_sonic_node1_uvs1[52];
extern NJS_COLOR target_sonic_node1_uvs2[26];
extern NJS_COLOR target_sonic_node1_uvs3[18];
extern NJS_COLOR target_sonic_node1_uvs4[6];
extern NJS_MESHSET target_sonic_node1_meshsets[5];
extern NJS_POINT3 target_sonic_node1_points[70];
extern NJS_VECTOR target_sonic_node1_normals[70];
extern NJS_MODEL target_sonic_node1_model;
extern NJS_OBJECT target_sonic_node1_object;
extern NJS_MATERIAL target_sonic_materials[2];
extern Sint16 target_sonic_meshes0[82];
extern Sint16 target_sonic_meshes1[17];
extern NJS_COLOR target_sonic_uvs0[74];
extern NJS_COLOR target_sonic_uvs1[14];
extern NJS_MESHSET target_sonic_meshsets[2];
extern NJS_POINT3 target_sonic_points[35];
extern NJS_VECTOR target_sonic_normals[35];
extern NJS_MODEL target_sonic_model;
extern NJS_OBJECT target_sonic_object;
extern NJS_MATERIAL target_knuckles_node8_materials[6];
extern Sint16 target_knuckles_node8_meshes0[22];
extern Sint16 target_knuckles_node8_meshes1[20];
extern Sint16 target_knuckles_node8_meshes2[7];
extern Sint16 target_knuckles_node8_meshes3[22];
extern Sint16 target_knuckles_node8_meshes4[15];
extern Sint16 target_knuckles_node8_meshes5[5];
extern NJS_COLOR target_knuckles_node8_uvs0[20];
extern NJS_COLOR target_knuckles_node8_uvs1[16];
extern NJS_COLOR target_knuckles_node8_uvs2[6];
extern NJS_COLOR target_knuckles_node8_uvs3[19];
extern NJS_COLOR target_knuckles_node8_uvs4[12];
extern NJS_COLOR target_knuckles_node8_uvs5[4];
extern NJS_MESHSET target_knuckles_node8_meshsets[6];
extern NJS_POINT3 target_knuckles_node8_points[34];
extern NJS_VECTOR target_knuckles_node8_normals[34];
extern NJS_MODEL target_knuckles_node8_model;
extern NJS_OBJECT target_knuckles_node8_object;
extern NJS_MATERIAL target_knuckles_node7_materials[2];
extern Sint16 target_knuckles_node7_meshes0[152];
extern Sint16 target_knuckles_node7_meshes1[22];
extern NJS_COLOR target_knuckles_node7_uvs0[131];
extern NJS_COLOR target_knuckles_node7_uvs1[20];
extern NJS_MESHSET target_knuckles_node7_meshsets[2];
extern NJS_POINT3 target_knuckles_node7_points[70];
extern NJS_VECTOR target_knuckles_node7_normals[70];
extern NJS_MODEL target_knuckles_node7_model;
extern NJS_OBJECT target_knuckles_node7_object;
extern NJS_MATERIAL target_knuckles_node6_materials[6];
extern Sint16 target_knuckles_node6_meshes0[22];
extern Sint16 target_knuckles_node6_meshes1[17];
extern Sint16 target_knuckles_node6_meshes2[7];
extern Sint16 target_knuckles_node6_meshes3[19];
extern Sint16 target_knuckles_node6_meshes4[15];
extern Sint16 target_knuckles_node6_meshes5[5];
extern NJS_COLOR target_knuckles_node6_uvs0[20];
extern NJS_COLOR target_knuckles_node6_uvs1[14];
extern NJS_COLOR target_knuckles_node6_uvs2[6];
extern NJS_COLOR target_knuckles_node6_uvs3[17];
extern NJS_COLOR target_knuckles_node6_uvs4[12];
extern NJS_COLOR target_knuckles_node6_uvs5[4];
extern NJS_MESHSET target_knuckles_node6_meshsets[6];
extern NJS_POINT3 target_knuckles_node6_points[34];
extern NJS_VECTOR target_knuckles_node6_normals[34];
extern NJS_MODEL target_knuckles_node6_model;
extern NJS_OBJECT target_knuckles_node6_object;
extern NJS_MATERIAL target_knuckles_node5_materials[2];
extern Sint16 target_knuckles_node5_meshes0[152];
extern Sint16 target_knuckles_node5_meshes1[22];
extern NJS_COLOR target_knuckles_node5_uvs0[131];
extern NJS_COLOR target_knuckles_node5_uvs1[20];
extern NJS_MESHSET target_knuckles_node5_meshsets[2];
extern NJS_POINT3 target_knuckles_node5_points[70];
extern NJS_VECTOR target_knuckles_node5_normals[70];
extern NJS_MODEL target_knuckles_node5_model;
extern NJS_OBJECT target_knuckles_node5_object;
extern NJS_MATERIAL target_knuckles_node4_materials[1];
extern Sint16 target_knuckles_node4_meshes[16];
extern NJS_COLOR target_knuckles_node4_uvs[14];
extern NJS_MESHSET target_knuckles_node4_meshsets[1];
extern NJS_POINT3 target_knuckles_node4_points[8];
extern NJS_VECTOR target_knuckles_node4_normals[8];
extern NJS_MODEL target_knuckles_node4_model;
extern NJS_OBJECT target_knuckles_node4_object;
extern NJS_MATERIAL target_knuckles_node3_materials[1];
extern Sint16 target_knuckles_node3_meshes[16];
extern NJS_COLOR target_knuckles_node3_uvs[14];
extern NJS_MESHSET target_knuckles_node3_meshsets[1];
extern NJS_POINT3 target_knuckles_node3_points[8];
extern NJS_VECTOR target_knuckles_node3_normals[8];
extern NJS_MODEL target_knuckles_node3_model;
extern NJS_OBJECT target_knuckles_node3_object;
extern NJS_MATERIAL target_knuckles_node2_materials[1];
extern Sint16 target_knuckles_node2_meshes[16];
extern NJS_COLOR target_knuckles_node2_uvs[14];
extern NJS_MESHSET target_knuckles_node2_meshsets[1];
extern NJS_POINT3 target_knuckles_node2_points[8];
extern NJS_VECTOR target_knuckles_node2_normals[8];
extern NJS_MODEL target_knuckles_node2_model;
extern NJS_OBJECT target_knuckles_node2_object;
extern NJS_MATERIAL target_knuckles_node1_materials[4];
extern Sint16 target_knuckles_node1_meshes0[97];
extern Sint16 target_knuckles_node1_meshes1[61];
extern Sint16 target_knuckles_node1_meshes2[36];
extern Sint16 target_knuckles_node1_meshes3[11];
extern NJS_COLOR target_knuckles_node1_uvs0[88];
extern NJS_COLOR target_knuckles_node1_uvs1[52];
extern NJS_COLOR target_knuckles_node1_uvs2[32];
extern NJS_COLOR target_knuckles_node1_uvs3[10];
extern NJS_MESHSET target_knuckles_node1_meshsets[4];
extern NJS_POINT3 target_knuckles_node1_points[70];
extern NJS_VECTOR target_knuckles_node1_normals[70];
extern NJS_MODEL target_knuckles_node1_model;
extern NJS_OBJECT target_knuckles_node1_object;
extern NJS_MATERIAL target_knuckles_materials[2];
extern Sint16 target_knuckles_meshes0[69];
extern Sint16 target_knuckles_meshes1[18];
extern NJS_COLOR target_knuckles_uvs0[62];
extern NJS_COLOR target_knuckles_uvs1[16];
extern NJS_MESHSET target_knuckles_meshsets[2];
extern NJS_POINT3 target_knuckles_points[32];
extern NJS_VECTOR target_knuckles_normals[32];
extern NJS_MODEL target_knuckles_model;
extern NJS_OBJECT target_knuckles_object;
extern NJS_MATERIAL target_tails_node10_materials[5];
extern Sint16 target_tails_node10_meshes0[22];
extern Sint16 target_tails_node10_meshes1[17];
extern Sint16 target_tails_node10_meshes2[27];
extern Sint16 target_tails_node10_meshes3[10];
extern Sint16 target_tails_node10_meshes4[12];
extern NJS_COLOR target_tails_node10_uvs0[20];
extern NJS_COLOR target_tails_node10_uvs1[14];
extern NJS_COLOR target_tails_node10_uvs2[23];
extern NJS_COLOR target_tails_node10_uvs3[8];
extern NJS_COLOR target_tails_node10_uvs4[10];
extern NJS_MESHSET target_tails_node10_meshsets[5];
extern NJS_POINT3 target_tails_node10_points[34];
extern NJS_VECTOR target_tails_node10_normals[34];
extern NJS_MODEL target_tails_node10_model;
extern NJS_OBJECT target_tails_node10_object;
extern NJS_MATERIAL target_tails_node9_materials[2];
extern Sint16 target_tails_node9_meshes0[112];
extern Sint16 target_tails_node9_meshes1[11];
extern NJS_COLOR target_tails_node9_uvs0[96];
extern NJS_COLOR target_tails_node9_uvs1[10];
extern NJS_MESHSET target_tails_node9_meshsets[2];
extern NJS_POINT3 target_tails_node9_points[46];
extern NJS_VECTOR target_tails_node9_normals[46];
extern NJS_MODEL target_tails_node9_model;
extern NJS_OBJECT target_tails_node9_object;
extern NJS_MATERIAL target_tails_node8_materials[1];
extern Sint16 target_tails_node8_meshes[16];
extern NJS_COLOR target_tails_node8_uvs[14];
extern NJS_MESHSET target_tails_node8_meshsets[1];
extern NJS_POINT3 target_tails_node8_points[8];
extern NJS_VECTOR target_tails_node8_normals[8];
extern NJS_MODEL target_tails_node8_model;
extern NJS_OBJECT target_tails_node8_object;
extern NJS_MATERIAL target_tails_node7_materials[1];
extern Sint16 target_tails_node7_meshes[16];
extern NJS_COLOR target_tails_node7_uvs[14];
extern NJS_MESHSET target_tails_node7_meshsets[1];
extern NJS_POINT3 target_tails_node7_points[8];
extern NJS_VECTOR target_tails_node7_normals[8];
extern NJS_MODEL target_tails_node7_model;
extern NJS_OBJECT target_tails_node7_object;
extern NJS_MATERIAL target_tails_node6_materials[1];
extern Sint16 target_tails_node6_meshes[16];
extern NJS_COLOR target_tails_node6_uvs[14];
extern NJS_MESHSET target_tails_node6_meshsets[1];
extern NJS_POINT3 target_tails_node6_points[8];
extern NJS_VECTOR target_tails_node6_normals[8];
extern NJS_MODEL target_tails_node6_model;
extern NJS_OBJECT target_tails_node6_object;
extern NJS_MATERIAL target_tails_node5_materials[5];
extern Sint16 target_tails_node5_meshes0[119];
extern Sint16 target_tails_node5_meshes1[37];
extern Sint16 target_tails_node5_meshes2[28];
extern Sint16 target_tails_node5_meshes3[8];
extern Sint16 target_tails_node5_meshes4[21];
extern NJS_COLOR target_tails_node5_uvs0[106];
extern NJS_COLOR target_tails_node5_uvs1[32];
extern NJS_COLOR target_tails_node5_uvs2[24];
extern NJS_COLOR target_tails_node5_uvs3[6];
extern NJS_COLOR target_tails_node5_uvs4[18];
extern NJS_MESHSET target_tails_node5_meshsets[5];
extern NJS_POINT3 target_tails_node5_points[68];
extern NJS_VECTOR target_tails_node5_normals[68];
extern NJS_MODEL target_tails_node5_model;
extern NJS_OBJECT target_tails_node5_object;
extern NJS_MATERIAL target_tails_node4_materials[5];
extern Sint16 target_tails_node4_meshes0[22];
extern Sint16 target_tails_node4_meshes1[17];
extern Sint16 target_tails_node4_meshes2[27];
extern Sint16 target_tails_node4_meshes3[10];
extern Sint16 target_tails_node4_meshes4[15];
extern NJS_COLOR target_tails_node4_uvs0[20];
extern NJS_COLOR target_tails_node4_uvs1[14];
extern NJS_COLOR target_tails_node4_uvs2[23];
extern NJS_COLOR target_tails_node4_uvs3[8];
extern NJS_COLOR target_tails_node4_uvs4[12];
extern NJS_MESHSET target_tails_node4_meshsets[5];
extern NJS_POINT3 target_tails_node4_points[34];
extern NJS_VECTOR target_tails_node4_normals[34];
extern NJS_MODEL target_tails_node4_model;
extern NJS_OBJECT target_tails_node4_object;
extern NJS_MATERIAL target_tails_node3_materials[2];
extern Sint16 target_tails_node3_meshes0[109];
extern Sint16 target_tails_node3_meshes1[11];
extern NJS_COLOR target_tails_node3_uvs0[94];
extern NJS_COLOR target_tails_node3_uvs1[10];
extern NJS_MESHSET target_tails_node3_meshsets[2];
extern NJS_POINT3 target_tails_node3_points[46];
extern NJS_VECTOR target_tails_node3_normals[46];
extern NJS_MODEL target_tails_node3_model;
extern NJS_OBJECT target_tails_node3_object;
extern NJS_MATERIAL target_tails_node2_materials[1];
extern Sint16 target_tails_node2_meshes[45];
extern NJS_COLOR target_tails_node2_uvs[40];
extern NJS_MESHSET target_tails_node2_meshsets[1];
extern NJS_POINT3 target_tails_node2_points[17];
extern NJS_VECTOR target_tails_node2_normals[17];
extern NJS_MODEL target_tails_node2_model;
extern NJS_OBJECT target_tails_node2_object;
extern NJS_MATERIAL target_tails_node1_materials[1];
extern Sint16 target_tails_node1_meshes[45];
extern NJS_COLOR target_tails_node1_uvs[40];
extern NJS_MESHSET target_tails_node1_meshsets[1];
extern NJS_POINT3 target_tails_node1_points[17];
extern NJS_VECTOR target_tails_node1_normals[17];
extern NJS_MODEL target_tails_node1_model;
extern NJS_OBJECT target_tails_node1_object;
extern NJS_MATERIAL target_tails_materials[2];
extern Sint16 target_tails_meshes0[59];
extern Sint16 target_tails_meshes1[73];
extern NJS_COLOR target_tails_uvs0[48];
extern NJS_COLOR target_tails_uvs1[64];
extern NJS_MESHSET target_tails_meshsets[2];
extern NJS_POINT3 target_tails_points[53];
extern NJS_VECTOR target_tails_normals[53];
extern NJS_MODEL target_tails_model;
extern NJS_OBJECT target_tails_object;
extern struct particle_pool_spec *final_pools[];

void final_pom_create(NJS_POINT3 *pos, Float scale)
{
    struct particle_pool *pool = final_pom_pool.pool;
    struct particle *particle;

    /* @hack spelling: the particle assigned in the test. SHC tests it in R0
     * (TST R0,R0 at 0x0c9150b2), and copies it to R5 in the branch's delay
     * slot. as two statements, SHC copies it to R4 to test it, and 14 of 43
     * words differ */
    if ((particle = SpCreateTask(pool, final_pom_step)) != NULL) {
        particle->pos = *pos;
        particle->scale = scale;
        particle->time = 0.0F;
        particle->ang = 0;
        particle->color = final_pom_params.color;
        DUST(particle)->params = &final_pom_params;
    }
}

void final_pom_step(struct particle *particle, struct particle_pool *pool)
{
    struct dust_params *params = DUST(particle)->params;

    particle->frame = particle->time;
    if (particle->frame >= (Sint16)pool->anim->frames) {
        particle->frame = pool->anim->frames - 1;
        SpFreeTask(particle);
        return;
    }
    /* @hack redundant: the rate times 1.0F, which SHC adds with an FMAC (FLDI1
     * FR0 at 0x0c91511e, FMAC FR0,FR3,FR2 at 0x0c915128); without it, 8 of 28
     * words differ */
    particle->time += params->rate * 1.0F;
}
