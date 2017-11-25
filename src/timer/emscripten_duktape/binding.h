#ifndef MTR_TIMER_EMSCRIPTEN_DUKTAPE_H
#define MTR_TIMER_EMSCRIPTEN_DUKTAPE_H

#include "duktape.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "Timer_Emscripten"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Timer_Emscripten_DuktapeRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
