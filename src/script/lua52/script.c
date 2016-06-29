#include "script.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Script_Lua52";
    report->version = 0x000000;
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

__declspec(dllexport) lua_State * __stdcall mtrScriptsGetVm(void)
{
    return mtrVm;
}

__declspec(dllexport) void __stdcall mtrScriptsRegisterFunction(lua_CFunction func, char * funcname)
{
    lua_register(mtrVm, funcname, func); /* регистрируем функцию */
    mtrLogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
}

__declspec(dllexport) void __stdcall mtrScriptsRegisterStringVariable(char *name, char *value)
{
    lua_pushstring(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
}

__declspec(dllexport) void __stdcall mtrScriptsRegisterNumericVariable(char *name, double value)
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
        mtrNotify("Error in the script or script file not found.", 0, MTR_DMT_ERROR);
        mtrLogWrite((char *)(lua_tostring(mtrVm, -1)), 0, MTR_LMT_ERROR);
    }
}

void mtrScriptsQuit(void)
{
    lua_close(mtrVm);
    mtrLogWrite("Lua VM closed", 0, MTR_LMT_INFO);
}

__declspec(dllexport) void __stdcall mtrScriptsAutorun(char * filename)
{
    mtrScriptsInit();
    mtrScriptsDoFile(filename);
}
