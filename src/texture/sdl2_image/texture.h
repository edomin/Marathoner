#ifndef MTR_TEXTURE_SDL2_IMAGE
#define MTR_TEXTURE_SDL2_IMAGE

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "marathoner/plugin.h"

#define MTR_FLIP_NONE                   SDL_FLIP_NONE
#define MTR_FLIP_HORIZONTAL             SDL_FLIP_HORIZONTAL
#define MTR_FLIP_VERTICAL               SDL_FLIP_VERTICAL
#define MTR_FLIP_BOTH                   (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL)
/*
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
*/
typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

typedef struct mtrTexture_t {
    SDL_Texture *texture;
    char        *name;
} mtrTexture_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */
mtrIndexkeeper_t *mtrTextureKeeper;

typedef mtrScreen_t *(MRT_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif

