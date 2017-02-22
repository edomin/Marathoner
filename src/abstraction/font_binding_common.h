#ifndef MTR_ABSTRACTION_FONT_BINDING_COMMON_H
#define MTR_ABSTRACTION_FONT_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrFontInitFunc)(uint32_t, uint32_t);
mtrFontInitFunc mtrFontInit;

typedef uint32_t (MTR_CALL * mtrFontLoadTtfFunc)(const char *, int);
mtrFontLoadTtfFunc mtrFontLoadTtf;

typedef void (MTR_CALL * mtrFontFreeFunc)(uint32_t);
mtrFontFreeFunc mtrFontFree;

typedef void (MTR_CALL * mtrFontSetTtfStyleFunc)(uint32_t, int);
mtrFontSetTtfStyleFunc mtrFontSetTtfStyle;

typedef void (MTR_CALL * mtrFontSetTtfOutlineFunc)(uint32_t, int);
mtrFontSetTtfOutlineFunc mtrFontSetTtfOutline;

typedef bool (MTR_CALL * mtrFontRenderTtfStringFunc)(uint32_t, uint32_t,
 uint8_t, uint8_t, uint8_t, const char *);
mtrFontRenderTtfStringFunc mtrFontRenderTtfString;

typedef uint32_t (MTR_CALL * mtrFontCreateMbfFunc)(const char *, int, int, int);
mtrFontCreateMbfFunc mtrFontCreateMbf;

typedef bool (MTR_CALL * mtrFontAddMbfTextureTableFunc)(uint32_t, uint32_t,
 int);
mtrFontAddMbfTextureTableFunc mtrFontAddMbfTextureTable;

typedef bool (MTR_CALL * mtrFontDrawMbfString_fFunc)(uint32_t, float, float,
 const char *);
mtrFontDrawMbfString_fFunc mtrFontDrawMbfString_f;

#endif
