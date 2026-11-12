/* @unit 0CB813C0-0CB8176C +r04 +egflags +pool32 +poolafter=AL_FaceEyeLidControl +asmfunc=FUN_0cb81642:0cb8176c */
/* Ported from the Japanese release's modules/al_race/body.c (tools/jpport/mkunit_ov.py): its C rebuilds this range byte for byte. */
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
enum animal_kind {
    ANIMAL_GOMA = 0,
    ANIMAL_PEN = 1,
    ANIMAL_RAKO = 2,
    ANIMAL_KUJA = 3,
    ANIMAL_TUBA = 4,
    ANIMAL_OUM = 5,
    ANIMAL_BANB = 6,
    ANIMAL_USA = 7,
    ANIMAL_WARA = 8,
    ANIMAL_GORI = 9,
    ANIMAL_LION = 10,
    ANIMAL_ZOU = 11,
    ANIMAL_MOGU = 12,
    ANIMAL_KOAR = 13,
    ANIMAL_SUKA = 14,
    ANIMAL_KINDS = 15,
    ANIMAL_CUSTOM = ANIMAL_KINDS
};
extern NJS_ACTION goma_action;
extern NJS_ACTION pen_action;
extern NJS_ACTION rako_action;
extern NJS_ACTION kuja_action;
extern NJS_ACTION tuba_action;
extern NJS_ACTION oum_action;
extern NJS_ACTION banb_action;
extern NJS_ACTION usa_action;
extern NJS_ACTION wara_action;
extern NJS_ACTION gori_action;
extern NJS_ACTION lion_action;
extern NJS_ACTION zou_action;
extern NJS_ACTION mogu_action;
extern NJS_ACTION koar_action;
extern NJS_ACTION suka_action;
struct animal_model {
    NJS_POINT3 pos;
    Float speed;
    NJS_ACTION *action;
    NJS_TEXLIST *texlist;
};
struct task_work *animal_create(Float x, Float y, Float z,
                                void (*start)(struct task *task));
struct task_work *animal_create_staying(Float x, Float y, Float z,
                                        void (*start)(struct task *task));
void animal_start_goma(struct task *task);
void animal_start_pen(struct task *task);
void animal_start_tuba(struct task *task);
void animal_start_kuja(struct task *task);
void animal_start_oum(struct task *task);
void animal_start_koar(struct task *task);
void animal_start_wara(struct task *task);
void animal_start_banb(struct task *task);
void animal_start_usa(struct task *task);
void animal_start_mogu(struct task *task);
void animal_start_zou(struct task *task);
void animal_start_lion(struct task *task);
void animal_start_gori(struct task *task);
void animal_start_suka(struct task *task);
void animal_start_rako(struct task *task);
struct task_work *animal_create_custom(struct animal_model *model,
                                       void (*destructor)(struct task *task));
