#ifndef MTR_PACKAGE_BINDING_COMMON_C
#define MTR_PACKAGE_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_PackageFunctionSupported,
 MTR_PackageFunctionSupported)
MTR_SCRIPT_FUNC_B_V(MTR_SF_PackageInit, MTR_PackageInit)
MTR_SCRIPT_FUNC_B_S2(MTR_SF_PackageMount, MTR_PackageMount)
MTR_SCRIPT_FUNC_B_S1(MTR_SF_PackageUnmount, MTR_PackageUnmount)
MTR_SCRIPT_FUNC_B_V(MTR_SF_PackageQuit, MTR_PackageQuit)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFopen, MTR_PackageGetFopen)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFclose, MTR_PackageGetFclose)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFeof, MTR_PackageGetFeof)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFtell, MTR_PackageGetFtell)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFseek, MTR_PackageGetFseek)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetRewind, MTR_PackageGetRewind)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFread, MTR_PackageGetFread)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFwrite, MTR_PackageGetFwrite)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFprintf, MTR_PackageGetFprintf)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFreadable, MTR_PackageGetFreadable)
MTR_SCRIPT_FUNC_P_V(MTR_SF_PackageGetFwritable, MTR_PackageGetFwritable)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageMount);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageUnmount);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageQuit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFopen);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFclose);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFeof);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFtell);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFseek);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetRewind);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFread);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFwrite);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFprintf);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFreadable);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, PackageGetFwritable);
}

#endif
