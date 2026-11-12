/* @unit 8C102DC0-8C107640 +r04 +egflags +pool32 +asmfunc=FUN_8c102dd6:+8c102dde,FUN_8c102dde:+8c102dee,zero_create:+8c103030,FUN_8c1031ec:!8c104508,FUN_8c1048b8:+8c104aa0,FUN_8c104cfc:+8c104ee4,FUN_8c104f76:+8c105590,zero_marker_step:+8c105abc,FUN_8c1064c0:+8c1067de,FUN_8c106978:+8c106a7e,FUN_8c106cd6:+8c106e0c,FUN_8c106ec4:+8c106f68,EggrobForEvent0:+8c107004,zero_event_step:+8c10754c,FUN_8c104508:+8c104740,FUN_8c104ee4:+8c104f76,FUN_8c105590:+8c105758,FUN_8c105b48:+8c105ca2,FUN_8c10616c:+8c1064c0,FUN_8c1067de:+8c1068cc,FUN_8c1068cc:+8c106978,FUN_8c106a7e:+8c106b0a,FUN_8c106b0a:+8c106cd6,zero_show_hatena:+8c106ec4,zero_amy_distance2:+8c104cfc,FUN_8c105758:+8c105860,zero_destroy:+8c103192,zero_collide:+8c1048b8,zero_fall:+8c10756c,zero_move:+8c107640,zero_event_destroy:+8c107042,FUN_8c106e0c:+8c106e92 +poolafter=zero_reset,zero_distance2,zero_draw_link,FUN_8c105e88,FUN_8c106e0c */
/* Ported from the Japanese release's src/enemy/zero.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
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
void LoopTaskC(struct task *task);
void heap_init(void);
void *heap_alloc(int size);
void *heap_calloc(int count, int size);
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
void world_collect_near_players(void);
void world_collect_all(void);
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
void SetMaterial(Float alpha, Float red, Float green, Float blue);
void draw_line(Float x1, Float y1, Float z1, Float x2, Float y2, Float z2);
void draw_line_colored(Float x1, Float y1, Float z1, const NJS_COLOR *color1,
                       Float x2, Float y2, Float z2, const NJS_COLOR *color2);
void draw_line_v(NJS_POINT3 *from, NJS_POINT3 *to);
void draw_highlight_near(struct task_work *work, Sint16 characters);
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
void CreateSmoke(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void dust_create_from(struct dust_params *params);
void dust_create_glow(struct dust_params *params);
void dust_grow_step(struct particle *particle, struct particle_pool *pool);
extern NJS_TEXLIST snow_texlist;
extern struct particle_pool_spec snow_pool;
void snow_create(NJS_POINT3 *pos, const NJS_VECTOR *speed, Float scale);
void snow_create_from(struct dust_params *params);
struct task;
extern NJS_TEXLIST zero_texlist;
struct zero_start {
    Sint32 how;
    NJS_POINT3 pos;
    NJS_POINT3 target;
};
struct task *zero_create(struct zero_start *start);
void FUN_8c102dd6(void);
void FUN_8c102dde(NJS_VECTOR *push);
void EggrobForEvent0(struct task *task);
Bool zero_event_grab(NJS_POINT3 *pos);
void zero_show_hatena_jp(NJS_POINT3 *pos);
void FUN_8c106ec4(NJS_POINT3 *pos);
struct zero_start;
void zero_init(void);
Bool zero_appear(struct zero_start *start);
Bool zero_kill(void);
Bool zero_leave(void);
Bool zero_exists(void);
Bool zero_get_pos(NJS_POINT3 *pos);
extern NJS_ACTION zero_stand_action;
enum event_look {
    EVENT_LOOK_NONE,
    EVENT_LOOK_ANGLES,
    EVENT_LOOK_POINT,
    EVENT_LOOK_TASK
};
enum event_action {
    EVENT_ACTION_NONE,
    EVENT_ACTION_DONE,
    EVENT_ACTION_RUN,
    EVENT_ACTION_MOVE,
    EVENT_ACTION_PUSH,
    EVENT_ACTION_TURN_BY,
    EVENT_ACTION_TURN_TO
};
struct event_motion {
    Uint8 flags;
    Uint8 blend;
    NJS_ACTION action;
    NJS_TEXLIST *texlist;
    struct event_motion *next;
    Float speed;
};
struct event_path_point {
    Sint8 ang_x;
    Sint8 ang_y;
    Sint8 ang_z;
    NJS_POINT3 pos;
};
struct event_path {
    Sint32 count;
    struct event_path_point *points;
};
struct event_path_entry {
    Uint8 flags;
    struct event_path *path;
    Float speed;
    struct event_path_entry *next;
};
struct event_mouth_key {
    Sint8 steps;
    Sint8 shape;
};
extern struct event_mouth_key *event_mouth_scripts[31];
struct event_mouth {
    Sint8 shape;
    Sint8 next_shape;
    Sint16 steps;
    Sint16 timer;
    const char *text;
    struct event_mouth_key *script;
};
struct event_work {
    Uint8 flags;
    Uint8 unk_01;
    Uint8 unk_02[2];
    Uint8 look;
    struct angles look_ang;
    NJS_POINT3 look_pos;
    struct task *look_task;
    Uint8 action;
    union {
        NJS_POINT3 pos;
        struct angles ang;
    } move;
    Float speed;
    Float accel;
    Float motion_frame;
    struct event_motion *motions;
    struct event_motion *previous;
    Float path_frame;
    struct event_path_entry *paths;
    NJS_POINT3 origin;
    struct event_mouth mouth;
    NJS_POINT3 offset;
    Float shadow;
};
void SetEventWork(struct task_work *work);
void event_free(struct task_work *work);
void event_motions_clear(struct task_work *work);
void event_motions_add_action(struct task_work *work, NJS_ACTION *action,
                              NJS_TEXLIST *texlist, Float speed, int flags,
                              int blend);
void event_motions_add(struct task_work *work, NJS_OBJECT *object,
                       NJS_MOTION *motion, NJS_TEXLIST *texlist, Float speed,
                       int flags, int blend);
void event_motions_draw(struct task_work *work);
void event_paths_add(struct task_work *work, struct event_path *path,
                     Float speed, int flags);
void event_paths_clear(struct task_work *work);
void ExecEventPath(struct task_work *work);
void event_mouth_start(struct task_work *work, const char *text);
void event_mouth_step(struct task_work *work);
void event_mouth_stop(struct task_work *work);
struct task *event_actor_create(void);
void event_actor_step(struct task *task);
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
void placement_stop(struct task *task);
void placement_kill(struct task *task);
Uint16 placement_get_kind(struct task *task);
void placement_set_state(struct task *task, Sint8 state);
Sint8 placement_get_state(struct task *task);
struct task;
enum amy_action {
    AMY_TAKING_DRUM = 1,
    AMY_SETTING_DRUM,
    AMY_RECOILING,
    AMY_HOLDING_HANDLE,
    AMY_SPINNING,
    AMY_BALANCING,
    AMY_HAMMER_JUMPING,
    AMY_AIR_HAMMERING,
    AMY_DIZZY
};
void amy_step(struct task *task);
Bool FUN_8c0ddd26(int player);
int amy_get_action(int player);
Bool amy_set_hammer_scale(Uint8 player, Float scale);
Bool amy_grow_hammer(Uint8 player, Float scale);
Bool amy_call_to_handle(void);
Bool amy_call_hidden(void);
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
void PDestruct(int player);
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
int dsPlay_iloop(int se, int id, int priority, int volume);
int dsPlay_timer(int se, int id, int priority, int volume, int updates);
int sound_play_at_for(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
int sound_play_around(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, Float radius, int updates);
void sound_stop(int se);
void dsStop_id(int id);
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
struct twinkle_mirror {
    NJS_POINT3 corner0;
    NJS_POINT3 corner1;
    NJS_VECTOR normal;
    int pair;
};
Bool twinkle_mirrors_clear(void);
Bool twinkle_mirrors_add(int count, struct twinkle_mirror *mirrors);
struct task *twinkle_reflect(struct task *task);
struct task *twinkle_reflect_player(struct task *task);
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
void SaveConstantAttr(void);
void LoadConstantAttr(void);
void OnConstantAttr(Uint32 and_attr, Uint32 or_attr);
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
enum zero_mode {
    ZERO_APPEAR = 1,
    ZERO_STILL = 2,
    ZERO_FALL = 5,
    ZERO_WONDER = 6,
    ZERO_TURN_HEAD = 8,
    ZERO_TURN_BODY = 9,
    ZERO_WALK = 10,
    ZERO_DASH_IN = 11,
    ZERO_HIT_FRONT = 12,
    ZERO_HIT_BEHIND = 13,
    ZERO_STOMP = 14,
    ZERO_LEAVE = 15,
    ZERO_AIM = 16,
    ZERO_BEAM = 17,
    ZERO_WIND_UP = 18,
    ZERO_THROW = 19,
    ZERO_REEL = 20,
    ZERO_EVENT = 21
};
enum zero_action {
    ZERO_ACT_HIT_BEHIND = 0,
    ZERO_ACT_HIT_BEHIND_LAND = 1,
    ZERO_ACT_HIT_FRONT = 2,
    ZERO_ACT_HIT_FRONT_LAND = 3,
    ZERO_ACT_AIM = 4,
    ZERO_ACT_WALK = 5,
    ZERO_ACT_WIND_UP = 9,
    ZERO_ACT_THROW = 11,
    ZERO_ACT_BEAM = 12,
    ZERO_ACT_BEAM_END = 13,
    ZERO_ACT_WONDER_START = 14,
    ZERO_ACT_WONDER = 15,
    ZERO_ACT_WONDER_END = 16,
    ZERO_ACT_STOMP_LIFT = 17,
    ZERO_ACT_STOMP = 18,
    ZERO_ACT_LEAVE = 19,
    ZERO_ACT_STAND = 20
};
enum zero_hand {
    ZERO_HAND_OUT,
    ZERO_HAND_UNTHROWN,
    ZERO_HAND_READY,
    ZERO_HAND_FLYING,
    ZERO_HAND_CAUGHT,
    ZERO_HAND_MISSED,
    ZERO_HAND_BACK,
    ZERO_HAND_HOME
};
enum zero_grab { ZERO_GRAB_NONE, ZERO_GRAB_ASKED, ZERO_GRAB_STARTED };
enum zero_turn_phase { PHASE_AIM, PHASE_HEAD, PHASE_BODY, PHASE_DONE };
enum zero_sight_mode { SIGHT_START, SIGHT_FLY };
enum zero_shock_mode { SHOCK_START, SHOCK_SPREAD };
enum zero_marker_mode {
    MARKER_START,
    MARKER_LOCK,
    MARKER_WIND_UP,
    MARKER_LOST,
    MARKER_SWELL
};
struct zero_vars {
    Uint8 player;
    Uint8 unk_01[3];
    Sint32 timer;
    union {
        Float alpha;
        Sint8 turn[4];
    } shade;
};
struct zero_sight_vars {
    Float travel;
};
struct zero_mark_vars {
    Uint16 frame;
    Uint8 unk_02[6];
    struct task_work *follow;
};
struct zero_marker_vars {
    Uint8 unk_00[8];
    Float grow;
};
struct zero_shock_vars {
    Uint32 steps;
};
struct zero_sweep_vars {
    NJS_POINT3 last_end;
};
struct zero_request {
    Bool blind;
    NJS_VECTOR push;
};
extern NJS_OBJECT zero_neck_object[1];
extern NJS_OBJECT zero_head_object[1];
extern NJS_OBJECT zero_bob_object;
extern NJS_OBJECT zero_hand_object[1];
extern NJS_OBJECT zero_claw0_object[1];
extern NJS_OBJECT zero_claw1_object[1];
extern NJS_OBJECT zero_claw1_tip_object[1];
extern NJS_OBJECT zero_link_object;
extern NJS_OBJECT zero_shock_object;
extern NJS_ACTION zero_hit_behind_action;
extern NJS_ACTION zero_hit_behind_land_action;
extern NJS_ACTION zero_hit_front_action;
extern NJS_ACTION zero_hit_front_land_action;
extern NJS_ACTION zero_aim_action;
extern NJS_ACTION zero_walk_action;
extern NJS_ACTION dat_8c5fc4e0;
extern NJS_ACTION dat_8c6001d4;
extern NJS_ACTION dat_8c600f88;
extern NJS_ACTION zero_wind_up_action;
extern NJS_ACTION zero_wind_up_end_action;
extern NJS_ACTION zero_throw_action;
extern NJS_ACTION zero_beam_action;
extern NJS_ACTION zero_beam_end_action;
extern NJS_ACTION zero_wonder_action;
extern NJS_ACTION zero_wonder_loop_action;
extern NJS_ACTION zero_stomp_lift_action;
extern NJS_ACTION zero_stomp_action;
extern NJS_ACTION zero_leave_action;
void zero_setup(struct task *task);
void zero_reset(struct task *task);
void zero_destroy(struct task *task);
void FUN_8c1031ec(struct task *task);
void zero_collide(struct task *task);
Bool Eggrob_FindAmy(struct task *task);
Float zero_amy_distance2(NJS_POINT3 *pos);
void FUN_8c104cfc(struct task *task);
void FUN_8c104ee4(void);
void FUN_8c104f76(struct task *task);
void zero_sweep_step(struct task *task);
void FUN_8c105758(struct task *task);
void zero_marker_step(struct task *task);
int zero_hand_launch(struct task *task);
int zero_hand_fly(struct task *task);
int FUN_8c1064c0(struct task *task);
void zero_hand_shadow_step(struct task *task);
void FUN_8c106978(struct task *task);
void zero_hirame_step(struct task *task);
void zero_shock_step(struct task *task);
void FUN_8c106cd6(struct task *task);
void FUN_8c106e0c(struct task *task);
void zero_event_destroy(struct task *task);
void zero_event_step(struct task *task);
void zero_fall(struct task *task);
void zero_move(struct task *task);
extern struct player_anim zero_anim;
extern Float zero_hit_pace;
extern Float zero_frame;
extern int zero_beam_turn_timer;
extern Bool zero_beam_hit;
extern Float zero_beam_length;
extern NJS_POINT3 zero_beam_aim;
extern NJS_VECTOR zero_beam_dir;
extern NJS_POINT3 zero_beam_last_start;
extern NJS_POINT3 zero_beam_end;
extern NJS_POINT3 zero_beam_last_end;
extern NJS_VECTOR zero_beam_drift;
extern Bool zero_locked;
extern NJS_POINT3 zero_lock_pos;
extern int zero_hand_state;
extern Angle zero_hand_ang_y;
extern Angle zero_hand_pitch;
extern NJS_POINT3 zero_arm_end;
extern NJS_POINT3 zero_hand_pos;
extern NJS_VECTOR zero_hand_speed;
extern NJS_POINT3 zero_chain[16];
extern Bool zero_sight_out;
extern Bool zero_sight_saw;
extern Float zero_damage;
extern Float zero_restless;
extern struct zero_request zero_request;
extern Bool zero_beam_unblocked;
extern NJS_POINT3 zero_beam_points[2];
extern Uint32 dat_8c7ae0d4;
extern NJS_MATRIX zero_node_matrix;
extern NJS_POINT3 zero_sweep_points[4];
extern NJS_POINT3 zero_scorch_points[2];
extern int zero_event_grab_state;
extern NJS_POINT3 zero_event_grab_pos;
extern struct player_action zero_actions[21];
extern struct collision_shape zero_shapes[2];
extern struct collision_shape zero_sight_shape[1];
extern NJS_COLOR zero_beam_colors[2];
extern NJS_POINT3COL zero_beam_line;
extern NJS_COLOR zero_sweep_colors[4];
extern NJS_POINT3COL zero_sweep_quad;
extern NJS_COLOR zero_scorch_colors[2];
extern NJS_POINT3COL zero_scorch_line;
extern NJS_POINT3 zero_marker_points[5];
extern NJS_COLOR zero_marker_colors[5];
extern NJS_POINT3COL zero_marker_faces;
extern NJS_TEXANIM zero_hirame_texanims[3];
extern NJS_SPRITE zero_hirame_sprite;
extern NJS_TEXANIM zero_hatena_texanims[3];
extern NJS_SPRITE zero_hatena_sprite;
extern struct collision_shape zero_shock_shape[1];
void zero_clear_request(void)
{
    zero_request.blind = (0);
    ((&zero_request.push)->x = 0.0F, (&zero_request.push)->y = 0.0F, (&zero_request.push)->z = 0.0F);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c102dd6(void)
{
    zero_request.blind = (1);
}
#else
void FUN_8c102dd6(void)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c102dde(NJS_VECTOR *push)
{
    zero_request.push = *push;
}
#else
void FUN_8c102dde(NJS_VECTOR *push)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
struct task *zero_create(struct zero_start *start)
{
    struct task *task;
    Float dx;
    Float dz;
    if (GetPlayerNumber() != 5 || playertwp[0] == ((void *)0)) {
        return ((void *)0);
    }
    if ((task = CreateElementalTask(0x2, 3, zero_setup)) == ((void *)0)) {
        return ((void *)0);
    }
    zero_beam_unblocked = (0);
    switch (GetStageNumber()) {
    case ((3) << 8 | (1)):
    case ((3) << 8 | (2)):
        zero_beam_unblocked = (1);
        break;
    }
    switch (start->how) {
    case 0:
        task->work->pos = start->pos;
        task->work->pos.y += 5.0F;
        dx = start->target.x - start->pos.x;
        dz = start->target.z - start->pos.z;
        task->work->ang.y = (Angle)(njArcTan2(dz, -dx) * (65536.0 / (2 * 3.141592)));
        ((struct zero_vars *)&(task->work)->vars)->timer =
            (int)(njSqrt((dx * dx) + (dz * dz)) * (1.0F / 3.0F));
        ((task->work)->scl).y = 0.0F;
        ((task->work)->scl).z = 0.0F;
        task->work->mode = ZERO_DASH_IN;
        break;
    case 1:
        task->work->pos = start->pos;
        if (playertwp[0] == ((void *)0)) {
            task->work->ang.y = 0;
        } else {
            dx = playertwp[0]->pos.x - start->pos.x;
            dz = playertwp[0]->pos.z - start->pos.z;
            task->work->ang.y = (Angle)(njArcTan2(dz, -dx) * (65536.0 / (2 * 3.141592)));
        }
        task->work->mode = ZERO_APPEAR;
        break;
    case 2:
        task->work->pos = start->pos;
        task->work->pos.y += 5.0F;
        dx = start->target.x - start->pos.x;
        dz = start->target.z - start->pos.z;
        task->work->ang.y = (Angle)(njArcTan2(dz, -dx) * (65536.0 / (2 * 3.141592)));
        ((struct zero_vars *)&(task->work)->vars)->timer =
            (int)(njSqrt((dx * dx) + (dz * dz)) * (1.0F / 3.0F));
        ((task->work)->scl).x = 1.0F;
        ((task->work)->scl).y = 4.0F;
        ((task->work)->scl).z = 0.0F;
        task->work->mode = ZERO_FALL;
        break;
    }
    vibration_start(0, 6, 15, 0);
    return task;
}
#else
struct task *zero_create(struct zero_start *start)
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
    asm_stub[0] = 120; asm_stub[1] = 121;
    return 0;
}
#endif
void zero_setup(struct task *task)
{
    CCL_Init(task, zero_shapes, 3, 1, 2);
    task->destructor = zero_destroy;
    task->draw = FUN_8c104cfc;
    if (GetStageNumber() == ((3) << 8 | (2))) {
        twinkle_reflect(task);
    }
    task->step = FUN_8c1031ec;
    zero_damage = 0.0F;
    zero_reset(task);
    FUN_8c104ee4();
}
void zero_reset(struct task *task)
{
    struct task_work *work = task->work;
    if (playertwp[0] == ((void *)0)) {
        return;
    }
    zero_anim.state = 0;
    zero_anim.actions = zero_actions;
    zero_anim.action = zero_anim.current = ZERO_ACT_STAND;
    zero_anim.pace = &zero_hit_pace;
    work->tick = 0;
    ((work)->ang.x) = 0;
    ((work)->ang.z) = 0;
    zero_neck_object[0].ang[1] = 0;
    zero_head_object[0].ang[2] = ((Angle)(((180) * 65536.0) / 360.0));
    zero_sight_out = (0);
    zero_sight_saw = (0);
    work->collision->shapes[1].flags |= 0x10;
    zero_restless = 0.0F;
    zero_clear_request();
}
void zero_restore(struct task_work *work)
{
    work->tick = 0;
    (((struct zero_vars *)&(work)->vars)->shade.alpha) = 1.0F;
    work->collision->shapes[1].flags |= 0x10;
    zero_locked = (0);
    zero_neck_object[0].ang[1] = 0;
    zero_head_object[0].ang[2] = ((Angle)(((180) * 65536.0) / 360.0));
    zero_hand_object[0].evalflags &= ~0x08;
    zero_claw1_object[0].evalflags &= ~0x08;
    zero_claw1_tip_object[0].evalflags &= ~0x08;
    zero_claw0_object[0].evalflags &= ~0x08;
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void zero_destroy(struct task *task)
{
}
#else
void zero_destroy(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
Bool zero_play_frames(Float frames)
{
    zero_frame += frames;
    zero_anim.frame = zero_frame;
    if (frames > 0.0F &&
        zero_anim.frame >
            (Float)zero_actions[zero_anim.action].action->motion->nbFrame -
                frames) {
        return (1);
    }
    if (frames < 0.0F && -frames > zero_anim.frame) {
        return (1);
    }
    return (0);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c1031ec(struct task *task)
{
    struct task_work *work;
    struct task_work *amy;
    struct task *child;
    NJS_POINT3 point;
    NJS_POINT3 vector;
    NJS_POINT2 amy_screen;
    NJS_POINT2 zero_screen;
    Float distance;
    Float dx;
    Float dz;
    Float lock_x;
    Float lock_z;
    Float speed;
    Float amy_depth;
    Float zero_depth;
    Float amy_radius;
    Float zero_radius;
    Float sx;
    Float sy;
    Float frame;
    Float gap;
    Float target_alpha;
    Float alpha;
    Angle angle;
    int action;
    Bool covered;
    int i;
    work = task->work;
    amy = playertwp[0];
    if (edit_mode == 1) {
        (((struct zero_vars *)&(work)->vars)->shade.alpha) = 0.5F;
        FUN_8c104cfc(task);
        shadow_draw(work, 1.8F);
        zero_locked = (0);
        return;
    }
    if (amy == ((void *)0)) {
        dsStop_id((int)work);
        zero_kill();
        return;
    }
    if ((distance = zero_amy_distance2(&task->work->pos)) >
        400.0F * 400.0F) {
        dsStop_id((int)work);
        zero_kill();
        return;
    }
    if (work->mode != ZERO_LEAVE && (work->tick & 0x1)) {
        ((struct zero_vars *)&(work)->vars)->timer = 60;
        ((work)->scl).x = 0.0F;
        ((work)->scl).y = 0.0F;
        ((work)->scl).z = 0.0F;
        zero_anim.action = ZERO_ACT_LEAVE;
        work->mode = ZERO_LEAVE;
    }
    if (EV_CheckCansel() == (1)) {
        return;
    }
    if (work->mode != ZERO_WIND_UP && work->mode != ZERO_THROW &&
        work->mode != ZERO_HIT_BEHIND && work->mode != ZERO_HIT_FRONT &&
        work->mode != ZERO_LEAVE && (work->flags & 0x4)) {
        dsStop_id((int)work);
        if (zero_damage < 1.0F) {
            zero_restore(work);
            dx = amy->pos.x - work->pos.x;
            dz = amy->pos.z - work->pos.z;
            zero_hit_pace =
                ((1.0F - zero_damage) * 0.5F) + (zero_damage * 2.0F);
            speed = 1.0F;
            ((work)->scl).y = speed = (speed - (zero_damage * 0.5F)) * 1.0F;
            if (DiffAngle(work->ang.y, angle = (Angle)(njArcTan2(dz, -dx) *
                                                            (65536.0 / (2 * 3.141592)))) <
                ((Angle)(((90) * 65536.0) / 360.0))) {
                work->ang.y = angle;
                ((work)->scl).x = -speed;
                zero_anim.action = ZERO_ACT_HIT_FRONT;
                work->mode = ZERO_HIT_FRONT;
            } else {
                work->ang.y = angle + ((Angle)(((180) * 65536.0) / 360.0));
                ((work)->scl).x = speed;
                zero_anim.action = ZERO_ACT_HIT_BEHIND;
                work->mode = ZERO_HIT_BEHIND;
            }
            if ((zero_damage += 0.2F) > 1.0F) {
                zero_damage = 1.0F;
            }
            dsPlay_oneshot_v(767, 0, 0, 50, work->pos.x, work->pos.y,
                          work->pos.z);
        }
    }
    switch (action = zero_anim.action, frame = zero_anim.frame, work->mode) {
    case ZERO_APPEAR:
        if (--((struct zero_vars *)&(work)->vars)->timer <= 0) {
            ((work)->scl).x = ((work)->scl).z = 0.0F;
            ((work)->scl).y = -1.0F;
            work->mode = ZERO_FALL;
            break;
        }
        break;
    case ZERO_FALL:
        zero_fall(task);
        zero_move(task);
        zero_collide(task);
        if (!(work->flags & 0x1)) {
            break;
        }
        if (((Float)_builtin_fabsf((Float)(((work)->scl).y))) < 0.1F) {
            dx = amy->pos.x - work->pos.x;
            dz = amy->pos.z - work->pos.z;
            if (DiffAngle(work->ang.y,
                               (Angle)(njArcTan2(dz, -dx) * (65536.0 / (2 * 3.141592)))) <
                ((Angle)(((90) * 65536.0) / 360.0))) {
                ((struct zero_vars *)&(work)->vars)->timer = 120;
                zero_anim.action = ZERO_ACT_WALK;
                work->mode = ZERO_WALK;
                break;
            } else {
                ((struct zero_vars *)&(work)->vars)->timer = 30;
                zero_anim.action = ZERO_ACT_WONDER_START;
                work->mode = ZERO_WONDER;
                break;
            }
        } else {
            dsPlay_oneshot_v(762, 0, 0, 50, work->pos.x, work->pos.y,
                          work->pos.z);
            vibration_start(0, 4, 15, 0);
            break;
        }
        break;
    case ZERO_WONDER:
        switch (action) {
        case ZERO_ACT_WONDER:
            if (((struct zero_vars *)&(work)->vars)->timer == 30) {
                zero_sight_saw = (0);
                if ((child = CreateElementalTask(0x2, 6, FUN_8c106978)) !=
                    ((void *)0)) {
                    child->work->pos = work->pos;
                    child->work->pos.y += 15.0F;
                }
                dsPlay_oneshot(760, 0, 0, 0);
            }
            if (--((struct zero_vars *)&(work)->vars)->timer > 0) {
                break;
            }
            if (zero_restless > 0.9F && rand() * (1.0F / (32767 + 1)) < 0.5F) {
                ((work)->ang.x) = (Angle)(rand() * 2.0F);
            } else {
                dx = amy->pos.x - work->pos.x;
                dz = amy->pos.z - work->pos.z;
                ((work)->ang.x) = angle_difference(
                    work->ang.y, (Angle)(njArcTan2(dz, -dx) * (65536.0 / (2 * 3.141592))));
                ((work)->ang.x) += (Angle)(((rand() * (((0.5F) - (-0.5F)) * (1.0F / (32767 + 1)))) + (-0.5F)) * 16384.0F);
            }
            ((work)->ang.z) = 0;
            zero_set_action(ZERO_ACT_WONDER_END,
                            (Float)zero_actions[ZERO_ACT_WONDER_END]
                                    .action->motion->nbFrame -
                                1.0F);
            break;
        case ZERO_ACT_WONDER_END:
            if (zero_play_frames(-1.0F) == (1)) {
                work->mode = ZERO_TURN_HEAD;
                dsPlay_oneshot_v(772, 0, 0, 50, work->pos.x, work->pos.y,
                              work->pos.z);
            }
        }
        break;
    case ZERO_TURN_HEAD:
        ((work)->ang.z) =
            AdjustAngle(((work)->ang.z), ((work)->ang.x), 0x800);
        zero_neck_object[0].ang[1] = ((work)->ang.z);
        if (DiffAngle(((work)->ang.x), ((work)->ang.z)) < 0x800) {
            work->mode = ZERO_TURN_BODY;
            dsPlay_oneshot_v(772, 0, 0, 50, work->pos.x, work->pos.y,
                          work->pos.z);
            break;
        }
        break;
    case ZERO_TURN_BODY:
        angle = AdjustAngle(((work)->ang.z), 0, 0x800);
        work->ang.y += angle_difference(angle, ((work)->ang.z));
        ((work)->ang.z) = angle;
        zero_neck_object[0].ang[1] = ((work)->ang.z);
        if (DiffAngle(((work)->ang.z), 0) < 0x800) {
            ((struct zero_vars *)&(work)->vars)->timer = (int)((rand() * (((180.0F) - (120.0F)) * (1.0F / (32767 + 1)))) + (120.0F));
            zero_anim.action = ZERO_ACT_WALK;
            work->mode = ZERO_WALK;
            break;
        }
        break;
    case ZERO_WALK:
        ((struct zero_vars *)&(work)->vars)->timer--;
        if (amy->pos.y - work->pos.y > 20.0F) {
            ((struct zero_vars *)&(work)->vars)->timer = 0;
        }
        if ((work->flags & 0x100) && distance < 100.0F * 100.0F) {
            ((struct zero_vars *)&(work)->vars)->timer = 0;
        }
        if (FUN_8c0ddd26(0) && distance < 20.0F * 20.0F) {
            dx = amy->pos.x - work->pos.x;
            dz = amy->pos.z - work->pos.z;
            if (DiffAngle(work->ang.y,
                               (Angle)(njArcTan2(dz, -dx) * (65536.0 / (2 * 3.141592)))) <
                ((Angle)(((90) * 65536.0) / 360.0))) {
                ((struct zero_vars *)&(work)->vars)->timer = 0;
            }
        }
        if (((struct zero_vars *)&(work)->vars)->timer > 0) {
            if ((((work)->scl).x += 0.04F) > 1.25F) {
                ((work)->scl).x = 1.25F;
            }
            if (distance > 100.0F * 100.0F) {
                dx = amy->pos.x - work->pos.x;
                dz = amy->pos.z - work->pos.z;
                work->ang.y = AdjustAngle(
                    work->ang.y, (Angle)(njArcTan2(dz, -dx) * (65536.0 / (2 * 3.141592))),
                    0x400);
            }
        } else if ((((work)->scl).x += -0.1F) < 0.0F) {
            ((work)->scl).x = 0.0F;
            if ((zero_restless += 0.125F) > 1.0F) {
                zero_restless = 1.0F;
            }
            if (distance < 150.0F * 150.0F &&
                rand() * (1.0F / (32767 + 1)) < zero_restless) {
                zero_restless *= 0.5F;
                zero_anim.action = ZERO_ACT_STOMP_LIFT;
                work->mode = ZERO_STOMP;
                break;
            }
            if (amy->pos.y - work->pos.y > 20.0F) {
                ((work)->scl).x = 1.0F;
                ((work)->scl).y = 4.0F;
                work->mode = ZERO_FALL;
                dsPlay_oneshot_v(771, 0, 0, 50, work->pos.x, work->pos.y,
                              work->pos.z);
                for (i = 0; i < 5; i++) {
                    point.x = 0.5F - (rand() * (1.0F / (32767 + 1)));
                    point.y = -(rand() * (0.5F * (1.0F / (32767 + 1))));
                    point.z = 0.5F - (rand() * (1.0F / (32767 + 1)));
                    CreateSmoke(&work->pos, &point, 1.0F);
                }
            } else {
                work->mode = ZERO_FALL;
                break;
            }
        }
        zero_fall(task);
        zero_move(task);
        zero_collide(task);
        if (Eggrob_FindAmy(task) == (1)) {
            if ((child = CreateElementalTask(0x2, 6, zero_hirame_step)) != ((void *)0)) {
                child->work->pos = work->pos;
                ((struct zero_mark_vars *)&(child->work)->vars)->follow = work;
            }
            dsPlay_oneshot(760, 0, 0, 0);
            zero_restless = 0.0F;
            zero_anim.action = ZERO_ACT_AIM;
            work->mode = ZERO_AIM;
            break;
        }
        break;
    case ZERO_DASH_IN:
        ((struct zero_vars *)&(work)->vars)->timer--;
        if (((struct zero_vars *)&(work)->vars)->timer > 0) {
            ((work)->scl).x = 3.0F;
        } else if ((((work)->scl).x += -0.5F) < 0.0F) {
            ((work)->scl).x = 0.0F;
            work->mode = ZERO_FALL;
            dsPlay_oneshot(1184, 0, 0, 0);
            break;
        }
        zero_move(task);
        break;
    case ZERO_STILL:
        break;
    case ZERO_AIM:
        if (action == ZERO_ACT_STAND) {
            ((work)->scl).x = 0.0F;
            ((struct zero_vars *)&(work)->vars)->timer = 120;
            zero_anim.action = ZERO_ACT_BEAM;
            work->mode = ZERO_BEAM;
            break;
        }
        if (CalcDistance(&work->pos, &amy->pos) > 40.0F) {
            if ((((work)->scl).x += 0.04F) > 0.625F) {
                ((work)->scl).x = 1.25F;
            }
        } else if ((((work)->scl).x += -0.1F) < 0.0F) {
            ((work)->scl).x = 0.0F;
        }
        if (zero_anim.frame < 30.0F) {
            if (!((int)zero_anim.frame & 7)) {
                dsPlay_oneshot_v(759, 0, 0, 50, work->pos.x, work->pos.y,
                              work->pos.z);
            }
        }
        zero_fall(task);
        zero_move(task);
        zero_collide(task);
        break;
    case ZERO_BEAM:
        switch (action) {
        case ZERO_ACT_BEAM:
            if (frame <= 1.0F) {
                FUN_8c104ee4();
            } else if (frame >= 19.0F) {
                if (--((struct zero_vars *)&(work)->vars)->timer > 0) {
                    FUN_8c104f76(task);
                    if (zero_locked == (1) && ((struct zero_vars *)&(work)->vars)->timer > 60) {
                        ((struct zero_vars *)&(work)->vars)->timer = 60;
                    }
                } else {
                    ((struct zero_vars *)&(work)->vars)->timer = 14;
                    zero_anim.frame = ((struct zero_vars *)&(work)->vars)->timer;
                    zero_anim.action = zero_anim.current = zero_anim.previous =
                        zero_anim.next = ZERO_ACT_BEAM_END;
                }
                dsPlay_timer(773, (int)work, 1, 0, 4);
            }
            break;
        case ZERO_ACT_BEAM_END:
            if (--((struct zero_vars *)&(work)->vars)->timer <= 1) {
                zero_anim.action = ZERO_ACT_STAND;
                break;
            }
            zero_anim.frame = ((struct zero_vars *)&(work)->vars)->timer;
            break;
        default:
            if (zero_locked == (1)) {
                ((struct zero_vars *)&(work)->vars)->timer = 180;
                zero_anim.action = ZERO_ACT_WIND_UP;
                work->mode = ZERO_WIND_UP;
                zero_hand_state = ZERO_HAND_READY;
            } else {
                work->mode = ZERO_FALL;
            }
            break;
        }
        if (CalcDistance(&work->pos, &amy->pos) > 40.0F) {
            if ((((work)->scl).x += 0.04F) > 0.625F) {
                ((work)->scl).x = 1.25F;
            }
        } else if ((((work)->scl).x += -0.1F) < 0.0F) {
            ((work)->scl).x = 0.0F;
        }
        zero_fall(task);
        zero_move(task);
        zero_collide(task);
        if (zero_amy_distance2(&work->pos) > 150.0F * 150.0F ||
            amy->pos.y - work->pos.y > 20.0F ||
            FUN_8c0ddd26(0) == (1)) {
            zero_locked = (0);
            work->mode = ZERO_FALL;
            break;
        }
        break;
    case ZERO_WIND_UP:
        if (action == ZERO_ACT_THROW && frame >= 16.0F) {
            if (zero_locked == (1) && !zero_hand_launch(task)) {
                dsPlay_oneshot_v(763, 0, 0, 50, work->pos.x, work->pos.y,
                              work->pos.z);
                ((struct zero_vars *)&(work)->vars)->timer = 60;
                work->mode = ZERO_THROW;
                break;
            }
            work->mode = ZERO_FALL;
            break;
        }
        if (zero_locked == (1) &&
            zero_amy_distance2(&work->pos) > 200.0F * 200.0F) {
            zero_locked = (0);
        }
        break;
    case ZERO_THROW:
        if (--((struct zero_vars *)&(work)->vars)->timer <= 0) {
            zero_locked = (0);
            ((struct zero_vars *)&(work)->vars)->timer = 180;
            work->mode = ZERO_REEL;
            break;
        }
        if (zero_locked == (1) &&
            zero_amy_distance2(&work->pos) > 200.0F * 200.0F) {
            zero_locked = (0);
            break;
        }
        switch (zero_hand_fly(task)) {
        case ZERO_HAND_FLYING:
            break;
        case ZERO_HAND_UNTHROWN:
        case ZERO_HAND_CAUGHT:
        case ZERO_HAND_MISSED:
        case ZERO_HAND_BACK:
            zero_locked = (0);
            dsStop_id((int)work);
            dsPlay_iloop(761, (int)work, 1, 0);
            ((struct zero_vars *)&(work)->vars)->timer = 180;
            work->mode = ZERO_REEL;
            break;
        }
        break;
    case ZERO_REEL:
        switch (FUN_8c1064c0(task)) {
        case ZERO_HAND_HOME:
            dsStop_id((int)work);
            work->mode = ZERO_FALL;
            break;
        }
        break;
    case ZERO_HIT_FRONT:
    case ZERO_HIT_BEHIND:
        if (action == ZERO_ACT_STAND) {
            work->mode = ZERO_FALL;
            break;
        }
        zero_fall(task);
        zero_move(task);
        zero_collide(task);
        if (!(work->flags & 0x1)) {
            break;
        }
        ((work)->scl).x *= 0.9F;
        ((work)->scl).z *= 0.9F;
        if (zero_anim.action == ZERO_ACT_HIT_BEHIND ||
            zero_anim.action == ZERO_ACT_HIT_FRONT) {
            point = work->pos;
            point.x += (0.5F - (rand() * (1.0F / (32767 + 1)))) * 16.0F;
            point.y -= 8.0F;
            point.z += (0.5F - (rand() * (1.0F / (32767 + 1)))) * 16.0F;
            vector.x = vector.y = vector.z = 0.0F;
            CreateSmoke(&point, &vector, 1.0F);
        }
        if (zero_anim.action == ZERO_ACT_HIT_BEHIND_LAND ||
            zero_anim.action == ZERO_ACT_HIT_FRONT_LAND) {
            if (zero_anim.frame < 1.0F) {
                dsPlay_oneshot_v(775, 0, 0, 50, work->pos.x, work->pos.y,
                              work->pos.z);
            }
        }
        if (njScalor(&((work)->scl)) > 0.5F) {
            dsPlay_oneshot_v(764, 0, 0, 50, work->pos.x, work->pos.y,
                          work->pos.z);
            vibration_start(0, 4, 15, 0);
        }
        break;
    case ZERO_STOMP:
        if (action == ZERO_ACT_STAND) {
            work->mode = ZERO_FALL;
            break;
        }
        if (action == ZERO_ACT_STOMP && frame >= 8.0F &&
            frame < 8.0F + 1.0F) {
            if ((child = CreateElementalTask(0x2, 6, zero_shock_step)) != ((void *)0)) {
                child->work->pos = work->pos;
                child->work->pos.x += -(njCos(work->ang.y) * 15.0F);
                child->work->pos.z += njSin(work->ang.y) * 15.0F;
                child->work->pos.y += -12.0F;
            }
            dsPlay_oneshot_v(762, 0, 0, 50, work->pos.x, work->pos.y,
                          work->pos.z);
            dsPlay_oneshot_v(710, 0, 0, 50, work->pos.x, work->pos.y,
                          work->pos.z);
        }
        break;
    case ZERO_LEAVE:
        zero_locked = (0);
        if ((((work)->scl).y += 0.2F) > 4.0F) {
            ((work)->scl).y = 4.0F;
        }
        zero_move(task);
        point.x = 0.5F - (rand() * (1.0F / (32767 + 1)));
        point.y = -(rand() * (0.5F * (1.0F / (32767 + 1))));
        point.z = 0.5F - (rand() * (1.0F / (32767 + 1)));
        CreateSmoke(&work->pos, &point, 1.0F);
        if (--((struct zero_vars *)&(work)->vars)->timer <= 0) {
            dsStop_id((int)work);
            zero_kill();
            return;
        }
        break;
    }
    switch (work->mode) {
    case ZERO_AIM:
    case ZERO_BEAM:
        dx = amy->pos.x - work->pos.x;
        dz = amy->pos.z - work->pos.z;
        work->ang.y = AdjustAngle(
            work->ang.y, (Angle)(njArcTan2(dz, -dx) * (65536.0 / (2 * 3.141592))), 0x400);
        break;
    case ZERO_WIND_UP:
    case ZERO_THROW:
        (void)zero_lock_pos.y;
        lock_x = zero_lock_pos.x - work->pos.x;
        lock_z = zero_lock_pos.z - work->pos.z;
        work->ang.y = AdjustAngle(
            work->ang.y, (Angle)(njArcTan2(lock_z, -lock_x) * (65536.0 / (2 * 3.141592))),
            0x400);
        break;
    }
    EntryColliList(work);
    player_anim_step(&zero_anim);
    covered = (0);
    do {
        point = amy->collision->shapes->center;
        vector = work->pos;
        vector.y += 2.0F;
        amy_depth = CalcDistance(&camera_twp->pos, &point);
        if ((zero_depth = CalcDistance(&camera_twp->pos, &vector)) < 10.0F) {
            covered = (1);
            break;
        }
        if (amy_depth > zero_depth) {
            njProjectScreen(((void *)0), &point, &amy_screen);
            njProjectScreen(((void *)0), &vector, &zero_screen);
            amy_radius = _nj_screen_.dist * 5.0F / amy_depth;
            zero_radius = _nj_screen_.dist * 10.0F / zero_depth;
            sx = amy_screen.x - zero_screen.x;
            sy = amy_screen.y - zero_screen.y;
            gap = njSqrt((sx * sx) + (sy * sy));
            if (gap < amy_radius + zero_radius) {
                covered = (1);
            }
        }
    } while (0);
    target_alpha = 1.0F;
    if (covered == (1)) {
        target_alpha = 0.15F;
    }
    if ((((struct zero_vars *)&(work)->vars)->shade.alpha) < target_alpha) {
        if (((((struct zero_vars *)&(work)->vars)->shade.alpha) += 0.05F) > 1.0F) {
            (((struct zero_vars *)&(work)->vars)->shade.alpha) = 1.0F;
        }
    } else if ((((struct zero_vars *)&(work)->vars)->shade.alpha) > target_alpha) {
        if (((((struct zero_vars *)&(work)->vars)->shade.alpha) -= 0.05F) < 0.0F) {
            (((struct zero_vars *)&(work)->vars)->shade.alpha) = 0.0F;
        }
    }
    FUN_8c104cfc(task);
    shadow_draw(work, 1.8F);
    if (work->mode != ZERO_HIT_BEHIND && work->mode != ZERO_HIT_FRONT &&
        zero_damage == 1.0F && rand() * (1.0F / (32767 + 1)) < 0.05F) {
        point = work->pos;
        point.x += (0.5F - (rand() * (1.0F / (32767 + 1)))) * 10.0F;
        point.y += 15.0F;
        point.z += (0.5F - (rand() * (1.0F / (32767 + 1)))) * 10.0F;
        vector.x = 0.5F - (rand() * (1.0F / (32767 + 1)));
        vector.y = 0.5F;
        vector.z = 0.5F - (rand() * (1.0F / (32767 + 1)));
        snow_create(&point, &vector, 0.005F);
    }
    alpha = (((struct zero_vars *)&(work)->vars)->shade.alpha);
    (((struct zero_vars *)&(work)->vars)->shade.alpha) = 1.0F;
    LoopTaskC(task);
    (((struct zero_vars *)&(work)->vars)->shade.alpha) = alpha;
    zero_clear_request();
}
#else
void FUN_8c1031ec(struct task *task)
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
    asm_stub[0] = 112; asm_stub[1] = 113; asm_stub[2] = 114; asm_stub[3] = 115; asm_stub[4] = 116; asm_stub[5] = 117; asm_stub[6] = 118; asm_stub[7] = 119;
    asm_stub[0] = 120; asm_stub[1] = 121; asm_stub[2] = 122; asm_stub[3] = 123; asm_stub[4] = 124; asm_stub[5] = 125; asm_stub[6] = 126; asm_stub[7] = 127;
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c104508(struct task *task)
{
}
#else
void FUN_8c104508(struct task *task)
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
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void zero_collide(struct task *task)
{
    struct task_work *work = task->work;
    struct sides_query hits;
    Float y;
    zero_find_sides(&hits, &work->pos, 12.0F);
    work->flags &= ~0x100;
    if (hits.sides[SIDE_MINUS_X].found == (1) &&
        work->pos.x - hits.sides[SIDE_MINUS_X].level < 12.0F) {
        work->pos.x = hits.sides[SIDE_MINUS_X].level + 12.0F;
        work->flags |= 0x100;
    }
    if (hits.sides[SIDE_PLUS_X].found == (1) &&
        hits.sides[SIDE_PLUS_X].level - work->pos.x < 12.0F) {
        work->pos.x = hits.sides[SIDE_PLUS_X].level - 12.0F;
        work->flags |= 0x100;
    }
    if (hits.sides[SIDE_MINUS_Z].found == (1) &&
        work->pos.z - hits.sides[SIDE_MINUS_Z].level < 12.0F) {
        work->pos.z = hits.sides[SIDE_MINUS_Z].level + 12.0F;
        work->flags |= 0x100;
    }
    if (hits.sides[SIDE_PLUS_Z].found == (1) &&
        hits.sides[SIDE_PLUS_Z].level - work->pos.z < 12.0F) {
        work->pos.z = hits.sides[SIDE_PLUS_Z].level - 12.0F;
        work->flags |= 0x100;
    }
    work->flags &= ~0x1;
    if (hits.sides[SIDE_BELOW].found == (1) &&
        work->pos.y - hits.sides[SIDE_BELOW].level < 12.0F) {
        y = work->pos.y;
        work->pos.y = hits.sides[SIDE_BELOW].level + 12.0F;
        work->flags |= 0x1;
        if (work->pos.y - y > 3.0F) {
            ((work)->scl).y = 1.0F;
        } else {
            ((work)->scl).y *= -0.5F;
        }
    }
    if (hits.sides[SIDE_ABOVE].found == (1) &&
        hits.sides[SIDE_ABOVE].level - work->pos.y < 12.0F) {
        work->pos.y = hits.sides[SIDE_ABOVE].level - 12.0F;
        ((work)->scl).y = 0.0F;
    }
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c1048b8(struct task *task)
{
    struct task_work *work = task->work;
    struct sides_query hits;
    struct surface *side;
    struct world_object *object;
    struct collision_work *hit;
    Uint16 kind;
    const char *axis;
    int count;
    int i;
    switch (work->mode) {
    case SIGHT_START:
        CCL_Init(task, zero_sight_shape, 4, 1, 1);
        ((struct zero_sight_vars *)&(work)->vars)->travel = 0.0F;
        work->mode = SIGHT_FLY;
        break;
    case SIGHT_FLY:
        if ((((struct zero_sight_vars *)&(work)->vars)->travel += 5.0F) >= 150.0F) {
            zero_sight_saw = (0);
            zero_sight_out = (0);
            FreeTask(task);
            return;
        }
        if ((hit = work->collision->hit) != ((void *)0)) {
            if (!(kind = hit->kind)) {
                zero_sight_saw = (1);
                zero_sight_out = (0);
                FreeTask(task);
                return;
            }
            if (kind >= 4 && kind <= 7) {
                zero_sight_saw = (0);
                zero_sight_out = (0);
                FreeTask(task);
                return;
            }
        }
        ListGroundForCollision(work->pos.x, work->pos.y, work->pos.z, 5.0F);
        hits.pos = work->pos;
        for (count = LandCollList, object = numLandCollList; count > 0;
             count--, object++) {
            if (polygon_find_sides(&hits, object->object, object->flags) ==
                (1)) {
                side = hits.sides;
                axis = (const char *)&work->pos;
                for (i = SIDES; i > 0; i--) {
                    if (side->found == (1) &&
                        ((Float)_builtin_fabsf((Float)(side->level - *(const Float *)axis))) < 5.0F) {
                        zero_sight_saw = (0);
                        zero_sight_out = (0);
                        FreeTask(task);
                        return;
                    }
                    side++;
                    if (i & 1) {
                        axis += sizeof(Float);
                    }
                }
            }
        }
        ((&work->pos)->x += (&work->scl)->x, (&work->pos)->y += (&work->scl)->y, (&work->pos)->z += (&work->scl)->z);
        EntryColliList(work);
        break;
    }
}
#else
void FUN_8c1048b8(struct task *task)
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
    asm_stub[0] = 88; asm_stub[1] = 89;
}
#endif
Bool Eggrob_FindAmy(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VECTOR dir;
    NJS_POINT3 from;
    NJS_POINT3 target;
    NJS_VECTOR speed;
    Float distance;
    struct task *sight;
    if (FUN_8c0ddd26(0) == (1)) {
        return (0);
    }
    if (zero_request.blind == (1)) {
        return (0);
    }
    from = work->pos;
    target = playertwp[0]->pos;
    target.y += 5.0F;
    dir.x = target.x - from.x;
    dir.y = target.y - from.y;
    dir.z = target.z - from.z;
    if ((distance = njScalor(&dir)) == 0.0F) {
        dir.x = 1.0F;
        dir.y = dir.z = 0.0F;
    } else {
        njUnitVector(&dir);
    }
    if (zero_sight_out == (0) &&
        (sight = CreateElementalTask(0x2, 6, FUN_8c1048b8)) != ((void *)0)) {
        zero_sight_out = (1);
        speed = dir;
        speed.x *= 5.0F;
        speed.y *= 5.0F;
        speed.z *= 5.0F;
        sight->work->pos = from;
        sight->work->scl = speed;
    }
    if (distance > 150.0F) {
        return (0);
    }
    if (amy_get_action(0) == AMY_BALANCING) {
        return (0);
    }
    if (amy_get_action(0) == AMY_RECOILING) {
        return (1);
    }
    if (DiffAngle(work->ang.y,
                       (Angle)(njArcTan2(dir.z, -dir.x) * (65536.0 / (2 * 3.141592)))) >
        ((Angle)(((100) * 65536.0) / 360.0))) {
        return (0);
    }
    if (zero_sight_saw == (0)) {
        return (0);
    }
    return (1);
}
Float zero_distance2(NJS_POINT3 *from, NJS_POINT3 *to)
{
    NJS_VECTOR between;
    between = *to;
    njSubVector(&between, from);
    return njScalor2(&between);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
Float zero_amy_distance2(NJS_POINT3 *pos)
{
    NJS_POINT3 target;
    NJS_VECTOR away;
    target = playertwp[0]->pos;
    target.y += 5.0F;
    away.x = target.x - pos->x;
    away.y = target.y - pos->y;
    away.z = target.z - pos->z;
    return (away.x * away.x) + (away.y * away.y) + (away.z * away.z);
}
#else
Float zero_amy_distance2(NJS_POINT3 *pos)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    return asm_stub[0];
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c104cfc(struct task *task)
{
    struct task_work *work;
    struct player_action *entry;
    Float red;
    Float green;
    Float blue;
    if (loop_count != 0) {
        return;
    }
    work = task->work, zero_bob_object.evalflags |= 0x01;
    switch (zero_anim.action) {
    case ZERO_ACT_WALK:
    case ZERO_ACT_STAND:
        if (work->mode != ZERO_FALL) {
            zero_bob_object.evalflags &= ~0x01;
            zero_bob_object.pos[1] =
                njCos((Angle)((zero_anim.frame - 5.0F) * 4096.0F)) * 1.0F;
        }
        break;
    }
    njSetTexture(&zero_texlist);
    if (work->event != ((void *)0) && work->event->motions != ((void *)0)) {
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        event_motions_draw(work);
        njPopMatrix(1);
    } else {
        SaveConstantAttr();
        if ((((struct zero_vars *)&(work)->vars)->shade.alpha) < 1.0F) {
            OnConstantAttr(0, 0x00100000);
        }
        red = green = blue = 0.0F;
        if (zero_damage == 1.0F) {
            green = blue = -0.4F;
        }
        SetMaterial((((struct zero_vars *)&(work)->vars)->shade.alpha) - 1.0F, red, green, blue);
        njPushMatrix(((void *)0));
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        if (zero_anim.state == 2) {
            if (zero_damage == 1.0F) {
                njSimpleAction(zero_anim.blend, zero_anim.frame);
            } else {
                ds_ActionClip(zero_anim.blend, zero_anim.frame);
            }
        } else {
            entry = &zero_anim.actions[zero_anim.action];
            if (zero_damage == 1.0F) {
                njSimpleAction(entry->action, zero_anim.frame);
            } else {
                ds_ActionClip(entry->action, zero_anim.frame);
            }
        }
        njPopMatrix(1);
        LoadConstantAttr();
        SetMaterial(0.0F, 0.0F, 0.0F, 0.0F);
    }
}
#else
void FUN_8c104cfc(struct task *task)
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
    asm_stub[0] = 96;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c104ee4(void)
{
}
#else
void FUN_8c104ee4(void)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c104f76(struct task *task)
{
    struct task_work *work = task->work;
    struct player_anim *anim;
    NJS_ACTION *action;
    NJS_POINT3 *stride;
    Float falloff;
    Float length;
    {
        NJS_POINT3 pos;
        NJS_POINT3 point;
        njPushMatrix(&nj_unit_matrix_);
        pos.x = 4.5F;
        pos.y = -5.0F;
        pos.z = 0.0F;
        njTranslateV(((void *)0), &work->pos);
        ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
        anim = &zero_anim;
        if (anim->state == 2) {
            action = anim->blend;
        } else {
            action = zero_actions[anim->action].action;
        }
        CalcMMMatrix(((void *)0), action, anim->frame, 10, &zero_node_matrix);
        njCalcPoint(&zero_node_matrix, &pos, &point);
        zero_beam_points[0] = point;
        njPopMatrix(1);
        if ((zero_beam_length += 1.0F) > 150.0F) {
            zero_beam_length = 150.0F;
        }
        if (--zero_beam_turn_timer <= 0) {
            zero_beam_turn_timer = (int)(rand() * (17.0F * (1.0F / (32767 + 1)))) + 17;
            pos.x = playertwp[0]->pos.x - zero_beam_aim.x;
            pos.y = playertwp[0]->pos.y - zero_beam_aim.y + 5.0F;
            pos.z = playertwp[0]->pos.z - zero_beam_aim.z;
            if (njScalor(&pos) == 0.0F) {
                zero_beam_drift.x = zero_beam_drift.y = zero_beam_drift.z =
                    0.0F;
            } else {
                njUnitVector(&pos);
                zero_beam_drift = pos;
            }
        } else {
            if (zero_beam_aim.x < playertwp[0]->pos.x) {
                if ((zero_beam_drift.x += 0.01F) > 1.0F) {
                    zero_beam_drift.x = 1.0F;
                }
            } else {
                if ((zero_beam_drift.x -= 0.01F) < -1.0F) {
                    zero_beam_drift.x = -1.0F;
                }
            }
            if (zero_beam_aim.y < playertwp[0]->pos.y) {
                if ((zero_beam_drift.y += 0.01F) > 1.0F) {
                    zero_beam_drift.y = 1.0F;
                }
            } else {
                if ((zero_beam_drift.y -= 0.01F) < -1.0F) {
                    zero_beam_drift.y = -1.0F;
                }
            }
            if (zero_beam_aim.z < playertwp[0]->pos.z) {
                if ((zero_beam_drift.z += 0.01F) > 1.0F) {
                    zero_beam_drift.z = 1.0F;
                }
            } else {
                if ((zero_beam_drift.z -= 0.01F) < -1.0F) {
                    zero_beam_drift.z = -1.0F;
                }
            }
        }
        zero_beam_aim.x += zero_beam_drift.x;
        zero_beam_aim.y += zero_beam_drift.y;
        zero_beam_aim.z += zero_beam_drift.z;
    }
    zero_beam_dir.x = zero_beam_aim.x - zero_beam_points[0].x;
    zero_beam_dir.y = zero_beam_aim.y - zero_beam_points[0].y;
    zero_beam_dir.z = zero_beam_aim.z - zero_beam_points[0].z;
    if (njScalor(&zero_beam_dir) == 0.0F) {
        (&zero_beam_dir)->x = 1.0F;
        (&zero_beam_dir)->y = (&zero_beam_dir)->z = 0.0F;
    } else {
        njUnitVector(&zero_beam_dir);
    }
    zero_beam_end.x =
        (zero_beam_dir.x * zero_beam_length) + zero_beam_points[0].x;
    zero_beam_end.y =
        (zero_beam_dir.y * zero_beam_length) + zero_beam_points[0].y;
    zero_beam_end.z =
        (zero_beam_dir.z * zero_beam_length) + zero_beam_points[0].z;
    if (zero_beam_unblocked == (0)) {
        struct ray_query query;
        query.length = zero_beam_length;
        query.origin = zero_beam_points[0];
        query.dir = zero_beam_dir;
        if (polygon_cast_ray(&query) == (1)) {
            zero_beam_end = query.hit;
            if (zero_beam_hit == (1) &&
                zero_distance2(&zero_beam_end, &zero_beam_last_end) < 25.0F) {
                struct task *child;
                if ((child = CreateElementalTask(0x2, 6, FUN_8c105758)) !=
                    ((void *)0)) {
                    child->work->pos = zero_beam_end;
                    child->work->scl = zero_beam_last_end;
                }
            }
            zero_beam_hit = (1);
        } else {
            zero_beam_hit = (0);
        }
        zero_beam_points[1] = zero_beam_end;
    } else {
        zero_beam_hit = (0);
        zero_beam_points[1] = zero_beam_end;
    }
    falloff =
        1.0F - (CalcDistance(&zero_beam_points[0], &zero_beam_points[1]) *
                (1.0F / 150.0F));
    zero_beam_colors[1].argb.a = falloff * 255.0F;
    if (loop_count == 0) {
        njColorBlendingMode(0, 8);
        njColorBlendingMode(1, 10);
        njDrawLine3D(&zero_beam_line, 1, 0x00000040);
    }
    if (zero_beam_length > 1.0F) {
        struct task *child;
        if ((child = CreateElementalTask(0x2, 6, zero_sweep_step)) != ((void *)0)) {
            child->work->pos = zero_beam_points[0];
            child->work->scl = zero_beam_points[1];
            ((struct zero_sweep_vars *)&(child->work)->vars)->last_end.x = zero_beam_last_end.x;
            ((struct zero_sweep_vars *)&(child->work)->vars)->last_end.y = zero_beam_last_end.y;
            ((struct zero_sweep_vars *)&(child->work)->vars)->last_end.z = zero_beam_last_end.z;
            child->work->ang.x =
                (zero_beam_last_start.x - zero_beam_points[0].x) * 65536.0F;
            child->work->ang.y =
                (zero_beam_last_start.y - zero_beam_points[0].y) * 65536.0F;
            child->work->ang.z =
                (zero_beam_last_start.z - zero_beam_points[0].z) * 65536.0F;
        }
    }
    if (zero_locked == (0)) {
        NJS_POINT3 pos;
        NJS_POINT3 point;
        NJS_POINT3 target;
        length = CalcDistance(&zero_beam_points[0], &zero_beam_points[1]);
        pos = zero_beam_points[0];
        stride = &point;
        *stride = zero_beam_dir;
        stride->x = stride->x * 4.0F;
        stride->y = stride->y * 4.0F;
        stride->z = stride->z * 4.0F;
        target = playertwp[0]->pos;
        target.y += 5.0F;
        if (length > 0.0F) {
            do {
                if (zero_amy_distance2(&pos) < 4.0F * 4.0F) {
                    zero_locked = (1);
                    CreateElementalTask(0x2, 6, zero_marker_step);
                    dsPlay_oneshot(774, 0, 0, 0);
                    break;
                }
                length -= 4.0F;
                pos.x += stride->x;
                pos.y += stride->y;
                pos.z += stride->z;
            } while (length > 0.0F);
        }
    }
    zero_beam_last_start = zero_beam_points[0];
    (void)zero_beam_last_end.x;
    zero_beam_last_end = zero_beam_end;
}
#else
void FUN_8c104f76(struct task *task)
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
    asm_stub[0] = 112; asm_stub[1] = 113; asm_stub[2] = 114; asm_stub[3] = 115; asm_stub[4] = 116; asm_stub[5] = 117; asm_stub[6] = 118; asm_stub[7] = 119;
    asm_stub[0] = 120; asm_stub[1] = 121; asm_stub[2] = 122; asm_stub[3] = 123; asm_stub[4] = 124; asm_stub[5] = 125; asm_stub[6] = 126; asm_stub[7] = 127;
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c105590(struct task *task)
{
}
#else
void FUN_8c105590(struct task *task)
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
    asm_stub[0] = 88;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c105758(struct task *task)
{
    struct task_work *work = task->work;
    Float fade;
    if (++(*(Uint16 *)&(work)->timer) >= 45) {
        FreeTask(task);
        return;
    }
    if (loop_count != 0) {
        return;
    }
    fade = (45 - (*(Uint16 *)&(work)->timer)) * (1.0F / 45.0F);
    zero_scorch_colors[0].argb.a = fade * 255.0F;
    fade -= 1.0F / 45.0F;
    zero_scorch_colors[1].argb.a = fade * 255.0F;
    zero_scorch_points[0] = work->pos;
    zero_scorch_points[1] = work->scl;
    njDrawLine3D(&zero_scorch_line, 1, 0x00000040);
    CheckRangeOut(task);
}
#else
void FUN_8c105758(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void zero_marker_step(struct task *task)
{
    struct task_work *work = task->work;
    NJS_COLOR *color;
    int alpha;
    int red;
    int green;
    int blue;
    switch (work->mode) {
    case MARKER_START:
        work->scl.x = 100.0F;
        work->ang.x = 0;
        work->ang.y = ((Angle)(((120) * 65536.0) / 360.0));
        alpha = 255;
        red = 255;
        green = 255;
        blue = 0;
        work->mode = MARKER_LOCK;
        break;
    case MARKER_LOCK:
        if (!EV_CheckCansel()) {
            zero_lock_pos = playertwp[0]->pos;
            zero_lock_pos.y += 5.0F;
        }
        if ((work->scl.x *= 0.8F) < 8.0F) {
            work->scl.x = 8.0F;
        }
        work->ang.x += 0x200;
        work->ang.y += 0x200;
        green = work->ang.x >> 6;
        alpha = 160;
        red = 255;
        blue = 0;
        if (zero_hand_state == ZERO_HAND_READY) {
            work->scl.x = 10.0F;
            work->mode = MARKER_WIND_UP;
        }
        if (zero_locked == (0)) {
            work->scl.x = 8.0F;
            (*(Uint16 *)&(work)->timer) = 30;
            work->mode = MARKER_LOST;
        }
        break;
    case MARKER_WIND_UP:
        work->ang.x += 0x600;
        work->ang.y += 0x600;
        alpha = 160;
        red = 255;
        green = 0;
        blue = 0;
        if (zero_locked == (0)) {
            (*(Uint16 *)&(work)->timer) = 30;
            work->mode = MARKER_LOST;
        }
        break;
    case MARKER_LOST:
        if (--(*(Uint16 *)&(work)->timer) <= 0) {
            ((struct zero_marker_vars *)&(work)->vars)->grow = 1.0F;
            work->mode = MARKER_SWELL;
        }
        alpha = 160;
        green = red = 64;
        blue = 255;
        break;
    case MARKER_SWELL:
        ((struct zero_marker_vars *)&(work)->vars)->grow += -0.1F;
        alpha = 160;
        green = red = 64;
        blue = 255;
        if ((work->scl.x += ((struct zero_marker_vars *)&(work)->vars)->grow) < 0.01F) {
            FreeTask(task);
            return;
        }
        break;
    }
    if (loop_count != 0) {
        return;
    }
    for (color = zero_marker_colors; color < &zero_marker_colors[5]; color++) {
        color->argb.a = alpha;
        color->argb.r = red;
        color->argb.g = green;
        color->argb.b = blue;
    }
    njColorBlendingMode(0, 1);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &zero_lock_pos);
    ((work->ang.x) ? (njRotateX)(((void *)0), (work->ang.x)) : (void)0);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    njScale(((void *)0), work->scl.x, work->scl.x, work->scl.x);
    njDrawTriangle3D(&zero_marker_faces, 3,
                     0x00000040 | 0x00000002);
    njPopMatrix(1);
}
#else
void zero_marker_step(struct task *task)
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
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22;
}
#endif
void FUN_8c105abc(struct task *task)
{
    struct task_work *work = task->work;
    NJS_POINT3 pos;
    NJS_POINT3 point;
    NJS_ACTION *action;
    njPushMatrix(&nj_unit_matrix_);
    pos.x = 0.0F;
    pos.y = 0.0F;
    pos.z = 0.0F;
    njTranslateV(((void *)0), &work->pos);
    ((work->ang.y) ? (njRotateY)(((void *)0), (work->ang.y)) : (void)0);
    if (zero_anim.state == 2) {
        action = zero_anim.blend;
    } else {
        action = zero_actions[zero_anim.action].action;
    }
    CalcMMMatrix(((void *)0), action, zero_anim.frame, 30, &zero_node_matrix);
    njCalcPoint(&zero_node_matrix, &pos, &point);
    zero_arm_end = point;
    njPopMatrix(1);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c105b48(struct task *task)
{
}
#else
void FUN_8c105b48(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50; asm_stub[3] = 51; asm_stub[4] = 52; asm_stub[5] = 53; asm_stub[6] = 54; asm_stub[7] = 55;
    asm_stub[0] = 56; asm_stub[1] = 57; asm_stub[2] = 58; asm_stub[3] = 59; asm_stub[4] = 60; asm_stub[5] = 61;
}
#endif
void zero_draw_link(NJS_POINT3 *from, NJS_POINT3 *to)
{
    NJS_VECTOR span;
    Float length;
    Float across;
    Angle ang_y;
    Angle ang_z;
    span.x = to->x - from->x;
    span.y = to->y - from->y;
    span.z = to->z - from->z;
    length = njScalor(&span);
    across = njSqrt((span.x * span.x) + (span.z * span.z));
    ang_y = (Angle)(njArcTan2(span.z, -span.x) * (65536.0 / (2 * 3.141592)));
    if (span.y < 0.0F) {
        if (across < 0.01F) {
            ang_z = ((Angle)(((90) * 65536.0) / 360.0));
        } else {
            ang_z = (Angle)(FUN_8c10cf48(across / length) * (65536.0 / (2 * 3.141592)));
        }
    } else {
        if (across < 0.01F) {
            ang_z = ((Angle)(((270) * 65536.0) / 360.0));
        } else {
            ang_z = -(Angle)(FUN_8c10cf48(across / length) * (65536.0 / (2 * 3.141592)));
        }
    }
    length *= 1.0F / 10.0F;
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), from);
    ((ang_y) ? (njRotateY)(((void *)0), (ang_y)) : (void)0);
    ((ang_z) ? (njRotateZ)(((void *)0), (ang_z)) : (void)0);
    njScale(((void *)0), length, 1.0F, 1.0F);
    njSetTexture(&zero_texlist);
    late_DrawObject(&zero_link_object);
    njPopMatrix(1);
}
void zero_draw_chain(void)
{
    NJS_POINT3 *point;
    NJS_POINT3 *next;
    int i;
    point = zero_chain;
    next = point + 1;
    for (i = 16; i > 1; i--, point++, next++) {
        zero_draw_link(point, next);
    }
    zero_draw_link(point, &zero_arm_end);
}
void FUN_8c105e88(void)
{
    NJS_OBJECT *objects[4];
    NJS_VECTOR dir;
    NJS_VECTOR speed;
    NJS_POINT3 pos;
    Float length;
    objects[0] = zero_hand_object;
    objects[1] = zero_claw1_object;
    objects[2] = zero_claw1_tip_object;
    objects[3] = zero_claw0_object;
    objects[0]->evalflags &= ~0x08;
    objects[1]->evalflags &= ~0x08;
    objects[2]->evalflags &= ~0x08;
    objects[3]->evalflags &= ~0x08;
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &zero_hand_pos);
    ((zero_hand_ang_y) ? (njRotateY)(((void *)0), (zero_hand_ang_y)) : (void)0);
    njRotateX(((void *)0), ((Angle)(((180) * 65536.0) / 360.0)));
    ((zero_hand_pitch) ? (njRotateZ)(((void *)0), (zero_hand_pitch)) : (void)0);
    njSetTexture(&zero_texlist);
    late_DrawObject(objects[3]);
    njPopMatrix(1);
    objects[0]->evalflags |= 0x08;
    objects[1]->evalflags |= 0x08;
    objects[2]->evalflags |= 0x08;
    objects[3]->evalflags |= 0x08;
    speed.x = speed.y = speed.z = 0.0F;
    dir = zero_hand_speed;
    if ((length = njScalor(&dir)) == 0.0F) {
        dir.x = dir.y = dir.z = 0.0F;
    } else {
        njUnitVector(&dir);
    }
    dir.x *= -3.0F;
    dir.y *= -3.0F;
    dir.z *= -3.0F;
    pos = zero_hand_pos;
    while (length > 0.0F) {
        CreateSmoke(&pos, &dir, 1.0F);
        length -= 3.0F;
        njAddVector(&pos, &dir);
    }
}
void zero_keep_clear(NJS_POINT3 *pos, Float radius)
{
    struct sides_query hits;
    if (!zero_find_sides(&hits, pos, radius)) {
        return;
    }
    if (hits.sides[SIDE_MINUS_X].found == (1) &&
        pos->x - hits.sides[SIDE_MINUS_X].level < radius) {
        pos->x = hits.sides[SIDE_MINUS_X].level + radius;
    }
    if (hits.sides[SIDE_PLUS_X].found == (1) &&
        hits.sides[SIDE_PLUS_X].level - pos->x < radius) {
        pos->x = hits.sides[SIDE_PLUS_X].level - radius;
    }
    if (hits.sides[SIDE_MINUS_Z].found == (1) &&
        pos->z - hits.sides[SIDE_MINUS_Z].level < radius) {
        pos->z = hits.sides[SIDE_MINUS_Z].level + radius;
    }
    if (hits.sides[SIDE_PLUS_Z].found == (1) &&
        hits.sides[SIDE_PLUS_Z].level - pos->z < radius) {
        pos->z = hits.sides[SIDE_PLUS_Z].level - radius;
    }
    if (hits.sides[SIDE_BELOW].found == (1) &&
        pos->y - hits.sides[SIDE_BELOW].level < radius) {
        pos->y = hits.sides[SIDE_BELOW].level + radius;
    }
    if (hits.sides[SIDE_ABOVE].found == (1) &&
        hits.sides[SIDE_ABOVE].level - pos->y < radius) {
        pos->y = hits.sides[SIDE_ABOVE].level - radius;
    }
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c10616c(struct task *task)
{
}
#else
void FUN_8c10616c(struct task *task)
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
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
int FUN_8c1064c0(struct task *task)
{
    struct task_work *work = task->work;
    NJS_VECTOR dir;
    NJS_VECTOR target;
    NJS_OBJECT *objects[4];
    Float distance;
    int i;
    objects[0] = zero_hand_object;
    objects[1] = zero_claw1_object;
    objects[2] = zero_claw1_tip_object;
    objects[3] = zero_claw0_object;
    FUN_8c105abc(task);
    distance = zero_distance2(&zero_arm_end, &zero_hand_pos);
    dir = zero_hand_speed;
    if (njScalor(&dir) == 0.0F) {
        (&dir)->x = 1.0F;
        (&dir)->y = (&dir)->z = 0.0F;
    } else {
        njUnitVector(&dir);
    }
    target.x = zero_arm_end.x - zero_hand_pos.x;
    target.y = zero_arm_end.y - zero_hand_pos.y;
    target.z = zero_arm_end.z - zero_hand_pos.z;
    if (njScalor(&target) == 0.0F) {
        target = dir;
    } else {
        njUnitVector(&target);
    }
    zero_hand_speed.x = (dir.x * 0.825F) + (target.x * 0.175F);
    zero_hand_speed.y = (dir.y * 0.825F) + (target.y * 0.175F);
    zero_hand_speed.z = (dir.z * 0.825F) + (target.z * 0.175F);
    if (njScalor(&zero_hand_speed) == 0.0F) {
        zero_hand_speed = target;
    } else {
        njUnitVector(&zero_hand_speed);
    }
    if (distance > 30.0F * 30.0F) {
        zero_hand_speed.x *= 4.0F;
        zero_hand_speed.y *= 4.0F;
        zero_hand_speed.z *= 4.0F;
    } else {
        zero_hand_speed.x *= 1.0F;
        zero_hand_speed.y *= 1.0F;
        zero_hand_speed.z *= 1.0F;
    }
    njAddVector(&zero_hand_pos, &zero_hand_speed);
    zero_keep_clear(&zero_hand_pos, 8.0F);
    work->collision->shapes[1].center = zero_hand_pos;
    if (--((struct zero_vars *)&(work)->vars)->timer <= 0 || distance < 1.5F * 1.5F) {
        objects[0]->evalflags &= ~0x08;
        objects[1]->evalflags &= ~0x08;
        objects[2]->evalflags &= ~0x08;
        objects[3]->evalflags &= ~0x08;
        work->collision->shapes[1].flags |= 0x10;
        dsStop_id((int)work);
        return zero_hand_state = ZERO_HAND_HOME;
    }
    for (i = 16 - 1; i > 0; i--) {
        zero_chain[i].x =
            (zero_chain[i - 1].x * 0.85F) + (zero_arm_end.x * 0.15F);
        zero_chain[i].y =
            (zero_chain[i - 1].y * 0.85F) + (zero_arm_end.y * 0.15F);
        zero_chain[i].z =
            (zero_chain[i - 1].z * 0.85F) + (zero_arm_end.z * 0.15F);
    }
    zero_chain[0] = zero_hand_pos;
    zero_draw_chain();
    if (distance < 30.0F * 30.0F) {
        zero_hand_ang_y = AdjustAngle(zero_hand_ang_y,
                                         work->ang.y + ((Angle)(((180) * 65536.0) / 360.0)), 0x400);
        zero_hand_pitch = AdjustAngle(zero_hand_pitch, 0, 0x400);
    }
    FUN_8c105e88();
    return zero_hand_state = ZERO_HAND_BACK;
}
#else
int FUN_8c1064c0(struct task *task)
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
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50;
    return asm_stub[0];
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c1067de(struct task *task)
{
}
#else
void FUN_8c1067de(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c1068cc(struct task *task)
{
}
#else
void FUN_8c1068cc(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c106978(struct task *task)
{
    struct task_work *work = task->work;
    if (++(*(Uint16 *)&(work)->timer) >= 60) {
        FreeTask(task);
        return;
    }
    if (loop_count != 0) {
        return;
    }
    if (++((struct zero_mark_vars *)&(work)->vars)->frame >= 3) {
        ((struct zero_mark_vars *)&(work)->vars)->frame = 0;
    }
    njColorBlendingMode(0, 8);
    njColorBlendingMode(1, 6);
    njPushMatrix(((void *)0));
    njTranslateV(((void *)0), &work->pos);
    njSetTexture(&zero_texlist);
    njDrawSprite3D(&zero_hatena_sprite, ((struct zero_mark_vars *)&(work)->vars)->frame,
                   0x10 | 0x20);
    njPopMatrix(1);
}
#else
void FUN_8c106978(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38; asm_stub[7] = 39;
    asm_stub[0] = 40; asm_stub[1] = 41; asm_stub[2] = 42; asm_stub[3] = 43; asm_stub[4] = 44; asm_stub[5] = 45; asm_stub[6] = 46; asm_stub[7] = 47;
    asm_stub[0] = 48; asm_stub[1] = 49; asm_stub[2] = 50;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c106a7e(struct task *task)
{
}
#else
void FUN_8c106a7e(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c106b0a(struct task *task)
{
}
#else
void FUN_8c106b0a(struct task *task)
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
    asm_stub[0] = 80; asm_stub[1] = 81; asm_stub[2] = 82; asm_stub[3] = 83;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c106cd6(struct task *task)
{
    struct task_work *work = task->work;
    switch (work->mode) {
    case ZERO_WIND_UP:
        if (zero_anim.action == ZERO_ACT_THROW &&
            zero_anim.frame >= 16.0F) {
            if (zero_locked == (1) && !zero_hand_launch(task)) {
                ((struct zero_vars *)&(work)->vars)->timer = 60;
                work->mode = ZERO_THROW;
                break;
            }
        }
        break;
    case ZERO_THROW:
        if (--((struct zero_vars *)&(work)->vars)->timer <= 0) {
            zero_locked = (0);
            ((struct zero_vars *)&(work)->vars)->timer = 180;
            work->mode = ZERO_REEL;
            break;
        }
        switch (zero_hand_fly(task)) {
        case ZERO_HAND_FLYING:
            break;
        case ZERO_HAND_UNTHROWN:
        case ZERO_HAND_CAUGHT:
        case ZERO_HAND_MISSED:
        case ZERO_HAND_BACK:
            zero_locked = (0);
            ((struct zero_vars *)&(work)->vars)->timer = 180;
            work->mode = ZERO_REEL;
        }
        break;
    case ZERO_REEL:
        if (FUN_8c1064c0(task) == ZERO_HAND_HOME) {
            work->mode = ZERO_FALL;
            zero_anim.action = ZERO_ACT_STAND;
            task->step = zero_event_step;
        }
        break;
    }
    player_anim_step(&zero_anim);
    (((struct zero_vars *)&(work)->vars)->shade.alpha) = 1.0F;
    FUN_8c104cfc(task);
    shadow_draw(work, 1.8F);
}
#else
void FUN_8c106cd6(struct task *task)
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
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c106e0c(struct task *task)
{
    struct task_work *work = task->work;
    zero_locked = (1);
    zero_lock_pos = zero_event_grab_pos;
    CreateElementalTask(0x2, 6, zero_marker_step);
    ((struct zero_vars *)&(work)->vars)->timer = 180;
    zero_anim.action = ZERO_ACT_WIND_UP;
    work->mode = ZERO_WIND_UP;
    player_anim_step(&zero_anim);
    (((struct zero_vars *)&(work)->vars)->shade.alpha) = 1.0F;
    FUN_8c104cfc(task);
    shadow_draw(work, 1.8F);
    task->step = FUN_8c106cd6;
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void zero_show_hatena(struct task *task)
{
}
#else
void zero_show_hatena(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void FUN_8c106ec4(NJS_POINT3 *pos)
{
    struct task *task;
    if ((task = CreateElementalTask(0x2, 6, zero_hirame_step)) != ((void *)0)) {
        task->work->pos = *pos;
        ((struct zero_mark_vars *)&(task->work)->vars)->follow = ((void *)0);
    }
}
#else
void FUN_8c106ec4(NJS_POINT3 *pos)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
}
#endif
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void EggrobForEvent0(struct task *task)
{
    struct task_work *work = task->work;
    CCL_Init(task, zero_shapes, 2, 1, 2);
    SetEventWork(work);
    player_init(((struct zero_vars *)&(work)->vars)->player, task);
    texLoadTexturePvmFile("EGGROB", &zero_texlist);
    ((work)->scl).z = 0.0F;
    ((work)->scl).y = 0.0F;
    ((work)->scl).x = 0.0F;
    zero_damage = 0.0F;
    zero_anim.state = 0;
    zero_anim.actions = zero_actions;
    zero_anim.action = zero_anim.current = ZERO_ACT_STAND;
    zero_anim.pace = &zero_hit_pace;
    zero_neck_object[0].ang[1] = 0;
    zero_head_object[0].ang[2] = ((Angle)(((180) * 65536.0) / 360.0));
    zero_sight_out = (0);
    zero_sight_saw = (0);
    work->collision->shapes[1].flags |= 0x10;
    zero_restless = 0.0F;
    ((struct zero_vars *)&(work)->vars)->timer = 180;
    work->mode = ZERO_FALL;
    FUN_8c104ee4();
    zero_event_grab_state = ZERO_GRAB_NONE;
    task->destructor = zero_event_destroy;
    task->step = zero_event_step;
}
#else
void EggrobForEvent0(struct task *task)
{
    volatile int asm_stub[8];     /* (as long as the original function, no pool: the build uses the original's bytes) */
    asm_stub[0] = 0; asm_stub[1] = 1; asm_stub[2] = 2; asm_stub[3] = 3; asm_stub[4] = 4; asm_stub[5] = 5; asm_stub[6] = 6; asm_stub[7] = 7;
    asm_stub[0] = 8; asm_stub[1] = 9; asm_stub[2] = 10; asm_stub[3] = 11; asm_stub[4] = 12; asm_stub[5] = 13; asm_stub[6] = 14; asm_stub[7] = 15;
    asm_stub[0] = 16; asm_stub[1] = 17; asm_stub[2] = 18; asm_stub[3] = 19; asm_stub[4] = 20; asm_stub[5] = 21; asm_stub[6] = 22; asm_stub[7] = 23;
    asm_stub[0] = 24; asm_stub[1] = 25; asm_stub[2] = 26; asm_stub[3] = 27; asm_stub[4] = 28; asm_stub[5] = 29; asm_stub[6] = 30; asm_stub[7] = 31;
    asm_stub[0] = 32; asm_stub[1] = 33; asm_stub[2] = 34; asm_stub[3] = 35; asm_stub[4] = 36; asm_stub[5] = 37; asm_stub[6] = 38;
}
#endif
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void zero_event_destroy(struct task *task)
{
    zero_neck_object[0].ang[1] = 0;
    zero_head_object[0].ang[2] = ((Angle)(((180) * 65536.0) / 360.0));
    zero_hand_object[0].evalflags &= ~0x08;
    zero_claw1_object[0].evalflags &= ~0x08;
    zero_claw1_tip_object[0].evalflags &= ~0x08;
    zero_claw0_object[0].evalflags &= ~0x08;
    PDestruct(((struct zero_vars *)&(task->work)->vars)->player);
}
/* asm: register allocation not reproduced */
#ifdef NON_MATCHING
void zero_event_step(struct task *task)
{
    struct task_work *work = task->work;
    struct event_work *event = work->event;
    NJS_POINT3 delta;
    Angle heading;
    Float distance;
    Float angle_scale;
    Float speed;
    Float accel;
    struct task *target;
    if (event == ((void *)0)) {
        FreeTask(task);
        return;
    }
    if (zero_event_grab_state == ZERO_GRAB_ASKED) {
        task->step = FUN_8c106e0c;
        zero_event_grab_state = ZERO_GRAB_STARTED;
        return;
    }
    if (work->event->paths != ((void *)0)) {
        work->mode = ZERO_EVENT;
    } else if (event->look != EVENT_LOOK_NONE) {
        switch (event->look) {
        case EVENT_LOOK_ANGLES:
        case EVENT_LOOK_POINT:
        case EVENT_LOOK_TASK:
            work->mode = ZERO_EVENT;
            break;
        case EVENT_LOOK_NONE:
        default:
            work->mode = ZERO_FALL;
            break;
        }
    } else {
        switch (event->action) {
        case EVENT_ACTION_RUN:
        case EVENT_ACTION_MOVE:
        case EVENT_ACTION_PUSH:
        case EVENT_ACTION_TURN_BY:
        case EVENT_ACTION_TURN_TO:
            work->mode = ZERO_EVENT;
            break;
        case EVENT_ACTION_NONE:
        case EVENT_ACTION_DONE:
        default:
            work->mode = ZERO_FALL;
            break;
        }
        if (event->action != EVENT_ACTION_TURN_BY &&
            event->action != EVENT_ACTION_TURN_TO) {
            (((struct zero_vars *)&(work)->vars)->shade.turn[1]) = PHASE_AIM;
        }
    }
    switch (work->mode) {
    case ZERO_FALL:
        zero_fall(task);
        zero_move(task);
        zero_collide(task);
        if ((work->flags & 0x1) && ((Float)_builtin_fabsf((Float)(((work)->scl).y))) < 0.1F) {
            work->mode = ZERO_STILL;
        }
        break;
    case ZERO_STILL:
        ((work)->scl).z = 0.0F;
        ((work)->scl).y = 0.0F;
        ((work)->scl).x = 0.0F;
        break;
    case ZERO_EVENT:
        if (work->event->paths != ((void *)0)) {
            ExecEventPath(work);
            break;
        }
        angle_scale = (65536.0 / (2 * 3.141592));
        if (event->look != EVENT_LOOK_NONE) {
            switch (event->look) {
            case EVENT_LOOK_ANGLES:
                work->ang.y =
                    AdjustAngle(work->ang.y, event->look_ang.y, 0x400);
                break;
            case EVENT_LOOK_POINT:
                delta = event->look_pos;
                delta.y = 0.0F;
                njSubVector(&delta, &work->pos);
                work->ang.y = AdjustAngle(
                    work->ang.y,
                    (Angle)(njArcTan2(delta.z, -delta.x) * angle_scale), 0x400);
                break;
            case EVENT_LOOK_TASK:
                target = event->look_task;
                if (target == ((void *)0) || target->work == ((void *)0)) {
                    break;
                }
                delta = target->work->pos;
                delta.y = 0.0F;
                njSubVector(&delta, &work->pos);
                work->ang.y = AdjustAngle(
                    work->ang.y,
                    (Angle)(njArcTan2(delta.z, -delta.x) * angle_scale), 0x400);
                break;
            }
            break;
        }
        switch (event->action) {
        case EVENT_ACTION_RUN:
            delta = event->move.pos;
            njSubVector(&delta, &work->pos);
            delta.y = 0.0F;
            if (njScalor(&delta) < 1.0F + (((Float)_builtin_fabsf((Float)(((work)->scl).x))) * 0.5F)) {
                break;
            }
            work->ang.y = AdjustAngle(
                work->ang.y, (Angle)(njArcTan2(delta.z, -delta.x) * angle_scale),
                0x400);
            speed = event->speed;
            accel = event->accel;
            if (speed == 0.0F && accel == 0.0F) {
                if ((((work)->scl).x += 0.04F) > 1.25F) {
                    ((work)->scl).x = 1.25F;
                }
            } else {
                if (speed == 0.0F) {
                    speed = ((work)->scl).x;
                }
                ((work)->scl).x = speed + accel;
            }
            zero_fall(task);
            zero_move(task);
            zero_collide(task);
            break;
        case EVENT_ACTION_MOVE:
            delta = event->move.pos;
            delta.y = 0.0F;
            if ((distance = njScalor(&delta)) < 0.01F) {
                break;
            }
            work->ang.y = AdjustAngle(
                work->ang.y, (Angle)(njArcTan2(delta.z, -delta.x) * angle_scale),
                0x400);
            if (((work)->scl).x + 0.04F < distance) {
                ((work)->scl).x += 0.04F;
            } else if (((work)->scl).x + -0.1F > distance) {
                ((work)->scl).x += -0.1F;
            } else {
                ((work)->scl).x = distance;
            }
            zero_fall(task);
            zero_move(task);
            zero_collide(task);
            break;
        case EVENT_ACTION_PUSH:
            break;
        case EVENT_ACTION_TURN_BY:
        case EVENT_ACTION_TURN_TO:
            switch ((((struct zero_vars *)&(work)->vars)->shade.turn[1])) {
            case PHASE_AIM:
                if (event->action == EVENT_ACTION_TURN_BY) {
                    ((work)->ang.x) = event->move.ang.y;
                } else {
                    ((work)->ang.x) =
                        angle_difference(work->ang.y, event->move.ang.y);
                }
                (((struct zero_vars *)&(work)->vars)->shade.turn[1]) = PHASE_HEAD;
                break;
            case PHASE_HEAD:
                ((work)->ang.z) =
                    AdjustAngle(((work)->ang.z), ((work)->ang.x), 0x800);
                zero_neck_object[0].ang[1] = ((work)->ang.z);
                if (((work)->ang.z) == ((work)->ang.x)) {
                    (((struct zero_vars *)&(work)->vars)->shade.turn[1]) = PHASE_BODY;
                }
                break;
            case PHASE_BODY:
                heading = AdjustAngle(((work)->ang.z), 0, 0x800);
                work->ang.y += angle_difference(heading, ((work)->ang.z));
                ((work)->ang.z) = heading;
                zero_neck_object[0].ang[1] = ((work)->ang.z);
                if (((work)->ang.z) == 0) {
                    (((struct zero_vars *)&(work)->vars)->shade.turn[1]) = PHASE_DONE;
                    break;
                }
                break;
            }
            break;
        }
        break;
    }
    EntryColliList(work);
    player_anim_step(&zero_anim);
    (((struct zero_vars *)&(work)->vars)->shade.alpha) = 1.0F;
    FUN_8c104cfc(task);
    shadow_draw(work, 1.8F);
}
#else
void zero_event_step(struct task *task)
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
    asm_stub[0] = 64; asm_stub[1] = 65;
}
#endif
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void zero_fall(struct task *task)
{
    if ((((task->work)->scl).y += -0.1F) < -3.0F) {
        ((task->work)->scl).y = -3.0F;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void zero_move(struct task *task)
{
    struct task_work *work = task->work;
    if (((Float)_builtin_fabsf((Float)(((work)->scl).x))) < 0.01F) {
        ((work)->scl).x = 0.0F;
    }
    if (((Float)_builtin_fabsf((Float)(((work)->scl).y))) < 0.01F) {
        ((work)->scl).y = 0.0F;
    }
    if (((Float)_builtin_fabsf((Float)(((work)->scl).z))) < 0.01F) {
        ((work)->scl).z = 0.0F;
    }
    work->pos.x -= ((work)->scl).x * njCos(work->ang.y);
    work->pos.z += ((work)->scl).x * njSin(work->ang.y);
    work->pos.y += ((work)->scl).y;
    njAddVector(&work->pos, &zero_request.push);
}
