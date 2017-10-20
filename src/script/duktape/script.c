#include "script.h"

#include "marathoner/plugin_common.c"
#include "../common.c"

MTR_SUBSYSTEM_FUNCTION_SUPPORTED_FUNC(Scripts, FA_FUNCTIONS_COUNT)

MTR_EXPORT mtrReport* MTR_CALL MTR_CreateReport(void)
{
    mtrReport *report;
    report = malloc(sizeof(mtrReport));
    if (report == NULL)
        return NULL;
    report->moduleID = "Script_Duktape";
    report->version = MTR_VERSION_SCRIPT_DUKTAPE;
    report->subsystem = "script";
    report->prereqsCount = 0;
    report->prereqs = NULL;
    report->prereqSubsystemsCount = 0;
    report->prereqSubsystems = NULL;
    return report;
}

static void push_file_as_string(const char *filename)
{
    FILE *f;
    size_t len;
    char buf[1048576]; /* 1MB filezise limit */

    f = fopen(filename, "rb");
    if (f)
    {
        len = fread((void *) buf, 1, sizeof(buf), f);
        fclose(f);
        duk_push_lstring(mtrVm, (const char *) buf, (duk_size_t) len);
    }
    else
        duk_push_undefined(mtrVm);
}

static duk_ret_t cb_resolve_module(duk_context *ctx) {
	const char *module_id;
//	const char *parent_id;

	module_id = duk_require_string(ctx, 0);
//	parent_id = duk_require_string(ctx, 1);

	duk_push_sprintf(ctx, "%s.js", module_id);
//	printf("resolve_cb: id:'%s', parent-id:'%s', resolve-to:'%s'\n",
//		module_id, parent_id, duk_get_string(ctx, -1));

	return 1;
}

static duk_ret_t cb_load_module(duk_context *ctx) {
	const char *filename;
//	const char *module_id;

//	module_id = duk_require_string(ctx, 0);
	duk_get_prop_string(ctx, 2, "filename");
	filename = duk_require_string(ctx, -1);

//	printf("load_cb: id:'%s', filename:'%s'\n", module_id, filename);

	push_file_as_string(filename);

	return 1;
}

void MTR_ScriptsInit(void)
{
    uint8_t i;
    uint8_t j;
    long int verMajor;
    long int verMinor;
    long int verPatch;

    MTR_LogWrite("Initializing script subsystem", 0, MTR_LMT_INFO);

    verMajor = DUK_VERSION / 10000;
    verMinor = (DUK_VERSION - verMajor * 10000) / 100;
    verPatch = DUK_VERSION - verMajor * 10000 - verMinor * 100;
    MTR_LogWrite("Reporting Duktape compile-time version:", 1, MTR_LMT_INFO);
    MTR_LogWrite_i("Major:", 2, MTR_LMT_INFO, verMajor);
    MTR_LogWrite_i("Minor:", 2, MTR_LMT_INFO, verMinor);
    MTR_LogWrite_i("Patch:", 2, MTR_LMT_INFO, verPatch);

    mtrVm = duk_create_heap_default();
    if (mtrVm != NULL)
        MTR_LogWrite("Duktape context created", 1, MTR_LMT_INFO);
    else
        MTR_Notify("Unable to create Duktape context", 1, MTR_DMT_FATAL);

    duk_push_object(mtrVm);
    duk_push_c_function(mtrVm, cb_resolve_module, DUK_VARARGS);
    duk_put_prop_string(mtrVm, -2, "resolve");
    duk_push_c_function(mtrVm, cb_load_module, DUK_VARARGS);
    duk_put_prop_string(mtrVm, -2, "load");
    duk_module_node_init(mtrVm);

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
            if (
             strcmp(mtrPluginData[i].report->prereqs[j], "Script_Duktape") == 0)
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

MTR_EXPORT duk_context *MTR_CALL MTR_ScriptsGetVm(void)
{
    return mtrVm;
}

MTR_EXPORT char * MTR_CALL MTR_ScriptsGetAutorunPath(void)
{
    return mtrAutorun;
}

MTR_EXPORT void MTR_CALL MTR_ScriptsRegisterFunction(duk_c_function func,
 const char *funcname)
{
    duk_push_c_function(mtrVm, func, DUK_VARARGS);
    duk_put_global_string(mtrVm, funcname);

    MTR_LogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
}

/*fa MTR_ScriptsRegisterVariable_b yes */
MTR_EXPORT bool MTR_CALL MTR_ScriptsRegisterVariable_b(const char *name,
 bool value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        duk_push_boolean(mtrVm, value);
        duk_put_global_string(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_i yes */
MTR_EXPORT bool MTR_CALL MTR_ScriptsRegisterVariable_i(const char *name,
 int value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        duk_push_int(mtrVm, value);
        duk_put_global_string(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_u yes */
MTR_EXPORT bool MTR_CALL MTR_ScriptsRegisterVariable_u(const char *name,
 unsigned int value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        duk_push_uint(mtrVm, value);
        duk_put_global_string(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_f yes */
MTR_EXPORT bool MTR_CALL MTR_ScriptsRegisterVariable_f(const char *name,
 float value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        duk_push_number(mtrVm, value);
        duk_put_global_string(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_d yes */
MTR_EXPORT bool MTR_CALL MTR_ScriptsRegisterVariable_d(const char *name,
 double value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        duk_push_number(mtrVm, value);
        duk_put_global_string(mtrVm, name);
        MTR_LogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
        return true;
    } else {
        MTR_LogWrite("Script const not added. Incorrect const name:", 3,
         MTR_LMT_ERROR);
    }
    return false;
}

/*fa MTR_ScriptsRegisterVariable_s yes */
MTR_EXPORT bool MTR_CALL MTR_ScriptsRegisterVariable_s(const char *name,
 const char *value)
{
    if ((name != NULL) && (strcmp(name, "") != 0))
    {
        duk_push_string(mtrVm, value);
        duk_put_global_string(mtrVm, name);
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
    push_file_as_string(filename);
    if (duk_module_node_peval_main(mtrVm, filename) == DUK_EXEC_ERROR)
    {
        MTR_Notify("Error in the script or script file not found.", 0,
         MTR_DMT_ERROR);
        MTR_Notify(duk_safe_to_string(mtrVm, -1), 0, MTR_DMT_ERROR);
    }
    duk_pop(mtrVm);  /* ignore result */
}

void MTR_ScriptsQuit(void)
{
    duk_destroy_heap(mtrVm);
    MTR_LogWrite("Duktape heap destroyed", 0, MTR_LMT_INFO);
}

MTR_EXPORT void MTR_CALL MTR_ScriptsAutorun(char * filename)
{
    MTR_ScriptsInit();
    mtrAutorun = filename;
    MTR_ScriptsDoFile(filename);
}
