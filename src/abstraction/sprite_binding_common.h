#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_H
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_H

MTR_FUNC(int, MTR_SpriteFunctionSupported, const char *);
MTR_FUNC(bool, MTR_SpriteInit, uint32_t, uint32_t);
MTR_FUNC(uint32_t, MTR_SpriteLoad, const char *, int, int, int, int, int, int,
 int);
MTR_FUNC(uint32_t, MTR_SpriteLoadSimple, const char *, int, int);
MTR_FUNC(uint32_t, MTR_SpriteLoadAtlas, const char *, int);
MTR_FUNC(bool, MTR_SpriteSetAtlasFrame, uint32_t, int, int, int, int, int, int,
 int);
MTR_FUNC(void, MTR_SpriteFree, uint32_t);
MTR_FUNC(void, MTR_SpriteSetModulation_c, uint32_t, uint32_t);
MTR_FUNC(void, MTR_SpriteSetModulation_ca, uint32_t, uint32_t);
MTR_FUNC(void, MTR_SpriteSetModulation_rgb, uint32_t, uint8_t, uint8_t,
 uint8_t);
MTR_FUNC(void, MTR_SpriteSetModulation_rgba, uint32_t, uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(void, MTR_SpriteSetModulationAlpha, uint32_t, uint8_t);
MTR_FUNC(void, MTR_SpriteSetModulationAlpha_f, uint32_t, float);
MTR_FUNC(void, MTR_SpriteDraw_f, uint32_t, int, float, float);
MTR_FUNC(void, MTR_SpriteDrawSized_f, uint32_t, int, float, float, float,
 float);
MTR_FUNC(void, MTR_SpriteDrawScaled_f, uint32_t, int, float, float, float,
 float);
MTR_FUNC(void, MTR_SpriteDrawAngled_f, uint32_t, int, float, float, float);
MTR_FUNC(void, MTR_SpriteDrawFlipped_f, uint32_t, int, float, float, int);
MTR_FUNC(void, MTR_SpriteDrawGeneral_f, uint32_t, int, float, float, float,
 float, float, int);
#endif
