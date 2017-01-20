#include "mouse.h"

#include "marathoner/plugin_common.c"

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
    return true;
}

MTR_EXPORT void MTR_CALL mtrMouseRefresh(void)
{
    int mouseState;
    int i;
    int mouseX;
    int mouseY;

    mtrMouse.relativeWheel = 0;

    SDL_PumpEvents();
    mouseState = SDL_GetMouseState(&mouseX, &mouseY);
    mtrMouse.previousX = mtrMouse.x;
    mtrMouse.previousY = mtrMouse.y;
    mtrMouse.x = mouseX;
    mtrMouse.y = mouseY;
    for (i = 0; i < 5; i++)
    {
        mtrMouse.previousMousestate[i] = mtrMouse.currentMousestate[i];
        mtrMouse.currentMousestate[i] = mouseState & SDL_BUTTON(i);
    }
}

MTR_EXPORT bool MTR_CALL mtrMousePress(int button)
{
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

MTR_EXPORT bool MTR_CALL mtrMouseRelease(int button)
{
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

MTR_EXPORT bool MTR_CALL mtrMousePressed(int button)
{
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

/* Dummy function for future compatibility */
MTR_EXPORT int MTR_CALL mtrMouseGetWheelRelative(void)
{
    return 0;
}

MTR_EXPORT int MTR_CALL mtrMouseGetX(void)
{
    return mtrMouse.x;
}

MTR_EXPORT int MTR_CALL mtrMouseGetY(void)
{
    return mtrMouse.y;
}

MTR_EXPORT void MTR_CALL mtrMouseGetXY(int *mouseX, int *mouseY)
{
    *mouseX = mtrMouse.x;
    *mouseY = mtrMouse.y;
}

MTR_EXPORT int MTR_CALL mtrMouseGetDeltaX(void)
{
    return mtrMouse.x - mtrMouse.previousX;
}

MTR_EXPORT int MTR_CALL mtrMouseGetDeltaY(void)
{
    return mtrMouse.y - mtrMouse.previousY;
}

MTR_EXPORT void MTR_CALL mtrMouseGetDeltaXY(int *deltaX, int *deltaY)
{
    *deltaX = mtrMouse.x - mtrMouse.previousX;
    *deltaY = mtrMouse.y - mtrMouse.previousY;
}
