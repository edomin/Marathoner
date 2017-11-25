#ifndef MTR_TIMER_EMSCRIPTEN_H
#define MTR_TIMER_EMSCRIPTEN_H

#include <string.h>
#include <emscripten.h>

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faTimer
#endif
#include "fa/Timer_Emscripten.h"

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
