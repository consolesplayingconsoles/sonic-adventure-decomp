/* @unit 8C65E6DC-8C65E6E0 */
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
/* Straight-line functions with loads (batch gen b): getters, copies and float parameter blocks, generated from the code and
   checked by tests. */

void SetCameraDistance(float f4);
float GetCameraDistance(void);
void SetScreenRatio(float f4);
int ReturnBreakPinNum(void);
int ReturnBreakBeachFlag(void);
int getKyakuOffFlag(void);
int Init_Pass_Time(void);
int Get_Bowling_Gate(void);
int CheckNumRideon(void);
int rinRandGetSeed(void);
int nlIntrGetEvent(void);
int kmChangeContextUserClipMode(int a4);
int ADXAMP_GetStat(int a4);
int ADXSJD_GetStat(int a4);
int ADXSJD_GetDecNumSmpl(int a4);
int ADXSTM_GetStat(int a4);
int ADXSTM_GetSj(int a4);
int ADXSTM_GetFileLen(int a4);
int SJMEM_GetUuid(int a4);
int SJMEM_GetBufPtr(int a4);
int SJMEM_GetBufSize(int a4);
int SJRBF_GetUuid(int a4);
int SJRBF_GetBufPtr(int a4);
int SJRBF_GetBufSize(int a4);
int SJRBF_GetXtrSize(int a4);
int SJUNI_GetUuid(int a4);
int ADXB_GetPcmBuf(int a4);
int ADXB_GetFormat(int a4);
int ADXB_GetSfreq(int a4);
int ADXB_GetNumChan(int a4);
int ADXB_GetBlkSmpl(int a4);
int ADXB_GetBlkLen(int a4);
int ADXB_GetTotalNumSmpl(int a4);
int ADXB_GetCof(int a4);
int ADXB_GetLpInsNsmpl(int a4);
int ADXB_GetNumLoop(int a4);
int ADXB_GetLpStartPos(int a4);
int ADXB_GetLpStartOfst(int a4);
int ADXB_GetLpEndPos(int a4);
int ADXB_GetLpEndOfst(int a4);
int ADXB_GetStat(int a4);
int ADXB_GetDecDtLen(int a4);
int ADXB_GetDecNumSmpl(int a4);
int ADXB_GetAdxpd(int a4);
int mwlSbGetGain(int a4);
int mwlSbGetDrctLvl(int a4);
int ADXPD_GetStat(int a4);
int ADXPD_GetNumBlk(int a4);


































































































int SJRBF_GetBufSize(int a4)
{
    int t0;

    t0 = *(int *)((a4 + 0x20));
    return t0;
}