enum garden {
    GARDEN_STATION_SQUARE,
    GARDEN_EGG_CARRIER,
    GARDEN_MYSTIC_RUINS,
    GARDEN_COUNT
};
enum chao_type {
    CHAO_CHILD,
    CHAO_STANDARD,
    CHAO_SWIM,
    CHAO_FLY,
    CHAO_RUN,
    CHAO_POWER,
    CHAO_CHAOS,
    CHAO_EGG,
    CHAO_NOTHING,
    CHAO_PARTNER
};
enum chao_part {
    CHAO_PART_FHEAD,
    CHAO_PART_HORN,
    CHAO_PART_EAR,
    CHAO_PART_WING,
    CHAO_PART_HAND,
    CHAO_PART_FOOT,
    CHAO_PART_TAIL,
    CHAO_PARTS
};
struct chao_skills {
    Uint16 swim;
    Uint16 fly;
    Uint16 run;
    Uint16 power;
};
struct chao_like {
    Sint8 like;
    Uint8 raised;
};
struct race_time {
    Uint8 steps;
    Uint8 seconds;
    Uint8 minutes;
};
struct chao {
    Uint8 type;
    Uint8 garden;
    Sint8 user_like;
    Uint8 mark_c;
    Uint8 name[8];
    struct chao_skills skills;
    Uint16 hp;
    Uint16 hp_max;
    Sint8 fruit[8];
    Float h_pos;
    Float v_pos;
    Float growth;
    Uint16 like_changes;
    Uint16 life;
    Uint16 old;
    Uint16 minimal;
    Uint8 race_wins;
    Uint8 mark_h;
    Uint16 flags;
    NJS_POINT3 pos;
    Sint32 age;
    Uint32 id;
    Sint8 parts[CHAO_PARTS];
    Uint8 mark_a;
    struct chao_skills points;
    Sint8 kind;
    Sint8 agres;
    Sint8 curio;
    Uint8 charm;
    Uint8 breed;
    Uint8 sleep;
    Uint8 hunger;
    Uint8 tedious;
    Uint8 unk_64;
    Uint8 unk_65;
    Uint8 unk_66;
    Uint8 pleasure;
    Uint8 anger;
    Uint8 sorrow;
    Uint8 fear;
    Uint8 unk_6b;
    struct chao_like likes[6];
    Uint8 unk_78[0x100];
    Uint8 generation;
    Uint8 mark_o;
    Uint8 unk_17a;
    Uint8 unk_17b;
    Uint16 reincarnations;
    struct race_time race_times[5];
    Uint8 unk_18d[5];
    Uint8 jewel;
    Uint8 unk_193[0x6d];
};
struct chao_node {
    Uint8 unk_00;
    Uint8 number;
    struct chao *chao;
    struct chao_node *next;
};
extern NJS_TEXLIST extra_texlist;
struct chao *chao_get_records(void);
Uint8 *chao_get_file_data(void);
Sint8 fun_8c02616c(void);
void chao_set_carried(struct chao *chao);
struct chao *chao_get_carried(void);
void chao_set_carried_to(Sint8 garden);
void chao_clear_carried(void);
Sint8 chao_get_carried_to(void);
struct chao_node *chao_get_list(int garden);
Uint8 chao_count(int garden);
void chao_set_id(struct chao *chao, int number);
void chao_init_egg(struct chao *chao);
void chao_reborn(struct chao *chao);
void chao_breed(struct chao *first, struct chao *second, struct chao *child);
struct chao *chao_find_empty(void);
void chao_list_add(int garden, struct chao *chao);
void chao_list_remove(struct chao *chao);
Bool chao_move(struct chao *chao, int garden);
void chao_gardens_init(void);
void chao_reset(void);
void animal_icon_add(Sint8 kind);
void animal_icons_create(void);
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
enum chao_handling {
    HANDLING_FREE = 0,
    HANDLING_HELD = 1,
    HANDLING_THROWN = 2,
    HANDLING_VMS = 3,
    HANDLING_REBORN = 5
};
enum chao_move {
    MOVE_WALK = 0,
    MOVE_STOP = 1,
    MOVE_FLY = 2,
    MOVE_3 = 3,
    MOVE_SWIM = 4,
    MOVE_DESCEND = 6,
    MOVE_CLIMB = 7
};
enum motion_end { END_LOOP, END_BLEND, END_CHANGE, END_STOP };
struct chao_motion_entry {
    NJS_MOTION *motion;
    Sint16 end;
    Sint16 next;
    Float first;
    Float last;
    Float speed;
    Float blend;
};
struct chao_motion {
    Sint16 end;
    Uint16 flags;
    Uint16 timer;
    Sint16 current;
    Sint16 next;
    Sint16 id;
    Float frame;
    Uint8 unk_10[4];
    Float next_frame;
    Float ratio;
    Float rate;
    struct chao_motion_entry *table;
};
struct chao_shape {
    NJS_OBJECT *model;
    NJS_OBJECT *objects[50];
    NJS_OBJECT *start[50];
    NJS_OBJECT *center[50];
    NJS_OBJECT *fly[50];
    NJS_OBJECT *run[50];
    NJS_OBJECT *power[50];
    NJS_OBJECT *swim[50];
};
struct chao_face {
    Uint16 blink_wait;
    Uint16 blink_steps;
    Uint8 unk_04[4];
    Sint32 eyes_steps;
    Sint32 mouth_steps;
    Sint32 look_steps;
    Uint32 flags;
    Angle lid;
    Angle eye_x;
    Angle open_x;
    Angle look_x;
    Angle rest_x;
    Angle eye_z;
    Uint8 unk_30[4];
    Angle look_z;
    Angle rest_z;
    Sint16 eyes;
    Sint16 other_eyes;
    Sint16 mouth_0;
    Sint16 mouth_1;
    Sint16 other_mouth_0;
    Sint16 other_mouth_1;
};
struct chao_terrain {
    Uint16 flags;
    Uint8 unk_02[2];
    Float unk_04;
    Float query_height;
    Float unk_0c;
    Float head_height;
    Float unk_14;
    Float unk_18;
    Uint8 unk_1c[4];
    Float wall_bounce;
    Uint8 unk_24[0xc];
    Angle wall_turn;
    Float unk_34;
    Float unk_38;
    Float water_level;
    struct sides_query query;
};
struct icon_part {
    Uint16 frames;
    Uint16 texture;
    Uint16 state;
    Uint8 unk_06[10];
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    NJS_VECTOR size;
    NJS_VECTOR grow;
};
struct chao_icon {
    Uint8 unk_00[2];
    Uint16 kind;
    Uint16 timer;
    Uint16 unk_06;
    Uint8 unk_08[4];
    NJS_POINT3 pos;
    Uint8 unk_18[0x18];
    Angle phase;
    struct icon_part symbol;
    struct icon_part ball;
    Uint8 blue;
    Uint8 green;
    Uint8 red;
    Uint8 alpha;
};
struct alife_chao {
    void *unk_000;
    NJS_VECTOR speed;
    NJS_VECTOR accel;
    Uint8 unk_01c[0x10];
    Angle turn_speed;
    Uint8 unk_030[4];
    Float carry_reach;
    Uint8 unk_038[4];
    Float gravity;
    Uint8 unk_040[8];
    Sint16 mode_timer;
    Uint16 limit;
    Uint16 sound_timer;
    Uint8 unk_04e[2];
    Sint16 last_mode;
    Uint8 unk_052[0xa];
    Sint16 handling;
    Uint8 unk_05e[2];
    Uint32 flags;
    Uint16 move;
    Uint8 unk_066[6];
    Float cocoon_scale;
    Float cocoon_alpha;
    Sint32 name_alpha;
    Uint16 name_frames;
    Uint16 hit_wait;
    Angle spin;
    Sint32 unk_080;
    Uint8 unk_084[8];
    NJS_POINT3 home;
    NJS_POINT3 target;
    NJS_POINT3 last_pos;
    Float unk_0b0;
    Float unk_0b4;
    Float unk_0b8;
    Angle bob_phase;
    Angle aim;
    Angle unk_0c4;
    Uint8 unk_0c8[0xc];
    Float scale_speed;
    Float scale;
    Float h_pos;
    Float v_pos;
    Float growth;
    Uint16 unk_0e8;
    Uint8 unk_0ea[2];
    struct chao *record;
    Uint8 unk_0f0[0x22];
    Uint16 unk_112;
    Uint8 unk_114[4];
    struct chao_motion motion;
    struct chao_terrain terrain;
    struct chao_shape shape;
    NJS_TEXLIST *texlist;
    struct chao_face face;
    struct chao_icon icon;
    Uint32 player_flags;
    struct task *task;
};
extern struct collision_shape chao_collisions[];
extern Float animal_part_chances[ANIMAL_KINDS][CHAO_PARTS];
extern Sint16 animal_skill_bonuses[ANIMAL_LION + 1][4];
extern Uint8 dat_0ca84420[8];
extern Sint32 alife_paused;
struct task *alife_chao_create(struct chao *record);
int alife_chao_alloc(struct task *task, struct chao *record);
void alife_chao_remove(struct task *task);
void fun_0c9002ac(struct task_work *work, struct alife_chao *chao);
void alife_chao_create_garden(int garden);
void chao_name_draw_at(struct chao *chao, NJS_POINT3 *pos, Float scale,
                       NJS_COLOR *color);
