#ifndef MTR_AUDIO_SDL2_MIXER_LUA
#define MTR_AUDIO_SDL2_MIXER_LUA

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

#define MTR_AU_FREQ_DEFAULT         0
#define MTR_AU_CHANNELS_DEFAULT     0
#define MTR_AU_CHUNK_SIZE_DEFAULT   0
#define MTR_AU_DEFAULT              0

lua_State *mtrVm;

typedef lua_State* (MTR_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MTR_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction,
 char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MTR_CALL * mtrScriptsRegisterNumericVariableFunc)(char *,
 double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MTR_CALL * mtrAudioInitFunc)(int, int, int, int, int, int, int);
mtrAudioInitFunc mtrAudioInit;

typedef void (MTR_CALL * mtrAudioQuitFunc)(void);
mtrAudioQuitFunc mtrAudioQuit;

typedef int (MTR_CALL * mtrAudioSoundLoadFunc)(const char *);
mtrAudioSoundLoadFunc mtrAudioSoundLoad;

typedef int (MTR_CALL * mtrAudioMusicLoadFunc)(const char *);
mtrAudioMusicLoadFunc mtrAudioMusicLoad;

typedef void (MTR_CALL * mtrAudioSoundPlayFunc)(int);
mtrAudioSoundPlayFunc mtrAudioSoundPlay;

typedef void (MTR_CALL * mtrAudioSoundFadeInPlayFunc)(int, int);
mtrAudioSoundFadeInPlayFunc mtrAudioSoundFadeInPlay;

typedef void (MTR_CALL * mtrAudioSoundSetVolumeFunc)(int, int);
mtrAudioSoundSetVolumeFunc mtrAudioSoundSetVolume;

typedef void (MTR_CALL * mtrAudioSoundSetVolume_fFunc)(int, float);
mtrAudioSoundSetVolume_fFunc mtrAudioSoundSetVolume_f;

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

typedef void (MTR_CALL * mtrAudioMusicPlayFunc)(int);
mtrAudioMusicPlayFunc mtrAudioMusicPlay;

typedef void (MTR_CALL * mtrAudioMusicFadeInPlayFunc)(int, int);
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

typedef void (MTR_CALL * mtrAudioSoundFreeFunc)(int);
mtrAudioSoundFreeFunc mtrAudioSoundFree;

typedef void (MTR_CALL * mtrAudioMusicFreeFunc)(int);
mtrAudioMusicFreeFunc mtrAudioMusicFree;

#endif
