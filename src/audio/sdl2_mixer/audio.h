#ifndef MTR_AUDIO_SDL2_MIXER_H
#define MTR_AUDIO_SDL2_MIXER_H

#ifdef __MINGW64__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wswitch-default"
#endif
#include "SDL2/SDL.h"
#ifdef __MINGW64__
    #pragma GCC diagnostic pop
#endif
#include "SDL2/SDL_mixer.h"

#include "marathoner/plugin.h"
#ifdef MTR_MOD_STATIC
    #define fa faAudio
#endif
#include "fa/Audio_SDL2_mixer.h"
#include "../common.h"

typedef struct mtrSound_t {
    Mix_Chunk *sound;
    char      *name;
} mtrSound_t;

typedef struct mtrMusic_t {
    Mix_Music *music;
    char      *name;
} mtrMusic_t;

char mtrDefaultSoundName[] = "Unnamed_Sound";
char mtrDefaultMusicName[] = "Unnamed_Music";
mtrIndexkeeper_t *mtrSoundKeeper;
mtrIndexkeeper_t *mtrMusicKeeper;
static bool mtrAudioInited = false;
#define MTR_AUDIO_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrAudioInited)                           \
        return returnValue;
#define MTR_AUDIO_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue) \
    if (!mtrAudioInited)                                              \
    {                                                                 \
        MTR_LogWrite(message ". Audio manager are not initialized",   \
         1, MTR_LMT_ERROR);                                           \
        return returnValue;                                           \
    }

#endif