void chao_name_step(struct task_work *work, struct alife_chao *chao);
void chao_name_draw(struct task_work *work, struct alife_chao *chao);
float acosf(float x);
float asinf(float x);
float njArcTan2(float y, float x);
float ceilf(float x);
float floorf(float x);
float modff(float value, float *iptr);
float powf(float x, float y);
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
void alife_terrain_init(struct task_work *work, struct alife_chao *chao);
int alife_find_sides(struct chao_terrain *terrain);
void alife_collide_terrain(struct task_work *work, struct alife_chao *chao);
void alife_set_target(struct task_work *work, struct alife_chao *chao,
                      NJS_POINT3 *target);
void alife_set_home(struct task_work *work, struct alife_chao *chao);
void alife_save_pos(struct task_work *work, struct alife_chao *chao);
void alife_restore_pos(struct task_work *work, struct alife_chao *chao);
Float alife_target_distance(struct task_work *work, struct alife_chao *chao);
Float alife_target_distance2(struct task_work *work, struct alife_chao *chao);
Angle alife_turn_to_target(struct task_work *work, struct alife_chao *chao);
Float alife_camera_distance_squared(Float *pos);
void alife_apply_speed(struct task_work *work, struct alife_chao *chao);
void alife_drag(struct task_work *work, struct alife_chao *chao, Float drag);
int alife_get_garden(void);
extern NJS_OBJECT *child_part_objects[ANIMAL_KINDS][12][2];
extern NJS_OBJECT *adult_part_objects[ANIMAL_KINDS][12][2];
void alife_shape_init(struct task_work *work, struct alife_chao *chao);
void alife_shape_free(struct task_work *work, struct alife_chao *chao);
void alife_shape_set_parts(struct task_work *work, struct alife_chao *chao);
void alife_shape_set_wins(struct task_work *work, struct alife_chao *chao);
void alife_shape_blend(struct task_work *work, struct alife_chao *chao);
void alife_grow_step(struct task_work *work, struct alife_chao *chao);
void alife_squash_step(struct task_work *work, struct alife_chao *chao);
void alife_chao_show(struct task_work *work, struct alife_chao *chao);
void alife_chao_draw(struct task *task);
struct race_cards {
    Uint8 unk_00[0x40];
    Uint8 loaded;
    Uint8 remaining;
    Uint8 count;
};
int race_load_cards(struct race_cards *cards, struct chao *chao);
int race_cards_busy(struct race_cards *cards);
int race_card_has_chao(struct race_cards *cards, int drive);
int race_card_loaded(struct race_cards *cards, int drive);
int race_cards_drop_absent(struct race_cards *cards);
int race_card_remains(struct race_cards *cards, int drive);
int race_cards_changed(struct race_cards *cards);
void race_card_save(struct race_cards *cards, int drive,
                    const struct chao *chao);
