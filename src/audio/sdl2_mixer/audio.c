#include "audio.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Audio, FA_FUNCTIONS_COUNT)

/*fa MTR_AudioInit yes */
MTR_DCLSPC bool MTR_CALL MTR_AudioInit(uint32_t sndDmSize,
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

    MTR_LogWrite("Initializing audio manager", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&sdlLinked);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, sdlLinked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, sdlLinked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, sdlLinked.patch);
    MTR_LogWrite("Reporting SDL_mixer compile-time version:", 1, MTR_LMT_INFO);
    SDL_MIXER_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL_mixer linked version:", 1, MTR_LMT_INFO);
    linked = Mix_Linked_Version();
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, linked->major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, linked->minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, linked->patch);

    if (SDL_InitSubSystem(SDL_INIT_AUDIO) == 0)
        MTR_LogWrite("SDL audio subsystem initialized", 1, MTR_LMT_INFO);
    else
        MTR_LogWrite("Unable to initialize SDL audio subsystem", 1,
         MTR_LMT_INFO);

    initFlags = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MODPLUG | MIX_INIT_MP3 |
     MIX_INIT_OGG | MIX_INIT_FLUIDSYNTH;
    initResult = Mix_Init(initFlags);
    if(initResult != initFlags)
    {
        if (initResult == 0)
        {
            MTR_Notify("Unable to load libraries needed by SDL_mixer", 1,
             MTR_LMT_ERROR);
            return false;
        }

        MTR_LogWrite("Unable to initialize support of this formats:", 1,
         MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_FLAC) == 0)
            MTR_LogWrite("FLAC", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_MOD) == 0)
            MTR_LogWrite("MOD", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_MODPLUG) == 0)
            MTR_LogWrite("MODPlug", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_MP3) == 0)
            MTR_LogWrite("MP3", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_OGG) == 0)
            MTR_LogWrite("OGG", 2, MTR_LMT_WARNING);
        if ((initResult & MIX_INIT_FLUIDSYNTH) == 0)
            MTR_LogWrite("FluidSynth", 2, MTR_LMT_WARNING);
    }
    else
        MTR_LogWrite("Support of the every SDL_mixer audio format initialized",
         1, MTR_LMT_INFO);

    MTR_LogWrite("Preparing parameters for initialize SDL_mixer", 1,
     MTR_LMT_INFO);

    /* Choosing sampling frequency */
    if (freq == MTR_AU_FREQ_DEFAULT)
    {
        frequency = MIX_DEFAULT_FREQUENCY;
        MTR_LogWrite_i("Choosed default sampling frequency (Hz): ", 2,
         MTR_LMT_INFO, MIX_DEFAULT_FREQUENCY);
    }
    else if (freq < 11025)
    {
        frequency = 11025;
        MTR_LogWrite_i("Choosed sampling frequency not supported. Using "
         "minimal supported sampling frequency (Hz): ", 2, MTR_LMT_WARNING,
         11025);
    }
    else
    {
        frequency = freq;
        MTR_LogWrite_i("Choosed sampling frequency (Hz): ", 2, MTR_LMT_INFO,
         freq);
    }

    /* Choosing channels count */
    if (channels == MTR_AU_CHANNELS_DEFAULT)
    {
        channelsCount = MIX_DEFAULT_CHANNELS;
        MTR_LogWrite_s("Choosed default channels count: ", 2, MTR_LMT_INFO,
         channelsConf[MIX_DEFAULT_CHANNELS - 1]);
    }
    else if (channels > 2)
    {
        channelsCount = 2;
        MTR_LogWrite_s("Choosed channels count are not supported. Using max "
         "supported channels count: ", 2, MTR_LMT_WARNING, channelsConf[2 - 1]);
    }
    else
    {
        channelsCount = channels;
        MTR_LogWrite_s("Choosed channels count: ", 2, MTR_LMT_INFO,
         channelsConf[channels - 1]);
    }

    /* Choosing chunk size */
    if (chunkSize == MTR_AU_CHUNK_SIZE_DEFAULT)
    {
        finalChunkSize = 4096;
        MTR_LogWrite_i("Choosed default chunk size (bytes): ", 2, MTR_LMT_INFO,
         4096);
    }
    else if (chunkSize > 8192)
    {
        finalChunkSize = 8192;
        MTR_LogWrite_i("Choosed chunk size not supported. Using max supported "
         "chunk size (bytes): ", 2, MTR_LMT_WARNING, 8192);
    }
    else if (chunkSize < 512)
    {
        finalChunkSize = 512;
        MTR_LogWrite_i("Choosed chunk size not supported. Using minimal "
         "supported chunk size (bytes): ", 2, MTR_LMT_WARNING, 512);
    }
    else
    {
        finalChunkSize = chunkSize;
        MTR_LogWrite_i("Choosed chunk size (bytes): ", 2, MTR_LMT_INFO,
         chunkSize);
    }

    if (Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, channelsCount,
     finalChunkSize) == 0)
    {
        MTR_LogWrite("SDL_mixer initialized", 1, MTR_LMT_INFO);

        MTR_LogWrite("Reporting built-in SDL_mixer chunk decoders", 1,
         MTR_LMT_INFO);
        for (i = 0; i < Mix_GetNumChunkDecoders(); i++)
            MTR_LogWrite_s("Chunk decoder found: ", 2, MTR_LMT_INFO,
             Mix_GetChunkDecoder(i));
        MTR_LogWrite("Reporting built-in SDL_mixer music decoders", 1,
         MTR_LMT_INFO);
        for (i = 0; i < Mix_GetNumMusicDecoders(); i++)
            MTR_LogWrite_s("Music decoder found: ", 2, MTR_LMT_INFO,
             Mix_GetMusicDecoder(i));
    }
    else
    {
        MTR_Notify("Unable to initialize SDL2_mixer", 1, MTR_LMT_ERROR);
        MTR_LogWrite_s("SDL2_mixer error: ", 1, MTR_LMT_ERROR, Mix_GetError());
        Mix_Quit();
        return false;
    }
    Mix_AllocateChannels(64);

    mtrSoundKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(sndDmSize,
     sndReservedCount, sizeof(mtrSound_t));
    if (mtrSoundKeeper == NULL)
    {
        MTR_Notify("Unable to initialize indexkeeper structure for sounds", 1,
         MTR_LMT_ERROR);
        Mix_CloseAudio();
        Mix_Quit();
        return false;
    }
    else
        MTR_LogWrite("Indexkeeper structure for sounds initialized", 1,
         MTR_LMT_INFO);

    mtrMusicKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(musDmSize,
     musReservedCount, sizeof(mtrMusic_t));
    if (mtrMusicKeeper == NULL)
    {
        MTR_Notify("Unable to initialize indexkeeper structure for music", 1,
         MTR_LMT_ERROR);
        Mix_CloseAudio();
        Mix_Quit();
        return false;
    }
    else
        MTR_LogWrite("Indexkeeper structure for music initialized", 1,
         MTR_LMT_INFO);

    MTR_LogWrite("Audio manager initialized", 0, MTR_LMT_INFO);

    mtrCurrentMusic = 0U;
    mtrAudioInited = true;
    return true;
}

