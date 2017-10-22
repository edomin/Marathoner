#include "font.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Font, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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
    report->prereqSubsystems = malloc(
     sizeof(char *) * report->prereqSubsystemsCount);
    if (report->prereqSubsystems == NULL)
    {
        free(report);
        return NULL;
    }
    report->prereqSubsystems[0] = "texture";
    report->prereqSubsystems[1] = "ttf";
    return report;
}

/*fa MTR_FontInit yes */
MTR_DCLSPC bool MTR_CALL MTR_FontInit(uint32_t dmSize, uint32_t reservedCount)
{
    MTR_LogWrite("Initializing font abstraction manager", 0, MTR_LMT_INFO);

    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfLoad, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfFree, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfGetFontHeight, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfGetStringWidth, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfSetFontStyle, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfSetFontOutline, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfRenderString, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlit_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureBlitRegion_f, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureReceivePixels, "texture");

    mtrFontKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrFont_t));
    if (mtrFontKeeper == NULL)
    {
        MTR_Notify("Unable to create indexkeeper structure for fonts", 1,
         MTR_LMT_FATAL);
        return false;
    }
    else
        MTR_LogWrite("Indexkeeper structure for fonts created", 1,
         MTR_LMT_INFO);

    MTR_LogWrite("Font abstraction manager initialized", 0, MTR_LMT_INFO);

    mtrFontInited = true;
    return true;
}

/*fa MTR_FontLoadTtf yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_FontLoadTtf(const char *filename, int size)
{
    uint32_t   freeIndex;
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load font", 0U);

    MTR_LogWrite_s("Loading font", 0, MTR_LMT_INFO, filename);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrFontKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, freeIndex);

    font->mbf = NULL;
    font->ttfIndex = MTR_TtfLoad(filename, size);
    if (font->ttfIndex == 0)
    {
        MTR_Notify("Unable to load font", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
        return 0;
    }

    font->name = malloc(sizeof(char) * (strlen(filename) + 1));
    if (font->name == NULL)
        font->name = mtrDefaultFontName;
    else
        font->name = strcpy(font->name, filename);

    return freeIndex;
}

/*fa MTR_FontFree yes */
MTR_DCLSPC void MTR_CALL MTR_FontFree(uint32_t fontNum)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload font",);

    if (fontNum != 0)
    {
        font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
        MTR_LogWrite_s("Unloading font", 0, MTR_LMT_INFO, font->name);
        if (font->name != mtrDefaultFontName)
            free(font->name);
        MTR_TtfFree(font->ttfIndex);
        MTR_IndexkeeperFreeIndex(mtrFontKeeper, fontNum);
        MTR_LogWrite("Font unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa MTR_FontSetTtfStyle yes */
MTR_DCLSPC void MTR_CALL MTR_FontSetTtfStyle(uint32_t fontNum, int style)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED();

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
    MTR_TtfSetFontStyle(font->ttfIndex, style);
}

/*fa MTR_FontSetTtfOutline yes */
MTR_DCLSPC void MTR_CALL MTR_FontSetTtfOutline(uint32_t fontNum, int outline)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED();

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
    MTR_TtfSetFontOutline(font->ttfIndex, outline);
}

/*fa MTR_FontRenderTtfString yes */
MTR_DCLSPC bool MTR_CALL MTR_FontRenderTtfString(uint32_t fontNum,
 uint32_t texNum, uint8_t r, uint8_t g, uint8_t b, const char *string)
{
    mtrFont_t   *font;
    mtrPixels_t *pixels;
    MTR_FONT_CHECK_IF_NOT_INITED(false);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);

    pixels = MTR_TtfRenderString(font->ttfIndex, r, g, b, string);
    if (pixels == NULL)
        return false;

    return MTR_TextureReceivePixels(texNum, pixels);
}

/* Create monospace bitmap font */
/*fa MTR_FontCreateMbf yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_FontCreateMbf(const char *name,
 int reservedTables, int width, int height)
{
    uint32_t   freeIndex;
    mtrFont_t *font;
    int        i;
    MTR_FONT_CHECK_IF_NOT_INITED_WITH_LOG("Unable to create font", 0U);

    if (name == NULL)
        name = mtrDefaultFontName;

    MTR_LogWrite_s("Creating font", 0, MTR_LMT_INFO, name);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrFontKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, freeIndex);

    font->ttfIndex = 0;
    font->mbf = malloc(sizeof(mtrMbf_t));
    if (font->mbf == NULL)
    {
        MTR_Notify("Unable to create monospace bitmap font's structure", 1,
         MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
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
        MTR_Notify("Unable to allocate memory for textures' table of the "
                  "monospace bitmap font",
         1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
        free(font->mbf);
        free(font->name);
        return 0;
    }
    for (i = 0; i < reservedTables; i++)
    {
        font->mbf->texTable[i] = 0;
    }

    return freeIndex;
}

/*fa MTR_FontAddMbfTextureTable yes */
MTR_DCLSPC bool MTR_CALL MTR_FontAddMbfTextureTable(uint32_t fontNum,
 uint32_t texNum, unsigned int tableNum)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED(false);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);

    if (font->mbf == NULL ||
     texNum == 0 ||
     tableNum >= font->mbf->reservedTables)
        return false;

    font->mbf->texTable[tableNum] = texNum;

    return true;
}

/*fa MTR_FontDrawMbfString_f yes */
MTR_DCLSPC bool MTR_CALL MTR_FontDrawMbfString_f(uint32_t fontNum,
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
    MTR_FONT_CHECK_IF_NOT_INITED(false);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);

    if (font->mbf == NULL || string == NULL)
        return false;

    ucs4Text = NULL;
    ucs4Length = MTR_EncodingUtf8ToUcs4(string, &ucs4Text);

    for (i = 0; i < ucs4Length; i++)
    {
        symbolTable = ucs4Text[i] >> 8;
        if (symbolTable >= font->mbf->reservedTables)
            continue;
        symbolNum = ucs4Text[i] - (symbolTable << 8);
        symbolRow = (symbolNum >> 4);
        symbolCol = (symbolNum - (symbolRow << 4));
        if (font->mbf->texTable[symbolTable] != 0)
        {
            MTR_TextureBlitRegion_f(font->mbf->texTable[symbolTable],
             x + i * font->mbf->width, y, symbolCol * font->mbf->width,
             symbolRow * font->mbf->height, font->mbf->width,
             font->mbf->height);
        }
    }

    free(ucs4Text);

    return true;
}

/*fa MTR_FontGetHeight yes */
MTR_DCLSPC int MTR_CALL MTR_FontGetHeight(uint32_t fontNum)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
    if (font->ttfIndex > 0)
        return MTR_TtfGetFontHeight(font->ttfIndex);
    if (font->mbf != NULL)
        return font->mbf->height;
    return 0;
}

/*fa MTR_FontGetStringWidth yes */
MTR_DCLSPC int MTR_CALL MTR_FontGetStringWidth(uint32_t fontNum,
 const char *string)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
    if (font->ttfIndex > 0)
        return MTR_TtfGetStringWidth(font->ttfIndex, string);
    if (font->mbf != NULL)
        return font->mbf->width * MTR_EncodingUtf8Codepoints(string);
    return 0;
}

/*fa MTR_FontGetName yes */
MTR_DCLSPC char *MTR_CALL MTR_FontGetName(uint32_t fontNum)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED(NULL);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
    return font->name;
}
