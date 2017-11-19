#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Game_Controller_SDL2_Squirrel,
 MTR_VERSION_GAME_CONTROLLER_SDL2_SQUIRREL, "Game_Controller_SDL2")
