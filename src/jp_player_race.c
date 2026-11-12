/* @unit 8C07F4A0-8C081A00 @data 8C158E7C-8C158E98 +r04 +egflags +pool32 */
/* Ported from the Japanese release's src/player/race.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
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
void late_DrawSprite2D(NJS_SPRITE *sp, Int n, Float pri, Uint32 attr);
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
typedef enum SYE_CBL_CABLE_TAG {
    SYE_CBL_CABLE_VGA = 0,
    SYE_CBL_CABLE_RESERVED = 1,
    SYE_CBL_CABLE_RGB = 2,
    SYE_CBL_CABLE_VBS = 3
} SYE_CBL_CABLE;
SYE_CBL_CABLE syCblCheckCable(void);
void syBtExit(void);
Sint32 syBtCheckDisc(void);
struct tag_SYS_BT_SYSTEMID {
    Sint32 nNo;
    Sint32 nAll;
    Sint8 szProduct[16];
};
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID;
Sint32 syBtGetBootSystemID(SYS_BT_SYSTEMID *id);
Sint32 syBtGetCurrentSystemID(SYS_BT_SYSTEMID *id);
void syBtGetSystemIDAddress(char **boot, char **current);
void syMallocInit(void *heap, Uint32 size);
void syMallocFinish(void);
void syMallocStat(Uint32 *wholeFreeSize, Uint32 *biggestFreeBlockSize);
void *syMalloc(Uint32 size);
void syFree(void *ptr);
typedef struct PDS_PERIPHERALINFO {
    Uint32 type;
    Uint32 reserved[3];
    Uint8 is_root;
    Uint8 area_code;
    Uint8 connector_dir[2];
    char product_name[32];
    char license[64];
    Uint16 stdby_pow;
    Uint16 max_pow;
} PDS_PERIPHERALINFO;
typedef struct PDS_PERIPHERAL {
    Uint32 id;
    Uint32 support;
    Uint32 on;
    Uint32 off;
    Uint32 press;
    Uint32 release;
    Uint16 r, l;
    Sint16 x1, y1, x2, y2;
    char *name;
    void *extend;
    Uint32 old;
    struct PDS_PERIPHERALINFO *info;
} PDS_PERIPHERAL;
void pdExecPeripheralServer(void);
typedef PDS_PERIPHERAL NJS_PERIPHERAL;
const NJS_PERIPHERAL *njGetPeripheral(Uint32 port);
void njPrintPeripheralInfo(Int loc, Uint32 port);
void pdInitPeripheral(Sint32 logic, void *recvbuf, void *sendbuf);
void pdExitPeripheral(void);
const PDS_PERIPHERAL *pdGetPeripheral(Uint32 port);
const PDS_PERIPHERALINFO *pdGetPeripheralInfo(Uint32 port);
Sint32 pdGetPeripheralError(Uint32 port);
void pdSetMode(Sint32 mode);
Sint32 pdGetMode(void);
typedef Uint16 SY_TMR_CLOCK;
void syTmrInit(void);
Uint32 syTmrGetCount(void);
Uint32 syTmrDiffCount(Uint32 count1, Uint32 count2);
Uint32 syTmrCountToMicro(Uint32 count);
Uint32 syTmrMicroToCount(Uint32 micro);
void syTmrGenStart(void);
void syTmrGenStop(void);
void syTmrGenSetInt(void (*func)(void *), void *arg);
void syTmrGenCancelInt(void);
void syTmrGenSetClock(SY_TMR_CLOCK clock);
void syTmrGenSetCount(Uint32 count);
Uint32 syTmrGenGetCount(void);
Uint32 syTmrGenMicroToCount(Uint32 micro, SY_TMR_CLOCK clock);
Uint32 syTmrGenCountToMicro(Uint32 count, SY_TMR_CLOCK clock);
Uint32 syTmrGenDiffCount(Uint32 count1, Uint32 count2);
Sint32 syTmrInt1Set(Uint32 count, void (*func)(void *), void *arg);
void syTmrInt1Cancel(void);
Sint32 syTmrInt1SetEx(Uint32 count, void (*func)(void *), void *arg,
                      SY_TMR_CLOCK clock);
typedef struct _SYS_RTC_DATE {
    Uint16 year;
    Uint8 month;
    Uint8 day;
    Uint8 hour;
    Uint8 minute;
    Uint8 second;
    Uint8 dayofweek;
    Uint8 ageofmoon;
} SYS_RTC_DATE;
Sint32 syRtcInit(void);
void syRtcFinish(void);
void syRtcExecServer(void);
Sint32 syRtcGetDate(SYS_RTC_DATE *date);
Sint32 syRtcSetDate(const SYS_RTC_DATE *date);
void syRtcSetServerMode(Sint32 mode);
Sint32 syRtcGetStat(void);
Sint32 syRtcCompareDate(const SYS_RTC_DATE *date1, const SYS_RTC_DATE *date2);
void syRtcDateToCount(const SYS_RTC_DATE *date, Uint32 *count);
void syRtcCountToDate(Uint32 count, SYS_RTC_DATE *date);
struct sy_fiber {
    void *sp;
    void *data;
};
Sint32 syFbrInit(struct sy_fiber *table, Sint32 count);
struct sy_fiber *syFbrCreateFiber(void *stack, Uint32 size,
                                  void (*func)(void *), void *data);
struct sy_fiber *syFbrConvertThreadToFiber(void *data);
Sint32 syFbrDeleteFiber(struct sy_fiber *fiber);
struct sy_fiber *syFbrGetCurrentFiber(void);
void *syFbrGetFiberData(void);
Sint32 syFbrSetIntStack(void *stack);
void syFbrSwitchToFiber(struct sy_fiber *fiber);
void syFbrDelayedSwitchToFiber(struct sy_fiber *fiber);
struct sy_fiber *syFbrGetTblPtr(int index);
Sint32 syFbrGetMaxFiber(void);
void *syFbrGetSp(struct sy_fiber *fiber);
void *syFbrGetData(struct sy_fiber *fiber);
void syFbrSetSp(struct sy_fiber *fiber, void *sp);
void syFbrSetData(struct sy_fiber *fiber, void *data);
void *syFbrGet_fib_sp(int index);
void syFbrDumpTable(void);
void *syFbrCreateFiberMain(void *stack, Sint32 size, void (*func)(void *),
                           void *data);
void syCacheInit_P2_(Uint32 form);
void syCachePurgeAll(void);
void syCacheICI_P2_(void);
void syCacheOCI_P2_(void);
void syCacheOCBP(void *address, Sint32 size);
void syCacheOCBI(void *address, Sint32 size);
void syCacheOCWB(void *address, Uint32 size);
void syCachePREF(void *address, Uint32 size);
void syCachePREF_s(void *address, Uint32 size);
void syCacheMOVCAL(void *address, Uint32 value);
void syCacheAllocCacheRAM(void **address, Sint32 pages);
void syCacheFreeCacheRAM(void *address);
void syIntInit(Uint32 mode, void *stack);
void syIntEnableInt(Uint32 level);
void syIntBrkRteRte(void);
typedef struct {
    Uint16 year;
    Uint8 month;
    Uint8 day;
    Uint8 hour;
    Uint8 minute;
    Uint8 second;
    Uint8 dayofweek;
} BUS_TIME;
typedef struct {
    Uint8 volume[32];
    Uint16 total_blocks;
    Uint16 total_user_blocks;
    Uint16 free_blocks;
    Uint16 free_user_blocks;
    Uint16 total_exe_blocks;
    Uint16 free_exe_blocks;
    Uint16 block_size;
    Uint16 icon_no;
    BUS_TIME time;
} BUS_DISKINFO;
typedef struct {
    Uint32 filesize;
    Uint16 blocks;
    Uint8 type;
    Uint8 copyflag;
    Uint16 headerofs;
    BUS_TIME time;
} BUS_FILEINFO;
typedef void (*BU_INITCALLBACK)(void);
typedef Sint32 (*BU_COMPLETECALLBACK)(Sint32 drive, Sint32 op, Sint32 status,
                                      Uint32 param);
typedef Sint32 (*BU_PROGRESSCALLBACK)(Sint32 drive, Sint32 op, Sint32 count,
                                      Sint32 max);
typedef struct {
    char vms_comment[18];
    char btr_comment[34];
    Uint8 game_name[16];
    void *icon_palette;
    void *icon_data;
    Uint16 icon_num;
    Uint16 icon_speed;
    void *visual_data;
    Uint16 visual_type;
    Uint16 reserved;
    void *save_data;
    Uint32 save_size;
} BUS_BACKUPFILEHEADER;
Sint32 buInit(Sint32 capacity, Sint32 drives, void *work, BU_INITCALLBACK func);
Sint32 buExit(void);
void buExecServer(void);
Uint32 buGetVersion(void);
void buSetCompleteCallback(BU_COMPLETECALLBACK func);
void buSetProgressCallback(BU_PROGRESSCALLBACK func);
void buSetCallbackParam(Uint32 param);
void buSetPrintFunc(void (*func)(const char *str));
void buSetRetryCount(Sint32 count);
Sint32 buIsReady(Sint32 drive);
Sint32 buStat(Sint32 drive);
Sint32 buGetLastError(Sint32 drive);
Sint32 buMount(Sint32 drive);
Sint32 buRemount(Sint32 drive);
Sint32 buUnmount(Sint32 drive);
Sint32 buMountDisk(Sint32 drive, void *addr, Sint32 size);
Sint32 buUnmountDisk(Sint32 drive);
Sint32 buIsFormat(Sint32 drive);
Sint32 buFormatDisk(Sint32 drive, const Uint8 *volume, Sint32 icon,
                    const BUS_TIME *time, Uint32 flag);
Sint32 buGetDiskInfo(Sint32 drive, BUS_DISKINFO *info);
Sint32 buGetDiskFree(Sint32 drive, Sint32 type);
Sint32 buDefragDisk(Sint32 drive, void *work);
Sint32 buFindFirstFile(Sint32 drive, char *fname);
Sint32 buFindNextFile(Sint32 drive, char *fname);
Sint32 buFindFirstFileEx(Sint32 drive, char *fname, BUS_FILEINFO *finfo);
Sint32 buFindNextFileEx(Sint32 drive, char *fname, BUS_FILEINFO *finfo);
Sint32 buFindExecFile(Sint32 drive, char *fname);
Sint32 buIsExistFile(Sint32 drive, const char *fname);
Sint32 buGetFileInfo(Sint32 drive, const char *fname, BUS_FILEINFO *finfo);
Sint32 buGetFileSize(Sint32 drive, const char *fname);
Sint32 buLoadFile(Sint32 drive, const char *fname, void *buf, Uint32 nblock);
Sint32 buLoadFileEx(Sint32 drive, const char *fname, void *buf, Uint32 start,
                    Uint32 nblock);
Sint32 buSaveFile(Sint32 drive, const char *fname, const void *buf,
                  Uint32 nblock, BUS_TIME *time, Uint32 flag);
Sint32 buSaveExecFile(Sint32 drive, const char *fname, const void *buf,
                      Uint32 nblock, BUS_TIME *time, Uint32 flag);
Sint32 buRewriteExecFile(Sint32 drive, const char *fname, const void *buf,
                         Uint32 start, Uint32 nblock);
Sint32 buDeleteFile(Sint32 drive, const char *fname);
Sint32 buDeleteFileEx(Sint32 drive, const char **fname, Sint32 nfiles);
Sint32 buRenameFile(Sint32 drive, const char *from, const char *to);
Sint32 buSetFileAttr(Sint32 drive, const char *fname, Uint16 hdrofs,
                     Uint8 copyflag);
Sint32 buMakeBackupFileImage(void *buf, const BUS_BACKUPFILEHEADER *hdr);
Sint32 buCalcBackupFileSize(Uint32 inum, Uint32 vtype, Uint32 size);
Sint32 buAnalyzeBackupFileImage(BUS_BACKUPFILEHEADER *hdr, const void *buf);
Uint16 buCalcCRC(const void *buf, Uint32 size);
void buDisableServer(void);
void kbCfgIni(Sint32 which);
void *kbCfgGetId(void);
typedef struct SYS_BT_FL_BLK_INFO {
    Sint32 fmaddr;
    Sint32 size;
} SY_BT_FL_BLKINFO;
Sint32 syBtFlGetInfo(Sint32 part, SY_BT_FL_BLKINFO *info);
Sint32 syBtFlRead(Sint32 address, void *buffer, Sint32 size);
Sint32 syBtFlWrite(Sint32 address, void *buffer, Sint32 size);
Sint32 syBtFlDeleteSct(Sint32 address);
Sint32 fmMngInit(Sint32 part, void *work);
Sint32 fmMngFormat(Sint32 type);
Sint32 fmMngRead(Sint32 packet, void *buffer);
Sint32 fmMngWrite(Sint32 packet, void *buffer);
Sint32 fmMngExecServer(void);
Sint32 fmMngGetErr(void);
void fmMngFinish(void);
Sint32 fmMngRefresh(void);
Sint32 fmMngGetFree(void);
Uint32 fmcalccrc(Sint32 size, const Uint8 *data);
Sint32 syBtCfgSet(Sint32 permit, void *work);
Sint32 syCfgInit(void *work);
Sint32 syCfgExit(void);
Sint32 syCfgSetSoundMode(Sint32 mode);
Sint32 syCfgGetSoundMode(Sint32 *mode);
enum SDE_ERR {
    SDE_ERR_NOTHING,
    SDE_ERR_PRM_OVER_RANGE = 0x03000001,
    SDE_ERR_QUEUE_NO_ENOUGH = 0x05000101,
    SDE_ERR_MEMBLK_ALREADY_TRANSFER = 0x06000001,
    SDE_ERR_HANDLE_NO_ENOUGH = 0x07000101,
    SDE_ERR_HANDLE_ILLEGAL_VALUE = 0x07000102,
    SDE_ERR_HANDLE_NULL = 0x07000103,
    SDE_ERR_PTR_NULL = 0x07000203,
    SDE_ERR_BANK_ILLEGAL_NUM = 0x08000003,
    SDE_ERR_DATA_ILLEGAL_TYPE = 0x09000001,
    SDE_ERR_DATA_ILLEGAL_VER = 0x09000002,
    SDE_ERR_HOST_CMD_BUF_NO_ENOUGH = 0x0a000001,
    SDD_ERR_SND_DRV_ILLEGAL_VER = 0x0b000002,
    SDE_ERR_SND_DRV_BUSY = 0x0b000003,
    SDE_ERR_NO_INIT = 0x0d000001,
    SDE_ERR_UNKNOW_NUM = 0x7fffffff
};
typedef enum SDE_ERR SDE_ERR;
enum SDE_DATA_TYPE {
    SDE_DATA_TYPE_SND_DRV = (('S') | (('D') << 8) | (('R') << 16) | (('V') << 24)),
    SDE_DATA_TYPE_MULTI_UNIT = (('S') | (('M') << 8) | (('L') << 16) | (('T') << 24)),
    SDE_DATA_TYPE_MIDI_SEQ_DATA = (('S') | (('M') << 8) | (('S') << 16) | (('D') << 24)),
    SDE_DATA_TYPE_MIDI_SEQ_BANK = (('S') | (('M') << 8) | (('S') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_MIDI_PRG_BANK = (('S') | (('M') << 8) | (('P') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_SHOT_DATA = (('S') | (('O') << 8) | (('S') << 16) | (('D') << 24)),
    SDE_DATA_TYPE_SHOT_BANK = (('S') | (('O') << 8) | (('S') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_PSTM_DATA = (('S') | (('P') << 8) | (('S') << 16) | (('D') << 24)),
    SDE_DATA_TYPE_PSTM_RING_BUF = (('S') | (('P') << 8) | (('S') << 16) | (('R') << 24)),
    SDE_DATA_TYPE_FX_OUT_BANK = (('S') | (('F') << 8) | (('O') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_FX_PRG_BANK = (('S') | (('F') << 8) | (('P') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_FX_PRG_WRK = (('S') | (('F') << 8) | (('P') << 16) | (('W') << 24))
};
typedef enum SDE_DATA_TYPE SDE_DATA_TYPE;
enum SDE_SPACE {
    SDE_SPACE_MONO = (('M') | (('O') << 8) | (('N') << 16) | (('O') << 24)),
    SDE_SPACE_STEREO = (('S') | (('T') << 8) | (('R') << 16) | (('O') << 24))
};
typedef enum SDE_SPACE SDE_SPACE;
enum SDE_MEMBLK_STAT {
    SDE_MEMBLK_STAT_TRANSFER_REMAIN,
    SDE_MEMBLK_STAT_TRANSFER_FINISHED,
    SDE_MEMBLK_STAT_TRANSFER_PROGRESS
};
typedef enum SDE_MEMBLK_STAT SDE_MEMBLK_STAT;
enum SDE_MEMBLK_TRANSFER_MODE {
    SDE_MEMBLK_TRANSFER_MODE_CPU,
    SDE_MEMBLK_TRANSFER_MODE_DMA
};
typedef enum SDE_MEMBLK_TRANSFER_MODE SDE_MEMBLK_TRANSFER_MODE;
enum SDE_PCM_TYPE {
    SDE_PCM_TYPE_8BIT_PCM,
    SDE_PCM_TYPE_16BIT_PCM,
    SDE_PCM_TYPE_4BIT_ADPCM
};
typedef enum SDE_PCM_TYPE SDE_PCM_TYPE;
typedef struct SDS_MIDI_MES {
    Uint8 m_Member[4];
} SDS_MIDI_MES;
struct SDS_VER {
    Sint8 m_MajorVer;
    Sint8 m_MinorVer;
    Sint8 m_DebugVer;
    Sint8 rsv;
};
typedef struct SDS_VER SDS_VER;
typedef struct SDS_PORT_REF *SDHANDLE;
typedef SDHANDLE *SDMIDI;
typedef SDHANDLE *SDPSTM;
struct SDS_MIDI_STAT {
    Sint8 m_HostCmdRsvNum;
    Sint8 m_HostCmdDelayTime;
    Sint8 m_Vol;
    Sint8 m_Pan;
    Sint8 m_FxLev;
    Sint8 m_DrctLev;
    Sint16 m_Pitch;
    Sint16 m_Speed;
    Uint32 m_TotalBeatTime;
    Sint32 m_CurAdr;
    Uint32 m_Err;
    Uint32 m_Flg;
};
typedef struct SDS_MIDI_STAT SDS_MIDI_STAT;
struct SDS_PSTM_STAT {
    Sint8 m_HostCmdRsvNum;
    Sint8 m_HostCmdDelayTime;
    Sint8 m_Vol;
    Sint8 m_Pan;
    Sint8 m_FxLev;
    Sint8 m_DrctLev;
    Sint16 m_Pitch;
    Sint16 m_Speed;
    Uint32 m_TotalSmpFrame;
    Sint32 m_CurAdr;
    Uint32 m_Err;
    Uint32 m_Flg;
};
typedef struct SDS_PSTM_STAT SDS_PSTM_STAT;
struct SDS_MEM_BLK {
    Uint32 m_Member[8];
};
typedef struct SDS_MEM_BLK *SDMEMBLK;
typedef void (*SD_MEMBLK_CALLBACK_FUNC)(void *first_arg);
SDE_ERR sdDrvInit(SDMEMBLK handle);
SDE_ERR sdDrvGetInfo(void);
SDE_ERR sdLibInit(void *wrk_ptr, Sint32 mem_blk_handle_max,
                  Sint32 second_host_cmd_max);
SDE_ERR sdSysServer(void);
SDE_ERR sdSysFlushHostCmd(void);
void sdSysErrTrap(void *func, SDE_ERR err);
int sdDebugPrintf(const char *format, ...);
int sdDebugPrint(const char *str);
int sdDebugSetPrintFunc(void (*func)(const char *str));
extern Bool sdgDebugMode;
extern void (*sdgPrintFunc)(const char *str);
extern Sint32 sdgExistSndDrv;
SDE_ERR sdARM7ResetKeep(void);
SDE_ERR sdARM7ResetRel(void);
SDE_ERR sdSndMemClear(void);
SDE_ERR sdSndMemWriteUint8(Sint32 address, Uint8 value);
SDE_ERR sdModuleRefInit(void);
SDE_ERR sdPrimaryHostCmdInitList(void *buffer);
extern void *sdgPrimaryBufPtr;
SDE_ERR sd2ndHostCmdSendList(void);
SDE_ERR sdPrimaryHostCmdFlush(void);
void sdPrimaryHostCmdFlushCallback(void *first_arg);
SDE_ERR sdSndMemReadSint8(Sint32 address, Sint8 *value);
SDE_ERR sdSndMemReadUint8(Sint32 address, Uint8 *value);
SDE_ERR sdSndMemReadSint32(Sint32 address, Sint32 *value);
SDE_ERR sdSndMemReadUint32(Sint32 address, Uint32 *value);
SDE_ERR sdSndMemWriteSint32(Sint32 address, Sint32 value);
SDE_ERR sdSndMemWriteUint32(Sint32 address, Uint32 value);
SDE_ERR sdSndSetSpace(const SDE_SPACE space);
SDE_ERR sdSndSetFxPrg(const Sint8 new_fx_prg_num, const Sint8 new_fx_out_num);
SDE_ERR sdSndSetFxOutPrm(const Sint8 out_num, const Sint8 out_pan,
                         const Sint8 out_lev);
SDE_ERR sdQsndSetPos(const Sint8 *pos);
SDE_ERR sdMultiUnitDownload(SDMEMBLK handle);
SDE_ERR sdBankDownload(SDMEMBLK handle, const SDE_DATA_TYPE bank_type,
                       const Sint8 bank_num);
SDE_ERR sdSndMemGetBankStat(const SDE_DATA_TYPE data_type, const Sint8 bank_num,
                            Sint32 *allocate_ptr, Sint32 *allocate_size);
SDE_ERR sdSndMemAllocateBank(const SDE_DATA_TYPE data_type, int bank_num,
                             Sint32 allocate_ptr, Sint32 allocate_size);
SDE_ERR sdMemBlkCreate(SDMEMBLK *handle);
SDE_ERR sdMemBlkDestroy(SDMEMBLK handle);
SDE_ERR sdMemBlkSetPrm(SDMEMBLK handle, const void *src_blk_ptr,
                       const Sint32 src_blk_sz,
                       const SD_MEMBLK_CALLBACK_FUNC callback_func,
                       const void *callback_first_arg);
SDE_ERR sdMemBlkGetStat(SDMEMBLK handle, SDE_MEMBLK_STAT *stat);
SDE_ERR sdMemBlkTransfer(SDMEMBLK handle, Sint32 dst_ptr);
SDE_ERR sdMemBlkSetTransferMode(SDE_MEMBLK_TRANSFER_MODE transfer_mode);
SDE_ERR sdMemBlkQueGetPushNum(Sint32 *push_num);
SDE_ERR sdMemBlkSetStat(SDMEMBLK handle, SDE_MEMBLK_STAT stat);
SDE_ERR sdMemBlkSetAdr(SDMEMBLK handle, const void *src_blk_ptr);
SDE_ERR sdMemBlkSetSz(SDMEMBLK handle, Sint32 src_blk_sz);
SDE_ERR sdMemBlkSetCallback(SDMEMBLK handle,
                            SD_MEMBLK_CALLBACK_FUNC callback_func,
                            const void *callback_first_arg);
SDE_ERR sdMemBlkExecuteCallback(SDMEMBLK handle);
SDE_ERR sdMemBlkCpuTransfer(SDMEMBLK handle, Sint32 dst_ptr);
SDE_ERR sdMemBlkQuePush(SDMEMBLK handle, Sint32 dst_ptr);
SDE_ERR sdMemBlkQuePop(SDMEMBLK *handle, Sint32 *dst_ptr);
SDE_ERR sdMemBlkDmaTransfer(SDMEMBLK handle, Sint32 dst_ptr);
void sdMemBlkWaitSync(void);
void sdMemBlkG2DmaErrTrap(void);
void sdMemBlkEndTransferHandller(void *first_arg);
SDE_ERR sdMoveWrkMemToSndMem(void *src_ptr, Sint32 dst_ptr, Sint32 size,
                             SD_MEMBLK_CALLBACK_FUNC callback_func,
                             void *callback_first_arg);
SDE_ERR sdMidiOpenPort(SDMIDI *handle);
SDE_ERR sdMidiPlay(SDMIDI handle, const Sint8 bank_num, const Sint8 data_num,
                   const Sint8 priority);
SDE_ERR sdMidiSetMes(SDMIDI handle, SDS_MIDI_MES *midi_mes_ptr,
                     const Uint8 midi_mes, ...);
SDE_ERR sdMidiSetVol(SDMIDI handle, const Sint8 vol, const Sint32 fade_time);
SDE_ERR sdMidiStop(SDMIDI handle);
SDE_ERR sdMidiSendMes(SDMIDI handle, const SDS_MIDI_MES *midi_mes_ptr,
                      const Sint8 priority);
SDE_ERR sdMidiGetCurAdr(SDMIDI handle, Sint32 *cur_adr);
SDE_ERR sdMidiGetStat(SDMIDI handle, SDS_MIDI_STAT *midi_stat);
SDE_ERR sdMidiGetTotalBeatTime(SDMIDI handle, Uint32 *cur_beat_time);
SDE_ERR sdMidiGetDrctLev(SDMIDI handle, Sint8 *drct_lev);
SDE_ERR sdMidiGetErr(SDMIDI handle, Uint32 *err_num);
SDE_ERR sdMidiGetFlg(SDMIDI handle, Uint32 *flg);
SDE_ERR sdMidiGetFxLev(SDMIDI handle, Sint8 *fx_lev);
SDE_ERR sdMidiGetPan(SDMIDI handle, Sint8 *pan);
SDE_ERR sdMidiGetPitch(SDMIDI handle, Sint16 *pitch);
SDE_ERR sdMidiGetSpeed(SDMIDI handle, Sint16 *speed);
SDE_ERR sdMidiGetVol(SDMIDI handle, Sint8 *vol);
SDE_ERR sdPstmClosePort(SDPSTM handle);
SDE_ERR sdPstmGetCurAdr(SDPSTM handle, const Sint8 target_ch,
                        Sint32 *cur_smp_adr);
SDE_ERR sdPstmGetStat(SDPSTM handle, const Sint8 target_ch,
                      SDS_PSTM_STAT *pstm_stat);
SDE_ERR sdPstmGetTotalSmpFrame(SDPSTM handle, const Sint8 target_ch,
                               Uint32 *cur_smp_frame);
SDE_ERR sdPstmOpenPort(SDPSTM *handle, const Sint8 use_ch, ...);
SDE_ERR sdPstmPlay(SDPSTM handle, const SDE_PCM_TYPE pcm_type,
                   const Uint16 freq, const Sint8 priority);
SDE_ERR sdPstmPlayMw(SDPSTM handle, const SDE_PCM_TYPE pcm_type,
                     const Uint16 freq, const Sint8 priority);
SDE_ERR sdPstmResetPrm(SDPSTM handle);
SDE_ERR sdPstmSetBaseVol(SDPSTM handle, const Sint8 base_vol);
SDE_ERR sdPstmSetDrctLev(SDPSTM handle, const Sint8 drct_lev);
SDE_ERR sdPstmSetFxCh(SDPSTM handle, const Sint8 fx_in_ch,
                      const Sint8 fx_base_lev);
SDE_ERR sdPstmSetPan(SDPSTM handle, const Sint8 target_ch, const Sint8 pan,
                     const Sint32 fade_time);
SDE_ERR sdPstmSetPitch(SDPSTM handle, const Sint16 pitch,
                       const Sint32 fade_time);
SDE_ERR sdPstmSetUseCh(SDPSTM handle, const Sint8 use_ch);
SDE_ERR sdPstmSetVol(SDPSTM handle, const Sint8 target_ch, const Sint8 vol,
                     const Sint32 fade_time);
SDE_ERR sdPstmStop(SDPSTM handle);
SDE_ERR sdPstmStopAll(void);
SDE_ERR sdPstmGetDrctLev(SDPSTM handle, const Sint8 target_ch, Sint8 *drct_lev);
SDE_ERR sdPstmGetErr(SDPSTM handle, const Sint8 target_ch, Uint32 *err_num);
SDE_ERR sdPstmGetFlg(SDPSTM handle, const Sint8 target_ch, Uint32 *flg);
SDE_ERR sdPstmGetFxLev(SDPSTM handle, const Sint8 target_ch, Sint8 *fx_lev);
SDE_ERR sdPstmGetPan(SDPSTM handle, const Sint8 target_ch, Sint8 *pan);
SDE_ERR sdPstmGetPitch(SDPSTM handle, const Sint8 target_ch, Sint16 *pitch);
SDE_ERR sdPstmGetSpeed(SDPSTM handle, const Sint8 target_ch, Sint16 *speed);
SDE_ERR sdPstmGetVol(SDPSTM handle, const Sint8 target_ch, Sint8 *vol);
typedef struct GDS_FS_HANDLE *GDFS;
typedef struct GDS_FS_DIRREC_TBL *GDFS_DIRREC;
typedef void (*GDFS_ERRFUNC)(void *obj, Sint32 err);
typedef void (*GDFS_FUNC)(void *obj);
Sint32 gdFsInit(Sint32 max_open, void *gdfs_work, Sint32 max_dirent,
                void *dirbuf);
Sint32 gdFsInitOvl(Sint32 max_open, void *gdfs_work, Sint32 max_dirent,
                   void *dirbuf);
Sint32 gdFsReinit(void);
void gdFsFinish(void);
GDFS_DIRREC gdFsCreateDirhn(void *dirbuf, Sint32 max_dirent);
Sint32 gdFsLoadDir(const char *dirname, GDFS_DIRREC gf_dirrec);
Sint32 gdFsSetDir(GDFS_DIRREC gf_dirrec);
Sint32 gdFsChangeDir(const char *dirname);
GDFS gdFsOpen(const char *fname, GDFS_DIRREC gf_dirrec);
GDFS gdFsOpenRange(Sint32 stsct, Sint32 nsct);
typedef struct GDS_FS_DIRINFO {
    Sint32 fad;
    Sint32 fsize;
    Uint8 flag;
    Uint8 pad[3];
} GDFS_DIRINFO;
Sint32 gdFsGetDirInfo(const char *name, GDFS_DIRINFO *dirinfo);
Bool gdFsGetFileSize(GDFS gdfs, Sint32 *fsize);
Bool gdFsGetFileSctSize(GDFS gdfs, Sint32 *fsctsize);
Bool gdFsGetFileFad(GDFS gdfs, Sint32 *fad);
Sint32 gdFsSeek(GDFS gdfs, Sint32 sctno, Sint32 type);
Sint32 gdFsTell(GDFS gdfs);
Sint32 gdFsCheckEof(GDFS gdfs, Bool *iseof);
Sint32 gdFsRead(GDFS gdfs, Sint32 nsct, void *buf);
Sint32 gdFsReqRd32(GDFS gdfs, Sint32 nsct, void *buf);
Sint32 gdFsGetStat(GDFS gdfs);
Sint32 gdFsGetErrStat(GDFS gdfs);
Sint32 gdFsStopRd(GDFS gdfs);
Sint32 gdFsGetNumRd(GDFS gdfs);
Sint32 gdFsMovePickup(GDFS gdfs);
Sint32 gdFsReqGdRd(GDFS gdfs, Sint32 nsct);
Sint32 gdFsTrans32(GDFS gdfs, Sint32 nbytes, void *buf);
Sint32 gdFsGetTransStat(GDFS gdfs);
GDFS gdFsGetWorkHn(void);
GDFS gdFsGetSysHn(void);
Sint32 gdFsGetToc(Sint32 type, void *buf);
void gdFsClose(GDFS gdfs);
Sint32 gdFsGetDrvStat(void);
Sint32 gdFsReqDrvStat(void);
Bool gdFsIsTrayOpen(void);
void gdFsEntryRdEndFunc(GDFS gdfs, GDFS_FUNC func, void *obj);
void gdFsEntryTrEndFunc(GDFS gdfs, GDFS_FUNC func, void *obj);
void gdFsEntryErrFunc(GDFS gdfs, GDFS_ERRFUNC erfunc, void *obj);
void gdFsEntryErrFuncAll(GDFS_ERRFUNC erfunc, void *obj);
void gdFsExecServer(void);
Sint32 gdFsDaPlay(Sint32 st_track, Sint32 end_track, Sint32 reptime);
Sint32 gdFsDaPlaySct(Sint32 st_sct, Sint32 end_sct, Sint32 reptime);
Sint32 gdFsDaStop(void);
Sint32 gdFsDaPause(void);
Sint32 gdFsDaRelease(Sint32 reptime);
typedef struct GDS_FS_DAINFO {
    Sint32 track;
    Sint32 min;
    Sint32 sec;
    Sint32 frame;
    Sint32 fad;
} GDFS_DAINFO;
Sint32 gdFsDaGetInfo(GDFS_DAINFO *dainfo);
Sint32 gdGdcReqCmd(Sint32 cmd, void *param);
Sint32 gdGdcGetCmdStat(Sint32 gdchn, void *stat);
void gdGdcExecServer(void);
void gdGdcInitSystem(void);
Sint32 gdGdcGetDrvStat(Sint32 *info);
void gdGdcG1DmaEnd(GDFS_FUNC func, void *obj);
Sint32 gdGdcReqDmaTrans(Sint32 gdchn, Sint32 *param);
Sint32 gdGdcCheckDmaTrans(Sint32 gdchn, Sint32 *size);
void gdGdcReadAbort(Sint32 gdchn);
void gdGdcReset(void);
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
extern Sint16 world_count;
extern struct world_object world_objects[1024];
void world_land_step(struct task *task);
void world_load_act(int stage, int act);
void world_release_act(int stage, int act);
void world_change_act(Sint16 by);
void world_hide_land(void);
void world_show_land(void);
void world_set_land_material(Float gray);
void world_collect_near_players(void);
void world_collect_all(void);
void world_list_near(Float x, Float y, Float z, Float radius);
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
void late_DrawObject(NJS_OBJECT *object);
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
void dust_create_from(struct dust_params *params);
void dust_create_glow(struct dust_params *params);
void dust_grow_step(struct particle *particle, struct particle_pool *pool);
extern NJS_TEXLIST glare_texlist;
void DrawHeadLight(NJS_POINT3 *pos, NJS_VECTOR *dir, Float size, NJS_ARGB *color);
extern NJS_TEXLIST panlight_texlist;
extern struct particle_pool_spec panlight_pool;
void panlight_create(struct dust_params *params);
enum game_mode {
    GAME_MODE_BOOT = 0,
    GAME_MODE_LOGO = 1,
    GAME_MODE_TITLE = 2,
    GAME_MODE_STAGE_SELECT = 3,
    GAME_MODE_ACTION = 4,
    GAME_MODE_FIELD = 5,
    GAME_MODE_MOVIE = 8,
    GAME_MODE_TRIAL = 9,
    GAME_MODE_MENU = 10,
    GAME_MODE_MENU_RUN = 11,
    GAME_MODE_SUMMARY = 14,
    GAME_MODE_SUMMARY_RUN = 15,
    GAME_MODE_TUTORIAL = 16,
    GAME_MODE_TUTORIAL_RUN = 17,
    GAME_MODE_STAFF_ROLL = 18,
    GAME_MODE_STAFF_ROLL_RUN = 19
};
enum overlay_result {
    OVERLAY_RESET = -2,
    OVERLAY_BACK = -1,
    OVERLAY_RUNNING = 0,
    OVERLAY_DONE = 1,
    OVERLAY_EMPTY = -1
};
enum menu_choice {
    MENU_TRIAL = 100,
    MENU_ADVENTURE = 101,
    MENU_INTERNET = 102,
    MENU_STAFF_ROLL = 103,
    MENU_TUTORIAL = 104,
    MENU_UNK_106 = 106,
    MENU_DEMO = 107,
    MENU_EXIT = 108
};
enum menu_entrance {
    MENU_FROM_TOP = 0,
    MENU_FROM_SUMMARY = 1,
    MENU_FROM_TRIAL = 2
};
extern enum menu_entrance menu_entrance;
extern int cable_mode;
extern enum game_mode game_mode;
extern NJS_TEXMEMLIST texmemlist[];
extern Bool loader_error_flag;
extern int dat_8c78b4d8;
extern int dat_8c78b4dc;
extern int dat_8c78b4e0;
extern Float shape_buffer[];
extern NJS_VIEW view;
extern NJS_SCREEN screen;
extern NJS_FOG_TABLE fog_table;
void main(void);
void game_leave(void);
void game_init(void);
int game_mode_step(void);
void game_shutdown(void);
void game_release_textures(void);
void texture_release_all(void);
void display_reset_full(void);
void system_boot_init(void);
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
struct task *GetPlayerTaskPointer(Uint8 player);
int player_task_character(struct task *task);
struct player *GetPlayerWorkPointer(Uint8 player);
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
void SetInputP(Uint8 player, Uint8 mode);
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
void SetPositionP(Uint8 player, Float x, Float y, Float z);
Bool player_ground_speed(Uint8 player, Float *speed);
void player_set_speed(Uint8 player, Float x, Float y, Float z);
void player_set_accel(Sint8 player, Float x, Float y, Float z);
void player_updraft(Sint8 player, Float x, Float y, Float z);
void player_push(Sint8 player, Float x, Float y, Float z);
void player_ride_off(Uint8 player, Float x, Float y, Float z);
Bool player_set_history(Uint8 player, int steps, NJS_POINT3 *pos,
                        struct angles *ang);
Bool GetPlayerPosition(Uint8 player, int steps, NJS_POINT3 *pos,
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
extern NJS_VECTOR VecTemp0;
extern NJS_VECTOR scratch_vector2;
extern NJS_VECTOR scratch_vector3;
extern Uint8 dat_8c75d5dc[12];
extern NJS_POINT3 scratch_point;
extern NJS_POINT3 scratch_point2;
extern NJS_MATRIX scratch_matrix;
extern Uint8 dat_8c75d640[192];
extern NJS_VECTOR vG;
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
void SetFinishAction(void);
void set_character(Sint16 character);
void set_character_number(Sint16 character);
int get_character(void);
int stage_get_retries(void);
Uint16 GetStageNumber(void);
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
extern struct save SaveData[3];
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
struct AdvertiseWork {
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
extern struct AdvertiseWork AdvertiseWork;
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
struct task;
enum race_outcome { RACE_RUNNING, RACE_WON, RACE_LOST };
struct race_point {
    Sint32 attr;
    NJS_POINT3 pos;
};
extern NJS_TEXLIST milesrace_texlist;
void race_create(Uint16 character, Sint16 player, Sint16 stage);
void race_set_course(Sint32 course);
void race_set_won(void);
void race_set_lost(void);
enum race_outcome race_outcome(void);
void race_result_step(struct task *task);
void race_texture_step(struct task *task);
void race_eggman_texture_step(struct task *task);
struct task;
void sonic_step(struct task *task);
void sonic_board_start(struct task *task);
struct save;
struct task;
enum mission { MISSION_A, MISSION_B, MISSION_C };
extern NJS_TEXLIST emblem_texlist;
void emblem_clear_all(struct save *save);
Bool emblem_check(struct save *save, int number);
int emblem_count(struct save *save);
int emblem_mission_number(int character, int stage, int mission);
void emblem_set_story(struct save *save, int character);
Bool emblem_check_story(struct save *save, int character);
Bool emblem_check_mission(struct save *save, int character, int stage,
                          int mission);
void emblem_set_mission(struct save *save, int character, int stage,
                        int mission);
void emblem_step(struct task *task);
struct task *emblem_start_count_display(void);
struct task;
enum music {
    MUSIC_ADVAMY = 0,
    MUSIC_ADVBIG,
    MUSIC_ADVE102,
    MUSIC_ADVKNKLS,
    MUSIC_ADVMILES,
    MUSIC_ADVSONIC,
    MUSIC_AMY,
    MUSIC_BIG,
    MUSIC_BOSSALL,
    MUSIC_BOSSE101,
    MUSIC_BOSSEVNT,
    MUSIC_BOSSTRGT,
    MUSIC_CASINO1,
    MUSIC_CASINO2,
    MUSIC_CASINO3,
    MUSIC_CASINO4,
    MUSIC_CHAO,
    MUSIC_CHAOGOAL,
    MUSIC_CHAOHALL,
    MUSIC_CHAORACE,
    MUSIC_CHAOS,
    MUSIC_CHAOS_6,
    MUSIC_CHAOS_P1,
    MUSIC_CHAOS_P2,
    MUSIC_CHARACTR,
    MUSIC_CIRCUIT,
    MUSIC_CONTINUE,
    MUSIC_E102,
    MUSIC_ECOAST1,
    MUSIC_ECOAST2,
    MUSIC_ECOAST3,
    MUSIC_EGCARER1,
    MUSIC_EGCARER2,
    MUSIC_EGGMAN,
    MUSIC_EGGMBL23,
    MUSIC_EGGROBO,
    MUSIC_EVTBGM00,
    MUSIC_EVTBGM01,
    MUSIC_EVTBGM02,
    MUSIC_EVTBGM03,
    MUSIC_EVTBGM04,
    MUSIC_EVTBGM05,
    MUSIC_FINALEG1,
    MUSIC_FINALEG2,
    MUSIC_FISHGET,
    MUSIC_FISHING,
    MUSIC_FISHMISS,
    MUSIC_HAMMER,
    MUSIC_HIGHWAY1,
    MUSIC_HIGHWAY2,
    MUSIC_HIGHWAY3,
    MUSIC_HURRYUP,
    MUSIC_ICECAP1,
    MUSIC_ICECAP2,
    MUSIC_ICECAP3,
    MUSIC_INVNCIBL,
    MUSIC_ITEM1,
    MUSIC_JINGLE_1,
    MUSIC_JINGLE_2,
    MUSIC_JINGLE_3,
    MUSIC_JINGLE_4,
    MUSIC_JINGLE_5,
    MUSIC_KNUCKLES,
    MUSIC_LSTWRLD1,
    MUSIC_LSTWRLD2,
    MUSIC_LSTWRLD3,
    MUSIC_MAINTHEM,
    MUSIC_MSTCLN,
    MUSIC_NIGHTS_A,
    MUSIC_NIGHTS_K,
    MUSIC_NIGHTS_S,
    MUSIC_ONE_UP,
    MUSIC_OPTION,
    MUSIC_REDMNTN1,
    MUSIC_REDMNTN2,
    MUSIC_RNDCLEAR,
    MUSIC_S_SQUARE,
    MUSIC_SANDHILL,
    MUSIC_SCRAMBLE,
    MUSIC_SHELTER1,
    MUSIC_SHELTER2,
    MUSIC_SKYDECK1,
    MUSIC_SKYDECK2,
    MUSIC_SONIC,
    MUSIC_SONIC_CD,
    MUSIC_SPEEDUP,
    MUSIC_SPRSONIC,
    MUSIC_SSRACING,
    MUSIC_TAILS,
    MUSIC_THEAMY,
    MUSIC_THEBIG,
    MUSIC_THEE102,
    MUSIC_THEKNKLS,
    MUSIC_THEMILES,
    MUSIC_THESONIC,
    MUSIC_TICAL,
    MUSIC_TIMER,
    MUSIC_TITL_EGG,
    MUSIC_TITL_MR1,
    MUSIC_TITL_MR2,
    MUSIC_TITL_SS,
    MUSIC_TITLE,
    MUSIC_TITLE2,
    MUSIC_TRIAL,
    MUSIC_TWNKLPK1,
    MUSIC_TWNKLPK2,
    MUSIC_TWNKLPK3,
    MUSIC_WNDYVLY1,
    MUSIC_WNDYVLY2,
    MUSIC_WNDYVLY3,
    MUSIC_COUNT
};
void stream_init_step(struct task *task);
void stream_destroy(void);
void stream_request_music(int music);
void stream_stop_music(void);
Sint32 stream_music_state(void);
int stream_music_time(void);
Bool stream_restart_music(void);
void Serif_Play(int voice);
void stream_stop_voice(void);
Sint32 stream_voice_state(void);
int stream_voice_time(void);
void stream_mute(void);
void stream_unmute(void);
void stream_request_interlude(int music);
void stream_reset_music(void);
void stream_reset_voice(void);
void stream_reset(void);
void stream_request_and_save_music(int music);
Bool stream_restore_music(void);
extern const struct race_point sky_deck_race_points[];
extern const Sint32 sky_deck_race_count;
extern int frame_interval;
extern int frame_countdown;
extern int frame_step_count;
extern int loop_count;
void frame_pacing_init(int interval, int steps);
void frame_set_interval(int interval);
void frame_wait(void);
void frame_wait_step(int left);
void frame_vsync(void);
void fun_8c054be0(void);
void fun_8c054be4(void);
struct pad_stick {
    Angle ang;
    Float stroke;
};
extern Uint32 pad_action_buttons;
extern Sint32 pad_jump_buttons;
extern Uint32 pad_choose_buttons;
extern Uint32 pad_cancel_buttons;
extern Uint32 pad_grab_buttons;
extern Uint32 pad_camera_buttons;
extern Uint32 pad_debug_buttons;
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per_info[4];
extern Uint8 dat_8c75d910[20];
extern struct pad_stick input_dataG[8];
extern struct pad_stick pad_sticks_read[8];
extern Uint32 pad_held[4];
extern Uint32 pad_press_repeat[4];
extern Uint32 pad_held_live[4];
extern Uint32 pad_press_live[4];
extern Bool pad_port_used[4];
extern int pad_ports[4];
void pad_enable(void);
void pad_disable(void);
Bool pad_is_enabled(void);
void pad_enable_player(Uint8 player);
void PadReadOffP(Uint8 player);
Bool pad_player_is_enabled(Uint8 player);
Bool pad_quit_pressed(int unused);
void pad_scan(void);
struct texture_pvm {
    char *name;
    NJS_TEXLIST *texlist;
};
struct act_textures {
    Uint16 stage_act;
    Sint8 count;
    Sint8 users;
    struct texture_pvm *pvms;
};
extern Sint8 character_users[];
void texture_load_character(int character);
void texture_release_character(int character);
void texture_release_characters(void);
void texture_load_regular(int set);
void texture_release_regular(void);
void texture_load_stage(void);
Bool texture_set_regular(void);
Bool texture_set_stage(void);
Bool texture_has_primary_stage_texlist(void);
void texture_release_stage(void);
Bool texture_load_act(Uint16 stage_act);
Bool texture_act_in_use(Uint16 stage_act);
Bool texture_release_act(Uint16 stage_act);
void texture_release_acts(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
Sint32 texture_load_prs_file(char *name, NJS_TEXLIST *texlist);
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
/* EU: pad_jump_buttons is declared Sint32 in this file (above): one name, so one pool entry in race_sonic_drive, and the
   Sint32 gives its GOAL_ARRIVE store order (the Japanese decomp's second Sint32 name for it adds a second pool entry here) */
