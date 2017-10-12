#include "json.h"

#include "marathoner/plugin_common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Json, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
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

/*fa mtrJsonInit yes */
MTR_EXPORT bool MTR_CALL mtrJsonInit(uint32_t dmSize, uint32_t reservedCount)
{
    mtrLogWrite("Initializing JSON subsystem", 0, MTR_LMT_INFO);

    mtrLogWrite_s("Reporting cJSON version:", 1, MTR_LMT_INFO, cJSON_Version());

    mtrJsonKeeper = (mtrIndexkeeper_t *)mtrIndexkeeperCreate(dmSize,
     reservedCount, sizeof(mtrJson_t));
    if (mtrJsonKeeper == NULL)
    {
        mtrNotify("Unable to initialize JSON subsystem", 1, MTR_LMT_ERROR);
        return false;
    }
    else
        mtrLogWrite("JSON subsystem initialized", 0, MTR_LMT_INFO);

    mtrJsonInited = false;
    return true;
}

/*fa mtrJsonCreateObject yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonCreateObject(void)
{
    uint32_t   freeIndex;
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to create JSON object", 0U);

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    json->json = cJSON_CreateObject();
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to create JSON object", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    json->parent = 0U;
    return freeIndex;
}

/*fa mtrJsonCreateArray yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonCreateArray(void)
{
    uint32_t   freeIndex;
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to create JSON array", 0U);

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    json->json = cJSON_CreateArray();
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to create JSON object", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    json->parent = 0U;
    return freeIndex;
}

/*fa mtrJsonParseString yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonParseString(const char *string)
{
    uint32_t   freeIndex;
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to parse JSON string", 0U);

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    json->json = cJSON_Parse(string);
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to parse JSON string", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    json->parent = 0U;
    return freeIndex;
}

/*fa mtrJsonParseFile yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonParseFile(const char *filename)
{
    uint32_t   freeIndex;
    mtrJson_t *json;
    uint32_t   file;
    char      *buffer;
    size_t     size;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to parse JSON file", 0U);

    file = mtrFileOpen(filename, MTR_FM_READ);
    if (file == 0)
    {
        mtrLogWrite("Unable to open JSON file", 0, MTR_LMT_ERROR);
        return 0U;
    }

    size = mtrFileRead(file, &buffer);
    mtrFileClose(file);

    if (size == 0)
    {
        mtrLogWrite("Unable to read JSON file", 0, MTR_LMT_ERROR);
        return 0U;
    }

    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);

    json->json = cJSON_Parse(buffer);
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to parse JSON file", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    json->parent = 0U;
    return freeIndex;
}

/*fa mtrJsonAddItemToObject yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddItemToObject(uint32_t object,
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
        mtrLogWrite("Unable to add item to JSON object. Incorrect item name", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        mtrLogWrite("Unable to add item to JSON object. Invalid JSON object", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonItem->json == NULL)
    {
        mtrLogWrite("Unable to add item to JSON object. Invalid JSON item", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    cJSON_AddItemToObject(jsonObject->json, itemName, jsonItem->json);
    jsonItem->parent = object;

    return item;
}

/*fa mtrJsonAddStringToObject yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddStringToObject(uint32_t object,
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
        mtrLogWrite("Unable to add string to JSON object. Incorrect item name",
         0, MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        mtrLogWrite("Unable to add string to JSON object. Invalid JSON object",
         0, MTR_LMT_ERROR);
        return 0U;
    }
    if (string == NULL)
    {
        mtrLogWrite("Unable to add string to JSON object. String is empty", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonString = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonString->json = cJSON_CreateString(string);

    cJSON_AddItemToObject(jsonObject->json, itemName, jsonString->json);
    jsonString->parent = object;

    return freeIndex;
}

/*fa mtrJsonAddDoubleToObject yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddDoubleToObject(uint32_t object,
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
        mtrLogWrite("Unable to add double number to JSON object. Incorrect "
         "item name", 0, MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        mtrLogWrite("Unable to add double number to JSON object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonNum = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonNum->json = cJSON_CreateNumber(num);

    cJSON_AddItemToObject(jsonObject->json, itemName, jsonNum->json);
    jsonNum->parent = object;

    return freeIndex;
}

/*fa mtrJsonAddBoolToObject yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddBoolToObject(uint32_t object,
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
        mtrLogWrite("Unable to add boolean value to JSON object. Incorrect "
         "item name", 0, MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        mtrLogWrite("Unable to add boolean value to JSON object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonBool = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonBool->json = cJSON_CreateBool(value);

    cJSON_AddItemToObject(jsonObject->json, itemName, jsonBool->json);
    jsonBool->parent = object;

    return freeIndex;
}

/*fa mtrJsonAddNullToObject yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddNullToObject(uint32_t object,
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
        mtrLogWrite("Unable to add null value to JSON object. Incorrect "
         "item name", 0, MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonObject->json == NULL)
    {
        mtrLogWrite("Unable to add null value to JSON object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonNull = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonNull->json = cJSON_CreateNull();

    cJSON_AddItemToObject(jsonObject->json, itemName, jsonNull->json);
    jsonNull->parent = object;

    return freeIndex;
}

/*fa mtrJsonAddItemToArray yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddItemToArray(uint32_t array,
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
        mtrLogWrite("Unable to add item to JSON array. Invalid JSON array", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    if (jsonItem->json == NULL)
    {
        mtrLogWrite("Unable to add item to JSON array. Invalid JSON item", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    cJSON_AddItemToArray(jsonArray->json, jsonItem->json);
    jsonItem->parent = array;

    return item;
}

/*fa mtrJsonAddStringToArray yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddStringToArray(uint32_t array,
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
        mtrLogWrite("Unable to add string to JSON array. Invalid JSON array",
         0, MTR_LMT_ERROR);
        return 0U;
    }
    if (string == NULL)
    {
        mtrLogWrite("Unable to add string to JSON array. String is empty", 0,
         MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonString = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonString->json = cJSON_CreateString(string);

    cJSON_AddItemToArray(jsonArray->json, jsonString->json);
    jsonString->parent = array;

    return freeIndex;
}

/*fa mtrJsonAddDoubleToArray yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddDoubleToArray(uint32_t array, double num)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonDouble;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add double number to JSON array", 0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
    {
        mtrLogWrite("Unable to add double number to JSON array. Invalid "
         "JSON array", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonDouble = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonDouble->json = cJSON_CreateNumber(num);

    cJSON_AddItemToArray(jsonArray->json, jsonDouble->json);
    jsonDouble->parent = array;

    return freeIndex;
}

/*fa mtrJsonAddBoolToArray yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddBoolToArray(uint32_t array, bool value)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonBool;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add boolean value to JSON array", 0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
    {
        mtrLogWrite("Unable to add boolean value to JSON array. Invalid JSON "
         "array", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonBool = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonBool->json = cJSON_CreateBool(value);

    cJSON_AddItemToArray(jsonArray->json, jsonBool->json);
    jsonBool->parent = array;

    return freeIndex;
}

/*fa mtrJsonAddNullToArray yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonAddNullToArray(uint32_t array)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonNull;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to add null value to JSON array", 0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
    {
        mtrLogWrite("Unable to add null value to JSON array. Invalid JSON "
         "array", 0, MTR_LMT_ERROR);
        return 0U;
    }
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonNull = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonNull->json = cJSON_CreateNull();

    cJSON_AddItemToArray(jsonArray->json, jsonNull->json);
    jsonNull->parent = array;

    return freeIndex;
}

/*fa mtrJsonGetObjectItem yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonGetObjectItem(uint32_t object,
 const char *item)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonObject;
    mtrJson_t *jsonItem;
    MTR_JSON_CHECK_IF_NOT_INITED(0U);

    jsonObject = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);

    if (jsonObject->json == NULL)
        return 0U;
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonItem = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonItem->json = cJSON_GetObjectItemCaseSensitive(jsonObject->json, item);
    if (jsonItem->json == NULL)
    {
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    jsonItem->parent = object;

    return freeIndex;
}

/*fa mtrJsonGetArrayItem yes */
MTR_EXPORT uint32_t MTR_CALL mtrJsonGetArrayItem(uint32_t array, int item)
{
    uint32_t   freeIndex;
    mtrJson_t *jsonArray;
    mtrJson_t *jsonItem;
    MTR_JSON_CHECK_IF_NOT_INITED(0U);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);

    if (jsonArray->json == NULL)
        return 0U;
    freeIndex = mtrIndexkeeperGetFreeIndex(mtrJsonKeeper);
    jsonItem = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, freeIndex);
    jsonItem->json = cJSON_GetArrayItem(jsonArray->json, item);
    if (jsonItem->json == NULL)
    {
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, freeIndex);
        return 0U;
    }
    jsonItem->parent = array;

    return freeIndex;
}

