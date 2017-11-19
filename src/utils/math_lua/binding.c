#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../math_binding_common.c"

MTR_BINDING_COMMON_CODE(Utils_math_Lua, MTR_VERSION_UTILS_MATH_LUA,
 "Utils_math")
