#ifndef MTR_TTF_BINDING_COMMON_H
#define MTR_TTF_BINDING_COMMON_H

typedef int (MTR_CALL * mtrTtfFunctionSupportedFunc)(const char *);
mtrTtfFunctionSupportedFunc mtrTtfFunctionSupported;

typedef bool (MTR_CALL * mtrTtfInitFunc)(uint32_t, uint32_t);
mtrTtfInitFunc mtrTtfInit;

typedef void (MTR_CALL * mtrTtfQuitFunc)(void);
mtrTtfQuitFunc mtrTtfQuit;

typedef uint32_t (MTR_CALL * mtrTtfLoadFunc)(const char *, int);
mtrTtfLoadFunc mtrTtfLoad;

typedef void (MTR_CALL * mtrTtfFreeFunc)(uint32_t);
mtrTtfFreeFunc mtrTtfFree;

typedef int (MTR_CALL * mtrTtfGetFontHeightFunc)(uint32_t);
mtrTtfGetFontHeightFunc mtrTtfGetFontHeight;

typedef bool (MTR_CALL * mtrTtfGetStringSizesFunc)(uint32_t, const char *,
 int *, int *);
mtrTtfGetStringSizesFunc mtrTtfGetStringSizes;

typedef int (MTR_CALL * mtrTtfGetStringWidthFunc)(uint32_t, const char *);
mtrTtfGetStringWidthFunc mtrTtfGetStringWidth;

typedef void (MTR_CALL * mtrTtfSetFontStyleFunc)(uint32_t, int);
mtrTtfSetFontStyleFunc mtrTtfSetFontStyle;

typedef void (MTR_CALL * mtrTtfSetFontOutlineFunc)(uint32_t, int);
mtrTtfSetFontOutlineFunc mtrTtfSetFontOutline;

typedef mtrPixels_t *(MTR_CALL * mtrTtfRenderStringFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t, const char *);
mtrTtfRenderStringFunc mtrTtfRenderString;

#endif
