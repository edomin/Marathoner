#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(JSON_cJSON_Squirrel, MTR_VERSION_JSON_CJSON_SQUIRREL,
 "JSON_cJSON")
