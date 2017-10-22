#ifndef MTR_TYPES_H
#define MTR_TYPES_H

/*
 * Types:
 * Macros (functions):
 * Macros (other):
 * MTR_CALL             - calling convention
 * MTR_DCLSPC           - function's attribute for exporting it from shared
 *                        library
 */

#include <stdint.h>
#include <stdbool.h>

#ifdef __MINGW32__
    #define MTR_CALL __stdcall
    #define MTR_DCLSPC __declspec(dllexport)
#else
    #define MTR_CALL
    #define MTR_DCLSPC EMSCRIPTEN_KEEPALIVE
#endif

#endif
