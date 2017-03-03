#include "script.h"

#include "marathoner/plugin_common.c"
#include "../common.c"

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
    mtrScriptsRegisterNumericVariable("FM_WRITE", MTR_FM_WRITE);
    mtrScriptsRegisterNumericVariable("FM_APPEND", MTR_FM_APPEND);

    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterStringVariable,
     "RegisterStringVariable");
    mtrScriptsRegisterFunction(mtrSF_ScriptsRegisterNumericVariable,
     "RegisterNumericVariable");

    mtrScriptsRegisterFunction(mtrSF_ConfigfileGetKeyName,
     "ConfigfileGetKeyName");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileGetSectionName,
     "ConfigfileGetSectionName");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileDeleteKey,
     "ConfigfileDeleteKey");
    mtrScriptsRegisterFunction(mtrSF_ConfigfileReadBool, "ConfigfileReadBool");
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
    mtrScriptsRegisterFunction(mtrSF_ShowSelectFolderDialog,
     "ShowSelectFolderDialog");

    mtrScriptsRegisterFunction(mtrSF_Notify, "Notify");

    mtrScriptsRegisterFunction(mtrSF_EncodingUtf8Codepoints,
     "EncodingUtf8Codepoints");

    mtrScriptsRegisterFunction(mtrSF_FileWriteLine, "FileWriteLine");

    mtrScriptsRegisterFunction(mtrSF_ClipboardPutText, "ClipboardPutText");
    mtrScriptsRegisterFunction(mtrSF_ClipboardGetText, "ClipboardGetText");

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
                 mtrPluginInit = (mtrPluginInitFunc)mtrFindFunction(mtrPluginData[i].report->moduleID, "mtrPluginInit");
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

MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(lua_CFunction func,
 const char * funcname)
{
    lua_register(mtrVm, funcname, func); /* регистрируем функцию */
    mtrLogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value)
{
    lua_pushstring(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value)
{
    lua_pushnumber(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
}

void mtrScriptsDoFile(const char * filename)
{
    bool error;
    error = luaL_dofile(mtrVm, filename);
    if (error)
    {
        mtrNotify("Error in the script or script file not found.", 0,
         MTR_DMT_ERROR);
        mtrLogWrite((char *)(lua_tostring(mtrVm, -1)), 0, MTR_LMT_ERROR);
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
    mtrScriptsDoFile(filename);
}
