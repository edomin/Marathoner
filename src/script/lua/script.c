#include "script.h"

#include "marathoner/plugin_common.c"
#include "../common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Scripts, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Script_Lua";
    report->version = MTR_VERSION_SCRIPT_LUA;
    report->subsystem = "script";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

void mtrScriptsInit(void)
{
    uint8_t i;
    uint8_t j;

    mtrLogWrite("Initializing script subsystem", 0, MTR_LMT_INFO);

    mtrLogWrite_s("Reporting Lua compile-time version:", 1, MTR_LMT_INFO,
     LUA_RELEASE);

    mtrVm = luaL_newstate();
    if (mtrVm != NULL)
        mtrLogWrite("Lua VM created", 1, MTR_LMT_INFO);
    else
        mtrNotify("Unable to create Lua VM", 1, MTR_DMT_FATAL);
    luaL_openlibs(mtrVm);
    mtrLogWrite("Lua libs opened", 1, MTR_LMT_INFO);
    /* Registering functions and constants from all binding plugins */
    mtrLogWrite("Registering functions and constants of engine", 1,
     MTR_LMT_INFO);
    mtrScriptsRegisterNumericVariable("IKDM_SMALL", MTR_IKDM_SMALL);
    mtrScriptsRegisterNumericVariable("IKDM_MEDIUM", MTR_IKDM_MEDIUM);
    mtrScriptsRegisterNumericVariable("IKDM_LARGE", MTR_IKDM_LARGE);
    mtrScriptsRegisterNumericVariable("FM_READ", MTR_FM_READ);
    mtrScriptsRegisterNumericVariable("FM_WRITE", MTR_FM_WRITE);
    mtrScriptsRegisterNumericVariable("FM_APPEND", MTR_FM_APPEND);
    mtrScriptsRegisterNumericVariable("LMT_INFO", MTR_LMT_INFO);
    mtrScriptsRegisterNumericVariable("LMT_NOTE", MTR_LMT_NOTE);
    mtrScriptsRegisterNumericVariable("LMT_WARNING", MTR_LMT_WARNING);
    mtrScriptsRegisterNumericVariable("LMT_ERROR", MTR_LMT_ERROR);
    mtrScriptsRegisterNumericVariable("LMT_FATAL", MTR_LMT_FATAL);
    mtrScriptsRegisterNumericVariable("LMT_DEBUG", MTR_LMT_DEBUG);
    mtrScriptsRegisterNumericVariable("DMT_INFO", MTR_DMT_INFO);
    mtrScriptsRegisterNumericVariable("DMT_NOTE", MTR_DMT_NOTE);
    mtrScriptsRegisterNumericVariable("DMT_WARNING", MTR_DMT_WARNING);
    mtrScriptsRegisterNumericVariable("DMT_ERROR", MTR_DMT_ERROR);
    mtrScriptsRegisterNumericVariable("DMT_FATAL", MTR_DMT_FATAL);
    mtrScriptsRegisterNumericVariable("DMT_DEBUG", MTR_DMT_DEBUG);
    mtrScriptsRegisterNumericVariable("FA_NO", MTR_FA_NO);
    mtrScriptsRegisterNumericVariable("FA_DUMMY", MTR_FA_DUMMY);
    mtrScriptsRegisterNumericVariable("FA_BUGGY", MTR_FA_BUGGY);
    mtrScriptsRegisterNumericVariable("FA_PARTIAL", MTR_FA_PARTIAL);
    mtrScriptsRegisterNumericVariable("FA_YES", MTR_FA_YES);

    mtrScriptsRegisterFunction(mtrSF_ScriptsFunctionSupported,
     "ScriptsFunctionSupported");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterStringVariable,
     "RegisterStringVariable");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterNumericVariable,
     "RegisterNumericVariable");

    mtrScriptsRegisterFunction(mtrSF_MarathonerGetVersion,
     "MarathonerGetVersion");
    mtrScriptsRegisterFunction(mtrSF_MarathonerGetModuleVersion,
     "MarathonerGetModuleVersion");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileGetKeyName,
     "ConfigfileGetKeyName");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileGetSectionName,
     "ConfigfileGetSectionName");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileDeleteKey,
     "ConfigfileDeleteKey");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileDeleteSection,
     "ConfigfileDeleteSection");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadBool, "ConfigfileReadBool");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadInt, "ConfigfileReadInt");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadSingle,
     "ConfigfileReadSingle");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadString,
     "ConfigfileReadString");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileWriteBool,
     "ConfigfileWriteBool");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileWriteInt, "ConfigfileWriteInt");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileWriteSingle,
     "ConfigfileWriteSingle");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileWriteString,
     "ConfigfileWriteString");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileCreateSection,
     "ConfigfileCreateSection");

    mtrScriptsRegisterFunction(mtrSF_LogWrite, "LogWrite");
    mtrScriptsRegisterFunction(mtrSF_LogWrite_s, "LogWrite_s");
    mtrScriptsRegisterFunction(mtrSF_LogWrite_i, "LogWrite_i");
    mtrScriptsRegisterFunction(mtrSF_LogWrite_d, "LogWrite_d");

    mtrScriptsRegisterFunction(mtrSF_ShowSimpleMessageBox,
     "ShowSimpleMessageBox");
    mtrScriptsRegisterFunction(mtrSF_ShowYesNoMessageBox,
     "ShowYesNoMessageBox");
    mtrScriptsRegisterFunction(mtrSF_ShowOkCancelMessageBox,
     "ShowOkCancelMessageBox");
    mtrScriptsRegisterFunction(mtrSF_ShowInputDialog, "ShowInputDialog");
    mtrScriptsRegisterFunction(mtrSF_ShowPasswordDialog, "ShowPasswordDialog");
    mtrScriptsRegisterFunction(mtrSF_AddFileFilter, "AddFileFilter");
    mtrScriptsRegisterFunction(mtrSF_ClearFileFilters, "ClearFileFilters");
    mtrScriptsRegisterFunction(mtrSF_ShowSaveFileDialog, "ShowSaveFileDialog");
    mtrScriptsRegisterFunction(mtrSF_ShowOpenFileDialog, "ShowOpenFileDialog");
    mtrScriptsRegisterFunction(mtrSF_ShowSelectFolderDialog,
     "ShowSelectFolderDialog");

    mtrScriptsRegisterFunction(mtrSF_Notify, "Notify");

    mtrScriptsRegisterFunction(mtrSF_EncodingUtf8Codepoints,
     "EncodingUtf8Codepoints");

    mtrScriptsRegisterFunction(mtrSF_FileOpen, "FileOpen");
    mtrScriptsRegisterFunction(mtrSF_FileClose, "FileClose");
    mtrScriptsRegisterFunction(mtrSF_FileRead, "FileRead");
    mtrScriptsRegisterFunction(mtrSF_FileWrite, "FileWrite");
    mtrScriptsRegisterFunction(mtrSF_FileWriteLine, "FileWriteLine");
    mtrScriptsRegisterFunction(mtrSF_FileWriteFast, "FileWriteFast");
    mtrScriptsRegisterFunction(mtrSF_FileWriteLineFast, "FileWriteLineFast");

    mtrScriptsRegisterFunction(mtrSF_ClipboardPutText, "ClipboardPutText");
    mtrScriptsRegisterFunction(mtrSF_ClipboardGetText, "ClipboardGetText");

    mtrScriptsRegisterFunction(mtrSF_StringBufferAdd, "StringBufferAdd");
    mtrScriptsRegisterFunction(mtrSF_StringBufferDelete, "StringBufferDelete");
    mtrScriptsRegisterFunction(mtrSF_StringBufferSetString,
     "StringBufferSetString");
    mtrScriptsRegisterFunction(mtrSF_StringBufferGetString,
     "StringBufferGetString");
    mtrScriptsRegisterFunction(mtrSF_StringBufferGetMaxLen,
     "StringBufferGetMaxLen");

    mtrScriptsRegisterFunction(mtrSF_OptionsAlias, "OptionsAlias");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet, "OptionsGet");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet_i, "OptionsGet_i");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet_l, "OptionsGet_l");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet_f, "OptionsGet_f");
    mtrScriptsRegisterFunction(mtrSF_OptionsGet_d, "OptionsGet_d");

    mtrLogWrite("Script functions and constants of engine registered",
     1, MTR_LMT_INFO);
    /* Registering functions and constants from all binding plugins */
    mtrLogWrite("Registering functions and constants of bindings", 1,
     MTR_LMT_INFO);
    for (i = 0; i < mtrPluginsCount; i++)
    {
        for (j = 0; j < mtrPluginData[i].report->prereqsCount; j++)
        {
            if (strcmp(mtrPluginData[i].report->prereqs[j], "Script_Lua") == 0)
            {
                mtrLogWrite_s("Binding found:", 2, MTR_LMT_INFO,
                 mtrPluginData[i].report->moduleID);
                mtrPluginInit = (mtrPluginInitFunc)mtrFindFunction(
                 mtrPluginData[i].report->moduleID, "mtrPluginInit");
                if (mtrPluginInit != NULL)
                    mtrPluginInit();
                else
                    mtrNotify("Library not contain mtrPluginInit function", 1,
                     MTR_LMT_ERROR);
            }
        }
    }

    mtrLogWrite("Script functions and constants of bindings registered",
     1, MTR_LMT_INFO);
    mtrLogWrite("Script subsystem initialized", 0, MTR_LMT_INFO);
}

