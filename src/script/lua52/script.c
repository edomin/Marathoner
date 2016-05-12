#include "script.h"

__declspec(dllexport) mtrReport* __stdcall mtrCreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    report->moduleID = "Script_Lua52";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    return report;
}

__declspec(dllexport) void __stdcall mtrRequireEngineFuncs(mtrLogWriteFunc_t LogWriteFunc,
                           mtrLogWrite_sFunc_t LogWrite_sFunc,
                           mtrLogWrite_iFunc_t LogWrite_iFunc,
                           mtrLogWrite_dFunc_t LogWrite_dFunc,
                           mtrNotifyFunc_t NotifyFunc)
{
    mtrLogWrite = LogWriteFunc;
    mtrLogWrite_s = LogWrite_sFunc;
    mtrLogWrite_i = LogWrite_iFunc;
    mtrLogWrite_d = LogWrite_dFunc;
    mtrNotify = NotifyFunc;
}

void ScriptsInit(void)
{
    mtrLogWrite("Initializing script subsystem", 0, MTR_LMT_INFO);
    mtrVm = luaL_newstate();
    if (mtrVm != NULL)
        mtrLogWrite("Lua VM created", 1, MTR_LMT_INFO);
    else
        mtrNotify("Unable to create Lua VM", 1, MTR_DMT_FATAL);
    luaL_openlibs(mtrVm);
    mtrLogWrite("Lua libs opened", 1, MTR_LMT_INFO);
//    RegisterAll();
//    mtrLogWrite("Script functions registered", 1, MTR_LMT_INFO);
    mtrLogWrite("Script subsystem initialized", 0, MTR_LMT_INFO);
}

void ScriptsRegisterFunction(lua_CFunction func, char * funcname)
{
    lua_register(mtrVm, funcname, func); /* регистрируем функцию */
    mtrLogWrite_s("Script function added:", 0, MTR_LMT_INFO, funcname);
}

void ScriptsRegisterStringVariable(char *name, char *value)
{
    lua_pushstring(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 0, MTR_LMT_INFO, name);
}

void ScriptsRegisterNumericVariable(char *name, double value)
{
    lua_pushnumber(mtrVm, value);
    lua_setglobal(mtrVm, name);
    mtrLogWrite_s("Script const added:", 0, MTR_LMT_INFO, name);
}

void ScriptsDoFile(char * filename)
{
    bool error;
    error = luaL_dofile(mtrVm, filename);
    if (error)
    {
        mtrNotify("Error in the script or script file not found.", 0, MTR_DMT_ERROR);
        mtrLogWrite((char *)(lua_tostring(mtrVm, -1)), 0, MTR_LMT_ERROR);
    }
}

void ScriptsQuit(void)
{
    lua_close(mtrVm);
    mtrLogWrite("Lua VM closed", 0, MTR_LMT_INFO);
}
