#ifndef MTR_TEXTURE_BINDING_COMMON_C
#define MTR_TEXTURE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_TextureFunctionSupported,
 mtrTextureFunctionSupported);
MTR_SCRIPT_FUNC_B_U32t2(mtrSF_TextureInit, mtrTextureInit);
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_TextureBeginTarget, mtrTextureBeginTarget);
MTR_SCRIPT_FUNC_V_V(mtrSF_TextureEndTarget, mtrTextureEndTarget);
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_TextureGetWidth, mtrTextureGetWidth);
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_TextureGetHeight, mtrTextureGetHeight);

#ifdef lua_h
MTR_SCRIPT_FUNC(mtrSF_TextureGetSizes)
{
    uint32_t texNum;
    int      width;
    int      height;

    MTR_SF_GET_UINT32(texNum, 1);
    mtrTextureGetSizes(texNum, &width, &height);

    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_U32t_S1I2(mtrSF_TextureCreate, mtrTextureCreate);
MTR_SCRIPT_FUNC_U32t_S1(mtrSF_TextureLoad, mtrTextureLoad);
MTR_SCRIPT_FUNC_U32t_U32t1(mtrSF_TextureCopy, mtrTextureCopy);
MTR_SCRIPT_FUNC_V_U32t1S1(mtrSF_TextureSave, mtrTextureSave);
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_TextureFree, mtrTextureFree);
MTR_SCRIPT_FUNC_V_U32t2(mtrSF_TextureSetModulation_c,
 mtrTextureSetModulation_c);
MTR_SCRIPT_FUNC_V_U32t2(mtrSF_TextureSetModulation_ca,
 mtrTextureSetModulation_ca);
MTR_SCRIPT_FUNC_V_U32t1U8t3(mtrSF_TextureSetModulation_rgb,
 mtrTextureSetModulation_rgb);
MTR_SCRIPT_FUNC_V_U32t1U8t4(mtrSF_TextureSetModulation_rgba,
 mtrTextureSetModulation_rgba);
MTR_SCRIPT_FUNC_V_U32t1U8t1(mtrSF_TextureSetModulationAlpha,
 mtrTextureSetModulationAlpha);
MTR_SCRIPT_FUNC_V_U32t1F1(mtrSF_TextureSetModulationAlpha_f,
 mtrTextureSetModulationAlpha_f);
MTR_SCRIPT_FUNC_V_U32t1I4(mtrSF_TextureSetBlendFunction,
 mtrTextureSetBlendFunction);
MTR_SCRIPT_FUNC_V_U32t1B1(mtrSF_TextureSetAlphaBlending,
 mtrTextureSetAlphaBlending);
MTR_SCRIPT_FUNC_V_U32t1F2(mtrSF_TextureBlit_f, mtrTextureBlit_f);
MTR_SCRIPT_FUNC_V_U32t1F4(mtrSF_TextureBlitSized_f, mtrTextureBlitSized_f);
MTR_SCRIPT_FUNC_V_U32t1F4(mtrSF_TextureBlitScaled_f, mtrTextureBlitScaled_f);
MTR_SCRIPT_FUNC_V_U32t1F5(mtrSF_TextureBlitAngled_f, mtrTextureBlitAngled_f);
MTR_SCRIPT_FUNC_V_U32t1F2I1(mtrSF_TextureBlitFlipped_f,
 mtrTextureBlitFlipped_f);
MTR_SCRIPT_FUNC_V_U32t1F7I1(mtrSF_TextureBlitGeneral_f,
 mtrTextureBlitGeneral_f);
MTR_SCRIPT_FUNC_V_U32t1F6(mtrSF_TextureBlitRegion_f, mtrTextureBlitRegion_f);
MTR_SCRIPT_FUNC_V_U32t1F8(mtrSF_TextureBlitRegionSized_f,
 mtrTextureBlitRegionSized_f);
MTR_SCRIPT_FUNC_V_U32t1F8(mtrSF_TextureBlitRegionScaled_f,
 mtrTextureBlitRegionScaled_f);
MTR_SCRIPT_FUNC_V_U32t1F9(mtrSF_TextureBlitRegionAngled_f,
 mtrTextureBlitRegionAngled_f);
MTR_SCRIPT_FUNC_V_U32t1F6I1(mtrSF_TextureBlitRegionFlipped_f,
 mtrTextureBlitRegionFlipped_f);
MTR_SCRIPT_FUNC_V_U32t1F11I1(mtrSF_TextureBlitRegionGeneral_f,
 mtrTextureBlitRegionGeneral_f);
MTR_SCRIPT_FUNC_B_U32t1P1(mtrSF_TextureReceivePixels, mtrTextureReceivePixels);

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBeginTarget);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureEndTarget);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureGetWidth);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureGetHeight);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureGetSizes);
    #endif
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureCreate);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureLoad);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureCopy);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSave);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureFree);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSetModulation_c);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSetModulation_ca);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSetModulation_rgb);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSetModulation_rgba);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSetModulationAlpha);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSetModulationAlpha_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSetBlendFunction);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureSetAlphaBlending);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlit_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitSized_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitScaled_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitAngled_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitFlipped_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitGeneral_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitRegion_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitRegionSized_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitRegionScaled_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitRegionAngled_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitRegionFlipped_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureBlitRegionGeneral_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureReceivePixels);

    mtrScriptsRegisterVariable_i("FLIP_NONE", MTR_FLIP_NONE);
    mtrScriptsRegisterVariable_i("FLIP_HORIZONTAL", MTR_FLIP_HORIZONTAL);
    mtrScriptsRegisterVariable_i("FLIP_VERTICAL", MTR_FLIP_VERTICAL);
    mtrScriptsRegisterVariable_i("FLIP_BOTH", MTR_FLIP_BOTH);
//    mtrScriptsRegisterVariable_i("BLEND_ZERO", MTR_BLEND_ZERO);
//    mtrScriptsRegisterVariable_i("BLEND_ONE", MTR_BLEND_ONE);
//    mtrScriptsRegisterVariable_i("BLEND_SRC_COLOR",
//     MTR_BLEND_SRC_COLOR);
//    mtrScriptsRegisterVariable_i("BLEND_DST_COLOR",
//     MTR_BLEND_DST_COLOR);
//    mtrScriptsRegisterVariable_i("BLEND_ONE_MINUS_SRC",
//     MTR_BLEND_ONE_MINUS_SRC);
//    mtrScriptsRegisterVariable_i("BLEND_ONE_MINUS_DST",
//     MTR_BLEND_ONE_MINUS_DST);
//    mtrScriptsRegisterVariable_i("BLEND_SRC_ALPHA",
//     MTR_BLEND_SRC_ALPHA);
//    mtrScriptsRegisterVariable_i("BLEND_DST_ALPHA",
//     MTR_BLEND_DST_ALPHA);
//    mtrScriptsRegisterVariable_i("BLEND_ONE_MINUS_SRC_ALPHA",
//     MTR_BLEND_ONE_MINUS_SRC_ALPHA);
//    mtrScriptsRegisterVariable_i("BLEND_ONE_MINUS_DST_ALPHA",
//     MTR_BLEND_ONE_MINUS_DST_ALPHA);
}

#endif
