#ifndef MTR_AUDIO_BINDING_COMMON_H
#define MTR_AUDIO_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_AudioFunctionSupportedFunc)(const char *);
MTR_AudioFunctionSupportedFunc MTR_AudioFunctionSupported;

typedef bool (MTR_CALL * MTR_AudioInitFunc)(uint32_t, uint32_t, uint32_t,
 uint32_t, int, int, int);
MTR_AudioInitFunc MTR_AudioInit;

typedef void (MTR_CALL * MTR_AudioQuitFunc)(void);
MTR_AudioQuitFunc MTR_AudioQuit;

typedef uint32_t (MTR_CALL * MTR_AudioSoundLoadFunc)(const char *);
MTR_AudioSoundLoadFunc MTR_AudioSoundLoad;

typedef uint32_t (MTR_CALL * MTR_AudioMusicLoadFunc)(const char *);
MTR_AudioMusicLoadFunc MTR_AudioMusicLoad;

typedef void (MTR_CALL * MTR_AudioSoundPlayFunc)(uint32_t);
MTR_AudioSoundPlayFunc MTR_AudioSoundPlay;

typedef void (MTR_CALL * MTR_AudioSoundFadeInPlayFunc)(uint32_t, int);
MTR_AudioSoundFadeInPlayFunc MTR_AudioSoundFadeInPlay;

typedef void (MTR_CALL * MTR_AudioSoundSetVolumeFunc)(uint32_t, int);
MTR_AudioSoundSetVolumeFunc MTR_AudioSoundSetVolume;

typedef void (MTR_CALL * MTR_AudioSoundSetVolume_fFunc)(uint32_t, float);
MTR_AudioSoundSetVolume_fFunc MTR_AudioSoundSetVolume_f;

typedef void (MTR_CALL * MTR_AudioSoundStopFunc)(uint32_t);
MTR_AudioSoundStopFunc MTR_AudioSoundStop;

typedef void (MTR_CALL * MTR_AudioSoundFadeOutStopFunc)(uint32_t, int);
MTR_AudioSoundFadeOutStopFunc MTR_AudioSoundFadeOutStop;

typedef void (MTR_CALL * MTR_AudioChannelsSetVolumeFunc)(int);
MTR_AudioChannelsSetVolumeFunc MTR_AudioChannelsSetVolume;

typedef void (MTR_CALL * MTR_AudioChannelsSetVolume_fFunc)(float);
MTR_AudioChannelsSetVolume_fFunc MTR_AudioChannelsSetVolume_f;

typedef void (MTR_CALL * MTR_AudioChannelsPauseFunc)(void);
MTR_AudioChannelsPauseFunc MTR_AudioChannelsPause;

typedef void (MTR_CALL * MTR_AudioChannelsResumeFunc)(void);
MTR_AudioChannelsResumeFunc MTR_AudioChannelsResume;

typedef void (MTR_CALL * MTR_AudioChannelsStopFunc)(void);
MTR_AudioChannelsStopFunc MTR_AudioChannelsStop;

typedef void (MTR_CALL * MTR_AudioChannelsFadeOutStopFunc)(int);
MTR_AudioChannelsFadeOutStopFunc MTR_AudioChannelsFadeOutStop;

typedef void (MTR_CALL * MTR_AudioMusicPlayFunc)(uint32_t);
MTR_AudioMusicPlayFunc MTR_AudioMusicPlay;

typedef void (MTR_CALL * MTR_AudioMusicFadeInPlayFunc)(uint32_t, int);
MTR_AudioMusicFadeInPlayFunc MTR_AudioMusicFadeInPlay;

typedef void (MTR_CALL * MTR_AudioMusicSetVolumeFunc)(int);
MTR_AudioMusicSetVolumeFunc MTR_AudioMusicSetVolume;

typedef void (MTR_CALL * MTR_AudioMusicSetVolume_fFunc)(float);
MTR_AudioMusicSetVolume_fFunc MTR_AudioMusicSetVolume_f;

typedef void (MTR_CALL * MTR_AudioMusicPauseFunc)(void);
MTR_AudioMusicPauseFunc MTR_AudioMusicPause;

typedef void (MTR_CALL * MTR_AudioMusicResumeFunc)(void);
MTR_AudioMusicResumeFunc MTR_AudioMusicResume;

typedef void (MTR_CALL * MTR_AudioMusicStopFunc)(void);
MTR_AudioMusicStopFunc MTR_AudioMusicStop;

typedef void (MTR_CALL * MTR_AudioMusicFadeOutStopFunc)(int);
MTR_AudioMusicFadeOutStopFunc MTR_AudioMusicFadeOutStop;

typedef void (MTR_CALL * MTR_AudioSoundFreeFunc)(uint32_t);
MTR_AudioSoundFreeFunc MTR_AudioSoundFree;

typedef void (MTR_CALL * MTR_AudioMusicFreeFunc)(uint32_t);
MTR_AudioMusicFreeFunc MTR_AudioMusicFree;

#endif
