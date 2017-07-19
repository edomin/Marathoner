#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_B_U32t2(mtrSF_SpriteInit, mtrSpriteInit)
MTR_SCRIPT_FUNC_U32t_S1I7(mtrSF_SpriteLoad, mtrSpriteLoad)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_SpriteFree, mtrSpriteFree)
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
        mtrScriptsRegisterFunction(mtrSF_SpriteInit, "SpriteInit");
        mtrScriptsRegisterFunction(mtrSF_SpriteLoad, "SpriteLoad");
        mtrScriptsRegisterFunction(mtrSF_SpriteFree, "SpriteFree");
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
