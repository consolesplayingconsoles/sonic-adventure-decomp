/* @unit 8C10D330-8C10D340 */
/* Small NAOMI library (nl*) and runtime functions: texture and palette loading, trig helpers, object/triangle
   put attributes, interrupt priority, sound stream and DMA handles, strlen. */

extern float _builtin_sqrtf(float);
/* the 12-byte struct copy in nlObjPutSetFadeColor compiles to a call of this runtime helper */
extern void _quick_odd_mvn(void);

typedef struct { float x, y, z; } Vector3f;
typedef struct { short w, h; int data; int pal; } NlTextureDescriptor;

extern char gNlDummyTextureSurface[];
extern char *gNlPaletteTable;
extern unsigned int gNlPrintFlags;
extern int gNlRenderTextureTableState[3];
extern Vector3f gNlObjectFadeColor;
extern Vector3f gNlObjectFadeColorCopy;
extern signed char g_0c14a9c0[][4];
extern float gNlSpriteScreenSize[2];

void kmCreateTextureSurface(void *s, int w, int h, int fmt);
int kmLoadTexture(void *s, int data, int a, int b);
void nlCreateTextureParamA(void *s);
int kmSetBorderColor(unsigned int c);
float nlSin(int a);
float nlLog(float x);
void nlSetPaletteData(int a, int b, int c);
void nlUnitVector(float *v);
void nlRotateAxe(float *v, int a);
int nlObjPutLoadTextureOnce_Sub(int a, int b, int i, int *pi, int z);
void kmSetCheapShadowMode(void);
void nlObjPutMvSetMode(int mode);
void nlstripSetVertexContext(void *a);






























int strlen(const char *s)
{
    int n = 0;

    while (*s++)
        n++;
    return n;
}
