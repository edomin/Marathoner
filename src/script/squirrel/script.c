#include "script.h"

#include "marathoner/plugin_common.c"
#include "../common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Scripts, FA_FUNCTIONS_COUNT)

MTR_DCLSPC mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Script_Squirrel";
    report->version = MTR_VERSION_SCRIPT_SQUIRREL;
    report->subsystem = "script";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

void MTR_ScriptPrintFunc(HSQUIRRELVM v,const SQChar *s,...)
{
    char buf[80];
    va_list vl;
    va_start(vl, s);

    vsnprintf(buf, 80, s, vl);
    MTR_LogWrite_s("Squirrel:", 0, MTR_LMT_INFO, buf);

    va_end(vl);
}

void MTR_ScriptErrorFunc(HSQUIRRELVM v, const SQChar *s,...)
{
    char buf[80];
    va_list vl;
    va_start(vl, s);

    vsnprintf(buf, 80, s, vl);
    MTR_LogWrite_s("Squirrel:", 0, MTR_LMT_ERROR, buf);

    va_end(vl);
}

void MTR_ScriptsInit(void)
{
    uint8_t i;
    uint8_t j;

    MTR_LogWrite("Initializing script subsystem", 0, MTR_LMT_INFO);

    MTR_LogWrite_s("Reporting Squirrel compile-time version:", 1, MTR_LMT_INFO,
     SQUIRREL_VERSION);
    MTR_LogWrite_i("Reporting Squirrel linked version:", 1, MTR_LMT_INFO,
     sq_getversion());

    mtrVm = sq_open(1024);
    sq_setprintfunc(mtrVm, MTR_ScriptPrintFunc, MTR_ScriptErrorFunc); //sets the print function
    sq_pushroottable(mtrVm);
    sqstd_register_bloblib(mtrVm);
    sqstd_register_iolib(mtrVm);
    sqstd_register_systemlib(mtrVm);
    sqstd_register_mathlib(mtrVm);
    sqstd_register_stringlib(mtrVm);
    sqstd_seterrorhandlers(mtrVm); //registers the default error handlers
    MTR_LogWrite("Squirrel VM created", 1, MTR_LMT_INFO);
    /* Registering functions and constants from all binding plugins */
    MTR_LogWrite("Registering functions and constants of engine", 1,
     MTR_LMT_INFO);

    MTR_ScriptsRegisterAll();

    MTR_LogWrite("Script functions and constants of engine registered",
     1, MTR_LMT_INFO);
    /* Registering functions and constants from all binding plugins */
    MTR_LogWrite("Registering functions and constants of bindings", 1,
     MTR_LMT_INFO);
    for (i = 0; i < mtrPluginsCount; i++)
    {
        for (j = 0; j < mtrPluginData[i].report->prereqsCount; j++)
        {
            if (strcmp(mtrPluginData[i].report->prereqs[j], "Script_Squirrel") == 0)
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

    MTR_LogWrite("Script functions and constants of bindings registered",
     1, MTR_LMT_INFO);
    MTR_LogWrite("Script subsystem initialized", 0, MTR_LMT_INFO);
}

MTR_DCLSPC HSQUIRRELVM MTR_CALL MTR_ScriptsGetVm(void)
{
    return mtrVm;
}

/*fa MTR_ScriptsGetAutorunPath yes */
MTR_DCLSPC char * MTR_CALL MTR_ScriptsGetAutorunPath(void)
{
    return mtrAutorun;
}

MTR_DCLSPC void MTR_CALL MTR_ScriptsRegisterFunction(SQFUNCTION func,
 const char * funcname)
{
    sq_pushroottable(mtrVm);
    sq_pushstring(mtrVm, funcname, -1);
    sq_newclosure(mtrVm, func, 0); //create a new function
    sq_newslot(mtrVm, -3, SQFalse);
    sq_pop(mtrVm, 1); //pops the root table
    MTR_LogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
    return;
}

/*fa MTR_ScriptsRegisterVariable_b buggy */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_b(const char *name,
 bool value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        sq_pushconsttable(mtrVm);
        sq_pushstring(mtrVm, name, -1);
        sq_pushbool(mtrVm, value);
        sq_rawset(mtrVm, -3);
        sq_poptop(mtrVm);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_i buggy */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_i(const char *name,
 int value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        sq_pushconsttable(mtrVm);
        sq_pushstring(mtrVm, name, -1);
        sq_pushinteger(mtrVm, value);
        sq_rawset(mtrVm, -3);
        sq_poptop(mtrVm);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_u buggy */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_u(const char *name,
 unsigned int value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        sq_pushconsttable(mtrVm);
        sq_pushstring(mtrVm, name, -1);
        sq_pushfloat(mtrVm, value);
        sq_rawset(mtrVm, -3);
        sq_poptop(mtrVm);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_f buggy */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_f(const char *name,
 float value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        sq_pushconsttable(mtrVm);
        sq_pushstring(mtrVm, name, -1);
        sq_pushfloat(mtrVm, value);
        sq_rawset(mtrVm, -3);
        sq_poptop(mtrVm);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_d buggy */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_d(const char *name,
 double value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        sq_pushconsttable(mtrVm);
        sq_pushstring(mtrVm, name, -1);
        sq_pushfloat(mtrVm, value);
        sq_rawset(mtrVm, -3);
        sq_poptop(mtrVm);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_s buggy */
MTR_DCLSPC bool MTR_CALL MTR_ScriptsRegisterVariable_s(const char *name,
 const char *value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        sq_pushconsttable(mtrVm);
        sq_pushstring(mtrVm, name, -1);
        sq_pushstring(mtrVm, value, -1);
        sq_rawset(mtrVm, -3);
        sq_poptop(mtrVm);
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
    SQRESULT error;

    if (filename == NULL) {
        MTR_Notify("Unable to run script. Filename is is not valid", 0,
         MTR_LMT_ERROR);
        return;
    }

    error = sqstd_dofile(mtrVm, filename, 0, 1);
    if (SQ_FAILED(error))
    {
        MTR_Notify("Error in the script or script file not found.", 0,
         MTR_DMT_ERROR);
    }
}

void MTR_ScriptsQuit(void)
{
    sq_pop(mtrVm, 1); //pops the root table
    sq_close(mtrVm);
    MTR_LogWrite("Squirrel VM closed", 0, MTR_LMT_INFO);
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
