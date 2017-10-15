#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_SpriteFunctionSupported, mtrSpriteFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(mtrSF_SpriteInit, mtrSpriteInit)
MTR_SCRIPT_FUNC_U32t_S1I7(mtrSF_SpriteLoad, mtrSpriteLoad)
MTR_SCRIPT_FUNC_U32t_S1I2(mtrSF_SpriteLoadSimple, mtrSpriteLoadSimple)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_SpriteFree, mtrSpriteFree)
MTR_SCRIPT_FUNC_V_U32t2(mtrSF_SpriteSetModulation_c, mtrSpriteSetModulation_c)
MTR_SCRIPT_FUNC_V_U32t2(mtrSF_SpriteSetModulation_ca, mtrSpriteSetModulation_ca)
MTR_SCRIPT_FUNC_V_U32t1U8t3(mtrSF_SpriteSetModulation_rgb,
 mtrSpriteSetModulation_rgb)
MTR_SCRIPT_FUNC_V_U32t1U8t4(mtrSF_SpriteSetModulation_rgba,
 mtrSpriteSetModulation_rgba)
MTR_SCRIPT_FUNC_V_U32t1U8t1(mtrSF_SpriteSetModulationAlpha,
 mtrSpriteSetModulationAlpha)
MTR_SCRIPT_FUNC_V_U32t1F1(mtrSF_SpriteSetModulationAlpha_f,
 mtrSpriteSetModulationAlpha_f)
MTR_SCRIPT_FUNC_V_U32t1I1F2(mtrSF_SpriteDraw_f, mtrSpriteDraw_f)
MTR_SCRIPT_FUNC_V_U32t1I1F4(mtrSF_SpriteDrawSized_f, mtrSpriteDrawSized_f)
MTR_SCRIPT_FUNC_V_U32t1I1F4(mtrSF_SpriteDrawScaled_f, mtrSpriteDrawScaled_f)
MTR_SCRIPT_FUNC_V_U32t1I1F3(mtrSF_SpriteDrawAngled_f, mtrSpriteDrawAngled_f)
MTR_SCRIPT_FUNC_V_U32t1I1F2I1(mtrSF_SpriteDrawFlipped_f, mtrSpriteDrawFlipped_f)
MTR_SCRIPT_FUNC_V_U32t1I1F5I1(mtrSF_SpriteDrawGeneral_f, mtrSpriteDrawGeneral_f)

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteInit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteLoad);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteLoadSimple);
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
