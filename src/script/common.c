#include "marathoner/script_func.h"

MTR_SCRIPT_FUNC(mtrSF_ConfigfileGetKeyName)
{
    const char *filename;
    const char *section;
    int         index;
    char       *result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_INT(index, 3);
    result = mtrConfigfileGetKeyName(filename, section, index);

    MTR_SF_PUSH_STRING(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileGetSectionName)
{
    const char *filename;
    int         index;
    char       *result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_INT(index, 2);
    result = mtrConfigfileGetSectionName(filename, index);

    MTR_SF_PUSH_STRING(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileDeleteKey)
{
    const char *filename;
    const char *section;
    const char *key;
    bool        result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    result = mtrConfigfileDeleteKey(filename, section, key);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileDeleteSection)
{
    const char *filename;
    const char *section;
    bool        result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    result = mtrConfigfileDeleteSection(filename, section);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileReadBool)
{
    const char *filename;
    const char *section;
    const char *key;
    bool        defaultValue;
    bool        result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    MTR_SF_GET_BOOL(defaultValue, 4);
    result = mtrConfigfileReadBool(filename, section, key, defaultValue);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileReadInt)
{
    const char *filename;
    const char *section;
    const char *key;
    int         defaultValue;
    int         result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    MTR_SF_GET_INT(defaultValue, 4);
    result = mtrConfigfileReadInt(filename, section, key, defaultValue);

    MTR_SF_PUSH_INT(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileReadSingle)
{
    const char *filename;
    const char *section;
    const char *key;
    float       defaultValue;
    float       result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    MTR_SF_GET_SINGLE(defaultValue, 4);
    result = mtrConfigfileReadSingle(filename, section, key, defaultValue);

    MTR_SF_PUSH_SINGLE(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileReadString)
{
    const char *filename;
    const char *section;
    const char *key;
    const char *defaultValue;
    char       *result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    MTR_SF_GET_STRING(defaultValue, 4);
    result = mtrConfigfileReadString(filename, section, key, defaultValue);

    MTR_SF_PUSH_STRING(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileWriteInt)
{
    const char *filename;
    const char *section;
    const char *key;
    int         value;
    bool        result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    MTR_SF_GET_INT(value, 4);
    result = mtrConfigfileWriteInt(filename, section, key, value);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileWriteSingle)
{
    const char *filename;
    const char *section;
    const char *key;
    float       value;
    bool        result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    MTR_SF_GET_SINGLE(value, 4);
    result = mtrConfigfileWriteSingle(filename, section, key, value);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ConfigfileWriteString)
{
    const char *filename;
    const char *section;
    const char *key;
    const char *value;
    bool        result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    MTR_SF_GET_STRING(value, 4);
    result = mtrConfigfileWriteString(filename, section, key, value);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FileWriteLine)
{
    const char *filename;
    const char *string;
    int         mode;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(string, 2);
    MTR_SF_GET_INT(mode, 3);
    mtrFileWriteLine(filename, string, mode);

    return 0;
}