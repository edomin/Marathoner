#include "json.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Json, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "JSON_cJSON";
    report->version = MTR_VERSION_JSON_CJSON;
    report->subsystem = "json";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

/*fa MTR_JsonInit yes */
MTR_DCLSPC bool MTR_CALL MTR_JsonInit(uint32_t dmSize, uint32_t reservedCount)
{
    MTR_LogWrite("Initializing JSON subsystem", 0, MTR_LMT_INFO);

    MTR_LogWrite_s("Reporting cJSON version:", 1, MTR_LMT_INFO,
     cJSON_Version());

    mtrJsonKeeper = (mtrIndexkeeper_t *)MTR_IndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrJson_t));
    if (mtrJsonKeeper == NULL)
    {
        MTR_Notify("Unable to initialize JSON subsystem", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        MTR_LogWrite("JSON subsystem initialized", 0, MTR_LMT_INFO);

    mtrJsonInited = false;
    return true;
}

/*fa MTR_JsonCreateObject yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonCreateObject(void)
{
    uint32_t   freeIndex;
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to create JSON object", 0U);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    json->json = cJSON_CreateObject();
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to create JSON object", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    json->parent = 0U;
    return freeIndex;
}

/*fa MTR_JsonCreateArray yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonCreateArray(void)
{
    uint32_t   freeIndex;
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to create JSON array", 0U);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    json->json = cJSON_CreateArray();
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to create JSON array", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    json->parent = 0U;
    return freeIndex;
}

/*fa MTR_JsonParseString yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonParseString(const char *string)
{
    uint32_t   freeIndex;
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to parse JSON string", 0U);

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    json->json = cJSON_Parse(string);
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to parse JSON string", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    json->parent = 0U;
    return freeIndex;
}

/*fa MTR_JsonParseFile yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonParseFile(const char *filename)
{
    uint32_t   freeIndex;
    mtrJson_t *json;
    uint32_t   file;
    char      *buffer;
    size_t     size;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to parse JSON file", 0U);

    file = MTR_FileOpen(filename, MTR_FM_READ);
    if (file == 0)
    {
        MTR_LogWrite("Unable to open JSON file", 0, MTR_LMT_ERROR);
        return 0U;
    }

    size = MTR_FileRead(file, &buffer);
    MTR_FileClose(file);

    if (size == 0)
    {
        MTR_LogWrite("Unable to read JSON file", 0, MTR_LMT_ERROR);
        return 0U;
    }

    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);

    json->json = cJSON_Parse(buffer);
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to parse JSON file", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    json->parent = 0U;
    return freeIndex;
}

/*fa MTR_JsonAddItemToObject yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddItemToObject(uint32_t object,
 const char *itemName, uint32_t item)
{
    mtrJson_t *jsonObject;
    mtrJson_t *jsonItem;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to add item to JSON object",
     0U);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);
    jsonItem = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, item);
    if (itemName == NULL)
    {
        MTR_LogWrite("Unable to add item to JSON object. Incorrect item name", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        MTR_LogWrite("Unable to add item to JSON object. Invalid JSON object", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonItem->json == NULL)
    {
        MTR_LogWrite("Unable to add item to JSON object. Invalid JSON item", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    cJSON_AddItemToObject(jsonObject->json, itemName, jsonItem->json);
    jsonItem->parent = object;

    return item;
}

/*fa MTR_JsonAddStringToObject yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddStringToObject(uint32_t object,
 const char *itemName, const char *string)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonObject;
    mtrJson_t *jsonString;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to add string to JSON object",
     0U);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);

    if (itemName == NULL)
    {
        MTR_LogWrite("Unable to add string to JSON object. Incorrect item name",
         0, MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        MTR_LogWrite("Unable to add string to JSON object. Invalid JSON object",
         0, MTR_LMT_ERROR);
        return 0U;
    }
    if (string == NULL)
    {
        MTR_LogWrite("Unable to add string to JSON object. String is empty", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonString = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonString->json = cJSON_CreateString(string);

    cJSON_AddItemToObject(jsonObject->json, itemName, jsonString->json);
    jsonString->parent = object;

    return freeIndex;
}

/*fa MTR_JsonAddDoubleToObject yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddDoubleToObject(uint32_t object,
 const char *itemName, double num)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonObject;
    mtrJson_t *jsonNum;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add double number to JSON object", 0U);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);
    if (itemName == NULL)
    {
        MTR_LogWrite("Unable to add double number to JSON object. Incorrect "
         "item name", 0, MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        MTR_LogWrite("Unable to add double number to JSON object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonNum = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonNum->json = cJSON_CreateNumber(num);

    cJSON_AddItemToObject(jsonObject->json, itemName, jsonNum->json);
    jsonNum->parent = object;

    return freeIndex;
}

/*fa MTR_JsonAddBoolToObject yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddBoolToObject(uint32_t object,
 const char *itemName, bool value)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonObject;
    mtrJson_t *jsonBool;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add boolean value to JSON object", 0U);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);
    if (itemName == NULL)
    {
        MTR_LogWrite("Unable to add boolean value to JSON object. Incorrect "
         "item name", 0, MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        MTR_LogWrite("Unable to add boolean value to JSON object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonBool = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonBool->json = cJSON_CreateBool(value);

    cJSON_AddItemToObject(jsonObject->json, itemName, jsonBool->json);
    jsonBool->parent = object;

    return freeIndex;
}

/*fa MTR_JsonAddNullToObject yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddNullToObject(uint32_t object,
 const char *itemName)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonObject;
    mtrJson_t *jsonNull;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add null value to JSON object", 0U);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);
    if (itemName == NULL)
    {
        MTR_LogWrite("Unable to add null value to JSON object. Incorrect "
         "item name", 0, MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        MTR_LogWrite("Unable to add null value to JSON object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonNull = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonNull->json = cJSON_CreateNull();

    cJSON_AddItemToObject(jsonObject->json, itemName, jsonNull->json);
    jsonNull->parent = object;

    return freeIndex;
}

/*fa MTR_JsonAddItemToArray yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddItemToArray(uint32_t array,
 uint32_t item)
{
    mtrJson_t *jsonArray;
    mtrJson_t *jsonItem;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to add item to JSON array",
     0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);
    jsonItem = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, item);
    if (jsonArray->json == NULL)
    {
        MTR_LogWrite("Unable to add item to JSON array. Invalid JSON array", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonItem->json == NULL)
    {
        MTR_LogWrite("Unable to add item to JSON array. Invalid JSON item", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    cJSON_AddItemToArray(jsonArray->json, jsonItem->json);
    jsonItem->parent = array;

    return item;
}

/*fa MTR_JsonAddStringToArray yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddStringToArray(uint32_t array,
 const char *string)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonString;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to add string to JSON array",
     0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
    {
        MTR_LogWrite("Unable to add string to JSON array. Invalid JSON array",
         0, MTR_LMT_ERROR);
        return 0U;
    }
    if (string == NULL)
    {
        MTR_LogWrite("Unable to add string to JSON array. String is empty", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonString = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonString->json = cJSON_CreateString(string);

    cJSON_AddItemToArray(jsonArray->json, jsonString->json);
    jsonString->parent = array;

    return freeIndex;
}

/*fa MTR_JsonAddDoubleToArray yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddDoubleToArray(uint32_t array, double num)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonDouble;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add double number to JSON array", 0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
    {
        MTR_LogWrite("Unable to add double number to JSON array. Invalid "
         "JSON array", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonDouble = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonDouble->json = cJSON_CreateNumber(num);

    cJSON_AddItemToArray(jsonArray->json, jsonDouble->json);
    jsonDouble->parent = array;

    return freeIndex;
}

/*fa MTR_JsonAddBoolToArray yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddBoolToArray(uint32_t array, bool value)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonBool;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add boolean value to JSON array", 0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
    {
        MTR_LogWrite("Unable to add boolean value to JSON array. Invalid JSON "
         "array", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonBool = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonBool->json = cJSON_CreateBool(value);

    cJSON_AddItemToArray(jsonArray->json, jsonBool->json);
    jsonBool->parent = array;

    return freeIndex;
}

/*fa MTR_JsonAddNullToArray yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonAddNullToArray(uint32_t array)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonNull;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add null value to JSON array", 0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
    {
        MTR_LogWrite("Unable to add null value to JSON array. Invalid JSON "
         "array", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonNull = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonNull->json = cJSON_CreateNull();

    cJSON_AddItemToArray(jsonArray->json, jsonNull->json);
    jsonNull->parent = array;

    return freeIndex;
}

/*fa MTR_JsonGetObjectItem yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonGetObjectItem(uint32_t object,
 const char *item)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonObject;
    mtrJson_t *jsonItem;
    MTR_JSON_CHECK_IF_NOT_INITED(0U);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);

    if (jsonObject->json == NULL)
        return 0U;
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonItem = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonItem->json = cJSON_GetObjectItemCaseSensitive(jsonObject->json, item);
    if (jsonItem->json == NULL)
    {
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    jsonItem->parent = object;

    return freeIndex;
}

/*fa MTR_JsonGetArrayItem yes */
MTR_DCLSPC uint32_t MTR_CALL MTR_JsonGetArrayItem(uint32_t array, int item)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonItem;
    MTR_JSON_CHECK_IF_NOT_INITED(0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
        return 0U;
    freeIndex = MTR_IndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonItem = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonItem->json = cJSON_GetArrayItem(jsonArray->json, item);
    if (jsonItem->json == NULL)
    {
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    jsonItem->parent = array;

    return freeIndex;
}

/* Returned string need to be freed after using */
/*fa MTR_JsonToString yes */
MTR_DCLSPC char *MTR_CALL MTR_JsonToString(uint32_t entity)
{
    mtrJson_t *json;
    char      *text;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to print JSON entity to string", NULL);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to print JSON entity to string. Invalid JSON "
         "entity", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return NULL;
    }
    text = cJSON_PrintUnformatted(json->json);
    if (text == NULL)
    {
        MTR_LogWrite("Unable to print JSON entity to string. Failed to render "
         "JSON string", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return NULL;
    }

    return text;
}

/* Returned string need to be freed after using */
/*fa MTR_JsonToStringFormatted yes */
MTR_DCLSPC char *MTR_CALL MTR_JsonToStringFormatted(uint32_t entity)
{
    mtrJson_t *json;
    char      *text;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to print JSON entity to string", NULL);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to print JSON entity to string. Invalid JSON "
         "entity", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return NULL;
    }
    text = cJSON_Print(json->json);
    if (text == NULL)
    {
        MTR_LogWrite("Unable to print JSON entity to string. Failed to render "
         "JSON string", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return NULL;
    }

    return text;
}

/*fa MTR_JsonToFile yes */
MTR_DCLSPC bool MTR_CALL MTR_JsonToFile(uint32_t entity, const char *filename)
{
    mtrJson_t *json;
    char      *text;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to print JSON entity to file",
     false);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to print JSON entity to string. Invalid JSON "
         "entity", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return false;
    }

    text = cJSON_PrintUnformatted(json->json);
    if (text == NULL)
    {
        MTR_LogWrite("Unable to print JSON entity to file. Failed to render "
         "JSON string", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return false;
    }

    MTR_FileWriteFast(filename, text, MTR_FM_WRITE);
    free(text);

    return true;
}

/*fa MTR_JsonToFileFormatted yes */
MTR_DCLSPC bool MTR_CALL MTR_JsonToFileFormatted(uint32_t entity,
 const char *filename)
{
    mtrJson_t *json;
    char      *text;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to print JSON entity to file",
     false);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to print JSON entity to string. Invalid JSON "
         "entity", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return false;
    }

    text = cJSON_Print(json->json);
    if (text == NULL)
    {
        MTR_LogWrite("Unable to print JSON entity to file. Failed to render "
         "JSON string", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return false;
    }

    MTR_FileWriteFast(filename, text, MTR_FM_WRITE);
    free(text);

    return true;
}

