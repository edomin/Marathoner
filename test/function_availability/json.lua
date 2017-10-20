-- Function Availability
FileWriteLineFast("test/output.txt", "Function Availability", FM_WRITE);
local fa = dofile("test/common/function_availability.lua");

fa.FunctionSupported(JsonInit, "MTR_JsonInit", JsonFunctionSupported);
fa.FunctionSupported(JsonCreateObject, "MTR_JsonCreateObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonCreateArray, "MTR_JsonCreateArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonParseString, "MTR_JsonParseString",
 JsonFunctionSupported);
fa.FunctionSupported(JsonParseFile, "MTR_JsonParseFile", JsonFunctionSupported);
fa.FunctionSupported(JsonAddItemToObject, "MTR_JsonAddItemToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddStringToObject, "MTR_JsonAddStringToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddDoubleToObject, "MTR_JsonAddDoubleToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddBoolToObject, "MTR_JsonAddBoolToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddNullToObject, "MTR_JsonAddNullToObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddItemToArray, "MTR_JsonAddItemToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddStringToArray, "MTR_JsonAddStringToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddDoubleToArray, "MTR_JsonAddDoubleToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddBoolToArray, "MTR_JsonAddBoolToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonAddNullToArray, "MTR_JsonAddNullToArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonGetObjectItem, "MTR_JsonGetObjectItem",
 JsonFunctionSupported);
fa.FunctionSupported(JsonGetArrayItem, "MTR_JsonGetArrayItem",
 JsonFunctionSupported);
fa.FunctionSupported(JsonToString, "MTR_JsonToString", JsonFunctionSupported);
fa.FunctionSupported(JsonToStringFormatted, "MTR_JsonToStringFormatted",
 JsonFunctionSupported);
fa.FunctionSupported(JsonToFile, "MTR_JsonToFile", JsonFunctionSupported);
fa.FunctionSupported(JsonToFileFormatted, "MTR_JsonToFileFormatted",
 JsonFunctionSupported);
fa.FunctionSupported(JsonDelete, "MTR_JsonDelete", JsonFunctionSupported);
fa.FunctionSupported(JsonDeleteItemFromObject, "MTR_JsonDeleteItemFromObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonDeleteItemFromArray, "MTR_JsonDeleteItemFromArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonDetachItemFromObject, "MTR_JsonDetachItemFromObject",
 JsonFunctionSupported);
fa.FunctionSupported(JsonDetachItemFromArray, "MTR_JsonDetachItemFromArray",
 JsonFunctionSupported);
fa.FunctionSupported(JsonObjectHasItem, "MTR_JsonObjectHasItem",
 JsonFunctionSupported);
fa.FunctionSupported(JsonLength, "MTR_JsonLength", JsonFunctionSupported);
