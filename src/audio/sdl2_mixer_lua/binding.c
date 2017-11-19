#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Audio_SDL2_mixer_Lua,
 MTR_VERSION_AUDIO_SDL2_MIXER_LUA, "Audio_SDL2_mixer")
