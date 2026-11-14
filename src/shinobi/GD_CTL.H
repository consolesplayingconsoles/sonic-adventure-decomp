/*
 *  Shinobi Library
 *  Copyright (c) 1998 SEGA
 *  
 *       FileSystem
 *
 *  Module  : GDC Control Module Header File
 *  File    : gd_ctl.h
 *  Date    : 1998-10-01
 *  Modify  :
 *  Author  : T.S. (SEGA, SYSTEM_R&D)
 *  Version : 1.01
 *  Note    :
 */


/***** Macros *****/


/*** DCF Macros ***/

#define  gdDcfInit(dcf)      (dcf)->dcf_init()
#define  gdDcfRead(dcf,fad,nsct,buf,tmode)  \
	(dcf)->dcf_read((fad),(nsct),(buf),(tmode))
#define  gdDcfReqGdRd(dcf,fad,nsct)  \
	(dcf)->dcf_reqgdrd((fad),(nsct))
#define  gdDcfTrans32(dcf,hn,buf,size)  (dcf)->dcf_trans32((hn),(buf),(size))
#define  gdDcfStat(dcf,gdch,err)  (dcf)->dcf_stat((gdch),(err))
#define  gdDcfStop(dcf,gdch)      (dcf)->dcf_stop((gdch))
#define  gdDcfSeek(dcf,fad)  (dcf)->dcf_seek((fad))
#define  gdDcfReset(dcf)     (dcf)->dcf_reset()
#define  gdDcfGetDrvStat(dcf,dstat)  (dcf)->dcf_getdrvstat((dstat))
#define  gdDcfChkDmaTrans(dcf,hn,size)  (dcf)->dcf_chkdmatrans((hn),(size))
#define  gdDcfDaPlay(dcf,sttrack,endtrack,reptime)  (dcf)->dcf_daplay((sttrack),(endtrack),(reptime))
#define  gdDcfDaPlay2(dcf,stsct,endsct,reptime)  \
	(dcf)->dcf_daplay2((stsct),(endsct),(reptime))
#define  gdDcfDaPause(dcf)  (dcf)->dcf_dapause()
#define  gdDcfDaRelease(dcf,reptime)  (dcf)->dcf_darelease((reptime))
#define  gdDcfGetToc(dcf,type,buf)  (dcf)->dcf_gettoc((type),(buf))
#define  gdDcfGetScd(dcf,format,length,buf)  \
	(dcf)->dcf_getscd((format),(length),(buf))
#define  gdDcfSvr(dcf)       (dcf)->dcf_svr()
#define  gdDcfSftReset(dcf)       (dcf)->dcf_sftreset()
#define  gdDcfReqStat(dcf,rep,track,toc,index)  \
	(dcf)->dcf_reqstat((rep),(track),(toc),(index))
#define  gdDcfGetVer(dcf,ver_str)       (dcf)->dcf_getver(ver_str)


/***** structs *****/

/* Device Control Function Table */
struct GDS_DCF {
	Sint32 (* dcf_init)(void);
	Sint32 (* dcf_read)(Sint32, Sint32, void *, Sint32);
	Sint32 (* dcf_reqgdrd)(Sint32, Sint32);
	Sint32 (* dcf_trans32)(Sint32, void *, Sint32);
	Sint32 (* dcf_stat)(Sint32, void *);
	void (* dcf_stop)(Sint32);
	Sint32 (* dcf_seek)(Sint32);
	Sint32 (* dcf_reset)(void);
	Sint32 (* dcf_getdrvstat)(void *);
	Sint32 (* dcf_chkdmatrans)(Sint32, Sint32 *);
	Sint32 (* dcf_daplay)(Sint32, Sint32, Sint32);
	Sint32 (* dcf_daplay2)(Sint32, Sint32, Sint32);
	Sint32 (* dcf_dapause)(void);
	Sint32 (* dcf_darelease)(Sint32);
	Sint32 (* dcf_gettoc)(Sint32, void *);
	Sint32 (* dcf_getscd)(Sint32, Sint32, void *);
	Sint32 (* dcf_svr)(void);
	void (* dcf_sftreset)(void);
	Sint32 (* dcf_reqstat)(Sint32 *, Sint32 *, Sint32 *, Sint32 *);
	Sint32 (* dcf_getver)(Sint8 *);
};


/***** Prototypes *****/

extern GD_DCF  *gdFsGetGdDcf(void);


/* eof */
