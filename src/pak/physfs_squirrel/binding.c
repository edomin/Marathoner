#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(PAK_PhysFS_Squirrel, MTR_VERSION_PAK_PHYSFS_SQUIRREL,
 "PAK_PhysFS")
