#ifndef MTR_AUDIO_BINDING_COMMON_H
#define MTR_AUDIO_BINDING_COMMON_H

MTR_FUNC(int, MTR_AudioFunctionSupported, const char *);
MTR_FUNC(bool, MTR_AudioInit, uint32_t, uint32_t, uint32_t, uint32_t, int, int,
 int);
MTR_FUNC(void, MTR_AudioQuit, void);
MTR_FUNC(uint32_t, MTR_AudioSoundLoad, const char *);
MTR_FUNC(uint32_t, MTR_AudioMusicLoad, const char *);
MTR_FUNC(void, MTR_AudioSoundPlay, uint32_t);
MTR_FUNC(void, MTR_AudioSoundFadeInPlay, uint32_t, int);
MTR_FUNC(void, MTR_AudioSoundSetVolume, uint32_t, int);
MTR_FUNC(void, MTR_AudioSoundSetVolume_f, uint32_t, float);
MTR_FUNC(void, MTR_AudioSoundStop, uint32_t);
MTR_FUNC(void, MTR_AudioSoundFadeOutStop, uint32_t, int);
MTR_FUNC(void, MTR_AudioChannelsSetVolume, int);
MTR_FUNC(void, MTR_AudioChannelsSetVolume_f, float);
MTR_FUNC(void, MTR_AudioChannelsPause, void);
MTR_FUNC(void, MTR_AudioChannelsResume, void);
MTR_FUNC(void, MTR_AudioChannelsStop, void);
MTR_FUNC(void, MTR_AudioChannelsFadeOutStop, int);
MTR_FUNC(void, MTR_AudioMusicPlay, uint32_t);
MTR_FUNC(void, MTR_AudioMusicFadeInPlay, uint32_t, int);
MTR_FUNC(void, MTR_AudioMusicSetVolume, int);
MTR_FUNC(void, MTR_AudioMusicSetVolume_f, float);
MTR_FUNC(void, MTR_AudioMusicPause, void);
MTR_FUNC(void, MTR_AudioMusicResume, void);
MTR_FUNC(void, MTR_AudioMusicStop, void);
MTR_FUNC(void, MTR_AudioMusicFadeOutStop, int);
MTR_FUNC(void, MTR_AudioSoundFree, uint32_t);
MTR_FUNC(void, MTR_AudioMusicFree, uint32_t);

#endif
