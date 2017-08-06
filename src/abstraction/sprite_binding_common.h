#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_H
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrSpriteInitFunc)(uint32_t, uint32_t);
mtrSpriteInitFunc mtrSpriteInit;

typedef uint32_t (MTR_CALL * mtrSpriteLoadFunc)(const char *, int, int, int,
 int, int, int, int);
mtrSpriteLoadFunc mtrSpriteLoad;

typedef uint32_t (MTR_CALL * mtrSpriteLoadSimpleFunc)(const char *, int, int);
mtrSpriteLoadSimpleFunc mtrSpriteLoadSimple;

typedef void (MTR_CALL * mtrSpriteFreeFunc)(uint32_t);
mtrSpriteFreeFunc mtrSpriteFree;

typedef void (MTR_CALL * mtrSpriteSetModulation_cFunc)(uint32_t, uint32_t);
mtrSpriteSetModulation_cFunc mtrSpriteSetModulation_c;

typedef void (MTR_CALL * mtrSpriteSetModulation_caFunc)(uint32_t, uint32_t);
mtrSpriteSetModulation_caFunc mtrSpriteSetModulation_ca;

typedef void (MTR_CALL * mtrSpriteSetModulation_rgbFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t);
mtrSpriteSetModulation_rgbFunc mtrSpriteSetModulation_rgb;

typedef void (MTR_CALL * mtrSpriteSetModulation_rgbaFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t, uint8_t);
mtrSpriteSetModulation_rgbaFunc mtrSpriteSetModulation_rgba;

typedef void (MTR_CALL * mtrSpriteSetModulationAlphaFunc)(uint32_t, uint8_t);
mtrSpriteSetModulationAlphaFunc mtrSpriteSetModulationAlpha;

typedef void (MTR_CALL * mtrSpriteSetModulationAlpha_fFunc)(uint32_t, float);
mtrSpriteSetModulationAlpha_fFunc mtrSpriteSetModulationAlpha_f;

typedef bool (MTR_CALL * mtrSpriteDraw_fFunc)(uint32_t, int, float, float);
mtrSpriteDraw_fFunc mtrSpriteDraw_f;

typedef bool (MTR_CALL * mtrSpriteDrawScaled_fFunc)(uint32_t, int, float, float,
 float, float);
mtrSpriteDrawScaled_fFunc mtrSpriteDrawScaled_f;

typedef bool (MTR_CALL * mtrSpriteDrawAngled_fFunc)(uint32_t, int, float, float,
 float);
mtrSpriteDrawAngled_fFunc mtrSpriteDrawAngled_f;

typedef bool (MTR_CALL * mtrSpriteDrawFlipped_fFunc)(uint32_t, int, float,
 float, int);
mtrSpriteDrawFlipped_fFunc mtrSpriteDrawFlipped_f;

typedef bool (MTR_CALL * mtrSpriteDrawGeneral_fFunc)(uint32_t, int, float,
 float, float, float, float, int);
mtrSpriteDrawGeneral_fFunc mtrSpriteDrawGeneral_f;
#endif
