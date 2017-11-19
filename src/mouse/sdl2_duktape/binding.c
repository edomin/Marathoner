#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Mouse_SDL2_Duktape, MTR_VERSION_MOUSE_SDL2_DUKTAPE,
 "Mouse_SDL2")
