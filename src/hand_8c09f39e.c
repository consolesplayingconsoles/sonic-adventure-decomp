/* @unit 8C09F39E-8C09F3AA +egflags */
/* Hand-written from the European disassembly (hand/agentB, byte-exact per tools/jpport/fcmp_x.py). */
typedef unsigned char Uint8;
typedef signed char Sint8;
typedef unsigned short Uint16;
typedef signed short Sint16;
typedef unsigned long Uint32;
typedef signed long Sint32;
typedef float Float;
typedef int Bool;


typedef struct { Sint32 a, b, c, d; } SFHDS;
void SFHDS_InitFhd(SFHDS *p)
{
    p->a = 0;
    p->b = 0;
    p->c = 0;
    p->d = 0;
}
