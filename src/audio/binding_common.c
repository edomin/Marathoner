#ifndef MTR_AUDIO_BINDING_COMMON_C
#define MTR_AUDIO_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_AudioFunctionSupported, mtrAudioFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t4I3(mtrSF_AudioInit, mtrAudioInit)
MTR_SCRIPT_FUNC_V_V(mtrSF_AudioQuit, mtrAudioQuit)
MTR_SCRIPT_FUNC_U32t_S1(mtrSF_AudioSoundLoad, mtrAudioSoundLoad)
MTR_SCRIPT_FUNC_U32t_S1(mtrSF_AudioMusicLoad, mtrAudioMusicLoad)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_AudioSoundPlay, mtrAudioSoundPlay)
MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_AudioSoundFadeInPlay, mtrAudioSoundFadeInPlay)
MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_AudioSoundSetVolume, mtrAudioSoundSetVolume)
MTR_SCRIPT_FUNC_V_U32t1F1(mtrSF_AudioSoundSetVolume_f, mtrAudioSoundSetVolume_f)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_AudioSoundStop, mtrAudioSoundStop)
MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_AudioSoundFadeOutStop, mtrAudioSoundFadeOutStop)
MTR_SCRIPT_FUNC_V_I1(mtrSF_AudioChannelsSetVolume, mtrAudioChannelsSetVolume)
MTR_SCRIPT_FUNC_V_F1(mtrSF_AudioChannelsSetVolume_f,
 mtrAudioChannelsSetVolume_f)
MTR_SCRIPT_FUNC_V_V(mtrSF_AudioChannelsPause, mtrAudioChannelsPause)
MTR_SCRIPT_FUNC_V_V(mtrSF_AudioChannelsResume, mtrAudioChannelsResume)
MTR_SCRIPT_FUNC_V_V(mtrSF_AudioChannelsStop, mtrAudioChannelsStop)
MTR_SCRIPT_FUNC_V_I1(mtrSF_AudioChannelsFadeOutStop,
 mtrAudioChannelsFadeOutStop)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_AudioMusicPlay, mtrAudioMusicPlay)
MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_AudioMusicFadeInPlay, mtrAudioMusicFadeInPlay)
MTR_SCRIPT_FUNC_V_I1(mtrSF_AudioMusicSetVolume, mtrAudioMusicSetVolume)
MTR_SCRIPT_FUNC_V_F1(mtrSF_AudioMusicSetVolume_f, mtrAudioMusicSetVolume_f)
MTR_SCRIPT_FUNC_V_V(mtrSF_AudioMusicPause, mtrAudioMusicPause)
MTR_SCRIPT_FUNC_V_V(mtrSF_AudioMusicResume, mtrAudioMusicResume)
MTR_SCRIPT_FUNC_V_V(mtrSF_AudioMusicStop, mtrAudioMusicStop)
MTR_SCRIPT_FUNC_V_I1(mtrSF_AudioMusicFadeOutStop, mtrAudioMusicFadeOutStop)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_AudioSoundFree, mtrAudioSoundFree)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_AudioMusicFree, mtrAudioMusicFree)

void mtrScriptsRegisterAll(void)
{
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrAudioFunctionSupported, MTR_SOURCE_MODULE);
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

        mtrScriptsRegisterFunction(mtrSF_AudioFunctionSupported,
         "AudioFunctionSupported");
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
