/* @unit 8C0F4F80-8C0F5C80 +r04 +egflags +pool32 +poolafter=amenbo_take_hit,FUN_8c0f53f0,FUN_8c0f5668,amenbo_keep_on_water,amenbo_chase +poolbra=amenbo_aim_right:1,FUN_8c0f53f0:1,amenbo_step:6 */
/* Ported from the Japanese release's src/enemy/amenbo.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#define TEXT_6 ""
#define TEXT_7 ""
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
float acosf(float x);
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
typedef unsigned long size_t;
int rand(void);
void srand(unsigned int seed);
void *calloc(size_t nmemb, size_t size);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);
void animal_create_random(int unused, Float x, Float y, Float z);
void animal_create_rare(Float x, Float y, Float z);
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
struct collision_shape {
    Uint32 flags;
    Uint8 levels;
    Uint8 push;
    NJS_POINT3 center;
    Float radius;
    Float size_y;
    Float size_z;
    struct angles ang;
    Sint16 hit_shape;
    struct collision_work *hit;
};
struct collision_work {
    Uint16 kind;
    Uint16 flags;
    Uint16 count;
    Uint16 current;
    Float radius;
    struct collision_shape *shapes;
    struct task *owner;
    Sint16 own_shape;
    Sint16 hit_shape;
    struct collision_work *hit;
};
struct near_task {
    struct task_work *work;
    Float distance;
};
extern struct near_task near_tasks[1160 + 1];
extern struct near_task near_rings[512 + 1];
extern struct near_task near_tasks_player1[1160 + 1];
extern struct near_task near_rings_player1[512 + 1];
extern Uint16 collision_player_count;
extern Uint16 collision_attack_count;
extern Uint16 collision_object_count;
extern Uint16 collision_mutual_object_count;
extern Uint16 collision_pickup_count;
extern Uint16 collision_ring_count;
extern Uint16 collision_wall_count;
extern struct collision_work *collision_players[8];
extern struct collision_work *collision_attacks[128];
extern struct collision_work *collision_items[128];
extern struct collision_work *collision_enemies[256];
extern NJS_OBJECT marker_object;
extern NJS_OBJECT marker_cylinder_object;
extern NJS_OBJECT marker_cube_object[1];
extern NJS_OBJECT marker_ball_object;
extern NJS_OBJECT marker_dome_object;
extern NJS_OBJECT marker_tube_object;
void collision_draw_radius(struct collision_work *collision);
void collision_set_radius(struct collision_work *collision);
void CCL_Init(struct task *task, const struct collision_shape *shapes,
                    Uint8 kind, int unused, Uint8 count);
void EntryColliList(struct task_work *work);
void collision_clear_lists(void);
int collision_get_hit_player(struct task_work *work);
void collision_get_shape_center(struct task_work *work,
                                struct collision_shape *shape, NJS_POINT3 *pos);
void collision_collide_all(void);
void collision_free(struct task_work *work);
Sint8 collision_get_hit_normal(struct task_work *work, NJS_VECTOR *normal);
struct angles;
struct sides_query;
struct task_work;
struct shadow {
    Angle ang_x;
    Angle ang_z;
    Uint32 above_flags;
    Uint32 below_flags;
    Float above;
    Float below;
    Uint32 last_above_flags;
    Uint32 last_below_flags;
    Float scale;
};
Float ground_below(Float x, Float y, Float z, struct angles *slope);
int ground_below_int(Float x, Float y, Float z, struct angles *slope);
Float ground_nearest(Float x, Float y, Float z, struct angles *slope);
Float ground_nearest_land(Float x, Float y, Float z, struct angles *slope);
Float ground_find_first_floor(struct task_work *work, struct angles *slope);
void shadow_draw_at_height(struct task_work *work, Float height);
Float shadow_draw(struct task_work *work, Float scale);
void shadow_draw_at(struct angles *ang, NJS_POINT3 *pos, Float scale);
Float shadow_draw_slope(struct task_work *work, Float scale,
                        struct angles *slope);
void shadow_update(struct task_work *work, struct shadow *shadow);
Bool ground_find_sides(struct sides_query *result);
Bool ground_find_sides_water(struct sides_query *result);
extern Sint16 edit_mode;
extern Sint16 editor_kind;
extern struct task_work *editor_work;
extern NJS_OBJECT marker_box_object;
Bool placement_editing(struct task *task);
void editor_create(void);
int editor_request_open(void);
enum light_editor_mode {
    EDIT_OFF = 0,
    EDIT_PALETTE = 1,
    EDIT_ENV = 2,
    EDIT_VMS_TO_PC = 3,
    EDIT_PC_TO_VMS = 4,
    EDIT_FILE = 5,
    EDIT_FREE = 7,
    EDIT_SLAVE = 8
};
extern enum light_editor_mode light_editor_mode;
void light_editor_draw(void);
void editor_take_buttons(int port, Uint32 buttons);
void light_editor_init(void);
int light_editor_exec(void);
struct task_work;
void ds_ActionClip(NJS_ACTION *action, Float frame);
void draw_motion(NJS_OBJECT *object, NJS_MOTION *motion, Float frame);
void draw_action_link(NJS_ACTION_LINK *link, Float ratio);
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
Bool dsCheckViewV(Float x, Float y, Float z, Float radius);
void draw_set_light(Float x, Float y, Float z);
void draw_divide_light(Float scale);
void draw_reset_light(void);
void draw_set_palette(int palette);
void draw_take_point_lights(void);
void late_DrawObject(NJS_OBJECT *object);
struct particle_anim;
struct particle_pool;
struct particle_pool_spec {
    struct particle_anim *anim;
    Uint32 size;
    void (*init)(struct particle_pool *pool);
    struct particle_pool *pool;
};
void particle_create_pools(void);
struct task_work;
extern NJS_TEXLIST explosion_texlist;
extern struct particle_pool_spec explosion_pool;
void explosion_create(struct task_work *work, Float scale);
void CreateFlash2(Float x, Float y, Float z, Float scale);
struct task;
extern NJS_TEXLIST e_amenbo_texlist;
void EnemyPondSkater(struct task *task);
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
extern struct polygon_contact polygon_contacts[];
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
Bool collision_mesh_update(void);
void collision_mesh_collect_all(void);
void collision_mesh_link_pools(void);
void polygon_pool_seek_free(void);
void collision_mesh_forget(NJS_OBJECT *object);
int polygon_collect_near(struct polygon_ball *ball);
Bool polygon_sweep(struct polygon_ball *ball, NJS_OBJECT *object, Uint32 flags);
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
Bool polygon_cast_ray(struct ray_query *query);
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
struct e102;
struct lockon_target {
    struct task_motion motion;
    struct task *lockon;
    void (*destructor)(struct task *task);
    Uint8 unk_48;
    Sint8 last_mode;
    Sint8 unk_4a;
    Uint8 unk_4b;
    Sint16 unk_4c;
    Uint16 flags;
    NJS_POINT3 home;
    NJS_POINT3 target;
    NJS_POINT3 last_pos;
    Float unk_74;
    Float unk_78;
    Float unk_7c;
    Float unk_80;
    Float unk_84;
    Float unk_88;
    Float unk_8c;
    Uint8 unk_90[0xc];
    NJS_VECTOR probe_offset;
    Float top;
    Float radius;
    Float bottom;
    Float step_down;
    Float wall_bounce;
    Float floor_bounce;
    Float friction;
    Float unk_c4;
    Angle wall_turn;
    Float shadow_size;
    Float shadow_ratio;
    struct sides_query ground;
    Float scale_speed;
    Angle heading;
    Angle turn_speed;
    Angle phase;
    Angle angles[8];
    Angle aim_y;
    Angle sight_angle;
    Float sight_distance;
    Float near_distance;
    Float frame;
    Float unk_1e4;
    Float next_frame;
    Float blend;
    Float blend_speed;
    NJS_ACTION *action;
    NJS_ACTION *next_action;
    NJS_MATRIX matrix;
};
struct lockon_extra {
    Sint8 marked;
    Sint8 number;
    Sint8 unk_02;
    Uint8 unk_03;
    Sint16 upgrades;
    Uint8 unk_06[2];
    struct task *target;
    struct task_work *player;
    struct e102 *e102;
    struct task *shot;
    Uint8 unk_18[4];
    Float radius;
    struct angles ang;
    struct task *bonus;
    void (*step)(struct task *task);
};
extern NJS_SPRITE lockon_sprite;
void lockon_step(struct task *task);
struct task *lockon_get_shot(struct task *lockon);
struct task *lockon_of_shot(struct task *shot);
void lockon_release(struct task *target);
void lockon_release_hit(struct task *target);
void lockon_release_hit_fading(struct task *target);
#pragma inline(enemy_ignore)
static void enemy_ignore(void *value)
{
    if (0) {
        *(void **)value = value;
    }
}
struct lockon_target *EnemyInitialize(struct task *task,
                                         struct task_work *work);
void enemy_end(struct task *task, struct task_work *work,
               struct lockon_target *record);
Sint8 enemy_sees_player(struct task_work *work, struct lockon_target *record);
void EnemyCheckGroundCollision(struct task_work *work, struct lockon_target *record);
void Knuckles_KakeraGame_Set_CheckEme(struct task_work *work, struct lockon_target *record);
void enemy_save_pos(struct task_work *work, struct lockon_target *record);
void FUN_8c047da2(struct task_work *work, struct lockon_target *record);
int enemy_aim_at_target(struct task_work *work, struct lockon_target *record);
int enemy_turn_to_target(struct task_work *work, struct lockon_target *record);
int enemy_aim_at_home(struct task_work *work, struct lockon_target *record);
int enemy_turn_home(struct task_work *work, struct lockon_target *record);
int enemy_aim_at_player(struct task_work *work, struct lockon_target *record,
                        Uint8 player);
int enemy_turn_to_player(struct task_work *work, struct lockon_target *record,
                         Uint8 player);
int enemy_turn_from_player(struct task_work *work, struct lockon_target *record,
                           Uint8 player);
Float enemy_target_distance(struct task_work *work,
                            struct lockon_target *record);
Float enemy_target_distance2(struct task_work *work,
                             struct lockon_target *record);
Float enemy_home_distance(struct task_work *work, struct lockon_target *record);
Float enemy_home_distance2(struct task_work *work,
                           struct lockon_target *record);
Float enemy_player_distance2(struct task_work *work, int player);
Sint8 enemy_on_screen(NJS_POINT3 *pos);
void enemy_target_near_player(struct task_work *work,
                              struct lockon_target *record, int player,
                              int spot);
void enemy_break(struct task_work *work, NJS_MODEL **models,
                 NJS_TEXLIST *texlist);
void enemy_scatter_debris(struct task_work *work, Uint8 count);
void enemy_spring_scale(struct task_work *work, struct lockon_target *record);
void enemy_bounce_player(Sint8 player);
Bool enemy_take_hit(struct task_work *work, struct lockon_target *record);
struct set_entry {
    Uint16 id;
    Sint16 ang_x;
    Sint16 ang_y;
    Sint16 ang_z;
    NJS_POINT3 pos;
    NJS_POINT3 scl;
};
struct set_file {
    Uint32 count;
    Uint8 unk_04[28];
};
struct object_kind {
    Uint8 create;
    Uint8 level;
    Sint16 attr;
    Float range;
    void *param;
    void (*step)(struct task *task);
    char *name;
};
struct object_list {
    Sint16 count;
    struct object_kind *kinds;
};
struct placement_pose {
    struct angles ang;
    NJS_POINT3 pos;
    NJS_POINT3 scl;
};
struct placement {
    Sint8 tasks;
    Sint8 state;
    Sint16 flags;
    struct task *task;
    struct set_entry *entry;
    union {
        Float range;
        struct placement_pose *pose;
    } leave;
};
extern struct object_list *placement_list;
extern struct set_file *placement_file;
extern Uint32 *placement_file_count;
extern struct set_entry *placement_entries;
extern Sint16 placement_count;
extern struct placement placements[1023];
void placement_manager_step(struct task *task);
void placement_reset(void);
void placement_change_act(Sint16 change);
Bool placement_far_from_camera(struct task *task);
Bool placement_far_from_camera_by(struct task *task, Float range);
Bool placement_try_leave(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
Bool placement_try_leave_saving(struct task *task);
Bool placement_try_leave_saving_by(struct task *task, Float range);
void placement_set_used(struct task *task);
void placement_keep(struct task *task);
int placement_used(struct task *task);
void placement_hold(struct task *task);
int placement_held(struct task *task);
void placement_stop(struct task *task);
void DeadOut(struct task *task);
Uint16 placement_get_kind(struct task *task);
void placement_set_state(struct task *task, Sint8 state);
Sint8 placement_get_state(struct task *task);
struct angles;
struct e102;
struct event_mouth_key;
struct path;
struct polygon_ball;
struct task;
struct task_motion;
struct task_work;
struct player_vars {
    Uint8 player;
    Uint8 character;
    Uint8 unk_02[6];
    union {
        struct task *carry;
        struct path *path;
    } arg;
};
struct player_anim {
    Sint16 state;
    Sint16 weld_mode;
    Uint16 action;
    Uint16 current;
    Uint16 previous;
    Uint16 next;
    Sint16 updates;
    Sint16 flags;
    Float frame;
    Float start_frame;
    Float *speed;
    Float *pace;
    struct player_action *actions;
    struct weld *welds;
    NJS_ACTION *blend;
};
union character_vars {
    Sint8 b[32];
    Sint16 w[16];
    Sint32 l[8];
    Float f[8];
    void *p[8];
    struct {
        struct e102 *record[1];
        Sint16 skate_steps;
    } e102;
    struct {
        Sint8 dashes[1];
        Uint8 unk_01;
        Sint16 curled_steps;
        Sint16 dash_steps;
        Sint16 steps;
        Uint8 unk_08[0x10];
        Float toe_blend_plus_z;
        Float toe_blend_minus_z;
    } sonic;
    struct {
        union {
            Float coord[6];
            NJS_POINT3 point[2];
        } tips;
        Float spin;
        Float flight;
    } tails;
    union {
        struct {
            Uint8 unk_00[5];
            Sint8 bumps;
        } glide;
        Sint16 w[7];
    } knuckles;
};
struct player_target {
    NJS_POINT3 pos;
    Float radius;
    Float distance;
    Float across;
    Angle off;
    Angle ang;
};
struct character_constants {
    Sint32 jump_hold_steps;
    Float snap;
    Float speed_limit;
    Float fall_limit;
    Float top_speed;
    Float push_speed;
    Float jump_speed;
    Float launch_speed;
    Float slide_speed;
    Float trot_speed;
    Float running_speed;
    Float sprint_speed;
    Float crash_speed;
    Float full_speed;
    Float jump_hold_speed;
    Float ground_accel;
    Float air_accel;
    Float ground_drag;
    Float brake_drag;
    Float air_brake;
    Float air_resist;
    NJS_VECTOR resist;
    Float moving_grip;
    Float side_grip;
    Float still_grip;
    Float unk_6c;
    Float radius;
    Float height;
    Float gravity;
    Float eye_height;
    Float center_y;
};
struct player {
    Float action_speed;
    Sint16 upgrades;
    Sint16 effects;
    Sint16 jump_steps;
    Sint16 launch_steps;
    Sint16 underwater_steps;
    Sint16 idle_steps;
    Sint16 last_flags;
    Sint16 target_count;
    Sint16 path_point;
    Uint8 unk_16[2];
    Float path_distance;
    Float level;
    NJS_VECTOR nudge;
    NJS_VECTOR accel;
    NJS_VECTOR speed;
    NJS_VECTOR wall_normal;
    NJS_VECTOR ground_normal;
    Uint32 ground_flags;
    Uint32 last_ground_flags;
    struct polygon_ball *contact;
    struct task *held;
    struct task *ground_task;
    struct player_mouth *mouth;
    NJS_OBJECT *ground_object;
    struct player_target *targets;
    union character_vars own;
    struct character_constants consts;
    struct player_anim anim;
    NJS_POINT3 weld_point0;
    NJS_POINT3 weld_point1;
    NJS_POINT3 weld_point2;
    NJS_POINT3 weld_point3;
    NJS_POINT3 weld_point4;
    NJS_POINT3 weld_point5;
    NJS_VECTOR weld_axis0;
    NJS_VECTOR weld_axis1;
    NJS_VECTOR weld_axis2;
    NJS_VECTOR weld_axis3;
    NJS_VECTOR weld_axis4;
    NJS_VECTOR weld_axis5;
    struct shadow shadow;
};
struct weld {
    NJS_OBJECT *base;
    NJS_OBJECT *object_a;
    NJS_OBJECT *object_b;
    Uint8 count;
    Sint8 kind;
    Uint8 node_a;
    Uint8 node_b;
    NJS_POINT3 *vertices;
    Uint16 *indices;
};
enum weld_kind {
    WELD_OFF,
    WELD_BOTH,
    WELD_TO_A,
    WELD_TO_B,
    WELD_MARK
};
struct player_action {
    NJS_ACTION *action;
    Uint8 nodes;
    Sint8 mode;
    Uint16 next;
    Float blend;
    Float speed;
};
struct player_look {
    Angle head_aim_y, head_aim_z;
    Angle head_y, head_z;
    Angle eyes_aim_y, eyes_aim_z;
    Angle eye0_y, eye0_z;
    Angle eye1_y, eye1_z;
    Angle head_max_y, head_min_y;
    Angle head_max_z, head_min_z;
    Angle eye0_max_y, eye0_min_y;
    Angle eye0_max_z, eye0_min_z;
    Angle eye1_max_y, eye1_min_y;
    Angle eyes_max_z, eyes_min_z;
    NJS_OBJECT *head;
    NJS_OBJECT *eye0;
    NJS_OBJECT *eye1;
};
enum look_mode { LOOK_INIT, LOOK_AHEAD, LOOK_CAMERA, LOOK_EVENT, LOOK_END };
union player_look_eye {
    Angle ang[3];
    Float pos[3];
};
struct player_look_motion {
    struct player_look look;
    Angle head_ang[3];
    union player_look_eye eye0;
    union player_look_eye eye1;
};
struct player_sway {
    Uint8 unk_00[8];
    Float bob;
    Float sway;
    Uint8 unk_10[0x18];
    Angle lean;
    Angle sway_phase;
    Angle bob_phase;
};
enum sway_mode { SWAY_INIT, SWAY_SWAY, SWAY_END };
struct player_mouth {
    Sint8 from;
    Sint8 to;
    Uint8 unk_02;
    Sint8 key;
    Float amount;
    Float step;
    struct event_mouth_key *script;
    NJS_OBJECT *face;
    NJS_OBJECT *mouth;
    NJS_OBJECT *blend;
    NJS_MOTION *shapes;
};
enum mouth_mode {
    MOUTH_INIT,
    MOUTH_STILL,
    MOUTH_NEXT_KEY,
    MOUTH_SCRIPT,
    MOUTH_TALK
};
struct death_zone {
    Uint32 characters;
    NJS_OBJECT *object;
};
extern struct death_zone **death_zones[];
extern struct task_work *playertwp[];
extern struct task_motion *player_motion[];
extern struct task *player_tasks[8];
extern struct player *player_records[8];
extern Uint8 player_history_index[8];
extern NJS_POINT3 player_history_pos[256][8];
extern Angle player_history_ang[256][8][3];
extern Sint8 player_held_kinds[8];
void player_clear_slots(void);
Bool player_debug_pressed(int player);
void player_init(int player, struct task *task);
void player_free(int player);
void player_finish_step(struct task_work *work, struct task_motion *motion,
                        struct player *record);
int player_action_touch_id(struct task_work *work);
int player_carry_flags(struct task_work *work);
Bool player_touches_shakable(struct task_work *work, struct task_motion *motion,
                             struct player *record);
void player_shake_touched(struct task_work *work, struct task_motion *motion,
                          struct player *record);
void player_approach_touched(struct task_work *work,
                             struct task_motion *motion);
Bool player_upright(struct task_work *work);
Bool player_read_stick(struct task_work *work, Angle *ang, Float *stroke);
Bool player_stick_back_or_end_event(struct task_work *work,
                                    struct task_motion *motion);
enum player_jump { PLAYER_JUMP_NONE, PLAYER_JUMP_PRESSED, PLAYER_JUMP_PANEL };
enum player_jump player_jump_pressed(struct task_work *work,
                                     struct player *record);
Bool player_count_jump_hold(struct task_work *work, struct player *record);
enum player_wall {
    PLAYER_WALL_NO_STICK,
    PLAYER_WALL_AWAY,
    PLAYER_WALL_ACROSS,
    PLAYER_WALL_ASKEW,
    PLAYER_WALL_HEAD_ON
};
int player_face_wall(struct task_work *work, struct task_motion *motion);
int player_stick_into_wall(struct task_work *work, struct task_motion *motion);
int player_move_into_wall(struct task_work *work, struct task_motion *motion);
Bool player_has_target(Uint8 player);
void player_turn_to_target(struct task_work *work, struct task_motion *motion,
                           struct player *record);
void player_accel_ground(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void player_accel_air(struct task_work *work, struct task_motion *motion,
                      struct player *record);
void player_accel_path(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_accel_push(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_accel_brake(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_accel_launched(struct task_work *work, struct task_motion *motion,
                           struct player *record);
void player_accel_roll(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_accel_gravity(struct task_work *work, struct task_motion *motion,
                          struct player *record);
void player_accel_wall(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_accel_fly(struct task_work *work, struct task_motion *motion,
                      struct player *record);
void player_accel_glide(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_accel_climb(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_accel_drive(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_accel_wall_idle(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void player_accel_board(struct task_work *work, struct task_motion *motion,
                        struct player *record, Float max_speed);
void player_accel_board_air(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void player_accel_board_trick(struct task_work *work,
                              struct task_motion *motion,
                              struct player *record);
void player_accel_board_brake(struct task_work *work,
                              struct task_motion *motion,
                              struct player *record);
void player_accel_slope(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_board_spray(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_turn_to_stick(struct task_work *work, struct task_motion *motion,
                          struct player *record);
void player_turn_upright(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void player_apply_accel(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_apply_path_accel(struct task_work *work, struct task_motion *motion,
                             struct player *record);
void player_apply_push(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_apply_climb_accel(struct task_work *work,
                              struct task_motion *motion,
                              struct player *record);
void player_apply_glide_accel(struct task_work *work,
                              struct task_motion *motion,
                              struct player *record);
int player_collide(struct task_work *work, struct task_motion *motion,
                   struct player *record);
int player_collide_climb(struct task_work *work, struct task_motion *motion,
                         struct player *record);
int player_collide_simple(struct task_work *work, struct task_motion *motion,
                          struct player *record);
void player_move_on_path(struct task_work *work, struct task_motion *motion,
                         struct player *record);
Bool player_shift_on_path(struct task_work *work, struct task_motion *motion,
                          struct player *record);
Bool player_slide_on_path(struct task_work *work, struct task_motion *motion,
                          struct player *record);
int player_collide_wall(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_take_wall_speed(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void player_turn_to_wall(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void player_turn_to_world(struct task_work *work, NJS_VECTOR *vector);
void player_take_speed(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_take_push_speed(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void player_anim_step(struct player_anim *anim);
void player_update_welds(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void player_look_turn_head(struct player_look *look);
void player_look_turn_eyes(struct player_look *look);
void player_mouth_step(struct task *task);
void player_mouth_destroy(struct task *task);
void player_mouth_set_script(Sint8 player, int script);
void player_mouth_stop(Uint8 player);
void player_sound_in_mode(int se, Uint8 player, Sint16 mode);
void player_crash_burst(struct task_work *work);
void death_zone_step(struct task *task);
void player_fall(Uint8 player);
void player_down(int player);
void player_set_heading(Sint8 player, Angle ang);
void player_event_run(Uint8 player, Float x, Float z);
void player_event_move(Uint8 player, Float x, Float z);
void player_event_push(Uint8 player, Float x, Float z);
void player_event_stop(Uint8 player);
void player_event_end(Uint8 player);
void player_clear_speed(struct task_motion *motion, struct player *record);
void player_turn_back(struct task_work *work, NJS_VECTOR *vector);
void player_make_ripple(Uint8 player, NJS_POINT3 *pos, Angle *ang);
void player_make_splash(struct task_work *work);
void player_kick_dust(struct task_work *work, struct task_motion *motion,
                      struct player *record);
int player_in_range(const NJS_POINT3 *pos, Float radius);
int player_in_cylinder(NJS_POINT3 *pos, Float radius, Float height);
void player_push_out_of(struct task_work *work);
int player_get_character(Uint8 player);
struct task *player_get_task(Uint8 player);
int player_task_character(struct task *task);
struct player *player_get(Uint8 player);
int player_count(void);
int player_nearest(NJS_POINT3 *pos);
int player_find_rival(Uint8 player);
Bool player_stands_on(Uint8 player, struct task *task);
void player_suspend(Uint8 player);
void player_resume(Uint8 player);
void player_give_speed_up(Uint8 player);
void player_give_magnetic_barrier(Uint8 player);
void player_give_barrier(Uint8 player);
void player_give_invincibility(Uint8 player);
void player_set_look_task(Uint8 player, struct task *task, NJS_POINT3 *offset);
void player_set_look_point(Uint8 player, NJS_POINT3 *pos);
void player_set_look_angles(Uint8 player, struct angles *ang);
void player_clear_look(Uint8 player);
void player_look_at_task(Uint8 player, struct task *task, int steps);
void player_look_at_point(Uint8 player, NJS_POINT3 *pos, Uint32 steps);
void player_look_at_angles(Uint8 player, struct angles *ang, Uint32 steps);
void player_knock_back(Uint8 player, Float x, Float y, Float z);
void player_knock_apart(Uint8 one, Uint8 other, Float speed);
void player_set_mode(Uint8 player, Uint8 mode);
void player_join_path(Uint8 player, struct path *path);
void player_hang_path(Uint8 player, struct path *path, int point);
void player_ledge_path(Uint8 player, struct path *path, int point,
                       struct angles *ang);
void player_run_path(Uint8 player, struct path *path);
void player_spin_path(Uint8 player, struct path *path);
int player_on_path(struct path *path);
void player_circle(Uint8 player, struct task *task);
void player_dangle(Uint8 player, struct task *task);
void player_bounce(Uint8 player, Float x, Float y, Float z);
void player_bounce_higher(Uint8 player, Uint8 bounce, Float x, Float y,
                          Float z);
void player_squash(Uint8 player, Uint8 bounce);
void player_launch(Uint8 player, const Angle *ang, Float speed, Sint16 steps);
void player_launch_speed(Uint8 player, NJS_VECTOR *speed, const Angle *ang,
                         Sint16 steps);
void player_fling(Uint8 player, Float speed, NJS_VECTOR *line);
void player_send_flying(Uint8 player, NJS_VECTOR *speed, const Angle *ang,
                        Sint16 steps);
void player_set_angles(Uint8 player, Angle x, Angle y, Angle z);
void player_face_along(Uint8 player, Float x, Float y, Float z);
void player_set_position(Uint8 player, Float x, Float y, Float z);
Bool player_ground_speed(Uint8 player, Float *speed);
void player_set_speed(Uint8 player, Float x, Float y, Float z);
void player_set_accel(Sint8 player, Float x, Float y, Float z);
void player_updraft(Sint8 player, Float x, Float y, Float z);
void player_push(Sint8 player, Float x, Float y, Float z);
void player_ride_off(Uint8 player, Float x, Float y, Float z);
Bool player_set_history(Uint8 player, int steps, NJS_POINT3 *pos,
                        struct angles *ang);
Bool player_get_history(Uint8 player, int steps, NJS_POINT3 *pos,
                        struct angles *ang);
typedef char *va_list;
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
Angle AdjustAngle(Angle from, Angle to, Angle step);
Angle angle_difference(Angle from, Angle to);
Angle DiffAngle(Angle from, Angle to);
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
enum amenbo_mode {
    AMENBO_ROW,
    AMENBO_REST,
    AMENBO_CHASE,
    AMENBO_HIT,
    AMENBO_BURST
};
struct amenbo_vars {
    Uint8 strokes;
};
static void amenbo_draw(struct task *task);
static void amenbo_destroy(struct task *task);
static void amenbo_step(struct task *task);
extern NJS_TEXNAME e_amenbo_textures[23];
extern NJS_TEXLIST e_amenbo_texlist;
extern NJS_MATERIAL amenbo_thigh_back_minus_x_materials[1];
extern Sint16 amenbo_thigh_back_minus_x_meshes0[15];
extern NJS_COLOR amenbo_thigh_back_minus_x_uvs0[12];
extern NJS_MESHSET amenbo_thigh_back_minus_x_meshsets[1];
extern NJS_POINT3 amenbo_thigh_back_minus_x_points[6];
extern NJS_VECTOR amenbo_thigh_back_minus_x_normals[6];
extern NJS_MODEL amenbo_thigh_back_minus_x_model;
extern NJS_OBJECT amenbo_thigh_back_minus_x;
extern NJS_MATERIAL amenbo_foot_back_minus_x_materials[3];
extern Sint16 amenbo_foot_back_minus_x_meshes0[14];
extern Sint16 amenbo_foot_back_minus_x_meshes1[7];
extern Sint16 amenbo_foot_back_minus_x_meshes2[5];
extern NJS_COLOR amenbo_foot_back_minus_x_uvs0[12];
extern NJS_COLOR amenbo_foot_back_minus_x_uvs1[6];
extern NJS_COLOR amenbo_foot_back_minus_x_uvs2[4];
extern NJS_MESHSET amenbo_foot_back_minus_x_meshsets[3];
extern NJS_POINT3 amenbo_foot_back_minus_x_points[16];
extern NJS_VECTOR amenbo_foot_back_minus_x_normals[16];
extern NJS_MODEL amenbo_foot_back_minus_x_model;
extern NJS_OBJECT amenbo_foot_back_minus_x;
extern NJS_MATERIAL amenbo_shin_back_minus_x_materials[2];
extern Sint16 amenbo_shin_back_minus_x_meshes0[32];
extern Sint16 amenbo_shin_back_minus_x_meshes1[9];
extern NJS_COLOR amenbo_shin_back_minus_x_uvs0[24];
extern NJS_COLOR amenbo_shin_back_minus_x_uvs1[8];
extern NJS_MESHSET amenbo_shin_back_minus_x_meshsets[2];
extern NJS_POINT3 amenbo_shin_back_minus_x_points[12];
extern NJS_VECTOR amenbo_shin_back_minus_x_normals[12];
extern NJS_MODEL amenbo_shin_back_minus_x_model;
extern NJS_OBJECT amenbo_shin_back_minus_x;
extern NJS_OBJECT amenbo_shin_tip_back_minus_x;
extern NJS_OBJECT amenbo_shin_bone_back_minus_x;
extern NJS_OBJECT amenbo_thigh_bone_back_minus_x;
extern NJS_OBJECT amenbo_hip_back_minus_x;
extern NJS_MATERIAL amenbo_thigh_front_minus_x_materials[1];
extern Sint16 amenbo_thigh_front_minus_x_meshes0[15];
extern NJS_COLOR amenbo_thigh_front_minus_x_uvs0[12];
extern NJS_MESHSET amenbo_thigh_front_minus_x_meshsets[1];
extern NJS_POINT3 amenbo_thigh_front_minus_x_points[6];
extern NJS_VECTOR amenbo_thigh_front_minus_x_normals[6];
extern NJS_MODEL amenbo_thigh_front_minus_x_model;
extern NJS_OBJECT amenbo_thigh_front_minus_x;
extern NJS_MATERIAL amenbo_foot_front_minus_x_materials[3];
extern Sint16 amenbo_foot_front_minus_x_meshes0[14];
extern Sint16 amenbo_foot_front_minus_x_meshes1[7];
extern Sint16 amenbo_foot_front_minus_x_meshes2[5];
extern NJS_COLOR amenbo_foot_front_minus_x_uvs0[12];
extern NJS_COLOR amenbo_foot_front_minus_x_uvs1[6];
extern NJS_COLOR amenbo_foot_front_minus_x_uvs2[4];
extern NJS_MESHSET amenbo_foot_front_minus_x_meshsets[3];
extern NJS_POINT3 amenbo_foot_front_minus_x_points[16];
extern NJS_VECTOR amenbo_foot_front_minus_x_normals[16];
extern NJS_MODEL amenbo_foot_front_minus_x_model;
extern NJS_OBJECT amenbo_foot_front_minus_x;
extern NJS_MATERIAL amenbo_shin_front_minus_x_materials[2];
extern Sint16 amenbo_shin_front_minus_x_meshes0[32];
extern Sint16 amenbo_shin_front_minus_x_meshes1[9];
extern NJS_COLOR amenbo_shin_front_minus_x_uvs0[24];
extern NJS_COLOR amenbo_shin_front_minus_x_uvs1[8];
extern NJS_MESHSET amenbo_shin_front_minus_x_meshsets[2];
extern NJS_POINT3 amenbo_shin_front_minus_x_points[12];
extern NJS_VECTOR amenbo_shin_front_minus_x_normals[12];
extern NJS_MODEL amenbo_shin_front_minus_x_model;
extern NJS_OBJECT amenbo_shin_front_minus_x;
extern NJS_OBJECT amenbo_shin_tip_front_minus_x;
extern NJS_OBJECT amenbo_shin_bone_front_minus_x;
extern NJS_OBJECT amenbo_thigh_bone_front_minus_x;
extern NJS_OBJECT amenbo_hip_front_minus_x;
extern NJS_MATERIAL amenbo_thigh_back_plus_x_materials[1];
extern Sint16 amenbo_thigh_back_plus_x_meshes0[15];
extern NJS_COLOR amenbo_thigh_back_plus_x_uvs0[12];
extern NJS_MESHSET amenbo_thigh_back_plus_x_meshsets[1];
extern NJS_POINT3 amenbo_thigh_back_plus_x_points[6];
extern NJS_VECTOR amenbo_thigh_back_plus_x_normals[6];
extern NJS_MODEL amenbo_thigh_back_plus_x_model;
extern NJS_OBJECT amenbo_thigh_back_plus_x;
extern NJS_MATERIAL amenbo_foot_back_plus_x_materials[3];
extern Sint16 amenbo_foot_back_plus_x_meshes0[14];
extern Sint16 amenbo_foot_back_plus_x_meshes1[7];
extern Sint16 amenbo_foot_back_plus_x_meshes2[5];
extern NJS_COLOR amenbo_foot_back_plus_x_uvs0[12];
extern NJS_COLOR amenbo_foot_back_plus_x_uvs1[6];
extern NJS_COLOR amenbo_foot_back_plus_x_uvs2[4];
extern NJS_MESHSET amenbo_foot_back_plus_x_meshsets[3];
extern NJS_POINT3 amenbo_foot_back_plus_x_points[16];
extern NJS_VECTOR amenbo_foot_back_plus_x_normals[16];
extern NJS_MODEL amenbo_foot_back_plus_x_model;
extern NJS_OBJECT amenbo_foot_back_plus_x;
extern NJS_MATERIAL amenbo_shin_back_plus_x_materials[2];
extern Sint16 amenbo_shin_back_plus_x_meshes0[32];
extern Sint16 amenbo_shin_back_plus_x_meshes1[9];
extern NJS_COLOR amenbo_shin_back_plus_x_uvs0[24];
extern NJS_COLOR amenbo_shin_back_plus_x_uvs1[8];
extern NJS_MESHSET amenbo_shin_back_plus_x_meshsets[2];
extern NJS_POINT3 amenbo_shin_back_plus_x_points[12];
extern NJS_VECTOR amenbo_shin_back_plus_x_normals[12];
extern NJS_MODEL amenbo_shin_back_plus_x_model;
extern NJS_OBJECT amenbo_shin_back_plus_x;
extern NJS_OBJECT amenbo_shin_tip_back_plus_x;
extern NJS_OBJECT amenbo_shin_bone_back_plus_x;
extern NJS_OBJECT amenbo_thigh_bone_back_plus_x;
extern NJS_OBJECT amenbo_hip_back_plus_x;
extern NJS_MATERIAL amenbo_thigh_front_plus_x_materials[1];
extern Sint16 amenbo_thigh_front_plus_x_meshes0[15];
extern NJS_COLOR amenbo_thigh_front_plus_x_uvs0[12];
extern NJS_MESHSET amenbo_thigh_front_plus_x_meshsets[1];
extern NJS_POINT3 amenbo_thigh_front_plus_x_points[6];
extern NJS_VECTOR amenbo_thigh_front_plus_x_normals[6];
extern NJS_MODEL amenbo_thigh_front_plus_x_model;
extern NJS_OBJECT amenbo_thigh_front_plus_x;
extern NJS_MATERIAL amenbo_foot_front_plus_x_materials[3];
extern Sint16 amenbo_foot_front_plus_x_meshes0[14];
extern Sint16 amenbo_foot_front_plus_x_meshes1[7];
extern Sint16 amenbo_foot_front_plus_x_meshes2[5];
extern NJS_COLOR amenbo_foot_front_plus_x_uvs0[12];
extern NJS_COLOR amenbo_foot_front_plus_x_uvs1[6];
extern NJS_COLOR amenbo_foot_front_plus_x_uvs2[4];
extern NJS_MESHSET amenbo_foot_front_plus_x_meshsets[3];
extern NJS_POINT3 amenbo_foot_front_plus_x_points[16];
extern NJS_VECTOR amenbo_foot_front_plus_x_normals[16];
extern NJS_MODEL amenbo_foot_front_plus_x_model;
extern NJS_OBJECT amenbo_foot_front_plus_x;
extern NJS_MATERIAL amenbo_shin_front_plus_x_materials[2];
extern Sint16 amenbo_shin_front_plus_x_meshes0[32];
extern Sint16 amenbo_shin_front_plus_x_meshes1[9];
extern NJS_COLOR amenbo_shin_front_plus_x_uvs0[24];
extern NJS_COLOR amenbo_shin_front_plus_x_uvs1[8];
extern NJS_MESHSET amenbo_shin_front_plus_x_meshsets[2];
extern NJS_POINT3 amenbo_shin_front_plus_x_points[12];
extern NJS_VECTOR amenbo_shin_front_plus_x_normals[12];
extern NJS_MODEL amenbo_shin_front_plus_x_model;
extern NJS_OBJECT amenbo_shin_front_plus_x;
extern NJS_OBJECT amenbo_shin_tip_front_plus_x;
extern NJS_OBJECT amenbo_shin_bone_front_plus_x;
extern NJS_OBJECT amenbo_thigh_bone_front_plus_x;
extern NJS_OBJECT amenbo_hip_front_plus_x;
extern NJS_MATERIAL amenbo_tail_materials[3];
extern Sint16 amenbo_tail_meshes0[10];
extern Sint16 amenbo_tail_meshes1[11];
extern Sint16 amenbo_tail_meshes2[5];
extern NJS_COLOR amenbo_tail_uvs0[8];
extern NJS_COLOR amenbo_tail_uvs1[10];
extern NJS_COLOR amenbo_tail_uvs2[4];
extern NJS_MESHSET amenbo_tail_meshsets[3];
extern NJS_POINT3 amenbo_tail_points[9];
extern NJS_VECTOR amenbo_tail_normals[9];
extern NJS_MODEL amenbo_tail_model;
extern NJS_OBJECT amenbo_tail;
extern NJS_MATERIAL amenbo_mouth_materials[4];
extern Sint16 amenbo_mouth_meshes0[10];
extern Sint16 amenbo_mouth_meshes1[11];
extern Sint16 amenbo_mouth_meshes2[9];
extern Sint16 amenbo_mouth_meshes3[4];
extern NJS_COLOR amenbo_mouth_uvs0[8];
extern NJS_COLOR amenbo_mouth_uvs1[10];
extern NJS_COLOR amenbo_mouth_uvs2[8];
extern NJS_COLOR amenbo_mouth_uvs3[3];
extern NJS_MESHSET amenbo_mouth_meshsets[4];
extern NJS_POINT3 amenbo_mouth_points[14];
extern NJS_VECTOR amenbo_mouth_normals[14];
extern NJS_MODEL amenbo_mouth_model;
extern NJS_OBJECT amenbo_mouth;
extern NJS_MATERIAL amenbo_head_materials[8];
extern Sint16 amenbo_head_meshes0[17];
extern Sint16 amenbo_head_meshes1[28];
extern Sint16 amenbo_head_meshes2[5];
extern Sint16 amenbo_head_meshes3[22];
extern Sint16 amenbo_head_meshes4[8];
extern Sint16 amenbo_head_meshes5[30];
extern Sint16 amenbo_head_meshes6[30];
extern Sint16 amenbo_head_meshes7[7];
extern NJS_COLOR amenbo_head_uvs0[14];
extern NJS_COLOR amenbo_head_uvs1[24];
extern NJS_COLOR amenbo_head_uvs2[4];
extern NJS_COLOR amenbo_head_uvs3[20];
extern NJS_COLOR amenbo_head_uvs4[6];
extern NJS_COLOR amenbo_head_uvs5[26];
extern NJS_COLOR amenbo_head_uvs6[26];
extern NJS_COLOR amenbo_head_uvs7[6];
extern NJS_MESHSET amenbo_head_meshsets[8];
extern NJS_POINT3 amenbo_head_points[56];
extern NJS_VECTOR amenbo_head_normals[56];
extern NJS_MODEL amenbo_head_model;
extern NJS_OBJECT amenbo_head;
extern NJS_MATERIAL amenbo_body_materials[5];
extern Sint16 amenbo_body_meshes0[26];
extern Sint16 amenbo_body_meshes1[10];
extern Sint16 amenbo_body_meshes2[20];
extern Sint16 amenbo_body_meshes3[26];
extern Sint16 amenbo_body_meshes4[40];
extern NJS_COLOR amenbo_body_uvs0[20];
extern NJS_COLOR amenbo_body_uvs1[8];
extern NJS_COLOR amenbo_body_uvs2[16];
extern NJS_COLOR amenbo_body_uvs3[20];
extern NJS_COLOR amenbo_body_uvs4[32];
extern NJS_MESHSET amenbo_body_meshsets[5];
extern NJS_POINT3 amenbo_body_points[36];
extern NJS_VECTOR amenbo_body_normals[36];
extern NJS_MODEL amenbo_body_model;
extern NJS_OBJECT amenbo_body;
extern NJS_OBJECT amenbo_object;
extern NJS_MKEY_F amenbo_rest_pos1[21];
extern NJS_MKEY_A amenbo_rest_ang1[21];
extern NJS_MKEY_A amenbo_rest_ang2[53];
extern NJS_MKEY_A amenbo_rest_ang6[60];
extern NJS_MKEY_A amenbo_rest_ang7[60];
extern NJS_MKEY_A amenbo_rest_ang10[60];
extern NJS_MKEY_A amenbo_rest_ang13[60];
extern NJS_MKEY_A amenbo_rest_ang14[60];
extern NJS_MKEY_A amenbo_rest_ang17[58];
extern NJS_MKEY_A amenbo_rest_ang20[60];
extern NJS_MKEY_A amenbo_rest_ang21[60];
extern NJS_MKEY_A amenbo_rest_ang24[60];
extern NJS_MKEY_A amenbo_rest_ang27[60];
extern NJS_MKEY_A amenbo_rest_ang28[60];
extern NJS_MKEY_A amenbo_rest_ang31[58];
extern NJS_MDATA2 amenbo_rest_mdata[33];
extern NJS_MOTION amenbo_rest_motion;
extern NJS_ACTION amenbo_rest_action;
extern NJS_MKEY_F amenbo_chase_pos1[30];
extern NJS_MKEY_A amenbo_chase_ang1[26];
extern NJS_MKEY_A amenbo_chase_ang2[29];
extern NJS_MKEY_A amenbo_chase_ang4[29];
extern NJS_MKEY_A amenbo_chase_ang6[30];
extern NJS_MKEY_A amenbo_chase_ang7[28];
extern NJS_MKEY_A amenbo_chase_ang10[30];
extern NJS_MKEY_A amenbo_chase_ang13[30];
extern NJS_MKEY_A amenbo_chase_ang14[30];
extern NJS_MKEY_A amenbo_chase_ang17[30];
extern NJS_MKEY_A amenbo_chase_ang20[30];
extern NJS_MKEY_A amenbo_chase_ang21[28];
extern NJS_MKEY_A amenbo_chase_ang24[30];
extern NJS_MKEY_A amenbo_chase_ang27[30];
extern NJS_MKEY_A amenbo_chase_ang28[30];
extern NJS_MKEY_A amenbo_chase_ang31[30];
extern NJS_MDATA2 amenbo_chase_mdata[33];
extern NJS_MOTION amenbo_chase_motion;
extern NJS_ACTION amenbo_chase_action;
extern NJS_MKEY_F amenbo_row_pos1[44];
extern NJS_MKEY_A amenbo_row_ang2[42];
extern NJS_MKEY_A amenbo_row_ang4[44];
extern NJS_MKEY_A amenbo_row_ang6[44];
extern NJS_MKEY_A amenbo_row_ang7[44];
extern NJS_MKEY_A amenbo_row_ang10[44];
extern NJS_MKEY_A amenbo_row_ang13[44];
extern NJS_MKEY_A amenbo_row_ang14[44];
extern NJS_MKEY_A amenbo_row_ang17[44];
extern NJS_MKEY_A amenbo_row_ang20[44];
extern NJS_MKEY_A amenbo_row_ang21[44];
extern NJS_MKEY_A amenbo_row_ang24[44];
extern NJS_MKEY_A amenbo_row_ang27[44];
extern NJS_MKEY_A amenbo_row_ang28[44];
extern NJS_MKEY_A amenbo_row_ang31[44];
extern NJS_MDATA2 amenbo_row_mdata[33];
extern NJS_MOTION amenbo_row_motion;
extern NJS_ACTION amenbo_row_action;
extern struct collision_shape amenbo_shapes[2];
extern NJS_MODEL *amenbo_pieces[];
void EnemyPondSkater(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record;
    struct angles slope;
    NJS_POINT3 *pos;
    CCL_Init(task, amenbo_shapes, 3, 1, 1);
    record = EnemyInitialize(task, work);
    work->mode = AMENBO_ROW;
    work->submode = 0;
    work->tick = (Uint8)(rand() * (4.0F * (1.0F / (32767 + 1)))) + 2;
    work->timer = rand() * (150 * (1.0F / (32767 + 1)));
    pos = &work->pos;
    record->sight_distance = 200.0F * 200.0F;
    record->near_distance = 30.0F * 30.0F;
    work->pos.y = ground_nearest(pos->x, pos->y, pos->z, &slope);
    work->scl.x = 1.0F;
    work->scl.y = 1.0F;
    work->scl.z = 0.0F;
    record->probe_offset.x = 0.0F;
    record->probe_offset.y = 10.0F;
    record->probe_offset.z = 0.0F;
    record->top = 10.0F;
    record->radius = 15.0F;
    record->bottom = -10.0F;
    record->floor_bounce = 1.0F;
    record->friction = 1.0F;
    record->unk_c4 = 1.0F;
    record->wall_bounce = 1.0F;
    record->action = &amenbo_row_action;
    record->frame = 0.0F;
    task->motion = &record->motion;
    Knuckles_KakeraGame_Set_CheckEme(work, record);
    task->destructor = amenbo_destroy;
    task->step = amenbo_step;
    task->draw = amenbo_draw;
    record->flags |= 0x2000;
}
static void amenbo_aim_left(struct task_work *work,
                            struct lockon_target *record)
{
    switch (work->mode) {
    case AMENBO_ROW:
        if ((*(Uint16 *)&(work)->timer) == 70) {
            record->aim_y = work->ang.y + ((Angle)(((60) * 65536.0) / 360.0));
        }
        record->turn_speed = 0x60;
        break;
    case AMENBO_CHASE:
        if ((*(Uint16 *)&(work)->timer) == 15) {
            record->aim_y = work->ang.y + ((Angle)(((60) * 65536.0) / 360.0));
        }
        record->turn_speed = 0x200;
        break;
    default:
        return;
    }
}
static void amenbo_aim_right(struct task_work *work,
                             struct lockon_target *record)
{
    switch (work->mode) {
    case AMENBO_ROW:
        if ((*(Uint16 *)&(work)->timer) == 70) {
            record->aim_y = work->ang.y - ((Angle)(((60) * 65536.0) / 360.0));
        }
        record->turn_speed = 0x60;
        break;
    case AMENBO_CHASE:
        if ((*(Uint16 *)&(work)->timer) == 15) {
            record->aim_y = work->ang.y - ((Angle)(((60) * 65536.0) / 360.0));
        }
        record->turn_speed = 0x200;
        break;
    default:
        return;
    }
}
static void amenbo_turn(struct task_work *work, struct lockon_target *record)
{
    if (work->flags & (0x200 | 0x1000)) {
        enemy_turn_home(work, record);
    } else {
        switch (work->mode) {
        case AMENBO_ROW:
            amenbo_aim_left(work, record);
            work->ang.y =
                AdjustAngle(work->ang.y, record->aim_y, record->turn_speed);
            break;
        case AMENBO_CHASE:
            if (work->flags & 0x800) {
                amenbo_aim_left(work, record);
            } else {
                amenbo_aim_right(work, record);
            }
            work->ang.y =
                AdjustAngle(work->ang.y, record->aim_y, record->turn_speed);
            break;
        }
    }
}
static void amenbo_take_hit(struct task_work *work,
                            struct lockon_target *record)
{
    struct collision_work *collision;
    struct collision_work *hit;
    enemy_ignore((void *)playertwp);
    collision = work->collision;
    hit = collision->hit;
    if (enemy_take_hit(work, record)) {
        work->mode = AMENBO_HIT;
        ((work)->vars.b[1] = 0, (work)->vars.b[2] = 1);
        work->timer = 0;
        work->scl.z = 0.35F;
        if (hit->kind == 0) {
            player_set_speed(0, 0.0F, 2.0F, 0.0F);
        }
    }
}
static void amenbo_spring_scale(struct task_work *work)
{
    Float stretch = work->scl.y - 1.0F;
    work->scl.z += -(work->scl.z * 0.12F) - (stretch * 0.32F);
    work->scl.y += work->scl.z;
    work->scl.x = 2.0F - work->scl.y;
}
static void FUN_8c0f52ea(struct task_work *work, struct lockon_target *record)
{
    struct task_work *player;
    Float distance2;
    Angle facing;
    Angle toward;
    Angle side;
    Angle away;
    Sint8 i;
    work->flags &= ~0x400;
    for (i = 0; i < 2; i++) {
        player = playertwp[i];
        if (player != ((void *)0)) {
            distance2 = ((player->pos.x - work->pos.x) * (player->pos.x - work->pos.x)) +
                        ((player->pos.y - work->pos.y) * (player->pos.y - work->pos.y)) +
                        ((player->pos.z - work->pos.z) * (player->pos.z - work->pos.z));
            if (distance2 < record->sight_distance) {
                facing = work->ang.y;
                toward = (Angle)(njArcTan2(player->pos.x - work->pos.x,
                                        player->pos.z - work->pos.z) *
                                 (65536.0 / (2 * 3.141592))) -
                         ((Angle)(((90) * 65536.0) / 360.0));
                side = angle_difference(toward, facing);
                away = DiffAngle(toward, facing);
                if (away < record->sight_angle) {
                    work->flags |= 0x400;
                } else if (distance2 < record->near_distance) {
                    work->flags |= 0x400;
                }
                if (side < 0) {
                    work->flags |= 0x800;
                } else {
                    work->flags &= ~0x800;
                }
            }
        }
    }
}
static void FUN_8c0f53f0(struct task_work *work, struct lockon_target *record)
{
    Float frame = record->frame;
    switch (work->mode) {
    case AMENBO_ROW:
        if (frame > 7.0F && frame < 14.0F) {
            record->motion.accel.x = njCos(work->ang.y) * 0.3F;
            record->motion.accel.z = -(njSin(work->ang.y) * 0.3F);
        }
        if ((*(Uint16 *)&(work)->timer)++ > 150) {
            work->timer = 0;
            work->flags |= 0x100;
            if (work->flags & 0x400) {
                work->mode = AMENBO_CHASE;
            } else if (((struct amenbo_vars *)&(work)->vars)->strokes++ > work->tick) {
                work->tick = (Uint8)(rand() * (4.0F * (1.0F / (32767 + 1)))) + 2;
                work->mode = AMENBO_REST;
                ((struct amenbo_vars *)&(work)->vars)->strokes = 0;
            }
            record->frame = 0.0F;
        }
        break;
    case AMENBO_CHASE:
        if (frame > 7.0F && frame < 14.0F) {
            record->motion.accel.x = njCos(work->ang.y) * 0.35F;
            record->motion.accel.z = -(njSin(work->ang.y) * 0.35F);
        }
        if ((*(Uint16 *)&(work)->timer)++ > 35) {
            work->timer = 0;
            work->flags |= 0x100;
            if (work->flags & 0x400) {
                work->mode = AMENBO_CHASE;
            } else if (((struct amenbo_vars *)&(work)->vars)->strokes++ > work->tick) {
                work->tick = (Uint8)(rand() * (4.0F * (1.0F / (32767 + 1)))) + 2;
                work->mode = AMENBO_REST;
                ((struct amenbo_vars *)&(work)->vars)->strokes = 0;
            } else {
                work->mode = AMENBO_ROW;
            }
            record->frame = 0.0F;
        }
        break;
    }
}
static void amenbo_move(struct task_work *work, struct lockon_target *record)
{
    record->motion.accel.x += -(record->motion.speed.x * 0.04F);
    if (_builtin_fabsf(record->motion.speed.x) < 0.01F) {
        record->motion.speed.x = 0.0F;
    }
    record->motion.accel.z += -(record->motion.speed.z * 0.04F);
    if (_builtin_fabsf(record->motion.speed.z) < 0.01F) {
        record->motion.speed.z = 0.0F;
    }
    record->motion.speed.x += record->motion.accel.x;
    record->motion.speed.z += record->motion.accel.z;
    work->pos.x += record->motion.speed.x;
    work->pos.z += record->motion.speed.z;
    record->motion.accel.x = 0.0F;
    record->motion.accel.z = 0.0F;
}
static void FUN_8c0f5668(struct task_work *work, struct lockon_target *record)
{
    NJS_ACTION *action = record->action;
    Float frames = (Float)action->motion->nbFrame;
    switch (work->mode) {
    case AMENBO_ROW:
        if (work->flags & 0x100) {
            record->frame = 0.0F;
            work->flags &= ~0x100;
        }
        record->frame += 0.7F;
        if (record->frame > frames) {
            record->frame = frames - 0.1F;
        }
        return;
    case AMENBO_CHASE:
        if (work->flags & 0x100) {
            record->frame = 0.0F;
            work->flags &= ~0x100;
        }
        record->frame += 1.2F;
        if (record->frame > frames) {
            record->frame = frames - 0.1F;
            return;
        }
        break;
    case AMENBO_REST:
        record->frame += 0.8F;
        if (record->frame > frames) {
            record->frame = 0.0F;
            if (record->flags & 0x400) {
                work->mode = AMENBO_CHASE;
            } else {
                work->mode = AMENBO_ROW;
            }
        }
        break;
    default:
        return;
    }
}
static void FUN_8c0f5760(struct task_work *work,
                             struct lockon_target *record)
{
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    amenbo_spring_scale(work);
    njSetTexture(&e_amenbo_texlist);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y + ((Angle)(((90) * 65536.0) / 360.0))) ? (njRotateY)(((void *)0), (work->ang.y + ((Angle)(((90) * 65536.0) / 360.0)))) : (void)0);
    njScale(((void *)0), work->scl.x, work->scl.y, work->scl.x);
    ds_ActionClip(record->action, record->frame);
    njPopMatrix(1);
}
static void amenbo_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    if (!record) {
        return;
    }
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    njSetTexture(&e_amenbo_texlist);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y + ((Angle)(((90) * 65536.0) / 360.0))) ? (njRotateY)(((void *)0), (work->ang.y + ((Angle)(((90) * 65536.0) / 360.0)))) : (void)0);
    njScale(((void *)0), work->scl.x, work->scl.y, work->scl.x);
    ds_ActionClip(record->action, record->frame);
    njPopMatrix(1);
}
static void amenbo_keep_on_water(struct task_work *work,
                                 struct lockon_target *record)
{
    EnemyCheckGroundCollision(work, record);
    if (!(record->flags & 0x4000)) {
        FUN_8c047da2(work, record);
        record->motion.speed.x *= -1.0F;
        record->motion.speed.z *= -1.0F;
        work->ang.x = 0;
        work->ang.z = 0;
        work->flags |= 0x1000;
    } else {
        work->flags &= ~0x1000;
    }
}
static void amenbo_edit_draw(struct task_work *work)
{
    njSetTexture(&e_amenbo_texlist);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y + ((Angle)(((90) * 65536.0) / 360.0))) ? (njRotateY)(((void *)0), (work->ang.y + ((Angle)(((90) * 65536.0) / 360.0)))) : (void)0);
    late_DrawObject(&amenbo_object);
    njPopMatrix(1);
}
static void amenbo_destroy(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    enemy_end(task, work, record);
}
static void amenbo_burst(struct task_work *work, struct lockon_target *record)
{
    CreateFlash2(work->pos.x, work->pos.y + 5.0F, work->pos.z, 1.4F);
    enemy_break(work, amenbo_pieces, &e_amenbo_texlist);
    enemy_scatter_debris(work, 8);
    animal_create_random(1, work->pos.x, work->pos.y + 15.0F, work->pos.z);
}
static void FUN_8c0f59ea(struct task_work *work, struct lockon_target *record)
{
    record->action = &amenbo_row_action;
    record->sight_angle = ((Angle)(((80) * 65536.0) / 360.0));
    FUN_8c0f52ea(work, record);
    amenbo_turn(work, record);
    FUN_8c0f53f0(work, record);
    amenbo_move(work, record);
    amenbo_keep_on_water(work, record);
    FUN_8c0f5668(work, record);
    FUN_8c0f5760(work, record);
    amenbo_take_hit(work, record);
}
static void amenbo_chase(struct task_work *work, struct lockon_target *record)
{
    record->sight_angle = ((Angle)(((180) * 65536.0) / 360.0));
    record->action = &amenbo_chase_action;
    FUN_8c0f52ea(work, record);
    amenbo_turn(work, record);
    FUN_8c0f53f0(work, record);
    amenbo_move(work, record);
    amenbo_keep_on_water(work, record);
    FUN_8c0f5668(work, record);
    FUN_8c0f5760(work, record);
    amenbo_take_hit(work, record);
}
static void FUN_8c0f5b00(struct task_work *work, struct lockon_target *record)
{
    enemy_target_distance2(work, record);
    record->action = &amenbo_rest_action;
    record->sight_angle = ((Angle)(((180) * 65536.0) / 360.0));
    FUN_8c0f52ea(work, record);
    amenbo_keep_on_water(work, record);
    FUN_8c0f5668(work, record);
    FUN_8c0f5760(work, record);
    amenbo_take_hit(work, record);
}
static void amenbo_hit(struct task_work *work, struct lockon_target *record)
{
    amenbo_keep_on_water(work, record);
    FUN_8c0f5668(work, record);
    FUN_8c0f5760(work, record);
    if ((*(Uint16 *)&(work)->timer)++ > 15) {
        work->mode = AMENBO_BURST;
    }
}
static void amenbo_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    if (edit_mode) {
        amenbo_edit_draw(work);
        return;
    }
    (void)player->mode;
    if (CheckRangeOutWithR(task, (700.0F * 700.0F))) {
        return;
    }
    switch (work->mode) {
    case AMENBO_ROW:
        FUN_8c0f59ea(work, record);
        break;
    case AMENBO_CHASE:
        amenbo_chase(work, record);
        break;
    case AMENBO_REST:
        FUN_8c0f5b00(work, record);
        break;
    case AMENBO_HIT:
        amenbo_hit(work, record);
        break;
    case AMENBO_BURST:
        amenbo_burst(work, record);
        enemy_end(task, work, record), DeadOut(task);
        return;
    default:
        break;
    }
    enemy_save_pos(work, record);
    EntryColliList(work);
}
