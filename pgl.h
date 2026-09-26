#pragma once

typedef enum
{
	setTCC = 0x0,
	setTFX = 0x1,
	setMMIN = 0x2,
	setMMAX = 0x3,
	setWMS = 0x4,
	setWMT = 0x5,
	setLCM_LightColorMatrix = 0x6,
	setK = 0x8,
	setL = 0x9,
} pgluParamType;


typedef enum
{
	PGL_PrimTME_Textured = 0x2,
	PGL_TEST_DestinationAlphaTest = 0x3,
	PGL_TEST_AlphaTest = 0x4,
	PGL_TEST_DepthTest = 0x5,
	PGL_PrimABE_AlphaBlend = 0x6,
	PGL_7 = 0x7,
	PGL_PrimFGE_Fogging = 0x8,
	PGL_PrimAA1_Antialiasing = 0x9,
	PGL_10 = 0xA,
	PGL_11 = 0xB,
	PGL_12 = 0xC,
	PGL_13 = 0xD,
	PGL_14 = 0xE,
	PGL_CullMode = 0xF,
	PGL_16 = 0x10,
	PGL_17 = 0x11,
	PGL_Scissor = 0x12,
	PGL_19 = 0x13,
	PGL_20 = 0x14,
	PGL_21 = 0x15,
	PGL_Display1Y = 0x16,
	PGL_Display1X = 0x17,
	PGL_LightUnk1 = 0x65,
	PGL_LightUnk2 = 0x66,
	PGL_LightUnk3 = 0x67,
	PGL_LightUnk4 = 0x68,
	PGL_LightUnk5 = 0x69,
	PGL_LightUnk6 = 0x6A,
	PGL_LightUnk7 = 0x6B,
	PGL_LightUnk8 = 0x6C,
} pglFlags;

typedef struct
{
	float x;
	float y;
	float z;
} MathVector3;

typedef struct
{
	float x;
	float y;
	float z;
} MathVector2;

