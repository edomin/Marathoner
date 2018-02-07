#include "binding.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../binding_common.c"

MTR_BINDING_COMMON_CODE(Package_PhysFS_Lua, MTR_VERSION_PACKAGE_PHYSFS_LUA,
 "Package_PhysFS")
