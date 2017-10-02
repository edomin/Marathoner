-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(JsonInit, "mtrJsonInit", JsonFunctionSupported);
fa.FunctionSupported(JsonCreateObject, "mtrJsonCreateObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonCreateArray, "mtrJsonCreateArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonParseString, "mtrJsonParseString",
 JsonFunctionSupported);
fa.FunctionSupported(JsonParseFile, "mtrJsonParseFile", JsonFunctionSupported);
fa.FunctionSupported(JsonAddItemToObject, "mtrJsonAddItemToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddStringToObject, "mtrJsonAddStringToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddDoubleToObject, "mtrJsonAddDoubleToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddBoolToObject, "mtrJsonAddBoolToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddNullToObject, "mtrJsonAddNullToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddItemToArray, "mtrJsonAddItemToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddStringToArray, "mtrJsonAddStringToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddDoubleToArray, "mtrJsonAddDoubleToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddBoolToArray, "mtrJsonAddBoolToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddNullToArray, "mtrJsonAddNullToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonGetObjectItem, "mtrJsonGetObjectItem",
 JsonFunctionSupported);
fa.FunctionSupported(JsonGetArrayItem, "mtrJsonGetArrayItem",
 JsonFunctionSupported);
fa.FunctionSupported(JsonToString, "mtrJsonToString", JsonFunctionSupported);
fa.FunctionSupported(JsonToStringFormatted, "mtrJsonToStringFormatted",
 JsonFunctionSupported);
fa.FunctionSupported(JsonToFile, "mtrJsonToFile", JsonFunctionSupported);
fa.FunctionSupported(JsonToFileFormatted, "mtrJsonToFileFormatted",
 JsonFunctionSupported);
fa.FunctionSupported(JsonDelete, "mtrJsonDelete", JsonFunctionSupported);
fa.FunctionSupported(JsonDeleteItemFromObject, "mtrJsonDeleteItemFromObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonDeleteItemFromArray, "mtrJsonDeleteItemFromArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonDetachItemFromObject, "mtrJsonDetachItemFromObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonDetachItemFromArray, "mtrJsonDetachItemFromArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonObjectHasItem, "mtrJsonObjectHasItem",
 JsonFunctionSupported);
fa.FunctionSupported(JsonLength, "mtrJsonLength", JsonFunctionSupported);
