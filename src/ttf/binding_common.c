#ifndef MTR_TTF_BINDING_COMMON_C
#define MTR_TTF_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_TtfFunctionSupported, mtrTtfFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(mtrSF_TtfInit, mtrTtfInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_TtfQuit, mtrTtfQuit)
MTR_SCRIPT_FUNC_U32t_S1I1(mtrSF_TtfLoad, mtrTtfLoad)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_TtfFree, mtrTtfFree)
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_TtfGetFontHeight, mtrTtfGetFontHeight)

#ifdef lua_h
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
    mtrVm = mtrScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfQuit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfLoad);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfFree);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetFontHeight);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetStringSizes);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetStringWidth);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfSetFontStyle);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfSetFontOutline);

    mtrScriptsRegisterNumericVariable("FS_NORMAL", MTR_FS_NORMAL);
    mtrScriptsRegisterNumericVariable("FS_BOLD", MTR_FS_BOLD);
    mtrScriptsRegisterNumericVariable("FS_ITALIC", MTR_FS_ITALIC);
    mtrScriptsRegisterNumericVariable("FS_UNDERLINE", MTR_FS_UNDERLINE);
    mtrScriptsRegisterNumericVariable("FS_STRIKETHROUGH", MTR_FS_STRIKETHROUGH);
}

#endif
