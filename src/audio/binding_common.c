#ifndef MTR_AUDIO_BINDING_COMMON_C
#define MTR_AUDIO_BINDING_COMMON_C

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

    MTR_FIND_FUNCTION(mtrAudioInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioQuit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioSoundLoad, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicLoad, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioSoundPlay, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioSoundFadeInPlay, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioSoundSetVolume, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioSoundSetVolume_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioSoundStop, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioSoundFadeOutStop, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioChannelsSetVolume, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioChannelsSetVolume_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioChannelsPause, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioChannelsResume, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioChannelsStop, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioChannelsFadeOutStop, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicPlay, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicFadeInPlay, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicSetVolume, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicSetVolume_f, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicPause, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicResume, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicStop, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicFadeOutStop, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioSoundFree, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrAudioMusicFree, MTR_SOURCE_MODULE);

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

#endif
