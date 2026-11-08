/* @unit 8C10D25C-8C10D274 */
/* Small SDK (nl library) functions: texture surface tables, triangle/object put attributes, matrix helpers,
   sprite and sound stream setup, memset. */

extern int *gNlTextureSurfaces;
extern int gNlTextureSurfaceCount;
extern int gNlTextureLoadAttempts;
extern int gNlCommonTextureOffset;
extern float gNlGlobalAmbience;
extern float gNlObjectGlobalAmbience;
extern void (*g_0c14a9a8[])(int);
extern float gNlSpriteInverseScreenSize[2];
extern float gNlSpriteScreenSize[2];
extern char gNlSoundStreamHeaderTemplate[];
extern int gNlG2DmaHandles[];
extern char *gNlPaletteTable;

extern int nlPushMatrix(void *m);
extern void nlUnitMatrix();
extern void nlPopMatrix(int n);
extern float nlFloor(float x);
extern float nlLog(float x);
extern float nlScalor(float *v);
extern void nlstripSetVertexContext(void *ctx);
extern void kmRender();
extern void kmFlipFrameBuffer();
extern int kmSetFogDensity(int w);




























void *memset(void *dst, int val, unsigned int n)
{
    unsigned int i;
    char *p = (char *)dst;

    for (i = 0; i < n; i++)
        *p++ = (char)val;
    return dst;
}
