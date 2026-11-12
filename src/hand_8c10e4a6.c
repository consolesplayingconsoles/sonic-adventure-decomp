/* @unit 8C10E4A6-8C10E4B6 +egflags */
/* Hand-written from the European disassembly (hand/agentB, byte-exact per tools/jpport/fcmp_x.py). */
typedef unsigned char Uint8;
typedef signed char Sint8;
typedef unsigned short Uint16;
typedef signed short Sint16;
typedef unsigned long Uint32;
typedef signed long Sint32;
typedef float Float;
typedef int Bool;


typedef struct { Sint32 mode; Uint8 *buf; } TXT;
void terminate_text(TXT *p)
{
    if (p->mode == 1) {
        *p->buf = 0;
    }
}
