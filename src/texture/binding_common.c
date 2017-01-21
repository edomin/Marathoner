#ifndef MTR_TEXTURE_BINDING_COMMON_C
#define MTR_TEXTURE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_TextureInit)
{
    uint32_t  dmSize;
    uint32_t  reservedCount;
    bool      success;

    MTR_SF_GET_UINT32(dmSize, 1);
    MTR_SF_GET_UINT32(reservedCount, 2);
    success = mtrTextureInit(dmSize, reservedCount);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBeginTarget)
{
    uint32_t texNum;

    MTR_SF_GET_UINT32(texNum, 1);
    mtrTextureBeginTarget(texNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureEndTarget)
{
    mtrTextureEndTarget();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureGetWidth)
{
    uint32_t texNum;
    int      width;

    MTR_SF_GET_UINT32(texNum, 1);
    width = mtrTextureGetWidth(texNum);

    MTR_SF_PUSH_INT(width);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureGetHeight)
{
    uint32_t texNum;
    int      height;

    MTR_SF_GET_UINT32(texNum, 1);
    height = mtrTextureGetHeight(texNum);

    MTR_SF_PUSH_INT(height);

    return 0;
}

#ifndef _SQUIRREL_H_
MTR_SCRIPT_FUNC(mtrSF_TextureGetSizes)
{
    uint32_t texNum;
    int      width;
    int      height;

    MTR_SF_GET_UINT32(texNum, 1);
    mtrTextureGetSizes(texNum, &width, &height);

    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);

    return 0;
}
#endif

