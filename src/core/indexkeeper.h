#ifndef MTR_CORE_INDEXKEEPER_H
#define MTR_CORE_INDEXKEEPER_H

#include "marathoner/marathoner.h"

#include "log.h"
#include "notification.h"

#include "marathoner/engine.h"

typedef struct mtrIndexkeeper_t {
    void *data;
    size_t dataSize;
    #if !defined(__EMSCRIPTEN__)
    uint64_t reservedData;
    #else
    uint32_t reservedData;
    #endif
    uint32_t dataCount;
    uint32_t dmSize;
    uint32_t *dataMap;
} mtrIndexkeeper_t;

void *MTR_CALL MTR_IndexkeeperCreate(uint32_t dmSize, uint32_t reservedCount,
 size_t datasize);
uint32_t MTR_CALL MTR_IndexkeeperGetFreeIndex(void *ik);
void MTR_CALL MTR_IndexkeeperFreeIndex(void *ik, uint32_t index);
bool MTR_CALL MTR_IndexkeeperIndexIsEmpty(void *ik, uint32_t index);
uint32_t MTR_CALL MTR_IndexkeeperGetReservedDataCount(void *ik);
void MTR_CALL MTR_IndexkeeperDestroy(void *ik);

#endif
