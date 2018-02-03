#ifndef MTR_TYPES_H
#define MTR_TYPES_H

/* std integer and boolean types */
#include <stdint.h>
#include <stdbool.h>

/* FILE* type */
#include <stdio.h>

typedef FILE *(MTR_STDCALL *MTR_FopenFunc)(const char *, const char *);
typedef int (MTR_STDCALL *MTR_FcloseFunc)(FILE *);
typedef int (MTR_STDCALL *MTR_FeofFunc)(FILE *);
typedef long int (MTR_STDCALL *MTR_FtellFunc)(FILE *);
typedef int (MTR_STDCALL *MTR_FseekFunc)(FILE *, long int, int);
typedef size_t (MTR_STDCALL *MTR_FreadFunc)(void *, size_t, size_t, FILE *);
typedef size_t (MTR_STDCALL *MTR_FwriteFunc)(const void *, size_t, size_t,
 FILE *);

#endif
