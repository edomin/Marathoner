#ifndef MTR_KEYBOARD_SDL2_SQUIRREL_H
#define MTR_KEYBOARD_SDL2_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "Keyboard_SDL2"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Keyboard_SDL2_SquirrelRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
