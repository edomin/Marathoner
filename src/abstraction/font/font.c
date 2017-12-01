#include "font.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Abstraction_font";
    report->version = MTR_VERSION_ABSTRACTION_FONT;
    report->subsystem = "abstraction";

    report->prereqsCount = 1;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    if (report->prereqs == NULL) {
        free(report);
        return NULL;
    }
    report->prereqs[0] = "Abstraction_sprite";

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
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Font, FA_FUNCTIONS_COUNT)

/*fa MTR_FontInit yes */
MTR_DCLSPC bool MTR_CALL MTR_FontInit(uint32_t dmSize, uint32_t reservedCount)
{
    #ifdef MTR_MOD_PLUGIN
    bool ok = true;
    #endif

    MTR_LogWrite("Initializing font abstraction manager", 0, MTR_LMT_INFO);

    #ifdef MTR_MOD_PLUGIN
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfLoad, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfFree, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfSetStyle, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfSetOutline, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfGetGlyphSizes, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TtfRenderGlyph, "ttf");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureCreate, "texture");
    MTR_FIND_FUNCTION_IN_SUBSYSTEM(MTR_TextureReceivePixelsToPos, "texture");
    MTR_FIND_FUNCTION(MTR_SpriteGetFrameWidth, "Abstraction_sprite");
    MTR_FIND_FUNCTION(MTR_SpriteGetFrameHeight, "Abstraction_sprite");
    MTR_FIND_FUNCTION(MTR_SpriteDraw_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(MTR_SpriteCreateFromTexture, "Abstraction_sprite");
    MTR_FIND_FUNCTION(MTR_SpriteSetAtlasFrame, "Abstraction_sprite");

    if (ok)
        MTR_LogWrite("Added dependent functions", 1, MTR_LMT_INFO);
    else {
        MTR_Notify("Functions not added", 1, MTR_LMT_FATAL);
        return false;
    }
    #endif

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

/*fa MTR_FontCreate yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_FontCreate(const char *name,
 int reservedAtlases)
{
    uint32_t   freeIndex;
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED_WITH_LOG("Unable to create font", 0U);

    MTR_LogWrite_s("Creating font", 0, MTR_LMT_INFO, name);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrFontKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, freeIndex);

    font->name = malloc(sizeof(char) * (strlen(name) + 1));
    if (font->name == NULL)
        font->name = mtrDefaultFontName;
    else
        font->name = strcpy(font->name, name);

    font->reservedAtlases = reservedAtlases;
    font->spriteAtlas = malloc(sizeof(uint32_t) * reservedAtlases);
    if (font->spriteAtlas == NULL) {
        if (font->name != mtrDefaultFontName)
            free(font->name);
        MTR_IndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
        return 0U;
    }

    return freeIndex;
}

/*fa MTR_FontAddAtlas yes */
MTR_DCLSPC bool MTR_CALL MTR_FontAddAtlas(uint32_t fontNum, uint32_t sprNum,
 unsigned int atlasNum)
{
    mtrFont_t *font;
    uint32_t  *oldSpriteAtlas;
    int        oldReservedAtlases;
    MTR_FONT_CHECK_IF_NOT_INITED(false);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);

    if (sprNum == 0)
        return false;

    if (atlasNum >= font->reservedAtlases) {
        oldReservedAtlases = font->reservedAtlases;
        oldSpriteAtlas = font->spriteAtlas;
        font->reservedAtlases = atlasNum + 1;
        font->spriteAtlas = realloc(font->spriteAtlas,
         sizeof(uint32_t) * font->reservedAtlases);
        if (font->spriteAtlas == NULL) {
            font->spriteAtlas = oldSpriteAtlas;
            font->reservedAtlases = oldReservedAtlases;
            return false;
        }
    }

    font->spriteAtlas[atlasNum] = sprNum;

    return true;
}

