/* @unit 8C051760-8C0519C0 @ddata 8C19E324-8C19E8A4 +r04 +egflags +pool32 */
/* Ported from the Japanese release's src/system/frame.c (tools/jpport/mkunit.py): its C rebuilds this range byte for byte. */
typedef unsigned int KMSTATUS;
typedef unsigned char KMBYTE;
typedef unsigned short KMWORD;
typedef int KMINT32;
typedef int KMBOOLEAN;
typedef unsigned int KMUINT32;
typedef KMUINT32 *PKMUINT32;
typedef KMINT32 *PKMINT32;
typedef unsigned long KMDWORD;
typedef KMDWORD *PKMDWORD;
typedef float KMFLOAT;
typedef KMFLOAT *PKMFLOAT;
typedef unsigned int KMTEXTURETYPE;
typedef void *PVOID;
typedef void *PKMVOID;
typedef union _tagKMPACKEDARGB {
    KMDWORD dwPacked;
    struct {
        KMBYTE bBlue;
        KMBYTE bGreen;
        KMBYTE bRed;
        KMBYTE bAlpha;
    } byte;
} KMPACKEDARGB;
typedef void (*PKMCALLBACKFUNC)(void *pArgs);
typedef struct tagKMSURFACEDESC {
    KMDWORD SurfaceType;
    KMDWORD BitDepth;
    KMDWORD PixelFormat;
    union {
        KMDWORD USize;
        KMDWORD Width;
    } u0;
    union {
        KMDWORD VSize;
        KMDWORD Height;
    } u1;
    union {
        KMDWORD dwTextureSize;
        KMDWORD dwFrameBufferSize;
    } uSize;
    KMDWORD fSurfaceFlags;
    PKMDWORD pSurface;
    PKMDWORD pVirtual;
    PKMDWORD pPhysical;
} KMSURFACEDESC, *PKMSURFACEDESC;
typedef struct tagKMVERTEXCONTEXT {
    KMDWORD RenderState;
    KMINT32 ParamType;
    KMINT32 ListType;
    KMINT32 ColorType;
    KMINT32 UVFormat;
    KMINT32 DepthMode;
    KMINT32 CullingMode;
    KMINT32 ScreenCoordination;
    KMINT32 ShadingMode;
    KMINT32 SelectModifier;
    KMBOOLEAN bZWriteDisable;
    KMINT32 SRCBlendingMode;
    KMINT32 DSTBlendingMode;
    KMBOOLEAN bSRCSel;
    KMBOOLEAN bDSTSel;
    KMINT32 FogMode;
    KMBOOLEAN bUseSpecular;
    KMBOOLEAN bUseAlpha;
    KMBOOLEAN bIgnoreTextureAlpha;
    KMINT32 ClampUV;
    KMINT32 FlipUV;
    KMINT32 FilterMode;
    KMBOOLEAN bSuperSample;
    KMDWORD MipMapAdjust;
    KMINT32 TextureShadingMode;
    KMBOOLEAN bColorClamp;
    KMDWORD PaletteBank;
    PKMSURFACEDESC pTextureSurfaceDesc;
    KMFLOAT fFaceColorAlpha;
    KMFLOAT fFaceColorRed;
    KMFLOAT fFaceColorGreen;
    KMFLOAT fFaceColorBlue;
    KMFLOAT fOffsetColorAlpha;
    KMFLOAT fOffsetColorRed;
    KMFLOAT fOffsetColorGreen;
    KMFLOAT fOffsetColorBlue;
    KMDWORD GLOBALPARAMBUFFER;
    KMDWORD ISPPARAMBUFFER;
    KMDWORD TSPPARAMBUFFER;
    KMDWORD TexturePARAMBUFFER;
    KMDWORD ModifierInstruction;
    KMFLOAT fBoundingBoxXmin;
    KMFLOAT fBoundingBoxYmin;
    KMFLOAT fBoundingBoxXmax;
    KMFLOAT fBoundingBoxYmax;
    KMBOOLEAN bDCalcExact;
    KMINT32 StripLength;
    KMINT32 UserClipMode;
} KMVERTEXCONTEXT, *PKMVERTEXCONTEXT, **PPKMVERTEXCONTEXT;
typedef struct _tagKMCURRENTLISTSTATE {
    KMDWORD ListType;
    KMDWORD GlobalParamSize;
    KMDWORD Reserved0;
    KMDWORD VertexBank;
} KMCURRENTLISTSTATE, *PKMCURRENTLISTSTATE;
typedef struct _tagKMVERTEXBUFFDESC {
    PKMDWORD *pCurrentPtr;
    PKMDWORD pGlobalParam;
    PKMCURRENTLISTSTATE pCurrentListState;
    PKMDWORD **ppBuffer;
    KMDWORD fActiveList;
    KMDWORD Reserved1;
    KMDWORD Reserved2;
    KMDWORD Reserved3;
} KMVERTEXBUFFDESC, *PKMVERTEXBUFFDESC;
KMSTATUS kmRender(void);
KMSTATUS kmFlipFrameBuffer(void);
KMSTATUS kmSetEORCallback(PKMCALLBACKFUNC callback, void *argument);
KMSTATUS kmSetVSyncCallback(PKMCALLBACKFUNC callback, void *argument);
KMSTATUS kmSetHSyncCallback(PKMCALLBACKFUNC callback, void *argument);
KMSTATUS kmSetTexOverflowCallback(PKMCALLBACKFUNC callback, void *argument);
KMSTATUS kmSetStripOverRunCallback(PKMCALLBACKFUNC callback, void *argument);
KMSTATUS kmSetEndOfVertexCallback(PKMCALLBACKFUNC callback, void *argument);
KMSTATUS kmSetEndOfYUVCallback(PKMCALLBACKFUNC callback, void *argument);
KMSTATUS kmSetWaitVsyncCallback(PKMCALLBACKFUNC callback, void *argument);
KMSTATUS kmfSetFatalErrorCallback(PKMCALLBACKFUNC callback);
KMSTATUS kmSetHSyncLine(KMINT32 line);
KMSTATUS kmGetCurrentScanline(KMINT32 *line);
KMSTATUS kmSetBorderColor(KMPACKEDARGB color);
KMSTATUS kmProcessVertexRenderState(PKMVERTEXCONTEXT pVertexContext);
KMSTATUS kmSetVertexRenderState(PKMVERTEXCONTEXT pVertexContext);
KMSTATUS kmSetModifierRenderState(PKMVERTEXCONTEXT pVertexContext);
KMSTATUS kmSetStripLength(KMINT32 StripLength);
KMSTATUS kmSetCheapShadowMode(KMINT32 nIntensity);
KMSTATUS kmChangeContextColorType(KMINT32 Color);
KMSTATUS kmChangeContextDepthMode(KMINT32 DepthMode);
KMSTATUS kmChangeContextCullingMode(KMINT32 CullingMode);
KMSTATUS kmChangeContextZWriteDisable(KMBOOLEAN fZWriteDisable);
KMSTATUS kmChangeContextSRCBlendMode(KMINT32 SRCBlend);
KMSTATUS kmChangeContextDSTBlendMode(KMINT32 DSTBlend);
KMSTATUS kmChangeContextFogMode(KMINT32 FogMode);
KMSTATUS kmChangeContextFlipUV(KMINT32 FlipMode);
KMSTATUS kmChangeContextClampUV(KMINT32 ClampMode);
KMSTATUS kmChangeContextFilterMode(KMINT32 FilterMode);
KMSTATUS kmChangeContextSuperSample(KMBOOLEAN fEnable);
KMSTATUS kmChangeContextTextureShadingMode(KMINT32 TexShadingmode);
KMSTATUS kmChangeContextColorClamp(KMBOOLEAN fColorClamp);
KMSTATUS kmChangeContextPaletteBank(KMDWORD Bank);
KMSTATUS kmChangeContextStripLength(KMINT32 StripLength);
KMSTATUS kmChangeContextUserClipMode(KMINT32 UserClipMode);
KMSTATUS kmSetPaletteMode(KMINT32 Palettemode);
KMSTATUS kmCreateTextureSurface(PKMSURFACEDESC pSurfaceDesc, KMINT32 nWidth,
                                KMINT32 nHeight, KMTEXTURETYPE nTextureType);
KMSTATUS kmLoadTexture(PKMSURFACEDESC pSurfaceDesc, PKMDWORD pTexture,
                       KMBOOLEAN fAutoMipMap, KMBOOLEAN fDither);
KMSTATUS kmfSetVertexBufferBaseAddress(KMDWORD dwBaseAddress,
                                       KMDWORD dwVertexBufferSize);
typedef struct _tagKMISYSTEMMETRICS {
    struct _tagNativeParams {
        KMDWORD NativeITPBase;
        KMDWORD NativeOBJBase;
        KMDWORD NativeRegBase;
        KMDWORD NativeITPLimit;
        KMDWORD NativeOBJLimit;
        KMDWORD NativeLastITPCurrent;
    } NativeParams[2];
    struct _tagFBParams {
        KMDWORD FBStartAddr[2];
        KMDWORD FBLineStride[2];
        KMDWORD XClip;
        KMDWORD YClip;
    } FBParams;
    KMDWORD RenderTimeOutCount;
    KMDWORD VertexTimeOutCount;
    KMDWORD OBJOverflowCount;
    KMDWORD ITPOverflowCount;
    KMDWORD DMADataAddress[2][5];
    KMDWORD InternalVertexBufSize[5];
    KMDWORD MaxVertexBufSize[5];
    KMDWORD LastTATime;
    KMDWORD LastRenderTime;
    KMDWORD Reserved2;
    KMDWORD Reserved3;
    KMDWORD Reserved4;
    KMDWORD Reserved5;
    KMDWORD Reserved6;
    KMDWORD Reserved7;
} KMISYSTEMMETRICS, *PKMISYSTEMMETRICS;
KMSTATUS kmfGetInternalSystemMetrics(PKMISYSTEMMETRICS pSystemMetrics);
KMSTATUS kmfSetTimeOutCount(KMDWORD nVertexTimeOut, KMDWORD nRenderTimeOut);
KMSTATUS kmfInitializeYUVConverter(PKMSURFACEDESC pSurface, KMDWORD TextureType,
                                   KMDWORD ConvertMode, KMDWORD xMBSize,
                                   KMDWORD yMBSize);
KMSTATUS kmfSetCommonModifier(PKMDWORD pCommonBuffer, KMDWORD BufferSize);
KMSTATUS kmRenderTexture(PKMSURFACEDESC pTextureSurface);
KMSTATUS kmGetTexture(PKMDWORD pTexture, PKMSURFACEDESC pSurfaceDesc);
KMSTATUS kmFreeTexture(PKMSURFACEDESC pSurfaceDesc);
KMSTATUS kmSetPixelClipping(KMINT32 Xmin, KMINT32 Ymin, KMINT32 Xmax,
                            KMINT32 Ymax);
KMSTATUS kmSetStrideWidth(KMINT32 nWidth);
typedef enum {
    KM_DSPBPP_RGB565 = 0,
    KM_DSPBPP_RGB555 = 1,
    KM_DSPBPP_ARGB1555 = 3,
    KM_DSPBPP_RGB888 = 4,
    KM_DSPBPP_ARGB8888 = 5
} KMBPPMODE;
KMSTATUS kmuConvertFBtoBMP(PKMDWORD pOutputData, PKMDWORD pInputData,
                           KMINT32 nWidth, KMINT32 nHeight, KMBPPMODE nBpp);
KMSTATUS kmuCreateTwiddledTexture(PKMDWORD pOutputTexture,
                                  PKMDWORD pInputTexture, KMBOOLEAN bAutoMipMap,
                                  KMBOOLEAN bDither, KMINT32 USize,
                                  KMTEXTURETYPE nTextureType);
typedef KMUINT32 KMUPASSSTATUS;
KMSTATUS kmuSetTarget(KMDWORD dwTarget);
KMUPASSSTATUS kmuGeneratePassTable(PKMVERTEXCONTEXT pVertexContext,
                                   KMUINT32 nNumContext,
                                   PPKMVERTEXCONTEXT ppVertexContextTable,
                                   PKMUINT32 pPass);
KMUPASSSTATUS kmuCheckPassTable(PPKMVERTEXCONTEXT ppVertexContextTable,
                                KMUINT32 nNumContext, PKMUINT32 pPass);
KMSTATUS kmGetFreeTextureMem(PKMUINT32 pSizeOfTexture,
                             PKMUINT32 pMaxBlockSizeOfTexture);
KMSTATUS kmGarbageCollectTexture(void);
KMSTATUS kmQueryFinishLastTextureDMA(void);
KMSTATUS kmSetFogTableColor(KMPACKEDARGB FogTableColor);
/* kmSetFogTable: kmSetFogTable here */
KMSTATUS kmSetFogDensity(KMDWORD fogDensity);
KMSTATUS kmLoadYUVTexture(PKMSURFACEDESC pSurfaceDesc, PKMDWORD pTexture,
                          KMINT32 nWidth, KMINT32 nHeight, KMINT32 nFormat,
                          KMBOOLEAN bWaitEndOfDMA);
KMSTATUS kmCreateCombinedTextureSurface(PKMSURFACEDESC pSurfaceDesc1,
                                        PKMSURFACEDESC pSurfaceDesc2,
                                        KMINT32 nWidth, KMINT32 nHeight,
                                        KMTEXTURETYPE nTextureType);
KMSTATUS kmCreateContiguousTextureSurface(PKMSURFACEDESC pSurfaceDesc,
                                          KMINT32 nTexture, KMINT32 nWidth,
                                          KMINT32 nHeight,
                                          KMTEXTURETYPE nTextureType);
KMSTATUS kmLoadTextureBlock(PKMSURFACEDESC pSurfaceDesc, PKMDWORD pTexture,
                            KMUINT32 nBlockNum, KMUINT32 nBlockSize);
KMSTATUS kmLoadTexturePart(PKMSURFACEDESC pSurfaceDesc, PKMDWORD pTexture,
                           KMUINT32 nOffset, KMUINT32 nSize);
KMSTATUS kmLoadRectangleTexturePart(PKMSURFACEDESC pSurfaceDesc,
                                    PKMDWORD pTexture, KMUINT32 width,
                                    KMUINT32 height, KMUINT32 dst_X,
                                    KMUINT32 dst_Y, KMUINT32 src_X,
                                    KMUINT32 src_Y, KMUINT32 src_U);
KMSTATUS kmLoadVQCodebook(PKMSURFACEDESC pSurfaceDesc, PKMDWORD pTexture);
KMSTATUS kmReLoadMipmap(PKMSURFACEDESC pSurfaceDesc, PKMVOID pTexture,
                        KMINT32 nMipmapCount);
