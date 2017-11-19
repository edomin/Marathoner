#ifndef MTR_JSON_BINDING_COMMON_H
#define MTR_JSON_BINDING_COMMON_H

MTR_FUNC(int, MTR_JsonFunctionSupported, const char *);
MTR_FUNC(bool, MTR_JsonInit, uint32_t, uint32_t);
MTR_FUNC(uint32_t, MTR_JsonCreateObject, void);
MTR_FUNC(uint32_t, MTR_JsonCreateArray, void);
MTR_FUNC(uint32_t, MTR_JsonParseString, const char *);
MTR_FUNC(uint32_t, MTR_JsonParseFile, const char *);
MTR_FUNC(uint32_t, MTR_JsonAddItemToObject, uint32_t, const char *, uint32_t);
MTR_FUNC(uint32_t, MTR_JsonAddStringToObject, uint32_t, const char *,
 const char *);
MTR_FUNC(uint32_t, MTR_JsonAddDoubleToObject, uint32_t, const char *, double);
MTR_FUNC(uint32_t, MTR_JsonAddBoolToObject, uint32_t, const char *, bool);
MTR_FUNC(uint32_t, MTR_JsonAddNullToObject, uint32_t, const char *);
MTR_FUNC(uint32_t, MTR_JsonAddItemToArray, uint32_t, uint32_t);
MTR_FUNC(uint32_t, MTR_JsonAddStringToArray, uint32_t, const char *);
MTR_FUNC(uint32_t, MTR_JsonAddDoubleToArray, uint32_t, double);
MTR_FUNC(uint32_t, MTR_JsonAddBoolToArray, uint32_t, bool);
MTR_FUNC(uint32_t, MTR_JsonAddNullToArray, uint32_t);
MTR_FUNC(uint32_t, MTR_JsonGetObjectItem, uint32_t, const char *);
MTR_FUNC(uint32_t, MTR_JsonGetArrayItem, uint32_t, int);
MTR_FUNC(char *, MTR_JsonToString, uint32_t);
MTR_FUNC(char *, MTR_JsonToStringFormatted, uint32_t);
MTR_FUNC(char *, MTR_JsonToFile, uint32_t, const char *);
MTR_FUNC(char *, MTR_JsonToFileFormatted, uint32_t, const char *);
MTR_FUNC(void, MTR_JsonDelete, uint32_t);
MTR_FUNC(void, MTR_JsonDeleteItemFromObject, uint32_t, const char *);
MTR_FUNC(void, MTR_JsonDeleteItemFromArray, uint32_t, int);
MTR_FUNC(void, MTR_JsonDetachItemFromObject, uint32_t, uint32_t);
MTR_FUNC(void, MTR_JsonDetachItemFromArray, uint32_t, uint32_t);
MTR_FUNC(bool, MTR_JsonObjectHasItem, uint32_t, const char *);
MTR_FUNC(int, MTR_JsonLength, uint32_t);

#endif