/* Returned string need to be freed after using */
/*fa mtrJsonToString yes */
MTR_EXPORT char *MTR_CALL mtrJsonToString(uint32_t entity)
{
    mtrJson_t *json;
    char      *text;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to print JSON entity to string", NULL);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to print JSON entity to string. Invalid JSON "
         "entity", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return NULL;
    }
    text = cJSON_PrintUnformatted(json->json);
    if (text == NULL)
    {
        mtrLogWrite("Unable to print JSON entity to string. Failed to render "
         "JSON string", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return NULL;
    }

    return text;
}

/* Returned string need to be freed after using */
/*fa mtrJsonToStringFormatted yes */
MTR_EXPORT char *MTR_CALL mtrJsonToStringFormatted(uint32_t entity)
{
    mtrJson_t *json;
    char      *text;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to print JSON entity to string", NULL);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to print JSON entity to string. Invalid JSON "
         "entity", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return NULL;
    }
    text = cJSON_Print(json->json);
    if (text == NULL)
    {
        mtrLogWrite("Unable to print JSON entity to string. Failed to render "
         "JSON string", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return NULL;
    }

    return text;
}

/*fa mtrJsonToFile yes */
MTR_EXPORT bool MTR_CALL mtrJsonToFile(uint32_t entity, const char *filename)
{
    mtrJson_t *json;
    char      *text;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to print JSON entity to file",
     false);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to print JSON entity to string. Invalid JSON "
         "entity", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return false;
    }

    text = cJSON_PrintUnformatted(json->json);
    if (text == NULL)
    {
        mtrLogWrite("Unable to print JSON entity to file. Failed to render "
         "JSON string", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return false;
    }

    mtrFileWriteFast(filename, text, MTR_FM_WRITE);
    free(text);

    return true;
}

