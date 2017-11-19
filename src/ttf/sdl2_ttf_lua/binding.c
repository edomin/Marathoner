#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(TTF_SDL2_ttf_Lua, MTR_VERSION_TTF_SDL2_TTF_LUA,
 "TTF_SDL2_ttf")
