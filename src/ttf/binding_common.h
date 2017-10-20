#ifndef MTR_TTF_BINDING_COMMON_H
#define MTR_TTF_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_TtfFunctionSupportedFunc)(const char *);
MTR_TtfFunctionSupportedFunc MTR_TtfFunctionSupported;

typedef bool (MTR_CALL * MTR_TtfInitFunc)(uint32_t, uint32_t);
MTR_TtfInitFunc MTR_TtfInit;

typedef void (MTR_CALL * MTR_TtfQuitFunc)(void);
MTR_TtfQuitFunc MTR_TtfQuit;

typedef uint32_t (MTR_CALL * MTR_TtfLoadFunc)(const char *, int);
MTR_TtfLoadFunc MTR_TtfLoad;

typedef void (MTR_CALL * MTR_TtfFreeFunc)(uint32_t);
MTR_TtfFreeFunc MTR_TtfFree;

typedef int (MTR_CALL * MTR_TtfGetFontHeightFunc)(uint32_t);
MTR_TtfGetFontHeightFunc MTR_TtfGetFontHeight;

typedef bool (MTR_CALL * MTR_TtfGetStringSizesFunc)(uint32_t, const char *,
 int *, int *);
MTR_TtfGetStringSizesFunc MTR_TtfGetStringSizes;

typedef int (MTR_CALL * MTR_TtfGetStringWidthFunc)(uint32_t, const char *);
MTR_TtfGetStringWidthFunc MTR_TtfGetStringWidth;

typedef void (MTR_CALL * MTR_TtfSetFontStyleFunc)(uint32_t, int);
MTR_TtfSetFontStyleFunc MTR_TtfSetFontStyle;

typedef void (MTR_CALL * MTR_TtfSetFontOutlineFunc)(uint32_t, int);
MTR_TtfSetFontOutlineFunc MTR_TtfSetFontOutline;

typedef mtrPixels_t *(MTR_CALL * MTR_TtfRenderStringFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t, const char *);
MTR_TtfRenderStringFunc MTR_TtfRenderString;

#endif
