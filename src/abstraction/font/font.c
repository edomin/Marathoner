#include "font.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Abstraction_font";
    report->version = MTR_VERSION_ABSTRACTION_FONT;
    report->subsystem = "abstraction";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 2;
    report->prereqSubsystems = malloc(sizeof(char *) * report->prereqSubsystemsCount);
    if (report->prereqSubsystems == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqSubsystems[0] = "texture";
    report->prereqSubsystems[1] = "ttf";
    return report;
}

MTR_EXPORT bool MTR_CALL mtrFontInit(uint32_t dmSize, uint32_t reservedCount)
{
    mtrLogWrite("Initializing font abstraction manager", 0, MTR_LMT_INFO);

    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTtfLoad, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTtfFree, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTtfGetFontHeight, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTtfGetStringWidth, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTtfSetFontStyle, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTtfSetFontOutline, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTtfRenderString, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlit_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureBlitRegion_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(mtrTextureReceivePixels, "texture");

    mtrFontKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrFont_t));
    if (mtrFontKeeper == NULL)
    {
        mtrNotify("Unable to create indexkeeper structure for fonts", 1,
         MTR_LMT_FATAL);
        return false;
    }
    else
        mtrLogWrite("Indexkeeper structure for fonts created", 1,
         MTR_LMT_INFO);

    mtrLogWrite("Font abstraction manager initialized", 0, MTR_LMT_INFO);
    return true;
}

MTR_EXPORT uint32_t MTR_CALL mtrFontLoadTtf(const char *filename, int size)
{
    uint32_t   freeIndex;
    mtrFont_t *font;

    mtrLogWrite_s("Loading font", 0, MTR_LMT_INFO, filename);

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrFontKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[freeIndex]);

    font->mbf = NULL;
    font->ttfIndex = mtrTtfLoad(filename, size);
    if (font->ttfIndex == 0)
    {
        mtrNotify("Unable to load font", 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
        return 0;
    }

    font->name = malloc(sizeof(char) * (strlen(filename) + 1));
    if (font->name == NULL)
        font->name = mtrDefaultFontName;
    else
        font->name = strcpy(font->name, filename);

    return freeIndex;
}

MTR_EXPORT void MTR_CALL mtrFontFree(uint32_t fontNum)
{
    mtrFont_t *font;
    if (fontNum != 0)
    {
        font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);
        mtrLogWrite_s("Unloading font", 0, MTR_LMT_INFO, font->name);
        if (font->name != mtrDefaultFontName)
            free(font->name);
        mtrTtfFree(font->ttfIndex);
        mtrIndexkeeperFreeIndex(mtrFontKeeper, fontNum);
        mtrLogWrite("Font unloaded", 0, MTR_LMT_INFO);
    }
}

MTR_EXPORT void MTR_CALL mtrFontSetTtfStyle(uint32_t fontNum, int style)
{
    mtrFont_t *font;
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);
    mtrTtfSetFontStyle(font->ttfIndex, style);
}

MTR_EXPORT void MTR_CALL mtrFontSetTtfOutline(uint32_t fontNum, int outline)
{
    mtrFont_t *font;
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);
    mtrTtfSetFontOutline(font->ttfIndex, outline);
}

MTR_EXPORT bool MTR_CALL mtrFontRenderTtfString(uint32_t fontNum,
 uint32_t texNum, uint8_t r, uint8_t g, uint8_t b, const char *string)
{
    mtrFont_t   *font;
    mtrPixels_t *pixels;
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);

    pixels = mtrTtfRenderString(font->ttfIndex, r, g, b, string);
    if (pixels == NULL)
        return false;

    return mtrTextureReceivePixels(texNum, pixels);
}

/* Create monospace bitmap font */
MTR_EXPORT uint32_t MTR_CALL mtrFontCreateMbf(const char *name,
 int reservedTables, int width, int height)
{
    uint32_t   freeIndex;
    mtrFont_t *font;

    if (name == NULL)
        name = mtrDefaultFontName;

    mtrLogWrite_s("Creating font", 0, MTR_LMT_INFO, name);

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrFontKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[freeIndex]);

    font->ttfIndex = 0;
    font->mbf = malloc(sizeof(mtrMbf_t));
    if (font->mbf == NULL)
    {
        mtrNotify("Unable to create monospace bitmap font's structure", 1,
         MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
        return 0;
    }

    font->name = malloc(sizeof(char) * (strlen(name) + 1));
    if (font->name == NULL)
        font->name = mtrDefaultFontName;
    else
        font->name = strcpy(font->name, name);

    font->mbf->width = width;
    font->mbf->height = height;
    font->mbf->reservedTables = reservedTables;
    font->mbf->texTable = malloc(sizeof(uint32_t) * reservedTables);
    if (font->mbf->texTable == NULL)
    {
        mtrNotify("Unable to allocate memory for textures' table of the monospace bitmap font",
         1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
        free(font->mbf);
        free(font->name);
        return 0;
    }

    return freeIndex;
}

MTR_EXPORT bool MTR_CALL mtrFontAddMbfTextureTable(uint32_t fontNum,
 uint32_t texNum, unsigned int tableNum)
{
    mtrFont_t *font;
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);

    if (font->mbf == NULL ||
     texNum == 0 ||
     tableNum >= font->mbf->reservedTables)
        return false;

    font->mbf->texTable[tableNum] = texNum;

    return true;
}

MTR_EXPORT bool MTR_CALL mtrFontDrawMbfString_f(uint32_t fontNum,
 float x, float y, const char *string)
{
    mtrFont_t   *font;
    uint32_t    *ucs4Text;
    size_t       ucs4Length;
    unsigned int i;
    uint32_t     symbolTable;
    int          symbolNum;
    int          symbolCol;
    int          symbolRow;
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);

    if (font->mbf == NULL)
        return false;

    ucs4Text = NULL;
    ucs4Length = mtrEncodingUtf8ToUcs4(string, &ucs4Text);

    for (i = 0; i < ucs4Length; i++)
    {
        symbolTable = ucs4Text[i] >> 8;
        if (symbolTable >= font->mbf->reservedTables)
            continue;
        symbolNum = ucs4Text[i] - (symbolTable << 8);
        symbolRow = (symbolNum >> 4);
        symbolCol = (symbolNum - (symbolRow << 4));
        mtrTextureBlitRegion_f(font->mbf->texTable[symbolTable],
         x + i * font->mbf->width, y, symbolCol * font->mbf->width,
         symbolRow * font->mbf->height, font->mbf->width, font->mbf->height);
    }

    free(ucs4Text);

    return true;
}

MTR_EXPORT int MTR_CALL mtrFontGetHeight(uint32_t fontNum)
{
    mtrFont_t *font;
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);
    if (font->ttfIndex > 0)
        return mtrTtfGetFontHeight(font->ttfIndex);
    if (font->mbf != NULL)
        return font->mbf->height;
    return 0;
}

MTR_EXPORT int MTR_CALL mtrFontGetStringWidth(uint32_t fontNum,
 const char *string)
{
    mtrFont_t *font;

    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);
    if (font->ttfIndex > 0)
        return mtrTtfGetStringWidth(font->ttfIndex, string);
    if (font->mbf != NULL)
        return font->mbf->width * mtrEncodingUtf8Codepoints(string);
    return 0;
}

MTR_EXPORT char *MTR_CALL mtrFontGetName(uint32_t fontNum)
{
    mtrFont_t *font;
    font = (mtrFont_t *)(&((mtrFont_t *)mtrFontKeeper->data)[fontNum]);
    return font->name;
}
