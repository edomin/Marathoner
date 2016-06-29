#include "keyboard.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Keyboard_SDL2";
    report->version = 0x000000;
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

__declspec(dllexport) bool __stdcall mtrKeyboardInit(void)
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

    if(SDL_WasInit(SDL_INIT_EVENTS) != 0)
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
        mtrLogWrite("Keyboard state get", 1, MT_INFO);
    }
    else
    {
        mtrNotify("Unable to get current keyboard state", 1, MTR_LMT_ERROR);
        return false;
    }
    mtrLogWrite("Keyboard support initialized", 0, MTR_LMT_INFO);
    return true;
}

void KeyboardRefresh(void)
{
    uint16_t i;
    for (i = 0; i < SDL_NUM_SCANCODES; i++)
    {
        mtrKeyboard.previousKeystate[i] = (uint8_t)mtrKeyboard.currentKeystate[i];
    }
    SDL_PumpEvents();
}

bool KeyboardPress(uint16_t key)
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

bool KeyboardRelease(uint16_t key)
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

bool KeyboardPressed(uint16_t key)
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
