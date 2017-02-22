#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_FontInit)
{
    uint32_t dmSize;
    uint32_t reservedCount;
    bool     success;

    MTR_SF_GET_UINT32(dmSize, 1);
    MTR_SF_GET_UINT32(reservedCount, 2);
    success = mtrFontInit(dmSize, reservedCount);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FontLoadTtf)
{
    const char *filename;
    int         size;
    uint32_t    fontNum;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_INT(size, 2);
    fontNum = mtrFontLoadTtf(filename, size);

    MTR_SF_PUSH_UINT32(fontNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FontFree)
{
    uint32_t fontNum;

    MTR_SF_GET_UINT32(fontNum, 1);
    mtrFontFree(fontNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_FontSetTtfStyle)
{
    uint32_t fontNum;
    int      style;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_INT(style, 2);
    mtrFontSetTtfStyle(fontNum, style);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_FontSetTtfOutline)
{
    uint32_t fontNum;
    int      outline;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_INT(outline, 2);
    mtrFontSetTtfOutline(fontNum, outline);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_FontRenderTtfString)
{
    uint32_t    fontNum;
    uint32_t    texNum;
    uint8_t     r;
    uint8_t     g;
    uint8_t     b;
    const char *string;
    bool        success;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_UINT32(texNum, 2);
    MTR_SF_GET_UINT8(r, 3);
    MTR_SF_GET_UINT8(g, 4);
    MTR_SF_GET_UINT8(b, 5);
    MTR_SF_GET_STRING(string, 6);
    success = mtrFontRenderTtfString(fontNum, texNum, r, g, b, string);

    MTR_SF_PUSH_BOOL(success);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_FontCreateMbf)
{
    const char *name;
    int         reservedTables;
    int         width;
    int         height;
    uint32_t    fontNum;

    MTR_SF_GET_STRING(name, 1);
    MTR_SF_GET_INT(reservedTables, 2);
    MTR_SF_GET_INT(width, 3);
    MTR_SF_GET_INT(height, 4);
    fontNum = mtrFontCreateMbf(name, reservedTables, width, height);

    MTR_SF_PUSH_UINT32(fontNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FontAddMbfTextureTable)
{
    uint32_t fontNum;
    uint32_t texNum;
    int      tableNum;
    bool     result;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_UINT32(texNum, 2);
    MTR_SF_GET_INT(tableNum, 3);
    result = mtrFontAddMbfTextureTable(fontNum, texNum, tableNum);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FontDrawMbfString_f)
{
    uint32_t    fontNum;
    float       x;
    float       y;
    const char *string;
    bool        result;

    MTR_SF_GET_UINT32(fontNum, 1);
    MTR_SF_GET_SINGLE(x, 2);
    MTR_SF_GET_SINGLE(y, 3);
    MTR_SF_GET_STRING(string, 4);
    result = mtrFontDrawMbfString_f(fontNum, x, y, string);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrFontInit, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontLoadTtf, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontFree, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontSetTtfStyle, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontSetTtfOutline, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontRenderTtfString, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontCreateMbf, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontAddMbfTextureTable, "Abstraction_font");
    MTR_FIND_FUNCTION(mtrFontDrawMbfString_f, "Abstraction_font");

    if (ok)
    {
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
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
