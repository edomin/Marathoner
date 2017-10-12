#ifndef MTR_PRIMITIVE_SDL2_GFX_H
#define MTR_PRIMITIVE_SDL2_GFX_H

#include "SDL2/SDL.h"
#include "SDL2/SDL2_gfxPrimitives.h"

#include "fa/Primitive_SDL2_gfx.h"
#include "marathoner/plugin.h"

//#define MTR_ARC_SEGMENTS_COUNT 64
//#define MTR_PI_180_F 0.01745329f

typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

mtrScreen_t *mtrScreen; /* this will imported from screen plugin */
float        mtrLinePointX_f;
float        mtrLinePointY_f;
bool         mtrLineDrawing;
int          screenWidth;
int          screenHeight;
static bool  mtrPrimitiveInited = false;
#define MTR_PRIMITIVE_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrPrimitiveInited)                           \
        return returnValue;
#define MTR_PRIMITIVE_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrPrimitiveInited)                                             \
    {                                                                    \
        mtrLogWrite(                                                     \
         message ". Primitive drawing subsystem are not initialized", 1, \
         MTR_LMT_ERROR);                                                 \
        return returnValue;                                              \
    }

typedef mtrScreen_t *(MTR_CALL * mtrGetScreenFunc)(void);
mtrGetScreenFunc mtrGetScreen;

#endif