/*fa MTR_AudioQuit yes */
MTR_DCLSPC void MTR_CALL MTR_AudioQuit(void)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED_WITH_LOG("Unable to destroy audio manager",);

    MTR_LogWrite("Destroying audio manager", 0, MTR_LMT_INFO);
    Mix_CloseAudio();
    Mix_Quit();
    MTR_LogWrite("Audio manager destroyed", 0, MTR_LMT_INFO);
}

/*fa MTR_AudioSoundLoad yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_AudioSoundLoad(const char *filename)
{
    uint32_t    freeIndex;
    mtrSound_t *sound;
    MTR_AUDIO_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load sound", 0U);

    if (filename == NULL) {
        MTR_Notify("Unable to load sound. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return 0U;
    }

    MTR_LogWrite_s("Loading sound", 0, MTR_LMT_INFO, filename);
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrSoundKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[freeIndex]);
    sound->sound = Mix_LoadWAV(filename);
    if (sound->sound != NULL)
    {
        sound->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (sound->name == NULL)
            sound->name = mtrDefaultSoundName;
        else
            sound->name = strcpy(sound->name, filename);
        MTR_LogWrite_s("Sound loaded", 0, MTR_LMT_INFO, filename);
        return freeIndex;
    }
    else
    {
        MTR_Notify("Unable to load sound", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrSoundKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa MTR_AudioMusicLoad yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_AudioMusicLoad(const char *filename)
{
    uint32_t     freeIndex;
    mtrMusic_t  *music;
    int          musicType;
    MTR_AUDIO_CHECK_IF_NOT_INITED_WITH_LOG("Unable to load music", 0U);

    if (filename == NULL) {
        MTR_Notify("Unable to load music. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return 0U;
    }

    MTR_LogWrite_s("Loading music file", 0, MTR_LMT_INFO, filename);
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrMusicKeeper);
    MTR_LogWrite_i("Found free index: ", 1, MTR_LMT_INFO, freeIndex);
    music = (mtrMusic_t *)(&((mtrMusic_t *)mtrMusicKeeper->data)[freeIndex]);
    music->music = Mix_LoadMUS(filename);
    if (music->music != NULL)
    {
        music->name = malloc(sizeof(char) * (strlen(filename) + 1));
        if (music->name == NULL)
            music->name = mtrDefaultMusicName;
        else
            music->name = strcpy(music->name, filename);
        MTR_LogWrite_s("Music file loaded", 0, MTR_LMT_INFO, filename);
        musicType = Mix_GetMusicType(music->music);
        switch(musicType)
        {
            case MUS_NONE:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "unknown");
                break;
            case MUS_CMD:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO,
                 "music playing via external music player");
                break;
            case MUS_WAV:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "WAV");
                break;
            case MUS_MOD:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "MOD");
                break;
            case MUS_MID:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "MIDI");
                break;
            case MUS_OGG:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "OGG");
                break;
            case MUS_MP3:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "MP3");
                break;
            case MUS_MP3_MAD:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO,
                 "MP3 playing via MAD audio decoder");
                break;
            case MUS_FLAC:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "FLAC");
                break;
            case MUS_MODPLUG:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "tracker music");
                break;
            default:
                MTR_LogWrite_s("Music type:", 2, MTR_LMT_INFO, "unknown");
                break;
        }
        return freeIndex;
    }
    else
    {
        MTR_Notify("Unable to load music", 1, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrMusicKeeper, freeIndex);
        return 0U;
    }
    return 0U;
}

/*fa MTR_AudioSoundPlay yes */
MTR_DCLSPC void MTR_CALL MTR_AudioSoundPlay(uint32_t soundNum)
{
    mtrSound_t *sound;
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    Mix_PlayChannel(-1, sound->sound, 0);
}

