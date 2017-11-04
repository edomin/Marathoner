#include "ttf.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Ttf, FA_FUNCTIONS_COUNT)

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
MTR_DCLSPC uint32_t MTR_CALL MTR_TtfLoad(const char *filename, int size)
{
    uint32_t  freeIndex;
    mtrTtf_t *font;
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
    font->font = TTF_OpenFont(filename, size);
    if (font->font != NULL)
    {
        font->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (font->name == NULL)
            font->name = mtrDefaultTTFName;
        else
            font->name = strcpy(font->name, filename);
        MTR_LogWrite_s("TTF font loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    }
    else
    {
        MTR_Notify("Unable to load TTF font", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrTtfKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa MTR_TtfGetFontHeight yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetFontHeight(uint32_t fontNum)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    if (font->font != NULL)
        return TTF_FontHeight(font->font);
    else
        return 0;
}

/*fa MTR_TtfGetStringSizes yes */
MTR_DCLSPC bool MTR_CALL MTR_TtfGetStringSizes(uint32_t fontNum,
 const char *string, int *w, int *h)
{
    mtrTtf_t *font;

    if (!mtrTtfInited)
    {
        *w = 0;
        *h = 0;
        return false;
    }

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    if (font->font == NULL || string == NULL)
    {
        if (w != NULL)
            *w = 0;
        if (h != NULL)
            *h = 0;
        return false;
    }
    if (TTF_SizeUTF8(font->font, string, w, h) == 0)
        return true;
    else
        return false;
}

/*fa MTR_TtfGetStringWidth yes */
MTR_DCLSPC int MTR_CALL MTR_TtfGetStringWidth(uint32_t fontNum,
 const char *string)
{
    mtrTtf_t *font;
    int       width;
    MTR_TTF_CHECK_IF_NOT_INITED(0);

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    if (font->font == NULL || string == NULL)
    {
        return 0;
    }
    if (TTF_SizeUTF8(font->font, string, &width, NULL) == 0)
        return width;
    else
        return 0;
}

/*fa MTR_TtfSetFontStyle yes */
MTR_DCLSPC void MTR_CALL MTR_TtfSetFontStyle(uint32_t fontNum, int style)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED();

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    TTF_SetFontStyle(font->font, style);
}

/*fa MTR_TtfSetFontOutline yes */
MTR_DCLSPC void MTR_CALL MTR_TtfSetFontOutline(uint32_t fontNum, int outline)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED();

    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    TTF_SetFontOutline(font->font, outline);
}

/*fa MTR_TtfFree yes */
MTR_DCLSPC void MTR_CALL MTR_TtfFree(uint32_t fontNum)
{
    mtrTtf_t *font;
    MTR_TTF_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload TTF font",);

    if (fontNum != 0)
    {
        font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
        MTR_LogWrite_s("Unloading TTF font", 0, MTR_LMT_INFO, font->name);
        if (font->name != mtrDefaultTTFName)
            free(font->name);
        TTF_CloseFont(font->font);
        MTR_IndexkeeperFreeIndex(mtrTtfKeeper, fontNum);
        MTR_LogWrite("TTF font unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa MTR_TtfRenderString yes */
MTR_DCLSPC mtrPixels_t *MTR_CALL MTR_TtfRenderString(uint32_t fontNum, uint8_t r,
 uint8_t g, uint8_t b, const char *string)
{
    mtrTtf_t        *font;
    SDL_Color        textcolor;
    SDL_Surface     *renderedSurface;
    int              success;
    MTR_TTF_CHECK_IF_NOT_INITED(NULL);

    if (string == NULL)
        return NULL;

    if (tempSurface != NULL)
    {
        SDL_FreeSurface(tempSurface);
        tempSurface = NULL;
    }
    if (tempPixels != NULL)
        free(tempPixels);

    if (fontNum != 0)
    {
        font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);

        textcolor.r = r;
        textcolor.g = g;
        textcolor.b = b;
        renderedSurface = TTF_RenderUTF8_Blended(font->font, string, textcolor);
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
    }
    return tempPixels;
}
