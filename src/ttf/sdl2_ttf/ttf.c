#include "ttf.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "TTF_SDL2_ttf";
    report->version = MTR_VERSION_TTF_SDL2_TTF;
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT bool MTR_CALL mtrTtfInit(uint32_t dmSize, uint32_t reservedCount)
{
    SDL_version compiled;
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

MTR_EXPORT void MTR_CALL mtrTtfQuit(void)
{
    mtrLogWrite("Destroying TTF font manager", 0, MTR_LMT_INFO);
    TTF_Quit();
    mtrLogWrite("TTF font manager destroyed", 0, MTR_LMT_INFO);
}

MTR_EXPORT uint32_t MTR_CALL mtrTtfLoad(const char *filename, uint16_t size)
{
    uint32_t    freeIndex;
    mtrTtf_t   *font;

    mtrLogWrite_s("Loading TTF font", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrTtfKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    font = (mtrTtf_t *)(&((mtrTtf_t *)mtrTtfKeeper->data)[freeIndex]);
    font->font = TTF_OpenFont(filename, size);
    if (font->font != NULL)
    {
        font->name = malloc(sizeof(char) * (strlen(filename) + 1));
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

MTR_EXPORT void MTR_CALL mtrTtfSetFontStyle(uint32_t fontNum, uint8_t style)
{
    mtrTtf_t *font;
    font = (mtrTtf_t *)(&((mtrTtf_t *)mtrTtfKeeper->data)[fontNum]);
    TTF_SetFontStyle(font->font, style);
}

MTR_EXPORT void MTR_CALL mtrTtfSetFontOutline(uint32_t fontNum,
 uint16_t outline)
{
    mtrTtf_t *font;
    font = (mtrTtf_t *)(&((mtrTtf_t *)mtrTtfKeeper->data)[fontNum]);
    TTF_SetFontOutline(font->font, outline);
}

MTR_EXPORT void MTR_CALL mtrTtfFree(uint32_t fontNum)
{
    mtrTtf_t *font;
    if (fontNum != 0)
    {
        font = (mtrTtf_t *)(&((mtrTtf_t *)mtrTtfKeeper->data)[fontNum]);
        mtrLogWrite_s("Unloading TTF font", 0, MTR_LMT_INFO, font->name);
        free(font->name);
        TTF_CloseFont(font->font);
        mtrIndexkeeperFreeIndex(mtrTtfKeeper, fontNum);
        mtrLogWrite("TTF font unloaded", 0, MTR_LMT_INFO);
    }
}
