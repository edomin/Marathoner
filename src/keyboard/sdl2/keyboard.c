#include "keyboard.h"

#include "marathoner/plugin_common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Keyboard_SDL2";
    report->version = MTR_VERSION_KEYBOARD_SDL2;
    report->subsystem = "keyboard";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

MTR_EXPORT bool MTR_CALL mtrKeyboardInit(void)
{
    SDL_version compiled;
    SDL_version linked;

    mtrLogWrite("Initializing keyboard support", 0, MTR_LMT_INFO);

    mtrLogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    mtrLogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&linked);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    if(SDL_WasInit(SDL_INIT_EVENTS) == 0)
        if (SDL_InitSubSystem(SDL_INIT_EVENTS) == 0)
            mtrLogWrite("SDL events subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             mtrNotify("Unable to initialize SDL events subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    else
        mtrLogWrite("SDL events subsystem already initialized", 1, MTR_LMT_INFO);

    mtrLogWrite("Getting current keyboard state", 1, MTR_LMT_INFO);
    mtrKeyboard.currentKeystate = SDL_GetKeyboardState(NULL);
    if (mtrKeyboard.currentKeystate != NULL)
    {
        mtrLogWrite("Keyboard state get", 1, MTR_LMT_INFO);
    }
    else
    {
        mtrNotify("Unable to get current keyboard state", 1, MTR_LMT_ERROR);
        return false;
    }
    mtrLogWrite("Keyboard support initialized", 0, MTR_LMT_INFO);
    return true;
}

MTR_EXPORT void MTR_CALL mtrKeyboardRefresh(void)
{
    uint16_t i;
    for (i = 0; i < SDL_NUM_SCANCODES; i++)
    {
        mtrKeyboard.previousKeystate[i] = (uint8_t)mtrKeyboard.currentKeystate[i];
    }
    SDL_PumpEvents();
}

MTR_EXPORT bool MTR_CALL mtrKeyboardPress(uint16_t key)
{
    if (key >= SDL_NUM_SCANCODES)
        return false;
    if ((mtrKeyboard.currentKeystate[key]) &&
        !(mtrKeyboard.previousKeystate[key]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

MTR_EXPORT bool MTR_CALL mtrKeyboardRelease(uint16_t key)
{
    if (key >= SDL_NUM_SCANCODES)
        return false;
    if (!(mtrKeyboard.currentKeystate[key]) &&
        (mtrKeyboard.previousKeystate[key]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

MTR_EXPORT bool MTR_CALL mtrKeyboardPressed(uint16_t key)
{
    if (key >= SDL_NUM_SCANCODES)
        return false;
    if (mtrKeyboard.currentKeystate [key])
    {
        return true;
    }
    else
    {
        return false;
    }
}
