#ifndef MTR_ABSTRACTION_GUI_BINDING_COMMON_C
#define MTR_ABSTRACTION_GUI_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_GuiFunctionSupported, mtrGuiFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t5(mtrSF_GuiInit, mtrGuiInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiQuit, mtrGuiQuit)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiProcessEvents, mtrGuiProcessEvents)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiRender, mtrGuiRender)
MTR_SCRIPT_FUNC_U32t_U32t1(mtrSF_GuiAddFont, mtrGuiAddFont)
MTR_SCRIPT_FUNC_U32t_U32t1I4(mtrSF_GuiAddImage, mtrGuiAddImage)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_GuiDeleteFont, mtrGuiDeleteFont)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_GuiDeleteImage, mtrGuiDeleteImage)
MTR_SCRIPT_FUNC_B_S1F4I1(mtrSF_GuiBegin, mtrGuiBegin)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiEnd, mtrGuiEnd)
MTR_SCRIPT_FUNC_B_S1I1(mtrSF_GuiButtonText, mtrGuiButtonText)
MTR_SCRIPT_FUNC_B_S1(mtrSF_GuiButtonLabel, mtrGuiButtonLabel)
MTR_SCRIPT_FUNC_B_U32t1(mtrSF_GuiButtonColor_c, mtrGuiButtonColor_c)
MTR_SCRIPT_FUNC_B_U32t1(mtrSF_GuiButtonColor_ca, mtrGuiButtonColor_ca)
MTR_SCRIPT_FUNC_B_U8t3(mtrSF_GuiButtonColor_rgb, mtrGuiButtonColor_rgb)
MTR_SCRIPT_FUNC_B_U8t4(mtrSF_GuiButtonColor_rgba, mtrGuiButtonColor_rgba)
MTR_SCRIPT_FUNC_B_I1(mtrSF_GuiButtonSymbol, mtrGuiButtonSymbol)
MTR_SCRIPT_FUNC_B_I1S1I1(mtrSF_GuiButtonSymbolLabel, mtrGuiButtonSymbolLabel)
MTR_SCRIPT_FUNC_B_I1S1I2(mtrSF_GuiButtonSymbolText, mtrGuiButtonSymbolText)
MTR_SCRIPT_FUNC_B_U32t1(mtrSF_GuiButtonImage, mtrGuiButtonImage)
MTR_SCRIPT_FUNC_B_U32t1S1I1(mtrSF_GuiButtonImageLabel, mtrGuiButtonImageLabel)
MTR_SCRIPT_FUNC_B_U32t1S1I2(mtrSF_GuiButtonImageText, mtrGuiButtonImageText)
MTR_SCRIPT_FUNC_B_S1B1(mtrSF_GuiCheckLabel, mtrGuiCheckLabel)
MTR_SCRIPT_FUNC_B_S1I1B1(mtrSF_GuiCheckText, mtrGuiCheckText)
MTR_SCRIPT_FUNC_B_S1I1B1(mtrSF_GuiSelectableLabel, mtrGuiSelectableLabel)
MTR_SCRIPT_FUNC_B_S1I1B2(mtrSF_GuiSelectableText, mtrGuiSelectableText)
MTR_SCRIPT_FUNC_B_U32t1S1B2(mtrSF_GuiSelectableImageLabel,
 mtrGuiSelectableImageLabel)
MTR_SCRIPT_FUNC_B_U32t1S1I2B1(mtrSF_GuiSelectableImageText,
 mtrGuiSelectableImageText)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_GuiEditText, mtrGuiEditText)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_GuiEditInteger, mtrGuiEditInteger)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_GuiEditFloat, mtrGuiEditFloat)
MTR_SCRIPT_FUNC_V_S1I1(mtrSF_GuiLabel, mtrGuiLabel)
MTR_SCRIPT_FUNC_V_S1I1U32t1(mtrSF_GuiLabelColored_c, mtrGuiLabelColored_c)
MTR_SCRIPT_FUNC_V_S1I1U32t1(mtrSF_GuiLabelColored_ca, mtrGuiLabelColored_ca)
MTR_SCRIPT_FUNC_V_S1I1U8t3(mtrSF_GuiLabelColored_rgb, mtrGuiLabelColored_rgb)
MTR_SCRIPT_FUNC_V_S1I1U8t4(mtrSF_GuiLabelColored_rgba, mtrGuiLabelColored_rgba)
MTR_SCRIPT_FUNC_V_S1(mtrSF_GuiLabelWrap, mtrGuiLabelWrap)
MTR_SCRIPT_FUNC_V_S1U32t1(mtrSF_GuiLabelColoredWrap_c, mtrGuiLabelColoredWrap_c)
MTR_SCRIPT_FUNC_V_S1U32t1(mtrSF_GuiLabelColoredWrap_ca,
 mtrGuiLabelColoredWrap_ca)
