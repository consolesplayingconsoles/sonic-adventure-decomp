/* CRI ADX bitstream decoder (ADXB), as this game's code lays it out: 172 bytes, eight of them in adxb_obj. */
#ifndef ADXB_DC_H
#define ADXB_DC_H
typedef struct {
    short used;
    short pad0;
    int stat;               /* +4 */
    void *adxpd;            /* +8 */
    char pad1;
    signed char bps;        /* +13 */
    signed char nch;        /* +14 */
    signed char blklen;     /* +15 */
    int blksmpl;            /* +16 */
    int sfreq;              /* +20 */
    int total;              /* +24 */
    short cof;              /* +28 */
    short pad2;
    int lpins;              /* +32 */
    short nloop;            /* +36 */
    short pad3;
    int lpspos;             /* +40 */
    int lpsofst;            /* +44 */
    int lpepos;             /* +48 */
    int lpeofst;            /* +52 */
    void *f56;              /* +56 */
    void *pcmbuf;           /* +60 */
    int f64;                /* +64 */
    int f68;                /* +68 */
    int pad5[2];
    void *data;             /* +80 */
    int nblk;               /* +84 */
    int pad6[11];
    int f132;               /* +132 */
    void *getwr;            /* +136 */
    void *getwrobj;
    void *addwr;            /* +144 */
    void *addwrobj;
    int f152;               /* +152 */
    int f156;               /* +156 */
    int f160;               /* +160 */
    int decdtlen;           /* +164 */
    short format;           /* +168 */
    short f170;             /* +170 */
} ADXB;

#endif
