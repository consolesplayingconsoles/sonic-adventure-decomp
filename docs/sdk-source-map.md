# SDK source in Sonic Adventure: what matches and where

What `tools/5-generated/sdk_source.py` found on 2026-11-14, kept here because its own output (`build/`, `sdk-source/`) is local and can be wiped.
Names and addresses only: the SDK's source is not in this repo.

**What counts.** This is a matching decomp: a function is matched only when it is in a C unit and `bash build.sh` ends in MATCH on the whole
image. Everything below that says "match", "verify" or "reproduce" is a weaker check (one function's instructions compared, addresses
masked, constant pools and data not compared) and is a lead, not a result. Matched by that standard so far: `sg_syBrd.c` (2 functions,
unit `src/shinobi/sg_syBrd.c`, build MATCH on 2026-11-14).

- 255 functions verify with this repo's SDK (r9) plus `sdk-headers/sg_bup2.h` and `sdk-patches.txt`: they are `sdk-verified.txt`.
- 120 more verify only with the r10.1 SDK's headers (listed at the end). They are not in `sdk-verified.txt`.
- None of them is a C unit of the build yet. "Trial" is a per-function compare (`tools/fcmp.py`) of the whole source file as a unit; no `build.sh` run has checked one.

| Source file | Verified functions | With r9 | Address runs (start-end, functions) | Trial |
|---|---|---|---|---|
| `FM_.C` | 5 | 5 | 8C603F84-8C604224 (5) | did not compile with the build's own headers; see "Headers" below |
| `FMCRC_.C` | 1 | 1 | 8C64BCE0-8C64BD1C (1) | compiles in the build as it is; all functions match per function |
| `GDCTL_.C` | 1 | 1 | 8C645268-8C645288 (1) | did not compile with the build's own headers; see "Headers" below |
| `GDFS_.C` | 24 | 0 | 8C5FF900-8C5FF926 (1), 8C5FF948-8C5FF952 (1), 8C5FFBD8-8C5FFC3E (1), 8C5FFF72-8C5FFF78 (1), 8C600180-8C6001E2 (1), 8C6002EE-8C600414 (4), 8C60048C-8C600490 (1), 8C600526-8C600C30 (14) | not tried |
| `GDFSDIR_.C` | 4 | 4 | 8C64529C-8C6452B4 (1), 8C64543E-8C64567E (3) | not tried |
| `GDFSHN_.C` | 24 | 24 | 8C600C30-8C600EEC (13), 8C600FC4-8C6014D8 (11) | not tried |
| `GDFSIF_.C` | 21 | 0 | 8C601514-8C6017B4 (21) | not tried |
| `Kdapi_.c` | 20 | 0 | 8C646A70-8C646B7E (6), 8C646B80-8C646E28 (11), 8C646EA8-8C646ECC (1), 8C646F84-8C647002 (1), 8C647194-8C647218 (1) | not tried |
| `KMDELETEDFUNC.C` | 1 | 1 | 8C65322E-8C653232 (1) | did not compile with the build's own headers; see "Headers" below |
| `LCD_.C` | 1 | 0 | 8C6028D8-8C602944 (1) | not tried |
| `LCDVMS_.C` | 4 | 0 | 8C602944-8C602AA8 (4) | not tried |
| `MPAPI_.C` | 32 | 32 | 8C65EAF0-8C65EC0C (1), 8C65F0EA-8C65F42E (26), 8C65F438-8C65F498 (5) | not tried |
| `MPDRV_.C` | 38 | 38 | 8C65F70C-8C65F750 (1), 8C65FBD2-8C65FE52 (5), 8C660262-8C660708 (32) | not tried |
| `NJPAD_.C` | 1 | 1 | 8C6017BA-8C601974 (1) | did not compile with the build's own headers; see "Headers" below |
| `PDMAIN_.C` | 18 | 0 | 8C601974-8C601AF2 (2), 8C601E9A-8C601EC4 (1), 8C601F0C-8C602068 (15) | not tried |
| `Pdvibmx_.c` | 3 | 0 | 8C6042B6-8C604420 (3) | not tried |
| `Rfiber_.c` | 3 | 3 | 8C668C58-8C668CD0 (2), 8C668D9C-8C668DA0 (1) | not tried |
| `sg_syBrd.c` | 2 | 2 | 8C10BF84-8C10C010 (2) | compiles in the build as it is; all functions match per function |
| `sg_syCbl.c` | 2 | 2 | 8C10D854-8C10D878 (2) | compiles in the build as it is; all functions match per function |
| `SG_SYFB_.C` | 7 | 0 | 8C5FBA60-8C5FBAA0 (1), 8C5FBACE-8C5FBB80 (3), 8C5FBBAE-8C5FBBF6 (1), 8C5FBC08-8C5FBC16 (1), 8C5FBC2C-8C5FBC5C (1) | not tried |
| `SG_SYRTC.C` | 20 | 20 | 8C10B988-8C10BF84 (20) | did not compile with the build's own headers; see "Headers" below |
| `SH4TMR_.C` | 13 | 0 | 8C602528-8C6025AC (5), 8C6026CC-8C6026E6 (2), 8C602752-8C6028D8 (6) | not tried |
| `SYBTCFG_.C` | 1 | 1 | 8C64BD1C-8C64BE18 (1) | did not compile with the build's own headers; see "Headers" below |
| `Syhw_.c` | 3 | 0 | 8C602410-8C602486 (3) | not tried |
| `syMalloc_.c` | 1 | 1 | 8C60209E-8C6020A2 (1) | did not compile with the build's own headers; see "Headers" below |
| `Vms_rw_.c` | 4 | 4 | 8C647474-8C64770C (4) | did not compile with the build's own headers; see "Headers" below |
| `VMSAPI_.C` | 33 | 33 | 8C602DB0-8C602DB4 (1), 8C602E9C-8C603690 (31), 8C603696-8C60369C (1) | not tried |
| `Vmscmd_.c` | 11 | 11 | 8C647AF8-8C647CEC (11) | did not compile with the build's own headers; see "Headers" below |
| `Vmsfib_.c` | 5 | 5 | 8C66076C-8C660782 (1), 8C66079A-8C6607D8 (4) | not tried |
| `Vmsio_.c` | 6 | 0 | 8C6607D8-8C6609BE (3), 8C660CCC-8C660DC0 (3) | not tried |
| `Vmsphys_.c` | 64 | 64 | 8C647CEC-8C647D56 (2), 8C647E50-8C647E8C (1), 8C647FE2-8C648474 (9), 8C64888A-8C648914 (1), 8C649422-8C64959C (2), 8C64968A-8C649928 (3), 8C649BA8-8C64A088 (5), 8C64A08A-8C64A33A (3), 8C64A3F2-8C64A52A (2), 8C64A5EA-8C64A68E (3), 8C64A6FA-8C64A768 (1), 8C64A8E8-8C64A956 (1), 8C64ABA2-8C64AC1A (2), 8C64AC96-8C64B1E6 (17), 8C64B21C-8C64B2D0 (2), 8C64B32C-8C64B4C4 (3), 8C64B54E-8C64B5BA (1), 8C64B76C-8C64B85C (1), 8C64B970-8C64BCE0 (5) | not tried |
| `Vmsutil_.c` | 2 | 2 | 8C6038D8-8C60392C (1), 8C603A78-8C603AC4 (1) | not tried |

