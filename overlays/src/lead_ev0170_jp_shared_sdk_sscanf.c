/* @unit 0CB83860-0CB8389C +rtflags +resff */
/* Ported from the Japanese release's events/shared/sdk/sscanf.c (tools/jpport/mkunit_ov.py): its C rebuilds this range byte for byte. */
typedef char *va_list;
typedef struct _iobuf {
    unsigned char *_bufptr;
    long _bufcnt;
    unsigned char *_bufbase;
    long _buflen;
    char _ioflag1;
} FILE;
int sprintf(char *s, const char *format, ...);
int vsprintf(char *s, const char *format, va_list args);
int sscanf(const char *s, const char *format, ...);
int FUN_0cb838b8(int string_mode, int (*read)(FILE *), const void *input,
           const char *format, va_list arguments);
enum {
    RANGE_ERRNO_FLOAT = 1,
    RANGE_ERRNO_DOUBLE,
    RANGE_ERRNO_LONG_DOUBLE,
    RANGE_ERRNO_RANGE
};
float _stf(int sign, const char *digits, int exponent, char range_errno);
void _calcint(unsigned char *integer, int digit, int count);
float _calcfpow(unsigned char *integer, int n, char range_errno);
float _packf(short exponent, unsigned char *fraction);
int sscanf(const char *s, const char *format, ...)
{
    va_list args;
    int count;
    (void)((args) = (int)((char *)&(format) + sizeof(format)) % 4U ? (char *)&(format) + (((sizeof(format) / 4U) + 1U) * 4U) : (char *)&(format) + sizeof(format));
    count = FUN_0cb838b8(1, ((void *)0), s, format, args);
    ;
    return count;
}
