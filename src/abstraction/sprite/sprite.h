#ifndef MTR_ABSTRACTION_SPRITE_H
#define MTR_ABSTRACTION_SPRITE_H

#include "fa/Abstraction_sprite.h"
#include "marathoner/plugin.h"

#include <math.h>

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

typedef uint32_t (MTR_CALL * MTR_TextureLoadFunc)(const char *);
MTR_TextureLoadFunc MTR_TextureLoad;

typedef void (MTR_CALL * MTR_TextureFreeFunc)(uint32_t);
MTR_TextureFreeFunc MTR_TextureFree;

typedef void (MTR_CALL * MTR_TextureGetSizesFunc)(uint32_t, int *, int *);
MTR_TextureGetSizesFunc MTR_TextureGetSizes;

typedef void (MTR_CALL * MTR_TextureSetModulation_cFunc)(uint32_t, uint32_t);
MTR_TextureSetModulation_cFunc MTR_TextureSetModulation_c;

typedef void (MTR_CALL * MTR_TextureSetModulation_caFunc)(uint32_t, uint32_t);
MTR_TextureSetModulation_caFunc MTR_TextureSetModulation_ca;

typedef void (MTR_CALL * MTR_TextureSetModulation_rgbFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t);
MTR_TextureSetModulation_rgbFunc MTR_TextureSetModulation_rgb;

typedef void (MTR_CALL * MTR_TextureSetModulation_rgbaFunc)(uint32_t, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_TextureSetModulation_rgbaFunc MTR_TextureSetModulation_rgba;

typedef void (MTR_CALL * MTR_TextureSetModulationAlphaFunc)(uint32_t, uint8_t);
MTR_TextureSetModulationAlphaFunc MTR_TextureSetModulationAlpha;

typedef void (MTR_CALL * MTR_TextureSetModulationAlpha_fFunc)(uint32_t, float);
MTR_TextureSetModulationAlpha_fFunc MTR_TextureSetModulationAlpha_f;

typedef void (MTR_CALL * MTR_TextureBlitRegion_fFunc)(uint32_t, float, float,
 float, float, float, float);
MTR_TextureBlitRegion_fFunc MTR_TextureBlitRegion_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionSized_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float);
MTR_TextureBlitRegionSized_fFunc MTR_TextureBlitRegionSized_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionScaled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float);
MTR_TextureBlitRegionScaled_fFunc MTR_TextureBlitRegionScaled_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionAngled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float);
MTR_TextureBlitRegionAngled_fFunc MTR_TextureBlitRegionAngled_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionFlipped_fFunc)(uint32_t, float,
 float, float, float, float, float, int);
MTR_TextureBlitRegionFlipped_fFunc MTR_TextureBlitRegionFlipped_f;

typedef void (MTR_CALL * MTR_TextureBlitRegionGeneral_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float, float, float, int);
MTR_TextureBlitRegionGeneral_fFunc MTR_TextureBlitRegionGeneral_f;

#endif
