#ifndef MTR_ENGINE_CONFIGFILE
#define MTR_ENGINE_CONFIGFILE

#include <stdlib.h>
#include <string.h>
#include "minINI/minIni.h"

#include "marathoner/engine.h"

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))
char mtrConfigfileTempbuf[65536];

bool mtrConfigfileReadBool(char* filename, char *section, char *key,
 bool defaultValue);
int mtrConfigfileReadInt(char* filename, char *section, char *key,
 int defaultValue);
char *mtrConfigfileReadString(char* filename, char *section, char *key,
 char *defaultValue);

#endif
