#ifndef MTR_UTILS_COLOR_BINDING_COMMON_H
#define MTR_UTILS_COLOR_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_ColorFunctionSupportedFunc)(const char *);
MTR_ColorFunctionSupportedFunc MTR_ColorFunctionSupported;

typedef uint32_t (MTR_CALL * MTR_ColorAssembleRGBFunc)(uint8_t, uint8_t,
 uint8_t);
MTR_ColorAssembleRGBFunc MTR_ColorAssembleRGB;

typedef uint32_t (MTR_CALL * MTR_ColorAssembleRGBAFunc)(uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_ColorAssembleRGBAFunc MTR_ColorAssembleRGBA;

#ifdef lua_h
typedef void (MTR_CALL * MTR_ColorSplitRGBFunc)(uint32_t, uint8_t *, uint8_t *,
 uint8_t *);
MTR_ColorSplitRGBFunc MTR_ColorSplitRGB;
#endif

typedef uint8_t (MTR_CALL * MTR_ColorRGBGetRFunc)(uint32_t);
MTR_ColorRGBGetRFunc MTR_ColorRGBGetR;

typedef uint8_t (MTR_CALL * MTR_ColorRGBGetGFunc)(uint32_t);
MTR_ColorRGBGetGFunc MTR_ColorRGBGetG;

typedef uint8_t (MTR_CALL * MTR_ColorRGBGetBFunc)(uint32_t);
MTR_ColorRGBGetBFunc MTR_ColorRGBGetB;

typedef uint32_t (MTR_CALL * MTR_ColorRGBSetRFunc)(uint32_t, uint8_t);
MTR_ColorRGBSetRFunc MTR_ColorRGBSetR;

typedef uint32_t (MTR_CALL * MTR_ColorRGBSetGFunc)(uint32_t, uint8_t);
MTR_ColorRGBSetGFunc MTR_ColorRGBSetG;

typedef uint32_t (MTR_CALL * MTR_ColorRGBSetBFunc)(uint32_t, uint8_t);
MTR_ColorRGBSetBFunc MTR_ColorRGBSetB;

#ifdef lua_h
typedef void (MTR_CALL * MTR_ColorSplitRGBAFunc)(uint32_t, uint8_t *, uint8_t *,
 uint8_t *, uint8_t *);
MTR_ColorSplitRGBAFunc MTR_ColorSplitRGBA;
#endif

typedef uint8_t (MTR_CALL * MTR_ColorRGBAGetRFunc)(uint32_t);
MTR_ColorRGBAGetRFunc MTR_ColorRGBAGetR;

typedef uint8_t (MTR_CALL * MTR_ColorRGBAGetGFunc)(uint32_t);
MTR_ColorRGBAGetGFunc MTR_ColorRGBAGetG;

typedef uint8_t (MTR_CALL * MTR_ColorRGBAGetBFunc)(uint32_t);
MTR_ColorRGBAGetBFunc MTR_ColorRGBAGetB;

typedef uint8_t (MTR_CALL * MTR_ColorRGBAGetAFunc)(uint32_t);
MTR_ColorRGBAGetAFunc MTR_ColorRGBAGetA;

typedef uint32_t (MTR_CALL * MTR_ColorRGBASetRFunc)(uint32_t, uint8_t);
MTR_ColorRGBASetRFunc MTR_ColorRGBASetR;

typedef uint32_t (MTR_CALL * MTR_ColorRGBASetGFunc)(uint32_t, uint8_t);
MTR_ColorRGBASetGFunc MTR_ColorRGBASetG;

typedef uint32_t (MTR_CALL * MTR_ColorRGBASetBFunc)(uint32_t, uint8_t);
MTR_ColorRGBASetBFunc MTR_ColorRGBASetB;

typedef uint32_t (MTR_CALL * MTR_ColorRGBASetAFunc)(uint32_t, uint8_t);
MTR_ColorRGBASetAFunc MTR_ColorRGBASetA;

typedef uint32_t (MTR_CALL * MTR_ColorRGBtoRGBAFunc)(uint32_t);
MTR_ColorRGBtoRGBAFunc MTR_ColorRGBtoRGBA;

typedef uint32_t (MTR_CALL * MTR_ColorRGBAtoRGBFunc)(uint32_t);
MTR_ColorRGBAtoRGBFunc MTR_ColorRGBAtoRGB;

#endif
