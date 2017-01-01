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
