#ifndef MTR_PRIMITIVE_SDL2_H
#define MTR_PRIMITIVE_SDL2_H

#include "SDL2/SDL.h"

#include "fa/Primitive_SDL2.h"
#include "marathoner/plugin.h"

#define MTR_ARC_SEGMENTS_COUNT 32
#define MTR_PI_180_F 0.01745329f

typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */
float mtrLinePointX_f;
float mtrLinePointY_f;
bool  mtrLineDrawing;

typedef mtrScreen_t *(MTR_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

MTR_EXPORT void MTR_CALL mtrPrimitiveLineBegin_f(float, float);
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_rgb_f(float, float, uint8_t,
 uint8_t, uint8_t);
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_rgba_f(float, float, uint8_t,
 uint8_t, uint8_t, uint8_t);
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_c_f(float, float, uint32_t);
MTR_EXPORT void MTR_CALL mtrPrimitiveLineTo_ca_f(float, float, uint32_t);
MTR_EXPORT void MTR_CALL mtrPrimitiveLineEnd(void);

#endif

