/* @unit 0C90B520-0C90B580 +pool32 */
/* SADX's C (sadx-decomp sonic/src/adv01_eggcarrierab/o_carrier_sidelift.c, read as text), byte-identical here: one source file of the game. */
       
typedef unsigned char Uint8;
typedef signed char Sint8;
typedef unsigned short Uint16;
typedef signed short Sint16;
typedef unsigned long Uint32;
typedef signed long Sint32;
typedef float Float;
typedef void Void;
typedef int Int;
typedef Sint32 Angle;
typedef Float NJS_MATRIX[16];
typedef void (*NJS_INT_FUNC)(void);
typedef struct {
 Sint16 u;
 Sint16 v;
} NJS_TEX;
typedef struct {
 Uint8 b;
 Uint8 g;
 Uint8 r;
 Uint8 a;
} NJS_BGRA;
typedef union {
 Uint32 color;
 NJS_TEX tex;
 NJS_BGRA argb;
} NJS_COLOR;
typedef struct {
 Float a;
 Float r;
 Float g;
 Float b;
} NJS_ARGB;
typedef struct {
 Float x;
 Float y;
 Float z;
} NJS_POINT3, NJS_VECTOR;
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
 void *ext;
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
 void *res;
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
 NJS_OBJECT *object;
 NJS_MOTION *motion;
} NJS_ACTION;
typedef struct
{
 Float ratten;
 Float ipd;
 Float nrr;
 Float frr;
 Float cosi;
 Float cose;
 Float idev;
 Float odev;
 Float rate;
 Float intns;
 Int exp;
 Int reserve;
 NJS_POINT3 lpnt;
 NJS_VECTOR lvctr;
 NJS_VECTOR lmvctr;
 NJS_ARGB atten;
 NJS_ARGB amb;
 NJS_ARGB dif;
 NJS_ARGB spc;
 NJS_ARGB mamb;
 NJS_ARGB mdif;
 NJS_ARGB mspc;
} NJS_LIGHT_CAL, *NJS_LIGHT_CAL_PTR;
typedef struct {
 Int lsrc;
 Float iamb;
 Float idif;
 Float ispc;
 Float nrang;
 Float frang;
 void* func;
 Angle iang;
 Angle oang;
 NJS_ARGB argb;
} NJS_LIGHT_ATTR, *NJS_LIGHT_ATTR_PTR;
typedef struct {
 NJS_MATRIX mtrx;
 NJS_POINT3 pnt;
 NJS_VECTOR vctr;
 Int stat;
 Int reserve;
 NJS_LIGHT_CAL ltcal;
 NJS_LIGHT_ATTR attr;
} NJS_LIGHT, *NJS_LIGHT_PTR;
typedef void (*NJF_LIGHT_FUNC)(NJS_ARGB*, NJS_POINT3*, NJS_VECTOR*, NJS_LIGHT_PTR); double exp(double);
typedef struct eventwk eventwk;
typedef struct task task;
typedef struct taskwk taskwk;
typedef struct colliwk colliwk;
typedef struct Angle3
{
 Angle x, y, z;
} Angle3;
typedef struct c_colli_hit_info
{
 Sint8 my_num;
 Sint8 hit_num;
 Uint16 flag;
 taskwk* hit_twp;
} c_colli_hit_info;
typedef struct CCL_INFO {
 Sint8 kind;
 Sint8 form;
 Sint8 push;
 Sint8 damage;
 Uint32 attr;
 NJS_POINT3 center;
 Float a;
 Float b;
 Float c;
 Float d;
 Angle angx;
 Angle angy;
 Angle angz;
} CCL_INFO;
struct colliwk {
 Uint16 id;
 Sint16 nbHit;
 Uint16 flag;
 Uint16 nbInfo;
 Float colli_range;
 CCL_INFO* info;
 c_colli_hit_info hit_info[16];
 NJS_POINT3 normal;
 task* mytask;
 Sint16 my_num;
 Sint16 hit_num;
 colliwk* hit_cwp;
};
struct taskwk {
 Sint8 mode;
 Sint8 smode;
 Uint8 id;
 Uint8 btimer;
 Sint16 flag;
 Uint16 wtimer;
 union
 {
  Uint8 b[4];
  Uint16 w[2];
  Uint32 l;
  Float f;
  Void* ptr;
 } counter;
 union
 {
  Sint8 b[4];
  Sint16 w[2];
  Sint32 l;
  Float f;
  Void* ptr;
 } timer, value;
 Angle3 ang;
 NJS_POINT3 pos;
 NJS_POINT3 scl;
 colliwk* cwp;
 eventwk* ewp;
};
typedef struct _OBJ_EDITENTRY {
 Uint16 usID;
 Sint16 rotx;
 Sint16 roty;
 Sint16 rotz;
 Float xpos;
 Float ypos;
 Float zpos;
 Float xscl;
 Float yscl;
 Float zscl;
} _OBJ_EDITENTRY;
typedef struct _OBJ_SLEEPCON {
 Angle3 ang;
 NJS_POINT3 pos;
 NJS_POINT3 scl;
} _OBJ_SLEEPCON;
typedef union _UNION_STATUS {
 Float fRangeOut;
 _OBJ_SLEEPCON* pObjSleepCondition;
} _UNION_STATUS;
typedef struct OBJ_CONDITION {
 Sint8 scCount;
 Sint8 scUserFlag;
 Sint16 ssCondition;
 task* pTask;
 _OBJ_EDITENTRY* pObjEditEntry;
 _UNION_STATUS unionStatus;
} OBJ_CONDITION;
typedef struct motionwk {
 union
 {
  Sint8 b[4];
  Sint16 w[2];
  Sint32 l;
  Float f;
  Void* ptr;
 } work;
 NJS_POINT3 spd;
 NJS_POINT3 acc;
 Angle3 ang_aim;
 Angle3 ang_spd;
 Float rad;
 Float height;
 Float weight;
} motionwk;
typedef struct forcewk {
 void (*call_back)(struct task*, struct taskwk*, struct forcewk*);
 Angle3 ang_spd;
 NJS_POINT3 pos_spd;
} forcewk;
typedef struct anywk {
 union
 {
  Uint8 ub[16];
  Sint8 sb[16];
  Uint16 uw[8];
  Sint16 sw[8];
  Uint32 ul[4];
  Sint32 sl[4];
  Float f[4];
  Void* ptr[4];
 } work;
} anywk;
struct task
{
 task* next;
 task* last;
 task* ptp;
 task* ctp;
 void(*exec)(struct task*);
 void(*disp)(struct task*);
 void(*dest)(struct task*);
 OBJ_CONDITION* ocp;
 taskwk* twp;
 motionwk* mwp;
 forcewk* fwp;
 anywk* awp;
 void* thp;
};
void WithdrawCollisionEntry(task* pTask, NJS_OBJECT* pObject);
void ReleaseMobileLandObject(NJS_OBJECT* pObject);
        
       
       