bool MTR_FontTryToPackTtf(uint32_t ttfNum, int textureSide, int currentAtlas,
 stbrp_rect *glyph)
{
    stbrp_node   *node;
    int           nodesCount;
    stbrp_context rectPackContext;
    int           i;
    int           glyphWidth;
    int           glyphHeight;
    bool          success = true;

    nodesCount = textureSide * 2;
    node = malloc(sizeof(stbrp_node) * nodesCount);
    if (node == NULL) {
        MTR_LogWrite(
         "Unable to allocate memory for nodes needed by packing algorithm", 2,
         MTR_LMT_ERROR);
        return false;
    }
    MTR_LogWrite("DEBUG 1", 2, MTR_LMT_DEBUG);
    for (i = 0; i < 256; i++) {
        glyph[i].id = i;
        glyph[i].x = 0;
        glyph[i].y = 0;
        glyph[i].was_packed = false;
        MTR_TtfGetGlyphSizes(ttfNum, (currentAtlas << 8) | i, &glyphWidth,
         &glyphHeight);
        glyph[i].w = glyphWidth;
        glyph[i].h = glyphHeight;
    }
    MTR_LogWrite("DEBUG 2", 2, MTR_LMT_DEBUG);
    stbrp_init_target (&rectPackContext, textureSide, textureSide, node,
     nodesCount);
    MTR_LogWrite("DEBUG 3", 2, MTR_LMT_DEBUG);
//    stbrp_setup_allow_out_of_mem (&rectPackContext, true);
    stbrp_pack_rects(&rectPackContext, glyph, 256);
    MTR_LogWrite("DEBUG 4", 2, MTR_LMT_DEBUG);
    for (i = 0; i < 256; i++) {
        if (!glyph[i].was_packed) {
            success = false;
            break;
        }
//        MTR_LogWrite_i("glyph x", 2, MTR_LMT_DEBUG, glyph[i].x);
//        MTR_LogWrite_i("glyph y", 2, MTR_LMT_DEBUG, glyph[i].y);
    }
    MTR_LogWrite("DEBUG 5", 2, MTR_LMT_DEBUG);
    free(node);
    MTR_LogWrite("DEBUG 6", 2, MTR_LMT_DEBUG);
    return success;
}

/*fa MTR_FontCacheTtf yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_FontCacheTtf(const char *name, uint32_t ttfNum,
 unsigned int reservedAtlases)
{
    uint32_t     freeIndex;
    mtrFont_t   *font;
//    bool         success;
    unsigned int i;
    int          j;
    int          currentTexSide;
    int          texSideNum;
    uint32_t     spriteIndex;
    uint32_t     textureIndex;
    bool         packed;
    stbrp_rect   glyph[256];
    mtrPixels_t *renderedGlyph;
    MTR_FONT_CHECK_IF_NOT_INITED_WITH_LOG("Unable to cache TTF", 0U);

    MTR_LogWrite_s("Caching TTF", 0, MTR_LMT_INFO, name);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrFontKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, freeIndex);

    font->reservedAtlases = reservedAtlases;
    font->spriteAtlas = malloc(sizeof(uint32_t) * reservedAtlases);
    if (font->spriteAtlas == NULL) {
        MTR_IndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
        return 0U;
    }

    for (i = 0; i < font->reservedAtlases; i++) {
        texSideNum = 0;
        currentTexSide = mtrTextureSides[texSideNum];
        while (currentTexSide <= 2048) {
            MTR_LogWrite_i(
             "Trying to generate glyph positions in atlas with side", 1,
             MTR_LMT_INFO, currentTexSide);
            packed = MTR_FontTryToPackTtf(ttfNum, currentTexSide, i, glyph);
            if (packed) {
                MTR_LogWrite("Success", 2, MTR_LMT_INFO);
                break;
            }
            MTR_LogWrite("Failed", 2, MTR_LMT_INFO);
            texSideNum += 1;
            currentTexSide = mtrTextureSides[texSideNum];
        }
        if (!packed) {
            MTR_LogWrite("Unable to generate glyph positions in atlas", 1,
             MTR_LMT_ERROR);
            MTR_IndexkeeperFreeIndex(mtrFontKeeper, freeIndex);
            return 0U;
        }

        textureIndex = MTR_TextureCreate(name, currentTexSide,
         currentTexSide);
        spriteIndex = MTR_SpriteCreateFromTexture(name, textureIndex, 256);
        MTR_FontAddAtlas(freeIndex, spriteIndex, i);

        for (j = 0; j < 256; j++) {
            renderedGlyph = MTR_TtfRenderGlyph(ttfNum, 0xFF, 0xFF, 0xFF,
             (i << 8) | j);
            if (renderedGlyph == NULL) {
                MTR_LogWrite_i("Unable to render glyph", 0, MTR_LMT_NOTE,
                 (i << 8) | j);
            } else {
                MTR_TextureReceivePixelsToPos(textureIndex, renderedGlyph,
                 glyph[j].x, glyph[j].y);
            }
            MTR_SpriteSetAtlasFrame(spriteIndex, j, glyph[j].x, glyph[j].y,
             glyph[j].x + glyph[j].w - 1, glyph[j].y + glyph[j].h - 1, 0, 0);
        }
    }

    font->name = malloc(sizeof(char) * (strlen(name) + 1));
    if (font->name == NULL)
        font->name = mtrDefaultFontName;
    else
        font->name = strcpy(font->name, name);

    return freeIndex;
}

/*fa MTR_FontFree yes */
MTR_DCLSPC void MTR_CALL MTR_FontFree(uint32_t fontNum)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload font",);

    if (fontNum == 0)
        return;

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
    MTR_LogWrite_s("Unloading font", 0, MTR_LMT_INFO, font->name);
    if (font->name != mtrDefaultFontName)
        free(font->name);
    MTR_IndexkeeperFreeIndex(mtrFontKeeper, fontNum);
    MTR_LogWrite("Font unloaded", 0, MTR_LMT_INFO);
}

