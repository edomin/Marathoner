#ifndef MTR_TEXTURE_SDL_GPU
#define MTR_TEXTURE_SDL_GPU

#define MTR_PLUGIN
#include "marathoner.h"

#include "sdl_gpu/SDL_gpu.h"

typedef struct mtrTexture_t {
    GPU_Image texture;
    const char *name;
} mtrTexture_t;

mtrTexture_t *mtrTexture;
uint16_t reservedTextures;
uint16_t texturesCount;
uint32_t texturesMap[2048]; /* bit array */

#endif
