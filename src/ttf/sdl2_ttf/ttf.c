#include "ttf.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "TTF_SDL2_ttf";
    report->version = MTR_VERSION_TTF_SDL2_TTF;
    report->subsystem = "ttf";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Ttf, FA_FUNCTIONS_COUNT)

/*fa MTR_TtfInit yes */
MTR_DCLSPC bool MTR_CALL MTR_TtfInit(uint32_t dmSize, uint32_t reservedCount)
{
    SDL_version        compiled;
    const SDL_version *linked;

    MTR_LogWrite("Initializing TTF font manager", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL_ttf compile-time version:", 1, MTR_LMT_INFO);
    SDL_TTF_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL_ttf linked version:", 1, MTR_LMT_INFO);
    linked = TTF_Linked_Version();
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, linked->major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, linked->minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, linked->patch);

    tempSurface = NULL;
    tempPixels = NULL;

    if(TTF_Init() != 0)
    {
        MTR_LogWrite("Unable to initialize SDL_ttf", 1, MTR_LMT_INFO);
        return false;
    }

    mtrTtfKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrTtf_t));
    if (mtrTtfKeeper == NULL)
    {
        MTR_Notify("Unable to initialize texture manager", 1, MTR_LMT_ERROR);
        TTF_Quit();
        return false;
    }
    else
        MTR_LogWrite("TTF font manager initialized", 0, MTR_LMT_INFO);

    mtrTtfInited = true;
    return true;
}

/*fa MTR_TtfQuit yes */
MTR_DCLSPC void MTR_CALL MTR_TtfQuit(void)
{
    MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG("Unable to destroy TTF font manager",);

    MTR_LogWrite("Destroying TTF font manager", 0, MTR_LMT_INFO);
    TTF_Quit();
    MTR_LogWrite("TTF font manager destroyed", 0, MTR_LMT_INFO);
}

/*fa MTR_TtfLoad yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_TtfLoad(const char *filename)
{
    uint32_t  freeIndex;
    mtrTtf_t *font;
    int       i;
    MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load TTF font", 0U);

    if (filename == NULL) {
        MTR_Notify("Unable to load ttf-font. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return 0U;
    }

    MTR_LogWrite_s("Loading TTF font", 0, MTR_LMT_INFO, filename);
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrTtfKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, freeIndex);

    font->filename = malloc(sizeof(char) * (strlen(filename) + 1));
    if (font->filename == NULL) {
        MTR_LogWrite(
         "Unable to allocate memory for TTF's filename", 0, MTR_LMT_INFO);
        return 0U;
    }
    font->filename = strcpy(font->filename, filename);

    font->maxHeight = MTR_TTF_INITIAL_MAX_HEIGHT;
    font->font = malloc(sizeof(TTF_Font *) * (font->maxHeight + 1));
    if (font->font == NULL) {
        MTR_LogWrite(
         "Unable to allocate memory for array of various TTF's sizes", 0,
          MTR_LMT_INFO);
        free(font->filename);
        return 0U;
    }
    for (i = 0; i <= font->maxHeight; i++) {
        font->font[i] = NULL;
    }
    font->width = 0;
    font->height = 0;

    MTR_LogWrite_s("TTF font loaded", 0, MTR_LMT_INFO, filename);
    return freeIndex;
}

/*fa MTR_TtfFree yes */
MTR_DCLSPC void MTR_CALL MTR_TtfFree(uint32_t fontNum)
{
    mtrTtf_t *font;
    int       i;
    MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload TTF font",);

    if (fontNum != 0)
    {
        font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
        MTR_LogWrite_s("Unloading TTF font", 0, MTR_LMT_INFO, font->filename);
        free(font->filename);
        for (i = 0; i <= font->maxHeight; i++) {
            if (font->font[i] != NULL) {
                TTF_CloseFont(font->font[i]);
                font->font[i] = NULL;
            }
        }
        MTR_IndexkeeperFreeIndex(mtrTtfKeeper, fontNum);
        MTR_LogWrite("TTF font unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa MTR_TtfGetWidth yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetWidth(uint32_t fontNum)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    if (font->font == NULL)
        return 0;

    return font->width;
}

/*fa MTR_TtfGetHeight yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetHeight(uint32_t fontNum)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    if (font->font == NULL)
        return 0;

    return font->height;
}

/*fa MTR_TtfGetSizes yes */
MTR_DCLSPC void MTR_CALL MTR_TtfGetSizes(uint32_t fontNum, int *width,
 int *height)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED();

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    if (font->font == NULL) {
        *width = 0;
        *height = 0;
    }

    *width = font->width;
    *height = font->height;
}

/*fa MTR_TtfSetSizes yes */
MTR_DCLSPC bool MTR_CALL MTR_TtfSetSizes(uint32_t fontNum, int width,
 int height)
{
    mtrTtf_t *font;
    int       i;
    int       oldMaxHeight;
    MTR_TTF_CHECK_IF_NOT_INITED(false);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    if (font->font == NULL)
        return false;

    if (height > font->maxHeight) {
        oldMaxHeight = font->maxHeight;
        font->maxHeight = height;
        font->font = realloc(font->font,
         sizeof(TTF_Font *) * (font->maxHeight + 1));
        if (font->font == NULL)
            return false;
        for (i = oldMaxHeight + 1; i <= font->maxHeight; i++) {
            font->font[i] = NULL;
        }
    }

    if (font->font[height] == NULL) {
        font->font[height] = TTF_OpenFont(font->filename, height);
        if (font->font[height] == NULL)
            return false;
    }

    font->width = width;
    font->height = height;

    return true;
}

/*fa MTR_TtfGetStyle yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetStyle(uint32_t fontNum)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    return TTF_GetFontStyle(font->font[font->height]);
}

/*fa MTR_TtfGetOutline yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetOutline(uint32_t fontNum)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    return TTF_GetFontOutline(font->font[font->height]);
}

/*fa MTR_TtfSetStyle yes */
MTR_DCLSPC void MTR_CALL MTR_TtfSetStyle(uint32_t fontNum, int style)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED();

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    TTF_SetFontStyle(font->font[font->height], style);
}

