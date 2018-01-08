#ifndef MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C
#define MTR_ABSTRACTION_SPRITE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_SpriteFunctionSupported,
 MTR_SpriteFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_SpriteInit, MTR_SpriteInit)
MTR_SCRIPT_FUNC_U32t_S1I7(MTR_SF_SpriteLoad, MTR_SpriteLoad)
MTR_SCRIPT_FUNC_U32t_S1I2(MTR_SF_SpriteLoadSimple, MTR_SpriteLoadSimple)
MTR_SCRIPT_FUNC_U32t_S1I1(MTR_SF_SpriteLoadAtlas, MTR_SpriteLoadAtlas)
MTR_SCRIPT_FUNC_U32t_S1U32t1I1(MTR_SF_SpriteCreateFromTexture,
 MTR_SpriteCreateFromTexture)
MTR_SCRIPT_FUNC_B_U32t1I7(MTR_SF_SpriteSetAtlasFrame, MTR_SpriteSetAtlasFrame)
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_SpriteGetFramesCount, MTR_SpriteGetFramesCount)
MTR_SCRIPT_FUNC_V_U32t1I2(MTR_SF_SpriteSetFrameAnchorY,
 MTR_SpriteSetFrameAnchorY)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_SpriteGetFrameSizes)
{
    uint32_t sprNum;
    int      frame;
    int      width;
    int      height;
    MTR_SF_GET_UINT32(sprNum, 1);
    MTR_SF_GET_INT(frame, 2);
    MTR_SpriteGetFrameSizes(sprNum, frame, &width, &height);
    MTR_SF_PUSH_INT(width);
    MTR_SF_PUSH_INT(height);
    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_U32t1I1(MTR_SF_SpriteGetFrameWidth, MTR_SpriteGetFrameWidth)
MTR_SCRIPT_FUNC_I_U32t1I1(MTR_SF_SpriteGetFrameHeight, MTR_SpriteGetFrameHeight)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_SpriteGetFrameCoords)
{
    uint32_t sprNum;
    int      frame;
    int      x;
    int      y;
    MTR_SF_GET_UINT32(sprNum, 1);
    MTR_SF_GET_INT(frame, 2);
    MTR_SpriteGetFrameCoords(sprNum, frame, &x, &y);
    MTR_SF_PUSH_INT(x);
    MTR_SF_PUSH_INT(y);
    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_U32t1I1(MTR_SF_SpriteGetFrameX, MTR_SpriteGetFrameX)
MTR_SCRIPT_FUNC_I_U32t1I1(MTR_SF_SpriteGetFrameY, MTR_SpriteGetFrameY)

#ifdef lua_h
MTR_SCRIPT_FUNC(MTR_SF_SpriteGetFrameAnchors)
{
    uint32_t sprNum;
    int      frame;
    int      anchorX;
    int      anchorY;
    MTR_SF_GET_UINT32(sprNum, 1);
    MTR_SF_GET_INT(frame, 2);
    MTR_SpriteGetFrameAnchors(sprNum, frame, &anchorX, &anchorY);
    MTR_SF_PUSH_INT(anchorX);
    MTR_SF_PUSH_INT(anchorY);
    return 2;
}
#endif

MTR_SCRIPT_FUNC_I_U32t1I1(MTR_SF_SpriteGetFrameAnchorX,
 MTR_SpriteGetFrameAnchorX)
MTR_SCRIPT_FUNC_I_U32t1I1(MTR_SF_SpriteGetFrameAnchorY,
 MTR_SpriteGetFrameAnchorY)
MTR_SCRIPT_FUNC_U32t_U32t1(MTR_SF_SpriteGetTexture, MTR_SpriteGetTexture)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_SpriteFree, MTR_SpriteFree)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_SpriteDetachTexture, MTR_SpriteDetachTexture)
MTR_SCRIPT_FUNC_V_U32t2(MTR_SF_SpriteSetModulation_c, MTR_SpriteSetModulation_c)
MTR_SCRIPT_FUNC_V_U32t2(MTR_SF_SpriteSetModulation_ca,
 MTR_SpriteSetModulation_ca)
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
MTR_SCRIPT_FUNC_V_U32t1I1F2I1(MTR_SF_SpriteDrawFlipped_f,
 MTR_SpriteDrawFlipped_f)
MTR_SCRIPT_FUNC_V_U32t1I1F5I1(MTR_SF_SpriteDrawGeneral_f,
 MTR_SpriteDrawGeneral_f)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteInit);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteLoad);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteLoadSimple);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteLoadAtlas);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteCreateFromTexture);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetAtlasFrame);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFramesCount);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteSetFrameAnchorY);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameSizes);
    #endif
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameWidth);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameHeight);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameCoords);
    #endif
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameX);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameY);
    #ifdef lua_h
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameAnchors);
    #endif
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameAnchorX);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetFrameAnchorY);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteGetTexture);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteFree);
    MTR_FIND_AND_ADD_FUNCTION("Abstraction_sprite", SpriteDetachTexture);
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