typedef struct tagKMVERTEX0 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMDWORD Reserved0;
    KMDWORD Reserved1;
    KMPACKEDARGB uBaseRGB;
    KMDWORD Reserved2;
} KMVERTEX0, *PKMVERTEX0;
typedef struct tagKMVERTEX1 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMFLOAT fBaseAlpha;
    KMFLOAT fBaseRed;
    KMFLOAT fBaseGreen;
    KMFLOAT fBaseBlue;
} KMVERTEX1, *PKMVERTEX1;
typedef struct tagKMVERTEX2 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMDWORD Reserved0;
    KMDWORD Reserved1;
    KMFLOAT fBaseIntensity;
    KMDWORD Reserved2;
} KMVERTEX2, *PKMVERTEX2;
typedef enum { KM_VERTEXTYPE_00 = 0, KM_VERTEXTYPE_03 = 3 } KMVERTEXTYPE;
typedef struct tagKMVERTEX3 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMFLOAT fU;
    KMFLOAT fV;
    KMPACKEDARGB uBaseRGB;
    KMPACKEDARGB uOffsetRGB;
} KMVERTEX3, *PKMVERTEX3;
typedef struct tagKMVERTEX4 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMDWORD dwUV;
    KMDWORD Reserved0;
    KMPACKEDARGB uBaseRGB;
    KMPACKEDARGB uOffsetRGB;
} KMVERTEX4, *PKMVERTEX4;
typedef struct tagKMVERTEX5 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMFLOAT fU;
    KMFLOAT fV;
    KMDWORD Reserved0;
    KMDWORD Reserved1;
    KMFLOAT fBaseAlpha;
    KMFLOAT fBaseRed;
    KMFLOAT fBaseGreen;
    KMFLOAT fBaseBlue;
    KMFLOAT fOffsetAlpha;
    KMFLOAT fOffsetRed;
    KMFLOAT fOffsetGreen;
    KMFLOAT fOffsetBlue;
} KMVERTEX5, *PKMVERTEX5;
typedef struct tagKMVERTEX6 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMDWORD dwUV;
    KMDWORD Reserved0;
    KMDWORD Reserved1;
    KMDWORD Reserved2;
    KMFLOAT fBaseAlpha;
    KMFLOAT fBaseRed;
    KMFLOAT fBaseGreen;
    KMFLOAT fBaseBlue;
    KMFLOAT fOffsetAlpha;
    KMFLOAT fOffsetRed;
    KMFLOAT fOffsetGreen;
    KMFLOAT fOffsetBlue;
} KMVERTEX6, *PKMVERTEX6;
typedef struct tagKMVERTEX7 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMFLOAT fU;
    KMFLOAT fV;
    KMFLOAT fBaseIntensity;
    KMFLOAT fOffsetIntensity;
} KMVERTEX7, *PKMVERTEX7;
typedef struct tagKMVERTEX8 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMDWORD dwUV;
    KMDWORD Reserved0;
    KMFLOAT fBaseIntensity;
    KMFLOAT fOffsetIntensity;
} KMVERTEX8, *PKMVERTEX8;
typedef struct tagKMVERTEX9 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMPACKEDARGB uBaseRGB0m;
    KMPACKEDARGB uBaseRGB1m;
    KMDWORD Reserved0;
    KMDWORD Reserved1;
} KMVERTEX9, *PKMVERTEX9;
typedef struct tagKMVERTEX10 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMFLOAT fBaseIntensity0m;
    KMFLOAT fBaseIntensity1m;
    KMDWORD Reserved0;
    KMDWORD Reserved1;
} KMVERTEX10, *PKMVERTEX10;
typedef struct tagKMVERTEX11 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMFLOAT fU0m;
    KMFLOAT fV0m;
    KMPACKEDARGB uBaseRGB0m;
    KMPACKEDARGB uOffsetRGB0m;
    KMFLOAT fU1m;
    KMFLOAT fV1m;
    KMPACKEDARGB uBaseRGB1m;
    KMPACKEDARGB uOffsetRGB1m;
    KMDWORD Reserved0;
    KMDWORD Reserved1;
    KMDWORD Reserved2;
    KMDWORD Reserved3;
} KMVERTEX11, *PKMVERTEX11;
typedef struct tagKMVERTEX12 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMDWORD dwUV0m;
    KMDWORD Reserved0;
    KMPACKEDARGB uBaseRGB0m;
    KMPACKEDARGB uOffsetRGB0m;
    KMDWORD dwUV1m;
    KMDWORD Reserved1;
    KMPACKEDARGB uBaseRGB1m;
    KMPACKEDARGB uOffsetRGB1m;
    KMDWORD Reserved2;
    KMDWORD Reserved3;
    KMDWORD Reserved4;
    KMDWORD Reserved5;
} KMVERTEX12, *PKMVERTEX12;
typedef struct tagKMVERTEX13 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMFLOAT fU0m;
    KMFLOAT fV0m;
    KMFLOAT fBaseIntensity0m;
    KMFLOAT fOffsetIntensity0m;
    KMFLOAT fU1m;
    KMFLOAT fV1m;
    KMFLOAT fBaseIntensity1m;
    KMFLOAT fOffsetIntensity1m;
    KMDWORD Reserved0;
    KMDWORD Reserved1;
    KMDWORD Reserved2;
    KMDWORD Reserved3;
} KMVERTEX13, *PKMVERTEX13;
typedef struct tagKMVERTEX14 {
    KMDWORD ParamControlWord;
    KMFLOAT fX;
    KMFLOAT fY;
    union {
        KMFLOAT fZ;
        KMFLOAT fInvW;
    } u;
    KMDWORD dwUV0m;
    KMDWORD Reserved0;
    KMFLOAT fBaseIntensity0m;
    KMFLOAT fOffsetIntensity0m;
    KMDWORD dwUV1m;
    KMDWORD Reserved1;
    KMFLOAT fBaseIntensity1m;
    KMFLOAT fOffsetIntensity1m;
    KMDWORD Reserved2;
    KMDWORD Reserved3;
    KMDWORD Reserved4;
    KMDWORD Reserved5;
} KMVERTEX14, *PKMVERTEX14;
typedef struct tagKMVERTEX16 {
    KMDWORD ParamControlWord;
    KMFLOAT fAX;
    KMFLOAT fAY;
    union {
        KMFLOAT fAZ;
        KMFLOAT fAInvW;
    } uA;
    KMFLOAT fBX;
    KMFLOAT fBY;
    union {
        KMFLOAT fBZ;
        KMFLOAT fBInvW;
    } uB;
    KMFLOAT fCX;
    KMFLOAT fCY;
    union {
        KMFLOAT fCZ;
        KMFLOAT fCInvW;
    } uC;
    KMFLOAT fDX;
    KMFLOAT fDY;
    KMDWORD Reserved0;
    KMDWORD dwUVA;
    KMDWORD dwUVB;
    KMDWORD dwUVC;
} KMVERTEX16, *PKMVERTEX16;
KMSTATUS kmStartVertexStrip(PKMVERTEXBUFFDESC pBufferDesc);
KMSTATUS kmSetVertex(PKMVERTEXBUFFDESC pBufferDesc, void *pVertex,
                     KMVERTEXTYPE VertexType, KMINT32 StructSize);
KMDWORD kmGetCurrentVertexOffset(KMINT32 ListType);
KMSTATUS kmChangeVertexOffset(KMINT32 ListType, KMDWORD VertexOffset);
KMSTATUS kmChangeVertexPCW(KMINT32 ListType, KMDWORD VertexPCW, KMDWORD IncPtr);
KMSTATUS kmFlushVertexBuffer(KMINT32 ListType);
KMSTATUS kmQueryFinishFlushVertexBuffer(void);
PKMDWORD kmiMemCopy8(PKMDWORD dstPtr, PKMDWORD SrcAdr, KMDWORD Size);
void kmResetPointer(void);
typedef enum { KM_NTSC = 0, KM_VGA = 1, KM_PAL = 2 } KMVIDEOMODE;
typedef enum { KM_DSPMODE_VGA = KM_VGA } KMDISPLAYMODE;
typedef union _tagKMPALETTEDATA {
    KMDWORD dwPaletteData[1024];
} KMPALETTEDATA, *PKMPALETTEDATA;
typedef enum _tagKMADJUSTTYPE {
    KM_LEVEL_ADJUST_NORMAL,
    KM_LEVEL_ADJUST_HALF
} KMADJUSTTYPE;
KMSTATUS kmSetCullingRegister(KMFLOAT fCullVal);
typedef enum { KM_LATENCYMODEL_3V = 0, KM_LATENCYMODEL_2V = 1 } KMLATENCYMODEL;
typedef enum {
    KM_VERTEXBUFMODEL_NORMAL = 0x00,
    KM_VERTEXBUFMODEL_NOBUF_OPAQUE = 0x20,
    KM_VERTEXBUFMODEL_NOBUF_OPAQUE_MODIFIER = 0x21,
    KM_VERTEXBUFMODEL_NOBUF_TRANS = 0x22,
    KM_VERTEXBUFMODEL_NOBUF_TRANS_MODIFIER = 0x23,
    KM_VERTEXBUFMODEL_NOBUF_PUNCH_THROUGH = 0x24
} KMVERTEXBUFMODEL;
typedef struct _tagKMSYSTEMCONFIGSTRUCT {
    KMDWORD dwSize;
    KMDWORD flags;
    PKMSURFACEDESC *ppSurfaceDescArray;
    KMUINT32 nNumOfFrameBuffer;
    KMUINT32 nWidth;
    KMUINT32 nHeight;
    KMBPPMODE nBpp;
    KMUINT32 nTextureMemorySize;
    PKMVERTEXBUFFDESC pBufferDesc;
    PKMDWORD pVertexBuffer;
    KMUINT32 nVertexBufferSize;
    KMFLOAT fBufferSize[5];
    KMDWORD reserved01;
    KMDWORD reserved02;
    KMDWORD reserved03;
    KMDWORD reserved04;
    KMDWORD reserved05;
    KMDWORD reserved06;
    KMDWORD reserved07;
    KMVERTEXBUFMODEL nVbufModel;
} KMSYSTEMCONFIGSTRUCT, *PKMSYSTEMCONFIGSTRUCT;
KMSTATUS kmSetSystemConfiguration(PKMSYSTEMCONFIGSTRUCT pSystemConfigStruct);
KMSTATUS kmCreateFrameBufferSurface(PKMSURFACEDESC pSurfaceDesc, KMINT32 nWidth,
                                    KMINT32 nHeight, KMBOOLEAN fStripBuffer,
                                    KMBOOLEAN fBufferClear);
KMSTATUS kmActivateFrameBuffer(PKMSURFACEDESC pPrimarySurfaceDesc,
                               PKMSURFACEDESC pBackBufferSurfaceDesc,
                               KMBOOLEAN fStripBuffer, KMBOOLEAN fWaitVSync);
KMSTATUS kmCreateVertexBuffer(PKMVERTEXBUFFDESC pBufferDesc,
                              KMINT32 OpaquePolygonBuffer,
                              KMINT32 OpaqueModifierBuffer,
                              KMINT32 TransPolygonBuffer,
                              KMINT32 TransModifierBuffer);
KMSTATUS kmCreateTABuffer(PKMVERTEXBUFFDESC pBufferDesc, KMINT32 TABuffer);
KMSTATUS kmDiscardVertexBuffer(PKMVERTEXBUFFDESC pBufferDesc);
KMSTATUS kmChangeLatencyModel(KMLATENCYMODEL LatencyModel,
                              KMVERTEXBUFMODEL VbufModel);
KMSTATUS kmInitDevice(KMVIDEOMODE nVideoMode);
KMSTATUS kmSetDisplayMode(KMDISPLAYMODE nDisplayMode, KMBPPMODE nBpp,
                          KMBOOLEAN fDither, KMBOOLEAN fAntiAlias);
KMSTATUS kmStopDisplayFrameBuffer(void);
KMSTATUS kmAdjustDisplayCenter(long nXAdjust, long nYAdjust);
KMSTATUS kmSetWaitVsyncCount(KMINT32 nCount);
KMSTATUS kmSetBackGroundRenderState(PKMVERTEXCONTEXT pVertexContext);
KMSTATUS kmSetBackGroundPlane(PVOID pVertex[3], KMVERTEXTYPE VertexType,
                              KMINT32 StructSize);
KMSTATUS kmSetColorClampValue(KMPACKEDARGB MaxVal, KMPACKEDARGB MinVal);
KMSTATUS kmSetUserClipping(PKMVERTEXBUFFDESC pBufferDesc, KMINT32 ListType,
                           KMINT32 Xmin, KMINT32 Ymin, KMINT32 Xmax,
                           KMINT32 Ymax);
struct kmi_ta_layout {
    KMDWORD region_array;
    KMDWORD object_list;
    KMDWORD isp_params;
    KMDWORD tsp_params;
};
struct kmi_version_info {
    KMDWORD major, minor, revision, build;
    char *copyright;
};
struct kmi_callback {
    PKMCALLBACKFUNC function;
    void *argument;
};
struct kmi_ta_bank {
    KMDWORD start;
    KMDWORD region_base;
    KMDWORD unk_08;
    KMDWORD ol_base;
    KMDWORD ol_limit;
    KMDWORD next_opb_init;
    KMDWORD isp_base;
    KMDWORD isp_limit;
};
enum {
    SLOT_OVERFLOW = -3,
    SLOT_FREE = -1,
    SLOT_FILLING,
    SLOT_READY,
    SLOT_IN_TA,
    SLOT_TA_DONE,
    SLOT_RENDERING,
    SLOT_RENDERED,
    SLOT_SHOWN = 7
};
enum {
    END_RENDER_CALLBACK,
    VSYNC_CALLBACK,
    HSYNC_CALLBACK,
    TEXTURE_OVERFLOW_CALLBACK,
    STRIP_OVERRUN_CALLBACK,
    END_VERTEX_CALLBACK,
    END_YUV_CALLBACK,
    WAIT_VSYNC_CALLBACK,
    FATAL_ERROR_CALLBACK,
    CALLBACKS
};
struct kmi_device_extension {
    struct kmi_version_info *version;
    KMDWORD core;
    KMDWORD capabilities;
    unsigned char unk_00c[8];
    KMDWORD memory_alignment;
    KMDWORD texture_memory_size;
    KMDWORD unk_01c;
    KMINT32 video_mode;
    KMINT32 display_mode;
    KMINT32 bpp;
    KMBOOLEAN dither;
    KMBOOLEAN anti_alias;
    KMBOOLEAN strip_buffer;
    KMINT32 level_adjust;
    KMINT32 skip_lines;
    KMDWORD fb_width;
    KMDWORD fb_lines;
    KMDWORD display_width;
    KMDWORD display_height;
    KMINT32 offset_x;
    KMINT32 offset_y;
    KMINT32 origin_x;
    KMINT32 origin_y1;
    KMINT32 origin_y2;
    KMDWORD polling_ta;
    KMDWORD ta_options;
    struct kmi_ta_layout ta_layout[2];
    KMDWORD bank_limit[2];
    KMDWORD isp_size;
    KMDWORD tsp_size;
    KMINT32 palette_mode;
    KMINT32 alpha_threshold;
    KMDWORD background_packet[62];
    KMDWORD background_size;
    KMDWORD background_isp;
    KMDWORD background_tsp;
    KMDWORD background_texture;
    KMDWORD background_skip;
    KMDWORD background_depth;
    KMDWORD background_tag;
    KMDWORD background_base_color;
    KMDWORD background_offset_color;
    KMINT32 regions_stale;
    KMBOOLEAN presort;
    KMBOOLEAN global_clip;
    KMDWORD global_clip_width;
    KMDWORD global_clip_height;
    KMBOOLEAN another_modifier;
    KMINT32 another_modifier_list;
    KMDWORD strip_length;
    KMINT32 vsync_remaining;
    KMINT32 vsync_wait;
    KMBOOLEAN wait_vsync;
    KMDWORD unk_1ec;
    unsigned char unk_1f0[0x18];
    KMDWORD render_busy;
    KMDWORD ta_busy;
    unsigned char unk_210[8];
    KMINT32 field_offset[2];
    unsigned char unk_220[4];
    KMDWORD render_timeout;
    KMDWORD vertex_timeout;
    KMDWORD vsync_timeout;
    struct kmi_callback callback[CALLBACKS];
    unsigned char unk_278[4];
    KMDWORD stack_pointer;
    unsigned char unk_280[0x20];
    KMBOOLEAN display_changed;
    KMDWORD unk_2a4;
    KMDWORD callback_pending;
    KMDWORD fb_clip_x;
    KMDWORD fb_clip_y;
    KMDWORD unk_2b4;
    KMDWORD fb_read_size;
    KMDWORD fb_write_stride;
    KMDWORD fb_read_control;
    KMDWORD fb_write_control;
    KMDWORD fb_read_start1;
    KMDWORD fb_read_start2;
    unsigned char unk_2d0[8];
    KMDWORD sync_control;
    KMDWORD hblank_interrupt;
    KMDWORD vblank_interrupt;
    KMDWORD hblank;
    KMDWORD sync_load;
    KMDWORD vblank;
    KMDWORD sync_width;
    KMDWORD y_coefficients;
    KMDWORD scaler_control;
    KMDWORD video_control;
    KMDWORD video_start_x;
    KMDWORD video_start_y;
    unsigned char unk_308[4];
    KMDWORD feed_config;
    KMDWORD picture_end;
    KMDWORD picture_start;
    KMDWORD picture_lines;
    unsigned char unk_31c[0x10];
    KMDWORD fb_start[2];
    KMDWORD unk_334[2];
    KMDWORD latency_model;
    unsigned char unk_340[4];
    KMINT32 slot_state[4];
    KMINT32 write_slot;
    KMINT32 render_slot;
    KMINT32 ta_slot;
    KMDWORD lists_sent;
    KMDWORD lists_done;
    KMDWORD vsync_count;
    KMINT32 flip_pending;
    KMDWORD texture_render;
    KMDWORD slots_held;
    union {
        PKMDWORD row[5][4];
        PKMDWORD word[20];
    } list_start;
    KMDWORD list_size[5][4];
    KMDWORD vertex_buffer_model;
    KMDWORD vertex_buffer_list;
    KMDWORD flush_dma;
    KMINT32 frame_dma;
    KMINT32 frame_dma_wait;
    KMBOOLEAN common_modifier;
    PKMDWORD common_modifier_data;
    KMDWORD common_modifier_size;
    KMDWORD vertex_base;
    KMDWORD vertex_size;
    KMDWORD unk_440;
    KMDWORD isp_bytes;
    KMDWORD unk_448;
    KMDWORD unk_44c;
    KMDWORD ta_buffer_size;
    KMDWORD tiles_x;
    KMDWORD tiles_y;
    KMDWORD dummy_translucent;
    KMDWORD lists_used;
    struct kmi_ta_bank ta_bank[2];
    KMDWORD opb_downward;
    KMDWORD opaque_opb;
    KMDWORD opaque_modifier_opb;
    KMDWORD translucent_opb;
    KMDWORD translucent_modifier_opb;
    KMDWORD punchthrough_opb;
    KMDWORD list_limit[5];
};
extern volatile struct kmi_device_extension kmiDeviceExtension;
extern volatile struct kmi_device_extension *volatile kmiHardwareResource;
void kmiInitCallback(void);
void kmiRegisterCallback(volatile struct kmi_device_extension *device,
                         KMINT32 slot, PKMCALLBACKFUNC callback,
                         void *argument);
