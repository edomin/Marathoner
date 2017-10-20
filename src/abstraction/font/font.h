#ifndef MTR_ABSTRACTION_FONT_H
#define MTR_ABSTRACTION_FONT_H

#include "fa/Abstraction_font.h"
#include "marathoner/plugin.h"

/* Monospace bitmap font */
typedef struct mtrMbf_t {
    unsigned int reservedTables; /* 1 table = 256 bytes */
    uint32_t    *texTable; /* array of textures with tables of symbols */
    int          width;
    int          height;
} mtrMbf_t;

typedef struct mtrFont_t {
    uint32_t   ttfIndex;
    mtrMbf_t  *mbf;
    char      *name;
} mtrFont_t;

char mtrDefaultFontName[] = "Unnamed_Font";
mtrIndexkeeper_t *mtrFontKeeper;
static bool mtrFontInited = false;
#define MTR_FONT_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrFontInited)                           \
        return returnValue;
#define MTR_FONT_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue)            \
    if (!mtrFontInited)                                                        \
    {                                                                          \
        MTR_LogWrite(message ". Font abstraction manager are not initialized", \
         1, MTR_LMT_ERROR);                                                    \
        return returnValue;                                                    \
    }

typedef uint32_t (MTR_CALL * MTR_TtfLoadFunc)(const char *filename, int size);
MTR_TtfLoadFunc MTR_TtfLoad;

typedef void (MTR_CALL * MTR_TtfFreeFunc)(uint32_t fontNum);
MTR_TtfFreeFunc MTR_TtfFree;

typedef int (MTR_CALL * MTR_TtfGetFontHeightFunc)(uint32_t fontNum);
MTR_TtfGetFontHeightFunc MTR_TtfGetFontHeight;

typedef int (MTR_CALL * MTR_TtfGetStringWidthFunc)(uint32_t fontNum,
 const char *string);
MTR_TtfGetStringWidthFunc MTR_TtfGetStringWidth;

typedef void (MTR_CALL * MTR_TtfSetFontStyleFunc)(uint32_t fontNum, int style);
MTR_TtfSetFontStyleFunc MTR_TtfSetFontStyle;

typedef void (MTR_CALL * MTR_TtfSetFontOutlineFunc)(uint32_t fontNum,
 int outline);
MTR_TtfSetFontOutlineFunc MTR_TtfSetFontOutline;

typedef mtrPixels_t *(MTR_CALL * MTR_TtfRenderStringFunc)(uint32_t fontNum,
 uint8_t r, uint8_t g, uint8_t b, const char *string);
MTR_TtfRenderStringFunc MTR_TtfRenderString;

typedef void (MTR_CALL * MTR_TextureBlit_fFunc)(uint32_t texNum, float x,
 float y);
MTR_TextureBlit_fFunc MTR_TextureBlit_f;

typedef void (MTR_CALL * MTR_TextureBlitRegion_fFunc)(uint32_t texNum, float x,
 float y, float rx, float ry, float rw, float rh);
MTR_TextureBlitRegion_fFunc MTR_TextureBlitRegion_f;

typedef bool (MTR_CALL * MTR_TextureReceivePixelsFunc)(uint32_t texNum,
 mtrPixels_t *pixels);
MTR_TextureReceivePixelsFunc MTR_TextureReceivePixels;

#endif
