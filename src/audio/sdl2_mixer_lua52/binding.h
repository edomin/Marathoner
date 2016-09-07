#ifndef MTR_AUDIO_SDL2_MIXER_LUA52
#define MTR_AUDIO_SDL2_MIXER_LUA52

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

#include "marathoner/plugin.h"

#define MTR_AU_FREQ_DEFAULT         0
#define MTR_AU_CHANNELS_DEFAULT     0
#define MTR_AU_CHUNK_SIZE_DEFAULT   0
#define MTR_AU_DEFAULT              0

lua_State *mtrVm;

typedef lua_State* (MRT_CALL * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (MRT_CALL * mtrScriptsRegisterFunctionFunc)(lua_CFunction,
 char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (MRT_CALL * mtrScriptsRegisterNumericVariableFunc)(char *,
 double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (MRT_CALL * mtrAudioInitFunc)(uint32_t, uint32_t, uint32_t,
 uint32_t, uint32_t, uint8_t, uint16_t);
mtrAudioInitFunc mtrAudioInit;

typedef void (MRT_CALL * mtrAudioQuitFunc)(void);
mtrAudioQuitFunc mtrAudioQuit;

typedef uint32_t (MRT_CALL * mtrAudioSoundLoadFunc)(const char *);
mtrAudioSoundLoadFunc mtrAudioSoundLoad;

typedef uint32_t (MRT_CALL * mtrAudioMusicLoadFunc)(const char *);
mtrAudioMusicLoadFunc mtrAudioMusicLoad;

typedef void (MRT_CALL * mtrAudioSoundPlayFunc)(uint32_t);
mtrAudioSoundPlayFunc mtrAudioSoundPlay;

typedef void (MRT_CALL * mtrAudioSoundFadeInPlayFunc)(uint32_t, uint32_t);
mtrAudioSoundFadeInPlayFunc mtrAudioSoundFadeInPlay;

typedef void (MRT_CALL * mtrAudioSoundSetVolumeFunc)(uint32_t, uint8_t);
mtrAudioSoundSetVolumeFunc mtrAudioSoundSetVolume;

typedef void (MRT_CALL * mtrAudioSoundSetVolume_fFunc)(uint32_t, float);
mtrAudioSoundSetVolume_fFunc mtrAudioSoundSetVolume_f;

typedef void (MRT_CALL * mtrAudioChannelsSetVolumeFunc)(uint8_t);
mtrAudioChannelsSetVolumeFunc mtrAudioChannelsSetVolume;

typedef void (MRT_CALL * mtrAudioChannelsSetVolume_fFunc)(float);
mtrAudioChannelsSetVolume_fFunc mtrAudioChannelsSetVolume_f;

typedef void (MRT_CALL * mtrAudioChannelsPauseFunc)(void);
mtrAudioChannelsPauseFunc mtrAudioChannelsPause;

typedef void (MRT_CALL * mtrAudioChannelsResumeFunc)(void);
mtrAudioChannelsResumeFunc mtrAudioChannelsResume;

typedef void (MRT_CALL * mtrAudioChannelsStopFunc)(void);
mtrAudioChannelsStopFunc mtrAudioChannelsStop;

typedef void (MRT_CALL * mtrAudioChannelsFadeOutStopFunc)(uint32_t);
mtrAudioChannelsFadeOutStopFunc mtrAudioChannelsFadeOutStop;

typedef void (MRT_CALL * mtrAudioMusicPlayFunc)(uint32_t);
mtrAudioMusicPlayFunc mtrAudioMusicPlay;

typedef void (MRT_CALL * mtrAudioMusicFadeInPlayFunc)(uint32_t, uint32_t);
mtrAudioMusicFadeInPlayFunc mtrAudioMusicFadeInPlay;

typedef void (MRT_CALL * mtrAudioMusicSetVolumeFunc)(uint8_t);
mtrAudioMusicSetVolumeFunc mtrAudioMusicSetVolume;

typedef void (MRT_CALL * mtrAudioMusicSetVolume_fFunc)(float);
mtrAudioMusicSetVolume_fFunc mtrAudioMusicSetVolume_f;

typedef void (MRT_CALL * mtrAudioMusicPauseFunc)(void);
mtrAudioMusicPauseFunc mtrAudioMusicPause;

typedef void (MRT_CALL * mtrAudioMusicResumeFunc)(void);
mtrAudioMusicResumeFunc mtrAudioMusicResume;

typedef void (MRT_CALL * mtrAudioMusicStopFunc)(void);
mtrAudioMusicStopFunc mtrAudioMusicStop;

typedef void (MRT_CALL * mtrAudioMusicFadeOutStopFunc)(uint32_t);
mtrAudioMusicFadeOutStopFunc mtrAudioMusicFadeOutStop;

typedef void (MRT_CALL * mtrAudioSoundFreeFunc)(uint32_t);
mtrAudioSoundFreeFunc mtrAudioSoundFree;

typedef void (MRT_CALL * mtrAudioMusicFreeFunc)(uint32_t);
mtrAudioMusicFreeFunc mtrAudioMusicFree;

int mtrSF_AudioInit(lua_State* l);
int mtrSF_AudioQuit(lua_State* l);
int mtrSF_AudioSoundLoad(lua_State* l);
int mtrSF_AudioMusicLoad(lua_State* l);
int mtrSF_AudioSoundPlay(lua_State* l);
int mtrSF_AudioSoundFadeInPlay(lua_State* l);
int mtrSF_AudioSoundSetVolume(lua_State* l);
int mtrSF_AudioSoundSetVolume_f(lua_State* l);
int mtrSF_AudioChannelsSetVolume(lua_State* l);
int mtrSF_AudioChannelsSetVolume_f(lua_State* l);
int mtrSF_AudioChannelsPause(lua_State* l);
int mtrSF_AudioChannelsResume(lua_State* l);
int mtrSF_AudioChannelsStop(lua_State* l);
int mtrSF_AudioChannelsFadeOutStop(lua_State* l);
int mtrSF_AudioMusicPlay(lua_State* l);
int mtrSF_AudioMusicFadeInPlay(lua_State* l);
int mtrSF_AudioMusicSetVolume(lua_State* l);
int mtrSF_AudioMusicSetVolume_f(lua_State* l);
int mtrSF_AudioMusicPause(lua_State* l);
int mtrSF_AudioMusicResume(lua_State* l);
int mtrSF_AudioMusicStop(lua_State* l);
int mtrSF_AudioMusicFadeOutStop(lua_State* l);
int mtrSF_AudioSoundFree(lua_State* l);
int mtrSF_AudioMusicFree(lua_State* l);

#endif

