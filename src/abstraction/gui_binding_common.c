#ifndef MTR_ABSTRACTION_GUI_BINDING_COMMON_C
#define MTR_ABSTRACTION_GUI_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_GuiInit)
{
    uint32_t fontDmSize;
    uint32_t fontReservedCount;
    uint32_t imageDmSize;
    uint32_t imageReservedCount;
    uint32_t sbDmSize;
    uint32_t sbReservedCount;
    uint32_t fontnum;
    bool     success;

    MTR_SF_GET_UINT32(fontDmSize, 1);
    MTR_SF_GET_UINT32(fontReservedCount, 2);
    MTR_SF_GET_UINT32(imageDmSize, 3);
    MTR_SF_GET_UINT32(imageReservedCount, 4);
    MTR_SF_GET_UINT32(sbDmSize, 5);
    MTR_SF_GET_UINT32(sbReservedCount, 6);
    MTR_SF_GET_UINT32(fontnum, 7);
    success = mtrGuiInit(fontDmSize, fontReservedCount, imageDmSize,
     imageReservedCount, sbDmSize, sbReservedCount, fontnum);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiQuit)
{
    mtrGuiQuit();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiProcessEvents)
{
    mtrGuiProcessEvents();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiRender)
{
    mtrGuiRender();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiAddFont)
{
    uint32_t font;
    uint32_t guiFont;

    MTR_SF_GET_UINT32(font, 1);
    guiFont = mtrGuiAddFont(font);

    MTR_SF_PUSH_UINT32(guiFont);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiAddImage)
{
    uint32_t texnum;
    int      x;
    int      y;
    int      w;
    int      h;
    uint32_t image;

    MTR_SF_GET_UINT32(texnum, 1);
    MTR_SF_GET_INT(x, 2);
    MTR_SF_GET_INT(y, 3);
    MTR_SF_GET_INT(w, 4);
    MTR_SF_GET_INT(h, 5);
    image = mtrGuiAddImage(texnum, x, y, w, h);

    MTR_SF_PUSH_UINT32(image);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiAddStringBuffer)
{
    const char *initialString;
    uint32_t    sb;
    int         maxlen;

    MTR_SF_GET_STRING(initialString, 1);
    MTR_SF_GET_INT(maxlen, 2);
    sb = mtrGuiAddStringBuffer(initialString, maxlen);

    MTR_SF_PUSH_UINT32(sb);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiDeleteFont)
{
    uint32_t font;

    MTR_SF_GET_UINT32(font, 1);
    mtrGuiDeleteFont(font);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiDeleteImage)
{
    uint32_t image;

    MTR_SF_GET_UINT32(image, 1);
    mtrGuiDeleteImage(image);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiDeleteStringBuffer)
{
    uint32_t sb;

    MTR_SF_GET_UINT32(sb, 1);
    mtrGuiDeleteStringBuffer(sb);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiSetStringBuffer)
{
    uint32_t    sb;
    const char *string;

    MTR_SF_GET_UINT32(sb, 1);
    MTR_SF_GET_STRING(string, 2);
    mtrGuiSetStringBuffer(sb, string);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiGetStringBuffer)
{
    uint32_t sb;
    char    *string;

    MTR_SF_GET_UINT32(sb, 1);
    string = mtrGuiGetStringBuffer(sb);

    if (string != NULL)
        MTR_SF_PUSH_STRING(string);
    else
        MTR_SF_PUSH_NIL();

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiBegin)
{
    const char *title;
    float       boundsX;
    float       boundsY;
    float       boundsW;
    float       bountsH;
    int         flags;
    bool        success;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_SINGLE(boundsX, 2);
    MTR_SF_GET_SINGLE(boundsY, 3);
    MTR_SF_GET_SINGLE(boundsW, 4);
    MTR_SF_GET_SINGLE(bountsH, 5);
    MTR_SF_GET_INT(flags, 6);
    success = mtrGuiBegin(title, boundsX, boundsY, boundsW, bountsH, flags);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiEnd)
{
    mtrGuiEnd();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonText)
{
    const char *title;
    int         len;
    bool        pressed;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_INT(len, 2);
    pressed = mtrGuiButtonText(title, len);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonLabel)
{
    const char *title;
    bool        pressed;

    MTR_SF_GET_STRING(title, 1);
    pressed = mtrGuiButtonLabel(title);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonColor_c)
{
    uint32_t color;
    bool     pressed;

    MTR_SF_GET_UINT32(color, 1);
    pressed = mtrGuiButtonColor_c(color);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonColor_ca)
{
    uint32_t color;
    bool     pressed;

    MTR_SF_GET_UINT32(color, 1);
    pressed = mtrGuiButtonColor_ca(color);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonColor_rgb)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    bool    pressed;

    MTR_SF_GET_UINT8(r, 1);
    MTR_SF_GET_UINT8(g, 2);
    MTR_SF_GET_UINT8(b, 3);
    pressed = mtrGuiButtonColor_rgb(r, g, b);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonColor_rgba)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    bool    pressed;

    MTR_SF_GET_UINT8(r, 1);
    MTR_SF_GET_UINT8(g, 2);
    MTR_SF_GET_UINT8(b, 3);
    MTR_SF_GET_UINT8(a, 3);
    pressed = mtrGuiButtonColor_rgba(r, g, b, a);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonSymbol)
{
    int  symbol;
    bool pressed;

    MTR_SF_GET_INT(symbol, 1);
    pressed = mtrGuiButtonSymbol(symbol);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonSymbolLabel)
{
    int         symbol;
    const char *string;
    int         alignment;
    bool        pressed;

    MTR_SF_GET_INT(symbol, 1);
    MTR_SF_GET_STRING(string, 2);
    MTR_SF_GET_INT(alignment, 3);
    pressed = mtrGuiButtonSymbolLabel(symbol, string, alignment);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonSymbolText)
{
    int         symbol;
    const char *string;
    int         len;
    int         alignment;
    bool        pressed;

    MTR_SF_GET_INT(symbol, 1);
    MTR_SF_GET_STRING(string, 2);
    MTR_SF_GET_INT(len, 3);
    MTR_SF_GET_INT(alignment, 4);
    pressed = mtrGuiButtonSymbolText(symbol, string, len, alignment);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonImage)
{
    uint32_t imagenum;
    bool     pressed;

    MTR_SF_GET_UINT32(imagenum, 1);
    pressed = mtrGuiButtonImage(imagenum);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonImageLabel)
{
    uint32_t    imagenum;
    const char *string;
    int         alignment;
    bool        pressed;

    MTR_SF_GET_UINT32(imagenum, 1);
    MTR_SF_GET_STRING(string, 2);
    MTR_SF_GET_INT(alignment, 3);
    pressed = mtrGuiButtonImageLabel(imagenum, string, alignment);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiButtonImageText)
{
    uint32_t    imagenum;
    const char *string;
    int         len;
    int         alignment;
    bool        pressed;

    MTR_SF_GET_UINT32(imagenum, 1);
    MTR_SF_GET_STRING(string, 2);
    MTR_SF_GET_INT(len, 3);
    MTR_SF_GET_INT(alignment, 4);
    pressed = mtrGuiButtonImageText(imagenum, string, len, alignment);

    MTR_SF_PUSH_BOOL(pressed);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiCheckLabel)
{
    const char *label;
    bool        active;
    bool        result;

    MTR_SF_GET_STRING(label, 1);
    MTR_SF_GET_BOOL(active, 2);
    result = mtrGuiCheckLabel(label, active);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiCheckText)
{
    const char *label;
    int         len;
    bool        active;
    bool        result;

    MTR_SF_GET_STRING(label, 1);
    MTR_SF_GET_INT(len, 2);
    MTR_SF_GET_BOOL(active, 3);
    result = mtrGuiCheckText(label, len, active);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiSelectableLabel)
{
    const char *text;
    int         alignment;
    bool        selected;
    bool        result;

    MTR_SF_GET_STRING(text, 1);
    MTR_SF_GET_INT(alignment, 2);
    MTR_SF_GET_BOOL(selected, 3);
    result = mtrGuiSelectableLabel(text, alignment, selected);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiSelectableText)
{
    const char *text;
    int         len;
    int         alignment;
    bool        selected;
    bool        result;

    MTR_SF_GET_STRING(text, 1);
    MTR_SF_GET_INT(len, 2);
    MTR_SF_GET_INT(alignment, 3);
    MTR_SF_GET_BOOL(selected, 4);
    result = mtrGuiSelectableText(text, len, alignment, selected);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiSelectableImageLabel)
{
    uint32_t    imagenum;
    const char *text;
    int         alignment;
    bool        selected;
    bool        result;

    MTR_SF_GET_UINT32(imagenum, 1);
    MTR_SF_GET_STRING(text, 2);
    MTR_SF_GET_INT(alignment, 3);
    MTR_SF_GET_BOOL(selected, 4);
    result = mtrGuiSelectableImageLabel(imagenum, text, alignment, selected);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiSelectableImageText)
{
    uint32_t imagenum;
    const char *text;
    int         len;
    int         alignment;
    bool        selected;
    bool        result;

    MTR_SF_GET_UINT32(imagenum, 1);
    MTR_SF_GET_STRING(text, 2);
    MTR_SF_GET_INT(len, 3);
    MTR_SF_GET_INT(alignment, 4);
    MTR_SF_GET_BOOL(selected, 5);
    result = mtrGuiSelectableImageText(imagenum, text, len, alignment, selected);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiEditText)
{
    uint32_t sbnum;

    MTR_SF_GET_UINT32(sbnum, 1);
    mtrGuiEditText(sbnum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiEditInteger)
{
    uint32_t sbnum;

    MTR_SF_GET_UINT32(sbnum, 1);
    mtrGuiEditInteger(sbnum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiEditFloat)
{
    uint32_t sbnum;

    MTR_SF_GET_UINT32(sbnum, 1);
    mtrGuiEditFloat(sbnum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabel)
{
    const char *string;
    int         alignment;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_INT(alignment, 2);
    mtrGuiLabel(string, alignment);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelColored_c)
{
    const char *string;
    int         alignment;
    uint32_t    color;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_INT(alignment, 2);
    MTR_SF_GET_UINT32(color, 3);
    mtrGuiLabelColored_c(string, alignment, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelColored_ca)
{
    const char *string;
    int         alignment;
    uint32_t    color;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_INT(alignment, 2);
    MTR_SF_GET_UINT32(color, 3);
    mtrGuiLabelColored_ca(string, alignment, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelColored_rgb)
{
    const char *string;
    int         alignment;
    uint8_t     r;
    uint8_t     g;
    uint8_t     b;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_INT(alignment, 2);
    MTR_SF_GET_UINT8(r, 3);
    MTR_SF_GET_UINT8(g, 4);
    MTR_SF_GET_UINT8(b, 5);
    mtrGuiLabelColored_rgb(string, alignment, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelColored_rgba)
{
    const char *string;
    int         alignment;
    uint8_t     r;
    uint8_t     g;
    uint8_t     b;
    uint8_t     a;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_INT(alignment, 2);
    MTR_SF_GET_UINT8(r, 3);
    MTR_SF_GET_UINT8(g, 4);
    MTR_SF_GET_UINT8(b, 5);
    MTR_SF_GET_UINT8(a, 5);
    mtrGuiLabelColored_rgba(string, alignment, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelWrap)
{
    const char *string;

    MTR_SF_GET_STRING(string, 1);
    mtrGuiLabelWrap(string);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelColoredWrap_c)
{
    const char *string;
    uint32_t    color;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_UINT32(color, 2);
    mtrGuiLabelColoredWrap_c(string, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelColoredWrap_ca)
{
    const char *string;
    uint32_t    color;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_UINT32(color, 2);
    mtrGuiLabelColoredWrap_ca(string, color);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelColoredWrap_rgb)
{
    const char *string;
    uint8_t     r;
    uint8_t     g;
    uint8_t     b;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_UINT8(r, 2);
    MTR_SF_GET_UINT8(g, 3);
    MTR_SF_GET_UINT8(b, 4);
    mtrGuiLabelColoredWrap_rgb(string, r, g, b);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLabelColoredWrap_rgba)
{
    const char *string;
    uint8_t     r;
    uint8_t     g;
    uint8_t     b;
    uint8_t     a;

    MTR_SF_GET_STRING(string, 1);
    MTR_SF_GET_UINT8(r, 2);
    MTR_SF_GET_UINT8(g, 3);
    MTR_SF_GET_UINT8(b, 4);
    MTR_SF_GET_UINT8(a, 5);
    mtrGuiLabelColoredWrap_rgba(string, r, g, b, a);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiTreeTabBegin)
{
    const char *title;
    bool        maximized;
    bool        result;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_BOOL(maximized, 2);
    result = mtrGuiTreeTabBegin(title, maximized);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiTreeTabEnd)
{
    mtrGuiTreeTabEnd();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLayoutRowDynamic)
{
    float height;
    int   cols;

    MTR_SF_GET_SINGLE(height, 1);
    MTR_SF_GET_INT(cols, 2);
    mtrGuiLayoutRowDynamic(height, cols);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiLayoutRowStatic)
{
    float height;
    int   cols;
    int   itemWidth;

    MTR_SF_GET_SINGLE(height, 1);
    MTR_SF_GET_INT(cols, 2);
    MTR_SF_GET_INT(itemWidth, 3);
    mtrGuiLayoutRowStatic(height, cols, itemWidth);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiGroupBegin)
{
    const char *title;
    int         flags;
    bool        result;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_INT(flags, 2);
    result = mtrGuiGroupBegin(title, flags);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_GuiGroupEnd)
{
    mtrGuiGroupEnd();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_GuiSpacing)
{
    int cols;

    MTR_SF_GET_INT(cols, 1);
    mtrGuiSpacing(cols);

    return 0;
}

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
        mtrScriptsRegisterFunction(mtrSF_GuiAddStringBuffer, "GuiAddImage");
        mtrScriptsRegisterFunction(mtrSF_GuiDeleteFont, "GuiAddFont");
        mtrScriptsRegisterFunction(mtrSF_GuiDeleteImage, "GuiAddImage");
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

