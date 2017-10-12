#include "mouse.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Mouse, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
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

/*fa mtrMouseInit yes */
MTR_EXPORT bool MTR_CALL mtrMouseInit(void)
{
    SDL_version compiled;
    SDL_version linked;
    uint8_t i;

    mtrLogWrite("Initializing mouse support", 0, MTR_LMT_INFO);

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

    for (i = 0; i < 5; i++)
    {
        mtrMouse.currentMousestate[i] = false;
    }

    mtrMouse.x = 0;
    mtrMouse.y = 0;
    mtrMouse.relativeWheel = 0;

    mtrLogWrite("Mouse support initialized", 0, MTR_LMT_INFO);

    mtrMouseInited = true;
    return true;
}

/*fa mtrMouseRefresh yes */
MTR_EXPORT void MTR_CALL mtrMouseRefresh(void)
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

/*fa mtrMousePress yes */
MTR_EXPORT bool MTR_CALL mtrMousePress(int button)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(false);

    if (button > 5)
        return false;
    if (!(mtrMouse.previousMousestate[button]) &&
        (mtrMouse.currentMousestate[button]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*fa mtrMouseRelease yes */
MTR_EXPORT bool MTR_CALL mtrMouseRelease(int button)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(false);

    if (button > 5)
        return false;
    if ((mtrMouse.previousMousestate[button]) &&
        !(mtrMouse.currentMousestate[button]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*fa mtrMousePressed yes */
MTR_EXPORT bool MTR_CALL mtrMousePressed(int button)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(false);

    if (button > 5)
        return false;
    if (mtrMouse.currentMousestate[button])
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*fa mtrMouseGetWheelRelative yes */
MTR_EXPORT int MTR_CALL mtrMouseGetWheelRelative(void)
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

    return -wheelRel;
}

/*fa mtrMouseMoving yes */
MTR_EXPORT bool MTR_CALL mtrMouseMoving(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(false);

    return mtrMouse.mouseMotion;
}

/*fa mtrMouseGetX yes */
MTR_EXPORT int MTR_CALL mtrMouseGetX(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    return mtrMouse.x;
}

/*fa mtrMouseGetY yes */
MTR_EXPORT int MTR_CALL mtrMouseGetY(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    return mtrMouse.y;
}

/*fa mtrMouseGetXY yes */
MTR_EXPORT void MTR_CALL mtrMouseGetXY(int *mouseX, int *mouseY)
{
    if (!mtrMouseInited)
    {
        *mouseX = 0;
        *mouseY = 0;
    }
    *mouseX = mtrMouse.x;
    *mouseY = mtrMouse.y;
}

/*fa mtrMouseGetDeltaX yes */
MTR_EXPORT int MTR_CALL mtrMouseGetDeltaX(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    return mtrMouse.deltaX;
}

/*fa mtrMouseGetDeltaY yes */
MTR_EXPORT int MTR_CALL mtrMouseGetDeltaY(void)
{
    MTR_MOUSE_CHECK_IF_NOT_INITED(0);

    return mtrMouse.deltaY;
}

/*fa mtrMouseGetDeltaXY yes */
MTR_EXPORT void MTR_CALL mtrMouseGetDeltaXY(int *deltaX, int *deltaY)
{
    if (!mtrMouseInited)
    {
        *deltaX = 0;
        *deltaY = 0;
    }
    *deltaX = mtrMouse.deltaX;
    *deltaY = mtrMouse.deltaY;
}
