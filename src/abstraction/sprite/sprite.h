#ifndef MTR_ABSTRACTION_SPRITE_H
#define MTR_ABSTRACTION_SPRITE_H

#include "marathoner/plugin.h"

#include <math.h>

typedef struct mtrClip_t {
    int x;
    int y;
    int w;
    int h;
} mtrClip_t;

typedef struct mtrSprite_t {
    uint32_t   textureIndex;
    int        clipWidth;
    int        clipHeight;
    int        rowsCount;
    int        colsCount;
    int        clipsCount;
    mtrClip_t *clip;
    int        anchorX;
    int        anchorY;
    char      *name;
} mtrSprite_t;

char mtrDefaultSpriteName[] = "Unnamed_Sprite";

mtrIndexkeeper_t *mtrSpriteKeeper;

typedef uint32_t (MTR_CALL * mtrTextureLoadFunc)(const char *);
mtrTextureLoadFunc mtrTextureLoad;

typedef void (MTR_CALL * mtrTextureFreeFunc)(uint32_t);
mtrTextureFreeFunc mtrTextureFree;

typedef void (MTR_CALL * mtrTextureGetSizesFunc)(uint32_t, int *, int *);
mtrTextureGetSizesFunc mtrTextureGetSizes;

typedef void (MTR_CALL * mtrTextureBlitRegion_fFunc)(uint32_t, float, float,
 float, float, float, float);
mtrTextureBlitRegion_fFunc mtrTextureBlitRegion_f;

typedef void (MTR_CALL * mtrTextureBlitRegionScaled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float);
mtrTextureBlitRegionScaled_fFunc mtrTextureBlitRegionScaled_f;

typedef void (MTR_CALL * mtrTextureBlitRegionAngled_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float);
mtrTextureBlitRegionAngled_fFunc mtrTextureBlitRegionAngled_f;

typedef void (MTR_CALL * mtrTextureBlitRegionFlipped_fFunc)(uint32_t, float,
 float, float, float, float, float, int);
mtrTextureBlitRegionFlipped_fFunc mtrTextureBlitRegionFlipped_f;

typedef void (MTR_CALL * mtrTextureBlitRegionGeneral_fFunc)(uint32_t, float,
 float, float, float, float, float, float, float, float, float, float, int);
mtrTextureBlitRegionGeneral_fFunc mtrTextureBlitRegionGeneral_f;

#endif
