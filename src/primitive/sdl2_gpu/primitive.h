#ifndef MTR_PRIMITIVE_SDL2_GPU_H
#define MTR_PRIMITIVE_SDL2_GPU_H

#include "SDL2/SDL_gpu.h"

#include "fa/Primitive_SDL2_gpu.h"
#include "marathoner/plugin.h"

#define MTR_RGB_TO_SDL_COLOR(sdl_color, ar, ag, ab) \
    sdl_color.r = ar;                               \
    sdl_color.g = ag;                               \
    sdl_color.b = ab;                               \
    sdl_color.a = 0xFF;

#define MTR_RGBA_TO_SDL_COLOR(sdl_color, ar, ag, ab, aa)    \
    sdl_color.r = ar;                                       \
    sdl_color.g = ag;                                       \
    sdl_color.b = ab;                                       \
    sdl_color.a = aa;

#define MTR_COLOR24_TO_SDL_COLOR(sdl_color, color)                          \
    sdl_color.r = (uint8_t)(color >> 16);                                   \
    sdl_color.g = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 8));   \
    sdl_color.b = (uint8_t)(color - ((uint32_t)sdl_color.r << 16) -         \
     ((uint32_t)sdl_color.g << 8));                                         \
    sdl_color.a = 0xFF;

#define MTR_COLOR32_TO_SDL_COLOR(sdl_color, color)                          \
    sdl_color.r = (uint8_t)(color >> 24);                                   \
    sdl_color.g = (uint8_t)((color >> 16) - ((uint32_t)sdl_color.r << 8));  \
    sdl_color.b = (uint8_t)((color >> 8) - ((uint32_t)sdl_color.r << 16) -  \
     ((uint32_t)sdl_color.g << 8));                                         \
    sdl_color.a = (uint8_t)(color - ((uint32_t)sdl_color.r << 24) -         \
     ((uint32_t)sdl_color.g << 16) - ((uint32_t)sdl_color.b << 8));


typedef struct mtrScreen_t {
    GPU_Target* screen;
    GPU_Target* target;
} mtrScreen_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */
float mtrLinePointX_f;
float mtrLinePointY_f;
bool  mtrLineDrawing;

typedef mtrScreen_t *(MTR_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif
