#ifndef MTR_UTILS_COLOR_BINDING_COMMON_H
#define MTR_UTILS_COLOR_BINDING_COMMON_H

typedef int (MTR_CALL * mtrColorFunctionSupportedFunc)(const char *);
mtrColorFunctionSupportedFunc mtrColorFunctionSupported;

typedef uint32_t (MTR_CALL * mtrColorAssembleRGBFunc)(uint8_t, uint8_t,
 uint8_t);
mtrColorAssembleRGBFunc mtrColorAssembleRGB;

typedef uint32_t (MTR_CALL * mtrColorAssembleRGBAFunc)(uint8_t, uint8_t,
 uint8_t, uint8_t);
mtrColorAssembleRGBAFunc mtrColorAssembleRGBA;

#ifdef lua_h
typedef void (MTR_CALL * mtrColorSplitRGBFunc)(uint32_t, uint8_t *, uint8_t *,
 uint8_t *);
mtrColorSplitRGBFunc mtrColorSplitRGB;
#endif

typedef uint8_t (MTR_CALL * mtrColorRGBGetRFunc)(uint32_t);
mtrColorRGBGetRFunc mtrColorRGBGetR;

typedef uint8_t (MTR_CALL * mtrColorRGBGetGFunc)(uint32_t);
mtrColorRGBGetGFunc mtrColorRGBGetG;

typedef uint8_t (MTR_CALL * mtrColorRGBGetBFunc)(uint32_t);
mtrColorRGBGetBFunc mtrColorRGBGetB;

typedef uint32_t (MTR_CALL * mtrColorRGBSetRFunc)(uint32_t, uint8_t);
mtrColorRGBSetRFunc mtrColorRGBSetR;

typedef uint32_t (MTR_CALL * mtrColorRGBSetGFunc)(uint32_t, uint8_t);
mtrColorRGBSetGFunc mtrColorRGBSetG;

typedef uint32_t (MTR_CALL * mtrColorRGBSetBFunc)(uint32_t, uint8_t);
mtrColorRGBSetBFunc mtrColorRGBSetB;

#ifdef lua_h
typedef void (MTR_CALL * mtrColorSplitRGBAFunc)(uint32_t, uint8_t *, uint8_t *,
 uint8_t *, uint8_t *);
mtrColorSplitRGBAFunc mtrColorSplitRGBA;
#endif

typedef uint8_t (MTR_CALL * mtrColorRGBAGetRFunc)(uint32_t);
mtrColorRGBAGetRFunc mtrColorRGBAGetR;

typedef uint8_t (MTR_CALL * mtrColorRGBAGetGFunc)(uint32_t);
mtrColorRGBAGetGFunc mtrColorRGBAGetG;

typedef uint8_t (MTR_CALL * mtrColorRGBAGetBFunc)(uint32_t);
mtrColorRGBAGetBFunc mtrColorRGBAGetB;

typedef uint8_t (MTR_CALL * mtrColorRGBAGetAFunc)(uint32_t);
mtrColorRGBAGetAFunc mtrColorRGBAGetA;

typedef uint32_t (MTR_CALL * mtrColorRGBASetRFunc)(uint32_t, uint8_t);
mtrColorRGBASetRFunc mtrColorRGBASetR;

typedef uint32_t (MTR_CALL * mtrColorRGBASetGFunc)(uint32_t, uint8_t);
mtrColorRGBASetGFunc mtrColorRGBASetG;

typedef uint32_t (MTR_CALL * mtrColorRGBASetBFunc)(uint32_t, uint8_t);
mtrColorRGBASetBFunc mtrColorRGBASetB;

typedef uint32_t (MTR_CALL * mtrColorRGBASetAFunc)(uint32_t, uint8_t);
mtrColorRGBASetAFunc mtrColorRGBASetA;

typedef uint32_t (MTR_CALL * mtrColorRGBtoRGBAFunc)(uint32_t);
mtrColorRGBtoRGBAFunc mtrColorRGBtoRGBA;

typedef uint32_t (MTR_CALL * mtrColorRGBAtoRGBFunc)(uint32_t);
mtrColorRGBAtoRGBFunc mtrColorRGBAtoRGB;

#endif
