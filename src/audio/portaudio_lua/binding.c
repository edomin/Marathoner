#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Audio_PortAudio_Lua, MTR_VERSION_AUDIO_PORTAUDIO_LUA,
 "Audio_PortAudio")
