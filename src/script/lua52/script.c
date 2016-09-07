#include "script.h"

#include "marathoner/plugin_common.c"

MRT_EXPORT mtrReport* MRT_CALL mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Script_Lua52";
    report->version = MTR_VERSION_SCRIPT_LUA;
    report->prereqsCount = 0;
    report->prereqs = NULL;
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
    mtrScriptsRegisterFunction(mtrSF_FileWriteLine, "FileWriteLine");
    mtrLogWrite("Script functions and constants of engine registered",
     1, MTR_LMT_INFO);
    /* Registering functions and constants from all binding plugins */
    mtrLogWrite("Registering functions and constants of bindings", 1,
     MTR_LMT_INFO);
    for (i = 0; i < mtrPluginsCount; i++)
    {
        for (j = 0; j < mtrPluginData[i].report->prereqsCount; j++)
        {
            if (strcmp(mtrPluginData[i].report->prereqs[j], "Script_Lua52") == 0)
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

MRT_EXPORT lua_State * MRT_CALL mtrScriptsGetVm(void)
{
    return mtrVm;
}

MRT_EXPORT void MRT_CALL mtrScriptsRegisterFunction(lua_CFunction func,
 char * funcname)
{
    lua_register(mtrVm, funcname, func); /* регистрируем функцию */
    mtrLogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
}

MRT_EXPORT void MRT_CALL mtrScriptsRegisterStringVariable(char *name,
 char *value)
{
    lua_pushstring(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
}

MRT_EXPORT void MRT_CALL mtrScriptsRegisterNumericVariable(char *name,
 double value)
{
    lua_pushnumber(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
}

void mtrScriptsDoFile(char * filename)
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

MRT_EXPORT void MRT_CALL mtrScriptsAutorun(char * filename)
{
    mtrScriptsInit();
    mtrScriptsDoFile(filename);
}

int mtrSF_FileWriteLine(lua_State* l)
{
    const char *filename = lua_tostring(mtrVm, 1);
    const char *string = lua_tostring(mtrVm, 2);
    uint8_t mode = lua_tointeger(mtrVm, 3);
    mtrFileWriteLine(filename, string, mode);

    return 0;
}
