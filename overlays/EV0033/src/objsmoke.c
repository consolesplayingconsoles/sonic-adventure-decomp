/* @unit 0CB877A0-0CB878D0 -speed +pool32 */
/* Smoke puffs in events. Sonic Adventure DC's own objsmoke.c, written from the code. */
       
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
Void* MAlloc(Uint32 size);
Void Free(Void* data);
task* CreateElementalTask(Uint16 im, tasklevel level, void (*exec)(task*));
typedef struct particle_info {
 Float scl;
 Float sclspd;
 Float animspd;
 Float friction;
 Float yacc;
 NJS_POINT3 pos;
 NJS_POINT3 velo;
 NJS_ARGB argb;
} particle_info;
void CreateSmoke2(particle_info* effect);
task* CObjSmoke_Create();
extern particle_info gParticleInfo;

static void CObjSmoke_Dest(task* tp) {
 Free(tp->twp->value.ptr);
}

static void CObjSmoke_Disp(task* tp) {
 ;
}

static void CObjSmoke_Exec(task* tp)
{
 particle_info* particle;
 taskwk* twp = tp->twp;
 if (--twp->ang.x == 0)
 {
  particle = (particle_info*)twp->value.ptr;
  twp->ang.x = twp->ang.y;
  gParticleInfo.scl = particle->scl;
  gParticleInfo.sclspd = particle->sclspd;
  gParticleInfo.animspd = particle->animspd;
  gParticleInfo.friction = particle->friction;
  gParticleInfo.yacc = particle->yacc;
  gParticleInfo.velo = particle->velo;
  gParticleInfo.argb = particle->argb;
  gParticleInfo.pos = twp->pos;
  CreateSmoke2(&gParticleInfo);
 }
}

task* CObjSmoke_Create()
{
 particle_info* particle;
 task* tp = CreateElementalTask(0x2, LEV_5, 0);
 if (tp)
 {
  taskwk* twp;
  tp->exec = CObjSmoke_Exec;
  tp->disp = CObjSmoke_Disp;
  tp->dest = CObjSmoke_Dest;
  twp = tp->twp;
  twp->ang.x = twp->ang.y = 0;
  particle = (particle_info*)MAlloc(sizeof(particle_info));
  twp->value.ptr = particle;
  particle->scl = 1.0f;
  particle->sclspd = 0.038f;
  particle->animspd = 0.19f;
  particle->friction = 0.06f;
  particle->yacc = 0.02499999851f;  /* 0x3CCCCCCC: the original's constant, one bit under 0.025f */
  particle->velo.x = 0.0f;
  particle->velo.y = 0.0f;
  particle->velo.z = 0.0f;
  particle->argb.a = 1.0f;
  particle->argb.r = 1.0f;
  particle->argb.g = 1.0f;
  particle->argb.b = 1.0f;
 }
 return tp;
}
