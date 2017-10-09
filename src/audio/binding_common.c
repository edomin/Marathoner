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
    mtrVm = mtrScriptsGetVm();

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioQuit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioSoundLoad);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicLoad);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioSoundPlay);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioSoundFadeInPlay);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioSoundSetVolume);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioSoundSetVolume_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioSoundStop);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioSoundFadeOutStop);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioChannelsSetVolume);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioChannelsSetVolume_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioChannelsPause);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioChannelsResume);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioChannelsStop);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioChannelsFadeOutStop);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicPlay);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicFadeInPlay);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicSetVolume);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicSetVolume_f);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicPause);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicResume);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicStop);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicFadeOutStop);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioSoundFree);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, AudioMusicFree);

    mtrScriptsRegisterVariable_i("AU_FREQ_DEFAULT", MTR_AU_FREQ_DEFAULT);
    mtrScriptsRegisterVariable_i("AU_CHANNELS_DEFAULT",
     MTR_AU_CHANNELS_DEFAULT);
    mtrScriptsRegisterVariable_i("AU_CHUNK_SIZE_DEFAULT",
     MTR_AU_CHUNK_SIZE_DEFAULT);
    mtrScriptsRegisterVariable_i("AU_DEFAULT", MTR_AU_DEFAULT);
}

#endif