enum cheer_state { CHEER_WAIT, CHEER_CHOSEN, CHEER_CHEERING, CHEER_DONE };
struct race_cheer {
    Uint16 timer;
    Uint8 state;
    Uint8 rounds;
    Uint8 lane;
    Uint8 presses;
    Sint8 sound_wait;
    Uint8 unk_07;
};
struct camera_view;
struct race_game;
enum race_camera_mode {
    RACE_CAMERA_NONE,
    RACE_CAMERA_HALL,
    RACE_CAMERA_HALL_FIXED,
    RACE_CAMERA_AHEAD,
    RACE_CAMERA_COURSE_FIXED,
    RACE_CAMERA_FOLLOW,
    RACE_CAMERA_FRONT,
    RACE_CAMERA_FRONT_2,
    RACE_CAMERA_BEHIND,
    RACE_CAMERA_WATCH,
    RACE_CAMERA_FINISH,
    RACE_CAMERA_NONE_2,
    RACE_CAMERA_FREE,
    RACE_CAMERA_EDITOR
};
enum race_camera_finish_phase {
    FINISH_HOLD,
    FINISH_HOLD_2,
    FINISH_MOVE,
    FINISH_CIRCLE
};
union race_camera_state {
    struct {
        Uint8 at_edge;
        Uint8 unk_01;
        Uint8 unk_02[10];
    } hall;
    struct {
        Angle heading;
        Uint8 unk_04[4];
        Uint16 segment;
        Uint16 lane;
    } follow;
    struct {
        Angle heading;
        Sint32 segment;
        Uint8 unk_08[4];
    } orbit;
    struct {
        Float timer;
        Angle heading;
        Sint32 phase;
    } finish;
};
struct race_camera {
    Uint8 mode;
    Uint8 phase;
    Uint8 previous;
    Uint8 unk_03;
    Uint16 flags;
    Uint8 unk_06[2];
    Angle angle;
    Sint32 heading;
    NJS_VECTOR target_speed;
    NJS_VECTOR speed;
    Uint8 unk_28[12];
    NJS_VECTOR push;
    union race_camera_state state;
};
void fun_0cb889fa(struct camera_view *view);
void race_camera_reset(struct race_camera *camera);
void race_camera_step(struct race_camera *camera, struct race_game *game);
int race_camera_get_mode(struct race_camera *camera);
void race_camera_release(struct race_camera *camera);
void fun_0cb88d14(struct race_camera *camera);
void fun_0cb88d2a(struct race_camera *camera);
void fun_0cb89620(NJS_POINT3 *pos);
void race_camera_set_heading(struct race_camera *camera, int heading);
int race_camera_to_world(NJS_POINT3 *out, NJS_POINT3 *point);
struct path;
struct race_path_span {
    Float start;
    Float end;
};
struct race_path {
    NJS_POINT3 target;
    struct race_path_span *spans;
    struct path **paths;
    int count;
};
struct race_path_position {
    struct path *path;
    Float along;
    Float distance;
};
enum { LOCATE_SKIP_FIRST, LOCATE_ALL };
void race_path_init(struct race_path *path, struct path **paths, int count,
                    Float distance);
void race_path_locate(struct race_path *path, NJS_POINT3 *point,
                      struct race_path_position *position, int mode);
