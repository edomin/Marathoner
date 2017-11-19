#ifndef MTR_AUDIO_BINDING_COMMON_C
#define MTR_AUDIO_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_AudioFunctionSupported, MTR_AudioFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t4I3(MTR_SF_AudioInit, MTR_AudioInit)
MTR_SCRIPT_FUNC_V_V(MTR_SF_AudioQuit, MTR_AudioQuit)
MTR_SCRIPT_FUNC_U32t_S1(MTR_SF_AudioSoundLoad, MTR_AudioSoundLoad)
MTR_SCRIPT_FUNC_U32t_S1(MTR_SF_AudioMusicLoad, MTR_AudioMusicLoad)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_AudioSoundPlay, MTR_AudioSoundPlay)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_AudioSoundFadeInPlay, MTR_AudioSoundFadeInPlay)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_AudioSoundSetVolume, MTR_AudioSoundSetVolume)
MTR_SCRIPT_FUNC_V_U32t1F1(MTR_SF_AudioSoundSetVolume_f,
 MTR_AudioSoundSetVolume_f)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_AudioSoundStop, MTR_AudioSoundStop)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_AudioSoundFadeOutStop,
 MTR_AudioSoundFadeOutStop)
MTR_SCRIPT_FUNC_V_I1(MTR_SF_AudioChannelsSetVolume, MTR_AudioChannelsSetVolume)
MTR_SCRIPT_FUNC_V_F1(MTR_SF_AudioChannelsSetVolume_f,
 MTR_AudioChannelsSetVolume_f)
MTR_SCRIPT_FUNC_V_V(MTR_SF_AudioChannelsPause, MTR_AudioChannelsPause)
MTR_SCRIPT_FUNC_V_V(MTR_SF_AudioChannelsResume, MTR_AudioChannelsResume)
MTR_SCRIPT_FUNC_V_V(MTR_SF_AudioChannelsStop, MTR_AudioChannelsStop)
MTR_SCRIPT_FUNC_V_I1(MTR_SF_AudioChannelsFadeOutStop,
 MTR_AudioChannelsFadeOutStop)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_AudioMusicPlay, MTR_AudioMusicPlay)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_AudioMusicFadeInPlay, MTR_AudioMusicFadeInPlay)
MTR_SCRIPT_FUNC_V_I1(MTR_SF_AudioMusicSetVolume, MTR_AudioMusicSetVolume)
MTR_SCRIPT_FUNC_V_F1(MTR_SF_AudioMusicSetVolume_f, MTR_AudioMusicSetVolume_f)
MTR_SCRIPT_FUNC_V_V(MTR_SF_AudioMusicPause, MTR_AudioMusicPause)
MTR_SCRIPT_FUNC_V_V(MTR_SF_AudioMusicResume, MTR_AudioMusicResume)
MTR_SCRIPT_FUNC_V_V(MTR_SF_AudioMusicStop, MTR_AudioMusicStop)
MTR_SCRIPT_FUNC_V_I1(MTR_SF_AudioMusicFadeOutStop, MTR_AudioMusicFadeOutStop)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_AudioSoundFree, MTR_AudioSoundFree)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_AudioMusicFree, MTR_AudioMusicFree)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

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

    MTR_ScriptsRegisterVariable_i("AU_FREQ_DEFAULT", MTR_AU_FREQ_DEFAULT);
    MTR_ScriptsRegisterVariable_i("AU_CHANNELS_DEFAULT",
     MTR_AU_CHANNELS_DEFAULT);
    MTR_ScriptsRegisterVariable_i("AU_CHUNK_SIZE_DEFAULT",
     MTR_AU_CHUNK_SIZE_DEFAULT);
    MTR_ScriptsRegisterVariable_i("AU_DEFAULT", MTR_AU_DEFAULT);
}

#endif
