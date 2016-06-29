#ifndef MTR_TEXTURE_SDL_GPU
#define MTR_TEXTURE_SDL_GPU

#define MTR_PLUGIN
#include "marathoner.h"

#include "sdl_gpu/SDL_gpu.h"
#include "SDL2/SDL.h"

#define MTR_FLIP_NONE                   GPU_FLIP_NONE
#define MTR_FLIP_HORIZONTAL             GPU_FLIP_HORIZONTAL
#define MTR_FLIP_VERTICAL               GPU_FLIP_VERTICAL
#define MTR_FLIP_BOTH                   (GPU_FLIP_HORIZONTAL | GPU_FLIP_VERTICAL)

#define MTR_BLEND_ZERO                  GPU_FUNC_ZERO
#define MTR_BLEND_ONE                   GPU_FUNC_ONE
#define MTR_BLEND_SRC_COLOR             GPU_FUNC_SRC_COLOR
#define MTR_BLEND_DST_COLOR             GPU_FUNC_DST_COLOR
#define MTR_BLEND_ONE_MINUS_SRC         GPU_FUNC_ONE_MINUS_SRC
#define MTR_BLEND_ONE_MINUS_DST         GPU_FUNC_ONE_MINUS_DST
#define MTR_BLEND_SRC_ALPHA             GPU_FUNC_SRC_ALPHA
#define MTR_BLEND_DST_ALPHA             GPU_FUNC_DST_ALPHA
#define MTR_BLEND_ONE_MINUS_SRC_ALPHA   GPU_FUNC_ONE_MINUS_SRC_ALPHA
#define MTR_BLEND_ONE_MINUS_DST_ALPHA   GPU_FUNC_ONE_MINUS_DST_ALPHA

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
