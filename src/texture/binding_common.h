#ifndef MTR_TEXTURE_BINDING_COMMON_H
#define MTR_TEXTURE_BINDING_COMMON_H

MTR_FUNC(int, MTR_TextureFunctionSupported, const char *);
MTR_FUNC(bool, MTR_TextureInit, uint32_t, uint32_t);
MTR_FUNC(void, MTR_TextureBeginTarget, int);
MTR_FUNC(void, MTR_TextureEndTarget, void);
MTR_FUNC(int, MTR_TextureGetWidth, uint32_t);
MTR_FUNC(int, MTR_TextureGetHeight, uint32_t);
#ifdef lua_h
MTR_FUNC(void, MTR_TextureGetSizes, uint32_t, int *, int *);
#endif
MTR_FUNC(uint32_t, MTR_TextureCreate, const char *, int, int);
MTR_FUNC(uint32_t, MTR_TextureLoad, const char *);
MTR_FUNC(uint32_t, MTR_TextureCopy, uint32_t);
MTR_FUNC(bool, MTR_TextureSave, uint32_t, const char *);
MTR_FUNC(void, MTR_TextureFree, uint32_t);
MTR_FUNC(void, MTR_TextureSetModulation_c, uint32_t, uint32_t);
MTR_FUNC(void, MTR_TextureSetModulation_ca, uint32_t, uint32_t);
MTR_FUNC(void, MTR_TextureSetModulation_rgb, uint32_t, uint8_t, uint8_t,
 uint8_t);
MTR_FUNC(void, MTR_TextureSetModulation_rgba, uint32_t, uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(void, MTR_TextureSetModulationAlpha, uint32_t, uint8_t);
MTR_FUNC(void, MTR_TextureSetModulationAlpha_f, uint32_t, float);
MTR_FUNC(void, MTR_TextureSetBlendFunction, uint32_t, int, int, int, int);
MTR_FUNC(void, MTR_TextureSetAlphaBlending, uint32_t, bool);
MTR_FUNC(void, MTR_TextureBlit_f, uint32_t, float, float);
MTR_FUNC(void, MTR_TextureBlitSized_f, uint32_t, float, float, float, float);
MTR_FUNC(void, MTR_TextureBlitScaled_f, uint32_t, float, float, float, float);
MTR_FUNC(void, MTR_TextureBlitAngled_f, uint32_t, float, float, float, float,
 float);
MTR_FUNC(void, MTR_TextureBlitFlipped_f, uint32_t, float, float, int);
MTR_FUNC(void, MTR_TextureBlitGeneral_f, uint32_t, float, float, float, float,
 float, float, float, int);
MTR_FUNC(void, MTR_TextureBlitRegion_f, uint32_t, float, float, float, float,
 float, float);
MTR_FUNC(void, MTR_TextureBlitRegionSized_f, uint32_t, float, float, float,
 float, float, float, float, float);
MTR_FUNC(void, MTR_TextureBlitRegionScaled_f, uint32_t, float, float, float,
 float, float, float, float, float);
MTR_FUNC(void, MTR_TextureBlitRegionAngled_f, uint32_t, float, float, float,
 float, float, float, float, float, float);
MTR_FUNC(void, MTR_TextureBlitRegionFlipped_f, uint32_t, float, float, float,
 float, float, float, int);
MTR_FUNC(void, MTR_TextureBlitRegionGeneral_f, uint32_t, float, float, float,
 float, float, float, float, float, float, float, float, int);
MTR_FUNC(bool, MTR_TextureReceivePixels, uint32_t, mtrPixels_t *);

#endif
