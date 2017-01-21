#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_SpriteInit)
{
    uint32_t dmSize;
    uint32_t reservedCount;
    bool     success;

    MTR_SF_GET_UINT32(dmSize, 1);
    MTR_SF_GET_UINT32(reservedCount, 2);
    success = mtrSpriteInit(dmSize, reservedCount);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_SpriteLoad)
{
    const char *filename;
    int         clipWidth;
    int         clipHeight;
    int         rowsCount;
    int         colsCount;
    int         clipsCount;
    int         anchorX;
    int         anchorY;
    uint32_t    sprNum;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_INT(clipWidth, 2);
    MTR_SF_GET_INT(clipHeight, 3);
    MTR_SF_GET_INT(rowsCount, 4);
    MTR_SF_GET_INT(colsCount, 5);
    MTR_SF_GET_INT(clipsCount, 6);
    MTR_SF_GET_INT(anchorX, 7);
    MTR_SF_GET_INT(anchorY, 8);
    sprNum = mtrSpriteLoad(filename, clipWidth, clipHeight, rowsCount,
     colsCount, clipsCount, anchorX, anchorY);

    MTR_SF_PUSH_UINT32(sprNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_SpriteFree)
{
    uint32_t sprNum;

    MTR_SF_GET_UINT32(sprNum, 1);
    mtrSpriteFree(sprNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_SpriteDraw_f)
{
    uint32_t sprNum;
    int      clipNum;
    float    x;
    float    y;

    MTR_SF_GET_UINT32(sprNum, 1);
    MTR_SF_GET_INT(clipNum, 2);
    MTR_SF_GET_SINGLE(x, 3);
    MTR_SF_GET_SINGLE(y, 4);
    mtrSpriteDraw_f(sprNum, clipNum, x, y);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_SpriteDrawScaled_f)
{
    uint32_t sprNum;
    int      clipNum;
    float    x;
    float    y;
    float    w;
    float    h;

    MTR_SF_GET_UINT32(sprNum, 1);
    MTR_SF_GET_INT(clipNum, 2);
    MTR_SF_GET_SINGLE(x, 3);
    MTR_SF_GET_SINGLE(y, 4);
    MTR_SF_GET_SINGLE(w, 5);
    MTR_SF_GET_SINGLE(h, 6);
    mtrSpriteDrawScaled_f(sprNum, clipNum, x, y, w, h);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_SpriteDrawAngled_f)
{
    uint32_t sprNum;
    int      clipNum;
    float    x;
    float    y;
    float    angle;

    MTR_SF_GET_UINT32(sprNum, 1);
    MTR_SF_GET_INT(clipNum, 2);
    MTR_SF_GET_SINGLE(x, 3);
    MTR_SF_GET_SINGLE(y, 4);
    MTR_SF_GET_SINGLE(angle, 5);
    mtrSpriteDrawAngled_f(sprNum, clipNum, x, y, angle);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_SpriteDrawFlipped_f)
{
    uint32_t sprNum;
    int      clipNum;
    float    x;
    float    y;
    int      flip;

    MTR_SF_GET_UINT32(sprNum, 1);
    MTR_SF_GET_INT(clipNum, 2);
    MTR_SF_GET_SINGLE(x, 3);
    MTR_SF_GET_SINGLE(y, 4);
    MTR_SF_GET_INT(flip, 5);
    mtrSpriteDrawFlipped_f(sprNum, clipNum, x, y, flip);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_SpriteDrawGeneral_f)
{
    uint32_t sprNum;
    int      clipNum;
    float    x;
    float    y;
    float    w;
    float    h;
    float    angle;
    int      flip;

    MTR_SF_GET_UINT32(sprNum, 1);
    MTR_SF_GET_INT(clipNum, 2);
    MTR_SF_GET_SINGLE(x, 3);
    MTR_SF_GET_SINGLE(y, 4);
    MTR_SF_GET_SINGLE(w, 5);
    MTR_SF_GET_SINGLE(h, 6);
    MTR_SF_GET_SINGLE(angle, 7);
    MTR_SF_GET_INT(flip, 8);
    mtrSpriteDrawGeneral_f(sprNum, clipNum, x, y, w, h, angle, flip);

    return 0;
}

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrSpriteInit, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteLoad, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteFree, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDraw_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDrawScaled_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDrawAngled_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDrawFlipped_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDrawGeneral_f, "Abstraction_sprite");

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_SpriteInit, "mtrSpriteInit");
        mtrScriptsRegisterFunction(mtrSF_SpriteLoad, "mtrSpriteLoad");
        mtrScriptsRegisterFunction(mtrSF_SpriteFree, "mtrSpriteFree");
        mtrScriptsRegisterFunction(mtrSF_SpriteDraw_f, "mtrSpriteDraw_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDrawScaled_f,
         "mtrSpriteDrawScaled_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDrawAngled_f,
         "mtrSpriteDrawAngled_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDrawFlipped_f,
         "mtrSpriteDrawFlipped_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDrawGeneral_f,
         "mtrSpriteDrawGeneral_f");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
