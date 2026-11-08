/* @unit 0CB83740-0CB83890 +pool32 */
/* Tikal's light ball in events. Sonic Adventure DC's own tikallight.c, written from the code. */
       
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
void LoopTaskC(task* tp);
void FreeTaskC(task* tp);
task* CreateElementalTask(Uint16 im, tasklevel level, void (*exec)(task*));
task* CTikalLight_Create(Float x, Float y, Float z);
void TikalSetParameter(task* tikal_task_p, Float scale, Float alpha);
void TikalSetIllusion(task* tikal_task_p);
task* TikalMake(task* par_task_p, task** child_task_pp, NJS_POINT3* pos_p);
       
       
typedef struct FACETBL {
 Sint8 nbFrame;
 Sint8 faceNo;
} FACETBL;
extern struct EVENT_ACTION_LIST;
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
void SetEventWork(taskwk* twp);
void ExecEventPath(taskwk* twp);

static void CTikalLight_Dest(task* tp) {
 FreeTaskC(tp);
}

static void CTikalLight_Disp(task* tp) {
 ;
}

static void CTikalLight_Exec(task* tp)
{
	taskwk* twp;
	Float sclxy;
	Float sclzv;

	twp = tp->twp;
	if (twp->ewp->path.list)
		ExecEventPath(twp);
	sclxy = twp->scl.x + twp->scl.y;
	sclzv = twp->scl.z + twp->value.f;
	if (sclxy < 0.0f)
		sclxy = 0.0f;
	else if (sclxy > 1.0f)
		sclxy = 1.0f;
	if (sclzv < 0.0f)
		sclzv = 0.0f;
	TikalSetParameter((task*)twp->value.ptr, sclzv, sclxy);
	if (!--twp->ang.y)
	{
		TikalSetIllusion((task*)twp->value.ptr);
		twp->ang.y = twp->ang.x;
	}
	LoopTaskC(tp);
}

task* CTikalLight_Create(Float x, Float y, Float z)
{
	task* tp;
	taskwk* twp;

	tp = CreateElementalTask(2, 5, 0);
	if (tp)
	{
		tp->exec = CTikalLight_Exec;
		tp->disp = CTikalLight_Disp;
		tp->dest = CTikalLight_Dest;
		twp = tp->twp;
		SetEventWork(twp);
		twp->pos.x = x;
		twp->pos.y = y;
		twp->pos.z = z;
		twp->ang.x = 0;
		twp->ang.y = 0;
		twp->scl.x = 1.0f;
		twp->scl.y = 0.0f;
		twp->scl.z = 4.0f;
		twp->timer.f = 0.0f;
		twp->value.ptr = TikalMake(tp, (task**)&twp->value.ptr, &twp->pos);
	}
	return tp;
}
