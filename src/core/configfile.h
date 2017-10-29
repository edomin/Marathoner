#ifndef MTR_CORE_CONFIGFILE_H
#define MTR_CORE_CONFIGFILE_H

#include <stdlib.h>
#include <string.h>
#include "minINI/minIni.h"

#include "marathoner/engine.h"

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))
char mtrConfigfileTempbuf[65536];

/* returned value (if not NULL) must be freed after use */
char *MTR_CALL MTR_ConfigfileGetKeyName(const char *filename,
 const char *section, int index);
/* returned value (if not NULL) must be freed after use */
char *MTR_CALL MTR_ConfigfileGetSectionName(const char *filename, int index);

bool MTR_CALL MTR_ConfigfileKeyExists(const char* filename, const char *section,
 const char *key);
bool MTR_CALL MTR_ConfigfileSectionExists(const char* filename,
 const char *section);

bool MTR_CALL MTR_ConfigfileDeleteKey(const char *filename, const char *section,
 const char *key);
bool MTR_CALL MTR_ConfigfileDeleteSection(const char *filename,
 const char *section);

bool MTR_CALL MTR_ConfigfileReadBool(const char *filename, const char *section,
 const char *key, bool defaultValue);
int MTR_CALL MTR_ConfigfileReadInt(const char *filename, const char *section,
 const char *key, int defaultValue);
float MTR_CALL MTR_ConfigfileReadSingle(const char *filename,
 const char *section, const char *key, float defaultValue);
char *MTR_CALL MTR_ConfigfileReadString(const char *filename,
 const char *section, const char *key, const char *defaultValue);

bool MTR_CALL MTR_ConfigfileWriteBool(const char* filename, const char *section,
 const char *key, bool value);
bool MTR_CALL MTR_ConfigfileWriteInt(const char *filename, const char *section,
 const char *key, int value);
bool MTR_CALL MTR_ConfigfileWriteSingle(const char *filename,
 const char *section, const char *key, float value);
bool MTR_CALL MTR_ConfigfileWriteString(const char *filename,
 const char *section, const char *key, const char *value);
bool MTR_CALL MTR_ConfigfileCreateSection(const char* filename,
 const char *section);

#endif
