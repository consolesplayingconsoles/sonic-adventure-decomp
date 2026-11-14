/*
 *-----------------------------------------------------------------------------
 *  FILE: gdc.h
 *        Copyright 1997 SEGA ENTERPLISES, LTD.
 *
 *  PURPOSE:
 *
 *      GD Drive controler header file for KATANA
 *
 *  DESCRIPTION:
 *
 *  AUTHOR(S):
 *
 *      1997/12/11  Ver 0.10   Y.Yamanaka SYSTEM R&D Dep.
 *
 *  MOD HISTORY:
 *
 *      modified by T.Suzuki  SYSTEM R&D Dep.  1998/10/02
 *
 *
 *-----------------------------------------------------------------------------
 */

#ifndef   _GDC_H_     /* This header */
#define   _GDC_H_

/* return value of API's */
enum gdc_return_value
{
    GDC_ERR = -1,     /* -1 */
    GDC_OK,           /*  0 */
    GDC_BUSY,         /*  1 */
    GDC_COMPLETE,     /*  2 */
    GDC_CONTINUE,     /*  3 */
    GDC_SMPHR_BUSY,   /*  4 */
    GDC_RET1,         /*  5 */
    GDC_RET2          /*  6 */
};

/* command codes of GDC_ReqCmd */
enum gdc_cmd_code
{
    GDC_CMD_PIOREAD  = 0x10,         /* 0x10 */
    GDC_CMD_DMAREAD,                 /* 0x11 */
    GDC_CMD_GETTOC,                  /* 0x12 */
    GDC_CMD_GETTOC2,                 /* 0x13 */
    GDC_CMD_PLAY,                    /* 0x14 */
    GDC_CMD_PLAY2,                   /* 0x15 */
    GDC_CMD_PAUSE,                   /* 0x16 */
    GDC_CMD_RELEASE,                 /* 0x17 */
    GDC_CMD_INIT,                    /* 0x18 */
    GDC_CMD_READABORT,               /* 0x19 */
    GDC_CMD_OPEN,                    /* 0x1A */
    GDC_CMD_SEEK,                    /* 0x1B */
    GDC_CMD_DMAREADREQ,              /* 0x1C */
    GDC_CMD_GETQINFO,                /* 0x1D */
    GDC_CMD_REQMODE,                 /* 0x1E */
    GDC_CMD_SETMODE,                 /* 0x1F */
    GDC_CMD_SCAN,                    /* 0x20 */
    GDC_CMD_STOP,                    /* 0x21 */
    GDC_CMD_GETSCD,                  /* 0x22 */
    GDC_CMD_REQSES,                  /* 0x23 */
    GDC_CMD_REQSTAT,                 /* 0x24 */
    GDC_CMD_PIOREADREQ,              /* 0x25 */
    GDC_CMD_DMAREADREQ2,             /* 0x26 */
    GDC_CMD_PIOREADREQ2,             /* 0x27 */
    GDC_CMD_GETVERSION,              /* 0x28 */
    GDC_CMD_CMDA,                    /* 0x29 */
    GDC_CMD_CMDB,                    /* 0x2A */
    GDC_CMD_CMDC,                    /* 0x2B */
    GDC_CMD_CMDD,                    /* 0x2C */
    GDC_CMD_CMDE,                    /* 0x2D */
    GDC_CMD_CMDF,                    /* 0x2E */
    GDC_CMD_CMDG                     /* 0x2F */
};


/* error code of gdGdcGetCmdStat */
#define   GDC_ERR_NOERR          0x00
#define   GDC_ERR_RECOVERED      0x01
#define   GDC_ERR_NOTREADY       0x02
#define   GDC_ERR_MEDIUM         0x03
#define   GDC_ERR_HARDWARE       0x04
#define   GDC_ERR_ILLEGALREQUEST 0x05
#define   GDC_ERR_UNITATTENTION  0x06
#define   GDC_ERR_DATAPROTECT    0x07
#define   GDC_ERR_ABORTED        0x0B
#define   GDC_ERR_NOREADABLE     0x10
#define   GDC_ERR_G1SEMAPHORE    0x20

/* status code of gdGdcGetDevStat */
#define   GDC_STAT_BUSY          0x00
#define   GDC_STAT_PAUSE         0x01
#define   GDC_STAT_STANDBY       0x02
#define   GDC_STAT_PLAY          0x03
#define   GDC_STAT_SEEK          0x04
#define   GDC_STAT_SCAN          0x05
#define   GDC_STAT_OPEN          0x06
#define   GDC_STAT_NODISC        0x07
#define   GDC_STAT_RETRY         0x08
#define   GDC_STAT_ERROR         0x09

/* disc format */
#define   GDC_DISC_CDDA          0x00
#define   GDC_DISC_CDROM         0x10
#define   GDC_DISC_CDROMXA       0x20
#define   GDC_DISC_CDI           0x30
#define   GDC_DISC_GDROM         0x80

