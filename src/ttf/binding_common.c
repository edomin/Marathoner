#ifndef MTR_TTF_BINDING_COMMON_C
#define MTR_TTF_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_B_U32t2(mtrSF_TtfInit, mtrTtfInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_TtfQuit, mtrTtfQuit)
MTR_SCRIPT_FUNC_U32t_S1I1(mtrSF_TtfLoad, mtrTtfLoad)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_TtfFree, mtrTtfFree)
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_TtfGetFontHeight, mtrTtfGetFontHeight)

#ifndef _SQUIRREL_H_
MTR_SCRIPT_FUNC(mtrSF_TtfGetStringSizes)
{
    uint32_t    fontNum;
    const char *string;
    int         width;
    int         height;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_STRING(string, 2);
    mtrTtfGetStringSizes(fontNum, string, &width, &height);

    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);

    return 2;
}
#endif

MTR_SCRIPT_FUNC(mtrSF_TtfGetStringWidth)
{
    uint32_t    fontNum;
    const char *string;
    int         width;
    int         height;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_STRING(string, 2);
    mtrTtfGetStringSizes(fontNum, string, &width, &height);

    MTR_SF_PUSH_INT(width);

    return 1;
}

MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_TtfSetFontStyle, mtrTtfSetFontStyle)
MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_TtfSetFontOutline, mtrTtfSetFontOutline)

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrTtfInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfQuit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfLoad, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfFree, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTtfGetFontHeight, MTR_SOURCE_MODULE);
    #ifndef _SQUIRREL_H_
    MTR_FIND_FUNCTION(mtrTtfGetStringSizes, MTR_SOURCE_MODULE);
    #endif
    MTR_FIND_FUNCTION(mtrTtfGetStringWidth, MTR_SOURCE_MODULE);
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
        mtrScriptsRegisterFunction(mtrSF_TtfGetFontHeight, "TtfGetFontHeight");
        #ifndef _SQUIRREL_H_
        mtrScriptsRegisterFunction(mtrSF_TtfGetStringSizes,
         "TtfGetStringSizes");
        #endif
        mtrScriptsRegisterFunction(mtrSF_TtfGetStringWidth,
         "TtfGetStringWidth");
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
