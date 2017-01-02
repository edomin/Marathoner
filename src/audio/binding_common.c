#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_AudioInit)
{
    uint32_t  sndDmSize;
    uint32_t  sndReservedCount;
    uint32_t  musDmSize;
    uint32_t  musReservedCount;
    int       freq;
    int       channels;
    int       chunkSize;
    bool      success;

    MTR_SF_GET_UINT32(sndDmSize, 1);
    MTR_SF_GET_UINT32(sndReservedCount, 2);
    MTR_SF_GET_UINT32(musDmSize, 3);
    MTR_SF_GET_UINT32(musReservedCount, 4);
    MTR_SF_GET_INT(freq, 5);
    MTR_SF_GET_INT(channels, 6);
    MTR_SF_GET_INT(chunkSize, 7);
    success = mtrAudioInit(sndDmSize, sndReservedCount, musDmSize,
     musReservedCount, freq, channels, chunkSize);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AudioQuit)
{
    mtrAudioQuit();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundLoad)
{
    const char *filename;
    uint32_t    soundNum;

    MTR_SF_GET_STRING(filename, 1);
    soundNum = mtrAudioSoundLoad(filename);

    MTR_SF_PUSH_UINT32(soundNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicLoad)
{
    const char *filename;
    uint32_t    musicNum;

    MTR_SF_GET_STRING(filename, 1);
    musicNum = mtrAudioMusicLoad(filename);

    MTR_SF_PUSH_UINT32(musicNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundPlay)
{
    uint32_t soundNum;

    MTR_SF_GET_UINT32(soundNum, 1);
    mtrAudioSoundPlay(soundNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundFadeInPlay)
{
    uint32_t soundNum;
    int      ms;

    MTR_SF_GET_UINT32(soundNum, 1);
    MTR_SF_GET_INT(ms, 2);
    mtrAudioSoundFadeInPlay(soundNum, ms);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundSetVolume)
{
    uint32_t soundNum;
    int      volume;

    MTR_SF_GET_UINT32(soundNum, 1);
    MTR_SF_GET_INT(volume, 2);
    mtrAudioSoundSetVolume(soundNum, volume);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundSetVolume_f)
{
    uint32_t soundNum;
    float    volume;

    MTR_SF_GET_UINT32(soundNum, 1);
    MTR_SF_GET_SINGLE(volume, 2);
    mtrAudioSoundSetVolume_f(soundNum, volume);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundStop)
{
    uint32_t soundNum;

    MTR_SF_GET_UINT32(soundNum, 1);
    mtrAudioSoundStop(soundNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundFadeOutStop)
{
    uint32_t soundNum;
    int      ms;

    MTR_SF_GET_UINT32(soundNum, 1);
    MTR_SF_GET_INT(ms, 2);
    mtrAudioSoundFadeOutStop(soundNum, ms);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioChannelsSetVolume)
{
    int volume;

    MTR_SF_GET_INT(volume, 1);
    mtrAudioChannelsSetVolume(volume);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioChannelsSetVolume_f)
{
    float volume;

    MTR_SF_GET_SINGLE(volume, 1);
    mtrAudioChannelsSetVolume(volume);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioChannelsPause)
{
    mtrAudioChannelsPause();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioChannelsResume)
{
    mtrAudioChannelsResume();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioChannelsStop)
{
    mtrAudioChannelsStop();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioChannelsFadeOutStop)
{
    int ms;

    MTR_SF_GET_INT(ms, 1);
    mtrAudioChannelsFadeOutStop(ms);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicPlay)
{
    uint32_t musicNum;

    MTR_SF_GET_UINT32(musicNum, 1);
    mtrAudioMusicPlay(musicNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicFadeInPlay)
{
    uint32_t musicNum;
    int      ms;

    MTR_SF_GET_UINT32(musicNum, 1);
    MTR_SF_GET_INT(ms, 2);
    mtrAudioMusicFadeInPlay(musicNum, ms);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicSetVolume)
{
    int volume;

    MTR_SF_GET_INT(volume, 1);
    mtrAudioMusicSetVolume(volume);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicSetVolume_f)
{
    float volume;

    MTR_SF_GET_SINGLE(volume, 1);
    mtrAudioMusicSetVolume_f(volume);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicPause)
{
    mtrAudioMusicPause();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicResume)
{
    mtrAudioMusicResume();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicStop)
{
    mtrAudioMusicStop();

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicFadeOutStop)
{
    int ms;

    MTR_SF_GET_INT(ms, 1);
    mtrAudioMusicFadeOutStop(ms);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundFree)
{
    uint32_t sound;

    MTR_SF_GET_UINT32(sound, 1);
    mtrAudioSoundFree(sound);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicFree)
{
    uint32_t music;

    MTR_SF_GET_UINT32(music, 1);
    mtrAudioMusicFree(music);

    return 0;
}

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();
    mtrAudioInit = (mtrAudioInitFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioInit");
    if (mtrAudioInit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioInit");
        ok = false;
    }
    mtrAudioQuit = (mtrAudioQuitFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioQuit");
    if (mtrAudioQuit == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioQuit");
        ok = false;
    }
    mtrAudioSoundLoad = (mtrAudioSoundLoadFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundLoad");
    if (mtrAudioSoundLoad == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundLoad");
        ok = false;
    }
    mtrAudioMusicLoad = (mtrAudioMusicLoadFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicLoad");
    if (mtrAudioMusicLoad == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicLoad");
        ok = false;
    }
    mtrAudioSoundPlay = (mtrAudioSoundPlayFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundPlay");
    if (mtrAudioSoundPlay == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundPlay");
        ok = false;
    }
    mtrAudioSoundFadeInPlay = (mtrAudioSoundFadeInPlayFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundFadeInPlay");
    if (mtrAudioSoundFadeInPlay == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundFadeInPlay");
        ok = false;
    }
    mtrAudioSoundSetVolume = (mtrAudioSoundSetVolumeFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundSetVolume");
    if (mtrAudioSoundSetVolume == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundSetVolume");
        ok = false;
    }
    mtrAudioSoundSetVolume_f = (mtrAudioSoundSetVolume_fFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundSetVolume_f");
    if (mtrAudioSoundSetVolume_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundSetVolume_f");
        ok = false;
    }
    mtrAudioSoundStop = (mtrAudioSoundStopFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundStop");
    if (mtrAudioSoundStop == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundStop");
        ok = false;
    }
    mtrAudioSoundFadeOutStop = (mtrAudioSoundFadeOutStopFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundFadeOutStop");
    if (mtrAudioSoundFadeOutStop == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundFadeOutStop");
        ok = false;
    }
    mtrAudioSoundSetVolume = (mtrAudioSoundSetVolumeFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundSetVolume");
    if (mtrAudioSoundSetVolume == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundSetVolume");
        ok = false;
    }
    mtrAudioChannelsSetVolume = (mtrAudioChannelsSetVolumeFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioChannelsSetVolume");
    if (mtrAudioChannelsSetVolume == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioChannelsSetVolume");
        ok = false;
    }
    mtrAudioChannelsSetVolume_f = (mtrAudioChannelsSetVolume_fFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioChannelsSetVolume_f");
    if (mtrAudioChannelsSetVolume_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioChannelsSetVolume_f");
        ok = false;
    }
    mtrAudioChannelsPause = (mtrAudioChannelsPauseFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioChannelsPause");
    if (mtrAudioChannelsPause == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioChannelsPause");
        ok = false;
    }
    mtrAudioChannelsResume = (mtrAudioChannelsResumeFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioChannelsResume");
    if (mtrAudioChannelsResume == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioChannelsResume");
        ok = false;
    }
    mtrAudioChannelsStop = (mtrAudioChannelsStopFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioChannelsStop");
    if (mtrAudioChannelsStop == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioChannelsStop");
        ok = false;
    }
    mtrAudioChannelsFadeOutStop = (mtrAudioChannelsFadeOutStopFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioChannelsFadeOutStop");
    if (mtrAudioChannelsFadeOutStop == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioChannelsFadeOutStop");
        ok = false;
    }
    mtrAudioMusicPlay = (mtrAudioMusicPlayFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicPlay");
    if (mtrAudioMusicPlay == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicPlay");
        ok = false;
    }
    mtrAudioMusicFadeInPlay = (mtrAudioMusicFadeInPlayFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicFadeInPlay");
    if (mtrAudioMusicFadeInPlay == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicFadeInPlay");
        ok = false;
    }
    mtrAudioMusicSetVolume = (mtrAudioMusicSetVolumeFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicSetVolume");
    if (mtrAudioMusicSetVolume == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicSetVolume");
        ok = false;
    }
    mtrAudioMusicSetVolume_f = (mtrAudioMusicSetVolume_fFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicSetVolume_f");
    if (mtrAudioMusicSetVolume_f == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicSetVolume_f");
        ok = false;
    }
    mtrAudioMusicPause = (mtrAudioMusicPauseFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicPause");
    if (mtrAudioMusicPause == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicPause");
        ok = false;
    }
    mtrAudioMusicResume = (mtrAudioMusicResumeFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicResume");
    if (mtrAudioMusicResume == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicResume");
        ok = false;
    }
    mtrAudioMusicStop = (mtrAudioMusicStopFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicStop");
    if (mtrAudioMusicStop == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicStop");
        ok = false;
    }
    mtrAudioMusicFadeOutStop = (mtrAudioMusicFadeOutStopFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicFadeOutStop");
    if (mtrAudioMusicFadeOutStop == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicFadeOutStop");
        ok = false;
    }
    mtrAudioSoundFree = (mtrAudioSoundFreeFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioSoundFree");
    if (mtrAudioSoundFree == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioSoundFree");
        ok = false;
    }
    mtrAudioMusicFree = (mtrAudioMusicFreeFunc)mtrFindFunction("Audio_SDL2_mixer",
      "mtrAudioMusicFree");
    if (mtrAudioMusicFree == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrAudioMusicFree");
        ok = false;
    }

    if (ok)
    {
        mtrScriptsRegisterNumericVariable("AU_FREQ_DEFAULT",
         MTR_AU_FREQ_DEFAULT);
        mtrScriptsRegisterNumericVariable("AU_CHANNELS_DEFAULT",
         MTR_AU_CHANNELS_DEFAULT);
        mtrScriptsRegisterNumericVariable("AU_CHUNK_SIZE_DEFAULT",
         MTR_AU_CHUNK_SIZE_DEFAULT);
        mtrScriptsRegisterNumericVariable("AU_DEFAULT", MTR_AU_DEFAULT);

        mtrScriptsRegisterFunction(mtrSF_AudioInit, "AudioInit");
        mtrScriptsRegisterFunction(mtrSF_AudioQuit, "AudioQuit");
        mtrScriptsRegisterFunction(mtrSF_AudioSoundLoad, "AudioSoundLoad");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicLoad, "AudioMusicLoad");
        mtrScriptsRegisterFunction(mtrSF_AudioSoundPlay, "AudioSoundPlay");
        mtrScriptsRegisterFunction(mtrSF_AudioSoundFadeInPlay,
         "AudioSoundFadeInPlay");
        mtrScriptsRegisterFunction(mtrSF_AudioSoundSetVolume,
         "AudioSoundSetVolume");
        mtrScriptsRegisterFunction(mtrSF_AudioSoundSetVolume_f,
         "AudioSoundSetVolume_f");
        mtrScriptsRegisterFunction(mtrSF_AudioSoundStop,
         "AudioSoundStop");
        mtrScriptsRegisterFunction(mtrSF_AudioSoundFadeOutStop,
         "AudioSoundFadeOutStop");
        mtrScriptsRegisterFunction(mtrSF_AudioChannelsSetVolume,
         "AudioChannelsSetVolume");
        mtrScriptsRegisterFunction(mtrSF_AudioChannelsSetVolume_f,
         "AudioChannelsSetVolume_f");
        mtrScriptsRegisterFunction(mtrSF_AudioChannelsPause,
         "AudioChannelsPause");
        mtrScriptsRegisterFunction(mtrSF_AudioChannelsResume,
         "AudioChannelsResume");
        mtrScriptsRegisterFunction(mtrSF_AudioChannelsStop,
         "AudioChannelsStop");
        mtrScriptsRegisterFunction(mtrSF_AudioChannelsFadeOutStop,
         "AudioChannelsFadeOutStop");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicPlay,
         "AudioMusicPlay");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicFadeInPlay,
         "AudioMusicFadeInPlay");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicSetVolume,
         "AudioMusicSetVolume");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicSetVolume_f,
         "AudioMusicSetVolume_f");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicPause,
         "AudioMusicPause");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicResume,
         "AudioMusicResume");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicStop, "AudioMusicStop");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicFadeOutStop,
         "AudioMusicFadeOutStop");
        mtrScriptsRegisterFunction(mtrSF_AudioSoundFree, "AudioSoundFree");
        mtrScriptsRegisterFunction(mtrSF_AudioMusicFree, "AudioMusicFree");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}
