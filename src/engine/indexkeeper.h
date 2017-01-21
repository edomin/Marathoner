#ifndef MTR_ENGINE_INDEXKEEPER_H
#define MTR_ENGINE_INDEXKEEPER_H

#include "marathoner/marathoner.h"

#include "log.h"
#include "notification.h"

#include "marathoner/engine.h"

typedef struct mtrIndexkeeper_t {
    void *data;
    size_t dataSize;
    uint64_t reservedData;
    uint32_t dataCount;
    uint32_t dmSize;
    uint32_t *dataMap;
} mtrIndexkeeper_t;

void *MTR_CALL mtrIndexkeeperCreate(uint32_t dmSize, uint32_t reservedCount,
 size_t datasize);
uint32_t MTR_CALL mtrIndexkeeperGetFreeIndex(void *ik);
void MTR_CALL mtrIndexkeeperFreeIndex(void *ik, uint32_t index);
void MTR_CALL mtrIndexkeeperDestroy(void *ik);

#endif