/*fa MTR_FontSetStyle yes */
MTR_DCLSPC void MTR_CALL MTR_FontSetStyle(uint32_t fontNum, int style)
{
//    mtrFont_t *font;
//    MTR_FONT_CHECK_IF_NOT_INITED();
//
//    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
//    if (font->ttfIndex != 0)
//        MTR_TtfSetFontStyle(font->ttfIndex, style);
}

/*fa MTR_FontSetOutline yes */
MTR_DCLSPC void MTR_CALL MTR_FontSetOutline(uint32_t fontNum, int outline)
{
//    mtrFont_t *font;
//    MTR_FONT_CHECK_IF_NOT_INITED();
//
//    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
//    if (font->ttfIndex != 0)
//        MTR_TtfSetFontOutline(font->ttfIndex, outline);
}

/*fa MTR_FontDrawString_f yes */
MTR_DCLSPC bool MTR_CALL MTR_FontDrawString_f(uint32_t fontNum,
 float x, float y, const char *string)
{
    mtrFont_t   *font;
    uint32_t    *ucs4Text = NULL;
    size_t       ucs4Length;
    unsigned int i;
    uint32_t     glyphAtlas;
    int          symbolNum;
    int          xOffset = 0;
    uint32_t     sprNum;
    MTR_FONT_CHECK_IF_NOT_INITED(false);

    if (string == NULL || fontNum == 0)
        return false;

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);

    ucs4Length = MTR_EncodingUtf8ToUcs4(string, &ucs4Text);

    for (i = 0; i < ucs4Length; i++) {
        glyphAtlas = ucs4Text[i] >> 8;
        if (glyphAtlas >= font->reservedAtlases)
            continue;
        symbolNum = ucs4Text[i] - (glyphAtlas << 8);

        sprNum = font->spriteAtlas[glyphAtlas];

        MTR_SpriteDraw_f(sprNum, symbolNum, x + xOffset, y);
        xOffset += MTR_SpriteGetFrameWidth(sprNum, symbolNum);
    }

    free(ucs4Text);

    return true;
}

/*fa MTR_FontGetHeight yes */
MTR_DCLSPC int MTR_CALL MTR_FontGetHeight(uint32_t fontNum)
{
    mtrFont_t   *font;
    unsigned int i;
    int          j;
    int          maxHeight = 0;
    int          currentSymbolHeight;
    MTR_FONT_CHECK_IF_NOT_INITED(0);

    if (fontNum == 0)
        return 0;

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);

    for (i = 0; i < font->reservedAtlases; i++) {
        for (j = 0; j < 256; j++) {
            currentSymbolHeight = MTR_SpriteGetFrameHeight(font->spriteAtlas[i], j);
            if (currentSymbolHeight > maxHeight)
                maxHeight = currentSymbolHeight;
        }
    }
    return maxHeight;
}

/*fa MTR_FontGetStringWidth yes */
MTR_DCLSPC int MTR_CALL MTR_FontGetStringWidth(uint32_t fontNum,
 const char *string)
{
    mtrFont_t   *font;
    uint32_t    *ucs4Text = NULL;
    size_t       ucs4Length;
    unsigned int i;
    unsigned int glyphAtlas;
    int          symbolNum;
    uint32_t     sprNum;
    int          xOffset = 0;
    MTR_FONT_CHECK_IF_NOT_INITED(0);

    if (string == NULL || fontNum == 0)
        return 0;

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);

    ucs4Length = MTR_EncodingUtf8ToUcs4(string, &ucs4Text);

    MTR_LogWrite_i("ucs4Length", 0, MTR_LMT_DEBUG, ucs4Length);
    for (i = 0; i < ucs4Length; i++) {
        glyphAtlas = ucs4Text[i] >> 8;
        if (glyphAtlas >= font->reservedAtlases)
            continue;
        symbolNum = ucs4Text[i] - (glyphAtlas << 8);

        sprNum = font->spriteAtlas[glyphAtlas];

        xOffset += MTR_SpriteGetFrameWidth(sprNum, symbolNum);
        MTR_LogWrite_i("xOffset", 0, MTR_LMT_DEBUG, xOffset);
    }

    return xOffset;
}

/*fa MTR_FontGetName yes */
MTR_DCLSPC char *MTR_CALL MTR_FontGetName(uint32_t fontNum)
{
    mtrFont_t *font;
    MTR_FONT_CHECK_IF_NOT_INITED(NULL);

    font = IK_GET_DATA(mtrFont_t *, mtrFontKeeper, fontNum);
    return font->name;
}
