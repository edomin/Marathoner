#ifndef MTR_CORE_CONFIGFILE_H
#define MTR_CORE_CONFIGFILE_H

#include <stdlib.h>
#include <string.h>
#include "minINI/minIni.h"

#include "marathoner/engine.h"

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))
char mtrConfigfileTempbuf[65536];

/* returned value (if not NULL) must be freed after use */
char *MTR_CALL mtrConfigfileGetKeyName(const char *filename,
 const char *section, int index);
/* returned value (if not NULL) must be freed after use */
char *MTR_CALL mtrConfigfileGetSectionName(const char *filename, int index);

bool MTR_CALL mtrConfigfileDeleteKey(const char *filename, const char *section,
 const char *key);
bool MTR_CALL mtrConfigfileDeleteSection(const char *filename,
 const char *section);

bool MTR_CALL mtrConfigfileReadBool(const char *filename, const char *section,
 const char *key, bool defaultValue);
int MTR_CALL mtrConfigfileReadInt(const char *filename, const char *section,
 const char *key, int defaultValue);
float MTR_CALL mtrConfigfileReadSingle(const char *filename,
 const char *section, const char *key, float defaultValue);
char *MTR_CALL mtrConfigfileReadString(const char *filename,
 const char *section, const char *key, const char *defaultValue);

bool MTR_CALL mtrConfigfileWriteBool(const char* filename, const char *section,
 const char *key, bool value);
bool MTR_CALL mtrConfigfileWriteInt(const char *filename, const char *section,
 const char *key, int value);
bool MTR_CALL mtrConfigfileWriteSingle(const char *filename,
 const char *section, const char *key, float value);
bool MTR_CALL mtrConfigfileWriteString(const char *filename,
 const char *section, const char *key, const char *value);
bool MTR_CALL mtrConfigfileCreateSection(const char* filename,
 const char *section);

#endif