#define ADDR_pglAccum 0x005A0410
#define ADDR_pglAccumBuffer 0x0059EC40
#define ADDR_pglAllocatePacket 0x005A26E0
#define ADDR_pglAlphaFail 0x0059EFF8
#define ADDR_pglAlphaFunc1ub 0x0059F0E8
#define ADDR_pglAppendGIFPacket 0x005A2700
#define ADDR_pglAppendImagePacket 0x005A8638
#define ADDR_pglApplyDepthBias_Guessed 0x0059EDC0
#define ADDR_pglApplyMatrix 0x005A45B0
#define ADDR_pglBeginStrip 0x00598AC8
#define ADDR_pglBlendFunc 0x0059F038
#define ADDR_pglBlendFunc1ub 0x0059F138
#define ADDR_pglClear 0x0059FBC0
#define ADDR_pglClearColor 0x0059F870
#define ADDR_pglClearColor1ui 0x0059F8A8
#define ADDR_pglClearDepth 0x0059F8B8
#define ADDR_pglClutBuffer 0x005A15B8
#define ADDR_pglClutLoad 0x005A13A8
#define ADDR_pglClutOffset 0x005A16D0
#define ADDR_pglColor 0x005A6B20
#define ADDR_pglColor4f 0x005A6B90
#define ADDR_pglColor4ftoi 0x005A6A88
#define ADDR_pglColorBuffer 0x0059ECA8
#define ADDR_pglColorMask1ui 0x0059F1B0
#define ADDR_pglCounterMatrix 0x005A4620
#define ADDR_pglCullFace 0x0059E1D0
#define ADDR_pglCylinderMapAxis 0x0059BFD8
#define ADDR_pglCylinderMapHint 0x0059BFA0
#define ADDR_pglCylinderMapT 0x0059BE40
#define ADDR_pglDMABuffer 0x0059E220
#define ADDR_pglDepthBias 0x0059F850
#define ADDR_pglDepthBuffer 0x0059EE20
#define ADDR_pglDepthFunc 0x0059EF20
#define ADDR_pglDepthMask 0x0059F1D8
#define ADDR_pglDestinationAlphaFunc 0x0059F088
#define ADDR_pglDisable 0x005A79F8
#define ADDR_pglDisplayMask 0x0059D130
#define ADDR_pglDisplayMode 0x0059D028
#define ADDR_pglDisplayResolution 0x0059D3D0
#define ADDR_pglDisplayViewport 0x0059D398
#define ADDR_pglDitherMatrix 0x0059DBE8
#define ADDR_pglEnable 0x0059DE58
#define ADDR_pglEndFrameMaybe 0x0059E4C8
#define ADDR_pglEndStrip 0x00598B08
#define ADDR_pglExecute 0x0059DA18
#define ADDR_pglExit 0x0059CF58
#define ADDR_pglFinish 0x0059E8F8
#define ADDR_pglFlush 0x0059C648
#define ADDR_pglFlushCache 0x005A6E58
#define ADDR_pglFog 0x005A0B28
#define ADDR_pglFogColor 0x005A0A10
#define ADDR_pglFogColor1ui 0x005A0AC8
#define ADDR_pglFree 0x005A7070
#define ADDR_pglFrontFace 0x0059E1F8
#define ADDR_pglGetColor1ui 0x005A4730
#define ADDR_pglGetColorBuffer 0x005A47A8
#define ADDR_pglGetCullFace 0x005A47D8
#define ADDR_pglGetField 0x005A4768
#define ADDR_pglGetFogColor1ui 0x005A4708
#define ADDR_pglGetViewport 0x005A47E8
#define ADDR_pglGetWorkPage 0x005A79E8
#define ADDR_pglInit 0x0059CBB8
#define ADDR_pglInverse_0 0x005A455C
#define ADDR_pglIsInFrame 0x0059D018
#define ADDR_pglLightModelfv 0x005A2830
#define ADDR_pglLightfv 0x005A2768
#define ADDR_pglLoadIdentity 0x005A3F5C
#define ADDR_pglLoadIdentityTranslate 0x005A3FA8
#define ADDR_pglLoadMatrix 0x005A3FBC
#define ADDR_pglLock 0x0059CEB0
#define ADDR_pglMatrixMode 0x005A1ED8
#define ADDR_pglMultMatrix 0x005A41A0
#define ADDR_pglMultMatrixLeft 0x005A427C
#define ADDR_pglNewFrame 0x0059E3E0
#define ADDR_pglObjectScale 0x005A4408
#define ADDR_pglOrtho 0x005A2600
#define ADDR_pglPixelCenter 0x0059F340
#define ADDR_pglPixelDomain 0x0059F388
#define ADDR_pglPoolMode 0x0059E2D0
#define ADDR_pglPopAttrib 0x005A21F8
#define ADDR_pglPopMatrix 0x005A1E08
#define ADDR_pglPushAttrib 0x005A1F88
#define ADDR_pglPushMatrix 0x005A1DB0
#define ADDR_pglResetCache 0x005A6E30
#define ADDR_pglRotate 0x005A40E0
#define ADDR_pglRotateX 0x005A4490
#define ADDR_pglRotateY 0x005A44B8
#define ADDR_pglRotateZ 0x005A44E0
#define ADDR_pglSaveSkinningMatrix 0x005A4668
#define ADDR_pglScale 0x005A4398
#define ADDR_pglScanMask 0x005A2B50
#define ADDR_pglScissor 0x0059F698
#define ADDR_pglSetTexCoords 0x0059C230
#define ADDR_pglSignalSema 0x0059D758
#define ADDR_pglStoreMatrix 0x005A4058
#define ADDR_pglStrip 0x00598FF0
#define ADDR_pglSyncDMA 0x0059EC20
#define ADDR_pglSyncV 0x0059EAF0
#define ADDR_pglTaggedAllocate 0x005A6F28
#define ADDR_pglTexFlush 0x005A1388
#define ADDR_pglTexGenf 0x0059BBC0
#define ADDR_pglTexImage 0x00597BC0
#define ADDR_pglTexParameter 0x00597EF8
#define ADDR_pglTexRegion 0x00598070
#define ADDR_pglTranslate 0x005A434C
#define ADDR_pglTriangleStrip 0x0059C2D8
#define ADDR_pglTriangleStrip_0 0x0059C5C0
#define ADDR_pglUnkEnableSomething 0x00598370
#define ADDR_pglUnlock 0x0059CF10
#define ADDR_pglVariableColorOffset 0x005A2C70
#define ADDR_pglVariableColorScale 0x005A2C50
#define ADDR_pglViewport 0x0059F550
#define ADDR_pglWaitSema 0x0059D728
#define ADDR_pglWcLine2i 0x005A35F8
#define ADDR_pglWcRect2i 0x005A2CB0
#define ADDR_pglWcSliceRect2i 0x005A2DF0
#define ADDR_pglWcSliceSprite2f 0x005A3280
#define ADDR_pglWcSprite2f 0x005A3078
#define ADDR_pglWritePixelsImm 0x005A1B28
#define ADDR_pglWritePixelsPath1 0x005A1848
#define ADDR_pglWritePixelsPath3 0x005A19B0
#define ADDR_pgl_SetGSControlRegister 0x005AA5E8
#define ADDR_pglmRandomSeed 0x005AA30C
#define ADDR_pgluApplyClutAnimation 0x00595E30
#define ADDR_pgluApplyClutPatch 0x00595BB8
#define ADDR_pgluApplyMaterial_GUESSED 0x0059ABD0
#define ADDR_pgluCacheGetSize 0x005A7008
#define ADDR_pgluCacheTexSetPath3 0x00596640
#define ADDR_pgluCallShape 0x0059A580
#define ADDR_pgluCallTstrip 0x00593E30
#define ADDR_pgluComputeTexSize 0x00598148
#define ADDR_pgluCopyPixelsToAlpha 0x005A5DC0
#define ADDR_pgluCustomizeShimmer 0x005923E0
#define ADDR_pgluDepthOffset 0x00597A80
#define ADDR_pgluExternalMatIndex 0x00599D28
#define ADDR_pgluExternalTexIndex 0x00599D70
#define ADDR_pgluField 0x0059F240
#define ADDR_pgluFontFacePDI 0x0033CDB8
#define ADDR_pgluGammaCorrection 0x005A4898
#define ADDR_pgluInitShimmer 0x00592320
#define ADDR_pgluJitter 0x0059F488
#define ADDR_pgluLoadIdentityClut 0x005A5C70
#define ADDR_pgluMapShape 0x005959F8
#define ADDR_pgluMapTexSet 0x00595A40
#define ADDR_pgluMatTable 0x00599D58
#define ADDR_pgluMaterialFunc 0x00599DB8
#define ADDR_pgluRandomFloat_Guessed 0x00591EB0
#define ADDR_pgluRandomize 0x00591EA0
#define ADDR_pgluReflection 0x005979A8
#define ADDR_pgluRelocateTexSet 0x00595740
#define ADDR_pgluResetClutAnimation_0 0x00596288
#define ADDR_pgluSetVertColors 0x0059C1D8
#define ADDR_pgluSetupFontFacePDI 0x005967C0
#define ADDR_pgluSetupKanjiImagePDI 0x00596A78
#define ADDR_pgluShapeCallback 0x00599B50
#define ADDR_pgluShapeTweenRatio 0x005A4648
#define ADDR_pgluShimmer 0x005924D0
#define ADDR_pgluShimmerMove 0x00592470
#define ADDR_pgluSignalClutAnimation 0x00596210
#define ADDR_pgluTexImage 0x005A0B78
#define ADDR_pgluTexIsCachedMaybe 0x005A7140
#define ADDR_pgluTexParameter 0x005A0FC8
#define ADDR_pgluTexRegion_SetClampSettings 0x005A1288
#define ADDR_pgluTexReset 0x00597B98
#define ADDR_pgluTexSize 0x00597E28
#define ADDR_pgluTexSize_setTW_TH 0x005A0E90
#define ADDR_pgluTexTable 0x00599DA0
#define ADDR_pgluTexture 0x00599B60
#define ADDR_pgluTriangleList2fv 0x005995E0
#define ADDR_pgluTriangleStrip2fv 0x00599A80
#define ADDR_pgluTriangleStrip3fv 0x0059C570
#define ADDR_pgluUpdateClutAnimation 0x00595EA0
#define ADDR_pgluWeirdTextureThingWithSizes 0x005A1720
#define ADDR_pgluWriteKanjiImagePDI 0x00596B60

