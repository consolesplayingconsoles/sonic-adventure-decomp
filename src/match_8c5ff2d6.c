/* @unit 8C5FF2D6-8C5FF2DC */
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
/* Small library functions (batch h): NAOMI library setters and stubs, Kamui's register access and system config flags,
   the backup library's jumps into vmsfs, ADX getters and setters. */

extern int *g_8c46c264[];

int nlSingleLineSub(int a, int b, int c, int d);
int nlMultiLineSub(int a, int b);
void ovMdlEntryTbl(int a);
void ovMdlDeleteTbl(int a);
int buExecServer(void);
int buMount(int drive);
int vmsfs_c_setcompletecallback(void *f);
int vmsfs_c_setprogresscallback(void *f);
int vmsfs_c_setcallbackparam(void *p);
int vmsfs_ismount(int drive);
int vmsfs_isformat(int drive);
int vmsfs_setretry(int n);



















/* A stream's pitch word: the octave in bits 11-15, the frequency number below. */














































/* A language character ('0'...) to its number. */
















/* Copies n bytes (whole words) from s to d. */








int syCfgConvLang(int c)
{
    return c - 48;
}
