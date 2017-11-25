#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Timer_Emscripten_Lua, MTR_VERSION_TIMER_EMSCRIPTEN_LUA,
 "Timer_Emscripten")