MTR_EXPORT lua_State * MTR_CALL mtrScriptsGetVm(void)
{
    return mtrVm;
}

MTR_EXPORT char * MTR_CALL mtrScriptsGetAutorunPath(void)
{
    return mtrAutorun;
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(lua_CFunction func,
 const char * funcname)
{
    lua_register(mtrVm, funcname, func); /* регистрируем функцию */
    mtrLogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
}

/*fa mtrScriptsRegisterStringVariable yes */
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value)
{
    if ((name != NULL) && (strcmp(name, "") != 0)) {
        lua_pushstring(mtrVm, value);
        lua_setglobal(mtrVm, name);
        mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        mtrLogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa mtrScriptsRegisterNumericVariable yes */
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushnumber(mtrVm, value);
        lua_setglobal(mtrVm, name);
        mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        mtrLogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

void mtrScriptsDoFile(const char * filename)
{
    bool error;
    error = luaL_dofile(mtrVm, filename);
    if (error)
    {
        mtrNotify("Error in the script or script file not found.", 0,
         MTR_DMT_ERROR);
        mtrLogWrite(lua_tostring(mtrVm, -1), 0, MTR_LMT_ERROR);
    }
}

void mtrScriptsQuit(void)
{
    lua_close(mtrVm);
    mtrLogWrite("Lua VM closed", 0, MTR_LMT_INFO);
}

MTR_EXPORT void MTR_CALL mtrScriptsAutorun(char * filename)
{
    mtrScriptsInit();
    mtrAutorun = filename;
    mtrScriptsDoFile(filename);
}
