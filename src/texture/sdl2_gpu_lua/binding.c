#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Texture_SDL2_gpu_Lua,
 MTR_VERSION_TEXTURE_SDL2_GPU_LUA, "Texture_SDL2_gpu")
