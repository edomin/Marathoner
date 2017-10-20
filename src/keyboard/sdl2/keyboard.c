#include "keyboard.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Keyboard, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Keyboard_SDL2";
    report->version = MTR_VERSION_KEYBOARD_SDL2;
    report->subsystem = "keyboard";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

/*fa MTR_KeyboardInit yes */
MTR_EXPORT bool MTR_CALL MTR_KeyboardInit(void)
{
    SDL_version compiled;
    SDL_version linked;

    MTR_LogWrite("Initializing keyboard support", 0, MTR_LMT_INFO);

    MTR_LogWrite("Reporting SDL compile-time version:", 1, MTR_LMT_INFO);
    SDL_VERSION(&compiled);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, compiled.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, compiled.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, compiled.patch);
    MTR_LogWrite("Reporting SDL linked version:", 1, MTR_LMT_INFO);
    SDL_GetVersion(&linked);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, linked.major);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, linked.minor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, linked.patch);

    if(SDL_WasInit(SDL_INIT_EVENTS) == 0)
        if (SDL_InitSubSystem(SDL_INIT_EVENTS) == 0)
            MTR_LogWrite("SDL events subsystem initialized", 1, MTR_LMT_INFO);
        else
        {
             MTR_Notify("Unable to initialize SDL events subsystem", 1,
              MTR_LMT_ERROR);
              return false;
        }
    else
        MTR_LogWrite("SDL events subsystem already initialized", 1, MTR_LMT_INFO);

    MTR_LogWrite("Getting current keyboard state", 1, MTR_LMT_INFO);
    mtrKeyboard.currentKeystate = SDL_GetKeyboardState(NULL);
    if (mtrKeyboard.currentKeystate != NULL)
    {
        MTR_LogWrite("Keyboard state get", 1, MTR_LMT_INFO);
    }
    else
    {
        MTR_Notify("Unable to get current keyboard state", 1, MTR_LMT_ERROR);
        return false;
    }
    MTR_LogWrite("Keyboard support initialized", 0, MTR_LMT_INFO);

    mtrKeyboardInited = true;
    return true;
}

/*fa MTR_KeyboardRefresh yes */
MTR_EXPORT void MTR_CALL MTR_KeyboardRefresh(void)
{
    int i;
    MTR_KEYBOARD_CHECK_IF_NOT_INITED();

    for (i = 0; i < SDL_NUM_SCANCODES; i++)
    {
        mtrKeyboard.previousKeystate[i] = (uint8_t)mtrKeyboard.currentKeystate[i];
    }
    SDL_PumpEvents();
}

/*fa MTR_KeyboardPress yes */
MTR_EXPORT bool MTR_CALL MTR_KeyboardPress(int key)
{
    MTR_KEYBOARD_CHECK_IF_NOT_INITED(false);

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

/*fa MTR_KeyboardRelease yes */
MTR_EXPORT bool MTR_CALL MTR_KeyboardRelease(int key)
{
    MTR_KEYBOARD_CHECK_IF_NOT_INITED(false);

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

/*fa MTR_KeyboardPressed yes */
MTR_EXPORT bool MTR_CALL MTR_KeyboardPressed(int key)
{
    MTR_KEYBOARD_CHECK_IF_NOT_INITED(false);

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

/*fa MTR_KeyboardInputChar yes */
MTR_EXPORT char *MTR_CALL MTR_KeyboardInputChar(void)
{
    SDL_Event  event;
    int        numEvents;
    MTR_KEYBOARD_CHECK_IF_NOT_INITED(NULL);

    numEvents = SDL_PeepEvents(&event, 1, SDL_GETEVENT, SDL_TEXTINPUT,
     SDL_TEXTINPUT);

    if (numEvents == 0)
        return NULL;

    return memcpy(mtrKeyboard.utf8char, event.text.text,
     SDL_TEXTINPUTEVENT_TEXT_SIZE);
}