/*fa MTR_TtfSetOutline yes */
MTR_DCLSPC void MTR_CALL MTR_TtfSetOutline(uint32_t fontNum, int outline)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED();

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    TTF_SetFontOutline(font->font[font->height], outline);
}

/*fa MTR_TtfGetGlyphSizes yes */
MTR_DCLSPC void MTR_CALL MTR_TtfGetGlyphSizes(uint32_t fontNum,
 uint32_t glyph, int *w, int *h)
{
    mtrTtf_t *font;
    int       miny;
    int       maxy;
    int       advance;
    int       glyphMetricsGet;
    MTR_TTF_CHECK_IF_NOT_INITED();

    if ((fontNum == 0) || (glyph >= UINT16_MAX)) {
        *w = 0;
        *h = 0;
        return;
    }

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    glyphMetricsGet = TTF_GlyphMetrics(font->font[font->height], glyph, NULL,
     NULL, &miny, &maxy, &advance);
    if(glyphMetricsGet == -1) {
        *w = 0;
        *h = 0;
        return;
    }

    *w = advance;
    *h = maxy - miny;
}

/*fa MTR_TtfGetGlyphWidth yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetGlyphWidth(uint32_t fontNum, uint32_t glyph)
{
    mtrTtf_t *font;
    int       advance;
    int       glyphMetricsGet;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    if ((fontNum == 0) || (glyph >= UINT16_MAX))
        return 0;

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    glyphMetricsGet = TTF_GlyphMetrics(font->font[font->height], glyph, NULL,
     NULL, NULL, NULL, &advance);
    if(glyphMetricsGet == -1)
        return 0;

    return advance;
}

/*fa MTR_TtfGetGlyphHeight yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetGlyphHeight(uint32_t fontNum, uint32_t glyph)
{
    mtrTtf_t *font;
    int       miny;
    int       maxy;
    int       glyphMetricsGet;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    if ((fontNum == 0) || (glyph >= UINT16_MAX))
        return 0;

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    glyphMetricsGet = TTF_GlyphMetrics(font->font[font->height], glyph, NULL,
     NULL, &miny, &maxy, NULL);
    if(glyphMetricsGet == -1)
        return 0;

    return maxy - miny;
}

/*fa MTR_TtfRenderGlyph yes */
MTR_DCLSPC mtrPixels_t *MTR_CALL MTR_TtfRenderGlyph(uint32_t fontNum,
 uint8_t r, uint8_t g, uint8_t b, uint32_t glyph)
{
    mtrTtf_t        *font;
    SDL_Color        textcolor;
    SDL_Surface     *renderedSurface;
    int              success;
    MTR_TTF_CHECK_IF_NOT_INITED(NULL);

    if (tempSurface != NULL)
    {
        SDL_FreeSurface(tempSurface);
        tempSurface = NULL;
    }
    if (tempPixels != NULL) {
        free(tempPixels);
        tempPixels = NULL;
    }

    if ((fontNum == 0) || (glyph >= UINT16_MAX))
        return NULL;

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

    textcolor.r = r;
    textcolor.g = g;
    textcolor.b = b;
    renderedSurface = TTF_RenderGlyph_Blended(font->font[font->height],
     glyph, textcolor);
    if (renderedSurface == NULL)
        return NULL;

    tempSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, renderedSurface->w,
     renderedSurface->h, 32, 0xFF000000, 0x00FF0000, 0x0000FF00,
     0x000000FF);
    if (tempSurface == NULL)
    {
        SDL_FreeSurface(renderedSurface);
        return NULL;
    }

    success = SDL_UpperBlit(renderedSurface, NULL, tempSurface, NULL);

    SDL_FreeSurface(renderedSurface);

    if (success == -1)
        return NULL;

    tempPixels = malloc(sizeof(mtrPixels_t));

    tempPixels->data = tempSurface->pixels;
    tempPixels->w = tempSurface->w;
    tempPixels->h = tempSurface->h;
    tempPixels->pitch = tempSurface->pitch;
    tempPixels->pixelformat = MTR_PF_RGBA;
    return tempPixels;
}
