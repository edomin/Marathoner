#ifndef MTR_JSON_BINDING_COMMON_C
#define MTR_JSON_BINDING_COMMON_C

#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_JsonInit)
{
    uint32_t  dmSize;
    uint32_t  reservedCount;
    bool      success;

    MTR_SF_GET_UINT32(dmSize, 1);
    MTR_SF_GET_UINT32(reservedCount, 2);
    success = mtrJsonInit(dmSize, reservedCount);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonCreateObject)
{
    uint32_t json;

    json = mtrJsonCreateObject();

    MTR_SF_PUSH_UINT32(json);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonCreateArray)
{
    uint32_t json;

    json = mtrJsonCreateArray();

    MTR_SF_PUSH_UINT32(json);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonParseString)
{
    const char *string;
    uint32_t    json;

    MTR_SF_GET_STRING(string, 1);
    json = mtrJsonParseString(string);

    MTR_SF_PUSH_UINT32(json);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonParseFile)
{
    const char *filename;
    uint32_t    json;

    MTR_SF_GET_STRING(filename, 1);
    json = mtrJsonParseFile(filename);

    MTR_SF_PUSH_UINT32(json);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddItemToObject)
{
    uint32_t    object;
    const char *itemname;
    uint32_t    item;
    uint32_t    returnedItem;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_STRING(itemname, 2);
    MTR_SF_GET_UINT32(item, 3);
    returnedItem = mtrJsonAddItemToObject(object, itemname, item);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddStringToObject)
{
    uint32_t    object;
    const char *itemname;
    const char *string;
    uint32_t    returnedItem;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_STRING(itemname, 2);
    MTR_SF_GET_STRING(string, 3);
    returnedItem = mtrJsonAddStringToObject(object, itemname, string);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddDoubleToObject)
{
    uint32_t    object;
    const char *itemname;
    double      num;
    uint32_t    returnedItem;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_STRING(itemname, 2);
    MTR_SF_GET_DOUBLE(num, 3);
    returnedItem = mtrJsonAddDoubleToObject(object, itemname, num);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddBoolToObject)
{
    uint32_t    object;
    const char *itemname;
    bool        value;
    uint32_t    returnedItem;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_STRING(itemname, 2);
    MTR_SF_GET_BOOL(value, 3);
    returnedItem = mtrJsonAddBoolToObject(object, itemname, value);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddNullToObject)
{
    uint32_t    object;
    const char *itemname;
    uint32_t    returnedItem;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_STRING(itemname, 2);
    returnedItem = mtrJsonAddNullToObject(object, itemname);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddItemToArray)
{
    uint32_t array;
    uint32_t item;
    uint32_t returnedItem;

    MTR_SF_GET_UINT32(array, 1);
    MTR_SF_GET_UINT32(item, 2);
    returnedItem = mtrJsonAddItemToArray(array, item);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddStringToArray)
{
    uint32_t    array;
    const char *string;
    uint32_t    returnedItem;

    MTR_SF_GET_UINT32(array, 1);
    MTR_SF_GET_STRING(string, 2);
    returnedItem = mtrJsonAddStringToArray(array, string);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddDoubleToArray)
{
    uint32_t array;
    double   num;
    uint32_t returnedItem;

    MTR_SF_GET_UINT32(array, 1);
    MTR_SF_GET_DOUBLE(num, 2);
    returnedItem = mtrJsonAddDoubleToArray(array, num);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddBoolToArray)
{
    uint32_t array;
    bool     value;
    uint32_t returnedItem;

    MTR_SF_GET_UINT32(array, 1);
    MTR_SF_GET_BOOL(value, 2);
    returnedItem = mtrJsonAddBoolToArray(array, value);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonAddNullToArray)
{
    uint32_t array;
    uint32_t returnedItem;

    MTR_SF_GET_UINT32(array, 1);
    returnedItem = mtrJsonAddNullToArray(array);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonGetObjectItem)
{
    uint32_t    object;
    const char *itemName;
    uint32_t    returnedItem;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_STRING(itemName, 2);
    returnedItem = mtrJsonGetObjectItem(object, itemName);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonGetArrayItem)
{
    uint32_t array;
    int      itemNum;
    uint32_t returnedItem;

    MTR_SF_GET_UINT32(array, 1);
    MTR_SF_GET_INT(itemNum, 2);
    returnedItem = mtrJsonGetArrayItem(array, itemNum);

    MTR_SF_PUSH_UINT32(returnedItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonToString)
{
    uint32_t    entity;
    const char *string;

    MTR_SF_GET_UINT32(entity, 1);
    string = mtrJsonToString(entity);

    MTR_SF_PUSH_STRING(string);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonToStringFormatted)
{
    uint32_t    entity;
    const char *string;

    MTR_SF_GET_UINT32(entity, 1);
    string = mtrJsonToStringFormatted(entity);

    MTR_SF_PUSH_STRING(string);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonToFile)
{
    uint32_t    entity;
    const char *filename;
    bool        success;

    MTR_SF_GET_UINT32(entity, 1);
    MTR_SF_GET_STRING(filename, 2);
    success = mtrJsonToFile(entity, filename);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonToFileFormatted)
{
    uint32_t    entity;
    const char *filename;
    bool        success;

    MTR_SF_GET_UINT32(entity, 1);
    MTR_SF_GET_STRING(filename, 2);
    success = mtrJsonToFileFormatted(entity, filename);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonDelete)
{
    uint32_t entity;

    MTR_SF_GET_UINT32(entity, 1);
    mtrJsonDelete(entity);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_JsonDeleteItemFromObject)
{
    uint32_t    object;
    const char *itemName;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_STRING(itemName, 2);
    mtrJsonDeleteItemFromObject(object, itemName);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_JsonDeleteItemFromArray)
{
    uint32_t object;
    int      itemNum;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_INT(itemNum, 2);
    mtrJsonDeleteItemFromArray(object, itemNum);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_JsonDetachItemFromObject)
{
    uint32_t object;
    uint32_t item;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_UINT32(item, 2);
    mtrJsonDetachItemFromObject(object, item);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_JsonDetachItemFromArray)
{
    uint32_t array;
    uint32_t item;

    MTR_SF_GET_UINT32(array, 1);
    MTR_SF_GET_UINT32(item, 2);
    mtrJsonDetachItemFromArray(array, item);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_JsonObjectHasItem)
{
    uint32_t    object;
    const char *itemName;
    bool        hasItem;

    MTR_SF_GET_UINT32(object, 1);
    MTR_SF_GET_STRING(itemName, 2);
    hasItem = mtrJsonObjectHasItem(object, itemName);

    MTR_SF_PUSH_BOOL(hasItem);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_JsonLength)
{
    uint32_t entity;
    int      length;

    MTR_SF_GET_UINT32(entity, 1);
    length = mtrJsonLength(entity);

    MTR_SF_PUSH_INT(length);

    return 1;
}

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
