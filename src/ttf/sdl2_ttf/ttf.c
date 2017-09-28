#include "ttf.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Ttf, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
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

/*fa mtrTtfInit yes */
MTR_EXPORT bool MTR_CALL mtrTtfInit(uint32_t dmSize, uint32_t reservedCount)
{
    SDL_version        compiled;
    const SDL_version *linked;

    mtrLogWrite("Initializing TTF font manager", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL_ttf compile-time version:", 1, MTR_LMT_INFO);
    SDL_TTF_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL_ttf linked version:", 1, MTR_LMT_INFO);
    linked = TTF_Linked_Version();
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, linked->major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, linked->minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, linked->patch);

    tempSurface = NULL;
    tempPixels = NULL;

    if(TTF_Init() != 0)
    {
        mtrLogWrite("Unable to initialize SDL_ttf", 1, MTR_LMT_INFO);
        return false;
    }

    mtrTtfKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrTtf_t));
    if (mtrTtfKeeper == NULL)
    {
        mtrNotify("Unable to initialize texture manager", 1, MTR_LMT_ERROR);
        TTF_Quit();
        return false;
    }
    else
        mtrLogWrite("TTF font manager initialized", 0, MTR_LMT_INFO);

    return true;
}

/*fa mtrTtfQuit yes */
MTR_EXPORT void MTR_CALL mtrTtfQuit(void)
{
    mtrLogWrite("Destroying TTF font manager", 0, MTR_LMT_INFO);
    TTF_Quit();
    mtrLogWrite("TTF font manager destroyed", 0, MTR_LMT_INFO);
}

/*fa mtrTtfLoad yes */
MTR_EXPORT uint32_t MTR_CALL mtrTtfLoad(const char *filename, int size)
{
    uint32_t    freeIndex;
    mtrTtf_t   *font;

    mtrLogWrite_s("Loading TTF font", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTtfKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, freeIndex);
    font->font = TTF_OpenFont(filename, size);
    if (font->font != NULL)
    {
        font->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (font->name == NULL)
            font->name = mtrDefaultTTFName;
        else
            font->name = strcpy(font->name, filename);
        mtrLogWrite_s("TTF font loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to load TTF font", 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrTtfKeeper, freeIndex);
        return 0;
    }
    return 0;
}

/*fa mtrTtfGetFontHeight yes */
MTR_EXPORT int MTR_CALL mtrTtfGetFontHeight(uint32_t fontNum)
{
    mtrTtf_t *font;
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    if (font->font != NULL)
        return TTF_FontHeight(font->font);
    else
        return 0;
}

/*fa mtrTtfGetStringSizes yes */
MTR_EXPORT bool MTR_CALL mtrTtfGetStringSizes(uint32_t fontNum,
 const char *string, int *w, int *h)
{
    mtrTtf_t *font;
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

/*fa mtrTtfGetStringWidth yes */
MTR_EXPORT int MTR_CALL mtrTtfGetStringWidth(uint32_t fontNum,
 const char *string)
{
    mtrTtf_t *font;
    int       width;
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

/*fa mtrTtfSetFontStyle yes */
MTR_EXPORT void MTR_CALL mtrTtfSetFontStyle(uint32_t fontNum, int style)
{
    mtrTtf_t *font;
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    TTF_SetFontStyle(font->font, style);
}

/*fa mtrTtfSetFontOutline yes */
MTR_EXPORT void MTR_CALL mtrTtfSetFontOutline(uint32_t fontNum, int outline)
{
    mtrTtf_t *font;
    font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
    TTF_SetFontOutline(font->font, outline);
}

/*fa mtrTtfFree yes */
MTR_EXPORT void MTR_CALL mtrTtfFree(uint32_t fontNum)
{
    mtrTtf_t *font;
    if (fontNum != 0)
    {
        font = IK_GET_DATA(mtrTtf_t *, mtrTtfKeeper, fontNum);
        mtrLogWrite_s("Unloading TTF font", 0, MTR_LMT_INFO, font->name);
        if (font->name != mtrDefaultTTFName)
            free(font->name);
        TTF_CloseFont(font->font);
        mtrIndexkeeperFreeIndex(mtrTtfKeeper, fontNum);
        mtrLogWrite("TTF font unloaded", 0, MTR_LMT_INFO);
    }
}

MTR_EXPORT mtrPixels_t *MTR_CALL mtrTtfRenderString(uint32_t fontNum, uint8_t r,
 uint8_t g, uint8_t b, const char *string)
{
    mtrTtf_t        *font;
    SDL_Color        textcolor;
    SDL_Surface     *renderedSurface;
    int              success;

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
