#include "audio.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Audio_SDL2_mixer";
    report->version = MTR_VERSION_AUDIO_SDL2_MIXER;
    report->subsystem = "audio";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT bool MTR_CALL mtrAudioInit(uint32_t sndDmSize,
 uint32_t sndReservedCount, uint32_t musDmSize, uint32_t musReservedCount,
 int freq, int channels, int chunkSize)
{
    SDL_version compiled;
    const SDL_version *linked;
    SDL_version sdlLinked;
    int frequency;
    int channelsCount;
    int finalChunkSize;
    int initFlags;
    int initResult;
    const char channelsMono[] = "mono";
    const char channelsStereo[] = "stereo";
    const char *channelsConf[2];
    int i;

    channelsConf[0] = channelsMono;
    channelsConf[1] = channelsStereo;

    mtrLogWrite("Initializing audio manager", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&sdlLinked);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, sdlLinked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlLinked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlLinked.patch);
    mtrLogWrite("Reporting SDL_mixer compile-time version:", 1, MTR_LMT_INFO);
    SDL_MIXER_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL_mixer linked version:", 1, MTR_LMT_INFO);
    linked = Mix_Linked_Version();
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, linked->major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, linked->minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, linked->patch);

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) == 0)
        mtrLogWrite("SDL audio subsystem initialized", 1, MTR_LMT_INFO);
    else
        mtrLogWrite("Unable to initialize SDL audio subsystem", 1,
         MTR_LMT_INFO);

    initFlags = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MODPLUG | MIX_INIT_MP3 |
     MIX_INIT_OGG | MIX_INIT_FLUIDSYNTH;
    initResult = Mix_Init(initFlags);
    if(initResult != initFlags)
    {
        if (initResult == 0)
        {
            mtrNotify("Unable to load libraries needed by SDL_mixer", 1,
             MTR_LMT_ERROR);
            return false;
        }

        mtrLogWrite("Unable to initialize support of this formats:", 1,
         MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_FLAC) == 0)
            mtrLogWrite("FLAC", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_MOD) == 0)
            mtrLogWrite("MOD", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_MODPLUG) == 0)
            mtrLogWrite("MODPlug", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_MP3) == 0)
            mtrLogWrite("MP3", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_OGG) == 0)
            mtrLogWrite("OGG", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_FLUIDSYNTH) == 0)
            mtrLogWrite("FluidSynth", 2, MTR_LMT_WARNING);
    }
    else
        mtrLogWrite("Support of the every SDL_mixer audio format initialized",
         1, MTR_LMT_INFO);

    mtrLogWrite("Preparing parameters for initialize SDL_mixer", 1,
     MTR_LMT_INFO);

    /* Choosing sampling frequency */
    if (freq == MTR_AU_FREQ_DEFAULT)
    {
        frequency = MIX_DEFAULT_FREQUENCY;
        mtrLogWrite_i("Choosed default sampling frequency (Hz): ", 2,
         MTR_LMT_INFO, MIX_DEFAULT_FREQUENCY);
    }
    else if (freq < 11025)
    {
        frequency = 11025;
        mtrLogWrite_i("Choosed sampling frequency not supported. Using minimal "
         "supported sampling frequency (Hz): ", 2, MTR_LMT_WARNING, 11025);
    }
    else
    {
        frequency = freq;
        mtrLogWrite_i("Choosed sampling frequency (Hz): ", 2, MTR_LMT_INFO,
         freq);
    }
    /* */

    /* Choosing channels count */
    if (channels == MTR_AU_CHANNELS_DEFAULT)
    {
        channelsCount = MIX_DEFAULT_CHANNELS;
        mtrLogWrite_s("Choosed default channels count: ", 2, MTR_LMT_INFO,
         channelsConf[MIX_DEFAULT_CHANNELS - 1]);
    }
    else if (channels > 2)
    {
        channelsCount = 2;
        mtrLogWrite_s("Choosed channels count are not supported. Using max "
         "supported channels count: ", 2, MTR_LMT_WARNING, channelsConf[2 - 1]);
    }
    else
    {
        channelsCount = channels;
        mtrLogWrite_s("Choosed channels count: ", 2, MTR_LMT_INFO,
         channelsConf[channels - 1]);
    }
    /*  */

    /* Choosing chunk size */
    if (chunkSize == MTR_AU_CHUNK_SIZE_DEFAULT)
    {
        finalChunkSize = 4096;
        mtrLogWrite_i("Choosed default chunk size (bytes): ", 2, MTR_LMT_INFO,
         4096);
    }
    else if (chunkSize > 8192)
    {
        finalChunkSize = 8192;
        mtrLogWrite_i("Choosed chunk size not supported. Using max supported "
         "chunk size (bytes): ", 2, MTR_LMT_WARNING, 8192);
    }
    else if (chunkSize < 512)
    {
        finalChunkSize = 512;
        mtrLogWrite_i("Choosed chunk size not supported. Using minimal "
         "supported chunk size (bytes): ", 2, MTR_LMT_WARNING, 512);
    }
    else
    {
        finalChunkSize = chunkSize;
        mtrLogWrite_i("Choosed chunk size (bytes): ", 2, MTR_LMT_INFO,
         chunkSize);
    }
    /* */

    if (Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, channelsCount,
     finalChunkSize) == 0)
    {
        mtrLogWrite("SDL_mixer initialized", 1, MTR_LMT_INFO);

        mtrLogWrite("Reporting built-in SDL_mixer chunk decoders", 1,
         MTR_LMT_INFO);
        for (i = 0; i < Mix_GetNumChunkDecoders(); i++)
            mtrLogWrite_s("Chunk decoder found: ", 2, MTR_LMT_INFO,
             Mix_GetChunkDecoder(i));
        mtrLogWrite("Reporting built-in SDL_mixer music decoders", 1,
         MTR_LMT_INFO);
        for (i = 0; i < Mix_GetNumMusicDecoders(); i++)
            mtrLogWrite_s("Music decoder found: ", 2, MTR_LMT_INFO,
             Mix_GetMusicDecoder(i));
    }
    else
    {
        mtrNotify("Unable to initialize SDL_mixer", 1, MTR_LMT_ERROR);
        Mix_Quit();
        return false;
    }
    Mix_AllocateChannels(32);

    mtrSoundKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(sndDmSize,
     sndReservedCount, sizeof(mtrSound_t));
    if (mtrSoundKeeper == NULL)
    {
        mtrNotify("Unable to initialize indexkeeper structure for sounds", 1,
         MTR_LMT_ERROR);
        Mix_CloseAudio();
        Mix_Quit();
        return false;
    }
    else
        mtrLogWrite("Indexkeeper structure for sounds initialized", 1,
         MTR_LMT_INFO);

    mtrMusicKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(musDmSize,
     musReservedCount, sizeof(mtrMusic_t));
    if (mtrMusicKeeper == NULL)
    {
        mtrNotify("Unable to initialize indexkeeper structure for music", 1,
         MTR_LMT_ERROR);
        Mix_CloseAudio();
        Mix_Quit();
        return false;
    }
    else
        mtrLogWrite("Indexkeeper structure for music initialized", 1,
         MTR_LMT_INFO);

    mtrLogWrite("Audio manager initialized", 0, MTR_LMT_INFO);

    return true;
}

