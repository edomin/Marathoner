#include "script.h"

#include "marathoner/plugin_common.c"
#include "../common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
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

void mtrScriptsInit(void)
{
    uint8_t i;
    uint8_t j;
    long int verMajor;
    long int verMinor;
    long int verPatch;

    mtrLogWrite("Initializing script subsystem", 0, MTR_LMT_INFO);

    verMajor = DUK_VERSION / 10000;
    verMinor = (DUK_VERSION - verMajor * 10000) / 100;
    verPatch = DUK_VERSION - verMajor * 10000 - verMinor * 100;
    mtrLogWrite("Reporting Duktape compile-time version:", 1, MTR_LMT_INFO);
    mtrLogWrite_i("Major:", 2, MTR_LMT_INFO, verMajor);
    mtrLogWrite_i("Minor:", 2, MTR_LMT_INFO, verMinor);
    mtrLogWrite_i("Patch:", 2, MTR_LMT_INFO, verPatch);

    mtrVm = duk_create_heap_default();
    if (mtrVm != NULL)
        mtrLogWrite("Duktape context created", 1, MTR_LMT_INFO);
    else
        mtrNotify("Unable to create Duktape context", 1, MTR_DMT_FATAL);

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

    mtrLogWrite("Script functions and constants of engine registered",
     1, MTR_LMT_INFO);
    /* Registering functions and constants from all binding plugins */
    mtrLogWrite("Registering functions and constants of bindings", 1,
     MTR_LMT_INFO);
    for (i = 0; i < mtrPluginsCount; i++)
    {
        for (j = 0; j < mtrPluginData[i].report->prereqsCount; j++)
        {
            if (strcmp(mtrPluginData[i].report->prereqs[j], "Script_Duktape") == 0)
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

MTR_EXPORT duk_context *MTR_CALL mtrScriptsGetVm(void)
{
    return mtrVm;
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(duk_c_function func,
 const char *funcname)
{
    duk_push_c_function(mtrVm, func, DUK_VARARGS);
    duk_put_global_string(mtrVm, funcname);

    mtrLogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value)
{
    duk_push_string(mtrVm, value);
    duk_put_global_string(mtrVm, name);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value)
{
    duk_push_number(mtrVm, value);
    duk_put_global_string(mtrVm, name);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
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

void mtrScriptsDoFile(const char * filename)
{
    push_file_as_string(filename);
    if (duk_peval(mtrVm) != 0)
    {
        mtrNotify("Error in the script or script file not found.", 0,
         MTR_DMT_ERROR);
        mtrNotify(duk_safe_to_string(mtrVm, -1), 0, MTR_DMT_ERROR);
    }
    duk_pop(mtrVm);  /* ignore result */
}

void mtrScriptsQuit(void)
{
    duk_destroy_heap(mtrVm);
    mtrLogWrite("Duktape heap destroyed", 0, MTR_LMT_INFO);
}

MTR_EXPORT void MTR_CALL mtrScriptsAutorun(char * filename)
{
    mtrScriptsInit();
    mtrScriptsDoFile(filename);
}
