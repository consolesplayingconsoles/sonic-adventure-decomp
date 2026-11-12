/* @unit 8C0D3B40-8C0D4A40 +r04 +egflags +pool32 +poolafter=shot_destroy,shot_step,shot_trail_step +poolbra=FUN_8c0d431a:j1,shot_choose_way:4,FUN_8c0d460e:5,FUN_8c0d460e:18 +asmfunc=shot_step,FUN_8c0d40a0 */
/* Ported from the Japanese release's src/player/e102_shot.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
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
struct task_work;
void draw_action(NJS_ACTION *action, Float frame);
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
void late_DrawObject(NJS_OBJECT *object);
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
void event_load(int number);
void event_unload(void);
void event_start(void);
void event_skip(void);
Bool event_is_playing(int unused);
Bool EV_CheckCansel(void);
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
Bool CheckRangeOut(struct task *task);
Bool placement_try_leave_by(struct task *task, Float range);
Bool placement_try_leave_saving(struct task *task);
Bool placement_try_leave_saving_by(struct task *task, Float range);
void placement_set_used(struct task *task);
void placement_keep(struct task *task);
int placement_used(struct task *task);
void placement_hold(struct task *task);
int placement_held(struct task *task);
void FUN_8c091aca(struct task *task);
void placement_kill(struct task *task);
Uint16 placement_get_kind(struct task *task);
void placement_set_state(struct task *task, Sint8 state);
Sint8 placement_get_state(struct task *task);
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
struct e102;
struct player;
struct task;
struct task_work;
Bool e102_target_counts(struct task *task);
void e102_aim(struct task_work *work, struct player *record, struct e102 *e102);
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
struct e102;
struct player;
struct task;
struct task_work;
struct shot_work {
    Sint8 mode;
    Uint8 unk_01[3];
    Sint16 flags;
    Uint16 upgrades;
    struct task_work *player;
    Float pull;
    struct task *lockon;
    Sint32 steps;
    Uint8 unk_18[8];
    NJS_POINT3 pos;
    NJS_POINT3 scl;
};
void FUN_8c0d460e(struct task *task, struct player *record, struct e102 *e102);
void e102_release_shot(struct task *shot, NJS_VECTOR *speed);
void FUN_8c0d48f8(struct task *task, struct player *record,
                       struct e102 *e102);
void e102_smoke_create(NJS_POINT3 *pos, NJS_VECTOR *speed, Float scale);
void e102_smoke_init(void);
struct task;
void FUN_8c0d64fa(struct task *task);
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
int sound_play(int se, int id, int priority, int volume);
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
void SaveControl3D(void);
void LoadControl3D(void);
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
enum shot_way {
    SHOT_AHEAD,
    SHOT_BEHIND,
    SHOT_MINUS_Z,
    SHOT_PLUS_Z,
    SHOT_LOW,
    SHOT_HIGH,
    SHOT_WAYS
};
enum shot_mode { SHOT_START, SHOT_HOMING, SHOT_FREE };
enum fade_mode { FADE_START, FADE_OUT };
struct trail_work {
    Sint8 mode;
    Sint8 first;
    Uint8 unk_02[4];
    Uint16 upgrades;
    Float fade;
    Sint8 player;
    Uint8 unk_0d[11];
    Angle ang_y;
    Angle ang_z;
    NJS_POINT3 pos;
};
struct flash_work {
    Sint8 mode;
    Uint8 unk_01[5];
    Uint16 upgrades;
    Float size;
    Sint8 player;
    Uint8 unk_0d[19];
    NJS_POINT3 pos;
};
struct blast_work {
    Sint8 mode;
    Uint8 unk_01[7];
    Float frame;
    Uint8 unk_0c[12];
    Angle ang_y;
    Angle ang_z;
    NJS_POINT3 pos;
};
extern NJS_ACTION e102_shot_ahead_action;
extern NJS_ACTION e102_shot_behind_action;
extern NJS_ACTION e102_shot_minus_z_action;
extern NJS_ACTION e102_shot_plus_z_action;
extern NJS_ACTION e102_shot_low_action;
extern NJS_ACTION e102_shot_high_action;
extern NJS_OBJECT e102_trail_first;
extern NJS_OBJECT e102_trail;
extern NJS_OBJECT e102_blast;
extern NJS_MATERIAL e102_blast_materials[];
void shot_draw(struct task *task);
void shot_destroy(struct task *task);
void shot_step(struct task *task);
void FUN_8c0d40a0(struct task *task);
void shot_trail_step(struct task *task);
void shot_flash_draw(struct task *task);
void shot_flash_step(struct task *task);
void FUN_8c0d431a(struct task *task);
extern const NJS_VECTOR fire_smoke_speed;
extern NJS_TEXANIM shot_texanims[2];
extern NJS_TEXANIM shot_flash_texanims[2];
extern NJS_ACTION *shot_actions[SHOT_WAYS];
extern NJS_SPRITE shot_sprite;
extern NJS_SPRITE shot_flash_sprite;
extern NJS_ARGB shot_material;
extern struct collision_shape shot_shape;
extern Float shot_trail_material;
extern Float shot_trail_red;
extern Float shot_trail_green;
extern Float shot_trail_blue;
extern NJS_ARGB shot_flash_material;
extern Float shot_blast_material;
extern Float shot_blast_red;
extern Float shot_blast_green;
extern Float shot_blast_blue;
struct task *nearest_lockon(struct task_work *work, struct e102 *e102,
                                   Bool marked)
{
    struct task **list;
    Float best;
    int count;
    struct task *found;
    int i;
    count = 0;
    best = 999999.0F;
    list = e102->lockons;
    found = ((void *)0);
    for (i = e102->lockon_count; i > 0; i--) {
        struct task *lockon = *list++;
        struct lockon_extra *extra = lockon->extra;
        Float distance;
        if (extra->shot != ((void *)0)) {
            continue;
        }
        if (extra->target == ((void *)0)) {
            continue;
        }
        if (extra->target->work == ((void *)0)) {
            continue;
        }
        if (marked && !extra->marked) {
            continue;
        }
        count++;
        distance = CalcDistance(&work->pos, &extra->target->work->pos);
        if (best > distance) {
            best = distance;
            found = lockon;
        }
    }
    e102->unshot = count;
    return found;
}
void shot_draw(struct task *task)
{
    struct shot_work *shot = ((struct shot_work *)(task)->work);
    int laser;
    if (loop_count != 0) {
        return;
    }
    njSetConstantMaterial(&shot_material);
    njColorBlendingMode(0, 10);
    njColorBlendingMode(1, 10);
    njPushMatrix(((void *)0));
    laser = (shot->upgrades & 0x200) ? 1 : 0;
    njTranslateV(((void *)0), &shot->pos);
    njSetTexture(&e102beam_texlist);
    njDrawSprite3D(&shot_sprite, laser, 0x10 | 0x20);
    njPopMatrix(1);
}
void shot_destroy(struct task *task)
{
    struct shot_work *shot = ((struct shot_work *)(task)->work);
    struct task *lockon = shot->lockon;
    struct lockon_extra *extra;
    struct task *sphere;
    if (lockon != ((void *)0)) {
        extra = lockon->extra;
        extra->shot = ((void *)0);
    }
    if (shot->flags & 0x100) {
        sphere = CreateElementalTask(0x2, 2, FUN_8c0d64fa);
        if (sphere != ((void *)0)) {
            sphere->work->pos = shot->pos;
        }
    }
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void shot_step(struct task *task)
{
    struct shot_work *shot = ((struct shot_work *)(task)->work);
    struct task_motion *motion = task->motion;
    struct task *lockon = shot->lockon;
    struct lockon_extra *extra;
    struct task_work *player;
    struct task *made;
    struct trail_work *trail;
    NJS_VECTOR to;
    Float distance;
    Float scale;
    int se;
    shot->steps++;
    if (shot->steps > 600) {
        FreeTask(task);
        return;
    }
    switch (shot->mode) {
    case SHOT_START:
        if (lockon == ((void *)0)) {
            FreeTask(task);
            return;
        }
        shot->scl.x = 1.0F;
        motion->speed.x *= 5.0F;
        motion->speed.y *= 5.0F;
        motion->speed.z *= 5.0F;
        shot->pull = 0.0F;
        CCL_Init(task, &shot_shape, 1, 1, 1);
        extra = lockon->extra;
        player = extra->player;
        if (extra == ((void *)0)) {
            FreeTask(task);
            return;
        }
        if (player == ((void *)0)) {
            player = playertwp[0];
        }
        shot->player = player;
        shot->upgrades = extra->upgrades;
        se = (shot->upgrades & 0x200) ? 792 : 791;
        if (e102_in_play) {
            dsPlay_oneshot_v(se, 0, 0, 0, shot->pos.x, shot->pos.y, shot->pos.z);
        }
        task->draw = shot_draw;
        task->destructor = shot_destroy;
        to = lockon->work->pos;
        njSubVector(&to, &shot->pos);
        distance = njScalor(&to);
        scale = 5.0F / distance;
        if (distance < 100.0F) {
            if (distance >= 5.0F) {
                to.x *= scale;
                to.y *= scale;
                to.z *= scale;
            }
            motion->speed = to;
        } else {
            njUnitVector(&to);
            motion->speed.x = to.x * scale;
            motion->speed.y = to.y * scale;
            motion->speed.z = to.z * scale;
        }
        shot->mode = SHOT_HOMING;
        break;
    case SHOT_HOMING:
        if (lockon == ((void *)0)) {
            FreeTask(task);
            return;
        }
        to = lockon->work->pos;
        njSubVector(&to, &shot->pos);
        distance = njScalor(&to);
        if (distance >= 16.0F) {
            if (distance >= 100.0F) {
                scale = shot->pull / distance;
                to.x *= scale;
                to.y *= scale;
                to.z *= scale;
                njAddVector(&motion->speed, &to);
            } else {
                motion->speed = to;
            }
            njUnitVector(&motion->speed);
            motion->speed.x *= 5.0F;
            motion->speed.y *= 5.0F;
            motion->speed.z *= 5.0F;
            njAddVector(&shot->pos, &motion->speed);
        } else {
            shot->pos = lockon->work->pos;
        }
        e102_current->shots[e102_current->shot_count++] = task;
        break;
    case SHOT_FREE:
        if (CheckRangeOut(task)) {
            FreeTask(task);
            return;
        }
        njAddVector(&shot->pos, &motion->speed);
        break;
    }
    made = CreateElementalTask(0x2, 2, shot_trail_step);
    if (made != ((void *)0)) {
        trail = ((struct trail_work *)(made)->work);
        trail->pos = shot->pos;
        trail->ang_y =
            0x8000 - (Angle)(njArcTan2(motion->speed.z, motion->speed.x) *
                             (65536.0 / (2 * 3.141592)));
        trail->ang_z =
            -(Angle)(njArcTan2(motion->speed.y,
                            njSqrt((motion->speed.x * motion->speed.x) +
                                   (motion->speed.z * motion->speed.z))) *
                     (65536.0 / (2 * 3.141592)));
        trail->first = shot->pull == 0.0F;
        player = shot->player != ((void *)0) ? shot->player : playertwp[0];
        trail->player = ((struct player_vars *)&(player)->vars)->player;
        trail->upgrades = shot->upgrades;
    }
    shot->pull = shot->pull + 0.5F > 5.0F ? shot->pull + 0.5F : 5.0F;
    shot_draw(task);
    EntryColliList((struct task_work *)shot);
}
#else
void shot_step(struct task *task)
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
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c0d40a0(struct task *task)
{
    struct trail_work *trail = ((struct trail_work *)(task)->work);
    if (loop_count != 0) {
        return;
    }
    SaveControl3D();
    njControl3D(0x00000010);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &trail->pos);
    ((trail->ang_y) ? (njRotateY)(((void *)0), (trail->ang_y)) : (void)0);
    ((trail->ang_z) ? (njRotateZ)(((void *)0), (trail->ang_z)) : (void)0);
    if (trail->upgrades & 0x200) {
        njScale(((void *)0), 2.5F, 1.25F, 1.25F);
        shot_trail_red = trail->fade;
        shot_trail_green = trail->fade;
        shot_trail_blue = 1.0F;
    } else {
        njScale(((void *)0), 2.5F, 1.0F, 1.0F);
        shot_trail_red = trail->fade;
        shot_trail_green = trail->fade;
        shot_trail_blue = 0.0F;
    }
    njSetConstantMaterial((NJS_ARGB *)&shot_trail_material);
    if (trail->first) {
        njSetTexture(&e102beam_texlist);
        late_DrawObjectClip(&e102_trail_first);
    } else {
        late_DrawObjectClip(&e102_trail);
    }
    njPopMatrix(1);
    LoadControl3D();
}
#else
void FUN_8c0d40a0(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56; asm_stub[1] = 57; asm_stub[2] = 58; asm_stub[3] = 59;
}
#endif
void shot_trail_step(struct task *task)
{
    struct trail_work *trail = ((struct trail_work *)(task)->work);
    switch (trail->mode) {
    case FADE_START:
        trail->fade = 1.0F;
        task->draw = FUN_8c0d40a0;
        trail->mode = FADE_OUT;
    case FADE_OUT:
        trail->fade -= 0.1F;
        if (trail->fade <= 0.0F) {
            DestroyTask(task);
            return;
        }
        break;
    }
    FUN_8c0d40a0(task);
}
void shot_flash_draw(struct task *task)
{
    struct flash_work *flash = ((struct flash_work *)(task)->work);
    int laser;
    if (loop_count != 0) {
        return;
    }
    njColorBlendingMode(0, 10);
    njColorBlendingMode(1, 10);
    njSetConstantMaterial(&shot_flash_material);
    njSetTexture(&e102beam_texlist);
    njPushMatrix(((void *)0));
    laser = (flash->upgrades & 0x200) ? 1 : 0;
    njTranslateV(((void *)0), &flash->pos);
    shot_flash_sprite.sx = shot_flash_sprite.sy = flash->size;
    njDrawSprite3D(&shot_flash_sprite, laser,
                   0x10 | 0x20);
    njPopMatrix(1);
}
void shot_flash_step(struct task *task)
{
    struct flash_work *flash = ((struct flash_work *)(task)->work);
    switch (flash->mode) {
    case FADE_START:
        flash->size = 2.0F;
        flash->mode = FADE_OUT;
    case FADE_OUT:
        flash->size -= 0.5F;
        if (flash->size <= 0.0F) {
            DestroyTask(task);
            return;
        }
        break;
    }
    shot_flash_draw(task);
}
void FUN_8c0d431a(struct task *task)
{
    struct blast_work *blast = ((struct blast_work *)(task)->work);
    Float scale;
    Float color;
    switch (blast->mode) {
    case FADE_START:
        blast->frame = 0.0F;
        blast->mode = FADE_OUT;
    case FADE_OUT:
        blast->frame += 0.5F;
        if (blast->frame >= 8.0F) {
            DestroyTask(task);
            return;
        }
        break;
    }
    SaveControl3D();
    njControl3D((_nj_control_3d_flag_ & ~0x00000020) |
                0x00000010);
    njColorBlendingMode(0, 10);
    njColorBlendingMode(1, 10);
    scale = blast->frame * 0.125F;
    color = 1.5F - scale;
    shot_blast_red = color;
    shot_blast_green = color;
    shot_blast_blue = color;
    njSetConstantMaterial((NJS_ARGB *)&shot_blast_material);
    njSetTexture(&e102beam_texlist);
    njPushMatrix(((void *)0));
    scale *= 2.0F;
    njTranslateV(((void *)0), &blast->pos);
    ((blast->ang_y) ? (njRotateY)(((void *)0), (blast->ang_y)) : (void)0);
    ((blast->ang_z) ? (njRotateZ)(((void *)0), (blast->ang_z)) : (void)0);
    njScale(((void *)0), scale, scale, scale);
    e102_blast_materials[0].attr_texId = (Uint32)blast->frame;
    late_DrawObject(&e102_blast);
    njPopMatrix(1);
    LoadControl3D();
}
enum shot_way shot_choose_way(struct task_work *work,
                                     struct task_work *target)
{
    Float dx;
    Float dy;
    Float dz;
    Angle yaw;
    Angle pitch;
    enum shot_way way;
    Bool behind;
    if (work->mode == E102_SKATE || work->mode == E102_WATER_SKATE) {
        return SHOT_LOW;
    }
    dx = target->pos.x - work->pos.x;
    dy = target->pos.y - work->pos.y;
    dz = target->pos.z - work->pos.z;
    yaw = ((Angle)(njArcTan2(dz, dx) * (65536.0 / (2 * 3.141592))) - work->ang.y + 0x2000) &
          0xffff;
    pitch =
        -(Angle)(njArcTan2(dy, njSqrt((dx * dx) + (dz * dz))) * (65536.0 / (2 * 3.141592)));
    switch (yaw & 0xc000) {
    case 0x4000:
        way = SHOT_PLUS_Z;
        break;
    case 0x8000:
        way = SHOT_BEHIND;
        break;
    case 0xc000:
        way = SHOT_MINUS_Z;
        break;
    default:
        way = SHOT_AHEAD;
        break;
    }
    behind = yaw >= 0x6000 && yaw <= 0xe000;
    if (pitch < -0x2000) {
        way = behind ? SHOT_LOW : SHOT_HIGH;
    }
    if (pitch > 0x2000) {
        way = behind ? SHOT_HIGH : SHOT_LOW;
    }
    return way;
}
void FUN_8c0d460e(struct task *task, struct player *record, struct e102 *e102)
{
    struct task_work *work = task->work;
    struct task *lockon;
    struct task *bonus;
    struct task *shot;
    struct lockon_extra *extra;
    struct task **list;
    int count;
    int i;
    switch (e102->shot_phase) {
    case E102_SHOT_START:
        e102->kick = 0.0F;
        e102->shot_phase = E102_SHOT_TURN;
    case E102_SHOT_TURN:
        lockon = nearest_lockon(work, e102, (0));
        if (lockon != ((void *)0)) {
            e102->shot_way = shot_choose_way(work, lockon->work);
        } else {
            e102->shot_way = SHOT_AHEAD;
        }
        e102->shot_action = shot_actions[e102->shot_way];
        if (lockon == ((void *)0)) {
            break;
        }
        if (e102->lockon_count <= 0) {
            break;
        }
        if (e102->aim_mode != E102_AIM_READY) {
            break;
        }
        e102->shot_phase = E102_SHOT_MARK;
    case E102_SHOT_MARK:
        e102->shot_frame = 14.0F;
        count = 0;
        list = &e102->lockons[0];
        bonus = CreateElementalTask(0x2, 2, FUN_8c0d514a);
        if (bonus == ((void *)0)) {
            break;
        }
        for (i = e102->lockon_count; i > 0; i--) {
            lockon = *list++;
            extra = lockon->extra;
            if (extra->shot != ((void *)0)) {
                continue;
            }
            if (extra->target == ((void *)0)) {
                continue;
            }
            if (extra->target->placement != ((void *)0)) {
                FUN_8c091aca(extra->target);
            } else if (extra->target->parent->placement != ((void *)0)) {
                FUN_8c091aca(extra->target->parent);
            }
            if (extra->target->work == ((void *)0)) {
                continue;
            }
            extra->marked = (1);
            if (!e102_target_counts(extra->target)) {
                continue;
            }
            count++;
            extra->bonus = bonus;
        }
        ((struct bonus_work *)(bonus)->work)->volley[0] = count;
    case E102_SHOT_NEXT:
        e102->kick = 0.0F;
        lockon = nearest_lockon(work, e102, (1));
        if (lockon != ((void *)0)) {
            e102->shot_way = shot_choose_way(work, lockon->work);
            e102->shot_action = shot_actions[e102->shot_way];
            e102->shot_phase = E102_SHOT_AIM;
        } else {
            e102->shot_phase = E102_SHOT_START;
            break;
        }
    case E102_SHOT_AIM:
        e102->shot_frame += 1.0F;
        if (e102->shot_frame < 15.0F) {
            break;
        }
        e102->shot_phase = E102_SHOT_KICK;
        lockon = nearest_lockon(work, e102, (1));
        if (lockon == ((void *)0)) {
            break;
        }
        extra = lockon->extra;
        if (extra->target == ((void *)0)) {
            break;
        }
        if (extra->target->step == ((void *)0)) {
            break;
        }
        shot = CreateElementalTask(0x1 | 0x2, 6, shot_step);
        if (shot != ((void *)0)) {
            ((struct player_vars *)&(shot->work)->vars)->player = ((struct player_vars *)&(task->work)->vars)->player;
            shot->work->pos = e102->shot_pos;
            shot->motion->speed = e102->shot_dir;
            ((struct shot_work *)(shot)->work)->lockon = lockon;
            extra->shot = shot;
            FUN_8c0d48f8(task, record, e102);
        }
        break;
    case E102_SHOT_KICK:
        e102->shot_frame += 1.0F;
        e102->kick = 1.0F - ((e102->shot_frame - 15.0F) *
                             (1.0F / (30.0F - 15.0F)));
        if (nearest_lockon(work, e102, (1)) != ((void *)0)) {
            if (e102->shot_frame >= 24.0F) {
                e102->shot_frame = 10.0F;
                e102->shot_phase = E102_SHOT_NEXT;
                break;
            }
        } else {
            if (e102->shot_frame >= 30.0F) {
                e102->shot_frame = 0.0F;
                e102->shot_phase = E102_SHOT_NEXT;
                break;
            }
        }
        break;
    }
    e102->lockon_count = e102->shot_count = 0;
}
void e102_release_shot(struct task *shot, NJS_VECTOR *speed)
{
    ((struct shot_work *)(shot)->work)->mode = SHOT_FREE;
    ((struct shot_work *)(shot)->work)->lockon = ((void *)0);
    if (speed != ((void *)0)) {
        shot->motion->speed = *speed;
    }
}
void FUN_8c0d48f8(struct task *task, struct player *record,
                       struct e102 *e102)
{
    NJS_VECTOR speed;
    struct task_work *work;
    struct task *made;
    Angle ang;
    speed = fire_smoke_speed;
    work = task->work;
    made = CreateElementalTask(0x2, 3, shot_flash_step);
    if (made != ((void *)0)) {
        made->work->pos = e102->shot_pos;
        ((struct flash_work *)(made)->work)->player = ((struct player_vars *)&(task->work)->vars)->player;
        ((struct flash_work *)(made)->work)->upgrades = record->upgrades;
    }
    ang = 0x8000 - work->ang.y;
    made = CreateElementalTask(0x2, 3, FUN_8c0d431a);
    if (made != ((void *)0)) {
        made->work->pos = e102->shot_pos;
        ((struct blast_work *)(made)->work)->ang_y = ang;
    }
    speed.x = njCos(ang) * 1.0F;
    speed.z = njSin(ang) * 1.0F;
    e102_smoke_create(&e102->points[0], &speed, 0.2F);
    e102_smoke_create(&e102->points[1], &speed, 0.2F);
    if (work->id == 1 && EV_CheckCansel() != (1)) {
        vibration_start(0, 4, 15, 0);
    }
}
