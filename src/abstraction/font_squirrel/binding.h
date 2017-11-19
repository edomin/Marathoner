#ifndef MTR_ABSTRACTION_FONT_SQUIRREL_H
#define MTR_ABSTRACTION_FONT_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Abstraction_font_SquirrelRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../font_binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
