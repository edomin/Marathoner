#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Audio_SDL2_mixer_Lua";
    report->version = MTR_VERSION_AUDIO_SDL2_MIXER_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Audio_SDL2_mixer";
    report->prereqs[1] = "Script_Lua";
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT void MTR_CALL mtrPluginInit(void)
{
    bool ok;
    ok = true;

    mtrLogWrite_s("Reporting Lua compile-time version:", 3, MTR_LMT_INFO,
     LUA_RELEASE);

    mtrScriptsRegisterFunction = (mtrScriptsRegisterFunctionFunc)mtrFindFunction("Script_Lua",
     "mtrScriptsRegisterFunction");
    if (mtrScriptsRegisterFunction == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterFunction");
        ok = false;
    }
    mtrScriptsRegisterNumericVariable = (mtrScriptsRegisterNumericVariableFunc)mtrFindFunction("Script_Lua",
     "mtrScriptsRegisterNumericVariable");
    if (mtrScriptsRegisterNumericVariable == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsRegisterNumericVariable");
        ok = false;
    }
    mtrScriptsGetVm = (mtrScriptsGetVmFunc)mtrFindFunction("Script_Lua",
     "mtrScriptsGetVm");
    if (mtrScriptsGetVm == NULL)
    {
        mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
          "mtrScriptsGetVm");
        ok = false;
    }
    else
    {
        mtrVm = mtrScriptsGetVm();
        mtrAudioInit = (mtrAudioInitFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioInit");
        if (mtrAudioInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioInit");
            ok = false;
        }
        mtrAudioQuit = (mtrAudioQuitFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioQuit");
        if (mtrAudioQuit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioQuit");
            ok = false;
        }
        mtrAudioSoundLoad = (mtrAudioSoundLoadFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioSoundLoad");
        if (mtrAudioSoundLoad == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioSoundLoad");
            ok = false;
        }
        mtrAudioMusicLoad = (mtrAudioMusicLoadFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicLoad");
        if (mtrAudioMusicLoad == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicLoad");
            ok = false;
        }
        mtrAudioSoundPlay = (mtrAudioSoundPlayFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioSoundPlay");
        if (mtrAudioSoundPlay == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioSoundPlay");
            ok = false;
        }
        mtrAudioSoundFadeInPlay = (mtrAudioSoundFadeInPlayFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioSoundFadeInPlay");
        if (mtrAudioSoundFadeInPlay == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioSoundFadeInPlay");
            ok = false;
        }
        mtrAudioSoundSetVolume = (mtrAudioSoundSetVolumeFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioSoundSetVolume");
        if (mtrAudioSoundSetVolume == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioSoundSetVolume");
            ok = false;
        }
        mtrAudioSoundSetVolume_f = (mtrAudioSoundSetVolume_fFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioSoundSetVolume_f");
        if (mtrAudioSoundSetVolume_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioSoundSetVolume_f");
            ok = false;
        }
        mtrAudioChannelsSetVolume = (mtrAudioChannelsSetVolumeFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioChannelsSetVolume");
        if (mtrAudioChannelsSetVolume == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioChannelsSetVolume");
            ok = false;
        }
        mtrAudioChannelsSetVolume_f = (mtrAudioChannelsSetVolume_fFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioChannelsSetVolume_f");
        if (mtrAudioChannelsSetVolume_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioChannelsSetVolume_f");
            ok = false;
        }
        mtrAudioChannelsPause = (mtrAudioChannelsPauseFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioChannelsPause");
        if (mtrAudioChannelsPause == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioChannelsPause");
            ok = false;
        }
        mtrAudioChannelsResume = (mtrAudioChannelsResumeFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioChannelsResume");
        if (mtrAudioChannelsResume == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioChannelsResume");
            ok = false;
        }
        mtrAudioChannelsStop = (mtrAudioChannelsStopFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioChannelsStop");
        if (mtrAudioChannelsStop == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioChannelsStop");
            ok = false;
        }
        mtrAudioChannelsFadeOutStop = (mtrAudioChannelsFadeOutStopFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioChannelsFadeOutStop");
        if (mtrAudioChannelsFadeOutStop == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioChannelsFadeOutStop");
            ok = false;
        }
        mtrAudioMusicPlay = (mtrAudioMusicPlayFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicPlay");
        if (mtrAudioMusicPlay == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicPlay");
            ok = false;
        }
        mtrAudioMusicFadeInPlay = (mtrAudioMusicFadeInPlayFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicFadeInPlay");
        if (mtrAudioMusicFadeInPlay == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicFadeInPlay");
            ok = false;
        }
        mtrAudioMusicSetVolume = (mtrAudioMusicSetVolumeFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicSetVolume");
        if (mtrAudioMusicSetVolume == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicSetVolume");
            ok = false;
        }
        mtrAudioMusicSetVolume_f = (mtrAudioMusicSetVolume_fFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicSetVolume_f");
        if (mtrAudioMusicSetVolume_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicSetVolume_f");
            ok = false;
        }
        mtrAudioMusicPause = (mtrAudioMusicPauseFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicPause");
        if (mtrAudioMusicPause == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicPause");
            ok = false;
        }
        mtrAudioMusicResume = (mtrAudioMusicResumeFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicResume");
        if (mtrAudioMusicResume == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicResume");
            ok = false;
        }
        mtrAudioMusicStop = (mtrAudioMusicStopFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicStop");
        if (mtrAudioMusicStop == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicStop");
            ok = false;
        }
        mtrAudioMusicFadeOutStop = (mtrAudioMusicFadeOutStopFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicFadeOutStop");
        if (mtrAudioMusicFadeOutStop == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicFadeOutStop");
            ok = false;
        }
        mtrAudioSoundFree = (mtrAudioSoundFreeFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioSoundFree");
        if (mtrAudioSoundFree == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioSoundFree");
            ok = false;
        }
        mtrAudioMusicFree = (mtrAudioMusicFreeFunc)mtrFindFunction("Audio_SDL2_mixer",
          "mtrAudioMusicFree");
        if (mtrAudioMusicFree == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrAudioMusicFree");
            ok = false;
        }

        if (ok)
        {
            mtrScriptsRegisterNumericVariable("AU_FREQ_DEFAULT",
             MTR_AU_FREQ_DEFAULT);
            mtrScriptsRegisterNumericVariable("AU_CHANNELS_DEFAULT",
             MTR_AU_CHANNELS_DEFAULT);
            mtrScriptsRegisterNumericVariable("AU_CHUNK_SIZE_DEFAULT",
             MTR_AU_CHUNK_SIZE_DEFAULT);
            mtrScriptsRegisterNumericVariable("AU_DEFAULT", MTR_AU_DEFAULT);

            mtrScriptsRegisterFunction(mtrSF_AudioInit, "AudioInit");
            mtrScriptsRegisterFunction(mtrSF_AudioQuit, "AudioQuit");
            mtrScriptsRegisterFunction(mtrSF_AudioSoundLoad, "AudioSoundLoad");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicLoad, "AudioMusicLoad");
            mtrScriptsRegisterFunction(mtrSF_AudioSoundPlay, "AudioSoundPlay");
            mtrScriptsRegisterFunction(mtrSF_AudioSoundFadeInPlay,
             "AudioSoundFadeInPlay");
            mtrScriptsRegisterFunction(mtrSF_AudioSoundSetVolume,
             "AudioSoundSetVolume");
            mtrScriptsRegisterFunction(mtrSF_AudioSoundSetVolume_f,
             "AudioSoundSetVolume_f");
            mtrScriptsRegisterFunction(mtrSF_AudioChannelsSetVolume,
             "AudioChannelsSetVolume");
            mtrScriptsRegisterFunction(mtrSF_AudioChannelsSetVolume_f,
             "AudioChannelsSetVolume_f");
            mtrScriptsRegisterFunction(mtrSF_AudioChannelsPause,
             "AudioChannelsPause");
            mtrScriptsRegisterFunction(mtrSF_AudioChannelsResume,
             "AudioChannelsResume");
            mtrScriptsRegisterFunction(mtrSF_AudioChannelsStop,
             "AudioChannelsStop");
            mtrScriptsRegisterFunction(mtrSF_AudioChannelsFadeOutStop,
             "AudioChannelsFadeOutStop");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicPlay,
             "AudioMusicPlay");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicFadeInPlay,
             "AudioMusicFadeInPlay");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicSetVolume,
             "AudioMusicSetVolume");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicSetVolume_f,
             "AudioMusicSetVolume_f");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicPause,
             "AudioMusicPause");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicResume,
             "AudioMusicResume");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicStop, "AudioMusicStop");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicFadeOutStop,
             "AudioMusicFadeOutStop");
            mtrScriptsRegisterFunction(mtrSF_AudioSoundFree, "AudioSoundFree");
            mtrScriptsRegisterFunction(mtrSF_AudioMusicFree, "AudioMusicFree");
        }
        else
        {
            mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
        }
    }
}
