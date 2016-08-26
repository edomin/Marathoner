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

typedef lua_State* (__stdcall * mtrScriptsGetVmFunc)(void);
mtrScriptsGetVmFunc mtrScriptsGetVm;

typedef void (__stdcall * mtrScriptsRegisterFunctionFunc)(lua_CFunction,
 char *);
mtrScriptsRegisterFunctionFunc mtrScriptsRegisterFunction;

typedef void (__stdcall * mtrScriptsRegisterNumericVariableFunc)(char *,
 double);
mtrScriptsRegisterNumericVariableFunc mtrScriptsRegisterNumericVariable;

typedef bool (__stdcall * mtrAudioInitFunc)(uint32_t, uint32_t, uint32_t,
 uint32_t, uint32_t, uint8_t, uint16_t);
mtrAudioInitFunc mtrAudioInit;

typedef void (__stdcall * mtrAudioQuitFunc)(void);
mtrAudioQuitFunc mtrAudioQuit;

typedef uint32_t (__stdcall * mtrAudioSoundLoadFunc)(const char *);
mtrAudioSoundLoadFunc mtrAudioSoundLoad;

typedef uint32_t (__stdcall * mtrAudioMusicLoadFunc)(const char *);
mtrAudioMusicLoadFunc mtrAudioMusicLoad;

typedef void (__stdcall * mtrAudioSoundPlayFunc)(uint32_t);
mtrAudioSoundPlayFunc mtrAudioSoundPlay;

typedef void (__stdcall * mtrAudioSoundFadeInPlayFunc)(uint32_t, uint32_t);
mtrAudioSoundFadeInPlayFunc mtrAudioSoundFadeInPlay;

typedef void (__stdcall * mtrAudioSoundSetVolumeFunc)(uint32_t, uint8_t);
mtrAudioSoundSetVolumeFunc mtrAudioSoundSetVolume;

typedef void (__stdcall * mtrAudioSoundSetVolume_fFunc)(uint32_t, float);
mtrAudioSoundSetVolume_fFunc mtrAudioSoundSetVolume_f;

typedef void (__stdcall * mtrAudioChannelsSetVolumeFunc)(uint8_t);
mtrAudioChannelsSetVolumeFunc mtrAudioChannelsSetVolume;

typedef void (__stdcall * mtrAudioChannelsSetVolume_fFunc)(float);
mtrAudioChannelsSetVolume_fFunc mtrAudioChannelsSetVolume_f;

typedef void (__stdcall * mtrAudioChannelsPauseFunc)(void);
mtrAudioChannelsPauseFunc mtrAudioChannelsPause;

typedef void (__stdcall * mtrAudioChannelsResumeFunc)(void);
mtrAudioChannelsResumeFunc mtrAudioChannelsResume;

typedef void (__stdcall * mtrAudioChannelsStopFunc)(void);
mtrAudioChannelsStopFunc mtrAudioChannelsStop;

typedef void (__stdcall * mtrAudioChannelsFadeOutStopFunc)(uint32_t);
mtrAudioChannelsFadeOutStopFunc mtrAudioChannelsFadeOutStop;

typedef void (__stdcall * mtrAudioMusicPlayFunc)(uint32_t);
mtrAudioMusicPlayFunc mtrAudioMusicPlay;

typedef void (__stdcall * mtrAudioMusicFadeInPlayFunc)(uint32_t, uint32_t);
mtrAudioMusicFadeInPlayFunc mtrAudioMusicFadeInPlay;

typedef void (__stdcall * mtrAudioMusicSetVolumeFunc)(uint8_t);
mtrAudioMusicSetVolumeFunc mtrAudioMusicSetVolume;

typedef void (__stdcall * mtrAudioMusicSetVolume_fFunc)(float);
mtrAudioMusicSetVolume_fFunc mtrAudioMusicSetVolume_f;

typedef void (__stdcall * mtrAudioMusicPauseFunc)(void);
mtrAudioMusicPauseFunc mtrAudioMusicPause;

typedef void (__stdcall * mtrAudioMusicResumeFunc)(void);
mtrAudioMusicResumeFunc mtrAudioMusicResume;

typedef void (__stdcall * mtrAudioMusicStopFunc)(void);
mtrAudioMusicStopFunc mtrAudioMusicStop;

typedef void (__stdcall * mtrAudioMusicFadeOutStopFunc)(uint32_t);
mtrAudioMusicFadeOutStopFunc mtrAudioMusicFadeOutStop;

typedef void (__stdcall * mtrAudioSoundFreeFunc)(uint32_t);
mtrAudioSoundFreeFunc mtrAudioSoundFree;

typedef void (__stdcall * mtrAudioMusicFreeFunc)(uint32_t);
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

