#ifndef MTR_UTILS_COLOR_SQUIRREL_H
#define MTR_UTILS_COLOR_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../color_common.h"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Utils_color_SquirrelRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../color_binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
