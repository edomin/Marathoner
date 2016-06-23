#ifndef MTR_TEXTURE_SDL_GPU
#define MTR_TEXTURE_SDL_GPU

#define MTR_PLUGIN
#include "marathoner.h"

#include "sdl_gpu/SDL_gpu.h"

typedef struct mtrTexture_t {
    GPU_Image *texture;
    char *name;
} mtrTexture_t;

mtrIndexkeeper_t *mtrTextureKeeper;

#endif