// dma channel is 0 = VIF0, 1 = VIF1, 2 = GIF

void (*pglLoadIdentity)() = (void*)ADDR_pglLoadIdentity;
void (*pglEnable)(pglFlags) = (void*)ADDR_pglEnable;
void (*pglDisable)(pglFlags) = (void*)ADDR_pglDisable;
void (*pglAccum)(int, float) = (void*)ADDR_pglAccum;
void (*pglAccumBuffer)(unsigned int, char, int, int) = (void*)ADDR_pglAccumBuffer;
void (*pglAllocatePacket)(unsigned int) = (void*)ADDR_pglAllocatePacket;
void (*pglAlphaFail)(unsigned int) = (void*)ADDR_pglAlphaFail;
void (*pglAlphaFunc1ub)(char val, unsigned char val2) = (void*)ADDR_pglAlphaFunc1ub;
void (*pgluTriangleStrip3fv)(int, MathVector3*, MathVector3*, MathVector3*, int*) = (void*)ADDR_pgluTriangleStrip3fv;
void (*pglColor)(unsigned int) = (void*)ADDR_pglColor;
void (*pglColor4f)(float, float, float, float) = (void*)ADDR_pglColor4f;
void (*pglColor4ftoi)(float, float, float, float) = (void*)ADDR_pglColor4ftoi;
void (*pglGetViewport)(float*, float*, float*, float*) = (void*)ADDR_pglGetViewport;
void (*pglAppendGIFPacket)(unsigned long long) = (void*)ADDR_pglAppendGIFPacket;
void (*pglAppendImagePacket)(unsigned long long) = (void*)ADDR_pglAppendImagePacket;
void (*pglApplyMatrix)(float*, float*) = (void*)ADDR_pglApplyMatrix;
void (*pglBeginStrip)() = (void*)ADDR_pglBeginStrip;
void (*pglBlendFunc1ub)() = (void*)ADDR_pglBlendFunc1ub;
void (*pglClear)() = (void*)ADDR_pglClear;
void (*pglClearColor)(float, float, float, float) = (void*)ADDR_pglClearColor;
void (*pglClearColor1ui)(unsigned int) = (void*)ADDR_pglClearColor1ui;
void (*pglClearDepth)(float) = (void*)ADDR_pglClearDepth;
void (*pglClutBuffer)(int, unsigned long long) = (void*)ADDR_pglClutBuffer;
void (*pglClutLoad)(int) = (void*)ADDR_pglClutLoad;
void (*pglClutOffset)(char) = (void*)ADDR_pglClutOffset;
void (*pglColorBuffer)(unsigned int tbp, char tbw, int a3, int a4) = (void*)ADDR_pglColorBuffer;
void (*pglColorMask1ui)(unsigned int color) = (void*)ADDR_pglColorMask1ui;
void (*pglCounterMatrix)(float* matrix) = (void*)ADDR_pglCounterMatrix;
void (*pglCullFace)(int mode) = (void*)ADDR_pglCullFace;
void (*pglCylinderMapAxis)(float, float, float, float, float, float) = (void*)ADDR_pglCylinderMapAxis;
void (*pglCylinderMapHint)(float, float, float) = (void*)ADDR_pglCylinderMapHint;
void (*pglCylinderMapT)(float, float) = (void*)ADDR_pglCylinderMapT;
void (*pglDMABuffer)(int, int) = (void*)ADDR_pglDMABuffer;
void (*pglDepthBias)(float) = (void*)ADDR_pglDepthBias;
void (*pglDepthBuffer)(unsigned int a1, unsigned int a2) = (void*)ADDR_pglDepthBuffer;
void (*pglDepthMask)(char a1) = (void*)ADDR_pglDepthMask;
void (*pglDestinationAlphaFunc)(int gsTestValue) = (void*)ADDR_pglDestinationAlphaFunc;
void (*pglDisplayMask)(char enableDisplayMask) = (void*)ADDR_pglDisplayMask;
void (*pglDisplayMode)(int a1, int outputMode, int a3) = (void*)ADDR_pglDisplayMode;
void (*pglDisplayResolution)(short width, short height) = (void*)ADDR_pglDisplayResolution;
void (*pglDisplayViewport)(short x, short y, short width, short height) = (void*)ADDR_pglDisplayViewport;
void (*pglDitherMatrix)(int*) = (void*)ADDR_pglDitherMatrix;
void (*pglEndStrip)() = (void*)ADDR_pglEndStrip;
void (*pglExit)() = (void*)ADDR_pglExit;
void (*pglFinish)() = (void*)ADDR_pglFinish;
void (*pglFlush)() = (void*)ADDR_pglFlush;
void (*pglFlushCache)() = (void*)ADDR_pglFlush;
void (*pglFog)(float, float) = (void*)ADDR_pglFog;
void (*pglFogColor)(float r, float g, float b) = (void*)ADDR_pglFogColor;
void (*pglFogColor1ui)(int fogcol, unsigned int color) = (void*)ADDR_pglFogColor1ui;
void (*pglFrontFace)(int a1) = (void*)ADDR_pglFrontFace;
void (*pglFree)(int a1) = (void*)ADDR_pglFree;
int (*pglGetColor1ui)() = (void*)ADDR_pglGetColor1ui;
void (*pglGetColorBuffer)(int*, int*, int*, int*) = (void*)ADDR_pglGetColorBuffer;
int (*pglGetCullFace)() = (void*)ADDR_pglGetCullFace;
int (*pglGetField)(int) = (void*)ADDR_pglGetField;
unsigned int (*pglGetFogColor1ui)(int) = (void*)ADDR_pglGetFogColor1ui;
int (*pglGetWorkPage)() = (void*)ADDR_pglGetWorkPage;
void (*pglInit)() = (void*)ADDR_pglInit;
void (*pglInverse_0)(float* matrix) = (void*)ADDR_pglInverse_0;
char (*pglIsInFrame)() = (void*)ADDR_pglIsInFrame;
void (*pglLightModelfv)(int sides, float*) = (void*)ADDR_pglLightModelfv;
void (*pglLightfv)(int unkMode, int a2, int a3) = (void*)ADDR_pglLightfv;
void (*pglLoadIdentityTranslate)(float* matrix) = (void*)ADDR_pglLoadIdentityTranslate;
void (*pglLoadMatrix)() = (void*)ADDR_pglLoadMatrix;
void (*pglLock)() = (void*)ADDR_pglLock;
void (*pglMatrixMode)(int mode) = (void*)ADDR_pglMatrixMode;
void (*pglMultMatrix)(float* matrix) = (void*)ADDR_pglMultMatrix;
void (*pglMultMatrixLeft)(float* matrix) = (void*)ADDR_pglMultMatrixLeft;
void (*pglNewFrame)() = (void*)ADDR_pglNewFrame;
void (*pglObjectScale)(float a1, float a2, float a3) = (void*)ADDR_pglObjectScale;
void (*pglOrtho)(float, float, float, float, float, float) = (void*)ADDR_pglOrtho;
void (*pglPixelCenter)(float a1, float a2) = (void*)ADDR_pglPixelCenter;
void (*pglPixelDomain)(float a1, float a2, float a3) = (void*)ADDR_pglPixelDomain;
void (*pglPoolMode)(int mode) = (void*)ADDR_pglPoolMode;
void (*pglPopAttrib)() = (void*)ADDR_pglPopAttrib;
void (*pglPopMatrix)() = (void*)ADDR_pglPopMatrix;
void (*pglPushAttrib)(int attrib) = (void*)ADDR_pglPushAttrib; // 0x40 = fog, 0x800 = scissor, 0x02 = depth test, 0x01 = ?, 0x04 = ?
void (*pglPushMatrix)() = (void*)ADDR_pglPushMatrix;
void (*pglResetCache)() = (void*)ADDR_pglResetCache;
void (*pglRotate)(float x, float y, float z, float w) = (void*)ADDR_pglRotate;
void (*pglRotateX)(float x) = (void*)ADDR_pglRotateX;
void (*pglRotateY)(float y) = (void*)ADDR_pglRotateY;
void (*pglRotateZ)(float z) = (void*)ADDR_pglRotateZ;
void (*pglSaveSkinningMatrix)(int a1, int a2) = (void*)ADDR_pglSaveSkinningMatrix;
void (*pglScale)(float x, float y, float z) = (void*)ADDR_pglScale;
void (*pglScanMask)(int scanMskOp) = (void*)ADDR_pglScanMask;
void (*pglScissor)(int x, int y, int w, int h) = (void*)ADDR_pglScissor;
void (*pglSetTexCoords)(int a1, int texCoords, int count) = (void*)ADDR_pglSetTexCoords;
void (*pglSignalSema)(int dmaChannel) = (void*)ADDR_pglSignalSema;
void (*pglStoreMatrix)(float* matrix) = (void*)ADDR_pglStoreMatrix;
void (*pglStrip)(int num, float* vertices, float* texcoords, float* normals, int* a5, int* a6) = (void*)ADDR_pglStrip;
void (*pglSyncDMA)() = (void*)ADDR_pglSyncDMA;
void (*pglSyncV)(int a1) = (void*)ADDR_pglSyncV;
void (*pglTaggedAllocate)(int a1, int a2) = (void*)ADDR_pglTaggedAllocate;
void (*pglTexFlush)() = (void*)ADDR_pglTexFlush;
void (*pglTexGenf)(int unkMode, float value) = (void*)ADDR_pglTexGenf;
void (*pglTexImage)(void* pgluTex, int mipmapLevel, unsigned int actualOffset, char a4, int tbwActual) = (void*)ADDR_pglTexImage;
void (*pglTexParameter)(void* pgluTex, pgluParamType paramType, short value) = (void*)ADDR_pglTexParameter;
void (*pglTexRegion)(void* pgluTex, int a2, short x, short y) = (void*)ADDR_pglTexRegion; // a2 is min or max bool?
void (*pglTranslate)(float x, float y, float z) = (void*)ADDR_pglTranslate;
void (*pglTriangleStrip)(void* dmaThing, float* vertices, float* unused, unsigned int* colors, 
	float* texcoordUV, int numVertex, char useTrifanInsteadOfStrip) = (void*)ADDR_pglTriangleStrip;
