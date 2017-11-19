#ifndef MTR_TTF_BINDING_COMMON_C
#define MTR_TTF_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_TtfFunctionSupported, MTR_TtfFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_TtfInit, MTR_TtfInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_TtfQuit, MTR_TtfQuit)
MTR_SCRIPT_FUNC_U32t_S1I1(MTR_SF_TtfLoad, MTR_TtfLoad)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_TtfFree, MTR_TtfFree)
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_TtfGetFontHeight, MTR_TtfGetFontHeight)
MTR_SCRIPT_FUNC_P_U32t1U8t3S1(MTR_SF_TtfRenderString, MTR_TtfRenderString)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_TtfGetStringSizes)
{
    uint32_t    fontNum;
    const char *string;
    int         width;
    int         height;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_STRING(string, 2);
    MTR_TtfGetStringSizes(fontNum, string, &width, &height);

    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_U32t1S1(MTR_SF_TtfGetStringWidth, MTR_TtfGetStringWidth)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_TtfSetFontStyle, MTR_TtfSetFontStyle)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_TtfSetFontOutline, MTR_TtfSetFontOutline)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

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
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfRenderString);

    MTR_ScriptsRegisterVariable_i("FS_NORMAL", MTR_FS_NORMAL);
    MTR_ScriptsRegisterVariable_i("FS_BOLD", MTR_FS_BOLD);
    MTR_ScriptsRegisterVariable_i("FS_ITALIC", MTR_FS_ITALIC);
    MTR_ScriptsRegisterVariable_i("FS_UNDERLINE", MTR_FS_UNDERLINE);
    MTR_ScriptsRegisterVariable_i("FS_STRIKETHROUGH", MTR_FS_STRIKETHROUGH);
}

#endif
