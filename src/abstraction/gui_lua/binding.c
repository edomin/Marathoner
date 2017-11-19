#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif

#include "../gui_binding_common.c"

MTR_BINDING_COMMON_CODE(Abstraction_gui_Lua, MTR_VERSION_ABSTRACTION_GUI_LUA,
 "Abstraction_gui")