typedef struct FACETBL {
 Sint8 nbFrame;
 Sint8 faceNo;
} FACETBL;
struct EVENT_ACTION_LIST;
typedef struct EVENT_ACTION_LIST
{
 Uint8 mode;
 Uint8 linkframe;
 NJS_ACTION action;
 NJS_TEXLIST* texlist;
 struct EVENT_ACTION_LIST* next;
 Float speed;
} EVENT_ACTION_LIST;
typedef struct epathang3 {
 Sint8 x;
 Sint8 y;
 Sint8 z;
} epathang3;
typedef struct epathtbl {
 epathang3 ang;
 NJS_POINT3 pos;
} epathtbl;
typedef struct EPATHTAG {
 Sint32 points;
 epathtbl* tblhead;
} EPATHTAG;
typedef struct EVENT_PATH_LIST {
 Uint8 mode;
 EPATHTAG* path;
 Float speed;
 struct EVENT_PATH_LIST* next;
} EVENT_PATH_LIST;
typedef struct facewk {
 Sint8 old;
 Sint8 __new;
 Sint16 nbFrame;
 Sint16 frame;
 Sint8* dataPtr;
 FACETBL* tablePtr;
} facewk;
struct eventwk {
 Uint8 mode;
 Uint8 command;
 struct
 {
  Uint8 mode;
  Angle3 ang;
  NJS_POINT3 pos;
  task* obj;
 } look;
 struct
 {
  Uint8 mode;
  union
  {
   NJS_POINT3 pos;
   NJS_POINT3 spd;
   NJS_POINT3 acc;
   Angle3 ang;
  } param;
  Float run_speed;
  Float run_accel;
 } move;
 struct
 {
  Float timer;
  EVENT_ACTION_LIST* list;
  EVENT_ACTION_LIST* old;
 } action;
 struct
 {
  Float timer;
  EVENT_PATH_LIST* list;
  NJS_POINT3 pos;
 } path;
 facewk face;
 NJS_POINT3 posofs;
 Float shadowSize;
};

void SideliftDestructor(task* tp)
{
 taskwk* twp = tp->twp;
 if (twp->counter.ptr)
 {
  WithdrawCollisionEntry(tp, (NJS_OBJECT*)twp->counter.ptr);
  ReleaseMobileLandObject((NJS_OBJECT*)twp->counter.ptr);
 }
}