/*fa mtrJsonToFileFormatted yes */
MTR_EXPORT bool MTR_CALL mtrJsonToFileFormatted(uint32_t entity,
 const char *filename)
{
    mtrJson_t *json;
    char      *text;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to print JSON entity to file",
     false);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to print JSON entity to string. Invalid JSON "
         "entity", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return false;
    }

    text = cJSON_Print(json->json);
    if (text == NULL)
    {
        mtrLogWrite("Unable to print JSON entity to file. Failed to render "
         "JSON string", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return false;
    }

    mtrFileWriteFast(filename, text, MTR_FM_WRITE);
    free(text);

    return true;
}

/*fa mtrJsonDelete yes */
MTR_EXPORT void MTR_CALL mtrJsonDelete(uint32_t entity)
{
    uint32_t   i;
    mtrJson_t *json;
    mtrJson_t *checkedJson;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG("Unable to delete JSON entity",);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        mtrLogWrite("Unable to delete JSON entity. Invalid JSON entity", 0,
         MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return;
    }
    cJSON_Delete(json->json);
    mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);

    /* We can not know indeces of every child of the entity. This is         */
    /* why we need to check every index and delete invalid indeces after     */
    /* deleting root entity                                                  */
    for (i = 1; i <= mtrJsonKeeper->reservedData; i++)
    {
        if (!mtrIndexkeeperIndexIsEmpty(mtrJsonKeeper, i))
        {
            checkedJson = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, i);
            if (checkedJson->json == NULL)
                mtrIndexkeeperFreeIndex(mtrJsonKeeper, i);
        }
    }
}

/*fa mtrJsonDeleteItemFromObject yes */
MTR_EXPORT void MTR_CALL mtrJsonDeleteItemFromObject(uint32_t object,
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
        mtrLogWrite("Unable to delete JSON item from object. Incorrect "
         "item name", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, object);
        return;
    }
    if (jsonObject->json == NULL)
    {
        mtrLogWrite("Unable to delete JSON item from object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, object);
        return;
    }
    cJSON_DeleteItemFromObject(jsonObject->json, item);

    /* We can not know indeces of every child of the entity. This is         */
    /* why we need to check every index and delete invalid indeces after     */
    /* deleting root entity                                                  */
    for (i = 1; i <= mtrJsonKeeper->reservedData; i++)
    {
        if (!mtrIndexkeeperIndexIsEmpty(mtrJsonKeeper, i))
        {
            checkedJson = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, i);
            if (checkedJson->json == NULL)
                mtrIndexkeeperFreeIndex(mtrJsonKeeper, i);
        }
    }
}

