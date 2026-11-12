/* @unit 0CB82F80-0CB830C0 -speed +pool32 +synth16 */
/* The sky walk under Sonic in events. Sonic Adventure DC's own skywalk.c, written from the code with sadx-decomp's event/src/skywalk.c (SADX's C, read as text) as the guide.
   +synth16: the game's compiler built the constant 0x100 with mov #1 / shll8, which no available SHC does (tools/fill.py, synth16). */
       
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
typedef enum tasklevel {
 LEV_0 = 0x0,
 LEV_1 = 0x1,
 LEV_2 = 0x2,
 LEV_3 = 0x3,
 LEV_4 = 0x4,
 LEV_5 = 0x5,
 LEV_6 = 0x6,
 LEV_C = 0x7,
 LEV_M = 0x8,
} tasklevel;
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
task* CreateElementalTask(Uint16 im, tasklevel level, void (*exec)(task*));
task* CSkyWalk_create2(task* obj, Float height);
void RegisterCollisionEntry(Sint32 slAttribute, task* pTask, NJS_OBJECT* pObject);
void WithdrawCollisionEntry(task* pTask, NJS_OBJECT* pObject);
NJS_OBJECT* GetMobileLandObject();
void ReleaseMobileLandObject(NJS_OBJECT* pObject);
extern NJS_OBJECT object_skywalk_cl[];

void CSkyWalk_dest(task* tp)
{
 NJS_OBJECT* obj = (NJS_OBJECT*)tp->twp->counter.ptr;
 WithdrawCollisionEntry(tp, obj);
 ReleaseMobileLandObject(obj);
}

void CSkyWalk_exec2(task* tp)
{
 taskwk* twp = tp->twp;
 NJS_OBJECT* skywalk = (NJS_OBJECT*)twp->counter.ptr;
 task* obj = (task*)twp->timer.ptr;
 skywalk->pos[0] = obj->twp->pos.x;
 skywalk->pos[2] = obj->twp->pos.z;
}

void CSkyWalk_cons2(task* tp)
{
	forcewk* fwp;
	NJS_OBJECT* skywalk;
	taskwk* twp;
	NJS_OBJECT* cl;

	tp->exec = CSkyWalk_exec2;
	tp->dest = CSkyWalk_dest;
	twp = tp->twp;
	cl = object_skywalk_cl;
	skywalk = GetMobileLandObject();
	twp->counter.ptr = skywalk;
	skywalk->evalflags = cl->evalflags;
	CSkyWalk_exec2(tp);
	skywalk->pos[1] = twp->pos.y;
	skywalk->ang[0] = 0;
	skywalk->ang[1] = 0;
	skywalk->ang[2] = 0;
	skywalk->scl[0] = 1.0f;
	skywalk->scl[1] = 1.0f;
	skywalk->scl[2] = 1.0f;
	skywalk->model = cl->model;
	skywalk->child = cl->child;
	skywalk->sibling = cl->sibling;
	RegisterCollisionEntry(1744830465, tp, skywalk);
	twp->flag = twp->flag | 0x100u;
	fwp = tp->fwp;
	fwp->pos_spd.x = 0.0f;
	fwp->pos_spd.y = 0.0f;
	fwp->pos_spd.z = 0.0f;
	fwp->ang_spd.x = 0;
	fwp->ang_spd.y = 0;
	fwp->ang_spd.z = 0;
}

task* CSkyWalk_create2(task* obj, Float height)
{
	task* result = CreateElementalTask(0x2 | 0x4, LEV_3, CSkyWalk_cons2);
	result->twp->pos.y = height;
	result->twp->timer.ptr = obj;
	return result;
}
