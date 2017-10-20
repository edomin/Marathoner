-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(AudioInit, "MTR_AudioInit", AudioFunctionSupported);
fa.FunctionSupported(AudioQuit, "MTR_AudioQuit", AudioFunctionSupported);
fa.FunctionSupported(AudioSoundLoad, "MTR_AudioSoundLoad",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicLoad, "MTR_AudioMusicLoad",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundPlay, "MTR_AudioSoundPlay",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundFadeInPlay, "MTR_AudioSoundFadeInPlay",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundSetVolume, "MTR_AudioSoundSetVolume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundSetVolume_f, "MTR_AudioSoundSetVolume_f",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundStop, "MTR_AudioSoundStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundFadeOutStop, "MTR_AudioSoundFadeOutStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsSetVolume, "MTR_AudioChannelsSetVolume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsSetVolume_f, "MTR_AudioChannelsSetVolume_f",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsPause, "MTR_AudioChannelsPause",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsResume, "MTR_AudioChannelsResume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsStop, "MTR_AudioChannelsStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsFadeOutStop, "MTR_AudioChannelsFadeOutStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicPlay, "MTR_AudioMusicPlay",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicFadeInPlay, "MTR_AudioMusicFadeInPlay",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicSetVolume, "MTR_AudioMusicSetVolume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicSetVolume_f, "MTR_AudioMusicSetVolume_f",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicPause, "MTR_AudioMusicPause",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicResume, "MTR_AudioMusicResume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicStop, "MTR_AudioMusicStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicFadeOutStop, "MTR_AudioMusicFadeOutStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundFree, "MTR_AudioSoundFree",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicFree, "MTR_AudioMusicFree",
 AudioFunctionSupported);
