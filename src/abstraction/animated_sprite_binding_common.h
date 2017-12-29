#ifndef MTR_ABSTRACTION_ANIMATED_SPRITE_BINDING_COMMON_H
#define MTR_ABSTRACTION_ANIMATED_SPRITE_BINDING_COMMON_H

MTR_FUNC(int, MTR_AnimatedSpriteFunctionSupported, const char *);
MTR_FUNC(bool, MTR_AnimatedSpriteInit, uint32_t, uint32_t);
MTR_FUNC(uint32_t, MTR_AnimatedSpriteCreateFromSprite, uint32_t, float, float,
 float, float);
MTR_FUNC(uint32_t, MTR_AnimatedSpriteCreate, void);
MTR_FUNC(bool, MTR_AnimatedSpriteSetSprite, uint32_t, uint32_t);
MTR_FUNC(bool, MTR_AnimatedSpriteSetAnimSpeed, uint32_t, float);
MTR_FUNC(bool, MTR_AnimatedSpriteSetScale, uint32_t, float, float);
MTR_FUNC(bool, MTR_AnimatedSpriteSetCurrentFrame, uint32_t, float);
MTR_FUNC(void, MTR_AnimatedSpriteFree, uint32_t);
MTR_FUNC(void, MTR_AnimatedSpriteDetachSprite, uint32_t);
MTR_FUNC(void, MTR_AnimatedSpriteDraw_f, uint32_t, float, float);
MTR_FUNC(void, MTR_AnimatedSpriteDrawAngled_f, uint32_t, float, float, float);
MTR_FUNC(void, MTR_AnimatedSpriteDrawFlipped_f, uint32_t, float, float, int);
MTR_FUNC(void, MTR_AnimatedSpriteDrawGeneral_f, uint32_t, float, float, float,
 int);
MTR_FUNC(void, MTR_AnimatedSpriteUpdate_f, uint32_t);

#endif
