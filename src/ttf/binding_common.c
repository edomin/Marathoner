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

    MTR_FIND_FUNCTION(mtrTtfInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfQuit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfLoad, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfFree, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfSetFontStyle, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfSetFontOutline, MTR_SOURCE_MODULE);

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
