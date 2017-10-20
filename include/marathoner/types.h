#ifndef MTR_TYPES_H
#define MTR_TYPES_H

/*
 * Types:
 * mtr_lhandler         - shared library handle
 * Macros (functions):
 * mtrLoadLibrary       - load shared library
 * mtrLoadSymbolName    - load function from shared library
 * mtrCloseLibrary      - close shared library
 * Macros (other):
 * MTR_CALL             - calling convention
 * MTR_DCLSPC           - function's attribute for exporting it from shared
 *                        library
 */

#include <stdint.h>
#include <stdbool.h>

#ifdef __MINGW32__
    #include <windows.h>
    typedef HMODULE mtr_lhandler; /* Library handle type */
    #define MTR_LoadLibrary LoadLibrary
    #define MTR_LoadSymbolName GetProcAddress
    #define MTR_CloseLibrary FreeLibrary
    #define MTR_CALL __stdcall
    #define MTR_DCLSPC __declspec(dllexport)
#else
    #include <emscripten.h>
    typedef void* mtr_lhandler;
    #define MTR_LoadLibrary(filename) dlopen(filename, RTLD_LAZY)
    #define MTR_LoadSymbolName dlsym
    #define MTR_CloseLibrary dlclose
    #define MTR_CALL
    #define MTR_DCLSPC EMSCRIPTEN_KEEPALIVE
#endif

#endif
