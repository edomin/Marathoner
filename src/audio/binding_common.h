#ifndef MTR_AUDIO_BINDING_COMMON_H
#define MTR_AUDIO_BINDING_COMMON_H

typedef bool (MTR_CALL * mtrAudioInitFunc)(uint32_t, uint32_t, uint32_t,
 uint32_t, int, int, int);
mtrAudioInitFunc mtrAudioInit;

typedef void (MTR_CALL * mtrAudioQuitFunc)(void);
mtrAudioQuitFunc mtrAudioQuit;

typedef uint32_t (MTR_CALL * mtrAudioSoundLoadFunc)(const char *);
mtrAudioSoundLoadFunc mtrAudioSoundLoad;

typedef uint32_t (MTR_CALL * mtrAudioMusicLoadFunc)(const char *);
mtrAudioMusicLoadFunc mtrAudioMusicLoad;

typedef void (MTR_CALL * mtrAudioSoundPlayFunc)(uint32_t);
mtrAudioSoundPlayFunc mtrAudioSoundPlay;

typedef void (MTR_CALL * mtrAudioSoundFadeInPlayFunc)(uint32_t, int);
mtrAudioSoundFadeInPlayFunc mtrAudioSoundFadeInPlay;

typedef void (MTR_CALL * mtrAudioSoundSetVolumeFunc)(uint32_t, int);
mtrAudioSoundSetVolumeFunc mtrAudioSoundSetVolume;

typedef void (MTR_CALL * mtrAudioSoundSetVolume_fFunc)(uint32_t, float);
mtrAudioSoundSetVolume_fFunc mtrAudioSoundSetVolume_f;

typedef void (MTR_CALL * mtrAudioSoundStopFunc)(uint32_t);
mtrAudioSoundStopFunc mtrAudioSoundStop;

typedef void (MTR_CALL * mtrAudioSoundFadeOutStopFunc)(uint32_t, int);
mtrAudioSoundFadeOutStopFunc mtrAudioSoundFadeOutStop;

typedef void (MTR_CALL * mtrAudioChannelsSetVolumeFunc)(int);
mtrAudioChannelsSetVolumeFunc mtrAudioChannelsSetVolume;

typedef void (MTR_CALL * mtrAudioChannelsSetVolume_fFunc)(float);
mtrAudioChannelsSetVolume_fFunc mtrAudioChannelsSetVolume_f;

typedef void (MTR_CALL * mtrAudioChannelsPauseFunc)(void);
mtrAudioChannelsPauseFunc mtrAudioChannelsPause;

typedef void (MTR_CALL * mtrAudioChannelsResumeFunc)(void);
mtrAudioChannelsResumeFunc mtrAudioChannelsResume;

typedef void (MTR_CALL * mtrAudioChannelsStopFunc)(void);
mtrAudioChannelsStopFunc mtrAudioChannelsStop;

typedef void (MTR_CALL * mtrAudioChannelsFadeOutStopFunc)(int);
mtrAudioChannelsFadeOutStopFunc mtrAudioChannelsFadeOutStop;

typedef void (MTR_CALL * mtrAudioMusicPlayFunc)(uint32_t);
mtrAudioMusicPlayFunc mtrAudioMusicPlay;

typedef void (MTR_CALL * mtrAudioMusicFadeInPlayFunc)(uint32_t, int);
mtrAudioMusicFadeInPlayFunc mtrAudioMusicFadeInPlay;

typedef void (MTR_CALL * mtrAudioMusicSetVolumeFunc)(int);
mtrAudioMusicSetVolumeFunc mtrAudioMusicSetVolume;

typedef void (MTR_CALL * mtrAudioMusicSetVolume_fFunc)(float);
mtrAudioMusicSetVolume_fFunc mtrAudioMusicSetVolume_f;

typedef void (MTR_CALL * mtrAudioMusicPauseFunc)(void);
mtrAudioMusicPauseFunc mtrAudioMusicPause;

typedef void (MTR_CALL * mtrAudioMusicResumeFunc)(void);
mtrAudioMusicResumeFunc mtrAudioMusicResume;

typedef void (MTR_CALL * mtrAudioMusicStopFunc)(void);
mtrAudioMusicStopFunc mtrAudioMusicStop;

typedef void (MTR_CALL * mtrAudioMusicFadeOutStopFunc)(int);
mtrAudioMusicFadeOutStopFunc mtrAudioMusicFadeOutStop;

typedef void (MTR_CALL * mtrAudioSoundFreeFunc)(uint32_t);
mtrAudioSoundFreeFunc mtrAudioSoundFree;

typedef void (MTR_CALL * mtrAudioMusicFreeFunc)(uint32_t);
mtrAudioMusicFreeFunc mtrAudioMusicFree;

#endif
