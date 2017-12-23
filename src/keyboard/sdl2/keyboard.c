#include "keyboard.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Keyboard, FA_FUNCTIONS_COUNT)

/*fa MTR_KeyboardInit yes */
MTR_DCLSPC bool MTR_CALL MTR_KeyboardInit(void)
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
MTR_DCLSPC void MTR_CALL MTR_KeyboardRefresh(void)
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
MTR_DCLSPC bool MTR_CALL MTR_KeyboardPress(int key)
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
MTR_DCLSPC bool MTR_CALL MTR_KeyboardRelease(int key)
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
MTR_DCLSPC bool MTR_CALL MTR_KeyboardPressed(int key)
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

/*fa MTR_KeyboardArrowsGetAxes yes */
MTR_DCLSPC void MTR_CALL MTR_KeyboardArrowsGetAxes(int keyUp, int keyDown,
 int keyLeft, int keyRight, int *hsign, int *vsign)
{
    MTR_KEYBOARD_CHECK_IF_NOT_INITED();
    bool upPressed;
    bool downPressed;
    bool leftPressed;
    bool rightPressed;

    upPressed = MTR_KeyboardPressed(keyUp);
    downPressed = MTR_KeyboardPressed(keyDown);
    leftPressed = MTR_KeyboardPressed(keyLeft);
    rightPressed = MTR_KeyboardPressed(keyRight);

    if (upPressed) {
        if (downPressed)
            *vsign = 0;
        else
            *vsign = -1;
    } else {
        if (downPressed)
            *vsign = 1;
        else
            *vsign = 0;
    }

    if (leftPressed) {
        if (rightPressed)
            *hsign = 0;
        else
            *hsign = -1;
    } else {
        if (rightPressed)
            *hsign = 1;
        else
            *hsign = 0;
    }
}

/*fa MTR_KeyboardArrowsGetAxis yes */
MTR_DCLSPC int MTR_CALL MTR_KeyboardArrowsGetAxis(int keyMin, int keyMax)
{
    MTR_KEYBOARD_CHECK_IF_NOT_INITED(0);
    bool minPressed;
    bool maxPressed;

    minPressed = MTR_KeyboardPressed(keyMin);
    maxPressed = MTR_KeyboardPressed(keyMax);

    if (minPressed) {
        if (maxPressed)
            return 0;
        else
            return -1;
    } else {
        if (maxPressed)
            return 1;
        else
            return 0;
    }

    return 0;
}

/*fa MTR_KeyboardArrowsGetDirection yes */
MTR_DCLSPC int MTR_CALL MTR_KeyboardArrowsGetDirection(int keyUp, int keyDown,
 int keyLeft, int keyRight)
{
    MTR_KEYBOARD_CHECK_IF_NOT_INITED(0);
    bool upPressed;
    bool downPressed;
    bool leftPressed;
    bool rightPressed;

    upPressed = MTR_KeyboardPressed(keyUp);
    downPressed = MTR_KeyboardPressed(keyDown);
    leftPressed = MTR_KeyboardPressed(keyLeft);
    rightPressed = MTR_KeyboardPressed(keyRight);

    if (rightPressed) {
        if (leftPressed) {
            if (upPressed) {
                if (downPressed)
                    return 0; /* dummy */
                else
                    return 90;
            } else {
                if (downPressed)
                    return 270;
                else
                    return 0; /* dummy */
            }
        } else {
            if (upPressed) {
                if (downPressed)
                    return 0;
                else
                    return 45;
            } else {
                if (downPressed)
                    return 315;
                else
                    return 0;
            }
        }
    } else {
        if (leftPressed) {
            if (upPressed) {
                if (downPressed)
                    return 180;
                else
                    return 135;
            } else {
                if (downPressed)
                    return 225;
                else
                    return 180;
            }
        } else {
            if (upPressed) {
                if (downPressed)
                    return 0; /* dummy */
                else
                    return 90;
            } else {
                if (downPressed)
                    return 270;
                else
                    return 0; /* dummy */
            }
        }
    }
}

/*fa MTR_KeyboardInputChar yes */
MTR_DCLSPC char *MTR_CALL MTR_KeyboardInputChar(void)
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