## Headers

A unit can reach the SDK's headers with no tool change: an option in its first line, `/* @unit <start>-<end> -include=build\sdkinc,build\sdkpriv,src */`.
`build/sdkinc/` is a copy of the SDK's include folders (the r10.1 ones were used) and `build/sdkpriv/` the library's private headers from the
source dump; both are local. The folder names must not hold a hyphen: the compiler rejects the option. Includes written with a path
(`..\fl\SG_FL.H`) are cut to the file name.

Second trial, 12 files that way, compiled with this repo's r9 compiler: 11 compile. All functions match per function in `FMCRC_.C`, `GDCTL_.C`,
`NJPAD_.C`, `SG_SYRTC.C`, `SYBTCFG_.C`, `Vms_rw_.c`, `Vmscmd_.c`, `sg_syBrd.c`, `sg_syCbl.c`. One function differs in `FM_.C` (`fmMngInit`) and one in
`syMalloc_.c` (`syMalloc_default_malloc`). `KMDELETEDFUNC.C` does not compile (errors in `km2vtx.h`). Still no `build.sh` run on any of them.

## The 120 that need the r10.1 headers

`gdFsCreateHn`, `gdFsCreateHnG`, `gdFsDaGetInfoG`, `gdFsDaPauseG`, `gdFsDaPlayG`, `gdFsDaPlaySctG`, `gdFsDaReleaseG`, `gdFsDaStopG`, `gdFsEntryErrFuncAll`, `gdFsEntryErrFuncAllG`, `gdFsExecServer`, `gdFsFinish`, `gdFsFinishG`, `gdFsGetDirInfo`, `gdFsGetDirInfoG`, `gdFsGetDrvStat`, `gdFsGetDrvStatG`, `gdFsGetGlobalErr`, `gdFsGetGlobalErrG`, `gdFsGetLE4`, `gdFsGetSysHn`, `gdFsGetSysHnG`, `gdFsGetToc`, `gdFsGetTocG`, `gdFsGetWorkHn`, `gdFsGetWorkHnG`, `gdFsInit`, `gdFsInitOvl`, `gdFsIsTrayOpenG`, `gdFsLoadDir`, `gdFsLoadDirFast`, `gdFsLoadDirFastG`, `gdFsOpen`, `gdFsOpenFast`, `gdFsOpenFastG`, `gdFsOpenRange`, `gdFsReadW`, `gdFsReadWG`, `gdFsReinit`, `gdFsReqDrvStat`, `gdFsReqDrvStatG`, `gdFsSetDir`, `gdFsSetDirG`, `gdFsSetGlobalErr`, `gdFsSetGlobalErrG`, `kdDevGetControllerInfo`, `kdDevGetFD`, `kdDevGetGunInfo`, `kdDevGetLCDInfo`, `kdDevGetSIPInfo`, `kdDevGetStorageInfo`, `kdDevGetTimerInfo`, `kdDevGetVibrationInfo`, `kdGetDriverMode`, `kdGetGunLatchedPort`, `kdGetGunPosition`, `kdGetSystemInfo`, `kdGetVersion`, `kdIsChanged`, `kdRecognizeChanged`, `kdSetBlockWriteEx`, `kdSetCallback`, `kdSetDeviceResetEx`, `kdSetDriverMode`, `kdSetGunTrigger`, `pdGetMode`, `pdGetOptimize`, `pdGetPeripheral`, `pdGetPeripheralError`, `pdGetPeripheralInfo`, `pdGunCheck`, `pdGunEnter`, `pdGunGetFlashColor`, `pdGunGetLatchedPort`, `pdGunGetPosition`, `pdGunLeave`, `pdGunSetFlashColor`, `pdGunSetTrigger`, `pdInitPeripheral`, `pdInitPeripheralEx`, `pdLcdGetDirection`, `pdSetMode`, `pdSetOptimize`, `pdSetThreshold`, `pdVibMxSetStopTime`, `pdVibMxStart`, `pdVibMxStop`, `pdVmsLcdBlt`, `pdVmsLcdIsReady`, `pdVmsLcdWrite`, `pdVmsLcdWrite1`, `syFbrConvertThreadToFiber`, `syFbrCreateFiber`, `syFbrDeleteFiber`, `syFbrFishin`, `syFbrGetTblPtr`, `syFbrGet_fib_sp`, `syFbrInit`, `syHwFinish`, `syHwInit`, `syHwInit2`, `syTmrCountToMicro`, `syTmrDiffCount`, `syTmrGenCancelInt`, `syTmrGenCountToMicro`, `syTmrGenGetCount`, `syTmrGenMicroToCount`, `syTmrGenSetClock`, `syTmrGenSetCount`, `syTmrGenStart`, `syTmrGenStop`, `syTmrGetCount`, `syTmrInit`, `syTmrMicroToCount`, `vmsfs_memcmp`, `vmsio_exit`, `vmsio_get_media_info`, `vmsio_init`, `vmsio_ismount`, `vmsio_isready`

