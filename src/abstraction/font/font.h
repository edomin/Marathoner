#ifndef MTR_ABSTRACTION_FONT_H
#define MTR_ABSTRACTION_FONT_H

#include "marathoner/plugin.h"

/* Monospace bitmap font */
typedef struct mtrMbf_t {
    int       reservedTables; /* 1 table = 256 bytes */
    uint32_t *texTable; /* array of textures with tables of symbols */
    int       width;
    int       height;
} mtrMbf_t;

typedef struct mtrFont_t {
    uint32_t   ttfIndex;
    mtrMbf_t  *mbf;
    char      *name;
} mtrFont_t;

mtrIndexkeeper_t *mtrFontKeeper;

typedef uint32_t (MTR_CALL * mtrTtfLoadFunc)(const char *filename, int size);
mtrTtfLoadFunc mtrTtfLoad;

typedef void (MTR_CALL * mtrTtfFreeFunc)(uint32_t fontNum);
mtrTtfFreeFunc mtrTtfFree;

typedef int (MTR_CALL * mtrTtfGetFontHeightFunc)(uint32_t fontNum);
mtrTtfGetFontHeightFunc mtrTtfGetFontHeight;

typedef int (MTR_CALL * mtrTtfGetStringWidthFunc)(uint32_t fontNum,
 const char *string);
mtrTtfGetStringWidthFunc mtrTtfGetStringWidth;

typedef void (MTR_CALL * mtrTtfSetFontStyleFunc)(uint32_t fontNum, int style);
mtrTtfSetFontStyleFunc mtrTtfSetFontStyle;

typedef void (MTR_CALL * mtrTtfSetFontOutlineFunc)(uint32_t fontNum,
 int outline);
mtrTtfSetFontOutlineFunc mtrTtfSetFontOutline;

typedef mtrPixels_t *(MTR_CALL * mtrTtfRenderStringFunc)(uint32_t fontNum,
 uint8_t r, uint8_t g, uint8_t b, const char *string);
mtrTtfRenderStringFunc mtrTtfRenderString;

typedef void (MTR_CALL * mtrTextureBlit_fFunc)(uint32_t texNum, float x,
 float y);
mtrTextureBlit_fFunc mtrTextureBlit_f;

typedef void (MTR_CALL * mtrTextureBlitRegion_fFunc)(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh);
mtrTextureBlitRegion_fFunc mtrTextureBlitRegion_f;

typedef bool (MTR_CALL * mtrTextureReceivePixelsFunc)(uint32_t texNum,
 mtrPixels_t *pixels);
mtrTextureReceivePixelsFunc mtrTextureReceivePixels;

#endif
