#ifndef MTR_TEXTURE_BINDING_COMMON_H
#define MTR_TEXTURE_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_TextureFunctionSupportedFunc)(const char *);
MTR_TextureFunctionSupportedFunc MTR_TextureFunctionSupported;

typedef bool (MTR_CALL * MTR_TextureInitFunc)(uint32_t, uint32_t);
MTR_TextureInitFunc MTR_TextureInit;

typedef void (MTR_CALL * MTR_TextureBeginTargetFunc)(int);
MTR_TextureBeginTargetFunc MTR_TextureBeginTarget;

typedef void (MTR_CALL * MTR_TextureEndTargetFunc)(void);
MTR_TextureEndTargetFunc MTR_TextureEndTarget;

typedef int (MTR_CALL * MTR_TextureGetWidthFunc)(uint32_t);
MTR_TextureGetWidthFunc MTR_TextureGetWidth;

typedef int (MTR_CALL * MTR_TextureGetHeightFunc)(uint32_t);
MTR_TextureGetHeightFunc MTR_TextureGetHeight;

#ifdef lua_h
typedef void (MTR_CALL * MTR_TextureGetSizesFunc)(uint32_t, int *, int *);
MTR_TextureGetSizesFunc MTR_TextureGetSizes;
#endif

typedef uint32_t (MTR_CALL * MTR_TextureCreateFunc)(const char *, int, int);
MTR_TextureCreateFunc MTR_TextureCreate;

typedef uint32_t (MTR_CALL * MTR_TextureLoadFunc)(const char *);
MTR_TextureLoadFunc MTR_TextureLoad;

typedef uint32_t (MTR_CALL * MTR_TextureCopyFunc)(uint32_t);
MTR_TextureCopyFunc MTR_TextureCopy;

typedef bool (MTR_CALL * MTR_TextureSaveFunc)(uint32_t, const char *);
MTR_TextureSaveFunc MTR_TextureSave;

typedef void (MTR_CALL * MTR_TextureFreeFunc)(uint32_t);
MTR_TextureFreeFunc MTR_TextureFree;

typedef void (MTR_CALL * MTR_TextureSetModulation_cFunc)(uint32_t, uint32_t);
MTR_TextureSetModulation_cFunc MTR_TextureSetModulation_c;

typedef void (MTR_CALL * MTR_TextureSetModulation_caFunc)(uint32_t, uint32_t);
MTR_TextureSetModulation_caFunc MTR_TextureSetModulation_ca;

typedef void (MTR_CALL * MTR_TextureSetModulation_rgbFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t);
MTR_TextureSetModulation_rgbFunc MTR_TextureSetModulation_rgb;

typedef void (MTR_CALL * MTR_TextureSetModulation_rgbaFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_TextureSetModulation_rgbaFunc MTR_TextureSetModulation_rgba;

typedef void (MTR_CALL * MTR_TextureSetModulationAlphaFunc)(uint32_t, uint8_t);
MTR_TextureSetModulationAlphaFunc MTR_TextureSetModulationAlpha;

typedef void (MTR_CALL * MTR_TextureSetModulationAlpha_fFunc)(uint32_t, float);
MTR_TextureSetModulationAlpha_fFunc MTR_TextureSetModulationAlpha_f;

typedef void (MTR_CALL * MTR_TextureSetBlendFunctionFunc)(uint32_t, int, int,
 int, int);
MTR_TextureSetBlendFunctionFunc MTR_TextureSetBlendFunction;

typedef void (MTR_CALL * MTR_TextureSetAlphaBlendingFunc)(uint32_t, bool);
MTR_TextureSetAlphaBlendingFunc MTR_TextureSetAlphaBlending;

typedef void (MTR_CALL * MTR_TextureBlit_fFunc)(uint32_t, float, float);
MTR_TextureBlit_fFunc MTR_TextureBlit_f;

typedef void (MTR_CALL * MTR_TextureBlitSized_fFunc)(uint32_t, float, float,
 float, float);
MTR_TextureBlitSized_fFunc MTR_TextureBlitSized_f;

typedef void (MTR_CALL * MTR_TextureBlitScaled_fFunc)(uint32_t, float, float,
 float, float);
MTR_TextureBlitScaled_fFunc MTR_TextureBlitScaled_f;

typedef void (MTR_CALL * MTR_TextureBlitAngled_fFunc)(uint32_t, float, float,
 float, float, float);
MTR_TextureBlitAngled_fFunc MTR_TextureBlitAngled_f;

typedef void (MTR_CALL * MTR_TextureBlitFlipped_fFunc)(uint32_t, float, float,
 int);
MTR_TextureBlitFlipped_fFunc MTR_TextureBlitFlipped_f;

typedef void (MTR_CALL * MTR_TextureBlitGeneral_fFunc)(uint32_t, float, float,
 float, float, float, float, float, int);
MTR_TextureBlitGeneral_fFunc MTR_TextureBlitGeneral_f;

typedef void (MTR_CALL * MTR_TextureBlitRegion_fFunc)(uint32_t, float, float,
 float, float, float, float);
MTR_TextureBlitRegion_fFunc MTR_TextureBlitRegion_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionSized_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float);
MTR_TextureBlitRegionSized_fFunc MTR_TextureBlitRegionSized_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionScaled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float);
MTR_TextureBlitRegionScaled_fFunc MTR_TextureBlitRegionScaled_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionAngled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float);
MTR_TextureBlitRegionAngled_fFunc MTR_TextureBlitRegionAngled_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionFlipped_fFunc)(uint32_t, float,
 float, float, float, float, float, int);
MTR_TextureBlitRegionFlipped_fFunc MTR_TextureBlitRegionFlipped_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionGeneral_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float, float, float, int);
MTR_TextureBlitRegionGeneral_fFunc MTR_TextureBlitRegionGeneral_f;

typedef bool (MTR_CALL * MTR_TextureReceivePixelsFunc)(uint32_t, mtrPixels_t *);
MTR_TextureReceivePixelsFunc MTR_TextureReceivePixels;

#endif
