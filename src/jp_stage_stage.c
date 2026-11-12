/* @unit 8C04C680-8C04FEA0 @data 8C112A4C-8C112A78 +r04 +egflags +pool32    +poolafter=GM_CheckClearEvent,stage_keep_previous,stage_begin,music_play_later,FUN_8c04f7ee +poolbra=stage_start_event:1,FUN_8c04e714:2,stage_place_player:1,stage_place_player:9,FUN_8c04fb3a:1,FUN_8c04fb3a:10,FUN_8c04fd50:4 +brfar=FUN_8c04fb3a:5 +asmfunc=FUN_8c04ecd0,FUN_8c04f84e,FUN_8c04ca40:8c04d7f2,FUN_8c04d830,FUN_8c04da20:8c04e386,stage_reset_play,GameInit,stage_run_action,stage_run_field,FUN_8c04eb7e,FUN_8c04ed1a,SetFinishAction,stage_create_task,FUN_8c04ca40:8c04d7f2,FUN_8c04da20:8c04e386,FUN_8c04d920:+8c04da20,InitializeStage:+8c04e660,clear_wait_step:+8c04f3c0 */
/* Ported from the Japanese release's src/stage/stage.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
#define TEXT_1 ""
#define TEXT_2 ""
#define TEXT_3 ""
#define TEXT_4 ""
#define TEXT_5 ""
#define TEXT_6 ""
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
void FUN_8c6409c0(Int loc, Int val, Int digit);
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
void CHAOS_SetChaosNo(Uint32 c);
void njSetFogDensity(Uint32 density);
Uint32 njGenerateFogDensity(Float f);
void njGenerateFogTable(NJS_FOG_TABLE fog);
void ReleaseModule(NJS_FOG_TABLE fog, Float n, Float f);
void kmSetFogTable(NJS_FOG_TABLE fog);
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
void FUN_8c098380(struct task *task);
void (*task_get_current_root_step(void))(struct task *task);
void task_init(void);
struct task *CreateElementalTask(Uint16 flags, int level,
                         void (*step)(struct task *task));
struct task *FUN_8c09852c(int level, void (*step)(struct task *task));
void DestroyTask(struct task *task);
void FreeTask(struct task *task);
void task_step_level(int level);
void task_draw_level(int level);
void task_draw_children(struct task *task);
void task_destroy_level(int level);
void task_draw_all(void);
void task_step_all(void);
void task_destroy_levels_0_to_6(void);
void task_destroy_all(void);
void *FUN_8c0988a0(void);
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
void FreeTaskC(struct task *task);
void LoopTaskC(struct task *task);
void heap_init(void);
void *MAlloc(int size);
void *CAlloc(int count, int size);
void Free(void *mem);
void heap_stats(int *total, int *largest);
void station_square_place_player(struct task_work *work);
struct death_zone;
extern struct death_zone *station_square_death_zones[];
void station_square_step(struct task *task);
void station_square_sky_step(struct task *task);
extern Sint8 captain_switch_was;
extern struct task *field_act_tasks[4];
extern Bool egg_carrier_sunk;
void egg_carrier_step(struct task *task);
void egg_carrier_sky_step(struct task *task);
void egg_carrier_clouds_step(struct task *task);
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
void ReleasePlayersTexture(int character);
void njExitTexture(void);
void LoadPlayerMotionData();
void LoadTextureForEachGameMode(int set);
extern int event_current;
void texture_release_regular(void);
void texture_load_stage(void);
Bool SetObjectTexture(void);
Bool SetRegularTexture(void);
Bool CheckObjectTexture(void);
void texture_release_stage(void);
Bool texture_load_act(Uint16 stage_act);
Bool texture_act_in_use(Uint16 stage_act);
Bool texture_release_act(Uint16 stage_act);
void texture_release_acts(void);
void texLoadTexturePvmFile(char *name, NJS_TEXLIST *texlist);
Sint32 texture_load_prs_file(char *name, NJS_TEXLIST *texlist);
struct death_zone;
extern struct death_zone *inside_death_zones[];
void egg_carrier_inside_step(struct task *task);
void egg_carrier_inside_sky_step(struct task *task);
extern struct texture_pvm egg_carrier_inside_pvms[];
extern struct texture_pvm egg_carrier_inside_act_pvms[];
extern NJS_TEXLIST obj_ec30_texlist;
extern NJS_TEXLIST ec_water_texlist;
extern NJS_TEXLIST ec_tarai_texlist;
extern NJS_TEXLIST adv_ec30_texlist;
extern NJS_TEXLIST adv_ec31_texlist;
extern NJS_TEXLIST adv_ec32_texlist;
extern NJS_TEXLIST adv_ec33_texlist;
extern NJS_TEXLIST adv_ec34_texlist;
extern NJS_TEXLIST adv_ec35_texlist;
void egg_carrier_place_player(struct task_work *work);
enum {
    MYSTIC_RUINS_STATION,
    MYSTIC_RUINS_ISLAND,
    MYSTIC_RUINS_JUNGLE,
    MYSTIC_RUINS_BASE
};
void mystic_ruins_step(struct task *task);
void mystic_ruins_sky_step(struct task *task);
void mystic_ruins_place_player(struct task_work *work);
enum { PAST_KNUCKLES, PAST_CHAOS, PAST_FIRE };
struct death_zone;
extern struct death_zone *past_death_zones[];
void past_step(struct task *task);
void past_sky_step(struct task *task);
extern NJS_TEXLIST obj_past_texlist;
extern NJS_TEXLIST sky_act0_texlist;
extern NJS_TEXLIST sky_act1_texlist;
extern NJS_OBJECT pyramid_snake_object;
void past_place_player(struct task_work *work);
struct script_page {
    char *text;
    Sint32 steps;
};
enum script_word {
    SCRIPT_END = -1,
    SCRIPT_BRANCH = -2,
    SCRIPT_FLAG = -3,
    SCRIPT_VOICE = -4,
    SCRIPT_CHARACTERS = -5,
    SCRIPT_EVENTS = -6,
    SCRIPT_FLAGS = -7
};
struct script_row {
    Sint16 *script;
    void *runs;
};
struct field_messages {
    Sint32 people;
    struct script_row *table;
};
struct script_pages {
    struct script_page *pages;
    Sint32 voice;
    Sint32 flag;
};
struct script_lines {
    char **lines;
    Sint32 flag;
};
void message_show_timed(char **lines);
void message_set_shown(Uint8 *shown);
void script_set_lines_table(struct script_row *table);
void script_set_table(struct script_row *table);
Bool HintMessageInit(int row, struct script_pages *pick);
Bool FUN_8c05f080(int row, struct script_lines *lines);
void HintMessageStart(struct script_pages *pick);
void script_show_lines(struct script_lines *lines);
Bool message_busy(void);
void message_cut(void);
extern struct script_row station_square_garden_script_table[];
void station_square_garden_step(struct task *task);
extern struct script_row egg_carrier_garden_script_table[];
void egg_carrier_garden_step(struct task *task);
extern struct script_row mystic_ruins_garden_script_table[];
void mystic_ruins_garden_step(struct task *task);
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
Sint8 FUN_8c02596c(void);
void chao_set_carried(struct chao *chao);
struct chao *chao_get_carried(void);
void chao_set_carried_to(Sint8 garden);
void chao_clear_carried(void);
Sint8 chao_get_carried_to(void);
struct chao_node *chao_get_list(int garden);
Uint8 chao_count(int garden);
void chao_set_id(struct chao *chao, int number);
void FUN_8c025ab8(struct chao *chao);
void chao_reborn(struct chao *chao);
void chao_breed(struct chao *first, struct chao *second, struct chao *child);
struct chao *chao_find_empty(void);
void chao_list_add(int garden, struct chao *chao);
void chao_list_remove(struct chao *chao);
Bool chao_move(struct chao *chao, int garden);
void chao_gardens_init(void);
void chao_reset(void);
void AddExtraDisplay(Sint8 kind);
void ExtraDisplayInit(void);
struct save;
struct card_drive {
    Uint16 mounted;
    Uint16 info_read;
    Sint32 error;
    Sint32 count;
    Sint32 max;
    Uint32 op;
    BUS_DISKINFO info;
};
enum save_file_kind {
    SAVE_FILE_NET,
    SAVE_FILE_CHAO,
    SAVE_FILE_RECORD,
    SAVE_FILE_CART,
    SAVE_FILE_EVENT,
    SAVE_FILE_KINDS
};
extern int save_slot;
extern int save_drive;
extern Bool save_disabled;
extern int card_saving;
void card_init(void);
void card_finish(void);
int card_notice_busy(void);
void FUN_8c010b7a(void);
Sint32 card_complete(Sint32 drive, Sint32 op, Sint32 status, Uint32 param);
Sint32 FUN_8c010f0e(Sint32 drive, Sint32 op, Sint32 count, Sint32 max);
int card_free_blocks(void);
int card_newest_download(int drive);
Bool save_file_exists(void);
int save_reset_all_write(void);
int save_reset_write(void);
int FUN_8c0114bc(void);
int save_write_wait(void);
int save_update_write_wait(void);
int save_update_write(void);
int save_read(void);
struct save *save_peek(void);
int card_find(char *name);
int save_write_file(char *name, int size, int kind);
int save_read_file(char *name);
int card_write_work(char *name, int size);
int card_read_xzxz(void);
struct card_menu_drive {
    Sint32 was_present;
    Sint32 present;
    Sint32 unk_08;
    Sint32 error;
    Sint32 count;
    Sint32 max;
    Sint32 op;
    Sint32 exec_marked;
    Sint32 arrived;
    struct chao chao;
    struct chao egg;
    Float unk_424;
    Uint8 unk_428[0xc];
};
extern struct card_menu_drive card_menu_drives[8];
int card_drives_start(void);
void card_drives_end(void);
int card_get_save_drive(void);
void card_drives_refresh(void);
int fun_0c90288c(void);
int alife_load(void);
int alife_save(void);
int alife_save_wait(void);
int card_read_chao(Sint32 drive, struct chao *chao);
int fun_0c9023ac(Sint32 drive, struct chao *egg);
int card_delete_exec(Sint32 drive);
int card_write_chao(Sint32 drive, const struct chao *chao);
int card_clear_chao(Sint32 drive);
int card_write_egg(Sint32 drive, const struct chao *egg);
int fun_0c902760(Sint32 drive);
void card_drives_take_changes(void);
void alife_race_step(struct task *task);
void race_sky_step(struct task *task);
void chaos0_step(struct task *task);
void chaos0_sky_step(struct task *task);
void chaos0_music_wait_step(struct task *task);
void chaos2_step(struct task *task);
void chaos2_sky_step(struct task *task);
void chaos2_music_wait_step(struct task *task);
void chaos4_step(struct task *task);
void chaos4_sky_step(struct task *task);
void chaos6_step(struct task *task);
void chaos6_music_wait_step(struct task *task);
void chaos6_sky_step(struct task *task);
void chaos6_clouds_step(struct task *task);
extern NJS_TEXLIST chaos6_bg_texlist;
void chaos7_step(struct task *task);
void chaos7_sky_step(struct task *task);
void chaos7_part_2_start(void);
void chaos7_part_2_end(void);
void chaos7_music_stop(void);
void chaos7_restart(void);
void e101_step(struct task *task);
void e101_sky_step(struct task *task);
void e101_r_step(struct task *task);
void e101_r_sky_step(struct task *task);
void eggmobile1_step(struct task *task);
void eggmobile1_sky_step(struct task *task);
void eggmobile2_step(struct task *task);
void eggmobile2_sky_step(struct task *task);
extern NJS_POINT3 *egg_viper_segment_pos[13];
extern struct angles *egg_viper_segment_ang[13];
extern struct task *egg_viper_task;
extern struct task *egg_viper_needles[2];
extern struct task *egg_viper_segments[13];
void eggmobile3_step(struct task *task);
void eggmobile3_sky_step(struct task *task);
void eggmanrobo_step(struct task *task);
void eggmanrobo_sky_step(struct task *task);
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
extern struct task_work *camera_work;
extern struct camera_state *const camera_state;
void InitCartGoalCamFunc(struct camera_view *view);
void camera_set_start_mode(Sint8 mode);
void camera_set_restore_mode(Sint8 mode, Sint8 adjust);
Angle camera_get_perspective(void);
void FUN_8c01937c(Angle ang);
Bool camera_collisions_enabled(void);
void camera_enable_collisions(void);
void camera_disable_collisions(void);
void FUN_8c01957e(void);
void camera_change_act(Sint16 by);
void camera_create_advertise(void);
void camera_place_at_angles(struct task_work *work);
void FUN_8c01a680(struct task_work *work);
void camera_place_from_target(struct task_work *work);
void FUN_8c01a7a4(NJS_VECTOR *offset);
void FUN_8c01aae0(Sint16 mode, Uint8 adjust);
void camera_override_mode(Sint16 mode, Uint8 adjust);
void CameraSetEventCameraFunc(void (*step)(struct camera_view *view), Uint8 adjust,
                     Sint8 type);
void CameraReleaseEventCamera(void);
void CameraSetCollisionCameraFunc(void (*step)(struct camera_view *view), Uint8 adjust,
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
void camera_step_follow(struct camera_view *view);
void camera_step_work_view(struct camera_view *view);
void FUN_8c021b60(struct camera_view *view);
void camera_step_pose(struct camera_view *view);
void camera_start_path(struct path *path, int mode, Uint32 steps);
void FUN_8c020140(int unbounded);
void camera_boss_place_from_player(int below_only);
int FUN_8c020440(int from_anchor);
void camera_set_e103(struct task_work *work, NJS_POINT3 *points);
void camera_set_boss_offsets(NJS_POINT3 *target, NJS_POINT3 *offset);
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
void CCL_CalcRange(struct collision_work *collision);
void CCL_Init(struct task *task, const struct collision_shape *shapes,
                    Uint8 kind, int unused, Uint8 count);
void EntryColliList(struct task_work *work);
void collision_clear_lists(void);
int collision_get_hit_player(struct task_work *work);
void shape_get_center(struct task_work *work,
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
Bool FUN_8c028ec2(void);
void collision_mesh_collect_all(void);
void collision_mesh_link_pools(void);
void polygon_pool_seek_free(void);
void collision_mesh_forget(NJS_OBJECT *object);
int CL_ColPolListUpNear(struct polygon_ball *ball);
Bool CL_ColPolCheckTouchRe(struct polygon_ball *ball, NJS_OBJECT *object, Uint32 flags);
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
Bool CL_ColPolBeamHit(struct ray_query *query);
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
extern Sint16 world_count;
extern struct world_object world_objects[1024];
void world_land_step(struct task *task);
void world_load_act(int stage, int act);
void world_release_act(int stage, int act);
void world_change_act(Sint16 by);
void world_hide_land(void);
void world_show_land(void);
void world_set_land_material(Float gray);
void FUN_8c052518(void);
void FUN_8c052e30(void);
void ListGroundForCollision(Float x, Float y, Float z, Float radius);
void FUN_8c052d36(void);
void world_disable_land(void);
void world_enable_land(void);
void RegisterCollisionEntry(Sint32 flags, struct task *task, NJS_OBJECT *object);
void WithdrawCollisionEntry(struct task *task, NJS_OBJECT *object);
NJS_OBJECT *GetMobileLandObject(void);
void ReleaseMobileLandObject(NJS_OBJECT *object);
void world_reset_gravity(void);
void FUN_8c052aa8(Angle ang_x, Angle ang_z);
void FUN_8c052ba0(void);
void world_set_near_radius(Float radius);
void world_reset_near_radius(void);
struct task_work;
Bool debug_set_flag(Sint16 on);
void debug_draw_axes(struct task_work *work);
void debug_draw_line(NJS_POINT3 *pos, NJS_VECTOR *dir, Float length);
void debug_name_frame(void);
void fun_8c035f18(void);
void debug_print_stage_name(Int loc, Sint16 stage_act);
struct task;
void FUN_8c042f0e(void);
Sint16 fade_in_step(void);
void fade_out_start(void);
Sint16 fade_out_step(void);
void fade_start(void);
void fade_stop(void);
void game_over_start(void);
Sint16 GameOver(int choice);
void FUN_8c0430e0(void);
void coming_soon_start(void);
Sint16 coming_soon_step(void);
void FUN_8c0437c6(struct task *task);
void FUN_8c0438ac(struct task *task);
void fade_set_cover(NJS_COLOR *color);
void fade_get_cover(NJS_COLOR *color);
void FUN_8c0439ae(void);
struct task;
struct light_spec {
    Sint32 type;
    Float specular, diffuse, ambient;
    NJS_ARGB color;
    NJS_POINT3 pos;
    NJS_VECTOR direction;
    Float near, far;
    Angle inner, outer;
};
extern NJS_LIGHT dir_light;
void FUN_8c052fa0(struct task *task);
struct task *FUN_8c0531d6(struct task *parent, NJS_LIGHT *light,
                          struct light_spec *spec);
int light_write_palettes(int stage, int act);
int light_write_sources(int stage, int act);
void light_load_act(void);
Bool light_read_disc(const char *name, void *dest);
Bool light_read_disc_sources(Uint16 stage, int act);
Bool light_read_disc_palettes(Uint16 stage, int act);
void FUN_8c0130f8(void);
int light_place_point_and_test(NJS_MODEL *model);
extern Uint32 draw_palettes[8][256 * 2];
extern Uint32 draw_unlit_offsets[512];
extern int draw_debug_counts[20];
void draw_model_init(void);
void draw_model(NJS_MODEL *model);
void draw_model_nested(NJS_MODEL *model);
void draw_models_begin(void);
void draw_model_unculled(NJS_MODEL *model);
void draw_models_end(void);
Bool draw_in_view(Float x, Float y, Float z, Float radius);
void draw_set_light(Float x, Float y, Float z);
void draw_divide_light(Float scale);
void draw_reset_light(void);
void draw_set_palette(int palette);
void draw_take_point_lights(void);
void text_style_init(Uint32 *texture, Uint32 size, Uint32 attr);
void FUN_8c041e94(void);
void text_set_size(Uint16 size);
void text_set_color(Uint32 color);
void FUN_8c042298(Int loc, const char *string);
void FUN_8c042416(Int loc, const char *string);
void FUN_8c0425a0(Int loc, Int value, Int digits);
void FUN_8c042880(Int loc, Uint32 value, Int digits);
void FUN_8c04298e(Int loc, Uint32 value, Int digits);
void FUN_8c042b22(Int loc, Float value, Int digits);
void FUN_8c042d3a(Int loc, const char *format, ...);
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
void FUN_8c09dff8(void);
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
Bool EV_CheckCansel(void);
Bool EV_CheckExec(int number);
void event_wait(int steps);
void FUN_8c049b00(const char *text);
void event_message_wait(int steps, const char *text);
void FUN_8c049bb2(const char *format, ...);
void event_message_wait_printf(int steps, const char *format, ...);
void event_message_close(void);
void event_message_clear(void);
int event_message_choose(const char *text);
Sint32 event_load_texlist(NJS_TEXLIST *texlist);
Sint32 event_release_texlist(NJS_TEXLIST *texlist);
struct task *event_get_player(int player);
void EV_CreateObject(struct task **slot, Float x, Float y, Float z,
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
void FUN_8c04a168(struct task *task);
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
void FUN_8c04a45a(struct task *task, Float x, Float y, Float z,
                        Float speed, Float accel);
void event_turn_by(struct task *task, Angle ang_x, Angle ang_y, Angle ang_z);
void event_turn_to(struct task *task, Angle ang_y);
void event_run_wait(struct task *task);
void event_camera_take(void);
void FUN_8c04a840(void);
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
void FUN_8c089fb4(void);
void FUN_8c089fbc(void);
void lives_add(Sint16 count);
void ring_add(int count);
void score_add(int points);
void score_add_bonus(int points);
int ring_count(void);
void hud_draw(void);
Sint16 FUN_8c08a4b2(void);
void play_time_reset(void);
void thunk_FUN_8c608734(void);
void WakeTimer(void);
void SleepTimer(void);
void play_time_count(void);
void FUN_8c08a50c(void);
int play_time_get(void);
void FUN_8c08a3fa(void);
void time_get_whole(Uint8 *minutes, Uint8 *seconds);
void time_set_whole(int minutes, int seconds);
void time_set(Uint8 minutes, Uint8 seconds, Uint8 frames);
void time_get(Uint8 *minutes, Uint8 *seconds, Uint8 *frames);
void time_add_seconds(int seconds);
Bool time_is_zero(void);
void score_step(struct task *task);
void DrawSNumbers(struct hud_number *number);
void trial_times_clear(void);
struct task;
enum menu_kind { MENU_ROW, MENU_COLUMN };
struct menu_sounds {
    Sint32 open;
    Sint32 close;
    Sint32 move;
    Sint32 select;
    Sint32 cancel;
};
struct menu_item {
    Float x, y;
    Uint8 texture;
};
struct menu_view {
    Float x, y, z;
    Float scale_x, scale_y;
    Sint8 cursor;
};
struct menu {
    enum menu_kind kind;
    void (*draw)(struct menu_view *view);
    NJS_TEXLIST *texlist;
    const struct menu_item *items;
    const struct menu_sounds *sounds;
    Uint32 frame_top;
    Uint32 frame_bottom;
    Float x, y, z;
    Float frame_w, frame_h;
    Float item_scale_x, item_scale_y;
    Sint8 count;
    Sint8 cancel;
};
extern const struct menu_sounds menu_default_sounds;
extern NJS_TEXLIST menu_row_texlist;
extern NJS_TEXLIST menu_column_texlist;
void program_select_init(void);
void program_select_step(void);
void SetDlgCsrStat(Uint8 *alpha, Angle *blink, Float *pulse);
Uint32 menu_blend_color(Uint32 from, Uint32 to, Float part);
void DrawDlgCsr(int alpha, Float x, Float y, Float z, Float scale_x,
                          Float scale_y);
void DrawDlgCsrSqr();
void menu_draw_row_item(Uint32 color, Float x, Float y, Float z, Float scale_x,
                        Float scale_y);
void menu_draw_column_item(Uint32 color, Float x, Float y, Float z,
                           Float scale_x, Float scale_y);
void menu_draw_box(Float x, Float y, Float z, Float width, Float height);
struct task *SetDialogTask(void);
void menu_kill(void);
void FUN_8c0a65e8(const struct menu *menu, Sint8 cursor, Sint8 *disabled);
void menu_popup(const struct menu *menu, Sint8 cursor, Sint8 *disabled);
void menu_popup_default(const struct menu *menu);
int menu_result(void);
Bool menu_close(void);
Sint16 menu_get_idle(void);
void menu_set_idle(Sint16 idle);
struct task;
void FUN_8c01493e(void);
void FUN_8c014a78(void);
void FUN_8c014b86(void);
void FUN_8c014b8a(struct task *task);
void press_start_destroy(struct task *task);
enum pause_choice { PAUSE_CONTINUE, PAUSE_RESTART, PAUSE_QUIT, PAUSE_CHOICES };
void FUN_8c014c4a(enum pause_choice choice);
void FUN_8c014d6e(int choice);
void pause_draw_no_choices(void);
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
int FUN_8c053b60(void);
void SetPlayerNumberForGame(void);
void game_release_textures(void);
void texture_release_all(void);
void Draw_Reset(void);
void system_boot_init(void);
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
void SetObject(struct task *task);
void placement_reset(void);
void placement_change_act(Sint16 change);
Bool FUN_8c091852(struct task *task);
Bool placement_far_from_camera_by(struct task *task, Float range);
Bool CheckRangeOut(struct task *task);
Bool CheckRangeOutWithR(struct task *task, Float range);
Bool FUN_8c0919d2(struct task *task);
Bool placement_try_leave_saving_by(struct task *task, Float range);
void placement_set_used(struct task *task);
void FUN_8c091a9e(struct task *task);
int placement_used(struct task *task);
void placement_hold(struct task *task);
int placement_held(struct task *task);
void FUN_8c091aca(struct task *task);
void DeadOut(struct task *task);
Uint16 placement_get_kind(struct task *task);
void placement_set_state(struct task *task, Sint8 state);
Sint8 placement_get_state(struct task *task);
extern struct object_kind cart_object_kinds[];
void cart_step(struct task *task);
void cart_sky_step(struct task *task);
int capsule_get_player(void);
void capsule_reset(void);
void ObjectReleaseBox(struct task *task);
void capsule_test_active(void);
struct task *capsule_get(void);
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
void CharacterShadow(struct task_work *work, struct shadow *shadow);
Bool FUN_8c09276e(struct sides_query *result);
Bool FUN_8c092b20(struct sides_query *result);
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
void PInitialize(int player, struct task *task);
void PDestruct(int player);
void player_finish_step(struct task_work *work, struct task_motion *motion,
                        struct player *record);
int player_action_touch_id(struct task_work *work);
int player_carry_flags(struct task_work *work);
Bool player_touches_shakable(struct task_work *work, struct task_motion *motion,
                             struct player *record);
void player_shake_touched(struct task_work *work, struct task_motion *motion,
                          struct player *record);
void PAdjustHoldingPosition(struct task_work *work,
                             struct task_motion *motion);
Bool player_upright(struct task_work *work);
Bool PCheckPower(struct task_work *work, Angle *ang, Float *stroke);
Bool FUN_8c06cd80(struct task_work *work,
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
void FUN_8c06d194(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void player_accel_air(struct task_work *work, struct task_motion *motion,
                      struct player *record);
void FUN_8c06f19c(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void FUN_8c06f2c6(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_accel_brake(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_accel_launched(struct task_work *work, struct task_motion *motion,
                           struct player *record);
void player_accel_roll(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void FUN_8c071596(struct task_work *work, struct task_motion *motion,
                          struct player *record);
void player_accel_wall(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void PGetAccelerationFly(struct task_work *work, struct task_motion *motion,
                      struct player *record);
void FUN_8c06f8e2(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void FUN_8c06fa44(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void FUN_8c06f780(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_accel_wall_idle(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void FUN_8c070002(struct task_work *work, struct task_motion *motion,
                        struct player *record, Float max_speed);
void player_accel_board_air(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void FUN_8c070754(struct task_work *work,
                              struct task_motion *motion,
                              struct player *record);
void FUN_8c07089e(struct task_work *work,
                              struct task_motion *motion,
                              struct player *record);
void FUN_8c071a66(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void PSetSnowEffect(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_turn_to_stick(struct task_work *work, struct task_motion *motion,
                          struct player *record);
void FUN_8c071c80(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void player_apply_accel(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void player_apply_path_accel(struct task_work *work, struct task_motion *motion,
                             struct player *record);
void FUN_8c0725ae(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_apply_climb_accel(struct task_work *work,
                              struct task_motion *motion,
                              struct player *record);
void player_apply_glide_accel(struct task_work *work,
                              struct task_motion *motion,
                              struct player *record);
int FUN_8c072a84(struct task_work *work, struct task_motion *motion,
                   struct player *record);
int player_collide_climb(struct task_work *work, struct task_motion *motion,
                         struct player *record);
int player_collide_simple(struct task_work *work, struct task_motion *motion,
                          struct player *record);
void player_move_on_path(struct task_work *work, struct task_motion *motion,
                         struct player *record);
Bool player_shift_on_path(struct task_work *work, struct task_motion *motion,
                          struct player *record);
Bool FUN_8c078438(struct task_work *work, struct task_motion *motion,
                          struct player *record);
int player_collide_wall(struct task_work *work, struct task_motion *motion,
                        struct player *record);
void PResetPositionForBuilding(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void player_turn_to_wall(struct task_work *work, struct task_motion *motion,
                         struct player *record);
void player_turn_to_world(struct task_work *work, NJS_VECTOR *vector);
void PResetPosition(struct task_work *work, struct task_motion *motion,
                       struct player *record);
void player_take_push_speed(struct task_work *work, struct task_motion *motion,
                            struct player *record);
void FUN_8c0793b6(struct player_anim *anim);
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
void KillPlayerFallingDownStageP(struct task *task);
void player_fall(Uint8 player);
void player_down(int player);
void player_set_heading(Sint8 player, Angle ang);
void player_event_run(Uint8 player, Float x, Float z);
void player_event_move(Uint8 player, Float x, Float z);
void player_event_push(Uint8 player, Float x, Float z);
void FUN_8c07c180(Uint8 player);
void player_event_end(Uint8 player);
void player_clear_speed(struct task_motion *motion, struct player *record);
void player_turn_back(struct task_work *work, NJS_VECTOR *vector);
void PSetRippleEffect(Uint8 player, NJS_POINT3 *pos, Angle *ang);
void player_make_splash(struct task_work *work);
void player_kick_dust(struct task_work *work, struct task_motion *motion,
                      struct player *record);
int player_in_range(const NJS_POINT3 *pos, Float radius);
int CheckCollisionCylinderP(NJS_POINT3 *pos, Float radius, Float height);
void player_push_out_of(struct task_work *work);
int GetPlayerCharacterName(Uint8 player);
struct task *GetPlayerTaskPointer(Uint8 player);
int player_task_character(struct task *task);
struct player *player_get(Uint8 player);
int player_count(void);
int GetTheNearestPlayerNumber(NJS_POINT3 *pos);
int player_find_rival(Uint8 player);
Bool CheckPlayerRideOnMobileLandObjectP(Uint8 player, struct task *task);
void player_suspend(Uint8 player);
void player_resume(Uint8 player);
void FUN_8c07d2e0(Uint8 player);
void player_give_magnetic_barrier(Uint8 player);
void player_give_barrier(Uint8 player);
void player_give_invincibility(Uint8 player);
void SetLookingTaskP(Uint8 player, struct task *task, NJS_POINT3 *offset);
void SetLookingPointP(Uint8 player, NJS_POINT3 *pos);
void player_set_look_angles(Uint8 player, struct angles *ang);
void CancelLookingAtP(Uint8 player);
void player_look_at_task(Uint8 player, struct task *task, int steps);
void HoldOnPillarP(Uint8 player, NJS_POINT3 *pos, Uint32 steps);
void KeepPlayersEyesOnThePointP(Uint8 player, struct angles *ang, Uint32 steps);
void player_knock_back(Uint8 player, Float x, Float y, Float z);
void player_knock_apart(Uint8 one, Uint8 other, Float speed);
void SetInputP(Uint8 player, Uint8 mode);
void player_join_path(Uint8 player, struct path *path);
void FUN_8c07c024(Uint8 player, struct path *path, int point);
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
void FUN_8c07c6a8(Uint8 player, const Angle *ang, Float speed, Sint16 steps);
void SetVelocityAndRotationAndNoconTimeWithSpinDashP(Uint8 player, NJS_VECTOR *speed, const Angle *ang,
                         Sint16 steps);
void player_fling(Uint8 player, Float speed, NJS_VECTOR *line);
void player_send_flying(Uint8 player, NJS_VECTOR *speed, const Angle *ang,
                        Sint16 steps);
void player_set_angles(Uint8 player, Angle x, Angle y, Angle z);
void FUN_8c07c93a(Uint8 player, Float x, Float y, Float z);
void SetPositionP(Uint8 player, Float x, Float y, Float z);
Bool player_ground_speed(Uint8 player, Float *speed);
void player_set_speed(Uint8 player, Float x, Float y, Float z);
void player_set_accel(Sint8 player, Float x, Float y, Float z);
void player_updraft(Sint8 player, Float x, Float y, Float z);
void player_push(Sint8 player, Float x, Float y, Float z);
void player_ride_off(Uint8 player, Float x, Float y, Float z);
Bool damage(Uint8 player, int steps, NJS_POINT3 *pos,
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
extern Sint16 stage_retry_count;
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
Sint16 FUN_8c04ca40(void);
Sint16 FUN_8c04da20(void);
void stage_end(Sint16 end);
void sound_play_later(int se);
void music_play_later(int music);
void SetFinishAction(void);
void set_character(Sint16 character);
void FUN_8c04f692(Sint16 character);
int GetPlayerNumber(void);
int FUN_8c04f6a0(void);
Uint16 GetStageNumber(void);
Uint16 FUN_8c04f7ee(void);
void stage_set_stage_act(Uint8 stage, Uint8 act);
void stage_fade_to(Uint8 stage, Uint8 act);
void FUN_8c04f7bc(void);
void stage_set_next_stage_act(Uint8 stage, Uint8 act);
Uint16 FUN_8c04f840(void);
void stage_go_to_next(void);
void stage_change_act(Sint16 by);
void stage_set_entrance(Sint8 entrance);
Sint8 stage_get_entrance(void);
void stage_place_player(struct task_work *work);
#pragma inline(stage_set_next_exit)
void stage_set_next_exit(void);
Bool ChkPause(void);
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
extern Uint8 seqVars[512];
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
void SeqCtrl(void);
void story_save(void);
void FUN_8c09033c(void);
void story_set_wait(Uint16 stage_act);
void main(void);
void story_next_section(void);
void SeqEvent(int event);
void FUN_8c0904b2(Sint8 time);
int story_get_time(void);
Bool playable_check(int character);
void playable_set(int character);
void event_flag_set(int flag);
void FUN_8c0905c6(int flag);
Bool SeqCheckFlag(int flag);
Bool FUN_8c0905dc(int stage, int act);
void FUN_8c090628(void);
void story_go_to(int stage, int act);
Bool story_going_to(Uint8 stage, Uint8 act);
void battle_start(int number);
Bool FUN_8c090792(int stage);
void story_mark_cleared(int stage);
Bool egg_carrier_has_sunk(void);
void FUN_8c090818(void);
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
    Sint8 seqVars[512 / 8];
    Sint8 events_played[512 / 8];
    Uint8 unk_2e0[8];
    struct story_record story_records[8];
    Sint8 stage_clears[8][43];
};
extern int stage_last_cleared;
extern struct save SaveData[3];
void save_reset_all(void);
void save_store(void);
void save_store(void);
void save_update(void);
void save_load(void);
Bool FUN_8c088708(struct save *save);
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
void FUN_8c058438(int unused, struct task *player);
int FUN_8c0584e6(int character);
Bool thunk_FUN_8c081ba6(void);
struct task *thunk_FUN_8c081bec(void);
void FUN_8c0584fa(void);
void FUN_8c058502(void);
struct task *thunk_FUN_8c08395e(struct battle *battle);
struct task *thunk_FUN_8c083ebc(struct battle *battle);
void thunk_FUN_8c083f7e(struct battle *battle);
enum battle_outcome {
    BATTLE_RUNNING,
    BATTLE_WON,
    BATTLE_LOST
};
void battle_set_outcome(enum battle_outcome outcome);
enum battle_outcome battle_outcome(void);
Sint16 thunk_FUN_8c0829cc(int frames);
Sint16 thunk_FUN_8c082b9a(int unused);
void boot_finish(void);
int FUN_8c05859c(void);
struct save *FUN_8c0585a4(void);
enum carry_kind {
    CARRY_KIND_SMALL = 4,
    CARRY_KIND_MEDIUM,
    CARRY_KIND_LARGE,
    CARRY_KIND_SHAKE
};
Bool carry_set_kind(struct task_work *work, struct task_motion *motion,
                    enum carry_kind kind);
void ObjectMovableSRegularExecute(struct task *task);
void ObjectMovableMRegularExecute(struct task *task);
void carry_step_still(struct task *task);
void ObjectSetupInput(struct task_work *work, struct task_motion *motion);
void object_turn_back(struct task_work *work, NJS_VECTOR *vector);
void object_turn(struct task_work *work, NJS_VECTOR *vector);
void InitObjects(void);
Bool FUN_8c058fba(struct task *task);
Bool FUN_8c059108(struct task *task);
Bool FUN_8c0591fc(struct task *task);
Bool model_start_solid_scaled(struct task *task);
Bool ObjectGCollision(struct task *task);
Bool FUN_8c0596ee(struct task *task);
void FUN_8c059854(struct task_work *work);
NJS_OBJECT *object_add_world(NJS_OBJECT *model, struct task *task,
                             Sint32 flags);
extern char card_hex_digits[16];
void download_reset(void);
void download_start(void);
void download_end(void);
struct task;
enum ring_mode { RING_INIT, RING_WAIT, RING_SPARKLE, RING_DONE };
struct ring_vars {
    Float spin;
    Sint8 bit;
    Sint8 gone;
};
extern Sint32 ring_stagger;
extern NJS_TEXLIST ring_texlist;
void ring_reset_stagger(void);
void ring_step(struct task *task);
void ring_lose(Sint8 player);
void ring_scatter(Float x, Float y, Float z, int count);
void restart_clear(void);
Bool restart_keep_this_act(void);
void FUN_8c064df2(NJS_POINT3 *pos, struct angles *ang);
void FUN_8c064e36(NJS_POINT3 *pos, struct angles *ang);
void FUN_8c064e80(struct task *task);
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
void FUN_8c089468(void);
Bool path_create_manager(void);
Bool GetStatusOnPath(struct path *path, struct GetStatusOnPath *sample);
Bool path_find_segment(struct path *path, Float distance, Uint32 *index);
Bool path_get_distance(struct path *path, Uint32 index, Float *distance);
Float path_wrap(struct path *path, Float distance);
Float path_find_nearest(struct path *path, NJS_POINT3 *pos, NJS_POINT3 *nearest,
                        Float *along);
Bool path_spline_sample(struct path_spline *spline, struct GetStatusOnPath *sample);
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
Bool FUN_8c0de3ea(Uint8 player, Float scale);
Bool amy_call_to_handle(void);
Bool FUN_8c0de4ac(void);
struct task;
enum big_action {
    ACTION_STAND = 0,
    ACTION_FIDGET_START = 1,
    ACTION_FIDGET = 2,
    ACTION_FIDGET_END = 3,
    ACTION_STAND_UPHILL = 4,
    ACTION_STAND_DOWNHILL = 5,
    ACTION_LAND = 6,
    ACTION_WALK = 7,
    ACTION_TROT = 8,
    ACTION_RUN = 9,
    ACTION_SPRINT = 10,
    ACTION_FULL_SPEED = 11,
    ACTION_SPRING = 12,
    ACTION_FALL_START = 13,
    ACTION_FALL = 14,
    ACTION_JUMP = 15,
    ACTION_STOP = 16,
    ACTION_PUSH_START = 17,
    ACTION_PUSH = 18,
    ACTION_HURT = 19,
    ACTION_HURT_LAND = 20,
    ACTION_UPDRAFT = 21,
    ACTION_CRASH = 22,
    ACTION_CRASH_END = 23,
    ACTION_TURN = 24,
    ACTION_SLIDE = 25,
    ACTION_LIFT = 26,
    ACTION_HOLD_RUN = 27,
    ACTION_HOLD_STOP = 28,
    ACTION_HOLD_TURN = 29,
    ACTION_HOLD_STAND = 30,
    ACTION_HOLD_WALK = 31,
    ACTION_HANG_ON = 32,
    ACTION_PULL = 33,
    ACTION_SHAKE = 34,
    ACTION_GRIP_START = 35,
    ACTION_GRIP = 36,
    ACTION_HOLD_JUMP = 37,
    ACTION_HOLD_FALL_START = 38,
    ACTION_HOLD_FALL = 39,
    ACTION_HOLD_LAND = 40,
    ACTION_THROW_AT = 41,
    ACTION_THROW = 42,
    ACTION_AIR_THROW_AT = 43,
    ACTION_AIR_THROW = 44,
    ACTION_PUT_DOWN = 45,
    ACTION_LEDGE = 46,
    ACTION_FLUNG = 47,
    ACTION_CLEAR = 48,
    ACTION_SWING = 49,
    ACTION_REEL = 50,
    ACTION_REEL_HELD = 51,
    ACTION_CAST_START = 52,
    ACTION_CAST = 53,
    ACTION_CAST_SWING = 54,
    ACTION_REEL_DOWN = 55,
    ACTION_REEL_DOWN_RIGHT = 56,
    ACTION_REEL_DOWN_LEFT = 57,
    ACTION_REEL_RIGHT = 58,
    ACTION_REEL_LEFT = 59,
    ACTION_CATCH_SMALL = 60,
    ACTION_CATCH_MEDIUM = 61,
    ACTION_CATCH_LARGE = 62,
    ACTION_SNAP = 63,
    ACTION_SNAPPED = 64,
    ACTION_FLOAT_CAST_START = 66,
    ACTION_FLOAT_CAST = 67,
    ACTION_FLOAT_REEL_HELD = 68,
    ACTION_FLOAT_REEL_DOWN = 69,
    ACTION_FLOAT_REEL_DOWN_RIGHT = 70,
    ACTION_FLOAT_REEL_DOWN_LEFT = 71,
    ACTION_FLOAT_REEL_RIGHT = 72,
    ACTION_FLOAT_REEL_LEFT = 73,
    ACTION_HOLD_SMALL = 74,
    ACTION_HOLD_SMALL_WALK = 75,
    ACTION_HOLD_SMALL_RUN = 76,
    ACTION_LIFT_SMALL = 78,
    ACTION_PUT_DOWN_SMALL = 80,
    ACTION_SWIM_START = 86,
    ACTION_SWIM = 87,
    ACTION_DIVE_START = 88,
    ACTION_DIVE = 89,
    ACTION_FLOAT_UNDER_START = 90,
    ACTION_FLOAT_UNDER = 91,
    ACTION_FLOAT = 92,
    ACTION_HOLD_SHAKE_START = 93,
    ACTION_HOLD_SHAKE = 94,
    ACTION_HOLD_SHAKE_END = 95,
    ACTION_RIDE = 96,
    ACTION_BREATHE = 97,
    ACTION_DROWN = 98,
    ACTION_DOWN = 99,
    ACTION_DOWN_LAND = 100
};
extern struct task *big_lure;
extern struct task *big_catch;
extern int fishing_fish_count;
extern Bool fishing_shelter_ready;
void big_step(struct task *task);
Bool ChkFishingThrowNow(struct task *task);
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
Bool CheckPadReadMode(void);
void PadReadOnP(Uint8 player);
void PadReadOffP(Uint8 player);
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
void FUN_8c0c0580(struct task *task);
Bool FUN_8c0d1f72(struct task_work *work);
void FUN_8c0d1856(struct task *task);
struct task;
struct task_work;
extern int fishing_score;
extern Sint16 biggest_fish;
extern int biggest_fish_kind;
extern int fishing_record_weight;
extern Uint16 fishing_flags;
extern Float fishing_strain;
extern NJS_POINT3 fishing_cast_pos;
extern int fishing_fight_steps;
struct task *SetFishingCursorTask(struct task *big);
struct task *fishing_create_lure(struct task *big);
void fishing_hud_step(struct task *task);
void fishing_look_at_big(struct task *task);
Bool fishing_task_in_reach(struct task_work *work);
void fishing_show_catch(int weight, int kind);
int FUN_8c0e6dc0(void);
void fishing_hook_point(NJS_POINT3 *pos);
void fishing_catch_point(NJS_POINT3 *pos);
Float fishing_get_water(void);
Float FUN_8c0eb4f0(void);
void fishing_start_fight(void);
void fishing_reset(void);
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
Bool FUN_8c094d0c(void);
Bool Knuckles_KakeraGame_GetNearEmePos(NJS_POINT3 *from, NJS_POINT3 *pos, Float *distance);
Bool knuckles_find_piece(int id, NJS_POINT3 *pos);
Bool Knuckles_KakeraGame_Set_PutEme(int id, NJS_POINT3 *pos);
Bool knuckles_mark_piece(int id, NJS_POINT3 *pos);
void knuckles_force_dig(int sound);
struct task;
struct tails_vars {
    Uint8 player;
    Uint8 character;
    Uint16 struggle;
    Sint8 own[4];
};
void tails_step(struct task *task);
void FUN_8c0bfa2e(void);
void MilesSnowBoard(struct task *task);
Sint8 tails_set_tail_spin(int player);
Sint8 FUN_8c0bfcaa(int player);
struct task;
struct task *NpcMilesSet(struct task *leader);
void npc_kill(void);
Bool npc_follow(void);
Bool npc_wait(void);
Bool FUN_8c081b40(void);
Bool npc_remove_tails(void);
struct task *npc_create_tails(void);
Angle npc_angle_to(NJS_POINT3 *from, NJS_POINT3 *to, Float *distance,
                   Float *across);
void FUN_8c08267c(NJS_VECTOR *speed, Float *stroke, Angle *ang);
Bool FUN_8c082704(struct task *task, struct task *other);
void npc_set_disabled(Bool disabled);
Sint16 StageNameModeInit(int frames);
Sint16 StageNameMode(void);
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
void FUN_8c08167e(struct task *task);
struct task;
void sonic_step(struct task *task);
void sonic_board_start(struct task *task);
struct task;
struct task *InputHookInit(void);
Bool InputHookSet(void *id, NJS_POINT3 *pos, Angle *ang, Bool *active, Float radius,
              Sint32 flags);
void InputHookRelease(void);
void InputHookDelete(void *id);
struct task;
enum logo_result { LOGO_ADVERTISE = 1, LOGO_MOVIE = 3 };
extern Bool demo_playing;
extern int demo_event;
extern int demo_event_ended;
extern NJS_TEXLIST press_start_texlist;
void logo_start(void);
void boot_init(void);
int logo_step(void);
void FUN_8c08f30e(void);
void FUN_8c08f380(void);
void menu_begin(void);
int demo_next_mode(void);
void GM_WaitEventDemo(struct task *task);
extern int movie_request;
int movie_play(int list);
enum recorder_mode { RECORDER_RECORD, RECORDER_PLAY, RECORDER_DONE };
enum recording_kind { RECORDING_OFF, RECORDING_RECORD, RECORDING_PLAY };
struct pad_sample {
    Uint32 on;
    Uint16 l, r;
    Sint16 x1, y1;
};
extern Bool recording_on;
extern enum recorder_mode recording_mode;
extern enum recording_kind recording_kind;
extern int demo_next;
extern struct pad_sample *recording_next;
extern Uint32 recording_buttons;
extern void *dat_8c751454;
void FUN_8c034de0(void);
void sunaboard_sky_step(struct task *task);
extern struct object_kind sunaboard_object_kinds[];
void sunaboard_step(struct task *task);
struct shooting_flight {
    NJS_VECTOR offset;
    NJS_POINT3 pos;
    Float speed;
    Float alpha;
    struct angles ang;
    Uint8 unk_2c[8];
    int bullets;
    int phase;
    int charge;
};
struct shooting_scene {
    int kind;
    NJS_POINT3 *path;
    int *begin;
    int *end;
};
struct shooting_actor {
    struct task *task;
    Sint32 active;
};
struct scene_vars {
    Uint16 spin_x;
    Uint16 spin_y;
    Sint16 timer;
    Sint16 spin_z;
    Uint8 unk_08;
    Uint8 sounded;
    Sint8 scene;
    Sint8 frame;
};
enum scene_mode {
    SCENE_INIT = 0,
    SCENE_FLY = 1,
    SCENE_WAIT = 2,
    SCENE_FALL = 3,
    SCENE_GONE = 5
};
enum shooting_mode {
    SHOOTING_INIT,
    SHOOTING_FLY,
    SHOOTING_DOWN,
    SHOOTING_CLEAR,
    SHOOTING_SCORE,
    SHOOTING_EVENT1,
    SHOOTING_EVENT2,
    SHOOTING_AFTER,
    SHOOTING_SECOND,
    SHOOTING_FALL,
    SHOOTING_END
};
extern struct shooting_flight shooting_flight;
extern int shooting_path_index;
extern Bool shooting_path_running;
extern struct shooting_actor shooting_actors[512];
extern int shooting_actor_count;
extern NJS_POINT3 *shooting_path;
extern int shooting_path_count;
extern int shooting_act;
extern int dat_0cad53d8;
extern Float shooting_lives;
extern int shooting_score;
extern int shooting_course_part;
extern int dat_0cad53e8;
extern int dat_0cad53ec;
enum { REQUEST_EVENT1 = 1, REQUEST_EVENT2 = 2, REQUEST_CLEAR = 3 };
extern int shooting_request;
extern int shooting_stage_mode;
extern struct shooting_scene *shooting_scenes;
extern int dat_0cad53fc;
extern int dat_0cad5400;
void shooting_act1_step(struct task *task);
void shooting_act2_step(struct task *task);
void shooting_actors_clear(void);
void shooting_actors_add(struct task *task);
Bool shooting_event_playing(void);
void shooting_player_step(struct task *task);
Bool tornado_count_charge(void);
struct task;
void sound_system_init(void);
void FUN_8c092f28(void);
void sound_load_stage(void);
void sound_load_file(const char *name);
void sound_load_shot_bank(int bank, const char *name);
void sound_load_sequence_bank(int bank, const char *name);
void FUN_8c093980(int bank, const char *name);
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
int dsPlay_Dolby_time(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
int sound_play_around(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, Float radius, int updates);
void dsStop_num(int se);
void dsStop_id(int id);
void dsVolume_id(int id, int volume);
void dsPan_id(int id, int pan);
void dsPitch_id(int id, int pitch);
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
void FUN_8c095130(struct task *task);
void sound_load_alt_voice(void);
void sound_load_alt_field(void);
void sound_play_bank(Uint8 bank, Uint8 number);
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
void FUN_8c1077a4(struct task *task);
void ADX_Close(void);
void BGM_Play(int music);
void stream_stop_music(void);
Sint32 stream_music_state(void);
int stream_music_time(void);
Bool CameraFishingCatch(void);
void Serif_Play(int voice);
void stream_stop_voice(void);
Sint32 stream_voice_state(void);
int stream_voice_time(void);
void FUN_8c107b32(void);
void stream_unmute(void);
void stream_request_interlude(int music);
void stream_reset_music(void);
void stream_reset_voice(void);
void ADXTaskInit(void);
void stream_request_and_save_music(int music);
Bool stream_restore_music(void);
void practice_step(struct task *task);
enum beach_mode {
    BEACH_INIT,
    BEACH_ACT0,
    BEACH_ACT1,
    BEACH_ACT2,
    BEACH_END
};
void beach_step(struct task *task);
void beach_sky_step(struct task *task);
extern NJS_FOG_TABLE windy_fog_table;
extern NJS_COLOR windy_fog_color;
extern Uint32 windy_fog_shown;
void windy_step(struct task *task);
void windy_sky_step(struct task *task);
void twinkle_step(struct task *task);
void twinkle_sky_step(struct task *task);
void highway_step(struct task *task);
void highway_sky_step(struct task *task);
struct death_zone;
extern struct death_zone *mountain_death_zones[];
extern struct task_work *mountain_work;
struct mountain_vars {
    Float lava_moved;
};
void mountain_step(struct task *task);
void mountain_sky_step(struct task *task);
void knuckles_tutorial_create(struct task *task);
void fun_0c91335e(struct task *task);
void fun_0c9137a0(struct task *task);
void fun_0c913a20(int mode);
void fun_0c913bc6(struct task *task);
void fun_0c913c6e(struct task *task);
struct path;
struct path_point;
void sky_deck_step(struct task *task);
void sky_deck_sky_step(struct task *task);
void sky_deck_welcome(void);
struct trail_point {
    Sint32 wait;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
};
enum trail_volume_kind {
    TRAIL_UPRIGHT,
    TRAIL_LYING,
    TRAIL_BALL
};
struct trail_volume {
    struct task_work *owner;
    Sint32 kind;
    NJS_POINT3 center;
    Float reach;
    Float radius;
    Float height;
};
extern Sint8 sky_deck_started_act;
extern Sint8 sky_deck_act;
extern struct trail_point trail_points[32][5];
extern Sint32 trail_life[32];
extern struct trail_volume trail_volumes[20];
extern NJS_FOG_TABLE sky_deck_fog_table;
extern Uint32 sky_deck_fog_color;
extern Float sky_deck_shade;
extern Float sky_deck_fog_near;
extern Float sky_deck_fog_far;
extern Uint32 sky_deck_palettes_above[8][256 * 2];
extern Uint32 sky_deck_palettes_below[8][256 * 2];
extern int sky_deck_sky_mode;
extern NJS_POINT3 sky_deck_sky_pos;
extern Float sky_deck_sky_lift;
extern Float sky_deck_timeline_value;
extern int sky_deck_cloud_scroll;
extern int sky_deck_cloud_scroll_low;
extern Angle sky_deck_roll;
extern Angle sky_deck_pitch;
extern NJS_VECTOR dat_0caf373c;
extern Float sky_deck_timeline_rate;
extern int sky_deck_timeline_steps;
extern int sky_deck_clouds;
extern int sky_deck_cloud_wait;
extern NJS_COLOR sky_deck_cloud_uvs[32];
extern NJS_COLOR sky_deck_cloud_uvs_low[32];
extern int sky_deck_clock;
extern NJS_POINT3COL trail_line;
extern NJS_POINT3 trail_line_points[5];
extern NJS_COLOR trail_line_colors[5];
extern Float draft_lift;
extern Float draft_push;
void edge_0_step(struct task *task);
void branch_l_step(struct task *task);
void branch_s_step(struct task *task);
void pole_s_step(struct task *task);
void pole_l_step(struct task *task);
void base_l_step(struct task *task);
void rest_6_step(struct task *task);
void rest_45_step(struct task *task);
void block_0_step(struct task *task);
void block_1_step(struct task *task);
void block_2_step(struct task *task);
void block_3_step(struct task *task);
void block_4_step(struct task *task);
void block_5_step(struct task *task);
void cover_step(struct task *task);
void screw_step(struct task *task);
void launcher_step(struct task *task);
void block_6_step(struct task *task);
void block_7_step(struct task *task);
void rail_l_step(struct task *task);
void rail_s_step(struct task *task);
void fun_0c90226c(struct task *task);
void lantern_step(struct task *task);
void tower_i_step(struct task *task);
void rest_9_step(struct task *task);
void fun_0c902284(struct task *task);
void cold_fan_step(struct task *task);
void fun_0c902290(struct task *task);
void fun_0c902296(struct task *task);
void fun_0c90229c(struct task *task);
void fun_0c9022a2(struct task *task);
void fun_0c9022a8(struct task *task);
void fun_0c9022ae(struct task *task);
void fun_0c9022b4(struct task *task);
void carrier_step(struct task *task);
void carrier2_step(struct task *task);
void carrier3_step(struct task *task);
void fun_0c9022cc(struct task *task);
void fun_0c9022d2(struct task *task);
void fun_0c9022d8(struct task *task);
void fun_0c9022de(struct task *task);
void fun_0c9022e4(struct task *task);
void ctrltower_step(struct task *task);
void scope_step(struct task *task);
void edge_step(struct task *task);
void la_step(struct task *task);
void lb_step(struct task *task);
void lc_step(struct task *task);
void stop_step(struct task *task);
void s_wing_step(struct task *task);
void s_map_step(struct task *task);
void s_obj_step(struct task *task);
void s_eng_step(struct task *task);
Bool sky_deck_try_leave(struct task *task);
void next_act_step(struct task *task);
void sky_deck_voice_change_act_step(struct task *task);
void sky_deck_change_act_step(struct task *task);
void sky_deck_grip_start(struct task *task);
void hangpole_start(struct task *task);
void cyl_s_start(struct task *task);
void tank_h_start(struct task *task);
void top_0_start(struct task *task);
void radder_start(struct task *task);
void duct_start(struct task *task);
void untei_start(struct task *task);
void fence_l_start(struct task *task);
void fence_m_start(struct task *task);
void fence_s_start(struct task *task);
void hang_a_start(struct task *task);
void hang_b_start(struct task *task);
void hang_c_start(struct task *task);
struct path_owner_vars {
    Uint8 unk_00[4];
    struct path_point *points;
    struct path *path;
};
void trails_reset(void);
void trails_move(void);
void trails_draw(void);
void FUN_8c0b5460(struct task *task);
void trail_step(struct task *task);
void trail_destroy(struct task *task);
void trail_camera_step(struct task *task);
void trail_volume_set(struct task_work *owner, int kind, Bool force,
                      Float radius, Float height, Float x, Float y, Float z);
void t_colli_start(struct task *task);
void t_colli_step(struct task *task);
void t_colli_draw(struct task *task);
void t_colli_destroy(struct task *task);
void scroll_draw(struct task *task);
void draft_reset(void);
void draft_step(Uint16 act);
void w_wall_step(struct task *task);
void flap01_start(struct task *task);
void flap02_start(struct task *task);
void flap_step(struct task *task);
void homing_start(struct task *task);
void homing_step(struct task *task);
void homing_destroy(struct task *task);
void ruin_step(struct task *task);
void ruin_sky_step(struct task *task);
void icecap_step(struct task *task);
void icecap_sky_step(struct task *task);
void loader_poll_drive(void);
void loader_note_error(void *obj, Sint32 err);
void FUN_8c09cdd0(void);
void FUN_8c09d8c0(int character);
void *loader_read_alloc(char *name, int result);
void syMalloc_default_free(void *memory);
int thunk_FUN_8c09cbc0(char *name, void *dest);
int loader_read_prs(char *name, void *dest);
int loader_file_size(char *name);
void read_queue_init(void);
int read_queue_selected_slot(void);
Bool read_queue_add(char *name, void *dest);
void read_queue_cancel(void);
void FUN_8c09dafc(void);
extern int casino_request;
extern int casino_rings_deposited;
extern NJS_TEXLIST obj_casino9_texlist;
void casino_step(struct task *task);
void casino_set_texture(int acts);
struct death_zone;
extern struct death_zone *final_death_zones[];
void final_step(struct task *task);
void final_sky_step(struct task *task);
void final_light_step(struct task *task);
void shelter_step(struct task *task);
void shelter_sky_step(struct task *task);
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
void FUN_8c055776(struct bitmap *bitmap);
void bitmap_init_window(struct bitmap *bitmap);
void bitmap_clear(struct bitmap *bitmap);
void bitmap_newline(struct bitmap *bitmap);
void bitmap_print(struct bitmap *bitmap, const char *text);
void nwEditWinPrintf(struct bitmap *bitmap, const char *format, ...);
void bitmap_queue(struct bitmap *bitmap);
void bitmap_queue_add(struct bitmap *bitmap);
void bitmap_clear_queue(void);
void bitmap_flush_queue(void);
void bitmap_draw(struct bitmap *bitmap);
void FUN_8c05523a(struct bitmap *bitmap);
void bitmap_fade_out(struct bitmap *bitmap);
void bitmap_fade_in_text(struct bitmap *bitmap);
void bitmap_fade_out_text(struct bitmap *bitmap);
void bitmap_wait(struct bitmap *bitmap, int steps);
struct thread *bitmap_choose(const char *text);
struct thread *bitmap_choose_lines(int count, const char **lines);
void bitmap_show_pages(char **pages);
void FUN_8c055878(char **pages);
Bool bitmap_pages_active(void);
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
extern Uint8 history_counts[6 * 5];
void history_init(void);
void history_count_play(int character);
void history_count_clear(int character);
void history_write(void);
void history_restart(void);
void history_read(Uint16 *times, Uint32 *starts);
struct thread;
void thread_init(void);
void thread_destroy_all(void);
struct thread *thread_create(void *entry, void *arg, int size);
struct thread *thread_create_child(struct thread *parent, void *entry,
                                   void *arg, int size);
void FUN_8c099afa(struct thread *thread, void *entry, void *arg);
void thread_destroy(struct thread *thread);
void thread_yield(void);
struct thread *thread_insert_before(struct thread *thread, void *entry,
                                    void *arg, int size);
void *TH_GetWork(struct thread *thread);
void thread_set_status(struct thread *thread, int status);
int thread_get_status(struct thread *thread);
void thread_set_unk_1c(struct thread *thread, int value);
int thread_get_unk_1c(struct thread *thread);
void thread_set_destructor(struct thread *thread, void (*destructor)(void));
extern struct thread *thread_current;
void thread_next(void);
void thread_exit(void);
extern int debug_page;
extern Bool pause_flg;
void FUN_8c06c000(void);
Float timer_lap(void);
void timer_mark(void);
Float timer_elapsed(void);
Float timer_elapsed_and_mark(void);
Float timer_render_time(void);
void timer_show_counts(void);
enum vmu_request {
    VMU_REQUEST_CLEAR = 1,
    VMU_REQUEST_GAME_OVER = 3
};
struct vmu_frame {
    const Uint8 *bitmap;
    Uint32 updates;
};
struct vmu_point {
    Sint16 x;
    Sint16 y;
};
struct vmu_screen {
    Uint8 pixels[32][48];
    Sint8 ready;
    Sint8 direction;
    Sint8 port;
    Sint8 mode;
    Sint16 wait;
    Sint32 countdown;
    Uint16 frame;
    Uint16 timer;
    const struct vmu_frame *anim;
    Sint8 puzzles;
    Sint8 slides;
    Sint8 blank;
    Sint8 cursor;
    Sint8 blink;
    Sint8 tiles[(3 * 3)];
    Sint8 along_row;
    Sint16 look_wait;
    Sint16 roam_wait;
    struct vmu_point target;
    struct vmu_point pos;
    Uint32 lcd;
    Sint32 held;
    Sint32 pressed;
};
void vmu_request(int request);
Bool vmu_screen_due(struct vmu_screen *screen);
void vmu_init(void);
void FUN_8c109cb2(enum game_mode game_mode);
enum stage_mode {
    STAGE_ENTER,
    STAGE_ENTER_WAIT,
    STAGE_AGAIN,
    STAGE_AGAIN_WAIT,
    STAGE_FADE_IN,
    STAGE_CLEAR_FADE,
    STAGE_MISS_FADE,
    STAGE_GAME_OVER_FADE,
    STAGE_GO_TO_FADE,
    STAGE_WAIT,
    STAGE_RESTART_FADE,
    STAGE_RETRY_FADE,
    STAGE_QUIT_FADE,
    STAGE_ENDING,
    STAGE_PLAY,
    STAGE_PAUSE,
    STAGE_LEAVE,
    STAGE_GAME_OVER,
    STAGE_CONTINUE,
    STAGE_QUIT,
    STAGE_COMING_SOON,
    STAGE_TITLE_CARD,
    STAGE_TITLE_CARD_SHOW,
    STAGE_TRIAL_END,
    STAGE_CARD_ERROR
};
struct stage_event {
    Sint8 stage;
    Sint8 act;
    Sint16 character;
    Sint16 unk_04;
    Sint16 event;
    void (*destructor)(struct task *task);
};
struct start_point {
    Sint16 stage;
    Sint16 act;
    NJS_POINT3 pos;
    Angle ang_y;
};
struct return_point {
    Sint16 stage;
    Sint16 field;
    NJS_POINT3 pos;
    Angle ang_y;
};
struct back_color {
    Uint32 col1;
    Uint32 col2;
    Uint32 col3;
};
struct stage_exit {
    Sint8 movie;
    Uint8 stage;
    Uint8 first_stage;
    Uint8 first_act;
    Uint8 first_entrance;
    Uint8 again_stage;
    Uint8 again_act;
    Uint8 again_entrance;
};
enum later_kind { LATER_MUSIC, LATER_SOUND };
struct later_extra {
    int steps;
    int number;
    enum later_kind kind;
};
extern struct path amy_clear_path;
extern struct path sonic_clear_path;
extern struct path e102_clear_path;
extern struct path knuckles_clear_path;
Bool stage_start_event(void);
void GM_WaitEvent(struct task *task);
void GM_WaitEventS(struct task *task);
void FUN_8c04c868(struct task *task);
void FUN_8c04c86e(struct task *task);
Bool GM_CheckClearEvent(void);
void action_leave_cleared(void);
void FUN_8c04d830(void);
void FUN_8c04d920(void);
void stage_reset_counts(void);
void stage_reset_play(void);
void InitializeStage(void);
void GameInit(void);
int FUN_8c04e714(void);
int stage_run_action(void);
int stage_run_field(void);
int FUN_8c04eb7e(void);
int FUN_8c04ecd0(void);
void stage_stop(void);
void FUN_8c04ed1a(void);
void stage_unload(void);
void later_step(struct task *task);
void clear_wait_step(struct task *task);
void stage_create_players(void);
void stage_create_task(void);
void FUN_8c04f5ac(void);
void stage_keep_previous(void);
void stage_set_next_return(void);
void FUN_8c011524(void);
void FUN_8c04fb3a(Uint16 stage, Uint16 act);
Bool FUN_8c04fd50(void);
extern struct stage_event entry_events[];
extern struct stage_event clear_events[];
extern struct start_point sonic_starts[];
extern struct start_point tails_starts[];
extern struct start_point knuckles_starts[];
extern struct start_point big_starts[];
extern struct start_point amy_starts[];
extern struct start_point e102_starts[];
extern Sint16 sonic_bosses[];
extern Sint16 tails_bosses[];
extern Sint16 knuckles_bosses[];
extern Sint16 amy_bosses[];
extern Sint16 e102_bosses[];
extern Sint16 big_bosses[];
extern struct return_point sonic_returns[];
extern struct return_point tails_returns[];
extern struct return_point knuckles_returns[];
extern struct return_point amy_returns[];
extern struct return_point big_returns[];
extern struct return_point e102_returns[];
extern struct return_point *returns[8];
extern Sint16 stage_end_kind;
extern Sint16 ssPauseEnable;
extern Sint16 fishing_reset_flag;
extern struct return_point *return_point;
extern void (*stage_steps[43])(struct task *task);
extern struct back_color back_colors[43];
extern void (*sky_steps[43])(struct task *task);
extern struct stage_exit sonic_exits[];
extern struct stage_exit tails_exits[];
extern struct stage_exit knuckles_exits[];
extern struct stage_exit amy_exits[];
extern struct stage_exit e102_exits[];
extern struct stage_exit big_exits[];
extern struct stage_exit *exits[8];
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
extern Sint16 stage_retry_count;
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
void pause_enable(void)
{
    ssPauseEnable = 1;
}
void pause_disable(void)
{
    ssPauseEnable = 0;
}
void boot_new_game(void)
{
    int found;
    set_character(0);
    play_time_reset();
    hud_reset();
    progress_init();
    messages_shown = 0;
    stage_begin();
    save_reset_all();
    found = save_file_exists();
    if (found & 1) {
        save_read();
    } else {
    }
    debug_unlocked = 0;
    srand(0xdead0cab);
}
void GM_WaitEvent(struct task *task)
{
    if (!EV_CheckCansel()) {
        DestroyTask(task);
        ufExitSystem();
        if (stage_current != 19) {
            ssPauseEnable = 1;
        }
        WakeTimer();
    }
}
void GM_WaitEventS(struct task *task)
{
    ADX_Close();
    EV_Load2((Uint16)task->work->timer);
    EV_Exec2();
    task->step = GM_WaitEvent;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool stage_start_event(void)
{
    struct stage_event *event = entry_events;
    struct task *task;
    if (demo_playing) {
        demo_event_ended = 0;
        if (demo_event >= 0) {
            CreateElementalTask(0, 0, GM_WaitEventDemo);
            return (1);
        }
    }
    if (game_mode == GAME_MODE_TRIAL) {
        return (0);
    }
    for (; event->stage != 43; event++) {
        if (event->stage == stage_current && event->act == act_current &&
            event->character == character_current) {
            if (EV_CheckExec(event->event)) {
            } else {
                task = CreateElementalTask(0x2, 0, GM_WaitEventS);
                task->work->timer = event->event;
                task->destructor = event->destructor;
                return (1);
            }
        }
    }
    return (0);
}
void FUN_8c04c868(struct task *task)
{
    stage_end(STAGE_END_CLEAR);
}
void FUN_8c04c86e(struct task *task)
{
    task->step = GM_WaitEvent;
    task->destructor = FUN_8c04c868;
}
Bool GM_CheckClearEvent(void)
{
    struct stage_event *event = clear_events;
    if (game_mode == GAME_MODE_TRIAL) {
        return (0);
    }
    for (; event->stage != 43; event++) {
        if (event->stage == stage_current && event->act == act_current &&
            event->character == character_current) {
            if (!EV_CheckExec(event->event)) {
                ADX_Close();
                EV_Load2(event->event);
                EV_Exec2();
                CreateElementalTask(0, 0, FUN_8c04c86e);
                event_ending = -1;
                return (1);
            }
        }
    }
    return (0);
}
enum stage_group stage_group(void)
{
    int stage = stage_current;
    enum stage_group group;
    if (stage <= 14) {
        group = STAGE_GROUP_ACTION;
    } else if (stage <= 25) {
        group = STAGE_GROUP_ACTION;
    } else if (stage <= 34) {
        group = STAGE_GROUP_FIELD;
    } else if (stage <= 38) {
        group = STAGE_GROUP_ACTION;
    } else {
        group = STAGE_GROUP_FIELD;
    }
    return group;
}
enum stage_group stage_begin(void)
{
    stage_mode = STAGE_TITLE_CARD;
    stage_end_kind = STAGE_END_NONE;
    movie_request = 0;
    world_reset_gravity();
    pause_choice = PAUSE_CONTINUE;
    pause_hidden = 0;
    return_point = ((void *)0);
    if (SaveData[save_slot].flags & 0x2) {
        messages_shown = 0;
    } else {
        messages_shown = 1;
    }
    if (FUN_8c08a4b2() < 4) {
        FUN_8c089fbc();
    }
    return stage_group();
}
static void start_play(void)
{
    GameInit();
    return;
}
static void stop_play(void)
{
    stage_stop();
    return;
}
static void stop_ended(void)
{
    FUN_8c04ed1a();
    stage_end_kind = STAGE_END_NONE;
    return;
}
static void forget_end(void)
{
    stage_end_kind = STAGE_END_NONE;
    return;
}
static void reset_steps(void)
{
    stage_mode = STAGE_TITLE_CARD;
    stage_end_kind = STAGE_END_NONE;
    return;
}
static void pause_sound(void)
{
    dsPlay_oneshot(3, 0, 0, 0);
    return;
}
static void pause_restart(void)
{
    stage_mode = STAGE_PLAY;
    stage_end(STAGE_END_RESTART);
    return;
}
static Sint16 end_kind(void)
{
    return stage_end_kind;
}
static void stop_time_and_pausing(void)
{
    SleepTimer();
    ssPauseEnable = 0;
    return;
}
static enum stage_group group(void)
{
    return stage_group();
}
static void save_now(void)
{
    save_write_wait();
    return;
}
static void step_tasks(void)
{
    task_draw_all();
    return;
}
static void cover(NJS_COLOR *color)
{
    fade_set_cover(color);
    return;
}
static void fade_from_black(void)
{
    FUN_8c042f0e();
    return;
}
static void load_textures(int character)
{
    texture_load_character(character);
    LoadPlayerMotionData(0);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Sint16 FUN_8c04ca40(void)
{
    Sint16 result;
    Sint16 status;
    Uint8 stage;
    Uint8 act;
    NJS_COLOR color;
    switch (stage_mode) {
    case STAGE_TITLE_CARD:
        if (demo_playing) {
            stage_mode = STAGE_ENTER;
            break;
        } else {
            color.argb.b = color.argb.g = color.argb.r = color.argb.a = 0;
            fade_set_cover(&color);
            status = thunk_FUN_8c0829cc(5);
            if (status == -1) {
                stage_mode = STAGE_ENTER;
                break;
            } else {
                stage_mode++;
            }
        }
        break;
    case STAGE_TITLE_CARD_SHOW:
        status = thunk_FUN_8c082b9a(0);
        if (status == 1) {
            pause_flg = (0);
            InitializeStage();
            start_play();
            FUN_8c042f0e();
            FUN_8c01493e();
            while (fade_in_step() != 0) {
            }
            if (stage_start_event()) {
                stage_mode = STAGE_FADE_IN;
            } else {
                stage_mode = STAGE_FADE_IN;
            }
        }
        break;
    case STAGE_ENTER:
        pause_flg = (0);
        FUN_8c042f0e();
        stage_mode = STAGE_ENTER_WAIT;
    case STAGE_ENTER_WAIT:
        if (fade_in_step() == 0) {
            InitializeStage();
            start_play();
            FUN_8c01493e();
            if (stage_start_event()) {
                stage_mode = STAGE_FADE_IN;
            } else {
                stage_mode = STAGE_FADE_IN;
            }
        }
        break;
    case STAGE_AGAIN:
        FUN_8c042f0e();
        stage_mode = STAGE_AGAIN_WAIT;
    case STAGE_AGAIN_WAIT:
        if (fade_in_step() == 0) {
            start_play();
            stage_mode = STAGE_FADE_IN;
        }
        break;
    case STAGE_FADE_IN:
        result = fade_in_step();
        stage_run_action();
        if (result != 0) {
            stage_mode = STAGE_PLAY;
            if (!EV_CheckCansel()) {
                ufExitSystem();
                WakeTimer();
                if (recording_kind == RECORDING_OFF) {
                    ssPauseEnable = 1;
                }
            }
        }
        break;
    case STAGE_PLAY:
        stage_run_action();
        if (stage_mode == STAGE_CARD_ERROR) {
            dsPlay_oneshot(3, 0, 0, 0);
            pause_choice = PAUSE_CONTINUE;
            sound_pause();
            sound_mute();
            break;
        }
        if (end_kind() == STAGE_END_QUIT) {
            forget_end();
            if ((stage_current <= 14 ||
                 stage_current == 35 ||
                 stage_current == 38) &&
                !demo_playing) {
                stage_set_next_return();
                stage_mode = STAGE_GO_TO_FADE;
            } else {
                stage_mode = STAGE_QUIT_FADE;
            }
            fade_out_start();
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if (end_kind() == STAGE_END_CLEAR) {
            forget_end();
            if (stage_current == 19) {
                pause_flg = (1);
                stage_mode = STAGE_ENDING;
                fade_out_start();
                PadReadOff();
                SleepTimer();
                ssPauseEnable = 0;
            } else {
                stage_mode = STAGE_CLEAR_FADE;
                if (event_ending) {
                    action_leave_cleared();
                    break;
                }
                fade_out_start();
                PadReadOff();
                stop_time_and_pausing();
            }
        } else if (end_kind() == STAGE_END_MISS) {
            forget_end();
            if (game_mode == GAME_MODE_TRIAL &&
                stage_current > 14 &&
                stage_current <= 25) {
                stage_mode = STAGE_MISS_FADE;
                fade_out_start();
            } else if (FUN_8c08a4b2() <= 0) {
                if (game_mode == GAME_MODE_TRIAL) {
                    stage_mode = STAGE_MISS_FADE;
                    fade_out_start();
                } else {
                    stage_mode = STAGE_GAME_OVER_FADE;
                    game_over_start();
                }
            } else {
                stage_mode = STAGE_MISS_FADE;
                fade_out_start();
            }
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if (end_kind() == STAGE_END_GO_TO) {
            forget_end();
            stage_mode = STAGE_GO_TO_FADE;
            fade_out_start();
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if (end_kind() == STAGE_END_RESTART) {
            forget_end();
            if (stage_current == 35) {
                stage_mode = STAGE_RESTART_FADE;
                fade_out_start();
            } else if (game_mode != GAME_MODE_TRIAL && FUN_8c08a4b2() <= 0) {
                stage_mode = STAGE_GAME_OVER_FADE;
                game_over_start();
            } else {
                stage_mode = STAGE_MISS_FADE;
                fade_out_start();
            }
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if (end_kind() == STAGE_END_RETRY) {
            forget_end();
            if (FUN_8c08a4b2() <= 0) {
                stage_mode = STAGE_GAME_OVER_FADE;
                game_over_start();
            } else {
                stage_mode = STAGE_RETRY_FADE;
                fade_out_start();
            }
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if ((per[0]->press & (1 << 3)) || demo_event_ended) {
            if (recording_kind != RECORDING_OFF) {
                if (demo_event >= 0 && demo_event_ended) {
                    stop_ended();
                    stage_mode = STAGE_QUIT;
                } else {
                    stage_end(STAGE_END_QUIT);
                }
                if (!demo_event_ended) {
                    recording_kind = RECORDING_OFF;
                }
            } else if (perG[0].on & (1 << 3)) {
                if (ssPauseEnable == 1 && !EV_CheckCansel()) {
                    dsPlay_oneshot(3, 0, 0, 0);
                    pause_choice = PAUSE_CONTINUE;
                    stage_mode = STAGE_PAUSE;
                    sound_pause();
                    sound_mute();
                }
            }
        } else {
            if (((per[0]->press & (1 << 17)) &&
                 (per[0]->on & (1 << 16))) ||
                ((per[0]->on & (1 << 17)) &&
                 (per[0]->press & (1 << 16)))) {
                debug_name_frame();
            } else if ((per[0]->press & ((1 << 10) | (1 << 9) | (1 << 2) | (1 << 1))) &&
                       (per[0]->on & ((1 << 10) | (1 << 9) | (1 << 2) | (1 << 1))) == ((1 << 10) | (1 << 9) | (1 << 2) | (1 << 1))) {
                hud_hidden = ~hud_hidden;
            }
        }
        break;
    case STAGE_PAUSE:
        FUN_8c04eb7e();
        if (per[0]->press & (1 << 3)) {
            pause_sound();
            if (*(Uint16 *)&pause_choice == PAUSE_CONTINUE) {
                stage_mode = STAGE_PLAY;
            } else if (pause_choice == PAUSE_RESTART) {
                pause_restart();
            } else {
                history_write();
                if (game_mode == GAME_MODE_TRIAL) {
                    FUN_8c04ed1a();
                    stage_mode = STAGE_TRIAL_END;
                } else if (act_current >= 1 && stage_current == 35) {
                    FUN_8c04ed1a();
                    stage_mode = STAGE_QUIT;
                } else if (stage_current <= 14 ||
                           stage_current == 35 ||
                           stage_current == 38) {
                    stage_mode = STAGE_PLAY;
                    stage_set_next_return();
                    act = act_next;
                    stage = stage_next;
                    stage_fade_to(stage, act);
                    download_reset();
                } else {
                    FUN_8c04ed1a();
                    stage_mode = STAGE_QUIT;
                }
            }
            if (recording_kind == RECORDING_OFF) {
                recording_on = (0);
            } else {
                lives_add(1);
                stage_end(STAGE_END_MISS);
            }
            if (pause_choice != PAUSE_CONTINUE) {
                sound_end_act();
            } else {
                sound_resume(15);
            }
            sound_unmute();
        }
        break;
    case STAGE_CLEAR_FADE:
        result = fade_out_step();
        stage_run_action();
        if (result != 0) {
            history_write();
            stop_ended();
            story_mark_cleared(stage_current);
            if (act_current >= 1 && stage_current == 35) {
                stage_mode = STAGE_QUIT;
            } else if (game_mode == GAME_MODE_TRIAL) {
                if (FUN_8c04fd50()) {
                    stage_mode = STAGE_LEAVE;
                } else {
                    stage_mode = STAGE_TRIAL_END;
                }
            } else {
                stage_set_next_exit();
                stage_mode = STAGE_LEAVE;
            }
            save_update_write_wait();
        }
        break;
    case STAGE_MISS_FADE:
        result = fade_out_step();
        stage_run_action();
        if (result != 0) {
            stop_ended();
            if (game_mode == GAME_MODE_TRIAL &&
                stage_current > 14 &&
                stage_current <= 25) {
                stage_mode = STAGE_AGAIN;
            } else if (game_mode == GAME_MODE_TRIAL) {
                if (FUN_8c08a4b2() == 0) {
                    stage_mode = STAGE_TRIAL_END;
                } else {
                    lives_add(-1);
                    stage_mode = STAGE_AGAIN;
                }
            } else {
                lives_add(-1);
                stage_mode = STAGE_AGAIN;
            }
            stage_retry_count++;
            FUN_8c089fb4();
        }
        break;
    case STAGE_RETRY_FADE:
        result = fade_out_step();
        stage_run_action();
        if (result != 0) {
            stop_ended();
            lives_add(-1);
            if (game_mode == GAME_MODE_TRIAL) {
                stage_mode = STAGE_TRIAL_END;
            } else {
                stage_mode = STAGE_FADE_IN;
            }
            stage_retry_count++;
            task_destroy_all();
            restart_clear();
            world_reset_gravity();
            thunk_FUN_8c608734();
            SleepTimer();
            if (character_current == 3) {
                FUN_8c094d0c();
            } else if (character_current == 7) {
                fishing_reset();
            }
            heap_init();
            task_init();
            CreateElementalTask(0x2, 8, SetObject);
            FUN_8c04f5ac();
            stage_create_task();
            FUN_8c089fb4();
            start_play();
            FUN_8c042f0e();
            while (fade_in_step() != 0) {
            }
        }
        break;
    case STAGE_GAME_OVER_FADE:
        result = GameOver(continue_choice);
        stage_run_action();
        if (result != 0) {
            stop_ended();
            stage_mode = STAGE_GAME_OVER;
            FUN_8c089fb4();
        }
        break;
    case STAGE_RESTART_FADE:
        result = fade_out_step();
        stage_run_action();
        if (result != 0) {
            stop_ended();
            if (stage_current != 35) {
                lives_add(-1);
                stage_retry_count++;
            }
            FUN_8c089fb4();
            if (stage_current == 9) {
                casino_rings_deposited = 0;
            }
            stage_mode = STAGE_AGAIN;
        }
        break;
    case STAGE_GO_TO_FADE:
        result = fade_out_step();
        stage_run_action();
        if (result != 0) {
            FUN_8c04d830();
        }
        break;
    case STAGE_WAIT:
        if (fade_in_step() == 0) {
            stage_mode = STAGE_FADE_IN;
        }
        break;
    case STAGE_QUIT_FADE:
        result = fade_out_step();
        stage_run_action();
        if (result != 0) {
            stop_ended();
            if (demo_playing) {
                stage_mode = STAGE_QUIT;
            } else {
                stage_mode = STAGE_GAME_OVER;
            }
        }
        break;
    case STAGE_ENDING:
        stop_ended();
        stage_unload();
        if (player_record != ((void *)0)) {
            player_record->section = -1;
            event_flag_set(78);
            save_now();
        }
        stage_mode = STAGE_TITLE_CARD;
        return STAGE_STEP_STAFF_ROLL;
    case STAGE_LEAVE:
        stage_unload();
        stage_go_to_next();
        if (movie_request) {
            if (movie_play(movie_request) < 0) {
                reset_steps();
                return STAGE_STEP_RESET;
            }
            stage_mode = STAGE_ENTER;
        } else if (stage_previous == 34) {
            stage_mode = STAGE_ENTER;
        } else if (stage_current == 33 &&
                   act_current == MYSTIC_RUINS_BASE) {
            stage_mode = STAGE_ENTER;
        } else if (stage_previous > 14 &&
                   stage_previous <= 25) {
            stage_mode = STAGE_ENTER;
        } else {
            stage_mode = STAGE_TITLE_CARD;
        }
        return group();
    case STAGE_GAME_OVER:
        stage_unload();
        hud_reset();
        stage_mode = STAGE_CONTINUE;
        continue_choice = 0;
        continue_timer = 1200;
        heap_init();
        task_init();
        history_write();
        vmu_request(VMU_REQUEST_GAME_OVER);
        ADXTaskInit();
        stream_request_interlude(MUSIC_CONTINUE);
    case STAGE_CONTINUE:
        if (((Sint32)(pad_press_repeat[0]) & (Sint32)(pad_choose_buttons))) {
            sound_kill_all();
            task_destroy_all();
            FUN_8c0430e0();
            if (continue_choice) {
                stage_mode = STAGE_TITLE_CARD;
                return STAGE_STEP_QUIT;
            } else {
                stage_current = stage_loaded;
                act_current = act_loaded;
                stage_mode = STAGE_TITLE_CARD;
                return 0;
            }
        }
        if (continue_timer-- <= 0) {
            sound_kill_all();
            task_destroy_all();
            FUN_8c0430e0();
            stage_mode = STAGE_TITLE_CARD;
            return STAGE_STEP_QUIT;
        }
        if (pad_press_repeat[0] &
            ((1 << 17) | (1 << 16) | (1 << 7) | (1 << 6))) {
            continue_choice = continue_choice ^ 1;
        }
        GameOver(continue_choice);
        pad_scan();
        loop_count = 0;
        step_tasks();
        break;
    case STAGE_QUIT:
        stage_unload();
        stage_mode = STAGE_TITLE_CARD;
        continue_choice = 0;
        return STAGE_STEP_QUIT;
    case STAGE_COMING_SOON:
        result = coming_soon_step();
        if (result != 0) {
            task_destroy_all();
            stage_go_to_next();
            stage_mode = STAGE_TITLE_CARD;
            return STAGE_STEP_QUIT;
        }
        break;
    case STAGE_TRIAL_END:
        stage_unload();
        stage_mode = STAGE_TITLE_CARD;
        return STAGE_STEP_QUIT;
    case STAGE_CARD_ERROR:
        FUN_8c04ecd0();
        break;
    default:
        stage_mode = STAGE_LEAVE;
        break;
    }
    if (pad_quit_pressed(0)) {
        switch (stage_mode) {
        case STAGE_AGAIN:
        case STAGE_AGAIN_WAIT:
        case STAGE_FADE_IN:
        case STAGE_CLEAR_FADE:
        case STAGE_MISS_FADE:
        case STAGE_GO_TO_FADE:
        case STAGE_QUIT_FADE:
        case STAGE_PLAY:
        case STAGE_PAUSE:
            FUN_8c04ed1a();
            stage_unload();
            break;
        case STAGE_LEAVE:
        case STAGE_GAME_OVER:
        case STAGE_QUIT:
            stage_unload();
            break;
        case STAGE_GAME_OVER_FADE:
            FUN_8c04ed1a();
            stage_unload();
            break;
        case STAGE_CONTINUE:
            FUN_8c0430e0();
            break;
        }
        reset_steps();
        return STAGE_STEP_RESET;
    }
    return 0;
}
void action_leave_cleared(void)
{
    stop_ended();
    story_mark_cleared(stage_current);
    if (game_mode == GAME_MODE_TRIAL) {
        FUN_8c04fd50();
    } else {
        stage_set_next_exit();
    }
    stage_mode = 17;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c04d830(void)
{
    Sint16 delta;
    ADX_Close();
    if (stage_next == stage_current) {
        stage_mode = STAGE_FADE_IN;
        delta = act_next - act_current;
        world_change_act(delta);
        placement_change_act(delta);
        camera_change_act(delta);
        stage_change_act(delta);
        stage_place_player(playertwp[0]);
        SetInputP(0, 24);
        forget_end();
        FUN_8c042f0e();
        while (fade_in_step() != 0) {
        }
    } else {
        FUN_8c04ed1a();
        stage_end_kind = 0;
        stage_mode = STAGE_GAME_OVER;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c04d920(void)
{
    Sint16 delta;
    ADX_Close();
    if (stage_next == stage_current) {
        stage_mode = STAGE_FADE_IN;
        delta = act_next - act_current;
        world_change_act(delta);
        placement_change_act(delta);
        camera_change_act(delta);
        stage_previous = stage_current;
        act_previous = act_current;
        stage_change_act(delta);
        stage_place_player(playertwp[0]);
        SetInputP(0, 24);
        forget_end();
        FUN_8c042f0e();
        while (fade_in_step() != 0) {
        }
    } else {
        stage_stop();
        forget_end();
        stage_mode = STAGE_GAME_OVER;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Sint16 FUN_8c04da20(void)
{
    Sint16 result;
    Sint16 status;
    Sint16 delta;
    int found;
    NJS_COLOR color;
    Uint32 press;
    switch (stage_mode) {
    case STAGE_TITLE_CARD:
        if (stage_current == 34 ||
            (character_current == 3 &&
             !EV_CheckExec(128)) ||
            (stage_current == 33 &&
             act_current == MYSTIC_RUINS_BASE) ||
            demo_playing) {
            stage_mode = STAGE_ENTER;
            break;
        } else {
            color.argb.b = color.argb.g = color.argb.r = color.argb.a = 0;
            fade_set_cover(&color);
            status = thunk_FUN_8c0829cc(5);
            if (status == -1) {
                stage_mode = STAGE_ENTER;
                break;
            } else {
                stage_mode++;
            }
        }
        break;
    case STAGE_TITLE_CARD_SHOW:
        status = thunk_FUN_8c082b9a(0);
        if (status == 1) {
            pause_flg = (0);
            InitializeStage();
            story_start_act();
            start_play();
            FUN_8c042f0e();
            FUN_8c01493e();
            while (fade_in_step() != 0) {
            }
            if (stage_start_event()) {
                stage_mode = STAGE_FADE_IN;
            } else {
                stage_mode = STAGE_FADE_IN;
            }
        }
        break;
    case STAGE_ENTER:
        pause_flg = (0);
        FUN_8c042f0e();
        stage_mode = STAGE_ENTER_WAIT;
    case STAGE_ENTER_WAIT:
        if (!card_saving) {
            if (fade_in_step() == 0) {
                InitializeStage();
                story_start_act();
                start_play();
                while (fade_in_step() != 0) {
                }
                stage_start_event();
                stage_mode = STAGE_FADE_IN;
            }
        }
        break;
    case STAGE_AGAIN:
        FUN_8c042f0e();
        stage_mode = STAGE_AGAIN_WAIT;
    case STAGE_AGAIN_WAIT:
        if (fade_in_step() == 0) {
            story_start_act();
            start_play();
            stage_mode = STAGE_FADE_IN;
        }
        break;
    case STAGE_FADE_IN:
        result = fade_in_step();
        SeqCtrl();
        stage_run_field();
        if (result != 0) {
            stage_mode = STAGE_PLAY;
            if (!EV_CheckCansel()) {
                ufExitSystem();
            }
            WakeTimer();
            ssPauseEnable = 1;
        }
        break;
    case STAGE_PLAY:
        SeqCtrl();
        if (story_ended) {
            stage_end(STAGE_END_CLEAR);
        }
        stage_run_field();
        if (stage_mode == STAGE_CARD_ERROR) {
            dsPlay_oneshot(3, 0, 0, 0);
            pause_choice = PAUSE_CONTINUE;
            sound_pause();
            sound_mute();
            break;
        }
        if (end_kind() == STAGE_END_QUIT) {
            forget_end();
            stage_mode = STAGE_QUIT_FADE;
            fade_out_start();
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if (end_kind() == STAGE_END_CLEAR) {
            forget_end();
            if (!story_ended) {
                if (event_ending) {
                    stage_mode = STAGE_LEAVE;
                    stop_play();
                } else {
                    stage_mode = STAGE_CLEAR_FADE;
                    fade_out_start();
                }
            } else {
                pause_flg = (1);
                stage_mode = STAGE_ENDING;
            }
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if (end_kind() == STAGE_END_MISS) {
            forget_end();
            if (FUN_8c08a4b2() > 0) {
                fade_out_start();
                stage_mode = STAGE_MISS_FADE;
            } else {
                game_over_start();
                stage_mode = STAGE_GAME_OVER_FADE;
            }
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if (end_kind() == STAGE_END_GO_TO) {
            forget_end();
            stage_mode = STAGE_GO_TO_FADE;
            if (event_ending) {
                FUN_8c04d920();
            } else {
                stage_mode = STAGE_GO_TO_FADE;
                fade_out_start();
            }
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if (end_kind() == STAGE_END_RESTART &&
                   stage_current == 42) {
            forget_end();
            stage_mode = STAGE_RESTART_FADE;
            fade_out_start();
            PadReadOff();
            SleepTimer();
            ssPauseEnable = 0;
        } else if ((per[0]->press & (1 << 3)) || demo_event_ended) {
            if (recording_kind != RECORDING_OFF) {
                if (demo_event >= 0 && demo_event_ended) {
                    stop_play();
                    forget_end();
                    stage_mode = STAGE_QUIT;
                } else {
                    stage_end(STAGE_END_QUIT);
                }
                if (!demo_event_ended) {
                    recording_kind = RECORDING_OFF;
                }
            } else if (perG[0].on & (1 << 3)) {
                if (ssPauseEnable == 1 && !EV_CheckCansel()) {
                    dsPlay_oneshot(3, 0, 0, 0);
                    pause_choice = PAUSE_CONTINUE;
                    stage_mode = STAGE_PAUSE;
                    sound_pause();
                    sound_mute();
                }
            }
        } else {
            press = per[0]->press;
            if (((press & (1 << 17)) && (per[0]->on & (1 << 16))) ||
                ((per[0]->on & (1 << 17)) && (press & (1 << 16)))) {
                debug_name_frame();
            } else if ((per[0]->press & ((1 << 10) | (1 << 9) | (1 << 2) | (1 << 1))) &&
                       (per[0]->on & ((1 << 10) | (1 << 9) | (1 << 2) | (1 << 1))) == ((1 << 10) | (1 << 9) | (1 << 2) | (1 << 1))) {
                hud_hidden = ~hud_hidden;
            }
        }
        break;
    case STAGE_PAUSE:
        FUN_8c04eb7e();
        if (per[0]->press & (1 << 3)) {
            pause_sound();
            if (*(Uint16 *)&pause_choice == PAUSE_CONTINUE) {
                stage_mode = STAGE_PLAY;
            } else if (pause_choice == PAUSE_RESTART) {
                pause_restart();
            } else {
                history_write();
                stop_play();
                stage_mode = STAGE_QUIT;
                if (stage_current >= 39 &&
                    stage_current <= 42) {
                    alife_save_wait();
                }
            }
            if (recording_kind == RECORDING_OFF) {
                recording_on = (0);
            } else {
                lives_add(1);
                stage_end(STAGE_END_MISS);
            }
            if (pause_choice != PAUSE_CONTINUE) {
                sound_end_act();
            } else {
                sound_resume(15);
            }
            sound_unmute();
        }
        break;
    case STAGE_CLEAR_FADE:
        result = fade_out_step();
        SeqCtrl();
        stage_run_field();
        if (result != 0) {
            history_write();
            stop_play();
            forget_end();
            stage_mode = STAGE_LEAVE;
        }
        break;
    case STAGE_MISS_FADE:
        result = fade_out_step();
        stage_run_field();
        if (result != 0) {
            stop_play();
            forget_end();
            lives_add(-1);
            stage_mode = STAGE_AGAIN;
            FUN_8c089fb4();
        }
        break;
    case STAGE_GAME_OVER_FADE:
        result = GameOver(continue_choice);
        stage_run_field();
        if (result != 0) {
            stop_play();
            forget_end();
            stage_mode = STAGE_GAME_OVER;
            FUN_8c089fb4();
        }
        break;
    case STAGE_GO_TO_FADE:
        result = fade_out_step();
        SeqCtrl();
        stage_run_field();
        if (result != 0) {
            FUN_8c04d920();
        }
        break;
    case STAGE_QUIT_FADE:
        result = fade_out_step();
        stage_run_field();
        if (result != 0) {
            stop_play();
            forget_end();
            stage_mode = STAGE_QUIT;
        }
        break;
    case STAGE_ENDING:
        stop_play();
        forget_end();
        stage_unload();
        stage_mode = STAGE_TITLE_CARD;
        color.color = 0;
        cover(&color);
        return STAGE_STEP_STAFF_ROLL;
    case STAGE_RESTART_FADE:
        result = fade_out_step();
        stage_run_field();
        if (result != 0) {
            stop_play();
            forget_end();
            delta = act_loaded - act_current;
            placement_change_act(delta);
            stage_change_act(delta);
            stage_mode = STAGE_AGAIN;
        }
        break;
    case STAGE_LEAVE:
        stage_unload();
        stage_go_to_next();
        if (movie_request) {
            if (movie_play(movie_request) < 0) {
                reset_steps();
                return STAGE_STEP_RESET;
            }
            stage_mode = STAGE_ENTER;
        } else if (stage_previous == 34) {
            stage_mode = STAGE_ENTER;
        } else if (stage_current == 33 &&
                   act_current == MYSTIC_RUINS_BASE) {
            stage_mode = STAGE_ENTER;
        } else {
            stage_mode = STAGE_TITLE_CARD;
        }
        return group();
    case STAGE_GAME_OVER:
        stage_unload();
        stage_mode = STAGE_CONTINUE;
        continue_choice = 0;
        continue_timer = 1200;
        heap_init();
        task_init();
        history_write();
        vmu_request(VMU_REQUEST_GAME_OVER);
        ADXTaskInit();
        stream_request_interlude(MUSIC_CONTINUE);
    case STAGE_CONTINUE:
        if (((Sint32)(pad_press_repeat[0]) & (Sint32)(pad_choose_buttons))) {
            sound_kill_all();
            task_destroy_all();
            FUN_8c0430e0();
            if (continue_choice) {
                stage_mode = STAGE_TITLE_CARD;
                return STAGE_STEP_QUIT;
            } else {
                hud_reset();
                progress_init();
                found = save_file_exists();
                if (found & 1) {
                    save_read();
                }
                save_load();
                if (FUN_8c08a4b2() < 4) {
                    FUN_8c089fbc();
                }
                story_enable();
                story_set_character(character_current);
                story_set_next_stage(player_record->section);
                stage_mode = STAGE_TITLE_CARD;
                return 0;
            }
        }
        if (continue_timer-- <= 0) {
            sound_kill_all();
            task_destroy_all();
            FUN_8c0430e0();
            stage_mode = STAGE_TITLE_CARD;
            return STAGE_STEP_QUIT;
        }
        if (pad_press_repeat[0] &
            ((1 << 17) | (1 << 16) | (1 << 7) | (1 << 6))) {
            continue_choice ^= 1;
        }
        GameOver(continue_choice);
        pad_scan();
        loop_count = 0;
        step_tasks();
        break;
    case STAGE_QUIT:
        stage_unload();
        stage_mode = STAGE_TITLE_CARD;
        continue_choice = 0;
        return STAGE_STEP_QUIT;
    case STAGE_CARD_ERROR:
        FUN_8c04ecd0();
        break;
    default:
        stage_mode = STAGE_LEAVE;
        break;
    }
    if (pad_quit_pressed(0)) {
        switch (stage_mode) {
        case STAGE_AGAIN:
        case STAGE_AGAIN_WAIT:
        case STAGE_FADE_IN:
        case STAGE_CLEAR_FADE:
        case STAGE_MISS_FADE:
        case STAGE_GO_TO_FADE:
        case STAGE_QUIT_FADE:
        case STAGE_PLAY:
        case STAGE_PAUSE:
            stop_play();
        case STAGE_LEAVE:
        case STAGE_GAME_OVER:
        case STAGE_QUIT:
            stage_unload();
            break;
        case STAGE_GAME_OVER_FADE:
            stop_play();
            stage_unload();
            break;
        case STAGE_CONTINUE:
            FUN_8c0430e0();
            break;
        }
        reset_steps();
        return STAGE_STEP_RESET;
    }
    return 0;
}
void stage_end(Sint16 end)
{
    if (end == STAGE_END_CLEAR && GM_CheckClearEvent()) {
        return;
    }
    stage_end_kind = end;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void stage_reset_counts(void)
{
    stage_retry_count = 0;
    restart_clear();
    world_reset_gravity();
    if (stage_current <= 14 || stage_current == 35 ||
        stage_current == 38) {
        FUN_8c089fb4();
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void stage_reset_play(void)
{
    ssPauseEnable = 0;
    debug_hidden = -1;
    if (recording_kind == RECORDING_OFF) {
        recording_on = (0);
    } else {
        recording_on = (1);
        srand(0);
        if (recording_kind == RECORDING_RECORD) {
            recording_mode = RECORDER_RECORD;
        } else {
            recording_mode = RECORDER_PLAY;
        }
    }
    recording_next = ((struct pad_sample *)0x0cbe0000);
    recording_buttons = 0;
    dat_8c751454 = (void *)0x0cbc0000;
    PadReadOnP(3);
    ring_reset_stagger();
    score_reset();
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void InitializeStage(void)
{
    Uint16 stage;
    int which;
    stage_loaded = stage_current;
    act_loaded = act_current;
    CHAOS_SetChaosNo(0);
    ReleaseModule(fog_table, -7000.0F, -8000.0F);
    kmSetFogTable(fog_table);
    sound_load_stage();
    FUN_8c09cdd0();
    FUN_8c052ba0();
    stage = GetStageNumber();
    stage = (((stage) & 0xff00) >> 8);
    switch (stage) {
    case 36:
    case 37:
        texture_release_regular();
        which = 2;
        break;
    default:
        texture_release_regular();
        LoadPlayerMotionData();
        thunk_FUN_8c608734();
        texture_load_character(character_current);
        which = 0;
        break;
    }
    LoadTextureForEachGameMode(which);
    texture_load_stage();
    texture_load_act(((stage_current) << 8 | (act_current)));
    world_load_act(stage_current, act_current);
    njGarbageTexture(texmemlist, 2048);
    stage_reset_counts();
    ssPauseEnable = 0;
    time_reset();
    SleepTimer();
    if (character_current == 3) {
        FUN_8c094d0c();
    } else if (character_current == 7) {
        fishing_reset();
    }
    heap_init();
    task_init();
    CreateElementalTask(0x2, 8, SetObject);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void GameInit(void)
{
    struct task *task;
    frame_pacing_init(2, 2);
    stage_reset_play();
    thread_init();
    FUN_8c01957e();
    CreateElementalTask(0x2, 0, FUN_8c052fa0);
    FUN_8c04f5ac();
    stage_create_task();
    CreateElementalTask(0x2, 1, world_land_step);
    stage_create_players();
    CreateElementalTask(0x2, 1, KillPlayerFallingDownStageP);
    InitObjects();
    ExtraDisplayInit();
    InputHookInit();
    program_select_init();
    collision_mesh_init();
    path_create_manager();
    collision_clear_lists();
    particle_init(stage_particles, 512);
    particle_create_pools();
    download_start();
    event_ending = 0;
    if (demo_playing) {
        texLoadTexturePvmFile("PRESSSTART", &press_start_texlist);
        task = CreateElementalTask(0x2, 1, FUN_8c014b8a);
        task->destructor = press_start_destroy;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int FUN_8c04e714(void)
{
    int i;
    pad_scan();
    thread_yield();
    task_step_all();
    timer_mark();
    collision_collide_all();
    if (debug_page == 1) {
        njPrintC(((1) << 16 | (24)), "C_Colli");
        FUN_8c6409c0((((loop_count * 5) + 10) << 16 | (24)), (int)timer_lap(), 4);
    }
    particle_run();
    timer_mark();
    FUN_8c028ec2();
    if (debug_page == 1) {
        njPrintC(((1) << 16 | (25)), "CRangeIn");
        FUN_8c6409c0((((loop_count * 5) + 10) << 16 | (25)), (int)timer_lap(), 4);
    }
    if (debug_page == 2 && loop_count == 0) {
        for (i = 0; i < 20; i++) {
            FUN_8c6409c0(((3) << 16 | (i + 6)), i * 16, 3);
            FUN_8c6409c0(((7) << 16 | (i + 6)), draw_debug_counts[i], 4);
        }
    }
    if (!EV_CheckCansel()) {
        if (stage_group() != STAGE_GROUP_FIELD) {
            FUN_8c08a50c();
        }
        hud_hidden = 0;
    } else {
        hud_hidden = -1;
    }
    if (game_mode == GAME_MODE_TRIAL && stage_current <= 25 &&
        stage_current > 14) {
        lives_shown = -1;
    }
    return 0;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int stage_run_action(void)
{
    int extra;
    Float limit;
    Uint32 press0;
    Uint32 press1;
    press0 = per[0]->press;
    press1 = per[1]->press;
    extra = 0;
    for (loop_count = 0, limit = 1900.0F;
         loop_count < frame_step_count + extra;) {
        FUN_8c04e714();
        if (loop_count == 1 && timer_elapsed() >= limit) {
            extra++;
        }
        loop_count++;
        if (loop_count < frame_step_count + extra) {
            frame_wait_step(frame_step_count - loop_count + extra);
            press0 |= per[0]->press;
            press1 |= per[1]->press;
        }
    }
    per[0]->press = press0;
    per[1]->press = press1;
    hud_draw();
    FUN_8c08a3fa();
    return 0;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int stage_run_field(void)
{
    int extra;
    Float limit;
    Uint32 press0;
    Uint32 press1;
    press0 = per[0]->press;
    press1 = per[1]->press;
    extra = 0;
    for (loop_count = 0, limit = 1850.0F;
         loop_count < frame_step_count + extra;) {
        FUN_8c04e714();
        if (loop_count == 1 && timer_elapsed() >= limit) {
            extra++;
        }
        loop_count++;
        if (loop_count < frame_step_count + extra) {
            frame_wait_step(frame_step_count - loop_count + extra);
            press0 |= per[0]->press;
            press1 |= per[1]->press;
        }
    }
    per[0]->press = press0;
    per[1]->press = press1;
    hud_draw();
    return 0;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
int FUN_8c04eb7e(void)
{
    pad_scan();
    loop_count = 0;
    task_step_all();
    hud_draw();
    if ((per[0]->on & ((1 << 10) | (1 << 9))) ==
        ((1 << 10) | (1 << 9))) {
        pause_hidden = -1;
    } else {
        pause_hidden = 0;
    }
    if ((stage_current >= 26 &&
         stage_current <= 34) ||
        (stage_current >= 39 && stage_current <= 41) ||
        FUN_8c08a4b2() <= 0) {
        if (pad_press_repeat[0] & ((1 << 4) | (1 << 5))) {
            if (pause_choice != PAUSE_CONTINUE) {
                pause_choice = PAUSE_CONTINUE;
            } else {
                pause_choice = PAUSE_QUIT;
            }
        }
        if (pause_hidden >= 0) {
            FUN_8c014d6e(pause_choice != PAUSE_CONTINUE);
        }
    } else {
        if (pad_press_repeat[0] & (1 << 4)) {
            pause_choice--;
        } else if (pad_press_repeat[0] & (1 << 5)) {
            pause_choice++;
        }
        if (pause_choice >= PAUSE_CHOICES) {
            pause_choice = PAUSE_CONTINUE;
        } else if (pause_choice < PAUSE_CONTINUE) {
            pause_choice = PAUSE_QUIT;
        }
        if (pause_hidden >= 0) {
            FUN_8c014c4a(pause_choice);
        }
    }
    FUN_8c08a3fa();
    FUN_8c09dff8();
    return 0;
}
void stage_stop(void)
{
    sound_end_act();
    sound_kill_all();
    thread_destroy_all();
    task_destroy_levels_0_to_6();
    particle_free_all();
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c04ed1a(void)
{
    Uint8 count;
    stage_stop();
    if ((stage_mode != STAGE_CLEAR_FADE && stage_mode != 14) ||
        (stage_current > 25 && stage_current != 36 &&
         stage_current != 37 && stage_current != 38 &&
         stage_current != 35)) {
        return;
    }
    count = stage_clears[character_current][stage_current];
    if (count < 256) {
        count++;
    }
    stage_clears[character_current][stage_current] = count;
    if (stage_current == 3) {
        count = stage_clears[character_current][35];
        if (count == 0) {
            count = 1;
        }
        stage_clears[character_current][35] = count;
    }
    if (stage_clears[0][3] != 0 &&
        stage_clears[5][3] != 0 &&
        stage_clears[7][3] != 0) {
        stage_clears[3][35] =
            stage_clears[2][35] =
                stage_clears[6][35] = 1;
    }
    if (stage_current == 38) {
        if (stage_clears[0][38] == 0 &&
            stage_clears[2][38] == 1) {
            stage_clears[0][38] = 1;
        }
    }
    stage_last_cleared = stage_current;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void stage_unload(void)
{
    Uint16 stage;
    task_destroy_all();
    texture_release_stage();
    texture_release_act(((stage_current) << 8 | (act_current)));
    world_release_act(stage_current, act_current);
    download_end();
    stage = GetStageNumber();
    stage = (((stage) & 0xff00) >> 8);
    switch (stage) {
    case 36:
    case 37:
        texture_release_regular();
        LoadTextureForEachGameMode(0);
        break;
    }
    event_current = -1;
}
void later_step(struct task *task)
{
    struct later_extra *later = task->extra;
    later->steps--;
    if (later->steps > 0) {
        return;
    }
    switch (later->kind) {
    case LATER_MUSIC:
        BGM_Play(later->number);
        break;
    case LATER_SOUND:
        dsPlay_oneshot(later->number, 0, 0, 0);
        break;
    }
    DestroyTask(task);
}
void sound_play_later(int se)
{
    struct task *task;
    if ((task = CreateElementalTask(0x8, 1, later_step)) != ((void *)0)) {
        ((struct later_extra *)(task)->extra)->steps = 5;
        ((struct later_extra *)(task)->extra)->number = se;
        ((struct later_extra *)(task)->extra)->kind = LATER_SOUND;
    }
}
void music_play_later(int music)
{
    struct task *task;
    if ((task = CreateElementalTask(0x8, 1, later_step)) != ((void *)0)) {
        ((struct later_extra *)(task)->extra)->steps = 5;
        ((struct later_extra *)(task)->extra)->number = music;
        ((struct later_extra *)(task)->extra)->kind = LATER_MUSIC;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void SetFinishAction(void)
{
    PadReadOffP(0);
    ssPauseEnable = 0;
    SleepTimer();
    switch (character_current) {
    case 2:
        if (race_outcome() == RACE_WON) {
            CreateElementalTask(0, 3, clear_wait_step);
        } else {
            SetInputP(0, 19);
            FUN_8c0bfa2e();
            FUN_8c014b86();
            CreateElementalTask(0x2, 1, score_step);
        }
        break;
    case 3:
        SetInputP(0, 19);
        camera_start_path(&knuckles_clear_path, 3,
                          720);
        FUN_8c014b86();
        CreateElementalTask(0x2, 1, score_step);
        if (GetStageNumber() < ((15) << 8 | (0))) {
            ADX_Close();
            sound_play_later(0x537);
            music_play_later(MUSIC_RNDCLEAR);
        } else {
            ADX_Close();
            sound_play_later(0x53a);
            music_play_later(MUSIC_RNDCLEAR);
        }
        break;
    case 5:
        if (GetStageNumber() < ((15) << 8 | (0))) {
            SetInputP(0, 19);
            FUN_8c014b86();
            CreateElementalTask(0x2, 1, score_step);
            ADX_Close();
            sound_play_later(0x4ff);
            music_play_later(MUSIC_RNDCLEAR);
        } else {
            CreateElementalTask(0, 3, clear_wait_step);
        }
        break;
    case 7:
        SetInputP(0, 19);
        {
            NJS_POINT3 pos = {-36.0729F, 5.7132F, -1.5176F};
            NJS_POINT3 offset;
            player_turn_to_world(playertwp[0], &pos);
            offset = playertwp[0]->collision->shapes->center;
            camera_override_view.target.x = offset.x;
            camera_override_view.target.y = offset.y;
            camera_override_view.target.z = offset.z;
            njSubVector(&offset, &pos);
            camera_override_view.pos.x = offset.x;
            camera_override_view.pos.y = offset.y;
            camera_override_view.pos.z = offset.z;
            CameraSetEventCameraFunc(camera_step_fixed, 1, CAMERA_LOOK_AT);
            CreateElementalTask(0x2, 1, score_step);
            if (GetStageNumber() < ((15) << 8 | (0))) {
                ADX_Close();
            }
            music_play_later(MUSIC_RNDCLEAR);
        }
        break;
    default:
        CreateElementalTask(0, 3, clear_wait_step);
        ADX_Close();
        break;
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void clear_wait_step(struct task *task)
{
    struct task_work *work;
    work = GetPlayerTaskPointer(0)->work;
    if (playertwp[1] != ((void *)0) && capsule_get() != ((void *)0) &&
        capsule_get_player() == 1) {
        work = playertwp[1];
    }
    if (!(work->flags & (0x1 | 0x2))) {
        return;
    }
    SetInputP(0, 19);
    if (character_current == 0) {
        camera_start_path(&sonic_clear_path, 3,
                          720);
        if (stage_current <= 14) {
            sound_play_later(0x569);
        } else {
            sound_play_later(0x56c);
        }
    } else if (character_current == 2) {
        FUN_8c0bfa2e();
    } else if (character_current == 6) {
        camera_start_path(&e102_clear_path, 3, 720);
    } else if (character_current == 5) {
        camera_start_path(&amy_clear_path, 3, 720);
        sound_play_later(0x501);
    }
    FUN_8c014b86();
    CreateElementalTask(0x2, 1, score_step);
    music_play_later(MUSIC_RNDCLEAR);
    FreeTask(task);
}
void stage_create_players(void)
{
    struct task *task;
    void (*step)(struct task *task);
    NJS_POINT3 pos;
    Sint16 i;
    player_clear_slots();
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            if (character_current == 0) {
                if (stage_current == 36 ||
                    stage_current == 37) {
                    step = shooting_player_step;
                } else {
                    step = sonic_step;
                }
                task =
                    CreateElementalTask(0x1 | 0x2 | 0x4, 1, step);
                ((struct player_vars *)&(task->work)->vars)->character = character_current;
            }
            if (character_current == 3) {
                task = CreateElementalTask(0x1 | 0x2 | 0x4, 1,
                                   knuckles_step);
                ((struct player_vars *)&(task->work)->vars)->character = character_current;
            }
            if (character_current == 2) {
                if (stage_current == 36 ||
                    stage_current == 37) {
                    step = shooting_player_step;
                } else {
                    step = tails_step;
                }
                task =
                    CreateElementalTask(0x1 | 0x2 | 0x4, 1, step);
                ((struct player_vars *)&(task->work)->vars)->character = character_current;
            }
            if (character_current == 7) {
                task = CreateElementalTask(0x1 | 0x2 | 0x4, 1,
                                   big_step);
                ((struct player_vars *)&(task->work)->vars)->character = character_current;
            }
            if (character_current == 5) {
                task = CreateElementalTask(0x1 | 0x2 | 0x4, 1,
                                   amy_step);
                ((struct player_vars *)&(task->work)->vars)->character = character_current;
            }
            if (character_current == 6) {
                task = CreateElementalTask(0x1 | 0x2 | 0x4, 1,
                                   FUN_8c0c0580);
                ((struct player_vars *)&(task->work)->vars)->character = character_current;
            }
            ((struct player_vars *)&(task->work)->vars)->player = i;
            playertwp[i] = task->work;
            playermwp[i] = task->motion;
            stage_place_player(task->work);
            pos = task->work->pos;
        } else {
            if (character_current == 0 && i == 1) {
                NpcMilesSet(task);
            }
            race_create(character_current, i, stage_current);
        }
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void stage_create_task(void)
{
    void (**step)(struct task *task) = &stage_steps[stage_current];
    if (*step != ((void *)0)) {
        stage_task = CreateElementalTask(0x2, 0, *step);
    } else {
        stage_task = ((void *)0);
    }
    return;
}
void FUN_8c04f5ac(void)
{
    struct back_color *color = &back_colors[stage_current];
    njSetBackColor(color->col1, color->col2, color->col3);
    if (sky_steps[stage_current] != ((void *)0)) {
        CreateElementalTask(0x2, 2, sky_steps[stage_current]);
    }
}
void set_character(Sint16 character)
{
    int index;
    ReleasePlayersTexture(character_current);
    index = character_current;
    if (index > 4) {
        index--;
    }
    if (index > 1) {
        index--;
    }
    SaveData[save_slot].lives[index] = lives;
    character_current = character;
    FUN_8c09d8c0(character_current);
    texture_load_character(character_current);
    index = character_current;
    if (index > 4) {
        index--;
    }
    if (index > 1) {
        index--;
    }
    lives = SaveData[save_slot].lives[index];
    if (FUN_8c08a4b2() < 4) {
        FUN_8c089fbc();
    }
    chao_reset();
}
void FUN_8c04f692(Sint16 character)
{
    character_current = character;
}
int GetPlayerNumber(void)
{
    return character_current;
}
int FUN_8c04f6a0(void)
{
    return stage_retry_count;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void stage_keep_previous(void)
{
    stage_previous = stage_current;
    act_previous = act_current;
    return;
}
void stage_set_next_return(void)
{
    struct return_point *list;
    stage_next = stage_previous;
    act_next = act_previous;
    list = returns[character_current];
    return_point = ((void *)0);
    for (; list->stage != 43; list++) {
        if (list->stage == stage_current) {
            return_point = list;
            if (stage_current == 3) {
                act_next = 5;
            }
            return;
        }
    }
}
void stage_set_stage_act(Uint8 stage, Uint8 act)
{
    stage_keep_previous();
    stage_current = stage;
    act_current = act;
}
void stage_set_next_stage_act(Uint8 stage, Uint8 act)
{
    stage_next = stage;
    act_next = act;
}
void stage_fade_to(Uint8 stage, Uint8 act)
{
    stage_end(STAGE_END_GO_TO);
    stage_next = stage;
    act_next = act;
    return;
}
void FUN_8c04f7bc(void)
{
    stage_end(STAGE_END_RESTART);
}
void stage_go_to_next(void)
{
    stage_keep_previous();
    stage_current = stage_next;
    act_current = act_next;
    return;
}
Uint16 GetStageNumber(void)
{
    return ((stage_current) << 8 | (act_current));
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Uint16 FUN_8c04f7ee(void)
{
    return ((stage_previous) << 8 | (act_previous));
}
Uint16 FUN_8c04f840(void)
{
    return ((stage_next) << 8 | (act_next));
}
void stage_change_act(Sint16 by)
{
    texture_release_act(((stage_current) << 8 | (act_current)));
    world_release_act(stage_current, act_current);
    download_end();
    act_current += by;
    if (act_current >= 8) {
        act_current = 0;
    }
    if (stage_current != 33 && stage_current != 34) {
        light_load_act();
    }
    texture_load_act(((stage_current) << 8 | (act_current)));
    world_load_act(stage_current, act_current);
    download_start();
    story_steps = 0;
}
void stage_set_entrance(Sint8 entrance)
{
    entrance_next = entrance;
}
Sint8 stage_get_entrance(void)
{
    return entrance_next;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void stage_place_player(struct task_work *work)
{
    int character;
    struct start_point *start;
    Uint8 minutes;
    Uint8 seconds;
    int total_seconds;
    if (restart_keep_this_act()) {
        FUN_8c064df2(&work->pos, &work->ang);
    } else {
        if (act_loaded == act_current) {
            time_reset();
        }
        character = character_current;
        switch (character) {
        case 6:
            time_set_whole(3, 0);
            break;
        default:
            break;
        }
        if (return_point != ((void *)0)) {
            work->ang.y = return_point->ang_y;
            work->pos = return_point->pos;
            return_point = ((void *)0);
        } else if (stage_current == 26 ||
                   stage_current == 27 ||
                   stage_current == 28) {
            station_square_place_player(work);
        } else if (stage_current == 29 ||
                   stage_current == 32) {
            egg_carrier_place_player(work);
        } else if (stage_current == 33) {
            mystic_ruins_place_player(work);
        } else if (stage_current == 34) {
            past_place_player(work);
        } else {
            switch (((struct player_vars *)&(work)->vars)->character) {
            case 0:
                start = sonic_starts;
                break;
            case 2:
                start = tails_starts;
                break;
            case 3:
                start = knuckles_starts;
                break;
            case 7:
                start = big_starts;
                break;
            case 5:
                start = amy_starts;
                break;
            case 6:
                start = e102_starts;
                break;
            }
            for (;;) {
                if (start->stage == stage_current &&
                    start->act == act_current) {
                    work->ang.y = start->ang_y;
                    work->pos = start->pos;
                    break;
                }
                if (start->stage == 43) {
                    work->ang.y = 0;
                    work->pos.x = 0.0F;
                    work->pos.y = 0.0F;
                    work->pos.z = 0.0F;
                    break;
                }
                start++;
            }
        }
    }
    damage(((struct player_vars *)&(work)->vars)->player, 0, &work->pos, ((void *)0));
    character = character_current;
    switch (character) {
    case 6:
        time_get_whole(&minutes, &seconds);
        total_seconds = (minutes * 60) + seconds;
        if (total_seconds < 60) {
            time_set_whole(1, 0);
        }
        break;
    }
    if (((struct player_vars *)&(work)->vars)->player == 0 && stage_current <= 14) {
        FUN_8c064e36(&work->pos, &work->ang);
    }
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
void FUN_8c04fb3a(Uint16 stage, Uint16 act)
{
    struct stage_exit *entry;
    int request;
    if (stage == 35) {
        stage_next = 26;
        act_next = 5;
        entrance_next = 2;
        return;
    }
    entry = exits[character_current];
    stage_next = 26;
    act_next = 0;
    entrance_next = 0;
    while (entry->stage != 0xffff) {
        if (entry->stage == stage) {
            if (stage_clears[character_current][stage] == 1) {
                stage_next = entry->first_stage;
                act_next = entry->first_act;
                entrance_next = entry->first_entrance;
            } else if (entry->again_stage != 0) {
                stage_next = entry->again_stage;
                act_next = entry->again_act;
                entrance_next = entry->again_entrance;
            } else {
                stage_next = entry->first_stage;
                act_next = entry->first_act;
                entrance_next = entry->first_entrance;
            }
            if (player_record != ((void *)0)) {
                player_record->stage_act = ((stage_next) << 8 | (act_next));
                player_record->entrance = entrance_next;
                FUN_8c011524();
            }
            break;
        }
        entry++;
        request = entry->movie;
        switch (character_current) {
        case 0:
            if (seqVars[72]) {
                request = 0;
            }
            break;
        case 2:
            if (seqVars[73]) {
                request = 0;
            }
            break;
        case 3:
            if (seqVars[74]) {
                request = 0;
            }
            break;
        case 5:
            if (seqVars[75]) {
                request = 0;
            }
            break;
        case 6:
            if (seqVars[76]) {
                request = 0;
            }
            break;
        case 7:
            if (seqVars[77]) {
                request = 0;
            }
            break;
        }
        movie_request = request;
    }
}
void stage_set_next_exit(void)
{
    FUN_8c04fb3a(stage_current, act_current);
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool FUN_8c04fd50(void)
{
    Sint16 *walk;
    if (stage_current <= 14 || stage_current > 25) {
        stage_next = 26;
        act_next = 0;
        return (0);
    }
    switch (character_current) {
    case 0:
        walk = sonic_bosses;
        break;
    case 2:
        walk = tails_bosses;
        break;
    case 3:
        walk = knuckles_bosses;
        break;
    case 5:
        walk = amy_bosses;
        break;
    case 6:
        walk = e102_bosses;
        break;
    case 7:
        walk = big_bosses;
        break;
    }
    for (; walk[0] != 43; walk += 2) {
        if (walk[0] == stage_current) {
            if (walk[2] != 43) {
                stage_next = walk[2];
                act_next = walk[3];
                return (1);
            }
            break;
        }
    }
    return (0);
}
Bool ChkPause(void)
{
    return stage_mode == 16;
}
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
/* asm: register allocation not reproduced (this C is compiled for the file's pool layout; the bytes are the original's: +asmfunc) */
Bool stage_playing(void)
{
    return stage_mode == 15 || stage_mode == 4 || stage_mode == 2;
}
