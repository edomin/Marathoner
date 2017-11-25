#include "console.h"

#ifdef WINVER
#if WINVER < 0x0500
/* https://support.microsoft.com/en-us/help/124103/how-to-obtain-a-console-window-handle-hwnd */
HWND GetConsoleWindow(void)
{
    #define MY_BUFSIZE 1024 // Buffer size for console window titles.
    HWND hwndFound;         // This is what is returned to the caller.
    char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
                                       // WindowTitle.
    char pszOldWindowTitle[MY_BUFSIZE]; // Contains original
                                       // WindowTitle.

    // Fetch current window title.
    GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

    // Format a "unique" NewWindowTitle.
    wsprintf(pszNewWindowTitle,"%d/%d", GetTickCount(), GetCurrentProcessId());

    // Change current window title.
    SetConsoleTitle(pszNewWindowTitle);

    // Ensure window title has been updated.
    Sleep(40);

    // Look for NewWindowTitle.
    hwndFound=FindWindow(NULL, pszNewWindowTitle);

    // Restore original window title.
    SetConsoleTitle(pszOldWindowTitle);

    return(hwndFound);
}
#endif /* WINVER < 0x0500 */
#endif /* WINVER */

bool MTR_ConsoleInit(void)
{
    #ifdef __MINGW32__
    if (AllocConsole() == 0)
    {
        mtrConsoleInited = false;
        return false;
    }

    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);

    SetConsoleTitle("Marathoner Log");

    mtrConsole = GetConsoleWindow();
    #endif

    mtrConsoleInited = true;
    return true;
}

/*fa MTR_ConsoleShow yes */
void MTR_CALL MTR_ConsoleShow(void)
{
    if (!mtrConsoleInited)
        if (!MTR_ConsoleInit())
            return;

    #ifdef __MINGW32__
    ShowWindow(mtrConsole, SW_SHOW);
    #endif
    mtrConsoleShowed = true;
}

/*fa MTR_ConsoleHide yes */
void MTR_CALL MTR_ConsoleHide(void)
{
    if (!mtrConsoleInited)
        if (!MTR_ConsoleInit())
            return;

    #ifdef __MINGW32__
    ShowWindow(mtrConsole, SW_HIDE);
    #endif
    mtrConsoleShowed = false;
}

void MTR_ConsolePrint(const char *string)
{
    if ((mtrConsoleInited) && (mtrConsoleShowed))
       printf("%s", string);
}
