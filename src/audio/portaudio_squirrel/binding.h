#ifndef MTR_AUDIO_PORTAUDIO_SQUIRREL_H
#define MTR_AUDIO_PORTAUDIO_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"
#include "../common.h"

#define MTR_SOURCE_MODULE "Audio_PortAudio"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Audio_PortAudio_SquirrelRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
