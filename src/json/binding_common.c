#ifndef MTR_JSON_BINDING_COMMON_C
#define MTR_JSON_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(MTR_SF_JsonFunctionSupported, MTR_JsonFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(MTR_SF_JsonInit, MTR_JsonInit)
MTR_SCRIPT_FUNC_U32t_V(MTR_SF_JsonCreateObject, MTR_JsonCreateObject)
MTR_SCRIPT_FUNC_U32t_V(MTR_SF_JsonCreateArray, MTR_JsonCreateArray)
MTR_SCRIPT_FUNC_U32t_S1(MTR_SF_JsonParseString, MTR_JsonParseString)
MTR_SCRIPT_FUNC_U32t_S1(MTR_SF_JsonParseFile, MTR_JsonParseFile)
MTR_SCRIPT_FUNC_U32t_U32t1S1U32t1(MTR_SF_JsonAddItemToObject,
 MTR_JsonAddItemToObject)
MTR_SCRIPT_FUNC_U32t_U32t1S2(MTR_SF_JsonAddStringToObject,
 MTR_JsonAddStringToObject)
MTR_SCRIPT_FUNC_U32t_U32t1S1D1(MTR_SF_JsonAddDoubleToObject,
 MTR_JsonAddDoubleToObject)
MTR_SCRIPT_FUNC_U32t_U32t1S1B1(MTR_SF_JsonAddBoolToObject,
 MTR_JsonAddBoolToObject)
MTR_SCRIPT_FUNC_U32t_U32t1S1(MTR_SF_JsonAddNullToObject,
 MTR_JsonAddNullToObject)
MTR_SCRIPT_FUNC_U32t_U32t2(MTR_SF_JsonAddItemToArray, MTR_JsonAddItemToArray)
MTR_SCRIPT_FUNC_U32t_U32t1S1(MTR_SF_JsonAddStringToArray,
 MTR_JsonAddStringToArray)
MTR_SCRIPT_FUNC_U32t_U32t1D1(MTR_SF_JsonAddDoubleToArray,
 MTR_JsonAddDoubleToArray)
MTR_SCRIPT_FUNC_U32t_U32t1B1(MTR_SF_JsonAddBoolToArray, MTR_JsonAddBoolToArray)
MTR_SCRIPT_FUNC_U32t_U32t1(MTR_SF_JsonAddNullToArray, MTR_JsonAddNullToArray)
MTR_SCRIPT_FUNC_U32t_U32t1S1(MTR_SF_JsonGetObjectItem, MTR_JsonGetObjectItem)
MTR_SCRIPT_FUNC_U32t_U32t1I1(MTR_SF_JsonGetArrayItem, MTR_JsonGetArrayItem)
MTR_SCRIPT_FUNC_S_U32t1(MTR_SF_JsonToString, MTR_JsonToString)
MTR_SCRIPT_FUNC_S_U32t1(MTR_SF_JsonToStringFormatted, MTR_JsonToStringFormatted)
MTR_SCRIPT_FUNC_B_U32t1S1(MTR_SF_JsonToFile, MTR_JsonToFile)
MTR_SCRIPT_FUNC_B_U32t1S1(MTR_SF_JsonToFileFormatted, MTR_JsonToFileFormatted)
MTR_SCRIPT_FUNC_V_U32t1(MTR_SF_JsonDelete, MTR_JsonDelete)
MTR_SCRIPT_FUNC_V_U32t1S1(MTR_SF_JsonDeleteItemFromObject,
 MTR_JsonDeleteItemFromObject)
MTR_SCRIPT_FUNC_V_U32t1I1(MTR_SF_JsonDeleteItemFromArray,
 MTR_JsonDeleteItemFromArray)
MTR_SCRIPT_FUNC_V_U32t2(MTR_SF_JsonDetachItemFromObject,
 MTR_JsonDetachItemFromObject)
MTR_SCRIPT_FUNC_V_U32t2(MTR_SF_JsonDetachItemFromArray,
 MTR_JsonDetachItemFromArray)
MTR_SCRIPT_FUNC_B_U32t1S1(MTR_SF_JsonObjectHasItem, MTR_JsonObjectHasItem)
MTR_SCRIPT_FUNC_I_U32t1(MTR_SF_JsonLength, MTR_JsonLength)

void MTR_ScriptsRegisterAll(void)
{
    #ifdef MTR_MOD_PLUGIN
    mtrVm = MTR_ScriptsGetVm();
    #endif

    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonFunctionSupported);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonInit);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonCreateObject);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonCreateArray);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonParseString);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonParseFile);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddItemToObject);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddStringToObject);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddDoubleToObject);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddBoolToObject);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddNullToObject);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddItemToArray);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddStringToArray);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddDoubleToArray);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddBoolToArray);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonAddNullToArray);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonGetObjectItem);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonGetArrayItem);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonToString);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonToStringFormatted);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonToFile);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonToFileFormatted);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonDelete);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonDeleteItemFromObject);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonDeleteItemFromArray);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonDetachItemFromObject);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonDetachItemFromArray);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonObjectHasItem);
    MTR_FIND_AND_ADD_FUNCTION(MTR_SOURCE_MODULE, JsonLength);
}

#endif
