/* @unit 8C0FAE8A-8C0FDE20 +r04 +egflags +pool32 +asmfunc=FUN_8c0faeda:+8c0fb034,SaruBombDraw:+8c0fb3f0,SaruBombCollision:+8c0fb50e,SaruBombCountDraw:+8c0fb6f4,SaruBombCountDown:+8c0fb848,saru_bomb_blast:+8c0fb906,SaruBombAExecutor:+8c0fba40,SaruBombA:+8c0fbbee,FUN_8c0fbd44:+8c0fbefc,saru_draw_throwing:+8c0fc6ac,SaruDecideAimPos:+8c0fcc40,SaruJump:+8c0fd05a,SaruTurnL:+8c0fd240,SaruTurnR:+8c0fd360,SaruTurnP:+8c0fd5a0,SaruRunL:+8c0fd7a0,FUN_8c0fdae4:+8c0fdc20,saru_step:!8c0fddfe,SaruPori:+8c0fd160,FUN_8c0fb034:+8c0fb100,CreateSaruBombExplosion:+8c0fb132,SaruBombADisplayer:+8c0fbcaa,SaruRunR:+8c0fd9c0,FUN_8c0fd9c0:+8c0fdae4,saru_bomb_destroy:+8c0fb91a,SaruDraw:+8c0fc240,SaruWait:+8c0fcf80,FUN_8c0fc6ac:+8c0fca7c,FUN_8c0fae8a:+8c0faeda,saru_break:+8c0fcade,saru_take_hit:+8c0fbf32,SaruTraceCircle:+8c0fbd1c,SaruBombNormal:+8c0fb5a0,saru_draw:+8c0fc0a0,SaruDrawLow:+8c0fc3c0,SaruCheckInterrupt:+8c0fcd80 +poolafter=SaruBombNormal,saru_draw,SaruDrawLow,SaruCheckInterrupt */
/* Ported from the Japanese release's src/enemy/saru.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
#define TEXT_1 ""
#define TEXT_13 ""
#define TEXT_15 ""
#define TEXT_2 ""
#define TEXT_14 ""
#define TEXT_16 ""
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
struct task *CreateElementalTask(Uint16 flags, int level,
                         void (*step)(struct task *task));
struct task *task_alloc(int level, void (*step)(struct task *task));
void task_destroy(struct task *task);
void FreeTask(struct task *task);
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                               struct task *parent);
struct task *task_create_children(struct task_spec *spec, struct task *parent);
void task_destroy_children(struct task *task);
void LoopTaskC(struct task *task);
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
void late_DrawObject(NJS_OBJECT *object);
void FUN_8c09efc0(void);
void FUN_8c09f134(int scroll);
void FUN_8c09f1e0(Float blend);
void FUN_8c09f29a(Float alpha);
struct particle_pool;
struct particle_anim {
    NJS_TEXLIST *tlist;
    NJS_TEXANIM *tanim;
    Sint32 frames;
    Sint32 src_blend;
    Sint32 dst_blend;
};
union particle_vars {
    Sint32 l[2];
    Float f[2];
    void *p[2];
};
struct particle {
    struct particle *next;
    void (*step)(struct particle *particle, struct particle_pool *pool);
    Uint8 life;
    Uint8 unk_09;
    Sint16 frame;
    Angle ang;
    Float time;
    Float scale;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    NJS_ARGB color;
    Float depth;
    union particle_vars vars;
};
struct particle_pool {
    struct particle_pool *next;
    struct particle *particles;
    void (*step)(struct particle_pool *pool);
    Sint32 count;
    struct particle_anim *anim;
    Sint32 flags;
    void *work;
};
void particle_init(struct particle *buffer, Uint32 count);
struct particle *particle_alloc(struct particle_pool *pool,
                                void (*step)(struct particle *particle,
                                             struct particle_pool *pool));
void particle_kill(struct particle *particle);
struct particle_pool *particle_pool_create(struct particle_anim *anim,
                                           Uint32 size);
Bool particle_pool_step(struct particle_pool *pool);
void particle_pool_kill(struct particle_pool *pool);
void particle_pool_release(struct particle_pool *pool);
void particle_pool_pause(struct particle_pool *pool);
void particle_pool_resume(struct particle_pool *pool);
void particle_run(void);
void particle_draw_all(void);
void particle_free_all(void);
void particle_release_all(void);
void particle_set_depth(Float depth);
struct particle_anim;
struct particle_pool;
struct particle_pool_spec {
    struct particle_anim *anim;
    Uint32 size;
    void (*init)(struct particle_pool *pool);
    struct particle_pool *pool;
};
void particle_create_pools(void);
struct dust_params {
    Float scale;
    Float growth;
    Float rate;
    Float drag;
    Float lift;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    NJS_ARGB color;
};
struct dust_vars {
    struct dust_params *params;
};
extern NJS_TEXLIST dust_texlist;
extern NJS_TEXANIM dust_frames[];
extern struct particle_pool_spec dust_pool;
extern struct particle_pool_spec dust_glow_pool;
void dust_rise_step(struct particle *particle, struct particle_pool *pool);
void dust_step(struct particle *particle, struct particle_pool *pool);
void dust_create(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void CreateSmoke2(struct dust_params *params);
void dust_create_glow(struct dust_params *params);
void dust_grow_step(struct particle *particle, struct particle_pool *pool);
struct task_work;
extern NJS_TEXLIST explosion_texlist;
extern struct particle_pool_spec explosion_pool;
void explosion_create(struct task_work *work, Float scale);
void CreateFlash2(Float x, Float y, Float z, Float scale);
void spark_create(NJS_POINT3 *pos, NJS_VECTOR *speed, Float unused);
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
void enemy_restore_pos(struct task_work *work, struct lockon_target *record);
int enemy_aim_at_target(struct task_work *work, struct lockon_target *record);
int enemy_turn_to_target(struct task_work *work, struct lockon_target *record);
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
extern NJS_TEXLIST e_saru_texlist;
extern NJS_OBJECT saru_object;
extern NJS_MODEL saru_body_prism_model;
extern NJS_MODEL saru_arm_prism_model;
extern NJS_ACTION action_saru_robo_grad1_chn2;
extern NJS_ACTION saru_flip_action;
extern NJS_ACTION action_saru_robo_move_chn2;
extern NJS_ACTION action_saru_robo_grad2_chn2;
extern NJS_ACTION action_saru_robo_wait_chn2;
extern NJS_ACTION saru_fidget_action;
extern NJS_TEXLIST e_bomb_texlist;
extern NJS_TEXLIST CreateSpark;
extern NJS_OBJECT togeball_object;
void FUN_8c0fbd44(struct task *task);
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
extern struct particle stage_particles[512];
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
struct story_script;
struct story_section;
struct story_record {
    Sint8 time;
    Sint8 unk_01;
    Sint16 seq;
    Sint16 section;
    Sint16 entrance;
    Uint16 stage_act;
    Uint16 wait_at;
};
extern Bool last_story;
extern int battle_rival;
extern Sint8 stage_clears[8][43];
extern Uint8 event_flags[512];
extern struct story_record story_records[8];
extern Uint8 dat_8c7a2718[8];
extern Sint8 events_played[512];
extern Uint8 dat_8c7a2920[512];
extern Uint8 dat_8c7a2b20[512];
extern Uint8 dat_8c7a2d20[16];
extern Uint8 dat_8c7a2d30[512];
extern Uint8 dat_8c7a2f30[344];
extern struct story_section *story_table;
extern struct story_script *story_current_script;
extern Sint16 story_character;
extern int story_steps;
extern Bool story_ended;
extern int story_event_delay;
void progress_init(void);
void story_clear(void);
void story_enable(void);
void story_disable(void);
Bool story_is_enabled(void);
void story_set_character(int character);
void story_set_next_stage(int section);
void story_start_act(void);
void story_step(void);
void story_save(void);
void fun_8c0955fc(void);
void story_set_wait(Uint16 stage_act);
void story_next_seq(void);
void story_next_section(void);
void story_play_event(int event);
void story_set_time(Sint8 time);
int story_get_time(void);
Bool playable_check(int character);
void playable_set(int character);
void event_flag_set(int flag);
void event_flag_clear(int flag);
Bool event_flag_check(int flag);
Bool story_wait_at(int stage, int act);
void fun_8c0958e8(void);
void story_go_to(int stage, int act);
Bool story_going_to(Uint8 stage, Uint8 act);
void battle_start(int number);
Bool stage_cleared(int stage);
void story_mark_cleared(int stage);
Bool egg_carrier_has_sunk(void);
void field_people_place(void);
void field_people_remove(void);
struct save_time {
    Sint8 minutes;
    Sint8 seconds;
    Sint8 frames;
};
struct save_scores {
    Sint32 score[3];
};
struct save_times {
    struct save_time time[3];
};
struct save_cart_times {
    struct save_time time[3 + 2];
};
struct save_fish {
    Sint16 weight;
    Sint16 kind;
};
struct save {
    Uint32 checksum;
    Sint32 play_time;
    Sint32 stage_scores[32];
    struct save_time stage_times[28];
    Sint16 fishing_scores[(32 - 28)][3];
    struct save_fish biggest_fish[(32 - 28)];
    Sint16 stage_rings[32];
    struct save_scores shooting1_scores[2];
    struct save_scores shooting2_scores[2];
    struct save_scores icecap_scores[2];
    struct save_scores sunaboard_scores[2];
    struct save_scores mole_scores;
    struct save_cart_times cart_times[6];
    struct save_times trial_times[6];
    Sint8 emblems[17];
    Sint8 flags;
    Sint8 lives[6];
    Uint8 character;
    Uint8 unk_259[3];
    Uint16 stage;
    Uint8 unk_25e[2];
    Sint8 event_flags[512 / 8];
    Sint8 events_played[512 / 8];
    Uint8 unk_2e0[8];
    struct story_record story_records[8];
    Sint8 stage_clears[8][43];
};
extern int stage_last_cleared;
extern struct save saves[3];
void save_reset_all(void);
void save_reset(void);
void save_store(void);
void save_update(void);
void save_load(void);
Bool save_check_all(struct save *save);
struct battle;
struct model_vars {
    NJS_OBJECT *object;
    Uint8 unk_04[4];
    NJS_TEXLIST *texlist;
};
struct action_vars {
    NJS_ACTION *action;
    Float frame;
    NJS_TEXLIST *texlist;
};
struct world_model_vars {
    NJS_OBJECT *world;
    NJS_OBJECT *model;
    NJS_TEXLIST *texlist;
};
struct menu_state {
    Uint8 all_open[1];
    Uint8 trial[1];
    Uint8 summary[1];
    Uint8 card_noticed;
    Uint8 unk_04[5];
    Uint8 save;
    Uint8 mode;
    Uint8 wheel_story;
    Uint8 mode_visits;
    Uint8 story;
    Uint8 stage;
    Uint8 act;
    Uint8 unk_10[2];
};
extern struct menu_state menu_state;
extern Sint32 dat_8c793fc4;
extern struct save menu_saves[3];
extern struct task *npc_task;
extern Bool npc_disabled;
void npc_choose(Uint32 loc);
void npc_start(int unused, struct task *player);
int menu_get_story(int character);
Bool npc_leave(void);
struct task *npc_return(void);
void npc_disable(void);
void npc_enable(void);
struct task *battle_begin(struct battle *battle);
struct task *battle_create_rival(struct battle *battle);
void battle_remove_rival(struct battle *battle);
enum battle_outcome {
    BATTLE_RUNNING,
    BATTLE_WON,
    BATTLE_LOST
};
void battle_set_outcome(enum battle_outcome outcome);
enum battle_outcome battle_outcome(void);
Sint16 title_card_load(int frames);
Sint16 title_card_draw(int unused);
void boot_finish(void);
int menu_get_mode(void);
struct save *menu_get_save(void);
enum carry_kind {
    CARRY_KIND_SMALL = 4,
    CARRY_KIND_MEDIUM,
    CARRY_KIND_LARGE,
    CARRY_KIND_SHAKE
};
Bool carry_set_kind(struct task_work *work, struct task_motion *motion,
                    enum carry_kind kind);
void carry_step_small(struct task *task);
void carry_step_large(struct task *task);
void carry_step_still(struct task *task);
void object_clear_touch(struct task_work *work, struct task_motion *motion);
void object_turn_back(struct task_work *work, NJS_VECTOR *vector);
void object_turn(struct task_work *work, NJS_VECTOR *vector);
void object_init(void);
Bool model_start(struct task *task);
Bool model_start_scaled(struct task *task);
Bool model_start_solid(struct task *task);
Bool model_start_solid_scaled(struct task *task);
Bool model_start_world(struct task *task);
Bool model_start_action(struct task *task);
void object_scale_shapes(struct task_work *work);
NJS_OBJECT *object_add_world(NJS_OBJECT *model, struct task *task,
                             Sint32 flags);
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
struct task;
void sound_system_init(void);
void sound_set_space(void);
void sound_load_stage(void);
void sound_load_file(const char *name);
void sound_load_shot_bank(int bank, const char *name);
void sound_load_sequence_bank(int bank, const char *name);
void sound_load_program_bank(int bank, const char *name);
void sound_download(void *data);
void sound_slot_play(int bank, int number, int priority, int slot);
void sound_slot_stop(int slot);
void sound_slot_set_pan(int pan, int slot);
void sound_slot_set_pitch(int pitch, int slot);
void sound_set_qsound(Sint8 *pos);
int dsPlay_oneshot(int se, int id, int priority, int volume);
int dsPlay_oneshot_v(int se, int id, int priority, int volume, Float x, Float y,
                  Float z);
int sound_play_held(int se, int id, int priority, int volume);
int sound_play_for(int se, int id, int priority, int volume, int updates);
int sound_play_at_for(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
int sound_play_around(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, Float radius, int updates);
void sound_stop(int se);
void sound_stop_id(int id);
void sound_set_volume(int id, int volume);
void sound_set_pan(int id, int pan);
void sound_set_pitch(int id, int pitch);
void sound_mute(void);
void sound_unmute(void);
void sound_kill_all(void);
void sound_send_queue(void);
void fun_8c09a47e(void);
void sound_end_act(void);
void sound_pause(void);
void sound_resume(int unused);
void sound_request_fx(int level);
void sound_request_fx_max(void);
void sound_test(void);
void sound_load_voice(void);
void sound_fx_zone_step(struct task *task);
void sound_orbit_step(struct task *task);
void sound_load_alt_voice(void);
void sound_load_alt_field(void);
void sound_play_bank(Uint8 bank, Uint8 number);
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
enum saru_mode {
    SARU_WAIT = 0,
    SARU_HOP = 1,
    SARU_FIDGET = 2,
    SARU_TURN_ON = 3,
    SARU_WALK_ON = 4,
    SARU_TURN_BACK = 5,
    SARU_WALK_BACK = 6,
    SARU_FACE = 7,
    SARU_THROW = 9,
    SARU_CHEER = 10,
    SARU_BREAK = 12
};
enum saru_arms { SARU_BOMB, SARU_TOGEBALL, SARU_UNARMED };
struct saru_vars {
    Uint8 unk_00[4];
    Sint32 since_hit;
};
enum bomb_mode { BOMB_FLY, BOMB_LIE, BOMB_BLAST, BOMB_END };
enum blast_mode { BLAST_INIT, BLAST_GROW, BLAST_END };
struct blast_vars {
    Uint8 unk_00[4];
    Sint32 scroll;
    Float growth;
};
void FUN_8c0fca7c(struct task *task);
void saru_draw(struct task *task);
void saru_step(struct task *task);
extern NJS_TEXNAME e_saru_textures[12];
extern NJS_TEXLIST e_saru_texlist;
extern NJS_OBJECT saru_tail_bone;
extern NJS_MATERIAL saru_thigh_minus_z_materials[2];
extern Sint16 saru_thigh_minus_z_meshes0[12];
extern Sint16 saru_thigh_minus_z_meshes1[3];
extern NJS_COLOR saru_thigh_minus_z_uvs0[12];
extern NJS_MESHSET saru_thigh_minus_z_meshsets[2];
extern NJS_POINT3 saru_thigh_minus_z_points[6];
extern NJS_VECTOR saru_thigh_minus_z_normals[6];
extern NJS_MODEL saru_thigh_minus_z_model;
extern NJS_OBJECT saru_thigh_minus_z;
extern NJS_MATERIAL saru_foot_minus_z_materials[4];
extern Sint16 saru_foot_minus_z_meshes0[4];
extern Sint16 saru_foot_minus_z_meshes1[7];
extern Sint16 saru_foot_minus_z_meshes2[15];
extern Sint16 saru_foot_minus_z_meshes3[12];
extern Sint16 saru_foot_minus_z_meshes4[4];
extern Sint16 saru_foot_minus_z_meshes5[3];
extern NJS_COLOR saru_foot_minus_z_uvs2[15];
extern NJS_COLOR saru_foot_minus_z_uvs3[12];
extern NJS_COLOR saru_foot_minus_z_uvs4[4];
extern NJS_COLOR saru_foot_minus_z_uvs5[3];
extern NJS_MESHSET saru_foot_minus_z_meshsets[6];
extern NJS_POINT3 saru_foot_minus_z_points[11];
extern NJS_VECTOR saru_foot_minus_z_normals[11];
extern NJS_MODEL saru_foot_minus_z_model;
extern NJS_OBJECT saru_foot_minus_z;
extern NJS_MATERIAL saru_shin_minus_z_materials[1];
extern Sint16 saru_shin_minus_z_meshes0[6];
extern Sint16 saru_shin_minus_z_meshes1[12];
extern NJS_COLOR saru_shin_minus_z_uvs0[6];
extern NJS_COLOR saru_shin_minus_z_uvs1[12];
extern NJS_MESHSET saru_shin_minus_z_meshsets[2];
extern NJS_POINT3 saru_shin_minus_z_points[6];
extern NJS_VECTOR saru_shin_minus_z_normals[6];
extern NJS_MODEL saru_shin_minus_z_model;
extern NJS_OBJECT saru_shin_minus_z;
extern NJS_OBJECT saru_shin_tip_minus_z;
extern NJS_OBJECT saru_shin_bone_minus_z;
extern NJS_OBJECT saru_thigh_bone_minus_z;
extern NJS_OBJECT saru_hip_minus_z;
extern NJS_MATERIAL saru_thigh_plus_z_materials[2];
extern Sint16 saru_thigh_plus_z_meshes0[12];
extern Sint16 saru_thigh_plus_z_meshes1[3];
extern NJS_COLOR saru_thigh_plus_z_uvs0[12];
extern NJS_MESHSET saru_thigh_plus_z_meshsets[2];
extern NJS_POINT3 saru_thigh_plus_z_points[6];
extern NJS_VECTOR saru_thigh_plus_z_normals[6];
extern NJS_MODEL saru_thigh_plus_z_model;
extern NJS_OBJECT saru_thigh_plus_z;
extern NJS_MATERIAL saru_foot_plus_z_materials[4];
extern Sint16 saru_foot_plus_z_meshes0[4];
extern Sint16 saru_foot_plus_z_meshes1[7];
extern Sint16 saru_foot_plus_z_meshes2[15];
extern Sint16 saru_foot_plus_z_meshes3[12];
extern Sint16 saru_foot_plus_z_meshes4[4];
extern Sint16 saru_foot_plus_z_meshes5[3];
extern NJS_COLOR saru_foot_plus_z_uvs2[15];
extern NJS_COLOR saru_foot_plus_z_uvs3[12];
extern NJS_COLOR saru_foot_plus_z_uvs4[4];
extern NJS_COLOR saru_foot_plus_z_uvs5[3];
extern NJS_MESHSET saru_foot_plus_z_meshsets[6];
extern NJS_POINT3 saru_foot_plus_z_points[11];
extern NJS_VECTOR saru_foot_plus_z_normals[11];
extern NJS_MODEL saru_foot_plus_z_model;
extern NJS_OBJECT saru_foot_plus_z;
extern NJS_MATERIAL saru_shin_plus_z_materials[1];
extern Sint16 saru_shin_plus_z_meshes0[6];
extern Sint16 saru_shin_plus_z_meshes1[12];
extern NJS_COLOR saru_shin_plus_z_uvs0[6];
extern NJS_COLOR saru_shin_plus_z_uvs1[12];
extern NJS_MESHSET saru_shin_plus_z_meshsets[2];
extern NJS_POINT3 saru_shin_plus_z_points[6];
extern NJS_VECTOR saru_shin_plus_z_normals[6];
extern NJS_MODEL saru_shin_plus_z_model;
extern NJS_OBJECT saru_shin_plus_z;
extern NJS_OBJECT saru_shin_tip_plus_z;
extern NJS_OBJECT saru_shin_bone_plus_z;
extern NJS_OBJECT saru_thigh_bone_plus_z;
extern NJS_OBJECT saru_hip_plus_z;
extern NJS_MATERIAL saru_upper_arm_plus_z_materials[3];
extern Sint16 saru_upper_arm_plus_z_meshes0[12];
extern Sint16 saru_upper_arm_plus_z_meshes1[3];
extern Sint16 saru_upper_arm_plus_z_meshes2[3];
extern NJS_COLOR saru_upper_arm_plus_z_uvs0[12];
extern NJS_COLOR saru_upper_arm_plus_z_uvs1[3];
extern NJS_MESHSET saru_upper_arm_plus_z_meshsets[3];
extern NJS_POINT3 saru_upper_arm_plus_z_points[6];
extern NJS_VECTOR saru_upper_arm_plus_z_normals[6];
extern NJS_MODEL saru_upper_arm_plus_z_model;
extern NJS_OBJECT saru_upper_arm_plus_z;
extern NJS_MATERIAL saru_hand_plus_z_materials[3];
extern Sint16 saru_hand_plus_z_meshes0[6];
extern Sint16 saru_hand_plus_z_meshes1[4];
extern Sint16 saru_hand_plus_z_meshes2[33];
extern Sint16 saru_hand_plus_z_meshes3[4];
extern Sint16 saru_hand_plus_z_meshes4[16];
extern NJS_COLOR saru_hand_plus_z_uvs0[6];
extern NJS_COLOR saru_hand_plus_z_uvs1[4];
extern NJS_COLOR saru_hand_plus_z_uvs2[33];
extern NJS_COLOR saru_hand_plus_z_uvs3[4];
extern NJS_COLOR saru_hand_plus_z_uvs4[16];
extern NJS_MESHSET saru_hand_plus_z_meshsets[5];
extern NJS_POINT3 saru_hand_plus_z_points[17];
extern NJS_VECTOR saru_hand_plus_z_normals[17];
extern NJS_MODEL saru_hand_plus_z_model;
extern NJS_OBJECT saru_hand_plus_z;
extern NJS_MATERIAL saru_forearm_plus_z_materials[1];
extern Sint16 saru_forearm_plus_z_meshes0[6];
extern Sint16 saru_forearm_plus_z_meshes1[12];
extern NJS_COLOR saru_forearm_plus_z_uvs0[6];
extern NJS_COLOR saru_forearm_plus_z_uvs1[12];
extern NJS_MESHSET saru_forearm_plus_z_meshsets[2];
extern NJS_POINT3 saru_forearm_plus_z_points[6];
extern NJS_VECTOR saru_forearm_plus_z_normals[6];
extern NJS_MODEL saru_forearm_plus_z_model;
extern NJS_OBJECT saru_forearm_plus_z;
extern NJS_OBJECT saru_forearm_tip_plus_z;
extern NJS_OBJECT saru_forearm_bone_plus_z;
extern NJS_OBJECT saru_upper_arm_bone_plus_z;
extern NJS_OBJECT saru_shoulder_plus_z;
extern NJS_MATERIAL saru_upper_arm_minus_z_materials[3];
extern Sint16 saru_upper_arm_minus_z_meshes0[12];
extern Sint16 saru_upper_arm_minus_z_meshes1[3];
extern Sint16 saru_upper_arm_minus_z_meshes2[3];
extern NJS_COLOR saru_upper_arm_minus_z_uvs0[12];
extern NJS_COLOR saru_upper_arm_minus_z_uvs1[3];
extern NJS_MESHSET saru_upper_arm_minus_z_meshsets[3];
extern NJS_POINT3 saru_upper_arm_minus_z_points[6];
extern NJS_VECTOR saru_upper_arm_minus_z_normals[6];
extern NJS_MODEL saru_upper_arm_minus_z_model;
extern NJS_OBJECT saru_upper_arm_minus_z;
extern NJS_MATERIAL saru_hand_minus_z_materials[3];
extern Sint16 saru_hand_minus_z_meshes0[6];
extern Sint16 saru_hand_minus_z_meshes1[4];
extern Sint16 saru_hand_minus_z_meshes2[33];
extern Sint16 saru_hand_minus_z_meshes3[4];
extern Sint16 saru_hand_minus_z_meshes4[16];
extern NJS_COLOR saru_hand_minus_z_uvs0[6];
extern NJS_COLOR saru_hand_minus_z_uvs1[4];
extern NJS_COLOR saru_hand_minus_z_uvs2[33];
extern NJS_COLOR saru_hand_minus_z_uvs3[4];
extern NJS_COLOR saru_hand_minus_z_uvs4[16];
extern NJS_MESHSET saru_hand_minus_z_meshsets[5];
extern NJS_POINT3 saru_hand_minus_z_points[17];
extern NJS_VECTOR saru_hand_minus_z_normals[17];
extern NJS_MODEL saru_hand_minus_z_model;
extern NJS_OBJECT saru_hand_minus_z;
extern NJS_MATERIAL saru_forearm_minus_z_materials[1];
extern Sint16 saru_forearm_minus_z_meshes0[6];
extern Sint16 saru_forearm_minus_z_meshes1[12];
extern NJS_COLOR saru_forearm_minus_z_uvs0[6];
extern NJS_COLOR saru_forearm_minus_z_uvs1[12];
extern NJS_MESHSET saru_forearm_minus_z_meshsets[2];
extern NJS_POINT3 saru_forearm_minus_z_points[6];
extern NJS_VECTOR saru_forearm_minus_z_normals[6];
extern NJS_MODEL saru_forearm_minus_z_model;
extern NJS_OBJECT saru_forearm_minus_z;
extern NJS_OBJECT saru_forearm_tip_minus_z;
extern NJS_OBJECT saru_forearm_bone_minus_z;
extern NJS_OBJECT saru_upper_arm_bone_minus_z;
extern NJS_OBJECT saru_shoulder_minus_z;
extern NJS_MATERIAL saru_ears_materials[2];
extern Sint16 saru_ears_meshes0[30];
extern Sint16 saru_ears_meshes1[42];
extern NJS_COLOR saru_ears_uvs0[30];
extern NJS_COLOR saru_ears_uvs1[42];
extern NJS_MESHSET saru_ears_meshsets[2];
extern NJS_POINT3 saru_ears_points[16];
extern NJS_VECTOR saru_ears_normals[16];
extern NJS_MODEL saru_ears_model;
extern NJS_OBJECT saru_ears;
extern NJS_MATERIAL saru_head_materials[4];
extern Sint16 saru_head_meshes0[36];
extern Sint16 saru_head_meshes1[48];
extern Sint16 saru_head_meshes2[12];
extern Sint16 saru_head_meshes3[18];
extern Sint16 saru_head_meshes4[18];
extern NJS_COLOR saru_head_uvs0[36];
extern NJS_COLOR saru_head_uvs1[48];
extern NJS_COLOR saru_head_uvs2[12];
extern NJS_COLOR saru_head_uvs3[18];
extern NJS_COLOR saru_head_uvs4[18];
extern NJS_MESHSET saru_head_meshsets[5];
extern NJS_POINT3 saru_head_points[28];
extern NJS_VECTOR saru_head_normals[28];
extern NJS_MODEL saru_head_model;
extern NJS_OBJECT saru_head;
extern NJS_OBJECT saru_head_tip;
extern NJS_OBJECT saru_head_bone;
extern NJS_OBJECT saru_neck;
extern NJS_MATERIAL saru_body_materials[3];
extern Sint16 saru_body_meshes0[15];
extern Sint16 saru_body_meshes1[20];
extern Sint16 saru_body_meshes2[15];
extern NJS_COLOR saru_body_uvs0[15];
extern NJS_COLOR saru_body_uvs1[20];
extern NJS_COLOR saru_body_uvs2[15];
extern NJS_MESHSET saru_body_meshsets[3];
extern NJS_POINT3 saru_body_points[12];
extern NJS_VECTOR saru_body_normals[12];
extern NJS_MODEL saru_body_model;
extern NJS_OBJECT saru_body;
extern NJS_OBJECT saru_spine_tip;
extern NJS_OBJECT saru_spine;
extern NJS_OBJECT saru_object;
extern NJS_MATERIAL saru_body_prism_materials[1];
extern Sint16 saru_body_prism_meshes0[4];
extern Sint16 saru_body_prism_meshes1[12];
extern NJS_COLOR saru_body_prism_uvs0[3];
extern NJS_COLOR saru_body_prism_uvs1[12];
extern NJS_MESHSET saru_body_prism_meshsets[2];
extern NJS_POINT3 saru_body_prism_points[6];
extern NJS_VECTOR saru_body_prism_normals[6];
extern NJS_MODEL saru_body_prism_model;
extern NJS_OBJECT saru_body_prism;
extern NJS_MATERIAL saru_arm_prism_materials[2];
extern Sint16 saru_arm_prism_meshes0[12];
extern Sint16 saru_arm_prism_meshes1[4];
extern NJS_COLOR saru_arm_prism_uvs0[12];
extern NJS_MESHSET saru_arm_prism_meshsets[2];
extern NJS_POINT3 saru_arm_prism_points[6];
extern NJS_VECTOR saru_arm_prism_normals[6];
extern NJS_MODEL saru_arm_prism_model;
extern NJS_OBJECT saru_arm_prism;
extern NJS_MKEY_F saru_jump_pos0[16];
extern NJS_MKEY_A saru_jump_ang1[16];
extern NJS_MKEY_A saru_jump_ang5[16];
extern NJS_MKEY_A saru_jump_ang10[16];
extern NJS_MKEY_A saru_jump_ang11[16];
extern NJS_MKEY_A saru_jump_ang14[16];
extern NJS_MKEY_A saru_jump_ang17[16];
extern NJS_MKEY_A saru_jump_ang18[16];
extern NJS_MKEY_A saru_jump_ang21[16];
extern NJS_MKEY_A saru_jump_ang24[16];
extern NJS_MKEY_A saru_jump_ang25[16];
extern NJS_MKEY_A saru_jump_ang28[16];
extern NJS_MKEY_A saru_jump_ang31[16];
extern NJS_MKEY_A saru_jump_ang32[16];
extern NJS_MKEY_A saru_jump_ang35[16];
extern NJS_MDATA2 saru_jump_mdata[38];
extern NJS_MOTION saru_jump_motion;
extern NJS_ACTION action_saru_robo_grad1_chn2;
extern NJS_MKEY_F saru_flip_pos0[16];
extern NJS_MKEY_A saru_flip_ang1[16];
extern NJS_MKEY_A saru_flip_ang5[16];
extern NJS_MKEY_A saru_flip_ang10[16];
extern NJS_MKEY_A saru_flip_ang11[16];
extern NJS_MKEY_A saru_flip_ang17[16];
extern NJS_MKEY_A saru_flip_ang18[16];
extern NJS_MKEY_A saru_flip_ang24[16];
extern NJS_MKEY_A saru_flip_ang25[16];
extern NJS_MKEY_A saru_flip_ang28[16];
extern NJS_MKEY_A saru_flip_ang31[16];
extern NJS_MKEY_A saru_flip_ang32[16];
extern NJS_MKEY_A saru_flip_ang35[16];
extern NJS_MDATA2 saru_flip_mdata[38];
extern NJS_MOTION saru_flip_motion;
extern NJS_ACTION saru_flip_action;
extern NJS_MKEY_F saru_walk_pos0[16];
extern NJS_MKEY_A saru_walk_ang1[16];
extern NJS_MKEY_A saru_walk_ang5[16];
extern NJS_MKEY_A saru_walk_ang10[16];
extern NJS_MKEY_A saru_walk_ang11[16];
extern NJS_MKEY_A saru_walk_ang14[16];
extern NJS_MKEY_A saru_walk_ang17[16];
extern NJS_MKEY_A saru_walk_ang18[16];
extern NJS_MKEY_A saru_walk_ang21[16];
extern NJS_MKEY_A saru_walk_ang24[16];
extern NJS_MKEY_A saru_walk_ang25[16];
extern NJS_MKEY_A saru_walk_ang28[16];
extern NJS_MKEY_A saru_walk_ang31[16];
extern NJS_MKEY_A saru_walk_ang32[16];
extern NJS_MKEY_A saru_walk_ang35[16];
extern NJS_MDATA2 saru_walk_mdata[38];
extern NJS_MOTION saru_walk_motion;
extern NJS_ACTION action_saru_robo_move_chn2;
extern NJS_MKEY_F saru_throw_pos0[11];
extern NJS_MKEY_A saru_throw_ang1[13];
extern NJS_MKEY_A saru_throw_ang5[13];
extern NJS_MKEY_A saru_throw_ang10[13];
extern NJS_MKEY_A saru_throw_ang11[13];
extern NJS_MKEY_A saru_throw_ang14[13];
extern NJS_MKEY_A saru_throw_ang17[13];
extern NJS_MKEY_A saru_throw_ang18[13];
extern NJS_MKEY_A saru_throw_ang21[13];
extern NJS_MKEY_A saru_throw_ang24[13];
extern NJS_MKEY_A saru_throw_ang25[13];
extern NJS_MKEY_A saru_throw_ang28[9];
extern NJS_MKEY_A saru_throw_ang31[13];
extern NJS_MKEY_A saru_throw_ang32[13];
extern NJS_MKEY_A saru_throw_ang35[13];
extern NJS_MDATA2 saru_throw_mdata[38];
extern NJS_MOTION saru_throw_motion;
extern NJS_ACTION action_saru_robo_grad2_chn2;
extern NJS_MKEY_F saru_hop_pos0[16];
extern NJS_MKEY_A saru_hop_ang1[16];
extern NJS_MKEY_A saru_hop_ang5[16];
extern NJS_MKEY_A saru_hop_ang10[16];
extern NJS_MKEY_A saru_hop_ang11[16];
extern NJS_MKEY_A saru_hop_ang17[16];
extern NJS_MKEY_A saru_hop_ang18[16];
extern NJS_MKEY_A saru_hop_ang24[16];
extern NJS_MKEY_A saru_hop_ang25[16];
extern NJS_MKEY_A saru_hop_ang28[16];
extern NJS_MKEY_A saru_hop_ang31[16];
extern NJS_MKEY_A saru_hop_ang32[16];
extern NJS_MKEY_A saru_hop_ang35[16];
extern NJS_MDATA2 saru_hop_mdata[38];
extern NJS_MOTION saru_hop_motion;
extern NJS_ACTION action_saru_robo_wait_chn2;
extern NJS_MKEY_F saru_fidget_pos0[2];
extern NJS_MKEY_A saru_fidget_ang0[2];
extern NJS_MKEY_F saru_fidget_pos1[2];
extern NJS_MKEY_A saru_fidget_ang1[2];
extern NJS_MKEY_F saru_fidget_pos2[2];
extern NJS_MKEY_F saru_fidget_pos3[2];
extern NJS_MKEY_F saru_fidget_pos4[2];
extern NJS_MKEY_A saru_fidget_ang4[2];
extern NJS_MKEY_F saru_fidget_pos5[2];
extern NJS_MKEY_A saru_fidget_ang5[7];
extern NJS_MKEY_F saru_fidget_pos6[2];
extern NJS_MKEY_F saru_fidget_pos8[2];
extern NJS_MKEY_F saru_fidget_pos9[2];
extern NJS_MKEY_A saru_fidget_ang9[2];
extern NJS_MKEY_F saru_fidget_pos10[2];
extern NJS_MKEY_A saru_fidget_ang10[2];
extern NJS_MKEY_F saru_fidget_pos11[2];
extern NJS_MKEY_A saru_fidget_ang11[7];
extern NJS_MKEY_F saru_fidget_pos12[2];
extern NJS_MKEY_F saru_fidget_pos13[2];
extern NJS_MKEY_A saru_fidget_ang13[2];
extern NJS_MKEY_F saru_fidget_pos14[2];
extern NJS_MKEY_A saru_fidget_ang14[7];
extern NJS_MKEY_F saru_fidget_pos15[2];
extern NJS_MKEY_F saru_fidget_pos16[2];
extern NJS_MKEY_A saru_fidget_ang16[2];
extern NJS_MKEY_F saru_fidget_pos17[2];
extern NJS_MKEY_A saru_fidget_ang17[2];
extern NJS_MKEY_F saru_fidget_pos18[2];
extern NJS_MKEY_A saru_fidget_ang18[2];
extern NJS_MKEY_F saru_fidget_pos19[2];
extern NJS_MKEY_F saru_fidget_pos20[2];
extern NJS_MKEY_A saru_fidget_ang20[2];
extern NJS_MKEY_F saru_fidget_pos21[2];
extern NJS_MKEY_A saru_fidget_ang21[2];
extern NJS_MKEY_F saru_fidget_pos22[2];
extern NJS_MKEY_F saru_fidget_pos23[2];
extern NJS_MKEY_A saru_fidget_ang23[2];
extern NJS_MKEY_F saru_fidget_pos24[2];
extern NJS_MKEY_A saru_fidget_ang24[2];
extern NJS_MKEY_F saru_fidget_pos25[2];
extern NJS_MKEY_A saru_fidget_ang25[2];
extern NJS_MKEY_F saru_fidget_pos26[2];
extern NJS_MKEY_A saru_fidget_ang26[2];
extern NJS_MKEY_F saru_fidget_pos27[2];
extern NJS_MKEY_A saru_fidget_ang27[2];
extern NJS_MKEY_F saru_fidget_pos28[2];
extern NJS_MKEY_A saru_fidget_ang28[2];
extern NJS_MKEY_F saru_fidget_pos29[2];
extern NJS_MKEY_A saru_fidget_ang29[2];
extern NJS_MKEY_F saru_fidget_pos30[2];
extern NJS_MKEY_A saru_fidget_ang30[2];
extern NJS_MKEY_F saru_fidget_pos31[2];
extern NJS_MKEY_A saru_fidget_ang31[2];
extern NJS_MKEY_F saru_fidget_pos32[2];
extern NJS_MKEY_A saru_fidget_ang32[2];
extern NJS_MKEY_F saru_fidget_pos33[2];
extern NJS_MKEY_A saru_fidget_ang33[2];
extern NJS_MKEY_F saru_fidget_pos34[2];
extern NJS_MKEY_A saru_fidget_ang34[2];
extern NJS_MKEY_F saru_fidget_pos35[2];
extern NJS_MKEY_A saru_fidget_ang35[2];
extern NJS_MKEY_F saru_fidget_pos36[2];
extern NJS_MKEY_A saru_fidget_ang36[2];
extern NJS_MKEY_F saru_fidget_pos37[2];
extern NJS_MKEY_A saru_fidget_ang37[2];
extern NJS_MDATA2 saru_fidget_mdata[38];
extern NJS_MOTION saru_fidget_motion;
extern NJS_ACTION saru_fidget_action;
extern NJS_TEXNAME e_bomb_textures[2];
extern NJS_TEXLIST e_bomb_texlist;
extern NJS_MATERIAL saru_bomb_fuse_materials[1];
extern Sint16 saru_bomb_fuse_meshes0[4];
extern Sint16 saru_bomb_fuse_meshes1[24];
extern NJS_COLOR saru_bomb_fuse_uvs0[3];
extern NJS_COLOR saru_bomb_fuse_uvs1[24];
extern NJS_MESHSET saru_bomb_fuse_meshsets[2];
extern NJS_POINT3 saru_bomb_fuse_points[9];
extern NJS_VECTOR saru_bomb_fuse_normals[9];
extern NJS_MODEL ssGameMode;
extern NJS_OBJECT saru_bomb_fuse;
extern NJS_MATERIAL saru_bomb_materials[1];
extern Sint16 saru_bomb_meshes0[34];
extern Sint16 saru_bomb_meshes1[64];
extern NJS_COLOR saru_bomb_uvs0[28];
extern NJS_COLOR saru_bomb_uvs1[64];
extern NJS_MESHSET saru_bomb_meshsets[2];
extern NJS_POINT3 saru_bomb_points[29];
extern NJS_VECTOR saru_bomb_normals[29];
extern NJS_MODEL saru_bomb_model;
extern NJS_OBJECT saru_bomb;
extern NJS_TEXNAME togeball_textures[2];
extern NJS_TEXLIST CreateSpark;
extern NJS_MATERIAL togeball_spikes_materials[1];
extern Sint16 togeball_spikes_meshes[126];
extern NJS_COLOR togeball_spikes_uvs[105];
extern NJS_MESHSET togeball_spikes_meshsets[1];
extern NJS_POINT3 togeball_spikes_points[84];
extern NJS_VECTOR togeball_spikes_normals[84];
extern NJS_MODEL togeball_spikes_model;
extern NJS_OBJECT togeball_spikes;
extern NJS_MATERIAL togeball_materials[1];
extern Sint16 togeball_meshes[35];
extern NJS_COLOR togeball_uvs[30];
extern NJS_MESHSET togeball_meshsets[1];
extern NJS_POINT3 togeball_points[12];
extern NJS_VECTOR togeball_normals[12];
extern NJS_MODEL togeball_model;
extern NJS_OBJECT togeball_object;
extern struct collision_shape saru_shape;
extern struct collision_shape saru_bomb_shapes[4];
extern NJS_MODEL *saru_pieces[];
extern struct dust_params saru_dust;
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c0fae8a(struct task_work *work, struct lockon_target *record)
{
    record->motion.speed.y += record->motion.accel.y - 0.06F;
    ((&work->pos)->x += (&record->motion.speed)->x, (&work->pos)->y += (&record->motion.speed)->y, (&work->pos)->z += (&record->motion.speed)->z);
    ((&record->motion.accel)->x = 0.0F, (&record->motion.accel)->y = 0.0F, (&record->motion.accel)->z = 0.0F);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0faeda(struct task *task)
{
    struct task_work *work = task->work;
    switch (work->mode) {
    case BLAST_INIT:
        work->timer = 60;
        ((struct blast_vars *)&(work)->vars)->scroll = 0;
        ((struct blast_vars *)&(work)->vars)->growth = 4.0F;
        work->scl.x = 2.0F;
        work->scl.z = 1.0F;
        FUN_8c09efc0();
        work->mode = BLAST_GROW;
        break;
    case BLAST_GROW:
        if (--(*(Uint16 *)&(work)->timer) == 0) {
            work->mode = BLAST_END;
            break;
        }
        if ((*(Uint16 *)&(work)->timer) < 60 / 2) {
            work->scl.z -= 0.033F;
        }
        ((struct blast_vars *)&(work)->vars)->growth += 0.1F;
        ((struct blast_vars *)&(work)->vars)->growth *= 0.8F;
        work->scl.x += ((struct blast_vars *)&(work)->vars)->growth;
        ((struct blast_vars *)&(work)->vars)->scroll += 10;
        break;
    case BLAST_END:
        FreeTask(task);
        return;
    }
    njPushMatrix(((void *)0));
    FUN_8c09f134(((struct blast_vars *)&(work)->vars)->scroll);
    FUN_8c09f1e0(work->scl.z);
    FUN_8c09f29a(work->scl.z);
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    njScale(((void *)0), work->scl.x, work->scl.x, work->scl.x);
    njSetTexture(&FUN_8c09f134);
    FUN_8c09f1e0();
    njPopMatrix(1);
    EntryColliList(work);
}
#else
void FUN_8c0faeda(struct task *task)
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
    asm_stub[0] = 64; asm_stub[1] = 65; asm_stub[2] = 66; asm_stub[3] = 67;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0fb034(struct task_work *work, struct lockon_target *record)
{
    NJS_POINT3 offset = {1.0F, -2.0F, 0.0F};
    NJS_POINT3 pos;
    NJS_VECTOR speed = {0.5F, 0.0F, 0.0F};
    NJS_VECTOR out;
    Angle ang;
    int i;
    for (i = 0, ang = 0; i < 8; i++, ang += 0x2000) {
        njPushMatrix(&nj_unit_matrix_);
        ((ang) ? (njRotateY)(((void *)0), (ang)) : (void)0);
        njCalcVector(((void *)0), &speed, &out);
        njCalcPoint(((void *)0), &offset, &pos);
        njPopMatrix(1);
        saru_dust.speed = out;
        njAddVector(&pos, &work->pos);
        saru_dust.pos = pos;
        CreateSmoke2(&saru_dust);
    }
}
#else
void FUN_8c0fb034(struct task_work *work, struct lockon_target *record)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void CreateSaruBombExplosion(NJS_POINT3 *pos)
{
    struct task *task = CreateElementalTask(0x2, 5, FUN_8c0faeda);
    if (task != ((void *)0)) {
        struct task_work *work = task->work;
        work->pos = *pos;
    }
}
#else
void CreateSaruBombExplosion(NJS_POINT3 *pos)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruBombDraw(struct task_work *work, struct lockon_target *record)
{
    Float scale_x = work->scl.x;
    Float scale_y = work->scl.y;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    enemy_spring_scale(work, record);
    if (record->flags & 0x10) {
        if (work->submode == SARU_BOMB) {
            if (((Float)_builtin_fabsf((Float)(record->motion.speed.y))) > 0.3F) {
                record->scale_speed = 0.4F;
                FUN_8c0fb034(work, record);
            }
        } else {
            { (((record))->last_mode = ((work))->mode, ((work))->mode = (BOMB_BLAST), ((work))->timer = 0); (work)->scl.x = 5.0F; (work)->scl.y = 0.0F; CreateFlash2((work)->pos.x, (work)->pos.y + 3.0F, (work)->pos.z, 4.0F); (work)->collision->shapes[1].flags &= ~0x10; (work)->collision->shapes[0].flags |= 0x10; CreateSaruBombExplosion(&(work)->pos); };
        }
    }
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    if (work->submode == SARU_BOMB) {
        njSetTexture(&e_bomb_texlist);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        njScale(((void *)0), scale_x, scale_y, scale_x);
        draw_model(&saru_bomb_model);
        njTranslate(((void *)0), 0.0F, 2.3F, 0.0F);
        njScale(((void *)0), 1.0F, ((record)->motion.slip) * 1.25F, 1.0F);
        draw_model(&ssGameMode);
        njPopMatrix(1);
        ((record)->motion.slip) -= 0.003F;
        pos.x = work->pos.x;
        pos.y = work->pos.y + (((record)->motion.slip) * 2.5F) + 2.3F;
        pos.z = work->pos.z;
        speed.x = (0.5F - (rand() * (1.0F / (32767 + 1)))) * 1.2F;
        speed.y = ((rand() * (1.0F / (32767 + 1))) + 0.2F) * 0.9F;
        speed.z = (0.5F - (rand() * (1.0F / (32767 + 1)))) * 1.2F;
        spark_create(&pos, &speed, 0.6F);
    } else {
        njSetTexture(&CreateSpark);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        njScale(((void *)0), scale_x, scale_y, scale_x);
        late_DrawObject(&togeball_object);
        njPopMatrix(1);
    }
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
#else
void SaruBombDraw(struct task_work *work, struct lockon_target *record)
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
    asm_stub[0] = 104; asm_stub[1] = 105; asm_stub[2] = 106; asm_stub[3] = 107; asm_stub[4] = 108; asm_stub[5] = 109; asm_stub[6] = 110; asm_stub[7] = 111;
    asm_stub[0] = 112; asm_stub[1] = 113; asm_stub[2] = 114; asm_stub[3] = 115; asm_stub[4] = 116; asm_stub[5] = 117; asm_stub[6] = 118; asm_stub[7] = 119;
    asm_stub[0] = 120; asm_stub[1] = 121; asm_stub[2] = 122; asm_stub[3] = 123; asm_stub[4] = 124; asm_stub[5] = 125; asm_stub[6] = 126; asm_stub[7] = 127;
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruBombCollision(struct task_work *work,
                            struct lockon_target *record)
{
    struct collision_work *collision = work->collision;
    int flags = work->flags;
    int kind;
    if (((flags & 0x1) && work->submode == SARU_TOGEBALL) ||
        ((flags & 0x8) && work->submode == SARU_TOGEBALL) ||
        (flags & 0x4)) {
        { (((record))->last_mode = ((work))->mode, ((work))->mode = (BOMB_BLAST), ((work))->timer = 0); (work)->scl.x = 5.0F; (work)->scl.y = 0.0F; CreateFlash2((work)->pos.x, (work)->pos.y + 3.0F, (work)->pos.z, 4.0F); (work)->collision->shapes[1].flags &= ~0x10; (work)->collision->shapes[0].flags |= 0x10; CreateSaruBombExplosion(&(work)->pos); };
    }
    flags = work->flags;
    if ((flags & 0x800) && (flags & 0x8)) {
        kind = collision->hit->kind;
        if (kind == 2 || kind == 3) {
            { (((record))->last_mode = ((work))->mode, ((work))->mode = (BOMB_BLAST), ((work))->timer = 0); (work)->scl.x = 5.0F; (work)->scl.y = 0.0F; CreateFlash2((work)->pos.x, (work)->pos.y + 3.0F, (work)->pos.z, 4.0F); (work)->collision->shapes[1].flags &= ~0x10; (work)->collision->shapes[0].flags |= 0x10; CreateSaruBombExplosion(&(work)->pos); };
        }
    }
}
#else
void SaruBombCollision(struct task_work *work,
                            struct lockon_target *record)
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
    asm_stub[0] = 64; asm_stub[1] = 65; asm_stub[2] = 66; asm_stub[3] = 67; asm_stub[4] = 68; asm_stub[5] = 69; asm_stub[6] = 70;
}
#endif
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void SaruBombNormal(struct task_work *work, struct lockon_target *record)
{
    if ((*(Uint16 *)&(work)->timer) > 20) {
        SaruBombCollision(work, record);
    }
    FUN_8c0fae8a(work, record);
    EnemyCheckGroundCollision(work, record);
    SaruBombDraw(work, record);
    if ((*(Uint16 *)&(work)->timer) > 120) {
        ((record)->last_mode = (work)->mode, (work)->mode = (BOMB_LIE), (work)->timer = 0);
        work->submode = 15;
    }
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruBombCountDraw(struct task_work *work,
                                 struct lockon_target *record)
{
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    njSetTexture(&e_bomb_texlist);
    if (work->tick > work->submode) {
        work->tick = 0;
        if (work->submode > 0) {
            work->submode--;
        }
        SetMaterial(0.5F, 2.0F, -2.0F, -2.0F);
    } else {
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        draw_model(&saru_bomb_model);
        njTranslate(((void *)0), 0.0F, 2.3F, 0.0F);
        njScale(((void *)0), 1.0F, ((record)->motion.slip) * 1.25F, 1.0F);
        draw_model(&ssGameMode);
        njPopMatrix(1);
    }
    ((record)->motion.slip) -= 0.003F;
    if (((record)->motion.slip) < 0.0F) {
        ((record)->motion.slip) = 0.0F;
    }
    pos.x = work->pos.x;
    pos.y = work->pos.y + (((record)->motion.slip) * 2.5F) + 2.3F;
    pos.z = work->pos.z;
    speed.x = (0.5F - (rand() * (1.0F / (32767 + 1)))) * 1.2F;
    speed.y = ((rand() * (1.0F / (32767 + 1))) + 0.2F) * 0.9F;
    speed.z = (0.5F - (rand() * (1.0F / (32767 + 1)))) * 1.2F;
    spark_create(&pos, &speed, 0.6F);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
#else
void SaruBombCountDraw(struct task_work *work,
                                 struct lockon_target *record)
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
    asm_stub[0] = 80; asm_stub[1] = 81; asm_stub[2] = 82; asm_stub[3] = 83; asm_stub[4] = 84;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruBombCountDown(struct task_work *work, struct lockon_target *record)
{
    SaruBombCollision(work, record);
    if (njScalor(&record->motion.speed) >= 0.05F ||
        !(record->flags & 0x10)) {
        if (!(work->flags & 0x1000)) {
            FUN_8c0fae8a(work, record);
            EnemyCheckGroundCollision(work, record);
        }
    }
    SaruBombCountDraw(work, record);
    if ((*(Uint16 *)&(work)->timer) > 150) {
        { (((record))->last_mode = ((work))->mode, ((work))->mode = (BOMB_BLAST), ((work))->timer = 0); (work)->scl.x = 5.0F; (work)->scl.y = 0.0F; CreateFlash2((work)->pos.x, (work)->pos.y + 3.0F, (work)->pos.z, 4.0F); (work)->collision->shapes[1].flags &= ~0x10; (work)->collision->shapes[0].flags |= 0x10; CreateSaruBombExplosion(&(work)->pos); };
    }
}
#else
void SaruBombCountDown(struct task_work *work, struct lockon_target *record)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void saru_bomb_blast(struct task_work *work,
                            struct lockon_target *record)
{
    struct collision_shape *shape = &work->collision->shapes[1];
    if ((*(Uint16 *)&(work)->timer) % 2) {
        SetMaterial(work->scl.y, 1.0F, 0.0F, 0.0F);
    } else {
        SetMaterial(work->scl.y, 0.5F, 0.5F, 0.0F);
    }
    if (work->scl.x < 25.0F) {
        work->scl.x += 1.0F;
        shape->radius += 1.0F;
    } else {
        work->scl.y -= 0.05F;
        if (work->scl.y < -1.0F) {
            ((record)->last_mode = (work)->mode, (work)->mode = (BOMB_END), (work)->timer = 0);
        }
    }
    work->ang.y += 0x100;
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
#else
void saru_bomb_blast(struct task_work *work,
                            struct lockon_target *record)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void saru_bomb_destroy(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    enemy_end(task, work, record);
}
#else
void saru_bomb_destroy(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruBombAExecutor(struct task *task)
{
    register struct task_work *work = task->work;
    register struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    if (edit_mode == 0) {
        switch (work->mode) {
        case BOMB_FLY:
            SaruBombNormal(work, record);
            break;
        case BOMB_LIE:
            SaruBombCountDown(work, record);
            break;
        case BOMB_BLAST:
            saru_bomb_blast(work, record);
            if (work->collision->hit != ((void *)0)) {
                if (work->collision->hit->kind == 0) {
                    task->parent->work->flags |= 0x400 | 0x800;
                    ((struct saru_vars *)&(task->parent->work)->vars)->since_hit = 0;
                }
            }
            break;
        case BOMB_END:
            enemy_end(task, work, record);
            FreeTask(task);
            break;
        default:
            break;
        }
        enemy_save_pos(work, record);
        if (!(work->flags & 0x1000)) {
            EntryColliList(work);
            work->timer++;
            work->tick++;
        } else {
            work->flags |= 0x800;
        }
    }
}
#else
void SaruBombAExecutor(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56; asm_stub[1] = 57;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruBombA(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record;
    NJS_VECTOR speed;
    CCL_Init(task, saru_bomb_shapes, 3, 1, 3);
    task->work->collision->flags &= ~0x800;
    if (work->submode == SARU_BOMB) {
        task->work->collision->shapes[0].flags &= ~0x10;
    }
    task->work->collision->radius = 40.0F;
    record = EnemyInitialize(task, work);
    record->flags |= 0x2;
    speed.x = njSqrt(EnemyDist2FromPlayer(work, 0)) * 0.013F;
    speed.y = 2.0F;
    speed.z = 0.0F;
    if (speed.x > 1.2F) {
        speed.x = 1.2F;
    }
    carry_set_kind(work, task->motion, CARRY_KIND_SMALL);
    work->flags &= ~0x800;
    njPushMatrix(&nj_unit_matrix_);
    ((work->ang.x + work->ang.y) ? (njRotateY)(((void *)0), (work->ang.x + work->ang.y)) : (void)0);
    njCalcVector(((void *)0), &speed, &record->motion.speed);
    njPopMatrix(1);
    work->scl.x = 1.0F;
    work->scl.y = 1.0F;
    work->scl.z = 0.0F;
    work->tick = 0;
    work->timer = 0;
    ((record)->motion.slip) = 0.0F;
    record->turn_speed = 0xe0;
    work->ang.x = (Angle)(rand() * (1.0F / (32767 + 1)) * 360.0F * (65536.0F / 360.0F));
    work->ang.z = (Angle)(rand() * (1.0F / (32767 + 1)) * 360.0F * (65536.0F / 360.0F));
    record->aim_y = work->ang.y;
    record->frame = 0.0F;
    ((&record->probe_offset)->x = 0.0F, (&record->probe_offset)->y = 0.0F, (&record->probe_offset)->z = 0.0F);
    record->top = 3.0F;
    record->radius = 3.0F;
    record->bottom = -3.0F;
    record->wall_bounce = 0.7F;
    record->floor_bounce = 0.68F;
    record->friction = 0.5F;
    record->unk_c4 = 0.7F;
    record->shadow_size = 0.7F;
    record->shadow_ratio = 1.0F;
    ((record)->motion.slip) = 1.0F;
    Knuckles_KakeraGame_Set_CheckEme(work, record);
    task->destructor = saru_bomb_destroy;
    task->step = SaruBombAExecutor;
}
#else
void SaruBombA(struct task *task)
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
    asm_stub[0] = 104; asm_stub[1] = 105; asm_stub[2] = 106;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruBombADisplayer(struct task *task)
{
}
#else
void SaruBombADisplayer(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void SaruTraceCircle(struct task_work *work, struct lockon_target *record)
{
    NJS_POINT3 offset;
    offset.x = work->scl.z;
    offset.y = work->pos.y;
    offset.z = 0.0F;
    njPushMatrix(&nj_unit_matrix_);
    ((work->ang.x) ? (njRotateY)(((void *)0), (work->ang.x)) : (void)0);
    njCalcPoint(((void *)0), &offset, &work->pos);
    njPopMatrix(1);
    work->pos.x += record->home.x;
    work->pos.z += record->home.z;
}
void FUN_8c0fbd1c(struct task_work *work, struct lockon_target *record)
{
    if (work->flags & 0x2000) {
        work->pos.y = shadow_draw(work, 1.0F) + 4.0F;
    }
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0fbd44(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record;
    CCL_Init(task, &saru_shape, 3, 1, 1);
    record = EnemyInitialize(task, work);
    Knuckles_KakeraGame_Set_CheckEme(work, record);
    record->flags |= 0x1 | 0x2;
    record->flags &= ~0x200;
    work->tick = rand() * (1.0F / (32767 + 1)) * 20.0F;
    work->timer = 0;
    record->motion.slip = 0.0F;
    record->turn_speed = 0xe0;
    record->aim_y = work->ang.y;
    record->frame = 3.0F;
    record->next_frame = 0.0F;
    record->action = &action_saru_robo_wait_chn2;
    record->next_action = record->action;
    record->shadow_size = 1.6F;
    record->shadow_ratio = 1.0F;
    record->motion.gravity = 0.1F;
    ((record)->unk_7c) = 0.0F;
    record->scale_speed = 0.0F;
    if (work->scl.z <= 1.0F) {
        work->scl.z = 1.0F;
    }
    if (work->scl.x >= 0.0F) {
        work->flags &= ~0x2000;
    } else {
        work->flags |= 0x2000;
    }
    if (work->scl.y >= 0.0F) {
        work->submode = SARU_BOMB;
        if (work->scl.y >= 1000.0F) {
            work->submode = SARU_UNARMED;
        }
    } else {
        work->submode = SARU_TOGEBALL;
    }
    work->scl.x = 1.0F;
    work->scl.y = 1.0F;
    ((record)->unk_4c) = (Uint8)work->ang.z;
    ((work)->ang.z) = (work->ang.z & 0xff00) >> 8;
    SaruTraceCircle(work, record);
    task->destructor = FUN_8c0fca7c;
    task->step = saru_step;
    task->draw = saru_draw;
    work->flags |= 0x100;
    work->flags &= ~(0x200 | 0x400 | 0x800);
    knuckles_find_piece(((record)->unk_4c), &work->pos);
}
#else
void FUN_8c0fbd44(struct task *task)
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
    asm_stub[0] = 80; asm_stub[1] = 81; asm_stub[2] = 82; asm_stub[3] = 83; asm_stub[4] = 84;
}
#endif
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void saru_take_hit(struct task_work *work, struct lockon_target *record)
{
    struct collision_work *collision;
    enemy_ignore((void *)playertwp);
    (void)work->collision->hit_shape;
    collision = work->collision;
    enemy_ignore(collision->hit);
    if (!(collision->flags & 0x2)) {
        return;
    }
    if (!enemy_take_hit(work, record)) {
        return;
    }
    work->mode = SARU_BREAK;
    ((work)->vars.b[1] = 0, (work)->vars.b[2] = 1);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void saru_draw(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    Float scale_x = work->scl.x * 1.2F;
    Float scale_y = work->scl.y * 1.2F;
    if (record == ((void *)0)) {
        return;
    }
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    njSetTexture(&e_saru_texlist);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.x + work->ang.y) ? (njRotateY)(((void *)0), (work->ang.x + work->ang.y)) : (void)0);
    njScale(((void *)0), scale_x, scale_y, scale_x);
    njRotateY(((void *)0), 0x8000);
    if (record->flags & 0x200) {
        NJS_MOTION_LINK link;
        NJS_ACTION_LINK action;
        action.motionlink = &link;
        action.object = record->action->object;
        link.motion[0] = record->action->motion;
        link.motion[1] = record->next_action->motion;
        link.frame[0] = record->frame;
        link.frame[1] = record->next_frame;
        ___dsActionLink(&action, record->blend);
    } else {
        ds_ActionClip(record->action, record->frame);
    }
    njPopMatrix(1);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruDraw(struct task_work *work,
                               struct lockon_target *record)
{
    Float scale_x = work->scl.x * 1.2F;
    Float scale_y = work->scl.y * 1.2F;
    if (!dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        return;
    }
    FUN_8c0fbd1c(work, record);
    enemy_spring_scale(work, record);
    njSetTexture(&e_saru_texlist);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.x + work->ang.y) ? (njRotateY)(((void *)0), (work->ang.x + work->ang.y)) : (void)0);
    njScale(((void *)0), scale_x, scale_y, scale_x);
    njRotateY(((void *)0), 0x8000);
    do { if ((record)->flags & 0x200) { NJS_MOTION_LINK link; NJS_ACTION_LINK action; action.motionlink = &link; action.object = (record)->action->object; link.motion[0] = (record)->action->motion; link.motion[1] = (record)->next_action->motion; link.frame[0] = (record)->frame; link.frame[1] = (record)->next_frame; ___dsActionLink(&action, (record)->blend); do { (record)->blend += (record)->blend_speed; if ((record)->blend > 1.0F) { (record)->blend = 0.0F; (record)->frame = (record)->next_frame; (record)->action = (record)->next_action; (record)->flags &= ~0x200; } } while (0); } else { ds_ActionClip((record)->action, (record)->frame); } } while (0);
    njPopMatrix(1);
}
#else
void SaruDraw(struct task_work *work,
                               struct lockon_target *record)
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
    asm_stub[0] = 80; asm_stub[1] = 81;
}
#endif
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void SaruDrawLow(struct task_work *work,
                              struct lockon_target *record)
{
    Float scale_x = work->scl.x * 1.2F;
    Float scale_y = work->scl.y * 1.2F;
    FUN_8c0fbd1c(work, record);
    enemy_spring_scale(work, record);
    njSetTexture(&e_saru_texlist);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    njTranslate(((void *)0), 0.0F, ((record)->unk_78) - 1.5F, 0.0F);
    ((work->ang.x + work->ang.y) ? (njRotateY)(((void *)0), (work->ang.x + work->ang.y)) : (void)0);
    njScale(((void *)0), scale_x, scale_y, scale_x);
    njRotateY(((void *)0), 0x8000);
    do { if ((record)->flags & 0x200) { NJS_MOTION_LINK link; NJS_ACTION_LINK action; action.motionlink = &link; action.object = (record)->action->object; link.motion[0] = (record)->action->motion; link.motion[1] = (record)->next_action->motion; link.frame[0] = (record)->frame; link.frame[1] = (record)->next_frame; ___dsActionLink(&action, (record)->blend); do { (record)->blend += (record)->blend_speed; if ((record)->blend > 1.0F) { (record)->blend = 0.0F; (record)->frame = (record)->next_frame; (record)->action = (record)->next_action; (record)->flags &= ~0x200; } } while (0); } else { ds_ActionClip((record)->action, (record)->frame); } } while (0);
    njPopMatrix(1);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void saru_draw_throwing(struct task *task, struct lockon_target *record)
{
    struct task_work *work = task->work;
    Float scale_x = work->scl.x * 1.2F;
    Float scale_y = work->scl.y * 1.2F;
    NJS_POINT3 hand;
    enemy_spring_scale(work, record);
    njSetTexture(&e_saru_texlist);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    {
        NJS_MATRIX matrix;
        NJS_POINT3 offset = {0.0F, 0.0F, 0.0F};
        njPushMatrix(&nj_unit_matrix_);
        njScale(((void *)0), scale_x, scale_y, scale_x);
        CalcMMMatrix(((void *)0), record->action, record->frame, 14, &matrix);
        njCalcPoint(&matrix, &offset, &hand);
        njPopMatrix(1);
    }
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.x + work->ang.y) ? (njRotateY)(((void *)0), (work->ang.x + work->ang.y)) : (void)0);
    if (record->flags & 0x200) {
        NJS_MOTION_LINK link;
        NJS_ACTION_LINK action;
        action.motionlink = &link;
        action.object = record->action->object;
        link.motion[0] = record->action->motion;
        link.motion[1] = record->next_action->motion;
        link.frame[0] = record->frame;
        link.frame[1] = record->next_frame;
        njScale(((void *)0), scale_x, scale_y, scale_x);
        njRotateY(((void *)0), 0x8000);
        ___dsActionLink(&action, record->blend);
        do { (record)->blend += (record)->blend_speed; if ((record)->blend > 1.0F) { (record)->blend = 0.0F; (record)->frame = (record)->next_frame; (record)->action = (record)->next_action; (record)->flags &= ~0x200; } } while (0);
    } else {
        njPushMatrix(((void *)0));
        njScale(((void *)0), scale_x, scale_y, scale_x);
        njRotateY(((void *)0), 0x8000);
        ds_ActionClip(record->action, record->frame);
        njPopMatrix(1);
        njRotateY(((void *)0), 0x8000);
        if (work->flags & 0x200) {
            Float scale;
            ((record)->unk_7c) += 0.1F;
            if (((record)->unk_7c) > 1.0F) {
                ((record)->unk_7c) = 1.0F;
            }
            scale = ((record)->unk_7c);
            njTranslateV(((void *)0), &hand);
            njTranslate(((void *)0), 0.0F, scale * 1.0F, 0.0F);
            njScale(((void *)0), scale, scale, scale);
            if (work->submode == SARU_BOMB) {
                njSetTexture(&e_bomb_texlist);
                late_DrawObject(&saru_bomb);
            } else {
                njSetTexture(&CreateSpark);
                late_DrawObject(&togeball_object);
            }
            if (record->frame > 9.5F) {
                struct task *bomb;
                NJS_POINT3 unused = {0.0F, 0.0F, 0.0F};
                work->flags &= ~0x200;
                ((record)->unk_7c) = 0.0F;
                bomb = CreateChildTask(0x2, SaruBombA, task);
                if (bomb != ((void *)0)) {
                    struct task_work *bomb_work = bomb->work;
                    bomb_work->submode = work->submode;
                    bomb_work->pos = work->pos;
                    bomb_work->ang = work->ang;
                }
            }
        }
    }
    njPopMatrix(1);
}
#else
void saru_draw_throwing(struct task *task, struct lockon_target *record)
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
    asm_stub[0] = 104; asm_stub[1] = 105; asm_stub[2] = 106; asm_stub[3] = 107; asm_stub[4] = 108; asm_stub[5] = 109; asm_stub[6] = 110; asm_stub[7] = 111;
    asm_stub[0] = 112; asm_stub[1] = 113; asm_stub[2] = 114; asm_stub[3] = 115; asm_stub[4] = 116; asm_stub[5] = 117; asm_stub[6] = 118; asm_stub[7] = 119;
    asm_stub[0] = 120; asm_stub[1] = 121; asm_stub[2] = 122; asm_stub[3] = 123; asm_stub[4] = 124; asm_stub[5] = 125; asm_stub[6] = 126; asm_stub[7] = 127;
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0fc6ac(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 radius;
    NJS_POINT3 from;
    NJS_POINT3 to;
    NJS_POINT3 pos;
    int i;
    if (OnEdit(task)) {
        if (work->tick > 25) {
            njPrintC(((8) << 16 | (8)), "< SARU >");
        } else {
            njPrintC(((8) << 16 | (8)), "<      >");
            njPrintC(((6) << 16 | (9)), "sclY >= 1000.0 DE BOMB NAGEMASEN");
        }
        if (work->tick++ > 50) {
            work->tick = 0;
        }
        njPrintC(((17) << 16 | (16)), "-> POSITION    ");
        njPrintC(((17) << 16 | (17)), "->             ");
        njPrintC(((17) << 16 | (18)), "-> 00STRONG FFWEAK&EME");
        njPrintC(((17) << 16 | (19)), "-> [+ NOCOLLI][- COLLI]");
        njPrintC(((17) << 16 | (20)), "-> [+ BOMB][- TOGE]");
        njPrintC(((17) << 16 | (21)), "-> RADIUS      ");
        radius.x = work->scl.z;
        radius.y = 0.0F;
        radius.z = 0.0F;
        for (i = 0; i < 32; i++) {
            njPushMatrix(&nj_unit_matrix_);
            njTranslateV(((void *)0), &work->pos);
            ((i * (0x10000 / 32)) ? (njRotateY)(((void *)0), (i * (0x10000 / 32))) : (void)0);
            njCalcPoint(((void *)0), &radius, &from);
            njPopMatrix(1);
            njPushMatrix(&nj_unit_matrix_);
            njTranslateV(((void *)0), &work->pos);
            (((i + 1) * (0x10000 / 32)) ? (njRotateY)(((void *)0), ((i + 1) * (0x10000 / 32))) : (void)0);
            njCalcPoint(((void *)0), &radius, &to);
            njPopMatrix(1);
            draw_line_v(&from, &to);
        }
        njPushMatrix(&nj_unit_matrix_);
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.x) ? (njRotateY)(((void *)0), (work->ang.x)) : (void)0);
        njCalcPoint(((void *)0), &radius, &pos);
        njPopMatrix(1);
        njSetTexture(&e_saru_texlist);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &pos);
        ((work->ang.x + work->ang.y) ? (njRotateY)(((void *)0), (work->ang.x + work->ang.y)) : (void)0);
        njRotateY(((void *)0), 0x8000);
        njScale(((void *)0), 1.2F, 1.2F, 1.2F);
        late_DrawObject(&saru_object);
        njPopMatrix(1);
    } else {
        struct lockon_target *record = ((struct lockon_target *)(task)->motion);
        SaruDraw(work, record);
    }
}
#else
void FUN_8c0fc6ac(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
}
#endif
void FUN_8c0fca7c(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    enemy_end(task, work, record);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void saru_break(struct task_work *work, struct lockon_target *record)
{
    CreateFlash2(work->pos.x, work->pos.y + 5.0F, work->pos.z, 1.4F);
    enemy_break(work, saru_pieces, &e_saru_texlist);
    enemy_scatter_debris(work, 8);
    animal_create_random(3, work->pos.x, work->pos.y + 15.0F, work->pos.z);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruDecideAimPos(struct task_work *work,
                                struct lockon_target *record)
{
    struct task_work *player = playertwp[0];
    NJS_VECTOR way;
    Float distance;
    Float range;
    way = player->pos;
    njSubVector(&way, &record->home);
    distance = (way.x * way.x) + (way.y * way.y) + (way.z * way.z);
    range = work->scl.z + 140.0F;
    if (distance > range * range) {
        record->heading =
            (Angle)(rand() * (1.0F / (32767 + 1)) * 360.0F * (65536.0F / 360.0F));
    } else {
        range = work->scl.z + 20.0F;
        if (distance > range * range) {
            record->heading = (Angle)(njArcTan2(player->pos.x - record->home.x,
                                             player->pos.z - record->home.z) *
                                      (65536.0 / (2 * 3.141592))) -
                              0x4000;
        } else {
            record->heading = (Angle)(njArcTan2(player->pos.x - record->home.x,
                                             player->pos.z - record->home.z) *
                                      (65536.0 / (2 * 3.141592))) +
                              0x4000;
        }
    }
}
#else
void SaruDecideAimPos(struct task_work *work,
                                struct lockon_target *record)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56; asm_stub[1] = 57;
}
#endif
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool SaruCheckInterrupt(struct task_work *work, struct lockon_target *record)
{
    Float distance = EnemyDist2FromPlayer(work, 0);
    NJS_ACTION *hop = &action_saru_robo_wait_chn2;
    int blending = 0x200;
    if (distance < 25.0F * 25.0F) {
        SaruDecideAimPos(work, record);
        if (rand() * (1.0F / (32767 + 1)) > 0.5F) {
            ((record)->last_mode = (work)->mode, (work)->mode = (SARU_TURN_ON), (work)->timer = 0);
        } else {
            ((record)->last_mode = (work)->mode, (work)->mode = (SARU_TURN_BACK), (work)->timer = 0);
        }
        record->flags |= blending;
        record->blend_speed = 0.5F;
        record->next_frame = 0.0F;
        record->next_action = hop;
        return (1);
    } else if (distance < 200.0F * 200.0F &&
               (*(Uint16 *)&(work)->timer) > (Uint16)((work)->ang.z)) {
        ((record)->last_mode = (work)->mode, (work)->mode = (SARU_FACE), (work)->timer = 0);
        record->flags |= blending;
        record->blend_speed = 0.1F;
        record->next_frame = 0.0F;
        record->next_action = hop;
    }
    if ((work->flags & 0x400) && (work->flags & 0x800)) {
        ((record)->last_mode = (work)->mode, (work)->mode = (SARU_FACE), (work)->timer = 0);
        record->flags |= blending;
        record->blend_speed = 0.1F;
        record->next_frame = 0.0F;
        record->next_action = hop;
        work->flags &= ~0x800;
        return (1);
    }
    return (0);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruWait(struct task_work *work, struct lockon_target *record)
{
    Float chance = (Uint8)((work)->ang.z) * 0.003F;
    Float roll;
    saru_take_hit(work, record);
    roll = rand() * (1.0F / (32767 + 1));
    SaruDraw(work, record);
    if (SaruCheckInterrupt(work, record)) {
        return;
    }
    if (!(record->flags & 0x200)) {
        record->frame = (njSin(((record)->angles[5])) * 0.5F) + 3.0F;
        ((record)->angles[5]) += 0x600;
    }
    if ((*(Uint16 *)&(work)->timer) > work->tick) {
        ((record)->angles[5]) = 0;
        if (roll < chance) {
            if (work->flags & 0x400) {
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_CHEER), (work)->timer = 0);
                record->flags |= 0x200;
                record->blend_speed = 0.085F;
                record->next_frame = 0.0F;
                dsPlay_oneshot(819, 0, 0, 0);
                if (rand() * (1.0F / (32767 + 1)) > 0.5F) {
                    record->next_action = &action_saru_robo_grad1_chn2;
                } else {
                    record->next_action = &saru_flip_action;
                }
                return;
            }
            if (rand() * (1.0F / (32767 + 1)) > 0.5F) {
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_HOP), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.3F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
            } else {
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_FIDGET), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.085F), (record)->next_frame = (0.0F), (record)->next_action = (&saru_fidget_action));
            }
        } else if (roll < (chance * 0.5F) + 0.5F) {
            SaruDecideAimPos(work, record);
            ((record)->last_mode = (work)->mode, (work)->mode = (SARU_TURN_BACK), (work)->timer = 0);
        } else {
            SaruDecideAimPos(work, record);
            ((record)->last_mode = (work)->mode, (work)->mode = (SARU_TURN_ON), (work)->timer = 0);
        }
    }
}
#else
void SaruWait(struct task_work *work, struct lockon_target *record)
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
    asm_stub[0] = 104; asm_stub[1] = 105;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruJump(struct task_work *work, struct lockon_target *record)
{
    saru_take_hit(work, record);
    SaruDraw(work, record);
    if (SaruCheckInterrupt(work, record)) {
        return;
    }
    if (!(record->flags & 0x200)) {
        record->frame += 0.45F;
        if (record->frame >= (Float)record->action->motion->nbFrame) {
            record->frame = (Float)record->action->motion->nbFrame - 0.1F;
            FUN_8c0fb034(work, record);
            work->tick = (rand() * (1.0F / (32767 + 1)) * 30.0F) + 10.0F;
            ((record)->last_mode = (work)->mode, (work)->mode = (SARU_WAIT), (work)->timer = 0);
            ((record)->flags |= 0x200, (record)->blend_speed = (0.1F), (record)->next_frame = (3.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
        }
    }
}
#else
void SaruJump(struct task_work *work, struct lockon_target *record)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruPori(struct task_work *work, struct lockon_target *record)
{
    saru_take_hit(work, record);
    SaruDraw(work, record);
    if (!(record->flags & 0x200)) {
        record->frame += 0.28F;
        if (record->frame >= (Float)record->action->motion->nbFrame) {
            record->frame = (Float)record->action->motion->nbFrame - 0.1F;
            work->tick = (rand() * (1.0F / (32767 + 1)) * 40.0F) + 10.0F;
            ((record)->last_mode = (work)->mode, (work)->mode = (SARU_WAIT), (work)->timer = 0);
            ((record)->flags |= 0x200, (record)->blend_speed = (0.085F), (record)->next_frame = (3.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
        }
    }
}
#else
void SaruPori(struct task_work *work, struct lockon_target *record)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruTurnL(struct task_work *work, struct lockon_target *record)
{
    saru_take_hit(work, record);
    SaruDraw(work, record);
    if (record->flags & 0x200) {
        return;
    }
    record->frame += 0.45F;
    work->ang.y = AdjustAngle(work->ang.y, 0x4000, 0x400);
    if (record->frame >= (Float)record->action->motion->nbFrame) {
        record->frame = (Float)record->action->motion->nbFrame - 0.1F;
        FUN_8c0fb034(work, record);
        work->tick = (rand() * (1.0F / (32767 + 1)) * 30.0F) + 10.0F;
        ((record)->last_mode = (work)->mode, (work)->mode = (SARU_WALK_ON), (work)->timer = 0);
        ((record)->flags |= 0x200, (record)->blend_speed = (0.3F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_move_chn2));
    }
}
#else
void SaruTurnL(struct task_work *work, struct lockon_target *record)
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
void SaruTurnR(struct task_work *work, struct lockon_target *record)
{
    saru_take_hit(work, record);
    SaruDraw(work, record);
    if (record->flags & 0x200) {
        return;
    }
    record->frame += 0.45F;
    work->ang.y = AdjustAngle(work->ang.y, 0xc000, 0x400);
    if (record->frame >= (Float)record->action->motion->nbFrame) {
        record->frame = (Float)record->action->motion->nbFrame - 0.1F;
        FUN_8c0fb034(work, record);
        work->tick = (rand() * (1.0F / (32767 + 1)) * 30.0F) + 10.0F;
        ((record)->last_mode = (work)->mode, (work)->mode = (SARU_WALK_BACK), (work)->timer = 0);
        ((record)->flags |= 0x200, (record)->blend_speed = (0.3F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_move_chn2));
    }
}
#else
void SaruTurnR(struct task_work *work, struct lockon_target *record)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruTurnP(struct task_work *work, struct lockon_target *record)
{
    saru_take_hit(work, record);
    EnemyCalcPlayerAngle(work, record, 0);
    if (!(record->flags & 0x200)) {
        record->frame += 0.45F;
        work->ang.y =
            AdjustAngle(work->ang.y, record->aim_y - work->ang.x, 0x400);
        if (record->frame >= (Float)record->action->motion->nbFrame) {
            record->frame = (Float)record->action->motion->nbFrame - 0.1F;
            FUN_8c0fb034(work, record);
            if (work->flags & 0x400) {
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_CHEER), (work)->timer = 0);
                record->flags |= 0x200;
                record->blend_speed = 0.085F;
                record->next_frame = 0.0F;
                if (rand() * (1.0F / (32767 + 1)) > 0.5F) {
                    record->next_action = &action_saru_robo_grad1_chn2;
                } else {
                    record->next_action = &saru_flip_action;
                }
            } else if (EnemyDist2FromPlayer(work, 0) < 150.0F * 150.0F &&
                       ((Float)_builtin_fabsf((Float)(playertwp[0]->pos.y - work->pos.y))) < 60.0F &&
                       work->submode != SARU_UNARMED) {
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_THROW), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.085F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_grad2_chn2));
                work->flags |= 0x200;
            } else if (rand() * (1.0F / (32767 + 1)) > 0.5F) {
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_HOP), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.3F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
            } else {
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_FIDGET), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.085F), (record)->next_frame = (0.0F), (record)->next_action = (&saru_fidget_action));
            }
        }
    }
    SaruDraw(work, record);
}
#else
void SaruTurnP(struct task_work *work, struct lockon_target *record)
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
    asm_stub[0] = 104; asm_stub[1] = 105; asm_stub[2] = 106; asm_stub[3] = 107; asm_stub[4] = 108; asm_stub[5] = 109; asm_stub[6] = 110; asm_stub[7] = 111;
    asm_stub[0] = 112; asm_stub[1] = 113; asm_stub[2] = 114; asm_stub[3] = 115; asm_stub[4] = 116;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void SaruRunR(struct task_work *work, struct lockon_target *record)
{
    saru_take_hit(work, record);
    SaruDrawLow(work, record);
    if (!(record->flags & 0x200)) {
        record->frame += 1.2F;
        work->ang.x -= (Angle)(1.0F / (work->scl.z + 3.0F) * (65536.0 / (2 * 3.141592)));
        SaruTraceCircle(work, record);
        ((record)->unk_78) = ((Float)_builtin_fabsf((Float)(njSin(record->phase)))) * 7.0F;
        record->phase += 0x9a8;
        if (record->frame >= (Float)record->action->motion->nbFrame) {
            record->frame -= (Float)record->action->motion->nbFrame;
            record->phase = 0;
            FUN_8c0fb034(work, record);
            dsPlay_oneshot_v(33, 0, 0, 0, work->pos.x, work->pos.y,
                          work->pos.z);
            if (SaruCheckInterrupt(work, record)) {
                return;
            }
            if ((*(Uint16 *)&(work)->timer) > 120 &&
                EnemyDist2FromPlayer(work, 0) < 25.0F * 25.0F) {
                SaruDecideAimPos(work, record);
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_TURN_ON), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.4F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
            } else if ((*(Uint16 *)&(work)->timer) > (Uint16)((work)->ang.z) ||
                       DiffAngle(record->heading, work->ang.x) < 0x1000) {
                work->tick = (rand() * (1.0F / (32767 + 1)) * 20.0F) + 10.0F;
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_FACE), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.1F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
            }
        }
    }
}
void SaruRunL(struct task_work *work, struct lockon_target *record)
{
    saru_take_hit(work, record);
    SaruDrawLow(work, record);
    if (!(record->flags & 0x200)) {
        record->frame += 0.8F;
        work->ang.x += (Angle)(1.0F / (work->scl.z + 3.0F) * (65536.0 / (2 * 3.141592)));
        SaruTraceCircle(work, record);
        ((record)->unk_78) = ((Float)_builtin_fabsf((Float)(njSin(record->phase)))) * 6.0F;
        record->phase += 0x670;
        if (record->frame >= (Float)record->action->motion->nbFrame) {
            record->frame -= (Float)record->action->motion->nbFrame;
            record->phase = 0;
            FUN_8c0fb034(work, record);
            if (SaruCheckInterrupt(work, record)) {
                return;
            }
            if ((*(Uint16 *)&(work)->timer) > 120 &&
                EnemyDist2FromPlayer(work, 0) < 25.0F * 25.0F) {
                SaruDecideAimPos(work, record);
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_TURN_BACK), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.4F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
            } else if ((*(Uint16 *)&(work)->timer) > (Uint16)((work)->ang.z) ||
                       DiffAngle(record->heading, work->ang.x) < 0x1000) {
                work->tick = (rand() * (1.0F / (32767 + 1)) * 20.0F) + 10.0F;
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_FACE), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.1F), (record)->next_frame = (0.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
            }
        }
    }
}
#else
void SaruRunL(struct task_work *work, struct lockon_target *record)
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
    asm_stub[0] = 104; asm_stub[1] = 105; asm_stub[2] = 106; asm_stub[3] = 107; asm_stub[4] = 108; asm_stub[5] = 109; asm_stub[6] = 110;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
#else
void SaruRunR(struct task_work *work, struct lockon_target *record)
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
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0fd9c0(struct task_work *work, struct lockon_target *record)
{
    saru_take_hit(work, record);
    SaruDraw(work, record);
    if (!(record->flags & 0x200)) {
        record->frame += 0.4F;
        if (record->frame >= (Float)record->action->motion->nbFrame) {
            FUN_8c0fb034(work, record);
            if (rand() * (1.0F / (32767 + 1)) < 0.5F) {
                record->frame = (Float)record->action->motion->nbFrame - 0.1F;
                work->tick = (rand() * (1.0F / (32767 + 1)) * 10.0F) + 10.0F;
                ((record)->last_mode = (work)->mode, (work)->mode = (SARU_WAIT), (work)->timer = 0);
                ((record)->flags |= 0x200, (record)->blend_speed = (0.1F), (record)->next_frame = (3.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
            } else {
                dsPlay_oneshot(819, 0, 0, 0);
                record->frame -= (Float)record->action->motion->nbFrame;
            }
        }
    }
}
#else
void FUN_8c0fd9c0(struct task_work *work, struct lockon_target *record)
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
    asm_stub[0] = 72;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0fdae4(struct task *task, struct lockon_target *record)
{
    struct task_work *work = task->work;
    saru_take_hit(work, record);
    saru_draw_throwing(task, record);
    if (!(record->flags & 0x200)) {
        record->frame += 0.3F;
        if (record->frame >= (Float)record->action->motion->nbFrame) {
            record->frame = (Float)record->action->motion->nbFrame - 2.0F;
            work->tick = ((work)->ang.z);
            ((record)->last_mode = (work)->mode, (work)->mode = (SARU_WAIT), (work)->timer = 0);
            ((record)->flags |= 0x200, (record)->blend_speed = (0.07F), (record)->next_frame = (3.0F), (record)->next_action = (&action_saru_robo_wait_chn2));
            dsPlay_oneshot_v(820, 0, 0, 0, work->pos.x, work->pos.y,
                          work->pos.z);
        }
    }
}
#else
void FUN_8c0fdae4(struct task *task, struct lockon_target *record)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void saru_step(struct task *task)
{
    struct task_work *work = task->work;
    struct lockon_target *record = ((struct lockon_target *)(task)->motion);
    if (edit_mode) {
        FUN_8c0fc6ac(task);
        return;
    }
    if (CheckRangeOutWithR(task, (700.0F * 700.0F))) {
        return;
    }
    switch (work->mode) {
    case SARU_WAIT:
        SaruWait(work, record);
        break;
    case SARU_HOP:
        SaruJump(work, record);
        break;
    case SARU_FIDGET:
        SaruPori(work, record);
        break;
    case SARU_TURN_ON:
        SaruTurnL(work, record);
        break;
    case SARU_WALK_ON:
        SaruRunL(work, record);
        break;
    case SARU_TURN_BACK:
        SaruTurnR(work, record);
        break;
    case SARU_WALK_BACK:
        SaruRunR(work, record);
        break;
    case SARU_FACE:
        SaruTurnP(work, record);
        break;
    case SARU_CHEER:
        FUN_8c0fd9c0(work, record);
        break;
    case SARU_THROW:
        FUN_8c0fdae4(task, record);
        break;
    case SARU_BREAK:
        Knuckles_KakeraGame_Set_PutEme(((record)->unk_4c), &work->pos);
        saru_break(work, record);
        enemy_end(task, work, record), DeadOut(task);
        return;
    default:
        break;
    }
    enemy_save_pos(work, record);
    knuckles_find_piece(((record)->unk_4c), &work->pos);
    work->timer++;
    if (((struct saru_vars *)&(work)->vars)->since_hit++ > 600) {
        work->flags &= ~0x400;
    }
    if (work->flags & 0x100) {
        EntryColliList(work);
    }
    LoopTaskC(task);
}
#else
void saru_step(struct task *task)
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
    asm_stub[0] = 104; asm_stub[1] = 105; asm_stub[2] = 106; asm_stub[3] = 107; asm_stub[4] = 108; asm_stub[5] = 109; asm_stub[6] = 110; asm_stub[7] = 111;
    asm_stub[0] = 112; asm_stub[1] = 113; asm_stub[2] = 114; asm_stub[3] = 115; asm_stub[4] = 116; asm_stub[5] = 117; asm_stub[6] = 118;
}
#endif
