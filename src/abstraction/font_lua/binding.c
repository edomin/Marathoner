#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../font_binding_common.c"

MTR_BINDING_COMMON_CODE(Abstraction_font_Lua, MTR_VERSION_ABSTRACTION_FONT_LUA,
 "Abstraction_font")
