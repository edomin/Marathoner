#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Screen_SDL2_Squirrel, MTR_VERSION_SCREEN_SDL2_SQUIRREL,
 "Screen_SDL2")
