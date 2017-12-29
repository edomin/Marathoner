#ifndef MTR_ABSTRACTION_ANIMATED_SPRITE_SQUIRREL_H
#define MTR_ABSTRACTION_ANIMATED_SPRITE_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll \
     MTR_Abstraction_animated_sprite_SquirrelRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../animated_sprite_binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
