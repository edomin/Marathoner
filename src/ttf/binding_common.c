#ifndef MTR_TTF_BINDING_COMMON_C
#define MTR_TTF_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_TtfInit)
{
    uint32_t dmSize;
    uint32_t reservedCount;
    bool     success;

    MTR_SF_GET_UINT32(dmSize, 1);
    MTR_SF_GET_UINT32(reservedCount, 2);
    success = mtrTtfInit(dmSize, reservedCount);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TtfQuit)
{
    mtrTtfQuit();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TtfLoad)
{
    const char *filename;
    int         size;
    uint32_t    fontNum;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_INT(size, 2);
    fontNum = mtrTtfLoad(filename, size);

    MTR_SF_PUSH_UINT32(fontNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TtfFree)
{
    uint32_t fontNum;

    MTR_SF_GET_UINT32(fontNum, 1);
    mtrTtfFree(fontNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TtfSetFontStyle)
{
    uint32_t fontNum;
    int      style;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_INT(style, 2);
    mtrTtfSetFontStyle(fontNum, style);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TtfSetFontOutline)
{
    uint32_t fontNum;
    int      outline;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_INT(outline, 2);
    mtrTtfSetFontOutline(fontNum, outline);

    return 0;
}

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();
    mtrTtfInit = (mtrTtfInitFunc)mtrFindFunction("TTF_SDL2_ttf",
      "mtrTtfInit");
    if (mtrTtfInit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTtfInit");
        ok = false;
    }
    mtrTtfQuit = (mtrTtfQuitFunc)mtrFindFunction("TTF_SDL2_ttf",
      "mtrTtfQuit");
    if (mtrTtfQuit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTtfQuit");
        ok = false;
    }
    mtrTtfLoad = (mtrTtfLoadFunc)mtrFindFunction("TTF_SDL2_ttf",
      "mtrTtfLoad");
    if (mtrTtfLoad == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTtfLoad");
        ok = false;
    }
    mtrTtfFree = (mtrTtfFreeFunc)mtrFindFunction("TTF_SDL2_ttf",
      "mtrTtfFree");
    if (mtrTtfFree == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTtfFree");
        ok = false;
    }
    mtrTtfSetFontStyle = (mtrTtfSetFontStyleFunc)mtrFindFunction("TTF_SDL2_ttf",
      "mtrTtfSetFontStyle");
    if (mtrTtfSetFontStyle == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTtfSetFontStyle");
        ok = false;
    }
    mtrTtfSetFontOutline = (mtrTtfSetFontOutlineFunc)mtrFindFunction("TTF_SDL2_ttf",
      "mtrTtfSetFontOutline");
    if (mtrTtfSetFontOutline == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTtfSetFontOutline");
        ok = false;
    }
    if (ok)
    {
        mtrScriptsRegisterNumericVariable("FS_NORMAL", MTR_FS_NORMAL);
        mtrScriptsRegisterNumericVariable("FS_BOLD", MTR_FS_BOLD);
        mtrScriptsRegisterNumericVariable("FS_ITALIC", MTR_FS_ITALIC);
        mtrScriptsRegisterNumericVariable("FS_UNDERLINE", MTR_FS_UNDERLINE);
        mtrScriptsRegisterNumericVariable("FS_STRIKETHROUGH",
         MTR_FS_STRIKETHROUGH);

        mtrScriptsRegisterFunction(mtrSF_TtfInit, "TtfInit");
        mtrScriptsRegisterFunction(mtrSF_TtfQuit, "TtfQuit");
        mtrScriptsRegisterFunction(mtrSF_TtfLoad, "TtfLoad");
        mtrScriptsRegisterFunction(mtrSF_TtfFree, "TtfFree");
        mtrScriptsRegisterFunction(mtrSF_TtfSetFontStyle,
         "TtfSetFontStyle");
        mtrScriptsRegisterFunction(mtrSF_TtfSetFontOutline,
         "TtfSetFontOutline");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