/*fa MTR_JsonDelete yes */
MTR_DCLSPC void MTR_CALL MTR_JsonDelete(uint32_t entity)
{
    uint32_t   i;
    mtrJson_t *json;
    mtrJson_t *checkedJson;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to delete JSON entity",);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        MTR_LogWrite("Unable to delete JSON entity. Invalid JSON entity", 0,
         MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return;
    }
    cJSON_Delete(json->json);
    MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);

    /* We can not know indeces of every child of the entity. This is         */
    /* why we need to check every index and delete invalid indeces after     */
    /* deleting root entity                                                  */
    for (i = 1; i <= mtrJsonKeeper->reservedData; i++)
    {
        if (!MTR_IndexkeeperIndexIsEmpty(mtrJsonKeeper, i))
        {
            checkedJson = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, i);
            if (checkedJson->json == NULL)
                MTR_IndexkeeperFreeIndex(mtrJsonKeeper, i);
        }
    }
}

/*fa MTR_JsonDeleteItemFromObject yes */
MTR_DCLSPC void MTR_CALL MTR_JsonDeleteItemFromObject(uint32_t object,
 const char *item)
{
    uint32_t   i;
    mtrJson_t *jsonObject;
    mtrJson_t *checkedJson;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to delete JSON item from object",);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);
    if (item == NULL)
    {
        MTR_LogWrite("Unable to delete JSON item from object. Incorrect "
         "item name", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, object);
        return;
    }
    if (jsonObject->json == NULL)
    {
        MTR_LogWrite("Unable to delete JSON item from object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, object);
        return;
    }
    cJSON_DeleteItemFromObject(jsonObject->json, item);

    /* We can not know indeces of every child of the entity. This is         */
    /* why we need to check every index and delete invalid indeces after     */
    /* deleting root entity                                                  */
    for (i = 1; i <= mtrJsonKeeper->reservedData; i++)
    {
        if (!MTR_IndexkeeperIndexIsEmpty(mtrJsonKeeper, i))
        {
            checkedJson = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, i);
            if (checkedJson->json == NULL)
                MTR_IndexkeeperFreeIndex(mtrJsonKeeper, i);
        }
    }
}

