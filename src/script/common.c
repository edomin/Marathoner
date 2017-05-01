#ifndef MTR_SCRIPT_COMMON_C
#define MTR_SCRIPT_COMMON_C

#include "marathoner/script_func.h"

/*
TODO:
ShowSaveFileDialog
ShowOpenFileDialog
*/

MTR_SCRIPT_FUNC(mtrSF_ScriptsRegisterStringVariable)
{
    const char *varName;
    const char *value;

    MTR_SF_GET_STRING(varName, 1);
    MTR_SF_GET_STRING(value, 2);
    mtrScriptsRegisterStringVariable(varName, value);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_ScriptsRegisterNumericVariable)
{
    const char *varName;
    double      value;

    MTR_SF_GET_STRING(varName, 1);
    MTR_SF_GET_DOUBLE(value, 2);
    mtrScriptsRegisterNumericVariable(varName, value);

    return 0;
}

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

MTR_SCRIPT_FUNC(mtrSF_ConfigfileWriteBool)
{
    const char *filename;
    const char *section;
    const char *key;
    bool        value;
    bool        result;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(section, 2);
    MTR_SF_GET_STRING(key, 3);
    MTR_SF_GET_BOOL(value, 4);
    result = mtrConfigfileWriteBool(filename, section, key, value);

    MTR_SF_PUSH_BOOL(result);

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

MTR_SCRIPT_FUNC(mtrSF_LogWrite)
{
    const char *message;
    uint8_t     level;
    uint8_t     messageType;

    MTR_SF_GET_STRING(message, 1);
    MTR_SF_GET_UINT8(level, 2);
    MTR_SF_GET_UINT8(messageType, 3);
    mtrLogWrite(message, level, messageType);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_LogWrite_s)
{
    const char *message;
    uint8_t     level;
    uint8_t     messageType;
    const char *argument;

    MTR_SF_GET_STRING(message, 1);
    MTR_SF_GET_UINT8(level, 2);
    MTR_SF_GET_UINT8(messageType, 3);
    MTR_SF_GET_STRING(argument, 4);
    mtrLogWrite_s(message, level, messageType, argument);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_LogWrite_i)
{
    const char *message;
    uint8_t     level;
    uint8_t     messageType;
    uint32_t    argument;

    MTR_SF_GET_STRING(message, 1);
    MTR_SF_GET_UINT8(level, 2);
    MTR_SF_GET_UINT8(messageType, 3);
    MTR_SF_GET_UINT32(argument, 4);
    mtrLogWrite_i(message, level, messageType, argument);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_LogWrite_d)
{
    const char *message;
    uint8_t     level;
    uint8_t     messageType;
    double      argument;

    MTR_SF_GET_STRING(message, 1);
    MTR_SF_GET_UINT8(level, 2);
    MTR_SF_GET_UINT8(messageType, 3);
    MTR_SF_GET_DOUBLE(argument, 4);
    mtrLogWrite_d(message, level, messageType, argument);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_ShowSimpleMessageBox)
{
    uint8_t     type;
    const char *title;
    const char *message;

    MTR_SF_GET_UINT8(type, 1);
    MTR_SF_GET_STRING(title, 2);
    MTR_SF_GET_STRING(message, 3);
    mtrShowSimpleMessageBox(type, title, message);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_ShowYesNoMessageBox)
{
    const char *title;
    const char *message;
    bool        result;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_STRING(message, 2);
    result = mtrShowYesNoMessageBox(title, message);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ShowOkCancelMessageBox)
{
    const char *title;
    const char *message;
    bool        result;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_STRING(message, 2);
    result = mtrShowOkCancelMessageBox(title, message);

    MTR_SF_PUSH_BOOL(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ShowInputDialog)
{
    const char *title;
    const char *message;
    const char *defaultInput;
    const char *result;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_STRING(message, 2);
    MTR_SF_GET_STRING(defaultInput, 3);
    result = mtrShowInputDialog(title, message, defaultInput);

    MTR_SF_PUSH_STRING(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ShowPasswordDialog)
{
    const char *title;
    const char *message;
    const char *result;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_STRING(message, 2);
    result = mtrShowPasswordDialog(title, message);

    MTR_SF_PUSH_STRING(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ShowSelectFolderDialog)
{
    const char *title;
    const char *defaultPath;
    const char *result;

    MTR_SF_GET_STRING(title, 1);
    MTR_SF_GET_STRING(defaultPath, 2);
    result = mtrShowSelectFolderDialog(title, defaultPath);

    MTR_SF_PUSH_STRING(result);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_Notify)
{
    const char *message;
    uint8_t     level;
    uint8_t     messageType;

    MTR_SF_GET_STRING(message, 1);
    MTR_SF_GET_UINT8(level, 2);
    MTR_SF_GET_UINT8(messageType, 3);
    mtrNotify(message, level, messageType);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_EncodingUtf8Codepoints)
{
    const char *string;
    uint32_t    codepoints;

    MTR_SF_GET_STRING(string, 1);
    codepoints = mtrEncodingUtf8Codepoints(string);

    MTR_SF_PUSH_UINT32(codepoints);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FileOpen)
{
    const char *filename;
    int         mode;
    uint32_t    index;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_INT(mode, 2);
    index = mtrFileOpen(filename, mode);

    MTR_SF_PUSH_UINT32(index);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FileClose)
{
    uint32_t index;
    bool     success;

    MTR_SF_GET_UINT32(index, 1);
    success = mtrFileClose(index);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FileRead)
{
    uint32_t   index;
    char      *text;
    #ifdef lua_h
        size_t size;
    #endif /* lua_h */

    MTR_SF_GET_UINT32(index, 1);
    #ifdef lua_h
        size = mtrFileRead(index, &text);
    #else /* lua_h */
        mtrFileRead(index, &text);
    #endif /* lua_h */

    MTR_SF_PUSH_STRING(text);
    #ifdef lua_h
        MTR_SF_PUSH_SIZE(size);
        return 2;
    #else /* lua_h */
        return 1;
    #endif /* lua_h */
}

MTR_SCRIPT_FUNC(mtrSF_FileWrite)
{
    uint32_t    index;
    const char *string;
    bool        success;

    MTR_SF_GET_UINT32(index, 1);
    MTR_SF_GET_STRING(string, 2);
    success = mtrFileWrite(index, string);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FileWriteLine)
{
    uint32_t    index;
    const char *string;
    bool        success;

    MTR_SF_GET_UINT32(index, 1);
    MTR_SF_GET_STRING(string, 2);
    success = mtrFileWriteLine(index, string);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_FileWriteFast)
{
    const char *filename;
    const char *string;
    int         mode;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(string, 2);
    MTR_SF_GET_INT(mode, 3);
    mtrFileWriteFast(filename, string, mode);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_FileWriteLineFast)
{
    const char *filename;
    const char *string;
    int         mode;

    MTR_SF_GET_STRING(filename, 1);
    MTR_SF_GET_STRING(string, 2);
    MTR_SF_GET_INT(mode, 3);
    mtrFileWriteLineFast(filename, string, mode);

    return 0;
}

MTR_SCRIPT_FUNC(mtrSF_ClipboardPutText)
{
    const char *text;
    bool        success;

    MTR_SF_GET_STRING(text, 1);
    success = mtrClipboardPutText(text);

    MTR_SF_PUSH_BOOL(success);

    return 1;
}

MTR_SCRIPT_FUNC(mtrSF_ClipboardGetText)
{
    char *text;

    text = mtrClipboardGetText();

    MTR_SF_PUSH_STRING(text);

    return 1;
}

#endif
