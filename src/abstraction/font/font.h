#ifndef MTR_ABSTRACTION_FONT_H
#define MTR_ABSTRACTION_FONT_H

#include <string.h>

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faFont
#endif
#include "fa/Abstraction_font.h"

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

MTR_FUNC(uint32_t, MTR_TtfLoad, const char *, int);
MTR_FUNC(void, MTR_TtfFree, uint32_t);
MTR_FUNC(int, MTR_TtfGetFontHeight, uint32_t);
MTR_FUNC(int, MTR_TtfGetStringWidth, uint32_t, const char *);
MTR_FUNC(void, MTR_TtfSetFontStyle, uint32_t, int);
MTR_FUNC(void, MTR_TtfSetFontOutline, uint32_t, int);
MTR_FUNC(mtrPixels_t *, MTR_TtfRenderString, uint32_t, uint8_t, uint8_t,
 uint8_t, const char *);
MTR_FUNC(void, MTR_TextureBlit_f, uint32_t, float, float);
MTR_FUNC(void, MTR_TextureBlitRegion_f, uint32_t, float, float, float, float,
 float, float);
MTR_FUNC(bool, MTR_TextureReceivePixels, uint32_t, mtrPixels_t *);
MTR_FUNC(void, MTR_TtfGetGlyphSizes, uint32_t, uint32_t, int *, int *);
MTR_FUNC(bool, MTR_TextureReceivePixelsToPos, uint32_t, mtrPixels_t *, int,
 int);

#endif
