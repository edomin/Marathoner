#include "so.h"
#include "log.h"
#include "messagebox.h"
#include "notification.h"
#include "configfile.h"
#include "indexkeeper.h"
#include "file.h"
#include "directory.h"
#include "encoding.h"
#include "clipboard.h"
#include "string_buffer.h"
#include "plugin_loader.h"
#include "options.h"
#include "version.h"
#include "console.h"
#include "fa.h"
#include "module.h"

#include "marathoner/engine.h"

void RequireEngineFuncs(uint8_t plugin)
{
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireMarathonerFunctionSupported,
     MTR_MarathonerFunctionSupported);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireMarathonerGetVersion,
     MTR_MarathonerGetVersion);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireMarathonerGetModuleVersion,
     MTR_MarathonerGetModuleVersion);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireMarathonerGetSubsystemModuleId,
     MTR_MarathonerGetSubsystemModuleId);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileGetKeyName,
     MTR_ConfigfileGetKeyName);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileGetSectionName,
     MTR_ConfigfileGetSectionName);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileKeyExists,
     MTR_ConfigfileKeyExists);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileSectionExists,
     MTR_ConfigfileSectionExists);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileDeleteKey,
     MTR_ConfigfileDeleteKey);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileDeleteSection,
     MTR_ConfigfileDeleteSection);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileReadBool,
     MTR_ConfigfileReadBool);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileReadInt,
     MTR_ConfigfileReadInt);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileReadSingle,
     MTR_ConfigfileReadSingle);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileReadString,
     MTR_ConfigfileReadString);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileWriteBool,
     MTR_ConfigfileWriteBool);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileWriteInt,
     MTR_ConfigfileWriteInt);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileWriteSingle,
     MTR_ConfigfileWriteSingle);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileWriteString,
     MTR_ConfigfileWriteString);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConfigfileCreateSection,
     MTR_ConfigfileCreateSection);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireLogWrite, MTR_LogWrite);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireLogWrite_s, MTR_LogWrite_s);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireLogWrite_i, MTR_LogWrite_i);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireLogWrite_d, MTR_LogWrite_d);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireShowSimpleMessageBox,
     MTR_ShowSimpleMessageBox);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireShowYesNoMessageBox,
     MTR_ShowYesNoMessageBox);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireShowOkCancelMessageBox,
     MTR_ShowOkCancelMessageBox);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireShowInputDialog, MTR_ShowInputDialog);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireShowPasswordDialog,
     MTR_ShowPasswordDialog);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireAddFileFilter,
     MTR_AddFileFilter);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireClearFileFilters,
     MTR_ClearFileFilters);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireShowSaveFileDialog,
     MTR_ShowSaveFileDialog);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireShowOpenFileDialog,
     MTR_ShowOpenFileDialog);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireShowSelectFolderDialog,
     MTR_ShowSelectFolderDialog);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireNotify, MTR_Notify);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireIndexkeeperCreate, MTR_IndexkeeperCreate);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireIndexkeeperGetFreeIndex,
     MTR_IndexkeeperGetFreeIndex);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireIndexkeeperFreeIndex,
     MTR_IndexkeeperFreeIndex);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireIndexkeeperIndexIsEmpty,
     MTR_IndexkeeperIndexIsEmpty);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireIndexkeeperGetReservedDataCount,
     MTR_IndexkeeperGetReservedDataCount);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireIndexkeeperDestroy,
     MTR_IndexkeeperDestroy);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireEncodingUtf8ToUcs4,
     MTR_EncodingUtf8ToUcs4);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireEncodingUtf8Codepoints,
     MTR_EncodingUtf8Codepoints);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireFileOpen, MTR_FileOpen);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireFileClose, MTR_FileClose);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireFileRead, MTR_FileRead);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireFileWrite, MTR_FileWrite);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireFileWriteLine, MTR_FileWriteLine);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireFileWriteFast, MTR_FileWriteFast);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireFileWriteLineFast, MTR_FileWriteLineFast);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireClipboardPutText, MTR_ClipboardPutText);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireClipboardGetText, MTR_ClipboardGetText);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireStringBufferAdd, MTR_StringBufferAdd);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireStringBufferDelete,
     MTR_StringBufferDelete);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireStringBufferSetString,
     MTR_StringBufferSetString);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireStringBufferGetString,
     MTR_StringBufferGetString);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireStringBufferGetMaxLen,
     MTR_StringBufferGetMaxLen);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireOptionsAlias, MTR_OptionsAlias);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireOptionsGet, MTR_OptionsGet);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireOptionsGet_b, MTR_OptionsGet_b);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireOptionsGet_i, MTR_OptionsGet_i);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireOptionsGet_l, MTR_OptionsGet_l);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireOptionsGet_f, MTR_OptionsGet_f);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireOptionsGet_d, MTR_OptionsGet_d);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConsoleShow, MTR_ConsoleShow);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireConsoleHide, MTR_ConsoleHide);
    MTR_REQUIRE_ENGINE_FUNC(MTR_RequireSoLoadSymbol, MTR_SoLoadSymbol);
}