KMINT32 kmiEnableVSyncInterrupt(KMBOOLEAN enable);
KMINT32 kmiEnableHSyncInterrupt(KMBOOLEAN enable);
KMINT32 kmiWriteRegister(KMDWORD reg, KMDWORD value);
KMDWORD kmiReadRegister(KMDWORD reg);
void kmiMemCopy4(void *dst, void *src, KMDWORD size);
KMINT32 kmiCopyToPVRMemory(void *dst, void *src, KMDWORD size);
KMINT32 kmiCopyFromPVRMemory(void *dst, void *src, KMDWORD size);
KMINT32 kmiCopyToFrameBuffer(KMDWORD offset, KMDWORD *src, KMDWORD size);
KMINT32 kmiCopyFromFrameBuffer(KMDWORD *dst, KMDWORD offset, KMDWORD size);
KMINT32 kmiGetProfileInt(const char *section, const char *key,
                         KMINT32 fallback);
void kmiResetBoard(void);
void kmiDiscardRenderPipeline(void);
void kmiInitializeDMA(void);
KMSTATUS kmiDMAtoTARequest(KMDWORD target, const KMDWORD *source,
                           KMDWORD length, KMDWORD flags, KMDWORD **handle);
KMBOOLEAN kmiQueryFinishDMA(KMDWORD handle);
KMBOOLEAN kmiWaitForFinishDMA(KMDWORD handle);
KMINT32 kmiDMAHazardReset(void);
KMBOOLEAN kmiExecuteDMAChain(void);
void kmiInitPAL(void);
void kmiInitNTSC(void);
void kmiInitVGA(void);
KMINT32 kmiFBControl(KMINT32 width, KMINT32 height, KMBPPMODE bpp,
                     KMINT32 interlace, KMBOOLEAN dither, KMBOOLEAN anti_alias);
extern KMSTATUS (*kmiBackGroundPlaneFuncs[18])(void *pVertex[3]);
KMDWORD kmiAddSysConfigFlag(KMDWORD flag);
KMDWORD kmiSetSysConfigFlag(KMDWORD flag);
KMDWORD kmiGetSysConfigFlag(void);
struct kmi_frame_request {
    PKMSURFACEDESC surface;
    KMINT32 width;
    KMINT32 height;
    KMBOOLEAN clear;
};
struct kmi_system_config {
    PKMVERTEXBUFFDESC buffer;
    KMDWORD opaque;
    KMDWORD opaque_modifier;
    KMDWORD translucent;
    KMDWORD translucent_modifier;
    KMDWORD punchthrough;
    KMBOOLEAN strip_buffer;
    struct kmi_frame_request request[2];
    PKMSURFACEDESC front;
    PKMSURFACEDESC back;
    KMBOOLEAN wait_vsync;
    KMINT32 width;
    KMINT32 height;
    KMINT32 bytes_per_pixel;
    KMINT32 buffer_mode;
    KMDWORD ta_buffer_size;
    KMDWORD texture_size;
    KMDWORD frame_buffer_size;
    KMDWORD region_opb_size;
};
extern struct kmi_system_config kmiSystemConfig;
KMSTATUS kmiAllocSysConfig(KMDWORD buffer_mode);
void kmiGetDisplayData(KMDWORD bpp, KMDWORD strip_buffer, KMDWORD height);
KMSTATUS kmiFBalloc(KMINT32 size, KMSURFACEDESC *surface);
KMSTATUS kmiTXalloc(KMINT32 size, KMSURFACEDESC *surface);
KMSTATUS kmiABSalloc(KMINT32 size, KMSURFACEDESC *surface);
KMSTATUS kmiVQalloc(KMSURFACEDESC *surface);
KMSTATUS kmiFBfree(KMINT32 offset);
KMSTATUS kmiVQFBfree(KMSURFACEDESC *surface);
KMSTATUS kmiFBgetfreemem(KMINT32 *bank0, KMINT32 *bank1, KMINT32 *vq,
                         KMINT32 *largest);
KMSTATUS kmiFBSortQueue(void);
KMSTATUS kmiFBGarbageCollect(void);
void kmiPurgeCache(void *addr);
void kmiDefaultInterruptHandler(KMINT32 event);
void kmiExCallBackFunc(PKMCALLBACKFUNC function, void *argument);
void kmiRegisterPhIntHandler(KMINT32 (*handler)(void));
void kmiCreateRegionArray(KMDWORD width, KMDWORD height, KMDWORD index,
                          KMINT32 unused, KMINT32 bank, KMDWORD order);
struct kmi_interrupt_statistics {
    KMDWORD render_wait;
    KMDWORD ta_wait;
    KMDWORD render_timeouts;
    KMDWORD ta_timeouts;
    KMDWORD ol_overflow_wait;
    KMDWORD isp_overflow_wait;
    KMDWORD hold_wait;
    KMDWORD ol_overflows;
    KMDWORD isp_overflows;
    KMDWORD isp_current[2];
    KMDWORD list_max[5];
    KMDWORD render_start;
    KMDWORD render_time;
    KMDWORD ta_start;
    KMDWORD ta_time;
};
extern struct kmi_version_info kmiVersionInfo;
KMSTATUS kmiInitTimer(void);
void kmiInitializeDriver(void);
void kmiReleaseHardware(void);
void kmiFatalErrorEntry(KMDWORD code);
void kmiWaitAccurate(KMFLOAT seconds);
KMINT32 kmiVerifyWriteRegister(KMDWORD reg, KMDWORD data);
void kmiInitRenderer(void);
KMINT32 kmiInitializeDevice(void);
void kmiInitializeFog(void);
void kmiUnloadDevice(void);
void kmiInitInterrupt(void);
KMINT32 kmiInterruptHandlerSH(void);
void kmiModuleInitialize(void);
KMSTATUS kmiInitializeBackGroundPlane(void);
KMSTATUS kmiFBinit(void);
void kmiInitializeTA(void);
void kmiResetTA(void);
void kmiInitializeHardware(void);
void kmiSetTAEnvironment(KMDWORD region_array, KMDWORD object_list,
                         KMDWORD isp_params, KMDWORD tsp_params,
                         KMDWORD options, KMDWORD unk);
struct kmi_global_parameter {
    KMDWORD control;
    KMDWORD isp;
    KMDWORD tsp;
    KMDWORD texture;
    KMDWORD data[12];
};
extern struct kmi_global_parameter kmiGlobalWork;
extern KMCURRENTLISTSTATE kmiCurrentListState;
extern PKMDWORD *kmiVertexBuff;
extern PKMDWORD *kmiCurrentVertexBuff;
extern PKMDWORD *kmiDstVertexBuffer;
extern PKMDWORD *kmi_banks[2];
extern PKMDWORD kmi_list_bases[2][5];
extern PKMDWORD kmi_write_pointers[5];
extern PKMDWORD kmi_list_starts[5];
extern KMDWORD kmiCurrentListType;
struct list_header {
    KMDWORD control;
    KMDWORD isp;
    KMDWORD tsp;
    KMDWORD texture;
    KMDWORD data[4];
};
struct dummy_polygon {
    struct list_header header;
    KMVERTEX1 vertex[3];
};
void kmiFlipVertexBuffer(KMDWORD bank);
KMDWORD kmiConvertUVnum(KMDWORD size);
void kmiCreateGlobalParameter(void);
PKMDWORD *kmiPutGlobalParam(void);
typedef unsigned char Uint8;
typedef signed char Sint8;
typedef unsigned short Uint16;
typedef short Sint16;
typedef unsigned long Uint32;
typedef long Sint32;
typedef int Int;
typedef float Float;
enum bool { false, true };
typedef enum bool Bool;
typedef Sint32 Angle;
typedef Float NJS_MATRIX[16];
typedef struct {
    Float x, y;
} NJS_POINT2;
typedef struct {
    Float x, y, z;
} NJS_POINT3, NJS_VECTOR;
typedef struct {
    Float a, r, g, b;
} NJS_ARGB;
typedef Float NJS_FOG_TABLE[128];
typedef struct {
    Sint16 u, v;
} NJS_TEX;
typedef struct {
    Uint8 b, g, r, a;
} NJS_BGRA;
typedef union {
    Uint32 color;
    NJS_TEX tex;
    NJS_BGRA argb;
} NJS_COLOR;
typedef struct {
    NJS_COLOR diffuse;
    NJS_COLOR specular;
    Float exponent;
    Uint32 attr_texId;
    Uint32 attrflags;
} NJS_MATERIAL;
typedef struct {
    Uint16 type_matId;
    Uint16 nbMesh;
    Sint16 *meshes;
    Uint32 *attrs;
    NJS_VECTOR *normals;
    NJS_COLOR *vertcolor;
    NJS_COLOR *vertuv;
} NJS_MESHSET;
typedef struct {
    NJS_POINT3 *points;
    NJS_VECTOR *normals;
    Sint32 nbPoint;
    NJS_MESHSET *meshsets;
    NJS_MATERIAL *mats;
    Uint16 nbMeshset;
    Uint16 nbMat;
    NJS_POINT3 center;
    Float r;
} NJS_MODEL;
typedef struct obj {
    Uint32 evalflags;
    NJS_MODEL *model;
    Float pos[3];
    Angle ang[3];
    Float scl[3];
    struct obj *child;
    struct obj *sibling;
} NJS_OBJECT;
typedef struct {
    void *mdata;
    Uint32 nbFrame;
    Uint16 type;
    Uint16 inp_fn;
} NJS_MOTION;
typedef struct {
    Uint32 keyframe;
    Float key[3];
} NJS_MKEY_F;
typedef struct {
    Uint32 keyframe;
    Angle key[3];
} NJS_MKEY_A;
typedef struct {
    Uint32 keyframe;
    void *key;
} NJS_MKEY_P;
typedef struct {
    void *p[1];
    Uint32 nb[1];
} NJS_MDATA1;
typedef struct {
    void *p[2];
    Uint32 nb[2];
} NJS_MDATA2;
typedef struct {
    void *p[3];
    Uint32 nb[3];
} NJS_MDATA3;
typedef struct {
    void *p[4];
    Uint32 nb[4];
} NJS_MDATA4;
typedef struct {
    NJS_OBJECT *object;
    NJS_MOTION *motion;
} NJS_ACTION;
typedef struct {
    NJS_MOTION *motion[2];
    Float frame[2];
} NJS_MOTION_LINK;
typedef struct {
    NJS_OBJECT *object;
    NJS_MOTION_LINK *motionlink;
} NJS_ACTION_LINK;
typedef struct {
    Float *pos;
    Angle *ang;
    Float *scl;
} NJS_MOTION_DATA;
typedef struct {
    void *filename;
    Uint32 attr;
    Uint32 texaddr;
} NJS_TEXNAME;
typedef struct {
    NJS_TEXNAME *textures;
    Uint32 nbTexture;
} NJS_TEXLIST;
typedef struct {
    Uint32 Type;
    Uint32 BitDepth;
    Uint32 PixelFormat;
    Uint32 nWidth;
    Uint32 nHeight;
    Uint32 TextureSize;
    Uint32 fSurfaceFlags;
    Uint32 *pSurface;
    Uint32 *pVirtual;
    Uint32 *pPhysical;
} NJS_TEXSURFACE;
typedef struct {
    void *texaddr;
    NJS_TEXSURFACE texsurface;
} NJS_TEXINFO;
typedef struct {
    Uint32 globalIndex;
    Uint32 bank;
    Uint32 tspparambuffer;
    Uint32 texparambuffer;
    Uint32 texaddr;
    NJS_TEXINFO texinfo;
    Uint16 count;
    Uint16 dummy;
} NJS_TEXMEMLIST;
typedef struct {
    void *palette;
    Uint16 mode;
    Sint16 bank;
    Sint16 offset;
    Sint16 count;
} NJS_TEXPALETTE;
typedef struct {
    Uint32 n;
    Uint32 globalIndex;
    Sint32 texerr;
    Sint32 gdstat;
    Sint32 gderr;
    Sint32 reserved0;
    Sint32 reserved1;
    Sint32 reserved2;
} NJS_TEXERRSTAT;
typedef struct {
    Sint16 sx, sy;
    Sint16 cx, cy;
    Sint16 u1, v1;
    Sint16 u2, v2;
    Sint16 texid;
    Sint16 attr;
} NJS_TEXANIM;
typedef struct {
    NJS_POINT3 p;
    Float sx, sy;
    Angle ang;
    NJS_TEXLIST *tlist;
    NJS_TEXANIM *tanim;
} NJS_SPRITE;
typedef struct {
    NJS_POINT2 *p;
    NJS_COLOR *col;
    NJS_COLOR *tex;
    Uint32 num;
} NJS_POINT2COL;
typedef struct {
    NJS_POINT3 *p;
    NJS_COLOR *col;
    NJS_COLOR *tex;
    Uint32 num;
} NJS_POINT3COL;
typedef struct {
    Float x, y, z;
    Uint32 col;
} NJS_POLYGON_VTX;
typedef struct {
    Float x, y, z;
    Float u, v;
    Uint32 col;
} NJS_TEXTURE_VTX;
typedef struct {
    Float px, py, pz;
    Float vx, vy, vz;
} NJS_LINE, NJS_PLANE;
typedef struct {
    NJS_POINT3 c;
    Float r;
} NJS_SPHERE;
typedef struct {
    int keys;
    int *iparam;
    float *fparam;
} NJS_SPLINE;
typedef struct {
    Float dist;
    Float w, h;
    Float cx, cy;
} NJS_SCREEN;
typedef struct {
    NJS_MATRIX m;
    Float px, py, pz;
    Float vx, vy, vz;
    Angle roll;
    Float apx, apy, apz;
    Float avx, avy, avz;
    Angle aroll;
} NJS_VIEW;
typedef struct {
    Float ratten, ipd;
    Float nrr, frr, cosi, cose, idev, odev;
    Float rate, intns;
    Int exp;
    Int reserve;
    NJS_POINT3 lpnt;
    NJS_VECTOR lvctr;
    NJS_VECTOR lmvctr;
    NJS_ARGB atten, amb, dif, spc;
    NJS_ARGB mamb, mdif, mspc;
} NJS_LIGHT_CAL;
typedef struct {
    Int lsrc;
    Float iamb, idif, ispc;
    Float nrang, frang;
    void *func;
    Angle iang, oang;
    NJS_ARGB argb;
} NJS_LIGHT_ATTR;
typedef struct {
    NJS_MATRIX mtrx;
    NJS_POINT3 pnt;
    NJS_VECTOR vctr;
    Int stat;
    Int reserve;
    NJS_LIGHT_CAL ltcal;
    NJS_LIGHT_ATTR attr;
} NJS_LIGHT;
typedef struct {
    NJS_ARGB ambient;
    NJS_ARGB diffuse;
    NJS_ARGB specular;
    Float exponent;
} NJS_LIGHT_MATERIAL;
typedef struct {
    Float px, py, pz;
    Float vx, vy, vz;
    Angle roll;
    Angle ang;
    Float n_clip;
    Float f_clip;
    NJS_VECTOR lx, ly;
} NJS_CAMERA;
typedef struct {
    NJS_CAMERA *camera;
    NJS_MOTION *motion;
} NJS_CACTION;
typedef struct NJS_VERTEX_BUF NJS_VERTEX_BUF;
struct nj_motion_info {
    void *mdata;
    void **p;
    Uint32 *nb;
    Float frame;
    Uint32 nbFrame;
    Uint32 factor;
    NJS_MATRIX *m;
};
struct nj_motlink_data_info {
    void *mdata;
    void **p;
    Uint32 *nb;
    Float frame;
    Uint32 nbFrame;
    Uint32 factor;
    Uint32 unk_18;
};
void njCreateLight(NJS_LIGHT *l, Int type);
void njDeleteLight(NJS_LIGHT *l);
void njSetLightDirection(NJS_LIGHT *l, Float x, Float y, Float z);
void njSetLightColor(NJS_LIGHT *l, Float r, Float g, Float b);
void njSetLightIntensity(NJS_LIGHT *l, Float spc, Float dif, Float amb);
void njSetLightAlpha(NJS_LIGHT *l, Float a);
void njSetLightAngle(NJS_LIGHT *l, Angle iang, Angle oang);
void njSetLightRange(NJS_LIGHT *l, Float nrang, Float frang);
void njSetLightLocation(NJS_LIGHT *l, Float x, Float y, Float z);
void njLightOn(NJS_LIGHT *l);
void njLightOff(NJS_LIGHT *l);
void njUnitLightMatrix(NJS_LIGHT *l);
void njTranslateLight(NJS_LIGHT *l, Float x, Float y, Float z);
void njTranslateLightV(NJS_LIGHT *l, NJS_VECTOR *v);
void njRotateLightX(NJS_LIGHT *l, Angle ang);
void njRotateLightY(NJS_LIGHT *l, Angle ang);
void njCalculateLightsRGB(NJS_ARGB *color, NJS_POINT3 *point,
                          NJS_VECTOR *normal, Int reverse);
