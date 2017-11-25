#ifndef MTR_ABSTRACTION_SPRITE_H
#define MTR_ABSTRACTION_SPRITE_H

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faSprite
#endif
#include "fa/Abstraction_sprite.h"

#include <math.h>
#include <string.h>

typedef struct mtrClip_t {
    int x;
    int y;
    int w;
    int h;
    int anchorX;
    int anchorY;
} mtrClip_t;

typedef struct mtrSprite_t {
    uint32_t   textureIndex;
    int        clipWidth;
    int        clipHeight;
    int        rowsCount;
    int        colsCount;
    int        clipsCount;
    mtrClip_t *clip;
    char      *name;
    bool       atlas;
} mtrSprite_t;

char mtrDefaultSpriteName[] = "Unnamed_Sprite";
mtrIndexkeeper_t *mtrSpriteKeeper;
static bool mtrSpriteInited = false;
#define MTR_SPRITE_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrSpriteInited)                           \
        return returnValue;
#define MTR_SPRITE_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrSpriteInited)                                             \
    {                                                                 \
        MTR_LogWrite(                                                 \
         message ". Sprite abstraction manager are not initialized",  \
         1, MTR_LMT_ERROR);                                           \
        return returnValue;                                           \
    }

MTR_FUNC(uint32_t, MTR_TextureLoad, const char *);
MTR_FUNC(void, MTR_TextureFree, uint32_t);
MTR_FUNC(void, MTR_TextureGetSizes, uint32_t, int *, int *);
MTR_FUNC(void, MTR_TextureSetModulation_c, uint32_t, uint32_t);
MTR_FUNC(void, MTR_TextureSetModulation_ca, uint32_t, uint32_t);
MTR_FUNC(void, MTR_TextureSetModulation_rgb, uint32_t, uint8_t, uint8_t,
 uint8_t);
MTR_FUNC(void, MTR_TextureSetModulation_rgba, uint32_t, uint8_t, uint8_t,
 uint8_t, uint8_t);
MTR_FUNC(void, MTR_TextureSetModulationAlpha, uint32_t, uint8_t);
MTR_FUNC(void, MTR_TextureSetModulationAlpha_f, uint32_t, float);
MTR_FUNC(void, MTR_TextureBlitRegion_f, uint32_t, float, float, float, float,
 float, float);
MTR_FUNC(void, MTR_TextureBlitRegionSized_f, uint32_t, float, float, float,
 float, float, float, float, float);
MTR_FUNC(void, MTR_TextureBlitRegionScaled_f, uint32_t, float, float, float,
 float, float, float, float, float);
MTR_FUNC(void, MTR_TextureBlitRegionAngled_f, uint32_t, float, float, float,
 float, float, float, float, float, float);
MTR_FUNC(void, MTR_TextureBlitRegionFlipped_f, uint32_t, float, float, float,
 float, float, float, int);
MTR_FUNC(void, MTR_TextureBlitRegionGeneral_f, uint32_t, float, float, float,
 float, float, float, float, float, float, float, float, int);

#endif
