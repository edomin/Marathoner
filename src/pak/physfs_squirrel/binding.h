#ifndef MTR_PAK_PHYSFS_SQUIRREL_H
#define MTR_PAK_PHYSFS_SQUIRREL_H

#include "squirrel.h"

#include "marathoner/plugin.h"

#define MTR_SOURCE_MODULE "PAK_PhysFS"
#ifdef MTR_MOD_STATIC
    #define MTR_BINDING
    #define MTR_ScriptsRegisterAll MTR_PAK_PhysFS_SquirrelRegisterAll
#endif
#include "marathoner/binding_common.h"
#include "../binding_common.h"

MTR_BINDING_COMMON_HEADER()

#endif
