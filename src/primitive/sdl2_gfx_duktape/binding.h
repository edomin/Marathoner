#ifndef MTR_PRIMITIVE_SDL2_GFX_DUKTAPE_H
#define MTR_PRIMITIVE_SDL2_GFX_DUKTAPE_H

#include "duktape.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "Primitive_SDL2_gfx"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Primitive_SDL2_gfx_DuktapeRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
