#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Game_Controller_SDL2_Duktape,
 MTR_VERSION_GAME_CONTROLLER_SDL2_DUKTAPE, "Game_Controller_SDL2")
