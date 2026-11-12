/* @unit 8C09F822-8C09F840 +egflags */
/* Hand-written from the European disassembly (hand/agentB, byte-exact per tools/jpport/fcmp_x.py). */
typedef unsigned char Uint8;
typedef signed char Sint8;
typedef unsigned short Uint16;
typedef signed short Sint16;
typedef unsigned long Uint32;
typedef signed long Sint32;
typedef float Float;
typedef int Bool;


typedef struct { Sint32 a; Sint32 b; Sint32 c; } ENT;
void FUN_8c09f822(Sint32 x, ENT *start, ENT *end)
{
    ENT *p;
    for (p = start; p < end; p++) {
        if (p->a) {
            p->a = p->a + x + 8;
        }
    }
}
