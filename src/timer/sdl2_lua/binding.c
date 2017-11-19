#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Timer_SDL2_Lua, MTR_VERSION_TIMER_SDL2_LUA,
 "Timer_SDL2")
