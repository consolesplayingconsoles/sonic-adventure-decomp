/* @unit 8C65322E-8C653232 */
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
/* Straight-line functions with calls and guards (batch gen_l): generated from the code and checked by tests. Calls are
   to the game or library function at the address, with the arguments in r4-r7 and fr4-fr11 as set. */

typedef struct { int w[4]; } Stk4;
int FUN_0c010250(void);
float FUN_0c0d9e90(int);
float FUN_0c0d9ee0(float);
float FUN_0c0da410(int);
float FUN_0c0da510(float);
int FUN_0c0db4d0(int, int);
int nlTransposeMatrix(void);
int FUN_0c0e2a4c(int);
int FUN_0c0e5dc0(void);
int FUN_0c0e5f1c(int);
int FUN_0c0e631c(int, int, int);
int FUN_0c0e6f62(int, int, float);
int FUN_0c0eaa22(int, int, float, float);
int FUN_0c0eb9c2(int, int, float, float);
int FUN_0c0ed8dc(int, int, int, int);
int FUN_0c0ef250(int, int, int, int);
int FUN_0c0f24ec(int, int);
float FUN_0c0f2fe4(float);
int _INITSCT(void);
int FUN_0c20d728(int, int);
int FUN_0c20ee8e(int);
int FUN_0c20eee6(int);
int FUN_0c20fa76(int);
int syCacheInit_P2_(int);
int FUN_8c658b60(void);
int FUN_8c658b64(void);
int syIntInit(int, int);
int sySqInit(void);
int syMmuDeleteAllEntries(void);
int FUN_0c229028(void);
extern int _builtin_get_imask(void);
extern void _builtin_prefetch(void *);
extern void _builtin_set_imask(int);
int buExecServer(int, int, int, int, float, float, float, float, float, float, float, float);
int fmMngExecServer(void);
int fmMngFormat(int);
int fmMngInit(int, int, int);
int gdFsGetStatG(void);
int gdFsInitOvl(void);
int gdFsLoadDirG(int, int);
int gdFsRead(int, int, int);
int gdFsReopenHn(int, int, int, int);
int kbCfgIni(int, int, int);
int kdGetDeviceInfo(int);
int kdGetDriverMode(int);
int kdGetGunLatchedPort(void);
int kdGetGunPosition(int, int);
int kdSetDriverMode(int, int);
int kdSetGunCallback(int);
int kdSetGunTrigger(int);
int kdSetHandler(int, int);
int kmiDiscardRenderPipeline(int, int, int, int);
int kmiQueryFinishDMA(int);
int kmiReadRegister(int);
int kmiRegisterCallback(int, int, int, int);
int kmiResetBoard(void);
int ntInfExit(void);
int ntInfInit(int, int);
int pdExecPeripheralServerUser(void);
int syChainAddHandler(int, int, int, int);
int syChainDeleteHandler(int);
int syChainInit(void);
int syG2SysInit(void);
int syG2Write(int, int, int, int, int, int);
int syHwCacheFinish(void);
int syRtcDateToCount(void);
int syRtcGetAndCheckCount(int);
int syRtcGetCountForce(void);
int syTmrInit(void);
int vmsfs_c_exit(void);
int vmsfs_c_getstate(int);
int vmsfs_c_setcallbackparam(int);
int vmsfs_c_setcompletecallback(int);
int vmsfs_c_setfunc(int, int);
int vmsfs_c_setparam(int, int, int, int, int, int, int);
int vmsfs_c_setprogresscallback(int);
int vmsfs_diskfree(int, int);
int vmsfs_exit(void);
int vmsfs_findfirst(int, int);
int vmsfs_getinfo(int, int);
int vmsfs_isformat(int);
int vmsfs_ismount(int);
int vmsfs_unmount(int);
int ovSearchLib(int a4);
void gdFsEntryErrFuncAllG(int a4, int a5);
float FUN_0c0f2c4c(float f4);
int FUN_0c0f3ccc(int a4, int a5, int a6);
int gdFsReadWG(int a4, int a5, int a6);
int _pd_peripheral_set_null(int a4);
int FUN_0c0e62e0(int a4, int a5, int a6);
int check_valid(int a4);
int FUN_0c0f2b34(int a4, int a5, int a6);
int syRtcMakeDayOfWeek(int a4, int a5, int a6);
void syHwFinish(void);
void buDisableServer(void);
int buMount(int a4);
int buConnect(int a4);
int syCblCheckBroadcast(int a4, int a5, int a6);
int FUN_0c0ed8a8(int a4, int a5, int a6);
int pd_peripheral_error(int a4, int a5, int a6);
int pdGunSetTrigger(int a4);
int buExit(void);
int FUN_0c0f2fa8(Stk4 s);
void pdExecPeripheralServer(void);
int FUN_0c211376(int a4, int a5);
int syRtcCompareDate(int a4, int a5);
int FUN_0c0e5aa0(void);
int FUN_0c0e5980(int a4, int a5);
int FUN_0c0e5ad0(int a4, int a5);
int FUN_0c0e66d0(int a4, int a5);
int kmSetHSyncCallback(int a4, int a5);
int kmGetGunTriggerPos(int a4, int a5);
int syRtcExecServer(void);
int syRtcInit(void);
int syHwInit(void);
int FUN_0c0e5880(int a4, float f4, float f5);
int ovGetLibTbl(int a4);
int gdFsGetDrvStatG(void);
int syRtcAicaSetWriteFlag(void);
void hwInit(void);
int FUN_0c20d160(void);
int FUN_0c0e5810(int a4, float f4);
int kmUseAnotherModifier(int a4);
int gdFsGetLE4(int a4);
int pdGunLeave(void);
int FUN_0c2113b4(void);
int syRtcAicaSetDateLo(int a4);
int syRtcAicaSetDateHi(int a4);
int buGetDiskInfo(int a4, int a5);
int buGetDiskFree(int a4, int a5);
int buFindFirstFile(int a4, int a5);
int init_fm(int a4, int a5, int a6);
int FUN_0c0ed62c(int a4);
int FUN_0c0f3fe0(int a4, int a5);
int kmSetBackGroundPlane(int a4, int a5);
int kmQueryFinishLastTextureDMA(void);
int gdFsExecServerG(void);
int pdGunEnter(int a4);
int pdGunSetCallback(int a4);
int FUN_0c0e58b0(int a4, int a5);
int FUN_0c0e58e0(int a4, float f4);
int ntInfGetFlag(int a4);
int FUN_0c0f0574(int a4, int a5);
int FUN_0c0edc20(int a4, int a5, int a6);
int FUN_0c0f31b8(int a4, int a5);
int kmSetVSyncCallback(int a4, int a5);
int gdFsCheckMedia(int a4);
int convert_support(int a4);
int FUN_0c0e6380(void);
int ntInfGetNetworkInfo(int a4);
int FUN_0c0f2598(int a4, int a5);
void FUN_0c0f3ca8(float f4);
int syRtcDbgWriteLog(int a4, int a5, int a6);
int buUnmount(int a4);
int wait_done(void);
int FUN_0c0ed5a0(int a4, int a5, int a6, float f4, float f5, float f6, float f7);
int gdFsFinish(void);
int buExitForce(void);
int FUN_0c0e6470(int a4, int a5);
int FUN_0c0e65c0(int a4, int a5);
int ntInfIsNetworkInfo(void);
void FUN_0c0f3c88(float f4);
int kmSetEORCallback(int a4, int a5);
int kmSetStripOverRunCallback(int a4, int a5);
int kmSetTexOverflowCallback(int a4, int a5);
int kmSetEndOfVertexCallback(int a4, int a5);
int kmSetWaitVsyncCallback(int a4, int a5);
int pdGunGetLatchedPort(void);
int FUN_0c0edc60(void);
int FUN_0c0f2a30(int a4, int a5);
int kmfSetFatalErrorCallback(int a4);
int kmSetPALEXTCallback(int a4);
int syCalloc(void);
void p2_cache_set(void);
int memset(int a4, int a5, int a6);
int FUN_0c0f0558(int a4);
int kmSetGlobalClipping(int a4, int a5);
void FUN_0c20ec20(int a4);
int FUN_0c2103bc(void);
int FUN_0c21045c(void);
int FUN_0c0e5910(int a4, int a5);
void FUN_0c20ec38(int a4);
void FUN_0c20f29a(int a4);
int gdFsReinit(void);
int FUN_0c210336(void);
int FUN_0c210378(void);
int FUN_0c21038e(void);
void FUN_0c210400(void);
void FUN_0c210416(void);
int kmResetRenderer(int a4, int a5, int a6, int a7);
int syMallocChangeIF(int a4);
int realloc(void);
int syRtcDbgSetLogAddr(int a4, int a5);
int FUN_0c0f0546(int a4);
void kmiWaitVlank(void);
int syHwInit2(void);
int FUN_0c0f05a0(int a4, int a5);
int pdGetOptimize(void);
int pdGunGetFlashColor(void);
int syRtcFinish(void);
void FUN_0c0ed4e0(float f4, float f5, float f6, float f7, float f8, float f9, float f10);
int kmfSetVertexBufferBaseAddress(int a4, int a5);
int pdGetPeripheral(int a4);
int pdSetMode(int a4);
int pdSetOptimize(int a4);
int pdGunSetFlashColor(int a4);
int FUN_0c0f3a7a(void);
int kmSetWaitVsyncCount(int a4);
void ovInit(int a4, int a5);
int gdFsSetGlobalErrG(int a4);
int pdGetPeripheralError(int a4);
int pdGetPeripheralInfo(int a4);
void pdSetThreshold(int a4, int a5);
int malloc(void);
int syFree(void);
int syMalloc(void);
int free(void);
int syRealloc(void);
int calloc(void);
int FUN_0c0e62d4(int a4, int a5, int a6, int a7);
int FUN_0c0e66c0(int a4, int a5);
int FUN_0c0ed650(int a4);
int FUN_0c0f3a72(void);
int FUN_0c20d188(void);
int FUN_0c20d190(void);
int gdFsGetGlobalErrG(void);
int gdFsGetWorkHnG(void);
int gdFsGetSysHnG(void);
int gdFsInit(void);
int gdFsOpenG(int a4, int a5);
int pdGetMode(void);
int pdGunCheck(void);
int pdGunGetPosition(int a4, int a5);
void syRtcSetServerMode(int a4);
int syRtcGetStat(void);
int buSetCompleteCallback(int a4);
int buSetProgressCallback(int a4);
int buGetVersion(void);
int buSetCallbackParam(int a4);
int buIsReady(int a4);
int buIsFormat(int a4);
int FUN_0c0e65e0(void);
void FUN_0c0eca30(void);
int kmSetForwardClipping(void);
void ovFinish(void);
int gdFsOpenFastG(int a4, int a5);
int gdFsLoadDirFastG(int a4, int a5);
void syMallocFinish(void);
int buInterruptHandler(int a4, int a5, int a6, int a7, float f4, float f5, float f6, float f7, float f8, float f9, float f10, float f11);
int buRemount(int a4);
int FUN_0c0e6f60(int a4, int a5);
int FUN_0c0eaa20(int a4, int a5, float f4, float f5);
int FUN_0c0eb9c0(int a4, int a5, float f4, float f5);
int kmSetEndOfYUVCallback(int a4, int a5);























































































































































































































































































































































int kmSetForwardClipping(void)
{
    return 0x78;
}
