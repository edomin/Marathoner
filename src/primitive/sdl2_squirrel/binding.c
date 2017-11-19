#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Primitive_SDL2_Squirrel,
 MTR_VERSION_PRIMITIVE_SDL2_SQUIRREL, "Primitive_SDL2")
