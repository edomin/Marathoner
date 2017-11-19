#ifndef MTR_ABSTRACTION_GUI_BINDING_COMMON_C
#define MTR_ABSTRACTION_GUI_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_GuiFunctionSupported, MTR_GuiFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t5(MTR_SF_GuiInit, MTR_GuiInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_GuiQuit, MTR_GuiQuit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_GuiProcessEvents, MTR_GuiProcessEvents)
MTR_SCRIPT_FUNC_V_V(MTR_SF_GuiRender, MTR_GuiRender)
MTR_SCRIPT_FUNC_U32t_U32t1(MTR_SF_GuiAddFont, MTR_GuiAddFont)
MTR_SCRIPT_FUNC_U32t_U32t1I4(MTR_SF_GuiAddImage, MTR_GuiAddImage)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_GuiDeleteFont, MTR_GuiDeleteFont)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_GuiDeleteImage, MTR_GuiDeleteImage)
MTR_SCRIPT_FUNC_B_S1F4I1(MTR_SF_GuiBegin, MTR_GuiBegin)
MTR_SCRIPT_FUNC_V_V(MTR_SF_GuiEnd, MTR_GuiEnd)
MTR_SCRIPT_FUNC_B_S1I1(MTR_SF_GuiButtonText, MTR_GuiButtonText)
MTR_SCRIPT_FUNC_B_S1(MTR_SF_GuiButtonLabel, MTR_GuiButtonLabel)
MTR_SCRIPT_FUNC_B_U32t1(MTR_SF_GuiButtonColor_c, MTR_GuiButtonColor_c)
MTR_SCRIPT_FUNC_B_U32t1(MTR_SF_GuiButtonColor_ca, MTR_GuiButtonColor_ca)
MTR_SCRIPT_FUNC_B_U8t3(MTR_SF_GuiButtonColor_rgb, MTR_GuiButtonColor_rgb)
MTR_SCRIPT_FUNC_B_U8t4(MTR_SF_GuiButtonColor_rgba, MTR_GuiButtonColor_rgba)
MTR_SCRIPT_FUNC_B_I1(MTR_SF_GuiButtonSymbol, MTR_GuiButtonSymbol)
MTR_SCRIPT_FUNC_B_I1S1I1(MTR_SF_GuiButtonSymbolLabel, MTR_GuiButtonSymbolLabel)
MTR_SCRIPT_FUNC_B_I1S1I2(MTR_SF_GuiButtonSymbolText, MTR_GuiButtonSymbolText)
MTR_SCRIPT_FUNC_B_U32t1(MTR_SF_GuiButtonImage, MTR_GuiButtonImage)
MTR_SCRIPT_FUNC_B_U32t1S1I1(MTR_SF_GuiButtonImageLabel, MTR_GuiButtonImageLabel)
MTR_SCRIPT_FUNC_B_U32t1S1I2(MTR_SF_GuiButtonImageText, MTR_GuiButtonImageText)
MTR_SCRIPT_FUNC_B_S1B1(MTR_SF_GuiCheckLabel, MTR_GuiCheckLabel)
MTR_SCRIPT_FUNC_B_S1I1B1(MTR_SF_GuiCheckText, MTR_GuiCheckText)
MTR_SCRIPT_FUNC_B_S1I1B1(MTR_SF_GuiSelectableLabel, MTR_GuiSelectableLabel)
MTR_SCRIPT_FUNC_B_S1I1B2(MTR_SF_GuiSelectableText, MTR_GuiSelectableText)
MTR_SCRIPT_FUNC_B_U32t1S1B2(MTR_SF_GuiSelectableImageLabel,
 MTR_GuiSelectableImageLabel)
MTR_SCRIPT_FUNC_B_U32t1S1I2B1(MTR_SF_GuiSelectableImageText,
 MTR_GuiSelectableImageText)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_GuiEditText, MTR_GuiEditText)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_GuiEditInteger, MTR_GuiEditInteger)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_GuiEditFloat, MTR_GuiEditFloat)
MTR_SCRIPT_FUNC_V_S1I1(MTR_SF_GuiLabel, MTR_GuiLabel)
MTR_SCRIPT_FUNC_V_S1I1U32t1(MTR_SF_GuiLabelColored_c, MTR_GuiLabelColored_c)
MTR_SCRIPT_FUNC_V_S1I1U32t1(MTR_SF_GuiLabelColored_ca, MTR_GuiLabelColored_ca)
MTR_SCRIPT_FUNC_V_S1I1U8t3(MTR_SF_GuiLabelColored_rgb, MTR_GuiLabelColored_rgb)
MTR_SCRIPT_FUNC_V_S1I1U8t4(MTR_SF_GuiLabelColored_rgba,
 MTR_GuiLabelColored_rgba)
MTR_SCRIPT_FUNC_V_S1(MTR_SF_GuiLabelWrap, MTR_GuiLabelWrap)
MTR_SCRIPT_FUNC_V_S1U32t1(MTR_SF_GuiLabelColoredWrap_c,
 MTR_GuiLabelColoredWrap_c)
MTR_SCRIPT_FUNC_V_S1U32t1(MTR_SF_GuiLabelColoredWrap_ca,
 MTR_GuiLabelColoredWrap_ca)
MTR_SCRIPT_FUNC_V_S1U8t3(MTR_SF_GuiLabelColoredWrap_rgb,
 MTR_GuiLabelColoredWrap_rgb)
