#ifndef MTR_SCREEN_SDL2_GPU_H
#define MTR_SCREEN_SDL2_GPU_H

#ifdef __MINGW64__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wswitch-default"
#endif
#include "SDL2/SDL.h"
#include "SDL2/SDL_gpu.h"
#ifdef __MINGW64__
    #pragma GCC diagnostic pop
#endif

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faScreen
#endif
#include "fa/Screen_SDL2_gpu.h"

typedef struct mtrScreen_t {
    GPU_Target* screen;
    GPU_Target* target;
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
