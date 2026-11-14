/*
 *  Shinobi Library
 *  Copyright (c) 1998,1999 SEGA
 *  
 *       FileSystem
 *
 *  Module  : Library Common Header File
 *  File    : gdfs.h
 *  Date    : 1999-01-12
 *  Modify  :
 *  Author  : T.S. (SEGA, SYSTEM_R&D)
 *  Version : 1.06
 *  Note    :
 */


/***** macros *****/

/* DEBUG */
#define DEBUG  0

/* CDROM / GDROM */
#define GDROM  1

/* PVD Address (FAD) */
#if GDROM

/* GDROM HighDensity Area */
#define  FAD_OF_PVD  0x0b06e
#else /* #if GDROM */

/* CDROM or GDROM SingleDensity Area */
#define  FAD_OF_PVD  0xa6
#endif /* #if GDROM */

/* Size of Sector */
#define  SCT_SIZE  2048

/* Start Sector of LSN */
#define  LSN_START   0x96

/* Priority of GDFS in VBlank */
#define  GDD_FS_PRIO_VBLNK  0x50

/* Priority of GDFS in G1 DMA End Int. */
#define  GDD_FS_PRIO_G1DMAE  0x10

/* Library ID */
/* {AC19E50A-0797-11d2-ACD3-00104B2AE8D5}*/
#define GDD_FS_LID {\
	(Uint32) 0xac19e50a, (Uint16) 0x797, (Uint16) 0x11d2, \
	{ \
		(Uint8) 0xac, (Uint8) 0xd3, (Uint8)  0x0, (Uint8) 0x10, \
		(Uint8) 0x4b, (Uint8) 0x2a, (Uint8) 0xe8, (Uint8) 0xd5, \
	} \
}


/* Library Version */
#define GDD_FS_VERSION_NO   (0x01) /* Version no. */
#define GDD_FS_REVISION_NO  (0x06) /* Rev. no. */


/* Handle action */
#define GDD_FS_HNDACT_IDLE   (0)
#define GDD_FS_HNDACT_READ   (1)
#define GDD_FS_HNDACT_SEEK   (2)
#define GDD_FS_HNDACT_ABORT  (3)
#define GDD_FS_HNDACT_GDRD   (4)
#define GDD_FS_HNDACT_TRANS  (5)
#define GDD_FS_HNDACT_CDDA   (6)
#define GDD_FS_HNDACT_GETSCD (7)
#define GDD_FS_HNDACT_TOCCHK (8)
#define GDD_FS_HNDACT_OTHER  (10)


/* Handle Status (internal) */
#define  GDD_STAT_FATAL     (64)
#define  GDD_STAT_CONTINUE  (65)
#define  GDD_STAT_UNDEF     (66)
#define  GDD_STAT_SMPBUSY   (67)


/* Server flag */
#define GDD_FS_SVR_NORMAL     (0)
#define GDD_FS_SVR_NOVSYNC    (1)


/* DA pause workaround */
#define GDD_FS_PAUSE_WA       (0x00010001)


/* DDS Info address */
#define GDD_FS_DDSADDR        (0x8c0080f0)

#define GDD_FS_DDSMODE_DDS    (0x01)
#define GDD_FS_DDSMODE_NORMAL (0x20)

/* misc */
#define GDD_FS_MAXRETRY  20000
#define GDD_FS_DMYLOOP  50000

#define GDD_FS_TOUTCNT  (15625000L)
#define GDD_FS_2MWAIT   (1563)


/***** structs *****/

/* Library Interface Function */
struct GDS_FS_LIF {
	/* Compatibility for COM Interface */
	void *(*QueryInterface)();
	void (*AddRef)();
	void (*Release)();
	/* Global function here */
	Sint32 (*Init)(Sint32, void *, Sint32, void *, GDFS_LIF *);
	Sint32 (*Reinit)(void);
	void (*Finish)(void);
	Sint32 (*SetGlobalErr)(Sint32);
	Sint32 (*ReadW)(Sint32, Sint32, void *);
	Sint32 (*LoadDir)(const char *, GDFS_DIRREC);
	Sint32 (*LoadDirFast)(const char *, GDFS_DIRREC);
	Sint32 (*SetDir)(GDFS_DIRREC);
	Sint32 (*GetDirInfo)(const char *, GDFS_DIRINFO *);
	GDFS (*GetWorkHn)(void);
	GDFS (*GetSysHn)(void);
	GDFS (*CreateHn)(GDFS, Sint32, Sint32, Sint32);
	GDFS (*Open)(const char *, GDFS_DIRREC);
	GDFS (*OpenFast)(const char *, GDFS_DIRREC);
	GDFS (*OpenRange)(Sint32, Sint32);
	void (*ExecServer)(void);
	Sint32 (*GetGlobalErr)(void);
	Sint32 (*GetToc)(Sint32, void *);
	Sint32 (*GetDrvStat)(void);
	Sint32 (*ReqDrvStat)(void);
	Sint32 (*DaPlay)(Sint32, Sint32, Sint32);
	Sint32 (*DaPlaySct)(Sint32, Sint32, Sint32);
	Sint32 (*DaStop)(void);
	Sint32 (*DaPause)(void);
	Sint32 (*DaRelease)(Sint32); 
	Sint32 (*DaGetInfo)(GDFS_DAINFO *); 
	void  (*EntryErrFuncAll)(GDFS_ERRFUNC, void *);
	Bool (*IsTrayOpen)(void);
};


typedef struct {
	Sint8 ApDir[12];
	Sint8 ddsf;
	Sint8 DaTno;
	Sint8 reserved[2];
} GDS_FS_DDSINFO;


typedef struct {
	Sint16 mode;
	Sint16 da;
	Sint32 aroot_fad;
	char arootdir[13];
} GDS_FS_DDSWORK;


/***** prototypes *****/

extern Sint32  gdFsWaitCompleteReq(GDFS gdfs);
extern Sint32  gdFsSetTmode(GDFS gdfs, Sint32 tmode);
extern Sint32  gdFsGetLE4(Uint8 *cp);
extern GDFS  gdFsReopenHn(GDFS gdfs, Sint32 fid, Sint32 fad, Sint32 fsize);
extern void  gdFsMemcpy(void *src, void *dst, Sint32 len);


extern Sint32  gdFsReadWG(Sint32 fad, Sint32 nsct, void *buf);
extern Sint32  gdFsSetGlobalErrG(Sint32 errstat);
extern Sint32  gdFsGetGlobalErrG(void);
extern Sint32  gdFsInitG(Sint32 max_open, void *gdfs_work, Sint32 max_dirent, void *dirbuf, GDFS_LIF *lif);
extern Sint32  gdFsReinitG(void);
extern void  gdFsFinishG(void);
extern GDFS  gdFsCreateHnG(GDFS gdfs, Sint32 fid, Sint32 fad, Sint32 fsize);
extern Sint32  gdFsLoadDirG(const char *dirname, GDFS_DIRREC gf_dirrec);
extern Sint32  gdFsLoadDirFastG(const char *dirname, GDFS_DIRREC gf_dirrec);
extern Sint32  gdFsSetDirG(GDFS_DIRREC gf_dirrec);
extern Sint32  gdFsGetDirInfoG(const char *name, GDFS_DIRINFO *dirinfo);
extern GDFS  gdFsOpenG(const char *fname, GDFS_DIRREC gf_dirrec);
extern GDFS  gdFsOpenFastG(const char *fname, GDFS_DIRREC gf_dirrec);
extern GDFS  gdFsOpenRangeG(Sint32 stsct, Sint32 nsct);
extern GDFS  gdFsGetWorkHnG(void);
extern GDFS  gdFsGetSysHnG(void);
extern void  gdFsExecServerG(void);
extern void  gdFsEntryErrFuncAllG(GDFS_ERRFUNC erfunc, void *obj);
extern Sint32  gdFsGetTocG(Sint32 type, void *buf);
extern Sint32  gdFsGetDrvStatG(void);
extern Sint32  gdFsReqDrvStatG(void);
extern Sint32  gdFsDaPlayG(Sint32 st_track, Sint32 end_track, Sint32 reptime);
extern Sint32  gdFsDaPlaySctG(Sint32 st_sct, Sint32 end_sct, Sint32 reptime);
extern Sint32  gdFsDaStopG(void);
extern Sint32  gdFsDaPauseG(void);
extern Sint32  gdFsDaReleaseG(Sint32 reptime);
extern Sint32  gdFsDaGetInfoG(GDFS_DAINFO *dainfo);
extern Bool  gdFsIsTrayOpenG(void);


/* eof */
