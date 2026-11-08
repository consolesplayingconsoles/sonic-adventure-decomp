/* @unit 8C6672B0-8C6673C8 */
/* CRI ADX: the bitstream decoders' pool (eight of them), create and destroy, and the default write-position callbacks. One source file
   of the library: its functions share one literal pool. Layout in adxb_dc.h, read from the code; the C written for this game's bytes. */

#include "adxb_dc.h"

void ADXPD_Init(void);
void *ADXPD_Create(void);
void ADXPD_Destroy(void *pd);
void *memset(void *d, int c, unsigned int n);
void ADXB_Destroy(ADXB *d);

extern ADXB adxb_obj[8];

void ADXB_Init(void)
{
    ADXPD_Init();
    memset(adxb_obj, 0, sizeof(adxb_obj));
}

void *adxb_DefGetWr(ADXB *d, int *pos, int *free, int *left)
{
    *pos = d->f156;
    *free = d->f64 - d->f156;
    *left = d->total - d->f152;
    return d->pcmbuf;
}

void adxb_DefAddWr(ADXB *d, int a, int n)
{
    d->f156 += n;
    d->f152 += n;
}

ADXB *ADXB_Create(void *f56, void *pcmbuf, int f64, int f68)
{
    ADXB *d;
    int i;

    for (i = 0; i < 8; i++) {
        if (adxb_obj[i].used == 0)
            break;
    }
    if (i == 8)
        return 0;
    d = &adxb_obj[i];
    memset(d, 0, sizeof(ADXB));
    d->used = 1;
    d->adxpd = ADXPD_Create();
    if (d->adxpd == 0) {
        ADXB_Destroy(d);
        return 0;
    }
    d->f56 = f56;
    d->pcmbuf = pcmbuf;
    d->f64 = f64;
    d->f68 = f68;
    d->getwr = (void *)adxb_DefGetWr;
    d->getwrobj = d;
    d->addwr = (void *)adxb_DefAddWr;
    d->addwrobj = d;
    return d;
}

void ADXB_Destroy(ADXB *d)
{
    if (d) {
        ADXPD_Destroy(d->adxpd);
        memset(d, 0, sizeof(ADXB));
        d->used = 0;
    }
}
