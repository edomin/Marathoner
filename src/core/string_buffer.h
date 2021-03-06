#ifndef MTR_CORE_STRING_BUFFER_H
#define MTR_CORE_STRING_BUFFER_H

#include <string.h>

#include "marathoner/engine.h"
#include "indexkeeper.h"

typedef struct mtrStringBuffer_t {
    char *string;
    int   maxlen;
} mtrStringBuffer_t;

mtrIndexkeeper_t *mtrStringBufferKeeper;

bool MTR_CALL MTR_StringBufferInit(uint32_t dmSize, uint32_t reservedCount);
uint32_t MTR_CALL MTR_StringBufferAdd(const char *initialString, int maxlen);
void MTR_CALL MTR_StringBufferDelete(uint32_t sbnum);
void MTR_CALL MTR_StringBufferSetString(uint32_t sbnum, const char *string);
char *MTR_CALL MTR_StringBufferGetString(uint32_t sbnum);
int MTR_CALL MTR_StringBufferGetMaxLen(uint32_t sbnum);

#endif