/*fa MTR_AudioSoundFadeInPlay yes */
MTR_DCLSPC void MTR_CALL MTR_AudioSoundFadeInPlay(uint32_t soundNum, int ms)
{
    mtrSound_t *sound;
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    Mix_FadeInChannel(-1, sound->sound, 0, ms);
}

/*fa MTR_AudioSoundSetVolume yes */
MTR_DCLSPC void MTR_CALL MTR_AudioSoundSetVolume(uint32_t soundNum,
 int volume)
{
    mtrSound_t *sound;
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    Mix_VolumeChunk(sound->sound, volume);
}

/*fa MTR_AudioSoundSetVolume_f yes */
MTR_DCLSPC void MTR_CALL MTR_AudioSoundSetVolume_f(uint32_t soundNum,
 float volume)
{
    mtrSound_t *sound;
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
    Mix_VolumeChunk(sound->sound, (int)((float)MIX_MAX_VOLUME * volume));
}

/*fa MTR_AudioSoundStop yes */
MTR_DCLSPC void MTR_CALL MTR_AudioSoundStop(uint32_t soundNum)
{
    int         i;
    int         channelsCount;
    mtrSound_t *sound;
    Mix_Chunk  *playingChunk;
    MTR_AUDIO_CHECK_IF_NOT_INITED();

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

/*fa MTR_AudioSoundFadeOutStop yes */
MTR_DCLSPC void MTR_CALL MTR_AudioSoundFadeOutStop(uint32_t soundNum, int ms)
{
    int         i;
    int         channelsCount;
    mtrSound_t *sound;
    Mix_Chunk  *playingChunk;
    MTR_AUDIO_CHECK_IF_NOT_INITED();

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

/*fa MTR_AudioChannelsSetVolume yes */
MTR_DCLSPC void MTR_CALL MTR_AudioChannelsSetVolume(int volume)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    Mix_Volume(-1, volume);
}

/*fa MTR_AudioChannelsSetVolume_f yes */
MTR_DCLSPC void MTR_CALL MTR_AudioChannelsSetVolume_f(float volume)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    Mix_Volume(-1, (int)((float)MIX_MAX_VOLUME * volume));
}

/*fa MTR_AudioChannelsPause yes */
MTR_DCLSPC void MTR_CALL MTR_AudioChannelsPause(void)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    if (Mix_Playing(-1) != 0)
        Mix_Pause(-1);
}

/*fa MTR_AudioChannelsResume yes */
MTR_DCLSPC void MTR_CALL MTR_AudioChannelsResume(void)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    if (Mix_Paused(-1) != 0)
        Mix_Resume(-1);
}

/*fa MTR_AudioChannelsStop yes */
MTR_DCLSPC void MTR_CALL MTR_AudioChannelsStop(void)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    Mix_HaltChannel(-1);
}

/*fa MTR_AudioChannelsFadeOutStop yes */
MTR_DCLSPC void MTR_CALL MTR_AudioChannelsFadeOutStop(int ms)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    Mix_FadeOutChannel(-1, ms);
}