/* Check if module disabled and process it */
bool MTR_ProcessModuleDisabled(int moduleNum)
{
    int i;

    if (!MTR_ConfigfileReadBool(CONFIGFILE_PATH, "Module",
     mtrPluginData[moduleNum].report->moduleID, true))
    {
        MTR_LogWrite_s("Module are disabled by configfile:", 1,
         MTR_LMT_NOTE, mtrPluginData[moduleNum].report->moduleID);
        free(mtrPluginData[moduleNum].filename);
        for (i = moduleNum; i < mtrPluginsFound - 1; i++)
            mtrPluginData[i] = mtrPluginData[i + 1];
        mtrPluginsFound--;
        return true;
    }
    return false;
}

bool MTR_IsSubsystem(int moduleNum)
{
    if ((strcmp(mtrPluginData[moduleNum].report->subsystem, "binding") != 0) &&
     (strcmp(mtrPluginData[moduleNum].report->subsystem, "utils") != 0) &&
     (strcmp(mtrPluginData[moduleNum].report->subsystem, "abstraction") != 0))
        return true;
    else
        return false;
}

int main(int argc, char** argv)
{
    uint8_t i;
    uint8_t j;
    uint8_t k;
    char   *temp; /* Read config result */
    bool    ok;
    int     error;
    char   *autorunAction = NULL;
    char   *autorunPlugin = NULL;
    char   *autorunScript = NULL;
    char   *currentArgument = NULL;
    bool    showConsole;

    chdir("..");

    MTR_OptionsProcess(argc, argv);
    MTR_OptionsAlias("help", "h");
    if (strcmp(MTR_OptionsGet("help"), "") == 0)
    {
        /* Print help to log */
    }

    showConsole = MTR_OptionsGet_b("show-console");
    if (!showConsole)
        showConsole = MTR_ConfigfileReadBool(CONFIGFILE_PATH, "Engine",
         "show_console", false);

    if (showConsole)
        MTR_ConsoleShow();

    autorunAction = MTR_OptionsGet("autorun-action");
    autorunPlugin = MTR_OptionsGet("autorun-plugin");
    autorunScript = MTR_OptionsGet("autorun-script");

    if (autorunAction == NULL)
        autorunAction = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun",
         "action", "none");
    if (autorunPlugin == NULL)
        autorunPlugin = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun",
         "plugin", "none");
    if (autorunScript == NULL)
        autorunScript = MTR_ConfigfileReadString(CONFIGFILE_PATH, "Autorun",
         "script", "none");

    MTR_LogInit("Marathoner.log");

    MTR_LogWrite("Reporting Marathoner version:", 0, MTR_LMT_INFO);
    MTR_LogWrite_i("Majon:", 1, MTR_LMT_INFO,
     (MTR_VERSION_MARATHONER & 0xFF0000) >> 16);
    MTR_LogWrite_i("Minor:", 1, MTR_LMT_INFO,
     (MTR_VERSION_MARATHONER & 0x00FF00) >> 8);
    MTR_LogWrite_i("Patch:", 1, MTR_LMT_INFO,
     MTR_VERSION_MARATHONER & 0x0000FF);
    MTR_LogWrite("Searching available plugins", 0, MTR_LMT_INFO);

    MTR_SoInit(MTR_IKDM_SMALL, 256);

    error = MTR_LoadAllPlugins(RequireEngineFuncs);
    if (error != 0)
        return error;

    MTR_LogWrite("Processing modules' reports", 0, MTR_LMT_INFO);
    ok = false;
    i = 0;
    while (i < mtrPluginsFound)
    {
        if (MTR_ProcessModuleDisabled(i))
        {
            i = 0;
            continue;
        }
        ok = true;
        /* searching conflicting subsystems */
        if (MTR_IsSubsystem(i))
        {
            for (j = 0; j < mtrPluginsFound; j++)
            {
                currentArgument = MTR_OptionsGet(
                 mtrPluginData[i].report->subsystem);
                if (currentArgument == NULL)
                    temp = MTR_ConfigfileReadString(CONFIGFILE_PATH,
                     "Subsystem", mtrPluginData[i].report->subsystem, "none");
                else
                    temp = currentArgument;
                if (strcmp(temp, "none") == 0)
                {
                    MTR_LogWrite_s("Subsystem of module are disabled by "
                     "configfile:", 1, MTR_LMT_NOTE,
                     mtrPluginData[i].report->moduleID);
                    MTR_SoClose(mtrPluginData[i].so);
                    free(mtrPluginData[i].filename);
                    if (temp != currentArgument)
                        free(temp);
                    currentArgument = NULL;
                    ok = false;
                    break;
                }

                if (
                    (strcmp(mtrPluginData[i].report->subsystem,
                     mtrPluginData[j].report->subsystem) == 0) &&
                    (i != j)
                   )
                {
                    ok = false;

                    currentArgument = MTR_OptionsGet(
                     mtrPluginData[i].report->subsystem);
                    if (currentArgument == NULL)
                        temp = MTR_ConfigfileReadString(CONFIGFILE_PATH,
                         "Subsystem", mtrPluginData[i].report->subsystem,
                         "none");
                    else
                        temp = currentArgument;

                    if (strcmp(temp, mtrPluginData[i].report->moduleID) == 0)
                    {
                        MTR_LogWrite_s("Module will not loaded:", 1,
                         MTR_LMT_NOTE, mtrPluginData[j].report->moduleID);
                        MTR_SoClose(mtrPluginData[j].so);
                        free(mtrPluginData[j].filename);
                        i = j;
                        if (temp != currentArgument)
                            free(temp);
                        currentArgument = NULL;
                        break;
                    }
                    if (strcmp(temp, mtrPluginData[j].report->moduleID) == 0)
                    {
                        MTR_LogWrite_s("Module will not loaded:", 1,
                         MTR_LMT_NOTE, mtrPluginData[i].report->moduleID);
                        MTR_SoClose(mtrPluginData[i].so);
                        free(mtrPluginData[i].filename);
                        if (temp != currentArgument)
                            free(temp);
                        currentArgument = NULL;
                        break;
                    }

                    MTR_LogWrite_s("Conflicting modules of subsystem:", 1,
                     MTR_LMT_ERROR, mtrPluginData[i].report->subsystem);
                    MTR_LogWrite_s("First module:", 2, MTR_LMT_INFO,
                     mtrPluginData[i].report->moduleID);
                    MTR_LogWrite_s("Second module:", 2, MTR_LMT_INFO,
                     mtrPluginData[j].report->moduleID);
                    MTR_LogWrite_s("Module will not loaded:", 1,
                     MTR_LMT_WARNING, mtrPluginData[i].report->moduleID);
                    MTR_SoClose(mtrPluginData[i].so);
                    free(mtrPluginData[i].filename);

                    if (temp != currentArgument)
                        free(temp);
                    currentArgument = NULL;
                    break;
                }
            }
            if (!ok)
            {

                for (j = i; j < mtrPluginsFound - 1; j++)
                    mtrPluginData[j] = mtrPluginData[j + 1];
                mtrPluginsFound--;
                i = 0;
                continue;
            }
        }
        /* searching existing of prerequied subsystems */
        if (mtrPluginData[i].report->prereqSubsystemsCount > 0)
        {
            for (j = 0; j < mtrPluginData[i].report->prereqSubsystemsCount; j++)
            {
                ok = false;
                for (k = 0; k < mtrPluginsFound; k++)
                {
                    if (strcmp(mtrPluginData[i].report->prereqSubsystems[j],
                     mtrPluginData[k].report->subsystem) == 0)
                    {
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    MTR_LogWrite_s("Missing Prerequired subsystem module:", 1,
                     MTR_LMT_ERROR,
                     mtrPluginData[i].report->prereqSubsystems[j]);
                    MTR_LogWrite_s("Module will not loaded:", 1,
                     MTR_LMT_WARNING, mtrPluginData[i].report->moduleID);
                    MTR_SoClose(mtrPluginData[i].so);
                    free(mtrPluginData[i].filename);
                    for (j = i; j < mtrPluginsFound - 1; j++)
                        mtrPluginData[j] = mtrPluginData[j + 1];
                    mtrPluginsFound--;
                    i = 0;
                    continue;
                }
            }
        }
        /* checking existing of prerequisites */
        if (mtrPluginData[i].report->prereqsCount > 0)
        {
            for (j = 0; j < mtrPluginData[i].report->prereqsCount; j++)
            {
                ok = false;
                for (k = 0; k < mtrPluginsFound; k++)
                {
                    if (strcmp(mtrPluginData[i].report->prereqs[j],
                     mtrPluginData[k].report->moduleID) == 0)
                    {
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    MTR_LogWrite_s("Missing Prerequisite module:", 1,
                     MTR_LMT_ERROR, mtrPluginData[i].report->prereqs[j]);
                    MTR_LogWrite_s("Module will not loaded:", 1,
                     MTR_LMT_WARNING, mtrPluginData[i].report->moduleID);
                    MTR_SoClose(mtrPluginData[i].so);
                    free(mtrPluginData[i].filename);
                    for (j = i; j < mtrPluginsFound - 1; j++)
                        mtrPluginData[j] = mtrPluginData[j + 1];
                    mtrPluginsFound--;
                    i = 0;
                    continue;
                }
            }
        }
        i++;
    }

    /* Plugins updating information about every other plugin */
    for (i = 0; i < mtrPluginsFound; i++)
    {
        MTR_RequirePluginData = (MTR_RequirePluginDataFunc)MTR_SoLoadSymbol(
         mtrPluginData[i].so, "MTR_RequirePluginData");
        if (MTR_RequirePluginData == NULL)
        {
            MTR_LogWrite(
             "Module are not contain function MTR_RequirePluginData", 1,
             MTR_LMT_ERROR);
            MTR_LogWrite_s("Module will not loaded:", 1,
             MTR_LMT_WARNING, mtrPluginData[i].report->moduleID);
            MTR_SoClose(mtrPluginData[i].so);
            free(mtrPluginData[i].filename);
            for (j = i; j < mtrPluginsFound - 1; j++)
                mtrPluginData[j] = mtrPluginData[j + 1];
            mtrPluginsFound--;
            i = 0;
            continue;
        }
        MTR_RequirePluginData(mtrPluginData, mtrPluginsFound);
    }

    MTR_LogWrite("Modules' reports processed", 0, MTR_LMT_INFO);

    if (!MTR_FileInit(MTR_IKDM_SMALL, 32))
        return 4;

    if (!MTR_StringBufferInit(MTR_IKDM_MEDIUM, 32))
        return 5;

    MTR_LogWrite("Reading 'Marathoner.cfg' for autorun options", 0,
     MTR_LMT_INFO);
    ok = false;
    if (strcmp(autorunAction, "runScript") == 0)
    {
        for (i = 0; i < mtrPluginsFound; i++)
        {
            if (strcmp(mtrPluginData[i].report->moduleID, autorunPlugin) == 0)
            {
                ok = true;
                currentPlugin = i;
                break;
            }
        }
        if (ok)
        {
            if (strcmp(autorunScript, "none") != 0)
            {
                MTR_ScriptsAutorun = (MTR_ScriptsAutorunFunc)MTR_SoLoadSymbol(
                 mtrPluginData[currentPlugin].so, "MTR_ScriptsAutorun");
                if (MTR_ScriptsAutorun == NULL)
                    MTR_Notify("Unable to load autorun plugin function", 1,
                     MTR_LMT_ERROR);
                else
                {
                    MTR_LogWrite_s("Running autorun function with file:", 0,
                     MTR_LMT_INFO, autorunScript);
                    MTR_ScriptsAutorun(autorunScript);
//                    MTR_ScriptsAutorun(strcat("../", autorunScript));
                }
            }
            else
            {
                MTR_Notify("Unable to read autorun script filename", 1,
                 MTR_LMT_ERROR);
            }
        }
        else
        {
            MTR_Notify("Ivalid autorun plugin", 1, MTR_LMT_ERROR);
        }
    }
    else
    {
        MTR_Notify("Invalid autorun action command", 1, MTR_LMT_ERROR);
    }

    MTR_LogWrite("Quiting Engine", 0, MTR_LMT_INFO);
    /* Freing allocated structures and unloading libraries */
    for (i = 0; i < mtrPluginsFound; i++)
    {
        MTR_LogWrite_s("Unloading plugin", 0, MTR_LMT_INFO,
         mtrPluginData[i].report->moduleID);
        MTR_SoClose(mtrPluginData[i].so);
    }
    free(mtrPluginData);

    MTR_LogWrite("Engine stopped", 0, MTR_LMT_INFO);

    return 0;
}
