#ifndef MTR_ABSTRACTION_ANIMATED_SPRITE_BINDING_COMMON_C
#define MTR_ABSTRACTION_ANIMATED_SPRITE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_AnimatedSpriteFunctionSupported,
 MTR_AnimatedSpriteFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_AnimatedSpriteInit, MTR_AnimatedSpriteInit)
MTR_SCRIPT_FUNC_U32t_U32t1F4(MTR_SF_AnimatedSpriteCreateFromSprite,
 MTR_AnimatedSpriteCreateFromSprite)
MTR_SCRIPT_FUNC_U32t_V(MTR_SF_AnimatedSpriteCreate, MTR_AnimatedSpriteCreate)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_AnimatedSpriteSetSprite,
 MTR_AnimatedSpriteSetSprite)
MTR_SCRIPT_FUNC_B_U32t1F1(MTR_SF_AnimatedSpriteSetAnimSpeed,
 MTR_AnimatedSpriteSetAnimSpeed)
MTR_SCRIPT_FUNC_B_U32t1F2(MTR_SF_AnimatedSpriteSetScale,
 MTR_AnimatedSpriteSetScale)
MTR_SCRIPT_FUNC_B_U32t1F1(MTR_SF_AnimatedSpriteSetCurrentFrame,
 MTR_AnimatedSpriteSetCurrentFrame)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_AnimatedSpriteFree, MTR_AnimatedSpriteFree)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_AnimatedSpriteDetachSprite,
 MTR_AnimatedSpriteDetachSprite)
MTR_SCRIPT_FUNC_V_U32t1F2(MTR_SF_AnimatedSpriteDraw_f, MTR_AnimatedSpriteDraw_f)
MTR_SCRIPT_FUNC_V_U32t1F3(MTR_SF_AnimatedSpriteDrawAngled_f,
 MTR_AnimatedSpriteDrawAngled_f)
MTR_SCRIPT_FUNC_V_U32t1F2I1(MTR_SF_AnimatedSpriteDrawFlipped_f,
 MTR_AnimatedSpriteDrawFlipped_f)
MTR_SCRIPT_FUNC_V_U32t1F3I1(MTR_SF_AnimatedSpriteDrawGeneral_f,
 MTR_AnimatedSpriteDrawGeneral_f)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_AnimatedSpriteUpdate_f,
 MTR_AnimatedSpriteUpdate_f)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteInit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteCreateFromSprite);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteCreate);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteSetSprite);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteSetAnimSpeed);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteSetScale);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteSetCurrentFrame);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteFree);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteDetachSprite);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteDraw_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteDrawAngled_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteDrawFlipped_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteDrawGeneral_f);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_animated_sprite",
     AnimatedSpriteUpdate_f);
}

#endif
