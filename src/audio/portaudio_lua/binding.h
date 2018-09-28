#ifndef MTR_AUDIO_PORTAUDIO_LUA_H
#define MTR_AUDIO_PORTAUDIO_LUA_H

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"
#include "../common.h"

#define MTR_SOURCE_MODULE "Audio_PortAudio"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Audio_PortAudio_LuaRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
