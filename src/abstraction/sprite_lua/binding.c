#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../sprite_binding_common.c"

MTR_BINDING_COMMON_CODE(Abstraction_sprite_Lua,
 MTR_VERSION_ABSTRACTION_SPRITE_LUA, "Abstraction_sprite")
