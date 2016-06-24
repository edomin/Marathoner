#ifndef MTR_TEXTURE_SDL_GPU
#define MTR_TEXTURE_SDL_GPU

#define MTR_PLUGIN
#include "marathoner.h"

#include "sdl_gpu/SDL_gpu.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
} mtrScreen_t;

typedef struct mtrTexture_t {
    GPU_Image *texture;
    char *name;
} mtrTexture_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */
mtrIndexkeeper_t *mtrTextureKeeper;

typedef mtrScreen_t *(__stdcall * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif
