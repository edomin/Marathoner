#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_TtfInit)
{
    int  dmSize;
    int  reservedCount;
    bool success;

    MTR_SF_GET_INT(dmSize, 1);
    MTR_SF_GET_INT(reservedCount, 2);
    success = mtrTtfInit(dmSize, reservedCount);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TtfQuit)
{
    mtrTtfQuit();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TtfLoad)
{
    const char *filename;
    int         size;
    int         fontNum;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_INT(size, 2);
    fontNum = mtrTtfLoad(filename, size);

    MTR_SF_PUSH_INT(fontNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TtfFree)
{
    int fontNum;

    MTR_SF_GET_INT(fontNum, 1);
    mtrTtfFree(fontNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TtfSetFontStyle)
{
    int fontNum;
    int style;

    MTR_SF_GET_INT(fontNum, 1);
    MTR_SF_GET_INT(style, 2);
    mtrTtfSetFontStyle(fontNum, style);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TtfSetFontOutline)
{
    int fontNum;
    int outline;

    MTR_SF_GET_INT(fontNum, 1);
    MTR_SF_GET_INT(outline, 2);
    mtrTtfSetFontOutline(fontNum, outline);

    return 0;
}
