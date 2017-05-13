#ifndef MTR_UTILS_COLOR_BINDING_COMMON_H
#define MTR_UTILS_COLOR_BINDING_COMMON_H

typedef uint32_t (MTR_CALL * mtrColorAssembleRGBFunc)(uint8_t, uint8_t,
 uint8_t);
mtrColorAssembleRGBFunc mtrColorAssembleRGB;

typedef uint32_t (MTR_CALL * mtrColorAssembleRGBAFunc)(uint8_t, uint8_t,
 uint8_t, uint8_t);
mtrColorAssembleRGBAFunc mtrColorAssembleRGBA;

typedef void (MTR_CALL * mtrColorSplitRGBFunc)(uint32_t, uint8_t *, uint8_t *,
 uint8_t *);
mtrColorSplitRGBFunc mtrColorSplitRGB;

typedef void (MTR_CALL * mtrColorSplitRGBAFunc)(uint32_t, uint8_t *, uint8_t *,
 uint8_t *, uint8_t *);
mtrColorSplitRGBAFunc mtrColorSplitRGBA;

typedef uint32_t (MTR_CALL * mtrColorRGBtoRGBAFunc)(uint32_t);
mtrColorRGBtoRGBAFunc mtrColorRGBtoRGBA;

typedef uint32_t (MTR_CALL * mtrColorRGBAtoRGBFunc)(uint32_t);
mtrColorRGBAtoRGBFunc mtrColorRGBAtoRGB;

#endif
