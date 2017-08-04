#ifndef MTR_TEXTURE_BINDING_COMMON_H
#define MTR_TEXTURE_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrTextureInitFunc)(uint32_t, uint32_t);
mtrTextureInitFunc mtrTextureInit;

typedef void (MTR_CALL * mtrTextureBeginTargetFunc)(int);
mtrTextureBeginTargetFunc mtrTextureBeginTarget;

typedef void (MTR_CALL * mtrTextureEndTargetFunc)(void);
mtrTextureEndTargetFunc mtrTextureEndTarget;

typedef int (MTR_CALL * mtrTextureGetWidthFunc)(uint32_t);
mtrTextureGetWidthFunc mtrTextureGetWidth;

typedef int (MTR_CALL * mtrTextureGetHeightFunc)(uint32_t);
mtrTextureGetHeightFunc mtrTextureGetHeight;

#ifndef _SQUIRREL_H_
typedef void (MTR_CALL * mtrTextureGetSizesFunc)(uint32_t, int *, int *);
mtrTextureGetSizesFunc mtrTextureGetSizes;
#endif

typedef uint32_t (MTR_CALL * mtrTextureCreateFunc)(const char *, int, int);
mtrTextureCreateFunc mtrTextureCreate;

typedef uint32_t (MTR_CALL * mtrTextureLoadFunc)(const char *);
mtrTextureLoadFunc mtrTextureLoad;

typedef uint32_t (MTR_CALL * mtrTextureCopyFunc)(uint32_t);
mtrTextureCopyFunc mtrTextureCopy;

typedef bool (MTR_CALL * mtrTextureSaveFunc)(uint32_t, const char *);
mtrTextureSaveFunc mtrTextureSave;

typedef void (MTR_CALL * mtrTextureFreeFunc)(uint32_t);
mtrTextureFreeFunc mtrTextureFree;

typedef void (MTR_CALL * mtrTextureSetModulation_cFunc)(uint32_t, uint32_t);
mtrTextureSetModulation_cFunc mtrTextureSetModulation_c;

typedef void (MTR_CALL * mtrTextureSetModulation_caFunc)(uint32_t, uint32_t);
mtrTextureSetModulation_caFunc mtrTextureSetModulation_ca;

typedef void (MTR_CALL * mtrTextureSetModulation_rgbFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t);
mtrTextureSetModulation_rgbFunc mtrTextureSetModulation_rgb;

typedef void (MTR_CALL * mtrTextureSetModulation_rgbaFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t, uint8_t);
mtrTextureSetModulation_rgbaFunc mtrTextureSetModulation_rgba;

typedef void (MTR_CALL * mtrTextureSetModulationAlphaFunc)(uint32_t, uint8_t);
mtrTextureSetModulationAlphaFunc mtrTextureSetModulationAlpha;

typedef void (MTR_CALL * mtrTextureSetModulationAlpha_fFunc)(uint32_t, float);
mtrTextureSetModulationAlpha_fFunc mtrTextureSetModulationAlpha_f;

typedef void (MTR_CALL * mtrTextureSetBlendFunctionFunc)(uint32_t, int, int,
 int, int);
mtrTextureSetBlendFunctionFunc mtrTextureSetBlendFunction;

typedef void (MTR_CALL * mtrTextureSetAlphaBlendingFunc)(uint32_t, bool);
mtrTextureSetAlphaBlendingFunc mtrTextureSetAlphaBlending;

typedef void (MTR_CALL * mtrTextureBlit_fFunc)(uint32_t, float, float);
mtrTextureBlit_fFunc mtrTextureBlit_f;

typedef void (MTR_CALL * mtrTextureBlitRegion_fFunc)(uint32_t, float, float,
 float, float, float, float);
mtrTextureBlitRegion_fFunc mtrTextureBlitRegion_f;

typedef void (MTR_CALL * mtrTextureBlitRegionScaled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float);
mtrTextureBlitRegionScaled_fFunc mtrTextureBlitRegionScaled_f;

typedef void (MTR_CALL * mtrTextureBlitRegionAngled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float);
mtrTextureBlitRegionAngled_fFunc mtrTextureBlitRegionAngled_f;

typedef void (MTR_CALL * mtrTextureBlitRegionFlipped_fFunc)(uint32_t, float,
 float, float, float, float, float, int);
mtrTextureBlitRegionFlipped_fFunc mtrTextureBlitRegionFlipped_f;

typedef void (MTR_CALL * mtrTextureBlitRegionGeneral_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float, float, float, int);
mtrTextureBlitRegionGeneral_fFunc mtrTextureBlitRegionGeneral_f;

#endif
