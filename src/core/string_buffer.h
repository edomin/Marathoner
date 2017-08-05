#ifndef MTR_CORE_STRING_BUFFER_H
#define MTR_CORE_STRING_BUFFER_H

#include "marathoner/engine.h"
#include "indexkeeper.h"

typedef struct mtrStringBuffer_t {
    char *string;
    int   maxlen;
} mtrStringBuffer_t;

mtrIndexkeeper_t *mtrStringBufferKeeper;

bool MTR_CALL mtrStringBufferInit(uint32_t dmSize, uint32_t reservedCount);
uint32_t MTR_CALL mtrStringBufferAdd(const char *initialString, int maxlen);
void MTR_CALL mtrStringBufferDelete(uint32_t sbnum);
void MTR_CALL mtrStringBufferSetString(uint32_t sbnum, const char *string);
char *MTR_CALL mtrStringBufferGetString(uint32_t sbnum);
int MTR_CALL mtrStringBufferGetMaxLen(uint32_t sbnum);

#endif