void (*pglTriangleStrip_0)(float* vertices, float* unused, unsigned int* colors, float* texcoordUV, int numVertex) = (void*)ADDR_pglTriangleStrip_0;
void (*pglUnkEnableSomething)() = (void*)ADDR_pglUnkEnableSomething;
void (*pglUnlock)() = (void*)ADDR_pglUnlock;
void (*pglVariableColorOffset)(float r, float g, float b, float a) = (void*)ADDR_pglVariableColorOffset;
void (*pglVariableColorScale)(float r, float g, float b, float a) = (void*)ADDR_pglVariableColorScale;
void (*pglViewport)(float x, float y, float w, float h) = (void*)ADDR_pglViewport;
void (*pglWaitSema)(int dmaChannel) = (void*)ADDR_pglWaitSema;
void (*pglWcLine2i)(int x1, int y1, int x2, int y2) = (void*)ADDR_pglWcLine2i;
void (*pglWcRect2i)(int x, int y, int w, int h) = (void*)ADDR_pglWcRect2i;
void (*pglWcSliceRect2i)(int x, int y, int w, int h) = (void*)ADDR_pglWcSliceRect2i;
void (*pglWcSliceSprite2f)(int x, int y, float a3, float a4, int a5, float a6, int a7, float a8) = (void*)ADDR_pglWcSliceSprite2f;
void (*pglWcSprite2f)(float a1, float a2, float a3, int a4, float a5, int a6, float a7) = (void*)ADDR_pglWcSprite2f;
void (*pglWritePixelsImm)(unsigned int a1, int a2, int a3, int a4, int a5, int a6, int a7) = (void*)ADDR_pglWritePixelsImm;
void (*pglWritePixelsPath1)(unsigned int a1, int a2, int a3, int a4, int a5, int width, int height, int* a8) = (void*)ADDR_pglWritePixelsPath1;
void (*pglWritePixelsPath3)(unsigned int a1, int format, int unkType, int a4, int a5, int width, int height, int* a8) = (void*)ADDR_pglWritePixelsPath3;
void (*pgl_SetGSControlRegister)(short a1, short a2, short a3, short a4) = (void*)ADDR_pgl_SetGSControlRegister;
void (*pglmRandomSeed)(float val) = (void*)ADDR_pglmRandomSeed;
void (*pgluApplyClutAnimation)(void*) = (void*)ADDR_pgluApplyClutAnimation;
void (*pgluApplyClutPatch)(void* pgluTexSet, void* clutPatch) = (void*)ADDR_pgluApplyClutPatch;
int (*pgluCacheGetSize)(int texSize, void* pgluTexSet) = (void*)ADDR_pgluCacheGetSize;
void (*pgluCacheTexSetPath3)(void* pgluTexSet) = (void*)ADDR_pgluCacheTexSetPath3;
void (*pgluCallShape)(void* pgluShape) = (void*)ADDR_pgluCallShape;
void (*pgluCallTstrip)(int a1, int a2, float a3, float a4, float a5, float a6) = (void*)ADDR_pgluCallTstrip;
int (*pgluComputeTexSize)(int format, int w, int h, int* outUnk) = (void*)ADDR_pgluComputeTexSize;
void (*pgluCopyPixelsToAlpha)(unsigned int a1, unsigned int a2, unsigned int a3, int a4, int a5) = (void*)ADDR_pgluCopyPixelsToAlpha;
void (*pgluCustomizeShimmer)(int a1, float a2, float a3, float a4, float a5, float a6) = (void*)ADDR_pgluCustomizeShimmer;
void (*pgluDepthOffset)(float value) = (void*)ADDR_pgluDepthOffset;
void (*pgluExternalMatIndex)(int idx) = (void*)ADDR_pgluExternalMatIndex;
void (*pgluExternalTexIndex)(int idx) = (void*)ADDR_pgluExternalTexIndex;
void (*pgluField)(int field) = (void*)ADDR_pgluField;
void (*pgluFontFacePDI)(/* 11 arguments.. */) = (void*)ADDR_pgluFontFacePDI;
void (*pgluGammaCorrection)(int a1, float a2) = (void*)ADDR_pgluGammaCorrection;
void (*pgluInitShimmer)(unsigned int a1, int a2, int a3) = (void*)ADDR_pgluInitShimmer;
void (*pgluJitter)(int a1, int a2) = (void*)ADDR_pgluJitter;
void (*pgluLoadIdentityClut)(int a1) = (void*)ADDR_pgluLoadIdentityClut;
void (*pgluMapShape)(void* pgluShape) = (void*)ADDR_pgluMapShape;
void (*pgluMapTexSet)(void* pgluTexSet) = (void*)ADDR_pgluMapTexSet;
void (*pgluMatTable)(int tableIdx) = (void*)ADDR_pgluMatTable;
void (*pgluMaterialFunc)(int packedBits) = (void*)ADDR_pgluMaterialFunc; // 9 bits tex index, upper 7 bits mat index 
float (*pgluRandomFloat_Guessed)() = (void*)ADDR_pgluRandomFloat_Guessed;
void (*pgluRandomize)(int value) = (void*)ADDR_pgluRandomize;
void (*pgluReflection)(float a1, float a2, float a3, float a4, float a5, float a6) = (void*)ADDR_pgluReflection;
void (*pgluRelocateTexSet)(void* pgluTexSet, unsigned int baseFrameBufferPos) = (void*)ADDR_pgluRelocateTexSet;
void (*pgluResetClutAnimation_0)(void* a1, int a2) = (void*)ADDR_pgluResetClutAnimation_0;
void (*pgluSetVertColors)(void* dmaThing, unsigned int* colors, int numColors) = (void*)ADDR_pgluSetVertColors;
void (*pgluSetupFontFacePDI)(void*) = (void*)ADDR_pgluSetupFontFacePDI;
void (*pgluSetupKanjiImagePDI)(int offset, int format, int a3, int a4, int a5, int width, int height) = (void*)ADDR_pgluSetupKanjiImagePDI;
void (*pgluShapeCallback)(void* callback) = (void*)ADDR_pgluShapeCallback;
void (*pgluShapeTweenRatio)(float tweenRatio) = (void*)ADDR_pgluShapeTweenRatio;
void (*pgluShimmer)(void* unkMatrixMaybe) = (void*)ADDR_pgluShimmer;
void (*pgluShimmerMove)(void* unk) = (void*)ADDR_pgluShimmerMove;
void (*pgluSignalClutAnimation)(void* unk, int a2) = (void*)ADDR_pgluSignalClutAnimation;
void (*pgluTexImage)(int mipLevel, unsigned int offset, char format, int a4) = (void*)ADDR_pgluTexImage;
char (*pgluTexIsCachedMaybe)(void*) = (void*)ADDR_pgluTexIsCachedMaybe;
void (*pgluTexParameter)(pgluParamType param, int value) = (void*)ADDR_pgluTexParameter;
void (*pgluTexRegion_SetClampSettings)(int unkMode, short x, short y) = (void*)ADDR_pgluTexRegion_SetClampSettings;
void (*pgluTexReset)(void* pgluTex) = (void*)ADDR_pgluTexReset;
void (*pgluTexSize)(void* pgluTex, short width, short height) = (void*)ADDR_pgluTexSize;
void (*pgluTexSize_setTW_TH)(int tw, int th) = (void*)ADDR_pgluTexSize_setTW_TH;
void (*pgluTexTable)(void* pgluTex) = (void*)ADDR_pgluTexTable;
void (*pgluTexture)(void* pgluTex) = (void*)ADDR_pgluTexture;
void (*pgluTriangleList2fv)(int numVerts, void* a2, void* a3, void* a4) = (void*)ADDR_pgluTriangleList2fv;
void (*pgluTriangleStrip2fv)(int numVerts, float*  vertices, int* a3, int* a4) = (void*)ADDR_pgluTriangleStrip2fv;
void (*pgluUpdateClutAnimation)(void*, void*, float) = (void*)ADDR_pgluUpdateClutAnimation;
void (*pgluWriteKanjiImagePDI)(void* a1) = (void*)ADDR_pgluWriteKanjiImagePDI;

