#ifndef MTR_TTF_BINDING_COMMON_C
#define MTR_TTF_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_TtfFunctionSupported, MTR_TtfFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_TtfInit, MTR_TtfInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_TtfQuit, MTR_TtfQuit)
MTR_SCRIPT_FUNC_U32t_S1(MTR_SF_TtfLoad, MTR_TtfLoad)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_TtfFree, MTR_TtfFree)
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_TtfGetWidth, MTR_TtfGetWidth)
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_TtfGetHeight, MTR_TtfGetHeight)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_TtfGetSizes)
{
    uint32_t fontNum;
    int      width;
    int      height;
    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_TtfGetSizes(fontNum, &width, &height);
    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);
    return 2;
}
#endif

MTR_SCRIPT_FUNC_B_U32t1I2(MTR_SF_TtfSetSizes, MTR_TtfSetSizes)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_TtfGetGlyphSizes)
{
    uint32_t fontNum;
    uint32_t glyph;
    int      width;
    int      height;
    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_UINT32(glyph, 2);
    MTR_TtfGetGlyphSizes(fontNum, glyph, &width, &height);
    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);
    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_U32t2(MTR_SF_TtfGetGlyphWidth, MTR_TtfGetGlyphWidth)
MTR_SCRIPT_FUNC_I_U32t2(MTR_SF_TtfGetGlyphHeight, MTR_TtfGetGlyphHeight)
MTR_SCRIPT_FUNC_P_U32t1U8t3U32t1(MTR_SF_TtfRenderGlyph, MTR_TtfRenderGlyph)

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
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetWidth);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetHeight);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetSizes);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfSetSizes);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetGlyphSizes);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetGlyphWidth);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfGetGlyphHeight);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TtfRenderGlyph);

    MTR_ScriptsRegisterVariable_i("FS_NORMAL", MTR_FS_NORMAL);
    MTR_ScriptsRegisterVariable_i("FS_BOLD", MTR_FS_BOLD);
    MTR_ScriptsRegisterVariable_i("FS_ITALIC", MTR_FS_ITALIC);
    MTR_ScriptsRegisterVariable_i("FS_UNDERLINE", MTR_FS_UNDERLINE);
    MTR_ScriptsRegisterVariable_i("FS_STRIKETHROUGH", MTR_FS_STRIKETHROUGH);
}

#endif
