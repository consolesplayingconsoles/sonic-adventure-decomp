/* @unit 8C027360-8C02CE80 @data 8C1123A8-8C112460 +r04 +jpflags +res00 +padnop  +asmfunc=FUN_8c028bc0,polygon_find_near_levels,CL_ColPolBeamHit,polygon_find_near_heights,polygon_find_model_heights,FUN_8c0274b8:+8c0275e0,sweep_model:+8c028100,sweep_take_nearest:+8c028280,FUN_8c028666:+8c0287a0,CL_ColPolListUpNear:+8c028e60,FUN_8c028ec2:+8c029400,polygon_find_sides:+8c029b00,CL_ColPolCheckTouchRe:+8c02a680,collision_segment_distance:+8c02b1a0,segment_cross_mesh:+8c02b620,polygon_find_nearest_height:+8c02bc60,find_model_heights_near:+8c02c100,polygon_find_model_sides:+8c02ca00 */
/* Ported from the Japanese release's src/collision/polygon.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
float FUN_8c10cf48(float x);
float asinf(float x);
float njArcTan2(float y, float x);
float ceilf(float x);
float floorf(float x);
float modff(float value, float *iptr);
float powf(float x, float y);
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
void FUN_8c6409c0(Int loc, Int val, Int digit);
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
Float CalcDistance(NJS_POINT3 *p1, NJS_POINT3 *p2);
Float FUN_8c63fec4(NJS_POINT3 *p, NJS_LINE *l, NJS_POINT3 *cp);
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
extern NJS_MATRIX nj_unit_matrix_;
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
struct collision_mesh;
struct floor_query;
struct height_query;
struct polygon;
extern struct collision_mesh *collision_mesh_list;
void polygon_pool_init(struct polygon *polygons, int count);
void collision_mesh_pool_init(struct collision_mesh *meshes, int count);
struct collision_mesh *FUN_8c02cef4(void);
void collision_mesh_free(struct collision_mesh *mesh);
struct polygon *collision_mesh_add_polygon(struct collision_mesh *mesh);
void collision_mesh_clear_buckets(void);
struct polygon *polygon_alloc(Float z);
void collision_mesh_take_buckets(struct collision_mesh *mesh);
Bool polygon_find_floor(struct floor_query *query, NJS_OBJECT *object,
                        Uint32 flags);
Bool polygon_find_heights(struct height_query *query, NJS_OBJECT *object,
                          Uint32 flags);
Float vector_length_squared(Float x, Float y, Float z);
Float mesh_point_distance2(NJS_POINT3 *from, NJS_POINT3 *to);
Float mesh_point_distance2_across(NJS_POINT3 *from, NJS_POINT3 *to);
void matrix_calc_point(NJS_POINT3 *point);
struct surface {
    Bool found;
    Sint32 flags;
    Angle ang_x;
    Angle ang_z;
    Float level;
    NJS_VECTOR normal;
};
struct floor_query {
    NJS_POINT3 pos;
    struct surface floor;
};
struct height_query {
    NJS_POINT3 pos;
    struct surface below;
    struct surface above;
};
struct line_query {
    Float radius;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    Uint8 unk_1c[20];
    Float level;
    Angle ang_x;
    Angle ang_z;
    NJS_VECTOR normal;
    Uint8 unk_48[60];
};
enum side {
    SIDE_MINUS_X,
    SIDE_PLUS_X,
    SIDE_BELOW,
    SIDE_ABOVE,
    SIDE_MINUS_Z,
    SIDE_PLUS_Z,
    SIDES
};
struct sides_query {
    NJS_POINT3 pos;
    struct surface sides[SIDES];
};
struct ray_query {
    Float length;
    NJS_POINT3 origin;
    NJS_VECTOR dir;
    Float distance;
    NJS_POINT3 hit;
    struct surface surface;
};
struct segment_query {
    NJS_POINT3 pos;
    NJS_VECTOR dir;
    NJS_POINT3 hit;
    NJS_VECTOR normal;
    Angle ang_x;
    Angle ang_z;
    Sint32 flags;
    Float distance;
};
struct polygon_hit {
    Angle ang_x;
    Angle ang_z;
    NJS_VECTOR front;
    NJS_VECTOR normal;
    NJS_POINT3 point;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    NJS_VECTOR normal_speed;
};
struct polygon_ball {
    Float radius;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    NJS_VECTOR normal;
    Uint16 count;
    Uint16 hit_index;
    Uint8 unk_2c[8];
    struct polygon_hit hit;
};
struct polygon_contact {
    struct polygon_hit hit;
    Float height;
    Float height_after;
};
extern struct polygon_contact colihitdat[];
struct polygon {
    struct polygon *next;
    struct polygon *prev;
    NJS_POINT3 center;
    Float radius;
    NJS_POINT3 vertex[3];
    Uint32 attr;
};
struct collision_mesh {
    struct collision_mesh *next;
    struct collision_mesh *prev;
    NJS_OBJECT *object;
    Sint32 flags;
    struct polygon *polygons;
    struct polygon *last;
    Sint32 unk_18;
    struct polygon **near;
    Sint32 unk_20;
    int near_count;
    Float span;
    Float unk_2c;
    NJS_POINT3 center;
    Sint32 unk_3c;
};
Bool collision_mesh_init(void);
Bool FUN_8c028ec2(void);
void collision_mesh_link_pools(void);
void polygon_pool_seek_free(void);
void collision_mesh_forget(NJS_OBJECT *object);
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object, Uint32 flags);
Bool polygon_sweep_model(struct polygon_ball *ball, NJS_OBJECT *object,
                         Uint32 flags);
Bool polygon_find_sides(struct sides_query *query, NJS_OBJECT *object,
                        Uint32 flags);
Bool polygon_find_nearest_height(struct line_query *query, NJS_OBJECT *object,
                                 Uint32 flags);
Bool polygon_find_model_heights(struct height_query *query, NJS_OBJECT *object);
Bool polygon_find_model_sides(struct sides_query *query, NJS_OBJECT *object,
                              Uint32 flags);
Bool polygon_find_near_heights(struct height_query *query, Float radius);
void polygon_find_near_levels(NJS_POINT3 *pos, Float radius, Float *above,
                              Angle *above_x, Angle *above_z, Float *below,
                              Angle *below_x, Angle *below_z);
Bool CL_ColPolBeamHit(struct ray_query *query);
NJS_OBJECT *polygon_cast_segment(struct segment_query *query,
                                 NJS_OBJECT *first);
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal);
Float polygon_point_distance2(NJS_POINT3 *from, NJS_POINT3 *to);
Float polygon_point_distance2_across(NJS_POINT3 *from, NJS_POINT3 *to);
Float polygon_distance2(Float *from, Float *to);
Float collision_segment_distance(NJS_POINT3 *point, NJS_POINT3 *start,
                                 NJS_POINT3 *end, NJS_POINT3 *nearest);
Bool collision_segment_nearest(NJS_POINT3 *start, NJS_POINT3 *end,
                               NJS_POINT3 *point, NJS_POINT3 *nearest,
                               Float *distance2);
struct task;
struct world_object {
    Sint32 flags;
    NJS_OBJECT *object;
    struct task *owner;
};
struct land_entry {
    NJS_POINT3 center;
    Float radius;
    Float size_y;
    Float size_z;
    NJS_OBJECT *object;
    Sint32 blocks;
    Sint32 flags;
};
struct land_motion {
    Float frame;
    Float speed;
    Float frames;
    NJS_OBJECT *object;
    union {
        NJS_ACTION *action;
        NJS_MOTION *motion;
    } play;
    NJS_TEXLIST *texlist;
};
struct land_table {
    Sint16 count;
    Sint16 motion_count;
    Sint16 flags;
    Sint16 users;
    Float clip;
    struct land_entry *entries;
    struct land_motion *motions;
    char *pvm;
    NJS_TEXLIST *texlist;
    char *file;
    void *data;
};
extern Sint32 world_land_blocks;
extern Sint16 LandCollList;
extern struct world_object numLandCollList[1024];
void world_land_step(struct task *task);
void world_load_act(int stage, int act);
void world_release_act(int stage, int act);
void world_change_act(Sint16 by);
void world_hide_land(void);
void world_show_land(void);
void world_set_land_material(Float gray);
void FUN_8c052518(void);
void FUN_8c052e30(void);
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void world_list_all(void);
void world_disable_land(void);
void world_enable_land(void);
void world_add(Sint32 flags, struct task *task, NJS_OBJECT *object);
void world_remove(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *world_object_alloc(void);
void world_object_free(NJS_OBJECT *object);
void world_reset_gravity(void);
void world_tilt_gravity(Angle ang_x, Angle ang_z);
void world_compute_bounds(void);
void world_set_near_radius(Float radius);
void world_reset_near_radius(void);
struct collision_work;
struct event_work;
struct placement;
struct player;
struct task;
struct angles {
    Angle x, y, z;
};
union task_vars {
    Sint8 b[12];
    Sint16 w[6];
    Sint32 l[3];
    Float f[3];
    void *p[3];
};
struct task_work {
    Sint8 mode;
    Sint8 submode;
    Uint8 id;
    Uint8 tick;
    Sint16 flags;
    Sint16 timer;
    union task_vars vars;
    struct angles ang;
    NJS_POINT3 pos;
    NJS_POINT3 scl;
    struct collision_work *collision;
    struct event_work *event;
};
struct task_motion {
    struct player *record;
    NJS_VECTOR speed;
    NJS_VECTOR accel;
    struct angles aim;
    Sint32 unk_28;
    Uint8 unk_2c[4];
    Angle phase;
    Float drive;
    Float slip;
    Float gravity;
};
struct task_force {
    void (*carry)(struct task *rider, struct task_work *work,
                  struct task_force *force);
    struct angles turn;
    NJS_VECTOR speed;
};
struct task {
    struct task *next;
    struct task *prev;
    struct task *parent;
    struct task *child;
    void (*step)(struct task *task);
    void (*draw)(struct task *task);
    void (*destructor)(struct task *task);
    struct placement *placement;
    struct task_work *work;
    struct task_motion *motion;
    void *force;
    void *extra;
};
struct task_spec {
    void (*step)(struct task *task);
    Uint16 create;
    Sint16 flags;
    struct angles ang;
    NJS_POINT3 pos;
    Sint32 var;
};
void task_idle(struct task *task);
void (*task_get_current_root_step(void))(struct task *task);
void task_init(void);
struct task *task_create(Uint16 flags, int level,
                         void (*step)(struct task *task));
struct task *task_alloc(int level, void (*step)(struct task *task));
void task_destroy(struct task *task);
void task_kill(struct task *task);
void task_step_level(int level);
void task_draw_level(int level);
void task_draw_children(struct task *task);
void task_destroy_level(int level);
void task_step_all(void);
void task_draw_all(void);
void task_destroy_levels_0_to_6(void);
void task_destroy_all(void);
void *task_alloc_work(void);
void *task_alloc_motion(void);
void *task_alloc_force(void);
void *task_alloc_extra(void);
void task_free_work(struct task *task);
void task_free_motion(struct task *task);
void task_free_force(struct task *task);
void task_free_extra(struct task *task);
struct task *task_create_child(Uint16 flags, void (*step)(struct task *task),
                               struct task *parent);
struct task *task_create_children(struct task_spec *spec, struct task *parent);
void task_destroy_children(struct task *task);
void task_step_children(struct task *task);
void heap_init(void);
void *heap_alloc(int size);
void *heap_calloc(int count, int size);
void heap_free(void *mem);
void heap_stats(int *total, int *largest);
struct collision_shape;
struct touch {
    NJS_VECTOR moved;
    union {
        struct collision_shape *shape;
        struct task *owner;
    } by;
};
struct jump {
    NJS_POINT3 pos;
    NJS_POINT3 target;
    Float gravity;
    Sint32 steps;
    NJS_VECTOR speed;
};
enum jump_state { JUMP_FLYING, JUMP_ON_TARGET, JUMP_OFF_TARGET };
enum drop_kind {
    DROP_RING = 1,
    DROP_5_RINGS = 2,
    DROP_10_RINGS = 3,
    DROP_RANDOM_RINGS = 4,
    DROP_1UP = 6
};
void vector_copy(const Float *from, Float *to);
void angles_copy(const Angle *from, Angle *to);
void vector_clear(Float *vector);
void vector_add(const NJS_VECTOR *first, const NJS_VECTOR *second,
                NJS_VECTOR *sum);
void vector_sub(const Float *first, const Float *second, Float *difference);
void vector_between(const NJS_VECTOR *from, const NJS_VECTOR *to,
                    NJS_VECTOR *out);
void object_step_draw_range(struct task *task);
void object_step_draw(struct task *task);
void object_draw_model(struct task *task);
void object_draw_model_scaled(struct task *task);
void object_draw_action(struct task *task);
int object_touch_moved(struct task_work *work, struct touch *touch);
Float vector_dot(NJS_VECTOR *first, NJS_VECTOR *second);
void vector_cross(NJS_VECTOR *first, NJS_VECTOR *second, NJS_VECTOR *out);
Float vector_length(NJS_VECTOR *vector);
void vector_aim_z(NJS_VECTOR *vector, Angle *ang_x, Angle *ang_y);
void vector_aim_y(NJS_VECTOR *vector, Angle *ang_x, Angle *ang_z);
void vector_aim_x(NJS_VECTOR *vector, Angle *ang_y, Angle *ang_z);
Float vector_reflect(NJS_VECTOR *vector, NJS_VECTOR *normal, NJS_VECTOR *out);
void arrow_draw(NJS_POINT3 *pos, NJS_VECTOR *vector);
void arrow_draw_y(NJS_POINT3 *pos, NJS_VECTOR *vector);
void marker_draw(NJS_POINT3 *pos, Float size);
extern NJS_OBJECT arrow_y;
int item_pick(Float *table);
Bool item_drop(struct task_work *work, enum drop_kind kind);
Bool polygon_contains(NJS_POINT3 *point, NJS_POINT3 *corners,
                      NJS_VECTOR *normal, int count);
void words_copy(Sint32 *from, Sint32 *to, int count);
Bool player_get_middle(Uint8 player, int steps, NJS_POINT3 *pos,
                       struct angles *ang);
void mirror_clear(void);
int mirror_count(void);
Bool mirror_add(struct task_work *work, NJS_MODEL *model);
void mirror_draw(struct task *task, void (*draw)(struct task *task));
NJS_OBJECT *object_add_world_model(struct task *task, NJS_MODEL *model);
void object_world_follow(struct task_work *work, NJS_OBJECT *object);
void object_world_test(struct task_work *work, NJS_OBJECT *object);
void collision_shapes_on(struct task_work *work);
void collision_shapes_off(struct task_work *work);
void action_advance(NJS_ACTION *action, Float *frame, Float step);
int players_near(NJS_POINT3 *pos, Float range);
Float vector_distance2(NJS_POINT3 *from, NJS_POINT3 *to);
void jump_aim(struct jump *jump);
enum jump_state jump_landed(struct jump *jump);
Float vector_cos(NJS_VECTOR *first, NJS_VECTOR *second);
Bool stage_before_bosses(void);
Float vector_normalize(NJS_VECTOR *vector);
void object_idle(struct task *task);
struct particle;
struct story_record;
struct task;
struct task_work;
enum stage_group { STAGE_GROUP_FIELD = 1, STAGE_GROUP_ACTION = 2 };
enum stage_end {
    STAGE_END_NONE = 0,
    STAGE_END_CLEAR = 1,
    STAGE_END_MISS = 2,
    STAGE_END_GO_TO = 3,
    STAGE_END_RESTART = 4,
    STAGE_END_RETRY = 5,
    STAGE_END_QUIT = 6
};
enum stage_step {
    STAGE_STEP_RESET = -2,
    STAGE_STEP_QUIT = -1,
    STAGE_STEP_STAFF_ROLL = 10
};
struct trial_time {
    Uint32 minutes;
    Uint32 seconds;
    Uint32 frames;
};
struct mirror_quad {
    NJS_VECTOR normal;
    NJS_POINT3 corners[4];
};
struct mirror {
    Sint32 count;
    struct mirror_quad quads[32];
};
struct mirror_list {
    Sint32 count;
    struct mirror mirrors[4];
};
extern int event_ending;
extern Sint16 stage_mode;
extern Sint16 stage_previous;
extern Sint16 act_previous;
extern Sint16 stage_current;
extern Sint16 act_current;
extern Sint16 stage_loaded;
extern Sint16 act_loaded;
extern Sint16 stage_next;
extern Sint16 act_next;
extern Sint16 entrance_next;
extern Uint16 character_current;
extern Sint16 stage_retries;
extern Sint16 pause_choice;
extern Sint16 pause_hidden;
extern Sint16 continue_choice;
extern Sint16 continue_timer;
extern int dat_8c75b734;
extern struct task *stage_task;
extern Uint16 collision_item_count;
extern Uint16 collision_enemy_count;
extern Sint8 debug_hidden;
extern Sint8 hud_hidden;
extern Sint8 lives_shown;
extern Sint8 rings_shown;
extern Sint8 lives;
extern Sint8 time_minutes;
extern Sint8 time_seconds;
extern Sint8 time_frames;
extern Sint16 rings;
extern int play_time;
extern int time_steps;
extern int score;
extern int bonus_points;
extern int trial_count;
extern Float shoot_hit_rate;
extern int hints_used;
extern struct trial_time trial_times[5];
extern struct mirror_list mirrors;
extern NJS_VECTOR scratch_vector;
extern NJS_VECTOR scratch_vector2;
extern NJS_VECTOR scratch_vector3;
extern Uint8 dat_8c75d5dc[12];
extern NJS_POINT3 scratch_point;
extern NJS_POINT3 scratch_point2;
extern NJS_MATRIX scratch_matrix;
extern Uint8 dat_8c75d640[192];
extern struct segment_query scratch_segment_query;
extern NJS_VECTOR world_gravity;
extern Angle world_gravity_ang_x;
extern Angle world_gravity_ang_z;
extern struct story_record *player_record;
extern int dat_8c75d758;
extern Sint8 debug_unlocked;
void pause_enable(void);
void pause_disable(void);
void boot_new_game(void);
enum stage_group stage_group(void);
enum stage_group stage_begin(void);
Sint16 stage_step_action(void);
Sint16 stage_step_field(void);
void stage_end(Sint16 end);
void sound_play_later(int se);
void music_play_later(int music);
void stage_clear(void);
void set_character(Sint16 character);
void set_character_number(Sint16 character);
int get_character(void);
int stage_get_retries(void);
Uint16 stage_get_stage_act(void);
Uint16 stage_get_previous_stage_act(void);
void stage_set_stage_act(Uint8 stage, Uint8 act);
void stage_fade_to(Uint8 stage, Uint8 act);
void stage_restart(void);
void stage_set_next_stage_act(Uint8 stage, Uint8 act);
Uint16 stage_get_next_stage_act(void);
void stage_go_to_next(void);
void stage_change_act(Sint16 by);
void stage_set_entrance(Sint8 entrance);
Sint8 stage_get_entrance(void);
void stage_place_player(struct task_work *work);
void stage_set_next_exit(void);
Bool stage_paused(void);
Bool stage_playing(void);
typedef char *va_list;
typedef unsigned long size_t;
int rand(void);
void srand(unsigned int seed);
void *calloc(size_t nmemb, size_t size);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
struct angles;
struct task_work;
union point_floats {
    NJS_POINT3 point;
    NJS_VECTOR vector;
    Float elements[3];
};
union line_view {
    NJS_LINE line;
    struct {
        NJS_POINT3 point;
        NJS_VECTOR direction;
    } split;
    Float coordinates[6];
};
union plane_view {
    NJS_PLANE plane;
    struct {
        NJS_POINT3 point;
        NJS_VECTOR normal;
    } split;
};
union angle_halves {
    Angle whole;
    Sint16 half[2];
};
struct model_weld {
    Sint16 count;
    Sint8 node_a;
    Sint8 node_b;
    Sint16 *pairs;
};
Angle angle_approach(Angle from, Angle to, Angle step);
Angle angle_difference(Angle from, Angle to);
Angle angle_distance(Angle from, Angle to);
Angle angle_unwrap(Angle from, Angle to);
int vector_angle(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *normal);
void vector_get_angles(const NJS_VECTOR *dir, const NJS_VECTOR *from,
                       Angle angles[3]);
Float float_wrap(Float value, Float period);
Float float_approach(Float from, Float to, Float step);
Bool draw_on_screen(struct task_work *work);
void draw_attr_save(void);
void draw_attr_restore(void);
void draw_attr_set(Uint32 and_attr, Uint32 or_attr);
void draw_attr_clear(Uint32 and_attr, Uint32 or_attr);
void draw_control_save(void);
void draw_control_restore(void);
void draw_control_set(Uint32 flags);
void draw_control_clear(Uint32 flags);
void model_blend(NJS_MODEL *from, NJS_MODEL *to, NJS_MODEL *out, Float blend);
void points_blend(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                  Float blend, int count);
void points_blend_sine(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                       Float blend, int count);
void points_blend_square(NJS_POINT3 *from, NJS_POINT3 *to, NJS_POINT3 *out,
                         Float blend, int count);
void model_calc_face_normals(NJS_MODEL *model);
void model_calc_point_normals(NJS_MODEL *model);
void model_weld(NJS_OBJECT *object, NJS_MOTION *motion, Float frame,
                struct model_weld *welds);
int tree_node_index(NJS_OBJECT *root, NJS_OBJECT *object);
int tree_list_nodes(NJS_OBJECT *root, NJS_OBJECT **nodes);
NJS_MATRIX *tree_calc_matrices(NJS_MATRIX *base, NJS_OBJECT *object, int index);
void tree_get_matrix(NJS_MATRIX *out, int index);
void evalflags_set_all(NJS_OBJECT **objects, Uint32 flags);
void evalflags_clear_all(NJS_OBJECT **objects, Uint32 flags);
void sprite_init(NJS_SPRITE *sprite, NJS_TEXLIST *texlist,
                 NJS_TEXANIM *texanim);
int world_sweep_ball(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                     int skip, Float radius);
int world_sweep_all(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                    Float radius);
Bool world_sweep_all_hit(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                         Float radius);
Bool world_sweep_ball_hit(NJS_POINT3 *pos, NJS_VECTOR *speed,
                          struct angles *ang, int skip, Float radius);
int string_vformat(char *buffer, const char *format, va_list args);
int string_format(char *buffer, const char *format, ...);
void vector_sum(NJS_VECTOR *a, NJS_VECTOR *b, NJS_VECTOR *out);
void vector_diff(NJS_VECTOR *a, NJS_VECTOR *b, NJS_VECTOR *out);
Float vector_dot_from(NJS_POINT3 *from, NJS_POINT3 *a, NJS_POINT3 *b);
Bool matrix_push_unit(void);
struct strip {
    int kind;
    int count;
    Sint16 *indices;
    NJS_MODEL *model;
    NJS_POINT3 points[1024];
};
struct sweep {
    Bool hit;
    int count;
    int tested;
    Float reach;
    Float length;
    Float spacing;
    struct polygon_contact *contacts;
};
struct touch_polygon {
    Sint32 unk_00;
    struct polygon polygon;
    struct polygon_contact contact;
};
extern struct polygon_contact colihitdat[16];
extern struct polygon *polygon_cursor;
extern int polygon_cursor_index;
extern Uint32 dat_8c6c4bb0;
extern struct collision_mesh mesh_pool[192];
extern struct polygon polygon_pool[8192];
extern int near_polygon_count;
extern struct polygon *near_polygons[96];
extern int touch_polygon_count;
extern struct touch_polygon touch_polygons[16];
extern NJS_OBJECT *mesh_stale_object;
extern NJS_POINT3 touch_points[3];
extern Float mesh_center_z;
extern Float mesh_span;
extern Float mesh_unk_2c_value;
extern NJS_MATRIX touch_matrix;
extern NJS_COLOR touch_colors[3];
extern NJS_POINT3COL touch_triangle;
extern Bool mesh_collect_all;
extern const Float size_reach2[4];
NJS_OBJECT *segment_cross_mesh(struct segment_query *query,
                                      NJS_OBJECT *object, Sint32 flags);
Bool find_model_heights_near(struct height_query *query,
                                    NJS_OBJECT *object, Uint32 flags);
void FUN_8c027360(const char *v0, const char *v1, const char *v2,
                            NJS_VECTOR *normal)
{
    Float ux;
    Float uy;
    Float uz;
    Float vx;
    Float vy;
    Float vz;
    vx = *(const Float *)v0;
    v0 += sizeof(Float);
    ux = *(const Float *)v1 - vx;
    v1 += sizeof(Float);
    uy = *(const Float *)v1 - (vy = *(const Float *)v0);
    v1 += sizeof(Float);
    v0 += sizeof(Float);
    vz = *(const Float *)v0;
    uz = *(const Float *)v1;
    vx -= *(const Float *)v2;
    v2 += sizeof(Float);
    vy -= *(const Float *)v2;
    v2 += sizeof(Float);
    uz -= vz;
    vz -= *(const Float *)v2;
    normal->x = (uz * vy) - (uy * vz);
    normal->y = (ux * vz) - (uz * vx);
    normal->z = (uy * vx) - (ux * vy);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool FUN_8c0273a2(struct strip *strip)
{
    NJS_POINT3 *points;
    NJS_POINT3 *out;
    Sint16 *indices;
    int i;
    Bool reversed = (0);
    switch (strip->kind) {
    case 0x0000:
    case 0x4000:
        indices = strip->indices;
        points = strip->model->points;
        out = strip->points;
        for (i = strip->count; i > 0; i--) {
            njCalcPoint(((void *)0), &points[*indices], out);
            indices++;
            out++;
        }
        strip->indices = indices;
        break;
    case 0x8000:
    case 0xc000:
        strip->count = *strip->indices & 0x7fff;
        if (*strip->indices & 0x8000) {
            reversed = (1);
        }
        if (strip->count > 1024) {
            strip->count = 1024;
            if (debug_hidden >= 0) {
                njPrintC(((2) << 16 | (18)), "WARNING: STRIP buf is FULL");
            }
        }
        strip->indices++;
        points = strip->model->points;
        out = strip->points;
        indices = strip->indices;
        for (i = strip->count; i > 0; i--) {
            njCalcPoint(((void *)0), &points[*indices], out);
            indices++;
            out++;
        }
        strip->indices = indices;
        break;
    }
    return reversed;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool FUN_8c0274b8(struct strip *strip)
{
    NJS_POINT3 *points;
    NJS_POINT3 *out;
    Sint16 *indices;
    int i;
    Bool reversed = (0);
    switch (strip->kind) {
    case 0x0000:
    case 0x4000:
        indices = strip->indices;
        points = strip->model->points;
        out = strip->points;
        for (i = strip->count; i > 0; i--) {
            *out = points[*indices];
            indices++;
            out++;
        }
        strip->indices = indices;
        break;
    case 0x8000:
    case 0xc000:
        strip->count = *strip->indices & 0x7fff;
        if (*strip->indices & 0x8000) {
            reversed = (1);
        }
        if (strip->count > 1024) {
            strip->count = 1024;
            if (debug_hidden >= 0) {
                njPrintC(((2) << 16 | (18)), "WARNING: STRIP buf is FULL");
            }
        }
        strip->indices++;
        points = strip->model->points;
        out = strip->points;
        indices = strip->indices;
        for (i = strip->count; i > 0; i--) {
            *out = points[*indices];
            indices++;
            out++;
        }
        strip->indices = indices;
        break;
    }
    return reversed;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool strip_next_moved(struct strip *strip, NJS_OBJECT *object)
{
    NJS_POINT3 *points;
    NJS_POINT3 *out;
    Float *point;
    Float x;
    Float y;
    Float z;
    Sint16 *indices;
    int i;
    Bool reversed = (0);
    switch (strip->kind) {
    case 0x0000:
    case 0x4000:
        x = object->pos[0];
        y = object->pos[1];
        z = object->pos[2];
        indices = strip->indices;
        points = strip->model->points;
        out = strip->points;
        for (i = strip->count; i > 0; i--) {
            point = &points[*indices].x;
            out->x = *point++ + x;
            out->y = *point++ + y;
            out->z = *point + z;
            indices++;
            out++;
        }
        strip->indices = indices;
        break;
    case 0x8000:
    case 0xc000:
        strip->count = *strip->indices & 0x7fff;
        if (*strip->indices & 0x8000) {
            reversed = (1);
        }
        if (strip->count > 1024) {
            strip->count = 1024;
            if (debug_hidden >= 0) {
                njPrintC(((2) << 16 | (18)), "WARNING: STRIP buf is FULL");
            }
        }
        strip->indices++;
        y = object->pos[1];
        z = object->pos[2];
        x = object->pos[0];
        points = strip->model->points;
        indices = strip->indices;
        out = strip->points;
        for (i = strip->count; i > 0; i--) {
            point = &points[*indices].x;
            out->x = *point++ + x;
            out->y = *point++ + y;
            out->z = *point + z;
            indices++;
            out++;
        }
        strip->indices = indices;
        break;
    }
    return reversed;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void sweep_model(struct polygon_ball *ball, NJS_OBJECT *object,
                        struct sweep *sweep)
{
    struct strip strip;
    NJS_POINT3 tri[3];
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    NJS_VECTOR foot;
    NJS_VECTOR normal;
    NJS_POINT3 out;
    NJS_VECTOR part;
    NJS_VECTOR stride;
    NJS_POINT3 at;
    NJS_MESHSET *meshset;
    NJS_POINT3 *corner;
    struct polygon_contact *contact;
    int meshsets;
    int strips;
    int i;
    Bool reversed;
    Bool hit;
    Bool more;
    Uint32 two_sided;
    Angle ang_x;
    Angle ang_y;
    Float *v0;
    Float *v1;
    Float *v2;
    char *edge1;
    char *edge2;
    Float dx;
    Float dy;
    Float dz;
    Float reach;
    Float edge;
    Float x;
    Float y;
    Float z;
    Float x0;
    Float y0;
    Float z0;
    Float x1;
    Float y1;
    Float z1;
    Float radius;
    Float travelled;
    Float e1;
    Float e2;
    Float e3;
    strip.model = object->model;
    meshsets = strip.model->nbMeshset;
    for (meshset = strip.model->meshsets;
         meshsets > 0 && sweep->count < 16;
         meshsets--, meshset++) {
        switch (strip.kind = meshset->type_matId & 0xc000) {
        case 0x0000:
            strip.count = 3;
            break;
        case 0x4000:
            strip.count = 4;
            break;
        case 0x8000:
        case 0xc000:
            break;
        default:
            continue;
        }
        strips = meshset->nbMesh;
        strip.indices = meshset->meshes;
        for (; strips != 0 && sweep->count < 16; strips--) {
            reversed = FUN_8c0273a2(&strip);
            tri[0].x = tri[0].y = tri[0].z = 0.0F;
            for (i = 0, corner = strip.points; i < strip.count - 2;
                 i++, corner++) {
                v0 = &corner->x;
                v1 = &corner->x + 3;
                v2 = &corner->x + 6;
                x1 = *v1++;
                y1 = *v1++;
                z1 = *v1;
                dx = x1 - *v0++;
                dy = y1 - *v0++;
                dz = z1 - *v0++;
                reach = (dx * dx) + (dy * dy) + (dz * dz);
                dx = *v2++ - x1;
                dy = *v2++ - y1;
                dz = *v2++ - z1;
                if ((edge = (dx * dx) + (dy * dy) + (dz * dz)) > reach) {
                    reach = edge;
                }
                v0 -= 3;
                v2 -= 3;
                dx = *v0++ - *v2++;
                dy = *v0++ - *v2++;
                dz = *v0 - *v2;
                if ((edge = (dx * dx) + (dy * dy) + (dz * dz)) > reach) {
                    reach = edge;
                }
                reach += (ball->speed.x * ball->speed.x) +
                         (ball->speed.y * ball->speed.y) +
                         (ball->speed.z * ball->speed.z) +
                         (ball->radius * ball->radius);
                v0 = &ball->pos.x;
                x = *v0++;
                y = *v0++;
                z = *v0;
                v0 = &corner->x;
                dx = x - *v0++;
                dy = y - *v0++;
                dz = z - *v0;
                if ((dx * dx) + (dy * dy) + (dz * dz) > reach) {
                    continue;
                }
                v0 = &corner->x + 3;
                dx = x - *v0++;
                dy = y - *v0++;
                dz = z - *v0;
                if ((dx * dx) + (dy * dy) + (dz * dz) > reach) {
                    continue;
                }
                v0 = &corner->x + 6;
                dx = x - *v0++;
                dy = y - *v0++;
                dz = z - *v0;
                if ((dx * dx) + (dy * dy) + (dz * dz) > reach) {
                    continue;
                }
                sweep->tested++;
                if (!((i + reversed) & 1)) {
                    edge1 = (char *)&tri[1];
                    edge2 = (char *)&tri[2];
                    v1 = &corner->x + 3;
                    v0 = &corner->x;
                    x0 = *v0++;
                    y0 = *v0++;
                    z0 = *v0;
                    *(Float *)edge1 = *v1++ - x0;
                    *(Float *)(edge1 + sizeof(Float)) = *v1++ - y0;
                    *(Float *)(edge1 + (2 * sizeof(Float))) = *v1 - z0;
                    v2 = &corner->x + 6;
                    *(Float *)edge2 = *v2++ - x0;
                    *(Float *)(edge2 + sizeof(Float)) = *v2++ - y0;
                    *(Float *)(edge2 + (2 * sizeof(Float))) = *v2 - z0;
                } else {
                    edge1 = (char *)&tri[1];
                    edge2 = (char *)&tri[2];
                    v2 = &corner->x + 6;
                    v0 = &corner->x;
                    x0 = *v0++;
                    y0 = *v0++;
                    z0 = *v0;
                    *(Float *)edge1 = *v2++ - x0;
                    *(Float *)(edge1 + sizeof(Float)) = *v2++ - y0;
                    *(Float *)(edge1 + (2 * sizeof(Float))) = *v2 - z0;
                    v1 = &corner->x + 3;
                    *(Float *)edge2 = *v1++ - x0;
                    *(Float *)(edge2 + sizeof(Float)) = *v1++ - y0;
                    *(Float *)(edge2 + (2 * sizeof(Float))) = *v1 - z0;
                }
                if ((tri[0].x == tri[1].x && tri[0].y == tri[1].y &&
                     tri[0].z == tri[1].z) ||
                    (tri[0].x == tri[2].x && tri[0].y == tri[2].y &&
                     tri[0].z == tri[2].z) ||
                    (tri[1].x == tri[2].x && tri[1].y == tri[2].y &&
                     tri[1].z == tri[2].z)) {
                    continue;
                }
                pos.x = ball->pos.x - corner->x;
                pos.y = ball->pos.y - corner->y;
                pos.z = ball->pos.z - corner->z;
                speed.x = ball->speed.x;
                speed.y = ball->speed.y;
                speed.z = ball->speed.z;
                FUN_8c027360((const char *)(NJS_POINT3 *)&tri[0].x,
                                (const char *)(NJS_POINT3 *)&tri[1].x,
                                (const char *)(NJS_POINT3 *)&tri[2].x, &normal);
                if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
                ang_x = (Angle)(FUN_8c10cf48(normal.y) * (65536.0 / (2 * 3.141592)));
                ang_y = (Angle)(njArcTan2(normal.x, normal.z) * (65536.0 / (2 * 3.141592)));
                njPushMatrix(&nj_unit_matrix_);
                ((-ang_x) ? (njRotateX)(((void *)0), (-ang_x)) : (void)0);
                ((-ang_y) ? (njRotateY)(((void *)0), (-ang_y)) : (void)0);
                njCalcPoint(((void *)0), &tri[1], &out);
                tri[1] = out;
                njCalcPoint(((void *)0), &tri[2], &out);
                tri[2] = out;
                njCalcPoint(((void *)0), &pos, &out);
                pos = out;
                njCalcPoint(((void *)0), &speed, &out);
                speed = out;
                two_sided =
                    strip.model->mats[meshset->type_matId & ~0xc000]
                        .attrflags &
                    0x00800000;
                radius = ball->radius;
                if (two_sided) {
                    if (pos.y < 0.0F) {
                        radius *= -1.0F;
                    }
                } else {
                }
                stride = speed;
                hit = (0);
                if (njScalor(&stride) == 0.0F) { (&stride)->x = (&stride)->y = (&stride)->z = 0.0F; } else { njUnitVector(&stride); };
                travelled = 0.0F;
                stride.x *= sweep->spacing;
                stride.y *= sweep->spacing;
                stride.z *= sweep->spacing;
                at = pos;
                for (;;) {
                    more = (1);
                    if (travelled >= sweep->length) {
                        v0 = &pos.x;
                        v1 = &speed.x;
                        at.x = *v0++ + *v1++;
                        at.y = *v0++ + *v1++;
                        at.z = *v0 + *v1;
                        more = (0);
                    }
                    if (((Float)_builtin_fabsf((Float)(at.y))) <= ball->radius) {
                        e1 = ((((&tri[1])->z - (&tri[0])->z) * ((&at)->x - (&tri[0])->x)) - (((&tri[1])->x - (&tri[0])->x) * ((&at)->z - (&tri[0])->z)));
                        e2 = ((((&tri[2])->z - (&tri[1])->z) * ((&at)->x - (&tri[1])->x)) - (((&tri[2])->x - (&tri[1])->x) * ((&at)->z - (&tri[1])->z)));
                        e3 = ((((&tri[0])->z - (&tri[2])->z) * ((&at)->x - (&tri[2])->x)) - (((&tri[0])->x - (&tri[2])->x) * ((&at)->z - (&tri[2])->z)));
                        if (e1 * e2 >= 0.0F && e2 * e3 >= 0.0F &&
                            e1 * e3 >= 0.0F) {
                            hit = (1);
                            break;
                        }
                    }
                    if (!more) {
                        break;
                    }
                    if (0) { if (more) { } };
                    at.x += stride.x;
                    at.y += stride.y;
                    at.z += stride.z;
                    travelled += sweep->spacing;
                }
                if (!hit) {
                    njPopMatrix(1);
                    continue;
                }
                sweep->hit = (1);
                contact = &sweep->contacts[sweep->count];
                contact->height = pos.y;
                contact->height_after = pos.y + speed.y;
                contact->hit.front = normal;
                if (two_sided) {
                    if (pos.y >= 0.0F) {
                        contact->hit.normal = normal;
                    } else {
                        contact->hit.normal.x = -normal.x;
                        contact->hit.normal.y = -normal.y;
                        contact->hit.normal.z = -normal.z;
                    }
                } else {
                    contact->hit.normal = normal;
                }
                contact->hit.ang_z = -(Angle)(njArcTan2(contact->hit.normal.x,
                                                     contact->hit.normal.y) *
                                              (65536.0 / (2 * 3.141592)));
                contact->hit.ang_x =
                    (Angle)(asinf(contact->hit.normal.z) * (65536.0 / (2 * 3.141592)));
                njInvertMatrix(((void *)0));
                foot.x = pos.x;
                foot.y = 0.0F;
                foot.z = pos.z;
                njCalcPoint(((void *)0), &foot, &out);
                contact->hit.point.x = out.x + corner->x;
                contact->hit.point.y = out.y + corner->y;
                contact->hit.point.z = out.z + corner->z;
                foot.y = radius;
                njCalcPoint(((void *)0), &foot, &out);
                contact->hit.pos.x = out.x + corner->x;
                contact->hit.pos.y = out.y + corner->y;
                contact->hit.pos.z = out.z + corner->z;
                part = speed;
                if (two_sided) {
                    if (pos.y * speed.y < 0.0F) {
                        part.y = -speed.y;
                    }
                } else if (radius * speed.y < 0.0F) {
                    part.y = -speed.y;
                }
                part.x = speed.x;
                part.y = 0.0F;
                part.z = speed.z;
                njCalcPoint(((void *)0), &part, &out);
                contact->hit.speed = out;
                part.x = 0.0F;
                part.y = speed.y;
                part.z = 0.0F;
                njCalcPoint(((void *)0), &part, &out);
                contact->hit.normal_speed = out;
                njPopMatrix(1);
                sweep->count++;
            }
        }
    }
    if (0) { if (strip.kind == 0xc000) { } };
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void sweep_take_nearest(struct polygon_ball *ball, struct sweep *sweep)
{
    struct polygon_ball sum;
    struct polygon_contact *contact;
    int i;
    int nearest = 0;
    Float height;
    Float scale;
    height = ((Float)_builtin_fabsf((Float)(sweep->contacts[0].height)));
    for (i = 1; i < sweep->count; i++) {
        if (height > ((Float)_builtin_fabsf((Float)(sweep->contacts[i].height_after)))) {
            nearest = i;
            height = ((Float)_builtin_fabsf((Float)(sweep->contacts[i].height_after)));
        }
    }
    ball->hit_index = nearest;
    contact = &sweep->contacts[nearest];
    ball->hit.ang_x = contact->hit.ang_x;
    ball->hit.ang_z = contact->hit.ang_z;
    ball->hit.front = contact->hit.front;
    ball->hit.normal = contact->hit.normal;
    ball->hit.speed = contact->hit.speed;
    ball->hit.normal_speed = contact->hit.normal_speed;
    sum.hit.point.x = sum.hit.point.y = sum.hit.point.z = 0.0F;
    sum.hit.pos.x = sum.hit.pos.y = sum.hit.pos.z = 0.0F;
    scale = 1.0F / sweep->count;
    for (i = sweep->count, contact = sweep->contacts; i > 0; i--) {
        sum.hit.point.x += scale * contact->hit.point.x;
        sum.hit.point.y += scale * contact->hit.point.y;
        sum.hit.point.z += scale * contact->hit.point.z;
        sum.hit.pos.x += scale * contact->hit.pos.x;
        sum.hit.pos.y += scale * contact->hit.pos.y;
        sum.hit.pos.z += scale * contact->hit.pos.z;
        contact++;
    }
    ball->hit.point = sum.hit.point;
    ball->hit.pos = sum.hit.pos;
}
NJS_OBJECT *sweep_tree(struct polygon_ball *ball, NJS_OBJECT *object,
                              struct sweep *sweep)
{
    NJS_OBJECT *child;
    if ((object->evalflags & (0x01 | 0x02 | 0x04)) ^ (0x01 | 0x02 | 0x04)) {
        njPushMatrix(((void *)0));
        if (!(object->evalflags & 0x01)) {
            njTranslateV(((void *)0), (NJS_VECTOR *)object->pos);
        }
        if (!(object->evalflags & 0x02)) {
            ((object->ang[2]) ? (njRotateZ)(((void *)0), (object->ang[2])) : (void)0);
            ((object->ang[1]) ? (njRotateY)(((void *)0), (object->ang[1])) : (void)0);
            ((object->ang[0]) ? (njRotateX)(((void *)0), (object->ang[0])) : (void)0);
        }
        if (!(object->evalflags & 0x04)) {
            njScaleV(((void *)0), (NJS_VECTOR *)object->scl);
        }
    }
    child = object->child;
    while (child != ((void *)0)) {
        child = sweep_tree(ball, child, sweep);
    }
    sweep_model(ball, object, sweep);
    if ((object->evalflags & (0x01 | 0x02 | 0x04)) ^ (0x01 | 0x02 | 0x04)) {
        njPopMatrix(1);
    }
    return object->sibling;
}
Bool polygon_sweep_model(struct polygon_ball *ball, NJS_OBJECT *object,
                         Uint32 flags)
{
    struct sweep sweep;
    NJS_OBJECT *child;
    sweep.hit = (0);
    sweep.count = 0;
    sweep.tested = 0;
    sweep.contacts = colihitdat;
    sweep.reach = size_reach2[((flags) & 0x60000000) >> 13];
    sweep.length = njScalor(&ball->speed);
    sweep.spacing = ball->radius * 0.5F;
    njPushMatrix(((void *)0));
    njUnitMatrix(((void *)0));
    if (!(object->evalflags & 0x01)) {
        njTranslateV(((void *)0), (NJS_VECTOR *)object->pos);
    }
    if (!(object->evalflags & 0x02)) {
        ((object->ang[2]) ? (njRotateZ)(((void *)0), (object->ang[2])) : (void)0);
        ((object->ang[1]) ? (njRotateY)(((void *)0), (object->ang[1])) : (void)0);
        ((object->ang[0]) ? (njRotateX)(((void *)0), (object->ang[0])) : (void)0);
    }
    if (!(object->evalflags & 0x04)) {
        njScaleV(((void *)0), (NJS_VECTOR *)object->scl);
    }
    child = object->child;
    while (child != ((void *)0)) {
        child = sweep_tree(ball, child, &sweep);
    }
    sweep_model(ball, object, &sweep);
    if (sweep.count > 0) {
        sweep_take_nearest(ball, &sweep);
        ball->count = sweep.count;
    }
    njPopMatrix(1);
    return sweep.hit;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void polygon_find_near_levels(NJS_POINT3 *pos, Float radius, Float *above,
                              Angle *above_x, Angle *above_z, Float *below,
                              Angle *below_x, Angle *below_z)
{
    struct line_query query;
    struct world_object *objects;
    Bool found_below;
    Bool found_above;
    int i;
    Float level;
    *above = pos->y + 100000.0F;
    *below = pos->y - 100000.0F;
    found_above = (0);
    found_below = (0);
    objects = numLandCollList;
    ListGroundForCollision(pos->x, pos->y, pos->z, radius);
    query.pos.x = pos->x;
    query.pos.y = pos->y;
    query.pos.z = pos->z;
    for (i = 0; i < LandCollList; i++) {
        if (polygon_find_nearest_height(&query, objects[i].object,
                                        objects[i].flags) == (1)) {
            level = query.level;
            if (level > pos->y) {
                if (*above > level) {
                    *above = level;
                    if (above_x != ((void *)0)) {
                        *above_x = query.ang_x;
                    }
                    if (above_z != ((void *)0)) {
                        *above_z = query.ang_z;
                    }
                    found_above = (1);
                }
            } else if (level > *below) {
                *below = level;
                if (below_x != ((void *)0)) {
                    *below_x = query.ang_x;
                }
                if (below_z != ((void *)0)) {
                    *below_z = query.ang_z;
                }
                found_below = (1);
            }
        }
    }
    if (!found_above) {
        *above = pos->y - 100000.0F;
    }
    if (!found_below) {
        *below = pos->y + 100000.0F;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void collision_mesh_link_pools(void)
{
    polygon_pool_init(polygon_pool, 8192);
    collision_mesh_pool_init(mesh_pool, 192);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void polygon_pool_seek_free(void)
{
    while (polygon_cursor_index < 8192 &&
           polygon_cursor->radius != 0.0F) {
        polygon_cursor_index++;
        polygon_cursor++;
    }
    if (polygon_cursor_index >= 8192) {
        polygon_cursor = ((void *)0);
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool FUN_8c028666(struct strip *strip)
{
    NJS_POINT3 *point;
    int i;
    Bool reversed = (0);
    switch (strip->kind) {
    case 0x0000:
    case 0x4000:
        for (i = strip->count, point = strip->points; i > 0; i--, point++) {
            njCalcPoint(((void *)0), &strip->model->points[*strip->indices], point);
            strip->indices++;
        }
        break;
    case 0x8000:
    case 0xc000:
        strip->count = *strip->indices & 0x7fff;
        if (*strip->indices & 0x8000) {
            reversed = (1);
        }
        if (strip->count > 1024) {
            strip->count = 1024;
            if (debug_hidden >= 0) {
                njPrintC(((2) << 16 | (18)), "WARNING: STRIP buf is FULL");
            }
        }
        strip->indices++;
        for (i = strip->count, point = strip->points; i > 0; i--, point++) {
            njCalcPoint(((void *)0), &strip->model->points[*strip->indices], point);
            strip->indices++;
        }
        break;
    }
    return reversed;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool mesh_add_model(NJS_OBJECT *object, Sint32 flags,
                           struct collision_mesh *mesh)
{
    struct strip strip;
    NJS_MESHSET *meshset;
    NJS_MATERIAL *mats;
    struct polygon *polygon;
    NJS_POINT3 *corner;
    int meshsets;
    int strips;
    Bool reversed;
    int i;
    Float x0;
    Float y0;
    Float z0;
    Float x1;
    Float y1;
    Float z1;
    Float x2;
    Float y2;
    Float z2;
    Float cx;
    Float cy;
    Float cz;
    Float span;
    Float span1;
    Float span2;
    Float radius;
    Float radius1;
    Float third;
    strip.model = object->model;
    meshsets = strip.model->nbMeshset;
    for (meshset = strip.model->meshsets; meshsets > 0; meshsets--, meshset++) {
        switch (strip.kind = meshset->type_matId & 0xc000) {
        case 0x0000:
            strip.count = 3;
            break;
        case 0x4000:
            strip.count = 4;
            break;
        case 0x8000:
        case 0xc000:
            break;
        default:
            continue;
        }
        strips = meshset->nbMesh;
        strip.indices = meshset->meshes;
        for (; strips > 0; strips--) {
            reversed = FUN_8c028666(&strip);
            for (i = 0, corner = strip.points; i < strip.count - 2;
                 i++, corner++) {
                x0 = corner[0].x;
                x1 = corner[1].x;
                x2 = corner[2].x;
                y0 = corner[0].y;
                y1 = corner[1].y;
                y2 = corner[2].y;
                z0 = corner[0].z;
                z1 = corner[1].z;
                z2 = corner[2].z;
                third = 0.3333F;
                cx = (x0 + x1 + x2) * third;
                cy = (y0 + y1 + y2) * third;
                cz = (z0 + z1 + z2) * third;
                if ((polygon = polygon_alloc(cz - mesh_center_z)) != ((void *)0)) {
                    if (!((reversed + i) & 1)) {
                        polygon->vertex[0].x = x0;
                        polygon->vertex[0].y = y0;
                        polygon->vertex[0].z = z0;
                        polygon->vertex[1].x = x1;
                        polygon->vertex[1].y = y1;
                        polygon->vertex[1].z = z1;
                        polygon->vertex[2].x = x2;
                        polygon->vertex[2].y = y2;
                        polygon->vertex[2].z = z2;
                    } else {
                        polygon->vertex[0].x = x0;
                        polygon->vertex[0].y = y0;
                        polygon->vertex[0].z = z0;
                        polygon->vertex[1].x = x2;
                        polygon->vertex[1].y = y2;
                        polygon->vertex[1].z = z2;
                        polygon->vertex[2].x = x1;
                        polygon->vertex[2].y = y1;
                        polygon->vertex[2].z = z1;
                    }
                    span = ((Float)_builtin_fabsf((Float)(z1 - z0)));
                    span1 = ((Float)_builtin_fabsf((Float)(z2 - z1)));
                    span2 = ((Float)_builtin_fabsf((Float)(z0 - z2)));
                    if (span1 > span) {
                        span = span1;
                    }
                    if (span2 > span) {
                        span = span2;
                    }
                    if (span > mesh_span) {
                        mesh_span = span;
                    }
                    x0 -= cx;
                    y0 -= cy;
                    z0 -= cz;
                    x1 -= cx;
                    y1 -= cy;
                    z1 -= cz;
                    x2 -= cx;
                    y2 -= cy;
                    z2 -= cz;
                    polygon->center.x = cx;
                    polygon->center.y = cy;
                    polygon->center.z = cz;
                    radius = vector_length_squared(x0, y0, z0);
                    radius1 = vector_length_squared(x1, y1, z1);
                    if (radius1 > radius) {
                        radius = radius1;
                    }
                    radius1 = vector_length_squared(x2, y2, z2);
                    if (radius1 > radius) {
                        radius = radius1;
                    }
                    polygon->radius = radius;
                    mats = object->model->mats;
                    if (mats != ((void *)0)) {
                        polygon->attr =
                            mats[meshset->type_matId & ~0xc000]
                                .attrflags;
                    } else {
                        polygon->attr = 0;
                    }
                } else {
                    return (0);
                }
            }
        }
    }
    return (1);
}
NJS_OBJECT *mesh_add_tree(NJS_OBJECT *object, Sint32 flags,
                                 struct collision_mesh *mesh)
{
    NJS_OBJECT *child;
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), (NJS_VECTOR *)object->pos);
    ((object->ang[2]) ? (njRotateZ)(((void *)0), (object->ang[2])) : (void)0);
    ((object->ang[1]) ? (njRotateY)(((void *)0), (object->ang[1])) : (void)0);
    ((object->ang[0]) ? (njRotateX)(((void *)0), (object->ang[0])) : (void)0);
    njScaleV(((void *)0), (NJS_VECTOR *)object->scl);
    child = object->child;
    while (child != ((void *)0)) {
        child = mesh_add_tree(child, flags, mesh);
    }
    if (!mesh_add_model(object, flags, mesh)) {
        njPopMatrix(1);
        return ((void *)0);
    }
    njPopMatrix(1);
    return object->sibling;
}
Float polygon_distance2(Float *from, Float *to)
{
    Float x;
    Float y;
    Float z;
    Float to_x;
    Float to_y;
    Float to_z;
    x = *from++;
    to_x = *to++;
    y = *from++;
    to_y = *to++;
    x = x - to_x;
    z = *from;
    to_z = *to;
    y = y - to_y;
    z = z - to_z;
    return (x * x) + (y * y) + (z * z);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int CL_ColPolListUpNear(struct polygon_ball *ball)
{
    struct polygon **near;
    struct collision_mesh *mesh;
    struct polygon *polygon;
    struct polygon *last;
    Bool found;
    struct world_object *object;
    int i;
    Float reach;
    Float reach2;
    Float low;
    Float high;
    Float z;
    Float dx;
    Float dy;
    Float dz;
    Float distance2;
    Float limit;
    near_polygon_count = 0;
    near = near_polygons;
    reach = njScalor(&ball->speed) + ball->radius;
    reach2 = reach * reach;
    ListGroundForCollision(ball->pos.x, ball->pos.y, ball->pos.z, ball->radius);
    for (mesh = collision_mesh_list; mesh != ((void *)0); mesh = mesh->next) {
        mesh->near = ((void *)0);
        mesh->near_count = 0;
        found = (0);
        for (i = LandCollList, object = numLandCollList; i > 0; i--, object++) {
            if (object->object == mesh->object) {
                found = (1);
                break;
            }
        }
        if (!found) {
            continue;
        }
        polygon = mesh->polygons;
        last = mesh->last;
        z = ball->pos.z;
        low = z - mesh->span - reach;
        high = z + mesh->span + reach;
        if (polygon->center.z < low && last->center.z > high) {
            while (polygon->center.z <= low) {
                if ((polygon = polygon->next) == ((void *)0)) {
                    break;
                }
            }
        }
        if (polygon != ((void *)0) && polygon->center.z > low) {
            for (; polygon != ((void *)0) && polygon->center.z < high;
                 polygon = polygon->next) {
                limit = (reach2 + polygon->radius) * 1.3F;
                dx = polygon->center.x;
                dy = polygon->center.y;
                dz = polygon->center.z;
                dx -= ball->pos.x;
                dy -= ball->pos.y;
                dz -= ball->pos.z;
                distance2 = (dx * dx) + (dy * dy) + (dz * dz);
                if (distance2 > limit) {
                    continue;
                }
                if (!mesh->near) {
                    mesh->near = near;
                }
                mesh->near_count++;
                *near = polygon;
                near++;
                if (++near_polygon_count == 96) {
                    if (debug_hidden >= 0) {
                        njPrintC(((2) << 16 | (21)),
                                 "WARNING: NEAR-poly is FULL");
                    }
                    goto end;
                }
            }
        } else {
            for (polygon = last; polygon->center.z > low && polygon != ((void *)0);
                 polygon = polygon->prev) {
                limit = (reach2 + polygon->radius) * 1.3F;
                dx = polygon->center.x;
                dy = polygon->center.y;
                dz = polygon->center.z;
                dx -= ball->pos.x;
                dy -= ball->pos.y;
                dz -= ball->pos.z;
                distance2 = (dx * dx) + (dy * dy) + (dz * dz);
                if (distance2 > limit) {
                    continue;
                }
                if (!mesh->near) {
                    mesh->near = near;
                }
                mesh->near_count++;
                *near = polygon;
                near++;
                if (++near_polygon_count == 96) {
                    if (debug_hidden >= 0) {
                        njPrintC(((2) << 16 | (21)),
                                 "WARNING: NEAR-poly is FULL");
                    }
                    goto end;
                }
            }
        }
    }
end:
    return near_polygon_count;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool collision_mesh_init(void)
{
    struct collision_mesh *mesh;
    struct polygon *polygon;
    int i;
    near_polygon_count = 0;
    touch_polygon_count = 0;
    collision_mesh_list = ((void *)0);
    mesh_stale_object = ((void *)0);
    for (i = 192, mesh = mesh_pool; i > 0; i--, mesh++) {
        mesh->object = ((void *)0);
    }
    for (i = 8192, polygon = polygon_pool; i > 0; i--, polygon++) {
        polygon->radius = 0.0F;
    }
    polygon_pool_init(polygon_pool, 8192);
    collision_mesh_pool_init(mesh_pool, 192);
    return (1);
}
void collision_mesh_collect_all(void)
{
    mesh_collect_all = 1;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool FUN_8c028ec2(void)
{
    NJS_OBJECT *objects[192];
    Sint32 flags[192];
    NJS_POINT3 center;
    NJS_OBJECT **object;
    Sint32 *flag;
    struct world_object *entry;
    struct collision_mesh *mesh;
    struct collision_mesh *next;
    struct polygon *polygon;
    NJS_OBJECT *root;
    NJS_MATRIX *matrix;
    int count;
    Bool found;
    int wanted;
    int i;
    int free;
    int most;
    int total;
    int used;
    if (!mesh_collect_all) {
        FUN_8c052518();
    } else {
        FUN_8c052e30();
        mesh_collect_all = (0);
    }
    do {
        wanted = 0;
        object = objects;
        flag = flags;
        if ((count = LandCollList) > 192) {
            count = 192;
        }
        for (entry = numLandCollList; count > 0; count--, entry++) {
            if (entry->flags & 0x08000000) {
                *object = entry->object;
                object++;
                wanted++;
                *flag = entry->flags;
                flag++;
            } else if (mesh_stale_object == entry->object) {
                wanted++;
                mesh_stale_object = ((void *)0);
                *object = entry->object;
                object++;
                *flag = entry->flags;
                flag++;
            } else {
                found = (0);
                for (mesh = collision_mesh_list; mesh != ((void *)0);
                     mesh = mesh->next) {
                    if (mesh->object == entry->object) {
                        found = (1);
                        break;
                    }
                }
                if (found) {
                    continue;
                }
                wanted++;
                *object++ = entry->object;
                *flag = entry->flags;
                flag++;
                if (wanted == 192) {
                    break;
                }
            }
        }
        if (wanted == 192) {
            break;
        }
        for (mesh = collision_mesh_list; mesh != ((void *)0); mesh = next) {
            found = (0);
            for (i = LandCollList, entry = numLandCollList; i > 0; i--, entry++) {
                if (mesh->object == entry->object) {
                    if ((entry->flags & 0x08000000) ||
                        mesh_stale_object == entry->object) {
                        found = (0);
                    } else {
                        found = (1);
                    }
                    break;
                }
            }
            next = mesh->next;
            if (!found) {
                collision_mesh_free(mesh);
            }
        }
    } while (0);
    njPushMatrix(&nj_unit_matrix_);
    flag = flags;
    object = objects;
    i = wanted;
    matrix = &nj_unit_matrix_;
    if (i > 0) {
        do {
            mesh = FUN_8c02cef4();
            collision_mesh_clear_buckets();
            njPushMatrix(matrix);
            root = *object;
            njTranslateV(((void *)0), (NJS_VECTOR *)root->pos);
            ((root->ang[2]) ? (njRotateZ)(((void *)0), (root->ang[2])) : (void)0);
            ((root->ang[1]) ? (njRotateY)(((void *)0), (root->ang[1])) : (void)0);
            ((root->ang[0]) ? (njRotateX)(((void *)0), (root->ang[0])) : (void)0);
            njScaleV(((void *)0), (NJS_VECTOR *)root->scl);
            center.x = root->model->center.x;
            center.y = root->model->center.y;
            center.z = root->model->center.z;
            njCalcPoint(((void *)0), &center, &center);
            mesh_center_z = center.z;
            mesh->center.x = center.x;
            mesh->center.y = center.y;
            mesh->center.z = center.z;
            njPopMatrix(1);
            mesh_unk_2c_value = mesh_span = 0.0F;
            mesh->object = *object;
            mesh->flags = *flag;
            mesh->polygons = ((void *)0);
            mesh->unk_18 = 0;
            mesh->near = ((void *)0);
            mesh->near_count = 0;
            mesh_add_tree(*object++, *flag, mesh);
            collision_mesh_take_buckets(mesh);
            mesh->span = mesh_span;
            mesh->unk_2c = mesh_unk_2c_value;
            flag++;
        } while (--i > 0);
    }
    njPopMatrix(1);
    if (debug_hidden >= 0) {
        njPrintC(((2) << 16 | (27)), "colbuf:");
        most = 0;
        total = 0;
        for (i = 192, mesh = mesh_pool, free = 0; i > 0; i--, mesh++) {
            if (mesh->object == ((void *)0)) {
                free++;
            } else {
                count = 0;
                for (polygon = mesh->polygons; polygon != ((void *)0);
                     polygon = polygon->next) {
                    count++;
                }
                if (most < count) {
                    most = count;
                }
                total += count;
            }
        }
        used = 100 - (free * 100 / 192);
        njPrintC(((10) << 16 | (26)), "obj:");
        if (used >= 95) {
            njPrintColor(0xffff8080);
            FUN_8c6409c0(((15) << 16 | (26)), used, 3);
            njPrintC(((18) << 16 | (26)), "%");
            njPrintColor(0xffffffff);
        } else {
            FUN_8c6409c0(((15) << 16 | (26)), used, 3);
            njPrintC(((18) << 16 | (26)), "%");
        }
        FUN_8c6409c0(((20) << 16 | (26)), 192 - free, 5);
        if (free == 0 && debug_hidden >= 0) {
            njPrintC(((2) << 16 | (19)), "WARNING: OBJECT buf is FULL");
        }
        njPrintC(((27) << 16 | (26)), "polMAX:");
        FUN_8c6409c0(((35) << 16 | (26)), most, 4);
        used = total * 100 / 8192;
        njPrintC(((10) << 16 | (27)), "r-p:");
        if (used >= 95) {
            njPrintColor(0xffff8080);
            FUN_8c6409c0(((15) << 16 | (27)), used, 3);
            njPrintC(((18) << 16 | (27)), "%");
            njPrintColor(0xffffffff);
        } else {
            FUN_8c6409c0(((15) << 16 | (27)), used, 3);
            njPrintC(((18) << 16 | (27)), "%");
        }
        FUN_8c6409c0(((20) << 16 | (27)), total, 5);
        if (free == 0 && debug_hidden >= 0) {
            njPrintC(((2) << 16 | (20)), "WARNING: RANGE-poly buf is FULL");
        }
    }
    return (1);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool polygon_find_sides(struct sides_query *query, NJS_OBJECT *object,
                        Uint32 flags)
{
    NJS_POINT3 *p0;
    NJS_POINT3 *p1;
    NJS_POINT3 *p2;
    struct surface *side;
    struct collision_mesh *mesh;
    struct polygon *polygon;
    Float e1;
    Float e2;
    Float e3;
    Float plane;
    Float x;
    Float y;
    Float z;
    Sint32 mesh_flags;
    Bool found;
    Bool any;
    int i;
    any = (0);
    for (i = SIDES, side = query->sides; i > 0; i--, side++) {
        side->found = (0);
    }
    query->sides[SIDE_MINUS_X].level = query->pos.x + 220.0F;
    query->sides[SIDE_PLUS_X].level = query->pos.x - 220.0F;
    query->sides[SIDE_BELOW].level = query->pos.y + 220.0F;
    query->sides[SIDE_ABOVE].level = query->pos.y - 220.0F;
    query->sides[SIDE_MINUS_Z].level = query->pos.z + 220.0F;
    query->sides[SIDE_PLUS_Z].level = query->pos.z - 220.0F;
    found = (0);
    for (mesh = collision_mesh_list; mesh != ((void *)0); mesh = mesh->next) {
        if (mesh->object == object) {
            found = (1);
            break;
        }
    }
    if (!found) {
        return (0);
    }
    if (0) { if (mesh) { } };
    polygon = mesh->polygons;
    mesh_flags = mesh->flags;
    for (; polygon != ((void *)0); polygon = polygon->next) {
        if (((polygon->vertex[0].x - query->pos.x) *
             (polygon->vertex[0].x - query->pos.x)) +
                ((polygon->vertex[0].y - query->pos.y) *
                 (polygon->vertex[0].y - query->pos.y)) +
                ((polygon->vertex[0].z - query->pos.z) *
                 (polygon->vertex[0].z - query->pos.z)) >
            220.0F * 220.0F) {
            continue;
        }
        p0 = &polygon->vertex[0];
        p1 = &polygon->vertex[1];
        p2 = &polygon->vertex[2];
        do {
            NJS_VECTOR normal;
            if (0) { if (&njPrintC) { } };
            e1 = ((((p1)->x - (p0)->x) * ((&query->pos)->y - (p0)->y)) - (((p1)->y - (p0)->y) * ((&query->pos)->x - (p0)->x)));
            e2 = ((((p2)->x - (p1)->x) * ((&query->pos)->y - (p1)->y)) - (((p2)->y - (p1)->y) * ((&query->pos)->x - (p1)->x)));
            e3 = ((((p0)->x - (p2)->x) * ((&query->pos)->y - (p2)->y)) - (((p0)->y - (p2)->y) * ((&query->pos)->x - (p2)->x)));
            if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                break;
            }
            if (0) { if (any) { } };
            FUN_8c027360((const char *)p0, (const char *)p1,
                            (const char *)p2, &normal);
            plane =
                -(normal.x * p0->x) - (normal.y * p0->y) - (normal.z * p0->z);
            if (normal.z * normal.z < 0.01F * 0.01F) {
                break;
            }
            z = (-(normal.x * query->pos.x) - (normal.y * query->pos.y) -
                 plane) /
                normal.z;
            side = ((void *)0);
            if (z < query->pos.z) {
                if (!query->sides[SIDE_MINUS_Z].found ||
                    z > query->sides[SIDE_MINUS_Z].level) {
                    side = &query->sides[SIDE_MINUS_Z];
                }
            } else {
                if (!query->sides[SIDE_PLUS_Z].found ||
                    z < query->sides[SIDE_PLUS_Z].level) {
                    side = &query->sides[SIDE_PLUS_Z];
                }
            }
            if (side == ((void *)0)) {
                break;
            }
            if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
            any = (1);
            side->found = (1);
            side->flags = mesh_flags;
            side->level = z;
            side->normal = normal;
            side->ang_z =
                -(Angle)(njArcTan2(normal.x, normal.y) * (65536.0 / (2 * 3.141592)));
            side->ang_x = (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
        } while (0);
        do {
            NJS_VECTOR normal;
            if (0) { if (&njPrintC) { } };
            e1 = ((((p1)->y - (p0)->y) * ((&query->pos)->z - (p0)->z)) - (((p1)->z - (p0)->z) * ((&query->pos)->y - (p0)->y)));
            e2 = ((((p2)->y - (p1)->y) * ((&query->pos)->z - (p1)->z)) - (((p2)->z - (p1)->z) * ((&query->pos)->y - (p1)->y)));
            e3 = ((((p0)->y - (p2)->y) * ((&query->pos)->z - (p2)->z)) - (((p0)->z - (p2)->z) * ((&query->pos)->y - (p2)->y)));
            if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                break;
            }
            FUN_8c027360((const char *)p0, (const char *)p1,
                            (const char *)p2, &normal);
            plane =
                -(normal.x * p0->x) - (normal.y * p0->y) - (normal.z * p0->z);
            if (normal.x * normal.x < 0.01F * 0.01F) {
                break;
            }
            x = (-(normal.y * query->pos.y) - (normal.z * query->pos.z) -
                 plane) /
                normal.x;
            side = ((void *)0);
            if (x < query->pos.x) {
                if (!query->sides[SIDE_MINUS_X].found ||
                    x > query->sides[SIDE_MINUS_X].level) {
                    side = &query->sides[SIDE_MINUS_X];
                }
            } else {
                if (!query->sides[SIDE_PLUS_X].found ||
                    x < query->sides[SIDE_PLUS_X].level) {
                    side = &query->sides[SIDE_PLUS_X];
                }
            }
            if (side == ((void *)0)) {
                break;
            }
            if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
            any = (1);
            side->found = (1);
            side->flags = mesh_flags;
            side->level = x;
            side->normal = normal;
            side->ang_z =
                -(Angle)(njArcTan2(normal.x, normal.y) * (65536.0 / (2 * 3.141592)));
            side->ang_x = (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
        } while (0);
        do {
            NJS_VECTOR normal;
            if (0) { if (&njPrintC) { } };
            e1 = ((((p1)->z - (p0)->z) * ((&query->pos)->x - (p0)->x)) - (((p1)->x - (p0)->x) * ((&query->pos)->z - (p0)->z)));
            e2 = ((((p2)->z - (p1)->z) * ((&query->pos)->x - (p1)->x)) - (((p2)->x - (p1)->x) * ((&query->pos)->z - (p1)->z)));
            e3 = ((((p0)->z - (p2)->z) * ((&query->pos)->x - (p2)->x)) - (((p0)->x - (p2)->x) * ((&query->pos)->z - (p2)->z)));
            if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                break;
            }
            FUN_8c027360((const char *)p0, (const char *)p1,
                            (const char *)p2, &normal);
            plane =
                -(normal.x * p0->x) - (normal.y * p0->y) - (normal.z * p0->z);
            if (normal.y * normal.y < 0.01F * 0.01F) {
                break;
            }
            y = (-(normal.z * query->pos.z) - (normal.x * query->pos.x) -
                 plane) /
                normal.y;
            side = ((void *)0);
            if (y < query->pos.y) {
                if (!query->sides[SIDE_BELOW].found ||
                    y > query->sides[SIDE_BELOW].level) {
                    side = &query->sides[SIDE_BELOW];
                }
            } else {
                if (!query->sides[SIDE_ABOVE].found ||
                    y < query->sides[SIDE_ABOVE].level) {
                    side = &query->sides[SIDE_ABOVE];
                }
            }
            if (side == ((void *)0)) {
                break;
            }
            if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
            any = (1);
            side->found = (1);
            side->flags = mesh_flags;
            side->level = y;
            side->normal = normal;
            side->ang_z =
                -(Angle)(njArcTan2(normal.x, normal.y) * (65536.0 / (2 * 3.141592)));
            side->ang_x = (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
        } while (0);
    }
    return any;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object, Uint32 flags)
{
    struct collision_mesh *mesh;
    struct polygon **near;
    struct touch_polygon *touch;
    struct polygon_contact *hit_contact;
    struct touch_polygon *touched;
    struct polygon_contact *listed;
    Bool found;
    int count;
    Bool hit;
    Bool more;
    Uint32 two_sided;
    int nearest;
    int i;
    Float length;
    Float spacing;
    Float travelled;
    Float radius;
    Float height;
    Float scale;
    Float e1;
    Float e2;
    Float e3;
    NJS_POINT3 tri[3];
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    NJS_VECTOR normal;
    NJS_VECTOR stride;
    NJS_POINT3 at;
    struct polygon_contact contact;
    NJS_VECTOR part;
    if (ball->radius <= 0.0F) {
        return (0);
    }
    touch_polygon_count = 0;
    length = njScalor(&ball->speed);
    spacing = ball->radius * 0.5F;
    touch = touch_polygons;
    found = (0);
    for (mesh = collision_mesh_list; mesh != ((void *)0); mesh = mesh->next) {
        if (mesh->object == object) {
            found = (1);
            break;
        }
        if (0) { if (mesh) { } };
    }
    if (0) { if (found) { } };
    if (!found) {
        return (0);
    }
    for (count = mesh->near_count, near = mesh->near; count > 0;
         count--, near++) {
        Float *v0;
        Float *v1;
        Float *v2;
        Float *edge;
        Float x0;
        Float y0;
        Float z0;
        Float x;
        Float y;
        Float z;
        NJS_POINT3 *vertex;
        tri[0].x = tri[0].y = tri[0].z = 0.0F;
        vertex = &(*near)->vertex[0];
        v0 = &vertex->x;
        v1 = &vertex[1].x;
        v2 = &vertex[2].x;
        if (0) { if (v0) { } };
        x0 = *v0++;
        x = *v1++ - x0;
        y0 = *v0++;
        y = *v1++ - y0;
        z0 = *v0;
        z = *v1 - z0;
        edge = &tri[1].x + 3;
        *--edge = z;
        *--edge = y;
        *--edge = x;
        x = *v2++ - x0;
        y = *v2++;
        z = *v2 - z0;
        y -= y0;
        edge = &tri[2].x + 3;
        *--edge = z;
        if (0) { if (x) { } };
        *--edge = y;
        *--edge = x;
        if (0) { if (x0) { } };
        pos.x = ball->pos.x - x0;
        pos.y = ball->pos.y - y0;
        pos.z = ball->pos.z - z0;
        speed = ball->speed;
        njPushMatrix(&nj_unit_matrix_);
        FUN_8c027360((const char *)(NJS_POINT3 *)&tri[0].x,
                        (const char *)(NJS_POINT3 *)&tri[1].x,
                        (const char *)(NJS_POINT3 *)&tri[2].x, &normal);
        do {
            if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
        } while (0);
        if (-(Angle)(FUN_8c10cf48(normal.y) * (65536.0 / (2 * 3.141592)))) { (njRotateX)(((void *)0), (-(Angle)(FUN_8c10cf48(normal.y) * (65536.0 / (2 * 3.141592))))); } else { };
        if (-(Angle)(njArcTan2(normal.x, normal.z) * (65536.0 / (2 * 3.141592)))) { (njRotateY)(((void *)0), (-(Angle)(njArcTan2(normal.x, normal.z) * (65536.0 / (2 * 3.141592))))); } else { };
        njCalcPoint(((void *)0), &tri[1], &tri[1]);
        njCalcPoint(((void *)0), &tri[2], &tri[2]);
        njCalcPoint(((void *)0), &pos, &pos);
        njCalcPoint(((void *)0), &speed, &speed);
        radius = ball->radius;
        if ((two_sided = (*near)->attr & 0x00800000) != 0) {
            if (pos.y < 0.0F) {
                radius *= -1.0F;
            }
        } else {
        }
        hit = (0);
        stride = speed;
        if (njScalor(&stride) == 0.0F) { (&stride)->x = (&stride)->y = (&stride)->z = 0.0F; } else { njUnitVector(&stride); };
        stride.x *= spacing;
        stride.y *= spacing;
        stride.z *= spacing;
        travelled = 0.0F;
        at = pos;
        for (;;) {
            more = (1);
            if (travelled >= length) {
                more = (0);
                at = pos;
                at.x = pos.x + speed.x;
                at.y = pos.y + speed.y;
                at.z = pos.z + speed.z;
            }
            if (((Float)_builtin_fabsf((Float)(at.y))) <= ball->radius) {
                e1 = ((((&tri[1])->z - (&tri[0])->z) * ((&at)->x - (&tri[0])->x)) - (((&tri[1])->x - (&tri[0])->x) * ((&at)->z - (&tri[0])->z)));
                e2 = ((((&tri[2])->z - (&tri[1])->z) * ((&at)->x - (&tri[1])->x)) - (((&tri[2])->x - (&tri[1])->x) * ((&at)->z - (&tri[1])->z)));
                e3 = ((((&tri[0])->z - (&tri[2])->z) * ((&at)->x - (&tri[2])->x)) - (((&tri[0])->x - (&tri[2])->x) * ((&at)->z - (&tri[2])->z)));
                if (e1 * e2 >= 0.0F && e2 * e3 >= 0.0F && e1 * e3 >= 0.0F) {
                    hit = (1);
                    break;
                }
            }
            if (!more) {
                break;
            }
            at.x += stride.x;
            at.y += stride.y;
            at.z += stride.z;
            travelled += spacing;
            if (0) { if (spacing) { } };
            if (0) { if (spacing) { } };
        }
        if (hit) {
            if (debug_hidden >= 0) {
                touch_points[0] = (*near)->vertex[0];
                touch_points[1] = (*near)->vertex[1];
                touch_points[2] = (*near)->vertex[2];
                touch_points[0].x += normal.x;
                touch_points[1].x += normal.x;
                touch_points[2].x += normal.x;
                touch_points[0].y += normal.y;
                touch_points[1].y += normal.y;
                touch_points[2].y += normal.y;
                touch_points[0].z += normal.z;
                touch_points[1].z += normal.z;
                touch_points[2].z += normal.z;
                njGetMatrix(&touch_matrix);
                njPopMatrix(1);
                njDrawTriangle3D(&touch_triangle, 3, 0x00000020);
                njPushMatrix(&touch_matrix);
            }
            contact.height = pos.y;
            contact.height_after = pos.y + speed.y;
            contact.hit.front = normal;
            if (two_sided) {
                if (pos.y >= 0.0F) {
                    contact.hit.normal = normal;
                } else {
                    contact.hit.normal.x = -normal.x;
                    contact.hit.normal.y = -normal.y;
                    contact.hit.normal.z = -normal.z;
                }
            } else {
                contact.hit.normal = normal;
            }
            contact.hit.ang_z =
                -(Angle)(njArcTan2(contact.hit.normal.x, contact.hit.normal.y) *
                         (65536.0 / (2 * 3.141592)));
            contact.hit.ang_x =
                (Angle)(asinf(contact.hit.normal.z) * (65536.0 / (2 * 3.141592)));
            njInvertMatrix(((void *)0));
            stride.x = pos.x;
            stride.y = 0.0F;
            stride.z = pos.z;
            njCalcPoint(((void *)0), &stride, &at);
            contact.hit.point.x = at.x + (*near)->vertex[0].x;
            contact.hit.point.y = at.y + (*near)->vertex[0].y;
            contact.hit.point.z = at.z + (*near)->vertex[0].z;
            stride.y = radius;
            njCalcPoint(((void *)0), &stride, &at);
            contact.hit.pos.x = at.x + (*near)->vertex[0].x;
            contact.hit.pos.y = at.y + (*near)->vertex[0].y;
            contact.hit.pos.z = at.z + (*near)->vertex[0].z;
            part = speed;
            if (two_sided) {
                if (pos.y * speed.y < 0.0F) {
                    part.y = -speed.y;
                }
            } else if (radius * speed.y < 0.0F) {
                part.y = -speed.y;
            }
            part.x = speed.x;
            part.y = 0.0F;
            part.z = speed.z;
            njCalcPoint(((void *)0), &part, &at);
            contact.hit.speed = at;
            part.x = 0.0F;
            part.y = speed.y;
            part.z = 0.0F;
            njCalcPoint(((void *)0), &part, &at);
            contact.hit.normal_speed = at;
            touch->polygon = **near;
            touch->contact = contact;
            touch++;
            if (++touch_polygon_count == 16) {
                if (debug_hidden >= 0) {
                    njPrintC(((2) << 16 | (22)),
                             "WARNING: TOUCH-poly buf is FULL");
                }
                break;
            }
        }
        njPopMatrix(1);
        if (0) { if (&njPrintC) { } };
        if (0) { if (&njArcTan2) { } };
    }
    count = touch_polygon_count;
    if (count < 1) {
        return (0);
    }
    if (0) { if (count) { } };
    nearest = 0;
    height = touch_polygons[0].contact.height_after;
    for (i = 1, touched = &touch_polygons[1]; i < count; i++, touched++) {
        if (height > touched->contact.height_after) {
            height = touched->contact.height_after;
            nearest = i;
        }
    }
    if (0) { if (i) { } };
    for (i = count, touched = touch_polygons, listed = colihitdat; i > 0;
         i--, touched++, listed++) {
        *listed = touched->contact;
    }
    ball->count = touch_polygon_count;
    ball->hit_index = nearest;
    hit_contact = &touch_polygons[nearest].contact;
    ball->hit.ang_x = hit_contact->hit.ang_x;
    ball->hit.ang_z = hit_contact->hit.ang_z;
    ball->hit.front = hit_contact->hit.front;
    ball->hit.normal = hit_contact->hit.normal;
    ball->hit.speed = hit_contact->hit.speed;
    ball->hit.normal_speed = hit_contact->hit.normal_speed;
    if (touch_polygon_count == 1) {
        ball->hit.point = hit_contact->hit.point;
        ball->hit.pos = hit_contact->hit.pos;
    } else {
        touched = touch_polygons;
        ball->hit.point = touched->contact.hit.point;
        ball->hit.pos = touched->contact.hit.pos;
        touched++;
        for (i = touch_polygon_count - 1; i > 0; i--) {
            ball->hit.point.x += touched->contact.hit.point.x;
            ball->hit.point.y += touched->contact.hit.point.y;
            ball->hit.point.z += touched->contact.hit.point.z;
            ball->hit.pos.x += touched->contact.hit.pos.x;
            ball->hit.pos.y += touched->contact.hit.pos.y;
            ball->hit.pos.z += touched->contact.hit.pos.z;
            touched++;
        }
        scale = 1.0F / (Float)touch_polygon_count;
        ball->hit.point.x *= scale;
        ball->hit.point.y *= scale;
        ball->hit.point.z *= scale;
        ball->hit.pos.x *= scale;
        ball->hit.pos.y *= scale;
        ball->hit.pos.z *= scale;
    }
    return (1);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool CL_ColPolBeamHit(struct ray_query *query)
{
    int count;
    Bool met;
    Float distance;
    struct world_object *object;
    struct collision_mesh *mesh;
    struct polygon *polygon;
    NJS_POINT3 *v0;
    NJS_POINT3 *v1;
    NJS_POINT3 *v2;
    Bool found;
    Float reach2;
    Float gap;
    Float e1;
    Float e2;
    Float e3;
    met = (0);
    query->surface.found = (0);
    if (query->length < 0.01F || query->length > 400.0F) {
        query->length = 400.0F;
    }
    reach2 = query->length + 220.0F;
    reach2 *= reach2;
    ListGroundForCollision(query->origin.x, query->origin.y, query->origin.z,
                    query->length);
    for (count = LandCollList, object = numLandCollList; count > 0;
         count--, object++) {
        found = (0);
        for (mesh = collision_mesh_list; mesh != ((void *)0); mesh = mesh->next) {
            if (mesh->object == object->object) {
                found = (1);
                break;
            }
        }
        if (!found) {
            continue;
        }
        for (polygon = mesh->polygons; polygon != ((void *)0);
             polygon = polygon->next) {
            v0 = &polygon->vertex[0];
            v1 = &v0[1];
            v2 = &v0[2];
            {
                NJS_VECTOR to0;
                NJS_VECTOR to1;
                NJS_VECTOR to2;
                to0.x = v0->x - query->origin.x;
                to0.y = v0->y - query->origin.y;
                to0.z = v0->z - query->origin.z;
                to1.x = v1->x - query->origin.x;
                to1.y = v1->y - query->origin.y;
                to1.z = v1->z - query->origin.z;
                to2.x = v2->x - query->origin.x;
                to2.y = v2->y - query->origin.y;
                to2.z = v2->z - query->origin.z;
                if ((((&to0)->x * (&query->dir)->x) + ((&to0)->y * (&query->dir)->y) + ((&to0)->z * (&query->dir)->z)) < 0.0F &&
                    (((&to1)->x * (&query->dir)->x) + ((&to1)->y * (&query->dir)->y) + ((&to1)->z * (&query->dir)->z)) < 0.0F &&
                    (((&to2)->x * (&query->dir)->x) + ((&to2)->y * (&query->dir)->y) + ((&to2)->z * (&query->dir)->z)) < 0.0F) {
                    continue;
                }
            }
            {
                NJS_POINT3 tri[3];
                NJS_POINT3 *edge;
                NJS_POINT3 origin;
                NJS_VECTOR dir;
                NJS_VECTOR normal;
                NJS_POINT3 at;
                NJS_POINT3 out;
                edge = &tri[1];
                tri[0].x = tri[0].y = tri[0].z = 0.0F;
                *edge = *v1;
                tri[2] = *v2;
                edge->x -= v0->x;
                tri[2].x -= v0->x;
                edge->y -= v0->y;
                tri[2].y -= v0->y;
                edge->z -= v0->z;
                tri[2].z -= v0->z;
                origin.x = query->origin.x - v0->x;
                origin.y = query->origin.y - v0->y;
                origin.z = query->origin.z - v0->z;
                dir = query->dir;
                FUN_8c027360((const char *)&tri[0], (const char *)edge,
                                (const char *)&tri[2], &normal);
                if (!(polygon->attr & 0x00800000)) {
                    if ((((&normal)->x * (&dir)->x) + ((&normal)->y * (&dir)->y) + ((&normal)->z * (&dir)->z)) > -0.01F) {
                        continue;
                    }
                }
                if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
                gap = (normal.x * origin.x) + (normal.y * origin.y) +
                      (normal.z * origin.z);
                gap *= gap;
                if (gap > reach2) {
                    continue;
                }
                njPushMatrix(&nj_unit_matrix_);
                if (-(Angle)(FUN_8c10cf48(normal.y) * (65536.0 / (2 * 3.141592)))) { (njRotateX)(((void *)0), (-(Angle)(FUN_8c10cf48(normal.y) * (65536.0 / (2 * 3.141592))))); } else { };
                if (-(Angle)(njArcTan2(normal.x, normal.z) * (65536.0 / (2 * 3.141592)))) { (njRotateY)(((void *)0), (-(Angle)(njArcTan2(normal.x, normal.z) * (65536.0 / (2 * 3.141592))))); } else { };
                njCalcPoint(((void *)0), &tri[1], &at);
                do {
                    tri[1] = at;
                    njCalcPoint(((void *)0), &tri[2], &at);
                    tri[2] = at;
                    njCalcPoint(((void *)0), &origin, &at);
                    origin = at;
                    njCalcPoint(((void *)0), &dir, &at);
                    dir = at;
                    if (origin.y >= 0.0F) {
                        if (dir.y > -0.01F) {
                            break;
                        }
                    } else if (dir.y < 0.01F) {
                        break;
                    }
                    at.x = -(dir.x * origin.y / dir.y) + origin.x;
                    at.z = -(dir.z * origin.y / dir.y) + origin.z;
                    at.y = 0.0F;
                    e1 = ((((&tri[1])->z - (&tri[0])->z) * ((&at)->x - (&tri[0])->x)) - (((&tri[1])->x - (&tri[0])->x) * ((&at)->z - (&tri[0])->z)));
                    e2 = ((((&tri[2])->z - (&tri[1])->z) * ((&at)->x - (&tri[1])->x)) - (((&tri[2])->x - (&tri[1])->x) * ((&at)->z - (&tri[1])->z)));
                    e3 = ((((&tri[0])->z - (&tri[2])->z) * ((&at)->x - (&tri[2])->x)) - (((&tri[0])->x - (&tri[2])->x) * ((&at)->z - (&tri[2])->z)));
                    if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                        break;
                    }
                    if ((distance = CalcDistance(&origin, &at)) >
                        query->length) {
                        break;
                    }
                    njInvertMatrix(((void *)0));
                    njCalcPoint(((void *)0), &at, &out);
                    at.x = out.x + v0->x;
                    at.y = out.y + v0->y;
                    at.z = out.z + v0->z;
                    if (!met || query->distance > distance) {
                        met = (1);
                        query->distance = distance;
                        query->hit = at;
                        query->surface.found = (1);
                        query->surface.flags = object->flags;
                        query->surface.ang_x =
                            (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
                        query->surface.ang_z =
                            -(Angle)(njArcTan2(normal.x, normal.y) *
                                     (65536.0 / (2 * 3.141592)));
                        query->surface.normal = normal;
                        reach2 = query->length + 220.0F;
                        reach2 *= reach2;
                    }
                } while (0);
                njPopMatrix(1);
            }
        }
    }
    if (0) { if (polygon) { } };
    if (0) { if (asinf(-0.01F)) { } };
    return met;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool polygon_find_near_heights(struct height_query *query, Float radius)
{
    struct height_query farthest;
    struct world_object *object;
    Bool any;
    int i;
    any = (0);
    farthest.below.found = (0);
    farthest.above.found = (0);
    ListGroundForCollision(query->pos.x, query->pos.y, query->pos.z, radius);
    for (i = LandCollList, object = numLandCollList; i > 0; i--, object++) {
        if (find_model_heights_near(query, object->object, object->flags) ==
            (1)) {
            if (query->below.found == (1)) {
                if (!farthest.below.found) {
                    any = (1);
                    farthest.below.found = (1);
                    farthest.below.level = query->below.level;
                } else if (farthest.below.level > query->below.level) {
                    farthest.below.level = query->below.level;
                }
            }
            if (query->above.found == (1)) {
                if (!farthest.above.found) {
                    any = (1);
                    farthest.above.found = (1);
                    farthest.above.level = query->above.level;
                } else if (farthest.above.level < query->above.level) {
                    farthest.above.level = query->above.level;
                }
            }
        }
    }
    query->below = farthest.below;
    query->above = farthest.above;
    return any;
}
void polygon_normal(const char *v0, const char *v1, const char *v2,
                    NJS_VECTOR *normal)
{
    Float ux;
    Float uy;
    Float uz;
    Float vx;
    Float vy;
    Float vz;
    vx = *(const Float *)v0;
    v0 += sizeof(Float);
    ux = *(const Float *)v1 - vx;
    v1 += sizeof(Float);
    uy = *(const Float *)v1 - (vy = *(const Float *)v0);
    v1 += sizeof(Float);
    v0 += sizeof(Float);
    vz = *(const Float *)v0;
    uz = *(const Float *)v1;
    vx -= *(const Float *)v2;
    v2 += sizeof(Float);
    vy -= *(const Float *)v2;
    v2 += sizeof(Float);
    uz -= vz;
    vz -= *(const Float *)v2;
    normal->x = (uz * vy) - (uy * vz);
    normal->y = (ux * vz) - (uz * vx);
    normal->z = (uy * vx) - (ux * vy);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool collision_segment_nearest(NJS_POINT3 *start, NJS_POINT3 *end,
                               NJS_POINT3 *point, NJS_POINT3 *nearest,
                               Float *distance2)
{
    NJS_VECTOR along;
    NJS_VECTOR past_start;
    NJS_VECTOR short_of_end;
    NJS_VECTOR away;
    Float part;
    along.x = end->x - start->x;
    along.y = end->y - start->y;
    along.z = end->z - start->z;
    past_start.x = point->x - start->x;
    past_start.y = point->y - start->y;
    past_start.z = point->z - start->z;
    short_of_end.x = end->x - point->x;
    short_of_end.y = end->y - point->y;
    short_of_end.z = end->z - point->z;
    if ((along.x * past_start.x) + (along.y * past_start.y) +
                (along.z * past_start.z) <
            0.0F ||
        (along.x * short_of_end.x) + (along.y * short_of_end.y) +
                (along.z * short_of_end.z) <
            0.0F) {
        return (0);
    }
    if (along.x * along.x < 0.01F * 0.01F &&
        along.y * along.y < 0.01F * 0.01F &&
        along.z * along.z < 0.01F * 0.01F) {
        *distance2 = (past_start.x * past_start.x) +
                     (past_start.y * past_start.y) +
                     (past_start.z * past_start.z);
        return (1);
    }
    part =
        ((along.x * (point->x - start->x)) + (along.y * (point->y - start->y)) +
         (along.z * (point->z - start->z))) /
        ((along.x * along.x) + (along.y * along.y) + (along.z * along.z));
    nearest->x = start->x + (part * along.x);
    nearest->y = start->y + (part * along.y);
    nearest->z = start->z + (part * along.z);
    away.x = nearest->x - point->x;
    away.y = nearest->y - point->y;
    away.z = nearest->z - point->z;
    *distance2 = (away.x * away.x) + (away.y * away.y) + (away.z * away.z);
    return (1);
}
Float polygon_point_distance2_across(NJS_POINT3 *from, NJS_POINT3 *to)
{
    Float dx = to->x - from->x;
    Float dz = to->z - from->z;
    return (dx * dx) + (dz * dz);
}
Float polygon_point_distance2(NJS_POINT3 *from, NJS_POINT3 *to)
{
    Float dx = to->x - from->x;
    Float dy = to->y - from->y;
    Float dz = to->z - from->z;
    return (dx * dx) + (dy * dy) + (dz * dz);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Float collision_segment_distance(NJS_POINT3 *point, NJS_POINT3 *start,
                                 NJS_POINT3 *end, NJS_POINT3 *nearest)
{
    NJS_LINE line;
    Float x;
    Float y;
    Float z;
    if (vector_dot_from(start, end, point) < 0.0F) {
        if (nearest != ((void *)0)) {
            *nearest = *start;
        }
        return CalcDistance(point, start);
    }
    if (vector_dot_from(end, start, point) < 0.0F) {
        if (nearest != ((void *)0)) {
            *nearest = *end;
        }
        return CalcDistance(point, end);
    }
    x = start->x;
    y = start->y;
    z = start->z;
    line.px = x;
    line.py = y;
    line.pz = z;
    line.vx = end->x - x;
    line.vy = end->y - y;
    line.vz = end->z - z;
    return FUN_8c63fec4(point, &line, nearest);
}
NJS_OBJECT *polygon_cast_segment(struct segment_query *query, NJS_OBJECT *first)
{
    NJS_VECTOR away;
    struct world_object *objects;
    NJS_POINT3 *pos;
    NJS_VECTOR *dir;
    NJS_OBJECT *skip;
    NJS_OBJECT *object;
    int i;
    Float reach;
    Float scale;
    Float distance;
    pos = &query->pos;
    dir = &query->dir;
    if ((skip = first) != ((void *)0)) {
        if ((first = segment_cross_mesh(query, first, query->flags)) != ((void *)0)) {
            return first;
        }
    }
    ListGroundForCollision(pos->x, pos->y, pos->z, 5.0F);
    if (LandCollList == 0) {
        return ((void *)0);
    }
    objects = numLandCollList;
    for (i = 0; i < LandCollList; i++) {
        if ((object = objects[i].object) == ((void *)0)) {
            continue;
        }
        if (object == skip) {
            continue;
        }
        if (objects[i].owner != ((void *)0)) {
            reach = njSqrt((dir->x * dir->x) + (dir->z * dir->z));
            scale = object->scl[0];
            if (scale < object->scl[1]) {
                scale = object->scl[1];
            }
            if (scale < object->scl[2]) {
                scale = object->scl[2];
            }
            reach += object->model->r * scale;
            away.x = object->pos[0] - pos->x;
            away.z = object->pos[2] - pos->z;
            distance = njSqrt((away.x * away.x) + (away.z * away.z));
            if (distance > reach + 1.0F) {
                continue;
            }
        }
        if ((first = segment_cross_mesh(query, object, objects[i].flags)) !=
            ((void *)0)) {
            return first;
        }
    }
    return ((void *)0);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
NJS_OBJECT *segment_cross_mesh(struct segment_query *query,
                                      NJS_OBJECT *object, Sint32 flags)
{
    NJS_VECTOR *dir;
    struct collision_mesh *mesh;
    struct polygon *polygon;
    NJS_OBJECT *crossed;
    NJS_POINT3 hit;
    NJS_VECTOR temp;
    NJS_VECTOR normal;
    NJS_VECTOR first;
    NJS_VECTOR second;
    NJS_VECTOR third;
    NJS_POINT3 *pos;
    NJS_POINT3 *v0;
    NJS_POINT3 *v1;
    NJS_POINT3 *v2;
    Float part;
    Float height;
    pos = &query->pos;
    dir = &query->dir;
    crossed = ((void *)0);
    for (mesh = collision_mesh_list; mesh != ((void *)0); mesh = mesh->next) {
        if (mesh->object == object) {
            for (polygon = mesh->polygons; polygon != ((void *)0);
                 polygon = polygon->next) {
                v0 = &polygon->vertex[0];
                v1 = &polygon->vertex[1];
                v2 = &polygon->vertex[2];
                first.x = v1->x - v0->x;
                first.y = v1->y - v0->y;
                first.z = v1->z - v0->z;
                second.x = v2->x - v0->x;
                second.y = v2->y - v0->y;
                second.z = v2->z - v0->z;
                normal.x = (first.y * second.z) - (first.z * second.y);
                normal.y = (first.z * second.x) - (first.x * second.z);
                normal.z = (first.x * second.y) - (first.y * second.x);
                if ((part = njInnerProduct(dir, &normal)) >= -0.000001F) {
                    continue;
                }
                temp.x = pos->x - v0->x;
                temp.y = pos->y - v0->y;
                temp.z = pos->z - v0->z;
                if ((height = njInnerProduct(&temp, &normal)) <= 0.000001F) {
                    continue;
                }
                part = -(height / part);
                if (part > 1.0F || part < 0.0F) {
                    continue;
                }
                hit.x = pos->x + (part * dir->x);
                hit.y = pos->y + (part * dir->y);
                hit.z = pos->z + (part * dir->z);
                first.x = v0->x - hit.x;
                first.y = v0->y - hit.y;
                first.z = v0->z - hit.z;
                second.x = v1->x - hit.x;
                second.y = v1->y - hit.y;
                second.z = v1->z - hit.z;
                vector_cross(&first, &second, &temp);
                if (njInnerProduct(&temp, &normal) <= 0.000001F) {
                    continue;
                }
                third.x = v2->x - hit.x;
                third.y = v2->y - hit.y;
                third.z = v2->z - hit.z;
                vector_cross(&second, &third, &temp);
                if (njInnerProduct(&temp, &normal) <= 0.000001F) {
                    continue;
                }
                vector_cross(&third, &first, &temp);
                if (njInnerProduct(&temp, &normal) <= 0.000001F) {
                    continue;
                }
                if (crossed == ((void *)0) || query->distance > part) {
                    crossed = object;
                    query->hit.x = hit.x;
                    query->hit.y = hit.y;
                    query->hit.z = hit.z;
                    query->normal.x = normal.x;
                    query->normal.y = normal.y;
                    query->normal.z = normal.z;
                    vector_aim_y(&normal, &query->ang_x, &query->ang_z);
                    query->flags = flags;
                    query->distance = part;
                }
            }
        }
    }
    return crossed;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool polygon_find_nearest_height(struct line_query *query, NJS_OBJECT *object,
                                 Uint32 flags)
{
    NJS_POINT3 *v0;
    NJS_POINT3 *v1;
    NJS_POINT3 *v2;
    NJS_POINT3 *p0;
    NJS_POINT3 *p1;
    NJS_POINT3 *p2;
    NJS_MODEL *source;
    NJS_MODEL model;
    struct strip strip;
    NJS_VECTOR normal;
    NJS_VECTOR edge;
    const Float *pos;
    const Float *slot;
    Float reach;
    Float length2;
    Float px;
    Float py;
    Float pz;
    Float dx;
    Float dy;
    Float dz;
    Float e1;
    Float e2;
    Float e3;
    Float plane;
    Float y;
    Bool found;
    int strips;
    int i;
    Bool reversed;
    found = (0);
    source = object->model;
    model = *source;
    strip.model = &model;
    njPushMatrix(((void *)0));
    njUnitMatrix(((void *)0));
    if (!(object->evalflags & 0x01)) {
        njTranslateV(((void *)0), (NJS_VECTOR *)object->pos);
    }
    if (!(object->evalflags & 0x02)) {
        ((object->ang[2]) ? (njRotateZ)(((void *)0), (object->ang[2])) : (void)0);
        ((object->ang[1]) ? (njRotateY)(((void *)0), (object->ang[1])) : (void)0);
        ((object->ang[0]) ? (njRotateX)(((void *)0), (object->ang[0])) : (void)0);
    }
    if (!(object->evalflags & 0x04)) {
        njScaleV(((void *)0), (NJS_VECTOR *)object->scl);
    }
    while (model.nbMeshset != 0) {
        switch (strip.kind = model.meshsets->type_matId & 0xc000) {
        case 0x0000:
            strip.count = 3;
            break;
        case 0x4000:
            strip.count = 4;
            break;
        case 0x8000:
        case 0xc000:
            break;
        default:
            return (0);
        }
        strips = model.meshsets->nbMesh;
        strip.indices = model.meshsets->meshes;
        while (strips != 0) {
            if ((object->evalflags & (0x01 | 0x02 | 0x04)) == (0x01 | 0x02 | 0x04)) {
                reversed = FUN_8c0274b8(&strip);
            } else if ((object->evalflags & (0x02 | 0x04)) == (0x02 | 0x04)) {
                reversed = strip_next_moved(&strip, object);
            } else {
                reversed = FUN_8c0273a2(&strip);
            }
            for (i = 0, v0 = &strip.points[0], v1 = &strip.points[1],
                v2 = &strip.points[2];
                 i < strip.count - 2; i++, v0 = v1, v1 = v2, v2++) {
                edge.x = v1->x - v0->x;
                edge.y = v1->y - v0->y;
                edge.z = v1->z - v0->z;
                reach = (((&edge)->x * (&edge)->x) + ((&edge)->y * (&edge)->y) + ((&edge)->z * (&edge)->z));
                edge.x = v2->x - v1->x;
                edge.y = v2->y - v1->y;
                edge.z = v2->z - v1->z;
                if ((length2 = (((&edge)->x * (&edge)->x) + ((&edge)->y * (&edge)->y) + ((&edge)->z * (&edge)->z))) > reach) {
                    reach = length2;
                }
                edge.x = v0->x - v2->x;
                edge.y = v0->y - v2->y;
                edge.z = v0->z - v2->z;
                if ((length2 = (((&edge)->x * (&edge)->x) + ((&edge)->y * (&edge)->y) + ((&edge)->z * (&edge)->z))) > reach) {
                    reach = length2;
                }
                reach += (((&query->speed)->x * (&query->speed)->x) + ((&query->speed)->y * (&query->speed)->y) + ((&query->speed)->z * (&query->speed)->z)) + ((query->radius) * (query->radius));
                pos = &query->pos.x;
                px = *pos++;
                py = *pos++;
                pz = *pos;
                slot = (Float *)&v0;
                dx = px - *slot++;
                dy = py - *slot++;
                dz = pz - *slot;
                if ((dx * dx) + (dy * dy) + (dz * dz) > reach) {
                    continue;
                }
                slot = (Float *)&v1;
                dx = px - *slot++;
                dy = py - *slot++;
                dz = pz - *slot;
                if ((dx * dx) + (dy * dy) + (dz * dz) > reach) {
                    continue;
                }
                slot = (Float *)&v2;
                dx = px - *slot++;
                dy = py - *slot++;
                dz = pz - *slot;
                if ((dx * dx) + (dy * dy) + (dz * dz) > reach) {
                    continue;
                }
                if (!((i + reversed) & 1)) {
                    p0 = v0;
                    p1 = v1;
                    p2 = v2;
                } else {
                    p0 = v0;
                    p1 = v2;
                    p2 = v1;
                }
                e1 = ((((p1)->z - (p0)->z) * ((&query->pos)->x - (p0)->x)) - (((p1)->x - (p0)->x) * ((&query->pos)->z - (p0)->z)));
                e2 = ((((p2)->z - (p1)->z) * ((&query->pos)->x - (p1)->x)) - (((p2)->x - (p1)->x) * ((&query->pos)->z - (p1)->z)));
                e3 = ((((p0)->z - (p2)->z) * ((&query->pos)->x - (p2)->x)) - (((p0)->x - (p2)->x) * ((&query->pos)->z - (p2)->z)));
                if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                    continue;
                }
                FUN_8c027360((const char *)p0, (const char *)p1,
                                (const char *)p2, &normal);
                plane = -(normal.x * p0->x) - (normal.y * p0->y) -
                        (normal.z * p0->z);
                if (normal.y != 0.0F) {
                    y = (-(normal.x * query->pos.x) -
                         (normal.z * query->pos.z) - plane) /
                        normal.y;
                    if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
                    if (!found || (found == (1) &&
                                   ((Float)_builtin_fabsf((Float)(y - query->pos.y))) <
                                       ((Float)_builtin_fabsf((Float)(query->level - query->pos.y))))) {
                        found = (1);
                        query->level = y;
                        query->normal = normal;
                        query->ang_z = -(Angle)(njArcTan2(normal.x, normal.y) *
                                                (65536.0 / (2 * 3.141592)));
                        query->ang_x =
                            (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
                    }
                }
            }
            strips--;
        }
        model.meshsets++;
        model.nbMeshset--;
    }
    njPopMatrix(1);
    return found;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool find_model_heights_near(struct height_query *query,
                                    NJS_OBJECT *object, Uint32 flags)
{
    NJS_POINT3 *v0;
    NJS_POINT3 *v1;
    NJS_POINT3 *v2;
    NJS_POINT3 *points;
    NJS_POINT3 *p0;
    NJS_POINT3 *p1;
    NJS_POINT3 *p2;
    struct surface *side;
    NJS_MODEL *source;
    NJS_MODEL model;
    struct strip strip;
    NJS_VECTOR normal;
    const Float *pos;
    const Float *slot;
    Float reach2;
    Float dx;
    Float dy;
    Float dz;
    Float e1;
    Float e2;
    Float e3;
    Float plane;
    Float y;
    Bool any;
    int strips;
    int i;
    Bool reversed;
    any = (0);
    query->below.found = (0);
    query->above.found = (0);
    source = object->model;
    model = *source;
    strip.model = &model;
    reach2 = size_reach2[((flags) & 0x60000000) >> 13];
    njPushMatrix(((void *)0));
    njUnitMatrix(((void *)0));
    if (!(object->evalflags & 0x01)) {
        njTranslateV(((void *)0), (NJS_VECTOR *)object->pos);
    }
    if (!(object->evalflags & 0x02)) {
        ((object->ang[2]) ? (njRotateZ)(((void *)0), (object->ang[2])) : (void)0);
        ((object->ang[1]) ? (njRotateY)(((void *)0), (object->ang[1])) : (void)0);
        ((object->ang[0]) ? (njRotateX)(((void *)0), (object->ang[0])) : (void)0);
    }
    if (!(object->evalflags & 0x04)) {
        njScaleV(((void *)0), (NJS_VECTOR *)object->scl);
    }
    while (model.nbMeshset != 0) {
        switch (strip.kind = model.meshsets->type_matId & 0xc000) {
        case 0x0000:
            strip.count = 3;
            break;
        case 0x4000:
            strip.count = 4;
            break;
        case 0x8000:
        case 0xc000:
            break;
        default:
            return (0);
        }
        strips = model.meshsets->nbMesh;
        strip.indices = model.meshsets->meshes;
        while (strips != 0) {
            if ((object->evalflags & (0x01 | 0x02 | 0x04)) == (0x01 | 0x02 | 0x04)) {
                reversed = FUN_8c0274b8(&strip);
            } else if ((object->evalflags & (0x02 | 0x04)) == (0x02 | 0x04)) {
                reversed = strip_next_moved(&strip, object);
            } else {
                reversed = FUN_8c0273a2(&strip);
            }
            for (i = 0, v0 = &strip.points[0], points = strip.points,
                v1 = &points[1], v2 = &points[2];
                 i < strip.count - 2; i++, v0 = v1, v1 = v2, v2++) {
                pos = &query->pos.x;
                slot = (Float *)&v0;
                dx = *pos++ - *slot++;
                dy = *pos++ - *slot;
                slot++;
                dz = *pos - *slot;
                if ((dx * dx) + (dy * dy) + (dz * dz) > reach2) {
                    continue;
                }
                if (!((i + reversed) & 1)) {
                    p0 = v0;
                    p1 = v1;
                    p2 = v2;
                } else {
                    p0 = v0;
                    p1 = v2;
                    p2 = v1;
                }
                do {
                    e1 = ((((p1)->z - (p0)->z) * ((&query->pos)->x - (p0)->x)) - (((p1)->x - (p0)->x) * ((&query->pos)->z - (p0)->z)));
                    e2 = ((((p2)->z - (p1)->z) * ((&query->pos)->x - (p1)->x)) - (((p2)->x - (p1)->x) * ((&query->pos)->z - (p1)->z)));
                    e3 = ((((p0)->z - (p2)->z) * ((&query->pos)->x - (p2)->x)) - (((p0)->x - (p2)->x) * ((&query->pos)->z - (p2)->z)));
                    if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                        break;
                    }
                    FUN_8c027360((const char *)p0, (const char *)p1,
                                    (const char *)p2, &normal);
                    plane = -(normal.x * p0->x) - (normal.y * p0->y) -
                            (normal.z * p0->z);
                    if (normal.y * normal.y >= 0.01F * 0.01F) {
                        y = (-(normal.z * query->pos.z) -
                             (normal.x * query->pos.x) - plane) /
                            normal.y;
                        side = ((void *)0);
                        if (query->pos.y > y) {
                            if (!query->below.found || y > query->below.level) {
                                side = &query->below;
                            }
                        } else {
                            if (!query->above.found || query->above.level > y) {
                                side = &query->above;
                            }
                        }
                        if (side == ((void *)0)) {
                            break;
                        }
                        if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
                        any = (1);
                        side->found = (1);
                        side->level = y;
                        side->normal = normal;
                        side->ang_z = -(Angle)(njArcTan2(normal.x, normal.y) *
                                               (65536.0 / (2 * 3.141592)));
                        side->ang_x =
                            (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
                    }
                } while (0);
            }
            strips--;
        }
        model.meshsets++;
        model.nbMeshset--;
    }
    njPopMatrix(1);
    return any;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool polygon_find_model_sides(struct sides_query *query, NJS_OBJECT *object,
                              Uint32 flags)
{
    NJS_POINT3 *v0;
    NJS_POINT3 *v1;
    NJS_POINT3 *v2;
    NJS_POINT3 *p0;
    NJS_POINT3 *p1;
    NJS_POINT3 *p2;
    struct surface *side;
    NJS_MODEL *source;
    NJS_MODEL model;
    struct strip strip;
    const Float *pos;
    const Float *slot;
    Float reach2;
    Float dx;
    Float dy;
    Float dz;
    Float e1;
    Float e2;
    Float e3;
    Float plane;
    Float x;
    Float y;
    Float z;
    Bool any;
    int strips;
    int i;
    Bool reversed;
    int sides;
    any = (0);
    for (sides = SIDES, side = query->sides; sides > 0; sides--, side++) {
        side->found = (0);
    }
    source = object->model;
    model = *source;
    strip.model = &model;
    reach2 = size_reach2[((flags) & 0x60000000) >> 13];
    njPushMatrix(((void *)0));
    njUnitMatrix(((void *)0));
    if (!(object->evalflags & 0x01)) {
        njTranslateV(((void *)0), (NJS_VECTOR *)object->pos);
    }
    if (!(object->evalflags & 0x02)) {
        ((object->ang[2]) ? (njRotateZ)(((void *)0), (object->ang[2])) : (void)0);
        ((object->ang[1]) ? (njRotateY)(((void *)0), (object->ang[1])) : (void)0);
        ((object->ang[0]) ? (njRotateX)(((void *)0), (object->ang[0])) : (void)0);
    }
    if (!(object->evalflags & 0x04)) {
        njScaleV(((void *)0), (NJS_VECTOR *)object->scl);
    }
    while (model.nbMeshset != 0) {
        switch (strip.kind = model.meshsets->type_matId & 0xc000) {
        case 0x0000:
            strip.count = 3;
            break;
        case 0x4000:
            strip.count = 4;
            break;
        case 0x8000:
        case 0xc000:
            break;
        default:
            return (0);
        }
        strips = model.meshsets->nbMesh;
        strip.indices = model.meshsets->meshes;
        while (strips != 0) {
            if ((object->evalflags & (0x01 | 0x02 | 0x04)) == (0x01 | 0x02 | 0x04)) {
                reversed = FUN_8c0274b8(&strip);
            } else if ((object->evalflags & (0x02 | 0x04)) == (0x02 | 0x04)) {
                reversed = strip_next_moved(&strip, object);
            } else {
                reversed = FUN_8c0273a2(&strip);
            }
            for (i = 0, v0 = &strip.points[0], v1 = &strip.points[1],
                v2 = &strip.points[2];
                 i < strip.count - 2; i++, v0 = v1, v1 = v2, v2++) {
                pos = &query->pos.x;
                slot = (Float *)&v0;
                dx = *pos++ - *slot;
                slot++;
                dy = *pos++ - *slot;
                slot++;
                dz = *pos - *slot;
                if (reach2 < (dx * dx) + (dy * dy) + (dz * dz)) {
                    continue;
                }
                if (!((i + reversed) & 1)) {
                    p0 = v0;
                    p1 = v1;
                    p2 = v2;
                } else {
                    p0 = v0;
                    p1 = v2;
                    p2 = v1;
                }
                do {
                    NJS_VECTOR normal;
                    e1 = ((((p1)->x - (p0)->x) * ((&query->pos)->y - (p0)->y)) - (((p1)->y - (p0)->y) * ((&query->pos)->x - (p0)->x)));
                    e2 = ((((p2)->x - (p1)->x) * ((&query->pos)->y - (p1)->y)) - (((p2)->y - (p1)->y) * ((&query->pos)->x - (p1)->x)));
                    e3 = ((((p0)->x - (p2)->x) * ((&query->pos)->y - (p2)->y)) - (((p0)->y - (p2)->y) * ((&query->pos)->x - (p2)->x)));
                    if (0) { if (p0) { } };
                    if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                        break;
                    }
                    FUN_8c027360((const char *)p0, (const char *)p1,
                                    (const char *)p2, &normal);
                    plane = -(normal.x * p0->x) - (normal.y * p0->y) -
                            (normal.z * p0->z);
                    if (normal.z * normal.z < 0.01F * 0.01F) {
                        break;
                    }
                    z = (-(normal.x * query->pos.x) -
                         (normal.y * query->pos.y) - plane) /
                        normal.z;
                    side = ((void *)0);
                    if (z < query->pos.z) {
                        if (!query->sides[SIDE_MINUS_Z].found ||
                            z > query->sides[SIDE_MINUS_Z].level) {
                            side = &query->sides[SIDE_MINUS_Z];
                        }
                    } else {
                        if (!query->sides[SIDE_PLUS_Z].found ||
                            z < query->sides[SIDE_PLUS_Z].level) {
                            side = &query->sides[SIDE_PLUS_Z];
                        }
                    }
                    if (side == ((void *)0)) {
                        break;
                    }
                    if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
                    any = (1);
                    side->found = (1);
                    side->level = z;
                    side->normal = normal;
                    side->ang_z =
                        -(Angle)(njArcTan2(normal.x, normal.y) * (65536.0 / (2 * 3.141592)));
                    side->ang_x = (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
                } while (0);
                do {
                    NJS_VECTOR normal;
                    e1 = ((((p1)->y - (p0)->y) * ((&query->pos)->z - (p0)->z)) - (((p1)->z - (p0)->z) * ((&query->pos)->y - (p0)->y)));
                    e2 = ((((p2)->y - (p1)->y) * ((&query->pos)->z - (p1)->z)) - (((p2)->z - (p1)->z) * ((&query->pos)->y - (p1)->y)));
                    e3 = ((((p0)->y - (p2)->y) * ((&query->pos)->z - (p2)->z)) - (((p0)->z - (p2)->z) * ((&query->pos)->y - (p2)->y)));
                    if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                        break;
                    }
                    FUN_8c027360((const char *)p0, (const char *)p1,
                                    (const char *)p2, &normal);
                    plane = -(normal.x * p0->x) - (normal.y * p0->y) -
                            (normal.z * p0->z);
                    if (normal.x * normal.x < 0.01F * 0.01F) {
                        break;
                    }
                    x = (-(normal.y * query->pos.y) -
                         (normal.z * query->pos.z) - plane) /
                        normal.x;
                    side = ((void *)0);
                    if (x < query->pos.x) {
                        if (!query->sides[SIDE_MINUS_X].found ||
                            x > query->sides[SIDE_MINUS_X].level) {
                            side = &query->sides[SIDE_MINUS_X];
                        }
                    } else {
                        if (!query->sides[SIDE_PLUS_X].found ||
                            x < query->sides[SIDE_PLUS_X].level) {
                            side = &query->sides[SIDE_PLUS_X];
                        }
                    }
                    if (side == ((void *)0)) {
                        break;
                    }
                    if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
                    any = (1);
                    side->found = (1);
                    side->level = x;
                    side->normal = normal;
                    side->ang_z =
                        -(Angle)(njArcTan2(normal.x, normal.y) * (65536.0 / (2 * 3.141592)));
                    side->ang_x = (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
                } while (0);
                do {
                    NJS_VECTOR normal;
                    e1 = ((((p1)->z - (p0)->z) * ((&query->pos)->x - (p0)->x)) - (((p1)->x - (p0)->x) * ((&query->pos)->z - (p0)->z)));
                    e2 = ((((p2)->z - (p1)->z) * ((&query->pos)->x - (p1)->x)) - (((p2)->x - (p1)->x) * ((&query->pos)->z - (p1)->z)));
                    e3 = ((((p0)->z - (p2)->z) * ((&query->pos)->x - (p2)->x)) - (((p0)->x - (p2)->x) * ((&query->pos)->z - (p2)->z)));
                    if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                        break;
                    }
                    FUN_8c027360((const char *)p0, (const char *)p1,
                                    (const char *)p2, &normal);
                    plane = -(normal.x * p0->x) - (normal.y * p0->y) -
                            (normal.z * p0->z);
                    if (normal.y * normal.y < 0.01F * 0.01F) {
                        break;
                    }
                    y = (-(normal.z * query->pos.z) -
                         (normal.x * query->pos.x) - plane) /
                        normal.y,
                    side = ((void *)0);
                    if (y < query->pos.y) {
                        if (!query->sides[SIDE_BELOW].found ||
                            y > query->sides[SIDE_BELOW].level) {
                            side = &query->sides[SIDE_BELOW];
                        }
                    } else {
                        if (!query->sides[SIDE_ABOVE].found ||
                            y < query->sides[SIDE_ABOVE].level) {
                            side = &query->sides[SIDE_ABOVE];
                        }
                    }
                    if (side == ((void *)0)) {
                        break;
                    }
                    if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
                    any = (1);
                    side->found = (1);
                    side->level = y;
                    side->normal = normal;
                    side->ang_z =
                        -(Angle)(njArcTan2(normal.x, normal.y) * (65536.0 / (2 * 3.141592)));
                    side->ang_x = (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
                } while (0);
            }
            strips--;
        }
        model.meshsets++;
        model.nbMeshset--;
    }
    njPopMatrix(1);
    if (0) { if (any) { } };
    return any;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool polygon_find_model_heights(struct height_query *query, NJS_OBJECT *object)
{
    NJS_POINT3 *v0;
    NJS_POINT3 *v1;
    NJS_POINT3 *v2;
    NJS_POINT3 *p0;
    NJS_POINT3 *p1;
    NJS_POINT3 *p2;
    struct surface *side;
    NJS_MODEL *source;
    NJS_MODEL model;
    struct strip strip;
    NJS_VECTOR normal;
    Float e1;
    Float e2;
    Float e3;
    Float plane;
    Float y;
    Bool any;
    int strips;
    int i;
    Bool reversed;
    any = (0);
    query->below.found = (0);
    query->above.found = (0);
    source = object->model;
    model = *source;
    strip.model = &model;
    njPushMatrix(((void *)0));
    njUnitMatrix(((void *)0));
    if (!(object->evalflags & 0x01)) {
        njTranslateV(((void *)0), (NJS_VECTOR *)object->pos);
    }
    if (!(object->evalflags & 0x02)) {
        ((object->ang[2]) ? (njRotateZ)(((void *)0), (object->ang[2])) : (void)0);
        ((object->ang[1]) ? (njRotateY)(((void *)0), (object->ang[1])) : (void)0);
        ((object->ang[0]) ? (njRotateX)(((void *)0), (object->ang[0])) : (void)0);
    }
    if (!(object->evalflags & 0x04)) {
        njScaleV(((void *)0), (NJS_VECTOR *)object->scl);
    }
    while (model.nbMeshset != 0) {
        switch (strip.kind = model.meshsets->type_matId & 0xc000) {
        case 0x0000:
            strip.count = 3;
            break;
        case 0x4000:
            strip.count = 4;
            break;
        case 0x8000:
        case 0xc000:
            break;
        default:
            return (0);
        }
        strips = model.meshsets->nbMesh;
        strip.indices = model.meshsets->meshes;
        while (strips != 0) {
            if ((object->evalflags & (0x01 | 0x02 | 0x04)) == (0x01 | 0x02 | 0x04)) {
                reversed = FUN_8c0274b8(&strip);
            } else if ((object->evalflags & (0x02 | 0x04)) == (0x02 | 0x04)) {
                reversed = strip_next_moved(&strip, object);
            } else {
                reversed = FUN_8c0273a2(&strip);
            }
            for (i = 0, v0 = &strip.points[0], v1 = &strip.points[1],
                v2 = &strip.points[2];
                 i < strip.count - 2; i++, v0 = v1, v1 = v2, v2++) {
                if (!((i + reversed) & 1)) {
                    p0 = v0;
                    p1 = v1;
                    p2 = v2;
                } else {
                    p0 = v0;
                    p1 = v2;
                    p2 = v1;
                }
                do {
                    e1 = ((((p1)->z - (p0)->z) * ((&query->pos)->x - (p0)->x)) - (((p1)->x - (p0)->x) * ((&query->pos)->z - (p0)->z)));
                    e2 = ((((p2)->z - (p1)->z) * ((&query->pos)->x - (p1)->x)) - (((p2)->x - (p1)->x) * ((&query->pos)->z - (p1)->z)));
                    e3 = ((((p0)->z - (p2)->z) * ((&query->pos)->x - (p2)->x)) - (((p0)->x - (p2)->x) * ((&query->pos)->z - (p2)->z)));
                    if (e1 * e2 < 0.0F || e2 * e3 < 0.0F || e1 * e3 < 0.0F) {
                        break;
                    }
                    FUN_8c027360((const char *)p0, (const char *)p1,
                                    (const char *)p2, &normal);
                    plane = -(normal.x * p0->x) - (normal.y * p0->y) -
                            (normal.z * p0->z);
                    if (normal.y * normal.y >= 0.01F * 0.01F) {
                        y = (-(normal.z * query->pos.z) -
                             (normal.x * query->pos.x) - plane) /
                            normal.y;
                        side = ((void *)0);
                        if (query->pos.y > y) {
                            if (!query->below.found || y > query->below.level) {
                                side = &query->below;
                            }
                        } else {
                            if (!query->above.found || query->above.level > y) {
                                side = &query->above;
                            }
                        }
                        if (side == ((void *)0)) {
                            break;
                        }
                        if (njScalor(&normal) == 0.0F) { (&normal)->x = 0.0F; (&normal)->y = 1.0F; (&normal)->z = 0.0F; } else { njUnitVector(&normal); };
                        any = (1);
                        side->found = (1);
                        side->level = y;
                        side->normal = normal;
                        side->ang_z = -(Angle)(njArcTan2(normal.x, normal.y) *
                                               (65536.0 / (2 * 3.141592)));
                        side->ang_x =
                            (Angle)(asinf(normal.z) * (65536.0 / (2 * 3.141592)));
                    }
                } while (0);
            }
            strips--;
        }
        model.meshsets++;
        model.nbMeshset--;
    }
    njPopMatrix(1);
    return any;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void collision_mesh_forget(NJS_OBJECT *object)
{
    struct collision_mesh *mesh;
    for (mesh = collision_mesh_list; mesh != ((void *)0); mesh = mesh->next) {
        if (mesh->object == object) {
            mesh->object = ((void *)0);
            break;
        }
    }
}
