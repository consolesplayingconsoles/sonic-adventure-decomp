/* @unit 8C664A52-8C664A76 */
extern void _div64(void);
extern void _divls(void);
extern void _divlu(void);
extern void _divws(void);
extern void _modls(void);
extern void _modlu(void);
extern void _quick_evn_mvn(void);
extern void _quick_mvn(void);
extern void _quick_odd_mvn(void);
extern void _quick_strcmp1(void);
extern void _slow_mvn(void);
extern void _slow_strcmp1(void);
extern void _slow_strcpy(void);
/* Straight-line functions with calls and guards (batch gen_ca): generated from the code and checked by tests. Calls are
   to the game or library function at the address, with the arguments in r4-r7 and fr4-fr11 as set. */

typedef struct { int w[4]; } Stk4;
extern int _builtin_tas(char *);
int gdFsGetStatG(void);
int hwInit(void);
int kdDevGetTimerInfo(int, int);
int kdGetDeviceInfo(int);
int kdGetGunLatchedPort(void);
int kdRecvFrame(void);
int kdSetDriverMode(int, int);
int kdSetHandler(int, int);
int mpdrv_dpf(int, ...);
int mpdrv_set_allstatreq_ns(int);
int mpdrv_set_arctrl_ns(int, int);
int mpdrv_set_bread_ns(int, int, int, int, int);
int mpdrv_set_bwrite(int, ...);
int mpdrv_set_dkill_ns(int);
int mpdrv_set_dreq_ns(int);
int mpdrv_set_dreset_ns(int);
int mpdrv_set_end_ns(void);
int mpdrv_set_ft4ctrl_ns(int, int);
int mpdrv_set_getcond_ns(int, int);
int mpdrv_set_getminfo_ns(int, int, int);
int mpdrv_set_setcond_ns(int, int, int, int);
int mpdrv_set_transagain_ns(int);
int mpdrv_setcmd(int, int, int, int, int, int);
int ovInit(int, int);
int pdVibMxIsReady(int);
int pdVibStart(int, int, int);
int pdVmsLcdBltAsm(int, int);
int pdVmsLcdBltAsmFlipH(int, int);
int pdVmsLcdBltAsmFlipHV(int, int);
int pdVmsLcdBltAsmFlipV(int, int);
int syCacheInit_P2_(int);
int syChainAddHandler(int, int, int, int);
int syG2Write(int, int, int, int, int, int);
int syIntInit(int, int);
int syRtcDateToCount(void);
int syRtcGetAndCheckCount(int);
int syRtcGetCountForce(void);
int sySqInit(void);
int syTmrInit(void);
int vmsfs_c_getstate(int);
int vmsfs_fsetparam(int, int, int);
int vmsio_ismount(int);
int buSetFileParam(int a4, int a5, int a6);
int kdSetBlockWrite(Stk4 s);
int fmcalccrc(int a4, int a5, int a6, int a7);
int syRtcCompareDate(int a4, int a5);
int vmsfs_ismount(int a4);
int mpdrv_set_bread(int a4, int a5, int a6, int a7, int a8);
int kdDevGetFD(int a4, int a5);
int mpdrv_set_bwrite_ns(int a4, int a5, int a6, int a7, int a8, int a9, int a10);
int vmsfs_setdevicetype(int a4);
int search_free_dir(int a4);
int mpdrv_set_getlerr_ns(int a4, int a5, int a6, int a7, int a8);
int mpdrv_set_dreq(int a4);
int mpdrv_set_getcond(int a4, int a5);
int mpdrv_set_dreset(int a4);
int mpdrv_set_dkill(int a4);
int mpdrv_set_allstatreq(int a4);
int mpdrv_set_getminfo(int a4, int a5, int a6);
int mpdrv_set_arctrl(int a4, int a5);
int mpdrv_set_ft4ctrl(int a4, int a5);
int mpdrv_set_transagain(int a4);
int mpdrv_set_setcond(int a4, int a5, int a6, int a7);
int mpdrv_set_end(void);
int syRtcInit(void);
int syRtcExecServer(void);
int syHwInit(void);
int pdVmsLcdBlt(int a4, int a5, int a6);
int vmsfs_unmount(int a4);
int gdFsGetDrvStatG(void);
int ovGetLibTbl(int a4);
int pdGunLeave(void);
int syRtcAicaSetDateHi(int a4);
int buGetLastError(int a4);
int pdVibMxStart(int a4, int a5);
int vmsfs_c_execcallback(int a4, int a5, int a6);
void syMmuDeleteEntry(int a4, int a5, int a6);
int gdFsExecServerG(void);
int pdGunEnter(int a4);
int kdSetCallback(int a4, int a5, int a6);
void vmsfs_c_setvolume(int a4, int a5);
void kmytex_FBEnQueueTop(int a4, int a5, int a6, int a7);
int pdVibMxStop(int a4);
int vmsfs_c_progress(int a4);
int pdTmrIsReady(int a4);
int syRtcDbgWriteLog(int a4, int a5, int a6);
int get_fat(int a4, int a5);
int vmsfs_memcmp(int a4, int a5);
int gdFsFinish(void);
int pdGunGetLatchedPort(void);
int vmsfs_c_setcompletecallback(int a4);
int vmsfs_c_setprogresscallback(int a4);
int vmsfs_c_setcallbackparam(int a4);







































































































void kmytex_FBEnQueueTop(int a4, int a5, int a6, int a7)
{
    int t1;

    if ((*(int *)((a4 + 0x0))) == 0) {
        *(unsigned int *)((a6 + 0x4)) = 0x0;
        *(unsigned int *)((a6 + 0x8)) = 0x0;
        *(unsigned int *)((a4 + 0x0)) = a6;
        *(unsigned int *)((a5 + 0x0)) = a6;
    } else {
        t1 = *(int *)((a4 + 0x0));
        *(unsigned int *)((a6 + 0x4)) = (*(int *)((t1 + 0x4)));
        *(unsigned int *)((a6 + 0x8)) = (*(int *)((a4 + 0x0)));
        *(unsigned int *)((t1 + 0x4)) = a6;
        *(unsigned int *)((a4 + 0x0)) = a6;
    }
}