void njCalculateLightsRGBVertex(NJS_ARGB *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal, Int reverse);
void njCalculateLightsRGBPacked(Uint32 *color, NJS_POINT3 *point,
                                NJS_VECTOR *normal, Int reverse);
void njCalculateLightsRGBPackedVertex(Uint32 *color, NJS_POINT3 *point,
                                      NJS_VECTOR *normal, Int reverse);
void njCheckLightMaterials(Int flags);
void njSetQueue(void);
void njSetLightMaterials(void);
void njCalcLightMatrices(void);
void njDrawModelSub(NJS_MODEL *volatile model);
void njResetQueue(void);
void njCalcLightMaterials(void);
void njGetLightDistance(NJS_POINT3 *point);
void njSetEasyLight(Float x, Float y, Float z);
void njSetEasyLightIntensity(Float inten, Float ambient);
void njSetEasyLightColor(Float r, Float g, Float b);
void njInitSystem(Int mode, Int frame, Int count);
void njChangeSystem(Int mode, Int frame, Int count);
void njExitSystem(void);
typedef Sint8 NJS_SYS_ATTR[192];
void njInit3D(NJS_VERTEX_BUF *vbuf, Int vn);
void njControl3D(Uint32 flag);
void njSetConstantAttr(Uint32 and_attr, Uint32 or_attr);
void njSetConstantMaterial(NJS_ARGB *mat);
void njSetDepthQueue(Float dnear, Float dfar);
void njInitMatrix(NJS_MATRIX *m, Sint32 n, Int flag);
void njInitShape(Float *buf);
extern Uint8 _nj_debug_char_[];
void njInitPrint(Uint32 *texture, Uint32 size, Uint32 attr);
void njExitPrint(void);
void njPrintSize(Uint16 size);
void njPrintColor(Uint32 c);
void njPrintC(Int loc, const char *s);
void njPrintD(Int loc, Int val, Int digit);
void njPrintB(Int loc, Uint32 val, Int digit);
void njPrintH(Int loc, Uint32 val, Int digit);
void njPrintF(Int loc, Float val, Int digit);
void njPrint(Int loc, const char *fmt, ...);
void njInitView(NJS_VIEW *v);
void njSetView(NJS_VIEW *v);
void njSetCamera(NJS_CAMERA *c);
void njPointCameraInterest(NJS_CAMERA *c, Float x, Float y, Float z);
void njRollCameraInterest(NJS_CAMERA *c, Angle ang);
void njSetCameraAngle(NJS_CAMERA *c, Angle ang);
void njRotateViewXRelative(NJS_VIEW *v, Angle ang);
void njRotateViewYRelative(NJS_VIEW *v, Angle ang);
void njRotateViewZRelative(NJS_VIEW *v, Angle ang);
void njTranslateViewRelative(NJS_VIEW *v, Float x, Float y, Float z);
void njRotateViewXAbsolute(NJS_VIEW *v, Angle ang);
void njRotateViewYAbsolute(NJS_VIEW *v, Angle ang);
void njRotateViewZAbsolute(NJS_VIEW *v, Angle ang);
void njTranslateViewAbsolute(NJS_VIEW *v, Float x, Float y, Float z);
void njSetScreen(NJS_SCREEN *s);
void njSetPerspective(Angle ang);
void njClipZ(Float n, Float f);
void njUserClipping(Int mode, NJS_POINT2 *p);
void njClearMatrix();
Bool njPushMatrix(NJS_MATRIX *m);
Bool njPopMatrix(Uint32 n);
void njUnitMatrix(NJS_MATRIX *m);
void njSetMatrix(NJS_MATRIX *md, NJS_MATRIX *ms);
void njGetMatrix(NJS_MATRIX *m);
void njMultiMatrix(NJS_MATRIX *md, NJS_MATRIX *ms);
void njTranslate(NJS_MATRIX *m, Float x, Float y, Float z);
void njTranslateV(NJS_MATRIX *m, NJS_VECTOR *v);
void njRotate(NJS_MATRIX *m, NJS_VECTOR *v, Angle ang);
void njRotateX(NJS_MATRIX *m, Angle ang);
void njRotateY(NJS_MATRIX *m, Angle ang);
void njRotateZ(NJS_MATRIX *m, Angle ang);
void njRotateXYZ(NJS_MATRIX *m, Angle angx, Angle angy, Angle angz);
void njRotateZXY(NJS_MATRIX *m, Angle angx, Angle angy, Angle angz);
Bool njInvertMatrix(NJS_MATRIX *m);
Float njDetMatrix(NJS_MATRIX *m);
void njScale(NJS_MATRIX *m, Float sx, Float sy, Float sz);
void njScaleV(NJS_MATRIX *m, NJS_VECTOR *v);
void njMirror(NJS_MATRIX *m, NJS_PLANE *pl);
void njAddVector(NJS_VECTOR *vd, NJS_VECTOR *vs);
void njSubVector(NJS_VECTOR *vd, NJS_VECTOR *vs);
void njCalcPoint(NJS_MATRIX *m, NJS_POINT3 *ps, NJS_POINT3 *pd);
void njCalcVector(NJS_MATRIX *m, NJS_VECTOR *vs, NJS_VECTOR *vd);
void njGetTranslation(NJS_MATRIX *m, NJS_POINT3 *p);
void njProjectScreen(NJS_MATRIX *m, NJS_POINT3 *p3, NJS_POINT2 *p2);
Float njScalor(NJS_VECTOR *v);
Float njScalor2(NJS_VECTOR *v);
Float njSin(Angle n);
Float njSqrt(Float n);
Float njInvertSqrt(Float n);
Float njCos(Angle n);
Float njTan(Angle n);
void njLinear(Float *idata, Float *odata, NJS_SPLINE *attr, Float frame);
Float njUnitVector(NJS_VECTOR *v);
Float njInnerProduct(NJS_VECTOR *v1, NJS_VECTOR *v2);
Float njOuterProduct(NJS_VECTOR *v1, NJS_VECTOR *v2, NJS_VECTOR *ov);
void njGetPlaneNormal2(NJS_POINT3 *p0, NJS_POINT3 *p1, NJS_POINT3 *p2,
                       NJS_VECTOR *v);