MTR_EXPORT void MTR_CALL mtrAudioQuit(void)
{
    mtrLogWrite("Destroying audio manager", 0, MTR_LMT_INFO);
    Mix_CloseAudio();
    Mix_Quit();
    mtrLogWrite("Audio manager destroyed", 0, MTR_LMT_INFO);
}

MTR_EXPORT uint32_t MTR_CALL mtrAudioSoundLoad(const char *filename)
{
    uint32_t    freeIndex;
    mtrSound_t *sound;

    mtrLogWrite_s("Loading sound", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrSoundKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[freeIndex]);
    sound->sound = Mix_LoadWAV(filename);
    if (sound->sound != NULL)
    {
        sound->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (sound->name == NULL)
            sound->name = mtrDefaultSoundName;
        else
            sound->name = strcpy(sound->name, filename);
        mtrLogWrite_s("Sound loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to load sound", 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrSoundKeeper, freeIndex);
        return 0;
    }
    return 0;
}

MTR_EXPORT uint32_t MTR_CALL mtrAudioMusicLoad(const char *filename)
{
    uint32_t     freeIndex;
    mtrMusic_t  *music;
    int          musicType;

    mtrLogWrite_s("Loading music file", 0, MTR_LMT_INFO, filename);
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrMusicKeeper);
    mtrLogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    music = (mtrMusic_t *)(&((mtrMusic_t *)mtrMusicKeeper->data)[freeIndex]);
    music->music = Mix_LoadMUS(filename);
    if (music->music != NULL)
    {
        music->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (music->name == NULL)
            music->name = mtrDefaultMusicName;
        else
            music->name = strcpy(music->name, filename);
        mtrLogWrite_s("Music file loaded", 0, MTR_LMT_INFO, filename);
        musicType = Mix_GetMusicType(music->music);
        switch(musicType)
        {
            case MUS_NONE:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "unknown");
                break;
            case MUS_CMD:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO,
                 "music playing via external music player");
                break;
            case MUS_WAV:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "WAV");
                break;
            case MUS_MOD:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "MOD");
                break;
            case MUS_MID:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "MIDI");
                break;
            case MUS_OGG:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "OGG");
                break;
            case MUS_MP3:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "MP3");
                break;
            case MUS_MP3_MAD:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO,
                 "MP3 playing via MAD audio decoder");
                break;
            case MUS_FLAC:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "FLAC");
                break;
            case MUS_MODPLUG:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "tracker music");
                break;
            default:
                mtrLogWrite_s("Music type:", 2, MTR_LMT_INFO, "unknown");
                break;
        }
        return freeIndex;
    }
    else
    {
        mtrNotify("Unable to load music", 1, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrMusicKeeper, freeIndex);
        return 0;
    }
    return 0;
}

