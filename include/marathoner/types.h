#ifndef MTR_TYPES_H
#define MTR_TYPES_H

/*
 * Types:
 * mtr_lhandler         - shared library handle
 * Macro (functions):
 * mtrLoadLibrary       - load shared library
 * mtrLoadSymbolName    - load function from shared library
 * mtrCloseLibrary      - close shared library
 * Macro (other):
 * MTR_CALL             - calling convention
 * MTR_EXPORT           - function's attribute for exporting it from shared
                          library
 */

#include <stdint.h>
#include <stdbool.h>

#ifdef __MINGW32__
    #include <windows.h>
    typedef HMODULE mtr_lhandler; /* Library handle type */
    #define mtrLoadLibrary LoadLibrary
    #define mtrLoadSymbolName GetProcAddress
    #define mtrCloseLibrary FreeLibrary
    #define MTR_CALL __stdcall
    #define MTR_EXPORT __declspec(dllexport)
#else
    #include <emscripten.h>
    typedef void* mtr_lhandler;
    #define mtrLoadLibrary(filename) dlopen(filename, RTLD_LAZY)
    #define mtrLoadSymbolName dlsym
    #define mtrCloseLibrary dlclose
    #define MTR_CALL
    #define MTR_EXPORT EMSCRIPTEN_KEEPALIVE
#endif

#endif
