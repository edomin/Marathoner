#ifndef MTR_FUNCTION_ATTRIBUTE_H
#define MTR_FUNCTION_ATTRIBUTE_H

#ifdef __GNUC__
    #ifdef __MINGW32__
        #define MTR_CALL __cdecl
        #define MTR_STDCALL __cdecl
        #ifdef MTR_MOD_PLUGIN
            #define MTR_DCLSPC __declspec(dllexport)
        #endif
    #else
        #ifdef __i386__
            #define MTR_CALL __attribute__((__cdecl__))
            #define MTR_STDCALL __attribute__((__cdecl__))
        #else
            #define MTR_CALL
            #define MTR_STDCALL
        #endif
        #ifdef MTR_MOD_PLUGIN
            #define MTR_DCLSPC __attribute__((visibility("default")))
        #endif
    #endif
#else
    #define MTR_CALL
    #define MTR_STDCALL
    #ifdef MTR_MOD_PLUGIN
        #define MTR_DCLSPC EMSCRIPTEN_KEEPALIVE
    #endif
#endif

#ifdef MTR_MOD_STATIC
    #define MTR_DCLSPC
#endif

#endif
