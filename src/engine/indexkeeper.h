#ifndef MTR_ENGINE_INDEXKEEPER
#define MTR_ENGINE_INDEXKEEPER

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

void *MRT_CALL mtrIndexkeeperCreate(uint32_t dmSize, uint32_t reservedCount,
 size_t datasize);
uint32_t MRT_CALL mtrIndexkeeperGetFreeIndex(void *ik);
void MRT_CALL mtrIndexkeeperFreeIndex(void *ik, uint32_t index);
void MRT_CALL mtrIndexkeeperDestroy(void *ik);

#endif
