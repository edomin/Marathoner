#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_AudioInit)
{
    int  sndDmSize;
    int  sndReservedCount;
    int  musDmSize;
    int  musReservedCount;
    int  freq;
    int  channels;
    int  chunkSize;
    bool success;

    MTR_SF_GET_INT(sndDmSize, 1);
    MTR_SF_GET_INT(sndReservedCount, 2);
    MTR_SF_GET_INT(musDmSize, 3);
    MTR_SF_GET_INT(musReservedCount, 4);
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
    int         soundNum;

    MTR_SF_GET_STRING(filename, 1);
    soundNum = mtrAudioSoundLoad(filename);

    MTR_SF_PUSH_INT(soundNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicLoad)
{
    const char *filename;
    int         musicNum;

    MTR_SF_GET_STRING(filename, 1);
    musicNum = mtrAudioMusicLoad(filename);

    MTR_SF_PUSH_INT(musicNum);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundPlay)
{
    int soundNum;

    MTR_SF_GET_INT(soundNum, 1);
    mtrAudioSoundPlay(soundNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundFadeInPlay)
{
    int soundNum;
    int ms;

    MTR_SF_GET_INT(soundNum, 1);
    MTR_SF_GET_INT(ms, 2);
    mtrAudioSoundFadeInPlay(soundNum, ms);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundSetVolume)
{
    int soundNum;
    int volume;

    MTR_SF_GET_INT(soundNum, 1);
    MTR_SF_GET_INT(volume, 2);
    mtrAudioSoundSetVolume(soundNum, volume);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioSoundSetVolume_f)
{
    int   soundNum;
    float volume;

    MTR_SF_GET_INT(soundNum, 1);
    MTR_SF_GET_SINGLE(volume, 2);
    mtrAudioSoundSetVolume_f(soundNum, volume);

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
    int musicNum;

    MTR_SF_GET_INT(musicNum, 1);
    mtrAudioMusicPlay(musicNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicFadeInPlay)
{
    int musicNum;
    int ms;

    MTR_SF_GET_INT(musicNum, 1);
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
    int sound;

    MTR_SF_GET_INT(sound, 1);
    mtrAudioSoundFree(sound);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_AudioMusicFree)
{
    int music;

    MTR_SF_GET_INT(music, 1);
    mtrAudioMusicFree(music);

    return 0;
}
