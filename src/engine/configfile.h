#ifndef MTR_ENGINE_CONFIGFILE
#define MTR_ENGINE_CONFIGFILE

#include <stdlib.h>
#include <string.h>
#include "minINI/minIni.h"

#include "marathoner/engine.h"

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))
char mtrConfigfileTempbuf[65536];

char *mtrConfigfileReadString(char* filename, char *section, char *key, char *defaultValue);

#endif