#define pad_jump_buttons_signed pad_jump_buttons
enum course {
    COURSE_WINDY,
    COURSE_HIGHWAY,
    COURSE_SKY_DECK,
    COURSE_ICECAP,
    COURSE_CASINO,
    COURSE_COUNT
};
enum point_kind {
    POINT_RUN,
    POINT_RUN_LEVEL,
    POINT_END,
    POINT_COAST_NEAR,
    POINT_DASH,
    POINT_COAST,
    POINT_EASE,
    POINT_LAUNCHED,
    POINT_REQUESTED,
    POINT_PUSH,
    POINT_LEDGE,
    POINT_DASH_NEAR,
    POINT_LAND,
    POINT_SPIN_UP,
    POINT_PATH,
    POINT_AIR,
    POINT_WAIT,
    POINT_BOARD,
    POINT_GOAL,
    POINT_LEAP
};
enum stick_way { WAY_RIGHT, WAY_LEFT, WAY_UP, WAY_DOWN };
enum race_mode { RACE_START, RACE_RUN, RACE_OVER };
enum wait_submode { WAIT_ARRIVE, WAIT_READY };
enum goal_submode {
    GOAL_ARRIVE,
    GOAL_JUMP,
    GOAL_LANDED,
    GOAL_LEAP,
    GOAL_FALL,
    GOAL_DONE
};
struct race_vars {
    Uint16 last[2];
    Sint16 point[2];
    Sint16 steps;
    Sint16 spin_steps;
};
struct race_aim {
    NJS_POINT3 from;
    NJS_POINT3 to;
    NJS_VECTOR ahead;
    Float distance;
    Sint32 attr;
    Sint32 resume;
    Angle heading;
    Float speed;
    Sint32 jumps;
};
struct race_eggman {
    NJS_POINT3 from;
    NJS_POINT3 to;
    NJS_VECTOR speed;
    Angle bob_phase;
    Float bob;
};
struct race_spark {
    struct dust_params *params;
    NJS_POINT3 from;
    NJS_POINT3 to;
};
enum race_saying {
    SAY_RACER_CLOSES = 0,
    SAY_TAILS_CLOSES = 1,
    SAY_LEADING = 2,
    SAY_TRAILING = 3,
    SAY_FAR_BEHIND = 4,
    SAY_START = 7
};
enum race_voices_mode { VOICES_WAIT, VOICES_RACE };
struct race_voices {
    enum race_voices_mode mode;
    enum race_saying last;
    Sint32 turns;
    Sint32 wait;
};
struct race_texture_vars {
    Uint8 unk_00[8];
    NJS_TEXLIST *texlist;
};
struct race_banner_vars {
    Uint8 unk_00[4];
    Float sprite;
    Float scale;
};
enum race_banner_mode { BANNER_INIT, BANNER_GROW, BANNER_SHRINK, BANNER_SHOW };
extern NJS_TEXLIST highway_eggmobile_texlist;
extern NJS_OBJECT highway_eggmobile_object;
extern NJS_OBJECT highway_eggmobile_jets_object;
static void race_start(struct task *task);
static void race_step(struct task *task);
static void FUN_8c07f8aa(struct task_work *work, struct task_work *sonic,
                             struct task_work *player);