/* wait type */
#define   GDC_WAIT_INTERNAL      0x00
#define   GDC_WAIT_IRQ           0x01
#define   GDC_WAIT_DRQ_0         0x02
#define   GDC_WAIT_DRQ_1         0x03
#define   GDC_WAIT_BUSY          0x04

/* data type */
#define   GDC_DATA_SET             0
#define   GDC_DATA_GET             1
 /* data select */
#define   GDC_DATA_SEL_HEADER      0x8000U
#define   GDC_DATA_SEL_SUBHEADER   0x4000U
#define   GDC_DATA_SEL_DATA        0x2000U
#define   GDC_DATA_SEL_OTHER       0x1000U
 /* expected data type */
#define   GDC_DATA_EXP_ANY         0x0000U
#define   GDC_DATA_EXP_CDDA        0x0200U
#define   GDC_DATA_EXP_MODE1       0x0400U
#define   GDC_DATA_EXP_MODE2       0x0600U
#define   GDC_DATA_EXP_MODE2FORM1  0x0800U
#define   GDC_DATA_EXP_MODE2FORM2  0x0A00U
#define   GDC_DATA_EXP_MODE2NONXA  0x0C00U

/* null commnad handle */
#define GDCH_NULL      0L

/* command handle */
typedef long GDCH;

/* callback function */
typedef void (*GDC_FUNC)(void*);

/* command status */
typedef struct
{
    unsigned long err;
    unsigned long err1;
    unsigned long size;
    unsigned long foo;
} GDC_CMD_STAT;

/* drive status */
typedef struct
{
    unsigned long stat;
    unsigned long media;
} GDC_DRV_STAT;

/* command parameta */
typedef struct
{
    unsigned long   start;
    unsigned long   size;
    unsigned short *buf;
    unsigned long   next;
} GDC_PIOprm, *pGDC_PIOprm;

typedef struct
{
    unsigned long   start;
    unsigned long   size;
    unsigned long  *buf;
    unsigned long   next;
} GDC_DMAprm, *pGDC_DMAprm;

typedef struct
{
    unsigned long   type;
    unsigned char  *buf;
} GDC_TOCprm, *pGDC_TOCprm;

typedef struct
{
    unsigned long   type;
    unsigned long  *buf;
} GDC_TOC2prm, *pGDC_TOC2prm;

typedef struct
{
    unsigned long   start;
    unsigned long   end;
    unsigned long   repeat;
} GDC_PLAYprm, *pGDC_PLAYprm;

typedef struct
{
    unsigned long   start;
    unsigned long   end;
    unsigned long   repeat;
} GDC_PLAY2prm, *pGDC_PLAY2prm;

typedef struct
{
    unsigned long   seek_point;
} GDC_SEEKprm, *pGDC_SEEKprm;

typedef struct
{
    unsigned long   start;
    unsigned long   size;
} GDC_DMAREADREQprm, *pGDC_DMAREADREQprm;

typedef struct
{
    unsigned long   start;
    unsigned long   size;
} GDC_PIOREADREQprm, *pGDC_PIOREADREQprm;

typedef struct
{
    unsigned long   start;
    unsigned long   size;
    unsigned long   next;
} GDC_DMAREADREQ2prm, *pGDC_DMAREADREQ2prm;

typedef struct
{
    unsigned long   start;
    unsigned long   size;
    unsigned long   next;
} GDC_PIOREADREQ2prm, *pGDC_PIOREADREQ2prm;

typedef struct
{
    unsigned long   format;
    unsigned long   length;
    unsigned short *buf;
} GDC_GETSCDprm, *pGDC_GETSCDprm;

typedef struct
{
    unsigned long  *track;
    unsigned long  *rel_fad;
    unsigned long  *toc;
    unsigned long  *index;
} GDC_GETQINFOprm, *pGDC_GETQINFOprm;

typedef struct
{
    unsigned long   cd_speed;
    unsigned long   standby_time;
    unsigned long   read_retry;
    unsigned long   read_retry_times;
} GDC_SETMODEprm, *pGDC_SETMODEprm;

typedef struct
{
    pGDC_SETMODEprm mode_prm;
} GDC_REQMODEprm, *pGDC_REQMODEprm;

typedef struct
{
    unsigned long   dir;
    unsigned long   speed;
} GDC_SCANprm, *pGDC_SCANprm;

typedef struct
{
    unsigned long   num;
    unsigned long  *session;
    unsigned long  *fad;
} GDC_REQSESprm, *pGDC_REQSESprm;

typedef struct
{
    unsigned long  *repeat;
    unsigned long  *track;
    unsigned long  *toc;
    unsigned long  *index;
} GDC_REQSTATprm, *pGDC_REQSTATprm;

typedef struct
{
    void          *buf;
    unsigned long  size;
} GDC_REQTRANSprm, *pGDC_REQTRANSprm;

typedef struct
{
	unsigned long set_get;
	unsigned long select;
	unsigned long expected_type;
	unsigned long sector_size;
} GDC_DATA_TYPE;