/*fa mtrJsonDeleteItemFromArray yes */
MTR_EXPORT void MTR_CALL mtrJsonDeleteItemFromArray(uint32_t array, int item)
{
    uint32_t   i;
    mtrJson_t *jsonArray;
    mtrJson_t *checkedJson;
    MTR_JSON_CHECK_IF_NOT_INITED_WITH_LOG(
     "Unable to delete JSON item from array",);

    jsonArray = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, array);
    if (jsonArray->json == NULL)
    {
        mtrLogWrite("Unable to delete JSON item from array. Invalid "
         "JSON array", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, array);
        return;
    }
    cJSON_DeleteItemFromArray(jsonArray->json, item);

    /* We can not know indeces of every child of the entity. This is         */
    /* why we need to check every index and delete invalid indeces after     */
    /* deleting root entity                                                  */
    for (i = 1; i <= mtrJsonKeeper->reservedData; i++)
    {
        if (!mtrIndexkeeperIndexIsEmpty(mtrJsonKeeper, i))
        {
            checkedJson = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, i);
            if (checkedJson->json == NULL)
                mtrIndexkeeperFreeIndex(mtrJsonKeeper, i);
        }
    }
}

/*fa mtrJsonDetachItemFromObject yes */
MTR_EXPORT void MTR_CALL mtrJsonDetachItemFromObject(uint32_t object,
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
        mtrLogWrite("Unable to detach JSON item from object. Invalid "
         "JSON item", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, item);
        return;
    }
    if (jsonObject->json == NULL)
    {
        mtrLogWrite("Unable to detach JSON item from object. Invalid "
         "JSON object", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, object);
        return;
    }
    if ((jsonItem->json->string == NULL) || (jsonItem->parent != object))
    {
        mtrLogWrite("Unable to detach JSON item from object. Item is not "
         "member of object", 0, MTR_LMT_ERROR);
        return;
    }

    cJSON_DetachItemFromObject(jsonObject->json, jsonItem->json->string);
    jsonItem->parent = 0;
}

/*fa mtrJsonDetachItemFromArray yes */
MTR_EXPORT void MTR_CALL mtrJsonDetachItemFromArray(uint32_t array,
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
        mtrLogWrite("Unable to detach JSON item from array. Invalid "
         "JSON item", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, item);
        return;
    }
    if (jsonArray->json == NULL)
    {
        mtrLogWrite("Unable to detach JSON item from array. Invalid "
         "JSON array", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, array);
        return;
    }
    arrayLength = cJSON_GetArraySize(jsonArray->json);
    if (arrayLength == 0)
    {
        mtrLogWrite("Unable to detach JSON item from array. Array has not "
         "members", 0, MTR_LMT_ERROR);
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, array);
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
        mtrLogWrite("Unable to detach JSON item from array. Item is not "
         "member of array", 0, MTR_LMT_ERROR);
        return;
    }

    cJSON_DetachItemFromArray(jsonArray->json, itemNum);
    jsonItem->parent = 0;
}

/*fa mtrJsonObjectHasItem yes */
MTR_EXPORT bool MTR_CALL mtrJsonObjectHasItem(uint32_t object, const char *item)
{
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED(false);

    if (item == NULL)
        return false;

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, object);
    if (json->json == NULL)
    {
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, object);
        return false;
    }
    return cJSON_HasObjectItem(json->json, item);
}

/*fa mtrJsonLength yes */
MTR_EXPORT int MTR_CALL mtrJsonLength(uint32_t entity)
{
    mtrJson_t *json;
    MTR_JSON_CHECK_IF_NOT_INITED(0);

    json = IK_GET_DATA(mtrJson_t *, mtrJsonKeeper, entity);
    if (json->json == NULL)
    {
        mtrIndexkeeperFreeIndex(mtrJsonKeeper, entity);
        return 0;
    }
    return cJSON_GetArraySize(json->json);
}