static void race_run(struct task *task, struct task_work *sonic,
                     struct task_work *player);
static void FUN_8c07f994(struct task_work *work, struct task_work *sonic,
                              struct task_work *player);
static void race_start_sky_deck(struct task_work *work, struct task_work *sonic,
                                struct task_work *player);
static void race_start_casino(struct task_work *work, struct task_work *sonic,
                              struct task_work *player);
static void race_eggman_start(struct task *task);
static void FUN_8c07fbb0(struct task *task);
static void race_eggman_init(struct task *task, struct race_eggman *eggman);
static void FUN_8c07fd3e(struct task *task, struct race_eggman *eggman);
static void FUN_8c07feae(Sint16 point);
static void race_eggman_place(struct task_work *work, Sint16 point,
                              struct race_eggman *eggman);
static void race_set_lines(void);
static void race_set_lasts(struct task_work *work);
static Sint16 race_player_point(struct task_work *work,
                                struct task_work *player);
static Sint16 race_nearest_point(NJS_POINT3 *pos,
                                 const struct race_point *point, Sint16 count);
static Sint16 FUN_8c0800a0(struct task_work *work, struct task_work *sonic,
                               struct race_aim *aim);
static void FUN_8c080480(struct task_work *work, struct task_work *sonic,
                             struct race_aim *aim);
