#ifndef MTR_ABSTRACTION_ANIMATED_SPRITE_H
#define MTR_ABSTRACTION_ANIMATED_SPRITE_H

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faAnimatedSprite
#endif
#include "fa/Abstraction_animated_sprite.h"

typedef struct mtrAnimatedSprite_t {
    float    animSpeed;
    float    currentFrame;
    float    hscale;
    float    vscale;
    int      framesCount;
    uint32_t spriteIndex;
} mtrAnimatedSprite_t;

mtrIndexkeeper_t *mtrAnimatedSpriteKeeper;
static bool mtrAnimatedSpriteInited = false;
#define MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrAnimatedSpriteInited)                            \
        return returnValue;
#define MTR_ANIMATED_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrAnimatedSpriteInited)                                              \
    {                                                                          \
        MTR_LogWrite(                                                          \
         message ". Animated Sprite abstraction are not initialized",          \
         1, MTR_LMT_ERROR);                                                    \
        return returnValue;                                                    \
    }

MTR_FUNC(void, MTR_SpriteFree, uint32_t);
MTR_FUNC(int, MTR_SpriteGetFramesCount, uint32_t);
MTR_FUNC(void, MTR_SpriteDrawScaled_f, uint32_t, int, float, float, float,
 float);
MTR_FUNC(void, MTR_SpriteDrawGeneral_f, uint32_t, int, float, float, float,
 float, float, int);

#endif
