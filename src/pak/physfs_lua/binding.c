#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(PAK_PhysFS_Lua, MTR_VERSION_PAK_PHYSFS_LUA,
 "PAK_PhysFS")
