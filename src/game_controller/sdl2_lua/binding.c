#include "binding.h"

#include "marathoner/plugin_common.c"
#include "../binding_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Game_Controller_SDL2_Lua";
    report->version = MTR_VERSION_GAME_CONTROLLER_SDL2_LUA;
    report->subsystem = "binding";
    report->prereqsCount = 2;
    report->prereqs = malloc(sizeof(char *) * report->prereqsCount);
    report->prereqs[0] = "Game_Controller_SDL2";
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
        mtrGameControllerInit = (mtrGameControllerInitFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerInit");
        if (mtrGameControllerInit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerInit");
            ok = false;
        }
        mtrGameControllerQuit = (mtrGameControllerQuitFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerQuit");
        if (mtrGameControllerQuit == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerQuit");
            ok = false;
        }
        mtrGameControllerRefresh = (mtrGameControllerRefreshFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerRefresh");
        if (mtrGameControllerRefresh == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerRefresh");
            ok = false;
        }
        mtrGameControllerButtonPress = (mtrGameControllerButtonPressFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerButtonPress");
        if (mtrGameControllerButtonPress == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerButtonPress");
            ok = false;
        }
        mtrGameControllerButtonRelease = (mtrGameControllerButtonReleaseFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerButtonRelease");
        if (mtrGameControllerButtonRelease == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerButtonRelease");
            ok = false;
        }
        mtrGameControllerButtonPressed = (mtrGameControllerButtonPressedFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerButtonPressed");
        if (mtrGameControllerButtonPressed == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerButtonPressed");
            ok = false;
        }
        mtrGameControllerGetAxis = (mtrGameControllerGetAxisFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerGetAxis");
        if (mtrGameControllerGetAxis == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerGetAxis");
            ok = false;
        }
        mtrGameControllerGetAxis_f = (mtrGameControllerGetAxis_fFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerGetAxis_f");
        if (mtrGameControllerGetAxis_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerGetAxis_f");
            ok = false;
        }
        mtrGameControllerGetAxisDelta = (mtrGameControllerGetAxisDeltaFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerGetAxisDelta");
        if (mtrGameControllerGetAxisDelta == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerGetAxisDelta");
            ok = false;
        }
        mtrGameControllerGetAxisDelta_f = (mtrGameControllerGetAxisDelta_fFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerGetAxisDelta_f");
        if (mtrGameControllerGetAxisDelta_f == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerGetAxisDelta_f");
            ok = false;
        }
        mtrGameControllerGetTrackballDeltaX = (mtrGameControllerGetTrackballDeltaXFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerGetTrackballDeltaX");
        if (mtrGameControllerGetTrackballDeltaX == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerGetTrackballDeltaX");
            ok = false;
        }
        mtrGameControllerGetTrackballDeltaY = (mtrGameControllerGetTrackballDeltaYFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerGetTrackballDeltaY");
        if (mtrGameControllerGetTrackballDeltaY == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerGetTrackballDeltaY");
            ok = false;
        }
        mtrGameControllerGetTrackballDeltaXY = (mtrGameControllerGetTrackballDeltaXYFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerGetTrackballDeltaXY");
        if (mtrGameControllerGetTrackballDeltaXY == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerGetTrackballDeltaXY");
            ok = false;
        }
        mtrGameControllerGetPovHat = (mtrGameControllerGetPovHatFunc)mtrFindFunction("Game_Controller_SDL2",
          "mtrGameControllerGetPovHat");
        if (mtrGameControllerGetPovHat == NULL)
        {
            mtrLogWrite_s("Unable to load function", 3, MTR_LMT_ERROR,
              "mtrGameControllerGetPovHat");
            ok = false;
        }
        if (ok)
        {
            mtrScriptsRegisterNumericVariable("POVHAT_CENTER",
             MTR_POVHAT_CENTER);
            mtrScriptsRegisterNumericVariable("POVHAT_UP", MTR_POVHAT_UP);
            mtrScriptsRegisterNumericVariable("POVHAT_DOWN", MTR_POVHAT_DOWN);
            mtrScriptsRegisterNumericVariable("POVHAT_LEFT", MTR_POVHAT_LEFT);
            mtrScriptsRegisterNumericVariable("POVHAT_RIGHT", MTR_POVHAT_RIGHT);
            mtrScriptsRegisterNumericVariable("POVHAT_UP_LEFT",
             MTR_POVHAT_UP_LEFT);
            mtrScriptsRegisterNumericVariable("POVHAT_UP_RIGHT",
             MTR_POVHAT_UP_RIGHT);
            mtrScriptsRegisterNumericVariable("POVHAT_DOWN_LEFT",
             MTR_POVHAT_DOWN_LEFT);
            mtrScriptsRegisterNumericVariable("POVHAT_DOWN_RIGHT",
             MTR_POVHAT_DOWN_RIGHT);
            mtrScriptsRegisterFunction(mtrSF_GameControllerInit,
             "GameControllerInit");
            mtrScriptsRegisterFunction(mtrSF_GameControllerQuit,
             "GameControllerQuit");
            mtrScriptsRegisterFunction(mtrSF_GameControllerRefresh,
             "GameControllerRefresh");
            mtrScriptsRegisterFunction(mtrSF_GameControllerButtonPress,
             "GameControllerButtonPress");
            mtrScriptsRegisterFunction(mtrSF_GameControllerButtonRelease,
             "GameControllerButtonRelease");
            mtrScriptsRegisterFunction(mtrSF_GameControllerButtonPressed,
             "GameControllerButtonPressed");
            mtrScriptsRegisterFunction(mtrSF_GameControllerGetAxis,
             "GameControllerGetAxis");
            mtrScriptsRegisterFunction(mtrSF_GameControllerGetAxis_f,
             "GameControllerGetAxis_f");
            mtrScriptsRegisterFunction(mtrSF_GameControllerGetAxisDelta,
             "GameControllerGetAxisDelta");
            mtrScriptsRegisterFunction(mtrSF_GameControllerGetAxisDelta_f,
             "GameControllerGetAxisDelta_f");
            mtrScriptsRegisterFunction(mtrSF_GameControllerGetTrackballDeltaX,
             "GameControllerGetTrackballDeltaX");
            mtrScriptsRegisterFunction(mtrSF_GameControllerGetTrackballDeltaY,
             "GameControllerGetTrackballDeltaY");
            mtrScriptsRegisterFunction(mtrSF_GameControllerGetTrackballDeltaXY,
             "GameControllerGetTrackballDeltaXY");
            mtrScriptsRegisterFunction(mtrSF_GameControllerGetPovHat,
             "GameControllerGetPovHat");
        }
        else
        {
            mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
        }
    }
}