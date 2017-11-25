#include "script.h"

#ifdef MTR_MOD_PLUGIN
    #include "marathoner/plugin_common.c"
#endif
#include "../common.c"

#ifdef MTR_MOD_PLUGIN
MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
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
#endif

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Scripts, FA_FUNCTIONS_COUNT)

void MTR_ScriptsInit(void)
{
    #ifdef MTR_MOD_PLUGIN
    int i;
    int j;
    #endif

    MTR_LogWrite("Initializing script subsystem", 0, MTR_LMT_INFO);

    MTR_LogWrite_s("Reporting Lua compile-time version:", 1, MTR_LMT_INFO,
     LUA_RELEASE);

    mtrVm = luaL_newstate();
    if (mtrVm != NULL)
        MTR_LogWrite("Lua VM created", 1, MTR_LMT_INFO);
    else
        MTR_Notify("Unable to create Lua VM", 1, MTR_DMT_FATAL);
    luaL_openlibs(mtrVm);
    MTR_LogWrite("Lua libs opened", 1, MTR_LMT_INFO);
    /* Registering functions and constants from all binding plugins */
    MTR_LogWrite("Registering functions and constants of engine", 1,
     MTR_LMT_INFO);

    MTR_ScriptsRegisterAll();

    MTR_LogWrite("Script functions and constants of engine registered",
     1, MTR_LMT_INFO);
    /* Registering functions and constants from all binding plugins */
    MTR_LogWrite("Registering functions and constants of bindings", 1,
     MTR_LMT_INFO);
    #ifdef MTR_MOD_PLUGIN
    for (i = 0; i < mtrPluginsCount; i++)
    {
        for (j = 0; j < mtrPluginData[i].report->prereqsCount; j++)
        {
            if (strcmp(mtrPluginData[i].report->prereqs[j], "Script_Lua") == 0)
            {
                MTR_LogWrite_s("Binding found:", 2, MTR_LMT_INFO,
                 mtrPluginData[i].report->moduleID);
                MTR_PluginInit = (mtrPluginInitFunc)MTR_FindFunction(
                 mtrPluginData[i].report->moduleID, "MTR_PluginInit");
                if (MTR_PluginInit != NULL)
                    MTR_PluginInit();
                else
                    MTR_Notify("Library not contain MTR_PluginInit function", 1,
                     MTR_LMT_ERROR);
            }
        }
    }
    #else
        MTR_BifInitAll();
    #endif

    MTR_LogWrite("Script functions and constants of bindings registered",
     1, MTR_LMT_INFO);
    MTR_LogWrite("Script subsystem initialized", 0, MTR_LMT_INFO);
}

MTR_DCLSPC lua_State * MTR_CALL MTR_ScriptsGetVm(void)
{
    return mtrVm;
}

/*fa MTR_ScriptsGetAutorunPath yes */
MTR_DCLSPC char * MTR_CALL MTR_ScriptsGetAutorunPath(void)
{
    return mtrAutorun;
}

MTR_DCLSPC void MTR_CALL MTR_ScriptsRegisterFunction(lua_CFunction func,
 const char * funcname)
{
    lua_register(mtrVm, funcname, func); /* регистрируем функцию */
    MTR_LogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
}

/*fa MTR_ScriptsRegisterVariable_b yes */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_b(const char *name,
 bool value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushboolean(mtrVm, value);
        lua_setglobal(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_i yes */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_i(const char *name,
 int value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushinteger(mtrVm, value);
        lua_setglobal(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_u yes */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_u(const char *name,
 unsigned int value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushnumber(mtrVm, value);
        lua_setglobal(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_f yes */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_f(const char *name,
 float value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushnumber(mtrVm, (double)value);
        lua_setglobal(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_d yes */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_d(const char *name,
 double value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushnumber(mtrVm, value);
        lua_setglobal(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_s yes */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_s(const char *name,
 const char *value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        lua_pushstring(mtrVm, value);
        lua_setglobal(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

void MTR_ScriptsDoFile(const char * filename)
{
    bool error;

    if (filename == NULL) {
        MTR_Notify("Unable to run script. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return;
    }

    error = luaL_dofile(mtrVm, filename);
    if (error)
    {
        MTR_Notify("Error in the script or script file not found.", 0,
         MTR_DMT_ERROR);
        MTR_LogWrite(lua_tostring(mtrVm, -1), 0, MTR_LMT_ERROR);
    }
}

void MTR_ScriptsQuit(void)
{
    lua_close(mtrVm);
    MTR_LogWrite("Lua VM closed", 0, MTR_LMT_INFO);
}

MTR_DCLSPC void MTR_CALL MTR_ScriptsAutorun(char * filename)
{
    if (filename == NULL) {
        MTR_Notify("Unable to autorun script. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return;
    }

    MTR_ScriptsInit();
    mtrAutorun = filename;
    MTR_ScriptsDoFile(filename);
}