typedef struct
{
	signed char *gdc_ver;
} GDC_GETVERSIONprm, *pGDC_GETVERSIONprm;

#define GDC_VERSION_STR ("GDC Version 1.01 1998-09-30 ")
#define GDC_VERSION_LEN         (28)

#if 1

GDCH gdGdcReqCmd(unsigned long cmd, void *prm);
long gdGdcGetCmdStat(GDCH gdch, GDC_CMD_STAT *stat);
void gdGdcExecServer(void);
void gdGdcInitSystem(void);
long gdGdcGetDrvStat(GDC_DRV_STAT *stat);
void gdGdcG1DmaEnd(GDC_FUNC func, void *obj);
long gdGdcReqDmaTrans(GDCH gdch, GDC_REQTRANSprm *prm);
long gdGdcCheckDmaTrans(GDCH gdch, unsigned long *size);
long gdGdcReadAbort(GDCH);
void gdGdcReset(void);
long gdGdcChangeDataType(GDC_DATA_TYPE *type);
void gdGdcSetPioCallBack(GDC_FUNC func, void *obj);
long gdGdcReqPioTrans(GDCH gdch, GDC_REQTRANSprm *prm);
long gdGdcCheckPioTrans(GDCH gdch, unsigned long *size);

long gdBtGdcReInitEntry(void);
long gdBtGdcAddDesc(long desc, unsigned long adr);

#else

/* for KABUTO */

/* table top address */
#define GDCTBLBASE (0x8C0010F0)

/* 00: GDCH gdGdcReqCmd(unsigned long cmd, void *prm); */
#define gdGdcReqCmd(a, b)\
  ((*((GDCH(*)(unsigned long, void*, long, long))GDCTBLBASE))(a,b,0,0))

/* 01: long gdGdcGetCmdStat(GDCH gdch, GDC_CMD_STAT *stat); */
#define gdGdcGetCmdStat(a,b)\
  ((*((long(*)(GDCH, GDC_CMD_STAT*, long, long))GDCTBLBASE))(a,b,0,1))

/* 02: void gdGdcExecServer(void); */
#define gdGdcExecServer()\
  ((*((void(*)(long, long, long, long))GDCTBLBASE))(0,0,0,2))

/* 03: void gdGdcInitSystem(void); */
#define gdGdcInitSystem()\
  ((*((void(*)(long, long, long, long))GDCTBLBASE))(0,0,0,3))

/* 04: long gdGdcGetDrvStat(GDC_DRV_STAT *stat); */
#define gdGdcGetDrvStat(a)\
  ((*((long(*)(GDC_DRV_STAT*,long,long,long))GDCTBLBASE))(a,0,0,4))

/* 05: void gdGdcG1DmaEnd(GDC_FUNC func, void *obj); */
#define gdGdcG1DmaEnd(a,b)\
  ((*((void(*)(GDC_FUNC,void*,long,long))GDCTBLBASE))(a,b,0,5))

/* 06: long gdGdcReqDmaTrans(GDCH gdch, GDC_REQTRANSprm *prm); */
#define gdGdcReqDmaTrans(a,b)\
  ((*((long(*)(GDCH,GDC_REQTRANSprm*,long,long))GDCTBLBASE))(a,b,0,6))

/* 07: long gdGdcCheckDmaTrans(GDCH gdch, unsigned long *size); */
#define gdGdcCheckDmaTrans(a,b)\
  ((*((long(*)(GDCH, unsigned long*,long,long))GDCTBLBASE))(a,b,0,7))

/* 08: long gdGdcReadAbort(GDCH); */
#define gdGdcReadAbort(a)\
  ((*((long(*)(GDCH,long,long,long))GDCTBLBASE))(a,0,0,8))

/* 09: void gdGdcReset(void) */
#define gdGdcReset()\
  ((*((void(*)(long,long,long,long))GDCTBLBASE))(0,0,0,9))

/* 0A: long gdGdcChangeDataType(GDC_DATA_TYPE *type) */
#define gdGdcChangeDataType(a)\
  ((*((void(*)(GDC_DATA_TYPE *))GDCTBLBASE))(a,0,0,10))

/* 0B: void gdGdcSetPioCallBack(GDC_FUNC func, void *obj) */
#define gdGdcSetPioCallBack(a,b)\
  ((*((void(*)(GDC_FUNC,void*,long,long))GDCTBLBASE))(a,b,0,11))

/* 0C: long gdGdcReqPioTrans(GDCH gdch, GDC_REQTRANSprm *prm) */
#define gdGdcReqPioTrans(a,b)\
  ((*((long(*)(GDCH,GDC_REQTRANSprm*,long,long))GDCTBLBASE))(a,b,0,12))

/* 0D: long gdGdcCheckPioTrans(GDCH gdch, unsigned long *size) */
#define gdGdcCheckDmaTrans(a,b)\
  ((*((long(*)(GDCH, unsigned long*,long,long))GDCTBLBASE))(a,b,0,13))



#endif


#endif /* _GDC_H_ */
