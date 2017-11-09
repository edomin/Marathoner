#ifndef MTR_FUNCTION_ATTRIBUTE_H
#define MTR_FUNCTION_ATTRIBUTE_H

#ifdef __MINGW32__
    #define MTR_CALL   __stdcall
    #define MTR_DCLSPC __declspec(dllexport)
#else
    #define MTR_CALL
    #define MTR_DCLSPC EMSCRIPTEN_KEEPALIVE
#endif

#endif
