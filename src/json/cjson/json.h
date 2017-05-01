#ifndef MTR_JSON_CJSON_H
#define MTR_JSON_CJSON_H

#include "cjson/cJSON.h"

#include "marathoner/plugin.h"

typedef struct mtrJson_t {
    cJSON   *json;
    uint32_t parent;
} mtrJson_t;

mtrIndexkeeper_t *mtrJsonKeeper;

#endif
