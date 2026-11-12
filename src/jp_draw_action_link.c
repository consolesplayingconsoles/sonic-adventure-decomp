/* @unit 8C040A60-8C041E60 +r04 +egflags +pool32 +asmfunc=action_link_blend_normal:+8c0410a4,action_link_blend_point:+8c0410d0,action_link_draw_morphed_model:+8c041a2e,action_link_draw_motion_tree:+8c041b0e,action_link_draw_shape_tree:+8c041c92,action_link_find_key:+8c040aaa,action_link_find_shape_key:+8c040af4,action_link_get_both_normals:+8c0412c8,action_link_get_both_points:+8c04124e,action_link_get_shape_normals:+8c0411d4,action_link_get_shape_points:+8c041152,action_link_morph_model:+8c0414a6,action_link_motion_node_0:+8c04154e,action_link_motion_node_1:+8c041600,action_link_motion_node_2:+8c041666,action_link_motion_node_3:+8c0416cc,action_link_motion_node_4:+8c041732,action_link_rotate_keys:+8c040f7a,action_link_rotate_object:+8c0414f0,action_link_sample_shape:+8c041040,action_link_scale_keys:+8c040ef8,action_link_scale_object:+8c041516,action_link_select_steps:+8c040c5c,action_link_shape_node_0:+8c04175c,action_link_shape_node_1:+8c041792,action_link_shape_node_2:+8c0417c8,action_link_start_motion:+8c040c02,action_link_start_shape:+8c040b90,action_link_translate_keys:+8c040e74,action_link_translate_object:+8c0414cc,draw_motion_link:+8c041e60,___dsActionLink:+8c041d68,FUN_8c0412c8:+8c041340,FUN_8c041340:+8c041378,FUN_8c0417c8:+8c04196c,link_linear_angles:+8c040df0,link_linear_vector:+8c040d60 */
/* Ported from the Japanese release's src/draw/action_link.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
typedef unsigned char Uint8;
typedef signed char Sint8;
typedef unsigned short Uint16;
typedef short Sint16;
typedef unsigned long Uint32;
typedef long Sint32;
typedef int Int;
typedef float Float;
enum bool { false, true };
typedef enum bool Bool;
typedef Sint32 Angle;
typedef Float NJS_MATRIX[16];
typedef struct {
    Float x, y;
} NJS_POINT2;
typedef struct {
    Float x, y, z;
} NJS_POINT3, NJS_VECTOR;
typedef struct {
    Float a, r, g, b;
} NJS_ARGB;
typedef Float NJS_FOG_TABLE[128];
typedef struct {
    Sint16 u, v;
} NJS_TEX;
typedef struct {
    Uint8 b, g, r, a;
} NJS_BGRA;
typedef union {
    Uint32 color;
    NJS_TEX tex;
    NJS_BGRA argb;
} NJS_COLOR;
typedef struct {
    NJS_COLOR diffuse;
    NJS_COLOR specular;
    Float exponent;
    Uint32 attr_texId;
    Uint32 attrflags;
} NJS_MATERIAL;
typedef struct {
    Uint16 type_matId;
    Uint16 nbMesh;
    Sint16 *meshes;
    Uint32 *attrs;
    NJS_VECTOR *normals;
    NJS_COLOR *vertcolor;
    NJS_COLOR *vertuv;
} NJS_MESHSET;
typedef struct {
    NJS_POINT3 *points;
    NJS_VECTOR *normals;
    Sint32 nbPoint;
    NJS_MESHSET *meshsets;
    NJS_MATERIAL *mats;
    Uint16 nbMeshset;
    Uint16 nbMat;
    NJS_POINT3 center;
    Float r;
} NJS_MODEL;
typedef struct obj {
    Uint32 evalflags;
    NJS_MODEL *model;
    Float pos[3];
    Angle ang[3];
    Float scl[3];
    struct obj *child;
    struct obj *sibling;
} NJS_OBJECT;
typedef struct {
    void *mdata;
    Uint32 nbFrame;
    Uint16 type;
    Uint16 inp_fn;
} NJS_MOTION;
typedef struct {
    Uint32 keyframe;
    Float key[3];
} NJS_MKEY_F;
typedef struct {
    Uint32 keyframe;
    Angle key[3];
} NJS_MKEY_A;
typedef struct {
    Uint32 keyframe;
    void *key;
} NJS_MKEY_P;
typedef struct {
    void *p[1];
    Uint32 nb[1];
} NJS_MDATA1;
typedef struct {
    void *p[2];
    Uint32 nb[2];
} NJS_MDATA2;
typedef struct {
    void *p[3];
    Uint32 nb[3];
} NJS_MDATA3;
typedef struct {
    void *p[4];
    Uint32 nb[4];
} NJS_MDATA4;
typedef struct {
    NJS_OBJECT *object;
    NJS_MOTION *motion;
} NJS_ACTION;
typedef struct {
    NJS_MOTION *motion[2];
    Float frame[2];
} NJS_MOTION_LINK;
typedef struct {
    NJS_OBJECT *object;
    NJS_MOTION_LINK *motionlink;
} NJS_ACTION_LINK;
typedef struct {
    Float *pos;
    Angle *ang;
    Float *scl;
} NJS_MOTION_DATA;
typedef struct {
    void *filename;
    Uint32 attr;
    Uint32 texaddr;
} NJS_TEXNAME;
typedef struct {
    NJS_TEXNAME *textures;
    Uint32 nbTexture;
} NJS_TEXLIST;
typedef struct {
    Uint32 Type;
    Uint32 BitDepth;
    Uint32 PixelFormat;
    Uint32 nWidth;
    Uint32 nHeight;
    Uint32 TextureSize;
    Uint32 fSurfaceFlags;
    Uint32 *pSurface;
    Uint32 *pVirtual;
    Uint32 *pPhysical;
} NJS_TEXSURFACE;
typedef struct {
    void *texaddr;
    NJS_TEXSURFACE texsurface;
} NJS_TEXINFO;
typedef struct {
    Uint32 globalIndex;
    Uint32 bank;
    Uint32 tspparambuffer;
    Uint32 texparambuffer;
    Uint32 texaddr;
    NJS_TEXINFO texinfo;
    Uint16 count;
    Uint16 dummy;
} NJS_TEXMEMLIST;
typedef struct {
    void *palette;
    Uint16 mode;
    Sint16 bank;
    Sint16 offset;
    Sint16 count;
} NJS_TEXPALETTE;
typedef struct {
    Uint32 n;
    Uint32 globalIndex;
    Sint32 texerr;
    Sint32 gdstat;
    Sint32 gderr;
    Sint32 reserved0;
    Sint32 reserved1;
    Sint32 reserved2;
} NJS_TEXERRSTAT;
typedef struct {
    Sint16 sx, sy;
    Sint16 cx, cy;
    Sint16 u1, v1;
    Sint16 u2, v2;
    Sint16 texid;
    Sint16 attr;
} NJS_TEXANIM;
typedef struct {
    NJS_POINT3 p;
    Float sx, sy;
    Angle ang;
    NJS_TEXLIST *tlist;
    NJS_TEXANIM *tanim;
} NJS_SPRITE;
typedef struct {
    NJS_POINT2 *p;
    NJS_COLOR *col;
    NJS_COLOR *tex;
    Uint32 num;
} NJS_POINT2COL;
typedef struct {
    NJS_POINT3 *p;
    NJS_COLOR *col;
    NJS_COLOR *tex;
    Uint32 num;
} NJS_POINT3COL;
typedef struct {
    Float x, y, z;
    Uint32 col;
} NJS_POLYGON_VTX;
typedef struct {
    Float x, y, z;
    Float u, v;
    Uint32 col;
} NJS_TEXTURE_VTX;
typedef struct {
    Float px, py, pz;
    Float vx, vy, vz;
} NJS_LINE, NJS_PLANE;
typedef struct {
    NJS_POINT3 c;
    Float r;
} NJS_SPHERE;
typedef struct {
    int keys;
    int *iparam;
    float *fparam;
} NJS_SPLINE;
typedef struct {
    Float dist;
    Float w, h;
    Float cx, cy;
} NJS_SCREEN;
typedef struct {
    NJS_MATRIX m;
    Float px, py, pz;
    Float vx, vy, vz;
    Angle roll;
    Float apx, apy, apz;
    Float avx, avy, avz;
    Angle aroll;
} NJS_VIEW;
typedef struct {
    Float ratten, ipd;
    Float nrr, frr, cosi, cose, idev, odev;
    Float rate, intns;
    Int exp;
    Int reserve;
    NJS_POINT3 lpnt;
    NJS_VECTOR lvctr;
    NJS_VECTOR lmvctr;
    NJS_ARGB atten, amb, dif, spc;
    NJS_ARGB mamb, mdif, mspc;
} NJS_LIGHT_CAL;
typedef struct {
    Int lsrc;
    Float iamb, idif, ispc;
    Float nrang, frang;
    void *func;
    Angle iang, oang;
    NJS_ARGB argb;
} NJS_LIGHT_ATTR;
typedef struct {
    NJS_MATRIX mtrx;
    NJS_POINT3 pnt;
    NJS_VECTOR vctr;
    Int stat;
    Int reserve;
    NJS_LIGHT_CAL ltcal;
    NJS_LIGHT_ATTR attr;
} NJS_LIGHT;
typedef struct {
    NJS_ARGB ambient;
    NJS_ARGB diffuse;
    NJS_ARGB specular;
    Float exponent;
} NJS_LIGHT_MATERIAL;
typedef struct {
    Float px, py, pz;
    Float vx, vy, vz;
    Angle roll;
    Angle ang;
    Float n_clip;
    Float f_clip;
    NJS_VECTOR lx, ly;
} NJS_CAMERA;
typedef struct {
    NJS_CAMERA *camera;
    NJS_MOTION *motion;
} NJS_CACTION;
typedef struct NJS_VERTEX_BUF NJS_VERTEX_BUF;
struct nj_motion_info {
    void *mdata;
    void **p;
    Uint32 *nb;
    Float frame;
    Uint32 nbFrame;
    Uint32 factor;
    NJS_MATRIX *m;
};
struct nj_motlink_data_info {
    void *mdata;
    void **p;
    Uint32 *nb;
    Float frame;
    Uint32 nbFrame;
    Uint32 factor;
    Uint32 unk_18;
};
void njCreateLight(NJS_LIGHT *l, Int type);
void njDeleteLight(NJS_LIGHT *l);
void njSetLightDirection(NJS_LIGHT *l, Float x, Float y, Float z);
void njSetLightColor(NJS_LIGHT *l, Float r, Float g, Float b);
void njSetLightIntensity(NJS_LIGHT *l, Float spc, Float dif, Float amb);
void njSetLightAlpha(NJS_LIGHT *l, Float a);
void njSetLightAngle(NJS_LIGHT *l, Angle iang, Angle oang);
void njSetLightRange(NJS_LIGHT *l, Float nrang, Float frang);
void njSetLightLocation(NJS_LIGHT *l, Float x, Float y, Float z);
void njLightOn(NJS_LIGHT *l);
void njLightOff(NJS_LIGHT *l);
void njUnitLightMatrix(NJS_LIGHT *l);
void njTranslateLight(NJS_LIGHT *l, Float x, Float y, Float z);
void njTranslateLightV(NJS_LIGHT *l, NJS_VECTOR *v);
void njRotateLightX(NJS_LIGHT *l, Angle ang);
void njRotateLightY(NJS_LIGHT *l, Angle ang);
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal, Int reverse);
void njCheckLightMaterials(Int flags);
void njSetQueue(void);
void njSetLightMaterials(void);
void njCalcLightMatrices(void);
void njDrawModelSub(NJS_MODEL *volatile model);
void njResetQueue(void);
void njCalcLightMaterials(void);
void njGetLightDistance(NJS_POINT3 *point);
void njSetEasyLight(Float x, Float y, Float z);
void njSetEasyLightIntensity(Float inten, Float ambient);
void njSetEasyLightColor(Float r, Float g, Float b);
void njInitSystem(Int mode, Int frame, Int count);
void njChangeSystem(Int mode, Int frame, Int count);
void njExitSystem(void);
typedef Sint8 NJS_SYS_ATTR[192];
void njInit3D(NJS_VERTEX_BUF *vbuf, Int vn);
void njControl3D(Uint32 flag);
void njSetConstantAttr(Uint32 and_attr, Uint32 or_attr);
void njSetConstantMaterial(NJS_ARGB *mat);
void njSetDepthQueue(Float dnear, Float dfar);
void njInitMatrix(NJS_MATRIX *m, Sint32 n, Int flag);
void njInitShape(Float *buf);
extern Uint8 _nj_debug_char_[];
void njInitPrint(Uint32 *texture, Uint32 size, Uint32 attr);
void njExitPrint(void);
void njPrintSize(Uint16 size);
void njPrintColor(Uint32 c);
void njPrintC(Int loc, const char *s);
void njPrintD(Int loc, Int val, Int digit);
void njPrintB(Int loc, Uint32 val, Int digit);
void njPrintH(Int loc, Uint32 val, Int digit);
void njPrintF(Int loc, Float val, Int digit);
void njPrint(Int loc, const char *fmt, ...);
void njInitView(NJS_VIEW *v);
void njSetView(NJS_VIEW *v);
void njSetCamera(NJS_CAMERA *c);
void njPointCameraInterest(NJS_CAMERA *c, Float x, Float y, Float z);
void njRollCameraInterest(NJS_CAMERA *c, Angle ang);
void njSetCameraAngle(NJS_CAMERA *c, Angle ang);
void njRotateViewXRelative(NJS_VIEW *v, Angle ang);
void njRotateViewYRelative(NJS_VIEW *v, Angle ang);
void njRotateViewZRelative(NJS_VIEW *v, Angle ang);
void njTranslateViewRelative(NJS_VIEW *v, Float x, Float y, Float z);
void njRotateViewXAbsolute(NJS_VIEW *v, Angle ang);
void njRotateViewYAbsolute(NJS_VIEW *v, Angle ang);
void njRotateViewZAbsolute(NJS_VIEW *v, Angle ang);
void njTranslateViewAbsolute(NJS_VIEW *v, Float x, Float y, Float z);
void njSetScreen(NJS_SCREEN *s);
void njSetPerspective(Angle ang);
void njClipZ(Float n, Float f);
void njUserClipping(Int mode, NJS_POINT2 *p);
void njClearMatrix();
Bool njPushMatrix(NJS_MATRIX *m);
Bool njPopMatrix(Uint32 n);
void njUnitMatrix(NJS_MATRIX *m);
void njSetMatrix(NJS_MATRIX *md, NJS_MATRIX *ms);
void njGetMatrix(NJS_MATRIX *m);
void njMultiMatrix(NJS_MATRIX *md, NJS_MATRIX *ms);
void njTranslate(NJS_MATRIX *m, Float x, Float y, Float z);
void njTranslateV(NJS_MATRIX *m, NJS_VECTOR *v);
void njRotate(NJS_MATRIX *m, NJS_VECTOR *v, Angle ang);
void njRotateX(NJS_MATRIX *m, Angle ang);
void njRotateY(NJS_MATRIX *m, Angle ang);
void njRotateZ(NJS_MATRIX *m, Angle ang);
void njRotateXYZ(NJS_MATRIX *m, Angle angx, Angle angy, Angle angz);
void njRotateZXY(NJS_MATRIX *m, Angle angx, Angle angy, Angle angz);
Bool njInvertMatrix(NJS_MATRIX *m);
Float njDetMatrix(NJS_MATRIX *m);
void njScale(NJS_MATRIX *m, Float sx, Float sy, Float sz);
void njScaleV(NJS_MATRIX *m, NJS_VECTOR *v);
void njMirror(NJS_MATRIX *m, NJS_PLANE *pl);
void njAddVector(NJS_VECTOR *vd, NJS_VECTOR *vs);
void njSubVector(NJS_VECTOR *vd, NJS_VECTOR *vs);
void njCalcPoint(NJS_MATRIX *m, NJS_POINT3 *ps, NJS_POINT3 *pd);
void njCalcVector(NJS_MATRIX *m, NJS_VECTOR *vs, NJS_VECTOR *vd);
void njGetTranslation(NJS_MATRIX *m, NJS_POINT3 *p);
void njProjectScreen(NJS_MATRIX *m, NJS_POINT3 *p3, NJS_POINT2 *p2);
Float njScalor(NJS_VECTOR *v);
Float njScalor2(NJS_VECTOR *v);
Float njSin(Angle n);
Float njSqrt(Float n);
Float njInvertSqrt(Float n);
Float njCos(Angle n);
Float njTan(Angle n);
void njLinear(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame);
Float njUnitVector(NJS_VECTOR *v);
Float njInnerProduct(NJS_VECTOR *v1, NJS_VECTOR *v2);
Float njOuterProduct(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *ov);
void njGetPlaneNormal2(NJS_POINT3 *p0, NJS_POINT3 *p1, NJS_POINT3 *p2,
                       NJS_VECTOR *v);
Float njDistanceP2P(NJS_POINT3 *p1, NJS_POINT3 *p2);
Float njDistanceP2L(NJS_POINT3 *p, NJS_LINE *l, NJS_POINT3 *cp);
Float njDistanceP2PL(NJS_POINT3 *p, NJS_PLANE *pl, NJS_POINT3 *cp);
Float njDistanceL2PL(NJS_LINE *l, NJS_PLANE *pl, NJS_POINT3 *cp);
Float njDistancePL2PL(NJS_PLANE *pl1, NJS_PLANE *pl2, NJS_LINE *l);
Bool njIsParalellL2PL(NJS_LINE *l, NJS_PLANE *pl);
Bool njIsParalellPL2PL(NJS_PLANE *pl1, NJS_PLANE *pl2);
Float njFraction(Float n);
extern Float FracInt;
Float njRoundOff(Float n);
Int njCollisionCheckSS(NJS_SPHERE *sphere1, NJS_SPHERE *sphere2);
void njSetMotionCallback(void (*func)(NJS_OBJECT *obj));
void njSimpleDrawModel(NJS_MODEL *model);
void njSimpleDrawObject(NJS_OBJECT *obj);
Sint32 njSimpleCalcModel(NJS_MODEL *model);
void njSimpleDrawModelSub(NJS_MODEL *model);
void njSimpleDrawObjectSub(NJS_OBJECT *obj);
void njSimpleAction(NJS_ACTION *action, Float frame);
void njSimpleDrawMotion(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njSimpleDrawShapeMotion(NJS_OBJECT *obj, NJS_MOTION *motion,
                             NJS_MOTION *shape, Float frame);
void njSimpleActionOld(NJS_ACTION *action, Float frame);
void njSimpleDrawMotionOld(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njSimpleDrawShapeMotionOld(NJS_OBJECT *obj, NJS_MOTION *motion,
                                NJS_MOTION *shape, Float frame);
void njSimpleActionLink(NJS_ACTION_LINK *actionlink, Float rate);
void njSimpleDrawMotionLink(NJS_OBJECT *object, NJS_MOTION_LINK *motionlink,
                            Float rate);
void njSimpleDrawShapeMotionLink(NJS_OBJECT *object,
                                 NJS_MOTION_LINK *motionlink,
                                 NJS_MOTION_LINK *shapelink, Float rate);
void njSimpleActionLinkOld(NJS_ACTION_LINK *actionlink, Float rate);
void njSimpleDrawMotionLinkOld(NJS_OBJECT *object, NJS_MOTION_LINK *motionlink,
                               Float rate);
void njSimpleDrawShapeMotionLinkOld(NJS_OBJECT *object,
                                    NJS_MOTION_LINK *motionlink,
                                    NJS_MOTION_LINK *shapelink, Float rate);
void njGetkmPointer(void);
void njSetkmPointer(void);
void njSetEORflag();
void njSetkmColorMode(Uint32 mode);
void *njStartVertexNonTexOpaque(void);
void *njStartVertexNonTexTrans(void);
void *njStartVertexTexOpaque(void);
void *njStartVertexTexTrans(void);
void *njStartVertexNonTexOpaqueIntens(Uint32 *color);
void *njStartVertexNonTexTransIntens(Uint32 *color);
void *njStartVertexTexOpaqueIntens(Uint32 *color);
void *njStartVertexTexTransIntens(Uint32 *color);
void njEndVertex(Uint32 *vertex);
Sint32 njSetkmTextureNum(Uint32 n);
void njSetkmModelAttr(Uint32 attr);
void njDrawModel(NJS_MODEL *model);
void njDrawObject(NJS_OBJECT *obj);
void njDrawMotion(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njAction(NJS_ACTION *action, Float frame);
void njDrawShapeMotion(NJS_OBJECT *obj, NJS_MOTION *motion, NJS_MOTION *shape,
                       Float frame);
void njDrawMotionOld(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njActionOld(NJS_ACTION *action, Float frame);
void njDrawShapeMotionOld(NJS_OBJECT *obj, NJS_MOTION *motion,
                          NJS_MOTION *shape, Float frame);
void njEasyDrawModel(NJS_MODEL *model);
void njEasyDrawObject(NJS_OBJECT *obj);
void njEasyDrawMotion(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njEasyAction(NJS_ACTION *action, Float frame);
void njEasyDrawShapeMotion(NJS_OBJECT *obj, NJS_MOTION *motion,
                           NJS_MOTION *shape, Float frame);
Int njFarClipping(NJS_POINT3COL *p, Int n);
Int njNearClipping(NJS_POINT3COL *in, Int n, NJS_POINT3COL *out, Uint32 attr);
Int njNearClippingLine(NJS_POINT3COL *in, NJS_POINT3COL *out, Uint32 attr);
void njtri_filled(Int n, NJS_POINT3COL *p, Float **vertex);
void njtri_filled_with_tex(Int n, NJS_POINT3COL *p, Float **vertex);
void njtri_wiredpoly(Int n, NJS_POINT3COL *p, Float **vertex);
void njtri_wiredpoly_with_tex(Int n, NJS_POINT3COL *p, Float **vertex);
void njGetDrawMotion(NJS_OBJECT *object, NJS_MOTION *motion,
                     NJS_MOTION_DATA *data, Float frame);
void njGetAction(NJS_ACTION *action, NJS_MOTION_DATA *data, Float frame);
void njCameraAction(NJS_CACTION *caction, Float frame);
void njCameraMotion(NJS_CAMERA *camera, NJS_MOTION *motion, Float frame);
void njCameraActionOld(NJS_CACTION *caction, Float frame);
void njCameraMotionOld(NJS_CAMERA *camera, NJS_MOTION *motion, Float frame);
void njDrawLine3D(NJS_POINT3COL *p, Int n, Uint32 attr);
void njDrawTriangle3D(NJS_POINT3COL *p, Int n, Uint32 attr);
void njDrawPolygon3D(NJS_POINT3COL *p, Int n, Uint32 attr);
void njDrawLine2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
void njDrawPolygon2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
void njDrawSprite2D(NJS_SPRITE *sp, Int n, Float pri, Uint32 attr);
void njDrawSprite3D(NJS_SPRITE *sp, Int n, Uint32 attr);
void njDrawPolygon(NJS_POLYGON_VTX *polygon, Int count, Int trans);
void njDrawTexture(NJS_TEXTURE_VTX *polygon, Int count, Int tex, Int flag);
void njDrawTextureMemList(NJS_TEXTURE_VTX *polygon, Int count, Int tex,
                          Int flag);
void njFogEnable(void);
void njFogDisable(void);
void njSetFogColor(Uint32 c);
void njSetFogDensity(Uint32 density);
Uint32 njGenerateFogDensity(Float f);
void njGenerateFogTable(NJS_FOG_TABLE fog);
void njGenerateFogTable3(NJS_FOG_TABLE fog, Float n, Float f);
void njSetFogTable(NJS_FOG_TABLE fog);
void njExecuteFade(Float f);
void njSetFadeColor(Uint32 c);
void njFadeEnable(void);
void njFadeDisable(void);
void njInitVertexBuffer(Sint32 op, Sint32 om, Sint32 tp, Sint32 tm, Sint32 pt);
void njSetVSyncFunction(void (*func)(void));
void njWaitVSync(void);
void njInitTextureBuffer(Sint8 *addr, Uint32 size);
void njInitTexture(NJS_TEXMEMLIST *addr, Uint32 n);
void njInitTextureGlobalIndex(Uint32 globalIndex);
void njExitTexture(void);
void njReleaseTextureAll(void);
void njGarbageTexture(NJS_TEXMEMLIST *addr, Uint32 n);
NJS_TEXERRSTAT *njGetTextureErrStat(void);
Uint32 njCalcTexture(Uint32 flag);
void njSetTexturePath(const char *path);
Sint32 njSetTexture(NJS_TEXLIST *texlist);
Sint32 njSetTextureNum(Uint32 n);
void njSetTextureMemorySize(Uint32 size);
Sint32 njLoadTexture(NJS_TEXLIST *texlist);
Sint32 njReleaseTexture(NJS_TEXLIST *texlist);
Sint32 njReleaseTextureNum(Uint32 n);
void njInitCacheTextureBuffer(Sint8 *addr, Uint32 size);
void njReleaseCacheTextureAll(void);
void njSetPvmTextureList(NJS_TEXLIST *texlist, NJS_TEXNAME *texname,
                         char *filename, Sint32 size);
Sint32 njLoadTexturePvmFile(const char *filename, NJS_TEXLIST *texlist);
Sint32 njLoadTexturePvmMemory(Uint8 *addr, NJS_TEXLIST *texlist);
void njSetTextureInfo(NJS_TEXINFO *info, Uint16 *tex, Sint32 type, Sint32 width,
                      Sint32 height);
void njSetTextureName(NJS_TEXNAME *texname, void *addr, Uint32 globalIndex,
                      Uint32 attr);
void *njCacheTextureMalloc(Uint32 size);
void njCacheTextureFree(void *addr);
Sint32 njSearchTexList(NJS_TEXMEMLIST *list, Uint32 n, Uint32 globalIndex);
void njFreeTexMemList(NJS_TEXMEMLIST *tex);
void njEntryTexMemList(Uint32 *handle, NJS_TEXINFO *info, Uint32 globalIndex,
                       Uint32 texaddr, Uint32 bank);
Sint32 njSearchTexList3(NJS_TEXMEMLIST *list, Uint32 n, Uint32 globalIndex,
                        Uint32 bank);
void njSetFlagAddrAllTexture(Uint32 globalIndex, Uint32 flag, void *addr);
NJS_TEXINFO *njTexMemList(Uint32 globalIndex);
Sint32 njCheckPaletteType(Uint32 type);
void njInitTextureErrStat(void);
Sint32 njTexFopen(const char *filename);
void njTexFclose(void);
Sint32 njTexFread(void *buf, Uint32 size);
void njTexFseek(Sint32 offset, Sint32 type);
Sint32 njCreateTextureSurface(NJS_TEXSURFACE *surface, Sint32 width,
                              Sint32 height, Sint32 type);
Sint32 njSetTexInfo(Sint32 *type, Sint32 width, Sint32 height, Sint32 bit,
                    Sint32 cn);
Sint32 njLoadTexMemFromFile(NJS_TEXNAME *texname, NJS_TEXINFO *info);
Sint32 njLoadCacheFromFile(NJS_TEXNAME *texname, NJS_TEXINFO *info);
Sint32 njLoadTexMemFromMemory(NJS_TEXNAME *texname, NJS_TEXINFO *info);
Sint32 njLoadTexMemFromCache(NJS_TEXNAME *texname, NJS_TEXINFO *info);
Sint32 njGetInfoMemory(NJS_TEXINFO *info);
Sint32 njGetSurfacePvr(NJS_TEXINFO *info, Uint32 attr, Sint32 *size);
Sint32 njGetInfoPvr(NJS_TEXINFO *info, Uint32 attr, Sint32 *size);
Sint32 njTexDownloadMipMap(void *tex, NJS_TEXINFO *info);
Sint32 njTexDownloadCache(void *tex, NJS_TEXINFO *info);
Sint32 njCheckFileName(char *path, char *name);
Sint32 njGetFileGlobalIndex(NJS_TEXNAME *texname);
Sint32 njGetFileTexType(void);
extern char fileext[][5];
extern Sint8 _nj_file_buffer[2048];
extern Sint8 *_nj_texture_buffer_st;
extern Uint32 _nj_texture_buffer_max_size;
Sint32 njLoadTextureLN(NJS_TEXLIST *texlist, Uint32 n);
Sint32 njReleaseTextureLN(Uint32 texaddr);
void njSetTextureParam(NJS_TEXMEMLIST *tex);
void njInitTexMemList(NJS_TEXMEMLIST *addr, Uint32 n);
void njSetPaletteBankLN(NJS_TEXMEMLIST *tex, Sint32 bank);
void njSetPaletteBank(Uint32 bank);
void strupr(char *s);
void njSetPaletteBankNum(Uint32 n, Sint32 bank);
void njSetPaletteBankNumG(Uint32 globalIndex, Sint32 bank);
void njSetPaletteMode(Uint32 mode);
Uint32 njGetPaletteMode(void);
void njSetPaletteData(Sint32 offset, Sint32 count, void *data);
void njGetPaletteData(Sint32 offset, Sint32 count, void *data);
Sint32 njLoadPaletteFile(const char *filename, NJS_TEXPALETTE *pl);
void njSetBackColor(Uint32 col1, Uint32 col2, Uint32 col3);
void njSetBorderColor(Uint32 color);
void njRenderTextureNum(Uint32 n);
void njRenderTextureNumG(Uint32 globalIndex);
void njSetRenderWidth(Uint32 nWidth);
void njFrameBufferBmp(char *bmp, char *buffer);
void njTextureFilterMode(Int mode);
void njTextureClampMode(Int mode);
void njTextureFlipMode(Int mode);
void njColorBlendingMode(Int target, Int mode);
void njSuperSampleMode(Int mode);
void njPolygonCullingMode(Int mode);
void njPolygonCullingSize(Float size);
void njMemCopy(void *dst, const void *src, Sint32 num);
void njMemCopy2(void *dst, const void *src, Sint32 num);
void njMemCopy4(void *dst, const void *src, Sint32 num);
extern NJS_MATRIX _unit_matrix_;
extern Float _nj_far_clip_;
extern NJS_MATRIX *_nj_current_matrix_ptr_;
extern NJS_MATRIX _nj_view_matrix_;
extern NJS_SCREEN _nj_screen_;
extern Int _nj_frame_mode_;
extern Int _nj_frame_size_w;
extern Int _nj_frame_size_h;
extern Float _nj_near_clip_;
extern Float _nj_scr_aspect_x_;
extern Float _nj_scr_aspect_y_;
extern Uint32 _nj_control_3d_flag_;
extern NJS_VERTEX_BUF *_nj_vertex_buf_;
extern Int _nj_vertex_num_;
extern Int _nj_calc_vertex_;
extern Int _nj_calc_polygon_;
extern Int _nj_draw_polygon_;
extern Uint32 _nj_constant_attr_and_;
extern Uint32 _nj_constant_attr_or_;
extern NJS_ARGB _nj_constant_material_;
extern Uint32 _nj_vsync_count_;
extern Float _nj_depth_near_;
extern Float _nj_depth_far_;
extern Float _nj_depth_range_;
extern Int _nj_depth_enable_;
extern Int _nj_matrix_flag_;
extern NJS_TEXLIST *_nj_current_texlist;
extern NJS_TEXMEMLIST *_nj_texmemlist;
extern Uint32 _nj_texmemsize;
extern Sint32 _nj_tex_count;
extern Uint32 _nj_current_texture;
extern Uint32 _nj_current_texture_bank;
extern char _nj_current_texture_path[256];
extern Uint32 _nj_tex_max_free_size;
extern Uint32 _nj_user_globalIndex;
extern NJS_TEXERRSTAT _nj_texerr_;
extern NJS_TEXSURFACE _nj_tex_err_surface;
extern struct tagKMVERTEXCONTEXT *_nj_current_ctx_;
extern NJS_LIGHT_MATERIAL _nj_light_material_;
extern struct nj_light_control {
    NJS_LIGHT *light[32];
    Int count;
} _nj_light_control_;
extern struct nj_light_queue {
    Int light[32];
    Int count;
} _nj_light_queue_;
void njLightSystemInit(void);
extern Uint32 _nj_wait_vsync_in_;
extern Uint32 _nj_wait_vsync_out_;
extern volatile Int _nj_eor_flag_;
extern Int _nj_display_mode_;
extern Int _nj_waitvsync_count;
extern NJS_POINT2 _nj_2d_clip_[2];
extern Uint32 _nj_vertex_buffer_op_;
extern Uint32 _nj_vertex_buffer_om_;
extern Uint32 _nj_vertex_buffer_tp_;
extern Uint32 _nj_vertex_buffer_tm_;
extern Uint32 _nj_vertex_buffer_pt_;
extern Uint32 _nj_vertex_buffer_size_;
extern Uint32 _nj_texture_memory_size;
extern Uint32 *_nj_usr_vertex_buffer_ptr_;
extern Uint32 _nj_usr_vertex_buffer_size_;
extern volatile Int _nj_render_flag_;
extern volatile Int _nj_eov_flag_;
extern volatile Int _nj_fatal_err_callback_;
extern void (*_nj_eor_function_)(void);
extern void (*_nj_motion_callback_)(NJS_OBJECT *obj);
extern struct nj_motion_info _nj_motion_data_info_;
extern struct nj_motion_info _nj_shape_data_info_;
extern void (*_nj_motion_data_func_)(NJS_OBJECT *obj);
extern void (*_nj_shape_data_func_)(NJS_OBJECT *obj);
extern void (*_nj_motion_data_func_table_[5])(NJS_OBJECT *obj);
extern void (*_nj_shape_data_func_table_[4])(NJS_OBJECT *obj);
extern void (*_nj_motion_translate_)(NJS_OBJECT *obj);
extern void (*_nj_motion_rotate_)(NJS_OBJECT *obj);
extern void (*_nj_motion_scale_)(NJS_OBJECT *obj);
extern void (*_nj_motion_shape_)(NJS_OBJECT *obj);
extern void (*_nj_shape_int_func_table_[2])(NJS_OBJECT *obj);
extern void (*_nj_draw_model_sub_)(NJS_MODEL *model);
extern void (*_nj_motion_int_f_func_)(NJS_MKEY_F *keys, Uint32 index, Uint32 nb,
                                      Float *out);
extern void (*_nj_motion_int_f_func_table_[2])(NJS_MKEY_F *keys, Uint32 index,
                                               Uint32 nb, Float *out);
extern void (*_nj_motion_int_a_func_)(NJS_MKEY_A *keys, Uint32 index, Uint32 nb,
                                      Angle *out);
extern void (*_nj_motion_int_a_func_table_[2])(NJS_MKEY_A *keys, Uint32 index,
                                               Uint32 nb, Angle *out);
extern void (*_nj_motion_int_a_func_table_old_[2])(NJS_MKEY_A *keys,
                                                   Uint32 index, Uint32 nb,
                                                   Angle *out);
enum { SHAPE_POINTS = 1, SHAPE_NORMALS = 2, SHAPE_BOTH = 3 };
extern Uint16 _nj_mot_data_cnt_;
extern Uint16 _nj_mot_data_type_;
extern Uint16 _nj_mot_spline_cnt_;
extern Uint16 _nj_mot_shape_data_cnt_;
extern Uint16 _nj_mot_shape_data_type_;
extern Uint16 _nj_mot_shape_spline_cnt_;
extern Float *_nj_shape_buf_;
void njMotionIntTranslate(NJS_OBJECT *obj);
void njMotionIntScale(NJS_OBJECT *obj);
void njMotionIntRotateXYZ(NJS_OBJECT *obj);
void njMotionIntRotateZXY(NJS_OBJECT *obj);
void njMotionObjTranslate(NJS_OBJECT *obj);
void njMotionObjRotateXYZ(NJS_OBJECT *obj);
void njMotionObjRotateZXY(NJS_OBJECT *obj);
void njMotionObjScale(NJS_OBJECT *obj);
extern Float *_nj_mot_pos_buf_ptr_;
extern Angle *_nj_mot_ang_buf_ptr_;
extern Float *_nj_mot_scl_buf_ptr_;
void njGetMotionIntTranslate(NJS_OBJECT *obj);
void njGetMotionIntScale(NJS_OBJECT *obj);
void njGetMotionIntRotate(NJS_OBJECT *obj);
void njGetMotionObjTranslate(NJS_OBJECT *obj);
void njGetMotionObjRotate(NJS_OBJECT *obj);
void njGetMotionObjScale(NJS_OBJECT *obj);
extern Uint16 _nj_mot_current_data_;
extern Float _nj_mot_current_frame_;
extern struct nj_motlink_data_info _nj_motlink_data_info_[2];
extern struct nj_motlink_data_info _nj_shapelink_data_info_[2];
extern Uint16 _nj_motlink_data_cnt_[2];
extern Uint16 _nj_motlink_data_type_[2];
extern Uint16 _nj_motlink_shape_data_cnt_[2];
extern Uint16 _nj_motlink_shape_data_type_[2];
extern void (*_nj_motlink_data_func_[2])(NJS_OBJECT *object);
extern void (*_nj_motlink_data_func_table_[5])(NJS_OBJECT *object);
extern void (*_nj_motion_translate_data_[2])(NJS_OBJECT *object);
extern void (*_nj_motion_rotate_data_[2])(NJS_OBJECT *object);
extern void (*_nj_motion_scale_data_[2])(NJS_OBJECT *object);
extern void (*_nj_shapelink_data_func_[2])(NJS_OBJECT *object);
extern void (*_nj_shapelink_data_func_table_[4])(NJS_OBJECT *object);
extern void (*_nj_motion_shape_data_[2])(NJS_OBJECT *object);
extern void (*_nj_shapelink_int_func_table[2])(NJS_OBJECT *object);
void njMotionIntTranslateData(NJS_OBJECT *object);
void njMotionIntRotateData(NJS_OBJECT *object);
void njMotionIntScaleData(NJS_OBJECT *object);
void njMotionObjTranslateData(NJS_OBJECT *object);
void njMotionObjRotateData(NJS_OBJECT *object);
void njMotionObjScaleData(NJS_OBJECT *object);
extern void (*_nj_motlink_int_f_func_table_[2])(NJS_MKEY_F *keys, Uint32 index,
                                                Uint32 nb, Float *out);
extern void (*_nj_motlink_int_a_func_table_[2])(NJS_MKEY_A *keys, Uint32 index,
                                                Uint32 nb, Angle *out);
extern void (*_nj_int_f_func_)(Float *values, Float *out, Float rate);
extern void (*_nj_int_a_func_)(Angle *values, Angle *out, Float rate);
extern void (*_nj_int_f_func_table_[2])(Float *values, Float *out, Float rate);
extern void (*_nj_int_a_func_table_[2])(Angle *values, Angle *out, Float rate);
extern void (*_nj_rotate_func_)(NJS_MATRIX *m, Angle angx, Angle angy,
                                Angle angz);
extern Uint16 _nj_pos_int_flag_;
extern Uint16 _nj_ang_int_flag_;
extern Uint16 _nj_scl_int_flag_;
extern Uint16 _nj_pnt_int_flag_;
extern Uint16 _nj_nml_int_flag_;
extern Float _nj_motion_link_pos_[12];
extern Float _nj_motion_link_scl_[12];
extern Angle _nj_motion_link_ang_[12];
extern NJS_POINT3 *_nj_shape_link_point_[4];
extern NJS_VECTOR *_nj_shape_link_normal_[4];
void njMakeMotionLink(void);
void njMakeShapeLink(NJS_OBJECT *object);
extern Float _nj_cnk_easy_multilight_buffer_[16];
extern NJS_TEXSURFACE _nj_framebuffer_surface0_;
extern NJS_TEXSURFACE _nj_framebuffer_surface1_;
void njInitSprite(void);
struct task_work;
void draw_action(NJS_ACTION *action, Float frame);
void draw_motion(NJS_OBJECT *object, NJS_MOTION *motion, Float frame);
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void draw_motion_link(NJS_OBJECT *object, NJS_MOTION_LINK *link, Float ratio);
void draw_shape_motion_link(NJS_OBJECT *object, NJS_MOTION_LINK *link,
                            NJS_MOTION_LINK *shape, Float ratio);
void draw_shape_motion(NJS_OBJECT *object, NJS_MOTION *motion,
                       NJS_MOTION *shape, Float frame);
void draw_set_material(Float alpha, Float red, Float green, Float blue);
void draw_line(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void draw_line_colored(Float x1, Float y1, Float z1, const NJS_COLOR *color1,
                       Float x2, Float y2, Float z2, const NJS_COLOR *color2);
void draw_line_v(NJS_POINT3 *from, NJS_POINT3 *to);
void draw_highlight_near(struct task_work *work, Sint16 characters);
extern Uint32 draw_palettes[8][256 * 2];
extern Uint32 draw_unlit_offsets[512];
extern int draw_debug_counts[20];
void draw_model_init(void);
void draw_model(NJS_MODEL *model);
void draw_model_nested(NJS_MODEL *model);
void draw_models_begin(void);
void draw_model_unculled(NJS_MODEL *model);
void draw_models_end(void);
Bool draw_in_view(Float x, Float y, Float z, Float radius);
void draw_set_light(Float x, Float y, Float z);
void draw_divide_light(Float scale);
void draw_reset_light(void);
void draw_set_palette(int palette);
void draw_take_point_lights(void);
void action_link_translate_keys(NJS_OBJECT *object);
void action_link_scale_keys(NJS_OBJECT *object);
void action_link_rotate_keys(NJS_OBJECT *object);
void action_link_translate_object(NJS_OBJECT *object);
void action_link_rotate_object(NJS_OBJECT *object);
void action_link_scale_object(NJS_OBJECT *object);
void action_link_motion_node_0(NJS_OBJECT *object);
void action_link_motion_node_1(NJS_OBJECT *object);
void action_link_motion_node_2(NJS_OBJECT *object);
void action_link_motion_node_3(NJS_OBJECT *object);
void action_link_motion_node_4(NJS_OBJECT *object);
void action_link_shape_node_0(NJS_OBJECT *object);
void action_link_shape_node_1(NJS_OBJECT *object);
void action_link_shape_node_2(NJS_OBJECT *object);
void FUN_8c0417c8(void);
void action_link_draw_morphed_model(NJS_OBJECT *object);
extern void (*action_link_motion_steps[])(NJS_OBJECT *obj);
extern void (*action_link_shape_steps[])(NJS_OBJECT *obj);
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_find_key(void *keys, Uint32 count, Uint32 *index)
{
    Uint32 frame;
    Uint32 low;
    Uint32 middle;
    Uint32 key;
    low = 0;
    frame = (Sint32)_nj_motlink_data_info_[_nj_mot_current_data_].frame;
    while (count - low - 1 > 0) {
        middle = (count + low) >> 1;
        key = ((const NJS_MKEY_F *)keys)[middle].keyframe;
        if (frame >= key) {
            low = middle;
        } else {
            count = middle;
        }
    }
    *index = low;
}
#else
void action_link_find_key(void *keys, Uint32 count, Uint32 *index)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_find_shape_key(NJS_MKEY_P *keys, Uint32 count,
                                       Uint32 *index)
{
    Uint32 frame;
    Uint32 low;
    Uint32 middle;
    Uint32 key;
    low = 0;
    frame = (Sint32)_nj_shapelink_data_info_[_nj_mot_current_data_].frame;
    while (count - low - 1 > 0) {
        middle = (count + low) >> 1;
        key = keys[middle].keyframe;
        if (frame >= key) {
            low = middle;
        } else {
            count = middle;
        }
    }
    *index = low;
}
#else
void action_link_find_shape_key(NJS_MKEY_P *keys, Uint32 count,
                                       Uint32 *index)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
Sint32 action_link_start_shape(NJS_MOTION_LINK *link, Sint32 slot)
{
    struct nj_motlink_data_info *info;
    NJS_MOTION *motion;
    Uint16 morphs;
    Uint16 type;
    info = &_nj_shapelink_data_info_[slot];
    motion = link->motion[slot];
    morphs = 0;
    type = 0;
    if (motion != ((void *)0)) {
        if (link->frame[slot] >= (Float)(Sint32)motion->nbFrame) {
            return 1;
        }
        info->frame = link->frame[slot];
        info->mdata = motion->mdata;
        info->nbFrame = motion->nbFrame;
        type = motion->type;
        _nj_mot_shape_spline_cnt_ = (motion->inp_fn & 0xc0) > 0;
    }
    info->factor = 0;
    info->unk_18 = 0;
    if (type & 0x10) {
        morphs = SHAPE_POINTS;
    }
    if (type & 0x20) {
        morphs += SHAPE_NORMALS;
    }
    _nj_shapelink_data_func_[slot] = action_link_shape_steps[morphs];
    _nj_motlink_shape_data_type_[slot] = 0;
    _nj_motlink_shape_data_cnt_[slot] = morphs;
    _nj_motlink_shape_data_type_[slot] = type;
    return 0;
}
#else
Sint32 action_link_start_shape(NJS_MOTION_LINK *link, Sint32 slot)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38;
    return asm_stub[0];
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
Sint32 action_link_start_motion(NJS_MOTION_LINK *link, Sint32 slot)
{
    struct nj_motlink_data_info *info;
    NJS_MOTION *motion;
    Uint16 type;
    Uint16 count;
    info = &_nj_motlink_data_info_[slot];
    motion = link->motion[slot];
    type = 0;
    count = 0;
    if (motion != ((void *)0)) {
        if (link->frame[slot] >= (Float)(Sint32)motion->nbFrame) {
            return 1;
        }
        info->frame = link->frame[slot];
        info->mdata = motion->mdata;
        info->nbFrame = motion->nbFrame;
        count = motion->inp_fn & ~0xc0;
        type = motion->type;
    }
    link = 0;
    info->factor = (Uint32)link;
    info->unk_18 = (Uint32)link;
    _nj_motlink_data_cnt_[slot] = count;
    _nj_motlink_data_type_[slot] = type;
    return (Sint32)link;
}
#else
Sint32 action_link_start_motion(NJS_MOTION_LINK *link, Sint32 slot)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27;
    return asm_stub[0];
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_select_steps(NJS_OBJECT *object, Sint32 slot)
{
    Uint32 type;
    void (*rotate)(NJS_MATRIX *matrix, Angle angx, Angle angy, Angle angz);
    void (*step)(NJS_OBJECT *obj);
    _nj_motlink_data_func_[slot] =
        action_link_motion_steps[_nj_motlink_data_cnt_[slot]];
    rotate = njRotateXYZ;
    if (object->evalflags & 0x20) {
        rotate = njRotateZXY;
    }
    _nj_rotate_func_ = rotate;
    type = _nj_motlink_data_type_[slot];
    step = action_link_translate_object;
    if (type & 0x1) {
        step = action_link_translate_keys;
    }
    _nj_motion_translate_data_[slot] = step;
    step = action_link_rotate_object;
    if (type & 0x2) {
        step = action_link_rotate_keys;
    }
    _nj_motion_rotate_data_[slot] = step;
    step = action_link_scale_object;
    if (type & 0x4) {
        step = action_link_scale_keys;
    }
    _nj_motion_scale_data_[slot] = step;
}
#else
void action_link_select_steps(NJS_OBJECT *object, Sint32 slot)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void link_linear_vector(NJS_MKEY_F *keys, Uint32 index,
                                      Uint32 count, Float *out)
{
    NJS_MKEY_F *key;
    Float *from;
    Float *to;
    Float weight;
    Float rest;
    Float inverse;
    Float ax;
    Float ay;
    Float az;
    Float bx;
    Float by;
    Float bz;
    Sint32 span;
    key = &keys[index];
    if (index + 1 < count) {
        keys = key + 1;
    }
    weight = _nj_motlink_data_info_[_nj_mot_current_data_].frame -
             (Float)(Sint32)key->keyframe;
    span = (Sint32)keys->keyframe - (Sint32)key->keyframe;
    if (span > 0) {
        inverse = (Float)span;
        inverse = _builtin_fsrra(inverse);
        inverse *= inverse;
        weight *= inverse;
    }
    rest = 1.0F;
    rest -= weight;
    from = key->key;
    to = keys->key;
    ax = *from++;
    ax *= rest;
    bx = *to++;
    bx *= weight;
    ax += bx;
    ay = *from++;
    ay *= rest;
    by = *to++;
    by *= weight;
    ay += by;
    az = *from;
    az *= rest;
    bz = *to;
    bz *= weight;
    az += bz;
    out += 3;
    *--out = az;
    *--out = ay;
    *--out = ax;
}
#else
void link_linear_vector(NJS_MKEY_F *keys, Uint32 index,
                                      Uint32 count, Float *out)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void link_linear_angles(NJS_MKEY_A *keys, Uint32 index,
                                      Uint32 count, Angle *out)
{
    NJS_MKEY_A *key;
    Float weight;
    Float rest;
    Float inverse;
    Sint32 span;
    key = &keys[index];
    if (index + 1 < count) {
        keys = key + 1;
    }
    weight = _nj_motlink_data_info_[_nj_mot_current_data_].frame -
             (Float)(Sint32)key->keyframe;
    span = (Sint32)keys->keyframe - (Sint32)key->keyframe;
    if (span > 0) {
        inverse = (Float)span;
        inverse = _builtin_fsrra(inverse);
        inverse *= inverse;
        weight *= inverse;
    }
    rest = 1.0F - weight;
    out[0] =
        (Angle)(((Float)key->key[0] * rest) + ((Float)keys->key[0] * weight));
    out[1] =
        (Angle)(((Float)key->key[1] * rest) + ((Float)keys->key[1] * weight));
    out[2] =
        (Angle)(((Float)key->key[2] * rest) + ((Float)keys->key[2] * weight));
}
#else
void link_linear_angles(NJS_MKEY_A *keys, Uint32 index,
                                      Uint32 count, Angle *out)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_translate_keys(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    Float *out;
    Float *from;
    NJS_MKEY_F *keys;
    Uint32 factor;
    Uint32 count;
    Uint32 index;
    Float x;
    Float y;
    Float z;
    info = &_nj_motlink_data_info_[_nj_mot_current_data_];
    out = &_nj_motion_link_pos_[_nj_mot_current_data_ * 3];
    factor = info->factor;
    keys = info->p[factor];
    if (keys != ((void *)0)) {
        count = info->nb[factor];
        action_link_find_key(keys, count, &index);
        link_linear_vector(keys, index, count, out);
        _nj_pos_int_flag_ |= _nj_mot_current_data_ + 1;
    } else {
        from = object->pos;
        x = *from++;
        y = *from++;
        z = *from;
        out += 3;
        *--out = z;
        *--out = y;
        *--out = x;
    }
    info->factor = factor + 1;
}
#else
void action_link_translate_keys(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_scale_keys(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    Float *out;
    Float *from;
    NJS_MKEY_F *keys;
    Uint32 factor;
    Uint32 count;
    Uint32 index;
    Float x;
    Float y;
    Float z;
    info = &_nj_motlink_data_info_[_nj_mot_current_data_];
    out = &_nj_motion_link_scl_[_nj_mot_current_data_ * 3];
    factor = info->factor;
    keys = info->p[factor];
    if (keys != ((void *)0)) {
        count = info->nb[factor];
        action_link_find_key(keys, count, &index);
        link_linear_vector(keys, index, count, out);
        _nj_scl_int_flag_ |= _nj_mot_current_data_ + 1;
    } else {
        from = object->scl;
        x = *from++;
        y = *from++;
        z = *from;
        out += 3;
        *--out = z;
        *--out = y;
        *--out = x;
    }
    info->factor = factor + 1;
}
#else
void action_link_scale_keys(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_rotate_keys(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    Angle *out;
    Angle *from;
    NJS_MKEY_A *keys;
    Uint32 factor;
    Uint32 count;
    Uint32 index;
    info = &_nj_motlink_data_info_[_nj_mot_current_data_];
    out = &_nj_motion_link_ang_[_nj_mot_current_data_ * 3];
    factor = info->factor;
    keys = info->p[factor];
    if (keys != ((void *)0)) {
        count = info->nb[factor];
        action_link_find_key(keys, count, &index);
        link_linear_angles(keys, index, count, out);
        _nj_ang_int_flag_ |= _nj_mot_current_data_ + 1;
    } else {
        from = object->ang;
        out[0] = from[0];
        out[1] = from[1];
        out[2] = from[2];
    }
    info->factor = factor + 1;
}
#else
void action_link_rotate_keys(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
Float action_link_sample_shape(NJS_MKEY_P *keys, Uint32 index,
                                      Uint32 count, NJS_POINT3 **data)
{
    NJS_MKEY_P *key;
    NJS_MKEY_P *before;
    NJS_MKEY_P *next;
    Float weight;
    Float inverse;
    Sint32 span;
    key = &keys[index];
    before = &keys[count - 1];
    if (index > 0) {
        before = key - 1;
    }
    next = keys;
    if (index + 1 < count) {
        next = key + 1;
    }
    if (index + 2 < count) {
        keys = next + 1;
    }
    weight = _nj_shapelink_data_info_[_nj_mot_current_data_].frame -
             (Float)(Sint32)key->keyframe;
    span = (Sint32)next->keyframe - (Sint32)key->keyframe;
    if (span > 0) {
        inverse = (Float)span;
        inverse = _builtin_fsrra(inverse);
        inverse *= inverse;
        weight *= inverse;
    }
    data[0] = before->key;
    data[1] = key->key;
    data[2] = next->key;
    data[3] = keys->key;
    return weight;
}
#else
Float action_link_sample_shape(NJS_MKEY_P *keys, Uint32 index,
                                      Uint32 count, NJS_POINT3 **data)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    return asm_stub[0];
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_blend_normal(Float *first, Float *second, Float *out,
                                     Float weight)
{
    Float rest;
    Float x;
    Float y;
    Float z;
    Float term;
    Float length;
    rest = 1.0F - weight;
    x = *first++;
    x *= rest;
    term = *second++;
    term *= weight;
    x += term;
    y = *first++;
    y *= rest;
    term = *second++;
    term *= weight;
    y += term;
    z = *first;
    z *= rest;
    term = *second;
    term *= weight;
    z += term;
    length = squared_length(x, y, z, 0.0F);
    if (length > 0.00001F) {
        length = _builtin_fsrra(length);
        x *= length;
        y *= length;
        z *= length;
    } else {
        x = 0.0F;
        y = 0.0F;
        z = 1.0F;
    }
    out += 3;
    *--out = z;
    *--out = y;
    *--out = x;
}
#else
void action_link_blend_normal(Float *first, Float *second, Float *out,
                                     Float weight)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_blend_point(Float *first, Float *second, Float *out,
                                    Float weight)
{
    Float rest;
    Float x;
    Float y;
    Float z;
    Float term;
    out += 3;
    rest = 1.0F - weight;
    x = *first++;
    x *= rest;
    term = *second++;
    term *= weight;
    x += term;
    y = *first++;
    y *= rest;
    term = *second++;
    term *= weight;
    y += term;
    z = *first;
    z *= rest;
    term = *second;
    term *= weight;
    z += term;
    *--out = z;
    *--out = y;
    *--out = x;
}
#else
void action_link_blend_point(Float *first, Float *second, Float *out,
                                    Float weight)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_get_shape_points(Uint32 *keyed, Float *weight,
                                         NJS_POINT3 **data, NJS_POINT3 *buffer)
{
    struct nj_motlink_data_info *info;
    NJS_MKEY_P *keys;
    Uint32 factor;
    Uint32 count;
    Uint32 index;
    info = &_nj_shapelink_data_info_[_nj_mot_current_data_];
    factor = info->factor;
    keys = info->p[factor];
    if (keys != ((void *)0)) {
        count = info->nb[factor];
        action_link_find_shape_key(keys, count, &index);
        *weight = action_link_sample_shape(keys, index, count, data);
        _nj_shape_link_point_[_nj_mot_current_data_] = buffer;
        _nj_pnt_int_flag_ |= _nj_mot_current_data_ + 1;
        *keyed = _nj_motlink_shape_data_cnt_[_nj_mot_current_data_];
    }
}
#else
void action_link_get_shape_points(Uint32 *keyed, Float *weight,
                                         NJS_POINT3 **data, NJS_POINT3 *buffer)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_get_shape_normals(Uint32 *keyed, Float *weight,
                                          NJS_POINT3 **data, NJS_POINT3 *buffer)
{
    struct nj_motlink_data_info *info;
    NJS_MKEY_P *keys;
    Uint32 factor;
    Uint32 count;
    Uint32 index;
    info = &_nj_shapelink_data_info_[_nj_mot_current_data_];
    factor = info->factor;
    keys = info->p[factor];
    if (keys != ((void *)0)) {
        count = info->nb[factor];
        action_link_find_shape_key(keys, count, &index);
        *weight = action_link_sample_shape(keys, index, count, data);
        _nj_shape_link_normal_[_nj_mot_current_data_] = buffer;
        _nj_nml_int_flag_ |= _nj_mot_current_data_ + 1;
        *keyed = _nj_motlink_shape_data_cnt_[_nj_mot_current_data_];
    }
}
#else
void action_link_get_shape_normals(Uint32 *keyed, Float *weight,
                                          NJS_POINT3 **data, NJS_POINT3 *buffer)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_get_both_points(Uint32 *keyed, Float *weight,
                                        NJS_POINT3 **data, NJS_POINT3 *buffer)
{
    struct nj_motlink_data_info *info;
    NJS_MKEY_P *keys;
    Uint32 factor;
    Uint32 count;
    Uint32 index;
    info = &_nj_shapelink_data_info_[_nj_mot_current_data_];
    factor = info->factor;
    keys = info->p[factor];
    if (keys != ((void *)0)) {
        count = info->nb[factor];
        action_link_find_shape_key(keys, count, &index);
        *weight = action_link_sample_shape(keys, index, count, data);
        _nj_shape_link_point_[_nj_mot_current_data_] = buffer;
        _nj_pnt_int_flag_ |= _nj_mot_current_data_ + 1;
        *keyed += SHAPE_POINTS;
    }
}
#else
void action_link_get_both_points(Uint32 *keyed, Float *weight,
                                        NJS_POINT3 **data, NJS_POINT3 *buffer)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_get_both_normals(Uint32 *keyed, Float *weight,
                                         NJS_POINT3 **data, NJS_POINT3 *buffer)
{
    struct nj_motlink_data_info *info;
    NJS_MKEY_P *keys;
    Uint32 factor;
    Uint32 count;
    Uint32 index;
    info = &_nj_shapelink_data_info_[_nj_mot_current_data_];
    factor = info->factor;
    keys = info->p[factor];
    if (keys != ((void *)0)) {
        count = info->nb[factor];
        action_link_find_shape_key(keys, count, &index);
        *weight = action_link_sample_shape(keys, index, count, data);
        _nj_shape_link_normal_[_nj_mot_current_data_] = buffer;
        _nj_nml_int_flag_ |= _nj_mot_current_data_ + 1;
        *keyed += SHAPE_NORMALS;
    }
}
#else
void action_link_get_both_normals(Uint32 *keyed, Float *weight,
                                         NJS_POINT3 **data, NJS_POINT3 *buffer)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0412c8(NJS_POINT3 **data, NJS_POINT3 *out,
                                      Float weight, Sint32 count)
{
    NJS_POINT3 *first;
    NJS_POINT3 *second;
    Sint32 left;
    first = data[1];
    second = data[2];
    left = count;
    do {
        action_link_blend_normal(&first->x, &second->x, &out->x, weight);
        first++;
        second++;
        out++;
    } while (--left != 0);
}
#else
void FUN_8c0412c8(NJS_POINT3 **data, NJS_POINT3 *out,
                                      Float weight, Sint32 count)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c041340(struct task *task)
{
}
#else
void FUN_8c041340(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_morph_model(NJS_OBJECT *object)
{
    NJS_POINT3 *point_data[4];
    NJS_POINT3 *normal_data[4];
    Float point_weight;
    Float normal_weight;
    Uint32 keyed;
    NJS_MODEL *model;
    NJS_POINT3 *points;
    NJS_POINT3 *normals;
    Sint32 count;
    Sint32 offset;
    model = object->model;
    if (model == ((void *)0)) {
        return;
    }
    if (object->evalflags & 0x08) {
        return;
    }
    keyed = 0;
    count = object->model->nbPoint;
    offset = _nj_mot_current_data_ * count * 6;
    points = (NJS_POINT3 *)&_nj_shape_buf_[offset];
    normals = (NJS_POINT3 *)&_nj_shape_buf_[(count * 3) + offset];
    _nj_shape_link_point_[_nj_mot_current_data_] = model->points;
    _nj_shape_link_normal_[_nj_mot_current_data_] = model->normals;
    switch (_nj_motlink_shape_data_cnt_[_nj_mot_current_data_]) {
    case SHAPE_POINTS:
        action_link_get_shape_points(&keyed, &point_weight, point_data, points);
        break;
    case SHAPE_NORMALS:
        action_link_get_shape_normals(&keyed, &normal_weight, normal_data,
                                      normals);
        break;
    case SHAPE_BOTH:
        action_link_get_both_points(&keyed, &point_weight, point_data, points);
        _nj_shapelink_data_info_[_nj_mot_current_data_].factor++;
        action_link_get_both_normals(&keyed, &normal_weight, normal_data,
                                     normals);
        break;
    }
    switch (keyed) {
    case SHAPE_POINTS:
        action_link_morph_points(point_data, points, point_weight, count);
        break;
    case SHAPE_NORMALS:
        FUN_8c0412c8(normal_data, normals, normal_weight, count);
        break;
    case SHAPE_BOTH:
        action_link_morph_points(point_data, points, point_weight, count);
        FUN_8c0412c8(normal_data, normals, normal_weight, count);
        break;
    }
}
#else
void action_link_morph_model(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56; asm_stub[1] = 57; asm_stub[2] = 58; asm_stub[3] = 59; asm_stub[4] = 60; asm_stub[5] = 61; asm_stub[6] = 62; asm_stub[7] = 63;
    asm_stub[0] = 64; asm_stub[1] = 65; asm_stub[2] = 66; asm_stub[3] = 67; asm_stub[4] = 68; asm_stub[5] = 69; asm_stub[6] = 70; asm_stub[7] = 71;
    asm_stub[0] = 72; asm_stub[1] = 73; asm_stub[2] = 74;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_translate_object(NJS_OBJECT *object)
{
    Float *from;
    Float *out;
    Float x;
    Float y;
    Float z;
    from = object->pos;
    out = &_nj_motion_link_pos_[_nj_mot_current_data_ * 3];
    x = *from++;
    y = *from++;
    z = *from;
    out += 3;
    *--out = z;
    *--out = y;
    *--out = x;
}
#else
void action_link_translate_object(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_rotate_object(NJS_OBJECT *object)
{
    Angle *from;
    Angle *out;
    Angle x;
    Angle y;
    Angle z;
    from = object->ang;
    out = &_nj_motion_link_ang_[_nj_mot_current_data_ * 3];
    x = from[0];
    y = from[1];
    z = from[2];
    out[0] = x;
    out[1] = y;
    out[2] = z;
}
#else
void action_link_rotate_object(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_scale_object(NJS_OBJECT *object)
{
    Float *from;
    Float *out;
    Float x;
    Float y;
    Float z;
    from = object->scl;
    out = &_nj_motion_link_scl_[_nj_mot_current_data_ * 3];
    x = *from++;
    y = *from++;
    z = *from;
    out += 3;
    *--out = z;
    *--out = y;
    *--out = x;
}
#else
void action_link_scale_object(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_motion_node_0(NJS_OBJECT *object)
{
    _nj_motion_translate_data_[_nj_mot_current_data_](object);
    _nj_motion_rotate_data_[_nj_mot_current_data_](object);
    _nj_motion_scale_data_[_nj_mot_current_data_](object);
}
#else
void action_link_motion_node_0(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_motion_node_1(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    NJS_MDATA1 *record;
    info = &_nj_motlink_data_info_[_nj_mot_current_data_];
    record = info->mdata;
    info->p = record->p;
    info->nb = record->nb;
    info->factor = 0;
    _nj_motion_translate_data_[_nj_mot_current_data_](object);
    _nj_motion_rotate_data_[_nj_mot_current_data_](object);
    _nj_motion_scale_data_[_nj_mot_current_data_](object);
    info->mdata = record + 1;
}
#else
void action_link_motion_node_1(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_motion_node_2(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    NJS_MDATA2 *record;
    info = &_nj_motlink_data_info_[_nj_mot_current_data_];
    record = info->mdata;
    info->p = record->p;
    info->nb = record->nb;
    info->factor = 0;
    _nj_motion_translate_data_[_nj_mot_current_data_](object);
    _nj_motion_rotate_data_[_nj_mot_current_data_](object);
    _nj_motion_scale_data_[_nj_mot_current_data_](object);
    info->mdata = record + 1;
}
#else
void action_link_motion_node_2(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_motion_node_3(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    NJS_MDATA3 *record;
    info = &_nj_motlink_data_info_[_nj_mot_current_data_];
    record = info->mdata;
    info->p = record->p;
    info->nb = record->nb;
    info->factor = 0;
    _nj_motion_translate_data_[_nj_mot_current_data_](object);
    _nj_motion_rotate_data_[_nj_mot_current_data_](object);
    _nj_motion_scale_data_[_nj_mot_current_data_](object);
    info->mdata = record + 1;
}
#else
void action_link_motion_node_3(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_motion_node_4(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    NJS_MDATA4 *record;
    info = &_nj_motlink_data_info_[_nj_mot_current_data_];
    record = info->mdata;
    info->p = record->p;
    info->nb = record->nb;
    info->factor = 0;
    _nj_motion_translate_data_[_nj_mot_current_data_](object);
    _nj_motion_rotate_data_[_nj_mot_current_data_](object);
    _nj_motion_scale_data_[_nj_mot_current_data_](object);
    info->mdata = record + 1;
}
#else
void action_link_motion_node_4(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_shape_node_0(NJS_OBJECT *object)
{
    NJS_MODEL *model;
    model = object->model;
    if (model != ((void *)0) && !(object->evalflags & 0x08)) {
        _nj_shape_link_point_[_nj_mot_current_data_] = model->points;
        _nj_shape_link_normal_[_nj_mot_current_data_] = model->normals;
    }
}
#else
void action_link_shape_node_0(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_shape_node_1(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    NJS_MDATA1 *record;
    info = &_nj_shapelink_data_info_[_nj_mot_current_data_];
    record = info->mdata;
    info->p = record->p;
    info->nb = record->nb;
    info->factor = 0;
    action_link_morph_model(object);
    info->mdata = record + 1;
}
#else
void action_link_shape_node_1(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_shape_node_2(NJS_OBJECT *object)
{
    struct nj_motlink_data_info *info;
    NJS_MDATA2 *record;
    info = &_nj_shapelink_data_info_[_nj_mot_current_data_];
    record = info->mdata;
    info->p = record->p;
    info->nb = record->nb;
    info->factor = 0;
    action_link_morph_model(object);
    info->mdata = record + 1;
}
#else
void action_link_shape_node_2(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0417c8(void)
{
    Float position[3];
    Float scale[3];
    Angle angle[3];
    Float *from;
    Float *to;
    Float *out;
    Angle *angle_from;
    Angle *angle_to;
    Float *base;
    Float ax;
    Float ay;
    Float az;
    Float bx;
    Float by;
    Float bz;
    Float weight;
    Float rest;
    Float one;
    Angle x;
    Angle y;
    Angle z;
    one = 1.0F;
    from = base = _nj_motion_link_pos_;
    if (_nj_pos_int_flag_ > 0) {
        ax = *from++;
        weight = _nj_mot_current_frame_;
        rest = one - weight;
        to = base + 3;
        ax *= rest;
        bx = *to++;
        ax += bx * weight;
        ay = *from++;
        ay *= rest;
        by = *to++;
        ay += by * weight;
        az = *from;
        az *= rest;
        bz = *to;
        az += bz * weight;
    } else {
        ax = *from++;
        ay = *from++;
        az = *from;
    }
    out = position + 3;
    *--out = az;
    *--out = ay;
    *--out = ax;
    angle_to = _nj_motion_link_ang_;
    if (_nj_ang_int_flag_ > 0) {
        weight = _nj_mot_current_frame_;
        rest = one - weight;
        angle_from = angle_to;
        angle_to += 3;
        x = (Angle)(((Float)angle_from[0] * rest) +
                    ((Float)angle_to[0] * weight));
        y = (Angle)(((Float)angle_from[1] * rest) +
                    ((Float)angle_to[1] * weight));
        z = (Angle)(((Float)angle_from[2] * rest) +
                    ((Float)angle_to[2] * weight));
    } else {
        x = *angle_to++;
        y = *angle_to++;
        z = *angle_to;
    }
    angle[0] = x;
    angle[1] = y;
    angle[2] = z;
    if (_nj_scl_int_flag_ > 0) {
        weight = _nj_mot_current_frame_;
        rest = one - weight;
        from = to = base;
        to += 3;
        ax = *from;
        from++;
        ax *= rest;
        bx = *to++;
        bx *= weight;
        ax = bx + ax;
        ay = *from++;
        ay *= rest;
        by = *to++;
        by *= weight;
        ay += by;
        az = *from;
        az *= rest;
        bz = *to;
        az += bz * weight;
    } else {
        from = _nj_motion_link_scl_;
        ax = *from++;
        ay = *from++;
        az = *from;
    }
    out = scale + 3;
    *--out = az;
    *--out = ay;
    *--out = ax;
    from = position;
    ax = *from++;
    ay = *from++;
    az = *from;
    njTranslate(((void *)0), ax, ay, az);
    angle_from = angle;
    x = angle_from[0];
    y = angle_from[1];
    z = angle_from[2];
    _nj_rotate_func_(((void *)0), x, y, z);
    from = scale;
    ax = *from++;
    ay = *from++;
    az = *from;
    njScale(((void *)0), ax, ay, az);
}
#else
void FUN_8c0417c8(void)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56; asm_stub[1] = 57; asm_stub[2] = 58; asm_stub[3] = 59; asm_stub[4] = 60; asm_stub[5] = 61; asm_stub[6] = 62; asm_stub[7] = 63;
    asm_stub[0] = 64; asm_stub[1] = 65; asm_stub[2] = 66; asm_stub[3] = 67; asm_stub[4] = 68; asm_stub[5] = 69; asm_stub[6] = 70; asm_stub[7] = 71;
    asm_stub[0] = 72; asm_stub[1] = 73; asm_stub[2] = 74; asm_stub[3] = 75; asm_stub[4] = 76; asm_stub[5] = 77; asm_stub[6] = 78; asm_stub[7] = 79;
    asm_stub[0] = 80; asm_stub[1] = 81; asm_stub[2] = 82; asm_stub[3] = 83;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_draw_morphed_model(NJS_OBJECT *object)
{
    NJS_MODEL *model;
    NJS_POINT3 *points;
    NJS_VECTOR *normals;
    NJS_POINT3 *first;
    NJS_POINT3 *second;
    NJS_POINT3 *out;
    NJS_POINT3 *out_normals;
    Sint32 count;
    Sint32 left;
    model = object->model;
    if (model == ((void *)0)) {
        return;
    }
    if (object->evalflags & 0x08) {
        return;
    }
    points = model->points;
    normals = model->normals;
    if (_nj_pnt_int_flag_ > 0 && _nj_nml_int_flag_ > 0) {
        first = _nj_shape_link_point_[0];
        second = _nj_shape_link_point_[1];
        count = model->nbPoint;
        out = (NJS_POINT3 *)&_nj_shape_buf_[count * 12];
        left = count;
        do {
            action_link_blend_point(&first->x, &second->x, &out->x,
                                    _nj_mot_current_frame_);
            first++;
            second++;
            out++;
        } while (--left != 0);
        first = _nj_shape_link_normal_[0];
        second = _nj_shape_link_normal_[1];
        count = model->nbPoint;
        out_normals = (NJS_POINT3 *)&_nj_shape_buf_[count * 15];
        left = count;
        do {
            action_link_blend_normal(&first->x, &second->x, &out_normals->x,
                                     _nj_mot_current_frame_);
            first++;
            second++;
            out_normals++;
        } while (--left != 0);
        model->points = out;
        model->normals = out_normals;
    }
    draw_model(model);
    model->points = points;
    model->normals = normals;
}
#else
void action_link_draw_morphed_model(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_draw_motion_tree(NJS_OBJECT *object)
{
    Uint32 flags;
    NJS_MATRIX *matrix;
    void (*rotate)(NJS_MATRIX *matrix, Angle angx, Angle angy, Angle angz);
    Float *from;
    Angle *angles;
    Float x;
    Float y;
    Float z;
    Angle angx;
    Angle angy;
    Angle angz;
    do {
        flags = object->evalflags;
        njPushMatrix(((void *)0));
        if (!(flags & 0x40)) {
            _nj_pos_int_flag_ = 0;
            _nj_ang_int_flag_ = 0;
            _nj_scl_int_flag_ = 0;
            _nj_mot_current_data_ = 0;
            _nj_motlink_data_func_[0](object);
            _nj_mot_current_data_ = 1;
            _nj_motlink_data_func_[1](object);
            FUN_8c0417c8();
        } else {
            matrix = _nj_motion_data_info_.m;
            from = object->pos;
            x = *from++;
            y = *from++;
            z = *from;
            njTranslate(matrix, x, y, z);
            rotate = njRotateXYZ;
            if (flags & 0x20) {
                rotate = njRotateZXY;
            }
            angles = object->ang;
            angx = angles[0];
            angy = angles[1];
            angz = angles[2];
            rotate(matrix, angx, angy, angz);
            from = object->scl;
            x = *from++;
            y = *from++;
            z = *from;
            njScale(matrix, x, y, z);
        }
        if (_nj_motion_callback_ != ((void *)0)) {
            _nj_motion_callback_(object);
        }
        if (object->model != ((void *)0) && !(flags & 0x08)) {
            draw_model(object->model);
        }
        if (object->child != ((void *)0)) {
            action_link_draw_motion_tree(object->child);
        }
        njPopMatrix(1);
        object = object->sibling;
    } while (object != ((void *)0));
}
#else
void action_link_draw_motion_tree(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void action_link_draw_shape_tree(NJS_OBJECT *object)
{
    Uint32 flags;
    NJS_MATRIX *matrix;
    void (*rotate)(NJS_MATRIX *matrix, Angle angx, Angle angy, Angle angz);
    Float *from;
    Angle *angles;
    Float x;
    Float y;
    Float z;
    Angle angx;
    Angle angy;
    Angle angz;
    do {
        flags = object->evalflags;
        njPushMatrix(((void *)0));
        if (!(flags & 0x40)) {
            _nj_pos_int_flag_ = 0;
            _nj_ang_int_flag_ = 0;
            _nj_scl_int_flag_ = 0;
            _nj_mot_current_data_ = 0;
            _nj_motlink_data_func_[0](object);
            _nj_mot_current_data_ = 1;
            _nj_motlink_data_func_[1](object);
            FUN_8c0417c8();
        } else {
            matrix = _nj_motion_data_info_.m;
            from = object->pos;
            x = *from++;
            y = *from++;
            z = *from;
            njTranslate(matrix, x, y, z);
            rotate = njRotateXYZ;
            if (flags & 0x20) {
                rotate = njRotateZXY;
            }
            angles = object->ang;
            angx = angles[0];
            angy = angles[1];
            angz = angles[2];
            rotate(matrix, angx, angy, angz);
            from = object->scl;
            x = *from++;
            y = *from++;
            z = *from;
            njScale(matrix, x, y, z);
        }
        if (_nj_motion_callback_ != ((void *)0)) {
            _nj_motion_callback_(object);
        }
        if (!(flags & 0x80)) {
            _nj_pnt_int_flag_ = 0;
            _nj_nml_int_flag_ = 0;
            _nj_mot_current_data_ = 0;
            _nj_shapelink_data_func_[0](object);
            _nj_mot_current_data_ = 1;
            _nj_shapelink_data_func_[1](object);
            action_link_draw_morphed_model(object);
        } else if (object->model != ((void *)0) && !(flags & 0x08)) {
            draw_model(object->model);
        }
        if (object->child != ((void *)0)) {
            action_link_draw_shape_tree(object->child);
        }
        njPopMatrix(1);
        object = object->sibling;
    } while (object != ((void *)0));
}
#else
void action_link_draw_shape_tree(NJS_OBJECT *object)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56; asm_stub[1] = 57; asm_stub[2] = 58; asm_stub[3] = 59; asm_stub[4] = 60; asm_stub[5] = 61; asm_stub[6] = 62; asm_stub[7] = 63;
    asm_stub[0] = 64; asm_stub[1] = 65; asm_stub[2] = 66; asm_stub[3] = 67; asm_stub[4] = 68;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio)
{
    NJS_OBJECT *object;
    NJS_MOTION_LINK *motions;
    if (ratio > 1.0F) {
        return;
    }
    motions = link->motionlink;
    object = link->object;
    _nj_mot_current_data_ = 0;
    _nj_mot_current_frame_ = ratio;
    if (action_link_start_motion(motions, 0)) {
        return;
    }
    if (action_link_start_motion(motions, 1)) {
        return;
    }
    action_link_select_steps(object, 0);
    action_link_select_steps(object, 1);
    njGetkmPointer();
    action_link_draw_motion_tree(object);
    njSetkmPointer();
}
#else
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void draw_motion_link(NJS_OBJECT *object, NJS_MOTION_LINK *link, Float ratio)
{
    if (ratio > 1.0F) {
        return;
    }
    _nj_mot_current_data_ = 0;
    _nj_mot_current_frame_ = ratio;
    if (action_link_start_motion(link, 0)) {
        return;
    }
    if (action_link_start_motion(link, 1)) {
        return;
    }
    action_link_select_steps(object, 0);
    action_link_select_steps(object, 1);
    njGetkmPointer();
    action_link_draw_motion_tree(object);
    njSetkmPointer();
}
#else
void draw_motion_link(NJS_OBJECT *object, NJS_MOTION_LINK *link, Float ratio)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
