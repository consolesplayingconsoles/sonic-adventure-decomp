/* @unit 8C01DDE0-8C025960 @data 8C1121D0-8C1122E4 +r04 +egflags +pool32  +poolafter=camera_preview_view,camera_boss_place_from_player,FUN_8c020440,camera_step_line,FUN_8c0212c4,cart_view_above,cart_ease_both,camera_step_two_hares,camera_pitch_ease,adjust_ease_aim,adjust_ease_trail,FUN_8c0242ee,gravDispose3,camera_step_follow,FUN_8c023212,FUN_8c01e6a6,camera_step_along_path,camera_step_trick_a +poolbra=FUN_8c01e15e:1,FUN_8c01effe:1,camera_step_pathcam:1,FUN_8c01f358:1,FUN_8c020140:6,FUN_8c024586:1,camera_step_e103:1,camera_adjust_ease:1,FUN_8c023c98:5,sonic_keep_distance:3,camera_step_follow:4,camera_step_follow:9,FUN_8c01e32a:2,FUN_8c01e508:2,camera_step_along_path:8,FUN_8c02070e:1 +brafpool=FUN_8c023960 +asmfunc=FUN_8c01fb98,FUN_8c022858,FUN_8c020b92,FUN_8c024b5c,camera_step_magonote,camera_step_chaos_p,FUN_8c020d60,FUN_8c021700,FUN_8c022640,FUN_8c022ae2,FUN_8c022d60,cart_play_keys,FUN_8c024768,FUN_8c024dca,FUN_8c025010,adjust_ease_follow,camera_step_chaos_std,AmyBalanceGameStartChecker:+8c01f9c0,camera_step_point:+8c020140,camera_step_ashland:+8c021160,at_path_end:+8c0218e0,path_track_point:+8c021ae0,FUN_8c021b60:+8c022580,FUN_8c0209a0:+8c020ae0 */
/* Ported from the Japanese release's src/camera/modes.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
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
Float FUN_8c63fec4(NJS_POINT3 *p, NJS_LINE *l, NJS_POINT3 *cp);
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
struct camera_view;
struct chaos7_shot {
    NJS_POINT3 from;
    NJS_POINT3 to;
    Float from_height;
    Float to_height;
    Float steps;
};
extern Sint8 chaos7_shot_done;
extern Sint8 chaos7_shot_held;
void chaos7_camera_entry(struct camera_view *view);
void chaos7_shot_start(struct chaos7_shot *shot);
void chaos7_camera_watch_step(struct camera_view *view);
enum e101_r_camera_mode {
    E101_R_CAMERA_FOLLOW,
    E101_R_CAMERA_COAST,
    E101_R_CAMERA_TURN,
    E101_R_CAMERA_TRACK,
    E101_R_CAMERA_BACK_OFF,
    E101_R_CAMERA_BEHIND,
    E101_R_CAMERA_ORBIT,
    E101_R_CAMERA_ORBIT_END
};
struct camera_view;
void e101_r_camera_step(struct camera_view *view);
void e101_r_camera_reset(void);
void e101_r_camera_start(NJS_POINT3 *boss);
void e101_r_camera_set_target_rise(Float rise);
void e101_r_camera_set_aim(Angle aim, Float speed);
void e101_r_camera_set_blast_size(Float size);
void e101_r_camera_set_wide(Bool wide);
void e101_r_camera_set_mode(int mode);
Angle e101_r_camera_get_turn(void);
Angle e101_r_camera_get_heading(void);
struct camera_view;
void eggmobile3_camera_step(struct camera_view *view);
void egg_viper_camera_reset(void);
void egg_viper_camera_shake(void);
Bool camera_move_at(NJS_POINT3 *pos, Float speed);
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
struct cameraControlWork {
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
extern struct cameraControlWork camera_state_record;
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
extern Bool CamPathCam2Core_AliveFlag;
extern NJS_POINT3 camera_pose_pos;
extern struct angles CamPathCam2Core_Angle;
extern struct task_work *camera_twp;
extern struct cameraControlWork *const cameraControlWork;
void InitCartGoalCamFunc(struct camera_view *view);
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
void FUN_8c01a680(struct task_work *work);
void camera_place_from_target(struct task_work *work);
void camera_add_offset(NJS_VECTOR *offset);
void camera_set_mode(Sint16 mode, Uint8 adjust);
void camera_override_mode(Sint16 mode, Uint8 adjust);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view), Uint8 adjust,
                     Sint8 type);
void CameraReleaseEventCamera(void);
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
int FUN_8c01b406(void);
int camera_get_mode(void);
Bool FUN_8c01b5e0(void);
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
void FUN_8c021700(struct camera_view *view);
void camera_step_trick_a(struct camera_view *view);
void FUN_8c01fb98(struct camera_view *view);
void AmyBalanceGameStartChecker(struct camera_view *view);
int FUN_8c01b782(NJS_POINT3 *a, NJS_POINT3 *b);
void camera_step_follow(struct camera_view *view);
void camera_step_work_view(struct camera_view *view);
void FUN_8c021b60(struct camera_view *view);
void camera_step_pose(struct camera_view *view);
void camera_start_path(struct path *path, int mode, Uint32 steps);
void FUN_8c020140(int unbounded);
void camera_boss_place_from_player(int below_only);
int FUN_8c020440(int from_anchor);
void camera_set_boss_limits(struct angles *step, struct angles *spin,
                            NJS_VECTOR *move);
void camera_start_swing(struct task_work *work, Float height, Float distance,
                        int swing_steps);
void camera_adjust_none(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust);
void FUN_8c024dca(struct task_work *work, struct task_work *last,
                          struct camera_adjust_work *adjust);
void FUN_8c025010(struct task_work *work, struct task_work *last,
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
extern struct camera_mode camera_mode_table[];
extern struct camera_layout camera_advertise_layout;
struct pathcam_key {
    Sint16 ang_y;
    Sint16 ang_x;
    Sint16 ang_z;
    Uint8 unk_06[2];
    NJS_POINT3 pos;
};
struct pathcam_path {
    Sint32 unk_00;
    Float length;
    struct pathcam_key *keys;
};
struct pathcam_route {
    Uint16 stage_act;
    Uint16 count;
    struct pathcam_path **paths;
};
extern struct pathcam_route pathcam_routes[];
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
struct chaos;
struct chaos_form;
struct weld;
struct task_work;
enum motion_mode {
    MOTION_START = 0,
    MOTION_CHANGE = 1,
    MOTION_BLENDING = 2,
    MOTION_LOOP = 3,
    MOTION_ONCE = 4,
    MOTION_BACKWARD = 6,
    MOTION_PACED = 9,
    MOTION_AT = 10,
    MOTION_STEP = 11,
    MOTION_POSED = 12,
    MOTION_FREE = 14,
    MOTION_HOLD = 15,
    MOTION_STILL = 16
};
struct motion_entry {
    NJS_ACTION *action;
    Uint8 nodes;
    Sint8 mode;
    Uint8 next;
    Float blend;
    Float speed;
};
struct motion {
    Float pace;
    Sint16 state;
    Sint16 weld_mode;
    Uint16 wanted;
    Uint16 current;
    Uint16 previous;
    Sint16 steps;
    Float frame;
    Uint8 unk_14[0xc];
    Float speed;
    Uint8 unk_24[8];
    struct motion_entry *actions;
    struct weld *welds;
    NJS_ACTION *blend;
};
struct boss_point {
    NJS_POINT3 pos;
    NJS_POINT3 last;
    NJS_VECTOR axis;
};
extern Sint8 motion_flags;
extern struct task_work *boss_work;
extern Sint8 boss_last_mode;
extern Sint8 boss_next_mode;
extern Sint8 boss_return_mode;
extern Sint32 boss_attack_checks;
extern Sint8 boss_repeats;
extern Sint8 boss_waiting;
extern Sint8 chaos_handed_over;
extern Uint8 dat_8c6c042b;
extern Sint8 chaos_current_form;
extern struct chaos *chaos_record;
extern struct chaos_form *chaos_params;
extern Float chaos_travel;
extern struct boss_point boss_points[32];
struct motion *motion_create(struct task_work *work, int size);
void motion_step(struct task_work *work, struct motion *motion);
void motion_weld(struct task_work *work, struct motion *motion);
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
enum path_ends { PATH_STOP, PATH_LOOP };
struct path_point {
    Sint16 ang_x;
    Sint16 ang_z;
    Float length;
    NJS_POINT3 pos;
};
struct path {
    Uint8 ends;
    Uint16 count;
    Float length;
    struct path_point *points;
    void (*step)(struct task *task);
};
struct path_list {
    Sint32 stage_act;
    struct path **paths;
};
extern struct path_list path_lists[];
extern struct path *practice_act2_paths[];
struct path_vars {
    Uint16 wait[2];
    Sint16 stage_act;
    struct path *path;
};
struct path_spline_point {
    Float length;
    NJS_POINT3 pos;
};
struct path_spline {
    Uint8 flags;
    Uint16 count;
    Float length;
    Float reach;
    Uint8 unk_0c[4];
    struct path_spline_point *points;
    struct path_spline_point *side;
};
struct GetStatusOnPath {
    Angle ang_x;
    Angle ang_z;
    Angle smooth_x;
    Angle smooth_z;
    Float distance;
    NJS_POINT3 pos_copy;
    NJS_POINT3 pos;
    NJS_VECTOR up;
    NJS_VECTOR smooth_up;
    NJS_VECTOR ahead;
};
void fun_8c08e0e0(void);
void path_run_cubic(void);
Bool path_create_manager(void);
Bool GetStatusOnPath(struct path *path, struct GetStatusOnPath *sample);
Bool path_find_segment(struct path *path, Float distance, Uint32 *index);
Bool path_get_distance(struct path *path, Uint32 index, Float *distance);
Float path_wrap(struct path *path, Float distance);
Float path_find_nearest(struct path *path, NJS_POINT3 *pos, NJS_POINT3 *nearest,
                        Float *along);
Bool path_spline_sample(struct path_spline *spline, struct GetStatusOnPath *sample);
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
Bool knuckles_take_piece(int id, NJS_POINT3 *pos);
Bool knuckles_mark_piece(int id, NJS_POINT3 *pos);
void knuckles_force_dig(int sound);
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
extern struct task_motion *playermwp[];
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
Bool GetPlayerPosition(Uint8 player, int steps, NJS_POINT3 *pos,
                        struct angles *ang);
extern Angle shooting_camera_ang_z;
void shooting_camera_watch(struct camera_view *view);
void shooting_camera_look_back(struct camera_view *view);
void shooting_camera_follow(struct camera_view *view);
void shooting_camera_swing(struct camera_view *view);
void shooting_camera_start(void);
void shooting_camera_set_spacing(int spacing);
void shooting_camera_swing_start(struct task_work *work, Float height,
                                 Float distance, int swing_steps);
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
void dsStop_num(int se);
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
extern struct segment_query scratch_segment_query;
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
void stage_clear(void);
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
extern PDS_PERIPHERAL perG[8];
extern PDS_PERIPHERAL *per[4];
extern Uint8 dat_8c75d910[20];
extern struct pad_stick pad_sticks[8];
extern struct pad_stick pad_sticks_read[8];
extern Uint32 pad_held[4];
extern Uint32 pad_press_repeat[4];
extern Uint32 pad_held_live[4];
extern Uint32 pad_press_live[4];
extern Bool pad_port_used[4];
extern int pad_ports[4];
void ufExitSystem(void);
void PadReadOff(void);
Bool pad_is_enabled(void);
void pad_enable_player(Uint8 player);
void pad_disable_player(Uint8 player);
Bool pad_player_is_enabled(Uint8 player);
Bool pad_quit_pressed(int unused);
void pad_scan(void);
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
Bool MSetPosition(NJS_POINT3 *pos, NJS_VECTOR *speed, struct angles *ang,
                         Float radius);
Bool world_sweep_ball_hit(NJS_POINT3 *pos, NJS_VECTOR *speed,
                          struct angles *ang, int skip, Float radius);
int string_vformat(char *buffer, const char *format, va_list args);
int string_format(char *buffer, const char *format, ...);
void vector_sum(NJS_VECTOR *a, NJS_VECTOR *b, NJS_VECTOR *out);
void vector_diff(NJS_VECTOR *a, NJS_VECTOR *b, NJS_VECTOR *out);
Float vector_dot_from(NJS_POINT3 *from, NJS_POINT3 *a, NJS_POINT3 *b);
Bool matrix_push_unit(void);
struct pathcam_vars {
    Uint8 path;
    Uint8 unk_01[3];
    Float place;
    struct pathcam_route *route;
};
struct path_play_vars {
    Uint8 mode;
    Uint8 unk_01;
    Uint16 point;
    Uint32 steps;
    struct path *path;
};
enum swing_phase { SWING_CLOSING, SWING_TURNING, SWING_ROUND };
struct adjust_ease {
    Bool sweeps;
    Float steps;
    int blend;
};
extern Float manual_distance;
extern struct path_point trick_a_points[56];
extern struct path trick_a_path;
extern struct path_point trick_b_points[80];
extern struct path trick_b_path;
extern NJS_POINT3 default_target_offset;
extern NJS_POINT3 default_offset;
extern struct angles default_turn_step;
extern struct angles default_spin_limit;
extern NJS_POINT3 default_move_limit;
extern NJS_POINT3 boss_place_anchor;
extern Sint8 path_playing;
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
extern Bool CamPathCam2Core_AliveFlag;
extern NJS_POINT3 camera_pose_pos;
extern struct angles CamPathCam2Core_Angle;
extern struct angles taiho_turn;
extern struct angles taiho_base;
extern struct angles taiho_last_turn;
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void gravDispose3(struct camera_view * view)
{
    NJS_VECTOR look;
    NJS_VECTOR up = {0.0F, 1.0F, 0.0F};
    float x;
    float dot;
    float scale;
    float cross;
    int wide;
    int angle;
    float z;
    if (GetStageNumber() != ((6) << 8 | (2))) {
        cameraControlWork->ang_z = 0;
        return;
    }
    look.x = cameraControlWork->pos.x - cameraControlWork->target.x;
    look.y = cameraControlWork->pos.y - cameraControlWork->target.y;
    look.z = cameraControlWork->pos.z - cameraControlWork->target.z;
    njUnitVector(&up);
    njPushMatrix(((void *)0));
    njUnitMatrix(((void *)0));
    ((world_gravity_ang_z) ? (njRotateZ)(((void *)0), (world_gravity_ang_z)) : (void)0);
    ((world_gravity_ang_x) ? (njRotateX)(((void *)0), (world_gravity_ang_x)) : (void)0);
    njCalcVector(((void *)0), &up, &up);
    njPopMatrix(1);
    angle = (Angle)(asinf(njSqrt(((x = up.x) * x) + ((z = up.z) * z))) *
                    (65536.0 / (2 * 3.141592)));
    look.y = 0.0F;
    up.y = 0.0F;
    njUnitVector(&look);
    njUnitVector(&up);
    cross = (look.z * up.x) - (look.x * up.z);
    dot = (look.x * up.x) + (look.z * up.z);
    wide = dot ? cameraControlWork->ang_x : 0;
    scale = 1.0F - (dot * dot);
    wide = (angle & 0x8000) ? (angle | 0xffff0000) : (angle & 0xffff);
    if (cross >= 0.0F) {
        cameraControlWork->ang_z = (Angle)((float)wide * scale);
    } else {
        cameraControlWork->ang_z = (Angle) - ((float)wide * scale);
    }
    cameraControlWork->ang_z &= 0xffff;
}
const NJS_VECTOR eu_vec_47 = {0.0F, 0.0F, -47.5F};
void camera_step_trigger_orbit(struct camera_view *view)
{
    NJS_POINT3 old;
    old.x = cameraControlWork->pos.x;
    old.y = cameraControlWork->pos.y;
    old.z = cameraControlWork->pos.z;
    if (!view->steps) {
        NJS_VECTOR to_player;
        to_player.x = playertwp[0]->pos.x - cameraControlWork->pos.x;
        to_player.z = playertwp[0]->pos.z - cameraControlWork->pos.z;
        trigger_orbit_distance =
            njSqrt((to_player.x * to_player.x) + (to_player.z * to_player.z));
        trigger_orbit_height = cameraControlWork->pos.y - playertwp[0]->pos.y;
        trigger_orbit_angle =
            (Angle)(njArcTan2(to_player.x, to_player.z) * (65536.0 / (2 * 3.141592))) +
            0x8000;
    }
    trigger_orbit_angle +=
        (Angle)(((perG[0].l << 8) - (perG[0].r << 8)) *
                0.0056875F);
    cameraControlWork->pos.x = playertwp[0]->pos.x +
                          (trigger_orbit_distance * njSin(trigger_orbit_angle));
    cameraControlWork->pos.y = playertwp[0]->pos.y + trigger_orbit_height;
    cameraControlWork->pos.z = playertwp[0]->pos.z +
                          (trigger_orbit_distance * njCos(trigger_orbit_angle));
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y =
        playertwp[0]->pos.y + GetPlayerWorkPointer(0)->consts.eye_height;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    {
        NJS_VECTOR move;
        move.x = cameraControlWork->pos.x - old.x;
        move.y = cameraControlWork->pos.y - old.y;
        move.z = cameraControlWork->pos.z - old.z;
        if (camera_sweep_hits(&old, &move, ((void *)0), 8.0F)) {
            cameraControlWork->pos.x = old.x;
            cameraControlWork->pos.y = old.y;
            cameraControlWork->pos.z = old.z;
        }
    }
    FUN_8c01a680(camera_twp);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int FUN_8c01e15e(void)
{
    NJS_VECTOR to_target;
    Float distance;
    Float height;
    Angle angle;
    if ((perG[0].x1 << 8) != 0 || (perG[0].y1 << 8) != 0 ||
        (per[0]->on & ((1 << 4) | (1 << 5) | (1 << 6) | (1 << 7))) || !camera_player_still) {
        if (trigger_orbit_active == 1) {
            camera_set_adjust(8);
        }
        trigger_orbit_active = 0;
    } else if ((((perG[0].l) << 8) - 32768 != -32768) ||
               (((perG[0].r) << 8) - 32768 != -32768)) {
        if (!FUN_8c01b406()) {
            trigger_orbit_active = 1;
        }
    }
    if (!trigger_orbit_active) {
        return trigger_orbit_active;
    }
    to_target.x = cameraControlWork->target.x - cameraControlWork->pos.x;
    to_target.z = cameraControlWork->target.z - cameraControlWork->pos.z;
    distance =
        njSqrt((to_target.x * to_target.x) + (to_target.z * to_target.z));
    height = cameraControlWork->pos.y - cameraControlWork->target.y;
    angle =
        (Angle)(njArcTan2(to_target.x, to_target.z) * (65536.0 / (2 * 3.141592))) + 0x8000;
    angle += (Angle)(((perG[0].l << 8) - (perG[0].r << 8)) *
                     0.0056875F);
    cameraControlWork->pos.x = cameraControlWork->target.x + (njSin(angle) * distance);
    cameraControlWork->pos.y = cameraControlWork->target.y + height;
    cameraControlWork->pos.z = cameraControlWork->target.z + (njCos(angle) * distance);
    return trigger_orbit_active;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c01e32a(NJS_POINT3 *last, NJS_POINT3 *pos)
{
    NJS_VECTOR move;
    NJS_VECTOR to_player[2];
    Bool blocked = 0;
    if (FUN_8c01b5e0()) {
        *last = *pos;
        return;
    }
    move.x = pos->x - last->x;
    move.y = pos->y - last->y;
    move.z = pos->z - last->z;
    to_player[0].x = playertwp[0]->pos.x - last->x;
    to_player[0].y = playertwp[0]->pos.y - last->y;
    to_player[0].z = playertwp[0]->pos.z - last->z;
    to_player[1].x = playertwp[0]->pos.x - pos->x;
    to_player[1].y = playertwp[0]->pos.y - pos->y;
    to_player[1].z = playertwp[0]->pos.z - pos->z;
    if (njScalor(&to_player[0]) < njScalor(&to_player[1])) {
        if (camera_sweep_hits(last, &move, ((void *)0), 8.0F)) {
            if (perG[0].on & 0x30000) {
                blocked = 1;
            } else {
                pos->x = last->x + move.x;
                pos->y = last->y + move.y;
                pos->z = last->z + move.z;
            }
        }
    } else if (camera_sweep_hits(last, &move, ((void *)0), 4.0F)) {
        if (perG[0].on & 0x30000) {
            blocked = 1;
        } else {
            pos->x = last->x + move.x;
            pos->y = last->y + move.y;
            pos->z = last->z + move.z;
        }
    }
    if (blocked) {
        pos->x = last->x + ((pos->x - last->x) * 0.1F);
        pos->y = last->y + ((pos->y - last->y) * 0.1F);
        pos->z = last->z + ((pos->z - last->z) * 0.1F);
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c01e508(NJS_POINT3 *last, NJS_POINT3 *pos)
{
    NJS_VECTOR move;
    NJS_VECTOR to_player[2];
    Bool blocked = 0;
    move.x = pos->x - last->x;
    move.y = pos->y - last->y;
    move.z = pos->z - last->z;
    to_player[0].x = playertwp[0]->pos.x - last->x;
    to_player[0].y = playertwp[0]->pos.y - last->y;
    to_player[0].z = playertwp[0]->pos.z - last->z;
    to_player[1].x = playertwp[0]->pos.x - pos->x;
    to_player[1].y = playertwp[0]->pos.y - pos->y;
    to_player[1].z = playertwp[0]->pos.z - pos->z;
    if (njScalor(&to_player[0]) < njScalor(&to_player[1])) {
        if (camera_sweep_hits(last, &move, ((void *)0), 8.0F)) {
            if (perG[0].on & 0x30000) {
                blocked = 1;
            } else {
                pos->x = last->x + move.x;
                pos->y = last->y + move.y;
                pos->z = last->z + move.z;
            }
        }
    } else if (camera_sweep_hits(last, &move, ((void *)0), 4.0F)) {
        if (perG[0].on & 0x30000) {
            blocked = 1;
        } else {
            pos->x = last->x + move.x;
            pos->y = last->y + move.y;
            pos->z = last->z + move.z;
        }
    }
    if (blocked) {
        pos->x = last->x + ((pos->x - last->x) * 0.1F);
        pos->y = last->y + ((pos->y - last->y) * 0.1F);
        pos->z = last->z + ((pos->z - last->z) * 0.1F);
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c01e6a6(struct camera_view *view)
{
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y = playertwp[0]->pos.y +
                             GetPlayerWorkPointer(0)->consts.eye_height +
                             (cameraControlWork->distance * 0.06F);
    cameraControlWork->target.z = playertwp[0]->pos.z;
    cameraControlWork->distance = manual_distance;
    cameraControlWork->ang_x = (-0x800);
    cameraControlWork->ang_z = 0;
    if (((struct player_vars *)&(playertwp[0])->vars)->character == 3 &&
        playertwp[0]->mode == KNUCKLES_PUSH) {
        cameraControlWork->ang_y +=
            angle_difference(cameraControlWork->ang_y,
                             0xc000 - playertwp[0]->ang.y) >>
            2;
    } else if (perG[0].on & (1 << 9)) {
        if (perG[0].on & (1 << 17)) {
            manual_distance += 2.0F;
        } else if (perG[0].on & (1 << 16)) {
            manual_distance -= 2.0F;
        }
    } else if (perG[0].on & (1 << 17)) {
        cameraControlWork->flags |= 0x1;
        cameraControlWork->ang_y -= 0x200;
    } else if (perG[0].on & (1 << 16)) {
        cameraControlWork->flags |= 0x1;
        cameraControlWork->ang_y += 0x200;
    }
}
void camera_step_origin(struct camera_view *view)
{
    cameraControlWork->target.x = 0.0F;
    cameraControlWork->target.y = 0.0F;
    cameraControlWork->target.z = 0.0F;
    cameraControlWork->distance = 50.0F;
    cameraControlWork->ang_x = 0;
    cameraControlWork->ang_z = 0;
    cameraControlWork->ang_y = 0;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_orbit(struct camera_view *view)
{
    Sint16 x;
    Sint16 y;
    unsigned short right;
    unsigned short left;
    cameraControlWork->target.x = camera_take_work->pos.x;
    cameraControlWork->target.y = camera_take_work->pos.y;
    cameraControlWork->target.z = camera_take_work->pos.z;
    cameraControlWork->ang_z = 0;
    if (per[0]->on & (1 << 3)) {
        x = per[0]->x1 << 8;
        y = per[0]->y1 << 8;
        if (x > -5000 && x < 5000) {
            x = 0;
        }
        if (y > -5000 && y < 5000) {
            y = 0;
        }
        right = ((Sint16)per[0]->r << 8) + 0x8000;
        left = ((Sint16)per[0]->l << 8) + 0x8000;
        cameraControlWork->ang_y += x / 64;
        cameraControlWork->ang_x += y / 64;
        if (per[0]->on & (1 << 17)) {
            cameraControlWork->distance += 2.0F;
        } else if (per[0]->on & (1 << 16)) {
            cameraControlWork->distance -= 2.0F;
        }
    }
    if (cameraControlWork->distance < 5.0F) {
        cameraControlWork->distance = 5.0F;
    }
    camera_place_from_target(camera_twp);
}
void camera_preview_view(struct camera_view *view)
{
    cameraControlWork->target.x = view->target.x;
    cameraControlWork->target.y = view->target.y;
    cameraControlWork->target.z = view->target.z;
    cameraControlWork->pos.x = view->pos.x;
    cameraControlWork->pos.y = view->pos.y;
    cameraControlWork->pos.z = view->pos.z;
    cameraControlWork->ang_z = 0;
    FUN_8c01a680(camera_twp);
}
void camera_step_guriguri(struct camera_view *view)
{
    short x;
    short y;
    unsigned short right;
    unsigned short left;
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y = playertwp[0]->pos.y;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    cameraControlWork->ang_z = 0;
    if (perG[1].press & (1 << 1)) {
        cameraControlWork->distance = 50.0F;
        cameraControlWork->ang_x = -0x800;
    }
    x = perG[0].x1 << 8;
    y = perG[0].y1 << 8;
    if (x > -5000 && x < 5000) {
        x = 0;
    }
    if (y > -5000 && y < 5000) {
        y = 0;
    }
    right = ((Sint16)perG[0].r << 8) + 0x8000;
    left = ((Sint16)perG[0].l << 8) + 0x8000;
    cameraControlWork->distance += right * 0.0001F;
    cameraControlWork->distance -= left * 0.0001F;
    cameraControlWork->ang_y += x / 64;
    cameraControlWork->ang_x += y / 64;
    if (perG[0].on & (1 << 0)) {
        cameraControlWork->distance += 2.0F;
    } else if (perG[0].on & (1 << 8)) {
        cameraControlWork->distance -= 2.0F;
    }
    if (cameraControlWork->distance < 5.0F) {
        cameraControlWork->distance = 5.0F;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_magonote(struct camera_view *view)
{
    NJS_POINT3 previous;
    NJS_POINT3 lead;
    NJS_POINT3 eyes;
    NJS_VECTOR offset;
    NJS_VECTOR heading;
    NJS_POINT3 *lp;
    NJS_VECTOR *hp;
    NJS_VECTOR *op;
    Float length;
    Angle diff;
    PDS_PERIPHERAL *pad;
    previous.x = camera_twp->pos.x;
    previous.y = camera_twp->pos.y;
    previous.z = camera_twp->pos.z;
    eyes = playertwp[0]->pos;
    eyes.y += GetPlayerWorkPointer(0)->consts.eye_height;
    hp = &heading;
    *hp = playermwp[0]->speed;
    lp = &lead;
    lp->x = eyes.x + (hp->x * 8.0F);
    lp->y = eyes.y + (hp->y * 8.0F);
    lp->z = eyes.z + (hp->z * 8.0F);
    if (0) {
    split:;
    }
    else if (0) {
    } else if (view->steps == 0) {
        cameraControlWork->target.x = lp->x;
        cameraControlWork->target.y = lp->y;
        cameraControlWork->target.z = lp->z;
    } else {
        cameraControlWork->target.x += (lp->x - cameraControlWork->target.x) * 0.1F;
        cameraControlWork->target.y += (lp->y - cameraControlWork->target.y) * 0.1F;
        cameraControlWork->target.z += (lp->z - cameraControlWork->target.z) * 0.1F;
    }
    if (0) {
        camera_twp->ang.x = 1;
        camera_twp->ang.x = 1;
        camera_twp->ang.x = 1;
    }
    if (0) {
    }
    op = &offset;
    op->x = lp->x - camera_twp->pos.x;
    op->y = lp->y - camera_twp->pos.y;
    op->z = lp->z - camera_twp->pos.z;
    length = njScalor(op);
    (void)lp->x;
    {
        NJS_VECTOR dir;
        dir = *op;
        njUnitVector(&dir);
        if (length > 40.0F) {
            length = ((length - 40.0F) * 0.9F) + 40.0F;
            if (length > 70.0F) {
                length = 70.0F;
            }
        } else if (length < 15.0F) {
            length *= 1.06F;
            if (length <= 0.0F) {
                length = 15.0F;
            }
        }
        cameraControlWork->pos.x += op->x - (dir.x * length);
        cameraControlWork->pos.y += op->y - (dir.y * length);
        cameraControlWork->pos.z += op->z - (dir.z * length);
    }
    {
        NJS_MATRIX matrix;
        NJS_VECTOR unit;
        Angle angle;
        unit.x = 1.0F;
        unit.y = unit.z = 0.0F;
        njUnitMatrix(&matrix);
        (((angle) = (playertwp[0]->ang.z)) ? (njRotateZ)((&matrix), (angle)) : (void)0);
        (((angle) = (playertwp[0]->ang.x)) ? (njRotateX)((&matrix), (angle)) : (void)0);
        (((angle) = (-playertwp[0]->ang.y)) ? (njRotateY)((&matrix), (angle)) : (void)0);
        njCalcVector(&matrix, &unit, hp);
    }
    hp->z = njSqrt((hp->x * hp->x) + (hp->z * hp->z));
    hp->x = 0.0F;
    njUnitVector(hp);
    op->z = njSqrt((op->x * op->x) + (op->z * op->z));
    op->x = 0.0F;
    njUnitVector(op);
    diff = angle_difference(camera_twp->ang.x,
                            (Angle)(njArcTan2(hp->y, hp->z) * (65536.0 / (2 * 3.141592))) -
                                0xa00);
    if (diff < -0x1000) {
        cameraControlWork->pos.y += 2.0F;
    } else if (diff < -0x800) {
        cameraControlWork->pos.y += 0.5F;
    } else if (diff < -0x400) {
        cameraControlWork->pos.y += 0.1F;
    } else if (diff > 0x1000) {
        cameraControlWork->pos.y -= 2.0F;
    } else if (diff > 0x800) {
        cameraControlWork->pos.y -= 0.5F;
    } else if (diff > 0x400) {
        cameraControlWork->pos.y -= 0.1F;
    }
    pad = perG;
    if (0) {
        if (pad) {
        }
    }
    if (0) {
        if (pad) {
        }
    }
    if (pad->on & (1 << 16)) {
        cameraControlWork->pos.x += njCos(camera_twp->ang.y) * 2.0F;
        cameraControlWork->pos.z -= njSin(camera_twp->ang.y) * 2.0F;
    } else if (pad->on & (1 << 17)) {
        cameraControlWork->pos.x -= njCos(camera_twp->ang.y) * 2.0F;
        cameraControlWork->pos.z += njSin(camera_twp->ang.y) * 2.0F;
    }
    {
        NJS_VECTOR dir;
        dir.x = cameraControlWork->pos.x - previous.x;
        dir.y = cameraControlWork->pos.y - previous.y;
        dir.z = cameraControlWork->pos.z - previous.z;
        if (MSetPosition(&previous, &dir, ((void *)0), 8.0F)) {
            cameraControlWork->pos.x = previous.x + dir.x;
            cameraControlWork->pos.y = previous.y + dir.y;
            cameraControlWork->pos.z = previous.z + dir.z;
        }
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c01effe(struct camera_view *view)
{
    struct task_work *player;
    Angle angle;
    if (playertwp[0] || playermwp[0]) {
        player = playertwp[0];
    } else {
        CameraReleaseEventCamera();
        return;
    }
    angle = (Angle)(njArcTan2(cameraControlWork->pos.x - player->pos.x,
                           cameraControlWork->pos.z - player->pos.z) *
                    (65536.0 / (2 * 3.141592)));
    if (perG[0].on & (1 << 17)) {
        cameraControlWork->ang_y -= 0xff;
    } else if (perG[0].on & (1 << 16)) {
        cameraControlWork->ang_y += 0xff;
    } else {
        cameraControlWork->ang_y = AdjustAngle(cameraControlWork->ang_y, angle, 0xff);
    }
    cameraControlWork->pos.x =
        (njSin(cameraControlWork->ang_y) * view->distance) + cameraControlWork->target.x;
    cameraControlWork->pos.z =
        (njCos(cameraControlWork->ang_y) * view->distance) + cameraControlWork->target.z;
    cameraControlWork->pos.y = player->pos.y + view->pos.y;
    cameraControlWork->target.x = view->target.x;
    cameraControlWork->target.y = view->target.y;
    cameraControlWork->target.z = view->target.z;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_pathcam(struct camera_view *view)
{
    unsigned short stage_act = GetStageNumber();
    struct pathcam_route *route;
    struct pathcam_path **paths;
    unsigned short count;
    struct pathcam_path *path;
    Float length;
    struct pathcam_key *key;
    struct pathcam_key *next;
    Float part;
    unsigned short index;
    for (route = pathcam_routes; route->stage_act != stage_act; route++) {
        if (route->stage_act == 0xffff) {
            CameraReleaseEventCamera();
            return;
        }
    }
    ((struct pathcam_vars *)&(camera_twp)->vars)->route = route;
    count = route->count;
    paths = route->paths;
    if (per[0]->press & (1 << 2)) {
        ((struct pathcam_vars *)&(camera_twp)->vars)->place = 0.0F;
        if (++((struct pathcam_vars *)&(camera_twp)->vars)->path >= count) {
            ((struct pathcam_vars *)&(camera_twp)->vars)->path = 0;
        }
    }
    path = paths[((struct pathcam_vars *)&(camera_twp)->vars)->path];
    length = path->length;
    key = path->keys;
    if (per[0]->press & (1 << 4)) {
        camera_twp->scl.x += 0.05F;
    }
    if (per[0]->press & (1 << 5)) {
        camera_twp->scl.x -= 0.05F;
    }
    if (camera_twp->scl.x < 0.05F) {
        camera_twp->scl.x = 0.05F;
    }
    if (camera_twp->scl.x > 1.0F) {
        camera_twp->scl.x = 1.0F;
    }
    ((struct pathcam_vars *)&(camera_twp)->vars)->place += camera_twp->scl.x;
    if (((struct pathcam_vars *)&(camera_twp)->vars)->place < 0.0F ||
        ((struct pathcam_vars *)&(camera_twp)->vars)->place >= length) {
        ((struct pathcam_vars *)&(camera_twp)->vars)->place = 0.0F;
    }
    if (per[0]->press & (1 << 1)) {
        ((struct pathcam_vars *)&(camera_twp)->vars)->place = 0.0F;
    }
    index = (int)((struct pathcam_vars *)&(camera_twp)->vars)->place;
    part = ((struct pathcam_vars *)&(camera_twp)->vars)->place - index;
    key += index;
    next = key;
    next++;
    cameraControlWork->pos.x = key->pos.x + ((next->pos.x - key->pos.x) * part);
    cameraControlWork->pos.y = key->pos.y + ((next->pos.y - key->pos.y) * part);
    cameraControlWork->pos.z = key->pos.z + ((next->pos.z - key->pos.z) * part);
    cameraControlWork->ang_x =
        (Angle)(angle_difference(key->ang_x, next->ang_x) * part) + key->ang_x;
    cameraControlWork->ang_y =
        (Angle)(angle_difference(key->ang_y, next->ang_y) * part) + key->ang_y;
    cameraControlWork->ang_z =
        (Angle)(angle_difference(key->ang_z, next->ang_z) * part) + key->ang_z;
    camera_place_at_angles(camera_twp);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c01f358(struct camera_view *view)
{
    GetPlayerWorkPointer(0);
    if (playertwp[0]->pos.y > -10200.0F) {
        cameraControlWork->target.x = 0.0F;
        cameraControlWork->target.y = playertwp[0]->pos.y - 90.0F;
        cameraControlWork->target.z = playertwp[0]->pos.z;
        cameraControlWork->pos.x = 35.0F;
        cameraControlWork->pos.y = playertwp[0]->pos.y + 40.0F;
        cameraControlWork->pos.z = playertwp[0]->pos.z;
        cameraControlWork->ang_z = 0;
    } else if (playertwp[0]->pos.y > -18380.0F) {
        cameraControlWork->target.x = 0.0F;
        cameraControlWork->target.y = playertwp[0]->pos.y - 100.0F;
        cameraControlWork->target.z = playertwp[0]->pos.z;
        cameraControlWork->pos.x = 20.0F;
        cameraControlWork->pos.y = playertwp[0]->pos.y + 30.0F;
        cameraControlWork->pos.z = playertwp[0]->pos.z;
        if (DiffAngle(cameraControlWork->ang_z, 0x8000) > 0xc00) {
            cameraControlWork->ang_z = AdjustAngle(
                cameraControlWork->ang_z, playertwp[0]->ang.y + 0x8000, 0x800);
        } else {
            cameraControlWork->ang_z = AdjustAngle(
                cameraControlWork->ang_z, playertwp[0]->ang.y + 0x8000, 64);
        }
    } else {
        cameraControlWork->ang_z = 0;
    }
}
void board_fixed_view(struct camera_view *view);
#pragma inline(board_target_ease)
static void board_target_ease(NJS_POINT3 *lead)
{
    cameraControlWork->target.x += (lead->x - cameraControlWork->target.x) * 0.16F;
    cameraControlWork->target.y += (lead->y - cameraControlWork->target.y) * 0.16F;
    cameraControlWork->target.z += (lead->z - cameraControlWork->target.z) * 0.16F;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void AmyBalanceGameStartChecker(struct camera_view *view)
{
    NJS_POINT3 previous;
    NJS_POINT3 lead;
    NJS_POINT3 pos;
    NJS_VECTOR offset;
    NJS_VECTOR speed;
    Uint32 unused[3];
    NJS_VECTOR dir;
    NJS_VECTOR delta;
    NJS_VECTOR normal;
    NJS_VECTOR *sp;
    NJS_POINT3 *lp;
    NJS_VECTOR *op;
    Float length;
    Float distance;
    Float slowness;
    Angle angle;
    if (GetStageNumber() == ((8) << 8 | (2)) &&
        playertwp[0]->pos.x > -5400.0F && playertwp[0]->pos.y > -3900.0F) {
        camera_twp->submode = 1;
        board_fixed_view(view);
    } else {
        camera_twp->submode = 0;
        if (0) {
            camera_twp->ang.x += matrix_push_unit();
        }
        previous = camera_twp->pos;
        pos = playertwp[0]->pos;
        sp = &speed;
        *sp = GetPlayerWorkPointer(0)->speed;
        player_turn_to_world(playertwp[0], sp);
        lp = &lead;
        lp->x = pos.x + (sp->x * 16.0F);
        lp->y = pos.y + (sp->y * 16.0F);
        lp->z = pos.z + (sp->z * 16.0F);
        if (view->steps == 0) {
            cameraControlWork->target.x = lp->x;
            cameraControlWork->target.y = lp->y;
            cameraControlWork->target.z = lp->z;
        } else {
            board_target_ease(lp);
        }
        op = &offset;
        op->x = camera_twp->pos.x - pos.x;
        op->y = camera_twp->pos.y - pos.y;
        op->z = camera_twp->pos.z - pos.z;
        length = njScalor(op);
        distance = length;
        dir = *op;
        njUnitVector(&dir);
        if (length > 22.0F) {
            length = 22.0F;
        } else if (length < 18.0F) {
            length = 18.0F;
        }
        cameraControlWork->pos.x += dir.x * (length - distance);
        cameraControlWork->pos.y += dir.y * (length - distance);
        cameraControlWork->pos.z += dir.z * (length - distance);
        slowness = (-njScalor(&playermwp[0]->speed) + 3.0F) * 0.33333333F;
        if (slowness < 0.0F) {
            slowness = 0.0F;
        }
        dir.x = -(slowness * 40.0F);
        dir.y = slowness * 3.0F;
        dir.z = 0.0F;
        player_turn_to_world(playertwp[0], &dir);
        cameraControlWork->pos.x += dir.x;
        cameraControlWork->pos.y += dir.y;
        cameraControlWork->pos.z += dir.z;
        dir = previous;
        normal = GetPlayerWorkPointer(0)->ground_normal;
        normal.x *= 4.0F;
        normal.y *= 4.0F;
        normal.z *= 4.0F;
        njAddVector(&dir, &normal);
        delta.x = cameraControlWork->pos.x - previous.x;
        delta.y = cameraControlWork->pos.y - previous.y;
        delta.z = cameraControlWork->pos.z - previous.z;
        if (MSetPosition(&dir, &delta, ((void *)0), 14.0F)) {
            cameraControlWork->pos.x = dir.x + delta.x - normal.x;
            cameraControlWork->pos.y = dir.y + delta.y - normal.y;
            cameraControlWork->pos.z = dir.z + delta.z - normal.z;
        }
        matrix_push_unit();
        (((angle) = (-camera_twp->ang.x)) ? (njRotateX)(((void *)0), (angle)) : (void)0);
        (((angle) = (-camera_twp->ang.y)) ? (njRotateY)(((void *)0), (angle)) : (void)0);
        njCalcVector(((void *)0), &normal, &normal);
        njPopMatrix(1);
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void board_fixed_view(struct camera_view *view)
{
    NJS_POINT3 previous;
    Uint32 unused[6];
    NJS_VECTOR dir;
    NJS_POINT3 origin;
    NJS_VECTOR delta;
    NJS_VECTOR normal;
    Float distance;
    previous = camera_twp->pos;
    distance = (njScalor(&playermwp[0]->speed) * 6.0F) + 20.0F;
    dir.x = njCos(-0xccc) * njSin(-0x471c);
    dir.y = njSin(-0xccc);
    dir.z = njCos(-0xccc) * njCos(-0x471c);
    cameraControlWork->pos.x = playertwp[0]->pos.x + (dir.x * distance);
    cameraControlWork->pos.y = playertwp[0]->pos.y + (dir.y * distance);
    cameraControlWork->pos.z = playertwp[0]->pos.z + (dir.z * distance);
    cameraControlWork->target.x = playertwp[0]->pos.x - (dir.x * distance);
    cameraControlWork->target.y = playertwp[0]->pos.y - (dir.y * distance);
    cameraControlWork->target.z = playertwp[0]->pos.z - (dir.z * distance);
    camera_push_out(&cameraControlWork->pos);
    origin = previous;
    normal = GetPlayerWorkPointer(0)->ground_normal;
    normal.x *= 4.0F;
    normal.y *= 4.0F;
    normal.z *= 4.0F;
    njAddVector(&origin, &normal);
    delta.x = cameraControlWork->pos.x - previous.x;
    delta.y = cameraControlWork->pos.y - previous.y;
    delta.z = cameraControlWork->pos.z - previous.z;
    if (MSetPosition(&origin, &delta, ((void *)0), 14.0F)) {
        cameraControlWork->pos.x = origin.x + delta.x - normal.x;
        cameraControlWork->pos.y = origin.y + delta.y - normal.y;
        cameraControlWork->pos.z = origin.z + delta.z - normal.z;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_trick_a(struct camera_view *view)
{
    struct GetStatusOnPath sample;
    NJS_VECTOR offset;
    NJS_VECTOR turned;
    Angle angle;
    Float distance;
    struct path *path = &trick_a_path;
    struct task_work *player = playertwp[0];
    int valid;
    valid = path_get_distance(path, view->steps, &distance);
    view->steps++;
    sample.distance = distance;
    if (!valid || (player->flags & 0x1) ||
        !GetStatusOnPath(path, &sample)) {
        CameraReleaseEventCamera();
        CameraSetEventCameraFunc(AmyBalanceGameStartChecker, 3, CAMERA_LOOK_AT);
        return;
    }
    offset.x = sample.pos.x;
    offset.y = sample.pos.y;
    offset.z = sample.pos.z;
    njPushMatrix(&nj_unit_matrix_);
    (((angle) = (-playertwp[0]->ang.y + 0x8000)) ? (njRotateY)(((void *)0), (angle)) : (void)0);
    njCalcVector(((void *)0), &offset, &turned);
    sample.pos.x = turned.x;
    sample.pos.y = turned.y;
    sample.pos.z = turned.z;
    njPopMatrix(1);
    cameraControlWork->pos.x =
        playertwp[0]->pos.x + playermwp[0]->speed.x + sample.pos.x;
    cameraControlWork->pos.y =
        playertwp[0]->pos.y + playermwp[0]->speed.y + sample.pos.y;
    cameraControlWork->pos.z =
        playertwp[0]->pos.z + playermwp[0]->speed.z + sample.pos.z;
    cameraControlWork->target.x =
        playertwp[0]->collision->shapes->center.x + playermwp[0]->speed.x;
    cameraControlWork->target.y =
        playertwp[0]->collision->shapes->center.y + playermwp[0]->speed.y;
    cameraControlWork->target.z =
        playertwp[0]->collision->shapes->center.z + playermwp[0]->speed.z;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_point(struct camera_view *view)
{
    NJS_POINT3 camera;
    NJS_VECTOR direction;
    NJS_POINT3 target;
    if (!view->steps) {
        camera_point_follows = 0;
    }
    if (camera_point_follows) {
        camera_step_follow(view);
        if (!(((perG[0].l) << 8) - 32768 != -32768) &&
            !(((perG[0].r) << 8) - 32768 != -32768) && !camera_player_still) {
            camera_point_follows = 0;
            camera_set_adjust(26);
        }
        return;
    }
    if ((((perG[0].l) << 8) - 32768 != -32768) || (((perG[0].r) << 8) - 32768 != -32768)) {
        if (pad_is_enabled()) {
            camera_point_follows = 1;
        }
    }
    camera = camera_twp->pos;
    if (!FUN_8c01e15e()) {
        target.x = view->target.x;
        target.y = view->target.y;
        target.z = view->target.z;
        cameraControlWork->target.x = playertwp[0]->pos.x;
        cameraControlWork->target.y = playertwp[0]->pos.y + 7.5F;
        cameraControlWork->target.z = playertwp[0]->pos.z;
        direction.x = playertwp[0]->pos.x - target.x;
        direction.y = playertwp[0]->pos.y - target.y;
        direction.z = playertwp[0]->pos.z - target.z;
        njUnitVector(&direction);
        cameraControlWork->pos.x =
            cameraControlWork->target.x + (view->distance * direction.x);
        cameraControlWork->pos.y =
            cameraControlWork->target.y + (view->distance * direction.y);
        cameraControlWork->pos.z =
            cameraControlWork->target.z + (view->distance * direction.z);
    }
    camera_push_out(&cameraControlWork->pos);
    camera_ease(&camera, &cameraControlWork->pos);
    if (!(Uint16)view->ang_x) {
        FUN_8c01e32a(&camera, &cameraControlWork->pos);
    }
    gravDispose3(view);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c020140(int unbounded)
{
    Float dz;
    Float dx;
    Float dist;
    Angle turn_y;
    Angle turn_x;
    Angle turn_z;
    Angle step_x;
    Angle step_y;
    Angle step_z;
    turn_y = (Angle)(njArcTan2(dx = cameraControlWork->pos.x - cameraControlWork->target.x,
                            dz = cameraControlWork->pos.z - cameraControlWork->target.z) *
                     (65536.0 / (2 * 3.141592)));
    dist = njSqrt((dx * dx) + (dz * dz));
    turn_x =
        -(Angle)(njArcTan2(cameraControlWork->pos.y - cameraControlWork->target.y, dist) *
                 (65536.0 / (2 * 3.141592)));
    turn_z = cameraControlWork->ang_z;
    turn_x = angle_difference(cameraControlWork->ang_x, turn_x) / 4;
    turn_y = angle_difference(cameraControlWork->ang_y, turn_y) / 4;
    turn_z = angle_difference(cameraControlWork->ang_z, turn_z) / 4;
    step_x = turn_x - cameraControlWork->spin_x;
    step_y = turn_y - cameraControlWork->spin_y;
    step_z = turn_z - cameraControlWork->spin_z;
    if (!unbounded) {
        step_x =
            ((step_x) < (-camera_boss_turn_step.x) ? (-camera_boss_turn_step.x) : (step_x) > (camera_boss_turn_step.x) ? (camera_boss_turn_step.x) : (step_x));
        step_y =
            ((step_y) < (-camera_boss_turn_step.y) ? (-camera_boss_turn_step.y) : (step_y) > (camera_boss_turn_step.y) ? (camera_boss_turn_step.y) : (step_y));
        step_z =
            ((step_z) < (-camera_boss_turn_step.z) ? (-camera_boss_turn_step.z) : (step_z) > (camera_boss_turn_step.z) ? (camera_boss_turn_step.z) : (step_z));
    }
    cameraControlWork->spin_x += step_x;
    cameraControlWork->spin_y += step_y;
    cameraControlWork->spin_z += step_z;
    if (!unbounded) {
        cameraControlWork->spin_x =
            ((cameraControlWork->spin_x) < (-camera_boss_spin_limit.x) ? (-camera_boss_spin_limit.x) : (cameraControlWork->spin_x) > (camera_boss_spin_limit.x) ? (camera_boss_spin_limit.x) : (cameraControlWork->spin_x));
        cameraControlWork->spin_y =
            ((cameraControlWork->spin_y) < (-camera_boss_spin_limit.y) ? (-camera_boss_spin_limit.y) : (cameraControlWork->spin_y) > (camera_boss_spin_limit.y) ? (camera_boss_spin_limit.y) : (cameraControlWork->spin_y));
        cameraControlWork->spin_z =
            ((cameraControlWork->spin_z) < (-camera_boss_spin_limit.z) ? (-camera_boss_spin_limit.z) : (cameraControlWork->spin_z) > (camera_boss_spin_limit.z) ? (camera_boss_spin_limit.z) : (cameraControlWork->spin_z));
    }
    cameraControlWork->ang_x += cameraControlWork->spin_x;
    cameraControlWork->ang_y += cameraControlWork->spin_y;
    cameraControlWork->ang_z += cameraControlWork->spin_z;
}
void camera_boss_place_from_player(int below_only)
{
    Float dx;
    Float dz;
    Float dist;
    Angle pitch;
    Angle angle;
    njPushMatrix(&nj_unit_matrix_);
    dx = cameraControlWork->target.x - playertwp[0]->pos.x;
    dz = cameraControlWork->target.z - playertwp[0]->pos.z;
    if (playertwp[0]->flags & 0x1) {
        dist = njSqrt((dx * dx) + (dz * dz));
        pitch = (Angle)(njArcTan2(cameraControlWork->target.y - playertwp[0]->pos.y,
                               dist) *
                        (65536.0 / (2 * 3.141592)));
    } else {
        pitch = 0;
    }
    (((angle) = (cameraControlWork->ang_y)) ? (njRotateY)(((void *)0), (angle)) : (void)0);
    if (below_only == 1) {
        pitch = pitch < 0 ? pitch : 0;
    }
    ((pitch) ? (njRotateX)(((void *)0), (pitch)) : (void)0);
    njCalcPoint(((void *)0), &camera_boss_offset, &camera_boss_place);
    njPopMatrix(1);
    njAddVector(&camera_boss_place, &playertwp[0]->pos);
}
int FUN_8c020440(int from_anchor)
{
    Float dx;
    Float dz;
    Angle angle;
    if (from_anchor) {
        dx = playertwp[0]->pos.x - boss_place_anchor.x;
        dz = playertwp[0]->pos.z - boss_place_anchor.z;
        angle = (Angle)(njArcTan2(dx, dz) * (65536.0 / (2 * 3.141592)));
        camera_boss_place.x = playertwp[0]->pos.x - (njSin(angle) * 30.0F);
        camera_boss_place.z = playertwp[0]->pos.z - (njCos(angle) * 30.0F);
    }
    cameraControlWork->move.x = camera_boss_place.x - cameraControlWork->pos.x;
    cameraControlWork->move.y = camera_boss_place.y - cameraControlWork->pos.y;
    cameraControlWork->move.z = camera_boss_place.z - cameraControlWork->pos.z;
    cameraControlWork->move.x =
        ((cameraControlWork->move.x) < (-camera_boss_move_limit.x) ? (-camera_boss_move_limit.x) : (cameraControlWork->move.x) > (camera_boss_move_limit.x) ? (camera_boss_move_limit.x) : (cameraControlWork->move.x));
    cameraControlWork->move.y =
        ((cameraControlWork->move.y) < (-camera_boss_move_limit.y) ? (-camera_boss_move_limit.y) : (cameraControlWork->move.y) > (camera_boss_move_limit.y) ? (camera_boss_move_limit.y) : (cameraControlWork->move.y));
    cameraControlWork->move.z =
        ((cameraControlWork->move.z) < (-camera_boss_move_limit.x) ? (-camera_boss_move_limit.x) : (cameraControlWork->move.z) > (camera_boss_move_limit.x) ? (camera_boss_move_limit.x) : (cameraControlWork->move.z));
    njAddVector(&cameraControlWork->pos, &cameraControlWork->move);
    return 0;
}
void camera_step_chaos(struct camera_view *view)
{
    register NJS_POINT3 *point;
    Float dx;
    Float dz;
    Angle angle;
    switch (cameraControlWork->phase) {
    case 0:
        dx = boss_work->pos.x - playertwp[0]->pos.x;
        dz = boss_work->pos.z - playertwp[0]->pos.z;
        angle = -(Angle)(njArcTan2(dx, dz) * (65536.0 / (2 * 3.141592)));
        cameraControlWork->pos.x = playertwp[0]->pos.x + (njSin(angle) * 30.0F);
        cameraControlWork->pos.y = playertwp[0]->pos.y + 15.0F;
        cameraControlWork->pos.z = playertwp[0]->pos.z + (njCos(angle) * 30.0F);
        *(NJS_POINT3 *)&cameraControlWork->target.x = boss_work->pos;
        cameraControlWork->ang_y =
            (Angle)(njArcTan2(cameraControlWork->pos.x - boss_work->pos.x,
                           cameraControlWork->pos.z - boss_work->pos.z) *
                    (65536.0 / (2 * 3.141592)));
        cameraControlWork->ang_x = cameraControlWork->ang_z = 0;
        cameraControlWork->phase = 1;
        break;
    case 1:
        if (playertwp[0]->flags & 0x1) {
            point = &boss_work->pos;
        } else {
            point = &playertwp[0]->pos;
        }
        cameraControlWork->target.x = point->x + camera_boss_target_offset.x;
        cameraControlWork->target.y = point->y + camera_boss_target_offset.y;
        cameraControlWork->target.z = point->z + camera_boss_target_offset.z;
        camera_boss_place_from_player(1);
        FUN_8c020440(0);
        FUN_8c020140(0);
        break;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c02070e(int unbounded)
{
    cameraControlWork->move.x = camera_boss_place.x - cameraControlWork->pos.x;
    cameraControlWork->move.y = camera_boss_place.y - cameraControlWork->pos.y;
    cameraControlWork->move.z = camera_boss_place.z - cameraControlWork->pos.z;
    if (!unbounded) {
        cameraControlWork->move.x =
            ((cameraControlWork->move.x) < (-camera_boss_move_limit.x) ? (-camera_boss_move_limit.x) : (cameraControlWork->move.x) > (camera_boss_move_limit.x) ? (camera_boss_move_limit.x) : (cameraControlWork->move.x));
        cameraControlWork->move.y =
            ((cameraControlWork->move.y) < (-camera_boss_move_limit.y) ? (-camera_boss_move_limit.y) : (cameraControlWork->move.y) > (camera_boss_move_limit.y) ? (camera_boss_move_limit.y) : (cameraControlWork->move.y));
        cameraControlWork->move.z =
            ((cameraControlWork->move.z) < (-camera_boss_move_limit.x) ? (-camera_boss_move_limit.x) : (cameraControlWork->move.z) > (camera_boss_move_limit.x) ? (camera_boss_move_limit.x) : (cameraControlWork->move.z));
    }
    njAddVector(&cameraControlWork->pos, &cameraControlWork->move);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_chaos_p(struct camera_view *view)
{
    cameraControlWork->target.x = boss_work->pos.x;
    cameraControlWork->target.y = boss_work->pos.y;
    cameraControlWork->target.z = boss_work->pos.z;
    FUN_8c020140(0);
    camera_boss_place_from_player(0);
    FUN_8c020440(0);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_chaos_std(struct camera_view *view)
{
    cameraControlWork->target.x = boss_work->pos.x + camera_boss_target_offset.x;
    cameraControlWork->target.y = boss_work->pos.y + camera_boss_target_offset.y;
    cameraControlWork->target.z = boss_work->pos.z + camera_boss_target_offset.z;
    FUN_8c020140(0);
    camera_boss_place_from_player(1);
    FUN_8c020440(0);
}
#if 0
/* EU function at 8C0208E0 (46 bytes, the JP camera_set_boss_offsets): it sits in the original bytes of camera_step_chaos_std
 * (+asmfunc runs on to camera_set_boss_limits), so it is kept as C text here (fcmp: MATCH with an F entry added) */
