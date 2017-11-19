#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(PNG_libpng_Squirrel, MTR_VERSION_PNG_LIBPNG_SQUIRREL,
 "PNG_libpng")
