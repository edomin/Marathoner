#ifndef MTR_MOUSE_SDL2_H
#define MTR_MOUSE_SDL2_H

#ifdef __MINGW64__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wswitch-default"
#endif
#include "SDL2/SDL.h"
#ifdef __MINGW64__
    #pragma GCC diagnostic pop
#endif

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faMouse
#endif
#include "fa/Mouse_SDL2.h"

typedef struct mtrMouse_t{
    int  currentMousestate[5];
    int  previousMousestate[5];
    int  x;
    int  y;
    int  deltaX;
    int  deltaY;
    bool mouseMotion;
    int  relativeWheel;
} mtrMouse_t;

mtrMouse_t mtrMouse;
static bool mtrMouseInited = false;
#define MTR_MOUSE_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrMouseInited)                           \
        return returnValue;
#define MTR_MOUSE_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrMouseInited)                                             \
    {                                                                \
        MTR_LogWrite(message ". Mouse support are not initialized",  \
         1, MTR_LMT_ERROR);                                          \
        return returnValue;                                          \
    }

#endif
