#ifndef MTR_FUNCTION_ATTRIBUTE_H
#define MTR_FUNCTION_ATTRIBUTE_H

#ifdef __MINGW32__
    #define MTR_CALL   __stdcall
    #ifdef MTR_MOD_PLUGIN
        #define MTR_DCLSPC __declspec(dllexport)
    #endif
    #define MTR_STDCALL __cdecl
#else
    #define MTR_CALL
    #ifdef MTR_MOD_PLUGIN
        #define MTR_DCLSPC EMSCRIPTEN_KEEPALIVE
    #endif
    #define MTR_STDCALL
#endif

#ifdef MTR_MOD_STATIC
    #define MTR_DCLSPC
#endif

#endif
