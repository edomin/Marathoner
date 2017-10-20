#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_SpriteFunctionSupported, MTR_SpriteFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_SpriteInit, MTR_SpriteInit)
MTR_SCRIPT_FUNC_U32t_S1I7(MTR_SF_SpriteLoad, MTR_SpriteLoad)
MTR_SCRIPT_FUNC_U32t_S1I2(MTR_SF_SpriteLoadSimple, MTR_SpriteLoadSimple)
MTR_SCRIPT_FUNC_U32t_S1I1(MTR_SF_SpriteLoadAtlas, MTR_SpriteLoadAtlas)
MTR_SCRIPT_FUNC_B_U32t1I7(MTR_SF_SpriteSetAtlasFrame, MTR_SpriteSetAtlasFrame)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_SpriteFree, MTR_SpriteFree)
MTR_SCRIPT_FUNC_V_U32t2(MTR_SF_SpriteSetModulation_c, MTR_SpriteSetModulation_c)
MTR_SCRIPT_FUNC_V_U32t2(MTR_SF_SpriteSetModulation_ca, MTR_SpriteSetModulation_ca)
MTR_SCRIPT_FUNC_V_U32t1U8t3(MTR_SF_SpriteSetModulation_rgb,
 MTR_SpriteSetModulation_rgb)
MTR_SCRIPT_FUNC_V_U32t1U8t4(MTR_SF_SpriteSetModulation_rgba,
 MTR_SpriteSetModulation_rgba)
MTR_SCRIPT_FUNC_V_U32t1U8t1(MTR_SF_SpriteSetModulationAlpha,
 MTR_SpriteSetModulationAlpha)
MTR_SCRIPT_FUNC_V_U32t1F1(MTR_SF_SpriteSetModulationAlpha_f,
 MTR_SpriteSetModulationAlpha_f)
MTR_SCRIPT_FUNC_V_U32t1I1F2(MTR_SF_SpriteDraw_f, MTR_SpriteDraw_f)
MTR_SCRIPT_FUNC_V_U32t1I1F4(MTR_SF_SpriteDrawSized_f, MTR_SpriteDrawSized_f)
MTR_SCRIPT_FUNC_V_U32t1I1F4(MTR_SF_SpriteDrawScaled_f, MTR_SpriteDrawScaled_f)
MTR_SCRIPT_FUNC_V_U32t1I1F3(MTR_SF_SpriteDrawAngled_f, MTR_SpriteDrawAngled_f)
MTR_SCRIPT_FUNC_V_U32t1I1F2I1(MTR_SF_SpriteDrawFlipped_f, MTR_SpriteDrawFlipped_f)
MTR_SCRIPT_FUNC_V_U32t1I1F5I1(MTR_SF_SpriteDrawGeneral_f, MTR_SpriteDrawGeneral_f)

void MTR_ScriptsRegisterAll(void)
{
    mtrVm = MTR_ScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteInit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteLoad);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteLoadSimple);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteLoadAtlas);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetAtlasFrame);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteFree);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetModulation_c);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetModulation_ca);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetModulation_rgb);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetModulation_rgba);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetModulationAlpha);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetModulationAlpha_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteDraw_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteDrawSized_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteDrawScaled_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteDrawAngled_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteDrawFlipped_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteDrawGeneral_f);
}

#endif
