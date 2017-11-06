#ifndef MTR_UTILS_COLOR_BINDING_COMMON_H
#define MTR_UTILS_COLOR_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_ColorFunctionSupportedFunc)(const char *);
MTR_ColorFunctionSupportedFunc MTR_ColorFunctionSupported;

typedef uint32_t (MTR_CALL * MTR_ColorRgbAssembleFunc)(uint8_t, uint8_t,
 uint8_t);
MTR_ColorRgbAssembleFunc MTR_ColorRgbAssemble;

typedef uint32_t (MTR_CALL * MTR_ColorRgbaAssembleFunc)(uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_ColorRgbaAssembleFunc MTR_ColorRgbaAssemble;

#ifdef lua_h
typedef void (MTR_CALL * MTR_ColorRgbSplitFunc)(uint32_t, uint8_t *, uint8_t *,
 uint8_t *);
MTR_ColorRgbSplitFunc MTR_ColorRgbSplit;
#endif

typedef uint8_t (MTR_CALL * MTR_ColorRgbGetRedFunc)(uint32_t);
MTR_ColorRgbGetRedFunc MTR_ColorRgbGetRed;

typedef uint8_t (MTR_CALL * MTR_ColorRgbGetGreenFunc)(uint32_t);
MTR_ColorRgbGetGreenFunc MTR_ColorRgbGetGreen;

typedef uint8_t (MTR_CALL * MTR_ColorRgbGetBlueFunc)(uint32_t);
MTR_ColorRgbGetBlueFunc MTR_ColorRgbGetBlue;

typedef uint32_t (MTR_CALL * MTR_ColorRgbSetRedFunc)(uint32_t, uint8_t);
MTR_ColorRgbSetRedFunc MTR_ColorRgbSetRed;

typedef uint32_t (MTR_CALL * MTR_ColorRgbSetGreenFunc)(uint32_t, uint8_t);
MTR_ColorRgbSetGreenFunc MTR_ColorRgbSetGreen;

typedef uint32_t (MTR_CALL * MTR_ColorRgbSetBlueFunc)(uint32_t, uint8_t);
MTR_ColorRgbSetBlueFunc MTR_ColorRgbSetBlue;

#ifdef lua_h
typedef void (MTR_CALL * MTR_ColorRgbaSplitFunc)(uint32_t, uint8_t *, uint8_t *,
 uint8_t *, uint8_t *);
MTR_ColorRgbaSplitFunc MTR_ColorRgbaSplit;
#endif

typedef uint8_t (MTR_CALL * MTR_ColorRgbaGetRedFunc)(uint32_t);
MTR_ColorRgbaGetRedFunc MTR_ColorRgbaGetRed;

typedef uint8_t (MTR_CALL * MTR_ColorRgbaGetGreenFunc)(uint32_t);
MTR_ColorRgbaGetGreenFunc MTR_ColorRgbaGetGreen;

typedef uint8_t (MTR_CALL * MTR_ColorRgbaGetBlueFunc)(uint32_t);
MTR_ColorRgbaGetBlueFunc MTR_ColorRgbaGetBlue;

typedef uint8_t (MTR_CALL * MTR_ColorRgbaGetAlphaFunc)(uint32_t);
MTR_ColorRgbaGetAlphaFunc MTR_ColorRgbaGetAlpha;

typedef uint32_t (MTR_CALL * MTR_ColorRgbaSetRedFunc)(uint32_t, uint8_t);
MTR_ColorRgbaSetRedFunc MTR_ColorRgbaSetRed;

typedef uint32_t (MTR_CALL * MTR_ColorRgbaSetGreenFunc)(uint32_t, uint8_t);
MTR_ColorRgbaSetGreenFunc MTR_ColorRgbaSetGreen;

typedef uint32_t (MTR_CALL * MTR_ColorRgbaSetBlueFunc)(uint32_t, uint8_t);
MTR_ColorRgbaSetBlueFunc MTR_ColorRgbaSetBlue;

typedef uint32_t (MTR_CALL * MTR_ColorRgbaSetAlphaFunc)(uint32_t, uint8_t);
MTR_ColorRgbaSetAlphaFunc MTR_ColorRgbaSetAlpha;

typedef uint32_t (MTR_CALL * MTR_ColorRgbToRgbaFunc)(uint32_t);
MTR_ColorRgbToRgbaFunc MTR_ColorRgbToRgba;

typedef uint32_t (MTR_CALL * MTR_ColorRgbaToRgbFunc)(uint32_t);
MTR_ColorRgbaToRgbFunc MTR_ColorRgbaToRgb;

#endif
