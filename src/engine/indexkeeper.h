#ifndef MTR_ENGINE_INDEXKEEPER
#define MTR_ENGINE_INDEXKEEPER

#include <stdint.h>

#include "marathoner.h"
#include "log.h"
#include "notification.h"

typedef struct mtrIndexkeeper_t {
    void *data;
    size_t dataSize;
    uint32_t reservedData;
    uint32_t dataCount;
    uint32_t dmSize;
    uint32_t *dataMap;
} mtrIndexkeeper_t;

void *__stdcall mtrIndexkeeperCreate(uint32_t dmSize, uint32_t reservedCount,
 size_t datasize);
uint32_t __stdcall mtrIndexkeeperGetFreeIndex(void *ik);
void __stdcall mtrIndexkeeperDestroy(void *ik);

#endif
