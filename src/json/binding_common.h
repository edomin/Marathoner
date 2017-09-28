#ifndef MTR_JSON_BINDING_COMMON_H
#define MTR_JSON_BINDING_COMMON_H

typedef int (MTR_CALL * mtrJsonFunctionSupportedFunc)(const char *);
mtrJsonFunctionSupportedFunc mtrJsonFunctionSupported;

typedef bool (MTR_CALL * mtrJsonInitFunc)(uint32_t, uint32_t);
mtrJsonInitFunc mtrJsonInit;

typedef uint32_t (MTR_CALL * mtrJsonCreateObjectFunc)(void);
mtrJsonCreateObjectFunc mtrJsonCreateObject;

typedef uint32_t (MTR_CALL * mtrJsonCreateArrayFunc)(void);
mtrJsonCreateArrayFunc mtrJsonCreateArray;

typedef uint32_t (MTR_CALL * mtrJsonParseStringFunc)(const char *);
mtrJsonParseStringFunc mtrJsonParseString;

typedef uint32_t (MTR_CALL * mtrJsonParseFileFunc)(const char *);
mtrJsonParseFileFunc mtrJsonParseFile;

typedef uint32_t (MTR_CALL * mtrJsonAddItemToObjectFunc)(uint32_t, const char *,
 uint32_t);
mtrJsonAddItemToObjectFunc mtrJsonAddItemToObject;

typedef uint32_t (MTR_CALL * mtrJsonAddStringToObjectFunc)(uint32_t,
 const char *, const char *);
mtrJsonAddStringToObjectFunc mtrJsonAddStringToObject;

typedef uint32_t (MTR_CALL * mtrJsonAddDoubleToObjectFunc)(uint32_t,
 const char *, double);
mtrJsonAddDoubleToObjectFunc mtrJsonAddDoubleToObject;

typedef uint32_t (MTR_CALL * mtrJsonAddBoolToObjectFunc)(uint32_t, const char *,
 bool);
mtrJsonAddBoolToObjectFunc mtrJsonAddBoolToObject;

typedef uint32_t (MTR_CALL * mtrJsonAddNullToObjectFunc)(uint32_t,
 const char *);
mtrJsonAddNullToObjectFunc mtrJsonAddNullToObject;

typedef uint32_t (MTR_CALL * mtrJsonAddItemToArrayFunc)(uint32_t, uint32_t);
mtrJsonAddItemToArrayFunc mtrJsonAddItemToArray;

typedef uint32_t (MTR_CALL * mtrJsonAddStringToArrayFunc)(uint32_t,
 const char *);
mtrJsonAddStringToArrayFunc mtrJsonAddStringToArray;

typedef uint32_t (MTR_CALL * mtrJsonAddDoubleToArrayFunc)(uint32_t, double);
mtrJsonAddDoubleToArrayFunc mtrJsonAddDoubleToArray;

typedef uint32_t (MTR_CALL * mtrJsonAddBoolToArrayFunc)(uint32_t, bool);
mtrJsonAddBoolToArrayFunc mtrJsonAddBoolToArray;

typedef uint32_t (MTR_CALL * mtrJsonAddNullToArrayFunc)(uint32_t);
mtrJsonAddNullToArrayFunc mtrJsonAddNullToArray;

typedef uint32_t (MTR_CALL * mtrJsonGetObjectItemFunc)(uint32_t, const char *);
mtrJsonGetObjectItemFunc mtrJsonGetObjectItem;

typedef uint32_t (MTR_CALL * mtrJsonGetArrayItemFunc)(uint32_t, int);
mtrJsonGetArrayItemFunc mtrJsonGetArrayItem;

typedef char *(MTR_CALL * mtrJsonToStringFunc)(uint32_t);
mtrJsonToStringFunc mtrJsonToString;

typedef char *(MTR_CALL * mtrJsonToStringFormattedFunc)(uint32_t);
mtrJsonToStringFormattedFunc mtrJsonToStringFormatted;

typedef char *(MTR_CALL * mtrJsonToFileFunc)(uint32_t, const char *);
mtrJsonToFileFunc mtrJsonToFile;

typedef char *(MTR_CALL * mtrJsonToFileFormattedFunc)(uint32_t, const char *);
mtrJsonToFileFormattedFunc mtrJsonToFileFormatted;

typedef void (MTR_CALL * mtrJsonDeleteFunc)(uint32_t);
mtrJsonDeleteFunc mtrJsonDelete;

typedef void (MTR_CALL * mtrJsonDeleteItemFromObjectFunc)(uint32_t,
 const char *);
mtrJsonDeleteItemFromObjectFunc mtrJsonDeleteItemFromObject;

typedef void (MTR_CALL * mtrJsonDeleteItemFromArrayFunc)(uint32_t, int);
mtrJsonDeleteItemFromArrayFunc mtrJsonDeleteItemFromArray;

typedef void (MTR_CALL * mtrJsonDetachItemFromObjectFunc)(uint32_t, uint32_t);
mtrJsonDetachItemFromObjectFunc mtrJsonDetachItemFromObject;

typedef void (MTR_CALL * mtrJsonDetachItemFromArrayFunc)(uint32_t, uint32_t);
mtrJsonDetachItemFromArrayFunc mtrJsonDetachItemFromArray;

typedef bool (MTR_CALL * mtrJsonObjectHasItemFunc)(uint32_t, const char *);
mtrJsonObjectHasItemFunc mtrJsonObjectHasItem;

typedef int (MTR_CALL * mtrJsonLengthFunc)(uint32_t);
mtrJsonLengthFunc mtrJsonLength;

#endif
