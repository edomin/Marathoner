#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_H
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_SpriteFunctionSupportedFunc)(const char *);
MTR_SpriteFunctionSupportedFunc MTR_SpriteFunctionSupported;

typedef bool (MTR_CALL * MTR_SpriteInitFunc)(uint32_t, uint32_t);
MTR_SpriteInitFunc MTR_SpriteInit;

typedef uint32_t (MTR_CALL * MTR_SpriteLoadFunc)(const char *, int, int, int,
 int, int, int, int);
MTR_SpriteLoadFunc MTR_SpriteLoad;

typedef uint32_t (MTR_CALL * MTR_SpriteLoadSimpleFunc)(const char *, int, int);
MTR_SpriteLoadSimpleFunc MTR_SpriteLoadSimple;

typedef uint32_t (MTR_CALL * MTR_SpriteLoadAtlasFunc)(const char *, int);
MTR_SpriteLoadAtlasFunc MTR_SpriteLoadAtlas;

typedef bool (MTR_CALL * MTR_SpriteSetAtlasFrameFunc)(uint32_t, int, int, int,
 int, int, int, int);
MTR_SpriteSetAtlasFrameFunc MTR_SpriteSetAtlasFrame;

typedef void (MTR_CALL * MTR_SpriteFreeFunc)(uint32_t);
MTR_SpriteFreeFunc MTR_SpriteFree;

typedef void (MTR_CALL * MTR_SpriteSetModulation_cFunc)(uint32_t, uint32_t);
MTR_SpriteSetModulation_cFunc MTR_SpriteSetModulation_c;

typedef void (MTR_CALL * MTR_SpriteSetModulation_caFunc)(uint32_t, uint32_t);
MTR_SpriteSetModulation_caFunc MTR_SpriteSetModulation_ca;

typedef void (MTR_CALL * MTR_SpriteSetModulation_rgbFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t);
MTR_SpriteSetModulation_rgbFunc MTR_SpriteSetModulation_rgb;

typedef void (MTR_CALL * MTR_SpriteSetModulation_rgbaFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_SpriteSetModulation_rgbaFunc MTR_SpriteSetModulation_rgba;

typedef void (MTR_CALL * MTR_SpriteSetModulationAlphaFunc)(uint32_t, uint8_t);
MTR_SpriteSetModulationAlphaFunc MTR_SpriteSetModulationAlpha;

typedef void (MTR_CALL * MTR_SpriteSetModulationAlpha_fFunc)(uint32_t, float);
MTR_SpriteSetModulationAlpha_fFunc MTR_SpriteSetModulationAlpha_f;

typedef bool (MTR_CALL * MTR_SpriteDraw_fFunc)(uint32_t, int, float, float);
MTR_SpriteDraw_fFunc MTR_SpriteDraw_f;

typedef bool (MTR_CALL * MTR_SpriteDrawSized_fFunc)(uint32_t, int, float, float,
 float, float);
MTR_SpriteDrawSized_fFunc MTR_SpriteDrawSized_f;

typedef bool (MTR_CALL * MTR_SpriteDrawScaled_fFunc)(uint32_t, int, float, float,
 float, float);
MTR_SpriteDrawScaled_fFunc MTR_SpriteDrawScaled_f;

typedef bool (MTR_CALL * MTR_SpriteDrawAngled_fFunc)(uint32_t, int, float, float,
 float);
MTR_SpriteDrawAngled_fFunc MTR_SpriteDrawAngled_f;

typedef bool (MTR_CALL * MTR_SpriteDrawFlipped_fFunc)(uint32_t, int, float,
 float, int);
MTR_SpriteDrawFlipped_fFunc MTR_SpriteDrawFlipped_f;

typedef bool (MTR_CALL * MTR_SpriteDrawGeneral_fFunc)(uint32_t, int, float,
 float, float, float, float, int);
MTR_SpriteDrawGeneral_fFunc MTR_SpriteDrawGeneral_f;
#endif
