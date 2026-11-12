/* @unit 8C09F67C-8C09F69A +egflags */
/* Hand-written from the European disassembly (hand/agentB, byte-exact per tools/jpport/fcmp_x.py). */
typedef unsigned char Uint8;
typedef signed char Sint8;
typedef unsigned short Uint16;
typedef signed short Sint16;
typedef unsigned long Uint32;
typedef signed long Sint32;
typedef float Float;
typedef int Bool;


typedef struct { Sint32 a; Sint32 b; } ENT;
ENT *FUN_8c09f67c(Sint32 x, ENT *p, Sint32 n)
{
    while (n > 0) {
        if (p->a) {
            ENT *q = p;
            q->a = q->a + x;
        }
        n -= 2;
        p++;
    }
    return p;
}
