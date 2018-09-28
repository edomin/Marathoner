#ifndef MTR_AUDIO_PORTAUDIO_DUKTAPE_H
#define MTR_AUDIO_PORTAUDIO_DUKTAPE_H

#include "duktape.h"

#include "marathoner/plugin.h"
#include "../common.h"

#define MTR_SOURCE_MODULE "Audio_PortAudio"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_Audio_PortAudio_DuktapeRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
