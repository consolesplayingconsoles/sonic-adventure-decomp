/* @unit 8C047040-8C048B00 @data 8C1129E8-8C112A24 +r04 +egflags +pool32 */
/* Ported from the Japanese release's src/enemy/enemy.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
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
void late_DrawObjectClip(NJS_OBJECT *obj);
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
void *CAlloc(int count, int size);
void heap_free(void *mem);
void heap_stats(int *total, int *largest);
struct path;
enum camera_type {
    CAMERA_BY_STEP,
    CAMERA_FROM_TARGET,
    CAMERA_LOOK_AT,
    CAMERA_AT_ANGLES
};
struct camera_view {
    Sint16 ang_x;
    Sint16 ang_y;
    NJS_POINT3 pos;
    NJS_POINT3 target;
    Float distance;
    Sint32 steps;
};
struct camera_state {
    Uint8 view;
    Uint8 phase;
    Uint8 unk_02[4];
    Sint16 flags;
    Float distance;
    NJS_POINT3 pos;
    NJS_POINT3 target;
    Angle ang_x, ang_y, ang_z;
    Uint8 unk_30[12];
    Angle spin_x, spin_y, spin_z;
    NJS_VECTOR move;
};
enum camera_level {
    CAMERA_LEVEL_NORMAL,
    CAMERA_LEVEL_AREA,
    CAMERA_LEVEL_EVENT,
    CAMERA_LEVEL_COMP,
    CAMERA_LEVEL_COLI,
    CAMERA_LEVEL_DEBUG,
    CAMERA_LEVELS
};
struct camera_mode {
    void (*step)(struct camera_view *view);
    Sint8 level;
    Sint8 type;
    Uint8 unk_06[2];
    Bool pickable;
    void (*editor)(struct camera_view *view);
};
struct camera_adjust_work {
    Sint16 flags;
    Uint8 unk_02[2];
    Angle turn_x;
    Angle turn_y;
    Uint8 unk_0c[4];
    Float move;
    Sint32 steps;
};
struct camera_adjust_mode {
    Sint32 waits;
    void (*step)(struct task_work *work, struct task_work *last,
                 struct camera_adjust_work *adjust);
};
struct camera_control {
    Bool changed;
    Sint16 collision;
    Sint8 mode;
    Sint8 type;
    Sint8 level;
    Sint8 adjust;
    Uint8 unk_0a;
    Sint8 flags;
    void (*step)(struct camera_view *view);
    void (*adjust_step)(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust);
    Sint32 steps;
    Sint32 saved_level[CAMERA_LEVELS];
    Sint16 saved_collision[CAMERA_LEVELS];
    Sint8 saved_flags[CAMERA_LEVELS];
    void (*saved_step[CAMERA_LEVELS])(struct camera_view *view);
    void (*saved_adjust_step[CAMERA_LEVELS])(struct task_work *work,
                                             struct task_work *last,
                                             struct camera_adjust_work *adjust);
    Sint8 saved_mode[CAMERA_LEVELS];
    Sint8 saved_adjust[CAMERA_LEVELS];
    Sint8 saved_type[CAMERA_LEVELS];
    Sint16 unk_86[CAMERA_LEVELS];
    NJS_VECTOR offset;
};
enum camcol { CAMCOL_SPHERE, CAMCOL_PLANE, CAMCOL_BLOCK, CAMCOL_TYPES };
struct camera_collision {
    Sint8 mode;
    Sint8 priority;
    Uint8 adjust;
    Sint8 type;
    Uint16 col_ang_x;
    Uint16 col_ang_y;
    NJS_POINT3 col_pos;
    NJS_POINT3 col_scl;
    Uint16 cam_ang_x;
    Uint16 cam_ang_y;
    NJS_POINT3 dir_pos;
    NJS_POINT3 cam_pos;
    Float distance;
};
struct camera_layout {
    Sint32 count;
    struct camera_collision *collisions;
};
struct camera_path {
    Sint32 flags;
    struct path *path;
    Float look_ahead;
    Float sit_back;
    Float look_share;
    Float sit_share;
    Float unk_18;
    Float unk_1c;
    Float height;
    Float short_by;
    Float unk_28;
    Float ease;
    Float far;
    Float unk_34;
    Sint32 first;
    Sint32 skip;
    Uint32 wait;
    NJS_VECTOR shift;
    NJS_VECTOR path_shift;
    Uint8 unk_5c[12];
    Angle unk_68;
    Float turn;
};
union camera_vars {
    NJS_POINT3 target;
    struct camera_path *path;
};
struct camera_key {
    NJS_POINT3 pos;
    NJS_POINT3 target;
};
union camera_place_arg {
    struct camera_key *keys;
    Sint32 last;
    NJS_POINT3 *point;
};
struct camera_place {
    NJS_POINT3 pos;
    NJS_POINT3 target;
    struct angles ang;
    union camera_place_arg args[2];
    Float distance;
};
extern struct camera_place camera_place;
extern Uint8 dat_8c6c0a30[4];
extern Bool camera_player_still;
extern NJS_VECTOR camera_moved;
extern struct task_work camera_last_record;
extern struct camera_state camera_state_record;
extern Uint8 dat_8c6c0ad8[12];
extern struct camera_control camera_control_record;
extern struct camera_view camera_step_view;
extern struct camera_view camera_override_view;
extern struct camera_adjust_work camera_adjust_record;
extern Sint16 camera_stage;
extern Sint16 camera_act;
extern Sint16 camera_mode_count;
extern struct camera_mode *camera_modes;
extern Sint16 camera_adjust_count;
extern struct camera_adjust_mode *camera_adjusts;
extern Sint32 *camera_collision_count;
extern struct camera_collision *camera_collisions;
extern Angle camera_perspective;
extern Sint32 camera_action_state;
extern NJS_CACTION *camera_action;
extern Float camera_action_frame;
extern Uint32 camera_steps;
extern Uint32 camera_restored_steps;
extern Sint32 camera_start_mode;
extern Sint32 camera_restore_mode;
extern Sint32 camera_restore_adjust;
extern Bool camera_cut;
extern Sint32 camera_step_count;
extern struct task_work *camera_take_work;
extern Uint8 dat_8c6c0c30[4];
extern NJS_POINT3 camera_player_last;
extern NJS_POINT3 camera_last_pos;
extern Bool camera_in_dry_box;
extern Float trigger_orbit_distance;
extern Float trigger_orbit_height;
extern Angle trigger_orbit_angle;
extern int trigger_orbit_active;
extern Uint8 dat_8c6c0ce0[4];
extern int camera_point_follows;
extern NJS_POINT3 camera_boss_place;
extern NJS_POINT3 camera_boss_target_offset;
extern NJS_POINT3 camera_boss_offset;
extern struct angles camera_boss_turn_step;
extern struct angles camera_boss_spin_limit;
extern NJS_POINT3 camera_boss_move_limit;
extern Angle camera_swing_turned;
extern Angle camera_swing_turn;
extern struct task_work *camera_swing_work;
extern Float camera_swing_height;
extern Float camera_swing_distance;
extern Float camera_swing_near;
extern Float camera_swing_close_step;
extern Sint8 camera_swing_done;
extern Sint8 camera_swing_phase;
extern NJS_POINT3 camera_swing_target;
extern Angle camera_swing_heading;
extern Float camera_klamath_height;
extern int camera_klamath_follows;
extern Float camera_klamath_sink;
extern int camera_ashland_follows;
extern Bool camera_pose_taken;
extern NJS_POINT3 camera_pose_pos;
extern struct angles camera_pose_ang;
extern struct task_work *camera_twp;
extern struct camera_state *const camera_state;
void camera_step_none(struct camera_view *view);
void camera_set_start_mode(Sint8 mode);
void camera_set_restore_mode(Sint8 mode, Sint8 adjust);
Angle camera_get_perspective(void);
void camera_set_perspective(Angle ang);
Bool camera_collisions_enabled(void);
void camera_enable_collisions(void);
void camera_disable_collisions(void);
void camera_create(void);
void camera_change_act(Sint16 by);
void camera_create_advertise(void);
void camera_place_at_angles(struct task_work *work);
void camera_place_look_at(struct task_work *work);
void camera_place_from_target(struct task_work *work);
void camera_add_offset(NJS_VECTOR *offset);
void camera_set_mode(Sint16 mode, Uint8 adjust);
void camera_override_mode(Sint16 mode, Uint8 adjust);
void camera_override(void (*step)(struct camera_view *view), Uint8 adjust,
                     Sint8 type);
void camera_restore(void);
void camera_override_high(void (*step)(struct camera_view *view), Uint8 adjust,
                          Sint8 type);
void camera_restore_high(void);
void camera_take(struct task_work *work,
                 void (*step)(struct camera_view *view));
void camera_release(void);
Bool camera_at_event_level(void);
Bool camera_at_comp_level(void);
Uint32 camera_get_steps(void);
void camera_reset_steps(void);
void camera_set_adjust(int adjust);
int camera_get_adjust(void);
int camera_get_mode(void);
Bool camera_adjust_is_c(void);
void camera_set_type(int type);
Bool camera_play_action(NJS_CACTION *action, Float frame);
int camera_push_out(NJS_POINT3 *pos);
void camera_ease(NJS_POINT3 *from, NJS_POINT3 *pos);
Bool camera_sweep_hits(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                       Float radius);
void camera_orbit(struct camera_view *view);
void camera_step_event(struct camera_view *view);
void camera_step_fixed(struct camera_view *view);
void camera_step_fishing_point(struct camera_view *view);
void camera_step_view_target(struct camera_view *view);
void camera_step_eyes(struct camera_view *view);
void camera_step_trick_a(struct camera_view *view);
void camera_step_trick_b(struct camera_view *view);
void camera_step_board(struct camera_view *view);
void camera_step_follow(struct camera_view *view);
void camera_step_work_view(struct camera_view *view);
void camera_step_path(struct camera_view *view);
void camera_step_pose(struct camera_view *view);
void camera_start_path(struct path *path, int mode, Uint32 steps);
void camera_boss_turn(int unbounded);
void camera_boss_place_from_player(int below_only);
int camera_boss_move(int from_anchor);
void camera_set_e103(struct task_work *work, NJS_POINT3 *points);
void camera_set_boss_offsets(NJS_POINT3 *target, NJS_POINT3 *offset);
void camera_set_boss_limits(struct angles *step, struct angles *spin,
                            NJS_VECTOR *move);
void camera_start_swing(struct task_work *work, Float height, Float distance,
                        int swing_steps);
void camera_adjust_none(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust);
void camera_adjust_normal(struct task_work *work, struct task_work *last,
                          struct camera_adjust_work *adjust);
void camera_adjust_slow(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust);
void camera_adjust_time(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust);
void camera_adjust_ease(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust);
struct camera_mode_table {
    Sint16 mode_count;
    Sint16 adjust_count;
    struct camera_mode *modes;
    struct camera_adjust_mode *adjusts;
};
extern struct camera_mode camera_mode_list[];
extern struct camera_mode_table camera_mode_table;
extern struct camera_layout camera_advertise_layout;
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
void collision_init(struct task *task, const struct collision_shape *shapes,
                    Uint8 kind, int unused, Uint8 count);
void collision_register(struct task_work *work);
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
Float GetShadowPos(Float x, Float y, Float z, struct angles *slope);
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
Bool FUN_8c09276e(struct sides_query *result);
Bool FUN_8c092b20(struct sides_query *result);
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
struct task_work;
void draw_action(NJS_ACTION *action, Float frame);
void draw_motion(NJS_OBJECT *object, NJS_MOTION *motion, Float frame);
void draw_action_link(NJS_ACTION_LINK *link, Float ratio);
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
struct particle *SpCreateTask(struct particle_pool *pool,
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
void FUN_8c047d90(struct task_work *work, struct lockon_target *record);
void FUN_8c047da2(struct task_work *work, struct lockon_target *record);
int enemy_aim_at_target(struct task_work *work, struct lockon_target *record);
int FUN_8c047e94(struct task_work *work, struct lockon_target *record);
int enemy_aim_at_home(struct task_work *work, struct lockon_target *record);
int enemy_turn_home(struct task_work *work, struct lockon_target *record);
int EnemyCalcPlayerAngle(struct task_work *work, struct lockon_target *record,
                        Uint8 player);
int FUN_8c048060(struct task_work *work, struct lockon_target *record,
                         Uint8 player);
int FUN_8c04808e(struct task_work *work, struct lockon_target *record,
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
void FUN_8c048980(Sint8 player);
Bool enemy_take_hit(struct task_work *work, struct lockon_target *record);
struct task;
struct hud_number {
    Uint8 flags;
    Uint8 place;
    Sint16 unk_02;
    Uint32 max;
    Uint32 value;
    NJS_POINT3 pos;
    Float scale;
    Uint32 color;
};
struct mole_hit {
    int count;
    int points;
};
extern NJS_TEXLIST hud_digit_texlist;
extern NJS_TEXLIST hud_texlist;
enum mole_kind { KIND_500, KIND_100, KIND_EGGMAN, MOLE_KINDS };
extern struct mole_hit mole_hits[MOLE_KINDS];
void hud_reset(void);
void score_reset(void);
void ring_reset(void);
void lives_reset(void);
void lives_add(Sint16 count);
void ring_add(int count);
void score_add(int points);
void score_add_bonus(int points);
int ring_count(void);
void hud_draw(void);
Sint16 lives_count(void);
void play_time_reset(void);
void time_reset(void);
void time_start(void);
void time_stop(void);
void play_time_count(void);
void time_step(void);
int play_time_get(void);
void hud_draw_timer(void);
void time_get_whole(Uint8 *minutes, Uint8 *seconds);
void time_set_whole(int minutes, int seconds);
void time_set(Uint8 minutes, Uint8 seconds, Uint8 frames);
void time_get(Uint8 *minutes, Uint8 *seconds, Uint8 *frames);
void time_add_seconds(int seconds);
Bool time_is_zero(void);
void score_step(struct task *task);
void hud_draw_number(struct hud_number *number);
void trial_times_clear(void);
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
struct task;
struct task_work;
enum item_kind {
    ITEM_SPEED_UP,
    ITEM_INVINCIBLE,
    ITEM_5RING,
    ITEM_10RING,
    ITEM_RANDOMRING,
    ITEM_BARRIER,
    ITEM_1UP,
    ITEM_EXPLOSION,
    ITEM_MAGNETIC_BARRIER,
    ITEM_COUNT
};
struct item {
    Uint32 texture;
    void (*give)(struct task_work *work);
};
extern struct item item_kinds[ITEM_COUNT];
extern Uint32 item_1up_textures[];
void item_box_create(NJS_POINT3 *pos, enum item_kind kind);
void item_box_step(struct task *task);
struct task;
extern Sint32 item_rings_given;
void item_box_air_create(NJS_POINT3 *pos, enum item_kind kind);
void item_box_air_step(struct task *task);
void item_reset(void);
void item_show(enum item_kind kind);
void item_explosion_start(NJS_POINT3 *pos);
Bool item_explosion_reaches(NJS_POINT3 *pos);
extern NJS_OBJECT savepoint_gate;
extern NJS_OBJECT savepoint_lamp_plus_x[];
extern NJS_OBJECT savepoint_lamp_minus_x[];
extern NJS_OBJECT iron_ball_object;
extern NJS_OBJECT iron_ball_link_object;
extern NJS_OBJECT iron_ball_joint_object;
extern NJS_MODEL capsule_base_model;
extern NJS_MODEL capsule_body_model;
extern NJS_MODEL capsule_button_model;
extern NJS_OBJECT target_object;
extern NJS_MODEL item_box_base_model;
extern NJS_MODEL item_box_glass_model;
extern NJS_MODEL item_box_top_model;
extern NJS_MODEL item_box_icon_model;
extern NJS_OBJECT level_item_wave_object[];
extern NJS_OBJECT level_item_light_object[];
extern NJS_OBJECT level_item_floor_object;
extern NJS_ACTION level_item_wave_action[];
extern NJS_OBJECT emerald_piece_object;
extern NJS_OBJECT panel_object;
extern NJS_OBJECT panel_number_object;
extern NJS_OBJECT panel_end_object;
extern NJS_OBJECT item_box_air_object;
extern NJS_OBJECT item_box_air_panel;
extern NJS_OBJECT item_box_air_lower;
extern NJS_OBJECT toge_object;
extern NJS_MODEL switch_plate_model;
extern NJS_MATERIAL switch_button_materials[];
extern NJS_MODEL switch_button_model;
extern NJS_MODEL switch_base_model;
extern NJS_OBJECT rocket_launcher_object[];
extern NJS_ACTION rocket_launcher_action;
extern NJS_ACTION rocket_h_action;
extern NJS_ACTION rocket_v_action;
extern NJS_MODEL spring_base_model;
extern NJS_OBJECT spring_coil_object;
extern NJS_OBJECT spring_top_object;
extern NJS_MODEL spring_b_base_model;
extern NJS_OBJECT spring_b_coil_object;
extern NJS_OBJECT spring_b_top_object;
extern NJS_MODEL spring_h_base_model;
extern NJS_MODEL spring_h_board_model;
extern NJS_OBJECT shadow_object[];
extern NJS_MODEL shadow_model;
extern NJS_OBJECT hint_object[];
extern NJS_ACTION dash_panel_action;
extern NJS_OBJECT dash_ring_object;
extern NJS_OBJECT kusa_object;
extern NJS_OBJECT kusa_cut_object;
extern NJS_OBJECT kusa_leaf_object;
extern NJS_MODEL balloon_model;
extern NJS_MODEL balloon_knot_model;
extern NJS_MODEL balloon_sign_model;
extern NJS_MODEL balloon_sign_frame_model;
extern NJS_MODEL ring_model;
extern NJS_OBJECT ring_object;
extern NJS_OBJECT ripple_object;
extern NJS_OBJECT star_yellow_object;
extern NJS_OBJECT star_orange_object;
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
Bool SetRegularTexture(void);
Bool texture_set_stage(void);
Bool texture_has_primary_stage_texlist(void);
void texture_release_stage(void);
Bool texture_load_act(Uint16 stage_act);
Bool texture_act_in_use(Uint16 stage_act);
Bool texture_release_act(Uint16 stage_act);
void texture_release_acts(void);
void texture_load_pvm(char *name, NJS_TEXLIST *texlist);
Sint32 texture_load_prs_file(char *name, NJS_TEXLIST *texlist);
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
void vibration_start(int pad, int power, int freq, int time);
void vibration_start_fading(int pad, int power, int freq, int length);
extern NJS_MODEL enemy_debris_model;
struct enemy_piece_vars {
    NJS_MODEL *model;
    Angle spin;
    NJS_TEXLIST *texlist;
};
enum enemy_piece_mode { PIECE_START, PIECE_FALL, PIECE_END };
extern NJS_POINT3 enemy_player_spots[4];
struct lockon_target *EnemyInitialize(struct task *task,
                                         struct task_work *work)
{
    struct lockon_target *record;
    record = CAlloc(1, sizeof(*record));
    if (record == ((void *)0)) {
        FreeTask(task);
        return ((void *)0);
    }
    task->motion = &record->motion;
    record->home = work->pos;
    record->radius = 15.0F;
    record->probe_offset.y = 5.0F;
    record->top = 10.0F;
    record->bottom = -1.0F;
    record->step_down = 50.0F;
    record->floor_bounce = 0.9F;
    record->friction = 0.8F;
    record->unk_c4 = 0.1F;
    record->wall_bounce = 0.7F;
    record->wall_turn = 0x400;
    record->sight_angle = ((Angle)(((80) * 65536.0) / 360.0));
    record->sight_distance = 150.0F * 150.0F;
    record->near_distance = 35.0F * 35.0F;
    record->turn_speed = 0x100;
    record->flags |= 0x80 | 0x400;
    record->flags &= ~(0x1000 | 0x2000);
    return record;
}
void enemy_end(struct task *task, struct task_work *work,
               struct lockon_target *record)
{
}
Sint8 enemy_sees_player(struct task_work *work, struct lockon_target *record)
{
    Sint8 i;
    for (i = 0; i < 2; i++) {
        struct task_work *player = playertwp[i];
        if (player != ((void *)0)) {
            Float distance2 = ((player->pos.x - work->pos.x) * (player->pos.x - work->pos.x)) +
                              ((player->pos.y - work->pos.y) * (player->pos.y - work->pos.y)) +
                              ((player->pos.z - work->pos.z) * (player->pos.z - work->pos.z));
            if (distance2 < record->sight_distance) {
                Angle heading = work->ang.y;
                Angle aim = (Angle)(njArcTan2(player->pos.x - work->pos.x,
                                           player->pos.z - work->pos.z) *
                                    (65536.0 / (2 * 3.141592))) -
                            ((Angle)(((90) * 65536.0) / 360.0));
                int away = (Uint16)DiffAngle(aim, heading);
                if (away < record->sight_angle ||
                    distance2 < record->near_distance) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void EnemyGetShadow(struct task_work *work,
                              struct lockon_target *record)
{
    struct sides_query *ground = &record->ground;
    NJS_VECTOR unused = {0.0F, 0.0F, 0.0F};
    NJS_VECTOR turned;
    NJS_VECTOR offset;
    offset = record->probe_offset;
    njPushMatrix(((void *)0));
    njUnitMatrix(((void *)0));
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    njCalcPoint(((void *)0), &offset, &turned);
    njPopMatrix(1);
    ground->pos.x = work->pos.x + turned.x;
    ground->pos.y = work->pos.y + turned.y;
    ground->pos.z = work->pos.z + turned.z;
    if (record->flags & 0x2000) {
        if (FUN_8c092b20(ground)) {
            record->flags = record->flags | 0x4000;
        } else {
            record->flags &= ~0x4000;
        }
    } else {
        FUN_8c09276e(ground);
    }
}
void enemy_collide_ceiling(struct task_work *work,
                                  struct lockon_target *record)
{
    Float top = record->ground.pos.y + record->top;
    struct surface *ceiling = &record->ground.sides[SIDE_ABOVE];
    record->flags &= ~0x8;
    if (top > ceiling->level) {
        record->motion.speed.y = 0.0F;
        work->pos.y -= (top - ceiling->level) * 0.3F;
        record->flags |= 0x8;
    }
}
void FUN_8c0473a8(struct task_work *work,
                                 struct lockon_target *record)
{
    Float bottom = record->ground.pos.y + record->bottom;
    struct surface *floor = &record->ground.sides[SIDE_BELOW];
    Float width;
    Float length;
    if ((record->flags & 0x1) &&
        !(record->flags & 0x80) &&
        (bottom - record->step_down > floor->level || !floor->found)) {
        FUN_8c047da2(work, record);
        record->flags |= 0x10 | 0x80;
        work->pos.x -= record->motion.speed.x * 0.4F;
        work->pos.z -= record->motion.speed.z * 0.4F;
        record->motion.speed.x = 0.0F;
        record->motion.speed.y = 0.0F;
        record->motion.speed.z = 0.0F;
    } else {
        record->flags &= ~0x10;
        if (floor->level > bottom) {
            record->motion.speed.y *= -record->floor_bounce;
            record->motion.speed.x *= record->friction;
            record->motion.speed.z *= record->friction;
            work->pos.y += (floor->level - bottom) * 0.3F;
            if (record->flags & 0x4) {
                work->ang.x = AdjustAngle(work->ang.x, floor->ang_x, 0x80);
                work->ang.z = AdjustAngle(work->ang.z, floor->ang_z, 0x80);
            }
            record->flags |= 0x10;
            record->flags &= ~0x80;
        }
    }
    if (!(record->flags & 0x2)) {
        return;
    }
    {
        extern int loop_count;
        if (loop_count != 0) {
            return;
        }
    }
    width = record->shadow_size /
            (1.0F + (0.03F * _builtin_fabsf(bottom - floor->level)));
    length = record->shadow_size * record->shadow_ratio;
    SetRegularTexture();
    SetMaterial(-0.05F, 0.0F, 0.0F, 0.0F);
    njPushMatrix(((void *)0));
    njTranslate(((void *)0), work->pos.x, floor->level + 0.2F, work->pos.z);
    ((floor->ang_z) ? (njRotateZ)(((void *)0), (floor->ang_z)) : (void)0);
    ((floor->ang_x) ? (njRotateX)(((void *)0), (floor->ang_x)) : (void)0);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    njScale(((void *)0), width, width, length);
    late_DrawObjectClip(shadow_object);
    njPopMatrix(1);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
void enemy_collide_walls(struct task_work *work,
                                struct lockon_target *record)
{
    NJS_POINT3 pos;
    NJS_PLANE plane;
    struct sides_query *ground = &record->ground;
    struct surface *wall;
    Float radius = record->radius;
    Float depth;
    Float bounce;
    pos = ground->pos;
    record->flags &= ~0x40;
    do { if (ground->sides[SIDE_MINUS_X].found) { NJS_VECTOR facing = {-1.0F, 0.0F, 0.0F}; NJS_POINT3 nearest; NJS_VECTOR push; NJS_VECTOR axis; NJS_VECTOR normal; wall = &ground->sides[SIDE_MINUS_X]; if (njInnerProduct(&facing, &wall->normal) < -0.5F) { plane.px = wall->level; plane.py = pos.y; plane.pz = pos.z; plane.vx = wall->normal.x; plane.vy = wall->normal.y; plane.vz = wall->normal.z; depth = radius - njDistanceP2PL(&pos, &plane, &nearest); if (depth > 0.0F) { push.x = wall->normal.x; push.y = 0.0F; push.z = wall->normal.z; push.x *= depth * 0.35F; push.y *= depth * 0.35F; push.z *= depth * 0.35F; njAddVector(&work->pos, &push); record->flags |= 0x40; if (njInnerProduct(&record->motion.speed, &wall->normal) < 0.0F) { normal = wall->normal; if (njUnitVector(&normal) == 0.0F) { normal.x = 1.0F; normal.y = 0.0F; normal.z = 0.0F; } bounce = -(njInnerProduct(&record->motion.speed, &normal) * record->wall_bounce * 2.0F); normal.x *= bounce; normal.y *= bounce; normal.z *= bounce; njAddVector(&record->motion.speed, &normal); njOuterProduct(&normal, &record->motion.speed, &axis); if (axis.y > 0.0F) { work->ang.y -= record->wall_turn; } else { work->ang.y += record->wall_turn; } } } } } } while (0);
    do { if (ground->sides[SIDE_PLUS_X].found) { NJS_VECTOR facing = {1.0F, 0.0F, 0.0F}; NJS_POINT3 nearest; NJS_VECTOR push; NJS_VECTOR axis; NJS_VECTOR normal; wall = &ground->sides[SIDE_PLUS_X]; if (njInnerProduct(&facing, &wall->normal) < -0.5F) { plane.px = wall->level; plane.py = pos.y; plane.pz = pos.z; plane.vx = wall->normal.x; plane.vy = wall->normal.y; plane.vz = wall->normal.z; depth = radius - njDistanceP2PL(&pos, &plane, &nearest); if (depth > 0.0F) { push.x = wall->normal.x; push.y = 0.0F; push.z = wall->normal.z; push.x *= depth * 0.35F; push.y *= depth * 0.35F; push.z *= depth * 0.35F; njAddVector(&work->pos, &push); record->flags |= 0x40; if (njInnerProduct(&record->motion.speed, &wall->normal) < 0.0F) { normal = wall->normal; if (njUnitVector(&normal) == 0.0F) { normal.x = 1.0F; normal.y = 0.0F; normal.z = 0.0F; } bounce = -(njInnerProduct(&record->motion.speed, &normal) * record->wall_bounce * 2.0F); normal.x *= bounce; normal.y *= bounce; normal.z *= bounce; njAddVector(&record->motion.speed, &normal); njOuterProduct(&normal, &record->motion.speed, &axis); if (axis.y > 0.0F) { work->ang.y -= record->wall_turn; } else { work->ang.y += record->wall_turn; } } } } } } while (0);
    do { if (ground->sides[SIDE_MINUS_Z].found) { NJS_VECTOR facing = {0.0F, 0.0F, -1.0F}; NJS_POINT3 nearest; NJS_VECTOR push; NJS_VECTOR axis; NJS_VECTOR normal; wall = &ground->sides[SIDE_MINUS_Z]; if (njInnerProduct(&facing, &wall->normal) < -0.5F) { plane.px = pos.x; plane.py = pos.y; plane.pz = wall->level; plane.vx = wall->normal.x; plane.vy = wall->normal.y; plane.vz = wall->normal.z; depth = radius - njDistanceP2PL(&pos, &plane, &nearest); if (depth > 0.0F) { push.x = wall->normal.x; push.y = 0.0F; push.z = wall->normal.z; push.x *= depth * 0.35F; push.y *= depth * 0.35F; push.z *= depth * 0.35F; njAddVector(&work->pos, &push); record->flags |= 0x40; if (njInnerProduct(&record->motion.speed, &wall->normal) < 0.0F) { normal = wall->normal; if (njUnitVector(&normal) == 0.0F) { normal.x = 1.0F; normal.y = 0.0F; normal.z = 0.0F; } bounce = -(njInnerProduct(&record->motion.speed, &normal) * record->wall_bounce * 2.0F); normal.x *= bounce; normal.y *= bounce; normal.z *= bounce; njAddVector(&record->motion.speed, &normal); njOuterProduct(&normal, &record->motion.speed, &axis); if (axis.y > 0.0F) { work->ang.y -= record->wall_turn; } else { work->ang.y += record->wall_turn; } } } } } } while (0);
    do { if (ground->sides[SIDE_PLUS_Z].found) { NJS_VECTOR facing = {0.0F, 0.0F, 1.0F}; NJS_POINT3 nearest; NJS_VECTOR push; NJS_VECTOR axis; NJS_VECTOR normal; wall = &ground->sides[SIDE_PLUS_Z]; if (njInnerProduct(&facing, &wall->normal) < -0.5F) { plane.px = pos.x; plane.py = pos.y; plane.pz = wall->level; plane.vx = wall->normal.x; plane.vy = wall->normal.y; plane.vz = wall->normal.z; depth = radius - njDistanceP2PL(&pos, &plane, &nearest); if (depth > 0.0F) { push.x = wall->normal.x; push.y = 0.0F; push.z = wall->normal.z; push.x *= depth * 0.35F; push.y *= depth * 0.35F; push.z *= depth * 0.35F; njAddVector(&work->pos, &push); record->flags |= 0x40; if (njInnerProduct(&record->motion.speed, &wall->normal) < 0.0F) { normal = wall->normal; if (njUnitVector(&normal) == 0.0F) { normal.x = 1.0F; normal.y = 0.0F; normal.z = 0.0F; } bounce = -(njInnerProduct(&record->motion.speed, &normal) * record->wall_bounce * 2.0F); normal.x *= bounce; normal.y *= bounce; normal.z *= bounce; njAddVector(&record->motion.speed, &normal); njOuterProduct(&normal, &record->motion.speed, &axis); if (axis.y > 0.0F) { work->ang.y -= record->wall_turn; } else { work->ang.y += record->wall_turn; } } } } } } while (0);
}
void EnemyCheckGroundCollision(struct task_work *work, struct lockon_target *record)
{
    EnemyGetShadow(work, record);
    enemy_collide_ceiling(work, record);
    FUN_8c0473a8(work, record);
    enemy_collide_walls(work, record);
}
void Knuckles_KakeraGame_Set_CheckEme(struct task_work *work, struct lockon_target *record)
{
    record->home = work->pos;
}
void FUN_8c047d90(struct task_work *work, struct lockon_target *record)
{
    record->last_pos = work->pos;
}
void FUN_8c047da2(struct task_work *work, struct lockon_target *record)
{
    work->pos = record->last_pos;
}
Float enemy_target_distance(struct task_work *work,
                            struct lockon_target *record)
{
    Float distance2 = ((record->target.x - work->pos.x) * (record->target.x - work->pos.x)) +
                      ((record->target.y - work->pos.y) * (record->target.y - work->pos.y)) +
                      ((record->target.z - work->pos.z) * (record->target.z - work->pos.z));
    return njSqrt(distance2);
}
Float enemy_target_distance2(struct task_work *work,
                             struct lockon_target *record)
{
    Float distance2 = ((record->target.x - work->pos.x) * (record->target.x - work->pos.x)) +
                      ((record->target.y - work->pos.y) * (record->target.y - work->pos.y)) +
                      ((record->target.z - work->pos.z) * (record->target.z - work->pos.z));
    return distance2;
}
int enemy_aim_at_target(struct task_work *work, struct lockon_target *record)
{
    Angle heading = work->ang.y;
    record->aim_y = (Angle)(njArcTan2(record->target.x - work->pos.x,
                                   record->target.z - work->pos.z) *
                            (65536.0 / (2 * 3.141592))) -
                    ((Angle)(((90) * 65536.0) / 360.0));
    return (Uint16)DiffAngle(record->aim_y, heading);
}
int FUN_8c047e94(struct task_work *work, struct lockon_target *record)
{
    int away = enemy_aim_at_target(work, record);
    work->ang.y =
        AdjustAngle(work->ang.y, record->aim_y, record->turn_speed);
    return away;
}
Float enemy_home_distance(struct task_work *work, struct lockon_target *record)
{
    Float distance2 = ((record->home.x - work->pos.x) * (record->home.x - work->pos.x)) +
                      ((record->home.y - work->pos.y) * (record->home.y - work->pos.y)) +
                      ((record->home.z - work->pos.z) * (record->home.z - work->pos.z));
    return njSqrt(distance2);
}
Float enemy_home_distance2(struct task_work *work, struct lockon_target *record)
{
    Float distance2 = ((record->home.x - work->pos.x) * (record->home.x - work->pos.x)) +
                      ((record->home.y - work->pos.y) * (record->home.y - work->pos.y)) +
                      ((record->home.z - work->pos.z) * (record->home.z - work->pos.z));
    return distance2;
}
int enemy_aim_at_home(struct task_work *work, struct lockon_target *record)
{
    Angle heading = work->ang.y;
    record->aim_y = (Angle)(njArcTan2(record->home.x - work->pos.x,
                                   record->home.z - work->pos.z) *
                            (65536.0 / (2 * 3.141592))) -
                    ((Angle)(((90) * 65536.0) / 360.0));
    return (Uint16)DiffAngle(record->aim_y, heading);
}
int enemy_turn_home(struct task_work *work, struct lockon_target *record)
{
    int away = enemy_aim_at_home(work, record);
    work->ang.y =
        AdjustAngle(work->ang.y, record->aim_y, record->turn_speed);
    return away;
}
Float EnemyDist2FromPlayer(struct task_work *work, int player)
{
    struct task_work *other = playertwp[player];
    Float distance2 = ((other->pos.x - work->pos.x) * (other->pos.x - work->pos.x)) +
                      ((other->pos.y - work->pos.y) * (other->pos.y - work->pos.y)) +
                      ((other->pos.z - work->pos.z) * (other->pos.z - work->pos.z));
    return distance2;
}
int EnemyCalcPlayerAngle(struct task_work *work, struct lockon_target *record,
                        Uint8 player)
{
    struct task_work *other = playertwp[player];
    Angle heading = work->ang.y;
    NJS_POINT3 *pos = &work->pos;
    record->aim_y =
        (Angle)(njArcTan2(other->pos.x - work->pos.x, other->pos.z - work->pos.z) *
                (65536.0 / (2 * 3.141592))) -
        ((Angle)(((90) * 65536.0) / 360.0));
    return (Uint16)DiffAngle(record->aim_y, heading);
}
int FUN_8c048060(struct task_work *work, struct lockon_target *record,
                         Uint8 player)
{
    int away = EnemyCalcPlayerAngle(work, record, player);
    work->ang.y =
        AdjustAngle(work->ang.y, record->aim_y, record->turn_speed);
    return away;
}
int FUN_8c04808e(struct task_work *work, struct lockon_target *record,
                           Uint8 player)
{
    int away = EnemyCalcPlayerAngle(work, record, player);
    record->aim_y += ((Angle)(((180) * 65536.0) / 360.0));
    work->ang.y =
        AdjustAngle(work->ang.y, record->aim_y, record->turn_speed);
    return away;
}
Sint8 EnemyCheckFrameIn(NJS_POINT3 *pos)
{
    NJS_POINT2 projected;
    njProjectScreen(((void *)0), pos, &projected);
    if (projected.x >= 0.0F && projected.x <= 640.0F &&
        projected.y >= 0.0F && projected.y <= 400.0F) {
        return 1;
    }
    return 0;
}
void enemy_target_near_player(struct task_work *work,
                              struct lockon_target *record, int player,
                              int spot)
{
    struct task_work *other = playertwp[player];
    NJS_POINT3 offset;
    njPushMatrix(((void *)0));
    njUnitMatrix(((void *)0));
    ((camera_twp->ang.y) ? (njRotateY)(((void *)0), (camera_twp->ang.y)) : (void)0);
    njCalcPoint(((void *)0), &enemy_player_spots[spot], &offset);
    njPopMatrix(1);
    record->target.x = other->pos.x + offset.x;
    record->target.y = other->pos.y + offset.y;
    record->target.z = other->pos.z + offset.z;
}
void EnemyPartsMove(struct task_work *work)
{
    struct angles slope;
    Float height;
    ((work)->scl).y -= 0.06F;
    if (work->tick++ > 9) {
        work->tick = 0;
        height =
            GetShadowPos(work->pos.x, work->pos.y + 4.0F, work->pos.z, &slope);
        height = _builtin_fabsf(height - work->pos.y);
        if (((work)->scl).y < 0.0F && height < 1.0F) {
            ((work)->scl).y = -(((work)->scl).y * 0.8F);
        }
    }
    ((&work->pos)->x += (&((work)->scl))->x, (&work->pos)->y += (&((work)->scl))->y, (&work->pos)->z += (&((work)->scl))->z);
    work->ang.x += ((struct enemy_piece_vars *)&(work)->vars)->spin;
    work->ang.y += ((struct enemy_piece_vars *)&(work)->vars)->spin;
    work->ang.z += ((work)->flags);
}
void enemy_debris_move(struct task_work *work)
{
    ((work)->scl).y -= 0.09F;
    ((&work->pos)->x += (&((work)->scl))->x, (&work->pos)->y += (&((work)->scl))->y, (&work->pos)->z += (&((work)->scl))->z);
    work->ang.x += 0x200;
    work->ang.y += 0x1000;
    work->ang.z += 0x700;
}
void FUN_8c0482f2(struct task_work *work)
{
    NJS_MODEL *model = ((struct enemy_piece_vars *)&(work)->vars)->model;
    NJS_POINT3 *center = &model->center;
    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 10.0F)) {
        njSetTexture(((struct enemy_piece_vars *)&(work)->vars)->texlist);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
        ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        njTranslate(((void *)0), -center->x, -center->y, -center->z);
        draw_model(model);
        njPopMatrix(1);
    }
}
void enemy_piece_draw_task(struct task *task)
{
    FUN_8c0482f2(task->work);
}
void enemy_debris_draw(struct task_work *work)
{
    NJS_MODEL *model = ((struct enemy_piece_vars *)&(work)->vars)->model;
    NJS_POINT3 *center = &model->center;
    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 10.0F)) {
        SetRegularTexture();
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
        ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        njScale(((void *)0), 0.5F, 1.5F, 0.5F);
        njScale(((void *)0), 0.6F, 0.6F, 0.6F);
        draw_model(model);
        njPopMatrix(1);
    }
}
void enemy_debris_draw_task(struct task *task)
{
    enemy_debris_draw(task->work);
}
void FUN_8c0484cc(struct task_work *work)
{
    struct particle *particle;
    particle = SpCreateTask(dust_pool.pool, dust_rise_step);
    if (particle != ((void *)0)) {
        particle->pos = work->pos;
        particle->scale = 0.1F * 0.15F;
        particle->time = rand() * (1.0F / (32767 + 1)) * 6.0F;
        particle->ang = rand() * (1.0F / (32767 + 1)) * 360.0F * (65536.0F / 360.0F);
    }
}
void enemy_piece_step(struct task *task)
{
    struct task_work *work = task->work;
    Float y;
    switch (work->mode) {
    case PIECE_START:
        work->mode = PIECE_FALL;
        task->draw = enemy_piece_draw_task;
        break;
    case PIECE_FALL:
        if ((*(Uint16 *)&(work)->timer)++ >= 120) {
            (*(Uint16 *)&(work)->timer) = 0xff;
            work->mode = PIECE_END;
        }
        EnemyPartsMove(work);
        FUN_8c0482f2(work);
        if (0) {
            ((work)->scl).x = y;
            ((work)->scl).y = y;
        }
        if ((*(Uint16 *)&(work)->timer)++ % 3 == 0) {
            FUN_8c0484cc(work);
        }
        break;
    case PIECE_END:
        (*(Uint16 *)&(work)->timer) = 0xff;
        ((struct enemy_piece_vars *)&(work)->vars)->model = ((void *)0);
        ((struct enemy_piece_vars *)&(work)->vars)->texlist = ((void *)0);
        FreeTask(task);
        break;
    }
}
void enemy_debris_step(struct task *task)
{
    struct task_work *work = task->work;
    switch (work->mode) {
    case PIECE_START:
        work->mode = PIECE_FALL;
        ((struct enemy_piece_vars *)&(work)->vars)->model = &enemy_debris_model;
        task->draw = enemy_debris_draw_task;
        break;
    case PIECE_FALL:
        if ((*(Uint16 *)&(work)->timer)++ >= 120) {
            ((struct enemy_piece_vars *)&(work)->vars)->model = ((void *)0);
            ((struct enemy_piece_vars *)&(work)->vars)->texlist = ((void *)0);
            FreeTask(task);
        } else {
            enemy_debris_move(work);
            enemy_debris_draw(work);
        }
        break;
    }
}
void enemy_break(struct task_work *work, NJS_MODEL **models,
                 NJS_TEXLIST *texlist)
{
    int i;
    struct task *task;
    struct task_work *piece;
    for (i = 0; models[i] != ((void *)0); i++) {
        task = CreateElementalTask(0x2, 2, enemy_piece_step);
        if (task != ((void *)0)) {
            piece = task->work;
            piece->pos = work->pos;
            ((piece)->scl).x = ((rand() * (1.0F / (32767 + 1))) - 0.5F) * 2.0F;
            ((piece)->scl).y = (rand() * (1.0F / (32767 + 1)) * 2.0F) + 0.9F;
            ((piece)->scl).z = ((rand() * (1.0F / (32767 + 1))) - 0.5F) * 2.0F;
            piece->ang = work->ang;
            piece->tick = i % 10;
            (*(Uint16 *)&(piece)->timer) = 0;
            ((struct enemy_piece_vars *)&(piece)->vars)->model = models[i];
            ((struct enemy_piece_vars *)&(piece)->vars)->spin =
                (0.5F - (rand() * (1.0F / (32767 + 1)))) * 20.0F * (65536.0F / 360.0F);
            ((piece)->flags) =
                (0.5F - (rand() * (1.0F / (32767 + 1)))) * 20.0F * (65536.0F / 360.0F);
            ((struct enemy_piece_vars *)&(piece)->vars)->texlist = texlist;
        }
    }
}
void enemy_scatter_debris(struct task_work *work, Uint8 count)
{
    int i;
    struct task *task;
    struct task_work *debris;
    for (i = 0; i < count; i++) {
        task = CreateElementalTask(0x2, 3, enemy_debris_step);
        if (task != ((void *)0)) {
            debris = task->work;
            debris->pos = work->pos;
            ((debris)->scl).x = ((rand() * (1.0F / (32767 + 1))) - 0.5F) * 3.0F;
            ((debris)->scl).y = (rand() * (1.0F / (32767 + 1)) * 3.0F) + 0.1F;
            ((debris)->scl).z = ((rand() * (1.0F / (32767 + 1))) - 0.5F) * 3.0F;
            debris->ang = work->ang;
            (*(Uint16 *)&(debris)->timer) = 0;
            ((struct enemy_piece_vars *)&(debris)->vars)->spin =
                ((rand() * (1.0F / (32767 + 1))) + 1.0F) * 50.0F * (65536.0F / 360.0F);
            ((debris)->flags) =
                ((rand() * (1.0F / (32767 + 1))) + 1.0F) * 50.0F * (65536.0F / 360.0F);
        }
    }
}
void enemy_spring_scale(struct task_work *work, struct lockon_target *record)
{
    Float stretch = work->scl.y - 1.0F;
    record->scale_speed += -(record->scale_speed * 0.2F) - (stretch * 0.32F);
    work->scl.y += record->scale_speed;
    if (work->scl.y > 1.7F) {
        work->scl.y = 1.7F;
    } else if (work->scl.y < 0.3F) {
        work->scl.y = 0.3F;
    }
    work->scl.x = 2.0F - work->scl.y;
}
void FUN_8c048980(Sint8 player)
{
    struct task_work *work = playertwp[player];
    int character;
    if (work == ((void *)0)) {
        return;
    }
    if ((work->flags & 0x100) && !(work->flags & (0x1 | 0x2))) {
        character = ((struct player_vars *)&(work)->vars)->character;
        if (character == 0 || character == 2 ||
            character == 3) {
            player_set_speed(player, 0.0F, 2.0F, 0.0F);
            vibration_start(player, 6, 30, 0);
        }
    }
}
Bool enemy_take_hit(struct task_work *work, struct lockon_target *record)
{
    struct collision_work *hit = work->collision->hit;
    if (work->flags & 0x4) {
        record->scale_speed = 0.35F;
        if (hit->kind == 0 || hit->kind == 1) {
            record->flags |= 0x1000;
            score_add_bonus(10);
            if (hit->shapes[work->collision->hit_shape].flags &
                0x200) {
                record->motion.speed.y = 0.7F;
                record->flags |= 0x800;
            } else {
                if (playertwp[0] == hit->owner->work) {
                    FUN_8c048980(0);
                } else {
                    FUN_8c048980(1);
                }
                record->flags &= ~0x400;
            }
        }
        return (1);
    }
    if (item_explosion_reaches(&work->pos)) {
        return (1);
    }
    return (0);
}
