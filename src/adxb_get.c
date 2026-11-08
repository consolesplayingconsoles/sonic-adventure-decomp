/* @unit 8C6675CC-8C667718 */
/* CRI ADX: the bitstream decoder's accessors, data entry and start/stop. One source file of the library: its functions share one literal pool.
   The decoder layout is read from the code; names from the SDK's function names; the C written for this game's bytes. */

#include "adxb_dc.h"

extern void _divls(void);       /* the compiler calls it for the divisions below; named here so tools/equiv.py links it */

void ADXPD_Stop(void *pd);
void ADXPD_Reset(void *pd);

void ADXB_EntryGetWrFunc(ADXB *d, void *f, void *obj)
{
    d->getwr = f;
    d->getwrobj = obj;
}

void ADXB_EntryAddWrFunc(ADXB *d, void *f, void *obj)
{
    d->addwr = f;
    d->addwrobj = obj;
}

void *ADXB_GetPcmBuf(ADXB *d)
{
    return d->pcmbuf;
}

int ADXB_GetFormat(ADXB *d)
{
    return d->format;
}

int ADXB_GetSfreq(ADXB *d)
{
    return d->sfreq;
}

int ADXB_GetNumChan(ADXB *d)
{
    return d->nch;
}

int ADXB_GetOutBps(ADXB *d)
{
    if (d->format) {
        if (d->format == 2) {
            if (d->f170 == 2)
                return 4;
            if (d->f170 == 1)
                return 8;
        } else if (d->format == 1 && d->f170 == 2) {
            return 4;
        }
    }
    return 16;
}

int ADXB_GetBlkSmpl(ADXB *d)
{
    return d->blksmpl;
}

int ADXB_GetBlkLen(ADXB *d)
{
    return d->blklen;
}

int ADXB_GetTotalNumSmpl(ADXB *d)
{
    return d->total;
}

int ADXB_GetCof(ADXB *d)
{
    return d->cof;
}

int ADXB_GetLpInsNsmpl(ADXB *d)
{
    return d->lpins;
}

int ADXB_GetNumLoop(ADXB *d)
{
    return d->nloop;
}

int ADXB_GetLpStartPos(ADXB *d)
{
    return d->lpspos;
}

int ADXB_GetLpStartOfst(ADXB *d)
{
    return d->lpsofst;
}

int ADXB_GetLpEndPos(ADXB *d)
{
    return d->lpepos;
}

int ADXB_GetLpEndOfst(ADXB *d)
{
    return d->lpeofst;
}

int ADXB_GetStat(ADXB *d)
{
    return d->stat;
}

void ADXB_EntryData(ADXB *d, void *buf, int nbyte)
{
    if (d->format == 0) {
        d->data = buf;
        d->nblk = nbyte / d->blklen;
    } else {
        d->data = buf;
        d->nblk = nbyte / (d->bps / 8 * d->nch);
    }
    d->f132 = 0;
    d->f160 = 0;
    d->decdtlen = 0;
}

void ADXB_Start(ADXB *d)
{
    if (d->stat == 0)
        d->stat = 1;
}

void ADXB_Stop(ADXB *d)
{
    ADXPD_Stop(d->adxpd);
    d->stat = 0;
}

void ADXB_Reset(ADXB *d)
{
    if (d->stat == 3) {
        ADXPD_Reset(d->adxpd);
        d->f156 = 0;
        d->stat = 0;
    }
}

int ADXB_GetDecDtLen(ADXB *d)
{
    return d->decdtlen;
}
