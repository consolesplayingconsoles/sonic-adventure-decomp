/* @unit 8C11019C-8C1101BC +pool32 */
/* Small library functions (batch j): matrix and line helpers, Kamui vertex buffer and callback setters, the backup and
   system config queries, ADX getters. */

float nlCosf(float a);
float nlSinf(float a);
void nlTranslate(float x, float y, float z);
int kmiQueryFinishDMA(int ch);
int kmiWriteRegister(int off, int v);
void kmiUnloadDevice(void);
void kmiRegisterCallback(int dev, int kind, void *f, void *p);
int vmsfs_c_getstate(int drive);
int kbCfgIni(int a);
int kbCfgGetId(void);
int ADXSJD_GetTotalNumSmpl(int sjd);
int ADXSJD_GetNumChan(int sjd);
void ADXERR_CallErrFunc(char *msg);











/* 1 when the n bytes at p are all 0. */


int _allzero(char *p, int n)
{
    int i;

    for (i = 0; i < n; i++, p++)
        if (*p)
            return 0;
    return 1;
}
