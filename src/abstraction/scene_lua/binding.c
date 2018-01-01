#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../scene_binding_common.c"

MTR_BINDING_COMMON_CODE(Abstraction_scene_Lua,
 MTR_VERSION_ABSTRACTION_SCENE_LUA, "Abstraction_scene")
