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
MTR_SCRIPT_FUNC_V_U32t1I1F4(mtrSF_SpriteDrawScaled_f, mtrSpriteDrawScaled_f)
MTR_SCRIPT_FUNC_V_U32t1I1F3(mtrSF_SpriteDrawAngled_f, mtrSpriteDrawAngled_f)
MTR_SCRIPT_FUNC_V_U32t1I1F2I1(mtrSF_SpriteDrawFlipped_f, mtrSpriteDrawFlipped_f)
MTR_SCRIPT_FUNC_V_U32t1I1F5I1(mtrSF_SpriteDrawGeneral_f, mtrSpriteDrawGeneral_f)

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrSpriteFunctionSupported, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteInit, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteLoad, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteLoadSimple, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteFree, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteSetModulation_c, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteSetModulation_ca, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteSetModulation_rgb, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteSetModulation_rgba, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteSetModulationAlpha, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteSetModulationAlpha_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDraw_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDrawScaled_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDrawAngled_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDrawFlipped_f, "Abstraction_sprite");
    MTR_FIND_FUNCTION(mtrSpriteDrawGeneral_f, "Abstraction_sprite");

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_SpriteFunctionSupported,
         "SpriteFunctionSupported");
        mtrScriptsRegisterFunction(mtrSF_SpriteInit, "SpriteInit");
        mtrScriptsRegisterFunction(mtrSF_SpriteLoad, "SpriteLoad");
        mtrScriptsRegisterFunction(mtrSF_SpriteLoadSimple, "SpriteLoadSimple");
        mtrScriptsRegisterFunction(mtrSF_SpriteFree, "SpriteFree");
        mtrScriptsRegisterFunction(mtrSF_SpriteSetModulation_c,
         "SetModulation_c");
        mtrScriptsRegisterFunction(mtrSF_SpriteSetModulation_ca,
         "SetModulation_ca");
        mtrScriptsRegisterFunction(mtrSF_SpriteSetModulation_rgb,
         "SetModulation_rgb");
        mtrScriptsRegisterFunction(mtrSF_SpriteSetModulation_rgba,
         "SetModulation_rgba");
        mtrScriptsRegisterFunction(mtrSF_SpriteSetModulationAlpha,
         "SetModulationAlpha");
        mtrScriptsRegisterFunction(mtrSF_SpriteSetModulationAlpha_f,
         "SetModulationAlpha_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDraw_f, "SpriteDraw_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDrawScaled_f,
         "SpriteDrawScaled_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDrawAngled_f,
         "SpriteDrawAngled_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDrawFlipped_f,
         "SpriteDrawFlipped_f");
        mtrScriptsRegisterFunction(mtrSF_SpriteDrawGeneral_f,
         "SpriteDrawGeneral_f");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
