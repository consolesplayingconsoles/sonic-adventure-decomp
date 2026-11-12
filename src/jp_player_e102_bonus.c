/* @unit 8C0D4A40-8C0D53E0 +r04 +egflags +pool32 +poolafter=FUN_8c0d4d26 +poolbra=tally_step:j1,FUN_8c0d4d80:7,FUN_8c0d4fec:3,FUN_8c0d514a:5,FUN_8c0d514a:15 */
/* Ported from the Japanese release's src/player/e102_bonus.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
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
struct pad_stick {
    Angle ang;
    Float stroke;
};
extern Uint32 pad_action_buttons;
extern Uint32 pad_jump_buttons;
extern Uint32 pad_choose_buttons;
extern Uint32 pad_cancel_buttons;
extern Uint32 pad_grab_buttons;
extern Uint32 pad_camera_buttons;
extern Uint32 pad_debug_buttons;
extern PDS_PERIPHERAL pad_records[8];
extern PDS_PERIPHERAL *per_info[4];
extern Uint8 dat_8c75d910[20];
extern struct pad_stick pad_sticks[8];
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
void pad_disable_player(Uint8 player);
Bool pad_player_is_enabled(Uint8 player);
Bool pad_quit_pressed(int unused);
void pad_scan(void);
struct task;
struct task_work;
struct lockon_strip {
    NJS_POINT3 *points;
    NJS_COLOR *colors;
    Sint16 *indices;
    Sint16 count;
    NJS_POINT3COL lines;
};
enum e102_mode {
    E102_INIT,
    E102_STAND,
    E102_WALK,
    E102_PATH,
    E102_JUMP,
    E102_SPRING,
    E102_LAUNCH,
    E102_FALL,
    E102_STOP,
    E102_PUSH,
    E102_HURT,
    E102_BACK,
    E102_CRASH,
    E102_SLIDE,
    E102_POSE,
    E102_LIFT,
    E102_PUT_DOWN,
    E102_HOLD_STAND,
    E102_GRIP,
    E102_HOLD_WALK,
    E102_THROW,
    E102_HOLD_STOP,
    E102_HOLD_FALL,
    E102_HOLD_JUMP,
    E102_HOLD_SPRING,
    E102_HOLD_LAUNCH,
    E102_PULL,
    E102_AIR_THROW,
    E102_SHAKE,
    E102_PRE_JUMP,
    E102_HOLD_PRE_JUMP,
    E102_SKATE,
    E102_HOLD_SKATE,
    E102_WATER_SKATE,
    E102_HOLD_WATER_SKATE,
    E102_WATER_JUMP,
    E102_HOLD_WATER_JUMP,
    E102_SKATE_JUMP,
    E102_HOLD_SKATE_JUMP,
    E102_SKATE_STOP,
    E102_HOLD_SKATE_STOP,
    E102_LEAP_START,
    E102_LEAP,
    E102_LEAP_FALL,
    E102_LEAP_HOVER,
    E102_SKATE_START,
    E102_SKATE_BRAKE,
    E102_LEDGE,
    E102_LEDGE_GO,
    E102_TIME_UP,
    E102_UNK_50,
    E102_DOWN,
    E102_CLEAR,
    E102_MODULE_POSE,
    E102_HOLD_SHAKE,
    E102_EVENT,
    E102_EDIT
};
enum e102_aim_mode {
    E102_AIM_INIT,
    E102_AIM_READY,
    E102_AIM_START,
    E102_AIM_LOCKING,
    E102_AIM_CANCEL,
    E102_AIM_LET_GO,
    E102_AIM_CANCELLED
};
enum e102_shot_phase {
    E102_SHOT_START,
    E102_SHOT_TURN,
    E102_SHOT_MARK,
    E102_SHOT_NEXT,
    E102_SHOT_AIM,
    E102_SHOT_KICK
};
struct e102 {
    Sint8 aim_mode;
    Sint8 shot_phase;
    Sint8 unshot;
    Uint8 unk_03;
    Sint8 lockon_count;
    Sint8 shot_count;
    Sint8 shot_way;
    Uint8 unk_07;
    Sint16 steps;
    Sint16 lockon_number;
    Sint16 unk_0c;
    Uint8 unk_0e[2];
    Sint16 aim_time;
    Sint16 aim_draws;
    Uint8 unk_14[2];
    Sint16 flags;
    Float booster_lift;
    Angle booster_phase;
    Angle booster_ang_x;
    Uint8 unk_24[4];
    Angle booster_ang_z;
    Angle bob;
    struct task *target;
    NJS_POINT3 muzzle;
    NJS_VECTOR aim;
    Float beam_length;
    Float beam_reach;
    NJS_POINT3 shot_pos;
    NJS_VECTOR shot_dir;
    struct task *search;
    Float shot_frame;
    Uint8 unk_74[12];
    NJS_ACTION *shot_action;
    Float cannon_frame;
    Angle glow;
    Angle cannon_ang;
    Float kick;
    NJS_POINT3 points[2];
    Float fall_speed;
    struct lockon_strip inner;
    struct lockon_strip outer;
    Uint8 unk_f0[4];
    struct task *lockons[32];
    struct task *shots[32];
    struct pad_stick sticks[8];
    Float ground;
    Float above;
    Uint32 ground_flags;
    Float walked;
};
extern Sint8 e102_in_play;
extern Sint8 e102_hovering;
extern Sint8 e102_time_runs;
extern NJS_POINT3COL e102_beam;
extern NJS_POINT3 e102_beam_points[];
extern NJS_COLOR e102_beam_colors[];
extern struct e102 *e102_current;
void e102_step(struct task *task);
Bool e102_can_aim(struct task_work *work);
void e102_look_step(struct task *task);
struct lockon_strip;
struct task;
struct bonus_work {
    Sint8 mode;
    Uint8 unk_01[3];
    Sint16 flags;
    Uint8 unk_06[2];
    Sint32 unk_08;
    Sint8 volley[2];
    Uint8 unk_0e[18];
    NJS_POINT3 pos;
    Float scale;
    Float shrink;
};
extern NJS_TEXLIST e102time_texlist;
extern NJS_SPRITE e102time_sprite;
void e102_draw_two_digits(int number);
void e102_time_bonus_create(struct task *parent);
void e102_bonus_hit(Sint8 unused);
void e102_bonus_count(struct task *bonus);
void FUN_8c0d514a(struct task *task);
void e102_draw_strip(struct lockon_strip *strip, Uint32 attr);
void e102_make_strips(struct lockon_strip *inner, struct lockon_strip *outer);
void e102_free_strips(struct lockon_strip *inner, struct lockon_strip *outer);
void e102_free_strip(struct lockon_strip *strip);
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
void DestroyTask(struct task *task);
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
struct task *CreateChildTask(Uint16 flags, void (*step)(struct task *task),
                               struct task *parent);
struct task *task_create_children(struct task_spec *spec, struct task *parent);
void task_destroy_children(struct task *task);
void task_step_children(struct task *task);
void heap_init(void);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void heap_stats(int *total, int *largest);
enum time_bonus_mode {
    TIME_BONUS_INIT,
    TIME_BONUS_IDLE,
    TIME_BONUS_RESTART,
    TIME_BONUS_COUNT,
    TIME_BONUS_HOLD,
    TIME_BONUS_LEAVE
};
enum bonus_mode {
    BONUS_INIT,
    BONUS_HIT,
    BONUS_WAIT,
    BONUS_PULSING,
    BONUS_END,
    BONUS_PAUSE,
    BONUS_LEAVE
};
struct tally_vars {
    Uint8 unk_00[4];
    Sint16 seconds;
    Sint16 delay;
};
struct time_bonus_extra {
    Sint8 ready;
    Sint8 pending;
    Sint16 count;
    Sint16 pulse;
    Sint16 timer;
};
struct bonus_extra {
    Sint32 pulse;
    Sint32 timer;
    Sint32 waited;
    Sint32 worth;
    Sint32 total;
};
void tally_step(struct task *task);
void FUN_8c0d4d80(struct task *task);
extern NJS_TEXNAME e102time_textures[];
extern NJS_TEXLIST e102time_texlist;
extern NJS_TEXANIM e102time_texanims[14];
extern NJS_SPRITE e102time_sprite;
extern struct task *time_bonus_task;
extern struct task *volley_bonus;
extern NJS_POINT3 cube_corners[8];
extern NJS_COLOR cube_red[8];
extern NJS_COLOR cube_yellow[8];
extern Sint16 cube_edges[12 * 2];
extern struct lockon_strip inner_cube;
extern struct lockon_strip outer_cube;
void e102_draw_two_digits(int number)
{
    late_DrawSprite2D(&e102time_sprite, number / 10, -2.0F,
                   0x20 | 0x02);
    e102time_sprite.p.x += 24.0F;
    late_DrawSprite2D(&e102time_sprite, number % 10, -2.0F,
                   0x20 | 0x02);
    e102time_sprite.p.x += 24.0F;
}
void e102_time_bonus_create(struct task *parent)
{
    time_bonus_task = CreateChildTask(0x2, FUN_8c0d4d80, parent);
}
void draw_number(int number, NJS_POINT3 *pos, Float scale)
{
    Float width = scale * 24.0F;
    e102time_sprite.p.x = pos->x;
    if (number > 99) {
        e102time_sprite.p.x += width;
    } else if (number > 9) {
        e102time_sprite.p.x += 0.5F * width;
    }
    e102time_sprite.p.y = pos->y - (width * 0.3F);
    e102time_sprite.sy = scale;
    e102time_sprite.sx = scale;
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    SetMaterial(1.0F, 1.0F, 1.0F, 0.0F);
    while (number > 0) {
        late_DrawSprite2D(&e102time_sprite, number % 10, -2.0F,
                       0x20 | 0x02);
        e102time_sprite.p.x -= width;
        number /= 10;
    }
    e102time_sprite.sy = 1.0F;
    e102time_sprite.sx = 1.0F;
}
void tally_step(struct task *task)
{
    struct task_work *work = task->work;
    if (((struct tally_vars *)&(work)->vars)->delay > 0) {
        ((struct tally_vars *)&(work)->vars)->delay--;
    } else {
        ((struct tally_vars *)&(work)->vars)->delay = 3;
        if (((struct tally_vars *)&(work)->vars)->seconds > 0) {
            ((struct tally_vars *)&(work)->vars)->seconds--;
            time_add_seconds(1);
            dsPlay_oneshot(4, 0, 0, 0);
        }
        if (!((struct tally_vars *)&(work)->vars)->seconds) {
            e102_time_runs = (1);
            DestroyTask(task);
        }
    }
}
void FUN_8c0d4c48(struct task *task)
{
    struct bonus_work *work = ((struct bonus_work *)(task)->work);
    struct time_bonus_extra *extra = task->extra;
    Float scale;
    Float size;
    if (loop_count != 0) {
        return;
    }
    if (!(work->flags & 0x100)) {
        return;
    }
    if (extra->count >= 25) {
        scale = 1.75F;
    } else if (extra->count >= 15) {
        scale = 1.5F;
    } else if (extra->count >= 6) {
        scale = 1.25F;
    } else {
        scale = 1.0F;
    }
    scale = scale + (scale * njSin(extra->pulse * 0x8000 / 15) * 0.5F);
    scale *= work->scale;
    size = scale;
    if (extra->count >= 100) {
        size *= 1.15F;
    }
    e102time_sprite.sy = size;
    e102time_sprite.sx = size;
    e102time_sprite.p.x = work->pos.x;
    e102time_sprite.p.y = work->pos.y;
    SetMaterial(1.0F, 1.0F, 1.0F, 1.0F);
    late_DrawSprite2D(&e102time_sprite, 11, -3.0F,
                   0x20 | 0x02);
    draw_number(extra->count, &work->pos, scale);
}
void FUN_8c0d4d26(struct task *task)
{
    time_bonus_task = ((void *)0);
}
void FUN_8c0d4d80(struct task *task)
{
    struct bonus_work *work = ((struct bonus_work *)(task)->work);
    struct time_bonus_extra *extra = task->extra;
    struct task *tally;
    work->flags &= ~0x100;
    switch (work->mode) {
    case TIME_BONUS_INIT:
        extra = task->extra = CAlloc(1, sizeof(struct time_bonus_extra));
        work->unk_08 = 0;
        task->draw = FUN_8c0d4c48;
        task->destructor = FUN_8c0d4d26;
        work->scale = 1.15F;
        work->mode = TIME_BONUS_IDLE;
    case TIME_BONUS_IDLE:
        if (extra->ready > 0) {
            e102_time_runs = (0);
            extra->count = 0;
            work->mode = TIME_BONUS_RESTART;
            work->pos.x = 540.0F;
            work->pos.y = 120.0F;
        }
        break;
    case TIME_BONUS_RESTART:
        extra->pulse = 15;
        work->scale = 1.15F;
        extra->timer = 0;
        work->mode = TIME_BONUS_COUNT;
    case TIME_BONUS_COUNT:
        if (extra->pending > 0) {
            extra->timer--;
            if (extra->timer <= 0) {
                extra->timer = 2;
                extra->pending--;
                extra->count++;
            }
        }
        extra->pulse--;
        if (extra->pulse <= 0) {
            extra->ready = 0;
            extra->timer = (4 * 60);
            work->mode = TIME_BONUS_HOLD;
        }
        break;
    case TIME_BONUS_HOLD:
        if (extra->ready > 0) {
            work->mode = TIME_BONUS_RESTART;
            break;
        }
        extra->timer--;
        if (extra->timer <= 0) {
            dsPlay_oneshot(22, 0, 0, 0);
            work->shrink = -(work->scale * (1.0F / 30.0F));
            work->mode = TIME_BONUS_LEAVE;
        }
        break;
    case TIME_BONUS_LEAVE:
        work->pos.x += (-14.0F);
        work->pos.y += (-3.0F);
        work->scale += work->shrink;
        if (work->scale <= 0.0F || extra->ready > 0) {
            tally = CreateElementalTask(0x2, 1, tally_step);
            ((struct tally_vars *)&(tally->work)->vars)->seconds = extra->count;
            work->mode = TIME_BONUS_IDLE;
        }
        break;
    }
    if (work->mode > TIME_BONUS_IDLE && hud_hidden >= 0) {
        work->flags |= 0x100;
        FUN_8c0d4c48(task);
    }
}
void e102_bonus_hit(Sint8 unused)
{
    struct task *task;
    if (volley_bonus == ((void *)0)) {
        task = CreateElementalTask(0x2, 2, FUN_8c0d514a);
        if (task == ((void *)0)) {
            time_add_seconds(1);
            dsPlay_oneshot(4, 0, 0, 0);
            return;
        }
    } else {
        task = volley_bonus;
    }
    ((struct bonus_work *)(task)->work)->volley[1]++;
}
void e102_bonus_count(struct task *bonus)
{
    if (bonus == ((void *)0)) {
        if (volley_bonus == ((void *)0)) {
            bonus = CreateElementalTask(0x2, 2, FUN_8c0d514a);
            if (bonus == ((void *)0)) {
                time_add_seconds(1);
                dsPlay_oneshot(4, 0, 0, 0);
                return;
            }
        } else {
            bonus = volley_bonus;
        }
        ((struct bonus_work *)(bonus)->work)->volley[0]++;
    }
    ((struct bonus_work *)(bonus)->work)->volley[1]++;
}
void FUN_8c0d4fec(struct task *task)
{
    struct bonus_work *work = ((struct bonus_work *)(task)->work);
    struct bonus_extra *extra = task->extra;
    Float scale;
    Float size;
    if (loop_count != 0) {
        return;
    }
    if (!(work->flags & 0x100)) {
        return;
    }
    if (extra->total >= 25) {
        scale = 1.75F;
    } else if (extra->total >= 15) {
        scale = 1.5F;
    } else if (extra->total >= 6) {
        scale = 1.25F;
    } else {
        scale = 1.0F;
    }
    scale = scale + (scale * njSin(extra->pulse * 0x8000 / 15) * 0.5F);
    scale *= work->scale;
    size = scale;
    if (extra->total >= 100) {
        size *= 1.15F;
    }
    e102time_sprite.sy = size;
    e102time_sprite.sx = size;
    e102time_sprite.p.x = work->pos.x;
    e102time_sprite.p.y = work->pos.y;
    SetMaterial(1.0F, 1.0F, 1.0F, 1.0F);
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    late_DrawSprite2D(&e102time_sprite, 11, -3.0F,
                   0x20 | 0x02);
    draw_number(extra->total, &work->pos, scale);
}
void FUN_8c0d513c(struct task *task)
{
    volley_bonus = ((void *)0);
    e102_time_runs = (1);
}
void FUN_8c0d514a(struct task *task)
{
    struct bonus_work *work = ((struct bonus_work *)(task)->work);
    struct bonus_extra *extra = task->extra;
    struct task *tally;
    int left;
    e102_time_runs = (0);
    switch (work->mode) {
    case BONUS_INIT:
        volley_bonus = task;
        task->extra = CAlloc(1, sizeof(struct bonus_extra));
        if (task->extra == ((void *)0)) {
            DestroyTask(task);
            return;
        }
        extra = task->extra;
        task->draw = FUN_8c0d4fec;
        task->destructor = FUN_8c0d513c;
        work->pos.x = 540.0F;
        work->pos.y = 120.0F;
        extra->waited = 0;
        work->mode = BONUS_WAIT;
    case BONUS_WAIT:
        if (work->volley[0] > 0 && work->volley[1] > 0) {
            work->mode = BONUS_HIT;
        }
        extra->waited++;
        if (extra->waited >= (5 * 60)) {
            work->mode = BONUS_END;
        }
        break;
    case BONUS_HIT:
        work->flags |= 0x100;
        work->volley[1]--;
        work->volley[0]--;
        extra->waited = 0;
        extra->worth =
            extra->worth + 1 < 5 ? extra->worth + 1 : 5;
        extra->total += extra->worth;
        extra->pulse = 15;
        extra->timer = 0;
        work->scale = 1.15F;
        work->mode = BONUS_PULSING;
    case BONUS_PULSING:
        extra->pulse--;
        if (extra->pulse > 0) {
            break;
        }
        if (work->volley[0] > 0) {
            work->mode = BONUS_WAIT;
        } else {
            work->mode = BONUS_END;
        }
        break;
    case BONUS_END:
        extra->timer = 60;
        work->shrink = -(work->scale * (1.0F / 30.0F));
        work->mode = BONUS_PAUSE;
    case BONUS_PAUSE:
        extra->timer--;
        if (extra->timer > 0) {
            break;
        }
        work->mode = BONUS_LEAVE;
        break;
    case BONUS_LEAVE:
        work->pos.x += (-14.0F);
        work->pos.y += (-3.0F);
        work->scale += work->shrink;
        if (work->scale > 0.0F) {
            break;
        }
        left = work->volley[0] < 6
                   ? work->volley[0]
                   : 6;
        while (left > 0) {
            left--;
            extra->worth =
                extra->worth + 1 < 5 ? extra->worth + 1 : 5;
            extra->total += extra->worth;
        }
        tally = CreateElementalTask(0x2, 1, tally_step);
        ((struct tally_vars *)&(tally->work)->vars)->seconds = extra->total;
        DestroyTask(task);
        return;
    default:
        break;
    }
    if (hud_hidden >= 0) {
        FUN_8c0d4fec(task);
    }
}