Float njDistanceP2P(NJS_POINT3 *p1, NJS_POINT3 *p2);
Float njDistanceP2L(NJS_POINT3 *p, NJS_LINE *l, NJS_POINT3 *cp);
Float njDistanceP2PL(NJS_POINT3 *p, NJS_PLANE *pl, NJS_POINT3 *cp);
Float njDistanceL2PL(NJS_LINE *l, NJS_PLANE *pl, NJS_POINT3 *cp);
Float njDistancePL2PL(NJS_PLANE *pl1, NJS_PLANE *pl2, NJS_LINE *l);
Bool njIsParalellL2PL(NJS_LINE *l, NJS_PLANE *pl);
Bool njIsParalellPL2PL(NJS_PLANE *pl1, NJS_PLANE *pl2);
Float njFraction(Float n);
extern Float FracInt;
Float njRoundOff(Float n);
Int njCollisionCheckSS(NJS_SPHERE *sphere1, NJS_SPHERE *sphere2);
void njSetMotionCallback(void (*func)(NJS_OBJECT *obj));
void njSimpleDrawModel(NJS_MODEL *model);
void njSimpleDrawObject(NJS_OBJECT *obj);
Sint32 njSimpleCalcModel(NJS_MODEL *model);
void njSimpleDrawModelSub(NJS_MODEL *model);
void njSimpleDrawObjectSub(NJS_OBJECT *obj);
void njSimpleAction(NJS_ACTION *action, Float frame);
void njSimpleDrawMotion(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njSimpleDrawShapeMotion(NJS_OBJECT *obj, NJS_MOTION *motion,
                             NJS_MOTION *shape, Float frame);
void njSimpleActionOld(NJS_ACTION *action, Float frame);
void njSimpleDrawMotionOld(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njSimpleDrawShapeMotionOld(NJS_OBJECT *obj, NJS_MOTION *motion,
                                NJS_MOTION *shape, Float frame);
void njSimpleActionLink(NJS_ACTION_LINK *actionlink, Float rate);
void njSimpleDrawMotionLink(NJS_OBJECT *object, NJS_MOTION_LINK *motionlink,
                            Float rate);
void njSimpleDrawShapeMotionLink(NJS_OBJECT *object,
                                 NJS_MOTION_LINK *motionlink,
                                 NJS_MOTION_LINK *shapelink, Float rate);
void njSimpleActionLinkOld(NJS_ACTION_LINK *actionlink, Float rate);
void njSimpleDrawMotionLinkOld(NJS_OBJECT *object, NJS_MOTION_LINK *motionlink,
                               Float rate);
void njSimpleDrawShapeMotionLinkOld(NJS_OBJECT *object,
                                    NJS_MOTION_LINK *motionlink,
                                    NJS_MOTION_LINK *shapelink, Float rate);
void njGetkmPointer(void);
void njSetkmPointer(void);
void njSetEORflag();
void njSetkmColorMode(Uint32 mode);
void *njStartVertexNonTexOpaque(void);
void *njStartVertexNonTexTrans(void);
void *njStartVertexTexOpaque(void);
void *njStartVertexTexTrans(void);
void *njStartVertexNonTexOpaqueIntens(Uint32 *color);
void *njStartVertexNonTexTransIntens(Uint32 *color);
void *njStartVertexTexOpaqueIntens(Uint32 *color);
void *njStartVertexTexTransIntens(Uint32 *color);
void njEndVertex(Uint32 *vertex);
Sint32 njSetkmTextureNum(Uint32 n);
void njSetkmModelAttr(Uint32 attr);
void njDrawModel(NJS_MODEL *model);
void njDrawObject(NJS_OBJECT *obj);
void njDrawMotion(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njAction(NJS_ACTION *action, Float frame);
void njDrawShapeMotion(NJS_OBJECT *obj, NJS_MOTION *motion, NJS_MOTION *shape,
                       Float frame);
void njDrawMotionOld(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njActionOld(NJS_ACTION *action, Float frame);
void njDrawShapeMotionOld(NJS_OBJECT *obj, NJS_MOTION *motion,
                          NJS_MOTION *shape, Float frame);
void njEasyDrawModel(NJS_MODEL *model);
void njEasyDrawObject(NJS_OBJECT *obj);
void njEasyDrawMotion(NJS_OBJECT *obj, NJS_MOTION *motion, Float frame);
void njEasyAction(NJS_ACTION *action, Float frame);
void njEasyDrawShapeMotion(NJS_OBJECT *obj, NJS_MOTION *motion,
                           NJS_MOTION *shape, Float frame);
Int njFarClipping(NJS_POINT3COL *p, Int n);
Int njNearClipping(NJS_POINT3COL *in, Int n, NJS_POINT3COL *out, Uint32 attr);
Int njNearClippingLine(NJS_POINT3COL *in, NJS_POINT3COL *out, Uint32 attr);
void njtri_filled(Int n, NJS_POINT3COL *p, Float **vertex);
void njtri_filled_with_tex(Int n, NJS_POINT3COL *p, Float **vertex);
void njtri_wiredpoly(Int n, NJS_POINT3COL *p, Float **vertex);
void njtri_wiredpoly_with_tex(Int n, NJS_POINT3COL *p, Float **vertex);
void njGetDrawMotion(NJS_OBJECT *object, NJS_MOTION *motion,
                     NJS_MOTION_DATA *data, Float frame);
void njGetAction(NJS_ACTION *action, NJS_MOTION_DATA *data, Float frame);
void njCameraAction(NJS_CACTION *caction, Float frame);
void njCameraMotion(NJS_CAMERA *camera, NJS_MOTION *motion, Float frame);
void njCameraActionOld(NJS_CACTION *caction, Float frame);
void njCameraMotionOld(NJS_CAMERA *camera, NJS_MOTION *motion, Float frame);
void njDrawLine3D(NJS_POINT3COL *p, Int n, Uint32 attr);
void njDrawTriangle3D(NJS_POINT3COL *p, Int n, Uint32 attr);
void njDrawPolygon3D(NJS_POINT3COL *p, Int n, Uint32 attr);
void njDrawLine2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
void njDrawPolygon2D(NJS_POINT2COL *p, Int n, Float pri, Uint32 attr);
void njDrawSprite2D(NJS_SPRITE *sp, Int n, Float pri, Uint32 attr);
void njDrawSprite3D(NJS_SPRITE *sp, Int n, Uint32 attr);
void njDrawPolygon(NJS_POLYGON_VTX *polygon, Int count, Int trans);
void njDrawTexture(NJS_TEXTURE_VTX *polygon, Int count, Int tex, Int flag);
void njDrawTextureMemList(NJS_TEXTURE_VTX *polygon, Int count, Int tex,
                          Int flag);
void njFogEnable(void);
void njFogDisable(void);
void CHAOS_SetChaosNo(Uint32 c);
void njSetFogDensity(Uint32 density);
Uint32 njGenerateFogDensity(Float f);
void njGenerateFogTable(NJS_FOG_TABLE fog);
void njGenerateFogTable3(NJS_FOG_TABLE fog, Float n, Float f);
void kmSetFogTable(NJS_FOG_TABLE fog);
void njExecuteFade(Float f);
void njSetFadeColor(Uint32 c);
void njFadeEnable(void);
void njFadeDisable(void);
void njInitVertexBuffer(Sint32 op, Sint32 om, Sint32 tp, Sint32 tm, Sint32 pt);
void njSetVSyncFunction(void (*func)(void));
void njWaitVSync(void);
void njInitTextureBuffer(Sint8 *addr, Uint32 size);
void njInitTexture(NJS_TEXMEMLIST *addr, Uint32 n);
void njInitTextureGlobalIndex(Uint32 globalIndex);
void njExitTexture(void);
void njReleaseTextureAll(void);
void njGarbageTexture(NJS_TEXMEMLIST *addr, Uint32 n);
NJS_TEXERRSTAT *njGetTextureErrStat(void);
Uint32 njCalcTexture(Uint32 flag);
void njSetTexturePath(const char *path);
Sint32 njSetTexture(NJS_TEXLIST *texlist);
Sint32 njSetTextureNum(Uint32 n);
void njSetTextureMemorySize(Uint32 size);
Sint32 njLoadTexture(NJS_TEXLIST *texlist);
Sint32 njReleaseTexture(NJS_TEXLIST *texlist);
Sint32 njReleaseTextureNum(Uint32 n);
void njInitCacheTextureBuffer(Sint8 *addr, Uint32 size);
void njReleaseCacheTextureAll(void);
void njSetPvmTextureList(NJS_TEXLIST *texlist, NJS_TEXNAME *texname,
                         char *filename, Sint32 size);
Sint32 njLoadTexturePvmFile(const char *filename, NJS_TEXLIST *texlist);
Sint32 njLoadTexturePvmMemory(Uint8 *addr, NJS_TEXLIST *texlist);
void njSetTextureInfo(NJS_TEXINFO *info, Uint16 *tex, Sint32 type, Sint32 width,
                      Sint32 height);
void njSetTextureName(NJS_TEXNAME *texname, void *addr, Uint32 globalIndex,
                      Uint32 attr);
void *njCacheTextureMalloc(Uint32 size);
void njCacheTextureFree(void *addr);
Sint32 njSearchTexList(NJS_TEXMEMLIST *list, Uint32 n, Uint32 globalIndex);
void njFreeTexMemList(NJS_TEXMEMLIST *tex);
void njEntryTexMemList(Uint32 *handle, NJS_TEXINFO *info, Uint32 globalIndex,
                       Uint32 texaddr, Uint32 bank);
Sint32 njSearchTexList3(NJS_TEXMEMLIST *list, Uint32 n, Uint32 globalIndex,
                        Uint32 bank);
void njSetFlagAddrAllTexture(Uint32 globalIndex, Uint32 flag, void *addr);
NJS_TEXINFO *njTexMemList(Uint32 globalIndex);
Sint32 njCheckPaletteType(Uint32 type);
void njInitTextureErrStat(void);
Sint32 njTexFopen(const char *filename);
void njTexFclose(void);
Sint32 njTexFread(void *buf, Uint32 size);
void njTexFseek(Sint32 offset, Sint32 type);
Sint32 njCreateTextureSurface(NJS_TEXSURFACE *surface, Sint32 width,
                              Sint32 height, Sint32 type);
Sint32 njSetTexInfo(Sint32 *type, Sint32 width, Sint32 height, Sint32 bit,
                    Sint32 cn);
Sint32 njLoadTexMemFromFile(NJS_TEXNAME *texname, NJS_TEXINFO *info);
Sint32 njLoadCacheFromFile(NJS_TEXNAME *texname, NJS_TEXINFO *info);
Sint32 njLoadTexMemFromMemory(NJS_TEXNAME *texname, NJS_TEXINFO *info);
Sint32 njLoadTexMemFromCache(NJS_TEXNAME *texname, NJS_TEXINFO *info);
Sint32 njGetInfoMemory(NJS_TEXINFO *info);
Sint32 njGetSurfacePvr(NJS_TEXINFO *info, Uint32 attr, Sint32 *size);
Sint32 njGetInfoPvr(NJS_TEXINFO *info, Uint32 attr, Sint32 *size);
Sint32 njTexDownloadMipMap(void *tex, NJS_TEXINFO *info);
Sint32 njTexDownloadCache(void *tex, NJS_TEXINFO *info);
Sint32 njCheckFileName(char *path, char *name);
Sint32 njGetFileGlobalIndex(NJS_TEXNAME *texname);
Sint32 njGetFileTexType(void);
extern char fileext[][5];
extern Sint8 _nj_file_buffer[2048];
extern Sint8 *_nj_texture_buffer_st;
extern Uint32 _nj_texture_buffer_max_size;
Sint32 njLoadTextureLN(NJS_TEXLIST *texlist, Uint32 n);
Sint32 njReleaseTextureLN(Uint32 texaddr);
void njSetTextureParam(NJS_TEXMEMLIST *tex);
void njInitTexMemList(NJS_TEXMEMLIST *addr, Uint32 n);
void njSetPaletteBankLN(NJS_TEXMEMLIST *tex, Sint32 bank);
void njSetPaletteBank(Uint32 bank);
void strupr(char *s);
void njSetPaletteBankNum(Uint32 n, Sint32 bank);
void njSetPaletteBankNumG(Uint32 globalIndex, Sint32 bank);
void njSetPaletteMode(Uint32 mode);
Uint32 njGetPaletteMode(void);
void njSetPaletteData(Sint32 offset, Sint32 count, void *data);
void njGetPaletteData(Sint32 offset, Sint32 count, void *data);
Sint32 njLoadPaletteFile(const char *filename, NJS_TEXPALETTE *pl);
void njSetBackColor(Uint32 col1, Uint32 col2, Uint32 col3);
void njSetBorderColor(Uint32 color);
void njRenderTextureNum(Uint32 n);
void njRenderTextureNumG(Uint32 globalIndex);
void njSetRenderWidth(Uint32 nWidth);
void njFrameBufferBmp(char *bmp, char *buffer);
void njTextureFilterMode(Int mode);
void njTextureClampMode(Int mode);
void njTextureFlipMode(Int mode);
void njColorBlendingMode(Int target, Int mode);
void njSuperSampleMode(Int mode);
void njPolygonCullingMode(Int mode);
void njPolygonCullingSize(Float size);
void njMemCopy(void *dst, const void *src, Sint32 num);
void njMemCopy2(void *dst, const void *src, Sint32 num);
void njMemCopy4(void *dst, const void *src, Sint32 num);
extern NJS_MATRIX _unit_matrix_;
extern Float _nj_far_clip_;
extern NJS_MATRIX *_nj_current_matrix_ptr_;
extern NJS_MATRIX _nj_view_matrix_;
extern NJS_SCREEN _nj_screen_;
extern Int _nj_frame_mode_;
extern Int _nj_frame_size_w;
extern Int _nj_frame_size_h;
extern Float _nj_near_clip_;
extern Float _nj_scr_aspect_x_;
extern Float _nj_scr_aspect_y_;
extern Uint32 _nj_control_3d_flag_;
extern NJS_VERTEX_BUF *_nj_vertex_buf_;
extern Int _nj_vertex_num_;
extern Int _nj_calc_vertex_;
extern Int _nj_calc_polygon_;
extern Int _nj_draw_polygon_;
extern Uint32 _nj_constant_attr_and_;
extern Uint32 _nj_constant_attr_or_;
extern NJS_ARGB _nj_constant_material_;
extern Uint32 _nj_vsync_count_;
extern Float _nj_depth_near_;
extern Float _nj_depth_far_;
extern Float _nj_depth_range_;
extern Int _nj_depth_enable_;
extern Int _nj_matrix_flag_;
extern NJS_TEXLIST *_nj_current_texlist;
extern NJS_TEXMEMLIST *_nj_texmemlist;
extern Uint32 _nj_texmemsize;
extern Sint32 _nj_tex_count;
extern Uint32 _nj_current_texture;
extern Uint32 _nj_current_texture_bank;
extern char _nj_current_texture_path[256];
extern Uint32 _nj_tex_max_free_size;
extern Uint32 _nj_user_globalIndex;
extern NJS_TEXERRSTAT _nj_texerr_;
extern NJS_TEXSURFACE _nj_tex_err_surface;
extern struct tagKMVERTEXCONTEXT *_nj_current_ctx_;
extern NJS_LIGHT_MATERIAL _nj_light_material_;
extern struct nj_light_control {
    NJS_LIGHT *light[32];
    Int count;
} _nj_light_control_;
extern struct nj_light_queue {
    Int light[32];
    Int count;
} _nj_light_queue_;
void njLightSystemInit(void);
extern Uint32 _nj_wait_vsync_in_;
extern Uint32 _nj_wait_vsync_out_;
extern volatile Int _nj_eor_flag_;
extern Int _nj_display_mode_;
extern Int _nj_waitvsync_count;
extern NJS_POINT2 _nj_2d_clip_[2];
extern Uint32 _nj_vertex_buffer_op_;
extern Uint32 _nj_vertex_buffer_om_;
extern Uint32 _nj_vertex_buffer_tp_;
extern Uint32 _nj_vertex_buffer_tm_;
extern Uint32 _nj_vertex_buffer_pt_;
extern Uint32 _nj_vertex_buffer_size_;
extern Uint32 _nj_texture_memory_size;
extern Uint32 *_nj_usr_vertex_buffer_ptr_;
extern Uint32 _nj_usr_vertex_buffer_size_;
extern volatile Int _nj_render_flag_;
extern volatile Int _nj_eov_flag_;
extern volatile Int _nj_fatal_err_callback_;
extern void (*_nj_eor_function_)(void);
extern void (*_nj_motion_callback_)(NJS_OBJECT *obj);
extern struct nj_motion_info _nj_motion_data_info_;
extern struct nj_motion_info _nj_shape_data_info_;
extern void (*_nj_motion_data_func_)(NJS_OBJECT *obj);
extern void (*_nj_shape_data_func_)(NJS_OBJECT *obj);
extern void (*_nj_motion_data_func_table_[5])(NJS_OBJECT *obj);
extern void (*_nj_shape_data_func_table_[4])(NJS_OBJECT *obj);
extern void (*_nj_motion_translate_)(NJS_OBJECT *obj);
extern void (*_nj_motion_rotate_)(NJS_OBJECT *obj);
extern void (*_nj_motion_scale_)(NJS_OBJECT *obj);
extern void (*_nj_motion_shape_)(NJS_OBJECT *obj);
extern void (*_nj_shape_int_func_table_[2])(NJS_OBJECT *obj);
extern void (*_nj_draw_model_sub_)(NJS_MODEL *model);
extern void (*_nj_motion_int_f_func_)(NJS_MKEY_F *keys, Uint32 index, Uint32 nb,
                                      Float *out);
extern void (*_nj_motion_int_f_func_table_[2])(NJS_MKEY_F *keys, Uint32 index,
                                               Uint32 nb, Float *out);
extern void (*_nj_motion_int_a_func_)(NJS_MKEY_A *keys, Uint32 index, Uint32 nb,
                                      Angle *out);
extern void (*_nj_motion_int_a_func_table_[2])(NJS_MKEY_A *keys, Uint32 index,
                                               Uint32 nb, Angle *out);
extern void (*_nj_motion_int_a_func_table_old_[2])(NJS_MKEY_A *keys,
                                                   Uint32 index, Uint32 nb,
                                                   Angle *out);
enum { SHAPE_POINTS = 1, SHAPE_NORMALS = 2, SHAPE_BOTH = 3 };
extern Uint16 _nj_mot_data_cnt_;
extern Uint16 _nj_mot_data_type_;
extern Uint16 _nj_mot_spline_cnt_;
extern Uint16 _nj_mot_shape_data_cnt_;
extern Uint16 _nj_mot_shape_data_type_;
extern Uint16 _nj_mot_shape_spline_cnt_;
extern Float *_nj_shape_buf_;
void njMotionIntTranslate(NJS_OBJECT *obj);
void njMotionIntScale(NJS_OBJECT *obj);
void njMotionIntRotateXYZ(NJS_OBJECT *obj);
void njMotionIntRotateZXY(NJS_OBJECT *obj);
void njMotionObjTranslate(NJS_OBJECT *obj);
void njMotionObjRotateXYZ(NJS_OBJECT *obj);
void njMotionObjRotateZXY(NJS_OBJECT *obj);
void njMotionObjScale(NJS_OBJECT *obj);
extern Float *_nj_mot_pos_buf_ptr_;
extern Angle *_nj_mot_ang_buf_ptr_;
extern Float *_nj_mot_scl_buf_ptr_;
void njGetMotionIntTranslate(NJS_OBJECT *obj);
void njGetMotionIntScale(NJS_OBJECT *obj);
void njGetMotionIntRotate(NJS_OBJECT *obj);
void njGetMotionObjTranslate(NJS_OBJECT *obj);
void njGetMotionObjRotate(NJS_OBJECT *obj);
void njGetMotionObjScale(NJS_OBJECT *obj);
extern Uint16 _nj_mot_current_data_;
extern Float _nj_mot_current_frame_;
extern struct nj_motlink_data_info _nj_motlink_data_info_[2];
extern struct nj_motlink_data_info _nj_shapelink_data_info_[2];
extern Uint16 _nj_motlink_data_cnt_[2];
extern Uint16 _nj_motlink_data_type_[2];
extern Uint16 _nj_motlink_shape_data_cnt_[2];
extern Uint16 _nj_motlink_shape_data_type_[2];
extern void (*_nj_motlink_data_func_[2])(NJS_OBJECT *object);
extern void (*_nj_motlink_data_func_table_[5])(NJS_OBJECT *object);
extern void (*_nj_motion_translate_data_[2])(NJS_OBJECT *object);
extern void (*_nj_motion_rotate_data_[2])(NJS_OBJECT *object);
extern void (*_nj_motion_scale_data_[2])(NJS_OBJECT *object);
extern void (*_nj_shapelink_data_func_[2])(NJS_OBJECT *object);
extern void (*_nj_shapelink_data_func_table_[4])(NJS_OBJECT *object);
extern void (*_nj_motion_shape_data_[2])(NJS_OBJECT *object);
extern void (*_nj_shapelink_int_func_table[2])(NJS_OBJECT *object);
void njMotionIntTranslateData(NJS_OBJECT *object);
void njMotionIntRotateData(NJS_OBJECT *object);
void njMotionIntScaleData(NJS_OBJECT *object);
void njMotionObjTranslateData(NJS_OBJECT *object);
void njMotionObjRotateData(NJS_OBJECT *object);
void njMotionObjScaleData(NJS_OBJECT *object);
extern void (*_nj_motlink_int_f_func_table_[2])(NJS_MKEY_F *keys, Uint32 index,
                                                Uint32 nb, Float *out);
extern void (*_nj_motlink_int_a_func_table_[2])(NJS_MKEY_A *keys, Uint32 index,
                                                Uint32 nb, Angle *out);
extern void (*_nj_int_f_func_)(Float *values, Float *out, Float rate);
extern void (*_nj_int_a_func_)(Angle *values, Angle *out, Float rate);
extern void (*_nj_int_f_func_table_[2])(Float *values, Float *out, Float rate);
extern void (*_nj_int_a_func_table_[2])(Angle *values, Angle *out, Float rate);
extern void (*_nj_rotate_func_)(NJS_MATRIX *m, Angle angx, Angle angy,
                                Angle angz);
extern Uint16 _nj_pos_int_flag_;
extern Uint16 _nj_ang_int_flag_;
extern Uint16 _nj_scl_int_flag_;
extern Uint16 _nj_pnt_int_flag_;
extern Uint16 _nj_nml_int_flag_;
extern Float _nj_motion_link_pos_[12];
extern Float _nj_motion_link_scl_[12];
extern Angle _nj_motion_link_ang_[12];
extern NJS_POINT3 *_nj_shape_link_point_[4];
extern NJS_VECTOR *_nj_shape_link_normal_[4];
void njMakeMotionLink(void);
void njMakeShapeLink(NJS_OBJECT *object);
extern Float _nj_cnk_easy_multilight_buffer_[16];
extern NJS_TEXSURFACE _nj_framebuffer_surface0_;
extern NJS_TEXSURFACE _nj_framebuffer_surface1_;
void njInitSprite(void);
typedef enum SYE_CBL_CABLE_TAG {
    SYE_CBL_CABLE_VGA = 0,
    SYE_CBL_CABLE_RESERVED = 1,
    SYE_CBL_CABLE_RGB = 2,
    SYE_CBL_CABLE_VBS = 3
} SYE_CBL_CABLE;
SYE_CBL_CABLE syCblCheckCable(void);
void syBtExit(void);
Sint32 syBtCheckDisc(void);
struct tag_SYS_BT_SYSTEMID {
    Sint32 nNo;
    Sint32 nAll;
    Sint8 szProduct[16];
};
typedef struct tag_SYS_BT_SYSTEMID SYS_BT_SYSTEMID;
Sint32 syBtGetBootSystemID(SYS_BT_SYSTEMID *id);
Sint32 syBtGetCurrentSystemID(SYS_BT_SYSTEMID *id);
void syBtGetSystemIDAddress(char **boot, char **current);
void syMallocInit(void *heap, Uint32 size);
void syMallocFinish(void);
void syMallocStat(Uint32 *wholeFreeSize, Uint32 *biggestFreeBlockSize);
void *syMalloc(Uint32 size);
void syFree(void *ptr);
typedef struct PDS_PERIPHERALINFO {
    Uint32 type;
    Uint32 reserved[3];
    Uint8 is_root;
    Uint8 area_code;
    Uint8 connector_dir[2];
    char product_name[32];
    char license[64];
    Uint16 stdby_pow;
    Uint16 max_pow;
} PDS_PERIPHERALINFO;
typedef struct PDS_PERIPHERAL {
    Uint32 id;
    Uint32 support;
    Uint32 on;
    Uint32 off;
    Uint32 press;
    Uint32 release;
    Uint16 r, l;
    Sint16 x1, y1, x2, y2;
    char *name;
    void *extend;
    Uint32 old;
    struct PDS_PERIPHERALINFO *info;
} PDS_PERIPHERAL;
void pdExecPeripheralServerUser(void);
typedef PDS_PERIPHERAL NJS_PERIPHERAL;
const NJS_PERIPHERAL *njGetPeripheral(Uint32 port);
void njPrintPeripheralInfo(Int loc, Uint32 port);
void pdInitPeripheral(Sint32 logic, void *recvbuf, void *sendbuf);
void pdExitPeripheral(void);
const PDS_PERIPHERAL *pdGetPeripheral(Uint32 port);
const PDS_PERIPHERALINFO *pdGetPeripheralInfo(Uint32 port);
Sint32 pdGetPeripheralError(Uint32 port);
void pdSetMode(Sint32 mode);
Sint32 pdGetMode(void);
typedef Uint16 SY_TMR_CLOCK;
void syTmrInit(void);
Uint32 syTmrGetCount(void);
Uint32 syTmrDiffCount(Uint32 count1, Uint32 count2);
Uint32 syTmrCountToMicro(Uint32 count);
Uint32 syTmrMicroToCount(Uint32 micro);
void syTmrGenStart(void);
void syTmrGenStop(void);
void syTmrGenSetInt(void (*func)(void *), void *arg);
void syTmrGenCancelInt(void);
void syTmrGenSetClock(SY_TMR_CLOCK clock);
void syTmrGenSetCount(Uint32 count);
Uint32 syTmrGenGetCount(void);
Uint32 syTmrGenMicroToCount(Uint32 micro, SY_TMR_CLOCK clock);
Uint32 syTmrGenCountToMicro(Uint32 count, SY_TMR_CLOCK clock);
Uint32 syTmrGenDiffCount(Uint32 count1, Uint32 count2);
Sint32 syTmrInt1Set(Uint32 count, void (*func)(void *), void *arg);
void syTmrInt1Cancel(void);
Sint32 syTmrInt1SetEx(Uint32 count, void (*func)(void *), void *arg,
                      SY_TMR_CLOCK clock);
typedef struct _SYS_RTC_DATE {
    Uint16 year;
    Uint8 month;
    Uint8 day;
    Uint8 hour;
    Uint8 minute;
    Uint8 second;
    Uint8 dayofweek;
    Uint8 ageofmoon;
} SYS_RTC_DATE;
Sint32 syRtcInit(void);
void syRtcFinish(void);
void syRtcExecServer(void);
Sint32 syRtcGetDate(SYS_RTC_DATE *date);
Sint32 syRtcSetDate(const SYS_RTC_DATE *date);
void syRtcSetServerMode(Sint32 mode);
Sint32 syRtcGetStat(void);
Sint32 syRtcCompareDate(const SYS_RTC_DATE *date1, const SYS_RTC_DATE *date2);
void syRtcDateToCount(const SYS_RTC_DATE *date, Uint32 *count);
void syRtcCountToDate(Uint32 count, SYS_RTC_DATE *date);
struct sy_fiber {
    void *sp;
    void *data;
};
Sint32 syFbrInit(struct sy_fiber *table, Sint32 count);
struct sy_fiber *syFbrCreateFiber(void *stack, Uint32 size,
                                  void (*func)(void *), void *data);
struct sy_fiber *syFbrConvertThreadToFiber(void *data);
Sint32 syFbrDeleteFiber(struct sy_fiber *fiber);
struct sy_fiber *syFbrGetCurrentFiber(void);
void *syFbrGetFiberData(void);
Sint32 syFbrSetIntStack(void *stack);
void syFbrSwitchToFiber(struct sy_fiber *fiber);
void syFbrDelayedSwitchToFiber(struct sy_fiber *fiber);
struct sy_fiber *syFbrGetTblPtr(int index);
Sint32 syFbrGetMaxFiber(void);
void *syFbrGetSp(struct sy_fiber *fiber);
void *syFbrGetData(struct sy_fiber *fiber);
void syFbrSetSp(struct sy_fiber *fiber, void *sp);
void syFbrSetData(struct sy_fiber *fiber, void *data);
void *syFbrGet_fib_sp(int index);
void syFbrDumpTable(void);
void *syFbrCreateFiberMain(void *stack, Sint32 size, void (*func)(void *),
                           void *data);
void syCacheInit_P2_(Uint32 form);
void syCachePurgeAll(void);
void syCacheICI_P2_(void);
void syCacheOCI_P2_(void);
void syCacheOCBP(void *address, Sint32 size);
void syCacheOCBI(void *address, Sint32 size);
void syCacheOCWB(void *address, Uint32 size);
void syCachePREF(void *address, Uint32 size);
void syCachePREF_s(void *address, Uint32 size);
void syCacheMOVCAL(void *address, Uint32 value);
void syCacheAllocCacheRAM(void **address, Sint32 pages);
void syCacheFreeCacheRAM(void *address);
void syIntInit(Uint32 mode, void *stack);
void syIntEnableInt(Uint32 level);
void syIntBrkRteRte(void);
typedef struct {
    Uint16 year;
    Uint8 month;
    Uint8 day;
    Uint8 hour;
    Uint8 minute;
    Uint8 second;
    Uint8 dayofweek;
} BUS_TIME;
typedef struct {
    Uint8 volume[32];
    Uint16 total_blocks;
    Uint16 total_user_blocks;
    Uint16 free_blocks;
    Uint16 free_user_blocks;
    Uint16 total_exe_blocks;
    Uint16 free_exe_blocks;
    Uint16 block_size;
    Uint16 icon_no;
    BUS_TIME time;
} BUS_DISKINFO;
typedef struct {
    Uint32 filesize;
    Uint16 blocks;
    Uint8 type;
    Uint8 copyflag;
    Uint16 headerofs;
    BUS_TIME time;
} BUS_FILEINFO;
typedef void (*BU_INITCALLBACK)(void);
typedef Sint32 (*BU_COMPLETECALLBACK)(Sint32 drive, Sint32 op, Sint32 status,
                                      Uint32 param);
typedef Sint32 (*BU_PROGRESSCALLBACK)(Sint32 drive, Sint32 op, Sint32 count,
                                      Sint32 max);
typedef struct {
    char vms_comment[18];
    char btr_comment[34];
    Uint8 game_name[16];
    void *icon_palette;
    void *icon_data;
    Uint16 icon_num;
    Uint16 icon_speed;
    void *visual_data;
    Uint16 visual_type;
    Uint16 reserved;
    void *save_data;
    Uint32 save_size;
} BUS_BACKUPFILEHEADER;
Sint32 buInit(Sint32 capacity, Sint32 drives, void *work, BU_INITCALLBACK func);
Sint32 buExit(void);
void buExecServer(void);
Uint32 buGetVersion(void);
void buSetCompleteCallback(BU_COMPLETECALLBACK func);
void buSetProgressCallback(BU_PROGRESSCALLBACK func);
void buSetCallbackParam(Uint32 param);
void buSetPrintFunc(void (*func)(const char *str));
void buSetRetryCount(Sint32 count);
Sint32 buIsReady(Sint32 drive);
Sint32 buStat(Sint32 drive);
Sint32 buGetLastError(Sint32 drive);
Sint32 buMount(Sint32 drive);
Sint32 buRemount(Sint32 drive);
Sint32 buUnmount(Sint32 drive);
Sint32 buMountDisk(Sint32 drive, void *addr, Sint32 size);
Sint32 buUnmountDisk(Sint32 drive);
Sint32 buIsFormat(Sint32 drive);
Sint32 buFormatDisk(Sint32 drive, const Uint8 *volume, Sint32 icon,
                    const BUS_TIME *time, Uint32 flag);
Sint32 buGetDiskInfo(Sint32 drive, BUS_DISKINFO *info);
Sint32 buGetDiskFree(Sint32 drive, Sint32 type);
Sint32 buDefragDisk(Sint32 drive, void *work);
Sint32 buFindFirstFile(Sint32 drive, char *fname);
Sint32 buFindNextFile(Sint32 drive, char *fname);
Sint32 buFindFirstFileEx(Sint32 drive, char *fname, BUS_FILEINFO *finfo);
Sint32 buFindNextFileEx(Sint32 drive, char *fname, BUS_FILEINFO *finfo);
Sint32 buFindExecFile(Sint32 drive, char *fname);
Sint32 buIsExistFile(Sint32 drive, const char *fname);
Sint32 buGetFileInfo(Sint32 drive, const char *fname, BUS_FILEINFO *finfo);
Sint32 buGetFileSize(Sint32 drive, const char *fname);
Sint32 buLoadFile(Sint32 drive, const char *fname, void *buf, Uint32 nblock);
Sint32 buLoadFileEx(Sint32 drive, const char *fname, void *buf, Uint32 start,
                    Uint32 nblock);
Sint32 buSaveFile(Sint32 drive, const char *fname, const void *buf,
                  Uint32 nblock, BUS_TIME *time, Uint32 flag);
Sint32 buSaveExecFile(Sint32 drive, const char *fname, const void *buf,
                      Uint32 nblock, BUS_TIME *time, Uint32 flag);
Sint32 buRewriteExecFile(Sint32 drive, const char *fname, const void *buf,
                         Uint32 start, Uint32 nblock);
Sint32 buDeleteFile(Sint32 drive, const char *fname);
Sint32 buDeleteFileEx(Sint32 drive, const char **fname, Sint32 nfiles);
Sint32 buRenameFile(Sint32 drive, const char *from, const char *to);
Sint32 buSetFileAttr(Sint32 drive, const char *fname, Uint16 hdrofs,
                     Uint8 copyflag);
Sint32 buMakeBackupFileImage(void *buf, const BUS_BACKUPFILEHEADER *hdr);
Sint32 buCalcBackupFileSize(Uint32 inum, Uint32 vtype, Uint32 size);
Sint32 buAnalyzeBackupFileImage(BUS_BACKUPFILEHEADER *hdr, const void *buf);
Uint16 buCalcCRC(const void *buf, Uint32 size);
void buDisableServer(void);
void kbCfgIni(Sint32 which);
void *kbCfgGetId(void);
typedef struct SYS_BT_FL_BLK_INFO {
    Sint32 fmaddr;
    Sint32 size;
} SY_BT_FL_BLKINFO;
Sint32 syBtFlGetInfo(Sint32 part, SY_BT_FL_BLKINFO *info);
Sint32 syBtFlRead(Sint32 address, void *buffer, Sint32 size);
Sint32 syBtFlWrite(Sint32 address, void *buffer, Sint32 size);
Sint32 syBtFlDeleteSct(Sint32 address);
Sint32 fmMngInit(Sint32 part, void *work);
Sint32 fmMngFormat(Sint32 type);
Sint32 fmMngRead(Sint32 packet, void *buffer);
Sint32 fmMngWrite(Sint32 packet, void *buffer);
Sint32 fmMngExecServer(void);
Sint32 fmMngGetErr(void);
void fmMngFinish(void);
Sint32 fmMngRefresh(void);
Sint32 fmMngGetFree(void);
Uint32 fmcalccrc(Sint32 size, const Uint8 *data);
Sint32 syBtCfgSet(Sint32 permit, void *work);
Sint32 syCfgInit(void *work);
Sint32 syCfgExit(void);
Sint32 syCfgSetSoundMode(Sint32 mode);
Sint32 syCfgGetSoundMode(Sint32 *mode);
enum SDE_ERR {
    SDE_ERR_NOTHING,
    SDE_ERR_PRM_OVER_RANGE = 0x03000001,
    SDE_ERR_QUEUE_NO_ENOUGH = 0x05000101,
    SDE_ERR_MEMBLK_ALREADY_TRANSFER = 0x06000001,
    SDE_ERR_HANDLE_NO_ENOUGH = 0x07000101,
    SDE_ERR_HANDLE_ILLEGAL_VALUE = 0x07000102,
    SDE_ERR_HANDLE_NULL = 0x07000103,
    SDE_ERR_PTR_NULL = 0x07000203,
    SDE_ERR_BANK_ILLEGAL_NUM = 0x08000003,
    SDE_ERR_DATA_ILLEGAL_TYPE = 0x09000001,
    SDE_ERR_DATA_ILLEGAL_VER = 0x09000002,
    SDE_ERR_HOST_CMD_BUF_NO_ENOUGH = 0x0a000001,
    SDD_ERR_SND_DRV_ILLEGAL_VER = 0x0b000002,
    SDE_ERR_SND_DRV_BUSY = 0x0b000003,
    SDE_ERR_NO_INIT = 0x0d000001,
    SDE_ERR_UNKNOW_NUM = 0x7fffffff
};
typedef enum SDE_ERR SDE_ERR;
enum SDE_DATA_TYPE {
    SDE_DATA_TYPE_SND_DRV = (('S') | (('D') << 8) | (('R') << 16) | (('V') << 24)),
    SDE_DATA_TYPE_MULTI_UNIT = (('S') | (('M') << 8) | (('L') << 16) | (('T') << 24)),
    SDE_DATA_TYPE_MIDI_SEQ_DATA = (('S') | (('M') << 8) | (('S') << 16) | (('D') << 24)),
    SDE_DATA_TYPE_MIDI_SEQ_BANK = (('S') | (('M') << 8) | (('S') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_MIDI_PRG_BANK = (('S') | (('M') << 8) | (('P') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_SHOT_DATA = (('S') | (('O') << 8) | (('S') << 16) | (('D') << 24)),
    SDE_DATA_TYPE_SHOT_BANK = (('S') | (('O') << 8) | (('S') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_PSTM_DATA = (('S') | (('P') << 8) | (('S') << 16) | (('D') << 24)),
    SDE_DATA_TYPE_PSTM_RING_BUF = (('S') | (('P') << 8) | (('S') << 16) | (('R') << 24)),
    SDE_DATA_TYPE_FX_OUT_BANK = (('S') | (('F') << 8) | (('O') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_FX_PRG_BANK = (('S') | (('F') << 8) | (('P') << 16) | (('B') << 24)),
    SDE_DATA_TYPE_FX_PRG_WRK = (('S') | (('F') << 8) | (('P') << 16) | (('W') << 24))
};
typedef enum SDE_DATA_TYPE SDE_DATA_TYPE;
enum SDE_SPACE {
    SDE_SPACE_MONO = (('M') | (('O') << 8) | (('N') << 16) | (('O') << 24)),
    SDE_SPACE_STEREO = (('S') | (('T') << 8) | (('R') << 16) | (('O') << 24))
};
typedef enum SDE_SPACE SDE_SPACE;
enum SDE_MEMBLK_STAT {
    SDE_MEMBLK_STAT_TRANSFER_REMAIN,
    SDE_MEMBLK_STAT_TRANSFER_FINISHED,
    SDE_MEMBLK_STAT_TRANSFER_PROGRESS
};
typedef enum SDE_MEMBLK_STAT SDE_MEMBLK_STAT;
enum SDE_MEMBLK_TRANSFER_MODE {
    SDE_MEMBLK_TRANSFER_MODE_CPU,
    SDE_MEMBLK_TRANSFER_MODE_DMA
};
typedef enum SDE_MEMBLK_TRANSFER_MODE SDE_MEMBLK_TRANSFER_MODE;
enum SDE_PCM_TYPE {
    SDE_PCM_TYPE_8BIT_PCM,
    SDE_PCM_TYPE_16BIT_PCM,
    SDE_PCM_TYPE_4BIT_ADPCM
};
typedef enum SDE_PCM_TYPE SDE_PCM_TYPE;
typedef struct SDS_MIDI_MES {
    Uint8 m_Member[4];
} SDS_MIDI_MES;
struct SDS_VER {
    Sint8 m_MajorVer;
    Sint8 m_MinorVer;
    Sint8 m_DebugVer;
    Sint8 rsv;
};
typedef struct SDS_VER SDS_VER;
typedef struct SDS_PORT_REF *SDHANDLE;
typedef SDHANDLE *SDMIDI;
typedef SDHANDLE *SDPSTM;
struct SDS_MIDI_STAT {
    Sint8 m_HostCmdRsvNum;
    Sint8 m_HostCmdDelayTime;
    Sint8 m_Vol;
    Sint8 m_Pan;
    Sint8 m_FxLev;
    Sint8 m_DrctLev;
    Sint16 m_Pitch;
    Sint16 m_Speed;
    Uint32 m_TotalBeatTime;
    Sint32 m_CurAdr;
    Uint32 m_Err;
    Uint32 m_Flg;
};
typedef struct SDS_MIDI_STAT SDS_MIDI_STAT;
struct SDS_PSTM_STAT {
    Sint8 m_HostCmdRsvNum;
    Sint8 m_HostCmdDelayTime;
    Sint8 m_Vol;
    Sint8 m_Pan;
    Sint8 m_FxLev;
    Sint8 m_DrctLev;
    Sint16 m_Pitch;
    Sint16 m_Speed;
    Uint32 m_TotalSmpFrame;
    Sint32 m_CurAdr;
    Uint32 m_Err;
    Uint32 m_Flg;
};
typedef struct SDS_PSTM_STAT SDS_PSTM_STAT;
struct SDS_MEM_BLK {
    Uint32 m_Member[8];
};
typedef struct SDS_MEM_BLK *SDMEMBLK;
typedef void (*SD_MEMBLK_CALLBACK_FUNC)(void *first_arg);
SDE_ERR sdDrvInit(SDMEMBLK handle);
SDE_ERR sdDrvGetInfo(void);
SDE_ERR sdLibInit(void *wrk_ptr, Sint32 mem_blk_handle_max,
                  Sint32 second_host_cmd_max);
SDE_ERR FUN_8c643ed8(void);
SDE_ERR sdSysFlushHostCmd(void);
void sdSysErrTrap(void *func, SDE_ERR err);
int sdDebugPrintf(const char *format, ...);
int sdDebugPrint(const char *str);
int sdDebugSetPrintFunc(void (*func)(const char *str));
extern Bool sdgDebugMode;
extern void (*sdgPrintFunc)(const char *str);
extern Sint32 sdgExistSndDrv;
SDE_ERR sdARM7ResetKeep(void);
SDE_ERR sdARM7ResetRel(void);
SDE_ERR sdSndMemClear(void);
SDE_ERR sdSndMemWriteUint8(Sint32 address, Uint8 value);
SDE_ERR sdModuleRefInit(void);
SDE_ERR sdPrimaryHostCmdInitList(void *buffer);
extern void *sdgPrimaryBufPtr;
SDE_ERR sd2ndHostCmdSendList(void);
SDE_ERR sdPrimaryHostCmdFlush(void);
void sdPrimaryHostCmdFlushCallback(void *first_arg);
SDE_ERR sdSndMemReadSint8(Sint32 address, Sint8 *value);
SDE_ERR sdSndMemReadUint8(Sint32 address, Uint8 *value);
SDE_ERR sdSndMemReadSint32(Sint32 address, Sint32 *value);
SDE_ERR sdSndMemReadUint32(Sint32 address, Uint32 *value);
SDE_ERR sdSndMemWriteSint32(Sint32 address, Sint32 value);
SDE_ERR sdSndMemWriteUint32(Sint32 address, Uint32 value);
SDE_ERR sdSndSetSpace(const SDE_SPACE space);
SDE_ERR sdSndSetFxPrg(const Sint8 new_fx_prg_num, const Sint8 new_fx_out_num);
SDE_ERR sdSndSetFxOutPrm(const Sint8 out_num, const Sint8 out_pan,
                         const Sint8 out_lev);
SDE_ERR sdQsndSetPos(const Sint8 *pos);
SDE_ERR sdMultiUnitDownload(SDMEMBLK handle);
SDE_ERR sdBankDownload(SDMEMBLK handle, const SDE_DATA_TYPE bank_type,
                       const Sint8 bank_num);
SDE_ERR sdSndMemGetBankStat(const SDE_DATA_TYPE data_type, const Sint8 bank_num,
                            Sint32 *allocate_ptr, Sint32 *allocate_size);
SDE_ERR sdSndMemAllocateBank(const SDE_DATA_TYPE data_type, int bank_num,
                             Sint32 allocate_ptr, Sint32 allocate_size);
SDE_ERR sdMemBlkCreate(SDMEMBLK *handle);
SDE_ERR sdMemBlkDestroy(SDMEMBLK handle);
SDE_ERR sdMemBlkSetPrm(SDMEMBLK handle, const void *src_blk_ptr,
                       const Sint32 src_blk_sz,
                       const SD_MEMBLK_CALLBACK_FUNC callback_func,
                       const void *callback_first_arg);
SDE_ERR sdMemBlkGetStat(SDMEMBLK handle, SDE_MEMBLK_STAT *stat);
SDE_ERR sdMemBlkTransfer(SDMEMBLK handle, Sint32 dst_ptr);
SDE_ERR sdMemBlkSetTransferMode(SDE_MEMBLK_TRANSFER_MODE transfer_mode);
SDE_ERR sdMemBlkQueGetPushNum(Sint32 *push_num);
SDE_ERR sdMemBlkSetStat(SDMEMBLK handle, SDE_MEMBLK_STAT stat);
SDE_ERR sdMemBlkSetAdr(SDMEMBLK handle, const void *src_blk_ptr);
SDE_ERR sdMemBlkSetSz(SDMEMBLK handle, Sint32 src_blk_sz);
SDE_ERR sdMemBlkSetCallback(SDMEMBLK handle,
                            SD_MEMBLK_CALLBACK_FUNC callback_func,
                            const void *callback_first_arg);
SDE_ERR sdMemBlkExecuteCallback(SDMEMBLK handle);
SDE_ERR sdMemBlkCpuTransfer(SDMEMBLK handle, Sint32 dst_ptr);
SDE_ERR sdMemBlkQuePush(SDMEMBLK handle, Sint32 dst_ptr);
SDE_ERR sdMemBlkQuePop(SDMEMBLK *handle, Sint32 *dst_ptr);
SDE_ERR sdMemBlkDmaTransfer(SDMEMBLK handle, Sint32 dst_ptr);
void sdMemBlkWaitSync(void);
void sdMemBlkG2DmaErrTrap(void);
void sdMemBlkEndTransferHandller(void *first_arg);
SDE_ERR sdMoveWrkMemToSndMem(void *src_ptr, Sint32 dst_ptr, Sint32 size,
                             SD_MEMBLK_CALLBACK_FUNC callback_func,
                             void *callback_first_arg);
SDE_ERR sdMidiOpenPort(SDMIDI *handle);
SDE_ERR sdMidiPlay(SDMIDI handle, const Sint8 bank_num, const Sint8 data_num,
                   const Sint8 priority);
SDE_ERR sdMidiSetMes(SDMIDI handle, SDS_MIDI_MES *midi_mes_ptr,
                     const Uint8 midi_mes, ...);
SDE_ERR sdMidiSetVol(SDMIDI handle, const Sint8 vol, const Sint32 fade_time);
SDE_ERR sdMidiStop(SDMIDI handle);
SDE_ERR sdMidiSendMes(SDMIDI handle, const SDS_MIDI_MES *midi_mes_ptr,
                      const Sint8 priority);
SDE_ERR sdMidiGetCurAdr(SDMIDI handle, Sint32 *cur_adr);
SDE_ERR sdMidiGetStat(SDMIDI handle, SDS_MIDI_STAT *midi_stat);
SDE_ERR sdMidiGetTotalBeatTime(SDMIDI handle, Uint32 *cur_beat_time);
SDE_ERR sdMidiGetDrctLev(SDMIDI handle, Sint8 *drct_lev);
SDE_ERR sdMidiGetErr(SDMIDI handle, Uint32 *err_num);
SDE_ERR sdMidiGetFlg(SDMIDI handle, Uint32 *flg);
SDE_ERR sdMidiGetFxLev(SDMIDI handle, Sint8 *fx_lev);
SDE_ERR sdMidiGetPan(SDMIDI handle, Sint8 *pan);
SDE_ERR sdMidiGetPitch(SDMIDI handle, Sint16 *pitch);
SDE_ERR sdMidiGetSpeed(SDMIDI handle, Sint16 *speed);
SDE_ERR sdMidiGetVol(SDMIDI handle, Sint8 *vol);
SDE_ERR sdPstmClosePort(SDPSTM handle);
SDE_ERR sdPstmGetCurAdr(SDPSTM handle, const Sint8 target_ch,
                        Sint32 *cur_smp_adr);
SDE_ERR sdPstmGetStat(SDPSTM handle, const Sint8 target_ch,
                      SDS_PSTM_STAT *pstm_stat);
SDE_ERR sdPstmGetTotalSmpFrame(SDPSTM handle, const Sint8 target_ch,
                               Uint32 *cur_smp_frame);
SDE_ERR sdPstmOpenPort(SDPSTM *handle, const Sint8 use_ch, ...);
SDE_ERR sdPstmPlay(SDPSTM handle, const SDE_PCM_TYPE pcm_type,
                   const Uint16 freq, const Sint8 priority);
SDE_ERR sdPstmPlayMw(SDPSTM handle, const SDE_PCM_TYPE pcm_type,
                     const Uint16 freq, const Sint8 priority);
SDE_ERR sdPstmResetPrm(SDPSTM handle);
SDE_ERR sdPstmSetBaseVol(SDPSTM handle, const Sint8 base_vol);
SDE_ERR sdPstmSetDrctLev(SDPSTM handle, const Sint8 drct_lev);
SDE_ERR sdPstmSetFxCh(SDPSTM handle, const Sint8 fx_in_ch,
                      const Sint8 fx_base_lev);
SDE_ERR sdPstmSetPan(SDPSTM handle, const Sint8 target_ch, const Sint8 pan,
                     const Sint32 fade_time);
SDE_ERR sdPstmSetPitch(SDPSTM handle, const Sint16 pitch,
                       const Sint32 fade_time);
SDE_ERR sdPstmSetUseCh(SDPSTM handle, const Sint8 use_ch);
SDE_ERR sdPstmSetVol(SDPSTM handle, const Sint8 target_ch, const Sint8 vol,
                     const Sint32 fade_time);
SDE_ERR sdPstmStop(SDPSTM handle);
SDE_ERR sdPstmStopAll(void);
SDE_ERR sdPstmGetDrctLev(SDPSTM handle, const Sint8 target_ch, Sint8 *drct_lev);
SDE_ERR sdPstmGetErr(SDPSTM handle, const Sint8 target_ch, Uint32 *err_num);
SDE_ERR sdPstmGetFlg(SDPSTM handle, const Sint8 target_ch, Uint32 *flg);
SDE_ERR sdPstmGetFxLev(SDPSTM handle, const Sint8 target_ch, Sint8 *fx_lev);
SDE_ERR sdPstmGetPan(SDPSTM handle, const Sint8 target_ch, Sint8 *pan);
SDE_ERR sdPstmGetPitch(SDPSTM handle, const Sint8 target_ch, Sint16 *pitch);
SDE_ERR sdPstmGetSpeed(SDPSTM handle, const Sint8 target_ch, Sint16 *speed);
SDE_ERR sdPstmGetVol(SDPSTM handle, const Sint8 target_ch, Sint8 *vol);
typedef struct GDS_FS_HANDLE *GDFS;
typedef struct GDS_FS_DIRREC_TBL *GDFS_DIRREC;
typedef void (*GDFS_ERRFUNC)(void *obj, Sint32 err);
typedef void (*GDFS_FUNC)(void *obj);
Sint32 gdFsInit(Sint32 max_open, void *gdfs_work, Sint32 max_dirent,
                void *dirbuf);
Sint32 gdFsInitOvl(Sint32 max_open, void *gdfs_work, Sint32 max_dirent,
                   void *dirbuf);
Sint32 gdFsReinit(void);
void gdFsFinish(void);
GDFS_DIRREC gdFsCreateDirhn(void *dirbuf, Sint32 max_dirent);
Sint32 gdFsLoadDir(const char *dirname, GDFS_DIRREC gf_dirrec);
Sint32 gdFsSetDir(GDFS_DIRREC gf_dirrec);
Sint32 gdFsChangeDir(const char *dirname);
GDFS gdFsOpen(const char *fname, GDFS_DIRREC gf_dirrec);
GDFS gdFsOpenRange(Sint32 stsct, Sint32 nsct);
typedef struct GDS_FS_DIRINFO {
    Sint32 fad;
    Sint32 fsize;
    Uint8 flag;
    Uint8 pad[3];
} GDFS_DIRINFO;
Sint32 gdFsGetDirInfo(const char *name, GDFS_DIRINFO *dirinfo);
Bool gdFsGetFileSize(GDFS gdfs, Sint32 *fsize);
Bool gdFsGetFileSctSize(GDFS gdfs, Sint32 *fsctsize);
Bool gdFsGetFileFad(GDFS gdfs, Sint32 *fad);
Sint32 gdFsSeek(GDFS gdfs, Sint32 sctno, Sint32 type);
Sint32 gdFsTell(GDFS gdfs);
Sint32 gdFsCheckEof(GDFS gdfs, Bool *iseof);
Sint32 gdFsRead(GDFS gdfs, Sint32 nsct, void *buf);
Sint32 gdFsReqRd32(GDFS gdfs, Sint32 nsct, void *buf);
Sint32 gdFsGetStat(GDFS gdfs);
Sint32 gdFsGetErrStat(GDFS gdfs);
Sint32 gdFsStopRd(GDFS gdfs);
Sint32 gdFsGetNumRd(GDFS gdfs);
Sint32 gdFsMovePickup(GDFS gdfs);
Sint32 gdFsReqGdRd(GDFS gdfs, Sint32 nsct);
Sint32 gdFsTrans32(GDFS gdfs, Sint32 nbytes, void *buf);
Sint32 gdFsGetTransStat(GDFS gdfs);
GDFS gdFsGetWorkHn(void);
GDFS gdFsGetSysHn(void);
Sint32 gdFsGetToc(Sint32 type, void *buf);
void gdFsClose(GDFS gdfs);
Sint32 gdFsGetDrvStat(void);
Sint32 gdFsReqDrvStat(void);
Bool gdFsIsTrayOpen(void);
void gdFsEntryRdEndFunc(GDFS gdfs, GDFS_FUNC func, void *obj);
void gdFsEntryTrEndFunc(GDFS gdfs, GDFS_FUNC func, void *obj);
void gdFsEntryErrFunc(GDFS gdfs, GDFS_ERRFUNC erfunc, void *obj);
void gdFsEntryErrFuncAll(GDFS_ERRFUNC erfunc, void *obj);
void gdFsExecServer(void);
Sint32 gdFsDaPlay(Sint32 st_track, Sint32 end_track, Sint32 reptime);
Sint32 gdFsDaPlaySct(Sint32 st_sct, Sint32 end_sct, Sint32 reptime);
Sint32 gdFsDaStop(void);
Sint32 gdFsDaPause(void);
Sint32 gdFsDaRelease(Sint32 reptime);
typedef struct GDS_FS_DAINFO {
    Sint32 track;
    Sint32 min;
    Sint32 sec;
    Sint32 frame;
    Sint32 fad;
} GDFS_DAINFO;
Sint32 gdFsDaGetInfo(GDFS_DAINFO *dainfo);
Sint32 gdGdcReqCmd(Sint32 cmd, void *param);
Sint32 gdGdcGetCmdStat(Sint32 gdchn, void *stat);
void gdGdcExecServer(void);
void gdGdcInitSystem(void);
Sint32 gdGdcGetDrvStat(Sint32 *info);
void gdGdcG1DmaEnd(GDFS_FUNC func, void *obj);
Sint32 gdGdcReqDmaTrans(Sint32 gdchn, Sint32 *param);
Sint32 gdGdcCheckDmaTrans(Sint32 gdchn, Sint32 *size);
void gdGdcReadAbort(Sint32 gdchn);
void gdGdcReset(void);
extern NJS_FOG_TABLE jungle_fog_table;
extern Uint32 jungle_fog_shown;
void jungle_fog_init(void);
void jungle_fog_update(int time);
struct task;
enum logo_result { LOGO_ADVERTISE = 1, LOGO_MOVIE = 3 };
extern Bool demo_playing;
extern int demo_event;
extern int demo_event_ended;
extern NJS_TEXLIST press_start_texlist;
void logo_start(void);
void boot_init(void);
int logo_step(void);
void demo_set_flags(void);
void demo_advance(void);
void menu_begin(void);
int demo_next_mode(void);
void demo_event_start(struct task *task);
struct task;
void sound_system_init(void);
void sound_set_space(void);
void sound_load_stage(void);
void sound_load_file(const char *name);
void sound_load_shot_bank(int bank, const char *name);
void sound_load_sequence_bank(int bank, const char *name);
void sound_load_program_bank(int bank, const char *name);
void sound_download(void *data);
void sound_slot_play(int bank, int number, int priority, int slot);
void sound_slot_stop(int slot);
void sound_slot_set_pan(int pan, int slot);
void sound_slot_set_pitch(int pitch, int slot);
void sound_set_qsound(Sint8 *pos);
int sound_play(int se, int id, int priority, int volume);
int sound_play_at(int se, int id, int priority, int volume, Float x, Float y,
                  Float z);
int sound_play_held(int se, int id, int priority, int volume);
int sound_play_for(int se, int id, int priority, int volume, int updates);
int sound_play_at_for(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, int updates);
int sound_play_around(int se, int id, int priority, int volume, Float x,
                      Float y, Float z, Float radius, int updates);
void sound_stop(int se);
void sound_stop_id(int id);
void sound_set_volume(int id, int volume);
void sound_set_pan(int id, int pan);
void sound_set_pitch(int id, int pitch);
void sound_mute(void);
void sound_unmute(void);
void sound_kill_all(void);
void sound_send_queue(void);
void fun_8c09a47e(void);
void sound_end_act(void);
void sound_pause(void);
void sound_resume(int unused);
void sound_request_fx(int level);
void sound_request_fx_max(void);
void sound_test(void);
void sound_load_voice(void);
void sound_fx_zone_step(struct task *task);
void sound_orbit_step(struct task *task);
void sound_load_alt_voice(void);
void sound_load_alt_field(void);
void sound_play_bank(Uint8 bank, Uint8 number);
struct particle;
struct story_record;
struct task;
struct task_work;
enum stage_group { STAGE_GROUP_FIELD = 1, STAGE_GROUP_ACTION = 2 };
enum stage_end {
    STAGE_END_NONE = 0,
    STAGE_END_CLEAR = 1,
    STAGE_END_MISS = 2,
    STAGE_END_GO_TO = 3,
    STAGE_END_RESTART = 4,
    STAGE_END_RETRY = 5,
    STAGE_END_QUIT = 6
};
enum stage_step {
    STAGE_STEP_RESET = -2,
    STAGE_STEP_QUIT = -1,
    STAGE_STEP_STAFF_ROLL = 10
};
struct trial_time {
    Uint32 minutes;
    Uint32 seconds;
    Uint32 frames;
};
struct mirror_quad {
    NJS_VECTOR normal;
    NJS_POINT3 corners[4];
};
struct mirror {
    Sint32 count;
    struct mirror_quad quads[32];
};
struct mirror_list {
    Sint32 count;
    struct mirror mirrors[4];
};
extern int event_ending;
extern Sint16 stage_mode;
extern Sint16 stage_previous;
extern Sint16 act_previous;
extern Sint16 stage_current;
extern Sint16 act_current;
extern Sint16 stage_loaded;
extern Sint16 act_loaded;
extern Sint16 stage_next;
extern Sint16 act_next;
extern Sint16 entrance_next;
extern Uint16 character_current;
extern Sint16 stage_retries;
extern Sint16 pause_choice;
extern Sint16 pause_hidden;
extern Sint16 continue_choice;
extern Sint16 continue_timer;
extern int dat_8c75b734;
extern struct task *stage_task;
extern Uint16 collision_item_count;
extern Uint16 collision_enemy_count;
extern Sint8 debug_hidden;
extern Sint8 hud_hidden;
extern Sint8 lives_shown;
extern Sint8 rings_shown;
extern Sint8 lives;
extern Sint8 time_minutes;
extern Sint8 time_seconds;
extern Sint8 time_frames;
extern Sint16 rings;
extern int play_time;
extern int time_steps;
extern int score;
extern int bonus_points;
extern int trial_count;
extern Float shoot_hit_rate;
extern int hints_used;
extern struct trial_time trial_times[5];
extern struct mirror_list mirrors;
extern NJS_VECTOR scratch_vector;
extern NJS_VECTOR scratch_vector2;
extern NJS_VECTOR scratch_vector3;
extern Uint8 dat_8c75d5dc[12];
extern NJS_POINT3 scratch_point;
extern NJS_POINT3 scratch_point2;
extern NJS_MATRIX scratch_matrix;
extern Uint8 dat_8c75d640[192];
extern NJS_VECTOR world_gravity;
extern Angle world_gravity_ang_x;
extern Angle world_gravity_ang_z;
extern struct story_record *player_record;
extern int dat_8c75d758;
extern Sint8 debug_unlocked;
void pause_enable(void);
void pause_disable(void);
void boot_new_game(void);
enum stage_group stage_group(void);
enum stage_group stage_begin(void);
Sint16 stage_step_action(void);
Sint16 stage_step_field(void);
void stage_end(Sint16 end);
void sound_play_later(int se);
void music_play_later(int music);
void stage_clear(void);
void set_character(Sint16 character);
void set_character_number(Sint16 character);
int get_character(void);
int stage_get_retries(void);
Uint16 GetStageNumber(void);
Uint16 stage_get_previous_stage_act(void);
void stage_set_stage_act(Uint8 stage, Uint8 act);
void stage_fade_to(Uint8 stage, Uint8 act);
void stage_restart(void);
void stage_set_next_stage_act(Uint8 stage, Uint8 act);
Uint16 stage_get_next_stage_act(void);
void stage_go_to_next(void);
void stage_change_act(Sint16 by);
void stage_set_entrance(Sint8 entrance);
Sint8 stage_get_entrance(void);
void stage_place_player(struct task_work *work);
void stage_set_next_exit(void);
Bool stage_paused(void);
Bool stage_playing(void);
struct collision_work;
struct event_work;
struct placement;
struct player;
struct task;
struct angles {
    Angle x, y, z;
};
union task_vars {
    Sint8 b[12];
    Sint16 w[6];
    Sint32 l[3];
    Float f[3];
    void *p[3];
};
struct task_work {
    Sint8 mode;
    Sint8 submode;
    Uint8 id;
    Uint8 tick;
    Sint16 flags;
    Sint16 timer;
    union task_vars vars;
    struct angles ang;
    NJS_POINT3 pos;
    NJS_POINT3 scl;
    struct collision_work *collision;
    struct event_work *event;
};
struct task_motion {
    struct player *record;
    NJS_VECTOR speed;
    NJS_VECTOR accel;
    struct angles aim;
    Sint32 unk_28;
    Uint8 unk_2c[4];
    Angle phase;
    Float drive;
    Float slip;
    Float gravity;
};
struct task_force {
    void (*carry)(struct task *rider, struct task_work *work,
                  struct task_force *force);
    struct angles turn;
    NJS_VECTOR speed;
};
struct task {
    struct task *next;
    struct task *prev;
    struct task *parent;
    struct task *child;
    void (*step)(struct task *task);
    void (*draw)(struct task *task);
    void (*destructor)(struct task *task);
    struct placement *placement;
    struct task_work *work;
    struct task_motion *motion;
    void *force;
    void *extra;
};
struct task_spec {
    void (*step)(struct task *task);
    Uint16 create;
    Sint16 flags;
    struct angles ang;
    NJS_POINT3 pos;
    Sint32 var;
};
void task_idle(struct task *task);
void (*task_get_current_root_step(void))(struct task *task);
void task_init(void);
struct task *task_create(Uint16 flags, int level,
                         void (*step)(struct task *task));
struct task *task_alloc(int level, void (*step)(struct task *task));
void task_destroy(struct task *task);
void task_kill(struct task *task);
void task_step_level(int level);
void task_draw_level(int level);
void task_draw_children(struct task *task);
void task_destroy_level(int level);
void task_step_all(void);
void task_draw_all(void);
void task_destroy_levels_0_to_6(void);
void task_destroy_all(void);
void *task_alloc_work(void);
void *task_alloc_motion(void);
void *task_alloc_force(void);
void *task_alloc_extra(void);
void task_free_work(struct task *task);
void task_free_motion(struct task *task);
void task_free_force(struct task *task);
void task_free_extra(struct task *task);
struct task *task_create_child(Uint16 flags, void (*step)(struct task *task),
                               struct task *parent);
struct task *task_create_children(struct task_spec *spec, struct task *parent);
void task_destroy_children(struct task *task);
void task_step_children(struct task *task);
void heap_init(void);
void *heap_alloc(int size);
void *heap_calloc(int count, int size);
void heap_free(void *mem);
void heap_stats(int *total, int *largest);
extern NJS_FOG_TABLE windy_fog_table;
extern NJS_COLOR windy_fog_color;
extern Uint32 windy_fog_shown;
void windy_step(struct task *task);
void windy_sky_step(struct task *task);
extern Uint32 draw_palettes[8][256 * 2];
extern Uint32 draw_unlit_offsets[512];
extern int draw_debug_counts[20];
void draw_model_init(void);
void draw_model(NJS_MODEL *model);
void draw_model_nested(NJS_MODEL *model);
void draw_models_begin(void);
void draw_model_unculled(NJS_MODEL *model);
void draw_models_end(void);
Bool draw_in_view(Float x, Float y, Float z, Float radius);
void draw_set_light(Float x, Float y, Float z);
void draw_divide_light(Float scale);
void draw_reset_light(void);
void draw_set_palette(int palette);
void draw_take_point_lights(void);
struct path;
struct path_point;
void sky_deck_step(struct task *task);
void sky_deck_sky_step(struct task *task);
void sky_deck_welcome(void);
struct trail_point {
    Sint32 wait;
    NJS_POINT3 pos;
    NJS_VECTOR speed;
};
enum trail_volume_kind {
    TRAIL_UPRIGHT,
    TRAIL_LYING,
    TRAIL_BALL
};
struct trail_volume {
    struct task_work *owner;
    Sint32 kind;
    NJS_POINT3 center;
    Float reach;
    Float radius;
    Float height;
};
extern Sint8 sky_deck_started_act;
extern Sint8 sky_deck_act;
extern struct trail_point trail_points[32][5];
extern Sint32 trail_life[32];
extern struct trail_volume trail_volumes[20];
extern NJS_FOG_TABLE sky_deck_fog_table;
extern Uint32 sky_deck_fog_color;
extern Float sky_deck_shade;
extern Float sky_deck_fog_near;
extern Float sky_deck_fog_far;
extern Uint32 sky_deck_palettes_above[8][256 * 2];
extern Uint32 sky_deck_palettes_below[8][256 * 2];
extern int sky_deck_sky_mode;
extern NJS_POINT3 sky_deck_sky_pos;
extern Float sky_deck_sky_lift;
extern Float sky_deck_timeline_value;
extern int sky_deck_cloud_scroll;
extern int sky_deck_cloud_scroll_low;
extern Angle sky_deck_roll;
extern Angle sky_deck_pitch;
extern NJS_VECTOR dat_0caf373c;
extern Float sky_deck_timeline_rate;
extern int sky_deck_timeline_steps;
extern int sky_deck_clouds;
extern int sky_deck_cloud_wait;
extern NJS_COLOR sky_deck_cloud_uvs[32];
extern NJS_COLOR sky_deck_cloud_uvs_low[32];
extern int sky_deck_clock;
extern NJS_POINT3COL trail_line;
extern NJS_POINT3 trail_line_points[5];
extern NJS_COLOR trail_line_colors[5];
extern Float draft_lift;
extern Float draft_push;
void edge_0_step(struct task *task);
void branch_l_step(struct task *task);
void branch_s_step(struct task *task);
void pole_s_step(struct task *task);
void pole_l_step(struct task *task);
void base_l_step(struct task *task);
void rest_6_step(struct task *task);
void rest_45_step(struct task *task);
void block_0_step(struct task *task);
void block_1_step(struct task *task);
void block_2_step(struct task *task);
void block_3_step(struct task *task);
void block_4_step(struct task *task);
void block_5_step(struct task *task);
void cover_step(struct task *task);
void screw_step(struct task *task);
void launcher_step(struct task *task);
void block_6_step(struct task *task);
void block_7_step(struct task *task);
void rail_l_step(struct task *task);
void rail_s_step(struct task *task);
void fun_0c90226c(struct task *task);
void lantern_step(struct task *task);
void tower_i_step(struct task *task);
void rest_9_step(struct task *task);
void fun_0c902284(struct task *task);
void cold_fan_step(struct task *task);
void fun_0c902290(struct task *task);
void fun_0c902296(struct task *task);
void fun_0c90229c(struct task *task);
void fun_0c9022a2(struct task *task);
void fun_0c9022a8(struct task *task);
void fun_0c9022ae(struct task *task);
void fun_0c9022b4(struct task *task);
void carrier_step(struct task *task);
void carrier2_step(struct task *task);
void carrier3_step(struct task *task);
void fun_0c9022cc(struct task *task);
void fun_0c9022d2(struct task *task);
void fun_0c9022d8(struct task *task);
void fun_0c9022de(struct task *task);
void fun_0c9022e4(struct task *task);
void ctrltower_step(struct task *task);
void scope_step(struct task *task);
void edge_step(struct task *task);
void la_step(struct task *task);
void lb_step(struct task *task);
void lc_step(struct task *task);
void stop_step(struct task *task);
void s_wing_step(struct task *task);
void s_map_step(struct task *task);
void s_obj_step(struct task *task);
void s_eng_step(struct task *task);
Bool sky_deck_try_leave(struct task *task);
void next_act_step(struct task *task);
void sky_deck_voice_change_act_step(struct task *task);
void sky_deck_change_act_step(struct task *task);
void sky_deck_grip_start(struct task *task);
void hangpole_start(struct task *task);
void cyl_s_start(struct task *task);
void tank_h_start(struct task *task);
void top_0_start(struct task *task);
void radder_start(struct task *task);
void duct_start(struct task *task);
void untei_start(struct task *task);
void fence_l_start(struct task *task);
void fence_m_start(struct task *task);
void fence_s_start(struct task *task);
void hang_a_start(struct task *task);
void hang_b_start(struct task *task);
void hang_c_start(struct task *task);
struct path_owner_vars {
    Uint8 unk_00[4];
    struct path_point *points;
    struct path *path;
};
void trails_reset(void);
void trails_move(void);
void trails_draw(void);
void trail_start(struct task *task);
void trail_step(struct task *task);
void trail_destroy(struct task *task);
void trail_camera_step(struct task *task);
void trail_volume_set(struct task_work *owner, int kind, Bool force,
                      Float radius, Float height, Float x, Float y, Float z);
void t_colli_start(struct task *task);
void t_colli_step(struct task *task);
void t_colli_draw(struct task *task);
void t_colli_destroy(struct task *task);
void scroll_draw(struct task *task);
void draft_reset(void);
void draft_step(Uint16 act);
void w_wall_step(struct task *task);
void flap01_start(struct task *task);
void flap02_start(struct task *task);
void flap_step(struct task *task);
void homing_start(struct task *task);
void homing_step(struct task *task);
void homing_destroy(struct task *task);
struct thread;
enum bitmap_mode { BITMAP_PLAIN, BITMAP_EVENT };
struct bitmap {
    Uint8 mode;
    Sint16 x;
    Sint16 y;
    Uint16 width;
    Uint16 height;
    Uint16 texture_width;
    Uint16 texture_height;
    Sint16 cursor_x;
    Sint16 cursor_y;
    Sint16 letter_spacing;
    Sint16 line_spacing;
    Uint16 ink;
    NJS_COLOR text_color;
    NJS_COLOR back_color;
    Uint16 *pixels;
    Uint32 index;
    NJS_TEXLIST texlist;
    NJS_TEXNAME texname;
};
extern Sint8 messages_shown;
struct bitmap *bitmap_alloc(struct bitmap *bitmap, int x, int y, int width,
                            int height, int index);
void bitmap_free(struct bitmap *bitmap);
struct bitmap *bitmap_init(struct bitmap *bitmap, int x, int y, int width,
                           int height, int index, void *memory);
void bitmap_release(struct bitmap *bitmap);
void bitmap_alloc_window(struct bitmap *bitmap);
void bitmap_init_window(struct bitmap *bitmap);
void bitmap_clear(struct bitmap *bitmap);
void bitmap_newline(struct bitmap *bitmap);
void bitmap_print(struct bitmap *bitmap, const char *text);
void bitmap_printf(struct bitmap *bitmap, const char *format, ...);
void bitmap_queue(struct bitmap *bitmap);
void bitmap_queue_add(struct bitmap *bitmap);
void bitmap_clear_queue(void);
void bitmap_flush_queue(void);
void bitmap_draw(struct bitmap *bitmap);
void bitmap_fade_in(struct bitmap *bitmap);
void bitmap_fade_out(struct bitmap *bitmap);
void bitmap_fade_in_text(struct bitmap *bitmap);
void bitmap_fade_out_text(struct bitmap *bitmap);
void bitmap_wait(struct bitmap *bitmap, int steps);
struct thread *bitmap_choose(const char *text);
struct thread *bitmap_choose_lines(int count, const char **lines);
void bitmap_show_pages(char **pages);
void bitmap_show_pages_until_b(char **pages);
Bool bitmap_pages_active(void);
extern int frame_interval;
extern int frame_countdown;
extern int frame_step_count;
extern int loop_count;
void frame_pacing_init(int interval, int steps);
void frame_set_interval(int interval);
void frame_wait(void);
void frame_wait_step(int left);
void frame_vsync(void);
void fun_8c054be0(void);
void fun_8c054be4(void);
void loader_poll_drive(void);
void loader_note_error(void *obj, Sint32 err);
void loader_read_stage_files(void);
void loader_read_character_motions(int character);
void *loader_read_alloc(char *name, int result);
void loader_free(void *memory);
int loader_read_file(char *name, void *dest);
int loader_read_prs(char *name, void *dest);
int loader_file_size(char *name);
void read_queue_init(void);
int read_queue_selected_slot(void);
Bool read_queue_add(char *name, void *dest);
void read_queue_cancel(void);
void read_queue_serve(void);
extern int debug_page;
extern Bool pause_flg;
void timer_start(void);
Float timer_lap(void);
void timer_mark(void);
Float timer_elapsed(void);
Float timer_elapsed_and_mark(void);
Float timer_render_time(void);
void timer_show_counts(void);
extern Uint32 ruin_fog_color;
extern NJS_FOG_TABLE ruin_fog;
static void act_idle(void);
void FUN_8c051900(void);
void FUN_8c051928(void);
void FUN_8c05193a(void);
void mystic_ruins_set_fog(void);
extern int frame_interval;
extern int frame_countdown;
extern int frame_step_count;
extern int loop_count;
static void (*act_hooks[(43 + 1)][8])(void) = {
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {FUN_8c051900, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {FUN_8c051928, FUN_8c051928, FUN_8c051928, act_idle, act_idle},
    {act_idle, FUN_8c05193a, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, mystic_ruins_set_fog, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
    {act_idle, act_idle, act_idle, act_idle, act_idle, act_idle},
};
void frame_pacing_init(int interval, int steps)
{
    frame_interval = interval;
    frame_countdown = frame_interval;
    frame_step_count = steps;
    loop_count = 0;
    njSetVSyncFunction(frame_vsync);
    bitmap_clear_queue();
}
void frame_set_interval(int interval)
{
    frame_interval = interval;
    frame_countdown = frame_interval;
}
void frame_wait(void)
{
    while (frame_countdown > 0) {
    }
    frame_countdown = frame_interval;
    if (pause_flg == (1)) {
        kmResetPointer();
    } else {
        bitmap_flush_queue();
        _nj_wait_vsync_in_ = syTmrGetCount();
        kmRender();
        _nj_calc_vertex_ = 0;
        _nj_calc_polygon_ = 0;
        _nj_draw_polygon_ = 0;
        _nj_vsync_count_++;
        kmFlipFrameBuffer();
    }
    pdExecPeripheralServerUser();
    _nj_wait_vsync_out_ = syTmrGetCount();
}
void frame_wait_step(int left)
{
    while (frame_countdown > left) {
    }
    pdExecPeripheralServerUser();
    sound_send_queue();
}
static void act_idle(void)
{
}
extern int game_mode;
void frame_vsync(void)
{
    int mode;
    Uint16 stage_act;
    Uint16 act;
    Uint16 stage;
    frame_countdown--;
    if (frame_countdown == 0) {
        stage_act = GetStageNumber();
        act = stage_act & 0xff;
        stage = (((stage_act) & 0xff00) >> 8);
        mode = game_mode;
        if (mode == 4 || mode == 5 || mode == 9) {
            act_hooks[stage][act]();
        }
        FUN_8c643ed8();
    }
    buExecServer();
    loader_poll_drive();
}
void FUN_8c051900(void)
{
    Uint32 color;
    color = windy_fog_shown;
    if (!demo_playing || color == 0xffffffff) {
        CHAOS_SetChaosNo(color);
        kmSetFogTable(windy_fog_table);
    }
}
void FUN_8c051928(void)
{
    CHAOS_SetChaosNo(sky_deck_fog_color);
    kmSetFogTable(sky_deck_fog_table);
}
void FUN_8c05193a(void)
{
    CHAOS_SetChaosNo(ruin_fog_color);
    kmSetFogTable(ruin_fog);
}
void mystic_ruins_set_fog(void)
{
    kmSetFogTable(jungle_fog_table);
    CHAOS_SetChaosNo(jungle_fog_shown);
}
void fun_8c054be0(void)
{
}
void fun_8c054be4(void)
{
}
