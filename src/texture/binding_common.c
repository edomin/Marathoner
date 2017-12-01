#ifndef MTR_TEXTURE_BINDING_COMMON_C
#define MTR_TEXTURE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_TextureFunctionSupported,
 MTR_TextureFunctionSupported);
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_TextureInit, MTR_TextureInit);
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_TextureBeginTarget, MTR_TextureBeginTarget);
MTR_SCRIPT_FUNC_V_V(MTR_SF_TextureEndTarget, MTR_TextureEndTarget);
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_TextureGetWidth, MTR_TextureGetWidth);
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_TextureGetHeight, MTR_TextureGetHeight);

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_TextureGetSizes)
{
    uint32_t texNum;
    int      width;
    int      height;

    MTR_SF_GET_UINT32(texNum, 1);
    MTR_TextureGetSizes(texNum, &width, &height);

    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);

    return 2;
}
#endif

MTR_SCRIPT_FUNC_U32t_S1I2(MTR_SF_TextureCreate, MTR_TextureCreate);
MTR_SCRIPT_FUNC_U32t_S1(MTR_SF_TextureLoad, MTR_TextureLoad);
MTR_SCRIPT_FUNC_U32t_U32t1(MTR_SF_TextureCopy, MTR_TextureCopy);
MTR_SCRIPT_FUNC_V_U32t1S1(MTR_SF_TextureSave, MTR_TextureSave);
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_TextureFree, MTR_TextureFree);
MTR_SCRIPT_FUNC_V_U32t2(MTR_SF_TextureSetModulation_c,
 MTR_TextureSetModulation_c);
MTR_SCRIPT_FUNC_V_U32t2(MTR_SF_TextureSetModulation_ca,
 MTR_TextureSetModulation_ca);
MTR_SCRIPT_FUNC_V_U32t1U8t3(MTR_SF_TextureSetModulation_rgb,
 MTR_TextureSetModulation_rgb);
MTR_SCRIPT_FUNC_V_U32t1U8t4(MTR_SF_TextureSetModulation_rgba,
 MTR_TextureSetModulation_rgba);
MTR_SCRIPT_FUNC_V_U32t1U8t1(MTR_SF_TextureSetModulationAlpha,
 MTR_TextureSetModulationAlpha);
MTR_SCRIPT_FUNC_V_U32t1F1(MTR_SF_TextureSetModulationAlpha_f,
 MTR_TextureSetModulationAlpha_f);
MTR_SCRIPT_FUNC_V_U32t1I4(MTR_SF_TextureSetBlendFunction,
 MTR_TextureSetBlendFunction);
MTR_SCRIPT_FUNC_V_U32t1B1(MTR_SF_TextureSetAlphaBlending,
 MTR_TextureSetAlphaBlending);
MTR_SCRIPT_FUNC_V_U32t1F2(MTR_SF_TextureBlit_f, MTR_TextureBlit_f);
MTR_SCRIPT_FUNC_V_U32t1F4(MTR_SF_TextureBlitSized_f, MTR_TextureBlitSized_f);
MTR_SCRIPT_FUNC_V_U32t1F4(MTR_SF_TextureBlitScaled_f, MTR_TextureBlitScaled_f);
MTR_SCRIPT_FUNC_V_U32t1F5(MTR_SF_TextureBlitAngled_f, MTR_TextureBlitAngled_f);
MTR_SCRIPT_FUNC_V_U32t1F2I1(MTR_SF_TextureBlitFlipped_f,
 MTR_TextureBlitFlipped_f);
MTR_SCRIPT_FUNC_V_U32t1F7I1(MTR_SF_TextureBlitGeneral_f,
 MTR_TextureBlitGeneral_f);
MTR_SCRIPT_FUNC_V_U32t1F6(MTR_SF_TextureBlitRegion_f, MTR_TextureBlitRegion_f);
MTR_SCRIPT_FUNC_V_U32t1F8(MTR_SF_TextureBlitRegionSized_f,
 MTR_TextureBlitRegionSized_f);
MTR_SCRIPT_FUNC_V_U32t1F8(MTR_SF_TextureBlitRegionScaled_f,
 MTR_TextureBlitRegionScaled_f);
MTR_SCRIPT_FUNC_V_U32t1F9(MTR_SF_TextureBlitRegionAngled_f,
 MTR_TextureBlitRegionAngled_f);
MTR_SCRIPT_FUNC_V_U32t1F6I1(MTR_SF_TextureBlitRegionFlipped_f,
 MTR_TextureBlitRegionFlipped_f);
MTR_SCRIPT_FUNC_V_U32t1F11I1(MTR_SF_TextureBlitRegionGeneral_f,
 MTR_TextureBlitRegionGeneral_f);
MTR_SCRIPT_FUNC_B_U32t1P1(MTR_SF_TextureReceivePixels,
 MTR_TextureReceivePixels);
MTR_SCRIPT_FUNC_B_U32t1P1I2(MTR_SF_TextureReceivePixelsToPos,
 MTR_TextureReceivePixelsToPos);

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

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
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, TextureReceivePixelsToPos);

    MTR_ScriptsRegisterVariable_i("FLIP_NONE", MTR_FLIP_NONE);
    MTR_ScriptsRegisterVariable_i("FLIP_HORIZONTAL", MTR_FLIP_HORIZONTAL);
    MTR_ScriptsRegisterVariable_i("FLIP_VERTICAL", MTR_FLIP_VERTICAL);
    MTR_ScriptsRegisterVariable_i("FLIP_BOTH", MTR_FLIP_BOTH);
//    MTR_ScriptsRegisterVariable_i("BLEND_ZERO", MTR_BLEND_ZERO);
//    MTR_ScriptsRegisterVariable_i("BLEND_ONE", MTR_BLEND_ONE);
//    MTR_ScriptsRegisterVariable_i("BLEND_SRC_COLOR",
//     MTR_BLEND_SRC_COLOR);
//    MTR_ScriptsRegisterVariable_i("BLEND_DST_COLOR",
//     MTR_BLEND_DST_COLOR);
//    MTR_ScriptsRegisterVariable_i("BLEND_ONE_MINUS_SRC",
//     MTR_BLEND_ONE_MINUS_SRC);
//    MTR_ScriptsRegisterVariable_i("BLEND_ONE_MINUS_DST",
//     MTR_BLEND_ONE_MINUS_DST);
//    MTR_ScriptsRegisterVariable_i("BLEND_SRC_ALPHA",
//     MTR_BLEND_SRC_ALPHA);
//    MTR_ScriptsRegisterVariable_i("BLEND_DST_ALPHA",
//     MTR_BLEND_DST_ALPHA);
//    MTR_ScriptsRegisterVariable_i("BLEND_ONE_MINUS_SRC_ALPHA",
//     MTR_BLEND_ONE_MINUS_SRC_ALPHA);
//    MTR_ScriptsRegisterVariable_i("BLEND_ONE_MINUS_DST_ALPHA",
//     MTR_BLEND_ONE_MINUS_DST_ALPHA);
}

#endif
