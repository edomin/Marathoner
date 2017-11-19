#ifndef MTR_MOUSE_SDL2_DUKTAPE_H
#define MTR_MOUSE_SDL2_DUKTAPE_H

#include "duktape.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "Mouse_SDL2"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Mouse_SDL2_DuktapeRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
