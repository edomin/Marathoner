#ifndef MTR_JSON_BINDING_COMMON_H
#define MTR_JSON_BINDING_COMMON_H

typedef int (MTR_CALL * MTR_JsonFunctionSupportedFunc)(const char *);
MTR_JsonFunctionSupportedFunc MTR_JsonFunctionSupported;

typedef bool (MTR_CALL * MTR_JsonInitFunc)(uint32_t, uint32_t);
MTR_JsonInitFunc MTR_JsonInit;

typedef uint32_t (MTR_CALL * MTR_JsonCreateObjectFunc)(void);
MTR_JsonCreateObjectFunc MTR_JsonCreateObject;

typedef uint32_t (MTR_CALL * MTR_JsonCreateArrayFunc)(void);
MTR_JsonCreateArrayFunc MTR_JsonCreateArray;

typedef uint32_t (MTR_CALL * MTR_JsonParseStringFunc)(const char *);
MTR_JsonParseStringFunc MTR_JsonParseString;

typedef uint32_t (MTR_CALL * MTR_JsonParseFileFunc)(const char *);
MTR_JsonParseFileFunc MTR_JsonParseFile;

typedef uint32_t (MTR_CALL * MTR_JsonAddItemToObjectFunc)(uint32_t, const char *,
 uint32_t);
MTR_JsonAddItemToObjectFunc MTR_JsonAddItemToObject;

typedef uint32_t (MTR_CALL * MTR_JsonAddStringToObjectFunc)(uint32_t,
 const char *, const char *);
MTR_JsonAddStringToObjectFunc MTR_JsonAddStringToObject;

typedef uint32_t (MTR_CALL * MTR_JsonAddDoubleToObjectFunc)(uint32_t,
 const char *, double);
MTR_JsonAddDoubleToObjectFunc MTR_JsonAddDoubleToObject;

typedef uint32_t (MTR_CALL * MTR_JsonAddBoolToObjectFunc)(uint32_t, const char *,
 bool);
MTR_JsonAddBoolToObjectFunc MTR_JsonAddBoolToObject;

typedef uint32_t (MTR_CALL * MTR_JsonAddNullToObjectFunc)(uint32_t,
 const char *);
MTR_JsonAddNullToObjectFunc MTR_JsonAddNullToObject;

typedef uint32_t (MTR_CALL * MTR_JsonAddItemToArrayFunc)(uint32_t, uint32_t);
MTR_JsonAddItemToArrayFunc MTR_JsonAddItemToArray;

typedef uint32_t (MTR_CALL * MTR_JsonAddStringToArrayFunc)(uint32_t,
 const char *);
MTR_JsonAddStringToArrayFunc MTR_JsonAddStringToArray;

typedef uint32_t (MTR_CALL * MTR_JsonAddDoubleToArrayFunc)(uint32_t, double);
MTR_JsonAddDoubleToArrayFunc MTR_JsonAddDoubleToArray;

typedef uint32_t (MTR_CALL * MTR_JsonAddBoolToArrayFunc)(uint32_t, bool);
MTR_JsonAddBoolToArrayFunc MTR_JsonAddBoolToArray;

typedef uint32_t (MTR_CALL * MTR_JsonAddNullToArrayFunc)(uint32_t);
MTR_JsonAddNullToArrayFunc MTR_JsonAddNullToArray;

typedef uint32_t (MTR_CALL * MTR_JsonGetObjectItemFunc)(uint32_t, const char *);
MTR_JsonGetObjectItemFunc MTR_JsonGetObjectItem;

typedef uint32_t (MTR_CALL * MTR_JsonGetArrayItemFunc)(uint32_t, int);
MTR_JsonGetArrayItemFunc MTR_JsonGetArrayItem;

typedef char *(MTR_CALL * MTR_JsonToStringFunc)(uint32_t);
MTR_JsonToStringFunc MTR_JsonToString;

typedef char *(MTR_CALL * MTR_JsonToStringFormattedFunc)(uint32_t);
MTR_JsonToStringFormattedFunc MTR_JsonToStringFormatted;

typedef char *(MTR_CALL * MTR_JsonToFileFunc)(uint32_t, const char *);
MTR_JsonToFileFunc MTR_JsonToFile;

typedef char *(MTR_CALL * MTR_JsonToFileFormattedFunc)(uint32_t, const char *);
MTR_JsonToFileFormattedFunc MTR_JsonToFileFormatted;

typedef void (MTR_CALL * MTR_JsonDeleteFunc)(uint32_t);
MTR_JsonDeleteFunc MTR_JsonDelete;

typedef void (MTR_CALL * MTR_JsonDeleteItemFromObjectFunc)(uint32_t,
 const char *);
MTR_JsonDeleteItemFromObjectFunc MTR_JsonDeleteItemFromObject;

typedef void (MTR_CALL * MTR_JsonDeleteItemFromArrayFunc)(uint32_t, int);
MTR_JsonDeleteItemFromArrayFunc MTR_JsonDeleteItemFromArray;

typedef void (MTR_CALL * MTR_JsonDetachItemFromObjectFunc)(uint32_t, uint32_t);
MTR_JsonDetachItemFromObjectFunc MTR_JsonDetachItemFromObject;

typedef void (MTR_CALL * MTR_JsonDetachItemFromArrayFunc)(uint32_t, uint32_t);
MTR_JsonDetachItemFromArrayFunc MTR_JsonDetachItemFromArray;

typedef bool (MTR_CALL * MTR_JsonObjectHasItemFunc)(uint32_t, const char *);
MTR_JsonObjectHasItemFunc MTR_JsonObjectHasItem;

typedef int (MTR_CALL * MTR_JsonLengthFunc)(uint32_t);
MTR_JsonLengthFunc MTR_JsonLength;

#endif
