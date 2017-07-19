#ifndef MTR_ABSTRACTION_GUI_BINDING_COMMON_C
#define MTR_ABSTRACTION_GUI_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_B_U32t7(mtrSF_GuiInit, mtrGuiInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiQuit, mtrGuiQuit)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiProcessEvents, mtrGuiProcessEvents)
MTR_SCRIPT_FUNC_V_V(mtrSF_GuiRender, mtrGuiRender)
MTR_SCRIPT_FUNC_U32t_U32t1(mtrSF_GuiAddFont, mtrGuiAddFont)
MTR_SCRIPT_FUNC_U32t_U32t1I4(mtrSF_GuiAddImage, mtrGuiAddImage)
MTR_SCRIPT_FUNC_U32t_S1I1(mtrSF_GuiAddStringBuffer, mtrGuiAddStringBuffer)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_GuiDeleteFont, mtrGuiDeleteFont)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_GuiDeleteImage, mtrGuiDeleteImage)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_GuiDeleteStringBuffer, mtrGuiDeleteStringBuffer)
MTR_SCRIPT_FUNC_V_U32t1S1(mtrSF_GuiSetStringBuffer, mtrGuiSetStringBuffer)
MTR_SCRIPT_FUNC_S_U32t1(mtrSF_GuiGetStringBuffer, mtrGuiGetStringBuffer)
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
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrGuiInit, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiQuit, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiProcessEvents, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiRender, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiAddFont, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiAddImage, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiAddStringBuffer, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiDeleteFont, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiDeleteImage, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiDeleteStringBuffer, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiSetStringBuffer, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiGetStringBuffer, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiBegin, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiEnd, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonText, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonColor_c, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonColor_ca, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonColor_rgb, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonColor_rgba, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonSymbol, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonSymbolLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonSymbolText, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonImage, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonImageLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonImageText, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiCheckLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiCheckText, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiSelectableLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiSelectableText, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiSelectableImageLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiSelectableImageText, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiEditText, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiEditInteger, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiEditFloat, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelColored_c, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelColored_ca, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelColored_rgb, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelColored_rgba, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelWrap, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelColoredWrap_c, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelColoredWrap_ca, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelColoredWrap_rgb, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLabelColoredWrap_rgba, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiTreeTabBegin, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiTreeTabEnd, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLayoutRowDynamic, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLayoutRowStatic, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiGroupBegin, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiGroupEnd, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiSpacing, "Abstraction_gui");

    if (ok)
    {
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
        mtrScriptsRegisterNumericVariable("GUI_WINDOW_TITLE",
         MTR_GUI_WINDOW_TITLE);
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

        mtrScriptsRegisterNumericVariable("GUI_SYMBOL_NONE",
         MTR_GUI_SYMBOL_NONE);
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
        mtrScriptsRegisterNumericVariable("GUI_SYMBOL_PLUS",
         MTR_GUI_SYMBOL_PLUS);
        mtrScriptsRegisterNumericVariable("GUI_SYMBOL_MINUS",
         MTR_GUI_SYMBOL_MINUS);

        mtrScriptsRegisterFunction(mtrSF_GuiInit, "GuiInit");
        mtrScriptsRegisterFunction(mtrSF_GuiQuit, "GuiQuit");
        mtrScriptsRegisterFunction(mtrSF_GuiProcessEvents, "GuiProcessEvents");
        mtrScriptsRegisterFunction(mtrSF_GuiRender, "GuiRender");
        mtrScriptsRegisterFunction(mtrSF_GuiAddFont, "GuiAddFont");
        mtrScriptsRegisterFunction(mtrSF_GuiAddImage, "GuiAddImage");
        mtrScriptsRegisterFunction(mtrSF_GuiAddStringBuffer,
         "GuiAddStringBuffer");
        mtrScriptsRegisterFunction(mtrSF_GuiDeleteFont, "GuiDeleteFont");
        mtrScriptsRegisterFunction(mtrSF_GuiDeleteImage, "GuiDeleteImage");
        mtrScriptsRegisterFunction(mtrSF_GuiDeleteStringBuffer,
         "GuiDeleteStringBuffer");
        mtrScriptsRegisterFunction(mtrSF_GuiSetStringBuffer,
         "GuiSetStringBuffer");
        mtrScriptsRegisterFunction(mtrSF_GuiGetStringBuffer,
         "GuiGetStringBuffer");
        mtrScriptsRegisterFunction(mtrSF_GuiBegin, "GuiBegin");
        mtrScriptsRegisterFunction(mtrSF_GuiEnd, "GuiEnd");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonText, "GuiButtonText");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonLabel, "GuiButtonLabel");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonColor_c, "GuiButtonColor_c");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonColor_ca,
         "GuiButtonColor_ca");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonColor_rgb,
         "GuiButtonColor_rgb");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonColor_rgba,
         "GuiButtonColor_rgba");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonSymbol, "GuiButtonSymbol");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonSymbolLabel,
         "GuiButtonSymbolLabel");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonSymbolText,
         "GuiButtonSymbolText");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonImage, "GuiButtonImage");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonImageLabel,
         "GuiButtonImageLabel");
        mtrScriptsRegisterFunction(mtrSF_GuiButtonImageText,
         "GuiButtonImageText");
        mtrScriptsRegisterFunction(mtrSF_GuiCheckLabel, "GuiCheckLabel");
        mtrScriptsRegisterFunction(mtrSF_GuiCheckText, "GuiCheckText");
        mtrScriptsRegisterFunction(mtrSF_GuiSelectableLabel,
         "GuiSelectableLabel");
        mtrScriptsRegisterFunction(mtrSF_GuiSelectableText,
         "GuiSelectableText");
        mtrScriptsRegisterFunction(mtrSF_GuiSelectableImageLabel,
         "GuiSelectableImageLabel");
        mtrScriptsRegisterFunction(mtrSF_GuiSelectableImageText,
         "GuiSelectableImageText");
        mtrScriptsRegisterFunction(mtrSF_GuiEditText, "GuiEditText");
        mtrScriptsRegisterFunction(mtrSF_GuiEditInteger, "GuiEditInteger");
        mtrScriptsRegisterFunction(mtrSF_GuiEditFloat, "GuiEditFloat");
        mtrScriptsRegisterFunction(mtrSF_GuiLabel, "GuiLabel");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelColored_c,
         "GuiLabelColored_c");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelColored_ca,
         "GuiLabelColored_ca");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelColored_rgb,
         "GuiLabelColored_rgb");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelColored_rgba,
         "GuiLabelColored_rgba");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelWrap, "GuiLabelWrap");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelColoredWrap_c,
         "GuiLabelColoredWrap_c");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelColoredWrap_ca,
         "GuiLabelColoredWrap_ca");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelColoredWrap_rgb,
         "GuiLabelColoredWrap_rgb");
        mtrScriptsRegisterFunction(mtrSF_GuiLabelColoredWrap_rgba,
         "GuiLabelColoredWrap_rgba");
        mtrScriptsRegisterFunction(mtrSF_GuiTreeTabBegin, "GuiTreeTabBegin");
        mtrScriptsRegisterFunction(mtrSF_GuiTreeTabEnd, "GuiTreeTabEnd");
        mtrScriptsRegisterFunction(mtrSF_GuiLayoutRowDynamic,
         "GuiLayoutRowDynamic");
        mtrScriptsRegisterFunction(mtrSF_GuiLayoutRowStatic,
         "GuiLayoutRowStatic");
        mtrScriptsRegisterFunction(mtrSF_GuiGroupBegin, "GuiGroupBegin");
        mtrScriptsRegisterFunction(mtrSF_GuiGroupEnd, "GuiGroupEnd");
        mtrScriptsRegisterFunction(mtrSF_GuiSpacing, "GuiSpacing");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif

