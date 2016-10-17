#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_TextureInit)
{
    int  dmSize;
    int  reservedCount;
    bool success;

    MTR_SF_GET_INT(dmSize, 1);
    MTR_SF_GET_INT(reservedCount, 2);
    success = mtrTextureInit(dmSize, reservedCount);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TextureLoad)
{
    const char *filename;
    int         texNum;

    MTR_SF_GET_STRING(filename, 1);
    texNum = mtrTextureLoad(filename);

    MTR_SF_PUSH_INT(texNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TextureFree)
{
    int texNum;

    MTR_SF_GET_INT(texNum, 1);
    mtrTextureFree(texNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureSetBlendFunction)
{
    int texNum;
    int srcColor;
    int destColor;
    int srcAlpha;
    int dstAlpha;

    MTR_SF_GET_INT(texNum, 1);
    MTR_SF_GET_INT(srcColor, 2);
    MTR_SF_GET_INT(destColor, 3);
    MTR_SF_GET_INT(srcAlpha, 4);
    MTR_SF_GET_INT(dstAlpha, 5);
    mtrTextureSetBlendFunction(texNum, srcColor, destColor, srcAlpha, dstAlpha);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureSetAlphaBlending)
{
    int  texNum;
    bool blending;

    MTR_SF_GET_INT(texNum, 1);
    MTR_SF_GET_BOOL(blending, 2);
    mtrTextureSetAlphaBlending(texNum, blending);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBlit_f)
{
    int   texNum;
    float x;
    float y;

    MTR_SF_GET_INT(texNum, 1);
    MTR_SF_GET_SINGLE(x, 2);
    MTR_SF_GET_SINGLE(y, 3);
    mtrTextureBlit_f(texNum, x, y);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBlitRegion_f)
{
    int   texNum;
    float x;
    float y;
    float rx;
    float ry;
    float rw;
    float rh;

    MTR_SF_GET_INT(texNum, 1);
    MTR_SF_GET_SINGLE(x, 2);
    MTR_SF_GET_SINGLE(y, 3);
    MTR_SF_GET_SINGLE(rx, 4);
    MTR_SF_GET_SINGLE(ry, 5);
    MTR_SF_GET_SINGLE(rw, 6);
    MTR_SF_GET_SINGLE(rh, 7);
    mtrTextureBlitRegion_f(texNum, x, y, rx, ry, rw, rh);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBlitRegionScaled_f)
{
    int   texNum;
    float x;
    float y;
    float w;
    float h;
    float rx;
    float ry;
    float rw;
    float rh;

    MTR_SF_GET_INT(texNum, 1);
    MTR_SF_GET_SINGLE(x, 2);
    MTR_SF_GET_SINGLE(y, 3);
    MTR_SF_GET_SINGLE(w, 4);
    MTR_SF_GET_SINGLE(h, 5);
    MTR_SF_GET_SINGLE(rx, 6);
    MTR_SF_GET_SINGLE(ry, 7);
    MTR_SF_GET_SINGLE(rw, 8);
    MTR_SF_GET_SINGLE(rh, 9);
    mtrTextureBlitRegionScaled_f(texNum, x, y, w, h, rx, ry, rw, rh);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBlitRegionAngled_f)
{
    int   texNum;
    float x;
    float y;
    float rx;
    float ry;
    float rw;
    float rh;
    float angle;
    float pivotX;
    float pivotY;

    MTR_SF_GET_INT(texNum, 1);
    MTR_SF_GET_SINGLE(x, 2);
    MTR_SF_GET_SINGLE(y, 3);
    MTR_SF_GET_SINGLE(rx, 4);
    MTR_SF_GET_SINGLE(ry, 5);
    MTR_SF_GET_SINGLE(rw, 6);
    MTR_SF_GET_SINGLE(rh, 7);
    MTR_SF_GET_SINGLE(angle, 8);
    MTR_SF_GET_SINGLE(pivotX, 9);
    MTR_SF_GET_SINGLE(pivotY, 10);
    mtrTextureBlitRegionAngled_f(texNum, x, y, rx, ry, rw, rh, angle, pivotX,
     pivotY);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBlitRegionFlipped_f)
{
    int   texNum;
    float x;
    float y;
    float rx;
    float ry;
    float rw;
    float rh;
    int   flip;

    MTR_SF_GET_INT(texNum, 1);
    MTR_SF_GET_SINGLE(x, 2);
    MTR_SF_GET_SINGLE(y, 3);
    MTR_SF_GET_SINGLE(rx, 4);
    MTR_SF_GET_SINGLE(ry, 5);
    MTR_SF_GET_SINGLE(rw, 6);
    MTR_SF_GET_SINGLE(rh, 7);
    MTR_SF_GET_INT(flip, 8);
    mtrTextureBlitRegionFlipped_f(texNum, x, y, rx, ry, rw, rh, flip);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBlitRegionGeneral_f)
{
    int   texNum;
    float x;
    float y;
    float w;
    float h;
    float rx;
    float ry;
    float rw;
    float rh;
    float angle;
    float pivotX;
    float pivotY;
    int   flip;

    MTR_SF_GET_INT(texNum, 1);
    MTR_SF_GET_SINGLE(x, 2);
    MTR_SF_GET_SINGLE(y, 3);
    MTR_SF_GET_SINGLE(w, 4);
    MTR_SF_GET_SINGLE(h, 5);
    MTR_SF_GET_SINGLE(rx, 6);
    MTR_SF_GET_SINGLE(ry, 7);
    MTR_SF_GET_SINGLE(rw, 8);
    MTR_SF_GET_SINGLE(rh, 9);
    MTR_SF_GET_SINGLE(angle, 10);
    MTR_SF_GET_SINGLE(pivotX, 11);
    MTR_SF_GET_SINGLE(pivotY, 12);
    MTR_SF_GET_INT(flip, 13);
    mtrTextureBlitRegionGeneral_f(texNum, x, y, w, h, rx, ry, rw, rh, angle,
     pivotX, pivotY, flip);

    return 0;
}
