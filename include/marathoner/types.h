#ifndef MTR_TYPES_H
#define MTR_TYPES_H

/* std integer and boolean types */
#include <stdint.h>
#include <stdbool.h>

/* FILE* type */
#include <stdio.h>

/* stdio.h function types */
typedef FILE *(MTR_STDCALL *MTR_FopenFunc)(const char *, const char *);
typedef int (MTR_STDCALL *MTR_FcloseFunc)(FILE *);
typedef int (MTR_STDCALL *MTR_FeofFunc)(FILE *);
typedef long int (MTR_STDCALL *MTR_FtellFunc)(FILE *);
typedef int (MTR_STDCALL *MTR_FseekFunc)(FILE *, long int, int);
typedef void (MTR_STDCALL *MTR_RewindFunc)(FILE *);
typedef size_t (MTR_STDCALL *MTR_FreadFunc)(void *, size_t, size_t, FILE *);
typedef size_t (MTR_STDCALL *MTR_FwriteFunc)(const void *, size_t, size_t,
 FILE *);
typedef int (MTR_STDCALL *MTR_FprintfFunc)(FILE *, const char *, ...);

/* stdio_ext.h functions types */
typedef int (MTR_STDCALL *MTR_FreadableFunc)(FILE *);
typedef int (MTR_STDCALL *MTR_FwritableFunc)(FILE *);

typedef struct MTR_Stdio {
    MTR_FopenFunc   Fopen;
    MTR_FcloseFunc  Fclose;
    MTR_FeofFunc    Feof;
    MTR_FtellFunc   Ftell;
    MTR_FseekFunc   Fseek;
    MTR_RewindFunc  Rewind;
    MTR_FreadFunc   Fread;
    MTR_FwriteFunc  Fwrite;
    MTR_FprintfFunc Fprintf;
} MTR_Stdio;

typedef struct MTR_StdioExt {
    MTR_FreadableFunc Freadable;
    MTR_FwritableFunc Fwritable;
} MTR_StdioExt;

#endif
