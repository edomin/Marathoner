-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(AudioInit, "mtrAudioInit", AudioFunctionSupported);
fa.FunctionSupported(AudioQuit, "mtrAudioQuit", AudioFunctionSupported);
fa.FunctionSupported(AudioSoundLoad, "mtrAudioSoundLoad",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicLoad, "mtrAudioMusicLoad",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundPlay, "mtrAudioSoundPlay",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundFadeInPlay, "mtrAudioSoundFadeInPlay",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundSetVolume, "mtrAudioSoundSetVolume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundSetVolume_f, "mtrAudioSoundSetVolume_f",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundStop, "mtrAudioSoundStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundFadeOutStop, "mtrAudioSoundFadeOutStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsSetVolume, "mtrAudioChannelsSetVolume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsSetVolume_f, "mtrAudioChannelsSetVolume_f",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsPause, "mtrAudioChannelsPause",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsResume, "mtrAudioChannelsResume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsStop, "mtrAudioChannelsStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioChannelsFadeOutStop, "mtrAudioChannelsFadeOutStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicPlay, "mtrAudioMusicPlay",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicFadeInPlay, "mtrAudioMusicFadeInPlay",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicSetVolume, "mtrAudioMusicSetVolume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicSetVolume_f, "mtrAudioMusicSetVolume_f",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicPause, "mtrAudioMusicPause",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicResume, "mtrAudioMusicResume",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicStop, "mtrAudioMusicStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicFadeOutStop, "mtrAudioMusicFadeOutStop",
 AudioFunctionSupported);
fa.FunctionSupported(AudioSoundFree, "mtrAudioSoundFree",
 AudioFunctionSupported);
fa.FunctionSupported(AudioMusicFree, "mtrAudioMusicFree",
 AudioFunctionSupported);