MTR_SCRIPT_FUNC_V_S1U8t3(mtrSF_GuiLabelColoredWrap_rgb,
 mtrGuiLabelColoredWrap_rgb)
MTR_SCRIPT_FUNC_V_S1U8t4(mtrSF_GuiLabelColoredWrap_rgba,
 mtrGuiLabelColoredWrap_rgba)
MTR_SCRIPT_FUNC_B_S1B1(mtrSF_GuiTreeTabBegin, mtrGuiTreeTabBegin)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiTreeTabEnd, mtrGuiTreeTabEnd)
MTR_SCRIPT_FUNC_V_F1I1(mtrSF_GuiLayoutRowDynamic, mtrGuiLayoutRowDynamic)
MTR_SCRIPT_FUNC_V_F1I2(mtrSF_GuiLayoutRowStatic, mtrGuiLayoutRowStatic)
MTR_SCRIPT_FUNC_B_S1I1(mtrSF_GuiGroupBegin, mtrGuiGroupBegin)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiGroupEnd, mtrGuiGroupEnd)
MTR_SCRIPT_FUNC_V_I1(mtrSF_GuiSpacing, mtrGuiSpacing)

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

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

    mtrScriptsRegisterNumericVariable("GUI_WINDOW_BORDER",
     MTR_GUI_WINDOW_BORDER);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_MOVABLE",
     MTR_GUI_WINDOW_MOVABLE);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_SCALABLE",
     MTR_GUI_WINDOW_SCALABLE);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_CLOSABLE",
     MTR_GUI_WINDOW_CLOSABLE);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_MINIMIZABLE",
     MTR_GUI_WINDOW_MINIMIZABLE);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_NO_SCROLLBAR",
     MTR_GUI_WINDOW_NO_SCROLLBAR);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_TITLE", MTR_GUI_WINDOW_TITLE);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_SCROLL_AUTO_HIDE",
     MTR_GUI_WINDOW_SCROLL_AUTO_HIDE);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_BACKGROUND",
     MTR_GUI_WINDOW_BACKGROUND);
    mtrScriptsRegisterNumericVariable("GUI_WINDOW_SCALE_LEFT",
     MTR_GUI_WINDOW_SCALE_LEFT);

    mtrScriptsRegisterNumericVariable("GUI_TEXT_ALIGN_LEFT",
     MTR_GUI_TEXT_ALIGN_LEFT);
    mtrScriptsRegisterNumericVariable("GUI_TEXT_ALIGN_CENTERED",
     MTR_GUI_TEXT_ALIGN_CENTERED);
    mtrScriptsRegisterNumericVariable("GUI_TEXT_ALIGN_RIGHT",
     MTR_GUI_TEXT_ALIGN_RIGHT);
    mtrScriptsRegisterNumericVariable("GUI_TEXT_ALIGN_TOP",
     MTR_GUI_TEXT_ALIGN_TOP);
    mtrScriptsRegisterNumericVariable("GUI_TEXT_ALIGN_MIDDLE",
     MTR_GUI_TEXT_ALIGN_MIDDLE);
    mtrScriptsRegisterNumericVariable("GUI_TEXT_ALIGN_BOTTOM",
     MTR_GUI_TEXT_ALIGN_BOTTOM);

    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_NONE", MTR_GUI_SYMBOL_NONE);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_X", MTR_GUI_SYMBOL_X);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_UNDERSCORE",
     MTR_GUI_SYMBOL_UNDERSCORE);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_CIRCLE_SOLID",
     MTR_GUI_SYMBOL_CIRCLE_SOLID);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_CIRCLE_OUTLINE",
     MTR_GUI_SYMBOL_CIRCLE_OUTLINE);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_RECT_SOLID",
     MTR_GUI_SYMBOL_RECT_SOLID);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_RECT_OUTLINE",
     MTR_GUI_SYMBOL_RECT_OUTLINE);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_TRIANGLE_UP",
     MTR_GUI_SYMBOL_TRIANGLE_UP);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_TRIANGLE_DOWN",
     MTR_GUI_SYMBOL_TRIANGLE_DOWN);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_TRIANGLE_LEFT",
     MTR_GUI_SYMBOL_TRIANGLE_LEFT);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_TRIANGLE_RIGHT",
     MTR_GUI_SYMBOL_TRIANGLE_RIGHT);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_PLUS", MTR_GUI_SYMBOL_PLUS);
    mtrScriptsRegisterNumericVariable("GUI_SYMBOL_MINUS", MTR_GUI_SYMBOL_MINUS);
}

#endif

