-- Positive
FileWriteLineFast("test/output.txt", "Positive test", FM_WRITE);

local success = JsonInit(IKDM_SMALL, 32);
if success then
    FileWriteLineFast("test/output.txt", "Success", FM_APPEND);
    local json = JsonParseFile("test/json/test.json");
    local parsedString = JsonParseString("{\"bool\": \"true\"}");
    local object = JsonCreateObject();
    local array = JsonCreateArray();
    JsonAddItemToObject(json, "object", object);
    JsonAddItemToObject(json, "array", array);
    JsonAddStringToObject(json, "string2", "world");
    JsonAddDoubleToObject(json, "double2", 3.14);
    JsonAddBoolToObject(json, "bool2", false);
    JsonAddNullToObject(json, "null");
    JsonAddItemToArray(array, parsedString);
    JsonAddStringToArray(array, "Marathoner");
    JsonAddDoubleToArray(array, 142.2);
    JsonAddBoolToArray(array, true);
    JsonAddNullToArray(array);
    local objectItem = JsonGetObjectItem(json, array);
    local objectItemString = JsonToString(objectItem);
    FileWriteLineFast("test/output.txt", objectItemString, FM_APPEND);
    local arrayItem = JsonGetArrayItem(array, parsedString);
    local arrayItemStringFormatted = JsonToStringFormatted(arrayItem);
    FileWriteLineFast("test/output.txt", arrayItemStringFormatted, FM_APPEND);
    JsonToFile(json, "test/output.json");
    JsonToFileFormatted(json, "test/output_formatted.json");

    JsonDelete(uint32_t entity);
    JsonDeleteItemFromObject(json, "object");
    JsonDeleteItemFromArray(array, 0);
    JsonDetachItemFromObject(json, array);
    JsonDetachItemFromArray(array, 0);
    if JsonObjectHasItem(object, "array")
        FileWriteLineFast("test/output.txt", "Ok", FM_APPEND);
    else
        FileWriteLineFast("test/output.txt", "Not ok", FM_APPEND);
    end;

    FileWriteLineFast("test/output.txt", "Json length: " .. JsonLength(json),
     FM_APPEND);

    JsonToFileFormatted(json, "test/output_formatted_json.json");
    JsonToFileFormatted(array, "test/output_formatted_array.json");
else
    FileWriteLineFast("test/output.txt", "Fail", FM_APPEND);
end;
