#ifndef MTR_PRIMITIVE_SDL2
#define MTR_PRIMITIVE_SDL2

#include "SDL2/SDL.h"

#include "marathoner/plugin.h"

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

