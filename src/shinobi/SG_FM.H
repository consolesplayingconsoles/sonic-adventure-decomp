/*
 *  Shinobi Library
 *  Copyright (c) 1998 SEGA
 *
 *  Library : Flash Memory Manage Library
 *  Module  : Library Interface Header
 *  File    : sg_fm.h
 *  Date    : 1998-11-27
 *  Author  : T.S. (SEGA, SYSTEM_R&D)
 *  Version : 1.02
 *
 */


#ifndef _SG_FM_H_

#define _SG_FM_H_


/***** macros *****/

#define FMD_EXEC_IDLE   (0)
#define FMD_EXEC_READ   (1)
#define FMD_EXEC_WRITE  (2)

#define FMD_STAT_IDLE      (0)
#define FMD_STAT_COMPLETE  (1)
#define FMD_STAT_BUSY      (2)
#define FMD_STAT_ERR       (3)

#define FMD_CONTINUE    (  1)
#define FMD_OK          (  0)
#define FMD_ERR_READ    ( -1)
#define FMD_ERR_WRITE   ( -2)
#define FMD_ERR_DELETE  ( -3)
#define FMD_ERR_DATA    ( -4)
#define FMD_ERR_BLKADR  ( -5)
#define FMD_ERR_TYPE    ( -6)
#define FMD_ERR_BADBLK  ( -7)
#define FMD_ERR_FMTERR  ( -8)
#define FMD_ERR_BUSY    ( -9)
#define FMD_ERR_FULL    (-10)
#define FMD_ERR_INIT    (-11)

#define FMD_PKT_LEN          (64)
#define FMD_PKT_NRM_DSIZE    (60)
#define FMD_PKT_NRM_CHKSIZE  ( 2)

#define FMD_EOS  (0xFFFF)

#define FMD_TYPE_NORMAL   (0)
#define FMD_TYPE_PROTECT  (1)

#define FMD_FORMATID  "KATANA_FLASH____"
#define FMD_FORMATID_SIZE  (16)
#define FMD_FORMATID_OPTSIZE  (4)

#define FMD_BLKHDR_SIZE  (18)

#define FMD_PAT_CLSIZE  (32768)

/***** structures *****/


/* FM_BLOCK_HEADER */
typedef struct FMS_BLK_HDR {
	const char format_id[16];
	Sint8 blockno;
	Sint8 type;
	Sint8 reserved[46];
} FM_BLKHDR; /* 64 bytes */


/* FM_PACKET_NORMAL */
typedef struct FMS_PKT_NRM {
	Uint16 offset;
	Uint8  data[60];
	Uint16 chk;
} FM_PKTN; /* 64 bytes */


/* FM_WORKAREA */
typedef struct FMS_WORKAREA {
	Sint16 fmblock;
	Sint16 fmtype;
	
	Sint32 blk_adr;
	Sint32 blk_size;
	void  *blk_buf;
	
	Sint32 blk_fre_adr;
	Sint32 blk_pat_adr;
	Sint32 blk_pat_size;
	
	Sint32 exec_mode;
	Sint32 exec_stat;
	Sint32 exec_flag;
	Sint32 exec_ofs;
	Sint32 exec_err;
	void  *exec_buf;
	
	Sint8  pkt_buf[FMD_PKT_LEN];
} FM_WRK; /* 116 bytes */


/***** prototype *****/


Sint32 fmMngInit(Sint32 fmblock, void *work);
Sint32 fmMngFormat(Sint32 type);
Sint32 fmMngRead(Sint32 offset, void *buf);
Sint32 fmMngWrite(Sint32 offset, void *data);
Sint32 fmMngExecServer(void);
Sint32 fmMngGetErr(void);
void fmMngFinish(void);
Sint32 fmMngRefresh(void);
Sint32 fmMngGetFree(void);


#endif /* _SG_FM_H_ */

/* eof */