Float race_path_distance(struct race_path *path, NJS_POINT3 *point);
int race_path_get_target(struct race_path *path, NJS_POINT3 *point);
struct path *race_path_course(struct race_path *path);
int race_path_at_target(struct race_path *path, NJS_POINT3 *point);
void race_path_free(struct race_path *path);
void race_path_set_target(struct race_path *path, Float distance);
enum drop_mode { DROP_WAIT, DROP_SHOWN, DROP_FLYING, DROP_FLYING_HIDDEN };
struct spray_drop {
    NJS_POINT3 pos;
    NJS_VECTOR speed;
    Uint8 frame;
    Sint8 frame_timer;
    Uint8 mode;
    Uint8 flags;
    Uint16 timer;
    Uint8 unk_1e[2];
};
typedef void (*spray_move)(struct spray_drop *drop, NJS_POINT3 *pos,
                           NJS_VECTOR *speed);
struct spray {
    struct spray_drop drops[5];
    NJS_TEXLIST *texlist;
    NJS_TEXANIM *texanim;
    Float scale;
    spray_move move;
    Uint16 frame_steps;
    Uint8 frames;
    Uint8 count;
};
struct spray_kind {
    NJS_TEXLIST *texlist;
    NJS_TEXANIM *texanim;
    Float scale;
    Uint8 frame_steps;
    Uint8 frames;
    Uint8 count;
};
void spray_init(struct spray *spray, struct spray_kind *kind,
                void (*init)(struct spray_drop *drop), spray_move move);
void spray_step(struct spray *spray, NJS_POINT3 *pos, NJS_VECTOR *speed);
void spray_draw(struct spray *spray);
void spray_set_move(struct spray *spray, spray_move move);
void spray_set_flags(struct spray *spray, int flags);
void spray_fall(struct spray_drop *drop, Float gravity, Float drag);
void spray_init_splash(struct spray *spray);
struct alife_chao;
struct racer;
struct race_path;
struct task;
struct task_work;
enum racer_command {
    COMMAND_NONE,
    COMMAND_WINDOW,
    COMMAND_BIRTH,
    COMMAND_WAIT,
    COMMAND_RACE,
    COMMAND_WALK,
    COMMAND_REST,
    COMMAND_HAPPY,
    COMMAND_SWING,
    COMMAND_PUSH,
    COMMAND_EAT,
    COMMAND_PLAY_RAPPA,
    COMMAND_PLAY_JYOURO,
    COMMAND_PLAY_SCOOP,
    COMMAND_RETURN,
    COMMAND_DANCE,
    COMMAND_COMMENDATION,
    COMMAND_DEBUG
};
enum racer_state {
    RACER_TO_ENTRY,
    RACER_IN_ENTRY,
    RACER_TO_WAIT,
    RACER_WAITING,
    RACER_TO_REST,
    RACER_RESTING,
    RACER_TO_WALK,
    RACER_WALKING,
    RACER_TO_RACE,
    RACER_RACING,
    RACER_TO_GOAL,
    RACER_AT_GOAL,
    RACER_TO_PODIUM,
    RACER_ON_PODIUM,
    RACER_TO_RESTART,
    RACER_RESTARTING,
    RACER_FINISHING
};
enum racer_gait {
    GAIT_FOOT,
    GAIT_FLY,
    GAIT_SWIM,
    GAIT_CLIMB,
    GAIT_WAIT,
    GAIT_STILL
};
enum racer_route {
    ROUTE_START,
    ROUTE_TARGET,
    ROUTE_ITEM
};
enum racer_effect { EFFECT_NONE, EFFECT_DANCE, EFFECT_BOOST };
struct racer_behavior {
    Uint8 priority;
    Uint8 state;
    Uint16 timer;
    void (*step)(struct racer *racer);
};
enum racer_reaction_status {
    REACTION_PENDING,
    REACTION_TAKEN,
    REACTION_DONE
};
struct racer_reaction {
    struct task *source;
    Sint8 kind;
    Sint8 mode;
    Uint8 status;
    Uint8 unk_07;
};
struct racer {
    struct spray spray;
    struct racer_behavior behavior;
    struct racer_reaction reaction;
    Uint8 lane;
    Uint8 segment;
    Uint16 flags;
    Uint8 place;
    Uint8 state;
    Uint8 command;
    Uint8 route;
    Float rise;
    Float distance;
    Uint8 path_index;
    Uint8 effect;
    Uint16 effect_timer;
    Angle phase;
    Uint8 gait;
    Uint8 run_motion;
    Uint8 overhang;
    Uint8 voice;
    Uint8 in_zone;
    Uint8 unk_e1;
    Uint16 gain_timer;
    Float sound_distance;
    Sint8 sleep_gain;
    Sint8 unk_64_gain;
    Sint8 unk_65_gain;
    Uint8 unk_eb;
    struct alife_chao *chao;
    struct task_work *work;
};
struct racer_vars {
    Uint8 unk_00[8];
    struct racer *racer;
};
struct racer *racer_init(struct racer *racer, int lane);
void racer_attach(struct racer *racer, struct task_work *work,
                  struct alife_chao *chao);
