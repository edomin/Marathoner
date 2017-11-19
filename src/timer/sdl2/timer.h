#ifndef MTR_TIMER_SDL2_H
#define MTR_TIMER_SDL2_H

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
    #define fa faTimer
#endif
#include "fa/Timer_SDL2.h"

typedef struct mtrTimer_t{
    uint32_t startTime;
} mtrTimer_t;

mtrTimer_t  mtrTimer;
static bool mtrTimerInited = false;
#define MTR_TIMER_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrTimerInited)                           \
        return returnValue;
#define MTR_TIMER_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue)  \
    if (!mtrTimerInited)                                              \
    {                                                                 \
        MTR_LogWrite(message ". Timer subsystem are not initialized", \
         1, MTR_LMT_ERROR);                                           \
        return returnValue;                                           \
    }

#endif