/*fa MTR_JsonDeleteItemFromArray yes */
MTR_DCLSPC void MTR_CALL MTR_JsonDeleteItemFromArray(uint32_t array, int item)
{
    uint32_t   i;
    mtrJson_t *jsonArray;
    mtrJson_t *checkedJson;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to delete JSON item from array",);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);
    if (jsonArray->json == NULL)
    {
        MTR_LogWrite("Unable to delete JSON item from array. Invalid "
         "JSON array", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, array);
        return;
    }
    cJSON_DeleteItemFromArray(jsonArray->json, item);

    /* We can not know indeces of every child of the entity. This is         */
    /* why we need to check every index and delete invalid indeces after     */
    /* deleting root entity                                                  */
    for (i = 1; i <= mtrJsonKeeper->reservedData; i++)
    {
        if (!MTR_IndexkeeperIndexIsEmpty(mtrJsonKeeper, i))
        {
            checkedJson = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, i);
            if (checkedJson->json == NULL)
                MTR_IndexkeeperFreeIndex(mtrJsonKeeper, i);
        }
    }
}

/*fa MTR_JsonDetachItemFromObject yes */
MTR_DCLSPC void MTR_CALL MTR_JsonDetachItemFromObject(uint32_t object,
 uint32_t item)
{
    mtrJson_t *jsonObject;
    mtrJson_t *jsonItem;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to detach JSON item from object",);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);
    jsonItem = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, item);
    if (jsonItem->json == NULL)
    {
        MTR_LogWrite("Unable to detach JSON item from object. Invalid "
         "JSON item", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, item);
        return;
    }
    if (jsonObject->json == NULL)
    {
        MTR_LogWrite("Unable to detach JSON item from object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, object);
        return;
    }
    if ((jsonItem->json->string == NULL) || (jsonItem->parent != object))
    {
        MTR_LogWrite("Unable to detach JSON item from object. Item is not "
         "member of object", 0, MTR_LMT_ERROR);
        return;
    }

    cJSON_DetachItemFromObject(jsonObject->json, jsonItem->json->string);
    jsonItem->parent = 0;
}

