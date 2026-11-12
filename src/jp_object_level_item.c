/* @unit 8C069800-8C06AE40 +r04 +egflags +pool32 +poolafter=level_item_destroy,FUN_8c069bae,level_item_draw_stand,FUN_8c06a40a,FUN_8c06a7d0,level_item_draw_spark +poolbra=level_item_step:9,FUN_8c069c20:8,FUN_8c06ad74:1 +asmfunc=FUN_8c06a086,levelupitemEffectManager */
/* Ported from the Japanese release's src/object/level_item.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
#define TEXT_1 ""
#define TEXT_3 ""
#define TEXT_2 ""
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
extern NJS_OBJECT level_item_crystal_ring_object;
extern NJS_OBJECT level_item_light_shoes_object;
extern NJS_OBJECT level_item_jet_anklet_object;
extern NJS_OBJECT kurotama_object;
extern NJS_TEXLIST ec_alife_texlist;
extern NJS_CACTION monorail_camera_action;
extern NJS_OBJECT level_item_booster_object;
extern NJS_OBJECT level_item_laser_object;
extern NJS_OBJECT level_item_long_hammer_object;
extern NJS_OBJECT level_item_fighting_gloves_object;
extern NJS_OBJECT level_item_shovel_claws_object;
extern NJS_OBJECT level_item_warrior_feather_object;
extern NJS_OBJECT level_item_life_belt_object;
extern NJS_OBJECT level_item_rhythm_brooch_object;
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
void LoopTaskC(struct task *task);
void heap_init(void);
void *MAlloc(int size);
void *heap_calloc(int count, int size);
void Free(void *mem);
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
extern NJS_TEXLIST sparkle_texlist;
extern struct particle_pool_spec sparkle_pool;
void sparkle_create(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale,
                    Angle spin);
void sparkle_create_glint(NJS_POINT3 *pos, Float size, Float rate);
struct event;
struct event_path;
struct texture_pvm;
struct event_module {
    void (*entry)(int phase);
    struct texture_pvm *textures;
};
enum event_phase {
    EVENT_LOAD,
    EVENT_PLAY,
    EVENT_END,
    EVENT_UNLOAD,
    EVENT_NONE
};
enum event_ease {
    EVENT_EASE_LINEAR,
    EVENT_EASE_SMOOTH
};
enum event_camera_look {
    EVENT_CAMERA_LOOK_NONE,
    EVENT_CAMERA_LOOK_POINT,
    EVENT_CAMERA_LOOK_TASK
};
enum event_camera_follow {
    EVENT_CAMERA_FOLLOW_NONE,
    EVENT_CAMERA_FOLLOW,
    EVENT_CAMERA_FOLLOW_HEADING,
    EVENT_CAMERA_FOLLOW_LOCAL,
    EVENT_CAMERA_FOLLOW_ORBIT,
    EVENT_CAMERA_FOLLOW_PATH
};
struct event_camera_key {
    Sint16 ang_y;
    Sint16 ang_x;
    Sint16 ang_z;
    NJS_POINT3 pos;
};
struct event_camera_path {
    Uint8 unk_00[4];
    Float count;
    struct event_camera_key *keys;
};
struct event_camera {
    Uint8 pos_ease;
    Uint8 ang_ease;
    Uint16 pos_steps;
    Uint16 pos_step;
    Uint16 ang_steps;
    Uint16 ang_step;
    NJS_POINT3 pos;
    struct angles ang;
    NJS_POINT3 pos_from;
    struct angles ang_from;
    NJS_POINT3 pos_to;
    struct angles ang_to;
    Uint8 look;
    NJS_POINT3 look_pos;
    struct task *look_task;
    Uint8 follow;
    Uint16 orbit_steps;
    Uint16 orbit_step;
    NJS_POINT3 follow_pos;
    struct angles follow_ang;
    Float orbit_start_distance;
    Uint8 unk_8c[12];
    struct angles orbit_end_ang;
    Float orbit_end_distance;
    struct task *follow_task;
    Uint8 fov_ease;
    Uint16 fov_steps;
    Uint16 fov_step;
    Angle fov;
    Angle fov_from;
    Angle fov_to;
    struct event_camera_path *path;
    Float path_frame;
    Float path_speed;
    struct event *owner;
};
struct event_pad_key {
    Uint8 buttons;
    Sint8 ang;
    Uint8 stroke;
};
struct event_pad_recording {
    const struct event_pad_key *keys;
    Sint32 count;
};
extern struct event_camera event_camera;
void event_init(void);
void event_toggle_messages(void);
void event_pads_on(void);
void event_pads_off(void);
void event_take_control(void);
void event_release_control(void);
Bool event_check_music(void);
void EV_Load2(int number);
void event_unload(void);
void EV_Exec2(void);
void event_skip(void);
Bool event_is_playing(int unused);
Bool event_in_control(void);
Bool event_was_played(int number);
void event_wait(int steps);
void event_message_show(const char *text);
void event_message_wait(int steps, const char *text);
void event_message_printf(const char *format, ...);
void event_message_wait_printf(int steps, const char *format, ...);
void event_message_close(void);
void event_message_clear(void);
int event_message_choose(const char *text);
Sint32 event_load_texlist(NJS_TEXLIST *texlist);
Sint32 event_release_texlist(NJS_TEXLIST *texlist);
struct task *event_get_player(int player);
void event_place_actor(struct task **slot, Float x, Float y, Float z,
                       Angle ang_x, Angle ang_y, Angle ang_z);
void event_place_task(struct task **slot, struct task *(*create)(void), Float x,
                      Float y, Float z, Angle ang_x, Angle ang_y, Angle ang_z);
void event_kill_task(struct task **slot);
void event_clear_task(struct task *task);
void event_set_pos(struct task *task, Float x, Float y, Float z);
void event_set_ang(struct task *task, Angle ang_x, Angle ang_y, Angle ang_z);
void event_set_flags(struct task *task, int flags);
void event_set_offset(struct task *task, Float x, Float y, Float z);
void event_set_shadow(struct task *task, Float size);
void event_set_radius(struct task *task, Float radius);
void event_create_player(int player, void (*step)(struct task *task), Float x,
                         Float y, Float z, Angle ang_x, Angle ang_y,
                         Angle ang_z);
void event_kill_player(int player);
void event_reset_player(int player);
void event_play_action(struct task *task, NJS_ACTION *action,
                       NJS_TEXLIST *texlist, Float speed, int flags, int blend);
void event_play_motion(struct task *task, NJS_OBJECT *object,
                       NJS_MOTION *motion, NJS_TEXLIST *texlist, Float speed,
                       int flags, int blend);
void event_clear_motions(struct task *task);
void event_wait_motions(struct task *task);
void event_play_path(struct task *task, struct event_path *path, Float speed,
                     int flags);
void event_clear_paths(struct task *task);
void event_wait_paths(struct task *task);
void fun_8c04d0c6(struct task *task, int value);
void event_play_pad(int port, const struct event_pad_recording *recording);
void event_wait_start_released(int port);
void event_look_clear(struct task *task);
void event_look_at_task(struct task *task, struct task *target, Float x,
                        Float y, Float z);
void event_look_at(struct task *task, Float x, Float y, Float z);
void event_look_angles(struct task *task, Angle ang_x, Angle ang_y,
                       Angle ang_z);
void event_run_clear(struct task *task);
void event_run_to(struct task *task, Float x, Float y, Float z);
void event_run_to_speed(struct task *task, Float x, Float y, Float z,
                        Float speed, Float accel);
void event_turn_by(struct task *task, Angle ang_x, Angle ang_y, Angle ang_z);
void event_turn_to(struct task *task, Angle ang_y);
void event_run_wait(struct task *task);
void event_camera_take(void);
void event_camera_release(void);
void event_camera_step(void);
void event_camera_set_ang(enum event_ease ease, int steps, Angle ang_x,
                          Angle ang_y, Angle ang_z);
void event_camera_set_pos(enum event_ease ease, int steps, Float x, Float y,
                          Float z);
void event_camera_set_pos_offset(enum event_ease ease, int steps,
                                 struct task *task, Float x, Float y, Float z);
void event_camera_set_pos_local(enum event_ease ease, int steps,
                                struct task *task, Float x, Float y, Float z);
void event_camera_set_pos_heading(enum event_ease ease, int steps,
                                  struct task *task, Float x, Float y, Float z);
void event_camera_look_clear(void);
void event_camera_look_at(enum event_ease ease, int steps, Float x, Float y,
                          Float z, Angle roll);
void event_camera_look_at_task(enum event_ease ease, int steps,
                               struct task *task, Float x, Float y, Float z,
                               Angle roll);
void event_camera_follow_clear(void);
void event_camera_follow(struct task *task);
void event_camera_follow_local(struct task *task);
void event_camera_follow_heading(struct task *task);
void event_camera_orbit(enum event_ease ease, int steps, struct task *task,
                        Float height, Angle ang_x, Angle ang_y, Angle ang_z,
                        Angle to_x, Angle to_y, Angle to_z, Float distance,
                        Float to_distance);
void event_camera_set_fov(Sint8 ease, int steps, Angle fov);
void event_camera_set_path(struct event_camera_path *path, Float speed);
void event_camera_wait_path(void);
void event_talk_start(struct task *task, const char *text);
void event_talk_stop(struct task *task);
void event_voice_wait(void);
void event_voice_play(int voice);
void event_voice_stop(void);
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
int GetGlobalTime(void);
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
struct level_item;
struct task;
enum level_item_kind {
    LEVEL_ITEM_CRYSTAL_RING = 0,
    LEVEL_ITEM_LIGHT_SHOES = 1,
    LEVEL_ITEM_ANCIENT_LIGHT = 2,
    LEVEL_ITEM_JET_ANKLET = 3,
    LEVEL_ITEM_RHYTHM_BROOCH = 4,
    LEVEL_ITEM_FIGHTING_GLOVES = 5,
    LEVEL_ITEM_SHOVEL_CLAWS = 6,
    LEVEL_ITEM_LONG_HAMMER = 7,
    LEVEL_ITEM_WARRIOR_FEATHER = 8,
    LEVEL_ITEM_LASER = 9,
    LEVEL_ITEM_BOOSTER = 10,
    LEVEL_ITEM_POWER_ROD = 11,
    LEVEL_ITEM_LIFE_BELT = 12,
    LEVEL_ITEM_LURE = 13,
    LEVEL_ITEM_COUNT = LEVEL_ITEM_LURE + 5
};
extern struct level_item *level_item_current;
extern int big_lure_count;
extern NJS_TEXLIST ancient_light_texlist;
void level_item_create(int kind, NJS_POINT3 *pos);
void level_item_step(struct task *task);
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
Bool FUN_8c091852(struct task *task);
Bool placement_far_from_camera_by(struct task *task, Float range);
Bool placement_try_leave(struct task *task);
Bool placement_try_leave_by(struct task *task, Float range);
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
extern NJS_OBJECT big_object;
extern NJS_OBJECT big_upper_arm_minus_z;
extern NJS_OBJECT big_forearm_minus_z;
extern NJS_OBJECT big_hand_minus_z;
extern NJS_OBJECT big_upper_arm_plus_z;
extern NJS_OBJECT big_forearm_plus_z;
extern NJS_OBJECT big_hand_plus_z;
extern NJS_OBJECT big_thigh_minus_z;
extern NJS_OBJECT big_shin_minus_z;
extern NJS_OBJECT big_thigh_plus_z;
extern NJS_OBJECT big_shin_plus_z;
extern NJS_OBJECT big_foot_minus_z;
extern NJS_OBJECT big_toes_minus_z;
extern NJS_OBJECT big_foot_plus_z;
extern NJS_OBJECT big_toes_plus_z;
extern NJS_OBJECT big_fingers_minus_z;
extern NJS_OBJECT big_fingers_plus_z;
extern NJS_OBJECT big_head_end;
extern NJS_OBJECT big_pupil_plus_z;
extern NJS_OBJECT big_pupil_minus_z;
extern NJS_OBJECT big_neck[];
extern NJS_OBJECT big_belt_torso[];
extern NJS_OBJECT big_torso;
extern NJS_POINT3 big_belt_torso_flat[];
extern NJS_POINT3 big_belt_torso_full[];
extern NJS_POINT3 big_belt_torso_points[];
extern NJS_POINT3 big_belt_piece_flat[];
extern NJS_POINT3 big_belt_piece_full[];
extern NJS_POINT3 big_belt_piece_points[];
extern NJS_OBJECT big_rod[];
extern NJS_MODEL big_power_rod_model;
extern NJS_OBJECT big_power_rod_reel;
extern NJS_OBJECT big_power_rod_object;
extern NJS_MODEL big_rod_model;
extern NJS_OBJECT big_rod_reel;
extern NJS_OBJECT big_mouth;
extern NJS_OBJECT big_head[];
extern NJS_OBJECT big_head_blend;
extern NJS_MOTION big_mouth_shapes;
extern NJS_MODEL big_head_model;
extern NJS_MODEL big_head_sway_model;
extern NJS_ACTION big_stand_action;
extern NJS_ACTION big_land_action;
extern NJS_ACTION big_walk_action;
extern NJS_ACTION big_run_action;
extern NJS_ACTION big_jump_action;
extern NJS_ACTION big_fall_start_action;
extern NJS_ACTION big_fall_action;
extern NJS_TEXLIST fishing_texlist;
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
struct task *player_get_task(Uint8 player);
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
void SetLookingPointP(Uint8 player, NJS_POINT3 *pos);
void player_set_look_angles(Uint8 player, struct angles *ang);
void CancelLookingAtP(Uint8 player);
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
extern NJS_TEXLIST sonic_texlist;
extern NJS_TEXLIST tails_texlist;
extern NJS_TEXLIST knuckles_texlist;
extern NJS_TEXLIST knu_eff_texlist;
extern NJS_TEXLIST e102_texlist;
extern NJS_TEXNAME e102beam_textures[14];
extern NJS_TEXLIST e102beam_texlist;
extern NJS_TEXLIST e102effect_texlist;
extern NJS_TEXLIST amy_texlist;
extern NJS_TEXLIST amy_eff_texlist;
extern NJS_TEXLIST big_texlist;
extern NJS_TEXLIST eggman_texlist;
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
int GetPlayerNumber(void);
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
Bool SeqCheckFlag(int flag);
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
int sound_play_at(int se, int id, int priority, int volume, Float x, Float y,
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
struct thread;
enum bitmap_mode { BITMAP_PLAIN, BITMAP_EVENT };
struct bitmap {
    Uint8 mode;
    Sint16 x;
    Sint16 y;
    Uint16 width;
    Uint16 height;
    Uint16 texture_width;
    Uint16 texture_height;
    Sint16 cursor_x;
    Sint16 cursor_y;
    Sint16 letter_spacing;
    Sint16 line_spacing;
    Uint16 ink;
    NJS_COLOR text_color;
    NJS_COLOR back_color;
    Uint16 *pixels;
    Uint32 index;
    NJS_TEXLIST texlist;
    NJS_TEXNAME texname;
};
extern Sint8 messages_shown;
struct bitmap *bitmap_alloc(struct bitmap *bitmap, int x, int y, int width,
                            int height, int index);
void bitmap_free(struct bitmap *bitmap);
struct bitmap *bitmap_init(struct bitmap *bitmap, int x, int y, int width,
                           int height, int index, void *memory);
void bitmap_release(struct bitmap *bitmap);
void bitmap_alloc_window(struct bitmap *bitmap);
void bitmap_init_window(struct bitmap *bitmap);
void bitmap_clear(struct bitmap *bitmap);
void bitmap_newline(struct bitmap *bitmap);
void bitmap_print(struct bitmap *bitmap, const char *text);
void bitmap_printf(struct bitmap *bitmap, const char *format, ...);
void bitmap_queue(struct bitmap *bitmap);
void bitmap_queue_add(struct bitmap *bitmap);
void bitmap_clear_queue(void);
void bitmap_flush_queue(void);
void bitmap_draw(struct bitmap *bitmap);
void bitmap_fade_in(struct bitmap *bitmap);
void bitmap_fade_out(struct bitmap *bitmap);
void bitmap_fade_in_text(struct bitmap *bitmap);
void bitmap_fade_out_text(struct bitmap *bitmap);
void bitmap_wait(struct bitmap *bitmap, int steps);
struct thread *bitmap_choose(const char *text);
struct thread *bitmap_choose_lines(int count, const char **lines);
void FUN_8c055878(char **pages);
void bitmap_show_pages_until_b(char **pages);
Bool bitmap_pages_active(void);
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
enum level_item_mode {
    LEVEL_ITEM_INIT,
    LEVEL_ITEM_WAIT,
    LEVEL_ITEM_TAKEN,
    LEVEL_ITEM_HINT,
    LEVEL_ITEM_STILL,
    LEVEL_ITEM_KILL
};
enum FUN_8c06ad74 { HINT_WAIT, HINT_SHOWN };
enum level_item_area {
    AREA_STATION_SQUARE,
    AREA_MYSTIC_RUINS,
    AREA_EGG_CARRIER,
    AREA_OTHER
};
struct level_item_spark {
    struct angles ang;
    struct angles spin;
    Float frame;
    Float rate;
};
struct level_item {
    Uint32 flags;
    Sint32 kind;
    Sint32 time;
    Float wave_frames[3];
    Float wave_fades[3];
    NJS_POINT3 pos;
    struct angles ang;
    Sint32 hint_mode;
    Sint32 hint_time;
    Uint8 unk_44[24];
    struct level_item_spark sparks[4];
};
struct level_item_extra {
    struct level_item *item;
};
struct level_item_model {
    NJS_OBJECT *object;
    NJS_TEXLIST *texlist;
};
struct level_item_place {
    Sint16 character;
    Sint32 area;
};
struct sprite_look {
    Float sx, sy;
    Angle ang;
    NJS_TEXLIST *tlist;
    NJS_TEXANIM *tanim;
};
struct level_item_event {
    Sint32 unk_00;
    Sint32 event;
};
extern NJS_OBJECT big_lure_0;
extern NJS_OBJECT big_lure_1;
extern NJS_OBJECT big_lure_2;
extern NJS_OBJECT big_lure_3;
extern NJS_OBJECT big_lure_4;
static void level_item_destroy(struct task *task);
static void level_item_draw(struct task *task);
static struct level_item *level_item_alloc(void);
static Bool level_item_in_area(Sint16 kind, int area);
static void FUN_8c069bae(Sint16 character, int area, Sint32 *kind);
static Bool FUN_8c069c20(int kind);
static void level_item_draw_stand(struct task *task);
static void level_item_draw_waves(struct task *task);
static void FUN_8c06a086(struct task *task);
static void level_item_draw_item(struct task *task);
static void level_item_touch(struct task *task);
static void FUN_8c06a40a(struct task *task);
static void levelupitemEffectManager(struct task *task);
static void levelupitemPlayerEyeCheck(struct task *task);
void FUN_8c06a7d0(int kind);
static void level_item_print(struct task *task);
static void level_item_draw_ancient_light(void);
static void level_item_draw_glow(void);
static void level_item_draw_spark(int spark);
static void level_item_init_sparks(void);
static void FUN_8c06ad74(struct task *task);
extern const Sint32 level_item_flags[LEVEL_ITEM_COUNT];
extern const struct level_item_model level_item_models[LEVEL_ITEM_COUNT];
extern const struct level_item_place level_item_places[LEVEL_ITEM_COUNT];
extern const Uint32 level_item_light_textures[8];
extern const Uint32 level_item_wave_textures[2][4];
extern const char level_item_label[];
extern const NJS_TEXANIM level_item_glow_texanims[8];
extern const NJS_TEXANIM level_item_spark_texanims[8];
extern const NJS_VECTOR level_item_spark_offset;
extern struct collision_shape level_item_shape[1];
extern char *level_item_lure_hints[5][3];
extern char **level_item_lure_pages[5];
extern NJS_TEXNAME ancient_light_textures[16];
extern NJS_TEXLIST ancient_light_texlist;
extern struct level_item_event level_item_events[LEVEL_ITEM_LURE];
extern char *level_item_names[LEVEL_ITEM_COUNT + 1];
extern NJS_SPRITE level_item_glow_sprite;
extern Float level_item_spark_x;
extern Float level_item_spark_y;
extern Float level_item_spark_z;
extern struct sprite_look level_item_spark_look;
extern struct level_item *level_item_current;
extern int big_lure_count;
void level_item_create(int kind, NJS_POINT3 *pos)
{
    struct task *task = CreateElementalTask(
        0x1 | 0x2 | 0x4 | 0x8, 3, level_item_step);
    struct task_work *work = task->work;
    ((work)->scl.x) = kind;
    work->pos = *pos;
}
void level_item_step(struct task *task)
{
    struct task_work *work = task->work;
    int i;
    if (FUN_8c091852(task)) {
        task->draw = ((void *)0);
    } else {
        task->draw = level_item_draw;
        level_item_current = ((struct level_item_extra *)(task)->extra)->item;
        if ((int)((work)->scl.x) < 0) {
            ((work)->scl.x) = LEVEL_ITEM_COUNT - 1;
        } else if ((int)((work)->scl.x) >= LEVEL_ITEM_COUNT) {
            ((work)->scl.x) = 0;
        }
        if (OnEdit(task)) {
            if (work->mode == LEVEL_ITEM_INIT) {
                work->mode++;
                ((struct level_item_extra *)(task)->extra)->item = level_item_alloc();
                task->destructor = level_item_destroy;
                task->draw = level_item_draw;
            }
            level_item_current = ((struct level_item_extra *)(task)->extra)->item;
            level_item_current->pos = work->pos;
            level_item_current->ang = work->ang;
            level_item_current->flags = 0x1;
            FUN_8c069c20((int)((work)->scl.x));
            level_item_init_sparks();
            level_item_draw(task);
            level_item_print(task);
        } else {
            switch (work->mode) {
            case LEVEL_ITEM_INIT:
                work->mode = LEVEL_ITEM_WAIT;
                ((struct level_item_extra *)(task)->extra)->item = level_item_alloc();
                level_item_current = ((struct level_item_extra *)(task)->extra)->item;
                task->destructor = level_item_destroy;
                CCL_Init(task, &level_item_shape[0], 4, 1,
                               3);
                level_item_wave_object->model->mats->attrflags &=
                    ~(0x00010000 | 0x00008000);
                level_item_current->pos = work->pos;
                level_item_current->ang = work->ang;
                level_item_current->time = 0;
                level_item_current->flags = 0x1;
                level_item_init_sparks();
                for (i = 0; i < 3; i++) {
                    level_item_current->wave_frames[i] = 0.0F;
                    level_item_current->wave_fades[i] = -1.0F;
                }
                if (FUN_8c069c20((int)((work)->scl.x))) {
                    work->mode = LEVEL_ITEM_KILL;
                }
                break;
            case LEVEL_ITEM_WAIT:
                level_item_draw(task);
                level_item_touch(task);
                FUN_8c06a086(task);
                FUN_8c06a40a(task);
                levelupitemPlayerEyeCheck(task);
                break;
            case LEVEL_ITEM_TAKEN:
                level_item_draw(task);
                levelupitemEffectManager(task);
                FUN_8c06a086(task);
                FUN_8c06ad74(task);
                break;
            case LEVEL_ITEM_HINT:
                FUN_8c06ad74(task);
                break;
            case LEVEL_ITEM_STILL:
                level_item_draw(task);
                break;
            case LEVEL_ITEM_KILL:
            default:
                DeadOut(task);
                break;
            }
        }
        if (level_item_current->flags & 0x2) {
            LoopTaskC(task);
        }
    }
}
static void level_item_destroy(struct task *task)
{
    if (((struct level_item_extra *)(task)->extra)->item != ((void *)0)) {
        Free(((struct level_item_extra *)(task)->extra)->item);
        ((struct level_item_extra *)(task)->extra)->item = ((void *)0);
    }
}
static void level_item_draw(struct task *task)
{
    struct task_work *work = task->work;
    if (dsCheckViewV(work->pos.x, work->pos.y, work->pos.z, 20.0F)) {
        level_item_current = ((struct level_item_extra *)(task)->extra)->item;
        switch (work->mode) {
        case LEVEL_ITEM_WAIT:
            level_item_draw_stand(task);
            level_item_draw_item(task);
            break;
        case LEVEL_ITEM_TAKEN:
            level_item_draw_waves(task);
            level_item_draw_item(task);
            break;
        }
    }
}
static struct level_item *level_item_alloc(void)
{
    struct level_item *item;
    Uint8 *p;
    Uint8 *end;
    struct level_item *r;
    if ((item = MAlloc(sizeof(*item))) != ((void *)0)) {
    }
    r = item;
    p = (Uint8 *)r;
    end = (Uint8 *)item + sizeof(*r);
    while (p < end) {
        *p++ = 0;
        *p++ = 0;
    }
    return item;
}
static Bool level_item_in_area(Sint16 kind, int area)
{
    if (kind < LEVEL_ITEM_LURE) {
        return level_item_places[kind].area == area;
    }
    return (1);
}
static Bool level_item_is_for(Sint16 kind, Sint16 character)
{
    return level_item_places[kind].character == character;
}
static void FUN_8c069bae(Sint16 character, int area, Sint32 *kind)
{
    Sint16 i;
    i = 0;
    while (!level_item_is_for(i, character) || !level_item_in_area(i, area)) {
        i++;
    }
    *kind = i;
}
static Bool FUN_8c069c20(int kind)
{
    Sint16 character = GetPlayerNumber();
    int area;
    switch (GetStageNumber() >> 8) {
    case 26:
    case 27:
    case 28:
        area = AREA_STATION_SQUARE;
        break;
    case 29:
    case 30:
    case 31:
    case 32:
        area = AREA_EGG_CARRIER;
        break;
    case 33:
    case 34:
        area = AREA_MYSTIC_RUINS;
        break;
    default:
        area = AREA_OTHER;
    }
    if (!level_item_is_for(kind, character) ||
        !level_item_in_area(kind, area)) {
        FUN_8c069bae(character, area, &level_item_current->kind);
    } else {
        level_item_current->kind = kind;
    }
    if (level_item_current->kind >= LEVEL_ITEM_LURE) {
        if (((GetStageNumber() & 0xff00) == (((32)) << 8 | (0)))) {
            if (SeqCheckFlag(478)) {
                return (1);
            }
        } else if (((GetStageNumber() & 0xff00) == (((8)) << 8 | (0)))) {
            if (SeqCheckFlag(479)) {
                return (1);
            }
        } else if (((GetStageNumber() & 0xff00) == (((26)) << 8 | (0))) ||
                   ((GetStageNumber() & 0xff00) == (((27)) << 8 | (0))) ||
                   ((GetStageNumber() & 0xff00) == (((28)) << 8 | (0)))) {
            if (SeqCheckFlag(480)) {
                return (1);
            }
        } else if (((GetStageNumber() & 0xff00) == (((33)) << 8 | (0)))) {
            if (SeqCheckFlag(481)) {
                return (1);
            }
        }
        big_lure_count = 1;
        if (SeqCheckFlag(478)) {
            big_lure_count++;
        }
        if (SeqCheckFlag(481)) {
            big_lure_count++;
        }
        if (SeqCheckFlag(478)) {
            big_lure_count++;
        }
        if (SeqCheckFlag(482)) {
            big_lure_count++;
        }
        if (level_item_current->kind >= LEVEL_ITEM_LURE) {
            level_item_current->kind = big_lure_count + LEVEL_ITEM_LURE;
            kind = level_item_current->kind;
        }
    }
    return SeqCheckFlag(level_item_flags[kind]) |
           (level_item_places[kind].character != character);
}
static void level_item_draw_stand(struct task *task)
{
    struct task_work *work = task->work;
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    SetRegularTexture();
    late_DrawObject(level_item_light_object);
    late_DrawObject(&level_item_floor_object);
    njPopMatrix(1);
}
static void level_item_draw_waves(struct task *task)
{
    struct task_work *work = task->work;
    Float fade;
    int i;
    if (level_item_current->time < 180 / 2) {
        fade = level_item_current->time * (2.0F / 180);
    } else {
        fade = (180 - level_item_current->time) * (2.0F / 180);
    }
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.z) ? (njRotateZ)(((void *)0), (work->ang.z)) : (void)0);
    ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    SetRegularTexture();
    for (i = 0; i < 3; i++) {
        SetMaterial(((level_item_current->wave_fades[i] + 1.0F) * fade) -
                              1.0F,
                          0.0F, 0.0F, 0.0F);
        ds_ActionClip(level_item_wave_action, level_item_current->wave_frames[i]);
    }
    if (level_item_current->time < 180 / 2) {
        fade = 1.0F;
    }
    if (level_item_current->kind >= LEVEL_ITEM_LURE) {
        SetMaterial(fade - 1.0F, 0.0F, 0.0F,
                          level_item_current->time / 180);
    } else {
        SetMaterial(fade - 1.0F, 0.0F,
                          level_item_current->time / 180, 0.0F);
    }
    late_DrawObject(&level_item_floor_object);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njPopMatrix(1);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
static void FUN_8c06a086(struct task *task)
{
    struct task_work *work = task->work;
    int i;
    switch (work->mode) {
    case LEVEL_ITEM_WAIT:
        level_item_light_object->model->mats->attr_texId =
            level_item_light_textures[((Uint32)GetGlobalTime() >> 1) & 7];
        break;
    case LEVEL_ITEM_TAKEN:
        if (level_item_current->kind >= LEVEL_ITEM_LURE) {
            level_item_wave_object->model->mats->attr_texId =
                level_item_wave_textures[1][((Uint32)GetGlobalTime() >> 1) & 3];
        } else {
            level_item_wave_object->model->mats->attr_texId =
                level_item_wave_textures[0][((Uint32)GetGlobalTime() >> 1) & 3];
        }
        for (i = 0; i < 3; i++) {
            level_item_current->wave_frames[i] += 0.25F;
            if (level_item_current->wave_frames[i] >=
                level_item_wave_action->motion->nbFrame - 1.0F) {
                level_item_current->wave_frames[i] = 0.0F;
            }
        }
        for (i = 0; i < 3; i++) {
            if (level_item_current->wave_frames[i] < 6.0F) {
                level_item_current->wave_fades[i] =
                    (level_item_current->wave_frames[i] * (1.0F / 6.0F)) - 1.0F;
            } else if (level_item_current->wave_frames[i] >
                       level_item_wave_action->motion->nbFrame - 7.0F) {
                level_item_current->wave_fades[i] =
                    ((level_item_wave_action->motion->nbFrame -
                      level_item_current->wave_frames[i] - 1.0F) *
                     (1.0F / 6.0F)) -
                    1.0F;
            } else {
                level_item_current->wave_fades[i] = 0.0F;
            }
        }
        break;
    }
    for (i = 0; i < 4; i++) {
        level_item_current->sparks[i].frame +=
            level_item_current->sparks[i].rate;
        level_item_current->sparks[i].ang.x +=
            level_item_current->sparks[i].spin.x;
        level_item_current->sparks[i].ang.y +=
            level_item_current->sparks[i].spin.y;
    }
}
#else
static void FUN_8c06a086(struct task *task)
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
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37;
}
#endif
static void level_item_draw_item(struct task *task)
{
    if (level_item_current->kind >= LEVEL_ITEM_COUNT) {
        return;
    }
    if (!(level_item_current->flags & 0x1)) {
        return;
    }
    if (level_item_models[level_item_current->kind].object != ((void *)0)) {
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &level_item_current->pos);
        ((level_item_current->ang.z) ? (njRotateZ)(((void *)0), (level_item_current->ang.z)) : (void)0);
        ((level_item_current->ang.x) ? (njRotateX)(((void *)0), (level_item_current->ang.x)) : (void)0);
        ((level_item_current->ang.y) ? (njRotateY)(((void *)0), (level_item_current->ang.y)) : (void)0);
        njSetTexture(level_item_models[level_item_current->kind].texlist);
        late_DrawObject(level_item_models[level_item_current->kind].object);
        njPopMatrix(1);
    } else if (level_item_current->kind == LEVEL_ITEM_ANCIENT_LIGHT) {
        level_item_draw_ancient_light();
    }
}
static void level_item_touch(struct task *task)
{
    struct task_work *work = task->work;
    struct collision_work *collision = work->collision;
    struct collision_work *hit = collision->hit;
    if ((collision->flags & 0x2) && hit->kind == 0) {
        dsPlay_oneshot(11, 0, 0, 0);
        work->mode = LEVEL_ITEM_TAKEN;
    }
    EntryColliList(work);
}
static void FUN_8c06a40a(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VECTOR speed;
    NJS_POINT3 pos;
    level_item_current->ang.y += ((Angle)(((3) * 65536.0) / 360.0));
    level_item_current->pos.y = work->pos.y + 10.0F;
    if (rand() * (1.0F / (32767 + 1)) < 0.1F) {
        speed.x = 0.0F;
        speed.y = 0.0F;
        speed.z = 0.0F;
        pos.x = level_item_current->pos.x + (rand() * (1.0F / (32767 + 1)) * 6.0F) - 3.0F;
        pos.y = level_item_current->pos.y + (rand() * (1.0F / (32767 + 1)) * 6.0F) - 3.0F;
        pos.z = level_item_current->pos.z + (rand() * (1.0F / (32767 + 1)) * 6.0F) - 3.0F;
        sparkle_create_glint(&pos, (rand() * (1.0F / (32767 + 1)) * 0.25F) + 0.1F,
                             ((rand() * (1.0F / (32767 + 1))) + 0.5F) * 0.5F);
    }
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
static void levelupitemEffectManager(struct task *task)
{
    struct task_work *work = task->work;
    int i;
    int last_upgrade;
    if (level_item_current->time == 0) {
        for (i = 0; i < 3; i++) {
            level_item_current->wave_frames[i] =
                i * (level_item_wave_action->motion->nbFrame - 1.0F) *
                (1.0F / 3);
            level_item_current->wave_fades[i] = -1.0F;
        }
    } else {
        last_upgrade = LEVEL_ITEM_LIFE_BELT;
        if (level_item_current->time == 180 / 2) {
            if (level_item_current->kind <= last_upgrade) {
                GetPlayerWorkPointer(0)->upgrades |= 1 << level_item_current->kind;
                if (level_item_current->kind <= last_upgrade) {
                    player_event_end(0);
                    EV_Load2(
                        level_item_events[level_item_current->kind].event);
                    EV_Exec2();
                }
            } else {
                big_lure_count++;
                if (big_lure_count > 4) {
                    big_lure_count = 4;
                }
            }
            FUN_8c06a7d0(level_item_current->kind);
            level_item_current->flags &= ~0x1;
            { extern int save_write_wait(void); save_write_wait(); }
        } else if (level_item_current->time == 180) {
            work->mode = LEVEL_ITEM_HINT;
        } else if (level_item_current->time < 180 / 2 &&
                   level_item_current->kind <= last_upgrade) {
            player_event_run(0, work->pos.x, work->pos.z);
        }
    }
    level_item_current->time++;
}
#else
static void levelupitemEffectManager(struct task *task)
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
}
#endif
static void levelupitemPlayerEyeCheck(struct task *task)
{
    NJS_VECTOR away;
    away.x = playertwp[0]->pos.x - level_item_current->pos.x;
    away.y = playertwp[0]->pos.y - level_item_current->pos.y;
    away.z = playertwp[0]->pos.z - level_item_current->pos.z;
    if (njScalor(&away) < 40.0F) {
        if (!(level_item_current->flags & 0x4)) {
            SetLookingPointP(0, &level_item_current->pos);
        }
        level_item_current->flags |= 0x4;
    } else {
        if (level_item_current->flags & 0x4) {
            CancelLookingAtP(0);
        }
        level_item_current->flags &= ~0x4;
    }
    if (task->work->mode != LEVEL_ITEM_WAIT) {
        CancelLookingAtP(0);
        level_item_current->flags &= ~0x4;
    }
}
void FUN_8c06a7d0(int kind)
{
    if (kind <= LEVEL_ITEM_LIFE_BELT) {
        event_flag_set(level_item_flags[kind]);
    } else if (((GetStageNumber() & 0xff00) == (((32)) << 8 | (0)))) {
        event_flag_set(478);
    } else if (((GetStageNumber() & 0xff00) == (((8)) << 8 | (0)))) {
        event_flag_set(479);
    } else if (((GetStageNumber() & 0xff00) == (((26)) << 8 | (0))) ||
               ((GetStageNumber() & 0xff00) == (((27)) << 8 | (0))) ||
               ((GetStageNumber() & 0xff00) == (((28)) << 8 | (0)))) {
        event_flag_set(480);
    } else if (((GetStageNumber() & 0xff00) == (((33)) << 8 | (0)))) {
        event_flag_set(481);
    }
}
static void level_item_print(struct task *task)
{
    njPrintC(((17) << 16 | ((19))), level_item_label);
    njPrintC(((20) << 16 | (20)), level_item_names[level_item_current->kind]);
}
static void level_item_draw_ancient_light(void)
{
    int i;
    level_item_draw_glow();
    for (i = 0; i < 4; i++) {
        level_item_draw_spark(i);
    }
}
static void level_item_draw_glow(void)
{
    level_item_glow_sprite.p = level_item_current->pos;
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njDrawSprite3D(&level_item_glow_sprite, GetGlobalTime() & 7,
                   0x20 | 0x10);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
}
static void level_item_draw_spark(int spark)
{
    NJS_VECTOR offset;
    offset = level_item_spark_offset;
    njPushMatrix(&nj_unit_matrix_);
    ((level_item_current->sparks[spark].ang.x) ? (njRotateX)(((void *)0), (level_item_current->sparks[spark].ang.x)) : (void)0);
    ((level_item_current->sparks[spark].ang.y) ? (njRotateY)(((void *)0), (level_item_current->sparks[spark].ang.y)) : (void)0);
    njCalcVector(((void *)0), &offset, &offset);
    njPopMatrix(1);
    level_item_spark_x = level_item_current->pos.x + offset.x;
    level_item_spark_y = level_item_current->pos.y + offset.y;
    level_item_spark_z = level_item_current->pos.z + offset.z;
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njDrawSprite3D(((NJS_SPRITE *)&level_item_spark_x),
                   (int)level_item_current->sparks[spark].frame % 8U,
                   0x20 | 0x10);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 10);
}
static void level_item_init_sparks(void)
{
    int i;
    for (i = 0; i < 4; i++) {
        level_item_current->sparks[i].ang.x =
            (Angle)((i * 45) * (65536.0F / 360.0F));
        level_item_current->sparks[i].spin.y =
            (Angle)((3.0F + (rand() * (1.0F / (32767 + 1)) * 2.0F)) * (65536.0F / 360.0F));
        if (rand() * (1.0F / (32767 + 1)) > 0.5F) {
            level_item_current->sparks[i].spin.y =
                -level_item_current->sparks[i].spin.y;
        }
        level_item_current->sparks[i].rate =
            1.0F / (1.0F + (rand() * (1.0F / (32767 + 1)) * 5.0F));
    }
}
static void FUN_8c06ad74(struct task *task)
{
    level_item_current->hint_time++;
    switch (level_item_current->hint_mode) {
    case HINT_WAIT:
        if (level_item_current->hint_time > 90) {
            level_item_current->hint_mode = HINT_SHOWN;
            if (level_item_current->kind >= LEVEL_ITEM_LURE) {
                extern int region_export; extern char **level_item_lure_pages_eu[];
                FUN_8c055878(level_item_lure_pages_eu[region_export]);
            }
        }
        break;
    case HINT_SHOWN:
        if (level_item_current->hint_time > 180) {
            task->work->mode = LEVEL_ITEM_KILL;
            level_item_current->flags &= ~0x2;
        }
        break;
    }
}
