#include "script.h"

#include "marathoner/plugin_common.c"
#include "../common.c"

MTR_EXPORT mtrReport* MTR_CALL mtrCreateReport(void)
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

void mtrScriptsInit(void)
{
    uint8_t i;
    uint8_t j;

    mtrLogWrite("Initializing script subsystem", 0, MTR_LMT_INFO);

    mtrLogWrite_s("Reporting Squirrel compile-time version:", 1, MTR_LMT_INFO,
     SQUIRREL_VERSION);
    mtrLogWrite_i("Reporting Squirrel linked version:", 1, MTR_LMT_INFO,
     sq_getversion());

    mtrVm = sq_open(1024);
    sqstd_register_iolib(mtrVm);
    mtrLogWrite("Squirrel VM created", 1, MTR_LMT_INFO);
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
            if (strcmp(mtrPluginData[i].report->prereqs[j], "Script_Squirrel") == 0)
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

MTR_EXPORT HSQUIRRELVM MTR_CALL mtrScriptsGetVm(void)
{
    return mtrVm;
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterFunction(SQFUNCTION func,
 const char * funcname)
{
    sq_pushroottable(mtrVm);
    sq_pushstring(mtrVm, funcname, -1);
    sq_newclosure(mtrVm, func, 0); //create a new function
    sq_newslot(mtrVm, -3, SQFalse);
    sq_pop(mtrVm, 1); //pops the root table
    mtrLogWrite_s("Script function added:", 3, MTR_LMT_INFO, funcname);
    return;
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterStringVariable(const char *name,
 const char *value)
{
    sq_pushconsttable(mtrVm);
    sq_pushstring(mtrVm, name, -1);
    sq_pushstring(mtrVm, value, -1);
    sq_rawset(mtrVm, -3);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
}

MTR_EXPORT void MTR_CALL mtrScriptsRegisterNumericVariable(const char *name,
 double value)
{
    sq_pushconsttable(mtrVm);
    sq_pushstring(mtrVm, name, -1);
    sq_pushfloat(mtrVm, value);
    sq_rawset(mtrVm, -3);
    mtrLogWrite_s("Script const added:", 3, MTR_LMT_INFO, name);
}

void mtrScriptPrintFunc(HSQUIRRELVM v,const SQChar *s,...)
{
    char buf[80];
    va_list vl;
    va_start(vl, s);

    vsnprintf(buf, 80, s, vl);
    mtrLogWrite_s("Squirrel:", 0, MTR_LMT_INFO, buf);

    va_end(vl);
}

void mtrScriptErrorFunc(HSQUIRRELVM v,const SQChar *s,...)
{
    char buf[80];
    va_list vl;
    va_start(vl, s);

    vsnprintf(buf, 80, s, vl);
    mtrLogWrite_s("Squirrel:", 0, MTR_LMT_ERROR, buf);

    va_end(vl);
}

void mtrScriptsDoFile(const char * filename)
{
    SQRESULT error;
    sqstd_seterrorhandlers(mtrVm); //registers the default error handlers
    sq_setprintfunc(mtrVm, mtrScriptPrintFunc, mtrScriptErrorFunc); //sets the print function
    sq_pushroottable(mtrVm);
    error = sqstd_dofile(mtrVm, filename, 0, 1);
    if (SQ_FAILED(error))
    {
        mtrNotify("Error in the script or script file not found.", 0,
         MTR_DMT_ERROR);
    }
}

void mtrScriptsQuit(void)
{
    sq_pop(mtrVm, 1); //pops the root table
    sq_close(mtrVm);
    mtrLogWrite("Squirrel VM closed", 0, MTR_LMT_INFO);
}

MTR_EXPORT void MTR_CALL mtrScriptsAutorun(char * filename)
{
    mtrScriptsInit();
    mtrScriptsDoFile(filename);
}
