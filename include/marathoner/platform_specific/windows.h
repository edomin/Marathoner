#ifndef MTR_PLATFORM_SPECIFIC_WINDOWS_H
#define MTR_PLATFORM_SPECIFIC_WINDOWS_H

#include <windows.h>
static inline char *MTR_WindowsErrorCodeToText(uint32_t error)
{
    #ifdef UNICODE
    wchar_t *lpMsgBuf;
    int textLen;
    char *result;
    #else
    LPTSTR lpMsgBuf;
    #endif

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
     FORMAT_MESSAGE_IGNORE_INSERTS, NULL, error,
     MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), (LPTSTR) &lpMsgBuf, 0, NULL);

    #ifdef UNICODE
    textLen = wcslen(lpMsgBuf);
    result = malloc(sizeof(char) * (textLen + 1));
    WideCharToMultiByte(CP_ACP, WC_COMPOSITECHECK | WC_NO_BEST_FIT_CHARS,
     lpMsgBuf, textLen, result, textLen, NULL, NULL);
    result[textLen] = '\0';
    //free(lpMsgBuf);
    return result;
    #else
    return lpMsgBuf;
    #endif
}

#endif
