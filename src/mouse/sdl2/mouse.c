#include "mouse.h"

#include "marathoner/plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Mouse_SDL2";
    report->version = 0x000000;
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

__declspec(dllexport) bool __stdcall mtrMouseInit(void)
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

__declspec(dllexport) void __stdcall mtrMouseRefresh(void)
{
    uint32_t mouseState;
    uint8_t i;
    int mouseX;
    int mouseY;

    mtrMouse.relativeWheel = 0;

    SDL_PumpEvents();
    mouseState = SDL_GetMouseState(&mouseX, &mouseY);
    mtrMouse.previousX = mtrMouse.x;
    mtrMouse.previousY = mtrMouse.y;
    mtrMouse.x = (int16_t)mouseX;
    mtrMouse.y = (int16_t)mouseY;
    for (i = 0; i < 5; i++)
    {
        mtrMouse.previousMousestate[i] = mtrMouse.currentMousestate[i];
        mtrMouse.currentMousestate[i] = mouseState & SDL_BUTTON(i);
    }
}

__declspec(dllexport) bool __stdcall mtrMousePress(uint8_t button)
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

__declspec(dllexport) bool __stdcall mtrMouseRelease(uint8_t button)
{
    if (button > 5)
        return false;
    if (!(mtrMouse.currentMousestate[button]) &&
        (mtrMouse.previousMousestate[button]))
    {
        return true;
    }
    else
    {
        return false;
    }
}

__declspec(dllexport) bool __stdcall mtrMousePressed(uint8_t button)
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
__declspec(dllexport) int8_t __stdcall mtrMouseGetWheelRelative(void)
{
    return 0;
}

__declspec(dllexport) int16_t __stdcall mtrMouseGetX(void)
{
    return mtrMouse.x;
}

__declspec(dllexport) int16_t __stdcall mtrMouseGetY(void)
{
    return mtrMouse.y;
}

__declspec(dllexport) void __stdcall mtrMouseGetXY(int16_t *mouseX,
 int16_t *mouseY)
{
    *mouseX = mtrMouse.x;
    *mouseY = mtrMouse.y;
}

__declspec(dllexport) int16_t __stdcall mtrMouseGetDeltaX(void)
{
    return mtrMouse.x - mtrMouse.previousX;
}

__declspec(dllexport) int16_t __stdcall mtrMouseGetDeltaY(void)
{
    return mtrMouse.y - mtrMouse.previousY;
}

__declspec(dllexport) void __stdcall mtrMouseGetDeltaXY(int16_t *deltaX,
 int16_t *deltaY)
{
    *deltaX = mtrMouse.x - mtrMouse.previousX;
    *deltaY = mtrMouse.y - mtrMouse.previousY;
}
