#include "mouse.h"

#ifdef MTR_MOD_PLUGIN
#include "marathoner/plugin_common.c"

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Mouse_SDL2";
    report->version = MTR_VERSION_MOUSE_SDL2;
    report->subsystem = "mouse";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Mouse, FA_FUNCTIONS_COUNT)

int MTR_ButtonToActualButton(int button)
{
    switch (button)
    {
        case MTR_MOUSE_LEFT:
            return SDL_BUTTON_LEFT;
        case MTR_MOUSE_RIGHT:
            return  SDL_BUTTON_LEFT;
        case MTR_MOUSE_MIDDLE:
            return SDL_BUTTON_MIDDLE;
        case MTR_MOUSE_X1:
            return SDL_BUTTON_X1;
        case MTR_MOUSE_X2:
            return SDL_BUTTON_X2;
        default:
            return button;
    }
}

/*fa MTR_MouseInit yes */
MTR_DCLSPC bool MTR_CALL MTR_MouseInit(void)
{
    SDL_version compiled;
    SDL_version linked;
    uint8_t i;

    MTR_LogWrite("Initializing mouse support", 0, MTR_LMT_INFO);

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
        MTR_LogWrite("SDL events subsystem already initialized", 1,
         MTR_LMT_INFO);

    for (i = 0; i < 5; i++)
    {
        mtrMouse.currentMousestate[i] = false;
    }

    mtrMouse.x = 0;
    mtrMouse.y = 0;
    mtrMouse.relativeWheel = 0;

    MTR_LogWrite("Mouse support initialized", 0, MTR_LMT_INFO);

    mtrMouseInited = true;
    return true;
}

/*fa MTR_MouseRefresh yes */
MTR_DCLSPC void MTR_CALL MTR_MouseRefresh(void)
{
    int       mouseState;
    int       i;
    int       mouseX;
    int       mouseY;
    SDL_Event events[32];
    int       numEvents;
    MTR_MOUSE_CHECK_IF_NOT_INITED();

    mtrMouse.relativeWheel = 0;
    mtrMouse.mouseMotion = false;
    mtrMouse.deltaX = 0;
    mtrMouse.deltaY = 0;

    numEvents = SDL_PeepEvents(events, 32, SDL_GETEVENT, SDL_MOUSEMOTION,
     SDL_MOUSEMOTION);

    if (numEvents != 0)
    {
        for (i = 0; i < numEvents; i++)
            if (events[i].motion.which != SDL_TOUCH_MOUSEID)
            {
                mtrMouse.mouseMotion = true;
                mtrMouse.deltaX += events[i].motion.xrel;
                mtrMouse.deltaY += events[i].motion.yrel;
            }
    }

    SDL_PumpEvents();
    mouseState = SDL_GetMouseState(&mouseX, &mouseY);
    mtrMouse.x = mouseX;
    mtrMouse.y = mouseY;
    for (i = 0; i < 5; i++)
    {
        mtrMouse.previousMousestate[i] = mtrMouse.currentMousestate[i];
        mtrMouse.currentMousestate[i] = mouseState & SDL_BUTTON(i);
    }
}

/*fa MTR_MousePress yes */
MTR_DCLSPC bool MTR_CALL MTR_MousePress(int button)
{
    int actualButton;
    MTR_MOUSE_CHECK_IF_NOT_INITED(false);

    actualButton = MTR_ButtonToActualButton(button);
    if (!(mtrMouse.previousMousestate[actualButton]) &&
     (mtrMouse.currentMousestate[actualButton]))
        return true;
    else
        return false;
}

/*fa MTR_MouseRelease yes */
MTR_DCLSPC bool MTR_CALL MTR_MouseRelease(int button)
{
    int actualButton;
    MTR_MOUSE_CHECK_IF_NOT_INITED(false);

    actualButton = MTR_ButtonToActualButton(button);
    if ((mtrMouse.previousMousestate[actualButton]) &&
     !(mtrMouse.currentMousestate[actualButton]))
        return true;
    else
        return false;
}

/*fa MTR_MousePressed yes */
MTR_DCLSPC bool MTR_CALL MTR_MousePressed(int button)
{
    int actualButton;
    MTR_MOUSE_CHECK_IF_NOT_INITED(false);

    actualButton = MTR_ButtonToActualButton(button);
    if (mtrMouse.currentMousestate[actualButton])
        return true;
    else
        return false;
}

/*fa MTR_MouseGetWheelRelative yes */
MTR_DCLSPC int MTR_CALL MTR_MouseGetWheelRelative(void)
{
    SDL_Event events[32];
    int       numEvents;
    int       i;
    int       wheelRel;
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    numEvents = SDL_PeepEvents(events, 32, SDL_GETEVENT, SDL_MOUSEWHEEL,
     SDL_MOUSEWHEEL);

    if (numEvents == 0)
        return 0;

    wheelRel = 0;
    for (i = 0; i < numEvents; i++)
        if (events[i].wheel.which != SDL_TOUCH_MOUSEID)
            wheelRel += events[i].wheel.y;

    return wheelRel;
}

/*fa MTR_MouseMoving yes */
MTR_DCLSPC bool MTR_CALL MTR_MouseMoving(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(false);

    return mtrMouse.mouseMotion;
}

/*fa MTR_MouseGetX yes */
MTR_DCLSPC int MTR_CALL MTR_MouseGetX(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    return mtrMouse.x;
}

/*fa MTR_MouseGetY yes */
MTR_DCLSPC int MTR_CALL MTR_MouseGetY(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    return mtrMouse.y;
}

/*fa MTR_MouseGetXY yes */
MTR_DCLSPC void MTR_CALL MTR_MouseGetXY(int *mouseX, int *mouseY)
{
    if (!mtrMouseInited)
    {
        *mouseX = 0;
        *mouseY = 0;
    }
    *mouseX = mtrMouse.x;
    *mouseY = mtrMouse.y;
}

/*fa MTR_MouseGetDeltaX yes */
MTR_DCLSPC int MTR_CALL MTR_MouseGetDeltaX(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    return mtrMouse.deltaX;
}

/*fa MTR_MouseGetDeltaY yes */
MTR_DCLSPC int MTR_CALL MTR_MouseGetDeltaY(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    return mtrMouse.deltaY;
}

/*fa MTR_MouseGetDeltaXY yes */
MTR_DCLSPC void MTR_CALL MTR_MouseGetDeltaXY(int *deltaX, int *deltaY)
{
    if (!mtrMouseInited)
    {
        *deltaX = 0;
        *deltaY = 0;
    }
    *deltaX = mtrMouse.deltaX;
    *deltaY = mtrMouse.deltaY;
}