void racer_detach(struct racer *racer);
void racer_destroy_chao(struct racer *racer);
int racer_has_chao(struct racer *racer);
struct alife_chao *racer_chao(struct racer *racer);
struct task_work *racer_work(struct racer *racer);
void racer_step(struct racer *racer, struct race_path *path, int kind);
void racer_entry_step(struct racer *racer);
void racer_spray(struct racer *racer, NJS_POINT3 *pos, NJS_VECTOR *speed);
void racer_draw_spray(struct racer *racer);
int racer_is_active(struct racer *racer);
int racer_at_goal(struct racer *racer);
int racer_at_podium(struct racer *racer);
int racer_take_command(struct racer *racer, int command);
int racer_is_followed(struct racer *racer);
void racer_clear_effect(struct racer *racer);
void racer_print_motion(struct racer *racer, int x, int y);
void racer_print_record(struct racer *racer, int x, int y);
int racer_place(struct racer *racer);
void racer_face_target(struct racer *racer, NJS_POINT3 *target);
void racer_hold_path(struct racer *racer);
int racer_path_index(struct racer *racer);
int racer_set_behavior(struct racer_behavior *behavior,
                       void (*step)(struct racer *racer), int priority);
void racer_override_behavior(struct racer_behavior *behavior,
                             void (*step)(struct racer *racer));
void racer_clear_behavior(struct racer_behavior *behavior);
enum racer_progress { PROGRESS_GOING, PROGRESS_DONE, PROGRESS_TIMED_OUT };
int racer_go_to(struct racer *racer, NJS_POINT3 *target, Float radius,
                int timeout);
int racer_tell(struct racer *racer, Sint8 mode, struct task *source,
               Sint8 kind);
void racer_cancel_item(struct racer *racer);
int racer_item_behavior(struct racer *racer);
struct race_standings {
    Uint8 lanes[8];
    Uint8 unk_08[8];
    Float scales[8];
    Angle spin;
    Float marker_y;
    Float marker_speed;
    Uint8 marker_state;
    Uint8 marker_lane;
    Uint16 timer;
};
void standings_init(struct race_standings *standings);
void standings_update(struct race_standings *standings, struct racer *racers,
                      int lane);
void standings_draw(struct race_standings *standings, struct racer *racers,
                    int lane);
void standings_draw_marker(struct race_standings *standings, int marker_lane,
                           NJS_POINT3 *pos);
int standings_lane(struct race_standings *standings, int rank);
int standings_index_of(const Uint8 *entries, int key);
struct race_places;
struct task;
enum race_state {
    STATE_ENTRANCE_INIT,
    STATE_MEDAL_GET,
    STATE_VMS_ERROR_CHECK,
    STATE_ENTRANCE_RE_INIT,
    STATE_ENTRANCE_INIT2,
    STATE_ENTRANCE,
    STATE_HINT_BOX,
    STATE_HINT_BOX_WAIT,
    STATE_RACE_WINDOW_INI,
    STATE_RACE_WINDOW,
    STATE_CUPS_WINDOW_INI,
    STATE_CUPS_WINDOW,
    STATE_GARDEN_WINDOW_INI,
    STATE_GARDEN_WINDOW,
    STATE_CHAO_WINDOW_INI,
    STATE_CHAO_WINDOW,
    STATE_CHAO_WINDOW_SLIDE,
    STATE_CHAO_DEMO_0,
    STATE_CHAO_DEMO_1,
    STATE_CHAO_DEMO_2,
    STATE_CHAO_DEMO_3,
    STATE_INIT,
    STATE_RE_INIT,
    STATE_WAIT,
    STATE_RACE,
    STATE_RACEEND,
    STATE_COMMENDATION_INI,
    STATE_COMMENDATION_0,
    STATE_COMMENDATION_1,
    STATE_COMMENDATION_2
};
struct race_entry {
    Uint8 kind;
    Uint8 index;
};
struct race_clock {
    struct race_time time;
    const struct race_time *best;
};
enum { RACE_RECORDED, RACE_MATCHED, RACE_GROUP };
struct race_records {
    Uint8 mark[8];
    Uint32 flags;
    Uint8 names[5][3][8];
    struct race_time times[5][3];
};
struct race_game {
    struct chao chao[8];
    struct racer racers[8];
    struct race_camera camera;
    struct race_places *places;
    struct race_records *records;
    struct race_entry entries[8];
    struct race_standings standings;
    struct race_path path;
    struct race_clock clock;
    struct race_cards cards;
    struct race_cheer cheer;
    Sint8 lane;
    Sint8 saved_lane;
    Uint8 state;
    Sint8 mode;
    Sint8 kind;
    Sint8 saved_choice;
    Sint8 character;
    Sint8 result_lane;
    Float average_distance;
    void (*guide)(struct race_game *game);
    Uint16 flags;
    Uint16 timer;
    Uint16 steps;
    Uint8 unk_18c6[3];
    Sint8 entry_count;
    Uint16 camera_timer;
    Uint8 card_drives;
    struct task *emblem_display;
};
extern struct race_game *race_game_current;
struct race_game *race_game_create(void);
Bool race_game_step(struct race_game *game);
void race_game_free(struct race_game *game);
int race_lane_of_task(struct task *chao_task);
void race_set_camera_mode(struct race_game *game, int mode);
int race_get_racer_pos(NJS_POINT3 *pos, int lane);
void race_print_state(struct race_game *game, int x, int y);
void fun_0cb8c942(struct race_game *game);
void fun_0cb8c956(struct race_game *game);
void fun_0cb8c9e0(struct race_game *game);
void race_guide_racers(struct race_game *game);
void race_request_voice(int group, int later);
void race_print_bits8(void *value, int x, int y);
void race_print_bits16(void *value, int x, int y);
void race_print_bits32(void *value, int x, int y);
int race_get_kind(int *kind);
int race_get_followed_lane(int *lane);
int fun_0cb8b510(int *timer, int which);
int fun_0cb8b566(void);
int race_get_entry_kind(int *kind, int lane);
int race_open_race_window(void);
int race_open_cups_window(void);
int race_open_garden_window(void);
int race_open_chao_window(void);
int fun_0cb8b7ea(void);
struct racer *race_racer_at_place(int place);
int fun_0cb8b860(int place, int what);
int race_cracker_kind(void);
struct race_digit {
    Float x;
    Float y;
    Float sx;
    Float sy;
    NJS_ARGB color;
};
void race_draw_digit(struct race_digit *digit, Int value, int set);
void race_clock_clear(struct race_clock *clock);
void race_clock_set_best(struct race_clock *clock, struct race_records *records,
                         int kind);
