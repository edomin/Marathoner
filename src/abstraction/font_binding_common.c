#ifndef MTR_ABSTRACTION_FONT_BINDING_COMMON_C
#define MTR_ABSTRACTION_FONT_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_FontFunctionSupported, mtrFontFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(mtrSF_FontInit, mtrFontInit)
MTR_SCRIPT_FUNC_U32t_S1I1(mtrSF_FontLoadTtf, mtrFontLoadTtf)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_FontFree, mtrFontFree)
MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_FontSetTtfStyle, mtrFontSetTtfStyle)
MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_FontSetTtfOutline, mtrFontSetTtfOutline)
MTR_SCRIPT_FUNC_B_U32t2U8t3S1(mtrSF_FontRenderTtfString, mtrFontRenderTtfString)
MTR_SCRIPT_FUNC_U32t_S1I3(mtrSF_FontCreateMbf, mtrFontCreateMbf)
MTR_SCRIPT_FUNC_B_U32t2UI1(mtrSF_FontAddMbfTextureTable,
 mtrFontAddMbfTextureTable)
MTR_SCRIPT_FUNC_B_U32t1F2S1(mtrSF_FontDrawMbfString_f, mtrFontDrawMbfString_f)
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_FontGetHeight, mtrFontGetHeight)
MTR_SCRIPT_FUNC_I_U32t1S1(mtrSF_FontGetStringWidth, mtrFontGetStringWidth)
MTR_SCRIPT_FUNC_S_U32t1(mtrSF_FontGetName, mtrFontGetName)

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontInit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontLoadTtf);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontFree);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontSetTtfStyle);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontSetTtfOutline);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontRenderTtfString);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontCreateMbf);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontAddMbfTextureTable);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontDrawMbfString_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontGetHeight);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontGetStringWidth);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_font", FontGetName);
}

#endif
