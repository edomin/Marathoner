#ifndef MTR_ENGINE_CONFIGFILE
#define MTR_ENGINE_CONFIGFILE

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "minINI/minIni.h"

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))
char mtrConfigfileTempbuf[65536];

char *mtrConfigfileReadString(char* filename, char *section, char *key, char *defaultValue);

#endif
