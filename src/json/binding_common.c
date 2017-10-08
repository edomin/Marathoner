#ifndef MTR_JSON_BINDING_COMMON_C
#define MTR_JSON_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC_I_S1(mtrSF_JsonFunctionSupported, mtrJsonFunctionSupported)
MTR_SCRIPT_FUNC_B_U32t2(mtrSF_JsonInit, mtrJsonInit)
MTR_SCRIPT_FUNC_U32t_V(mtrSF_JsonCreateObject, mtrJsonCreateObject)
MTR_SCRIPT_FUNC_U32t_V(mtrSF_JsonCreateArray, mtrJsonCreateArray)
MTR_SCRIPT_FUNC_U32t_S1(mtrSF_JsonParseString, mtrJsonParseString)
MTR_SCRIPT_FUNC_U32t_S1(mtrSF_JsonParseFile, mtrJsonParseFile)
MTR_SCRIPT_FUNC_U32t_U32t1S1U32t1(mtrSF_JsonAddItemToObject,
 mtrJsonAddItemToObject)
MTR_SCRIPT_FUNC_U32t_U32t1S2(mtrSF_JsonAddStringToObject,
 mtrJsonAddStringToObject)
MTR_SCRIPT_FUNC_U32t_U32t1S1D1(mtrSF_JsonAddDoubleToObject,
 mtrJsonAddDoubleToObject)
MTR_SCRIPT_FUNC_U32t_U32t1S1B1(mtrSF_JsonAddBoolToObject,
 mtrJsonAddBoolToObject)
MTR_SCRIPT_FUNC_U32t_U32t1S1(mtrSF_JsonAddNullToObject, mtrJsonAddNullToObject)
MTR_SCRIPT_FUNC_U32t_U32t2(mtrSF_JsonAddItemToArray, mtrJsonAddItemToArray)
MTR_SCRIPT_FUNC_U32t_U32t1S1(mtrSF_JsonAddStringToArray,
 mtrJsonAddStringToArray)
MTR_SCRIPT_FUNC_U32t_U32t1D1(mtrSF_JsonAddDoubleToArray,
 mtrJsonAddDoubleToArray)
MTR_SCRIPT_FUNC_U32t_U32t1B1(mtrSF_JsonAddBoolToArray, mtrJsonAddBoolToArray)
MTR_SCRIPT_FUNC_U32t_U32t1(mtrSF_JsonAddNullToArray, mtrJsonAddNullToArray)
MTR_SCRIPT_FUNC_U32t_U32t1S1(mtrSF_JsonGetObjectItem, mtrJsonGetObjectItem)
MTR_SCRIPT_FUNC_U32t_U32t1I1(mtrSF_JsonGetArrayItem, mtrJsonGetArrayItem)
MTR_SCRIPT_FUNC_S_U32t1(mtrSF_JsonToString, mtrJsonToString)
MTR_SCRIPT_FUNC_S_U32t1(mtrSF_JsonToStringFormatted, mtrJsonToStringFormatted)
MTR_SCRIPT_FUNC_B_U32t1S1(mtrSF_JsonToFile, mtrJsonToFile)
MTR_SCRIPT_FUNC_B_U32t1S1(mtrSF_JsonToFileFormatted, mtrJsonToFileFormatted)
MTR_SCRIPT_FUNC_V_U32t1(mtrSF_JsonDelete, mtrJsonDelete)
MTR_SCRIPT_FUNC_V_U32t1S1(mtrSF_JsonDeleteItemFromObject,
 mtrJsonDeleteItemFromObject)
MTR_SCRIPT_FUNC_V_U32t1I1(mtrSF_JsonDeleteItemFromArray,
 mtrJsonDeleteItemFromArray)
MTR_SCRIPT_FUNC_V_U32t2(mtrSF_JsonDetachItemFromObject,
 mtrJsonDetachItemFromObject)
MTR_SCRIPT_FUNC_V_U32t2(mtrSF_JsonDetachItemFromArray,
 mtrJsonDetachItemFromArray)
MTR_SCRIPT_FUNC_B_U32t1S1(mtrSF_JsonObjectHasItem, mtrJsonObjectHasItem)
MTR_SCRIPT_FUNC_I_U32t1(mtrSF_JsonLength, mtrJsonLength)

void mtrScriptsRegisterAll(void)
{
    mtrVm = mtrScriptsGetVm();

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
