#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(TTF_SDL2_ttf_Duktape, MTR_VERSION_TTF_SDL2_TTF_DUKTAPE,
 "TTF_SDL2_ttf")
