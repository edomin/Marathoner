#ifndef MTR_SCREEN_SDL2_H
#define MTR_SCREEN_SDL2_H

#ifdef __MINGW64__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wswitch-default"
#endif
#include "SDL2/SDL.h"
#ifdef __MINGW64__
    #pragma GCC diagnostic pop
#endif

#include "fa/Screen_SDL2.h"
#include "marathoner/plugin.h"

typedef struct mtrScreen_t {
    SDL_Window   *screen;
    SDL_Renderer *renderer;
} mtrScreen_t;

mtrScreen_t *mtrScreen;
static bool  mtrScreenInited = false;
#define MTR_SCREEN_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrScreenInited)                           \
        return returnValue;
#define MTR_SCREEN_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrScreenInited)                                             \
    {                                                                 \
        MTR_LogWrite(message ". Screen are not initialized",          \
         1, MTR_LMT_ERROR);                                           \
        return returnValue;                                           \
    }

#endif

