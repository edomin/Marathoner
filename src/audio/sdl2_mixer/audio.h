#ifndef MTR_AUDIO_SDL2_MIXER
#define MTR_AUDIO_SDL2_MIXER

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include "marathoner/plugin.h"

typedef struct mtrSound_t {
    Mix_Chunk *sound;
    char      *name;
} mtrSound_t;

typedef struct mtrMusic_t {
    Mix_Music *music;
    char      *name;
} mtrMusic_t;

mtrIndexkeeper_t *mtrSoundKeeper;
mtrIndexkeeper_t *mtrMusicKeeper;

#define MTR_AU_FREQ_DEFAULT         0
#define MTR_AU_CHANNELS_DEFAULT     0
#define MTR_AU_CHUNK_SIZE_DEFAULT   0
#define MTR_AU_DEFAULT              0

#endif

