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

    mtrScriptsRegisterAll();

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

/*fa mtrScriptsRegisterVariable_b yes */
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterVariable_b(const char *name,
 bool value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushboolean(mtrVm, value);
        lua_setglobal(mtrVm, name);
        mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        mtrLogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa mtrScriptsRegisterVariable_i yes */
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterVariable_i(const char *name,
 int value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushinteger(mtrVm, value);
        lua_setglobal(mtrVm, name);
        mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        mtrLogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa mtrScriptsRegisterVariable_u yes */
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterVariable_u(const char *name,
 unsigned int value)
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

/*fa mtrScriptsRegisterVariable_f yes */
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterVariable_f(const char *name,
 float value)
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

/*fa mtrScriptsRegisterVariable_d yes */
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterVariable_d(const char *name,
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

/*fa mtrScriptsRegisterVariable_s yes */
MTR_EXPORT bool MTR_CALL mtrScriptsRegisterVariable_s(const char *name,
 const char *value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
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
