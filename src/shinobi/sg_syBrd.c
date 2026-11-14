/* @unit 8C10BF84-8C10C010 -include=build\sdkinc,build\sdkpriv,src */
/* sg_syBrd.c **************************************************************/
/* for getting infotmation about type of broadcast *************************/
/* 19981127 SEKI Masahiro                          *************************/

#include <sg_xpt.h>
#include "KCFG.H"
#include "sg_syCbl.h"

#define SYD_CBL_BRD_OFS_BROADCAST   (0x0c)
#define SYD_CBL_BRD_TYPE_NTSC		('0')
#define SYD_CBL_BRD_TYPE_PAL		('1')
#define SYD_CBL_BRD_TYPE_PALM		('2')
#define SYD_CBL_BRD_TYPE_PALN		('3')


SYE_CBL_BROADCAST syCblCheckBroadcast( void )
{
	Sint8 *addr;
	SYE_CBL_BROADCAST ret;
	/*** activate configuration to ram ***/
	kbCfgIni( KBD_CFGINI );
	
	/*** get the ram address ***/
	addr = kbCfgGetId();
	
	switch( addr[SYD_CBL_BRD_OFS_BROADCAST] ) {
	case SYD_CBL_BRD_TYPE_PAL:
		ret = SYE_CBL_BROADCAST_PAL;
		break;
	case SYD_CBL_BRD_TYPE_PALM:
		ret = SYE_CBL_BROADCAST_PALM;
		break;
	case SYD_CBL_BRD_TYPE_PALN:
		ret = SYE_CBL_BROADCAST_PALN;
		break;
	case SYD_CBL_BRD_TYPE_NTSC:
	default:
		ret = SYE_CBL_BROADCAST_NTSC;
		break;
	}
	return ret;
}

SYE_CBL syCblCheck( void )
{
	Sint32 index;
	SYE_CBL_CABLE cable;
	SYE_CBL_BROADCAST broadcast;

	cable = syCblCheckCable();
	broadcast = syCblCheckBroadcast();
	if( cable == SYE_CBL_CABLE_VGA ) {
		return SYE_CBL_VGA;
	} else {
		switch( broadcast ) {
		case SYE_CBL_BROADCAST_PAL:
		case SYE_CBL_BROADCAST_PALN:
			return SYE_CBL_PAL;
			break;
		case SYE_CBL_BROADCAST_PALM:
		case SYE_CBL_BROADCAST_NTSC:
		default:
			return SYE_CBL_NTSC;
			break;
		}
	}
}
