#ifndef MTR_JSON_BINDING_COMMON_C
#define MTR_JSON_BINDING_COMMON_C

#include "marathoner/script_func.h"

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
    bool ok;
    ok = true;

    mtrVm = mtrScriptsGetVm();

    MTR_FIND_FUNCTION(mtrJsonInit, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonCreateObject, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonCreateArray, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonParseString, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonParseFile, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddItemToObject, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddStringToObject, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddDoubleToObject, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddBoolToObject, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddNullToObject, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddItemToArray, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddStringToArray, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddDoubleToArray, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddBoolToArray, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonAddNullToArray, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonGetObjectItem, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonGetArrayItem, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonToString, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonToStringFormatted, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonToFile, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonToFileFormatted, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonDelete, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonDeleteItemFromObject, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonDeleteItemFromArray, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonDetachItemFromObject, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonDetachItemFromArray, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonObjectHasItem, MTR_SOURCE_MODULE);
    MTR_FIND_FUNCTION(mtrJsonLength, MTR_SOURCE_MODULE);

    if (ok)
    {
        mtrScriptsRegisterFunction(mtrSF_JsonInit, "JsonInit");
        mtrScriptsRegisterFunction(mtrSF_JsonCreateObject, "JsonCreateObject");
        mtrScriptsRegisterFunction(mtrSF_JsonCreateArray, "JsonCreateArray");
        mtrScriptsRegisterFunction(mtrSF_JsonParseString, "JsonParseString");
        mtrScriptsRegisterFunction(mtrSF_JsonParseFile, "JsonParseFile");
        mtrScriptsRegisterFunction(mtrSF_JsonAddItemToObject,
         "JsonAddItemToObject");
        mtrScriptsRegisterFunction(mtrSF_JsonAddStringToObject,
         "JsonAddStringToObject");
        mtrScriptsRegisterFunction(mtrSF_JsonAddDoubleToObject,
         "JsonAddDoubleToObject");
        mtrScriptsRegisterFunction(mtrSF_JsonAddBoolToObject,
         "JsonAddBoolToObject");
        mtrScriptsRegisterFunction(mtrSF_JsonAddNullToObject,
         "JsonAddNullToObject");
        mtrScriptsRegisterFunction(mtrSF_JsonAddItemToArray,
         "JsonAddItemToArray");
        mtrScriptsRegisterFunction(mtrSF_JsonAddStringToArray,
         "JsonAddStringToArray");
        mtrScriptsRegisterFunction(mtrSF_JsonAddDoubleToArray,
         "JsonAddDoubleToArray");
        mtrScriptsRegisterFunction(mtrSF_JsonAddBoolToArray,
         "JsonAddBoolToArray");
        mtrScriptsRegisterFunction(mtrSF_JsonAddNullToArray,
         "JsonAddNullToArray");
        mtrScriptsRegisterFunction(mtrSF_JsonGetObjectItem,
         "JsonGetObjectItem");
        mtrScriptsRegisterFunction(mtrSF_JsonGetArrayItem, "JsonGetArrayItem");
        mtrScriptsRegisterFunction(mtrSF_JsonToString, "JsonToString");
        mtrScriptsRegisterFunction(mtrSF_JsonToStringFormatted,
         "JsonToStringFormatted");
        mtrScriptsRegisterFunction(mtrSF_JsonToFile, "JsonToFile");
        mtrScriptsRegisterFunction(mtrSF_JsonToFileFormatted,
         "JsonToFileFormatted");
        mtrScriptsRegisterFunction(mtrSF_JsonDelete, "JsonDelete");
        mtrScriptsRegisterFunction(mtrSF_JsonDeleteItemFromObject,
         "JsonDeleteItemFromObject");
        mtrScriptsRegisterFunction(mtrSF_JsonDeleteItemFromArray,
         "JsonDeleteItemFromArray");
        mtrScriptsRegisterFunction(mtrSF_JsonDetachItemFromObject,
         "JsonDetachItemFromObject");
        mtrScriptsRegisterFunction(mtrSF_JsonDetachItemFromArray,
         "JsonDetachItemFromArray");
        mtrScriptsRegisterFunction(mtrSF_JsonObjectHasItem,
         "JsonObjectHasItem");
        mtrScriptsRegisterFunction(mtrSF_JsonLength, "JsonLength");
    }
    else
    {
        mtrLogWrite("Functions not added", 3, MTR_LMT_ERROR);
    }
}

#endif
