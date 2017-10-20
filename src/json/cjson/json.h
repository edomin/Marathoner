#ifndef MTR_JSON_CJSON_H
#define MTR_JSON_CJSON_H

#include "cjson/cJSON.h"

#include "fa/JSON_cJSON.h"
#include "marathoner/plugin.h"

typedef struct mtrJson_t {
    cJSON   *json;
    uint32_t parent;
} mtrJson_t;

mtrIndexkeeper_t *mtrJsonKeeper;
static bool mtrJsonInited = false;
#define MTR_JSON_CHECK_IF_NOT_INITED(returnValue) \
    if (!mtrJsonInited)                           \
        return returnValue;
#define MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(message, returnValue)  \
    if (!mtrJsonInited)                                              \
    {                                                                \
        MTR_LogWrite(message ". JSON subsystem are not initialized", \
         1, MTR_LMT_ERROR);                                          \
        return returnValue;                                          \
    }

#endif
