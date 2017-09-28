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
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrFontFunctionSupported, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontInit, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontLoadTtf, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontFree, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontSetTtfStyle, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontSetTtfOutline, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontRenderTtfString, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontCreateMbf, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontAddMbfTextureTable, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontDrawMbfString_f, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontGetHeight, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontGetStringWidth, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontGetName, "Abstraction_font");

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_FontFunctionSupported,
         "FontFunctionSupported");
        mtrScriptsRegisterFunction(mtrSF_FontInit, "FontInit");
        mtrScriptsRegisterFunction(mtrSF_FontLoadTtf, "FontLoadTtf");
        mtrScriptsRegisterFunction(mtrSF_FontFree, "FontFree");
        mtrScriptsRegisterFunction(mtrSF_FontSetTtfStyle, "FontSetTtfStyle");
        mtrScriptsRegisterFunction(mtrSF_FontSetTtfOutline,
         "FontSetTtfOutline");
        mtrScriptsRegisterFunction(mtrSF_FontRenderTtfString,
         "FontRenderTtfString");
        mtrScriptsRegisterFunction(mtrSF_FontCreateMbf, "FontCreateMbf");
        mtrScriptsRegisterFunction(mtrSF_FontAddMbfTextureTable,
         "FontAddMbfTextureTable");
        mtrScriptsRegisterFunction(mtrSF_FontDrawMbfString_f,
         "FontDrawMbfString_f");
        mtrScriptsRegisterFunction(mtrSF_FontGetHeight, "FontGetHeight");
        mtrScriptsRegisterFunction(mtrSF_FontGetStringWidth,
         "FontGetStringWidth");
        mtrScriptsRegisterFunction(mtrSF_FontGetName, "FontGetName");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
