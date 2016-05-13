#include "script.h"

#include "plugin_common.c"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Script_Lua52";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

void mtrScriptsInit(void)
{
    mtrLogWrite("Initializing script subsystem", 0, MTR_LMT_INFO);
    mtrVm = luaL_newstate();
    if (mtrVm != NULL)
        mtrLogWrite("Lua VM created", 1, MTR_LMT_INFO);
    else
        mtrNotify("Unable to create Lua VM", 1, MTR_DMT_FATAL);
    luaL_openlibs(mtrVm);
    mtrLogWrite("Lua libs opened", 1, MTR_LMT_INFO);
    /* Registering functions from all binding plugins */
    mtrLogWrite("Script functions registered", 1, MTR_LMT_INFO);
    mtrLogWrite("Script subsystem initialized", 0, MTR_LMT_INFO);
}

__declspec(dllexport) lua_State * __stdcall mtrScriptsGetVm(void)
{
    return mtrVm;
}

__declspec(dllexport) void __stdcall mtrScriptsRegisterFunction(lua_CFunction func, char * funcname)
{
    lua_register(mtrVm, funcname, func); /* регистрируем функцию */
    mtrLogWrite_s("Script function added:", 0, MTR_LMT_INFO, funcname);
}

void mtrScriptsRegisterStringVariable(char *name, char *value)
{
    lua_pushstring(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 0, MTR_LMT_INFO, name);
}

void mtrScriptsRegisterNumericVariable(char *name, double value)
{
    lua_pushnumber(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 0, MTR_LMT_INFO, name);
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
