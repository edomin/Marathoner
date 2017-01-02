#ifndef MTR_TTF_BINDING_COMMON
#define MTR_TTF_BINDING_COMMON

typedef bool (MTR_CALL * mtrTtfInitFunc)(uint32_t, uint32_t);
mtrTtfInitFunc mtrTtfInit;

typedef void (MTR_CALL * mtrTtfQuitFunc)(void);
mtrTtfQuitFunc mtrTtfQuit;

typedef uint32_t (MTR_CALL * mtrTtfLoadFunc)(const char *, int);
mtrTtfLoadFunc mtrTtfLoad;

typedef void (MTR_CALL * mtrTtfFreeFunc)(uint32_t);
mtrTtfFreeFunc mtrTtfFree;

typedef void (MTR_CALL * mtrTtfSetFontStyleFunc)(uint32_t, int);
mtrTtfSetFontStyleFunc mtrTtfSetFontStyle;

typedef void (MTR_CALL * mtrTtfSetFontOutlineFunc)(uint32_t, int);
mtrTtfSetFontOutlineFunc mtrTtfSetFontOutline;

#endif