/*fa MTR_AudioMusicPlaying yes */
MTR_DCLSPC bool MTR_CALL MTR_AudioMusicPlaying(uint32_t musicNum)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED(false);

    if ((musicNum == 0) || (musicNum != mtrCurrentMusic))
        return false;

    return Mix_PlayingMusic();
}

/*fa MTR_AudioMusicFadingIn yes */
MTR_DCLSPC bool MTR_CALL MTR_AudioMusicFadingIn()
{
    MTR_AUDIO_CHECK_IF_NOT_INITED(false);

    if (Mix_FadingMusic() == MIX_FADING_IN)
        return true;
    else
        return false;
}

/*fa MTR_AudioMusicFadingOut yes */
MTR_DCLSPC bool MTR_CALL MTR_AudioMusicFadingOut()
{
    MTR_AUDIO_CHECK_IF_NOT_INITED(false);

    if (Mix_FadingMusic() == MIX_FADING_OUT)
        return true;
    else
        return false;
}

/*fa MTR_AudioMusicPlay yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicPlay(uint32_t musicNum, int loops)
{
    mtrMusic_t *music;
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    music = (mtrMusic_t *)(&((mtrMusic_t *)mtrMusicKeeper->data)[musicNum]);
    Mix_PlayMusic(music->music, loops);
    mtrCurrentMusic = musicNum;
}

/*fa MTR_AudioMusicFadeInPlay yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicFadeInPlay(uint32_t musicNum, int ms)
{
    mtrMusic_t *music;
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    music = (mtrMusic_t *)(&((mtrMusic_t *)mtrMusicKeeper->data)[musicNum]);
    Mix_FadeInMusic(music->music, -1, ms);
    mtrCurrentMusic = musicNum;
}

/*fa MTR_AudioMusicPause yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicPause(void)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    if(Mix_PausedMusic() == 0)
        Mix_PauseMusic();
}

/*fa MTR_AudioMusicResume yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicResume(void)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    if(Mix_PausedMusic() == 1)
        Mix_ResumeMusic();
}

/*fa MTR_AudioMusicStop yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicStop(void)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    if (Mix_PlayingMusic() == 1)
        Mix_HaltMusic();
    mtrCurrentMusic = 0U;
}

/*fa MTR_AudioMusicFadeOutStop yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicFadeOutStop(int ms)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    if (Mix_PlayingMusic() == 1)
        Mix_FadeOutMusic(ms);
    mtrCurrentMusic = 0U;
}

/*fa MTR_AudioMusicSetVolume yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicSetVolume(int volume)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    Mix_VolumeMusic(volume);
}

/*fa MTR_AudioMusicSetVolume_f yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicSetVolume_f(float volume)
{
    MTR_AUDIO_CHECK_IF_NOT_INITED();

    Mix_VolumeMusic((int)((float)MIX_MAX_VOLUME * volume));
}

/*fa MTR_AudioSoundFree yes */
MTR_DCLSPC void MTR_CALL MTR_AudioSoundFree(uint32_t soundNum)
{
    mtrSound_t *sound;
    MTR_AUDIO_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload sound",);

    if (soundNum != 0)
    {
        sound = (mtrSound_t *)(&((mtrSound_t *)mtrSoundKeeper->data)[soundNum]);
        MTR_LogWrite_s("Unloading sound", 0, MTR_LMT_INFO, sound->name);
        if (sound->name != mtrDefaultSoundName)
            free(sound->name);
        Mix_FreeChunk(sound->sound);
        MTR_IndexkeeperFreeIndex(mtrSoundKeeper, soundNum);
        MTR_LogWrite("Sound unloaded", 0, MTR_LMT_INFO);
    }
}

/*fa MTR_AudioMusicFree yes */
MTR_DCLSPC void MTR_CALL MTR_AudioMusicFree(uint32_t musicNum)
{
    mtrMusic_t *music;
    MTR_AUDIO_CHECK_IF_NOT_INITED_WITH_LOG("Unable to unload music",);

    if (musicNum != 0)
    {
        music = (mtrMusic_t *)(&((mtrMusic_t *)mtrMusicKeeper->data)[musicNum]);
        MTR_LogWrite_s("Unloading music", 0, MTR_LMT_INFO, music->name);
        if (music->name != mtrDefaultMusicName)
            free(music->name);
        Mix_FreeMusic(music->music);
        MTR_IndexkeeperFreeIndex(mtrMusicKeeper, musicNum);
        MTR_LogWrite("Music unloaded", 0, MTR_LMT_INFO);
    }
}