void camera_set_boss_offsets(NJS_POINT3 *target, NJS_POINT3 *offset)
{
    if (!target) {
        target = &default_target_offset;
    }
    if (!offset) {
        offset = &default_offset;
    }
    camera_boss_target_offset = *target;
    camera_boss_offset = *offset;
    camera_set_boss_limits(((void *)0), ((void *)0), ((void *)0));
}
#endif
void camera_set_boss_limits(struct angles *step, struct angles *spin,
                            NJS_VECTOR *move)
{
    if (!step) {
        step = &default_turn_step;
    }
    if (!spin) {
        spin = &default_spin_limit;
    }
    if (!move) {
        move = &default_move_limit;
    }
    camera_boss_turn_step = *step;
    camera_boss_spin_limit = *spin;
    camera_boss_move_limit = *move;
}
void point_on_heading(float distance, NJS_POINT3 *out)
{
    NJS_POINT3 point;
    Angle angle;
    point.x = 0.0F;
    point.y = 0.0F;
    point.z = distance;
    njPushMatrix(&nj_unit_matrix_);
    (((angle) = (cameraControlWork->ang_y)) ? (njRotateY)(((void *)0), (angle)) : (void)0);
    njCalcPoint(((void *)0), &point, out);
    njPopMatrix(1);
    njAddVector(out, &cameraControlWork->target);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c0209a0(struct camera_view *view)
{
    switch (camera_swing_phase) {
    case SWING_CLOSING:
        camera_swing_distance += camera_swing_close_step;
        if (camera_swing_distance <= camera_swing_near) {
            camera_swing_phase = SWING_TURNING;
        }
        break;
    case SWING_TURNING:
        camera_swing_heading += camera_swing_turn;
        camera_swing_turned += camera_swing_turn;
        if (camera_swing_turned >= 0x4000) {
            camera_swing_phase = SWING_ROUND;
            camera_swing_done = 1;
            ufExitSystem();
        }
        break;
    case SWING_ROUND:
        return;
    }
    cameraControlWork->ang_y = camera_swing_heading;
    cameraControlWork->target.x = camera_swing_target.x;
    cameraControlWork->target.y = camera_swing_target.y;
    cameraControlWork->target.z = camera_swing_target.z;
    point_on_heading(camera_swing_distance, &cameraControlWork->pos);
}
void camera_start_swing(struct task_work *work, Float height, Float distance,
                        int swing_steps)
{
    camera_swing_done = 0;
    camera_swing_work = work;
    camera_swing_height = height;
    camera_swing_near = distance;
    camera_swing_distance = distance * 4.0F;
    camera_swing_close_step =
        (camera_swing_near - camera_swing_distance) * (1.0F / 60.0F);
    camera_swing_target.x = cameraControlWork->target.x = camera_swing_work->pos.x;
    camera_swing_target.y = cameraControlWork->target.y =
        camera_swing_work->pos.y + height;
    camera_swing_target.z = cameraControlWork->target.z = camera_swing_work->pos.z;
    camera_swing_turn = (Angle)(90.0F / swing_steps * (65536.0F / 360.0F));
    cameraControlWork->ang_x = cameraControlWork->ang_z = 0;
    camera_swing_heading = cameraControlWork->ang_y = work->ang.y + 0xa000;
    camera_swing_turned = 0;
    point_on_heading(camera_swing_distance, &cameraControlWork->pos);
    camera_swing_phase = SWING_CLOSING;
    PadReadOff();
}
void camera_step_line(struct camera_view *view)
{
    Float dx;
    Float dz;
    Float length;
    Float drop;
    dx = playertwp[0]->pos.x - view->target.x;
    dz = playertwp[0]->pos.z - view->target.z;
    length = njSqrt((dx * dx) + (dz * dz));
    drop = length * (0.3F * 1.25F);
    dx = dx / length * 40.0F;
    dz = dz / length * 40.0F;
    cameraControlWork->pos.x = playertwp[0]->pos.x + dx;
    cameraControlWork->pos.y = playertwp[0]->pos.y + 20.0F;
    cameraControlWork->pos.z = playertwp[0]->pos.z + dz;
    cameraControlWork->target.x = view->target.x;
    cameraControlWork->target.y = playertwp[0]->pos.y - drop;
    cameraControlWork->target.z = view->target.z;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c020d60(struct camera_view *view)
{
    NJS_POINT3 camera;
    NJS_VECTOR direction;
    NJS_POINT3 target;
    Float length;
    if (!view->steps) {
        if ((Uint16)view->ang_x) {
            camera_klamath_height = (Uint16)view->ang_x * 0.1F;
        } else {
            camera_klamath_height = view->distance * 0.5F;
        }
        camera_klamath_sink = 0.0F;
        camera_klamath_follows = 0;
    }
    if (camera_klamath_follows) {
        camera_step_follow(view);
        if (!(((perG[0].l) << 8) - 32768 != -32768) &&
            !(((perG[0].r) << 8) - 32768 != -32768) && !camera_player_still) {
            camera_klamath_follows = 0;
            camera_set_adjust(26);
        }
        return;
    }
    if ((((perG[0].l) << 8) - 32768 != -32768) || (((perG[0].r) << 8) - 32768 != -32768)) {
        if (pad_is_enabled()) {
            camera_klamath_follows = 1;
        }
    }
    camera = camera_twp->pos;
    target.x = view->target.x;
    target.y = playertwp[0]->pos.y;
    target.z = view->target.z;
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y = playertwp[0]->pos.y;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    direction.x = playertwp[0]->pos.x - target.x;
    direction.y = 0.0F;
    direction.z = playertwp[0]->pos.z - target.z;
    njUnitVector(&direction);
    cameraControlWork->pos.x =
        cameraControlWork->target.x + (view->distance * direction.x);
    cameraControlWork->pos.y = camera_klamath_height + cameraControlWork->target.y;
    cameraControlWork->pos.z =
        cameraControlWork->target.z + (view->distance * direction.z);
    if (((playertwp[0]->flags & (0x1 | 0x2)) == 0) &
        ((Uint16)view->ang_y == 0)) {
        camera_klamath_sink -= 0.2F;
    } else {
        camera_klamath_sink *= 0.9F;
    }
    cameraControlWork->pos.y -= camera_klamath_sink;
    direction.x = cameraControlWork->pos.x - target.x;
    direction.y = 0.0F;
    direction.z = cameraControlWork->pos.z - target.z;
    length = njUnitVector(&direction);
    cameraControlWork->target.y +=
        camera_klamath_height * (length - view->distance) / length;
    camera_push_out(&cameraControlWork->pos);
    camera_ease(&camera, &cameraControlWork->pos);
    FUN_8c01e32a(&camera, &cameraControlWork->pos);
    gravDispose3(view);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_ashland(struct camera_view *view)
{
    struct task_work *player = playertwp[0];
    if (!view->steps) {
        camera_ashland_follows = 0;
    }
    if (camera_get_mode() >= 20 &&
        camera_get_mode() <= 22) {
        if (camera_ashland_follows) {
            camera_step_follow(view);
            if (!(((perG[0].l) << 8) - 32768 != -32768) &&
                !(((perG[0].r) << 8) - 32768 != -32768) && !camera_player_still) {
                camera_ashland_follows = 0;
                camera_set_adjust(26);
            }
            return;
        }
        if ((((perG[0].l) << 8) - 32768 != -32768) ||
            (((perG[0].r) << 8) - 32768 != -32768)) {
            if (pad_is_enabled()) {
                camera_ashland_follows = 1;
            }
        }
    }
    cameraControlWork->pos.x = view->pos.x;
    cameraControlWork->pos.y = view->pos.y;
    cameraControlWork->pos.z = view->pos.z;
    cameraControlWork->target.x = player->pos.x;
    cameraControlWork->target.y = player->pos.y + 7.0F;
    cameraControlWork->target.z = player->pos.z;
    gravDispose3(view);
}
void camera_step_event(struct camera_view *view)
{
    event_camera_step();
    cameraControlWork->pos.x = camera_twp->pos.x;
    cameraControlWork->pos.y = camera_twp->pos.y;
    cameraControlWork->pos.z = camera_twp->pos.z;
    cameraControlWork->ang_x = camera_twp->ang.x;
    cameraControlWork->ang_y = camera_twp->ang.y;
    cameraControlWork->ang_z = camera_twp->ang.z;
}
void camera_step_view_target(struct camera_view *view)
{
    float dx;
    float dy;
    float dz;
    float length;
    float target_x;
    float target_y;
    float target_z;
    float player_x;
    float player_y;
    float player_z;
    target_x = view->target.x;
    target_y = view->target.y;
    target_z = view->target.z;
    player_x = playertwp[0]->pos.x;
    player_y = playertwp[0]->pos.y;
    player_z = playertwp[0]->pos.z;
    dx = player_x - target_x;
    dy = player_y - target_y + 7.5F;
    dz = player_z - target_z;
    length = njSqrt((dx * dx) + (dy * dy) + (dz * dz));
    dx = dx / length * 50.0F;
    dy = dy / length * 50.0F;
    dz = dz / length * 50.0F;
    cameraControlWork->pos.x = player_x + dx;
    cameraControlWork->pos.y = player_y + dy + 7.5F;
    cameraControlWork->pos.z = player_z + dz;
    cameraControlWork->target.x = target_x;
    cameraControlWork->target.y = target_y;
    cameraControlWork->target.z = target_z;
}
void camera_step_fixed(struct camera_view *view)
{
    cameraControlWork->pos.x = view->pos.x;
    cameraControlWork->pos.y = view->pos.y;
    cameraControlWork->pos.z = view->pos.z;
    cameraControlWork->target.x = view->target.x;
    cameraControlWork->target.y = view->target.y;
    cameraControlWork->target.z = view->target.z;
}
void FUN_8c0212c4(void)
{
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y =
        playertwp[0]->pos.y + GetPlayerWorkPointer(0)->consts.eye_height;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    cameraControlWork->distance = float_approach(cameraControlWork->distance, 8.0F, 2.0F);
    cameraControlWork->ang_x = AdjustAngle(cameraControlWork->ang_x, 0xfc00, 0x100);
    cameraControlWork->ang_z = 0;
    if (cameraControlWork->distance != 8.0F || cameraControlWork->ang_x != 0xfc00) {
        cameraControlWork->ang_y -= 0x800;
    } else {
        cameraControlWork->ang_y = AdjustAngle(
            cameraControlWork->ang_y, 0x3000 - playertwp[0]->ang.y, 0x800);
    }
    camera_place_from_target(camera_twp);
}
void camera_step_along_path(struct camera_view *view);
void camera_start_path(struct path *path, int mode, Uint32 steps)
{
    CameraSetEventCameraFunc(camera_step_along_path, 0, CAMERA_LOOK_AT);
    ((struct path_play_vars *)&(camera_twp)->vars)->path = path;
    ((struct path_play_vars *)&(camera_twp)->vars)->mode = mode;
    ((struct path_play_vars *)&(camera_twp)->vars)->steps = steps;
    ((struct path_play_vars *)&(camera_twp)->vars)->point = 0;
}
void camera_end_path(void)
{
    if (path_playing == 1) {
        CameraReleaseEventCamera();
        path_playing = 0;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_along_path(struct camera_view *view)
{
    NJS_VECTOR offset;
    NJS_VECTOR turned;
    struct GetStatusOnPath sample;
    Angle angle;
    Float distance;
    struct path *path = ((struct path_play_vars *)&(camera_twp)->vars)->path;
    int valid;
    if (!view->steps) {
        ((struct path_play_vars *)&(camera_twp)->vars)->point = 0;
        path_playing = 1;
    }
    ((struct path_play_vars *)&(camera_twp)->vars)->point++;
    valid =
        path_get_distance(path, ((struct path_play_vars *)&(camera_twp)->vars)->point, &distance);
    switch (((struct path_play_vars *)&(camera_twp)->vars)->mode) {
    case 0:
        if (!valid) {
            camera_end_path();
            return;
        }
        break;
    case 3:
        if ((Uint32)view->steps >= ((struct path_play_vars *)&(camera_twp)->vars)->steps) {
            camera_end_path();
            return;
        }
    case 1:
        if (!valid) {
            ((struct path_play_vars *)&(camera_twp)->vars)->point--;
            valid = path_get_distance(path, ((struct path_play_vars *)&(camera_twp)->vars)->point,
                                      &distance);
        }
        break;
    case 4:
        if ((Uint32)view->steps >= ((struct path_play_vars *)&(camera_twp)->vars)->steps) {
            camera_end_path();
            return;
        }
    case 2:
        if (!valid) {
            ((struct path_play_vars *)&(camera_twp)->vars)->point--;
            valid = path_get_distance(path, ((struct path_play_vars *)&(camera_twp)->vars)->point,
                                      &distance);
        }
        break;
    case 5:
    default:
        camera_end_path();
        return;
    }
    if (valid) {
        sample.distance = distance;
        GetStatusOnPath(path, &sample);
        offset.x = sample.pos.x;
        offset.y = sample.pos.y;
        offset.z = sample.pos.z;
        njPushMatrix(&nj_unit_matrix_);
        (((angle) = (-playertwp[0]->ang.y + 0x8000)) ? (njRotateY)(((void *)0), (angle)) : (void)0);
        njCalcVector(((void *)0), &offset, &turned);
        sample.pos.x = turned.x;
        sample.pos.y = turned.y;
        sample.pos.z = turned.z;
        njPopMatrix(1);
        cameraControlWork->pos.x =
            playertwp[0]->pos.x + playermwp[0]->speed.x + sample.pos.x;
        cameraControlWork->pos.y =
            playertwp[0]->pos.y + playermwp[0]->speed.y + sample.pos.y;
        cameraControlWork->pos.z =
            playertwp[0]->pos.z + playermwp[0]->speed.z + sample.pos.z;
        turned.x = turned.z = 0.0F;
        turned.y = GetPlayerWorkPointer(0)->consts.eye_height;
        player_turn_to_world(playertwp[0], &turned);
        cameraControlWork->target.x =
            playertwp[0]->pos.x + playermwp[0]->speed.x + turned.x;
        cameraControlWork->target.y =
            playertwp[0]->pos.y + playermwp[0]->speed.y + turned.y;
        cameraControlWork->target.z =
            playertwp[0]->pos.z + playermwp[0]->speed.z + turned.z;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c021700(struct camera_view *view)
{
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y =
        playertwp[0]->pos.y + GetPlayerWorkPointer(0)->consts.eye_height;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    FUN_8c01a680(camera_twp);
}
float vec3_distance_squared(const NJS_POINT3 *from, const NJS_POINT3 *to)
{
    const char *at_from = (const char *)from;
    const char *at_to = (const char *)to;
    float dx;
    float dy;
    float dz;
    dx = *(const float *)at_from - *(const float *)at_to;
    at_from += sizeof(float);
    at_to += sizeof(float);
    dy = *(const float *)at_from - *(const float *)at_to;
    at_from += sizeof(float);
    at_to += sizeof(float);
    dz = *(const float *)at_from - *(const float *)at_to;
    return (dx * dx) + (dy * dy) + (dz * dz);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int at_path_end(int index, NJS_POINT3 *point,
                       struct camera_path *stretch)
{
    int limit = stretch->path->count - 3;
    if (index >= limit || index == 0) {
        return 1;
    }
    return 0;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int path_track_point(int *index, NJS_POINT3 *out, NJS_POINT3 *point,
                            NJS_VECTOR *dir, struct camera_path *stretch)
{
    int i;
    int last;
    int next;
    NJS_POINT3 p0;
    NJS_POINT3 p1;
    NJS_POINT3 cp;
    NJS_LINE line;
    Float d0;
    Float d1;
    Float d2;
    last = stretch->path->count - 1;
    i = *index;
    if (i >= last) {
        i = last - 1;
    }
    next = i + 1;
    p0.x = stretch->path->points[i].pos.x + stretch->path_shift.x;
    p0.y = stretch->path->points[i].pos.y + stretch->path_shift.y;
    p0.z = stretch->path->points[i].pos.z + stretch->path_shift.z;
    p1.x = stretch->path->points[next].pos.x + stretch->path_shift.x;
    p1.y = stretch->path->points[next].pos.y + stretch->path_shift.y;
    p1.z = stretch->path->points[next].pos.z + stretch->path_shift.z;
    line.px = p0.x;
    line.py = p0.y;
    line.pz = p0.z;
    line.vx = p0.x - p1.x;
    line.vy = p0.y - p1.y;
    line.vz = p0.z - p1.z;
    FUN_8c63fec4(point, &line, &cp);
    d0 = vec3_distance_squared(&p0, &p1);
    d1 = vec3_distance_squared(&p0, &cp);
    d2 = vec3_distance_squared(&p1, &cp);
    if (dir) {
        dir->x = p0.x - p1.x;
        dir->y = p0.y - p1.y;
        dir->z = p0.z - p1.z;
    }
    *index = i;
    *out = cp;
    if (d1 + d2 > d0) {
        if (d1 > d2) {
            *index = i + 1;
            if (*index < last) {
                *out = p1;
            } else {
                return 0;
            }
        } else {
            *index = i > 0 ? i - 1 : 0;
            if (*index > 0) {
                *out = p0;
            } else {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
int path_nearest_index(NJS_POINT3 *point, struct camera_path *stretch)
{
    int count = stretch->path->count;
    int i;
    int nearest;
    Float best;
    Float distance;
    NJS_POINT3 shifted;
    for (i = 0; i < count; i++) {
        const char *along = (const char *)&stretch->path->points[i].pos;
        const char *shift = (const char *)&stretch->path_shift;
        shifted.x = *(const float *)along + *(const float *)shift;
        along += sizeof(float);
        shift += sizeof(float);
        shifted.y = *(const float *)along + *(const float *)shift;
        along += sizeof(float);
        shift += sizeof(float);
        shifted.z = *(const float *)along + *(const float *)shift;
        distance = vec3_distance_squared(&shifted, point);
        if (i == 0 || best > distance) {
            best = distance;
            nearest = i;
        }
    }
    return nearest;
}
extern NJS_POINT3 survey_eye_offsets[2];
extern struct camera_key cart_views[3];
extern Float follow_g_distance;
void camera_step_pose(struct camera_view *view)
{
    NJS_POINT3 pos;
    struct angles ang;
    cameraControlWork->pos.x = camera_twp->pos.x;
    cameraControlWork->pos.y = camera_twp->pos.y;
    cameraControlWork->pos.z = camera_twp->pos.z;
    cameraControlWork->ang_x = camera_twp->ang.x;
    cameraControlWork->ang_y = camera_twp->ang.y;
    cameraControlWork->ang_z = camera_twp->ang.z;
    pos.x = cameraControlWork->pos.x;
    pos.y = cameraControlWork->pos.y;
    pos.z = cameraControlWork->pos.z;
    ang.x = cameraControlWork->ang_x;
    ang.y = cameraControlWork->ang_y;
    ang.z = cameraControlWork->ang_z;
    cameraControlWork->pos.x = camera_pose_pos.x;
    cameraControlWork->pos.y = camera_pose_pos.y;
    cameraControlWork->pos.z = camera_pose_pos.z;
    cameraControlWork->ang_x = CamPathCam2Core_Angle.x;
    cameraControlWork->ang_y = CamPathCam2Core_Angle.y;
    cameraControlWork->ang_z = CamPathCam2Core_Angle.z;
    CamPathCam2Core_AliveFlag = 1;
    camera_place_at_angles(camera_twp);
}
void turn_vector(struct angles *ang, NJS_VECTOR *vector);
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c022640(struct camera_view *view)
{
    struct cameraControlWork *const *cam = &cameraControlWork;
    NJS_VECTOR ahead;
    Float turn;
    struct angles *previous;
    struct angles *offset = &taiho_turn;
    Angle angle;
    if (!view->steps) {
        offset->x = 0;
        offset->y = 0;
        offset->z = 0;
        (*cam)->pos.x = camera_place.pos.x;
        (*cam)->pos.y = camera_place.pos.y;
        (*cam)->pos.z = camera_place.pos.z;
        taiho_base.x = camera_place.ang.x;
        taiho_base.y = camera_place.ang.y;
        taiho_base.z = camera_place.ang.z;
        ahead.x = 0.0F;
        ahead.y = 0.0F;
        ahead.z = 2.0F;
        turn_vector(&taiho_base, &ahead);
        (*cam)->pos.x += ahead.x;
        (*cam)->pos.y += ahead.y;
        (*cam)->pos.z += ahead.z;
    }
    previous = &taiho_last_turn;
    *previous = taiho_turn;
    if (0) {
        (void)(1 ? (void)(taiho_base = taiho_base) : (void)0);
    }
    (&taiho_turn)->x -= (Angle)((float)(perG[0].y1 << 8) *
                                ((65536.0F / 360.0F) * (1.0F / 16000.0F)));
    offset->y -= (Angle)((float)(perG[0].x1 << 8) *
                         ((65536.0F / 360.0F) * (1.0F / 16000.0F)));
    if (offset->x > ((Angle)(((45) * 65536.0) / 360.0))) {
        offset->x = ((Angle)(((45) * 65536.0) / 360.0));
    } else if (offset->x < -((Angle)(((45) * 65536.0) / 360.0))) {
        offset->x = -((Angle)(((45) * 65536.0) / 360.0));
    }
    angle = offset->y;
    if (angle > ((Angle)(((45) * 65536.0) / 360.0))) {
        offset->y = ((Angle)(((45) * 65536.0) / 360.0));
    } else if (angle < -((Angle)(((45) * 65536.0) / 360.0))) {
        offset->y = -((Angle)(((45) * 65536.0) / 360.0));
    }
    turn = _builtin_fabsf((float)(previous->x - offset->x)) +
           _builtin_fabsf((float)(previous->y - offset->y));
    if (turn > 50.0F) {
        dsPlay_oneshot(197, 0, 0, 0);
    } else {
        dsStop_num(197);
    }
    (*cam)->ang_x = offset->x + taiho_base.x;
    (*cam)->ang_y = offset->y + taiho_base.y + 0x8000;
    (*cam)->ang_z = offset->z + taiho_base.z;
    camera_place_at_angles(camera_twp);
}
void turn_vector(struct angles *ang, NJS_VECTOR *vector)
{
    Angle angle;
    njPushMatrix(&nj_unit_matrix_);
    (((angle) = (ang->z)) ? (njRotateZ)(((void *)0), (angle)) : (void)0);
    (((angle) = (ang->x)) ? (njRotateX)(((void *)0), (angle)) : (void)0);
    (((angle) = (ang->y)) ? (njRotateY)(((void *)0), (angle)) : (void)0);
    njCalcVector(((void *)0), vector, vector);
    njPopMatrix(1);
}
extern NJS_POINT3 cart_last_pos;
extern NJS_POINT3 cart_last_target;
extern int cart_key;
extern Float cart_rise;
extern int camera_cart_action;
extern Float sonic_far;
extern Float sonic_near;
extern Float sonic_far_limit;
extern Float sonic_near_limit;
extern Angle sonic_pitch;
extern int sonic_drift;
enum sonic_state {
    SONIC_START,
    SONIC_FOLLOW,
    SONIC_DRIFT,
    SONIC_DRIFTED
};
extern int sonic_state;
extern NJS_POINT3 sonic_last_pos;
extern int sonic_triggers_idle;
extern int sonic_slide_steps;
extern struct task_work *e103_target;
extern NJS_POINT3 *e103_line;
extern struct angles ease_off_aim;
extern struct angles ease_aim;
extern struct angles ease_limit;
extern Float ease_part;
extern NJS_POINT3 ease_start_move;
extern Float ease_steps;
extern int ease_blend;
extern int ease_sweeps;
extern int dat_8c6c0e68;
void cart_view_above(Float height);
void FUN_8c022d60(void);
void FUN_8c022dec(void);
void cart_ease_target(void);
void cart_ease_both(void);
void cart_keep_last(void);
void cart_play_keys(struct camera_view *view);
void FUN_8c023212(struct camera_view *view, NJS_POINT3 *out,
                            NJS_POINT3 *target);
void cart_orbit(struct camera_view *view);
void FUN_8c023960(void);
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c022ae2(struct camera_view *view)
{
    NJS_POINT3 previous;
    if (!view->steps) {
        cameraControlWork->view = 1;
        cart_last_pos = playertwp[0]->pos;
        cart_last_target = playertwp[0]->pos;
        cart_last_pos.y += GetPlayerWorkPointer(0)->consts.eye_height;
    }
    if (camera_cart_action == 1) {
        camera_set_adjust(0);
        camera_set_type(CAMERA_LOOK_AT);
        cart_play_keys(view);
    } else if (camera_cart_action == 2) {
        camera_set_adjust(0);
        cart_orbit(view);
        camera_set_type(CAMERA_FROM_TARGET);
        cart_key = 0;
    } else {
        cart_key = 0;
        camera_set_type(CAMERA_LOOK_AT);
        previous = camera_twp->pos;
        switch (cameraControlWork->view) {
        case 0:
            cart_view_above(GetPlayerWorkPointer(0)->consts.eye_height * 0.25F);
            FUN_8c022d60();
            FUN_8c022dec();
            cart_ease_target();
            break;
        case 1:
            if (camera_place.target.x != 0.0F) {
                cart_rise += 0.5F;
            } else {
                cart_rise = 0.0F;
            }
            cart_view_above(GetPlayerWorkPointer(0)->consts.eye_height);
            FUN_8c022d60();
            FUN_8c022dec();
            cart_ease_both();
            break;
        case 2:
            cart_view_above(GetPlayerWorkPointer(0)->consts.eye_height);
            FUN_8c022d60();
            FUN_8c022dec();
            cart_ease_both();
            break;
        default:
            cameraControlWork->view = 1;
            return;
            break;
        }
        cameraControlWork->ang_z = 0;
        FUN_8c01e32a(&previous, &cameraControlWork->pos);
        cart_keep_last();
        if (per[0]->press & (1 << 4)) {
            cameraControlWork->view++;
            if (cameraControlWork->view >= 3) {
                cameraControlWork->view = 0;
            }
        } else if (per[0]->press & (1 << 5)) {
            cameraControlWork->view--;
            if (cameraControlWork->view < 0) {
                cameraControlWork->view = 2;
            }
        }
    }
}
void cart_view_above(Float height)
{
    cameraControlWork->pos.x = camera_place.pos.x;
    cameraControlWork->pos.y = camera_place.pos.y + height + cart_rise;
    cameraControlWork->pos.z = camera_place.pos.z;
    cameraControlWork->target.x = camera_place.pos.x;
    cameraControlWork->target.y = camera_place.pos.y;
    cameraControlWork->target.z = camera_place.pos.z;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c022d60(void)
{
    NJS_VECTOR offset;
    offset = cart_views[cameraControlWork->view].pos;
    turn_vector(&camera_place.ang, &offset);
    cameraControlWork->pos.x += offset.x;
    cameraControlWork->pos.y += offset.y;
    cameraControlWork->pos.z += offset.z;
}
void FUN_8c022dec(void)
{
    NJS_VECTOR offset;
    offset = cart_views[cameraControlWork->view].target;
    turn_vector(&camera_place.ang, &offset);
    cameraControlWork->target.x += offset.x;
    cameraControlWork->target.y += offset.y;
    cameraControlWork->target.z += offset.z;
}
void cart_ease_target(void)
{
    cameraControlWork->pos.x = cameraControlWork->pos.x;
    cameraControlWork->pos.y = cameraControlWork->pos.y;
    cameraControlWork->pos.z = cameraControlWork->pos.z;
    cameraControlWork->target.x =
        cart_last_target.x +
        ((cameraControlWork->target.x - cart_last_target.x) * 0.2F);
    cameraControlWork->target.y =
        cart_last_target.y +
        ((cameraControlWork->target.y - cart_last_target.y) * 0.2F);
    cameraControlWork->target.z =
        cart_last_target.z +
        ((cameraControlWork->target.z - cart_last_target.z) * 0.2F);
}
void cart_ease_both(void)
{
    cameraControlWork->pos.x =
        cart_last_pos.x + ((cameraControlWork->pos.x - cart_last_pos.x) * 0.2F);
    cameraControlWork->pos.y =
        cart_last_pos.y + ((cameraControlWork->pos.y - cart_last_pos.y) * 0.2F);
    cameraControlWork->pos.z =
        cart_last_pos.z + ((cameraControlWork->pos.z - cart_last_pos.z) * 0.2F);
    cameraControlWork->target.x =
        cart_last_target.x +
        ((cameraControlWork->target.x - cart_last_target.x) * 0.2F);
    cameraControlWork->target.y =
        cart_last_target.y +
        ((cameraControlWork->target.y - cart_last_target.y) * 0.2F);
    cameraControlWork->target.z =
        cart_last_target.z +
        ((cameraControlWork->target.z - cart_last_target.z) * 0.2F);
}
void cart_keep_last(void)
{
    cart_last_pos.x = cameraControlWork->pos.x;
    cart_last_pos.y = cameraControlWork->pos.y;
    cart_last_pos.z = cameraControlWork->pos.z;
    cart_last_target.x = cameraControlWork->target.x;
    cart_last_target.y = cameraControlWork->target.y;
    cart_last_target.z = cameraControlWork->target.z;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void cart_play_keys(struct camera_view *view)
{
    struct camera_key *keys = camera_place.args[0].keys;
    int mode;
    if (cart_key == camera_place.args[1].last + 70) {
        camera_cart_action = 0;
        cameraControlWork->view = 1;
        cameraControlWork->pos.x =
            cart_last_pos.x + ((cameraControlWork->pos.x - cart_last_pos.x) * 0.05F);
        cameraControlWork->pos.y =
            cart_last_pos.y + ((cameraControlWork->pos.y - cart_last_pos.y) * 0.05F);
        cameraControlWork->pos.z =
            cart_last_pos.z + ((cameraControlWork->pos.z - cart_last_pos.z) * 0.05F);
        cameraControlWork->target.x =
            cart_last_target.x +
            ((cameraControlWork->target.x - cart_last_target.x) * 0.05F);
        cameraControlWork->target.y =
            cart_last_target.y +
            ((cameraControlWork->target.y - cart_last_target.y) * 0.05F);
        cameraControlWork->target.z =
            cart_last_target.z +
            ((cameraControlWork->target.z - cart_last_target.z) * 0.05F);
    } else if (cart_key > camera_place.args[1].last + 10) {
        mode = cameraControlWork->view;
        cameraControlWork->view = 1;
        cart_view_above(GetPlayerWorkPointer(0)->consts.eye_height);
        FUN_8c022d60();
        FUN_8c022dec();
        cameraControlWork->view = mode;
        cameraControlWork->pos.x =
            cart_last_pos.x + ((cameraControlWork->pos.x - cart_last_pos.x) * 0.05F);
        cameraControlWork->pos.y =
            cart_last_pos.y + ((cameraControlWork->pos.y - cart_last_pos.y) * 0.05F);
        cameraControlWork->pos.z =
            cart_last_pos.z + ((cameraControlWork->pos.z - cart_last_pos.z) * 0.05F);
        cameraControlWork->target.x =
            cart_last_target.x +
            ((cameraControlWork->target.x - cart_last_target.x) * 0.05F);
        cameraControlWork->target.y =
            cart_last_target.y +
            ((cameraControlWork->target.y - cart_last_target.y) * 0.05F);
        cameraControlWork->target.z =
            cart_last_target.z +
            ((cameraControlWork->target.z - cart_last_target.z) * 0.05F);
    } else if (cart_key <= camera_place.args[1].last) {
        cameraControlWork->pos.x = keys[cart_key].pos.x;
        cameraControlWork->pos.y = keys[cart_key].pos.y;
        cameraControlWork->pos.z = keys[cart_key].pos.z;
        cameraControlWork->target.x = keys[cart_key].target.x;
        cameraControlWork->target.y = keys[cart_key].target.y;
        cameraControlWork->target.z = keys[cart_key].target.z;
    }
    cart_key++;
    cart_keep_last();
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void cart_orbit(struct camera_view *view)
{
    NJS_POINT3 *out = camera_place.args[0].point;
    NJS_POINT3 *target = camera_place.args[1].point;
    FUN_8c023212(view, out, target);
}
void FUN_8c023212(struct camera_view *view, NJS_POINT3 *out,
                            NJS_POINT3 *target)
{
    Sint16 x;
    Sint16 y;
    unsigned short right;
    unsigned short left;
    cameraControlWork->target.x = target->x;
    cameraControlWork->target.y = target->y;
    cameraControlWork->target.z = target->z;
    cameraControlWork->ang_z = 0;
    if (perG[1].on & (1 << 3)) {
        x = per[1]->x1 << 8;
        y = per[1]->y1 << 8;
        if (x > -5000 && x < 5000) {
            x = 0;
        }
        if (y > -5000 && y < 5000) {
            y = 0;
        }
        right = ((Sint16)per[1]->r << 8) + 0x8000;
        left = ((Sint16)per[1]->l << 8) + 0x8000;
        cameraControlWork->ang_y += x / 64;
        cameraControlWork->ang_x += y / 64;
        if (perG[1].on & (1 << 17)) {
            cameraControlWork->distance += 2.0F;
        } else if (perG[1].on & (1 << 16)) {
            cameraControlWork->distance -= 2.0F;
        }
    }
    if (cameraControlWork->distance < 5.0F) {
        cameraControlWork->distance = 5.0F;
    }
    camera_place_from_target(camera_twp);
    *out = camera_twp->pos;
}
extern const NJS_VECTOR trail_offset;
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_follow(struct camera_view *view)
{
    NJS_POINT3 previous;
    NJS_VECTOR vector;
    NJS_POINT3 *eye;
    Angle *pitch;
    Float distance;
    Sint16 turn;
    if (!view->steps) {
        cameraControlWork->target.x = playertwp[0]->pos.x;
        cameraControlWork->target.y = playertwp[0]->pos.y;
        cameraControlWork->target.z = playertwp[0]->pos.z;
    }
    previous = camera_twp->pos;
    eye = &vector;
    *eye = playertwp[0]->pos;
    eye->y += GetPlayerWorkPointer(0)->consts.eye_height;
    eye->x += playermwp[0]->speed.x * 8.0F;
    eye->y += playermwp[0]->speed.y * 8.0F;
    eye->z += playermwp[0]->speed.z * 8.0F;
    cameraControlWork->target.x += (eye->x - cameraControlWork->target.x) * 0.1F;
    cameraControlWork->target.y += (eye->y - cameraControlWork->target.y) * 0.1F;
    cameraControlWork->target.z += (eye->z - cameraControlWork->target.z) * 0.1F;
    if (camera_get_mode() >= 8 &&
        camera_get_mode() <= 11) {
        if (camera_get_steps() < 5) {
            struct angles ang;
            vector = trail_offset;
            ang.x = ((Angle)(((-20) * 65536.0) / 360.0));
            ang.y = 0x4000 - playertwp[0]->ang.y;
            ang.z = 0;
            turn_vector(&ang, &vector);
            cameraControlWork->pos.x = playertwp[0]->pos.x + vector.x;
            cameraControlWork->pos.y = playertwp[0]->pos.y - vector.y;
            cameraControlWork->pos.z = playertwp[0]->pos.z + vector.z;
        } else if ((Sint16)angle_difference(-0x4000 - playertwp[0]->ang.y,
                                            camera_twp->ang.y) > 0) {
            cameraControlWork->pos.x -= njCos(camera_twp->ang.y) * 0.2F;
            cameraControlWork->pos.z += njSin(camera_twp->ang.y) * 0.2F;
        } else {
            cameraControlWork->pos.x += njCos(camera_twp->ang.y) * 0.2F;
            cameraControlWork->pos.z -= njSin(camera_twp->ang.y) * 0.2F;
        }
    }
    pitch = &camera_twp->ang.x;
    turn = angle_difference(((Angle)(((-20) * 65536.0) / 360.0)), *pitch);
    if (turn < 0) {
        turn = -turn;
    }
    if (turn > ((Angle)(((10) * 65536.0) / 360.0))) {
        *pitch = AdjustAngle(*pitch, ((Angle)(((-20) * 65536.0) / 360.0)), ((Angle)(((1) * 65536.0) / 360.0)));
        cameraControlWork->pos.y += njSin(*pitch - ((Angle)(((-20) * 65536.0) / 360.0))) * 1.0F;
    }
    if (perG[0].on & (1 << 16)) {
        cameraControlWork->pos.x += njCos(camera_twp->ang.y) * 2.0F;
        cameraControlWork->pos.z -= njSin(camera_twp->ang.y) * 2.0F;
        FUN_8c023960();
    }
    if (perG[0].on & (1 << 17)) {
        cameraControlWork->pos.x -= njCos(camera_twp->ang.y) * 2.0F;
        cameraControlWork->pos.z += njSin(camera_twp->ang.y) * 2.0F;
        FUN_8c023960();
    }
    vector.x = playertwp[0]->pos.x - cameraControlWork->pos.x;
    vector.y = playertwp[0]->pos.y - cameraControlWork->pos.y;
    vector.z = playertwp[0]->pos.z - cameraControlWork->pos.z;
    distance = njScalor(&vector);
    njUnitVector(&vector);
    if (distance > 60.0F) {
        distance = 60.0F + ((distance - 60.0F) * 0.9F);
        if (distance > 90.0F) {
            NJS_VECTOR ray;
            NJS_POINT3 from;
            from = previous;
            ray.x = playertwp[0]->pos.x - previous.x;
            ray.y = playertwp[0]->pos.y - previous.y;
            ray.z = playertwp[0]->pos.z - previous.z;
            njUnitVector(&ray);
            ray.x *= 10.0F;
            ray.y *= 20.0F;
            ray.z *= 10.0F;
            if (camera_sweep_hits(&from, &ray, ((void *)0), 4.0F)) {
                if (njScalor(&ray) < 3.0F) {
                    distance = 20.0F;
                } else {
                    distance = 90.0F;
                }
            } else {
                distance = 90.0F;
            }
        }
    } else if (distance < 35.0F) {
        distance *= 1.06F;
        if (distance < 20.0F) {
            distance = 20.0F;
        }
    }
    cameraControlWork->pos.x = playertwp[0]->pos.x - (vector.x * distance);
    cameraControlWork->pos.y = playertwp[0]->pos.y - (vector.y * distance);
    cameraControlWork->pos.z = playertwp[0]->pos.z - (vector.z * distance);
    if (cameraControlWork->pos.y > playertwp[0]->pos.y) {
        vector.x = cameraControlWork->pos.x - playertwp[0]->pos.x;
        vector.z = cameraControlWork->pos.z - playertwp[0]->pos.z;
        if ((vector.x * vector.x) + (vector.z * vector.z) < 900.0F) {
            vector.y = 0.0F;
            njUnitVector(&vector);
            cameraControlWork->pos.x = (vector.x * 30.0F) + playertwp[0]->pos.x;
            cameraControlWork->pos.z = (vector.z * 30.0F) + playertwp[0]->pos.z;
        }
    }
    camera_push_out(&cameraControlWork->pos);
    FUN_8c01b782(&previous, &cameraControlWork->pos);
    FUN_8c01e32a(&previous, &cameraControlWork->pos);
    gravDispose3(view);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c023960(void)
{
    switch (FUN_8c01b406()) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
        camera_set_adjust(17);
        break;
    case 6:
    case 7:
    case 16:
    case 17:
        break;
    }
}
void camera_step_fishing_point(struct camera_view *view)
{
    NJS_POINT3 previous;
    NJS_VECTOR away;
    previous = camera_twp->pos;
    cameraControlWork->target.x = camera_place.target.x;
    cameraControlWork->target.y = camera_place.target.y;
    cameraControlWork->target.z = camera_place.target.z;
    away.x = playertwp[0]->pos.x - cameraControlWork->target.x;
    away.y = playertwp[0]->pos.y - cameraControlWork->target.y + 20.0F;
    away.z = playertwp[0]->pos.z - cameraControlWork->target.z;
    njUnitVector(&away);
    away.x *= 50.0F;
    away.y *= 50.0F;
    away.z *= 50.0F;
    cameraControlWork->pos.x = playertwp[0]->pos.x + away.x;
    cameraControlWork->pos.y = playertwp[0]->pos.y + away.y + 20.0F;
    cameraControlWork->pos.z = playertwp[0]->pos.z + away.z;
    camera_push_out(&cameraControlWork->pos);
    camera_ease(&previous, &cameraControlWork->pos);
    FUN_8c01e32a(&previous, &cameraControlWork->pos);
    cameraControlWork->ang_z = 0;
}
void camera_step_two_hares(struct camera_view *view)
{
    NJS_POINT3 position;
    NJS_POINT3 target;
    NJS_VECTOR offset;
    NJS_VECTOR direction;
    Float distance;
    position = camera_place.pos;
    target = camera_place.target;
    cameraControlWork->target.x = (position.x + target.x) * 0.5F;
    cameraControlWork->target.y = (position.y + target.y) * 0.5F;
    cameraControlWork->target.z = (position.z + target.z) * 0.5F;
    offset.x = cameraControlWork->pos.x - cameraControlWork->target.x;
    offset.y = cameraControlWork->pos.y - cameraControlWork->target.y;
    offset.z = cameraControlWork->pos.z - cameraControlWork->target.z;
    direction.x = position.x - target.x;
    direction.y = position.y - target.y;
    direction.z = position.z - target.z;
    distance = njScalor(&direction) * 2.0F;
    njUnitVector(&offset);
    cameraControlWork->pos.x = cameraControlWork->target.x + (offset.x * distance);
    cameraControlWork->pos.y = cameraControlWork->target.y + (offset.y * distance);
    cameraControlWork->pos.z = cameraControlWork->target.z + (offset.z * distance);
}
void FUN_8c023c98(void);
void camera_target_follow(void);
void camera_pitch_ease(void);
void sonic_slide(void);
void sonic_keep_distance(void);
void FUN_8c0242ee(void);
void FUN_8c024460(void);
void FUN_8c024486(void);
void camera_step_sonic_p(struct camera_view *view)
{
    if (!view->steps) {
        sonic_state = SONIC_START;
    }
    sonic_far = view->target.x;
    sonic_near = view->target.y;
    sonic_far_limit = view->target.z;
    sonic_near_limit = view->distance;
    sonic_pitch = (Uint16)view->ang_x;
    sonic_drift = (Uint16)view->ang_y;
    FUN_8c023c98();
}
void camera_step_sonic(struct camera_view *view)
{
    if (!view->steps) {
        sonic_state = SONIC_START;
    }
    sonic_far = 60.0F;
    sonic_near = 35.0F;
    sonic_far_limit = 90.0F;
    sonic_near_limit = 20.0F;
    sonic_pitch = ((Angle)(((-20) * 65536.0) / 360.0));
    sonic_drift = 0;
    FUN_8c023c98();
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c023c98(void)
{
    switch (sonic_state) {
    case SONIC_START:
        sonic_slide_steps = 0;
        cameraControlWork->target.x = playertwp[0]->pos.x;
        cameraControlWork->target.y = playertwp[0]->pos.y;
        cameraControlWork->target.z = playertwp[0]->pos.z;
        sonic_state = SONIC_FOLLOW;
    case SONIC_FOLLOW:
        sonic_last_pos = camera_twp->pos;
        camera_target_follow();
        camera_pitch_ease();
        sonic_slide();
        sonic_keep_distance();
        FUN_8c0242ee();
        FUN_8c024460();
        if (camera_player_still == 1) {
            sonic_state = SONIC_DRIFT;
        }
        break;
    case SONIC_DRIFT:
        sonic_last_pos = camera_twp->pos;
        camera_target_follow();
        camera_pitch_ease();
        sonic_slide();
        FUN_8c024486();
        sonic_keep_distance();
        FUN_8c0242ee();
        FUN_8c024460();
        if (sonic_slide_steps || !sonic_triggers_idle) {
            sonic_state = SONIC_DRIFTED;
        }
        if (!camera_player_still) {
            sonic_state = SONIC_FOLLOW;
        }
        break;
    case SONIC_DRIFTED:
        sonic_last_pos = camera_twp->pos;
        camera_target_follow();
        camera_pitch_ease();
        sonic_slide();
        sonic_keep_distance();
        FUN_8c0242ee();
        FUN_8c024460();
        if (!camera_player_still) {
            sonic_state = SONIC_FOLLOW;
        }
        break;
    }
}
void camera_target_follow(void)
{
    NJS_POINT3 aim;
    aim = playertwp[0]->pos;
    aim.y += GetPlayerWorkPointer(0)->consts.eye_height;
    aim.x += playermwp[0]->speed.x * 8.0F;
    aim.y += playermwp[0]->speed.y * 8.0F;
    aim.z += playermwp[0]->speed.z * 8.0F;
    cameraControlWork->target.x += (aim.x - cameraControlWork->target.x) * 0.1F;
    cameraControlWork->target.y += (aim.y - cameraControlWork->target.y) * 0.1F;
    cameraControlWork->target.z += (aim.z - cameraControlWork->target.z) * 0.1F;
}
void camera_pitch_ease(void)
{
    Angle *ang_x = &camera_twp->ang.x;
    Sint16 diff;
    diff = angle_difference(sonic_pitch, *ang_x);
    if (diff < 0) {
        diff = -diff;
    }
    if (diff > ((Angle)(((10) * 65536.0) / 360.0))) {
        *ang_x = AdjustAngle(*ang_x, sonic_pitch, ((Angle)(((1) * 65536.0) / 360.0)));
        if (cameraControlWork->pos.y < playertwp[0]->pos.y) {
            cameraControlWork->pos.y = playertwp[0]->pos.y;
        } else {
            cameraControlWork->pos.y += njSin(*ang_x - sonic_pitch) * 1.0F;
        }
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void sonic_slide(void)
{
    sonic_triggers_idle = 1;
    if ((perG[0].on & (1 << 16)) || sonic_slide_steps > 0) {
        cameraControlWork->pos.x += njCos(camera_twp->ang.y) * 2.0F;
        cameraControlWork->pos.z -= njSin(camera_twp->ang.y) * 2.0F;
        if (sonic_slide_steps) {
            sonic_slide_steps--;
            cameraControlWork->pos.y += 0.25F;
        } else {
            sonic_triggers_idle = 0;
        }
    }
    if ((perG[0].on & (1 << 17)) || sonic_slide_steps < 0) {
        cameraControlWork->pos.x -= njCos(camera_twp->ang.y) * 2.0F;
        cameraControlWork->pos.z += njSin(camera_twp->ang.y) * 2.0F;
        if (sonic_slide_steps) {
            sonic_slide_steps++;
            cameraControlWork->pos.y += 0.25F;
        } else {
            sonic_triggers_idle = 0;
        }
    }
}
void sonic_keep_distance(void)
{
    NJS_VECTOR to_player;
    NJS_VECTOR ray;
    NJS_POINT3 from;
    Float distance;
    to_player.x = playertwp[0]->pos.x - cameraControlWork->pos.x;
    to_player.y = playertwp[0]->pos.y - cameraControlWork->pos.y;
    to_player.z = playertwp[0]->pos.z - cameraControlWork->pos.z;
    distance = njScalor(&to_player);
    njUnitVector(&to_player);
    if (distance > sonic_far) {
        distance = sonic_far + ((distance - sonic_far) * 0.9F);
        if (distance > sonic_far_limit) {
            from = sonic_last_pos;
            ray.x = playertwp[0]->pos.x - sonic_last_pos.x;
            ray.y = playertwp[0]->pos.y - sonic_last_pos.y;
            ray.z = playertwp[0]->pos.z - sonic_last_pos.z;
            njUnitVector(&ray);
            ray.x *= 10.0F;
            ray.y *= 20.0F;
            ray.z *= 10.0F;
            if (camera_sweep_hits(&from, &ray, ((void *)0), 4.0F)) {
                distance = sonic_near_limit;
            } else {
                distance = sonic_far_limit;
            }
        }
    } else if (distance < sonic_near) {
        distance *= 1.06F;
        if (distance < sonic_near_limit) {
            distance = sonic_near_limit;
        }
    }
    cameraControlWork->pos.x = playertwp[0]->pos.x - (to_player.x * distance);
    cameraControlWork->pos.y = playertwp[0]->pos.y - (to_player.y * distance);
    cameraControlWork->pos.z = playertwp[0]->pos.z - (to_player.z * distance);
    if (cameraControlWork->pos.y > playertwp[0]->pos.y) {
        to_player.x = cameraControlWork->pos.x - playertwp[0]->pos.x;
        to_player.z = cameraControlWork->pos.z - playertwp[0]->pos.z;
        if ((to_player.x * to_player.x) + (to_player.z * to_player.z) <
            900.0F) {
            to_player.y = 0.0F;
            njUnitVector(&to_player);
            cameraControlWork->pos.x = (to_player.x * 30.0F) + playertwp[0]->pos.x;
            cameraControlWork->pos.z = (to_player.z * 30.0F) + playertwp[0]->pos.z;
        }
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c0242ee(void)
{
    NJS_VECTOR offset;
    NJS_VECTOR vector;
    NJS_POINT3 position;
    if (sonic_slide_steps) {
        return;
    }
    if (!sonic_triggers_idle) {
        return;
    }
    position.x = cameraControlWork->pos.x;
    position.y = cameraControlWork->pos.y;
    position.z = cameraControlWork->pos.z;
    offset.x = playertwp[0]->pos.x - cameraControlWork->pos.x;
    offset.y = playertwp[0]->pos.y + GetPlayerWorkPointer(0)->consts.eye_height -
               cameraControlWork->pos.y;
    offset.z = playertwp[0]->pos.z - cameraControlWork->pos.z;
    vector = offset;
    if (!camera_sweep_hits(&position, &vector, ((void *)0), 4.0F)) {
        return;
    }
    if ((angle_difference(
             (Angle)(njArcTan2(offset.z, offset.x) * (65536.0 / (2 * 3.141592))),
             (Angle)(njArcTan2(vector.z, vector.x) * (65536.0 / (2 * 3.141592)))) &
         0xffff) > 0x8000) {
        sonic_slide_steps = -30;
    } else {
        sonic_slide_steps = 30;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c024460(void)
{
    camera_push_out(&cameraControlWork->pos);
    FUN_8c01b782(&sonic_last_pos, &cameraControlWork->pos);
    FUN_8c01e32a(&sonic_last_pos, &cameraControlWork->pos);
}
void FUN_8c024486(void)
{
    Angle distance = DiffAngle(0, camera_twp->ang.y);
    if (sonic_drift && distance > ((Angle)(((5) * 65536.0) / 360.0))) {
        if ((Sint16)angle_difference(0, camera_twp->ang.y) > 0) {
            cameraControlWork->pos.x -= njCos(camera_twp->ang.y) * 0.5F;
            cameraControlWork->pos.z += njSin(camera_twp->ang.y) * 0.5F;
        } else {
            cameraControlWork->pos.x += njCos(camera_twp->ang.y) * 0.5F;
            cameraControlWork->pos.z -= njSin(camera_twp->ang.y) * 0.5F;
        }
    }
}
void camera_step_fixed_rolled(struct camera_view *view)
{
    cameraControlWork->target.x = view->target.x;
    cameraControlWork->target.y = view->target.y;
    cameraControlWork->target.z = view->target.z;
    cameraControlWork->pos.x = view->pos.x;
    cameraControlWork->pos.y = view->pos.y;
    cameraControlWork->pos.z = view->pos.z;
    cameraControlWork->ang_z = 0;
    gravDispose3(view);
}
void InitCartGoalCamFunc(struct camera_view *view)
{
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c024586(struct camera_view *view)
{
    NJS_POINT3 previous;
    previous = camera_twp->pos;
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y =
        playertwp[0]->pos.y + GetPlayerWorkPointer(0)->consts.eye_height;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    if (perG[0].on & (1 << 16)) {
        cameraControlWork->ang_y += 0x222;
    } else if (perG[0].on & (1 << 17)) {
        cameraControlWork->ang_y -= 0x222;
    }
    cameraControlWork->distance = view->distance;
    cameraControlWork->ang_x = ((Angle)(((-20) * 65536.0) / 360.0));
    camera_place_from_target(camera_twp);
    cameraControlWork->pos.x = camera_twp->pos.x;
    cameraControlWork->pos.y = camera_twp->pos.y;
    cameraControlWork->pos.z = camera_twp->pos.z;
    cameraControlWork->ang_x = camera_twp->ang.x;
    cameraControlWork->ang_y = camera_twp->ang.y;
    cameraControlWork->ang_z = 0;
    if (!FUN_8c01b5e0()) {
        FUN_8c01e32a(&previous, &cameraControlWork->pos);
    }
}
void camera_step_leave(struct camera_view *view)
{
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y = playertwp[0]->pos.y;
    cameraControlWork->target.z = playertwp[0]->pos.z;
}
void camera_step_work_view(struct camera_view *view)
{
    cameraControlWork->pos.x = camera_twp->scl.x;
    cameraControlWork->pos.y = camera_twp->scl.y;
    cameraControlWork->pos.z = camera_twp->scl.z;
    cameraControlWork->target.x = ((union camera_vars *)&(camera_twp)->vars)->target.x;
    cameraControlWork->target.y = ((union camera_vars *)&(camera_twp)->vars)->target.y;
    cameraControlWork->target.z = ((union camera_vars *)&(camera_twp)->vars)->target.z;
    cameraControlWork->ang_z = 0;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c024768(struct camera_view *view)
{
    Float *gravity = &vG.x;
    Float gx;
    Float gy;
    Float gz;
    Float across;
    Angle ang_x;
    Angle ang_y;
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y = playertwp[0]->pos.y +
                             GetPlayerWorkPointer(0)->consts.eye_height +
                             (cameraControlWork->distance * 0.06F);
    cameraControlWork->target.z = playertwp[0]->pos.z;
    cameraControlWork->distance = follow_g_distance;
    gx = *gravity++;
    gy = *gravity++;
    gz = *gravity;
    if (gx == 0.0F && gz == 0.0F) {
        cameraControlWork->ang_x = (-0x800);
    } else {
        across = njSqrt((gx * gx) + (gz * gz));
        ang_y = (Angle)(njArcTan2(gx, gz) * (65536.0 / (2 * 3.141592)));
        ang_x = (Angle)(njArcTan2(across, -gy) * (65536.0 / (2 * 3.141592)));
        cameraControlWork->ang_x = (-0x800) - ang_x;
        cameraControlWork->ang_y = ang_y;
    }
    cameraControlWork->ang_z = 0;
    if (((struct player_vars *)&(playertwp[0])->vars)->character == 3 &&
        playertwp[0]->mode == KNUCKLES_PUSH) {
        cameraControlWork->ang_y +=
            angle_difference(cameraControlWork->ang_y,
                             0xc000 - playertwp[0]->ang.y) >>
            2;
    } else if (perG[0].on & (1 << 9)) {
        if (perG[0].on & (1 << 17)) {
            follow_g_distance += 2.0F;
        } else if (perG[0].on & (1 << 16)) {
            follow_g_distance -= 2.0F;
        }
    } else if (perG[0].on & (1 << 17)) {
        cameraControlWork->flags |= 0x1;
        cameraControlWork->ang_y -= 0x200;
    } else if (perG[0].on & (1 << 16)) {
        cameraControlWork->flags |= 0x1;
        cameraControlWork->ang_y += 0x200;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_step_e103(struct camera_view *view)
{
    NJS_VECTOR half;
    NJS_POINT3 point;
    NJS_LINE line;
    NJS_POINT3 *player = &playertwp[0]->pos;
    Float distance;
    half.x = (e103_target->pos.x - player->x) * 0.5F;
    half.y = (e103_target->pos.y - player->y) * 0.5F;
    half.z = (e103_target->pos.z - player->z) * 0.5F;
    cameraControlWork->target.x = player->x + half.x;
    cameraControlWork->target.z = player->z + half.z;
    cameraControlWork->target.y = player->y + half.y;
    line.px = e103_line[0].x;
    line.py = e103_line[0].y;
    line.pz = e103_line[0].z;
    line.vx = e103_line[1].x - e103_line[0].x;
    line.vy = e103_line[1].y - e103_line[0].y;
    line.vz = e103_line[1].z - e103_line[0].z;
    FUN_8c63fec4(&cameraControlWork->target, &line, &point);
    distance = CalcDistance(&e103_target->pos, &playertwp[0]->pos);
    if (distance < 100.0F) {
        distance = 100.0F;
    } else if (distance > 350.0F) {
        distance = 350.0F;
    }
    point.x -= cameraControlWork->target.x;
    point.y -= cameraControlWork->target.y;
    point.z -= cameraControlWork->target.z;
    njUnitVector(&point);
    ((&point)->x = (&point)->x * (distance), (&point)->y = (&point)->y * (distance), (&point)->z = (&point)->z * (distance));
    point.x += cameraControlWork->target.x;
    point.y += cameraControlWork->target.y;
    point.z += cameraControlWork->target.z;
    cameraControlWork->pos.x = point.x;
    cameraControlWork->pos.y = point.y;
    cameraControlWork->pos.z = point.z;
    if (cameraControlWork->pos.y <= player->y + 14.0F) {
        cameraControlWork->pos.y = player->y + 14.0F;
    }
}
void camera_adjust_none(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust)
{
    Float dx;
    Float dy;
    Float dz;
    Float distance;
    dx = work->pos.x - last->pos.x;
    dy = work->pos.y - last->pos.y;
    dz = work->pos.z - last->pos.z;
    distance = njSqrt((dx * dx) + (dy * dy) + (dz * dz));
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c024dca(struct task_work *work, struct task_work *last,
                          struct camera_adjust_work *adjust)
{
    Float player_distance;
    Float distance_gap;
    NJS_POINT3 past;
    NJS_POINT3 position;
    Float distance;
    Angle diff;
    Angle turn;
    Angle limit;
    position = work->pos;
    player_distance = CalcDistance(&work->pos, &playertwp[0]->pos);
    GetPlayerPosition(0, 2, &past, ((void *)0));
    distance = CalcDistance(&last->pos, &past);
    distance_gap = player_distance - distance;
    distance += distance_gap * 0.3F;
    if (distance < 20.0F) {
        distance = 20.0F;
    }
    if (0) {
        adjust->turn_x = 0;
        adjust->turn_y = 0;
        adjust->turn_x = 0;
        adjust->turn_y = 0;
    }
    if (cameraControlWork->flags & 0x1) {
        cameraControlWork->flags &= ~0x1;
    } else {
        diff = work->ang.y - last->ang.y;
        if (diff & 0x8000) {
            diff |= 0xffff0000;
        } else {
            diff = (Uint16)diff;
        }
        if (diff > -64 && diff < 64) {
            cameraControlWork->ang_y = work->ang.y;
            adjust->turn_y = 0;
            adjust->flags &= ~0x40;
        } else {
            turn = diff >> 2;
            if (diff < 0) {
                limit = adjust->turn_y - 64;
                if (0) {
                    adjust->turn_y = limit;
                    adjust->turn_y = limit;
                }
                if (turn > limit) {
                    diff = turn;
                } else {
                    diff = limit;
                }
                if (diff <= -0x100) {
                    diff = -0x100;
                } else {
                }
                adjust->turn_y = diff;
                cameraControlWork->ang_y = diff + last->ang.y;
            } else {
                limit = adjust->turn_y + 64;
                if (0) {
                    adjust->turn_y = limit;
                    adjust->turn_y = limit;
                }
                if (turn < limit) {
                    diff = turn;
                } else {
                    diff = limit;
                }
                if (diff >= 0x100) {
                    diff = 0x100;
                } else {
                }
                adjust->turn_y = diff;
                cameraControlWork->ang_y = diff + last->ang.y;
            }
        }
    }
    diff = work->ang.x - last->ang.x;
    if (diff & 0x8000) {
        diff |= 0xffff0000;
    } else {
        diff = (Uint16)diff;
    }
    if (diff > -128 && diff < 128) {
        cameraControlWork->ang_x = work->ang.x;
        adjust->turn_x = 0;
        adjust->flags &= ~0x20;
    } else {
        turn = diff >> 2;
        if (diff < 0) {
            limit = adjust->turn_x - 128;
            if (0) {
                adjust->turn_x = limit;
                adjust->turn_x = limit;
                adjust->turn_x = limit;
            }
            if (turn > limit) {
                diff = turn;
            } else {
                diff = limit;
            }
            if (diff <= -0x200) {
                diff = -0x200;
            } else {
            }
            adjust->turn_x = diff;
            cameraControlWork->ang_x = diff + last->ang.x;
        } else {
            limit = adjust->turn_x + 128;
            if (turn < limit) {
                diff = turn;
            } else {
                diff = limit;
            }
            if (diff >= 0x200) {
                diff = 0x200;
            }
            adjust->turn_x = diff;
            cameraControlWork->ang_x = diff + last->ang.x;
        }
    }
    cameraControlWork->target.x = playertwp[0]->pos.x;
    cameraControlWork->target.y = playertwp[0]->pos.y + 15.0F;
    cameraControlWork->target.z = playertwp[0]->pos.z;
    cameraControlWork->distance = distance;
    cameraControlWork->ang_z = 0;
    camera_place_from_target(work);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c025010(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust)
{
    Float dx;
    Float dy;
    Float dz;
    Float distance;
    Float move;
    Float change;
    Float step;
    Angle diff;
    Angle turn;
    Angle limit;
    Angle quarter;
    if (cameraControlWork->flags & 0x1) {
        cameraControlWork->flags &= ~0x1;
    } else {
        diff = work->ang.y - last->ang.y;
        diff = (diff & 0x8000) ? (diff | 0xffff0000) : (Uint16)diff;
        if (diff > -0x180 && diff < 0x180) {
            cameraControlWork->ang_y = work->ang.y;
            adjust->turn_y = 0;
            adjust->flags &= ~0x40;
        } else {
            quarter = diff >> 2;
            turn = quarter;
            if (diff < 0) {
                limit = adjust->turn_y - 0x180;
                if (turn > limit) {
                    diff = turn;
                } else {
                    diff = limit;
                }
                adjust->turn_y = diff;
                cameraControlWork->ang_y = diff + last->ang.y;
            } else {
                limit = adjust->turn_y + 0x180;
                if (turn < limit) {
                    diff = turn;
                } else {
                    diff = limit;
                }
                adjust->turn_y = diff;
                cameraControlWork->ang_y = diff + last->ang.y;
            }
        }
    }
    diff = work->ang.x - last->ang.x;
    diff = (diff & 0x8000) ? (diff | 0xffff0000) : (Uint16)diff;
    if (diff > -32 && diff < 32) {
        cameraControlWork->ang_x = work->ang.x;
        adjust->turn_x = 0;
        adjust->flags &= ~0x20;
    } else {
        quarter = diff >> 2;
        turn = quarter;
        if (diff < 0) {
            limit = adjust->turn_x - 32;
            if (turn > limit) {
                diff = turn;
            } else {
                diff = limit;
            }
            if (0) {
                if (diff) {
                }
            }
            if (diff <= -0x200) {
                diff = -0x200;
            }
            adjust->turn_x = diff;
            cameraControlWork->ang_x = diff + last->ang.x;
        } else {
            limit = adjust->turn_x + 32;
            if (turn < limit) {
                diff = turn;
            } else {
                diff = limit;
            }
            if (diff >= 0x200) {
                diff = 0x200;
            }
            adjust->turn_x = diff;
            cameraControlWork->ang_x = diff + last->ang.x;
        }
    }
    dx = work->pos.x - last->pos.x;
    dy = work->pos.y - last->pos.y;
    dz = work->pos.z - last->pos.z;
    distance = njSqrt((dx * dx) + (dy * dy) + (dz * dz));
    move = adjust->move;
    change = distance - move;
    if (change < 0.7F && change > -0.7F) {
        cameraControlWork->pos.x = work->pos.x;
        cameraControlWork->pos.y = work->pos.y;
        cameraControlWork->pos.z = work->pos.z;
        adjust->move = 0.0F;
    } else {
        step = change * 0.25F;
        if (change < 0.0F) {
            move += -0.7F;
            if (move < step) {
                move = step;
            }
            if (move < -80.0F) {
                move = -80.0F;
            }
        } else {
            move += 0.7F;
            if (move > step) {
                move = step;
            }
            if (move > 80.0F) {
                move = 80.0F;
            }
        }
        adjust->move = move;
        if (0.0F == distance) {
            cameraControlWork->pos.x = last->pos.x;
            cameraControlWork->pos.y = last->pos.y;
            cameraControlWork->pos.z = last->pos.z;
        } else {
            move /= distance;
            cameraControlWork->pos.x = last->pos.x + (dx * move);
            cameraControlWork->pos.y = last->pos.y + (dy * move);
            cameraControlWork->pos.z = last->pos.z + (dz * move);
        }
    }
    cameraControlWork->ang_z = 0;
    camera_place_at_angles(work);
}
void camera_adjust_time(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust)
{
    Float part;
    part = (Float)adjust->steps * (1.0F / 120.0F);
    if (part >= 1.0F) {
        part = 1.0F;
        camera_set_adjust(0);
    }
    work->pos.x = ((work->pos.x - last->pos.x) * part) + last->pos.x;
    work->pos.y = ((work->pos.y - last->pos.y) * part) + last->pos.y;
    work->pos.z = ((work->pos.z - last->pos.z) * part) + last->pos.z;
    work->ang.x = AdjustAngle(
        last->ang.x, work->ang.x,
        (Angle)(DiffAngle(work->ang.x, last->ang.x) * part));
    work->ang.y = AdjustAngle(
        last->ang.y, work->ang.y,
        (Angle)(DiffAngle(work->ang.y, last->ang.y) * part));
    work->ang.z = AdjustAngle(
        last->ang.z, work->ang.z,
        (Angle)(DiffAngle(work->ang.z, last->ang.z) * part));
    FUN_8c01e508(&last->pos, &work->pos);
}
void FUN_8c025482(struct task_work *work, struct task_work *last,
                              struct camera_adjust_work *adjust);
void adjust_ease_aim(struct task_work *work, struct task_work *last,
                            struct camera_adjust_work *adjust);
void adjust_ease_follow(struct task_work *work, struct task_work *last,
                               struct camera_adjust_work *adjust);
void adjust_ease_trail(struct task_work *work, struct task_work *last,
                              struct camera_adjust_work *adjust);
void adjust_ease_turn(struct task_work *work, struct task_work *last,
                             struct camera_adjust_work *adjust);
void adjust_ease_limit(struct task_work *work, struct task_work *last,
                              struct camera_adjust_work *adjust);
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void camera_adjust_ease(struct task_work *work, struct task_work *last,
                        struct camera_adjust_work *adjust)
{
    adjust_ease_aim(work, last, adjust);
    if (adjust->steps == 0) {
        FUN_8c025482(work, last, adjust);
    }
    ease_part = (Float)adjust->steps / ease_steps;
    if (ease_part >= 1.0F) {
        ease_part = 1.0F;
        camera_set_adjust(0);
    }
    ease_limit.x =
        ((((Angle)(((40) * 65536.0) / 360.0)) - ease_off_aim.x) * ease_part) + ease_off_aim.x;
    ease_limit.y =
        ((((Angle)(((20) * 65536.0) / 360.0)) - ease_off_aim.y) * ease_part) + ease_off_aim.y;
    if (FUN_8c01b406() <= 15) {
        adjust_ease_follow(work, last, adjust);
    } else {
        adjust_ease_trail(work, last, adjust);
    }
    adjust_ease_turn(work, last, adjust);
    adjust_ease_limit(work, last, adjust);
    if (ease_sweeps) {
        FUN_8c01e508(&last->pos, &work->pos);
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c025482(struct task_work *work, struct task_work *last,
                              struct camera_adjust_work *adjust)
{
    struct adjust_ease eases[21] = {
        {0, 60.0F, 0}, {1, 60.0F, 0}, {0, 180.0F, 3}, {1, 180.0F, 3},
        {0, 600.0F, 10}, {1, 600.0F, 10}, {0, 1800.0F, 30}, {1, 1800.0F, 30},
        {0, 3600.0F, 60}, {1, 3600.0F, 60}, {0, 60.0F, 0}, {1, 60.0F, 0},
        {0, 180.0F, 3}, {1, 180.0F, 3}, {0, 600.0F, 10}, {1, 600.0F, 10},
        {0, 1800.0F, 30}, {1, 1800.0F, 30}, {0, 3600.0F, 60}, {1, 3600.0F, 60},
        {1, 30000.0F, 60},
    };
    ease_off_aim.x = DiffAngle(last->ang.x, ease_aim.x);
    ease_off_aim.y = DiffAngle(last->ang.y, ease_aim.y);
    ease_start_move = camera_moved;
    ease_sweeps =
        eases[FUN_8c01b406() - 6]
            .sweeps;
    ease_steps =
        eases[FUN_8c01b406() - 6]
            .steps;
    ease_blend =
        eases[FUN_8c01b406() - 6]
            .blend;
    dat_8c6c0e68 = 0;
}
void adjust_ease_aim(struct task_work *work, struct task_work *last,
                            struct camera_adjust_work *adjust)
{
    NJS_POINT3 from_player;
    from_player.x = last->pos.x - playertwp[0]->pos.x;
    from_player.z = last->pos.z - playertwp[0]->pos.z;
    ease_aim.y =
        (Angle)(njArcTan2(from_player.x, from_player.z) * (65536.0 / (2 * 3.141592)));
    ease_aim.x = (Angle)(njArcTan2(playertwp[0]->pos.y - last->pos.y,
                                njSqrt((from_player.x * from_player.x) +
                                       (from_player.z * from_player.z))) *
                         (65536.0 / (2 * 3.141592)));
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void adjust_ease_follow(struct task_work *work, struct task_work *last,
                               struct camera_adjust_work *adjust)
{
    NJS_POINT3 lead;
    NJS_POINT3 eased;
    lead.x = (last->pos.x - playertwp[0]->pos.x) * (1.0F - ease_part) * 0.2F;
    lead.y = (last->pos.y - playertwp[0]->pos.y) * (1.0F - ease_part) * 0.2F;
    lead.z = (last->pos.z - playertwp[0]->pos.z) * (1.0F - ease_part) * 0.2F;
    if (adjust->steps < ease_blend) {
        eased.x = (work->pos.x - last->pos.x + lead.x) * ease_part;
        eased.y = (work->pos.y - last->pos.y + lead.y) * ease_part;
        eased.z = (work->pos.z - last->pos.z + lead.z) * ease_part;
        work->pos.x = last->pos.x +
                      (((eased.x * adjust->steps) +
                        (ease_start_move.x * (ease_blend - adjust->steps))) /
                       ease_blend);
        work->pos.y = last->pos.y +
                      (((eased.y * adjust->steps) +
                        (ease_start_move.y * (ease_blend - adjust->steps))) /
                       ease_blend);
        work->pos.z = last->pos.z +
                      (((eased.z * adjust->steps) +
                        (ease_start_move.z * (ease_blend - adjust->steps))) /
                       ease_blend);
    } else {
        work->pos.x =
            last->pos.x + ((work->pos.x - last->pos.x + lead.x) * ease_part);
        work->pos.y =
            last->pos.y + ((work->pos.y - last->pos.y + lead.y) * ease_part);
        work->pos.z =
            last->pos.z + ((work->pos.z - last->pos.z + lead.z) * ease_part);
    }
}
void adjust_ease_trail(struct task_work *work, struct task_work *last,
                              struct camera_adjust_work *adjust)
{
    NJS_POINT3 past;
    NJS_POINT3 lag;
    NJS_POINT3 offset;
    GetPlayerPosition(0, 1, &past, ((void *)0));
    lag.x = last->pos.x - past.x;
    lag.y = last->pos.y - past.y;
    lag.z = last->pos.z - past.z;
    offset.x = work->pos.x - playertwp[0]->pos.x;
    offset.y = work->pos.y - playertwp[0]->pos.y;
    offset.z = work->pos.z - playertwp[0]->pos.z;
    work->pos.x =
        lag.x + ((offset.x - lag.x) * ease_part) + playertwp[0]->pos.x;
    work->pos.y =
        lag.y + ((offset.y - lag.y) * ease_part) + playertwp[0]->pos.y;
    work->pos.z =
        lag.z + ((offset.z - lag.z) * ease_part) + playertwp[0]->pos.z;
}
void adjust_ease_turn(struct task_work *work, struct task_work *last,
                             struct camera_adjust_work *adjust)
{
    work->ang.x = AdjustAngle(
        last->ang.x, work->ang.x,
        (Angle)(DiffAngle(work->ang.x, last->ang.x) * ease_part));
    work->ang.y = AdjustAngle(
        last->ang.y, work->ang.y,
        (Angle)(DiffAngle(work->ang.y, last->ang.y) * ease_part));
    work->ang.z = AdjustAngle(
        last->ang.z, work->ang.z,
        (Angle)(DiffAngle(work->ang.z, last->ang.z) * ease_part));
}
void adjust_ease_limit(struct task_work *work, struct task_work *last,
                              struct camera_adjust_work *adjust)
{
    if (DiffAngle(work->ang.x, ease_aim.x) > ease_limit.x) {
        work->ang.x = AdjustAngle(ease_aim.x, work->ang.x, ease_limit.x);
    }
    if (DiffAngle(work->ang.y, ease_aim.y) > ease_limit.y) {
        work->ang.y = AdjustAngle(ease_aim.y, work->ang.y, ease_limit.y);
    }
}
extern struct camera_mode camera_mode_table[72];