MTR_EXPORT void MTR_CALL mtrAudioSoundPlay(uint32_t soundNum)
{
    mtrSound_t *sound;
    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    Mix_PlayChannel(-1, sound->sound, 0);
}

MTR_EXPORT void MTR_CALL mtrAudioSoundFadeInPlay(uint32_t soundNum, int ms)
{
    mtrSound_t *sound;
    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    Mix_FadeInChannel(-1, sound->sound, 0, ms);
}

MTR_EXPORT void MTR_CALL mtrAudioSoundSetVolume(uint32_t soundNum,
 int volume)
{
    mtrSound_t *sound;
    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    Mix_VolumeChunk(sound->sound, volume);
}

MTR_EXPORT void MTR_CALL mtrAudioSoundSetVolume_f(uint32_t soundNum,
 float volume)
{
    mtrSound_t *sound;
    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    Mix_VolumeChunk(sound->sound, (int)((float)MIX_MAX_VOLUME * volume));
}

MTR_EXPORT void MTR_CALL mtrAudioSoundStop(uint32_t soundNum)
{
    int i;
    int channelsCount;
    mtrSound_t *sound;
    Mix_Chunk *playingChunk;
    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    channelsCount = 32;
    for (i = 0; i < channelsCount; i++)
    {
        playingChunk = Mix_GetChunk(i);
        if (sound->sound == playingChunk)
        {
            Mix_HaltChannel(i);
        }
    }
}

MTR_EXPORT void MTR_CALL mtrAudioSoundFadeOutStop(uint32_t soundNum, int ms)
{
    int i;
    int channelsCount;
    mtrSound_t *sound;
    Mix_Chunk *playingChunk;
    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    channelsCount = 32;
    for (i = 0; i < channelsCount; i++)
    {
        playingChunk = Mix_GetChunk(i);
        if (sound->sound == playingChunk)
        {
            Mix_FadeOutChannel(i, ms);
        }
    }
}

