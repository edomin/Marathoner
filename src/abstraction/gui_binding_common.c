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
    MTR_FIND_FUNCTION(mtrGuiBegin, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiEnd, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonText, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonColor_c, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonColor_ca, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonColor_rgb, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiButtonColor_rgba, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiCheckLabel, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiCheckText, "Abstraction_gui");
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
    MTR_FIND_FUNCTION(mtrGuiLayoutRowDynamic, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiLayoutRowStatic, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiGroupBegin, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiGroupEnd, "Abstraction_gui");
    MTR_FIND_FUNCTION(mtrGuiSpacing, "Abstraction_gui");

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_GuiInit, "GuiInit");
        mtrScriptsRegisterFunction(mtrSF_GuiQuit, "GuiQuit");
        mtrScriptsRegisterFunction(mtrSF_GuiProcessEvents, "GuiProcessEvents");
        mtrScriptsRegisterFunction(mtrSF_GuiRender, "GuiRender");
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
        mtrScriptsRegisterFunction(mtrSF_GuiCheckLabel, "GuiCheckLabel");
        mtrScriptsRegisterFunction(mtrSF_GuiCheckText, "GuiCheckText");
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