void race_clock_step(struct race_clock *clock);
void race_clock_draw(struct race_clock *clock);
void race_records_reset_unmarked(struct race_records *records);
void race_records_enter(struct race_records *records, struct race_time *time,
                        struct chao *chao, int kind);
void race_records_draw(struct race_records *records, int kind);
void race_time_copy(struct race_time *dst, const struct race_time *src);
void race_time_copy_to(const struct race_time *src, struct race_time *dst);
int race_time_compare(const struct race_time *left,
                      const struct race_time *right);
int race_time_swap(struct race_time *first, struct race_time *second);
enum race_chao_mode {
    MODE_WAIT = 0,
    MODE_FLOAT = 1,
    MODE_RUN = 2,
    MODE_WALK = 3,
    MODE_KOKE = 4,
    MODE_PAUSE_SLEEP = 5,
    MODE_PAUSE_AGRES = 6,
    MODE_PAUSE_MILD = 7,
    MODE_FLY = 8,
    MODE_SWIM = 9,
    MODE_CLIMB = 10,
    MODE_PUSH = 11,
    MODE_GOAL = 12,
    MODE_PLAY_RAPPA = 13,
    MODE_PLAY_JYOURO = 14,
    MODE_PLAY_SCOOP = 15,
    MODE_SWING = 16,
    MODE_EAT = 17,
    MODE_REST = 18,
    MODE_DROWN = 19,
    MODE_DANCE = 20,
    MODE_FINISH_4 = 21,
    MODE_FINISH_6 = 22
};
struct alife_chao *race_chao_init(struct task *task);
void race_chao_step(struct task *task);
void race_chao_destroy(struct task *task);
void race_chao_draw(struct task *task);
void race_chao_reset(struct task *task);
void race_chao_face_target(struct task_work *work, struct alife_chao *chao);
int race_chao_angle_to_target(struct task *task, Angle *angle);
void FUN_0cb814a4(struct task_work *work, struct alife_chao *chao);
void AL_FaceEyeLidControl(struct task_work *work, struct alife_chao *chao);
void FUN_0cb81642(struct task_work *work, struct alife_chao *chao);
int race_chao_node_pos(NJS_POINT3 *pos, struct task_work *work,
                       struct alife_chao *chao, int node);
void race_chao_stop(struct task_work *work, struct alife_chao *chao);
void fun_0cb83ec0(struct task_work *work, struct alife_chao *chao);
void race_chao_dance_moves(struct task_work *work, struct alife_chao *chao);
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
void late_DrawObject(NJS_OBJECT *object);
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
extern NJS_OBJECT object_shadow[];
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
void FUN_0cb81460(struct task_work *work, struct alife_chao *chao,
                                Float scale, NJS_COLOR *color);
void FUN_0cb81540(struct task_work *work,
                                  struct alife_chao *chao);
void race_chao_face_target(struct task_work *work, struct alife_chao *chao)
{
    work->ang.y = ((Angle)(njArcTan2((chao)->target.x - (work)->pos.x, (chao)->target.z - (work)->pos.z) * (65536.0 / (2 * 3.141592))) - 0x4000);
}
int race_chao_angle_to_target(struct task *task, Angle *angle)
{
    struct task_work *work;
    struct alife_chao *chao;
    Angle heading;
    Angle turn;
    if (!task) {
        return 0;
    }
    work = task->work;
    chao = (struct alife_chao *)task->motion;
    heading = ((Angle)(njArcTan2((chao)->target.x - (work)->pos.x, (chao)->target.z - (work)->pos.z) * (65536.0 / (2 * 3.141592))) - 0x4000);
    turn = work->ang.y - heading;
    *angle = turn & 0x8000 ? turn | 0xffff0000 : (Uint16)turn;
    return 1;
}
void FUN_0cb81460(struct task_work *work, struct alife_chao *chao,
                                Float scale, NJS_COLOR *color)
{
    NJS_POINT3 pos;
    (&pos)->x = work->pos.x;
    (&pos)->y = work->pos.y;
    (&pos)->z = work->pos.z;
    pos.y += 6.5F;
    chao_name_draw_at(chao->record, &pos, scale, color);
}
void FUN_0cb814a4(struct task_work *work, struct alife_chao *chao)
{
    struct racer *racer = ((struct racer_vars *)&(work)->vars)->racer;
    racer->gait = GAIT_FOOT;
    racer->voice = 0;
}
void AL_FaceEyeLidControl(struct task_work *work, struct alife_chao *chao)
{
    struct sides_query *query = &chao->terrain.query;
    if ((work->flags & 0x8000) && query->sides[SIDE_BELOW].found) {
        work->ang.x =
            AdjustAngle(work->ang.x, query->sides[SIDE_BELOW].ang_x, 364);
        work->ang.z =
            AdjustAngle(work->ang.z, query->sides[SIDE_BELOW].ang_z, 364);
    } else {
        work->ang.x = AdjustAngle(work->ang.x, 0, 364);
        work->ang.z = AdjustAngle(work->ang.z, 0, 182);
    }
}
void FUN_0cb81540(struct task_work *work,
                                  struct alife_chao *chao)
{
    struct sides_query *query = &chao->terrain.query;
    Float rise;
    Float alpha;
    Float scale;
    Float fade;
    Float shrink;
    if (!query->sides[SIDE_BELOW].found) {
        return;
    }
    rise = (work->pos.y - query->sides[SIDE_BELOW].level) * 0.07F;
    if (rise >= 1.0F) {
        rise = 1.0F;
    } else if (rise <= 0.0F) {
        rise = 0.0F;
    }
    if (work->mode == MODE_SWIM ||
        (chao->terrain.flags & 0x800)) {
        alpha = -0.8F;
    } else {
        fade = -1.0F - 1.0F;
        alpha = 1.0F + (fade * rise);
    }
    shrink = 0.2F - 0.5F;
    scale = 0.5F + (shrink * rise);
    njPushMatrix(((void *)0));
    njTranslate(((void *)0), work->pos.x, query->sides[SIDE_BELOW].level + 0.1F,
                work->pos.z);
    njRotateXYZ(((void *)0), query->sides[SIDE_BELOW].ang_x, 0,
                query->sides[SIDE_BELOW].ang_z);
    SetRegularTexture();
    njScale(((void *)0), scale, scale, scale);
    SetMaterial(alpha, -1.0F, -1.0F, -1.0F);
    late_DrawObject(object_shadow);
    SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    njPopMatrix(1);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_0cb81642(struct task_work *work, struct alife_chao *chao)
{
    struct racer *racer = ((struct racer_vars *)&(work)->vars)->racer;
    NJS_COLOR color;
    int kind;
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    if (racer->flags & 0x1000) {
        alife_chao_show(work, chao);
        FUN_0cb81540(work, chao);
    }
    if (racer->flags & 0x2000) {
        color.argb.a = 255;
        color.argb.r = 0;
        color.argb.g = 0;
        if (race_get_entry_kind(&kind, racer->lane)) {
            if (kind == 4) {
                color.argb.b = 250;
            } else {
                color.argb.b = 0;
            }
        } else {
            color.argb.b = 0;
        }
        FUN_0cb81460(work, chao, 0.85F, &color);
        racer->flags &= ~0x2000;
    }
}
#else
void FUN_0cb81642(struct task_work *work, struct alife_chao *chao)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
}
#endif
