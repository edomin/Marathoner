#ifndef MTR_ABSTRACTION_FONT_DUKTAPE_H
#define MTR_ABSTRACTION_FONT_DUKTAPE_H

#include "duktape.h"

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Abstraction_font_DuktapeRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../font_binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
