#ifndef MTR_TEXTURE_BINDING_COMMON_C
#define MTR_TEXTURE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_B_U32t2(mtrSF_TextureInit, mtrTextureInit)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_TextureBeginTarget, mtrTextureBeginTarget)
MTR_SCRIPT_FUNC_V_V(mtrSF_TextureEndTarget, mtrTextureEndTarget)
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_TextureGetWidth, mtrTextureGetWidth)
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_TextureGetHeight, mtrTextureGetHeight)

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

MTR_SCRIPT_FUNC_U32t_S1I2(mtrSF_TextureCreate, mtrTextureCreate)
MTR_SCRIPT_FUNC_U32t_S1(mtrSF_TextureLoad, mtrTextureLoad)
MTR_SCRIPT_FUNC_U32t_U32t1(mtrSF_TextureCopy, mtrTextureCopy)
MTR_SCRIPT_FUNC_V_U32t1S1(mtrSF_TextureSave, mtrTextureSave)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_TextureFree, mtrTextureFree)
MTR_SCRIPT_FUNC_V_U32t2(mtrSF_TextureSetModulation_c, mtrTextureSetModulation_c)
MTR_SCRIPT_FUNC_V_U32t2(mtrSF_TextureSetModulation_ca,
 mtrTextureSetModulation_ca)
MTR_SCRIPT_FUNC_V_U32t1U8t3(mtrSF_TextureSetModulation_rgb,
 mtrTextureSetModulation_rgb)
MTR_SCRIPT_FUNC_V_U32t1U8t4(mtrSF_TextureSetModulation_rgba,
 mtrTextureSetModulation_rgba)
MTR_SCRIPT_FUNC_V_U32t1U8t1(mtrSF_TextureSetModulationAlpha,
 mtrTextureSetModulationAlpha)
MTR_SCRIPT_FUNC_V_U32t1F1(mtrSF_TextureSetModulationAlpha_f,
 mtrTextureSetModulationAlpha_f)
MTR_SCRIPT_FUNC_V_U32t1I4(mtrSF_TextureSetBlendFunction,
 mtrTextureSetBlendFunction)
MTR_SCRIPT_FUNC_V_U32t1B1(mtrSF_TextureSetAlphaBlending,
 mtrTextureSetAlphaBlending)
MTR_SCRIPT_FUNC_V_U32t1F2(mtrSF_TextureBlit_f, mtrTextureBlit_f)
MTR_SCRIPT_FUNC_V_U32t1F6(mtrSF_TextureBlitRegion_f, mtrTextureBlitRegion_f)
MTR_SCRIPT_FUNC_V_U32t1F8(mtrSF_TextureBlitRegionScaled_f,
 mtrTextureBlitRegionScaled_f)
MTR_SCRIPT_FUNC_V_U32t1F9(mtrSF_TextureBlitRegionAngled_f,
 mtrTextureBlitRegionAngled_f)
MTR_SCRIPT_FUNC_V_U32t1F6I1(mtrSF_TextureBlitRegionFlipped_f,
 mtrTextureBlitRegionFlipped_f)
MTR_SCRIPT_FUNC_V_U32t1F11I1(mtrSF_TextureBlitRegionGeneral_f,
 mtrTextureBlitRegionGeneral_f)

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrTextureInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureBeginTarget, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureEndTarget, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureGetWidth, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureGetHeight, MTR_SOURCE_MODULE);
    #ifndef _SQUIRREL_H_
    MTR_FIND_FUNCTION(mtrTextureGetSizes, MTR_SOURCE_MODULE);
    #endif
    MTR_FIND_FUNCTION(mtrTextureCreate, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureLoad, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureCopy, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSave, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureFree, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSetModulation_c, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSetModulation_ca, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSetModulation_rgb, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSetModulation_rgba, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSetModulationAlpha, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSetModulationAlpha_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSetBlendFunction, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureSetAlphaBlending, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureBlit_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureBlitRegion_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureBlitRegionScaled_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureBlitRegionAngled_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureBlitRegionFlipped_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrTextureBlitRegionGeneral_f, MTR_SOURCE_MODULE);

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
        mtrScriptsRegisterFunction(mtrSF_TextureCopy, "TextureCopy");
        mtrScriptsRegisterFunction(mtrSF_TextureSave, "TextureSave");
        mtrScriptsRegisterFunction(mtrSF_TextureFree, "TextureFree");
        mtrScriptsRegisterFunction(mtrSF_TextureSetModulation_c,
         "TextureSetModulation_c");
        mtrScriptsRegisterFunction(mtrSF_TextureSetModulation_ca,
         "TextureSetModulation_ca");
        mtrScriptsRegisterFunction(mtrSF_TextureSetModulation_rgb,
         "TextureSetModulation_rgb");
        mtrScriptsRegisterFunction(mtrSF_TextureSetModulation_rgba,
         "TextureSetModulation_rgba");
        mtrScriptsRegisterFunction(mtrSF_TextureSetModulationAlpha,
         "TextureSetModulationAlpha");
        mtrScriptsRegisterFunction(mtrSF_TextureSetModulationAlpha_f,
         "TextureSetModulationAlpha_f");
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