static void FUN_8c080ba8(struct task_work *sonic, NJS_POINT3 *to, int steps);
static Bool race_sonic_fly(struct task_work *sonic);
static Bool race_sonic_near_across(struct race_aim *aim);
static Angle race_sonic_heading(struct task_work *work, struct task_work *sonic,
                                struct race_aim *aim);
static Float race_stroke(NJS_VECTOR *ahead, Float reach, Float most);
static Bool race_sonic_stuck(struct task_work *sonic);
static Float race_sonic_stroke(struct race_aim *aim);
static Sint16 race_sonic_next(struct task_work *work, struct task_work *sonic,
                              struct race_aim *aim, Sint16 point);
static void race_eggman_draw(struct task *task);
static void race_eggman_spark(struct task *task, struct race_spark *spark);
static void race_eggman_glare(struct task *task);
static Sint16 race_eggman_reach(struct task_work *work,
                                struct race_eggman *eggman);
static void race_eggman_steer(struct task_work *work,
                              struct race_eggman *eggman);
static void FUN_8c08139e(struct task_work *work,
                             struct race_eggman *eggman);
static void race_eggman_bob(struct task_work *work, struct race_eggman *eggman);
static void FUN_8c081442(struct task *task, Sint16 player_point,
                            Sint16 racer_point);
