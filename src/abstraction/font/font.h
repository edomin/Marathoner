#ifndef MTR_ABSTRACTION_FONT_H
#define MTR_ABSTRACTION_FONT_H

#include <string.h>
#include <stdio.h>
#define STB_RECT_PACK_IMPLEMENTATION
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
#pragma GCC diagnostic ignored "-Wtype-limits"
#pragma GCC diagnostic ignored "-Wunused-function"
#include "stb_rect_pack.h"
#pragma GCC diagnostic pop

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faFont
#endif
#include "fa/Abstraction_font.h"

#define MTR_FONT_INITIAL_RESERVED_ATLASES 32

typedef struct mtrFont_t {
    uint32_t    *spriteAtlas;
    unsigned int reservedAtlases;
    char        *name;
} mtrFont_t;

char              mtrDefaultFontName[] = "Unnamed_Font";
mtrIndexkeeper_t *mtrFontKeeper;
static bool       mtrFontInited = false;
int               mtrTextureSides[] = {256, 512, 1024, 2048, 4096, 8192};
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

MTR_FUNC(uint32_t, MTR_TtfLoad, const char *);
MTR_FUNC(void, MTR_TtfFree, uint32_t);
MTR_FUNC(int, MTR_TtfGetGlyphHeight, uint32_t, uint32_t);
MTR_FUNC(void, MTR_TtfGetGlyphSizes, uint32_t, uint32_t, int *, int *);
MTR_FUNC(mtrPixels_t *, MTR_TtfRenderGlyph, uint32_t, uint8_t, uint8_t, uint8_t,
 uint32_t);
MTR_FUNC(uint32_t, MTR_TextureCreate, const char *, int, int);
MTR_FUNC(bool, MTR_TextureReceivePixelsToPos, uint32_t, mtrPixels_t *, int,
 int);
MTR_FUNC(int, MTR_SpriteGetFrameWidth, uint32_t, int);
MTR_FUNC(int, MTR_SpriteGetFrameHeight, uint32_t, int);
MTR_FUNC(void, MTR_SpriteDraw_f, uint32_t, int, float, float);
MTR_FUNC(uint32_t, MTR_SpriteCreateFromTexture, const char *, uint32_t, int);
MTR_FUNC(bool, MTR_SpriteSetAtlasFrame, uint32_t, int, int, int, int, int, int,
 int);

#endif