/// <summary>
/// Controls GS ALPHA_1
/// </summary>
void (*pglBlendFunc)(unsigned int, float) = (void*)ADDR_pglBlendFunc;
#define ADDR__PDISTD_FontManagerClass_putstring 0x33B740
#define ADDR__PDISTD_FontManagerClass_setRegion 0x33B418
#define ADDR__PDISTD_FontManagerClass_setFont 0x33AF90
#define ADDR__PDISTD_FontManagerClass_printf 0x33B6B0
typedef struct
{
	char Empty[0x2C];
	void* FontSet;
	void* Kanji;
	float UnkWidth; // 0x34
	float UnkHeight; // 0x38
	char Empty2[0x20]; // 0x3C
	unsigned int Color; // 0x5C
	int field_0x60;
	int IsAligned;
	int field_0x68;
	int RegionX1;
	int RegionY1;
	int RegionX2;
	int RegionY2;
	int AlignMode;
} FontManagerClass;
void (*PDISTD_FontManagerClass_putstring)(FontManagerClass*, char*) = (void*)ADDR__PDISTD_FontManagerClass_putstring;
void (*PDISTD_FontManagerClass_printf)(FontManagerClass*, char*, ...) = (void*)ADDR__PDISTD_FontManagerClass_printf;
void (*PDISTD_FontManagerClass_setRegion)(FontManagerClass*, int, int, int, int) = (void*)ADDR__PDISTD_FontManagerClass_setRegion;
void (*PDISTD_FontManagerClass_setFont)(FontManagerClass*, char*) = (void*)ADDR__PDISTD_FontManagerClass_setFont;