MTR_SCRIPT_FUNC(mtrSF_TextureCreate)
{
    const char *name;
    int         width;
    int         height;
    uint32_t    texNum;

    MTR_SF_GET_STRING(name, 1);
    MTR_SF_GET_INT(width, 2);
    MTR_SF_GET_INT(height, 3);
    texNum = mtrTextureCreate(name, width, height);

    MTR_SF_PUSH_UINT32(texNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TextureLoad)
{
    const char *filename;
    uint32_t    texNum;

    MTR_SF_GET_STRING(filename, 1);
    texNum = mtrTextureLoad(filename);

    MTR_SF_PUSH_UINT32(texNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_TextureFree)
{
    uint32_t texNum;

    MTR_SF_GET_UINT32(texNum, 1);
    mtrTextureFree(texNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureSetBlendFunction)
{
    uint32_t texNum;
    int      srcColor;
    int      destColor;
    int      srcAlpha;
    int      dstAlpha;

    MTR_SF_GET_UINT32(texNum, 1);
    MTR_SF_GET_INT(srcColor, 2);
    MTR_SF_GET_INT(destColor, 3);
    MTR_SF_GET_INT(srcAlpha, 4);
    MTR_SF_GET_INT(dstAlpha, 5);
    mtrTextureSetBlendFunction(texNum, srcColor, destColor, srcAlpha, dstAlpha);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureSetAlphaBlending)
{
    uint32_t texNum;
    bool     blending;

    MTR_SF_GET_UINT32(texNum, 1);
    MTR_SF_GET_BOOL(blending, 2);
    mtrTextureSetAlphaBlending(texNum, blending);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBlit_f)
{
    uint32_t texNum;
    float    x;
    float    y;

    MTR_SF_GET_UINT32(texNum, 1);
    MTR_SF_GET_SINGLE(x, 2);
    MTR_SF_GET_SINGLE(y, 3);
    mtrTextureBlit_f(texNum, x, y);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_TextureBlitRegion_f)
{
    uint32_t texNum;
    float    x;
    float    y;
    float    rx;
    float    ry;
    float    rw;
    float    rh;

    MTR_SF_GET_UINT32(texNum, 1);
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
    uint32_t texNum;
    float    x;
    float    y;
    float    w;
    float    h;
    float    rx;
    float    ry;
    float    rw;
    float    rh;

    MTR_SF_GET_UINT32(texNum, 1);
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
    uint32_t texNum;
    float    x;
    float    y;
    float    rx;
    float    ry;
    float    rw;
    float    rh;
    float    angle;
    float    pivotX;
    float    pivotY;

    MTR_SF_GET_UINT32(texNum, 1);
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
    uint32_t texNum;
    float    x;
    float    y;
    float    rx;
    float    ry;
    float    rw;
    float    rh;
    int      flip;

    MTR_SF_GET_UINT32(texNum, 1);
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
    uint32_t texNum;
    float    x;
    float    y;
    float    w;
    float    h;
    float    rx;
    float    ry;
    float    rw;
    float    rh;
    float    angle;
    float    pivotX;
    float    pivotY;
    int      flip;

    MTR_SF_GET_UINT32(texNum, 1);
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

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();
    mtrTextureInit = (mtrTextureInitFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureInit");
    if (mtrTextureInit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureInit");
        ok = false;
    }
    mtrTextureBeginTarget = (mtrTextureBeginTargetFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureBeginTarget");
    if (mtrTextureBeginTarget == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureBeginTarget");
        ok = false;
    }
    mtrTextureEndTarget = (mtrTextureEndTargetFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureEndTarget");
    if (mtrTextureEndTarget == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureEndTarget");
        ok = false;
    }
    mtrTextureGetWidth = (mtrTextureGetWidthFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureGetWidth");
    if (mtrTextureGetWidth == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureGetWidth");
        ok = false;
    }
    mtrTextureGetHeight = (mtrTextureGetHeightFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureGetHeight");
    if (mtrTextureGetHeight == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureGetHeight");
        ok = false;
    }
    #ifndef _SQUIRREL_H_
    mtrTextureGetSizes = (mtrTextureGetSizesFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureGetSizes");
    if (mtrTextureGetSizes == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureGetSizes");
        ok = false;
    }
    #endif
    mtrTextureCreate = (mtrTextureCreateFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureCreate");
    if (mtrTextureCreate == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureCreate");
        ok = false;
    }
    mtrTextureLoad = (mtrTextureLoadFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureLoad");
    if (mtrTextureLoad == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureLoad");
        ok = false;
    }
    mtrTextureFree = (mtrTextureFreeFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureFree");
    if (mtrTextureFree == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureFree");
        ok = false;
    }
    mtrTextureSetBlendFunction = (mtrTextureSetBlendFunctionFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureSetBlendFunction");
    if (mtrTextureSetBlendFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureSetBlendFunction");
        ok = false;
    }
    mtrTextureSetAlphaBlending = (mtrTextureSetAlphaBlendingFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureSetAlphaBlending");
    if (mtrTextureSetAlphaBlending == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureSetAlphaBlending");
        ok = false;
    }
    mtrTextureBlit_f = (mtrTextureBlit_fFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureBlit_f");
    if (mtrTextureBlit_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureBlit_f");
        ok = false;
    }
    mtrTextureBlitRegion_f = (mtrTextureBlitRegion_fFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureBlitRegion_f");
    if (mtrTextureBlitRegion_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureBlitRegion_f");
        ok = false;
    }
    mtrTextureBlitRegionScaled_f = (mtrTextureBlitRegionScaled_fFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureBlitRegionScaled_f");
    if (mtrTextureBlitRegionScaled_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureBlitRegionScaled_f");
        ok = false;
    }
    mtrTextureBlitRegionAngled_f = (mtrTextureBlitRegionAngled_fFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureBlitRegionAngled_f");
    if (mtrTextureBlitRegionAngled_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureBlitRegionAngled_f");
        ok = false;
    }
    mtrTextureBlitRegionFlipped_f = (mtrTextureBlitRegionFlipped_fFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureBlitRegionFlipped_f");
    if (mtrTextureBlitRegionFlipped_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureBlitRegionFlipped_f");
        ok = false;
    }
    mtrTextureBlitRegionGeneral_f = (mtrTextureBlitRegionGeneral_fFunc)mtrFindFunction("Texture_SDL2_gpu",
      "mtrTextureBlitRegionGeneral_f");
    if (mtrTextureBlitRegionGeneral_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrTextureBlitRegionGeneral_f");
        ok = false;
    }
    if (ok)
    {
        mtrScriptsRegisterNumericVariable("FLIP_NONE", MTR_FLIP_NONE);
        mtrScriptsRegisterNumericVariable("FLIP_HORIZONTAL",
         MTR_FLIP_HORIZONTAL);
        mtrScriptsRegisterNumericVariable("FLIP_VERTICAL",
         MTR_FLIP_VERTICAL);
        mtrScriptsRegisterNumericVariable("FLIP_BOTH", MTR_FLIP_BOTH);
//        mtrScriptsRegisterNumericVariable("BLEND_ZERO", MTR_BLEND_ZERO);
//        mtrScriptsRegisterNumericVariable("BLEND_ONE", MTR_BLEND_ONE);
//        mtrScriptsRegisterNumericVariable("BLEND_SRC_COLOR",
//         MTR_BLEND_SRC_COLOR);
//        mtrScriptsRegisterNumericVariable("BLEND_DST_COLOR",
//         MTR_BLEND_DST_COLOR);
//        mtrScriptsRegisterNumericVariable("BLEND_ONE_MINUS_SRC",
//         MTR_BLEND_ONE_MINUS_SRC);
//        mtrScriptsRegisterNumericVariable("BLEND_ONE_MINUS_DST",
//         MTR_BLEND_ONE_MINUS_DST);
//        mtrScriptsRegisterNumericVariable("BLEND_SRC_ALPHA",
//         MTR_BLEND_SRC_ALPHA);
//        mtrScriptsRegisterNumericVariable("BLEND_DST_ALPHA",
//         MTR_BLEND_DST_ALPHA);
//        mtrScriptsRegisterNumericVariable("BLEND_ONE_MINUS_SRC_ALPHA",
//         MTR_BLEND_ONE_MINUS_SRC_ALPHA);
//        mtrScriptsRegisterNumericVariable("BLEND_ONE_MINUS_DST_ALPHA",
//         MTR_BLEND_ONE_MINUS_DST_ALPHA);
        mtrScriptsRegisterFunction(mtrSF_TextureInit, "TextureInit");
        mtrScriptsRegisterFunction(mtrSF_TextureBeginTarget,
         "TextureBeginTarget");
        mtrScriptsRegisterFunction(mtrSF_TextureEndTarget, "TextureEndTarget");
        mtrScriptsRegisterFunction(mtrSF_TextureGetWidth, "TextureGetWidth");
        mtrScriptsRegisterFunction(mtrSF_TextureGetHeight,
         "mtrSF_TextureGetHeight");
        #ifndef _SQUIRREL_H_
        mtrScriptsRegisterFunction(mtrSF_TextureGetSizes,
         "mtrSF_TextureGetSizes");
        #endif
        mtrScriptsRegisterFunction(mtrSF_TextureCreate, "TextureCreate");
        mtrScriptsRegisterFunction(mtrSF_TextureLoad, "TextureLoad");
        mtrScriptsRegisterFunction(mtrSF_TextureFree, "TextureFree");
        mtrScriptsRegisterFunction(mtrSF_TextureSetBlendFunction,
         "TextureSetBlendFunction");
        mtrScriptsRegisterFunction(mtrSF_TextureSetAlphaBlending,
         "TextureSetBlending");
        mtrScriptsRegisterFunction(mtrSF_TextureBlit_f, "TextureBlit_f");
        mtrScriptsRegisterFunction(mtrSF_TextureBlitRegion_f,
         "TextureBlitRegion_f");
        mtrScriptsRegisterFunction(mtrSF_TextureBlitRegionScaled_f,
         "TextureBlitRegionScaled_f");
        mtrScriptsRegisterFunction(mtrSF_TextureBlitRegionAngled_f,
         "TextureBlitRegionAngled_f");
        mtrScriptsRegisterFunction(mtrSF_TextureBlitRegionFlipped_f,
         "TextureBlitRegionFlipped_f");
        mtrScriptsRegisterFunction(mtrSF_TextureBlitRegionGeneral_f,
         "TextureBlitRegionGeneral_f");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
