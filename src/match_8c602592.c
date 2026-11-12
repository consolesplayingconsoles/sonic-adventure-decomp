/* @unit 8C602592-8C6025AC */
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
/* Straight-line functions with calls and guards (batch gen_m): generated from the code and checked by tests. Calls are
   to the game or library function at the address, with the arguments in r4-r7 and fr4-fr11 as set. */

int ADXCRS_Lock(void);
int ADXCRS_Unlock(void);
int ADXERR_EntryErrFunc(int, int);
int ADXF_Init(void);
int ADXSJD_Start(int);
int ADXSTM_SetBufSize(int, int, int);
int ADXSTM_SetEos(int, int);
int ADXSTM_Start(int);
int FUN_0c0f05a0(int, int);
int FUN_0c210336(void);
int FUN_0c213a4e(int, int);
int FUN_0c213d02(void);
int FUN_0c218514(int, int, int, int);
int FUN_0c21b600(int);
int FUN_0c21b654(int);
int FUN_0c21b6b2(int);
int FUN_0c21b73c(int);
int FUN_0c228e94(int, int);
int FUN_0c228ebc(int, int);
int FUN_0c228f20(int, int);
int FUN_0c229028(int);
int FUN_0c229ce0(void);
int FUN_0c229d40(void);
int ADXERR_CallErrFunc(void);
int FUN_0c229ef4(void);
int FUN_0c229f08(void);
int ADXSJD_SetInSj(int, int);
int FUN_0c22a554(int);
int FUN_0c22a590(int);
int FUN_0c22a638(void);
int mwRnaSetFx(int, int, int, int);
int mwRnaSetDrctLvl(int, int, int, int);
int FUN_8c65ddba(int, int, int, int);
int mwRnaGetFx(int, int, int, int);
int mwRnaGetPitch(int, int, int, int);
int FUN_0c22cd34(void);
int FUN_0c22d010(void);
int FUN_0c22fa60(int, int, int);
int FUN_0c22fa7e(int, int, int);
int FUN_0c22fa8e(int);
extern void _builtin_set_imask(int);
int adxf_ExecOne(int);
int adxf_read_sj32(int, int, int);
int buMount(int);
int buUnmount(int);
int gdFsStopRd(int);
int kbCfgIni(int, int, int);
int kdSendFrame(void);
int kmiCopyToFrameBuffer(int, int, int);
int kmiFBGarbageCollect(void);
int kmiFBSortQueue(void);
int kmiFBfree(int);
int kmiFBfreeEx(int, int);
int kmiFBgetfreemem(int, int, int, int);
int kmiQueryFinishDMA(int);
int kmiVQFBfree(int);
int kmtex_GetTextureLevel(int, int);
int memset(int, int, int);
int mpdrv_get_deviceinfo(int);
int pdVibIsReady(int);
int pdVibStart(int, int);
int syBtCfgSet(int, int, int);
int syTmrInt1SetEx(int, int, int, int);
int thunk_FUN_0c22b6fa(void);
int thunk_FUN_0c22b736(int, int, int, int);
int thunk_FUN_0c22c6d0(void);
int thunk_FUN_0c22c8cc(int, int, int, int);
int vmsfs_c_getstate(int);
int vmsfs_fcreate(int, int, int, int);
int vmsfs_fgetinfo(int, int, int);
int vmsfs_fgetsize(int, int);
int vmsfs_findfirst_ex(int, int, int);
int vmsfs_findnext(int, int);
int vmsfs_findnext_ex(int, int, int);
int vmsfs_fisexist(int, int);
int vmsfs_fopen(int, int, int);
int vmsfs_fsetparam(int, int, int);
int vmsfs_setretry(int);
int vmsfs_setwork(int, int, int);
int vmsfs_xcreate(int, int, int, int);
int vmsfs_xfind(int, int);
int buCalcBackupFileSize(int a4, int a5, int a6);
int ADXT_IsIbufSafety(int a4);
int adxt_start_stm(int a4);
int FUN_0c213470(void);
int adxf_ChkPrmGfr(int a4, int a5);
int FUN_0c21b5a6(int a4);
int kmChangeContextFilterMode(int a4);
void kmiDACControl(void);
int FUN_0c21ef80(int a4);
int kmiCopyTextureToTexture(void);
int kmiPutGlobalParam(void);
int ccitt_updcrc(int a4, int a5, int a6, int a7);
int gdFsStrcmpi(int a4, int a5);
int syTmrGenSetClock(int a4);
int kmGetFreeTextureMem(int a4, int a5);
int kmChangeContextPaletteBank(int a4);
int kmChangeVertexPCW(int a4, int a5, int a6);
int gdFsClose(int a4);
int syCfgSetSoundMode(int a4, int a5, int a6);
int kmDiscardVertexBuffer(void);
int bcdtime2fad(int a4);
int buSetFileParam(int a4, int a5, int a6);
int FUN_0c214cdc(int a4, int a5, int a6);
int FUN_0c218676(int a4, int a5, int a6, int a7);
void ADXT_GetNumSctIbuf(int a4);
int adxf_ChkPrmPt(int a4, int a5);
int adxf_CreateAdxFs(void);
int syBtExit(void);
int adxt_start_sj(int a4, int a5);
int ADXF_ExecServer(void);
int ADXF_GetNumReqSct(int a4, int a5);
int buCreateFile(int a4, int a5, int a6, int a7);
int buCreateExecFile(int a4, int a5, int a6, int a7);
int ADXF_ReadSj32(int a4, int a5, int a6);
int ADXT_DiscardSmpl(int a4);
void kmiGetProfileInt(int a4, int a5, int a6);
int buFindFirstFileEx(int a4, int a5, int a6);
int buFindNextFileEx(int a4, int a5, int a6);
int buOpenFile(int a4, int a5, int a6);
int buGetFileInfo(int a4, int a5, int a6);
int syCfgGetCountryCode(int a4, int a5, int a6);
int syCfgGetDefaultLanguage(int a4, int a5, int a6);
int syCfgGetBroadcastType(int a4, int a5, int a6);
int FUN_0c214c80(int a4, int a5, int a6);
int FUN_0c21b7c0(int a4, int a5, int a6);
int kmiWaitAccurate(float f4);
int FUN_0c2186aa(int a4, int a5, int a6, int a7);
int kmiPurgeMemory(int a4, int a5);
int FUN_0c21b7ea(int a4, int a5, int a6);
int gdFsCheckEof(int a4, int a5);
int buFindNextFile(int a4, int a5);
int buFindExecFile(int a4, int a5);
int buIsExistFile(int a4, int a5);
int buGetLastError(int a4);
int buGetFileSize(int a4, int a5);
int pdVibMxStart(int a4, int a5);
int adxf_AllocAdxFs(void);
int gdFsGetTokenSize(int a4, int a5, int a6);
int gdFsGetSearchID(int a4);
void syChainMasterHandlerPVR_H(void);
int syTmrInit(void);
int buUnmountDisk(int a4);
int kmiCopyFromFrameBuffer(int a4, int a5, int a6);
int kmFreeTexture(int a4);
int kmiCreateDummyRegionforAvoidCacheBug(int a4);
int syChainMasterHandler(int a4);
int pdVibMxStop(int a4);
int FUN_0c2211be(int a4, int a5, int a6);
int FUN_0c2211e0(int a4, int a5, int a6);
int FUN_0c22124c(int a4, int a5, int a6);
int buMountDisk(int a4, int a5, int a6);
int kmiWriteRegisters(int a4, int a5, int a6, int a7);
int FUN_0c221282(int a4, int a5, int a6, int a7);
int FUN_0c213b90(int a4);
int FUN_0c213bae(int a4);
int FUN_0c214caa(int a4);
int FUN_0c2186d2(void);
int kmChangeContextDepthMode(int a4);
int kmChangeContextCullingMode(int a4);
int kmChangeContextFlipUV(int a4);
int kmChangeContextClampUV(int a4);
int kmChangeContextStripLength(int a4);
int kmGetCurrentVertexOffset(int a4);
int FUN_0c221142(int a4);
int FUN_0c221212(int a4);
int FUN_0c2212a2(int a4);
int FUN_0c221364(int a4, int a5);
int ADXF_GetFsizeSct(int a4);
int ADXF_Tell(int a4);
int ADXF_GetFsizeByte(int a4);
int ADXF_GetNumReadSct(int a4);
int ADXF_GetStat(int a4);
int FUN_0c214d10(int a4, int a5, int a6, int a7);
int kmQueryFinishFlushVertexBuffer(void);
int FUN_0c22100e(int a4, int a5);
int FUN_0c221230(int a4, int a5);
int buStat(int a4);
int syCfgGetIDAddress(int a4, int a5, int a6);
int kmiDefaultInterruptHandler(int a4);
int FUN_0c220e10(int a4);
int gdFsGetFileSize(int a4, int a5);
int gdFsGetFileSctSize(int a4, int a5);
int gdFsGetFileFad(int a4, int a5);
int gdFsSetTmode(int a4, int a5);
int gdFsGetTransStat(int a4);
int syTmrMicroToCount(int a4);
int syTmrGenSetCount(int a4);
int FUN_0c2134b2(int a4, int a5, int a6, int a7);
int kmChangeContextColorType(int a4);
int kmChangeVertexOffset(int a4, int a5);
void gdFsMemcpy(int a4, int a5, int a6);
int gdFsGetStat(int a4);
int kmiWaitForFinishDMA(int a4);
int kmiCopyToPVRMemory(int a4, int a5, int a6);
int kmiCopyFromPVRMemory(int a4, int a5, int a6);
int gdFsTell(int a4);
int gdFsGetNumRd(int a4);
int FUN_0c214cc8(int a4, int a5, int a6);
int kmGarbageCollectTexture(void);
int FUN_0c2212e0(int a4);
int syCfgInit(int a4);
int ADXT_SetOutVol(int a4, int a5, int a6, int a7);
int kdGetDevice(int a4);
int FUN_0c221160(void);
int FUN_0c221202(void);
int syTmrGenStart(void);
int kmiGetDstVertexBuffer(void);
int FUN_0c2211b0(int a4, int a5);
int FUN_0c22126e(int a4, int a5);
int kdGetDeviceInfo(int a4);
int ADXT_GetOutPan(int a4, int a5);
int kmiAddSysConfigFlag(int a4);
int gdFsCreateDirhn(int a4, int a5);
int kdVbInHandler(void);
int syCfgExit(void);
int ADXT_GetFilter(int a4);
int ADXT_SetFx(int a4, int a5, int a6, int a7);
int ADXT_GetFx(int a4, int a5, int a6, int a7);
int ADXT_SetFilter(int a4, int a5, int a6, int a7);
int ADXT_SetTranspose(int a4, int a5, int a6, int a7);
int ADXT_GetTranspose(int a4, int a5, int a6, int a7);
int ADXF_GetPtinfoSize(int a4);
int kmiFatalErrorEntry(int a4);
int syTmrGetCount(void);
int syTmrGenStop(void);
int syTmrGenGetCount(void);
int kmSetStripLength(int a4);
int kmiSetSysConfigFlag(int a4);
int kdDmaEndHandler1(void);
void buSetPrintFunc(int a4);
int buSetRetryCount(int a4);
int syCfgConvLang(int a4);
int pdVibMxIsReady(int a4);
int FUN_0c213c26(int a4, int a5);
int FUN_0c213cf2(int a4, int a5);
int ADXT_SetPauseBuf(void);
int ADXT_EntryErrFunc(int a4, int a5);
int kmiReadRegister(int a4);
int kmiGetSysConfigFlag(void);
int FUN_0c2212c0(void);
int gdFsChangeDir(void);
int syTmrDiffCount(int a4, int a5);
int FUN_0c213a4a(int a4, int a5);
int ADXT_GetStat(int a4);
void kmiCheckRenderer(void);
void kmiUnloadDevice(void);
void FUN_0c218da0(void);
void kmiInitRenderer(void);
void kmiFastTA(void);
void kmiFastTADirect(void);
int FUN_0c220da0(void);
int FUN_0c220da4(void);
int thunk_FUN_0c221364(int a4, int a5);
int syTmrInt1Set(int a4, int a5, int a6);

























































































































































































































































































































































int syTmrMicroToCount(int a4)
{
    return (((unsigned int)((0x7F & a4) * 0x64) >> 7) + (((unsigned int)a4 >> 7) * 0x64));
}