/*fa MTR_JsonDetachItemFromArray yes */
MTR_DCLSPC void MTR_CALL MTR_JsonDetachItemFromArray(uint32_t array,
 uint32_t item)
{
    int        i;
    int        arrayLength;
    int        itemNum;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonItem;
    cJSON     *jsonChild;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to detach JSON item from array",);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);
    jsonItem = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, item);
    if (jsonItem->json == NULL)
    {
        MTR_LogWrite("Unable to detach JSON item from array. Invalid "
         "JSON item", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, item);
        return;
    }
    if (jsonArray->json == NULL)
    {
        MTR_LogWrite("Unable to detach JSON item from array. Invalid "
         "JSON array", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, array);
        return;
    }
    arrayLength = cJSON_GetArraySize(jsonArray->json);
    if (arrayLength == 0)
    {
        MTR_LogWrite("Unable to detach JSON item from array. Array has not "
         "members", 0, MTR_LMT_ERROR);
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, array);
        return;
    }
    itemNum = -1;
    for (i = 0; i < arrayLength; i++)
    {
        jsonChild = cJSON_GetArrayItem(jsonArray->json, i);
        if (jsonChild == jsonItem->json)
        {
            itemNum = i;
            break;
        }
    }
    if (itemNum == -1)
    {
        MTR_LogWrite("Unable to detach JSON item from array. Item is not "
         "member of array", 0, MTR_LMT_ERROR);
        return;
    }

    cJSON_DetachItemFromArray(jsonArray->json, itemNum);
    jsonItem->parent = 0;
}

/*fa MTR_JsonObjectHasItem yes */
MTR_DCLSPC bool MTR_CALL MTR_JsonObjectHasItem(uint32_t object, const char *item)
{
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED(false);

    if (item == NULL)
        return false;

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);
    if (json->json == NULL)
    {
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, object);
        return false;
    }
    return cJSON_HasObjectItem(json->json, item);
}

/*fa MTR_JsonLength yes */
MTR_DCLSPC int MTR_CALL MTR_JsonLength(uint32_t entity)
{
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED(0);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        MTR_IndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return 0;
    }
    return cJSON_GetArraySize(json->json);
}
