/* @unit 8C0F5C80-8C0F7C60 @data 8C15CFD4-8C15D054 +r04 +egflags +pool32 +poolafter=FUN_8c0f5e72,FUN_8c0f6208,leon_draw_body,FUN_8c0f6ff6,FUN_8c0f75dc,FUN_8c0f791a +poolbra=FUN_8c0f60c6:1,FUN_8c0f6208:3,leon_draw_body:2,leon_draw_body:4,FUN_8c0f70a0:4,FUN_8c0f7782:1 +asmfunc=FUN_8c0f6ae0:+8c0f6ff0,FUN_8c0f7a88,leon_draw_body:+8c0f6ae0 */
/* Ported from the Japanese release's src/enemy/leon.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
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
Float CalcDistance(NJS_POINT3 *p1, NJS_POINT3 *p2);
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
Bool OnEdit(struct task *task);
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
void ___dsActionLink(NJS_ACTION_LINK *link, Float ratio);
void draw_motion_link(NJS_OBJECT *object, NJS_MOTION_LINK *link, Float ratio);
void draw_shape_motion_link(NJS_OBJECT *object, NJS_MOTION_LINK *link,
                            NJS_MOTION_LINK *shape, Float ratio);
void draw_shape_motion(NJS_OBJECT *object, NJS_MOTION *motion,
                       NJS_MOTION *shape, Float frame);
void SetMaterial(Float alpha, Float red, Float green, Float blue);
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
struct player;
struct player_action;
struct task_work;
void pose_draw_player(struct task_work *work, struct player *player,
                      struct player_action *actions);
Bool pose_draw_player_node(struct task_work *work, struct player *player,
                           struct player_action *actions, Uint32 node);
Bool CalcMMMatrix(NJS_MATRIX *base, NJS_ACTION *action, Float frame, Uint32 node,
                 NJS_MATRIX *out);
Uint32 pose_get_count(void);
Bool pose_get_matrix(Uint32 node, NJS_MATRIX *out);
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
int ChkPause(void);
#pragma inline(enemy_ignore2)
static void enemy_ignore2(void *c, int s)
{
}
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
void enemy_restore_pos(struct task_work *work, struct lockon_target *record);
int enemy_aim_at_target(struct task_work *work, struct lockon_target *record);
int FUN_8c047e94(struct task_work *work, struct lockon_target *record);
int enemy_aim_at_home(struct task_work *work, struct lockon_target *record);
int enemy_turn_home(struct task_work *work, struct lockon_target *record);
int EnemyCalcPlayerAngle(struct task_work *work, struct lockon_target *record,
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
Float EnemyDist2FromPlayer(struct task_work *work, int player);
Sint8 EnemyCheckFrameIn(NJS_POINT3 *pos);
void enemy_target_near_player(struct task_work *work,
                              struct lockon_target *record, int player,
                              int spot);
void enemy_break(struct task_work *work, NJS_MODEL **models,
                 NJS_TEXLIST *texlist);
void enemy_scatter_debris(struct task_work *work, Uint8 count);
void enemy_spring_scale(struct task_work *work, struct lockon_target *record);
void enemy_bounce_player(Sint8 player);
Bool enemy_take_hit(struct task_work *work, struct lockon_target *record);
struct lockon_target;
struct task;
struct task_work;
extern NJS_TEXLIST e_leon_texlist;
void FUN_8c0f5c80(struct task *task);
void leon_collide(struct task_work *work, struct lockon_target *record);
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
struct task;
enum knuckles_mode {
    KNUCKLES_INIT,
    KNUCKLES_STAND,
    KNUCKLES_WALK,
    KNUCKLES_PATH,
    KNUCKLES_ROLL,
    KNUCKLES_PATH_SPIN,
    KNUCKLES_JUMP,
    KNUCKLES_SPRING,
    KNUCKLES_LAUNCH,
    KNUCKLES_FALL,
    KNUCKLES_STOP,
    KNUCKLES_GLIDE,
    KNUCKLES_GLIDE_TURN,
    KNUCKLES_PUSH,
    KNUCKLES_HURT,
    KNUCKLES_BACK,
    KNUCKLES_POSE,
    KNUCKLES_CRASH,
    KNUCKLES_HOMING,
    KNUCKLES_DIG_DOWN,
    KNUCKLES_DIG_UP,
    KNUCKLES_DIG_OUT,
    KNUCKLES_DIG_FAIL,
    KNUCKLES_DIG_FAIL_BACK,
    KNUCKLES_CLIMB,
    KNUCKLES_CLIMB_OUT,
    KNUCKLES_PUNCH,
    KNUCKLES_LIFT,
    KNUCKLES_PUT_DOWN,
    KNUCKLES_HOLD_STAND,
    KNUCKLES_GRIP,
    KNUCKLES_HOLD_WALK,
    KNUCKLES_THROW,
    KNUCKLES_HOLD_STOP,
    KNUCKLES_HOLD_FALL,
    KNUCKLES_HOLD_JUMP,
    KNUCKLES_HOLD_SPRING,
    KNUCKLES_HOLD_LAUNCH,
    KNUCKLES_PULL,
    KNUCKLES_AIR_THROW,
    KNUCKLES_SHAKE,
    KNUCKLES_HOLD_SHAKE,
    KNUCKLES_HANG,
    KNUCKLES_HANG_GO,
    KNUCKLES_LEDGE,
    KNUCKLES_LEDGE_GO,
    KNUCKLES_PANEL_JUMP,
    KNUCKLES_PANEL_WAIT,
    KNUCKLES_ICED,
    KNUCKLES_EVENT,
    KNUCKLES_RISE,
    KNUCKLES_DOWN,
    KNUCKLES_MODULE_POSE,
    KNUCKLES_EDIT
};
enum knuckles_activity {
    KNUCKLES_DIGGING_DOWN = 1,
    KNUCKLES_DIGGING_UP,
    KNUCKLES_DIGGING_OUT,
    KNUCKLES_PUNCHING,
    KNUCKLES_CLIMBING,
    KNUCKLES_CLIMBING_OUT,
    KNUCKLES_GLIDING
};
void knuckles_step(struct task *task);
int knuckles_get_activity(int player);
Bool knuckles_pick_pieces(void);
Bool knuckles_nearest_piece(NJS_POINT3 *from, NJS_POINT3 *pos, Float *distance);
Bool knuckles_find_piece(int id, NJS_POINT3 *pos);
Bool Knuckles_KakeraGame_Set_PutEme(int id, NJS_POINT3 *pos);
Bool knuckles_mark_piece(int id, NJS_POINT3 *pos);
void knuckles_force_dig(int sound);
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
enum leon_mode {
    LEON_WAIT = 0,
    LEON_STALK = 1,
    LEON_LICK = 2,
    LEON_HIT = 4,
    LEON_BURST = 5
};
enum leon_submode { LEON_BLENDING, LEON_PLAYING };
struct leon_vars {
    Uint8 unk_00;
    Uint8 since_hit;
};
enum leon_angle { LEON_HEAD_PITCH, LEON_HEAD_YAW };
static void FUN_8c0f75dc(struct task *task);
static void FUN_8c0f7a88(struct task *task);
extern NJS_MATERIAL leon_tail_crest_materials[1];
extern Sint16 leon_tail_crest_meshes0[24];
extern NJS_COLOR leon_tail_crest_uvs0[20];
extern NJS_MESHSET leon_tail_crest_meshsets[1];
extern NJS_POINT3 leon_tail_crest_points[8];
extern NJS_VECTOR leon_tail_crest_normals[8];
extern NJS_MODEL leon_tail_crest_model;
extern NJS_OBJECT leon_tail_crest;
extern NJS_MATERIAL leon_tail_materials[3];
extern Sint16 leon_tail_meshes0[21];
extern Sint16 leon_tail_meshes1[12];
extern Sint16 leon_tail_meshes2[7];
extern NJS_COLOR leon_tail_uvs0[18];
extern NJS_COLOR leon_tail_uvs1[10];
extern NJS_COLOR leon_tail_uvs2[6];
extern NJS_MESHSET leon_tail_meshsets[3];
extern NJS_POINT3 leon_tail_points[13];
extern NJS_VECTOR leon_tail_normals[13];
extern NJS_MODEL leon_tail_model;
extern NJS_OBJECT leon_tail;
extern NJS_MATERIAL leon_thigh_back_minus_x_materials[1];
extern Sint16 leon_thigh_back_minus_x_meshes0[9];
extern NJS_COLOR leon_thigh_back_minus_x_uvs0[8];
extern NJS_MESHSET leon_thigh_back_minus_x_meshsets[1];
extern NJS_POINT3 leon_thigh_back_minus_x_points[6];
extern NJS_VECTOR leon_thigh_back_minus_x_normals[6];
extern NJS_MODEL leon_thigh_back_minus_x_model;
extern NJS_OBJECT leon_thigh_back_minus_x;
extern NJS_MATERIAL leon_shin_back_minus_x_materials[3];
extern Sint16 leon_shin_back_minus_x_meshes0[9];
extern Sint16 leon_shin_back_minus_x_meshes1[9];
extern Sint16 leon_shin_back_minus_x_meshes2[17];
extern NJS_COLOR leon_shin_back_minus_x_uvs0[8];
extern NJS_COLOR leon_shin_back_minus_x_uvs1[8];
extern NJS_COLOR leon_shin_back_minus_x_uvs2[14];
extern NJS_MESHSET leon_shin_back_minus_x_meshsets[3];
extern NJS_POINT3 leon_shin_back_minus_x_points[15];
extern NJS_VECTOR leon_shin_back_minus_x_normals[15];
extern NJS_MODEL leon_shin_back_minus_x_model;
extern NJS_OBJECT leon_shin_back_minus_x;
extern NJS_MATERIAL leon_foot_back_minus_x_materials[2];
extern Sint16 leon_foot_back_minus_x_meshes0[15];
extern Sint16 leon_foot_back_minus_x_meshes1[24];
extern NJS_COLOR leon_foot_back_minus_x_uvs0[14];
extern NJS_COLOR leon_foot_back_minus_x_uvs1[20];
extern NJS_MESHSET leon_foot_back_minus_x_meshsets[2];
extern NJS_POINT3 leon_foot_back_minus_x_points[18];
extern NJS_VECTOR leon_foot_back_minus_x_normals[18];
extern NJS_MODEL leon_foot_back_minus_x_model;
extern NJS_OBJECT leon_foot_back_minus_x;
extern NJS_OBJECT leon_foot_bone_back_minus_x;
extern NJS_OBJECT leon_shin_bone_back_minus_x;
extern NJS_OBJECT leon_thigh_bone_back_minus_x;
extern NJS_OBJECT leon_hip_back_minus_x;
extern NJS_MATERIAL leon_thigh_front_minus_x_materials[1];
extern Sint16 leon_thigh_front_minus_x_meshes0[9];
extern NJS_COLOR leon_thigh_front_minus_x_uvs0[8];
extern NJS_MESHSET leon_thigh_front_minus_x_meshsets[1];
extern NJS_POINT3 leon_thigh_front_minus_x_points[6];
extern NJS_VECTOR leon_thigh_front_minus_x_normals[6];
extern NJS_MODEL leon_thigh_front_minus_x_model;
extern NJS_OBJECT leon_thigh_front_minus_x;
extern NJS_MATERIAL leon_shin_front_minus_x_materials[3];
extern Sint16 leon_shin_front_minus_x_meshes0[17];
extern Sint16 leon_shin_front_minus_x_meshes1[9];
extern Sint16 leon_shin_front_minus_x_meshes2[9];
extern NJS_COLOR leon_shin_front_minus_x_uvs0[14];
extern NJS_COLOR leon_shin_front_minus_x_uvs1[8];
extern NJS_COLOR leon_shin_front_minus_x_uvs2[8];
extern NJS_MESHSET leon_shin_front_minus_x_meshsets[3];
extern NJS_POINT3 leon_shin_front_minus_x_points[15];
extern NJS_VECTOR leon_shin_front_minus_x_normals[15];
extern NJS_MODEL leon_shin_front_minus_x_model;
extern NJS_OBJECT leon_shin_front_minus_x;
extern NJS_MATERIAL leon_foot_front_minus_x_materials[2];
extern Sint16 leon_foot_front_minus_x_meshes0[15];
extern Sint16 leon_foot_front_minus_x_meshes1[24];
extern NJS_COLOR leon_foot_front_minus_x_uvs0[14];
extern NJS_COLOR leon_foot_front_minus_x_uvs1[20];
extern NJS_MESHSET leon_foot_front_minus_x_meshsets[2];
extern NJS_POINT3 leon_foot_front_minus_x_points[18];
extern NJS_VECTOR leon_foot_front_minus_x_normals[18];
extern NJS_MODEL leon_foot_front_minus_x_model;
extern NJS_OBJECT leon_foot_front_minus_x;
extern NJS_OBJECT leon_foot_bone_front_minus_x;
extern NJS_OBJECT leon_shin_bone_front_minus_x;
extern NJS_OBJECT leon_thigh_bone_front_minus_x;
extern NJS_OBJECT leon_hip_front_minus_x;
extern NJS_MATERIAL leon_thigh_back_plus_x_materials[1];
extern Sint16 leon_thigh_back_plus_x_meshes0[9];
extern NJS_COLOR leon_thigh_back_plus_x_uvs0[8];
extern NJS_MESHSET leon_thigh_back_plus_x_meshsets[1];
extern NJS_POINT3 leon_thigh_back_plus_x_points[6];
extern NJS_VECTOR leon_thigh_back_plus_x_normals[6];
extern NJS_MODEL leon_thigh_back_plus_x_model;
extern NJS_OBJECT leon_thigh_back_plus_x;
extern NJS_MATERIAL leon_shin_back_plus_x_materials[3];
extern Sint16 leon_shin_back_plus_x_meshes0[9];
extern Sint16 leon_shin_back_plus_x_meshes1[9];
extern Sint16 leon_shin_back_plus_x_meshes2[17];
extern NJS_COLOR leon_shin_back_plus_x_uvs0[8];
extern NJS_COLOR leon_shin_back_plus_x_uvs1[8];
extern NJS_COLOR leon_shin_back_plus_x_uvs2[14];
extern NJS_MESHSET leon_shin_back_plus_x_meshsets[3];
extern NJS_POINT3 leon_shin_back_plus_x_points[15];
extern NJS_VECTOR leon_shin_back_plus_x_normals[15];
extern NJS_MODEL leon_shin_back_plus_x_model;
extern NJS_OBJECT leon_shin_back_plus_x;
extern NJS_MATERIAL leon_foot_back_plus_x_materials[2];
extern Sint16 leon_foot_back_plus_x_meshes0[15];
extern Sint16 leon_foot_back_plus_x_meshes1[24];
extern NJS_COLOR leon_foot_back_plus_x_uvs0[14];
extern NJS_COLOR leon_foot_back_plus_x_uvs1[20];
extern NJS_MESHSET leon_foot_back_plus_x_meshsets[2];
extern NJS_POINT3 leon_foot_back_plus_x_points[18];
extern NJS_VECTOR leon_foot_back_plus_x_normals[18];
extern NJS_MODEL leon_foot_back_plus_x_model;
extern NJS_OBJECT leon_foot_back_plus_x;
extern NJS_OBJECT leon_foot_bone_back_plus_x;
extern NJS_OBJECT leon_shin_bone_back_plus_x;
extern NJS_OBJECT leon_thigh_bone_back_plus_x;
extern NJS_OBJECT leon_hip_back_plus_x;
extern NJS_MATERIAL leon_thigh_front_plus_x_materials[1];
extern Sint16 leon_thigh_front_plus_x_meshes0[9];
extern NJS_COLOR leon_thigh_front_plus_x_uvs0[8];
extern NJS_MESHSET leon_thigh_front_plus_x_meshsets[1];
extern NJS_POINT3 leon_thigh_front_plus_x_points[6];
extern NJS_VECTOR leon_thigh_front_plus_x_normals[6];
extern NJS_MODEL leon_thigh_front_plus_x_model;
extern NJS_OBJECT leon_thigh_front_plus_x;
extern NJS_MATERIAL leon_shin_front_plus_x_materials[3];
extern Sint16 leon_shin_front_plus_x_meshes0[17];
extern Sint16 leon_shin_front_plus_x_meshes1[9];
extern Sint16 leon_shin_front_plus_x_meshes2[9];
extern NJS_COLOR leon_shin_front_plus_x_uvs0[14];
extern NJS_COLOR leon_shin_front_plus_x_uvs1[8];
extern NJS_COLOR leon_shin_front_plus_x_uvs2[8];
extern NJS_MESHSET leon_shin_front_plus_x_meshsets[3];
extern NJS_POINT3 leon_shin_front_plus_x_points[15];
extern NJS_VECTOR leon_shin_front_plus_x_normals[15];
extern NJS_MODEL leon_shin_front_plus_x_model;
extern NJS_OBJECT leon_shin_front_plus_x;
extern NJS_MATERIAL leon_foot_front_plus_x_materials[2];
extern Sint16 leon_foot_front_plus_x_meshes0[15];
extern Sint16 leon_foot_front_plus_x_meshes1[24];
extern NJS_COLOR leon_foot_front_plus_x_uvs0[14];
extern NJS_COLOR leon_foot_front_plus_x_uvs1[20];
extern NJS_MESHSET leon_foot_front_plus_x_meshsets[2];
extern NJS_POINT3 leon_foot_front_plus_x_points[18];
extern NJS_VECTOR leon_foot_front_plus_x_normals[18];
extern NJS_MODEL leon_foot_front_plus_x_model;
extern NJS_OBJECT leon_foot_front_plus_x;
extern NJS_OBJECT leon_foot_bone_front_plus_x;
extern NJS_OBJECT leon_shin_bone_front_plus_x;
extern NJS_OBJECT leon_thigh_bone_front_plus_x;
extern NJS_OBJECT leon_hip_front_plus_x;
extern NJS_MATERIAL leon_crest_materials[1];
extern Sint16 leon_crest_meshes0[24];
extern NJS_COLOR leon_crest_uvs0[20];
extern NJS_MESHSET leon_crest_meshsets[1];
extern NJS_POINT3 leon_crest_points[8];
extern NJS_VECTOR leon_crest_normals[8];
extern NJS_MODEL leon_crest_model;
extern NJS_OBJECT leon_crest;
extern NJS_MATERIAL leon_horn_minus_x_materials[1];
extern Sint16 leon_horn_minus_x_meshes0[10];
extern NJS_COLOR leon_horn_minus_x_uvs0[8];
extern NJS_MESHSET leon_horn_minus_x_meshsets[1];
extern NJS_POINT3 leon_horn_minus_x_points[6];
extern NJS_VECTOR leon_horn_minus_x_normals[6];
extern NJS_MODEL leon_horn_minus_x_model;
extern NJS_OBJECT leon_horn_minus_x;
extern NJS_MATERIAL leon_horn_plus_x_materials[1];
extern Sint16 leon_horn_plus_x_meshes0[10];
extern NJS_COLOR leon_horn_plus_x_uvs0[8];
extern NJS_MESHSET leon_horn_plus_x_meshsets[1];
extern NJS_POINT3 leon_horn_plus_x_points[6];
extern NJS_VECTOR leon_horn_plus_x_normals[6];
extern NJS_MODEL leon_horn_plus_x_model;
extern NJS_OBJECT leon_horn_plus_x;
extern NJS_MATERIAL leon_body_materials[4];
extern Sint16 leon_body_meshes0[12];
extern Sint16 leon_body_meshes1[17];
extern Sint16 leon_body_meshes2[12];
extern Sint16 leon_body_meshes3[7];
extern NJS_COLOR leon_body_uvs0[10];
extern NJS_COLOR leon_body_uvs1[14];
extern NJS_COLOR leon_body_uvs2[10];
extern NJS_COLOR leon_body_uvs3[6];
extern NJS_MESHSET leon_body_meshsets[4];
extern NJS_POINT3 leon_body_points[14];
extern NJS_VECTOR leon_body_normals[14];
extern NJS_MODEL leon_body_model;
extern NJS_OBJECT leon_body;
extern NJS_OBJECT leon_waist;
extern NJS_OBJECT leon_object;
extern NJS_MATERIAL leon_head_horn_materials[1];
extern Sint16 leon_head_horn_meshes0[10];
extern NJS_COLOR leon_head_horn_uvs0[8];
extern NJS_MESHSET leon_head_horn_meshsets[1];
extern NJS_POINT3 leon_head_horn_points[8];
extern NJS_VECTOR leon_head_horn_normals[8];
extern NJS_MODEL leon_head_horn_model;
extern NJS_OBJECT leon_head_horn;
extern NJS_MATERIAL leon_eye_minus_x_materials[3];
extern Sint16 leon_eye_minus_x_meshes0[27];
extern Sint16 leon_eye_minus_x_meshes1[27];
extern Sint16 leon_eye_minus_x_meshes2[6];
extern NJS_COLOR leon_eye_minus_x_uvs0[24];
extern NJS_COLOR leon_eye_minus_x_uvs1[22];
extern NJS_COLOR leon_eye_minus_x_uvs2[5];
extern NJS_MESHSET leon_eye_minus_x_meshsets[3];
extern NJS_POINT3 leon_eye_minus_x_points[21];
extern NJS_VECTOR leon_eye_minus_x_normals[21];
extern NJS_MODEL leon_eye_minus_x_model;
extern NJS_OBJECT leon_eye_minus_x;
extern NJS_MATERIAL leon_jaw_materials[2];
extern Sint16 leon_jaw_meshes0[21];
extern Sint16 leon_jaw_meshes1[11];
extern NJS_COLOR leon_jaw_uvs0[18];
extern NJS_COLOR leon_jaw_uvs1[9];
extern NJS_MESHSET leon_jaw_meshsets[2];
extern NJS_POINT3 leon_jaw_points[12];
extern NJS_VECTOR leon_jaw_normals[12];
extern NJS_MODEL leon_jaw_model;
extern NJS_OBJECT leon_jaw;
extern NJS_MATERIAL leon_throat_materials[1];
extern Sint16 leon_throat_meshes0[21];
extern NJS_COLOR leon_throat_uvs0[18];
extern NJS_MESHSET leon_throat_meshsets[1];
extern NJS_POINT3 leon_throat_points[11];
extern NJS_VECTOR leon_throat_normals[11];
extern NJS_MODEL leon_throat_model;
extern NJS_OBJECT leon_throat;
extern NJS_MATERIAL leon_snout_horn_materials[1];
extern Sint16 leon_snout_horn_meshes0[10];
extern NJS_COLOR leon_snout_horn_uvs0[8];
extern NJS_MESHSET leon_snout_horn_meshsets[1];
extern NJS_POINT3 leon_snout_horn_points[5];
extern NJS_VECTOR leon_snout_horn_normals[5];
extern NJS_MODEL leon_snout_horn_model;
extern NJS_OBJECT leon_snout_horn;
extern NJS_MATERIAL leon_eye_plus_x_materials[3];
extern Sint16 leon_eye_plus_x_meshes0[27];
extern Sint16 leon_eye_plus_x_meshes1[27];
extern Sint16 leon_eye_plus_x_meshes2[6];
extern NJS_COLOR leon_eye_plus_x_uvs0[24];
extern NJS_COLOR leon_eye_plus_x_uvs1[22];
extern NJS_COLOR leon_eye_plus_x_uvs2[5];
extern NJS_MESHSET leon_eye_plus_x_meshsets[3];
extern NJS_POINT3 leon_eye_plus_x_points[21];
extern NJS_VECTOR leon_eye_plus_x_normals[21];
extern NJS_MODEL leon_eye_plus_x_model;
extern NJS_OBJECT leon_eye_plus_x;
extern NJS_MATERIAL leon_head_materials[3];
extern Sint16 leon_head_meshes0[12];
extern Sint16 leon_head_meshes1[27];
extern Sint16 leon_head_meshes2[27];
extern NJS_COLOR leon_head_uvs0[10];
extern NJS_COLOR leon_head_uvs1[24];
extern NJS_COLOR leon_head_uvs2[22];
extern NJS_MESHSET leon_head_meshsets[3];
extern NJS_POINT3 leon_head_points[21];
extern NJS_VECTOR leon_head_normals[21];
extern NJS_MODEL leon_head_model;
extern NJS_OBJECT leon_head;
extern NJS_MATERIAL leon_tongue_materials[1];
extern Sint16 leon_tongue_meshes0[14];
extern NJS_MESHSET leon_tongue_meshsets[1];
extern NJS_POINT3 leon_tongue_points[8];
extern NJS_VECTOR leon_tongue_normals[8];
extern NJS_MODEL leon_tongue_model;
extern NJS_OBJECT leon_tongue;
extern NJS_MATERIAL leon_tongue_tip_materials[1];
extern Sint16 leon_tongue_tip_meshes0[27];
extern NJS_MESHSET leon_tongue_tip_meshsets[1];
extern NJS_POINT3 leon_tongue_tip_points[10];
extern NJS_VECTOR leon_tongue_tip_normals[10];
extern NJS_MODEL leon_tongue_tip_model;
extern NJS_OBJECT leon_tongue_tip;
extern NJS_MATERIAL leon_tail_segment_materials[2];
extern Sint16 leon_tail_segment_meshes0[12];
extern Sint16 leon_tail_segment_meshes1[14];
extern NJS_COLOR leon_tail_segment_uvs0[10];
extern NJS_COLOR leon_tail_segment_uvs1[12];
extern NJS_MESHSET leon_tail_segment_meshsets[2];
extern NJS_POINT3 leon_tail_segment_points[9];
extern NJS_VECTOR leon_tail_segment_normals[9];
extern NJS_MODEL leon_tail_segment_model;
extern NJS_OBJECT leon_tail_segment;
extern NJS_MKEY_F leon_lick_pos1[19];
extern NJS_MKEY_A leon_lick_ang7[19];
extern NJS_MKEY_A leon_lick_ang8[19];
extern NJS_MKEY_A leon_lick_ang10[19];
extern NJS_MKEY_A leon_lick_ang14[19];
extern NJS_MKEY_A leon_lick_ang15[19];
extern NJS_MKEY_A leon_lick_ang17[19];
extern NJS_MKEY_A leon_lick_ang21[19];
extern NJS_MKEY_A leon_lick_ang22[19];
extern NJS_MKEY_A leon_lick_ang24[19];
extern NJS_MKEY_A leon_lick_ang28[19];
extern NJS_MKEY_A leon_lick_ang29[19];
extern NJS_MKEY_A leon_lick_ang31[19];
extern NJS_MDATA2 leon_lick_mdata[36];
extern NJS_MOTION leon_lick_motion;
extern NJS_ACTION leon_lick_action;
extern NJS_MKEY_A leon_jaw_ang0[19];
extern NJS_MKEY_A leon_jaw_ang4[12];
extern NJS_MDATA2 leon_jaw_mdata[7];
extern NJS_MOTION leon_jaw_motion;
extern NJS_ACTION leon_jaw_action[1];
extern NJS_MKEY_F leon_walk_pos1[60];
extern NJS_MKEY_A leon_walk_ang7[60];
extern NJS_MKEY_A leon_walk_ang8[59];
extern NJS_MKEY_A leon_walk_ang10[60];
extern NJS_MKEY_A leon_walk_ang14[60];
extern NJS_MKEY_A leon_walk_ang15[60];
extern NJS_MKEY_A leon_walk_ang17[60];
extern NJS_MKEY_A leon_walk_ang21[60];
extern NJS_MKEY_A leon_walk_ang22[60];
extern NJS_MKEY_A leon_walk_ang24[60];
extern NJS_MKEY_A leon_walk_ang28[60];
extern NJS_MKEY_A leon_walk_ang29[60];
extern NJS_MKEY_A leon_walk_ang31[60];
extern NJS_MDATA2 leon_walk_mdata[36];
extern NJS_MOTION leon_walk_motion;
extern NJS_ACTION leon_walk_action[1];
extern NJS_TEXNAME e_leon_textures[18];
extern NJS_TEXLIST e_leon_texlist;
extern struct collision_shape leon_shapes[3];
void FUN_8c0f5c80(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record;
    struct angles slope;
    CCL_Init(task, leon_shapes, 3, 1, 3);
    work->collision->radius = 60.0F;
    record = EnemyInitialize(task, work);
    work->mode = LEON_WAIT;
    work->submode = LEON_PLAYING;
    work->tick = 0;
    work->timer = 50;
    record->flags |= 0x1;
    record->motion.slip = 0.0F;
    record->turn_speed = 0xe0;
    record->angles[LEON_HEAD_PITCH] = 0;
    record->angles[LEON_HEAD_YAW] = 0;
    ((record)->motion.gravity) = 1.0F;
    ((record)->unk_80) = 0.0F;
    record->aim_y = work->ang.y;
    record->frame = 0.0F;
    ((record)->unk_84) = 0.0F;
    record->action = leon_walk_action;
    record->next_action = leon_walk_action;
    ((record)->heading) = 0x1100;
    (*(Float *)&(record)->motion.record) = 0.0F;
    ((record)->unk_8c) = -1.0F;
    ((record)->unk_4c) = rand() * (3.99F * (1.0F / (32767 + 1)));
    record->probe_offset.x = 0.0F;
    record->probe_offset.y = 8.0F;
    record->probe_offset.z = 0.0F;
    record->top = 6.0F;
    record->radius = 15.0F;
    record->bottom = -8.0F;
    record->wall_bounce = 1.0F;
    record->floor_bounce = 0.2F;
    record->friction = 1.0F;
    record->unk_c4 = 1.0F;
    ((record)->motion.phase) = work->ang.z;
    work->pos.y = shadow_draw_slope(work, 0.0F, &slope) + 0.5F;
    work->ang.x = slope.x;
    work->ang.z = slope.z;
    ((record)->unk_78) = work->scl.y + 100.0F;
    ((record)->unk_7c) = work->scl.z + 100.0F;
    work->scl.x = 1.0F;
    work->scl.y = 1.0F;
    work->scl.z = 0.0F;
    Knuckles_KakeraGame_Set_CheckEme(work, record);
    task->destructor = FUN_8c0f75dc;
    task->step = FUN_8c0f7a88;
    work->flags |= 0x400 | 0x1000;
    work->flags &= ~(0x100 | 0x200);
    knuckles_find_piece(((record)->motion.phase), &work->pos);
}
static void leon_creep(struct task_work *work, struct lockon_target *record)
{
    Float ahead = 0.1F;
    Float across = 0.0F;
    record->motion.accel.x +=
        (ahead * njCos(work->ang.y)) + (across * njSin(work->ang.y));
    record->motion.accel.z +=
        (ahead * njSin(-work->ang.y)) + (across * njCos(work->ang.y));
}
void FUN_8c0f5e72(struct task_work *work, struct lockon_target *record)
{
    struct collision_work *collision;
    enemy_ignore((void *)playertwp);
    enemy_ignore2(work->collision, work->collision->hit_shape);
    if (!enemy_take_hit(work, record)) {
        return;
    }
    work->mode = LEON_BURST;
    ((work)->vars.b[1] = 0, (work)->vars.b[2] = 1);
    work->scl.z = 0.35F;
    work->flags &= ~0x400;
}
static void FUN_8c0f5f40(struct task_work *work)
{
    Float stretch = work->scl.y - 1.0F;
    work->scl.z += -(work->scl.z * 0.2F) - (stretch * 0.32F);
    work->scl.y += work->scl.z;
    work->scl.x = 2.0F - work->scl.y;
}
static void FUN_8c0f5f8a(struct task_work *work, struct lockon_target *record)
{
    if (enemy_target_distance2(work, record) > 40.0F * 40.0F) {
        record->motion.speed.x = njCos(work->ang.y) * 0.5F;
        record->motion.speed.y += -0.18F;
        record->motion.speed.z = njSin(-work->ang.y) * 0.5F;
        ((record)->unk_74) = 2.5F;
    } else {
        record->motion.speed.x = njCos(work->ang.y) * 0.4F;
        record->motion.speed.y += -0.18F;
        record->motion.speed.z = njSin(-work->ang.y) * 0.4F;
        ((record)->unk_74) = 1.1F;
    }
    work->pos.x += record->motion.speed.x;
    work->pos.y += record->motion.speed.y;
    work->pos.z += record->motion.speed.z;
}
static void leon_shoot_tongue(struct task_work *work,
                              struct lockon_target *record)
{
    if (!(work->flags & 0x100) &&
        record->frame > 15.0F - 0.5F && record->frame < 15.0F) {
        ((record)->unk_80) = 4.0F;
        work->flags |= 0x100;
    }
    ((record)->unk_80) -= ((record)->motion.gravity) * 0.0055F;
    ((record)->motion.gravity) += ((record)->unk_80);
    if ((work->flags & 0x100) && ((record)->motion.gravity) < 1.0F) {
        ((record)->motion.gravity) = 1.0F;
        ((record)->unk_80) = 0.0F;
        work->flags &= ~0x100;
        ((work)->tick)++;
    }
}
static void FUN_8c0f60c6(struct task_work *work, struct lockon_target *record)
{
    NJS_ACTION *action = record->action;
    Float frames = (Float)action->motion->nbFrame;
    switch (work->mode) {
    case LEON_STALK:
        record->frame += ((record)->unk_74);
        ((record)->unk_84) = 0.0F;
        break;
    case LEON_LICK:
        if (!(work->flags & 0x200) && (*(Uint16 *)&(work)->timer) > 20) {
            work->flags |= 0x200;
        }
        if ((work->flags & 0x200) &&
            (record->frame < 15.0F ||
             !(work->flags & 0x100))) {
            record->frame += 0.3F;
            ((record)->unk_84) += 0.3F;
        }
        if (((record)->unk_84) >= frames) {
            ((record)->unk_84) -= frames;
            work->timer = 0;
            work->flags &= ~0x200;
        }
        leon_shoot_tongue(work, record);
        break;
    }
    if (record->frame >= frames) {
        record->frame -= frames;
    }
    record->phase += 0x880;
}
static void FUN_8c0f6208(struct task_work *work, struct lockon_target *record)
{
    NJS_VECTOR to;
    int ang;
    if (!(work->flags & 0x200)) {
        to.x = record->target.x - work->pos.x;
        to.y = record->target.y - work->pos.y;
        to.z = record->target.z - work->pos.z;
        ang = angle_difference(
            (Angle)(njArcTan2(njSqrt((to.x * to.x) + (to.z * to.z)), to.y) *
                    (65536.0 / (2 * 3.141592))) -
                0x4000,
            work->ang.z);
        ang = (Uint16)(ang + 0x8000);
        if (ang < 0x8000 - 0x1000) {
            ang = 0x8000 - 0x1000;
        } else if (ang > 0x8000 - (-0x37ff)) {
            ang = 0x8000 - (-0x37ff);
        }
        ang = (Uint16)(ang + 0x8000);
        record->angles[LEON_HEAD_PITCH] = AdjustAngle(
            record->angles[LEON_HEAD_PITCH], -ang, 0x160);
        enemy_aim_at_target(work, record);
        ang = angle_difference(record->aim_y, work->ang.y);
        ang = (Uint16)(ang + 0x8000);
        if (ang < 0x8000 - 0x2000) {
            ang = 0x8000 - 0x2000;
        } else if (ang > 0x8000 - (-0x2fff)) {
            ang = 0x8000 - (-0x2fff);
        }
        ang = (Uint16)(ang + 0x8000);
        record->angles[LEON_HEAD_YAW] =
            AdjustAngle(record->angles[LEON_HEAD_YAW], -ang, 0x1a0);
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
static void leon_draw_body(struct task_work *work, struct lockon_target *record)
{
    NJS_ACTION *action = record->action;
    Angle ang;
    Float along;
    Float frame;
    NJS_MATRIX matrix;
    NJS_MATRIX jaw;
    NJS_POINT3 current;
    NJS_POINT3 next;
    Angle pitch;
    Angle yaw;
    Angle *head;
    Float size;
    int i;
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 10.0F)) {
        return;
    }
    FUN_8c0f5f40(work);
    njSetTexture(&e_leon_texlist);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    SetMaterial(((record)->unk_8c), 0.0F, 0.0F, 0.0F);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    njRotateY(((void *)0), ((Angle)(((90) * 65536.0) / 360.0)));
    njScale(((void *)0), work->scl.x * 1.5F, work->scl.y * 1.5F, work->scl.x * 1.5F);
    njTranslate(((void *)0), 0.0F, 0.0F, 3.0F);
    ds_ActionClip(action, record->frame);
    {
        NJS_POINT3 offset = {0.0F, 0.0F, 0.0F};
        CalcMMMatrix(&nj_unit_matrix_, record->action, record->frame, 1, &matrix);
        njCalcPoint(&matrix, &offset, &current);
        frame = record->frame + 1.0F;
        if (frame >= (Float)record->action->motion->nbFrame) {
            frame -= (Float)record->action->motion->nbFrame;
        }
        CalcMMMatrix(&nj_unit_matrix_, record->action, frame, 1, &matrix);
        njCalcPoint(&matrix, &offset, &next);
        along = njFraction(record->frame);
        njTranslate(((void *)0), (current.x * (1.0F - along)) + (next.x * along),
                    (current.y * (1.0F - along)) + (next.y * along),
                    (current.z * (1.0F - along)) + (next.z * along));
        njPushMatrix(((void *)0));
        njTranslate(((void *)0), 0.0F, 1.9F, 0.4F);
        ((record->angles[LEON_HEAD_YAW]) ? (njRotateY)(((void *)0), (record->angles[LEON_HEAD_YAW])) : (void)0);
        ((record->angles[LEON_HEAD_PITCH]) ? (njRotateX)(((void *)0), (record->angles[LEON_HEAD_PITCH])) : (void)0);
        njTranslate(((void *)0), 0.0F, -4.8F, 0.8F);
        ds_ActionClip(leon_jaw_action, ((record)->unk_84));
        if (work->flags & 0x100) {
            CalcMMMatrix(&nj_unit_matrix_, leon_jaw_action, ((record)->unk_84), 0,
                        &jaw);
            njMultiMatrix(((void *)0), &jaw);
            njTranslate(((void *)0), 0.0F, -1.6F, 1.6F);
            njRotateX(((void *)0), 0x400);
            njPushMatrix(((void *)0));
            njTranslate(((void *)0), 0.0F, 0.0F, ((record)->motion.gravity) * 0.5F);
            njScale(((void *)0), 1.0F, 1.0F, ((record)->motion.gravity));
            draw_model(&leon_tongue_model);
            njPopMatrix(1);
            njPushMatrix(((void *)0));
            njTranslate(((void *)0), 0.0F, 0.0F,
                        (((record)->motion.gravity) * 1.095F) + 1.0F);
            draw_model(&leon_tongue_tip_model);
            njPopMatrix(1);
        }
        njPopMatrix(1);
        offset.x = offset.y = 0.0F;
        offset.z = ((record)->motion.gravity) * 0.8F;
        njPushMatrix(&nj_unit_matrix_);
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
        ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        njRotateY(((void *)0), ((Angle)(((90) * 65536.0) / 360.0)));
        njTranslate(((void *)0), (current.x * (1.0F - along)) + (next.x * along),
                    (current.y * (1.0F - along)) + (next.y * along),
                    (current.z * (1.0F - along)) + (next.z * along));
        njTranslate(((void *)0), 0.0F, 1.9F, 0.4F);
        ((record->angles[LEON_HEAD_YAW]) ? (njRotateY)(((void *)0), (record->angles[LEON_HEAD_YAW])) : (void)0);
        ((record->angles[LEON_HEAD_PITCH]) ? (njRotateX)(((void *)0), (record->angles[LEON_HEAD_PITCH])) : (void)0);
        njTranslate(((void *)0), 0.0F, 1.8F, 6.2F);
        njCalcPoint(((void *)0), &offset, &work->collision->shapes[2].center);
        njPopMatrix(1);
    }
    work->collision->shapes[2].ang.x =
        record->angles[LEON_HEAD_PITCH] + work->ang.x + 0x4000;
    work->collision->shapes[2].ang.y =
        record->angles[LEON_HEAD_YAW] + work->ang.y + 0x4000;
    work->collision->shapes[2].ang.z = work->ang.z;
    work->collision->shapes[2].size_y = ((record)->motion.gravity) * 0.85F;
    head = record->angles;
    ang = (Uint16)(head[LEON_HEAD_PITCH] + 0x8000) >> 2;
    ang = ang + 0xe000;
    ang = -(Uint16)ang;
    pitch = ((record)->heading) + ang;
    yaw = (Uint16)(((Uint16)(head[LEON_HEAD_YAW] + 0x8000) >> 3) + 0xf000);
    size = 2.0F;
    njPushMatrix(((void *)0));
    njTranslate(((void *)0), 0.0F, 2.2F, -5.5F);
    njPushMatrix(((void *)0));
    njScale(((void *)0), 2.0F, 2.0F, 1.0F);
    draw_model(&leon_tail_segment_model);
    njPopMatrix(1);
    if (!ChkPause()) {
    if (work->flags & 0x100) {
        ((record)->unk_88) -= 0.8F;
        if (((record)->unk_88) < (-0.6F)) {
            ((record)->unk_88) = (-0.6F);
        }
        ((record)->heading) -= 0x200;
        if (((record)->heading) < 0x200) {
            ((record)->heading) = 0x200;
        }
        work->collision->shapes[1].flags &= ~0x10;
        work->collision->shapes[2].flags &= ~0x10;
    } else {
        ((record)->unk_88) += 0.4F;
        if (((record)->unk_88) > 6.5F) {
            ((record)->unk_88) = 6.5F;
        }
        ((record)->heading) += 0x80;
        if (((record)->heading) > 0x1100) {
            ((record)->heading) = 0x1100;
        }
        work->collision->shapes[1].flags |= 0x10;
        work->collision->shapes[2].flags |= 0x10;
    }
    }
    yaw = -yaw;
    for (i = 0; i < 9; i++) {
        pitch += (Angle)((((record)->unk_88) + (njSin(record->phase) * 0.6F)) *
                         (65536.0F / 360.0F));
        size -= 0.13F;
        njTranslate(((void *)0), 0.0F, 0.0F, -2.7F);
        ((yaw) ? (njRotateY)(((void *)0), (yaw)) : (void)0);
        ((pitch) ? (njRotateX)(((void *)0), (pitch)) : (void)0);
        njPushMatrix(((void *)0));
        njScale(((void *)0), size, size, 1.0F);
        draw_model(&leon_tail_segment_model);
        njPopMatrix(1);
    }
    njPopMatrix(1);
    njPopMatrix(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
static void FUN_8c0f6ae0(struct task_work *work,
                            struct lockon_target *record)
{
    Angle ang;
    NJS_MATRIX matrix;
    NJS_MATRIX jaw;
    NJS_POINT3 current;
    NJS_POINT3 next;
    Float blend;
    Float rest;
    Angle pitch;
    Angle yaw;
    Float size;
    int i;
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 10.0F)) {
        return;
    }
    FUN_8c0f5f40(work);
    njSetTexture(&e_leon_texlist);
    SetMaterial(((record)->unk_8c), 0.0F, 0.0F, 0.0F);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    njRotateY(((void *)0), ((Angle)(((90) * 65536.0) / 360.0)));
    njScale(((void *)0), work->scl.x * 1.5F, work->scl.y * 1.5F, work->scl.x * 1.5F);
    njTranslate(((void *)0), 0.0F, 0.0F, 3.0F);
    {
        NJS_MOTION_LINK link;
        NJS_ACTION_LINK action;
        action.motionlink = &link;
        action.object = record->action->object;
        link.motion[0] = record->action->motion;
        link.motion[1] = record->next_action->motion;
        link.frame[0] = record->frame;
        link.frame[1] = 0.0F;
        ___dsActionLink(&action, (*(Float *)&(record)->motion.record));
    }
    if (!ChkPause()) {
    (*(Float *)&(record)->motion.record) += 0.07F;
    if ((*(Float *)&(record)->motion.record) > 1.0F) {
        (*(Float *)&(record)->motion.record) = 0.0F;
        record->frame = 0.0F;
        work->submode = LEON_PLAYING;
        record->action = record->next_action;
    }
    }
    {
        NJS_POINT3 offset = {0.0F, 0.0F, 0.0F};
        CalcMMMatrix(&nj_unit_matrix_, record->action, record->frame, 1, &matrix);
        njCalcPoint(&matrix, &offset, &current);
        CalcMMMatrix(&nj_unit_matrix_, record->next_action, 0.0F, 1, &matrix);
        njCalcPoint(&matrix, &offset, &next);
    }
    blend = (*(Float *)&(record)->motion.record);
    rest = 1.0F - blend;
    njTranslate(((void *)0), (current.x * rest) + (next.x * blend),
                (current.y * rest) + (next.y * blend),
                (current.z * rest) + (next.z * blend));
    njPushMatrix(((void *)0));
    njTranslate(((void *)0), 0.0F, 1.9F, 0.4F);
    ((record->angles[LEON_HEAD_PITCH]) ? (njRotateX)(((void *)0), (record->angles[LEON_HEAD_PITCH])) : (void)0);
    ((record->angles[LEON_HEAD_YAW]) ? (njRotateY)(((void *)0), (record->angles[LEON_HEAD_YAW])) : (void)0);
    njTranslate(((void *)0), 0.0F, -4.8F, 0.8F);
    ds_ActionClip(leon_jaw_action, ((record)->unk_84));
    if (work->flags & 0x100) {
        CalcMMMatrix(&nj_unit_matrix_, leon_jaw_action, ((record)->unk_84), 0,
                    &jaw);
        njMultiMatrix(((void *)0), &jaw);
        njTranslate(((void *)0), 0.0F, -1.6F, 1.6F);
        njRotateX(((void *)0), 0x400);
        njPushMatrix(((void *)0));
        njTranslate(((void *)0), 0.0F, 0.0F, ((record)->motion.gravity) * 0.5F);
        njScale(((void *)0), 1.0F, 1.0F, ((record)->motion.gravity));
        draw_model(&leon_tongue_model);
        njPopMatrix(1);
        njPushMatrix(((void *)0));
        njTranslate(((void *)0), 0.0F, 0.0F, (((record)->motion.gravity) * 1.1F) + 1.0F);
        draw_model(&leon_tongue_tip_model);
        njPopMatrix(1);
    }
    njPopMatrix(1);
    ang = -(Uint16)(((Uint16)(record->angles[LEON_HEAD_PITCH] + 0x8000) >> 2) +
                    0xe000);
    pitch = ((record)->heading) + ang;
    yaw = (Uint16)(((Uint16)(record->angles[LEON_HEAD_YAW] + 0x8000) >> 3) +
                   0xf000);
    size = 2.0F;
    njPushMatrix(((void *)0));
    njTranslate(((void *)0), 0.0F, 2.2F, -5.5F);
    njSetTexture(&e_leon_texlist);
    njPushMatrix(((void *)0));
    njScale(((void *)0), 2.0F, 2.0F, 1.0F);
    draw_model(&leon_tail_segment_model);
    njPopMatrix(1);
    if (!ChkPause()) {
    if (work->flags & 0x100) {
        ((record)->unk_88) -= 0.8F;
        if (((record)->unk_88) < (-0.6F)) {
            ((record)->unk_88) = (-0.6F);
        }
        ((record)->heading) -= 0x200;
        if (((record)->heading) < 0x200) {
            ((record)->heading) = 0x200;
        }
    } else {
        ((record)->unk_88) += 0.25F;
        if (((record)->unk_88) > 6.5F) {
            ((record)->unk_88) = 6.5F;
        }
        ((record)->heading) += 0x20;
        if (((record)->heading) > 0x1100) {
            ((record)->heading) = 0x1100;
        }
    }
    }
    yaw = -yaw;
    for (i = 0; i < 9; i++) {
        pitch += (Angle)((((record)->unk_88) + (njSin(record->phase) * 0.6F)) *
                         (65536.0F / 360.0F));
        size -= 0.13F;
        njTranslate(((void *)0), 0.0F, 0.0F, -2.7F);
        if ((ang = yaw) != 0) {
            njRotateY(((void *)0), ang);
        } else {
        }
        ((pitch) ? (njRotateX)(((void *)0), (pitch)) : (void)0);
        njPushMatrix(((void *)0));
        njScale(((void *)0), size, size, 1.0F);
        draw_model(&leon_tail_segment_model);
        njPopMatrix(1);
    }
    njPopMatrix(1);
    njPopMatrix(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
#else
static void FUN_8c0f6ae0(struct task_work *work,
                            struct lockon_target *record)
{
    NJS_POINT3 offset = {0.0F, 0.0F, 0.0F};
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = (int)offset.x; asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56; asm_stub[1] = 57; asm_stub[2] = 58; asm_stub[3] = 59; asm_stub[4] = 60; asm_stub[5] = 61; asm_stub[6] = 62; asm_stub[7] = 63;
    asm_stub[0] = 64; asm_stub[1] = 65; asm_stub[2] = 66; asm_stub[3] = 67; asm_stub[4] = 68; asm_stub[5] = 69; asm_stub[6] = 70; asm_stub[7] = 71;
    asm_stub[0] = 72; asm_stub[1] = 73; asm_stub[2] = 74; asm_stub[3] = 75; asm_stub[4] = 76; asm_stub[5] = 77; asm_stub[6] = 78; asm_stub[7] = 79;
    asm_stub[0] = 80; asm_stub[1] = 81; asm_stub[2] = 82; asm_stub[3] = 83; asm_stub[4] = 84; asm_stub[5] = 85; asm_stub[6] = 86; asm_stub[7] = 87;
    asm_stub[0] = 88; asm_stub[1] = 89; asm_stub[2] = 90; asm_stub[3] = 91; asm_stub[4] = 92; asm_stub[5] = 93; asm_stub[6] = 94; asm_stub[7] = 95;
    asm_stub[0] = 96; asm_stub[1] = 97; asm_stub[2] = 98; asm_stub[3] = 99; asm_stub[4] = 100; asm_stub[5] = 101; asm_stub[6] = 102; asm_stub[7] = 103;
    asm_stub[0] = 104; asm_stub[1] = 105; asm_stub[2] = 106; asm_stub[3] = 107; asm_stub[4] = 108; asm_stub[5] = 109; asm_stub[6] = 110; asm_stub[7] = 111;
    asm_stub[0] = 112; asm_stub[1] = 113; asm_stub[2] = 114; asm_stub[3] = 115; asm_stub[4] = 116; asm_stub[5] = 117; asm_stub[6] = 118; asm_stub[7] = 119;
    asm_stub[0] = 120; asm_stub[1] = 121; asm_stub[2] = 122; asm_stub[3] = 123; asm_stub[4] = 124; asm_stub[5] = 125; asm_stub[6] = 126; asm_stub[7] = 127;
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
    asm_stub[0] = 80; asm_stub[1] = 81; asm_stub[2] = 82; asm_stub[3] = 83; asm_stub[4] = 84; asm_stub[5] = 85; asm_stub[6] = 86; asm_stub[7] = 87;
    asm_stub[0] = 88; asm_stub[1] = 89; asm_stub[2] = 90; asm_stub[3] = 91; asm_stub[4] = 92; asm_stub[5] = 93; asm_stub[6] = 94; asm_stub[7] = 95;
    asm_stub[0] = 96; asm_stub[1] = 97; asm_stub[2] = 98; asm_stub[3] = 99; asm_stub[4] = 100; asm_stub[5] = 101; asm_stub[6] = 102; asm_stub[7] = 103;
    asm_stub[0] = 104; asm_stub[1] = 105; asm_stub[2] = 106; asm_stub[3] = 107; asm_stub[4] = 108; asm_stub[5] = 109; asm_stub[6] = 110; asm_stub[7] = 111;
    asm_stub[0] = 112; asm_stub[1] = 113; asm_stub[2] = 114; asm_stub[3] = 115; asm_stub[4] = 116; asm_stub[5] = 117; asm_stub[6] = 118; asm_stub[7] = 119;
    asm_stub[0] = 120; asm_stub[1] = 121; asm_stub[2] = 122; asm_stub[3] = 123; asm_stub[4] = 124; asm_stub[5] = 125; asm_stub[6] = 126; asm_stub[7] = 127;
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20;
}
#endif
void leon_collide(struct task_work *work, struct lockon_target *record)
{
    EnemyCheckGroundCollision(work, record);
    return;
}
static void FUN_8c0f6ff6(struct task_work *work, struct lockon_target *record)
{
    if (work->flags & 0x1000) {
        ((record)->unk_8c) -= 0.018F;
        if (((record)->unk_8c) < -1.0F) {
            ((record)->unk_8c) = -1.0F;
        }
        return;
    }
    ((record)->unk_8c) += 0.012F;
    if (((record)->unk_8c) > 0.0F) {
        ((record)->unk_8c) = 0.0F;
    }
}
static void leon_fade(struct task_work *work, struct lockon_target *record)
{
    FUN_8c0f6ff6(work, record);
    return;
}
void FUN_8c0f70a0(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 edge;
    NJS_POINT3 from;
    NJS_POINT3 to;
    int i;
    if (OnEdit(task)) {
        if (work->tick > 25) {
            njPrintC(((8) << 16 | (8)), "< LEON >");
            njPrintC(((17) << 16 | (16)), "->             ");
            njPrintC(((17) << 16 | (17)), "-> ROT Y       ");
            njPrintC(((17) << 16 | (18)), "-> EMERALD     ");
            njPrintC(((17) << 16 | (19)), "->             ");
            njPrintC(((17) << 16 | (20)), "-> SEARCH RANGE");
            njPrintC(((17) << 16 | (21)), "-> MOVE RANGE ");
            edge.x = work->scl.y + 100.0F;
            edge.y = 3.0F;
            edge.z = 0.0F;
            for (i = 0; i < 32; i++) {
                njPushMatrix(&nj_unit_matrix_);
                njTranslateV(((void *)0), &work->pos);
                ((i * (0x10000 / 32)) ? (njRotateY)(((void *)0), (i * (0x10000 / 32))) : (void)0);
                njCalcPoint(((void *)0), &edge, &from);
                njPopMatrix(1);
                njPushMatrix(&nj_unit_matrix_);
                njTranslateV(((void *)0), &work->pos);
                (((i + 1) * (0x10000 / 32)) ? (njRotateY)(((void *)0), ((i + 1) * (0x10000 / 32))) : (void)0);
                njCalcPoint(((void *)0), &edge, &to);
                njPopMatrix(1);
                draw_line_v(&from, &to);
            }
        } else {
            njPrintC(((8) << 16 | (8)), "<      >");
            njPrintC(((17) << 16 | (16)), "->             ");
            njPrintC(((17) << 16 | (17)), "-> ROT Y       ");
            njPrintC(((17) << 16 | (18)), "-> EMERALD     ");
            njPrintC(((17) << 16 | (19)), "->             ");
            njPrintC(((17) << 16 | (20)), "->             ");
            njPrintC(((17) << 16 | (21)), "-> MOVE RANGE ");
        }
        if (work->tick++ > 50) {
            work->tick = 0;
        }
    }
    edge.x = work->scl.z + 100.0F;
    edge.y = 0.0F;
    edge.z = 0.0F;
    for (i = 0; i < 32; i++) {
        njPushMatrix(&nj_unit_matrix_);
        njTranslateV(((void *)0), &work->pos);
        ((i * (0x10000 / 32)) ? (njRotateY)(((void *)0), (i * (0x10000 / 32))) : (void)0);
        njCalcPoint(((void *)0), &edge, &from);
        njPopMatrix(1);
        njPushMatrix(&nj_unit_matrix_);
        njTranslateV(((void *)0), &work->pos);
        (((i + 1) * (0x10000 / 32)) ? (njRotateY)(((void *)0), ((i + 1) * (0x10000 / 32))) : (void)0);
        njCalcPoint(((void *)0), &edge, &to);
        njPopMatrix(1);
        draw_line_v(&from, &to);
    }
    njSetTexture(&e_leon_texlist);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y + ((Angle)(((90) * 65536.0) / 360.0))) ? (njRotateY)(((void *)0), (work->ang.y + ((Angle)(((90) * 65536.0) / 360.0)))) : (void)0);
    ds_ActionClip(leon_walk_action, 1.0F);
    njPopMatrix(1);
}
static void FUN_8c0f75dc(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    enemy_end(task, work, record);
}
void leon_burst(struct task_work *work, struct lockon_target *record)
{
    CreateFlash2(work->pos.x, work->pos.y + 5.0F, work->pos.z, 1.4F);
    enemy_scatter_debris(work, 8);
    animal_create_random(15, work->pos.x, work->pos.y + 15.0F, work->pos.z);
}
void leon_wait(struct task_work *work, struct lockon_target *record)
{
    FUN_8c0f60c6(work, record);
    FUN_8c0f5f8a(work, record);
    leon_collide(work, record);
    leon_draw_body(work, record);
    if (EnemyDist2FromPlayer(work, 0) < 300.0F * 300.0F) {
        ((record)->last_mode = (work)->mode, (work)->mode = (LEON_STALK), (work)->timer = 0);
    }
}
static void FUN_8c0f76f0(struct task_work *work,
                             struct lockon_target *record)
{
    if (EnemyCheckFrameIn(&work->pos)) {
        work->flags |= 0x4000;
    } else {
        work->flags &= ~(0x2000 | 0x4000);
    }
    if (work->flags & 0x2000) {
        record->target = playertwp[0]->pos;
    } else {
        enemy_target_near_player(work, record, 0, ((record)->unk_4c));
    }
    if (CalcDistance(&record->home, &work->pos) >
        ((record)->unk_7c) + 100.0F) {
        record->target = record->home;
    }
}
static void leon_face_target(struct task_work *work,
                             struct lockon_target *record)
{
    FUN_8c047e94(work, record);
    return;
}
void FUN_8c0f7782(struct task_work *work, struct lockon_target *record)
{
    FUN_8c0f76f0(work, record);
    leon_face_target(work, record);
    FUN_8c0f6208(work, record);
    leon_creep(work, record);
    FUN_8c0f5f8a(work, record);
    leon_collide(work, record);
    switch (work->submode) {
    case LEON_BLENDING:
        FUN_8c0f60c6(work, record);
        FUN_8c0f6ae0(work, record);
        break;
    case LEON_PLAYING:
        FUN_8c0f60c6(work, record);
        if (((record)->unk_8c) > -0.99F) {
            leon_draw_body(work, record);
        }
        break;
    }
    if ((*(Uint16 *)&(work)->timer) > 60 &&
        enemy_target_distance2(work, record) <
            ((record)->unk_78) * ((record)->unk_78) &&
        (work->flags & 0x4000) && (work->flags & 0x1000)) {
        work->flags |= 0x2000;
        work->flags &= ~0x1000;
        EnemyCalcPlayerAngle(work, record, 0);
        work->ang.y = record->aim_y;
    }
    if (!(work->flags & 0x1000) && ((record)->unk_8c) > -0.1F) {
        ((record)->last_mode = (work)->mode, (work)->mode = (LEON_LICK), (work)->timer = 0);
        ((work)->tick) = 0;
        record->action = leon_walk_action;
        record->next_action = &leon_lick_action;
        work->submode = LEON_BLENDING;
        work->flags &= ~0x200;
    }
}
void FUN_8c0f791a(struct task_work *work, struct lockon_target *record)
{
    record->target = playertwp[0]->pos;
    FUN_8c0f6208(work, record);
    leon_collide(work, record);
    switch (work->submode) {
    case LEON_BLENDING:
        FUN_8c0f6ae0(work, record);
        break;
    case LEON_PLAYING:
        FUN_8c0f60c6(work, record);
        leon_draw_body(work, record);
        if (((work)->tick) > 2 || !(work->flags & 0x200)) {
            ((record)->last_mode = (work)->mode, (work)->mode = (LEON_STALK), (work)->timer = 0);
            ((work)->tick) = 0;
            record->next_action = leon_walk_action;
            work->submode = LEON_BLENDING;
            work->flags &= ~0x200;
            work->flags |= 0x1000;
        }
        break;
    }
}
void leon_hit(struct task_work *work, struct lockon_target *record)
{
    FUN_8c0f5e72(work, record);
    FUN_8c0f5f8a(work, record);
    leon_collide(work, record);
    FUN_8c0f60c6(work, record);
    leon_draw_body(work, record);
    if (((struct leon_vars *)&(work)->vars)->since_hit++ > 10) {
        work->mode = LEON_BURST;
    }
}
void FUN_8c0f7a6a(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    leon_draw_body(work, record);
}
void FUN_8c0f7a7a(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    FUN_8c0f6ae0(work, record);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
static void FUN_8c0f7a88(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    if (edit_mode) {
        FUN_8c0f70a0(task);
        return;
    }
    (void)player->mode;
    if (CheckRangeOutWithR(task, (700.0F * 700.0F))) {
        return;
    }
    FUN_8c0f5e72(work, record);
    switch (work->mode) {
    case LEON_WAIT:
        leon_wait(work, record);
        task->draw = FUN_8c0f7a6a;
        break;
    case LEON_STALK:
        FUN_8c0f7782(work, record);
        if (work->submode) {
            task->draw = FUN_8c0f7a6a;
        } else {
            task->draw = FUN_8c0f7a7a;
        }
        break;
    case LEON_LICK:
        FUN_8c0f791a(work, record);
        if (!work->submode) {
            task->draw = FUN_8c0f7a7a;
        } else {
            task->draw = FUN_8c0f7a6a;
        }
        break;
    case LEON_HIT:
        leon_hit(work, record);
        task->draw = FUN_8c0f7a6a;
        break;
    case LEON_BURST:
        Knuckles_KakeraGame_Set_PutEme(((record)->motion.phase), &work->pos);
        leon_burst(work, record);
        { struct task *t = task; enemy_end(t, work, record), DeadOut(t); }
        task->draw = 0;
        return;
    }
    leon_fade(work, record);
    enemy_save_pos(work, record);
    knuckles_find_piece(((record)->motion.phase), &work->pos);
    work->timer++;
    if ((work->flags & 0x400) && ((record)->unk_8c) > -0.8F) {
        EntryColliList(work);
        if (((record)->unk_8c) == 0.0F) {
            work->collision->shapes->levels =
                (work->collision->shapes->levels & ~0x3) | (1);
            work->collision->shapes->levels =
                work->collision->shapes->levels & ~0xc;
        } else {
            work->collision->shapes->levels =
                work->collision->shapes->levels & ~0x3;
            work->collision->shapes->levels =
                (work->collision->shapes->levels & ~0xc) | ((3) << 2);
        }
    }
}
#else
static void FUN_8c0f7a88(struct task *task)
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
    asm_stub[0] = 80; asm_stub[1] = 81; asm_stub[2] = 82; asm_stub[3] = 83; asm_stub[4] = 84; asm_stub[5] = 85; asm_stub[6] = 86; asm_stub[7] = 87;
    asm_stub[0] = 88; asm_stub[1] = 89; asm_stub[2] = 90; asm_stub[3] = 91; asm_stub[4] = 92; asm_stub[5] = 93; asm_stub[6] = 94; asm_stub[7] = 95;
    asm_stub[0] = 96; asm_stub[1] = 97; asm_stub[2] = 98; asm_stub[3] = 99; asm_stub[4] = 100; asm_stub[5] = 101; asm_stub[6] = 102; asm_stub[7] = 103;
    asm_stub[0] = 104;
}
#endif