MTR_SCRIPT_FUNC_V_S1U8t4(MTR_SF_GuiLabelColoredWrap_rgba,
 MTR_GuiLabelColoredWrap_rgba)
MTR_SCRIPT_FUNC_B_S1B1(MTR_SF_GuiTreeTabBegin, MTR_GuiTreeTabBegin)
MTR_SCRIPT_FUNC_V_V(MTR_SF_GuiTreeTabEnd, MTR_GuiTreeTabEnd)
MTR_SCRIPT_FUNC_V_F1I1(MTR_SF_GuiLayoutRowDynamic, MTR_GuiLayoutRowDynamic)
MTR_SCRIPT_FUNC_V_F1I2(MTR_SF_GuiLayoutRowStatic, MTR_GuiLayoutRowStatic)
MTR_SCRIPT_FUNC_B_S1I1(MTR_SF_GuiGroupBegin, MTR_GuiGroupBegin)
MTR_SCRIPT_FUNC_V_V(MTR_SF_GuiGroupEnd, MTR_GuiGroupEnd)
MTR_SCRIPT_FUNC_V_I1(MTR_SF_GuiSpacing, MTR_GuiSpacing)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiInit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiQuit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiProcessEvents);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiRender);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiAddFont);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiAddImage);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiDeleteFont);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiDeleteImage);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiBegin);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiEnd);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonText);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonLabel);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonColor_c);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonColor_ca);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonColor_rgb);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonColor_rgba);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonSymbol);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonSymbolLabel);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonSymbolText);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonImage);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonImageLabel);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiButtonImageText);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiCheckLabel);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiCheckText);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiSelectableLabel);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiSelectableText);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiSelectableImageLabel);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiSelectableImageText);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiEditText);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiEditInteger);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiEditFloat);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabel);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelColored_c);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelColored_ca);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelColored_rgb);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelColored_rgba);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelWrap);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelColoredWrap_c);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelColoredWrap_ca);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelColoredWrap_rgb);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLabelColoredWrap_rgba);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiTreeTabBegin);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiTreeTabEnd);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLayoutRowDynamic);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiLayoutRowStatic);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiGroupBegin);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiGroupEnd);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_gui", GuiSpacing);

    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_BORDER", MTR_GUI_WINDOW_BORDER);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_MOVABLE", MTR_GUI_WINDOW_MOVABLE);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_SCALABLE",
     MTR_GUI_WINDOW_SCALABLE);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_CLOSABLE",
     MTR_GUI_WINDOW_CLOSABLE);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_MINIMIZABLE",
     MTR_GUI_WINDOW_MINIMIZABLE);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_NO_SCROLLBAR",
     MTR_GUI_WINDOW_NO_SCROLLBAR);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_TITLE", MTR_GUI_WINDOW_TITLE);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_SCROLL_AUTO_HIDE",
     MTR_GUI_WINDOW_SCROLL_AUTO_HIDE);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_BACKGROUND",
     MTR_GUI_WINDOW_BACKGROUND);
    MTR_ScriptsRegisterVariable_i("GUI_WINDOW_SCALE_LEFT",
     MTR_GUI_WINDOW_SCALE_LEFT);

    MTR_ScriptsRegisterVariable_i("GUI_TEXT_ALIGN_LEFT",
     MTR_GUI_TEXT_ALIGN_LEFT);
    MTR_ScriptsRegisterVariable_i("GUI_TEXT_ALIGN_CENTERED",
     MTR_GUI_TEXT_ALIGN_CENTERED);
    MTR_ScriptsRegisterVariable_i("GUI_TEXT_ALIGN_RIGHT",
     MTR_GUI_TEXT_ALIGN_RIGHT);
    MTR_ScriptsRegisterVariable_i("GUI_TEXT_ALIGN_TOP", MTR_GUI_TEXT_ALIGN_TOP);
    MTR_ScriptsRegisterVariable_i("GUI_TEXT_ALIGN_MIDDLE",
     MTR_GUI_TEXT_ALIGN_MIDDLE);
    MTR_ScriptsRegisterVariable_i("GUI_TEXT_ALIGN_BOTTOM",
     MTR_GUI_TEXT_ALIGN_BOTTOM);

    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_NONE", MTR_GUI_SYMBOL_NONE);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_X", MTR_GUI_SYMBOL_X);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_UNDERSCORE",
     MTR_GUI_SYMBOL_UNDERSCORE);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_CIRCLE_SOLID",
     MTR_GUI_SYMBOL_CIRCLE_SOLID);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_CIRCLE_OUTLINE",
     MTR_GUI_SYMBOL_CIRCLE_OUTLINE);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_RECT_SOLID",
     MTR_GUI_SYMBOL_RECT_SOLID);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_RECT_OUTLINE",
     MTR_GUI_SYMBOL_RECT_OUTLINE);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_TRIANGLE_UP",
     MTR_GUI_SYMBOL_TRIANGLE_UP);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_TRIANGLE_DOWN",
     MTR_GUI_SYMBOL_TRIANGLE_DOWN);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_TRIANGLE_LEFT",
     MTR_GUI_SYMBOL_TRIANGLE_LEFT);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_TRIANGLE_RIGHT",
     MTR_GUI_SYMBOL_TRIANGLE_RIGHT);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_PLUS", MTR_GUI_SYMBOL_PLUS);
    MTR_ScriptsRegisterVariable_i("GUI_SYMBOL_MINUS", MTR_GUI_SYMBOL_MINUS);
}

#endif

