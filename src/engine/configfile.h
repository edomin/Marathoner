#ifndef MTR_ENGINE_CONFIGFILE_H
#define MTR_ENGINE_CONFIGFILE_H

#include <stdlib.h>
#include <string.h>
#include "minINI/minIni.h"

#include "marathoner/engine.h"

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))
char mtrConfigfileTempbuf[65536];

/* returned value (if not NULL) must be freed after use */
MTR_EXPORT char *MTR_CALL mtrConfigfileGetKeyName(const char *filename,
 const char *section, int index);
/* returned value (if not NULL) must be freed after use */
MTR_EXPORT char *MTR_CALL mtrConfigfileGetSectionName(const char *filename,
 int index);

MTR_EXPORT bool MTR_CALL mtrConfigfileDeleteKey(const char *filename,
 const char *section, const char *key);
MTR_EXPORT bool MTR_CALL mtrConfigfileDeleteSection(const char *filename,
 const char *section);

MTR_EXPORT bool MTR_CALL mtrConfigfileReadBool(const char *filename,
 const char *section, const char *key, bool defaultValue);
MTR_EXPORT int MTR_CALL mtrConfigfileReadInt(const char *filename,
 const char *section, const char *key, int defaultValue);
MTR_EXPORT float MTR_CALL mtrConfigfileReadSingle(const char *filename,
 const char *section, const char *key, float defaultValue);
MTR_EXPORT char *MTR_CALL mtrConfigfileReadString(const char *filename,
 const char *section, const char *key, const char *defaultValue);

MTR_EXPORT bool MTR_CALL mtrConfigfileWriteInt(const char *filename,
 const char *section, const char *key, int value);
MTR_EXPORT bool MTR_CALL mtrConfigfileWriteSingle(const char *filename,
 const char *section, const char *key, float value);
MTR_EXPORT bool MTR_CALL mtrConfigfileWriteString(const char *filename,
 const char *section, const char *key, const char *value);

#endif
