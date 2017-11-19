#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../color_binding_common.c"

MTR_BINDING_COMMON_CODE(Utils_color_Lua, MTR_VERSION_UTILS_COLOR_LUA,
 "Utils_color")