MTR_EXPORT void MTR_CALL mtrAudioChannelsSetVolume(int volume)
{
    Mix_Volume(-1, volume);
}

MTR_EXPORT void MTR_CALL mtrAudioChannelsSetVolume_f(float volume)
{
    Mix_Volume(-1, (int)((float)MIX_MAX_VOLUME * volume));
}

MTR_EXPORT void MTR_CALL mtrAudioChannelsPause(void)
{
    if (Mix_Playing(-1) != 0)
        Mix_Pause(-1);
}

MTR_EXPORT void MTR_CALL mtrAudioChannelsResume(void)
{
    if (Mix_Paused(-1) != 0)
        Mix_Resume(-1);
}

MTR_EXPORT void MTR_CALL mtrAudioChannelsStop(void)
{
    Mix_HaltChannel(-1);
}

MTR_EXPORT void MTR_CALL mtrAudioChannelsFadeOutStop(int ms)
{
    Mix_FadeOutChannel(-1, ms);
}

MTR_EXPORT void MTR_CALL mtrAudioMusicPlay(uint32_t musicNum)
{
    mtrMusic_t *music;
    music = (mtrMusic_t *)(&((mtrMusic_t *)mtrMusicKeeper->data)[musicNum]);
    Mix_PlayMusic(music->music, -1);
}

MTR_EXPORT void MTR_CALL mtrAudioMusicFadeInPlay(uint32_t musicNum, int ms)
{
    mtrMusic_t *music;
    music = (mtrMusic_t *)(&((mtrMusic_t *)mtrMusicKeeper->data)[musicNum]);
    Mix_FadeInMusic(music->music, -1, ms);
}

MTR_EXPORT void MTR_CALL mtrAudioMusicPause(void)
{
    if(Mix_PausedMusic() == 0)
        Mix_PauseMusic();
}

MTR_EXPORT void MTR_CALL mtrAudioMusicResume(void)
{
    if(Mix_PausedMusic() == 1)
        Mix_ResumeMusic();
}

MTR_EXPORT void MTR_CALL mtrAudioMusicStop(void)
{
    if (Mix_PlayingMusic() == 1)
        Mix_HaltMusic();
}

MTR_EXPORT void MTR_CALL mtrAudioMusicFadeOutStop(int ms)
{
    if (Mix_PlayingMusic() == 1)
        Mix_FadeOutMusic(ms);
}

MTR_EXPORT void MTR_CALL mtrAudioMusicSetVolume(int volume)
{
    Mix_VolumeMusic(volume);
}

MTR_EXPORT void MTR_CALL mtrAudioMusicSetVolume_f(float volume)
{
    Mix_VolumeMusic((int)((float)MIX_MAX_VOLUME * volume));
}

MTR_EXPORT void MTR_CALL mtrAudioSoundFree(uint32_t soundNum)
{
    mtrSound_t *sound;
    if (soundNum != 0)
    {
        sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
        mtrLogWrite_s("Unloading sound", 0, MTR_LMT_INFO, sound->name);
        if (sound->name == mtrDefaultSoundName)
            free(sound->name);
        Mix_FreeChunk(sound->sound);
        mtrIndexkeeperFreeIndex(mtrSoundKeeper, soundNum);
        mtrLogWrite("Sound unloaded", 0, MTR_LMT_INFO);
    }
}

MTR_EXPORT void MTR_CALL mtrAudioMusicFree(uint32_t musicNum)
{
    mtrMusic_t *music;
    if (musicNum != 0)
    {
        music = (mtrMusic_t *)(&((mtrMusic_t *)mtrMusicKeeper->data)[musicNum]);
        mtrLogWrite_s("Unloading music", 0, MTR_LMT_INFO, music->name);
        if (music->name == mtrDefaultMusicName)
            free(music->name);
        Mix_FreeMusic(music->music);
        mtrIndexkeeperFreeIndex(mtrMusicKeeper, musicNum);
        mtrLogWrite("Music unloaded", 0, MTR_LMT_INFO);
    }
}