## Third trial: all 32 files (2026-11-14)

Every source file as one unit with the r10.1 header folders and this repo's r9 compiler, compared per function by `tools/fcmp.py` (instructions, addresses masked).
Trying the r9 SDK's own headers instead gave the same or worse on every file, so the header set is not what makes the rest differ.
`Vmsphys_.c`, `VMSAPI_.C` and `Vmsio_.c` match fewer functions here than `sdk_source.py` verified; the cause is not found (suspect: the static-helper change of `sdk-patches.txt` did not reach this trial's copies).

| Unit | Match | Differ | Compile errors | Functions that differ |
|---|---|---|---|---|
| `FM.c` | 4 | 1 | no | fmMngInit |
| `FMCRC.c` | 1 | 0 | no |  |
| `GDCTL.c` | 1 | 0 | no |  |
| `GDFS.c` | 19 | 12 | no | gdFsGetLE4 gdFsGetStatG gdFsReadWG gdFsInitG gdFsReinitG gdFsLoadDirG gdFsSetDirG gdFsCreateHnG gdFsOpenRangeG gdFsDaPauseG gdFsDaReleaseG gdFsIsTrayOpenG |
| `GDFSDIR.c` | 2 | 3 | no | gdFsMemcpy gdFsGetDirEnt gdFsSearchPath_dds |
| `GDFSHN.c` | 22 | 3 | no | gdFsRead gdFsReqRd32 gdFsStopRd |
| `GDFSIF.c` | 21 | 0 | no |  |
| `KMDELETEDFUNC.c` | 0 | 0 | yes |  |
| `Kdapi.c` | 50 | 7 | no | kdVbInHandler kdInitSystem kdInitSystemEx kdSendFrame kdRecvFrame kdSetDeviceResetEx kdSetBlockWriteEx |
| `LCD.c` | 1 | 0 | no |  |
| `LCDVMS.c` | 4 | 0 | no |  |
| `MPAPI.c` | 32 | 2 | no | mpdrv_init_ex mpdrv_frame_send |
| `MPDRV.c` | 0 | 0 | yes |  |
| `NJPAD.c` | 1 | 0 | no |  |
| `PDMAIN.c` | 18 | 3 | no | pdInitPeripheralEx pdExecPeripheralServerUser pdGunSetCallback |
| `Pdvibmx.c` | 1 | 2 | no | pdVibMxStart pdVibMxStop |
| `Rfiber.c` | 7 | 5 | no | buFbrInit buFbrCreateServer buFbrCreateFiber buFbrExit buFbrExecFiberServer |
| `SG_SYFB.c` | 6 | 2 | no | syFbrConvertThreadToFiber syFbrGet_fib_sp |
| `SG_SYRTC.c` | 19 | 1 | no | syRtcCountToDate |
| `SH4TMR.c` | 15 | 2 | no | syTmrInt1Cancel syTmrGenMicroToCount |
| `SYBTCFG.c` | 1 | 0 | no |  |
| `Syhw.c` | 3 | 1 | no | syHwCacheFinish |
| `VMSAPI.c` | 27 | 18 | no | buInterruptHandler buInit buExecServer buUnmount buGetDiskInfo buGetDiskFree buFindFirstFile buFindNextFile buFindFirstFileEx buFindNextFileEx buFindExecFile buOpenFile buCreateFile buCreateExecFile buSetFileParam buIsExistFile buGetFileInfo buGetFileSize |
| `Vms_rw.c` | 4 | 0 | no |  |
| `Vmscmd.c` | 12 | 1 | no | vmsfs_c_init |
| `Vmsfib.c` | 6 | 0 | no |  |
| `Vmsio.c` | 4 | 4 | no | vmsio_get_media_info vmsio_block_read vmsio_block_write vmsio_ismount |
| `Vmsphys.c` | 54 | 41 | no | vmsfs_init vmsfs_init_work_normal vmsfs_mount vmsfs_mount2 vmsfs_fgetinfo vmsfs_format vmsfs_getinfo vmsfs_diskfree vmsfs_sysdiskfree vmsfs_fopen vmsfs_xcreate vmsfs_fcreate vmsfs_fsetparam vmsfs_fclose vmsfs_fwrite vmsfs_fwrite1 vmsfs_xwrite1 vmsfs_fread1 vmsfs_fisexist vmsfs_findfirst vmsfs_findfirst_ex vmsfs_findnext_ex vmsfs_fdelete_ex vmsfs_frename vmsfs_fsettime vmsfs_xfind vmsfs_setvolume search_dir_by_startfat vmsfs_xdefrag write_dir_all write_dir set_file_info search_dir open_file_handle close_file_handle check_file_correct vmsfs_read_disk_image vmsfs_load_file vmsfs_save_file vmsfs_save_exec_file vmsfs_rewrite_exec_file |
| `Vmsutil.c` | 2 | 2 | no | buMakeBackupFileImage buAnalyzeBackupFileImage |
| `sg_syBrd.c` | 2 | 0 | no |  |
| `sg_syCbl.c` | 2 | 0 | no |  |
| `syMalloc.c` | 3 | 1 | no | syMalloc_default_malloc |

Total matching per function: 344. Whole files with every function matching: 11.