static void race_say(struct race_voices *voices, enum race_saying say);
static Bool FUN_8c081634(void);
static void race_texture_destroy(struct task *task);
static void race_draw_bar(Float player, Float player_last, Float racer,
                          Float racer_last);
static void race_banner_draw(struct task *task);
extern enum race_outcome race_result;
extern enum course race_course;
extern struct jump race_leap;
extern NJS_SPRITE race_sprite;
extern const struct race_point *race_player_line;
extern const struct race_point *race_racer_line;
extern Sint32 dat_8c7a142c[3];
extern struct race_eggman race_eggman;
extern struct race_aim race_aim;
extern Sint32 dat_8c7a14a0;
extern Float race_sonic_pace;
extern Float race_eggman_top_speed;
extern Float race_eggman_turn_speed;
extern const struct race_point race_windy_points[249];
extern const Sint32 race_windy_count;
extern const struct race_point race_highway_points[256];
extern const Sint32 race_highway_count;
extern const struct race_point race_icecap_points[255];
extern const Sint32 race_icecap_count;
extern const struct race_point race_casino_points[99];
extern const Sint32 race_casino_count;
extern const Sint32 race_sticks[4];
extern const int race_sonic_voices[16];
extern const int race_eggman_voices[16];
extern NJS_TEXNAME race_textures[12];
extern NJS_TEXLIST milesrace_texlist;
extern NJS_TEXANIM race_sprites[12];
extern const struct race_point *race_lines[COURSE_COUNT * 2];
extern const Sint32 *race_counts[COURSE_COUNT * 2];
extern struct dust_params race_spark_params;
extern struct race_spark race_sparks[3];
extern NJS_POINT3 race_glare_from;
extern NJS_POINT3 race_glare_to;
extern struct collision_shape race_eggman_shape[1];
extern Bool race_mission_a;
void race_create(Uint16 character, Sint16 player, Sint16 stage)
{
    struct task *task;
    if (character != 2) {
        return;
    }
    if (player != 1) {
        return;
    }
    race_result = RACE_RUNNING;
    race_mission_a = FUN_8c081634();
    switch (stage) {
    case 2:
        if ((Uint8)GetStageNumber() == 2) {
            race_set_course(COURSE_WINDY);
            CreateElementalTask(0x8 | 0x2, 0, race_start);
            task = CreateElementalTask(0x1 | 0x2 | 0x4, 1,
                               sonic_step);
            ((struct player_vars *)&(task->work)->vars)->character = 0;
            ((struct player_vars *)&(task->work)->vars)->player = 1;
            task->work->id = 2;
            PadReadOffP(1);
        }
        break;
    case 4:
        if ((Uint8)GetStageNumber() == 0) {
            race_set_course(COURSE_HIGHWAY);
            CreateElementalTask(0x8 | 0x2, 0, race_eggman_start);
        }
        break;
    case 6:
        if ((Uint8)GetStageNumber() == 0) {
            race_set_course(COURSE_SKY_DECK);
            CreateElementalTask(0x8 | 0x2, 0, race_start);
            task = CreateElementalTask(0x1 | 0x2 | 0x4, 1,
                               sonic_step);
            ((struct player_vars *)&(task->work)->vars)->character = 0;
            ((struct player_vars *)&(task->work)->vars)->player = 1;
            task->work->id = 2;
            PadReadOffP(1);
        }
        break;
    case 8:
        if ((Uint8)GetStageNumber() == 2) {
            if (game_mode == GAME_MODE_TRIAL &&
                AdvertiseWork.trial[0] == 1) {
                return;
            }
            race_set_course(COURSE_ICECAP);
            CreateElementalTask(0x8 | 0x2, 0, race_start);
            task = CreateElementalTask(0x1 | 0x2 | 0x4, 1,
                               sonic_step);
            ((struct player_vars *)&(task->work)->vars)->character = 0;
            ((struct player_vars *)&(task->work)->vars)->player = 1;
            task->work->id = 2;
            PadReadOffP(1);
        }
        break;
    case 9:
        if ((Uint8)GetStageNumber() != 1) {
            break;
        }
        race_set_course(COURSE_CASINO);
        CreateElementalTask(0x8 | 0x2, 0, race_start);
        task = CreateElementalTask(0x1 | 0x2 | 0x4, 1, sonic_step);
        ((struct player_vars *)&(task->work)->vars)->character = 0;
        ((struct player_vars *)&(task->work)->vars)->player = 1;
        task->work->id = 2;
        PadReadOffP(1);
        break;
    }
}
static void race_start(struct task *task)
{
    struct task_work *work = task->work;
    ((struct player_vars *)&(task->work)->vars)->character = 0;
    ((struct player_vars *)&(task->work)->vars)->player = 1;
    race_set_lines();
    race_set_lasts(work);
    if (race_mission_a == (1)) {
        race_sonic_pace = 1.0F;
        trial_count = 1;
    } else {
        race_sonic_pace = 0.6F;
    }
    task->step = race_step;
}
static void race_step(struct task *task)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    struct task_work *sonic = playertwp[1];
    int i;
    if (player == ((void *)0) || sonic == ((void *)0)) {
        FreeTask(task);
        return;
    }
    if (sonic != ((void *)0)) {
        for (i = 0; i < sonic->collision->count; i++) {
            sonic->collision->shapes[i].levels &= ~0x20;
        }
    }
    switch (race_course) {
    case COURSE_WINDY:
        switch (work->mode) {
        case RACE_START:
            FUN_8c07f8aa(work, sonic, player);
            break;
        case RACE_RUN:
            race_run(task, sonic, player);
            break;
        case RACE_OVER:
            break;
        }
        break;
    case COURSE_HIGHWAY:
        break;
    case COURSE_ICECAP:
        switch (work->mode) {
        case RACE_START:
            FUN_8c07f994(work, sonic, player);
            break;
        case RACE_RUN:
            race_run(task, sonic, player);
            break;
        case 3:
            break;
        }
        break;
    case COURSE_SKY_DECK:
        switch (work->mode) {
        case RACE_START:
            race_start_sky_deck(work, sonic, player);
            break;
        case RACE_RUN:
            race_run(task, sonic, player);
            break;
        case RACE_OVER:
            break;
        }
        break;
    case COURSE_CASINO:
        switch (work->mode) {
        case RACE_START:
            race_start_casino(work, sonic, player);
            break;
        case RACE_RUN:
            race_run(task, sonic, player);
            break;
        case RACE_OVER:
            break;
        }
        break;
    default:
        FreeTask(task);
        return;
    }
    race_draw_bar(((struct race_vars *)&(work)->vars)->point[0], ((struct race_vars *)&(work)->vars)->last[0],
                  ((struct race_vars *)&(work)->vars)->point[1], ((struct race_vars *)&(work)->vars)->last[1]);
}
static void FUN_8c07f8aa(struct task_work *work, struct task_work *sonic,
                             struct task_work *player)
{
    work->mode = RACE_RUN;
    sonic->ang = player->ang;
    VecTemp0.x = 0.0F;
    VecTemp0.y = 1.0F;
    VecTemp0.z = 10.0F;
    player_turn_to_world(player, &VecTemp0);
    vector_add(&player->pos, &VecTemp0, &sonic->pos);
    ((struct race_vars *)&(work)->vars)->point[0] =
        race_nearest_point(&player->pos, race_player_line, ((struct race_vars *)&(work)->vars)->last[0]);
    ((struct race_vars *)&(work)->vars)->point[1] =
        race_nearest_point(&sonic->pos, race_racer_line, ((struct race_vars *)&(work)->vars)->last[1]);
    FUN_8c07feae(((struct race_vars *)&(work)->vars)->point[0]);
}
static void race_run(struct task *task, struct task_work *sonic,
                     struct task_work *player)
{
    struct task_work *work = task->work;
    struct race_aim *aim = &race_aim;
    Sint16 player_point;
    Sint16 racer_point;
    vector_between(&sonic->collision->shapes->center, &aim->to, &aim->ahead);
    aim->distance = njScalor2(&aim->ahead);
    player_point = race_player_point(work, player);
    racer_point = FUN_8c0800a0(work, sonic, aim);
    FUN_8c080480(work, sonic, aim);
    FUN_8c081442(task, player_point, racer_point);
    ((struct race_vars *)&(work)->vars)->point[0] = player_point;
    ((struct race_vars *)&(work)->vars)->point[1] = racer_point;
}
static void FUN_8c07f994(struct task_work *work, struct task_work *sonic,
                              struct task_work *player)
{
    const struct race_point *point = race_racer_line;
    struct race_aim *aim = &race_aim;
    struct task *board;
    NJS_VECTOR *offset;
    Sint32 *word;
    int i;
    work->mode = RACE_RUN;
    SetInputP(1, 44);
    sonic->ang = player->ang;
    offset = &VecTemp0;
    offset->x = 0.0F;
    offset->y = 1.0F;
    offset->z = 10.0F;
    player_turn_to_world(player, offset);
    sonic->pos.x = player->pos.x + offset->x;
    sonic->pos.y = player->pos.y + offset->y;
    sonic->pos.z = player->pos.z + offset->z;
    board = CreateElementalTask(0x2 | 0x1, 2, sonic_board_start);
    board->work->vars.b[0] = 1;
    word = (Sint32 *)aim;
    for (i = sizeof(*aim) / sizeof(*word); i != 0; i--) {
        *word++ = 0;
    }
    aim->from = point->pos;
    point++;
    aim->to = point->pos;
    aim->attr = point->attr;
}
static void race_start_sky_deck(struct task_work *work, struct task_work *sonic,
                                struct task_work *player)
{
    work->mode = RACE_RUN;
    sonic->ang = player->ang;
    VecTemp0.x = 0.0F;
    VecTemp0.y = 1.0F;
    VecTemp0.z = 10.0F;
    player_turn_to_world(player, &VecTemp0);
    vector_add(&player->pos, &VecTemp0, &sonic->pos);
    ((struct race_vars *)&(work)->vars)->point[0] =
        race_nearest_point(&player->pos, race_player_line, ((struct race_vars *)&(work)->vars)->last[0]);
    ((struct race_vars *)&(work)->vars)->point[1] =
        race_nearest_point(&sonic->pos, race_racer_line, ((struct race_vars *)&(work)->vars)->last[1]);
    FUN_8c07feae(((struct race_vars *)&(work)->vars)->point[0]);
}
static void race_start_casino(struct task_work *work, struct task_work *sonic,
                              struct task_work *player)
{
    work->mode = RACE_RUN;
    sonic->ang = player->ang;
    VecTemp0.x = 0.0F;
    VecTemp0.y = 1.0F;
    VecTemp0.z = 10.0F;
    player_turn_to_world(player, &VecTemp0);
    vector_add(&player->pos, &VecTemp0, &sonic->pos);
    ((struct race_vars *)&(work)->vars)->point[0] =
        race_nearest_point(&player->pos, race_player_line, ((struct race_vars *)&(work)->vars)->last[0]);
    ((struct race_vars *)&(work)->vars)->point[1] =
        race_nearest_point(&sonic->pos, race_racer_line, ((struct race_vars *)&(work)->vars)->last[1]);
    FUN_8c07feae(((struct race_vars *)&(work)->vars)->point[0]);
}
static void race_eggman_start(struct task *task)
{
    struct task_work *work = task->work;
    race_set_lines();
    race_set_lasts(work);
    race_set_lasts(work);
    task->step = FUN_8c07fbb0;
    task->draw = race_eggman_draw;
}
static void FUN_8c07fbb0(struct task *task)
{
    struct task_work *work = task->work;
    struct race_eggman *eggman = &race_eggman;
    struct task_work *player = playertwp[0];
    if (player == ((void *)0)) {
        FreeTask(task);
        return;
    }
    switch (work->mode) {
    case RACE_START:
        race_eggman_init(task, eggman);
    case RACE_RUN:
        FUN_8c07fd3e(task, eggman);
        break;
    case RACE_OVER:
        race_eggman_bob(work, eggman);
        break;
    }
    EntryColliList(work);
    object_step_draw(task);
    race_eggman_spark(task, &race_sparks[0]);
    race_eggman_spark(task, &race_sparks[1]);
    race_eggman_spark(task, &race_sparks[2]);
    race_eggman_glare(task);
    race_draw_bar(((struct race_vars *)&(work)->vars)->point[0], ((struct race_vars *)&(work)->vars)->last[0],
                  ((struct race_vars *)&(work)->vars)->point[1], ((struct race_vars *)&(work)->vars)->last[1]);
}
static void race_eggman_init(struct task *task, struct race_eggman *eggman)
{
    struct task_work *work = task->work;
    struct task_work *player = GetPlayerTaskPointer(0)->work;
    work->mode = RACE_RUN;
    if (race_mission_a == (1)) {
        race_eggman_top_speed = 3.5F;
        race_eggman_turn_speed = 2.2F;
        trial_count = 1;
    } else {
        race_eggman_top_speed = 2.0F;
        race_eggman_turn_speed = 0.08F;
    }
    ((struct race_vars *)&(work)->vars)->point[0] =
        race_nearest_point(&player->pos, race_player_line, ((struct race_vars *)&(work)->vars)->last[0]);
    ((struct race_vars *)&(work)->vars)->point[1] =
        race_nearest_point(&player->pos, race_racer_line, ((struct race_vars *)&(work)->vars)->last[1]);
    race_eggman_place(work, ((struct race_vars *)&(work)->vars)->point[1], eggman);
    CCL_Init(task, race_eggman_shape, 4, 1, 1);
}
static void FUN_8c07fd3e(struct task *task, struct race_eggman *eggman)
{
    struct task_work *work = task->work;
    struct task_work *player = playertwp[0];
    const NJS_POINT3 *end = &race_player_line[((struct race_vars *)&(work)->vars)->last[0]].pos;
    Sint16 player_point;
    Sint16 eggman_point;
    Float distance;
    vector_between(&player->pos, end, &VecTemp0);
    distance = njScalor2(&VecTemp0);
    if (distance < (150.0F * 150.0F)) {
        work->mode = RACE_OVER;
        race_set_won();
        SetFinishAction();
        return;
    }
    vector_between(&work->pos, end, &VecTemp0);
    distance = njScalor2(&VecTemp0);
    if (distance < (150.0F * 150.0F)) {
        work->mode = RACE_OVER;
        race_set_lost();
        SetFinishAction();
        return;
    }
    player_point = race_player_point(work, player);
    eggman_point = race_eggman_reach(work, eggman);
    race_eggman_steer(work, eggman);
    race_eggman_bob(work, eggman);
    FUN_8c08139e(work, eggman);
    FUN_8c081442(task, player_point, eggman_point);
    ((struct race_vars *)&(work)->vars)->point[1] = eggman_point;
    ((struct race_vars *)&(work)->vars)->point[0] = player_point;
}
static void FUN_8c07feae(Sint16 point)
{
    const struct race_point *from = &race_racer_line[point];
    struct race_aim *aim = &race_aim;
    Sint32 *word;
    int i;
    word = (Sint32 *)aim;
    for (i = sizeof(*aim) / sizeof(*word); i != 0; i--) {
        *word++ = 0;
    }
    aim->from = from->pos;
    from++;
    aim->to = from->pos;
    aim->attr = from->attr;
}
static void race_eggman_place(struct task_work *work, Sint16 point,
                              struct race_eggman *eggman)
{
    const struct race_point *from = &race_racer_line[point];
    Sint32 *word;
    int i;
    word = (Sint32 *)eggman;
    for (i = sizeof(*eggman) / sizeof(*word); i != 0; i--) {
        *word++ = 0;
    }
    vector_copy(&from->pos.x, &work->pos.x);
    vector_copy(&from->pos.x, &eggman->from.x);
    from++;
    vector_copy(&from->pos.x, &eggman->to.x);
}
static void race_set_lines(void)
{
    const struct race_point **line = &race_lines[race_course * 2];
    race_player_line = *line++;
    race_racer_line = *line;
}
static void race_set_lasts(struct task_work *work)
{
    const Sint32 **count = &race_counts[race_course * 2];
    ((struct race_vars *)&(work)->vars)->last[0] = **count++ - 1;
    ((struct race_vars *)&(work)->vars)->last[1] = **count - 1;
}
static Sint16 race_player_point(struct task_work *work,
                                struct task_work *player)
{
    if (loop_count != 0) {
        return ((struct race_vars *)&(work)->vars)->point[0];
    }
    return race_nearest_point(&player->pos, race_player_line,
                              ((struct race_vars *)&(work)->vars)->last[0]);
}
static Sint16 race_nearest_point(NJS_POINT3 *pos,
                                 const struct race_point *point, Sint16 count)
{
    int i;
    int nearest;
    Float best;
    Float distance;
    best = 100000000.0F;
    for (i = 0, nearest = 0; i < count; i++) {
        VecTemp0.x = pos->x - point->pos.x;
        VecTemp0.y = pos->y - point->pos.y;
        VecTemp0.z = pos->z - point->pos.z;
        distance = njScalor2(&VecTemp0);
        if (distance < best) {
            best = distance;
            nearest = i;
        }
        point++;
    }
    return nearest;
}
static Sint16 FUN_8c0800a0(struct task_work *work, struct task_work *sonic,
                               struct race_aim *aim)
{
    Sint16 point = ((struct race_vars *)&(work)->vars)->point[1];
    Sint16 next;
    Float dot;
    Float across;
    int behind;
    Sint32 wait;
    int steps;
    switch (((Uint8)(aim->attr))) {
    case POINT_COAST_NEAR:
    case POINT_DASH_NEAR:
        if (aim->distance < (5.0F * 5.0F)) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_PUSH:
        across = (aim->ahead.x * aim->ahead.x) + (aim->ahead.z * aim->ahead.z);
        if (across < (5.0F * 5.0F)) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_DASH:
    case POINT_COAST:
    case POINT_PATH:
    case POINT_AIR:
        vector_between(&aim->from, &aim->to, &VecTemp0);
        dot = njInnerProduct(&aim->ahead, &VecTemp0);
        if (dot <= 0.0F) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_RUN:
    case POINT_EASE:
    case POINT_SPIN_UP:
        vector_between(&aim->from, &aim->to, &VecTemp0);
        dot = njInnerProduct(&aim->ahead, &VecTemp0);
        if (dot <= 0.001F || aim->distance < (5.0F * 5.0F)) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_RUN_LEVEL:
        vector_between(&aim->from, &aim->to, &VecTemp0);
        VecTemp0.y = 0.0F;
        scratch_vector2 = aim->ahead;
        scratch_vector2.y = 0.0F;
        dot = njInnerProduct(&scratch_vector2, &VecTemp0);
        if (dot <= 0.001F || aim->distance < (5.0F * 5.0F)) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_REQUESTED:
        if (sonic->flags & 0x1000) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_LAUNCHED:
        if (sonic->submode == 4 ||
            sonic->submode == 3 ||
            sonic->submode == 25) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_LEDGE:
        if (sonic->submode == 31) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_LAND:
        if (sonic->flags & (0x1 | 0x2)) {
            point = race_sonic_next(work, sonic, aim, point);
        }
        break;
    case POINT_BOARD:
        vector_between(&aim->from, &aim->to, &VecTemp0);
        dot = njInnerProduct(&aim->ahead, &VecTemp0);
        if (dot <= 0.001F || aim->distance < (5.0F * 5.0F)) {
            point = race_sonic_next(work, sonic, aim, point);
            if (aim->attr & 0x08000000) {
                SetInputP(1, 24);
                PadReadOffP(1);
            }
        }
        break;
    case POINT_WAIT:
        if (((struct race_vars *)&(work)->vars)->point[0] > point || race_mission_a == (1)) {
            point = race_sonic_next(work, sonic, aim, point);
            break;
        }
        wait = aim->attr & ((0xf) << 20);
        if (wait != 0) {
            wait >>= 20;
            if (((struct race_vars *)&(work)->vars)->steps > wait * 120) {
                point = race_sonic_next(work, sonic, aim, point);
                break;
            }
        }
    case POINT_GOAL:
        break;
    }
    if (point == ((struct race_vars *)&(work)->vars)->point[1]) {
        steps = ((struct race_vars *)&(work)->vars)->steps++;
        if (((Uint8)(aim->attr)) == POINT_BOARD && steps > 180) {
            if (((struct race_vars *)&(work)->vars)->point[0] - ((struct race_vars *)&(work)->vars)->point[1] < 20) {
                perG[1].press |= pad_jump_buttons;
            } else {
                point = race_sonic_next(work, sonic, aim, point);
                sonic->pos = aim->from;
            }
        }
    }
    behind = race_mission_a == (1) ? 20 : 40;
    if (aim->distance > (1000.0F * 1000.0F) || ((struct race_vars *)&(work)->vars)->point[0] - point > behind) {
        next = race_sonic_next(work, sonic, aim, point);
        SetPositionP(1, aim->from.x, aim->from.y + 5.0F,
                            aim->from.z);
        if (((Uint8)(aim->attr)) != POINT_BOARD) {
            SetInputP(1, 24);
        }
        return next;
    }
    return point;
}
static void race_set_stick(PDS_PERIPHERAL *pad, Sint32 stick)
{
    pad->x1 = stick >> 16;
    pad->y1 = stick;
}
static void FUN_8c080480(struct task_work *work, struct task_work *sonic,
                             struct race_aim *aim)
{
    NJS_VECTOR *ahead = &aim->ahead;
    struct player *record = GetPlayerWorkPointer(1);
    struct task_work *player;
    Float level;
    Float speed;
    Float dot;
    Float push;
    int lead;
    Bool restart;
    switch (((Uint8)(aim->attr))) {
    case POINT_RUN:
    case POINT_RUN_LEVEL:
        input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
        input_dataG[1].stroke = race_sonic_stroke(aim);
        level = -njInnerProduct(&vG, &record->ground_normal);
        if (level > njCos(((Angle)(((45) * 65536.0) / 360.0))) && level < njCos(((Angle)(((25) * 65536.0) / 360.0)))) {
            speed = record->speed.x;
            if (aim->speed > speed && speed < 0.1F &&
                njScalor(&record->speed) < 0.1F) {
                aim->resume = aim->attr;
                aim->attr = POINT_SPIN_UP;
                perG[1].press |= pad_action_buttons;
                ((struct race_vars *)&(work)->vars)->spin_steps = 0;
            }
        }
        if (race_sonic_stuck(sonic)) {
            FUN_8c080ba8(sonic, &aim->to, 60);
            aim->attr = POINT_LEAP;
        }
        break;
    case POINT_DASH:
    case POINT_DASH_NEAR:
        input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
        input_dataG[1].stroke = 1.0F;
        if (race_sonic_stuck(sonic)) {
            FUN_8c080ba8(sonic, &aim->to, 60);
            aim->attr = POINT_LEAP;
        }
        break;
    case POINT_EASE:
        input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
        input_dataG[1].stroke = race_stroke(ahead, 40.0F, 0.6F);
        break;
    case POINT_AIR:
        if (!(sonic->flags & (0x1 | 0x2))) {
            input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
            input_dataG[1].stroke = race_stroke(ahead, 40.0F, 0.6F);
        }
        break;
    case POINT_LAUNCHED:
    case POINT_REQUESTED:
        input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
        input_dataG[1].stroke = race_stroke(ahead, 40.0F, 1.0F);
        if (race_sonic_stuck(sonic) && (sonic->flags & (0x1 | 0x2))) {
            FUN_8c080ba8(sonic, &aim->to, 60);
            aim->attr = POINT_LEAP;
        }
        break;
    case POINT_PUSH:
        race_set_stick(&perG[1], race_sticks[(((aim->attr) >> 30) & 3)]);
        break;
    case POINT_LEDGE:
        input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
        input_dataG[1].stroke = race_stroke(ahead, 40.0F, race_sonic_pace);
        if (race_sonic_near_across(aim)) {
            if (sonic->flags & (0x1 | 0x2)) {
                perG[1].press |= pad_jump_buttons;
            }
        }
        break;
    case POINT_SPIN_UP:
        input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
        input_dataG[1].stroke = 1.0F;
        if (((struct race_vars *)&(work)->vars)->spin_steps++ > 60) {
            aim->attr = aim->resume;
        } else {
            perG[1].on |= pad_action_buttons;
        }
        break;
    case POINT_PATH:
        if (sonic->flags & 0x2000) {
            race_set_stick(&perG[1],
                           race_sticks[(((aim->attr) >> 30) & 3)]);
        } else {
            input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
            input_dataG[1].stroke = race_sonic_stroke(aim);
        }
        break;
    case POINT_LEAP:
        if (race_sonic_fly(sonic)) {
            aim->attr = aim->resume;
        }
        break;
    case POINT_WAIT:
        switch (work->submode) {
        case WAIT_ARRIVE:
            input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
            input_dataG[1].stroke = race_stroke(ahead, 40.0F, 0.6F);
            vector_between(&aim->from, &aim->to, &VecTemp0);
            dot = njInnerProduct(&aim->ahead, &VecTemp0);
            if (dot <= 0.0F || aim->distance < (5.0F * 5.0F)) {
                work->submode = WAIT_READY;
                SetInputP(1, 34);
            }
            break;
        case WAIT_READY:
            if ((*(Uint16 *)&(work)->timer)++ > 300) {
                SetInputP(1, 34);
                (*(Uint16 *)&(work)->timer) = 0;
            }
            break;
        }
        break;
    case POINT_BOARD:
        input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
        input_dataG[1].stroke = race_sonic_stroke(aim);
        lead = ((struct race_vars *)&(work)->vars)->point[0] - ((struct race_vars *)&(work)->vars)->point[1];
        if (!race_mission_a) {
            if (lead > 0 && ((struct race_vars *)&(work)->vars)->point[1] < 210) {
                VecTemp0 = aim->ahead;
                VecTemp0.y = 0.0F;
                vector_normalize(&VecTemp0);
                if (lead > 6) {
                    push = 0.2F;
                } else if (lead > 3) {
                    push = 0.1F;
                } else {
                    push = 0.05F;
                }
                player_set_accel(1, VecTemp0.x * push, -push,
                                 VecTemp0.z * push);
            }
        } else {
            VecTemp0 = aim->ahead;
            VecTemp0.y = 0.0F;
            vector_normalize(&VecTemp0);
            push = 0.05F;
            player_set_accel(1, VecTemp0.x * push, -push,
                             VecTemp0.z * push);
        }
        break;
    case POINT_GOAL:
        switch (work->submode) {
        case GOAL_ARRIVE:
            if (race_outcome() != RACE_RUNNING) {
                work->submode = GOAL_DONE;
            } else {
                work->submode = GOAL_JUMP;
                perG[1].press |= pad_jump_buttons_signed;
                aim->jumps = 0;
            }
            break;
        case GOAL_JUMP:
            input_dataG[1].ang = race_sonic_heading(work, sonic, aim);
            input_dataG[1].stroke = race_stroke(ahead, 40.0F, 0.6F);
            perG[1].on |= pad_jump_buttons_signed;
            if (sonic->flags & (0x1 | 0x2)) {
                work->submode = GOAL_LANDED;
                (*(Uint16 *)&(work)->timer) = 0;
            }
            break;
        case GOAL_LANDED:
            if (race_outcome() != RACE_RUNNING) {
                player = playertwp[0];
                vector_between(&player->pos, &sonic->pos, &VecTemp0);
                if (njScalor2(&VecTemp0) < (5.0F * 5.0F)) {
                    player_set_accel(1, VecTemp0.x, VecTemp0.y,
                                     VecTemp0.z);
                }
                return;
            }
            if ((*(Uint16 *)&(work)->timer)++ > 32) {
                work->submode = GOAL_JUMP;
                perG[1].press |= pad_jump_buttons;
                if (aim->jumps++ > 3) {
                    work->submode = GOAL_LEAP;
                    VecTemp0 = aim->to;
                    VecTemp0.y += 45.0F;
                    FUN_8c080ba8(sonic, &VecTemp0, 60);
                }
            }
            break;
        case GOAL_LEAP:
            if (race_sonic_fly(sonic)) {
                work->submode = GOAL_FALL;
            }
            break;
        case GOAL_FALL:
            if (sonic->flags & (0x1 | 0x2)) {
                work->submode = GOAL_LANDED;
                (*(Uint16 *)&(work)->timer) = 0;
            }
            break;
        case GOAL_DONE:
            break;
        }
        break;
    }
    restart = (0);
    switch (((Uint8)(aim->attr))) {
    case POINT_RUN:
    case POINT_RUN_LEVEL:
    case POINT_LAUNCHED:
        if (((struct race_vars *)&(work)->vars)->steps > 420) {
            restart = (1);
        }
        break;
    case POINT_EASE:
    case POINT_LAND:
    case POINT_SPIN_UP:
    case POINT_PATH:
    case POINT_GOAL:
        if (((struct race_vars *)&(work)->vars)->steps > 600) {
            restart = (1);
        }
        break;
    case POINT_PUSH:
    case POINT_LEDGE:
        if (((struct race_vars *)&(work)->vars)->steps > 900) {
            restart = (1);
        }
        break;
    case POINT_COAST_NEAR:
    case POINT_DASH:
    case POINT_COAST:
    case POINT_REQUESTED:
        if (((struct race_vars *)&(work)->vars)->steps > 1200) {
            restart = (1);
        }
        break;
    case POINT_AIR:
        if ((sonic->flags & (0x1 | 0x2)) ||
            ((struct race_vars *)&(work)->vars)->steps > 1200) {
            restart = (1);
        }
        break;
    case POINT_LEAP:
        break;
    }
    if (restart) {
        ((struct race_vars *)&(work)->vars)->steps = 0;
        FUN_8c080ba8(sonic, &aim->to, 60);
        aim->attr = POINT_LEAP;
    }
    aim->speed = record->speed.x;
}
static void FUN_8c080ba8(struct task_work *sonic, NJS_POINT3 *to, int steps)
{
    struct jump *leap = &race_leap;
    struct player *record = GetPlayerWorkPointer(1);
    race_aim.resume = race_aim.attr;
    SetInputP(1, 13);
    leap->pos = sonic->pos;
    leap->target = *to;
    leap->gravity = record->consts.gravity;
    leap->steps = steps;
    jump_aim(leap);
    collision_shapes_off(sonic);
}
static Bool race_sonic_fly(struct task_work *sonic)
{
    struct jump *leap = &race_leap;
    enum jump_state state;
    SetPositionP(1, sonic->pos.x + leap->speed.x,
                        sonic->pos.y + leap->speed.y,
                        sonic->pos.z + leap->speed.z);
    leap->speed.y -= leap->gravity;
    if (leap->speed.y < 0.0F) {
        collision_shapes_on(sonic);
    }
    state = jump_landed(leap);
    if (state == JUMP_FLYING) {
        return (0);
    }
    SetInputP(1, 24);
    if (state == JUMP_OFF_TARGET) {
        SetPositionP(1, leap->target.x, leap->target.y, leap->target.z);
    }
    return (1);
}
static Bool race_sonic_near_across(struct race_aim *aim)
{
    Float across =
        (aim->ahead.x * aim->ahead.x) + (aim->ahead.z * aim->ahead.z);
    return across < (5.0F * 5.0F);
}
static Angle race_sonic_heading(struct task_work *work, struct task_work *sonic,
                                struct race_aim *aim)
{
    Angle last = aim->heading;
    Angle ang;
    Float along;
    Float front;
    Sint16 next;
    ang =
        (Angle)(njArcTan2(aim->ahead.z, aim->ahead.x) * (65536.0 / (2 * 3.141592))) & 0xffff;
    if (((Uint8)(aim->attr)) == POINT_RUN &&
        (sonic->flags & (0x1 | 0x2))) {
        next = ((struct race_vars *)&(work)->vars)->point[1] + 2;
        if (next <= ((struct race_vars *)&(work)->vars)->last[1]) {
            VecTemp0.x = 1.0F;
            VecTemp0.y = 0.0F;
            VecTemp0.z = 0.0F;
            player_turn_to_world(sonic, &VecTemp0);
            vector_between(&aim->from, &aim->to, &scratch_vector2);
            along = njInnerProduct(&VecTemp0, &scratch_vector2);
            scratch_vector3 = aim->ahead;
            scratch_vector3.y = 0.0F;
            front = njInnerProduct(&VecTemp0, &scratch_vector3);
            if (along > 0.0F && front < 0.0F) {
                ang = last;
            }
        }
    }
    aim->heading = ang;
    return ang;
}
static Float race_stroke(NJS_VECTOR *ahead, Float reach, Float most)
{
    Float across = njSqrt((ahead->x * ahead->x) + (ahead->z * ahead->z));
    Float stroke;
    if (across > reach) {
        across = reach;
    }
    stroke = most * across / reach;
    if (stroke < 0.2F) {
        stroke = 0.2F;
    }
    return stroke;
}
static Bool race_sonic_stuck(struct task_work *sonic)
{
    struct race_aim *aim = &race_aim;
    NJS_POINT3 pos;
    if (aim->attr & 0x01000000) {
        return (0);
    }
    GetPlayerPosition(1, 120, &pos, ((void *)0));
    vector_between(&pos, &sonic->pos, &VecTemp0);
    if (njScalor2(&VecTemp0) < (5.0F * 5.0F)) {
        return (1);
    }
    return (0);
}
static Float race_sonic_stroke(struct race_aim *aim)
{
    if (aim->attr & 0x04000000) {
        return 1.0F;
    } else if (aim->attr & 0x02000000) {
        return 0.8F;
    } else {
        return race_sonic_pace;
    }
}
static Sint16 race_sonic_next(struct task_work *work, struct task_work *sonic,
                              struct race_aim *aim_arg, Sint16 point)
{
    Bool leap;
    Sint16 last;
    struct race_aim *aim;
    const struct race_point *next;
    point++;
    last = ((struct race_vars *)&(work)->vars)->last[1];
    aim = aim_arg;
    leap = (0);
    if (point >= last || ((Uint8)(aim->attr)) == POINT_GOAL) {
        return last;
    }
    work->submode = 0;
    (*(Uint16 *)&(work)->timer) = 0;
    ((struct race_vars *)&(work)->vars)->steps = 0;
    if (aim->attr & 0x20000000) {
        perG[1].press |= pad_jump_buttons;
    }
    if (aim->attr & 0x10000000) {
        leap = (1);
    }
    next = &race_racer_line[point];
    aim->from = next->pos;
    next++;
    aim->to = next->pos;
    aim->attr = next->attr;
    vector_between(&sonic->pos, &aim->to, &aim->ahead);
    aim->distance = njScalor2(&aim->ahead);
    aim->speed = 0.0F;
    if (leap == (1)) {
        FUN_8c080ba8(sonic, &aim->to, 60);
        aim->attr = POINT_LEAP;
    }
    return point;
}
#pragma inline(race_between)
static void race_between(Float *from, Float *to, Float *out)
{
    *out++ = *to++ - *from++;
    *out++ = *to++ - *from++;
    *out = *to - *from;
}
static void race_eggman_draw(struct task *task)
{
    struct task_work *work = task->work;
    njSetTexture(&highway_eggmobile_texlist);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    late_DrawObject(&highway_eggmobile_object);
    late_DrawObject(&highway_eggmobile_jets_object);
    njPopMatrix(1);
}
static void race_eggman_spark(struct task *task, struct race_spark *spark)
{
    struct task_work *work = task->work;
    NJS_POINT3 to;
    njPushMatrix(&nj_unit_matrix_);
    njTranslate(((void *)0), work->pos.x, work->pos.y, work->pos.z);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    njCalcPoint(((void *)0), &spark->from, &spark->params->pos);
    njCalcPoint(((void *)0), &spark->to, &to);
    njPopMatrix(1);
    race_between(&spark->params->pos.x, &to.x, &spark->params->speed.x);
    panlight_create(spark->params);
}
static void race_eggman_glare(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 pos;
    NJS_VECTOR dir;
    NJS_ARGB color;
    Float size;
    njPushMatrix(&nj_unit_matrix_);
    njTranslate(((void *)0), work->pos.x, work->pos.y, work->pos.z);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    njCalcPoint(((void *)0), &race_glare_from, &pos);
    njCalcPoint(((void *)0), &race_glare_to, &dir);
    njPopMatrix(1);
    race_between(&pos.x, &dir.x, &dir.x);
    vector_normalize(&dir);
    size = 0.6F;
    color.a = 0.6F;
    color.r = 0.5F;
    color.g = 0.7F;
    color.b = 1.0F;
    DrawHeadLight(&pos, &dir, size, &color);
}
static Sint16 race_eggman_reach(struct task_work *work,
                                struct race_eggman *eggman)
{
    Sint16 point = ((struct race_vars *)&(work)->vars)->point[1];
    Float dot;
    const struct race_point *next;
    vector_between(&eggman->from, &eggman->to, &VecTemp0);
    vector_between(&work->pos, &eggman->to, &scratch_vector2);
    dot = njInnerProduct(&VecTemp0, &scratch_vector2);
    if (dot <= 0.0F || njScalor2(&VecTemp0) < (5.0F * 5.0F)) {
        if (++point < ((struct race_vars *)&(work)->vars)->last[1]) {
            next = &race_racer_line[point];
            vector_copy(&next->pos.x, &eggman->from.x);
            next++;
            vector_copy(&next->pos.x, &eggman->to.x);
        }
    }
    return point;
}
static void race_eggman_steer(struct task_work *work,
                              struct race_eggman *eggman)
{
    struct angles aim;
    vector_between(&work->pos, &eggman->to, &VecTemp0);
    vector_normalize(&VecTemp0);
    scratch_vector2.x = VecTemp0.x * race_eggman_turn_speed;
    scratch_vector2.y = VecTemp0.y * race_eggman_turn_speed;
    scratch_vector2.z = VecTemp0.z * race_eggman_turn_speed;
    vector_add(&eggman->speed, &scratch_vector2, &scratch_vector3);
    if (njScalor(&scratch_vector3) > race_eggman_top_speed) {
        vector_aim_y(&scratch_vector3, &aim.x, &aim.z);
        njPushMatrix(&nj_unit_matrix_);
        ((aim.z) ? (njRotateZ)(((void *)0), (aim.z)) : (void)0);
        ((aim.x) ? (njRotateX)(((void *)0), (aim.x)) : (void)0);
        scratch_vector2.x = 0.0F;
        scratch_vector2.y = race_eggman_top_speed;
        scratch_vector2.z = 0.0F;
        njCalcVector(((void *)0), &scratch_vector2, &scratch_vector3);
        njPopMatrix(1);
    }
    vector_copy(&scratch_vector3.x, &eggman->speed.x);
    vector_add(&work->pos, &scratch_vector3, &work->pos);
}
static void FUN_8c08139e(struct task_work *work, struct race_eggman *eggman)
{
    Float dx;
    Float dz;
    Angle ang;
    work->ang.y =
        (Angle)(njArcTan2(eggman->speed.x, eggman->speed.z) * (65536.0 / (2 * 3.141592)));
    dx = eggman->to.x - work->pos.x;
    dz = eggman->to.z - work->pos.z;
    ang = (Angle)(njArcTan2(dx, dz) * (65536.0 / (2 * 3.141592)));
    ang = -ang + work->ang.y;
    work->ang.z = AdjustAngle(work->ang.z, ang, 0x40);
}
static void race_eggman_bob(struct task_work *work, struct race_eggman *eggman)
{
    Float bob = njSin(eggman->bob_phase) * 3.0F;
    work->pos.y -= eggman->bob;
    work->pos.y += bob;
    eggman->bob_phase += 0x400;
    eggman->bob = bob;
}
static void FUN_8c081442(struct task *task, Sint16 player_point,
                            Sint16 racer_point)
{
    struct task_work *work = task->work;
    struct race_voices *voices = ((struct race_voices *)(task)->extra);
    Sint16 player = ((struct race_vars *)&(work)->vars)->point[0];
    Sint16 *points = ((struct race_vars *)&(work)->vars)->point;
    Sint16 racer = points[1];
    Sint16 last_lead = player - racer;
    Sint16 lead = player_point - racer_point;
    voices->wait--;
    switch (voices->mode) {
    case VOICES_WAIT:
        if (racer_point >= 1) {
            voices->mode = VOICES_RACE;
            race_say(voices, SAY_START);
        }
        break;
    case VOICES_RACE:
        if (lead != last_lead && race_outcome() == RACE_RUNNING && lead != 0) {
            if (lead > 0) {
                if (lead == 1 && last_lead > 1) {
                    race_say(voices, SAY_RACER_CLOSES);
                } else if (last_lead <= 0) {
                    race_say(voices, SAY_LEADING);
                }
            } else {
                if (lead == -1 && last_lead < -1) {
                    race_say(voices, SAY_TAILS_CLOSES);
                } else if (last_lead >= 0) {
                    race_say(voices, SAY_TRAILING);
                } else if (lead < -8) {
                    race_say(voices, SAY_FAR_BEHIND);
                }
            }
        }
        break;
    }
}
static void race_say(struct race_voices *voices, enum race_saying say)
{
    int second = 0;
    const int *table;
    Sint32 *turns;
    int bit;
    if (voices->last == say) {
        return;
    }
    if (voices->wait > 0) {
        return;
    }
    voices->wait = 180;
    if ((Uint8)(GetStageNumber() >> 8) != 4) {
        table = race_sonic_voices;
    } else {
        table = race_eggman_voices;
    }
    bit = 1 << say;
    turns = &voices->turns;
    *turns ^= bit;
    if (voices->turns & bit) {
        second = 1;
    }
    Serif_Play(table[(say * 2) + second]);
    voices->last = say;
}
static Bool FUN_8c081634(void)
{
    Bool result = (0);
    int stage = (Uint8)(GetStageNumber() >> 8);
    if (emblem_check_mission(SaveData, 2, stage, MISSION_C) &&
        emblem_check_mission(SaveData, 2, stage, MISSION_B)) {
        result = (1);
    }
    return result;
}
void race_texture_step(struct task *task)
{
    struct task_work *work = task->work;
    ((struct race_texture_vars *)&(work)->vars)->texlist = &milesrace_texlist;
    texLoadTexturePvmFile("MILESRACE", ((struct race_texture_vars *)&(work)->vars)->texlist);
    task->step = object_idle;
    task->destructor = race_texture_destroy;
}
void race_eggman_texture_step(struct task *task)
{
    struct task_work *work = task->work;
    ((struct race_texture_vars *)&(work)->vars)->texlist = &highway_eggmobile_texlist;
    texLoadTexturePvmFile("MRACE_EGGMOBLE", ((struct race_texture_vars *)&(work)->vars)->texlist);
    task->step = object_idle;
    task->destructor = race_texture_destroy;
}
static void race_texture_destroy(struct task *task)
{
    struct task_work *work = task->work;
    njReleaseTexture(((struct race_texture_vars *)&(work)->vars)->texlist);
}
static void race_draw_bar(Float player, Float player_last, Float racer,
                          Float racer_last)
{
    if (0 > hud_hidden || 0 == loop_count) {
        return;
    }
    player = player * (255.0F / player_last);
    racer = racer * (255.0F / racer_last);
    njSetTexture(&milesrace_texlist);
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    race_sprite.tlist = &milesrace_texlist;
    race_sprite.tanim = race_sprites;
    race_sprite.sy = 1.0F;
    race_sprite.sx = 16.0F;
    race_sprite.p.x = 184.0F;
    race_sprite.p.y = 424.0F;
    late_DrawSprite2D(&race_sprite, 0, -2.004F, 0x20);
    race_sprite.sx = 1.0F;
    race_sprite.p.x = racer + 184.0F;
    race_sprite.p.y = 416.0F;
    if ((Uint8)(GetStageNumber() >> 8) == 4) {
        late_DrawSprite2D(&race_sprite, 11, -2.001F, 0x20);
    } else {
        late_DrawSprite2D(&race_sprite, 1, -2.001F, 0x20);
    }
    player = player + 184.0F;
    race_sprite.p.x = player;
    race_sprite.p.y = 416.0F;
    late_DrawSprite2D(&race_sprite, 2, -2.0F, 0x20);
}
void race_set_course(Sint32 course)
{
    race_course = course;
}
void race_set_won(void)
{
    race_result = RACE_WON;
}
void race_set_lost(void)
{
    race_result = RACE_LOST;
}
enum race_outcome race_outcome(void)
{
    return race_result;
}
void race_result_step(struct task *task)
{
    struct task_work *work = task->work;
    Float scale = ((struct race_banner_vars *)&(work)->vars)->scale;
    switch (work->mode) {
    case BANNER_INIT:
        work->mode = BANNER_GROW;
        if (race_result == RACE_WON) {
            ((struct race_banner_vars *)&(work)->vars)->sprite = 3;
        } else {
            ((struct race_banner_vars *)&(work)->vars)->sprite = 7;
        }
        ((struct race_banner_vars *)&(work)->vars)->scale = 0.5F;
        task->draw = race_banner_draw;
        break;
    case BANNER_GROW:
        scale += 0.25F;
        if (scale >= 4.0F) {
            work->mode = BANNER_SHRINK;
        }
        ((struct race_banner_vars *)&(work)->vars)->scale = scale;
        break;
    case BANNER_SHRINK:
        scale -= 0.25F;
        if (scale <= 2.0F) {
            work->mode = BANNER_SHOW;
            scale = 2.0F;
        }
        ((struct race_banner_vars *)&(work)->vars)->scale = scale;
        break;
    case BANNER_SHOW:
        break;
    }
    object_step_draw(task);
}
static void race_banner_draw(struct task *task)
{
    struct task_work *work = task->work;
    Float scale = ((struct race_banner_vars *)&(work)->vars)->scale;
    int sprite;
    int i;
    if (loop_count == 0) {
        return;
    }
    njSetTexture(&milesrace_texlist);
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    race_sprite.tlist = &milesrace_texlist;
    race_sprite.tanim = race_sprites;
    race_sprite.sx = scale;
    race_sprite.sy = scale;
    race_sprite.p.x = (640.0F / 2);
    race_sprite.p.y = (480.0F / 2);
    sprite = (int)((struct race_banner_vars *)&(work)->vars)->sprite;
    for (i = 0; i < 4; i++) {
        late_DrawSprite2D(&race_sprite, sprite++, -2.004F, 0x20);
    }
}
