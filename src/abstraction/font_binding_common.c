#ifndef MTR_ABSTRACTION_FONT_BINDING_COMMON_C
#define MTR_ABSTRACTION_FONT_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_FontFunctionSupported, MTR_FontFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_FontInit, MTR_FontInit)
MTR_SCRIPT_FUNC_U32t_S1I1(MTR_SF_FontCreate, MTR_FontCreate)
MTR_SCRIPT_FUNC_B_U32t2UI1(MTR_SF_FontAddAtlas, MTR_FontAddAtlas)
MTR_SCRIPT_FUNC_U32t_S1U32t1UI1(MTR_SF_FontCacheTtf, MTR_FontCacheTtf)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_FontFree, MTR_FontFree)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_FontSetStyle, MTR_FontSetStyle)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_FontSetOutline, MTR_FontSetOutline)
MTR_SCRIPT_FUNC_B_U32t1F2S1(MTR_SF_FontDrawString_f, MTR_FontDrawString_f)
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_FontGetHeight, MTR_FontGetHeight)
MTR_SCRIPT_FUNC_I_U32t1S1(MTR_SF_FontGetStringWidth, MTR_FontGetStringWidth)
MTR_SCRIPT_FUNC_S_U32t1(MTR_SF_FontGetName, MTR_FontGetName)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontInit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontCreate);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontAddAtlas);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontCacheTtf);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontFree);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontSetStyle);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontSetOutline);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontDrawString_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontGetHeight);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontGetStringWidth);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontGetName);
}

#endif
